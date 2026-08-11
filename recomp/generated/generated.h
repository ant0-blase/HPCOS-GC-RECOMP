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

static inline f64 dolrecomp_f32_from_bits(u32 bits) {
    u64 x = bits;
    u64 exp = (x >> 23) & 0xFFu;
    u64 frac = x & 0x007FFFFFu;
    u64 result;
    if (exp > 0 && exp < 255) {
        u64 y = !(exp >> 7);
        u64 z = (y << 61) | (y << 60) | (y << 59);
        result = ((x & 0xC0000000u) << 32) | z |
                 ((x & 0x3FFFFFFFu) << 29);
    } else if (exp == 0 && frac != 0) {
        exp = 1023 - 126;
        do {
            frac <<= 1;
            exp -= 1;
        } while ((frac & 0x00800000u) == 0);
        result = ((x & 0x80000000u) << 32) | (exp << 52) |
                 ((frac & 0x007FFFFFu) << 29);
    } else {
        u64 y = exp >> 7;
        u64 z = (y << 61) | (y << 60) | (y << 59);
        result = ((x & 0xC0000000u) << 32) | z |
                 ((x & 0x3FFFFFFFu) << 29);
    }
    f64 value;
    memcpy(&value, &result, sizeof(value));
    return value;
}

static inline u32 dolrecomp_f32_to_bits(f64 value) {
    u64 bits;
    memcpy(&bits, &value, sizeof(bits));
    u32 exp = (u32)((bits >> 52) & 0x7FFu);
    if (exp > 896 || (bits & 0x7FFFFFFFFFFFFFFFull) == 0) {
        return (u32)(((bits >> 32) & 0xC0000000u) |
                     ((bits >> 29) & 0x3FFFFFFFu));
    }
    if (exp >= 874) {
        u32 result =
            (u32)(0x80000000u | ((bits & 0x000FFFFFFFFFFFFFull) >> 21));
        result >>= 905 - exp;
        result |= (u32)((bits >> 32) & 0x80000000u);
        return result;
    }
    return (u32)(((bits >> 32) & 0xC0000000u) |
                 ((bits >> 29) & 0x3FFFFFFFu));
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

static inline f64 dolrecomp_ps_from_bits(u32 bits) {
    return dolrecomp_f32_from_bits(bits);
}

static inline u32 dolrecomp_ps_to_bits(f64 value) {
    return dolrecomp_f32_to_bits(value);
}


// Function entry points
void func_80003100(CPUState* ctx);
void func_800032C0(CPUState* ctx);
void func_800072C0(CPUState* ctx);
void func_8000B2C0(CPUState* ctx);
void func_8000F2C0(CPUState* ctx);
void func_800132C0(CPUState* ctx);
void func_800172C0(CPUState* ctx);
void func_8001B2C0(CPUState* ctx);
void func_8001F2C0(CPUState* ctx);
void func_800232C0(CPUState* ctx);
void func_800272C0(CPUState* ctx);
void func_8002B2C0(CPUState* ctx);
void func_8002F2C0(CPUState* ctx);
void func_800332C0(CPUState* ctx);
void func_800372C0(CPUState* ctx);
void func_8003B2C0(CPUState* ctx);
void func_8003F2C0(CPUState* ctx);
void func_800432C0(CPUState* ctx);
void func_800472C0(CPUState* ctx);
void func_8004B2C0(CPUState* ctx);
void func_8004F2C0(CPUState* ctx);
void func_800532C0(CPUState* ctx);
void func_800572C0(CPUState* ctx);
void func_8005B2C0(CPUState* ctx);
void func_8005F2C0(CPUState* ctx);
void func_800632C0(CPUState* ctx);
void func_800672C0(CPUState* ctx);
void func_8006B2C0(CPUState* ctx);
void func_8006F2C0(CPUState* ctx);
void func_800732C0(CPUState* ctx);
void func_800772C0(CPUState* ctx);
void func_8007B2C0(CPUState* ctx);
void func_8007F2C0(CPUState* ctx);
void func_800832C0(CPUState* ctx);
void func_800872C0(CPUState* ctx);
void func_8008B2C0(CPUState* ctx);
void func_8008F2C0(CPUState* ctx);
void func_800932C0(CPUState* ctx);
void func_800972C0(CPUState* ctx);
void func_8009B2C0(CPUState* ctx);
void func_8009F2C0(CPUState* ctx);
void func_800A32C0(CPUState* ctx);
void func_800A72C0(CPUState* ctx);
void func_800AB2C0(CPUState* ctx);
void func_800AF2C0(CPUState* ctx);
void func_800B32C0(CPUState* ctx);
void func_800B72C0(CPUState* ctx);
void func_800BB2C0(CPUState* ctx);
void func_800BF2C0(CPUState* ctx);
void func_800C32C0(CPUState* ctx);
void func_800C72C0(CPUState* ctx);
void func_800CB2C0(CPUState* ctx);
void func_800CF2C0(CPUState* ctx);
void func_800D32C0(CPUState* ctx);
void func_800D72C0(CPUState* ctx);
void func_800DB2C0(CPUState* ctx);
void func_800DF2C0(CPUState* ctx);
void func_800E32C0(CPUState* ctx);
void func_800E72C0(CPUState* ctx);
void func_800EB2C0(CPUState* ctx);
void func_800EF2C0(CPUState* ctx);
void func_800F32C0(CPUState* ctx);
void func_800F72C0(CPUState* ctx);
void func_800FB2C0(CPUState* ctx);
void func_800FF2C0(CPUState* ctx);
void func_801032C0(CPUState* ctx);
void func_801072C0(CPUState* ctx);
void func_8010B2C0(CPUState* ctx);
void func_8010F2C0(CPUState* ctx);
void func_801132C0(CPUState* ctx);
void func_801172C0(CPUState* ctx);
void func_8011B2C0(CPUState* ctx);
void func_8011F2C0(CPUState* ctx);
void func_801232C0(CPUState* ctx);
void func_801272C0(CPUState* ctx);
void func_8012B2C0(CPUState* ctx);
void func_8012F2C0(CPUState* ctx);
void func_801332C0(CPUState* ctx);
void func_801372C0(CPUState* ctx);
void func_8013B2C0(CPUState* ctx);
void func_8013F2C0(CPUState* ctx);
void func_801432C0(CPUState* ctx);
void func_801472C0(CPUState* ctx);
void func_8014B2C0(CPUState* ctx);
void func_8014F2C0(CPUState* ctx);
void func_801532C0(CPUState* ctx);
void func_801572C0(CPUState* ctx);
void func_8015B2C0(CPUState* ctx);
void func_8015F2C0(CPUState* ctx);
void func_801632C0(CPUState* ctx);
void func_801672C0(CPUState* ctx);
void func_8016B2C0(CPUState* ctx);
void func_8016F2C0(CPUState* ctx);
void func_801732C0(CPUState* ctx);
void func_801772C0(CPUState* ctx);
void func_8017B2C0(CPUState* ctx);
void func_8017F2C0(CPUState* ctx);
void func_801832C0(CPUState* ctx);
void func_801872C0(CPUState* ctx);
void func_8018B2C0(CPUState* ctx);
void func_8018F2C0(CPUState* ctx);
void func_801932C0(CPUState* ctx);
void func_801972C0(CPUState* ctx);
void func_8019B2C0(CPUState* ctx);
void func_8019F2C0(CPUState* ctx);
void func_801A32C0(CPUState* ctx);
void func_801A72C0(CPUState* ctx);
void func_801AB2C0(CPUState* ctx);
void func_801AF2C0(CPUState* ctx);
void func_801B32C0(CPUState* ctx);
void func_801B72C0(CPUState* ctx);
void func_801BB2C0(CPUState* ctx);
void func_801BF2C0(CPUState* ctx);
void func_801C32C0(CPUState* ctx);
void func_801C72C0(CPUState* ctx);
void func_801CB2C0(CPUState* ctx);
void func_801CF2C0(CPUState* ctx);
void func_801D32C0(CPUState* ctx);
void func_801D72C0(CPUState* ctx);

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
    if (address >= 0x80003100u && address < 0x800032C0u && ((address - 0x80003100u) & 3u) == 0u) return func_80003100;
    {
        u32 offset = address - 0x800032C0u;
        if (offset < 0x001D6520u && (offset & 3u) == 0u) {
            static const DolRecompFunction chunk_functions[] = {
                func_800032C0,
                func_800072C0,
                func_8000B2C0,
                func_8000F2C0,
                func_800132C0,
                func_800172C0,
                func_8001B2C0,
                func_8001F2C0,
                func_800232C0,
                func_800272C0,
                func_8002B2C0,
                func_8002F2C0,
                func_800332C0,
                func_800372C0,
                func_8003B2C0,
                func_8003F2C0,
                func_800432C0,
                func_800472C0,
                func_8004B2C0,
                func_8004F2C0,
                func_800532C0,
                func_800572C0,
                func_8005B2C0,
                func_8005F2C0,
                func_800632C0,
                func_800672C0,
                func_8006B2C0,
                func_8006F2C0,
                func_800732C0,
                func_800772C0,
                func_8007B2C0,
                func_8007F2C0,
                func_800832C0,
                func_800872C0,
                func_8008B2C0,
                func_8008F2C0,
                func_800932C0,
                func_800972C0,
                func_8009B2C0,
                func_8009F2C0,
                func_800A32C0,
                func_800A72C0,
                func_800AB2C0,
                func_800AF2C0,
                func_800B32C0,
                func_800B72C0,
                func_800BB2C0,
                func_800BF2C0,
                func_800C32C0,
                func_800C72C0,
                func_800CB2C0,
                func_800CF2C0,
                func_800D32C0,
                func_800D72C0,
                func_800DB2C0,
                func_800DF2C0,
                func_800E32C0,
                func_800E72C0,
                func_800EB2C0,
                func_800EF2C0,
                func_800F32C0,
                func_800F72C0,
                func_800FB2C0,
                func_800FF2C0,
                func_801032C0,
                func_801072C0,
                func_8010B2C0,
                func_8010F2C0,
                func_801132C0,
                func_801172C0,
                func_8011B2C0,
                func_8011F2C0,
                func_801232C0,
                func_801272C0,
                func_8012B2C0,
                func_8012F2C0,
                func_801332C0,
                func_801372C0,
                func_8013B2C0,
                func_8013F2C0,
                func_801432C0,
                func_801472C0,
                func_8014B2C0,
                func_8014F2C0,
                func_801532C0,
                func_801572C0,
                func_8015B2C0,
                func_8015F2C0,
                func_801632C0,
                func_801672C0,
                func_8016B2C0,
                func_8016F2C0,
                func_801732C0,
                func_801772C0,
                func_8017B2C0,
                func_8017F2C0,
                func_801832C0,
                func_801872C0,
                func_8018B2C0,
                func_8018F2C0,
                func_801932C0,
                func_801972C0,
                func_8019B2C0,
                func_8019F2C0,
                func_801A32C0,
                func_801A72C0,
                func_801AB2C0,
                func_801AF2C0,
                func_801B32C0,
                func_801B72C0,
                func_801BB2C0,
                func_801BF2C0,
                func_801C32C0,
                func_801C72C0,
                func_801CB2C0,
                func_801CF2C0,
                func_801D32C0,
                func_801D72C0,
            };
            return chunk_functions[offset / 0x00004000u];
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
