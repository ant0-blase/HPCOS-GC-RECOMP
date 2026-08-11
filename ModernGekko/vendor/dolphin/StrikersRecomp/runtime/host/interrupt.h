#ifndef STRIKERSRECOMP_HOST_INTERRUPT_H
#define STRIKERSRECOMP_HOST_INTERRUPT_H

#include "core/cpu.h"

// Faithful external-interrupt delivery for the VI vertical retrace.
//
// The GameCube drives its frame loop from the VI retrace interrupt: the main
// thread blocks in VIWaitForRetrace, and once per frame the VI raises an
// interrupt whose handler wakes it. We model the Processor Interface (PI) and
// the VI display-interrupt registers, and deliver the interrupt by saving the
// interrupted state into the current OSContext and jumping to the recompiled
// __OSDispatchInterrupt -- bypassing the asm vector stub the SDK relocates to
// low memory (which the recompiler has no block for).

void interrupt_init(void);

// MMIO delegation for the runtime-owned PI/VI/PE interrupt and SI device models.
bool interrupt_mmio_contains(u32 ea);
u64  interrupt_mmio_read(u32 ea, u8 size);
void interrupt_mmio_write(u32 ea, u8 size, u64 value);
void interrupt_set_exi_pending(bool pending);
void interrupt_set_di_pending(bool pending);

// Restore the exact host-side floating state captured when an OSContext was
// interrupted. OSLoadContext relies on the hardware FP-unavailable exception
// for lazy FPU restoration; this bridge supplies that behavior until generated
// FP instructions model MSR[FP] and the exception path directly.
void interrupt_restore_fpu_context(CPUState* cpu, u32 context);

// Called once per current generated-dispatch work unit. Advances the runtime
// VI clock; when a retrace is due and external interrupts are enabled and
// unmasked, delivers the VI interrupt to the guest.
void interrupt_poll(CPUState* cpu);

// Commit a Pixel Engine "finish" interrupt (PI cause bit 10). Called when a
// thread blocks in GXWaitDrawDone (sleeps on FinishQueue), which only happens
// while a draw-done token is in flight (DrawDone == 0). Committing on the wait
// itself is the faithful trigger and -- unlike arming on the standalone
// GXSetDrawDone -- also covers the inlined GXDrawDone() path (it never calls the
// standalone GXSetDrawDone, so the loading screen used to hang here forever).
void interrupt_commit_pe_finish(void);

#endif // STRIKERSRECOMP_HOST_INTERRUPT_H
