#ifndef STRIKERSRECOMP_MMIO_H
#define STRIKERSRECOMP_MMIO_H

#include "core/cpu.h"

// Hardware register access hooks. The GameCube maps its hardware (VI, GX/CP/PE,
// AI, DSP, DI/DVD, SI, EXI, PI) into the 0xCC00_xxxx range. Compiled game code
// reaches those addresses through CPUState::external_read / external_write
// because they fall outside the 24 MB of guest RAM.
//
// This is the scaffold: reads return 0 and writes are recorded but otherwise
// ignored. Real behavior is the job of the future Aurora HLE layer. Install the
// hooks with mmio_install().
bool mmio_install(CPUState* cpu);
void mmio_shutdown(void);

// Enable/disable per-access logging (off by default to keep boot output quiet).
void mmio_set_logging(bool enabled);
void mmio_set_disc_present(bool present);

// Translate a guest address backed by the runtime into a stable host pointer.
// `available` receives the contiguous byte count remaining in that region.
void* mmio_guest_pointer(CPUState* cpu, u32 address, u32* available);

// Copy raw guest bytes between host-backed regions, falling back to byte loads
// and stores when either side is not a single contiguous host pointer.
void mmio_guest_copy(CPUState* cpu, u32 dest, u32 src, u32 bytes);

#endif /* STRIKERSRECOMP_MMIO_H */
