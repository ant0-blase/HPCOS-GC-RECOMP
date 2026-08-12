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
bool HandleFault(SContext* ctx);

// How many faults were recovered. Fastmem is only a win while this stays small
// relative to the number of guest memory accesses.
uint64_t RecoveredFaults();
}  // namespace StaticRecompFastmem
