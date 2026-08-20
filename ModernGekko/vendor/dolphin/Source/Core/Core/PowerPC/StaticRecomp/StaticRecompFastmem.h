// RecompCore: StaticRecomp fastmem fault recovery.
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include <cstdint>

#include "Core/MachineContext.h"

// A module built with GXRUNTIME_FASTMEM reaches guest memory by indexing the
// chassis arena with no range check, so an access to a guest page that has no
// host backing traps instead of being rejected. Recovery is a table lookup, not
// instruction emulation: each such access emitted an entry into the module's
// __fastmem_ex section pairing the faulting instruction with the address of its
// slow path, so the handler only has to move RIP.
namespace StaticRecompFastmem
{
// Takes the module's __fastmem_ex bounds and builds the lookup table. Safe to
// call with an empty range; that simply disables recovery.
bool Register(const void* section_start, const void* section_end);
void Unregister();

// Called from the SIGSEGV handler. Returns true when the faulting PC was one of
// ours and the context has been redirected to the slow path.
bool HandleFault(uintptr_t fault_address, SContext* ctx);

// Arena bases, so a recovered fault can be reported as the guest address the
// game actually used rather than a raw host pointer.
void SetArenaBases(const void* physical, const void* logical);

// Guest addresses that faulted most, worst first. Fastmem only pays while
// these stay rare, so naming them is what turns "it is slow" into a fix.
void ReportHotFaults(int max_rows);

// How many faults were recovered. Fastmem is only a win while this stays small
// relative to the number of guest memory accesses.
uint64_t RecoveredFaults();
}  // namespace StaticRecompFastmem
