// DolRecomp output
// cpu: gekko

#ifndef RECOMP_GENERATED_H
#define RECOMP_GENERATED_H

#define DOLRECOMP_CPU_GEKKO 1
#define DOLRECOMP_CPU_NAME "gekko"

#include <string.h>
#include <math.h>
#ifndef DOLRECOMP_CPU_HEADER
#define DOLRECOMP_CPU_HEADER "cpu/cpu.h"
#endif
#include DOLRECOMP_CPU_HEADER

#ifndef DOLRECOMP_C_LOOP_CYCLE_BUDGET
#define DOLRECOMP_C_LOOP_CYCLE_BUDGET 256
#endif

static inline u32 dolrecomp_rotl32(u32 value, u32 sh) {
    sh &= 31u;
    return sh ? ((value << sh) | (value >> (32u - sh))) : value;
}

static inline f32 dolrecomp_f32_from_bits(u32 bits) {
    f32 value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

static inline u32 dolrecomp_f32_to_bits(f32 value) {
    u32 bits;
    memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static inline f64 dolrecomp_f64_from_bits(u64 bits) {
    f64 value;
    memcpy(&value, &bits, sizeof(value));
    return value;
}

static inline u64 dolrecomp_f64_to_bits(f64 value) {
    u64 bits;
    memcpy(&bits, &value, sizeof(bits));
    return bits;
}

static inline f64 dolrecomp_ps_round(f64 value) {
    return (f64)(f32)value;
}

static inline f64 dolrecomp_ps_from_bits(u32 bits) {
    return (f64)dolrecomp_f32_from_bits(bits);
}

static inline u32 dolrecomp_ps_to_bits(f64 value) {
    return dolrecomp_f32_to_bits((f32)value);
}

#define DOLRECOMP_BACKEND_LLVM 1


// Function entry points
void func_80003100(CPUState* ctx);
void func_80003900(CPUState* ctx);

#define DOLRECOMP_ENTRY_POINT 0x80003100u

typedef void (*DolRecompFunction)(CPUState* ctx);

#if defined(__GNUC__) || defined(__clang__)
#define DOLRECOMP_UNUSED __attribute__((unused))
#else
#define DOLRECOMP_UNUSED
#endif

#if defined(DOLRECOMP_ENABLE_REPLACEMENTS)
int dolrecomp_dispatch_replacement(CPUState* ctx, u32 address);
#else
static inline int dolrecomp_dispatch_replacement(CPUState* ctx, u32 address) {
    (void)ctx;
    (void)address;
    return 0;
}
#endif

static inline DolRecompFunction dolrecomp_find_original(u32 address) {
    {
        u32 offset = address - 0x80003100u;
        if (offset < 0x00001000u && (offset & 3u) == 0u) {
            static const DolRecompFunction chunk_functions[] = {
                func_80003100,
                func_80003900,
            };
            return chunk_functions[offset / 0x00000800u];
        }
    }
    return NULL;
}

static inline int dolrecomp_call_original(CPUState* ctx, u32 address) {
    DolRecompFunction fn = dolrecomp_find_original(address);
    if (!fn) return 0;
    ctx->pc = address;
    fn(ctx);
    return 1;
}

static inline bool dolrecomp_physical_pc_alias(CPUState* ctx, u32 address, u32* alias_out) {
    if (address < ctx->ram_size) {
        *alias_out = address | GC_RAM_BASE;
        return *alias_out != address;
    }
    return false;
}

static inline int dolrecomp_call(CPUState* ctx, u32 address) {
    u32 alias;
    ctx->pc = address;
    if (dolrecomp_dispatch_replacement(ctx, address)) return 1;
    if (ctx->host_call && ppc_host_call(ctx, address)) return 1;
    if (dolrecomp_call_original(ctx, address)) return 1;
    if (dolrecomp_physical_pc_alias(ctx, address, &alias)) {
        ctx->pc = alias;
        if (dolrecomp_dispatch_replacement(ctx, alias)) return 1;
        if (ctx->host_call && ppc_host_call(ctx, alias)) return 1;
        if (dolrecomp_call_original(ctx, alias)) return 1;
    }
    return 0;
}

static inline DOLRECOMP_UNUSED int dolrecomp_run_blocks(CPUState* ctx, u32 max_blocks) {
    u32 blocks = 0;
    while (max_blocks == 0u || blocks < max_blocks) {
        if (!dolrecomp_call(ctx, ctx->pc)) return 0;
        if (ctx->exception) return 0;
        blocks++;
    }
    return 1;
}

#undef DOLRECOMP_UNUSED

#endif /* RECOMP_GENERATED_H */

// end
