#!/usr/bin/env python3
"""pixel_diff — tier-3 banded pixel comparison vs Dolphin frame dumps.

Compares dolgx_replay --png-dir output against Dolphin's deterministic
framedump PNGs of the same .dff scene, in EFB/VI output space (640x480):

  ours:   2048x1536 retina window capture; the presented frame fills the
          whole window in VI 640x480 shape (the dark band at the bottom is
          the game's own black overscan rows, NOT a letterbox — a 448-line
          crop model loses 0.2 band vs the full-frame resize; verified by
          alignment search on start_menu) -> bilinear-resize to 640x480.
  golden: Dolphin -b <scene.dff> with Dolphin.Movie.DumpFrames=True +
          Graphics.Settings.DumpFramesAsImages=True (640x480 native dumps,
          MD5-deterministic across runs).

Metrics per frame pair (starting thresholds from the S9 spec):
  band  = fraction of pixels whose max channel delta <= --tolerance
          (default 8/255 ~= one 6-bit GC dither step); pass >= --min-match
  ssim  = grayscale SSIM, 8x8 uniform windows; pass >= --min-ssim

Directory mode pairs sorted PNG lists; --auto-align searches the offset of
the golden sequence into ours (Dolphin skips dumping the first ~2 presents).
Exit 0 if every compared pair passes both thresholds, else 1 (an
EXPECTED-FAIL scene is a recorded inventory line, not a harness error).
"""

import argparse
import os
import re
import sys

import numpy as np
from PIL import Image

VI_OUT = (640, 480)  # Dolphin's dumped VI output size


def load_ours(path: str) -> np.ndarray:
    img = Image.open(path).convert("RGB")
    return np.asarray(img.resize(VI_OUT, Image.BILINEAR), dtype=np.int16)


def load_golden(path: str) -> np.ndarray:
    img = Image.open(path).convert("RGB")
    if img.size != VI_OUT:
        img = img.resize(VI_OUT, Image.BILINEAR)
    return np.asarray(img, dtype=np.int16)


def band_match(a: np.ndarray, b: np.ndarray, tolerance: int) -> float:
    delta = np.abs(a - b).max(axis=2)
    return float((delta <= tolerance).mean())


def ssim(a: np.ndarray, b: np.ndarray, window: int = 8) -> float:
    ga = np.asarray(Image.fromarray(a.astype(np.uint8)).convert("L"), dtype=np.float64)
    gb = np.asarray(Image.fromarray(b.astype(np.uint8)).convert("L"), dtype=np.float64)
    h = ga.shape[0] // window * window
    w = ga.shape[1] // window * window

    def blocks(x):
        return x[:h, :w].reshape(h // window, window, w // window, window)

    ba, bb = blocks(ga), blocks(gb)
    mu_a = ba.mean(axis=(1, 3))
    mu_b = bb.mean(axis=(1, 3))
    var_a = ba.var(axis=(1, 3))
    var_b = bb.var(axis=(1, 3))
    cov = (ba * bb).mean(axis=(1, 3)) - mu_a * mu_b
    c1 = (0.01 * 255.0) ** 2
    c2 = (0.03 * 255.0) ** 2
    s = ((2 * mu_a * mu_b + c1) * (2 * cov + c2)) / (
        (mu_a**2 + mu_b**2 + c1) * (var_a + var_b + c2)
    )
    return float(s.mean())


def numeric_key(name: str):
    nums = re.findall(r"\d+", name)
    return [int(n) for n in nums] if nums else [0]


def png_list(path: str):
    if os.path.isfile(path):
        return [path]
    names = sorted(
        (n for n in os.listdir(path) if n.lower().endswith(".png")),
        key=numeric_key,
    )
    return [os.path.join(path, n) for n in names]


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--ours", required=True, help="PNG file or --png-dir directory")
    parser.add_argument("--golden", required=True, help="PNG file or Dolphin Dump/Frames dir")
    parser.add_argument("--tolerance", type=int, default=8, help="per-channel band (default 8)")
    parser.add_argument("--min-match", type=float, default=0.98)
    parser.add_argument("--min-ssim", type=float, default=0.97)
    parser.add_argument("--auto-align", action="store_true",
                        help="search the golden->ours frame offset (0..4) by best band match")
    parser.add_argument("--offset", type=int, default=None,
                        help="explicit ours-index offset for golden frame 0")
    parser.add_argument("--diff-out", default=None,
                        help="write per-pair |delta| heatmap PNGs here")
    args = parser.parse_args()

    ours_paths = png_list(args.ours)
    golden_paths = png_list(args.golden)
    if not ours_paths or not golden_paths:
        print("pixel_diff: no PNGs found", file=sys.stderr)
        return 2

    offset = args.offset
    if offset is None and args.auto_align and len(ours_paths) > 1:
        golden0 = load_golden(golden_paths[0])
        scores = []
        for candidate in range(min(5, len(ours_paths))):
            scores.append(band_match(load_ours(ours_paths[candidate]), golden0,
                                     args.tolerance))
        offset = int(np.argmax(scores))
        print(f"pixel_diff: auto-align offset={offset} "
              f"(candidate band scores {['%.4f' % s for s in scores]})")
    if offset is None:
        # Static scenes: compare steady state (the last frame of each side).
        offset = 0
        if len(golden_paths) == 1 and len(ours_paths) > 1:
            ours_paths = ours_paths[-1:]

    pairs = []
    for i, golden_path in enumerate(golden_paths):
        j = i + offset
        if j >= len(ours_paths):
            break
        pairs.append((ours_paths[j], golden_path))
    if not pairs:
        print("pixel_diff: no frame pairs to compare", file=sys.stderr)
        return 2

    if args.diff_out:
        os.makedirs(args.diff_out, exist_ok=True)

    all_pass = True
    matches, ssims = [], []
    for ours_path, golden_path in pairs:
        a = load_ours(ours_path)
        b = load_golden(golden_path)
        match = band_match(a, b, args.tolerance)
        s = ssim(a, b)
        matches.append(match)
        ssims.append(s)
        ok = match >= args.min_match and s >= args.min_ssim
        all_pass &= ok
        print(f"{os.path.basename(ours_path)} vs {os.path.basename(golden_path)}: "
              f"band={match:.4f} ssim={s:.4f} {'PASS' if ok else 'FAIL'}")
        if args.diff_out:
            delta = np.abs(a - b).max(axis=2)
            heat = np.zeros((*delta.shape, 3), dtype=np.uint8)
            heat[..., 0] = np.clip(delta * 4, 0, 255)  # red = disagreement
            heat[..., 1] = np.where(delta <= args.tolerance, 64, 0)
            Image.fromarray(heat).save(
                os.path.join(args.diff_out,
                             os.path.basename(ours_path).replace(".png", "_diff.png")))

    print(f"pixel_diff: {len(pairs)} pairs tolerance={args.tolerance} "
          f"band min/mean {min(matches):.4f}/{float(np.mean(matches)):.4f} "
          f"ssim min/mean {min(ssims):.4f}/{float(np.mean(ssims)):.4f} "
          f"-> {'PASS' if all_pass else 'FAIL'}")
    return 0 if all_pass else 1


if __name__ == "__main__":
    sys.exit(main())
