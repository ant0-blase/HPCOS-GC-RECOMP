# Architecture

StrikersRecomp is the game integration: **DolRecomp's recompiled C**, G4QE01
symbols/addresses, game HLE policy, and diagnostics. The game-agnostic host is
the separate sibling repository [GXRuntime](../../GXRuntime).

Strikers links `GXRuntime::runtime` and, for GUI builds, `GXRuntime::aurora`.
Reusable PPC, memory, DOL/boot, disc, and platform behavior belongs there.

## 1. The block-dispatch model

DolRecomp splits each text section into fixed ~16 KB blocks and emits one C
function per block:

```c
void func_80005240(CPUState* ctx) {
    switch (ctx->pc) {           // enter at any instruction in the block
    case 0x80005240u: goto label_80005240;
    ...
    }
label_80005240:
    ctx->pc = 0x80005240u;
    /* translated instruction */
    ...
}
```

- **Intra-block branches** become `goto label_XXXXXXXX`.
- **Calls, returns, out-of-block branches** set `ctx->pc` and `return`.

The generated header supplies `dolrecomp_call()`, which calls `ppc_host_call()`
first (the HLE hook) and otherwise routes the address to its block function.
`runtime/host/main.c` runs the loop and stops on an unmapped `pc`, a CPU
exception, or the `--max-blocks` watchdog.

## 2. Memory

GXRuntime's `cpu_init` allocates 24 MB into `CPUState::ram`.
`mem_read*/mem_write*` map the
cached (`0x8000_0000`) and uncached (`0xC000_0000`) windows into it; anything
outside RAM is routed to the `external_read`/`external_write` hooks.

| Region | Handling |
|--------|----------|
| `0x8000_0000`–`0x817F_FFFF` | guest RAM (DOL sections + BSS + heap + stack) |
| `0xC000_0000`+ | uncached alias of RAM |
| `0xCC00_xxxx` | hardware MMIO → `runtime/host/mmio.c` |

## 3. Boot

`GXRuntime/src/loader.c` parses the DOL header (7 text + 11 data sections),
copies each section to `address - 0x8000_0000`, and zeroes the BSS.
`GXRuntime/src/boot.c` writes the GameCube low-memory OS globals (physical memory
size, bus/core clocks, console type, arena bounds) and an initial stack pointer.
`main.c` then sets `pc` to the DOL entry point (`0x80005240` for Strikers) and
starts the dispatcher.

## 4. The game/runtime boundary and symbol map

The current migration boundary is explicit:

- **GXRuntime** — PPC core, DOL/boot, ARAM, DVD image service, VM/locked-cache
  backing, and the Aurora graphics/input/audio adapter.
- **`runtime/host/mmio.c`** — temporary Strikers device router over GXRuntime
  memory plus the not-yet-extracted audio/interrupt devices.
- **`runtime/host/hle.c`** — G4QE01 host-call replacements/notifications. A
  `true` return skips the recompiled function and produces the game-visible
  effect.
- **`instruction_fallback`** — only for untranslated opcodes; Strikers has none.

The checked-out `smstrikers-decomp/config/G4QE01/symbols.txt` supplies the SDK
and game symbol map used to generate `generated/sdk_symbols.inc`. Exact guest
addresses remain in Strikers; they are never compiled into GXRuntime.

1. **Signature matching (FLIRT-style):** retail GameCube games are built with
   known Metrowerks CodeWarrior + Nintendo SDK archives. Build a signature
   database from those public `.a` libraries and match it against the decoded
   functions to label SDK code. This is decomp-independent and how decomp
   tooling (`dtk`/`ppcdis`) auto-labels library functions.
2. **String/anchor heuristics:** SDK functions reference known strings (OSReport
   formats, assertion `__FILE__` text); cross-referencing pins them down.
3. **Behavioral anchors:** a function writing the GX FIFO at `0xCC00_8000` is
   GX-side, etc.

The output is an address→function table that feeds `hle.c`.

## 5. Self-modifying code (SMC)

DolRecomp flags address ranges in Strikers as possible runtime patches of
executable memory (listed in `generated/generated_smc.txt`). The translated code
is emitted normally; genuine runtime rewrites would be fixed with a DolRecomp
patch in [`../patches/`](../patches) (none needed so far).
