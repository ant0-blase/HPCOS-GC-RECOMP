#!/usr/bin/env python3
"""Convert a big-endian PowerPC ELF executable into a GameCube DOL.

Some titles ship a tiny loader as sys/main.dol and keep the actual game in a
separate ELF read from the disc at runtime -- Medal of Honor Frontline's
main.dol is 168 KiB against 2.8 MiB for files/Moh2RelGC.elf. DolRecomp reads
DOL, REL and RPX, so recompiling that game means handing it the ELF's loadable
segments in a container it understands.

The two formats line up closely: a DOL is a table of sections with file
offsets, load addresses and sizes, which is exactly what PT_LOAD segments
carry. Executable segments become DOL text sections, the rest become data
sections, and the largest zero-filesz segment becomes the single BSS entry the
format allows.

Usage: elf2dol.py <input.elf> <output.dol>
"""

import struct
import sys

DOL_MAX_TEXT = 7
DOL_MAX_DATA = 11
DOL_HEADER_SIZE = 0x100
PT_LOAD = 1
PF_X = 1


def read_segments(data):
    if data[:4] != b"\x7fELF":
        raise SystemExit("not an ELF file")
    if data[4] != 1 or data[5] != 2:
        raise SystemExit("expected a 32-bit big-endian ELF")
    machine = struct.unpack_from(">H", data, 18)[0]
    if machine != 20:
        raise SystemExit(f"expected PowerPC (machine 20), got {machine}")

    entry, phoff = struct.unpack_from(">II", data, 24)
    phentsize, phnum = struct.unpack_from(">HH", data, 42)

    loads = []
    for i in range(phnum):
        off = phoff + i * phentsize
        p_type, p_offset, p_vaddr, _, p_filesz, p_memsz, p_flags = struct.unpack_from(
            ">IIIIIII", data, off)
        if p_type == PT_LOAD and p_memsz:
            loads.append({
                "offset": p_offset,
                "vaddr": p_vaddr,
                "filesz": p_filesz,
                "memsz": p_memsz,
                "exec": bool(p_flags & PF_X),
            })
    return entry, loads


def build_dol(data, entry, loads):
    text = [s for s in loads if s["exec"] and s["filesz"]]
    dataseg = [s for s in loads if not s["exec"] and s["filesz"]]
    bss = [s for s in loads if not s["filesz"]]

    if len(text) > DOL_MAX_TEXT:
        raise SystemExit(f"{len(text)} executable segments, DOL allows {DOL_MAX_TEXT}")
    if len(dataseg) > DOL_MAX_DATA:
        raise SystemExit(f"{len(dataseg)} data segments, DOL allows {DOL_MAX_DATA}")

    # DOL sections are 32-byte aligned in the file.
    out = bytearray(DOL_HEADER_SIZE)
    offsets, addrs, sizes = [], [], []
    for seg in text + dataseg:
        while len(out) % 32:
            out.append(0)
        offsets.append(len(out))
        addrs.append(seg["vaddr"])
        sizes.append(seg["filesz"])
        out += data[seg["offset"]:seg["offset"] + seg["filesz"]]

    # A DOL carries one BSS range; keep the largest and report what is dropped,
    # since anything else is zero-filled memory the loader would clear anyway.
    bss_addr = bss_size = 0
    if bss:
        biggest = max(bss, key=lambda s: s["memsz"])
        bss_addr, bss_size = biggest["vaddr"], biggest["memsz"]
        for s in bss:
            if s is not biggest:
                print(f"  note: BSS 0x{s['vaddr']:08X} ({s['memsz']} bytes) not "
                      f"representable in DOL, dropped", file=sys.stderr)

    def put(pos, values, count):
        for i in range(count):
            struct.pack_into(">I", out, pos + i * 4, values[i] if i < len(values) else 0)

    ntext = len(text)
    put(0x00, offsets[:ntext], DOL_MAX_TEXT)
    put(0x1C, offsets[ntext:], DOL_MAX_DATA)
    put(0x48, addrs[:ntext], DOL_MAX_TEXT)
    put(0x64, addrs[ntext:], DOL_MAX_DATA)
    put(0x90, sizes[:ntext], DOL_MAX_TEXT)
    put(0xAC, sizes[ntext:], DOL_MAX_DATA)
    struct.pack_into(">III", out, 0xD8, bss_addr, bss_size, entry)
    return bytes(out), ntext, len(dataseg)


def main():
    if len(sys.argv) != 3:
        print(__doc__, file=sys.stderr)
        return 2
    data = open(sys.argv[1], "rb").read()
    entry, loads = read_segments(data)
    dol, ntext, ndata = build_dol(data, entry, loads)
    open(sys.argv[2], "wb").write(dol)
    print(f"  entry 0x{entry:08X}  {ntext} text + {ndata} data sections  "
          f"{len(dol)} bytes")
    return 0


if __name__ == "__main__":
    sys.exit(main())
