// Faithful VI-retrace external interrupt. See interrupt.h.
#include "host/interrupt.h"
#include "host/hle_offsets.h"
#include "host/audio.h"
#include "gxruntime/interrupts.h"
#include "gxruntime/si.h"
#include "gxruntime/vi_clock.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MSR_EE 0x00008000u  // MSR[EE], external interrupts enabled (bit 16)

// Guest globals / entry points.
#define EXC_EXTERNAL 4u                 // __OS_EXCEPTION_EXTERNAL_INTERRUPT

// OSContext field offsets (dolphin/os/OSContext.h).
#define CTX_CR 0x080u
#define CTX_LR 0x084u
#define CTX_CTR 0x088u
#define CTX_XER 0x08Cu
#define CTX_FPR 0x090u
#define CTX_FPSCR 0x194u
#define CTX_SRR0 0x198u
#define CTX_SRR1 0x19Cu
#define CTX_STATE 0x1A2u
#define CTX_GQR 0x1A4u
#define OS_CONTEXT_STATE_FPSAVED 0x0002u

// Dispatch iterations between simulated retraces. Aurora's present path is
// vsynced, so this cadence only needs to be large enough that normal frame work
// reaches GXCopyDisp before the next VI tick. The old 2,000,000-block cadence
// made the front end present at roughly 11 FPS on macOS.
#define DEFAULT_FRAME_BLOCKS 350000ull

// The Broadway/Gekko time base runs at one quarter of the 162 MHz bus clock.
// DolViClock advances it in lockstep with the simulated 60 Hz VI cadence so
// OSGetTick, task delta times, animations, and gameplay timers progress
// deterministically instead of depending on host wall-clock speed.
#define GC_TIMEBASE_HZ 40500000ull
#define VI_REFRESH_HZ 60ull

static DolInterrupts interrupts;
static DolSiDevice si;
static DolViClock vi_clock;
static u64 frame_work_units;

// Blocks between batched retrace/interrupt-delivery evaluations (see
// interrupt_poll). Accumulator of guest blocks since the last batched pass.
#define INTERRUPT_POLL_INTERVAL 128u
static u32 interrupt_poll_accum;

#define FPU_CONTEXT_CACHE_CAPACITY 32u
typedef struct {
    bool valid;
    u32 context;
    f64 fpr[32];
    f64 ps1[32];
    u32 fpscr;
} FpuContextCacheEntry;

static FpuContextCacheEntry fpu_context_cache[FPU_CONTEXT_CACHE_CAPACITY];
static u32 fpu_context_cache_next;
static bool fpu_context_cache_miss_reported;

static FpuContextCacheEntry* find_fpu_context(u32 context) {
    for (u32 i = 0; i < FPU_CONTEXT_CACHE_CAPACITY; ++i) {
        if (fpu_context_cache[i].valid &&
            fpu_context_cache[i].context == context)
            return &fpu_context_cache[i];
    }
    return NULL;
}

static void capture_fpu_context(const CPUState* cpu, u32 context) {
    FpuContextCacheEntry* entry = find_fpu_context(context);
    if (entry == NULL) {
        entry = &fpu_context_cache[fpu_context_cache_next];
        fpu_context_cache_next =
            (fpu_context_cache_next + 1u) % FPU_CONTEXT_CACHE_CAPACITY;
    }
    entry->valid = true;
    entry->context = context;
    memcpy(entry->fpr, cpu->fpr, sizeof entry->fpr);
    memcpy(entry->ps1, cpu->ps1, sizeof entry->ps1);
    entry->fpscr = cpu->fpscr;
}

void interrupt_restore_fpu_context(CPUState* cpu, u32 context) {
    const u32 context_size = CTX_GQR + 32u;
    if (cpu == NULL || context < GC_RAM_BASE ||
        context_size > cpu->ram_size ||
        context - GC_RAM_BASE > cpu->ram_size - context_size)
        return;

    FpuContextCacheEntry* entry = find_fpu_context(context);
    if (entry != NULL) {
        memcpy(cpu->fpr, entry->fpr, sizeof entry->fpr);
        memcpy(cpu->ps1, entry->ps1, sizeof entry->ps1);
        cpu->fpscr = entry->fpscr;
        entry->valid = false;
        return;
    }

    // Contexts that predate the cache can still restore scalar FPR state from
    // OSContext. The split ps1 lane has no representation in the guest ABI, so
    // leave it untouched and report once; normally every resumed context has
    // an exact cache entry from deliver_external().
    if ((mem_read16(cpu, context + CTX_STATE) &
         OS_CONTEXT_STATE_FPSAVED) == 0u)
        return;
    for (u32 i = 0; i < 32u; ++i) {
        u64 bits = mem_read64(cpu, context + CTX_FPR + i * 8u);
        memcpy(&cpu->fpr[i], &bits, sizeof bits);
    }
    cpu->fpscr = mem_read32(cpu, context + CTX_FPSCR);
    if (!fpu_context_cache_miss_reported) {
        fpu_context_cache_miss_reported = true;
        fprintf(stderr,
                "[interrupt] OSLoadContext restored scalar FPRs without an "
                "exact paired-single cache entry (context=0x%08X)\n",
                context);
    }
}

static void sync_audio_interrupt(void) {
    dol_interrupts_set_source(&interrupts, DOL_PI_CAUSE_DSP,
                              audio_interrupt_pending());
}

static void sync_si_interrupt(void) {
    dol_interrupts_set_source(&interrupts, DOL_PI_CAUSE_SI,
                              dol_si_interrupt_pending(&si));
}

void interrupt_init(void) {
    dol_interrupts_init(&interrupts);
    dol_si_init(&si);
    dol_vi_clock_init(&vi_clock);
    interrupt_poll_accum = 0;
    frame_work_units = DEFAULT_FRAME_BLOCKS;
    memset(fpu_context_cache, 0, sizeof fpu_context_cache);
    fpu_context_cache_next = 0;
    fpu_context_cache_miss_reported = false;
    const char* env = getenv("STRIKERS_FRAME_BLOCKS");
    if (env != NULL && env[0] != '\0') {
        char* end = NULL;
        unsigned long long value = strtoull(env, &end, 0);
        if (end != env && value != 0)
            frame_work_units = value;
    }
    dol_vi_clock_configure(&vi_clock, frame_work_units, (u32)VI_REFRESH_HZ,
                           GC_TIMEBASE_HZ);
    audio_set_vi_clock(frame_work_units, (u32)VI_REFRESH_HZ);
}

void interrupt_commit_pe_finish(void) {
    dol_interrupts_commit_pe_finish(&interrupts);
}

bool interrupt_mmio_contains(u32 ea) {
    return dol_interrupts_mmio_contains(ea) || dol_si_mmio_contains(ea);
}

u64 interrupt_mmio_read(u32 ea, u8 size) {
    sync_audio_interrupt();
    u64 value = dol_si_mmio_contains(ea)
                    ? dol_si_mmio_read(&si, ea, size)
                    : dol_interrupts_mmio_read(&interrupts, ea, size);
    sync_si_interrupt();
    return value;
}

void interrupt_mmio_write(u32 ea, u8 size, u64 value) {
    if (dol_si_mmio_contains(ea))
        dol_si_mmio_write(&si, ea, size, value);
    else
        dol_interrupts_mmio_write(&interrupts, ea, size, value);
    sync_audio_interrupt();
    sync_si_interrupt();
}

void interrupt_set_exi_pending(bool pending) {
    dol_interrupts_set_source(&interrupts, DOL_PI_CAUSE_EXI, pending);
}

void interrupt_set_di_pending(bool pending) {
    dol_interrupts_set_source(&interrupts, DOL_PI_CAUSE_DI, pending);
}

// Save the interrupted CPU state into the current OSContext and vector to the
// recompiled __OSDispatchInterrupt. It dispatches to the VI handler (which acks
// the VI DI register and wakes the retrace waiter), reschedules, and ends in
// OSLoadContext -> rfi, transferring control to the resumed thread.
static void deliver_external(CPUState* cpu) {
    u32 ctx = mem_read32(cpu, STRIKERS_OS_CONTEXT_POINTER);
    if (ctx < GC_RAM_BASE || ctx >= GC_RAM_BASE + cpu->ram_size)
        return;  // no current context established yet

    capture_fpu_context(cpu, ctx);
    for (int i = 0; i < 32; i++)
        mem_write32(cpu, ctx + (u32)i * 4u, cpu->gpr[i]);
    mem_write32(cpu, ctx + CTX_CR, cpu->cr);
    mem_write32(cpu, ctx + CTX_LR, cpu->lr);
    mem_write32(cpu, ctx + CTX_CTR, cpu->ctr);
    mem_write32(cpu, ctx + CTX_XER, cpu->xer);
    for (int i = 0; i < 32; i++) {
        u64 bits;
        memcpy(&bits, &cpu->fpr[i], sizeof bits);
        mem_write64(cpu, ctx + CTX_FPR + (u32)i * 8u, bits);
    }
    mem_write32(cpu, ctx + CTX_FPSCR, cpu->fpscr);
    mem_write32(cpu, ctx + CTX_SRR0, cpu->pc);
    mem_write32(cpu, ctx + CTX_SRR1, cpu->msr);
    mem_write16(cpu, ctx + CTX_STATE, OS_CONTEXT_STATE_FPSAVED);
    for (int i = 0; i < 8; i++)
        mem_write32(cpu, ctx + CTX_GQR + (u32)i * 4u, cpu->gqr[i]);

    cpu->gpr[3] = EXC_EXTERNAL;
    cpu->gpr[4] = ctx;
    cpu->srr0 = cpu->pc;
    cpu->srr1 = cpu->msr;
    cpu->msr &= ~MSR_EE;  // run the handler with external interrupts masked
    cpu->pc = STRIKERS_DISPATCH_INTERRUPT_ADDR;
}

// A VI retrace is one work unit in ~350,000, and external-interrupt delivery is
// level-triggered (a pending, unmasked source stays pending until the guest
// acks it). Neither needs to be evaluated on every single guest block. Batching
// the retrace clock + interrupt-delivery work every INTERRUPT_POLL_INTERVAL
// blocks keeps the per-block hot path down to just audio_poll (a counter
// increment that early-returns on all but every ~5250th call). The retrace
// timing error is bounded by INTERVAL/frame_work_units (~0.037% at 128/350000),
// far below one guest frame. Audio stays per-block because its chunk cadence is
// driven by audio_poll's own work counter, not by this batched clock.
#define INTERRUPT_POLL_INTERVAL 128u

static u32 interrupt_poll_accum;

void interrupt_poll(CPUState* cpu) {
    audio_poll(cpu);

    if (++interrupt_poll_accum < INTERRUPT_POLL_INTERVAL)
        return;
    const u64 units = interrupt_poll_accum;
    interrupt_poll_accum = 0;

    sync_audio_interrupt();
    // Transitional adapter: DolRecomp does not yet report real guest work, so
    // one generated-block dispatch advances one work unit. DolViClock owns the
    // periodic retrace schedule; replacing the feed with instruction/cycle
    // counts will not change this interrupt/device path.
    dol_vi_clock_advance(&vi_clock, units);
    u64 ticks = 0;
    while (dol_vi_clock_pop_retrace(&vi_clock, &ticks)) {
        cpu->timebase += ticks;
        dol_interrupts_assert_vi_retrace(&interrupts);
        dol_si_latch_poll(&si, 0xFu);
        sync_si_interrupt();
    }

    // Deliver only when the guest can take an external interrupt and at least one
    // pending source is unmasked in the PI. One delivery drains every pending,
    // unmasked source: __OSDispatchInterrupt loops over the PI cause bits.
    if (!(cpu->msr & MSR_EE))
        return;  // interrupts disabled; stay pending until the guest enables them
    if (!dol_interrupts_external_pending(&interrupts))
        return;  // no pending source is unmasked yet; wait

    deliver_external(cpu);
}
