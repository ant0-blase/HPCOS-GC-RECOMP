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

void func_80003000(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x80003000u: goto label_80003000;
    case 0x80003004u: goto label_80003004;
    case 0x80003008u: goto label_80003008;
    case 0x8000300Cu: goto label_8000300C;
    case 0x80003010u: goto label_80003010;
    case 0x80003014u: goto label_80003014;
    case 0x80003018u: goto label_80003018;
    case 0x8000301Cu: goto label_8000301C;
    case 0x80003020u: goto label_80003020;
    case 0x80003024u: goto label_80003024;
    case 0x80003028u: goto label_80003028;
    case 0x8000302Cu: goto label_8000302C;
    case 0x80003030u: goto label_80003030;
    case 0x80003034u: goto label_80003034;
    case 0x80003038u: goto label_80003038;
    case 0x8000303Cu: goto label_8000303C;
    case 0x80003040u: goto label_80003040;
    case 0x80003044u: goto label_80003044;
    case 0x80003048u: goto label_80003048;
    case 0x8000304Cu: goto label_8000304C;
    case 0x80003050u: goto label_80003050;
    case 0x80003054u: goto label_80003054;
    case 0x80003058u: goto label_80003058;
    case 0x8000305Cu: goto label_8000305C;
    case 0x80003060u: goto label_80003060;
    case 0x80003064u: goto label_80003064;
    case 0x80003068u: goto label_80003068;
    case 0x8000306Cu: goto label_8000306C;
    case 0x80003070u: goto label_80003070;
    case 0x80003074u: goto label_80003074;
    case 0x80003078u: goto label_80003078;
    case 0x8000307Cu: goto label_8000307C;
    case 0x80003080u: goto label_80003080;
    case 0x80003084u: goto label_80003084;
    case 0x80003088u: goto label_80003088;
    case 0x8000308Cu: goto label_8000308C;
    case 0x80003090u: goto label_80003090;
    case 0x80003094u: goto label_80003094;
    case 0x80003098u: goto label_80003098;
    case 0x8000309Cu: goto label_8000309C;
    case 0x800030A0u: goto label_800030A0;
    case 0x800030A4u: goto label_800030A4;
    case 0x800030A8u: goto label_800030A8;
    case 0x800030ACu: goto label_800030AC;
    case 0x800030B0u: goto label_800030B0;
    case 0x800030B4u: goto label_800030B4;
    case 0x800030B8u: goto label_800030B8;
    case 0x800030BCu: goto label_800030BC;
    case 0x800030C0u: goto label_800030C0;
    case 0x800030C4u: goto label_800030C4;
    case 0x800030C8u: goto label_800030C8;
    case 0x800030CCu: goto label_800030CC;
    case 0x800030D0u: goto label_800030D0;
    case 0x800030D4u: goto label_800030D4;
    case 0x800030D8u: goto label_800030D8;
    case 0x800030DCu: goto label_800030DC;
    case 0x800030E0u: goto label_800030E0;
    case 0x800030E4u: goto label_800030E4;
    case 0x800030E8u: goto label_800030E8;
    case 0x800030ECu: goto label_800030EC;
    case 0x800030F0u: goto label_800030F0;
    case 0x800030F4u: goto label_800030F4;
    case 0x800030F8u: goto label_800030F8;
    case 0x800030FCu: goto label_800030FC;
    case 0x80003100u: goto label_80003100;
    case 0x80003104u: goto label_80003104;
    case 0x80003108u: goto label_80003108;
    case 0x8000310Cu: goto label_8000310C;
    case 0x80003110u: goto label_80003110;
    case 0x80003114u: goto label_80003114;
    case 0x80003118u: goto label_80003118;
    case 0x8000311Cu: goto label_8000311C;
    case 0x80003120u: goto label_80003120;
    case 0x80003124u: goto label_80003124;
    case 0x80003128u: goto label_80003128;
    case 0x8000312Cu: goto label_8000312C;
    case 0x80003130u: goto label_80003130;
    case 0x80003134u: goto label_80003134;
    case 0x80003138u: goto label_80003138;
    case 0x8000313Cu: goto label_8000313C;
    case 0x80003140u: goto label_80003140;
    case 0x80003144u: goto label_80003144;
    case 0x80003148u: goto label_80003148;
    case 0x8000314Cu: goto label_8000314C;
    case 0x80003150u: goto label_80003150;
    case 0x80003154u: goto label_80003154;
    case 0x80003158u: goto label_80003158;
    case 0x8000315Cu: goto label_8000315C;
    case 0x80003160u: goto label_80003160;
    case 0x80003164u: goto label_80003164;
    case 0x80003168u: goto label_80003168;
    case 0x8000316Cu: goto label_8000316C;
    case 0x80003170u: goto label_80003170;
    case 0x80003174u: goto label_80003174;
    case 0x80003178u: goto label_80003178;
    case 0x8000317Cu: goto label_8000317C;
    case 0x80003180u: goto label_80003180;
    case 0x80003184u: goto label_80003184;
    case 0x80003188u: goto label_80003188;
    case 0x8000318Cu: goto label_8000318C;
    case 0x80003190u: goto label_80003190;
    case 0x80003194u: goto label_80003194;
    case 0x80003198u: goto label_80003198;
    case 0x8000319Cu: goto label_8000319C;
    case 0x800031A0u: goto label_800031A0;
    case 0x800031A4u: goto label_800031A4;
    case 0x800031A8u: goto label_800031A8;
    case 0x800031ACu: goto label_800031AC;
    case 0x800031B0u: goto label_800031B0;
    case 0x800031B4u: goto label_800031B4;
    case 0x800031B8u: goto label_800031B8;
    case 0x800031BCu: goto label_800031BC;
    case 0x800031C0u: goto label_800031C0;
    case 0x800031C4u: goto label_800031C4;
    case 0x800031C8u: goto label_800031C8;
    case 0x800031CCu: goto label_800031CC;
    case 0x800031D0u: goto label_800031D0;
    case 0x800031D4u: goto label_800031D4;
    case 0x800031D8u: goto label_800031D8;
    case 0x800031DCu: goto label_800031DC;
    case 0x800031E0u: goto label_800031E0;
    case 0x800031E4u: goto label_800031E4;
    case 0x800031E8u: goto label_800031E8;
    case 0x800031ECu: goto label_800031EC;
    case 0x800031F0u: goto label_800031F0;
    case 0x800031F4u: goto label_800031F4;
    case 0x800031F8u: goto label_800031F8;
    case 0x800031FCu: goto label_800031FC;
    case 0x80003200u: goto label_80003200;
    case 0x80003204u: goto label_80003204;
    case 0x80003208u: goto label_80003208;
    case 0x8000320Cu: goto label_8000320C;
    case 0x80003210u: goto label_80003210;
    case 0x80003214u: goto label_80003214;
    case 0x80003218u: goto label_80003218;
    case 0x8000321Cu: goto label_8000321C;
    case 0x80003220u: goto label_80003220;
    case 0x80003224u: goto label_80003224;
    case 0x80003228u: goto label_80003228;
    case 0x8000322Cu: goto label_8000322C;
    case 0x80003230u: goto label_80003230;
    case 0x80003234u: goto label_80003234;
    case 0x80003238u: goto label_80003238;
    case 0x8000323Cu: goto label_8000323C;
    case 0x80003240u: goto label_80003240;
    case 0x80003244u: goto label_80003244;
    case 0x80003248u: goto label_80003248;
    case 0x8000324Cu: goto label_8000324C;
    case 0x80003250u: goto label_80003250;
    case 0x80003254u: goto label_80003254;
    case 0x80003258u: goto label_80003258;
    case 0x8000325Cu: goto label_8000325C;
    case 0x80003260u: goto label_80003260;
    case 0x80003264u: goto label_80003264;
    case 0x80003268u: goto label_80003268;
    case 0x8000326Cu: goto label_8000326C;
    case 0x80003270u: goto label_80003270;
    case 0x80003274u: goto label_80003274;
    case 0x80003278u: goto label_80003278;
    case 0x8000327Cu: goto label_8000327C;
    case 0x80003280u: goto label_80003280;
    case 0x80003284u: goto label_80003284;
    case 0x80003288u: goto label_80003288;
    case 0x8000328Cu: goto label_8000328C;
    case 0x80003290u: goto label_80003290;
    case 0x80003294u: goto label_80003294;
    case 0x80003298u: goto label_80003298;
    case 0x8000329Cu: goto label_8000329C;
    case 0x800032A0u: goto label_800032A0;
    case 0x800032A4u: goto label_800032A4;
    case 0x800032A8u: goto label_800032A8;
    case 0x800032ACu: goto label_800032AC;
    case 0x800032B0u: goto label_800032B0;
    case 0x800032B4u: goto label_800032B4;
    case 0x800032B8u: goto label_800032B8;
    case 0x800032BCu: goto label_800032BC;
    case 0x800032C0u: goto label_800032C0;
    case 0x800032C4u: goto label_800032C4;
    case 0x800032C8u: goto label_800032C8;
    case 0x800032CCu: goto label_800032CC;
    case 0x800032D0u: goto label_800032D0;
    case 0x800032D4u: goto label_800032D4;
    case 0x800032D8u: goto label_800032D8;
    case 0x800032DCu: goto label_800032DC;
    case 0x800032E0u: goto label_800032E0;
    case 0x800032E4u: goto label_800032E4;
    case 0x800032E8u: goto label_800032E8;
    case 0x800032ECu: goto label_800032EC;
    case 0x800032F0u: goto label_800032F0;
    case 0x800032F4u: goto label_800032F4;
    case 0x800032F8u: goto label_800032F8;
    case 0x800032FCu: goto label_800032FC;
    case 0x80003300u: goto label_80003300;
    case 0x80003304u: goto label_80003304;
    case 0x80003308u: goto label_80003308;
    case 0x8000330Cu: goto label_8000330C;
    case 0x80003310u: goto label_80003310;
    case 0x80003314u: goto label_80003314;
    case 0x80003318u: goto label_80003318;
    case 0x8000331Cu: goto label_8000331C;
    case 0x80003320u: goto label_80003320;
    case 0x80003324u: goto label_80003324;
    case 0x80003328u: goto label_80003328;
    case 0x8000332Cu: goto label_8000332C;
    case 0x80003330u: goto label_80003330;
    case 0x80003334u: goto label_80003334;
    case 0x80003338u: goto label_80003338;
    case 0x8000333Cu: goto label_8000333C;
    case 0x80003340u: goto label_80003340;
    case 0x80003344u: goto label_80003344;
    case 0x80003348u: goto label_80003348;
    case 0x8000334Cu: goto label_8000334C;
    case 0x80003350u: goto label_80003350;
    case 0x80003354u: goto label_80003354;
    case 0x80003358u: goto label_80003358;
    case 0x8000335Cu: goto label_8000335C;
    case 0x80003360u: goto label_80003360;
    case 0x80003364u: goto label_80003364;
    case 0x80003368u: goto label_80003368;
    case 0x8000336Cu: goto label_8000336C;
    case 0x80003370u: goto label_80003370;
    case 0x80003374u: goto label_80003374;
    case 0x80003378u: goto label_80003378;
    case 0x8000337Cu: goto label_8000337C;
    case 0x80003380u: goto label_80003380;
    case 0x80003384u: goto label_80003384;
    case 0x80003388u: goto label_80003388;
    case 0x8000338Cu: goto label_8000338C;
    case 0x80003390u: goto label_80003390;
    case 0x80003394u: goto label_80003394;
    case 0x80003398u: goto label_80003398;
    case 0x8000339Cu: goto label_8000339C;
    case 0x800033A0u: goto label_800033A0;
    case 0x800033A4u: goto label_800033A4;
    case 0x800033A8u: goto label_800033A8;
    case 0x800033ACu: goto label_800033AC;
    default: return;
    }
label_80003000:
    ctx->pc = 0x80003000u;
    ctx->downcount -= 53;
    // 80003000: mulli   r3, r4, -7
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[4] * (s64)(s32)-7);

label_80003004:
    ctx->pc = 0x80003004u;
    // 80003004: subfic  r4, r5, 1
    {
        u64 res = (u64)(u32)(s32)(1) + (u64)(~ctx->gpr[5]) + 1u;
        ctx->gpr[4] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80003008:
    ctx->pc = 0x80003008u;
    // 80003008: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8000300C:
    ctx->pc = 0x8000300Cu;
    // 8000300C: addic   r4, r4, -1
    {
        u64 a = ctx->gpr[4];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[4] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80003010:
    ctx->pc = 0x80003010u;
    // 80003010: addic.  r5, r5, -1
    {
        u64 a = ctx->gpr[5];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80003014:
    ctx->pc = 0x80003014u;
    // 80003014: lis     r5, 4660
    ctx->gpr[5] = ((u32)(s32)(4660) << 16);

label_80003018:
    ctx->pc = 0x80003018u;
    // 80003018: cmpwi   r3, -1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8000301C:
    ctx->pc = 0x8000301Cu;
    // 8000301C: cmplwi  r3, 0x8000
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x8000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80003020:
    ctx->pc = 0x80003020u;
    // 80003020: ori     r4, r3, 0xFF00
    ctx->gpr[4] = ctx->gpr[3] | 0xFF00u;

label_80003024:
    ctx->pc = 0x80003024u;
    // 80003024: oris    r5, r4, 0x1234
    ctx->gpr[5] = ctx->gpr[4] | (0x1234u << 16);

label_80003028:
    ctx->pc = 0x80003028u;
    // 80003028: xori    r6, r5, 0xFFFF
    ctx->gpr[6] = ctx->gpr[5] ^ 0xFFFFu;

label_8000302C:
    ctx->pc = 0x8000302Cu;
    // 8000302C: xoris   r7, r6, 0x8000
    ctx->gpr[7] = ctx->gpr[6] ^ (0x8000u << 16);

label_80003030:
    ctx->pc = 0x80003030u;
    // 80003030: andi.   r8, r7, 0x00FF
    {
        ctx->gpr[8] = ctx->gpr[7] & 0x00FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80003034:
    ctx->pc = 0x80003034u;
    // 80003034: andis.  r9, r7, 0x00FF
    {
        ctx->gpr[9] = ctx->gpr[7] & (0x00FFu << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80003038:
    ctx->pc = 0x80003038u;
    // 80003038: lwz     r3, 0(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8000303C:
    ctx->pc = 0x8000303Cu;
    // 8000303C: lwzu     r4, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
        ctx->gpr[1] = ea;
    }

label_80003040:
    ctx->pc = 0x80003040u;
    // 80003040: lbz     r5, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80003044:
    ctx->pc = 0x80003044u;
    // 80003044: lbzu     r6, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[6] = mem_read8(ctx, ea);
        ctx->gpr[1] = ea;
    }

label_80003048:
    ctx->pc = 0x80003048u;
    // 80003048: lhz     r7, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_8000304C:
    ctx->pc = 0x8000304Cu;
    // 8000304C: lhzu     r8, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[8] = mem_read16(ctx, ea);
        ctx->gpr[1] = ea;
    }

label_80003050:
    ctx->pc = 0x80003050u;
    // 80003050: lha     r9, -4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-4);
        ctx->gpr[9] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80003054:
    ctx->pc = 0x80003054u;
    // 80003054: lhau     r10, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
        ctx->gpr[1] = ea;
    }

label_80003058:
    ctx->pc = 0x80003058u;
    // 80003058: stw     r3, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8000305C:
    ctx->pc = 0x8000305Cu;
    // 8000305C: stwu     r4, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
        ctx->gpr[1] = ea;
    }

label_80003060:
    ctx->pc = 0x80003060u;
    // 80003060: stb     r5, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80003064:
    ctx->pc = 0x80003064u;
    // 80003064: stbu     r6, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
        ctx->gpr[1] = ea;
    }

label_80003068:
    ctx->pc = 0x80003068u;
    // 80003068: sth     r7, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8000306C:
    ctx->pc = 0x8000306Cu;
    // 8000306C: sthu     r8, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
        ctx->gpr[1] = ea;
    }

label_80003070:
    ctx->pc = 0x80003070u;
    // 80003070: lmw     r20, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        for (u32 r = 20; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80003074:
    ctx->pc = 0x80003074u;
    // 80003074: stmw     r20, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        for (u32 r = 20; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80003078:
    ctx->pc = 0x80003078u;
    // 80003078: b       0x80003140
    {
            goto label_80003140;
    }

label_8000307C:
    ctx->pc = 0x8000307Cu;
    ctx->downcount -= 1;
    // 8000307C: bc    12, 2, 0x80003140
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80003140;
        }
    }

label_80003080:
    ctx->pc = 0x80003080u;
    ctx->downcount -= 1;
    // 80003080: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80003084:
    ctx->pc = 0x80003084u;
    ctx->downcount -= 1;
    // 80003084: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80003088:
    ctx->pc = 0x80003088u;
    ctx->downcount -= 47;
    // 80003088: crand   2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a & b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8000308C:
    ctx->pc = 0x8000308Cu;
    // 8000308C: crandc  2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a & ~b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80003090:
    ctx->pc = 0x80003090u;
    // 80003090: creqv   2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (~(a ^ b)) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80003094:
    ctx->pc = 0x80003094u;
    // 80003094: crnand  2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (~(a & b)) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80003098:
    ctx->pc = 0x80003098u;
    // 80003098: crnor   2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (~(a | b)) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8000309C:
    ctx->pc = 0x8000309Cu;
    // 8000309C: cror    2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800030A0:
    ctx->pc = 0x800030A0u;
    // 800030A0: crorc   2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | ~b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800030A4:
    ctx->pc = 0x800030A4u;
    // 800030A4: crxor   2, 3, 4
    {
        u32 a = (ctx->cr >> (31u - 3u)) & 1u;
        u32 b = (ctx->cr >> (31u - 4u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800030A8:
    ctx->pc = 0x800030A8u;
    // 800030A8: mcrf    cr2, cr3
    {
        u32 bits = (ctx->cr >> 16) & 0xFu;
        ctx->cr = (ctx->cr & ~(0xFu << 20)) | (bits << 20);
    }

label_800030AC:
    ctx->pc = 0x800030ACu;
    // 800030AC: mfcr    r10
    ctx->gpr[10] = ctx->cr;

label_800030B0:
    ctx->pc = 0x800030B0u;
    // 800030B0: mtcr    r10
    ctx->cr = (ctx->cr & ~0xFFFFFFFFu) | (ctx->gpr[10] & 0xFFFFFFFFu);

label_800030B4:
    ctx->pc = 0x800030B4u;
    // 800030B4: mflr    r10
    ctx->gpr[10] = ctx->lr;

label_800030B8:
    ctx->pc = 0x800030B8u;
    // 800030B8: mtlr    r10
    ctx->lr = ctx->gpr[10];

label_800030BC:
    ctx->pc = 0x800030BCu;
    // 800030BC: cmpw    cr1, r3, r4
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 24)) | (cr_bits << 24);
    }

label_800030C0:
    ctx->pc = 0x800030C0u;
    // 800030C0: cmplw   cr2, r3, r4
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 20)) | (cr_bits << 20);
    }

label_800030C4:
    ctx->pc = 0x800030C4u;
    // 800030C4: add   r10, r11, r12
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[12];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_800030C8:
    ctx->pc = 0x800030C8u;
    // 800030C8: addc   r11, r12, r13
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[13];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[11] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_800030CC:
    ctx->pc = 0x800030CCu;
    // 800030CC: adde   r12, r13, r14
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[13];
        u32 b = ctx->gpr[14];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[12] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_800030D0:
    ctx->pc = 0x800030D0u;
    // 800030D0: addze  r13, r14
    {
        u32 a = ctx->gpr[14];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[13] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_800030D4:
    ctx->pc = 0x800030D4u;
    // 800030D4: subf   r14, r15, r16
    {
        u32 a = ~ctx->gpr[15];
        u32 b = ctx->gpr[16];
        u32 res = a + b + 1u;
        ctx->gpr[14] = res;
    }

label_800030D8:
    ctx->pc = 0x800030D8u;
    // 800030D8: subfc   r15, r16, r17
    {
        u32 a = ~ctx->gpr[16];
        u32 b = ctx->gpr[17];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[15] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_800030DC:
    ctx->pc = 0x800030DCu;
    // 800030DC: subfe   r16, r17, r18
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[18];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[16] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_800030E0:
    ctx->pc = 0x800030E0u;
    // 800030E0: subfze  r17, r18
    {
        u32 a = ~ctx->gpr[18];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[17] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_800030E4:
    ctx->pc = 0x800030E4u;
    // 800030E4: neg  r18, r19
    {
        u32 a = ctx->gpr[19];
        ctx->gpr[18] = (~a) + 1u;
    }

label_800030E8:
    ctx->pc = 0x800030E8u;
    // 800030E8: and   r19, r20, r21
    {
        ctx->gpr[19] = ctx->gpr[20] & ctx->gpr[21];
    }

label_800030EC:
    ctx->pc = 0x800030ECu;
    // 800030EC: andc   r20, r21, r22
    {
        ctx->gpr[20] = ctx->gpr[21] & ~ctx->gpr[22];
    }

label_800030F0:
    ctx->pc = 0x800030F0u;
    // 800030F0: or   r21, r22, r23
    {
        ctx->gpr[21] = ctx->gpr[22] | ctx->gpr[23];
    }

label_800030F4:
    ctx->pc = 0x800030F4u;
    // 800030F4: orc   r22, r23, r24
    {
        ctx->gpr[22] = ctx->gpr[23] | ~ctx->gpr[24];
    }

label_800030F8:
    ctx->pc = 0x800030F8u;
    // 800030F8: xor   r23, r24, r25
    {
        ctx->gpr[23] = ctx->gpr[24] ^ ctx->gpr[25];
    }

label_800030FC:
    ctx->pc = 0x800030FCu;
    // 800030FC: nand   r24, r25, r26
    {
        ctx->gpr[24] = ~(ctx->gpr[25] & ctx->gpr[26]);
    }

label_80003100:
    ctx->pc = 0x80003100u;
    // 80003100: nor   r25, r26, r27
    {
        ctx->gpr[25] = ~(ctx->gpr[26] | ctx->gpr[27]);
    }

label_80003104:
    ctx->pc = 0x80003104u;
    // 80003104: eqv   r26, r27, r28
    {
        ctx->gpr[26] = ~(ctx->gpr[27] ^ ctx->gpr[28]);
    }

label_80003108:
    ctx->pc = 0x80003108u;
    // 80003108: cntlzw r27, r28
    {
        u32 v = ctx->gpr[28];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[27] = n;
    }

label_8000310C:
    ctx->pc = 0x8000310Cu;
    // 8000310C: extsb r28, r29
    {
        ctx->gpr[28] = (u32)(s32)(s8)ctx->gpr[29];
    }

label_80003110:
    ctx->pc = 0x80003110u;
    // 80003110: extsh r29, r30
    {
        ctx->gpr[29] = (u32)(s32)(s16)ctx->gpr[30];
    }

label_80003114:
    ctx->pc = 0x80003114u;
    // 80003114: slw   r30, r31, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[30] = sh > 31 ? 0u : (ctx->gpr[31] << sh);
    }

label_80003118:
    ctx->pc = 0x80003118u;
    // 80003118: srw   r31, r3, r4
    {
        u32 sh = ctx->gpr[4] & 0x3Fu;
        ctx->gpr[31] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_8000311C:
    ctx->pc = 0x8000311Cu;
    // 8000311C: sraw   r3, r4, r5
    {
        u32 sh = ctx->gpr[5] & 0x3Fu;
        u32 value = ctx->gpr[4];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[3] = value;
        } else if (sh > 31) {
            ctx->gpr[3] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[3] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80003120:
    ctx->pc = 0x80003120u;
    // 80003120: srawi r4, r5, 7
    {
        u32 sh = 7u;
        u32 value = ctx->gpr[5];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[4] = value;
        } else if (sh > 31) {
            ctx->gpr[4] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[4] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80003124:
    ctx->pc = 0x80003124u;
    // 80003124: rlwinm r5, r6, 5, 8, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 5u) & 0x00FFFF00u;
    }

label_80003128:
    ctx->pc = 0x80003128u;
    // 80003128: rlwnm r6, r7, r8, 4, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], ctx->gpr[8]) & 0x0FFFFFF0u;
    }

label_8000312C:
    ctx->pc = 0x8000312Cu;
    // 8000312C: rlwimi r7, r8, 8, 8, 15
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[8], 8u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00FF0000u) | (rot & 0x00FF0000u);
    }

label_80003130:
    ctx->pc = 0x80003130u;
    // 80003130: lwzx    r3, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80003134:
    ctx->pc = 0x80003134u;
    // 80003134: lwzux    r6, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[6] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80003138:
    ctx->pc = 0x80003138u;
    // 80003138: lbzx    r7, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8000313C:
    ctx->pc = 0x8000313Cu;
    // 8000313C: lbzux    r8, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[8] = mem_read8(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80003140:
    ctx->pc = 0x80003140u;
    ctx->downcount -= 396;
    // 80003140: lhzx    r9, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80003144:
    ctx->pc = 0x80003144u;
    // 80003144: lhzux    r10, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[10] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80003148:
    ctx->pc = 0x80003148u;
    // 80003148: lhax    r11, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[11] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8000314C:
    ctx->pc = 0x8000314Cu;
    // 8000314C: lhaux    r12, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[12] = (u32)(s32)(s16)mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80003150:
    ctx->pc = 0x80003150u;
    // 80003150: lwbrx    r3, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[3] = bswap32(mem_read32(ctx, ea));
    }

label_80003154:
    ctx->pc = 0x80003154u;
    // 80003154: lhbrx    r6, r7, r8
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[8];
        ctx->gpr[6] = bswap16(mem_read16(ctx, ea));
    }

label_80003158:
    ctx->pc = 0x80003158u;
    // 80003158: stwx    r3, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8000315C:
    ctx->pc = 0x8000315Cu;
    // 8000315C: stwux    r6, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[4] = ea;
    }

label_80003160:
    ctx->pc = 0x80003160u;
    // 80003160: stbx    r7, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_80003164:
    ctx->pc = 0x80003164u;
    // 80003164: stbux    r8, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
        ctx->gpr[4] = ea;
    }

label_80003168:
    ctx->pc = 0x80003168u;
    // 80003168: sthx    r9, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_8000316C:
    ctx->pc = 0x8000316Cu;
    // 8000316C: sthux    r10, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
        ctx->gpr[4] = ea;
    }

label_80003170:
    ctx->pc = 0x80003170u;
    // 80003170: stwbrx    r9, r10, r11
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[11];
        mem_write32(ctx, ea, bswap32(ctx->gpr[9]));
    }

label_80003174:
    ctx->pc = 0x80003174u;
    // 80003174: sthbrx    r12, r13, r14
    {
        u32 ea = ctx->gpr[13] + ctx->gpr[14];
        mem_write16(ctx, ea, bswap16((u16)ctx->gpr[12]));
    }

label_80003178:
    ctx->pc = 0x80003178u;
    // 80003178: dcbz    r15, r16
    {
        u32 ea = ctx->gpr[15] + ctx->gpr[16];
        ea &= ~31u;
        for (u32 i = 0; i < 32; i += 4) mem_write32(ctx, ea + i, 0);
    }

label_8000317C:
    ctx->pc = 0x8000317Cu;
    // 8000317C: lfs     f1, 0(r4)
    if (!ppc_fp_available(ctx, 0x8000317Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        f64 value = (f64)dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80003180:
    ctx->pc = 0x80003180u;
    // 80003180: lfsu     f2, 4(r4)
    if (!ppc_fp_available(ctx, 0x80003180u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        f64 value = (f64)dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
        ctx->gpr[4] = ea;
    }

label_80003184:
    ctx->pc = 0x80003184u;
    // 80003184: lfd     f3, 8(r4)
    if (!ppc_fp_available(ctx, 0x80003184u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80003188:
    ctx->pc = 0x80003188u;
    // 80003188: lfdu     f4, 16(r4)
    if (!ppc_fp_available(ctx, 0x80003188u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
        ctx->gpr[4] = ea;
    }

label_8000318C:
    ctx->pc = 0x8000318Cu;
    // 8000318C: stfs     f5, 20(r4)
    if (!ppc_fp_available(ctx, 0x8000318Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits((f32)ctx->fpr[5]));
    }

label_80003190:
    ctx->pc = 0x80003190u;
    // 80003190: stfsu     f6, 24(r4)
    if (!ppc_fp_available(ctx, 0x80003190u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits((f32)ctx->fpr[6]));
        ctx->gpr[4] = ea;
    }

label_80003194:
    ctx->pc = 0x80003194u;
    // 80003194: stfd     f7, 32(r4)
    if (!ppc_fp_available(ctx, 0x80003194u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_80003198:
    ctx->pc = 0x80003198u;
    // 80003198: stfdu     f8, 40(r4)
    if (!ppc_fp_available(ctx, 0x80003198u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
        ctx->gpr[4] = ea;
    }

label_8000319C:
    ctx->pc = 0x8000319Cu;
    // 8000319C: lfsx    f9, r4, r5
    if (!ppc_fp_available(ctx, 0x8000319Cu)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        f64 value = (f64)dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_800031A0:
    ctx->pc = 0x800031A0u;
    // 800031A0: lfsux    f10, r4, r5
    if (!ppc_fp_available(ctx, 0x800031A0u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        f64 value = (f64)dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
        ctx->gpr[4] = ea;
    }

label_800031A4:
    ctx->pc = 0x800031A4u;
    // 800031A4: lfdx    f11, r4, r5
    if (!ppc_fp_available(ctx, 0x800031A4u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->fpr[11] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800031A8:
    ctx->pc = 0x800031A8u;
    // 800031A8: lfdux    f12, r4, r5
    if (!ppc_fp_available(ctx, 0x800031A8u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->fpr[12] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
        ctx->gpr[4] = ea;
    }

label_800031AC:
    ctx->pc = 0x800031ACu;
    // 800031AC: stfsx    f13, r4, r5
    if (!ppc_fp_available(ctx, 0x800031ACu)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write32(ctx, ea, dolrecomp_f32_to_bits((f32)ctx->fpr[13]));
    }

label_800031B0:
    ctx->pc = 0x800031B0u;
    // 800031B0: stfsux    f14, r4, r5
    if (!ppc_fp_available(ctx, 0x800031B0u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write32(ctx, ea, dolrecomp_f32_to_bits((f32)ctx->fpr[14]));
        ctx->gpr[4] = ea;
    }

label_800031B4:
    ctx->pc = 0x800031B4u;
    // 800031B4: stfdx    f15, r4, r5
    if (!ppc_fp_available(ctx, 0x800031B4u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[15]));
    }

label_800031B8:
    ctx->pc = 0x800031B8u;
    // 800031B8: stfdux    f16, r4, r5
    if (!ppc_fp_available(ctx, 0x800031B8u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[16]));
        ctx->gpr[4] = ea;
    }

label_800031BC:
    ctx->pc = 0x800031BCu;
    // 800031BC: fadds   f1, f2, f3
    if (!ppc_fp_available(ctx, 0x800031BCu)) return;
    ctx->fpr[1] = (f64)(f32)(ctx->fpr[2] + ctx->fpr[3]);

label_800031C0:
    ctx->pc = 0x800031C0u;
    // 800031C0: fsubs   f4, f5, f6
    if (!ppc_fp_available(ctx, 0x800031C0u)) return;
    ctx->fpr[4] = (f64)(f32)(ctx->fpr[5] - ctx->fpr[6]);

label_800031C4:
    ctx->pc = 0x800031C4u;
    // 800031C4: fmuls   f7, f8, f9
    if (!ppc_fp_available(ctx, 0x800031C4u)) return;
    ctx->fpr[7] = (f64)(f32)(ctx->fpr[8] * ctx->fpr[9]);

label_800031C8:
    ctx->pc = 0x800031C8u;
    // 800031C8: fdivs   f10, f11, f12
    if (!ppc_fp_available(ctx, 0x800031C8u)) return;
    ctx->fpr[10] = (f64)(f32)(ctx->fpr[11] / ctx->fpr[12]);

label_800031CC:
    ctx->pc = 0x800031CCu;
    // 800031CC: fadd   f13, f14, f15
    if (!ppc_fp_available(ctx, 0x800031CCu)) return;
    ctx->fpr[13] = ctx->fpr[14] + ctx->fpr[15];

label_800031D0:
    ctx->pc = 0x800031D0u;
    // 800031D0: fsub   f16, f17, f18
    if (!ppc_fp_available(ctx, 0x800031D0u)) return;
    ctx->fpr[16] = ctx->fpr[17] - ctx->fpr[18];

label_800031D4:
    ctx->pc = 0x800031D4u;
    // 800031D4: fmul   f19, f20, f21
    if (!ppc_fp_available(ctx, 0x800031D4u)) return;
    ctx->fpr[19] = ctx->fpr[20] * ctx->fpr[21];

label_800031D8:
    ctx->pc = 0x800031D8u;
    // 800031D8: fdiv   f22, f23, f24
    if (!ppc_fp_available(ctx, 0x800031D8u)) return;
    ctx->fpr[22] = ctx->fpr[23] / ctx->fpr[24];

label_800031DC:
    ctx->pc = 0x800031DCu;
    // 800031DC: fmr    f25, f26
    if (!ppc_fp_available(ctx, 0x800031DCu)) return;
    ctx->fpr[25] = ctx->fpr[26];

label_800031E0:
    ctx->pc = 0x800031E0u;
    // 800031E0: fneg    f27, f28
    if (!ppc_fp_available(ctx, 0x800031E0u)) return;
    ctx->fpr[27] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[28]) ^ 0x8000000000000000ull);

label_800031E4:
    ctx->pc = 0x800031E4u;
    // 800031E4: fabs    f29, f30
    if (!ppc_fp_available(ctx, 0x800031E4u)) return;
    ctx->fpr[29] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[30]) & 0x7FFFFFFFFFFFFFFFull);

label_800031E8:
    ctx->pc = 0x800031E8u;
    // 800031E8: fnabs    f31, f0
    if (!ppc_fp_available(ctx, 0x800031E8u)) return;
    ctx->fpr[31] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) | 0x8000000000000000ull);

label_800031EC:
    ctx->pc = 0x800031ECu;
    // 800031EC: frsp    f1, f2
    if (!ppc_fp_available(ctx, 0x800031ECu)) return;
    ctx->fpr[1] = (f64)(f32)ctx->fpr[2];

label_800031F0:
    ctx->pc = 0x800031F0u;
    // 800031F0: fsel   f1, f2, f3, f4
    if (!ppc_fp_available(ctx, 0x800031F0u)) return;
    {
        ctx->fpr[1] = (ctx->fpr[2] >= 0.0) ? ctx->fpr[3] : ctx->fpr[4];
    }

label_800031F4:
    ctx->pc = 0x800031F4u;
    // 800031F4: fcmpu   cr2, f3, f4
    if (!ppc_fp_available(ctx, 0x800031F4u)) return;
    {
        f64 val_a = ctx->fpr[3];
        f64 val_b = ctx->fpr[4];
        u32 cr_bits = 0;
        if (val_a < val_b)       cr_bits = 0x8u;
        else if (val_a > val_b)  cr_bits = 0x4u;
        else if (val_a == val_b) cr_bits = 0x2u;
        else                     cr_bits = 0x1u;
        ctx->cr = (ctx->cr & ~(0xFu << 20)) | (cr_bits << 20);
    }

label_800031F8:
    ctx->pc = 0x800031F8u;
    // 800031F8: fcmpo   cr3, f5, f6
    if (!ppc_fp_available(ctx, 0x800031F8u)) return;
    {
        f64 val_a = ctx->fpr[5];
        f64 val_b = ctx->fpr[6];
        u32 cr_bits = 0;
        if (val_a < val_b)       cr_bits = 0x8u;
        else if (val_a > val_b)  cr_bits = 0x4u;
        else if (val_a == val_b) cr_bits = 0x2u;
        else                     cr_bits = 0x1u;
        ctx->cr = (ctx->cr & ~(0xFu << 16)) | (cr_bits << 16);
    }

label_800031FC:
    ctx->pc = 0x800031FCu;
    // 800031FC: mtfsb0  31
    if (!ppc_fp_available(ctx, 0x800031FCu)) return;
    {
        u32 mask = 0x80000000u >> 31;
        if (31 != 1 && 31 != 2) ctx->fpscr &= ~mask;
    }

label_80003200:
    ctx->pc = 0x80003200u;
    // 80003200: mtfsb1  31
    if (!ppc_fp_available(ctx, 0x80003200u)) return;
    {
        u32 mask = 0x80000000u >> 31;
        if (31 != 1 && 31 != 2) ctx->fpscr |= mask;
    }

label_80003204:
    ctx->pc = 0x80003204u;
    // 80003204: psq_l   f1, 0(r4), 0, 0
    if (!ppc_fp_available(ctx, 0x80003204u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ppc_psq_load(ctx, 1u, ea, false, 0u, false, 0x80003204u);
        if (ctx->exception) return;
    }

label_80003208:
    ctx->pc = 0x80003208u;
    // 80003208: psq_lu   f3, 8(r4), 0, 0
    if (!ppc_fp_available(ctx, 0x80003208u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ppc_psq_load(ctx, 3u, ea, false, 0u, false, 0x80003208u);
        if (ctx->exception) return;
        ctx->gpr[4] = ea;
    }

label_8000320C:
    ctx->pc = 0x8000320Cu;
    // 8000320C: psq_st   f5, 16(r4), 0, 0
    if (!ppc_fp_available(ctx, 0x8000320Cu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ppc_psq_store(ctx, 5u, ea, false, 0u, false, 0x8000320Cu);
        if (ctx->exception) return;
    }

label_80003210:
    ctx->pc = 0x80003210u;
    // 80003210: psq_stu   f7, 24(r4), 0, 0
    if (!ppc_fp_available(ctx, 0x80003210u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        ppc_psq_store(ctx, 7u, ea, false, 0u, false, 0x80003210u);
        if (ctx->exception) return;
        ctx->gpr[4] = ea;
    }

label_80003214:
    ctx->pc = 0x80003214u;
    // 80003214: psq_lx   f9, r4, r5, 0, 0
    if (!ppc_fp_available(ctx, 0x80003214u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ppc_psq_load(ctx, 9u, ea, false, 0u, true, 0x80003214u);
        if (ctx->exception) return;
    }

label_80003218:
    ctx->pc = 0x80003218u;
    // 80003218: psq_lux   f11, r4, r5, 0, 0
    if (!ppc_fp_available(ctx, 0x80003218u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ppc_psq_load(ctx, 11u, ea, false, 0u, true, 0x80003218u);
        if (ctx->exception) return;
        ctx->gpr[4] = ea;
    }

label_8000321C:
    ctx->pc = 0x8000321Cu;
    // 8000321C: psq_stx   f13, r4, r5, 0, 0
    if (!ppc_fp_available(ctx, 0x8000321Cu)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ppc_psq_store(ctx, 13u, ea, false, 0u, true, 0x8000321Cu);
        if (ctx->exception) return;
    }

label_80003220:
    ctx->pc = 0x80003220u;
    // 80003220: psq_stux   f15, r4, r5, 0, 0
    if (!ppc_fp_available(ctx, 0x80003220u)) return;
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ppc_psq_store(ctx, 15u, ea, false, 0u, true, 0x80003220u);
        if (ctx->exception) return;
        ctx->gpr[4] = ea;
    }

label_80003224:
    ctx->pc = 0x80003224u;
    // 80003224: ps_add  f1, f2, f3
    if (!ppc_fp_available(ctx, 0x80003224u)) return;
    {
        ctx->fpr[1] = dolrecomp_ps_round((f32)ctx->fpr[2] + (f32)ctx->fpr[3]);
        ctx->ps1[1] = dolrecomp_ps_round((f32)ctx->ps1[2] + (f32)ctx->ps1[3]);
    }

label_80003228:
    ctx->pc = 0x80003228u;
    // 80003228: ps_sub  f4, f5, f6
    if (!ppc_fp_available(ctx, 0x80003228u)) return;
    {
        ctx->fpr[4] = dolrecomp_ps_round((f32)ctx->fpr[5] - (f32)ctx->fpr[6]);
        ctx->ps1[4] = dolrecomp_ps_round((f32)ctx->ps1[5] - (f32)ctx->ps1[6]);
    }

label_8000322C:
    ctx->pc = 0x8000322Cu;
    // 8000322C: ps_mul  f7, f8, f9
    if (!ppc_fp_available(ctx, 0x8000322Cu)) return;
    {
        ctx->fpr[7] = dolrecomp_ps_round((f32)ctx->fpr[8] * (f32)ctx->fpr[9]);
        ctx->ps1[7] = dolrecomp_ps_round((f32)ctx->ps1[8] * (f32)ctx->ps1[9]);
    }

label_80003230:
    ctx->pc = 0x80003230u;
    // 80003230: ps_div  f10, f11, f12
    if (!ppc_fp_available(ctx, 0x80003230u)) return;
    {
        ctx->fpr[10] = dolrecomp_ps_round((f32)ctx->fpr[11] / (f32)ctx->fpr[12]);
        ctx->ps1[10] = dolrecomp_ps_round((f32)ctx->ps1[11] / (f32)ctx->ps1[12]);
    }

label_80003234:
    ctx->pc = 0x80003234u;
    // 80003234: ps_madd  f13, f14, f15, f16
    if (!ppc_fp_available(ctx, 0x80003234u)) return;
    {
        f32 ps0 = (f32)ctx->fpr[14] * (f32)ctx->fpr[15];
        f32 ps1 = (f32)ctx->ps1[14] * (f32)ctx->ps1[15];
        ps0 += (f32)ctx->fpr[16];
        ps1 += (f32)ctx->ps1[16];
        ctx->fpr[13] = dolrecomp_ps_round(ps0);
        ctx->ps1[13] = dolrecomp_ps_round(ps1);
    }

label_80003238:
    ctx->pc = 0x80003238u;
    // 80003238: ps_msub  f17, f18, f19, f20
    if (!ppc_fp_available(ctx, 0x80003238u)) return;
    {
        f32 ps0 = (f32)ctx->fpr[18] * (f32)ctx->fpr[19];
        f32 ps1 = (f32)ctx->ps1[18] * (f32)ctx->ps1[19];
        ps0 -= (f32)ctx->fpr[20];
        ps1 -= (f32)ctx->ps1[20];
        ctx->fpr[17] = dolrecomp_ps_round(ps0);
        ctx->ps1[17] = dolrecomp_ps_round(ps1);
    }

label_8000323C:
    ctx->pc = 0x8000323Cu;
    // 8000323C: ps_nmadd  f21, f22, f23, f24
    if (!ppc_fp_available(ctx, 0x8000323Cu)) return;
    {
        f32 ps0 = (f32)ctx->fpr[22] * (f32)ctx->fpr[23];
        f32 ps1 = (f32)ctx->ps1[22] * (f32)ctx->ps1[23];
        ps0 += (f32)ctx->fpr[24];
        ps1 += (f32)ctx->ps1[24];
        ps0 = -ps0;
        ps1 = -ps1;
        ctx->fpr[21] = dolrecomp_ps_round(ps0);
        ctx->ps1[21] = dolrecomp_ps_round(ps1);
    }

label_80003240:
    ctx->pc = 0x80003240u;
    // 80003240: ps_nmsub  f25, f26, f27, f28
    if (!ppc_fp_available(ctx, 0x80003240u)) return;
    {
        f32 ps0 = (f32)ctx->fpr[26] * (f32)ctx->fpr[27];
        f32 ps1 = (f32)ctx->ps1[26] * (f32)ctx->ps1[27];
        ps0 -= (f32)ctx->fpr[28];
        ps1 -= (f32)ctx->ps1[28];
        ps0 = -ps0;
        ps1 = -ps1;
        ctx->fpr[25] = dolrecomp_ps_round(ps0);
        ctx->ps1[25] = dolrecomp_ps_round(ps1);
    }

label_80003244:
    ctx->pc = 0x80003244u;
    // 80003244: ps_neg  f1, f2
    if (!ppc_fp_available(ctx, 0x80003244u)) return;
    ctx->fpr[1] = dolrecomp_ps_from_bits(dolrecomp_ps_to_bits(ctx->fpr[2]) ^ 0x80000000u);
    ctx->ps1[1] = dolrecomp_ps_from_bits(dolrecomp_ps_to_bits(ctx->ps1[2]) ^ 0x80000000u);

label_80003248:
    ctx->pc = 0x80003248u;
    // 80003248: ps_abs  f3, f4
    if (!ppc_fp_available(ctx, 0x80003248u)) return;
    ctx->fpr[3] = dolrecomp_ps_from_bits(dolrecomp_ps_to_bits(ctx->fpr[4]) & 0x7FFFFFFFu);
    ctx->ps1[3] = dolrecomp_ps_from_bits(dolrecomp_ps_to_bits(ctx->ps1[4]) & 0x7FFFFFFFu);

label_8000324C:
    ctx->pc = 0x8000324Cu;
    // 8000324C: ps_nabs  f5, f6
    if (!ppc_fp_available(ctx, 0x8000324Cu)) return;
    ctx->fpr[5] = dolrecomp_ps_from_bits(dolrecomp_ps_to_bits(ctx->fpr[6]) | 0x80000000u);
    ctx->ps1[5] = dolrecomp_ps_from_bits(dolrecomp_ps_to_bits(ctx->ps1[6]) | 0x80000000u);

label_80003250:
    ctx->pc = 0x80003250u;
    // 80003250: ps_mr  f7, f8
    if (!ppc_fp_available(ctx, 0x80003250u)) return;
    ctx->fpr[7] = ctx->fpr[8];
    ctx->ps1[7] = ctx->ps1[8];

label_80003254:
    ctx->pc = 0x80003254u;
    // 80003254: ps_sum0  f9, f10, f11, f12
    if (!ppc_fp_available(ctx, 0x80003254u)) return;
    ctx->fpr[9] = dolrecomp_ps_round((f32)ctx->fpr[10] + (f32)ctx->ps1[12]);
    ctx->ps1[9] = dolrecomp_ps_round(ctx->ps1[11]);

label_80003258:
    ctx->pc = 0x80003258u;
    // 80003258: ps_sum1  f13, f14, f15, f16
    if (!ppc_fp_available(ctx, 0x80003258u)) return;
    ctx->fpr[13] = dolrecomp_ps_round(ctx->fpr[15]);
    ctx->ps1[13] = dolrecomp_ps_round((f32)ctx->fpr[14] + (f32)ctx->ps1[16]);

label_8000325C:
    ctx->pc = 0x8000325Cu;
    // 8000325C: ps_muls0  f17, f18, f19
    if (!ppc_fp_available(ctx, 0x8000325Cu)) return;
    ctx->fpr[17] = dolrecomp_ps_round((f32)ctx->fpr[18] * (f32)ctx->fpr[19]);
    ctx->ps1[17] = dolrecomp_ps_round((f32)ctx->ps1[18] * (f32)ctx->fpr[19]);

label_80003260:
    ctx->pc = 0x80003260u;
    // 80003260: ps_muls1  f20, f21, f22
    if (!ppc_fp_available(ctx, 0x80003260u)) return;
    ctx->fpr[20] = dolrecomp_ps_round((f32)ctx->fpr[21] * (f32)ctx->ps1[22]);
    ctx->ps1[20] = dolrecomp_ps_round((f32)ctx->ps1[21] * (f32)ctx->ps1[22]);

label_80003264:
    ctx->pc = 0x80003264u;
    // 80003264: ps_madds0  f23, f24, f25, f26
    if (!ppc_fp_available(ctx, 0x80003264u)) return;
    ctx->fpr[23] = dolrecomp_ps_round((f32)ctx->fpr[24] * (f32)ctx->fpr[25] + (f32)ctx->fpr[26]);
    ctx->ps1[23] = dolrecomp_ps_round((f32)ctx->ps1[24] * (f32)ctx->fpr[25] + (f32)ctx->ps1[26]);

label_80003268:
    ctx->pc = 0x80003268u;
    // 80003268: ps_madds1  f27, f28, f29, f30
    if (!ppc_fp_available(ctx, 0x80003268u)) return;
    ctx->fpr[27] = dolrecomp_ps_round((f32)ctx->fpr[28] * (f32)ctx->ps1[29] + (f32)ctx->fpr[30]);
    ctx->ps1[27] = dolrecomp_ps_round((f32)ctx->ps1[28] * (f32)ctx->ps1[29] + (f32)ctx->ps1[30]);

label_8000326C:
    ctx->pc = 0x8000326Cu;
    // 8000326C: ps_merge00  f1, f2, f3
    if (!ppc_fp_available(ctx, 0x8000326Cu)) return;
    ctx->fpr[1] = dolrecomp_ps_round(ctx->fpr[2]);
    ctx->ps1[1] = dolrecomp_ps_round(ctx->fpr[3]);

label_80003270:
    ctx->pc = 0x80003270u;
    // 80003270: ps_merge01  f4, f5, f6
    if (!ppc_fp_available(ctx, 0x80003270u)) return;
    ctx->fpr[4] = dolrecomp_ps_round(ctx->fpr[5]);
    ctx->ps1[4] = dolrecomp_ps_round(ctx->ps1[6]);

label_80003274:
    ctx->pc = 0x80003274u;
    // 80003274: ps_merge10  f7, f8, f9
    if (!ppc_fp_available(ctx, 0x80003274u)) return;
    ctx->fpr[7] = dolrecomp_ps_round(ctx->ps1[8]);
    ctx->ps1[7] = dolrecomp_ps_round(ctx->fpr[9]);

label_80003278:
    ctx->pc = 0x80003278u;
    // 80003278: ps_merge11  f10, f11, f12
    if (!ppc_fp_available(ctx, 0x80003278u)) return;
    ctx->fpr[10] = dolrecomp_ps_round(ctx->ps1[11]);
    ctx->ps1[10] = dolrecomp_ps_round(ctx->ps1[12]);

label_8000327C:
    ctx->pc = 0x8000327Cu;
    // 8000327C: ps_cmpu0 cr2, f13, f14
    if (!ppc_fp_available(ctx, 0x8000327Cu)) return;
    {
        f32 val_a = (f32)ctx->fpr[13];
        f32 val_b = (f32)ctx->fpr[14];
        u32 cr_bits = 0;
        if (val_a < val_b)       cr_bits = 0x8u;
        else if (val_a > val_b)  cr_bits = 0x4u;
        else if (val_a == val_b) cr_bits = 0x2u;
        else                     cr_bits = 0x1u;
        ctx->cr = (ctx->cr & ~(0xFu << 20)) | (cr_bits << 20);
    }

label_80003280:
    ctx->pc = 0x80003280u;
    // 80003280: ps_cmpo0 cr3, f15, f16
    if (!ppc_fp_available(ctx, 0x80003280u)) return;
    {
        f32 val_a = (f32)ctx->fpr[15];
        f32 val_b = (f32)ctx->fpr[16];
        u32 cr_bits = 0;
        if (val_a < val_b)       cr_bits = 0x8u;
        else if (val_a > val_b)  cr_bits = 0x4u;
        else if (val_a == val_b) cr_bits = 0x2u;
        else                     cr_bits = 0x1u;
        ctx->cr = (ctx->cr & ~(0xFu << 16)) | (cr_bits << 16);
    }

label_80003284:
    ctx->pc = 0x80003284u;
    // 80003284: ps_cmpu1 cr4, f17, f18
    if (!ppc_fp_available(ctx, 0x80003284u)) return;
    {
        f32 val_a = (f32)ctx->ps1[17];
        f32 val_b = (f32)ctx->ps1[18];
        u32 cr_bits = 0;
        if (val_a < val_b)       cr_bits = 0x8u;
        else if (val_a > val_b)  cr_bits = 0x4u;
        else if (val_a == val_b) cr_bits = 0x2u;
        else                     cr_bits = 0x1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_80003288:
    ctx->pc = 0x80003288u;
    // 80003288: ps_cmpo1 cr5, f19, f20
    if (!ppc_fp_available(ctx, 0x80003288u)) return;
    {
        f32 val_a = (f32)ctx->ps1[19];
        f32 val_b = (f32)ctx->ps1[20];
        u32 cr_bits = 0;
        if (val_a < val_b)       cr_bits = 0x8u;
        else if (val_a > val_b)  cr_bits = 0x4u;
        else if (val_a == val_b) cr_bits = 0x2u;
        else                     cr_bits = 0x1u;
        ctx->cr = (ctx->cr & ~(0xFu << 8)) | (cr_bits << 8);
    }

label_8000328C:
    ctx->pc = 0x8000328Cu;
    // 8000328C: ps_sel  f21, f22, f23, f24
    if (!ppc_fp_available(ctx, 0x8000328Cu)) return;
    ctx->fpr[21] = ((f32)ctx->fpr[22] >= 0.0f) ? ctx->fpr[23] : ctx->fpr[24];
    ctx->ps1[21] = ((f32)ctx->ps1[22] >= 0.0f) ? ctx->ps1[23] : ctx->ps1[24];

label_80003290:
    ctx->pc = 0x80003290u;
    // 80003290: mullw   r3, r4, r5
    {
        s64 product = (s64)(s32)ctx->gpr[4] * (s64)(s32)ctx->gpr[5];
        ctx->gpr[3] = (u32)product;
    }

label_80003294:
    ctx->pc = 0x80003294u;
    // 80003294: mulhw   r6, r7, r8
    {
        s64 product = (s64)(s32)ctx->gpr[7] * (s64)(s32)ctx->gpr[8];
        ctx->gpr[6] = (u32)(product >> 32);
    }

label_80003298:
    ctx->pc = 0x80003298u;
    // 80003298: mulhwu   r9, r10, r11
    {
        u64 product = (u64)ctx->gpr[10] * (u64)ctx->gpr[11];
        ctx->gpr[9] = (u32)(product >> 32);
    }

label_8000329C:
    ctx->pc = 0x8000329Cu;
    // 8000329C: divw   r12, r13, r14
    {
        s32 dividend = (s32)ctx->gpr[13];
        s32 divisor = (s32)ctx->gpr[14];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[12] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_800032A0:
    ctx->pc = 0x800032A0u;
    // 800032A0: divwu   r15, r16, r17
    {
        u32 divisor = ctx->gpr[17];
        ctx->gpr[15] = divisor == 0 ? 0u : ctx->gpr[16] / divisor;
    }

label_800032A4:
    ctx->pc = 0x800032A4u;
    // 800032A4: addme  r3, r4
    {
        u32 input = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 res = (u64)input + 0xFFFFFFFFull + carry;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | ((res >> 32) ? 0x20000000u : 0u);
    }

label_800032A8:
    ctx->pc = 0x800032A8u;
    // 800032A8: subfme  r5, r6
    {
        u32 input = ~ctx->gpr[6];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 res = (u64)input + 0xFFFFFFFFull + carry;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | ((res >> 32) ? 0x20000000u : 0u);
    }

label_800032AC:
    ctx->pc = 0x800032ACu;
    // 800032AC: lswi    r7, r12, 13
    {
        u32 ea = ctx->gpr[12];
        u32 count = 13u;
        for (u32 n = 0; n < count; n++) {
            u32 reg = (7u + n / 4u) & 31u;
            if ((n & 3u) == 0) ctx->gpr[reg] = 0;
            ctx->gpr[reg] |= (u32)mem_read8(ctx, ea + n) << (24u - 8u * (n & 3u));
        }
    }

label_800032B0:
    ctx->pc = 0x800032B0u;
    // 800032B0: lswx    r9, r20, r21
    {
        u32 ea = ctx->gpr[21];
        ea += ctx->gpr[20];
        u32 count = ctx->xer & 0x7Fu;
        u32 reg_count = (count + 3u) / 4u;
        for (u32 r = 0; r < reg_count; r++) {
            u32 reg = (9u + r) & 31u;
            if (reg == 20u || reg == 21u) {
                ppc_program_exception(ctx, PPC_PROGRAM_ILLEGAL, 0x800032B0u);
                return;
            }
        }
        for (u32 n = 0; n < count; n++) {
            u32 reg = (9u + n / 4u) & 31u;
            if ((n & 3u) == 0) ctx->gpr[reg] = 0;
            ctx->gpr[reg] |= (u32)mem_read8(ctx, ea + n) << (24u - 8u * (n & 3u));
        }
    }

label_800032B4:
    ctx->pc = 0x800032B4u;
    // 800032B4: stswi   r12, r13, 17
    {
        u32 ea = ctx->gpr[13];
        u32 count = 17u;
        for (u32 n = 0; n < count; n++) {
            u32 reg = (12u + n / 4u) & 31u;
            u8 value = (u8)(ctx->gpr[reg] >> (24u - 8u * (n & 3u)));
            mem_write8(ctx, ea + n, value);
        }
    }

label_800032B8:
    ctx->pc = 0x800032B8u;
    // 800032B8: stswx    r14, r15, r16
    {
        u32 ea = ctx->gpr[16] + ctx->gpr[15];
        u32 count = ctx->xer & 0x7Fu;
        for (u32 n = 0; n < count; n++) {
            u32 reg = (14u + n / 4u) & 31u;
            u8 value = (u8)(ctx->gpr[reg] >> (24u - 8u * (n & 3u)));
            mem_write8(ctx, ea + n, value);
        }
    }

label_800032BC:
    ctx->pc = 0x800032BCu;
    // 800032BC: lwarx    r17, r18, r19
    {
        u32 ea = ctx->gpr[18] + ctx->gpr[19];
        ctx->gpr[17] = mem_read32(ctx, ea);
        ctx->reserve_addr = ea;
        ctx->reserve_valid = true;
    }

label_800032C0:
    ctx->pc = 0x800032C0u;
    // 800032C0: stwcx.    r20, r21, r22
    {
        u32 ea = ctx->gpr[21] + ctx->gpr[22];
        bool success = ctx->reserve_valid && ea == ctx->reserve_addr;
        if (success) { mem_write32(ctx, ea, ctx->gpr[20]); ctx->reserve_valid = false; }
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | ((success ? 2u : 0u) << 28) | ((ctx->xer >> 3) & 0x10000000u);
    }

label_800032C4:
    ctx->pc = 0x800032C4u;
    // 800032C4: stfiwx    f23, r24, r25
    if (!ppc_fp_available(ctx, 0x800032C4u)) return;
    {
        u32 ea = ctx->gpr[24] + ctx->gpr[25];
        mem_write32(ctx, ea, (u32)dolrecomp_f64_to_bits(ctx->fpr[23]));
    }

label_800032C8:
    ctx->pc = 0x800032C8u;
    // 800032C8: fres    f1, f2
    if (!ppc_fp_available(ctx, 0x800032C8u)) return;
    { f64 result; if (ppc_fres(ctx, ctx->fpr[2], &result)) ctx->fpr[1] = ctx->ps1[1] = result; }

label_800032CC:
    ctx->pc = 0x800032CCu;
    // 800032CC: frsqrte    f3, f4
    if (!ppc_fp_available(ctx, 0x800032CCu)) return;
    { f64 result; if (ppc_frsqrte(ctx, ctx->fpr[4], &result)) ctx->fpr[3] = result; }

label_800032D0:
    ctx->pc = 0x800032D0u;
    // 800032D0: ps_res f5, f6
    if (!ppc_fp_available(ctx, 0x800032D0u)) return;
    { f64 a, b; ppc_ps_res(ctx, ctx->fpr[6], ctx->ps1[6], &a, &b); ctx->fpr[5] = dolrecomp_ps_round(a); ctx->ps1[5] = dolrecomp_ps_round(b); }

label_800032D4:
    ctx->pc = 0x800032D4u;
    // 800032D4: ps_rsqrte f7, f8
    if (!ppc_fp_available(ctx, 0x800032D4u)) return;
    { f64 a, b; ppc_ps_rsqrte(ctx, ctx->fpr[8], ctx->ps1[8], &a, &b); ctx->fpr[7] = dolrecomp_ps_round(a); ctx->ps1[7] = dolrecomp_ps_round(b); }

label_800032D8:
    ctx->pc = 0x800032D8u;
    // 800032D8: fctiw    f9, f10
    if (!ppc_fp_available(ctx, 0x800032D8u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[10], false, &result)) ctx->fpr[9] = dolrecomp_f64_from_bits(result); }

label_800032DC:
    ctx->pc = 0x800032DCu;
    // 800032DC: fctiwz    f11, f12
    if (!ppc_fp_available(ctx, 0x800032DCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[12], true, &result)) ctx->fpr[11] = dolrecomp_f64_from_bits(result); }

label_800032E0:
    ctx->pc = 0x800032E0u;
    // 800032E0: fmadd f13, f14, f15, f16
    if (!ppc_fp_available(ctx, 0x800032E0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[14], ctx->fpr[15], ctx->fpr[16], false, false, false, &result))
            ctx->fpr[13] = result;
    }

label_800032E4:
    ctx->pc = 0x800032E4u;
    // 800032E4: fmadds f17, f18, f19, f20
    if (!ppc_fp_available(ctx, 0x800032E4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[18], ctx->fpr[19], ctx->fpr[20], true, false, false, &result))
            ctx->fpr[17] = ctx->ps1[17] = result;
    }

label_800032E8:
    ctx->pc = 0x800032E8u;
    // 800032E8: fmsub f21, f22, f23, f24
    if (!ppc_fp_available(ctx, 0x800032E8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[22], ctx->fpr[23], ctx->fpr[24], false, true, false, &result))
            ctx->fpr[21] = result;
    }

label_800032EC:
    ctx->pc = 0x800032ECu;
    // 800032EC: fmsubs f25, f26, f27, f28
    if (!ppc_fp_available(ctx, 0x800032ECu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[26], ctx->fpr[27], ctx->fpr[28], true, true, false, &result))
            ctx->fpr[25] = ctx->ps1[25] = result;
    }

label_800032F0:
    ctx->pc = 0x800032F0u;
    // 800032F0: fnmadd f29, f30, f31, f0
    if (!ppc_fp_available(ctx, 0x800032F0u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[30], ctx->fpr[31], ctx->fpr[0], false, false, true, &result))
            ctx->fpr[29] = result;
    }

label_800032F4:
    ctx->pc = 0x800032F4u;
    // 800032F4: fnmadds f1, f2, f3, f4
    if (!ppc_fp_available(ctx, 0x800032F4u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[2], ctx->fpr[3], ctx->fpr[4], true, false, true, &result))
            ctx->fpr[1] = ctx->ps1[1] = result;
    }

label_800032F8:
    ctx->pc = 0x800032F8u;
    // 800032F8: fnmsub f5, f6, f7, f8
    if (!ppc_fp_available(ctx, 0x800032F8u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[6], ctx->fpr[7], ctx->fpr[8], false, true, true, &result))
            ctx->fpr[5] = result;
    }

label_800032FC:
    ctx->pc = 0x800032FCu;
    // 800032FC: fnmsubs f9, f10, f11, f12
    if (!ppc_fp_available(ctx, 0x800032FCu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[11], ctx->fpr[12], true, true, true, &result))
            ctx->fpr[9] = ctx->ps1[9] = result;
    }

label_80003300:
    ctx->pc = 0x80003300u;
    // 80003300: mffs   f13
    if (!ppc_fp_available(ctx, 0x80003300u)) return;
    ctx->fpr[13] = dolrecomp_f64_from_bits(0xFFF8000000000000ull | ctx->fpscr);

label_80003304:
    ctx->pc = 0x80003304u;
    // 80003304: mcrfs   cr2, cr3
    if (!ppc_fp_available(ctx, 0x80003304u)) return;
    {
        u32 field = (ctx->fpscr >> 16) & 0xFu;
        ctx->fpscr &= ~((0xFu << 16) & 0x83F80700u);
        ppc_fpscr_updated(ctx);
        ctx->cr = (ctx->cr & ~(0xFu << 20)) | (field << 20);
    }

label_80003308:
    ctx->pc = 0x80003308u;
    // 80003308: mtfsfi 4, 10
    if (!ppc_fp_available(ctx, 0x80003308u)) return;
    ctx->fpscr = (ctx->fpscr & ~(0xFu << 12)) | (0xAu << 12);
    ppc_fpscr_updated(ctx);

label_8000330C:
    ctx->pc = 0x8000330Cu;
    // 8000330C: mtfsf  0x5A, f14
    if (!ppc_fp_available(ctx, 0x8000330Cu)) return;
    {
        u32 mask = 0;
        for (u32 i = 0; i < 8; i++) if (0x5Au & (1u << i)) mask |= 0xFu << (i * 4);
        u32 source = (u32)dolrecomp_f64_to_bits(ctx->fpr[14]);
        ctx->fpscr = (ctx->fpscr & ~mask) | (source & mask);
        ppc_fpscr_updated(ctx);
    }

label_80003310:
    ctx->pc = 0x80003310u;
    // 80003310: sync
    ppc_memory_fence();

label_80003314:
    ctx->pc = 0x80003314u;
    // 80003314: eieio
    ppc_memory_fence();

label_80003318:
    ctx->pc = 0x80003318u;
    // 80003318: isync
    ppc_memory_fence();

label_8000331C:
    ctx->pc = 0x8000331Cu;
    // 8000331C: addo   r10, r11, r12
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[12];
        u32 res = a + b;
        ctx->gpr[10] = res;
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, b, res));
    }

label_80003320:
    ctx->pc = 0x80003320u;
    // 80003320: addco   r11, r12, r13
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[13];
        u64 wide = (u64)a + (u64)b;
        u32 res = (u32)wide;
        ctx->gpr[11] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, b, res));
    }

label_80003324:
    ctx->pc = 0x80003324u;
    // 80003324: addeo   r12, r13, r14
    {
        u32 carry = (ctx->xer >> 29) & 1u;
        u32 a = ctx->gpr[13];
        u32 b = ctx->gpr[14];
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[12] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, b, res));
    }

label_80003328:
    ctx->pc = 0x80003328u;
    // 80003328: addmeo  r13, r14
    {
        u32 input = ctx->gpr[14];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 res = (u64)input + 0xFFFFFFFFull + carry;
        ctx->gpr[13] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | ((res >> 32) ? 0x20000000u : 0u);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(input, 0xFFFFFFFFu, (u32)res));
    }

label_8000332C:
    ctx->pc = 0x8000332Cu;
    // 8000332C: addzeo  r14, r15
    {
        u32 a = ctx->gpr[15];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[14] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, 0u, res));
    }

label_80003330:
    ctx->pc = 0x80003330u;
    // 80003330: subfo   r15, r16, r17
    {
        u32 a = ~ctx->gpr[16];
        u32 b = ctx->gpr[17];
        u32 res = a + b + 1u;
        ctx->gpr[15] = res;
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, b, res));
    }

label_80003334:
    ctx->pc = 0x80003334u;
    // 80003334: subfco   r16, r17, r18
    {
        u32 a = ~ctx->gpr[17];
        u32 b = ctx->gpr[18];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[16] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, b, res));
    }

label_80003338:
    ctx->pc = 0x80003338u;
    // 80003338: subfeo   r17, r18, r19
    {
        u32 a = ~ctx->gpr[18];
        u32 b = ctx->gpr[19];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[17] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, b, res));
    }

label_8000333C:
    ctx->pc = 0x8000333Cu;
    // 8000333C: subfmeo  r18, r19
    {
        u32 input = ~ctx->gpr[19];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 res = (u64)input + 0xFFFFFFFFull + carry;
        ctx->gpr[18] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | ((res >> 32) ? 0x20000000u : 0u);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(input, 0xFFFFFFFFu, (u32)res));
    }

label_80003340:
    ctx->pc = 0x80003340u;
    // 80003340: subfzeo  r19, r20
    {
        u32 a = ~ctx->gpr[20];
        u64 wide = (u64)a + ((ctx->xer >> 29) & 1u);
        u32 res = (u32)wide;
        ctx->gpr[19] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
        ppc_set_xer_ov(ctx, ppc_add_overflowed(a, 0u, res));
    }

label_80003344:
    ctx->pc = 0x80003344u;
    // 80003344: nego  r20, r21
    {
        u32 a = ctx->gpr[21];
        ctx->gpr[20] = (~a) + 1u;
        ppc_set_xer_ov(ctx, a == 0x80000000u);
    }

label_80003348:
    ctx->pc = 0x80003348u;
    // 80003348: mullwo   r21, r22, r23
    {
        s64 product = (s64)(s32)ctx->gpr[22] * (s64)(s32)ctx->gpr[23];
        ctx->gpr[21] = (u32)product;
        ppc_set_xer_ov(ctx, product < -0x80000000ll || product > 0x7fffffffll);
    }

label_8000334C:
    ctx->pc = 0x8000334Cu;
    // 8000334C: divwo   r22, r23, r24
    {
        s32 dividend = (s32)ctx->gpr[23];
        s32 divisor = (s32)ctx->gpr[24];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[22] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
        ppc_set_xer_ov(ctx, ov);
    }

label_80003350:
    ctx->pc = 0x80003350u;
    // 80003350: divwuo   r23, r24, r25
    {
        u32 divisor = ctx->gpr[25];
        ctx->gpr[23] = divisor == 0 ? 0u : ctx->gpr[24] / divisor;
        ppc_set_xer_ov(ctx, divisor == 0);
    }

label_80003354:
    ctx->pc = 0x80003354u;
    // 80003354: twi     4, r5, -2
    if (ppc_trap_condition(4u, ctx->gpr[5], (u32)(s32)-2)) {
        ppc_program_exception(ctx, PPC_PROGRAM_TRAP, 0x80003354u);
        return;
    }

label_80003358:
    ctx->pc = 0x80003358u;
    // 80003358: tw      6, r7, r8
    if (ppc_trap_condition(6u, ctx->gpr[7], ctx->gpr[8])) {
        ppc_program_exception(ctx, PPC_PROGRAM_TRAP, 0x80003358u);
        return;
    }

label_8000335C:
    ctx->pc = 0x8000335Cu;
    // 8000335C: mcrxr   cr2
    {
        u32 bits = (ctx->xer >> 28) & 0xFu;
        ctx->cr = (ctx->cr & ~(0xFu << 20)) | (bits << 20);
        ctx->xer &= ~0xE0000000u;
    }

label_80003360:
    ctx->pc = 0x80003360u;
    // 80003360: mfmsr   r9
    ctx->gpr[9] = ctx->msr;

label_80003364:
    ctx->pc = 0x80003364u;
    // 80003364: mtmsr   r10
    ctx->msr = ctx->gpr[10];

label_80003368:
    ctx->pc = 0x80003368u;
    // 80003368: mfsr    r11, 3
    ctx->gpr[11] = ctx->sr[3];

label_8000336C:
    ctx->pc = 0x8000336Cu;
    // 8000336C: mfsrin  r12, r13
    ctx->gpr[12] = ctx->sr[(ctx->gpr[13] >> 28) & 0xFu];

label_80003370:
    ctx->pc = 0x80003370u;
    // 80003370: mtsr    4, r14
    ctx->sr[4] = ctx->gpr[14];

label_80003374:
    ctx->pc = 0x80003374u;
    // 80003374: mtsrin  r15, r16
    ctx->sr[(ctx->gpr[16] >> 28) & 0xFu] = ctx->gpr[15];

label_80003378:
    ctx->pc = 0x80003378u;
    // 80003378: dcbst    r17, r18
    ppc_fallback_instruction(ctx, 0x7C11906Cu, 0x80003378u);
    return;

label_8000337C:
    ctx->pc = 0x8000337Cu;
    // 8000337C: dcbf    r19, r20
    ppc_fallback_instruction(ctx, 0x7C13A0ACu, 0x8000337Cu);
    return;

label_80003380:
    ctx->pc = 0x80003380u;
    ctx->downcount -= 4;
    // 80003380: dcbtst    r21, r22
    (void)ctx;

label_80003384:
    ctx->pc = 0x80003384u;
    // 80003384: dcbt    r23, r24
    (void)ctx;

label_80003388:
    ctx->pc = 0x80003388u;
    // 80003388: dcbi    r25, r26
    ppc_fallback_instruction(ctx, 0x7C19D3ACu, 0x80003388u);
    return;

label_8000338C:
    ctx->pc = 0x8000338Cu;
    // 8000338C: icbi    r27, r28
    ppc_fallback_instruction(ctx, 0x7C1BE7ACu, 0x8000338Cu);
    return;

label_80003390:
    ctx->pc = 0x80003390u;
    ctx->downcount -= 3;
    // 80003390: tlbsync
    ppc_memory_fence();

label_80003394:
    ctx->pc = 0x80003394u;
    // 80003394: sc
    ppc_system_call_exception(ctx, 0x80003394u);
    return;

label_80003398:
    ctx->pc = 0x80003398u;
    ctx->downcount -= 2;
    // 80003398: rfi
    ppc_rfi(ctx, 0x80003398u);
    return;

label_8000339C:
    ctx->pc = 0x8000339Cu;
    ctx->downcount -= 5;
    // 8000339C: mftb    r3
    ctx->gpr[3] = ppc_mftb(ctx, 268u, 0x8000339Cu);
    if (ctx->exception) return;

label_800033A0:
    ctx->pc = 0x800033A0u;
    // 800033A0: dcbz_l    r5, r6
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[6];
        ppc_dcbz_l(ctx, ea, 0x800033A0u);
        if (ctx->exception) return;
    }

label_800033A4:
    ctx->pc = 0x800033A4u;
    // 800033A4: tlbie   r7
    ppc_tlbie(ctx, ctx->gpr[7], 0x800033A4u);
    if (ctx->exception) return;

label_800033A8:
    ctx->pc = 0x800033A8u;
    // 800033A8: eciwx   r8, r9, r10
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[10];
        u32 value = ppc_eciwx(ctx, ea, 0x800033A8u);
        if (ctx->exception) return;
        ctx->gpr[8] = value;
    }

label_800033AC:
    ctx->pc = 0x800033ACu;
    // 800033AC: ecowx   r11, r12, r13
    {
        u32 ea = ctx->gpr[12] + ctx->gpr[13];
        ppc_ecowx(ctx, ea, ctx->gpr[11], 0x800033ACu);
        if (ctx->exception) return;
    }

    ctx->pc = 0x800033B0u;
}

void func_80004000(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x80004000u: goto label_80004000;
    case 0x80004004u: goto label_80004004;
    case 0x80004008u: goto label_80004008;
    default: return;
    }
label_80004000:
    ctx->pc = 0x80004000u;
    ctx->downcount -= 1;
    // 80004000: b       0x80005000
    {
            ctx->pc = 0x80005000u;
            return;
    }

label_80004004:
    ctx->pc = 0x80004004u;
    ctx->downcount -= 1;
    // 80004004: bc    12, 2, 0x80005004
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x80005004u;
            return;
        }
    }

label_80004008:
    ctx->pc = 0x80004008u;
    ctx->downcount -= 1;
    // 80004008: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

    ctx->pc = 0x8000400Cu;
}

void func_8000400C(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8000400Cu: goto label_8000400C;
    case 0x80004010u: goto label_80004010;
    case 0x80004014u: goto label_80004014;
    default: return;
    }
label_8000400C:
    ctx->pc = 0x8000400Cu;
    ctx->downcount -= 1;
    // 8000400C: b       0x8000500C
    {
            ctx->pc = 0x8000500Cu;
            return;
    }

label_80004010:
    ctx->pc = 0x80004010u;
    ctx->downcount -= 1;
    // 80004010: bc    12, 2, 0x80005010
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x80005010u;
            return;
        }
    }

label_80004014:
    ctx->pc = 0x80004014u;
    ctx->downcount -= 1;
    // 80004014: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

    ctx->pc = 0x80004018u;
}

void func_80004018(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x80004018u: goto label_80004018;
    default: return;
    }
label_80004018:
    ctx->pc = 0x80004018u;
    ctx->downcount -= 1;
    // 80004018: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8000401Cu;
            ctx->pc = target;
            return;
        }
    }

    ctx->pc = 0x8000401Cu;
}

static void loop_80004020(CPUState* ctx) {
label_80004020:
    ctx->downcount -= 3;
    // 80004020: addi    r3, r3, -1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-1);

    // 80004024: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80004028: bc    4, 2, 0x80004020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80004020u;
                return;
            }
            goto label_80004020;
        }
    }

    ctx->pc = 0x8000402Cu;
}

void func_80004020(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x80004020u: goto label_80004020;
    case 0x80004024u: goto label_80004024;
    case 0x80004028u: goto label_80004028;
    case 0x8000402Cu: goto label_8000402C;
    default: return;
    }
label_80004020:
    loop_80004020(ctx);
    if (ctx->pc == 0x8000402Cu) goto label_8000402C;
    return;
label_80004024:
    // 80004024: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80004028:
    // 80004028: bc    4, 2, 0x80004020
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80004020u;
                return;
            }
            goto label_80004020;
        }
    }

label_8000402C:
    ctx->pc = 0x8000402Cu;
    ctx->downcount -= 1;
    // 8000402C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

    ctx->pc = 0x80004030u;
}

void func_80004030(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x80004030u: goto label_80004030;
    case 0x80004034u: goto label_80004034;
    case 0x80004038u: goto label_80004038;
    case 0x8000403Cu: goto label_8000403C;
    default: return;
    }
label_80004030:
    ctx->pc = 0x80004030u;
    ctx->downcount -= 1;
    // 80004030: bl      0x80004038
    {
            ctx->lr = 0x80004034u;
            goto label_80004038;
    }

label_80004034:
    ctx->pc = 0x80004034u;
    ctx->downcount -= 1;
    // 80004034: b       0x8000403C
    {
            goto label_8000403C;
    }

label_80004038:
    ctx->pc = 0x80004038u;
    ctx->downcount -= 1;
    // 80004038: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80004030;
        }
    }

label_8000403C:
    ctx->pc = 0x8000403Cu;
    ctx->downcount -= 1;
    // 8000403C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80004030;
        }
    }

    ctx->pc = 0x80004040u;
    return;
return_dispatch_80004030:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x80004034u: goto label_80004034;
    default: return;
    }
}

static void loop_80004040(CPUState* ctx) {
label_80004040:
    ctx->downcount -= 5;
    ctx->pc = 0x80004040u;
    // 80004040: lwz     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

    // 80004044: addi    r5, r5, 4
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(4);

    // 80004048: addi    r3, r3, -1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-1);

    // 8000404C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80004050: bc    4, 2, 0x80004040
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80004040u;
                return;
            }
            goto label_80004040;
        }
    }

    ctx->pc = 0x80004054u;
}

void func_80004040(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x80004040u: goto label_80004040;
    case 0x80004044u: goto label_80004044;
    case 0x80004048u: goto label_80004048;
    case 0x8000404Cu: goto label_8000404C;
    case 0x80004050u: goto label_80004050;
    case 0x80004054u: goto label_80004054;
    default: return;
    }
label_80004040:
    loop_80004040(ctx);
    if (ctx->pc == 0x80004054u) goto label_80004054;
    return;
label_80004044:
    // 80004044: addi    r5, r5, 4
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(4);

label_80004048:
    // 80004048: addi    r3, r3, -1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-1);

label_8000404C:
    // 8000404C: cmpwi   r3, 0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80004050:
    // 80004050: bc    4, 2, 0x80004040
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80004040u;
                return;
            }
            goto label_80004040;
        }
    }

label_80004054:
    ctx->pc = 0x80004054u;
    ctx->downcount -= 1;
    // 80004054: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

    ctx->pc = 0x80004058u;
}


#define DOLRECOMP_ENTRY_POINT 0x80003000u

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
    if (address >= 0x80003000u && address < 0x800033B0u && ((address - 0x80003000u) & 3u) == 0u) return func_80003000;
    {
        u32 offset = address - 0x80004000u;
        if (offset < 0x0000001Cu && (offset & 3u) == 0u) {
            static const DolRecompFunction chunk_functions[] = {
                func_80004000,
                func_8000400C,
                func_80004018,
            };
            return chunk_functions[offset / 0x0000000Cu];
        }
    }
    {
        u32 offset = address - 0x80004020u;
        if (offset < 0x00000020u && (offset & 3u) == 0u) {
            static const DolRecompFunction chunk_functions[] = {
                func_80004020,
                func_80004030,
            };
            return chunk_functions[offset / 0x00000010u];
        }
    }
    if (address >= 0x80004040u && address < 0x80004058u && ((address - 0x80004040u) & 3u) == 0u) return func_80004040;
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
