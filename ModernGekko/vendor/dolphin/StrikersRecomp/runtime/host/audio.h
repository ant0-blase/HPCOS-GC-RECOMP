#ifndef STRIKERSRECOMP_HOST_AUDIO_H
#define STRIKERSRECOMP_HOST_AUDIO_H

#include "core/cpu.h"

// Host model of the GameCube DSP audio-DMA interrupt and the MusyX/AX DSP
// command processor. The original game continues to run all CPU-side MusyX
// sequencing, voice allocation, streaming, and effect callbacks. This module
// replaces only the hardware DSP mixer and forwards AI-DMA stereo output at
// the guest-selected AID rate to the platform backend.

void audio_init(void);
void audio_shutdown(void);
void audio_set_vi_clock(u64 work_units_per_frame, u32 refresh_hz);

bool audio_mmio_contains(u32 address);
u64  audio_mmio_read(u32 address, u8 size);
void audio_mmio_write(u32 address, u8 size, u64 value);

// Called once per current generated-dispatch work unit. Consumes 32-byte AI DMA
// chunks at the guest-selected AID cadence and delivers AID through the normal
// PI/external interrupt path.
void audio_poll(CPUState* cpu);
bool audio_interrupt_pending(void);

// Observe a CPU-to-DSP mailbox send. MusyX sends a BABE-prefixed command-list
// size followed by the command-list address; the second mail runs the host AX
// mixer synchronously and marks the DSP work complete.
void audio_dsp_mail(CPUState* cpu, u32 mail);

// salInitDsp is replaced at the HLE boundary because no physical DSP task is
// booted. This initializes the guest-visible completion state expected by the
// rest of MusyX.
void audio_skip_dsp_init(CPUState* cpu);

#endif // STRIKERSRECOMP_HOST_AUDIO_H
