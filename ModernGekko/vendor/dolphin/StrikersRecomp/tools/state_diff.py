#!/usr/bin/env python3
"""Diff two raw guest-MEM1 dumps and map divergent regions to decomp symbols.

This is the analysis half of the deterministic save-state differential harness
(see GXRuntime savestate.h + StrikersRecomp main.c --snapshot/--restore/--dump-mem).
Given two MEM1 dumps -- e.g. the recomp's state vs Dolphin's at the same frame, or
the recomp before vs after a fix -- it finds the byte ranges that differ, coalesces
them into runs, and labels each run with the nearest preceding symbol from the
decomp symbol map. The output tells you WHICH game variables/objects diverge, so a
memory diff localizes a bug to a subsystem instead of a raw offset.

Usage:
    state_diff.py A.bin B.bin [--base 0x80000000] [--gap N] [--symbols PATH]
                  [--top N] [--json] [--ignore-zero]

Exit code 0 = identical, 1 = differences found, 2 = error.
"""
import argparse
import bisect
import json
import sys
from pathlib import Path

DEFAULT_SYMBOLS = (
    Path(__file__).resolve().parent.parent.parent
    / "smstrikers-decomp/config/G4QE01/symbols.txt"
)


def load_symbols(path: Path):
    """Parse `name = .section:0xADDR; // ...` lines into sorted (addr, name)."""
    syms = []
    if not path.is_file():
        return syms
    import re

    pat = re.compile(r"^([A-Za-z0-9_<>,$:* ]+?)\s*=\s*\.\w+:0x([0-9A-Fa-f]+)")
    for line in path.read_text(errors="ignore").splitlines():
        m = pat.match(line)
        if m:
            syms.append((int(m.group(2), 16), m.group(1).strip()))
    syms.sort()
    return syms


def nearest_symbol(syms, addrs, addr):
    """Nearest preceding symbol and its offset for a guest address."""
    if not syms:
        return None, 0
    i = bisect.bisect_right(addrs, addr) - 1
    if i < 0:
        return None, 0
    return syms[i][1], addr - syms[i][0]


def find_runs(a: bytes, b: bytes, gap: int, ignore_zero: bool):
    """Coalesce differing bytes into runs, merging runs separated by < gap bytes."""
    n = min(len(a), len(b))
    runs = []
    start = None
    last_diff = None
    for i in range(n):
        differ = a[i] != b[i]
        if differ and ignore_zero and a[i] == 0 and b[i] == 0:
            differ = False
        if differ:
            if start is None:
                start = i
            elif last_diff is not None and i - last_diff > gap:
                runs.append((start, last_diff + 1))
                start = i
            last_diff = i
    if start is not None:
        runs.append((start, last_diff + 1))
    return runs


def is_uninitialized(chunk: bytes) -> bool:
    """A run that is mostly the allocator fill byte 0xCD is 'not written yet',
    not a real divergence -- drop it to cut cross-run heap noise."""
    if not chunk:
        return False
    cd = chunk.count(0xCD)
    zero = chunk.count(0x00)
    return (cd + zero) >= int(0.85 * len(chunk))


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("a")
    ap.add_argument("b")
    ap.add_argument("--base", default="0x80000000")
    ap.add_argument("--gap", type=int, default=64,
                    help="merge diff runs separated by fewer than N equal bytes")
    ap.add_argument("--symbols", default=str(DEFAULT_SYMBOLS))
    ap.add_argument("--top", type=int, default=40, help="show the N largest runs")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--ignore-zero", action="store_true",
                    help="ignore positions where both are zero (already excluded)")
    ap.add_argument("--ignore-uninit", action="store_true",
                    help="drop runs that are mostly allocator-fill 0xCD/0x00 on "
                         "either side (uninitialized heap, not a real divergence)")
    ap.add_argument("--named-only", action="store_true",
                    help="only show runs within 0x4000 of a named symbol (game "
                         "state), hiding far-offset unlabeled heap regions")
    args = ap.parse_args()

    base = int(args.base, 0)
    a = Path(args.a).read_bytes()
    b = Path(args.b).read_bytes()
    if len(a) != len(b):
        print(f"warning: size mismatch {len(a)} vs {len(b)}; comparing prefix",
              file=sys.stderr)

    syms = load_symbols(Path(args.symbols))
    addrs = [s[0] for s in syms]

    runs = find_runs(a, b, args.gap, args.ignore_zero)
    total_bytes = sum(end - start for start, end in runs)
    # Rank by run size (largest divergences first).
    runs.sort(key=lambda r: r[1] - r[0], reverse=True)

    entries = []
    for start, end in runs:
        if args.ignore_uninit and (
            is_uninitialized(a[start:end]) or is_uninitialized(b[start:end])
        ):
            continue
        addr = base + start
        name, off = nearest_symbol(syms, addrs, addr)
        if args.named_only and (name is None or off > 0x4000):
            continue
        entries.append({
            "addr": f"0x{addr:08X}",
            "size": end - start,
            "symbol": name,
            "sym_offset": off,
            "a": a[start:min(start + 8, end)].hex(),
            "b": b[start:min(start + 8, end)].hex(),
        })

    shown_bytes = sum(e["size"] for e in entries)
    if args.json:
        print(json.dumps({
            "identical": len(runs) == 0,
            "diff_runs": len(runs),
            "diff_bytes": total_bytes,
            "shown_runs": len(entries),
            "shown_bytes": shown_bytes,
            "regions": entries[:args.top],
        }, indent=2))
    else:
        if not runs:
            print("IDENTICAL")
            return 0
        print(f"{len(runs)} divergent run(s), {total_bytes} bytes total; "
              f"{len(entries)} shown after filters ({shown_bytes} bytes). "
              f"Top {min(args.top, len(entries))} by size:")
        print(f"{'ADDR':<12}{'SIZE':>8}  {'A':<18}{'B':<18}SYMBOL")
        for e in entries[:args.top]:
            sym = e["symbol"] or "(no symbol)"
            if e["sym_offset"]:
                sym = f"{sym}+0x{e['sym_offset']:X}"
            print(f"{e['addr']:<12}{e['size']:>8}  {e['a']:<18}{e['b']:<18}{sym}")

    return 0 if not runs else 1


if __name__ == "__main__":
    sys.exit(main())
