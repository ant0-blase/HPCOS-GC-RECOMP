# StrikersRecomp

A static recompilation of *Super Mario Strikers* (`G4QE01`, NTSC) — the worked
example for [RecompCore](https://github.com/aharonahdoot/RecompCore) and
[GXRuntime](https://github.com/aharonahdoot/GXRuntime).

This repository holds only policy, glue, and tools for G4QE01: symbol maps,
game-specific HLE decisions, MMIO routing, and the scripts that turn your own
copy of the game into runnable native code. **No game data ships here.** The
recompiled C lives in `generated/`, which you produce locally from your own
ISO and which is never committed.

## Setup

The build expects sibling checkouts. From an empty parent directory:

```sh
git clone https://github.com/aharonahdoot/StrikersRecomp.git
cd StrikersRecomp && ./bootstrap.sh
```

`bootstrap.sh` clones [DolRecomp](https://github.com/aharonahdoot/DolRecomp)
(our maintained fork, pending upstream review),
[GXRuntime](https://github.com/aharonahdoot/GXRuntime), and
[RecompCore](https://github.com/aharonahdoot/RecompCore) next to this checkout.

## Generating the recompiled code

You need your own Super Mario Strikers ISO. Then:

```sh
python3 tools/generate.py --iso /path/to/strikers.iso
```

This extracts `main.dol`, runs DolRecomp over it (~665k instructions, zero
unknown opcodes, 163 C chunks), applies `tools/fix_generated.py`, and leaves
the result in `generated/`. `--dol /path/to/main.dol` skips extraction if you
already extracted the DOL (in Dolphin: right-click the game → Properties →
Filesystem).

## Two ways to run it

**1. RecompCore module (recommended).** Builds the generated code into a
native module that RecompCore (a Dolphin fork) loads by disc ID; everything
the module doesn't cover falls back to Dolphin's interpreter.

```sh
tools/package_module.sh        # builds and installs the gG4QE01_recomp module
```

The module is an ordinary shared library (`.dylib`/`.so`/`.dll` depending on
your platform; macOS is what we test on today).

Then run RecompCore with `-C Dolphin.Core.CPUCore=6`. This path has been
verified in lockstep against Dolphin's interpreter: 0 divergences over 37.7
billion dispatches, boot through a full match.

**2. Standalone GXRuntime app.** A self-contained runtime with its own GX
renderer, input, and audio:

```sh
cmake -S . -B build && cmake --build build -j
STRIKERS_ISO=/path/to/strikers.iso ./build/StrikersRecomp
```

## What works

Boot, menus, the intro cutscene, and full matches. Saves persist on a virtual
memory card (`.dolcard`). Under RecompCore, 99.9% of dispatches run native.

Known gaps: player shadows and gloss passes in the standalone renderer,
non-intro cutscenes, and standalone in-match performance (the active
workstream — RecompCore is the full-speed path today).

## Layout

```
runtime/host/    G4QE01 MMIO routing, interrupts, audio adaptation, HLE policy
chassis-module/  RecompCore module build (CMake + export tables)
tools/           generation, correction, and packaging tools
generated/       DolRecomp output (git-ignored; produced by generate.py)
docs/            architecture and reproduction notes
```

## Licensing & credits

GPLv3 (see [LICENSE](LICENSE)). Symbols and addresses derive from the CC0
[smstrikers-decomp](https://github.com/yannicksuter/SMStrikers) project — see
[THIRD_PARTY.md](THIRD_PARTY.md). Super Mario Strikers is © Nintendo/Next
Level Games; this project ships none of its code or assets, and module
binaries built from it must not be redistributed.
