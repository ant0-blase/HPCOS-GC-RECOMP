# Aurora fork — provenance

This directory is GXRuntime's **owned hard fork** of Aurora (program 63, decision 5,
2026-07-03). It is first-class product source: changes are normal commits here. There is no
patch stack and no upstream tracking/rebase intent.

- upstream: `https://github.com/encounter/aurora`
- fork point: `05495810ba4bc906f4f9a131cb5792011b3f35c4`
  (`0549581 Migrate remaining GX functions to FIFO`, 2026-06-22)
- license: MIT (upstream `LICENSE` retained in this directory; keep attribution)
- the workspace `aurora/` checkout is a pristine read-only reference of the same commit —
  never patch or edit it

## Baseline delta vs upstream (the retired patch stack, folded in at fork time)

The fork baseline = upstream `0549581` + the seven bootstrap patches (verified exact at
vendor time: pristine+stack rebuild diffed empty against this tree):

| retired patch | intent |
|---|---|
| 0001-session31-recomp-indexed-array-spans | per-draw indexed CP-array span events so recomp guest arrays resolve; adds the `lib/gx/recomp.{cpp,hpp}` seam |
| 0002-session34-guest-resolver-call-dl-cp-arrays | external guest-memory resolver for display lists + CP array bases (static-recomp feeds guest addresses, not host pointers) |
| 0003-session35-texture-tlut-copy-resolvers | guest resolvers for texture/TLUT/copy-source memory |
| 0004-session37-direct-replay-indexed-xf | direct replay injection for tests + two indexed-XF decode fixes (Dolphin/SDK-proven) |
| 0005-session63-xf-chanctrl-attnfn-decode | XF chan-ctrl attnfunc 2-bit decode was transposed (bits 9/10); SDK/Dolphin-proven fix (63/S6). Upstreamable as-is |
| 0006-session63-efb-readback-sync-pipelines | EFB readback (`lib/gfx/efb_readback.{cpp,hpp}`) + `AURORA_SYNC_PIPELINES` + shader-gen clamp — deterministic pixel replay (63/S8). Upstream remedy: public readback API |
| 0007-session63-cull-all-draw-skip | `push_gx_draw` drops draws while `cullMode==GX_CULL_ALL` (GC-exact: rasterize nothing) (63/S9). Upstreamable as-is |

## Planned carve (program 63)

- `lib/gfx/`, `lib/webgpu/`, window/input shell, texture codecs, present: **kept** (substrate).
- `lib/gx/` (GX semantics: state→pipeline, WGSL TEV/lighting/texgen): **replaced** by
  `GXRuntime/graphics/gxcore/` (Dolphin-ported, GPLv2+ — see `docs/abi-scope-license.md`),
  then deleted at program 63 Mfin.
