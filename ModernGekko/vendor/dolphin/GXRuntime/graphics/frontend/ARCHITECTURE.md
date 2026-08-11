# Aurora recomp graphics architecture

This document is the implementation contract for agents working on
GXRuntime's game-agnostic graphics path. It supersedes the assumption that
Aurora's source-native command processor can become the compatibility
authority through isolated fixes.

## Decision

Build a GXRuntime-owned retail-GX front end, grounded in Dolphin's hardware
model, and feed normalized immutable state/draw/resource packets into Aurora's
existing renderer.

Do not:

- embed Dolphin `VideoCommon` wholesale;
- rewrite Aurora's WebGPU renderer, shader generator, texture converters, or
  pipeline cache without a renderer-specific falsifier;
- preserve Strikers SDK metadata as a permanent API;
- keep two production FIFO parsers after cutover;
- declare compatibility from a game screenshot.

The current patch stack and `dol_gx_recomp` parser are bootstrap and fixture
infrastructure. The new front end becomes the sole retail FIFO semantic owner.
Aurora's source-port wrappers may remain as encoders, but must emit into the
same retail front end or an explicitly optional extension path.

## Why this split

Aurora is MIT-licensed and already provides useful host-renderer machinery:

- WebGPU/Metal device and render submission;
- GX shader and pipeline generation;
- texture conversion and replacement;
- framebuffer, depth, copy-texture, and presentation infrastructure;
- source-port SDK wrappers.

Its current `command_processor.cpp` combines four concerns:

1. retail FIFO decoding;
2. CP/BP/XF state mutation;
3. guest resource resolution;
4. immediate Aurora renderer submission.

That coupling let source-native pointer/metadata assumptions hide retail
decoder defects. Session 37's direct replay found two independent indexed-XF
errors even though the same gameplay scene already rendered.

Dolphin is the hardware oracle, but its `VideoCommon` implementation is not a
small reusable library. BP/XF/opcode handling depends on `Core::System`, FIFO
threading, emulator memory, PixelEngine, shader managers, framebuffer
management, and global configuration. Embedding it would import an emulator
subsystem rather than define a recomp runtime boundary.

Use Dolphin in three ways:

- source truth for register, memory, ordering, and synchronization semantics;
- executable truth for synthetic FIFO/DOL probes and retail FIFO captures;
- differential oracle for normalized state, resource accesses, draw packets,
  and frame output.

N64ModernRuntime supports the same product pattern. Its `ultramodern` layer
implements libultra-like services and `librecomp` bridges generated code, but
graphics are intentionally supplied through mandatory renderer callbacks such
as RT64. The lesson is not that the runtime should contain a monolithic
renderer; it is that the runtime must expose a stable console-shaped graphics
seam. For GameCube recompilation that seam is retail GX FIFO, guest resources,
PE, and VI, not source-native GX SDK metadata.

DolRecomp also supports this boundary. Its public README and emitted helpers
make it CPU/codegen-only: generated code calls a supplied runtime through
`CPUState`, memory helpers, external MMIO callbacks, and host-call hooks. A
complete GXRuntime must therefore provide the missing machine services and the
GX frontend contract. It should not require each game to reinvent renderer
metadata HLE.

Dusklight remains useful as an Aurora-native path oracle. It demonstrates how
source ports drive Aurora through source-level GX/J3D code and Aurora
extensions, but it is not hardware truth and cannot be the stable recomp API.

## Target ownership

```text
DolRecomp game
  -> GXRuntime WGPIPE / PE / VI / guest-memory services
  -> RetailGxFrontend
       FIFO assembler + display lists
       CP/VCD/VAT + vertex fetch
       XF memory/registers
       BP/PE/TMEM/EFB state
       resource coherency + synchronization
       normalized commands/state snapshots
  -> AuroraRenderSink
       GX state -> shader/pipeline configuration
       texture/TLUT conversion
       draw/copy/clear/peek/poke execution
       WebGPU submission and VI presentation
```

- GXRuntime owns guest memory, MMIO, event clocks, interrupts, and the
  frontend-to-renderer host contract.
- The GXRuntime-owned Aurora fork/subtree owns `RetailGxFrontend` and
  `AuroraRenderSink`.
- Strikers owns only title automation, SDK symbol policy, and diagnostics.
- Dolphin and Dusklight remain read-only oracles.

## Recomp graphics API

The API is a console boundary, not an SDK-call boundary. Its required inputs
are:

### Configuration

- guest range resolver:
  `(address, size, address_space, access, resource_kind) -> range`;
- optional range identity/generation for cache invalidation;
- PE event callback for token/finish interrupts;
- log/fatal callback;
- deterministic trace sink;
- backend capabilities and presentation configuration.

Every resolved range reports:

- host pointer;
- requested and available bytes;
- virtual/physical address interpretation;
- read/write access;
- stable identity;
- content generation, or `unknown` to force hash/snapshot validation.

### Runtime operations

- `write_fifo(bytes, size)`: accepts arbitrarily fragmented WGPIPE writes;
- `flush(reason)`: drains complete commands without inventing frame semantics;
- `read_pe` / `write_pe`: token, finish, bbox, and EFB CPU access state;
- `present_vi(config)`: VI-owned presentation, distinct from EFB copy;
- `notify_cpu_read/write(range)`: optional coherency acceleration;
- `capture_begin/end`: deterministic FIFO plus resource snapshot capture;
- `shutdown`: resolves pending writebacks and GPU work.

Display-list calls, indexed arrays, textures, TLUT loads, and EFB copy
destinations are guest addresses resolved internally. Source-native pointers,
byte sizes invented by SDK HLE, `texObjId`, and G4QE01 addresses are forbidden
from the stable API.

### Output to Aurora

The render sink receives immutable packets:

- state snapshot/version;
- primitive and VCD/VAT-derived vertex layout;
- inline vertex bytes plus resolved indexed ranges;
- shader/pipeline key;
- resolved texture/TLUT views with coherency token;
- copy/clear/peek/poke operation;
- ordering/synchronization marker.

The sink does not reinterpret FIFO or call back into title HLE.

## Complete module matrix

All modules are in scope from the start. Agents may implement them in parallel,
but no module is stable without its oracle and fixture gates.

| Module | Required semantics | Primary Dolphin oracle | Minimum fixture gate |
|---|---|---|---|
| FIFO assembler | fragmented writes, endian order, command boundaries, invalid opcodes | `OpcodeDecoding.h` | every opcode split at every byte boundary |
| Display lists | guest resolution, nesting, recursion limit, ordering, invalidation | opcode decoder + FIFO player | nested and self-recursive lists |
| CP state | matrix indices, VCD, all VAT groups, array bases/strides | `CPMemory`, `VertexLoaderBase` | state hash for every CP register |
| Vertex fetch | direct/index8/index16, NBT/NBT3, formats, fractions, matrix indices | `VertexLoader*` | generated layout/data differential |
| XF memory | direct/indexed loads, partial ranges, matrices, lights | `XFStructs`, `XFMemory` | full and partial A-D indexed loads |
| XF registers | viewport, projection, channels, texgen, dual texgen | `XFStateManager`, shader manager | normalized state differential |
| BP state | mask semantics, TEV, indirect, fog, alpha, depth, blend, scissor | `BPStructs`, `BPMemory` | register corpus with state hashes |
| Texture/TMEM | images, mips, formats, cache invalidation, TLUT loads/sampling | `TextureInfo`, `TMEM`, decoder | byte-range and decoded-image hashes |
| EFB | copy, clear, resolve, format conversion, scale/filter, peek/poke | BP functions + framebuffer manager | memory and pixel differentials |
| PE/sync | tokens, finish, interrupts, bbox, draw-done ordering | `PixelEngine`, FIFO | event transcript differential |
| VI/present | XFB/EFB ownership, aspect/viewport, retrace presentation | VI + Present | frame-boundary transcript |
| Trace/replay | FIFO plus resource snapshots and writebacks | FifoPlayer/FifoCI | deterministic state/frame replay |
| Aurora sink | immutable state mapping, shaders, pipelines, resources | Aurora source + Dusklight path | headless packet tests + image corpus |

Include zfreeze, perf-query/metrics commands, cache invalidation, and malformed
stream behavior in the appropriate module. Unsupported behavior must return a
targeted conformance failure; silent ignore is not compatibility.

## Harness directive

The harness should drive agents by module matrix and oracle pack, not by a
queue of gameplay screenshots. When a game exposes a visual failure, classify
the failure into this matrix, add or extend the smallest general fixture, and
only then return to the game as acceptance evidence.

For every module, keep four artifacts together:

- Dolphin source/executable oracle for hardware truth;
- synthetic FIFO/DOL or captured FIFO/resource case;
- normalized frontend state/resource/event transcript;
- Aurora sink packet or image regression.

This is the highest-throughput path for many agents: the work is divisible by
hardware module, has deterministic gates, and does not require repeatedly
driving through Strikers to discover the next missing primitive.

## Resource coherency rule

Guest memory is mutable and recompiled code often accesses MEM1 directly.
Correctness cannot depend on every CPU write being intercepted.

- If a resolver supplies a trustworthy generation, cache by
  `(identity, generation, descriptor)`.
- Otherwise hash or snapshot the exact resource range at the command where
  hardware consumes it.
- EFB copies that are CPU-readable must produce correct guest bytes before a
  CPU read; a GPU-only copy-texture alias is an optimization, not sufficient
  semantics.
- Resource bounds come from CP/VAT/draw analysis or hardware texture/copy
  layout, never from a title-wide guessed vertex count.

## Conformance workflow

1. Build synthetic FIFO/resource cases from the retail encoding.
2. Run the same case through Dolphin or a minimal DOL in Dolphin.
3. Compare normalized state, resource reads/writes, events, and draw packets.
4. Feed the normalized packet into Aurora's headless sink test.
5. Add rendered image comparison only after state/resource equality.
6. Use retail games as coverage collectors and acceptance clients, not as the
   unit-test driver.

When a game exposes a missing primitive, add the smallest general fixture to
the matrix. Do not diagnose the scene until the relevant module corpus passes.

## Migration

1. Materialize the GXRuntime-owned Aurora fork/subtree with upstream commit,
   MIT notice, and patch provenance.
2. Add `RetailGxFrontend` and `AuroraRenderSink` as separately buildable
   libraries with no Strikers dependency.
3. Move the resolver/resource helpers and direct replay into the frontend.
4. Port/implement the complete module matrix against Dolphin differentials.
5. Adapt Aurora's current `GXState`/pipeline path behind the immutable sink.
6. Route GXRuntime WGPIPE/PE/VI exclusively through the frontend.
7. Remove Strikers array/texture/TLUT/copy metadata from the correctness path.
8. Delete the bounded `dol_gx_recomp` parser or retain only a fixture builder
   once the frontend owns replay.
9. Validate Strikers and a second DolRecomp graphics client before freezing API
   version 1.

## Licensing

Aurora is MIT. Dolphin's relevant source is generally
`GPL-2.0-or-later`. GXRuntime already contains GPL-derived material and is
currently documented as GPL-compatible pending a repository-level license
decision.

Any direct Dolphin code port must preserve SPDX/copyright attribution and makes
the combined distribution subject to the applicable GPL terms. If a permissive
standalone runtime becomes a requirement, use Dolphin only as an external
behavioral oracle and implement from independently documented encodings and
differential test vectors. Treat this as a release/legal review requirement,
not an informal assumption.
