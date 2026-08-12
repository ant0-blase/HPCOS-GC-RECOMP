// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef DOLRECOMP_CPU_H
#define DOLRECOMP_CPU_H

#include "types.h"
#ifdef __cplusplus
extern "C" {
#endif
// more msvc shit fuck msvc
#if defined(_MSC_VER)
#define GXRUNTIME_ALWAYS_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#define GXRUNTIME_ALWAYS_INLINE inline __attribute__((always_inline))
#else
#define GXRUNTIME_ALWAYS_INLINE inline
#endif

// Minimal CPU support ABI for generated code and CPU tests.
//
// ABI status:
// - Fields up through `ram_size` intentionally mirror DolRecomp's current
//   generated-code CPUState contract.
// - GXRuntime extends that contract only at the tail with `external_pointer`,
//   used as a fast path for host-backed external memory such as locked cache.
// - Do not insert fields into the mirrored prefix without coordinating a
//   generated-code ABI bump with DolRecomp.
// - ABI v2 adds `downcount`: a guest-cycle charge accumulator.
//   Generated code subtracts each basic block's Gekko cycle cost (mirroring
//   Dolphin's PPCTables costs) at block entry; the embedding environment
//   consumes and resets it (Dolphin chassis: per-dispatch flush into
//   ppc_state.downcount). Hosts that do not meter guest time may ignore it
//   (s64: it cannot wrap in any realistic session).
// - ABI v4 adds persistent native cycle/guard budgets at the end of the
//   generated-code prefix, before host-specific SPR callbacks. They survive
//   MMIO and helper callbacks which materialize the local accumulator.
/* 5: added CPUState::fastmem_physical / fastmem_logical. */
#define GXRUNTIME_CPU_ABI_VERSION 5u
#define DOLRECOMP_CPU_ABI_VERSION GXRUNTIME_CPU_ABI_VERSION
#define GXRUNTIME_CPU_ABI_DOLRECOMP_PREFIX 1u
#define GXRUNTIME_CPU_ABI_EXTERNAL_POINTER_EXTENSION 1u

#define GC_MAIN_RAM_SIZE    (24 * 1024 * 1024)
#define GC_RAM_BASE         0x80000000u
#define GC_RAM_UNCACHED     0xC0000000u

#define PPC_EXC_PROGRAM        0x00000001u
#define PPC_EXC_DSI            0x00000002u
#define PPC_EXC_ALIGNMENT      0x00000004u
#define PPC_EXC_SYSTEM_CALL    0x00000008u
#define PPC_EXC_MACHINE_CHECK  0x00000010u
#define PPC_EXC_FP_UNAVAILABLE 0x00000020u

#define PPC_PROGRAM_FP        0x00100000u
#define PPC_PROGRAM_ILLEGAL   0x00080000u
#define PPC_PROGRAM_PRIV      0x00040000u
#define PPC_PROGRAM_TRAP      0x00020000u

#define PPC_DSI_EAR_DISABLED  0x00100000u

#define PPC_VECTOR_MACHINE_CHECK  0x00200u
#define PPC_VECTOR_DSI            0x00300u
#define PPC_VECTOR_ALIGNMENT      0x00600u
#define PPC_VECTOR_PROGRAM        0x00700u
#define PPC_VECTOR_FP_UNAVAILABLE 0x00800u
#define PPC_VECTOR_SYSTEM_CALL    0x00C00u

#define PPC_HID2_LSQE   0x80000000u
#define PPC_HID2_PSE    0x20000000u
#define PPC_HID2_LCE    0x10000000u
#define PPC_HID2_DCHERR 0x00800000u
#define PPC_HID2_DCHEE  0x00080000u

#define PPC_BIT(n) (1u << (31u - (n)))
#define PPC_MSR_RFI_MASK 0x87C0FFFFu
#define PPC_MSR_POW PPC_BIT(13)
#define PPC_MSR_ILE PPC_BIT(15)
#define PPC_MSR_EE  PPC_BIT(16)
#define PPC_MSR_PR  PPC_BIT(17)
#define PPC_MSR_FP  PPC_BIT(18)
#define PPC_MSR_ME  PPC_BIT(19)
#define PPC_MSR_FE0 PPC_BIT(20)
#define PPC_MSR_SE  PPC_BIT(21)
#define PPC_MSR_BE  PPC_BIT(22)
#define PPC_MSR_FE1 PPC_BIT(23)
#define PPC_MSR_IP  PPC_BIT(25)
#define PPC_MSR_IR  PPC_BIT(26)
#define PPC_MSR_DR  PPC_BIT(27)
#define PPC_MSR_PM  PPC_BIT(29)
#define PPC_MSR_RI  PPC_BIT(30)
#define PPC_MSR_LE  PPC_BIT(31)

#define PPC_EAR_ENABLE 0x80000000u
#define PPC_SRR1_MACHINE_CHECK_DCBZL PPC_BIT(10)

typedef struct CPUState CPUState;

typedef u64 (*PPCExternalRead)(CPUState* cpu, u32 ea, u8 size);
typedef void (*PPCExternalWrite)(CPUState* cpu, u32 ea, u64 value, u8 size);
typedef u32 (*PPCExternalRead32)(CPUState* cpu, u32 ea, u8 rid);
typedef void (*PPCExternalWrite32)(CPUState* cpu, u32 ea, u32 value, u8 rid);
typedef void* (*PPCExternalPointer)(CPUState* cpu, u32 ea, u32 size);
typedef void (*PPCInstructionFallback)(CPUState* cpu, u32 raw, u32 cia);
typedef bool (*PPCHostCall)(CPUState* cpu, u32 address);
typedef u32 (*PPCSPRRead)(CPUState* cpu, u16 spr, u32 cia);
typedef void (*PPCSPRWrite)(CPUState* cpu, u16 spr, u32 value, u32 cia);
typedef void (*PPCCacheControl)(CPUState* cpu, u8 operation, u32 ea, u32 cia);

enum {
    PPC_CACHE_DCBST,
    PPC_CACHE_DCBF,
    PPC_CACHE_DCBI,
    PPC_CACHE_ICBI,
};

struct CPUState {
    u32 gpr[32];
    f64 fpr[32];
    f64 ps1[32];
    u32 pc;
    u32 lr;
    u32 ctr;
    u32 cr;
    u32 xer;
    u32 fpscr;
    u32 msr;
    u32 srr0;
    u32 srr1;
    u32 dar;
    u32 dsisr;
    u32 ear;
    u32 hid2;
    u64 timebase;
    u32 sr[16];
    u32 gqr[8];
    u32 exception;
    u32 program_exception;
    u32 tlb_last_vps;
    u32 tlb_last_index;
    u32 tlb_invalidate_count;
    u32 external_addr;
    u32 external_value;
    u8 external_rid;
    u8 external_read_count;
    u8 external_write_count;
    u32 reserve_addr;
    bool reserve_valid;
    u32 locked_cache_tag[512];
    bool locked_cache_valid[512];
    PPCExternalRead external_read;
    PPCExternalWrite external_write;
    PPCExternalRead32 external_read32;
    PPCExternalWrite32 external_write32;
    PPCInstructionFallback instruction_fallback;
    PPCHostCall host_call;
    void* external_user_data;

    u8* ram;
    u32 ram_size;
    PPCExternalPointer external_pointer;
    s64 downcount;
    u8* exram;
    u32 exram_size;
    s64 native_cycle_budget;
    u32 native_guard_budget;
    PPCSPRRead spr_read;
    PPCSPRWrite spr_write;
    PPCCacheControl cache_control;
    /* See moderngekko/cpu_state.h: host views of the guest address space,
     * host = view + u32(guest_address), MSR.DR selecting which. NULL when
     * unavailable. */
    u8* fastmem_physical;
    u8* fastmem_logical;
};

#include <stdio.h>

/*
 * Lockstep RAM journal.
 *
 * Every guest store tests g_mem_write_journal, and the compiler cannot fold
 * that test away: ppc_set_mem_write_journal is marked visibility("default"),
 * so it looks externally callable even though module.exports demotes it with
 * `local: *` and the module ends up exporting staticrecomp_get_module alone.
 * The pointer is therefore unreachable from outside and permanently NULL,
 * while the load-test-branch is still paid on the hottest path in the port.
 *
 * Compiling the journal out removes that cost. The setter disappears with it,
 * so StaticRecompLockstepVerifier::Init fails its dlsym and disables lockstep
 * with its existing "module lacks ppc_set_mem_write_journal export" message —
 * loud, never a silently empty journal. Build with
 * -DGXRUNTIME_ENABLE_MEM_JOURNAL to get lockstep back.
 */
#if defined(GXRUNTIME_ENABLE_MEM_JOURNAL)
typedef void (*PPCMemWriteJournal)(u32 offset, u32 size, void* user);
extern PPCMemWriteJournal g_mem_write_journal;
extern void* g_mem_write_journal_user;
#define GXRUNTIME_JOURNAL_WRITE(off, sz)                                       \
    do {                                                                       \
        if (g_mem_write_journal && (off) != (u32)-1)                            \
            g_mem_write_journal((off), (sz), g_mem_write_journal_user);         \
    } while (0)
#else
#define GXRUNTIME_JOURNAL_WRITE(off, sz) ((void)(off))
#endif

#if defined(__clang__)
#define GXRUNTIME_ASSUME(cond) __builtin_assume(cond)
#elif defined(__GNUC__)
#define GXRUNTIME_ASSUME(cond)                                                 \
    do {                                                                       \
        if (!(cond))                                                           \
            __builtin_unreachable();                                            \
    } while (0)
#else
#define GXRUNTIME_ASSUME(cond) ((void)0)
#endif

static GXRUNTIME_ALWAYS_INLINE u8* get_ram_ptr(CPUState* cpu, u32 addr, u32 size, u32* out_offset) {
    const u32 masked_addr = addr & ~0x40000000u;

#if defined(GXRUNTIME_GAMECUBE_MEM1_ONLY)
    /*
     * GameCube retail fast path.
     *
     * MEM1 is fixed at 24 MiB. Non-MEM1 addresses return NULL and continue
     * through the existing external/MMIO path used by the memory helpers.
     *
     * Keeps generated code small and architecture-neutral:
     * i686, x86-64 and AArch64 all use the same C source.
     */
    const u32 offset = masked_addr - GC_RAM_BASE;

    if (offset <= GC_MAIN_RAM_SIZE - size) {
        if (out_offset)
            *out_offset = offset;
        /*
         * The bounds test above already decided this access is RAM, so the
         * NULL test the callers apply to the result is dead — but only the
         * chassis knows cpu->ram is populated, and it is in a different
         * translation unit. Stating it here lets the compiler drop a compare
         * and a branch from every guest load and store. StaticRecompCore_Run
         * refuses to attach a module when ram is null or not the 24 MiB
         * GameCube layout, which is what makes this safe to assert.
         */
        GXRUNTIME_ASSUME(cpu->ram != NULL);
        return cpu->ram + offset;
    }

    return NULL;
#else
    /*
     * Generic GC/Wii path.
     */
    if (cpu->exram) {
        const u32 offset = masked_addr - 0x90000000u;
        if (offset <= cpu->exram_size - size) {
            if (out_offset)
                *out_offset = (u32)-1;
            return cpu->exram + offset;
        }
    }

    const u32 offset = masked_addr - GC_RAM_BASE;
    if (offset <= cpu->ram_size - size) {
        if (out_offset)
            *out_offset = offset;
        return cpu->ram + offset;
    }

    return NULL;
#endif
}

/*
 * Reservation handling on plain stores.
 *
 * Dolphin only touches the reservation in lwarx (Interpreter_LoadStore.cpp
 * sets reserve/reserve_address) and in stwcx (tests and clears it). An ordinary
 * store never clears it there. This module used to be stricter than the
 * implementation it is lockstep-verified against, and paid a load, a compare
 * and two branches for it on every single guest store — roughly a third of the
 * whole fast path, on the 39% of guest instructions that touch memory.
 *
 * Matching Dolphin makes the two consistent. Real hardware would drop the
 * reservation on a same-block store, but the GameCube is single-processor and
 * lwarx/stwcx only appears in OS lock primitives, which never store into the
 * reserved line between the pair. Build with
 * -DGXRUNTIME_STORE_CLEARS_RESERVATION to restore the strict behaviour.
 */
#if defined(GXRUNTIME_STORE_CLEARS_RESERVATION)
static GXRUNTIME_ALWAYS_INLINE void clear_matching_reservation(CPUState* cpu, u32 addr) {
    u32 reserve_addr = cpu->reserve_addr & ~0x40000000u;
    u32 store_addr = addr & ~0x40000000u;
    if (cpu->reserve_valid && ((reserve_addr ^ store_addr) & ~31u) == 0)
        cpu->reserve_valid = false;
}
#else
static GXRUNTIME_ALWAYS_INLINE void clear_matching_reservation(CPUState* cpu, u32 addr) {
    (void)cpu;
    (void)addr;
}
#endif

/*
 * Fastmem accessors.
 *
 * host = cpu->fastmem_base + u32(guest_address), with the chassis arena laid
 * out like the guest memory map, so a guest access is one indexed instruction
 * and no range check at all. Guest pages that are not backed by host memory
 * (MMIO, unmapped) fault instead.
 *
 * Recovery uses an exception table rather than instruction emulation. Each
 * access records its own faulting address and a fixup address in the
 * __fastmem_ex section, exactly like the kernel's __ex_table: the SIGSEGV
 * handler looks the faulting RIP up and sets RIP to the fixup, which is the
 * ordinary external_read/external_write path. Nothing decodes instructions at
 * run time, and an unhandled access form cannot exist because these asm blocks
 * are the only thing that emits one.
 *
 * Entries are two self-relative 32-bit offsets so the section needs no
 * relocation processing at load time:
 *   entry[0] at address E  ->  faulting instruction at E + entry[0]
 *   entry[1] at address E+4 ->  fixup at E + 4 + entry[1]
 */
#if defined(GXRUNTIME_FASTMEM)

#define GXRUNTIME_FASTMEM_EX(fault_label, fixup_label)                         \
    ".pushsection __fastmem_ex,\"a\",@progbits\n"                              \
    ".balign 8\n"                                                              \
    ".long " fault_label " - .\n"                                              \
    ".long " fixup_label " - .\n"                                              \
    ".popsection\n"

/*
 * Hardware register space is pre-filtered instead of being left to fault.
 *
 * A signal costs thousands of cycles, so fastmem only pays when faults are
 * rare -- and they would not be: the game pushes every GX command word through
 * the write-gather pipe at 0xCC008000, so leaving MMIO unmapped would trade a
 * seven-instruction decode for a SIGSEGV per command word and land far behind
 * the JIT. Dolphin avoids this by backpatching its own emitted code, which is
 * not available to us over compiler-generated code.
 *
 * One unsigned compare separates the two worlds: everything at or above
 * 0xCC000000 (hardware registers, locked cache) takes the external path
 * directly, everything below reaches the arena with no range check at all.
 * Faults then only happen for genuinely unmapped guest pages, which are rare,
 * and the exception table catches those.
 */
#define GXRUNTIME_MMIO_FLOOR 0xCC000000u

/*
 * The arena base is a parameter, not a cpu->fastmem_base read, because the
 * "memory" clobber above forces a reload of anything living in memory after
 * every access. A chunk that loads it once into a local keeps it in a register
 * across the whole function -- the clobber invalidates memory, not registers --
 * which is what the JIT does with RMEM. Chunks declare that local in their
 * prologue; everything else keeps the ordinary bounds-checked helpers.
 */
/*
 * The slow paths are out-of-line and cold.
 *
 * Every access site carries one, and none of them ever run in a normal frame:
 * inlined, they interleave a null test, argument setup and an indirect call
 * with the hot code, and across ~186k sites that is over a megabyte of dead
 * instructions diluting the instruction cache. noinline+cold packs them into
 * .text.unlikely and leaves the fast paths dense.
 */
#if defined(__GNUC__) || defined(__clang__)
#define GXRUNTIME_COLD __attribute__((noinline, cold))
#else
#define GXRUNTIME_COLD
#endif

static GXRUNTIME_COLD void gxr_fastmem_slow_write(CPUState* cpu, u32 addr, u64 value, u8 size) {
    if (cpu->external_write)
        cpu->external_write(cpu, addr, value, size);
}

static GXRUNTIME_COLD u64 gxr_fastmem_slow_read(CPUState* cpu, u32 addr, u8 size) {
    return cpu->external_read ? cpu->external_read(cpu, addr, size) : 0u;
}

#define GXRUNTIME_FASTMEM_STORE(suffix, ctype, insn)                           \
    static GXRUNTIME_ALWAYS_INLINE void fastmem_write##suffix(                  \
        CPUState* cpu, u8* base, u32 addr, ctype value) {                       \
        if (addr >= GXRUNTIME_MMIO_FLOOR)                                       \
            goto slow;                                                          \
        asm goto("1: " insn " %[v], (%[b],%[o],1)\n"                            \
                 GXRUNTIME_FASTMEM_EX("1b", "%l[slow]")                         \
                 :                                                              \
                 : [v] "r"(value), [b] "r"(base), [o] "r"((u64)addr)            \
                 : "memory"                                                     \
                 : slow);                                                       \
        return;                                                                 \
    slow:                                                                       \
        gxr_fastmem_slow_write(cpu, addr, (u64)value, (u8)sizeof(ctype));       \
    }

#define GXRUNTIME_FASTMEM_LOAD(suffix, ctype, insn)                            \
    static GXRUNTIME_ALWAYS_INLINE ctype fastmem_read##suffix(                  \
        CPUState* cpu, u8* base, u32 addr) {                                    \
        ctype value;                                                            \
        if (addr >= GXRUNTIME_MMIO_FLOOR)                                       \
            goto slow;                                                          \
        asm goto("1: " insn " (%[b],%[o],1), %[v]\n"                            \
                 GXRUNTIME_FASTMEM_EX("1b", "%l[slow]")                         \
                 : [v] "=r"(value)                                              \
                 : [b] "r"(base), [o] "r"((u64)addr)                            \
                 : "memory"                                                     \
                 : slow);                                                       \
        return value;                                                           \
    slow:                                                                       \
        return (ctype)gxr_fastmem_slow_read(cpu, addr, (u8)sizeof(ctype));      \
    }

/* movbe supplies the big-endian swap for 16/32/64; single bytes need none. */
GXRUNTIME_FASTMEM_STORE(64, u64, "movbe")
GXRUNTIME_FASTMEM_STORE(32, u32, "movbe")
GXRUNTIME_FASTMEM_STORE(16, u16, "movbe")
GXRUNTIME_FASTMEM_STORE(8, u8, "movb")
GXRUNTIME_FASTMEM_LOAD(64, u64, "movbe")
GXRUNTIME_FASTMEM_LOAD(32, u32, "movbe")
GXRUNTIME_FASTMEM_LOAD(16, u16, "movbe")
GXRUNTIME_FASTMEM_LOAD(8, u8, "movb")

/* MSR[DR], PowerPC bit 27: address translation for data accesses. */
#define GXRUNTIME_MSR_DR 0x10u

#define GXRUNTIME_FASTMEM_SELECT(ctx)                                          \
    (((ctx)->msr & GXRUNTIME_MSR_DR) ? (ctx)->fastmem_logical                  \
                                     : (ctx)->fastmem_physical)

/*
 * Declared at the top of every generated chunk function, so the arena base
 * lives in a register for the whole function instead of being reloaded after
 * each access.
 *
 * Not const, and not selected once and forgotten: rfi leaves the chunk, but
 * mtmsr does not -- the emitter turns it into a plain ctx->msr assignment and
 * carries on -- so MSR[DR] can flip mid-function and swap which view is
 * correct. DolRecomp emits GXRUNTIME_FASTMEM_REFRESH right after every mtmsr.
 *
 * The redirection of mem_* onto the fastmem helpers is emitted by DolRecomp
 * into the generated translation units themselves, not here: cpu.c and
 * cpu_interpreter*.c are built with the same -DGXRUNTIME_FASTMEM and have no
 * such local, so they must keep seeing the bounds-checked helpers.
 */
#define GXRUNTIME_FASTMEM_PROLOGUE u8* gxr_fm_base = GXRUNTIME_FASTMEM_SELECT(ctx);
#define GXRUNTIME_FASTMEM_REFRESH gxr_fm_base = GXRUNTIME_FASTMEM_SELECT(ctx);

#else /* !GXRUNTIME_FASTMEM */

#define GXRUNTIME_FASTMEM_PROLOGUE
#define GXRUNTIME_FASTMEM_REFRESH

#endif /* GXRUNTIME_FASTMEM */

static GXRUNTIME_ALWAYS_INLINE u64 mem_read64(CPUState* cpu, u32 addr) {
    u8* ptr = get_ram_ptr(cpu, addr, 8, NULL);
    if (ptr == NULL) {
        if (cpu->external_read)
            return cpu->external_read(cpu, addr, 8);
        return 0;
    }
    return read_be64(ptr);
}

static GXRUNTIME_ALWAYS_INLINE void mem_write64(CPUState* cpu, u32 addr, u64 value) {
    u32 offset;
    u8* ptr = get_ram_ptr(cpu, addr, 8, &offset);
    if (ptr == NULL) {
        if (cpu->external_write) {
            cpu->external_write(cpu, addr, value, 8);
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    GXRUNTIME_JOURNAL_WRITE(offset, 8);
    write_be64(ptr, value);
}

static GXRUNTIME_ALWAYS_INLINE u32 mem_read32(CPUState* cpu, u32 addr) {
    u8* ptr = get_ram_ptr(cpu, addr, 4, NULL);
    if (ptr == NULL) {
        if (cpu->external_read)
            return (u32)cpu->external_read(cpu, addr, 4);
        return 0;
    }
    return read_be32(ptr);
}

static GXRUNTIME_ALWAYS_INLINE void mem_write32(CPUState* cpu, u32 addr, u32 value) {
    u32 offset;
    u8* ptr = get_ram_ptr(cpu, addr, 4, &offset);
    if (ptr == NULL) {
        if (cpu->external_write) {
            cpu->external_write(cpu, addr, value, 4);
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    GXRUNTIME_JOURNAL_WRITE(offset, 4);
    write_be32(ptr, value);
}

static GXRUNTIME_ALWAYS_INLINE u16 mem_read16(CPUState* cpu, u32 addr) {
    u8* ptr = get_ram_ptr(cpu, addr, 2, NULL);
    if (ptr == NULL) {
        if (cpu->external_read)
            return (u16)cpu->external_read(cpu, addr, 2);
        return 0;
    }
    return read_be16(ptr);
}

static GXRUNTIME_ALWAYS_INLINE void mem_write16(CPUState* cpu, u32 addr, u16 value) {
    u32 offset;
    u8* ptr = get_ram_ptr(cpu, addr, 2, &offset);
    if (ptr == NULL) {
        if (cpu->external_write) {
            cpu->external_write(cpu, addr, value, 2);
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    GXRUNTIME_JOURNAL_WRITE(offset, 2);
    write_be16(ptr, value);
}

static GXRUNTIME_ALWAYS_INLINE u8 mem_read8(CPUState* cpu, u32 addr) {
    u8* ptr = get_ram_ptr(cpu, addr, 1, NULL);
    if (ptr == NULL) {
        if (cpu->external_read)
            return (u8)cpu->external_read(cpu, addr, 1);
        return 0;
    }
    return *ptr;
}

static GXRUNTIME_ALWAYS_INLINE void mem_write8(CPUState* cpu, u32 addr, u8 value) {
    u32 offset;
    u8* ptr = get_ram_ptr(cpu, addr, 1, &offset);
    if (ptr == NULL) {
        if (cpu->external_write) {
            cpu->external_write(cpu, addr, value, 1);
        }
        return;
    }
    clear_matching_reservation(cpu, addr);
    GXRUNTIME_JOURNAL_WRITE(offset, 1);
    *ptr = value;
}

#undef GXRUNTIME_ALWAYS_INLINE

bool cpu_init(CPUState* cpu);
void cpu_free(CPUState* cpu);
void cpu_reset(CPUState* cpu);

f64 ppc_approx_reciprocal(f64 value);
f64 ppc_approx_rsqrt(f64 value);
bool ppc_fres(CPUState* cpu, f64 value, f64* result);
bool ppc_frsqrte(CPUState* cpu, f64 value, f64* result);
void ppc_ps_res(CPUState* cpu, f64 a, f64 b, f64* result_a, f64* result_b);
void ppc_ps_rsqrte(CPUState* cpu, f64 a, f64 b, f64* result_a, f64* result_b);
bool ppc_fma(CPUState* cpu, f64 a, f64 c, f64 b, bool single,
             bool subtract, bool negative, f64* output);
bool ppc_fctiw(CPUState* cpu, f64 value, bool toward_zero, u64* result);

/* Instruction-shaped FP unit mirroring Dolphin's interpreter bit-exactly
 * (Interpreter_FloatingPoint/Paired + Interpreter_FPUtils NI_* semantics:
 * PPC NaN propagation, Force25Bit frC rounding, single-precision Fill of
 * both PS lanes, FPSCR FPRF/FI/FR/exception updates, VE/ZE write gating).
 * Generated code calls these; the register indices select CPUState lanes. */
void ppc_fadds(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_fsubs(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_fmuls(CPUState* cpu, u8 d, u8 a, u8 c);
void ppc_fdivs(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_fadd(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_fsub(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_fmul(CPUState* cpu, u8 d, u8 a, u8 c);
void ppc_fdiv(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_fmadd_op(CPUState* cpu, u8 d, u8 a, u8 c, u8 b,
                  bool single, bool subtract, bool negative);
void ppc_frsp(CPUState* cpu, u8 d, u8 b);
void ppc_fres_op(CPUState* cpu, u8 d, u8 b);
void ppc_frsqrte_op(CPUState* cpu, u8 d, u8 b);
void ppc_fctiw_op(CPUState* cpu, u8 d, u8 b, bool toward_zero);
void ppc_fcmp(CPUState* cpu, u8 crfd, f64 a, f64 b, bool ordered);
void ppc_ps_add_op(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_ps_sub_op(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_ps_mul_op(CPUState* cpu, u8 d, u8 a, u8 c);
void ppc_ps_div_op(CPUState* cpu, u8 d, u8 a, u8 b);
void ppc_ps_madd_op(CPUState* cpu, u8 d, u8 a, u8 c, u8 b,
                    bool subtract, bool negative);
void ppc_ps_madds0(CPUState* cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_madds1(CPUState* cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_sum0(CPUState* cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_sum1(CPUState* cpu, u8 d, u8 a, u8 c, u8 b);
void ppc_ps_muls0(CPUState* cpu, u8 d, u8 a, u8 c);
void ppc_ps_muls1(CPUState* cpu, u8 d, u8 a, u8 c);
void ppc_ps_res_op(CPUState* cpu, u8 d, u8 b);
void ppc_ps_rsqrte_op(CPUState* cpu, u8 d, u8 b);
/* FP loads/stores with Dolphin's alignment exception + lfs/stfs ConvertTo*
 * bit repack. Return false when an exception was taken (callers skip the
 * update-form RA write-back). */
bool ppc_lfs_op(CPUState* cpu, u8 d, u32 ea, u32 cia);
bool ppc_lfd_op(CPUState* cpu, u8 d, u32 ea, u32 cia);
bool ppc_stfs_op(CPUState* cpu, u8 s, u32 ea, u32 cia);
bool ppc_stfd_op(CPUState* cpu, u8 s, u32 ea, u32 cia);
bool ppc_lwarx_op(CPUState* cpu, u8 d, u32 ea, u32 cia);
void ppc_stwcx_op(CPUState* cpu, u8 s, u32 ea, u32 cia);
/* stswi/stswx store-string: mirrors Dolphin's Helper_StoreString word-based
 * read-modify-write of the head/tail partial words. n = byte count, r =
 * first source GPR (wraps). */
void ppc_stsw(CPUState* cpu, u32 ea, u32 n, u8 r, u32 cia);
/* FPSCR control write (mtfsf/mtfsb/mtfsfi/mcrfs): recompute VX/FEX and re-arm
 * the host FPU rounding/flush mode from RN/NI (Dolphin FPSCRUpdated chain). */
void ppc_fpscr_control_updated(CPUState* cpu);
void ppc_mtfsb0_op(CPUState* cpu, u8 bit);
void ppc_mtfsb1_op(CPUState* cpu, u8 bit);
u32 ppc_mfspr(CPUState* cpu, u16 spr, u32 cia);
void ppc_mtspr(CPUState* cpu, u16 spr, u32 value, u32 cia);
void ppc_lswx(CPUState* cpu, u8 rD, u8 rA, u8 rB, u32 cia);
void ppc_cache_control(CPUState* cpu, u8 operation, u32 ea, u32 cia);

bool ppc_add_overflowed(u32 a, u32 b, u32 result);
bool ppc_trap_condition(u8 to, u32 a, u32 b);
void ppc_set_xer_ov(CPUState* cpu, bool ov);
void ppc_take_exception(CPUState* cpu, u32 exception, u32 vector, u32 srr0, u32 srr1_info);
void ppc_program_exception(CPUState* cpu, u32 cause, u32 cia);

/* Gekko lazy FP: generated FPU instructions call this first. Returns true
 * when MSR[FP] is set; otherwise raises the FP-unavailable exception (srr0 =
 * cia so the instruction retries after the OS restores the FP context) and
 * returns false. ppc_lazy_fp_set_enabled(false) restores the historical
 * execute-regardless behavior for hosts that eagerly restore FP state
 * themselves (StrikersRecomp standalone; see recomp-codegen.md Lazy FPU). */
bool ppc_fp_available(CPUState* cpu, u32 cia);
void ppc_lazy_fp_set_enabled(bool enabled);
void ppc_fallback_instruction(CPUState* cpu, u32 raw, u32 cia);
bool ppc_host_call(CPUState* cpu, u32 address);
void ppc_system_call_exception(CPUState* cpu, u32 cia);
void ppc_dsi_exception(CPUState* cpu, u32 ea, u32 cia, u32 dsisr);
void ppc_alignment_exception(CPUState* cpu, u32 ea, u32 cia);
u32 ppc_mftb(CPUState* cpu, u16 tbr, u32 cia);
void ppc_rfi(CPUState* cpu, u32 cia);
void ppc_dcbz_l(CPUState* cpu, u32 ea, u32 cia);
bool ppc_psq_load(CPUState* cpu, u8 frD, u32 ea, bool w, u8 gqr, bool indexed, u32 cia);
bool ppc_psq_store(CPUState* cpu, u8 frS, u32 ea, bool w, u8 gqr, bool indexed, u32 cia);
u32 ppc_eciwx(CPUState* cpu, u32 ea, u32 cia);
void ppc_ecowx(CPUState* cpu, u32 ea, u32 value, u32 cia);
void ppc_tlbie(CPUState* cpu, u32 ea, u32 cia);
void ppc_fpscr_updated(CPUState* cpu);
void ppc_memory_fence(void);

#ifdef __cplusplus
}
#endif

#endif /* DOLRECOMP_CPU_H */
