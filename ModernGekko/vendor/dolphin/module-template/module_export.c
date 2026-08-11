// RecompCore per-game native module export glue (game id set at build time).
//
// Wraps the DolRecomp-generated constant-time chunk dispatcher behind the
// StaticRecomp module ABI. All environment access goes through the CPUState
// hook pointers the chassis installs; this dylib has no host dependencies.

#include "generated.h"

#include "StaticRecompABI.h"

static int chassis_dispatch(CPUState* ctx, u32 address)
{
    return dolrecomp_call(ctx, address);
}

static void chassis_on_state_loaded(CPUState* ctx)
{
    // Re-arm host FP rounding/flush state from the freshly loaded guest FPSCR.
    ppc_fpscr_updated(ctx);
}

#include "module_tables.inc"

/*
 * Fast guest-PC -> module chunk index.
 *
 * Most DolRecomp DOL layouts consist of a tiny first text chunk followed by
 * one large uniform run. The arithmetic path is therefore the common case.
 * The binary-search fallback keeps this generic for irregular modules.
 */
static inline int chassis_chunk_index(u32 address)
{
    const u32 count = MODULE_CHUNK_RANGE_COUNT;

    if (count == 0u)
        return -1;

    if (count >= 3u)
    {
        const u32 base = s_chunk_ranges[1].start;
        const u32 stride = s_chunk_ranges[2].start - base;

        if (stride != 0u &&
            (stride & (stride - 1u)) == 0u &&
            address >= base)
        {
            const u32 candidate = 1u + ((address - base) / stride);

            if (candidate < count)
            {
                const StaticRecompRange* range = &s_chunk_ranges[candidate];

                if (address >= range->start && address < range->end)
                    return (int)candidate;
            }
        }
    }

    if (address >= s_chunk_ranges[0].start &&
        address < s_chunk_ranges[0].end)
    {
        return 0;
    }

    u32 lo = 1u;
    u32 hi = count;

    while (lo < hi)
    {
        const u32 mid = lo + (hi - lo) / 2u;
        const StaticRecompRange* range = &s_chunk_ranges[mid];

        if (address < range->start)
            hi = mid;
        else if (address >= range->end)
            lo = mid + 1u;
        else
            return (int)mid;
    }

    return -1;
}

/*
 * Native cross-chunk burst.
 *
 * Important correctness detail:
 * each generated chunk still starts with downcount == 0 exactly like the old
 * chassis loop. We accumulate each segment's charge locally, then expose the
 * total back to StaticRecompCore when the burst finishes.
 *
 * This preserves generated-code loop thresholds while amortizing the expensive
 * module -> C++ runtime -> module transition.
 */
static u32 chassis_dispatch_burst(
    CPUState* ctx,
    u32 address,
    const u8* chain_state,
    u32 chain_state_count,
    u64 cycle_budget,
    u64 timebase_origin,
    u64 timebase_cycles_before,
    u32 timebase_ratio)
{
    if (!chain_state || chain_state_count == 0u || cycle_budget == 0u)
        return 0u;

    u32 blocks = 0u;
    u64 total_cycles = 0u;

    ctx->pc = address;

    /*
     * Hard cap prevents pathological zero-cost control-flow from staying in
     * the module forever. Normal exit is the guest cycle budget.
     */
    while (blocks < 64u && total_cycles < cycle_budget)
    {
#if defined(DOLRECOMP_HAS_INDEXED_LOOKUP)

        /*
         * Native Burst v2.
         *
         * generated.h resolves BOTH the native function and the
         * module chunk index in one arithmetic lookup.
         */
        const u32 pc = ctx->pc;
        u32 chunk_index = 0xFFFFFFFFu;

        DolRecompFunction fn =
            dolrecomp_find_original_indexed(
                pc, &chunk_index);

        if (!fn ||
            chunk_index >= chain_state_count ||
            chain_state[chunk_index] == 0u)
        {
            break;
        }

        ctx->downcount = 0;
        ctx->pc = pc;

        fn(ctx);

#else

        const u32 pc = ctx->pc;
        const int chunk_index = chassis_chunk_index(pc);

        if (chunk_index < 0 ||
            (u32)chunk_index >= chain_state_count ||
            chain_state[chunk_index] == 0u)
        {
            break;
        }

        /*
         * Keep the exact old per-dispatch generated-code contract:
         * every segment receives a fresh local downcount accumulator.
         */
        ctx->downcount = 0;

        int handled = dolrecomp_dispatch_replacement(ctx, pc);

        if (!handled)
        {
            DolRecompFunction fn = dolrecomp_find_original(pc);

            if (!fn)
                break;

            ctx->pc = pc;
            fn(ctx);
            handled = 1;
        }

        if (!handled)
            break;

#endif

        const s64 raw_charge = -ctx->downcount;
        const u64 charge = raw_charge > 0 ? (u64)raw_charge : 1u;

        total_cycles += charge;
        ++blocks;

        /*
         * Generated guest code may read the emulated timebase. Keep it moving
         * between chained chunks exactly like the previous C++ dispatch loop.
         */
        if (timebase_ratio != 0u)
        {
            ctx->timebase =
                timebase_origin +
                (timebase_cycles_before + total_cycles) / timebase_ratio;
        }

        ctx->downcount = 0;

        if (ctx->exception)
            break;
    }

    ctx->downcount = -(s64)total_cycles;
    return blocks;
}

static const StaticRecompModuleDesc s_desc = {
    STATICRECOMP_ABI_VERSION,
    GXRUNTIME_CPU_ABI_VERSION,
    (u32)sizeof(CPUState),
    MODULE_GAME_ID,
    DOLRECOMP_ENTRY_POINT,
    chassis_dispatch,
    chassis_on_state_loaded,
    s_code_ranges,
    MODULE_CODE_RANGE_COUNT,
    s_smc_ranges,
    MODULE_SMC_RANGE_COUNT,
    s_chunk_ranges,
    MODULE_CHUNK_RANGE_COUNT,
    s_chunk_hashes,
    0,
    0,
    chassis_dispatch_burst,
};

#if defined(_WIN32)
#define RECOMP_MODULE_EXPORT __declspec(dllexport)
#elif defined(__GNUC__) || defined(__clang__)
#define RECOMP_MODULE_EXPORT __attribute__((visibility("default")))
#else
#define RECOMP_MODULE_EXPORT
#endif

RECOMP_MODULE_EXPORT const StaticRecompModuleDesc* staticrecomp_get_module(void)
{
    return &s_desc;
}
