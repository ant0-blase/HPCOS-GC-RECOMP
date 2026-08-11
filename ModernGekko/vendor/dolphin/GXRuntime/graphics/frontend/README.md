# Aurora recomp mode

This directory is the GXRuntime-owned home for Aurora changes required by
static-recompiled GameCube games.

Do not commit recomp-specific work into the standalone workspace `aurora/`
checkout — it is a pristine upstream reference. The
vendored fork is materialized at `GXRuntime/graphics/aurora/` (see its
`UPSTREAM.md`): Aurora changes are normal commits there. The bootstrap patch
stack this directory used to own is retired; its content is folded into the
fork baseline and documented below for provenance.

## Decision

Build a recompilation-friendly Aurora mode under GXRuntime ownership.

Replace the recomp-facing GX front end, not the renderer. Aurora already owns a
useful GX-to-host renderer, but its source-native command processor is no longer
the compatibility authority. The target front end is grounded in Dolphin's
hardware semantics and accepts retail FIFO, display-list bytes, CP/BP/XF state,
guest addresses, PE synchronization, and VI presentation directly.

See `ARCHITECTURE.md` for the complete API, module matrix, migration, and
licensing rules.

The selected architecture is:

```
recompiled game
  -> GXRuntime guest memory / hardware services
  -> retail-GX frontend (Dolphin-grounded semantics)
  -> immutable draw/state/resource packets
  -> Aurora render sink
```

The current patch overlay and bounded GXRuntime parser are checkpoint/fixture
mechanisms. They must not survive as competing production semantic owners.
Development is module-driven from the complete matrix in `ARCHITECTURE.md`;
Strikers and a second title are acceptance clients.

This mirrors the useful part of N64ModernRuntime: the runtime/recomp bridge is
stable and renderer-shaped, while the renderer implementation is supplied
behind that seam. For GameCube recompilation, that seam is retail GX FIFO,
guest resources, PE, and VI. Aurora's existing renderer can sit behind it;
Aurora's source-native metadata path cannot be the seam.

## Owned module targets

The first GXRuntime-owned module is materialized in this directory:

- `GXRuntime::retail_gx_frontend` owns the current bounded retail parser for
  fragmented FIFO, nested display lists, CP/BP/XF/indexed-XF, indexed draw
  spans, CP VCD/VAT-derived vertex layouts, and texture/TLUT/copy resource
  derivation.
- `GXRuntime::aurora_render_sink` defines the packet sink seam that Aurora's
  renderer will consume.
- `retail_gx_frontend_c.h` exposes the frontend through an opaque C ABI plus
  render-packet callback for GXRuntime clients and backend integration.
- `aurora_recomp_frontend_tests` replays the all-module synthetic FIFO through
  `RetailGxFrontend -> RecordingAuroraRenderSink`, proving the direct replay now
  crosses the frontend/sink boundary without booting a game or linking Aurora.
  It also feeds CP/BP/XF bytes through the C ABI one byte at a time to prove
  arbitrary WGPIPE fragmentation and callback packet ordering.
- The live Aurora backend can optionally shadow-feed WGPIPE bytes into
  `RetailGxFrontend` with `DOL_AURORA_RECOMP_FRONTEND_SHADOW=1`. This is a
  pressure-test bridge only: live rendering still uses Aurora's old path until
  normalized packets can be submitted/compared through the sink.

`UPSTREAM.md` records the Aurora reference commit and patch provenance. This is
an owned module boundary, not a commit to the standalone `aurora/` checkout.

## Module backlog

Each module must be implemented without Strikers literals and must have a
focused fixture or replay before it is called stable.

1. Guest memory resolver
   - API: resolve guest virtual/physical address + byte count + access kind.
   - Must support MEM1 and future ARAM/locked-cache backed resources where
     applicable.
   - Aurora must not require native source pointers for retail resources.
   - Current GXRuntime API: `DolGuestAddressResolver` plus
     `dol_guest_address_resolver_resolve`, with typed resource kinds for display
     lists, vertex arrays, textures, TLUTs, FIFO data, and copy destinations.

2. Retail FIFO ingress
   - Accept bytes exactly as the game writes them to WGPIPE/display lists.
   - Preserve big-endian command parsing.
   - Keep source-native Aurora extension commands available, but do not require
     them for recompiled games.

3. Display-list executor
   - Resolve `GXCallDisplayList` guest addresses through the memory resolver.
   - Execute nested `GX_CMD_CALL_DL` or fail with a targeted fixture, not a broad
     silent ignore.
   - Run the SDK-equivalent dirty-state / primitive-flush ordering before
     playback.

4. CP array base and stride resolver
   - Support retail CP array-base registers (`0xA0..0xAF`) as guest physical
     addresses.
   - Own VCD/VAT registers (`0x50`, `0x60`, `0x70/0x80/0x90 + vtx_fmt`) and
     derive per-format vertex sizes and indexed-attribute spans from them.
   - Retain Aurora extension array loads for source ports.
   - Do not force game HLE to invent native array metadata.

5. Indexed range analyzer
   - Derive per-draw required byte spans from the actual indexed draw stream.
   - Upload only required prefixes to Aurora storage.
   - Do not merge indexed draws unless range accounting remains correct.

6. Texture/TLUT/image resolver
   - Resolve texture image, mip, palette, and TLUT addresses from guest memory.
   - Keep title policy out of the renderer; the renderer owns format/layout
     decoding, not G4QE01 addresses.

7. XF/BP/TEV/cull conformance
   - Add targeted fixtures for matrix loads, indexed XF loads, cull-all,
     viewport/scissor, copy/filter state, blend/alpha/depth, and TEV paths that
     are used by retail games.
   - Dolphin source is hardware truth; Dusklight is only Aurora-native call-path
     truth.

8. FIFO/resource trace replay
   - Record retail FIFO bytes plus memory-resource snapshots at the GXRuntime
     boundary.
   - Replay without booting the full game.
   - Compare command state and frames against Dolphin/Aurora expectations.

9. Acceptance clients
   - Strikers remains the first end-to-end client.
   - Bring in another title before declaring the Aurora recomp-mode API stable.

## Module completion contract

A module is not complete because one Strikers scene improved. It is complete
when it has:

- A small fixture, synthetic display list, or replay that fails before and
  passes after.
- A source-grounded oracle note: Dolphin source for hardware semantics, Aurora
  source/Dusklight for existing source-native behavior when relevant.
- No G4QE01-specific addresses or scene assumptions in GXRuntime/Aurora.
- A documented boundary: what belongs in GXRuntime, what belongs in Aurora
  recomp mode, and what remains title policy.
- A Strikers smoke or capture proving the acceptance client did not regress.

## Fork baseline provenance (the retired patch stack, folded into the fork)

The patches below no longer exist as files; they are part of the
`graphics/aurora/` fork baseline (upstream `0549581` + 0001-0007). Patches
0005-0007 (attnfunc decode fix, EFB readback + sync pipelines, cull-all draw
skip) are summarized in the fork's `UPSTREAM.md`. The detailed intents of
0001-0004 are kept here:

`patches/0001-session31-recomp-indexed-array-spans.patch` captured the local
Aurora indexed-span changes from session 31:

- `copy_xf_data` returns successfully after loading position matrices.
- Indexed draw streams are scanned to calculate per-attribute required byte
  spans.
- Indexed draw merging is disabled until span accounting can be preserved across
  merges.
- Aurora uploads only the required indexed prefix instead of the whole
  advertised array size.

`patches/0002-session34-guest-resolver-call-dl-cp-arrays.patch` captures the
first Aurora-side resolver consumption:

- Adds `aurora::gx::recomp` guest-address resolver hooks.
- Resolves nested `GX_CMD_CALL_DL` addresses through the resolver and executes
  the resolved bytes with Aurora's existing FIFO parser.
- Resolves retail CP array-base registers (`0xA0..0xAF`) as physical guest
  vertex-array addresses and marks them big-endian.

`patches/0003-session35-texture-tlut-copy-resolvers.patch` captures the next
resource-consumer slice:

- Resolves retail texture image BP state (`image0`/`image3`) through the guest
  resolver when source-native texture metadata is absent.
- Tracks hardware-style TLUT loads by TMEM offset: BP `0x64/0x65` resolves the
  palette bytes, and per-texture TLUT BP registers provide the sampling offset
  and palette format.
- Resolves retail texture-copy destinations from BP `0x49/0x4A/0x4B/0x52` so
  dynamic EFB-copy textures key on the same host pointer as later texture
  binds.
- Keeps Aurora's source-native `GX_AURORA_*` metadata as a fallback and consumes
  its copy-destination mipmap byte so source-native command alignment remains
  correct.

`patches/0004-session37-direct-replay-indexed-xf.patch` makes the module
contract execute through Aurora's real parser:

- Moves the guest resolver plus lazy texture/TLUT resolution into a focused
  `lib/gx/recomp.cpp` unit shared by the renderer and headless FIFO tests.
- Lets GXRuntime add its owned replay fixture to Aurora's existing
  `gx_fifo_tests` target without copying Aurora's test harness.
- Fixes retail indexed-XF decoding to read the encoded 16-bit source index and
  to map opcodes `0x20/0x28/0x30/0x38` to XF arrays 21-24.
- Bounds-checks the indexed source span before copying it into XF memory.
- Adds one direct replay test covering nested display lists, CP arrays,
  indexed spans, indexed XF matrices, texture/TLUT/copy resources, cull state,
  and draw submission through Aurora.

There is no patch application step anymore: the fork at
`GXRuntime/graphics/aurora/` already contains this baseline, and both build
systems point at it by default.

## Current implemented contract

`GXRuntime/include/gxruntime/guest_memory.h` defines the first stable
recomp-mode seam:

- `DolGuestAddressSpace`: auto, forced virtual, forced physical.
- `DolGuestResourceKind`: generic, FIFO, display list, vertex array, texture,
  TLUT, copy destination.
- `DolGuestResolvedRange`: host pointer, requested size, available bytes,
  resolved address space, and resource kind.
- `DolGuestAddressResolver`: binds `DolGuestMemory` and `CPUState`.
- `dol_guest_address_resolver_init_callback`: adapts backend/client resolver
  callbacks without forcing the frontend to know a concrete memory owner.

Runtime tests cover:
- MEM1 cached virtual resolution;
- MEM1 physical resolution;
- locked-cache resolution through auto mode;
- forced-space rejection when physical and virtual are confused;
- zero-size and overrun rejection.

This is the resolver Aurora recomp mode should consume before CP array bases,
display-list addresses, textures, TLUTs, or copy destinations are moved out of
Strikers metadata HLE.

`GXRuntime/include/gxruntime/gx_recomp.h` defines the coordinated module
fixture surface:

- Retail FIFO ingress: fixed-capacity byte capture that preserves the exact
  stream and records trace events.
- Display-list executor boundary: resolves 32-byte-aligned display-list
  addresses through `DolGuestAddressResolver` and can append the resolved bytes
  to the FIFO fixture.
- CP array base/stride resolver: tracks retail CP registers `0xA0..0xAF` and
  `0xB0..0xBF`, resolves array bases as physical addresses, and resolves only
  the requested indexed byte span.
- Indexed range analyzer: computes required byte spans from indexed vertex
  stream offsets, supporting 8-bit and 16-bit big-endian indices plus
  element-size/bias cases used by normal/tangent/binormal-style layouts.
- Texture/TLUT resolver: parses SDK image/TLUT physical-address fields and
  resolves concrete byte ranges. Texture byte sizes use Dolphin-style tiled GX
  format classes for I4/I8/IA4/IA8/RGB565/RGB5A3/RGBA8/CI4/CI8/CI14X2/CMPR.
- Copy-destination resolver: resolves EFB-copy destinations as physical guest
  ranges.
- XF/BP/TEV/cull conformance markers: records BP and XF loads and explicitly
  flags `GX_CULL_ALL` from genMode bits.
- FIFO/resource trace replay seed: records module events so a later replay
  layer can assert the resource sequence without booting a full game.

The current fixture does not render. It exists to make the module boundaries
executable before the Aurora fork/subtree consumes them.

Session 36 extends that fixture surface with a bounded all-module retail FIFO
replay:

- `dol_gx_recomp_replay_fifo` parses the command subset needed by the current
  module ladder: CP array base/stride loads, BP loads, XF loads, indexed XF
  loads, nested `GX_CMD_CALL_DL`, and indexed draw commands with a configured
  fixture vertex layout.
- BP replay resolves texture image state (`image0`/`image3`), hardware-style
  TLUT loads (`0x64/0x65`) into a TMEM-offset table, per-texture TLUT
  offset/format regs, and EFB-copy destinations (`0x49/0x4A/0x4B/0x52`).
- The integration test feeds one synthetic retail stream through FIFO ingress,
  display-list resolution, CP arrays, indexed spans, texture/TLUT/copy
  resource resolution, XF/BP markers, cull-all, and replay trace events.

Session 37 consumes the same module contract through Aurora's command processor.
The direct test is injected from
`third_party/aurora-recomp/tests/recomp_fifo_test.cpp`; Aurora remains the only
production GX parser. The test caught two independent indexed-XF decode defects
before a gameplay run: the packet index was truncated/misaligned as an 8-bit
field, and the opcode-to-XF-array expression selected array 49 instead of
`GX_POS_MTX_ARRAY` through `GX_LIGHT_ARRAY`. Dolphin and the retail SDK encode
the command as one big-endian `u32` containing a 16-bit index plus a 16-bit
destination/length field.

Session 40 moved the current bounded replay subset into `RetailGxFrontend`
itself. `dol_gx_recomp_replay_fifo` remains useful fixture scaffolding, but the
frontend no longer delegates `replay_fifo()` to that C parser.

Session 41 added Dolphin-grounded CP VCD/VAT-derived vertex-layout ownership.
The frontend now tracks VCD_LO/VCD_HI, all three VAT groups for all eight
formats, direct matrix-index bytes, direct/index8/index16 attributes, Dolphin
size tables for position/normal/color/texcoord elements, and NBT index3
normal/tangent/binormal spans. Draw parsing lazily derives the layout if real
FIFO provides CP state before the draw. The C ABI exposes an explicit
`derive_vertex_layout` hook for tests and clients that want to inspect the
derived state.

The live Aurora backend now has an opt-in shadow bridge:
`DOL_AURORA_RECOMP_FRONTEND_SHADOW=1` feeds the same fragmented WGPIPE bytes
into `RetailGxFrontend` while preserving the current live renderer path. A
frontend rejection disables the shadow path and logs the FIFO byte count; it
must not break gameplay. This is the bridge-pressure stage, not final cutover.
Next, replace trace-only packets with normalized immutable draw/resource/state
packets in `AuroraRenderSink`, then submit/compare those packets before routing
live rendering exclusively through the frontend.

`GXRuntime/include/gxruntime/platform.h` now exposes
`dol_platform_set_guest_address_resolver`, an installation hook used by
Strikers to connect `DolGuestAddressResolver` to the active Aurora backend.
The Aurora backend maps that callback into `aurora::gx::recomp` without making
standalone Aurora depend on GXRuntime headers. This is the bootstrap shape of
the future GXRuntime-owned Aurora fork/subtree boundary.

## Development rule for future agents

When a new graphics bug appears, first ask which module above should own it. If
the answer is "more native metadata in Strikers HLE," stop and design the
recomp-mode Aurora fixture instead. Strikers can expose missing behavior, but it
must not be the only way the renderer becomes correct.
