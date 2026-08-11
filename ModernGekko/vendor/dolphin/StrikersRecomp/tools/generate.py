#!/usr/bin/env python3
"""Reproduce the recompiled Strikers sources from a user-supplied ISO.

Pipeline:
  1. Build DolRecomp (if its binary is missing).
  2. Extract sys/main.dol from the GameCube ISO (skip with --dol).
  3. Run DolRecomp in GameCube mode to emit split C into <repo>/generated/.
  4. Copy main.dol next to the generated output for the runtime loader.

No copyrighted data is committed; everything here is derived from the ISO the
user provides at build time.
"""

import argparse
import os
import platform
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

from fix_generated import fix_generated_sources

REPO_ROOT = Path(__file__).resolve().parent.parent


def run(cmd, **kwargs):
    print("+ " + " ".join(str(c) for c in cmd), flush=True)
    subprocess.run([str(c) for c in cmd], check=True, **kwargs)


def find_dolrecomp_binary(dolrecomp_dir: Path) -> Path | None:
    names = ["dolrecomp", "dolrecomp.exe"]
    search = [dolrecomp_dir / "build",
              dolrecomp_dir / "build" / "Release",
              dolrecomp_dir / "build" / "Debug"]
    for d in search:
        for n in names:
            p = d / n
            if p.is_file():
                return p
    return None


def build_dolrecomp(dolrecomp_dir: Path) -> Path:
    binary = find_dolrecomp_binary(dolrecomp_dir)
    if binary:
        print(f"DolRecomp already built: {binary}")
        return binary
    build_dir = dolrecomp_dir / "build"
    run(["cmake", "-S", dolrecomp_dir, "-B", build_dir, "-DCMAKE_BUILD_TYPE=Release"])
    run(["cmake", "--build", build_dir, "--config", "Release", "-j",
         str(os.cpu_count() or 4)])
    binary = find_dolrecomp_binary(dolrecomp_dir)
    if not binary:
        sys.exit("error: DolRecomp build did not produce a binary")
    return binary


def extract_dol(dolrecomp: Path, iso: Path, work: Path) -> Path:
    extract_dir = work / "extract"
    if extract_dir.exists():
        shutil.rmtree(extract_dir)
    run([dolrecomp, "extract", iso, extract_dir])
    dol = extract_dir / "sys" / "main.dol"
    if not dol.is_file():
        sys.exit(f"error: main.dol not found after extraction (looked for {dol})")
    return dol


def recompile(dolrecomp: Path, dol: Path, output_dir: Path, jobs: int):
    with tempfile.TemporaryDirectory(prefix="strikersrecomp_gen_") as tmp:
        tmp_out = Path(tmp)
        # --gamecube <dol> <dir> writes <dir>/generated/{generated.c,.h,chunks/}
        run([dolrecomp, "--gamecube", dol, tmp_out, "-j", str(jobs)])
        produced = tmp_out / "generated"
        if not (produced / "generated.h").is_file():
            sys.exit("error: DolRecomp did not produce generated/generated.h")
        if output_dir.exists():
            shutil.rmtree(output_dir)
        shutil.move(str(produced), str(output_dir))
    fixed = fix_generated_sources(output_dir)
    print(f"Applied {fixed} generated-code correction(s).")
    # Place the DOL where the runtime loads it by default.
    shutil.copy2(dol, output_dir / "main.dol")


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    src = ap.add_mutually_exclusive_group(required=True)
    src.add_argument("--iso", type=Path, help="GameCube ISO to extract main.dol from")
    src.add_argument("--dol", type=Path, help="use an existing main.dol (skip extraction)")
    ap.add_argument("--dolrecomp", type=Path, default=REPO_ROOT.parent / "DolRecomp",
                    help="path to the DolRecomp checkout (default: ../DolRecomp)")
    ap.add_argument("--output", type=Path, default=REPO_ROOT / "generated",
                    help="where to write recompiled sources (default: <repo>/generated)")
    ap.add_argument("--jobs", type=int, default=os.cpu_count() or 4,
                    help="parallel DolRecomp emit workers")
    args = ap.parse_args()

    dolrecomp_dir = args.dolrecomp.resolve()
    if not dolrecomp_dir.is_dir():
        sys.exit(f"error: DolRecomp not found at {dolrecomp_dir}")

    dolrecomp = build_dolrecomp(dolrecomp_dir)

    with tempfile.TemporaryDirectory(prefix="strikersrecomp_work_") as work_str:
        work = Path(work_str)
        if args.dol:
            dol = args.dol.resolve()
            if not dol.is_file():
                sys.exit(f"error: --dol path not found: {dol}")
            local = work / "main.dol"
            shutil.copy2(dol, local)
            dol = local
        else:
            dol = extract_dol(dolrecomp, args.iso.resolve(), work)
        recompile(dolrecomp, dol, args.output.resolve(), args.jobs)

    print(f"\nDone. Recompiled sources in: {args.output}")
    print("Next:\n  cmake -S . -B build\n  cmake --build build -j")


if __name__ == "__main__":
    main()
