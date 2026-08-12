#ifndef MODERNGEKKO_MODULE_ABI_H
#define MODERNGEKKO_MODULE_ABI_H

#include "moderngekko/cpu_state.h"

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* 5: wants_fastmem + __fastmem_ex bounds. */
#define MODERNGEKKO_MODULE_ABI_VERSION 5u
#define MODERNGEKKO_GET_MODULE_SYMBOL "staticrecomp_get_module"

#if defined(_WIN32)
#define MODERNGEKKO_MODULE_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define MODERNGEKKO_MODULE_EXPORT __attribute__((visibility("default")))
#else
#define MODERNGEKKO_MODULE_EXPORT
#endif

typedef struct ModernGekkoRange
{
    uint32_t start;
    uint32_t end;
} ModernGekkoRange;

typedef struct ModernGekkoRelSection
{
    uint32_t module_id;
    uint32_t section_index;
    uint32_t linked_start;
    uint32_t size;
} ModernGekkoRelSection;

typedef struct ModernGekkoRelModule
{
    uint32_t module_id;
    uint32_t version;
    uint32_t section_count;
    uint32_t section_info_offset;
    uint32_t file_size;
    const ModernGekkoRelSection* sections;
    uint32_t num_sections;
} ModernGekkoRelModule;

typedef struct ModernGekkoModuleDesc
{
    uint32_t abi_version;
    uint32_t cpu_abi_version;
    uint32_t cpu_state_size;
    char game_id[8];
    uint32_t entry_point;

    int (*dispatch)(CPUState* state, uint32_t address);
    void (*on_state_loaded)(CPUState* state);

    const ModernGekkoRange* code_ranges;
    uint32_t num_code_ranges;
    const ModernGekkoRange* smc_ranges;
    uint32_t num_smc_ranges;
    const ModernGekkoRange* chunk_ranges;
    uint32_t num_chunk_ranges;
    const uint64_t* chunk_hashes;
    const ModernGekkoRelModule* rel_modules;
    uint32_t num_rel_modules;

    /*
     * ABI v4 native burst dispatcher.
     *
     * Executes multiple already-verified native chunks before returning to
     * the chassis. chain_state is owned by the chassis:
     *   0 = return to chassis
     *   1 = safe to execute natively inside the burst
     *
     * The burst preserves the old per-dispatch downcount semantics internally
     * and returns the accumulated charge in state->downcount.
     */
    uint32_t (*dispatch_burst)(
        CPUState* state,
        uint32_t address,
        const uint8_t* chain_state,
        uint32_t chain_state_count,
        uint64_t cycle_budget,
        uint64_t timebase_origin,
        uint64_t timebase_cycles_before,
        uint32_t timebase_ratio);

    /*
     * ABI v5: fastmem.
     *
     * Non-zero when the module indexes the chassis fastmem arena directly
     * rather than range-checking every guest access. Such a module dereferences
     * CPUState::fastmem_physical / fastmem_logical on its first access, so the
     * chassis must refuse it when no arena exists.
     *
     * The pair below bounds the module's __fastmem_ex section, empty when
     * wants_fastmem is 0. Each 8-byte entry is two self-relative 32-bit
     * offsets: at entry address E, E + entry[0] is an instruction that may
     * fault on a guest access, and E + 4 + entry[1] is where execution resumes
     * to take the slow path. Recovery is a lookup, never instruction decoding.
     */
    uint32_t wants_fastmem;
    const void* fastmem_ex_start;
    const void* fastmem_ex_end;
} ModernGekkoModuleDesc;

typedef const ModernGekkoModuleDesc* (*ModernGekkoGetModuleFn)(void);

typedef ModernGekkoRange StaticRecompRange;
typedef ModernGekkoRelSection StaticRecompRelSection;
typedef ModernGekkoRelModule StaticRecompRelModule;
typedef ModernGekkoModuleDesc StaticRecompModuleDesc;
typedef ModernGekkoGetModuleFn StaticRecompGetModuleFn;

#define STATICRECOMP_ABI_VERSION MODERNGEKKO_MODULE_ABI_VERSION
#define STATICRECOMP_GET_MODULE_SYMBOL MODERNGEKKO_GET_MODULE_SYMBOL

#ifdef __cplusplus
}
#endif

#endif
