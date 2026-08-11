// DolRecomp output
#include "../generated.h"

static void loop_80003244(CPUState* ctx) {
label_80003244:
    ctx->downcount -= 5;
    // 80003244: addi    r6, r6, 4
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(4);

    ctx->pc = 0x80003248u;
    // 80003248: lwz     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

    // 8000324C: add   r7, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

    ctx->pc = 0x80003250u;
    // 80003250: stw     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

    // 80003254: bc    16, 0, 0x80003244
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003244u;
                return;
            }
            goto label_80003244;
        }
    }

    ctx->pc = 0x80003258u;
}

void func_80003100(CPUState* ctx) {
    switch (ctx->pc) {
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
    default: return;
    }
label_80003100:
    ctx->pc = 0x80003100u;
    ctx->downcount -= 7;
    // 80003100: lis     r1, -32693
    ctx->gpr[1] = ((u32)(s32)(-32693) << 16);

label_80003104:
    ctx->pc = 0x80003104u;
    // 80003104: ori     r1, r1, 0x1500
    ctx->gpr[1] = ctx->gpr[1] | 0x1500u;

label_80003108:
    ctx->pc = 0x80003108u;
    // 80003108: lis     r2, -32693
    ctx->gpr[2] = ((u32)(s32)(-32693) << 16);

label_8000310C:
    ctx->pc = 0x8000310Cu;
    // 8000310C: ori     r2, r2, 0x69E0
    ctx->gpr[2] = ctx->gpr[2] | 0x69E0u;

label_80003110:
    ctx->pc = 0x80003110u;
    // 80003110: lis     r13, -32694
    ctx->gpr[13] = ((u32)(s32)(-32694) << 16);

label_80003114:
    ctx->pc = 0x80003114u;
    // 80003114: ori     r13, r13, 0x69E0
    ctx->gpr[13] = ctx->gpr[13] | 0x69E0u;

label_80003118:
    ctx->pc = 0x80003118u;
    // 80003118: bl      0x8000326C
    {
            ctx->lr = 0x8000311Cu;
            goto label_8000326C;
    }

label_8000311C:
    ctx->pc = 0x8000311Cu;
    ctx->downcount -= 11;
    // 8000311C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80003120:
    ctx->pc = 0x80003120u;
    // 80003120: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80003124:
    ctx->pc = 0x80003124u;
    // 80003124: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80003128:
    ctx->pc = 0x80003128u;
    // 80003128: stw     r0, 0(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8000312C:
    ctx->pc = 0x8000312Cu;
    // 8000312C: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80003130:
    ctx->pc = 0x80003130u;
    // 80003130: addi    r4, r4, 20896
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(20896);

label_80003134:
    ctx->pc = 0x80003134u;
    // 80003134: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80003138:
    ctx->pc = 0x80003138u;
    // 80003138: lis     r6, -32694
    ctx->gpr[6] = ((u32)(s32)(-32694) << 16);

label_8000313C:
    ctx->pc = 0x8000313Cu;
    // 8000313C: addi    r6, r6, -5664
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-5664);

label_80003140:
    ctx->pc = 0x80003140u;
    // 80003140: subf   r6, r4, r6
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80003144:
    ctx->pc = 0x80003144u;
    // 80003144: bl      0x801698F0
    {
            ctx->lr = 0x80003148u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80003148:
    ctx->pc = 0x80003148u;
    ctx->downcount -= 7;
    // 80003148: lis     r4, -32694
    ctx->gpr[4] = ((u32)(s32)(-32694) << 16);

label_8000314C:
    ctx->pc = 0x8000314Cu;
    // 8000314C: addi    r4, r4, -1184
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-1184);

label_80003150:
    ctx->pc = 0x80003150u;
    // 80003150: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80003154:
    ctx->pc = 0x80003154u;
    // 80003154: lis     r6, -32694
    ctx->gpr[6] = ((u32)(s32)(-32694) << 16);

label_80003158:
    ctx->pc = 0x80003158u;
    // 80003158: addi    r6, r6, 1592
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(1592);

label_8000315C:
    ctx->pc = 0x8000315Cu;
    // 8000315C: subf   r6, r4, r6
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[6] = res;
    }

label_80003160:
    ctx->pc = 0x80003160u;
    // 80003160: bl      0x801698F0
    {
            ctx->lr = 0x80003164u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80003164:
    ctx->pc = 0x80003164u;
    ctx->downcount -= 9;
    // 80003164: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80003168:
    ctx->pc = 0x80003168u;
    // 80003168: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_8000316C:
    ctx->pc = 0x8000316Cu;
    // 8000316C: stw     r4, 68(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80003170:
    ctx->pc = 0x80003170u;
    // 80003170: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80003174:
    ctx->pc = 0x80003174u;
    // 80003174: lis     r6, -32768
    ctx->gpr[6] = ((u32)(s32)(-32768) << 16);

label_80003178:
    ctx->pc = 0x80003178u;
    // 80003178: addi    r6, r6, 244
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(244);

label_8000317C:
    ctx->pc = 0x8000317Cu;
    // 8000317C: lwz     r6, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80003180:
    ctx->pc = 0x80003180u;
    // 80003180: cmpwi   r6, 0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80003184:
    ctx->pc = 0x80003184u;
    // 80003184: bc    12, 2, 0x8000319C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8000319C;
        }
    }

label_80003188:
    ctx->pc = 0x80003188u;
    ctx->downcount -= 3;
    // 80003188: lwz     r3, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8000318C:
    ctx->pc = 0x8000318Cu;
    // 8000318C: cmplwi  r3, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80003190:
    ctx->pc = 0x80003190u;
    // 80003190: bc    12, 0, 0x8000319C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8000319C;
        }
    }

label_80003194:
    ctx->pc = 0x80003194u;
    ctx->downcount -= 1;
    // 80003194: bl      0x801620C8
    {
            ctx->lr = 0x80003198u;
            ctx->pc = 0x801620C8u;
            return;
    }

label_80003198:
    ctx->pc = 0x80003198u;
    ctx->downcount -= 1;
    // 80003198: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_8000319C:
    ctx->pc = 0x8000319Cu;
    ctx->downcount -= 1;
    // 8000319C: bl      0x80003200
    {
            ctx->lr = 0x800031A0u;
            goto label_80003200;
    }

label_800031A0:
    ctx->pc = 0x800031A0u;
    ctx->downcount -= 3;
    // 800031A0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800031A4:
    ctx->pc = 0x800031A4u;
    // 800031A4: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800031A8:
    ctx->pc = 0x800031A8u;
    // 800031A8: bl      0x8017ADA4
    {
            ctx->lr = 0x800031ACu;
            ctx->pc = 0x8017ADA4u;
            return;
    }

label_800031AC:
    ctx->pc = 0x800031ACu;
    ctx->downcount -= 1;
    // 800031AC: bl      0x8016F568
    {
            ctx->lr = 0x800031B0u;
            ctx->pc = 0x8016F568u;
            return;
    }

label_800031B0:
    ctx->pc = 0x800031B0u;
    ctx->downcount -= 2;
    // 800031B0: cmpwi   r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800031B4:
    ctx->pc = 0x800031B4u;
    // 800031B4: bc    12, 2, 0x800031F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800031F0;
        }
    }

label_800031B8:
    ctx->pc = 0x800031B8u;
    ctx->downcount -= 3;
    // 800031B8: lis     r3, -32733
    ctx->gpr[3] = ((u32)(s32)(-32733) << 16);

label_800031BC:
    ctx->pc = 0x800031BCu;
    // 800031BC: ori     r3, r3, 0xA920
    ctx->gpr[3] = ctx->gpr[3] | 0xA920u;

label_800031C0:
    ctx->pc = 0x800031C0u;
    // 800031C0: bl      0x80172A0C
    {
            ctx->lr = 0x800031C4u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_800031C4:
    ctx->pc = 0x800031C4u;
    ctx->downcount -= 16;
    // 800031C4: mfmsr   r5
    ctx->gpr[5] = ctx->msr;

label_800031C8:
    ctx->pc = 0x800031C8u;
    // 800031C8: ori     r4, r5, 0x8000
    ctx->gpr[4] = ctx->gpr[5] | 0x8000u;

label_800031CC:
    ctx->pc = 0x800031CCu;
    // 800031CC: xori    r4, r4, 0x8000
    ctx->gpr[4] = ctx->gpr[4] ^ 0x8000u;

label_800031D0:
    ctx->pc = 0x800031D0u;
    // 800031D0: mtmsr   r4
    ctx->msr = ctx->gpr[4];

label_800031D4:
    ctx->pc = 0x800031D4u;
    // 800031D4: sync
    ppc_memory_fence();

label_800031D8:
    ctx->pc = 0x800031D8u;
    // 800031D8: ori     r5, r5, 0x0200
    ctx->gpr[5] = ctx->gpr[5] | 0x0200u;

label_800031DC:
    ctx->pc = 0x800031DCu;
    // 800031DC: mtsrr1    r5
    ctx->srr1 = ctx->gpr[5];

label_800031E0:
    ctx->pc = 0x800031E0u;
    // 800031E0: lis     r4, -32768
    ctx->gpr[4] = ((u32)(s32)(-32768) << 16);

label_800031E4:
    ctx->pc = 0x800031E4u;
    // 800031E4: ori     r4, r4, 0x31F0
    ctx->gpr[4] = ctx->gpr[4] | 0x31F0u;

label_800031E8:
    ctx->pc = 0x800031E8u;
    // 800031E8: mtsrr0    r4
    ctx->srr0 = ctx->gpr[4];

label_800031EC:
    ctx->pc = 0x800031ECu;
    // 800031EC: rfi
    ppc_rfi(ctx, 0x800031ECu);
    return;

label_800031F0:
    ctx->pc = 0x800031F0u;
    ctx->downcount -= 3;
    // 800031F0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800031F4:
    ctx->pc = 0x800031F4u;
    // 800031F4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800031F8:
    ctx->pc = 0x800031F8u;
    // 800031F8: bl      0x8000BF70
    {
            ctx->lr = 0x800031FCu;
            ctx->pc = 0x8000BF70u;
            return;
    }

label_800031FC:
    ctx->pc = 0x800031FCu;
    ctx->downcount -= 1;
    // 800031FC: b       0x80166DA8
    {
            ctx->pc = 0x80166DA8u;
            return;
    }

label_80003200:
    ctx->pc = 0x80003200u;
    ctx->downcount -= 5;
    // 80003200: lis     r6, -32768
    ctx->gpr[6] = ((u32)(s32)(-32768) << 16);

label_80003204:
    ctx->pc = 0x80003204u;
    // 80003204: addi    r6, r6, 244
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(244);

label_80003208:
    ctx->pc = 0x80003208u;
    // 80003208: lwz     r5, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8000320C:
    ctx->pc = 0x8000320Cu;
    // 8000320C: cmpwi   r5, 0
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80003210:
    ctx->pc = 0x80003210u;
    // 80003210: bc    4, 2, 0x80003220
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80003220;
        }
    }

label_80003214:
    ctx->downcount -= 3;
    // 80003214: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80003218:
    // 80003218: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8000321C:
    ctx->pc = 0x8000321Cu;
    // 8000321C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_80003220:
    ctx->pc = 0x80003220u;
    ctx->downcount -= 3;
    // 80003220: lwz     r6, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80003224:
    // 80003224: cmpwi   r6, 0
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80003228:
    // 80003228: bc    12, 2, 0x80003214
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003214u;
                return;
            }
            goto label_80003214;
        }
    }

label_8000322C:
    ctx->downcount -= 4;
    // 8000322C: add   r6, r5, r6
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80003230:
    ctx->pc = 0x80003230u;
    // 80003230: lwz     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80003234:
    // 80003234: cmpwi   r3, 0
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

label_80003238:
    // 80003238: bc    12, 2, 0x80003214
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003214u;
                return;
            }
            goto label_80003214;
        }
    }

label_8000323C:
    ctx->pc = 0x8000323Cu;
    ctx->downcount -= 3;
    // 8000323C: addi    r4, r6, 4
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(4);

label_80003240:
    ctx->pc = 0x80003240u;
    // 80003240: mtctr    r3
    ctx->ctr = ctx->gpr[3];

label_80003244:
    loop_80003244(ctx);
    if (ctx->pc == 0x80003258u) goto label_80003258;
    return;
label_80003248:
    ctx->pc = 0x80003248u;
    // 80003248: lwz     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8000324C:
    // 8000324C: add   r7, r7, r5
    {
        u32 a = ctx->gpr[7];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_80003250:
    ctx->pc = 0x80003250u;
    // 80003250: stw     r7, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80003254:
    // 80003254: bc    16, 0, 0x80003244
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80003244u;
                return;
            }
            goto label_80003244;
        }
    }

label_80003258:
    ctx->pc = 0x80003258u;
    ctx->downcount -= 5;
    // 80003258: lis     r5, -32768
    ctx->gpr[5] = ((u32)(s32)(-32768) << 16);

label_8000325C:
    ctx->pc = 0x8000325Cu;
    // 8000325C: addi    r5, r5, 52
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(52);

label_80003260:
    ctx->pc = 0x80003260u;
    // 80003260: rlwinm r7, r4, 0, 0, 26
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_80003264:
    ctx->pc = 0x80003264u;
    // 80003264: stw     r7, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80003268:
    ctx->pc = 0x80003268u;
    // 80003268: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_8000326C:
    ctx->pc = 0x8000326Cu;
    ctx->downcount -= 5;
    // 8000326C: mfmsr   r0
    ctx->gpr[0] = ctx->msr;

label_80003270:
    ctx->pc = 0x80003270u;
    // 80003270: ori     r0, r0, 0x2000
    ctx->gpr[0] = ctx->gpr[0] | 0x2000u;

label_80003274:
    ctx->pc = 0x80003274u;
    // 80003274: mtmsr   r0
    ctx->msr = ctx->gpr[0];

label_80003278:
    ctx->pc = 0x80003278u;
    // 80003278: mflr    r31
    ctx->gpr[31] = ctx->lr;

label_8000327C:
    ctx->pc = 0x8000327Cu;
    // 8000327C: bl      0x8016FC80
    {
            ctx->lr = 0x80003280u;
            ctx->pc = 0x8016FC80u;
            return;
    }

label_80003280:
    ctx->pc = 0x80003280u;
    ctx->downcount -= 1;
    // 80003280: bl      0x80171F34
    {
            ctx->lr = 0x80003284u;
            ctx->pc = 0x80171F34u;
            return;
    }

label_80003284:
    ctx->pc = 0x80003284u;
    ctx->downcount -= 3;
    // 80003284: mtlr    r31
    ctx->lr = ctx->gpr[31];

label_80003288:
    ctx->pc = 0x80003288u;
    // 80003288: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

label_8000328C:
    ctx->pc = 0x8000328Cu;
    ctx->downcount -= 5;
    // 8000328C: lis     r5, -1
    ctx->gpr[5] = ((u32)(s32)(-1) << 16);

label_80003290:
    ctx->pc = 0x80003290u;
    // 80003290: ori     r5, r5, 0xFFF1
    ctx->gpr[5] = ctx->gpr[5] | 0xFFF1u;

label_80003294:
    ctx->pc = 0x80003294u;
    // 80003294: and   r5, r5, r3
    {
        ctx->gpr[5] = ctx->gpr[5] & ctx->gpr[3];
    }

label_80003298:
    ctx->pc = 0x80003298u;
    // 80003298: subf   r3, r5, r3
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_8000329C:
    ctx->pc = 0x8000329Cu;
    // 8000329C: add   r4, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_800032A0:
    ctx->pc = 0x800032A0u;
    // 800032A0: dcbst    0, r5
    ppc_fallback_instruction(ctx, 0x7C00286Cu, 0x800032A0u);
    return;

label_800032A4:
    ctx->pc = 0x800032A4u;
    ctx->downcount -= 3;
    // 800032A4: sync
    ppc_memory_fence();

label_800032A8:
    ctx->pc = 0x800032A8u;
    // 800032A8: icbi    0, r5
    ppc_fallback_instruction(ctx, 0x7C002FACu, 0x800032A8u);
    return;

label_800032AC:
    ctx->downcount -= 3;
    // 800032AC: addic   r5, r5, 8
    {
        u64 a = ctx->gpr[5];
        u64 b = (u32)(s32)(8);
        u64 res = a + b;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_800032B0:
    // 800032B0: addic.  r4, r4, -8
    {
        u64 a = ctx->gpr[4];
        u64 b = (u32)(s32)(-8);
        u64 res = a + b;
        ctx->gpr[4] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800032B4:
    // 800032B4: bc    4, 0, 0x800032A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800032A0u;
                return;
            }
            goto label_800032A0;
        }
    }

label_800032B8:
    ctx->pc = 0x800032B8u;
    ctx->downcount -= 2;
    // 800032B8: isync
    ppc_memory_fence();

label_800032BC:
    ctx->pc = 0x800032BCu;
    // 800032BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_80003100;
        }
    }

    ctx->pc = 0x800032C0u;
    return;
return_dispatch_80003100:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8000311Cu: goto label_8000311C;
    case 0x80003148u: goto label_80003148;
    case 0x80003164u: goto label_80003164;
    case 0x80003198u: goto label_80003198;
    case 0x800031A0u: goto label_800031A0;
    case 0x800031ACu: goto label_800031AC;
    case 0x800031B0u: goto label_800031B0;
    case 0x800031C4u: goto label_800031C4;
    case 0x800031FCu: goto label_800031FC;
    case 0x80003280u: goto label_80003280;
    case 0x80003284u: goto label_80003284;
    default: return;
    }
}

