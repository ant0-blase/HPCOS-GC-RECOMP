// RecompCore: static-recomp per-game module ABI.
// SPDX-License-Identifier: GPL-2.0-or-later
//
// This header is the contract between the chassis and a per-game native module
// (g<GAMEID>_recomp.<dylib|so|dll>). It is C, so module glue code written in C
// can include it directly.
//
// The guest CPU state layout is DolRecomp's CPUState, vendored verbatim under
// dolrecomp/ (provenance: GXRuntime include/core/cpu.h, CPU ABI v2 with the
// tail `downcount` cycle-charge accumulator; originally @ 9a40e03). Both sides
// may alternatively define CPUState by including GXRuntime's original header;
// the shared DOLRECOMP_CPU_H include guard makes that safe. Layout drift is
// guarded at load time via cpu_abi_version + cpu_state_size.

#ifndef STATICRECOMP_ABI_H
#define STATICRECOMP_ABI_H

#include "core/cpu.h"


#ifdef __cplusplus
extern "C" {
#endif

#ifndef MODERNGEKKO_MODULE_ABI_H

/* 5: wants_fastmem + __fastmem_ex bounds. */
#define STATICRECOMP_ABI_VERSION 5u

typedef struct StaticRecompRange
{
  u32 start;  // guest effective address, inclusive
  u32 end;    // guest effective address, exclusive
} StaticRecompRange;

typedef struct StaticRecompRelSection
{
  u32 module_id;
  u32 section_index;
  u32 linked_start;
  u32 size;
} StaticRecompRelSection;

typedef struct StaticRecompRelModule
{
  u32 module_id;
  u32 version;
  u32 section_count;
  u32 section_info_offset;
  u32 file_size;
  const StaticRecompRelSection* sections;
  u32 num_sections;
} StaticRecompRelModule;

typedef struct StaticRecompModuleDesc
{
  u32 abi_version;      // must equal STATICRECOMP_ABI_VERSION
  u32 cpu_abi_version;  // must equal GXRUNTIME_CPU_ABI_VERSION
  u32 cpu_state_size;   // must equal sizeof(CPUState) on the chassis side
  char game_id[8];      // e.g. "G4QE01", NUL-terminated
  u32 entry_point;      // guest entry PC the module was generated for (informational)

  // Execute one recompiled segment starting at `address`. Returns 1 if the
  // address was covered and executed (ctx->pc now holds the next PC), 0 if the
  // address is not covered by this module.
  int (*dispatch)(CPUState* ctx, u32 address);

  // Called by the chassis after it loads fresh register state into ctx
  // (e.g. re-arms host FP rounding from ctx->fpscr). May be NULL.
  void (*on_state_loaded)(CPUState* ctx);

  // Guest address ranges covered by dispatch(). Sorted, non-overlapping.
  const StaticRecompRange* code_ranges;
  u32 num_code_ranges;

  // Known self-modifying-code sites (candidate patch instructions) enumerated
  // by the recompiler. Enforcement policy lives in the chassis.
  const StaticRecompRange* smc_ranges;
  u32 num_smc_ranges;

  // Recompiled translation units ("chunks"), sorted, non-overlapping, and
  // exactly tiling code_ranges, plus the FNV-1a 64 hash of each chunk's
  // original text bytes (ABI v2). The chassis verifies a chunk's guest RAM
  // against its hash before the first native dispatch into it and again
  // after any icache invalidation that touches it; a mismatch (real SMC)
  // retires the chunk to the interpreter until the next invalidation.
  const StaticRecompRange* chunk_ranges;
  u32 num_chunk_ranges;
  const u64* chunk_hashes;
  const StaticRecompRelModule* rel_modules;
  u32 num_rel_modules;

  // ABI v4: execute multiple chassis-approved native chunks per call.
  u32 (*dispatch_burst)(
      CPUState* ctx,
      u32 address,
      const u8* chain_state,
      u32 chain_state_count,
      u64 cycle_budget,
      u64 timebase_origin,
      u64 timebase_cycles_before,
      u32 timebase_ratio);

  // ABI v5: fastmem.
  //
  // Non-zero when the module indexes the chassis fastmem arena directly
  // instead of range-checking every guest access. Such a module dereferences
  // CPUState::fastmem_physical / fastmem_logical on its first access, so the
  // chassis must refuse to activate it when no arena exists.
  u32 wants_fastmem;

  // Half-open range of the module's __fastmem_ex section, empty when
  // wants_fastmem is 0. Each 8-byte entry holds two self-relative 32-bit
  // offsets: at entry address E, E + entry[0] is an instruction that may fault
  // on a guest access, and E + 4 + entry[1] is where execution must resume to
  // take the slow path instead. The chassis SIGSEGV handler looks the faulting
  // RIP up here and rewrites RIP, so nothing decodes instructions at run time.
  const void* fastmem_ex_start;
  const void* fastmem_ex_end;
} StaticRecompModuleDesc;

// The single symbol a module must export:
//   const StaticRecompModuleDesc* staticrecomp_get_module(void);
typedef const StaticRecompModuleDesc* (*StaticRecompGetModuleFn)(void);
#define STATICRECOMP_GET_MODULE_SYMBOL "staticrecomp_get_module"

#endif  // MODERNGEKKO_MODULE_ABI_H

#ifdef __cplusplus
}
#endif

#endif  // STATICRECOMP_ABI_H
