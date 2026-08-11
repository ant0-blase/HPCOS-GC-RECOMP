// DolRecomp output
#include "../generated.h"

static void loop_80013CE8(CPUState* ctx) {
label_80013CE8:
    ctx->downcount -= 6;
    ctx->pc = 0x80013CE8u;
    // 80013CE8: lbzx    r0, r3, r31
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[31];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

    // 80013CEC: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

    // 80013CF0: add   r0, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

    // 80013CF4: cmpw    r31, r4
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

    // 80013CF8: add   r30, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

    // 80013CFC: bc    12, 0, 0x80013CE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013CE8u;
                return;
            }
            goto label_80013CE8;
        }
    }

    ctx->pc = 0x80013D00u;
}

static void loop_80014120(CPUState* ctx) {
label_80014120:
    ctx->downcount -= 16;
    ctx->pc = 0x80014120u;
    // 80014120: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80014124: addic.  r11, r11, -24
    {
        u64 a = ctx->gpr[11];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[11] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    ctx->pc = 0x80014128u;
    // 80014128: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8001412Cu;
    // 8001412C: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80014130u;
    // 80014130: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80014134u;
    // 80014134: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80014138u;
    // 80014138: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8001413Cu;
    // 8001413C: lwz     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80014140u;
    // 80014140: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80014144u;
    // 80014144: lwz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80014148u;
    // 80014148: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8001414Cu;
    // 8001414C: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 80014150: addi    r30, r30, 24
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(24);

    ctx->pc = 0x80014154u;
    // 80014154: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80014158: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

    // 8001415C: bc    4, 2, 0x80014120
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014120u;
                return;
            }
            goto label_80014120;
        }
    }

    ctx->pc = 0x80014160u;
}

static void loop_800162AC(CPUState* ctx) {
label_800162AC:
    ctx->downcount -= 3;
    ctx->pc = 0x800162ACu;
    // 800162AC: stb     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

    // 800162B0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

    // 800162B4: bc    16, 0, 0x800162AC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800162ACu;
                return;
            }
            goto label_800162AC;
        }
    }

    ctx->pc = 0x800162B8u;
}

static void loop_80016700(CPUState* ctx) {
label_80016700:
    ctx->downcount -= 5;
    ctx->pc = 0x80016700u;
    // 80016700: lwz     r9, 92(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80016704: add   r9, r11, r9
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

    ctx->pc = 0x80016708u;
    // 80016708: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8001670C: addi    r11, r11, 12
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(12);

    // 80016710: bc    16, 0, 0x80016700
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016700u;
                return;
            }
            goto label_80016700;
        }
    }

    ctx->pc = 0x80016714u;
}

static void loop_80016EF4(CPUState* ctx) {
label_80016EF4:
    ctx->downcount -= 3;
    ctx->pc = 0x80016EF4u;
    // 80016EF4: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80016EF8: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

    // 80016EFC: bc    16, 0, 0x80016EF4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016EF4u;
                return;
            }
            goto label_80016EF4;
        }
    }

    ctx->pc = 0x80016F00u;
}

static void loop_80017084(CPUState* ctx) {
label_80017084:
    ctx->downcount -= 9;
    ctx->pc = 0x80017084u;
    // 80017084: lwz     r11, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    // 80017088: addic.  r6, r6, -1
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8001708C: add   r11, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    ctx->pc = 0x80017090u;
    // 80017090: stw     r0, -8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x80017094u;
    // 80017094: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    // 80017098: add   r9, r10, r9
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

    ctx->pc = 0x8001709Cu;
    // 8001709C: stw     r0, -12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 800170A0: addi    r10, r10, -12
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(-12);

    // 800170A4: bc    12, 1, 0x80017084
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80017084u;
                return;
            }
            goto label_80017084;
        }
    }

    ctx->pc = 0x800170A8u;
}

static void loop_800170D4(CPUState* ctx) {
label_800170D4:
    ctx->downcount -= 12;
    ctx->pc = 0x800170D4u;
    // 800170D4: lwz     r7, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

    // 800170D8: addic.  r6, r6, -1
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 800170DC: add   r11, r5, r7
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

    // 800170E0: addi    r9, r11, -12
    ctx->gpr[9] = ctx->gpr[11] + (u32)(s32)(-12);

    ctx->pc = 0x800170E4u;
    // 800170E4: lwz     r0, -12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x800170E8u;
    // 800170E8: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x800170ECu;
    // 800170EC: lwz     r8, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x800170F0u;
    // 800170F0: stwx    r0, r5, r7
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x800170F4u;
    // 800170F4: stw     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

    // 800170F8: addi    r5, r5, -12
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-12);

    ctx->pc = 0x800170FCu;
    // 800170FC: stw     r8, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

    // 80017100: bc    12, 1, 0x800170D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800170D4u;
                return;
            }
            goto label_800170D4;
        }
    }

    ctx->pc = 0x80017104u;
}

void func_800132C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x800132C0u: goto label_800132C0;
    case 0x800132C4u: goto label_800132C4;
    case 0x800132C8u: goto label_800132C8;
    case 0x800132CCu: goto label_800132CC;
    case 0x800132D0u: goto label_800132D0;
    case 0x800132D4u: goto label_800132D4;
    case 0x800132D8u: goto label_800132D8;
    case 0x800132DCu: goto label_800132DC;
    case 0x800132E0u: goto label_800132E0;
    case 0x800132E4u: goto label_800132E4;
    case 0x800132E8u: goto label_800132E8;
    case 0x800132ECu: goto label_800132EC;
    case 0x800132F0u: goto label_800132F0;
    case 0x800132F4u: goto label_800132F4;
    case 0x800132F8u: goto label_800132F8;
    case 0x800132FCu: goto label_800132FC;
    case 0x80013300u: goto label_80013300;
    case 0x80013304u: goto label_80013304;
    case 0x80013308u: goto label_80013308;
    case 0x8001330Cu: goto label_8001330C;
    case 0x80013310u: goto label_80013310;
    case 0x80013314u: goto label_80013314;
    case 0x80013318u: goto label_80013318;
    case 0x8001331Cu: goto label_8001331C;
    case 0x80013320u: goto label_80013320;
    case 0x80013324u: goto label_80013324;
    case 0x80013328u: goto label_80013328;
    case 0x8001332Cu: goto label_8001332C;
    case 0x80013330u: goto label_80013330;
    case 0x80013334u: goto label_80013334;
    case 0x80013338u: goto label_80013338;
    case 0x8001333Cu: goto label_8001333C;
    case 0x80013340u: goto label_80013340;
    case 0x80013344u: goto label_80013344;
    case 0x80013348u: goto label_80013348;
    case 0x8001334Cu: goto label_8001334C;
    case 0x80013350u: goto label_80013350;
    case 0x80013354u: goto label_80013354;
    case 0x80013358u: goto label_80013358;
    case 0x8001335Cu: goto label_8001335C;
    case 0x80013360u: goto label_80013360;
    case 0x80013364u: goto label_80013364;
    case 0x80013368u: goto label_80013368;
    case 0x8001336Cu: goto label_8001336C;
    case 0x80013370u: goto label_80013370;
    case 0x80013374u: goto label_80013374;
    case 0x80013378u: goto label_80013378;
    case 0x8001337Cu: goto label_8001337C;
    case 0x80013380u: goto label_80013380;
    case 0x80013384u: goto label_80013384;
    case 0x80013388u: goto label_80013388;
    case 0x8001338Cu: goto label_8001338C;
    case 0x80013390u: goto label_80013390;
    case 0x80013394u: goto label_80013394;
    case 0x80013398u: goto label_80013398;
    case 0x8001339Cu: goto label_8001339C;
    case 0x800133A0u: goto label_800133A0;
    case 0x800133A4u: goto label_800133A4;
    case 0x800133A8u: goto label_800133A8;
    case 0x800133ACu: goto label_800133AC;
    case 0x800133B0u: goto label_800133B0;
    case 0x800133B4u: goto label_800133B4;
    case 0x800133B8u: goto label_800133B8;
    case 0x800133BCu: goto label_800133BC;
    case 0x800133C0u: goto label_800133C0;
    case 0x800133C4u: goto label_800133C4;
    case 0x800133C8u: goto label_800133C8;
    case 0x800133CCu: goto label_800133CC;
    case 0x800133D0u: goto label_800133D0;
    case 0x800133D4u: goto label_800133D4;
    case 0x800133D8u: goto label_800133D8;
    case 0x800133DCu: goto label_800133DC;
    case 0x800133E0u: goto label_800133E0;
    case 0x800133E4u: goto label_800133E4;
    case 0x800133E8u: goto label_800133E8;
    case 0x800133ECu: goto label_800133EC;
    case 0x800133F0u: goto label_800133F0;
    case 0x800133F4u: goto label_800133F4;
    case 0x800133F8u: goto label_800133F8;
    case 0x800133FCu: goto label_800133FC;
    case 0x80013400u: goto label_80013400;
    case 0x80013404u: goto label_80013404;
    case 0x80013408u: goto label_80013408;
    case 0x8001340Cu: goto label_8001340C;
    case 0x80013410u: goto label_80013410;
    case 0x80013414u: goto label_80013414;
    case 0x80013418u: goto label_80013418;
    case 0x8001341Cu: goto label_8001341C;
    case 0x80013420u: goto label_80013420;
    case 0x80013424u: goto label_80013424;
    case 0x80013428u: goto label_80013428;
    case 0x8001342Cu: goto label_8001342C;
    case 0x80013430u: goto label_80013430;
    case 0x80013434u: goto label_80013434;
    case 0x80013438u: goto label_80013438;
    case 0x8001343Cu: goto label_8001343C;
    case 0x80013440u: goto label_80013440;
    case 0x80013444u: goto label_80013444;
    case 0x80013448u: goto label_80013448;
    case 0x8001344Cu: goto label_8001344C;
    case 0x80013450u: goto label_80013450;
    case 0x80013454u: goto label_80013454;
    case 0x80013458u: goto label_80013458;
    case 0x8001345Cu: goto label_8001345C;
    case 0x80013460u: goto label_80013460;
    case 0x80013464u: goto label_80013464;
    case 0x80013468u: goto label_80013468;
    case 0x8001346Cu: goto label_8001346C;
    case 0x80013470u: goto label_80013470;
    case 0x80013474u: goto label_80013474;
    case 0x80013478u: goto label_80013478;
    case 0x8001347Cu: goto label_8001347C;
    case 0x80013480u: goto label_80013480;
    case 0x80013484u: goto label_80013484;
    case 0x80013488u: goto label_80013488;
    case 0x8001348Cu: goto label_8001348C;
    case 0x80013490u: goto label_80013490;
    case 0x80013494u: goto label_80013494;
    case 0x80013498u: goto label_80013498;
    case 0x8001349Cu: goto label_8001349C;
    case 0x800134A0u: goto label_800134A0;
    case 0x800134A4u: goto label_800134A4;
    case 0x800134A8u: goto label_800134A8;
    case 0x800134ACu: goto label_800134AC;
    case 0x800134B0u: goto label_800134B0;
    case 0x800134B4u: goto label_800134B4;
    case 0x800134B8u: goto label_800134B8;
    case 0x800134BCu: goto label_800134BC;
    case 0x800134C0u: goto label_800134C0;
    case 0x800134C4u: goto label_800134C4;
    case 0x800134C8u: goto label_800134C8;
    case 0x800134CCu: goto label_800134CC;
    case 0x800134D0u: goto label_800134D0;
    case 0x800134D4u: goto label_800134D4;
    case 0x800134D8u: goto label_800134D8;
    case 0x800134DCu: goto label_800134DC;
    case 0x800134E0u: goto label_800134E0;
    case 0x800134E4u: goto label_800134E4;
    case 0x800134E8u: goto label_800134E8;
    case 0x800134ECu: goto label_800134EC;
    case 0x800134F0u: goto label_800134F0;
    case 0x800134F4u: goto label_800134F4;
    case 0x800134F8u: goto label_800134F8;
    case 0x800134FCu: goto label_800134FC;
    case 0x80013500u: goto label_80013500;
    case 0x80013504u: goto label_80013504;
    case 0x80013508u: goto label_80013508;
    case 0x8001350Cu: goto label_8001350C;
    case 0x80013510u: goto label_80013510;
    case 0x80013514u: goto label_80013514;
    case 0x80013518u: goto label_80013518;
    case 0x8001351Cu: goto label_8001351C;
    case 0x80013520u: goto label_80013520;
    case 0x80013524u: goto label_80013524;
    case 0x80013528u: goto label_80013528;
    case 0x8001352Cu: goto label_8001352C;
    case 0x80013530u: goto label_80013530;
    case 0x80013534u: goto label_80013534;
    case 0x80013538u: goto label_80013538;
    case 0x8001353Cu: goto label_8001353C;
    case 0x80013540u: goto label_80013540;
    case 0x80013544u: goto label_80013544;
    case 0x80013548u: goto label_80013548;
    case 0x8001354Cu: goto label_8001354C;
    case 0x80013550u: goto label_80013550;
    case 0x80013554u: goto label_80013554;
    case 0x80013558u: goto label_80013558;
    case 0x8001355Cu: goto label_8001355C;
    case 0x80013560u: goto label_80013560;
    case 0x80013564u: goto label_80013564;
    case 0x80013568u: goto label_80013568;
    case 0x8001356Cu: goto label_8001356C;
    case 0x80013570u: goto label_80013570;
    case 0x80013574u: goto label_80013574;
    case 0x80013578u: goto label_80013578;
    case 0x8001357Cu: goto label_8001357C;
    case 0x80013580u: goto label_80013580;
    case 0x80013584u: goto label_80013584;
    case 0x80013588u: goto label_80013588;
    case 0x8001358Cu: goto label_8001358C;
    case 0x80013590u: goto label_80013590;
    case 0x80013594u: goto label_80013594;
    case 0x80013598u: goto label_80013598;
    case 0x8001359Cu: goto label_8001359C;
    case 0x800135A0u: goto label_800135A0;
    case 0x800135A4u: goto label_800135A4;
    case 0x800135A8u: goto label_800135A8;
    case 0x800135ACu: goto label_800135AC;
    case 0x800135B0u: goto label_800135B0;
    case 0x800135B4u: goto label_800135B4;
    case 0x800135B8u: goto label_800135B8;
    case 0x800135BCu: goto label_800135BC;
    case 0x800135C0u: goto label_800135C0;
    case 0x800135C4u: goto label_800135C4;
    case 0x800135C8u: goto label_800135C8;
    case 0x800135CCu: goto label_800135CC;
    case 0x800135D0u: goto label_800135D0;
    case 0x800135D4u: goto label_800135D4;
    case 0x800135D8u: goto label_800135D8;
    case 0x800135DCu: goto label_800135DC;
    case 0x800135E0u: goto label_800135E0;
    case 0x800135E4u: goto label_800135E4;
    case 0x800135E8u: goto label_800135E8;
    case 0x800135ECu: goto label_800135EC;
    case 0x800135F0u: goto label_800135F0;
    case 0x800135F4u: goto label_800135F4;
    case 0x800135F8u: goto label_800135F8;
    case 0x800135FCu: goto label_800135FC;
    case 0x80013600u: goto label_80013600;
    case 0x80013604u: goto label_80013604;
    case 0x80013608u: goto label_80013608;
    case 0x8001360Cu: goto label_8001360C;
    case 0x80013610u: goto label_80013610;
    case 0x80013614u: goto label_80013614;
    case 0x80013618u: goto label_80013618;
    case 0x8001361Cu: goto label_8001361C;
    case 0x80013620u: goto label_80013620;
    case 0x80013624u: goto label_80013624;
    case 0x80013628u: goto label_80013628;
    case 0x8001362Cu: goto label_8001362C;
    case 0x80013630u: goto label_80013630;
    case 0x80013634u: goto label_80013634;
    case 0x80013638u: goto label_80013638;
    case 0x8001363Cu: goto label_8001363C;
    case 0x80013640u: goto label_80013640;
    case 0x80013644u: goto label_80013644;
    case 0x80013648u: goto label_80013648;
    case 0x8001364Cu: goto label_8001364C;
    case 0x80013650u: goto label_80013650;
    case 0x80013654u: goto label_80013654;
    case 0x80013658u: goto label_80013658;
    case 0x8001365Cu: goto label_8001365C;
    case 0x80013660u: goto label_80013660;
    case 0x80013664u: goto label_80013664;
    case 0x80013668u: goto label_80013668;
    case 0x8001366Cu: goto label_8001366C;
    case 0x80013670u: goto label_80013670;
    case 0x80013674u: goto label_80013674;
    case 0x80013678u: goto label_80013678;
    case 0x8001367Cu: goto label_8001367C;
    case 0x80013680u: goto label_80013680;
    case 0x80013684u: goto label_80013684;
    case 0x80013688u: goto label_80013688;
    case 0x8001368Cu: goto label_8001368C;
    case 0x80013690u: goto label_80013690;
    case 0x80013694u: goto label_80013694;
    case 0x80013698u: goto label_80013698;
    case 0x8001369Cu: goto label_8001369C;
    case 0x800136A0u: goto label_800136A0;
    case 0x800136A4u: goto label_800136A4;
    case 0x800136A8u: goto label_800136A8;
    case 0x800136ACu: goto label_800136AC;
    case 0x800136B0u: goto label_800136B0;
    case 0x800136B4u: goto label_800136B4;
    case 0x800136B8u: goto label_800136B8;
    case 0x800136BCu: goto label_800136BC;
    case 0x800136C0u: goto label_800136C0;
    case 0x800136C4u: goto label_800136C4;
    case 0x800136C8u: goto label_800136C8;
    case 0x800136CCu: goto label_800136CC;
    case 0x800136D0u: goto label_800136D0;
    case 0x800136D4u: goto label_800136D4;
    case 0x800136D8u: goto label_800136D8;
    case 0x800136DCu: goto label_800136DC;
    case 0x800136E0u: goto label_800136E0;
    case 0x800136E4u: goto label_800136E4;
    case 0x800136E8u: goto label_800136E8;
    case 0x800136ECu: goto label_800136EC;
    case 0x800136F0u: goto label_800136F0;
    case 0x800136F4u: goto label_800136F4;
    case 0x800136F8u: goto label_800136F8;
    case 0x800136FCu: goto label_800136FC;
    case 0x80013700u: goto label_80013700;
    case 0x80013704u: goto label_80013704;
    case 0x80013708u: goto label_80013708;
    case 0x8001370Cu: goto label_8001370C;
    case 0x80013710u: goto label_80013710;
    case 0x80013714u: goto label_80013714;
    case 0x80013718u: goto label_80013718;
    case 0x8001371Cu: goto label_8001371C;
    case 0x80013720u: goto label_80013720;
    case 0x80013724u: goto label_80013724;
    case 0x80013728u: goto label_80013728;
    case 0x8001372Cu: goto label_8001372C;
    case 0x80013730u: goto label_80013730;
    case 0x80013734u: goto label_80013734;
    case 0x80013738u: goto label_80013738;
    case 0x8001373Cu: goto label_8001373C;
    case 0x80013740u: goto label_80013740;
    case 0x80013744u: goto label_80013744;
    case 0x80013748u: goto label_80013748;
    case 0x8001374Cu: goto label_8001374C;
    case 0x80013750u: goto label_80013750;
    case 0x80013754u: goto label_80013754;
    case 0x80013758u: goto label_80013758;
    case 0x8001375Cu: goto label_8001375C;
    case 0x80013760u: goto label_80013760;
    case 0x80013764u: goto label_80013764;
    case 0x80013768u: goto label_80013768;
    case 0x8001376Cu: goto label_8001376C;
    case 0x80013770u: goto label_80013770;
    case 0x80013774u: goto label_80013774;
    case 0x80013778u: goto label_80013778;
    case 0x8001377Cu: goto label_8001377C;
    case 0x80013780u: goto label_80013780;
    case 0x80013784u: goto label_80013784;
    case 0x80013788u: goto label_80013788;
    case 0x8001378Cu: goto label_8001378C;
    case 0x80013790u: goto label_80013790;
    case 0x80013794u: goto label_80013794;
    case 0x80013798u: goto label_80013798;
    case 0x8001379Cu: goto label_8001379C;
    case 0x800137A0u: goto label_800137A0;
    case 0x800137A4u: goto label_800137A4;
    case 0x800137A8u: goto label_800137A8;
    case 0x800137ACu: goto label_800137AC;
    case 0x800137B0u: goto label_800137B0;
    case 0x800137B4u: goto label_800137B4;
    case 0x800137B8u: goto label_800137B8;
    case 0x800137BCu: goto label_800137BC;
    case 0x800137C0u: goto label_800137C0;
    case 0x800137C4u: goto label_800137C4;
    case 0x800137C8u: goto label_800137C8;
    case 0x800137CCu: goto label_800137CC;
    case 0x800137D0u: goto label_800137D0;
    case 0x800137D4u: goto label_800137D4;
    case 0x800137D8u: goto label_800137D8;
    case 0x800137DCu: goto label_800137DC;
    case 0x800137E0u: goto label_800137E0;
    case 0x800137E4u: goto label_800137E4;
    case 0x800137E8u: goto label_800137E8;
    case 0x800137ECu: goto label_800137EC;
    case 0x800137F0u: goto label_800137F0;
    case 0x800137F4u: goto label_800137F4;
    case 0x800137F8u: goto label_800137F8;
    case 0x800137FCu: goto label_800137FC;
    case 0x80013800u: goto label_80013800;
    case 0x80013804u: goto label_80013804;
    case 0x80013808u: goto label_80013808;
    case 0x8001380Cu: goto label_8001380C;
    case 0x80013810u: goto label_80013810;
    case 0x80013814u: goto label_80013814;
    case 0x80013818u: goto label_80013818;
    case 0x8001381Cu: goto label_8001381C;
    case 0x80013820u: goto label_80013820;
    case 0x80013824u: goto label_80013824;
    case 0x80013828u: goto label_80013828;
    case 0x8001382Cu: goto label_8001382C;
    case 0x80013830u: goto label_80013830;
    case 0x80013834u: goto label_80013834;
    case 0x80013838u: goto label_80013838;
    case 0x8001383Cu: goto label_8001383C;
    case 0x80013840u: goto label_80013840;
    case 0x80013844u: goto label_80013844;
    case 0x80013848u: goto label_80013848;
    case 0x8001384Cu: goto label_8001384C;
    case 0x80013850u: goto label_80013850;
    case 0x80013854u: goto label_80013854;
    case 0x80013858u: goto label_80013858;
    case 0x8001385Cu: goto label_8001385C;
    case 0x80013860u: goto label_80013860;
    case 0x80013864u: goto label_80013864;
    case 0x80013868u: goto label_80013868;
    case 0x8001386Cu: goto label_8001386C;
    case 0x80013870u: goto label_80013870;
    case 0x80013874u: goto label_80013874;
    case 0x80013878u: goto label_80013878;
    case 0x8001387Cu: goto label_8001387C;
    case 0x80013880u: goto label_80013880;
    case 0x80013884u: goto label_80013884;
    case 0x80013888u: goto label_80013888;
    case 0x8001388Cu: goto label_8001388C;
    case 0x80013890u: goto label_80013890;
    case 0x80013894u: goto label_80013894;
    case 0x80013898u: goto label_80013898;
    case 0x8001389Cu: goto label_8001389C;
    case 0x800138A0u: goto label_800138A0;
    case 0x800138A4u: goto label_800138A4;
    case 0x800138A8u: goto label_800138A8;
    case 0x800138ACu: goto label_800138AC;
    case 0x800138B0u: goto label_800138B0;
    case 0x800138B4u: goto label_800138B4;
    case 0x800138B8u: goto label_800138B8;
    case 0x800138BCu: goto label_800138BC;
    case 0x800138C0u: goto label_800138C0;
    case 0x800138C4u: goto label_800138C4;
    case 0x800138C8u: goto label_800138C8;
    case 0x800138CCu: goto label_800138CC;
    case 0x800138D0u: goto label_800138D0;
    case 0x800138D4u: goto label_800138D4;
    case 0x800138D8u: goto label_800138D8;
    case 0x800138DCu: goto label_800138DC;
    case 0x800138E0u: goto label_800138E0;
    case 0x800138E4u: goto label_800138E4;
    case 0x800138E8u: goto label_800138E8;
    case 0x800138ECu: goto label_800138EC;
    case 0x800138F0u: goto label_800138F0;
    case 0x800138F4u: goto label_800138F4;
    case 0x800138F8u: goto label_800138F8;
    case 0x800138FCu: goto label_800138FC;
    case 0x80013900u: goto label_80013900;
    case 0x80013904u: goto label_80013904;
    case 0x80013908u: goto label_80013908;
    case 0x8001390Cu: goto label_8001390C;
    case 0x80013910u: goto label_80013910;
    case 0x80013914u: goto label_80013914;
    case 0x80013918u: goto label_80013918;
    case 0x8001391Cu: goto label_8001391C;
    case 0x80013920u: goto label_80013920;
    case 0x80013924u: goto label_80013924;
    case 0x80013928u: goto label_80013928;
    case 0x8001392Cu: goto label_8001392C;
    case 0x80013930u: goto label_80013930;
    case 0x80013934u: goto label_80013934;
    case 0x80013938u: goto label_80013938;
    case 0x8001393Cu: goto label_8001393C;
    case 0x80013940u: goto label_80013940;
    case 0x80013944u: goto label_80013944;
    case 0x80013948u: goto label_80013948;
    case 0x8001394Cu: goto label_8001394C;
    case 0x80013950u: goto label_80013950;
    case 0x80013954u: goto label_80013954;
    case 0x80013958u: goto label_80013958;
    case 0x8001395Cu: goto label_8001395C;
    case 0x80013960u: goto label_80013960;
    case 0x80013964u: goto label_80013964;
    case 0x80013968u: goto label_80013968;
    case 0x8001396Cu: goto label_8001396C;
    case 0x80013970u: goto label_80013970;
    case 0x80013974u: goto label_80013974;
    case 0x80013978u: goto label_80013978;
    case 0x8001397Cu: goto label_8001397C;
    case 0x80013980u: goto label_80013980;
    case 0x80013984u: goto label_80013984;
    case 0x80013988u: goto label_80013988;
    case 0x8001398Cu: goto label_8001398C;
    case 0x80013990u: goto label_80013990;
    case 0x80013994u: goto label_80013994;
    case 0x80013998u: goto label_80013998;
    case 0x8001399Cu: goto label_8001399C;
    case 0x800139A0u: goto label_800139A0;
    case 0x800139A4u: goto label_800139A4;
    case 0x800139A8u: goto label_800139A8;
    case 0x800139ACu: goto label_800139AC;
    case 0x800139B0u: goto label_800139B0;
    case 0x800139B4u: goto label_800139B4;
    case 0x800139B8u: goto label_800139B8;
    case 0x800139BCu: goto label_800139BC;
    case 0x800139C0u: goto label_800139C0;
    case 0x800139C4u: goto label_800139C4;
    case 0x800139C8u: goto label_800139C8;
    case 0x800139CCu: goto label_800139CC;
    case 0x800139D0u: goto label_800139D0;
    case 0x800139D4u: goto label_800139D4;
    case 0x800139D8u: goto label_800139D8;
    case 0x800139DCu: goto label_800139DC;
    case 0x800139E0u: goto label_800139E0;
    case 0x800139E4u: goto label_800139E4;
    case 0x800139E8u: goto label_800139E8;
    case 0x800139ECu: goto label_800139EC;
    case 0x800139F0u: goto label_800139F0;
    case 0x800139F4u: goto label_800139F4;
    case 0x800139F8u: goto label_800139F8;
    case 0x800139FCu: goto label_800139FC;
    case 0x80013A00u: goto label_80013A00;
    case 0x80013A04u: goto label_80013A04;
    case 0x80013A08u: goto label_80013A08;
    case 0x80013A0Cu: goto label_80013A0C;
    case 0x80013A10u: goto label_80013A10;
    case 0x80013A14u: goto label_80013A14;
    case 0x80013A18u: goto label_80013A18;
    case 0x80013A1Cu: goto label_80013A1C;
    case 0x80013A20u: goto label_80013A20;
    case 0x80013A24u: goto label_80013A24;
    case 0x80013A28u: goto label_80013A28;
    case 0x80013A2Cu: goto label_80013A2C;
    case 0x80013A30u: goto label_80013A30;
    case 0x80013A34u: goto label_80013A34;
    case 0x80013A38u: goto label_80013A38;
    case 0x80013A3Cu: goto label_80013A3C;
    case 0x80013A40u: goto label_80013A40;
    case 0x80013A44u: goto label_80013A44;
    case 0x80013A48u: goto label_80013A48;
    case 0x80013A4Cu: goto label_80013A4C;
    case 0x80013A50u: goto label_80013A50;
    case 0x80013A54u: goto label_80013A54;
    case 0x80013A58u: goto label_80013A58;
    case 0x80013A5Cu: goto label_80013A5C;
    case 0x80013A60u: goto label_80013A60;
    case 0x80013A64u: goto label_80013A64;
    case 0x80013A68u: goto label_80013A68;
    case 0x80013A6Cu: goto label_80013A6C;
    case 0x80013A70u: goto label_80013A70;
    case 0x80013A74u: goto label_80013A74;
    case 0x80013A78u: goto label_80013A78;
    case 0x80013A7Cu: goto label_80013A7C;
    case 0x80013A80u: goto label_80013A80;
    case 0x80013A84u: goto label_80013A84;
    case 0x80013A88u: goto label_80013A88;
    case 0x80013A8Cu: goto label_80013A8C;
    case 0x80013A90u: goto label_80013A90;
    case 0x80013A94u: goto label_80013A94;
    case 0x80013A98u: goto label_80013A98;
    case 0x80013A9Cu: goto label_80013A9C;
    case 0x80013AA0u: goto label_80013AA0;
    case 0x80013AA4u: goto label_80013AA4;
    case 0x80013AA8u: goto label_80013AA8;
    case 0x80013AACu: goto label_80013AAC;
    case 0x80013AB0u: goto label_80013AB0;
    case 0x80013AB4u: goto label_80013AB4;
    case 0x80013AB8u: goto label_80013AB8;
    case 0x80013ABCu: goto label_80013ABC;
    case 0x80013AC0u: goto label_80013AC0;
    case 0x80013AC4u: goto label_80013AC4;
    case 0x80013AC8u: goto label_80013AC8;
    case 0x80013ACCu: goto label_80013ACC;
    case 0x80013AD0u: goto label_80013AD0;
    case 0x80013AD4u: goto label_80013AD4;
    case 0x80013AD8u: goto label_80013AD8;
    case 0x80013ADCu: goto label_80013ADC;
    case 0x80013AE0u: goto label_80013AE0;
    case 0x80013AE4u: goto label_80013AE4;
    case 0x80013AE8u: goto label_80013AE8;
    case 0x80013AECu: goto label_80013AEC;
    case 0x80013AF0u: goto label_80013AF0;
    case 0x80013AF4u: goto label_80013AF4;
    case 0x80013AF8u: goto label_80013AF8;
    case 0x80013AFCu: goto label_80013AFC;
    case 0x80013B00u: goto label_80013B00;
    case 0x80013B04u: goto label_80013B04;
    case 0x80013B08u: goto label_80013B08;
    case 0x80013B0Cu: goto label_80013B0C;
    case 0x80013B10u: goto label_80013B10;
    case 0x80013B14u: goto label_80013B14;
    case 0x80013B18u: goto label_80013B18;
    case 0x80013B1Cu: goto label_80013B1C;
    case 0x80013B20u: goto label_80013B20;
    case 0x80013B24u: goto label_80013B24;
    case 0x80013B28u: goto label_80013B28;
    case 0x80013B2Cu: goto label_80013B2C;
    case 0x80013B30u: goto label_80013B30;
    case 0x80013B34u: goto label_80013B34;
    case 0x80013B38u: goto label_80013B38;
    case 0x80013B3Cu: goto label_80013B3C;
    case 0x80013B40u: goto label_80013B40;
    case 0x80013B44u: goto label_80013B44;
    case 0x80013B48u: goto label_80013B48;
    case 0x80013B4Cu: goto label_80013B4C;
    case 0x80013B50u: goto label_80013B50;
    case 0x80013B54u: goto label_80013B54;
    case 0x80013B58u: goto label_80013B58;
    case 0x80013B5Cu: goto label_80013B5C;
    case 0x80013B60u: goto label_80013B60;
    case 0x80013B64u: goto label_80013B64;
    case 0x80013B68u: goto label_80013B68;
    case 0x80013B6Cu: goto label_80013B6C;
    case 0x80013B70u: goto label_80013B70;
    case 0x80013B74u: goto label_80013B74;
    case 0x80013B78u: goto label_80013B78;
    case 0x80013B7Cu: goto label_80013B7C;
    case 0x80013B80u: goto label_80013B80;
    case 0x80013B84u: goto label_80013B84;
    case 0x80013B88u: goto label_80013B88;
    case 0x80013B8Cu: goto label_80013B8C;
    case 0x80013B90u: goto label_80013B90;
    case 0x80013B94u: goto label_80013B94;
    case 0x80013B98u: goto label_80013B98;
    case 0x80013B9Cu: goto label_80013B9C;
    case 0x80013BA0u: goto label_80013BA0;
    case 0x80013BA4u: goto label_80013BA4;
    case 0x80013BA8u: goto label_80013BA8;
    case 0x80013BACu: goto label_80013BAC;
    case 0x80013BB0u: goto label_80013BB0;
    case 0x80013BB4u: goto label_80013BB4;
    case 0x80013BB8u: goto label_80013BB8;
    case 0x80013BBCu: goto label_80013BBC;
    case 0x80013BC0u: goto label_80013BC0;
    case 0x80013BC4u: goto label_80013BC4;
    case 0x80013BC8u: goto label_80013BC8;
    case 0x80013BCCu: goto label_80013BCC;
    case 0x80013BD0u: goto label_80013BD0;
    case 0x80013BD4u: goto label_80013BD4;
    case 0x80013BD8u: goto label_80013BD8;
    case 0x80013BDCu: goto label_80013BDC;
    case 0x80013BE0u: goto label_80013BE0;
    case 0x80013BE4u: goto label_80013BE4;
    case 0x80013BE8u: goto label_80013BE8;
    case 0x80013BECu: goto label_80013BEC;
    case 0x80013BF0u: goto label_80013BF0;
    case 0x80013BF4u: goto label_80013BF4;
    case 0x80013BF8u: goto label_80013BF8;
    case 0x80013BFCu: goto label_80013BFC;
    case 0x80013C00u: goto label_80013C00;
    case 0x80013C04u: goto label_80013C04;
    case 0x80013C08u: goto label_80013C08;
    case 0x80013C0Cu: goto label_80013C0C;
    case 0x80013C10u: goto label_80013C10;
    case 0x80013C14u: goto label_80013C14;
    case 0x80013C18u: goto label_80013C18;
    case 0x80013C1Cu: goto label_80013C1C;
    case 0x80013C20u: goto label_80013C20;
    case 0x80013C24u: goto label_80013C24;
    case 0x80013C28u: goto label_80013C28;
    case 0x80013C2Cu: goto label_80013C2C;
    case 0x80013C30u: goto label_80013C30;
    case 0x80013C34u: goto label_80013C34;
    case 0x80013C38u: goto label_80013C38;
    case 0x80013C3Cu: goto label_80013C3C;
    case 0x80013C40u: goto label_80013C40;
    case 0x80013C44u: goto label_80013C44;
    case 0x80013C48u: goto label_80013C48;
    case 0x80013C4Cu: goto label_80013C4C;
    case 0x80013C50u: goto label_80013C50;
    case 0x80013C54u: goto label_80013C54;
    case 0x80013C58u: goto label_80013C58;
    case 0x80013C5Cu: goto label_80013C5C;
    case 0x80013C60u: goto label_80013C60;
    case 0x80013C64u: goto label_80013C64;
    case 0x80013C68u: goto label_80013C68;
    case 0x80013C6Cu: goto label_80013C6C;
    case 0x80013C70u: goto label_80013C70;
    case 0x80013C74u: goto label_80013C74;
    case 0x80013C78u: goto label_80013C78;
    case 0x80013C7Cu: goto label_80013C7C;
    case 0x80013C80u: goto label_80013C80;
    case 0x80013C84u: goto label_80013C84;
    case 0x80013C88u: goto label_80013C88;
    case 0x80013C8Cu: goto label_80013C8C;
    case 0x80013C90u: goto label_80013C90;
    case 0x80013C94u: goto label_80013C94;
    case 0x80013C98u: goto label_80013C98;
    case 0x80013C9Cu: goto label_80013C9C;
    case 0x80013CA0u: goto label_80013CA0;
    case 0x80013CA4u: goto label_80013CA4;
    case 0x80013CA8u: goto label_80013CA8;
    case 0x80013CACu: goto label_80013CAC;
    case 0x80013CB0u: goto label_80013CB0;
    case 0x80013CB4u: goto label_80013CB4;
    case 0x80013CB8u: goto label_80013CB8;
    case 0x80013CBCu: goto label_80013CBC;
    case 0x80013CC0u: goto label_80013CC0;
    case 0x80013CC4u: goto label_80013CC4;
    case 0x80013CC8u: goto label_80013CC8;
    case 0x80013CCCu: goto label_80013CCC;
    case 0x80013CD0u: goto label_80013CD0;
    case 0x80013CD4u: goto label_80013CD4;
    case 0x80013CD8u: goto label_80013CD8;
    case 0x80013CDCu: goto label_80013CDC;
    case 0x80013CE0u: goto label_80013CE0;
    case 0x80013CE4u: goto label_80013CE4;
    case 0x80013CE8u: goto label_80013CE8;
    case 0x80013CECu: goto label_80013CEC;
    case 0x80013CF0u: goto label_80013CF0;
    case 0x80013CF4u: goto label_80013CF4;
    case 0x80013CF8u: goto label_80013CF8;
    case 0x80013CFCu: goto label_80013CFC;
    case 0x80013D00u: goto label_80013D00;
    case 0x80013D04u: goto label_80013D04;
    case 0x80013D08u: goto label_80013D08;
    case 0x80013D0Cu: goto label_80013D0C;
    case 0x80013D10u: goto label_80013D10;
    case 0x80013D14u: goto label_80013D14;
    case 0x80013D18u: goto label_80013D18;
    case 0x80013D1Cu: goto label_80013D1C;
    case 0x80013D20u: goto label_80013D20;
    case 0x80013D24u: goto label_80013D24;
    case 0x80013D28u: goto label_80013D28;
    case 0x80013D2Cu: goto label_80013D2C;
    case 0x80013D30u: goto label_80013D30;
    case 0x80013D34u: goto label_80013D34;
    case 0x80013D38u: goto label_80013D38;
    case 0x80013D3Cu: goto label_80013D3C;
    case 0x80013D40u: goto label_80013D40;
    case 0x80013D44u: goto label_80013D44;
    case 0x80013D48u: goto label_80013D48;
    case 0x80013D4Cu: goto label_80013D4C;
    case 0x80013D50u: goto label_80013D50;
    case 0x80013D54u: goto label_80013D54;
    case 0x80013D58u: goto label_80013D58;
    case 0x80013D5Cu: goto label_80013D5C;
    case 0x80013D60u: goto label_80013D60;
    case 0x80013D64u: goto label_80013D64;
    case 0x80013D68u: goto label_80013D68;
    case 0x80013D6Cu: goto label_80013D6C;
    case 0x80013D70u: goto label_80013D70;
    case 0x80013D74u: goto label_80013D74;
    case 0x80013D78u: goto label_80013D78;
    case 0x80013D7Cu: goto label_80013D7C;
    case 0x80013D80u: goto label_80013D80;
    case 0x80013D84u: goto label_80013D84;
    case 0x80013D88u: goto label_80013D88;
    case 0x80013D8Cu: goto label_80013D8C;
    case 0x80013D90u: goto label_80013D90;
    case 0x80013D94u: goto label_80013D94;
    case 0x80013D98u: goto label_80013D98;
    case 0x80013D9Cu: goto label_80013D9C;
    case 0x80013DA0u: goto label_80013DA0;
    case 0x80013DA4u: goto label_80013DA4;
    case 0x80013DA8u: goto label_80013DA8;
    case 0x80013DACu: goto label_80013DAC;
    case 0x80013DB0u: goto label_80013DB0;
    case 0x80013DB4u: goto label_80013DB4;
    case 0x80013DB8u: goto label_80013DB8;
    case 0x80013DBCu: goto label_80013DBC;
    case 0x80013DC0u: goto label_80013DC0;
    case 0x80013DC4u: goto label_80013DC4;
    case 0x80013DC8u: goto label_80013DC8;
    case 0x80013DCCu: goto label_80013DCC;
    case 0x80013DD0u: goto label_80013DD0;
    case 0x80013DD4u: goto label_80013DD4;
    case 0x80013DD8u: goto label_80013DD8;
    case 0x80013DDCu: goto label_80013DDC;
    case 0x80013DE0u: goto label_80013DE0;
    case 0x80013DE4u: goto label_80013DE4;
    case 0x80013DE8u: goto label_80013DE8;
    case 0x80013DECu: goto label_80013DEC;
    case 0x80013DF0u: goto label_80013DF0;
    case 0x80013DF4u: goto label_80013DF4;
    case 0x80013DF8u: goto label_80013DF8;
    case 0x80013DFCu: goto label_80013DFC;
    case 0x80013E00u: goto label_80013E00;
    case 0x80013E04u: goto label_80013E04;
    case 0x80013E08u: goto label_80013E08;
    case 0x80013E0Cu: goto label_80013E0C;
    case 0x80013E10u: goto label_80013E10;
    case 0x80013E14u: goto label_80013E14;
    case 0x80013E18u: goto label_80013E18;
    case 0x80013E1Cu: goto label_80013E1C;
    case 0x80013E20u: goto label_80013E20;
    case 0x80013E24u: goto label_80013E24;
    case 0x80013E28u: goto label_80013E28;
    case 0x80013E2Cu: goto label_80013E2C;
    case 0x80013E30u: goto label_80013E30;
    case 0x80013E34u: goto label_80013E34;
    case 0x80013E38u: goto label_80013E38;
    case 0x80013E3Cu: goto label_80013E3C;
    case 0x80013E40u: goto label_80013E40;
    case 0x80013E44u: goto label_80013E44;
    case 0x80013E48u: goto label_80013E48;
    case 0x80013E4Cu: goto label_80013E4C;
    case 0x80013E50u: goto label_80013E50;
    case 0x80013E54u: goto label_80013E54;
    case 0x80013E58u: goto label_80013E58;
    case 0x80013E5Cu: goto label_80013E5C;
    case 0x80013E60u: goto label_80013E60;
    case 0x80013E64u: goto label_80013E64;
    case 0x80013E68u: goto label_80013E68;
    case 0x80013E6Cu: goto label_80013E6C;
    case 0x80013E70u: goto label_80013E70;
    case 0x80013E74u: goto label_80013E74;
    case 0x80013E78u: goto label_80013E78;
    case 0x80013E7Cu: goto label_80013E7C;
    case 0x80013E80u: goto label_80013E80;
    case 0x80013E84u: goto label_80013E84;
    case 0x80013E88u: goto label_80013E88;
    case 0x80013E8Cu: goto label_80013E8C;
    case 0x80013E90u: goto label_80013E90;
    case 0x80013E94u: goto label_80013E94;
    case 0x80013E98u: goto label_80013E98;
    case 0x80013E9Cu: goto label_80013E9C;
    case 0x80013EA0u: goto label_80013EA0;
    case 0x80013EA4u: goto label_80013EA4;
    case 0x80013EA8u: goto label_80013EA8;
    case 0x80013EACu: goto label_80013EAC;
    case 0x80013EB0u: goto label_80013EB0;
    case 0x80013EB4u: goto label_80013EB4;
    case 0x80013EB8u: goto label_80013EB8;
    case 0x80013EBCu: goto label_80013EBC;
    case 0x80013EC0u: goto label_80013EC0;
    case 0x80013EC4u: goto label_80013EC4;
    case 0x80013EC8u: goto label_80013EC8;
    case 0x80013ECCu: goto label_80013ECC;
    case 0x80013ED0u: goto label_80013ED0;
    case 0x80013ED4u: goto label_80013ED4;
    case 0x80013ED8u: goto label_80013ED8;
    case 0x80013EDCu: goto label_80013EDC;
    case 0x80013EE0u: goto label_80013EE0;
    case 0x80013EE4u: goto label_80013EE4;
    case 0x80013EE8u: goto label_80013EE8;
    case 0x80013EECu: goto label_80013EEC;
    case 0x80013EF0u: goto label_80013EF0;
    case 0x80013EF4u: goto label_80013EF4;
    case 0x80013EF8u: goto label_80013EF8;
    case 0x80013EFCu: goto label_80013EFC;
    case 0x80013F00u: goto label_80013F00;
    case 0x80013F04u: goto label_80013F04;
    case 0x80013F08u: goto label_80013F08;
    case 0x80013F0Cu: goto label_80013F0C;
    case 0x80013F10u: goto label_80013F10;
    case 0x80013F14u: goto label_80013F14;
    case 0x80013F18u: goto label_80013F18;
    case 0x80013F1Cu: goto label_80013F1C;
    case 0x80013F20u: goto label_80013F20;
    case 0x80013F24u: goto label_80013F24;
    case 0x80013F28u: goto label_80013F28;
    case 0x80013F2Cu: goto label_80013F2C;
    case 0x80013F30u: goto label_80013F30;
    case 0x80013F34u: goto label_80013F34;
    case 0x80013F38u: goto label_80013F38;
    case 0x80013F3Cu: goto label_80013F3C;
    case 0x80013F40u: goto label_80013F40;
    case 0x80013F44u: goto label_80013F44;
    case 0x80013F48u: goto label_80013F48;
    case 0x80013F4Cu: goto label_80013F4C;
    case 0x80013F50u: goto label_80013F50;
    case 0x80013F54u: goto label_80013F54;
    case 0x80013F58u: goto label_80013F58;
    case 0x80013F5Cu: goto label_80013F5C;
    case 0x80013F60u: goto label_80013F60;
    case 0x80013F64u: goto label_80013F64;
    case 0x80013F68u: goto label_80013F68;
    case 0x80013F6Cu: goto label_80013F6C;
    case 0x80013F70u: goto label_80013F70;
    case 0x80013F74u: goto label_80013F74;
    case 0x80013F78u: goto label_80013F78;
    case 0x80013F7Cu: goto label_80013F7C;
    case 0x80013F80u: goto label_80013F80;
    case 0x80013F84u: goto label_80013F84;
    case 0x80013F88u: goto label_80013F88;
    case 0x80013F8Cu: goto label_80013F8C;
    case 0x80013F90u: goto label_80013F90;
    case 0x80013F94u: goto label_80013F94;
    case 0x80013F98u: goto label_80013F98;
    case 0x80013F9Cu: goto label_80013F9C;
    case 0x80013FA0u: goto label_80013FA0;
    case 0x80013FA4u: goto label_80013FA4;
    case 0x80013FA8u: goto label_80013FA8;
    case 0x80013FACu: goto label_80013FAC;
    case 0x80013FB0u: goto label_80013FB0;
    case 0x80013FB4u: goto label_80013FB4;
    case 0x80013FB8u: goto label_80013FB8;
    case 0x80013FBCu: goto label_80013FBC;
    case 0x80013FC0u: goto label_80013FC0;
    case 0x80013FC4u: goto label_80013FC4;
    case 0x80013FC8u: goto label_80013FC8;
    case 0x80013FCCu: goto label_80013FCC;
    case 0x80013FD0u: goto label_80013FD0;
    case 0x80013FD4u: goto label_80013FD4;
    case 0x80013FD8u: goto label_80013FD8;
    case 0x80013FDCu: goto label_80013FDC;
    case 0x80013FE0u: goto label_80013FE0;
    case 0x80013FE4u: goto label_80013FE4;
    case 0x80013FE8u: goto label_80013FE8;
    case 0x80013FECu: goto label_80013FEC;
    case 0x80013FF0u: goto label_80013FF0;
    case 0x80013FF4u: goto label_80013FF4;
    case 0x80013FF8u: goto label_80013FF8;
    case 0x80013FFCu: goto label_80013FFC;
    case 0x80014000u: goto label_80014000;
    case 0x80014004u: goto label_80014004;
    case 0x80014008u: goto label_80014008;
    case 0x8001400Cu: goto label_8001400C;
    case 0x80014010u: goto label_80014010;
    case 0x80014014u: goto label_80014014;
    case 0x80014018u: goto label_80014018;
    case 0x8001401Cu: goto label_8001401C;
    case 0x80014020u: goto label_80014020;
    case 0x80014024u: goto label_80014024;
    case 0x80014028u: goto label_80014028;
    case 0x8001402Cu: goto label_8001402C;
    case 0x80014030u: goto label_80014030;
    case 0x80014034u: goto label_80014034;
    case 0x80014038u: goto label_80014038;
    case 0x8001403Cu: goto label_8001403C;
    case 0x80014040u: goto label_80014040;
    case 0x80014044u: goto label_80014044;
    case 0x80014048u: goto label_80014048;
    case 0x8001404Cu: goto label_8001404C;
    case 0x80014050u: goto label_80014050;
    case 0x80014054u: goto label_80014054;
    case 0x80014058u: goto label_80014058;
    case 0x8001405Cu: goto label_8001405C;
    case 0x80014060u: goto label_80014060;
    case 0x80014064u: goto label_80014064;
    case 0x80014068u: goto label_80014068;
    case 0x8001406Cu: goto label_8001406C;
    case 0x80014070u: goto label_80014070;
    case 0x80014074u: goto label_80014074;
    case 0x80014078u: goto label_80014078;
    case 0x8001407Cu: goto label_8001407C;
    case 0x80014080u: goto label_80014080;
    case 0x80014084u: goto label_80014084;
    case 0x80014088u: goto label_80014088;
    case 0x8001408Cu: goto label_8001408C;
    case 0x80014090u: goto label_80014090;
    case 0x80014094u: goto label_80014094;
    case 0x80014098u: goto label_80014098;
    case 0x8001409Cu: goto label_8001409C;
    case 0x800140A0u: goto label_800140A0;
    case 0x800140A4u: goto label_800140A4;
    case 0x800140A8u: goto label_800140A8;
    case 0x800140ACu: goto label_800140AC;
    case 0x800140B0u: goto label_800140B0;
    case 0x800140B4u: goto label_800140B4;
    case 0x800140B8u: goto label_800140B8;
    case 0x800140BCu: goto label_800140BC;
    case 0x800140C0u: goto label_800140C0;
    case 0x800140C4u: goto label_800140C4;
    case 0x800140C8u: goto label_800140C8;
    case 0x800140CCu: goto label_800140CC;
    case 0x800140D0u: goto label_800140D0;
    case 0x800140D4u: goto label_800140D4;
    case 0x800140D8u: goto label_800140D8;
    case 0x800140DCu: goto label_800140DC;
    case 0x800140E0u: goto label_800140E0;
    case 0x800140E4u: goto label_800140E4;
    case 0x800140E8u: goto label_800140E8;
    case 0x800140ECu: goto label_800140EC;
    case 0x800140F0u: goto label_800140F0;
    case 0x800140F4u: goto label_800140F4;
    case 0x800140F8u: goto label_800140F8;
    case 0x800140FCu: goto label_800140FC;
    case 0x80014100u: goto label_80014100;
    case 0x80014104u: goto label_80014104;
    case 0x80014108u: goto label_80014108;
    case 0x8001410Cu: goto label_8001410C;
    case 0x80014110u: goto label_80014110;
    case 0x80014114u: goto label_80014114;
    case 0x80014118u: goto label_80014118;
    case 0x8001411Cu: goto label_8001411C;
    case 0x80014120u: goto label_80014120;
    case 0x80014124u: goto label_80014124;
    case 0x80014128u: goto label_80014128;
    case 0x8001412Cu: goto label_8001412C;
    case 0x80014130u: goto label_80014130;
    case 0x80014134u: goto label_80014134;
    case 0x80014138u: goto label_80014138;
    case 0x8001413Cu: goto label_8001413C;
    case 0x80014140u: goto label_80014140;
    case 0x80014144u: goto label_80014144;
    case 0x80014148u: goto label_80014148;
    case 0x8001414Cu: goto label_8001414C;
    case 0x80014150u: goto label_80014150;
    case 0x80014154u: goto label_80014154;
    case 0x80014158u: goto label_80014158;
    case 0x8001415Cu: goto label_8001415C;
    case 0x80014160u: goto label_80014160;
    case 0x80014164u: goto label_80014164;
    case 0x80014168u: goto label_80014168;
    case 0x8001416Cu: goto label_8001416C;
    case 0x80014170u: goto label_80014170;
    case 0x80014174u: goto label_80014174;
    case 0x80014178u: goto label_80014178;
    case 0x8001417Cu: goto label_8001417C;
    case 0x80014180u: goto label_80014180;
    case 0x80014184u: goto label_80014184;
    case 0x80014188u: goto label_80014188;
    case 0x8001418Cu: goto label_8001418C;
    case 0x80014190u: goto label_80014190;
    case 0x80014194u: goto label_80014194;
    case 0x80014198u: goto label_80014198;
    case 0x8001419Cu: goto label_8001419C;
    case 0x800141A0u: goto label_800141A0;
    case 0x800141A4u: goto label_800141A4;
    case 0x800141A8u: goto label_800141A8;
    case 0x800141ACu: goto label_800141AC;
    case 0x800141B0u: goto label_800141B0;
    case 0x800141B4u: goto label_800141B4;
    case 0x800141B8u: goto label_800141B8;
    case 0x800141BCu: goto label_800141BC;
    case 0x800141C0u: goto label_800141C0;
    case 0x800141C4u: goto label_800141C4;
    case 0x800141C8u: goto label_800141C8;
    case 0x800141CCu: goto label_800141CC;
    case 0x800141D0u: goto label_800141D0;
    case 0x800141D4u: goto label_800141D4;
    case 0x800141D8u: goto label_800141D8;
    case 0x800141DCu: goto label_800141DC;
    case 0x800141E0u: goto label_800141E0;
    case 0x800141E4u: goto label_800141E4;
    case 0x800141E8u: goto label_800141E8;
    case 0x800141ECu: goto label_800141EC;
    case 0x800141F0u: goto label_800141F0;
    case 0x800141F4u: goto label_800141F4;
    case 0x800141F8u: goto label_800141F8;
    case 0x800141FCu: goto label_800141FC;
    case 0x80014200u: goto label_80014200;
    case 0x80014204u: goto label_80014204;
    case 0x80014208u: goto label_80014208;
    case 0x8001420Cu: goto label_8001420C;
    case 0x80014210u: goto label_80014210;
    case 0x80014214u: goto label_80014214;
    case 0x80014218u: goto label_80014218;
    case 0x8001421Cu: goto label_8001421C;
    case 0x80014220u: goto label_80014220;
    case 0x80014224u: goto label_80014224;
    case 0x80014228u: goto label_80014228;
    case 0x8001422Cu: goto label_8001422C;
    case 0x80014230u: goto label_80014230;
    case 0x80014234u: goto label_80014234;
    case 0x80014238u: goto label_80014238;
    case 0x8001423Cu: goto label_8001423C;
    case 0x80014240u: goto label_80014240;
    case 0x80014244u: goto label_80014244;
    case 0x80014248u: goto label_80014248;
    case 0x8001424Cu: goto label_8001424C;
    case 0x80014250u: goto label_80014250;
    case 0x80014254u: goto label_80014254;
    case 0x80014258u: goto label_80014258;
    case 0x8001425Cu: goto label_8001425C;
    case 0x80014260u: goto label_80014260;
    case 0x80014264u: goto label_80014264;
    case 0x80014268u: goto label_80014268;
    case 0x8001426Cu: goto label_8001426C;
    case 0x80014270u: goto label_80014270;
    case 0x80014274u: goto label_80014274;
    case 0x80014278u: goto label_80014278;
    case 0x8001427Cu: goto label_8001427C;
    case 0x80014280u: goto label_80014280;
    case 0x80014284u: goto label_80014284;
    case 0x80014288u: goto label_80014288;
    case 0x8001428Cu: goto label_8001428C;
    case 0x80014290u: goto label_80014290;
    case 0x80014294u: goto label_80014294;
    case 0x80014298u: goto label_80014298;
    case 0x8001429Cu: goto label_8001429C;
    case 0x800142A0u: goto label_800142A0;
    case 0x800142A4u: goto label_800142A4;
    case 0x800142A8u: goto label_800142A8;
    case 0x800142ACu: goto label_800142AC;
    case 0x800142B0u: goto label_800142B0;
    case 0x800142B4u: goto label_800142B4;
    case 0x800142B8u: goto label_800142B8;
    case 0x800142BCu: goto label_800142BC;
    case 0x800142C0u: goto label_800142C0;
    case 0x800142C4u: goto label_800142C4;
    case 0x800142C8u: goto label_800142C8;
    case 0x800142CCu: goto label_800142CC;
    case 0x800142D0u: goto label_800142D0;
    case 0x800142D4u: goto label_800142D4;
    case 0x800142D8u: goto label_800142D8;
    case 0x800142DCu: goto label_800142DC;
    case 0x800142E0u: goto label_800142E0;
    case 0x800142E4u: goto label_800142E4;
    case 0x800142E8u: goto label_800142E8;
    case 0x800142ECu: goto label_800142EC;
    case 0x800142F0u: goto label_800142F0;
    case 0x800142F4u: goto label_800142F4;
    case 0x800142F8u: goto label_800142F8;
    case 0x800142FCu: goto label_800142FC;
    case 0x80014300u: goto label_80014300;
    case 0x80014304u: goto label_80014304;
    case 0x80014308u: goto label_80014308;
    case 0x8001430Cu: goto label_8001430C;
    case 0x80014310u: goto label_80014310;
    case 0x80014314u: goto label_80014314;
    case 0x80014318u: goto label_80014318;
    case 0x8001431Cu: goto label_8001431C;
    case 0x80014320u: goto label_80014320;
    case 0x80014324u: goto label_80014324;
    case 0x80014328u: goto label_80014328;
    case 0x8001432Cu: goto label_8001432C;
    case 0x80014330u: goto label_80014330;
    case 0x80014334u: goto label_80014334;
    case 0x80014338u: goto label_80014338;
    case 0x8001433Cu: goto label_8001433C;
    case 0x80014340u: goto label_80014340;
    case 0x80014344u: goto label_80014344;
    case 0x80014348u: goto label_80014348;
    case 0x8001434Cu: goto label_8001434C;
    case 0x80014350u: goto label_80014350;
    case 0x80014354u: goto label_80014354;
    case 0x80014358u: goto label_80014358;
    case 0x8001435Cu: goto label_8001435C;
    case 0x80014360u: goto label_80014360;
    case 0x80014364u: goto label_80014364;
    case 0x80014368u: goto label_80014368;
    case 0x8001436Cu: goto label_8001436C;
    case 0x80014370u: goto label_80014370;
    case 0x80014374u: goto label_80014374;
    case 0x80014378u: goto label_80014378;
    case 0x8001437Cu: goto label_8001437C;
    case 0x80014380u: goto label_80014380;
    case 0x80014384u: goto label_80014384;
    case 0x80014388u: goto label_80014388;
    case 0x8001438Cu: goto label_8001438C;
    case 0x80014390u: goto label_80014390;
    case 0x80014394u: goto label_80014394;
    case 0x80014398u: goto label_80014398;
    case 0x8001439Cu: goto label_8001439C;
    case 0x800143A0u: goto label_800143A0;
    case 0x800143A4u: goto label_800143A4;
    case 0x800143A8u: goto label_800143A8;
    case 0x800143ACu: goto label_800143AC;
    case 0x800143B0u: goto label_800143B0;
    case 0x800143B4u: goto label_800143B4;
    case 0x800143B8u: goto label_800143B8;
    case 0x800143BCu: goto label_800143BC;
    case 0x800143C0u: goto label_800143C0;
    case 0x800143C4u: goto label_800143C4;
    case 0x800143C8u: goto label_800143C8;
    case 0x800143CCu: goto label_800143CC;
    case 0x800143D0u: goto label_800143D0;
    case 0x800143D4u: goto label_800143D4;
    case 0x800143D8u: goto label_800143D8;
    case 0x800143DCu: goto label_800143DC;
    case 0x800143E0u: goto label_800143E0;
    case 0x800143E4u: goto label_800143E4;
    case 0x800143E8u: goto label_800143E8;
    case 0x800143ECu: goto label_800143EC;
    case 0x800143F0u: goto label_800143F0;
    case 0x800143F4u: goto label_800143F4;
    case 0x800143F8u: goto label_800143F8;
    case 0x800143FCu: goto label_800143FC;
    case 0x80014400u: goto label_80014400;
    case 0x80014404u: goto label_80014404;
    case 0x80014408u: goto label_80014408;
    case 0x8001440Cu: goto label_8001440C;
    case 0x80014410u: goto label_80014410;
    case 0x80014414u: goto label_80014414;
    case 0x80014418u: goto label_80014418;
    case 0x8001441Cu: goto label_8001441C;
    case 0x80014420u: goto label_80014420;
    case 0x80014424u: goto label_80014424;
    case 0x80014428u: goto label_80014428;
    case 0x8001442Cu: goto label_8001442C;
    case 0x80014430u: goto label_80014430;
    case 0x80014434u: goto label_80014434;
    case 0x80014438u: goto label_80014438;
    case 0x8001443Cu: goto label_8001443C;
    case 0x80014440u: goto label_80014440;
    case 0x80014444u: goto label_80014444;
    case 0x80014448u: goto label_80014448;
    case 0x8001444Cu: goto label_8001444C;
    case 0x80014450u: goto label_80014450;
    case 0x80014454u: goto label_80014454;
    case 0x80014458u: goto label_80014458;
    case 0x8001445Cu: goto label_8001445C;
    case 0x80014460u: goto label_80014460;
    case 0x80014464u: goto label_80014464;
    case 0x80014468u: goto label_80014468;
    case 0x8001446Cu: goto label_8001446C;
    case 0x80014470u: goto label_80014470;
    case 0x80014474u: goto label_80014474;
    case 0x80014478u: goto label_80014478;
    case 0x8001447Cu: goto label_8001447C;
    case 0x80014480u: goto label_80014480;
    case 0x80014484u: goto label_80014484;
    case 0x80014488u: goto label_80014488;
    case 0x8001448Cu: goto label_8001448C;
    case 0x80014490u: goto label_80014490;
    case 0x80014494u: goto label_80014494;
    case 0x80014498u: goto label_80014498;
    case 0x8001449Cu: goto label_8001449C;
    case 0x800144A0u: goto label_800144A0;
    case 0x800144A4u: goto label_800144A4;
    case 0x800144A8u: goto label_800144A8;
    case 0x800144ACu: goto label_800144AC;
    case 0x800144B0u: goto label_800144B0;
    case 0x800144B4u: goto label_800144B4;
    case 0x800144B8u: goto label_800144B8;
    case 0x800144BCu: goto label_800144BC;
    case 0x800144C0u: goto label_800144C0;
    case 0x800144C4u: goto label_800144C4;
    case 0x800144C8u: goto label_800144C8;
    case 0x800144CCu: goto label_800144CC;
    case 0x800144D0u: goto label_800144D0;
    case 0x800144D4u: goto label_800144D4;
    case 0x800144D8u: goto label_800144D8;
    case 0x800144DCu: goto label_800144DC;
    case 0x800144E0u: goto label_800144E0;
    case 0x800144E4u: goto label_800144E4;
    case 0x800144E8u: goto label_800144E8;
    case 0x800144ECu: goto label_800144EC;
    case 0x800144F0u: goto label_800144F0;
    case 0x800144F4u: goto label_800144F4;
    case 0x800144F8u: goto label_800144F8;
    case 0x800144FCu: goto label_800144FC;
    case 0x80014500u: goto label_80014500;
    case 0x80014504u: goto label_80014504;
    case 0x80014508u: goto label_80014508;
    case 0x8001450Cu: goto label_8001450C;
    case 0x80014510u: goto label_80014510;
    case 0x80014514u: goto label_80014514;
    case 0x80014518u: goto label_80014518;
    case 0x8001451Cu: goto label_8001451C;
    case 0x80014520u: goto label_80014520;
    case 0x80014524u: goto label_80014524;
    case 0x80014528u: goto label_80014528;
    case 0x8001452Cu: goto label_8001452C;
    case 0x80014530u: goto label_80014530;
    case 0x80014534u: goto label_80014534;
    case 0x80014538u: goto label_80014538;
    case 0x8001453Cu: goto label_8001453C;
    case 0x80014540u: goto label_80014540;
    case 0x80014544u: goto label_80014544;
    case 0x80014548u: goto label_80014548;
    case 0x8001454Cu: goto label_8001454C;
    case 0x80014550u: goto label_80014550;
    case 0x80014554u: goto label_80014554;
    case 0x80014558u: goto label_80014558;
    case 0x8001455Cu: goto label_8001455C;
    case 0x80014560u: goto label_80014560;
    case 0x80014564u: goto label_80014564;
    case 0x80014568u: goto label_80014568;
    case 0x8001456Cu: goto label_8001456C;
    case 0x80014570u: goto label_80014570;
    case 0x80014574u: goto label_80014574;
    case 0x80014578u: goto label_80014578;
    case 0x8001457Cu: goto label_8001457C;
    case 0x80014580u: goto label_80014580;
    case 0x80014584u: goto label_80014584;
    case 0x80014588u: goto label_80014588;
    case 0x8001458Cu: goto label_8001458C;
    case 0x80014590u: goto label_80014590;
    case 0x80014594u: goto label_80014594;
    case 0x80014598u: goto label_80014598;
    case 0x8001459Cu: goto label_8001459C;
    case 0x800145A0u: goto label_800145A0;
    case 0x800145A4u: goto label_800145A4;
    case 0x800145A8u: goto label_800145A8;
    case 0x800145ACu: goto label_800145AC;
    case 0x800145B0u: goto label_800145B0;
    case 0x800145B4u: goto label_800145B4;
    case 0x800145B8u: goto label_800145B8;
    case 0x800145BCu: goto label_800145BC;
    case 0x800145C0u: goto label_800145C0;
    case 0x800145C4u: goto label_800145C4;
    case 0x800145C8u: goto label_800145C8;
    case 0x800145CCu: goto label_800145CC;
    case 0x800145D0u: goto label_800145D0;
    case 0x800145D4u: goto label_800145D4;
    case 0x800145D8u: goto label_800145D8;
    case 0x800145DCu: goto label_800145DC;
    case 0x800145E0u: goto label_800145E0;
    case 0x800145E4u: goto label_800145E4;
    case 0x800145E8u: goto label_800145E8;
    case 0x800145ECu: goto label_800145EC;
    case 0x800145F0u: goto label_800145F0;
    case 0x800145F4u: goto label_800145F4;
    case 0x800145F8u: goto label_800145F8;
    case 0x800145FCu: goto label_800145FC;
    case 0x80014600u: goto label_80014600;
    case 0x80014604u: goto label_80014604;
    case 0x80014608u: goto label_80014608;
    case 0x8001460Cu: goto label_8001460C;
    case 0x80014610u: goto label_80014610;
    case 0x80014614u: goto label_80014614;
    case 0x80014618u: goto label_80014618;
    case 0x8001461Cu: goto label_8001461C;
    case 0x80014620u: goto label_80014620;
    case 0x80014624u: goto label_80014624;
    case 0x80014628u: goto label_80014628;
    case 0x8001462Cu: goto label_8001462C;
    case 0x80014630u: goto label_80014630;
    case 0x80014634u: goto label_80014634;
    case 0x80014638u: goto label_80014638;
    case 0x8001463Cu: goto label_8001463C;
    case 0x80014640u: goto label_80014640;
    case 0x80014644u: goto label_80014644;
    case 0x80014648u: goto label_80014648;
    case 0x8001464Cu: goto label_8001464C;
    case 0x80014650u: goto label_80014650;
    case 0x80014654u: goto label_80014654;
    case 0x80014658u: goto label_80014658;
    case 0x8001465Cu: goto label_8001465C;
    case 0x80014660u: goto label_80014660;
    case 0x80014664u: goto label_80014664;
    case 0x80014668u: goto label_80014668;
    case 0x8001466Cu: goto label_8001466C;
    case 0x80014670u: goto label_80014670;
    case 0x80014674u: goto label_80014674;
    case 0x80014678u: goto label_80014678;
    case 0x8001467Cu: goto label_8001467C;
    case 0x80014680u: goto label_80014680;
    case 0x80014684u: goto label_80014684;
    case 0x80014688u: goto label_80014688;
    case 0x8001468Cu: goto label_8001468C;
    case 0x80014690u: goto label_80014690;
    case 0x80014694u: goto label_80014694;
    case 0x80014698u: goto label_80014698;
    case 0x8001469Cu: goto label_8001469C;
    case 0x800146A0u: goto label_800146A0;
    case 0x800146A4u: goto label_800146A4;
    case 0x800146A8u: goto label_800146A8;
    case 0x800146ACu: goto label_800146AC;
    case 0x800146B0u: goto label_800146B0;
    case 0x800146B4u: goto label_800146B4;
    case 0x800146B8u: goto label_800146B8;
    case 0x800146BCu: goto label_800146BC;
    case 0x800146C0u: goto label_800146C0;
    case 0x800146C4u: goto label_800146C4;
    case 0x800146C8u: goto label_800146C8;
    case 0x800146CCu: goto label_800146CC;
    case 0x800146D0u: goto label_800146D0;
    case 0x800146D4u: goto label_800146D4;
    case 0x800146D8u: goto label_800146D8;
    case 0x800146DCu: goto label_800146DC;
    case 0x800146E0u: goto label_800146E0;
    case 0x800146E4u: goto label_800146E4;
    case 0x800146E8u: goto label_800146E8;
    case 0x800146ECu: goto label_800146EC;
    case 0x800146F0u: goto label_800146F0;
    case 0x800146F4u: goto label_800146F4;
    case 0x800146F8u: goto label_800146F8;
    case 0x800146FCu: goto label_800146FC;
    case 0x80014700u: goto label_80014700;
    case 0x80014704u: goto label_80014704;
    case 0x80014708u: goto label_80014708;
    case 0x8001470Cu: goto label_8001470C;
    case 0x80014710u: goto label_80014710;
    case 0x80014714u: goto label_80014714;
    case 0x80014718u: goto label_80014718;
    case 0x8001471Cu: goto label_8001471C;
    case 0x80014720u: goto label_80014720;
    case 0x80014724u: goto label_80014724;
    case 0x80014728u: goto label_80014728;
    case 0x8001472Cu: goto label_8001472C;
    case 0x80014730u: goto label_80014730;
    case 0x80014734u: goto label_80014734;
    case 0x80014738u: goto label_80014738;
    case 0x8001473Cu: goto label_8001473C;
    case 0x80014740u: goto label_80014740;
    case 0x80014744u: goto label_80014744;
    case 0x80014748u: goto label_80014748;
    case 0x8001474Cu: goto label_8001474C;
    case 0x80014750u: goto label_80014750;
    case 0x80014754u: goto label_80014754;
    case 0x80014758u: goto label_80014758;
    case 0x8001475Cu: goto label_8001475C;
    case 0x80014760u: goto label_80014760;
    case 0x80014764u: goto label_80014764;
    case 0x80014768u: goto label_80014768;
    case 0x8001476Cu: goto label_8001476C;
    case 0x80014770u: goto label_80014770;
    case 0x80014774u: goto label_80014774;
    case 0x80014778u: goto label_80014778;
    case 0x8001477Cu: goto label_8001477C;
    case 0x80014780u: goto label_80014780;
    case 0x80014784u: goto label_80014784;
    case 0x80014788u: goto label_80014788;
    case 0x8001478Cu: goto label_8001478C;
    case 0x80014790u: goto label_80014790;
    case 0x80014794u: goto label_80014794;
    case 0x80014798u: goto label_80014798;
    case 0x8001479Cu: goto label_8001479C;
    case 0x800147A0u: goto label_800147A0;
    case 0x800147A4u: goto label_800147A4;
    case 0x800147A8u: goto label_800147A8;
    case 0x800147ACu: goto label_800147AC;
    case 0x800147B0u: goto label_800147B0;
    case 0x800147B4u: goto label_800147B4;
    case 0x800147B8u: goto label_800147B8;
    case 0x800147BCu: goto label_800147BC;
    case 0x800147C0u: goto label_800147C0;
    case 0x800147C4u: goto label_800147C4;
    case 0x800147C8u: goto label_800147C8;
    case 0x800147CCu: goto label_800147CC;
    case 0x800147D0u: goto label_800147D0;
    case 0x800147D4u: goto label_800147D4;
    case 0x800147D8u: goto label_800147D8;
    case 0x800147DCu: goto label_800147DC;
    case 0x800147E0u: goto label_800147E0;
    case 0x800147E4u: goto label_800147E4;
    case 0x800147E8u: goto label_800147E8;
    case 0x800147ECu: goto label_800147EC;
    case 0x800147F0u: goto label_800147F0;
    case 0x800147F4u: goto label_800147F4;
    case 0x800147F8u: goto label_800147F8;
    case 0x800147FCu: goto label_800147FC;
    case 0x80014800u: goto label_80014800;
    case 0x80014804u: goto label_80014804;
    case 0x80014808u: goto label_80014808;
    case 0x8001480Cu: goto label_8001480C;
    case 0x80014810u: goto label_80014810;
    case 0x80014814u: goto label_80014814;
    case 0x80014818u: goto label_80014818;
    case 0x8001481Cu: goto label_8001481C;
    case 0x80014820u: goto label_80014820;
    case 0x80014824u: goto label_80014824;
    case 0x80014828u: goto label_80014828;
    case 0x8001482Cu: goto label_8001482C;
    case 0x80014830u: goto label_80014830;
    case 0x80014834u: goto label_80014834;
    case 0x80014838u: goto label_80014838;
    case 0x8001483Cu: goto label_8001483C;
    case 0x80014840u: goto label_80014840;
    case 0x80014844u: goto label_80014844;
    case 0x80014848u: goto label_80014848;
    case 0x8001484Cu: goto label_8001484C;
    case 0x80014850u: goto label_80014850;
    case 0x80014854u: goto label_80014854;
    case 0x80014858u: goto label_80014858;
    case 0x8001485Cu: goto label_8001485C;
    case 0x80014860u: goto label_80014860;
    case 0x80014864u: goto label_80014864;
    case 0x80014868u: goto label_80014868;
    case 0x8001486Cu: goto label_8001486C;
    case 0x80014870u: goto label_80014870;
    case 0x80014874u: goto label_80014874;
    case 0x80014878u: goto label_80014878;
    case 0x8001487Cu: goto label_8001487C;
    case 0x80014880u: goto label_80014880;
    case 0x80014884u: goto label_80014884;
    case 0x80014888u: goto label_80014888;
    case 0x8001488Cu: goto label_8001488C;
    case 0x80014890u: goto label_80014890;
    case 0x80014894u: goto label_80014894;
    case 0x80014898u: goto label_80014898;
    case 0x8001489Cu: goto label_8001489C;
    case 0x800148A0u: goto label_800148A0;
    case 0x800148A4u: goto label_800148A4;
    case 0x800148A8u: goto label_800148A8;
    case 0x800148ACu: goto label_800148AC;
    case 0x800148B0u: goto label_800148B0;
    case 0x800148B4u: goto label_800148B4;
    case 0x800148B8u: goto label_800148B8;
    case 0x800148BCu: goto label_800148BC;
    case 0x800148C0u: goto label_800148C0;
    case 0x800148C4u: goto label_800148C4;
    case 0x800148C8u: goto label_800148C8;
    case 0x800148CCu: goto label_800148CC;
    case 0x800148D0u: goto label_800148D0;
    case 0x800148D4u: goto label_800148D4;
    case 0x800148D8u: goto label_800148D8;
    case 0x800148DCu: goto label_800148DC;
    case 0x800148E0u: goto label_800148E0;
    case 0x800148E4u: goto label_800148E4;
    case 0x800148E8u: goto label_800148E8;
    case 0x800148ECu: goto label_800148EC;
    case 0x800148F0u: goto label_800148F0;
    case 0x800148F4u: goto label_800148F4;
    case 0x800148F8u: goto label_800148F8;
    case 0x800148FCu: goto label_800148FC;
    case 0x80014900u: goto label_80014900;
    case 0x80014904u: goto label_80014904;
    case 0x80014908u: goto label_80014908;
    case 0x8001490Cu: goto label_8001490C;
    case 0x80014910u: goto label_80014910;
    case 0x80014914u: goto label_80014914;
    case 0x80014918u: goto label_80014918;
    case 0x8001491Cu: goto label_8001491C;
    case 0x80014920u: goto label_80014920;
    case 0x80014924u: goto label_80014924;
    case 0x80014928u: goto label_80014928;
    case 0x8001492Cu: goto label_8001492C;
    case 0x80014930u: goto label_80014930;
    case 0x80014934u: goto label_80014934;
    case 0x80014938u: goto label_80014938;
    case 0x8001493Cu: goto label_8001493C;
    case 0x80014940u: goto label_80014940;
    case 0x80014944u: goto label_80014944;
    case 0x80014948u: goto label_80014948;
    case 0x8001494Cu: goto label_8001494C;
    case 0x80014950u: goto label_80014950;
    case 0x80014954u: goto label_80014954;
    case 0x80014958u: goto label_80014958;
    case 0x8001495Cu: goto label_8001495C;
    case 0x80014960u: goto label_80014960;
    case 0x80014964u: goto label_80014964;
    case 0x80014968u: goto label_80014968;
    case 0x8001496Cu: goto label_8001496C;
    case 0x80014970u: goto label_80014970;
    case 0x80014974u: goto label_80014974;
    case 0x80014978u: goto label_80014978;
    case 0x8001497Cu: goto label_8001497C;
    case 0x80014980u: goto label_80014980;
    case 0x80014984u: goto label_80014984;
    case 0x80014988u: goto label_80014988;
    case 0x8001498Cu: goto label_8001498C;
    case 0x80014990u: goto label_80014990;
    case 0x80014994u: goto label_80014994;
    case 0x80014998u: goto label_80014998;
    case 0x8001499Cu: goto label_8001499C;
    case 0x800149A0u: goto label_800149A0;
    case 0x800149A4u: goto label_800149A4;
    case 0x800149A8u: goto label_800149A8;
    case 0x800149ACu: goto label_800149AC;
    case 0x800149B0u: goto label_800149B0;
    case 0x800149B4u: goto label_800149B4;
    case 0x800149B8u: goto label_800149B8;
    case 0x800149BCu: goto label_800149BC;
    case 0x800149C0u: goto label_800149C0;
    case 0x800149C4u: goto label_800149C4;
    case 0x800149C8u: goto label_800149C8;
    case 0x800149CCu: goto label_800149CC;
    case 0x800149D0u: goto label_800149D0;
    case 0x800149D4u: goto label_800149D4;
    case 0x800149D8u: goto label_800149D8;
    case 0x800149DCu: goto label_800149DC;
    case 0x800149E0u: goto label_800149E0;
    case 0x800149E4u: goto label_800149E4;
    case 0x800149E8u: goto label_800149E8;
    case 0x800149ECu: goto label_800149EC;
    case 0x800149F0u: goto label_800149F0;
    case 0x800149F4u: goto label_800149F4;
    case 0x800149F8u: goto label_800149F8;
    case 0x800149FCu: goto label_800149FC;
    case 0x80014A00u: goto label_80014A00;
    case 0x80014A04u: goto label_80014A04;
    case 0x80014A08u: goto label_80014A08;
    case 0x80014A0Cu: goto label_80014A0C;
    case 0x80014A10u: goto label_80014A10;
    case 0x80014A14u: goto label_80014A14;
    case 0x80014A18u: goto label_80014A18;
    case 0x80014A1Cu: goto label_80014A1C;
    case 0x80014A20u: goto label_80014A20;
    case 0x80014A24u: goto label_80014A24;
    case 0x80014A28u: goto label_80014A28;
    case 0x80014A2Cu: goto label_80014A2C;
    case 0x80014A30u: goto label_80014A30;
    case 0x80014A34u: goto label_80014A34;
    case 0x80014A38u: goto label_80014A38;
    case 0x80014A3Cu: goto label_80014A3C;
    case 0x80014A40u: goto label_80014A40;
    case 0x80014A44u: goto label_80014A44;
    case 0x80014A48u: goto label_80014A48;
    case 0x80014A4Cu: goto label_80014A4C;
    case 0x80014A50u: goto label_80014A50;
    case 0x80014A54u: goto label_80014A54;
    case 0x80014A58u: goto label_80014A58;
    case 0x80014A5Cu: goto label_80014A5C;
    case 0x80014A60u: goto label_80014A60;
    case 0x80014A64u: goto label_80014A64;
    case 0x80014A68u: goto label_80014A68;
    case 0x80014A6Cu: goto label_80014A6C;
    case 0x80014A70u: goto label_80014A70;
    case 0x80014A74u: goto label_80014A74;
    case 0x80014A78u: goto label_80014A78;
    case 0x80014A7Cu: goto label_80014A7C;
    case 0x80014A80u: goto label_80014A80;
    case 0x80014A84u: goto label_80014A84;
    case 0x80014A88u: goto label_80014A88;
    case 0x80014A8Cu: goto label_80014A8C;
    case 0x80014A90u: goto label_80014A90;
    case 0x80014A94u: goto label_80014A94;
    case 0x80014A98u: goto label_80014A98;
    case 0x80014A9Cu: goto label_80014A9C;
    case 0x80014AA0u: goto label_80014AA0;
    case 0x80014AA4u: goto label_80014AA4;
    case 0x80014AA8u: goto label_80014AA8;
    case 0x80014AACu: goto label_80014AAC;
    case 0x80014AB0u: goto label_80014AB0;
    case 0x80014AB4u: goto label_80014AB4;
    case 0x80014AB8u: goto label_80014AB8;
    case 0x80014ABCu: goto label_80014ABC;
    case 0x80014AC0u: goto label_80014AC0;
    case 0x80014AC4u: goto label_80014AC4;
    case 0x80014AC8u: goto label_80014AC8;
    case 0x80014ACCu: goto label_80014ACC;
    case 0x80014AD0u: goto label_80014AD0;
    case 0x80014AD4u: goto label_80014AD4;
    case 0x80014AD8u: goto label_80014AD8;
    case 0x80014ADCu: goto label_80014ADC;
    case 0x80014AE0u: goto label_80014AE0;
    case 0x80014AE4u: goto label_80014AE4;
    case 0x80014AE8u: goto label_80014AE8;
    case 0x80014AECu: goto label_80014AEC;
    case 0x80014AF0u: goto label_80014AF0;
    case 0x80014AF4u: goto label_80014AF4;
    case 0x80014AF8u: goto label_80014AF8;
    case 0x80014AFCu: goto label_80014AFC;
    case 0x80014B00u: goto label_80014B00;
    case 0x80014B04u: goto label_80014B04;
    case 0x80014B08u: goto label_80014B08;
    case 0x80014B0Cu: goto label_80014B0C;
    case 0x80014B10u: goto label_80014B10;
    case 0x80014B14u: goto label_80014B14;
    case 0x80014B18u: goto label_80014B18;
    case 0x80014B1Cu: goto label_80014B1C;
    case 0x80014B20u: goto label_80014B20;
    case 0x80014B24u: goto label_80014B24;
    case 0x80014B28u: goto label_80014B28;
    case 0x80014B2Cu: goto label_80014B2C;
    case 0x80014B30u: goto label_80014B30;
    case 0x80014B34u: goto label_80014B34;
    case 0x80014B38u: goto label_80014B38;
    case 0x80014B3Cu: goto label_80014B3C;
    case 0x80014B40u: goto label_80014B40;
    case 0x80014B44u: goto label_80014B44;
    case 0x80014B48u: goto label_80014B48;
    case 0x80014B4Cu: goto label_80014B4C;
    case 0x80014B50u: goto label_80014B50;
    case 0x80014B54u: goto label_80014B54;
    case 0x80014B58u: goto label_80014B58;
    case 0x80014B5Cu: goto label_80014B5C;
    case 0x80014B60u: goto label_80014B60;
    case 0x80014B64u: goto label_80014B64;
    case 0x80014B68u: goto label_80014B68;
    case 0x80014B6Cu: goto label_80014B6C;
    case 0x80014B70u: goto label_80014B70;
    case 0x80014B74u: goto label_80014B74;
    case 0x80014B78u: goto label_80014B78;
    case 0x80014B7Cu: goto label_80014B7C;
    case 0x80014B80u: goto label_80014B80;
    case 0x80014B84u: goto label_80014B84;
    case 0x80014B88u: goto label_80014B88;
    case 0x80014B8Cu: goto label_80014B8C;
    case 0x80014B90u: goto label_80014B90;
    case 0x80014B94u: goto label_80014B94;
    case 0x80014B98u: goto label_80014B98;
    case 0x80014B9Cu: goto label_80014B9C;
    case 0x80014BA0u: goto label_80014BA0;
    case 0x80014BA4u: goto label_80014BA4;
    case 0x80014BA8u: goto label_80014BA8;
    case 0x80014BACu: goto label_80014BAC;
    case 0x80014BB0u: goto label_80014BB0;
    case 0x80014BB4u: goto label_80014BB4;
    case 0x80014BB8u: goto label_80014BB8;
    case 0x80014BBCu: goto label_80014BBC;
    case 0x80014BC0u: goto label_80014BC0;
    case 0x80014BC4u: goto label_80014BC4;
    case 0x80014BC8u: goto label_80014BC8;
    case 0x80014BCCu: goto label_80014BCC;
    case 0x80014BD0u: goto label_80014BD0;
    case 0x80014BD4u: goto label_80014BD4;
    case 0x80014BD8u: goto label_80014BD8;
    case 0x80014BDCu: goto label_80014BDC;
    case 0x80014BE0u: goto label_80014BE0;
    case 0x80014BE4u: goto label_80014BE4;
    case 0x80014BE8u: goto label_80014BE8;
    case 0x80014BECu: goto label_80014BEC;
    case 0x80014BF0u: goto label_80014BF0;
    case 0x80014BF4u: goto label_80014BF4;
    case 0x80014BF8u: goto label_80014BF8;
    case 0x80014BFCu: goto label_80014BFC;
    case 0x80014C00u: goto label_80014C00;
    case 0x80014C04u: goto label_80014C04;
    case 0x80014C08u: goto label_80014C08;
    case 0x80014C0Cu: goto label_80014C0C;
    case 0x80014C10u: goto label_80014C10;
    case 0x80014C14u: goto label_80014C14;
    case 0x80014C18u: goto label_80014C18;
    case 0x80014C1Cu: goto label_80014C1C;
    case 0x80014C20u: goto label_80014C20;
    case 0x80014C24u: goto label_80014C24;
    case 0x80014C28u: goto label_80014C28;
    case 0x80014C2Cu: goto label_80014C2C;
    case 0x80014C30u: goto label_80014C30;
    case 0x80014C34u: goto label_80014C34;
    case 0x80014C38u: goto label_80014C38;
    case 0x80014C3Cu: goto label_80014C3C;
    case 0x80014C40u: goto label_80014C40;
    case 0x80014C44u: goto label_80014C44;
    case 0x80014C48u: goto label_80014C48;
    case 0x80014C4Cu: goto label_80014C4C;
    case 0x80014C50u: goto label_80014C50;
    case 0x80014C54u: goto label_80014C54;
    case 0x80014C58u: goto label_80014C58;
    case 0x80014C5Cu: goto label_80014C5C;
    case 0x80014C60u: goto label_80014C60;
    case 0x80014C64u: goto label_80014C64;
    case 0x80014C68u: goto label_80014C68;
    case 0x80014C6Cu: goto label_80014C6C;
    case 0x80014C70u: goto label_80014C70;
    case 0x80014C74u: goto label_80014C74;
    case 0x80014C78u: goto label_80014C78;
    case 0x80014C7Cu: goto label_80014C7C;
    case 0x80014C80u: goto label_80014C80;
    case 0x80014C84u: goto label_80014C84;
    case 0x80014C88u: goto label_80014C88;
    case 0x80014C8Cu: goto label_80014C8C;
    case 0x80014C90u: goto label_80014C90;
    case 0x80014C94u: goto label_80014C94;
    case 0x80014C98u: goto label_80014C98;
    case 0x80014C9Cu: goto label_80014C9C;
    case 0x80014CA0u: goto label_80014CA0;
    case 0x80014CA4u: goto label_80014CA4;
    case 0x80014CA8u: goto label_80014CA8;
    case 0x80014CACu: goto label_80014CAC;
    case 0x80014CB0u: goto label_80014CB0;
    case 0x80014CB4u: goto label_80014CB4;
    case 0x80014CB8u: goto label_80014CB8;
    case 0x80014CBCu: goto label_80014CBC;
    case 0x80014CC0u: goto label_80014CC0;
    case 0x80014CC4u: goto label_80014CC4;
    case 0x80014CC8u: goto label_80014CC8;
    case 0x80014CCCu: goto label_80014CCC;
    case 0x80014CD0u: goto label_80014CD0;
    case 0x80014CD4u: goto label_80014CD4;
    case 0x80014CD8u: goto label_80014CD8;
    case 0x80014CDCu: goto label_80014CDC;
    case 0x80014CE0u: goto label_80014CE0;
    case 0x80014CE4u: goto label_80014CE4;
    case 0x80014CE8u: goto label_80014CE8;
    case 0x80014CECu: goto label_80014CEC;
    case 0x80014CF0u: goto label_80014CF0;
    case 0x80014CF4u: goto label_80014CF4;
    case 0x80014CF8u: goto label_80014CF8;
    case 0x80014CFCu: goto label_80014CFC;
    case 0x80014D00u: goto label_80014D00;
    case 0x80014D04u: goto label_80014D04;
    case 0x80014D08u: goto label_80014D08;
    case 0x80014D0Cu: goto label_80014D0C;
    case 0x80014D10u: goto label_80014D10;
    case 0x80014D14u: goto label_80014D14;
    case 0x80014D18u: goto label_80014D18;
    case 0x80014D1Cu: goto label_80014D1C;
    case 0x80014D20u: goto label_80014D20;
    case 0x80014D24u: goto label_80014D24;
    case 0x80014D28u: goto label_80014D28;
    case 0x80014D2Cu: goto label_80014D2C;
    case 0x80014D30u: goto label_80014D30;
    case 0x80014D34u: goto label_80014D34;
    case 0x80014D38u: goto label_80014D38;
    case 0x80014D3Cu: goto label_80014D3C;
    case 0x80014D40u: goto label_80014D40;
    case 0x80014D44u: goto label_80014D44;
    case 0x80014D48u: goto label_80014D48;
    case 0x80014D4Cu: goto label_80014D4C;
    case 0x80014D50u: goto label_80014D50;
    case 0x80014D54u: goto label_80014D54;
    case 0x80014D58u: goto label_80014D58;
    case 0x80014D5Cu: goto label_80014D5C;
    case 0x80014D60u: goto label_80014D60;
    case 0x80014D64u: goto label_80014D64;
    case 0x80014D68u: goto label_80014D68;
    case 0x80014D6Cu: goto label_80014D6C;
    case 0x80014D70u: goto label_80014D70;
    case 0x80014D74u: goto label_80014D74;
    case 0x80014D78u: goto label_80014D78;
    case 0x80014D7Cu: goto label_80014D7C;
    case 0x80014D80u: goto label_80014D80;
    case 0x80014D84u: goto label_80014D84;
    case 0x80014D88u: goto label_80014D88;
    case 0x80014D8Cu: goto label_80014D8C;
    case 0x80014D90u: goto label_80014D90;
    case 0x80014D94u: goto label_80014D94;
    case 0x80014D98u: goto label_80014D98;
    case 0x80014D9Cu: goto label_80014D9C;
    case 0x80014DA0u: goto label_80014DA0;
    case 0x80014DA4u: goto label_80014DA4;
    case 0x80014DA8u: goto label_80014DA8;
    case 0x80014DACu: goto label_80014DAC;
    case 0x80014DB0u: goto label_80014DB0;
    case 0x80014DB4u: goto label_80014DB4;
    case 0x80014DB8u: goto label_80014DB8;
    case 0x80014DBCu: goto label_80014DBC;
    case 0x80014DC0u: goto label_80014DC0;
    case 0x80014DC4u: goto label_80014DC4;
    case 0x80014DC8u: goto label_80014DC8;
    case 0x80014DCCu: goto label_80014DCC;
    case 0x80014DD0u: goto label_80014DD0;
    case 0x80014DD4u: goto label_80014DD4;
    case 0x80014DD8u: goto label_80014DD8;
    case 0x80014DDCu: goto label_80014DDC;
    case 0x80014DE0u: goto label_80014DE0;
    case 0x80014DE4u: goto label_80014DE4;
    case 0x80014DE8u: goto label_80014DE8;
    case 0x80014DECu: goto label_80014DEC;
    case 0x80014DF0u: goto label_80014DF0;
    case 0x80014DF4u: goto label_80014DF4;
    case 0x80014DF8u: goto label_80014DF8;
    case 0x80014DFCu: goto label_80014DFC;
    case 0x80014E00u: goto label_80014E00;
    case 0x80014E04u: goto label_80014E04;
    case 0x80014E08u: goto label_80014E08;
    case 0x80014E0Cu: goto label_80014E0C;
    case 0x80014E10u: goto label_80014E10;
    case 0x80014E14u: goto label_80014E14;
    case 0x80014E18u: goto label_80014E18;
    case 0x80014E1Cu: goto label_80014E1C;
    case 0x80014E20u: goto label_80014E20;
    case 0x80014E24u: goto label_80014E24;
    case 0x80014E28u: goto label_80014E28;
    case 0x80014E2Cu: goto label_80014E2C;
    case 0x80014E30u: goto label_80014E30;
    case 0x80014E34u: goto label_80014E34;
    case 0x80014E38u: goto label_80014E38;
    case 0x80014E3Cu: goto label_80014E3C;
    case 0x80014E40u: goto label_80014E40;
    case 0x80014E44u: goto label_80014E44;
    case 0x80014E48u: goto label_80014E48;
    case 0x80014E4Cu: goto label_80014E4C;
    case 0x80014E50u: goto label_80014E50;
    case 0x80014E54u: goto label_80014E54;
    case 0x80014E58u: goto label_80014E58;
    case 0x80014E5Cu: goto label_80014E5C;
    case 0x80014E60u: goto label_80014E60;
    case 0x80014E64u: goto label_80014E64;
    case 0x80014E68u: goto label_80014E68;
    case 0x80014E6Cu: goto label_80014E6C;
    case 0x80014E70u: goto label_80014E70;
    case 0x80014E74u: goto label_80014E74;
    case 0x80014E78u: goto label_80014E78;
    case 0x80014E7Cu: goto label_80014E7C;
    case 0x80014E80u: goto label_80014E80;
    case 0x80014E84u: goto label_80014E84;
    case 0x80014E88u: goto label_80014E88;
    case 0x80014E8Cu: goto label_80014E8C;
    case 0x80014E90u: goto label_80014E90;
    case 0x80014E94u: goto label_80014E94;
    case 0x80014E98u: goto label_80014E98;
    case 0x80014E9Cu: goto label_80014E9C;
    case 0x80014EA0u: goto label_80014EA0;
    case 0x80014EA4u: goto label_80014EA4;
    case 0x80014EA8u: goto label_80014EA8;
    case 0x80014EACu: goto label_80014EAC;
    case 0x80014EB0u: goto label_80014EB0;
    case 0x80014EB4u: goto label_80014EB4;
    case 0x80014EB8u: goto label_80014EB8;
    case 0x80014EBCu: goto label_80014EBC;
    case 0x80014EC0u: goto label_80014EC0;
    case 0x80014EC4u: goto label_80014EC4;
    case 0x80014EC8u: goto label_80014EC8;
    case 0x80014ECCu: goto label_80014ECC;
    case 0x80014ED0u: goto label_80014ED0;
    case 0x80014ED4u: goto label_80014ED4;
    case 0x80014ED8u: goto label_80014ED8;
    case 0x80014EDCu: goto label_80014EDC;
    case 0x80014EE0u: goto label_80014EE0;
    case 0x80014EE4u: goto label_80014EE4;
    case 0x80014EE8u: goto label_80014EE8;
    case 0x80014EECu: goto label_80014EEC;
    case 0x80014EF0u: goto label_80014EF0;
    case 0x80014EF4u: goto label_80014EF4;
    case 0x80014EF8u: goto label_80014EF8;
    case 0x80014EFCu: goto label_80014EFC;
    case 0x80014F00u: goto label_80014F00;
    case 0x80014F04u: goto label_80014F04;
    case 0x80014F08u: goto label_80014F08;
    case 0x80014F0Cu: goto label_80014F0C;
    case 0x80014F10u: goto label_80014F10;
    case 0x80014F14u: goto label_80014F14;
    case 0x80014F18u: goto label_80014F18;
    case 0x80014F1Cu: goto label_80014F1C;
    case 0x80014F20u: goto label_80014F20;
    case 0x80014F24u: goto label_80014F24;
    case 0x80014F28u: goto label_80014F28;
    case 0x80014F2Cu: goto label_80014F2C;
    case 0x80014F30u: goto label_80014F30;
    case 0x80014F34u: goto label_80014F34;
    case 0x80014F38u: goto label_80014F38;
    case 0x80014F3Cu: goto label_80014F3C;
    case 0x80014F40u: goto label_80014F40;
    case 0x80014F44u: goto label_80014F44;
    case 0x80014F48u: goto label_80014F48;
    case 0x80014F4Cu: goto label_80014F4C;
    case 0x80014F50u: goto label_80014F50;
    case 0x80014F54u: goto label_80014F54;
    case 0x80014F58u: goto label_80014F58;
    case 0x80014F5Cu: goto label_80014F5C;
    case 0x80014F60u: goto label_80014F60;
    case 0x80014F64u: goto label_80014F64;
    case 0x80014F68u: goto label_80014F68;
    case 0x80014F6Cu: goto label_80014F6C;
    case 0x80014F70u: goto label_80014F70;
    case 0x80014F74u: goto label_80014F74;
    case 0x80014F78u: goto label_80014F78;
    case 0x80014F7Cu: goto label_80014F7C;
    case 0x80014F80u: goto label_80014F80;
    case 0x80014F84u: goto label_80014F84;
    case 0x80014F88u: goto label_80014F88;
    case 0x80014F8Cu: goto label_80014F8C;
    case 0x80014F90u: goto label_80014F90;
    case 0x80014F94u: goto label_80014F94;
    case 0x80014F98u: goto label_80014F98;
    case 0x80014F9Cu: goto label_80014F9C;
    case 0x80014FA0u: goto label_80014FA0;
    case 0x80014FA4u: goto label_80014FA4;
    case 0x80014FA8u: goto label_80014FA8;
    case 0x80014FACu: goto label_80014FAC;
    case 0x80014FB0u: goto label_80014FB0;
    case 0x80014FB4u: goto label_80014FB4;
    case 0x80014FB8u: goto label_80014FB8;
    case 0x80014FBCu: goto label_80014FBC;
    case 0x80014FC0u: goto label_80014FC0;
    case 0x80014FC4u: goto label_80014FC4;
    case 0x80014FC8u: goto label_80014FC8;
    case 0x80014FCCu: goto label_80014FCC;
    case 0x80014FD0u: goto label_80014FD0;
    case 0x80014FD4u: goto label_80014FD4;
    case 0x80014FD8u: goto label_80014FD8;
    case 0x80014FDCu: goto label_80014FDC;
    case 0x80014FE0u: goto label_80014FE0;
    case 0x80014FE4u: goto label_80014FE4;
    case 0x80014FE8u: goto label_80014FE8;
    case 0x80014FECu: goto label_80014FEC;
    case 0x80014FF0u: goto label_80014FF0;
    case 0x80014FF4u: goto label_80014FF4;
    case 0x80014FF8u: goto label_80014FF8;
    case 0x80014FFCu: goto label_80014FFC;
    case 0x80015000u: goto label_80015000;
    case 0x80015004u: goto label_80015004;
    case 0x80015008u: goto label_80015008;
    case 0x8001500Cu: goto label_8001500C;
    case 0x80015010u: goto label_80015010;
    case 0x80015014u: goto label_80015014;
    case 0x80015018u: goto label_80015018;
    case 0x8001501Cu: goto label_8001501C;
    case 0x80015020u: goto label_80015020;
    case 0x80015024u: goto label_80015024;
    case 0x80015028u: goto label_80015028;
    case 0x8001502Cu: goto label_8001502C;
    case 0x80015030u: goto label_80015030;
    case 0x80015034u: goto label_80015034;
    case 0x80015038u: goto label_80015038;
    case 0x8001503Cu: goto label_8001503C;
    case 0x80015040u: goto label_80015040;
    case 0x80015044u: goto label_80015044;
    case 0x80015048u: goto label_80015048;
    case 0x8001504Cu: goto label_8001504C;
    case 0x80015050u: goto label_80015050;
    case 0x80015054u: goto label_80015054;
    case 0x80015058u: goto label_80015058;
    case 0x8001505Cu: goto label_8001505C;
    case 0x80015060u: goto label_80015060;
    case 0x80015064u: goto label_80015064;
    case 0x80015068u: goto label_80015068;
    case 0x8001506Cu: goto label_8001506C;
    case 0x80015070u: goto label_80015070;
    case 0x80015074u: goto label_80015074;
    case 0x80015078u: goto label_80015078;
    case 0x8001507Cu: goto label_8001507C;
    case 0x80015080u: goto label_80015080;
    case 0x80015084u: goto label_80015084;
    case 0x80015088u: goto label_80015088;
    case 0x8001508Cu: goto label_8001508C;
    case 0x80015090u: goto label_80015090;
    case 0x80015094u: goto label_80015094;
    case 0x80015098u: goto label_80015098;
    case 0x8001509Cu: goto label_8001509C;
    case 0x800150A0u: goto label_800150A0;
    case 0x800150A4u: goto label_800150A4;
    case 0x800150A8u: goto label_800150A8;
    case 0x800150ACu: goto label_800150AC;
    case 0x800150B0u: goto label_800150B0;
    case 0x800150B4u: goto label_800150B4;
    case 0x800150B8u: goto label_800150B8;
    case 0x800150BCu: goto label_800150BC;
    case 0x800150C0u: goto label_800150C0;
    case 0x800150C4u: goto label_800150C4;
    case 0x800150C8u: goto label_800150C8;
    case 0x800150CCu: goto label_800150CC;
    case 0x800150D0u: goto label_800150D0;
    case 0x800150D4u: goto label_800150D4;
    case 0x800150D8u: goto label_800150D8;
    case 0x800150DCu: goto label_800150DC;
    case 0x800150E0u: goto label_800150E0;
    case 0x800150E4u: goto label_800150E4;
    case 0x800150E8u: goto label_800150E8;
    case 0x800150ECu: goto label_800150EC;
    case 0x800150F0u: goto label_800150F0;
    case 0x800150F4u: goto label_800150F4;
    case 0x800150F8u: goto label_800150F8;
    case 0x800150FCu: goto label_800150FC;
    case 0x80015100u: goto label_80015100;
    case 0x80015104u: goto label_80015104;
    case 0x80015108u: goto label_80015108;
    case 0x8001510Cu: goto label_8001510C;
    case 0x80015110u: goto label_80015110;
    case 0x80015114u: goto label_80015114;
    case 0x80015118u: goto label_80015118;
    case 0x8001511Cu: goto label_8001511C;
    case 0x80015120u: goto label_80015120;
    case 0x80015124u: goto label_80015124;
    case 0x80015128u: goto label_80015128;
    case 0x8001512Cu: goto label_8001512C;
    case 0x80015130u: goto label_80015130;
    case 0x80015134u: goto label_80015134;
    case 0x80015138u: goto label_80015138;
    case 0x8001513Cu: goto label_8001513C;
    case 0x80015140u: goto label_80015140;
    case 0x80015144u: goto label_80015144;
    case 0x80015148u: goto label_80015148;
    case 0x8001514Cu: goto label_8001514C;
    case 0x80015150u: goto label_80015150;
    case 0x80015154u: goto label_80015154;
    case 0x80015158u: goto label_80015158;
    case 0x8001515Cu: goto label_8001515C;
    case 0x80015160u: goto label_80015160;
    case 0x80015164u: goto label_80015164;
    case 0x80015168u: goto label_80015168;
    case 0x8001516Cu: goto label_8001516C;
    case 0x80015170u: goto label_80015170;
    case 0x80015174u: goto label_80015174;
    case 0x80015178u: goto label_80015178;
    case 0x8001517Cu: goto label_8001517C;
    case 0x80015180u: goto label_80015180;
    case 0x80015184u: goto label_80015184;
    case 0x80015188u: goto label_80015188;
    case 0x8001518Cu: goto label_8001518C;
    case 0x80015190u: goto label_80015190;
    case 0x80015194u: goto label_80015194;
    case 0x80015198u: goto label_80015198;
    case 0x8001519Cu: goto label_8001519C;
    case 0x800151A0u: goto label_800151A0;
    case 0x800151A4u: goto label_800151A4;
    case 0x800151A8u: goto label_800151A8;
    case 0x800151ACu: goto label_800151AC;
    case 0x800151B0u: goto label_800151B0;
    case 0x800151B4u: goto label_800151B4;
    case 0x800151B8u: goto label_800151B8;
    case 0x800151BCu: goto label_800151BC;
    case 0x800151C0u: goto label_800151C0;
    case 0x800151C4u: goto label_800151C4;
    case 0x800151C8u: goto label_800151C8;
    case 0x800151CCu: goto label_800151CC;
    case 0x800151D0u: goto label_800151D0;
    case 0x800151D4u: goto label_800151D4;
    case 0x800151D8u: goto label_800151D8;
    case 0x800151DCu: goto label_800151DC;
    case 0x800151E0u: goto label_800151E0;
    case 0x800151E4u: goto label_800151E4;
    case 0x800151E8u: goto label_800151E8;
    case 0x800151ECu: goto label_800151EC;
    case 0x800151F0u: goto label_800151F0;
    case 0x800151F4u: goto label_800151F4;
    case 0x800151F8u: goto label_800151F8;
    case 0x800151FCu: goto label_800151FC;
    case 0x80015200u: goto label_80015200;
    case 0x80015204u: goto label_80015204;
    case 0x80015208u: goto label_80015208;
    case 0x8001520Cu: goto label_8001520C;
    case 0x80015210u: goto label_80015210;
    case 0x80015214u: goto label_80015214;
    case 0x80015218u: goto label_80015218;
    case 0x8001521Cu: goto label_8001521C;
    case 0x80015220u: goto label_80015220;
    case 0x80015224u: goto label_80015224;
    case 0x80015228u: goto label_80015228;
    case 0x8001522Cu: goto label_8001522C;
    case 0x80015230u: goto label_80015230;
    case 0x80015234u: goto label_80015234;
    case 0x80015238u: goto label_80015238;
    case 0x8001523Cu: goto label_8001523C;
    case 0x80015240u: goto label_80015240;
    case 0x80015244u: goto label_80015244;
    case 0x80015248u: goto label_80015248;
    case 0x8001524Cu: goto label_8001524C;
    case 0x80015250u: goto label_80015250;
    case 0x80015254u: goto label_80015254;
    case 0x80015258u: goto label_80015258;
    case 0x8001525Cu: goto label_8001525C;
    case 0x80015260u: goto label_80015260;
    case 0x80015264u: goto label_80015264;
    case 0x80015268u: goto label_80015268;
    case 0x8001526Cu: goto label_8001526C;
    case 0x80015270u: goto label_80015270;
    case 0x80015274u: goto label_80015274;
    case 0x80015278u: goto label_80015278;
    case 0x8001527Cu: goto label_8001527C;
    case 0x80015280u: goto label_80015280;
    case 0x80015284u: goto label_80015284;
    case 0x80015288u: goto label_80015288;
    case 0x8001528Cu: goto label_8001528C;
    case 0x80015290u: goto label_80015290;
    case 0x80015294u: goto label_80015294;
    case 0x80015298u: goto label_80015298;
    case 0x8001529Cu: goto label_8001529C;
    case 0x800152A0u: goto label_800152A0;
    case 0x800152A4u: goto label_800152A4;
    case 0x800152A8u: goto label_800152A8;
    case 0x800152ACu: goto label_800152AC;
    case 0x800152B0u: goto label_800152B0;
    case 0x800152B4u: goto label_800152B4;
    case 0x800152B8u: goto label_800152B8;
    case 0x800152BCu: goto label_800152BC;
    case 0x800152C0u: goto label_800152C0;
    case 0x800152C4u: goto label_800152C4;
    case 0x800152C8u: goto label_800152C8;
    case 0x800152CCu: goto label_800152CC;
    case 0x800152D0u: goto label_800152D0;
    case 0x800152D4u: goto label_800152D4;
    case 0x800152D8u: goto label_800152D8;
    case 0x800152DCu: goto label_800152DC;
    case 0x800152E0u: goto label_800152E0;
    case 0x800152E4u: goto label_800152E4;
    case 0x800152E8u: goto label_800152E8;
    case 0x800152ECu: goto label_800152EC;
    case 0x800152F0u: goto label_800152F0;
    case 0x800152F4u: goto label_800152F4;
    case 0x800152F8u: goto label_800152F8;
    case 0x800152FCu: goto label_800152FC;
    case 0x80015300u: goto label_80015300;
    case 0x80015304u: goto label_80015304;
    case 0x80015308u: goto label_80015308;
    case 0x8001530Cu: goto label_8001530C;
    case 0x80015310u: goto label_80015310;
    case 0x80015314u: goto label_80015314;
    case 0x80015318u: goto label_80015318;
    case 0x8001531Cu: goto label_8001531C;
    case 0x80015320u: goto label_80015320;
    case 0x80015324u: goto label_80015324;
    case 0x80015328u: goto label_80015328;
    case 0x8001532Cu: goto label_8001532C;
    case 0x80015330u: goto label_80015330;
    case 0x80015334u: goto label_80015334;
    case 0x80015338u: goto label_80015338;
    case 0x8001533Cu: goto label_8001533C;
    case 0x80015340u: goto label_80015340;
    case 0x80015344u: goto label_80015344;
    case 0x80015348u: goto label_80015348;
    case 0x8001534Cu: goto label_8001534C;
    case 0x80015350u: goto label_80015350;
    case 0x80015354u: goto label_80015354;
    case 0x80015358u: goto label_80015358;
    case 0x8001535Cu: goto label_8001535C;
    case 0x80015360u: goto label_80015360;
    case 0x80015364u: goto label_80015364;
    case 0x80015368u: goto label_80015368;
    case 0x8001536Cu: goto label_8001536C;
    case 0x80015370u: goto label_80015370;
    case 0x80015374u: goto label_80015374;
    case 0x80015378u: goto label_80015378;
    case 0x8001537Cu: goto label_8001537C;
    case 0x80015380u: goto label_80015380;
    case 0x80015384u: goto label_80015384;
    case 0x80015388u: goto label_80015388;
    case 0x8001538Cu: goto label_8001538C;
    case 0x80015390u: goto label_80015390;
    case 0x80015394u: goto label_80015394;
    case 0x80015398u: goto label_80015398;
    case 0x8001539Cu: goto label_8001539C;
    case 0x800153A0u: goto label_800153A0;
    case 0x800153A4u: goto label_800153A4;
    case 0x800153A8u: goto label_800153A8;
    case 0x800153ACu: goto label_800153AC;
    case 0x800153B0u: goto label_800153B0;
    case 0x800153B4u: goto label_800153B4;
    case 0x800153B8u: goto label_800153B8;
    case 0x800153BCu: goto label_800153BC;
    case 0x800153C0u: goto label_800153C0;
    case 0x800153C4u: goto label_800153C4;
    case 0x800153C8u: goto label_800153C8;
    case 0x800153CCu: goto label_800153CC;
    case 0x800153D0u: goto label_800153D0;
    case 0x800153D4u: goto label_800153D4;
    case 0x800153D8u: goto label_800153D8;
    case 0x800153DCu: goto label_800153DC;
    case 0x800153E0u: goto label_800153E0;
    case 0x800153E4u: goto label_800153E4;
    case 0x800153E8u: goto label_800153E8;
    case 0x800153ECu: goto label_800153EC;
    case 0x800153F0u: goto label_800153F0;
    case 0x800153F4u: goto label_800153F4;
    case 0x800153F8u: goto label_800153F8;
    case 0x800153FCu: goto label_800153FC;
    case 0x80015400u: goto label_80015400;
    case 0x80015404u: goto label_80015404;
    case 0x80015408u: goto label_80015408;
    case 0x8001540Cu: goto label_8001540C;
    case 0x80015410u: goto label_80015410;
    case 0x80015414u: goto label_80015414;
    case 0x80015418u: goto label_80015418;
    case 0x8001541Cu: goto label_8001541C;
    case 0x80015420u: goto label_80015420;
    case 0x80015424u: goto label_80015424;
    case 0x80015428u: goto label_80015428;
    case 0x8001542Cu: goto label_8001542C;
    case 0x80015430u: goto label_80015430;
    case 0x80015434u: goto label_80015434;
    case 0x80015438u: goto label_80015438;
    case 0x8001543Cu: goto label_8001543C;
    case 0x80015440u: goto label_80015440;
    case 0x80015444u: goto label_80015444;
    case 0x80015448u: goto label_80015448;
    case 0x8001544Cu: goto label_8001544C;
    case 0x80015450u: goto label_80015450;
    case 0x80015454u: goto label_80015454;
    case 0x80015458u: goto label_80015458;
    case 0x8001545Cu: goto label_8001545C;
    case 0x80015460u: goto label_80015460;
    case 0x80015464u: goto label_80015464;
    case 0x80015468u: goto label_80015468;
    case 0x8001546Cu: goto label_8001546C;
    case 0x80015470u: goto label_80015470;
    case 0x80015474u: goto label_80015474;
    case 0x80015478u: goto label_80015478;
    case 0x8001547Cu: goto label_8001547C;
    case 0x80015480u: goto label_80015480;
    case 0x80015484u: goto label_80015484;
    case 0x80015488u: goto label_80015488;
    case 0x8001548Cu: goto label_8001548C;
    case 0x80015490u: goto label_80015490;
    case 0x80015494u: goto label_80015494;
    case 0x80015498u: goto label_80015498;
    case 0x8001549Cu: goto label_8001549C;
    case 0x800154A0u: goto label_800154A0;
    case 0x800154A4u: goto label_800154A4;
    case 0x800154A8u: goto label_800154A8;
    case 0x800154ACu: goto label_800154AC;
    case 0x800154B0u: goto label_800154B0;
    case 0x800154B4u: goto label_800154B4;
    case 0x800154B8u: goto label_800154B8;
    case 0x800154BCu: goto label_800154BC;
    case 0x800154C0u: goto label_800154C0;
    case 0x800154C4u: goto label_800154C4;
    case 0x800154C8u: goto label_800154C8;
    case 0x800154CCu: goto label_800154CC;
    case 0x800154D0u: goto label_800154D0;
    case 0x800154D4u: goto label_800154D4;
    case 0x800154D8u: goto label_800154D8;
    case 0x800154DCu: goto label_800154DC;
    case 0x800154E0u: goto label_800154E0;
    case 0x800154E4u: goto label_800154E4;
    case 0x800154E8u: goto label_800154E8;
    case 0x800154ECu: goto label_800154EC;
    case 0x800154F0u: goto label_800154F0;
    case 0x800154F4u: goto label_800154F4;
    case 0x800154F8u: goto label_800154F8;
    case 0x800154FCu: goto label_800154FC;
    case 0x80015500u: goto label_80015500;
    case 0x80015504u: goto label_80015504;
    case 0x80015508u: goto label_80015508;
    case 0x8001550Cu: goto label_8001550C;
    case 0x80015510u: goto label_80015510;
    case 0x80015514u: goto label_80015514;
    case 0x80015518u: goto label_80015518;
    case 0x8001551Cu: goto label_8001551C;
    case 0x80015520u: goto label_80015520;
    case 0x80015524u: goto label_80015524;
    case 0x80015528u: goto label_80015528;
    case 0x8001552Cu: goto label_8001552C;
    case 0x80015530u: goto label_80015530;
    case 0x80015534u: goto label_80015534;
    case 0x80015538u: goto label_80015538;
    case 0x8001553Cu: goto label_8001553C;
    case 0x80015540u: goto label_80015540;
    case 0x80015544u: goto label_80015544;
    case 0x80015548u: goto label_80015548;
    case 0x8001554Cu: goto label_8001554C;
    case 0x80015550u: goto label_80015550;
    case 0x80015554u: goto label_80015554;
    case 0x80015558u: goto label_80015558;
    case 0x8001555Cu: goto label_8001555C;
    case 0x80015560u: goto label_80015560;
    case 0x80015564u: goto label_80015564;
    case 0x80015568u: goto label_80015568;
    case 0x8001556Cu: goto label_8001556C;
    case 0x80015570u: goto label_80015570;
    case 0x80015574u: goto label_80015574;
    case 0x80015578u: goto label_80015578;
    case 0x8001557Cu: goto label_8001557C;
    case 0x80015580u: goto label_80015580;
    case 0x80015584u: goto label_80015584;
    case 0x80015588u: goto label_80015588;
    case 0x8001558Cu: goto label_8001558C;
    case 0x80015590u: goto label_80015590;
    case 0x80015594u: goto label_80015594;
    case 0x80015598u: goto label_80015598;
    case 0x8001559Cu: goto label_8001559C;
    case 0x800155A0u: goto label_800155A0;
    case 0x800155A4u: goto label_800155A4;
    case 0x800155A8u: goto label_800155A8;
    case 0x800155ACu: goto label_800155AC;
    case 0x800155B0u: goto label_800155B0;
    case 0x800155B4u: goto label_800155B4;
    case 0x800155B8u: goto label_800155B8;
    case 0x800155BCu: goto label_800155BC;
    case 0x800155C0u: goto label_800155C0;
    case 0x800155C4u: goto label_800155C4;
    case 0x800155C8u: goto label_800155C8;
    case 0x800155CCu: goto label_800155CC;
    case 0x800155D0u: goto label_800155D0;
    case 0x800155D4u: goto label_800155D4;
    case 0x800155D8u: goto label_800155D8;
    case 0x800155DCu: goto label_800155DC;
    case 0x800155E0u: goto label_800155E0;
    case 0x800155E4u: goto label_800155E4;
    case 0x800155E8u: goto label_800155E8;
    case 0x800155ECu: goto label_800155EC;
    case 0x800155F0u: goto label_800155F0;
    case 0x800155F4u: goto label_800155F4;
    case 0x800155F8u: goto label_800155F8;
    case 0x800155FCu: goto label_800155FC;
    case 0x80015600u: goto label_80015600;
    case 0x80015604u: goto label_80015604;
    case 0x80015608u: goto label_80015608;
    case 0x8001560Cu: goto label_8001560C;
    case 0x80015610u: goto label_80015610;
    case 0x80015614u: goto label_80015614;
    case 0x80015618u: goto label_80015618;
    case 0x8001561Cu: goto label_8001561C;
    case 0x80015620u: goto label_80015620;
    case 0x80015624u: goto label_80015624;
    case 0x80015628u: goto label_80015628;
    case 0x8001562Cu: goto label_8001562C;
    case 0x80015630u: goto label_80015630;
    case 0x80015634u: goto label_80015634;
    case 0x80015638u: goto label_80015638;
    case 0x8001563Cu: goto label_8001563C;
    case 0x80015640u: goto label_80015640;
    case 0x80015644u: goto label_80015644;
    case 0x80015648u: goto label_80015648;
    case 0x8001564Cu: goto label_8001564C;
    case 0x80015650u: goto label_80015650;
    case 0x80015654u: goto label_80015654;
    case 0x80015658u: goto label_80015658;
    case 0x8001565Cu: goto label_8001565C;
    case 0x80015660u: goto label_80015660;
    case 0x80015664u: goto label_80015664;
    case 0x80015668u: goto label_80015668;
    case 0x8001566Cu: goto label_8001566C;
    case 0x80015670u: goto label_80015670;
    case 0x80015674u: goto label_80015674;
    case 0x80015678u: goto label_80015678;
    case 0x8001567Cu: goto label_8001567C;
    case 0x80015680u: goto label_80015680;
    case 0x80015684u: goto label_80015684;
    case 0x80015688u: goto label_80015688;
    case 0x8001568Cu: goto label_8001568C;
    case 0x80015690u: goto label_80015690;
    case 0x80015694u: goto label_80015694;
    case 0x80015698u: goto label_80015698;
    case 0x8001569Cu: goto label_8001569C;
    case 0x800156A0u: goto label_800156A0;
    case 0x800156A4u: goto label_800156A4;
    case 0x800156A8u: goto label_800156A8;
    case 0x800156ACu: goto label_800156AC;
    case 0x800156B0u: goto label_800156B0;
    case 0x800156B4u: goto label_800156B4;
    case 0x800156B8u: goto label_800156B8;
    case 0x800156BCu: goto label_800156BC;
    case 0x800156C0u: goto label_800156C0;
    case 0x800156C4u: goto label_800156C4;
    case 0x800156C8u: goto label_800156C8;
    case 0x800156CCu: goto label_800156CC;
    case 0x800156D0u: goto label_800156D0;
    case 0x800156D4u: goto label_800156D4;
    case 0x800156D8u: goto label_800156D8;
    case 0x800156DCu: goto label_800156DC;
    case 0x800156E0u: goto label_800156E0;
    case 0x800156E4u: goto label_800156E4;
    case 0x800156E8u: goto label_800156E8;
    case 0x800156ECu: goto label_800156EC;
    case 0x800156F0u: goto label_800156F0;
    case 0x800156F4u: goto label_800156F4;
    case 0x800156F8u: goto label_800156F8;
    case 0x800156FCu: goto label_800156FC;
    case 0x80015700u: goto label_80015700;
    case 0x80015704u: goto label_80015704;
    case 0x80015708u: goto label_80015708;
    case 0x8001570Cu: goto label_8001570C;
    case 0x80015710u: goto label_80015710;
    case 0x80015714u: goto label_80015714;
    case 0x80015718u: goto label_80015718;
    case 0x8001571Cu: goto label_8001571C;
    case 0x80015720u: goto label_80015720;
    case 0x80015724u: goto label_80015724;
    case 0x80015728u: goto label_80015728;
    case 0x8001572Cu: goto label_8001572C;
    case 0x80015730u: goto label_80015730;
    case 0x80015734u: goto label_80015734;
    case 0x80015738u: goto label_80015738;
    case 0x8001573Cu: goto label_8001573C;
    case 0x80015740u: goto label_80015740;
    case 0x80015744u: goto label_80015744;
    case 0x80015748u: goto label_80015748;
    case 0x8001574Cu: goto label_8001574C;
    case 0x80015750u: goto label_80015750;
    case 0x80015754u: goto label_80015754;
    case 0x80015758u: goto label_80015758;
    case 0x8001575Cu: goto label_8001575C;
    case 0x80015760u: goto label_80015760;
    case 0x80015764u: goto label_80015764;
    case 0x80015768u: goto label_80015768;
    case 0x8001576Cu: goto label_8001576C;
    case 0x80015770u: goto label_80015770;
    case 0x80015774u: goto label_80015774;
    case 0x80015778u: goto label_80015778;
    case 0x8001577Cu: goto label_8001577C;
    case 0x80015780u: goto label_80015780;
    case 0x80015784u: goto label_80015784;
    case 0x80015788u: goto label_80015788;
    case 0x8001578Cu: goto label_8001578C;
    case 0x80015790u: goto label_80015790;
    case 0x80015794u: goto label_80015794;
    case 0x80015798u: goto label_80015798;
    case 0x8001579Cu: goto label_8001579C;
    case 0x800157A0u: goto label_800157A0;
    case 0x800157A4u: goto label_800157A4;
    case 0x800157A8u: goto label_800157A8;
    case 0x800157ACu: goto label_800157AC;
    case 0x800157B0u: goto label_800157B0;
    case 0x800157B4u: goto label_800157B4;
    case 0x800157B8u: goto label_800157B8;
    case 0x800157BCu: goto label_800157BC;
    case 0x800157C0u: goto label_800157C0;
    case 0x800157C4u: goto label_800157C4;
    case 0x800157C8u: goto label_800157C8;
    case 0x800157CCu: goto label_800157CC;
    case 0x800157D0u: goto label_800157D0;
    case 0x800157D4u: goto label_800157D4;
    case 0x800157D8u: goto label_800157D8;
    case 0x800157DCu: goto label_800157DC;
    case 0x800157E0u: goto label_800157E0;
    case 0x800157E4u: goto label_800157E4;
    case 0x800157E8u: goto label_800157E8;
    case 0x800157ECu: goto label_800157EC;
    case 0x800157F0u: goto label_800157F0;
    case 0x800157F4u: goto label_800157F4;
    case 0x800157F8u: goto label_800157F8;
    case 0x800157FCu: goto label_800157FC;
    case 0x80015800u: goto label_80015800;
    case 0x80015804u: goto label_80015804;
    case 0x80015808u: goto label_80015808;
    case 0x8001580Cu: goto label_8001580C;
    case 0x80015810u: goto label_80015810;
    case 0x80015814u: goto label_80015814;
    case 0x80015818u: goto label_80015818;
    case 0x8001581Cu: goto label_8001581C;
    case 0x80015820u: goto label_80015820;
    case 0x80015824u: goto label_80015824;
    case 0x80015828u: goto label_80015828;
    case 0x8001582Cu: goto label_8001582C;
    case 0x80015830u: goto label_80015830;
    case 0x80015834u: goto label_80015834;
    case 0x80015838u: goto label_80015838;
    case 0x8001583Cu: goto label_8001583C;
    case 0x80015840u: goto label_80015840;
    case 0x80015844u: goto label_80015844;
    case 0x80015848u: goto label_80015848;
    case 0x8001584Cu: goto label_8001584C;
    case 0x80015850u: goto label_80015850;
    case 0x80015854u: goto label_80015854;
    case 0x80015858u: goto label_80015858;
    case 0x8001585Cu: goto label_8001585C;
    case 0x80015860u: goto label_80015860;
    case 0x80015864u: goto label_80015864;
    case 0x80015868u: goto label_80015868;
    case 0x8001586Cu: goto label_8001586C;
    case 0x80015870u: goto label_80015870;
    case 0x80015874u: goto label_80015874;
    case 0x80015878u: goto label_80015878;
    case 0x8001587Cu: goto label_8001587C;
    case 0x80015880u: goto label_80015880;
    case 0x80015884u: goto label_80015884;
    case 0x80015888u: goto label_80015888;
    case 0x8001588Cu: goto label_8001588C;
    case 0x80015890u: goto label_80015890;
    case 0x80015894u: goto label_80015894;
    case 0x80015898u: goto label_80015898;
    case 0x8001589Cu: goto label_8001589C;
    case 0x800158A0u: goto label_800158A0;
    case 0x800158A4u: goto label_800158A4;
    case 0x800158A8u: goto label_800158A8;
    case 0x800158ACu: goto label_800158AC;
    case 0x800158B0u: goto label_800158B0;
    case 0x800158B4u: goto label_800158B4;
    case 0x800158B8u: goto label_800158B8;
    case 0x800158BCu: goto label_800158BC;
    case 0x800158C0u: goto label_800158C0;
    case 0x800158C4u: goto label_800158C4;
    case 0x800158C8u: goto label_800158C8;
    case 0x800158CCu: goto label_800158CC;
    case 0x800158D0u: goto label_800158D0;
    case 0x800158D4u: goto label_800158D4;
    case 0x800158D8u: goto label_800158D8;
    case 0x800158DCu: goto label_800158DC;
    case 0x800158E0u: goto label_800158E0;
    case 0x800158E4u: goto label_800158E4;
    case 0x800158E8u: goto label_800158E8;
    case 0x800158ECu: goto label_800158EC;
    case 0x800158F0u: goto label_800158F0;
    case 0x800158F4u: goto label_800158F4;
    case 0x800158F8u: goto label_800158F8;
    case 0x800158FCu: goto label_800158FC;
    case 0x80015900u: goto label_80015900;
    case 0x80015904u: goto label_80015904;
    case 0x80015908u: goto label_80015908;
    case 0x8001590Cu: goto label_8001590C;
    case 0x80015910u: goto label_80015910;
    case 0x80015914u: goto label_80015914;
    case 0x80015918u: goto label_80015918;
    case 0x8001591Cu: goto label_8001591C;
    case 0x80015920u: goto label_80015920;
    case 0x80015924u: goto label_80015924;
    case 0x80015928u: goto label_80015928;
    case 0x8001592Cu: goto label_8001592C;
    case 0x80015930u: goto label_80015930;
    case 0x80015934u: goto label_80015934;
    case 0x80015938u: goto label_80015938;
    case 0x8001593Cu: goto label_8001593C;
    case 0x80015940u: goto label_80015940;
    case 0x80015944u: goto label_80015944;
    case 0x80015948u: goto label_80015948;
    case 0x8001594Cu: goto label_8001594C;
    case 0x80015950u: goto label_80015950;
    case 0x80015954u: goto label_80015954;
    case 0x80015958u: goto label_80015958;
    case 0x8001595Cu: goto label_8001595C;
    case 0x80015960u: goto label_80015960;
    case 0x80015964u: goto label_80015964;
    case 0x80015968u: goto label_80015968;
    case 0x8001596Cu: goto label_8001596C;
    case 0x80015970u: goto label_80015970;
    case 0x80015974u: goto label_80015974;
    case 0x80015978u: goto label_80015978;
    case 0x8001597Cu: goto label_8001597C;
    case 0x80015980u: goto label_80015980;
    case 0x80015984u: goto label_80015984;
    case 0x80015988u: goto label_80015988;
    case 0x8001598Cu: goto label_8001598C;
    case 0x80015990u: goto label_80015990;
    case 0x80015994u: goto label_80015994;
    case 0x80015998u: goto label_80015998;
    case 0x8001599Cu: goto label_8001599C;
    case 0x800159A0u: goto label_800159A0;
    case 0x800159A4u: goto label_800159A4;
    case 0x800159A8u: goto label_800159A8;
    case 0x800159ACu: goto label_800159AC;
    case 0x800159B0u: goto label_800159B0;
    case 0x800159B4u: goto label_800159B4;
    case 0x800159B8u: goto label_800159B8;
    case 0x800159BCu: goto label_800159BC;
    case 0x800159C0u: goto label_800159C0;
    case 0x800159C4u: goto label_800159C4;
    case 0x800159C8u: goto label_800159C8;
    case 0x800159CCu: goto label_800159CC;
    case 0x800159D0u: goto label_800159D0;
    case 0x800159D4u: goto label_800159D4;
    case 0x800159D8u: goto label_800159D8;
    case 0x800159DCu: goto label_800159DC;
    case 0x800159E0u: goto label_800159E0;
    case 0x800159E4u: goto label_800159E4;
    case 0x800159E8u: goto label_800159E8;
    case 0x800159ECu: goto label_800159EC;
    case 0x800159F0u: goto label_800159F0;
    case 0x800159F4u: goto label_800159F4;
    case 0x800159F8u: goto label_800159F8;
    case 0x800159FCu: goto label_800159FC;
    case 0x80015A00u: goto label_80015A00;
    case 0x80015A04u: goto label_80015A04;
    case 0x80015A08u: goto label_80015A08;
    case 0x80015A0Cu: goto label_80015A0C;
    case 0x80015A10u: goto label_80015A10;
    case 0x80015A14u: goto label_80015A14;
    case 0x80015A18u: goto label_80015A18;
    case 0x80015A1Cu: goto label_80015A1C;
    case 0x80015A20u: goto label_80015A20;
    case 0x80015A24u: goto label_80015A24;
    case 0x80015A28u: goto label_80015A28;
    case 0x80015A2Cu: goto label_80015A2C;
    case 0x80015A30u: goto label_80015A30;
    case 0x80015A34u: goto label_80015A34;
    case 0x80015A38u: goto label_80015A38;
    case 0x80015A3Cu: goto label_80015A3C;
    case 0x80015A40u: goto label_80015A40;
    case 0x80015A44u: goto label_80015A44;
    case 0x80015A48u: goto label_80015A48;
    case 0x80015A4Cu: goto label_80015A4C;
    case 0x80015A50u: goto label_80015A50;
    case 0x80015A54u: goto label_80015A54;
    case 0x80015A58u: goto label_80015A58;
    case 0x80015A5Cu: goto label_80015A5C;
    case 0x80015A60u: goto label_80015A60;
    case 0x80015A64u: goto label_80015A64;
    case 0x80015A68u: goto label_80015A68;
    case 0x80015A6Cu: goto label_80015A6C;
    case 0x80015A70u: goto label_80015A70;
    case 0x80015A74u: goto label_80015A74;
    case 0x80015A78u: goto label_80015A78;
    case 0x80015A7Cu: goto label_80015A7C;
    case 0x80015A80u: goto label_80015A80;
    case 0x80015A84u: goto label_80015A84;
    case 0x80015A88u: goto label_80015A88;
    case 0x80015A8Cu: goto label_80015A8C;
    case 0x80015A90u: goto label_80015A90;
    case 0x80015A94u: goto label_80015A94;
    case 0x80015A98u: goto label_80015A98;
    case 0x80015A9Cu: goto label_80015A9C;
    case 0x80015AA0u: goto label_80015AA0;
    case 0x80015AA4u: goto label_80015AA4;
    case 0x80015AA8u: goto label_80015AA8;
    case 0x80015AACu: goto label_80015AAC;
    case 0x80015AB0u: goto label_80015AB0;
    case 0x80015AB4u: goto label_80015AB4;
    case 0x80015AB8u: goto label_80015AB8;
    case 0x80015ABCu: goto label_80015ABC;
    case 0x80015AC0u: goto label_80015AC0;
    case 0x80015AC4u: goto label_80015AC4;
    case 0x80015AC8u: goto label_80015AC8;
    case 0x80015ACCu: goto label_80015ACC;
    case 0x80015AD0u: goto label_80015AD0;
    case 0x80015AD4u: goto label_80015AD4;
    case 0x80015AD8u: goto label_80015AD8;
    case 0x80015ADCu: goto label_80015ADC;
    case 0x80015AE0u: goto label_80015AE0;
    case 0x80015AE4u: goto label_80015AE4;
    case 0x80015AE8u: goto label_80015AE8;
    case 0x80015AECu: goto label_80015AEC;
    case 0x80015AF0u: goto label_80015AF0;
    case 0x80015AF4u: goto label_80015AF4;
    case 0x80015AF8u: goto label_80015AF8;
    case 0x80015AFCu: goto label_80015AFC;
    case 0x80015B00u: goto label_80015B00;
    case 0x80015B04u: goto label_80015B04;
    case 0x80015B08u: goto label_80015B08;
    case 0x80015B0Cu: goto label_80015B0C;
    case 0x80015B10u: goto label_80015B10;
    case 0x80015B14u: goto label_80015B14;
    case 0x80015B18u: goto label_80015B18;
    case 0x80015B1Cu: goto label_80015B1C;
    case 0x80015B20u: goto label_80015B20;
    case 0x80015B24u: goto label_80015B24;
    case 0x80015B28u: goto label_80015B28;
    case 0x80015B2Cu: goto label_80015B2C;
    case 0x80015B30u: goto label_80015B30;
    case 0x80015B34u: goto label_80015B34;
    case 0x80015B38u: goto label_80015B38;
    case 0x80015B3Cu: goto label_80015B3C;
    case 0x80015B40u: goto label_80015B40;
    case 0x80015B44u: goto label_80015B44;
    case 0x80015B48u: goto label_80015B48;
    case 0x80015B4Cu: goto label_80015B4C;
    case 0x80015B50u: goto label_80015B50;
    case 0x80015B54u: goto label_80015B54;
    case 0x80015B58u: goto label_80015B58;
    case 0x80015B5Cu: goto label_80015B5C;
    case 0x80015B60u: goto label_80015B60;
    case 0x80015B64u: goto label_80015B64;
    case 0x80015B68u: goto label_80015B68;
    case 0x80015B6Cu: goto label_80015B6C;
    case 0x80015B70u: goto label_80015B70;
    case 0x80015B74u: goto label_80015B74;
    case 0x80015B78u: goto label_80015B78;
    case 0x80015B7Cu: goto label_80015B7C;
    case 0x80015B80u: goto label_80015B80;
    case 0x80015B84u: goto label_80015B84;
    case 0x80015B88u: goto label_80015B88;
    case 0x80015B8Cu: goto label_80015B8C;
    case 0x80015B90u: goto label_80015B90;
    case 0x80015B94u: goto label_80015B94;
    case 0x80015B98u: goto label_80015B98;
    case 0x80015B9Cu: goto label_80015B9C;
    case 0x80015BA0u: goto label_80015BA0;
    case 0x80015BA4u: goto label_80015BA4;
    case 0x80015BA8u: goto label_80015BA8;
    case 0x80015BACu: goto label_80015BAC;
    case 0x80015BB0u: goto label_80015BB0;
    case 0x80015BB4u: goto label_80015BB4;
    case 0x80015BB8u: goto label_80015BB8;
    case 0x80015BBCu: goto label_80015BBC;
    case 0x80015BC0u: goto label_80015BC0;
    case 0x80015BC4u: goto label_80015BC4;
    case 0x80015BC8u: goto label_80015BC8;
    case 0x80015BCCu: goto label_80015BCC;
    case 0x80015BD0u: goto label_80015BD0;
    case 0x80015BD4u: goto label_80015BD4;
    case 0x80015BD8u: goto label_80015BD8;
    case 0x80015BDCu: goto label_80015BDC;
    case 0x80015BE0u: goto label_80015BE0;
    case 0x80015BE4u: goto label_80015BE4;
    case 0x80015BE8u: goto label_80015BE8;
    case 0x80015BECu: goto label_80015BEC;
    case 0x80015BF0u: goto label_80015BF0;
    case 0x80015BF4u: goto label_80015BF4;
    case 0x80015BF8u: goto label_80015BF8;
    case 0x80015BFCu: goto label_80015BFC;
    case 0x80015C00u: goto label_80015C00;
    case 0x80015C04u: goto label_80015C04;
    case 0x80015C08u: goto label_80015C08;
    case 0x80015C0Cu: goto label_80015C0C;
    case 0x80015C10u: goto label_80015C10;
    case 0x80015C14u: goto label_80015C14;
    case 0x80015C18u: goto label_80015C18;
    case 0x80015C1Cu: goto label_80015C1C;
    case 0x80015C20u: goto label_80015C20;
    case 0x80015C24u: goto label_80015C24;
    case 0x80015C28u: goto label_80015C28;
    case 0x80015C2Cu: goto label_80015C2C;
    case 0x80015C30u: goto label_80015C30;
    case 0x80015C34u: goto label_80015C34;
    case 0x80015C38u: goto label_80015C38;
    case 0x80015C3Cu: goto label_80015C3C;
    case 0x80015C40u: goto label_80015C40;
    case 0x80015C44u: goto label_80015C44;
    case 0x80015C48u: goto label_80015C48;
    case 0x80015C4Cu: goto label_80015C4C;
    case 0x80015C50u: goto label_80015C50;
    case 0x80015C54u: goto label_80015C54;
    case 0x80015C58u: goto label_80015C58;
    case 0x80015C5Cu: goto label_80015C5C;
    case 0x80015C60u: goto label_80015C60;
    case 0x80015C64u: goto label_80015C64;
    case 0x80015C68u: goto label_80015C68;
    case 0x80015C6Cu: goto label_80015C6C;
    case 0x80015C70u: goto label_80015C70;
    case 0x80015C74u: goto label_80015C74;
    case 0x80015C78u: goto label_80015C78;
    case 0x80015C7Cu: goto label_80015C7C;
    case 0x80015C80u: goto label_80015C80;
    case 0x80015C84u: goto label_80015C84;
    case 0x80015C88u: goto label_80015C88;
    case 0x80015C8Cu: goto label_80015C8C;
    case 0x80015C90u: goto label_80015C90;
    case 0x80015C94u: goto label_80015C94;
    case 0x80015C98u: goto label_80015C98;
    case 0x80015C9Cu: goto label_80015C9C;
    case 0x80015CA0u: goto label_80015CA0;
    case 0x80015CA4u: goto label_80015CA4;
    case 0x80015CA8u: goto label_80015CA8;
    case 0x80015CACu: goto label_80015CAC;
    case 0x80015CB0u: goto label_80015CB0;
    case 0x80015CB4u: goto label_80015CB4;
    case 0x80015CB8u: goto label_80015CB8;
    case 0x80015CBCu: goto label_80015CBC;
    case 0x80015CC0u: goto label_80015CC0;
    case 0x80015CC4u: goto label_80015CC4;
    case 0x80015CC8u: goto label_80015CC8;
    case 0x80015CCCu: goto label_80015CCC;
    case 0x80015CD0u: goto label_80015CD0;
    case 0x80015CD4u: goto label_80015CD4;
    case 0x80015CD8u: goto label_80015CD8;
    case 0x80015CDCu: goto label_80015CDC;
    case 0x80015CE0u: goto label_80015CE0;
    case 0x80015CE4u: goto label_80015CE4;
    case 0x80015CE8u: goto label_80015CE8;
    case 0x80015CECu: goto label_80015CEC;
    case 0x80015CF0u: goto label_80015CF0;
    case 0x80015CF4u: goto label_80015CF4;
    case 0x80015CF8u: goto label_80015CF8;
    case 0x80015CFCu: goto label_80015CFC;
    case 0x80015D00u: goto label_80015D00;
    case 0x80015D04u: goto label_80015D04;
    case 0x80015D08u: goto label_80015D08;
    case 0x80015D0Cu: goto label_80015D0C;
    case 0x80015D10u: goto label_80015D10;
    case 0x80015D14u: goto label_80015D14;
    case 0x80015D18u: goto label_80015D18;
    case 0x80015D1Cu: goto label_80015D1C;
    case 0x80015D20u: goto label_80015D20;
    case 0x80015D24u: goto label_80015D24;
    case 0x80015D28u: goto label_80015D28;
    case 0x80015D2Cu: goto label_80015D2C;
    case 0x80015D30u: goto label_80015D30;
    case 0x80015D34u: goto label_80015D34;
    case 0x80015D38u: goto label_80015D38;
    case 0x80015D3Cu: goto label_80015D3C;
    case 0x80015D40u: goto label_80015D40;
    case 0x80015D44u: goto label_80015D44;
    case 0x80015D48u: goto label_80015D48;
    case 0x80015D4Cu: goto label_80015D4C;
    case 0x80015D50u: goto label_80015D50;
    case 0x80015D54u: goto label_80015D54;
    case 0x80015D58u: goto label_80015D58;
    case 0x80015D5Cu: goto label_80015D5C;
    case 0x80015D60u: goto label_80015D60;
    case 0x80015D64u: goto label_80015D64;
    case 0x80015D68u: goto label_80015D68;
    case 0x80015D6Cu: goto label_80015D6C;
    case 0x80015D70u: goto label_80015D70;
    case 0x80015D74u: goto label_80015D74;
    case 0x80015D78u: goto label_80015D78;
    case 0x80015D7Cu: goto label_80015D7C;
    case 0x80015D80u: goto label_80015D80;
    case 0x80015D84u: goto label_80015D84;
    case 0x80015D88u: goto label_80015D88;
    case 0x80015D8Cu: goto label_80015D8C;
    case 0x80015D90u: goto label_80015D90;
    case 0x80015D94u: goto label_80015D94;
    case 0x80015D98u: goto label_80015D98;
    case 0x80015D9Cu: goto label_80015D9C;
    case 0x80015DA0u: goto label_80015DA0;
    case 0x80015DA4u: goto label_80015DA4;
    case 0x80015DA8u: goto label_80015DA8;
    case 0x80015DACu: goto label_80015DAC;
    case 0x80015DB0u: goto label_80015DB0;
    case 0x80015DB4u: goto label_80015DB4;
    case 0x80015DB8u: goto label_80015DB8;
    case 0x80015DBCu: goto label_80015DBC;
    case 0x80015DC0u: goto label_80015DC0;
    case 0x80015DC4u: goto label_80015DC4;
    case 0x80015DC8u: goto label_80015DC8;
    case 0x80015DCCu: goto label_80015DCC;
    case 0x80015DD0u: goto label_80015DD0;
    case 0x80015DD4u: goto label_80015DD4;
    case 0x80015DD8u: goto label_80015DD8;
    case 0x80015DDCu: goto label_80015DDC;
    case 0x80015DE0u: goto label_80015DE0;
    case 0x80015DE4u: goto label_80015DE4;
    case 0x80015DE8u: goto label_80015DE8;
    case 0x80015DECu: goto label_80015DEC;
    case 0x80015DF0u: goto label_80015DF0;
    case 0x80015DF4u: goto label_80015DF4;
    case 0x80015DF8u: goto label_80015DF8;
    case 0x80015DFCu: goto label_80015DFC;
    case 0x80015E00u: goto label_80015E00;
    case 0x80015E04u: goto label_80015E04;
    case 0x80015E08u: goto label_80015E08;
    case 0x80015E0Cu: goto label_80015E0C;
    case 0x80015E10u: goto label_80015E10;
    case 0x80015E14u: goto label_80015E14;
    case 0x80015E18u: goto label_80015E18;
    case 0x80015E1Cu: goto label_80015E1C;
    case 0x80015E20u: goto label_80015E20;
    case 0x80015E24u: goto label_80015E24;
    case 0x80015E28u: goto label_80015E28;
    case 0x80015E2Cu: goto label_80015E2C;
    case 0x80015E30u: goto label_80015E30;
    case 0x80015E34u: goto label_80015E34;
    case 0x80015E38u: goto label_80015E38;
    case 0x80015E3Cu: goto label_80015E3C;
    case 0x80015E40u: goto label_80015E40;
    case 0x80015E44u: goto label_80015E44;
    case 0x80015E48u: goto label_80015E48;
    case 0x80015E4Cu: goto label_80015E4C;
    case 0x80015E50u: goto label_80015E50;
    case 0x80015E54u: goto label_80015E54;
    case 0x80015E58u: goto label_80015E58;
    case 0x80015E5Cu: goto label_80015E5C;
    case 0x80015E60u: goto label_80015E60;
    case 0x80015E64u: goto label_80015E64;
    case 0x80015E68u: goto label_80015E68;
    case 0x80015E6Cu: goto label_80015E6C;
    case 0x80015E70u: goto label_80015E70;
    case 0x80015E74u: goto label_80015E74;
    case 0x80015E78u: goto label_80015E78;
    case 0x80015E7Cu: goto label_80015E7C;
    case 0x80015E80u: goto label_80015E80;
    case 0x80015E84u: goto label_80015E84;
    case 0x80015E88u: goto label_80015E88;
    case 0x80015E8Cu: goto label_80015E8C;
    case 0x80015E90u: goto label_80015E90;
    case 0x80015E94u: goto label_80015E94;
    case 0x80015E98u: goto label_80015E98;
    case 0x80015E9Cu: goto label_80015E9C;
    case 0x80015EA0u: goto label_80015EA0;
    case 0x80015EA4u: goto label_80015EA4;
    case 0x80015EA8u: goto label_80015EA8;
    case 0x80015EACu: goto label_80015EAC;
    case 0x80015EB0u: goto label_80015EB0;
    case 0x80015EB4u: goto label_80015EB4;
    case 0x80015EB8u: goto label_80015EB8;
    case 0x80015EBCu: goto label_80015EBC;
    case 0x80015EC0u: goto label_80015EC0;
    case 0x80015EC4u: goto label_80015EC4;
    case 0x80015EC8u: goto label_80015EC8;
    case 0x80015ECCu: goto label_80015ECC;
    case 0x80015ED0u: goto label_80015ED0;
    case 0x80015ED4u: goto label_80015ED4;
    case 0x80015ED8u: goto label_80015ED8;
    case 0x80015EDCu: goto label_80015EDC;
    case 0x80015EE0u: goto label_80015EE0;
    case 0x80015EE4u: goto label_80015EE4;
    case 0x80015EE8u: goto label_80015EE8;
    case 0x80015EECu: goto label_80015EEC;
    case 0x80015EF0u: goto label_80015EF0;
    case 0x80015EF4u: goto label_80015EF4;
    case 0x80015EF8u: goto label_80015EF8;
    case 0x80015EFCu: goto label_80015EFC;
    case 0x80015F00u: goto label_80015F00;
    case 0x80015F04u: goto label_80015F04;
    case 0x80015F08u: goto label_80015F08;
    case 0x80015F0Cu: goto label_80015F0C;
    case 0x80015F10u: goto label_80015F10;
    case 0x80015F14u: goto label_80015F14;
    case 0x80015F18u: goto label_80015F18;
    case 0x80015F1Cu: goto label_80015F1C;
    case 0x80015F20u: goto label_80015F20;
    case 0x80015F24u: goto label_80015F24;
    case 0x80015F28u: goto label_80015F28;
    case 0x80015F2Cu: goto label_80015F2C;
    case 0x80015F30u: goto label_80015F30;
    case 0x80015F34u: goto label_80015F34;
    case 0x80015F38u: goto label_80015F38;
    case 0x80015F3Cu: goto label_80015F3C;
    case 0x80015F40u: goto label_80015F40;
    case 0x80015F44u: goto label_80015F44;
    case 0x80015F48u: goto label_80015F48;
    case 0x80015F4Cu: goto label_80015F4C;
    case 0x80015F50u: goto label_80015F50;
    case 0x80015F54u: goto label_80015F54;
    case 0x80015F58u: goto label_80015F58;
    case 0x80015F5Cu: goto label_80015F5C;
    case 0x80015F60u: goto label_80015F60;
    case 0x80015F64u: goto label_80015F64;
    case 0x80015F68u: goto label_80015F68;
    case 0x80015F6Cu: goto label_80015F6C;
    case 0x80015F70u: goto label_80015F70;
    case 0x80015F74u: goto label_80015F74;
    case 0x80015F78u: goto label_80015F78;
    case 0x80015F7Cu: goto label_80015F7C;
    case 0x80015F80u: goto label_80015F80;
    case 0x80015F84u: goto label_80015F84;
    case 0x80015F88u: goto label_80015F88;
    case 0x80015F8Cu: goto label_80015F8C;
    case 0x80015F90u: goto label_80015F90;
    case 0x80015F94u: goto label_80015F94;
    case 0x80015F98u: goto label_80015F98;
    case 0x80015F9Cu: goto label_80015F9C;
    case 0x80015FA0u: goto label_80015FA0;
    case 0x80015FA4u: goto label_80015FA4;
    case 0x80015FA8u: goto label_80015FA8;
    case 0x80015FACu: goto label_80015FAC;
    case 0x80015FB0u: goto label_80015FB0;
    case 0x80015FB4u: goto label_80015FB4;
    case 0x80015FB8u: goto label_80015FB8;
    case 0x80015FBCu: goto label_80015FBC;
    case 0x80015FC0u: goto label_80015FC0;
    case 0x80015FC4u: goto label_80015FC4;
    case 0x80015FC8u: goto label_80015FC8;
    case 0x80015FCCu: goto label_80015FCC;
    case 0x80015FD0u: goto label_80015FD0;
    case 0x80015FD4u: goto label_80015FD4;
    case 0x80015FD8u: goto label_80015FD8;
    case 0x80015FDCu: goto label_80015FDC;
    case 0x80015FE0u: goto label_80015FE0;
    case 0x80015FE4u: goto label_80015FE4;
    case 0x80015FE8u: goto label_80015FE8;
    case 0x80015FECu: goto label_80015FEC;
    case 0x80015FF0u: goto label_80015FF0;
    case 0x80015FF4u: goto label_80015FF4;
    case 0x80015FF8u: goto label_80015FF8;
    case 0x80015FFCu: goto label_80015FFC;
    case 0x80016000u: goto label_80016000;
    case 0x80016004u: goto label_80016004;
    case 0x80016008u: goto label_80016008;
    case 0x8001600Cu: goto label_8001600C;
    case 0x80016010u: goto label_80016010;
    case 0x80016014u: goto label_80016014;
    case 0x80016018u: goto label_80016018;
    case 0x8001601Cu: goto label_8001601C;
    case 0x80016020u: goto label_80016020;
    case 0x80016024u: goto label_80016024;
    case 0x80016028u: goto label_80016028;
    case 0x8001602Cu: goto label_8001602C;
    case 0x80016030u: goto label_80016030;
    case 0x80016034u: goto label_80016034;
    case 0x80016038u: goto label_80016038;
    case 0x8001603Cu: goto label_8001603C;
    case 0x80016040u: goto label_80016040;
    case 0x80016044u: goto label_80016044;
    case 0x80016048u: goto label_80016048;
    case 0x8001604Cu: goto label_8001604C;
    case 0x80016050u: goto label_80016050;
    case 0x80016054u: goto label_80016054;
    case 0x80016058u: goto label_80016058;
    case 0x8001605Cu: goto label_8001605C;
    case 0x80016060u: goto label_80016060;
    case 0x80016064u: goto label_80016064;
    case 0x80016068u: goto label_80016068;
    case 0x8001606Cu: goto label_8001606C;
    case 0x80016070u: goto label_80016070;
    case 0x80016074u: goto label_80016074;
    case 0x80016078u: goto label_80016078;
    case 0x8001607Cu: goto label_8001607C;
    case 0x80016080u: goto label_80016080;
    case 0x80016084u: goto label_80016084;
    case 0x80016088u: goto label_80016088;
    case 0x8001608Cu: goto label_8001608C;
    case 0x80016090u: goto label_80016090;
    case 0x80016094u: goto label_80016094;
    case 0x80016098u: goto label_80016098;
    case 0x8001609Cu: goto label_8001609C;
    case 0x800160A0u: goto label_800160A0;
    case 0x800160A4u: goto label_800160A4;
    case 0x800160A8u: goto label_800160A8;
    case 0x800160ACu: goto label_800160AC;
    case 0x800160B0u: goto label_800160B0;
    case 0x800160B4u: goto label_800160B4;
    case 0x800160B8u: goto label_800160B8;
    case 0x800160BCu: goto label_800160BC;
    case 0x800160C0u: goto label_800160C0;
    case 0x800160C4u: goto label_800160C4;
    case 0x800160C8u: goto label_800160C8;
    case 0x800160CCu: goto label_800160CC;
    case 0x800160D0u: goto label_800160D0;
    case 0x800160D4u: goto label_800160D4;
    case 0x800160D8u: goto label_800160D8;
    case 0x800160DCu: goto label_800160DC;
    case 0x800160E0u: goto label_800160E0;
    case 0x800160E4u: goto label_800160E4;
    case 0x800160E8u: goto label_800160E8;
    case 0x800160ECu: goto label_800160EC;
    case 0x800160F0u: goto label_800160F0;
    case 0x800160F4u: goto label_800160F4;
    case 0x800160F8u: goto label_800160F8;
    case 0x800160FCu: goto label_800160FC;
    case 0x80016100u: goto label_80016100;
    case 0x80016104u: goto label_80016104;
    case 0x80016108u: goto label_80016108;
    case 0x8001610Cu: goto label_8001610C;
    case 0x80016110u: goto label_80016110;
    case 0x80016114u: goto label_80016114;
    case 0x80016118u: goto label_80016118;
    case 0x8001611Cu: goto label_8001611C;
    case 0x80016120u: goto label_80016120;
    case 0x80016124u: goto label_80016124;
    case 0x80016128u: goto label_80016128;
    case 0x8001612Cu: goto label_8001612C;
    case 0x80016130u: goto label_80016130;
    case 0x80016134u: goto label_80016134;
    case 0x80016138u: goto label_80016138;
    case 0x8001613Cu: goto label_8001613C;
    case 0x80016140u: goto label_80016140;
    case 0x80016144u: goto label_80016144;
    case 0x80016148u: goto label_80016148;
    case 0x8001614Cu: goto label_8001614C;
    case 0x80016150u: goto label_80016150;
    case 0x80016154u: goto label_80016154;
    case 0x80016158u: goto label_80016158;
    case 0x8001615Cu: goto label_8001615C;
    case 0x80016160u: goto label_80016160;
    case 0x80016164u: goto label_80016164;
    case 0x80016168u: goto label_80016168;
    case 0x8001616Cu: goto label_8001616C;
    case 0x80016170u: goto label_80016170;
    case 0x80016174u: goto label_80016174;
    case 0x80016178u: goto label_80016178;
    case 0x8001617Cu: goto label_8001617C;
    case 0x80016180u: goto label_80016180;
    case 0x80016184u: goto label_80016184;
    case 0x80016188u: goto label_80016188;
    case 0x8001618Cu: goto label_8001618C;
    case 0x80016190u: goto label_80016190;
    case 0x80016194u: goto label_80016194;
    case 0x80016198u: goto label_80016198;
    case 0x8001619Cu: goto label_8001619C;
    case 0x800161A0u: goto label_800161A0;
    case 0x800161A4u: goto label_800161A4;
    case 0x800161A8u: goto label_800161A8;
    case 0x800161ACu: goto label_800161AC;
    case 0x800161B0u: goto label_800161B0;
    case 0x800161B4u: goto label_800161B4;
    case 0x800161B8u: goto label_800161B8;
    case 0x800161BCu: goto label_800161BC;
    case 0x800161C0u: goto label_800161C0;
    case 0x800161C4u: goto label_800161C4;
    case 0x800161C8u: goto label_800161C8;
    case 0x800161CCu: goto label_800161CC;
    case 0x800161D0u: goto label_800161D0;
    case 0x800161D4u: goto label_800161D4;
    case 0x800161D8u: goto label_800161D8;
    case 0x800161DCu: goto label_800161DC;
    case 0x800161E0u: goto label_800161E0;
    case 0x800161E4u: goto label_800161E4;
    case 0x800161E8u: goto label_800161E8;
    case 0x800161ECu: goto label_800161EC;
    case 0x800161F0u: goto label_800161F0;
    case 0x800161F4u: goto label_800161F4;
    case 0x800161F8u: goto label_800161F8;
    case 0x800161FCu: goto label_800161FC;
    case 0x80016200u: goto label_80016200;
    case 0x80016204u: goto label_80016204;
    case 0x80016208u: goto label_80016208;
    case 0x8001620Cu: goto label_8001620C;
    case 0x80016210u: goto label_80016210;
    case 0x80016214u: goto label_80016214;
    case 0x80016218u: goto label_80016218;
    case 0x8001621Cu: goto label_8001621C;
    case 0x80016220u: goto label_80016220;
    case 0x80016224u: goto label_80016224;
    case 0x80016228u: goto label_80016228;
    case 0x8001622Cu: goto label_8001622C;
    case 0x80016230u: goto label_80016230;
    case 0x80016234u: goto label_80016234;
    case 0x80016238u: goto label_80016238;
    case 0x8001623Cu: goto label_8001623C;
    case 0x80016240u: goto label_80016240;
    case 0x80016244u: goto label_80016244;
    case 0x80016248u: goto label_80016248;
    case 0x8001624Cu: goto label_8001624C;
    case 0x80016250u: goto label_80016250;
    case 0x80016254u: goto label_80016254;
    case 0x80016258u: goto label_80016258;
    case 0x8001625Cu: goto label_8001625C;
    case 0x80016260u: goto label_80016260;
    case 0x80016264u: goto label_80016264;
    case 0x80016268u: goto label_80016268;
    case 0x8001626Cu: goto label_8001626C;
    case 0x80016270u: goto label_80016270;
    case 0x80016274u: goto label_80016274;
    case 0x80016278u: goto label_80016278;
    case 0x8001627Cu: goto label_8001627C;
    case 0x80016280u: goto label_80016280;
    case 0x80016284u: goto label_80016284;
    case 0x80016288u: goto label_80016288;
    case 0x8001628Cu: goto label_8001628C;
    case 0x80016290u: goto label_80016290;
    case 0x80016294u: goto label_80016294;
    case 0x80016298u: goto label_80016298;
    case 0x8001629Cu: goto label_8001629C;
    case 0x800162A0u: goto label_800162A0;
    case 0x800162A4u: goto label_800162A4;
    case 0x800162A8u: goto label_800162A8;
    case 0x800162ACu: goto label_800162AC;
    case 0x800162B0u: goto label_800162B0;
    case 0x800162B4u: goto label_800162B4;
    case 0x800162B8u: goto label_800162B8;
    case 0x800162BCu: goto label_800162BC;
    case 0x800162C0u: goto label_800162C0;
    case 0x800162C4u: goto label_800162C4;
    case 0x800162C8u: goto label_800162C8;
    case 0x800162CCu: goto label_800162CC;
    case 0x800162D0u: goto label_800162D0;
    case 0x800162D4u: goto label_800162D4;
    case 0x800162D8u: goto label_800162D8;
    case 0x800162DCu: goto label_800162DC;
    case 0x800162E0u: goto label_800162E0;
    case 0x800162E4u: goto label_800162E4;
    case 0x800162E8u: goto label_800162E8;
    case 0x800162ECu: goto label_800162EC;
    case 0x800162F0u: goto label_800162F0;
    case 0x800162F4u: goto label_800162F4;
    case 0x800162F8u: goto label_800162F8;
    case 0x800162FCu: goto label_800162FC;
    case 0x80016300u: goto label_80016300;
    case 0x80016304u: goto label_80016304;
    case 0x80016308u: goto label_80016308;
    case 0x8001630Cu: goto label_8001630C;
    case 0x80016310u: goto label_80016310;
    case 0x80016314u: goto label_80016314;
    case 0x80016318u: goto label_80016318;
    case 0x8001631Cu: goto label_8001631C;
    case 0x80016320u: goto label_80016320;
    case 0x80016324u: goto label_80016324;
    case 0x80016328u: goto label_80016328;
    case 0x8001632Cu: goto label_8001632C;
    case 0x80016330u: goto label_80016330;
    case 0x80016334u: goto label_80016334;
    case 0x80016338u: goto label_80016338;
    case 0x8001633Cu: goto label_8001633C;
    case 0x80016340u: goto label_80016340;
    case 0x80016344u: goto label_80016344;
    case 0x80016348u: goto label_80016348;
    case 0x8001634Cu: goto label_8001634C;
    case 0x80016350u: goto label_80016350;
    case 0x80016354u: goto label_80016354;
    case 0x80016358u: goto label_80016358;
    case 0x8001635Cu: goto label_8001635C;
    case 0x80016360u: goto label_80016360;
    case 0x80016364u: goto label_80016364;
    case 0x80016368u: goto label_80016368;
    case 0x8001636Cu: goto label_8001636C;
    case 0x80016370u: goto label_80016370;
    case 0x80016374u: goto label_80016374;
    case 0x80016378u: goto label_80016378;
    case 0x8001637Cu: goto label_8001637C;
    case 0x80016380u: goto label_80016380;
    case 0x80016384u: goto label_80016384;
    case 0x80016388u: goto label_80016388;
    case 0x8001638Cu: goto label_8001638C;
    case 0x80016390u: goto label_80016390;
    case 0x80016394u: goto label_80016394;
    case 0x80016398u: goto label_80016398;
    case 0x8001639Cu: goto label_8001639C;
    case 0x800163A0u: goto label_800163A0;
    case 0x800163A4u: goto label_800163A4;
    case 0x800163A8u: goto label_800163A8;
    case 0x800163ACu: goto label_800163AC;
    case 0x800163B0u: goto label_800163B0;
    case 0x800163B4u: goto label_800163B4;
    case 0x800163B8u: goto label_800163B8;
    case 0x800163BCu: goto label_800163BC;
    case 0x800163C0u: goto label_800163C0;
    case 0x800163C4u: goto label_800163C4;
    case 0x800163C8u: goto label_800163C8;
    case 0x800163CCu: goto label_800163CC;
    case 0x800163D0u: goto label_800163D0;
    case 0x800163D4u: goto label_800163D4;
    case 0x800163D8u: goto label_800163D8;
    case 0x800163DCu: goto label_800163DC;
    case 0x800163E0u: goto label_800163E0;
    case 0x800163E4u: goto label_800163E4;
    case 0x800163E8u: goto label_800163E8;
    case 0x800163ECu: goto label_800163EC;
    case 0x800163F0u: goto label_800163F0;
    case 0x800163F4u: goto label_800163F4;
    case 0x800163F8u: goto label_800163F8;
    case 0x800163FCu: goto label_800163FC;
    case 0x80016400u: goto label_80016400;
    case 0x80016404u: goto label_80016404;
    case 0x80016408u: goto label_80016408;
    case 0x8001640Cu: goto label_8001640C;
    case 0x80016410u: goto label_80016410;
    case 0x80016414u: goto label_80016414;
    case 0x80016418u: goto label_80016418;
    case 0x8001641Cu: goto label_8001641C;
    case 0x80016420u: goto label_80016420;
    case 0x80016424u: goto label_80016424;
    case 0x80016428u: goto label_80016428;
    case 0x8001642Cu: goto label_8001642C;
    case 0x80016430u: goto label_80016430;
    case 0x80016434u: goto label_80016434;
    case 0x80016438u: goto label_80016438;
    case 0x8001643Cu: goto label_8001643C;
    case 0x80016440u: goto label_80016440;
    case 0x80016444u: goto label_80016444;
    case 0x80016448u: goto label_80016448;
    case 0x8001644Cu: goto label_8001644C;
    case 0x80016450u: goto label_80016450;
    case 0x80016454u: goto label_80016454;
    case 0x80016458u: goto label_80016458;
    case 0x8001645Cu: goto label_8001645C;
    case 0x80016460u: goto label_80016460;
    case 0x80016464u: goto label_80016464;
    case 0x80016468u: goto label_80016468;
    case 0x8001646Cu: goto label_8001646C;
    case 0x80016470u: goto label_80016470;
    case 0x80016474u: goto label_80016474;
    case 0x80016478u: goto label_80016478;
    case 0x8001647Cu: goto label_8001647C;
    case 0x80016480u: goto label_80016480;
    case 0x80016484u: goto label_80016484;
    case 0x80016488u: goto label_80016488;
    case 0x8001648Cu: goto label_8001648C;
    case 0x80016490u: goto label_80016490;
    case 0x80016494u: goto label_80016494;
    case 0x80016498u: goto label_80016498;
    case 0x8001649Cu: goto label_8001649C;
    case 0x800164A0u: goto label_800164A0;
    case 0x800164A4u: goto label_800164A4;
    case 0x800164A8u: goto label_800164A8;
    case 0x800164ACu: goto label_800164AC;
    case 0x800164B0u: goto label_800164B0;
    case 0x800164B4u: goto label_800164B4;
    case 0x800164B8u: goto label_800164B8;
    case 0x800164BCu: goto label_800164BC;
    case 0x800164C0u: goto label_800164C0;
    case 0x800164C4u: goto label_800164C4;
    case 0x800164C8u: goto label_800164C8;
    case 0x800164CCu: goto label_800164CC;
    case 0x800164D0u: goto label_800164D0;
    case 0x800164D4u: goto label_800164D4;
    case 0x800164D8u: goto label_800164D8;
    case 0x800164DCu: goto label_800164DC;
    case 0x800164E0u: goto label_800164E0;
    case 0x800164E4u: goto label_800164E4;
    case 0x800164E8u: goto label_800164E8;
    case 0x800164ECu: goto label_800164EC;
    case 0x800164F0u: goto label_800164F0;
    case 0x800164F4u: goto label_800164F4;
    case 0x800164F8u: goto label_800164F8;
    case 0x800164FCu: goto label_800164FC;
    case 0x80016500u: goto label_80016500;
    case 0x80016504u: goto label_80016504;
    case 0x80016508u: goto label_80016508;
    case 0x8001650Cu: goto label_8001650C;
    case 0x80016510u: goto label_80016510;
    case 0x80016514u: goto label_80016514;
    case 0x80016518u: goto label_80016518;
    case 0x8001651Cu: goto label_8001651C;
    case 0x80016520u: goto label_80016520;
    case 0x80016524u: goto label_80016524;
    case 0x80016528u: goto label_80016528;
    case 0x8001652Cu: goto label_8001652C;
    case 0x80016530u: goto label_80016530;
    case 0x80016534u: goto label_80016534;
    case 0x80016538u: goto label_80016538;
    case 0x8001653Cu: goto label_8001653C;
    case 0x80016540u: goto label_80016540;
    case 0x80016544u: goto label_80016544;
    case 0x80016548u: goto label_80016548;
    case 0x8001654Cu: goto label_8001654C;
    case 0x80016550u: goto label_80016550;
    case 0x80016554u: goto label_80016554;
    case 0x80016558u: goto label_80016558;
    case 0x8001655Cu: goto label_8001655C;
    case 0x80016560u: goto label_80016560;
    case 0x80016564u: goto label_80016564;
    case 0x80016568u: goto label_80016568;
    case 0x8001656Cu: goto label_8001656C;
    case 0x80016570u: goto label_80016570;
    case 0x80016574u: goto label_80016574;
    case 0x80016578u: goto label_80016578;
    case 0x8001657Cu: goto label_8001657C;
    case 0x80016580u: goto label_80016580;
    case 0x80016584u: goto label_80016584;
    case 0x80016588u: goto label_80016588;
    case 0x8001658Cu: goto label_8001658C;
    case 0x80016590u: goto label_80016590;
    case 0x80016594u: goto label_80016594;
    case 0x80016598u: goto label_80016598;
    case 0x8001659Cu: goto label_8001659C;
    case 0x800165A0u: goto label_800165A0;
    case 0x800165A4u: goto label_800165A4;
    case 0x800165A8u: goto label_800165A8;
    case 0x800165ACu: goto label_800165AC;
    case 0x800165B0u: goto label_800165B0;
    case 0x800165B4u: goto label_800165B4;
    case 0x800165B8u: goto label_800165B8;
    case 0x800165BCu: goto label_800165BC;
    case 0x800165C0u: goto label_800165C0;
    case 0x800165C4u: goto label_800165C4;
    case 0x800165C8u: goto label_800165C8;
    case 0x800165CCu: goto label_800165CC;
    case 0x800165D0u: goto label_800165D0;
    case 0x800165D4u: goto label_800165D4;
    case 0x800165D8u: goto label_800165D8;
    case 0x800165DCu: goto label_800165DC;
    case 0x800165E0u: goto label_800165E0;
    case 0x800165E4u: goto label_800165E4;
    case 0x800165E8u: goto label_800165E8;
    case 0x800165ECu: goto label_800165EC;
    case 0x800165F0u: goto label_800165F0;
    case 0x800165F4u: goto label_800165F4;
    case 0x800165F8u: goto label_800165F8;
    case 0x800165FCu: goto label_800165FC;
    case 0x80016600u: goto label_80016600;
    case 0x80016604u: goto label_80016604;
    case 0x80016608u: goto label_80016608;
    case 0x8001660Cu: goto label_8001660C;
    case 0x80016610u: goto label_80016610;
    case 0x80016614u: goto label_80016614;
    case 0x80016618u: goto label_80016618;
    case 0x8001661Cu: goto label_8001661C;
    case 0x80016620u: goto label_80016620;
    case 0x80016624u: goto label_80016624;
    case 0x80016628u: goto label_80016628;
    case 0x8001662Cu: goto label_8001662C;
    case 0x80016630u: goto label_80016630;
    case 0x80016634u: goto label_80016634;
    case 0x80016638u: goto label_80016638;
    case 0x8001663Cu: goto label_8001663C;
    case 0x80016640u: goto label_80016640;
    case 0x80016644u: goto label_80016644;
    case 0x80016648u: goto label_80016648;
    case 0x8001664Cu: goto label_8001664C;
    case 0x80016650u: goto label_80016650;
    case 0x80016654u: goto label_80016654;
    case 0x80016658u: goto label_80016658;
    case 0x8001665Cu: goto label_8001665C;
    case 0x80016660u: goto label_80016660;
    case 0x80016664u: goto label_80016664;
    case 0x80016668u: goto label_80016668;
    case 0x8001666Cu: goto label_8001666C;
    case 0x80016670u: goto label_80016670;
    case 0x80016674u: goto label_80016674;
    case 0x80016678u: goto label_80016678;
    case 0x8001667Cu: goto label_8001667C;
    case 0x80016680u: goto label_80016680;
    case 0x80016684u: goto label_80016684;
    case 0x80016688u: goto label_80016688;
    case 0x8001668Cu: goto label_8001668C;
    case 0x80016690u: goto label_80016690;
    case 0x80016694u: goto label_80016694;
    case 0x80016698u: goto label_80016698;
    case 0x8001669Cu: goto label_8001669C;
    case 0x800166A0u: goto label_800166A0;
    case 0x800166A4u: goto label_800166A4;
    case 0x800166A8u: goto label_800166A8;
    case 0x800166ACu: goto label_800166AC;
    case 0x800166B0u: goto label_800166B0;
    case 0x800166B4u: goto label_800166B4;
    case 0x800166B8u: goto label_800166B8;
    case 0x800166BCu: goto label_800166BC;
    case 0x800166C0u: goto label_800166C0;
    case 0x800166C4u: goto label_800166C4;
    case 0x800166C8u: goto label_800166C8;
    case 0x800166CCu: goto label_800166CC;
    case 0x800166D0u: goto label_800166D0;
    case 0x800166D4u: goto label_800166D4;
    case 0x800166D8u: goto label_800166D8;
    case 0x800166DCu: goto label_800166DC;
    case 0x800166E0u: goto label_800166E0;
    case 0x800166E4u: goto label_800166E4;
    case 0x800166E8u: goto label_800166E8;
    case 0x800166ECu: goto label_800166EC;
    case 0x800166F0u: goto label_800166F0;
    case 0x800166F4u: goto label_800166F4;
    case 0x800166F8u: goto label_800166F8;
    case 0x800166FCu: goto label_800166FC;
    case 0x80016700u: goto label_80016700;
    case 0x80016704u: goto label_80016704;
    case 0x80016708u: goto label_80016708;
    case 0x8001670Cu: goto label_8001670C;
    case 0x80016710u: goto label_80016710;
    case 0x80016714u: goto label_80016714;
    case 0x80016718u: goto label_80016718;
    case 0x8001671Cu: goto label_8001671C;
    case 0x80016720u: goto label_80016720;
    case 0x80016724u: goto label_80016724;
    case 0x80016728u: goto label_80016728;
    case 0x8001672Cu: goto label_8001672C;
    case 0x80016730u: goto label_80016730;
    case 0x80016734u: goto label_80016734;
    case 0x80016738u: goto label_80016738;
    case 0x8001673Cu: goto label_8001673C;
    case 0x80016740u: goto label_80016740;
    case 0x80016744u: goto label_80016744;
    case 0x80016748u: goto label_80016748;
    case 0x8001674Cu: goto label_8001674C;
    case 0x80016750u: goto label_80016750;
    case 0x80016754u: goto label_80016754;
    case 0x80016758u: goto label_80016758;
    case 0x8001675Cu: goto label_8001675C;
    case 0x80016760u: goto label_80016760;
    case 0x80016764u: goto label_80016764;
    case 0x80016768u: goto label_80016768;
    case 0x8001676Cu: goto label_8001676C;
    case 0x80016770u: goto label_80016770;
    case 0x80016774u: goto label_80016774;
    case 0x80016778u: goto label_80016778;
    case 0x8001677Cu: goto label_8001677C;
    case 0x80016780u: goto label_80016780;
    case 0x80016784u: goto label_80016784;
    case 0x80016788u: goto label_80016788;
    case 0x8001678Cu: goto label_8001678C;
    case 0x80016790u: goto label_80016790;
    case 0x80016794u: goto label_80016794;
    case 0x80016798u: goto label_80016798;
    case 0x8001679Cu: goto label_8001679C;
    case 0x800167A0u: goto label_800167A0;
    case 0x800167A4u: goto label_800167A4;
    case 0x800167A8u: goto label_800167A8;
    case 0x800167ACu: goto label_800167AC;
    case 0x800167B0u: goto label_800167B0;
    case 0x800167B4u: goto label_800167B4;
    case 0x800167B8u: goto label_800167B8;
    case 0x800167BCu: goto label_800167BC;
    case 0x800167C0u: goto label_800167C0;
    case 0x800167C4u: goto label_800167C4;
    case 0x800167C8u: goto label_800167C8;
    case 0x800167CCu: goto label_800167CC;
    case 0x800167D0u: goto label_800167D0;
    case 0x800167D4u: goto label_800167D4;
    case 0x800167D8u: goto label_800167D8;
    case 0x800167DCu: goto label_800167DC;
    case 0x800167E0u: goto label_800167E0;
    case 0x800167E4u: goto label_800167E4;
    case 0x800167E8u: goto label_800167E8;
    case 0x800167ECu: goto label_800167EC;
    case 0x800167F0u: goto label_800167F0;
    case 0x800167F4u: goto label_800167F4;
    case 0x800167F8u: goto label_800167F8;
    case 0x800167FCu: goto label_800167FC;
    case 0x80016800u: goto label_80016800;
    case 0x80016804u: goto label_80016804;
    case 0x80016808u: goto label_80016808;
    case 0x8001680Cu: goto label_8001680C;
    case 0x80016810u: goto label_80016810;
    case 0x80016814u: goto label_80016814;
    case 0x80016818u: goto label_80016818;
    case 0x8001681Cu: goto label_8001681C;
    case 0x80016820u: goto label_80016820;
    case 0x80016824u: goto label_80016824;
    case 0x80016828u: goto label_80016828;
    case 0x8001682Cu: goto label_8001682C;
    case 0x80016830u: goto label_80016830;
    case 0x80016834u: goto label_80016834;
    case 0x80016838u: goto label_80016838;
    case 0x8001683Cu: goto label_8001683C;
    case 0x80016840u: goto label_80016840;
    case 0x80016844u: goto label_80016844;
    case 0x80016848u: goto label_80016848;
    case 0x8001684Cu: goto label_8001684C;
    case 0x80016850u: goto label_80016850;
    case 0x80016854u: goto label_80016854;
    case 0x80016858u: goto label_80016858;
    case 0x8001685Cu: goto label_8001685C;
    case 0x80016860u: goto label_80016860;
    case 0x80016864u: goto label_80016864;
    case 0x80016868u: goto label_80016868;
    case 0x8001686Cu: goto label_8001686C;
    case 0x80016870u: goto label_80016870;
    case 0x80016874u: goto label_80016874;
    case 0x80016878u: goto label_80016878;
    case 0x8001687Cu: goto label_8001687C;
    case 0x80016880u: goto label_80016880;
    case 0x80016884u: goto label_80016884;
    case 0x80016888u: goto label_80016888;
    case 0x8001688Cu: goto label_8001688C;
    case 0x80016890u: goto label_80016890;
    case 0x80016894u: goto label_80016894;
    case 0x80016898u: goto label_80016898;
    case 0x8001689Cu: goto label_8001689C;
    case 0x800168A0u: goto label_800168A0;
    case 0x800168A4u: goto label_800168A4;
    case 0x800168A8u: goto label_800168A8;
    case 0x800168ACu: goto label_800168AC;
    case 0x800168B0u: goto label_800168B0;
    case 0x800168B4u: goto label_800168B4;
    case 0x800168B8u: goto label_800168B8;
    case 0x800168BCu: goto label_800168BC;
    case 0x800168C0u: goto label_800168C0;
    case 0x800168C4u: goto label_800168C4;
    case 0x800168C8u: goto label_800168C8;
    case 0x800168CCu: goto label_800168CC;
    case 0x800168D0u: goto label_800168D0;
    case 0x800168D4u: goto label_800168D4;
    case 0x800168D8u: goto label_800168D8;
    case 0x800168DCu: goto label_800168DC;
    case 0x800168E0u: goto label_800168E0;
    case 0x800168E4u: goto label_800168E4;
    case 0x800168E8u: goto label_800168E8;
    case 0x800168ECu: goto label_800168EC;
    case 0x800168F0u: goto label_800168F0;
    case 0x800168F4u: goto label_800168F4;
    case 0x800168F8u: goto label_800168F8;
    case 0x800168FCu: goto label_800168FC;
    case 0x80016900u: goto label_80016900;
    case 0x80016904u: goto label_80016904;
    case 0x80016908u: goto label_80016908;
    case 0x8001690Cu: goto label_8001690C;
    case 0x80016910u: goto label_80016910;
    case 0x80016914u: goto label_80016914;
    case 0x80016918u: goto label_80016918;
    case 0x8001691Cu: goto label_8001691C;
    case 0x80016920u: goto label_80016920;
    case 0x80016924u: goto label_80016924;
    case 0x80016928u: goto label_80016928;
    case 0x8001692Cu: goto label_8001692C;
    case 0x80016930u: goto label_80016930;
    case 0x80016934u: goto label_80016934;
    case 0x80016938u: goto label_80016938;
    case 0x8001693Cu: goto label_8001693C;
    case 0x80016940u: goto label_80016940;
    case 0x80016944u: goto label_80016944;
    case 0x80016948u: goto label_80016948;
    case 0x8001694Cu: goto label_8001694C;
    case 0x80016950u: goto label_80016950;
    case 0x80016954u: goto label_80016954;
    case 0x80016958u: goto label_80016958;
    case 0x8001695Cu: goto label_8001695C;
    case 0x80016960u: goto label_80016960;
    case 0x80016964u: goto label_80016964;
    case 0x80016968u: goto label_80016968;
    case 0x8001696Cu: goto label_8001696C;
    case 0x80016970u: goto label_80016970;
    case 0x80016974u: goto label_80016974;
    case 0x80016978u: goto label_80016978;
    case 0x8001697Cu: goto label_8001697C;
    case 0x80016980u: goto label_80016980;
    case 0x80016984u: goto label_80016984;
    case 0x80016988u: goto label_80016988;
    case 0x8001698Cu: goto label_8001698C;
    case 0x80016990u: goto label_80016990;
    case 0x80016994u: goto label_80016994;
    case 0x80016998u: goto label_80016998;
    case 0x8001699Cu: goto label_8001699C;
    case 0x800169A0u: goto label_800169A0;
    case 0x800169A4u: goto label_800169A4;
    case 0x800169A8u: goto label_800169A8;
    case 0x800169ACu: goto label_800169AC;
    case 0x800169B0u: goto label_800169B0;
    case 0x800169B4u: goto label_800169B4;
    case 0x800169B8u: goto label_800169B8;
    case 0x800169BCu: goto label_800169BC;
    case 0x800169C0u: goto label_800169C0;
    case 0x800169C4u: goto label_800169C4;
    case 0x800169C8u: goto label_800169C8;
    case 0x800169CCu: goto label_800169CC;
    case 0x800169D0u: goto label_800169D0;
    case 0x800169D4u: goto label_800169D4;
    case 0x800169D8u: goto label_800169D8;
    case 0x800169DCu: goto label_800169DC;
    case 0x800169E0u: goto label_800169E0;
    case 0x800169E4u: goto label_800169E4;
    case 0x800169E8u: goto label_800169E8;
    case 0x800169ECu: goto label_800169EC;
    case 0x800169F0u: goto label_800169F0;
    case 0x800169F4u: goto label_800169F4;
    case 0x800169F8u: goto label_800169F8;
    case 0x800169FCu: goto label_800169FC;
    case 0x80016A00u: goto label_80016A00;
    case 0x80016A04u: goto label_80016A04;
    case 0x80016A08u: goto label_80016A08;
    case 0x80016A0Cu: goto label_80016A0C;
    case 0x80016A10u: goto label_80016A10;
    case 0x80016A14u: goto label_80016A14;
    case 0x80016A18u: goto label_80016A18;
    case 0x80016A1Cu: goto label_80016A1C;
    case 0x80016A20u: goto label_80016A20;
    case 0x80016A24u: goto label_80016A24;
    case 0x80016A28u: goto label_80016A28;
    case 0x80016A2Cu: goto label_80016A2C;
    case 0x80016A30u: goto label_80016A30;
    case 0x80016A34u: goto label_80016A34;
    case 0x80016A38u: goto label_80016A38;
    case 0x80016A3Cu: goto label_80016A3C;
    case 0x80016A40u: goto label_80016A40;
    case 0x80016A44u: goto label_80016A44;
    case 0x80016A48u: goto label_80016A48;
    case 0x80016A4Cu: goto label_80016A4C;
    case 0x80016A50u: goto label_80016A50;
    case 0x80016A54u: goto label_80016A54;
    case 0x80016A58u: goto label_80016A58;
    case 0x80016A5Cu: goto label_80016A5C;
    case 0x80016A60u: goto label_80016A60;
    case 0x80016A64u: goto label_80016A64;
    case 0x80016A68u: goto label_80016A68;
    case 0x80016A6Cu: goto label_80016A6C;
    case 0x80016A70u: goto label_80016A70;
    case 0x80016A74u: goto label_80016A74;
    case 0x80016A78u: goto label_80016A78;
    case 0x80016A7Cu: goto label_80016A7C;
    case 0x80016A80u: goto label_80016A80;
    case 0x80016A84u: goto label_80016A84;
    case 0x80016A88u: goto label_80016A88;
    case 0x80016A8Cu: goto label_80016A8C;
    case 0x80016A90u: goto label_80016A90;
    case 0x80016A94u: goto label_80016A94;
    case 0x80016A98u: goto label_80016A98;
    case 0x80016A9Cu: goto label_80016A9C;
    case 0x80016AA0u: goto label_80016AA0;
    case 0x80016AA4u: goto label_80016AA4;
    case 0x80016AA8u: goto label_80016AA8;
    case 0x80016AACu: goto label_80016AAC;
    case 0x80016AB0u: goto label_80016AB0;
    case 0x80016AB4u: goto label_80016AB4;
    case 0x80016AB8u: goto label_80016AB8;
    case 0x80016ABCu: goto label_80016ABC;
    case 0x80016AC0u: goto label_80016AC0;
    case 0x80016AC4u: goto label_80016AC4;
    case 0x80016AC8u: goto label_80016AC8;
    case 0x80016ACCu: goto label_80016ACC;
    case 0x80016AD0u: goto label_80016AD0;
    case 0x80016AD4u: goto label_80016AD4;
    case 0x80016AD8u: goto label_80016AD8;
    case 0x80016ADCu: goto label_80016ADC;
    case 0x80016AE0u: goto label_80016AE0;
    case 0x80016AE4u: goto label_80016AE4;
    case 0x80016AE8u: goto label_80016AE8;
    case 0x80016AECu: goto label_80016AEC;
    case 0x80016AF0u: goto label_80016AF0;
    case 0x80016AF4u: goto label_80016AF4;
    case 0x80016AF8u: goto label_80016AF8;
    case 0x80016AFCu: goto label_80016AFC;
    case 0x80016B00u: goto label_80016B00;
    case 0x80016B04u: goto label_80016B04;
    case 0x80016B08u: goto label_80016B08;
    case 0x80016B0Cu: goto label_80016B0C;
    case 0x80016B10u: goto label_80016B10;
    case 0x80016B14u: goto label_80016B14;
    case 0x80016B18u: goto label_80016B18;
    case 0x80016B1Cu: goto label_80016B1C;
    case 0x80016B20u: goto label_80016B20;
    case 0x80016B24u: goto label_80016B24;
    case 0x80016B28u: goto label_80016B28;
    case 0x80016B2Cu: goto label_80016B2C;
    case 0x80016B30u: goto label_80016B30;
    case 0x80016B34u: goto label_80016B34;
    case 0x80016B38u: goto label_80016B38;
    case 0x80016B3Cu: goto label_80016B3C;
    case 0x80016B40u: goto label_80016B40;
    case 0x80016B44u: goto label_80016B44;
    case 0x80016B48u: goto label_80016B48;
    case 0x80016B4Cu: goto label_80016B4C;
    case 0x80016B50u: goto label_80016B50;
    case 0x80016B54u: goto label_80016B54;
    case 0x80016B58u: goto label_80016B58;
    case 0x80016B5Cu: goto label_80016B5C;
    case 0x80016B60u: goto label_80016B60;
    case 0x80016B64u: goto label_80016B64;
    case 0x80016B68u: goto label_80016B68;
    case 0x80016B6Cu: goto label_80016B6C;
    case 0x80016B70u: goto label_80016B70;
    case 0x80016B74u: goto label_80016B74;
    case 0x80016B78u: goto label_80016B78;
    case 0x80016B7Cu: goto label_80016B7C;
    case 0x80016B80u: goto label_80016B80;
    case 0x80016B84u: goto label_80016B84;
    case 0x80016B88u: goto label_80016B88;
    case 0x80016B8Cu: goto label_80016B8C;
    case 0x80016B90u: goto label_80016B90;
    case 0x80016B94u: goto label_80016B94;
    case 0x80016B98u: goto label_80016B98;
    case 0x80016B9Cu: goto label_80016B9C;
    case 0x80016BA0u: goto label_80016BA0;
    case 0x80016BA4u: goto label_80016BA4;
    case 0x80016BA8u: goto label_80016BA8;
    case 0x80016BACu: goto label_80016BAC;
    case 0x80016BB0u: goto label_80016BB0;
    case 0x80016BB4u: goto label_80016BB4;
    case 0x80016BB8u: goto label_80016BB8;
    case 0x80016BBCu: goto label_80016BBC;
    case 0x80016BC0u: goto label_80016BC0;
    case 0x80016BC4u: goto label_80016BC4;
    case 0x80016BC8u: goto label_80016BC8;
    case 0x80016BCCu: goto label_80016BCC;
    case 0x80016BD0u: goto label_80016BD0;
    case 0x80016BD4u: goto label_80016BD4;
    case 0x80016BD8u: goto label_80016BD8;
    case 0x80016BDCu: goto label_80016BDC;
    case 0x80016BE0u: goto label_80016BE0;
    case 0x80016BE4u: goto label_80016BE4;
    case 0x80016BE8u: goto label_80016BE8;
    case 0x80016BECu: goto label_80016BEC;
    case 0x80016BF0u: goto label_80016BF0;
    case 0x80016BF4u: goto label_80016BF4;
    case 0x80016BF8u: goto label_80016BF8;
    case 0x80016BFCu: goto label_80016BFC;
    case 0x80016C00u: goto label_80016C00;
    case 0x80016C04u: goto label_80016C04;
    case 0x80016C08u: goto label_80016C08;
    case 0x80016C0Cu: goto label_80016C0C;
    case 0x80016C10u: goto label_80016C10;
    case 0x80016C14u: goto label_80016C14;
    case 0x80016C18u: goto label_80016C18;
    case 0x80016C1Cu: goto label_80016C1C;
    case 0x80016C20u: goto label_80016C20;
    case 0x80016C24u: goto label_80016C24;
    case 0x80016C28u: goto label_80016C28;
    case 0x80016C2Cu: goto label_80016C2C;
    case 0x80016C30u: goto label_80016C30;
    case 0x80016C34u: goto label_80016C34;
    case 0x80016C38u: goto label_80016C38;
    case 0x80016C3Cu: goto label_80016C3C;
    case 0x80016C40u: goto label_80016C40;
    case 0x80016C44u: goto label_80016C44;
    case 0x80016C48u: goto label_80016C48;
    case 0x80016C4Cu: goto label_80016C4C;
    case 0x80016C50u: goto label_80016C50;
    case 0x80016C54u: goto label_80016C54;
    case 0x80016C58u: goto label_80016C58;
    case 0x80016C5Cu: goto label_80016C5C;
    case 0x80016C60u: goto label_80016C60;
    case 0x80016C64u: goto label_80016C64;
    case 0x80016C68u: goto label_80016C68;
    case 0x80016C6Cu: goto label_80016C6C;
    case 0x80016C70u: goto label_80016C70;
    case 0x80016C74u: goto label_80016C74;
    case 0x80016C78u: goto label_80016C78;
    case 0x80016C7Cu: goto label_80016C7C;
    case 0x80016C80u: goto label_80016C80;
    case 0x80016C84u: goto label_80016C84;
    case 0x80016C88u: goto label_80016C88;
    case 0x80016C8Cu: goto label_80016C8C;
    case 0x80016C90u: goto label_80016C90;
    case 0x80016C94u: goto label_80016C94;
    case 0x80016C98u: goto label_80016C98;
    case 0x80016C9Cu: goto label_80016C9C;
    case 0x80016CA0u: goto label_80016CA0;
    case 0x80016CA4u: goto label_80016CA4;
    case 0x80016CA8u: goto label_80016CA8;
    case 0x80016CACu: goto label_80016CAC;
    case 0x80016CB0u: goto label_80016CB0;
    case 0x80016CB4u: goto label_80016CB4;
    case 0x80016CB8u: goto label_80016CB8;
    case 0x80016CBCu: goto label_80016CBC;
    case 0x80016CC0u: goto label_80016CC0;
    case 0x80016CC4u: goto label_80016CC4;
    case 0x80016CC8u: goto label_80016CC8;
    case 0x80016CCCu: goto label_80016CCC;
    case 0x80016CD0u: goto label_80016CD0;
    case 0x80016CD4u: goto label_80016CD4;
    case 0x80016CD8u: goto label_80016CD8;
    case 0x80016CDCu: goto label_80016CDC;
    case 0x80016CE0u: goto label_80016CE0;
    case 0x80016CE4u: goto label_80016CE4;
    case 0x80016CE8u: goto label_80016CE8;
    case 0x80016CECu: goto label_80016CEC;
    case 0x80016CF0u: goto label_80016CF0;
    case 0x80016CF4u: goto label_80016CF4;
    case 0x80016CF8u: goto label_80016CF8;
    case 0x80016CFCu: goto label_80016CFC;
    case 0x80016D00u: goto label_80016D00;
    case 0x80016D04u: goto label_80016D04;
    case 0x80016D08u: goto label_80016D08;
    case 0x80016D0Cu: goto label_80016D0C;
    case 0x80016D10u: goto label_80016D10;
    case 0x80016D14u: goto label_80016D14;
    case 0x80016D18u: goto label_80016D18;
    case 0x80016D1Cu: goto label_80016D1C;
    case 0x80016D20u: goto label_80016D20;
    case 0x80016D24u: goto label_80016D24;
    case 0x80016D28u: goto label_80016D28;
    case 0x80016D2Cu: goto label_80016D2C;
    case 0x80016D30u: goto label_80016D30;
    case 0x80016D34u: goto label_80016D34;
    case 0x80016D38u: goto label_80016D38;
    case 0x80016D3Cu: goto label_80016D3C;
    case 0x80016D40u: goto label_80016D40;
    case 0x80016D44u: goto label_80016D44;
    case 0x80016D48u: goto label_80016D48;
    case 0x80016D4Cu: goto label_80016D4C;
    case 0x80016D50u: goto label_80016D50;
    case 0x80016D54u: goto label_80016D54;
    case 0x80016D58u: goto label_80016D58;
    case 0x80016D5Cu: goto label_80016D5C;
    case 0x80016D60u: goto label_80016D60;
    case 0x80016D64u: goto label_80016D64;
    case 0x80016D68u: goto label_80016D68;
    case 0x80016D6Cu: goto label_80016D6C;
    case 0x80016D70u: goto label_80016D70;
    case 0x80016D74u: goto label_80016D74;
    case 0x80016D78u: goto label_80016D78;
    case 0x80016D7Cu: goto label_80016D7C;
    case 0x80016D80u: goto label_80016D80;
    case 0x80016D84u: goto label_80016D84;
    case 0x80016D88u: goto label_80016D88;
    case 0x80016D8Cu: goto label_80016D8C;
    case 0x80016D90u: goto label_80016D90;
    case 0x80016D94u: goto label_80016D94;
    case 0x80016D98u: goto label_80016D98;
    case 0x80016D9Cu: goto label_80016D9C;
    case 0x80016DA0u: goto label_80016DA0;
    case 0x80016DA4u: goto label_80016DA4;
    case 0x80016DA8u: goto label_80016DA8;
    case 0x80016DACu: goto label_80016DAC;
    case 0x80016DB0u: goto label_80016DB0;
    case 0x80016DB4u: goto label_80016DB4;
    case 0x80016DB8u: goto label_80016DB8;
    case 0x80016DBCu: goto label_80016DBC;
    case 0x80016DC0u: goto label_80016DC0;
    case 0x80016DC4u: goto label_80016DC4;
    case 0x80016DC8u: goto label_80016DC8;
    case 0x80016DCCu: goto label_80016DCC;
    case 0x80016DD0u: goto label_80016DD0;
    case 0x80016DD4u: goto label_80016DD4;
    case 0x80016DD8u: goto label_80016DD8;
    case 0x80016DDCu: goto label_80016DDC;
    case 0x80016DE0u: goto label_80016DE0;
    case 0x80016DE4u: goto label_80016DE4;
    case 0x80016DE8u: goto label_80016DE8;
    case 0x80016DECu: goto label_80016DEC;
    case 0x80016DF0u: goto label_80016DF0;
    case 0x80016DF4u: goto label_80016DF4;
    case 0x80016DF8u: goto label_80016DF8;
    case 0x80016DFCu: goto label_80016DFC;
    case 0x80016E00u: goto label_80016E00;
    case 0x80016E04u: goto label_80016E04;
    case 0x80016E08u: goto label_80016E08;
    case 0x80016E0Cu: goto label_80016E0C;
    case 0x80016E10u: goto label_80016E10;
    case 0x80016E14u: goto label_80016E14;
    case 0x80016E18u: goto label_80016E18;
    case 0x80016E1Cu: goto label_80016E1C;
    case 0x80016E20u: goto label_80016E20;
    case 0x80016E24u: goto label_80016E24;
    case 0x80016E28u: goto label_80016E28;
    case 0x80016E2Cu: goto label_80016E2C;
    case 0x80016E30u: goto label_80016E30;
    case 0x80016E34u: goto label_80016E34;
    case 0x80016E38u: goto label_80016E38;
    case 0x80016E3Cu: goto label_80016E3C;
    case 0x80016E40u: goto label_80016E40;
    case 0x80016E44u: goto label_80016E44;
    case 0x80016E48u: goto label_80016E48;
    case 0x80016E4Cu: goto label_80016E4C;
    case 0x80016E50u: goto label_80016E50;
    case 0x80016E54u: goto label_80016E54;
    case 0x80016E58u: goto label_80016E58;
    case 0x80016E5Cu: goto label_80016E5C;
    case 0x80016E60u: goto label_80016E60;
    case 0x80016E64u: goto label_80016E64;
    case 0x80016E68u: goto label_80016E68;
    case 0x80016E6Cu: goto label_80016E6C;
    case 0x80016E70u: goto label_80016E70;
    case 0x80016E74u: goto label_80016E74;
    case 0x80016E78u: goto label_80016E78;
    case 0x80016E7Cu: goto label_80016E7C;
    case 0x80016E80u: goto label_80016E80;
    case 0x80016E84u: goto label_80016E84;
    case 0x80016E88u: goto label_80016E88;
    case 0x80016E8Cu: goto label_80016E8C;
    case 0x80016E90u: goto label_80016E90;
    case 0x80016E94u: goto label_80016E94;
    case 0x80016E98u: goto label_80016E98;
    case 0x80016E9Cu: goto label_80016E9C;
    case 0x80016EA0u: goto label_80016EA0;
    case 0x80016EA4u: goto label_80016EA4;
    case 0x80016EA8u: goto label_80016EA8;
    case 0x80016EACu: goto label_80016EAC;
    case 0x80016EB0u: goto label_80016EB0;
    case 0x80016EB4u: goto label_80016EB4;
    case 0x80016EB8u: goto label_80016EB8;
    case 0x80016EBCu: goto label_80016EBC;
    case 0x80016EC0u: goto label_80016EC0;
    case 0x80016EC4u: goto label_80016EC4;
    case 0x80016EC8u: goto label_80016EC8;
    case 0x80016ECCu: goto label_80016ECC;
    case 0x80016ED0u: goto label_80016ED0;
    case 0x80016ED4u: goto label_80016ED4;
    case 0x80016ED8u: goto label_80016ED8;
    case 0x80016EDCu: goto label_80016EDC;
    case 0x80016EE0u: goto label_80016EE0;
    case 0x80016EE4u: goto label_80016EE4;
    case 0x80016EE8u: goto label_80016EE8;
    case 0x80016EECu: goto label_80016EEC;
    case 0x80016EF0u: goto label_80016EF0;
    case 0x80016EF4u: goto label_80016EF4;
    case 0x80016EF8u: goto label_80016EF8;
    case 0x80016EFCu: goto label_80016EFC;
    case 0x80016F00u: goto label_80016F00;
    case 0x80016F04u: goto label_80016F04;
    case 0x80016F08u: goto label_80016F08;
    case 0x80016F0Cu: goto label_80016F0C;
    case 0x80016F10u: goto label_80016F10;
    case 0x80016F14u: goto label_80016F14;
    case 0x80016F18u: goto label_80016F18;
    case 0x80016F1Cu: goto label_80016F1C;
    case 0x80016F20u: goto label_80016F20;
    case 0x80016F24u: goto label_80016F24;
    case 0x80016F28u: goto label_80016F28;
    case 0x80016F2Cu: goto label_80016F2C;
    case 0x80016F30u: goto label_80016F30;
    case 0x80016F34u: goto label_80016F34;
    case 0x80016F38u: goto label_80016F38;
    case 0x80016F3Cu: goto label_80016F3C;
    case 0x80016F40u: goto label_80016F40;
    case 0x80016F44u: goto label_80016F44;
    case 0x80016F48u: goto label_80016F48;
    case 0x80016F4Cu: goto label_80016F4C;
    case 0x80016F50u: goto label_80016F50;
    case 0x80016F54u: goto label_80016F54;
    case 0x80016F58u: goto label_80016F58;
    case 0x80016F5Cu: goto label_80016F5C;
    case 0x80016F60u: goto label_80016F60;
    case 0x80016F64u: goto label_80016F64;
    case 0x80016F68u: goto label_80016F68;
    case 0x80016F6Cu: goto label_80016F6C;
    case 0x80016F70u: goto label_80016F70;
    case 0x80016F74u: goto label_80016F74;
    case 0x80016F78u: goto label_80016F78;
    case 0x80016F7Cu: goto label_80016F7C;
    case 0x80016F80u: goto label_80016F80;
    case 0x80016F84u: goto label_80016F84;
    case 0x80016F88u: goto label_80016F88;
    case 0x80016F8Cu: goto label_80016F8C;
    case 0x80016F90u: goto label_80016F90;
    case 0x80016F94u: goto label_80016F94;
    case 0x80016F98u: goto label_80016F98;
    case 0x80016F9Cu: goto label_80016F9C;
    case 0x80016FA0u: goto label_80016FA0;
    case 0x80016FA4u: goto label_80016FA4;
    case 0x80016FA8u: goto label_80016FA8;
    case 0x80016FACu: goto label_80016FAC;
    case 0x80016FB0u: goto label_80016FB0;
    case 0x80016FB4u: goto label_80016FB4;
    case 0x80016FB8u: goto label_80016FB8;
    case 0x80016FBCu: goto label_80016FBC;
    case 0x80016FC0u: goto label_80016FC0;
    case 0x80016FC4u: goto label_80016FC4;
    case 0x80016FC8u: goto label_80016FC8;
    case 0x80016FCCu: goto label_80016FCC;
    case 0x80016FD0u: goto label_80016FD0;
    case 0x80016FD4u: goto label_80016FD4;
    case 0x80016FD8u: goto label_80016FD8;
    case 0x80016FDCu: goto label_80016FDC;
    case 0x80016FE0u: goto label_80016FE0;
    case 0x80016FE4u: goto label_80016FE4;
    case 0x80016FE8u: goto label_80016FE8;
    case 0x80016FECu: goto label_80016FEC;
    case 0x80016FF0u: goto label_80016FF0;
    case 0x80016FF4u: goto label_80016FF4;
    case 0x80016FF8u: goto label_80016FF8;
    case 0x80016FFCu: goto label_80016FFC;
    case 0x80017000u: goto label_80017000;
    case 0x80017004u: goto label_80017004;
    case 0x80017008u: goto label_80017008;
    case 0x8001700Cu: goto label_8001700C;
    case 0x80017010u: goto label_80017010;
    case 0x80017014u: goto label_80017014;
    case 0x80017018u: goto label_80017018;
    case 0x8001701Cu: goto label_8001701C;
    case 0x80017020u: goto label_80017020;
    case 0x80017024u: goto label_80017024;
    case 0x80017028u: goto label_80017028;
    case 0x8001702Cu: goto label_8001702C;
    case 0x80017030u: goto label_80017030;
    case 0x80017034u: goto label_80017034;
    case 0x80017038u: goto label_80017038;
    case 0x8001703Cu: goto label_8001703C;
    case 0x80017040u: goto label_80017040;
    case 0x80017044u: goto label_80017044;
    case 0x80017048u: goto label_80017048;
    case 0x8001704Cu: goto label_8001704C;
    case 0x80017050u: goto label_80017050;
    case 0x80017054u: goto label_80017054;
    case 0x80017058u: goto label_80017058;
    case 0x8001705Cu: goto label_8001705C;
    case 0x80017060u: goto label_80017060;
    case 0x80017064u: goto label_80017064;
    case 0x80017068u: goto label_80017068;
    case 0x8001706Cu: goto label_8001706C;
    case 0x80017070u: goto label_80017070;
    case 0x80017074u: goto label_80017074;
    case 0x80017078u: goto label_80017078;
    case 0x8001707Cu: goto label_8001707C;
    case 0x80017080u: goto label_80017080;
    case 0x80017084u: goto label_80017084;
    case 0x80017088u: goto label_80017088;
    case 0x8001708Cu: goto label_8001708C;
    case 0x80017090u: goto label_80017090;
    case 0x80017094u: goto label_80017094;
    case 0x80017098u: goto label_80017098;
    case 0x8001709Cu: goto label_8001709C;
    case 0x800170A0u: goto label_800170A0;
    case 0x800170A4u: goto label_800170A4;
    case 0x800170A8u: goto label_800170A8;
    case 0x800170ACu: goto label_800170AC;
    case 0x800170B0u: goto label_800170B0;
    case 0x800170B4u: goto label_800170B4;
    case 0x800170B8u: goto label_800170B8;
    case 0x800170BCu: goto label_800170BC;
    case 0x800170C0u: goto label_800170C0;
    case 0x800170C4u: goto label_800170C4;
    case 0x800170C8u: goto label_800170C8;
    case 0x800170CCu: goto label_800170CC;
    case 0x800170D0u: goto label_800170D0;
    case 0x800170D4u: goto label_800170D4;
    case 0x800170D8u: goto label_800170D8;
    case 0x800170DCu: goto label_800170DC;
    case 0x800170E0u: goto label_800170E0;
    case 0x800170E4u: goto label_800170E4;
    case 0x800170E8u: goto label_800170E8;
    case 0x800170ECu: goto label_800170EC;
    case 0x800170F0u: goto label_800170F0;
    case 0x800170F4u: goto label_800170F4;
    case 0x800170F8u: goto label_800170F8;
    case 0x800170FCu: goto label_800170FC;
    case 0x80017100u: goto label_80017100;
    case 0x80017104u: goto label_80017104;
    case 0x80017108u: goto label_80017108;
    case 0x8001710Cu: goto label_8001710C;
    case 0x80017110u: goto label_80017110;
    case 0x80017114u: goto label_80017114;
    case 0x80017118u: goto label_80017118;
    case 0x8001711Cu: goto label_8001711C;
    case 0x80017120u: goto label_80017120;
    case 0x80017124u: goto label_80017124;
    case 0x80017128u: goto label_80017128;
    case 0x8001712Cu: goto label_8001712C;
    case 0x80017130u: goto label_80017130;
    case 0x80017134u: goto label_80017134;
    case 0x80017138u: goto label_80017138;
    case 0x8001713Cu: goto label_8001713C;
    case 0x80017140u: goto label_80017140;
    case 0x80017144u: goto label_80017144;
    case 0x80017148u: goto label_80017148;
    case 0x8001714Cu: goto label_8001714C;
    case 0x80017150u: goto label_80017150;
    case 0x80017154u: goto label_80017154;
    case 0x80017158u: goto label_80017158;
    case 0x8001715Cu: goto label_8001715C;
    case 0x80017160u: goto label_80017160;
    case 0x80017164u: goto label_80017164;
    case 0x80017168u: goto label_80017168;
    case 0x8001716Cu: goto label_8001716C;
    case 0x80017170u: goto label_80017170;
    case 0x80017174u: goto label_80017174;
    case 0x80017178u: goto label_80017178;
    case 0x8001717Cu: goto label_8001717C;
    case 0x80017180u: goto label_80017180;
    case 0x80017184u: goto label_80017184;
    case 0x80017188u: goto label_80017188;
    case 0x8001718Cu: goto label_8001718C;
    case 0x80017190u: goto label_80017190;
    case 0x80017194u: goto label_80017194;
    case 0x80017198u: goto label_80017198;
    case 0x8001719Cu: goto label_8001719C;
    case 0x800171A0u: goto label_800171A0;
    case 0x800171A4u: goto label_800171A4;
    case 0x800171A8u: goto label_800171A8;
    case 0x800171ACu: goto label_800171AC;
    case 0x800171B0u: goto label_800171B0;
    case 0x800171B4u: goto label_800171B4;
    case 0x800171B8u: goto label_800171B8;
    case 0x800171BCu: goto label_800171BC;
    case 0x800171C0u: goto label_800171C0;
    case 0x800171C4u: goto label_800171C4;
    case 0x800171C8u: goto label_800171C8;
    case 0x800171CCu: goto label_800171CC;
    case 0x800171D0u: goto label_800171D0;
    case 0x800171D4u: goto label_800171D4;
    case 0x800171D8u: goto label_800171D8;
    case 0x800171DCu: goto label_800171DC;
    case 0x800171E0u: goto label_800171E0;
    case 0x800171E4u: goto label_800171E4;
    case 0x800171E8u: goto label_800171E8;
    case 0x800171ECu: goto label_800171EC;
    case 0x800171F0u: goto label_800171F0;
    case 0x800171F4u: goto label_800171F4;
    case 0x800171F8u: goto label_800171F8;
    case 0x800171FCu: goto label_800171FC;
    case 0x80017200u: goto label_80017200;
    case 0x80017204u: goto label_80017204;
    case 0x80017208u: goto label_80017208;
    case 0x8001720Cu: goto label_8001720C;
    case 0x80017210u: goto label_80017210;
    case 0x80017214u: goto label_80017214;
    case 0x80017218u: goto label_80017218;
    case 0x8001721Cu: goto label_8001721C;
    case 0x80017220u: goto label_80017220;
    case 0x80017224u: goto label_80017224;
    case 0x80017228u: goto label_80017228;
    case 0x8001722Cu: goto label_8001722C;
    case 0x80017230u: goto label_80017230;
    case 0x80017234u: goto label_80017234;
    case 0x80017238u: goto label_80017238;
    case 0x8001723Cu: goto label_8001723C;
    case 0x80017240u: goto label_80017240;
    case 0x80017244u: goto label_80017244;
    case 0x80017248u: goto label_80017248;
    case 0x8001724Cu: goto label_8001724C;
    case 0x80017250u: goto label_80017250;
    case 0x80017254u: goto label_80017254;
    case 0x80017258u: goto label_80017258;
    case 0x8001725Cu: goto label_8001725C;
    case 0x80017260u: goto label_80017260;
    case 0x80017264u: goto label_80017264;
    case 0x80017268u: goto label_80017268;
    case 0x8001726Cu: goto label_8001726C;
    case 0x80017270u: goto label_80017270;
    case 0x80017274u: goto label_80017274;
    case 0x80017278u: goto label_80017278;
    case 0x8001727Cu: goto label_8001727C;
    case 0x80017280u: goto label_80017280;
    case 0x80017284u: goto label_80017284;
    case 0x80017288u: goto label_80017288;
    case 0x8001728Cu: goto label_8001728C;
    case 0x80017290u: goto label_80017290;
    case 0x80017294u: goto label_80017294;
    case 0x80017298u: goto label_80017298;
    case 0x8001729Cu: goto label_8001729C;
    case 0x800172A0u: goto label_800172A0;
    case 0x800172A4u: goto label_800172A4;
    case 0x800172A8u: goto label_800172A8;
    case 0x800172ACu: goto label_800172AC;
    case 0x800172B0u: goto label_800172B0;
    case 0x800172B4u: goto label_800172B4;
    case 0x800172B8u: goto label_800172B8;
    case 0x800172BCu: goto label_800172BC;
    default: return;
    }
label_800132C0:
    ctx->pc = 0x800132C0u;
    ctx->downcount -= 5;
    // 800132C0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800132C4:
    ctx->pc = 0x800132C4u;
    // 800132C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800132C8:
    ctx->pc = 0x800132C8u;
    // 800132C8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800132CC:
    ctx->pc = 0x800132CCu;
    // 800132CC: lwz     r3, -32568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32568);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800132D0:
    ctx->pc = 0x800132D0u;
    // 800132D0: bl      0x80039A44
    {
            ctx->lr = 0x800132D4u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_800132D4:
    ctx->pc = 0x800132D4u;
    ctx->downcount -= 2;
    // 800132D4: lwz     r3, -32564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32564);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800132D8:
    ctx->pc = 0x800132D8u;
    // 800132D8: bl      0x80039A44
    {
            ctx->lr = 0x800132DCu;
            ctx->pc = 0x80039A44u;
            return;
    }

label_800132DC:
    ctx->pc = 0x800132DCu;
    ctx->downcount -= 2;
    // 800132DC: lwz     r3, -32560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32560);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800132E0:
    ctx->pc = 0x800132E0u;
    // 800132E0: bl      0x80039A44
    {
            ctx->lr = 0x800132E4u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_800132E4:
    ctx->pc = 0x800132E4u;
    ctx->downcount -= 2;
    // 800132E4: lwz     r3, -32556(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32556);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800132E8:
    ctx->pc = 0x800132E8u;
    // 800132E8: bl      0x80039A44
    {
            ctx->lr = 0x800132ECu;
            ctx->pc = 0x80039A44u;
            return;
    }

label_800132EC:
    ctx->pc = 0x800132ECu;
    ctx->downcount -= 2;
    // 800132EC: lwz     r3, -32552(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32552);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800132F0:
    ctx->pc = 0x800132F0u;
    // 800132F0: bl      0x80039A44
    {
            ctx->lr = 0x800132F4u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_800132F4:
    ctx->pc = 0x800132F4u;
    ctx->downcount -= 2;
    // 800132F4: lwz     r3, -32548(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32548);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800132F8:
    ctx->pc = 0x800132F8u;
    // 800132F8: bl      0x80039A44
    {
            ctx->lr = 0x800132FCu;
            ctx->pc = 0x80039A44u;
            return;
    }

label_800132FC:
    ctx->pc = 0x800132FCu;
    ctx->downcount -= 2;
    // 800132FC: lwz     r3, -32544(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32544);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80013300:
    ctx->pc = 0x80013300u;
    // 80013300: bl      0x80039A44
    {
            ctx->lr = 0x80013304u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_80013304:
    ctx->pc = 0x80013304u;
    ctx->downcount -= 2;
    // 80013304: lwz     r3, -32540(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32540);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80013308:
    ctx->pc = 0x80013308u;
    // 80013308: bl      0x80039A44
    {
            ctx->lr = 0x8001330Cu;
            ctx->pc = 0x80039A44u;
            return;
    }

label_8001330C:
    ctx->pc = 0x8001330Cu;
    ctx->downcount -= 5;
    // 8001330C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013310:
    ctx->pc = 0x80013310u;
    // 80013310: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013314:
    ctx->pc = 0x80013314u;
    // 80013314: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80013318:
    ctx->pc = 0x80013318u;
    // 80013318: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_8001331C:
    ctx->pc = 0x8001331Cu;
    ctx->downcount -= 10;
    // 8001331C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013320:
    ctx->pc = 0x80013320u;
    // 80013320: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013324:
    ctx->pc = 0x80013324u;
    // 80013324: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013328:
    ctx->pc = 0x80013328u;
    // 80013328: addi    r9, r13, -32536
    ctx->gpr[9] = ctx->gpr[13] + (u32)(s32)(-32536);

label_8001332C:
    ctx->pc = 0x8001332Cu;
    // 8001332C: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80013330:
    ctx->pc = 0x80013330u;
    // 80013330: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80013334:
    ctx->pc = 0x80013334u;
    // 80013334: addi    r11, r11, -1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-1);

label_80013338:
    ctx->pc = 0x80013338u;
    // 80013338: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001333C:
    ctx->pc = 0x8001333Cu;
    // 8001333C: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80013340:
    ctx->pc = 0x80013340u;
    // 80013340: bc    12, 1, 0x8001336C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001336C;
        }
    }

label_80013344:
    ctx->pc = 0x80013344u;
    ctx->downcount -= 8;
    // 80013344: lwz     r3, -32568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32568);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80013348:
    ctx->pc = 0x80013348u;
    // 80013348: lis     r6, -32712
    ctx->gpr[6] = ((u32)(s32)(-32712) << 16);

label_8001334C:
    ctx->pc = 0x8001334Cu;
    // 8001334C: lis     r7, -32712
    ctx->gpr[7] = ((u32)(s32)(-32712) << 16);

label_80013350:
    ctx->pc = 0x80013350u;
    // 80013350: addi    r6, r6, -26964
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-26964);

label_80013354:
    ctx->pc = 0x80013354u;
    // 80013354: addi    r7, r7, -25940
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(-25940);

label_80013358:
    ctx->pc = 0x80013358u;
    // 80013358: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_8001335C:
    ctx->pc = 0x8001335Cu;
    // 8001335C: li      r5, 16
    ctx->gpr[5] = (u32)(s32)(16);

label_80013360:
    ctx->pc = 0x80013360u;
    // 80013360: bl      0x800137BC
    {
            ctx->lr = 0x80013364u;
            goto label_800137BC;
    }

label_80013364:
    ctx->pc = 0x80013364u;
    ctx->downcount -= 2;
    // 80013364: li      r0, 280
    ctx->gpr[0] = (u32)(s32)(280);

label_80013368:
    ctx->pc = 0x80013368u;
    // 80013368: stw     r0, -32536(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32536);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001336C:
    ctx->pc = 0x8001336Cu;
    ctx->downcount -= 7;
    // 8001336C: addi    r9, r13, -32532
    ctx->gpr[9] = ctx->gpr[13] + (u32)(s32)(-32532);

label_80013370:
    ctx->pc = 0x80013370u;
    // 80013370: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80013374:
    ctx->pc = 0x80013374u;
    // 80013374: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80013378:
    ctx->pc = 0x80013378u;
    // 80013378: addi    r11, r11, -1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-1);

label_8001337C:
    ctx->pc = 0x8001337Cu;
    // 8001337C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013380:
    ctx->pc = 0x80013380u;
    // 80013380: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80013384:
    ctx->pc = 0x80013384u;
    // 80013384: bc    12, 1, 0x800133B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800133B0;
        }
    }

label_80013388:
    ctx->pc = 0x80013388u;
    ctx->downcount -= 8;
    // 80013388: lwz     r3, -32564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32564);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001338C:
    ctx->pc = 0x8001338Cu;
    // 8001338C: lis     r6, -32712
    ctx->gpr[6] = ((u32)(s32)(-32712) << 16);

label_80013390:
    ctx->pc = 0x80013390u;
    // 80013390: lis     r7, -32712
    ctx->gpr[7] = ((u32)(s32)(-32712) << 16);

label_80013394:
    ctx->pc = 0x80013394u;
    // 80013394: addi    r6, r6, -23892
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-23892);

label_80013398:
    ctx->pc = 0x80013398u;
    // 80013398: addi    r7, r7, -19796
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(-19796);

label_8001339C:
    ctx->pc = 0x8001339Cu;
    // 8001339C: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_800133A0:
    ctx->pc = 0x800133A0u;
    // 800133A0: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_800133A4:
    ctx->pc = 0x800133A4u;
    // 800133A4: bl      0x800137BC
    {
            ctx->lr = 0x800133A8u;
            goto label_800137BC;
    }

label_800133A8:
    ctx->pc = 0x800133A8u;
    ctx->downcount -= 2;
    // 800133A8: li      r0, 200
    ctx->gpr[0] = (u32)(s32)(200);

label_800133AC:
    ctx->pc = 0x800133ACu;
    // 800133AC: stw     r0, -32532(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32532);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800133B0:
    ctx->pc = 0x800133B0u;
    ctx->downcount -= 7;
    // 800133B0: addi    r9, r13, -32528
    ctx->gpr[9] = ctx->gpr[13] + (u32)(s32)(-32528);

label_800133B4:
    ctx->pc = 0x800133B4u;
    // 800133B4: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800133B8:
    ctx->pc = 0x800133B8u;
    // 800133B8: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800133BC:
    ctx->pc = 0x800133BCu;
    // 800133BC: addi    r11, r11, -1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-1);

label_800133C0:
    ctx->pc = 0x800133C0u;
    // 800133C0: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800133C4:
    ctx->pc = 0x800133C4u;
    // 800133C4: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800133C8:
    ctx->pc = 0x800133C8u;
    // 800133C8: bc    12, 1, 0x800133F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800133F4;
        }
    }

label_800133CC:
    ctx->pc = 0x800133CCu;
    ctx->downcount -= 8;
    // 800133CC: lwz     r3, -32560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32560);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800133D0:
    ctx->pc = 0x800133D0u;
    // 800133D0: lis     r6, -32712
    ctx->gpr[6] = ((u32)(s32)(-32712) << 16);

label_800133D4:
    ctx->pc = 0x800133D4u;
    // 800133D4: lis     r7, -32712
    ctx->gpr[7] = ((u32)(s32)(-32712) << 16);

label_800133D8:
    ctx->pc = 0x800133D8u;
    // 800133D8: addi    r6, r6, -11604
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-11604);

label_800133DC:
    ctx->pc = 0x800133DCu;
    // 800133DC: addi    r7, r7, 4780
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(4780);

label_800133E0:
    ctx->pc = 0x800133E0u;
    // 800133E0: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_800133E4:
    ctx->pc = 0x800133E4u;
    // 800133E4: li      r5, 64
    ctx->gpr[5] = (u32)(s32)(64);

label_800133E8:
    ctx->pc = 0x800133E8u;
    // 800133E8: bl      0x800137BC
    {
            ctx->lr = 0x800133ECu;
            goto label_800137BC;
    }

label_800133EC:
    ctx->pc = 0x800133ECu;
    ctx->downcount -= 2;
    // 800133EC: li      r0, 120
    ctx->gpr[0] = (u32)(s32)(120);

label_800133F0:
    ctx->pc = 0x800133F0u;
    // 800133F0: stw     r0, -32528(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32528);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800133F4:
    ctx->pc = 0x800133F4u;
    ctx->downcount -= 7;
    // 800133F4: addi    r9, r13, -32524
    ctx->gpr[9] = ctx->gpr[13] + (u32)(s32)(-32524);

label_800133F8:
    ctx->pc = 0x800133F8u;
    // 800133F8: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800133FC:
    ctx->pc = 0x800133FCu;
    // 800133FC: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80013400:
    ctx->pc = 0x80013400u;
    // 80013400: addi    r11, r11, -1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-1);

label_80013404:
    ctx->pc = 0x80013404u;
    // 80013404: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013408:
    ctx->pc = 0x80013408u;
    // 80013408: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8001340C:
    ctx->pc = 0x8001340Cu;
    // 8001340C: bc    12, 1, 0x80013438
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013438;
        }
    }

label_80013410:
    ctx->pc = 0x80013410u;
    ctx->downcount -= 8;
    // 80013410: lwz     r3, -32556(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32556);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80013414:
    ctx->pc = 0x80013414u;
    // 80013414: lis     r6, -32711
    ctx->gpr[6] = ((u32)(s32)(-32711) << 16);

label_80013418:
    ctx->pc = 0x80013418u;
    // 80013418: lis     r7, -32710
    ctx->gpr[7] = ((u32)(s32)(-32710) << 16);

label_8001341C:
    ctx->pc = 0x8001341Cu;
    // 8001341C: addi    r6, r6, -27988
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-27988);

label_80013420:
    ctx->pc = 0x80013420u;
    // 80013420: addi    r7, r7, -27988
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(-27988);

label_80013424:
    ctx->pc = 0x80013424u;
    // 80013424: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_80013428:
    ctx->pc = 0x80013428u;
    // 80013428: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_8001342C:
    ctx->pc = 0x8001342Cu;
    // 8001342C: bl      0x800137BC
    {
            ctx->lr = 0x80013430u;
            goto label_800137BC;
    }

label_80013430:
    ctx->pc = 0x80013430u;
    ctx->downcount -= 2;
    // 80013430: li      r0, 40
    ctx->gpr[0] = (u32)(s32)(40);

label_80013434:
    ctx->pc = 0x80013434u;
    // 80013434: stw     r0, -32524(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32524);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013438:
    ctx->pc = 0x80013438u;
    ctx->downcount -= 12;
    // 80013438: lwz     r3, -32568(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32568);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001343C:
    ctx->pc = 0x8001343Cu;
    // 8001343C: lis     r6, -32712
    ctx->gpr[6] = ((u32)(s32)(-32712) << 16);

label_80013440:
    ctx->pc = 0x80013440u;
    // 80013440: lwz     r10, -32536(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32536);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80013444:
    ctx->pc = 0x80013444u;
    // 80013444: lis     r7, -32712
    ctx->gpr[7] = ((u32)(s32)(-32712) << 16);

label_80013448:
    ctx->pc = 0x80013448u;
    // 80013448: lis     r8, -32712
    ctx->gpr[8] = ((u32)(s32)(-32712) << 16);

label_8001344C:
    ctx->pc = 0x8001344Cu;
    // 8001344C: addi    r6, r6, -24916
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-24916);

label_80013450:
    ctx->pc = 0x80013450u;
    // 80013450: addi    r7, r7, -26964
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(-26964);

label_80013454:
    ctx->pc = 0x80013454u;
    // 80013454: addi    r8, r8, -25940
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(-25940);

label_80013458:
    ctx->pc = 0x80013458u;
    // 80013458: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_8001345C:
    ctx->pc = 0x8001345Cu;
    // 8001345C: li      r5, 16
    ctx->gpr[5] = (u32)(s32)(16);

label_80013460:
    ctx->pc = 0x80013460u;
    // 80013460: li      r9, 280
    ctx->gpr[9] = (u32)(s32)(280);

label_80013464:
    ctx->pc = 0x80013464u;
    // 80013464: bl      0x80013610
    {
            ctx->lr = 0x80013468u;
            goto label_80013610;
    }

label_80013468:
    ctx->pc = 0x80013468u;
    ctx->downcount -= 12;
    // 80013468: lwz     r3, -32564(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32564);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001346C:
    ctx->pc = 0x8001346Cu;
    // 8001346C: lis     r6, -32712
    ctx->gpr[6] = ((u32)(s32)(-32712) << 16);

label_80013470:
    ctx->pc = 0x80013470u;
    // 80013470: lwz     r10, -32532(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32532);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80013474:
    ctx->pc = 0x80013474u;
    // 80013474: lis     r7, -32712
    ctx->gpr[7] = ((u32)(s32)(-32712) << 16);

label_80013478:
    ctx->pc = 0x80013478u;
    // 80013478: lis     r8, -32712
    ctx->gpr[8] = ((u32)(s32)(-32712) << 16);

label_8001347C:
    ctx->pc = 0x8001347Cu;
    // 8001347C: addi    r6, r6, -15700
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-15700);

label_80013480:
    ctx->pc = 0x80013480u;
    // 80013480: addi    r7, r7, -23892
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(-23892);

label_80013484:
    ctx->pc = 0x80013484u;
    // 80013484: addi    r8, r8, -19796
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(-19796);

label_80013488:
    ctx->pc = 0x80013488u;
    // 80013488: li      r4, 32
    ctx->gpr[4] = (u32)(s32)(32);

label_8001348C:
    ctx->pc = 0x8001348Cu;
    // 8001348C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_80013490:
    ctx->pc = 0x80013490u;
    // 80013490: li      r9, 200
    ctx->gpr[9] = (u32)(s32)(200);

label_80013494:
    ctx->pc = 0x80013494u;
    // 80013494: bl      0x80013610
    {
            ctx->lr = 0x80013498u;
            goto label_80013610;
    }

label_80013498:
    ctx->pc = 0x80013498u;
    ctx->downcount -= 12;
    // 80013498: lwz     r3, -32560(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32560);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001349C:
    ctx->pc = 0x8001349Cu;
    // 8001349C: lis     r6, -32712
    ctx->gpr[6] = ((u32)(s32)(-32712) << 16);

label_800134A0:
    ctx->pc = 0x800134A0u;
    // 800134A0: lwz     r10, -32528(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32528);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800134A4:
    ctx->pc = 0x800134A4u;
    // 800134A4: lis     r7, -32712
    ctx->gpr[7] = ((u32)(s32)(-32712) << 16);

label_800134A8:
    ctx->pc = 0x800134A8u;
    // 800134A8: lis     r8, -32712
    ctx->gpr[8] = ((u32)(s32)(-32712) << 16);

label_800134AC:
    ctx->pc = 0x800134ACu;
    // 800134AC: addi    r6, r6, 21164
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(21164);

label_800134B0:
    ctx->pc = 0x800134B0u;
    // 800134B0: addi    r7, r7, -11604
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(-11604);

label_800134B4:
    ctx->pc = 0x800134B4u;
    // 800134B4: addi    r8, r8, 4780
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(4780);

label_800134B8:
    ctx->pc = 0x800134B8u;
    // 800134B8: li      r4, 64
    ctx->gpr[4] = (u32)(s32)(64);

label_800134BC:
    ctx->pc = 0x800134BCu;
    // 800134BC: li      r5, 64
    ctx->gpr[5] = (u32)(s32)(64);

label_800134C0:
    ctx->pc = 0x800134C0u;
    // 800134C0: li      r9, 120
    ctx->gpr[9] = (u32)(s32)(120);

label_800134C4:
    ctx->pc = 0x800134C4u;
    // 800134C4: bl      0x80013610
    {
            ctx->lr = 0x800134C8u;
            goto label_80013610;
    }

label_800134C8:
    ctx->pc = 0x800134C8u;
    ctx->downcount -= 12;
    // 800134C8: lwz     r10, -32524(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32524);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800134CC:
    ctx->pc = 0x800134CCu;
    // 800134CC: lis     r6, -32709
    ctx->gpr[6] = ((u32)(s32)(-32709) << 16);

label_800134D0:
    ctx->pc = 0x800134D0u;
    // 800134D0: lwz     r3, -32556(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32556);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800134D4:
    ctx->pc = 0x800134D4u;
    // 800134D4: lis     r7, -32711
    ctx->gpr[7] = ((u32)(s32)(-32711) << 16);

label_800134D8:
    ctx->pc = 0x800134D8u;
    // 800134D8: lis     r8, -32710
    ctx->gpr[8] = ((u32)(s32)(-32710) << 16);

label_800134DC:
    ctx->pc = 0x800134DCu;
    // 800134DC: addi    r6, r6, -27988
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-27988);

label_800134E0:
    ctx->pc = 0x800134E0u;
    // 800134E0: addi    r7, r7, -27988
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(-27988);

label_800134E4:
    ctx->pc = 0x800134E4u;
    // 800134E4: addi    r8, r8, -27988
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(-27988);

label_800134E8:
    ctx->pc = 0x800134E8u;
    // 800134E8: li      r9, 40
    ctx->gpr[9] = (u32)(s32)(40);

label_800134EC:
    ctx->pc = 0x800134ECu;
    // 800134EC: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_800134F0:
    ctx->pc = 0x800134F0u;
    // 800134F0: li      r5, 128
    ctx->gpr[5] = (u32)(s32)(128);

label_800134F4:
    ctx->pc = 0x800134F4u;
    // 800134F4: bl      0x80013610
    {
            ctx->lr = 0x800134F8u;
            goto label_80013610;
    }

label_800134F8:
    ctx->pc = 0x800134F8u;
    ctx->downcount -= 5;
    // 800134F8: lwz     r4, -32552(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32552);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800134FC:
    ctx->pc = 0x800134FCu;
    // 800134FC: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_80013500:
    ctx->pc = 0x80013500u;
    // 80013500: addi    r3, r3, -27988
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27988);

label_80013504:
    ctx->pc = 0x80013504u;
    // 80013504: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80013508:
    ctx->pc = 0x80013508u;
    // 80013508: bl      0x80012E68
    {
            ctx->lr = 0x8001350Cu;
            ctx->pc = 0x80012E68u;
            return;
    }

label_8001350C:
    ctx->pc = 0x8001350Cu;
    ctx->downcount -= 5;
    // 8001350C: lwz     r4, -32548(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32548);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80013510:
    ctx->pc = 0x80013510u;
    // 80013510: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_80013514:
    ctx->pc = 0x80013514u;
    // 80013514: addi    r3, r3, -27956
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27956);

label_80013518:
    ctx->pc = 0x80013518u;
    // 80013518: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_8001351C:
    ctx->pc = 0x8001351Cu;
    // 8001351C: bl      0x80012E68
    {
            ctx->lr = 0x80013520u;
            ctx->pc = 0x80012E68u;
            return;
    }

label_80013520:
    ctx->pc = 0x80013520u;
    ctx->downcount -= 5;
    // 80013520: lwz     r4, -32544(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32544);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80013524:
    ctx->pc = 0x80013524u;
    // 80013524: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_80013528:
    ctx->pc = 0x80013528u;
    // 80013528: addi    r3, r3, -27924
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27924);

label_8001352C:
    ctx->pc = 0x8001352Cu;
    // 8001352C: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80013530:
    ctx->pc = 0x80013530u;
    // 80013530: bl      0x80012E68
    {
            ctx->lr = 0x80013534u;
            ctx->pc = 0x80012E68u;
            return;
    }

label_80013534:
    ctx->pc = 0x80013534u;
    ctx->downcount -= 5;
    // 80013534: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_80013538:
    ctx->pc = 0x80013538u;
    // 80013538: lwz     r4, -32540(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32540);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8001353C:
    ctx->pc = 0x8001353Cu;
    // 8001353C: addi    r3, r3, -27892
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27892);

label_80013540:
    ctx->pc = 0x80013540u;
    // 80013540: li      r5, 256
    ctx->gpr[5] = (u32)(s32)(256);

label_80013544:
    ctx->pc = 0x80013544u;
    // 80013544: bl      0x80012E68
    {
            ctx->lr = 0x80013548u;
            ctx->pc = 0x80012E68u;
            return;
    }

label_80013548:
    ctx->pc = 0x80013548u;
    ctx->downcount -= 5;
    // 80013548: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001354C:
    ctx->pc = 0x8001354Cu;
    // 8001354C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013550:
    ctx->pc = 0x80013550u;
    // 80013550: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80013554:
    ctx->pc = 0x80013554u;
    // 80013554: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013558:
    ctx->pc = 0x80013558u;
    ctx->downcount -= 24;
    // 80013558: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8001355C:
    ctx->pc = 0x8001355Cu;
    // 8001355C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013560:
    ctx->pc = 0x80013560u;
    // 80013560: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80013564:
    ctx->pc = 0x80013564u;
    // 80013564: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013568:
    ctx->pc = 0x80013568u;
    // 80013568: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_8001356C:
    ctx->pc = 0x8001356Cu;
    // 8001356C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80013570:
    ctx->pc = 0x80013570u;
    // 80013570: lfs     f1, -20692(r30)
    if (!ppc_fp_available(ctx, 0x80013570u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-20692);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80013574:
    ctx->pc = 0x80013574u;
    // 80013574: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_80013578:
    ctx->pc = 0x80013578u;
    // 80013578: lfs     f3, -20688(r9)
    if (!ppc_fp_available(ctx, 0x80013578u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20688);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8001357C:
    ctx->pc = 0x8001357Cu;
    // 8001357C: addi    r3, r3, -27860
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27860);

label_80013580:
    ctx->pc = 0x80013580u;
    // 80013580: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80013580u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80013584:
    ctx->pc = 0x80013584u;
    // 80013584: li      r4, 640
    ctx->gpr[4] = (u32)(s32)(640);

label_80013588:
    ctx->pc = 0x80013588u;
    // 80013588: li      r5, 480
    ctx->gpr[5] = (u32)(s32)(480);

label_8001358C:
    ctx->pc = 0x8001358Cu;
    // 8001358C: bl      0x80012C7C
    {
            ctx->lr = 0x80013590u;
            ctx->pc = 0x80012C7Cu;
            return;
    }

label_80013590:
    ctx->pc = 0x80013590u;
    ctx->downcount -= 9;
    // 80013590: lfs     f1, -20692(r30)
    if (!ppc_fp_available(ctx, 0x80013590u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-20692);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80013594:
    ctx->pc = 0x80013594u;
    // 80013594: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80013598:
    ctx->pc = 0x80013598u;
    // 80013598: lfs     f3, -20684(r9)
    if (!ppc_fp_available(ctx, 0x80013598u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20684);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8001359C:
    ctx->pc = 0x8001359Cu;
    // 8001359C: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_800135A0:
    ctx->pc = 0x800135A0u;
    // 800135A0: addi    r3, r3, -27828
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27828);

label_800135A4:
    ctx->pc = 0x800135A4u;
    // 800135A4: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x800135A4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_800135A8:
    ctx->pc = 0x800135A8u;
    // 800135A8: li      r4, 640
    ctx->gpr[4] = (u32)(s32)(640);

label_800135AC:
    ctx->pc = 0x800135ACu;
    // 800135AC: li      r5, 480
    ctx->gpr[5] = (u32)(s32)(480);

label_800135B0:
    ctx->pc = 0x800135B0u;
    // 800135B0: bl      0x80012C7C
    {
            ctx->lr = 0x800135B4u;
            ctx->pc = 0x80012C7Cu;
            return;
    }

label_800135B4:
    ctx->pc = 0x800135B4u;
    ctx->downcount -= 9;
    // 800135B4: lfs     f1, -20692(r30)
    if (!ppc_fp_available(ctx, 0x800135B4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-20692);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800135B8:
    ctx->pc = 0x800135B8u;
    // 800135B8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800135BC:
    ctx->pc = 0x800135BCu;
    // 800135BC: lfs     f3, -20680(r9)
    if (!ppc_fp_available(ctx, 0x800135BCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20680);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800135C0:
    ctx->pc = 0x800135C0u;
    // 800135C0: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_800135C4:
    ctx->pc = 0x800135C4u;
    // 800135C4: addi    r3, r3, -27796
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27796);

label_800135C8:
    ctx->pc = 0x800135C8u;
    // 800135C8: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x800135C8u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_800135CC:
    ctx->pc = 0x800135CCu;
    // 800135CC: li      r4, 640
    ctx->gpr[4] = (u32)(s32)(640);

label_800135D0:
    ctx->pc = 0x800135D0u;
    // 800135D0: li      r5, 480
    ctx->gpr[5] = (u32)(s32)(480);

label_800135D4:
    ctx->pc = 0x800135D4u;
    // 800135D4: bl      0x80012C7C
    {
            ctx->lr = 0x800135D8u;
            ctx->pc = 0x80012C7Cu;
            return;
    }

label_800135D8:
    ctx->pc = 0x800135D8u;
    ctx->downcount -= 9;
    // 800135D8: lfs     f1, -20692(r30)
    if (!ppc_fp_available(ctx, 0x800135D8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-20692);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800135DC:
    ctx->pc = 0x800135DCu;
    // 800135DC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800135E0:
    ctx->pc = 0x800135E0u;
    // 800135E0: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_800135E4:
    ctx->pc = 0x800135E4u;
    // 800135E4: lfs     f3, -20676(r9)
    if (!ppc_fp_available(ctx, 0x800135E4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20676);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800135E8:
    ctx->pc = 0x800135E8u;
    // 800135E8: addi    r3, r3, -27764
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27764);

label_800135EC:
    ctx->pc = 0x800135ECu;
    // 800135EC: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x800135ECu)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_800135F0:
    ctx->pc = 0x800135F0u;
    // 800135F0: li      r4, 640
    ctx->gpr[4] = (u32)(s32)(640);

label_800135F4:
    ctx->pc = 0x800135F4u;
    // 800135F4: li      r5, 480
    ctx->gpr[5] = (u32)(s32)(480);

label_800135F8:
    ctx->pc = 0x800135F8u;
    // 800135F8: bl      0x80012C7C
    {
            ctx->lr = 0x800135FCu;
            ctx->pc = 0x80012C7Cu;
            return;
    }

label_800135FC:
    ctx->pc = 0x800135FCu;
    ctx->downcount -= 16;
    // 800135FC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013600:
    ctx->pc = 0x80013600u;
    // 80013600: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013604:
    ctx->pc = 0x80013604u;
    // 80013604: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80013608:
    ctx->pc = 0x80013608u;
    // 80013608: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8001360C:
    ctx->pc = 0x8001360Cu;
    // 8001360C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013610:
    ctx->pc = 0x80013610u;
    ctx->downcount -= 58;
    // 80013610: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013614:
    ctx->pc = 0x80013614u;
    // 80013614: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013618:
    ctx->pc = 0x80013618u;
    // 80013618: stmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8001361C:
    ctx->pc = 0x8001361Cu;
    // 8001361C: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013620:
    ctx->pc = 0x80013620u;
    // 80013620: xoris   r10, r10, 0x8000
    ctx->gpr[10] = ctx->gpr[10] ^ (0x8000u << 16);

label_80013624:
    ctx->pc = 0x80013624u;
    // 80013624: stw     r10, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80013628:
    ctx->pc = 0x80013628u;
    // 80013628: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8001362C:
    ctx->pc = 0x8001362Cu;
    // 8001362C: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80013630:
    ctx->pc = 0x80013630u;
    // 80013630: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_80013634:
    ctx->pc = 0x80013634u;
    // 80013634: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013638:
    ctx->pc = 0x80013638u;
    // 80013638: lis     r12, -32738
    ctx->gpr[12] = ((u32)(s32)(-32738) << 16);

label_8001363C:
    ctx->pc = 0x8001363Cu;
    // 8001363C: lfd     f12, -20672(r12)
    if (!ppc_fp_available(ctx, 0x8001363Cu)) return;
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(-20672);
        ctx->fpr[12] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80013640:
    ctx->pc = 0x80013640u;
    // 80013640: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80013644:
    ctx->pc = 0x80013644u;
    // 80013644: lfd     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x80013644u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80013648:
    ctx->pc = 0x80013648u;
    // 80013648: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8001364C:
    ctx->pc = 0x8001364Cu;
    // 8001364C: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80013650:
    ctx->pc = 0x80013650u;
    // 80013650: mtlr    r5
    ctx->lr = ctx->gpr[5];

label_80013654:
    ctx->pc = 0x80013654u;
    // 80013654: fsub   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x80013654u)) return;
    ppc_fsub(ctx, 13, 13, 12);

label_80013658:
    ctx->pc = 0x80013658u;
    // 80013658: lfs     f11, -20664(r3)
    if (!ppc_fp_available(ctx, 0x80013658u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-20664);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8001365C:
    ctx->pc = 0x8001365Cu;
    // 8001365C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013660:
    ctx->pc = 0x80013660u;
    // 80013660: frsp    f13, f13
    if (!ppc_fp_available(ctx, 0x80013660u)) return;
    ppc_frsp(ctx, 13, 13);

label_80013664:
    ctx->pc = 0x80013664u;
    // 80013664: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80013668:
    ctx->pc = 0x80013668u;
    // 80013668: or   r29, r7, r7
    {
        ctx->gpr[29] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8001366C:
    ctx->pc = 0x8001366Cu;
    // 8001366C: lfd     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x8001366Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80013670:
    ctx->pc = 0x80013670u;
    // 80013670: or   r30, r8, r8
    {
        ctx->gpr[30] = ctx->gpr[8] | ctx->gpr[8];
    }

label_80013674:
    ctx->pc = 0x80013674u;
    // 80013674: cmpw    r9, r31
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013678:
    ctx->pc = 0x80013678u;
    // 80013678: fsub   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x80013678u)) return;
    ppc_fsub(ctx, 0, 0, 12);

label_8001367C:
    ctx->pc = 0x8001367Cu;
    // 8001367C: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8001367Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_80013680:
    ctx->pc = 0x80013680u;
    // 80013680: fdivs   f13, f13, f0
    if (!ppc_fp_available(ctx, 0x80013680u)) return;
    ppc_fdivs(ctx, 13, 13, 0);

label_80013684:
    ctx->pc = 0x80013684u;
    // 80013684: fsubs   f11, f11, f13
    if (!ppc_fp_available(ctx, 0x80013684u)) return;
    ppc_fsubs(ctx, 11, 11, 13);

label_80013688:
    ctx->pc = 0x80013688u;
    // 80013688: bc    4, 0, 0x8001373C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001373C;
        }
    }

label_8001368C:
    ctx->pc = 0x8001368Cu;
    ctx->downcount -= 3;
    // 8001368C: addi    r28, r12, -20672
    ctx->gpr[28] = ctx->gpr[12] + (u32)(s32)(-20672);

label_80013690:
    ctx->pc = 0x80013690u;
    // 80013690: li      r8, 3
    ctx->gpr[8] = (u32)(s32)(3);

label_80013694:
    ctx->pc = 0x80013694u;
    // 80013694: li      r12, 3
    ctx->gpr[12] = (u32)(s32)(3);

label_80013698:
    ctx->pc = 0x80013698u;
    ctx->downcount -= 4;
    // 80013698: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001369C:
    // 8001369C: addi    r7, r9, 1
    ctx->gpr[7] = ctx->gpr[9] + (u32)(s32)(1);

label_800136A0:
    // 800136A0: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800136A4:
    // 800136A4: bc    4, 1, 0x80013730
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80013730;
        }
    }

label_800136A8:
    ctx->pc = 0x800136A8u;
    ctx->downcount -= 6;
    // 800136A8: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_800136AC:
    ctx->pc = 0x800136ACu;
    // 800136AC: lfd     f10, 0(r28)
    if (!ppc_fp_available(ctx, 0x800136ACu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->fpr[10] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800136B0:
    // 800136B0: lis     r4, 17200
    ctx->gpr[4] = ((u32)(s32)(17200) << 16);

label_800136B4:
    // 800136B4: add   r3, r12, r29
    {
        u32 a = ctx->gpr[12];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800136B8:
    // 800136B8: add   r5, r8, r30
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_800136BC:
    ctx->pc = 0x800136BCu;
    ctx->downcount -= 29;
    // 800136BC: lbz     r11, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_800136C0:
    ctx->pc = 0x800136C0u;
    // 800136C0: lbz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800136C4:
    // 800136C4: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800136C8:
    // 800136C8: addi    r5, r5, 4
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(4);

label_800136CC:
    // 800136CC: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_800136D0:
    // 800136D0: subf   r0, r11, r0
    {
        u32 a = ~ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800136D4:
    // 800136D4: addi    r8, r8, 4
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(4);

label_800136D8:
    // 800136D8: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_800136DC:
    // 800136DC: addi    r12, r12, 4
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(4);

label_800136E0:
    ctx->pc = 0x800136E0u;
    // 800136E0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800136E4:
    ctx->pc = 0x800136E4u;
    // 800136E4: stw     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_800136E8:
    ctx->pc = 0x800136E8u;
    // 800136E8: lfd     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800136E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800136EC:
    ctx->pc = 0x800136ECu;
    // 800136EC: fsub   f0, f0, f10
    if (!ppc_fp_available(ctx, 0x800136ECu)) return;
    ppc_fsub(ctx, 0, 0, 10);

label_800136F0:
    ctx->pc = 0x800136F0u;
    // 800136F0: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x800136F0u)) return;
    ppc_frsp(ctx, 0, 0);

label_800136F4:
    ctx->pc = 0x800136F4u;
    // 800136F4: fmuls   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x800136F4u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_800136F8:
    ctx->pc = 0x800136F8u;
    // 800136F8: fmr    f13, f0
    if (!ppc_fp_available(ctx, 0x800136F8u)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_800136FC:
    ctx->pc = 0x800136FCu;
    // 800136FC: fctiwz    f12, f13
    if (!ppc_fp_available(ctx, 0x800136FCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_80013700:
    ctx->pc = 0x80013700u;
    // 80013700: stfd     f12, 8(r1)
    if (!ppc_fp_available(ctx, 0x80013700u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_80013704:
    ctx->pc = 0x80013704u;
    // 80013704: lwz     r10, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80013708:
    // 80013708: add   r11, r11, r10
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8001370C:
    // 8001370C: rlwinm r11, r11, 0, 24, 31
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x000000FFu;
    }

label_80013710:
    // 80013710: rlwinm r9, r11, 8, 0, 23
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[11], 8u) & 0xFFFFFF00u;
    }

label_80013714:
    // 80013714: rlwinm r0, r11, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 16u) & 0xFFFF0000u;
    }

label_80013718:
    // 80013718: oris    r9, r9, 0xFF00
    ctx->gpr[9] = ctx->gpr[9] | (0xFF00u << 16);

label_8001371C:
    // 8001371C: or   r0, r0, r9
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[9];
    }

label_80013720:
    // 80013720: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80013724:
    ctx->pc = 0x80013724u;
    // 80013724: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013728:
    // 80013728: addi    r6, r6, 4
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(4);

label_8001372C:
    // 8001372C: bc    16, 0, 0x800136BC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800136BCu;
                return;
            }
            goto label_800136BC;
        }
    }

label_80013730:
    ctx->downcount -= 3;
    // 80013730: or   r9, r7, r7
    {
        ctx->gpr[9] = ctx->gpr[7] | ctx->gpr[7];
    }

label_80013734:
    // 80013734: cmpw    r9, r31
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013738:
    // 80013738: bc    12, 0, 0x80013698
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013698u;
                return;
            }
            goto label_80013698;
        }
    }

label_8001373C:
    ctx->pc = 0x8001373Cu;
    ctx->downcount -= 16;
    // 8001373C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013740:
    ctx->pc = 0x80013740u;
    // 80013740: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013744:
    ctx->pc = 0x80013744u;
    // 80013744: lmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80013748:
    ctx->pc = 0x80013748u;
    // 80013748: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8001374C:
    ctx->pc = 0x8001374Cu;
    // 8001374C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013750:
    ctx->pc = 0x80013750u;
    ctx->downcount -= 37;
    // 80013750: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013754:
    ctx->pc = 0x80013754u;
    // 80013754: rlwinm r11, r3, 13, 0, 18
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[3], 13u) & 0xFFFFE000u;
    }

label_80013758:
    ctx->pc = 0x80013758u;
    // 80013758: xor   r11, r11, r3
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[3];
    }

label_8001375C:
    ctx->pc = 0x8001375Cu;
    // 8001375C: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_80013760:
    ctx->pc = 0x80013760u;
    // 80013760: mullw   r9, r11, r11
    {
        s64 product = (s64)(s32)ctx->gpr[11] * (s64)(s32)ctx->gpr[11];
        ctx->gpr[9] = (u32)product;
    }

label_80013764:
    ctx->pc = 0x80013764u;
    // 80013764: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80013768:
    ctx->pc = 0x80013768u;
    // 80013768: lfd     f0, -20656(r10)
    if (!ppc_fp_available(ctx, 0x80013768u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-20656);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001376C:
    ctx->pc = 0x8001376Cu;
    // 8001376C: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_80013770:
    ctx->pc = 0x80013770u;
    // 80013770: lfs     f12, -20648(r8)
    if (!ppc_fp_available(ctx, 0x80013770u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-20648);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_80013774:
    ctx->pc = 0x80013774u;
    // 80013774: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80013778:
    ctx->pc = 0x80013778u;
    // 80013778: lfs     f13, -20644(r10)
    if (!ppc_fp_available(ctx, 0x80013778u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-20644);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8001377C:
    ctx->pc = 0x8001377Cu;
    // 8001377C: mulli   r9, r9, 15731
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)15731);

label_80013780:
    ctx->pc = 0x80013780u;
    // 80013780: addis   r9, r9, 12
    ctx->gpr[9] = ctx->gpr[9] + ((u32)(s32)(12) << 16);

label_80013784:
    ctx->pc = 0x80013784u;
    // 80013784: addi    r9, r9, 2789
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2789);

label_80013788:
    ctx->pc = 0x80013788u;
    // 80013788: mullw   r11, r11, r9
    {
        s64 product = (s64)(s32)ctx->gpr[11] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[11] = (u32)product;
    }

label_8001378C:
    ctx->pc = 0x8001378Cu;
    // 8001378C: addis   r11, r11, 21001
    ctx->gpr[11] = ctx->gpr[11] + ((u32)(s32)(21001) << 16);

label_80013790:
    ctx->pc = 0x80013790u;
    // 80013790: addi    r11, r11, -8947
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-8947);

label_80013794:
    ctx->pc = 0x80013794u;
    // 80013794: rlwinm r11, r11, 0, 1, 31
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x7FFFFFFFu;
    }

label_80013798:
    ctx->pc = 0x80013798u;
    // 80013798: stw     r11, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8001379C:
    ctx->pc = 0x8001379Cu;
    // 8001379C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800137A0:
    ctx->pc = 0x800137A0u;
    // 800137A0: lfd     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x800137A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800137A4:
    ctx->pc = 0x800137A4u;
    // 800137A4: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x800137A4u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_800137A8:
    ctx->pc = 0x800137A8u;
    // 800137A8: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x800137A8u)) return;
    ppc_frsp(ctx, 1, 1);

label_800137AC:
    ctx->pc = 0x800137ACu;
    // 800137AC: fmuls   f1, f1, f12
    if (!ppc_fp_available(ctx, 0x800137ACu)) return;
    ppc_fmuls(ctx, 1, 1, 12);

label_800137B0:
    ctx->pc = 0x800137B0u;
    // 800137B0: fsubs   f1, f13, f1
    if (!ppc_fp_available(ctx, 0x800137B0u)) return;
    ppc_fsubs(ctx, 1, 13, 1);

label_800137B4:
    ctx->pc = 0x800137B4u;
    // 800137B4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800137B8:
    ctx->pc = 0x800137B8u;
    // 800137B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800137BC:
    ctx->pc = 0x800137BCu;
    ctx->downcount -= 30;
    // 800137BC: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800137C0:
    ctx->pc = 0x800137C0u;
    // 800137C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800137C4:
    ctx->pc = 0x800137C4u;
    // 800137C4: stfd     f29, 56(r1)
    if (!ppc_fp_available(ctx, 0x800137C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_800137C8:
    ctx->pc = 0x800137C8u;
    // 800137C8: stfd     f30, 64(r1)
    if (!ppc_fp_available(ctx, 0x800137C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_800137CC:
    ctx->pc = 0x800137CCu;
    // 800137CC: stfd     f31, 72(r1)
    if (!ppc_fp_available(ctx, 0x800137CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800137D0:
    ctx->pc = 0x800137D0u;
    // 800137D0: stmw     r22, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 22; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800137D4:
    ctx->pc = 0x800137D4u;
    // 800137D4: stw     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800137D8:
    ctx->pc = 0x800137D8u;
    // 800137D8: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800137DC:
    ctx->pc = 0x800137DCu;
    // 800137DC: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_800137E0:
    ctx->pc = 0x800137E0u;
    // 800137E0: mullw   r5, r27, r29
    {
        s64 product = (s64)(s32)ctx->gpr[27] * (s64)(s32)ctx->gpr[29];
        ctx->gpr[5] = (u32)product;
    }

label_800137E4:
    ctx->pc = 0x800137E4u;
    // 800137E4: or   r30, r6, r6
    {
        ctx->gpr[30] = ctx->gpr[6] | ctx->gpr[6];
    }

label_800137E8:
    ctx->pc = 0x800137E8u;
    // 800137E8: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_800137EC:
    ctx->pc = 0x800137ECu;
    // 800137EC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800137F0:
    ctx->pc = 0x800137F0u;
    // 800137F0: rlwinm r5, r5, 2, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_800137F4:
    ctx->pc = 0x800137F4u;
    // 800137F4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800137F8:
    ctx->pc = 0x800137F8u;
    // 800137F8: bl      0x8016984C
    {
            ctx->lr = 0x800137FCu;
            ctx->pc = 0x8016984Cu;
            return;
    }

label_800137FC:
    ctx->pc = 0x800137FCu;
    ctx->downcount -= 3;
    // 800137FC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80013800:
    ctx->pc = 0x80013800u;
    // 80013800: cmpw    r9, r27
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013804:
    ctx->pc = 0x80013804u;
    // 80013804: bc    4, 0, 0x800138D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800138D8;
        }
    }

label_80013808:
    ctx->pc = 0x80013808u;
    ctx->downcount -= 3;
    // 80013808: lis     r22, -32738
    ctx->gpr[22] = ((u32)(s32)(-32738) << 16);

label_8001380C:
    ctx->pc = 0x8001380Cu;
    // 8001380C: lis     r23, -32738
    ctx->gpr[23] = ((u32)(s32)(-32738) << 16);

label_80013810:
    ctx->pc = 0x80013810u;
    // 80013810: lis     r24, -32738
    ctx->gpr[24] = ((u32)(s32)(-32738) << 16);

label_80013814:
    ctx->downcount -= 3;
    // 80013814: addi    r28, r9, 1
    ctx->gpr[28] = ctx->gpr[9] + (u32)(s32)(1);

label_80013818:
    // 80013818: cmpwi   r29, 0
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

label_8001381C:
    // 8001381C: bc    4, 1, 0x800138CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800138CC;
        }
    }

label_80013820:
    ctx->pc = 0x80013820u;
    ctx->downcount -= 6;
    // 80013820: lfd     f31, -20640(r22)
    if (!ppc_fp_available(ctx, 0x80013820u)) return;
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(-20640);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80013824:
    // 80013824: lis     r25, 17200
    ctx->gpr[25] = ((u32)(s32)(17200) << 16);

label_80013828:
    ctx->pc = 0x80013828u;
    // 80013828: lfd     f30, -20632(r23)
    if (!ppc_fp_available(ctx, 0x80013828u)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(-20632);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001382C:
    // 8001382C: lis     r26, -32738
    ctx->gpr[26] = ((u32)(s32)(-32738) << 16);

label_80013830:
    ctx->pc = 0x80013830u;
    // 80013830: lfs     f29, -20616(r24)
    if (!ppc_fp_available(ctx, 0x80013830u)) return;
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(-20616);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_80013834:
    // 80013834: or   r31, r29, r29
    {
        ctx->gpr[31] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013838:
    ctx->downcount -= 3;
    // 80013838: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8001383C:
    // 8001383C: ori     r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] | 0x8000u;

label_80013840:
    // 80013840: bl      0x80038F24
    {
            ctx->lr = 0x80013844u;
            ctx->pc = 0x80038F24u;
            return;
    }

label_80013844:
    ctx->downcount -= 1;
    // 80013844: bl      0x80013750
    {
            ctx->lr = 0x80013848u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013750u;
                return;
            }
            goto label_80013750;
    }

label_80013848:
    ctx->pc = 0x80013848u;
    ctx->downcount -= 16;
    // 80013848: fmr    f0, f1
    if (!ppc_fp_available(ctx, 0x80013848u)) return;
    ctx->fpr[0] = ctx->fpr[1];

label_8001384C:
    ctx->pc = 0x8001384Cu;
    // 8001384C: fabs    f0, f0
    if (!ppc_fp_available(ctx, 0x8001384Cu)) return;
    ctx->fpr[0] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[0]) & 0x7FFFFFFFFFFFFFFFull);

label_80013850:
    // 80013850: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80013854:
    ctx->pc = 0x80013854u;
    // 80013854: fmul   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x80013854u)) return;
    ppc_fmul(ctx, 0, 0, 31);

label_80013858:
    ctx->pc = 0x80013858u;
    // 80013858: lfd     f1, -20624(r26)
    if (!ppc_fp_available(ctx, 0x80013858u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(-20624);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001385C:
    ctx->pc = 0x8001385Cu;
    // 8001385C: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8001385Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_80013860:
    ctx->pc = 0x80013860u;
    // 80013860: stfd     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x80013860u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_80013864:
    ctx->pc = 0x80013864u;
    // 80013864: lwz     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80013868:
    // 80013868: rlwinm r9, r9, 0, 24, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x000000FFu;
    }

label_8001386C:
    // 8001386C: addi    r9, r9, -190
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-190);

label_80013870:
    // 80013870: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_80013874:
    ctx->pc = 0x80013874u;
    // 80013874: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80013878:
    ctx->pc = 0x80013878u;
    // 80013878: stw     r25, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8001387C:
    ctx->pc = 0x8001387Cu;
    // 8001387C: lfd     f2, 8(r1)
    if (!ppc_fp_available(ctx, 0x8001387Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80013880:
    ctx->pc = 0x80013880u;
    // 80013880: fsub   f2, f2, f30
    if (!ppc_fp_available(ctx, 0x80013880u)) return;
    ppc_fsub(ctx, 2, 2, 30);

label_80013884:
    // 80013884: bl      0x80163E90
    {
            ctx->lr = 0x80013888u;
            ctx->pc = 0x80163E90u;
            return;
    }

label_80013888:
    ctx->pc = 0x80013888u;
    ctx->downcount -= 17;
    // 80013888: fmul   f1, f1, f31
    if (!ppc_fp_available(ctx, 0x80013888u)) return;
    ppc_fmul(ctx, 1, 1, 31);

label_8001388C:
    // 8001388C: addic.  r31, r31, -1
    {
        u64 a = ctx->gpr[31];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[31] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80013890:
    ctx->pc = 0x80013890u;
    // 80013890: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x80013890u)) return;
    ppc_frsp(ctx, 1, 1);

label_80013894:
    ctx->pc = 0x80013894u;
    // 80013894: fsubs   f1, f29, f1
    if (!ppc_fp_available(ctx, 0x80013894u)) return;
    ppc_fsubs(ctx, 1, 29, 1);

label_80013898:
    ctx->pc = 0x80013898u;
    // 80013898: fmr    f0, f1
    if (!ppc_fp_available(ctx, 0x80013898u)) return;
    ctx->fpr[0] = ctx->fpr[1];

label_8001389C:
    ctx->pc = 0x8001389Cu;
    // 8001389C: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8001389Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_800138A0:
    ctx->pc = 0x800138A0u;
    // 800138A0: stfd     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x800138A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_800138A4:
    ctx->pc = 0x800138A4u;
    // 800138A4: lwz     r11, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800138A8:
    // 800138A8: rlwinm r11, r11, 0, 24, 31
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x000000FFu;
    }

label_800138AC:
    // 800138AC: rlwinm r9, r11, 8, 0, 23
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[11], 8u) & 0xFFFFFF00u;
    }

label_800138B0:
    // 800138B0: rlwinm r0, r11, 16, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 16u) & 0xFFFF0000u;
    }

label_800138B4:
    // 800138B4: oris    r9, r9, 0x1000
    ctx->gpr[9] = ctx->gpr[9] | (0x1000u << 16);

label_800138B8:
    // 800138B8: or   r0, r0, r9
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[9];
    }

label_800138BC:
    // 800138BC: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_800138C0:
    ctx->pc = 0x800138C0u;
    // 800138C0: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800138C4:
    // 800138C4: addi    r30, r30, 4
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(4);

label_800138C8:
    // 800138C8: bc    4, 2, 0x80013838
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013838u;
                return;
            }
            goto label_80013838;
        }
    }

label_800138CC:
    ctx->downcount -= 3;
    // 800138CC: or   r9, r28, r28
    {
        ctx->gpr[9] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800138D0:
    // 800138D0: cmpw    r9, r27
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800138D4:
    // 800138D4: bc    12, 0, 0x80013814
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013814u;
                return;
            }
            goto label_80013814;
        }
    }

label_800138D8:
    ctx->pc = 0x800138D8u;
    ctx->downcount -= 19;
    // 800138D8: lwz     r0, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800138DC:
    ctx->pc = 0x800138DCu;
    // 800138DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800138E0:
    ctx->pc = 0x800138E0u;
    // 800138E0: lmw     r22, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 22; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800138E4:
    ctx->pc = 0x800138E4u;
    // 800138E4: lfd     f29, 56(r1)
    if (!ppc_fp_available(ctx, 0x800138E4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800138E8:
    ctx->pc = 0x800138E8u;
    // 800138E8: lfd     f30, 64(r1)
    if (!ppc_fp_available(ctx, 0x800138E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800138EC:
    ctx->pc = 0x800138ECu;
    // 800138EC: lfd     f31, 72(r1)
    if (!ppc_fp_available(ctx, 0x800138ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800138F0:
    ctx->pc = 0x800138F0u;
    // 800138F0: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_800138F4:
    ctx->pc = 0x800138F4u;
    // 800138F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800138F8:
    ctx->pc = 0x800138F8u;
    ctx->downcount -= 9;
    // 800138F8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800138FC:
    ctx->pc = 0x800138FCu;
    // 800138FC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013900:
    ctx->pc = 0x80013900u;
    // 80013900: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013904:
    ctx->pc = 0x80013904u;
    // 80013904: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013908:
    ctx->pc = 0x80013908u;
    // 80013908: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_8001390C:
    ctx->pc = 0x8001390Cu;
    // 8001390C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013910:
    ctx->pc = 0x80013910u;
    // 80013910: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013914:
    ctx->pc = 0x80013914u;
    // 80013914: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013918:
    ctx->pc = 0x80013918u;
    // 80013918: bl      0x80198368
    {
            ctx->lr = 0x8001391Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_8001391C:
    ctx->pc = 0x8001391Cu;
    ctx->downcount -= 6;
    // 8001391C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013920:
    ctx->pc = 0x80013920u;
    // 80013920: li      r4, 10
    ctx->gpr[4] = (u32)(s32)(10);

label_80013924:
    ctx->pc = 0x80013924u;
    // 80013924: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80013928:
    ctx->pc = 0x80013928u;
    // 80013928: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8001392C:
    ctx->pc = 0x8001392Cu;
    // 8001392C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013930:
    ctx->pc = 0x80013930u;
    // 80013930: bl      0x80198368
    {
            ctx->lr = 0x80013934u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013934:
    ctx->pc = 0x80013934u;
    ctx->downcount -= 6;
    // 80013934: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013938:
    ctx->pc = 0x80013938u;
    // 80013938: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_8001393C:
    ctx->pc = 0x8001393Cu;
    // 8001393C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013940:
    ctx->pc = 0x80013940u;
    // 80013940: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80013944:
    ctx->pc = 0x80013944u;
    // 80013944: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013948:
    ctx->pc = 0x80013948u;
    // 80013948: bl      0x80198368
    {
            ctx->lr = 0x8001394Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_8001394C:
    ctx->pc = 0x8001394Cu;
    ctx->downcount -= 6;
    // 8001394C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013950:
    ctx->pc = 0x80013950u;
    // 80013950: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80013954:
    ctx->pc = 0x80013954u;
    // 80013954: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013958:
    ctx->pc = 0x80013958u;
    // 80013958: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8001395C:
    ctx->pc = 0x8001395Cu;
    // 8001395C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013960:
    ctx->pc = 0x80013960u;
    // 80013960: bl      0x80198368
    {
            ctx->lr = 0x80013964u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013964:
    ctx->pc = 0x80013964u;
    ctx->downcount -= 6;
    // 80013964: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80013968:
    ctx->pc = 0x80013968u;
    // 80013968: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_8001396C:
    ctx->pc = 0x8001396Cu;
    // 8001396C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80013970:
    ctx->pc = 0x80013970u;
    // 80013970: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013974:
    ctx->pc = 0x80013974u;
    // 80013974: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013978:
    ctx->pc = 0x80013978u;
    // 80013978: bl      0x80198368
    {
            ctx->lr = 0x8001397Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_8001397C:
    ctx->pc = 0x8001397Cu;
    ctx->downcount -= 6;
    // 8001397C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80013980:
    ctx->pc = 0x80013980u;
    // 80013980: li      r4, 10
    ctx->gpr[4] = (u32)(s32)(10);

label_80013984:
    ctx->pc = 0x80013984u;
    // 80013984: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80013988:
    ctx->pc = 0x80013988u;
    // 80013988: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8001398C:
    ctx->pc = 0x8001398Cu;
    // 8001398C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013990:
    ctx->pc = 0x80013990u;
    // 80013990: bl      0x80198368
    {
            ctx->lr = 0x80013994u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013994:
    ctx->pc = 0x80013994u;
    ctx->downcount -= 6;
    // 80013994: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80013998:
    ctx->pc = 0x80013998u;
    // 80013998: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_8001399C:
    ctx->pc = 0x8001399Cu;
    // 8001399C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800139A0:
    ctx->pc = 0x800139A0u;
    // 800139A0: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_800139A4:
    ctx->pc = 0x800139A4u;
    // 800139A4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800139A8:
    ctx->pc = 0x800139A8u;
    // 800139A8: bl      0x80198368
    {
            ctx->lr = 0x800139ACu;
            ctx->pc = 0x80198368u;
            return;
    }

label_800139AC:
    ctx->pc = 0x800139ACu;
    ctx->downcount -= 6;
    // 800139AC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800139B0:
    ctx->pc = 0x800139B0u;
    // 800139B0: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_800139B4:
    ctx->pc = 0x800139B4u;
    // 800139B4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800139B8:
    ctx->pc = 0x800139B8u;
    // 800139B8: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_800139BC:
    ctx->pc = 0x800139BCu;
    // 800139BC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800139C0:
    ctx->pc = 0x800139C0u;
    // 800139C0: bl      0x80198368
    {
            ctx->lr = 0x800139C4u;
            ctx->pc = 0x80198368u;
            return;
    }

label_800139C4:
    ctx->pc = 0x800139C4u;
    ctx->downcount -= 6;
    // 800139C4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800139C8:
    ctx->pc = 0x800139C8u;
    // 800139C8: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_800139CC:
    ctx->pc = 0x800139CCu;
    // 800139CC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800139D0:
    ctx->pc = 0x800139D0u;
    // 800139D0: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_800139D4:
    ctx->pc = 0x800139D4u;
    // 800139D4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800139D8:
    ctx->pc = 0x800139D8u;
    // 800139D8: bl      0x80198368
    {
            ctx->lr = 0x800139DCu;
            ctx->pc = 0x80198368u;
            return;
    }

label_800139DC:
    ctx->pc = 0x800139DCu;
    ctx->downcount -= 6;
    // 800139DC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800139E0:
    ctx->pc = 0x800139E0u;
    // 800139E0: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_800139E4:
    ctx->pc = 0x800139E4u;
    // 800139E4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800139E8:
    ctx->pc = 0x800139E8u;
    // 800139E8: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_800139EC:
    ctx->pc = 0x800139ECu;
    // 800139EC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800139F0:
    ctx->pc = 0x800139F0u;
    // 800139F0: bl      0x80198368
    {
            ctx->lr = 0x800139F4u;
            ctx->pc = 0x80198368u;
            return;
    }

label_800139F4:
    ctx->pc = 0x800139F4u;
    ctx->downcount -= 6;
    // 800139F4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800139F8:
    ctx->pc = 0x800139F8u;
    // 800139F8: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_800139FC:
    ctx->pc = 0x800139FCu;
    // 800139FC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013A00:
    ctx->pc = 0x80013A00u;
    // 80013A00: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013A04:
    ctx->pc = 0x80013A04u;
    // 80013A04: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013A08:
    ctx->pc = 0x80013A08u;
    // 80013A08: bl      0x80198368
    {
            ctx->lr = 0x80013A0Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013A0C:
    ctx->pc = 0x80013A0Cu;
    ctx->downcount -= 6;
    // 80013A0C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013A10:
    ctx->pc = 0x80013A10u;
    // 80013A10: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_80013A14:
    ctx->pc = 0x80013A14u;
    // 80013A14: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013A18:
    ctx->pc = 0x80013A18u;
    // 80013A18: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013A1C:
    ctx->pc = 0x80013A1Cu;
    // 80013A1C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013A20:
    ctx->pc = 0x80013A20u;
    // 80013A20: bl      0x80198368
    {
            ctx->lr = 0x80013A24u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013A24:
    ctx->pc = 0x80013A24u;
    ctx->downcount -= 6;
    // 80013A24: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013A28:
    ctx->pc = 0x80013A28u;
    // 80013A28: li      r4, 10
    ctx->gpr[4] = (u32)(s32)(10);

label_80013A2C:
    ctx->pc = 0x80013A2Cu;
    // 80013A2C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80013A30:
    ctx->pc = 0x80013A30u;
    // 80013A30: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013A34:
    ctx->pc = 0x80013A34u;
    // 80013A34: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013A38:
    ctx->pc = 0x80013A38u;
    // 80013A38: bl      0x80198368
    {
            ctx->lr = 0x80013A3Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013A3C:
    ctx->pc = 0x80013A3Cu;
    ctx->downcount -= 6;
    // 80013A3C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013A40:
    ctx->pc = 0x80013A40u;
    // 80013A40: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80013A44:
    ctx->pc = 0x80013A44u;
    // 80013A44: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013A48:
    ctx->pc = 0x80013A48u;
    // 80013A48: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80013A4C:
    ctx->pc = 0x80013A4Cu;
    // 80013A4C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013A50:
    ctx->pc = 0x80013A50u;
    // 80013A50: bl      0x80198368
    {
            ctx->lr = 0x80013A54u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013A54:
    ctx->pc = 0x80013A54u;
    ctx->downcount -= 6;
    // 80013A54: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013A58:
    ctx->pc = 0x80013A58u;
    // 80013A58: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80013A5C:
    ctx->pc = 0x80013A5Cu;
    // 80013A5C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013A60:
    ctx->pc = 0x80013A60u;
    // 80013A60: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013A64:
    ctx->pc = 0x80013A64u;
    // 80013A64: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013A68:
    ctx->pc = 0x80013A68u;
    // 80013A68: bl      0x80198368
    {
            ctx->lr = 0x80013A6Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013A6C:
    ctx->pc = 0x80013A6Cu;
    ctx->downcount -= 6;
    // 80013A6C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80013A70:
    ctx->pc = 0x80013A70u;
    // 80013A70: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_80013A74:
    ctx->pc = 0x80013A74u;
    // 80013A74: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013A78:
    ctx->pc = 0x80013A78u;
    // 80013A78: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013A7C:
    ctx->pc = 0x80013A7Cu;
    // 80013A7C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013A80:
    ctx->pc = 0x80013A80u;
    // 80013A80: bl      0x80198368
    {
            ctx->lr = 0x80013A84u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013A84:
    ctx->pc = 0x80013A84u;
    ctx->downcount -= 6;
    // 80013A84: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80013A88:
    ctx->pc = 0x80013A88u;
    // 80013A88: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80013A8C:
    ctx->pc = 0x80013A8Cu;
    // 80013A8C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013A90:
    ctx->pc = 0x80013A90u;
    // 80013A90: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80013A94:
    ctx->pc = 0x80013A94u;
    // 80013A94: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013A98:
    ctx->pc = 0x80013A98u;
    // 80013A98: bl      0x80198368
    {
            ctx->lr = 0x80013A9Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013A9C:
    ctx->pc = 0x80013A9Cu;
    ctx->downcount -= 6;
    // 80013A9C: li      r3, 4
    ctx->gpr[3] = (u32)(s32)(4);

label_80013AA0:
    ctx->pc = 0x80013AA0u;
    // 80013AA0: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80013AA4:
    ctx->pc = 0x80013AA4u;
    // 80013AA4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013AA8:
    ctx->pc = 0x80013AA8u;
    // 80013AA8: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013AAC:
    ctx->pc = 0x80013AACu;
    // 80013AAC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013AB0:
    ctx->pc = 0x80013AB0u;
    // 80013AB0: bl      0x80198368
    {
            ctx->lr = 0x80013AB4u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013AB4:
    ctx->pc = 0x80013AB4u;
    ctx->downcount -= 1;
    // 80013AB4: bl      0x8019831C
    {
            ctx->lr = 0x80013AB8u;
            ctx->pc = 0x8019831Cu;
            return;
    }

label_80013AB8:
    ctx->pc = 0x80013AB8u;
    ctx->downcount -= 3;
    // 80013AB8: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_80013ABC:
    ctx->pc = 0x80013ABCu;
    // 80013ABC: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80013AC0:
    ctx->pc = 0x80013AC0u;
    // 80013AC0: bl      0x801978AC
    {
            ctx->lr = 0x80013AC4u;
            ctx->pc = 0x801978ACu;
            return;
    }

label_80013AC4:
    ctx->pc = 0x80013AC4u;
    ctx->downcount -= 3;
    // 80013AC4: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_80013AC8:
    ctx->pc = 0x80013AC8u;
    // 80013AC8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80013ACC:
    ctx->pc = 0x80013ACCu;
    // 80013ACC: bl      0x801978AC
    {
            ctx->lr = 0x80013AD0u;
            ctx->pc = 0x801978ACu;
            return;
    }

label_80013AD0:
    ctx->pc = 0x80013AD0u;
    ctx->downcount -= 5;
    // 80013AD0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013AD4:
    ctx->pc = 0x80013AD4u;
    // 80013AD4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013AD8:
    ctx->pc = 0x80013AD8u;
    // 80013AD8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80013ADC:
    ctx->pc = 0x80013ADCu;
    // 80013ADC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013AE0:
    ctx->pc = 0x80013AE0u;
    ctx->downcount -= 7;
    // 80013AE0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013AE4:
    ctx->pc = 0x80013AE4u;
    // 80013AE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013AE8:
    ctx->pc = 0x80013AE8u;
    // 80013AE8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80013AEC:
    ctx->pc = 0x80013AECu;
    // 80013AEC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013AF0:
    ctx->pc = 0x80013AF0u;
    // 80013AF0: lwz     r31, 196(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(196);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80013AF4:
    ctx->pc = 0x80013AF4u;
    // 80013AF4: andi.   r0, r31, 0x0002
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80013AF8:
    ctx->pc = 0x80013AF8u;
    // 80013AF8: bc    12, 2, 0x80013B18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013B18;
        }
    }

label_80013AFC:
    ctx->pc = 0x80013AFCu;
    ctx->downcount -= 6;
    // 80013AFC: lbz     r7, 203(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(203);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80013B00:
    ctx->pc = 0x80013B00u;
    // 80013B00: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_80013B04:
    ctx->pc = 0x80013B04u;
    // 80013B04: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013B08:
    ctx->pc = 0x80013B08u;
    // 80013B08: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013B0C:
    ctx->pc = 0x80013B0Cu;
    // 80013B0C: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80013B10:
    ctx->pc = 0x80013B10u;
    // 80013B10: bl      0x80198368
    {
            ctx->lr = 0x80013B14u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013B14:
    ctx->pc = 0x80013B14u;
    ctx->downcount -= 1;
    // 80013B14: b       0x80013B30
    {
            goto label_80013B30;
    }

label_80013B18:
    ctx->pc = 0x80013B18u;
    ctx->downcount -= 6;
    // 80013B18: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013B1C:
    ctx->pc = 0x80013B1Cu;
    // 80013B1C: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_80013B20:
    ctx->pc = 0x80013B20u;
    // 80013B20: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013B24:
    ctx->pc = 0x80013B24u;
    // 80013B24: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013B28:
    ctx->pc = 0x80013B28u;
    // 80013B28: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013B2C:
    ctx->pc = 0x80013B2Cu;
    // 80013B2C: bl      0x80198368
    {
            ctx->lr = 0x80013B30u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013B30:
    ctx->pc = 0x80013B30u;
    ctx->downcount -= 2;
    // 80013B30: andi.   r0, r31, 0x0008
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80013B34:
    ctx->pc = 0x80013B34u;
    // 80013B34: bc    12, 2, 0x80013B54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013B54;
        }
    }

label_80013B38:
    ctx->pc = 0x80013B38u;
    ctx->downcount -= 6;
    // 80013B38: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013B3C:
    ctx->pc = 0x80013B3Cu;
    // 80013B3C: li      r4, 10
    ctx->gpr[4] = (u32)(s32)(10);

label_80013B40:
    ctx->pc = 0x80013B40u;
    // 80013B40: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80013B44:
    ctx->pc = 0x80013B44u;
    // 80013B44: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80013B48:
    ctx->pc = 0x80013B48u;
    // 80013B48: li      r7, 6
    ctx->gpr[7] = (u32)(s32)(6);

label_80013B4C:
    ctx->pc = 0x80013B4Cu;
    // 80013B4C: bl      0x80198368
    {
            ctx->lr = 0x80013B50u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013B50:
    ctx->pc = 0x80013B50u;
    ctx->downcount -= 1;
    // 80013B50: b       0x80013B6C
    {
            goto label_80013B6C;
    }

label_80013B54:
    ctx->pc = 0x80013B54u;
    ctx->downcount -= 6;
    // 80013B54: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013B58:
    ctx->pc = 0x80013B58u;
    // 80013B58: li      r4, 10
    ctx->gpr[4] = (u32)(s32)(10);

label_80013B5C:
    ctx->pc = 0x80013B5Cu;
    // 80013B5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80013B60:
    ctx->pc = 0x80013B60u;
    // 80013B60: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80013B64:
    ctx->pc = 0x80013B64u;
    // 80013B64: li      r7, 14
    ctx->gpr[7] = (u32)(s32)(14);

label_80013B68:
    ctx->pc = 0x80013B68u;
    // 80013B68: bl      0x80198368
    {
            ctx->lr = 0x80013B6Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013B6C:
    ctx->pc = 0x80013B6Cu;
    ctx->downcount -= 6;
    // 80013B6C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013B70:
    ctx->pc = 0x80013B70u;
    // 80013B70: li      r4, 11
    ctx->gpr[4] = (u32)(s32)(11);

label_80013B74:
    ctx->pc = 0x80013B74u;
    // 80013B74: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013B78:
    ctx->pc = 0x80013B78u;
    // 80013B78: li      r6, 5
    ctx->gpr[6] = (u32)(s32)(5);

label_80013B7C:
    ctx->pc = 0x80013B7Cu;
    // 80013B7C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013B80:
    ctx->pc = 0x80013B80u;
    // 80013B80: bl      0x80198368
    {
            ctx->lr = 0x80013B84u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013B84:
    ctx->pc = 0x80013B84u;
    ctx->downcount -= 2;
    // 80013B84: andi.   r0, r31, 0x0020
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0020u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80013B88:
    ctx->pc = 0x80013B88u;
    // 80013B88: bc    12, 2, 0x80013BC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013BC0;
        }
    }

label_80013B8C:
    ctx->pc = 0x80013B8Cu;
    ctx->downcount -= 6;
    // 80013B8C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013B90:
    ctx->pc = 0x80013B90u;
    // 80013B90: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80013B94:
    ctx->pc = 0x80013B94u;
    // 80013B94: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013B98:
    ctx->pc = 0x80013B98u;
    // 80013B98: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80013B9C:
    ctx->pc = 0x80013B9Cu;
    // 80013B9C: li      r7, 13
    ctx->gpr[7] = (u32)(s32)(13);

label_80013BA0:
    ctx->pc = 0x80013BA0u;
    // 80013BA0: bl      0x80198368
    {
            ctx->lr = 0x80013BA4u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013BA4:
    ctx->pc = 0x80013BA4u;
    ctx->downcount -= 6;
    // 80013BA4: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013BA8:
    ctx->pc = 0x80013BA8u;
    // 80013BA8: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_80013BAC:
    ctx->pc = 0x80013BACu;
    // 80013BAC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013BB0:
    ctx->pc = 0x80013BB0u;
    // 80013BB0: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80013BB4:
    ctx->pc = 0x80013BB4u;
    // 80013BB4: li      r7, 13
    ctx->gpr[7] = (u32)(s32)(13);

label_80013BB8:
    ctx->pc = 0x80013BB8u;
    // 80013BB8: bl      0x80198368
    {
            ctx->lr = 0x80013BBCu;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013BBC:
    ctx->pc = 0x80013BBCu;
    ctx->downcount -= 1;
    // 80013BBC: b       0x80013BF0
    {
            goto label_80013BF0;
    }

label_80013BC0:
    ctx->pc = 0x80013BC0u;
    ctx->downcount -= 6;
    // 80013BC0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013BC4:
    ctx->pc = 0x80013BC4u;
    // 80013BC4: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80013BC8:
    ctx->pc = 0x80013BC8u;
    // 80013BC8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013BCC:
    ctx->pc = 0x80013BCCu;
    // 80013BCC: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013BD0:
    ctx->pc = 0x80013BD0u;
    // 80013BD0: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013BD4:
    ctx->pc = 0x80013BD4u;
    // 80013BD4: bl      0x80198368
    {
            ctx->lr = 0x80013BD8u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013BD8:
    ctx->pc = 0x80013BD8u;
    ctx->downcount -= 6;
    // 80013BD8: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013BDC:
    ctx->pc = 0x80013BDCu;
    // 80013BDC: li      r4, 14
    ctx->gpr[4] = (u32)(s32)(14);

label_80013BE0:
    ctx->pc = 0x80013BE0u;
    // 80013BE0: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80013BE4:
    ctx->pc = 0x80013BE4u;
    // 80013BE4: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013BE8:
    ctx->pc = 0x80013BE8u;
    // 80013BE8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80013BEC:
    ctx->pc = 0x80013BECu;
    // 80013BEC: bl      0x80198368
    {
            ctx->lr = 0x80013BF0u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80013BF0:
    ctx->pc = 0x80013BF0u;
    ctx->downcount -= 7;
    // 80013BF0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80013BF4:
    ctx->pc = 0x80013BF4u;
    // 80013BF4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013BF8:
    ctx->pc = 0x80013BF8u;
    // 80013BF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013BFC:
    ctx->pc = 0x80013BFCu;
    // 80013BFC: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80013C00:
    ctx->pc = 0x80013C00u;
    // 80013C00: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80013C04:
    ctx->pc = 0x80013C04u;
    // 80013C04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013C08:
    ctx->pc = 0x80013C08u;
    ctx->downcount -= 27;
    // 80013C08: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013C0C:
    ctx->pc = 0x80013C0Cu;
    // 80013C0C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013C10:
    ctx->pc = 0x80013C10u;
    // 80013C10: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80013C14:
    ctx->pc = 0x80013C14u;
    // 80013C14: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013C18:
    ctx->pc = 0x80013C18u;
    // 80013C18: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80013C1C:
    ctx->pc = 0x80013C1Cu;
    // 80013C1C: lis     r11, -32734
    ctx->gpr[11] = ((u32)(s32)(-32734) << 16);

label_80013C20:
    ctx->pc = 0x80013C20u;
    // 80013C20: lwz     r0, 11828(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(11828);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013C24:
    ctx->pc = 0x80013C24u;
    // 80013C24: addi    r11, r11, 2380
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2380);

label_80013C28:
    ctx->pc = 0x80013C28u;
    // 80013C28: lis     r9, -32736
    ctx->gpr[9] = ((u32)(s32)(-32736) << 16);

label_80013C2C:
    ctx->pc = 0x80013C2Cu;
    // 80013C2C: lis     r27, -32736
    ctx->gpr[27] = ((u32)(s32)(-32736) << 16);

label_80013C30:
    ctx->pc = 0x80013C30u;
    // 80013C30: mulli   r0, r0, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_80013C34:
    ctx->pc = 0x80013C34u;
    // 80013C34: addi    r31, r9, 9348
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(9348);

label_80013C38:
    ctx->pc = 0x80013C38u;
    // 80013C38: addi    r28, r31, 120
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(120);

label_80013C3C:
    ctx->pc = 0x80013C3Cu;
    // 80013C3C: lis     r29, -32736
    ctx->gpr[29] = ((u32)(s32)(-32736) << 16);

label_80013C40:
    ctx->pc = 0x80013C40u;
    // 80013C40: lwzx    r30, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80013C44:
    ctx->pc = 0x80013C44u;
    ctx->downcount -= 3;
    // 80013C44: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013C48:
    // 80013C48: and.   r9, r0, r30
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80013C4C:
    // 80013C4C: bc    12, 2, 0x80013C68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013C68;
        }
    }

label_80013C50:
    ctx->pc = 0x80013C50u;
    ctx->downcount -= 3;
    // 80013C50: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80013C54:
    // 80013C54: addi    r3, r27, 9504
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(9504);

label_80013C58:
    // 80013C58: bl      0x80169A30
    {
            ctx->lr = 0x80013C5Cu;
            ctx->pc = 0x80169A30u;
            return;
    }

label_80013C5C:
    ctx->pc = 0x80013C5Cu;
    ctx->downcount -= 3;
    // 80013C5C: lwz     r4, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80013C60:
    // 80013C60: addi    r3, r29, 9536
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(9536);

label_80013C64:
    // 80013C64: bl      0x80169A30
    {
            ctx->lr = 0x80013C68u;
            ctx->pc = 0x80169A30u;
            return;
    }

label_80013C68:
    ctx->downcount -= 3;
    // 80013C68: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_80013C6C:
    // 80013C6C: cmplw   r31, r28
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013C70:
    // 80013C70: bc    4, 1, 0x80013C44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013C44u;
                return;
            }
            goto label_80013C44;
        }
    }

label_80013C74:
    ctx->pc = 0x80013C74u;
    ctx->downcount -= 16;
    // 80013C74: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013C78:
    ctx->pc = 0x80013C78u;
    // 80013C78: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013C7C:
    ctx->pc = 0x80013C7Cu;
    // 80013C7C: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80013C80:
    ctx->pc = 0x80013C80u;
    // 80013C80: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80013C84:
    ctx->pc = 0x80013C84u;
    // 80013C84: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013C88:
    ctx->pc = 0x80013C88u;
    ctx->downcount -= 16;
    // 80013C88: lhz     r11, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[11] = mem_read16(ctx, ea);
    }

label_80013C8C:
    ctx->pc = 0x80013C8Cu;
    // 80013C8C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80013C90:
    ctx->pc = 0x80013C90u;
    // 80013C90: lhz     r9, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80013C94:
    ctx->pc = 0x80013C94u;
    // 80013C94: li      r10, 64
    ctx->gpr[10] = (u32)(s32)(64);

label_80013C98:
    ctx->pc = 0x80013C98u;
    // 80013C98: lbz     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80013C9C:
    ctx->pc = 0x80013C9Cu;
    // 80013C9C: rlwinm r11, r11, 0, 16, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x0000FFFCu;
    }

label_80013CA0:
    ctx->pc = 0x80013CA0u;
    // 80013CA0: ori     r9, r9, 0x0003
    ctx->gpr[9] = ctx->gpr[9] | 0x0003u;

label_80013CA4:
    ctx->pc = 0x80013CA4u;
    // 80013CA4: ori     r11, r11, 0x0002
    ctx->gpr[11] = ctx->gpr[11] | 0x0002u;

label_80013CA8:
    ctx->pc = 0x80013CA8u;
    // 80013CA8: rlwinm r9, r9, 0, 30, 27
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFFFFF3u;
    }

label_80013CAC:
    ctx->pc = 0x80013CACu;
    // 80013CAC: rlwinm r0, r0, 0, 24, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000F8u;
    }

label_80013CB0:
    ctx->pc = 0x80013CB0u;
    // 80013CB0: stb     r0, 46(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(46);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80013CB4:
    ctx->pc = 0x80013CB4u;
    // 80013CB4: stw     r8, 56(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80013CB8:
    ctx->pc = 0x80013CB8u;
    // 80013CB8: stw     r10, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80013CBC:
    ctx->pc = 0x80013CBCu;
    // 80013CBC: sth     r11, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_80013CC0:
    ctx->pc = 0x80013CC0u;
    // 80013CC0: sth     r9, 54(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(54);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80013CC4:
    ctx->pc = 0x80013CC4u;
    // 80013CC4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013CC8:
    ctx->pc = 0x80013CC8u;
    ctx->downcount -= 18;
    // 80013CC8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013CCC:
    ctx->pc = 0x80013CCCu;
    // 80013CCC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013CD0:
    ctx->pc = 0x80013CD0u;
    // 80013CD0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80013CD4:
    ctx->pc = 0x80013CD4u;
    // 80013CD4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013CD8:
    ctx->pc = 0x80013CD8u;
    // 80013CD8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80013CDC:
    ctx->pc = 0x80013CDCu;
    // 80013CDC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80013CE0:
    ctx->pc = 0x80013CE0u;
    // 80013CE0: cmpw    r30, r4
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013CE4:
    ctx->pc = 0x80013CE4u;
    // 80013CE4: bc    4, 0, 0x80013D00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80013D00;
        }
    }

label_80013CE8:
    loop_80013CE8(ctx);
    if (ctx->pc == 0x80013D00u) goto label_80013D00;
    return;
label_80013CEC:
    // 80013CEC: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_80013CF0:
    // 80013CF0: add   r0, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80013CF4:
    // 80013CF4: cmpw    r31, r4
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013CF8:
    // 80013CF8: add   r30, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80013CFC:
    // 80013CFC: bc    12, 0, 0x80013CE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013CE8u;
                return;
            }
            goto label_80013CE8;
        }
    }

label_80013D00:
    ctx->pc = 0x80013D00u;
    ctx->downcount -= 4;
    // 80013D00: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80013D04:
    ctx->pc = 0x80013D04u;
    // 80013D04: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80013D08:
    ctx->pc = 0x80013D08u;
    // 80013D08: addi    r29, r9, -20404
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-20404);

label_80013D0C:
    ctx->pc = 0x80013D0Cu;
    // 80013D0C: b       0x80013D24
    {
            goto label_80013D24;
    }

label_80013D10:
    ctx->pc = 0x80013D10u;
    ctx->downcount -= 5;
    // 80013D10: lbzx    r0, r29, r31
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[31];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80013D14:
    // 80013D14: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_80013D18:
    // 80013D18: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80013D1C:
    // 80013D1C: add   r0, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80013D20:
    // 80013D20: add   r30, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80013D24:
    ctx->downcount -= 2;
    // 80013D24: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013D28:
    // 80013D28: bl      0x80169AB4
    {
            ctx->lr = 0x80013D2Cu;
            ctx->pc = 0x80169AB4u;
            return;
    }

label_80013D2C:
    ctx->downcount -= 2;
    // 80013D2C: cmplw   r31, r3
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013D30:
    // 80013D30: bc    12, 0, 0x80013D10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013D10u;
                return;
            }
            goto label_80013D10;
        }
    }

label_80013D34:
    ctx->pc = 0x80013D34u;
    ctx->downcount -= 4;
    // 80013D34: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80013D38:
    ctx->pc = 0x80013D38u;
    // 80013D38: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80013D3C:
    ctx->pc = 0x80013D3Cu;
    // 80013D3C: addi    r29, r9, -20392
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-20392);

label_80013D40:
    ctx->pc = 0x80013D40u;
    // 80013D40: b       0x80013D58
    {
            goto label_80013D58;
    }

label_80013D44:
    ctx->pc = 0x80013D44u;
    ctx->downcount -= 5;
    // 80013D44: lbzx    r0, r29, r31
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[31];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80013D48:
    // 80013D48: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_80013D4C:
    // 80013D4C: extsb r0, r0
    {
        ctx->gpr[0] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_80013D50:
    // 80013D50: add   r0, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80013D54:
    // 80013D54: add   r30, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80013D58:
    ctx->downcount -= 2;
    // 80013D58: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013D5C:
    // 80013D5C: bl      0x80169AB4
    {
            ctx->lr = 0x80013D60u;
            ctx->pc = 0x80169AB4u;
            return;
    }

label_80013D60:
    ctx->downcount -= 2;
    // 80013D60: cmplw   r31, r3
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013D64:
    // 80013D64: bc    12, 0, 0x80013D44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013D44u;
                return;
            }
            goto label_80013D44;
        }
    }

label_80013D68:
    ctx->pc = 0x80013D68u;
    ctx->downcount -= 25;
    // 80013D68: lwz     r3, -27916(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27916);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80013D6C:
    ctx->pc = 0x80013D6Cu;
    // 80013D6C: addi    r9, r30, 7
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(7);

label_80013D70:
    ctx->pc = 0x80013D70u;
    // 80013D70: lwz     r0, -27908(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27908);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013D74:
    ctx->pc = 0x80013D74u;
    // 80013D74: mullw   r3, r3, r0
    {
        s64 product = (s64)(s32)ctx->gpr[3] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[3] = (u32)product;
    }

label_80013D78:
    ctx->pc = 0x80013D78u;
    // 80013D78: add   r3, r9, r3
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80013D7C:
    ctx->pc = 0x80013D7Cu;
    // 80013D7C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013D80:
    ctx->pc = 0x80013D80u;
    // 80013D80: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013D84:
    ctx->pc = 0x80013D84u;
    // 80013D84: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80013D88:
    ctx->pc = 0x80013D88u;
    // 80013D88: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80013D8C:
    ctx->pc = 0x80013D8Cu;
    // 80013D8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013D90:
    ctx->pc = 0x80013D90u;
    ctx->downcount -= 19;
    // 80013D90: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013D94:
    ctx->pc = 0x80013D94u;
    // 80013D94: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013D98:
    ctx->pc = 0x80013D98u;
    // 80013D98: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80013D9C:
    ctx->pc = 0x80013D9Cu;
    // 80013D9C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013DA0:
    ctx->pc = 0x80013DA0u;
    // 80013DA0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80013DA4:
    ctx->pc = 0x80013DA4u;
    // 80013DA4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80013DA8:
    ctx->pc = 0x80013DA8u;
    // 80013DA8: lwz     r29, 2116(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(2116);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80013DAC:
    ctx->pc = 0x80013DACu;
    // 80013DAC: stw     r0, 2116(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(2116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013DB0:
    ctx->pc = 0x80013DB0u;
    // 80013DB0: bl      0x80013CC8
    {
            ctx->lr = 0x80013DB4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013CC8u;
                return;
            }
            goto label_80013CC8;
    }

label_80013DB4:
    ctx->pc = 0x80013DB4u;
    ctx->downcount -= 4;
    // 80013DB4: cmpw    r29, r3
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013DB8:
    ctx->pc = 0x80013DB8u;
    // 80013DB8: stw     r29, 2116(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(2116);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80013DBC:
    ctx->pc = 0x80013DBCu;
    // 80013DBC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80013DC0:
    ctx->pc = 0x80013DC0u;
    // 80013DC0: bc    12, 2, 0x80013DC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013DC8;
        }
    }

label_80013DC4:
    ctx->pc = 0x80013DC4u;
    ctx->downcount -= 1;
    // 80013DC4: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_80013DC8:
    ctx->pc = 0x80013DC8u;
    ctx->downcount -= 16;
    // 80013DC8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013DCC:
    ctx->pc = 0x80013DCCu;
    // 80013DCC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013DD0:
    ctx->pc = 0x80013DD0u;
    // 80013DD0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80013DD4:
    ctx->pc = 0x80013DD4u;
    // 80013DD4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80013DD8:
    ctx->pc = 0x80013DD8u;
    // 80013DD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013DDC:
    ctx->pc = 0x80013DDCu;
    ctx->downcount -= 25;
    // 80013DDC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013DE0:
    ctx->pc = 0x80013DE0u;
    // 80013DE0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013DE4:
    ctx->pc = 0x80013DE4u;
    // 80013DE4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80013DE8:
    ctx->pc = 0x80013DE8u;
    // 80013DE8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013DEC:
    ctx->pc = 0x80013DECu;
    // 80013DEC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80013DF0:
    ctx->pc = 0x80013DF0u;
    // 80013DF0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_80013DF4:
    ctx->pc = 0x80013DF4u;
    // 80013DF4: lwz     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80013DF8:
    ctx->pc = 0x80013DF8u;
    // 80013DF8: addi    r4, r4, -20380
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-20380);

label_80013DFC:
    ctx->pc = 0x80013DFCu;
    // 80013DFC: lwz     r7, -27928(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27928);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80013E00:
    ctx->pc = 0x80013E00u;
    // 80013E00: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_80013E04:
    ctx->pc = 0x80013E04u;
    // 80013E04: addi    r30, r9, 10311
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(10311);

label_80013E08:
    ctx->pc = 0x80013E08u;
    // 80013E08: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80013E0C:
    ctx->pc = 0x80013E0Cu;
    // 80013E0C: rlwinm r30, r30, 0, 0, 18
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0xFFFFE000u;
    }

label_80013E10:
    ctx->pc = 0x80013E10u;
    // 80013E10: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80013E14:
    ctx->pc = 0x80013E14u;
    // 80013E14: bl      0x80039A00
    {
            ctx->lr = 0x80013E18u;
            ctx->pc = 0x80039A00u;
            return;
    }

label_80013E18:
    ctx->pc = 0x80013E18u;
    ctx->downcount -= 2;
    // 80013E18: or.   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80013E1C:
    ctx->pc = 0x80013E1Cu;
    // 80013E1C: bc    4, 2, 0x80013E3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80013E3C;
        }
    }

label_80013E20:
    ctx->pc = 0x80013E20u;
    ctx->downcount -= 2;
    // 80013E20: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013E24:
    ctx->pc = 0x80013E24u;
    // 80013E24: bl      0x8018FA60
    {
            ctx->lr = 0x80013E28u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80013E28:
    ctx->pc = 0x80013E28u;
    ctx->downcount -= 5;
    // 80013E28: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013E2C:
    ctx->pc = 0x80013E2Cu;
    // 80013E2C: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013E30:
    ctx->pc = 0x80013E30u;
    // 80013E30: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80013E34:
    ctx->pc = 0x80013E34u;
    // 80013E34: li      r3, -96
    ctx->gpr[3] = (u32)(s32)(-96);

label_80013E38:
    ctx->pc = 0x80013E38u;
    // 80013E38: b       0x80013EF0
    {
            goto label_80013EF0;
    }

label_80013E3C:
    ctx->pc = 0x80013E3Cu;
    ctx->downcount -= 6;
    // 80013E3C: addis   r3, r31, 5
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(5) << 16);

label_80013E40:
    ctx->pc = 0x80013E40u;
    // 80013E40: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013E44:
    ctx->pc = 0x80013E44u;
    // 80013E44: addi    r3, r3, 32
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(32);

label_80013E48:
    ctx->pc = 0x80013E48u;
    // 80013E48: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80013E4C:
    ctx->pc = 0x80013E4Cu;
    // 80013E4C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80013E50:
    ctx->pc = 0x80013E50u;
    // 80013E50: bl      0x80191108
    {
            ctx->lr = 0x80013E54u;
            ctx->pc = 0x80191108u;
            return;
    }

label_80013E54:
    ctx->pc = 0x80013E54u;
    ctx->downcount -= 3;
    // 80013E54: cmpwi   r3, 0
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

label_80013E58:
    ctx->pc = 0x80013E58u;
    // 80013E58: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013E5C:
    ctx->pc = 0x80013E5Cu;
    // 80013E5C: bc    4, 0, 0x80013E84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80013E84;
        }
    }

label_80013E60:
    ctx->pc = 0x80013E60u;
    ctx->downcount -= 2;
    // 80013E60: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013E64:
    ctx->pc = 0x80013E64u;
    // 80013E64: bl      0x80039A44
    {
            ctx->lr = 0x80013E68u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_80013E68:
    ctx->pc = 0x80013E68u;
    ctx->downcount -= 2;
    // 80013E68: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013E6C:
    ctx->pc = 0x80013E6Cu;
    // 80013E6C: bl      0x8018FA60
    {
            ctx->lr = 0x80013E70u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80013E70:
    ctx->pc = 0x80013E70u;
    ctx->downcount -= 5;
    // 80013E70: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013E74:
    ctx->pc = 0x80013E74u;
    // 80013E74: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013E78:
    ctx->pc = 0x80013E78u;
    // 80013E78: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80013E7C:
    ctx->pc = 0x80013E7Cu;
    // 80013E7C: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80013E80:
    ctx->pc = 0x80013E80u;
    // 80013E80: b       0x80013EF0
    {
            goto label_80013EF0;
    }

label_80013E84:
    ctx->pc = 0x80013E84u;
    ctx->downcount -= 3;
    // 80013E84: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80013E88:
    ctx->pc = 0x80013E88u;
    // 80013E88: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013E8C:
    ctx->pc = 0x80013E8Cu;
    // 80013E8C: bl      0x80013D90
    {
            ctx->lr = 0x80013E90u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013D90u;
                return;
            }
            goto label_80013D90;
    }

label_80013E90:
    ctx->pc = 0x80013E90u;
    ctx->downcount -= 2;
    // 80013E90: cmpwi   r3, 0
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

label_80013E94:
    ctx->pc = 0x80013E94u;
    // 80013E94: bc    12, 0, 0x80013ED0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013ED0;
        }
    }

label_80013E98:
    ctx->pc = 0x80013E98u;
    ctx->downcount -= 5;
    // 80013E98: lwz     r5, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80013E9C:
    ctx->pc = 0x80013E9Cu;
    // 80013E9C: addi    r4, r29, 2120
    ctx->gpr[4] = ctx->gpr[29] + (u32)(s32)(2120);

label_80013EA0:
    ctx->pc = 0x80013EA0u;
    // 80013EA0: lwz     r3, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80013EA4:
    ctx->pc = 0x80013EA4u;
    // 80013EA4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80013EA8:
    ctx->pc = 0x80013EA8u;
    // 80013EA8: bl      0x8016984C
    {
            ctx->lr = 0x80013EACu;
            ctx->pc = 0x8016984Cu;
            return;
    }

label_80013EAC:
    ctx->pc = 0x80013EACu;
    ctx->downcount -= 2;
    // 80013EAC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013EB0:
    ctx->pc = 0x80013EB0u;
    // 80013EB0: bl      0x80039A44
    {
            ctx->lr = 0x80013EB4u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_80013EB4:
    ctx->pc = 0x80013EB4u;
    ctx->downcount -= 2;
    // 80013EB4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013EB8:
    ctx->pc = 0x80013EB8u;
    // 80013EB8: bl      0x8018FA60
    {
            ctx->lr = 0x80013EBCu;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80013EBC:
    ctx->pc = 0x80013EBCu;
    ctx->downcount -= 5;
    // 80013EBC: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013EC0:
    ctx->pc = 0x80013EC0u;
    // 80013EC0: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013EC4:
    ctx->pc = 0x80013EC4u;
    // 80013EC4: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80013EC8:
    ctx->pc = 0x80013EC8u;
    // 80013EC8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80013ECC:
    ctx->pc = 0x80013ECCu;
    // 80013ECC: b       0x80013EF0
    {
            goto label_80013EF0;
    }

label_80013ED0:
    ctx->pc = 0x80013ED0u;
    ctx->downcount -= 2;
    // 80013ED0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80013ED4:
    ctx->pc = 0x80013ED4u;
    // 80013ED4: bl      0x80039A44
    {
            ctx->lr = 0x80013ED8u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_80013ED8:
    ctx->pc = 0x80013ED8u;
    ctx->downcount -= 2;
    // 80013ED8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013EDC:
    ctx->pc = 0x80013EDCu;
    // 80013EDC: bl      0x8018FA60
    {
            ctx->lr = 0x80013EE0u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80013EE0:
    ctx->pc = 0x80013EE0u;
    ctx->downcount -= 4;
    // 80013EE0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013EE4:
    ctx->pc = 0x80013EE4u;
    // 80013EE4: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013EE8:
    ctx->pc = 0x80013EE8u;
    // 80013EE8: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80013EEC:
    ctx->pc = 0x80013EECu;
    // 80013EEC: li      r3, -91
    ctx->gpr[3] = (u32)(s32)(-91);

label_80013EF0:
    ctx->pc = 0x80013EF0u;
    ctx->downcount -= 17;
    // 80013EF0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013EF4:
    ctx->pc = 0x80013EF4u;
    // 80013EF4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013EF8:
    ctx->pc = 0x80013EF8u;
    // 80013EF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013EFC:
    ctx->pc = 0x80013EFCu;
    // 80013EFC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80013F00:
    ctx->pc = 0x80013F00u;
    // 80013F00: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80013F04:
    ctx->pc = 0x80013F04u;
    // 80013F04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013F08:
    ctx->pc = 0x80013F08u;
    ctx->downcount -= 20;
    // 80013F08: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013F0C:
    ctx->pc = 0x80013F0Cu;
    // 80013F0C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013F10:
    ctx->pc = 0x80013F10u;
    // 80013F10: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80013F14:
    ctx->pc = 0x80013F14u;
    // 80013F14: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013F18:
    ctx->pc = 0x80013F18u;
    // 80013F18: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80013F1C:
    ctx->pc = 0x80013F1Cu;
    // 80013F1C: addis   r9, r30, 5
    ctx->gpr[9] = ctx->gpr[30] + ((u32)(s32)(5) << 16);

label_80013F20:
    ctx->pc = 0x80013F20u;
    // 80013F20: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80013F24:
    ctx->pc = 0x80013F24u;
    // 80013F24: lwz     r31, 36(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80013F28:
    ctx->pc = 0x80013F28u;
    // 80013F28: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013F2C:
    ctx->pc = 0x80013F2Cu;
    // 80013F2C: bc    12, 0, 0x80013F8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013F8C;
        }
    }

label_80013F30:
    ctx->pc = 0x80013F30u;
    ctx->downcount -= 5;
    // 80013F30: lis     r29, -32708
    ctx->gpr[29] = ((u32)(s32)(-32708) << 16);

label_80013F34:
    ctx->pc = 0x80013F34u;
    // 80013F34: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013F38:
    ctx->pc = 0x80013F38u;
    // 80013F38: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80013F3C:
    ctx->pc = 0x80013F3Cu;
    // 80013F3C: addi    r5, r29, -27712
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(-27712);

label_80013F40:
    ctx->pc = 0x80013F40u;
    // 80013F40: bl      0x80191AC0
    {
            ctx->lr = 0x80013F44u;
            ctx->pc = 0x80191AC0u;
            return;
    }

label_80013F44:
    ctx->pc = 0x80013F44u;
    ctx->downcount -= 3;
    // 80013F44: cmpwi   r3, 0
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

label_80013F48:
    ctx->pc = 0x80013F48u;
    // 80013F48: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013F4C:
    ctx->pc = 0x80013F4Cu;
    // 80013F4C: bc    12, 0, 0x80013F78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013F78;
        }
    }

label_80013F50:
    ctx->pc = 0x80013F50u;
    ctx->downcount -= 2;
    // 80013F50: addi    r3, r29, -27712
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-27712);

label_80013F54:
    ctx->pc = 0x80013F54u;
    // 80013F54: bl      0x80013C88
    {
            ctx->lr = 0x80013F58u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013C88u;
                return;
            }
            goto label_80013C88;
    }

label_80013F58:
    ctx->pc = 0x80013F58u;
    ctx->downcount -= 3;
    // 80013F58: addi    r3, r29, -27712
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-27712);

label_80013F5C:
    ctx->pc = 0x80013F5Cu;
    // 80013F5C: li      r4, 108
    ctx->gpr[4] = (u32)(s32)(108);

label_80013F60:
    ctx->pc = 0x80013F60u;
    // 80013F60: bl      0x801715DC
    {
            ctx->lr = 0x80013F64u;
            ctx->pc = 0x801715DCu;
            return;
    }

label_80013F64:
    ctx->pc = 0x80013F64u;
    ctx->downcount -= 4;
    // 80013F64: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80013F68:
    ctx->pc = 0x80013F68u;
    // 80013F68: addi    r5, r29, -27712
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(-27712);

label_80013F6C:
    ctx->pc = 0x80013F6Cu;
    // 80013F6C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013F70:
    ctx->pc = 0x80013F70u;
    // 80013F70: bl      0x80191D60
    {
            ctx->lr = 0x80013F74u;
            ctx->pc = 0x80191D60u;
            return;
    }

label_80013F74:
    ctx->pc = 0x80013F74u;
    ctx->downcount -= 1;
    // 80013F74: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013F78:
    ctx->pc = 0x80013F78u;
    ctx->downcount -= 4;
    // 80013F78: lwz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013F7C:
    ctx->pc = 0x80013F7Cu;
    // 80013F7C: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80013F80:
    ctx->pc = 0x80013F80u;
    // 80013F80: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80013F84:
    ctx->pc = 0x80013F84u;
    // 80013F84: bc    12, 0, 0x80013F8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80013F8C;
        }
    }

label_80013F88:
    ctx->pc = 0x80013F88u;
    ctx->downcount -= 1;
    // 80013F88: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80013F8C:
    ctx->pc = 0x80013F8Cu;
    ctx->downcount -= 16;
    // 80013F8C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013F90:
    ctx->pc = 0x80013F90u;
    // 80013F90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80013F94:
    ctx->pc = 0x80013F94u;
    // 80013F94: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80013F98:
    ctx->pc = 0x80013F98u;
    // 80013F98: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80013F9C:
    ctx->pc = 0x80013F9Cu;
    // 80013F9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80013FA0:
    ctx->pc = 0x80013FA0u;
    ctx->downcount -= 19;
    // 80013FA0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80013FA4:
    ctx->pc = 0x80013FA4u;
    // 80013FA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80013FA8:
    ctx->pc = 0x80013FA8u;
    // 80013FA8: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80013FAC:
    ctx->pc = 0x80013FACu;
    // 80013FAC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013FB0:
    ctx->pc = 0x80013FB0u;
    // 80013FB0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80013FB4:
    ctx->pc = 0x80013FB4u;
    // 80013FB4: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80013FB8:
    ctx->pc = 0x80013FB8u;
    // 80013FB8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013FBC:
    ctx->pc = 0x80013FBCu;
    // 80013FBC: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_80013FC0:
    ctx->pc = 0x80013FC0u;
    // 80013FC0: bl      0x8018D5EC
    {
            ctx->lr = 0x80013FC4u;
            ctx->pc = 0x8018D5ECu;
            return;
    }

label_80013FC4:
    ctx->pc = 0x80013FC4u;
    ctx->downcount -= 3;
    // 80013FC4: cmpwi   r3, 0
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

label_80013FC8:
    ctx->pc = 0x80013FC8u;
    // 80013FC8: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013FCC:
    ctx->pc = 0x80013FCCu;
    // 80013FCC: bc    4, 0, 0x80013FF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80013FF0;
        }
    }

label_80013FD0:
    ctx->pc = 0x80013FD0u;
    ctx->downcount -= 2;
    // 80013FD0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80013FD4:
    ctx->pc = 0x80013FD4u;
    // 80013FD4: bl      0x8018FA60
    {
            ctx->lr = 0x80013FD8u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80013FD8:
    ctx->pc = 0x80013FD8u;
    ctx->downcount -= 6;
    // 80013FD8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013FDC:
    ctx->pc = 0x80013FDCu;
    // 80013FDC: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80013FE0:
    ctx->pc = 0x80013FE0u;
    // 80013FE0: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80013FE4:
    ctx->pc = 0x80013FE4u;
    // 80013FE4: li      r3, -86
    ctx->gpr[3] = (u32)(s32)(-86);

label_80013FE8:
    ctx->pc = 0x80013FE8u;
    // 80013FE8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80013FEC:
    ctx->pc = 0x80013FECu;
    // 80013FEC: b       0x80014088
    {
            goto label_80014088;
    }

label_80013FF0:
    ctx->pc = 0x80013FF0u;
    ctx->downcount -= 6;
    // 80013FF0: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80013FF4:
    ctx->pc = 0x80013FF4u;
    // 80013FF4: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80013FF8:
    ctx->pc = 0x80013FF8u;
    // 80013FF8: addi    r5, r9, 10311
    ctx->gpr[5] = ctx->gpr[9] + (u32)(s32)(10311);

label_80013FFC:
    ctx->pc = 0x80013FFCu;
    // 80013FFC: rlwinm r5, r5, 0, 0, 18
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFE000u;
    }

label_80014000:
    ctx->pc = 0x80014000u;
    // 80014000: cmpw    r0, r5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[5]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014004:
    ctx->pc = 0x80014004u;
    // 80014004: bc    12, 0, 0x80014014
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014014;
        }
    }

label_80014008:
    ctx->pc = 0x80014008u;
    ctx->downcount -= 3;
    // 80014008: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001400C:
    ctx->pc = 0x8001400Cu;
    // 8001400C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014010:
    ctx->pc = 0x80014010u;
    // 80014010: bc    12, 1, 0x80014034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014034;
        }
    }

label_80014014:
    ctx->pc = 0x80014014u;
    ctx->downcount -= 2;
    // 80014014: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014018:
    ctx->pc = 0x80014018u;
    // 80014018: bl      0x8018FA60
    {
            ctx->lr = 0x8001401Cu;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_8001401C:
    ctx->pc = 0x8001401Cu;
    ctx->downcount -= 6;
    // 8001401C: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014020:
    ctx->pc = 0x80014020u;
    // 80014020: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014024:
    ctx->pc = 0x80014024u;
    // 80014024: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014028:
    ctx->pc = 0x80014028u;
    // 80014028: li      r3, -99
    ctx->gpr[3] = (u32)(s32)(-99);

label_8001402C:
    ctx->pc = 0x8001402Cu;
    // 8001402C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014030:
    ctx->pc = 0x80014030u;
    // 80014030: b       0x80014088
    {
            goto label_80014088;
    }

label_80014034:
    ctx->pc = 0x80014034u;
    ctx->downcount -= 6;
    // 80014034: addis   r6, r30, 5
    ctx->gpr[6] = ctx->gpr[30] + ((u32)(s32)(5) << 16);

label_80014038:
    ctx->pc = 0x80014038u;
    // 80014038: lis     r4, -32736
    ctx->gpr[4] = ((u32)(s32)(-32736) << 16);

label_8001403C:
    ctx->pc = 0x8001403Cu;
    // 8001403C: addi    r4, r4, 9312
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(9312);

label_80014040:
    ctx->pc = 0x80014040u;
    // 80014040: addi    r6, r6, 32
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(32);

label_80014044:
    ctx->pc = 0x80014044u;
    // 80014044: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014048:
    ctx->pc = 0x80014048u;
    // 80014048: bl      0x80190C90
    {
            ctx->lr = 0x8001404Cu;
            ctx->pc = 0x80190C90u;
            return;
    }

label_8001404C:
    ctx->pc = 0x8001404Cu;
    ctx->downcount -= 5;
    // 8001404C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80014050:
    ctx->pc = 0x80014050u;
    // 80014050: stw     r31, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80014054:
    ctx->pc = 0x80014054u;
    // 80014054: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014058:
    ctx->pc = 0x80014058u;
    // 80014058: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8001405C:
    ctx->pc = 0x8001405Cu;
    // 8001405C: bc    4, 0, 0x80014088
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014088;
        }
    }

label_80014060:
    ctx->pc = 0x80014060u;
    ctx->downcount -= 2;
    // 80014060: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014064:
    ctx->pc = 0x80014064u;
    // 80014064: bl      0x8018FA60
    {
            ctx->lr = 0x80014068u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014068:
    ctx->pc = 0x80014068u;
    ctx->downcount -= 7;
    // 80014068: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001406C:
    ctx->pc = 0x8001406Cu;
    // 8001406C: cmpwi   r31, -5
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(-5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014070:
    ctx->pc = 0x80014070u;
    // 80014070: stw     r31, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80014074:
    ctx->pc = 0x80014074u;
    // 80014074: li      r3, -87
    ctx->gpr[3] = (u32)(s32)(-87);

label_80014078:
    ctx->pc = 0x80014078u;
    // 80014078: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8001407C:
    ctx->pc = 0x8001407Cu;
    // 8001407C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014080:
    ctx->pc = 0x80014080u;
    // 80014080: bc    12, 2, 0x80014088
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014088;
        }
    }

label_80014084:
    ctx->pc = 0x80014084u;
    ctx->downcount -= 1;
    // 80014084: li      r3, -86
    ctx->gpr[3] = (u32)(s32)(-86);

label_80014088:
    ctx->pc = 0x80014088u;
    ctx->downcount -= 16;
    // 80014088: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001408C:
    ctx->pc = 0x8001408Cu;
    // 8001408C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014090:
    ctx->pc = 0x80014090u;
    // 80014090: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014094:
    ctx->pc = 0x80014094u;
    // 80014094: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80014098:
    ctx->pc = 0x80014098u;
    // 80014098: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_8001409C:
    ctx->pc = 0x8001409Cu;
    ctx->downcount -= 25;
    // 8001409C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800140A0:
    ctx->pc = 0x800140A0u;
    // 800140A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800140A4:
    ctx->pc = 0x800140A4u;
    // 800140A4: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800140A8:
    ctx->pc = 0x800140A8u;
    // 800140A8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800140AC:
    ctx->pc = 0x800140ACu;
    // 800140AC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800140B0:
    ctx->pc = 0x800140B0u;
    // 800140B0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_800140B4:
    ctx->pc = 0x800140B4u;
    // 800140B4: lwz     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800140B8:
    ctx->pc = 0x800140B8u;
    // 800140B8: addi    r4, r4, -20360
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-20360);

label_800140BC:
    ctx->pc = 0x800140BCu;
    // 800140BC: lwz     r7, -27928(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27928);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800140C0:
    ctx->pc = 0x800140C0u;
    // 800140C0: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_800140C4:
    ctx->pc = 0x800140C4u;
    // 800140C4: addi    r27, r9, 10311
    ctx->gpr[27] = ctx->gpr[9] + (u32)(s32)(10311);

label_800140C8:
    ctx->pc = 0x800140C8u;
    // 800140C8: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_800140CC:
    ctx->pc = 0x800140CCu;
    // 800140CC: rlwinm r27, r27, 0, 0, 18
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[27], 0u) & 0xFFFFE000u;
    }

label_800140D0:
    ctx->pc = 0x800140D0u;
    // 800140D0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800140D4:
    ctx->pc = 0x800140D4u;
    // 800140D4: bl      0x80039A00
    {
            ctx->lr = 0x800140D8u;
            ctx->pc = 0x80039A00u;
            return;
    }

label_800140D8:
    ctx->pc = 0x800140D8u;
    ctx->downcount -= 2;
    // 800140D8: or.   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800140DC:
    ctx->pc = 0x800140DCu;
    // 800140DC: bc    4, 2, 0x800140FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800140FC;
        }
    }

label_800140E0:
    ctx->pc = 0x800140E0u;
    ctx->downcount -= 2;
    // 800140E0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800140E4:
    ctx->pc = 0x800140E4u;
    // 800140E4: bl      0x8018FA60
    {
            ctx->lr = 0x800140E8u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_800140E8:
    ctx->pc = 0x800140E8u;
    ctx->downcount -= 5;
    // 800140E8: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800140EC:
    ctx->pc = 0x800140ECu;
    // 800140EC: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800140F0:
    ctx->pc = 0x800140F0u;
    // 800140F0: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_800140F4:
    ctx->pc = 0x800140F4u;
    // 800140F4: li      r3, -96
    ctx->gpr[3] = (u32)(s32)(-96);

label_800140F8:
    ctx->pc = 0x800140F8u;
    // 800140F8: b       0x8001427C
    {
            goto label_8001427C;
    }

label_800140FC:
    ctx->pc = 0x800140FCu;
    ctx->downcount -= 6;
    // 800140FC: lis     r30, -32736
    ctx->gpr[30] = ((u32)(s32)(-32736) << 16);

label_80014100:
    ctx->pc = 0x80014100u;
    // 80014100: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80014104:
    ctx->pc = 0x80014104u;
    // 80014104: addi    r30, r30, 9504
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(9504);

label_80014108:
    ctx->pc = 0x80014108u;
    // 80014108: addis   r28, r31, 5
    ctx->gpr[28] = ctx->gpr[31] + ((u32)(s32)(5) << 16);

label_8001410C:
    ctx->pc = 0x8001410Cu;
    // 8001410C: stw     r0, 2116(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(2116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014110:
    ctx->pc = 0x80014110u;
    // 80014110: bl      0x80013C08
    {
            ctx->lr = 0x80014114u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013C08u;
                return;
            }
            goto label_80013C08;
    }

label_80014114:
    ctx->pc = 0x80014114u;
    ctx->downcount -= 3;
    // 80014114: addi    r3, r29, 2120
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(2120);

label_80014118:
    ctx->pc = 0x80014118u;
    // 80014118: or   r9, r29, r29
    {
        ctx->gpr[9] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8001411C:
    ctx->pc = 0x8001411Cu;
    // 8001411C: li      r11, 2112
    ctx->gpr[11] = (u32)(s32)(2112);

label_80014120:
    loop_80014120(ctx);
    if (ctx->pc == 0x80014160u) goto label_80014160;
    return;
label_80014124:
    // 80014124: addic.  r11, r11, -24
    {
        u64 a = ctx->gpr[11];
        u64 b = (u32)(s32)(-24);
        u64 res = a + b;
        ctx->gpr[11] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014128:
    ctx->pc = 0x80014128u;
    // 80014128: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001412C:
    ctx->pc = 0x8001412Cu;
    // 8001412C: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014130:
    ctx->pc = 0x80014130u;
    // 80014130: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014134:
    ctx->pc = 0x80014134u;
    // 80014134: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014138:
    ctx->pc = 0x80014138u;
    // 80014138: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001413C:
    ctx->pc = 0x8001413Cu;
    // 8001413C: lwz     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014140:
    ctx->pc = 0x80014140u;
    // 80014140: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014144:
    ctx->pc = 0x80014144u;
    // 80014144: lwz     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014148:
    ctx->pc = 0x80014148u;
    // 80014148: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001414C:
    ctx->pc = 0x8001414Cu;
    // 8001414C: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014150:
    // 80014150: addi    r30, r30, 24
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(24);

label_80014154:
    ctx->pc = 0x80014154u;
    // 80014154: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014158:
    // 80014158: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

label_8001415C:
    // 8001415C: bc    4, 2, 0x80014120
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014120u;
                return;
            }
            goto label_80014120;
        }
    }

label_80014160:
    ctx->pc = 0x80014160u;
    ctx->downcount -= 9;
    // 80014160: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014164:
    ctx->pc = 0x80014164u;
    // 80014164: addi    r28, r28, 32
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(32);

label_80014168:
    ctx->pc = 0x80014168u;
    // 80014168: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001416C:
    ctx->pc = 0x8001416Cu;
    // 8001416C: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014170:
    ctx->pc = 0x80014170u;
    // 80014170: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014174:
    ctx->pc = 0x80014174u;
    // 80014174: lwz     r5, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80014178:
    ctx->pc = 0x80014178u;
    // 80014178: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8001417C:
    ctx->pc = 0x8001417Cu;
    // 8001417C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80014180:
    ctx->pc = 0x80014180u;
    // 80014180: bl      0x8016984C
    {
            ctx->lr = 0x80014184u;
            ctx->pc = 0x8016984Cu;
            return;
    }

label_80014184:
    ctx->pc = 0x80014184u;
    ctx->downcount -= 3;
    // 80014184: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80014188:
    ctx->pc = 0x80014188u;
    // 80014188: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8001418C:
    ctx->pc = 0x8001418Cu;
    // 8001418C: bl      0x80013CC8
    {
            ctx->lr = 0x80014190u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013CC8u;
                return;
            }
            goto label_80013CC8;
    }

label_80014190:
    ctx->pc = 0x80014190u;
    ctx->downcount -= 4;
    // 80014190: stw     r3, 2116(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(2116);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014194:
    ctx->pc = 0x80014194u;
    // 80014194: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80014198:
    ctx->pc = 0x80014198u;
    // 80014198: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8001419C:
    ctx->pc = 0x8001419Cu;
    // 8001419C: bl      0x801715DC
    {
            ctx->lr = 0x800141A0u;
            ctx->pc = 0x801715DCu;
            return;
    }

label_800141A0:
    ctx->pc = 0x800141A0u;
    ctx->downcount -= 5;
    // 800141A0: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800141A4:
    ctx->pc = 0x800141A4u;
    // 800141A4: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800141A8:
    ctx->pc = 0x800141A8u;
    // 800141A8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800141AC:
    ctx->pc = 0x800141ACu;
    // 800141AC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800141B0:
    ctx->pc = 0x800141B0u;
    // 800141B0: bl      0x80191510
    {
            ctx->lr = 0x800141B4u;
            ctx->pc = 0x80191510u;
            return;
    }

label_800141B4:
    ctx->pc = 0x800141B4u;
    ctx->downcount -= 4;
    // 800141B4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800141B8:
    ctx->pc = 0x800141B8u;
    // 800141B8: stw     r30, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800141BC:
    ctx->pc = 0x800141BCu;
    // 800141BC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800141C0:
    ctx->pc = 0x800141C0u;
    // 800141C0: bl      0x80039A44
    {
            ctx->lr = 0x800141C4u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_800141C4:
    ctx->pc = 0x800141C4u;
    ctx->downcount -= 3;
    // 800141C4: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800141C8:
    ctx->pc = 0x800141C8u;
    // 800141C8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800141CC:
    ctx->pc = 0x800141CCu;
    // 800141CC: bc    4, 0, 0x80014204
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014204;
        }
    }

label_800141D0:
    ctx->pc = 0x800141D0u;
    ctx->downcount -= 2;
    // 800141D0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800141D4:
    ctx->pc = 0x800141D4u;
    // 800141D4: bl      0x801908E4
    {
            ctx->lr = 0x800141D8u;
            ctx->pc = 0x801908E4u;
            return;
    }

label_800141D8:
    ctx->pc = 0x800141D8u;
    ctx->downcount -= 2;
    // 800141D8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800141DC:
    ctx->pc = 0x800141DCu;
    // 800141DC: bl      0x8018FA60
    {
            ctx->lr = 0x800141E0u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_800141E0:
    ctx->pc = 0x800141E0u;
    ctx->downcount -= 7;
    // 800141E0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800141E4:
    ctx->pc = 0x800141E4u;
    // 800141E4: cmpwi   r30, -5
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(-5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800141E8:
    ctx->pc = 0x800141E8u;
    // 800141E8: stw     r30, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800141EC:
    ctx->pc = 0x800141ECu;
    // 800141EC: li      r3, -87
    ctx->gpr[3] = (u32)(s32)(-87);

label_800141F0:
    ctx->pc = 0x800141F0u;
    // 800141F0: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_800141F4:
    ctx->pc = 0x800141F4u;
    // 800141F4: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800141F8:
    ctx->pc = 0x800141F8u;
    // 800141F8: bc    12, 2, 0x80014280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014280;
        }
    }

label_800141FC:
    ctx->pc = 0x800141FCu;
    ctx->downcount -= 2;
    // 800141FC: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80014200:
    ctx->pc = 0x80014200u;
    // 80014200: b       0x80014280
    {
            goto label_80014280;
    }

label_80014204:
    ctx->pc = 0x80014204u;
    ctx->downcount -= 2;
    // 80014204: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014208:
    ctx->pc = 0x80014208u;
    // 80014208: bl      0x80013F08
    {
            ctx->lr = 0x8001420Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013F08u;
                return;
            }
            goto label_80013F08;
    }

label_8001420C:
    ctx->pc = 0x8001420Cu;
    ctx->downcount -= 3;
    // 8001420C: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014210:
    ctx->pc = 0x80014210u;
    // 80014210: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014214:
    ctx->pc = 0x80014214u;
    // 80014214: bc    12, 0, 0x8001425C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001425C;
        }
    }

label_80014218:
    ctx->pc = 0x80014218u;
    ctx->downcount -= 2;
    // 80014218: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8001421C:
    ctx->pc = 0x8001421Cu;
    // 8001421C: bl      0x801908E4
    {
            ctx->lr = 0x80014220u;
            ctx->pc = 0x801908E4u;
            return;
    }

label_80014220:
    ctx->pc = 0x80014220u;
    ctx->downcount -= 4;
    // 80014220: cmpwi   r3, 0
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

label_80014224:
    ctx->pc = 0x80014224u;
    // 80014224: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014228:
    ctx->pc = 0x80014228u;
    // 80014228: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_8001422C:
    ctx->pc = 0x8001422Cu;
    // 8001422C: bc    12, 0, 0x80014280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014280;
        }
    }

label_80014230:
    ctx->pc = 0x80014230u;
    ctx->downcount -= 2;
    // 80014230: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014234:
    ctx->pc = 0x80014234u;
    // 80014234: bl      0x8018FA60
    {
            ctx->lr = 0x80014238u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014238:
    ctx->pc = 0x80014238u;
    ctx->downcount -= 7;
    // 80014238: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001423C:
    ctx->pc = 0x8001423Cu;
    // 8001423C: cmpwi   r3, 0
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

label_80014240:
    ctx->pc = 0x80014240u;
    // 80014240: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014244:
    ctx->pc = 0x80014244u;
    // 80014244: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014248:
    ctx->pc = 0x80014248u;
    // 80014248: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_8001424C:
    ctx->pc = 0x8001424Cu;
    // 8001424C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014250:
    ctx->pc = 0x80014250u;
    // 80014250: bc    12, 0, 0x80014280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014280;
        }
    }

label_80014254:
    ctx->pc = 0x80014254u;
    ctx->downcount -= 2;
    // 80014254: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014258:
    ctx->pc = 0x80014258u;
    // 80014258: b       0x80014280
    {
            goto label_80014280;
    }

label_8001425C:
    ctx->pc = 0x8001425Cu;
    ctx->downcount -= 2;
    // 8001425C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80014260:
    ctx->pc = 0x80014260u;
    // 80014260: bl      0x801908E4
    {
            ctx->lr = 0x80014264u;
            ctx->pc = 0x801908E4u;
            return;
    }

label_80014264:
    ctx->pc = 0x80014264u;
    ctx->downcount -= 2;
    // 80014264: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014268:
    ctx->pc = 0x80014268u;
    // 80014268: bl      0x8018FA60
    {
            ctx->lr = 0x8001426Cu;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_8001426C:
    ctx->pc = 0x8001426Cu;
    ctx->downcount -= 4;
    // 8001426C: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014270:
    ctx->pc = 0x80014270u;
    // 80014270: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014274:
    ctx->pc = 0x80014274u;
    // 80014274: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014278:
    ctx->pc = 0x80014278u;
    // 80014278: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_8001427C:
    ctx->pc = 0x8001427Cu;
    ctx->downcount -= 1;
    // 8001427C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014280:
    ctx->pc = 0x80014280u;
    ctx->downcount -= 16;
    // 80014280: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014284:
    ctx->pc = 0x80014284u;
    // 80014284: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014288:
    ctx->pc = 0x80014288u;
    // 80014288: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8001428C:
    ctx->pc = 0x8001428Cu;
    // 8001428C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80014290:
    ctx->pc = 0x80014290u;
    // 80014290: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014294:
    ctx->pc = 0x80014294u;
    ctx->downcount -= 20;
    // 80014294: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014298:
    ctx->pc = 0x80014298u;
    // 80014298: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001429C:
    ctx->pc = 0x8001429Cu;
    // 8001429C: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800142A0:
    ctx->pc = 0x800142A0u;
    // 800142A0: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800142A4:
    ctx->pc = 0x800142A4u;
    // 800142A4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800142A8:
    ctx->pc = 0x800142A8u;
    // 800142A8: addi    r30, r1, 8
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(8);

label_800142AC:
    ctx->pc = 0x800142ACu;
    // 800142AC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800142B0:
    ctx->pc = 0x800142B0u;
    // 800142B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800142B4:
    ctx->pc = 0x800142B4u;
    // 800142B4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800142B8:
    ctx->pc = 0x800142B8u;
    // 800142B8: bl      0x80191DC0
    {
            ctx->lr = 0x800142BCu;
            ctx->pc = 0x80191DC0u;
            return;
    }

label_800142BC:
    ctx->pc = 0x800142BCu;
    ctx->downcount -= 3;
    // 800142BC: cmpwi   r3, 0
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

label_800142C0:
    ctx->pc = 0x800142C0u;
    // 800142C0: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800142C4:
    ctx->pc = 0x800142C4u;
    // 800142C4: bc    4, 0, 0x800142D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800142D0;
        }
    }

label_800142C8:
    ctx->pc = 0x800142C8u;
    ctx->downcount -= 2;
    // 800142C8: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_800142CC:
    ctx->pc = 0x800142CCu;
    // 800142CC: b       0x80014354
    {
            goto label_80014354;
    }

label_800142D0:
    ctx->pc = 0x800142D0u;
    ctx->downcount -= 2;
    // 800142D0: cmpwi   r29, 0
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

label_800142D4:
    ctx->pc = 0x800142D4u;
    // 800142D4: bc    12, 2, 0x800142F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800142F8;
        }
    }

label_800142D8:
    ctx->pc = 0x800142D8u;
    ctx->downcount -= 3;
    // 800142D8: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800142DC:
    ctx->pc = 0x800142DCu;
    // 800142DC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800142E0:
    ctx->pc = 0x800142E0u;
    // 800142E0: bc    4, 2, 0x80014328
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014328;
        }
    }

label_800142E4:
    ctx->pc = 0x800142E4u;
    ctx->downcount -= 4;
    // 800142E4: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800142E8:
    ctx->pc = 0x800142E8u;
    // 800142E8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800142EC:
    ctx->pc = 0x800142ECu;
    // 800142EC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800142F0:
    ctx->pc = 0x800142F0u;
    // 800142F0: bc    12, 2, 0x80014354
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014354;
        }
    }

label_800142F4:
    ctx->pc = 0x800142F4u;
    ctx->downcount -= 1;
    // 800142F4: b       0x80014328
    {
            goto label_80014328;
    }

label_800142F8:
    ctx->pc = 0x800142F8u;
    ctx->downcount -= 3;
    // 800142F8: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800142FC:
    ctx->pc = 0x800142FCu;
    // 800142FC: andis.  r9, r0, 0x2000
    {
        ctx->gpr[9] = ctx->gpr[0] & (0x2000u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014300:
    ctx->pc = 0x80014300u;
    // 80014300: bc    12, 2, 0x80014330
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014330;
        }
    }

label_80014304:
    ctx->pc = 0x80014304u;
    ctx->downcount -= 5;
    // 80014304: addis   r3, r31, 5
    ctx->gpr[3] = ctx->gpr[31] + ((u32)(s32)(5) << 16);

label_80014308:
    ctx->pc = 0x80014308u;
    // 80014308: lwz     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8001430C:
    ctx->pc = 0x8001430Cu;
    // 8001430C: lwz     r0, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014310:
    ctx->pc = 0x80014310u;
    // 80014310: cmpw    r9, r0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014314:
    ctx->pc = 0x80014314u;
    // 80014314: bc    4, 2, 0x80014328
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014328;
        }
    }

label_80014318:
    ctx->pc = 0x80014318u;
    ctx->downcount -= 4;
    // 80014318: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8001431C:
    ctx->pc = 0x8001431Cu;
    // 8001431C: lwz     r0, 56(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014320:
    ctx->pc = 0x80014320u;
    // 80014320: cmpw    r9, r0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014324:
    ctx->pc = 0x80014324u;
    // 80014324: bc    12, 2, 0x80014350
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014350;
        }
    }

label_80014328:
    ctx->pc = 0x80014328u;
    ctx->downcount -= 2;
    // 80014328: li      r3, -94
    ctx->gpr[3] = (u32)(s32)(-94);

label_8001432C:
    ctx->pc = 0x8001432Cu;
    // 8001432C: b       0x80014354
    {
            goto label_80014354;
    }

label_80014330:
    ctx->pc = 0x80014330u;
    ctx->downcount -= 8;
    // 80014330: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014334:
    ctx->pc = 0x80014334u;
    // 80014334: addis   r9, r31, 5
    ctx->gpr[9] = ctx->gpr[31] + ((u32)(s32)(5) << 16);

label_80014338:
    ctx->pc = 0x80014338u;
    // 80014338: lwz     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8001433C:
    ctx->pc = 0x8001433Cu;
    // 8001433C: stw     r0, 56(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014340:
    ctx->pc = 0x80014340u;
    // 80014340: stw     r11, 52(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80014344:
    ctx->pc = 0x80014344u;
    // 80014344: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014348:
    ctx->pc = 0x80014348u;
    // 80014348: oris    r0, r0, 0x2000
    ctx->gpr[0] = ctx->gpr[0] | (0x2000u << 16);

label_8001434C:
    ctx->pc = 0x8001434Cu;
    // 8001434C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014350:
    ctx->pc = 0x80014350u;
    ctx->downcount -= 1;
    // 80014350: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014354:
    ctx->pc = 0x80014354u;
    ctx->downcount -= 16;
    // 80014354: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014358:
    ctx->pc = 0x80014358u;
    // 80014358: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8001435C:
    ctx->pc = 0x8001435Cu;
    // 8001435C: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014360:
    ctx->pc = 0x80014360u;
    // 80014360: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80014364:
    ctx->pc = 0x80014364u;
    // 80014364: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014368:
    ctx->pc = 0x80014368u;
    ctx->downcount -= 18;
    // 80014368: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8001436C:
    ctx->pc = 0x8001436Cu;
    // 8001436C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014370:
    ctx->pc = 0x80014370u;
    // 80014370: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014374:
    ctx->pc = 0x80014374u;
    // 80014374: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014378:
    ctx->pc = 0x80014378u;
    // 80014378: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8001437C:
    ctx->pc = 0x8001437Cu;
    // 8001437C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014380:
    ctx->pc = 0x80014380u;
    // 80014380: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014384:
    ctx->pc = 0x80014384u;
    // 80014384: bl      0x80014584
    {
            ctx->lr = 0x80014388u;
            goto label_80014584;
    }

label_80014388:
    ctx->pc = 0x80014388u;
    ctx->downcount -= 3;
    // 80014388: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8001438C:
    ctx->pc = 0x8001438Cu;
    // 8001438C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014390:
    ctx->pc = 0x80014390u;
    // 80014390: bc    12, 0, 0x80014450
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014450;
        }
    }

label_80014394:
    ctx->pc = 0x80014394u;
    ctx->downcount -= 3;
    // 80014394: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014398:
    ctx->pc = 0x80014398u;
    // 80014398: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8001439C:
    ctx->pc = 0x8001439Cu;
    // 8001439C: bl      0x80014294
    {
            ctx->lr = 0x800143A0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_800143A0:
    ctx->pc = 0x800143A0u;
    ctx->downcount -= 2;
    // 800143A0: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800143A4:
    ctx->pc = 0x800143A4u;
    // 800143A4: bc    4, 0, 0x800143C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800143C8;
        }
    }

label_800143A8:
    ctx->pc = 0x800143A8u;
    ctx->downcount -= 2;
    // 800143A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800143AC:
    ctx->pc = 0x800143ACu;
    // 800143AC: bl      0x8018FA60
    {
            ctx->lr = 0x800143B0u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_800143B0:
    ctx->pc = 0x800143B0u;
    ctx->downcount -= 6;
    // 800143B0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800143B4:
    ctx->pc = 0x800143B4u;
    // 800143B4: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800143B8:
    ctx->pc = 0x800143B8u;
    // 800143B8: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_800143BC:
    ctx->pc = 0x800143BCu;
    // 800143BC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800143C0:
    ctx->pc = 0x800143C0u;
    // 800143C0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800143C4:
    ctx->pc = 0x800143C4u;
    // 800143C4: b       0x80014450
    {
            goto label_80014450;
    }

label_800143C8:
    ctx->pc = 0x800143C8u;
    ctx->downcount -= 4;
    // 800143C8: lis     r4, -32736
    ctx->gpr[4] = ((u32)(s32)(-32736) << 16);

label_800143CC:
    ctx->pc = 0x800143CCu;
    // 800143CC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800143D0:
    ctx->pc = 0x800143D0u;
    // 800143D0: addi    r4, r4, 9312
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(9312);

label_800143D4:
    ctx->pc = 0x800143D4u;
    // 800143D4: bl      0x80191880
    {
            ctx->lr = 0x800143D8u;
            ctx->pc = 0x80191880u;
            return;
    }

label_800143D8:
    ctx->pc = 0x800143D8u;
    ctx->downcount -= 3;
    // 800143D8: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800143DC:
    ctx->pc = 0x800143DCu;
    // 800143DC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800143E0:
    ctx->pc = 0x800143E0u;
    // 800143E0: bl      0x8018FA60
    {
            ctx->lr = 0x800143E4u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_800143E4:
    ctx->pc = 0x800143E4u;
    ctx->downcount -= 6;
    // 800143E4: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800143E8:
    ctx->pc = 0x800143E8u;
    // 800143E8: cmpwi   r3, -3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800143EC:
    ctx->pc = 0x800143ECu;
    // 800143EC: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800143F0:
    ctx->pc = 0x800143F0u;
    // 800143F0: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_800143F4:
    ctx->pc = 0x800143F4u;
    // 800143F4: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800143F8:
    ctx->pc = 0x800143F8u;
    // 800143F8: bc    12, 1, 0x80014418
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014418;
        }
    }

label_800143FC:
    ctx->pc = 0x800143FCu;
    ctx->downcount -= 2;
    // 800143FC: cmpwi   r3, -5
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014400:
    ctx->pc = 0x80014400u;
    // 80014400: bc    4, 0, 0x8001442C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001442C;
        }
    }

label_80014404:
    ctx->pc = 0x80014404u;
    ctx->downcount -= 2;
    // 80014404: cmpwi   r3, -128
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-128);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014408:
    ctx->pc = 0x80014408u;
    // 80014408: bc    12, 2, 0x8001442C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001442C;
        }
    }

label_8001440C:
    ctx->pc = 0x8001440Cu;
    ctx->downcount -= 2;
    // 8001440C: cmpwi   r3, -10
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014410:
    ctx->pc = 0x80014410u;
    // 80014410: bc    12, 2, 0x8001442C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001442C;
        }
    }

label_80014414:
    ctx->pc = 0x80014414u;
    ctx->downcount -= 1;
    // 80014414: b       0x8001443C
    {
            goto label_8001443C;
    }

label_80014418:
    ctx->pc = 0x80014418u;
    ctx->downcount -= 2;
    // 80014418: cmpwi   r3, -1
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

label_8001441C:
    ctx->pc = 0x8001441Cu;
    // 8001441C: bc    12, 2, 0x8001442C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001442C;
        }
    }

label_80014420:
    ctx->pc = 0x80014420u;
    ctx->downcount -= 2;
    // 80014420: cmpwi   r3, 0
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

label_80014424:
    ctx->pc = 0x80014424u;
    // 80014424: bc    12, 2, 0x80014434
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014434;
        }
    }

label_80014428:
    ctx->pc = 0x80014428u;
    ctx->downcount -= 1;
    // 80014428: b       0x8001443C
    {
            goto label_8001443C;
    }

label_8001442C:
    ctx->pc = 0x8001442Cu;
    ctx->downcount -= 2;
    // 8001442C: li      r3, -94
    ctx->gpr[3] = (u32)(s32)(-94);

label_80014430:
    ctx->pc = 0x80014430u;
    // 80014430: b       0x80014450
    {
            goto label_80014450;
    }

label_80014434:
    ctx->pc = 0x80014434u;
    ctx->downcount -= 2;
    // 80014434: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014438:
    ctx->pc = 0x80014438u;
    // 80014438: b       0x80014450
    {
            goto label_80014450;
    }

label_8001443C:
    ctx->pc = 0x8001443Cu;
    ctx->downcount -= 4;
    // 8001443C: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80014440:
    ctx->pc = 0x80014440u;
    // 80014440: addi    r3, r3, -20512
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20512);

label_80014444:
    ctx->pc = 0x80014444u;
    // 80014444: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80014448:
    ctx->pc = 0x80014448u;
    // 80014448: bl      0x80166EF4
    {
            ctx->lr = 0x8001444Cu;
            ctx->pc = 0x80166EF4u;
            return;
    }

label_8001444C:
    ctx->downcount -= 1;
    // 8001444C: b       0x8001444C
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8001444Cu;
                return;
            }
            goto label_8001444C;
    }

label_80014450:
    ctx->pc = 0x80014450u;
    ctx->downcount -= 16;
    // 80014450: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014454:
    ctx->pc = 0x80014454u;
    // 80014454: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014458:
    ctx->pc = 0x80014458u;
    // 80014458: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8001445C:
    ctx->pc = 0x8001445Cu;
    // 8001445C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80014460:
    ctx->pc = 0x80014460u;
    // 80014460: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014464:
    ctx->pc = 0x80014464u;
    ctx->downcount -= 17;
    // 80014464: stwu     r1, -136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-136);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014468:
    ctx->pc = 0x80014468u;
    // 80014468: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001446C:
    ctx->pc = 0x8001446Cu;
    // 8001446C: stmw     r29, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014470:
    ctx->pc = 0x80014470u;
    // 80014470: stw     r0, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014474:
    ctx->pc = 0x80014474u;
    // 80014474: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80014478:
    ctx->pc = 0x80014478u;
    // 80014478: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8001447C:
    ctx->pc = 0x8001447Cu;
    // 8001447C: bl      0x80014294
    {
            ctx->lr = 0x80014480u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_80014480:
    ctx->pc = 0x80014480u;
    ctx->downcount -= 2;
    // 80014480: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014484:
    ctx->pc = 0x80014484u;
    // 80014484: bc    4, 0, 0x800144A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800144A4;
        }
    }

label_80014488:
    ctx->pc = 0x80014488u;
    ctx->downcount -= 2;
    // 80014488: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8001448C:
    ctx->pc = 0x8001448Cu;
    // 8001448C: bl      0x8018FA60
    {
            ctx->lr = 0x80014490u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014490:
    ctx->pc = 0x80014490u;
    ctx->downcount -= 5;
    // 80014490: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014494:
    ctx->pc = 0x80014494u;
    // 80014494: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014498:
    ctx->pc = 0x80014498u;
    // 80014498: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8001449C:
    ctx->pc = 0x8001449Cu;
    // 8001449C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800144A0:
    ctx->pc = 0x800144A0u;
    // 800144A0: b       0x8001456C
    {
            goto label_8001456C;
    }

label_800144A4:
    ctx->pc = 0x800144A4u;
    ctx->downcount -= 7;
    // 800144A4: addis   r30, r31, 5
    ctx->gpr[30] = ctx->gpr[31] + ((u32)(s32)(5) << 16);

label_800144A8:
    ctx->pc = 0x800144A8u;
    // 800144A8: lis     r4, -32736
    ctx->gpr[4] = ((u32)(s32)(-32736) << 16);

label_800144AC:
    ctx->pc = 0x800144ACu;
    // 800144AC: addi    r29, r30, 32
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(32);

label_800144B0:
    ctx->pc = 0x800144B0u;
    // 800144B0: addi    r4, r4, 9312
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(9312);

label_800144B4:
    ctx->pc = 0x800144B4u;
    // 800144B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800144B8:
    ctx->pc = 0x800144B8u;
    // 800144B8: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800144BC:
    ctx->pc = 0x800144BCu;
    // 800144BC: bl      0x8019076C
    {
            ctx->lr = 0x800144C0u;
            ctx->pc = 0x8019076Cu;
            return;
    }

label_800144C0:
    ctx->pc = 0x800144C0u;
    ctx->downcount -= 3;
    // 800144C0: cmpwi   r3, 0
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

label_800144C4:
    ctx->pc = 0x800144C4u;
    // 800144C4: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800144C8:
    ctx->pc = 0x800144C8u;
    // 800144C8: bc    4, 0, 0x800144D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800144D4;
        }
    }

label_800144CC:
    ctx->pc = 0x800144CCu;
    ctx->downcount -= 2;
    // 800144CC: li      r3, -97
    ctx->gpr[3] = (u32)(s32)(-97);

label_800144D0:
    ctx->pc = 0x800144D0u;
    // 800144D0: b       0x80014570
    {
            goto label_80014570;
    }

label_800144D4:
    ctx->pc = 0x800144D4u;
    ctx->downcount -= 4;
    // 800144D4: lwz     r4, 36(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(36);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800144D8:
    ctx->pc = 0x800144D8u;
    // 800144D8: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_800144DC:
    ctx->pc = 0x800144DCu;
    // 800144DC: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800144E0:
    ctx->pc = 0x800144E0u;
    // 800144E0: bc    12, 0, 0x80014570
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014570;
        }
    }

label_800144E4:
    ctx->pc = 0x800144E4u;
    ctx->downcount -= 3;
    // 800144E4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800144E8:
    ctx->pc = 0x800144E8u;
    // 800144E8: addi    r5, r1, 8
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(8);

label_800144EC:
    ctx->pc = 0x800144ECu;
    // 800144EC: bl      0x80191AC0
    {
            ctx->lr = 0x800144F0u;
            ctx->pc = 0x80191AC0u;
            return;
    }

label_800144F0:
    ctx->pc = 0x800144F0u;
    ctx->downcount -= 3;
    // 800144F0: cmpwi   r3, 0
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

label_800144F4:
    ctx->pc = 0x800144F4u;
    // 800144F4: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800144F8:
    ctx->pc = 0x800144F8u;
    // 800144F8: bc    4, 0, 0x80014504
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014504;
        }
    }

label_800144FC:
    ctx->pc = 0x800144FCu;
    ctx->downcount -= 2;
    // 800144FC: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80014500:
    ctx->pc = 0x80014500u;
    // 80014500: b       0x80014570
    {
            goto label_80014570;
    }

label_80014504:
    ctx->pc = 0x80014504u;
    ctx->downcount -= 1;
    // 80014504: bl      0x80183370
    {
            ctx->lr = 0x80014508u;
            ctx->pc = 0x80183370u;
            return;
    }

label_80014508:
    ctx->pc = 0x80014508u;
    ctx->downcount -= 5;
    // 80014508: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8001450C:
    ctx->pc = 0x8001450Cu;
    // 8001450C: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80014510:
    ctx->pc = 0x80014510u;
    // 80014510: addi    r3, r1, 48
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(48);

label_80014514:
    ctx->pc = 0x80014514u;
    // 80014514: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014518:
    ctx->pc = 0x80014518u;
    // 80014518: bl      0x801697BC
    {
            ctx->lr = 0x8001451Cu;
            ctx->pc = 0x801697BCu;
            return;
    }

label_8001451C:
    ctx->pc = 0x8001451Cu;
    ctx->downcount -= 2;
    // 8001451C: cmpwi   r3, 0
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

label_80014520:
    ctx->pc = 0x80014520u;
    // 80014520: bc    4, 2, 0x8001453C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001453C;
        }
    }

label_80014524:
    ctx->pc = 0x80014524u;
    ctx->downcount -= 4;
    // 80014524: addi    r4, r30, 4
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(4);

label_80014528:
    ctx->pc = 0x80014528u;
    // 80014528: addi    r3, r1, 52
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(52);

label_8001452C:
    ctx->pc = 0x8001452Cu;
    // 8001452C: li      r5, 2
    ctx->gpr[5] = (u32)(s32)(2);

label_80014530:
    ctx->pc = 0x80014530u;
    // 80014530: bl      0x801697BC
    {
            ctx->lr = 0x80014534u;
            ctx->pc = 0x801697BCu;
            return;
    }

label_80014534:
    ctx->pc = 0x80014534u;
    ctx->downcount -= 2;
    // 80014534: cmpwi   r3, 0
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

label_80014538:
    ctx->pc = 0x80014538u;
    // 80014538: bc    12, 2, 0x80014560
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014560;
        }
    }

label_8001453C:
    ctx->pc = 0x8001453Cu;
    ctx->downcount -= 2;
    // 8001453C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014540:
    ctx->pc = 0x80014540u;
    // 80014540: bl      0x801908E4
    {
            ctx->lr = 0x80014544u;
            ctx->pc = 0x801908E4u;
            return;
    }

label_80014544:
    ctx->pc = 0x80014544u;
    ctx->downcount -= 2;
    // 80014544: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014548:
    ctx->pc = 0x80014548u;
    // 80014548: bl      0x8018FA60
    {
            ctx->lr = 0x8001454Cu;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_8001454C:
    ctx->pc = 0x8001454Cu;
    ctx->downcount -= 5;
    // 8001454C: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014550:
    ctx->pc = 0x80014550u;
    // 80014550: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014554:
    ctx->pc = 0x80014554u;
    // 80014554: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014558:
    ctx->pc = 0x80014558u;
    // 80014558: li      r3, -94
    ctx->gpr[3] = (u32)(s32)(-94);

label_8001455C:
    ctx->pc = 0x8001455Cu;
    // 8001455C: b       0x8001456C
    {
            goto label_8001456C;
    }

label_80014560:
    ctx->pc = 0x80014560u;
    ctx->downcount -= 3;
    // 80014560: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014564:
    ctx->pc = 0x80014564u;
    // 80014564: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014568:
    ctx->pc = 0x80014568u;
    // 80014568: oris    r0, r0, 0x4000
    ctx->gpr[0] = ctx->gpr[0] | (0x4000u << 16);

label_8001456C:
    ctx->pc = 0x8001456Cu;
    ctx->downcount -= 1;
    // 8001456C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014570:
    ctx->pc = 0x80014570u;
    ctx->downcount -= 16;
    // 80014570: lwz     r0, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014574:
    ctx->pc = 0x80014574u;
    // 80014574: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014578:
    ctx->pc = 0x80014578u;
    // 80014578: lmw     r29, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8001457C:
    ctx->pc = 0x8001457Cu;
    // 8001457C: addi    r1, r1, 136
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(136);

label_80014580:
    ctx->pc = 0x80014580u;
    // 80014580: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014584:
    ctx->pc = 0x80014584u;
    ctx->downcount -= 19;
    // 80014584: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014588:
    ctx->pc = 0x80014588u;
    // 80014588: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001458C:
    ctx->pc = 0x8001458Cu;
    // 8001458C: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_80014590:
    ctx->pc = 0x80014590u;
    // 80014590: stmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014594:
    ctx->pc = 0x80014594u;
    // 80014594: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014598:
    ctx->pc = 0x80014598u;
    // 80014598: stw     r12, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8001459C:
    ctx->pc = 0x8001459Cu;
    // 8001459C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800145A0:
    ctx->pc = 0x800145A0u;
    // 800145A0: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800145A4:
    ctx->pc = 0x800145A4u;
    // 800145A4: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_800145A8:
    ctx->downcount -= 4;
    // 800145A8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800145AC:
    // 800145AC: addi    r4, r31, 20
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(20);

label_800145B0:
    // 800145B0: addi    r5, r31, 24
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(24);

label_800145B4:
    // 800145B4: bl      0x8018F094
    {
            ctx->lr = 0x800145B8u;
            ctx->pc = 0x8018F094u;
            return;
    }

label_800145B8:
    ctx->pc = 0x800145B8u;
    ctx->downcount -= 3;
    // 800145B8: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800145BC:
    // 800145BC: cmpwi   r3, -1
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

label_800145C0:
    // 800145C0: bc    12, 2, 0x800145A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800145A8u;
                return;
            }
            goto label_800145A8;
        }
    }

label_800145C4:
    ctx->pc = 0x800145C4u;
    ctx->downcount -= 2;
    // 800145C4: cmpwi   r3, -2
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800145C8:
    ctx->pc = 0x800145C8u;
    // 800145C8: bc    4, 2, 0x800145D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800145D4;
        }
    }

label_800145CC:
    ctx->downcount -= 2;
    // 800145CC: li      r3, -92
    ctx->gpr[3] = (u32)(s32)(-92);

label_800145D0:
    // 800145D0: b       0x800147DC
    {
            goto label_800147DC;
    }

label_800145D4:
    ctx->downcount -= 2;
    // 800145D4: cmpwi   r3, 0
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

label_800145D8:
    // 800145D8: bc    12, 2, 0x800145E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800145E4;
        }
    }

label_800145DC:
    ctx->downcount -= 2;
    // 800145DC: li      r3, -98
    ctx->gpr[3] = (u32)(s32)(-98);

label_800145E0:
    // 800145E0: b       0x800147DC
    {
            goto label_800147DC;
    }

label_800145E4:
    ctx->pc = 0x800145E4u;
    ctx->downcount -= 4;
    // 800145E4: lwz     r0, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800145E8:
    // 800145E8: cmpwi   r0, 8192
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(8192);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800145EC:
    // 800145EC: li      r3, -88
    ctx->gpr[3] = (u32)(s32)(-88);

label_800145F0:
    // 800145F0: bc    4, 2, 0x800147DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800147DC;
        }
    }

label_800145F4:
    ctx->downcount -= 4;
    // 800145F4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800145F8:
    // 800145F8: addi    r4, r31, 32
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(32);

label_800145FC:
    // 800145FC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014600:
    // 80014600: bl      0x8018F97C
    {
            ctx->lr = 0x80014604u;
            ctx->pc = 0x8018F97Cu;
            return;
    }

label_80014604:
    ctx->pc = 0x80014604u;
    ctx->downcount -= 3;
    // 80014604: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014608:
    // 80014608: cmpwi   r3, 0
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

label_8001460C:
    // 8001460C: bc    4, 0, 0x8001467C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001467C;
        }
    }

label_80014610:
    ctx->downcount -= 2;
    // 80014610: cmpwi   r3, -3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014614:
    // 80014614: bc    12, 2, 0x800145DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800145DCu;
                return;
            }
            goto label_800145DC;
        }
    }

label_80014618:
    ctx->downcount -= 1;
    // 80014618: bc    12, 1, 0x80014630
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014630;
        }
    }

label_8001461C:
    ctx->downcount -= 2;
    // 8001461C: cmpwi   r3, -13
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-13);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014620:
    // 80014620: bc    12, 2, 0x80014644
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014644;
        }
    }

label_80014624:
    ctx->downcount -= 2;
    // 80014624: cmpwi   r3, -5
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014628:
    // 80014628: bc    12, 2, 0x80014674
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014674;
        }
    }

label_8001462C:
    ctx->downcount -= 1;
    // 8001462C: b       0x8001467C
    {
            goto label_8001467C;
    }

label_80014630:
    ctx->downcount -= 2;
    // 80014630: cmpwi   r3, -2
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014634:
    // 80014634: bc    12, 2, 0x800145CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800145CCu;
                return;
            }
            goto label_800145CC;
        }
    }

label_80014638:
    ctx->pc = 0x80014638u;
    ctx->downcount -= 2;
    // 80014638: cmpwi   r3, -1
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

label_8001463C:
    ctx->pc = 0x8001463Cu;
    // 8001463C: bc    12, 2, 0x80014674
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014674;
        }
    }

label_80014640:
    ctx->pc = 0x80014640u;
    ctx->downcount -= 1;
    // 80014640: b       0x8001467C
    {
            goto label_8001467C;
    }

label_80014644:
    ctx->pc = 0x80014644u;
    ctx->downcount -= 2;
    // 80014644: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014648:
    ctx->pc = 0x80014648u;
    // 80014648: bc    4, 2, 0x8001467C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001467C;
        }
    }

label_8001464C:
    ctx->pc = 0x8001464Cu;
    ctx->downcount -= 2;
    // 8001464C: cmpwi   r29, 0
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

label_80014650:
    ctx->pc = 0x80014650u;
    // 80014650: bc    12, 2, 0x8001466C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001466C;
        }
    }

label_80014654:
    ctx->pc = 0x80014654u;
    ctx->downcount -= 6;
    // 80014654: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014658:
    ctx->pc = 0x80014658u;
    // 80014658: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8001465C:
    ctx->pc = 0x8001465Cu;
    // 8001465C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014660:
    ctx->pc = 0x80014660u;
    // 80014660: rlwinm r0, r0, 0, 3, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xDFFFFFFFu;
    }

label_80014664:
    ctx->pc = 0x80014664u;
    // 80014664: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014668:
    ctx->pc = 0x80014668u;
    // 80014668: bl      0x80014294
    {
            ctx->lr = 0x8001466Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_8001466C:
    ctx->pc = 0x8001466Cu;
    ctx->downcount -= 2;
    // 8001466C: li      r3, -93
    ctx->gpr[3] = (u32)(s32)(-93);

label_80014670:
    ctx->pc = 0x80014670u;
    // 80014670: b       0x800147DC
    {
            goto label_800147DC;
    }

label_80014674:
    ctx->pc = 0x80014674u;
    ctx->downcount -= 2;
    // 80014674: li      r3, -89
    ctx->gpr[3] = (u32)(s32)(-89);

label_80014678:
    ctx->pc = 0x80014678u;
    // 80014678: b       0x800147DC
    {
            goto label_800147DC;
    }

label_8001467C:
    ctx->pc = 0x8001467Cu;
    ctx->downcount -= 5;
    // 8001467C: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014680:
    ctx->pc = 0x80014680u;
    // 80014680: cmpwi   cr4, r29, 0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_80014684:
    ctx->pc = 0x80014684u;
    // 80014684: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_80014688:
    ctx->pc = 0x80014688u;
    // 80014688: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001468C:
    ctx->pc = 0x8001468Cu;
    // 8001468C: bc    12, 18, 0x800146A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800146A4;
        }
    }

label_80014690:
    ctx->pc = 0x80014690u;
    ctx->downcount -= 5;
    // 80014690: rlwinm r0, r0, 0, 3, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xDFFFFFFFu;
    }

label_80014694:
    ctx->pc = 0x80014694u;
    // 80014694: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014698:
    ctx->pc = 0x80014698u;
    // 80014698: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001469C:
    ctx->pc = 0x8001469Cu;
    // 8001469C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800146A0:
    ctx->pc = 0x800146A0u;
    // 800146A0: bl      0x80014294
    {
            ctx->lr = 0x800146A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_800146A4:
    ctx->pc = 0x800146A4u;
    ctx->downcount -= 3;
    // 800146A4: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800146A8:
    ctx->pc = 0x800146A8u;
    // 800146A8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800146AC:
    ctx->pc = 0x800146ACu;
    // 800146AC: bc    12, 2, 0x800146B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800146B8;
        }
    }

label_800146B0:
    ctx->pc = 0x800146B0u;
    ctx->downcount -= 2;
    // 800146B0: cmpwi   r0, -6
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800146B4:
    ctx->pc = 0x800146B4u;
    // 800146B4: bc    4, 2, 0x800146C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800146C4;
        }
    }

label_800146B8:
    ctx->pc = 0x800146B8u;
    ctx->downcount -= 2;
    // 800146B8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800146BC:
    ctx->pc = 0x800146BCu;
    // 800146BC: bl      0x8018EFB4
    {
            ctx->lr = 0x800146C0u;
            ctx->pc = 0x8018EFB4u;
            return;
    }

label_800146C0:
    ctx->pc = 0x800146C0u;
    ctx->downcount -= 1;
    // 800146C0: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800146C4:
    ctx->pc = 0x800146C4u;
    ctx->downcount -= 3;
    // 800146C4: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800146C8:
    ctx->pc = 0x800146C8u;
    // 800146C8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800146CC:
    ctx->pc = 0x800146CCu;
    // 800146CC: bc    4, 0, 0x80014750
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014750;
        }
    }

label_800146D0:
    ctx->pc = 0x800146D0u;
    ctx->downcount -= 2;
    // 800146D0: cmpwi   r0, -6
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800146D4:
    ctx->pc = 0x800146D4u;
    // 800146D4: bc    12, 2, 0x80014748
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014748;
        }
    }

label_800146D8:
    ctx->pc = 0x800146D8u;
    ctx->downcount -= 1;
    // 800146D8: bc    12, 1, 0x800146F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800146F0;
        }
    }

label_800146DC:
    ctx->pc = 0x800146DCu;
    ctx->downcount -= 2;
    // 800146DC: cmpwi   r0, -128
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-128);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800146E0:
    ctx->pc = 0x800146E0u;
    // 800146E0: bc    12, 2, 0x80014748
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014748;
        }
    }

label_800146E4:
    ctx->pc = 0x800146E4u;
    ctx->downcount -= 2;
    // 800146E4: cmpwi   r0, -13
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-13);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800146E8:
    ctx->pc = 0x800146E8u;
    // 800146E8: bc    12, 2, 0x80014714
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014714;
        }
    }

label_800146EC:
    ctx->pc = 0x800146ECu;
    ctx->downcount -= 1;
    // 800146EC: b       0x80014750
    {
            goto label_80014750;
    }

label_800146F0:
    ctx->pc = 0x800146F0u;
    ctx->downcount -= 2;
    // 800146F0: cmpwi   r0, -3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800146F4:
    ctx->pc = 0x800146F4u;
    // 800146F4: bc    12, 2, 0x80014720
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014720;
        }
    }

label_800146F8:
    ctx->pc = 0x800146F8u;
    ctx->downcount -= 1;
    // 800146F8: bc    12, 1, 0x80014708
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014708;
        }
    }

label_800146FC:
    ctx->pc = 0x800146FCu;
    ctx->downcount -= 2;
    // 800146FC: cmpwi   r0, -5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014700:
    ctx->pc = 0x80014700u;
    // 80014700: bc    12, 2, 0x80014740
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014740;
        }
    }

label_80014704:
    ctx->pc = 0x80014704u;
    ctx->downcount -= 1;
    // 80014704: b       0x80014750
    {
            goto label_80014750;
    }

label_80014708:
    ctx->pc = 0x80014708u;
    ctx->downcount -= 2;
    // 80014708: cmpwi   r0, -1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001470C:
    ctx->pc = 0x8001470Cu;
    // 8001470C: bc    12, 2, 0x80014748
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014748;
        }
    }

label_80014710:
    ctx->pc = 0x80014710u;
    ctx->downcount -= 1;
    // 80014710: b       0x80014750
    {
            goto label_80014750;
    }

label_80014714:
    ctx->pc = 0x80014714u;
    ctx->downcount -= 2;
    // 80014714: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014718:
    ctx->pc = 0x80014718u;
    // 80014718: bc    4, 2, 0x800147D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800147D8;
        }
    }

label_8001471C:
    ctx->pc = 0x8001471Cu;
    ctx->downcount -= 1;
    // 8001471C: b       0x8001479C
    {
            goto label_8001479C;
    }

label_80014720:
    ctx->pc = 0x80014720u;
    ctx->downcount -= 2;
    // 80014720: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014724:
    ctx->pc = 0x80014724u;
    // 80014724: bl      0x8018FA60
    {
            ctx->lr = 0x80014728u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014728:
    ctx->pc = 0x80014728u;
    ctx->downcount -= 6;
    // 80014728: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001472C:
    ctx->pc = 0x8001472Cu;
    // 8001472C: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014730:
    ctx->pc = 0x80014730u;
    // 80014730: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014734:
    ctx->pc = 0x80014734u;
    // 80014734: li      r3, -98
    ctx->gpr[3] = (u32)(s32)(-98);

label_80014738:
    ctx->pc = 0x80014738u;
    // 80014738: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001473C:
    ctx->pc = 0x8001473Cu;
    // 8001473C: b       0x800147DC
    {
            goto label_800147DC;
    }

label_80014740:
    ctx->pc = 0x80014740u;
    ctx->downcount -= 2;
    // 80014740: li      r3, -87
    ctx->gpr[3] = (u32)(s32)(-87);

label_80014744:
    ctx->pc = 0x80014744u;
    // 80014744: b       0x800147DC
    {
            goto label_800147DC;
    }

label_80014748:
    ctx->pc = 0x80014748u;
    ctx->downcount -= 2;
    // 80014748: li      r3, -90
    ctx->gpr[3] = (u32)(s32)(-90);

label_8001474C:
    ctx->pc = 0x8001474Cu;
    // 8001474C: b       0x800147DC
    {
            goto label_800147DC;
    }

label_80014750:
    ctx->pc = 0x80014750u;
    ctx->downcount -= 2;
    // 80014750: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014754:
    ctx->pc = 0x80014754u;
    // 80014754: bc    4, 2, 0x800147D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800147D8;
        }
    }

label_80014758:
    ctx->pc = 0x80014758u;
    ctx->downcount -= 3;
    // 80014758: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8001475C:
    ctx->pc = 0x8001475Cu;
    // 8001475C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80014760:
    ctx->pc = 0x80014760u;
    // 80014760: bl      0x8018D73C
    {
            ctx->lr = 0x80014764u;
            ctx->pc = 0x8018D73Cu;
            return;
    }

label_80014764:
    ctx->pc = 0x80014764u;
    ctx->downcount -= 3;
    // 80014764: cmpwi   r3, 0
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

label_80014768:
    ctx->pc = 0x80014768u;
    // 80014768: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8001476C:
    ctx->pc = 0x8001476Cu;
    // 8001476C: bc    4, 0, 0x80014790
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014790;
        }
    }

label_80014770:
    ctx->pc = 0x80014770u;
    ctx->downcount -= 2;
    // 80014770: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014774:
    ctx->pc = 0x80014774u;
    // 80014774: bl      0x8018FA60
    {
            ctx->lr = 0x80014778u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014778:
    ctx->pc = 0x80014778u;
    ctx->downcount -= 6;
    // 80014778: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001477C:
    ctx->pc = 0x8001477Cu;
    // 8001477C: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014780:
    ctx->pc = 0x80014780u;
    // 80014780: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014784:
    ctx->pc = 0x80014784u;
    // 80014784: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80014788:
    ctx->pc = 0x80014788u;
    // 80014788: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001478C:
    ctx->pc = 0x8001478Cu;
    // 8001478C: b       0x800147DC
    {
            goto label_800147DC;
    }

label_80014790:
    ctx->pc = 0x80014790u;
    ctx->downcount -= 3;
    // 80014790: lhz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80014794:
    ctx->pc = 0x80014794u;
    // 80014794: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014798:
    ctx->pc = 0x80014798u;
    // 80014798: bc    12, 2, 0x800147D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800147D8;
        }
    }

label_8001479C:
    ctx->pc = 0x8001479Cu;
    ctx->downcount -= 1;
    // 8001479C: bc    12, 18, 0x800147B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800147B8;
        }
    }

label_800147A0:
    ctx->pc = 0x800147A0u;
    ctx->downcount -= 6;
    // 800147A0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800147A4:
    ctx->pc = 0x800147A4u;
    // 800147A4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800147A8:
    ctx->pc = 0x800147A8u;
    // 800147A8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800147AC:
    ctx->pc = 0x800147ACu;
    // 800147AC: rlwinm r0, r0, 0, 3, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xDFFFFFFFu;
    }

label_800147B0:
    ctx->pc = 0x800147B0u;
    // 800147B0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800147B4:
    ctx->pc = 0x800147B4u;
    // 800147B4: bl      0x80014294
    {
            ctx->lr = 0x800147B8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_800147B8:
    ctx->pc = 0x800147B8u;
    ctx->downcount -= 2;
    // 800147B8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800147BC:
    ctx->pc = 0x800147BCu;
    // 800147BC: bl      0x8018FA60
    {
            ctx->lr = 0x800147C0u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_800147C0:
    ctx->pc = 0x800147C0u;
    ctx->downcount -= 6;
    // 800147C0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800147C4:
    ctx->pc = 0x800147C4u;
    // 800147C4: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800147C8:
    ctx->pc = 0x800147C8u;
    // 800147C8: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_800147CC:
    ctx->pc = 0x800147CCu;
    // 800147CC: li      r3, -93
    ctx->gpr[3] = (u32)(s32)(-93);

label_800147D0:
    ctx->pc = 0x800147D0u;
    // 800147D0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800147D4:
    ctx->pc = 0x800147D4u;
    // 800147D4: b       0x800147DC
    {
            goto label_800147DC;
    }

label_800147D8:
    ctx->pc = 0x800147D8u;
    ctx->downcount -= 1;
    // 800147D8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800147DC:
    ctx->pc = 0x800147DCu;
    ctx->downcount -= 18;
    // 800147DC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800147E0:
    ctx->pc = 0x800147E0u;
    // 800147E0: lwz     r12, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_800147E4:
    ctx->pc = 0x800147E4u;
    // 800147E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800147E8:
    ctx->pc = 0x800147E8u;
    // 800147E8: lmw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800147EC:
    ctx->pc = 0x800147ECu;
    // 800147EC: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_800147F0:
    ctx->pc = 0x800147F0u;
    // 800147F0: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_800147F4:
    ctx->pc = 0x800147F4u;
    // 800147F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800147F8:
    ctx->pc = 0x800147F8u;
    ctx->downcount -= 19;
    // 800147F8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800147FC:
    ctx->pc = 0x800147FCu;
    // 800147FC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014800:
    ctx->pc = 0x80014800u;
    // 80014800: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014804:
    ctx->pc = 0x80014804u;
    // 80014804: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014808:
    ctx->pc = 0x80014808u;
    // 80014808: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8001480C:
    ctx->pc = 0x8001480Cu;
    // 8001480C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80014810:
    ctx->pc = 0x80014810u;
    // 80014810: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80014814:
    ctx->pc = 0x80014814u;
    // 80014814: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014818:
    ctx->pc = 0x80014818u;
    // 80014818: bl      0x80014584
    {
            ctx->lr = 0x8001481Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014584u;
                return;
            }
            goto label_80014584;
    }

label_8001481C:
    ctx->pc = 0x8001481Cu;
    ctx->downcount -= 4;
    // 8001481C: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014820:
    ctx->pc = 0x80014820u;
    // 80014820: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80014824:
    ctx->pc = 0x80014824u;
    // 80014824: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014828:
    ctx->pc = 0x80014828u;
    // 80014828: bc    12, 0, 0x8001483C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001483C;
        }
    }

label_8001482C:
    ctx->pc = 0x8001482Cu;
    ctx->downcount -= 2;
    // 8001482C: cmpwi   r3, 0
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

label_80014830:
    ctx->pc = 0x80014830u;
    // 80014830: bc    12, 0, 0x800148C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800148C8;
        }
    }

label_80014834:
    ctx->pc = 0x80014834u;
    ctx->downcount -= 2;
    // 80014834: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80014838:
    ctx->pc = 0x80014838u;
    // 80014838: b       0x800148C8
    {
            goto label_800148C8;
    }

label_8001483C:
    ctx->pc = 0x8001483Cu;
    ctx->downcount -= 3;
    // 8001483C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014840:
    ctx->pc = 0x80014840u;
    // 80014840: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014844:
    ctx->pc = 0x80014844u;
    // 80014844: bl      0x80014294
    {
            ctx->lr = 0x80014848u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_80014848:
    ctx->pc = 0x80014848u;
    ctx->downcount -= 2;
    // 80014848: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8001484C:
    ctx->pc = 0x8001484Cu;
    // 8001484C: bc    4, 0, 0x80014870
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014870;
        }
    }

label_80014850:
    ctx->pc = 0x80014850u;
    ctx->downcount -= 2;
    // 80014850: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014854:
    ctx->pc = 0x80014854u;
    // 80014854: bl      0x8018FA60
    {
            ctx->lr = 0x80014858u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014858:
    ctx->pc = 0x80014858u;
    ctx->downcount -= 6;
    // 80014858: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001485C:
    ctx->pc = 0x8001485Cu;
    // 8001485C: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014860:
    ctx->pc = 0x80014860u;
    // 80014860: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014864:
    ctx->pc = 0x80014864u;
    // 80014864: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014868:
    ctx->pc = 0x80014868u;
    // 80014868: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001486C:
    ctx->pc = 0x8001486Cu;
    // 8001486C: b       0x800148C8
    {
            goto label_800148C8;
    }

label_80014870:
    ctx->pc = 0x80014870u;
    ctx->downcount -= 5;
    // 80014870: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014874:
    ctx->pc = 0x80014874u;
    // 80014874: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014878:
    ctx->pc = 0x80014878u;
    // 80014878: rlwinm r0, r0, 0, 3, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xDFFFFFFFu;
    }

label_8001487C:
    ctx->pc = 0x8001487Cu;
    // 8001487C: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014880:
    ctx->pc = 0x80014880u;
    // 80014880: bl      0x80190338
    {
            ctx->lr = 0x80014884u;
            ctx->pc = 0x80190338u;
            return;
    }

label_80014884:
    ctx->pc = 0x80014884u;
    ctx->downcount -= 3;
    // 80014884: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014888:
    ctx->pc = 0x80014888u;
    // 80014888: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8001488C:
    ctx->pc = 0x8001488Cu;
    // 8001488C: bl      0x8018FA60
    {
            ctx->lr = 0x80014890u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014890:
    ctx->pc = 0x80014890u;
    ctx->downcount -= 6;
    // 80014890: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014894:
    ctx->pc = 0x80014894u;
    // 80014894: cmpwi   r3, 0
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

label_80014898:
    ctx->pc = 0x80014898u;
    // 80014898: stw     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8001489C:
    ctx->pc = 0x8001489Cu;
    // 8001489C: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_800148A0:
    ctx->pc = 0x800148A0u;
    // 800148A0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800148A4:
    ctx->pc = 0x800148A4u;
    // 800148A4: bc    12, 0, 0x800148C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800148C4;
        }
    }

label_800148A8:
    ctx->pc = 0x800148A8u;
    ctx->downcount -= 5;
    // 800148A8: rlwinm r0, r0, 0, 3, 1
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xDFFFFFFFu;
    }

label_800148AC:
    ctx->pc = 0x800148ACu;
    // 800148AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800148B0:
    ctx->pc = 0x800148B0u;
    // 800148B0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800148B4:
    ctx->pc = 0x800148B4u;
    // 800148B4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800148B8:
    ctx->pc = 0x800148B8u;
    // 800148B8: bl      0x80014294
    {
            ctx->lr = 0x800148BCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_800148BC:
    ctx->pc = 0x800148BCu;
    ctx->downcount -= 2;
    // 800148BC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800148C0:
    ctx->pc = 0x800148C0u;
    // 800148C0: b       0x800148C8
    {
            goto label_800148C8;
    }

label_800148C4:
    ctx->pc = 0x800148C4u;
    ctx->downcount -= 1;
    // 800148C4: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_800148C8:
    ctx->pc = 0x800148C8u;
    ctx->downcount -= 16;
    // 800148C8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800148CC:
    ctx->pc = 0x800148CCu;
    // 800148CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800148D0:
    ctx->pc = 0x800148D0u;
    // 800148D0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800148D4:
    ctx->pc = 0x800148D4u;
    // 800148D4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800148D8:
    ctx->pc = 0x800148D8u;
    // 800148D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800148DC:
    ctx->pc = 0x800148DCu;
    ctx->downcount -= 7;
    // 800148DC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800148E0:
    ctx->pc = 0x800148E0u;
    // 800148E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800148E4:
    ctx->pc = 0x800148E4u;
    // 800148E4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800148E8:
    ctx->pc = 0x800148E8u;
    // 800148E8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800148EC:
    ctx->pc = 0x800148ECu;
    // 800148EC: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_800148F0:
    ctx->pc = 0x800148F0u;
    // 800148F0: addi    r3, r3, -27584
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27584);

label_800148F4:
    ctx->pc = 0x800148F4u;
    // 800148F4: bl      0x800147F8
    {
            ctx->lr = 0x800148F8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800147F8u;
                return;
            }
            goto label_800147F8;
    }

label_800148F8:
    ctx->pc = 0x800148F8u;
    ctx->downcount -= 5;
    // 800148F8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800148FC:
    ctx->pc = 0x800148FCu;
    // 800148FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014900:
    ctx->pc = 0x80014900u;
    // 80014900: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80014904:
    ctx->pc = 0x80014904u;
    // 80014904: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014908:
    ctx->pc = 0x80014908u;
    ctx->downcount -= 19;
    // 80014908: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8001490C:
    ctx->pc = 0x8001490Cu;
    // 8001490C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014910:
    ctx->pc = 0x80014910u;
    // 80014910: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014914:
    ctx->pc = 0x80014914u;
    // 80014914: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014918:
    ctx->pc = 0x80014918u;
    // 80014918: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8001491C:
    ctx->pc = 0x8001491Cu;
    // 8001491C: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80014920:
    ctx->pc = 0x80014920u;
    // 80014920: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_80014924:
    ctx->pc = 0x80014924u;
    // 80014924: addi    r3, r3, -26760
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-26760);

label_80014928:
    ctx->pc = 0x80014928u;
    // 80014928: bl      0x80030F78
    {
            ctx->lr = 0x8001492Cu;
            ctx->pc = 0x80030F78u;
            return;
    }

label_8001492C:
    ctx->pc = 0x8001492Cu;
    ctx->downcount -= 3;
    // 8001492C: lis     r3, -32701
    ctx->gpr[3] = ((u32)(s32)(-32701) << 16);

label_80014930:
    ctx->pc = 0x80014930u;
    // 80014930: addi    r3, r3, -29512
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-29512);

label_80014934:
    ctx->pc = 0x80014934u;
    // 80014934: bl      0x80034700
    {
            ctx->lr = 0x80014938u;
            ctx->pc = 0x80034700u;
            return;
    }

label_80014938:
    ctx->pc = 0x80014938u;
    ctx->downcount -= 5;
    // 80014938: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8001493C:
    ctx->pc = 0x8001493Cu;
    // 8001493C: lis     r4, 8192
    ctx->gpr[4] = ((u32)(s32)(8192) << 16);

label_80014940:
    ctx->pc = 0x80014940u;
    // 80014940: addi    r3, r3, -26744
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-26744);

label_80014944:
    ctx->pc = 0x80014944u;
    // 80014944: ori     r4, r4, 0x0131
    ctx->gpr[4] = ctx->gpr[4] | 0x0131u;

label_80014948:
    ctx->pc = 0x80014948u;
    // 80014948: bl      0x80032644
    {
            ctx->lr = 0x8001494Cu;
            ctx->pc = 0x80032644u;
            return;
    }

label_8001494C:
    ctx->pc = 0x8001494Cu;
    ctx->downcount -= 2;
    // 8001494C: or.   r3, r3, r3
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014950:
    ctx->pc = 0x80014950u;
    // 80014950: bc    12, 2, 0x8001498C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001498C;
        }
    }

label_80014954:
    ctx->pc = 0x80014954u;
    ctx->downcount -= 3;
    // 80014954: lwz     r9, 88(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(88);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80014958:
    ctx->pc = 0x80014958u;
    // 80014958: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001495C:
    ctx->pc = 0x8001495Cu;
    // 8001495C: bc    12, 2, 0x8001496C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001496C;
        }
    }

label_80014960:
    ctx->pc = 0x80014960u;
    ctx->downcount -= 3;
    // 80014960: addi    r0, r9, 88
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(88);

label_80014964:
    ctx->pc = 0x80014964u;
    // 80014964: add   r4, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80014968:
    ctx->pc = 0x80014968u;
    // 80014968: b       0x80014970
    {
            goto label_80014970;
    }

label_8001496C:
    ctx->pc = 0x8001496Cu;
    ctx->downcount -= 1;
    // 8001496C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014970:
    ctx->pc = 0x80014970u;
    ctx->downcount -= 4;
    // 80014970: lis     r3, -32736
    ctx->gpr[3] = ((u32)(s32)(-32736) << 16);

label_80014974:
    ctx->pc = 0x80014974u;
    // 80014974: li      r5, 2048
    ctx->gpr[5] = (u32)(s32)(2048);

label_80014978:
    ctx->pc = 0x80014978u;
    // 80014978: addi    r3, r3, 9568
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9568);

label_8001497C:
    ctx->pc = 0x8001497Cu;
    // 8001497C: bl      0x8016984C
    {
            ctx->lr = 0x80014980u;
            ctx->pc = 0x8016984Cu;
            return;
    }

label_80014980:
    ctx->pc = 0x80014980u;
    ctx->downcount -= 3;
    // 80014980: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_80014984:
    ctx->pc = 0x80014984u;
    // 80014984: addi    r3, r3, -26744
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-26744);

label_80014988:
    ctx->pc = 0x80014988u;
    // 80014988: bl      0x80030FE8
    {
            ctx->lr = 0x8001498Cu;
            ctx->pc = 0x80030FE8u;
            return;
    }

label_8001498C:
    ctx->pc = 0x8001498Cu;
    ctx->downcount -= 31;
    // 8001498C: lis     r8, -32708
    ctx->gpr[8] = ((u32)(s32)(-32708) << 16);

label_80014990:
    ctx->pc = 0x80014990u;
    // 80014990: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80014994:
    ctx->pc = 0x80014994u;
    // 80014994: addi    r9, r8, -27584
    ctx->gpr[9] = ctx->gpr[8] + (u32)(s32)(-27584);

label_80014998:
    ctx->pc = 0x80014998u;
    // 80014998: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8001499C:
    ctx->pc = 0x8001499Cu;
    // 8001499C: addis   r7, r9, 5
    ctx->gpr[7] = ctx->gpr[9] + ((u32)(s32)(5) << 16);

label_800149A0:
    ctx->pc = 0x800149A0u;
    // 800149A0: li      r11, 1
    ctx->gpr[11] = (u32)(s32)(1);

label_800149A4:
    ctx->pc = 0x800149A4u;
    // 800149A4: stw     r10, 56(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800149A8:
    ctx->pc = 0x800149A8u;
    // 800149A8: stw     r10, -27584(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-27584);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800149AC:
    ctx->pc = 0x800149ACu;
    // 800149AC: stw     r11, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800149B0:
    ctx->pc = 0x800149B0u;
    // 800149B0: stw     r0, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800149B4:
    ctx->pc = 0x800149B4u;
    // 800149B4: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800149B8:
    ctx->pc = 0x800149B8u;
    // 800149B8: stw     r31, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800149BC:
    ctx->pc = 0x800149BCu;
    // 800149BC: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800149C0:
    ctx->pc = 0x800149C0u;
    // 800149C0: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800149C4:
    ctx->pc = 0x800149C4u;
    // 800149C4: stw     r10, 52(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800149C8:
    ctx->pc = 0x800149C8u;
    // 800149C8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800149CC:
    ctx->pc = 0x800149CCu;
    // 800149CC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800149D0:
    ctx->pc = 0x800149D0u;
    // 800149D0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800149D4:
    ctx->pc = 0x800149D4u;
    // 800149D4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800149D8:
    ctx->pc = 0x800149D8u;
    // 800149D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800149DC:
    ctx->pc = 0x800149DCu;
    ctx->downcount -= 2;
    // 800149DC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800149E0:
    ctx->pc = 0x800149E0u;
    // 800149E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800149E4:
    ctx->pc = 0x800149E4u;
    ctx->downcount -= 19;
    // 800149E4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800149E8:
    ctx->pc = 0x800149E8u;
    // 800149E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800149EC:
    ctx->pc = 0x800149ECu;
    // 800149EC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800149F0:
    ctx->pc = 0x800149F0u;
    // 800149F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800149F4:
    ctx->pc = 0x800149F4u;
    // 800149F4: lis     r30, -32708
    ctx->gpr[30] = ((u32)(s32)(-32708) << 16);

label_800149F8:
    ctx->pc = 0x800149F8u;
    // 800149F8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800149FC:
    ctx->pc = 0x800149FCu;
    // 800149FC: addi    r3, r30, -27584
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27584);

label_80014A00:
    ctx->pc = 0x80014A00u;
    // 80014A00: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014A04:
    ctx->pc = 0x80014A04u;
    // 80014A04: bl      0x80014584
    {
            ctx->lr = 0x80014A08u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014584u;
                return;
            }
            goto label_80014584;
    }

label_80014A08:
    ctx->pc = 0x80014A08u;
    ctx->downcount -= 2;
    // 80014A08: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014A0C:
    ctx->pc = 0x80014A0Cu;
    // 80014A0C: bc    4, 0, 0x80014A3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014A3C;
        }
    }

label_80014A10:
    ctx->pc = 0x80014A10u;
    ctx->downcount -= 2;
    // 80014A10: cmpwi   r31, -98
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(-98);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014A14:
    ctx->pc = 0x80014A14u;
    // 80014A14: bc    12, 2, 0x80014A58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014A58;
        }
    }

label_80014A18:
    ctx->pc = 0x80014A18u;
    ctx->downcount -= 4;
    // 80014A18: lwz     r0, -27584(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-27584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014A1C:
    ctx->pc = 0x80014A1Cu;
    // 80014A1C: addi    r3, r30, -27584
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27584);

label_80014A20:
    ctx->pc = 0x80014A20u;
    // 80014A20: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014A24:
    ctx->pc = 0x80014A24u;
    // 80014A24: bc    4, 0, 0x80014A54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014A54;
        }
    }

label_80014A28:
    ctx->pc = 0x80014A28u;
    ctx->downcount -= 2;
    // 80014A28: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014A2C:
    ctx->pc = 0x80014A2Cu;
    // 80014A2C: bl      0x80014294
    {
            ctx->lr = 0x80014A30u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_80014A30:
    ctx->pc = 0x80014A30u;
    ctx->downcount -= 2;
    // 80014A30: cmpwi   r3, -94
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-94);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014A34:
    ctx->pc = 0x80014A34u;
    // 80014A34: bc    4, 2, 0x80014A58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014A58;
        }
    }

label_80014A38:
    ctx->pc = 0x80014A38u;
    ctx->downcount -= 1;
    // 80014A38: b       0x80014A54
    {
            goto label_80014A54;
    }

label_80014A3C:
    ctx->pc = 0x80014A3Cu;
    ctx->downcount -= 2;
    // 80014A3C: addi    r3, r30, -27584
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27584);

label_80014A40:
    ctx->pc = 0x80014A40u;
    // 80014A40: bl      0x80014464
    {
            ctx->lr = 0x80014A44u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014464u;
                return;
            }
            goto label_80014464;
    }

label_80014A44:
    ctx->pc = 0x80014A44u;
    ctx->downcount -= 2;
    // 80014A44: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014A48:
    ctx->pc = 0x80014A48u;
    // 80014A48: bc    4, 0, 0x80014A60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014A60;
        }
    }

label_80014A4C:
    ctx->pc = 0x80014A4Cu;
    ctx->downcount -= 2;
    // 80014A4C: cmpwi   r31, -98
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(-98);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014A50:
    ctx->pc = 0x80014A50u;
    // 80014A50: bc    12, 2, 0x80014A58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014A58;
        }
    }

label_80014A54:
    ctx->pc = 0x80014A54u;
    ctx->downcount -= 1;
    // 80014A54: li      r31, -94
    ctx->gpr[31] = (u32)(s32)(-94);

label_80014A58:
    ctx->pc = 0x80014A58u;
    ctx->downcount -= 2;
    // 80014A58: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014A5C:
    ctx->pc = 0x80014A5Cu;
    // 80014A5C: b       0x80014A78
    {
            goto label_80014A78;
    }

label_80014A60:
    ctx->pc = 0x80014A60u;
    ctx->downcount -= 2;
    // 80014A60: addi    r3, r30, -27584
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27584);

label_80014A64:
    ctx->pc = 0x80014A64u;
    // 80014A64: bl      0x8001409C
    {
            ctx->lr = 0x80014A68u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8001409Cu;
                return;
            }
            goto label_8001409C;
    }

label_80014A68:
    ctx->pc = 0x80014A68u;
    ctx->downcount -= 3;
    // 80014A68: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014A6C:
    ctx->pc = 0x80014A6Cu;
    // 80014A6C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014A70:
    ctx->pc = 0x80014A70u;
    // 80014A70: bc    12, 0, 0x80014A78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014A78;
        }
    }

label_80014A74:
    ctx->pc = 0x80014A74u;
    ctx->downcount -= 1;
    // 80014A74: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014A78:
    ctx->pc = 0x80014A78u;
    ctx->downcount -= 16;
    // 80014A78: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014A7C:
    ctx->pc = 0x80014A7Cu;
    // 80014A7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014A80:
    ctx->pc = 0x80014A80u;
    // 80014A80: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014A84:
    ctx->pc = 0x80014A84u;
    // 80014A84: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80014A88:
    ctx->pc = 0x80014A88u;
    // 80014A88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014A8C:
    ctx->pc = 0x80014A8Cu;
    ctx->downcount -= 2;
    // 80014A8C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014A90:
    ctx->pc = 0x80014A90u;
    // 80014A90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014A94:
    ctx->pc = 0x80014A94u;
    ctx->downcount -= 20;
    // 80014A94: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014A98:
    ctx->pc = 0x80014A98u;
    // 80014A98: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014A9C:
    ctx->pc = 0x80014A9Cu;
    // 80014A9C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014AA0:
    ctx->pc = 0x80014AA0u;
    // 80014AA0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014AA4:
    ctx->pc = 0x80014AA4u;
    // 80014AA4: lis     r30, -32708
    ctx->gpr[30] = ((u32)(s32)(-32708) << 16);

label_80014AA8:
    ctx->pc = 0x80014AA8u;
    // 80014AA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014AAC:
    ctx->pc = 0x80014AACu;
    // 80014AAC: addi    r29, r30, -27584
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(-27584);

label_80014AB0:
    ctx->pc = 0x80014AB0u;
    // 80014AB0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014AB4:
    ctx->pc = 0x80014AB4u;
    // 80014AB4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014AB8:
    ctx->pc = 0x80014AB8u;
    // 80014AB8: bl      0x80014584
    {
            ctx->lr = 0x80014ABCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014584u;
                return;
            }
            goto label_80014584;
    }

label_80014ABC:
    ctx->pc = 0x80014ABCu;
    ctx->downcount -= 4;
    // 80014ABC: lwz     r0, -27584(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-27584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014AC0:
    ctx->pc = 0x80014AC0u;
    // 80014AC0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80014AC4:
    ctx->pc = 0x80014AC4u;
    // 80014AC4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014AC8:
    ctx->pc = 0x80014AC8u;
    // 80014AC8: bc    4, 0, 0x80014B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014B50;
        }
    }

label_80014ACC:
    ctx->pc = 0x80014ACCu;
    ctx->downcount -= 3;
    // 80014ACC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014AD0:
    ctx->pc = 0x80014AD0u;
    // 80014AD0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014AD4:
    ctx->pc = 0x80014AD4u;
    // 80014AD4: bl      0x80014294
    {
            ctx->lr = 0x80014AD8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_80014AD8:
    ctx->pc = 0x80014AD8u;
    ctx->downcount -= 2;
    // 80014AD8: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014ADC:
    ctx->pc = 0x80014ADCu;
    // 80014ADC: bc    12, 0, 0x80014AF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014AF8;
        }
    }

label_80014AE0:
    ctx->pc = 0x80014AE0u;
    ctx->downcount -= 2;
    // 80014AE0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014AE4:
    ctx->pc = 0x80014AE4u;
    // 80014AE4: bl      0x80014464
    {
            ctx->lr = 0x80014AE8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014464u;
                return;
            }
            goto label_80014464;
    }

label_80014AE8:
    ctx->pc = 0x80014AE8u;
    ctx->downcount -= 2;
    // 80014AE8: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014AEC:
    ctx->pc = 0x80014AECu;
    // 80014AEC: bc    4, 0, 0x80014B48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014B48;
        }
    }

label_80014AF0:
    ctx->pc = 0x80014AF0u;
    ctx->downcount -= 2;
    // 80014AF0: cmpwi   r31, -97
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(-97);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014AF4:
    ctx->pc = 0x80014AF4u;
    // 80014AF4: bc    12, 2, 0x80014B18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014B18;
        }
    }

label_80014AF8:
    ctx->pc = 0x80014AF8u;
    ctx->downcount -= 2;
    // 80014AF8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014AFC:
    ctx->pc = 0x80014AFCu;
    // 80014AFC: bl      0x8018FA60
    {
            ctx->lr = 0x80014B00u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014B00:
    ctx->pc = 0x80014B00u;
    ctx->downcount -= 6;
    // 80014B00: lwz     r0, -27584(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-27584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014B04:
    ctx->pc = 0x80014B04u;
    // 80014B04: stw     r3, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014B08:
    ctx->pc = 0x80014B08u;
    // 80014B08: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014B0C:
    ctx->pc = 0x80014B0Cu;
    // 80014B0C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014B10:
    ctx->pc = 0x80014B10u;
    // 80014B10: stw     r0, -27584(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-27584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014B14:
    ctx->pc = 0x80014B14u;
    // 80014B14: b       0x80014B54
    {
            goto label_80014B54;
    }

label_80014B18:
    ctx->pc = 0x80014B18u;
    ctx->downcount -= 2;
    // 80014B18: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014B1C:
    ctx->pc = 0x80014B1Cu;
    // 80014B1C: bl      0x80013FA0
    {
            ctx->lr = 0x80014B20u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013FA0u;
                return;
            }
            goto label_80013FA0;
    }

label_80014B20:
    ctx->pc = 0x80014B20u;
    ctx->downcount -= 3;
    // 80014B20: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014B24:
    ctx->pc = 0x80014B24u;
    // 80014B24: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014B28:
    ctx->pc = 0x80014B28u;
    // 80014B28: bc    12, 0, 0x80014B54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014B54;
        }
    }

label_80014B2C:
    ctx->pc = 0x80014B2Cu;
    ctx->downcount -= 2;
    // 80014B2C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014B30:
    ctx->pc = 0x80014B30u;
    // 80014B30: bl      0x8001409C
    {
            ctx->lr = 0x80014B34u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8001409Cu;
                return;
            }
            goto label_8001409C;
    }

label_80014B34:
    ctx->pc = 0x80014B34u;
    ctx->downcount -= 3;
    // 80014B34: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014B38:
    ctx->pc = 0x80014B38u;
    // 80014B38: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014B3C:
    ctx->pc = 0x80014B3Cu;
    // 80014B3C: bc    12, 0, 0x80014B54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014B54;
        }
    }

label_80014B40:
    ctx->pc = 0x80014B40u;
    ctx->downcount -= 2;
    // 80014B40: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80014B44:
    ctx->pc = 0x80014B44u;
    // 80014B44: b       0x80014B54
    {
            goto label_80014B54;
    }

label_80014B48:
    ctx->pc = 0x80014B48u;
    ctx->downcount -= 2;
    // 80014B48: li      r3, -100
    ctx->gpr[3] = (u32)(s32)(-100);

label_80014B4C:
    ctx->pc = 0x80014B4Cu;
    // 80014B4C: b       0x80014B54
    {
            goto label_80014B54;
    }

label_80014B50:
    ctx->pc = 0x80014B50u;
    ctx->downcount -= 1;
    // 80014B50: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014B54:
    ctx->pc = 0x80014B54u;
    ctx->downcount -= 16;
    // 80014B54: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014B58:
    ctx->pc = 0x80014B58u;
    // 80014B58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014B5C:
    ctx->pc = 0x80014B5Cu;
    // 80014B5C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014B60:
    ctx->pc = 0x80014B60u;
    // 80014B60: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80014B64:
    ctx->pc = 0x80014B64u;
    // 80014B64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014B68:
    ctx->pc = 0x80014B68u;
    ctx->downcount -= 20;
    // 80014B68: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014B6C:
    ctx->pc = 0x80014B6Cu;
    // 80014B6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014B70:
    ctx->pc = 0x80014B70u;
    // 80014B70: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014B74:
    ctx->pc = 0x80014B74u;
    // 80014B74: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014B78:
    ctx->pc = 0x80014B78u;
    // 80014B78: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80014B7C:
    ctx->pc = 0x80014B7Cu;
    // 80014B7C: lis     r29, -32708
    ctx->gpr[29] = ((u32)(s32)(-32708) << 16);

label_80014B80:
    ctx->pc = 0x80014B80u;
    // 80014B80: addi    r3, r29, -27584
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014B84:
    ctx->pc = 0x80014B84u;
    // 80014B84: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014B88:
    ctx->pc = 0x80014B88u;
    // 80014B88: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80014B8C:
    ctx->pc = 0x80014B8Cu;
    // 80014B8C: bl      0x80014584
    {
            ctx->lr = 0x80014B90u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014584u;
                return;
            }
            goto label_80014584;
    }

label_80014B90:
    ctx->pc = 0x80014B90u;
    ctx->downcount -= 2;
    // 80014B90: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014B94:
    ctx->pc = 0x80014B94u;
    // 80014B94: bc    4, 0, 0x80014BBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014BBC;
        }
    }

label_80014B98:
    ctx->pc = 0x80014B98u;
    ctx->downcount -= 4;
    // 80014B98: lwz     r0, -27584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-27584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014B9C:
    ctx->pc = 0x80014B9Cu;
    // 80014B9C: addi    r30, r29, -27584
    ctx->gpr[30] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014BA0:
    ctx->pc = 0x80014BA0u;
    // 80014BA0: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014BA4:
    ctx->pc = 0x80014BA4u;
    // 80014BA4: bc    4, 0, 0x80014BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014BB4;
        }
    }

label_80014BA8:
    ctx->pc = 0x80014BA8u;
    ctx->downcount -= 3;
    // 80014BA8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014BAC:
    ctx->pc = 0x80014BACu;
    // 80014BAC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014BB0:
    ctx->pc = 0x80014BB0u;
    // 80014BB0: bl      0x80014294
    {
            ctx->lr = 0x80014BB4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014294u;
                return;
            }
            goto label_80014294;
    }

label_80014BB4:
    ctx->pc = 0x80014BB4u;
    ctx->downcount -= 2;
    // 80014BB4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014BB8:
    ctx->pc = 0x80014BB8u;
    // 80014BB8: b       0x80014BDC
    {
            goto label_80014BDC;
    }

label_80014BBC:
    ctx->pc = 0x80014BBCu;
    ctx->downcount -= 2;
    // 80014BBC: addi    r3, r29, -27584
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014BC0:
    ctx->pc = 0x80014BC0u;
    // 80014BC0: bl      0x80014464
    {
            ctx->lr = 0x80014BC4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014464u;
                return;
            }
            goto label_80014464;
    }

label_80014BC4:
    ctx->pc = 0x80014BC4u;
    ctx->downcount -= 2;
    // 80014BC4: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014BC8:
    ctx->pc = 0x80014BC8u;
    // 80014BC8: bc    4, 0, 0x80014C54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014C54;
        }
    }

label_80014BCC:
    ctx->pc = 0x80014BCCu;
    ctx->downcount -= 2;
    // 80014BCC: cmpwi   r31, -97
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(-97);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014BD0:
    ctx->pc = 0x80014BD0u;
    // 80014BD0: bc    12, 2, 0x80014BF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014BF8;
        }
    }

label_80014BD4:
    ctx->pc = 0x80014BD4u;
    ctx->downcount -= 2;
    // 80014BD4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014BD8:
    ctx->pc = 0x80014BD8u;
    // 80014BD8: addi    r30, r29, -27584
    ctx->gpr[30] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014BDC:
    ctx->pc = 0x80014BDCu;
    ctx->downcount -= 1;
    // 80014BDC: bl      0x8018FA60
    {
            ctx->lr = 0x80014BE0u;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014BE0:
    ctx->pc = 0x80014BE0u;
    ctx->downcount -= 6;
    // 80014BE0: lwz     r0, -27584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-27584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014BE4:
    ctx->pc = 0x80014BE4u;
    // 80014BE4: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014BE8:
    ctx->pc = 0x80014BE8u;
    // 80014BE8: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014BEC:
    ctx->pc = 0x80014BECu;
    // 80014BEC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014BF0:
    ctx->pc = 0x80014BF0u;
    // 80014BF0: stw     r0, -27584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-27584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014BF4:
    ctx->pc = 0x80014BF4u;
    // 80014BF4: b       0x80014C6C
    {
            goto label_80014C6C;
    }

label_80014BF8:
    ctx->pc = 0x80014BF8u;
    ctx->downcount -= 2;
    // 80014BF8: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014BFC:
    ctx->pc = 0x80014BFCu;
    // 80014BFC: bc    4, 2, 0x80014C24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014C24;
        }
    }

label_80014C00:
    ctx->pc = 0x80014C00u;
    ctx->downcount -= 3;
    // 80014C00: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014C04:
    ctx->pc = 0x80014C04u;
    // 80014C04: addi    r30, r29, -27584
    ctx->gpr[30] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014C08:
    ctx->pc = 0x80014C08u;
    // 80014C08: bl      0x8018FA60
    {
            ctx->lr = 0x80014C0Cu;
            ctx->pc = 0x8018FA60u;
            return;
    }

label_80014C0C:
    ctx->pc = 0x80014C0Cu;
    ctx->downcount -= 6;
    // 80014C0C: lwz     r0, -27584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-27584);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014C10:
    ctx->pc = 0x80014C10u;
    // 80014C10: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014C14:
    ctx->pc = 0x80014C14u;
    // 80014C14: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80014C18:
    ctx->pc = 0x80014C18u;
    // 80014C18: li      r3, -97
    ctx->gpr[3] = (u32)(s32)(-97);

label_80014C1C:
    ctx->pc = 0x80014C1Cu;
    // 80014C1C: stw     r0, -27584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-27584);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014C20:
    ctx->pc = 0x80014C20u;
    // 80014C20: b       0x80014C6C
    {
            goto label_80014C6C;
    }

label_80014C24:
    ctx->pc = 0x80014C24u;
    ctx->downcount -= 2;
    // 80014C24: addi    r3, r29, -27584
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014C28:
    ctx->pc = 0x80014C28u;
    // 80014C28: bl      0x80013FA0
    {
            ctx->lr = 0x80014C2Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013FA0u;
                return;
            }
            goto label_80013FA0;
    }

label_80014C2C:
    ctx->pc = 0x80014C2Cu;
    ctx->downcount -= 3;
    // 80014C2C: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014C30:
    ctx->pc = 0x80014C30u;
    // 80014C30: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014C34:
    ctx->pc = 0x80014C34u;
    // 80014C34: bc    12, 0, 0x80014C6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014C6C;
        }
    }

label_80014C38:
    ctx->pc = 0x80014C38u;
    ctx->downcount -= 2;
    // 80014C38: addi    r3, r29, -27584
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014C3C:
    ctx->pc = 0x80014C3Cu;
    // 80014C3C: bl      0x8001409C
    {
            ctx->lr = 0x80014C40u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8001409Cu;
                return;
            }
            goto label_8001409C;
    }

label_80014C40:
    ctx->pc = 0x80014C40u;
    ctx->downcount -= 3;
    // 80014C40: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014C44:
    ctx->pc = 0x80014C44u;
    // 80014C44: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014C48:
    ctx->pc = 0x80014C48u;
    // 80014C48: bc    12, 0, 0x80014C6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014C6C;
        }
    }

label_80014C4C:
    ctx->pc = 0x80014C4Cu;
    ctx->downcount -= 2;
    // 80014C4C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80014C50:
    ctx->pc = 0x80014C50u;
    // 80014C50: b       0x80014C6C
    {
            goto label_80014C6C;
    }

label_80014C54:
    ctx->pc = 0x80014C54u;
    ctx->downcount -= 2;
    // 80014C54: addi    r3, r29, -27584
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-27584);

label_80014C58:
    ctx->pc = 0x80014C58u;
    // 80014C58: bl      0x80013DDC
    {
            ctx->lr = 0x80014C5Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80013DDCu;
                return;
            }
            goto label_80013DDC;
    }

label_80014C5C:
    ctx->pc = 0x80014C5Cu;
    ctx->downcount -= 3;
    // 80014C5C: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80014C60:
    ctx->pc = 0x80014C60u;
    // 80014C60: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80014C64:
    ctx->pc = 0x80014C64u;
    // 80014C64: bc    12, 0, 0x80014C6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014C6C;
        }
    }

label_80014C68:
    ctx->pc = 0x80014C68u;
    ctx->downcount -= 1;
    // 80014C68: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_80014C6C:
    ctx->pc = 0x80014C6Cu;
    ctx->downcount -= 16;
    // 80014C6C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014C70:
    ctx->pc = 0x80014C70u;
    // 80014C70: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014C74:
    ctx->pc = 0x80014C74u;
    // 80014C74: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014C78:
    ctx->pc = 0x80014C78u;
    // 80014C78: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80014C7C:
    ctx->pc = 0x80014C7Cu;
    // 80014C7C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014C80:
    ctx->pc = 0x80014C80u;
    ctx->downcount -= 4;
    // 80014C80: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014C84:
    ctx->pc = 0x80014C84u;
    // 80014C84: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014C88:
    ctx->pc = 0x80014C88u;
    // 80014C88: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014C8C:
    ctx->pc = 0x80014C8Cu;
    // 80014C8C: bl      0x80014A8C
    {
            ctx->lr = 0x80014C90u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014A8Cu;
                return;
            }
            goto label_80014A8C;
    }

label_80014C90:
    ctx->pc = 0x80014C90u;
    ctx->downcount -= 5;
    // 80014C90: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014C94:
    ctx->pc = 0x80014C94u;
    // 80014C94: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014C98:
    ctx->pc = 0x80014C98u;
    // 80014C98: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80014C9C:
    ctx->pc = 0x80014C9Cu;
    // 80014C9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014CA0:
    ctx->pc = 0x80014CA0u;
    ctx->downcount -= 4;
    // 80014CA0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014CA4:
    ctx->pc = 0x80014CA4u;
    // 80014CA4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014CA8:
    ctx->pc = 0x80014CA8u;
    // 80014CA8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014CAC:
    ctx->pc = 0x80014CACu;
    // 80014CAC: bl      0x80014B68
    {
            ctx->lr = 0x80014CB0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014B68u;
                return;
            }
            goto label_80014B68;
    }

label_80014CB0:
    ctx->pc = 0x80014CB0u;
    ctx->downcount -= 5;
    // 80014CB0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014CB4:
    ctx->pc = 0x80014CB4u;
    // 80014CB4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014CB8:
    ctx->pc = 0x80014CB8u;
    // 80014CB8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80014CBC:
    ctx->pc = 0x80014CBCu;
    // 80014CBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014CC0:
    ctx->pc = 0x80014CC0u;
    ctx->downcount -= 4;
    // 80014CC0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014CC4:
    ctx->pc = 0x80014CC4u;
    // 80014CC4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014CC8:
    ctx->pc = 0x80014CC8u;
    // 80014CC8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014CCC:
    ctx->pc = 0x80014CCCu;
    // 80014CCC: bl      0x800149DC
    {
            ctx->lr = 0x80014CD0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800149DCu;
                return;
            }
            goto label_800149DC;
    }

label_80014CD0:
    ctx->pc = 0x80014CD0u;
    ctx->downcount -= 5;
    // 80014CD0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014CD4:
    ctx->pc = 0x80014CD4u;
    // 80014CD4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014CD8:
    ctx->pc = 0x80014CD8u;
    // 80014CD8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80014CDC:
    ctx->pc = 0x80014CDCu;
    // 80014CDC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014CE0:
    ctx->pc = 0x80014CE0u;
    ctx->downcount -= 4;
    // 80014CE0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014CE4:
    ctx->pc = 0x80014CE4u;
    // 80014CE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014CE8:
    ctx->pc = 0x80014CE8u;
    // 80014CE8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014CEC:
    ctx->pc = 0x80014CECu;
    // 80014CEC: bl      0x800149E4
    {
            ctx->lr = 0x80014CF0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800149E4u;
                return;
            }
            goto label_800149E4;
    }

label_80014CF0:
    ctx->pc = 0x80014CF0u;
    ctx->downcount -= 5;
    // 80014CF0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014CF4:
    ctx->pc = 0x80014CF4u;
    // 80014CF4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014CF8:
    ctx->pc = 0x80014CF8u;
    // 80014CF8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80014CFC:
    ctx->pc = 0x80014CFCu;
    // 80014CFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014D00:
    ctx->pc = 0x80014D00u;
    ctx->downcount -= 5;
    // 80014D00: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014D04:
    ctx->pc = 0x80014D04u;
    // 80014D04: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014D08:
    ctx->pc = 0x80014D08u;
    // 80014D08: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014D0C:
    ctx->pc = 0x80014D0Cu;
    // 80014D0C: cmpwi   r3, 1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014D10:
    ctx->pc = 0x80014D10u;
    // 80014D10: bc    12, 2, 0x80014D24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014D24;
        }
    }

label_80014D14:
    ctx->pc = 0x80014D14u;
    ctx->downcount -= 1;
    // 80014D14: bc    4, 1, 0x80014D54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014D54;
        }
    }

label_80014D18:
    ctx->pc = 0x80014D18u;
    ctx->downcount -= 2;
    // 80014D18: cmpwi   r3, 2
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014D1C:
    ctx->pc = 0x80014D1Cu;
    // 80014D1C: bc    12, 2, 0x80014D3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80014D3C;
        }
    }

label_80014D20:
    ctx->pc = 0x80014D20u;
    ctx->downcount -= 1;
    // 80014D20: b       0x80014D54
    {
            goto label_80014D54;
    }

label_80014D24:
    ctx->pc = 0x80014D24u;
    ctx->downcount -= 5;
    // 80014D24: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80014D28:
    ctx->pc = 0x80014D28u;
    // 80014D28: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014D2C:
    ctx->pc = 0x80014D2Cu;
    // 80014D2C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014D30:
    ctx->pc = 0x80014D30u;
    // 80014D30: li      r6, 12
    ctx->gpr[6] = (u32)(s32)(12);

label_80014D34:
    ctx->pc = 0x80014D34u;
    // 80014D34: bl      0x8019EECC
    {
            ctx->lr = 0x80014D38u;
            ctx->pc = 0x8019EECCu;
            return;
    }

label_80014D38:
    ctx->pc = 0x80014D38u;
    ctx->downcount -= 1;
    // 80014D38: b       0x80014D68
    {
            goto label_80014D68;
    }

label_80014D3C:
    ctx->pc = 0x80014D3Cu;
    ctx->downcount -= 5;
    // 80014D3C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014D40:
    ctx->pc = 0x80014D40u;
    // 80014D40: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80014D44:
    ctx->pc = 0x80014D44u;
    // 80014D44: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80014D48:
    ctx->pc = 0x80014D48u;
    // 80014D48: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80014D4C:
    ctx->pc = 0x80014D4Cu;
    // 80014D4C: bl      0x8019EECC
    {
            ctx->lr = 0x80014D50u;
            ctx->pc = 0x8019EECCu;
            return;
    }

label_80014D50:
    ctx->pc = 0x80014D50u;
    ctx->downcount -= 1;
    // 80014D50: b       0x80014D68
    {
            goto label_80014D68;
    }

label_80014D54:
    ctx->pc = 0x80014D54u;
    ctx->downcount -= 5;
    // 80014D54: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014D58:
    ctx->pc = 0x80014D58u;
    // 80014D58: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80014D5C:
    ctx->pc = 0x80014D5Cu;
    // 80014D5C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014D60:
    ctx->pc = 0x80014D60u;
    // 80014D60: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80014D64:
    ctx->pc = 0x80014D64u;
    // 80014D64: bl      0x8019EECC
    {
            ctx->lr = 0x80014D68u;
            ctx->pc = 0x8019EECCu;
            return;
    }

label_80014D68:
    ctx->pc = 0x80014D68u;
    ctx->downcount -= 5;
    // 80014D68: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014D6C:
    ctx->pc = 0x80014D6Cu;
    // 80014D6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014D70:
    ctx->pc = 0x80014D70u;
    // 80014D70: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80014D74:
    ctx->pc = 0x80014D74u;
    // 80014D74: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014D78:
    ctx->pc = 0x80014D78u;
    ctx->downcount -= 28;
    // 80014D78: stwu     r1, -88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-88);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014D7C:
    ctx->pc = 0x80014D7Cu;
    // 80014D7C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014D80:
    ctx->pc = 0x80014D80u;
    // 80014D80: stmw     r29, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014D84:
    ctx->pc = 0x80014D84u;
    // 80014D84: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014D88:
    ctx->pc = 0x80014D88u;
    // 80014D88: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80014D8C:
    ctx->pc = 0x80014D8Cu;
    // 80014D8C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80014D90:
    ctx->pc = 0x80014D90u;
    // 80014D90: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80014D94:
    ctx->pc = 0x80014D94u;
    // 80014D94: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80014D98:
    ctx->pc = 0x80014D98u;
    // 80014D98: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80014D9C:
    ctx->pc = 0x80014D9Cu;
    // 80014D9C: addi    r3, r3, -27520
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27520);

label_80014DA0:
    ctx->pc = 0x80014DA0u;
    // 80014DA0: addi    r4, r4, -8160
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-8160);

label_80014DA4:
    ctx->pc = 0x80014DA4u;
    // 80014DA4: li      r5, 64
    ctx->gpr[5] = (u32)(s32)(64);

label_80014DA8:
    ctx->pc = 0x80014DA8u;
    // 80014DA8: li      r6, 96
    ctx->gpr[6] = (u32)(s32)(96);

label_80014DAC:
    ctx->pc = 0x80014DACu;
    // 80014DAC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80014DB0:
    ctx->pc = 0x80014DB0u;
    // 80014DB0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80014DB4:
    ctx->pc = 0x80014DB4u;
    // 80014DB4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80014DB8:
    ctx->pc = 0x80014DB8u;
    // 80014DB8: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80014DBC:
    ctx->pc = 0x80014DBCu;
    // 80014DBC: bl      0x8019BE18
    {
            ctx->lr = 0x80014DC0u;
            ctx->pc = 0x8019BE18u;
            return;
    }

label_80014DC0:
    ctx->pc = 0x80014DC0u;
    ctx->downcount -= 2;
    // 80014DC0: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80014DC4:
    ctx->pc = 0x80014DC4u;
    // 80014DC4: bc    4, 2, 0x80014E00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80014E00;
        }
    }

label_80014DC8:
    ctx->pc = 0x80014DC8u;
    ctx->downcount -= 12;
    // 80014DC8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80014DCC:
    ctx->pc = 0x80014DCCu;
    // 80014DCC: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80014DD0:
    ctx->pc = 0x80014DD0u;
    // 80014DD0: lfs     f1, -20284(r9)
    if (!ppc_fp_available(ctx, 0x80014DD0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20284);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80014DD4:
    ctx->pc = 0x80014DD4u;
    // 80014DD4: addi    r3, r3, -27520
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27520);

label_80014DD8:
    ctx->pc = 0x80014DD8u;
    // 80014DD8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014DDC:
    ctx->pc = 0x80014DDCu;
    // 80014DDC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014DE0:
    ctx->pc = 0x80014DE0u;
    // 80014DE0: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80014DE0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80014DE4:
    ctx->pc = 0x80014DE4u;
    // 80014DE4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80014DE8:
    ctx->pc = 0x80014DE8u;
    // 80014DE8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80014DEC:
    ctx->pc = 0x80014DECu;
    // 80014DEC: fmr    f3, f2
    if (!ppc_fp_available(ctx, 0x80014DECu)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_80014DF0:
    ctx->pc = 0x80014DF0u;
    // 80014DF0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80014DF4:
    ctx->pc = 0x80014DF4u;
    // 80014DF4: bl      0x8019C0D4
    {
            ctx->lr = 0x80014DF8u;
            ctx->pc = 0x8019C0D4u;
            return;
    }

label_80014DF8:
    ctx->pc = 0x80014DF8u;
    ctx->downcount -= 2;
    // 80014DF8: stw     r31, -32520(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32520);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80014DFC:
    ctx->pc = 0x80014DFCu;
    // 80014DFC: b       0x80014E08
    {
            goto label_80014E08;
    }

label_80014E00:
    ctx->pc = 0x80014E00u;
    ctx->downcount -= 2;
    // 80014E00: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80014E04:
    ctx->pc = 0x80014E04u;
    // 80014E04: stw     r0, -32520(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32520);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014E08:
    ctx->pc = 0x80014E08u;
    ctx->downcount -= 4;
    // 80014E08: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80014E0C:
    ctx->pc = 0x80014E0Cu;
    // 80014E0C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014E10:
    ctx->pc = 0x80014E10u;
    // 80014E10: addi    r3, r3, -27520
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27520);

label_80014E14:
    ctx->pc = 0x80014E14u;
    // 80014E14: bl      0x8019C740
    {
            ctx->lr = 0x80014E18u;
            ctx->pc = 0x8019C740u;
            return;
    }

label_80014E18:
    ctx->pc = 0x80014E18u;
    ctx->downcount -= 54;
    // 80014E18: li      r0, 64
    ctx->gpr[0] = (u32)(s32)(64);

label_80014E1C:
    ctx->pc = 0x80014E1Cu;
    // 80014E1C: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014E20:
    ctx->pc = 0x80014E20u;
    // 80014E20: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_80014E24:
    ctx->pc = 0x80014E24u;
    // 80014E24: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80014E28:
    ctx->pc = 0x80014E28u;
    // 80014E28: li      r0, 96
    ctx->gpr[0] = (u32)(s32)(96);

label_80014E2C:
    ctx->pc = 0x80014E2Cu;
    // 80014E2C: stw     r7, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80014E30:
    ctx->pc = 0x80014E30u;
    // 80014E30: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80014E34:
    ctx->pc = 0x80014E34u;
    // 80014E34: lfd     f0, -20280(r10)
    if (!ppc_fp_available(ctx, 0x80014E34u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-20280);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80014E38:
    ctx->pc = 0x80014E38u;
    // 80014E38: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_80014E3C:
    ctx->pc = 0x80014E3Cu;
    // 80014E3C: lfd     f1, 64(r1)
    if (!ppc_fp_available(ctx, 0x80014E3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80014E40:
    ctx->pc = 0x80014E40u;
    // 80014E40: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80014E44:
    ctx->pc = 0x80014E44u;
    // 80014E44: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014E48:
    ctx->pc = 0x80014E48u;
    // 80014E48: lfs     f3, -20272(r8)
    if (!ppc_fp_available(ctx, 0x80014E48u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-20272);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_80014E4C:
    ctx->pc = 0x80014E4Cu;
    // 80014E4C: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x80014E4Cu)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_80014E50:
    ctx->pc = 0x80014E50u;
    // 80014E50: stw     r7, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80014E54:
    ctx->pc = 0x80014E54u;
    // 80014E54: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x80014E54u)) return;
    ppc_frsp(ctx, 1, 1);

label_80014E58:
    ctx->pc = 0x80014E58u;
    // 80014E58: fdivs   f1, f3, f1
    if (!ppc_fp_available(ctx, 0x80014E58u)) return;
    ppc_fdivs(ctx, 1, 3, 1);

label_80014E5C:
    ctx->pc = 0x80014E5Cu;
    // 80014E5C: lfd     f2, 64(r1)
    if (!ppc_fp_available(ctx, 0x80014E5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80014E60:
    ctx->pc = 0x80014E60u;
    // 80014E60: fsub   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x80014E60u)) return;
    ppc_fsub(ctx, 2, 2, 0);

label_80014E64:
    ctx->pc = 0x80014E64u;
    // 80014E64: frsp    f2, f2
    if (!ppc_fp_available(ctx, 0x80014E64u)) return;
    ppc_frsp(ctx, 2, 2);

label_80014E68:
    ctx->pc = 0x80014E68u;
    // 80014E68: fdivs   f2, f3, f2
    if (!ppc_fp_available(ctx, 0x80014E68u)) return;
    ppc_fdivs(ctx, 2, 3, 2);

label_80014E6C:
    ctx->pc = 0x80014E6Cu;
    // 80014E6C: bl      0x8017C0F4
    {
            ctx->lr = 0x80014E70u;
            ctx->pc = 0x8017C0F4u;
            return;
    }

label_80014E70:
    ctx->pc = 0x80014E70u;
    ctx->downcount -= 4;
    // 80014E70: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014E74:
    ctx->pc = 0x80014E74u;
    // 80014E74: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80014E78:
    ctx->pc = 0x80014E78u;
    // 80014E78: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80014E7C:
    ctx->pc = 0x80014E7Cu;
    // 80014E7C: bl      0x8019FB20
    {
            ctx->lr = 0x80014E80u;
            ctx->pc = 0x8019FB20u;
            return;
    }

label_80014E80:
    ctx->pc = 0x80014E80u;
    ctx->downcount -= 2;
    // 80014E80: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014E84:
    ctx->pc = 0x80014E84u;
    // 80014E84: bl      0x80199104
    {
            ctx->lr = 0x80014E88u;
            ctx->pc = 0x80199104u;
            return;
    }

label_80014E88:
    ctx->pc = 0x80014E88u;
    ctx->downcount -= 7;
    // 80014E88: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80014E8C:
    ctx->pc = 0x80014E8Cu;
    // 80014E8C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014E90:
    ctx->pc = 0x80014E90u;
    // 80014E90: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80014E94:
    ctx->pc = 0x80014E94u;
    // 80014E94: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80014E98:
    ctx->pc = 0x80014E98u;
    // 80014E98: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80014E9C:
    ctx->pc = 0x80014E9Cu;
    // 80014E9C: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_80014EA0:
    ctx->pc = 0x80014EA0u;
    // 80014EA0: bl      0x80198E34
    {
            ctx->lr = 0x80014EA4u;
            ctx->pc = 0x80198E34u;
            return;
    }

label_80014EA4:
    ctx->pc = 0x80014EA4u;
    ctx->downcount -= 16;
    // 80014EA4: lwz     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014EA8:
    ctx->pc = 0x80014EA8u;
    // 80014EA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014EAC:
    ctx->pc = 0x80014EACu;
    // 80014EAC: lmw     r29, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014EB0:
    ctx->pc = 0x80014EB0u;
    // 80014EB0: addi    r1, r1, 88
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(88);

label_80014EB4:
    ctx->pc = 0x80014EB4u;
    // 80014EB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014EB8:
    ctx->pc = 0x80014EB8u;
    ctx->downcount -= 38;
    // 80014EB8: stwu     r1, -136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-136);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014EBC:
    ctx->pc = 0x80014EBCu;
    // 80014EBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014EC0:
    ctx->pc = 0x80014EC0u;
    // 80014EC0: stmw     r30, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014EC4:
    ctx->pc = 0x80014EC4u;
    // 80014EC4: stw     r0, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014EC8:
    ctx->pc = 0x80014EC8u;
    // 80014EC8: xoris   r4, r4, 0x8000
    ctx->gpr[4] = ctx->gpr[4] ^ (0x8000u << 16);

label_80014ECC:
    ctx->pc = 0x80014ECCu;
    // 80014ECC: stw     r4, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80014ED0:
    ctx->pc = 0x80014ED0u;
    // 80014ED0: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_80014ED4:
    ctx->pc = 0x80014ED4u;
    // 80014ED4: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80014ED8:
    ctx->pc = 0x80014ED8u;
    // 80014ED8: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_80014EDC:
    ctx->pc = 0x80014EDCu;
    // 80014EDC: stw     r0, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014EE0:
    ctx->pc = 0x80014EE0u;
    // 80014EE0: fneg    f6, f1
    if (!ppc_fp_available(ctx, 0x80014EE0u)) return;
    ctx->fpr[6] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_80014EE4:
    ctx->pc = 0x80014EE4u;
    // 80014EE4: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_80014EE8:
    ctx->pc = 0x80014EE8u;
    // 80014EE8: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_80014EEC:
    ctx->pc = 0x80014EECu;
    // 80014EEC: lfd     f2, 120(r1)
    if (!ppc_fp_available(ctx, 0x80014EECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80014EF0:
    ctx->pc = 0x80014EF0u;
    // 80014EF0: addi    r30, r1, 72
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(72);

label_80014EF4:
    ctx->pc = 0x80014EF4u;
    // 80014EF4: stw     r3, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80014EF8:
    ctx->pc = 0x80014EF8u;
    // 80014EF8: lfd     f0, -20264(r8)
    if (!ppc_fp_available(ctx, 0x80014EF8u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-20264);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80014EFC:
    ctx->pc = 0x80014EFCu;
    // 80014EFC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80014F00:
    ctx->pc = 0x80014F00u;
    // 80014F00: stw     r0, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014F04:
    ctx->pc = 0x80014F04u;
    // 80014F04: lfs     f1, -20256(r11)
    if (!ppc_fp_available(ctx, 0x80014F04u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-20256);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80014F08:
    ctx->pc = 0x80014F08u;
    // 80014F08: fsub   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x80014F08u)) return;
    ppc_fsub(ctx, 2, 2, 0);

label_80014F0C:
    ctx->pc = 0x80014F0Cu;
    // 80014F0C: lfd     f4, 120(r1)
    if (!ppc_fp_available(ctx, 0x80014F0Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80014F10:
    ctx->pc = 0x80014F10u;
    // 80014F10: frsp    f2, f2
    if (!ppc_fp_available(ctx, 0x80014F10u)) return;
    ppc_frsp(ctx, 2, 2);

label_80014F14:
    ctx->pc = 0x80014F14u;
    // 80014F14: fmr    f3, f1
    if (!ppc_fp_available(ctx, 0x80014F14u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_80014F18:
    ctx->pc = 0x80014F18u;
    // 80014F18: fsub   f4, f4, f0
    if (!ppc_fp_available(ctx, 0x80014F18u)) return;
    ppc_fsub(ctx, 4, 4, 0);

label_80014F1C:
    ctx->pc = 0x80014F1Cu;
    // 80014F1C: fmr    f5, f3
    if (!ppc_fp_available(ctx, 0x80014F1Cu)) return;
    ctx->fpr[5] = ctx->fpr[3];

label_80014F20:
    ctx->pc = 0x80014F20u;
    // 80014F20: frsp    f4, f4
    if (!ppc_fp_available(ctx, 0x80014F20u)) return;
    ppc_frsp(ctx, 4, 4);

label_80014F24:
    ctx->pc = 0x80014F24u;
    // 80014F24: bl      0x8017D06C
    {
            ctx->lr = 0x80014F28u;
            ctx->pc = 0x8017D06Cu;
            return;
    }

label_80014F28:
    ctx->pc = 0x80014F28u;
    ctx->downcount -= 3;
    // 80014F28: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80014F2C:
    ctx->pc = 0x80014F2Cu;
    // 80014F2C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80014F30:
    ctx->pc = 0x80014F30u;
    // 80014F30: bl      0x8019F6E4
    {
            ctx->lr = 0x80014F34u;
            ctx->pc = 0x8019F6E4u;
            return;
    }

label_80014F34:
    ctx->pc = 0x80014F34u;
    ctx->downcount -= 2;
    // 80014F34: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014F38:
    ctx->pc = 0x80014F38u;
    // 80014F38: bl      0x8017AF38
    {
            ctx->lr = 0x80014F3Cu;
            ctx->pc = 0x8017AF38u;
            return;
    }

label_80014F3C:
    ctx->pc = 0x80014F3Cu;
    ctx->downcount -= 3;
    // 80014F3C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014F40:
    ctx->pc = 0x80014F40u;
    // 80014F40: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014F44:
    ctx->pc = 0x80014F44u;
    // 80014F44: bl      0x8019F9C4
    {
            ctx->lr = 0x80014F48u;
            ctx->pc = 0x8019F9C4u;
            return;
    }

label_80014F48:
    ctx->pc = 0x80014F48u;
    ctx->downcount -= 2;
    // 80014F48: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014F4C:
    ctx->pc = 0x80014F4Cu;
    // 80014F4C: bl      0x8019FAE4
    {
            ctx->lr = 0x80014F50u;
            ctx->pc = 0x8019FAE4u;
            return;
    }

label_80014F50:
    ctx->pc = 0x80014F50u;
    ctx->downcount -= 16;
    // 80014F50: lwz     r0, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014F54:
    ctx->pc = 0x80014F54u;
    // 80014F54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014F58:
    ctx->pc = 0x80014F58u;
    // 80014F58: lmw     r30, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014F5C:
    ctx->pc = 0x80014F5Cu;
    // 80014F5C: addi    r1, r1, 136
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(136);

label_80014F60:
    ctx->pc = 0x80014F60u;
    // 80014F60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014F64:
    ctx->pc = 0x80014F64u;
    ctx->downcount -= 20;
    // 80014F64: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014F68:
    ctx->pc = 0x80014F68u;
    // 80014F68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80014F6C:
    ctx->pc = 0x80014F6Cu;
    // 80014F6C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80014F70:
    ctx->pc = 0x80014F70u;
    // 80014F70: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80014F74:
    ctx->pc = 0x80014F74u;
    // 80014F74: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80014F78:
    ctx->pc = 0x80014F78u;
    // 80014F78: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80014F7C:
    ctx->pc = 0x80014F7Cu;
    // 80014F7C: lfs     f1, -20252(r9)
    if (!ppc_fp_available(ctx, 0x80014F7Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20252);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80014F80:
    ctx->pc = 0x80014F80u;
    // 80014F80: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80014F84:
    ctx->pc = 0x80014F84u;
    // 80014F84: or   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80014F88:
    ctx->pc = 0x80014F88u;
    // 80014F88: bl      0x80014EB8
    {
            ctx->lr = 0x80014F8Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014EB8u;
                return;
            }
            goto label_80014EB8;
    }

label_80014F8C:
    ctx->pc = 0x80014F8Cu;
    ctx->downcount -= 4;
    // 80014F8C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80014F90:
    ctx->pc = 0x80014F90u;
    // 80014F90: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80014F94:
    ctx->pc = 0x80014F94u;
    // 80014F94: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014F98:
    ctx->pc = 0x80014F98u;
    // 80014F98: bl      0x8019F050
    {
            ctx->lr = 0x80014F9Cu;
            ctx->pc = 0x8019F050u;
            return;
    }

label_80014F9C:
    ctx->pc = 0x80014F9Cu;
    ctx->downcount -= 2;
    // 80014F9C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014FA0:
    ctx->pc = 0x80014FA0u;
    // 80014FA0: bl      0x8019B960
    {
            ctx->lr = 0x80014FA4u;
            ctx->pc = 0x8019B960u;
            return;
    }

label_80014FA4:
    ctx->pc = 0x80014FA4u;
    ctx->downcount -= 2;
    // 80014FA4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80014FA8:
    ctx->pc = 0x80014FA8u;
    // 80014FA8: bl      0x8019EA20
    {
            ctx->lr = 0x80014FACu;
            ctx->pc = 0x8019EA20u;
            return;
    }

label_80014FAC:
    ctx->pc = 0x80014FACu;
    ctx->downcount -= 3;
    // 80014FAC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014FB0:
    ctx->pc = 0x80014FB0u;
    // 80014FB0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80014FB4:
    ctx->pc = 0x80014FB4u;
    // 80014FB4: bl      0x8019E018
    {
            ctx->lr = 0x80014FB8u;
            ctx->pc = 0x8019E018u;
            return;
    }

label_80014FB8:
    ctx->pc = 0x80014FB8u;
    ctx->downcount -= 5;
    // 80014FB8: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80014FBC:
    ctx->pc = 0x80014FBCu;
    // 80014FBC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014FC0:
    ctx->pc = 0x80014FC0u;
    // 80014FC0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80014FC4:
    ctx->pc = 0x80014FC4u;
    // 80014FC4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014FC8:
    ctx->pc = 0x80014FC8u;
    // 80014FC8: bl      0x8019E844
    {
            ctx->lr = 0x80014FCCu;
            ctx->pc = 0x8019E844u;
            return;
    }

label_80014FCC:
    ctx->pc = 0x80014FCCu;
    ctx->downcount -= 4;
    // 80014FCC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80014FD0:
    ctx->pc = 0x80014FD0u;
    // 80014FD0: li      r4, 30
    ctx->gpr[4] = (u32)(s32)(30);

label_80014FD4:
    ctx->pc = 0x80014FD4u;
    // 80014FD4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80014FD8:
    ctx->pc = 0x80014FD8u;
    // 80014FD8: bl      0x80014D78
    {
            ctx->lr = 0x80014FDCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014D78u;
                return;
            }
            goto label_80014D78;
    }

label_80014FDC:
    ctx->pc = 0x80014FDCu;
    ctx->downcount -= 2;
    // 80014FDC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80014FE0:
    ctx->pc = 0x80014FE0u;
    // 80014FE0: bl      0x80014D00
    {
            ctx->lr = 0x80014FE4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014D00u;
                return;
            }
            goto label_80014D00;
    }

label_80014FE4:
    ctx->pc = 0x80014FE4u;
    ctx->downcount -= 16;
    // 80014FE4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80014FE8:
    ctx->pc = 0x80014FE8u;
    // 80014FE8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80014FEC:
    ctx->pc = 0x80014FECu;
    // 80014FEC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80014FF0:
    ctx->pc = 0x80014FF0u;
    // 80014FF0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80014FF4:
    ctx->pc = 0x80014FF4u;
    // 80014FF4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80014FF8:
    ctx->pc = 0x80014FF8u;
    ctx->downcount -= 21;
    // 80014FF8: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80014FFC:
    ctx->pc = 0x80014FFCu;
    // 80014FFC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015000:
    ctx->pc = 0x80015000u;
    // 80015000: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_80015004:
    ctx->pc = 0x80015004u;
    // 80015004: stmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80015008:
    ctx->pc = 0x80015008u;
    // 80015008: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001500C:
    ctx->pc = 0x8001500Cu;
    // 8001500C: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80015010:
    ctx->pc = 0x80015010u;
    // 80015010: or   r26, r6, r6
    {
        ctx->gpr[26] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80015014:
    ctx->pc = 0x80015014u;
    // 80015014: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80015018:
    ctx->pc = 0x80015018u;
    // 80015018: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8001501C:
    ctx->pc = 0x8001501Cu;
    // 8001501C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80015020:
    ctx->pc = 0x80015020u;
    // 80015020: bl      0x8019831C
    {
            ctx->lr = 0x80015024u;
            ctx->pc = 0x8019831Cu;
            return;
    }

label_80015024:
    ctx->pc = 0x80015024u;
    ctx->downcount -= 4;
    // 80015024: or   r27, r26, r26
    {
        ctx->gpr[27] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80015028:
    ctx->pc = 0x80015028u;
    // 80015028: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_8001502C:
    ctx->pc = 0x8001502Cu;
    // 8001502C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80015030:
    ctx->pc = 0x80015030u;
    // 80015030: bl      0x801978AC
    {
            ctx->lr = 0x80015034u;
            ctx->pc = 0x801978ACu;
            return;
    }

label_80015034:
    ctx->pc = 0x80015034u;
    ctx->downcount -= 4;
    // 80015034: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80015038:
    ctx->pc = 0x80015038u;
    // 80015038: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_8001503C:
    ctx->pc = 0x8001503Cu;
    // 8001503C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80015040:
    ctx->pc = 0x80015040u;
    // 80015040: bl      0x801978AC
    {
            ctx->lr = 0x80015044u;
            ctx->pc = 0x801978ACu;
            return;
    }

label_80015044:
    ctx->pc = 0x80015044u;
    ctx->downcount -= 6;
    // 80015044: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015048:
    ctx->pc = 0x80015048u;
    // 80015048: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_8001504C:
    ctx->pc = 0x8001504Cu;
    // 8001504C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015050:
    ctx->pc = 0x80015050u;
    // 80015050: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80015054:
    ctx->pc = 0x80015054u;
    // 80015054: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80015058:
    ctx->pc = 0x80015058u;
    // 80015058: bl      0x80198368
    {
            ctx->lr = 0x8001505Cu;
            ctx->pc = 0x80198368u;
            return;
    }

label_8001505C:
    ctx->pc = 0x8001505Cu;
    ctx->downcount -= 6;
    // 8001505C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015060:
    ctx->pc = 0x80015060u;
    // 80015060: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80015064:
    ctx->pc = 0x80015064u;
    // 80015064: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015068:
    ctx->pc = 0x80015068u;
    // 80015068: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_8001506C:
    ctx->pc = 0x8001506Cu;
    // 8001506C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80015070:
    ctx->pc = 0x80015070u;
    // 80015070: bl      0x80198368
    {
            ctx->lr = 0x80015074u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80015074:
    ctx->pc = 0x80015074u;
    ctx->downcount -= 6;
    // 80015074: lbz     r9, 0(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_80015078:
    // 80015078: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_8001507C:
    // 8001507C: extsb r9, r9
    {
        ctx->gpr[9] = (u32)(s32)(s8)ctx->gpr[9];
    }

label_80015080:
    // 80015080: addi    r0, r9, -32
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-32);

label_80015084:
    // 80015084: cmplwi  r0, 0x005F
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x005Fu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015088:
    // 80015088: bc    12, 1, 0x80015094
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80015094;
        }
    }

label_8001508C:
    ctx->downcount -= 2;
    // 8001508C: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_80015090:
    // 80015090: b       0x80015074
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015074u;
                return;
            }
            goto label_80015074;
    }

label_80015094:
    ctx->downcount -= 3;
    // 80015094: cmpwi   cr4, r9, 10
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_80015098:
    // 80015098: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001509C:
    // 8001509C: bc    4, 1, 0x80015194
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015194;
        }
    }

label_800150A0:
    ctx->downcount -= 4;
    // 800150A0: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_800150A4:
    // 800150A4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800150A8:
    // 800150A8: rlwinm r5, r28, 2, 16, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[28], 2u) & 0x0000FFFCu;
    }

label_800150AC:
    // 800150AC: bl      0x80199D18
    {
            ctx->lr = 0x800150B0u;
            ctx->pc = 0x80199D18u;
            return;
    }

label_800150B0:
    ctx->downcount -= 3;
    // 800150B0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800150B4:
    // 800150B4: cmpw    r3, r28
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800150B8:
    // 800150B8: bc    4, 0, 0x80015190
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015190;
        }
    }

label_800150BC:
    ctx->downcount -= 6;
    // 800150BC: addi    r0, r30, 8
    ctx->gpr[0] = ctx->gpr[30] + (u32)(s32)(8);

label_800150C0:
    ctx->pc = 0x800150C0u;
    // 800150C0: lwz     r31, -32520(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32520);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800150C4:
    // 800150C4: extsh r12, r0
    {
        ctx->gpr[12] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_800150C8:
    // 800150C8: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_800150CC:
    // 800150CC: addi    r4, r25, 8
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(8);

label_800150D0:
    // 800150D0: or   r5, r25, r25
    {
        ctx->gpr[5] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800150D4:
    ctx->pc = 0x800150D4u;
    ctx->downcount -= 6;
    // 800150D4: lbzx    r0, r26, r3
    {
        u32 ea = ctx->gpr[26] + ctx->gpr[3];
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800150D8:
    // 800150D8: extsb r9, r0
    {
        ctx->gpr[9] = (u32)(s32)(s8)ctx->gpr[0];
    }

label_800150DC:
    // 800150DC: addi    r0, r9, -32
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-32);

label_800150E0:
    // 800150E0: or   r11, r0, r0
    {
        ctx->gpr[11] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800150E4:
    // 800150E4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800150E8:
    // 800150E8: bc    4, 0, 0x800150F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800150F0;
        }
    }

label_800150EC:
    ctx->downcount -= 1;
    // 800150EC: addi    r11, r9, -25
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-25);

label_800150F0:
    ctx->downcount -= 40;
    // 800150F0: srawi r11, r11, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[11];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[11] = value;
        } else if (sh > 31) {
            ctx->gpr[11] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[11] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800150F4:
    // 800150F4: extsh r7, r5
    {
        ctx->gpr[7] = (u32)(s32)(s16)ctx->gpr[5];
    }

label_800150F8:
    // 800150F8: rlwinm r9, r11, 3, 0, 28
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[11], 3u) & 0xFFFFFFF8u;
    }

label_800150FC:
    ctx->pc = 0x800150FCu;
    // 800150FC: sth     r7, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_80015100:
    // 80015100: subf   r9, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_80015104:
    ctx->pc = 0x80015104u;
    // 80015104: sth     r30, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_80015108:
    // 80015108: rlwinm r9, r9, 4, 0, 27
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 4u) & 0xFFFFFFF0u;
    }

label_8001510C:
    // 8001510C: rlwinm r11, r11, 4, 0, 27
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 4u) & 0xFFFFFFF0u;
    }

label_80015110:
    // 80015110: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80015114:
    ctx->pc = 0x80015114u;
    // 80015114: sth     r29, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[29]);
    }

label_80015118:
    // 80015118: extsh r8, r9
    {
        ctx->gpr[8] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_8001511C:
    // 8001511C: add   r11, r11, r31
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80015120:
    ctx->pc = 0x80015120u;
    // 80015120: sth     r8, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_80015124:
    // 80015124: extsh r0, r11
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[11];
    }

label_80015128:
    ctx->pc = 0x80015128u;
    // 80015128: sth     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8001512C:
    // 8001512C: extsh r10, r4
    {
        ctx->gpr[10] = (u32)(s32)(s16)ctx->gpr[4];
    }

label_80015130:
    ctx->pc = 0x80015130u;
    // 80015130: sth     r10, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_80015134:
    // 80015134: addi    r9, r9, 16
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(16);

label_80015138:
    ctx->pc = 0x80015138u;
    // 80015138: sth     r30, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_8001513C:
    // 8001513C: extsh r9, r9
    {
        ctx->gpr[9] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_80015140:
    ctx->pc = 0x80015140u;
    // 80015140: sth     r29, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[29]);
    }

label_80015144:
    // 80015144: addi    r11, r11, 16
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(16);

label_80015148:
    ctx->pc = 0x80015148u;
    // 80015148: sth     r9, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_8001514C:
    // 8001514C: extsh r11, r11
    {
        ctx->gpr[11] = (u32)(s32)(s16)ctx->gpr[11];
    }

label_80015150:
    ctx->pc = 0x80015150u;
    // 80015150: sth     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80015154:
    // 80015154: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80015158:
    ctx->pc = 0x80015158u;
    // 80015158: sth     r10, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_8001515C:
    // 8001515C: addi    r4, r4, 8
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(8);

label_80015160:
    ctx->pc = 0x80015160u;
    // 80015160: sth     r12, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[12]);
    }

label_80015164:
    // 80015164: addi    r5, r5, 8
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(8);

label_80015168:
    ctx->pc = 0x80015168u;
    // 80015168: sth     r29, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[29]);
    }

label_8001516C:
    // 8001516C: cmpw    r3, r28
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[28]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015170:
    ctx->pc = 0x80015170u;
    // 80015170: sth     r9, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_80015174:
    ctx->pc = 0x80015174u;
    // 80015174: sth     r11, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_80015178:
    ctx->pc = 0x80015178u;
    // 80015178: sth     r7, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8001517C:
    ctx->pc = 0x8001517Cu;
    // 8001517C: sth     r12, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[12]);
    }

label_80015180:
    ctx->pc = 0x80015180u;
    // 80015180: sth     r29, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[29]);
    }

label_80015184:
    ctx->pc = 0x80015184u;
    // 80015184: sth     r8, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_80015188:
    ctx->pc = 0x80015188u;
    // 80015188: sth     r11, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_8001518C:
    // 8001518C: bc    12, 0, 0x800150D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800150D4u;
                return;
            }
            goto label_800150D4;
        }
    }

label_80015190:
    ctx->downcount -= 1;
    // 80015190: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80015194:
    ctx->downcount -= 2;
    // 80015194: or   r26, r27, r27
    {
        ctx->gpr[26] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80015198:
    // 80015198: bc    4, 18, 0x800151A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800151A8;
        }
    }

label_8001519C:
    ctx->downcount -= 3;
    // 8001519C: addi    r0, r30, 8
    ctx->gpr[0] = ctx->gpr[30] + (u32)(s32)(8);

label_800151A0:
    // 800151A0: extsh r30, r0
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_800151A4:
    // 800151A4: b       0x80015074
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015074u;
                return;
            }
            goto label_80015074;
    }

label_800151A8:
    ctx->pc = 0x800151A8u;
    ctx->downcount -= 18;
    // 800151A8: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800151AC:
    ctx->pc = 0x800151ACu;
    // 800151AC: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_800151B0:
    ctx->pc = 0x800151B0u;
    // 800151B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800151B4:
    ctx->pc = 0x800151B4u;
    // 800151B4: lmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800151B8:
    ctx->pc = 0x800151B8u;
    // 800151B8: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_800151BC:
    ctx->pc = 0x800151BCu;
    // 800151BC: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800151C0:
    ctx->pc = 0x800151C0u;
    // 800151C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800151C4:
    ctx->pc = 0x800151C4u;
    ctx->downcount -= 28;
    // 800151C4: stwu     r1, -416(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-416);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800151C8:
    ctx->pc = 0x800151C8u;
    // 800151C8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800151CC:
    ctx->pc = 0x800151CCu;
    // 800151CC: stmw     r28, 400(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800151D0:
    ctx->pc = 0x800151D0u;
    // 800151D0: stw     r0, 420(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800151D4:
    ctx->pc = 0x800151D4u;
    // 800151D4: lis     r12, 1024
    ctx->gpr[12] = ((u32)(s32)(1024) << 16);

label_800151D8:
    ctx->pc = 0x800151D8u;
    // 800151D8: addi    r0, r1, 424
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(424);

label_800151DC:
    ctx->pc = 0x800151DCu;
    // 800151DC: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_800151E0:
    ctx->pc = 0x800151E0u;
    // 800151E0: stw     r0, 388(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800151E4:
    ctx->pc = 0x800151E4u;
    // 800151E4: stw     r11, 392(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800151E8:
    ctx->pc = 0x800151E8u;
    // 800151E8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800151EC:
    ctx->pc = 0x800151ECu;
    // 800151EC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800151F0:
    ctx->pc = 0x800151F0u;
    // 800151F0: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_800151F4:
    ctx->pc = 0x800151F4u;
    // 800151F4: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800151F8:
    ctx->pc = 0x800151F8u;
    // 800151F8: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800151FC:
    ctx->pc = 0x800151FCu;
    // 800151FC: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80015200:
    ctx->pc = 0x80015200u;
    // 80015200: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80015204:
    ctx->pc = 0x80015204u;
    // 80015204: stw     r12, 384(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80015208:
    ctx->pc = 0x80015208u;
    // 80015208: bc    4, 6, 0x8001522C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001522C;
        }
    }

label_8001520C:
    ctx->pc = 0x8001520Cu;
    ctx->downcount -= 8;
    // 8001520C: stfd     f1, 40(r1)
    if (!ppc_fp_available(ctx, 0x8001520Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_80015210:
    ctx->pc = 0x80015210u;
    // 80015210: stfd     f2, 48(r1)
    if (!ppc_fp_available(ctx, 0x80015210u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_80015214:
    ctx->pc = 0x80015214u;
    // 80015214: stfd     f3, 56(r1)
    if (!ppc_fp_available(ctx, 0x80015214u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_80015218:
    ctx->pc = 0x80015218u;
    // 80015218: stfd     f4, 64(r1)
    if (!ppc_fp_available(ctx, 0x80015218u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_8001521C:
    ctx->pc = 0x8001521Cu;
    // 8001521C: stfd     f5, 72(r1)
    if (!ppc_fp_available(ctx, 0x8001521Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_80015220:
    ctx->pc = 0x80015220u;
    // 80015220: stfd     f6, 80(r1)
    if (!ppc_fp_available(ctx, 0x80015220u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_80015224:
    ctx->pc = 0x80015224u;
    // 80015224: stfd     f7, 88(r1)
    if (!ppc_fp_available(ctx, 0x80015224u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_80015228:
    ctx->pc = 0x80015228u;
    // 80015228: stfd     f8, 96(r1)
    if (!ppc_fp_available(ctx, 0x80015228u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_8001522C:
    ctx->pc = 0x8001522Cu;
    ctx->downcount -= 12;
    // 8001522C: addi    r11, r1, 384
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(384);

label_80015230:
    ctx->pc = 0x80015230u;
    // 80015230: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_80015234:
    ctx->pc = 0x80015234u;
    // 80015234: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80015238:
    ctx->pc = 0x80015238u;
    // 80015238: addi    r30, r1, 128
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(128);

label_8001523C:
    ctx->pc = 0x8001523Cu;
    // 8001523C: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015240:
    ctx->pc = 0x80015240u;
    // 80015240: or   r4, r6, r6
    {
        ctx->gpr[4] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80015244:
    ctx->pc = 0x80015244u;
    // 80015244: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80015248:
    ctx->pc = 0x80015248u;
    // 80015248: or   r5, r9, r9
    {
        ctx->gpr[5] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8001524C:
    ctx->pc = 0x8001524Cu;
    // 8001524C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015250:
    ctx->pc = 0x80015250u;
    // 80015250: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015254:
    ctx->pc = 0x80015254u;
    // 80015254: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80015258:
    ctx->pc = 0x80015258u;
    // 80015258: bl      0x80169514
    {
            ctx->lr = 0x8001525Cu;
            ctx->pc = 0x80169514u;
            return;
    }

label_8001525C:
    ctx->pc = 0x8001525Cu;
    ctx->downcount -= 5;
    // 8001525C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80015260:
    ctx->pc = 0x80015260u;
    // 80015260: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015264:
    ctx->pc = 0x80015264u;
    // 80015264: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80015268:
    ctx->pc = 0x80015268u;
    // 80015268: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8001526C:
    ctx->pc = 0x8001526Cu;
    // 8001526C: bl      0x80014FF8
    {
            ctx->lr = 0x80015270u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014FF8u;
                return;
            }
            goto label_80014FF8;
    }

label_80015270:
    ctx->pc = 0x80015270u;
    ctx->downcount -= 16;
    // 80015270: lwz     r0, 420(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015274:
    ctx->pc = 0x80015274u;
    // 80015274: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015278:
    ctx->pc = 0x80015278u;
    // 80015278: lmw     r28, 400(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8001527C:
    ctx->pc = 0x8001527Cu;
    // 8001527C: addi    r1, r1, 416
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(416);

label_80015280:
    ctx->pc = 0x80015280u;
    // 80015280: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015284:
    ctx->pc = 0x80015284u;
    ctx->downcount -= 4;
    // 80015284: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80015288:
    ctx->pc = 0x80015288u;
    // 80015288: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001528C:
    ctx->pc = 0x8001528Cu;
    // 8001528C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015290:
    ctx->pc = 0x80015290u;
    // 80015290: bl      0x801730B0
    {
            ctx->lr = 0x80015294u;
            ctx->pc = 0x801730B0u;
            return;
    }

label_80015294:
    ctx->pc = 0x80015294u;
    ctx->downcount -= 2;
    // 80015294: cmpwi   r3, 1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015298:
    ctx->pc = 0x80015298u;
    // 80015298: bc    4, 2, 0x800152B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800152B4;
        }
    }

label_8001529C:
    ctx->pc = 0x8001529Cu;
    ctx->downcount -= 6;
    // 8001529C: lis     r3, 18
    ctx->gpr[3] = ((u32)(s32)(18) << 16);

label_800152A0:
    ctx->pc = 0x800152A0u;
    // 800152A0: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_800152A4:
    ctx->pc = 0x800152A4u;
    // 800152A4: lwz     r7, -27928(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27928);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800152A8:
    ctx->pc = 0x800152A8u;
    // 800152A8: addi    r4, r4, -20248
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-20248);

label_800152AC:
    ctx->pc = 0x800152ACu;
    // 800152AC: ori     r3, r3, 0x0F00
    ctx->gpr[3] = ctx->gpr[3] | 0x0F00u;

label_800152B0:
    ctx->pc = 0x800152B0u;
    // 800152B0: b       0x800152C8
    {
            goto label_800152C8;
    }

label_800152B4:
    ctx->pc = 0x800152B4u;
    ctx->downcount -= 5;
    // 800152B4: lis     r3, 2
    ctx->gpr[3] = ((u32)(s32)(2) << 16);

label_800152B8:
    ctx->pc = 0x800152B8u;
    // 800152B8: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_800152BC:
    ctx->pc = 0x800152BCu;
    // 800152BC: lwz     r7, -27928(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27928);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800152C0:
    ctx->pc = 0x800152C0u;
    // 800152C0: addi    r4, r4, -20248
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-20248);

label_800152C4:
    ctx->pc = 0x800152C4u;
    // 800152C4: ori     r3, r3, 0x0120
    ctx->gpr[3] = ctx->gpr[3] | 0x0120u;

label_800152C8:
    ctx->pc = 0x800152C8u;
    ctx->downcount -= 3;
    // 800152C8: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_800152CC:
    ctx->pc = 0x800152CCu;
    // 800152CC: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_800152D0:
    ctx->pc = 0x800152D0u;
    // 800152D0: bl      0x80039A00
    {
            ctx->lr = 0x800152D4u;
            ctx->pc = 0x80039A00u;
            return;
    }

label_800152D4:
    ctx->pc = 0x800152D4u;
    ctx->downcount -= 4;
    // 800152D4: stw     r3, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800152D8:
    ctx->pc = 0x800152D8u;
    // 800152D8: lwz     r0, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800152DC:
    ctx->pc = 0x800152DCu;
    // 800152DC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800152E0:
    ctx->pc = 0x800152E0u;
    // 800152E0: bc    4, 2, 0x80015300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015300;
        }
    }

label_800152E4:
    ctx->pc = 0x800152E4u;
    ctx->downcount -= 7;
    // 800152E4: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_800152E8:
    ctx->pc = 0x800152E8u;
    // 800152E8: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_800152EC:
    ctx->pc = 0x800152ECu;
    // 800152EC: addi    r3, r3, -20240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20240);

label_800152F0:
    ctx->pc = 0x800152F0u;
    // 800152F0: addi    r5, r5, -20200
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-20200);

label_800152F4:
    ctx->pc = 0x800152F4u;
    // 800152F4: li      r4, 431
    ctx->gpr[4] = (u32)(s32)(431);

label_800152F8:
    ctx->pc = 0x800152F8u;
    // 800152F8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800152FC:
    ctx->pc = 0x800152FCu;
    // 800152FC: bl      0x80172A8C
    {
            ctx->lr = 0x80015300u;
            ctx->pc = 0x80172A8Cu;
            return;
    }

label_80015300:
    ctx->pc = 0x80015300u;
    ctx->downcount -= 2;
    // 80015300: lwz     r3, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80015304:
    ctx->pc = 0x80015304u;
    // 80015304: bl      0x80173BC4
    {
            ctx->lr = 0x80015308u;
            ctx->pc = 0x80173BC4u;
            return;
    }

label_80015308:
    ctx->pc = 0x80015308u;
    ctx->downcount -= 2;
    // 80015308: cmpwi   r3, 0
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

label_8001530C:
    ctx->pc = 0x8001530Cu;
    // 8001530C: bc    4, 2, 0x8001532C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001532C;
        }
    }

label_80015310:
    ctx->pc = 0x80015310u;
    ctx->downcount -= 7;
    // 80015310: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80015314:
    ctx->pc = 0x80015314u;
    // 80015314: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_80015318:
    ctx->pc = 0x80015318u;
    // 80015318: addi    r3, r3, -20240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20240);

label_8001531C:
    ctx->pc = 0x8001531Cu;
    // 8001531C: addi    r5, r5, -20168
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-20168);

label_80015320:
    ctx->pc = 0x80015320u;
    // 80015320: li      r4, 435
    ctx->gpr[4] = (u32)(s32)(435);

label_80015324:
    ctx->pc = 0x80015324u;
    // 80015324: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80015328:
    ctx->pc = 0x80015328u;
    // 80015328: bl      0x80172A8C
    {
            ctx->lr = 0x8001532Cu;
            ctx->pc = 0x80172A8Cu;
            return;
    }

label_8001532C:
    ctx->pc = 0x8001532Cu;
    ctx->downcount -= 11;
    // 8001532C: lwz     r3, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80015330:
    ctx->pc = 0x80015330u;
    // 80015330: li      r9, -16
    ctx->gpr[9] = (u32)(s32)(-16);

label_80015334:
    ctx->pc = 0x80015334u;
    // 80015334: lhz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80015338:
    ctx->pc = 0x80015338u;
    // 80015338: sth     r9, -28010(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28010);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_8001533C:
    ctx->pc = 0x8001533Cu;
    // 8001533C: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80015340:
    ctx->pc = 0x80015340u;
    // 80015340: sth     r0, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80015344:
    ctx->pc = 0x80015344u;
    // 80015344: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015348:
    ctx->pc = 0x80015348u;
    // 80015348: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8001534C:
    ctx->pc = 0x8001534Cu;
    // 8001534C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80015350:
    ctx->pc = 0x80015350u;
    // 80015350: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015354:
    ctx->pc = 0x80015354u;
    ctx->downcount -= 5;
    // 80015354: rlwinm r3, r3, 4, 0, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0xFFFFFFF0u;
    }

label_80015358:
    ctx->pc = 0x80015358u;
    // 80015358: rlwinm r4, r4, 4, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_8001535C:
    ctx->pc = 0x8001535Cu;
    // 8001535C: sth     r3, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80015360:
    ctx->pc = 0x80015360u;
    // 80015360: sth     r4, -28010(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28010);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80015364:
    ctx->pc = 0x80015364u;
    // 80015364: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015368:
    ctx->pc = 0x80015368u;
    ctx->downcount -= 2;
    // 80015368: or.   r3, r3, r3
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8001536C:
    ctx->pc = 0x8001536Cu;
    // 8001536C: bc    12, 2, 0x80015388
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80015388;
        }
    }

label_80015370:
    ctx->pc = 0x80015370u;
    ctx->downcount -= 3;
    // 80015370: lha     r9, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[9] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015374:
    ctx->pc = 0x80015374u;
    // 80015374: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015378:
    ctx->pc = 0x80015378u;
    // 80015378: bc    4, 0, 0x80015380
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015380;
        }
    }

label_8001537C:
    ctx->pc = 0x8001537Cu;
    ctx->downcount -= 1;
    // 8001537C: addi    r9, r9, 15
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15);

label_80015380:
    ctx->pc = 0x80015380u;
    ctx->downcount -= 2;
    // 80015380: srawi r0, r9, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[9];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80015384:
    ctx->pc = 0x80015384u;
    // 80015384: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80015388:
    ctx->pc = 0x80015388u;
    ctx->downcount -= 2;
    // 80015388: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001538C:
    ctx->pc = 0x8001538Cu;
    // 8001538C: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015390:
    ctx->pc = 0x80015390u;
    ctx->downcount -= 3;
    // 80015390: lha     r9, -28010(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28010);
        ctx->gpr[9] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015394:
    ctx->pc = 0x80015394u;
    // 80015394: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015398:
    ctx->pc = 0x80015398u;
    // 80015398: bc    4, 0, 0x800153A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800153A0;
        }
    }

label_8001539C:
    ctx->pc = 0x8001539Cu;
    ctx->downcount -= 1;
    // 8001539C: addi    r9, r9, 15
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15);

label_800153A0:
    ctx->pc = 0x800153A0u;
    ctx->downcount -= 3;
    // 800153A0: srawi r0, r9, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[9];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800153A4:
    ctx->pc = 0x800153A4u;
    // 800153A4: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_800153A8:
    ctx->pc = 0x800153A8u;
    // 800153A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800153AC:
    ctx->pc = 0x800153ACu;
    ctx->downcount -= 133;
    // 800153AC: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800153B0:
    ctx->pc = 0x800153B0u;
    // 800153B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800153B4:
    ctx->pc = 0x800153B4u;
    // 800153B4: stmw     r22, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 22; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800153B8:
    ctx->pc = 0x800153B8u;
    // 800153B8: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800153BC:
    ctx->pc = 0x800153BCu;
    // 800153BC: lwz     r9, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800153C0:
    ctx->pc = 0x800153C0u;
    // 800153C0: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800153C4:
    ctx->pc = 0x800153C4u;
    // 800153C4: lhz     r28, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[28] = mem_read16(ctx, ea);
    }

label_800153C8:
    ctx->pc = 0x800153C8u;
    // 800153C8: extsh r22, r3
    {
        ctx->gpr[22] = (u32)(s32)(s16)ctx->gpr[3];
    }

label_800153CC:
    ctx->pc = 0x800153CCu;
    // 800153CC: lhz     r30, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read16(ctx, ea);
    }

label_800153D0:
    ctx->pc = 0x800153D0u;
    // 800153D0: or   r23, r6, r6
    {
        ctx->gpr[23] = ctx->gpr[6] | ctx->gpr[6];
    }

label_800153D4:
    ctx->pc = 0x800153D4u;
    // 800153D4: extsh r0, r28
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_800153D8:
    ctx->pc = 0x800153D8u;
    // 800153D8: lhz     r11, 10(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(10);
        ctx->gpr[11] = mem_read16(ctx, ea);
    }

label_800153DC:
    ctx->pc = 0x800153DCu;
    // 800153DC: mullw   r30, r30, r0
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[30] = (u32)product;
    }

label_800153E0:
    ctx->pc = 0x800153E0u;
    // 800153E0: lhz     r29, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[29] = mem_read16(ctx, ea);
    }

label_800153E4:
    ctx->pc = 0x800153E4u;
    // 800153E4: lhz     r24, 18(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(18);
        ctx->gpr[24] = mem_read16(ctx, ea);
    }

label_800153E8:
    ctx->pc = 0x800153E8u;
    // 800153E8: or   r25, r7, r7
    {
        ctx->gpr[25] = ctx->gpr[7] | ctx->gpr[7];
    }

label_800153EC:
    ctx->pc = 0x800153ECu;
    // 800153EC: mullw   r11, r11, r0
    {
        s64 product = (s64)(s32)ctx->gpr[11] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[11] = (u32)product;
    }

label_800153F0:
    ctx->pc = 0x800153F0u;
    // 800153F0: rlwinm r9, r29, 0, 16, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0x0000FFFFu;
    }

label_800153F4:
    ctx->pc = 0x800153F4u;
    // 800153F4: add   r29, r29, r23
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[23];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_800153F8:
    ctx->pc = 0x800153F8u;
    // 800153F8: divw   r30, r30, r9
    {
        s32 dividend = (s32)ctx->gpr[30];
        s32 divisor = (s32)ctx->gpr[9];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[30] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_800153FC:
    ctx->pc = 0x800153FCu;
    // 800153FC: add   r24, r24, r25
    {
        u32 a = ctx->gpr[24];
        u32 b = ctx->gpr[25];
        u32 res = a + b;
        ctx->gpr[24] = res;
    }

label_80015400:
    ctx->pc = 0x80015400u;
    // 80015400: or   r26, r5, r5
    {
        ctx->gpr[26] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80015404:
    ctx->pc = 0x80015404u;
    // 80015404: add   r28, r22, r28
    {
        u32 a = ctx->gpr[22];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[28] = res;
    }

label_80015408:
    ctx->pc = 0x80015408u;
    // 80015408: extsh r28, r28
    {
        ctx->gpr[28] = (u32)(s32)(s16)ctx->gpr[28];
    }

label_8001540C:
    ctx->pc = 0x8001540Cu;
    // 8001540C: extsh r29, r29
    {
        ctx->gpr[29] = (u32)(s32)(s16)ctx->gpr[29];
    }

label_80015410:
    ctx->pc = 0x80015410u;
    // 80015410: extsh r24, r24
    {
        ctx->gpr[24] = (u32)(s32)(s16)ctx->gpr[24];
    }

label_80015414:
    ctx->pc = 0x80015414u;
    // 80015414: extsh r23, r23
    {
        ctx->gpr[23] = (u32)(s32)(s16)ctx->gpr[23];
    }

label_80015418:
    ctx->pc = 0x80015418u;
    // 80015418: extsh r25, r25
    {
        ctx->gpr[25] = (u32)(s32)(s16)ctx->gpr[25];
    }

label_8001541C:
    ctx->pc = 0x8001541Cu;
    // 8001541C: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_80015420:
    ctx->pc = 0x80015420u;
    // 80015420: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015424:
    ctx->pc = 0x80015424u;
    // 80015424: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80015428:
    ctx->pc = 0x80015428u;
    // 80015428: divw   r11, r11, r9
    {
        s32 dividend = (s32)ctx->gpr[11];
        s32 divisor = (s32)ctx->gpr[9];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[11] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_8001542C:
    ctx->pc = 0x8001542Cu;
    // 8001542C: subf   r30, r30, r27
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[27];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_80015430:
    ctx->pc = 0x80015430u;
    // 80015430: extsh r30, r30
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[30];
    }

label_80015434:
    ctx->pc = 0x80015434u;
    // 80015434: add   r27, r27, r11
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_80015438:
    ctx->pc = 0x80015438u;
    // 80015438: extsh r27, r27
    {
        ctx->gpr[27] = (u32)(s32)(s16)ctx->gpr[27];
    }

label_8001543C:
    ctx->pc = 0x8001543Cu;
    // 8001543C: bl      0x80199D18
    {
            ctx->lr = 0x80015440u;
            ctx->pc = 0x80199D18u;
            return;
    }

label_80015440:
    ctx->pc = 0x80015440u;
    ctx->downcount -= 38;
    // 80015440: lis     r9, -13311
    ctx->gpr[9] = ((u32)(s32)(-13311) << 16);

label_80015444:
    ctx->pc = 0x80015444u;
    // 80015444: extsh r26, r26
    {
        ctx->gpr[26] = (u32)(s32)(s16)ctx->gpr[26];
    }

label_80015448:
    ctx->pc = 0x80015448u;
    // 80015448: sth     r22, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[22]);
    }

label_8001544C:
    ctx->pc = 0x8001544Cu;
    // 8001544C: sth     r30, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_80015450:
    ctx->pc = 0x80015450u;
    // 80015450: sth     r26, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_80015454:
    ctx->pc = 0x80015454u;
    // 80015454: sth     r23, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[23]);
    }

label_80015458:
    ctx->pc = 0x80015458u;
    // 80015458: sth     r25, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[25]);
    }

label_8001545C:
    ctx->pc = 0x8001545Cu;
    // 8001545C: sth     r28, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_80015460:
    ctx->pc = 0x80015460u;
    // 80015460: sth     r30, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_80015464:
    ctx->pc = 0x80015464u;
    // 80015464: sth     r26, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_80015468:
    ctx->pc = 0x80015468u;
    // 80015468: sth     r29, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[29]);
    }

label_8001546C:
    ctx->pc = 0x8001546Cu;
    // 8001546C: sth     r25, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[25]);
    }

label_80015470:
    ctx->pc = 0x80015470u;
    // 80015470: sth     r28, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[28]);
    }

label_80015474:
    ctx->pc = 0x80015474u;
    // 80015474: sth     r27, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[27]);
    }

label_80015478:
    ctx->pc = 0x80015478u;
    // 80015478: sth     r26, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_8001547C:
    ctx->pc = 0x8001547Cu;
    // 8001547C: sth     r29, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[29]);
    }

label_80015480:
    ctx->pc = 0x80015480u;
    // 80015480: sth     r24, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[24]);
    }

label_80015484:
    ctx->pc = 0x80015484u;
    // 80015484: sth     r22, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[22]);
    }

label_80015488:
    ctx->pc = 0x80015488u;
    // 80015488: sth     r27, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[27]);
    }

label_8001548C:
    ctx->pc = 0x8001548Cu;
    // 8001548C: sth     r26, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[26]);
    }

label_80015490:
    ctx->pc = 0x80015490u;
    // 80015490: sth     r23, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[23]);
    }

label_80015494:
    ctx->pc = 0x80015494u;
    // 80015494: sth     r24, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[24]);
    }

label_80015498:
    ctx->pc = 0x80015498u;
    // 80015498: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001549C:
    ctx->pc = 0x8001549Cu;
    // 8001549C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800154A0:
    ctx->pc = 0x800154A0u;
    // 800154A0: lmw     r22, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 22; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800154A4:
    ctx->pc = 0x800154A4u;
    // 800154A4: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_800154A8:
    ctx->pc = 0x800154A8u;
    // 800154A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800154AC:
    ctx->pc = 0x800154ACu;
    ctx->downcount -= 19;
    // 800154AC: stwu     r1, -104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-104);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800154B0:
    ctx->pc = 0x800154B0u;
    // 800154B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800154B4:
    ctx->pc = 0x800154B4u;
    // 800154B4: stmw     r30, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800154B8:
    ctx->pc = 0x800154B8u;
    // 800154B8: stw     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800154BC:
    ctx->pc = 0x800154BCu;
    // 800154BC: lwz     r0, -28016(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28016);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800154C0:
    ctx->pc = 0x800154C0u;
    // 800154C0: or   r12, r3, r3
    {
        ctx->gpr[12] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800154C4:
    ctx->pc = 0x800154C4u;
    // 800154C4: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800154C8:
    ctx->pc = 0x800154C8u;
    // 800154C8: cmpw    r0, r12
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[12]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800154CC:
    ctx->pc = 0x800154CCu;
    // 800154CC: bc    12, 2, 0x800155D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800155D4;
        }
    }

label_800154D0:
    ctx->pc = 0x800154D0u;
    ctx->downcount -= 12;
    // 800154D0: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800154D4:
    ctx->pc = 0x800154D4u;
    // 800154D4: addi    r30, r1, 56
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(56);

label_800154D8:
    ctx->pc = 0x800154D8u;
    // 800154D8: or   r4, r12, r12
    {
        ctx->gpr[4] = ctx->gpr[12] | ctx->gpr[12];
    }

label_800154DC:
    ctx->pc = 0x800154DCu;
    // 800154DC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800154E0:
    ctx->pc = 0x800154E0u;
    // 800154E0: lhz     r7, 24(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(24);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_800154E4:
    ctx->pc = 0x800154E4u;
    // 800154E4: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800154E8:
    ctx->pc = 0x800154E8u;
    // 800154E8: lhz     r5, 30(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(30);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800154EC:
    ctx->pc = 0x800154ECu;
    // 800154EC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800154F0:
    ctx->pc = 0x800154F0u;
    // 800154F0: lhz     r6, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_800154F4:
    ctx->pc = 0x800154F4u;
    // 800154F4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800154F8:
    ctx->pc = 0x800154F8u;
    // 800154F8: stw     r12, -28016(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28016);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_800154FC:
    ctx->pc = 0x800154FCu;
    // 800154FC: bl      0x8019BE18
    {
            ctx->lr = 0x80015500u;
            ctx->pc = 0x8019BE18u;
            return;
    }

label_80015500:
    ctx->pc = 0x80015500u;
    ctx->downcount -= 11;
    // 80015500: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015504:
    ctx->pc = 0x80015504u;
    // 80015504: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80015508:
    ctx->pc = 0x80015508u;
    // 80015508: lfs     f1, -20116(r9)
    if (!ppc_fp_available(ctx, 0x80015508u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20116);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8001550C:
    ctx->pc = 0x8001550Cu;
    // 8001550C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80015510:
    ctx->pc = 0x80015510u;
    // 80015510: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80015514:
    ctx->pc = 0x80015514u;
    // 80015514: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015518:
    ctx->pc = 0x80015518u;
    // 80015518: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80015518u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_8001551C:
    ctx->pc = 0x8001551Cu;
    // 8001551C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015520:
    ctx->pc = 0x80015520u;
    // 80015520: fmr    f3, f2
    if (!ppc_fp_available(ctx, 0x80015520u)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_80015524:
    ctx->pc = 0x80015524u;
    // 80015524: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80015528:
    ctx->pc = 0x80015528u;
    // 80015528: bl      0x8019C0D4
    {
            ctx->lr = 0x8001552Cu;
            ctx->pc = 0x8019C0D4u;
            return;
    }

label_8001552C:
    ctx->pc = 0x8001552Cu;
    ctx->downcount -= 3;
    // 8001552C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80015530:
    ctx->pc = 0x80015530u;
    // 80015530: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015534:
    ctx->pc = 0x80015534u;
    // 80015534: bl      0x8019C740
    {
            ctx->lr = 0x80015538u;
            ctx->pc = 0x8019C740u;
            return;
    }

label_80015538:
    ctx->pc = 0x80015538u;
    ctx->downcount -= 58;
    // 80015538: lwz     r10, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8001553C:
    ctx->pc = 0x8001553Cu;
    // 8001553C: lis     r5, 17200
    ctx->gpr[5] = ((u32)(s32)(17200) << 16);

label_80015540:
    ctx->pc = 0x80015540u;
    // 80015540: or   r7, r11, r11
    {
        ctx->gpr[7] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80015544:
    ctx->pc = 0x80015544u;
    // 80015544: lhz     r0, 30(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(30);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80015548:
    ctx->pc = 0x80015548u;
    // 80015548: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_8001554C:
    ctx->pc = 0x8001554Cu;
    // 8001554C: lhz     r9, 32(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80015550:
    ctx->pc = 0x80015550u;
    // 80015550: lis     r6, -32738
    ctx->gpr[6] = ((u32)(s32)(-32738) << 16);

label_80015554:
    ctx->pc = 0x80015554u;
    // 80015554: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_80015558:
    ctx->pc = 0x80015558u;
    // 80015558: lfd     f13, -20112(r8)
    if (!ppc_fp_available(ctx, 0x80015558u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-20112);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001555C:
    ctx->pc = 0x8001555Cu;
    // 8001555C: stw     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015560:
    ctx->pc = 0x80015560u;
    // 80015560: xoris   r9, r9, 0x8000
    ctx->gpr[9] = ctx->gpr[9] ^ (0x8000u << 16);

label_80015564:
    ctx->pc = 0x80015564u;
    // 80015564: lfs     f2, -20104(r6)
    if (!ppc_fp_available(ctx, 0x80015564u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-20104);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80015568:
    ctx->pc = 0x80015568u;
    // 80015568: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8001556C:
    ctx->pc = 0x8001556Cu;
    // 8001556C: stw     r5, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80015570:
    ctx->pc = 0x80015570u;
    // 80015570: fmr    f3, f2
    if (!ppc_fp_available(ctx, 0x80015570u)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_80015574:
    ctx->pc = 0x80015574u;
    // 80015574: lfd     f1, 88(r1)
    if (!ppc_fp_available(ctx, 0x80015574u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80015578:
    ctx->pc = 0x80015578u;
    // 80015578: stw     r9, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8001557C:
    ctx->pc = 0x8001557Cu;
    // 8001557C: fsub   f1, f1, f13
    if (!ppc_fp_available(ctx, 0x8001557Cu)) return;
    ppc_fsub(ctx, 1, 1, 13);

label_80015580:
    ctx->pc = 0x80015580u;
    // 80015580: stw     r5, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80015584:
    ctx->pc = 0x80015584u;
    // 80015584: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x80015584u)) return;
    ppc_frsp(ctx, 1, 1);

label_80015588:
    ctx->pc = 0x80015588u;
    // 80015588: fdivs   f1, f2, f1
    if (!ppc_fp_available(ctx, 0x80015588u)) return;
    ppc_fdivs(ctx, 1, 2, 1);

label_8001558C:
    ctx->pc = 0x8001558Cu;
    // 8001558C: lfd     f0, 88(r1)
    if (!ppc_fp_available(ctx, 0x8001558Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80015590:
    ctx->pc = 0x80015590u;
    // 80015590: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x80015590u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_80015594:
    ctx->pc = 0x80015594u;
    // 80015594: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x80015594u)) return;
    ppc_frsp(ctx, 0, 0);

label_80015598:
    ctx->pc = 0x80015598u;
    // 80015598: fdivs   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x80015598u)) return;
    ppc_fdivs(ctx, 2, 2, 0);

label_8001559C:
    ctx->pc = 0x8001559Cu;
    // 8001559C: bl      0x8017C0F4
    {
            ctx->lr = 0x800155A0u;
            ctx->pc = 0x8017C0F4u;
            return;
    }

label_800155A0:
    ctx->pc = 0x800155A0u;
    ctx->downcount -= 4;
    // 800155A0: li      r4, 30
    ctx->gpr[4] = (u32)(s32)(30);

label_800155A4:
    ctx->pc = 0x800155A4u;
    // 800155A4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800155A8:
    ctx->pc = 0x800155A8u;
    // 800155A8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800155AC:
    ctx->pc = 0x800155ACu;
    // 800155AC: bl      0x8019FB20
    {
            ctx->lr = 0x800155B0u;
            ctx->pc = 0x8019FB20u;
            return;
    }

label_800155B0:
    ctx->pc = 0x800155B0u;
    ctx->downcount -= 2;
    // 800155B0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800155B4:
    ctx->pc = 0x800155B4u;
    // 800155B4: bl      0x80199104
    {
            ctx->lr = 0x800155B8u;
            ctx->pc = 0x80199104u;
            return;
    }

label_800155B8:
    ctx->pc = 0x800155B8u;
    ctx->downcount -= 7;
    // 800155B8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800155BC:
    ctx->pc = 0x800155BCu;
    // 800155BC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800155C0:
    ctx->pc = 0x800155C0u;
    // 800155C0: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_800155C4:
    ctx->pc = 0x800155C4u;
    // 800155C4: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800155C8:
    ctx->pc = 0x800155C8u;
    // 800155C8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800155CC:
    ctx->pc = 0x800155CCu;
    // 800155CC: li      r8, 125
    ctx->gpr[8] = (u32)(s32)(125);

label_800155D0:
    ctx->pc = 0x800155D0u;
    // 800155D0: bl      0x80198E34
    {
            ctx->lr = 0x800155D4u;
            ctx->pc = 0x80198E34u;
            return;
    }

label_800155D4:
    ctx->pc = 0x800155D4u;
    ctx->downcount -= 16;
    // 800155D4: lwz     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800155D8:
    ctx->pc = 0x800155D8u;
    // 800155D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800155DC:
    ctx->pc = 0x800155DCu;
    // 800155DC: lmw     r30, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800155E0:
    ctx->pc = 0x800155E0u;
    // 800155E0: addi    r1, r1, 104
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(104);

label_800155E4:
    ctx->pc = 0x800155E4u;
    // 800155E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800155E8:
    ctx->pc = 0x800155E8u;
    ctx->downcount -= 21;
    // 800155E8: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800155EC:
    ctx->pc = 0x800155ECu;
    // 800155EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800155F0:
    ctx->pc = 0x800155F0u;
    // 800155F0: stmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800155F4:
    ctx->pc = 0x800155F4u;
    // 800155F4: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800155F8:
    ctx->pc = 0x800155F8u;
    // 800155F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800155FC:
    ctx->pc = 0x800155FCu;
    // 800155FC: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80015600:
    ctx->pc = 0x80015600u;
    // 80015600: stw     r0, -28016(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28016);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015604:
    ctx->pc = 0x80015604u;
    // 80015604: or   r31, r6, r6
    {
        ctx->gpr[31] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80015608:
    ctx->pc = 0x80015608u;
    // 80015608: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8001560C:
    ctx->pc = 0x8001560Cu;
    // 8001560C: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80015610:
    ctx->pc = 0x80015610u;
    // 80015610: bl      0x8019831C
    {
            ctx->lr = 0x80015614u;
            ctx->pc = 0x8019831Cu;
            return;
    }

label_80015614:
    ctx->pc = 0x80015614u;
    ctx->downcount -= 4;
    // 80015614: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80015618:
    ctx->pc = 0x80015618u;
    // 80015618: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_8001561C:
    ctx->pc = 0x8001561Cu;
    // 8001561C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80015620:
    ctx->pc = 0x80015620u;
    // 80015620: bl      0x801978AC
    {
            ctx->lr = 0x80015624u;
            ctx->pc = 0x801978ACu;
            return;
    }

label_80015624:
    ctx->pc = 0x80015624u;
    ctx->downcount -= 3;
    // 80015624: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_80015628:
    ctx->pc = 0x80015628u;
    // 80015628: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8001562C:
    ctx->pc = 0x8001562Cu;
    // 8001562C: bl      0x801978AC
    {
            ctx->lr = 0x80015630u;
            ctx->pc = 0x801978ACu;
            return;
    }

label_80015630:
    ctx->pc = 0x80015630u;
    ctx->downcount -= 6;
    // 80015630: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015634:
    ctx->pc = 0x80015634u;
    // 80015634: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_80015638:
    ctx->pc = 0x80015638u;
    // 80015638: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8001563C:
    ctx->pc = 0x8001563Cu;
    // 8001563C: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80015640:
    ctx->pc = 0x80015640u;
    // 80015640: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_80015644:
    ctx->pc = 0x80015644u;
    // 80015644: bl      0x80198368
    {
            ctx->lr = 0x80015648u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80015648:
    ctx->pc = 0x80015648u;
    ctx->downcount -= 6;
    // 80015648: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8001564C:
    ctx->pc = 0x8001564Cu;
    // 8001564C: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_80015650:
    ctx->pc = 0x80015650u;
    // 80015650: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015654:
    ctx->pc = 0x80015654u;
    // 80015654: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_80015658:
    ctx->pc = 0x80015658u;
    // 80015658: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8001565C:
    ctx->pc = 0x8001565Cu;
    // 8001565C: bl      0x80198368
    {
            ctx->lr = 0x80015660u;
            ctx->pc = 0x80198368u;
            return;
    }

label_80015660:
    ctx->pc = 0x80015660u;
    ctx->downcount -= 9;
    // 80015660: lbz     r10, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80015664:
    ctx->pc = 0x80015664u;
    // 80015664: rlwinm r0, r29, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 4u) & 0xFFFFFFF0u;
    }

label_80015668:
    ctx->pc = 0x80015668u;
    // 80015668: rlwinm r9, r30, 4, 0, 27
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[30], 4u) & 0xFFFFFFF0u;
    }

label_8001566C:
    ctx->pc = 0x8001566Cu;
    // 8001566C: rlwinm r11, r28, 4, 0, 27
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[28], 4u) & 0xFFFFFFF0u;
    }

label_80015670:
    ctx->pc = 0x80015670u;
    // 80015670: extsh r29, r0
    {
        ctx->gpr[29] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_80015674:
    ctx->pc = 0x80015674u;
    // 80015674: extsh r30, r9
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_80015678:
    ctx->pc = 0x80015678u;
    // 80015678: extsh r28, r11
    {
        ctx->gpr[28] = (u32)(s32)(s16)ctx->gpr[11];
    }

label_8001567C:
    ctx->pc = 0x8001567Cu;
    // 8001567C: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015680:
    ctx->pc = 0x80015680u;
    // 80015680: bc    12, 2, 0x80015728
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80015728;
        }
    }

label_80015684:
    ctx->downcount -= 2;
    // 80015684: cmpwi   r10, 10
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015688:
    // 80015688: bc    4, 2, 0x800156B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800156B8;
        }
    }

label_8001568C:
    ctx->pc = 0x8001568Cu;
    ctx->downcount -= 54;
    // 8001568C: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80015690:
    // 80015690: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80015694:
    ctx->pc = 0x80015694u;
    // 80015694: lha     r10, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015698:
    // 80015698: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8001569C:
    ctx->pc = 0x8001569Cu;
    // 8001569C: lhz     r0, 14(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800156A0:
    ctx->pc = 0x800156A0u;
    // 800156A0: lhz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_800156A4:
    // 800156A4: mullw   r0, r0, r10
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[10];
        ctx->gpr[0] = (u32)product;
    }

label_800156A8:
    // 800156A8: divw   r0, r0, r9
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[9];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_800156AC:
    // 800156AC: add   r0, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800156B0:
    // 800156B0: extsh r30, r0
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_800156B4:
    // 800156B4: b       0x8001571C
    {
            goto label_8001571C;
    }

label_800156B8:
    ctx->downcount -= 6;
    // 800156B8: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_800156BC:
    // 800156BC: addi    r6, r1, 16
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(16);

label_800156C0:
    // 800156C0: addi    r7, r1, 20
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(20);

label_800156C4:
    // 800156C4: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_800156C8:
    // 800156C8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800156CC:
    // 800156CC: bl      0x80173CA4
    {
            ctx->lr = 0x800156D0u;
            ctx->pc = 0x80173CA4u;
            return;
    }

label_800156D0:
    ctx->downcount -= 4;
    // 800156D0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800156D4:
    // 800156D4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800156D8:
    ctx->pc = 0x800156D8u;
    // 800156D8: lwz     r3, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800156DC:
    // 800156DC: bl      0x800154AC
    {
            ctx->lr = 0x800156E0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800154ACu;
                return;
            }
            goto label_800154AC;
    }

label_800156E0:
    ctx->pc = 0x800156E0u;
    ctx->downcount -= 6;
    // 800156E0: lwz     r6, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800156E4:
    // 800156E4: add   r3, r29, r27
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800156E8:
    ctx->pc = 0x800156E8u;
    // 800156E8: lwz     r7, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800156EC:
    // 800156EC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800156F0:
    // 800156F0: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800156F4:
    // 800156F4: bl      0x800153AC
    {
            ctx->lr = 0x800156F8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800153ACu;
                return;
            }
            goto label_800153AC;
    }

label_800156F8:
    ctx->pc = 0x800156F8u;
    ctx->downcount -= 52;
    // 800156F8: lwz     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800156FC:
    ctx->pc = 0x800156FCu;
    // 800156FC: lha     r0, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015700:
    ctx->pc = 0x80015700u;
    // 80015700: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80015704:
    // 80015704: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_80015708:
    ctx->pc = 0x80015708u;
    // 80015708: lha     r10, -28010(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28010);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8001570C:
    ctx->pc = 0x8001570Cu;
    // 8001570C: lhz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80015710:
    // 80015710: divw   r0, r0, r9
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[9];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80015714:
    // 80015714: add   r0, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80015718:
    // 80015718: add   r27, r27, r0
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[27] = res;
    }

label_8001571C:
    ctx->pc = 0x8001571Cu;
    ctx->downcount -= 3;
    // 8001571C: lbz     r10, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_80015720:
    // 80015720: cmpwi   r10, 0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015724:
    // 80015724: bc    4, 2, 0x80015684
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015684u;
                return;
            }
            goto label_80015684;
        }
    }

label_80015728:
    ctx->pc = 0x80015728u;
    ctx->downcount -= 2;
    // 80015728: addic.  r3, r27, 15
    {
        u64 a = ctx->gpr[27];
        u64 b = (u32)(s32)(15);
        u64 res = a + b;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8001572C:
    ctx->pc = 0x8001572Cu;
    // 8001572C: bc    4, 0, 0x80015734
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015734;
        }
    }

label_80015730:
    ctx->pc = 0x80015730u;
    ctx->downcount -= 1;
    // 80015730: addi    r3, r27, 30
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(30);

label_80015734:
    ctx->pc = 0x80015734u;
    ctx->downcount -= 17;
    // 80015734: srawi r3, r3, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[3];
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

label_80015738:
    ctx->pc = 0x80015738u;
    // 80015738: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001573C:
    ctx->pc = 0x8001573Cu;
    // 8001573C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015740:
    ctx->pc = 0x80015740u;
    // 80015740: lmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80015744:
    ctx->pc = 0x80015744u;
    // 80015744: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_80015748:
    ctx->pc = 0x80015748u;
    // 80015748: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_8001574C:
    ctx->pc = 0x8001574Cu;
    ctx->downcount -= 23;
    // 8001574C: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80015750:
    ctx->pc = 0x80015750u;
    // 80015750: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015754:
    ctx->pc = 0x80015754u;
    // 80015754: stmw     r25, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80015758:
    ctx->pc = 0x80015758u;
    // 80015758: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001575C:
    ctx->pc = 0x8001575Cu;
    // 8001575C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80015760:
    ctx->pc = 0x80015760u;
    // 80015760: or   r31, r6, r6
    {
        ctx->gpr[31] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80015764:
    ctx->pc = 0x80015764u;
    // 80015764: or   r27, r5, r5
    {
        ctx->gpr[27] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80015768:
    ctx->pc = 0x80015768u;
    // 80015768: or   r28, r7, r7
    {
        ctx->gpr[28] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8001576C:
    ctx->pc = 0x8001576Cu;
    // 8001576C: stw     r0, -28016(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28016);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015770:
    ctx->pc = 0x80015770u;
    // 80015770: add   r25, r31, r8
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[25] = res;
    }

label_80015774:
    ctx->pc = 0x80015774u;
    // 80015774: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015778:
    ctx->pc = 0x80015778u;
    // 80015778: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8001577C:
    ctx->pc = 0x8001577Cu;
    // 8001577C: bl      0x8019831C
    {
            ctx->lr = 0x80015780u;
            ctx->pc = 0x8019831Cu;
            return;
    }

label_80015780:
    ctx->pc = 0x80015780u;
    ctx->downcount -= 4;
    // 80015780: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80015784:
    ctx->pc = 0x80015784u;
    // 80015784: li      r3, 9
    ctx->gpr[3] = (u32)(s32)(9);

label_80015788:
    ctx->pc = 0x80015788u;
    // 80015788: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8001578C:
    ctx->pc = 0x8001578Cu;
    // 8001578C: bl      0x801978AC
    {
            ctx->lr = 0x80015790u;
            ctx->pc = 0x801978ACu;
            return;
    }

label_80015790:
    ctx->pc = 0x80015790u;
    ctx->downcount -= 3;
    // 80015790: li      r3, 13
    ctx->gpr[3] = (u32)(s32)(13);

label_80015794:
    ctx->pc = 0x80015794u;
    // 80015794: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80015798:
    ctx->pc = 0x80015798u;
    // 80015798: bl      0x801978AC
    {
            ctx->lr = 0x8001579Cu;
            ctx->pc = 0x801978ACu;
            return;
    }

label_8001579C:
    ctx->pc = 0x8001579Cu;
    ctx->downcount -= 6;
    // 8001579C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800157A0:
    ctx->pc = 0x800157A0u;
    // 800157A0: li      r4, 9
    ctx->gpr[4] = (u32)(s32)(9);

label_800157A4:
    ctx->pc = 0x800157A4u;
    // 800157A4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800157A8:
    ctx->pc = 0x800157A8u;
    // 800157A8: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_800157AC:
    ctx->pc = 0x800157ACu;
    // 800157AC: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_800157B0:
    ctx->pc = 0x800157B0u;
    // 800157B0: bl      0x80198368
    {
            ctx->lr = 0x800157B4u;
            ctx->pc = 0x80198368u;
            return;
    }

label_800157B4:
    ctx->pc = 0x800157B4u;
    ctx->downcount -= 6;
    // 800157B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800157B8:
    ctx->pc = 0x800157B8u;
    // 800157B8: li      r4, 13
    ctx->gpr[4] = (u32)(s32)(13);

label_800157BC:
    ctx->pc = 0x800157BCu;
    // 800157BC: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_800157C0:
    ctx->pc = 0x800157C0u;
    // 800157C0: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_800157C4:
    ctx->pc = 0x800157C4u;
    // 800157C4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800157C8:
    ctx->pc = 0x800157C8u;
    // 800157C8: bl      0x80198368
    {
            ctx->lr = 0x800157CCu;
            ctx->pc = 0x80198368u;
            return;
    }

label_800157CC:
    ctx->pc = 0x800157CCu;
    ctx->downcount -= 10;
    // 800157CC: lbz     r8, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_800157D0:
    ctx->pc = 0x800157D0u;
    // 800157D0: rlwinm r0, r29, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 4u) & 0xFFFFFFF0u;
    }

label_800157D4:
    ctx->pc = 0x800157D4u;
    // 800157D4: rlwinm r9, r30, 4, 0, 27
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[30], 4u) & 0xFFFFFFF0u;
    }

label_800157D8:
    ctx->pc = 0x800157D8u;
    // 800157D8: rlwinm r11, r27, 4, 0, 27
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[27], 4u) & 0xFFFFFFF0u;
    }

label_800157DC:
    ctx->pc = 0x800157DCu;
    // 800157DC: rlwinm r10, r28, 4, 0, 27
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[28], 4u) & 0xFFFFFFF0u;
    }

label_800157E0:
    ctx->pc = 0x800157E0u;
    // 800157E0: extsh r29, r0
    {
        ctx->gpr[29] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_800157E4:
    ctx->pc = 0x800157E4u;
    // 800157E4: extsh r30, r9
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_800157E8:
    ctx->pc = 0x800157E8u;
    // 800157E8: extsh r27, r11
    {
        ctx->gpr[27] = (u32)(s32)(s16)ctx->gpr[11];
    }

label_800157EC:
    ctx->pc = 0x800157ECu;
    // 800157EC: extsh r28, r10
    {
        ctx->gpr[28] = (u32)(s32)(s16)ctx->gpr[10];
    }

label_800157F0:
    ctx->pc = 0x800157F0u;
    // 800157F0: b       0x800158D4
    {
            goto label_800158D4;
    }

label_800157F4:
    ctx->downcount -= 2;
    // 800157F4: cmpwi   r8, 10
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800157F8:
    // 800157F8: bc    4, 2, 0x80015828
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015828;
        }
    }

label_800157FC:
    ctx->pc = 0x800157FCu;
    ctx->downcount -= 54;
    // 800157FC: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80015800:
    // 80015800: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80015804:
    ctx->pc = 0x80015804u;
    // 80015804: lha     r10, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015808:
    // 80015808: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8001580C:
    ctx->pc = 0x8001580Cu;
    // 8001580C: lhz     r0, 14(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80015810:
    ctx->pc = 0x80015810u;
    // 80015810: lhz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80015814:
    // 80015814: mullw   r0, r0, r10
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[10];
        ctx->gpr[0] = (u32)product;
    }

label_80015818:
    // 80015818: divw   r0, r0, r9
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[9];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_8001581C:
    // 8001581C: add   r0, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80015820:
    // 80015820: extsh r30, r0
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_80015824:
    // 80015824: b       0x800158D0
    {
            goto label_800158D0;
    }

label_80015828:
    ctx->downcount -= 6;
    // 80015828: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8001582C:
    // 8001582C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80015830:
    // 80015830: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_80015834:
    // 80015834: addi    r6, r1, 16
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(16);

label_80015838:
    // 80015838: addi    r7, r1, 20
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(20);

label_8001583C:
    // 8001583C: bl      0x80173CA4
    {
            ctx->lr = 0x80015840u;
            ctx->pc = 0x80173CA4u;
            return;
    }

label_80015840:
    ctx->pc = 0x80015840u;
    ctx->downcount -= 55;
    // 80015840: lha     r8, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[8] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015844:
    // 80015844: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015848:
    ctx->pc = 0x80015848u;
    // 80015848: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001584C:
    ctx->pc = 0x8001584Cu;
    // 8001584C: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80015850:
    // 80015850: mullw   r0, r8, r0
    {
        s64 product = (s64)(s32)ctx->gpr[8] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[0] = (u32)product;
    }

label_80015854:
    ctx->pc = 0x80015854u;
    // 80015854: lha     r9, -28010(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28010);
        ctx->gpr[9] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015858:
    ctx->pc = 0x80015858u;
    // 80015858: lhz     r10, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_8001585C:
    // 8001585C: divw   r0, r0, r10
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[10];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80015860:
    // 80015860: add   r0, r26, r0
    {
        u32 a = ctx->gpr[26];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80015864:
    // 80015864: add   r0, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80015868:
    // 80015868: cmpw    r28, r0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001586C:
    // 8001586C: bc    4, 0, 0x80015888
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015888;
        }
    }

label_80015870:
    ctx->pc = 0x80015870u;
    ctx->downcount -= 49;
    // 80015870: lhz     r0, 14(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80015874:
    // 80015874: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80015878:
    // 80015878: mullw   r0, r0, r8
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[8];
        ctx->gpr[0] = (u32)product;
    }

label_8001587C:
    // 8001587C: divw   r0, r0, r10
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[10];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80015880:
    // 80015880: add   r0, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80015884:
    // 80015884: extsh r30, r0
    {
        ctx->gpr[30] = (u32)(s32)(s16)ctx->gpr[0];
    }

label_80015888:
    ctx->pc = 0x80015888u;
    ctx->downcount -= 3;
    // 80015888: lwz     r3, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001588C:
    // 8001588C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015890:
    // 80015890: bl      0x800154AC
    {
            ctx->lr = 0x80015894u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800154ACu;
                return;
            }
            goto label_800154AC;
    }

label_80015894:
    ctx->pc = 0x80015894u;
    ctx->downcount -= 6;
    // 80015894: lwz     r6, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80015898:
    // 80015898: add   r3, r29, r26
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[26];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8001589C:
    ctx->pc = 0x8001589Cu;
    // 8001589C: lwz     r7, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800158A0:
    // 800158A0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800158A4:
    // 800158A4: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800158A8:
    // 800158A8: bl      0x800153AC
    {
            ctx->lr = 0x800158ACu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800153ACu;
                return;
            }
            goto label_800153AC;
    }

label_800158AC:
    ctx->pc = 0x800158ACu;
    ctx->downcount -= 52;
    // 800158AC: lwz     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800158B0:
    ctx->pc = 0x800158B0u;
    // 800158B0: lha     r0, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800158B4:
    ctx->pc = 0x800158B4u;
    // 800158B4: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800158B8:
    // 800158B8: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_800158BC:
    ctx->pc = 0x800158BCu;
    // 800158BC: lha     r10, -28010(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28010);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_800158C0:
    ctx->pc = 0x800158C0u;
    // 800158C0: lhz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_800158C4:
    // 800158C4: divw   r0, r0, r9
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[9];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_800158C8:
    // 800158C8: add   r0, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800158CC:
    // 800158CC: add   r26, r26, r0
    {
        u32 a = ctx->gpr[26];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[26] = res;
    }

label_800158D0:
    ctx->pc = 0x800158D0u;
    ctx->downcount -= 1;
    // 800158D0: lbz     r8, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_800158D4:
    ctx->downcount -= 2;
    // 800158D4: cmpwi   r8, 0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800158D8:
    // 800158D8: bc    12, 2, 0x800158E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800158E4;
        }
    }

label_800158DC:
    ctx->downcount -= 2;
    // 800158DC: cmplw   r31, r25
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(ctx->gpr[25]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800158E0:
    // 800158E0: bc    12, 0, 0x800157F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800157F4u;
                return;
            }
            goto label_800157F4;
        }
    }

label_800158E4:
    ctx->pc = 0x800158E4u;
    ctx->downcount -= 2;
    // 800158E4: addic.  r3, r26, 15
    {
        u64 a = ctx->gpr[26];
        u64 b = (u32)(s32)(15);
        u64 res = a + b;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800158E8:
    ctx->pc = 0x800158E8u;
    // 800158E8: bc    4, 0, 0x800158F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800158F0;
        }
    }

label_800158EC:
    ctx->pc = 0x800158ECu;
    ctx->downcount -= 1;
    // 800158EC: addi    r3, r26, 30
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(30);

label_800158F0:
    ctx->pc = 0x800158F0u;
    ctx->downcount -= 17;
    // 800158F0: srawi r3, r3, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[3];
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

label_800158F4:
    ctx->pc = 0x800158F4u;
    // 800158F4: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800158F8:
    ctx->pc = 0x800158F8u;
    // 800158F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800158FC:
    ctx->pc = 0x800158FCu;
    // 800158FC: lmw     r25, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80015900:
    ctx->pc = 0x80015900u;
    // 80015900: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_80015904:
    ctx->pc = 0x80015904u;
    // 80015904: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015908:
    ctx->pc = 0x80015908u;
    ctx->downcount -= 28;
    // 80015908: stwu     r1, -416(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-416);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8001590C:
    ctx->pc = 0x8001590Cu;
    // 8001590C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015910:
    ctx->pc = 0x80015910u;
    // 80015910: stmw     r28, 400(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80015914:
    ctx->pc = 0x80015914u;
    // 80015914: stw     r0, 420(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015918:
    ctx->pc = 0x80015918u;
    // 80015918: lis     r12, 1024
    ctx->gpr[12] = ((u32)(s32)(1024) << 16);

label_8001591C:
    ctx->pc = 0x8001591Cu;
    // 8001591C: addi    r0, r1, 424
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(424);

label_80015920:
    ctx->pc = 0x80015920u;
    // 80015920: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_80015924:
    ctx->pc = 0x80015924u;
    // 80015924: stw     r0, 388(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015928:
    ctx->pc = 0x80015928u;
    // 80015928: stw     r11, 392(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(392);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8001592C:
    ctx->pc = 0x8001592Cu;
    // 8001592C: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015930:
    ctx->pc = 0x80015930u;
    // 80015930: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80015934:
    ctx->pc = 0x80015934u;
    // 80015934: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80015938:
    ctx->pc = 0x80015938u;
    // 80015938: stw     r7, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8001593C:
    ctx->pc = 0x8001593Cu;
    // 8001593C: stw     r8, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80015940:
    ctx->pc = 0x80015940u;
    // 80015940: stw     r9, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80015944:
    ctx->pc = 0x80015944u;
    // 80015944: stw     r10, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80015948:
    ctx->pc = 0x80015948u;
    // 80015948: stw     r12, 384(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(384);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8001594C:
    ctx->pc = 0x8001594Cu;
    // 8001594C: bc    4, 6, 0x80015970
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x02000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015970;
        }
    }

label_80015950:
    ctx->pc = 0x80015950u;
    ctx->downcount -= 8;
    // 80015950: stfd     f1, 40(r1)
    if (!ppc_fp_available(ctx, 0x80015950u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[1]));
    }

label_80015954:
    ctx->pc = 0x80015954u;
    // 80015954: stfd     f2, 48(r1)
    if (!ppc_fp_available(ctx, 0x80015954u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[2]));
    }

label_80015958:
    ctx->pc = 0x80015958u;
    // 80015958: stfd     f3, 56(r1)
    if (!ppc_fp_available(ctx, 0x80015958u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[3]));
    }

label_8001595C:
    ctx->pc = 0x8001595Cu;
    // 8001595C: stfd     f4, 64(r1)
    if (!ppc_fp_available(ctx, 0x8001595Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[4]));
    }

label_80015960:
    ctx->pc = 0x80015960u;
    // 80015960: stfd     f5, 72(r1)
    if (!ppc_fp_available(ctx, 0x80015960u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[5]));
    }

label_80015964:
    ctx->pc = 0x80015964u;
    // 80015964: stfd     f6, 80(r1)
    if (!ppc_fp_available(ctx, 0x80015964u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[6]));
    }

label_80015968:
    ctx->pc = 0x80015968u;
    // 80015968: stfd     f7, 88(r1)
    if (!ppc_fp_available(ctx, 0x80015968u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[7]));
    }

label_8001596C:
    ctx->pc = 0x8001596Cu;
    // 8001596C: stfd     f8, 96(r1)
    if (!ppc_fp_available(ctx, 0x8001596Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[8]));
    }

label_80015970:
    ctx->pc = 0x80015970u;
    ctx->downcount -= 12;
    // 80015970: addi    r11, r1, 384
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(384);

label_80015974:
    ctx->pc = 0x80015974u;
    // 80015974: addi    r9, r1, 112
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(112);

label_80015978:
    ctx->pc = 0x80015978u;
    // 80015978: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8001597C:
    ctx->pc = 0x8001597Cu;
    // 8001597C: addi    r30, r1, 128
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(128);

label_80015980:
    ctx->pc = 0x80015980u;
    // 80015980: lwz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015984:
    ctx->pc = 0x80015984u;
    // 80015984: or   r5, r9, r9
    {
        ctx->gpr[5] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80015988:
    ctx->pc = 0x80015988u;
    // 80015988: stw     r12, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8001598C:
    ctx->pc = 0x8001598Cu;
    // 8001598C: or   r4, r6, r6
    {
        ctx->gpr[4] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80015990:
    ctx->pc = 0x80015990u;
    // 80015990: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015994:
    ctx->pc = 0x80015994u;
    // 80015994: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015998:
    ctx->pc = 0x80015998u;
    // 80015998: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8001599C:
    ctx->pc = 0x8001599Cu;
    // 8001599C: bl      0x80169514
    {
            ctx->lr = 0x800159A0u;
            ctx->pc = 0x80169514u;
            return;
    }

label_800159A0:
    ctx->pc = 0x800159A0u;
    ctx->downcount -= 5;
    // 800159A0: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800159A4:
    ctx->pc = 0x800159A4u;
    // 800159A4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800159A8:
    ctx->pc = 0x800159A8u;
    // 800159A8: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800159AC:
    ctx->pc = 0x800159ACu;
    // 800159AC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800159B0:
    ctx->pc = 0x800159B0u;
    // 800159B0: bl      0x800155E8
    {
            ctx->lr = 0x800159B4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800155E8u;
                return;
            }
            goto label_800155E8;
    }

label_800159B4:
    ctx->pc = 0x800159B4u;
    ctx->downcount -= 2;
    // 800159B4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800159B8:
    ctx->pc = 0x800159B8u;
    // 800159B8: bl      0x800138F8
    {
            ctx->lr = 0x800159BCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800138F8u;
                return;
            }
            goto label_800138F8;
    }

label_800159BC:
    ctx->pc = 0x800159BCu;
    ctx->downcount -= 17;
    // 800159BC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800159C0:
    ctx->pc = 0x800159C0u;
    // 800159C0: lwz     r0, 420(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(420);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800159C4:
    ctx->pc = 0x800159C4u;
    // 800159C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800159C8:
    ctx->pc = 0x800159C8u;
    // 800159C8: lmw     r28, 400(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(400);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800159CC:
    ctx->pc = 0x800159CCu;
    // 800159CC: addi    r1, r1, 416
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(416);

label_800159D0:
    ctx->pc = 0x800159D0u;
    // 800159D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800159D4:
    ctx->pc = 0x800159D4u;
    ctx->downcount -= 16;
    // 800159D4: stwu     r1, -1192(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-1192);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800159D8:
    ctx->pc = 0x800159D8u;
    // 800159D8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800159DC:
    ctx->pc = 0x800159DCu;
    // 800159DC: stmw     r26, 1168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1168);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800159E0:
    ctx->pc = 0x800159E0u;
    // 800159E0: stw     r0, 1196(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1196);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800159E4:
    ctx->pc = 0x800159E4u;
    // 800159E4: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800159E8:
    ctx->pc = 0x800159E8u;
    // 800159E8: bl      0x801730B0
    {
            ctx->lr = 0x800159ECu;
            ctx->pc = 0x801730B0u;
            return;
    }

label_800159EC:
    ctx->pc = 0x800159ECu;
    ctx->downcount -= 2;
    // 800159EC: cmpwi   r3, 1
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800159F0:
    ctx->pc = 0x800159F0u;
    // 800159F0: bc    4, 2, 0x80015A08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015A08;
        }
    }

label_800159F4:
    ctx->pc = 0x800159F4u;
    ctx->downcount -= 5;
    // 800159F4: lwz     r9, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800159F8:
    ctx->pc = 0x800159F8u;
    // 800159F8: addis   r11, r9, 13
    ctx->gpr[11] = ctx->gpr[9] + ((u32)(s32)(13) << 16);

label_800159FC:
    ctx->pc = 0x800159FCu;
    // 800159FC: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80015A00:
    ctx->pc = 0x80015A00u;
    // 80015A00: addi    r4, r11, 16128
    ctx->gpr[4] = ctx->gpr[11] + (u32)(s32)(16128);

label_80015A04:
    ctx->pc = 0x80015A04u;
    // 80015A04: b       0x80015A18
    {
            goto label_80015A18;
    }

label_80015A08:
    ctx->pc = 0x80015A08u;
    ctx->downcount -= 4;
    // 80015A08: lwz     r9, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80015A0C:
    ctx->pc = 0x80015A0Cu;
    // 80015A0C: addis   r11, r9, 2
    ctx->gpr[11] = ctx->gpr[9] + ((u32)(s32)(2) << 16);

label_80015A10:
    ctx->pc = 0x80015A10u;
    // 80015A10: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80015A14:
    ctx->pc = 0x80015A14u;
    // 80015A14: addi    r4, r11, -12000
    ctx->gpr[4] = ctx->gpr[11] + (u32)(s32)(-12000);

label_80015A18:
    ctx->pc = 0x80015A18u;
    ctx->downcount -= 3;
    // 80015A18: rlwinm r4, r4, 0, 0, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_80015A1C:
    ctx->pc = 0x80015A1Cu;
    // 80015A1C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80015A20:
    ctx->pc = 0x80015A20u;
    // 80015A20: bl      0x80173300
    {
            ctx->lr = 0x80015A24u;
            ctx->pc = 0x80173300u;
            return;
    }

label_80015A24:
    ctx->pc = 0x80015A24u;
    ctx->downcount -= 5;
    // 80015A24: lis     r26, -32738
    ctx->gpr[26] = ((u32)(s32)(-32738) << 16);

label_80015A28:
    ctx->pc = 0x80015A28u;
    // 80015A28: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015A2C:
    ctx->pc = 0x80015A2Cu;
    // 80015A2C: li      r5, 1152
    ctx->gpr[5] = (u32)(s32)(1152);

label_80015A30:
    ctx->pc = 0x80015A30u;
    // 80015A30: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80015A34:
    ctx->pc = 0x80015A34u;
    // 80015A34: bl      0x801698F0
    {
            ctx->lr = 0x80015A38u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80015A38:
    ctx->pc = 0x80015A38u;
    ctx->downcount -= 7;
    // 80015A38: addi    r31, r1, 8
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(8);

label_80015A3C:
    ctx->pc = 0x80015A3Cu;
    // 80015A3C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80015A40:
    ctx->pc = 0x80015A40u;
    // 80015A40: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80015A44:
    ctx->pc = 0x80015A44u;
    // 80015A44: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80015A48:
    ctx->pc = 0x80015A48u;
    // 80015A48: li      r6, 12
    ctx->gpr[6] = (u32)(s32)(12);

label_80015A4C:
    ctx->pc = 0x80015A4Cu;
    // 80015A4C: addi    r7, r1, 1160
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(1160);

label_80015A50:
    ctx->pc = 0x80015A50u;
    // 80015A50: bl      0x80173540
    {
            ctx->lr = 0x80015A54u;
            ctx->pc = 0x80173540u;
            return;
    }

label_80015A54:
    ctx->pc = 0x80015A54u;
    ctx->downcount -= 1;
    // 80015A54: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015A58:
    ctx->downcount -= 3;
    // 80015A58: or   r0, r28, r28
    {
        ctx->gpr[0] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80015A5C:
    // 80015A5C: cmpwi   r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015A60:
    // 80015A60: bc    4, 0, 0x80015A68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015A68;
        }
    }

label_80015A64:
    ctx->downcount -= 1;
    // 80015A64: addi    r0, r28, 7
    ctx->gpr[0] = ctx->gpr[28] + (u32)(s32)(7);

label_80015A68:
    ctx->downcount -= 28;
    // 80015A68: srawi r0, r0, 3
    {
        u32 sh = 3u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_80015A6C:
    // 80015A6C: addi    r3, r26, -20100
    ctx->gpr[3] = ctx->gpr[26] + (u32)(s32)(-20100);

label_80015A70:
    // 80015A70: mulli   r9, r0, 48
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)48);

label_80015A74:
    // 80015A74: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80015A78:
    // 80015A78: subf   r0, r0, r28
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[28];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_80015A7C:
    // 80015A7C: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_80015A80:
    // 80015A80: add   r9, r9, r0
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80015A84:
    // 80015A84: addi    r29, r9, 40
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(40);

label_80015A88:
    // 80015A88: addi    r0, r9, 8
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(8);

label_80015A8C:
    // 80015A8C: addi    r11, r9, 16
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(16);

label_80015A90:
    // 80015A90: addi    r10, r9, 24
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(24);

label_80015A94:
    // 80015A94: addi    r30, r9, 32
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(32);

label_80015A98:
    // 80015A98: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80015A9C:
    // 80015A9C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_80015AA0:
    // 80015AA0: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80015AA4:
    // 80015AA4: rlwinm r10, r10, 2, 0, 29
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 2u) & 0xFFFFFFFCu;
    }

label_80015AA8:
    // 80015AA8: rlwinm r30, r30, 2, 0, 29
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_80015AAC:
    // 80015AAC: rlwinm r29, r29, 2, 0, 29
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[29], 2u) & 0xFFFFFFFCu;
    }

label_80015AB0:
    ctx->pc = 0x80015AB0u;
    // 80015AB0: lwzx    r4, r31, r9
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[9];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80015AB4:
    ctx->pc = 0x80015AB4u;
    // 80015AB4: lwzx    r5, r31, r0
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80015AB8:
    ctx->pc = 0x80015AB8u;
    // 80015AB8: lwzx    r6, r31, r11
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[11];
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80015ABC:
    ctx->pc = 0x80015ABCu;
    // 80015ABC: lwzx    r7, r31, r10
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[10];
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80015AC0:
    ctx->pc = 0x80015AC0u;
    // 80015AC0: lwzx    r8, r31, r30
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[30];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80015AC4:
    ctx->pc = 0x80015AC4u;
    // 80015AC4: lwzx    r9, r31, r29
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[29];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80015AC8:
    // 80015AC8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80015ACC:
    // 80015ACC: bl      0x80172A0C
    {
            ctx->lr = 0x80015AD0u;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80015AD0:
    ctx->downcount -= 2;
    // 80015AD0: cmpwi   r28, 47
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(47);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015AD4:
    // 80015AD4: bc    4, 1, 0x80015A58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015A58u;
                return;
            }
            goto label_80015A58;
        }
    }

label_80015AD8:
    ctx->pc = 0x80015AD8u;
    ctx->downcount -= 5;
    // 80015AD8: lwz     r4, 1160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1160);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80015ADC:
    ctx->pc = 0x80015ADCu;
    // 80015ADC: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80015AE0:
    ctx->pc = 0x80015AE0u;
    // 80015AE0: addi    r3, r3, -20072
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20072);

label_80015AE4:
    ctx->pc = 0x80015AE4u;
    // 80015AE4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80015AE8:
    ctx->pc = 0x80015AE8u;
    // 80015AE8: bl      0x80172A0C
    {
            ctx->lr = 0x80015AECu;
            ctx->pc = 0x80172A0Cu;
            return;
    }

label_80015AEC:
    ctx->pc = 0x80015AECu;
    ctx->downcount -= 2;
    // 80015AEC: lwz     r3, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80015AF0:
    ctx->pc = 0x80015AF0u;
    // 80015AF0: bl      0x80173BC4
    {
            ctx->lr = 0x80015AF4u;
            ctx->pc = 0x80173BC4u;
            return;
    }

label_80015AF4:
    ctx->pc = 0x80015AF4u;
    ctx->downcount -= 17;
    // 80015AF4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80015AF8:
    ctx->pc = 0x80015AF8u;
    // 80015AF8: lwz     r0, 1196(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1196);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015AFC:
    ctx->pc = 0x80015AFCu;
    // 80015AFC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015B00:
    ctx->pc = 0x80015B00u;
    // 80015B00: lmw     r26, 1168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1168);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80015B04:
    ctx->pc = 0x80015B04u;
    // 80015B04: addi    r1, r1, 1192
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(1192);

label_80015B08:
    ctx->pc = 0x80015B08u;
    // 80015B08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015B0C:
    ctx->pc = 0x80015B0Cu;
    ctx->downcount -= 19;
    // 80015B0C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80015B10:
    ctx->pc = 0x80015B10u;
    // 80015B10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015B14:
    ctx->pc = 0x80015B14u;
    // 80015B14: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80015B18:
    ctx->pc = 0x80015B18u;
    // 80015B18: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015B1C:
    ctx->pc = 0x80015B1Cu;
    // 80015B1C: lbz     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80015B20:
    ctx->pc = 0x80015B20u;
    // 80015B20: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80015B24:
    ctx->pc = 0x80015B24u;
    // 80015B24: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80015B28:
    ctx->pc = 0x80015B28u;
    // 80015B28: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015B2C:
    ctx->pc = 0x80015B2Cu;
    // 80015B2C: bc    12, 2, 0x80015B80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80015B80;
        }
    }

label_80015B30:
    ctx->downcount -= 2;
    // 80015B30: cmpwi   r11, 10
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015B34:
    // 80015B34: bc    4, 2, 0x80015B48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015B48;
        }
    }

label_80015B38:
    ctx->downcount -= 2;
    // 80015B38: cmpw    r31, r30
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015B3C:
    // 80015B3C: bc    4, 0, 0x80015B44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015B44;
        }
    }

label_80015B40:
    ctx->downcount -= 1;
    // 80015B40: or   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015B44:
    ctx->downcount -= 1;
    // 80015B44: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80015B48:
    ctx->downcount -= 2;
    // 80015B48: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80015B4C:
    // 80015B4C: bl      0x80173E1C
    {
            ctx->lr = 0x80015B50u;
            ctx->pc = 0x80173E1Cu;
            return;
    }

label_80015B50:
    ctx->pc = 0x80015B50u;
    ctx->downcount -= 55;
    // 80015B50: lwz     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80015B54:
    ctx->pc = 0x80015B54u;
    // 80015B54: lha     r0, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015B58:
    ctx->pc = 0x80015B58u;
    // 80015B58: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80015B5C:
    // 80015B5C: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_80015B60:
    ctx->pc = 0x80015B60u;
    // 80015B60: lha     r10, -28010(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28010);
        ctx->gpr[10] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_80015B64:
    ctx->pc = 0x80015B64u;
    // 80015B64: lhz     r9, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80015B68:
    ctx->pc = 0x80015B68u;
    // 80015B68: lbz     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80015B6C:
    // 80015B6C: divw   r0, r0, r9
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[9];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80015B70:
    // 80015B70: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015B74:
    // 80015B74: add   r0, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80015B78:
    // 80015B78: add   r30, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_80015B7C:
    // 80015B7C: bc    4, 2, 0x80015B30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015B30u;
                return;
            }
            goto label_80015B30;
        }
    }

label_80015B80:
    ctx->pc = 0x80015B80u;
    ctx->downcount -= 2;
    // 80015B80: cmpw    r31, r30
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015B84:
    ctx->pc = 0x80015B84u;
    // 80015B84: bc    4, 0, 0x80015B8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015B8C;
        }
    }

label_80015B88:
    ctx->pc = 0x80015B88u;
    ctx->downcount -= 1;
    // 80015B88: or   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015B8C:
    ctx->pc = 0x80015B8Cu;
    ctx->downcount -= 2;
    // 80015B8C: addic.  r3, r31, 15
    {
        u64 a = ctx->gpr[31];
        u64 b = (u32)(s32)(15);
        u64 res = a + b;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80015B90:
    ctx->pc = 0x80015B90u;
    // 80015B90: bc    4, 0, 0x80015B98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015B98;
        }
    }

label_80015B94:
    ctx->pc = 0x80015B94u;
    ctx->downcount -= 1;
    // 80015B94: addi    r3, r31, 30
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(30);

label_80015B98:
    ctx->pc = 0x80015B98u;
    ctx->downcount -= 17;
    // 80015B98: srawi r3, r3, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[3];
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

label_80015B9C:
    ctx->pc = 0x80015B9Cu;
    // 80015B9C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015BA0:
    ctx->pc = 0x80015BA0u;
    // 80015BA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015BA4:
    ctx->pc = 0x80015BA4u;
    // 80015BA4: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80015BA8:
    ctx->pc = 0x80015BA8u;
    // 80015BA8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80015BAC:
    ctx->pc = 0x80015BACu;
    // 80015BAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015BB0:
    ctx->pc = 0x80015BB0u;
    ctx->downcount -= 6;
    // 80015BB0: lbz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80015BB4:
    ctx->pc = 0x80015BB4u;
    // 80015BB4: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_80015BB8:
    ctx->pc = 0x80015BB8u;
    // 80015BB8: lwz     r11, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80015BBC:
    ctx->pc = 0x80015BBCu;
    // 80015BBC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015BC0:
    ctx->pc = 0x80015BC0u;
    // 80015BC0: lhz     r9, -28012(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28012);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_80015BC4:
    ctx->pc = 0x80015BC4u;
    // 80015BC4: bc    12, 2, 0x80015BE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80015BE0;
        }
    }

label_80015BC8:
    ctx->downcount -= 2;
    // 80015BC8: cmpwi   r0, 10
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015BCC:
    // 80015BCC: bc    4, 2, 0x80015BD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015BD4;
        }
    }

label_80015BD0:
    ctx->downcount -= 1;
    // 80015BD0: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_80015BD4:
    ctx->pc = 0x80015BD4u;
    ctx->downcount -= 3;
    // 80015BD4: lbzu     r0, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80015BD8:
    // 80015BD8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015BDC:
    // 80015BDC: bc    4, 2, 0x80015BC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015BC8u;
                return;
            }
            goto label_80015BC8;
        }
    }

label_80015BE0:
    ctx->pc = 0x80015BE0u;
    ctx->downcount -= 55;
    // 80015BE0: lhz     r0, 14(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80015BE4:
    ctx->pc = 0x80015BE4u;
    // 80015BE4: extsh r9, r9
    {
        ctx->gpr[9] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_80015BE8:
    ctx->pc = 0x80015BE8u;
    // 80015BE8: lhz     r11, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read16(ctx, ea);
    }

label_80015BEC:
    ctx->pc = 0x80015BECu;
    // 80015BEC: mullw   r0, r0, r9
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[9];
        ctx->gpr[0] = (u32)product;
    }

label_80015BF0:
    ctx->pc = 0x80015BF0u;
    // 80015BF0: divw   r0, r0, r11
    {
        s32 dividend = (s32)ctx->gpr[0];
        s32 divisor = (s32)ctx->gpr[11];
        bool ov = divisor == 0 || ((u32)dividend == 0x80000000u && divisor == -1);
        ctx->gpr[0] = ov ? ((dividend < 0) ? 0xFFFFFFFFu : 0u) : (u32)(dividend / divisor);
    }

label_80015BF4:
    ctx->pc = 0x80015BF4u;
    // 80015BF4: mullw   r10, r10, r0
    {
        s64 product = (s64)(s32)ctx->gpr[10] * (s64)(s32)ctx->gpr[0];
        ctx->gpr[10] = (u32)product;
    }

label_80015BF8:
    ctx->pc = 0x80015BF8u;
    // 80015BF8: addic.  r3, r10, 15
    {
        u64 a = ctx->gpr[10];
        u64 b = (u32)(s32)(15);
        u64 res = a + b;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80015BFC:
    ctx->pc = 0x80015BFCu;
    // 80015BFC: bc    4, 0, 0x80015C04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80015C04;
        }
    }

label_80015C00:
    ctx->pc = 0x80015C00u;
    ctx->downcount -= 1;
    // 80015C00: addi    r3, r10, 30
    ctx->gpr[3] = ctx->gpr[10] + (u32)(s32)(30);

label_80015C04:
    ctx->pc = 0x80015C04u;
    ctx->downcount -= 2;
    // 80015C04: srawi r3, r3, 4
    {
        u32 sh = 4u;
        u32 value = ctx->gpr[3];
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

label_80015C08:
    ctx->pc = 0x80015C08u;
    // 80015C08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015C0C:
    ctx->pc = 0x80015C0Cu;
    ctx->downcount -= 22;
    // 80015C0C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80015C10:
    ctx->pc = 0x80015C10u;
    // 80015C10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015C14:
    ctx->pc = 0x80015C14u;
    // 80015C14: stmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80015C18:
    ctx->pc = 0x80015C18u;
    // 80015C18: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015C1C:
    ctx->pc = 0x80015C1Cu;
    // 80015C1C: or   r28, r4, r4
    {
        ctx->gpr[28] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80015C20:
    ctx->pc = 0x80015C20u;
    // 80015C20: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80015C24:
    ctx->pc = 0x80015C24u;
    // 80015C24: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015C28:
    ctx->pc = 0x80015C28u;
    // 80015C28: lis     r4, 255
    ctx->gpr[4] = ((u32)(s32)(255) << 16);

label_80015C2C:
    ctx->pc = 0x80015C2Cu;
    // 80015C2C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80015C30:
    ctx->pc = 0x80015C30u;
    // 80015C30: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015C34:
    ctx->pc = 0x80015C34u;
    // 80015C34: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_80015C38:
    ctx->pc = 0x80015C38u;
    // 80015C38: bl      0x8019A9BC
    {
            ctx->lr = 0x80015C3Cu;
            ctx->pc = 0x8019A9BCu;
            return;
    }

label_80015C3C:
    ctx->pc = 0x80015C3Cu;
    ctx->downcount -= 3;
    // 80015C3C: lwz     r3, -28008(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28008);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80015C40:
    ctx->pc = 0x80015C40u;
    // 80015C40: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80015C44:
    ctx->pc = 0x80015C44u;
    // 80015C44: bl      0x8019AC68
    {
            ctx->lr = 0x80015C48u;
            ctx->pc = 0x8019AC68u;
            return;
    }

label_80015C48:
    ctx->pc = 0x80015C48u;
    ctx->downcount -= 2;
    // 80015C48: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80015C4C:
    ctx->pc = 0x80015C4Cu;
    // 80015C4C: bl      0x800054CC
    {
            ctx->lr = 0x80015C50u;
            ctx->pc = 0x800054CCu;
            return;
    }

label_80015C50:
    ctx->pc = 0x80015C50u;
    ctx->downcount -= 4;
    // 80015C50: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015C54:
    ctx->pc = 0x80015C54u;
    // 80015C54: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80015C58:
    ctx->pc = 0x80015C58u;
    // 80015C58: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80015C5C:
    ctx->pc = 0x80015C5Cu;
    // 80015C5C: bl      0x8019F050
    {
            ctx->lr = 0x80015C60u;
            ctx->pc = 0x8019F050u;
            return;
    }

label_80015C60:
    ctx->pc = 0x80015C60u;
    ctx->downcount -= 2;
    // 80015C60: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015C64:
    ctx->pc = 0x80015C64u;
    // 80015C64: bl      0x8019B960
    {
            ctx->lr = 0x80015C68u;
            ctx->pc = 0x8019B960u;
            return;
    }

label_80015C68:
    ctx->pc = 0x80015C68u;
    ctx->downcount -= 2;
    // 80015C68: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80015C6C:
    ctx->pc = 0x80015C6Cu;
    // 80015C6C: bl      0x8019EA20
    {
            ctx->lr = 0x80015C70u;
            ctx->pc = 0x8019EA20u;
            return;
    }

label_80015C70:
    ctx->pc = 0x80015C70u;
    ctx->downcount -= 3;
    // 80015C70: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015C74:
    ctx->pc = 0x80015C74u;
    // 80015C74: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80015C78:
    ctx->pc = 0x80015C78u;
    // 80015C78: bl      0x8019E018
    {
            ctx->lr = 0x80015C7Cu;
            ctx->pc = 0x8019E018u;
            return;
    }

label_80015C7C:
    ctx->pc = 0x80015C7Cu;
    ctx->downcount -= 5;
    // 80015C7C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015C80:
    ctx->pc = 0x80015C80u;
    // 80015C80: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015C84:
    ctx->pc = 0x80015C84u;
    // 80015C84: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80015C88:
    ctx->pc = 0x80015C88u;
    // 80015C88: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80015C8C:
    ctx->pc = 0x80015C8Cu;
    // 80015C8C: bl      0x8019E844
    {
            ctx->lr = 0x80015C90u;
            ctx->pc = 0x8019E844u;
            return;
    }

label_80015C90:
    ctx->pc = 0x80015C90u;
    ctx->downcount -= 6;
    // 80015C90: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015C94:
    ctx->pc = 0x80015C94u;
    // 80015C94: li      r4, 24
    ctx->gpr[4] = (u32)(s32)(24);

label_80015C98:
    ctx->pc = 0x80015C98u;
    // 80015C98: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015C9C:
    ctx->pc = 0x80015C9Cu;
    // 80015C9C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015CA0:
    ctx->pc = 0x80015CA0u;
    // 80015CA0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80015CA4:
    ctx->pc = 0x80015CA4u;
    // 80015CA4: bl      0x80015908
    {
            ctx->lr = 0x80015CA8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015908u;
                return;
            }
            goto label_80015908;
    }

label_80015CA8:
    ctx->pc = 0x80015CA8u;
    ctx->downcount -= 2;
    // 80015CA8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015CAC:
    ctx->pc = 0x80015CACu;
    // 80015CAC: bl      0x80015B0C
    {
            ctx->lr = 0x80015CB0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015B0Cu;
                return;
            }
            goto label_80015B0C;
    }

label_80015CB0:
    ctx->pc = 0x80015CB0u;
    ctx->downcount -= 4;
    // 80015CB0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015CB4:
    ctx->pc = 0x80015CB4u;
    // 80015CB4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015CB8:
    ctx->pc = 0x80015CB8u;
    // 80015CB8: addi    r30, r30, 7
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(7);

label_80015CBC:
    ctx->pc = 0x80015CBCu;
    // 80015CBC: bl      0x80015BB0
    {
            ctx->lr = 0x80015CC0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015BB0u;
                return;
            }
            goto label_80015BB0;
    }

label_80015CC0:
    ctx->pc = 0x80015CC0u;
    ctx->downcount -= 9;
    // 80015CC0: rlwinm r30, r30, 0, 0, 28
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0xFFFFFFF8u;
    }

label_80015CC4:
    ctx->pc = 0x80015CC4u;
    // 80015CC4: addi    r29, r3, 7
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(7);

label_80015CC8:
    ctx->pc = 0x80015CC8u;
    // 80015CC8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015CCC:
    ctx->pc = 0x80015CCCu;
    // 80015CCC: rlwinm r29, r29, 0, 0, 28
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[29], 0u) & 0xFFFFFFF8u;
    }

label_80015CD0:
    ctx->pc = 0x80015CD0u;
    // 80015CD0: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80015CD4:
    ctx->pc = 0x80015CD4u;
    // 80015CD4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015CD8:
    ctx->pc = 0x80015CD8u;
    // 80015CD8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80015CDC:
    ctx->pc = 0x80015CDCu;
    // 80015CDC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80015CE0:
    ctx->pc = 0x80015CE0u;
    // 80015CE0: bl      0x8000E4C4
    {
            ctx->lr = 0x80015CE4u;
            ctx->pc = 0x8000E4C4u;
            return;
    }

label_80015CE4:
    ctx->pc = 0x80015CE4u;
    ctx->downcount -= 2;
    // 80015CE4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80015CE8:
    ctx->pc = 0x80015CE8u;
    // 80015CE8: bl      0x8000F424
    {
            ctx->lr = 0x80015CECu;
            ctx->pc = 0x8000F424u;
            return;
    }

label_80015CEC:
    ctx->pc = 0x80015CECu;
    ctx->downcount -= 8;
    // 80015CEC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80015CF0:
    ctx->pc = 0x80015CF0u;
    // 80015CF0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80015CF4:
    ctx->pc = 0x80015CF4u;
    // 80015CF4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80015CF8:
    ctx->pc = 0x80015CF8u;
    // 80015CF8: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015CFC:
    ctx->pc = 0x80015CFCu;
    // 80015CFC: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015D00:
    ctx->pc = 0x80015D00u;
    // 80015D00: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015D04:
    ctx->pc = 0x80015D04u;
    // 80015D04: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80015D08:
    ctx->pc = 0x80015D08u;
    // 80015D08: bl      0x8000F38C
    {
            ctx->lr = 0x80015D0Cu;
            ctx->pc = 0x8000F38Cu;
            return;
    }

label_80015D0C:
    ctx->pc = 0x80015D0Cu;
    ctx->downcount -= 2;
    // 80015D0C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80015D10:
    ctx->pc = 0x80015D10u;
    // 80015D10: bl      0x8000F3F0
    {
            ctx->lr = 0x80015D14u;
            ctx->pc = 0x8000F3F0u;
            return;
    }

label_80015D14:
    ctx->pc = 0x80015D14u;
    ctx->downcount -= 16;
    // 80015D14: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015D18:
    ctx->pc = 0x80015D18u;
    // 80015D18: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015D1C:
    ctx->pc = 0x80015D1Cu;
    // 80015D1C: lmw     r28, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80015D20:
    ctx->pc = 0x80015D20u;
    // 80015D20: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80015D24:
    ctx->pc = 0x80015D24u;
    // 80015D24: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015D28:
    ctx->pc = 0x80015D28u;
    ctx->downcount -= 21;
    // 80015D28: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80015D2C:
    ctx->pc = 0x80015D2Cu;
    // 80015D2C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015D30:
    ctx->pc = 0x80015D30u;
    // 80015D30: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80015D34:
    ctx->pc = 0x80015D34u;
    // 80015D34: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015D38:
    ctx->pc = 0x80015D38u;
    // 80015D38: lwz     r7, -27928(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27928);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80015D3C:
    ctx->pc = 0x80015D3Cu;
    // 80015D3C: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_80015D40:
    ctx->pc = 0x80015D40u;
    // 80015D40: addi    r4, r4, -20060
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-20060);

label_80015D44:
    ctx->pc = 0x80015D44u;
    // 80015D44: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_80015D48:
    ctx->pc = 0x80015D48u;
    // 80015D48: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_80015D4C:
    ctx->pc = 0x80015D4Cu;
    // 80015D4C: lis     r3, 25
    ctx->gpr[3] = ((u32)(s32)(25) << 16);

label_80015D50:
    ctx->pc = 0x80015D50u;
    // 80015D50: bl      0x80039A00
    {
            ctx->lr = 0x80015D54u;
            ctx->pc = 0x80039A00u;
            return;
    }

label_80015D54:
    ctx->pc = 0x80015D54u;
    ctx->downcount -= 3;
    // 80015D54: lis     r30, -32703
    ctx->gpr[30] = ((u32)(s32)(-32703) << 16);

label_80015D58:
    ctx->pc = 0x80015D58u;
    // 80015D58: stw     r3, -28008(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28008);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80015D5C:
    ctx->pc = 0x80015D5Cu;
    // 80015D5C: bl      0x80015284
    {
            ctx->lr = 0x80015D60u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015284u;
                return;
            }
            goto label_80015284;
    }

label_80015D60:
    ctx->pc = 0x80015D60u;
    ctx->downcount -= 3;
    // 80015D60: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80015D64:
    ctx->pc = 0x80015D64u;
    // 80015D64: addi    r3, r3, -20056
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20056);

label_80015D68:
    ctx->pc = 0x80015D68u;
    // 80015D68: bl      0x800159D4
    {
            ctx->lr = 0x80015D6Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800159D4u;
                return;
            }
            goto label_800159D4;
    }

label_80015D6C:
    ctx->pc = 0x80015D6Cu;
    ctx->downcount -= 6;
    // 80015D6C: li      r5, 200
    ctx->gpr[5] = (u32)(s32)(200);

label_80015D70:
    ctx->pc = 0x80015D70u;
    // 80015D70: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80015D74:
    ctx->pc = 0x80015D74u;
    // 80015D74: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_80015D78:
    ctx->pc = 0x80015D78u;
    // 80015D78: li      r4, 320
    ctx->gpr[4] = (u32)(s32)(320);

label_80015D7C:
    ctx->pc = 0x80015D7Cu;
    // 80015D7C: addi    r3, r30, -27488
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27488);

label_80015D80:
    ctx->pc = 0x80015D80u;
    // 80015D80: bl      0x8000E4C4
    {
            ctx->lr = 0x80015D84u;
            ctx->pc = 0x8000E4C4u;
            return;
    }

label_80015D84:
    ctx->pc = 0x80015D84u;
    ctx->downcount -= 2;
    // 80015D84: addi    r3, r30, -27488
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-27488);

label_80015D88:
    ctx->pc = 0x80015D88u;
    // 80015D88: bl      0x8000F424
    {
            ctx->lr = 0x80015D8Cu;
            ctx->pc = 0x8000F424u;
            return;
    }

label_80015D8C:
    ctx->pc = 0x80015D8Cu;
    ctx->downcount -= 5;
    // 80015D8C: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80015D90:
    ctx->pc = 0x80015D90u;
    // 80015D90: lis     r4, -32703
    ctx->gpr[4] = ((u32)(s32)(-32703) << 16);

label_80015D94:
    ctx->pc = 0x80015D94u;
    // 80015D94: addi    r3, r3, -20052
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20052);

label_80015D98:
    ctx->pc = 0x80015D98u;
    // 80015D98: addi    r4, r4, -27420
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27420);

label_80015D9C:
    ctx->pc = 0x80015D9Cu;
    // 80015D9C: bl      0x80015C0C
    {
            ctx->lr = 0x80015DA0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015C0Cu;
                return;
            }
            goto label_80015C0C;
    }

label_80015DA0:
    ctx->pc = 0x80015DA0u;
    ctx->downcount -= 5;
    // 80015DA0: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80015DA4:
    ctx->pc = 0x80015DA4u;
    // 80015DA4: lis     r4, -32703
    ctx->gpr[4] = ((u32)(s32)(-32703) << 16);

label_80015DA8:
    ctx->pc = 0x80015DA8u;
    // 80015DA8: addi    r3, r3, -20028
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20028);

label_80015DAC:
    ctx->pc = 0x80015DACu;
    // 80015DAC: addi    r4, r4, -27352
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27352);

label_80015DB0:
    ctx->pc = 0x80015DB0u;
    // 80015DB0: bl      0x80015C0C
    {
            ctx->lr = 0x80015DB4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015C0Cu;
                return;
            }
            goto label_80015C0C;
    }

label_80015DB4:
    ctx->pc = 0x80015DB4u;
    ctx->downcount -= 5;
    // 80015DB4: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80015DB8:
    ctx->pc = 0x80015DB8u;
    // 80015DB8: lis     r4, -32703
    ctx->gpr[4] = ((u32)(s32)(-32703) << 16);

label_80015DBC:
    ctx->pc = 0x80015DBCu;
    // 80015DBC: addi    r3, r3, -20016
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20016);

label_80015DC0:
    ctx->pc = 0x80015DC0u;
    // 80015DC0: addi    r4, r4, -27284
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27284);

label_80015DC4:
    ctx->pc = 0x80015DC4u;
    // 80015DC4: bl      0x80015C0C
    {
            ctx->lr = 0x80015DC8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015C0Cu;
                return;
            }
            goto label_80015C0C;
    }

label_80015DC8:
    ctx->pc = 0x80015DC8u;
    ctx->downcount -= 5;
    // 80015DC8: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80015DCC:
    ctx->pc = 0x80015DCCu;
    // 80015DCC: lis     r4, -32703
    ctx->gpr[4] = ((u32)(s32)(-32703) << 16);

label_80015DD0:
    ctx->pc = 0x80015DD0u;
    // 80015DD0: addi    r3, r3, -20000
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-20000);

label_80015DD4:
    ctx->pc = 0x80015DD4u;
    // 80015DD4: addi    r4, r4, -27216
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-27216);

label_80015DD8:
    ctx->pc = 0x80015DD8u;
    // 80015DD8: bl      0x80015C0C
    {
            ctx->lr = 0x80015DDCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015C0Cu;
                return;
            }
            goto label_80015C0C;
    }

label_80015DDC:
    ctx->pc = 0x80015DDCu;
    ctx->downcount -= 16;
    // 80015DDC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015DE0:
    ctx->pc = 0x80015DE0u;
    // 80015DE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015DE4:
    ctx->pc = 0x80015DE4u;
    // 80015DE4: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80015DE8:
    ctx->pc = 0x80015DE8u;
    // 80015DE8: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80015DEC:
    ctx->pc = 0x80015DECu;
    // 80015DEC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015DF0:
    ctx->pc = 0x80015DF0u;
    ctx->downcount -= 5;
    // 80015DF0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80015DF4:
    ctx->pc = 0x80015DF4u;
    // 80015DF4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015DF8:
    ctx->pc = 0x80015DF8u;
    // 80015DF8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015DFC:
    ctx->pc = 0x80015DFCu;
    // 80015DFC: lwz     r3, -28008(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28008);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80015E00:
    ctx->pc = 0x80015E00u;
    // 80015E00: bl      0x80039A44
    {
            ctx->lr = 0x80015E04u;
            ctx->pc = 0x80039A44u;
            return;
    }

label_80015E04:
    ctx->pc = 0x80015E04u;
    ctx->downcount -= 2;
    // 80015E04: lwz     r3, -28020(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28020);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80015E08:
    ctx->pc = 0x80015E08u;
    // 80015E08: bl      0x80039A44
    {
            ctx->lr = 0x80015E0Cu;
            ctx->pc = 0x80039A44u;
            return;
    }

label_80015E0C:
    ctx->pc = 0x80015E0Cu;
    ctx->downcount -= 5;
    // 80015E0C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015E10:
    ctx->pc = 0x80015E10u;
    // 80015E10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015E14:
    ctx->pc = 0x80015E14u;
    // 80015E14: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80015E18:
    ctx->pc = 0x80015E18u;
    // 80015E18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80015E1C:
    ctx->pc = 0x80015E1Cu;
    ctx->downcount -= 21;
    // 80015E1C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80015E20:
    ctx->pc = 0x80015E20u;
    // 80015E20: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80015E24:
    ctx->pc = 0x80015E24u;
    // 80015E24: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80015E28:
    ctx->pc = 0x80015E28u;
    // 80015E28: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015E2C:
    ctx->pc = 0x80015E2Cu;
    // 80015E2C: lwz     r0, -32516(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32516);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015E30:
    ctx->pc = 0x80015E30u;
    // 80015E30: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015E34:
    ctx->pc = 0x80015E34u;
    // 80015E34: lis     r11, -32703
    ctx->gpr[11] = ((u32)(s32)(-32703) << 16);

label_80015E38:
    ctx->pc = 0x80015E38u;
    // 80015E38: addi    r31, r9, -19964
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-19964);

label_80015E3C:
    ctx->pc = 0x80015E3Cu;
    // 80015E3C: addi    r29, r11, -27488
    ctx->gpr[29] = ctx->gpr[11] + (u32)(s32)(-27488);

label_80015E40:
    ctx->pc = 0x80015E40u;
    // 80015E40: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80015E44:
    ctx->pc = 0x80015E44u;
    // 80015E44: bc    12, 2, 0x80015F04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80015F04;
        }
    }

label_80015E48:
    ctx->pc = 0x80015E48u;
    ctx->downcount -= 6;
    // 80015E48: lwz     r11, -28184(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28184);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80015E4C:
    ctx->pc = 0x80015E4Cu;
    // 80015E4C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015E50:
    ctx->pc = 0x80015E50u;
    // 80015E50: lfs     f1, -19888(r9)
    if (!ppc_fp_available(ctx, 0x80015E50u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19888);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80015E54:
    ctx->pc = 0x80015E54u;
    // 80015E54: lhz     r4, 6(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(6);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_80015E58:
    ctx->pc = 0x80015E58u;
    // 80015E58: lhz     r3, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80015E5C:
    ctx->pc = 0x80015E5Cu;
    // 80015E5C: bl      0x80014EB8
    {
            ctx->lr = 0x80015E60u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80014EB8u;
                return;
            }
            goto label_80014EB8;
    }

label_80015E60:
    ctx->pc = 0x80015E60u;
    ctx->downcount -= 4;
    // 80015E60: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015E64:
    ctx->pc = 0x80015E64u;
    // 80015E64: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80015E68:
    ctx->pc = 0x80015E68u;
    // 80015E68: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80015E6C:
    ctx->pc = 0x80015E6Cu;
    // 80015E6C: bl      0x8019F050
    {
            ctx->lr = 0x80015E70u;
            ctx->pc = 0x8019F050u;
            return;
    }

label_80015E70:
    ctx->pc = 0x80015E70u;
    ctx->downcount -= 2;
    // 80015E70: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015E74:
    ctx->pc = 0x80015E74u;
    // 80015E74: bl      0x8019B960
    {
            ctx->lr = 0x80015E78u;
            ctx->pc = 0x8019B960u;
            return;
    }

label_80015E78:
    ctx->pc = 0x80015E78u;
    ctx->downcount -= 2;
    // 80015E78: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80015E7C:
    ctx->pc = 0x80015E7Cu;
    // 80015E7C: bl      0x8019EA20
    {
            ctx->lr = 0x80015E80u;
            ctx->pc = 0x8019EA20u;
            return;
    }

label_80015E80:
    ctx->pc = 0x80015E80u;
    ctx->downcount -= 3;
    // 80015E80: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015E84:
    ctx->pc = 0x80015E84u;
    // 80015E84: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80015E88:
    ctx->pc = 0x80015E88u;
    // 80015E88: bl      0x8019E018
    {
            ctx->lr = 0x80015E8Cu;
            ctx->pc = 0x8019E018u;
            return;
    }

label_80015E8C:
    ctx->pc = 0x80015E8Cu;
    ctx->downcount -= 5;
    // 80015E8C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015E90:
    ctx->pc = 0x80015E90u;
    // 80015E90: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015E94:
    ctx->pc = 0x80015E94u;
    // 80015E94: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80015E98:
    ctx->pc = 0x80015E98u;
    // 80015E98: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80015E9C:
    ctx->pc = 0x80015E9Cu;
    // 80015E9C: bl      0x8019E844
    {
            ctx->lr = 0x80015EA0u;
            ctx->pc = 0x8019E844u;
            return;
    }

label_80015EA0:
    ctx->pc = 0x80015EA0u;
    ctx->downcount -= 6;
    // 80015EA0: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_80015EA4:
    ctx->pc = 0x80015EA4u;
    // 80015EA4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015EA8:
    ctx->pc = 0x80015EA8u;
    // 80015EA8: or   r6, r31, r31
    {
        ctx->gpr[6] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80015EAC:
    ctx->pc = 0x80015EACu;
    // 80015EAC: li      r3, 8
    ctx->gpr[3] = (u32)(s32)(8);

label_80015EB0:
    ctx->pc = 0x80015EB0u;
    // 80015EB0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80015EB4:
    ctx->pc = 0x80015EB4u;
    // 80015EB4: bl      0x80015908
    {
            ctx->lr = 0x80015EB8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015908u;
                return;
            }
            goto label_80015908;
    }

label_80015EB8:
    ctx->pc = 0x80015EB8u;
    ctx->downcount -= 1;
    // 80015EB8: bl      0x8000914C
    {
            ctx->lr = 0x80015EBCu;
            ctx->pc = 0x8000914Cu;
            return;
    }

label_80015EBC:
    ctx->pc = 0x80015EBCu;
    ctx->downcount -= 2;
    // 80015EBC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80015EC0:
    ctx->pc = 0x80015EC0u;
    // 80015EC0: bl      0x80015B0C
    {
            ctx->lr = 0x80015EC4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015B0Cu;
                return;
            }
            goto label_80015B0C;
    }

label_80015EC4:
    ctx->pc = 0x80015EC4u;
    ctx->downcount -= 3;
    // 80015EC4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015EC8:
    ctx->pc = 0x80015EC8u;
    // 80015EC8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80015ECC:
    ctx->pc = 0x80015ECCu;
    // 80015ECC: bl      0x80015BB0
    {
            ctx->lr = 0x80015ED0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015BB0u;
                return;
            }
            goto label_80015BB0;
    }

label_80015ED0:
    ctx->pc = 0x80015ED0u;
    ctx->downcount -= 8;
    // 80015ED0: or   r7, r3, r3
    {
        ctx->gpr[7] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80015ED4:
    ctx->pc = 0x80015ED4u;
    // 80015ED4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_80015ED8:
    ctx->pc = 0x80015ED8u;
    // 80015ED8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_80015EDC:
    ctx->pc = 0x80015EDCu;
    // 80015EDC: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80015EE0:
    ctx->pc = 0x80015EE0u;
    // 80015EE0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015EE4:
    ctx->pc = 0x80015EE4u;
    // 80015EE4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015EE8:
    ctx->pc = 0x80015EE8u;
    // 80015EE8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80015EEC:
    ctx->pc = 0x80015EECu;
    // 80015EEC: bl      0x8000F38C
    {
            ctx->lr = 0x80015EF0u;
            ctx->pc = 0x8000F38Cu;
            return;
    }

label_80015EF0:
    ctx->pc = 0x80015EF0u;
    ctx->downcount -= 2;
    // 80015EF0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015EF4:
    ctx->pc = 0x80015EF4u;
    // 80015EF4: bl      0x8000F3F0
    {
            ctx->lr = 0x80015EF8u;
            ctx->pc = 0x8000F3F0u;
            return;
    }

label_80015EF8:
    ctx->pc = 0x80015EF8u;
    ctx->downcount -= 3;
    // 80015EF8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80015EFC:
    ctx->pc = 0x80015EFCu;
    // 80015EFC: stw     r0, -32516(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32516);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80015F00:
    ctx->pc = 0x80015F00u;
    // 80015F00: b       0x80015FEC
    {
            goto label_80015FEC;
    }

label_80015F04:
    ctx->pc = 0x80015F04u;
    ctx->downcount -= 5;
    // 80015F04: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015F08:
    ctx->pc = 0x80015F08u;
    // 80015F08: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80015F0C:
    ctx->pc = 0x80015F0Cu;
    // 80015F0C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80015F10:
    ctx->pc = 0x80015F10u;
    // 80015F10: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_80015F14:
    ctx->pc = 0x80015F14u;
    // 80015F14: bl      0x8019F050
    {
            ctx->lr = 0x80015F18u;
            ctx->pc = 0x8019F050u;
            return;
    }

label_80015F18:
    ctx->pc = 0x80015F18u;
    ctx->downcount -= 2;
    // 80015F18: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015F1C:
    ctx->pc = 0x80015F1Cu;
    // 80015F1C: bl      0x8019B960
    {
            ctx->lr = 0x80015F20u;
            ctx->pc = 0x8019B960u;
            return;
    }

label_80015F20:
    ctx->pc = 0x80015F20u;
    ctx->downcount -= 2;
    // 80015F20: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80015F24:
    ctx->pc = 0x80015F24u;
    // 80015F24: bl      0x8019EA20
    {
            ctx->lr = 0x80015F28u;
            ctx->pc = 0x8019EA20u;
            return;
    }

label_80015F28:
    ctx->pc = 0x80015F28u;
    ctx->downcount -= 3;
    // 80015F28: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015F2C:
    ctx->pc = 0x80015F2Cu;
    // 80015F2C: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80015F30:
    ctx->pc = 0x80015F30u;
    // 80015F30: bl      0x8019E018
    {
            ctx->lr = 0x80015F34u;
            ctx->pc = 0x8019E018u;
            return;
    }

label_80015F34:
    ctx->pc = 0x80015F34u;
    ctx->downcount -= 5;
    // 80015F34: li      r6, 255
    ctx->gpr[6] = (u32)(s32)(255);

label_80015F38:
    ctx->pc = 0x80015F38u;
    // 80015F38: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015F3C:
    ctx->pc = 0x80015F3Cu;
    // 80015F3C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80015F40:
    ctx->pc = 0x80015F40u;
    // 80015F40: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80015F44:
    ctx->pc = 0x80015F44u;
    // 80015F44: bl      0x8019E844
    {
            ctx->lr = 0x80015F48u;
            ctx->pc = 0x8019E844u;
            return;
    }

label_80015F48:
    ctx->pc = 0x80015F48u;
    ctx->downcount -= 7;
    // 80015F48: lis     r6, -32738
    ctx->gpr[6] = ((u32)(s32)(-32738) << 16);

label_80015F4C:
    ctx->pc = 0x80015F4Cu;
    // 80015F4C: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_80015F50:
    ctx->pc = 0x80015F50u;
    // 80015F50: addi    r6, r6, -19936
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-19936);

label_80015F54:
    ctx->pc = 0x80015F54u;
    // 80015F54: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80015F58:
    ctx->pc = 0x80015F58u;
    // 80015F58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80015F5C:
    ctx->pc = 0x80015F5Cu;
    // 80015F5C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80015F60:
    ctx->pc = 0x80015F60u;
    // 80015F60: bl      0x80015908
    {
            ctx->lr = 0x80015F64u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80015908u;
                return;
            }
            goto label_80015908;
    }

label_80015F64:
    ctx->pc = 0x80015F64u;
    ctx->downcount -= 10;
    // 80015F64: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80015F68:
    ctx->pc = 0x80015F68u;
    // 80015F68: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_80015F6C:
    ctx->pc = 0x80015F6Cu;
    // 80015F6C: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_80015F70:
    ctx->pc = 0x80015F70u;
    // 80015F70: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015F74:
    ctx->pc = 0x80015F74u;
    // 80015F74: lfs     f3, -19876(r9)
    if (!ppc_fp_available(ctx, 0x80015F74u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19876);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_80015F78:
    ctx->pc = 0x80015F78u;
    // 80015F78: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80015F7C:
    ctx->pc = 0x80015F7Cu;
    // 80015F7C: lfs     f1, -19884(r10)
    if (!ppc_fp_available(ctx, 0x80015F7Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-19884);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80015F80:
    ctx->pc = 0x80015F80u;
    // 80015F80: lfs     f2, -19880(r8)
    if (!ppc_fp_available(ctx, 0x80015F80u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-19880);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80015F84:
    ctx->pc = 0x80015F84u;
    // 80015F84: lfs     f4, -19872(r11)
    if (!ppc_fp_available(ctx, 0x80015F84u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-19872);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_80015F88:
    ctx->pc = 0x80015F88u;
    // 80015F88: bl      0x8000E8EC
    {
            ctx->lr = 0x80015F8Cu;
            ctx->pc = 0x8000E8ECu;
            return;
    }

label_80015F8C:
    ctx->pc = 0x80015F8Cu;
    ctx->downcount -= 6;
    // 80015F8C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015F90:
    ctx->pc = 0x80015F90u;
    // 80015F90: lfs     f1, -19868(r30)
    if (!ppc_fp_available(ctx, 0x80015F90u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-19868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80015F94:
    ctx->pc = 0x80015F94u;
    // 80015F94: lfs     f2, -19864(r9)
    if (!ppc_fp_available(ctx, 0x80015F94u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19864);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80015F98:
    ctx->pc = 0x80015F98u;
    // 80015F98: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80015F9C:
    ctx->pc = 0x80015F9Cu;
    // 80015F9C: addi    r3, r3, -27420
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27420);

label_80015FA0:
    ctx->pc = 0x80015FA0u;
    // 80015FA0: bl      0x8000E950
    {
            ctx->lr = 0x80015FA4u;
            ctx->pc = 0x8000E950u;
            return;
    }

label_80015FA4:
    ctx->pc = 0x80015FA4u;
    ctx->downcount -= 6;
    // 80015FA4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015FA8:
    ctx->pc = 0x80015FA8u;
    // 80015FA8: lfs     f1, -19868(r30)
    if (!ppc_fp_available(ctx, 0x80015FA8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-19868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80015FAC:
    ctx->pc = 0x80015FACu;
    // 80015FAC: lfs     f2, -19860(r9)
    if (!ppc_fp_available(ctx, 0x80015FACu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19860);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80015FB0:
    ctx->pc = 0x80015FB0u;
    // 80015FB0: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80015FB4:
    ctx->pc = 0x80015FB4u;
    // 80015FB4: addi    r3, r3, -27352
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27352);

label_80015FB8:
    ctx->pc = 0x80015FB8u;
    // 80015FB8: bl      0x8000E950
    {
            ctx->lr = 0x80015FBCu;
            ctx->pc = 0x8000E950u;
            return;
    }

label_80015FBC:
    ctx->pc = 0x80015FBCu;
    ctx->downcount -= 6;
    // 80015FBC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015FC0:
    ctx->pc = 0x80015FC0u;
    // 80015FC0: lfs     f1, -19868(r30)
    if (!ppc_fp_available(ctx, 0x80015FC0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-19868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80015FC4:
    ctx->pc = 0x80015FC4u;
    // 80015FC4: lfs     f2, -19856(r9)
    if (!ppc_fp_available(ctx, 0x80015FC4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19856);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80015FC8:
    ctx->pc = 0x80015FC8u;
    // 80015FC8: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80015FCC:
    ctx->pc = 0x80015FCCu;
    // 80015FCC: addi    r3, r3, -27284
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27284);

label_80015FD0:
    ctx->pc = 0x80015FD0u;
    // 80015FD0: bl      0x8000E950
    {
            ctx->lr = 0x80015FD4u;
            ctx->pc = 0x8000E950u;
            return;
    }

label_80015FD4:
    ctx->pc = 0x80015FD4u;
    ctx->downcount -= 6;
    // 80015FD4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80015FD8:
    ctx->pc = 0x80015FD8u;
    // 80015FD8: lis     r3, -32703
    ctx->gpr[3] = ((u32)(s32)(-32703) << 16);

label_80015FDC:
    ctx->pc = 0x80015FDCu;
    // 80015FDC: lfs     f1, -19868(r30)
    if (!ppc_fp_available(ctx, 0x80015FDCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-19868);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80015FE0:
    ctx->pc = 0x80015FE0u;
    // 80015FE0: addi    r3, r3, -27216
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27216);

label_80015FE4:
    ctx->pc = 0x80015FE4u;
    // 80015FE4: lfs     f2, -19852(r9)
    if (!ppc_fp_available(ctx, 0x80015FE4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19852);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_80015FE8:
    ctx->pc = 0x80015FE8u;
    // 80015FE8: bl      0x8000E950
    {
            ctx->lr = 0x80015FECu;
            ctx->pc = 0x8000E950u;
            return;
    }

label_80015FEC:
    ctx->pc = 0x80015FECu;
    ctx->downcount -= 16;
    // 80015FEC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80015FF0:
    ctx->pc = 0x80015FF0u;
    // 80015FF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80015FF4:
    ctx->pc = 0x80015FF4u;
    // 80015FF4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80015FF8:
    ctx->pc = 0x80015FF8u;
    // 80015FF8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80015FFC:
    ctx->pc = 0x80015FFCu;
    // 80015FFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016000:
    ctx->pc = 0x80016000u;
    ctx->downcount -= 1;
    // 80016000: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016004:
    ctx->pc = 0x80016004u;
    ctx->downcount -= 7;
    // 80016004: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016008:
    ctx->pc = 0x80016008u;
    // 80016008: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001600C:
    ctx->pc = 0x8001600Cu;
    // 8001600C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016010:
    ctx->pc = 0x80016010u;
    // 80016010: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80016014:
    ctx->pc = 0x80016014u;
    // 80016014: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80016018:
    ctx->pc = 0x80016018u;
    // 80016018: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_8001601C:
    ctx->pc = 0x8001601Cu;
    // 8001601C: bl      0x80016000
    {
            ctx->lr = 0x80016020u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016000u;
                return;
            }
            goto label_80016000;
    }

label_80016020:
    ctx->pc = 0x80016020u;
    ctx->downcount -= 5;
    // 80016020: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016024:
    ctx->pc = 0x80016024u;
    // 80016024: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016028:
    ctx->pc = 0x80016028u;
    // 80016028: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8001602C:
    ctx->pc = 0x8001602Cu;
    // 8001602C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016030:
    ctx->pc = 0x80016030u;
    ctx->downcount -= 25;
    // 80016030: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016034:
    ctx->pc = 0x80016034u;
    // 80016034: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016038:
    ctx->pc = 0x80016038u;
    // 80016038: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001603C:
    ctx->pc = 0x8001603Cu;
    // 8001603C: lwz     r11, -28184(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28184);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016040:
    ctx->pc = 0x80016040u;
    // 80016040: lis     r5, 17200
    ctx->gpr[5] = ((u32)(s32)(17200) << 16);

label_80016044:
    ctx->pc = 0x80016044u;
    // 80016044: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80016048:
    ctx->pc = 0x80016048u;
    // 80016048: lhz     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8001604C:
    ctx->pc = 0x8001604Cu;
    // 8001604C: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_80016050:
    ctx->pc = 0x80016050u;
    // 80016050: lhz     r6, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80016054:
    ctx->pc = 0x80016054u;
    // 80016054: lis     r7, -32738
    ctx->gpr[7] = ((u32)(s32)(-32738) << 16);

label_80016058:
    ctx->pc = 0x80016058u;
    // 80016058: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001605C:
    ctx->pc = 0x8001605Cu;
    // 8001605C: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_80016060:
    ctx->pc = 0x80016060u;
    // 80016060: lfd     f0, -19776(r8)
    if (!ppc_fp_available(ctx, 0x80016060u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-19776);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016064:
    ctx->pc = 0x80016064u;
    // 80016064: stw     r5, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80016068:
    ctx->pc = 0x80016068u;
    // 80016068: lfs     f5, -19768(r7)
    if (!ppc_fp_available(ctx, 0x80016068u)) return;
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-19768);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8001606C:
    ctx->pc = 0x8001606Cu;
    // 8001606C: lfd     f3, 8(r1)
    if (!ppc_fp_available(ctx, 0x8001606Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016070:
    ctx->pc = 0x80016070u;
    // 80016070: stw     r6, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80016074:
    ctx->pc = 0x80016074u;
    // 80016074: fsub   f3, f3, f0
    if (!ppc_fp_available(ctx, 0x80016074u)) return;
    ppc_fsub(ctx, 3, 3, 0);

label_80016078:
    ctx->pc = 0x80016078u;
    // 80016078: lfs     f6, -19764(r11)
    if (!ppc_fp_available(ctx, 0x80016078u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-19764);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8001607C:
    ctx->pc = 0x8001607Cu;
    // 8001607C: stw     r5, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80016080:
    ctx->pc = 0x80016080u;
    // 80016080: frsp    f3, f3
    if (!ppc_fp_available(ctx, 0x80016080u)) return;
    ppc_frsp(ctx, 3, 3);

label_80016084:
    ctx->pc = 0x80016084u;
    // 80016084: lfd     f4, 8(r1)
    if (!ppc_fp_available(ctx, 0x80016084u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016088:
    ctx->pc = 0x80016088u;
    // 80016088: fsub   f4, f4, f0
    if (!ppc_fp_available(ctx, 0x80016088u)) return;
    ppc_fsub(ctx, 4, 4, 0);

label_8001608C:
    ctx->pc = 0x8001608Cu;
    // 8001608C: frsp    f4, f4
    if (!ppc_fp_available(ctx, 0x8001608Cu)) return;
    ppc_frsp(ctx, 4, 4);

label_80016090:
    ctx->pc = 0x80016090u;
    // 80016090: bl      0x8019FD24
    {
            ctx->lr = 0x80016094u;
            ctx->pc = 0x8019FD24u;
            return;
    }

label_80016094:
    ctx->pc = 0x80016094u;
    ctx->downcount -= 6;
    // 80016094: lwz     r9, -28184(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28184);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016098:
    ctx->pc = 0x80016098u;
    // 80016098: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8001609C:
    ctx->pc = 0x8001609Cu;
    // 8001609C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800160A0:
    ctx->pc = 0x800160A0u;
    // 800160A0: lhz     r6, 6(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(6);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_800160A4:
    ctx->pc = 0x800160A4u;
    // 800160A4: lhz     r5, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800160A8:
    ctx->pc = 0x800160A8u;
    // 800160A8: bl      0x8019FD94
    {
            ctx->lr = 0x800160ACu;
            ctx->pc = 0x8019FD94u;
            return;
    }

label_800160AC:
    ctx->pc = 0x800160ACu;
    ctx->downcount -= 5;
    // 800160AC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800160B0:
    ctx->pc = 0x800160B0u;
    // 800160B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800160B4:
    ctx->pc = 0x800160B4u;
    // 800160B4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800160B8:
    ctx->pc = 0x800160B8u;
    // 800160B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800160BC:
    ctx->pc = 0x800160BCu;
    ctx->downcount -= 17;
    // 800160BC: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800160C0:
    ctx->pc = 0x800160C0u;
    // 800160C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800160C4:
    ctx->pc = 0x800160C4u;
    // 800160C4: stmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800160C8:
    ctx->pc = 0x800160C8u;
    // 800160C8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800160CC:
    ctx->pc = 0x800160CCu;
    // 800160CC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800160D0:
    ctx->pc = 0x800160D0u;
    // 800160D0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800160D4:
    ctx->pc = 0x800160D4u;
    // 800160D4: bl      0x800054CC
    {
            ctx->lr = 0x800160D8u;
            ctx->pc = 0x800054CCu;
            return;
    }

label_800160D8:
    ctx->pc = 0x800160D8u;
    ctx->downcount -= 3;
    // 800160D8: lwz     r3, 248(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(248);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800160DC:
    ctx->pc = 0x800160DCu;
    // 800160DC: cmpwi   r3, 0
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

label_800160E0:
    ctx->pc = 0x800160E0u;
    // 800160E0: bc    12, 2, 0x80016170
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016170;
        }
    }

label_800160E4:
    ctx->pc = 0x800160E4u;
    ctx->downcount -= 3;
    // 800160E4: lwz     r4, 252(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(252);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800160E8:
    ctx->pc = 0x800160E8u;
    // 800160E8: cmpwi   r4, -1
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800160EC:
    ctx->pc = 0x800160ECu;
    // 800160EC: bc    12, 2, 0x80016170
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016170;
        }
    }

label_800160F0:
    ctx->pc = 0x800160F0u;
    ctx->downcount -= 2;
    // 800160F0: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_800160F4:
    ctx->pc = 0x800160F4u;
    // 800160F4: bl      0x800324E8
    {
            ctx->lr = 0x800160F8u;
            ctx->pc = 0x800324E8u;
            return;
    }

label_800160F8:
    ctx->pc = 0x800160F8u;
    ctx->downcount -= 24;
    // 800160F8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800160FC:
    ctx->pc = 0x800160FCu;
    // 800160FC: lhz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80016100:
    ctx->pc = 0x80016100u;
    // 80016100: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_80016104:
    ctx->pc = 0x80016104u;
    // 80016104: lhz     r6, 10(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(10);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80016108:
    ctx->pc = 0x80016108u;
    // 80016108: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8001610C:
    ctx->pc = 0x8001610Cu;
    // 8001610C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016110:
    ctx->pc = 0x80016110u;
    // 80016110: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80016114:
    ctx->pc = 0x80016114u;
    // 80016114: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_80016118:
    ctx->pc = 0x80016118u;
    // 80016118: lfd     f0, -19760(r9)
    if (!ppc_fp_available(ctx, 0x80016118u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19760);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001611C:
    ctx->pc = 0x8001611Cu;
    // 8001611C: stw     r7, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80016120:
    ctx->pc = 0x80016120u;
    // 80016120: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80016124:
    ctx->pc = 0x80016124u;
    // 80016124: lfs     f1, -19752(r8)
    if (!ppc_fp_available(ctx, 0x80016124u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-19752);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_80016128:
    ctx->pc = 0x80016128u;
    // 80016128: lfd     f3, 16(r1)
    if (!ppc_fp_available(ctx, 0x80016128u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001612C:
    ctx->pc = 0x8001612Cu;
    // 8001612C: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80016130:
    ctx->pc = 0x80016130u;
    // 80016130: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x80016130u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_80016134:
    ctx->pc = 0x80016134u;
    // 80016134: fsub   f3, f3, f0
    if (!ppc_fp_available(ctx, 0x80016134u)) return;
    ppc_fsub(ctx, 3, 3, 0);

label_80016138:
    ctx->pc = 0x80016138u;
    // 80016138: lfs     f6, -19748(r9)
    if (!ppc_fp_available(ctx, 0x80016138u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19748);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[6] = value;
        ctx->ps1[6] = value;
    }

label_8001613C:
    ctx->pc = 0x8001613Cu;
    // 8001613C: stw     r7, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80016140:
    ctx->pc = 0x80016140u;
    // 80016140: frsp    f3, f3
    if (!ppc_fp_available(ctx, 0x80016140u)) return;
    ppc_frsp(ctx, 3, 3);

label_80016144:
    ctx->pc = 0x80016144u;
    // 80016144: fmr    f5, f2
    if (!ppc_fp_available(ctx, 0x80016144u)) return;
    ctx->fpr[5] = ctx->fpr[2];

label_80016148:
    ctx->pc = 0x80016148u;
    // 80016148: lfd     f4, 16(r1)
    if (!ppc_fp_available(ctx, 0x80016148u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[4] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001614C:
    ctx->pc = 0x8001614Cu;
    // 8001614C: fsub   f4, f4, f0
    if (!ppc_fp_available(ctx, 0x8001614Cu)) return;
    ppc_fsub(ctx, 4, 4, 0);

label_80016150:
    ctx->pc = 0x80016150u;
    // 80016150: frsp    f4, f4
    if (!ppc_fp_available(ctx, 0x80016150u)) return;
    ppc_frsp(ctx, 4, 4);

label_80016154:
    ctx->pc = 0x80016154u;
    // 80016154: bl      0x8019FD24
    {
            ctx->lr = 0x80016158u;
            ctx->pc = 0x8019FD24u;
            return;
    }

label_80016158:
    ctx->pc = 0x80016158u;
    ctx->downcount -= 5;
    // 80016158: lhz     r6, 10(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(10);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8001615C:
    ctx->pc = 0x8001615Cu;
    // 8001615C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016160:
    ctx->pc = 0x80016160u;
    // 80016160: lhz     r5, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80016164:
    ctx->pc = 0x80016164u;
    // 80016164: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80016168:
    ctx->pc = 0x80016168u;
    // 80016168: bl      0x8019FD94
    {
            ctx->lr = 0x8001616Cu;
            ctx->pc = 0x8019FD94u;
            return;
    }

label_8001616C:
    ctx->pc = 0x8001616Cu;
    ctx->downcount -= 1;
    // 8001616C: b       0x800161DC
    {
            goto label_800161DC;
    }

label_80016170:
    ctx->pc = 0x80016170u;
    ctx->downcount -= 3;
    // 80016170: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016174:
    ctx->pc = 0x80016174u;
    // 80016174: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016178:
    ctx->pc = 0x80016178u;
    // 80016178: bc    12, 2, 0x800161C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800161C8;
        }
    }

label_8001617C:
    ctx->pc = 0x8001617Cu;
    ctx->downcount -= 16;
    // 8001617C: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016180:
    ctx->pc = 0x80016180u;
    // 80016180: addi    r11, r1, 12
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(12);

label_80016184:
    ctx->pc = 0x80016184u;
    // 80016184: lbz     r8, 7(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(7);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_80016188:
    ctx->pc = 0x80016188u;
    // 80016188: lis     r4, 255
    ctx->gpr[4] = ((u32)(s32)(255) << 16);

label_8001618C:
    ctx->pc = 0x8001618Cu;
    // 8001618C: rlwinm r9, r0, 16, 16, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x0000FFFFu;
    }

label_80016190:
    ctx->pc = 0x80016190u;
    // 80016190: rlwinm r10, r0, 8, 24, 31
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x000000FFu;
    }

label_80016194:
    ctx->pc = 0x80016194u;
    // 80016194: stb     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_80016198:
    ctx->pc = 0x80016198u;
    // 80016198: rlwinm r0, r0, 24, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00FFFFFFu;
    }

label_8001619C:
    ctx->pc = 0x8001619Cu;
    // 8001619C: stb     r10, 3(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(3);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_800161A0:
    ctx->pc = 0x800161A0u;
    // 800161A0: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_800161A4:
    ctx->pc = 0x800161A4u;
    // 800161A4: stb     r0, 1(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(1);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_800161A8:
    ctx->pc = 0x800161A8u;
    // 800161A8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800161AC:
    ctx->pc = 0x800161ACu;
    // 800161AC: stb     r8, 2(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(2);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_800161B0:
    ctx->pc = 0x800161B0u;
    // 800161B0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800161B4:
    ctx->pc = 0x800161B4u;
    // 800161B4: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800161B8:
    ctx->pc = 0x800161B8u;
    // 800161B8: bl      0x8019A9BC
    {
            ctx->lr = 0x800161BCu;
            ctx->pc = 0x8019A9BCu;
            return;
    }

label_800161BC:
    ctx->pc = 0x800161BCu;
    ctx->downcount -= 1;
    // 800161BC: bl      0x8000A704
    {
            ctx->lr = 0x800161C0u;
            ctx->pc = 0x8000A704u;
            return;
    }

label_800161C0:
    ctx->pc = 0x800161C0u;
    ctx->downcount -= 2;
    // 800161C0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800161C4:
    ctx->pc = 0x800161C4u;
    // 800161C4: bl      0x8019AC68
    {
            ctx->lr = 0x800161C8u;
            ctx->pc = 0x8019AC68u;
            return;
    }

label_800161C8:
    ctx->pc = 0x800161C8u;
    ctx->downcount -= 5;
    // 800161C8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800161CC:
    ctx->pc = 0x800161CCu;
    // 800161CC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800161D0:
    ctx->pc = 0x800161D0u;
    // 800161D0: lfs     f1, -19752(r9)
    if (!ppc_fp_available(ctx, 0x800161D0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19752);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800161D4:
    ctx->pc = 0x800161D4u;
    // 800161D4: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x800161D4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_800161D8:
    ctx->pc = 0x800161D8u;
    // 800161D8: bl      0x80016030
    {
            ctx->lr = 0x800161DCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016030u;
                return;
            }
            goto label_80016030;
    }

label_800161DC:
    ctx->pc = 0x800161DCu;
    ctx->downcount -= 16;
    // 800161DC: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800161E0:
    ctx->pc = 0x800161E0u;
    // 800161E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800161E4:
    ctx->pc = 0x800161E4u;
    // 800161E4: lmw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800161E8:
    ctx->pc = 0x800161E8u;
    // 800161E8: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_800161EC:
    ctx->pc = 0x800161ECu;
    // 800161EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800161F0:
    ctx->pc = 0x800161F0u;
    ctx->downcount -= 6;
    // 800161F0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800161F4:
    ctx->pc = 0x800161F4u;
    // 800161F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800161F8:
    ctx->pc = 0x800161F8u;
    // 800161F8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800161FC:
    ctx->pc = 0x800161FCu;
    // 800161FC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016200:
    ctx->pc = 0x80016200u;
    // 80016200: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016204:
    ctx->pc = 0x80016204u;
    // 80016204: bl      0x80005CF0
    {
            ctx->lr = 0x80016208u;
            ctx->pc = 0x80005CF0u;
            return;
    }

label_80016208:
    ctx->pc = 0x80016208u;
    ctx->downcount -= 3;
    // 80016208: lwz     r3, 248(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(248);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001620C:
    ctx->pc = 0x8001620Cu;
    // 8001620C: cmpwi   r3, 0
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

label_80016210:
    ctx->pc = 0x80016210u;
    // 80016210: bc    12, 2, 0x8001627C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001627C;
        }
    }

label_80016214:
    ctx->pc = 0x80016214u;
    ctx->downcount -= 3;
    // 80016214: lwz     r4, 252(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(252);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80016218:
    ctx->pc = 0x80016218u;
    // 80016218: cmpwi   r4, -1
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001621C:
    ctx->pc = 0x8001621Cu;
    // 8001621C: bc    12, 2, 0x8001627C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001627C;
        }
    }

label_80016220:
    ctx->pc = 0x80016220u;
    ctx->downcount -= 2;
    // 80016220: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_80016224:
    ctx->pc = 0x80016224u;
    // 80016224: bl      0x800324E8
    {
            ctx->lr = 0x80016228u;
            ctx->pc = 0x800324E8u;
            return;
    }

label_80016228:
    ctx->pc = 0x80016228u;
    ctx->downcount -= 6;
    // 80016228: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8001622C:
    ctx->pc = 0x8001622Cu;
    // 8001622C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80016230:
    ctx->pc = 0x80016230u;
    // 80016230: lhz     r5, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_80016234:
    ctx->pc = 0x80016234u;
    // 80016234: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016238:
    ctx->pc = 0x80016238u;
    // 80016238: lhz     r6, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8001623C:
    ctx->pc = 0x8001623Cu;
    // 8001623C: bl      0x8019A2AC
    {
            ctx->lr = 0x80016240u;
            ctx->pc = 0x8019A2ACu;
            return;
    }

label_80016240:
    ctx->pc = 0x80016240u;
    ctx->downcount -= 5;
    // 80016240: lhz     r3, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80016244:
    ctx->pc = 0x80016244u;
    // 80016244: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_80016248:
    ctx->pc = 0x80016248u;
    // 80016248: lhz     r4, 10(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(10);
        ctx->gpr[4] = mem_read16(ctx, ea);
    }

label_8001624C:
    ctx->pc = 0x8001624Cu;
    // 8001624C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80016250:
    ctx->pc = 0x80016250u;
    // 80016250: bl      0x8019A3B0
    {
            ctx->lr = 0x80016254u;
            ctx->pc = 0x8019A3B0u;
            return;
    }

label_80016254:
    ctx->pc = 0x80016254u;
    ctx->downcount -= 3;
    // 80016254: lwz     r9, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016258:
    ctx->pc = 0x80016258u;
    // 80016258: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001625C:
    ctx->pc = 0x8001625Cu;
    // 8001625C: bc    12, 2, 0x8001626C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001626C;
        }
    }

label_80016260:
    ctx->pc = 0x80016260u;
    ctx->downcount -= 3;
    // 80016260: addi    r0, r9, 88
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(88);

label_80016264:
    ctx->pc = 0x80016264u;
    // 80016264: add   r3, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80016268:
    ctx->pc = 0x80016268u;
    // 80016268: b       0x80016270
    {
            goto label_80016270;
    }

label_8001626C:
    ctx->pc = 0x8001626Cu;
    ctx->downcount -= 1;
    // 8001626C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016270:
    ctx->pc = 0x80016270u;
    ctx->downcount -= 2;
    // 80016270: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_80016274:
    ctx->pc = 0x80016274u;
    // 80016274: bl      0x8019ADD8
    {
            ctx->lr = 0x80016278u;
            ctx->pc = 0x8019ADD8u;
            return;
    }

label_80016278:
    ctx->pc = 0x80016278u;
    ctx->downcount -= 1;
    // 80016278: bl      0x80199610
    {
            ctx->lr = 0x8001627Cu;
            ctx->pc = 0x80199610u;
            return;
    }

label_8001627C:
    ctx->pc = 0x8001627Cu;
    ctx->downcount -= 6;
    // 8001627C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016280:
    ctx->pc = 0x80016280u;
    // 80016280: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016284:
    ctx->pc = 0x80016284u;
    // 80016284: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016288:
    ctx->pc = 0x80016288u;
    // 80016288: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8001628C:
    ctx->pc = 0x8001628Cu;
    // 8001628C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016290:
    ctx->pc = 0x80016290u;
    ctx->downcount -= 4;
    // 80016290: addi    r0, r3, 96
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(96);

label_80016294:
    ctx->pc = 0x80016294u;
    // 80016294: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016298:
    ctx->pc = 0x80016298u;
    // 80016298: cmplw   r3, r0
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001629C:
    ctx->pc = 0x8001629Cu;
    // 8001629C: bc    4, 0, 0x800162B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800162B8;
        }
    }

label_800162A0:
    ctx->pc = 0x800162A0u;
    ctx->downcount -= 4;
    // 800162A0: li      r11, 96
    ctx->gpr[11] = (u32)(s32)(96);

label_800162A4:
    ctx->pc = 0x800162A4u;
    // 800162A4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800162A8:
    ctx->pc = 0x800162A8u;
    // 800162A8: mtctr    r11
    ctx->ctr = ctx->gpr[11];

label_800162AC:
    loop_800162AC(ctx);
    if (ctx->pc == 0x800162B8u) goto label_800162B8;
    return;
label_800162B0:
    // 800162B0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_800162B4:
    // 800162B4: bc    16, 0, 0x800162AC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800162ACu;
                return;
            }
            goto label_800162AC;
        }
    }

label_800162B8:
    ctx->pc = 0x800162B8u;
    ctx->downcount -= 9;
    // 800162B8: li      r9, -1
    ctx->gpr[9] = (u32)(s32)(-1);

label_800162BC:
    ctx->pc = 0x800162BCu;
    // 800162BC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800162C0:
    ctx->pc = 0x800162C0u;
    // 800162C0: stw     r0, 80(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800162C4:
    ctx->pc = 0x800162C4u;
    // 800162C4: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800162C8:
    ctx->pc = 0x800162C8u;
    // 800162C8: stw     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800162CC:
    ctx->pc = 0x800162CCu;
    // 800162CC: stw     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800162D0:
    ctx->pc = 0x800162D0u;
    // 800162D0: stw     r9, 88(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800162D4:
    ctx->pc = 0x800162D4u;
    // 800162D4: stw     r9, 72(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800162D8:
    ctx->pc = 0x800162D8u;
    // 800162D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800162DC:
    ctx->pc = 0x800162DCu;
    ctx->downcount -= 7;
    // 800162DC: li      r0, 24
    ctx->gpr[0] = (u32)(s32)(24);

label_800162E0:
    ctx->pc = 0x800162E0u;
    // 800162E0: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_800162E4:
    ctx->pc = 0x800162E4u;
    // 800162E4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_800162E8:
    ctx->pc = 0x800162E8u;
    // 800162E8: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_800162EC:
    ctx->pc = 0x800162ECu;
    // 800162EC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800162F0:
    ctx->pc = 0x800162F0u;
    // 800162F0: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800162F4:
    ctx->pc = 0x800162F4u;
    ctx->downcount -= 3;
    // 800162F4: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800162F8:
    // 800162F8: cmpw    r0, r3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[3]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800162FC:
    // 800162FC: bc    4, 2, 0x80016304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016304;
        }
    }

label_80016300:
    ctx->pc = 0x80016300u;
    ctx->downcount -= 1;
    // 80016300: stwx    r10, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80016304:
    ctx->downcount -= 2;
    // 80016304: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_80016308:
    // 80016308: bc    16, 0, 0x800162F4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800162F4u;
                return;
            }
            goto label_800162F4;
        }
    }

label_8001630C:
    ctx->pc = 0x8001630Cu;
    ctx->downcount -= 1;
    // 8001630C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016310:
    ctx->pc = 0x80016310u;
    ctx->downcount -= 6;
    // 80016310: li      r0, 24
    ctx->gpr[0] = (u32)(s32)(24);

label_80016314:
    ctx->pc = 0x80016314u;
    // 80016314: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016318:
    ctx->pc = 0x80016318u;
    // 80016318: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8001631C:
    ctx->pc = 0x8001631Cu;
    // 8001631C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016320:
    ctx->pc = 0x80016320u;
    // 80016320: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016324:
    ctx->pc = 0x80016324u;
    ctx->downcount -= 4;
    // 80016324: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016328:
    // 80016328: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8001632C:
    // 8001632C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016330:
    ctx->pc = 0x80016330u;
    // 80016330: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016334:
    ctx->downcount -= 2;
    // 80016334: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_80016338:
    // 80016338: bc    16, 0, 0x80016324
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016324u;
                return;
            }
            goto label_80016324;
        }
    }

label_8001633C:
    ctx->pc = 0x8001633Cu;
    ctx->downcount -= 2;
    // 8001633C: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_80016340:
    ctx->pc = 0x80016340u;
    // 80016340: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016344:
    ctx->pc = 0x80016344u;
    ctx->downcount -= 23;
    // 80016344: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016348:
    ctx->pc = 0x80016348u;
    // 80016348: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001634C:
    ctx->pc = 0x8001634Cu;
    // 8001634C: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80016350:
    ctx->pc = 0x80016350u;
    // 80016350: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016354:
    ctx->pc = 0x80016354u;
    // 80016354: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016358:
    ctx->pc = 0x80016358u;
    // 80016358: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_8001635C:
    ctx->pc = 0x8001635Cu;
    // 8001635C: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016360:
    ctx->pc = 0x80016360u;
    // 80016360: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016364:
    ctx->pc = 0x80016364u;
    // 80016364: lwzx    r31, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016368:
    ctx->pc = 0x80016368u;
    // 80016368: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8001636C:
    ctx->pc = 0x8001636Cu;
    // 8001636C: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80016370:
    ctx->pc = 0x80016370u;
    // 80016370: or.   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[27];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80016374:
    ctx->pc = 0x80016374u;
    // 80016374: bc    4, 2, 0x800163D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800163D0;
        }
    }

label_80016378:
    ctx->pc = 0x80016378u;
    ctx->downcount -= 1;
    // 80016378: bl      0x801B52DC
    {
            ctx->lr = 0x8001637Cu;
            ctx->pc = 0x801B52DCu;
            return;
    }

label_8001637C:
    ctx->pc = 0x8001637Cu;
    ctx->downcount -= 4;
    // 8001637C: lbz     r0, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80016380:
    ctx->pc = 0x80016380u;
    // 80016380: stw     r29, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80016384:
    ctx->pc = 0x80016384u;
    // 80016384: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016388:
    ctx->pc = 0x80016388u;
    // 80016388: bc    12, 2, 0x800163B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800163B8;
        }
    }

label_8001638C:
    ctx->pc = 0x8001638Cu;
    ctx->downcount -= 14;
    // 8001638C: lis     r4, 26214
    ctx->gpr[4] = ((u32)(s32)(26214) << 16);

label_80016390:
    ctx->pc = 0x80016390u;
    // 80016390: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016394:
    ctx->pc = 0x80016394u;
    // 80016394: ori     r4, r4, 0x6667
    ctx->gpr[4] = ctx->gpr[4] | 0x6667u;

label_80016398:
    ctx->pc = 0x80016398u;
    // 80016398: srawi r0, r30, 31
    {
        u32 sh = 31u;
        u32 value = ctx->gpr[30];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[0] = value;
        } else if (sh > 31) {
            ctx->gpr[0] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[0] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8001639C:
    ctx->pc = 0x8001639Cu;
    // 8001639C: mulhw   r4, r30, r4
    {
        s64 product = (s64)(s32)ctx->gpr[30] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[4] = (u32)(product >> 32);
    }

label_800163A0:
    ctx->pc = 0x800163A0u;
    // 800163A0: lwz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800163A4:
    ctx->pc = 0x800163A4u;
    // 800163A4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800163A8:
    ctx->pc = 0x800163A8u;
    // 800163A8: srawi r4, r4, 2
    {
        u32 sh = 2u;
        u32 value = ctx->gpr[4];
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

label_800163AC:
    ctx->pc = 0x800163ACu;
    // 800163AC: subf   r4, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b + 1u;
        ctx->gpr[4] = res;
    }

label_800163B0:
    ctx->pc = 0x800163B0u;
    // 800163B0: bl      0x801AF954
    {
            ctx->lr = 0x800163B4u;
            ctx->pc = 0x801AF954u;
            return;
    }

label_800163B4:
    ctx->pc = 0x800163B4u;
    ctx->downcount -= 1;
    // 800163B4: b       0x800163C8
    {
            goto label_800163C8;
    }

label_800163B8:
    ctx->pc = 0x800163B8u;
    ctx->downcount -= 4;
    // 800163B8: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800163BC:
    ctx->pc = 0x800163BCu;
    // 800163BC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800163C0:
    ctx->pc = 0x800163C0u;
    // 800163C0: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800163C4:
    ctx->pc = 0x800163C4u;
    // 800163C4: bl      0x801B6188
    {
            ctx->lr = 0x800163C8u;
            ctx->pc = 0x801B6188u;
            return;
    }

label_800163C8:
    ctx->pc = 0x800163C8u;
    ctx->downcount -= 2;
    // 800163C8: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800163CC:
    ctx->pc = 0x800163CCu;
    // 800163CC: bl      0x801B5310
    {
            ctx->lr = 0x800163D0u;
            ctx->pc = 0x801B5310u;
            return;
    }

label_800163D0:
    ctx->pc = 0x800163D0u;
    ctx->downcount -= 8;
    // 800163D0: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_800163D4:
    ctx->pc = 0x800163D4u;
    // 800163D4: addi    r4, r31, 15
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(15);

label_800163D8:
    ctx->pc = 0x800163D8u;
    // 800163D8: addi    r3, r3, -19676
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19676);

label_800163DC:
    ctx->pc = 0x800163DCu;
    // 800163DC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800163E0:
    ctx->pc = 0x800163E0u;
    // 800163E0: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800163E4:
    ctx->pc = 0x800163E4u;
    // 800163E4: or   r7, r27, r27
    {
        ctx->gpr[7] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800163E8:
    ctx->pc = 0x800163E8u;
    // 800163E8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800163EC:
    ctx->pc = 0x800163ECu;
    // 800163EC: bl      0x801C0CF0
    {
            ctx->lr = 0x800163F0u;
            ctx->pc = 0x801C0CF0u;
            return;
    }

label_800163F0:
    ctx->pc = 0x800163F0u;
    ctx->downcount -= 17;
    // 800163F0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800163F4:
    ctx->pc = 0x800163F4u;
    // 800163F4: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800163F8:
    ctx->pc = 0x800163F8u;
    // 800163F8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800163FC:
    ctx->pc = 0x800163FCu;
    // 800163FC: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80016400:
    ctx->pc = 0x80016400u;
    // 80016400: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80016404:
    ctx->pc = 0x80016404u;
    // 80016404: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016408:
    ctx->pc = 0x80016408u;
    ctx->downcount -= 23;
    // 80016408: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8001640C:
    ctx->pc = 0x8001640Cu;
    // 8001640C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016410:
    ctx->pc = 0x80016410u;
    // 80016410: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80016414:
    ctx->pc = 0x80016414u;
    // 80016414: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016418:
    ctx->pc = 0x80016418u;
    // 80016418: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_8001641C:
    ctx->pc = 0x8001641Cu;
    // 8001641C: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80016420:
    ctx->pc = 0x80016420u;
    // 80016420: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016424:
    ctx->pc = 0x80016424u;
    // 80016424: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80016428:
    ctx->pc = 0x80016428u;
    // 80016428: lwzx    r30, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8001642C:
    ctx->pc = 0x8001642Cu;
    // 8001642C: or.   r5, r5, r5
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[5];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80016430:
    ctx->pc = 0x80016430u;
    // 80016430: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016434:
    ctx->pc = 0x80016434u;
    // 80016434: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016438:
    ctx->pc = 0x80016438u;
    // 80016438: bc    12, 2, 0x80016444
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016444;
        }
    }

label_8001643C:
    ctx->pc = 0x8001643Cu;
    ctx->downcount -= 2;
    // 8001643C: stw     r5, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80016440:
    ctx->pc = 0x80016440u;
    // 80016440: b       0x8001644C
    {
            goto label_8001644C;
    }

label_80016444:
    ctx->pc = 0x80016444u;
    ctx->downcount -= 1;
    // 80016444: bl      0x800164C0
    {
            ctx->lr = 0x80016448u;
            goto label_800164C0;
    }

label_80016448:
    ctx->pc = 0x80016448u;
    ctx->downcount -= 1;
    // 80016448: stw     r3, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8001644C:
    ctx->pc = 0x8001644Cu;
    ctx->downcount -= 4;
    // 8001644C: lwz     r4, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80016450:
    ctx->pc = 0x80016450u;
    // 80016450: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016454:
    ctx->pc = 0x80016454u;
    // 80016454: li      r3, -39
    ctx->gpr[3] = (u32)(s32)(-39);

label_80016458:
    ctx->pc = 0x80016458u;
    // 80016458: bc    12, 2, 0x800164AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800164AC;
        }
    }

label_8001645C:
    ctx->pc = 0x8001645Cu;
    ctx->downcount -= 2;
    // 8001645C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80016460:
    ctx->pc = 0x80016460u;
    // 80016460: bl      0x801AFAB4
    {
            ctx->lr = 0x80016464u;
            ctx->pc = 0x801AFAB4u;
            return;
    }

label_80016464:
    ctx->pc = 0x80016464u;
    ctx->downcount -= 2;
    // 80016464: cmpwi   r3, 7
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016468:
    ctx->pc = 0x80016468u;
    // 80016468: bc    4, 2, 0x800164A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800164A8;
        }
    }

label_8001646C:
    ctx->pc = 0x8001646Cu;
    ctx->downcount -= 2;
    // 8001646C: lwz     r3, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016470:
    ctx->pc = 0x80016470u;
    // 80016470: bl      0x801B0A78
    {
            ctx->lr = 0x80016474u;
            ctx->pc = 0x801B0A78u;
            return;
    }

label_80016474:
    ctx->pc = 0x80016474u;
    ctx->downcount -= 5;
    // 80016474: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016478:
    ctx->pc = 0x80016478u;
    // 80016478: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8001647C:
    ctx->pc = 0x8001647Cu;
    // 8001647C: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80016480:
    ctx->pc = 0x80016480u;
    // 80016480: addi    r3, r3, -19624
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19624);

label_80016484:
    ctx->pc = 0x80016484u;
    // 80016484: bl      0x8003A948
    {
            ctx->lr = 0x80016488u;
            ctx->pc = 0x8003A948u;
            return;
    }

label_80016488:
    ctx->pc = 0x80016488u;
    ctx->downcount -= 2;
    // 80016488: or.   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8001648C:
    ctx->pc = 0x8001648Cu;
    // 8001648C: bc    12, 2, 0x800164A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800164A8;
        }
    }

label_80016490:
    ctx->pc = 0x80016490u;
    ctx->downcount -= 3;
    // 80016490: lwz     r4, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80016494:
    ctx->pc = 0x80016494u;
    // 80016494: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80016498:
    ctx->pc = 0x80016498u;
    // 80016498: bl      0x801B0A04
    {
            ctx->lr = 0x8001649Cu;
            ctx->pc = 0x801B0A04u;
            return;
    }

label_8001649C:
    ctx->pc = 0x8001649Cu;
    ctx->downcount -= 2;
    // 8001649C: lwz     r3, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800164A0:
    ctx->pc = 0x800164A0u;
    // 800164A0: bl      0x8003A990
    {
            ctx->lr = 0x800164A4u;
            ctx->pc = 0x8003A990u;
            return;
    }

label_800164A4:
    ctx->pc = 0x800164A4u;
    ctx->downcount -= 1;
    // 800164A4: stw     r31, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800164A8:
    ctx->pc = 0x800164A8u;
    ctx->downcount -= 1;
    // 800164A8: lwz     r3, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800164AC:
    ctx->pc = 0x800164ACu;
    ctx->downcount -= 16;
    // 800164AC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800164B0:
    ctx->pc = 0x800164B0u;
    // 800164B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800164B4:
    ctx->pc = 0x800164B4u;
    // 800164B4: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800164B8:
    ctx->pc = 0x800164B8u;
    // 800164B8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800164BC:
    ctx->pc = 0x800164BCu;
    // 800164BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800164C0:
    ctx->pc = 0x800164C0u;
    ctx->downcount -= 16;
    // 800164C0: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800164C4:
    ctx->pc = 0x800164C4u;
    // 800164C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800164C8:
    ctx->pc = 0x800164C8u;
    // 800164C8: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800164CC:
    ctx->pc = 0x800164CCu;
    // 800164CC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800164D0:
    ctx->pc = 0x800164D0u;
    // 800164D0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800164D4:
    ctx->pc = 0x800164D4u;
    // 800164D4: bl      0x800334E0
    {
            ctx->lr = 0x800164D8u;
            ctx->pc = 0x800334E0u;
            return;
    }

label_800164D8:
    ctx->pc = 0x800164D8u;
    ctx->downcount -= 2;
    // 800164D8: or.   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800164DC:
    ctx->pc = 0x800164DCu;
    // 800164DC: bc    12, 2, 0x80016508
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016508;
        }
    }

label_800164E0:
    ctx->pc = 0x800164E0u;
    ctx->downcount -= 4;
    // 800164E0: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_800164E4:
    ctx->pc = 0x800164E4u;
    // 800164E4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800164E8:
    ctx->pc = 0x800164E8u;
    // 800164E8: addi    r3, r3, -19612
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19612);

label_800164EC:
    ctx->pc = 0x800164ECu;
    // 800164EC: bl      0x8003A948
    {
            ctx->lr = 0x800164F0u;
            ctx->pc = 0x8003A948u;
            return;
    }

label_800164F0:
    ctx->pc = 0x800164F0u;
    ctx->downcount -= 4;
    // 800164F0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800164F4:
    ctx->pc = 0x800164F4u;
    // 800164F4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800164F8:
    ctx->pc = 0x800164F8u;
    // 800164F8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800164FC:
    ctx->pc = 0x800164FCu;
    // 800164FC: bl      0x80033924
    {
            ctx->lr = 0x80016500u;
            ctx->pc = 0x80033924u;
            return;
    }

label_80016500:
    ctx->pc = 0x80016500u;
    ctx->downcount -= 2;
    // 80016500: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80016504:
    ctx->pc = 0x80016504u;
    // 80016504: b       0x8001650C
    {
            goto label_8001650C;
    }

label_80016508:
    ctx->pc = 0x80016508u;
    ctx->downcount -= 1;
    // 80016508: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8001650C:
    ctx->pc = 0x8001650Cu;
    ctx->downcount -= 16;
    // 8001650C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016510:
    ctx->pc = 0x80016510u;
    // 80016510: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016514:
    ctx->pc = 0x80016514u;
    // 80016514: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80016518:
    ctx->pc = 0x80016518u;
    // 80016518: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8001651C:
    ctx->pc = 0x8001651Cu;
    // 8001651C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016520:
    ctx->pc = 0x80016520u;
    ctx->downcount -= 6;
    // 80016520: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016524:
    ctx->pc = 0x80016524u;
    // 80016524: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016528:
    ctx->pc = 0x80016528u;
    // 80016528: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001652C:
    ctx->pc = 0x8001652Cu;
    // 8001652C: lwz     r0, -32500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32500);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016530:
    ctx->pc = 0x80016530u;
    // 80016530: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016534:
    ctx->pc = 0x80016534u;
    // 80016534: bc    12, 2, 0x80016540
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016540;
        }
    }

label_80016538:
    ctx->pc = 0x80016538u;
    ctx->downcount -= 3;
    // 80016538: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8001653C:
    ctx->pc = 0x8001653Cu;
    // 8001653C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80016540u;
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016540:
    ctx->pc = 0x80016540u;
    ctx->downcount -= 6;
    // 80016540: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016544:
    ctx->pc = 0x80016544u;
    // 80016544: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016548:
    ctx->pc = 0x80016548u;
    // 80016548: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8001654C:
    ctx->pc = 0x8001654Cu;
    // 8001654C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80016550:
    ctx->pc = 0x80016550u;
    // 80016550: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016554:
    ctx->pc = 0x80016554u;
    ctx->downcount -= 4;
    // 80016554: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016558:
    ctx->pc = 0x80016558u;
    // 80016558: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001655C:
    ctx->pc = 0x8001655Cu;
    // 8001655C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016560:
    ctx->pc = 0x80016560u;
    // 80016560: bl      0x801A8ED0
    {
            ctx->lr = 0x80016564u;
            ctx->pc = 0x801A8ED0u;
            return;
    }

label_80016564:
    ctx->pc = 0x80016564u;
    ctx->downcount -= 47;
    // 80016564: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_80016568:
    ctx->pc = 0x80016568u;
    // 80016568: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8001656C:
    ctx->pc = 0x8001656Cu;
    // 8001656C: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_80016570:
    ctx->pc = 0x80016570u;
    // 80016570: lwz     r0, -25976(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25976);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016574:
    ctx->pc = 0x80016574u;
    // 80016574: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80016578:
    ctx->pc = 0x80016578u;
    // 80016578: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8001657C:
    ctx->pc = 0x8001657Cu;
    // 8001657C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80016580:
    ctx->pc = 0x80016580u;
    // 80016580: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_80016584:
    ctx->pc = 0x80016584u;
    // 80016584: lfd     f12, -19600(r9)
    if (!ppc_fp_available(ctx, 0x80016584u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19600);
        ctx->fpr[12] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016588:
    ctx->pc = 0x80016588u;
    // 80016588: lfd     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x80016588u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8001658C:
    ctx->pc = 0x8001658Cu;
    // 8001658C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80016590:
    ctx->pc = 0x80016590u;
    // 80016590: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016594:
    ctx->pc = 0x80016594u;
    // 80016594: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80016598:
    ctx->pc = 0x80016598u;
    // 80016598: fsub   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x80016598u)) return;
    ppc_fsub(ctx, 13, 13, 12);

label_8001659C:
    ctx->pc = 0x8001659Cu;
    // 8001659C: lfs     f10, -19592(r9)
    if (!ppc_fp_available(ctx, 0x8001659Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19592);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800165A0:
    ctx->pc = 0x800165A0u;
    // 800165A0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800165A4:
    ctx->pc = 0x800165A4u;
    // 800165A4: frsp    f13, f13
    if (!ppc_fp_available(ctx, 0x800165A4u)) return;
    ppc_frsp(ctx, 13, 13);

label_800165A8:
    ctx->pc = 0x800165A8u;
    // 800165A8: lfd     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800165A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800165AC:
    ctx->pc = 0x800165ACu;
    // 800165AC: fsub   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x800165ACu)) return;
    ppc_fsub(ctx, 0, 0, 12);

label_800165B0:
    ctx->pc = 0x800165B0u;
    // 800165B0: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x800165B0u)) return;
    ppc_frsp(ctx, 0, 0);

label_800165B4:
    ctx->pc = 0x800165B4u;
    // 800165B4: fdivs   f13, f13, f0
    if (!ppc_fp_available(ctx, 0x800165B4u)) return;
    ppc_fdivs(ctx, 13, 13, 0);

label_800165B8:
    ctx->pc = 0x800165B8u;
    // 800165B8: fmuls   f13, f13, f10
    if (!ppc_fp_available(ctx, 0x800165B8u)) return;
    ppc_fmuls(ctx, 13, 13, 10);

label_800165BC:
    ctx->pc = 0x800165BCu;
    // 800165BC: fmr    f0, f13
    if (!ppc_fp_available(ctx, 0x800165BCu)) return;
    ctx->fpr[0] = ctx->fpr[13];

label_800165C0:
    ctx->pc = 0x800165C0u;
    // 800165C0: fctiwz    f11, f0
    if (!ppc_fp_available(ctx, 0x800165C0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[11] = dolrecomp_f64_from_bits(result); }

label_800165C4:
    ctx->pc = 0x800165C4u;
    // 800165C4: stfd     f11, 8(r1)
    if (!ppc_fp_available(ctx, 0x800165C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[11]));
    }

label_800165C8:
    ctx->pc = 0x800165C8u;
    // 800165C8: lwz     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800165CC:
    ctx->pc = 0x800165CCu;
    // 800165CC: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800165D0:
    ctx->pc = 0x800165D0u;
    // 800165D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800165D4:
    ctx->pc = 0x800165D4u;
    // 800165D4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800165D8:
    ctx->pc = 0x800165D8u;
    // 800165D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800165DC:
    ctx->pc = 0x800165DCu;
    ctx->downcount -= 10;
    // 800165DC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800165E0:
    ctx->pc = 0x800165E0u;
    // 800165E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800165E4:
    ctx->pc = 0x800165E4u;
    // 800165E4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800165E8:
    ctx->pc = 0x800165E8u;
    // 800165E8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800165EC:
    ctx->pc = 0x800165ECu;
    // 800165EC: mulli   r9, r3, 12
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)12);

label_800165F0:
    ctx->pc = 0x800165F0u;
    // 800165F0: or.   r4, r4, r4
    {
        ctx->gpr[4] = ctx->gpr[4] | ctx->gpr[4];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800165F4:
    ctx->pc = 0x800165F4u;
    // 800165F4: addi    r31, r9, 96
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(96);

label_800165F8:
    ctx->pc = 0x800165F8u;
    // 800165F8: bc    4, 1, 0x80016604
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016604;
        }
    }

label_800165FC:
    ctx->pc = 0x800165FCu;
    ctx->downcount -= 1;
    // 800165FC: bl      0x801B6410
    {
            ctx->lr = 0x80016600u;
            ctx->pc = 0x801B6410u;
            return;
    }

label_80016600:
    ctx->pc = 0x80016600u;
    ctx->downcount -= 1;
    // 80016600: add   r31, r31, r3
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_80016604:
    ctx->pc = 0x80016604u;
    ctx->downcount -= 4;
    // 80016604: addi    r0, r31, 16
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(16);

label_80016608:
    ctx->pc = 0x80016608u;
    // 80016608: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8001660C:
    ctx->pc = 0x8001660Cu;
    // 8001660C: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016610:
    ctx->pc = 0x80016610u;
    // 80016610: bc    4, 0, 0x80016618
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016618;
        }
    }

label_80016614:
    ctx->pc = 0x80016614u;
    ctx->downcount -= 1;
    // 80016614: addi    r3, r31, 15
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(15);

label_80016618:
    ctx->pc = 0x80016618u;
    ctx->downcount -= 9;
    // 80016618: rlwinm r3, r3, 0, 0, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF0u;
    }

label_8001661C:
    ctx->pc = 0x8001661Cu;
    // 8001661C: subf   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80016620:
    ctx->pc = 0x80016620u;
    // 80016620: subf   r3, r3, r0
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[3] = res;
    }

label_80016624:
    ctx->pc = 0x80016624u;
    // 80016624: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016628:
    ctx->pc = 0x80016628u;
    // 80016628: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8001662C:
    ctx->pc = 0x8001662Cu;
    // 8001662C: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016630:
    ctx->pc = 0x80016630u;
    // 80016630: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80016634:
    ctx->pc = 0x80016634u;
    // 80016634: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016638:
    ctx->pc = 0x80016638u;
    ctx->downcount -= 25;
    // 80016638: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8001663C:
    ctx->pc = 0x8001663Cu;
    // 8001663C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016640:
    ctx->pc = 0x80016640u;
    // 80016640: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_80016644:
    ctx->pc = 0x80016644u;
    // 80016644: stmw     r20, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 20; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80016648:
    ctx->pc = 0x80016648u;
    // 80016648: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001664C:
    ctx->pc = 0x8001664Cu;
    // 8001664C: stw     r12, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_80016650:
    ctx->pc = 0x80016650u;
    // 80016650: or   r20, r3, r3
    {
        ctx->gpr[20] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016654:
    ctx->pc = 0x80016654u;
    // 80016654: or   r22, r4, r4
    {
        ctx->gpr[22] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016658:
    ctx->pc = 0x80016658u;
    // 80016658: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8001665C:
    ctx->pc = 0x8001665Cu;
    // 8001665C: or   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80016660:
    ctx->pc = 0x80016660u;
    // 80016660: or   r23, r7, r7
    {
        ctx->gpr[23] = ctx->gpr[7] | ctx->gpr[7];
    }

label_80016664:
    ctx->pc = 0x80016664u;
    // 80016664: or   r31, r8, r8
    {
        ctx->gpr[31] = ctx->gpr[8] | ctx->gpr[8];
    }

label_80016668:
    ctx->pc = 0x80016668u;
    // 80016668: or   r26, r9, r9
    {
        ctx->gpr[26] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8001666C:
    ctx->pc = 0x8001666Cu;
    // 8001666C: or   r21, r10, r10
    {
        ctx->gpr[21] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80016670:
    ctx->pc = 0x80016670u;
    // 80016670: bl      0x80016310
    {
            ctx->lr = 0x80016674u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016310u;
                return;
            }
            goto label_80016310;
    }

label_80016674:
    ctx->pc = 0x80016674u;
    ctx->downcount -= 2;
    // 80016674: or.   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[25];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80016678:
    ctx->pc = 0x80016678u;
    // 80016678: bc    4, 0, 0x80016684
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016684;
        }
    }

label_8001667C:
    ctx->pc = 0x8001667Cu;
    ctx->downcount -= 2;
    // 8001667C: li      r3, -13
    ctx->gpr[3] = (u32)(s32)(-13);

label_80016680:
    ctx->pc = 0x80016680u;
    // 80016680: b       0x800167BC
    {
            goto label_800167BC;
    }

label_80016684:
    ctx->pc = 0x80016684u;
    ctx->downcount -= 7;
    // 80016684: lis     r30, -32703
    ctx->gpr[30] = ((u32)(s32)(-32703) << 16);

label_80016688:
    ctx->pc = 0x80016688u;
    // 80016688: rlwinm r29, r25, 2, 0, 29
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[25], 2u) & 0xFFFFFFFCu;
    }

label_8001668C:
    ctx->pc = 0x8001668Cu;
    // 8001668C: addi    r30, r30, -27132
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-27132);

label_80016690:
    ctx->pc = 0x80016690u;
    // 80016690: stwx    r31, r30, r29
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[29];
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80016694:
    ctx->pc = 0x80016694u;
    // 80016694: addi    r31, r31, 96
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(96);

label_80016698:
    ctx->pc = 0x80016698u;
    // 80016698: lwzx    r3, r30, r29
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[29];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001669C:
    ctx->pc = 0x8001669Cu;
    // 8001669C: bl      0x80016290
    {
            ctx->lr = 0x800166A0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016290u;
                return;
            }
            goto label_80016290;
    }

label_800166A0:
    ctx->pc = 0x800166A0u;
    ctx->downcount -= 11;
    // 800166A0: mulli   r0, r27, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[27] * (s64)(s32)12);

label_800166A4:
    ctx->pc = 0x800166A4u;
    // 800166A4: lwzx    r29, r30, r29
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[29];
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_800166A8:
    ctx->pc = 0x800166A8u;
    // 800166A8: stw     r31, 92(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800166AC:
    ctx->pc = 0x800166ACu;
    // 800166AC: add   r31, r31, r0
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_800166B0:
    ctx->pc = 0x800166B0u;
    // 800166B0: subf   r9, r29, r31
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[9] = res;
    }

label_800166B4:
    ctx->pc = 0x800166B4u;
    // 800166B4: addi    r6, r31, 16
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(16);

label_800166B8:
    ctx->pc = 0x800166B8u;
    // 800166B8: or   r0, r9, r9
    {
        ctx->gpr[0] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800166BC:
    ctx->pc = 0x800166BCu;
    // 800166BC: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800166C0:
    ctx->pc = 0x800166C0u;
    // 800166C0: bc    4, 0, 0x800166C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800166C8;
        }
    }

label_800166C4:
    ctx->pc = 0x800166C4u;
    ctx->downcount -= 1;
    // 800166C4: addi    r0, r9, 15
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(15);

label_800166C8:
    ctx->pc = 0x800166C8u;
    ctx->downcount -= 11;
    // 800166C8: rlwinm r0, r0, 0, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF0u;
    }

label_800166CC:
    ctx->pc = 0x800166CCu;
    // 800166CC: cmpwi   r27, 0
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800166D0:
    ctx->pc = 0x800166D0u;
    // 800166D0: subf   r0, r0, r9
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800166D4:
    ctx->pc = 0x800166D4u;
    // 800166D4: cmpwi   cr7, r28, 0
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_800166D8:
    ctx->pc = 0x800166D8u;
    // 800166D8: subf   r31, r0, r6
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b + 1u;
        ctx->gpr[31] = res;
    }

label_800166DC:
    ctx->pc = 0x800166DCu;
    // 800166DC: addi    r30, r29, 28
    ctx->gpr[30] = ctx->gpr[29] + (u32)(s32)(28);

label_800166E0:
    ctx->pc = 0x800166E0u;
    // 800166E0: subf   r0, r29, r31
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800166E4:
    ctx->pc = 0x800166E4u;
    // 800166E4: addi    r24, r29, 15
    ctx->gpr[24] = ctx->gpr[29] + (u32)(s32)(15);

label_800166E8:
    ctx->pc = 0x800166E8u;
    // 800166E8: subf   r26, r0, r26
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[26];
        u32 res = a + b + 1u;
        ctx->gpr[26] = res;
    }

label_800166EC:
    ctx->pc = 0x800166ECu;
    // 800166EC: cmpwi   cr4, r23, 0
    {
        s32 val_a = (s32)(ctx->gpr[23]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_800166F0:
    ctx->pc = 0x800166F0u;
    // 800166F0: bc    4, 1, 0x80016714
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016714;
        }
    }

label_800166F4:
    ctx->pc = 0x800166F4u;
    ctx->downcount -= 4;
    // 800166F4: mtctr    r27
    ctx->ctr = ctx->gpr[27];

label_800166F8:
    ctx->pc = 0x800166F8u;
    // 800166F8: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_800166FC:
    ctx->pc = 0x800166FCu;
    // 800166FC: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80016700:
    loop_80016700(ctx);
    if (ctx->pc == 0x80016714u) goto label_80016714;
    return;
label_80016704:
    // 80016704: add   r9, r11, r9
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80016708:
    ctx->pc = 0x80016708u;
    // 80016708: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001670C:
    // 8001670C: addi    r11, r11, 12
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(12);

label_80016710:
    // 80016710: bc    16, 0, 0x80016700
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016700u;
                return;
            }
            goto label_80016700;
        }
    }

label_80016714:
    ctx->pc = 0x80016714u;
    ctx->downcount -= 1;
    // 80016714: bc    12, 30, 0x8001674C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001674C;
        }
    }

label_80016718:
    ctx->pc = 0x80016718u;
    ctx->downcount -= 13;
    // 80016718: lwz     r0, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001671C:
    ctx->pc = 0x8001671Cu;
    // 8001671C: lwz     r9, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016720:
    ctx->pc = 0x80016720u;
    // 80016720: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016724:
    ctx->pc = 0x80016724u;
    // 80016724: lwz     r10, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80016728:
    ctx->pc = 0x80016728u;
    // 80016728: stw     r0, 28(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001672C:
    ctx->pc = 0x8001672Cu;
    // 8001672C: stw     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80016730:
    ctx->pc = 0x80016730u;
    // 80016730: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80016734:
    ctx->pc = 0x80016734u;
    // 80016734: stw     r10, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80016738:
    ctx->pc = 0x80016738u;
    // 80016738: lwz     r0, 20(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001673C:
    ctx->pc = 0x8001673Cu;
    // 8001673C: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016740:
    ctx->pc = 0x80016740u;
    // 80016740: stw     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016744:
    ctx->pc = 0x80016744u;
    // 80016744: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80016748:
    ctx->pc = 0x80016748u;
    // 80016748: b       0x80016754
    {
            goto label_80016754;
    }

label_8001674C:
    ctx->pc = 0x8001674Cu;
    ctx->downcount -= 2;
    // 8001674C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80016750:
    ctx->pc = 0x80016750u;
    // 80016750: bl      0x801B4ED0
    {
            ctx->lr = 0x80016754u;
            ctx->pc = 0x801B4ED0u;
            return;
    }

label_80016754:
    ctx->pc = 0x80016754u;
    ctx->downcount -= 6;
    // 80016754: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_80016758:
    ctx->pc = 0x80016758u;
    // 80016758: or   r3, r24, r24
    {
        ctx->gpr[3] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8001675C:
    ctx->pc = 0x8001675Cu;
    // 8001675C: addi    r4, r4, -19588
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-19588);

label_80016760:
    ctx->pc = 0x80016760u;
    // 80016760: or   r5, r22, r22
    {
        ctx->gpr[5] = ctx->gpr[22] | ctx->gpr[22];
    }

label_80016764:
    ctx->pc = 0x80016764u;
    // 80016764: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80016768:
    ctx->pc = 0x80016768u;
    // 80016768: bl      0x80167074
    {
            ctx->lr = 0x8001676Cu;
            ctx->pc = 0x80167074u;
            return;
    }

label_8001676C:
    ctx->pc = 0x8001676Cu;
    ctx->downcount -= 1;
    // 8001676C: bc    4, 17, 0x8001678C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00004000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001678C;
        }
    }

label_80016770:
    ctx->pc = 0x80016770u;
    ctx->downcount -= 6;
    // 80016770: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80016774:
    ctx->pc = 0x80016774u;
    // 80016774: or   r5, r23, r23
    {
        ctx->gpr[5] = ctx->gpr[23] | ctx->gpr[23];
    }

label_80016778:
    ctx->pc = 0x80016778u;
    // 80016778: or   r6, r31, r31
    {
        ctx->gpr[6] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8001677C:
    ctx->pc = 0x8001677Cu;
    // 8001677C: or   r7, r26, r26
    {
        ctx->gpr[7] = ctx->gpr[26] | ctx->gpr[26];
    }

label_80016780:
    ctx->pc = 0x80016780u;
    // 80016780: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80016784:
    ctx->pc = 0x80016784u;
    // 80016784: bl      0x801B5F68
    {
            ctx->lr = 0x80016788u;
            ctx->pc = 0x801B5F68u;
            return;
    }

label_80016788:
    ctx->pc = 0x80016788u;
    ctx->downcount -= 1;
    // 80016788: b       0x800167A4
    {
            goto label_800167A4;
    }

label_8001678C:
    ctx->pc = 0x8001678Cu;
    ctx->downcount -= 6;
    // 8001678C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80016790:
    ctx->pc = 0x80016790u;
    // 80016790: or   r4, r20, r20
    {
        ctx->gpr[4] = ctx->gpr[20] | ctx->gpr[20];
    }

label_80016794:
    ctx->pc = 0x80016794u;
    // 80016794: stb     r0, 14(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(14);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80016798:
    ctx->pc = 0x80016798u;
    // 80016798: or   r5, r21, r21
    {
        ctx->gpr[5] = ctx->gpr[21] | ctx->gpr[21];
    }

label_8001679C:
    ctx->pc = 0x8001679Cu;
    // 8001679C: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800167A0:
    ctx->pc = 0x800167A0u;
    // 800167A0: bl      0x80016408
    {
            ctx->lr = 0x800167A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016408u;
                return;
            }
            goto label_80016408;
    }

label_800167A4:
    ctx->pc = 0x800167A4u;
    ctx->downcount -= 4;
    // 800167A4: stw     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800167A8:
    ctx->pc = 0x800167A8u;
    // 800167A8: lwz     r3, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800167AC:
    ctx->pc = 0x800167ACu;
    // 800167AC: cmpwi   r3, 0
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

label_800167B0:
    ctx->pc = 0x800167B0u;
    // 800167B0: bc    12, 0, 0x800167BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800167BC;
        }
    }

label_800167B4:
    ctx->pc = 0x800167B4u;
    ctx->downcount -= 2;
    // 800167B4: stw     r27, 88(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_800167B8:
    ctx->pc = 0x800167B8u;
    // 800167B8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800167BC:
    ctx->pc = 0x800167BCu;
    ctx->downcount -= 18;
    // 800167BC: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800167C0:
    ctx->pc = 0x800167C0u;
    // 800167C0: lwz     r12, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_800167C4:
    ctx->pc = 0x800167C4u;
    // 800167C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800167C8:
    ctx->pc = 0x800167C8u;
    // 800167C8: lmw     r20, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 20; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800167CC:
    ctx->pc = 0x800167CCu;
    // 800167CC: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_800167D0:
    ctx->pc = 0x800167D0u;
    // 800167D0: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_800167D4:
    ctx->pc = 0x800167D4u;
    // 800167D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800167D8:
    ctx->pc = 0x800167D8u;
    ctx->downcount -= 11;
    // 800167D8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800167DC:
    ctx->pc = 0x800167DCu;
    // 800167DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800167E0:
    ctx->pc = 0x800167E0u;
    // 800167E0: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800167E4:
    ctx->pc = 0x800167E4u;
    // 800167E4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800167E8:
    ctx->pc = 0x800167E8u;
    // 800167E8: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_800167EC:
    ctx->pc = 0x800167ECu;
    // 800167EC: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_800167F0:
    ctx->pc = 0x800167F0u;
    // 800167F0: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_800167F4:
    ctx->pc = 0x800167F4u;
    // 800167F4: lwzx    r31, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800167F8:
    ctx->pc = 0x800167F8u;
    // 800167F8: lbz     r0, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_800167FC:
    ctx->pc = 0x800167FCu;
    // 800167FC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016800:
    ctx->pc = 0x80016800u;
    // 80016800: bc    12, 2, 0x80016820
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016820;
        }
    }

label_80016804:
    ctx->pc = 0x80016804u;
    ctx->downcount -= 2;
    // 80016804: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016808:
    ctx->pc = 0x80016808u;
    // 80016808: bl      0x801B0BFC
    {
            ctx->lr = 0x8001680Cu;
            ctx->pc = 0x801B0BFCu;
            return;
    }

label_8001680C:
    ctx->pc = 0x8001680Cu;
    ctx->downcount -= 3;
    // 8001680C: lwz     r3, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016810:
    ctx->pc = 0x80016810u;
    // 80016810: cmpwi   r3, 0
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

label_80016814:
    ctx->pc = 0x80016814u;
    // 80016814: bc    12, 2, 0x80016828
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016828;
        }
    }

label_80016818:
    ctx->pc = 0x80016818u;
    ctx->downcount -= 1;
    // 80016818: bl      0x8003A990
    {
            ctx->lr = 0x8001681Cu;
            ctx->pc = 0x8003A990u;
            return;
    }

label_8001681C:
    ctx->pc = 0x8001681Cu;
    ctx->downcount -= 1;
    // 8001681C: b       0x80016828
    {
            goto label_80016828;
    }

label_80016820:
    ctx->pc = 0x80016820u;
    ctx->downcount -= 2;
    // 80016820: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016824:
    ctx->pc = 0x80016824u;
    // 80016824: bl      0x801B5F90
    {
            ctx->lr = 0x80016828u;
            ctx->pc = 0x801B5F90u;
            return;
    }

label_80016828:
    ctx->pc = 0x80016828u;
    ctx->downcount -= 2;
    // 80016828: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8001682C:
    ctx->pc = 0x8001682Cu;
    // 8001682C: bl      0x800162DC
    {
            ctx->lr = 0x80016830u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800162DCu;
                return;
            }
            goto label_800162DC;
    }

label_80016830:
    ctx->pc = 0x80016830u;
    ctx->downcount -= 6;
    // 80016830: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016834:
    ctx->pc = 0x80016834u;
    // 80016834: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016838:
    ctx->pc = 0x80016838u;
    // 80016838: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8001683C:
    ctx->pc = 0x8001683Cu;
    // 8001683C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80016840:
    ctx->pc = 0x80016840u;
    // 80016840: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016844:
    ctx->pc = 0x80016844u;
    ctx->downcount -= 6;
    // 80016844: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016848:
    ctx->pc = 0x80016848u;
    // 80016848: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_8001684C:
    ctx->pc = 0x8001684Cu;
    // 8001684C: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016850:
    ctx->pc = 0x80016850u;
    // 80016850: lwzx    r3, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016854:
    ctx->pc = 0x80016854u;
    // 80016854: cmpwi   r3, 0
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

label_80016858:
    ctx->pc = 0x80016858u;
    // 80016858: bc    12, 2, 0x80016870
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016870;
        }
    }

label_8001685C:
    ctx->pc = 0x8001685Cu;
    ctx->downcount -= 3;
    // 8001685C: lbz     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80016860:
    ctx->pc = 0x80016860u;
    // 80016860: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016864:
    ctx->pc = 0x80016864u;
    // 80016864: bc    12, 2, 0x80016870
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016870;
        }
    }

label_80016868:
    ctx->pc = 0x80016868u;
    ctx->downcount -= 2;
    // 80016868: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001686C:
    ctx->pc = 0x8001686Cu;
    // 8001686C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016870:
    ctx->pc = 0x80016870u;
    ctx->downcount -= 2;
    // 80016870: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_80016874:
    ctx->pc = 0x80016874u;
    // 80016874: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016878:
    ctx->pc = 0x80016878u;
    ctx->downcount -= 6;
    // 80016878: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_8001687C:
    ctx->pc = 0x8001687Cu;
    // 8001687C: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80016880:
    ctx->pc = 0x80016880u;
    // 80016880: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016884:
    ctx->pc = 0x80016884u;
    // 80016884: lwzx    r3, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016888:
    ctx->pc = 0x80016888u;
    // 80016888: cmpwi   r3, 0
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

label_8001688C:
    ctx->pc = 0x8001688Cu;
    // 8001688C: bc    12, 2, 0x800168A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800168A4;
        }
    }

label_80016890:
    ctx->pc = 0x80016890u;
    ctx->downcount -= 3;
    // 80016890: lbz     r0, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80016894:
    ctx->pc = 0x80016894u;
    // 80016894: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016898:
    ctx->pc = 0x80016898u;
    // 80016898: bc    4, 2, 0x800168A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800168A4;
        }
    }

label_8001689C:
    ctx->pc = 0x8001689Cu;
    ctx->downcount -= 2;
    // 8001689C: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800168A0:
    ctx->pc = 0x800168A0u;
    // 800168A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800168A4:
    ctx->pc = 0x800168A4u;
    ctx->downcount -= 2;
    // 800168A4: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_800168A8:
    ctx->pc = 0x800168A8u;
    // 800168A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800168AC:
    ctx->pc = 0x800168ACu;
    ctx->downcount -= 11;
    // 800168AC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800168B0:
    ctx->pc = 0x800168B0u;
    // 800168B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800168B4:
    ctx->pc = 0x800168B4u;
    // 800168B4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800168B8:
    ctx->pc = 0x800168B8u;
    // 800168B8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800168BC:
    ctx->pc = 0x800168BCu;
    // 800168BC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800168C0:
    ctx->pc = 0x800168C0u;
    // 800168C0: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_800168C4:
    ctx->pc = 0x800168C4u;
    // 800168C4: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_800168C8:
    ctx->pc = 0x800168C8u;
    // 800168C8: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_800168CC:
    ctx->pc = 0x800168CCu;
    // 800168CC: lwzx    r9, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800168D0:
    ctx->pc = 0x800168D0u;
    // 800168D0: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800168D4:
    ctx->pc = 0x800168D4u;
    // 800168D4: bc    12, 2, 0x800168EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800168EC;
        }
    }

label_800168D8:
    ctx->pc = 0x800168D8u;
    ctx->downcount -= 3;
    // 800168D8: lwz     r0, 80(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800168DC:
    ctx->pc = 0x800168DCu;
    // 800168DC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800168E0:
    ctx->pc = 0x800168E0u;
    // 800168E0: bc    12, 2, 0x800168EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800168EC;
        }
    }

label_800168E4:
    ctx->pc = 0x800168E4u;
    ctx->downcount -= 2;
    // 800168E4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800168E8:
    ctx->pc = 0x800168E8u;
    // 800168E8: bl      0x80016B08
    {
            ctx->lr = 0x800168ECu;
            goto label_80016B08;
    }

label_800168EC:
    ctx->pc = 0x800168ECu;
    ctx->downcount -= 11;
    // 800168EC: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_800168F0:
    ctx->pc = 0x800168F0u;
    // 800168F0: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_800168F4:
    ctx->pc = 0x800168F4u;
    // 800168F4: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_800168F8:
    ctx->pc = 0x800168F8u;
    // 800168F8: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800168FC:
    ctx->pc = 0x800168FCu;
    // 800168FC: lwz     r3, 76(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(76);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016900:
    ctx->pc = 0x80016900u;
    // 80016900: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016904:
    ctx->pc = 0x80016904u;
    // 80016904: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016908:
    ctx->pc = 0x80016908u;
    // 80016908: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8001690C:
    ctx->pc = 0x8001690Cu;
    // 8001690C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80016910:
    ctx->pc = 0x80016910u;
    // 80016910: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016914:
    ctx->pc = 0x80016914u;
    ctx->downcount -= 11;
    // 80016914: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016918:
    ctx->pc = 0x80016918u;
    // 80016918: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001691C:
    ctx->pc = 0x8001691Cu;
    // 8001691C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80016920:
    ctx->pc = 0x80016920u;
    // 80016920: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016924:
    ctx->pc = 0x80016924u;
    // 80016924: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016928:
    ctx->pc = 0x80016928u;
    // 80016928: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_8001692C:
    ctx->pc = 0x8001692Cu;
    // 8001692C: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016930:
    ctx->pc = 0x80016930u;
    // 80016930: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_80016934:
    ctx->pc = 0x80016934u;
    // 80016934: lwzx    r9, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016938:
    ctx->pc = 0x80016938u;
    // 80016938: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001693C:
    ctx->pc = 0x8001693Cu;
    // 8001693C: bc    12, 2, 0x80016954
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016954;
        }
    }

label_80016940:
    ctx->pc = 0x80016940u;
    ctx->downcount -= 3;
    // 80016940: lwz     r0, 80(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016944:
    ctx->pc = 0x80016944u;
    // 80016944: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016948:
    ctx->pc = 0x80016948u;
    // 80016948: bc    12, 2, 0x80016954
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016954;
        }
    }

label_8001694C:
    ctx->pc = 0x8001694Cu;
    ctx->downcount -= 2;
    // 8001694C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016950:
    ctx->pc = 0x80016950u;
    // 80016950: bl      0x80016B08
    {
            ctx->lr = 0x80016954u;
            goto label_80016B08;
    }

label_80016954:
    ctx->pc = 0x80016954u;
    ctx->downcount -= 11;
    // 80016954: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016958:
    ctx->pc = 0x80016958u;
    // 80016958: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_8001695C:
    ctx->pc = 0x8001695Cu;
    // 8001695C: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016960:
    ctx->pc = 0x80016960u;
    // 80016960: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016964:
    ctx->pc = 0x80016964u;
    // 80016964: lwz     r3, 68(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(68);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016968:
    ctx->pc = 0x80016968u;
    // 80016968: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8001696C:
    ctx->pc = 0x8001696Cu;
    // 8001696C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016970:
    ctx->pc = 0x80016970u;
    // 80016970: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016974:
    ctx->pc = 0x80016974u;
    // 80016974: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80016978:
    ctx->pc = 0x80016978u;
    // 80016978: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_8001697C:
    ctx->pc = 0x8001697Cu;
    ctx->downcount -= 11;
    // 8001697C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016980:
    ctx->pc = 0x80016980u;
    // 80016980: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016984:
    ctx->pc = 0x80016984u;
    // 80016984: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80016988:
    ctx->pc = 0x80016988u;
    // 80016988: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001698C:
    ctx->pc = 0x8001698Cu;
    // 8001698C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016990:
    ctx->pc = 0x80016990u;
    // 80016990: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016994:
    ctx->pc = 0x80016994u;
    // 80016994: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016998:
    ctx->pc = 0x80016998u;
    // 80016998: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_8001699C:
    ctx->pc = 0x8001699Cu;
    // 8001699C: lwzx    r9, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800169A0:
    ctx->pc = 0x800169A0u;
    // 800169A0: cmpwi   r9, 0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800169A4:
    ctx->pc = 0x800169A4u;
    // 800169A4: bc    12, 2, 0x800169BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800169BC;
        }
    }

label_800169A8:
    ctx->pc = 0x800169A8u;
    ctx->downcount -= 3;
    // 800169A8: lwz     r0, 80(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800169AC:
    ctx->pc = 0x800169ACu;
    // 800169AC: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800169B0:
    ctx->pc = 0x800169B0u;
    // 800169B0: bc    12, 2, 0x800169BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800169BC;
        }
    }

label_800169B4:
    ctx->pc = 0x800169B4u;
    ctx->downcount -= 2;
    // 800169B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800169B8:
    ctx->pc = 0x800169B8u;
    // 800169B8: bl      0x80016B08
    {
            ctx->lr = 0x800169BCu;
            goto label_80016B08;
    }

label_800169BC:
    ctx->pc = 0x800169BCu;
    ctx->downcount -= 11;
    // 800169BC: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_800169C0:
    ctx->pc = 0x800169C0u;
    // 800169C0: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_800169C4:
    ctx->pc = 0x800169C4u;
    // 800169C4: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_800169C8:
    ctx->pc = 0x800169C8u;
    // 800169C8: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800169CC:
    ctx->pc = 0x800169CCu;
    // 800169CC: lwz     r3, 60(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(60);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800169D0:
    ctx->pc = 0x800169D0u;
    // 800169D0: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800169D4:
    ctx->pc = 0x800169D4u;
    // 800169D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800169D8:
    ctx->pc = 0x800169D8u;
    // 800169D8: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800169DC:
    ctx->pc = 0x800169DCu;
    // 800169DC: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800169E0:
    ctx->pc = 0x800169E0u;
    // 800169E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800169E4:
    ctx->pc = 0x800169E4u;
    ctx->downcount -= 21;
    // 800169E4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800169E8:
    ctx->pc = 0x800169E8u;
    // 800169E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800169EC:
    ctx->pc = 0x800169ECu;
    // 800169EC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800169F0:
    ctx->pc = 0x800169F0u;
    // 800169F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800169F4:
    ctx->pc = 0x800169F4u;
    // 800169F4: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_800169F8:
    ctx->pc = 0x800169F8u;
    // 800169F8: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_800169FC:
    ctx->pc = 0x800169FCu;
    // 800169FC: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016A00:
    ctx->pc = 0x80016A00u;
    // 80016A00: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016A04:
    ctx->pc = 0x80016A04u;
    // 80016A04: lwzx    r31, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016A08:
    ctx->pc = 0x80016A08u;
    // 80016A08: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016A0C:
    ctx->pc = 0x80016A0Cu;
    // 80016A0C: bc    12, 2, 0x80016A24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016A24;
        }
    }

label_80016A10:
    ctx->pc = 0x80016A10u;
    ctx->downcount -= 3;
    // 80016A10: lwz     r0, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016A14:
    ctx->pc = 0x80016A14u;
    // 80016A14: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016A18:
    ctx->pc = 0x80016A18u;
    // 80016A18: bc    12, 2, 0x80016A24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016A24;
        }
    }

label_80016A1C:
    ctx->pc = 0x80016A1Cu;
    ctx->downcount -= 2;
    // 80016A1C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016A20:
    ctx->pc = 0x80016A20u;
    // 80016A20: bl      0x80016B08
    {
            ctx->lr = 0x80016A24u;
            goto label_80016B08;
    }

label_80016A24:
    ctx->pc = 0x80016A24u;
    ctx->downcount -= 2;
    // 80016A24: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016A28:
    ctx->pc = 0x80016A28u;
    // 80016A28: bc    4, 0, 0x80016A34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016A34;
        }
    }

label_80016A2C:
    ctx->pc = 0x80016A2Cu;
    ctx->downcount -= 2;
    // 80016A2C: lwz     r3, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016A30:
    ctx->pc = 0x80016A30u;
    // 80016A30: b       0x80016A60
    {
            goto label_80016A60;
    }

label_80016A34:
    ctx->pc = 0x80016A34u;
    ctx->downcount -= 4;
    // 80016A34: lwz     r0, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016A38:
    ctx->pc = 0x80016A38u;
    // 80016A38: cmpw    r30, r0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016A3C:
    ctx->pc = 0x80016A3Cu;
    // 80016A3C: li      r3, -8
    ctx->gpr[3] = (u32)(s32)(-8);

label_80016A40:
    ctx->pc = 0x80016A40u;
    // 80016A40: bc    4, 0, 0x80016A60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016A60;
        }
    }

label_80016A44:
    ctx->pc = 0x80016A44u;
    ctx->downcount -= 8;
    // 80016A44: mulli   r0, r30, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[30] * (s64)(s32)12);

label_80016A48:
    ctx->pc = 0x80016A48u;
    // 80016A48: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016A4C:
    ctx->pc = 0x80016A4Cu;
    // 80016A4C: add   r4, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80016A50:
    ctx->pc = 0x80016A50u;
    // 80016A50: lwz     r11, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016A54:
    ctx->pc = 0x80016A54u;
    // 80016A54: cmpwi   r11, 0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016A58:
    ctx->pc = 0x80016A58u;
    // 80016A58: bc    12, 0, 0x80016A60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016A60;
        }
    }

label_80016A5C:
    ctx->pc = 0x80016A5Cu;
    ctx->downcount -= 1;
    // 80016A5C: lwz     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016A60:
    ctx->pc = 0x80016A60u;
    ctx->downcount -= 16;
    // 80016A60: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016A64:
    ctx->pc = 0x80016A64u;
    // 80016A64: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016A68:
    ctx->pc = 0x80016A68u;
    // 80016A68: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80016A6C:
    ctx->pc = 0x80016A6Cu;
    // 80016A6C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80016A70:
    ctx->pc = 0x80016A70u;
    // 80016A70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016A74:
    ctx->pc = 0x80016A74u;
    ctx->downcount -= 21;
    // 80016A74: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016A78:
    ctx->pc = 0x80016A78u;
    // 80016A78: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016A7C:
    ctx->pc = 0x80016A7Cu;
    // 80016A7C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80016A80:
    ctx->pc = 0x80016A80u;
    // 80016A80: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016A84:
    ctx->pc = 0x80016A84u;
    // 80016A84: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016A88:
    ctx->pc = 0x80016A88u;
    // 80016A88: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80016A8C:
    ctx->pc = 0x80016A8Cu;
    // 80016A8C: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016A90:
    ctx->pc = 0x80016A90u;
    // 80016A90: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016A94:
    ctx->pc = 0x80016A94u;
    // 80016A94: lwzx    r31, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016A98:
    ctx->pc = 0x80016A98u;
    // 80016A98: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016A9C:
    ctx->pc = 0x80016A9Cu;
    // 80016A9C: bc    12, 2, 0x80016AB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016AB4;
        }
    }

label_80016AA0:
    ctx->pc = 0x80016AA0u;
    ctx->downcount -= 3;
    // 80016AA0: lwz     r0, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016AA4:
    ctx->pc = 0x80016AA4u;
    // 80016AA4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016AA8:
    ctx->pc = 0x80016AA8u;
    // 80016AA8: bc    12, 2, 0x80016AB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016AB4;
        }
    }

label_80016AAC:
    ctx->pc = 0x80016AACu;
    ctx->downcount -= 2;
    // 80016AAC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016AB0:
    ctx->pc = 0x80016AB0u;
    // 80016AB0: bl      0x80016B08
    {
            ctx->lr = 0x80016AB4u;
            goto label_80016B08;
    }

label_80016AB4:
    ctx->pc = 0x80016AB4u;
    ctx->downcount -= 4;
    // 80016AB4: lwz     r0, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016AB8:
    ctx->pc = 0x80016AB8u;
    // 80016AB8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80016ABC:
    ctx->pc = 0x80016ABCu;
    // 80016ABC: cmpw    r11, r0
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016AC0:
    ctx->pc = 0x80016AC0u;
    // 80016AC0: bc    4, 0, 0x80016AF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016AF0;
        }
    }

label_80016AC4:
    ctx->pc = 0x80016AC4u;
    ctx->downcount -= 2;
    // 80016AC4: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016AC8:
    ctx->pc = 0x80016AC8u;
    // 80016AC8: or   r10, r0, r0
    {
        ctx->gpr[10] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80016ACC:
    ctx->pc = 0x80016ACCu;
    ctx->downcount -= 3;
    // 80016ACC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016AD0:
    // 80016AD0: cmpw    r0, r30
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016AD4:
    // 80016AD4: bc    4, 2, 0x80016AE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016AE0;
        }
    }

label_80016AD8:
    ctx->pc = 0x80016AD8u;
    ctx->downcount -= 2;
    // 80016AD8: lwz     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016ADC:
    // 80016ADC: b       0x80016AF4
    {
            goto label_80016AF4;
    }

label_80016AE0:
    ctx->downcount -= 4;
    // 80016AE0: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_80016AE4:
    // 80016AE4: addi    r9, r9, 12
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12);

label_80016AE8:
    // 80016AE8: cmpw    r11, r10
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016AEC:
    // 80016AEC: bc    12, 0, 0x80016ACC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016ACCu;
                return;
            }
            goto label_80016ACC;
        }
    }

label_80016AF0:
    ctx->pc = 0x80016AF0u;
    ctx->downcount -= 1;
    // 80016AF0: li      r3, -8
    ctx->gpr[3] = (u32)(s32)(-8);

label_80016AF4:
    ctx->pc = 0x80016AF4u;
    ctx->downcount -= 16;
    // 80016AF4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016AF8:
    ctx->pc = 0x80016AF8u;
    // 80016AF8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016AFC:
    ctx->pc = 0x80016AFCu;
    // 80016AFC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80016B00:
    ctx->pc = 0x80016B00u;
    // 80016B00: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80016B04:
    ctx->pc = 0x80016B04u;
    // 80016B04: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016B08:
    ctx->pc = 0x80016B08u;
    ctx->downcount -= 20;
    // 80016B08: stwu     r1, -248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-248);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016B0C:
    ctx->pc = 0x80016B0Cu;
    // 80016B0C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016B10:
    ctx->pc = 0x80016B10u;
    // 80016B10: stfd     f29, 224(r1)
    if (!ppc_fp_available(ctx, 0x80016B10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_80016B14:
    ctx->pc = 0x80016B14u;
    // 80016B14: stfd     f30, 232(r1)
    if (!ppc_fp_available(ctx, 0x80016B14u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_80016B18:
    ctx->pc = 0x80016B18u;
    // 80016B18: stfd     f31, 240(r1)
    if (!ppc_fp_available(ctx, 0x80016B18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_80016B1C:
    ctx->pc = 0x80016B1Cu;
    // 80016B1C: stmw     r18, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        for (u32 r = 18; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80016B20:
    ctx->pc = 0x80016B20u;
    // 80016B20: stw     r0, 252(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(252);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016B24:
    ctx->pc = 0x80016B24u;
    // 80016B24: or   r19, r3, r3
    {
        ctx->gpr[19] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016B28:
    ctx->pc = 0x80016B28u;
    // 80016B28: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80016B2C:
    ctx->pc = 0x80016B2Cu;
    // 80016B2C: bl      0x801B52DC
    {
            ctx->lr = 0x80016B30u;
            ctx->pc = 0x801B52DCu;
            return;
    }

label_80016B30:
    ctx->pc = 0x80016B30u;
    ctx->downcount -= 11;
    // 80016B30: lis     r18, -32703
    ctx->gpr[18] = ((u32)(s32)(-32703) << 16);

label_80016B34:
    ctx->pc = 0x80016B34u;
    // 80016B34: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80016B38:
    ctx->pc = 0x80016B38u;
    // 80016B38: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_80016B3C:
    ctx->pc = 0x80016B3Cu;
    // 80016B3C: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80016B40:
    ctx->pc = 0x80016B40u;
    // 80016B40: lfd     f30, -19584(r9)
    if (!ppc_fp_available(ctx, 0x80016B40u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19584);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016B44:
    ctx->pc = 0x80016B44u;
    // 80016B44: lfd     f31, -19576(r11)
    if (!ppc_fp_available(ctx, 0x80016B44u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-19576);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016B48:
    ctx->pc = 0x80016B48u;
    // 80016B48: li      r20, 0
    ctx->gpr[20] = (u32)(s32)(0);

label_80016B4C:
    ctx->pc = 0x80016B4Cu;
    // 80016B4C: lfs     f29, -19568(r10)
    if (!ppc_fp_available(ctx, 0x80016B4Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-19568);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_80016B50:
    ctx->pc = 0x80016B50u;
    // 80016B50: li      r21, 1
    ctx->gpr[21] = (u32)(s32)(1);

label_80016B54:
    ctx->pc = 0x80016B54u;
    // 80016B54: li      r23, -1
    ctx->gpr[23] = (u32)(s32)(-1);

label_80016B58:
    ctx->pc = 0x80016B58u;
    // 80016B58: lis     r22, 17200
    ctx->gpr[22] = ((u32)(s32)(17200) << 16);

label_80016B5C:
    ctx->downcount -= 6;
    // 80016B5C: addi    r9, r18, -27132
    ctx->gpr[9] = ctx->gpr[18] + (u32)(s32)(-27132);

label_80016B60:
    // 80016B60: rlwinm r0, r30, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_80016B64:
    ctx->pc = 0x80016B64u;
    // 80016B64: lwzx    r31, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016B68:
    // 80016B68: addi    r25, r30, 1
    ctx->gpr[25] = ctx->gpr[30] + (u32)(s32)(1);

label_80016B6C:
    // 80016B6C: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016B70:
    // 80016B70: bc    12, 2, 0x80016E1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016E1C;
        }
    }

label_80016B74:
    ctx->downcount -= 2;
    // 80016B74: cmpwi   r19, 0
    {
        s32 val_a = (s32)(ctx->gpr[19]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016B78:
    // 80016B78: bc    12, 2, 0x80016B88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016B88;
        }
    }

label_80016B7C:
    ctx->pc = 0x80016B7Cu;
    ctx->downcount -= 3;
    // 80016B7C: stw     r21, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[21]);
    }

label_80016B80:
    ctx->pc = 0x80016B80u;
    // 80016B80: stw     r20, 84(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[20]);
    }

label_80016B84:
    // 80016B84: b       0x80016E1C
    {
            goto label_80016E1C;
    }

label_80016B88:
    ctx->pc = 0x80016B88u;
    ctx->downcount -= 7;
    // 80016B88: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016B8C:
    // 80016B8C: li      r24, -8
    ctx->gpr[24] = (u32)(s32)(-8);

label_80016B90:
    // 80016B90: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_80016B94:
    // 80016B94: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80016B98:
    ctx->pc = 0x80016B98u;
    // 80016B98: stw     r21, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[21]);
    }

label_80016B9C:
    // 80016B9C: cmpwi   r3, 0
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

label_80016BA0:
    // 80016BA0: bc    12, 0, 0x80016E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016E0C;
        }
    }

label_80016BA4:
    ctx->pc = 0x80016BA4u;
    ctx->downcount -= 3;
    // 80016BA4: lbz     r0, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80016BA8:
    // 80016BA8: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016BAC:
    // 80016BAC: bc    12, 2, 0x80016C98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016C98;
        }
    }

label_80016BB0:
    ctx->pc = 0x80016BB0u;
    ctx->downcount -= 3;
    // 80016BB0: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80016BB4:
    // 80016BB4: cmpwi   r4, 0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016BB8:
    // 80016BB8: bc    12, 0, 0x80016E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016E0C;
        }
    }

label_80016BBC:
    ctx->pc = 0x80016BBCu;
    ctx->downcount -= 4;
    // 80016BBC: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016BC0:
    ctx->pc = 0x80016BC0u;
    // 80016BC0: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016BC4:
    // 80016BC4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016BC8:
    // 80016BC8: bc    12, 0, 0x80016E0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016E0C;
        }
    }

label_80016BCC:
    ctx->downcount -= 4;
    // 80016BCC: addi    r5, r1, 152
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(152);

label_80016BD0:
    // 80016BD0: addi    r6, r1, 40
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(40);

label_80016BD4:
    // 80016BD4: addi    r7, r1, 128
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(128);

label_80016BD8:
    // 80016BD8: bl      0x801B0A90
    {
            ctx->lr = 0x80016BDCu;
            ctx->pc = 0x801B0A90u;
            return;
    }

label_80016BDC:
    ctx->downcount -= 2;
    // 80016BDC: or.   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[24];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80016BE0:
    // 80016BE0: bc    12, 0, 0x80016C64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016C64;
        }
    }

label_80016BE4:
    ctx->pc = 0x80016BE4u;
    ctx->downcount -= 3;
    // 80016BE4: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016BE8:
    ctx->pc = 0x80016BE8u;
    // 80016BE8: lwz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016BEC:
    // 80016BEC: bl      0x801B7508
    {
            ctx->lr = 0x80016BF0u;
            ctx->pc = 0x801B7508u;
            return;
    }

label_80016BF0:
    ctx->downcount -= 2;
    // 80016BF0: or.   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80016BF4:
    // 80016BF4: bc    4, 0, 0x80016C08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016C08;
        }
    }

label_80016BF8:
    ctx->pc = 0x80016BF8u;
    ctx->downcount -= 4;
    // 80016BF8: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016BFC:
    // 80016BFC: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_80016C00:
    ctx->pc = 0x80016C00u;
    // 80016C00: stw     r23, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_80016C04:
    // 80016C04: b       0x80016E0C
    {
            goto label_80016E0C;
    }

label_80016C08:
    ctx->pc = 0x80016C08u;
    ctx->downcount -= 41;
    // 80016C08: lwz     r11, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016C0C:
    ctx->pc = 0x80016C0Cu;
    // 80016C0C: lhz     r0, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80016C10:
    // 80016C10: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80016C14:
    ctx->pc = 0x80016C14u;
    // 80016C14: stw     r11, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80016C18:
    // 80016C18: mulli   r29, r29, 10
    ctx->gpr[29] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)10);

label_80016C1C:
    // 80016C1C: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_80016C20:
    ctx->pc = 0x80016C20u;
    // 80016C20: stw     r22, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80016C24:
    // 80016C24: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80016C28:
    ctx->pc = 0x80016C28u;
    // 80016C28: lfd     f13, 160(r1)
    if (!ppc_fp_available(ctx, 0x80016C28u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016C2C:
    ctx->pc = 0x80016C2Cu;
    // 80016C2C: stw     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016C30:
    ctx->pc = 0x80016C30u;
    // 80016C30: fsub   f13, f13, f30
    if (!ppc_fp_available(ctx, 0x80016C30u)) return;
    ppc_fsub(ctx, 13, 13, 30);

label_80016C34:
    ctx->pc = 0x80016C34u;
    // 80016C34: stw     r22, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80016C38:
    ctx->pc = 0x80016C38u;
    // 80016C38: frsp    f13, f13
    if (!ppc_fp_available(ctx, 0x80016C38u)) return;
    ppc_frsp(ctx, 13, 13);

label_80016C3C:
    ctx->pc = 0x80016C3Cu;
    // 80016C3C: lfd     f0, 160(r1)
    if (!ppc_fp_available(ctx, 0x80016C3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016C40:
    ctx->pc = 0x80016C40u;
    // 80016C40: fsub   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x80016C40u)) return;
    ppc_fsub(ctx, 0, 0, 31);

label_80016C44:
    ctx->pc = 0x80016C44u;
    // 80016C44: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x80016C44u)) return;
    ppc_frsp(ctx, 0, 0);

label_80016C48:
    ctx->pc = 0x80016C48u;
    // 80016C48: fdivs   f13, f13, f0
    if (!ppc_fp_available(ctx, 0x80016C48u)) return;
    ppc_fdivs(ctx, 13, 13, 0);

label_80016C4C:
    ctx->pc = 0x80016C4Cu;
    // 80016C4C: fmuls   f13, f13, f29
    if (!ppc_fp_available(ctx, 0x80016C4Cu)) return;
    ppc_fmuls(ctx, 13, 13, 29);

label_80016C50:
    ctx->pc = 0x80016C50u;
    // 80016C50: fmr    f0, f13
    if (!ppc_fp_available(ctx, 0x80016C50u)) return;
    ctx->fpr[0] = ctx->fpr[13];

label_80016C54:
    ctx->pc = 0x80016C54u;
    // 80016C54: fctiwz    f12, f0
    if (!ppc_fp_available(ctx, 0x80016C54u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_80016C58:
    ctx->pc = 0x80016C58u;
    // 80016C58: stfd     f12, 160(r1)
    if (!ppc_fp_available(ctx, 0x80016C58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_80016C5C:
    ctx->pc = 0x80016C5Cu;
    // 80016C5C: lwz     r11, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016C60:
    // 80016C60: subf   r26, r29, r11
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[11];
        u32 res = a + b + 1u;
        ctx->gpr[26] = res;
    }

label_80016C64:
    ctx->pc = 0x80016C64u;
    ctx->downcount -= 8;
    // 80016C64: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016C68:
    // 80016C68: addi    r25, r30, 1
    ctx->gpr[25] = ctx->gpr[30] + (u32)(s32)(1);

label_80016C6C:
    ctx->pc = 0x80016C6Cu;
    // 80016C6C: stw     r29, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80016C70:
    ctx->pc = 0x80016C70u;
    // 80016C70: lwz     r11, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016C74:
    ctx->pc = 0x80016C74u;
    // 80016C74: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016C78:
    ctx->pc = 0x80016C78u;
    // 80016C78: stw     r0, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016C7C:
    ctx->pc = 0x80016C7Cu;
    // 80016C7C: lwz     r3, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016C80:
    // 80016C80: bl      0x801B0EF4
    {
            ctx->lr = 0x80016C84u;
            ctx->pc = 0x801B0EF4u;
            return;
    }

label_80016C84:
    ctx->pc = 0x80016C84u;
    ctx->downcount -= 5;
    // 80016C84: stw     r3, 76(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80016C88:
    ctx->pc = 0x80016C88u;
    // 80016C88: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016C8C:
    ctx->pc = 0x80016C8Cu;
    // 80016C8C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016C90:
    ctx->pc = 0x80016C90u;
    // 80016C90: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016C94:
    // 80016C94: b       0x80016E0C
    {
            goto label_80016E0C;
    }

label_80016C98:
    ctx->downcount -= 2;
    // 80016C98: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_80016C9C:
    // 80016C9C: bl      0x801B6600
    {
            ctx->lr = 0x80016CA0u;
            ctx->pc = 0x801B6600u;
            return;
    }

label_80016CA0:
    ctx->pc = 0x80016CA0u;
    ctx->downcount -= 6;
    // 80016CA0: stw     r29, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80016CA4:
    // 80016CA4: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016CA8:
    ctx->pc = 0x80016CA8u;
    // 80016CA8: lwz     r9, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016CAC:
    ctx->pc = 0x80016CACu;
    // 80016CAC: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016CB0:
    // 80016CB0: cmpw    r0, r9
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016CB4:
    // 80016CB4: bc    12, 0, 0x80016CBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016CBC;
        }
    }

label_80016CB8:
    ctx->pc = 0x80016CB8u;
    ctx->downcount -= 1;
    // 80016CB8: stw     r29, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80016CBC:
    ctx->pc = 0x80016CBCu;
    ctx->downcount -= 4;
    // 80016CBC: lwz     r0, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016CC0:
    // 80016CC0: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_80016CC4:
    // 80016CC4: cmpw    r29, r0
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016CC8:
    // 80016CC8: bc    4, 0, 0x80016E00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016E00;
        }
    }

label_80016CCC:
    ctx->downcount -= 2;
    // 80016CCC: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_80016CD0:
    // 80016CD0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80016CD4:
    ctx->pc = 0x80016CD4u;
    ctx->downcount -= 8;
    // 80016CD4: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016CD8:
    // 80016CD8: add   r9, r30, r9
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80016CDC:
    ctx->pc = 0x80016CDCu;
    // 80016CDC: stw     r28, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80016CE0:
    ctx->pc = 0x80016CE0u;
    // 80016CE0: lwz     r11, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016CE4:
    // 80016CE4: add   r11, r30, r11
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80016CE8:
    ctx->pc = 0x80016CE8u;
    // 80016CE8: lwz     r3, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016CEC:
    // 80016CEC: cmpwi   r3, 0
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

label_80016CF0:
    // 80016CF0: bc    12, 0, 0x80016DEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016DEC;
        }
    }

label_80016CF4:
    ctx->downcount -= 2;
    // 80016CF4: addi    r4, r1, 24
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(24);

label_80016CF8:
    // 80016CF8: bl      0x801B64A4
    {
            ctx->lr = 0x80016CFCu;
            ctx->pc = 0x801B64A4u;
            return;
    }

label_80016CFC:
    ctx->pc = 0x80016CFCu;
    ctx->downcount -= 3;
    // 80016CFC: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016D00:
    // 80016D00: cmpwi   r0, 1
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016D04:
    // 80016D04: bc    12, 2, 0x80016D24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016D24;
        }
    }

label_80016D08:
    ctx->downcount -= 1;
    // 80016D08: bc    12, 1, 0x80016D18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016D18;
        }
    }

label_80016D0C:
    ctx->downcount -= 2;
    // 80016D0C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016D10:
    // 80016D10: bc    12, 2, 0x80016D6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016D6C;
        }
    }

label_80016D14:
    ctx->downcount -= 1;
    // 80016D14: b       0x80016DE0
    {
            goto label_80016DE0;
    }

label_80016D18:
    ctx->downcount -= 2;
    // 80016D18: cmpwi   r0, 2
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016D1C:
    // 80016D1C: bc    12, 2, 0x80016D6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016D6C;
        }
    }

label_80016D20:
    ctx->downcount -= 1;
    // 80016D20: b       0x80016DE0
    {
            goto label_80016DE0;
    }

label_80016D24:
    ctx->pc = 0x80016D24u;
    ctx->downcount -= 18;
    // 80016D24: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016D28:
    ctx->pc = 0x80016D28u;
    // 80016D28: lwzx    r0, r30, r9
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016D2C:
    // 80016D2C: add   r9, r30, r9
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80016D30:
    ctx->pc = 0x80016D30u;
    // 80016D30: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016D34:
    ctx->pc = 0x80016D34u;
    // 80016D34: lwz     r10, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80016D38:
    ctx->pc = 0x80016D38u;
    // 80016D38: lwz     r0, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016D3C:
    ctx->pc = 0x80016D3Cu;
    // 80016D3C: lwzx    r11, r30, r10
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[10];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016D40:
    ctx->pc = 0x80016D40u;
    // 80016D40: lwz     r9, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016D44:
    // 80016D44: add   r10, r30, r10
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[10] = res;
    }

label_80016D48:
    // 80016D48: add   r0, r0, r11
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80016D4C:
    ctx->pc = 0x80016D4Cu;
    // 80016D4C: stw     r0, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016D50:
    ctx->pc = 0x80016D50u;
    // 80016D50: lwz     r11, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016D54:
    ctx->pc = 0x80016D54u;
    // 80016D54: stw     r28, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80016D58:
    // 80016D58: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80016D5C:
    ctx->pc = 0x80016D5Cu;
    // 80016D5C: stw     r9, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80016D60:
    ctx->pc = 0x80016D60u;
    // 80016D60: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016D64:
    ctx->pc = 0x80016D64u;
    // 80016D64: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016D68:
    // 80016D68: b       0x80016DEC
    {
            goto label_80016DEC;
    }

label_80016D6C:
    ctx->pc = 0x80016D6Cu;
    ctx->downcount -= 4;
    // 80016D6C: lwz     r26, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_80016D70:
    ctx->pc = 0x80016D70u;
    // 80016D70: lwz     r29, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80016D74:
    // 80016D74: cmpwi   r26, 0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016D78:
    // 80016D78: bc    4, 2, 0x80016D90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016D90;
        }
    }

label_80016D7C:
    ctx->downcount -= 2;
    // 80016D7C: cmpwi   r29, 0
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

label_80016D80:
    // 80016D80: bc    4, 2, 0x80016D90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016D90;
        }
    }

label_80016D84:
    ctx->pc = 0x80016D84u;
    ctx->downcount -= 3;
    // 80016D84: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016D88:
    ctx->pc = 0x80016D88u;
    // 80016D88: lwzx    r29, r30, r9
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[9];
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80016D8C:
    // 80016D8C: or   r26, r29, r29
    {
        ctx->gpr[26] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80016D90:
    ctx->pc = 0x80016D90u;
    ctx->downcount -= 14;
    // 80016D90: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016D94:
    // 80016D94: add   r9, r30, r9
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80016D98:
    ctx->pc = 0x80016D98u;
    // 80016D98: stw     r29, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80016D9C:
    ctx->pc = 0x80016D9Cu;
    // 80016D9C: lwz     r0, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016DA0:
    ctx->pc = 0x80016DA0u;
    // 80016DA0: lwz     r11, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80016DA4:
    // 80016DA4: add   r0, r0, r29
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80016DA8:
    ctx->pc = 0x80016DA8u;
    // 80016DA8: stw     r0, 64(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016DAC:
    ctx->pc = 0x80016DACu;
    // 80016DAC: lwz     r9, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016DB0:
    // 80016DB0: add   r11, r11, r9
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80016DB4:
    ctx->pc = 0x80016DB4u;
    // 80016DB4: stw     r11, 60(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80016DB8:
    ctx->pc = 0x80016DB8u;
    // 80016DB8: lwz     r9, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016DBC:
    ctx->pc = 0x80016DBCu;
    // 80016DBC: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016DC0:
    // 80016DC0: cmpw    r9, r0
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016DC4:
    // 80016DC4: bc    4, 0, 0x80016DCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016DCC;
        }
    }

label_80016DC8:
    ctx->pc = 0x80016DC8u;
    ctx->downcount -= 1;
    // 80016DC8: stw     r28, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80016DCC:
    ctx->pc = 0x80016DCCu;
    ctx->downcount -= 5;
    // 80016DCC: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016DD0:
    // 80016DD0: add   r9, r30, r9
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80016DD4:
    ctx->pc = 0x80016DD4u;
    // 80016DD4: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016DD8:
    ctx->pc = 0x80016DD8u;
    // 80016DD8: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016DDC:
    // 80016DDC: b       0x80016DEC
    {
            goto label_80016DEC;
    }

label_80016DE0:
    ctx->pc = 0x80016DE0u;
    ctx->downcount -= 3;
    // 80016DE0: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016DE4:
    // 80016DE4: add   r9, r30, r9
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80016DE8:
    ctx->pc = 0x80016DE8u;
    // 80016DE8: stw     r23, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_80016DEC:
    ctx->pc = 0x80016DECu;
    ctx->downcount -= 5;
    // 80016DEC: lwz     r0, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016DF0:
    // 80016DF0: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_80016DF4:
    // 80016DF4: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_80016DF8:
    // 80016DF8: cmpw    r27, r0
    {
        s32 val_a = (s32)(ctx->gpr[27]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016DFC:
    // 80016DFC: bc    12, 0, 0x80016CD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016CD4u;
                return;
            }
            goto label_80016CD4;
        }
    }

label_80016E00:
    ctx->pc = 0x80016E00u;
    ctx->downcount -= 2;
    // 80016E00: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016E04:
    // 80016E04: bl      0x801B61F4
    {
            ctx->lr = 0x80016E08u;
            ctx->pc = 0x801B61F4u;
            return;
    }

label_80016E08:
    ctx->pc = 0x80016E08u;
    ctx->downcount -= 1;
    // 80016E08: stw     r3, 76(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80016E0C:
    ctx->pc = 0x80016E0Cu;
    ctx->downcount -= 4;
    // 80016E0C: stw     r26, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80016E10:
    ctx->pc = 0x80016E10u;
    // 80016E10: stw     r29, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80016E14:
    ctx->pc = 0x80016E14u;
    // 80016E14: stw     r24, 84(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_80016E18:
    ctx->pc = 0x80016E18u;
    // 80016E18: stw     r20, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[20]);
    }

label_80016E1C:
    ctx->downcount -= 3;
    // 80016E1C: or   r30, r25, r25
    {
        ctx->gpr[30] = ctx->gpr[25] | ctx->gpr[25];
    }

label_80016E20:
    // 80016E20: cmpwi   r30, 23
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(23);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016E24:
    // 80016E24: bc    4, 1, 0x80016B5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016B5Cu;
                return;
            }
            goto label_80016B5C;
        }
    }

label_80016E28:
    ctx->pc = 0x80016E28u;
    ctx->downcount -= 1;
    // 80016E28: bl      0x801B5310
    {
            ctx->lr = 0x80016E2Cu;
            ctx->pc = 0x801B5310u;
            return;
    }

label_80016E2C:
    ctx->pc = 0x80016E2Cu;
    ctx->downcount -= 19;
    // 80016E2C: lwz     r0, 252(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(252);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016E30:
    ctx->pc = 0x80016E30u;
    // 80016E30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016E34:
    ctx->pc = 0x80016E34u;
    // 80016E34: lmw     r18, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        for (u32 r = 18; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80016E38:
    ctx->pc = 0x80016E38u;
    // 80016E38: lfd     f29, 224(r1)
    if (!ppc_fp_available(ctx, 0x80016E38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016E3C:
    ctx->pc = 0x80016E3Cu;
    // 80016E3C: lfd     f30, 232(r1)
    if (!ppc_fp_available(ctx, 0x80016E3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016E40:
    ctx->pc = 0x80016E40u;
    // 80016E40: lfd     f31, 240(r1)
    if (!ppc_fp_available(ctx, 0x80016E40u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_80016E44:
    ctx->pc = 0x80016E44u;
    // 80016E44: addi    r1, r1, 248
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(248);

label_80016E48:
    ctx->pc = 0x80016E48u;
    // 80016E48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016E4C:
    ctx->pc = 0x80016E4Cu;
    ctx->downcount -= 22;
    // 80016E4C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016E50:
    ctx->pc = 0x80016E50u;
    // 80016E50: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016E54:
    ctx->pc = 0x80016E54u;
    // 80016E54: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80016E58:
    ctx->pc = 0x80016E58u;
    // 80016E58: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016E5C:
    ctx->pc = 0x80016E5Cu;
    // 80016E5C: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016E60:
    ctx->pc = 0x80016E60u;
    // 80016E60: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80016E64:
    ctx->pc = 0x80016E64u;
    // 80016E64: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016E68:
    ctx->pc = 0x80016E68u;
    // 80016E68: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016E6C:
    ctx->pc = 0x80016E6Cu;
    // 80016E6C: lwzx    r31, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016E70:
    ctx->pc = 0x80016E70u;
    // 80016E70: or   r29, r5, r5
    {
        ctx->gpr[29] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80016E74:
    ctx->pc = 0x80016E74u;
    // 80016E74: cmpwi   r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016E78:
    ctx->pc = 0x80016E78u;
    // 80016E78: bc    4, 2, 0x80016E84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016E84;
        }
    }

label_80016E7C:
    ctx->pc = 0x80016E7Cu;
    ctx->downcount -= 2;
    // 80016E7C: li      r3, -8
    ctx->gpr[3] = (u32)(s32)(-8);

label_80016E80:
    ctx->pc = 0x80016E80u;
    // 80016E80: b       0x80016EB8
    {
            goto label_80016EB8;
    }

label_80016E84:
    ctx->pc = 0x80016E84u;
    ctx->downcount -= 3;
    // 80016E84: lwz     r0, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016E88:
    ctx->pc = 0x80016E88u;
    // 80016E88: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016E8C:
    ctx->pc = 0x80016E8Cu;
    // 80016E8C: bc    12, 2, 0x80016E98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016E98;
        }
    }

label_80016E90:
    ctx->pc = 0x80016E90u;
    ctx->downcount -= 2;
    // 80016E90: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80016E94:
    ctx->pc = 0x80016E94u;
    // 80016E94: bl      0x80016B08
    {
            ctx->lr = 0x80016E98u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016B08u;
                return;
            }
            goto label_80016B08;
    }

label_80016E98:
    ctx->pc = 0x80016E98u;
    ctx->downcount -= 7;
    // 80016E98: lwz     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016E9C:
    ctx->pc = 0x80016E9Cu;
    // 80016E9C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016EA0:
    ctx->pc = 0x80016EA0u;
    // 80016EA0: lwz     r9, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80016EA4:
    ctx->pc = 0x80016EA4u;
    // 80016EA4: stw     r9, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80016EA8:
    ctx->pc = 0x80016EA8u;
    // 80016EA8: lwz     r3, 84(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(84);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016EAC:
    ctx->pc = 0x80016EACu;
    // 80016EAC: cmpwi   r3, 0
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

label_80016EB0:
    ctx->pc = 0x80016EB0u;
    // 80016EB0: bc    4, 2, 0x80016EB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80016EB8;
        }
    }

label_80016EB4:
    ctx->pc = 0x80016EB4u;
    ctx->downcount -= 1;
    // 80016EB4: lwz     r3, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016EB8:
    ctx->pc = 0x80016EB8u;
    ctx->downcount -= 16;
    // 80016EB8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016EBC:
    ctx->pc = 0x80016EBCu;
    // 80016EBC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016EC0:
    ctx->pc = 0x80016EC0u;
    // 80016EC0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80016EC4:
    ctx->pc = 0x80016EC4u;
    // 80016EC4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80016EC8:
    ctx->pc = 0x80016EC8u;
    // 80016EC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016ECC:
    ctx->pc = 0x80016ECCu;
    ctx->downcount -= 11;
    // 80016ECC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016ED0:
    ctx->pc = 0x80016ED0u;
    // 80016ED0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016ED4:
    ctx->pc = 0x80016ED4u;
    // 80016ED4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016ED8:
    ctx->pc = 0x80016ED8u;
    // 80016ED8: li      r10, 24
    ctx->gpr[10] = (u32)(s32)(24);

label_80016EDC:
    ctx->pc = 0x80016EDCu;
    // 80016EDC: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80016EE0:
    ctx->pc = 0x80016EE0u;
    // 80016EE0: mtctr    r10
    ctx->ctr = ctx->gpr[10];

label_80016EE4:
    ctx->pc = 0x80016EE4u;
    // 80016EE4: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80016EE8:
    ctx->pc = 0x80016EE8u;
    // 80016EE8: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80016EEC:
    ctx->pc = 0x80016EECu;
    // 80016EEC: addi    r9, r9, 92
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(92);

label_80016EF0:
    ctx->pc = 0x80016EF0u;
    // 80016EF0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80016EF4:
    loop_80016EF4(ctx);
    if (ctx->pc == 0x80016F00u) goto label_80016F00;
    return;
label_80016EF8:
    // 80016EF8: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_80016EFC:
    // 80016EFC: bc    16, 0, 0x80016EF4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016EF4u;
                return;
            }
            goto label_80016EF4;
        }
    }

label_80016F00:
    ctx->pc = 0x80016F00u;
    ctx->downcount -= 4;
    // 80016F00: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016F04:
    ctx->pc = 0x80016F04u;
    // 80016F04: stw     r11, -32500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32500);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80016F08:
    ctx->pc = 0x80016F08u;
    // 80016F08: stw     r4, -32496(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32496);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80016F0C:
    ctx->pc = 0x80016F0Cu;
    // 80016F0C: bl      0x801B0DE8
    {
            ctx->lr = 0x80016F10u;
            ctx->pc = 0x801B0DE8u;
            return;
    }

label_80016F10:
    ctx->pc = 0x80016F10u;
    ctx->downcount -= 5;
    // 80016F10: lis     r3, -32767
    ctx->gpr[3] = ((u32)(s32)(-32767) << 16);

label_80016F14:
    ctx->pc = 0x80016F14u;
    // 80016F14: li      r4, 5
    ctx->gpr[4] = (u32)(s32)(5);

label_80016F18:
    ctx->pc = 0x80016F18u;
    // 80016F18: addi    r3, r3, 25888
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(25888);

label_80016F1C:
    ctx->pc = 0x80016F1Cu;
    // 80016F1C: li      r5, 100
    ctx->gpr[5] = (u32)(s32)(100);

label_80016F20:
    ctx->pc = 0x80016F20u;
    // 80016F20: bl      0x801A979C
    {
            ctx->lr = 0x80016F24u;
            ctx->pc = 0x801A979Cu;
            return;
    }

label_80016F24:
    ctx->pc = 0x80016F24u;
    ctx->downcount -= 16;
    // 80016F24: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80016F28:
    ctx->pc = 0x80016F28u;
    // 80016F28: lis     r11, -32741
    ctx->gpr[11] = ((u32)(s32)(-32741) << 16);

label_80016F2C:
    ctx->pc = 0x80016F2Cu;
    // 80016F2C: lis     r10, -32746
    ctx->gpr[10] = ((u32)(s32)(-32746) << 16);

label_80016F30:
    ctx->pc = 0x80016F30u;
    // 80016F30: addi    r9, r9, -19564
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-19564);

label_80016F34:
    ctx->pc = 0x80016F34u;
    // 80016F34: addi    r11, r11, -32608
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-32608);

label_80016F38:
    ctx->pc = 0x80016F38u;
    // 80016F38: addi    r10, r10, 28404
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(28404);

label_80016F3C:
    ctx->pc = 0x80016F3Cu;
    // 80016F3C: li      r0, 620
    ctx->gpr[0] = (u32)(s32)(620);

label_80016F40:
    ctx->pc = 0x80016F40u;
    // 80016F40: stw     r9, -26000(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26000);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80016F44:
    ctx->pc = 0x80016F44u;
    // 80016F44: stw     r0, -25996(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-25996);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016F48:
    ctx->pc = 0x80016F48u;
    // 80016F48: stw     r11, -32512(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32512);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80016F4C:
    ctx->pc = 0x80016F4Cu;
    // 80016F4C: stw     r10, -32508(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32508);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80016F50:
    ctx->pc = 0x80016F50u;
    // 80016F50: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016F54:
    ctx->pc = 0x80016F54u;
    // 80016F54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016F58:
    ctx->pc = 0x80016F58u;
    // 80016F58: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80016F5C:
    ctx->pc = 0x80016F5Cu;
    // 80016F5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016F60:
    ctx->pc = 0x80016F60u;
    ctx->downcount -= 6;
    // 80016F60: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016F64:
    ctx->pc = 0x80016F64u;
    // 80016F64: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016F68:
    ctx->pc = 0x80016F68u;
    // 80016F68: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016F6C:
    ctx->pc = 0x80016F6Cu;
    // 80016F6C: lwz     r0, -32500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32500);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016F70:
    ctx->pc = 0x80016F70u;
    // 80016F70: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80016F74:
    ctx->pc = 0x80016F74u;
    // 80016F74: bc    12, 2, 0x80016FA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80016FA8;
        }
    }

label_80016F78:
    ctx->pc = 0x80016F78u;
    ctx->downcount -= 4;
    // 80016F78: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80016F7C:
    ctx->pc = 0x80016F7Cu;
    // 80016F7C: addi    r3, r3, -19528
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19528);

label_80016F80:
    ctx->pc = 0x80016F80u;
    // 80016F80: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80016F84:
    ctx->pc = 0x80016F84u;
    // 80016F84: bl      0x801C0CA0
    {
            ctx->lr = 0x80016F88u;
            ctx->pc = 0x801C0CA0u;
            return;
    }

label_80016F88:
    ctx->pc = 0x80016F88u;
    ctx->downcount -= 2;
    // 80016F88: lwz     r3, -32496(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32496);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80016F8C:
    ctx->pc = 0x80016F8Cu;
    // 80016F8C: bl      0x801B0E20
    {
            ctx->lr = 0x80016F90u;
            ctx->pc = 0x801B0E20u;
            return;
    }

label_80016F90:
    ctx->pc = 0x80016F90u;
    ctx->downcount -= 3;
    // 80016F90: lis     r3, -32767
    ctx->gpr[3] = ((u32)(s32)(-32767) << 16);

label_80016F94:
    ctx->pc = 0x80016F94u;
    // 80016F94: addi    r3, r3, 25888
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(25888);

label_80016F98:
    ctx->pc = 0x80016F98u;
    // 80016F98: bl      0x801A9934
    {
            ctx->lr = 0x80016F9Cu;
            ctx->pc = 0x801A9934u;
            return;
    }

label_80016F9C:
    ctx->pc = 0x80016F9Cu;
    ctx->downcount -= 3;
    // 80016F9C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80016FA0:
    ctx->pc = 0x80016FA0u;
    // 80016FA0: stw     r0, -32496(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32496);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016FA4:
    ctx->pc = 0x80016FA4u;
    // 80016FA4: stw     r0, -32500(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32500);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016FA8:
    ctx->pc = 0x80016FA8u;
    ctx->downcount -= 5;
    // 80016FA8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80016FAC:
    ctx->pc = 0x80016FACu;
    // 80016FAC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80016FB0:
    ctx->pc = 0x80016FB0u;
    // 80016FB0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80016FB4:
    ctx->pc = 0x80016FB4u;
    // 80016FB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80016FB8:
    ctx->pc = 0x80016FB8u;
    ctx->downcount -= 26;
    // 80016FB8: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80016FBC:
    ctx->pc = 0x80016FBCu;
    // 80016FBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80016FC0:
    ctx->pc = 0x80016FC0u;
    // 80016FC0: stmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80016FC4:
    ctx->pc = 0x80016FC4u;
    // 80016FC4: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80016FC8:
    ctx->pc = 0x80016FC8u;
    // 80016FC8: lis     r11, -32703
    ctx->gpr[11] = ((u32)(s32)(-32703) << 16);

label_80016FCC:
    ctx->pc = 0x80016FCCu;
    // 80016FCC: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80016FD0:
    ctx->pc = 0x80016FD0u;
    // 80016FD0: addi    r11, r11, -27132
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-27132);

label_80016FD4:
    ctx->pc = 0x80016FD4u;
    // 80016FD4: or   r27, r4, r4
    {
        ctx->gpr[27] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80016FD8:
    ctx->pc = 0x80016FD8u;
    // 80016FD8: lwzx    r31, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80016FDC:
    ctx->pc = 0x80016FDCu;
    // 80016FDC: or   r26, r5, r5
    {
        ctx->gpr[26] = ctx->gpr[5] | ctx->gpr[5];
    }

label_80016FE0:
    ctx->pc = 0x80016FE0u;
    // 80016FE0: or   r28, r6, r6
    {
        ctx->gpr[28] = ctx->gpr[6] | ctx->gpr[6];
    }

label_80016FE4:
    ctx->pc = 0x80016FE4u;
    // 80016FE4: or   r25, r7, r7
    {
        ctx->gpr[25] = ctx->gpr[7] | ctx->gpr[7];
    }

label_80016FE8:
    ctx->pc = 0x80016FE8u;
    // 80016FE8: or   r30, r9, r9
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[9];
    }

label_80016FEC:
    ctx->pc = 0x80016FECu;
    // 80016FEC: or   r29, r10, r10
    {
        ctx->gpr[29] = ctx->gpr[10] | ctx->gpr[10];
    }

label_80016FF0:
    ctx->pc = 0x80016FF0u;
    // 80016FF0: or.   r8, r8, r8
    {
        ctx->gpr[8] = ctx->gpr[8] | ctx->gpr[8];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80016FF4:
    ctx->pc = 0x80016FF4u;
    // 80016FF4: bc    12, 0, 0x80017004
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80017004;
        }
    }

label_80016FF8:
    ctx->pc = 0x80016FF8u;
    ctx->downcount -= 3;
    // 80016FF8: or   r4, r8, r8
    {
        ctx->gpr[4] = ctx->gpr[8] | ctx->gpr[8];
    }

label_80016FFC:
    ctx->pc = 0x80016FFCu;
    // 80016FFC: stb     r8, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_80017000:
    ctx->pc = 0x80017000u;
    // 80017000: bl      0x800171C8
    {
            ctx->lr = 0x80017004u;
            goto label_800171C8;
    }

label_80017004:
    ctx->pc = 0x80017004u;
    ctx->downcount -= 3;
    // 80017004: lbz     r0, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80017008:
    ctx->pc = 0x80017008u;
    // 80017008: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8001700C:
    ctx->pc = 0x8001700Cu;
    // 8001700C: bc    12, 2, 0x8001705C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001705C;
        }
    }

label_80017010:
    ctx->pc = 0x80017010u;
    ctx->downcount -= 2;
    // 80017010: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80017014:
    ctx->pc = 0x80017014u;
    // 80017014: bc    4, 0, 0x8001701C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8001701C;
        }
    }

label_80017018:
    ctx->pc = 0x80017018u;
    ctx->downcount -= 1;
    // 80017018: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8001701C:
    ctx->pc = 0x8001701Cu;
    ctx->downcount -= 4;
    // 8001701C: add   r9, r28, r30
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80017020:
    ctx->pc = 0x80017020u;
    // 80017020: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_80017024:
    ctx->pc = 0x80017024u;
    // 80017024: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80017028:
    ctx->pc = 0x80017028u;
    // 80017028: bl      0x801B52DC
    {
            ctx->lr = 0x8001702Cu;
            ctx->pc = 0x801B52DCu;
            return;
    }

label_8001702C:
    ctx->pc = 0x8001702Cu;
    ctx->downcount -= 4;
    // 8001702C: lwz     r4, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80017030:
    ctx->pc = 0x80017030u;
    // 80017030: addi    r5, r31, 28
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(28);

label_80017034:
    ctx->pc = 0x80017034u;
    // 80017034: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80017038:
    ctx->pc = 0x80017038u;
    // 80017038: bl      0x801B0B70
    {
            ctx->lr = 0x8001703Cu;
            ctx->pc = 0x801B0B70u;
            return;
    }

label_8001703C:
    ctx->pc = 0x8001703Cu;
    ctx->downcount -= 2;
    // 8001703C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80017040:
    ctx->pc = 0x80017040u;
    // 80017040: bl      0x801B5310
    {
            ctx->lr = 0x80017044u;
            ctx->pc = 0x801B5310u;
            return;
    }

label_80017044:
    ctx->pc = 0x80017044u;
    ctx->downcount -= 6;
    // 80017044: lwz     r11, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80017048:
    ctx->pc = 0x80017048u;
    // 80017048: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8001704C:
    ctx->pc = 0x8001704Cu;
    // 8001704C: stw     r30, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80017050:
    ctx->pc = 0x80017050u;
    // 80017050: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80017054:
    ctx->pc = 0x80017054u;
    // 80017054: stw     r25, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80017058:
    ctx->pc = 0x80017058u;
    // 80017058: b       0x80017118
    {
            goto label_80017118;
    }

label_8001705C:
    ctx->pc = 0x8001705Cu;
    ctx->downcount -= 3;
    // 8001705C: cmpwi   r29, 0
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

label_80017060:
    ctx->pc = 0x80017060u;
    // 80017060: rlwinm r30, r28, 2, 0, 29
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[28], 2u) & 0xFFFFFFFCu;
    }

label_80017064:
    ctx->pc = 0x80017064u;
    // 80017064: bc    12, 2, 0x800170A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800170A8;
        }
    }

label_80017068:
    ctx->pc = 0x80017068u;
    ctx->downcount -= 2;
    // 80017068: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001706C:
    ctx->pc = 0x8001706Cu;
    // 8001706C: bl      0x801B6050
    {
            ctx->lr = 0x80017070u;
            ctx->pc = 0x801B6050u;
            return;
    }

label_80017070:
    ctx->pc = 0x80017070u;
    ctx->downcount -= 3;
    // 80017070: lwz     r0, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80017074:
    ctx->pc = 0x80017074u;
    // 80017074: addic.  r6, r0, -1
    {
        u64 a = ctx->gpr[0];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80017078:
    ctx->pc = 0x80017078u;
    // 80017078: bc    4, 1, 0x800170A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800170A8;
        }
    }

label_8001707C:
    ctx->pc = 0x8001707Cu;
    ctx->downcount -= 4;
    // 8001707C: mulli   r10, r6, 12
    ctx->gpr[10] = (u32)((s64)(s32)ctx->gpr[6] * (s64)(s32)12);

label_80017080:
    ctx->pc = 0x80017080u;
    // 80017080: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80017084:
    loop_80017084(ctx);
    if (ctx->pc == 0x800170A8u) goto label_800170A8;
    return;
label_80017088:
    // 80017088: addic.  r6, r6, -1
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8001708C:
    // 8001708C: add   r11, r10, r11
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_80017090:
    ctx->pc = 0x80017090u;
    // 80017090: stw     r0, -8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80017094:
    ctx->pc = 0x80017094u;
    // 80017094: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80017098:
    // 80017098: add   r9, r10, r9
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8001709C:
    ctx->pc = 0x8001709Cu;
    // 8001709C: stw     r0, -12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800170A0:
    // 800170A0: addi    r10, r10, -12
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(-12);

label_800170A4:
    // 800170A4: bc    12, 1, 0x80017084
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80017084u;
                return;
            }
            goto label_80017084;
        }
    }

label_800170A8:
    ctx->pc = 0x800170A8u;
    ctx->downcount -= 5;
    // 800170A8: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800170AC:
    ctx->pc = 0x800170ACu;
    // 800170AC: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800170B0:
    ctx->pc = 0x800170B0u;
    // 800170B0: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800170B4:
    ctx->pc = 0x800170B4u;
    // 800170B4: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800170B8:
    ctx->pc = 0x800170B8u;
    // 800170B8: bl      0x801B602C
    {
            ctx->lr = 0x800170BCu;
            ctx->pc = 0x801B602Cu;
            return;
    }

label_800170BC:
    ctx->pc = 0x800170BCu;
    ctx->downcount -= 2;
    // 800170BC: or.   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800170C0:
    ctx->pc = 0x800170C0u;
    // 800170C0: bc    12, 0, 0x80017114
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80017114;
        }
    }

label_800170C4:
    ctx->pc = 0x800170C4u;
    ctx->downcount -= 3;
    // 800170C4: lwz     r0, 88(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800170C8:
    ctx->pc = 0x800170C8u;
    // 800170C8: addic.  r6, r0, -1
    {
        u64 a = ctx->gpr[0];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800170CC:
    ctx->pc = 0x800170CCu;
    // 800170CC: bc    4, 1, 0x80017104
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80017104;
        }
    }

label_800170D0:
    ctx->pc = 0x800170D0u;
    ctx->downcount -= 3;
    // 800170D0: mulli   r5, r6, 12
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[6] * (s64)(s32)12);

label_800170D4:
    loop_800170D4(ctx);
    if (ctx->pc == 0x80017104u) goto label_80017104;
    return;
label_800170D8:
    // 800170D8: addic.  r6, r6, -1
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[6] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800170DC:
    // 800170DC: add   r11, r5, r7
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800170E0:
    // 800170E0: addi    r9, r11, -12
    ctx->gpr[9] = ctx->gpr[11] + (u32)(s32)(-12);

label_800170E4:
    ctx->pc = 0x800170E4u;
    // 800170E4: lwz     r0, -12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800170E8:
    ctx->pc = 0x800170E8u;
    // 800170E8: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800170EC:
    ctx->pc = 0x800170ECu;
    // 800170EC: lwz     r8, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800170F0:
    ctx->pc = 0x800170F0u;
    // 800170F0: stwx    r0, r5, r7
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800170F4:
    ctx->pc = 0x800170F4u;
    // 800170F4: stw     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800170F8:
    // 800170F8: addi    r5, r5, -12
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-12);

label_800170FC:
    ctx->pc = 0x800170FCu;
    // 800170FC: stw     r8, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80017100:
    // 80017100: bc    12, 1, 0x800170D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800170D4u;
                return;
            }
            goto label_800170D4;
        }
    }

label_80017104:
    ctx->pc = 0x80017104u;
    ctx->downcount -= 4;
    // 80017104: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80017108:
    ctx->pc = 0x80017108u;
    // 80017108: stw     r30, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8001710C:
    ctx->pc = 0x8001710Cu;
    // 8001710C: lwz     r11, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80017110:
    ctx->pc = 0x80017110u;
    // 80017110: stw     r25, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80017114:
    ctx->pc = 0x80017114u;
    ctx->downcount -= 1;
    // 80017114: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80017118:
    ctx->pc = 0x80017118u;
    ctx->downcount -= 18;
    // 80017118: stw     r0, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8001711C:
    ctx->pc = 0x8001711Cu;
    // 8001711C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80017120:
    ctx->pc = 0x80017120u;
    // 80017120: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80017124:
    ctx->pc = 0x80017124u;
    // 80017124: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80017128:
    ctx->pc = 0x80017128u;
    // 80017128: lmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8001712C:
    ctx->pc = 0x8001712Cu;
    // 8001712C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_80017130:
    ctx->pc = 0x80017130u;
    // 80017130: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_80017134:
    ctx->pc = 0x80017134u;
    ctx->downcount -= 12;
    // 80017134: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80017138:
    ctx->pc = 0x80017138u;
    // 80017138: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8001713C:
    ctx->pc = 0x8001713Cu;
    // 8001713C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80017140:
    ctx->pc = 0x80017140u;
    // 80017140: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80017144:
    ctx->pc = 0x80017144u;
    // 80017144: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_80017148:
    ctx->pc = 0x80017148u;
    // 80017148: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_8001714C:
    ctx->pc = 0x8001714Cu;
    // 8001714C: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_80017150:
    ctx->pc = 0x80017150u;
    // 80017150: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80017154:
    ctx->pc = 0x80017154u;
    // 80017154: lwzx    r31, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80017158:
    ctx->pc = 0x80017158u;
    // 80017158: lbz     r0, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8001715C:
    ctx->pc = 0x8001715Cu;
    // 8001715C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80017160:
    ctx->pc = 0x80017160u;
    // 80017160: bc    4, 2, 0x80017174
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80017174;
        }
    }

label_80017164:
    ctx->pc = 0x80017164u;
    ctx->downcount -= 3;
    // 80017164: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80017168:
    ctx->pc = 0x80017168u;
    // 80017168: lwz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8001716C:
    ctx->pc = 0x8001716Cu;
    // 8001716C: bl      0x801B62B8
    {
            ctx->lr = 0x80017170u;
            ctx->pc = 0x801B62B8u;
            return;
    }

label_80017170:
    ctx->pc = 0x80017170u;
    ctx->downcount -= 1;
    // 80017170: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80017174:
    ctx->pc = 0x80017174u;
    ctx->downcount -= 2;
    // 80017174: cmpwi   r5, 0
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

label_80017178:
    ctx->pc = 0x80017178u;
    // 80017178: bc    4, 0, 0x80017190
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80017190;
        }
    }

label_8001717C:
    ctx->pc = 0x8001717Cu;
    ctx->downcount -= 5;
    // 8001717C: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80017180:
    ctx->pc = 0x80017180u;
    // 80017180: addi    r4, r31, 15
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(15);

label_80017184:
    ctx->pc = 0x80017184u;
    // 80017184: addi    r3, r3, -19504
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19504);

label_80017188:
    ctx->pc = 0x80017188u;
    // 80017188: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8001718C:
    ctx->pc = 0x8001718Cu;
    // 8001718C: bl      0x801C0CA0
    {
            ctx->lr = 0x80017190u;
            ctx->pc = 0x801C0CA0u;
            return;
    }

label_80017190:
    ctx->pc = 0x80017190u;
    ctx->downcount -= 6;
    // 80017190: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80017194:
    ctx->pc = 0x80017194u;
    // 80017194: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80017198:
    ctx->pc = 0x80017198u;
    // 80017198: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8001719C:
    ctx->pc = 0x8001719Cu;
    // 8001719C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800171A0:
    ctx->pc = 0x800171A0u;
    // 800171A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800171A4:
    ctx->pc = 0x800171A4u;
    ctx->downcount -= 5;
    // 800171A4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800171A8:
    ctx->pc = 0x800171A8u;
    // 800171A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800171AC:
    ctx->pc = 0x800171ACu;
    // 800171AC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800171B0:
    ctx->pc = 0x800171B0u;
    // 800171B0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800171B4:
    ctx->pc = 0x800171B4u;
    // 800171B4: bl      0x80016344
    {
            ctx->lr = 0x800171B8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016344u;
                return;
            }
            goto label_80016344;
    }

label_800171B8:
    ctx->pc = 0x800171B8u;
    ctx->downcount -= 5;
    // 800171B8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800171BC:
    ctx->pc = 0x800171BCu;
    // 800171BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800171C0:
    ctx->pc = 0x800171C0u;
    // 800171C0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800171C4:
    ctx->pc = 0x800171C4u;
    // 800171C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800171C8:
    ctx->pc = 0x800171C8u;
    ctx->downcount -= 23;
    // 800171C8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800171CC:
    ctx->pc = 0x800171CCu;
    // 800171CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800171D0:
    ctx->pc = 0x800171D0u;
    // 800171D0: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800171D4:
    ctx->pc = 0x800171D4u;
    // 800171D4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800171D8:
    ctx->pc = 0x800171D8u;
    // 800171D8: lis     r9, -32703
    ctx->gpr[9] = ((u32)(s32)(-32703) << 16);

label_800171DC:
    ctx->pc = 0x800171DCu;
    // 800171DC: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_800171E0:
    ctx->pc = 0x800171E0u;
    // 800171E0: addi    r9, r9, -27132
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27132);

label_800171E4:
    ctx->pc = 0x800171E4u;
    // 800171E4: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_800171E8:
    ctx->pc = 0x800171E8u;
    // 800171E8: lwzx    r31, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800171EC:
    ctx->pc = 0x800171ECu;
    // 800171EC: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_800171F0:
    ctx->pc = 0x800171F0u;
    // 800171F0: lwz     r0, 80(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(80);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800171F4:
    ctx->pc = 0x800171F4u;
    // 800171F4: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800171F8:
    ctx->pc = 0x800171F8u;
    // 800171F8: bc    12, 2, 0x80017204
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80017204;
        }
    }

label_800171FC:
    ctx->pc = 0x800171FCu;
    ctx->downcount -= 2;
    // 800171FC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80017200:
    ctx->pc = 0x80017200u;
    // 80017200: bl      0x80016B08
    {
            ctx->lr = 0x80017204u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80016B08u;
                return;
            }
            goto label_80016B08;
    }

label_80017204:
    ctx->pc = 0x80017204u;
    ctx->downcount -= 4;
    // 80017204: lwz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80017208:
    ctx->pc = 0x80017208u;
    // 80017208: lwz     r29, 76(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(76);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8001720C:
    ctx->pc = 0x8001720Cu;
    // 8001720C: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80017210:
    ctx->pc = 0x80017210u;
    // 80017210: bc    12, 0, 0x8001721C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8001721C;
        }
    }

label_80017214:
    ctx->pc = 0x80017214u;
    ctx->downcount -= 2;
    // 80017214: cmpw    r0, r29
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80017218:
    ctx->pc = 0x80017218u;
    // 80017218: bc    4, 2, 0x80017294
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80017294;
        }
    }

label_8001721C:
    ctx->pc = 0x8001721Cu;
    ctx->downcount -= 4;
    // 8001721C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80017220:
    ctx->pc = 0x80017220u;
    // 80017220: cmpw    r29, r30
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(ctx->gpr[30]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80017224:
    ctx->pc = 0x80017224u;
    // 80017224: stw     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80017228:
    ctx->pc = 0x80017228u;
    // 80017228: bc    12, 2, 0x80017298
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80017298;
        }
    }

label_8001722C:
    ctx->pc = 0x8001722Cu;
    ctx->downcount -= 2;
    // 8001722C: cmpwi   r30, 0
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80017230:
    ctx->pc = 0x80017230u;
    // 80017230: bc    12, 0, 0x80017298
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80017298;
        }
    }

label_80017234:
    ctx->pc = 0x80017234u;
    ctx->downcount -= 2;
    // 80017234: cmpwi   r29, 0
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

label_80017238:
    ctx->pc = 0x80017238u;
    // 80017238: bc    12, 0, 0x80017298
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80017298;
        }
    }

label_8001723C:
    ctx->pc = 0x8001723Cu;
    ctx->downcount -= 1;
    // 8001723C: bl      0x801B52DC
    {
            ctx->lr = 0x80017240u;
            ctx->pc = 0x801B52DCu;
            return;
    }

label_80017240:
    ctx->pc = 0x80017240u;
    ctx->downcount -= 3;
    // 80017240: lbz     r0, 14(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80017244:
    ctx->pc = 0x80017244u;
    // 80017244: cmpwi   r0, 0
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80017248:
    ctx->pc = 0x80017248u;
    // 80017248: bc    12, 2, 0x80017260
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80017260;
        }
    }

label_8001724C:
    ctx->pc = 0x8001724Cu;
    ctx->downcount -= 4;
    // 8001724C: lwz     r9, 92(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80017250:
    ctx->pc = 0x80017250u;
    // 80017250: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80017254:
    ctx->pc = 0x80017254u;
    // 80017254: lwz     r3, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80017258:
    ctx->pc = 0x80017258u;
    // 80017258: bl      0x801B7B64
    {
            ctx->lr = 0x8001725Cu;
            ctx->pc = 0x801B7B64u;
            return;
    }

label_8001725C:
    ctx->pc = 0x8001725Cu;
    ctx->downcount -= 1;
    // 8001725C: b       0x8001726C
    {
            goto label_8001726C;
    }

label_80017260:
    ctx->pc = 0x80017260u;
    ctx->downcount -= 3;
    // 80017260: lwz     r3, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80017264:
    ctx->pc = 0x80017264u;
    // 80017264: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80017268:
    ctx->pc = 0x80017268u;
    // 80017268: bl      0x801B66E0
    {
            ctx->lr = 0x8001726Cu;
            ctx->pc = 0x801B66E0u;
            return;
    }

label_8001726C:
    ctx->pc = 0x8001726Cu;
    ctx->downcount -= 1;
    // 8001726C: bl      0x801B5310
    {
            ctx->lr = 0x80017270u;
            ctx->pc = 0x801B5310u;
            return;
    }

label_80017270:
    ctx->pc = 0x80017270u;
    ctx->downcount -= 8;
    // 80017270: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80017274:
    ctx->pc = 0x80017274u;
    // 80017274: stw     r30, 76(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80017278:
    ctx->pc = 0x80017278u;
    // 80017278: addi    r3, r3, -19468
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-19468);

label_8001727C:
    ctx->pc = 0x8001727Cu;
    // 8001727C: addi    r4, r31, 15
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(15);

label_80017280:
    ctx->pc = 0x80017280u;
    // 80017280: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80017284:
    ctx->pc = 0x80017284u;
    // 80017284: or   r6, r30, r30
    {
        ctx->gpr[6] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80017288:
    ctx->pc = 0x80017288u;
    // 80017288: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8001728C:
    ctx->pc = 0x8001728Cu;
    // 8001728C: bl      0x801C0CF0
    {
            ctx->lr = 0x80017290u;
            ctx->pc = 0x801C0CF0u;
            return;
    }

label_80017290:
    ctx->pc = 0x80017290u;
    ctx->downcount -= 1;
    // 80017290: b       0x80017298
    {
            goto label_80017298;
    }

label_80017294:
    ctx->pc = 0x80017294u;
    ctx->downcount -= 1;
    // 80017294: li      r28, -8
    ctx->gpr[28] = (u32)(s32)(-8);

label_80017298:
    ctx->pc = 0x80017298u;
    ctx->downcount -= 17;
    // 80017298: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8001729C:
    ctx->pc = 0x8001729Cu;
    // 8001729C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800172A0:
    ctx->pc = 0x800172A0u;
    // 800172A0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800172A4:
    ctx->pc = 0x800172A4u;
    // 800172A4: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800172A8:
    ctx->pc = 0x800172A8u;
    // 800172A8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800172AC:
    ctx->pc = 0x800172ACu;
    // 800172AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800132C0;
        }
    }

label_800172B0:
    ctx->pc = 0x800172B0u;
    ctx->downcount -= 14;
    // 800172B0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800172B4:
    ctx->pc = 0x800172B4u;
    // 800172B4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800172B8:
    ctx->pc = 0x800172B8u;
    // 800172B8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800172BC:
    ctx->pc = 0x800172BCu;
    // 800172BC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x800172C0u;
    return;
return_dispatch_800132C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x800132D4u: goto label_800132D4;
    case 0x800132DCu: goto label_800132DC;
    case 0x800132E4u: goto label_800132E4;
    case 0x800132ECu: goto label_800132EC;
    case 0x800132F4u: goto label_800132F4;
    case 0x800132FCu: goto label_800132FC;
    case 0x80013304u: goto label_80013304;
    case 0x8001330Cu: goto label_8001330C;
    case 0x80013364u: goto label_80013364;
    case 0x800133A8u: goto label_800133A8;
    case 0x800133ECu: goto label_800133EC;
    case 0x80013430u: goto label_80013430;
    case 0x80013468u: goto label_80013468;
    case 0x80013498u: goto label_80013498;
    case 0x800134C8u: goto label_800134C8;
    case 0x800134F8u: goto label_800134F8;
    case 0x8001350Cu: goto label_8001350C;
    case 0x80013520u: goto label_80013520;
    case 0x80013534u: goto label_80013534;
    case 0x80013548u: goto label_80013548;
    case 0x80013590u: goto label_80013590;
    case 0x800135B4u: goto label_800135B4;
    case 0x800135D8u: goto label_800135D8;
    case 0x800135FCu: goto label_800135FC;
    case 0x800137FCu: goto label_800137FC;
    case 0x80013844u: goto label_80013844;
    case 0x80013848u: goto label_80013848;
    case 0x80013888u: goto label_80013888;
    case 0x8001391Cu: goto label_8001391C;
    case 0x80013934u: goto label_80013934;
    case 0x8001394Cu: goto label_8001394C;
    case 0x80013964u: goto label_80013964;
    case 0x8001397Cu: goto label_8001397C;
    case 0x80013994u: goto label_80013994;
    case 0x800139ACu: goto label_800139AC;
    case 0x800139C4u: goto label_800139C4;
    case 0x800139DCu: goto label_800139DC;
    case 0x800139F4u: goto label_800139F4;
    case 0x80013A0Cu: goto label_80013A0C;
    case 0x80013A24u: goto label_80013A24;
    case 0x80013A3Cu: goto label_80013A3C;
    case 0x80013A54u: goto label_80013A54;
    case 0x80013A6Cu: goto label_80013A6C;
    case 0x80013A84u: goto label_80013A84;
    case 0x80013A9Cu: goto label_80013A9C;
    case 0x80013AB4u: goto label_80013AB4;
    case 0x80013AB8u: goto label_80013AB8;
    case 0x80013AC4u: goto label_80013AC4;
    case 0x80013AD0u: goto label_80013AD0;
    case 0x80013B14u: goto label_80013B14;
    case 0x80013B30u: goto label_80013B30;
    case 0x80013B50u: goto label_80013B50;
    case 0x80013B6Cu: goto label_80013B6C;
    case 0x80013B84u: goto label_80013B84;
    case 0x80013BA4u: goto label_80013BA4;
    case 0x80013BBCu: goto label_80013BBC;
    case 0x80013BD8u: goto label_80013BD8;
    case 0x80013BF0u: goto label_80013BF0;
    case 0x80013C5Cu: goto label_80013C5C;
    case 0x80013C68u: goto label_80013C68;
    case 0x80013D2Cu: goto label_80013D2C;
    case 0x80013D60u: goto label_80013D60;
    case 0x80013DB4u: goto label_80013DB4;
    case 0x80013E18u: goto label_80013E18;
    case 0x80013E28u: goto label_80013E28;
    case 0x80013E54u: goto label_80013E54;
    case 0x80013E68u: goto label_80013E68;
    case 0x80013E70u: goto label_80013E70;
    case 0x80013E90u: goto label_80013E90;
    case 0x80013EACu: goto label_80013EAC;
    case 0x80013EB4u: goto label_80013EB4;
    case 0x80013EBCu: goto label_80013EBC;
    case 0x80013ED8u: goto label_80013ED8;
    case 0x80013EE0u: goto label_80013EE0;
    case 0x80013F44u: goto label_80013F44;
    case 0x80013F58u: goto label_80013F58;
    case 0x80013F64u: goto label_80013F64;
    case 0x80013F74u: goto label_80013F74;
    case 0x80013FC4u: goto label_80013FC4;
    case 0x80013FD8u: goto label_80013FD8;
    case 0x8001401Cu: goto label_8001401C;
    case 0x8001404Cu: goto label_8001404C;
    case 0x80014068u: goto label_80014068;
    case 0x800140D8u: goto label_800140D8;
    case 0x800140E8u: goto label_800140E8;
    case 0x80014114u: goto label_80014114;
    case 0x80014184u: goto label_80014184;
    case 0x80014190u: goto label_80014190;
    case 0x800141A0u: goto label_800141A0;
    case 0x800141B4u: goto label_800141B4;
    case 0x800141C4u: goto label_800141C4;
    case 0x800141D8u: goto label_800141D8;
    case 0x800141E0u: goto label_800141E0;
    case 0x8001420Cu: goto label_8001420C;
    case 0x80014220u: goto label_80014220;
    case 0x80014238u: goto label_80014238;
    case 0x80014264u: goto label_80014264;
    case 0x8001426Cu: goto label_8001426C;
    case 0x800142BCu: goto label_800142BC;
    case 0x80014388u: goto label_80014388;
    case 0x800143A0u: goto label_800143A0;
    case 0x800143B0u: goto label_800143B0;
    case 0x800143D8u: goto label_800143D8;
    case 0x800143E4u: goto label_800143E4;
    case 0x8001444Cu: goto label_8001444C;
    case 0x80014480u: goto label_80014480;
    case 0x80014490u: goto label_80014490;
    case 0x800144C0u: goto label_800144C0;
    case 0x800144F0u: goto label_800144F0;
    case 0x80014508u: goto label_80014508;
    case 0x8001451Cu: goto label_8001451C;
    case 0x80014534u: goto label_80014534;
    case 0x80014544u: goto label_80014544;
    case 0x8001454Cu: goto label_8001454C;
    case 0x800145B8u: goto label_800145B8;
    case 0x80014604u: goto label_80014604;
    case 0x8001466Cu: goto label_8001466C;
    case 0x800146A4u: goto label_800146A4;
    case 0x800146C0u: goto label_800146C0;
    case 0x80014728u: goto label_80014728;
    case 0x80014764u: goto label_80014764;
    case 0x80014778u: goto label_80014778;
    case 0x800147B8u: goto label_800147B8;
    case 0x800147C0u: goto label_800147C0;
    case 0x8001481Cu: goto label_8001481C;
    case 0x80014848u: goto label_80014848;
    case 0x80014858u: goto label_80014858;
    case 0x80014884u: goto label_80014884;
    case 0x80014890u: goto label_80014890;
    case 0x800148BCu: goto label_800148BC;
    case 0x800148F8u: goto label_800148F8;
    case 0x8001492Cu: goto label_8001492C;
    case 0x80014938u: goto label_80014938;
    case 0x8001494Cu: goto label_8001494C;
    case 0x80014980u: goto label_80014980;
    case 0x8001498Cu: goto label_8001498C;
    case 0x80014A08u: goto label_80014A08;
    case 0x80014A30u: goto label_80014A30;
    case 0x80014A44u: goto label_80014A44;
    case 0x80014A68u: goto label_80014A68;
    case 0x80014ABCu: goto label_80014ABC;
    case 0x80014AD8u: goto label_80014AD8;
    case 0x80014AE8u: goto label_80014AE8;
    case 0x80014B00u: goto label_80014B00;
    case 0x80014B20u: goto label_80014B20;
    case 0x80014B34u: goto label_80014B34;
    case 0x80014B90u: goto label_80014B90;
    case 0x80014BB4u: goto label_80014BB4;
    case 0x80014BC4u: goto label_80014BC4;
    case 0x80014BE0u: goto label_80014BE0;
    case 0x80014C0Cu: goto label_80014C0C;
    case 0x80014C2Cu: goto label_80014C2C;
    case 0x80014C40u: goto label_80014C40;
    case 0x80014C5Cu: goto label_80014C5C;
    case 0x80014C90u: goto label_80014C90;
    case 0x80014CB0u: goto label_80014CB0;
    case 0x80014CD0u: goto label_80014CD0;
    case 0x80014CF0u: goto label_80014CF0;
    case 0x80014D38u: goto label_80014D38;
    case 0x80014D50u: goto label_80014D50;
    case 0x80014D68u: goto label_80014D68;
    case 0x80014DC0u: goto label_80014DC0;
    case 0x80014DF8u: goto label_80014DF8;
    case 0x80014E18u: goto label_80014E18;
    case 0x80014E70u: goto label_80014E70;
    case 0x80014E80u: goto label_80014E80;
    case 0x80014E88u: goto label_80014E88;
    case 0x80014EA4u: goto label_80014EA4;
    case 0x80014F28u: goto label_80014F28;
    case 0x80014F34u: goto label_80014F34;
    case 0x80014F3Cu: goto label_80014F3C;
    case 0x80014F48u: goto label_80014F48;
    case 0x80014F50u: goto label_80014F50;
    case 0x80014F8Cu: goto label_80014F8C;
    case 0x80014F9Cu: goto label_80014F9C;
    case 0x80014FA4u: goto label_80014FA4;
    case 0x80014FACu: goto label_80014FAC;
    case 0x80014FB8u: goto label_80014FB8;
    case 0x80014FCCu: goto label_80014FCC;
    case 0x80014FDCu: goto label_80014FDC;
    case 0x80014FE4u: goto label_80014FE4;
    case 0x80015024u: goto label_80015024;
    case 0x80015034u: goto label_80015034;
    case 0x80015044u: goto label_80015044;
    case 0x8001505Cu: goto label_8001505C;
    case 0x80015074u: goto label_80015074;
    case 0x800150B0u: goto label_800150B0;
    case 0x8001525Cu: goto label_8001525C;
    case 0x80015270u: goto label_80015270;
    case 0x80015294u: goto label_80015294;
    case 0x800152D4u: goto label_800152D4;
    case 0x80015300u: goto label_80015300;
    case 0x80015308u: goto label_80015308;
    case 0x8001532Cu: goto label_8001532C;
    case 0x80015440u: goto label_80015440;
    case 0x80015500u: goto label_80015500;
    case 0x8001552Cu: goto label_8001552C;
    case 0x80015538u: goto label_80015538;
    case 0x800155A0u: goto label_800155A0;
    case 0x800155B0u: goto label_800155B0;
    case 0x800155B8u: goto label_800155B8;
    case 0x800155D4u: goto label_800155D4;
    case 0x80015614u: goto label_80015614;
    case 0x80015624u: goto label_80015624;
    case 0x80015630u: goto label_80015630;
    case 0x80015648u: goto label_80015648;
    case 0x80015660u: goto label_80015660;
    case 0x800156D0u: goto label_800156D0;
    case 0x800156E0u: goto label_800156E0;
    case 0x800156F8u: goto label_800156F8;
    case 0x80015780u: goto label_80015780;
    case 0x80015790u: goto label_80015790;
    case 0x8001579Cu: goto label_8001579C;
    case 0x800157B4u: goto label_800157B4;
    case 0x800157CCu: goto label_800157CC;
    case 0x80015840u: goto label_80015840;
    case 0x80015894u: goto label_80015894;
    case 0x800158ACu: goto label_800158AC;
    case 0x800159A0u: goto label_800159A0;
    case 0x800159B4u: goto label_800159B4;
    case 0x800159BCu: goto label_800159BC;
    case 0x800159ECu: goto label_800159EC;
    case 0x80015A24u: goto label_80015A24;
    case 0x80015A38u: goto label_80015A38;
    case 0x80015A54u: goto label_80015A54;
    case 0x80015AD0u: goto label_80015AD0;
    case 0x80015AECu: goto label_80015AEC;
    case 0x80015AF4u: goto label_80015AF4;
    case 0x80015B50u: goto label_80015B50;
    case 0x80015C3Cu: goto label_80015C3C;
    case 0x80015C48u: goto label_80015C48;
    case 0x80015C50u: goto label_80015C50;
    case 0x80015C60u: goto label_80015C60;
    case 0x80015C68u: goto label_80015C68;
    case 0x80015C70u: goto label_80015C70;
    case 0x80015C7Cu: goto label_80015C7C;
    case 0x80015C90u: goto label_80015C90;
    case 0x80015CA8u: goto label_80015CA8;
    case 0x80015CB0u: goto label_80015CB0;
    case 0x80015CC0u: goto label_80015CC0;
    case 0x80015CE4u: goto label_80015CE4;
    case 0x80015CECu: goto label_80015CEC;
    case 0x80015D0Cu: goto label_80015D0C;
    case 0x80015D14u: goto label_80015D14;
    case 0x80015D54u: goto label_80015D54;
    case 0x80015D60u: goto label_80015D60;
    case 0x80015D6Cu: goto label_80015D6C;
    case 0x80015D84u: goto label_80015D84;
    case 0x80015D8Cu: goto label_80015D8C;
    case 0x80015DA0u: goto label_80015DA0;
    case 0x80015DB4u: goto label_80015DB4;
    case 0x80015DC8u: goto label_80015DC8;
    case 0x80015DDCu: goto label_80015DDC;
    case 0x80015E04u: goto label_80015E04;
    case 0x80015E0Cu: goto label_80015E0C;
    case 0x80015E60u: goto label_80015E60;
    case 0x80015E70u: goto label_80015E70;
    case 0x80015E78u: goto label_80015E78;
    case 0x80015E80u: goto label_80015E80;
    case 0x80015E8Cu: goto label_80015E8C;
    case 0x80015EA0u: goto label_80015EA0;
    case 0x80015EB8u: goto label_80015EB8;
    case 0x80015EBCu: goto label_80015EBC;
    case 0x80015EC4u: goto label_80015EC4;
    case 0x80015ED0u: goto label_80015ED0;
    case 0x80015EF0u: goto label_80015EF0;
    case 0x80015EF8u: goto label_80015EF8;
    case 0x80015F18u: goto label_80015F18;
    case 0x80015F20u: goto label_80015F20;
    case 0x80015F28u: goto label_80015F28;
    case 0x80015F34u: goto label_80015F34;
    case 0x80015F48u: goto label_80015F48;
    case 0x80015F64u: goto label_80015F64;
    case 0x80015F8Cu: goto label_80015F8C;
    case 0x80015FA4u: goto label_80015FA4;
    case 0x80015FBCu: goto label_80015FBC;
    case 0x80015FD4u: goto label_80015FD4;
    case 0x80015FECu: goto label_80015FEC;
    case 0x80016020u: goto label_80016020;
    case 0x80016094u: goto label_80016094;
    case 0x800160ACu: goto label_800160AC;
    case 0x800160D8u: goto label_800160D8;
    case 0x800160F8u: goto label_800160F8;
    case 0x80016158u: goto label_80016158;
    case 0x8001616Cu: goto label_8001616C;
    case 0x800161BCu: goto label_800161BC;
    case 0x800161C0u: goto label_800161C0;
    case 0x800161C8u: goto label_800161C8;
    case 0x800161DCu: goto label_800161DC;
    case 0x80016208u: goto label_80016208;
    case 0x80016228u: goto label_80016228;
    case 0x80016240u: goto label_80016240;
    case 0x80016254u: goto label_80016254;
    case 0x80016278u: goto label_80016278;
    case 0x8001627Cu: goto label_8001627C;
    case 0x8001637Cu: goto label_8001637C;
    case 0x800163B4u: goto label_800163B4;
    case 0x800163C8u: goto label_800163C8;
    case 0x800163D0u: goto label_800163D0;
    case 0x800163F0u: goto label_800163F0;
    case 0x80016448u: goto label_80016448;
    case 0x80016464u: goto label_80016464;
    case 0x80016474u: goto label_80016474;
    case 0x80016488u: goto label_80016488;
    case 0x8001649Cu: goto label_8001649C;
    case 0x800164A4u: goto label_800164A4;
    case 0x800164D8u: goto label_800164D8;
    case 0x800164F0u: goto label_800164F0;
    case 0x80016500u: goto label_80016500;
    case 0x80016540u: goto label_80016540;
    case 0x80016564u: goto label_80016564;
    case 0x80016600u: goto label_80016600;
    case 0x80016674u: goto label_80016674;
    case 0x800166A0u: goto label_800166A0;
    case 0x80016754u: goto label_80016754;
    case 0x8001676Cu: goto label_8001676C;
    case 0x80016788u: goto label_80016788;
    case 0x800167A4u: goto label_800167A4;
    case 0x8001680Cu: goto label_8001680C;
    case 0x8001681Cu: goto label_8001681C;
    case 0x80016828u: goto label_80016828;
    case 0x80016830u: goto label_80016830;
    case 0x800168ECu: goto label_800168EC;
    case 0x80016954u: goto label_80016954;
    case 0x800169BCu: goto label_800169BC;
    case 0x80016A24u: goto label_80016A24;
    case 0x80016AB4u: goto label_80016AB4;
    case 0x80016B30u: goto label_80016B30;
    case 0x80016BDCu: goto label_80016BDC;
    case 0x80016BF0u: goto label_80016BF0;
    case 0x80016C84u: goto label_80016C84;
    case 0x80016CA0u: goto label_80016CA0;
    case 0x80016CFCu: goto label_80016CFC;
    case 0x80016E08u: goto label_80016E08;
    case 0x80016E2Cu: goto label_80016E2C;
    case 0x80016E98u: goto label_80016E98;
    case 0x80016F10u: goto label_80016F10;
    case 0x80016F24u: goto label_80016F24;
    case 0x80016F88u: goto label_80016F88;
    case 0x80016F90u: goto label_80016F90;
    case 0x80016F9Cu: goto label_80016F9C;
    case 0x80017004u: goto label_80017004;
    case 0x8001702Cu: goto label_8001702C;
    case 0x8001703Cu: goto label_8001703C;
    case 0x80017044u: goto label_80017044;
    case 0x80017070u: goto label_80017070;
    case 0x800170BCu: goto label_800170BC;
    case 0x80017170u: goto label_80017170;
    case 0x80017190u: goto label_80017190;
    case 0x800171B8u: goto label_800171B8;
    case 0x80017204u: goto label_80017204;
    case 0x80017240u: goto label_80017240;
    case 0x8001725Cu: goto label_8001725C;
    case 0x8001726Cu: goto label_8001726C;
    case 0x80017270u: goto label_80017270;
    case 0x80017290u: goto label_80017290;
    default: return;
    }
}

