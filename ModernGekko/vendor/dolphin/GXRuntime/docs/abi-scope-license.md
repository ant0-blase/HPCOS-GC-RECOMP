# GXRuntime ABI, scope, and licensing status

This document records the current reusable-runtime boundary. It is part of the
runtime repository so consumers do not need the harness notes to understand the
contract.

## Generated-code ABI

GXRuntime currently consumes DolRecomp-style generated C:

```c
void func_<guest_address>(CPUState* ctx);
int dolrecomp_call(CPUState* ctx, u32 address);
int dolrecomp_run_blocks(CPUState* ctx, u32 max_blocks);
```

Generated code includes `core/cpu.h` and directly reads/writes fields in
`CPUState`, so the struct layout is an ABI, not an implementation detail.

`GXRuntime/include/core/cpu.h` intentionally mirrors
`DolRecomp/src/core/cpu.h` through the `ram_size` field. The only current
GXRuntime extension is a tail field:

```c
PPCExternalPointer external_pointer;
```

That extension lets PPC helpers obtain a stable host pointer for external
guest-visible memory such as locked cache and VM windows. It must remain a tail
extension until DolRecomp owns a versioned generated-code ABI that includes this
capability.

The current macros are:

```c
GXRUNTIME_CPU_ABI_VERSION = 1
GXRUNTIME_CPU_ABI_DOLRECOMP_PREFIX = 1
GXRUNTIME_CPU_ABI_EXTERNAL_POINTER_EXTENSION = 1
```

`tests/runtime_tests.c` has compile-time guards for the generated-code prefix
and the tail-extension rule. If a future change inserts, removes, or reorders
fields in the prefix, update the generated-code ABI intentionally rather than
allowing silent drift.

## Current v1 scope

GXRuntime owns game-independent console/runtime services:

- PPC state and helper semantics required by generated code.
- Big-endian MEM1 access and host-backed external memory windows.
- Fixed-capacity callback MMIO bus for guest external reads/writes.
- DOL section loading and boot low-memory globals.
- ARAM storage and MEM1/ARAM DMA helpers.
- Host-backed DVD image/FST reads.
- Virtual GameCube memory-card service.
- AI DMA cadence primitive and AI/DSP-AID device register MMIO (control,
  sample-rate decode, DSP AID interrupt status/mask, audio-DMA source/length).
- Deterministic event-clock queue over abstract guest-work units.
- VI retrace/timebase clock primitive built on the event clock.
- PI interrupt cause/mask plus the first VI/SI/PE/DSP source register
  primitive.
- SI register device state through the communication I/O buffer, including
  polling status, per-channel RDST consumption, synchronous command-transfer
  completion, and mask-gated RDST/TC interrupt status.
- EXI channel-controller registers, immediate/DMA transfer descriptors,
  synchronous or deferred completion, interrupt aggregation, and a pluggable
  device-transfer boundary.
- DI status/cover/config and command/DMA registers, callback-backed command
  execution, completion/error/break interrupts, and disc-presence state.
- Backend-neutral platform callbacks.
- Deterministic headless/recording backend capturing the settled input,
  audio, and presentation contracts (graphics resource metadata excluded).
- Aurora as one optional backend.

Game clients own title-specific policy:

- generated chunks and dispatch tables;
- DOL identity, symbols, and address maps;
- SDK/HLE replacement policy;
- middleware specialization not yet proven by a second title;
- diagnostics and scene automation.

Reference projects remain reference projects. Under the current repository
rules, GXRuntime may contain narrow shims for read-only Aurora limitations, but
those shims are not the stable graphics architecture. In a collaboration
end-state, Aurora should own retail FIFO decoding/resource resolution with an
external guest-memory resolver.

## Not complete yet

Before GXRuntime can be called a complete reusable runtime, at minimum:

- DolRecomp and GXRuntime need a jointly owned versioned generated-code ABI.
- DolRecomp/generated code must report deterministic guest work, preferably
  original instruction/cycle counts. The runtime now has event-clock and VI
  clock primitives, but Strikers still feeds them through a transitional
  one-work-unit-per-dispatch adapter.
- The MMIO bus and first PI/VI/SI/PE/DSP interrupt source model are tested,
  but broader device MMIO behavior and external-interrupt delivery still need
  generalized runtime APIs. The AI/DSP-AID audio device registers and a
  deterministic headless backend and SI register device are now in GXRuntime,
  but concrete DI command and EXI device payloads, the Aurora guest-memory
  resolver, and durable GX trace replay remain open.
- The graphics boundary is now specified as a Dolphin-grounded retail-GX front
  end feeding an Aurora render sink; see
  `graphics/frontend/ARCHITECTURE.md`. The renderer
  substrate is an owned hard fork vendored at `graphics/aurora/` (provenance in
  its `UPSTREAM.md`; the old bootstrap patch stack is retired), and the
  Dolphin-ported GX semantics modules land as first-class code in
  `graphics/gxcore/`.
- A second title must validate that the public boundary is not Strikers-shaped.

## Licensing status

GXRuntime currently contains code derived from DolRecomp's CPU support and
floating-point helper tables adapted from Dolphin Emulator
`Common/FloatUtils.cpp`.

Observed source facts:

- `DolRecomp/LICENSE` is GNU GPL version 3 text.
- Dolphin's copied floating-point helper material is marked
  `GPL-2.0-or-later`.
- `GXRuntime/src/core/cpu.c` preserves the Dolphin attribution on the adapted
  table.
- `graphics/aurora/` is a vendored hard fork of Aurora
  (`https://github.com/encounter/aurora`, fork point `0549581`), MIT-licensed;
  its `LICENSE` file is retained in the vendored tree.
- `graphics/gxcore/` contains GX semantics ported from
  Dolphin (`GPL-2.0-or-later`): the same GPL obligation already carried by the
  cpu.c tables extends to the graphics core. MIT (Aurora) is compatible with
  inclusion in a GPL-licensed whole.

Resolution: GXRuntime is licensed **GPL-3.0-or-later**. The repository-level
`LICENSE` file carries the GPLv3 text, source files carry
`SPDX-License-Identifier: GPL-3.0-or-later` headers (excluding the vendored
`graphics/aurora/` tree, which remains MIT with its notices retained), and
`THIRD_PARTY.md` records the provenance above.
