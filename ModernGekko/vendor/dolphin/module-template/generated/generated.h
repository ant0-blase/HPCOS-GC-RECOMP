// DolRecomp output
// cpu: gekko

#ifndef RECOMP_GENERATED_H
#define RECOMP_GENERATED_H

#define DOLRECOMP_CPU_GEKKO 1
#define DOLRECOMP_CPU_NAME "gekko"

#include <string.h>
#include <math.h>
#include "core/cpu.h"

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


// Function entry points
void func_80003400(CPUState* ctx);
void func_8132FFE0(CPUState* ctx);
void func_81333FE0(CPUState* ctx);
void func_81337FE0(CPUState* ctx);
void func_8133BFE0(CPUState* ctx);
void func_8133FFE0(CPUState* ctx);
void func_81343FE0(CPUState* ctx);
void func_81347FE0(CPUState* ctx);
void func_8134BFE0(CPUState* ctx);
void func_8134FFE0(CPUState* ctx);
void func_81353FE0(CPUState* ctx);
void func_81357FE0(CPUState* ctx);
void func_8135BFE0(CPUState* ctx);
void func_8135FFE0(CPUState* ctx);
void func_81363FE0(CPUState* ctx);
void func_81367FE0(CPUState* ctx);
void func_8136BFE0(CPUState* ctx);
void func_8136FFE0(CPUState* ctx);
void func_81373FE0(CPUState* ctx);
void func_81377FE0(CPUState* ctx);
void func_8137BFE0(CPUState* ctx);
void func_8137FFE0(CPUState* ctx);
void func_81383FE0(CPUState* ctx);
void func_81387FE0(CPUState* ctx);
void func_8138BFE0(CPUState* ctx);
void func_8138FFE0(CPUState* ctx);
void func_81393FE0(CPUState* ctx);
void func_81397FE0(CPUState* ctx);
void func_8139BFE0(CPUState* ctx);
void func_8139FFE0(CPUState* ctx);
void func_813A3FE0(CPUState* ctx);
void func_813A7FE0(CPUState* ctx);
void func_813ABFE0(CPUState* ctx);
void func_813AFFE0(CPUState* ctx);
void func_813B3FE0(CPUState* ctx);
void func_813B7FE0(CPUState* ctx);
void func_813BBFE0(CPUState* ctx);
void func_813BFFE0(CPUState* ctx);
void func_813C3FE0(CPUState* ctx);
void func_813C7FE0(CPUState* ctx);
void func_813CBFE0(CPUState* ctx);
void func_813CFFE0(CPUState* ctx);
void func_813D3FE0(CPUState* ctx);
void func_813D7FE0(CPUState* ctx);
void func_813DBFE0(CPUState* ctx);
void func_813DFFE0(CPUState* ctx);
void func_813E3FE0(CPUState* ctx);
void func_813E7FE0(CPUState* ctx);
void func_813EBFE0(CPUState* ctx);
void func_813EFFE0(CPUState* ctx);
void func_813F3FE0(CPUState* ctx);
void func_813F7FE0(CPUState* ctx);
void func_813FBFE0(CPUState* ctx);
void func_813FFFE0(CPUState* ctx);
void func_81403FE0(CPUState* ctx);
void func_81407FE0(CPUState* ctx);
void func_8140BFE0(CPUState* ctx);
void func_8140FFE0(CPUState* ctx);
void func_81413FE0(CPUState* ctx);
void func_81417FE0(CPUState* ctx);
void func_8141BFE0(CPUState* ctx);
void func_8141FFE0(CPUState* ctx);
void func_81423FE0(CPUState* ctx);
void func_81427FE0(CPUState* ctx);
void func_8142BFE0(CPUState* ctx);
void func_8142FFE0(CPUState* ctx);
void func_81433FE0(CPUState* ctx);
void func_81437FE0(CPUState* ctx);
void func_8143BFE0(CPUState* ctx);
void func_8143FFE0(CPUState* ctx);
void func_81443FE0(CPUState* ctx);
void func_81447FE0(CPUState* ctx);
void func_8144BFE0(CPUState* ctx);
void func_8144FFE0(CPUState* ctx);
void func_81453FE0(CPUState* ctx);
void func_81457FE0(CPUState* ctx);
void func_8145BFE0(CPUState* ctx);
void func_8145FFE0(CPUState* ctx);
void func_81463FE0(CPUState* ctx);
void func_81467FE0(CPUState* ctx);
void func_8146BFE0(CPUState* ctx);
void func_8146FFE0(CPUState* ctx);
void func_81473FE0(CPUState* ctx);
void func_81477FE0(CPUState* ctx);
void func_8147BFE0(CPUState* ctx);
void func_8147FFE0(CPUState* ctx);
void func_81483FE0(CPUState* ctx);
void func_81487FE0(CPUState* ctx);
void func_8148BFE0(CPUState* ctx);
void func_8148FFE0(CPUState* ctx);
void func_81493FE0(CPUState* ctx);
void func_81497FE0(CPUState* ctx);
void func_8149BFE0(CPUState* ctx);
void func_8149FFE0(CPUState* ctx);
void func_814A3FE0(CPUState* ctx);
void func_814A7FE0(CPUState* ctx);
void func_814ABFE0(CPUState* ctx);
void func_814AFFE0(CPUState* ctx);
void func_814B3FE0(CPUState* ctx);
void func_814B7FE0(CPUState* ctx);
void func_814BBFE0(CPUState* ctx);
void func_814BFFE0(CPUState* ctx);
void func_814C3FE0(CPUState* ctx);
void func_814C7FE0(CPUState* ctx);
void func_814CBFE0(CPUState* ctx);
void func_814CFFE0(CPUState* ctx);
void func_814D3FE0(CPUState* ctx);
void func_814D7FE0(CPUState* ctx);
void func_814DBFE0(CPUState* ctx);
void func_814DFFE0(CPUState* ctx);
void func_814E3FE0(CPUState* ctx);
void func_814E7FE0(CPUState* ctx);
void func_814EBFE0(CPUState* ctx);
void func_814EFFE0(CPUState* ctx);
void func_814F3FE0(CPUState* ctx);
void func_814F7FE0(CPUState* ctx);
void func_814FBFE0(CPUState* ctx);
void func_814FFFE0(CPUState* ctx);
void func_81503FE0(CPUState* ctx);
void func_81507FE0(CPUState* ctx);
void func_8150BFE0(CPUState* ctx);
void func_8150FFE0(CPUState* ctx);
void func_81513FE0(CPUState* ctx);
void func_81517FE0(CPUState* ctx);
void func_8151BFE0(CPUState* ctx);
void func_8151FFE0(CPUState* ctx);
void func_81523FE0(CPUState* ctx);
void func_81527FE0(CPUState* ctx);
void func_8152BFE0(CPUState* ctx);
void func_8152FFE0(CPUState* ctx);
void func_81533FE0(CPUState* ctx);
void func_81537FE0(CPUState* ctx);
void func_8153BFE0(CPUState* ctx);
void func_8153FFE0(CPUState* ctx);
void func_81543FE0(CPUState* ctx);
void func_81547FE0(CPUState* ctx);
void func_8154BFE0(CPUState* ctx);
void func_8154FFE0(CPUState* ctx);
void func_81553FE0(CPUState* ctx);
void func_81557FE0(CPUState* ctx);
void func_8155BFE0(CPUState* ctx);
void func_8155FFE0(CPUState* ctx);
void func_81563FE0(CPUState* ctx);
void func_81567FE0(CPUState* ctx);
void func_8156BFE0(CPUState* ctx);
void func_8156FFE0(CPUState* ctx);
void func_81573FE0(CPUState* ctx);
void func_81577FE0(CPUState* ctx);
void func_8157BFE0(CPUState* ctx);
void func_8157FFE0(CPUState* ctx);
void func_81583FE0(CPUState* ctx);
void func_81587FE0(CPUState* ctx);
void func_8158BFE0(CPUState* ctx);
void func_8158FFE0(CPUState* ctx);
void func_81593FE0(CPUState* ctx);
void func_81597FE0(CPUState* ctx);
void func_8159BFE0(CPUState* ctx);
void func_8159FFE0(CPUState* ctx);
void func_815A3FE0(CPUState* ctx);
void func_815A7FE0(CPUState* ctx);
void func_815ABFE0(CPUState* ctx);
void func_815AFFE0(CPUState* ctx);
void func_815B3FE0(CPUState* ctx);
void func_815B7FE0(CPUState* ctx);
void func_815BBFE0(CPUState* ctx);
void func_815BFFE0(CPUState* ctx);
void func_815C3FE0(CPUState* ctx);
void func_815C7FE0(CPUState* ctx);
void func_815CBFE0(CPUState* ctx);
void func_815CFFE0(CPUState* ctx);
void func_815D3FE0(CPUState* ctx);
void func_815D7FE0(CPUState* ctx);
void func_815DBFE0(CPUState* ctx);
void func_815DFFE0(CPUState* ctx);
void func_815E3FE0(CPUState* ctx);
void func_815E7FE0(CPUState* ctx);
void func_815EBFE0(CPUState* ctx);
void func_815EFFE0(CPUState* ctx);
void func_815F3FE0(CPUState* ctx);
void func_815F7FE0(CPUState* ctx);
void func_815FBFE0(CPUState* ctx);
void func_815FFFE0(CPUState* ctx);
void func_81603FE0(CPUState* ctx);
void func_81607FE0(CPUState* ctx);
void func_8160BFE0(CPUState* ctx);
void func_8160FFE0(CPUState* ctx);
void func_81613FE0(CPUState* ctx);
void func_81617FE0(CPUState* ctx);
void func_8161BFE0(CPUState* ctx);
void func_8161FFE0(CPUState* ctx);
void func_81623FE0(CPUState* ctx);
void func_81627FE0(CPUState* ctx);
void func_8162BFE0(CPUState* ctx);
void func_8162FFE0(CPUState* ctx);
void func_81633FE0(CPUState* ctx);
void func_81637FE0(CPUState* ctx);
void func_8163BFE0(CPUState* ctx);
void func_8163FFE0(CPUState* ctx);
void func_81643FE0(CPUState* ctx);
void func_81647FE0(CPUState* ctx);
void func_8164BFE0(CPUState* ctx);
void func_8164FFE0(CPUState* ctx);
void func_81653FE0(CPUState* ctx);
void func_81657FE0(CPUState* ctx);
void func_8165BFE0(CPUState* ctx);
void func_8165FFE0(CPUState* ctx);
void func_81663FE0(CPUState* ctx);
void func_81667FE0(CPUState* ctx);
void func_8166BFE0(CPUState* ctx);
void func_8166FFE0(CPUState* ctx);
void func_81673FE0(CPUState* ctx);
void func_81677FE0(CPUState* ctx);
void func_8167BFE0(CPUState* ctx);
void func_8167FFE0(CPUState* ctx);
void func_81683FE0(CPUState* ctx);
void func_81687FE0(CPUState* ctx);
void func_8168BFE0(CPUState* ctx);
void func_8168FFE0(CPUState* ctx);
void func_81693FE0(CPUState* ctx);
void func_81697FE0(CPUState* ctx);
void func_8169BFE0(CPUState* ctx);
void func_8169FFE0(CPUState* ctx);
void func_816A3FE0(CPUState* ctx);
void func_816A7FE0(CPUState* ctx);
void func_816ABFE0(CPUState* ctx);
void func_816AFFE0(CPUState* ctx);
void func_816B3FE0(CPUState* ctx);
void func_816B7FE0(CPUState* ctx);
void func_816BBFE0(CPUState* ctx);
void func_816BFFE0(CPUState* ctx);
void func_816C3FE0(CPUState* ctx);
void func_816C7FE0(CPUState* ctx);
void func_816CBFE0(CPUState* ctx);
void func_816CFFE0(CPUState* ctx);
void func_816D3FE0(CPUState* ctx);
void func_816D7FE0(CPUState* ctx);
void func_816DBFE0(CPUState* ctx);

#define DOLRECOMP_ENTRY_POINT 0x80003400u

typedef void (*DolRecompFunction)(CPUState* ctx);

static inline int dolrecomp_call(CPUState* ctx, u32 address) {
    if (ppc_host_call(ctx, address)) return 1;
    // DolRecomp constant-time chunk dispatch.
    if (address >= 0x80003400u && address < 0x80003800u && ((address - 0x80003400u) & 3u) == 0u) {
        func_80003400(ctx);
        return 1;
    }
    if (address >= 0x8132FFE0u && address < 0x816DFFE0u && ((address - 0x8132FFE0u) & 3u) == 0u) {
        static const DolRecompFunction functions[] = {
            func_8132FFE0,
            func_81333FE0,
            func_81337FE0,
            func_8133BFE0,
            func_8133FFE0,
            func_81343FE0,
            func_81347FE0,
            func_8134BFE0,
            func_8134FFE0,
            func_81353FE0,
            func_81357FE0,
            func_8135BFE0,
            func_8135FFE0,
            func_81363FE0,
            func_81367FE0,
            func_8136BFE0,
            func_8136FFE0,
            func_81373FE0,
            func_81377FE0,
            func_8137BFE0,
            func_8137FFE0,
            func_81383FE0,
            func_81387FE0,
            func_8138BFE0,
            func_8138FFE0,
            func_81393FE0,
            func_81397FE0,
            func_8139BFE0,
            func_8139FFE0,
            func_813A3FE0,
            func_813A7FE0,
            func_813ABFE0,
            func_813AFFE0,
            func_813B3FE0,
            func_813B7FE0,
            func_813BBFE0,
            func_813BFFE0,
            func_813C3FE0,
            func_813C7FE0,
            func_813CBFE0,
            func_813CFFE0,
            func_813D3FE0,
            func_813D7FE0,
            func_813DBFE0,
            func_813DFFE0,
            func_813E3FE0,
            func_813E7FE0,
            func_813EBFE0,
            func_813EFFE0,
            func_813F3FE0,
            func_813F7FE0,
            func_813FBFE0,
            func_813FFFE0,
            func_81403FE0,
            func_81407FE0,
            func_8140BFE0,
            func_8140FFE0,
            func_81413FE0,
            func_81417FE0,
            func_8141BFE0,
            func_8141FFE0,
            func_81423FE0,
            func_81427FE0,
            func_8142BFE0,
            func_8142FFE0,
            func_81433FE0,
            func_81437FE0,
            func_8143BFE0,
            func_8143FFE0,
            func_81443FE0,
            func_81447FE0,
            func_8144BFE0,
            func_8144FFE0,
            func_81453FE0,
            func_81457FE0,
            func_8145BFE0,
            func_8145FFE0,
            func_81463FE0,
            func_81467FE0,
            func_8146BFE0,
            func_8146FFE0,
            func_81473FE0,
            func_81477FE0,
            func_8147BFE0,
            func_8147FFE0,
            func_81483FE0,
            func_81487FE0,
            func_8148BFE0,
            func_8148FFE0,
            func_81493FE0,
            func_81497FE0,
            func_8149BFE0,
            func_8149FFE0,
            func_814A3FE0,
            func_814A7FE0,
            func_814ABFE0,
            func_814AFFE0,
            func_814B3FE0,
            func_814B7FE0,
            func_814BBFE0,
            func_814BFFE0,
            func_814C3FE0,
            func_814C7FE0,
            func_814CBFE0,
            func_814CFFE0,
            func_814D3FE0,
            func_814D7FE0,
            func_814DBFE0,
            func_814DFFE0,
            func_814E3FE0,
            func_814E7FE0,
            func_814EBFE0,
            func_814EFFE0,
            func_814F3FE0,
            func_814F7FE0,
            func_814FBFE0,
            func_814FFFE0,
            func_81503FE0,
            func_81507FE0,
            func_8150BFE0,
            func_8150FFE0,
            func_81513FE0,
            func_81517FE0,
            func_8151BFE0,
            func_8151FFE0,
            func_81523FE0,
            func_81527FE0,
            func_8152BFE0,
            func_8152FFE0,
            func_81533FE0,
            func_81537FE0,
            func_8153BFE0,
            func_8153FFE0,
            func_81543FE0,
            func_81547FE0,
            func_8154BFE0,
            func_8154FFE0,
            func_81553FE0,
            func_81557FE0,
            func_8155BFE0,
            func_8155FFE0,
            func_81563FE0,
            func_81567FE0,
            func_8156BFE0,
            func_8156FFE0,
            func_81573FE0,
            func_81577FE0,
            func_8157BFE0,
            func_8157FFE0,
            func_81583FE0,
            func_81587FE0,
            func_8158BFE0,
            func_8158FFE0,
            func_81593FE0,
            func_81597FE0,
            func_8159BFE0,
            func_8159FFE0,
            func_815A3FE0,
            func_815A7FE0,
            func_815ABFE0,
            func_815AFFE0,
            func_815B3FE0,
            func_815B7FE0,
            func_815BBFE0,
            func_815BFFE0,
            func_815C3FE0,
            func_815C7FE0,
            func_815CBFE0,
            func_815CFFE0,
            func_815D3FE0,
            func_815D7FE0,
            func_815DBFE0,
            func_815DFFE0,
            func_815E3FE0,
            func_815E7FE0,
            func_815EBFE0,
            func_815EFFE0,
            func_815F3FE0,
            func_815F7FE0,
            func_815FBFE0,
            func_815FFFE0,
            func_81603FE0,
            func_81607FE0,
            func_8160BFE0,
            func_8160FFE0,
            func_81613FE0,
            func_81617FE0,
            func_8161BFE0,
            func_8161FFE0,
            func_81623FE0,
            func_81627FE0,
            func_8162BFE0,
            func_8162FFE0,
            func_81633FE0,
            func_81637FE0,
            func_8163BFE0,
            func_8163FFE0,
            func_81643FE0,
            func_81647FE0,
            func_8164BFE0,
            func_8164FFE0,
            func_81653FE0,
            func_81657FE0,
            func_8165BFE0,
            func_8165FFE0,
            func_81663FE0,
            func_81667FE0,
            func_8166BFE0,
            func_8166FFE0,
            func_81673FE0,
            func_81677FE0,
            func_8167BFE0,
            func_8167FFE0,
            func_81683FE0,
            func_81687FE0,
            func_8168BFE0,
            func_8168FFE0,
            func_81693FE0,
            func_81697FE0,
            func_8169BFE0,
            func_8169FFE0,
            func_816A3FE0,
            func_816A7FE0,
            func_816ABFE0,
            func_816AFFE0,
            func_816B3FE0,
            func_816B7FE0,
            func_816BBFE0,
            func_816BFFE0,
            func_816C3FE0,
            func_816C7FE0,
            func_816CBFE0,
            func_816CFFE0,
            func_816D3FE0,
            func_816D7FE0,
            func_816DBFE0
        };
        const u32 index = (address - 0x8132FFE0u) / 0x4000u;
        functions[index](ctx);
        return 1;
    }
    return 0;
}

static inline int dolrecomp_run_blocks(CPUState* ctx, u32 max_blocks) {
    u32 blocks = 0;
    while (max_blocks == 0u || blocks < max_blocks) {
        if (!dolrecomp_call(ctx, ctx->pc)) return 0;
        if (ctx->exception) return 0;
        blocks++;
    }
    return 1;
}

#endif // RECOMP_GENERATED_H
// end
