# Reproducing the build

Everything is derived from your own Super Mario Strikers ISO. Nothing
copyrighted is committed.

## Prerequisites

- CMake ≥ 3.16 and a C11 compiler.
- Python 3.
- A [DolRecomp](../../DolRecomp) checkout (default location `../DolRecomp`;
  override with `--dolrecomp`).
- A *Super Mario Strikers* `G4QE01` ISO.

## Step 1 — Generate the recompiled C

```sh
python3 tools/generate.py --iso /path/to/strikers.iso
```

This builds DolRecomp if needed, extracts `sys/main.dol`, runs DolRecomp in
GameCube mode into `generated/` (163 chunk files), and copies `main.dol` to
`generated/main.dol`. It also applies the repository's generated-code
compatibility fixes, including correct PowerPC single-precision arithmetic
rounding.

Options: `--dol` (use an existing DOL), `--dolrecomp` (DolRecomp location),
`--output` (alternate output dir; pass the same path to CMake as
`-DSTRIKERSRECOMP_GENERATED_DIR=`), `--jobs N`.

## Step 2 — Build

```sh
cmake -S . -B build
cmake --build build -j
```

Default build type is `Debug` (fast to compile for the large chunk files).
For optimized output: `-DCMAKE_BUILD_TYPE=Release`.

## Step 3 — Run

```sh
./build/StrikersRecomp --trace-every 100000
```

Expected output: a boot log, executed blocks from entry `0x80005240`, then a
clean stop at the OS/hardware boundary with a final-state report.
Use `--mmio-log` to watch hardware accesses or `--max-blocks N` to bound a run.
