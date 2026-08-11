// DolRecomp output
#include "../generated.h"

static void loop_8005B5FC(CPUState* ctx) {
label_8005B5FC:
    ctx->downcount -= 3;
    ctx->pc = 0x8005B5FCu;
    // 8005B5FC: stw     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 8005B600: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

    // 8005B604: bc    16, 0, 0x8005B5FC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B5FCu;
                return;
            }
            goto label_8005B5FC;
        }
    }

    ctx->pc = 0x8005B608u;
}

static void loop_8005B9B4(CPUState* ctx) {
label_8005B9B4:
    ctx->downcount -= 9;
    ctx->pc = 0x8005B9B4u;
    // 8005B9B4: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8005B9B8u;
    // 8005B9B8: lwz     r9, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8005B9BCu;
    // 8005B9BC: lwz     r11, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8005B9C0u;
    // 8005B9C0: stw     r0, -12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8005B9C4: addi    r8, r8, 12
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(12);

    ctx->pc = 0x8005B9C8u;
    // 8005B9C8: stw     r9, -4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

    ctx->pc = 0x8005B9CCu;
    // 8005B9CC: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

    // 8005B9D0: addi    r10, r10, 16
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(16);

    // 8005B9D4: bc    16, 0, 0x8005B9B4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B9B4u;
                return;
            }
            goto label_8005B9B4;
        }
    }

    ctx->pc = 0x8005B9D8u;
}

static void loop_8005CBE0(CPUState* ctx) {
label_8005CBE0:
    ctx->downcount -= 2;
    // 8005CBE0: addi    r9, r9, 12
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12);

    // 8005CBE4: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

    ctx->pc = 0x8005CBE8u;
    // 8005CBE8: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8005CBEC: cmpwi   r0, 0
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

    // 8005CBF0: bc    4, 2, 0x8005CBE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005CBE0u;
                return;
            }
            goto label_8005CBE0;
        }
    }

    ctx->pc = 0x8005CBF4u;
}

static void loop_8005E1F0(CPUState* ctx) {
label_8005E1F0:
    ctx->downcount -= 16;
    ctx->pc = 0x8005E1F0u;
    // 8005E1F0: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8005E1F4: addic.  r11, r11, -24
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

    ctx->pc = 0x8005E1F8u;
    // 8005E1F8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8005E1FCu;
    // 8005E1FC: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8005E200u;
    // 8005E200: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8005E204u;
    // 8005E204: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8005E208u;
    // 8005E208: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8005E20Cu;
    // 8005E20C: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8005E210u;
    // 8005E210: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8005E214u;
    // 8005E214: lwz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x8005E218u;
    // 8005E218: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8005E21Cu;
    // 8005E21C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 8005E220: addi    r3, r3, 24
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(24);

    ctx->pc = 0x8005E224u;
    // 8005E224: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8005E228: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

    // 8005E22C: bc    4, 2, 0x8005E1F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005E1F0u;
                return;
            }
            goto label_8005E1F0;
        }
    }

    ctx->pc = 0x8005E230u;
}

static void loop_8005EBA8(CPUState* ctx) {
label_8005EBA8:
    ctx->downcount -= 4;
    ctx->pc = 0x8005EBA8u;
    // 8005EBA8: stw     r0, -40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x8005EBACu;
    // 8005EBAC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 8005EBB0: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

    // 8005EBB4: bc    16, 0, 0x8005EBA8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005EBA8u;
                return;
            }
            goto label_8005EBA8;
        }
    }

    ctx->pc = 0x8005EBB8u;
}

void func_8005B2C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8005B2C0u: goto label_8005B2C0;
    case 0x8005B2C4u: goto label_8005B2C4;
    case 0x8005B2C8u: goto label_8005B2C8;
    case 0x8005B2CCu: goto label_8005B2CC;
    case 0x8005B2D0u: goto label_8005B2D0;
    case 0x8005B2D4u: goto label_8005B2D4;
    case 0x8005B2D8u: goto label_8005B2D8;
    case 0x8005B2DCu: goto label_8005B2DC;
    case 0x8005B2E0u: goto label_8005B2E0;
    case 0x8005B2E4u: goto label_8005B2E4;
    case 0x8005B2E8u: goto label_8005B2E8;
    case 0x8005B2ECu: goto label_8005B2EC;
    case 0x8005B2F0u: goto label_8005B2F0;
    case 0x8005B2F4u: goto label_8005B2F4;
    case 0x8005B2F8u: goto label_8005B2F8;
    case 0x8005B2FCu: goto label_8005B2FC;
    case 0x8005B300u: goto label_8005B300;
    case 0x8005B304u: goto label_8005B304;
    case 0x8005B308u: goto label_8005B308;
    case 0x8005B30Cu: goto label_8005B30C;
    case 0x8005B310u: goto label_8005B310;
    case 0x8005B314u: goto label_8005B314;
    case 0x8005B318u: goto label_8005B318;
    case 0x8005B31Cu: goto label_8005B31C;
    case 0x8005B320u: goto label_8005B320;
    case 0x8005B324u: goto label_8005B324;
    case 0x8005B328u: goto label_8005B328;
    case 0x8005B32Cu: goto label_8005B32C;
    case 0x8005B330u: goto label_8005B330;
    case 0x8005B334u: goto label_8005B334;
    case 0x8005B338u: goto label_8005B338;
    case 0x8005B33Cu: goto label_8005B33C;
    case 0x8005B340u: goto label_8005B340;
    case 0x8005B344u: goto label_8005B344;
    case 0x8005B348u: goto label_8005B348;
    case 0x8005B34Cu: goto label_8005B34C;
    case 0x8005B350u: goto label_8005B350;
    case 0x8005B354u: goto label_8005B354;
    case 0x8005B358u: goto label_8005B358;
    case 0x8005B35Cu: goto label_8005B35C;
    case 0x8005B360u: goto label_8005B360;
    case 0x8005B364u: goto label_8005B364;
    case 0x8005B368u: goto label_8005B368;
    case 0x8005B36Cu: goto label_8005B36C;
    case 0x8005B370u: goto label_8005B370;
    case 0x8005B374u: goto label_8005B374;
    case 0x8005B378u: goto label_8005B378;
    case 0x8005B37Cu: goto label_8005B37C;
    case 0x8005B380u: goto label_8005B380;
    case 0x8005B384u: goto label_8005B384;
    case 0x8005B388u: goto label_8005B388;
    case 0x8005B38Cu: goto label_8005B38C;
    case 0x8005B390u: goto label_8005B390;
    case 0x8005B394u: goto label_8005B394;
    case 0x8005B398u: goto label_8005B398;
    case 0x8005B39Cu: goto label_8005B39C;
    case 0x8005B3A0u: goto label_8005B3A0;
    case 0x8005B3A4u: goto label_8005B3A4;
    case 0x8005B3A8u: goto label_8005B3A8;
    case 0x8005B3ACu: goto label_8005B3AC;
    case 0x8005B3B0u: goto label_8005B3B0;
    case 0x8005B3B4u: goto label_8005B3B4;
    case 0x8005B3B8u: goto label_8005B3B8;
    case 0x8005B3BCu: goto label_8005B3BC;
    case 0x8005B3C0u: goto label_8005B3C0;
    case 0x8005B3C4u: goto label_8005B3C4;
    case 0x8005B3C8u: goto label_8005B3C8;
    case 0x8005B3CCu: goto label_8005B3CC;
    case 0x8005B3D0u: goto label_8005B3D0;
    case 0x8005B3D4u: goto label_8005B3D4;
    case 0x8005B3D8u: goto label_8005B3D8;
    case 0x8005B3DCu: goto label_8005B3DC;
    case 0x8005B3E0u: goto label_8005B3E0;
    case 0x8005B3E4u: goto label_8005B3E4;
    case 0x8005B3E8u: goto label_8005B3E8;
    case 0x8005B3ECu: goto label_8005B3EC;
    case 0x8005B3F0u: goto label_8005B3F0;
    case 0x8005B3F4u: goto label_8005B3F4;
    case 0x8005B3F8u: goto label_8005B3F8;
    case 0x8005B3FCu: goto label_8005B3FC;
    case 0x8005B400u: goto label_8005B400;
    case 0x8005B404u: goto label_8005B404;
    case 0x8005B408u: goto label_8005B408;
    case 0x8005B40Cu: goto label_8005B40C;
    case 0x8005B410u: goto label_8005B410;
    case 0x8005B414u: goto label_8005B414;
    case 0x8005B418u: goto label_8005B418;
    case 0x8005B41Cu: goto label_8005B41C;
    case 0x8005B420u: goto label_8005B420;
    case 0x8005B424u: goto label_8005B424;
    case 0x8005B428u: goto label_8005B428;
    case 0x8005B42Cu: goto label_8005B42C;
    case 0x8005B430u: goto label_8005B430;
    case 0x8005B434u: goto label_8005B434;
    case 0x8005B438u: goto label_8005B438;
    case 0x8005B43Cu: goto label_8005B43C;
    case 0x8005B440u: goto label_8005B440;
    case 0x8005B444u: goto label_8005B444;
    case 0x8005B448u: goto label_8005B448;
    case 0x8005B44Cu: goto label_8005B44C;
    case 0x8005B450u: goto label_8005B450;
    case 0x8005B454u: goto label_8005B454;
    case 0x8005B458u: goto label_8005B458;
    case 0x8005B45Cu: goto label_8005B45C;
    case 0x8005B460u: goto label_8005B460;
    case 0x8005B464u: goto label_8005B464;
    case 0x8005B468u: goto label_8005B468;
    case 0x8005B46Cu: goto label_8005B46C;
    case 0x8005B470u: goto label_8005B470;
    case 0x8005B474u: goto label_8005B474;
    case 0x8005B478u: goto label_8005B478;
    case 0x8005B47Cu: goto label_8005B47C;
    case 0x8005B480u: goto label_8005B480;
    case 0x8005B484u: goto label_8005B484;
    case 0x8005B488u: goto label_8005B488;
    case 0x8005B48Cu: goto label_8005B48C;
    case 0x8005B490u: goto label_8005B490;
    case 0x8005B494u: goto label_8005B494;
    case 0x8005B498u: goto label_8005B498;
    case 0x8005B49Cu: goto label_8005B49C;
    case 0x8005B4A0u: goto label_8005B4A0;
    case 0x8005B4A4u: goto label_8005B4A4;
    case 0x8005B4A8u: goto label_8005B4A8;
    case 0x8005B4ACu: goto label_8005B4AC;
    case 0x8005B4B0u: goto label_8005B4B0;
    case 0x8005B4B4u: goto label_8005B4B4;
    case 0x8005B4B8u: goto label_8005B4B8;
    case 0x8005B4BCu: goto label_8005B4BC;
    case 0x8005B4C0u: goto label_8005B4C0;
    case 0x8005B4C4u: goto label_8005B4C4;
    case 0x8005B4C8u: goto label_8005B4C8;
    case 0x8005B4CCu: goto label_8005B4CC;
    case 0x8005B4D0u: goto label_8005B4D0;
    case 0x8005B4D4u: goto label_8005B4D4;
    case 0x8005B4D8u: goto label_8005B4D8;
    case 0x8005B4DCu: goto label_8005B4DC;
    case 0x8005B4E0u: goto label_8005B4E0;
    case 0x8005B4E4u: goto label_8005B4E4;
    case 0x8005B4E8u: goto label_8005B4E8;
    case 0x8005B4ECu: goto label_8005B4EC;
    case 0x8005B4F0u: goto label_8005B4F0;
    case 0x8005B4F4u: goto label_8005B4F4;
    case 0x8005B4F8u: goto label_8005B4F8;
    case 0x8005B4FCu: goto label_8005B4FC;
    case 0x8005B500u: goto label_8005B500;
    case 0x8005B504u: goto label_8005B504;
    case 0x8005B508u: goto label_8005B508;
    case 0x8005B50Cu: goto label_8005B50C;
    case 0x8005B510u: goto label_8005B510;
    case 0x8005B514u: goto label_8005B514;
    case 0x8005B518u: goto label_8005B518;
    case 0x8005B51Cu: goto label_8005B51C;
    case 0x8005B520u: goto label_8005B520;
    case 0x8005B524u: goto label_8005B524;
    case 0x8005B528u: goto label_8005B528;
    case 0x8005B52Cu: goto label_8005B52C;
    case 0x8005B530u: goto label_8005B530;
    case 0x8005B534u: goto label_8005B534;
    case 0x8005B538u: goto label_8005B538;
    case 0x8005B53Cu: goto label_8005B53C;
    case 0x8005B540u: goto label_8005B540;
    case 0x8005B544u: goto label_8005B544;
    case 0x8005B548u: goto label_8005B548;
    case 0x8005B54Cu: goto label_8005B54C;
    case 0x8005B550u: goto label_8005B550;
    case 0x8005B554u: goto label_8005B554;
    case 0x8005B558u: goto label_8005B558;
    case 0x8005B55Cu: goto label_8005B55C;
    case 0x8005B560u: goto label_8005B560;
    case 0x8005B564u: goto label_8005B564;
    case 0x8005B568u: goto label_8005B568;
    case 0x8005B56Cu: goto label_8005B56C;
    case 0x8005B570u: goto label_8005B570;
    case 0x8005B574u: goto label_8005B574;
    case 0x8005B578u: goto label_8005B578;
    case 0x8005B57Cu: goto label_8005B57C;
    case 0x8005B580u: goto label_8005B580;
    case 0x8005B584u: goto label_8005B584;
    case 0x8005B588u: goto label_8005B588;
    case 0x8005B58Cu: goto label_8005B58C;
    case 0x8005B590u: goto label_8005B590;
    case 0x8005B594u: goto label_8005B594;
    case 0x8005B598u: goto label_8005B598;
    case 0x8005B59Cu: goto label_8005B59C;
    case 0x8005B5A0u: goto label_8005B5A0;
    case 0x8005B5A4u: goto label_8005B5A4;
    case 0x8005B5A8u: goto label_8005B5A8;
    case 0x8005B5ACu: goto label_8005B5AC;
    case 0x8005B5B0u: goto label_8005B5B0;
    case 0x8005B5B4u: goto label_8005B5B4;
    case 0x8005B5B8u: goto label_8005B5B8;
    case 0x8005B5BCu: goto label_8005B5BC;
    case 0x8005B5C0u: goto label_8005B5C0;
    case 0x8005B5C4u: goto label_8005B5C4;
    case 0x8005B5C8u: goto label_8005B5C8;
    case 0x8005B5CCu: goto label_8005B5CC;
    case 0x8005B5D0u: goto label_8005B5D0;
    case 0x8005B5D4u: goto label_8005B5D4;
    case 0x8005B5D8u: goto label_8005B5D8;
    case 0x8005B5DCu: goto label_8005B5DC;
    case 0x8005B5E0u: goto label_8005B5E0;
    case 0x8005B5E4u: goto label_8005B5E4;
    case 0x8005B5E8u: goto label_8005B5E8;
    case 0x8005B5ECu: goto label_8005B5EC;
    case 0x8005B5F0u: goto label_8005B5F0;
    case 0x8005B5F4u: goto label_8005B5F4;
    case 0x8005B5F8u: goto label_8005B5F8;
    case 0x8005B5FCu: goto label_8005B5FC;
    case 0x8005B600u: goto label_8005B600;
    case 0x8005B604u: goto label_8005B604;
    case 0x8005B608u: goto label_8005B608;
    case 0x8005B60Cu: goto label_8005B60C;
    case 0x8005B610u: goto label_8005B610;
    case 0x8005B614u: goto label_8005B614;
    case 0x8005B618u: goto label_8005B618;
    case 0x8005B61Cu: goto label_8005B61C;
    case 0x8005B620u: goto label_8005B620;
    case 0x8005B624u: goto label_8005B624;
    case 0x8005B628u: goto label_8005B628;
    case 0x8005B62Cu: goto label_8005B62C;
    case 0x8005B630u: goto label_8005B630;
    case 0x8005B634u: goto label_8005B634;
    case 0x8005B638u: goto label_8005B638;
    case 0x8005B63Cu: goto label_8005B63C;
    case 0x8005B640u: goto label_8005B640;
    case 0x8005B644u: goto label_8005B644;
    case 0x8005B648u: goto label_8005B648;
    case 0x8005B64Cu: goto label_8005B64C;
    case 0x8005B650u: goto label_8005B650;
    case 0x8005B654u: goto label_8005B654;
    case 0x8005B658u: goto label_8005B658;
    case 0x8005B65Cu: goto label_8005B65C;
    case 0x8005B660u: goto label_8005B660;
    case 0x8005B664u: goto label_8005B664;
    case 0x8005B668u: goto label_8005B668;
    case 0x8005B66Cu: goto label_8005B66C;
    case 0x8005B670u: goto label_8005B670;
    case 0x8005B674u: goto label_8005B674;
    case 0x8005B678u: goto label_8005B678;
    case 0x8005B67Cu: goto label_8005B67C;
    case 0x8005B680u: goto label_8005B680;
    case 0x8005B684u: goto label_8005B684;
    case 0x8005B688u: goto label_8005B688;
    case 0x8005B68Cu: goto label_8005B68C;
    case 0x8005B690u: goto label_8005B690;
    case 0x8005B694u: goto label_8005B694;
    case 0x8005B698u: goto label_8005B698;
    case 0x8005B69Cu: goto label_8005B69C;
    case 0x8005B6A0u: goto label_8005B6A0;
    case 0x8005B6A4u: goto label_8005B6A4;
    case 0x8005B6A8u: goto label_8005B6A8;
    case 0x8005B6ACu: goto label_8005B6AC;
    case 0x8005B6B0u: goto label_8005B6B0;
    case 0x8005B6B4u: goto label_8005B6B4;
    case 0x8005B6B8u: goto label_8005B6B8;
    case 0x8005B6BCu: goto label_8005B6BC;
    case 0x8005B6C0u: goto label_8005B6C0;
    case 0x8005B6C4u: goto label_8005B6C4;
    case 0x8005B6C8u: goto label_8005B6C8;
    case 0x8005B6CCu: goto label_8005B6CC;
    case 0x8005B6D0u: goto label_8005B6D0;
    case 0x8005B6D4u: goto label_8005B6D4;
    case 0x8005B6D8u: goto label_8005B6D8;
    case 0x8005B6DCu: goto label_8005B6DC;
    case 0x8005B6E0u: goto label_8005B6E0;
    case 0x8005B6E4u: goto label_8005B6E4;
    case 0x8005B6E8u: goto label_8005B6E8;
    case 0x8005B6ECu: goto label_8005B6EC;
    case 0x8005B6F0u: goto label_8005B6F0;
    case 0x8005B6F4u: goto label_8005B6F4;
    case 0x8005B6F8u: goto label_8005B6F8;
    case 0x8005B6FCu: goto label_8005B6FC;
    case 0x8005B700u: goto label_8005B700;
    case 0x8005B704u: goto label_8005B704;
    case 0x8005B708u: goto label_8005B708;
    case 0x8005B70Cu: goto label_8005B70C;
    case 0x8005B710u: goto label_8005B710;
    case 0x8005B714u: goto label_8005B714;
    case 0x8005B718u: goto label_8005B718;
    case 0x8005B71Cu: goto label_8005B71C;
    case 0x8005B720u: goto label_8005B720;
    case 0x8005B724u: goto label_8005B724;
    case 0x8005B728u: goto label_8005B728;
    case 0x8005B72Cu: goto label_8005B72C;
    case 0x8005B730u: goto label_8005B730;
    case 0x8005B734u: goto label_8005B734;
    case 0x8005B738u: goto label_8005B738;
    case 0x8005B73Cu: goto label_8005B73C;
    case 0x8005B740u: goto label_8005B740;
    case 0x8005B744u: goto label_8005B744;
    case 0x8005B748u: goto label_8005B748;
    case 0x8005B74Cu: goto label_8005B74C;
    case 0x8005B750u: goto label_8005B750;
    case 0x8005B754u: goto label_8005B754;
    case 0x8005B758u: goto label_8005B758;
    case 0x8005B75Cu: goto label_8005B75C;
    case 0x8005B760u: goto label_8005B760;
    case 0x8005B764u: goto label_8005B764;
    case 0x8005B768u: goto label_8005B768;
    case 0x8005B76Cu: goto label_8005B76C;
    case 0x8005B770u: goto label_8005B770;
    case 0x8005B774u: goto label_8005B774;
    case 0x8005B778u: goto label_8005B778;
    case 0x8005B77Cu: goto label_8005B77C;
    case 0x8005B780u: goto label_8005B780;
    case 0x8005B784u: goto label_8005B784;
    case 0x8005B788u: goto label_8005B788;
    case 0x8005B78Cu: goto label_8005B78C;
    case 0x8005B790u: goto label_8005B790;
    case 0x8005B794u: goto label_8005B794;
    case 0x8005B798u: goto label_8005B798;
    case 0x8005B79Cu: goto label_8005B79C;
    case 0x8005B7A0u: goto label_8005B7A0;
    case 0x8005B7A4u: goto label_8005B7A4;
    case 0x8005B7A8u: goto label_8005B7A8;
    case 0x8005B7ACu: goto label_8005B7AC;
    case 0x8005B7B0u: goto label_8005B7B0;
    case 0x8005B7B4u: goto label_8005B7B4;
    case 0x8005B7B8u: goto label_8005B7B8;
    case 0x8005B7BCu: goto label_8005B7BC;
    case 0x8005B7C0u: goto label_8005B7C0;
    case 0x8005B7C4u: goto label_8005B7C4;
    case 0x8005B7C8u: goto label_8005B7C8;
    case 0x8005B7CCu: goto label_8005B7CC;
    case 0x8005B7D0u: goto label_8005B7D0;
    case 0x8005B7D4u: goto label_8005B7D4;
    case 0x8005B7D8u: goto label_8005B7D8;
    case 0x8005B7DCu: goto label_8005B7DC;
    case 0x8005B7E0u: goto label_8005B7E0;
    case 0x8005B7E4u: goto label_8005B7E4;
    case 0x8005B7E8u: goto label_8005B7E8;
    case 0x8005B7ECu: goto label_8005B7EC;
    case 0x8005B7F0u: goto label_8005B7F0;
    case 0x8005B7F4u: goto label_8005B7F4;
    case 0x8005B7F8u: goto label_8005B7F8;
    case 0x8005B7FCu: goto label_8005B7FC;
    case 0x8005B800u: goto label_8005B800;
    case 0x8005B804u: goto label_8005B804;
    case 0x8005B808u: goto label_8005B808;
    case 0x8005B80Cu: goto label_8005B80C;
    case 0x8005B810u: goto label_8005B810;
    case 0x8005B814u: goto label_8005B814;
    case 0x8005B818u: goto label_8005B818;
    case 0x8005B81Cu: goto label_8005B81C;
    case 0x8005B820u: goto label_8005B820;
    case 0x8005B824u: goto label_8005B824;
    case 0x8005B828u: goto label_8005B828;
    case 0x8005B82Cu: goto label_8005B82C;
    case 0x8005B830u: goto label_8005B830;
    case 0x8005B834u: goto label_8005B834;
    case 0x8005B838u: goto label_8005B838;
    case 0x8005B83Cu: goto label_8005B83C;
    case 0x8005B840u: goto label_8005B840;
    case 0x8005B844u: goto label_8005B844;
    case 0x8005B848u: goto label_8005B848;
    case 0x8005B84Cu: goto label_8005B84C;
    case 0x8005B850u: goto label_8005B850;
    case 0x8005B854u: goto label_8005B854;
    case 0x8005B858u: goto label_8005B858;
    case 0x8005B85Cu: goto label_8005B85C;
    case 0x8005B860u: goto label_8005B860;
    case 0x8005B864u: goto label_8005B864;
    case 0x8005B868u: goto label_8005B868;
    case 0x8005B86Cu: goto label_8005B86C;
    case 0x8005B870u: goto label_8005B870;
    case 0x8005B874u: goto label_8005B874;
    case 0x8005B878u: goto label_8005B878;
    case 0x8005B87Cu: goto label_8005B87C;
    case 0x8005B880u: goto label_8005B880;
    case 0x8005B884u: goto label_8005B884;
    case 0x8005B888u: goto label_8005B888;
    case 0x8005B88Cu: goto label_8005B88C;
    case 0x8005B890u: goto label_8005B890;
    case 0x8005B894u: goto label_8005B894;
    case 0x8005B898u: goto label_8005B898;
    case 0x8005B89Cu: goto label_8005B89C;
    case 0x8005B8A0u: goto label_8005B8A0;
    case 0x8005B8A4u: goto label_8005B8A4;
    case 0x8005B8A8u: goto label_8005B8A8;
    case 0x8005B8ACu: goto label_8005B8AC;
    case 0x8005B8B0u: goto label_8005B8B0;
    case 0x8005B8B4u: goto label_8005B8B4;
    case 0x8005B8B8u: goto label_8005B8B8;
    case 0x8005B8BCu: goto label_8005B8BC;
    case 0x8005B8C0u: goto label_8005B8C0;
    case 0x8005B8C4u: goto label_8005B8C4;
    case 0x8005B8C8u: goto label_8005B8C8;
    case 0x8005B8CCu: goto label_8005B8CC;
    case 0x8005B8D0u: goto label_8005B8D0;
    case 0x8005B8D4u: goto label_8005B8D4;
    case 0x8005B8D8u: goto label_8005B8D8;
    case 0x8005B8DCu: goto label_8005B8DC;
    case 0x8005B8E0u: goto label_8005B8E0;
    case 0x8005B8E4u: goto label_8005B8E4;
    case 0x8005B8E8u: goto label_8005B8E8;
    case 0x8005B8ECu: goto label_8005B8EC;
    case 0x8005B8F0u: goto label_8005B8F0;
    case 0x8005B8F4u: goto label_8005B8F4;
    case 0x8005B8F8u: goto label_8005B8F8;
    case 0x8005B8FCu: goto label_8005B8FC;
    case 0x8005B900u: goto label_8005B900;
    case 0x8005B904u: goto label_8005B904;
    case 0x8005B908u: goto label_8005B908;
    case 0x8005B90Cu: goto label_8005B90C;
    case 0x8005B910u: goto label_8005B910;
    case 0x8005B914u: goto label_8005B914;
    case 0x8005B918u: goto label_8005B918;
    case 0x8005B91Cu: goto label_8005B91C;
    case 0x8005B920u: goto label_8005B920;
    case 0x8005B924u: goto label_8005B924;
    case 0x8005B928u: goto label_8005B928;
    case 0x8005B92Cu: goto label_8005B92C;
    case 0x8005B930u: goto label_8005B930;
    case 0x8005B934u: goto label_8005B934;
    case 0x8005B938u: goto label_8005B938;
    case 0x8005B93Cu: goto label_8005B93C;
    case 0x8005B940u: goto label_8005B940;
    case 0x8005B944u: goto label_8005B944;
    case 0x8005B948u: goto label_8005B948;
    case 0x8005B94Cu: goto label_8005B94C;
    case 0x8005B950u: goto label_8005B950;
    case 0x8005B954u: goto label_8005B954;
    case 0x8005B958u: goto label_8005B958;
    case 0x8005B95Cu: goto label_8005B95C;
    case 0x8005B960u: goto label_8005B960;
    case 0x8005B964u: goto label_8005B964;
    case 0x8005B968u: goto label_8005B968;
    case 0x8005B96Cu: goto label_8005B96C;
    case 0x8005B970u: goto label_8005B970;
    case 0x8005B974u: goto label_8005B974;
    case 0x8005B978u: goto label_8005B978;
    case 0x8005B97Cu: goto label_8005B97C;
    case 0x8005B980u: goto label_8005B980;
    case 0x8005B984u: goto label_8005B984;
    case 0x8005B988u: goto label_8005B988;
    case 0x8005B98Cu: goto label_8005B98C;
    case 0x8005B990u: goto label_8005B990;
    case 0x8005B994u: goto label_8005B994;
    case 0x8005B998u: goto label_8005B998;
    case 0x8005B99Cu: goto label_8005B99C;
    case 0x8005B9A0u: goto label_8005B9A0;
    case 0x8005B9A4u: goto label_8005B9A4;
    case 0x8005B9A8u: goto label_8005B9A8;
    case 0x8005B9ACu: goto label_8005B9AC;
    case 0x8005B9B0u: goto label_8005B9B0;
    case 0x8005B9B4u: goto label_8005B9B4;
    case 0x8005B9B8u: goto label_8005B9B8;
    case 0x8005B9BCu: goto label_8005B9BC;
    case 0x8005B9C0u: goto label_8005B9C0;
    case 0x8005B9C4u: goto label_8005B9C4;
    case 0x8005B9C8u: goto label_8005B9C8;
    case 0x8005B9CCu: goto label_8005B9CC;
    case 0x8005B9D0u: goto label_8005B9D0;
    case 0x8005B9D4u: goto label_8005B9D4;
    case 0x8005B9D8u: goto label_8005B9D8;
    case 0x8005B9DCu: goto label_8005B9DC;
    case 0x8005B9E0u: goto label_8005B9E0;
    case 0x8005B9E4u: goto label_8005B9E4;
    case 0x8005B9E8u: goto label_8005B9E8;
    case 0x8005B9ECu: goto label_8005B9EC;
    case 0x8005B9F0u: goto label_8005B9F0;
    case 0x8005B9F4u: goto label_8005B9F4;
    case 0x8005B9F8u: goto label_8005B9F8;
    case 0x8005B9FCu: goto label_8005B9FC;
    case 0x8005BA00u: goto label_8005BA00;
    case 0x8005BA04u: goto label_8005BA04;
    case 0x8005BA08u: goto label_8005BA08;
    case 0x8005BA0Cu: goto label_8005BA0C;
    case 0x8005BA10u: goto label_8005BA10;
    case 0x8005BA14u: goto label_8005BA14;
    case 0x8005BA18u: goto label_8005BA18;
    case 0x8005BA1Cu: goto label_8005BA1C;
    case 0x8005BA20u: goto label_8005BA20;
    case 0x8005BA24u: goto label_8005BA24;
    case 0x8005BA28u: goto label_8005BA28;
    case 0x8005BA2Cu: goto label_8005BA2C;
    case 0x8005BA30u: goto label_8005BA30;
    case 0x8005BA34u: goto label_8005BA34;
    case 0x8005BA38u: goto label_8005BA38;
    case 0x8005BA3Cu: goto label_8005BA3C;
    case 0x8005BA40u: goto label_8005BA40;
    case 0x8005BA44u: goto label_8005BA44;
    case 0x8005BA48u: goto label_8005BA48;
    case 0x8005BA4Cu: goto label_8005BA4C;
    case 0x8005BA50u: goto label_8005BA50;
    case 0x8005BA54u: goto label_8005BA54;
    case 0x8005BA58u: goto label_8005BA58;
    case 0x8005BA5Cu: goto label_8005BA5C;
    case 0x8005BA60u: goto label_8005BA60;
    case 0x8005BA64u: goto label_8005BA64;
    case 0x8005BA68u: goto label_8005BA68;
    case 0x8005BA6Cu: goto label_8005BA6C;
    case 0x8005BA70u: goto label_8005BA70;
    case 0x8005BA74u: goto label_8005BA74;
    case 0x8005BA78u: goto label_8005BA78;
    case 0x8005BA7Cu: goto label_8005BA7C;
    case 0x8005BA80u: goto label_8005BA80;
    case 0x8005BA84u: goto label_8005BA84;
    case 0x8005BA88u: goto label_8005BA88;
    case 0x8005BA8Cu: goto label_8005BA8C;
    case 0x8005BA90u: goto label_8005BA90;
    case 0x8005BA94u: goto label_8005BA94;
    case 0x8005BA98u: goto label_8005BA98;
    case 0x8005BA9Cu: goto label_8005BA9C;
    case 0x8005BAA0u: goto label_8005BAA0;
    case 0x8005BAA4u: goto label_8005BAA4;
    case 0x8005BAA8u: goto label_8005BAA8;
    case 0x8005BAACu: goto label_8005BAAC;
    case 0x8005BAB0u: goto label_8005BAB0;
    case 0x8005BAB4u: goto label_8005BAB4;
    case 0x8005BAB8u: goto label_8005BAB8;
    case 0x8005BABCu: goto label_8005BABC;
    case 0x8005BAC0u: goto label_8005BAC0;
    case 0x8005BAC4u: goto label_8005BAC4;
    case 0x8005BAC8u: goto label_8005BAC8;
    case 0x8005BACCu: goto label_8005BACC;
    case 0x8005BAD0u: goto label_8005BAD0;
    case 0x8005BAD4u: goto label_8005BAD4;
    case 0x8005BAD8u: goto label_8005BAD8;
    case 0x8005BADCu: goto label_8005BADC;
    case 0x8005BAE0u: goto label_8005BAE0;
    case 0x8005BAE4u: goto label_8005BAE4;
    case 0x8005BAE8u: goto label_8005BAE8;
    case 0x8005BAECu: goto label_8005BAEC;
    case 0x8005BAF0u: goto label_8005BAF0;
    case 0x8005BAF4u: goto label_8005BAF4;
    case 0x8005BAF8u: goto label_8005BAF8;
    case 0x8005BAFCu: goto label_8005BAFC;
    case 0x8005BB00u: goto label_8005BB00;
    case 0x8005BB04u: goto label_8005BB04;
    case 0x8005BB08u: goto label_8005BB08;
    case 0x8005BB0Cu: goto label_8005BB0C;
    case 0x8005BB10u: goto label_8005BB10;
    case 0x8005BB14u: goto label_8005BB14;
    case 0x8005BB18u: goto label_8005BB18;
    case 0x8005BB1Cu: goto label_8005BB1C;
    case 0x8005BB20u: goto label_8005BB20;
    case 0x8005BB24u: goto label_8005BB24;
    case 0x8005BB28u: goto label_8005BB28;
    case 0x8005BB2Cu: goto label_8005BB2C;
    case 0x8005BB30u: goto label_8005BB30;
    case 0x8005BB34u: goto label_8005BB34;
    case 0x8005BB38u: goto label_8005BB38;
    case 0x8005BB3Cu: goto label_8005BB3C;
    case 0x8005BB40u: goto label_8005BB40;
    case 0x8005BB44u: goto label_8005BB44;
    case 0x8005BB48u: goto label_8005BB48;
    case 0x8005BB4Cu: goto label_8005BB4C;
    case 0x8005BB50u: goto label_8005BB50;
    case 0x8005BB54u: goto label_8005BB54;
    case 0x8005BB58u: goto label_8005BB58;
    case 0x8005BB5Cu: goto label_8005BB5C;
    case 0x8005BB60u: goto label_8005BB60;
    case 0x8005BB64u: goto label_8005BB64;
    case 0x8005BB68u: goto label_8005BB68;
    case 0x8005BB6Cu: goto label_8005BB6C;
    case 0x8005BB70u: goto label_8005BB70;
    case 0x8005BB74u: goto label_8005BB74;
    case 0x8005BB78u: goto label_8005BB78;
    case 0x8005BB7Cu: goto label_8005BB7C;
    case 0x8005BB80u: goto label_8005BB80;
    case 0x8005BB84u: goto label_8005BB84;
    case 0x8005BB88u: goto label_8005BB88;
    case 0x8005BB8Cu: goto label_8005BB8C;
    case 0x8005BB90u: goto label_8005BB90;
    case 0x8005BB94u: goto label_8005BB94;
    case 0x8005BB98u: goto label_8005BB98;
    case 0x8005BB9Cu: goto label_8005BB9C;
    case 0x8005BBA0u: goto label_8005BBA0;
    case 0x8005BBA4u: goto label_8005BBA4;
    case 0x8005BBA8u: goto label_8005BBA8;
    case 0x8005BBACu: goto label_8005BBAC;
    case 0x8005BBB0u: goto label_8005BBB0;
    case 0x8005BBB4u: goto label_8005BBB4;
    case 0x8005BBB8u: goto label_8005BBB8;
    case 0x8005BBBCu: goto label_8005BBBC;
    case 0x8005BBC0u: goto label_8005BBC0;
    case 0x8005BBC4u: goto label_8005BBC4;
    case 0x8005BBC8u: goto label_8005BBC8;
    case 0x8005BBCCu: goto label_8005BBCC;
    case 0x8005BBD0u: goto label_8005BBD0;
    case 0x8005BBD4u: goto label_8005BBD4;
    case 0x8005BBD8u: goto label_8005BBD8;
    case 0x8005BBDCu: goto label_8005BBDC;
    case 0x8005BBE0u: goto label_8005BBE0;
    case 0x8005BBE4u: goto label_8005BBE4;
    case 0x8005BBE8u: goto label_8005BBE8;
    case 0x8005BBECu: goto label_8005BBEC;
    case 0x8005BBF0u: goto label_8005BBF0;
    case 0x8005BBF4u: goto label_8005BBF4;
    case 0x8005BBF8u: goto label_8005BBF8;
    case 0x8005BBFCu: goto label_8005BBFC;
    case 0x8005BC00u: goto label_8005BC00;
    case 0x8005BC04u: goto label_8005BC04;
    case 0x8005BC08u: goto label_8005BC08;
    case 0x8005BC0Cu: goto label_8005BC0C;
    case 0x8005BC10u: goto label_8005BC10;
    case 0x8005BC14u: goto label_8005BC14;
    case 0x8005BC18u: goto label_8005BC18;
    case 0x8005BC1Cu: goto label_8005BC1C;
    case 0x8005BC20u: goto label_8005BC20;
    case 0x8005BC24u: goto label_8005BC24;
    case 0x8005BC28u: goto label_8005BC28;
    case 0x8005BC2Cu: goto label_8005BC2C;
    case 0x8005BC30u: goto label_8005BC30;
    case 0x8005BC34u: goto label_8005BC34;
    case 0x8005BC38u: goto label_8005BC38;
    case 0x8005BC3Cu: goto label_8005BC3C;
    case 0x8005BC40u: goto label_8005BC40;
    case 0x8005BC44u: goto label_8005BC44;
    case 0x8005BC48u: goto label_8005BC48;
    case 0x8005BC4Cu: goto label_8005BC4C;
    case 0x8005BC50u: goto label_8005BC50;
    case 0x8005BC54u: goto label_8005BC54;
    case 0x8005BC58u: goto label_8005BC58;
    case 0x8005BC5Cu: goto label_8005BC5C;
    case 0x8005BC60u: goto label_8005BC60;
    case 0x8005BC64u: goto label_8005BC64;
    case 0x8005BC68u: goto label_8005BC68;
    case 0x8005BC6Cu: goto label_8005BC6C;
    case 0x8005BC70u: goto label_8005BC70;
    case 0x8005BC74u: goto label_8005BC74;
    case 0x8005BC78u: goto label_8005BC78;
    case 0x8005BC7Cu: goto label_8005BC7C;
    case 0x8005BC80u: goto label_8005BC80;
    case 0x8005BC84u: goto label_8005BC84;
    case 0x8005BC88u: goto label_8005BC88;
    case 0x8005BC8Cu: goto label_8005BC8C;
    case 0x8005BC90u: goto label_8005BC90;
    case 0x8005BC94u: goto label_8005BC94;
    case 0x8005BC98u: goto label_8005BC98;
    case 0x8005BC9Cu: goto label_8005BC9C;
    case 0x8005BCA0u: goto label_8005BCA0;
    case 0x8005BCA4u: goto label_8005BCA4;
    case 0x8005BCA8u: goto label_8005BCA8;
    case 0x8005BCACu: goto label_8005BCAC;
    case 0x8005BCB0u: goto label_8005BCB0;
    case 0x8005BCB4u: goto label_8005BCB4;
    case 0x8005BCB8u: goto label_8005BCB8;
    case 0x8005BCBCu: goto label_8005BCBC;
    case 0x8005BCC0u: goto label_8005BCC0;
    case 0x8005BCC4u: goto label_8005BCC4;
    case 0x8005BCC8u: goto label_8005BCC8;
    case 0x8005BCCCu: goto label_8005BCCC;
    case 0x8005BCD0u: goto label_8005BCD0;
    case 0x8005BCD4u: goto label_8005BCD4;
    case 0x8005BCD8u: goto label_8005BCD8;
    case 0x8005BCDCu: goto label_8005BCDC;
    case 0x8005BCE0u: goto label_8005BCE0;
    case 0x8005BCE4u: goto label_8005BCE4;
    case 0x8005BCE8u: goto label_8005BCE8;
    case 0x8005BCECu: goto label_8005BCEC;
    case 0x8005BCF0u: goto label_8005BCF0;
    case 0x8005BCF4u: goto label_8005BCF4;
    case 0x8005BCF8u: goto label_8005BCF8;
    case 0x8005BCFCu: goto label_8005BCFC;
    case 0x8005BD00u: goto label_8005BD00;
    case 0x8005BD04u: goto label_8005BD04;
    case 0x8005BD08u: goto label_8005BD08;
    case 0x8005BD0Cu: goto label_8005BD0C;
    case 0x8005BD10u: goto label_8005BD10;
    case 0x8005BD14u: goto label_8005BD14;
    case 0x8005BD18u: goto label_8005BD18;
    case 0x8005BD1Cu: goto label_8005BD1C;
    case 0x8005BD20u: goto label_8005BD20;
    case 0x8005BD24u: goto label_8005BD24;
    case 0x8005BD28u: goto label_8005BD28;
    case 0x8005BD2Cu: goto label_8005BD2C;
    case 0x8005BD30u: goto label_8005BD30;
    case 0x8005BD34u: goto label_8005BD34;
    case 0x8005BD38u: goto label_8005BD38;
    case 0x8005BD3Cu: goto label_8005BD3C;
    case 0x8005BD40u: goto label_8005BD40;
    case 0x8005BD44u: goto label_8005BD44;
    case 0x8005BD48u: goto label_8005BD48;
    case 0x8005BD4Cu: goto label_8005BD4C;
    case 0x8005BD50u: goto label_8005BD50;
    case 0x8005BD54u: goto label_8005BD54;
    case 0x8005BD58u: goto label_8005BD58;
    case 0x8005BD5Cu: goto label_8005BD5C;
    case 0x8005BD60u: goto label_8005BD60;
    case 0x8005BD64u: goto label_8005BD64;
    case 0x8005BD68u: goto label_8005BD68;
    case 0x8005BD6Cu: goto label_8005BD6C;
    case 0x8005BD70u: goto label_8005BD70;
    case 0x8005BD74u: goto label_8005BD74;
    case 0x8005BD78u: goto label_8005BD78;
    case 0x8005BD7Cu: goto label_8005BD7C;
    case 0x8005BD80u: goto label_8005BD80;
    case 0x8005BD84u: goto label_8005BD84;
    case 0x8005BD88u: goto label_8005BD88;
    case 0x8005BD8Cu: goto label_8005BD8C;
    case 0x8005BD90u: goto label_8005BD90;
    case 0x8005BD94u: goto label_8005BD94;
    case 0x8005BD98u: goto label_8005BD98;
    case 0x8005BD9Cu: goto label_8005BD9C;
    case 0x8005BDA0u: goto label_8005BDA0;
    case 0x8005BDA4u: goto label_8005BDA4;
    case 0x8005BDA8u: goto label_8005BDA8;
    case 0x8005BDACu: goto label_8005BDAC;
    case 0x8005BDB0u: goto label_8005BDB0;
    case 0x8005BDB4u: goto label_8005BDB4;
    case 0x8005BDB8u: goto label_8005BDB8;
    case 0x8005BDBCu: goto label_8005BDBC;
    case 0x8005BDC0u: goto label_8005BDC0;
    case 0x8005BDC4u: goto label_8005BDC4;
    case 0x8005BDC8u: goto label_8005BDC8;
    case 0x8005BDCCu: goto label_8005BDCC;
    case 0x8005BDD0u: goto label_8005BDD0;
    case 0x8005BDD4u: goto label_8005BDD4;
    case 0x8005BDD8u: goto label_8005BDD8;
    case 0x8005BDDCu: goto label_8005BDDC;
    case 0x8005BDE0u: goto label_8005BDE0;
    case 0x8005BDE4u: goto label_8005BDE4;
    case 0x8005BDE8u: goto label_8005BDE8;
    case 0x8005BDECu: goto label_8005BDEC;
    case 0x8005BDF0u: goto label_8005BDF0;
    case 0x8005BDF4u: goto label_8005BDF4;
    case 0x8005BDF8u: goto label_8005BDF8;
    case 0x8005BDFCu: goto label_8005BDFC;
    case 0x8005BE00u: goto label_8005BE00;
    case 0x8005BE04u: goto label_8005BE04;
    case 0x8005BE08u: goto label_8005BE08;
    case 0x8005BE0Cu: goto label_8005BE0C;
    case 0x8005BE10u: goto label_8005BE10;
    case 0x8005BE14u: goto label_8005BE14;
    case 0x8005BE18u: goto label_8005BE18;
    case 0x8005BE1Cu: goto label_8005BE1C;
    case 0x8005BE20u: goto label_8005BE20;
    case 0x8005BE24u: goto label_8005BE24;
    case 0x8005BE28u: goto label_8005BE28;
    case 0x8005BE2Cu: goto label_8005BE2C;
    case 0x8005BE30u: goto label_8005BE30;
    case 0x8005BE34u: goto label_8005BE34;
    case 0x8005BE38u: goto label_8005BE38;
    case 0x8005BE3Cu: goto label_8005BE3C;
    case 0x8005BE40u: goto label_8005BE40;
    case 0x8005BE44u: goto label_8005BE44;
    case 0x8005BE48u: goto label_8005BE48;
    case 0x8005BE4Cu: goto label_8005BE4C;
    case 0x8005BE50u: goto label_8005BE50;
    case 0x8005BE54u: goto label_8005BE54;
    case 0x8005BE58u: goto label_8005BE58;
    case 0x8005BE5Cu: goto label_8005BE5C;
    case 0x8005BE60u: goto label_8005BE60;
    case 0x8005BE64u: goto label_8005BE64;
    case 0x8005BE68u: goto label_8005BE68;
    case 0x8005BE6Cu: goto label_8005BE6C;
    case 0x8005BE70u: goto label_8005BE70;
    case 0x8005BE74u: goto label_8005BE74;
    case 0x8005BE78u: goto label_8005BE78;
    case 0x8005BE7Cu: goto label_8005BE7C;
    case 0x8005BE80u: goto label_8005BE80;
    case 0x8005BE84u: goto label_8005BE84;
    case 0x8005BE88u: goto label_8005BE88;
    case 0x8005BE8Cu: goto label_8005BE8C;
    case 0x8005BE90u: goto label_8005BE90;
    case 0x8005BE94u: goto label_8005BE94;
    case 0x8005BE98u: goto label_8005BE98;
    case 0x8005BE9Cu: goto label_8005BE9C;
    case 0x8005BEA0u: goto label_8005BEA0;
    case 0x8005BEA4u: goto label_8005BEA4;
    case 0x8005BEA8u: goto label_8005BEA8;
    case 0x8005BEACu: goto label_8005BEAC;
    case 0x8005BEB0u: goto label_8005BEB0;
    case 0x8005BEB4u: goto label_8005BEB4;
    case 0x8005BEB8u: goto label_8005BEB8;
    case 0x8005BEBCu: goto label_8005BEBC;
    case 0x8005BEC0u: goto label_8005BEC0;
    case 0x8005BEC4u: goto label_8005BEC4;
    case 0x8005BEC8u: goto label_8005BEC8;
    case 0x8005BECCu: goto label_8005BECC;
    case 0x8005BED0u: goto label_8005BED0;
    case 0x8005BED4u: goto label_8005BED4;
    case 0x8005BED8u: goto label_8005BED8;
    case 0x8005BEDCu: goto label_8005BEDC;
    case 0x8005BEE0u: goto label_8005BEE0;
    case 0x8005BEE4u: goto label_8005BEE4;
    case 0x8005BEE8u: goto label_8005BEE8;
    case 0x8005BEECu: goto label_8005BEEC;
    case 0x8005BEF0u: goto label_8005BEF0;
    case 0x8005BEF4u: goto label_8005BEF4;
    case 0x8005BEF8u: goto label_8005BEF8;
    case 0x8005BEFCu: goto label_8005BEFC;
    case 0x8005BF00u: goto label_8005BF00;
    case 0x8005BF04u: goto label_8005BF04;
    case 0x8005BF08u: goto label_8005BF08;
    case 0x8005BF0Cu: goto label_8005BF0C;
    case 0x8005BF10u: goto label_8005BF10;
    case 0x8005BF14u: goto label_8005BF14;
    case 0x8005BF18u: goto label_8005BF18;
    case 0x8005BF1Cu: goto label_8005BF1C;
    case 0x8005BF20u: goto label_8005BF20;
    case 0x8005BF24u: goto label_8005BF24;
    case 0x8005BF28u: goto label_8005BF28;
    case 0x8005BF2Cu: goto label_8005BF2C;
    case 0x8005BF30u: goto label_8005BF30;
    case 0x8005BF34u: goto label_8005BF34;
    case 0x8005BF38u: goto label_8005BF38;
    case 0x8005BF3Cu: goto label_8005BF3C;
    case 0x8005BF40u: goto label_8005BF40;
    case 0x8005BF44u: goto label_8005BF44;
    case 0x8005BF48u: goto label_8005BF48;
    case 0x8005BF4Cu: goto label_8005BF4C;
    case 0x8005BF50u: goto label_8005BF50;
    case 0x8005BF54u: goto label_8005BF54;
    case 0x8005BF58u: goto label_8005BF58;
    case 0x8005BF5Cu: goto label_8005BF5C;
    case 0x8005BF60u: goto label_8005BF60;
    case 0x8005BF64u: goto label_8005BF64;
    case 0x8005BF68u: goto label_8005BF68;
    case 0x8005BF6Cu: goto label_8005BF6C;
    case 0x8005BF70u: goto label_8005BF70;
    case 0x8005BF74u: goto label_8005BF74;
    case 0x8005BF78u: goto label_8005BF78;
    case 0x8005BF7Cu: goto label_8005BF7C;
    case 0x8005BF80u: goto label_8005BF80;
    case 0x8005BF84u: goto label_8005BF84;
    case 0x8005BF88u: goto label_8005BF88;
    case 0x8005BF8Cu: goto label_8005BF8C;
    case 0x8005BF90u: goto label_8005BF90;
    case 0x8005BF94u: goto label_8005BF94;
    case 0x8005BF98u: goto label_8005BF98;
    case 0x8005BF9Cu: goto label_8005BF9C;
    case 0x8005BFA0u: goto label_8005BFA0;
    case 0x8005BFA4u: goto label_8005BFA4;
    case 0x8005BFA8u: goto label_8005BFA8;
    case 0x8005BFACu: goto label_8005BFAC;
    case 0x8005BFB0u: goto label_8005BFB0;
    case 0x8005BFB4u: goto label_8005BFB4;
    case 0x8005BFB8u: goto label_8005BFB8;
    case 0x8005BFBCu: goto label_8005BFBC;
    case 0x8005BFC0u: goto label_8005BFC0;
    case 0x8005BFC4u: goto label_8005BFC4;
    case 0x8005BFC8u: goto label_8005BFC8;
    case 0x8005BFCCu: goto label_8005BFCC;
    case 0x8005BFD0u: goto label_8005BFD0;
    case 0x8005BFD4u: goto label_8005BFD4;
    case 0x8005BFD8u: goto label_8005BFD8;
    case 0x8005BFDCu: goto label_8005BFDC;
    case 0x8005BFE0u: goto label_8005BFE0;
    case 0x8005BFE4u: goto label_8005BFE4;
    case 0x8005BFE8u: goto label_8005BFE8;
    case 0x8005BFECu: goto label_8005BFEC;
    case 0x8005BFF0u: goto label_8005BFF0;
    case 0x8005BFF4u: goto label_8005BFF4;
    case 0x8005BFF8u: goto label_8005BFF8;
    case 0x8005BFFCu: goto label_8005BFFC;
    case 0x8005C000u: goto label_8005C000;
    case 0x8005C004u: goto label_8005C004;
    case 0x8005C008u: goto label_8005C008;
    case 0x8005C00Cu: goto label_8005C00C;
    case 0x8005C010u: goto label_8005C010;
    case 0x8005C014u: goto label_8005C014;
    case 0x8005C018u: goto label_8005C018;
    case 0x8005C01Cu: goto label_8005C01C;
    case 0x8005C020u: goto label_8005C020;
    case 0x8005C024u: goto label_8005C024;
    case 0x8005C028u: goto label_8005C028;
    case 0x8005C02Cu: goto label_8005C02C;
    case 0x8005C030u: goto label_8005C030;
    case 0x8005C034u: goto label_8005C034;
    case 0x8005C038u: goto label_8005C038;
    case 0x8005C03Cu: goto label_8005C03C;
    case 0x8005C040u: goto label_8005C040;
    case 0x8005C044u: goto label_8005C044;
    case 0x8005C048u: goto label_8005C048;
    case 0x8005C04Cu: goto label_8005C04C;
    case 0x8005C050u: goto label_8005C050;
    case 0x8005C054u: goto label_8005C054;
    case 0x8005C058u: goto label_8005C058;
    case 0x8005C05Cu: goto label_8005C05C;
    case 0x8005C060u: goto label_8005C060;
    case 0x8005C064u: goto label_8005C064;
    case 0x8005C068u: goto label_8005C068;
    case 0x8005C06Cu: goto label_8005C06C;
    case 0x8005C070u: goto label_8005C070;
    case 0x8005C074u: goto label_8005C074;
    case 0x8005C078u: goto label_8005C078;
    case 0x8005C07Cu: goto label_8005C07C;
    case 0x8005C080u: goto label_8005C080;
    case 0x8005C084u: goto label_8005C084;
    case 0x8005C088u: goto label_8005C088;
    case 0x8005C08Cu: goto label_8005C08C;
    case 0x8005C090u: goto label_8005C090;
    case 0x8005C094u: goto label_8005C094;
    case 0x8005C098u: goto label_8005C098;
    case 0x8005C09Cu: goto label_8005C09C;
    case 0x8005C0A0u: goto label_8005C0A0;
    case 0x8005C0A4u: goto label_8005C0A4;
    case 0x8005C0A8u: goto label_8005C0A8;
    case 0x8005C0ACu: goto label_8005C0AC;
    case 0x8005C0B0u: goto label_8005C0B0;
    case 0x8005C0B4u: goto label_8005C0B4;
    case 0x8005C0B8u: goto label_8005C0B8;
    case 0x8005C0BCu: goto label_8005C0BC;
    case 0x8005C0C0u: goto label_8005C0C0;
    case 0x8005C0C4u: goto label_8005C0C4;
    case 0x8005C0C8u: goto label_8005C0C8;
    case 0x8005C0CCu: goto label_8005C0CC;
    case 0x8005C0D0u: goto label_8005C0D0;
    case 0x8005C0D4u: goto label_8005C0D4;
    case 0x8005C0D8u: goto label_8005C0D8;
    case 0x8005C0DCu: goto label_8005C0DC;
    case 0x8005C0E0u: goto label_8005C0E0;
    case 0x8005C0E4u: goto label_8005C0E4;
    case 0x8005C0E8u: goto label_8005C0E8;
    case 0x8005C0ECu: goto label_8005C0EC;
    case 0x8005C0F0u: goto label_8005C0F0;
    case 0x8005C0F4u: goto label_8005C0F4;
    case 0x8005C0F8u: goto label_8005C0F8;
    case 0x8005C0FCu: goto label_8005C0FC;
    case 0x8005C100u: goto label_8005C100;
    case 0x8005C104u: goto label_8005C104;
    case 0x8005C108u: goto label_8005C108;
    case 0x8005C10Cu: goto label_8005C10C;
    case 0x8005C110u: goto label_8005C110;
    case 0x8005C114u: goto label_8005C114;
    case 0x8005C118u: goto label_8005C118;
    case 0x8005C11Cu: goto label_8005C11C;
    case 0x8005C120u: goto label_8005C120;
    case 0x8005C124u: goto label_8005C124;
    case 0x8005C128u: goto label_8005C128;
    case 0x8005C12Cu: goto label_8005C12C;
    case 0x8005C130u: goto label_8005C130;
    case 0x8005C134u: goto label_8005C134;
    case 0x8005C138u: goto label_8005C138;
    case 0x8005C13Cu: goto label_8005C13C;
    case 0x8005C140u: goto label_8005C140;
    case 0x8005C144u: goto label_8005C144;
    case 0x8005C148u: goto label_8005C148;
    case 0x8005C14Cu: goto label_8005C14C;
    case 0x8005C150u: goto label_8005C150;
    case 0x8005C154u: goto label_8005C154;
    case 0x8005C158u: goto label_8005C158;
    case 0x8005C15Cu: goto label_8005C15C;
    case 0x8005C160u: goto label_8005C160;
    case 0x8005C164u: goto label_8005C164;
    case 0x8005C168u: goto label_8005C168;
    case 0x8005C16Cu: goto label_8005C16C;
    case 0x8005C170u: goto label_8005C170;
    case 0x8005C174u: goto label_8005C174;
    case 0x8005C178u: goto label_8005C178;
    case 0x8005C17Cu: goto label_8005C17C;
    case 0x8005C180u: goto label_8005C180;
    case 0x8005C184u: goto label_8005C184;
    case 0x8005C188u: goto label_8005C188;
    case 0x8005C18Cu: goto label_8005C18C;
    case 0x8005C190u: goto label_8005C190;
    case 0x8005C194u: goto label_8005C194;
    case 0x8005C198u: goto label_8005C198;
    case 0x8005C19Cu: goto label_8005C19C;
    case 0x8005C1A0u: goto label_8005C1A0;
    case 0x8005C1A4u: goto label_8005C1A4;
    case 0x8005C1A8u: goto label_8005C1A8;
    case 0x8005C1ACu: goto label_8005C1AC;
    case 0x8005C1B0u: goto label_8005C1B0;
    case 0x8005C1B4u: goto label_8005C1B4;
    case 0x8005C1B8u: goto label_8005C1B8;
    case 0x8005C1BCu: goto label_8005C1BC;
    case 0x8005C1C0u: goto label_8005C1C0;
    case 0x8005C1C4u: goto label_8005C1C4;
    case 0x8005C1C8u: goto label_8005C1C8;
    case 0x8005C1CCu: goto label_8005C1CC;
    case 0x8005C1D0u: goto label_8005C1D0;
    case 0x8005C1D4u: goto label_8005C1D4;
    case 0x8005C1D8u: goto label_8005C1D8;
    case 0x8005C1DCu: goto label_8005C1DC;
    case 0x8005C1E0u: goto label_8005C1E0;
    case 0x8005C1E4u: goto label_8005C1E4;
    case 0x8005C1E8u: goto label_8005C1E8;
    case 0x8005C1ECu: goto label_8005C1EC;
    case 0x8005C1F0u: goto label_8005C1F0;
    case 0x8005C1F4u: goto label_8005C1F4;
    case 0x8005C1F8u: goto label_8005C1F8;
    case 0x8005C1FCu: goto label_8005C1FC;
    case 0x8005C200u: goto label_8005C200;
    case 0x8005C204u: goto label_8005C204;
    case 0x8005C208u: goto label_8005C208;
    case 0x8005C20Cu: goto label_8005C20C;
    case 0x8005C210u: goto label_8005C210;
    case 0x8005C214u: goto label_8005C214;
    case 0x8005C218u: goto label_8005C218;
    case 0x8005C21Cu: goto label_8005C21C;
    case 0x8005C220u: goto label_8005C220;
    case 0x8005C224u: goto label_8005C224;
    case 0x8005C228u: goto label_8005C228;
    case 0x8005C22Cu: goto label_8005C22C;
    case 0x8005C230u: goto label_8005C230;
    case 0x8005C234u: goto label_8005C234;
    case 0x8005C238u: goto label_8005C238;
    case 0x8005C23Cu: goto label_8005C23C;
    case 0x8005C240u: goto label_8005C240;
    case 0x8005C244u: goto label_8005C244;
    case 0x8005C248u: goto label_8005C248;
    case 0x8005C24Cu: goto label_8005C24C;
    case 0x8005C250u: goto label_8005C250;
    case 0x8005C254u: goto label_8005C254;
    case 0x8005C258u: goto label_8005C258;
    case 0x8005C25Cu: goto label_8005C25C;
    case 0x8005C260u: goto label_8005C260;
    case 0x8005C264u: goto label_8005C264;
    case 0x8005C268u: goto label_8005C268;
    case 0x8005C26Cu: goto label_8005C26C;
    case 0x8005C270u: goto label_8005C270;
    case 0x8005C274u: goto label_8005C274;
    case 0x8005C278u: goto label_8005C278;
    case 0x8005C27Cu: goto label_8005C27C;
    case 0x8005C280u: goto label_8005C280;
    case 0x8005C284u: goto label_8005C284;
    case 0x8005C288u: goto label_8005C288;
    case 0x8005C28Cu: goto label_8005C28C;
    case 0x8005C290u: goto label_8005C290;
    case 0x8005C294u: goto label_8005C294;
    case 0x8005C298u: goto label_8005C298;
    case 0x8005C29Cu: goto label_8005C29C;
    case 0x8005C2A0u: goto label_8005C2A0;
    case 0x8005C2A4u: goto label_8005C2A4;
    case 0x8005C2A8u: goto label_8005C2A8;
    case 0x8005C2ACu: goto label_8005C2AC;
    case 0x8005C2B0u: goto label_8005C2B0;
    case 0x8005C2B4u: goto label_8005C2B4;
    case 0x8005C2B8u: goto label_8005C2B8;
    case 0x8005C2BCu: goto label_8005C2BC;
    case 0x8005C2C0u: goto label_8005C2C0;
    case 0x8005C2C4u: goto label_8005C2C4;
    case 0x8005C2C8u: goto label_8005C2C8;
    case 0x8005C2CCu: goto label_8005C2CC;
    case 0x8005C2D0u: goto label_8005C2D0;
    case 0x8005C2D4u: goto label_8005C2D4;
    case 0x8005C2D8u: goto label_8005C2D8;
    case 0x8005C2DCu: goto label_8005C2DC;
    case 0x8005C2E0u: goto label_8005C2E0;
    case 0x8005C2E4u: goto label_8005C2E4;
    case 0x8005C2E8u: goto label_8005C2E8;
    case 0x8005C2ECu: goto label_8005C2EC;
    case 0x8005C2F0u: goto label_8005C2F0;
    case 0x8005C2F4u: goto label_8005C2F4;
    case 0x8005C2F8u: goto label_8005C2F8;
    case 0x8005C2FCu: goto label_8005C2FC;
    case 0x8005C300u: goto label_8005C300;
    case 0x8005C304u: goto label_8005C304;
    case 0x8005C308u: goto label_8005C308;
    case 0x8005C30Cu: goto label_8005C30C;
    case 0x8005C310u: goto label_8005C310;
    case 0x8005C314u: goto label_8005C314;
    case 0x8005C318u: goto label_8005C318;
    case 0x8005C31Cu: goto label_8005C31C;
    case 0x8005C320u: goto label_8005C320;
    case 0x8005C324u: goto label_8005C324;
    case 0x8005C328u: goto label_8005C328;
    case 0x8005C32Cu: goto label_8005C32C;
    case 0x8005C330u: goto label_8005C330;
    case 0x8005C334u: goto label_8005C334;
    case 0x8005C338u: goto label_8005C338;
    case 0x8005C33Cu: goto label_8005C33C;
    case 0x8005C340u: goto label_8005C340;
    case 0x8005C344u: goto label_8005C344;
    case 0x8005C348u: goto label_8005C348;
    case 0x8005C34Cu: goto label_8005C34C;
    case 0x8005C350u: goto label_8005C350;
    case 0x8005C354u: goto label_8005C354;
    case 0x8005C358u: goto label_8005C358;
    case 0x8005C35Cu: goto label_8005C35C;
    case 0x8005C360u: goto label_8005C360;
    case 0x8005C364u: goto label_8005C364;
    case 0x8005C368u: goto label_8005C368;
    case 0x8005C36Cu: goto label_8005C36C;
    case 0x8005C370u: goto label_8005C370;
    case 0x8005C374u: goto label_8005C374;
    case 0x8005C378u: goto label_8005C378;
    case 0x8005C37Cu: goto label_8005C37C;
    case 0x8005C380u: goto label_8005C380;
    case 0x8005C384u: goto label_8005C384;
    case 0x8005C388u: goto label_8005C388;
    case 0x8005C38Cu: goto label_8005C38C;
    case 0x8005C390u: goto label_8005C390;
    case 0x8005C394u: goto label_8005C394;
    case 0x8005C398u: goto label_8005C398;
    case 0x8005C39Cu: goto label_8005C39C;
    case 0x8005C3A0u: goto label_8005C3A0;
    case 0x8005C3A4u: goto label_8005C3A4;
    case 0x8005C3A8u: goto label_8005C3A8;
    case 0x8005C3ACu: goto label_8005C3AC;
    case 0x8005C3B0u: goto label_8005C3B0;
    case 0x8005C3B4u: goto label_8005C3B4;
    case 0x8005C3B8u: goto label_8005C3B8;
    case 0x8005C3BCu: goto label_8005C3BC;
    case 0x8005C3C0u: goto label_8005C3C0;
    case 0x8005C3C4u: goto label_8005C3C4;
    case 0x8005C3C8u: goto label_8005C3C8;
    case 0x8005C3CCu: goto label_8005C3CC;
    case 0x8005C3D0u: goto label_8005C3D0;
    case 0x8005C3D4u: goto label_8005C3D4;
    case 0x8005C3D8u: goto label_8005C3D8;
    case 0x8005C3DCu: goto label_8005C3DC;
    case 0x8005C3E0u: goto label_8005C3E0;
    case 0x8005C3E4u: goto label_8005C3E4;
    case 0x8005C3E8u: goto label_8005C3E8;
    case 0x8005C3ECu: goto label_8005C3EC;
    case 0x8005C3F0u: goto label_8005C3F0;
    case 0x8005C3F4u: goto label_8005C3F4;
    case 0x8005C3F8u: goto label_8005C3F8;
    case 0x8005C3FCu: goto label_8005C3FC;
    case 0x8005C400u: goto label_8005C400;
    case 0x8005C404u: goto label_8005C404;
    case 0x8005C408u: goto label_8005C408;
    case 0x8005C40Cu: goto label_8005C40C;
    case 0x8005C410u: goto label_8005C410;
    case 0x8005C414u: goto label_8005C414;
    case 0x8005C418u: goto label_8005C418;
    case 0x8005C41Cu: goto label_8005C41C;
    case 0x8005C420u: goto label_8005C420;
    case 0x8005C424u: goto label_8005C424;
    case 0x8005C428u: goto label_8005C428;
    case 0x8005C42Cu: goto label_8005C42C;
    case 0x8005C430u: goto label_8005C430;
    case 0x8005C434u: goto label_8005C434;
    case 0x8005C438u: goto label_8005C438;
    case 0x8005C43Cu: goto label_8005C43C;
    case 0x8005C440u: goto label_8005C440;
    case 0x8005C444u: goto label_8005C444;
    case 0x8005C448u: goto label_8005C448;
    case 0x8005C44Cu: goto label_8005C44C;
    case 0x8005C450u: goto label_8005C450;
    case 0x8005C454u: goto label_8005C454;
    case 0x8005C458u: goto label_8005C458;
    case 0x8005C45Cu: goto label_8005C45C;
    case 0x8005C460u: goto label_8005C460;
    case 0x8005C464u: goto label_8005C464;
    case 0x8005C468u: goto label_8005C468;
    case 0x8005C46Cu: goto label_8005C46C;
    case 0x8005C470u: goto label_8005C470;
    case 0x8005C474u: goto label_8005C474;
    case 0x8005C478u: goto label_8005C478;
    case 0x8005C47Cu: goto label_8005C47C;
    case 0x8005C480u: goto label_8005C480;
    case 0x8005C484u: goto label_8005C484;
    case 0x8005C488u: goto label_8005C488;
    case 0x8005C48Cu: goto label_8005C48C;
    case 0x8005C490u: goto label_8005C490;
    case 0x8005C494u: goto label_8005C494;
    case 0x8005C498u: goto label_8005C498;
    case 0x8005C49Cu: goto label_8005C49C;
    case 0x8005C4A0u: goto label_8005C4A0;
    case 0x8005C4A4u: goto label_8005C4A4;
    case 0x8005C4A8u: goto label_8005C4A8;
    case 0x8005C4ACu: goto label_8005C4AC;
    case 0x8005C4B0u: goto label_8005C4B0;
    case 0x8005C4B4u: goto label_8005C4B4;
    case 0x8005C4B8u: goto label_8005C4B8;
    case 0x8005C4BCu: goto label_8005C4BC;
    case 0x8005C4C0u: goto label_8005C4C0;
    case 0x8005C4C4u: goto label_8005C4C4;
    case 0x8005C4C8u: goto label_8005C4C8;
    case 0x8005C4CCu: goto label_8005C4CC;
    case 0x8005C4D0u: goto label_8005C4D0;
    case 0x8005C4D4u: goto label_8005C4D4;
    case 0x8005C4D8u: goto label_8005C4D8;
    case 0x8005C4DCu: goto label_8005C4DC;
    case 0x8005C4E0u: goto label_8005C4E0;
    case 0x8005C4E4u: goto label_8005C4E4;
    case 0x8005C4E8u: goto label_8005C4E8;
    case 0x8005C4ECu: goto label_8005C4EC;
    case 0x8005C4F0u: goto label_8005C4F0;
    case 0x8005C4F4u: goto label_8005C4F4;
    case 0x8005C4F8u: goto label_8005C4F8;
    case 0x8005C4FCu: goto label_8005C4FC;
    case 0x8005C500u: goto label_8005C500;
    case 0x8005C504u: goto label_8005C504;
    case 0x8005C508u: goto label_8005C508;
    case 0x8005C50Cu: goto label_8005C50C;
    case 0x8005C510u: goto label_8005C510;
    case 0x8005C514u: goto label_8005C514;
    case 0x8005C518u: goto label_8005C518;
    case 0x8005C51Cu: goto label_8005C51C;
    case 0x8005C520u: goto label_8005C520;
    case 0x8005C524u: goto label_8005C524;
    case 0x8005C528u: goto label_8005C528;
    case 0x8005C52Cu: goto label_8005C52C;
    case 0x8005C530u: goto label_8005C530;
    case 0x8005C534u: goto label_8005C534;
    case 0x8005C538u: goto label_8005C538;
    case 0x8005C53Cu: goto label_8005C53C;
    case 0x8005C540u: goto label_8005C540;
    case 0x8005C544u: goto label_8005C544;
    case 0x8005C548u: goto label_8005C548;
    case 0x8005C54Cu: goto label_8005C54C;
    case 0x8005C550u: goto label_8005C550;
    case 0x8005C554u: goto label_8005C554;
    case 0x8005C558u: goto label_8005C558;
    case 0x8005C55Cu: goto label_8005C55C;
    case 0x8005C560u: goto label_8005C560;
    case 0x8005C564u: goto label_8005C564;
    case 0x8005C568u: goto label_8005C568;
    case 0x8005C56Cu: goto label_8005C56C;
    case 0x8005C570u: goto label_8005C570;
    case 0x8005C574u: goto label_8005C574;
    case 0x8005C578u: goto label_8005C578;
    case 0x8005C57Cu: goto label_8005C57C;
    case 0x8005C580u: goto label_8005C580;
    case 0x8005C584u: goto label_8005C584;
    case 0x8005C588u: goto label_8005C588;
    case 0x8005C58Cu: goto label_8005C58C;
    case 0x8005C590u: goto label_8005C590;
    case 0x8005C594u: goto label_8005C594;
    case 0x8005C598u: goto label_8005C598;
    case 0x8005C59Cu: goto label_8005C59C;
    case 0x8005C5A0u: goto label_8005C5A0;
    case 0x8005C5A4u: goto label_8005C5A4;
    case 0x8005C5A8u: goto label_8005C5A8;
    case 0x8005C5ACu: goto label_8005C5AC;
    case 0x8005C5B0u: goto label_8005C5B0;
    case 0x8005C5B4u: goto label_8005C5B4;
    case 0x8005C5B8u: goto label_8005C5B8;
    case 0x8005C5BCu: goto label_8005C5BC;
    case 0x8005C5C0u: goto label_8005C5C0;
    case 0x8005C5C4u: goto label_8005C5C4;
    case 0x8005C5C8u: goto label_8005C5C8;
    case 0x8005C5CCu: goto label_8005C5CC;
    case 0x8005C5D0u: goto label_8005C5D0;
    case 0x8005C5D4u: goto label_8005C5D4;
    case 0x8005C5D8u: goto label_8005C5D8;
    case 0x8005C5DCu: goto label_8005C5DC;
    case 0x8005C5E0u: goto label_8005C5E0;
    case 0x8005C5E4u: goto label_8005C5E4;
    case 0x8005C5E8u: goto label_8005C5E8;
    case 0x8005C5ECu: goto label_8005C5EC;
    case 0x8005C5F0u: goto label_8005C5F0;
    case 0x8005C5F4u: goto label_8005C5F4;
    case 0x8005C5F8u: goto label_8005C5F8;
    case 0x8005C5FCu: goto label_8005C5FC;
    case 0x8005C600u: goto label_8005C600;
    case 0x8005C604u: goto label_8005C604;
    case 0x8005C608u: goto label_8005C608;
    case 0x8005C60Cu: goto label_8005C60C;
    case 0x8005C610u: goto label_8005C610;
    case 0x8005C614u: goto label_8005C614;
    case 0x8005C618u: goto label_8005C618;
    case 0x8005C61Cu: goto label_8005C61C;
    case 0x8005C620u: goto label_8005C620;
    case 0x8005C624u: goto label_8005C624;
    case 0x8005C628u: goto label_8005C628;
    case 0x8005C62Cu: goto label_8005C62C;
    case 0x8005C630u: goto label_8005C630;
    case 0x8005C634u: goto label_8005C634;
    case 0x8005C638u: goto label_8005C638;
    case 0x8005C63Cu: goto label_8005C63C;
    case 0x8005C640u: goto label_8005C640;
    case 0x8005C644u: goto label_8005C644;
    case 0x8005C648u: goto label_8005C648;
    case 0x8005C64Cu: goto label_8005C64C;
    case 0x8005C650u: goto label_8005C650;
    case 0x8005C654u: goto label_8005C654;
    case 0x8005C658u: goto label_8005C658;
    case 0x8005C65Cu: goto label_8005C65C;
    case 0x8005C660u: goto label_8005C660;
    case 0x8005C664u: goto label_8005C664;
    case 0x8005C668u: goto label_8005C668;
    case 0x8005C66Cu: goto label_8005C66C;
    case 0x8005C670u: goto label_8005C670;
    case 0x8005C674u: goto label_8005C674;
    case 0x8005C678u: goto label_8005C678;
    case 0x8005C67Cu: goto label_8005C67C;
    case 0x8005C680u: goto label_8005C680;
    case 0x8005C684u: goto label_8005C684;
    case 0x8005C688u: goto label_8005C688;
    case 0x8005C68Cu: goto label_8005C68C;
    case 0x8005C690u: goto label_8005C690;
    case 0x8005C694u: goto label_8005C694;
    case 0x8005C698u: goto label_8005C698;
    case 0x8005C69Cu: goto label_8005C69C;
    case 0x8005C6A0u: goto label_8005C6A0;
    case 0x8005C6A4u: goto label_8005C6A4;
    case 0x8005C6A8u: goto label_8005C6A8;
    case 0x8005C6ACu: goto label_8005C6AC;
    case 0x8005C6B0u: goto label_8005C6B0;
    case 0x8005C6B4u: goto label_8005C6B4;
    case 0x8005C6B8u: goto label_8005C6B8;
    case 0x8005C6BCu: goto label_8005C6BC;
    case 0x8005C6C0u: goto label_8005C6C0;
    case 0x8005C6C4u: goto label_8005C6C4;
    case 0x8005C6C8u: goto label_8005C6C8;
    case 0x8005C6CCu: goto label_8005C6CC;
    case 0x8005C6D0u: goto label_8005C6D0;
    case 0x8005C6D4u: goto label_8005C6D4;
    case 0x8005C6D8u: goto label_8005C6D8;
    case 0x8005C6DCu: goto label_8005C6DC;
    case 0x8005C6E0u: goto label_8005C6E0;
    case 0x8005C6E4u: goto label_8005C6E4;
    case 0x8005C6E8u: goto label_8005C6E8;
    case 0x8005C6ECu: goto label_8005C6EC;
    case 0x8005C6F0u: goto label_8005C6F0;
    case 0x8005C6F4u: goto label_8005C6F4;
    case 0x8005C6F8u: goto label_8005C6F8;
    case 0x8005C6FCu: goto label_8005C6FC;
    case 0x8005C700u: goto label_8005C700;
    case 0x8005C704u: goto label_8005C704;
    case 0x8005C708u: goto label_8005C708;
    case 0x8005C70Cu: goto label_8005C70C;
    case 0x8005C710u: goto label_8005C710;
    case 0x8005C714u: goto label_8005C714;
    case 0x8005C718u: goto label_8005C718;
    case 0x8005C71Cu: goto label_8005C71C;
    case 0x8005C720u: goto label_8005C720;
    case 0x8005C724u: goto label_8005C724;
    case 0x8005C728u: goto label_8005C728;
    case 0x8005C72Cu: goto label_8005C72C;
    case 0x8005C730u: goto label_8005C730;
    case 0x8005C734u: goto label_8005C734;
    case 0x8005C738u: goto label_8005C738;
    case 0x8005C73Cu: goto label_8005C73C;
    case 0x8005C740u: goto label_8005C740;
    case 0x8005C744u: goto label_8005C744;
    case 0x8005C748u: goto label_8005C748;
    case 0x8005C74Cu: goto label_8005C74C;
    case 0x8005C750u: goto label_8005C750;
    case 0x8005C754u: goto label_8005C754;
    case 0x8005C758u: goto label_8005C758;
    case 0x8005C75Cu: goto label_8005C75C;
    case 0x8005C760u: goto label_8005C760;
    case 0x8005C764u: goto label_8005C764;
    case 0x8005C768u: goto label_8005C768;
    case 0x8005C76Cu: goto label_8005C76C;
    case 0x8005C770u: goto label_8005C770;
    case 0x8005C774u: goto label_8005C774;
    case 0x8005C778u: goto label_8005C778;
    case 0x8005C77Cu: goto label_8005C77C;
    case 0x8005C780u: goto label_8005C780;
    case 0x8005C784u: goto label_8005C784;
    case 0x8005C788u: goto label_8005C788;
    case 0x8005C78Cu: goto label_8005C78C;
    case 0x8005C790u: goto label_8005C790;
    case 0x8005C794u: goto label_8005C794;
    case 0x8005C798u: goto label_8005C798;
    case 0x8005C79Cu: goto label_8005C79C;
    case 0x8005C7A0u: goto label_8005C7A0;
    case 0x8005C7A4u: goto label_8005C7A4;
    case 0x8005C7A8u: goto label_8005C7A8;
    case 0x8005C7ACu: goto label_8005C7AC;
    case 0x8005C7B0u: goto label_8005C7B0;
    case 0x8005C7B4u: goto label_8005C7B4;
    case 0x8005C7B8u: goto label_8005C7B8;
    case 0x8005C7BCu: goto label_8005C7BC;
    case 0x8005C7C0u: goto label_8005C7C0;
    case 0x8005C7C4u: goto label_8005C7C4;
    case 0x8005C7C8u: goto label_8005C7C8;
    case 0x8005C7CCu: goto label_8005C7CC;
    case 0x8005C7D0u: goto label_8005C7D0;
    case 0x8005C7D4u: goto label_8005C7D4;
    case 0x8005C7D8u: goto label_8005C7D8;
    case 0x8005C7DCu: goto label_8005C7DC;
    case 0x8005C7E0u: goto label_8005C7E0;
    case 0x8005C7E4u: goto label_8005C7E4;
    case 0x8005C7E8u: goto label_8005C7E8;
    case 0x8005C7ECu: goto label_8005C7EC;
    case 0x8005C7F0u: goto label_8005C7F0;
    case 0x8005C7F4u: goto label_8005C7F4;
    case 0x8005C7F8u: goto label_8005C7F8;
    case 0x8005C7FCu: goto label_8005C7FC;
    case 0x8005C800u: goto label_8005C800;
    case 0x8005C804u: goto label_8005C804;
    case 0x8005C808u: goto label_8005C808;
    case 0x8005C80Cu: goto label_8005C80C;
    case 0x8005C810u: goto label_8005C810;
    case 0x8005C814u: goto label_8005C814;
    case 0x8005C818u: goto label_8005C818;
    case 0x8005C81Cu: goto label_8005C81C;
    case 0x8005C820u: goto label_8005C820;
    case 0x8005C824u: goto label_8005C824;
    case 0x8005C828u: goto label_8005C828;
    case 0x8005C82Cu: goto label_8005C82C;
    case 0x8005C830u: goto label_8005C830;
    case 0x8005C834u: goto label_8005C834;
    case 0x8005C838u: goto label_8005C838;
    case 0x8005C83Cu: goto label_8005C83C;
    case 0x8005C840u: goto label_8005C840;
    case 0x8005C844u: goto label_8005C844;
    case 0x8005C848u: goto label_8005C848;
    case 0x8005C84Cu: goto label_8005C84C;
    case 0x8005C850u: goto label_8005C850;
    case 0x8005C854u: goto label_8005C854;
    case 0x8005C858u: goto label_8005C858;
    case 0x8005C85Cu: goto label_8005C85C;
    case 0x8005C860u: goto label_8005C860;
    case 0x8005C864u: goto label_8005C864;
    case 0x8005C868u: goto label_8005C868;
    case 0x8005C86Cu: goto label_8005C86C;
    case 0x8005C870u: goto label_8005C870;
    case 0x8005C874u: goto label_8005C874;
    case 0x8005C878u: goto label_8005C878;
    case 0x8005C87Cu: goto label_8005C87C;
    case 0x8005C880u: goto label_8005C880;
    case 0x8005C884u: goto label_8005C884;
    case 0x8005C888u: goto label_8005C888;
    case 0x8005C88Cu: goto label_8005C88C;
    case 0x8005C890u: goto label_8005C890;
    case 0x8005C894u: goto label_8005C894;
    case 0x8005C898u: goto label_8005C898;
    case 0x8005C89Cu: goto label_8005C89C;
    case 0x8005C8A0u: goto label_8005C8A0;
    case 0x8005C8A4u: goto label_8005C8A4;
    case 0x8005C8A8u: goto label_8005C8A8;
    case 0x8005C8ACu: goto label_8005C8AC;
    case 0x8005C8B0u: goto label_8005C8B0;
    case 0x8005C8B4u: goto label_8005C8B4;
    case 0x8005C8B8u: goto label_8005C8B8;
    case 0x8005C8BCu: goto label_8005C8BC;
    case 0x8005C8C0u: goto label_8005C8C0;
    case 0x8005C8C4u: goto label_8005C8C4;
    case 0x8005C8C8u: goto label_8005C8C8;
    case 0x8005C8CCu: goto label_8005C8CC;
    case 0x8005C8D0u: goto label_8005C8D0;
    case 0x8005C8D4u: goto label_8005C8D4;
    case 0x8005C8D8u: goto label_8005C8D8;
    case 0x8005C8DCu: goto label_8005C8DC;
    case 0x8005C8E0u: goto label_8005C8E0;
    case 0x8005C8E4u: goto label_8005C8E4;
    case 0x8005C8E8u: goto label_8005C8E8;
    case 0x8005C8ECu: goto label_8005C8EC;
    case 0x8005C8F0u: goto label_8005C8F0;
    case 0x8005C8F4u: goto label_8005C8F4;
    case 0x8005C8F8u: goto label_8005C8F8;
    case 0x8005C8FCu: goto label_8005C8FC;
    case 0x8005C900u: goto label_8005C900;
    case 0x8005C904u: goto label_8005C904;
    case 0x8005C908u: goto label_8005C908;
    case 0x8005C90Cu: goto label_8005C90C;
    case 0x8005C910u: goto label_8005C910;
    case 0x8005C914u: goto label_8005C914;
    case 0x8005C918u: goto label_8005C918;
    case 0x8005C91Cu: goto label_8005C91C;
    case 0x8005C920u: goto label_8005C920;
    case 0x8005C924u: goto label_8005C924;
    case 0x8005C928u: goto label_8005C928;
    case 0x8005C92Cu: goto label_8005C92C;
    case 0x8005C930u: goto label_8005C930;
    case 0x8005C934u: goto label_8005C934;
    case 0x8005C938u: goto label_8005C938;
    case 0x8005C93Cu: goto label_8005C93C;
    case 0x8005C940u: goto label_8005C940;
    case 0x8005C944u: goto label_8005C944;
    case 0x8005C948u: goto label_8005C948;
    case 0x8005C94Cu: goto label_8005C94C;
    case 0x8005C950u: goto label_8005C950;
    case 0x8005C954u: goto label_8005C954;
    case 0x8005C958u: goto label_8005C958;
    case 0x8005C95Cu: goto label_8005C95C;
    case 0x8005C960u: goto label_8005C960;
    case 0x8005C964u: goto label_8005C964;
    case 0x8005C968u: goto label_8005C968;
    case 0x8005C96Cu: goto label_8005C96C;
    case 0x8005C970u: goto label_8005C970;
    case 0x8005C974u: goto label_8005C974;
    case 0x8005C978u: goto label_8005C978;
    case 0x8005C97Cu: goto label_8005C97C;
    case 0x8005C980u: goto label_8005C980;
    case 0x8005C984u: goto label_8005C984;
    case 0x8005C988u: goto label_8005C988;
    case 0x8005C98Cu: goto label_8005C98C;
    case 0x8005C990u: goto label_8005C990;
    case 0x8005C994u: goto label_8005C994;
    case 0x8005C998u: goto label_8005C998;
    case 0x8005C99Cu: goto label_8005C99C;
    case 0x8005C9A0u: goto label_8005C9A0;
    case 0x8005C9A4u: goto label_8005C9A4;
    case 0x8005C9A8u: goto label_8005C9A8;
    case 0x8005C9ACu: goto label_8005C9AC;
    case 0x8005C9B0u: goto label_8005C9B0;
    case 0x8005C9B4u: goto label_8005C9B4;
    case 0x8005C9B8u: goto label_8005C9B8;
    case 0x8005C9BCu: goto label_8005C9BC;
    case 0x8005C9C0u: goto label_8005C9C0;
    case 0x8005C9C4u: goto label_8005C9C4;
    case 0x8005C9C8u: goto label_8005C9C8;
    case 0x8005C9CCu: goto label_8005C9CC;
    case 0x8005C9D0u: goto label_8005C9D0;
    case 0x8005C9D4u: goto label_8005C9D4;
    case 0x8005C9D8u: goto label_8005C9D8;
    case 0x8005C9DCu: goto label_8005C9DC;
    case 0x8005C9E0u: goto label_8005C9E0;
    case 0x8005C9E4u: goto label_8005C9E4;
    case 0x8005C9E8u: goto label_8005C9E8;
    case 0x8005C9ECu: goto label_8005C9EC;
    case 0x8005C9F0u: goto label_8005C9F0;
    case 0x8005C9F4u: goto label_8005C9F4;
    case 0x8005C9F8u: goto label_8005C9F8;
    case 0x8005C9FCu: goto label_8005C9FC;
    case 0x8005CA00u: goto label_8005CA00;
    case 0x8005CA04u: goto label_8005CA04;
    case 0x8005CA08u: goto label_8005CA08;
    case 0x8005CA0Cu: goto label_8005CA0C;
    case 0x8005CA10u: goto label_8005CA10;
    case 0x8005CA14u: goto label_8005CA14;
    case 0x8005CA18u: goto label_8005CA18;
    case 0x8005CA1Cu: goto label_8005CA1C;
    case 0x8005CA20u: goto label_8005CA20;
    case 0x8005CA24u: goto label_8005CA24;
    case 0x8005CA28u: goto label_8005CA28;
    case 0x8005CA2Cu: goto label_8005CA2C;
    case 0x8005CA30u: goto label_8005CA30;
    case 0x8005CA34u: goto label_8005CA34;
    case 0x8005CA38u: goto label_8005CA38;
    case 0x8005CA3Cu: goto label_8005CA3C;
    case 0x8005CA40u: goto label_8005CA40;
    case 0x8005CA44u: goto label_8005CA44;
    case 0x8005CA48u: goto label_8005CA48;
    case 0x8005CA4Cu: goto label_8005CA4C;
    case 0x8005CA50u: goto label_8005CA50;
    case 0x8005CA54u: goto label_8005CA54;
    case 0x8005CA58u: goto label_8005CA58;
    case 0x8005CA5Cu: goto label_8005CA5C;
    case 0x8005CA60u: goto label_8005CA60;
    case 0x8005CA64u: goto label_8005CA64;
    case 0x8005CA68u: goto label_8005CA68;
    case 0x8005CA6Cu: goto label_8005CA6C;
    case 0x8005CA70u: goto label_8005CA70;
    case 0x8005CA74u: goto label_8005CA74;
    case 0x8005CA78u: goto label_8005CA78;
    case 0x8005CA7Cu: goto label_8005CA7C;
    case 0x8005CA80u: goto label_8005CA80;
    case 0x8005CA84u: goto label_8005CA84;
    case 0x8005CA88u: goto label_8005CA88;
    case 0x8005CA8Cu: goto label_8005CA8C;
    case 0x8005CA90u: goto label_8005CA90;
    case 0x8005CA94u: goto label_8005CA94;
    case 0x8005CA98u: goto label_8005CA98;
    case 0x8005CA9Cu: goto label_8005CA9C;
    case 0x8005CAA0u: goto label_8005CAA0;
    case 0x8005CAA4u: goto label_8005CAA4;
    case 0x8005CAA8u: goto label_8005CAA8;
    case 0x8005CAACu: goto label_8005CAAC;
    case 0x8005CAB0u: goto label_8005CAB0;
    case 0x8005CAB4u: goto label_8005CAB4;
    case 0x8005CAB8u: goto label_8005CAB8;
    case 0x8005CABCu: goto label_8005CABC;
    case 0x8005CAC0u: goto label_8005CAC0;
    case 0x8005CAC4u: goto label_8005CAC4;
    case 0x8005CAC8u: goto label_8005CAC8;
    case 0x8005CACCu: goto label_8005CACC;
    case 0x8005CAD0u: goto label_8005CAD0;
    case 0x8005CAD4u: goto label_8005CAD4;
    case 0x8005CAD8u: goto label_8005CAD8;
    case 0x8005CADCu: goto label_8005CADC;
    case 0x8005CAE0u: goto label_8005CAE0;
    case 0x8005CAE4u: goto label_8005CAE4;
    case 0x8005CAE8u: goto label_8005CAE8;
    case 0x8005CAECu: goto label_8005CAEC;
    case 0x8005CAF0u: goto label_8005CAF0;
    case 0x8005CAF4u: goto label_8005CAF4;
    case 0x8005CAF8u: goto label_8005CAF8;
    case 0x8005CAFCu: goto label_8005CAFC;
    case 0x8005CB00u: goto label_8005CB00;
    case 0x8005CB04u: goto label_8005CB04;
    case 0x8005CB08u: goto label_8005CB08;
    case 0x8005CB0Cu: goto label_8005CB0C;
    case 0x8005CB10u: goto label_8005CB10;
    case 0x8005CB14u: goto label_8005CB14;
    case 0x8005CB18u: goto label_8005CB18;
    case 0x8005CB1Cu: goto label_8005CB1C;
    case 0x8005CB20u: goto label_8005CB20;
    case 0x8005CB24u: goto label_8005CB24;
    case 0x8005CB28u: goto label_8005CB28;
    case 0x8005CB2Cu: goto label_8005CB2C;
    case 0x8005CB30u: goto label_8005CB30;
    case 0x8005CB34u: goto label_8005CB34;
    case 0x8005CB38u: goto label_8005CB38;
    case 0x8005CB3Cu: goto label_8005CB3C;
    case 0x8005CB40u: goto label_8005CB40;
    case 0x8005CB44u: goto label_8005CB44;
    case 0x8005CB48u: goto label_8005CB48;
    case 0x8005CB4Cu: goto label_8005CB4C;
    case 0x8005CB50u: goto label_8005CB50;
    case 0x8005CB54u: goto label_8005CB54;
    case 0x8005CB58u: goto label_8005CB58;
    case 0x8005CB5Cu: goto label_8005CB5C;
    case 0x8005CB60u: goto label_8005CB60;
    case 0x8005CB64u: goto label_8005CB64;
    case 0x8005CB68u: goto label_8005CB68;
    case 0x8005CB6Cu: goto label_8005CB6C;
    case 0x8005CB70u: goto label_8005CB70;
    case 0x8005CB74u: goto label_8005CB74;
    case 0x8005CB78u: goto label_8005CB78;
    case 0x8005CB7Cu: goto label_8005CB7C;
    case 0x8005CB80u: goto label_8005CB80;
    case 0x8005CB84u: goto label_8005CB84;
    case 0x8005CB88u: goto label_8005CB88;
    case 0x8005CB8Cu: goto label_8005CB8C;
    case 0x8005CB90u: goto label_8005CB90;
    case 0x8005CB94u: goto label_8005CB94;
    case 0x8005CB98u: goto label_8005CB98;
    case 0x8005CB9Cu: goto label_8005CB9C;
    case 0x8005CBA0u: goto label_8005CBA0;
    case 0x8005CBA4u: goto label_8005CBA4;
    case 0x8005CBA8u: goto label_8005CBA8;
    case 0x8005CBACu: goto label_8005CBAC;
    case 0x8005CBB0u: goto label_8005CBB0;
    case 0x8005CBB4u: goto label_8005CBB4;
    case 0x8005CBB8u: goto label_8005CBB8;
    case 0x8005CBBCu: goto label_8005CBBC;
    case 0x8005CBC0u: goto label_8005CBC0;
    case 0x8005CBC4u: goto label_8005CBC4;
    case 0x8005CBC8u: goto label_8005CBC8;
    case 0x8005CBCCu: goto label_8005CBCC;
    case 0x8005CBD0u: goto label_8005CBD0;
    case 0x8005CBD4u: goto label_8005CBD4;
    case 0x8005CBD8u: goto label_8005CBD8;
    case 0x8005CBDCu: goto label_8005CBDC;
    case 0x8005CBE0u: goto label_8005CBE0;
    case 0x8005CBE4u: goto label_8005CBE4;
    case 0x8005CBE8u: goto label_8005CBE8;
    case 0x8005CBECu: goto label_8005CBEC;
    case 0x8005CBF0u: goto label_8005CBF0;
    case 0x8005CBF4u: goto label_8005CBF4;
    case 0x8005CBF8u: goto label_8005CBF8;
    case 0x8005CBFCu: goto label_8005CBFC;
    case 0x8005CC00u: goto label_8005CC00;
    case 0x8005CC04u: goto label_8005CC04;
    case 0x8005CC08u: goto label_8005CC08;
    case 0x8005CC0Cu: goto label_8005CC0C;
    case 0x8005CC10u: goto label_8005CC10;
    case 0x8005CC14u: goto label_8005CC14;
    case 0x8005CC18u: goto label_8005CC18;
    case 0x8005CC1Cu: goto label_8005CC1C;
    case 0x8005CC20u: goto label_8005CC20;
    case 0x8005CC24u: goto label_8005CC24;
    case 0x8005CC28u: goto label_8005CC28;
    case 0x8005CC2Cu: goto label_8005CC2C;
    case 0x8005CC30u: goto label_8005CC30;
    case 0x8005CC34u: goto label_8005CC34;
    case 0x8005CC38u: goto label_8005CC38;
    case 0x8005CC3Cu: goto label_8005CC3C;
    case 0x8005CC40u: goto label_8005CC40;
    case 0x8005CC44u: goto label_8005CC44;
    case 0x8005CC48u: goto label_8005CC48;
    case 0x8005CC4Cu: goto label_8005CC4C;
    case 0x8005CC50u: goto label_8005CC50;
    case 0x8005CC54u: goto label_8005CC54;
    case 0x8005CC58u: goto label_8005CC58;
    case 0x8005CC5Cu: goto label_8005CC5C;
    case 0x8005CC60u: goto label_8005CC60;
    case 0x8005CC64u: goto label_8005CC64;
    case 0x8005CC68u: goto label_8005CC68;
    case 0x8005CC6Cu: goto label_8005CC6C;
    case 0x8005CC70u: goto label_8005CC70;
    case 0x8005CC74u: goto label_8005CC74;
    case 0x8005CC78u: goto label_8005CC78;
    case 0x8005CC7Cu: goto label_8005CC7C;
    case 0x8005CC80u: goto label_8005CC80;
    case 0x8005CC84u: goto label_8005CC84;
    case 0x8005CC88u: goto label_8005CC88;
    case 0x8005CC8Cu: goto label_8005CC8C;
    case 0x8005CC90u: goto label_8005CC90;
    case 0x8005CC94u: goto label_8005CC94;
    case 0x8005CC98u: goto label_8005CC98;
    case 0x8005CC9Cu: goto label_8005CC9C;
    case 0x8005CCA0u: goto label_8005CCA0;
    case 0x8005CCA4u: goto label_8005CCA4;
    case 0x8005CCA8u: goto label_8005CCA8;
    case 0x8005CCACu: goto label_8005CCAC;
    case 0x8005CCB0u: goto label_8005CCB0;
    case 0x8005CCB4u: goto label_8005CCB4;
    case 0x8005CCB8u: goto label_8005CCB8;
    case 0x8005CCBCu: goto label_8005CCBC;
    case 0x8005CCC0u: goto label_8005CCC0;
    case 0x8005CCC4u: goto label_8005CCC4;
    case 0x8005CCC8u: goto label_8005CCC8;
    case 0x8005CCCCu: goto label_8005CCCC;
    case 0x8005CCD0u: goto label_8005CCD0;
    case 0x8005CCD4u: goto label_8005CCD4;
    case 0x8005CCD8u: goto label_8005CCD8;
    case 0x8005CCDCu: goto label_8005CCDC;
    case 0x8005CCE0u: goto label_8005CCE0;
    case 0x8005CCE4u: goto label_8005CCE4;
    case 0x8005CCE8u: goto label_8005CCE8;
    case 0x8005CCECu: goto label_8005CCEC;
    case 0x8005CCF0u: goto label_8005CCF0;
    case 0x8005CCF4u: goto label_8005CCF4;
    case 0x8005CCF8u: goto label_8005CCF8;
    case 0x8005CCFCu: goto label_8005CCFC;
    case 0x8005CD00u: goto label_8005CD00;
    case 0x8005CD04u: goto label_8005CD04;
    case 0x8005CD08u: goto label_8005CD08;
    case 0x8005CD0Cu: goto label_8005CD0C;
    case 0x8005CD10u: goto label_8005CD10;
    case 0x8005CD14u: goto label_8005CD14;
    case 0x8005CD18u: goto label_8005CD18;
    case 0x8005CD1Cu: goto label_8005CD1C;
    case 0x8005CD20u: goto label_8005CD20;
    case 0x8005CD24u: goto label_8005CD24;
    case 0x8005CD28u: goto label_8005CD28;
    case 0x8005CD2Cu: goto label_8005CD2C;
    case 0x8005CD30u: goto label_8005CD30;
    case 0x8005CD34u: goto label_8005CD34;
    case 0x8005CD38u: goto label_8005CD38;
    case 0x8005CD3Cu: goto label_8005CD3C;
    case 0x8005CD40u: goto label_8005CD40;
    case 0x8005CD44u: goto label_8005CD44;
    case 0x8005CD48u: goto label_8005CD48;
    case 0x8005CD4Cu: goto label_8005CD4C;
    case 0x8005CD50u: goto label_8005CD50;
    case 0x8005CD54u: goto label_8005CD54;
    case 0x8005CD58u: goto label_8005CD58;
    case 0x8005CD5Cu: goto label_8005CD5C;
    case 0x8005CD60u: goto label_8005CD60;
    case 0x8005CD64u: goto label_8005CD64;
    case 0x8005CD68u: goto label_8005CD68;
    case 0x8005CD6Cu: goto label_8005CD6C;
    case 0x8005CD70u: goto label_8005CD70;
    case 0x8005CD74u: goto label_8005CD74;
    case 0x8005CD78u: goto label_8005CD78;
    case 0x8005CD7Cu: goto label_8005CD7C;
    case 0x8005CD80u: goto label_8005CD80;
    case 0x8005CD84u: goto label_8005CD84;
    case 0x8005CD88u: goto label_8005CD88;
    case 0x8005CD8Cu: goto label_8005CD8C;
    case 0x8005CD90u: goto label_8005CD90;
    case 0x8005CD94u: goto label_8005CD94;
    case 0x8005CD98u: goto label_8005CD98;
    case 0x8005CD9Cu: goto label_8005CD9C;
    case 0x8005CDA0u: goto label_8005CDA0;
    case 0x8005CDA4u: goto label_8005CDA4;
    case 0x8005CDA8u: goto label_8005CDA8;
    case 0x8005CDACu: goto label_8005CDAC;
    case 0x8005CDB0u: goto label_8005CDB0;
    case 0x8005CDB4u: goto label_8005CDB4;
    case 0x8005CDB8u: goto label_8005CDB8;
    case 0x8005CDBCu: goto label_8005CDBC;
    case 0x8005CDC0u: goto label_8005CDC0;
    case 0x8005CDC4u: goto label_8005CDC4;
    case 0x8005CDC8u: goto label_8005CDC8;
    case 0x8005CDCCu: goto label_8005CDCC;
    case 0x8005CDD0u: goto label_8005CDD0;
    case 0x8005CDD4u: goto label_8005CDD4;
    case 0x8005CDD8u: goto label_8005CDD8;
    case 0x8005CDDCu: goto label_8005CDDC;
    case 0x8005CDE0u: goto label_8005CDE0;
    case 0x8005CDE4u: goto label_8005CDE4;
    case 0x8005CDE8u: goto label_8005CDE8;
    case 0x8005CDECu: goto label_8005CDEC;
    case 0x8005CDF0u: goto label_8005CDF0;
    case 0x8005CDF4u: goto label_8005CDF4;
    case 0x8005CDF8u: goto label_8005CDF8;
    case 0x8005CDFCu: goto label_8005CDFC;
    case 0x8005CE00u: goto label_8005CE00;
    case 0x8005CE04u: goto label_8005CE04;
    case 0x8005CE08u: goto label_8005CE08;
    case 0x8005CE0Cu: goto label_8005CE0C;
    case 0x8005CE10u: goto label_8005CE10;
    case 0x8005CE14u: goto label_8005CE14;
    case 0x8005CE18u: goto label_8005CE18;
    case 0x8005CE1Cu: goto label_8005CE1C;
    case 0x8005CE20u: goto label_8005CE20;
    case 0x8005CE24u: goto label_8005CE24;
    case 0x8005CE28u: goto label_8005CE28;
    case 0x8005CE2Cu: goto label_8005CE2C;
    case 0x8005CE30u: goto label_8005CE30;
    case 0x8005CE34u: goto label_8005CE34;
    case 0x8005CE38u: goto label_8005CE38;
    case 0x8005CE3Cu: goto label_8005CE3C;
    case 0x8005CE40u: goto label_8005CE40;
    case 0x8005CE44u: goto label_8005CE44;
    case 0x8005CE48u: goto label_8005CE48;
    case 0x8005CE4Cu: goto label_8005CE4C;
    case 0x8005CE50u: goto label_8005CE50;
    case 0x8005CE54u: goto label_8005CE54;
    case 0x8005CE58u: goto label_8005CE58;
    case 0x8005CE5Cu: goto label_8005CE5C;
    case 0x8005CE60u: goto label_8005CE60;
    case 0x8005CE64u: goto label_8005CE64;
    case 0x8005CE68u: goto label_8005CE68;
    case 0x8005CE6Cu: goto label_8005CE6C;
    case 0x8005CE70u: goto label_8005CE70;
    case 0x8005CE74u: goto label_8005CE74;
    case 0x8005CE78u: goto label_8005CE78;
    case 0x8005CE7Cu: goto label_8005CE7C;
    case 0x8005CE80u: goto label_8005CE80;
    case 0x8005CE84u: goto label_8005CE84;
    case 0x8005CE88u: goto label_8005CE88;
    case 0x8005CE8Cu: goto label_8005CE8C;
    case 0x8005CE90u: goto label_8005CE90;
    case 0x8005CE94u: goto label_8005CE94;
    case 0x8005CE98u: goto label_8005CE98;
    case 0x8005CE9Cu: goto label_8005CE9C;
    case 0x8005CEA0u: goto label_8005CEA0;
    case 0x8005CEA4u: goto label_8005CEA4;
    case 0x8005CEA8u: goto label_8005CEA8;
    case 0x8005CEACu: goto label_8005CEAC;
    case 0x8005CEB0u: goto label_8005CEB0;
    case 0x8005CEB4u: goto label_8005CEB4;
    case 0x8005CEB8u: goto label_8005CEB8;
    case 0x8005CEBCu: goto label_8005CEBC;
    case 0x8005CEC0u: goto label_8005CEC0;
    case 0x8005CEC4u: goto label_8005CEC4;
    case 0x8005CEC8u: goto label_8005CEC8;
    case 0x8005CECCu: goto label_8005CECC;
    case 0x8005CED0u: goto label_8005CED0;
    case 0x8005CED4u: goto label_8005CED4;
    case 0x8005CED8u: goto label_8005CED8;
    case 0x8005CEDCu: goto label_8005CEDC;
    case 0x8005CEE0u: goto label_8005CEE0;
    case 0x8005CEE4u: goto label_8005CEE4;
    case 0x8005CEE8u: goto label_8005CEE8;
    case 0x8005CEECu: goto label_8005CEEC;
    case 0x8005CEF0u: goto label_8005CEF0;
    case 0x8005CEF4u: goto label_8005CEF4;
    case 0x8005CEF8u: goto label_8005CEF8;
    case 0x8005CEFCu: goto label_8005CEFC;
    case 0x8005CF00u: goto label_8005CF00;
    case 0x8005CF04u: goto label_8005CF04;
    case 0x8005CF08u: goto label_8005CF08;
    case 0x8005CF0Cu: goto label_8005CF0C;
    case 0x8005CF10u: goto label_8005CF10;
    case 0x8005CF14u: goto label_8005CF14;
    case 0x8005CF18u: goto label_8005CF18;
    case 0x8005CF1Cu: goto label_8005CF1C;
    case 0x8005CF20u: goto label_8005CF20;
    case 0x8005CF24u: goto label_8005CF24;
    case 0x8005CF28u: goto label_8005CF28;
    case 0x8005CF2Cu: goto label_8005CF2C;
    case 0x8005CF30u: goto label_8005CF30;
    case 0x8005CF34u: goto label_8005CF34;
    case 0x8005CF38u: goto label_8005CF38;
    case 0x8005CF3Cu: goto label_8005CF3C;
    case 0x8005CF40u: goto label_8005CF40;
    case 0x8005CF44u: goto label_8005CF44;
    case 0x8005CF48u: goto label_8005CF48;
    case 0x8005CF4Cu: goto label_8005CF4C;
    case 0x8005CF50u: goto label_8005CF50;
    case 0x8005CF54u: goto label_8005CF54;
    case 0x8005CF58u: goto label_8005CF58;
    case 0x8005CF5Cu: goto label_8005CF5C;
    case 0x8005CF60u: goto label_8005CF60;
    case 0x8005CF64u: goto label_8005CF64;
    case 0x8005CF68u: goto label_8005CF68;
    case 0x8005CF6Cu: goto label_8005CF6C;
    case 0x8005CF70u: goto label_8005CF70;
    case 0x8005CF74u: goto label_8005CF74;
    case 0x8005CF78u: goto label_8005CF78;
    case 0x8005CF7Cu: goto label_8005CF7C;
    case 0x8005CF80u: goto label_8005CF80;
    case 0x8005CF84u: goto label_8005CF84;
    case 0x8005CF88u: goto label_8005CF88;
    case 0x8005CF8Cu: goto label_8005CF8C;
    case 0x8005CF90u: goto label_8005CF90;
    case 0x8005CF94u: goto label_8005CF94;
    case 0x8005CF98u: goto label_8005CF98;
    case 0x8005CF9Cu: goto label_8005CF9C;
    case 0x8005CFA0u: goto label_8005CFA0;
    case 0x8005CFA4u: goto label_8005CFA4;
    case 0x8005CFA8u: goto label_8005CFA8;
    case 0x8005CFACu: goto label_8005CFAC;
    case 0x8005CFB0u: goto label_8005CFB0;
    case 0x8005CFB4u: goto label_8005CFB4;
    case 0x8005CFB8u: goto label_8005CFB8;
    case 0x8005CFBCu: goto label_8005CFBC;
    case 0x8005CFC0u: goto label_8005CFC0;
    case 0x8005CFC4u: goto label_8005CFC4;
    case 0x8005CFC8u: goto label_8005CFC8;
    case 0x8005CFCCu: goto label_8005CFCC;
    case 0x8005CFD0u: goto label_8005CFD0;
    case 0x8005CFD4u: goto label_8005CFD4;
    case 0x8005CFD8u: goto label_8005CFD8;
    case 0x8005CFDCu: goto label_8005CFDC;
    case 0x8005CFE0u: goto label_8005CFE0;
    case 0x8005CFE4u: goto label_8005CFE4;
    case 0x8005CFE8u: goto label_8005CFE8;
    case 0x8005CFECu: goto label_8005CFEC;
    case 0x8005CFF0u: goto label_8005CFF0;
    case 0x8005CFF4u: goto label_8005CFF4;
    case 0x8005CFF8u: goto label_8005CFF8;
    case 0x8005CFFCu: goto label_8005CFFC;
    case 0x8005D000u: goto label_8005D000;
    case 0x8005D004u: goto label_8005D004;
    case 0x8005D008u: goto label_8005D008;
    case 0x8005D00Cu: goto label_8005D00C;
    case 0x8005D010u: goto label_8005D010;
    case 0x8005D014u: goto label_8005D014;
    case 0x8005D018u: goto label_8005D018;
    case 0x8005D01Cu: goto label_8005D01C;
    case 0x8005D020u: goto label_8005D020;
    case 0x8005D024u: goto label_8005D024;
    case 0x8005D028u: goto label_8005D028;
    case 0x8005D02Cu: goto label_8005D02C;
    case 0x8005D030u: goto label_8005D030;
    case 0x8005D034u: goto label_8005D034;
    case 0x8005D038u: goto label_8005D038;
    case 0x8005D03Cu: goto label_8005D03C;
    case 0x8005D040u: goto label_8005D040;
    case 0x8005D044u: goto label_8005D044;
    case 0x8005D048u: goto label_8005D048;
    case 0x8005D04Cu: goto label_8005D04C;
    case 0x8005D050u: goto label_8005D050;
    case 0x8005D054u: goto label_8005D054;
    case 0x8005D058u: goto label_8005D058;
    case 0x8005D05Cu: goto label_8005D05C;
    case 0x8005D060u: goto label_8005D060;
    case 0x8005D064u: goto label_8005D064;
    case 0x8005D068u: goto label_8005D068;
    case 0x8005D06Cu: goto label_8005D06C;
    case 0x8005D070u: goto label_8005D070;
    case 0x8005D074u: goto label_8005D074;
    case 0x8005D078u: goto label_8005D078;
    case 0x8005D07Cu: goto label_8005D07C;
    case 0x8005D080u: goto label_8005D080;
    case 0x8005D084u: goto label_8005D084;
    case 0x8005D088u: goto label_8005D088;
    case 0x8005D08Cu: goto label_8005D08C;
    case 0x8005D090u: goto label_8005D090;
    case 0x8005D094u: goto label_8005D094;
    case 0x8005D098u: goto label_8005D098;
    case 0x8005D09Cu: goto label_8005D09C;
    case 0x8005D0A0u: goto label_8005D0A0;
    case 0x8005D0A4u: goto label_8005D0A4;
    case 0x8005D0A8u: goto label_8005D0A8;
    case 0x8005D0ACu: goto label_8005D0AC;
    case 0x8005D0B0u: goto label_8005D0B0;
    case 0x8005D0B4u: goto label_8005D0B4;
    case 0x8005D0B8u: goto label_8005D0B8;
    case 0x8005D0BCu: goto label_8005D0BC;
    case 0x8005D0C0u: goto label_8005D0C0;
    case 0x8005D0C4u: goto label_8005D0C4;
    case 0x8005D0C8u: goto label_8005D0C8;
    case 0x8005D0CCu: goto label_8005D0CC;
    case 0x8005D0D0u: goto label_8005D0D0;
    case 0x8005D0D4u: goto label_8005D0D4;
    case 0x8005D0D8u: goto label_8005D0D8;
    case 0x8005D0DCu: goto label_8005D0DC;
    case 0x8005D0E0u: goto label_8005D0E0;
    case 0x8005D0E4u: goto label_8005D0E4;
    case 0x8005D0E8u: goto label_8005D0E8;
    case 0x8005D0ECu: goto label_8005D0EC;
    case 0x8005D0F0u: goto label_8005D0F0;
    case 0x8005D0F4u: goto label_8005D0F4;
    case 0x8005D0F8u: goto label_8005D0F8;
    case 0x8005D0FCu: goto label_8005D0FC;
    case 0x8005D100u: goto label_8005D100;
    case 0x8005D104u: goto label_8005D104;
    case 0x8005D108u: goto label_8005D108;
    case 0x8005D10Cu: goto label_8005D10C;
    case 0x8005D110u: goto label_8005D110;
    case 0x8005D114u: goto label_8005D114;
    case 0x8005D118u: goto label_8005D118;
    case 0x8005D11Cu: goto label_8005D11C;
    case 0x8005D120u: goto label_8005D120;
    case 0x8005D124u: goto label_8005D124;
    case 0x8005D128u: goto label_8005D128;
    case 0x8005D12Cu: goto label_8005D12C;
    case 0x8005D130u: goto label_8005D130;
    case 0x8005D134u: goto label_8005D134;
    case 0x8005D138u: goto label_8005D138;
    case 0x8005D13Cu: goto label_8005D13C;
    case 0x8005D140u: goto label_8005D140;
    case 0x8005D144u: goto label_8005D144;
    case 0x8005D148u: goto label_8005D148;
    case 0x8005D14Cu: goto label_8005D14C;
    case 0x8005D150u: goto label_8005D150;
    case 0x8005D154u: goto label_8005D154;
    case 0x8005D158u: goto label_8005D158;
    case 0x8005D15Cu: goto label_8005D15C;
    case 0x8005D160u: goto label_8005D160;
    case 0x8005D164u: goto label_8005D164;
    case 0x8005D168u: goto label_8005D168;
    case 0x8005D16Cu: goto label_8005D16C;
    case 0x8005D170u: goto label_8005D170;
    case 0x8005D174u: goto label_8005D174;
    case 0x8005D178u: goto label_8005D178;
    case 0x8005D17Cu: goto label_8005D17C;
    case 0x8005D180u: goto label_8005D180;
    case 0x8005D184u: goto label_8005D184;
    case 0x8005D188u: goto label_8005D188;
    case 0x8005D18Cu: goto label_8005D18C;
    case 0x8005D190u: goto label_8005D190;
    case 0x8005D194u: goto label_8005D194;
    case 0x8005D198u: goto label_8005D198;
    case 0x8005D19Cu: goto label_8005D19C;
    case 0x8005D1A0u: goto label_8005D1A0;
    case 0x8005D1A4u: goto label_8005D1A4;
    case 0x8005D1A8u: goto label_8005D1A8;
    case 0x8005D1ACu: goto label_8005D1AC;
    case 0x8005D1B0u: goto label_8005D1B0;
    case 0x8005D1B4u: goto label_8005D1B4;
    case 0x8005D1B8u: goto label_8005D1B8;
    case 0x8005D1BCu: goto label_8005D1BC;
    case 0x8005D1C0u: goto label_8005D1C0;
    case 0x8005D1C4u: goto label_8005D1C4;
    case 0x8005D1C8u: goto label_8005D1C8;
    case 0x8005D1CCu: goto label_8005D1CC;
    case 0x8005D1D0u: goto label_8005D1D0;
    case 0x8005D1D4u: goto label_8005D1D4;
    case 0x8005D1D8u: goto label_8005D1D8;
    case 0x8005D1DCu: goto label_8005D1DC;
    case 0x8005D1E0u: goto label_8005D1E0;
    case 0x8005D1E4u: goto label_8005D1E4;
    case 0x8005D1E8u: goto label_8005D1E8;
    case 0x8005D1ECu: goto label_8005D1EC;
    case 0x8005D1F0u: goto label_8005D1F0;
    case 0x8005D1F4u: goto label_8005D1F4;
    case 0x8005D1F8u: goto label_8005D1F8;
    case 0x8005D1FCu: goto label_8005D1FC;
    case 0x8005D200u: goto label_8005D200;
    case 0x8005D204u: goto label_8005D204;
    case 0x8005D208u: goto label_8005D208;
    case 0x8005D20Cu: goto label_8005D20C;
    case 0x8005D210u: goto label_8005D210;
    case 0x8005D214u: goto label_8005D214;
    case 0x8005D218u: goto label_8005D218;
    case 0x8005D21Cu: goto label_8005D21C;
    case 0x8005D220u: goto label_8005D220;
    case 0x8005D224u: goto label_8005D224;
    case 0x8005D228u: goto label_8005D228;
    case 0x8005D22Cu: goto label_8005D22C;
    case 0x8005D230u: goto label_8005D230;
    case 0x8005D234u: goto label_8005D234;
    case 0x8005D238u: goto label_8005D238;
    case 0x8005D23Cu: goto label_8005D23C;
    case 0x8005D240u: goto label_8005D240;
    case 0x8005D244u: goto label_8005D244;
    case 0x8005D248u: goto label_8005D248;
    case 0x8005D24Cu: goto label_8005D24C;
    case 0x8005D250u: goto label_8005D250;
    case 0x8005D254u: goto label_8005D254;
    case 0x8005D258u: goto label_8005D258;
    case 0x8005D25Cu: goto label_8005D25C;
    case 0x8005D260u: goto label_8005D260;
    case 0x8005D264u: goto label_8005D264;
    case 0x8005D268u: goto label_8005D268;
    case 0x8005D26Cu: goto label_8005D26C;
    case 0x8005D270u: goto label_8005D270;
    case 0x8005D274u: goto label_8005D274;
    case 0x8005D278u: goto label_8005D278;
    case 0x8005D27Cu: goto label_8005D27C;
    case 0x8005D280u: goto label_8005D280;
    case 0x8005D284u: goto label_8005D284;
    case 0x8005D288u: goto label_8005D288;
    case 0x8005D28Cu: goto label_8005D28C;
    case 0x8005D290u: goto label_8005D290;
    case 0x8005D294u: goto label_8005D294;
    case 0x8005D298u: goto label_8005D298;
    case 0x8005D29Cu: goto label_8005D29C;
    case 0x8005D2A0u: goto label_8005D2A0;
    case 0x8005D2A4u: goto label_8005D2A4;
    case 0x8005D2A8u: goto label_8005D2A8;
    case 0x8005D2ACu: goto label_8005D2AC;
    case 0x8005D2B0u: goto label_8005D2B0;
    case 0x8005D2B4u: goto label_8005D2B4;
    case 0x8005D2B8u: goto label_8005D2B8;
    case 0x8005D2BCu: goto label_8005D2BC;
    case 0x8005D2C0u: goto label_8005D2C0;
    case 0x8005D2C4u: goto label_8005D2C4;
    case 0x8005D2C8u: goto label_8005D2C8;
    case 0x8005D2CCu: goto label_8005D2CC;
    case 0x8005D2D0u: goto label_8005D2D0;
    case 0x8005D2D4u: goto label_8005D2D4;
    case 0x8005D2D8u: goto label_8005D2D8;
    case 0x8005D2DCu: goto label_8005D2DC;
    case 0x8005D2E0u: goto label_8005D2E0;
    case 0x8005D2E4u: goto label_8005D2E4;
    case 0x8005D2E8u: goto label_8005D2E8;
    case 0x8005D2ECu: goto label_8005D2EC;
    case 0x8005D2F0u: goto label_8005D2F0;
    case 0x8005D2F4u: goto label_8005D2F4;
    case 0x8005D2F8u: goto label_8005D2F8;
    case 0x8005D2FCu: goto label_8005D2FC;
    case 0x8005D300u: goto label_8005D300;
    case 0x8005D304u: goto label_8005D304;
    case 0x8005D308u: goto label_8005D308;
    case 0x8005D30Cu: goto label_8005D30C;
    case 0x8005D310u: goto label_8005D310;
    case 0x8005D314u: goto label_8005D314;
    case 0x8005D318u: goto label_8005D318;
    case 0x8005D31Cu: goto label_8005D31C;
    case 0x8005D320u: goto label_8005D320;
    case 0x8005D324u: goto label_8005D324;
    case 0x8005D328u: goto label_8005D328;
    case 0x8005D32Cu: goto label_8005D32C;
    case 0x8005D330u: goto label_8005D330;
    case 0x8005D334u: goto label_8005D334;
    case 0x8005D338u: goto label_8005D338;
    case 0x8005D33Cu: goto label_8005D33C;
    case 0x8005D340u: goto label_8005D340;
    case 0x8005D344u: goto label_8005D344;
    case 0x8005D348u: goto label_8005D348;
    case 0x8005D34Cu: goto label_8005D34C;
    case 0x8005D350u: goto label_8005D350;
    case 0x8005D354u: goto label_8005D354;
    case 0x8005D358u: goto label_8005D358;
    case 0x8005D35Cu: goto label_8005D35C;
    case 0x8005D360u: goto label_8005D360;
    case 0x8005D364u: goto label_8005D364;
    case 0x8005D368u: goto label_8005D368;
    case 0x8005D36Cu: goto label_8005D36C;
    case 0x8005D370u: goto label_8005D370;
    case 0x8005D374u: goto label_8005D374;
    case 0x8005D378u: goto label_8005D378;
    case 0x8005D37Cu: goto label_8005D37C;
    case 0x8005D380u: goto label_8005D380;
    case 0x8005D384u: goto label_8005D384;
    case 0x8005D388u: goto label_8005D388;
    case 0x8005D38Cu: goto label_8005D38C;
    case 0x8005D390u: goto label_8005D390;
    case 0x8005D394u: goto label_8005D394;
    case 0x8005D398u: goto label_8005D398;
    case 0x8005D39Cu: goto label_8005D39C;
    case 0x8005D3A0u: goto label_8005D3A0;
    case 0x8005D3A4u: goto label_8005D3A4;
    case 0x8005D3A8u: goto label_8005D3A8;
    case 0x8005D3ACu: goto label_8005D3AC;
    case 0x8005D3B0u: goto label_8005D3B0;
    case 0x8005D3B4u: goto label_8005D3B4;
    case 0x8005D3B8u: goto label_8005D3B8;
    case 0x8005D3BCu: goto label_8005D3BC;
    case 0x8005D3C0u: goto label_8005D3C0;
    case 0x8005D3C4u: goto label_8005D3C4;
    case 0x8005D3C8u: goto label_8005D3C8;
    case 0x8005D3CCu: goto label_8005D3CC;
    case 0x8005D3D0u: goto label_8005D3D0;
    case 0x8005D3D4u: goto label_8005D3D4;
    case 0x8005D3D8u: goto label_8005D3D8;
    case 0x8005D3DCu: goto label_8005D3DC;
    case 0x8005D3E0u: goto label_8005D3E0;
    case 0x8005D3E4u: goto label_8005D3E4;
    case 0x8005D3E8u: goto label_8005D3E8;
    case 0x8005D3ECu: goto label_8005D3EC;
    case 0x8005D3F0u: goto label_8005D3F0;
    case 0x8005D3F4u: goto label_8005D3F4;
    case 0x8005D3F8u: goto label_8005D3F8;
    case 0x8005D3FCu: goto label_8005D3FC;
    case 0x8005D400u: goto label_8005D400;
    case 0x8005D404u: goto label_8005D404;
    case 0x8005D408u: goto label_8005D408;
    case 0x8005D40Cu: goto label_8005D40C;
    case 0x8005D410u: goto label_8005D410;
    case 0x8005D414u: goto label_8005D414;
    case 0x8005D418u: goto label_8005D418;
    case 0x8005D41Cu: goto label_8005D41C;
    case 0x8005D420u: goto label_8005D420;
    case 0x8005D424u: goto label_8005D424;
    case 0x8005D428u: goto label_8005D428;
    case 0x8005D42Cu: goto label_8005D42C;
    case 0x8005D430u: goto label_8005D430;
    case 0x8005D434u: goto label_8005D434;
    case 0x8005D438u: goto label_8005D438;
    case 0x8005D43Cu: goto label_8005D43C;
    case 0x8005D440u: goto label_8005D440;
    case 0x8005D444u: goto label_8005D444;
    case 0x8005D448u: goto label_8005D448;
    case 0x8005D44Cu: goto label_8005D44C;
    case 0x8005D450u: goto label_8005D450;
    case 0x8005D454u: goto label_8005D454;
    case 0x8005D458u: goto label_8005D458;
    case 0x8005D45Cu: goto label_8005D45C;
    case 0x8005D460u: goto label_8005D460;
    case 0x8005D464u: goto label_8005D464;
    case 0x8005D468u: goto label_8005D468;
    case 0x8005D46Cu: goto label_8005D46C;
    case 0x8005D470u: goto label_8005D470;
    case 0x8005D474u: goto label_8005D474;
    case 0x8005D478u: goto label_8005D478;
    case 0x8005D47Cu: goto label_8005D47C;
    case 0x8005D480u: goto label_8005D480;
    case 0x8005D484u: goto label_8005D484;
    case 0x8005D488u: goto label_8005D488;
    case 0x8005D48Cu: goto label_8005D48C;
    case 0x8005D490u: goto label_8005D490;
    case 0x8005D494u: goto label_8005D494;
    case 0x8005D498u: goto label_8005D498;
    case 0x8005D49Cu: goto label_8005D49C;
    case 0x8005D4A0u: goto label_8005D4A0;
    case 0x8005D4A4u: goto label_8005D4A4;
    case 0x8005D4A8u: goto label_8005D4A8;
    case 0x8005D4ACu: goto label_8005D4AC;
    case 0x8005D4B0u: goto label_8005D4B0;
    case 0x8005D4B4u: goto label_8005D4B4;
    case 0x8005D4B8u: goto label_8005D4B8;
    case 0x8005D4BCu: goto label_8005D4BC;
    case 0x8005D4C0u: goto label_8005D4C0;
    case 0x8005D4C4u: goto label_8005D4C4;
    case 0x8005D4C8u: goto label_8005D4C8;
    case 0x8005D4CCu: goto label_8005D4CC;
    case 0x8005D4D0u: goto label_8005D4D0;
    case 0x8005D4D4u: goto label_8005D4D4;
    case 0x8005D4D8u: goto label_8005D4D8;
    case 0x8005D4DCu: goto label_8005D4DC;
    case 0x8005D4E0u: goto label_8005D4E0;
    case 0x8005D4E4u: goto label_8005D4E4;
    case 0x8005D4E8u: goto label_8005D4E8;
    case 0x8005D4ECu: goto label_8005D4EC;
    case 0x8005D4F0u: goto label_8005D4F0;
    case 0x8005D4F4u: goto label_8005D4F4;
    case 0x8005D4F8u: goto label_8005D4F8;
    case 0x8005D4FCu: goto label_8005D4FC;
    case 0x8005D500u: goto label_8005D500;
    case 0x8005D504u: goto label_8005D504;
    case 0x8005D508u: goto label_8005D508;
    case 0x8005D50Cu: goto label_8005D50C;
    case 0x8005D510u: goto label_8005D510;
    case 0x8005D514u: goto label_8005D514;
    case 0x8005D518u: goto label_8005D518;
    case 0x8005D51Cu: goto label_8005D51C;
    case 0x8005D520u: goto label_8005D520;
    case 0x8005D524u: goto label_8005D524;
    case 0x8005D528u: goto label_8005D528;
    case 0x8005D52Cu: goto label_8005D52C;
    case 0x8005D530u: goto label_8005D530;
    case 0x8005D534u: goto label_8005D534;
    case 0x8005D538u: goto label_8005D538;
    case 0x8005D53Cu: goto label_8005D53C;
    case 0x8005D540u: goto label_8005D540;
    case 0x8005D544u: goto label_8005D544;
    case 0x8005D548u: goto label_8005D548;
    case 0x8005D54Cu: goto label_8005D54C;
    case 0x8005D550u: goto label_8005D550;
    case 0x8005D554u: goto label_8005D554;
    case 0x8005D558u: goto label_8005D558;
    case 0x8005D55Cu: goto label_8005D55C;
    case 0x8005D560u: goto label_8005D560;
    case 0x8005D564u: goto label_8005D564;
    case 0x8005D568u: goto label_8005D568;
    case 0x8005D56Cu: goto label_8005D56C;
    case 0x8005D570u: goto label_8005D570;
    case 0x8005D574u: goto label_8005D574;
    case 0x8005D578u: goto label_8005D578;
    case 0x8005D57Cu: goto label_8005D57C;
    case 0x8005D580u: goto label_8005D580;
    case 0x8005D584u: goto label_8005D584;
    case 0x8005D588u: goto label_8005D588;
    case 0x8005D58Cu: goto label_8005D58C;
    case 0x8005D590u: goto label_8005D590;
    case 0x8005D594u: goto label_8005D594;
    case 0x8005D598u: goto label_8005D598;
    case 0x8005D59Cu: goto label_8005D59C;
    case 0x8005D5A0u: goto label_8005D5A0;
    case 0x8005D5A4u: goto label_8005D5A4;
    case 0x8005D5A8u: goto label_8005D5A8;
    case 0x8005D5ACu: goto label_8005D5AC;
    case 0x8005D5B0u: goto label_8005D5B0;
    case 0x8005D5B4u: goto label_8005D5B4;
    case 0x8005D5B8u: goto label_8005D5B8;
    case 0x8005D5BCu: goto label_8005D5BC;
    case 0x8005D5C0u: goto label_8005D5C0;
    case 0x8005D5C4u: goto label_8005D5C4;
    case 0x8005D5C8u: goto label_8005D5C8;
    case 0x8005D5CCu: goto label_8005D5CC;
    case 0x8005D5D0u: goto label_8005D5D0;
    case 0x8005D5D4u: goto label_8005D5D4;
    case 0x8005D5D8u: goto label_8005D5D8;
    case 0x8005D5DCu: goto label_8005D5DC;
    case 0x8005D5E0u: goto label_8005D5E0;
    case 0x8005D5E4u: goto label_8005D5E4;
    case 0x8005D5E8u: goto label_8005D5E8;
    case 0x8005D5ECu: goto label_8005D5EC;
    case 0x8005D5F0u: goto label_8005D5F0;
    case 0x8005D5F4u: goto label_8005D5F4;
    case 0x8005D5F8u: goto label_8005D5F8;
    case 0x8005D5FCu: goto label_8005D5FC;
    case 0x8005D600u: goto label_8005D600;
    case 0x8005D604u: goto label_8005D604;
    case 0x8005D608u: goto label_8005D608;
    case 0x8005D60Cu: goto label_8005D60C;
    case 0x8005D610u: goto label_8005D610;
    case 0x8005D614u: goto label_8005D614;
    case 0x8005D618u: goto label_8005D618;
    case 0x8005D61Cu: goto label_8005D61C;
    case 0x8005D620u: goto label_8005D620;
    case 0x8005D624u: goto label_8005D624;
    case 0x8005D628u: goto label_8005D628;
    case 0x8005D62Cu: goto label_8005D62C;
    case 0x8005D630u: goto label_8005D630;
    case 0x8005D634u: goto label_8005D634;
    case 0x8005D638u: goto label_8005D638;
    case 0x8005D63Cu: goto label_8005D63C;
    case 0x8005D640u: goto label_8005D640;
    case 0x8005D644u: goto label_8005D644;
    case 0x8005D648u: goto label_8005D648;
    case 0x8005D64Cu: goto label_8005D64C;
    case 0x8005D650u: goto label_8005D650;
    case 0x8005D654u: goto label_8005D654;
    case 0x8005D658u: goto label_8005D658;
    case 0x8005D65Cu: goto label_8005D65C;
    case 0x8005D660u: goto label_8005D660;
    case 0x8005D664u: goto label_8005D664;
    case 0x8005D668u: goto label_8005D668;
    case 0x8005D66Cu: goto label_8005D66C;
    case 0x8005D670u: goto label_8005D670;
    case 0x8005D674u: goto label_8005D674;
    case 0x8005D678u: goto label_8005D678;
    case 0x8005D67Cu: goto label_8005D67C;
    case 0x8005D680u: goto label_8005D680;
    case 0x8005D684u: goto label_8005D684;
    case 0x8005D688u: goto label_8005D688;
    case 0x8005D68Cu: goto label_8005D68C;
    case 0x8005D690u: goto label_8005D690;
    case 0x8005D694u: goto label_8005D694;
    case 0x8005D698u: goto label_8005D698;
    case 0x8005D69Cu: goto label_8005D69C;
    case 0x8005D6A0u: goto label_8005D6A0;
    case 0x8005D6A4u: goto label_8005D6A4;
    case 0x8005D6A8u: goto label_8005D6A8;
    case 0x8005D6ACu: goto label_8005D6AC;
    case 0x8005D6B0u: goto label_8005D6B0;
    case 0x8005D6B4u: goto label_8005D6B4;
    case 0x8005D6B8u: goto label_8005D6B8;
    case 0x8005D6BCu: goto label_8005D6BC;
    case 0x8005D6C0u: goto label_8005D6C0;
    case 0x8005D6C4u: goto label_8005D6C4;
    case 0x8005D6C8u: goto label_8005D6C8;
    case 0x8005D6CCu: goto label_8005D6CC;
    case 0x8005D6D0u: goto label_8005D6D0;
    case 0x8005D6D4u: goto label_8005D6D4;
    case 0x8005D6D8u: goto label_8005D6D8;
    case 0x8005D6DCu: goto label_8005D6DC;
    case 0x8005D6E0u: goto label_8005D6E0;
    case 0x8005D6E4u: goto label_8005D6E4;
    case 0x8005D6E8u: goto label_8005D6E8;
    case 0x8005D6ECu: goto label_8005D6EC;
    case 0x8005D6F0u: goto label_8005D6F0;
    case 0x8005D6F4u: goto label_8005D6F4;
    case 0x8005D6F8u: goto label_8005D6F8;
    case 0x8005D6FCu: goto label_8005D6FC;
    case 0x8005D700u: goto label_8005D700;
    case 0x8005D704u: goto label_8005D704;
    case 0x8005D708u: goto label_8005D708;
    case 0x8005D70Cu: goto label_8005D70C;
    case 0x8005D710u: goto label_8005D710;
    case 0x8005D714u: goto label_8005D714;
    case 0x8005D718u: goto label_8005D718;
    case 0x8005D71Cu: goto label_8005D71C;
    case 0x8005D720u: goto label_8005D720;
    case 0x8005D724u: goto label_8005D724;
    case 0x8005D728u: goto label_8005D728;
    case 0x8005D72Cu: goto label_8005D72C;
    case 0x8005D730u: goto label_8005D730;
    case 0x8005D734u: goto label_8005D734;
    case 0x8005D738u: goto label_8005D738;
    case 0x8005D73Cu: goto label_8005D73C;
    case 0x8005D740u: goto label_8005D740;
    case 0x8005D744u: goto label_8005D744;
    case 0x8005D748u: goto label_8005D748;
    case 0x8005D74Cu: goto label_8005D74C;
    case 0x8005D750u: goto label_8005D750;
    case 0x8005D754u: goto label_8005D754;
    case 0x8005D758u: goto label_8005D758;
    case 0x8005D75Cu: goto label_8005D75C;
    case 0x8005D760u: goto label_8005D760;
    case 0x8005D764u: goto label_8005D764;
    case 0x8005D768u: goto label_8005D768;
    case 0x8005D76Cu: goto label_8005D76C;
    case 0x8005D770u: goto label_8005D770;
    case 0x8005D774u: goto label_8005D774;
    case 0x8005D778u: goto label_8005D778;
    case 0x8005D77Cu: goto label_8005D77C;
    case 0x8005D780u: goto label_8005D780;
    case 0x8005D784u: goto label_8005D784;
    case 0x8005D788u: goto label_8005D788;
    case 0x8005D78Cu: goto label_8005D78C;
    case 0x8005D790u: goto label_8005D790;
    case 0x8005D794u: goto label_8005D794;
    case 0x8005D798u: goto label_8005D798;
    case 0x8005D79Cu: goto label_8005D79C;
    case 0x8005D7A0u: goto label_8005D7A0;
    case 0x8005D7A4u: goto label_8005D7A4;
    case 0x8005D7A8u: goto label_8005D7A8;
    case 0x8005D7ACu: goto label_8005D7AC;
    case 0x8005D7B0u: goto label_8005D7B0;
    case 0x8005D7B4u: goto label_8005D7B4;
    case 0x8005D7B8u: goto label_8005D7B8;
    case 0x8005D7BCu: goto label_8005D7BC;
    case 0x8005D7C0u: goto label_8005D7C0;
    case 0x8005D7C4u: goto label_8005D7C4;
    case 0x8005D7C8u: goto label_8005D7C8;
    case 0x8005D7CCu: goto label_8005D7CC;
    case 0x8005D7D0u: goto label_8005D7D0;
    case 0x8005D7D4u: goto label_8005D7D4;
    case 0x8005D7D8u: goto label_8005D7D8;
    case 0x8005D7DCu: goto label_8005D7DC;
    case 0x8005D7E0u: goto label_8005D7E0;
    case 0x8005D7E4u: goto label_8005D7E4;
    case 0x8005D7E8u: goto label_8005D7E8;
    case 0x8005D7ECu: goto label_8005D7EC;
    case 0x8005D7F0u: goto label_8005D7F0;
    case 0x8005D7F4u: goto label_8005D7F4;
    case 0x8005D7F8u: goto label_8005D7F8;
    case 0x8005D7FCu: goto label_8005D7FC;
    case 0x8005D800u: goto label_8005D800;
    case 0x8005D804u: goto label_8005D804;
    case 0x8005D808u: goto label_8005D808;
    case 0x8005D80Cu: goto label_8005D80C;
    case 0x8005D810u: goto label_8005D810;
    case 0x8005D814u: goto label_8005D814;
    case 0x8005D818u: goto label_8005D818;
    case 0x8005D81Cu: goto label_8005D81C;
    case 0x8005D820u: goto label_8005D820;
    case 0x8005D824u: goto label_8005D824;
    case 0x8005D828u: goto label_8005D828;
    case 0x8005D82Cu: goto label_8005D82C;
    case 0x8005D830u: goto label_8005D830;
    case 0x8005D834u: goto label_8005D834;
    case 0x8005D838u: goto label_8005D838;
    case 0x8005D83Cu: goto label_8005D83C;
    case 0x8005D840u: goto label_8005D840;
    case 0x8005D844u: goto label_8005D844;
    case 0x8005D848u: goto label_8005D848;
    case 0x8005D84Cu: goto label_8005D84C;
    case 0x8005D850u: goto label_8005D850;
    case 0x8005D854u: goto label_8005D854;
    case 0x8005D858u: goto label_8005D858;
    case 0x8005D85Cu: goto label_8005D85C;
    case 0x8005D860u: goto label_8005D860;
    case 0x8005D864u: goto label_8005D864;
    case 0x8005D868u: goto label_8005D868;
    case 0x8005D86Cu: goto label_8005D86C;
    case 0x8005D870u: goto label_8005D870;
    case 0x8005D874u: goto label_8005D874;
    case 0x8005D878u: goto label_8005D878;
    case 0x8005D87Cu: goto label_8005D87C;
    case 0x8005D880u: goto label_8005D880;
    case 0x8005D884u: goto label_8005D884;
    case 0x8005D888u: goto label_8005D888;
    case 0x8005D88Cu: goto label_8005D88C;
    case 0x8005D890u: goto label_8005D890;
    case 0x8005D894u: goto label_8005D894;
    case 0x8005D898u: goto label_8005D898;
    case 0x8005D89Cu: goto label_8005D89C;
    case 0x8005D8A0u: goto label_8005D8A0;
    case 0x8005D8A4u: goto label_8005D8A4;
    case 0x8005D8A8u: goto label_8005D8A8;
    case 0x8005D8ACu: goto label_8005D8AC;
    case 0x8005D8B0u: goto label_8005D8B0;
    case 0x8005D8B4u: goto label_8005D8B4;
    case 0x8005D8B8u: goto label_8005D8B8;
    case 0x8005D8BCu: goto label_8005D8BC;
    case 0x8005D8C0u: goto label_8005D8C0;
    case 0x8005D8C4u: goto label_8005D8C4;
    case 0x8005D8C8u: goto label_8005D8C8;
    case 0x8005D8CCu: goto label_8005D8CC;
    case 0x8005D8D0u: goto label_8005D8D0;
    case 0x8005D8D4u: goto label_8005D8D4;
    case 0x8005D8D8u: goto label_8005D8D8;
    case 0x8005D8DCu: goto label_8005D8DC;
    case 0x8005D8E0u: goto label_8005D8E0;
    case 0x8005D8E4u: goto label_8005D8E4;
    case 0x8005D8E8u: goto label_8005D8E8;
    case 0x8005D8ECu: goto label_8005D8EC;
    case 0x8005D8F0u: goto label_8005D8F0;
    case 0x8005D8F4u: goto label_8005D8F4;
    case 0x8005D8F8u: goto label_8005D8F8;
    case 0x8005D8FCu: goto label_8005D8FC;
    case 0x8005D900u: goto label_8005D900;
    case 0x8005D904u: goto label_8005D904;
    case 0x8005D908u: goto label_8005D908;
    case 0x8005D90Cu: goto label_8005D90C;
    case 0x8005D910u: goto label_8005D910;
    case 0x8005D914u: goto label_8005D914;
    case 0x8005D918u: goto label_8005D918;
    case 0x8005D91Cu: goto label_8005D91C;
    case 0x8005D920u: goto label_8005D920;
    case 0x8005D924u: goto label_8005D924;
    case 0x8005D928u: goto label_8005D928;
    case 0x8005D92Cu: goto label_8005D92C;
    case 0x8005D930u: goto label_8005D930;
    case 0x8005D934u: goto label_8005D934;
    case 0x8005D938u: goto label_8005D938;
    case 0x8005D93Cu: goto label_8005D93C;
    case 0x8005D940u: goto label_8005D940;
    case 0x8005D944u: goto label_8005D944;
    case 0x8005D948u: goto label_8005D948;
    case 0x8005D94Cu: goto label_8005D94C;
    case 0x8005D950u: goto label_8005D950;
    case 0x8005D954u: goto label_8005D954;
    case 0x8005D958u: goto label_8005D958;
    case 0x8005D95Cu: goto label_8005D95C;
    case 0x8005D960u: goto label_8005D960;
    case 0x8005D964u: goto label_8005D964;
    case 0x8005D968u: goto label_8005D968;
    case 0x8005D96Cu: goto label_8005D96C;
    case 0x8005D970u: goto label_8005D970;
    case 0x8005D974u: goto label_8005D974;
    case 0x8005D978u: goto label_8005D978;
    case 0x8005D97Cu: goto label_8005D97C;
    case 0x8005D980u: goto label_8005D980;
    case 0x8005D984u: goto label_8005D984;
    case 0x8005D988u: goto label_8005D988;
    case 0x8005D98Cu: goto label_8005D98C;
    case 0x8005D990u: goto label_8005D990;
    case 0x8005D994u: goto label_8005D994;
    case 0x8005D998u: goto label_8005D998;
    case 0x8005D99Cu: goto label_8005D99C;
    case 0x8005D9A0u: goto label_8005D9A0;
    case 0x8005D9A4u: goto label_8005D9A4;
    case 0x8005D9A8u: goto label_8005D9A8;
    case 0x8005D9ACu: goto label_8005D9AC;
    case 0x8005D9B0u: goto label_8005D9B0;
    case 0x8005D9B4u: goto label_8005D9B4;
    case 0x8005D9B8u: goto label_8005D9B8;
    case 0x8005D9BCu: goto label_8005D9BC;
    case 0x8005D9C0u: goto label_8005D9C0;
    case 0x8005D9C4u: goto label_8005D9C4;
    case 0x8005D9C8u: goto label_8005D9C8;
    case 0x8005D9CCu: goto label_8005D9CC;
    case 0x8005D9D0u: goto label_8005D9D0;
    case 0x8005D9D4u: goto label_8005D9D4;
    case 0x8005D9D8u: goto label_8005D9D8;
    case 0x8005D9DCu: goto label_8005D9DC;
    case 0x8005D9E0u: goto label_8005D9E0;
    case 0x8005D9E4u: goto label_8005D9E4;
    case 0x8005D9E8u: goto label_8005D9E8;
    case 0x8005D9ECu: goto label_8005D9EC;
    case 0x8005D9F0u: goto label_8005D9F0;
    case 0x8005D9F4u: goto label_8005D9F4;
    case 0x8005D9F8u: goto label_8005D9F8;
    case 0x8005D9FCu: goto label_8005D9FC;
    case 0x8005DA00u: goto label_8005DA00;
    case 0x8005DA04u: goto label_8005DA04;
    case 0x8005DA08u: goto label_8005DA08;
    case 0x8005DA0Cu: goto label_8005DA0C;
    case 0x8005DA10u: goto label_8005DA10;
    case 0x8005DA14u: goto label_8005DA14;
    case 0x8005DA18u: goto label_8005DA18;
    case 0x8005DA1Cu: goto label_8005DA1C;
    case 0x8005DA20u: goto label_8005DA20;
    case 0x8005DA24u: goto label_8005DA24;
    case 0x8005DA28u: goto label_8005DA28;
    case 0x8005DA2Cu: goto label_8005DA2C;
    case 0x8005DA30u: goto label_8005DA30;
    case 0x8005DA34u: goto label_8005DA34;
    case 0x8005DA38u: goto label_8005DA38;
    case 0x8005DA3Cu: goto label_8005DA3C;
    case 0x8005DA40u: goto label_8005DA40;
    case 0x8005DA44u: goto label_8005DA44;
    case 0x8005DA48u: goto label_8005DA48;
    case 0x8005DA4Cu: goto label_8005DA4C;
    case 0x8005DA50u: goto label_8005DA50;
    case 0x8005DA54u: goto label_8005DA54;
    case 0x8005DA58u: goto label_8005DA58;
    case 0x8005DA5Cu: goto label_8005DA5C;
    case 0x8005DA60u: goto label_8005DA60;
    case 0x8005DA64u: goto label_8005DA64;
    case 0x8005DA68u: goto label_8005DA68;
    case 0x8005DA6Cu: goto label_8005DA6C;
    case 0x8005DA70u: goto label_8005DA70;
    case 0x8005DA74u: goto label_8005DA74;
    case 0x8005DA78u: goto label_8005DA78;
    case 0x8005DA7Cu: goto label_8005DA7C;
    case 0x8005DA80u: goto label_8005DA80;
    case 0x8005DA84u: goto label_8005DA84;
    case 0x8005DA88u: goto label_8005DA88;
    case 0x8005DA8Cu: goto label_8005DA8C;
    case 0x8005DA90u: goto label_8005DA90;
    case 0x8005DA94u: goto label_8005DA94;
    case 0x8005DA98u: goto label_8005DA98;
    case 0x8005DA9Cu: goto label_8005DA9C;
    case 0x8005DAA0u: goto label_8005DAA0;
    case 0x8005DAA4u: goto label_8005DAA4;
    case 0x8005DAA8u: goto label_8005DAA8;
    case 0x8005DAACu: goto label_8005DAAC;
    case 0x8005DAB0u: goto label_8005DAB0;
    case 0x8005DAB4u: goto label_8005DAB4;
    case 0x8005DAB8u: goto label_8005DAB8;
    case 0x8005DABCu: goto label_8005DABC;
    case 0x8005DAC0u: goto label_8005DAC0;
    case 0x8005DAC4u: goto label_8005DAC4;
    case 0x8005DAC8u: goto label_8005DAC8;
    case 0x8005DACCu: goto label_8005DACC;
    case 0x8005DAD0u: goto label_8005DAD0;
    case 0x8005DAD4u: goto label_8005DAD4;
    case 0x8005DAD8u: goto label_8005DAD8;
    case 0x8005DADCu: goto label_8005DADC;
    case 0x8005DAE0u: goto label_8005DAE0;
    case 0x8005DAE4u: goto label_8005DAE4;
    case 0x8005DAE8u: goto label_8005DAE8;
    case 0x8005DAECu: goto label_8005DAEC;
    case 0x8005DAF0u: goto label_8005DAF0;
    case 0x8005DAF4u: goto label_8005DAF4;
    case 0x8005DAF8u: goto label_8005DAF8;
    case 0x8005DAFCu: goto label_8005DAFC;
    case 0x8005DB00u: goto label_8005DB00;
    case 0x8005DB04u: goto label_8005DB04;
    case 0x8005DB08u: goto label_8005DB08;
    case 0x8005DB0Cu: goto label_8005DB0C;
    case 0x8005DB10u: goto label_8005DB10;
    case 0x8005DB14u: goto label_8005DB14;
    case 0x8005DB18u: goto label_8005DB18;
    case 0x8005DB1Cu: goto label_8005DB1C;
    case 0x8005DB20u: goto label_8005DB20;
    case 0x8005DB24u: goto label_8005DB24;
    case 0x8005DB28u: goto label_8005DB28;
    case 0x8005DB2Cu: goto label_8005DB2C;
    case 0x8005DB30u: goto label_8005DB30;
    case 0x8005DB34u: goto label_8005DB34;
    case 0x8005DB38u: goto label_8005DB38;
    case 0x8005DB3Cu: goto label_8005DB3C;
    case 0x8005DB40u: goto label_8005DB40;
    case 0x8005DB44u: goto label_8005DB44;
    case 0x8005DB48u: goto label_8005DB48;
    case 0x8005DB4Cu: goto label_8005DB4C;
    case 0x8005DB50u: goto label_8005DB50;
    case 0x8005DB54u: goto label_8005DB54;
    case 0x8005DB58u: goto label_8005DB58;
    case 0x8005DB5Cu: goto label_8005DB5C;
    case 0x8005DB60u: goto label_8005DB60;
    case 0x8005DB64u: goto label_8005DB64;
    case 0x8005DB68u: goto label_8005DB68;
    case 0x8005DB6Cu: goto label_8005DB6C;
    case 0x8005DB70u: goto label_8005DB70;
    case 0x8005DB74u: goto label_8005DB74;
    case 0x8005DB78u: goto label_8005DB78;
    case 0x8005DB7Cu: goto label_8005DB7C;
    case 0x8005DB80u: goto label_8005DB80;
    case 0x8005DB84u: goto label_8005DB84;
    case 0x8005DB88u: goto label_8005DB88;
    case 0x8005DB8Cu: goto label_8005DB8C;
    case 0x8005DB90u: goto label_8005DB90;
    case 0x8005DB94u: goto label_8005DB94;
    case 0x8005DB98u: goto label_8005DB98;
    case 0x8005DB9Cu: goto label_8005DB9C;
    case 0x8005DBA0u: goto label_8005DBA0;
    case 0x8005DBA4u: goto label_8005DBA4;
    case 0x8005DBA8u: goto label_8005DBA8;
    case 0x8005DBACu: goto label_8005DBAC;
    case 0x8005DBB0u: goto label_8005DBB0;
    case 0x8005DBB4u: goto label_8005DBB4;
    case 0x8005DBB8u: goto label_8005DBB8;
    case 0x8005DBBCu: goto label_8005DBBC;
    case 0x8005DBC0u: goto label_8005DBC0;
    case 0x8005DBC4u: goto label_8005DBC4;
    case 0x8005DBC8u: goto label_8005DBC8;
    case 0x8005DBCCu: goto label_8005DBCC;
    case 0x8005DBD0u: goto label_8005DBD0;
    case 0x8005DBD4u: goto label_8005DBD4;
    case 0x8005DBD8u: goto label_8005DBD8;
    case 0x8005DBDCu: goto label_8005DBDC;
    case 0x8005DBE0u: goto label_8005DBE0;
    case 0x8005DBE4u: goto label_8005DBE4;
    case 0x8005DBE8u: goto label_8005DBE8;
    case 0x8005DBECu: goto label_8005DBEC;
    case 0x8005DBF0u: goto label_8005DBF0;
    case 0x8005DBF4u: goto label_8005DBF4;
    case 0x8005DBF8u: goto label_8005DBF8;
    case 0x8005DBFCu: goto label_8005DBFC;
    case 0x8005DC00u: goto label_8005DC00;
    case 0x8005DC04u: goto label_8005DC04;
    case 0x8005DC08u: goto label_8005DC08;
    case 0x8005DC0Cu: goto label_8005DC0C;
    case 0x8005DC10u: goto label_8005DC10;
    case 0x8005DC14u: goto label_8005DC14;
    case 0x8005DC18u: goto label_8005DC18;
    case 0x8005DC1Cu: goto label_8005DC1C;
    case 0x8005DC20u: goto label_8005DC20;
    case 0x8005DC24u: goto label_8005DC24;
    case 0x8005DC28u: goto label_8005DC28;
    case 0x8005DC2Cu: goto label_8005DC2C;
    case 0x8005DC30u: goto label_8005DC30;
    case 0x8005DC34u: goto label_8005DC34;
    case 0x8005DC38u: goto label_8005DC38;
    case 0x8005DC3Cu: goto label_8005DC3C;
    case 0x8005DC40u: goto label_8005DC40;
    case 0x8005DC44u: goto label_8005DC44;
    case 0x8005DC48u: goto label_8005DC48;
    case 0x8005DC4Cu: goto label_8005DC4C;
    case 0x8005DC50u: goto label_8005DC50;
    case 0x8005DC54u: goto label_8005DC54;
    case 0x8005DC58u: goto label_8005DC58;
    case 0x8005DC5Cu: goto label_8005DC5C;
    case 0x8005DC60u: goto label_8005DC60;
    case 0x8005DC64u: goto label_8005DC64;
    case 0x8005DC68u: goto label_8005DC68;
    case 0x8005DC6Cu: goto label_8005DC6C;
    case 0x8005DC70u: goto label_8005DC70;
    case 0x8005DC74u: goto label_8005DC74;
    case 0x8005DC78u: goto label_8005DC78;
    case 0x8005DC7Cu: goto label_8005DC7C;
    case 0x8005DC80u: goto label_8005DC80;
    case 0x8005DC84u: goto label_8005DC84;
    case 0x8005DC88u: goto label_8005DC88;
    case 0x8005DC8Cu: goto label_8005DC8C;
    case 0x8005DC90u: goto label_8005DC90;
    case 0x8005DC94u: goto label_8005DC94;
    case 0x8005DC98u: goto label_8005DC98;
    case 0x8005DC9Cu: goto label_8005DC9C;
    case 0x8005DCA0u: goto label_8005DCA0;
    case 0x8005DCA4u: goto label_8005DCA4;
    case 0x8005DCA8u: goto label_8005DCA8;
    case 0x8005DCACu: goto label_8005DCAC;
    case 0x8005DCB0u: goto label_8005DCB0;
    case 0x8005DCB4u: goto label_8005DCB4;
    case 0x8005DCB8u: goto label_8005DCB8;
    case 0x8005DCBCu: goto label_8005DCBC;
    case 0x8005DCC0u: goto label_8005DCC0;
    case 0x8005DCC4u: goto label_8005DCC4;
    case 0x8005DCC8u: goto label_8005DCC8;
    case 0x8005DCCCu: goto label_8005DCCC;
    case 0x8005DCD0u: goto label_8005DCD0;
    case 0x8005DCD4u: goto label_8005DCD4;
    case 0x8005DCD8u: goto label_8005DCD8;
    case 0x8005DCDCu: goto label_8005DCDC;
    case 0x8005DCE0u: goto label_8005DCE0;
    case 0x8005DCE4u: goto label_8005DCE4;
    case 0x8005DCE8u: goto label_8005DCE8;
    case 0x8005DCECu: goto label_8005DCEC;
    case 0x8005DCF0u: goto label_8005DCF0;
    case 0x8005DCF4u: goto label_8005DCF4;
    case 0x8005DCF8u: goto label_8005DCF8;
    case 0x8005DCFCu: goto label_8005DCFC;
    case 0x8005DD00u: goto label_8005DD00;
    case 0x8005DD04u: goto label_8005DD04;
    case 0x8005DD08u: goto label_8005DD08;
    case 0x8005DD0Cu: goto label_8005DD0C;
    case 0x8005DD10u: goto label_8005DD10;
    case 0x8005DD14u: goto label_8005DD14;
    case 0x8005DD18u: goto label_8005DD18;
    case 0x8005DD1Cu: goto label_8005DD1C;
    case 0x8005DD20u: goto label_8005DD20;
    case 0x8005DD24u: goto label_8005DD24;
    case 0x8005DD28u: goto label_8005DD28;
    case 0x8005DD2Cu: goto label_8005DD2C;
    case 0x8005DD30u: goto label_8005DD30;
    case 0x8005DD34u: goto label_8005DD34;
    case 0x8005DD38u: goto label_8005DD38;
    case 0x8005DD3Cu: goto label_8005DD3C;
    case 0x8005DD40u: goto label_8005DD40;
    case 0x8005DD44u: goto label_8005DD44;
    case 0x8005DD48u: goto label_8005DD48;
    case 0x8005DD4Cu: goto label_8005DD4C;
    case 0x8005DD50u: goto label_8005DD50;
    case 0x8005DD54u: goto label_8005DD54;
    case 0x8005DD58u: goto label_8005DD58;
    case 0x8005DD5Cu: goto label_8005DD5C;
    case 0x8005DD60u: goto label_8005DD60;
    case 0x8005DD64u: goto label_8005DD64;
    case 0x8005DD68u: goto label_8005DD68;
    case 0x8005DD6Cu: goto label_8005DD6C;
    case 0x8005DD70u: goto label_8005DD70;
    case 0x8005DD74u: goto label_8005DD74;
    case 0x8005DD78u: goto label_8005DD78;
    case 0x8005DD7Cu: goto label_8005DD7C;
    case 0x8005DD80u: goto label_8005DD80;
    case 0x8005DD84u: goto label_8005DD84;
    case 0x8005DD88u: goto label_8005DD88;
    case 0x8005DD8Cu: goto label_8005DD8C;
    case 0x8005DD90u: goto label_8005DD90;
    case 0x8005DD94u: goto label_8005DD94;
    case 0x8005DD98u: goto label_8005DD98;
    case 0x8005DD9Cu: goto label_8005DD9C;
    case 0x8005DDA0u: goto label_8005DDA0;
    case 0x8005DDA4u: goto label_8005DDA4;
    case 0x8005DDA8u: goto label_8005DDA8;
    case 0x8005DDACu: goto label_8005DDAC;
    case 0x8005DDB0u: goto label_8005DDB0;
    case 0x8005DDB4u: goto label_8005DDB4;
    case 0x8005DDB8u: goto label_8005DDB8;
    case 0x8005DDBCu: goto label_8005DDBC;
    case 0x8005DDC0u: goto label_8005DDC0;
    case 0x8005DDC4u: goto label_8005DDC4;
    case 0x8005DDC8u: goto label_8005DDC8;
    case 0x8005DDCCu: goto label_8005DDCC;
    case 0x8005DDD0u: goto label_8005DDD0;
    case 0x8005DDD4u: goto label_8005DDD4;
    case 0x8005DDD8u: goto label_8005DDD8;
    case 0x8005DDDCu: goto label_8005DDDC;
    case 0x8005DDE0u: goto label_8005DDE0;
    case 0x8005DDE4u: goto label_8005DDE4;
    case 0x8005DDE8u: goto label_8005DDE8;
    case 0x8005DDECu: goto label_8005DDEC;
    case 0x8005DDF0u: goto label_8005DDF0;
    case 0x8005DDF4u: goto label_8005DDF4;
    case 0x8005DDF8u: goto label_8005DDF8;
    case 0x8005DDFCu: goto label_8005DDFC;
    case 0x8005DE00u: goto label_8005DE00;
    case 0x8005DE04u: goto label_8005DE04;
    case 0x8005DE08u: goto label_8005DE08;
    case 0x8005DE0Cu: goto label_8005DE0C;
    case 0x8005DE10u: goto label_8005DE10;
    case 0x8005DE14u: goto label_8005DE14;
    case 0x8005DE18u: goto label_8005DE18;
    case 0x8005DE1Cu: goto label_8005DE1C;
    case 0x8005DE20u: goto label_8005DE20;
    case 0x8005DE24u: goto label_8005DE24;
    case 0x8005DE28u: goto label_8005DE28;
    case 0x8005DE2Cu: goto label_8005DE2C;
    case 0x8005DE30u: goto label_8005DE30;
    case 0x8005DE34u: goto label_8005DE34;
    case 0x8005DE38u: goto label_8005DE38;
    case 0x8005DE3Cu: goto label_8005DE3C;
    case 0x8005DE40u: goto label_8005DE40;
    case 0x8005DE44u: goto label_8005DE44;
    case 0x8005DE48u: goto label_8005DE48;
    case 0x8005DE4Cu: goto label_8005DE4C;
    case 0x8005DE50u: goto label_8005DE50;
    case 0x8005DE54u: goto label_8005DE54;
    case 0x8005DE58u: goto label_8005DE58;
    case 0x8005DE5Cu: goto label_8005DE5C;
    case 0x8005DE60u: goto label_8005DE60;
    case 0x8005DE64u: goto label_8005DE64;
    case 0x8005DE68u: goto label_8005DE68;
    case 0x8005DE6Cu: goto label_8005DE6C;
    case 0x8005DE70u: goto label_8005DE70;
    case 0x8005DE74u: goto label_8005DE74;
    case 0x8005DE78u: goto label_8005DE78;
    case 0x8005DE7Cu: goto label_8005DE7C;
    case 0x8005DE80u: goto label_8005DE80;
    case 0x8005DE84u: goto label_8005DE84;
    case 0x8005DE88u: goto label_8005DE88;
    case 0x8005DE8Cu: goto label_8005DE8C;
    case 0x8005DE90u: goto label_8005DE90;
    case 0x8005DE94u: goto label_8005DE94;
    case 0x8005DE98u: goto label_8005DE98;
    case 0x8005DE9Cu: goto label_8005DE9C;
    case 0x8005DEA0u: goto label_8005DEA0;
    case 0x8005DEA4u: goto label_8005DEA4;
    case 0x8005DEA8u: goto label_8005DEA8;
    case 0x8005DEACu: goto label_8005DEAC;
    case 0x8005DEB0u: goto label_8005DEB0;
    case 0x8005DEB4u: goto label_8005DEB4;
    case 0x8005DEB8u: goto label_8005DEB8;
    case 0x8005DEBCu: goto label_8005DEBC;
    case 0x8005DEC0u: goto label_8005DEC0;
    case 0x8005DEC4u: goto label_8005DEC4;
    case 0x8005DEC8u: goto label_8005DEC8;
    case 0x8005DECCu: goto label_8005DECC;
    case 0x8005DED0u: goto label_8005DED0;
    case 0x8005DED4u: goto label_8005DED4;
    case 0x8005DED8u: goto label_8005DED8;
    case 0x8005DEDCu: goto label_8005DEDC;
    case 0x8005DEE0u: goto label_8005DEE0;
    case 0x8005DEE4u: goto label_8005DEE4;
    case 0x8005DEE8u: goto label_8005DEE8;
    case 0x8005DEECu: goto label_8005DEEC;
    case 0x8005DEF0u: goto label_8005DEF0;
    case 0x8005DEF4u: goto label_8005DEF4;
    case 0x8005DEF8u: goto label_8005DEF8;
    case 0x8005DEFCu: goto label_8005DEFC;
    case 0x8005DF00u: goto label_8005DF00;
    case 0x8005DF04u: goto label_8005DF04;
    case 0x8005DF08u: goto label_8005DF08;
    case 0x8005DF0Cu: goto label_8005DF0C;
    case 0x8005DF10u: goto label_8005DF10;
    case 0x8005DF14u: goto label_8005DF14;
    case 0x8005DF18u: goto label_8005DF18;
    case 0x8005DF1Cu: goto label_8005DF1C;
    case 0x8005DF20u: goto label_8005DF20;
    case 0x8005DF24u: goto label_8005DF24;
    case 0x8005DF28u: goto label_8005DF28;
    case 0x8005DF2Cu: goto label_8005DF2C;
    case 0x8005DF30u: goto label_8005DF30;
    case 0x8005DF34u: goto label_8005DF34;
    case 0x8005DF38u: goto label_8005DF38;
    case 0x8005DF3Cu: goto label_8005DF3C;
    case 0x8005DF40u: goto label_8005DF40;
    case 0x8005DF44u: goto label_8005DF44;
    case 0x8005DF48u: goto label_8005DF48;
    case 0x8005DF4Cu: goto label_8005DF4C;
    case 0x8005DF50u: goto label_8005DF50;
    case 0x8005DF54u: goto label_8005DF54;
    case 0x8005DF58u: goto label_8005DF58;
    case 0x8005DF5Cu: goto label_8005DF5C;
    case 0x8005DF60u: goto label_8005DF60;
    case 0x8005DF64u: goto label_8005DF64;
    case 0x8005DF68u: goto label_8005DF68;
    case 0x8005DF6Cu: goto label_8005DF6C;
    case 0x8005DF70u: goto label_8005DF70;
    case 0x8005DF74u: goto label_8005DF74;
    case 0x8005DF78u: goto label_8005DF78;
    case 0x8005DF7Cu: goto label_8005DF7C;
    case 0x8005DF80u: goto label_8005DF80;
    case 0x8005DF84u: goto label_8005DF84;
    case 0x8005DF88u: goto label_8005DF88;
    case 0x8005DF8Cu: goto label_8005DF8C;
    case 0x8005DF90u: goto label_8005DF90;
    case 0x8005DF94u: goto label_8005DF94;
    case 0x8005DF98u: goto label_8005DF98;
    case 0x8005DF9Cu: goto label_8005DF9C;
    case 0x8005DFA0u: goto label_8005DFA0;
    case 0x8005DFA4u: goto label_8005DFA4;
    case 0x8005DFA8u: goto label_8005DFA8;
    case 0x8005DFACu: goto label_8005DFAC;
    case 0x8005DFB0u: goto label_8005DFB0;
    case 0x8005DFB4u: goto label_8005DFB4;
    case 0x8005DFB8u: goto label_8005DFB8;
    case 0x8005DFBCu: goto label_8005DFBC;
    case 0x8005DFC0u: goto label_8005DFC0;
    case 0x8005DFC4u: goto label_8005DFC4;
    case 0x8005DFC8u: goto label_8005DFC8;
    case 0x8005DFCCu: goto label_8005DFCC;
    case 0x8005DFD0u: goto label_8005DFD0;
    case 0x8005DFD4u: goto label_8005DFD4;
    case 0x8005DFD8u: goto label_8005DFD8;
    case 0x8005DFDCu: goto label_8005DFDC;
    case 0x8005DFE0u: goto label_8005DFE0;
    case 0x8005DFE4u: goto label_8005DFE4;
    case 0x8005DFE8u: goto label_8005DFE8;
    case 0x8005DFECu: goto label_8005DFEC;
    case 0x8005DFF0u: goto label_8005DFF0;
    case 0x8005DFF4u: goto label_8005DFF4;
    case 0x8005DFF8u: goto label_8005DFF8;
    case 0x8005DFFCu: goto label_8005DFFC;
    case 0x8005E000u: goto label_8005E000;
    case 0x8005E004u: goto label_8005E004;
    case 0x8005E008u: goto label_8005E008;
    case 0x8005E00Cu: goto label_8005E00C;
    case 0x8005E010u: goto label_8005E010;
    case 0x8005E014u: goto label_8005E014;
    case 0x8005E018u: goto label_8005E018;
    case 0x8005E01Cu: goto label_8005E01C;
    case 0x8005E020u: goto label_8005E020;
    case 0x8005E024u: goto label_8005E024;
    case 0x8005E028u: goto label_8005E028;
    case 0x8005E02Cu: goto label_8005E02C;
    case 0x8005E030u: goto label_8005E030;
    case 0x8005E034u: goto label_8005E034;
    case 0x8005E038u: goto label_8005E038;
    case 0x8005E03Cu: goto label_8005E03C;
    case 0x8005E040u: goto label_8005E040;
    case 0x8005E044u: goto label_8005E044;
    case 0x8005E048u: goto label_8005E048;
    case 0x8005E04Cu: goto label_8005E04C;
    case 0x8005E050u: goto label_8005E050;
    case 0x8005E054u: goto label_8005E054;
    case 0x8005E058u: goto label_8005E058;
    case 0x8005E05Cu: goto label_8005E05C;
    case 0x8005E060u: goto label_8005E060;
    case 0x8005E064u: goto label_8005E064;
    case 0x8005E068u: goto label_8005E068;
    case 0x8005E06Cu: goto label_8005E06C;
    case 0x8005E070u: goto label_8005E070;
    case 0x8005E074u: goto label_8005E074;
    case 0x8005E078u: goto label_8005E078;
    case 0x8005E07Cu: goto label_8005E07C;
    case 0x8005E080u: goto label_8005E080;
    case 0x8005E084u: goto label_8005E084;
    case 0x8005E088u: goto label_8005E088;
    case 0x8005E08Cu: goto label_8005E08C;
    case 0x8005E090u: goto label_8005E090;
    case 0x8005E094u: goto label_8005E094;
    case 0x8005E098u: goto label_8005E098;
    case 0x8005E09Cu: goto label_8005E09C;
    case 0x8005E0A0u: goto label_8005E0A0;
    case 0x8005E0A4u: goto label_8005E0A4;
    case 0x8005E0A8u: goto label_8005E0A8;
    case 0x8005E0ACu: goto label_8005E0AC;
    case 0x8005E0B0u: goto label_8005E0B0;
    case 0x8005E0B4u: goto label_8005E0B4;
    case 0x8005E0B8u: goto label_8005E0B8;
    case 0x8005E0BCu: goto label_8005E0BC;
    case 0x8005E0C0u: goto label_8005E0C0;
    case 0x8005E0C4u: goto label_8005E0C4;
    case 0x8005E0C8u: goto label_8005E0C8;
    case 0x8005E0CCu: goto label_8005E0CC;
    case 0x8005E0D0u: goto label_8005E0D0;
    case 0x8005E0D4u: goto label_8005E0D4;
    case 0x8005E0D8u: goto label_8005E0D8;
    case 0x8005E0DCu: goto label_8005E0DC;
    case 0x8005E0E0u: goto label_8005E0E0;
    case 0x8005E0E4u: goto label_8005E0E4;
    case 0x8005E0E8u: goto label_8005E0E8;
    case 0x8005E0ECu: goto label_8005E0EC;
    case 0x8005E0F0u: goto label_8005E0F0;
    case 0x8005E0F4u: goto label_8005E0F4;
    case 0x8005E0F8u: goto label_8005E0F8;
    case 0x8005E0FCu: goto label_8005E0FC;
    case 0x8005E100u: goto label_8005E100;
    case 0x8005E104u: goto label_8005E104;
    case 0x8005E108u: goto label_8005E108;
    case 0x8005E10Cu: goto label_8005E10C;
    case 0x8005E110u: goto label_8005E110;
    case 0x8005E114u: goto label_8005E114;
    case 0x8005E118u: goto label_8005E118;
    case 0x8005E11Cu: goto label_8005E11C;
    case 0x8005E120u: goto label_8005E120;
    case 0x8005E124u: goto label_8005E124;
    case 0x8005E128u: goto label_8005E128;
    case 0x8005E12Cu: goto label_8005E12C;
    case 0x8005E130u: goto label_8005E130;
    case 0x8005E134u: goto label_8005E134;
    case 0x8005E138u: goto label_8005E138;
    case 0x8005E13Cu: goto label_8005E13C;
    case 0x8005E140u: goto label_8005E140;
    case 0x8005E144u: goto label_8005E144;
    case 0x8005E148u: goto label_8005E148;
    case 0x8005E14Cu: goto label_8005E14C;
    case 0x8005E150u: goto label_8005E150;
    case 0x8005E154u: goto label_8005E154;
    case 0x8005E158u: goto label_8005E158;
    case 0x8005E15Cu: goto label_8005E15C;
    case 0x8005E160u: goto label_8005E160;
    case 0x8005E164u: goto label_8005E164;
    case 0x8005E168u: goto label_8005E168;
    case 0x8005E16Cu: goto label_8005E16C;
    case 0x8005E170u: goto label_8005E170;
    case 0x8005E174u: goto label_8005E174;
    case 0x8005E178u: goto label_8005E178;
    case 0x8005E17Cu: goto label_8005E17C;
    case 0x8005E180u: goto label_8005E180;
    case 0x8005E184u: goto label_8005E184;
    case 0x8005E188u: goto label_8005E188;
    case 0x8005E18Cu: goto label_8005E18C;
    case 0x8005E190u: goto label_8005E190;
    case 0x8005E194u: goto label_8005E194;
    case 0x8005E198u: goto label_8005E198;
    case 0x8005E19Cu: goto label_8005E19C;
    case 0x8005E1A0u: goto label_8005E1A0;
    case 0x8005E1A4u: goto label_8005E1A4;
    case 0x8005E1A8u: goto label_8005E1A8;
    case 0x8005E1ACu: goto label_8005E1AC;
    case 0x8005E1B0u: goto label_8005E1B0;
    case 0x8005E1B4u: goto label_8005E1B4;
    case 0x8005E1B8u: goto label_8005E1B8;
    case 0x8005E1BCu: goto label_8005E1BC;
    case 0x8005E1C0u: goto label_8005E1C0;
    case 0x8005E1C4u: goto label_8005E1C4;
    case 0x8005E1C8u: goto label_8005E1C8;
    case 0x8005E1CCu: goto label_8005E1CC;
    case 0x8005E1D0u: goto label_8005E1D0;
    case 0x8005E1D4u: goto label_8005E1D4;
    case 0x8005E1D8u: goto label_8005E1D8;
    case 0x8005E1DCu: goto label_8005E1DC;
    case 0x8005E1E0u: goto label_8005E1E0;
    case 0x8005E1E4u: goto label_8005E1E4;
    case 0x8005E1E8u: goto label_8005E1E8;
    case 0x8005E1ECu: goto label_8005E1EC;
    case 0x8005E1F0u: goto label_8005E1F0;
    case 0x8005E1F4u: goto label_8005E1F4;
    case 0x8005E1F8u: goto label_8005E1F8;
    case 0x8005E1FCu: goto label_8005E1FC;
    case 0x8005E200u: goto label_8005E200;
    case 0x8005E204u: goto label_8005E204;
    case 0x8005E208u: goto label_8005E208;
    case 0x8005E20Cu: goto label_8005E20C;
    case 0x8005E210u: goto label_8005E210;
    case 0x8005E214u: goto label_8005E214;
    case 0x8005E218u: goto label_8005E218;
    case 0x8005E21Cu: goto label_8005E21C;
    case 0x8005E220u: goto label_8005E220;
    case 0x8005E224u: goto label_8005E224;
    case 0x8005E228u: goto label_8005E228;
    case 0x8005E22Cu: goto label_8005E22C;
    case 0x8005E230u: goto label_8005E230;
    case 0x8005E234u: goto label_8005E234;
    case 0x8005E238u: goto label_8005E238;
    case 0x8005E23Cu: goto label_8005E23C;
    case 0x8005E240u: goto label_8005E240;
    case 0x8005E244u: goto label_8005E244;
    case 0x8005E248u: goto label_8005E248;
    case 0x8005E24Cu: goto label_8005E24C;
    case 0x8005E250u: goto label_8005E250;
    case 0x8005E254u: goto label_8005E254;
    case 0x8005E258u: goto label_8005E258;
    case 0x8005E25Cu: goto label_8005E25C;
    case 0x8005E260u: goto label_8005E260;
    case 0x8005E264u: goto label_8005E264;
    case 0x8005E268u: goto label_8005E268;
    case 0x8005E26Cu: goto label_8005E26C;
    case 0x8005E270u: goto label_8005E270;
    case 0x8005E274u: goto label_8005E274;
    case 0x8005E278u: goto label_8005E278;
    case 0x8005E27Cu: goto label_8005E27C;
    case 0x8005E280u: goto label_8005E280;
    case 0x8005E284u: goto label_8005E284;
    case 0x8005E288u: goto label_8005E288;
    case 0x8005E28Cu: goto label_8005E28C;
    case 0x8005E290u: goto label_8005E290;
    case 0x8005E294u: goto label_8005E294;
    case 0x8005E298u: goto label_8005E298;
    case 0x8005E29Cu: goto label_8005E29C;
    case 0x8005E2A0u: goto label_8005E2A0;
    case 0x8005E2A4u: goto label_8005E2A4;
    case 0x8005E2A8u: goto label_8005E2A8;
    case 0x8005E2ACu: goto label_8005E2AC;
    case 0x8005E2B0u: goto label_8005E2B0;
    case 0x8005E2B4u: goto label_8005E2B4;
    case 0x8005E2B8u: goto label_8005E2B8;
    case 0x8005E2BCu: goto label_8005E2BC;
    case 0x8005E2C0u: goto label_8005E2C0;
    case 0x8005E2C4u: goto label_8005E2C4;
    case 0x8005E2C8u: goto label_8005E2C8;
    case 0x8005E2CCu: goto label_8005E2CC;
    case 0x8005E2D0u: goto label_8005E2D0;
    case 0x8005E2D4u: goto label_8005E2D4;
    case 0x8005E2D8u: goto label_8005E2D8;
    case 0x8005E2DCu: goto label_8005E2DC;
    case 0x8005E2E0u: goto label_8005E2E0;
    case 0x8005E2E4u: goto label_8005E2E4;
    case 0x8005E2E8u: goto label_8005E2E8;
    case 0x8005E2ECu: goto label_8005E2EC;
    case 0x8005E2F0u: goto label_8005E2F0;
    case 0x8005E2F4u: goto label_8005E2F4;
    case 0x8005E2F8u: goto label_8005E2F8;
    case 0x8005E2FCu: goto label_8005E2FC;
    case 0x8005E300u: goto label_8005E300;
    case 0x8005E304u: goto label_8005E304;
    case 0x8005E308u: goto label_8005E308;
    case 0x8005E30Cu: goto label_8005E30C;
    case 0x8005E310u: goto label_8005E310;
    case 0x8005E314u: goto label_8005E314;
    case 0x8005E318u: goto label_8005E318;
    case 0x8005E31Cu: goto label_8005E31C;
    case 0x8005E320u: goto label_8005E320;
    case 0x8005E324u: goto label_8005E324;
    case 0x8005E328u: goto label_8005E328;
    case 0x8005E32Cu: goto label_8005E32C;
    case 0x8005E330u: goto label_8005E330;
    case 0x8005E334u: goto label_8005E334;
    case 0x8005E338u: goto label_8005E338;
    case 0x8005E33Cu: goto label_8005E33C;
    case 0x8005E340u: goto label_8005E340;
    case 0x8005E344u: goto label_8005E344;
    case 0x8005E348u: goto label_8005E348;
    case 0x8005E34Cu: goto label_8005E34C;
    case 0x8005E350u: goto label_8005E350;
    case 0x8005E354u: goto label_8005E354;
    case 0x8005E358u: goto label_8005E358;
    case 0x8005E35Cu: goto label_8005E35C;
    case 0x8005E360u: goto label_8005E360;
    case 0x8005E364u: goto label_8005E364;
    case 0x8005E368u: goto label_8005E368;
    case 0x8005E36Cu: goto label_8005E36C;
    case 0x8005E370u: goto label_8005E370;
    case 0x8005E374u: goto label_8005E374;
    case 0x8005E378u: goto label_8005E378;
    case 0x8005E37Cu: goto label_8005E37C;
    case 0x8005E380u: goto label_8005E380;
    case 0x8005E384u: goto label_8005E384;
    case 0x8005E388u: goto label_8005E388;
    case 0x8005E38Cu: goto label_8005E38C;
    case 0x8005E390u: goto label_8005E390;
    case 0x8005E394u: goto label_8005E394;
    case 0x8005E398u: goto label_8005E398;
    case 0x8005E39Cu: goto label_8005E39C;
    case 0x8005E3A0u: goto label_8005E3A0;
    case 0x8005E3A4u: goto label_8005E3A4;
    case 0x8005E3A8u: goto label_8005E3A8;
    case 0x8005E3ACu: goto label_8005E3AC;
    case 0x8005E3B0u: goto label_8005E3B0;
    case 0x8005E3B4u: goto label_8005E3B4;
    case 0x8005E3B8u: goto label_8005E3B8;
    case 0x8005E3BCu: goto label_8005E3BC;
    case 0x8005E3C0u: goto label_8005E3C0;
    case 0x8005E3C4u: goto label_8005E3C4;
    case 0x8005E3C8u: goto label_8005E3C8;
    case 0x8005E3CCu: goto label_8005E3CC;
    case 0x8005E3D0u: goto label_8005E3D0;
    case 0x8005E3D4u: goto label_8005E3D4;
    case 0x8005E3D8u: goto label_8005E3D8;
    case 0x8005E3DCu: goto label_8005E3DC;
    case 0x8005E3E0u: goto label_8005E3E0;
    case 0x8005E3E4u: goto label_8005E3E4;
    case 0x8005E3E8u: goto label_8005E3E8;
    case 0x8005E3ECu: goto label_8005E3EC;
    case 0x8005E3F0u: goto label_8005E3F0;
    case 0x8005E3F4u: goto label_8005E3F4;
    case 0x8005E3F8u: goto label_8005E3F8;
    case 0x8005E3FCu: goto label_8005E3FC;
    case 0x8005E400u: goto label_8005E400;
    case 0x8005E404u: goto label_8005E404;
    case 0x8005E408u: goto label_8005E408;
    case 0x8005E40Cu: goto label_8005E40C;
    case 0x8005E410u: goto label_8005E410;
    case 0x8005E414u: goto label_8005E414;
    case 0x8005E418u: goto label_8005E418;
    case 0x8005E41Cu: goto label_8005E41C;
    case 0x8005E420u: goto label_8005E420;
    case 0x8005E424u: goto label_8005E424;
    case 0x8005E428u: goto label_8005E428;
    case 0x8005E42Cu: goto label_8005E42C;
    case 0x8005E430u: goto label_8005E430;
    case 0x8005E434u: goto label_8005E434;
    case 0x8005E438u: goto label_8005E438;
    case 0x8005E43Cu: goto label_8005E43C;
    case 0x8005E440u: goto label_8005E440;
    case 0x8005E444u: goto label_8005E444;
    case 0x8005E448u: goto label_8005E448;
    case 0x8005E44Cu: goto label_8005E44C;
    case 0x8005E450u: goto label_8005E450;
    case 0x8005E454u: goto label_8005E454;
    case 0x8005E458u: goto label_8005E458;
    case 0x8005E45Cu: goto label_8005E45C;
    case 0x8005E460u: goto label_8005E460;
    case 0x8005E464u: goto label_8005E464;
    case 0x8005E468u: goto label_8005E468;
    case 0x8005E46Cu: goto label_8005E46C;
    case 0x8005E470u: goto label_8005E470;
    case 0x8005E474u: goto label_8005E474;
    case 0x8005E478u: goto label_8005E478;
    case 0x8005E47Cu: goto label_8005E47C;
    case 0x8005E480u: goto label_8005E480;
    case 0x8005E484u: goto label_8005E484;
    case 0x8005E488u: goto label_8005E488;
    case 0x8005E48Cu: goto label_8005E48C;
    case 0x8005E490u: goto label_8005E490;
    case 0x8005E494u: goto label_8005E494;
    case 0x8005E498u: goto label_8005E498;
    case 0x8005E49Cu: goto label_8005E49C;
    case 0x8005E4A0u: goto label_8005E4A0;
    case 0x8005E4A4u: goto label_8005E4A4;
    case 0x8005E4A8u: goto label_8005E4A8;
    case 0x8005E4ACu: goto label_8005E4AC;
    case 0x8005E4B0u: goto label_8005E4B0;
    case 0x8005E4B4u: goto label_8005E4B4;
    case 0x8005E4B8u: goto label_8005E4B8;
    case 0x8005E4BCu: goto label_8005E4BC;
    case 0x8005E4C0u: goto label_8005E4C0;
    case 0x8005E4C4u: goto label_8005E4C4;
    case 0x8005E4C8u: goto label_8005E4C8;
    case 0x8005E4CCu: goto label_8005E4CC;
    case 0x8005E4D0u: goto label_8005E4D0;
    case 0x8005E4D4u: goto label_8005E4D4;
    case 0x8005E4D8u: goto label_8005E4D8;
    case 0x8005E4DCu: goto label_8005E4DC;
    case 0x8005E4E0u: goto label_8005E4E0;
    case 0x8005E4E4u: goto label_8005E4E4;
    case 0x8005E4E8u: goto label_8005E4E8;
    case 0x8005E4ECu: goto label_8005E4EC;
    case 0x8005E4F0u: goto label_8005E4F0;
    case 0x8005E4F4u: goto label_8005E4F4;
    case 0x8005E4F8u: goto label_8005E4F8;
    case 0x8005E4FCu: goto label_8005E4FC;
    case 0x8005E500u: goto label_8005E500;
    case 0x8005E504u: goto label_8005E504;
    case 0x8005E508u: goto label_8005E508;
    case 0x8005E50Cu: goto label_8005E50C;
    case 0x8005E510u: goto label_8005E510;
    case 0x8005E514u: goto label_8005E514;
    case 0x8005E518u: goto label_8005E518;
    case 0x8005E51Cu: goto label_8005E51C;
    case 0x8005E520u: goto label_8005E520;
    case 0x8005E524u: goto label_8005E524;
    case 0x8005E528u: goto label_8005E528;
    case 0x8005E52Cu: goto label_8005E52C;
    case 0x8005E530u: goto label_8005E530;
    case 0x8005E534u: goto label_8005E534;
    case 0x8005E538u: goto label_8005E538;
    case 0x8005E53Cu: goto label_8005E53C;
    case 0x8005E540u: goto label_8005E540;
    case 0x8005E544u: goto label_8005E544;
    case 0x8005E548u: goto label_8005E548;
    case 0x8005E54Cu: goto label_8005E54C;
    case 0x8005E550u: goto label_8005E550;
    case 0x8005E554u: goto label_8005E554;
    case 0x8005E558u: goto label_8005E558;
    case 0x8005E55Cu: goto label_8005E55C;
    case 0x8005E560u: goto label_8005E560;
    case 0x8005E564u: goto label_8005E564;
    case 0x8005E568u: goto label_8005E568;
    case 0x8005E56Cu: goto label_8005E56C;
    case 0x8005E570u: goto label_8005E570;
    case 0x8005E574u: goto label_8005E574;
    case 0x8005E578u: goto label_8005E578;
    case 0x8005E57Cu: goto label_8005E57C;
    case 0x8005E580u: goto label_8005E580;
    case 0x8005E584u: goto label_8005E584;
    case 0x8005E588u: goto label_8005E588;
    case 0x8005E58Cu: goto label_8005E58C;
    case 0x8005E590u: goto label_8005E590;
    case 0x8005E594u: goto label_8005E594;
    case 0x8005E598u: goto label_8005E598;
    case 0x8005E59Cu: goto label_8005E59C;
    case 0x8005E5A0u: goto label_8005E5A0;
    case 0x8005E5A4u: goto label_8005E5A4;
    case 0x8005E5A8u: goto label_8005E5A8;
    case 0x8005E5ACu: goto label_8005E5AC;
    case 0x8005E5B0u: goto label_8005E5B0;
    case 0x8005E5B4u: goto label_8005E5B4;
    case 0x8005E5B8u: goto label_8005E5B8;
    case 0x8005E5BCu: goto label_8005E5BC;
    case 0x8005E5C0u: goto label_8005E5C0;
    case 0x8005E5C4u: goto label_8005E5C4;
    case 0x8005E5C8u: goto label_8005E5C8;
    case 0x8005E5CCu: goto label_8005E5CC;
    case 0x8005E5D0u: goto label_8005E5D0;
    case 0x8005E5D4u: goto label_8005E5D4;
    case 0x8005E5D8u: goto label_8005E5D8;
    case 0x8005E5DCu: goto label_8005E5DC;
    case 0x8005E5E0u: goto label_8005E5E0;
    case 0x8005E5E4u: goto label_8005E5E4;
    case 0x8005E5E8u: goto label_8005E5E8;
    case 0x8005E5ECu: goto label_8005E5EC;
    case 0x8005E5F0u: goto label_8005E5F0;
    case 0x8005E5F4u: goto label_8005E5F4;
    case 0x8005E5F8u: goto label_8005E5F8;
    case 0x8005E5FCu: goto label_8005E5FC;
    case 0x8005E600u: goto label_8005E600;
    case 0x8005E604u: goto label_8005E604;
    case 0x8005E608u: goto label_8005E608;
    case 0x8005E60Cu: goto label_8005E60C;
    case 0x8005E610u: goto label_8005E610;
    case 0x8005E614u: goto label_8005E614;
    case 0x8005E618u: goto label_8005E618;
    case 0x8005E61Cu: goto label_8005E61C;
    case 0x8005E620u: goto label_8005E620;
    case 0x8005E624u: goto label_8005E624;
    case 0x8005E628u: goto label_8005E628;
    case 0x8005E62Cu: goto label_8005E62C;
    case 0x8005E630u: goto label_8005E630;
    case 0x8005E634u: goto label_8005E634;
    case 0x8005E638u: goto label_8005E638;
    case 0x8005E63Cu: goto label_8005E63C;
    case 0x8005E640u: goto label_8005E640;
    case 0x8005E644u: goto label_8005E644;
    case 0x8005E648u: goto label_8005E648;
    case 0x8005E64Cu: goto label_8005E64C;
    case 0x8005E650u: goto label_8005E650;
    case 0x8005E654u: goto label_8005E654;
    case 0x8005E658u: goto label_8005E658;
    case 0x8005E65Cu: goto label_8005E65C;
    case 0x8005E660u: goto label_8005E660;
    case 0x8005E664u: goto label_8005E664;
    case 0x8005E668u: goto label_8005E668;
    case 0x8005E66Cu: goto label_8005E66C;
    case 0x8005E670u: goto label_8005E670;
    case 0x8005E674u: goto label_8005E674;
    case 0x8005E678u: goto label_8005E678;
    case 0x8005E67Cu: goto label_8005E67C;
    case 0x8005E680u: goto label_8005E680;
    case 0x8005E684u: goto label_8005E684;
    case 0x8005E688u: goto label_8005E688;
    case 0x8005E68Cu: goto label_8005E68C;
    case 0x8005E690u: goto label_8005E690;
    case 0x8005E694u: goto label_8005E694;
    case 0x8005E698u: goto label_8005E698;
    case 0x8005E69Cu: goto label_8005E69C;
    case 0x8005E6A0u: goto label_8005E6A0;
    case 0x8005E6A4u: goto label_8005E6A4;
    case 0x8005E6A8u: goto label_8005E6A8;
    case 0x8005E6ACu: goto label_8005E6AC;
    case 0x8005E6B0u: goto label_8005E6B0;
    case 0x8005E6B4u: goto label_8005E6B4;
    case 0x8005E6B8u: goto label_8005E6B8;
    case 0x8005E6BCu: goto label_8005E6BC;
    case 0x8005E6C0u: goto label_8005E6C0;
    case 0x8005E6C4u: goto label_8005E6C4;
    case 0x8005E6C8u: goto label_8005E6C8;
    case 0x8005E6CCu: goto label_8005E6CC;
    case 0x8005E6D0u: goto label_8005E6D0;
    case 0x8005E6D4u: goto label_8005E6D4;
    case 0x8005E6D8u: goto label_8005E6D8;
    case 0x8005E6DCu: goto label_8005E6DC;
    case 0x8005E6E0u: goto label_8005E6E0;
    case 0x8005E6E4u: goto label_8005E6E4;
    case 0x8005E6E8u: goto label_8005E6E8;
    case 0x8005E6ECu: goto label_8005E6EC;
    case 0x8005E6F0u: goto label_8005E6F0;
    case 0x8005E6F4u: goto label_8005E6F4;
    case 0x8005E6F8u: goto label_8005E6F8;
    case 0x8005E6FCu: goto label_8005E6FC;
    case 0x8005E700u: goto label_8005E700;
    case 0x8005E704u: goto label_8005E704;
    case 0x8005E708u: goto label_8005E708;
    case 0x8005E70Cu: goto label_8005E70C;
    case 0x8005E710u: goto label_8005E710;
    case 0x8005E714u: goto label_8005E714;
    case 0x8005E718u: goto label_8005E718;
    case 0x8005E71Cu: goto label_8005E71C;
    case 0x8005E720u: goto label_8005E720;
    case 0x8005E724u: goto label_8005E724;
    case 0x8005E728u: goto label_8005E728;
    case 0x8005E72Cu: goto label_8005E72C;
    case 0x8005E730u: goto label_8005E730;
    case 0x8005E734u: goto label_8005E734;
    case 0x8005E738u: goto label_8005E738;
    case 0x8005E73Cu: goto label_8005E73C;
    case 0x8005E740u: goto label_8005E740;
    case 0x8005E744u: goto label_8005E744;
    case 0x8005E748u: goto label_8005E748;
    case 0x8005E74Cu: goto label_8005E74C;
    case 0x8005E750u: goto label_8005E750;
    case 0x8005E754u: goto label_8005E754;
    case 0x8005E758u: goto label_8005E758;
    case 0x8005E75Cu: goto label_8005E75C;
    case 0x8005E760u: goto label_8005E760;
    case 0x8005E764u: goto label_8005E764;
    case 0x8005E768u: goto label_8005E768;
    case 0x8005E76Cu: goto label_8005E76C;
    case 0x8005E770u: goto label_8005E770;
    case 0x8005E774u: goto label_8005E774;
    case 0x8005E778u: goto label_8005E778;
    case 0x8005E77Cu: goto label_8005E77C;
    case 0x8005E780u: goto label_8005E780;
    case 0x8005E784u: goto label_8005E784;
    case 0x8005E788u: goto label_8005E788;
    case 0x8005E78Cu: goto label_8005E78C;
    case 0x8005E790u: goto label_8005E790;
    case 0x8005E794u: goto label_8005E794;
    case 0x8005E798u: goto label_8005E798;
    case 0x8005E79Cu: goto label_8005E79C;
    case 0x8005E7A0u: goto label_8005E7A0;
    case 0x8005E7A4u: goto label_8005E7A4;
    case 0x8005E7A8u: goto label_8005E7A8;
    case 0x8005E7ACu: goto label_8005E7AC;
    case 0x8005E7B0u: goto label_8005E7B0;
    case 0x8005E7B4u: goto label_8005E7B4;
    case 0x8005E7B8u: goto label_8005E7B8;
    case 0x8005E7BCu: goto label_8005E7BC;
    case 0x8005E7C0u: goto label_8005E7C0;
    case 0x8005E7C4u: goto label_8005E7C4;
    case 0x8005E7C8u: goto label_8005E7C8;
    case 0x8005E7CCu: goto label_8005E7CC;
    case 0x8005E7D0u: goto label_8005E7D0;
    case 0x8005E7D4u: goto label_8005E7D4;
    case 0x8005E7D8u: goto label_8005E7D8;
    case 0x8005E7DCu: goto label_8005E7DC;
    case 0x8005E7E0u: goto label_8005E7E0;
    case 0x8005E7E4u: goto label_8005E7E4;
    case 0x8005E7E8u: goto label_8005E7E8;
    case 0x8005E7ECu: goto label_8005E7EC;
    case 0x8005E7F0u: goto label_8005E7F0;
    case 0x8005E7F4u: goto label_8005E7F4;
    case 0x8005E7F8u: goto label_8005E7F8;
    case 0x8005E7FCu: goto label_8005E7FC;
    case 0x8005E800u: goto label_8005E800;
    case 0x8005E804u: goto label_8005E804;
    case 0x8005E808u: goto label_8005E808;
    case 0x8005E80Cu: goto label_8005E80C;
    case 0x8005E810u: goto label_8005E810;
    case 0x8005E814u: goto label_8005E814;
    case 0x8005E818u: goto label_8005E818;
    case 0x8005E81Cu: goto label_8005E81C;
    case 0x8005E820u: goto label_8005E820;
    case 0x8005E824u: goto label_8005E824;
    case 0x8005E828u: goto label_8005E828;
    case 0x8005E82Cu: goto label_8005E82C;
    case 0x8005E830u: goto label_8005E830;
    case 0x8005E834u: goto label_8005E834;
    case 0x8005E838u: goto label_8005E838;
    case 0x8005E83Cu: goto label_8005E83C;
    case 0x8005E840u: goto label_8005E840;
    case 0x8005E844u: goto label_8005E844;
    case 0x8005E848u: goto label_8005E848;
    case 0x8005E84Cu: goto label_8005E84C;
    case 0x8005E850u: goto label_8005E850;
    case 0x8005E854u: goto label_8005E854;
    case 0x8005E858u: goto label_8005E858;
    case 0x8005E85Cu: goto label_8005E85C;
    case 0x8005E860u: goto label_8005E860;
    case 0x8005E864u: goto label_8005E864;
    case 0x8005E868u: goto label_8005E868;
    case 0x8005E86Cu: goto label_8005E86C;
    case 0x8005E870u: goto label_8005E870;
    case 0x8005E874u: goto label_8005E874;
    case 0x8005E878u: goto label_8005E878;
    case 0x8005E87Cu: goto label_8005E87C;
    case 0x8005E880u: goto label_8005E880;
    case 0x8005E884u: goto label_8005E884;
    case 0x8005E888u: goto label_8005E888;
    case 0x8005E88Cu: goto label_8005E88C;
    case 0x8005E890u: goto label_8005E890;
    case 0x8005E894u: goto label_8005E894;
    case 0x8005E898u: goto label_8005E898;
    case 0x8005E89Cu: goto label_8005E89C;
    case 0x8005E8A0u: goto label_8005E8A0;
    case 0x8005E8A4u: goto label_8005E8A4;
    case 0x8005E8A8u: goto label_8005E8A8;
    case 0x8005E8ACu: goto label_8005E8AC;
    case 0x8005E8B0u: goto label_8005E8B0;
    case 0x8005E8B4u: goto label_8005E8B4;
    case 0x8005E8B8u: goto label_8005E8B8;
    case 0x8005E8BCu: goto label_8005E8BC;
    case 0x8005E8C0u: goto label_8005E8C0;
    case 0x8005E8C4u: goto label_8005E8C4;
    case 0x8005E8C8u: goto label_8005E8C8;
    case 0x8005E8CCu: goto label_8005E8CC;
    case 0x8005E8D0u: goto label_8005E8D0;
    case 0x8005E8D4u: goto label_8005E8D4;
    case 0x8005E8D8u: goto label_8005E8D8;
    case 0x8005E8DCu: goto label_8005E8DC;
    case 0x8005E8E0u: goto label_8005E8E0;
    case 0x8005E8E4u: goto label_8005E8E4;
    case 0x8005E8E8u: goto label_8005E8E8;
    case 0x8005E8ECu: goto label_8005E8EC;
    case 0x8005E8F0u: goto label_8005E8F0;
    case 0x8005E8F4u: goto label_8005E8F4;
    case 0x8005E8F8u: goto label_8005E8F8;
    case 0x8005E8FCu: goto label_8005E8FC;
    case 0x8005E900u: goto label_8005E900;
    case 0x8005E904u: goto label_8005E904;
    case 0x8005E908u: goto label_8005E908;
    case 0x8005E90Cu: goto label_8005E90C;
    case 0x8005E910u: goto label_8005E910;
    case 0x8005E914u: goto label_8005E914;
    case 0x8005E918u: goto label_8005E918;
    case 0x8005E91Cu: goto label_8005E91C;
    case 0x8005E920u: goto label_8005E920;
    case 0x8005E924u: goto label_8005E924;
    case 0x8005E928u: goto label_8005E928;
    case 0x8005E92Cu: goto label_8005E92C;
    case 0x8005E930u: goto label_8005E930;
    case 0x8005E934u: goto label_8005E934;
    case 0x8005E938u: goto label_8005E938;
    case 0x8005E93Cu: goto label_8005E93C;
    case 0x8005E940u: goto label_8005E940;
    case 0x8005E944u: goto label_8005E944;
    case 0x8005E948u: goto label_8005E948;
    case 0x8005E94Cu: goto label_8005E94C;
    case 0x8005E950u: goto label_8005E950;
    case 0x8005E954u: goto label_8005E954;
    case 0x8005E958u: goto label_8005E958;
    case 0x8005E95Cu: goto label_8005E95C;
    case 0x8005E960u: goto label_8005E960;
    case 0x8005E964u: goto label_8005E964;
    case 0x8005E968u: goto label_8005E968;
    case 0x8005E96Cu: goto label_8005E96C;
    case 0x8005E970u: goto label_8005E970;
    case 0x8005E974u: goto label_8005E974;
    case 0x8005E978u: goto label_8005E978;
    case 0x8005E97Cu: goto label_8005E97C;
    case 0x8005E980u: goto label_8005E980;
    case 0x8005E984u: goto label_8005E984;
    case 0x8005E988u: goto label_8005E988;
    case 0x8005E98Cu: goto label_8005E98C;
    case 0x8005E990u: goto label_8005E990;
    case 0x8005E994u: goto label_8005E994;
    case 0x8005E998u: goto label_8005E998;
    case 0x8005E99Cu: goto label_8005E99C;
    case 0x8005E9A0u: goto label_8005E9A0;
    case 0x8005E9A4u: goto label_8005E9A4;
    case 0x8005E9A8u: goto label_8005E9A8;
    case 0x8005E9ACu: goto label_8005E9AC;
    case 0x8005E9B0u: goto label_8005E9B0;
    case 0x8005E9B4u: goto label_8005E9B4;
    case 0x8005E9B8u: goto label_8005E9B8;
    case 0x8005E9BCu: goto label_8005E9BC;
    case 0x8005E9C0u: goto label_8005E9C0;
    case 0x8005E9C4u: goto label_8005E9C4;
    case 0x8005E9C8u: goto label_8005E9C8;
    case 0x8005E9CCu: goto label_8005E9CC;
    case 0x8005E9D0u: goto label_8005E9D0;
    case 0x8005E9D4u: goto label_8005E9D4;
    case 0x8005E9D8u: goto label_8005E9D8;
    case 0x8005E9DCu: goto label_8005E9DC;
    case 0x8005E9E0u: goto label_8005E9E0;
    case 0x8005E9E4u: goto label_8005E9E4;
    case 0x8005E9E8u: goto label_8005E9E8;
    case 0x8005E9ECu: goto label_8005E9EC;
    case 0x8005E9F0u: goto label_8005E9F0;
    case 0x8005E9F4u: goto label_8005E9F4;
    case 0x8005E9F8u: goto label_8005E9F8;
    case 0x8005E9FCu: goto label_8005E9FC;
    case 0x8005EA00u: goto label_8005EA00;
    case 0x8005EA04u: goto label_8005EA04;
    case 0x8005EA08u: goto label_8005EA08;
    case 0x8005EA0Cu: goto label_8005EA0C;
    case 0x8005EA10u: goto label_8005EA10;
    case 0x8005EA14u: goto label_8005EA14;
    case 0x8005EA18u: goto label_8005EA18;
    case 0x8005EA1Cu: goto label_8005EA1C;
    case 0x8005EA20u: goto label_8005EA20;
    case 0x8005EA24u: goto label_8005EA24;
    case 0x8005EA28u: goto label_8005EA28;
    case 0x8005EA2Cu: goto label_8005EA2C;
    case 0x8005EA30u: goto label_8005EA30;
    case 0x8005EA34u: goto label_8005EA34;
    case 0x8005EA38u: goto label_8005EA38;
    case 0x8005EA3Cu: goto label_8005EA3C;
    case 0x8005EA40u: goto label_8005EA40;
    case 0x8005EA44u: goto label_8005EA44;
    case 0x8005EA48u: goto label_8005EA48;
    case 0x8005EA4Cu: goto label_8005EA4C;
    case 0x8005EA50u: goto label_8005EA50;
    case 0x8005EA54u: goto label_8005EA54;
    case 0x8005EA58u: goto label_8005EA58;
    case 0x8005EA5Cu: goto label_8005EA5C;
    case 0x8005EA60u: goto label_8005EA60;
    case 0x8005EA64u: goto label_8005EA64;
    case 0x8005EA68u: goto label_8005EA68;
    case 0x8005EA6Cu: goto label_8005EA6C;
    case 0x8005EA70u: goto label_8005EA70;
    case 0x8005EA74u: goto label_8005EA74;
    case 0x8005EA78u: goto label_8005EA78;
    case 0x8005EA7Cu: goto label_8005EA7C;
    case 0x8005EA80u: goto label_8005EA80;
    case 0x8005EA84u: goto label_8005EA84;
    case 0x8005EA88u: goto label_8005EA88;
    case 0x8005EA8Cu: goto label_8005EA8C;
    case 0x8005EA90u: goto label_8005EA90;
    case 0x8005EA94u: goto label_8005EA94;
    case 0x8005EA98u: goto label_8005EA98;
    case 0x8005EA9Cu: goto label_8005EA9C;
    case 0x8005EAA0u: goto label_8005EAA0;
    case 0x8005EAA4u: goto label_8005EAA4;
    case 0x8005EAA8u: goto label_8005EAA8;
    case 0x8005EAACu: goto label_8005EAAC;
    case 0x8005EAB0u: goto label_8005EAB0;
    case 0x8005EAB4u: goto label_8005EAB4;
    case 0x8005EAB8u: goto label_8005EAB8;
    case 0x8005EABCu: goto label_8005EABC;
    case 0x8005EAC0u: goto label_8005EAC0;
    case 0x8005EAC4u: goto label_8005EAC4;
    case 0x8005EAC8u: goto label_8005EAC8;
    case 0x8005EACCu: goto label_8005EACC;
    case 0x8005EAD0u: goto label_8005EAD0;
    case 0x8005EAD4u: goto label_8005EAD4;
    case 0x8005EAD8u: goto label_8005EAD8;
    case 0x8005EADCu: goto label_8005EADC;
    case 0x8005EAE0u: goto label_8005EAE0;
    case 0x8005EAE4u: goto label_8005EAE4;
    case 0x8005EAE8u: goto label_8005EAE8;
    case 0x8005EAECu: goto label_8005EAEC;
    case 0x8005EAF0u: goto label_8005EAF0;
    case 0x8005EAF4u: goto label_8005EAF4;
    case 0x8005EAF8u: goto label_8005EAF8;
    case 0x8005EAFCu: goto label_8005EAFC;
    case 0x8005EB00u: goto label_8005EB00;
    case 0x8005EB04u: goto label_8005EB04;
    case 0x8005EB08u: goto label_8005EB08;
    case 0x8005EB0Cu: goto label_8005EB0C;
    case 0x8005EB10u: goto label_8005EB10;
    case 0x8005EB14u: goto label_8005EB14;
    case 0x8005EB18u: goto label_8005EB18;
    case 0x8005EB1Cu: goto label_8005EB1C;
    case 0x8005EB20u: goto label_8005EB20;
    case 0x8005EB24u: goto label_8005EB24;
    case 0x8005EB28u: goto label_8005EB28;
    case 0x8005EB2Cu: goto label_8005EB2C;
    case 0x8005EB30u: goto label_8005EB30;
    case 0x8005EB34u: goto label_8005EB34;
    case 0x8005EB38u: goto label_8005EB38;
    case 0x8005EB3Cu: goto label_8005EB3C;
    case 0x8005EB40u: goto label_8005EB40;
    case 0x8005EB44u: goto label_8005EB44;
    case 0x8005EB48u: goto label_8005EB48;
    case 0x8005EB4Cu: goto label_8005EB4C;
    case 0x8005EB50u: goto label_8005EB50;
    case 0x8005EB54u: goto label_8005EB54;
    case 0x8005EB58u: goto label_8005EB58;
    case 0x8005EB5Cu: goto label_8005EB5C;
    case 0x8005EB60u: goto label_8005EB60;
    case 0x8005EB64u: goto label_8005EB64;
    case 0x8005EB68u: goto label_8005EB68;
    case 0x8005EB6Cu: goto label_8005EB6C;
    case 0x8005EB70u: goto label_8005EB70;
    case 0x8005EB74u: goto label_8005EB74;
    case 0x8005EB78u: goto label_8005EB78;
    case 0x8005EB7Cu: goto label_8005EB7C;
    case 0x8005EB80u: goto label_8005EB80;
    case 0x8005EB84u: goto label_8005EB84;
    case 0x8005EB88u: goto label_8005EB88;
    case 0x8005EB8Cu: goto label_8005EB8C;
    case 0x8005EB90u: goto label_8005EB90;
    case 0x8005EB94u: goto label_8005EB94;
    case 0x8005EB98u: goto label_8005EB98;
    case 0x8005EB9Cu: goto label_8005EB9C;
    case 0x8005EBA0u: goto label_8005EBA0;
    case 0x8005EBA4u: goto label_8005EBA4;
    case 0x8005EBA8u: goto label_8005EBA8;
    case 0x8005EBACu: goto label_8005EBAC;
    case 0x8005EBB0u: goto label_8005EBB0;
    case 0x8005EBB4u: goto label_8005EBB4;
    case 0x8005EBB8u: goto label_8005EBB8;
    case 0x8005EBBCu: goto label_8005EBBC;
    case 0x8005EBC0u: goto label_8005EBC0;
    case 0x8005EBC4u: goto label_8005EBC4;
    case 0x8005EBC8u: goto label_8005EBC8;
    case 0x8005EBCCu: goto label_8005EBCC;
    case 0x8005EBD0u: goto label_8005EBD0;
    case 0x8005EBD4u: goto label_8005EBD4;
    case 0x8005EBD8u: goto label_8005EBD8;
    case 0x8005EBDCu: goto label_8005EBDC;
    case 0x8005EBE0u: goto label_8005EBE0;
    case 0x8005EBE4u: goto label_8005EBE4;
    case 0x8005EBE8u: goto label_8005EBE8;
    case 0x8005EBECu: goto label_8005EBEC;
    case 0x8005EBF0u: goto label_8005EBF0;
    case 0x8005EBF4u: goto label_8005EBF4;
    case 0x8005EBF8u: goto label_8005EBF8;
    case 0x8005EBFCu: goto label_8005EBFC;
    case 0x8005EC00u: goto label_8005EC00;
    case 0x8005EC04u: goto label_8005EC04;
    case 0x8005EC08u: goto label_8005EC08;
    case 0x8005EC0Cu: goto label_8005EC0C;
    case 0x8005EC10u: goto label_8005EC10;
    case 0x8005EC14u: goto label_8005EC14;
    case 0x8005EC18u: goto label_8005EC18;
    case 0x8005EC1Cu: goto label_8005EC1C;
    case 0x8005EC20u: goto label_8005EC20;
    case 0x8005EC24u: goto label_8005EC24;
    case 0x8005EC28u: goto label_8005EC28;
    case 0x8005EC2Cu: goto label_8005EC2C;
    case 0x8005EC30u: goto label_8005EC30;
    case 0x8005EC34u: goto label_8005EC34;
    case 0x8005EC38u: goto label_8005EC38;
    case 0x8005EC3Cu: goto label_8005EC3C;
    case 0x8005EC40u: goto label_8005EC40;
    case 0x8005EC44u: goto label_8005EC44;
    case 0x8005EC48u: goto label_8005EC48;
    case 0x8005EC4Cu: goto label_8005EC4C;
    case 0x8005EC50u: goto label_8005EC50;
    case 0x8005EC54u: goto label_8005EC54;
    case 0x8005EC58u: goto label_8005EC58;
    case 0x8005EC5Cu: goto label_8005EC5C;
    case 0x8005EC60u: goto label_8005EC60;
    case 0x8005EC64u: goto label_8005EC64;
    case 0x8005EC68u: goto label_8005EC68;
    case 0x8005EC6Cu: goto label_8005EC6C;
    case 0x8005EC70u: goto label_8005EC70;
    case 0x8005EC74u: goto label_8005EC74;
    case 0x8005EC78u: goto label_8005EC78;
    case 0x8005EC7Cu: goto label_8005EC7C;
    case 0x8005EC80u: goto label_8005EC80;
    case 0x8005EC84u: goto label_8005EC84;
    case 0x8005EC88u: goto label_8005EC88;
    case 0x8005EC8Cu: goto label_8005EC8C;
    case 0x8005EC90u: goto label_8005EC90;
    case 0x8005EC94u: goto label_8005EC94;
    case 0x8005EC98u: goto label_8005EC98;
    case 0x8005EC9Cu: goto label_8005EC9C;
    case 0x8005ECA0u: goto label_8005ECA0;
    case 0x8005ECA4u: goto label_8005ECA4;
    case 0x8005ECA8u: goto label_8005ECA8;
    case 0x8005ECACu: goto label_8005ECAC;
    case 0x8005ECB0u: goto label_8005ECB0;
    case 0x8005ECB4u: goto label_8005ECB4;
    case 0x8005ECB8u: goto label_8005ECB8;
    case 0x8005ECBCu: goto label_8005ECBC;
    case 0x8005ECC0u: goto label_8005ECC0;
    case 0x8005ECC4u: goto label_8005ECC4;
    case 0x8005ECC8u: goto label_8005ECC8;
    case 0x8005ECCCu: goto label_8005ECCC;
    case 0x8005ECD0u: goto label_8005ECD0;
    case 0x8005ECD4u: goto label_8005ECD4;
    case 0x8005ECD8u: goto label_8005ECD8;
    case 0x8005ECDCu: goto label_8005ECDC;
    case 0x8005ECE0u: goto label_8005ECE0;
    case 0x8005ECE4u: goto label_8005ECE4;
    case 0x8005ECE8u: goto label_8005ECE8;
    case 0x8005ECECu: goto label_8005ECEC;
    case 0x8005ECF0u: goto label_8005ECF0;
    case 0x8005ECF4u: goto label_8005ECF4;
    case 0x8005ECF8u: goto label_8005ECF8;
    case 0x8005ECFCu: goto label_8005ECFC;
    case 0x8005ED00u: goto label_8005ED00;
    case 0x8005ED04u: goto label_8005ED04;
    case 0x8005ED08u: goto label_8005ED08;
    case 0x8005ED0Cu: goto label_8005ED0C;
    case 0x8005ED10u: goto label_8005ED10;
    case 0x8005ED14u: goto label_8005ED14;
    case 0x8005ED18u: goto label_8005ED18;
    case 0x8005ED1Cu: goto label_8005ED1C;
    case 0x8005ED20u: goto label_8005ED20;
    case 0x8005ED24u: goto label_8005ED24;
    case 0x8005ED28u: goto label_8005ED28;
    case 0x8005ED2Cu: goto label_8005ED2C;
    case 0x8005ED30u: goto label_8005ED30;
    case 0x8005ED34u: goto label_8005ED34;
    case 0x8005ED38u: goto label_8005ED38;
    case 0x8005ED3Cu: goto label_8005ED3C;
    case 0x8005ED40u: goto label_8005ED40;
    case 0x8005ED44u: goto label_8005ED44;
    case 0x8005ED48u: goto label_8005ED48;
    case 0x8005ED4Cu: goto label_8005ED4C;
    case 0x8005ED50u: goto label_8005ED50;
    case 0x8005ED54u: goto label_8005ED54;
    case 0x8005ED58u: goto label_8005ED58;
    case 0x8005ED5Cu: goto label_8005ED5C;
    case 0x8005ED60u: goto label_8005ED60;
    case 0x8005ED64u: goto label_8005ED64;
    case 0x8005ED68u: goto label_8005ED68;
    case 0x8005ED6Cu: goto label_8005ED6C;
    case 0x8005ED70u: goto label_8005ED70;
    case 0x8005ED74u: goto label_8005ED74;
    case 0x8005ED78u: goto label_8005ED78;
    case 0x8005ED7Cu: goto label_8005ED7C;
    case 0x8005ED80u: goto label_8005ED80;
    case 0x8005ED84u: goto label_8005ED84;
    case 0x8005ED88u: goto label_8005ED88;
    case 0x8005ED8Cu: goto label_8005ED8C;
    case 0x8005ED90u: goto label_8005ED90;
    case 0x8005ED94u: goto label_8005ED94;
    case 0x8005ED98u: goto label_8005ED98;
    case 0x8005ED9Cu: goto label_8005ED9C;
    case 0x8005EDA0u: goto label_8005EDA0;
    case 0x8005EDA4u: goto label_8005EDA4;
    case 0x8005EDA8u: goto label_8005EDA8;
    case 0x8005EDACu: goto label_8005EDAC;
    case 0x8005EDB0u: goto label_8005EDB0;
    case 0x8005EDB4u: goto label_8005EDB4;
    case 0x8005EDB8u: goto label_8005EDB8;
    case 0x8005EDBCu: goto label_8005EDBC;
    case 0x8005EDC0u: goto label_8005EDC0;
    case 0x8005EDC4u: goto label_8005EDC4;
    case 0x8005EDC8u: goto label_8005EDC8;
    case 0x8005EDCCu: goto label_8005EDCC;
    case 0x8005EDD0u: goto label_8005EDD0;
    case 0x8005EDD4u: goto label_8005EDD4;
    case 0x8005EDD8u: goto label_8005EDD8;
    case 0x8005EDDCu: goto label_8005EDDC;
    case 0x8005EDE0u: goto label_8005EDE0;
    case 0x8005EDE4u: goto label_8005EDE4;
    case 0x8005EDE8u: goto label_8005EDE8;
    case 0x8005EDECu: goto label_8005EDEC;
    case 0x8005EDF0u: goto label_8005EDF0;
    case 0x8005EDF4u: goto label_8005EDF4;
    case 0x8005EDF8u: goto label_8005EDF8;
    case 0x8005EDFCu: goto label_8005EDFC;
    case 0x8005EE00u: goto label_8005EE00;
    case 0x8005EE04u: goto label_8005EE04;
    case 0x8005EE08u: goto label_8005EE08;
    case 0x8005EE0Cu: goto label_8005EE0C;
    case 0x8005EE10u: goto label_8005EE10;
    case 0x8005EE14u: goto label_8005EE14;
    case 0x8005EE18u: goto label_8005EE18;
    case 0x8005EE1Cu: goto label_8005EE1C;
    case 0x8005EE20u: goto label_8005EE20;
    case 0x8005EE24u: goto label_8005EE24;
    case 0x8005EE28u: goto label_8005EE28;
    case 0x8005EE2Cu: goto label_8005EE2C;
    case 0x8005EE30u: goto label_8005EE30;
    case 0x8005EE34u: goto label_8005EE34;
    case 0x8005EE38u: goto label_8005EE38;
    case 0x8005EE3Cu: goto label_8005EE3C;
    case 0x8005EE40u: goto label_8005EE40;
    case 0x8005EE44u: goto label_8005EE44;
    case 0x8005EE48u: goto label_8005EE48;
    case 0x8005EE4Cu: goto label_8005EE4C;
    case 0x8005EE50u: goto label_8005EE50;
    case 0x8005EE54u: goto label_8005EE54;
    case 0x8005EE58u: goto label_8005EE58;
    case 0x8005EE5Cu: goto label_8005EE5C;
    case 0x8005EE60u: goto label_8005EE60;
    case 0x8005EE64u: goto label_8005EE64;
    case 0x8005EE68u: goto label_8005EE68;
    case 0x8005EE6Cu: goto label_8005EE6C;
    case 0x8005EE70u: goto label_8005EE70;
    case 0x8005EE74u: goto label_8005EE74;
    case 0x8005EE78u: goto label_8005EE78;
    case 0x8005EE7Cu: goto label_8005EE7C;
    case 0x8005EE80u: goto label_8005EE80;
    case 0x8005EE84u: goto label_8005EE84;
    case 0x8005EE88u: goto label_8005EE88;
    case 0x8005EE8Cu: goto label_8005EE8C;
    case 0x8005EE90u: goto label_8005EE90;
    case 0x8005EE94u: goto label_8005EE94;
    case 0x8005EE98u: goto label_8005EE98;
    case 0x8005EE9Cu: goto label_8005EE9C;
    case 0x8005EEA0u: goto label_8005EEA0;
    case 0x8005EEA4u: goto label_8005EEA4;
    case 0x8005EEA8u: goto label_8005EEA8;
    case 0x8005EEACu: goto label_8005EEAC;
    case 0x8005EEB0u: goto label_8005EEB0;
    case 0x8005EEB4u: goto label_8005EEB4;
    case 0x8005EEB8u: goto label_8005EEB8;
    case 0x8005EEBCu: goto label_8005EEBC;
    case 0x8005EEC0u: goto label_8005EEC0;
    case 0x8005EEC4u: goto label_8005EEC4;
    case 0x8005EEC8u: goto label_8005EEC8;
    case 0x8005EECCu: goto label_8005EECC;
    case 0x8005EED0u: goto label_8005EED0;
    case 0x8005EED4u: goto label_8005EED4;
    case 0x8005EED8u: goto label_8005EED8;
    case 0x8005EEDCu: goto label_8005EEDC;
    case 0x8005EEE0u: goto label_8005EEE0;
    case 0x8005EEE4u: goto label_8005EEE4;
    case 0x8005EEE8u: goto label_8005EEE8;
    case 0x8005EEECu: goto label_8005EEEC;
    case 0x8005EEF0u: goto label_8005EEF0;
    case 0x8005EEF4u: goto label_8005EEF4;
    case 0x8005EEF8u: goto label_8005EEF8;
    case 0x8005EEFCu: goto label_8005EEFC;
    case 0x8005EF00u: goto label_8005EF00;
    case 0x8005EF04u: goto label_8005EF04;
    case 0x8005EF08u: goto label_8005EF08;
    case 0x8005EF0Cu: goto label_8005EF0C;
    case 0x8005EF10u: goto label_8005EF10;
    case 0x8005EF14u: goto label_8005EF14;
    case 0x8005EF18u: goto label_8005EF18;
    case 0x8005EF1Cu: goto label_8005EF1C;
    case 0x8005EF20u: goto label_8005EF20;
    case 0x8005EF24u: goto label_8005EF24;
    case 0x8005EF28u: goto label_8005EF28;
    case 0x8005EF2Cu: goto label_8005EF2C;
    case 0x8005EF30u: goto label_8005EF30;
    case 0x8005EF34u: goto label_8005EF34;
    case 0x8005EF38u: goto label_8005EF38;
    case 0x8005EF3Cu: goto label_8005EF3C;
    case 0x8005EF40u: goto label_8005EF40;
    case 0x8005EF44u: goto label_8005EF44;
    case 0x8005EF48u: goto label_8005EF48;
    case 0x8005EF4Cu: goto label_8005EF4C;
    case 0x8005EF50u: goto label_8005EF50;
    case 0x8005EF54u: goto label_8005EF54;
    case 0x8005EF58u: goto label_8005EF58;
    case 0x8005EF5Cu: goto label_8005EF5C;
    case 0x8005EF60u: goto label_8005EF60;
    case 0x8005EF64u: goto label_8005EF64;
    case 0x8005EF68u: goto label_8005EF68;
    case 0x8005EF6Cu: goto label_8005EF6C;
    case 0x8005EF70u: goto label_8005EF70;
    case 0x8005EF74u: goto label_8005EF74;
    case 0x8005EF78u: goto label_8005EF78;
    case 0x8005EF7Cu: goto label_8005EF7C;
    case 0x8005EF80u: goto label_8005EF80;
    case 0x8005EF84u: goto label_8005EF84;
    case 0x8005EF88u: goto label_8005EF88;
    case 0x8005EF8Cu: goto label_8005EF8C;
    case 0x8005EF90u: goto label_8005EF90;
    case 0x8005EF94u: goto label_8005EF94;
    case 0x8005EF98u: goto label_8005EF98;
    case 0x8005EF9Cu: goto label_8005EF9C;
    case 0x8005EFA0u: goto label_8005EFA0;
    case 0x8005EFA4u: goto label_8005EFA4;
    case 0x8005EFA8u: goto label_8005EFA8;
    case 0x8005EFACu: goto label_8005EFAC;
    case 0x8005EFB0u: goto label_8005EFB0;
    case 0x8005EFB4u: goto label_8005EFB4;
    case 0x8005EFB8u: goto label_8005EFB8;
    case 0x8005EFBCu: goto label_8005EFBC;
    case 0x8005EFC0u: goto label_8005EFC0;
    case 0x8005EFC4u: goto label_8005EFC4;
    case 0x8005EFC8u: goto label_8005EFC8;
    case 0x8005EFCCu: goto label_8005EFCC;
    case 0x8005EFD0u: goto label_8005EFD0;
    case 0x8005EFD4u: goto label_8005EFD4;
    case 0x8005EFD8u: goto label_8005EFD8;
    case 0x8005EFDCu: goto label_8005EFDC;
    case 0x8005EFE0u: goto label_8005EFE0;
    case 0x8005EFE4u: goto label_8005EFE4;
    case 0x8005EFE8u: goto label_8005EFE8;
    case 0x8005EFECu: goto label_8005EFEC;
    case 0x8005EFF0u: goto label_8005EFF0;
    case 0x8005EFF4u: goto label_8005EFF4;
    case 0x8005EFF8u: goto label_8005EFF8;
    case 0x8005EFFCu: goto label_8005EFFC;
    case 0x8005F000u: goto label_8005F000;
    case 0x8005F004u: goto label_8005F004;
    case 0x8005F008u: goto label_8005F008;
    case 0x8005F00Cu: goto label_8005F00C;
    case 0x8005F010u: goto label_8005F010;
    case 0x8005F014u: goto label_8005F014;
    case 0x8005F018u: goto label_8005F018;
    case 0x8005F01Cu: goto label_8005F01C;
    case 0x8005F020u: goto label_8005F020;
    case 0x8005F024u: goto label_8005F024;
    case 0x8005F028u: goto label_8005F028;
    case 0x8005F02Cu: goto label_8005F02C;
    case 0x8005F030u: goto label_8005F030;
    case 0x8005F034u: goto label_8005F034;
    case 0x8005F038u: goto label_8005F038;
    case 0x8005F03Cu: goto label_8005F03C;
    case 0x8005F040u: goto label_8005F040;
    case 0x8005F044u: goto label_8005F044;
    case 0x8005F048u: goto label_8005F048;
    case 0x8005F04Cu: goto label_8005F04C;
    case 0x8005F050u: goto label_8005F050;
    case 0x8005F054u: goto label_8005F054;
    case 0x8005F058u: goto label_8005F058;
    case 0x8005F05Cu: goto label_8005F05C;
    case 0x8005F060u: goto label_8005F060;
    case 0x8005F064u: goto label_8005F064;
    case 0x8005F068u: goto label_8005F068;
    case 0x8005F06Cu: goto label_8005F06C;
    case 0x8005F070u: goto label_8005F070;
    case 0x8005F074u: goto label_8005F074;
    case 0x8005F078u: goto label_8005F078;
    case 0x8005F07Cu: goto label_8005F07C;
    case 0x8005F080u: goto label_8005F080;
    case 0x8005F084u: goto label_8005F084;
    case 0x8005F088u: goto label_8005F088;
    case 0x8005F08Cu: goto label_8005F08C;
    case 0x8005F090u: goto label_8005F090;
    case 0x8005F094u: goto label_8005F094;
    case 0x8005F098u: goto label_8005F098;
    case 0x8005F09Cu: goto label_8005F09C;
    case 0x8005F0A0u: goto label_8005F0A0;
    case 0x8005F0A4u: goto label_8005F0A4;
    case 0x8005F0A8u: goto label_8005F0A8;
    case 0x8005F0ACu: goto label_8005F0AC;
    case 0x8005F0B0u: goto label_8005F0B0;
    case 0x8005F0B4u: goto label_8005F0B4;
    case 0x8005F0B8u: goto label_8005F0B8;
    case 0x8005F0BCu: goto label_8005F0BC;
    case 0x8005F0C0u: goto label_8005F0C0;
    case 0x8005F0C4u: goto label_8005F0C4;
    case 0x8005F0C8u: goto label_8005F0C8;
    case 0x8005F0CCu: goto label_8005F0CC;
    case 0x8005F0D0u: goto label_8005F0D0;
    case 0x8005F0D4u: goto label_8005F0D4;
    case 0x8005F0D8u: goto label_8005F0D8;
    case 0x8005F0DCu: goto label_8005F0DC;
    case 0x8005F0E0u: goto label_8005F0E0;
    case 0x8005F0E4u: goto label_8005F0E4;
    case 0x8005F0E8u: goto label_8005F0E8;
    case 0x8005F0ECu: goto label_8005F0EC;
    case 0x8005F0F0u: goto label_8005F0F0;
    case 0x8005F0F4u: goto label_8005F0F4;
    case 0x8005F0F8u: goto label_8005F0F8;
    case 0x8005F0FCu: goto label_8005F0FC;
    case 0x8005F100u: goto label_8005F100;
    case 0x8005F104u: goto label_8005F104;
    case 0x8005F108u: goto label_8005F108;
    case 0x8005F10Cu: goto label_8005F10C;
    case 0x8005F110u: goto label_8005F110;
    case 0x8005F114u: goto label_8005F114;
    case 0x8005F118u: goto label_8005F118;
    case 0x8005F11Cu: goto label_8005F11C;
    case 0x8005F120u: goto label_8005F120;
    case 0x8005F124u: goto label_8005F124;
    case 0x8005F128u: goto label_8005F128;
    case 0x8005F12Cu: goto label_8005F12C;
    case 0x8005F130u: goto label_8005F130;
    case 0x8005F134u: goto label_8005F134;
    case 0x8005F138u: goto label_8005F138;
    case 0x8005F13Cu: goto label_8005F13C;
    case 0x8005F140u: goto label_8005F140;
    case 0x8005F144u: goto label_8005F144;
    case 0x8005F148u: goto label_8005F148;
    case 0x8005F14Cu: goto label_8005F14C;
    case 0x8005F150u: goto label_8005F150;
    case 0x8005F154u: goto label_8005F154;
    case 0x8005F158u: goto label_8005F158;
    case 0x8005F15Cu: goto label_8005F15C;
    case 0x8005F160u: goto label_8005F160;
    case 0x8005F164u: goto label_8005F164;
    case 0x8005F168u: goto label_8005F168;
    case 0x8005F16Cu: goto label_8005F16C;
    case 0x8005F170u: goto label_8005F170;
    case 0x8005F174u: goto label_8005F174;
    case 0x8005F178u: goto label_8005F178;
    case 0x8005F17Cu: goto label_8005F17C;
    case 0x8005F180u: goto label_8005F180;
    case 0x8005F184u: goto label_8005F184;
    case 0x8005F188u: goto label_8005F188;
    case 0x8005F18Cu: goto label_8005F18C;
    case 0x8005F190u: goto label_8005F190;
    case 0x8005F194u: goto label_8005F194;
    case 0x8005F198u: goto label_8005F198;
    case 0x8005F19Cu: goto label_8005F19C;
    case 0x8005F1A0u: goto label_8005F1A0;
    case 0x8005F1A4u: goto label_8005F1A4;
    case 0x8005F1A8u: goto label_8005F1A8;
    case 0x8005F1ACu: goto label_8005F1AC;
    case 0x8005F1B0u: goto label_8005F1B0;
    case 0x8005F1B4u: goto label_8005F1B4;
    case 0x8005F1B8u: goto label_8005F1B8;
    case 0x8005F1BCu: goto label_8005F1BC;
    case 0x8005F1C0u: goto label_8005F1C0;
    case 0x8005F1C4u: goto label_8005F1C4;
    case 0x8005F1C8u: goto label_8005F1C8;
    case 0x8005F1CCu: goto label_8005F1CC;
    case 0x8005F1D0u: goto label_8005F1D0;
    case 0x8005F1D4u: goto label_8005F1D4;
    case 0x8005F1D8u: goto label_8005F1D8;
    case 0x8005F1DCu: goto label_8005F1DC;
    case 0x8005F1E0u: goto label_8005F1E0;
    case 0x8005F1E4u: goto label_8005F1E4;
    case 0x8005F1E8u: goto label_8005F1E8;
    case 0x8005F1ECu: goto label_8005F1EC;
    case 0x8005F1F0u: goto label_8005F1F0;
    case 0x8005F1F4u: goto label_8005F1F4;
    case 0x8005F1F8u: goto label_8005F1F8;
    case 0x8005F1FCu: goto label_8005F1FC;
    case 0x8005F200u: goto label_8005F200;
    case 0x8005F204u: goto label_8005F204;
    case 0x8005F208u: goto label_8005F208;
    case 0x8005F20Cu: goto label_8005F20C;
    case 0x8005F210u: goto label_8005F210;
    case 0x8005F214u: goto label_8005F214;
    case 0x8005F218u: goto label_8005F218;
    case 0x8005F21Cu: goto label_8005F21C;
    case 0x8005F220u: goto label_8005F220;
    case 0x8005F224u: goto label_8005F224;
    case 0x8005F228u: goto label_8005F228;
    case 0x8005F22Cu: goto label_8005F22C;
    case 0x8005F230u: goto label_8005F230;
    case 0x8005F234u: goto label_8005F234;
    case 0x8005F238u: goto label_8005F238;
    case 0x8005F23Cu: goto label_8005F23C;
    case 0x8005F240u: goto label_8005F240;
    case 0x8005F244u: goto label_8005F244;
    case 0x8005F248u: goto label_8005F248;
    case 0x8005F24Cu: goto label_8005F24C;
    case 0x8005F250u: goto label_8005F250;
    case 0x8005F254u: goto label_8005F254;
    case 0x8005F258u: goto label_8005F258;
    case 0x8005F25Cu: goto label_8005F25C;
    case 0x8005F260u: goto label_8005F260;
    case 0x8005F264u: goto label_8005F264;
    case 0x8005F268u: goto label_8005F268;
    case 0x8005F26Cu: goto label_8005F26C;
    case 0x8005F270u: goto label_8005F270;
    case 0x8005F274u: goto label_8005F274;
    case 0x8005F278u: goto label_8005F278;
    case 0x8005F27Cu: goto label_8005F27C;
    case 0x8005F280u: goto label_8005F280;
    case 0x8005F284u: goto label_8005F284;
    case 0x8005F288u: goto label_8005F288;
    case 0x8005F28Cu: goto label_8005F28C;
    case 0x8005F290u: goto label_8005F290;
    case 0x8005F294u: goto label_8005F294;
    case 0x8005F298u: goto label_8005F298;
    case 0x8005F29Cu: goto label_8005F29C;
    case 0x8005F2A0u: goto label_8005F2A0;
    case 0x8005F2A4u: goto label_8005F2A4;
    case 0x8005F2A8u: goto label_8005F2A8;
    case 0x8005F2ACu: goto label_8005F2AC;
    case 0x8005F2B0u: goto label_8005F2B0;
    case 0x8005F2B4u: goto label_8005F2B4;
    case 0x8005F2B8u: goto label_8005F2B8;
    case 0x8005F2BCu: goto label_8005F2BC;
    default: return;
    }
label_8005B2C0:
    ctx->pc = 0x8005B2C0u;
    ctx->downcount -= 2;
    // 8005B2C0: lwzx    r10, r28, r9
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[9];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005B2C4:
    ctx->pc = 0x8005B2C4u;
    // 8005B2C4: or   r9, r29, r29
    {
        ctx->gpr[9] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005B2C8:
    ctx->pc = 0x8005B2C8u;
    ctx->downcount -= 4;
    // 8005B2C8: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B2CC:
    // 8005B2CC: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8005B2D0:
    // 8005B2D0: cmpw    r10, r0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B2D4:
    // 8005B2D4: bc    4, 2, 0x8005B2E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B2E0;
        }
    }

label_8005B2D8:
    ctx->downcount -= 2;
    // 8005B2D8: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005B2DC:
    // 8005B2DC: b       0x8005B2F0
    {
            goto label_8005B2F0;
    }

label_8005B2E0:
    ctx->downcount -= 3;
    // 8005B2E0: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_8005B2E4:
    // 8005B2E4: cmpw    r11, r8
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B2E8:
    // 8005B2E8: bc    12, 0, 0x8005B2C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B2C8u;
                return;
            }
            goto label_8005B2C8;
        }
    }

label_8005B2EC:
    ctx->pc = 0x8005B2ECu;
    ctx->downcount -= 1;
    // 8005B2EC: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005B2F0:
    ctx->pc = 0x8005B2F0u;
    ctx->downcount -= 2;
    // 8005B2F0: cmpwi   r0, -1
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

label_8005B2F4:
    ctx->pc = 0x8005B2F4u;
    // 8005B2F4: bc    4, 2, 0x8005B300
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B300;
        }
    }

label_8005B2F8:
    ctx->pc = 0x8005B2F8u;
    ctx->downcount -= 2;
    // 8005B2F8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005B2FC:
    ctx->pc = 0x8005B2FCu;
    // 8005B2FC: bl      0x8003F1B8
    {
            ctx->lr = 0x8005B300u;
            ctx->pc = 0x8003F1B8u;
            return;
    }

label_8005B300:
    ctx->pc = 0x8005B300u;
    ctx->downcount -= 4;
    // 8005B300: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B304:
    ctx->pc = 0x8005B304u;
    // 8005B304: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005B308:
    ctx->pc = 0x8005B308u;
    // 8005B308: cmpw    r4, r0
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B30C:
    ctx->pc = 0x8005B30Cu;
    // 8005B30C: bc    12, 0, 0x8005B2A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8005B2A8u;
            return;
        }
    }

label_8005B310:
    ctx->pc = 0x8005B310u;
    ctx->downcount -= 5;
    // 8005B310: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005B314:
    ctx->pc = 0x8005B314u;
    // 8005B314: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005B318:
    ctx->pc = 0x8005B318u;
    // 8005B318: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B31C:
    ctx->pc = 0x8005B31Cu;
    // 8005B31C: or   r7, r9, r9
    {
        ctx->gpr[7] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005B320:
    ctx->pc = 0x8005B320u;
    // 8005B320: bc    4, 0, 0x8005B3D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B3D8;
        }
    }

label_8005B324:
    ctx->downcount -= 5;
    // 8005B324: rlwinm r0, r11, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_8005B328:
    // 8005B328: addi    r31, r11, 1
    ctx->gpr[31] = ctx->gpr[11] + (u32)(s32)(1);

label_8005B32C:
    ctx->pc = 0x8005B32Cu;
    // 8005B32C: lwzx    r8, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005B330:
    // 8005B330: cmpwi   r8, 0
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

label_8005B334:
    // 8005B334: bc    12, 2, 0x8005B3C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005B3C4;
        }
    }

label_8005B338:
    ctx->downcount -= 3;
    // 8005B338: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005B33C:
    // 8005B33C: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B340:
    // 8005B340: bc    4, 0, 0x8005B370
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B370;
        }
    }

label_8005B344:
    ctx->downcount -= 2;
    // 8005B344: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8005B348:
    // 8005B348: addi    r9, r30, 52
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(52);

label_8005B34C:
    ctx->pc = 0x8005B34Cu;
    ctx->downcount -= 4;
    // 8005B34C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B350:
    // 8005B350: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8005B354:
    // 8005B354: cmpw    r0, r8
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B358:
    // 8005B358: bc    4, 2, 0x8005B364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B364;
        }
    }

label_8005B35C:
    ctx->downcount -= 2;
    // 8005B35C: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005B360:
    // 8005B360: b       0x8005B374
    {
            goto label_8005B374;
    }

label_8005B364:
    ctx->downcount -= 3;
    // 8005B364: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_8005B368:
    // 8005B368: cmpw    r11, r10
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

label_8005B36C:
    // 8005B36C: bc    12, 0, 0x8005B34C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B34Cu;
                return;
            }
            goto label_8005B34C;
        }
    }

label_8005B370:
    ctx->downcount -= 1;
    // 8005B370: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005B374:
    ctx->downcount -= 2;
    // 8005B374: cmpwi   r0, -1
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

label_8005B378:
    // 8005B378: bc    4, 2, 0x8005B3C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B3C4;
        }
    }

label_8005B37C:
    ctx->downcount -= 3;
    // 8005B37C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8005B380:
    // 8005B380: cmpw    r10, r7
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B384:
    // 8005B384: bc    4, 0, 0x8005B3C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B3C4;
        }
    }

label_8005B388:
    ctx->downcount -= 2;
    // 8005B388: addi    r11, r8, 16
    ctx->gpr[11] = ctx->gpr[8] + (u32)(s32)(16);

label_8005B38C:
    // 8005B38C: addi    r9, r30, 52
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(52);

label_8005B390:
    ctx->pc = 0x8005B390u;
    ctx->downcount -= 3;
    // 8005B390: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B394:
    // 8005B394: cmpwi   r0, 0
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

label_8005B398:
    // 8005B398: bc    4, 2, 0x8005B3B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B3B4;
        }
    }

label_8005B39C:
    ctx->pc = 0x8005B39Cu;
    ctx->downcount -= 5;
    // 8005B39C: lwz     r0, -40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B3A0:
    // 8005B3A0: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005B3A4:
    ctx->pc = 0x8005B3A4u;
    // 8005B3A4: stw     r0, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B3A8:
    ctx->pc = 0x8005B3A8u;
    // 8005B3A8: stw     r8, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005B3AC:
    // 8005B3AC: bl      0x80030AE0
    {
            ctx->lr = 0x8005B3B0u;
            ctx->pc = 0x80030AE0u;
            return;
    }

label_8005B3B0:
    ctx->downcount -= 1;
    // 8005B3B0: b       0x8005B3C4
    {
            goto label_8005B3C4;
    }

label_8005B3B4:
    ctx->downcount -= 4;
    // 8005B3B4: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_8005B3B8:
    // 8005B3B8: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8005B3BC:
    // 8005B3BC: cmpw    r10, r7
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B3C0:
    // 8005B3C0: bc    12, 0, 0x8005B390
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B390u;
                return;
            }
            goto label_8005B390;
        }
    }

label_8005B3C4:
    ctx->pc = 0x8005B3C4u;
    ctx->downcount -= 5;
    // 8005B3C4: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005B3C8:
    // 8005B3C8: or   r11, r31, r31
    {
        ctx->gpr[11] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005B3CC:
    // 8005B3CC: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B3D0:
    // 8005B3D0: or   r7, r9, r9
    {
        ctx->gpr[7] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005B3D4:
    // 8005B3D4: bc    12, 0, 0x8005B324
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B324u;
                return;
            }
            goto label_8005B324;
        }
    }

label_8005B3D8:
    ctx->pc = 0x8005B3D8u;
    ctx->downcount -= 19;
    // 8005B3D8: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005B3DC:
    ctx->pc = 0x8005B3DCu;
    // 8005B3DC: addi    r9, r9, -27600
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-27600);

label_8005B3E0:
    ctx->pc = 0x8005B3E0u;
    // 8005B3E0: stw     r9, -31248(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31248);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005B3E4:
    ctx->pc = 0x8005B3E4u;
    // 8005B3E4: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B3E8:
    ctx->pc = 0x8005B3E8u;
    // 8005B3E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B3EC:
    ctx->pc = 0x8005B3ECu;
    // 8005B3EC: lmw     r28, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005B3F0:
    ctx->pc = 0x8005B3F0u;
    // 8005B3F0: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_8005B3F4:
    ctx->pc = 0x8005B3F4u;
    // 8005B3F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B3F8:
    ctx->pc = 0x8005B3F8u;
    ctx->downcount -= 50;
    // 8005B3F8: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B3FC:
    ctx->pc = 0x8005B3FCu;
    // 8005B3FC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B400:
    ctx->pc = 0x8005B400u;
    // 8005B400: stmw     r28, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005B404:
    ctx->pc = 0x8005B404u;
    // 8005B404: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B408:
    ctx->pc = 0x8005B408u;
    // 8005B408: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B40C:
    ctx->pc = 0x8005B40Cu;
    // 8005B40C: mulli   r3, r3, 56
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)56);

label_8005B410:
    ctx->pc = 0x8005B410u;
    // 8005B410: lwz     r10, 11828(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(11828);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005B414:
    ctx->pc = 0x8005B414u;
    // 8005B414: lis     r8, -32735
    ctx->gpr[8] = ((u32)(s32)(-32735) << 16);

label_8005B418:
    ctx->pc = 0x8005B418u;
    // 8005B418: addi    r8, r8, -27600
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(-27600);

label_8005B41C:
    ctx->pc = 0x8005B41Cu;
    // 8005B41C: lis     r11, -32734
    ctx->gpr[11] = ((u32)(s32)(-32734) << 16);

label_8005B420:
    ctx->pc = 0x8005B420u;
    // 8005B420: mulli   r10, r10, 20
    ctx->gpr[10] = (u32)((s64)(s32)ctx->gpr[10] * (s64)(s32)20);

label_8005B424:
    ctx->pc = 0x8005B424u;
    // 8005B424: addi    r6, r8, -25984
    ctx->gpr[6] = ctx->gpr[8] + (u32)(s32)(-25984);

label_8005B428:
    ctx->pc = 0x8005B428u;
    // 8005B428: add   r3, r3, r6
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8005B42C:
    ctx->pc = 0x8005B42Cu;
    // 8005B42C: stw     r8, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005B430:
    ctx->pc = 0x8005B430u;
    // 8005B430: stw     r3, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005B434:
    ctx->pc = 0x8005B434u;
    // 8005B434: addi    r11, r11, 2380
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(2380);

label_8005B438:
    ctx->pc = 0x8005B438u;
    // 8005B438: addi    r11, r11, 16
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(16);

label_8005B43C:
    ctx->pc = 0x8005B43Cu;
    // 8005B43C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B440:
    ctx->pc = 0x8005B440u;
    // 8005B440: lwzx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B444:
    ctx->pc = 0x8005B444u;
    // 8005B444: addi    r31, r9, 11848
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(11848);

label_8005B448:
    ctx->pc = 0x8005B448u;
    // 8005B448: lwz     r10, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005B44C:
    ctx->pc = 0x8005B44Cu;
    // 8005B44C: addi    r7, r1, 24
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(24);

label_8005B450:
    ctx->pc = 0x8005B450u;
    // 8005B450: mulli   r0, r0, 56
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)56);

label_8005B454:
    ctx->pc = 0x8005B454u;
    // 8005B454: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B458:
    ctx->pc = 0x8005B458u;
    // 8005B458: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005B45C:
    ctx->pc = 0x8005B45Cu;
    // 8005B45C: cmpw    r4, r10
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B460:
    ctx->pc = 0x8005B460u;
    // 8005B460: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8005B464:
    ctx->pc = 0x8005B464u;
    // 8005B464: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B468:
    ctx->pc = 0x8005B468u;
    // 8005B468: lwz     r9, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005B46C:
    ctx->pc = 0x8005B46Cu;
    // 8005B46C: lwz     r0, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B470:
    ctx->pc = 0x8005B470u;
    // 8005B470: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005B474:
    ctx->pc = 0x8005B474u;
    // 8005B474: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B478:
    ctx->pc = 0x8005B478u;
    // 8005B478: stw     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005B47C:
    ctx->pc = 0x8005B47Cu;
    // 8005B47C: bc    4, 0, 0x8005B4EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B4EC;
        }
    }

label_8005B480:
    ctx->pc = 0x8005B480u;
    ctx->downcount -= 1;
    // 8005B480: addi    r28, r31, 52
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(52);

label_8005B484:
    ctx->downcount -= 4;
    // 8005B484: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005B488:
    // 8005B488: addi    r30, r4, 1
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(1);

label_8005B48C:
    // 8005B48C: cmpw    r11, r10
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

label_8005B490:
    // 8005B490: bc    4, 0, 0x8005B4C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B4C8;
        }
    }

label_8005B494:
    ctx->downcount -= 4;
    // 8005B494: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_8005B498:
    ctx->pc = 0x8005B498u;
    // 8005B498: lwz     r8, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005B49C:
    ctx->pc = 0x8005B49Cu;
    // 8005B49C: lwzx    r10, r28, r0
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[0];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005B4A0:
    // 8005B4A0: or   r9, r29, r29
    {
        ctx->gpr[9] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005B4A4:
    ctx->pc = 0x8005B4A4u;
    ctx->downcount -= 4;
    // 8005B4A4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B4A8:
    // 8005B4A8: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8005B4AC:
    // 8005B4AC: cmpw    r10, r0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B4B0:
    // 8005B4B0: bc    4, 2, 0x8005B4BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B4BC;
        }
    }

label_8005B4B4:
    ctx->downcount -= 2;
    // 8005B4B4: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005B4B8:
    // 8005B4B8: b       0x8005B4CC
    {
            goto label_8005B4CC;
    }

label_8005B4BC:
    ctx->downcount -= 3;
    // 8005B4BC: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_8005B4C0:
    // 8005B4C0: cmpw    r11, r8
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B4C4:
    // 8005B4C4: bc    12, 0, 0x8005B4A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B4A4u;
                return;
            }
            goto label_8005B4A4;
        }
    }

label_8005B4C8:
    ctx->downcount -= 1;
    // 8005B4C8: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005B4CC:
    ctx->downcount -= 2;
    // 8005B4CC: cmpwi   r0, -1
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

label_8005B4D0:
    // 8005B4D0: bc    4, 2, 0x8005B4DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B4DC;
        }
    }

label_8005B4D4:
    ctx->downcount -= 2;
    // 8005B4D4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005B4D8:
    // 8005B4D8: bl      0x8003F1B8
    {
            ctx->lr = 0x8005B4DCu;
            ctx->pc = 0x8003F1B8u;
            return;
    }

label_8005B4DC:
    ctx->pc = 0x8005B4DCu;
    ctx->downcount -= 4;
    // 8005B4DC: lwz     r10, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005B4E0:
    // 8005B4E0: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005B4E4:
    // 8005B4E4: cmpw    r4, r10
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(ctx->gpr[10]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B4E8:
    // 8005B4E8: bc    12, 0, 0x8005B484
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B484u;
                return;
            }
            goto label_8005B484;
        }
    }

label_8005B4EC:
    ctx->pc = 0x8005B4ECu;
    ctx->downcount -= 5;
    // 8005B4EC: lwz     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005B4F0:
    ctx->pc = 0x8005B4F0u;
    // 8005B4F0: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005B4F4:
    ctx->pc = 0x8005B4F4u;
    // 8005B4F4: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B4F8:
    ctx->pc = 0x8005B4F8u;
    // 8005B4F8: or   r7, r9, r9
    {
        ctx->gpr[7] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005B4FC:
    ctx->pc = 0x8005B4FCu;
    // 8005B4FC: bc    4, 0, 0x8005B5B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B5B4;
        }
    }

label_8005B500:
    ctx->downcount -= 5;
    // 8005B500: rlwinm r0, r11, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_8005B504:
    // 8005B504: addi    r30, r11, 1
    ctx->gpr[30] = ctx->gpr[11] + (u32)(s32)(1);

label_8005B508:
    ctx->pc = 0x8005B508u;
    // 8005B508: lwzx    r8, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005B50C:
    // 8005B50C: cmpwi   r8, 0
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

label_8005B510:
    // 8005B510: bc    12, 2, 0x8005B5A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005B5A0;
        }
    }

label_8005B514:
    ctx->downcount -= 3;
    // 8005B514: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005B518:
    // 8005B518: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B51C:
    // 8005B51C: bc    4, 0, 0x8005B54C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B54C;
        }
    }

label_8005B520:
    ctx->downcount -= 2;
    // 8005B520: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_8005B524:
    // 8005B524: addi    r9, r31, 52
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(52);

label_8005B528:
    ctx->pc = 0x8005B528u;
    ctx->downcount -= 4;
    // 8005B528: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B52C:
    // 8005B52C: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8005B530:
    // 8005B530: cmpw    r0, r8
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[8]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B534:
    // 8005B534: bc    4, 2, 0x8005B540
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B540;
        }
    }

label_8005B538:
    ctx->downcount -= 2;
    // 8005B538: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005B53C:
    // 8005B53C: b       0x8005B550
    {
            goto label_8005B550;
    }

label_8005B540:
    ctx->downcount -= 3;
    // 8005B540: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_8005B544:
    // 8005B544: cmpw    r11, r10
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

label_8005B548:
    // 8005B548: bc    12, 0, 0x8005B528
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B528u;
                return;
            }
            goto label_8005B528;
        }
    }

label_8005B54C:
    ctx->downcount -= 1;
    // 8005B54C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005B550:
    ctx->downcount -= 2;
    // 8005B550: cmpwi   r0, -1
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

label_8005B554:
    // 8005B554: bc    4, 2, 0x8005B5A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B5A0;
        }
    }

label_8005B558:
    ctx->downcount -= 3;
    // 8005B558: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8005B55C:
    // 8005B55C: cmpw    r10, r7
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B560:
    // 8005B560: bc    4, 0, 0x8005B5A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B5A0;
        }
    }

label_8005B564:
    ctx->downcount -= 2;
    // 8005B564: addi    r11, r8, 16
    ctx->gpr[11] = ctx->gpr[8] + (u32)(s32)(16);

label_8005B568:
    // 8005B568: addi    r9, r31, 52
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(52);

label_8005B56C:
    ctx->pc = 0x8005B56Cu;
    ctx->downcount -= 3;
    // 8005B56C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B570:
    // 8005B570: cmpwi   r0, 0
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

label_8005B574:
    // 8005B574: bc    4, 2, 0x8005B590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B590;
        }
    }

label_8005B578:
    ctx->pc = 0x8005B578u;
    ctx->downcount -= 5;
    // 8005B578: lwz     r0, -40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B57C:
    // 8005B57C: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005B580:
    ctx->pc = 0x8005B580u;
    // 8005B580: stw     r0, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B584:
    ctx->pc = 0x8005B584u;
    // 8005B584: stw     r8, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005B588:
    // 8005B588: bl      0x80030AE0
    {
            ctx->lr = 0x8005B58Cu;
            ctx->pc = 0x80030AE0u;
            return;
    }

label_8005B58C:
    ctx->downcount -= 1;
    // 8005B58C: b       0x8005B5A0
    {
            goto label_8005B5A0;
    }

label_8005B590:
    ctx->downcount -= 4;
    // 8005B590: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_8005B594:
    // 8005B594: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_8005B598:
    // 8005B598: cmpw    r10, r7
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B59C:
    // 8005B59C: bc    12, 0, 0x8005B56C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B56Cu;
                return;
            }
            goto label_8005B56C;
        }
    }

label_8005B5A0:
    ctx->pc = 0x8005B5A0u;
    ctx->downcount -= 5;
    // 8005B5A0: lwz     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005B5A4:
    // 8005B5A4: or   r11, r30, r30
    {
        ctx->gpr[11] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005B5A8:
    // 8005B5A8: cmpw    r11, r9
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005B5AC:
    // 8005B5AC: or   r7, r9, r9
    {
        ctx->gpr[7] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005B5B0:
    // 8005B5B0: bc    12, 0, 0x8005B500
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B500u;
                return;
            }
            goto label_8005B500;
        }
    }

label_8005B5B4:
    ctx->pc = 0x8005B5B4u;
    ctx->downcount -= 16;
    // 8005B5B4: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B5B8:
    ctx->pc = 0x8005B5B8u;
    // 8005B5B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B5BC:
    ctx->pc = 0x8005B5BCu;
    // 8005B5BC: lmw     r28, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005B5C0:
    ctx->pc = 0x8005B5C0u;
    // 8005B5C0: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_8005B5C4:
    ctx->pc = 0x8005B5C4u;
    // 8005B5C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B5C8:
    ctx->pc = 0x8005B5C8u;
    ctx->downcount -= 14;
    // 8005B5C8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B5CC:
    ctx->pc = 0x8005B5CCu;
    // 8005B5CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B5D0:
    ctx->pc = 0x8005B5D0u;
    // 8005B5D0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B5D4:
    ctx->pc = 0x8005B5D4u;
    // 8005B5D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005B5D8:
    ctx->pc = 0x8005B5D8u;
    // 8005B5D8: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B5DC:
    ctx->pc = 0x8005B5DCu;
    // 8005B5DC: stw     r0, 11848(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(11848);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B5E0:
    ctx->pc = 0x8005B5E0u;
    // 8005B5E0: addi    r3, r9, 11848
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(11848);

label_8005B5E4:
    ctx->pc = 0x8005B5E4u;
    // 8005B5E4: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B5E8:
    ctx->pc = 0x8005B5E8u;
    // 8005B5E8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005B5EC:
    ctx->pc = 0x8005B5ECu;
    // 8005B5EC: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B5F0:
    ctx->pc = 0x8005B5F0u;
    // 8005B5F0: addi    r9, r3, 88
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(88);

label_8005B5F4:
    ctx->pc = 0x8005B5F4u;
    // 8005B5F4: li      r0, 10
    ctx->gpr[0] = (u32)(s32)(10);

label_8005B5F8:
    ctx->pc = 0x8005B5F8u;
    // 8005B5F8: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8005B5FC:
    loop_8005B5FC(ctx);
    if (ctx->pc == 0x8005B608u) goto label_8005B608;
    return;
label_8005B600:
    // 8005B600: addi    r9, r9, -4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-4);

label_8005B604:
    // 8005B604: bc    16, 0, 0x8005B5FC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B5FCu;
                return;
            }
            goto label_8005B5FC;
        }
    }

label_8005B608:
    ctx->pc = 0x8005B608u;
    ctx->downcount -= 4;
    // 8005B608: lwz     r5, -27928(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27928);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005B60C:
    ctx->pc = 0x8005B60Cu;
    // 8005B60C: lis     r4, 13
    ctx->gpr[4] = ((u32)(s32)(13) << 16);

label_8005B610:
    ctx->pc = 0x8005B610u;
    // 8005B610: ori     r4, r4, 0x5C80
    ctx->gpr[4] = ctx->gpr[4] | 0x5C80u;

label_8005B614:
    ctx->pc = 0x8005B614u;
    // 8005B614: bl      0x80039A70
    {
            ctx->lr = 0x8005B618u;
            ctx->pc = 0x80039A70u;
            return;
    }

label_8005B618:
    ctx->pc = 0x8005B618u;
    ctx->downcount -= 1;
    // 8005B618: bl      0x80030780
    {
            ctx->lr = 0x8005B61Cu;
            ctx->pc = 0x80030780u;
            return;
    }

label_8005B61C:
    ctx->pc = 0x8005B61Cu;
    ctx->downcount -= 5;
    // 8005B61C: lis     r4, -32699
    ctx->gpr[4] = ((u32)(s32)(-32699) << 16);

label_8005B620:
    ctx->pc = 0x8005B620u;
    // 8005B620: li      r3, 8376
    ctx->gpr[3] = (u32)(s32)(8376);

label_8005B624:
    ctx->pc = 0x8005B624u;
    // 8005B624: addi    r4, r4, -13308
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-13308);

label_8005B628:
    ctx->pc = 0x8005B628u;
    // 8005B628: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8005B62C:
    ctx->pc = 0x8005B62Cu;
    // 8005B62C: bl      0x8003F200
    {
            ctx->lr = 0x8005B630u;
            ctx->pc = 0x8003F200u;
            return;
    }

label_8005B630:
    ctx->pc = 0x8005B630u;
    ctx->downcount -= 1;
    // 8005B630: bl      0x8005AA1C
    {
            ctx->lr = 0x8005B634u;
            ctx->pc = 0x8005AA1Cu;
            return;
    }

label_8005B634:
    ctx->pc = 0x8005B634u;
    ctx->downcount -= 1;
    // 8005B634: bl      0x8005AADC
    {
            ctx->lr = 0x8005B638u;
            ctx->pc = 0x8005AADCu;
            return;
    }

label_8005B638:
    ctx->pc = 0x8005B638u;
    ctx->downcount -= 1;
    // 8005B638: bl      0x800C7110
    {
            ctx->lr = 0x8005B63Cu;
            ctx->pc = 0x800C7110u;
            return;
    }

label_8005B63C:
    ctx->pc = 0x8005B63Cu;
    ctx->downcount -= 1;
    // 8005B63C: bl      0x80094A64
    {
            ctx->lr = 0x8005B640u;
            ctx->pc = 0x80094A64u;
            return;
    }

label_8005B640:
    ctx->pc = 0x8005B640u;
    ctx->downcount -= 1;
    // 8005B640: bl      0x800B7214
    {
            ctx->lr = 0x8005B644u;
            ctx->pc = 0x800B7214u;
            return;
    }

label_8005B644:
    ctx->pc = 0x8005B644u;
    ctx->downcount -= 1;
    // 8005B644: bl      0x800C2F1C
    {
            ctx->lr = 0x8005B648u;
            ctx->pc = 0x800C2F1Cu;
            return;
    }

label_8005B648:
    ctx->pc = 0x8005B648u;
    ctx->downcount -= 1;
    // 8005B648: bl      0x80066714
    {
            ctx->lr = 0x8005B64Cu;
            ctx->pc = 0x80066714u;
            return;
    }

label_8005B64C:
    ctx->pc = 0x8005B64Cu;
    ctx->downcount -= 1;
    // 8005B64C: bl      0x8001DBFC
    {
            ctx->lr = 0x8005B650u;
            ctx->pc = 0x8001DBFCu;
            return;
    }

label_8005B650:
    ctx->pc = 0x8005B650u;
    ctx->downcount -= 1;
    // 8005B650: bl      0x80095290
    {
            ctx->lr = 0x8005B654u;
            ctx->pc = 0x80095290u;
            return;
    }

label_8005B654:
    ctx->pc = 0x8005B654u;
    ctx->downcount -= 4;
    // 8005B654: lis     r3, -32699
    ctx->gpr[3] = ((u32)(s32)(-32699) << 16);

label_8005B658:
    ctx->pc = 0x8005B658u;
    // 8005B658: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005B65C:
    ctx->pc = 0x8005B65Cu;
    // 8005B65C: addi    r3, r3, 16240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16240);

label_8005B660:
    ctx->pc = 0x8005B660u;
    // 8005B660: bl      0x80044028
    {
            ctx->lr = 0x8005B664u;
            ctx->pc = 0x80044028u;
            return;
    }

label_8005B664:
    ctx->pc = 0x8005B664u;
    ctx->downcount -= 5;
    // 8005B664: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B668:
    ctx->pc = 0x8005B668u;
    // 8005B668: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B66C:
    ctx->pc = 0x8005B66Cu;
    // 8005B66C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B670:
    ctx->pc = 0x8005B670u;
    // 8005B670: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B674:
    ctx->pc = 0x8005B674u;
    ctx->downcount -= 7;
    // 8005B674: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B678:
    ctx->pc = 0x8005B678u;
    // 8005B678: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B67C:
    ctx->pc = 0x8005B67Cu;
    // 8005B67C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B680:
    ctx->pc = 0x8005B680u;
    // 8005B680: lis     r3, -32699
    ctx->gpr[3] = ((u32)(s32)(-32699) << 16);

label_8005B684:
    ctx->pc = 0x8005B684u;
    // 8005B684: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005B688:
    ctx->pc = 0x8005B688u;
    // 8005B688: addi    r3, r3, 16240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16240);

label_8005B68C:
    ctx->pc = 0x8005B68Cu;
    // 8005B68C: bl      0x80044028
    {
            ctx->lr = 0x8005B690u;
            ctx->pc = 0x80044028u;
            return;
    }

label_8005B690:
    ctx->pc = 0x8005B690u;
    ctx->downcount -= 1;
    // 8005B690: bl      0x80066678
    {
            ctx->lr = 0x8005B694u;
            ctx->pc = 0x80066678u;
            return;
    }

label_8005B694:
    ctx->pc = 0x8005B694u;
    ctx->downcount -= 5;
    // 8005B694: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B698:
    ctx->pc = 0x8005B698u;
    // 8005B698: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B69C:
    ctx->pc = 0x8005B69Cu;
    // 8005B69C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B6A0:
    ctx->pc = 0x8005B6A0u;
    // 8005B6A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B6A4:
    ctx->pc = 0x8005B6A4u;
    ctx->downcount -= 7;
    // 8005B6A4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B6A8:
    ctx->pc = 0x8005B6A8u;
    // 8005B6A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B6AC:
    ctx->pc = 0x8005B6ACu;
    // 8005B6AC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B6B0:
    ctx->pc = 0x8005B6B0u;
    // 8005B6B0: lis     r3, -32699
    ctx->gpr[3] = ((u32)(s32)(-32699) << 16);

label_8005B6B4:
    ctx->pc = 0x8005B6B4u;
    // 8005B6B4: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8005B6B8:
    ctx->pc = 0x8005B6B8u;
    // 8005B6B8: addi    r3, r3, 16240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16240);

label_8005B6BC:
    ctx->pc = 0x8005B6BCu;
    // 8005B6BC: bl      0x80044028
    {
            ctx->lr = 0x8005B6C0u;
            ctx->pc = 0x80044028u;
            return;
    }

label_8005B6C0:
    ctx->pc = 0x8005B6C0u;
    ctx->downcount -= 5;
    // 8005B6C0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B6C4:
    ctx->pc = 0x8005B6C4u;
    // 8005B6C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B6C8:
    ctx->pc = 0x8005B6C8u;
    // 8005B6C8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B6CC:
    ctx->pc = 0x8005B6CCu;
    // 8005B6CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B6D0:
    ctx->pc = 0x8005B6D0u;
    ctx->downcount -= 7;
    // 8005B6D0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B6D4:
    ctx->pc = 0x8005B6D4u;
    // 8005B6D4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B6D8:
    ctx->pc = 0x8005B6D8u;
    // 8005B6D8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B6DC:
    ctx->pc = 0x8005B6DCu;
    // 8005B6DC: lis     r3, -32699
    ctx->gpr[3] = ((u32)(s32)(-32699) << 16);

label_8005B6E0:
    ctx->pc = 0x8005B6E0u;
    // 8005B6E0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8005B6E4:
    ctx->pc = 0x8005B6E4u;
    // 8005B6E4: addi    r3, r3, 16240
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16240);

label_8005B6E8:
    ctx->pc = 0x8005B6E8u;
    // 8005B6E8: bl      0x80044028
    {
            ctx->lr = 0x8005B6ECu;
            ctx->pc = 0x80044028u;
            return;
    }

label_8005B6EC:
    ctx->pc = 0x8005B6ECu;
    ctx->downcount -= 5;
    // 8005B6EC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B6F0:
    ctx->pc = 0x8005B6F0u;
    // 8005B6F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B6F4:
    ctx->pc = 0x8005B6F4u;
    // 8005B6F4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B6F8:
    ctx->pc = 0x8005B6F8u;
    // 8005B6F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B6FC:
    ctx->pc = 0x8005B6FCu;
    ctx->downcount -= 16;
    // 8005B6FC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B700:
    ctx->pc = 0x8005B700u;
    // 8005B700: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B704:
    ctx->pc = 0x8005B704u;
    // 8005B704: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005B708:
    ctx->pc = 0x8005B708u;
    // 8005B708: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B70C:
    ctx->pc = 0x8005B70Cu;
    // 8005B70C: cmpwi   r3, 0
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

label_8005B710:
    ctx->pc = 0x8005B710u;
    // 8005B710: bc    4, 2, 0x8005B718
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B718;
        }
    }

label_8005B714:
    ctx->pc = 0x8005B714u;
    ctx->downcount -= 1;
    // 8005B714: bl      0x8005AADC
    {
            ctx->lr = 0x8005B718u;
            ctx->pc = 0x8005AADCu;
            return;
    }

label_8005B718:
    ctx->pc = 0x8005B718u;
    ctx->downcount -= 4;
    // 8005B718: lis     r30, -32699
    ctx->gpr[30] = ((u32)(s32)(-32699) << 16);

label_8005B71C:
    ctx->pc = 0x8005B71Cu;
    // 8005B71C: addi    r30, r30, -21636
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-21636);

label_8005B720:
    ctx->pc = 0x8005B720u;
    // 8005B720: lwz     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005B724:
    ctx->pc = 0x8005B724u;
    // 8005B724: bl      0x8005B85C
    {
            ctx->lr = 0x8005B728u;
            goto label_8005B85C;
    }

label_8005B728:
    ctx->pc = 0x8005B728u;
    ctx->downcount -= 1;
    // 8005B728: bl      0x8005B998
    {
            ctx->lr = 0x8005B72Cu;
            goto label_8005B998;
    }

label_8005B72C:
    ctx->pc = 0x8005B72Cu;
    ctx->downcount -= 3;
    // 8005B72C: li      r4, 51
    ctx->gpr[4] = (u32)(s32)(51);

label_8005B730:
    ctx->pc = 0x8005B730u;
    // 8005B730: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005B734:
    ctx->pc = 0x8005B734u;
    // 8005B734: bl      0x8005B1D8
    {
            ctx->lr = 0x8005B738u;
            ctx->pc = 0x8005B1D8u;
            return;
    }

label_8005B738:
    ctx->pc = 0x8005B738u;
    ctx->downcount -= 13;
    // 8005B738: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005B73C:
    ctx->pc = 0x8005B73Cu;
    // 8005B73C: li      r11, 192
    ctx->gpr[11] = (u32)(s32)(192);

label_8005B740:
    ctx->pc = 0x8005B740u;
    // 8005B740: li      r10, -1
    ctx->gpr[10] = (u32)(s32)(-1);

label_8005B744:
    ctx->pc = 0x8005B744u;
    // 8005B744: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8005B748:
    ctx->pc = 0x8005B748u;
    // 8005B748: sth     r0, 960(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(960);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005B74C:
    ctx->pc = 0x8005B74Cu;
    // 8005B74C: sth     r11, 910(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(910);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_8005B750:
    ctx->pc = 0x8005B750u;
    // 8005B750: stw     r9, 936(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(936);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005B754:
    ctx->pc = 0x8005B754u;
    // 8005B754: sth     r10, 926(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(926);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_8005B758:
    ctx->pc = 0x8005B758u;
    // 8005B758: stw     r0, 916(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(916);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B75C:
    ctx->pc = 0x8005B75Cu;
    // 8005B75C: sth     r11, 908(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(908);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_8005B760:
    ctx->pc = 0x8005B760u;
    // 8005B760: sth     r0, 920(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(920);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005B764:
    ctx->pc = 0x8005B764u;
    // 8005B764: sth     r10, 922(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(922);
        mem_write16(ctx, ea, (u16)ctx->gpr[10]);
    }

label_8005B768:
    ctx->pc = 0x8005B768u;
    // 8005B768: bl      0x8012CDF4
    {
            ctx->lr = 0x8005B76Cu;
            ctx->pc = 0x8012CDF4u;
            return;
    }

label_8005B76C:
    ctx->pc = 0x8005B76Cu;
    ctx->downcount -= 1;
    // 8005B76C: bl      0x800E9070
    {
            ctx->lr = 0x8005B770u;
            ctx->pc = 0x800E9070u;
            return;
    }

label_8005B770:
    ctx->pc = 0x8005B770u;
    ctx->downcount -= 16;
    // 8005B770: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B774:
    ctx->pc = 0x8005B774u;
    // 8005B774: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B778:
    ctx->pc = 0x8005B778u;
    // 8005B778: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005B77C:
    ctx->pc = 0x8005B77Cu;
    // 8005B77C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005B780:
    ctx->pc = 0x8005B780u;
    // 8005B780: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B784:
    ctx->pc = 0x8005B784u;
    ctx->downcount -= 3;
    // 8005B784: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B788:
    ctx->pc = 0x8005B788u;
    // 8005B788: sth     r3, -21600(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21600);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8005B78C:
    ctx->pc = 0x8005B78Cu;
    // 8005B78C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B790:
    ctx->pc = 0x8005B790u;
    ctx->downcount -= 3;
    // 8005B790: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B794:
    ctx->pc = 0x8005B794u;
    // 8005B794: sth     r3, -21598(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21598);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_8005B798:
    ctx->pc = 0x8005B798u;
    // 8005B798: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B79C:
    ctx->pc = 0x8005B79Cu;
    ctx->downcount -= 4;
    // 8005B79C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B7A0:
    ctx->pc = 0x8005B7A0u;
    // 8005B7A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B7A4:
    ctx->pc = 0x8005B7A4u;
    // 8005B7A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B7A8:
    ctx->pc = 0x8005B7A8u;
    // 8005B7A8: bl      0x8005B784
    {
            ctx->lr = 0x8005B7ACu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B784u;
                return;
            }
            goto label_8005B784;
    }

label_8005B7AC:
    ctx->pc = 0x8005B7ACu;
    ctx->downcount -= 5;
    // 8005B7AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B7B0:
    ctx->pc = 0x8005B7B0u;
    // 8005B7B0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B7B4:
    ctx->pc = 0x8005B7B4u;
    // 8005B7B4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B7B8:
    ctx->pc = 0x8005B7B8u;
    // 8005B7B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B7BC:
    ctx->pc = 0x8005B7BCu;
    ctx->downcount -= 5;
    // 8005B7BC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B7C0:
    ctx->pc = 0x8005B7C0u;
    // 8005B7C0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B7C4:
    ctx->pc = 0x8005B7C4u;
    // 8005B7C4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B7C8:
    ctx->pc = 0x8005B7C8u;
    // 8005B7C8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005B7CC:
    ctx->pc = 0x8005B7CCu;
    // 8005B7CC: bl      0x8005B79C
    {
            ctx->lr = 0x8005B7D0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B79Cu;
                return;
            }
            goto label_8005B79C;
    }

label_8005B7D0:
    ctx->pc = 0x8005B7D0u;
    ctx->downcount -= 5;
    // 8005B7D0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B7D4:
    ctx->pc = 0x8005B7D4u;
    // 8005B7D4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B7D8:
    ctx->pc = 0x8005B7D8u;
    // 8005B7D8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B7DC:
    ctx->pc = 0x8005B7DCu;
    // 8005B7DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B7E0:
    ctx->pc = 0x8005B7E0u;
    ctx->downcount -= 5;
    // 8005B7E0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B7E4:
    ctx->pc = 0x8005B7E4u;
    // 8005B7E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B7E8:
    ctx->pc = 0x8005B7E8u;
    // 8005B7E8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B7EC:
    ctx->pc = 0x8005B7ECu;
    // 8005B7EC: li      r3, 51
    ctx->gpr[3] = (u32)(s32)(51);

label_8005B7F0:
    ctx->pc = 0x8005B7F0u;
    // 8005B7F0: bl      0x8005B79C
    {
            ctx->lr = 0x8005B7F4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B79Cu;
                return;
            }
            goto label_8005B79C;
    }

label_8005B7F4:
    ctx->pc = 0x8005B7F4u;
    ctx->downcount -= 8;
    // 8005B7F4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B7F8:
    ctx->pc = 0x8005B7F8u;
    // 8005B7F8: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8005B7FC:
    ctx->pc = 0x8005B7FCu;
    // 8005B7FC: sth     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005B800:
    ctx->pc = 0x8005B800u;
    // 8005B800: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B804:
    ctx->pc = 0x8005B804u;
    // 8005B804: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B808:
    ctx->pc = 0x8005B808u;
    // 8005B808: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B80C:
    ctx->pc = 0x8005B80Cu;
    // 8005B80C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B810:
    ctx->pc = 0x8005B810u;
    ctx->downcount -= 13;
    // 8005B810: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B814:
    ctx->pc = 0x8005B814u;
    // 8005B814: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B818:
    ctx->pc = 0x8005B818u;
    // 8005B818: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B81C:
    ctx->pc = 0x8005B81Cu;
    // 8005B81C: mulli   r10, r3, 24
    ctx->gpr[10] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)24);

label_8005B820:
    ctx->pc = 0x8005B820u;
    // 8005B820: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005B824:
    ctx->pc = 0x8005B824u;
    // 8005B824: addi    r9, r9, -2804
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2804);

label_8005B828:
    ctx->pc = 0x8005B828u;
    // 8005B828: addi    r11, r9, 16
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(16);

label_8005B82C:
    ctx->pc = 0x8005B82Cu;
    // 8005B82C: or   r3, r4, r4
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005B830:
    ctx->pc = 0x8005B830u;
    // 8005B830: lwzx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B834:
    ctx->pc = 0x8005B834u;
    // 8005B834: cmpwi   r0, 0
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

label_8005B838:
    ctx->pc = 0x8005B838u;
    // 8005B838: bc    12, 2, 0x8005B84C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005B84C;
        }
    }

label_8005B83C:
    ctx->pc = 0x8005B83Cu;
    ctx->downcount -= 5;
    // 8005B83C: add   r9, r10, r9
    {
        u32 a = ctx->gpr[10];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005B840:
    ctx->pc = 0x8005B840u;
    // 8005B840: lwz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B844:
    ctx->pc = 0x8005B844u;
    // 8005B844: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B848:
    ctx->pc = 0x8005B848u;
    // 8005B848: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8005B84Cu;
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B84C:
    ctx->pc = 0x8005B84Cu;
    ctx->downcount -= 5;
    // 8005B84C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B850:
    ctx->pc = 0x8005B850u;
    // 8005B850: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B854:
    ctx->pc = 0x8005B854u;
    // 8005B854: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005B858:
    ctx->pc = 0x8005B858u;
    // 8005B858: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B85C:
    ctx->pc = 0x8005B85Cu;
    ctx->downcount -= 17;
    // 8005B85C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B860:
    ctx->pc = 0x8005B860u;
    // 8005B860: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B864:
    ctx->pc = 0x8005B864u;
    // 8005B864: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005B868:
    ctx->pc = 0x8005B868u;
    // 8005B868: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B86C:
    ctx->pc = 0x8005B86Cu;
    // 8005B86C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005B870:
    ctx->pc = 0x8005B870u;
    // 8005B870: lis     r31, -32699
    ctx->gpr[31] = ((u32)(s32)(-32699) << 16);

label_8005B874:
    ctx->pc = 0x8005B874u;
    // 8005B874: bl      0x80055A2C
    {
            ctx->lr = 0x8005B878u;
            ctx->pc = 0x80055A2Cu;
            return;
    }

label_8005B878:
    ctx->pc = 0x8005B878u;
    ctx->downcount -= 6;
    // 8005B878: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005B87C:
    ctx->pc = 0x8005B87Cu;
    // 8005B87C: rlwinm r30, r30, 2, 0, 29
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 2u) & 0xFFFFFFFCu;
    }

label_8005B880:
    ctx->pc = 0x8005B880u;
    // 8005B880: addi    r9, r9, 4392
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4392);

label_8005B884:
    ctx->pc = 0x8005B884u;
    // 8005B884: lwzx    r30, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8005B888:
    ctx->pc = 0x8005B888u;
    // 8005B888: cmpwi   r30, 0
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

label_8005B88C:
    ctx->pc = 0x8005B88Cu;
    // 8005B88C: bc    12, 2, 0x8005B978
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005B978;
        }
    }

label_8005B890:
    ctx->pc = 0x8005B890u;
    ctx->downcount -= 1;
    // 8005B890: bl      0x800C4B6C
    {
            ctx->lr = 0x8005B894u;
            ctx->pc = 0x800C4B6Cu;
            return;
    }

label_8005B894:
    ctx->pc = 0x8005B894u;
    ctx->downcount -= 3;
    // 8005B894: lwz     r4, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005B898:
    ctx->pc = 0x8005B898u;
    // 8005B898: addi    r3, r31, -21636
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(-21636);

label_8005B89C:
    ctx->pc = 0x8005B89Cu;
    // 8005B89C: bl      0x8005B1D8
    {
            ctx->lr = 0x8005B8A0u;
            ctx->pc = 0x8005B1D8u;
            return;
    }

label_8005B8A0:
    ctx->pc = 0x8005B8A0u;
    ctx->downcount -= 13;
    // 8005B8A0: lhz     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8005B8A4:
    ctx->pc = 0x8005B8A4u;
    // 8005B8A4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005B8A8:
    ctx->pc = 0x8005B8A8u;
    // 8005B8A8: addi    r3, r31, -21636
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(-21636);

label_8005B8AC:
    ctx->pc = 0x8005B8ACu;
    // 8005B8AC: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005B8B0:
    ctx->pc = 0x8005B8B0u;
    // 8005B8B0: slw   r0, r0, r9
    {
        u32 sh = ctx->gpr[9] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_8005B8B4:
    ctx->pc = 0x8005B8B4u;
    // 8005B8B4: stw     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005B8B8:
    ctx->pc = 0x8005B8B8u;
    // 8005B8B8: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B8BC:
    ctx->pc = 0x8005B8BCu;
    // 8005B8BC: lhz     r9, 2(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(2);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8005B8C0:
    ctx->pc = 0x8005B8C0u;
    // 8005B8C0: sth     r11, 662(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(662);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_8005B8C4:
    ctx->pc = 0x8005B8C4u;
    // 8005B8C4: sth     r9, 660(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(660);
        mem_write16(ctx, ea, (u16)ctx->gpr[9]);
    }

label_8005B8C8:
    ctx->pc = 0x8005B8C8u;
    // 8005B8C8: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005B8CC:
    ctx->pc = 0x8005B8CCu;
    // 8005B8CC: cmpwi   r11, 0
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

label_8005B8D0:
    ctx->pc = 0x8005B8D0u;
    // 8005B8D0: bc    12, 2, 0x8005B978
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005B978;
        }
    }

label_8005B8D4:
    ctx->pc = 0x8005B8D4u;
    ctx->downcount -= 6;
    // 8005B8D4: lhz     r9, 2(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(2);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8005B8D8:
    ctx->pc = 0x8005B8D8u;
    // 8005B8D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005B8DC:
    ctx->pc = 0x8005B8DCu;
    // 8005B8DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8005B8E0:
    ctx->pc = 0x8005B8E0u;
    // 8005B8E0: extsh r0, r9
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_8005B8E4:
    ctx->pc = 0x8005B8E4u;
    // 8005B8E4: cmpwi   r0, -1
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

label_8005B8E8:
    ctx->pc = 0x8005B8E8u;
    // 8005B8E8: bc    12, 2, 0x8005B958
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005B958;
        }
    }

label_8005B8EC:
    ctx->pc = 0x8005B8ECu;
    ctx->downcount -= 6;
    // 8005B8EC: or   r12, r3, r3
    {
        ctx->gpr[12] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005B8F0:
    ctx->pc = 0x8005B8F0u;
    // 8005B8F0: addi    r30, r3, 1320
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(1320);

label_8005B8F4:
    ctx->pc = 0x8005B8F4u;
    // 8005B8F4: addi    r31, r3, 1332
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(1332);

label_8005B8F8:
    ctx->pc = 0x8005B8F8u;
    // 8005B8F8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8005B8FC:
    ctx->pc = 0x8005B8FCu;
    // 8005B8FC: addi    r3, r3, 1336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1336);

label_8005B900:
    ctx->pc = 0x8005B900u;
    // 8005B900: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8005B904:
    ctx->downcount -= 2;
    // 8005B904: cmpwi   r9, 0
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

label_8005B908:
    // 8005B908: bc    12, 2, 0x8005B910
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005B910;
        }
    }

label_8005B90C:
    ctx->downcount -= 1;
    // 8005B90C: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8005B910:
    ctx->pc = 0x8005B910u;
    ctx->downcount -= 7;
    // 8005B910: lha     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[9] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8005B914:
    // 8005B914: addi    r7, r12, 1328
    ctx->gpr[7] = ctx->gpr[12] + (u32)(s32)(1328);

label_8005B918:
    // 8005B918: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8005B91C:
    ctx->pc = 0x8005B91Cu;
    // 8005B91C: stwx    r9, r10, r30
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005B920:
    ctx->pc = 0x8005B920u;
    // 8005B920: lha     r0, 2(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(2);
        ctx->gpr[0] = (u32)(s32)(s16)mem_read16(ctx, ea);
    }

label_8005B924:
    // 8005B924: cmpwi   r0, 0
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

label_8005B928:
    // 8005B928: bc    4, 2, 0x8005B930
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B930;
        }
    }

label_8005B92C:
    ctx->downcount -= 1;
    // 8005B92C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8005B930:
    ctx->pc = 0x8005B930u;
    ctx->downcount -= 10;
    // 8005B930: stwx    r8, r7, r10
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005B934:
    // 8005B934: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_8005B938:
    ctx->pc = 0x8005B938u;
    // 8005B938: stwx    r6, r31, r10
    {
        u32 ea = ctx->gpr[31] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005B93C:
    // 8005B93C: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_8005B940:
    ctx->pc = 0x8005B940u;
    // 8005B940: stwx    r6, r3, r10
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[10];
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005B944:
    // 8005B944: addi    r10, r10, 20
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(20);

label_8005B948:
    ctx->pc = 0x8005B948u;
    // 8005B948: lhz     r9, 2(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(2);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_8005B94C:
    // 8005B94C: extsh r0, r9
    {
        ctx->gpr[0] = (u32)(s32)(s16)ctx->gpr[9];
    }

label_8005B950:
    // 8005B950: cmpwi   r0, -1
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

label_8005B954:
    // 8005B954: bc    4, 2, 0x8005B904
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B904u;
                return;
            }
            goto label_8005B904;
        }
    }

label_8005B958:
    ctx->pc = 0x8005B958u;
    ctx->downcount -= 6;
    // 8005B958: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B95C:
    ctx->pc = 0x8005B95Cu;
    // 8005B95C: cmpwi   r5, 0
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

label_8005B960:
    ctx->pc = 0x8005B960u;
    // 8005B960: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005B964:
    ctx->pc = 0x8005B964u;
    // 8005B964: stw     r4, 2080(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(2080);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005B968:
    ctx->pc = 0x8005B968u;
    // 8005B968: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005B96C:
    ctx->pc = 0x8005B96Cu;
    // 8005B96C: bc    4, 1, 0x8005B974
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005B974;
        }
    }

label_8005B970:
    ctx->pc = 0x8005B970u;
    ctx->downcount -= 1;
    // 8005B970: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005B974:
    ctx->pc = 0x8005B974u;
    ctx->downcount -= 1;
    // 8005B974: stw     r0, 2088(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(2088);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B978:
    ctx->pc = 0x8005B978u;
    ctx->downcount -= 19;
    // 8005B978: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B97C:
    ctx->pc = 0x8005B97Cu;
    // 8005B97C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005B980:
    ctx->pc = 0x8005B980u;
    // 8005B980: stw     r0, -21592(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B984:
    ctx->pc = 0x8005B984u;
    // 8005B984: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005B988:
    ctx->pc = 0x8005B988u;
    // 8005B988: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005B98C:
    ctx->pc = 0x8005B98Cu;
    // 8005B98C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005B990:
    ctx->pc = 0x8005B990u;
    // 8005B990: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005B994:
    ctx->pc = 0x8005B994u;
    // 8005B994: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B998:
    ctx->pc = 0x8005B998u;
    ctx->downcount -= 8;
    // 8005B998: li      r0, 18
    ctx->gpr[0] = (u32)(s32)(18);

label_8005B99C:
    ctx->pc = 0x8005B99Cu;
    // 8005B99C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005B9A0:
    ctx->pc = 0x8005B9A0u;
    // 8005B9A0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8005B9A4:
    ctx->pc = 0x8005B9A4u;
    // 8005B9A4: lis     r11, -32735
    ctx->gpr[11] = ((u32)(s32)(-32735) << 16);

label_8005B9A8:
    ctx->pc = 0x8005B9A8u;
    // 8005B9A8: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005B9AC:
    ctx->pc = 0x8005B9ACu;
    // 8005B9AC: addi    r8, r11, 4448
    ctx->gpr[8] = ctx->gpr[11] + (u32)(s32)(4448);

label_8005B9B0:
    ctx->pc = 0x8005B9B0u;
    // 8005B9B0: addi    r10, r9, 1028
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(1028);

label_8005B9B4:
    loop_8005B9B4(ctx);
    if (ctx->pc == 0x8005B9D8u) goto label_8005B9D8;
    return;
label_8005B9B8:
    ctx->pc = 0x8005B9B8u;
    // 8005B9B8: lwz     r9, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005B9BC:
    ctx->pc = 0x8005B9BCu;
    // 8005B9BC: lwz     r11, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005B9C0:
    ctx->pc = 0x8005B9C0u;
    // 8005B9C0: stw     r0, -12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B9C4:
    // 8005B9C4: addi    r8, r8, 12
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(12);

label_8005B9C8:
    ctx->pc = 0x8005B9C8u;
    // 8005B9C8: stw     r9, -4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005B9CC:
    ctx->pc = 0x8005B9CCu;
    // 8005B9CC: stw     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005B9D0:
    // 8005B9D0: addi    r10, r10, 16
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(16);

label_8005B9D4:
    // 8005B9D4: bc    16, 0, 0x8005B9B4
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B9B4u;
                return;
            }
            goto label_8005B9B4;
        }
    }

label_8005B9D8:
    ctx->pc = 0x8005B9D8u;
    ctx->downcount -= 1;
    // 8005B9D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005B9DC:
    ctx->pc = 0x8005B9DCu;
    ctx->downcount -= 19;
    // 8005B9DC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005B9E0:
    ctx->pc = 0x8005B9E0u;
    // 8005B9E0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005B9E4:
    ctx->pc = 0x8005B9E4u;
    // 8005B9E4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005B9E8:
    ctx->pc = 0x8005B9E8u;
    // 8005B9E8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005B9EC:
    ctx->pc = 0x8005B9ECu;
    // 8005B9EC: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_8005B9F0:
    ctx->pc = 0x8005B9F0u;
    // 8005B9F0: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005B9F4:
    ctx->pc = 0x8005B9F4u;
    // 8005B9F4: addi    r3, r30, 20844
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20844);

label_8005B9F8:
    ctx->pc = 0x8005B9F8u;
    // 8005B9F8: lis     r29, -32738
    ctx->gpr[29] = ((u32)(s32)(-32738) << 16);

label_8005B9FC:
    ctx->pc = 0x8005B9FCu;
    // 8005B9FC: bl      0x8005999C
    {
            ctx->lr = 0x8005BA00u;
            ctx->pc = 0x8005999Cu;
            return;
    }

label_8005BA00:
    ctx->pc = 0x8005BA00u;
    ctx->downcount -= 1;
    // 8005BA00: bl      0x800C7614
    {
            ctx->lr = 0x8005BA04u;
            ctx->pc = 0x800C7614u;
            return;
    }

label_8005BA04:
    ctx->pc = 0x8005BA04u;
    ctx->downcount -= 2;
    // 8005BA04: addi    r3, r30, 20844
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20844);

label_8005BA08:
    ctx->pc = 0x8005BA08u;
    // 8005BA08: bl      0x800599F4
    {
            ctx->lr = 0x8005BA0Cu;
            ctx->pc = 0x800599F4u;
            return;
    }

label_8005BA0C:
    ctx->pc = 0x8005BA0Cu;
    ctx->downcount -= 2;
    // 8005BA0C: addi    r3, r29, 20860
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(20860);

label_8005BA10:
    ctx->pc = 0x8005BA10u;
    // 8005BA10: bl      0x8005999C
    {
            ctx->lr = 0x8005BA14u;
            ctx->pc = 0x8005999Cu;
            return;
    }

label_8005BA14:
    ctx->pc = 0x8005BA14u;
    ctx->downcount -= 1;
    // 8005BA14: bl      0x800B7400
    {
            ctx->lr = 0x8005BA18u;
            ctx->pc = 0x800B7400u;
            return;
    }

label_8005BA18:
    ctx->pc = 0x8005BA18u;
    ctx->downcount -= 2;
    // 8005BA18: addi    r3, r29, 20860
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(20860);

label_8005BA1C:
    ctx->pc = 0x8005BA1Cu;
    // 8005BA1C: bl      0x800599F4
    {
            ctx->lr = 0x8005BA20u;
            ctx->pc = 0x800599F4u;
            return;
    }

label_8005BA20:
    ctx->pc = 0x8005BA20u;
    ctx->downcount -= 1;
    // 8005BA20: bl      0x800642C0
    {
            ctx->lr = 0x8005BA24u;
            ctx->pc = 0x800642C0u;
            return;
    }

label_8005BA24:
    ctx->pc = 0x8005BA24u;
    ctx->downcount -= 2;
    // 8005BA24: or.   r30, r3, r3
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

label_8005BA28:
    ctx->pc = 0x8005BA28u;
    // 8005BA28: bc    12, 2, 0x8005BA4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BA4C;
        }
    }

label_8005BA2C:
    ctx->pc = 0x8005BA2Cu;
    ctx->downcount -= 3;
    // 8005BA2C: lwz     r0, -31764(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31764);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BA30:
    ctx->pc = 0x8005BA30u;
    // 8005BA30: cmpwi   r0, 1
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

label_8005BA34:
    ctx->pc = 0x8005BA34u;
    // 8005BA34: bc    4, 2, 0x8005BA40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BA40;
        }
    }

label_8005BA38:
    ctx->pc = 0x8005BA38u;
    ctx->downcount -= 1;
    // 8005BA38: bl      0x8004EBA4
    {
            ctx->lr = 0x8005BA3Cu;
            ctx->pc = 0x8004EBA4u;
            return;
    }

label_8005BA3C:
    ctx->pc = 0x8005BA3Cu;
    ctx->downcount -= 1;
    // 8005BA3C: b       0x8005BA50
    {
            goto label_8005BA50;
    }

label_8005BA40:
    ctx->pc = 0x8005BA40u;
    ctx->downcount -= 2;
    // 8005BA40: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005BA44:
    ctx->pc = 0x8005BA44u;
    // 8005BA44: bl      0x8004EB40
    {
            ctx->lr = 0x8005BA48u;
            ctx->pc = 0x8004EB40u;
            return;
    }

label_8005BA48:
    ctx->pc = 0x8005BA48u;
    ctx->downcount -= 1;
    // 8005BA48: b       0x8005BA50
    {
            goto label_8005BA50;
    }

label_8005BA4C:
    ctx->pc = 0x8005BA4Cu;
    ctx->downcount -= 1;
    // 8005BA4C: bl      0x8004EBA4
    {
            ctx->lr = 0x8005BA50u;
            ctx->pc = 0x8004EBA4u;
            return;
    }

label_8005BA50:
    ctx->pc = 0x8005BA50u;
    ctx->downcount -= 1;
    // 8005BA50: bl      0x800CAE6C
    {
            ctx->lr = 0x8005BA54u;
            ctx->pc = 0x800CAE6Cu;
            return;
    }

label_8005BA54:
    ctx->pc = 0x8005BA54u;
    ctx->downcount -= 2;
    // 8005BA54: cmpwi   r3, 0
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

label_8005BA58:
    ctx->pc = 0x8005BA58u;
    // 8005BA58: bc    4, 2, 0x8005BB1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BB1C;
        }
    }

label_8005BA5C:
    ctx->pc = 0x8005BA5Cu;
    ctx->downcount -= 3;
    // 8005BA5C: cmpwi   r30, 0
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

label_8005BA60:
    ctx->pc = 0x8005BA60u;
    // 8005BA60: mfcr    r30
    ctx->gpr[30] = ctx->cr;

label_8005BA64:
    ctx->pc = 0x8005BA64u;
    // 8005BA64: bc    12, 2, 0x8005BA74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BA74;
        }
    }

label_8005BA68:
    ctx->pc = 0x8005BA68u;
    ctx->downcount -= 1;
    // 8005BA68: bl      0x80065F50
    {
            ctx->lr = 0x8005BA6Cu;
            ctx->pc = 0x80065F50u;
            return;
    }

label_8005BA6C:
    ctx->pc = 0x8005BA6Cu;
    ctx->downcount -= 2;
    // 8005BA6C: cmpwi   r3, 0
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

label_8005BA70:
    ctx->pc = 0x8005BA70u;
    // 8005BA70: bc    12, 2, 0x8005BA78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BA78;
        }
    }

label_8005BA74:
    ctx->pc = 0x8005BA74u;
    ctx->downcount -= 1;
    // 8005BA74: bl      0x80045DD8
    {
            ctx->lr = 0x8005BA78u;
            ctx->pc = 0x80045DD8u;
            return;
    }

label_8005BA78:
    ctx->pc = 0x8005BA78u;
    ctx->downcount -= 2;
    // 8005BA78: mtcrf   0x80, r30
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[30] & 0xF0000000u);

label_8005BA7C:
    ctx->pc = 0x8005BA7Cu;
    // 8005BA7C: bc    4, 2, 0x8005BB1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BB1C;
        }
    }

label_8005BA80:
    ctx->pc = 0x8005BA80u;
    ctx->downcount -= 5;
    // 8005BA80: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_8005BA84:
    ctx->pc = 0x8005BA84u;
    // 8005BA84: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005BA88:
    ctx->pc = 0x8005BA88u;
    // 8005BA88: addi    r3, r30, 20876
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20876);

label_8005BA8C:
    ctx->pc = 0x8005BA8Cu;
    // 8005BA8C: lis     r29, -32738
    ctx->gpr[29] = ((u32)(s32)(-32738) << 16);

label_8005BA90:
    ctx->pc = 0x8005BA90u;
    // 8005BA90: bl      0x80046418
    {
            ctx->lr = 0x8005BA94u;
            ctx->pc = 0x80046418u;
            return;
    }

label_8005BA94:
    ctx->pc = 0x8005BA94u;
    ctx->downcount -= 1;
    // 8005BA94: bl      0x80094CB8
    {
            ctx->lr = 0x8005BA98u;
            ctx->pc = 0x80094CB8u;
            return;
    }

label_8005BA98:
    ctx->pc = 0x8005BA98u;
    ctx->downcount -= 2;
    // 8005BA98: addi    r3, r30, 20876
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20876);

label_8005BA9C:
    ctx->pc = 0x8005BA9Cu;
    // 8005BA9C: bl      0x800464F8
    {
            ctx->lr = 0x8005BAA0u;
            ctx->pc = 0x800464F8u;
            return;
    }

label_8005BAA0:
    ctx->pc = 0x8005BAA0u;
    ctx->downcount -= 3;
    // 8005BAA0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005BAA4:
    ctx->pc = 0x8005BAA4u;
    // 8005BAA4: addi    r3, r29, 20892
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(20892);

label_8005BAA8:
    ctx->pc = 0x8005BAA8u;
    // 8005BAA8: bl      0x80046418
    {
            ctx->lr = 0x8005BAACu;
            ctx->pc = 0x80046418u;
            return;
    }

label_8005BAAC:
    ctx->pc = 0x8005BAACu;
    ctx->downcount -= 1;
    // 8005BAAC: bl      0x80051108
    {
            ctx->lr = 0x8005BAB0u;
            ctx->pc = 0x80051108u;
            return;
    }

label_8005BAB0:
    ctx->pc = 0x8005BAB0u;
    ctx->downcount -= 2;
    // 8005BAB0: addi    r3, r29, 20892
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(20892);

label_8005BAB4:
    ctx->pc = 0x8005BAB4u;
    // 8005BAB4: bl      0x800464F8
    {
            ctx->lr = 0x8005BAB8u;
            ctx->pc = 0x800464F8u;
            return;
    }

label_8005BAB8:
    ctx->pc = 0x8005BAB8u;
    ctx->downcount -= 1;
    // 8005BAB8: bl      0x8004C38C
    {
            ctx->lr = 0x8005BABCu;
            ctx->pc = 0x8004C38Cu;
            return;
    }

label_8005BABC:
    ctx->pc = 0x8005BABCu;
    ctx->downcount -= 2;
    // 8005BABC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005BAC0:
    ctx->pc = 0x8005BAC0u;
    // 8005BAC0: bl      0x8001D910
    {
            ctx->lr = 0x8005BAC4u;
            ctx->pc = 0x8001D910u;
            return;
    }

label_8005BAC4:
    ctx->pc = 0x8005BAC4u;
    ctx->downcount -= 3;
    // 8005BAC4: lis     r3, -32700
    ctx->gpr[3] = ((u32)(s32)(-32700) << 16);

label_8005BAC8:
    ctx->pc = 0x8005BAC8u;
    // 8005BAC8: addi    r3, r3, -22100
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22100);

label_8005BACC:
    ctx->pc = 0x8005BACCu;
    // 8005BACC: bl      0x8003D710
    {
            ctx->lr = 0x8005BAD0u;
            ctx->pc = 0x8003D710u;
            return;
    }

label_8005BAD0:
    ctx->pc = 0x8005BAD0u;
    ctx->downcount -= 3;
    // 8005BAD0: lwz     r0, -31848(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31848);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BAD4:
    ctx->pc = 0x8005BAD4u;
    // 8005BAD4: cmpwi   r0, 0
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

label_8005BAD8:
    ctx->pc = 0x8005BAD8u;
    // 8005BAD8: bc    4, 2, 0x8005BAE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BAE0;
        }
    }

label_8005BADC:
    ctx->pc = 0x8005BADCu;
    ctx->downcount -= 1;
    // 8005BADC: bl      0x8004FB84
    {
            ctx->lr = 0x8005BAE0u;
            ctx->pc = 0x8004FB84u;
            return;
    }

label_8005BAE0:
    ctx->pc = 0x8005BAE0u;
    ctx->downcount -= 11;
    // 8005BAE0: lis     r10, -32699
    ctx->gpr[10] = ((u32)(s32)(-32699) << 16);

label_8005BAE4:
    ctx->pc = 0x8005BAE4u;
    // 8005BAE4: lis     r11, -32735
    ctx->gpr[11] = ((u32)(s32)(-32735) << 16);

label_8005BAE8:
    ctx->pc = 0x8005BAE8u;
    // 8005BAE8: lwz     r9, -21636(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-21636);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005BAEC:
    ctx->pc = 0x8005BAECu;
    // 8005BAEC: addi    r11, r11, -2804
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-2804);

label_8005BAF0:
    ctx->pc = 0x8005BAF0u;
    // 8005BAF0: mulli   r9, r9, 24
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)24);

label_8005BAF4:
    ctx->pc = 0x8005BAF4u;
    // 8005BAF4: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005BAF8:
    ctx->pc = 0x8005BAF8u;
    // 8005BAF8: lwz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BAFC:
    ctx->pc = 0x8005BAFCu;
    // 8005BAFC: cmpwi   r0, 0
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

label_8005BB00:
    ctx->pc = 0x8005BB00u;
    // 8005BB00: bc    12, 2, 0x8005BB10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BB10;
        }
    }

label_8005BB04:
    ctx->pc = 0x8005BB04u;
    ctx->downcount -= 4;
    // 8005BB04: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005BB08:
    ctx->pc = 0x8005BB08u;
    // 8005BB08: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005BB0C:
    ctx->pc = 0x8005BB0Cu;
    // 8005BB0C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8005BB10u;
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BB10:
    ctx->pc = 0x8005BB10u;
    ctx->downcount -= 3;
    // 8005BB10: lwz     r9, -32368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32368);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005BB14:
    ctx->pc = 0x8005BB14u;
    // 8005BB14: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_8005BB18:
    ctx->pc = 0x8005BB18u;
    // 8005BB18: stw     r9, -32368(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32368);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005BB1C:
    ctx->pc = 0x8005BB1Cu;
    ctx->downcount -= 1;
    // 8005BB1C: bl      0x8001B13C
    {
            ctx->lr = 0x8005BB20u;
            ctx->pc = 0x8001B13Cu;
            return;
    }

label_8005BB20:
    ctx->pc = 0x8005BB20u;
    ctx->downcount -= 1;
    // 8005BB20: bl      0x80066734
    {
            ctx->lr = 0x8005BB24u;
            ctx->pc = 0x80066734u;
            return;
    }

label_8005BB24:
    ctx->pc = 0x8005BB24u;
    ctx->downcount -= 16;
    // 8005BB24: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BB28:
    ctx->pc = 0x8005BB28u;
    // 8005BB28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005BB2C:
    ctx->pc = 0x8005BB2Cu;
    // 8005BB2C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005BB30:
    ctx->pc = 0x8005BB30u;
    // 8005BB30: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8005BB34:
    ctx->pc = 0x8005BB34u;
    // 8005BB34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BB38:
    ctx->pc = 0x8005BB38u;
    ctx->downcount -= 4;
    // 8005BB38: lwz     r0, -31824(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31824);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BB3C:
    ctx->pc = 0x8005BB3Cu;
    // 8005BB3C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8005BB40:
    ctx->pc = 0x8005BB40u;
    // 8005BB40: cmpw    r10, r0
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BB44:
    ctx->pc = 0x8005BB44u;
    // 8005BB44: bc    4, 0, 0x8005BBD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BBD8;
        }
    }

label_8005BB48:
    ctx->pc = 0x8005BB48u;
    ctx->downcount -= 8;
    // 8005BB48: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005BB4C:
    ctx->pc = 0x8005BB4Cu;
    // 8005BB4C: lis     r11, -32735
    ctx->gpr[11] = ((u32)(s32)(-32735) << 16);

label_8005BB50:
    ctx->pc = 0x8005BB50u;
    // 8005BB50: lwz     r8, -21636(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21636);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005BB54:
    ctx->pc = 0x8005BB54u;
    // 8005BB54: or   r7, r0, r0
    {
        ctx->gpr[7] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8005BB58:
    ctx->pc = 0x8005BB58u;
    // 8005BB58: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005BB5C:
    ctx->pc = 0x8005BB5Cu;
    // 8005BB5C: addi    r11, r11, 4640
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4640);

label_8005BB60:
    ctx->pc = 0x8005BB60u;
    // 8005BB60: cmpwi   cr6, r8, 24
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(24);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 4)) | (cr_bits << 4);
    }

label_8005BB64:
    ctx->pc = 0x8005BB64u;
    // 8005BB64: cmpwi   cr7, r8, 29
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(29);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 0)) | (cr_bits << 0);
    }

label_8005BB68:
    ctx->pc = 0x8005BB68u;
    ctx->downcount -= 3;
    // 8005BB68: lwz     r0, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BB6C:
    // 8005BB6C: cmpw    r8, r0
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BB70:
    // 8005BB70: bc    4, 2, 0x8005BBC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BBC8;
        }
    }

label_8005BB74:
    ctx->pc = 0x8005BB74u;
    ctx->downcount -= 4;
    // 8005BB74: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BB78:
    // 8005BB78: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005BB7C:
    // 8005BB7C: andi.   r10, r0, 0x0001
    {
        ctx->gpr[10] = ctx->gpr[0] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005BB80:
    // 8005BB80: bc    12, 2, 0x8005BB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BB88;
        }
    }

label_8005BB84:
    ctx->downcount -= 1;
    // 8005BB84: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8005BB88:
    ctx->downcount -= 2;
    // 8005BB88: cmpwi   r9, 0
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

label_8005BB8C:
    // 8005BB8C: bc    12, 2, 0x8005BBC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BBC0;
        }
    }

label_8005BB90:
    ctx->downcount -= 2;
    // 8005BB90: cmpwi   r8, 26
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(26);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BB94:
    // 8005BB94: bc    12, 2, 0x8005BBB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BBB0;
        }
    }

label_8005BB98:
    ctx->downcount -= 1;
    // 8005BB98: bc    12, 1, 0x8005BBA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BBA4;
        }
    }

label_8005BB9C:
    ctx->downcount -= 1;
    // 8005BB9C: bc    12, 26, 0x8005BBB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000020u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BBB8;
        }
    }

label_8005BBA0:
    ctx->downcount -= 1;
    // 8005BBA0: b       0x8005BBC0
    {
            goto label_8005BBC0;
    }

label_8005BBA4:
    ctx->downcount -= 1;
    // 8005BBA4: bc    4, 30, 0x8005BBC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00000002u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BBC0;
        }
    }

label_8005BBA8:
    ctx->downcount -= 2;
    // 8005BBA8: li      r3, 240
    ctx->gpr[3] = (u32)(s32)(240);

label_8005BBAC:
    ctx->pc = 0x8005BBACu;
    // 8005BBAC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BBB0:
    ctx->downcount -= 2;
    // 8005BBB0: li      r3, 243
    ctx->gpr[3] = (u32)(s32)(243);

label_8005BBB4:
    ctx->pc = 0x8005BBB4u;
    // 8005BBB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BBB8:
    ctx->downcount -= 2;
    // 8005BBB8: li      r3, 245
    ctx->gpr[3] = (u32)(s32)(245);

label_8005BBBC:
    ctx->pc = 0x8005BBBCu;
    // 8005BBBC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BBC0:
    ctx->pc = 0x8005BBC0u;
    ctx->downcount -= 2;
    // 8005BBC0: lwz     r3, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005BBC4:
    ctx->pc = 0x8005BBC4u;
    // 8005BBC4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BBC8:
    ctx->downcount -= 4;
    // 8005BBC8: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_8005BBCC:
    // 8005BBCC: addi    r11, r11, 12
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(12);

label_8005BBD0:
    // 8005BBD0: cmpw    r10, r7
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(ctx->gpr[7]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BBD4:
    // 8005BBD4: bc    12, 0, 0x8005BB68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BB68u;
                return;
            }
            goto label_8005BB68;
        }
    }

label_8005BBD8:
    ctx->pc = 0x8005BBD8u;
    ctx->downcount -= 2;
    // 8005BBD8: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_8005BBDC:
    ctx->pc = 0x8005BBDCu;
    // 8005BBDC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BBE0:
    ctx->pc = 0x8005BBE0u;
    ctx->downcount -= 20;
    // 8005BBE0: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005BBE4:
    ctx->pc = 0x8005BBE4u;
    // 8005BBE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005BBE8:
    ctx->pc = 0x8005BBE8u;
    // 8005BBE8: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005BBEC:
    ctx->pc = 0x8005BBECu;
    // 8005BBEC: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BBF0:
    ctx->pc = 0x8005BBF0u;
    // 8005BBF0: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_8005BBF4:
    ctx->pc = 0x8005BBF4u;
    // 8005BBF4: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005BBF8:
    ctx->pc = 0x8005BBF8u;
    // 8005BBF8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005BBFC:
    ctx->pc = 0x8005BBFCu;
    // 8005BBFC: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8005BC00:
    ctx->pc = 0x8005BC00u;
    // 8005BC00: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BC04:
    ctx->pc = 0x8005BC04u;
    // 8005BC04: bl      0x80034A2C
    {
            ctx->lr = 0x8005BC08u;
            ctx->pc = 0x80034A2Cu;
            return;
    }

label_8005BC08:
    ctx->pc = 0x8005BC08u;
    ctx->downcount -= 5;
    // 8005BC08: lwz     r4, -27488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27488);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005BC0C:
    ctx->pc = 0x8005BC0Cu;
    // 8005BC0C: lis     r5, -16384
    ctx->gpr[5] = ((u32)(s32)(-16384) << 16);

label_8005BC10:
    ctx->pc = 0x8005BC10u;
    // 8005BC10: ori     r5, r5, 0x0005
    ctx->gpr[5] = ctx->gpr[5] | 0x0005u;

label_8005BC14:
    ctx->pc = 0x8005BC14u;
    // 8005BC14: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BC18:
    ctx->pc = 0x8005BC18u;
    // 8005BC18: bl      0x80034BB0
    {
            ctx->lr = 0x8005BC1Cu;
            ctx->pc = 0x80034BB0u;
            return;
    }

label_8005BC1C:
    ctx->pc = 0x8005BC1Cu;
    ctx->downcount -= 3;
    // 8005BC1C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BC20:
    ctx->pc = 0x8005BC20u;
    // 8005BC20: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005BC24:
    ctx->pc = 0x8005BC24u;
    // 8005BC24: bl      0x80035C48
    {
            ctx->lr = 0x8005BC28u;
            ctx->pc = 0x80035C48u;
            return;
    }

label_8005BC28:
    ctx->pc = 0x8005BC28u;
    ctx->downcount -= 4;
    // 8005BC28: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8005BC2C:
    ctx->pc = 0x8005BC2Cu;
    // 8005BC2C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BC30:
    ctx->pc = 0x8005BC30u;
    // 8005BC30: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8005BC34:
    ctx->pc = 0x8005BC34u;
    // 8005BC34: bl      0x80035C50
    {
            ctx->lr = 0x8005BC38u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_8005BC38:
    ctx->pc = 0x8005BC38u;
    ctx->downcount -= 3;
    // 8005BC38: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BC3C:
    ctx->pc = 0x8005BC3Cu;
    // 8005BC3C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005BC40:
    ctx->pc = 0x8005BC40u;
    // 8005BC40: bl      0x80035C40
    {
            ctx->lr = 0x8005BC44u;
            ctx->pc = 0x80035C40u;
            return;
    }

label_8005BC44:
    ctx->pc = 0x8005BC44u;
    ctx->downcount -= 4;
    // 8005BC44: lis     r4, -56
    ctx->gpr[4] = ((u32)(s32)(-56) << 16);

label_8005BC48:
    ctx->pc = 0x8005BC48u;
    // 8005BC48: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BC4C:
    ctx->pc = 0x8005BC4Cu;
    // 8005BC4C: ori     r4, r4, 0xC800
    ctx->gpr[4] = ctx->gpr[4] | 0xC800u;

label_8005BC50:
    ctx->pc = 0x8005BC50u;
    // 8005BC50: bl      0x80034BA8
    {
            ctx->lr = 0x8005BC54u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005BC54:
    ctx->pc = 0x8005BC54u;
    ctx->downcount -= 5;
    // 8005BC54: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BC58:
    ctx->pc = 0x8005BC58u;
    // 8005BC58: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8005BC5C:
    ctx->pc = 0x8005BC5Cu;
    // 8005BC5C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005BC60:
    ctx->pc = 0x8005BC60u;
    // 8005BC60: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005BC64:
    ctx->pc = 0x8005BC64u;
    // 8005BC64: bl      0x80034E9C
    {
            ctx->lr = 0x8005BC68u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8005BC68:
    ctx->pc = 0x8005BC68u;
    ctx->downcount -= 16;
    // 8005BC68: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BC6C:
    ctx->pc = 0x8005BC6Cu;
    // 8005BC6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005BC70:
    ctx->pc = 0x8005BC70u;
    // 8005BC70: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005BC74:
    ctx->pc = 0x8005BC74u;
    // 8005BC74: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8005BC78:
    ctx->pc = 0x8005BC78u;
    // 8005BC78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BC7C:
    ctx->pc = 0x8005BC7Cu;
    ctx->downcount -= 18;
    // 8005BC7C: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005BC80:
    ctx->pc = 0x8005BC80u;
    // 8005BC80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005BC84:
    ctx->pc = 0x8005BC84u;
    // 8005BC84: stmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005BC88:
    ctx->pc = 0x8005BC88u;
    // 8005BC88: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BC8C:
    ctx->pc = 0x8005BC8Cu;
    // 8005BC8C: lwz     r0, -31840(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31840);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BC90:
    ctx->pc = 0x8005BC90u;
    // 8005BC90: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005BC94:
    ctx->pc = 0x8005BC94u;
    // 8005BC94: cmpwi   r0, 0
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

label_8005BC98:
    ctx->pc = 0x8005BC98u;
    // 8005BC98: bc    4, 2, 0x8005BCCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005BCCC;
        }
    }

label_8005BC9C:
    ctx->pc = 0x8005BC9Cu;
    ctx->downcount -= 12;
    // 8005BC9C: xoris   r0, r30, 0x8000
    ctx->gpr[0] = ctx->gpr[30] ^ (0x8000u << 16);

label_8005BCA0:
    ctx->pc = 0x8005BCA0u;
    // 8005BCA0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BCA4:
    ctx->pc = 0x8005BCA4u;
    // 8005BCA4: lis     r10, 17200
    ctx->gpr[10] = ((u32)(s32)(17200) << 16);

label_8005BCA8:
    ctx->pc = 0x8005BCA8u;
    // 8005BCA8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005BCAC:
    ctx->pc = 0x8005BCACu;
    // 8005BCAC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005BCB0:
    ctx->pc = 0x8005BCB0u;
    // 8005BCB0: stw     r10, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005BCB4:
    ctx->pc = 0x8005BCB4u;
    // 8005BCB4: lfd     f13, 21520(r9)
    if (!ppc_fp_available(ctx, 0x8005BCB4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21520);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BCB8:
    ctx->pc = 0x8005BCB8u;
    // 8005BCB8: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005BCB8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BCBC:
    ctx->pc = 0x8005BCBCu;
    // 8005BCBC: stw     r0, -31840(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31840);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BCC0:
    ctx->pc = 0x8005BCC0u;
    // 8005BCC0: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x8005BCC0u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_8005BCC4:
    ctx->pc = 0x8005BCC4u;
    // 8005BCC4: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005BCC4u)) return;
    ppc_frsp(ctx, 0, 0);

label_8005BCC8:
    ctx->pc = 0x8005BCC8u;
    // 8005BCC8: stfs     f0, -31836(r13)
    if (!ppc_fp_available(ctx, 0x8005BCC8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31836);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005BCCC:
    ctx->pc = 0x8005BCCCu;
    ctx->downcount -= 1;
    // 8005BCCC: bl      0x8005BB38
    {
            ctx->lr = 0x8005BCD0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BB38u;
                return;
            }
            goto label_8005BB38;
    }

label_8005BCD0:
    ctx->pc = 0x8005BCD0u;
    ctx->downcount -= 40;
    // 8005BCD0: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005BCD4:
    ctx->pc = 0x8005BCD4u;
    // 8005BCD4: lfs     f11, -31836(r13)
    if (!ppc_fp_available(ctx, 0x8005BCD4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31836);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005BCD8:
    ctx->pc = 0x8005BCD8u;
    // 8005BCD8: lfs     f12, 21528(r9)
    if (!ppc_fp_available(ctx, 0x8005BCD8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21528);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8005BCDC:
    ctx->pc = 0x8005BCDCu;
    // 8005BCDC: xoris   r0, r30, 0x8000
    ctx->gpr[0] = ctx->gpr[30] ^ (0x8000u << 16);

label_8005BCE0:
    ctx->pc = 0x8005BCE0u;
    // 8005BCE0: lis     r8, 17200
    ctx->gpr[8] = ((u32)(s32)(17200) << 16);

label_8005BCE4:
    ctx->pc = 0x8005BCE4u;
    // 8005BCE4: fdivs   f12, f12, f11
    if (!ppc_fp_available(ctx, 0x8005BCE4u)) return;
    ppc_fdivs(ctx, 12, 12, 11);

label_8005BCE8:
    ctx->pc = 0x8005BCE8u;
    // 8005BCE8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BCEC:
    ctx->pc = 0x8005BCECu;
    // 8005BCEC: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005BCF0:
    ctx->pc = 0x8005BCF0u;
    // 8005BCF0: lfs     f9, -31828(r13)
    if (!ppc_fp_available(ctx, 0x8005BCF0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[9] = value;
        ctx->ps1[9] = value;
    }

label_8005BCF4:
    ctx->pc = 0x8005BCF4u;
    // 8005BCF4: stw     r8, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005BCF8:
    ctx->pc = 0x8005BCF8u;
    // 8005BCF8: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005BCFC:
    ctx->pc = 0x8005BCFCu;
    // 8005BCFC: lfd     f13, 21520(r11)
    if (!ppc_fp_available(ctx, 0x8005BCFCu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21520);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BD00:
    ctx->pc = 0x8005BD00u;
    // 8005BD00: cmpwi   r3, 0
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

label_8005BD04:
    ctx->pc = 0x8005BD04u;
    // 8005BD04: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005BD04u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BD08:
    ctx->pc = 0x8005BD08u;
    // 8005BD08: lfs     f10, 21532(r10)
    if (!ppc_fp_available(ctx, 0x8005BD08u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(21532);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_8005BD0C:
    ctx->pc = 0x8005BD0Cu;
    // 8005BD0C: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x8005BD0Cu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_8005BD10:
    ctx->pc = 0x8005BD10u;
    // 8005BD10: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005BD10u)) return;
    ppc_frsp(ctx, 0, 0);

label_8005BD14:
    ctx->pc = 0x8005BD14u;
    // 8005BD14: fsubs   f11, f11, f0
    if (!ppc_fp_available(ctx, 0x8005BD14u)) return;
    ppc_fsubs(ctx, 11, 11, 0);

label_8005BD18:
    ctx->pc = 0x8005BD18u;
    // 8005BD18: fmuls   f12, f12, f11
    if (!ppc_fp_available(ctx, 0x8005BD18u)) return;
    ppc_fmuls(ctx, 12, 12, 11);

label_8005BD1C:
    ctx->pc = 0x8005BD1Cu;
    // 8005BD1C: fsubs   f0, f12, f9
    if (!ppc_fp_available(ctx, 0x8005BD1Cu)) return;
    ppc_fsubs(ctx, 0, 12, 9);

label_8005BD20:
    ctx->pc = 0x8005BD20u;
    // 8005BD20: stfs     f12, -31832(r13)
    if (!ppc_fp_available(ctx, 0x8005BD20u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31832);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8005BD24:
    ctx->pc = 0x8005BD24u;
    // 8005BD24: fmadds f0, f0, f10, f9
    if (!ppc_fp_available(ctx, 0x8005BD24u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[0], ctx->fpr[10], ctx->fpr[9], true, false, false, &result))
            ctx->fpr[0] = ctx->ps1[0] = result;
    }

label_8005BD28:
    ctx->pc = 0x8005BD28u;
    // 8005BD28: stfs     f0, -31828(r13)
    if (!ppc_fp_available(ctx, 0x8005BD28u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31828);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005BD2C:
    ctx->pc = 0x8005BD2Cu;
    // 8005BD2C: bc    12, 0, 0x8005BE00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BE00;
        }
    }

label_8005BD30:
    ctx->pc = 0x8005BD30u;
    ctx->downcount -= 1;
    // 8005BD30: bl      0x8005BB38
    {
            ctx->lr = 0x8005BD34u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BB38u;
                return;
            }
            goto label_8005BB38;
    }

label_8005BD34:
    ctx->pc = 0x8005BD34u;
    ctx->downcount -= 23;
    // 8005BD34: lis     r29, -32738
    ctx->gpr[29] = ((u32)(s32)(-32738) << 16);

label_8005BD38:
    ctx->pc = 0x8005BD38u;
    // 8005BD38: lfs     f0, -31828(r13)
    if (!ppc_fp_available(ctx, 0x8005BD38u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005BD3C:
    ctx->pc = 0x8005BD3Cu;
    // 8005BD3C: mulli   r5, r3, 56
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)56);

label_8005BD40:
    ctx->pc = 0x8005BD40u;
    // 8005BD40: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005BD44:
    ctx->pc = 0x8005BD44u;
    // 8005BD44: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005BD48:
    ctx->pc = 0x8005BD48u;
    // 8005BD48: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8005BD48u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_8005BD4C:
    ctx->pc = 0x8005BD4Cu;
    // 8005BD4C: lis     r30, -32736
    ctx->gpr[30] = ((u32)(s32)(-32736) << 16);

label_8005BD50:
    ctx->pc = 0x8005BD50u;
    // 8005BD50: stfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005BD50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_8005BD54:
    ctx->pc = 0x8005BD54u;
    // 8005BD54: addi    r30, r30, 11952
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(11952);

label_8005BD58:
    ctx->pc = 0x8005BD58u;
    // 8005BD58: lfs     f2, 21540(r10)
    if (!ppc_fp_available(ctx, 0x8005BD58u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(21540);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8005BD5C:
    ctx->pc = 0x8005BD5Cu;
    // 8005BD5C: lis     r6, 8192
    ctx->gpr[6] = ((u32)(s32)(8192) << 16);

label_8005BD60:
    ctx->pc = 0x8005BD60u;
    // 8005BD60: lwz     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005BD64:
    ctx->pc = 0x8005BD64u;
    // 8005BD64: add   r5, r5, r30
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8005BD68:
    ctx->pc = 0x8005BD68u;
    // 8005BD68: lfs     f1, 21536(r11)
    if (!ppc_fp_available(ctx, 0x8005BD68u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005BD6C:
    ctx->pc = 0x8005BD6Cu;
    // 8005BD6C: li      r4, 16
    ctx->gpr[4] = (u32)(s32)(16);

label_8005BD70:
    ctx->pc = 0x8005BD70u;
    // 8005BD70: lfs     f3, 21544(r29)
    if (!ppc_fp_available(ctx, 0x8005BD70u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(21544);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8005BD74:
    ctx->pc = 0x8005BD74u;
    // 8005BD74: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005BD78:
    ctx->pc = 0x8005BD78u;
    // 8005BD78: ori     r6, r6, 0x0144
    ctx->gpr[6] = ctx->gpr[6] | 0x0144u;

label_8005BD7C:
    ctx->pc = 0x8005BD7Cu;
    // 8005BD7C: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8005BD80:
    ctx->pc = 0x8005BD80u;
    // 8005BD80: li      r8, 1
    ctx->gpr[8] = (u32)(s32)(1);

label_8005BD84:
    ctx->pc = 0x8005BD84u;
    // 8005BD84: bl      0x80011210
    {
            ctx->lr = 0x8005BD88u;
            ctx->pc = 0x80011210u;
            return;
    }

label_8005BD88:
    ctx->pc = 0x8005BD88u;
    ctx->downcount -= 1;
    // 8005BD88: bl      0x8005BB38
    {
            ctx->lr = 0x8005BD8Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BB38u;
                return;
            }
            goto label_8005BB38;
    }

label_8005BD8C:
    ctx->pc = 0x8005BD8Cu;
    ctx->downcount -= 16;
    // 8005BD8C: mulli   r5, r3, 56
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)56);

label_8005BD90:
    ctx->pc = 0x8005BD90u;
    // 8005BD90: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005BD94:
    ctx->pc = 0x8005BD94u;
    // 8005BD94: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005BD98:
    ctx->pc = 0x8005BD98u;
    // 8005BD98: lfs     f1, 21548(r9)
    if (!ppc_fp_available(ctx, 0x8005BD98u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21548);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005BD9C:
    ctx->pc = 0x8005BD9Cu;
    // 8005BD9C: lfs     f2, 21552(r11)
    if (!ppc_fp_available(ctx, 0x8005BD9Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21552);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8005BDA0:
    ctx->pc = 0x8005BDA0u;
    // 8005BDA0: lis     r6, 8192
    ctx->gpr[6] = ((u32)(s32)(8192) << 16);

label_8005BDA4:
    ctx->pc = 0x8005BDA4u;
    // 8005BDA4: lfs     f3, 21544(r29)
    if (!ppc_fp_available(ctx, 0x8005BDA4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(21544);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8005BDA8:
    ctx->pc = 0x8005BDA8u;
    // 8005BDA8: li      r4, 128
    ctx->gpr[4] = (u32)(s32)(128);

label_8005BDAC:
    ctx->pc = 0x8005BDACu;
    // 8005BDAC: add   r5, r5, r30
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8005BDB0:
    ctx->pc = 0x8005BDB0u;
    // 8005BDB0: ori     r6, r6, 0x0151
    ctx->gpr[6] = ctx->gpr[6] | 0x0151u;

label_8005BDB4:
    ctx->pc = 0x8005BDB4u;
    // 8005BDB4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8005BDB8:
    ctx->pc = 0x8005BDB8u;
    // 8005BDB8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8005BDBC:
    ctx->pc = 0x8005BDBCu;
    // 8005BDBC: li      r3, 128
    ctx->gpr[3] = (u32)(s32)(128);

label_8005BDC0:
    ctx->pc = 0x8005BDC0u;
    // 8005BDC0: bl      0x80011210
    {
            ctx->lr = 0x8005BDC4u;
            ctx->pc = 0x80011210u;
            return;
    }

label_8005BDC4:
    ctx->pc = 0x8005BDC4u;
    ctx->downcount -= 1;
    // 8005BDC4: bl      0x8005BB38
    {
            ctx->lr = 0x8005BDC8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BB38u;
                return;
            }
            goto label_8005BB38;
    }

label_8005BDC8:
    ctx->pc = 0x8005BDC8u;
    ctx->downcount -= 16;
    // 8005BDC8: mulli   r5, r3, 56
    ctx->gpr[5] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)56);

label_8005BDCC:
    ctx->pc = 0x8005BDCCu;
    // 8005BDCC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005BDD0:
    ctx->pc = 0x8005BDD0u;
    // 8005BDD0: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005BDD4:
    ctx->pc = 0x8005BDD4u;
    // 8005BDD4: lfs     f1, 21556(r9)
    if (!ppc_fp_available(ctx, 0x8005BDD4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21556);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005BDD8:
    ctx->pc = 0x8005BDD8u;
    // 8005BDD8: lis     r6, 8192
    ctx->gpr[6] = ((u32)(s32)(8192) << 16);

label_8005BDDC:
    ctx->pc = 0x8005BDDCu;
    // 8005BDDC: lfs     f2, 21560(r11)
    if (!ppc_fp_available(ctx, 0x8005BDDCu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21560);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8005BDE0:
    ctx->pc = 0x8005BDE0u;
    // 8005BDE0: lfs     f3, 21544(r29)
    if (!ppc_fp_available(ctx, 0x8005BDE0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(21544);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8005BDE4:
    ctx->pc = 0x8005BDE4u;
    // 8005BDE4: li      r3, 640
    ctx->gpr[3] = (u32)(s32)(640);

label_8005BDE8:
    ctx->pc = 0x8005BDE8u;
    // 8005BDE8: add   r5, r5, r30
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8005BDEC:
    ctx->pc = 0x8005BDECu;
    // 8005BDEC: li      r4, 300
    ctx->gpr[4] = (u32)(s32)(300);

label_8005BDF0:
    ctx->pc = 0x8005BDF0u;
    // 8005BDF0: ori     r6, r6, 0x013F
    ctx->gpr[6] = ctx->gpr[6] | 0x013Fu;

label_8005BDF4:
    ctx->pc = 0x8005BDF4u;
    // 8005BDF4: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_8005BDF8:
    ctx->pc = 0x8005BDF8u;
    // 8005BDF8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8005BDFC:
    ctx->pc = 0x8005BDFCu;
    // 8005BDFC: bl      0x80011210
    {
            ctx->lr = 0x8005BE00u;
            ctx->pc = 0x80011210u;
            return;
    }

label_8005BE00:
    ctx->pc = 0x8005BE00u;
    ctx->downcount -= 4;
    // 8005BE00: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_8005BE04:
    ctx->pc = 0x8005BE04u;
    // 8005BE04: li      r4, 4658
    ctx->gpr[4] = (u32)(s32)(4658);

label_8005BE08:
    ctx->pc = 0x8005BE08u;
    // 8005BE08: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_8005BE0C:
    ctx->pc = 0x8005BE0Cu;
    // 8005BE0C: bl      0x80046B00
    {
            ctx->lr = 0x8005BE10u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8005BE10:
    ctx->pc = 0x8005BE10u;
    ctx->downcount -= 4;
    // 8005BE10: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005BE14:
    ctx->pc = 0x8005BE14u;
    // 8005BE14: li      r4, 284
    ctx->gpr[4] = (u32)(s32)(284);

label_8005BE18:
    ctx->pc = 0x8005BE18u;
    // 8005BE18: li      r3, 55
    ctx->gpr[3] = (u32)(s32)(55);

label_8005BE1C:
    ctx->pc = 0x8005BE1Cu;
    // 8005BE1C: bl      0x8005BBE0
    {
            ctx->lr = 0x8005BE20u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BBE0u;
                return;
            }
            goto label_8005BBE0;
    }

label_8005BE20:
    ctx->pc = 0x8005BE20u;
    ctx->downcount -= 16;
    // 8005BE20: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BE24:
    ctx->pc = 0x8005BE24u;
    // 8005BE24: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005BE28:
    ctx->pc = 0x8005BE28u;
    // 8005BE28: lmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005BE2C:
    ctx->pc = 0x8005BE2Cu;
    // 8005BE2C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8005BE30:
    ctx->pc = 0x8005BE30u;
    // 8005BE30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BE34:
    ctx->pc = 0x8005BE34u;
    ctx->downcount -= 20;
    // 8005BE34: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005BE38:
    ctx->pc = 0x8005BE38u;
    // 8005BE38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005BE3C:
    ctx->pc = 0x8005BE3Cu;
    // 8005BE3C: stmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005BE40:
    ctx->pc = 0x8005BE40u;
    // 8005BE40: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BE44:
    ctx->pc = 0x8005BE44u;
    // 8005BE44: lis     r30, -32698
    ctx->gpr[30] = ((u32)(s32)(-32698) << 16);

label_8005BE48:
    ctx->pc = 0x8005BE48u;
    // 8005BE48: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005BE4C:
    ctx->pc = 0x8005BE4Cu;
    // 8005BE4C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005BE50:
    ctx->pc = 0x8005BE50u;
    // 8005BE50: or   r28, r5, r5
    {
        ctx->gpr[28] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8005BE54:
    ctx->pc = 0x8005BE54u;
    // 8005BE54: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BE58:
    ctx->pc = 0x8005BE58u;
    // 8005BE58: bl      0x80034A2C
    {
            ctx->lr = 0x8005BE5Cu;
            ctx->pc = 0x80034A2Cu;
            return;
    }

label_8005BE5C:
    ctx->pc = 0x8005BE5Cu;
    ctx->downcount -= 5;
    // 8005BE5C: lwz     r4, -27488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27488);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005BE60:
    ctx->pc = 0x8005BE60u;
    // 8005BE60: lis     r5, -16384
    ctx->gpr[5] = ((u32)(s32)(-16384) << 16);

label_8005BE64:
    ctx->pc = 0x8005BE64u;
    // 8005BE64: ori     r5, r5, 0x0005
    ctx->gpr[5] = ctx->gpr[5] | 0x0005u;

label_8005BE68:
    ctx->pc = 0x8005BE68u;
    // 8005BE68: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BE6C:
    ctx->pc = 0x8005BE6Cu;
    // 8005BE6C: bl      0x80034BB0
    {
            ctx->lr = 0x8005BE70u;
            ctx->pc = 0x80034BB0u;
            return;
    }

label_8005BE70:
    ctx->pc = 0x8005BE70u;
    ctx->downcount -= 3;
    // 8005BE70: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BE74:
    ctx->pc = 0x8005BE74u;
    // 8005BE74: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005BE78:
    ctx->pc = 0x8005BE78u;
    // 8005BE78: bl      0x80035C48
    {
            ctx->lr = 0x8005BE7Cu;
            ctx->pc = 0x80035C48u;
            return;
    }

label_8005BE7C:
    ctx->pc = 0x8005BE7Cu;
    ctx->downcount -= 4;
    // 8005BE7C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8005BE80:
    ctx->pc = 0x8005BE80u;
    // 8005BE80: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BE84:
    ctx->pc = 0x8005BE84u;
    // 8005BE84: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8005BE88:
    ctx->pc = 0x8005BE88u;
    // 8005BE88: bl      0x80035C50
    {
            ctx->lr = 0x8005BE8Cu;
            ctx->pc = 0x80035C50u;
            return;
    }

label_8005BE8C:
    ctx->pc = 0x8005BE8Cu;
    ctx->downcount -= 3;
    // 8005BE8C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BE90:
    ctx->pc = 0x8005BE90u;
    // 8005BE90: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005BE94:
    ctx->pc = 0x8005BE94u;
    // 8005BE94: bl      0x80035C40
    {
            ctx->lr = 0x8005BE98u;
            ctx->pc = 0x80035C40u;
            return;
    }

label_8005BE98:
    ctx->pc = 0x8005BE98u;
    ctx->downcount -= 4;
    // 8005BE98: lis     r4, -56
    ctx->gpr[4] = ((u32)(s32)(-56) << 16);

label_8005BE9C:
    ctx->pc = 0x8005BE9Cu;
    // 8005BE9C: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BEA0:
    ctx->pc = 0x8005BEA0u;
    // 8005BEA0: ori     r4, r4, 0xC800
    ctx->gpr[4] = ctx->gpr[4] | 0xC800u;

label_8005BEA4:
    ctx->pc = 0x8005BEA4u;
    // 8005BEA4: bl      0x80034BA8
    {
            ctx->lr = 0x8005BEA8u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005BEA8:
    ctx->pc = 0x8005BEA8u;
    ctx->downcount -= 6;
    // 8005BEA8: addi    r3, r30, 11668
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(11668);

label_8005BEAC:
    ctx->pc = 0x8005BEACu;
    // 8005BEAC: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8005BEB0:
    ctx->pc = 0x8005BEB0u;
    // 8005BEB0: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005BEB4:
    ctx->pc = 0x8005BEB4u;
    // 8005BEB4: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005BEB8:
    ctx->pc = 0x8005BEB8u;
    // 8005BEB8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005BEBC:
    ctx->pc = 0x8005BEBCu;
    // 8005BEBC: bl      0x800350B4
    {
            ctx->lr = 0x8005BEC0u;
            ctx->pc = 0x800350B4u;
            return;
    }

label_8005BEC0:
    ctx->pc = 0x8005BEC0u;
    ctx->downcount -= 16;
    // 8005BEC0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BEC4:
    ctx->pc = 0x8005BEC4u;
    // 8005BEC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005BEC8:
    ctx->pc = 0x8005BEC8u;
    // 8005BEC8: lmw     r27, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005BECC:
    ctx->pc = 0x8005BECCu;
    // 8005BECC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8005BED0:
    ctx->pc = 0x8005BED0u;
    // 8005BED0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BED4:
    ctx->pc = 0x8005BED4u;
    ctx->downcount -= 1;
    // 8005BED4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005BED8:
    ctx->pc = 0x8005BED8u;
    ctx->downcount -= 18;
    // 8005BED8: stwu     r1, -56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-56);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005BEDC:
    ctx->pc = 0x8005BEDCu;
    // 8005BEDC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005BEE0:
    ctx->pc = 0x8005BEE0u;
    // 8005BEE0: stfd     f31, 48(r1)
    if (!ppc_fp_available(ctx, 0x8005BEE0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8005BEE4:
    ctx->pc = 0x8005BEE4u;
    // 8005BEE4: stmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005BEE8:
    ctx->pc = 0x8005BEE8u;
    // 8005BEE8: stw     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BEEC:
    ctx->pc = 0x8005BEECu;
    // 8005BEEC: lwz     r0, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005BEF0:
    ctx->pc = 0x8005BEF0u;
    // 8005BEF0: cmpwi   r0, 5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BEF4:
    ctx->pc = 0x8005BEF4u;
    // 8005BEF4: bc    12, 1, 0x8005BF18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BF18;
        }
    }

label_8005BEF8:
    ctx->pc = 0x8005BEF8u;
    ctx->downcount -= 2;
    // 8005BEF8: cmpwi   r0, 4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BEFC:
    ctx->pc = 0x8005BEFCu;
    // 8005BEFC: bc    4, 0, 0x8005C118
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005C118;
        }
    }

label_8005BF00:
    ctx->pc = 0x8005BF00u;
    ctx->downcount -= 2;
    // 8005BF00: cmpwi   r0, 2
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

label_8005BF04:
    ctx->pc = 0x8005BF04u;
    // 8005BF04: bc    12, 2, 0x8005BF2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005BF2C;
        }
    }

label_8005BF08:
    ctx->pc = 0x8005BF08u;
    ctx->downcount -= 1;
    // 8005BF08: bc    12, 1, 0x8005C0F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C0F4;
        }
    }

label_8005BF0C:
    ctx->pc = 0x8005BF0Cu;
    ctx->downcount -= 2;
    // 8005BF0C: cmpwi   r0, 0
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

label_8005BF10:
    ctx->pc = 0x8005BF10u;
    // 8005BF10: bc    12, 0, 0x8005C4C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C4C8;
        }
    }

label_8005BF14:
    ctx->pc = 0x8005BF14u;
    ctx->downcount -= 1;
    // 8005BF14: b       0x8005C0F4
    {
            goto label_8005C0F4;
    }

label_8005BF18:
    ctx->pc = 0x8005BF18u;
    ctx->downcount -= 2;
    // 8005BF18: cmpwi   r0, 7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BF1C:
    ctx->pc = 0x8005BF1Cu;
    // 8005BF1C: bc    4, 1, 0x8005C0F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005C0F4;
        }
    }

label_8005BF20:
    ctx->pc = 0x8005BF20u;
    ctx->downcount -= 2;
    // 8005BF20: cmpwi   r0, 8
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(8);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005BF24:
    ctx->pc = 0x8005BF24u;
    // 8005BF24: bc    12, 2, 0x8005C4C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C4C0;
        }
    }

label_8005BF28:
    ctx->pc = 0x8005BF28u;
    ctx->downcount -= 1;
    // 8005BF28: b       0x8005C4C8
    {
            goto label_8005C4C8;
    }

label_8005BF2C:
    ctx->pc = 0x8005BF2Cu;
    ctx->downcount -= 1;
    // 8005BF2C: bl      0x80037DDC
    {
            ctx->lr = 0x8005BF30u;
            ctx->pc = 0x80037DDCu;
            return;
    }

label_8005BF30:
    ctx->pc = 0x8005BF30u;
    ctx->downcount -= 33;
    // 8005BF30: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_8005BF34:
    ctx->pc = 0x8005BF34u;
    // 8005BF34: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BF38:
    ctx->pc = 0x8005BF38u;
    // 8005BF38: lis     r4, 17200
    ctx->gpr[4] = ((u32)(s32)(17200) << 16);

label_8005BF3C:
    ctx->pc = 0x8005BF3Cu;
    // 8005BF3C: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005BF40:
    ctx->pc = 0x8005BF40u;
    // 8005BF40: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005BF44:
    ctx->pc = 0x8005BF44u;
    // 8005BF44: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005BF48:
    ctx->pc = 0x8005BF48u;
    // 8005BF48: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005BF4C:
    ctx->pc = 0x8005BF4Cu;
    // 8005BF4C: li      r5, 32
    ctx->gpr[5] = (u32)(s32)(32);

label_8005BF50:
    ctx->pc = 0x8005BF50u;
    // 8005BF50: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_8005BF54:
    ctx->pc = 0x8005BF54u;
    // 8005BF54: lfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005BF54u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BF58:
    ctx->pc = 0x8005BF58u;
    // 8005BF58: lis     r7, -32738
    ctx->gpr[7] = ((u32)(s32)(-32738) << 16);

label_8005BF5C:
    ctx->pc = 0x8005BF5Cu;
    // 8005BF5C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BF60:
    ctx->pc = 0x8005BF60u;
    // 8005BF60: lis     r6, -32702
    ctx->gpr[6] = ((u32)(s32)(-32702) << 16);

label_8005BF64:
    ctx->pc = 0x8005BF64u;
    // 8005BF64: lfd     f12, 21584(r8)
    if (!ppc_fp_available(ctx, 0x8005BF64u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(21584);
        ctx->fpr[12] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BF68:
    ctx->pc = 0x8005BF68u;
    // 8005BF68: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8005BF6C:
    ctx->pc = 0x8005BF6Cu;
    // 8005BF6C: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005BF70:
    ctx->pc = 0x8005BF70u;
    // 8005BF70: addi    r31, r6, 30624
    ctx->gpr[31] = ctx->gpr[6] + (u32)(s32)(30624);

label_8005BF74:
    ctx->pc = 0x8005BF74u;
    // 8005BF74: lfs     f8, -27904(r13)
    if (!ppc_fp_available(ctx, 0x8005BF74u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27904);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_8005BF78:
    ctx->pc = 0x8005BF78u;
    // 8005BF78: fsub   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x8005BF78u)) return;
    ppc_fsub(ctx, 13, 13, 12);

label_8005BF7C:
    ctx->pc = 0x8005BF7Cu;
    // 8005BF7C: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005BF7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BF80:
    ctx->pc = 0x8005BF80u;
    // 8005BF80: frsp    f7, f13
    if (!ppc_fp_available(ctx, 0x8005BF80u)) return;
    ppc_frsp(ctx, 7, 13);

label_8005BF84:
    ctx->pc = 0x8005BF84u;
    // 8005BF84: stw     r5, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8005BF88:
    ctx->pc = 0x8005BF88u;
    // 8005BF88: fsub   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x8005BF88u)) return;
    ppc_fsub(ctx, 0, 0, 12);

label_8005BF8C:
    ctx->pc = 0x8005BF8Cu;
    // 8005BF8C: lfs     f11, 21592(r7)
    if (!ppc_fp_available(ctx, 0x8005BF8Cu)) return;
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(21592);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005BF90:
    ctx->pc = 0x8005BF90u;
    // 8005BF90: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005BF94:
    ctx->pc = 0x8005BF94u;
    // 8005BF94: frsp    f9, f0
    if (!ppc_fp_available(ctx, 0x8005BF94u)) return;
    ppc_frsp(ctx, 9, 0);

label_8005BF98:
    ctx->pc = 0x8005BF98u;
    // 8005BF98: fcmpu   cr0, f8, f11
    if (!ppc_fp_available(ctx, 0x8005BF98u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[8], ctx->fpr[11], false);

label_8005BF9C:
    ctx->pc = 0x8005BF9Cu;
    // 8005BF9C: stw     r9, 30624(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(30624);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005BFA0:
    ctx->pc = 0x8005BFA0u;
    // 8005BFA0: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005BFA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BFA4:
    ctx->pc = 0x8005BFA4u;
    // 8005BFA4: fmr    f5, f9
    if (!ppc_fp_available(ctx, 0x8005BFA4u)) return;
    ctx->fpr[5] = ctx->fpr[9];

label_8005BFA8:
    ctx->pc = 0x8005BFA8u;
    // 8005BFA8: fsub   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x8005BFA8u)) return;
    ppc_fsub(ctx, 0, 0, 12);

label_8005BFAC:
    ctx->pc = 0x8005BFACu;
    // 8005BFAC: frsp    f6, f0
    if (!ppc_fp_available(ctx, 0x8005BFACu)) return;
    ppc_frsp(ctx, 6, 0);

label_8005BFB0:
    ctx->pc = 0x8005BFB0u;
    // 8005BFB0: bc    4, 1, 0x8005C058
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005C058;
        }
    }

label_8005BFB4:
    ctx->pc = 0x8005BFB4u;
    ctx->downcount -= 41;
    // 8005BFB4: lbz     r0, -27900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27900);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8005BFB8:
    ctx->pc = 0x8005BFB8u;
    // 8005BFB8: lbz     r11, -27899(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27899);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_8005BFBC:
    ctx->pc = 0x8005BFBCu;
    // 8005BFBC: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005BFC0:
    ctx->pc = 0x8005BFC0u;
    // 8005BFC0: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005BFC4:
    ctx->pc = 0x8005BFC4u;
    // 8005BFC4: lbz     r8, -27898(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27898);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_8005BFC8:
    ctx->pc = 0x8005BFC8u;
    // 8005BFC8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005BFCC:
    ctx->pc = 0x8005BFCCu;
    // 8005BFCC: xoris   r11, r11, 0x8000
    ctx->gpr[11] = ctx->gpr[11] ^ (0x8000u << 16);

label_8005BFD0:
    ctx->pc = 0x8005BFD0u;
    // 8005BFD0: or   r7, r9, r9
    {
        ctx->gpr[7] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005BFD4:
    ctx->pc = 0x8005BFD4u;
    // 8005BFD4: xoris   r8, r8, 0x8000
    ctx->gpr[8] = ctx->gpr[8] ^ (0x8000u << 16);

label_8005BFD8:
    ctx->pc = 0x8005BFD8u;
    // 8005BFD8: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005BFDC:
    ctx->pc = 0x8005BFDCu;
    // 8005BFDC: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005BFE0:
    ctx->pc = 0x8005BFE0u;
    // 8005BFE0: lbz     r0, -27897(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27897);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8005BFE4:
    ctx->pc = 0x8005BFE4u;
    // 8005BFE4: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005BFE8:
    ctx->pc = 0x8005BFE8u;
    // 8005BFE8: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005BFE8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BFEC:
    ctx->pc = 0x8005BFECu;
    // 8005BFEC: stw     r11, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005BFF0:
    ctx->pc = 0x8005BFF0u;
    // 8005BFF0: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005BFF4:
    ctx->pc = 0x8005BFF4u;
    // 8005BFF4: lfd     f11, 21600(r5)
    if (!ppc_fp_available(ctx, 0x8005BFF4u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(21600);
        ctx->fpr[11] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005BFF8:
    ctx->pc = 0x8005BFF8u;
    // 8005BFF8: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005BFFC:
    ctx->pc = 0x8005BFFCu;
    // 8005BFFC: fsub   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005BFFCu)) return;
    ppc_fsub(ctx, 0, 0, 11);

label_8005C000:
    ctx->pc = 0x8005C000u;
    // 8005C000: lfd     f12, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C000u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[12] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C004:
    ctx->pc = 0x8005C004u;
    // 8005C004: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005C004u)) return;
    ppc_frsp(ctx, 0, 0);

label_8005C008:
    ctx->pc = 0x8005C008u;
    // 8005C008: stw     r8, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005C00C:
    ctx->pc = 0x8005C00Cu;
    // 8005C00C: fsubs   f10, f0, f7
    if (!ppc_fp_available(ctx, 0x8005C00Cu)) return;
    ppc_fsubs(ctx, 10, 0, 7);

label_8005C010:
    ctx->pc = 0x8005C010u;
    // 8005C010: fsub   f12, f12, f11
    if (!ppc_fp_available(ctx, 0x8005C010u)) return;
    ppc_fsub(ctx, 12, 12, 11);

label_8005C014:
    ctx->pc = 0x8005C014u;
    // 8005C014: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C018:
    ctx->pc = 0x8005C018u;
    // 8005C018: fmadds f7, f10, f8, f7
    if (!ppc_fp_available(ctx, 0x8005C018u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[7], true, false, false, &result))
            ctx->fpr[7] = ctx->ps1[7] = result;
    }

label_8005C01C:
    ctx->pc = 0x8005C01Cu;
    // 8005C01C: frsp    f12, f12
    if (!ppc_fp_available(ctx, 0x8005C01Cu)) return;
    ppc_frsp(ctx, 12, 12);

label_8005C020:
    ctx->pc = 0x8005C020u;
    // 8005C020: lfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C020u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C024:
    ctx->pc = 0x8005C024u;
    // 8005C024: fsubs   f10, f12, f9
    if (!ppc_fp_available(ctx, 0x8005C024u)) return;
    ppc_fsubs(ctx, 10, 12, 9);

label_8005C028:
    ctx->pc = 0x8005C028u;
    // 8005C028: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C02C:
    ctx->pc = 0x8005C02Cu;
    // 8005C02C: fmadds f5, f10, f8, f9
    if (!ppc_fp_available(ctx, 0x8005C02Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[9], true, false, false, &result))
            ctx->fpr[5] = ctx->ps1[5] = result;
    }

label_8005C030:
    ctx->pc = 0x8005C030u;
    // 8005C030: fsub   f13, f13, f11
    if (!ppc_fp_available(ctx, 0x8005C030u)) return;
    ppc_fsub(ctx, 13, 13, 11);

label_8005C034:
    ctx->pc = 0x8005C034u;
    // 8005C034: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C038:
    ctx->pc = 0x8005C038u;
    // 8005C038: frsp    f13, f13
    if (!ppc_fp_available(ctx, 0x8005C038u)) return;
    ppc_frsp(ctx, 13, 13);

label_8005C03C:
    ctx->pc = 0x8005C03Cu;
    // 8005C03C: fsubs   f10, f13, f9
    if (!ppc_fp_available(ctx, 0x8005C03Cu)) return;
    ppc_fsubs(ctx, 10, 13, 9);

label_8005C040:
    ctx->pc = 0x8005C040u;
    // 8005C040: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C040u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C044:
    ctx->pc = 0x8005C044u;
    // 8005C044: fmadds f9, f10, f8, f9
    if (!ppc_fp_available(ctx, 0x8005C044u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[9], true, false, false, &result))
            ctx->fpr[9] = ctx->ps1[9] = result;
    }

label_8005C048:
    ctx->pc = 0x8005C048u;
    // 8005C048: fsub   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005C048u)) return;
    ppc_fsub(ctx, 0, 0, 11);

label_8005C04C:
    ctx->pc = 0x8005C04Cu;
    // 8005C04C: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005C04Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_8005C050:
    ctx->pc = 0x8005C050u;
    // 8005C050: fsubs   f10, f0, f6
    if (!ppc_fp_available(ctx, 0x8005C050u)) return;
    ppc_fsubs(ctx, 10, 0, 6);

label_8005C054:
    ctx->pc = 0x8005C054u;
    // 8005C054: fmadds f6, f10, f8, f6
    if (!ppc_fp_available(ctx, 0x8005C054u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[6], true, false, false, &result))
            ctx->fpr[6] = ctx->ps1[6] = result;
    }

label_8005C058:
    ctx->pc = 0x8005C058u;
    ctx->downcount -= 28;
    // 8005C058: fmr    f0, f7
    if (!ppc_fp_available(ctx, 0x8005C058u)) return;
    ctx->fpr[0] = ctx->fpr[7];

label_8005C05C:
    ctx->pc = 0x8005C05Cu;
    // 8005C05C: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8005C05Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_8005C060:
    ctx->pc = 0x8005C060u;
    // 8005C060: or   r8, r9, r9
    {
        ctx->gpr[8] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005C064:
    ctx->pc = 0x8005C064u;
    // 8005C064: stfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C064u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_8005C068:
    ctx->pc = 0x8005C068u;
    // 8005C068: fmr    f12, f5
    if (!ppc_fp_available(ctx, 0x8005C068u)) return;
    ctx->fpr[12] = ctx->fpr[5];

label_8005C06C:
    ctx->pc = 0x8005C06Cu;
    // 8005C06C: fctiwz    f0, f12
    if (!ppc_fp_available(ctx, 0x8005C06Cu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[12], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8005C070:
    ctx->pc = 0x8005C070u;
    // 8005C070: lwz     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005C074:
    ctx->pc = 0x8005C074u;
    // 8005C074: fmr    f13, f9
    if (!ppc_fp_available(ctx, 0x8005C074u)) return;
    ctx->fpr[13] = ctx->fpr[9];

label_8005C078:
    ctx->pc = 0x8005C078u;
    // 8005C078: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C078u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8005C07C:
    ctx->pc = 0x8005C07Cu;
    // 8005C07C: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8005C080:
    ctx->pc = 0x8005C080u;
    // 8005C080: fctiwz    f0, f13
    if (!ppc_fp_available(ctx, 0x8005C080u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8005C084:
    ctx->pc = 0x8005C084u;
    // 8005C084: rlwinm r9, r9, 24, 0, 7
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 24u) & 0xFF000000u;
    }

label_8005C088:
    ctx->pc = 0x8005C088u;
    // 8005C088: lwz     r8, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005C08C:
    ctx->pc = 0x8005C08Cu;
    // 8005C08C: fmr    f13, f6
    if (!ppc_fp_available(ctx, 0x8005C08Cu)) return;
    ctx->fpr[13] = ctx->fpr[6];

label_8005C090:
    ctx->pc = 0x8005C090u;
    // 8005C090: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C090u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8005C094:
    ctx->pc = 0x8005C094u;
    // 8005C094: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005C098:
    ctx->pc = 0x8005C098u;
    // 8005C098: fctiwz    f0, f13
    if (!ppc_fp_available(ctx, 0x8005C098u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8005C09C:
    ctx->pc = 0x8005C09Cu;
    // 8005C09C: rlwinm r8, r8, 16, 8, 15
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 16u) & 0x00FF0000u;
    }

label_8005C0A0:
    ctx->pc = 0x8005C0A0u;
    // 8005C0A0: lwz     r10, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005C0A4:
    ctx->pc = 0x8005C0A4u;
    // 8005C0A4: or   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[8];
    }

label_8005C0A8:
    ctx->pc = 0x8005C0A8u;
    // 8005C0A8: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C0A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8005C0AC:
    ctx->pc = 0x8005C0ACu;
    // 8005C0AC: rlwinm r10, r10, 8, 16, 23
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 8u) & 0x0000FF00u;
    }

label_8005C0B0:
    ctx->pc = 0x8005C0B0u;
    // 8005C0B0: lwz     r11, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005C0B4:
    ctx->pc = 0x8005C0B4u;
    // 8005C0B4: or   r9, r9, r10
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[10];
    }

label_8005C0B8:
    ctx->pc = 0x8005C0B8u;
    // 8005C0B8: rlwinm r11, r11, 0, 24, 31
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x000000FFu;
    }

label_8005C0BC:
    ctx->pc = 0x8005C0BCu;
    // 8005C0BC: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_8005C0C0:
    ctx->pc = 0x8005C0C0u;
    // 8005C0C0: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C0C4:
    ctx->pc = 0x8005C0C4u;
    // 8005C0C4: bl      0x80050528
    {
            ctx->lr = 0x8005C0C8u;
            ctx->pc = 0x80050528u;
            return;
    }

label_8005C0C8:
    ctx->pc = 0x8005C0C8u;
    ctx->downcount -= 3;
    // 8005C0C8: lis     r3, -32701
    ctx->gpr[3] = ((u32)(s32)(-32701) << 16);

label_8005C0CC:
    ctx->pc = 0x8005C0CCu;
    // 8005C0CC: addi    r3, r3, -29512
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-29512);

label_8005C0D0:
    ctx->pc = 0x8005C0D0u;
    // 8005C0D0: bl      0x80033E74
    {
            ctx->lr = 0x8005C0D4u;
            ctx->pc = 0x80033E74u;
            return;
    }

label_8005C0D4:
    ctx->pc = 0x8005C0D4u;
    ctx->downcount -= 2;
    // 8005C0D4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005C0D8:
    ctx->pc = 0x8005C0D8u;
    // 8005C0D8: bl      0x8005BED4
    {
            ctx->lr = 0x8005C0DCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BED4u;
                return;
            }
            goto label_8005BED4;
    }

label_8005C0DC:
    ctx->pc = 0x8005C0DCu;
    ctx->downcount -= 1;
    // 8005C0DC: bl      0x80032C88
    {
            ctx->lr = 0x8005C0E0u;
            ctx->pc = 0x80032C88u;
            return;
    }

label_8005C0E0:
    ctx->pc = 0x8005C0E0u;
    ctx->downcount -= 2;
    // 8005C0E0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005C0E4:
    ctx->pc = 0x8005C0E4u;
    // 8005C0E4: bl      0x8005BC7C
    {
            ctx->lr = 0x8005C0E8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005BC7Cu;
                return;
            }
            goto label_8005BC7C;
    }

label_8005C0E8:
    ctx->pc = 0x8005C0E8u;
    ctx->downcount -= 2;
    // 8005C0E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005C0EC:
    ctx->pc = 0x8005C0ECu;
    // 8005C0EC: bl      0x80050698
    {
            ctx->lr = 0x8005C0F0u;
            ctx->pc = 0x80050698u;
            return;
    }

label_8005C0F0:
    ctx->pc = 0x8005C0F0u;
    ctx->downcount -= 1;
    // 8005C0F0: b       0x8005C4DC
    {
            goto label_8005C4DC;
    }

label_8005C0F4:
    ctx->pc = 0x8005C0F4u;
    ctx->downcount -= 6;
    // 8005C0F4: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_8005C0F8:
    ctx->pc = 0x8005C0F8u;
    // 8005C0F8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C0FC:
    ctx->pc = 0x8005C0FCu;
    // 8005C0FC: addi    r30, r9, 30624
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(30624);

label_8005C100:
    ctx->pc = 0x8005C100u;
    // 8005C100: stw     r0, 30624(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C104:
    ctx->pc = 0x8005C104u;
    // 8005C104: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005C108:
    ctx->pc = 0x8005C108u;
    // 8005C108: bl      0x80050528
    {
            ctx->lr = 0x8005C10Cu;
            ctx->pc = 0x80050528u;
            return;
    }

label_8005C10C:
    ctx->pc = 0x8005C10Cu;
    ctx->downcount -= 2;
    // 8005C10C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005C110:
    ctx->pc = 0x8005C110u;
    // 8005C110: bl      0x80050698
    {
            ctx->lr = 0x8005C114u;
            ctx->pc = 0x80050698u;
            return;
    }

label_8005C114:
    ctx->pc = 0x8005C114u;
    ctx->downcount -= 1;
    // 8005C114: b       0x8005C4DC
    {
            goto label_8005C4DC;
    }

label_8005C118:
    ctx->pc = 0x8005C118u;
    ctx->downcount -= 9;
    // 8005C118: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005C11C:
    ctx->pc = 0x8005C11Cu;
    // 8005C11C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005C120:
    ctx->pc = 0x8005C120u;
    // 8005C120: lfs     f0, 21608(r9)
    if (!ppc_fp_available(ctx, 0x8005C120u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21608);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005C124:
    ctx->pc = 0x8005C124u;
    // 8005C124: lis     r28, -32738
    ctx->gpr[28] = ((u32)(s32)(-32738) << 16);

label_8005C128:
    ctx->pc = 0x8005C128u;
    // 8005C128: stw     r0, -31840(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31840);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C12C:
    ctx->pc = 0x8005C12Cu;
    // 8005C12C: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005C130:
    ctx->pc = 0x8005C130u;
    // 8005C130: stfs     f0, -31828(r13)
    if (!ppc_fp_available(ctx, 0x8005C130u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31828);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C134:
    ctx->pc = 0x8005C134u;
    // 8005C134: addi    r3, r28, 21564
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(21564);

label_8005C138:
    ctx->pc = 0x8005C138u;
    // 8005C138: bl      0x80046418
    {
            ctx->lr = 0x8005C13Cu;
            ctx->pc = 0x80046418u;
            return;
    }

label_8005C13C:
    ctx->pc = 0x8005C13Cu;
    ctx->downcount -= 4;
    // 8005C13C: lis     r30, -32700
    ctx->gpr[30] = ((u32)(s32)(-32700) << 16);

label_8005C140:
    ctx->pc = 0x8005C140u;
    // 8005C140: addi    r3, r30, -22100
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-22100);

label_8005C144:
    ctx->pc = 0x8005C144u;
    // 8005C144: lis     r29, -32699
    ctx->gpr[29] = ((u32)(s32)(-32699) << 16);

label_8005C148:
    ctx->pc = 0x8005C148u;
    // 8005C148: bl      0x8003D2AC
    {
            ctx->lr = 0x8005C14Cu;
            ctx->pc = 0x8003D2ACu;
            return;
    }

label_8005C14C:
    ctx->pc = 0x8005C14Cu;
    ctx->downcount -= 2;
    // 8005C14C: addi    r3, r30, -22100
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(-22100);

label_8005C150:
    ctx->pc = 0x8005C150u;
    // 8005C150: bl      0x8003D400
    {
            ctx->lr = 0x8005C154u;
            ctx->pc = 0x8003D400u;
            return;
    }

label_8005C154:
    ctx->pc = 0x8005C154u;
    ctx->downcount -= 10;
    // 8005C154: lwz     r9, -21636(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-21636);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005C158:
    ctx->pc = 0x8005C158u;
    // 8005C158: lis     r11, -32735
    ctx->gpr[11] = ((u32)(s32)(-32735) << 16);

label_8005C15C:
    ctx->pc = 0x8005C15Cu;
    // 8005C15C: addi    r31, r11, -2804
    ctx->gpr[31] = ctx->gpr[11] + (u32)(s32)(-2804);

label_8005C160:
    ctx->pc = 0x8005C160u;
    // 8005C160: mulli   r9, r9, 24
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)24);

label_8005C164:
    ctx->pc = 0x8005C164u;
    // 8005C164: add   r9, r9, r31
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005C168:
    ctx->pc = 0x8005C168u;
    // 8005C168: lwz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C16C:
    ctx->pc = 0x8005C16Cu;
    // 8005C16C: cmpwi   r0, 0
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

label_8005C170:
    ctx->pc = 0x8005C170u;
    // 8005C170: bc    12, 2, 0x8005C184
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C184;
        }
    }

label_8005C174:
    ctx->pc = 0x8005C174u;
    ctx->downcount -= 5;
    // 8005C174: lis     r3, 4096
    ctx->gpr[3] = ((u32)(s32)(4096) << 16);

label_8005C178:
    ctx->pc = 0x8005C178u;
    // 8005C178: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005C17C:
    ctx->pc = 0x8005C17Cu;
    // 8005C17C: ori     r3, r3, 0x0004
    ctx->gpr[3] = ctx->gpr[3] | 0x0004u;

label_8005C180:
    ctx->pc = 0x8005C180u;
    // 8005C180: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x8005C184u;
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C184:
    ctx->pc = 0x8005C184u;
    ctx->downcount -= 2;
    // 8005C184: addi    r3, r28, 21564
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(21564);

label_8005C188:
    ctx->pc = 0x8005C188u;
    // 8005C188: bl      0x800464F8
    {
            ctx->lr = 0x8005C18Cu;
            ctx->pc = 0x800464F8u;
            return;
    }

label_8005C18C:
    ctx->pc = 0x8005C18Cu;
    ctx->downcount -= 3;
    // 8005C18C: lwz     r0, -32100(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32100);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C190:
    ctx->pc = 0x8005C190u;
    // 8005C190: cmpwi   r0, 0
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

label_8005C194:
    ctx->pc = 0x8005C194u;
    // 8005C194: bc    4, 2, 0x8005C1BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005C1BC;
        }
    }

label_8005C198:
    ctx->pc = 0x8005C198u;
    ctx->downcount -= 10;
    // 8005C198: lwz     r0, -21636(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-21636);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C19C:
    ctx->pc = 0x8005C19Cu;
    // 8005C19C: addi    r10, r31, 12
    ctx->gpr[10] = ctx->gpr[31] + (u32)(s32)(12);

label_8005C1A0:
    ctx->pc = 0x8005C1A0u;
    // 8005C1A0: mulli   r0, r0, 24
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)24);

label_8005C1A4:
    ctx->pc = 0x8005C1A4u;
    // 8005C1A4: lwzx    r9, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005C1A8:
    ctx->pc = 0x8005C1A8u;
    // 8005C1A8: lwz     r11, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005C1AC:
    ctx->pc = 0x8005C1ACu;
    // 8005C1AC: xori    r10, r11, 0x0200
    ctx->gpr[10] = ctx->gpr[11] ^ 0x0200u;

label_8005C1B0:
    ctx->pc = 0x8005C1B0u;
    // 8005C1B0: andi.   r0, r10, 0x0200
    {
        ctx->gpr[0] = ctx->gpr[10] & 0x0200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005C1B4:
    ctx->pc = 0x8005C1B4u;
    // 8005C1B4: bc    12, 2, 0x8005C1BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C1BC;
        }
    }

label_8005C1B8:
    ctx->pc = 0x8005C1B8u;
    ctx->downcount -= 1;
    // 8005C1B8: bl      0x800C77B0
    {
            ctx->lr = 0x8005C1BCu;
            ctx->pc = 0x800C77B0u;
            return;
    }

label_8005C1BC:
    ctx->pc = 0x8005C1BCu;
    ctx->downcount -= 1;
    // 8005C1BC: bl      0x80064E04
    {
            ctx->lr = 0x8005C1C0u;
            ctx->pc = 0x80064E04u;
            return;
    }

label_8005C1C0:
    ctx->pc = 0x8005C1C0u;
    ctx->downcount -= 2;
    // 8005C1C0: cmpwi   r3, 0
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

label_8005C1C4:
    ctx->pc = 0x8005C1C4u;
    // 8005C1C4: bc    4, 2, 0x8005C1CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005C1CC;
        }
    }

label_8005C1C8:
    ctx->pc = 0x8005C1C8u;
    ctx->downcount -= 1;
    // 8005C1C8: bl      0x80094D0C
    {
            ctx->lr = 0x8005C1CCu;
            ctx->pc = 0x80094D0Cu;
            return;
    }

label_8005C1CC:
    ctx->pc = 0x8005C1CCu;
    ctx->downcount -= 1;
    // 8005C1CC: bl      0x800461E4
    {
            ctx->lr = 0x8005C1D0u;
            ctx->pc = 0x800461E4u;
            return;
    }

label_8005C1D0:
    ctx->pc = 0x8005C1D0u;
    ctx->downcount -= 1;
    // 8005C1D0: bl      0x80065F50
    {
            ctx->lr = 0x8005C1D4u;
            ctx->pc = 0x80065F50u;
            return;
    }

label_8005C1D4:
    ctx->pc = 0x8005C1D4u;
    ctx->downcount -= 2;
    // 8005C1D4: cmpwi   r3, 0
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

label_8005C1D8:
    ctx->pc = 0x8005C1D8u;
    // 8005C1D8: bc    4, 2, 0x8005C22C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005C22C;
        }
    }

label_8005C1DC:
    ctx->pc = 0x8005C1DCu;
    ctx->downcount -= 4;
    // 8005C1DC: lwz     r9, -31844(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31844);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005C1E0:
    ctx->pc = 0x8005C1E0u;
    // 8005C1E0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_8005C1E4:
    ctx->pc = 0x8005C1E4u;
    // 8005C1E4: stw     r9, -31844(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31844);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C1E8:
    ctx->pc = 0x8005C1E8u;
    // 8005C1E8: bl      0x8004C4AC
    {
            ctx->lr = 0x8005C1ECu;
            ctx->pc = 0x8004C4ACu;
            return;
    }

label_8005C1EC:
    ctx->pc = 0x8005C1ECu;
    ctx->downcount -= 1;
    // 8005C1EC: bl      0x80037DDC
    {
            ctx->lr = 0x8005C1F0u;
            ctx->pc = 0x80037DDCu;
            return;
    }

label_8005C1F0:
    ctx->pc = 0x8005C1F0u;
    ctx->downcount -= 6;
    // 8005C1F0: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_8005C1F4:
    ctx->pc = 0x8005C1F4u;
    // 8005C1F4: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C1F8:
    ctx->pc = 0x8005C1F8u;
    // 8005C1F8: addi    r30, r9, 30624
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(30624);

label_8005C1FC:
    ctx->pc = 0x8005C1FCu;
    // 8005C1FC: stw     r0, 30624(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C200:
    ctx->pc = 0x8005C200u;
    // 8005C200: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005C204:
    ctx->pc = 0x8005C204u;
    // 8005C204: bl      0x80050528
    {
            ctx->lr = 0x8005C208u;
            ctx->pc = 0x80050528u;
            return;
    }

label_8005C208:
    ctx->pc = 0x8005C208u;
    ctx->downcount -= 3;
    // 8005C208: lis     r3, -32700
    ctx->gpr[3] = ((u32)(s32)(-32700) << 16);

label_8005C20C:
    ctx->pc = 0x8005C20Cu;
    // 8005C20C: addi    r3, r3, -22100
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-22100);

label_8005C210:
    ctx->pc = 0x8005C210u;
    // 8005C210: bl      0x8003D0DC
    {
            ctx->lr = 0x8005C214u;
            ctx->pc = 0x8003D0DCu;
            return;
    }

label_8005C214:
    ctx->pc = 0x8005C214u;
    ctx->downcount -= 1;
    // 8005C214: bl      0x8004331C
    {
            ctx->lr = 0x8005C218u;
            ctx->pc = 0x8004331Cu;
            return;
    }

label_8005C218:
    ctx->pc = 0x8005C218u;
    ctx->downcount -= 1;
    // 8005C218: bl      0x8004FBB8
    {
            ctx->lr = 0x8005C21Cu;
            ctx->pc = 0x8004FBB8u;
            return;
    }

label_8005C21C:
    ctx->pc = 0x8005C21Cu;
    ctx->downcount -= 1;
    // 8005C21C: bl      0x80032C84
    {
            ctx->lr = 0x8005C220u;
            ctx->pc = 0x80032C84u;
            return;
    }

label_8005C220:
    ctx->pc = 0x8005C220u;
    ctx->downcount -= 2;
    // 8005C220: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005C224:
    ctx->pc = 0x8005C224u;
    // 8005C224: bl      0x80050698
    {
            ctx->lr = 0x8005C228u;
            ctx->pc = 0x80050698u;
            return;
    }

label_8005C228:
    ctx->pc = 0x8005C228u;
    ctx->downcount -= 1;
    // 8005C228: b       0x8005C4C0
    {
            goto label_8005C4C0;
    }

label_8005C22C:
    ctx->pc = 0x8005C22Cu;
    ctx->downcount -= 10;
    // 8005C22C: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_8005C230:
    ctx->pc = 0x8005C230u;
    // 8005C230: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005C234:
    ctx->pc = 0x8005C234u;
    // 8005C234: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005C238:
    ctx->pc = 0x8005C238u;
    // 8005C238: addi    r29, r11, 11948
    ctx->gpr[29] = ctx->gpr[11] + (u32)(s32)(11948);

label_8005C23C:
    ctx->pc = 0x8005C23Cu;
    // 8005C23C: lfs     f2, 21616(r9)
    if (!ppc_fp_available(ctx, 0x8005C23Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21616);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8005C240:
    ctx->pc = 0x8005C240u;
    // 8005C240: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005C244:
    ctx->pc = 0x8005C244u;
    // 8005C244: lfs     f1, 21612(r10)
    if (!ppc_fp_available(ctx, 0x8005C244u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(21612);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005C248:
    ctx->pc = 0x8005C248u;
    // 8005C248: addi    r31, r29, 24
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(24);

label_8005C24C:
    ctx->pc = 0x8005C24Cu;
    // 8005C24C: addi    r28, r29, 28
    ctx->gpr[28] = ctx->gpr[29] + (u32)(s32)(28);

label_8005C250:
    ctx->pc = 0x8005C250u;
    // 8005C250: bl      0x801D804C
    {
            ctx->lr = 0x8005C254u;
            ctx->pc = 0x801D804Cu;
            return;
    }

label_8005C254:
    ctx->pc = 0x8005C254u;
    ctx->downcount -= 4;
    // 8005C254: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005C258:
    ctx->pc = 0x8005C258u;
    // 8005C258: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005C25C:
    ctx->pc = 0x8005C25Cu;
    // 8005C25C: lfs     f1, 21620(r9)
    if (!ppc_fp_available(ctx, 0x8005C25Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21620);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005C260:
    ctx->pc = 0x8005C260u;
    // 8005C260: bl      0x80037624
    {
            ctx->lr = 0x8005C264u;
            ctx->pc = 0x80037624u;
            return;
    }

label_8005C264:
    ctx->pc = 0x8005C264u;
    ctx->downcount -= 21;
    // 8005C264: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005C268:
    ctx->pc = 0x8005C268u;
    // 8005C268: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8005C26C:
    ctx->pc = 0x8005C26Cu;
    // 8005C26C: sth     r7, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8005C270:
    ctx->pc = 0x8005C270u;
    // 8005C270: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005C274:
    ctx->pc = 0x8005C274u;
    // 8005C274: stb     r0, 51(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(51);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8005C278:
    ctx->pc = 0x8005C278u;
    // 8005C278: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005C27C:
    ctx->pc = 0x8005C27Cu;
    // 8005C27C: li      r6, 3
    ctx->gpr[6] = (u32)(s32)(3);

label_8005C280:
    ctx->pc = 0x8005C280u;
    // 8005C280: lwz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C284:
    ctx->pc = 0x8005C284u;
    // 8005C284: lfs     f0, 21624(r11)
    if (!ppc_fp_available(ctx, 0x8005C284u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21624);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005C288:
    ctx->pc = 0x8005C288u;
    // 8005C288: lfs     f31, 21608(r9)
    if (!ppc_fp_available(ctx, 0x8005C288u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21608);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8005C28C:
    ctx->pc = 0x8005C28Cu;
    // 8005C28C: rlwinm r0, r0, 0, 17, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF7FFFu;
    }

label_8005C290:
    ctx->pc = 0x8005C290u;
    // 8005C290: lwz     r9, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005C294:
    ctx->pc = 0x8005C294u;
    // 8005C294: stfs     f0, 44(r31)
    if (!ppc_fp_available(ctx, 0x8005C294u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C298:
    ctx->pc = 0x8005C298u;
    // 8005C298: stw     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C29C:
    ctx->pc = 0x8005C29Cu;
    // 8005C29C: cmpw    r6, r9
    {
        s32 val_a = (s32)(ctx->gpr[6]);
        s32 val_b = (s32)(ctx->gpr[9]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005C2A0:
    ctx->pc = 0x8005C2A0u;
    // 8005C2A0: stfs     f31, 28(r29)
    if (!ppc_fp_available(ctx, 0x8005C2A0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8005C2A4:
    ctx->pc = 0x8005C2A4u;
    // 8005C2A4: stfs     f31, 4(r28)
    if (!ppc_fp_available(ctx, 0x8005C2A4u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8005C2A8:
    ctx->pc = 0x8005C2A8u;
    // 8005C2A8: stfs     f31, 8(r28)
    if (!ppc_fp_available(ctx, 0x8005C2A8u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8005C2AC:
    ctx->pc = 0x8005C2ACu;
    // 8005C2AC: stfs     f0, 36(r31)
    if (!ppc_fp_available(ctx, 0x8005C2ACu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C2B0:
    ctx->pc = 0x8005C2B0u;
    // 8005C2B0: stfs     f0, 40(r31)
    if (!ppc_fp_available(ctx, 0x8005C2B0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C2B4:
    ctx->pc = 0x8005C2B4u;
    // 8005C2B4: bc    12, 2, 0x8005C2BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C2BC;
        }
    }

label_8005C2B8:
    ctx->pc = 0x8005C2B8u;
    ctx->downcount -= 1;
    // 8005C2B8: sth     r7, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8005C2BC:
    ctx->pc = 0x8005C2BCu;
    ctx->downcount -= 24;
    // 8005C2BC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005C2C0:
    ctx->pc = 0x8005C2C0u;
    // 8005C2C0: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005C2C4:
    ctx->pc = 0x8005C2C4u;
    // 8005C2C4: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005C2C8:
    ctx->pc = 0x8005C2C8u;
    // 8005C2C8: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_8005C2CC:
    ctx->pc = 0x8005C2CCu;
    // 8005C2CC: lfs     f11, 21628(r9)
    if (!ppc_fp_available(ctx, 0x8005C2CCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21628);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005C2D0:
    ctx->pc = 0x8005C2D0u;
    // 8005C2D0: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8005C2D4:
    ctx->pc = 0x8005C2D4u;
    // 8005C2D4: lfs     f12, 21632(r11)
    if (!ppc_fp_available(ctx, 0x8005C2D4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21632);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_8005C2D8:
    ctx->pc = 0x8005C2D8u;
    // 8005C2D8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005C2DC:
    ctx->pc = 0x8005C2DCu;
    // 8005C2DC: lfs     f13, 21636(r10)
    if (!ppc_fp_available(ctx, 0x8005C2DCu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(21636);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8005C2E0:
    ctx->pc = 0x8005C2E0u;
    // 8005C2E0: addi    r27, r29, -8
    ctx->gpr[27] = ctx->gpr[29] + (u32)(s32)(-8);

label_8005C2E4:
    ctx->pc = 0x8005C2E4u;
    // 8005C2E4: lfs     f0, 21640(r8)
    if (!ppc_fp_available(ctx, 0x8005C2E4u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(21640);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005C2E8:
    ctx->pc = 0x8005C2E8u;
    // 8005C2E8: lfs     f1, -32088(r13)
    if (!ppc_fp_available(ctx, 0x8005C2E8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32088);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005C2EC:
    ctx->pc = 0x8005C2ECu;
    // 8005C2EC: stb     r7, 50(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(50);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_8005C2F0:
    ctx->pc = 0x8005C2F0u;
    // 8005C2F0: stw     r6, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005C2F4:
    ctx->pc = 0x8005C2F4u;
    // 8005C2F4: stfs     f11, 220(r29)
    if (!ppc_fp_available(ctx, 0x8005C2F4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(220);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_8005C2F8:
    ctx->pc = 0x8005C2F8u;
    // 8005C2F8: stfs     f12, 224(r29)
    if (!ppc_fp_available(ctx, 0x8005C2F8u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(224);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_8005C2FC:
    ctx->pc = 0x8005C2FCu;
    // 8005C2FC: stfs     f13, 16(r29)
    if (!ppc_fp_available(ctx, 0x8005C2FCu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8005C300:
    ctx->pc = 0x8005C300u;
    // 8005C300: stfs     f0, 20(r29)
    if (!ppc_fp_available(ctx, 0x8005C300u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C304:
    ctx->pc = 0x8005C304u;
    // 8005C304: stfs     f31, 20(r31)
    if (!ppc_fp_available(ctx, 0x8005C304u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8005C308:
    ctx->pc = 0x8005C308u;
    // 8005C308: stfs     f31, 24(r31)
    if (!ppc_fp_available(ctx, 0x8005C308u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8005C30C:
    ctx->pc = 0x8005C30Cu;
    // 8005C30C: stfs     f31, 28(r31)
    if (!ppc_fp_available(ctx, 0x8005C30Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8005C310:
    ctx->pc = 0x8005C310u;
    // 8005C310: stw     r30, 24(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8005C314:
    ctx->pc = 0x8005C314u;
    // 8005C314: sth     r30, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_8005C318:
    ctx->pc = 0x8005C318u;
    // 8005C318: bl      0x80037624
    {
            ctx->lr = 0x8005C31Cu;
            ctx->pc = 0x80037624u;
            return;
    }

label_8005C31C:
    ctx->pc = 0x8005C31Cu;
    ctx->downcount -= 33;
    // 8005C31C: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_8005C320:
    ctx->pc = 0x8005C320u;
    // 8005C320: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C324:
    ctx->pc = 0x8005C324u;
    // 8005C324: lis     r4, 17200
    ctx->gpr[4] = ((u32)(s32)(17200) << 16);

label_8005C328:
    ctx->pc = 0x8005C328u;
    // 8005C328: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005C32C:
    ctx->pc = 0x8005C32Cu;
    // 8005C32C: or   r10, r9, r9
    {
        ctx->gpr[10] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005C330:
    ctx->pc = 0x8005C330u;
    // 8005C330: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C334:
    ctx->pc = 0x8005C334u;
    // 8005C334: li      r0, 32
    ctx->gpr[0] = (u32)(s32)(32);

label_8005C338:
    ctx->pc = 0x8005C338u;
    // 8005C338: lfd     f12, 21584(r11)
    if (!ppc_fp_available(ctx, 0x8005C338u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21584);
        ctx->fpr[12] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C33C:
    ctx->pc = 0x8005C33Cu;
    // 8005C33C: lis     r7, -32738
    ctx->gpr[7] = ((u32)(s32)(-32738) << 16);

label_8005C340:
    ctx->pc = 0x8005C340u;
    // 8005C340: lfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C340u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C344:
    ctx->pc = 0x8005C344u;
    // 8005C344: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005C348:
    ctx->pc = 0x8005C348u;
    // 8005C348: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C34C:
    ctx->pc = 0x8005C34Cu;
    // 8005C34C: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_8005C350:
    ctx->pc = 0x8005C350u;
    // 8005C350: fsub   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x8005C350u)) return;
    ppc_fsub(ctx, 13, 13, 12);

label_8005C354:
    ctx->pc = 0x8005C354u;
    // 8005C354: lfs     f11, 21648(r7)
    if (!ppc_fp_available(ctx, 0x8005C354u)) return;
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(21648);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005C358:
    ctx->pc = 0x8005C358u;
    // 8005C358: frsp    f7, f13
    if (!ppc_fp_available(ctx, 0x8005C358u)) return;
    ppc_frsp(ctx, 7, 13);

label_8005C35C:
    ctx->pc = 0x8005C35Cu;
    // 8005C35C: lfs     f8, -27904(r13)
    if (!ppc_fp_available(ctx, 0x8005C35Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27904);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[8] = value;
        ctx->ps1[8] = value;
    }

label_8005C360:
    ctx->pc = 0x8005C360u;
    // 8005C360: lfs     f13, 21592(r11)
    if (!ppc_fp_available(ctx, 0x8005C360u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(21592);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8005C364:
    ctx->pc = 0x8005C364u;
    // 8005C364: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C368:
    ctx->pc = 0x8005C368u;
    // 8005C368: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C36C:
    ctx->pc = 0x8005C36Cu;
    // 8005C36C: fmr    f9, f31
    if (!ppc_fp_available(ctx, 0x8005C36Cu)) return;
    ctx->fpr[9] = ctx->fpr[31];

label_8005C370:
    ctx->pc = 0x8005C370u;
    // 8005C370: stfs     f11, 8(r28)
    if (!ppc_fp_available(ctx, 0x8005C370u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_8005C374:
    ctx->pc = 0x8005C374u;
    // 8005C374: fmr    f5, f9
    if (!ppc_fp_available(ctx, 0x8005C374u)) return;
    ctx->fpr[5] = ctx->fpr[9];

label_8005C378:
    ctx->pc = 0x8005C378u;
    // 8005C378: sth     r30, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[30]);
    }

label_8005C37C:
    ctx->pc = 0x8005C37Cu;
    // 8005C37C: fcmpu   cr0, f8, f13
    if (!ppc_fp_available(ctx, 0x8005C37Cu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[8], ctx->fpr[13], false);

label_8005C380:
    ctx->pc = 0x8005C380u;
    // 8005C380: lfs     f10, 21644(r8)
    if (!ppc_fp_available(ctx, 0x8005C380u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(21644);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_8005C384:
    ctx->pc = 0x8005C384u;
    // 8005C384: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C384u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C388:
    ctx->pc = 0x8005C388u;
    // 8005C388: stw     r0, -8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C38C:
    ctx->pc = 0x8005C38Cu;
    // 8005C38C: fsub   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x8005C38Cu)) return;
    ppc_fsub(ctx, 0, 0, 12);

label_8005C390:
    ctx->pc = 0x8005C390u;
    // 8005C390: stfs     f10, 4(r28)
    if (!ppc_fp_available(ctx, 0x8005C390u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_8005C394:
    ctx->pc = 0x8005C394u;
    // 8005C394: frsp    f6, f0
    if (!ppc_fp_available(ctx, 0x8005C394u)) return;
    ppc_frsp(ctx, 6, 0);

label_8005C398:
    ctx->pc = 0x8005C398u;
    // 8005C398: stfs     f31, 28(r29)
    if (!ppc_fp_available(ctx, 0x8005C398u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_8005C39C:
    ctx->pc = 0x8005C39Cu;
    // 8005C39C: bc    4, 1, 0x8005C440
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005C440;
        }
    }

label_8005C3A0:
    ctx->pc = 0x8005C3A0u;
    ctx->downcount -= 40;
    // 8005C3A0: lbz     r0, -27900(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27900);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8005C3A4:
    ctx->pc = 0x8005C3A4u;
    // 8005C3A4: lbz     r11, -27899(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27899);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_8005C3A8:
    ctx->pc = 0x8005C3A8u;
    // 8005C3A8: or   r7, r9, r9
    {
        ctx->gpr[7] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005C3AC:
    ctx->pc = 0x8005C3ACu;
    // 8005C3AC: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005C3B0:
    ctx->pc = 0x8005C3B0u;
    // 8005C3B0: lbz     r8, -27898(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27898);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_8005C3B4:
    ctx->pc = 0x8005C3B4u;
    // 8005C3B4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C3B8:
    ctx->pc = 0x8005C3B8u;
    // 8005C3B8: xoris   r11, r11, 0x8000
    ctx->gpr[11] = ctx->gpr[11] ^ (0x8000u << 16);

label_8005C3BC:
    ctx->pc = 0x8005C3BCu;
    // 8005C3BC: xoris   r8, r8, 0x8000
    ctx->gpr[8] = ctx->gpr[8] ^ (0x8000u << 16);

label_8005C3C0:
    ctx->pc = 0x8005C3C0u;
    // 8005C3C0: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005C3C4:
    ctx->pc = 0x8005C3C4u;
    // 8005C3C4: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C3C8:
    ctx->pc = 0x8005C3C8u;
    // 8005C3C8: or   r6, r9, r9
    {
        ctx->gpr[6] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005C3CC:
    ctx->pc = 0x8005C3CCu;
    // 8005C3CC: lbz     r0, -27897(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27897);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8005C3D0:
    ctx->pc = 0x8005C3D0u;
    // 8005C3D0: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C3D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C3D4:
    ctx->pc = 0x8005C3D4u;
    // 8005C3D4: stw     r11, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C3D8:
    ctx->pc = 0x8005C3D8u;
    // 8005C3D8: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005C3DC:
    ctx->pc = 0x8005C3DCu;
    // 8005C3DC: lfd     f11, 21600(r5)
    if (!ppc_fp_available(ctx, 0x8005C3DCu)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(21600);
        ctx->fpr[11] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C3E0:
    ctx->pc = 0x8005C3E0u;
    // 8005C3E0: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C3E4:
    ctx->pc = 0x8005C3E4u;
    // 8005C3E4: fsub   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005C3E4u)) return;
    ppc_fsub(ctx, 0, 0, 11);

label_8005C3E8:
    ctx->pc = 0x8005C3E8u;
    // 8005C3E8: lfd     f12, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C3E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[12] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C3EC:
    ctx->pc = 0x8005C3ECu;
    // 8005C3EC: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005C3ECu)) return;
    ppc_frsp(ctx, 0, 0);

label_8005C3F0:
    ctx->pc = 0x8005C3F0u;
    // 8005C3F0: stw     r8, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005C3F4:
    ctx->pc = 0x8005C3F4u;
    // 8005C3F4: fsubs   f10, f0, f7
    if (!ppc_fp_available(ctx, 0x8005C3F4u)) return;
    ppc_fsubs(ctx, 10, 0, 7);

label_8005C3F8:
    ctx->pc = 0x8005C3F8u;
    // 8005C3F8: fsub   f12, f12, f11
    if (!ppc_fp_available(ctx, 0x8005C3F8u)) return;
    ppc_fsub(ctx, 12, 12, 11);

label_8005C3FC:
    ctx->pc = 0x8005C3FCu;
    // 8005C3FC: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C400:
    ctx->pc = 0x8005C400u;
    // 8005C400: fmadds f7, f10, f8, f7
    if (!ppc_fp_available(ctx, 0x8005C400u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[7], true, false, false, &result))
            ctx->fpr[7] = ctx->ps1[7] = result;
    }

label_8005C404:
    ctx->pc = 0x8005C404u;
    // 8005C404: frsp    f12, f12
    if (!ppc_fp_available(ctx, 0x8005C404u)) return;
    ppc_frsp(ctx, 12, 12);

label_8005C408:
    ctx->pc = 0x8005C408u;
    // 8005C408: lfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C408u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C40C:
    ctx->pc = 0x8005C40Cu;
    // 8005C40C: fsubs   f10, f12, f9
    if (!ppc_fp_available(ctx, 0x8005C40Cu)) return;
    ppc_fsubs(ctx, 10, 12, 9);

label_8005C410:
    ctx->pc = 0x8005C410u;
    // 8005C410: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C414:
    ctx->pc = 0x8005C414u;
    // 8005C414: fmadds f5, f10, f8, f9
    if (!ppc_fp_available(ctx, 0x8005C414u)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[9], true, false, false, &result))
            ctx->fpr[5] = ctx->ps1[5] = result;
    }

label_8005C418:
    ctx->pc = 0x8005C418u;
    // 8005C418: fsub   f13, f13, f11
    if (!ppc_fp_available(ctx, 0x8005C418u)) return;
    ppc_fsub(ctx, 13, 13, 11);

label_8005C41C:
    ctx->pc = 0x8005C41Cu;
    // 8005C41C: stw     r4, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C420:
    ctx->pc = 0x8005C420u;
    // 8005C420: frsp    f13, f13
    if (!ppc_fp_available(ctx, 0x8005C420u)) return;
    ppc_frsp(ctx, 13, 13);

label_8005C424:
    ctx->pc = 0x8005C424u;
    // 8005C424: fsubs   f10, f13, f9
    if (!ppc_fp_available(ctx, 0x8005C424u)) return;
    ppc_fsubs(ctx, 10, 13, 9);

label_8005C428:
    ctx->pc = 0x8005C428u;
    // 8005C428: lfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C428u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C42C:
    ctx->pc = 0x8005C42Cu;
    // 8005C42C: fmadds f9, f10, f8, f9
    if (!ppc_fp_available(ctx, 0x8005C42Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[9], true, false, false, &result))
            ctx->fpr[9] = ctx->ps1[9] = result;
    }

label_8005C430:
    ctx->pc = 0x8005C430u;
    // 8005C430: fsub   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005C430u)) return;
    ppc_fsub(ctx, 0, 0, 11);

label_8005C434:
    ctx->pc = 0x8005C434u;
    // 8005C434: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005C434u)) return;
    ppc_frsp(ctx, 0, 0);

label_8005C438:
    ctx->pc = 0x8005C438u;
    // 8005C438: fsubs   f10, f0, f6
    if (!ppc_fp_available(ctx, 0x8005C438u)) return;
    ppc_fsubs(ctx, 10, 0, 6);

label_8005C43C:
    ctx->pc = 0x8005C43Cu;
    // 8005C43C: fmadds f6, f10, f8, f6
    if (!ppc_fp_available(ctx, 0x8005C43Cu)) return;
    {
        f64 result;
        if (ppc_fma(ctx, ctx->fpr[10], ctx->fpr[8], ctx->fpr[6], true, false, false, &result))
            ctx->fpr[6] = ctx->ps1[6] = result;
    }

label_8005C440:
    ctx->pc = 0x8005C440u;
    ctx->downcount -= 28;
    // 8005C440: fmr    f0, f7
    if (!ppc_fp_available(ctx, 0x8005C440u)) return;
    ctx->fpr[0] = ctx->fpr[7];

label_8005C444:
    ctx->pc = 0x8005C444u;
    // 8005C444: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8005C444u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_8005C448:
    ctx->pc = 0x8005C448u;
    // 8005C448: or   r8, r9, r9
    {
        ctx->gpr[8] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005C44C:
    ctx->pc = 0x8005C44Cu;
    // 8005C44C: stfd     f13, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C44Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_8005C450:
    ctx->pc = 0x8005C450u;
    // 8005C450: fmr    f12, f5
    if (!ppc_fp_available(ctx, 0x8005C450u)) return;
    ctx->fpr[12] = ctx->fpr[5];

label_8005C454:
    ctx->pc = 0x8005C454u;
    // 8005C454: fctiwz    f0, f12
    if (!ppc_fp_available(ctx, 0x8005C454u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[12], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8005C458:
    ctx->pc = 0x8005C458u;
    // 8005C458: lwz     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005C45C:
    ctx->pc = 0x8005C45Cu;
    // 8005C45C: fmr    f13, f9
    if (!ppc_fp_available(ctx, 0x8005C45Cu)) return;
    ctx->fpr[13] = ctx->fpr[9];

label_8005C460:
    ctx->pc = 0x8005C460u;
    // 8005C460: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C460u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8005C464:
    ctx->pc = 0x8005C464u;
    // 8005C464: or   r11, r10, r10
    {
        ctx->gpr[11] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8005C468:
    ctx->pc = 0x8005C468u;
    // 8005C468: fctiwz    f0, f13
    if (!ppc_fp_available(ctx, 0x8005C468u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8005C46C:
    ctx->pc = 0x8005C46Cu;
    // 8005C46C: rlwinm r9, r9, 24, 0, 7
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 24u) & 0xFF000000u;
    }

label_8005C470:
    ctx->pc = 0x8005C470u;
    // 8005C470: lwz     r8, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005C474:
    ctx->pc = 0x8005C474u;
    // 8005C474: fmr    f13, f6
    if (!ppc_fp_available(ctx, 0x8005C474u)) return;
    ctx->fpr[13] = ctx->fpr[6];

label_8005C478:
    ctx->pc = 0x8005C478u;
    // 8005C478: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C478u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8005C47C:
    ctx->pc = 0x8005C47Cu;
    // 8005C47C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8005C480:
    ctx->pc = 0x8005C480u;
    // 8005C480: fctiwz    f0, f13
    if (!ppc_fp_available(ctx, 0x8005C480u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[0] = dolrecomp_f64_from_bits(result); }

label_8005C484:
    ctx->pc = 0x8005C484u;
    // 8005C484: rlwinm r8, r8, 16, 8, 15
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 16u) & 0x00FF0000u;
    }

label_8005C488:
    ctx->pc = 0x8005C488u;
    // 8005C488: lwz     r10, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005C48C:
    ctx->pc = 0x8005C48Cu;
    // 8005C48C: or   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[8];
    }

label_8005C490:
    ctx->pc = 0x8005C490u;
    // 8005C490: stfd     f0, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005C490u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[0]));
    }

label_8005C494:
    ctx->pc = 0x8005C494u;
    // 8005C494: rlwinm r10, r10, 8, 16, 23
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 8u) & 0x0000FF00u;
    }

label_8005C498:
    ctx->pc = 0x8005C498u;
    // 8005C498: lwz     r11, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005C49C:
    ctx->pc = 0x8005C49Cu;
    // 8005C49C: or   r9, r9, r10
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[10];
    }

label_8005C4A0:
    ctx->pc = 0x8005C4A0u;
    // 8005C4A0: rlwinm r11, r11, 0, 24, 31
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x000000FFu;
    }

label_8005C4A4:
    ctx->pc = 0x8005C4A4u;
    // 8005C4A4: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_8005C4A8:
    ctx->pc = 0x8005C4A8u;
    // 8005C4A8: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C4AC:
    ctx->pc = 0x8005C4ACu;
    // 8005C4AC: bl      0x80050528
    {
            ctx->lr = 0x8005C4B0u;
            ctx->pc = 0x80050528u;
            return;
    }

label_8005C4B0:
    ctx->pc = 0x8005C4B0u;
    ctx->downcount -= 1;
    // 8005C4B0: bl      0x80032C88
    {
            ctx->lr = 0x8005C4B4u;
            ctx->pc = 0x80032C88u;
            return;
    }

label_8005C4B4:
    ctx->pc = 0x8005C4B4u;
    ctx->downcount -= 1;
    // 8005C4B4: bl      0x8004331C
    {
            ctx->lr = 0x8005C4B8u;
            ctx->pc = 0x8004331Cu;
            return;
    }

label_8005C4B8:
    ctx->pc = 0x8005C4B8u;
    ctx->downcount -= 2;
    // 8005C4B8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8005C4BC:
    ctx->pc = 0x8005C4BCu;
    // 8005C4BC: bl      0x80050698
    {
            ctx->lr = 0x8005C4C0u;
            ctx->pc = 0x80050698u;
            return;
    }

label_8005C4C0:
    ctx->pc = 0x8005C4C0u;
    ctx->downcount -= 1;
    // 8005C4C0: bl      0x8001B16C
    {
            ctx->lr = 0x8005C4C4u;
            ctx->pc = 0x8001B16Cu;
            return;
    }

label_8005C4C4:
    ctx->pc = 0x8005C4C4u;
    ctx->downcount -= 1;
    // 8005C4C4: b       0x8005C4DC
    {
            goto label_8005C4DC;
    }

label_8005C4C8:
    ctx->pc = 0x8005C4C8u;
    ctx->downcount -= 5;
    // 8005C4C8: lis     r3, -32702
    ctx->gpr[3] = ((u32)(s32)(-32702) << 16);

label_8005C4CC:
    ctx->pc = 0x8005C4CCu;
    // 8005C4CC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C4D0:
    ctx->pc = 0x8005C4D0u;
    // 8005C4D0: stw     r0, 30624(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(30624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C4D4:
    ctx->pc = 0x8005C4D4u;
    // 8005C4D4: addi    r3, r3, 30624
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(30624);

label_8005C4D8:
    ctx->pc = 0x8005C4D8u;
    // 8005C4D8: bl      0x80050528
    {
            ctx->lr = 0x8005C4DCu;
            ctx->pc = 0x80050528u;
            return;
    }

label_8005C4DC:
    ctx->pc = 0x8005C4DCu;
    ctx->downcount -= 17;
    // 8005C4DC: lwz     r0, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C4E0:
    ctx->pc = 0x8005C4E0u;
    // 8005C4E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005C4E4:
    ctx->pc = 0x8005C4E4u;
    // 8005C4E4: lmw     r27, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005C4E8:
    ctx->pc = 0x8005C4E8u;
    // 8005C4E8: lfd     f31, 48(r1)
    if (!ppc_fp_available(ctx, 0x8005C4E8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005C4EC:
    ctx->pc = 0x8005C4ECu;
    // 8005C4EC: addi    r1, r1, 56
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(56);

label_8005C4F0:
    ctx->pc = 0x8005C4F0u;
    // 8005C4F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C4F4:
    ctx->pc = 0x8005C4F4u;
    ctx->downcount -= 20;
    // 8005C4F4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005C4F8:
    ctx->pc = 0x8005C4F8u;
    // 8005C4F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005C4FC:
    ctx->pc = 0x8005C4FCu;
    // 8005C4FC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005C500:
    ctx->pc = 0x8005C500u;
    // 8005C500: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C504:
    ctx->pc = 0x8005C504u;
    // 8005C504: lis     r30, -32699
    ctx->gpr[30] = ((u32)(s32)(-32699) << 16);

label_8005C508:
    ctx->pc = 0x8005C508u;
    // 8005C508: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005C50C:
    ctx->pc = 0x8005C50Cu;
    // 8005C50C: addi    r31, r30, -21636
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(-21636);

label_8005C510:
    ctx->pc = 0x8005C510u;
    // 8005C510: lwz     r3, -31600(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31600);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005C514:
    ctx->pc = 0x8005C514u;
    // 8005C514: sth     r0, 960(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(960);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005C518:
    ctx->pc = 0x8005C518u;
    // 8005C518: bl      0x800688DC
    {
            ctx->lr = 0x8005C51Cu;
            ctx->pc = 0x800688DCu;
            return;
    }

label_8005C51C:
    ctx->pc = 0x8005C51Cu;
    ctx->downcount -= 10;
    // 8005C51C: lwz     r11, -21636(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-21636);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005C520:
    ctx->pc = 0x8005C520u;
    // 8005C520: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005C524:
    ctx->pc = 0x8005C524u;
    // 8005C524: addi    r9, r9, -2804
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2804);

label_8005C528:
    ctx->pc = 0x8005C528u;
    // 8005C528: mulli   r11, r11, 24
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)24);

label_8005C52C:
    ctx->pc = 0x8005C52Cu;
    // 8005C52C: add   r11, r11, r9
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_8005C530:
    ctx->pc = 0x8005C530u;
    // 8005C530: lwz     r30, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8005C534:
    ctx->pc = 0x8005C534u;
    // 8005C534: cmpwi   r30, 0
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

label_8005C538:
    ctx->pc = 0x8005C538u;
    // 8005C538: bc    12, 2, 0x8005C5D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C5D8;
        }
    }

label_8005C53C:
    ctx->pc = 0x8005C53Cu;
    ctx->downcount -= 3;
    // 8005C53C: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C540:
    ctx->pc = 0x8005C540u;
    // 8005C540: andi.   r9, r0, 0x0001
    {
        ctx->gpr[9] = ctx->gpr[0] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005C544:
    ctx->pc = 0x8005C544u;
    // 8005C544: bc    12, 2, 0x8005C56C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C56C;
        }
    }

label_8005C548:
    ctx->pc = 0x8005C548u;
    ctx->downcount -= 4;
    // 8005C548: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005C54C:
    ctx->pc = 0x8005C54Cu;
    // 8005C54C: li      r3, 28674
    ctx->gpr[3] = (u32)(s32)(28674);

label_8005C550:
    ctx->pc = 0x8005C550u;
    // 8005C550: stw     r0, 936(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(936);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C554:
    ctx->pc = 0x8005C554u;
    // 8005C554: bl      0x800C4F28
    {
            ctx->lr = 0x8005C558u;
            ctx->pc = 0x800C4F28u;
            return;
    }

label_8005C558:
    ctx->pc = 0x8005C558u;
    ctx->downcount -= 2;
    // 8005C558: cmpwi   r3, 0
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

label_8005C55C:
    ctx->pc = 0x8005C55Cu;
    // 8005C55C: bc    12, 2, 0x8005C56C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C56C;
        }
    }

label_8005C560:
    ctx->pc = 0x8005C560u;
    ctx->downcount -= 3;
    // 8005C560: lwz     r0, 936(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(936);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C564:
    ctx->pc = 0x8005C564u;
    // 8005C564: oris    r0, r0, 0x0400
    ctx->gpr[0] = ctx->gpr[0] | (0x0400u << 16);

label_8005C568:
    ctx->pc = 0x8005C568u;
    // 8005C568: stw     r0, 936(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(936);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C56C:
    ctx->pc = 0x8005C56Cu;
    ctx->downcount -= 9;
    // 8005C56C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005C570:
    ctx->pc = 0x8005C570u;
    // 8005C570: lwz     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005C574:
    ctx->pc = 0x8005C574u;
    // 8005C574: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005C578:
    ctx->pc = 0x8005C578u;
    // 8005C578: lwz     r0, 936(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(936);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C57C:
    ctx->pc = 0x8005C57Cu;
    // 8005C57C: or   r11, r0, r11
    {
        ctx->gpr[11] = ctx->gpr[0] | ctx->gpr[11];
    }

label_8005C580:
    ctx->pc = 0x8005C580u;
    // 8005C580: stw     r11, 936(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(936);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C584:
    ctx->pc = 0x8005C584u;
    // 8005C584: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C588:
    ctx->pc = 0x8005C588u;
    // 8005C588: andi.   r10, r0, 0x0002
    {
        ctx->gpr[10] = ctx->gpr[0] & 0x0002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005C58C:
    ctx->pc = 0x8005C58Cu;
    // 8005C58C: bc    12, 2, 0x8005C598
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C598;
        }
    }

label_8005C590:
    ctx->pc = 0x8005C590u;
    ctx->downcount -= 2;
    // 8005C590: oris    r0, r11, 0x0400
    ctx->gpr[0] = ctx->gpr[11] | (0x0400u << 16);

label_8005C594:
    ctx->pc = 0x8005C594u;
    // 8005C594: stw     r0, 936(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(936);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C598:
    ctx->pc = 0x8005C598u;
    ctx->downcount -= 3;
    // 8005C598: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C59C:
    ctx->pc = 0x8005C59Cu;
    // 8005C59C: andi.   r9, r0, 0x0004
    {
        ctx->gpr[9] = ctx->gpr[0] & 0x0004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005C5A0:
    ctx->pc = 0x8005C5A0u;
    // 8005C5A0: bc    12, 2, 0x8005C5B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C5B8;
        }
    }

label_8005C5A4:
    ctx->pc = 0x8005C5A4u;
    ctx->downcount -= 5;
    // 8005C5A4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005C5A8:
    ctx->pc = 0x8005C5A8u;
    // 8005C5A8: addi    r9, r9, 17168
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17168);

label_8005C5AC:
    ctx->pc = 0x8005C5ACu;
    // 8005C5AC: lhz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005C5B0:
    ctx->pc = 0x8005C5B0u;
    // 8005C5B0: ori     r0, r0, 0x0028
    ctx->gpr[0] = ctx->gpr[0] | 0x0028u;

label_8005C5B4:
    ctx->pc = 0x8005C5B4u;
    // 8005C5B4: sth     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005C5B8:
    ctx->pc = 0x8005C5B8u;
    ctx->downcount -= 3;
    // 8005C5B8: lwz     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C5BC:
    ctx->pc = 0x8005C5BCu;
    // 8005C5BC: andi.   r10, r0, 0x0008
    {
        ctx->gpr[10] = ctx->gpr[0] & 0x0008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005C5C0:
    ctx->pc = 0x8005C5C0u;
    // 8005C5C0: bc    12, 2, 0x8005C5D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C5D8;
        }
    }

label_8005C5C4:
    ctx->pc = 0x8005C5C4u;
    ctx->downcount -= 5;
    // 8005C5C4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005C5C8:
    ctx->pc = 0x8005C5C8u;
    // 8005C5C8: addi    r9, r9, 17168
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(17168);

label_8005C5CC:
    ctx->pc = 0x8005C5CCu;
    // 8005C5CC: lhz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005C5D0:
    ctx->pc = 0x8005C5D0u;
    // 8005C5D0: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_8005C5D4:
    ctx->pc = 0x8005C5D4u;
    // 8005C5D4: sth     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005C5D8:
    ctx->pc = 0x8005C5D8u;
    ctx->downcount -= 19;
    // 8005C5D8: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_8005C5DC:
    ctx->pc = 0x8005C5DCu;
    // 8005C5DC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C5E0:
    ctx->pc = 0x8005C5E0u;
    // 8005C5E0: stw     r0, 31460(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C5E4:
    ctx->pc = 0x8005C5E4u;
    // 8005C5E4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C5E8:
    ctx->pc = 0x8005C5E8u;
    // 8005C5E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005C5EC:
    ctx->pc = 0x8005C5ECu;
    // 8005C5EC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005C5F0:
    ctx->pc = 0x8005C5F0u;
    // 8005C5F0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005C5F4:
    ctx->pc = 0x8005C5F4u;
    // 8005C5F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C5F8:
    ctx->pc = 0x8005C5F8u;
    ctx->downcount -= 8;
    // 8005C5F8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005C5FC:
    ctx->pc = 0x8005C5FCu;
    // 8005C5FC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005C600:
    ctx->pc = 0x8005C600u;
    // 8005C600: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005C604:
    ctx->pc = 0x8005C604u;
    // 8005C604: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C608:
    ctx->pc = 0x8005C608u;
    // 8005C608: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_8005C60C:
    ctx->pc = 0x8005C60Cu;
    // 8005C60C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C610:
    ctx->pc = 0x8005C610u;
    // 8005C610: stw     r0, 31460(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C614:
    ctx->pc = 0x8005C614u;
    // 8005C614: li      r31, 100
    ctx->gpr[31] = (u32)(s32)(100);

label_8005C618:
    ctx->downcount -= 2;
    // 8005C618: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005C61C:
    // 8005C61C: bl      0x8001D910
    {
            ctx->lr = 0x8005C620u;
            ctx->pc = 0x8001D910u;
            return;
    }

label_8005C620:
    ctx->downcount -= 2;
    // 8005C620: addic.  r31, r31, -1
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

label_8005C624:
    // 8005C624: bc    4, 2, 0x8005C618
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C618u;
                return;
            }
            goto label_8005C618;
        }
    }

label_8005C628:
    ctx->pc = 0x8005C628u;
    ctx->downcount -= 6;
    // 8005C628: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C62C:
    ctx->pc = 0x8005C62Cu;
    // 8005C62C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005C630:
    ctx->pc = 0x8005C630u;
    // 8005C630: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8005C634:
    ctx->pc = 0x8005C634u;
    // 8005C634: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005C638:
    ctx->pc = 0x8005C638u;
    // 8005C638: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C63C:
    ctx->pc = 0x8005C63Cu;
    ctx->downcount -= 40;
    // 8005C63C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005C640:
    ctx->pc = 0x8005C640u;
    // 8005C640: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005C644:
    ctx->pc = 0x8005C644u;
    // 8005C644: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005C648:
    ctx->pc = 0x8005C648u;
    // 8005C648: lis     r10, -32699
    ctx->gpr[10] = ((u32)(s32)(-32699) << 16);

label_8005C64C:
    ctx->pc = 0x8005C64Cu;
    // 8005C64C: stw     r11, -13308(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-13308);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C650:
    ctx->pc = 0x8005C650u;
    // 8005C650: addi    r9, r10, -13308
    ctx->gpr[9] = ctx->gpr[10] + (u32)(s32)(-13308);

label_8005C654:
    ctx->pc = 0x8005C654u;
    // 8005C654: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C658:
    ctx->pc = 0x8005C658u;
    // 8005C658: stw     r11, 16756(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16756);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C65C:
    ctx->pc = 0x8005C65Cu;
    // 8005C65C: stw     r0, 16760(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C660:
    ctx->pc = 0x8005C660u;
    // 8005C660: li      r8, -1
    ctx->gpr[8] = (u32)(s32)(-1);

label_8005C664:
    ctx->pc = 0x8005C664u;
    // 8005C664: stw     r8, -27920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27920);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005C668:
    ctx->pc = 0x8005C668u;
    // 8005C668: li      r7, 50
    ctx->gpr[7] = (u32)(s32)(50);

label_8005C66C:
    ctx->pc = 0x8005C66Cu;
    // 8005C66C: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C670:
    ctx->pc = 0x8005C670u;
    // 8005C670: li      r6, 350
    ctx->gpr[6] = (u32)(s32)(350);

label_8005C674:
    ctx->pc = 0x8005C674u;
    // 8005C674: stw     r0, 8384(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8384);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C678:
    ctx->pc = 0x8005C678u;
    // 8005C678: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8005C67C:
    ctx->pc = 0x8005C67Cu;
    // 8005C67C: stw     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C680:
    ctx->pc = 0x8005C680u;
    // 8005C680: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8005C684:
    ctx->pc = 0x8005C684u;
    // 8005C684: stw     r11, 8376(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8376);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C688:
    ctx->pc = 0x8005C688u;
    // 8005C688: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8005C68C:
    ctx->pc = 0x8005C68Cu;
    // 8005C68C: stw     r11, 8380(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8380);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C690:
    ctx->pc = 0x8005C690u;
    // 8005C690: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005C694:
    ctx->pc = 0x8005C694u;
    // 8005C694: stw     r11, 16752(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16752);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C698:
    ctx->pc = 0x8005C698u;
    // 8005C698: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005C69C:
    ctx->pc = 0x8005C69Cu;
    // 8005C69C: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C6A0:
    ctx->pc = 0x8005C6A0u;
    // 8005C6A0: li      r31, 320
    ctx->gpr[31] = (u32)(s32)(320);

label_8005C6A4:
    ctx->pc = 0x8005C6A4u;
    // 8005C6A4: lfs     f0, 21724(r10)
    if (!ppc_fp_available(ctx, 0x8005C6A4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(21724);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005C6A8:
    ctx->pc = 0x8005C6A8u;
    // 8005C6A8: li      r12, -1
    ctx->gpr[12] = (u32)(s32)(-1);

label_8005C6AC:
    ctx->pc = 0x8005C6ACu;
    // 8005C6AC: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005C6B0:
    ctx->pc = 0x8005C6B0u;
    // 8005C6B0: stw     r7, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005C6B4:
    ctx->pc = 0x8005C6B4u;
    // 8005C6B4: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8005C6B8:
    ctx->pc = 0x8005C6B8u;
    // 8005C6B8: stw     r6, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005C6BC:
    ctx->pc = 0x8005C6BCu;
    // 8005C6BC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C6C0:
    ctx->pc = 0x8005C6C0u;
    // 8005C6C0: addi    r8, r3, 20
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(20);

label_8005C6C4:
    ctx->pc = 0x8005C6C4u;
    // 8005C6C4: stw     r5, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8005C6C8:
    ctx->pc = 0x8005C6C8u;
    // 8005C6C8: stw     r11, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C6CC:
    ctx->pc = 0x8005C6CCu;
    // 8005C6CC: stw     r11, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C6D0:
    ctx->pc = 0x8005C6D0u;
    // 8005C6D0: stw     r11, 132(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C6D4:
    ctx->pc = 0x8005C6D4u;
    // 8005C6D4: stw     r11, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C6D8:
    ctx->pc = 0x8005C6D8u;
    ctx->downcount -= 7;
    // 8005C6D8: stw     r4, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C6DC:
    ctx->pc = 0x8005C6DCu;
    // 8005C6DC: stw     r4, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C6E0:
    ctx->pc = 0x8005C6E0u;
    // 8005C6E0: stw     r31, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005C6E4:
    ctx->pc = 0x8005C6E4u;
    // 8005C6E4: stw     r12, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8005C6E8:
    ctx->pc = 0x8005C6E8u;
    // 8005C6E8: stfs     f0, 16(r8)
    if (!ppc_fp_available(ctx, 0x8005C6E8u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C6EC:
    // 8005C6EC: addi    r8, r8, 20
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(20);

label_8005C6F0:
    // 8005C6F0: bc    16, 0, 0x8005C6D8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C6D8u;
                return;
            }
            goto label_8005C6D8;
        }
    }

label_8005C6F4:
    ctx->pc = 0x8005C6F4u;
    ctx->downcount -= 23;
    // 8005C6F4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005C6F8:
    ctx->pc = 0x8005C6F8u;
    // 8005C6F8: li      r10, 320
    ctx->gpr[10] = (u32)(s32)(320);

label_8005C6FC:
    ctx->pc = 0x8005C6FCu;
    // 8005C6FC: li      r0, 150
    ctx->gpr[0] = (u32)(s32)(150);

label_8005C700:
    ctx->pc = 0x8005C700u;
    // 8005C700: li      r11, -1
    ctx->gpr[11] = (u32)(s32)(-1);

label_8005C704:
    ctx->pc = 0x8005C704u;
    // 8005C704: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C708:
    ctx->pc = 0x8005C708u;
    // 8005C708: lis     r6, -32699
    ctx->gpr[6] = ((u32)(s32)(-32699) << 16);

label_8005C70C:
    ctx->pc = 0x8005C70Cu;
    // 8005C70C: stw     r10, 140(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C710:
    ctx->pc = 0x8005C710u;
    // 8005C710: li      r8, 16
    ctx->gpr[8] = (u32)(s32)(16);

label_8005C714:
    ctx->pc = 0x8005C714u;
    // 8005C714: stw     r11, 144(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C718:
    ctx->pc = 0x8005C718u;
    // 8005C718: li      r7, 5
    ctx->gpr[7] = (u32)(s32)(5);

label_8005C71C:
    ctx->pc = 0x8005C71Cu;
    // 8005C71C: stw     r9, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C720:
    ctx->pc = 0x8005C720u;
    // 8005C720: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C724:
    ctx->pc = 0x8005C724u;
    // 8005C724: stw     r10, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C728:
    ctx->pc = 0x8005C728u;
    // 8005C728: stw     r9, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C72C:
    ctx->pc = 0x8005C72Cu;
    // 8005C72C: stw     r9, 160(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C730:
    ctx->pc = 0x8005C730u;
    // 8005C730: stw     r9, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C734:
    ctx->pc = 0x8005C734u;
    // 8005C734: stw     r9, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C738:
    ctx->pc = 0x8005C738u;
    // 8005C738: sth     r8, -21584(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_8005C73C:
    ctx->pc = 0x8005C73Cu;
    // 8005C73C: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C740:
    ctx->pc = 0x8005C740u;
    // 8005C740: stw     r7, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005C744:
    ctx->pc = 0x8005C744u;
    // 8005C744: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8005C748:
    ctx->pc = 0x8005C748u;
    // 8005C748: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005C74C:
    ctx->pc = 0x8005C74Cu;
    // 8005C74C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C750:
    ctx->pc = 0x8005C750u;
    ctx->downcount -= 40;
    // 8005C750: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005C754:
    ctx->pc = 0x8005C754u;
    // 8005C754: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005C758:
    ctx->pc = 0x8005C758u;
    // 8005C758: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005C75C:
    ctx->pc = 0x8005C75Cu;
    // 8005C75C: lis     r10, -32699
    ctx->gpr[10] = ((u32)(s32)(-32699) << 16);

label_8005C760:
    ctx->pc = 0x8005C760u;
    // 8005C760: stw     r11, -13308(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-13308);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C764:
    ctx->pc = 0x8005C764u;
    // 8005C764: addi    r9, r10, -13308
    ctx->gpr[9] = ctx->gpr[10] + (u32)(s32)(-13308);

label_8005C768:
    ctx->pc = 0x8005C768u;
    // 8005C768: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005C76C:
    ctx->pc = 0x8005C76Cu;
    // 8005C76C: stw     r11, 16756(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16756);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C770:
    ctx->pc = 0x8005C770u;
    // 8005C770: stw     r0, 16760(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C774:
    ctx->pc = 0x8005C774u;
    // 8005C774: li      r8, -1
    ctx->gpr[8] = (u32)(s32)(-1);

label_8005C778:
    ctx->pc = 0x8005C778u;
    // 8005C778: stw     r8, -27920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27920);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005C77C:
    ctx->pc = 0x8005C77Cu;
    // 8005C77C: li      r7, 50
    ctx->gpr[7] = (u32)(s32)(50);

label_8005C780:
    ctx->pc = 0x8005C780u;
    // 8005C780: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C784:
    ctx->pc = 0x8005C784u;
    // 8005C784: li      r6, 350
    ctx->gpr[6] = (u32)(s32)(350);

label_8005C788:
    ctx->pc = 0x8005C788u;
    // 8005C788: stw     r0, 8384(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8384);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C78C:
    ctx->pc = 0x8005C78Cu;
    // 8005C78C: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8005C790:
    ctx->pc = 0x8005C790u;
    // 8005C790: stw     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C794:
    ctx->pc = 0x8005C794u;
    // 8005C794: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8005C798:
    ctx->pc = 0x8005C798u;
    // 8005C798: stw     r11, 8376(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8376);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C79C:
    ctx->pc = 0x8005C79Cu;
    // 8005C79C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8005C7A0:
    ctx->pc = 0x8005C7A0u;
    // 8005C7A0: stw     r11, 8380(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8380);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C7A4:
    ctx->pc = 0x8005C7A4u;
    // 8005C7A4: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005C7A8:
    ctx->pc = 0x8005C7A8u;
    // 8005C7A8: stw     r11, 16752(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16752);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C7AC:
    ctx->pc = 0x8005C7ACu;
    // 8005C7AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005C7B0:
    ctx->pc = 0x8005C7B0u;
    // 8005C7B0: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C7B4:
    ctx->pc = 0x8005C7B4u;
    // 8005C7B4: li      r31, 320
    ctx->gpr[31] = (u32)(s32)(320);

label_8005C7B8:
    ctx->pc = 0x8005C7B8u;
    // 8005C7B8: lfs     f0, 21728(r10)
    if (!ppc_fp_available(ctx, 0x8005C7B8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(21728);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005C7BC:
    ctx->pc = 0x8005C7BCu;
    // 8005C7BC: li      r12, -1
    ctx->gpr[12] = (u32)(s32)(-1);

label_8005C7C0:
    ctx->pc = 0x8005C7C0u;
    // 8005C7C0: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005C7C4:
    ctx->pc = 0x8005C7C4u;
    // 8005C7C4: stw     r7, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005C7C8:
    ctx->pc = 0x8005C7C8u;
    // 8005C7C8: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8005C7CC:
    ctx->pc = 0x8005C7CCu;
    // 8005C7CC: stw     r6, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005C7D0:
    ctx->pc = 0x8005C7D0u;
    // 8005C7D0: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C7D4:
    ctx->pc = 0x8005C7D4u;
    // 8005C7D4: addi    r8, r3, 20
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(20);

label_8005C7D8:
    ctx->pc = 0x8005C7D8u;
    // 8005C7D8: stw     r5, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8005C7DC:
    ctx->pc = 0x8005C7DCu;
    // 8005C7DC: stw     r11, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C7E0:
    ctx->pc = 0x8005C7E0u;
    // 8005C7E0: stw     r11, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C7E4:
    ctx->pc = 0x8005C7E4u;
    // 8005C7E4: stw     r11, 132(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C7E8:
    ctx->pc = 0x8005C7E8u;
    // 8005C7E8: stw     r11, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C7EC:
    ctx->pc = 0x8005C7ECu;
    ctx->downcount -= 7;
    // 8005C7EC: stw     r4, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C7F0:
    ctx->pc = 0x8005C7F0u;
    // 8005C7F0: stw     r4, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C7F4:
    ctx->pc = 0x8005C7F4u;
    // 8005C7F4: stw     r31, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005C7F8:
    ctx->pc = 0x8005C7F8u;
    // 8005C7F8: stw     r12, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8005C7FC:
    ctx->pc = 0x8005C7FCu;
    // 8005C7FC: stfs     f0, 16(r8)
    if (!ppc_fp_available(ctx, 0x8005C7FCu)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C800:
    // 8005C800: addi    r8, r8, 20
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(20);

label_8005C804:
    // 8005C804: bc    16, 0, 0x8005C7EC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C7ECu;
                return;
            }
            goto label_8005C7EC;
        }
    }

label_8005C808:
    ctx->pc = 0x8005C808u;
    ctx->downcount -= 22;
    // 8005C808: li      r0, 150
    ctx->gpr[0] = (u32)(s32)(150);

label_8005C80C:
    ctx->pc = 0x8005C80Cu;
    // 8005C80C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005C810:
    ctx->pc = 0x8005C810u;
    // 8005C810: li      r10, 320
    ctx->gpr[10] = (u32)(s32)(320);

label_8005C814:
    ctx->pc = 0x8005C814u;
    // 8005C814: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C818:
    ctx->pc = 0x8005C818u;
    // 8005C818: li      r11, -1
    ctx->gpr[11] = (u32)(s32)(-1);

label_8005C81C:
    ctx->pc = 0x8005C81Cu;
    // 8005C81C: lis     r7, -32699
    ctx->gpr[7] = ((u32)(s32)(-32699) << 16);

label_8005C820:
    ctx->pc = 0x8005C820u;
    // 8005C820: stw     r10, 140(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C824:
    ctx->pc = 0x8005C824u;
    // 8005C824: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_8005C828:
    ctx->pc = 0x8005C828u;
    // 8005C828: stw     r11, 144(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C82C:
    ctx->pc = 0x8005C82Cu;
    // 8005C82C: li      r8, 5
    ctx->gpr[8] = (u32)(s32)(5);

label_8005C830:
    ctx->pc = 0x8005C830u;
    // 8005C830: stw     r10, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C834:
    ctx->pc = 0x8005C834u;
    // 8005C834: stw     r9, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C838:
    ctx->pc = 0x8005C838u;
    // 8005C838: stw     r9, 160(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C83C:
    ctx->pc = 0x8005C83Cu;
    // 8005C83C: stw     r9, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C840:
    ctx->pc = 0x8005C840u;
    // 8005C840: stw     r9, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C844:
    ctx->pc = 0x8005C844u;
    // 8005C844: stw     r9, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C848:
    ctx->pc = 0x8005C848u;
    // 8005C848: sth     r0, -21584(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005C84C:
    ctx->pc = 0x8005C84Cu;
    // 8005C84C: stw     r9, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C850:
    ctx->pc = 0x8005C850u;
    // 8005C850: stw     r8, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005C854:
    ctx->pc = 0x8005C854u;
    // 8005C854: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8005C858:
    ctx->pc = 0x8005C858u;
    // 8005C858: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005C85C:
    ctx->pc = 0x8005C85Cu;
    // 8005C85C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C860:
    ctx->pc = 0x8005C860u;
    ctx->downcount -= 24;
    // 8005C860: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005C864:
    ctx->pc = 0x8005C864u;
    // 8005C864: li      r8, 350
    ctx->gpr[8] = (u32)(s32)(350);

label_8005C868:
    ctx->pc = 0x8005C868u;
    // 8005C868: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C86C:
    ctx->pc = 0x8005C86Cu;
    // 8005C86C: li      r10, 50
    ctx->gpr[10] = (u32)(s32)(50);

label_8005C870:
    ctx->pc = 0x8005C870u;
    // 8005C870: stw     r8, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005C874:
    ctx->pc = 0x8005C874u;
    // 8005C874: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005C878:
    ctx->pc = 0x8005C878u;
    // 8005C878: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005C87C:
    ctx->pc = 0x8005C87Cu;
    // 8005C87C: li      r8, 5
    ctx->gpr[8] = (u32)(s32)(5);

label_8005C880:
    ctx->pc = 0x8005C880u;
    // 8005C880: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8005C884:
    ctx->pc = 0x8005C884u;
    // 8005C884: li      r7, 3
    ctx->gpr[7] = (u32)(s32)(3);

label_8005C888:
    ctx->pc = 0x8005C888u;
    // 8005C888: mtctr    r8
    ctx->ctr = ctx->gpr[8];

label_8005C88C:
    ctx->pc = 0x8005C88Cu;
    // 8005C88C: lfs     f0, 21732(r9)
    if (!ppc_fp_available(ctx, 0x8005C88Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(21732);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005C890:
    ctx->pc = 0x8005C890u;
    // 8005C890: stw     r10, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C894:
    ctx->pc = 0x8005C894u;
    // 8005C894: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8005C898:
    ctx->pc = 0x8005C898u;
    // 8005C898: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C89C:
    ctx->pc = 0x8005C89Cu;
    // 8005C89C: li      r10, 320
    ctx->gpr[10] = (u32)(s32)(320);

label_8005C8A0:
    ctx->pc = 0x8005C8A0u;
    // 8005C8A0: stw     r7, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005C8A4:
    ctx->pc = 0x8005C8A4u;
    // 8005C8A4: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005C8A8:
    ctx->pc = 0x8005C8A8u;
    // 8005C8A8: stw     r11, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C8AC:
    ctx->pc = 0x8005C8ACu;
    // 8005C8AC: addi    r9, r3, 20
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(20);

label_8005C8B0:
    ctx->pc = 0x8005C8B0u;
    // 8005C8B0: stw     r11, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C8B4:
    ctx->pc = 0x8005C8B4u;
    // 8005C8B4: stw     r11, 132(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C8B8:
    ctx->pc = 0x8005C8B8u;
    // 8005C8B8: stw     r11, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C8BC:
    ctx->pc = 0x8005C8BCu;
    ctx->downcount -= 7;
    // 8005C8BC: stw     r6, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005C8C0:
    ctx->pc = 0x8005C8C0u;
    // 8005C8C0: stw     r6, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005C8C4:
    ctx->pc = 0x8005C8C4u;
    // 8005C8C4: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C8C8:
    ctx->pc = 0x8005C8C8u;
    // 8005C8C8: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C8CC:
    ctx->pc = 0x8005C8CCu;
    // 8005C8CC: stfs     f0, 16(r9)
    if (!ppc_fp_available(ctx, 0x8005C8CCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005C8D0:
    // 8005C8D0: addi    r9, r9, 20
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(20);

label_8005C8D4:
    // 8005C8D4: bc    16, 0, 0x8005C8BC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C8BCu;
                return;
            }
            goto label_8005C8BC;
        }
    }

label_8005C8D8:
    ctx->pc = 0x8005C8D8u;
    ctx->downcount -= 21;
    // 8005C8D8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005C8DC:
    ctx->pc = 0x8005C8DCu;
    // 8005C8DC: li      r10, 320
    ctx->gpr[10] = (u32)(s32)(320);

label_8005C8E0:
    ctx->pc = 0x8005C8E0u;
    // 8005C8E0: li      r0, 150
    ctx->gpr[0] = (u32)(s32)(150);

label_8005C8E4:
    ctx->pc = 0x8005C8E4u;
    // 8005C8E4: li      r11, -1
    ctx->gpr[11] = (u32)(s32)(-1);

label_8005C8E8:
    ctx->pc = 0x8005C8E8u;
    // 8005C8E8: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C8EC:
    ctx->pc = 0x8005C8ECu;
    // 8005C8EC: lis     r6, -32699
    ctx->gpr[6] = ((u32)(s32)(-32699) << 16);

label_8005C8F0:
    ctx->pc = 0x8005C8F0u;
    // 8005C8F0: stw     r10, 140(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C8F4:
    ctx->pc = 0x8005C8F4u;
    // 8005C8F4: li      r8, 16
    ctx->gpr[8] = (u32)(s32)(16);

label_8005C8F8:
    ctx->pc = 0x8005C8F8u;
    // 8005C8F8: stw     r11, 144(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C8FC:
    ctx->pc = 0x8005C8FCu;
    // 8005C8FC: li      r7, 5
    ctx->gpr[7] = (u32)(s32)(5);

label_8005C900:
    ctx->pc = 0x8005C900u;
    // 8005C900: stw     r9, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C904:
    ctx->pc = 0x8005C904u;
    // 8005C904: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8005C908:
    ctx->pc = 0x8005C908u;
    // 8005C908: stw     r10, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C90C:
    ctx->pc = 0x8005C90Cu;
    // 8005C90C: stw     r9, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C910:
    ctx->pc = 0x8005C910u;
    // 8005C910: stw     r9, 160(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C914:
    ctx->pc = 0x8005C914u;
    // 8005C914: stw     r9, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C918:
    ctx->pc = 0x8005C918u;
    // 8005C918: stw     r9, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C91C:
    ctx->pc = 0x8005C91Cu;
    // 8005C91C: sth     r8, -21584(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_8005C920:
    ctx->pc = 0x8005C920u;
    // 8005C920: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C924:
    ctx->pc = 0x8005C924u;
    // 8005C924: stw     r7, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005C928:
    ctx->pc = 0x8005C928u;
    // 8005C928: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C92C:
    ctx->pc = 0x8005C92Cu;
    ctx->downcount -= 2;
    // 8005C92C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005C930:
    ctx->pc = 0x8005C930u;
    // 8005C930: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C934:
    ctx->pc = 0x8005C934u;
    ctx->downcount -= 3;
    // 8005C934: or.   r5, r5, r5
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

label_8005C938:
    ctx->pc = 0x8005C938u;
    // 8005C938: stw     r4, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C93C:
    ctx->pc = 0x8005C93Cu;
    // 8005C93C: bc    12, 2, 0x8005C944
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C944;
        }
    }

label_8005C940:
    ctx->pc = 0x8005C940u;
    ctx->downcount -= 1;
    // 8005C940: stw     r5, 132(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8005C944:
    ctx->pc = 0x8005C944u;
    ctx->downcount -= 3;
    // 8005C944: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8005C948:
    ctx->pc = 0x8005C948u;
    // 8005C948: stw     r0, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C94C:
    ctx->pc = 0x8005C94Cu;
    // 8005C94C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C950:
    ctx->pc = 0x8005C950u;
    ctx->downcount -= 13;
    // 8005C950: lwz     r8, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005C954:
    ctx->pc = 0x8005C954u;
    // 8005C954: li      r9, 320
    ctx->gpr[9] = (u32)(s32)(320);

label_8005C958:
    ctx->pc = 0x8005C958u;
    // 8005C958: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005C95C:
    ctx->pc = 0x8005C95Cu;
    // 8005C95C: li      r11, 4
    ctx->gpr[11] = (u32)(s32)(4);

label_8005C960:
    ctx->pc = 0x8005C960u;
    // 8005C960: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_8005C964:
    ctx->pc = 0x8005C964u;
    // 8005C964: stw     r5, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8005C968:
    ctx->pc = 0x8005C968u;
    // 8005C968: stw     r9, 140(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005C96C:
    ctx->pc = 0x8005C96Cu;
    // 8005C96C: stw     r0, 144(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C970:
    ctx->pc = 0x8005C970u;
    // 8005C970: stw     r4, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005C974:
    ctx->pc = 0x8005C974u;
    // 8005C974: stw     r8, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005C978:
    ctx->pc = 0x8005C978u;
    // 8005C978: stw     r11, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005C97C:
    ctx->pc = 0x8005C97Cu;
    // 8005C97C: stw     r10, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005C980:
    ctx->pc = 0x8005C980u;
    // 8005C980: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005C984:
    ctx->pc = 0x8005C984u;
    ctx->downcount -= 18;
    // 8005C984: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005C988:
    ctx->pc = 0x8005C988u;
    // 8005C988: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005C98C:
    ctx->pc = 0x8005C98Cu;
    // 8005C98C: stmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005C990:
    ctx->pc = 0x8005C990u;
    // 8005C990: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005C994:
    ctx->pc = 0x8005C994u;
    // 8005C994: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005C998:
    ctx->pc = 0x8005C998u;
    // 8005C998: lwz     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005C99C:
    ctx->pc = 0x8005C99Cu;
    // 8005C99C: cmpwi   r0, 12
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(12);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005C9A0:
    ctx->pc = 0x8005C9A0u;
    // 8005C9A0: bc    12, 2, 0x8005D198
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D198;
        }
    }

label_8005C9A4:
    ctx->pc = 0x8005C9A4u;
    ctx->downcount -= 1;
    // 8005C9A4: bc    12, 1, 0x8005CA1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CA1C;
        }
    }

label_8005C9A8:
    ctx->pc = 0x8005C9A8u;
    ctx->downcount -= 2;
    // 8005C9A8: cmpwi   r0, 5
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(5);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005C9AC:
    ctx->pc = 0x8005C9ACu;
    // 8005C9AC: bc    12, 2, 0x8005CF30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CF30;
        }
    }

label_8005C9B0:
    ctx->pc = 0x8005C9B0u;
    ctx->downcount -= 1;
    // 8005C9B0: bc    12, 1, 0x8005C9E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C9E8;
        }
    }

label_8005C9B4:
    ctx->pc = 0x8005C9B4u;
    ctx->downcount -= 2;
    // 8005C9B4: cmpwi   r0, 2
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

label_8005C9B8:
    ctx->pc = 0x8005C9B8u;
    // 8005C9B8: bc    12, 2, 0x8005CBA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CBA0;
        }
    }

label_8005C9BC:
    ctx->pc = 0x8005C9BCu;
    ctx->downcount -= 1;
    // 8005C9BC: bc    12, 1, 0x8005C9D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005C9D4;
        }
    }

label_8005C9C0:
    ctx->pc = 0x8005C9C0u;
    ctx->downcount -= 2;
    // 8005C9C0: cmpwi   r0, 0
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

label_8005C9C4:
    ctx->pc = 0x8005C9C4u;
    // 8005C9C4: bc    12, 2, 0x8005CA94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CA94;
        }
    }

label_8005C9C8:
    ctx->pc = 0x8005C9C8u;
    ctx->downcount -= 2;
    // 8005C9C8: cmpwi   r0, 1
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

label_8005C9CC:
    ctx->pc = 0x8005C9CCu;
    // 8005C9CC: bc    12, 2, 0x8005CAA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CAA8;
        }
    }

label_8005C9D0:
    ctx->pc = 0x8005C9D0u;
    ctx->downcount -= 1;
    // 8005C9D0: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005C9D4:
    ctx->pc = 0x8005C9D4u;
    ctx->downcount -= 2;
    // 8005C9D4: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005C9D8:
    ctx->pc = 0x8005C9D8u;
    // 8005C9D8: bc    12, 2, 0x8005CE98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CE98;
        }
    }

label_8005C9DC:
    ctx->pc = 0x8005C9DCu;
    ctx->downcount -= 2;
    // 8005C9DC: cmpwi   r0, 4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005C9E0:
    ctx->pc = 0x8005C9E0u;
    // 8005C9E0: bc    12, 2, 0x8005CBCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CBCC;
        }
    }

label_8005C9E4:
    ctx->pc = 0x8005C9E4u;
    ctx->downcount -= 1;
    // 8005C9E4: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005C9E8:
    ctx->pc = 0x8005C9E8u;
    ctx->downcount -= 2;
    // 8005C9E8: cmpwi   r0, 8
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(8);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005C9EC:
    ctx->pc = 0x8005C9ECu;
    // 8005C9EC: bc    12, 2, 0x8005CEB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CEB8;
        }
    }

label_8005C9F0:
    ctx->pc = 0x8005C9F0u;
    ctx->downcount -= 1;
    // 8005C9F0: bc    12, 1, 0x8005CA08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CA08;
        }
    }

label_8005C9F4:
    ctx->pc = 0x8005C9F4u;
    ctx->downcount -= 2;
    // 8005C9F4: cmpwi   r0, 6
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(6);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005C9F8:
    ctx->pc = 0x8005C9F8u;
    // 8005C9F8: bc    12, 2, 0x8005CED0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CED0;
        }
    }

label_8005C9FC:
    ctx->pc = 0x8005C9FCu;
    ctx->downcount -= 2;
    // 8005C9FC: cmpwi   r0, 7
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA00:
    ctx->pc = 0x8005CA00u;
    // 8005CA00: bc    12, 2, 0x8005CEE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CEE8;
        }
    }

label_8005CA04:
    ctx->pc = 0x8005CA04u;
    ctx->downcount -= 1;
    // 8005CA04: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CA08:
    ctx->pc = 0x8005CA08u;
    ctx->downcount -= 2;
    // 8005CA08: cmpwi   r0, 10
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

label_8005CA0C:
    ctx->pc = 0x8005CA0Cu;
    // 8005CA0C: bc    12, 2, 0x8005D2D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D2D0;
        }
    }

label_8005CA10:
    ctx->pc = 0x8005CA10u;
    ctx->downcount -= 2;
    // 8005CA10: cmpwi   r0, 11
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(11);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA14:
    ctx->pc = 0x8005CA14u;
    // 8005CA14: bc    12, 2, 0x8005D1C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D1C4;
        }
    }

label_8005CA18:
    ctx->pc = 0x8005CA18u;
    ctx->downcount -= 1;
    // 8005CA18: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CA1C:
    ctx->pc = 0x8005CA1Cu;
    ctx->downcount -= 2;
    // 8005CA1C: cmpwi   r0, 18
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(18);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA20:
    ctx->pc = 0x8005CA20u;
    // 8005CA20: bc    12, 2, 0x8005D304
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D304;
        }
    }

label_8005CA24:
    ctx->pc = 0x8005CA24u;
    ctx->downcount -= 1;
    // 8005CA24: bc    12, 1, 0x8005CA5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CA5C;
        }
    }

label_8005CA28:
    ctx->pc = 0x8005CA28u;
    ctx->downcount -= 2;
    // 8005CA28: cmpwi   r0, 15
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(15);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA2C:
    ctx->pc = 0x8005CA2Cu;
    // 8005CA2C: bc    12, 2, 0x8005D204
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D204;
        }
    }

label_8005CA30:
    ctx->pc = 0x8005CA30u;
    ctx->downcount -= 1;
    // 8005CA30: bc    12, 1, 0x8005CA48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CA48;
        }
    }

label_8005CA34:
    ctx->pc = 0x8005CA34u;
    ctx->downcount -= 2;
    // 8005CA34: cmpwi   r0, 13
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(13);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA38:
    ctx->pc = 0x8005CA38u;
    // 8005CA38: bc    12, 2, 0x8005D2F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D2F8;
        }
    }

label_8005CA3C:
    ctx->pc = 0x8005CA3Cu;
    ctx->downcount -= 2;
    // 8005CA3C: cmpwi   r0, 14
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(14);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA40:
    ctx->pc = 0x8005CA40u;
    // 8005CA40: bc    12, 2, 0x8005D0F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D0F8;
        }
    }

label_8005CA44:
    ctx->pc = 0x8005CA44u;
    ctx->downcount -= 1;
    // 8005CA44: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CA48:
    ctx->pc = 0x8005CA48u;
    ctx->downcount -= 2;
    // 8005CA48: cmpwi   r0, 16
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(16);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA4C:
    ctx->pc = 0x8005CA4Cu;
    // 8005CA4C: bc    12, 2, 0x8005D25C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D25C;
        }
    }

label_8005CA50:
    ctx->pc = 0x8005CA50u;
    ctx->downcount -= 2;
    // 8005CA50: cmpwi   r0, 17
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(17);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA54:
    ctx->pc = 0x8005CA54u;
    // 8005CA54: bc    12, 2, 0x8005D330
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D330;
        }
    }

label_8005CA58:
    ctx->pc = 0x8005CA58u;
    ctx->downcount -= 1;
    // 8005CA58: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CA5C:
    ctx->pc = 0x8005CA5Cu;
    ctx->downcount -= 2;
    // 8005CA5C: cmpwi   r0, 21
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(21);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA60:
    ctx->pc = 0x8005CA60u;
    // 8005CA60: bc    12, 2, 0x8005CFF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CFF0;
        }
    }

label_8005CA64:
    ctx->pc = 0x8005CA64u;
    ctx->downcount -= 1;
    // 8005CA64: bc    12, 1, 0x8005CA7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CA7C;
        }
    }

label_8005CA68:
    ctx->pc = 0x8005CA68u;
    ctx->downcount -= 2;
    // 8005CA68: cmpwi   r0, 19
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA6C:
    ctx->pc = 0x8005CA6Cu;
    // 8005CA6C: bc    12, 2, 0x8005D230
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D230;
        }
    }

label_8005CA70:
    ctx->pc = 0x8005CA70u;
    ctx->downcount -= 2;
    // 8005CA70: cmpwi   r0, 20
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(20);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA74:
    ctx->pc = 0x8005CA74u;
    // 8005CA74: bc    12, 2, 0x8005CFD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CFD8;
        }
    }

label_8005CA78:
    ctx->pc = 0x8005CA78u;
    ctx->downcount -= 1;
    // 8005CA78: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CA7C:
    ctx->pc = 0x8005CA7Cu;
    ctx->downcount -= 2;
    // 8005CA7C: cmpwi   r0, 23
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(23);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA80:
    ctx->pc = 0x8005CA80u;
    // 8005CA80: bc    12, 2, 0x8005D15C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D15C;
        }
    }

label_8005CA84:
    ctx->pc = 0x8005CA84u;
    ctx->downcount -= 1;
    // 8005CA84: bc    12, 0, 0x8005CFC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CFC0;
        }
    }

label_8005CA88:
    ctx->pc = 0x8005CA88u;
    ctx->downcount -= 2;
    // 8005CA88: cmpwi   r0, 24
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(24);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CA8C:
    ctx->pc = 0x8005CA8Cu;
    // 8005CA8C: bc    12, 2, 0x8005D11C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D11C;
        }
    }

label_8005CA90:
    ctx->pc = 0x8005CA90u;
    ctx->downcount -= 1;
    // 8005CA90: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CA94:
    ctx->pc = 0x8005CA94u;
    ctx->downcount -= 4;
    // 8005CA94: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_8005CA98:
    ctx->pc = 0x8005CA98u;
    // 8005CA98: addi    r3, r3, 21684
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(21684);

label_8005CA9C:
    ctx->pc = 0x8005CA9Cu;
    // 8005CA9C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005CAA0:
    ctx->pc = 0x8005CAA0u;
    // 8005CAA0: bl      0x80166EF4
    {
            ctx->lr = 0x8005CAA4u;
            ctx->pc = 0x80166EF4u;
            return;
    }

label_8005CAA4:
    ctx->downcount -= 1;
    // 8005CAA4: b       0x8005CAA4
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005CAA4u;
                return;
            }
            goto label_8005CAA4;
    }

label_8005CAA8:
    ctx->pc = 0x8005CAA8u;
    ctx->downcount -= 19;
    // 8005CAA8: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005CAAC:
    ctx->pc = 0x8005CAACu;
    // 8005CAAC: lwz     r30, 160(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(160);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8005CAB0:
    ctx->pc = 0x8005CAB0u;
    // 8005CAB0: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005CAB4:
    ctx->pc = 0x8005CAB4u;
    // 8005CAB4: lwz     r0, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CAB8:
    ctx->pc = 0x8005CAB8u;
    // 8005CAB8: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CABC:
    ctx->pc = 0x8005CABCu;
    // 8005CABC: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005CAC0:
    ctx->pc = 0x8005CAC0u;
    // 8005CAC0: lwz     r7, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005CAC4:
    ctx->pc = 0x8005CAC4u;
    // 8005CAC4: andc   r11, r0, r11
    {
        ctx->gpr[11] = ctx->gpr[0] & ~ctx->gpr[11];
    }

label_8005CAC8:
    ctx->pc = 0x8005CAC8u;
    // 8005CAC8: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005CACC:
    ctx->pc = 0x8005CACCu;
    // 8005CACC: lwz     r6, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005CAD0:
    ctx->pc = 0x8005CAD0u;
    // 8005CAD0: andc   r10, r7, r10
    {
        ctx->gpr[10] = ctx->gpr[7] & ~ctx->gpr[10];
    }

label_8005CAD4:
    ctx->pc = 0x8005CAD4u;
    // 8005CAD4: lwz     r5, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005CAD8:
    ctx->pc = 0x8005CAD8u;
    // 8005CAD8: or   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[10];
    }

label_8005CADC:
    ctx->pc = 0x8005CADCu;
    // 8005CADC: lwz     r0, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CAE0:
    ctx->pc = 0x8005CAE0u;
    // 8005CAE0: andc   r8, r6, r8
    {
        ctx->gpr[8] = ctx->gpr[6] & ~ctx->gpr[8];
    }

label_8005CAE4:
    ctx->pc = 0x8005CAE4u;
    // 8005CAE4: or   r11, r11, r8
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[8];
    }

label_8005CAE8:
    ctx->pc = 0x8005CAE8u;
    // 8005CAE8: andc   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] & ~ctx->gpr[0];
    }

label_8005CAEC:
    ctx->pc = 0x8005CAECu;
    // 8005CAEC: or   r29, r11, r0
    {
        ctx->gpr[29] = ctx->gpr[11] | ctx->gpr[0];
    }

label_8005CAF0:
    ctx->pc = 0x8005CAF0u;
    // 8005CAF0: b       0x8005CAF8
    {
            goto label_8005CAF8;
    }

label_8005CAF4:
    ctx->downcount -= 1;
    // 8005CAF4: addi    r30, r30, 8
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(8);

label_8005CAF8:
    ctx->pc = 0x8005CAF8u;
    ctx->downcount -= 3;
    // 8005CAF8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CAFC:
    // 8005CAFC: cmpwi   r0, 0
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

label_8005CB00:
    // 8005CB00: bc    12, 2, 0x8005CB50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CB50;
        }
    }

label_8005CB04:
    ctx->downcount -= 2;
    // 8005CB04: and.   r9, r29, r0
    {
        ctx->gpr[9] = ctx->gpr[29] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005CB08:
    // 8005CB08: bc    12, 2, 0x8005CAF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005CAF4u;
                return;
            }
            goto label_8005CAF4;
        }
    }

label_8005CB0C:
    ctx->pc = 0x8005CB0Cu;
    ctx->downcount -= 5;
    // 8005CB0C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005CB10:
    ctx->pc = 0x8005CB10u;
    // 8005CB10: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8005CB14:
    ctx->pc = 0x8005CB14u;
    // 8005CB14: lfs     f1, 22504(r9)
    if (!ppc_fp_available(ctx, 0x8005CB14u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005CB18:
    ctx->pc = 0x8005CB18u;
    // 8005CB18: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_8005CB1C:
    ctx->pc = 0x8005CB1Cu;
    // 8005CB1C: bl      0x8004DC00
    {
            ctx->lr = 0x8005CB20u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8005CB20:
    ctx->pc = 0x8005CB20u;
    ctx->downcount -= 3;
    // 8005CB20: lwz     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CB24:
    ctx->pc = 0x8005CB24u;
    // 8005CB24: cmpwi   r0, 12
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(12);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005CB28:
    ctx->pc = 0x8005CB28u;
    // 8005CB28: bc    4, 2, 0x8005CB3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005CB3C;
        }
    }

label_8005CB2C:
    ctx->pc = 0x8005CB2Cu;
    ctx->downcount -= 3;
    // 8005CB2C: lwz     r3, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005CB30:
    ctx->pc = 0x8005CB30u;
    // 8005CB30: and   r3, r29, r3
    {
        ctx->gpr[3] = ctx->gpr[29] & ctx->gpr[3];
    }

label_8005CB34:
    ctx->pc = 0x8005CB34u;
    // 8005CB34: bl      0x8004427C
    {
            ctx->lr = 0x8005CB38u;
            ctx->pc = 0x8004427Cu;
            return;
    }

label_8005CB38:
    ctx->pc = 0x8005CB38u;
    ctx->downcount -= 1;
    // 8005CB38: stw     r3, -32304(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32304);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005CB3C:
    ctx->pc = 0x8005CB3Cu;
    ctx->downcount -= 3;
    // 8005CB3C: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_8005CB40:
    ctx->pc = 0x8005CB40u;
    // 8005CB40: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005CB44:
    ctx->pc = 0x8005CB44u;
    // 8005CB44: bl      0x80044410
    {
            ctx->lr = 0x8005CB48u;
            ctx->pc = 0x80044410u;
            return;
    }

label_8005CB48:
    ctx->pc = 0x8005CB48u;
    ctx->downcount -= 2;
    // 8005CB48: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CB4C:
    ctx->pc = 0x8005CB4Cu;
    // 8005CB4C: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CB50:
    ctx->pc = 0x8005CB50u;
    ctx->downcount -= 19;
    // 8005CB50: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CB54:
    ctx->pc = 0x8005CB54u;
    // 8005CB54: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_8005CB58:
    ctx->pc = 0x8005CB58u;
    // 8005CB58: lwz     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CB5C:
    ctx->pc = 0x8005CB5Cu;
    // 8005CB5C: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005CB60:
    ctx->pc = 0x8005CB60u;
    // 8005CB60: or   r8, r10, r10
    {
        ctx->gpr[8] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8005CB64:
    ctx->pc = 0x8005CB64u;
    // 8005CB64: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CB68:
    ctx->pc = 0x8005CB68u;
    // 8005CB68: xoris   r11, r11, 0x8000
    ctx->gpr[11] = ctx->gpr[11] ^ (0x8000u << 16);

label_8005CB6C:
    ctx->pc = 0x8005CB6Cu;
    // 8005CB6C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005CB70:
    ctx->pc = 0x8005CB70u;
    // 8005CB70: stw     r7, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005CB74:
    ctx->pc = 0x8005CB74u;
    // 8005CB74: lfd     f0, 22512(r9)
    if (!ppc_fp_available(ctx, 0x8005CB74u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22512);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005CB78:
    ctx->pc = 0x8005CB78u;
    // 8005CB78: lfd     f1, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005CB78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005CB7C:
    ctx->pc = 0x8005CB7Cu;
    // 8005CB7C: stw     r11, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005CB80:
    ctx->pc = 0x8005CB80u;
    // 8005CB80: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x8005CB80u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_8005CB84:
    ctx->pc = 0x8005CB84u;
    // 8005CB84: stw     r7, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005CB88:
    ctx->pc = 0x8005CB88u;
    // 8005CB88: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x8005CB88u)) return;
    ppc_frsp(ctx, 1, 1);

label_8005CB8C:
    ctx->pc = 0x8005CB8Cu;
    // 8005CB8C: lfd     f2, 16(r1)
    if (!ppc_fp_available(ctx, 0x8005CB8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005CB90:
    ctx->pc = 0x8005CB90u;
    // 8005CB90: fsub   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x8005CB90u)) return;
    ppc_fsub(ctx, 2, 2, 0);

label_8005CB94:
    ctx->pc = 0x8005CB94u;
    // 8005CB94: frsp    f2, f2
    if (!ppc_fp_available(ctx, 0x8005CB94u)) return;
    ppc_frsp(ctx, 2, 2);

label_8005CB98:
    ctx->pc = 0x8005CB98u;
    // 8005CB98: bl      0x80133520
    {
            ctx->lr = 0x8005CB9Cu;
            ctx->pc = 0x80133520u;
            return;
    }

label_8005CB9C:
    ctx->pc = 0x8005CB9Cu;
    ctx->downcount -= 1;
    // 8005CB9C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CBA0:
    ctx->pc = 0x8005CBA0u;
    ctx->downcount -= 5;
    // 8005CBA0: lwz     r9, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005CBA4:
    ctx->pc = 0x8005CBA4u;
    // 8005CBA4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_8005CBA8:
    ctx->pc = 0x8005CBA8u;
    // 8005CBA8: cmpwi   r9, 0
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

label_8005CBAC:
    ctx->pc = 0x8005CBACu;
    // 8005CBAC: stw     r9, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005CBB0:
    ctx->pc = 0x8005CBB0u;
    // 8005CBB0: bc    12, 1, 0x8005D358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D358;
        }
    }

label_8005CBB4:
    ctx->pc = 0x8005CBB4u;
    ctx->downcount -= 6;
    // 8005CBB4: lwz     r9, 132(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(132);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005CBB8:
    ctx->pc = 0x8005CBB8u;
    // 8005CBB8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005CBBC:
    ctx->pc = 0x8005CBBCu;
    // 8005CBBC: stw     r0, 132(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CBC0:
    ctx->pc = 0x8005CBC0u;
    // 8005CBC0: stw     r9, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005CBC4:
    ctx->pc = 0x8005CBC4u;
    // 8005CBC4: stw     r0, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CBC8:
    ctx->pc = 0x8005CBC8u;
    // 8005CBC8: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CBCC:
    ctx->pc = 0x8005CBCCu;
    ctx->downcount -= 5;
    // 8005CBCC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005CBD0:
    ctx->pc = 0x8005CBD0u;
    // 8005CBD0: lwz     r9, 148(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005CBD4:
    ctx->pc = 0x8005CBD4u;
    // 8005CBD4: stw     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CBD8:
    ctx->pc = 0x8005CBD8u;
    // 8005CBD8: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_8005CBDC:
    ctx->pc = 0x8005CBDCu;
    // 8005CBDC: b       0x8005CBE8
    {
            goto label_8005CBE8;
    }

label_8005CBE0:
    loop_8005CBE0(ctx);
    if (ctx->pc == 0x8005CBF4u) goto label_8005CBF4;
    return;
label_8005CBE4:
    // 8005CBE4: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_8005CBE8:
    ctx->pc = 0x8005CBE8u;
    ctx->downcount -= 3;
    // 8005CBE8: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CBEC:
    // 8005CBEC: cmpwi   r0, 0
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

label_8005CBF0:
    // 8005CBF0: bc    4, 2, 0x8005CBE0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005CBE0u;
                return;
            }
            goto label_8005CBE0;
        }
    }

label_8005CBF4:
    ctx->pc = 0x8005CBF4u;
    ctx->downcount -= 28;
    // 8005CBF4: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005CBF8:
    ctx->pc = 0x8005CBF8u;
    // 8005CBF8: lis     r7, 16
    ctx->gpr[7] = ((u32)(s32)(16) << 16);

label_8005CBFC:
    ctx->pc = 0x8005CBFCu;
    // 8005CBFC: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005CC00:
    ctx->pc = 0x8005CC00u;
    // 8005CC00: ori     r7, r7, 0x0001
    ctx->gpr[7] = ctx->gpr[7] | 0x0001u;

label_8005CC04:
    ctx->pc = 0x8005CC04u;
    // 8005CC04: lwz     r6, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005CC08:
    ctx->pc = 0x8005CC08u;
    // 8005CC08: lwz     r5, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005CC0C:
    ctx->pc = 0x8005CC0Cu;
    // 8005CC0C: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CC10:
    ctx->pc = 0x8005CC10u;
    // 8005CC10: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005CC14:
    ctx->pc = 0x8005CC14u;
    // 8005CC14: lwz     r3, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005CC18:
    ctx->pc = 0x8005CC18u;
    // 8005CC18: xor   r11, r11, r6
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[6];
    }

label_8005CC1C:
    ctx->pc = 0x8005CC1Cu;
    // 8005CC1C: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005CC20:
    ctx->pc = 0x8005CC20u;
    // 8005CC20: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_8005CC24:
    ctx->pc = 0x8005CC24u;
    // 8005CC24: lwz     r4, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005CC28:
    ctx->pc = 0x8005CC28u;
    // 8005CC28: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_8005CC2C:
    ctx->pc = 0x8005CC2Cu;
    // 8005CC2C: lwz     r0, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CC30:
    ctx->pc = 0x8005CC30u;
    // 8005CC30: xor   r8, r8, r3
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[3];
    }

label_8005CC34:
    ctx->pc = 0x8005CC34u;
    // 8005CC34: and   r10, r10, r7
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[7];
    }

label_8005CC38:
    ctx->pc = 0x8005CC38u;
    // 8005CC38: and   r11, r11, r6
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[6];
    }

label_8005CC3C:
    ctx->pc = 0x8005CC3Cu;
    // 8005CC3C: and   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[5];
    }

label_8005CC40:
    ctx->pc = 0x8005CC40u;
    // 8005CC40: xor   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[4];
    }

label_8005CC44:
    ctx->pc = 0x8005CC44u;
    // 8005CC44: and   r8, r8, r7
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[7];
    }

label_8005CC48:
    ctx->pc = 0x8005CC48u;
    // 8005CC48: or   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[10];
    }

label_8005CC4C:
    ctx->pc = 0x8005CC4Cu;
    // 8005CC4C: and   r8, r8, r3
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[3];
    }

label_8005CC50:
    ctx->pc = 0x8005CC50u;
    // 8005CC50: and   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[7];
    }

label_8005CC54:
    ctx->pc = 0x8005CC54u;
    // 8005CC54: or   r11, r11, r8
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[8];
    }

label_8005CC58:
    ctx->pc = 0x8005CC58u;
    // 8005CC58: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_8005CC5C:
    ctx->pc = 0x8005CC5Cu;
    // 8005CC5C: or.   r9, r11, r0
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005CC60:
    ctx->pc = 0x8005CC60u;
    // 8005CC60: bc    12, 2, 0x8005CC90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CC90;
        }
    }

label_8005CC64:
    ctx->pc = 0x8005CC64u;
    ctx->downcount -= 3;
    // 8005CC64: lwz     r11, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CC68:
    ctx->pc = 0x8005CC68u;
    // 8005CC68: cmpwi   r11, 0
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

label_8005CC6C:
    ctx->pc = 0x8005CC6Cu;
    // 8005CC6C: bc    4, 1, 0x8005CC90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005CC90;
        }
    }

label_8005CC70:
    ctx->pc = 0x8005CC70u;
    ctx->downcount -= 7;
    // 8005CC70: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005CC74:
    ctx->pc = 0x8005CC74u;
    // 8005CC74: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_8005CC78:
    ctx->pc = 0x8005CC78u;
    // 8005CC78: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8005CC7C:
    ctx->pc = 0x8005CC7Cu;
    // 8005CC7C: lfs     f1, 22504(r9)
    if (!ppc_fp_available(ctx, 0x8005CC7Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005CC80:
    ctx->pc = 0x8005CC80u;
    // 8005CC80: stw     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CC84:
    ctx->pc = 0x8005CC84u;
    // 8005CC84: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8005CC88:
    ctx->pc = 0x8005CC88u;
    // 8005CC88: bl      0x8004DC00
    {
            ctx->lr = 0x8005CC8Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8005CC8C:
    ctx->pc = 0x8005CC8Cu;
    ctx->downcount -= 1;
    // 8005CC8C: b       0x8005CD2C
    {
            goto label_8005CD2C;
    }

label_8005CC90:
    ctx->pc = 0x8005CC90u;
    ctx->downcount -= 28;
    // 8005CC90: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005CC94:
    ctx->pc = 0x8005CC94u;
    // 8005CC94: lis     r7, 32
    ctx->gpr[7] = ((u32)(s32)(32) << 16);

label_8005CC98:
    ctx->pc = 0x8005CC98u;
    // 8005CC98: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005CC9C:
    ctx->pc = 0x8005CC9Cu;
    // 8005CC9C: ori     r7, r7, 0x0002
    ctx->gpr[7] = ctx->gpr[7] | 0x0002u;

label_8005CCA0:
    ctx->pc = 0x8005CCA0u;
    // 8005CCA0: lwz     r6, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005CCA4:
    ctx->pc = 0x8005CCA4u;
    // 8005CCA4: lwz     r5, 84(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(84);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005CCA8:
    ctx->pc = 0x8005CCA8u;
    // 8005CCA8: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CCAC:
    ctx->pc = 0x8005CCACu;
    // 8005CCAC: lwz     r10, 88(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(88);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005CCB0:
    ctx->pc = 0x8005CCB0u;
    // 8005CCB0: lwz     r3, 140(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005CCB4:
    ctx->pc = 0x8005CCB4u;
    // 8005CCB4: xor   r11, r11, r6
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[6];
    }

label_8005CCB8:
    ctx->pc = 0x8005CCB8u;
    // 8005CCB8: lwz     r8, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005CCBC:
    ctx->pc = 0x8005CCBCu;
    // 8005CCBC: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_8005CCC0:
    ctx->pc = 0x8005CCC0u;
    // 8005CCC0: lwz     r4, 196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(196);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005CCC4:
    ctx->pc = 0x8005CCC4u;
    // 8005CCC4: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_8005CCC8:
    ctx->pc = 0x8005CCC8u;
    // 8005CCC8: lwz     r0, 200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CCCC:
    ctx->pc = 0x8005CCCCu;
    // 8005CCCC: xor   r8, r8, r3
    {
        ctx->gpr[8] = ctx->gpr[8] ^ ctx->gpr[3];
    }

label_8005CCD0:
    ctx->pc = 0x8005CCD0u;
    // 8005CCD0: and   r10, r10, r7
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[7];
    }

label_8005CCD4:
    ctx->pc = 0x8005CCD4u;
    // 8005CCD4: and   r11, r11, r6
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[6];
    }

label_8005CCD8:
    ctx->pc = 0x8005CCD8u;
    // 8005CCD8: and   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[5];
    }

label_8005CCDC:
    ctx->pc = 0x8005CCDCu;
    // 8005CCDC: xor   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[4];
    }

label_8005CCE0:
    ctx->pc = 0x8005CCE0u;
    // 8005CCE0: and   r8, r8, r7
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[7];
    }

label_8005CCE4:
    ctx->pc = 0x8005CCE4u;
    // 8005CCE4: or   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[10];
    }

label_8005CCE8:
    ctx->pc = 0x8005CCE8u;
    // 8005CCE8: and   r8, r8, r3
    {
        ctx->gpr[8] = ctx->gpr[8] & ctx->gpr[3];
    }

label_8005CCEC:
    ctx->pc = 0x8005CCECu;
    // 8005CCEC: and   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[7];
    }

label_8005CCF0:
    ctx->pc = 0x8005CCF0u;
    // 8005CCF0: or   r11, r11, r8
    {
        ctx->gpr[11] = ctx->gpr[11] | ctx->gpr[8];
    }

label_8005CCF4:
    ctx->pc = 0x8005CCF4u;
    // 8005CCF4: and   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[4];
    }

label_8005CCF8:
    ctx->pc = 0x8005CCF8u;
    // 8005CCF8: or.   r9, r11, r0
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005CCFC:
    ctx->pc = 0x8005CCFCu;
    // 8005CCFC: bc    12, 2, 0x8005CD2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CD2C;
        }
    }

label_8005CD00:
    ctx->pc = 0x8005CD00u;
    ctx->downcount -= 4;
    // 8005CD00: lwz     r11, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CD04:
    ctx->pc = 0x8005CD04u;
    // 8005CD04: addi    r0, r30, -1
    ctx->gpr[0] = ctx->gpr[30] + (u32)(s32)(-1);

label_8005CD08:
    ctx->pc = 0x8005CD08u;
    // 8005CD08: cmpw    r11, r0
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

label_8005CD0C:
    ctx->pc = 0x8005CD0Cu;
    // 8005CD0C: bc    4, 0, 0x8005CD2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005CD2C;
        }
    }

label_8005CD10:
    ctx->pc = 0x8005CD10u;
    ctx->downcount -= 7;
    // 8005CD10: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005CD14:
    ctx->pc = 0x8005CD14u;
    // 8005CD14: addi    r0, r11, 1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(1);

label_8005CD18:
    ctx->pc = 0x8005CD18u;
    // 8005CD18: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8005CD1C:
    ctx->pc = 0x8005CD1Cu;
    // 8005CD1C: lfs     f1, 22504(r9)
    if (!ppc_fp_available(ctx, 0x8005CD1Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005CD20:
    ctx->pc = 0x8005CD20u;
    // 8005CD20: stw     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CD24:
    ctx->pc = 0x8005CD24u;
    // 8005CD24: ori     r3, r3, 0x03C3
    ctx->gpr[3] = ctx->gpr[3] | 0x03C3u;

label_8005CD28:
    ctx->pc = 0x8005CD28u;
    // 8005CD28: bl      0x8004DC00
    {
            ctx->lr = 0x8005CD2Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8005CD2C:
    ctx->pc = 0x8005CD2Cu;
    ctx->downcount -= 3;
    // 8005CD2C: lwz     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CD30:
    ctx->pc = 0x8005CD30u;
    // 8005CD30: cmpw    r0, r30
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

label_8005CD34:
    ctx->pc = 0x8005CD34u;
    // 8005CD34: bc    12, 0, 0x8005CD40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CD40;
        }
    }

label_8005CD38:
    ctx->pc = 0x8005CD38u;
    ctx->downcount -= 2;
    // 8005CD38: addi    r0, r30, -1
    ctx->gpr[0] = ctx->gpr[30] + (u32)(s32)(-1);

label_8005CD3C:
    ctx->pc = 0x8005CD3Cu;
    // 8005CD3C: stw     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CD40:
    ctx->pc = 0x8005CD40u;
    ctx->downcount -= 3;
    // 8005CD40: lwz     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CD44:
    ctx->pc = 0x8005CD44u;
    // 8005CD44: cmpwi   r0, 0
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

label_8005CD48:
    ctx->pc = 0x8005CD48u;
    // 8005CD48: bc    4, 0, 0x8005CD54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005CD54;
        }
    }

label_8005CD4C:
    ctx->pc = 0x8005CD4Cu;
    ctx->downcount -= 2;
    // 8005CD4C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005CD50:
    ctx->pc = 0x8005CD50u;
    // 8005CD50: stw     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CD54:
    ctx->pc = 0x8005CD54u;
    ctx->downcount -= 26;
    // 8005CD54: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005CD58:
    ctx->pc = 0x8005CD58u;
    // 8005CD58: addi    r30, r9, -21024
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005CD5C:
    ctx->pc = 0x8005CD5Cu;
    // 8005CD5C: lwz     r8, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005CD60:
    ctx->pc = 0x8005CD60u;
    // 8005CD60: lwz     r7, 84(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(84);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005CD64:
    ctx->pc = 0x8005CD64u;
    // 8005CD64: lwz     r9, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005CD68:
    ctx->pc = 0x8005CD68u;
    // 8005CD68: lwz     r11, 88(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CD6C:
    ctx->pc = 0x8005CD6Cu;
    // 8005CD6C: lwz     r5, 140(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005CD70:
    ctx->pc = 0x8005CD70u;
    // 8005CD70: xor   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] ^ ctx->gpr[8];
    }

label_8005CD74:
    ctx->pc = 0x8005CD74u;
    // 8005CD74: lwz     r10, 144(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005CD78:
    ctx->pc = 0x8005CD78u;
    // 8005CD78: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_8005CD7C:
    ctx->pc = 0x8005CD7Cu;
    // 8005CD7C: lwz     r6, 196(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(196);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005CD80:
    ctx->pc = 0x8005CD80u;
    // 8005CD80: rlwinm r9, r9, 0, 15, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00010000u;
    }

label_8005CD84:
    ctx->pc = 0x8005CD84u;
    // 8005CD84: lwz     r0, 200(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CD88:
    ctx->pc = 0x8005CD88u;
    // 8005CD88: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_8005CD8C:
    ctx->pc = 0x8005CD8Cu;
    // 8005CD8C: rlwinm r11, r11, 0, 15, 15
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00010000u;
    }

label_8005CD90:
    ctx->pc = 0x8005CD90u;
    // 8005CD90: and   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[8];
    }

label_8005CD94:
    ctx->pc = 0x8005CD94u;
    // 8005CD94: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_8005CD98:
    ctx->pc = 0x8005CD98u;
    // 8005CD98: xor   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[6];
    }

label_8005CD9C:
    ctx->pc = 0x8005CD9Cu;
    // 8005CD9C: rlwinm r10, r10, 0, 15, 15
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00010000u;
    }

label_8005CDA0:
    ctx->pc = 0x8005CDA0u;
    // 8005CDA0: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_8005CDA4:
    ctx->pc = 0x8005CDA4u;
    // 8005CDA4: and   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[5];
    }

label_8005CDA8:
    ctx->pc = 0x8005CDA8u;
    // 8005CDA8: rlwinm r0, r0, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00010000u;
    }

label_8005CDAC:
    ctx->pc = 0x8005CDACu;
    // 8005CDAC: or   r9, r9, r10
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[10];
    }

label_8005CDB0:
    ctx->pc = 0x8005CDB0u;
    // 8005CDB0: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_8005CDB4:
    ctx->pc = 0x8005CDB4u;
    // 8005CDB4: or.   r11, r9, r0
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005CDB8:
    ctx->pc = 0x8005CDB8u;
    // 8005CDB8: bc    12, 2, 0x8005CE04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CE04;
        }
    }

label_8005CDBC:
    ctx->pc = 0x8005CDBCu;
    ctx->downcount -= 17;
    // 8005CDBC: lwz     r9, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005CDC0:
    ctx->pc = 0x8005CDC0u;
    // 8005CDC0: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005CDC4:
    ctx->pc = 0x8005CDC4u;
    // 8005CDC4: lwz     r8, 148(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(148);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005CDC8:
    ctx->pc = 0x8005CDC8u;
    // 8005CDC8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8005CDCC:
    ctx->pc = 0x8005CDCCu;
    // 8005CDCC: mulli   r9, r9, 12
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)12);

label_8005CDD0:
    ctx->pc = 0x8005CDD0u;
    // 8005CDD0: lwz     r10, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005CDD4:
    ctx->pc = 0x8005CDD4u;
    // 8005CDD4: lfs     f1, 22504(r11)
    if (!ppc_fp_available(ctx, 0x8005CDD4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(22504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005CDD8:
    ctx->pc = 0x8005CDD8u;
    // 8005CDD8: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8005CDDC:
    ctx->pc = 0x8005CDDCu;
    // 8005CDDC: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_8005CDE0:
    ctx->pc = 0x8005CDE0u;
    // 8005CDE0: add   r9, r9, r8
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005CDE4:
    ctx->pc = 0x8005CDE4u;
    // 8005CDE4: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CDE8:
    ctx->pc = 0x8005CDE8u;
    // 8005CDE8: stw     r10, 136(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005CDEC:
    ctx->pc = 0x8005CDECu;
    // 8005CDEC: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CDF0:
    ctx->pc = 0x8005CDF0u;
    // 8005CDF0: stw     r7, 148(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005CDF4:
    ctx->pc = 0x8005CDF4u;
    // 8005CDF4: bl      0x8004DC00
    {
            ctx->lr = 0x8005CDF8u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8005CDF8:
    ctx->pc = 0x8005CDF8u;
    ctx->downcount -= 3;
    // 8005CDF8: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_8005CDFC:
    ctx->pc = 0x8005CDFCu;
    // 8005CDFC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005CE00:
    ctx->pc = 0x8005CE00u;
    // 8005CE00: bl      0x80044410
    {
            ctx->lr = 0x8005CE04u;
            ctx->pc = 0x80044410u;
            return;
    }

label_8005CE04:
    ctx->pc = 0x8005CE04u;
    ctx->downcount -= 24;
    // 8005CE04: lwz     r8, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005CE08:
    ctx->pc = 0x8005CE08u;
    // 8005CE08: lwz     r7, 84(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(84);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005CE0C:
    ctx->pc = 0x8005CE0Cu;
    // 8005CE0C: lwz     r9, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005CE10:
    ctx->pc = 0x8005CE10u;
    // 8005CE10: lwz     r11, 88(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(88);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005CE14:
    ctx->pc = 0x8005CE14u;
    // 8005CE14: lwz     r5, 140(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(140);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005CE18:
    ctx->pc = 0x8005CE18u;
    // 8005CE18: xor   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] ^ ctx->gpr[8];
    }

label_8005CE1C:
    ctx->pc = 0x8005CE1Cu;
    // 8005CE1C: lwz     r10, 144(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005CE20:
    ctx->pc = 0x8005CE20u;
    // 8005CE20: xor   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[7];
    }

label_8005CE24:
    ctx->pc = 0x8005CE24u;
    // 8005CE24: lwz     r6, 196(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(196);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005CE28:
    ctx->pc = 0x8005CE28u;
    // 8005CE28: rlwinm r9, r9, 0, 14, 14
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0x00020000u;
    }

label_8005CE2C:
    ctx->pc = 0x8005CE2Cu;
    // 8005CE2C: lwz     r0, 200(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(200);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CE30:
    ctx->pc = 0x8005CE30u;
    // 8005CE30: xor   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] ^ ctx->gpr[5];
    }

label_8005CE34:
    ctx->pc = 0x8005CE34u;
    // 8005CE34: rlwinm r11, r11, 0, 14, 14
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00020000u;
    }

label_8005CE38:
    ctx->pc = 0x8005CE38u;
    // 8005CE38: and   r9, r9, r8
    {
        ctx->gpr[9] = ctx->gpr[9] & ctx->gpr[8];
    }

label_8005CE3C:
    ctx->pc = 0x8005CE3Cu;
    // 8005CE3C: and   r11, r11, r7
    {
        ctx->gpr[11] = ctx->gpr[11] & ctx->gpr[7];
    }

label_8005CE40:
    ctx->pc = 0x8005CE40u;
    // 8005CE40: xor   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[6];
    }

label_8005CE44:
    ctx->pc = 0x8005CE44u;
    // 8005CE44: rlwinm r10, r10, 0, 14, 14
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0x00020000u;
    }

label_8005CE48:
    ctx->pc = 0x8005CE48u;
    // 8005CE48: or   r9, r9, r11
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[11];
    }

label_8005CE4C:
    ctx->pc = 0x8005CE4Cu;
    // 8005CE4C: and   r10, r10, r5
    {
        ctx->gpr[10] = ctx->gpr[10] & ctx->gpr[5];
    }

label_8005CE50:
    ctx->pc = 0x8005CE50u;
    // 8005CE50: rlwinm r0, r0, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00020000u;
    }

label_8005CE54:
    ctx->pc = 0x8005CE54u;
    // 8005CE54: or   r9, r9, r10
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[10];
    }

label_8005CE58:
    ctx->pc = 0x8005CE58u;
    // 8005CE58: and   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[6];
    }

label_8005CE5C:
    ctx->pc = 0x8005CE5Cu;
    // 8005CE5C: or.   r11, r9, r0
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005CE60:
    ctx->pc = 0x8005CE60u;
    // 8005CE60: bc    12, 2, 0x8005D358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D358;
        }
    }

label_8005CE64:
    ctx->pc = 0x8005CE64u;
    ctx->downcount -= 3;
    // 8005CE64: lwz     r0, 152(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(152);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CE68:
    ctx->pc = 0x8005CE68u;
    // 8005CE68: cmpwi   r0, 0
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

label_8005CE6C:
    ctx->pc = 0x8005CE6Cu;
    // 8005CE6C: bc    12, 2, 0x8005D358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D358;
        }
    }

label_8005CE70:
    ctx->pc = 0x8005CE70u;
    ctx->downcount -= 6;
    // 8005CE70: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005CE74:
    ctx->pc = 0x8005CE74u;
    // 8005CE74: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8005CE78:
    ctx->pc = 0x8005CE78u;
    // 8005CE78: lfs     f1, 22504(r9)
    if (!ppc_fp_available(ctx, 0x8005CE78u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22504);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005CE7C:
    ctx->pc = 0x8005CE7Cu;
    // 8005CE7C: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_8005CE80:
    ctx->pc = 0x8005CE80u;
    // 8005CE80: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CE84:
    ctx->pc = 0x8005CE84u;
    // 8005CE84: bl      0x8004DC00
    {
            ctx->lr = 0x8005CE88u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8005CE88:
    ctx->pc = 0x8005CE88u;
    ctx->downcount -= 3;
    // 8005CE88: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_8005CE8C:
    ctx->pc = 0x8005CE8Cu;
    // 8005CE8C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005CE90:
    ctx->pc = 0x8005CE90u;
    // 8005CE90: bl      0x80044410
    {
            ctx->lr = 0x8005CE94u;
            ctx->pc = 0x80044410u;
            return;
    }

label_8005CE94:
    ctx->pc = 0x8005CE94u;
    ctx->downcount -= 1;
    // 8005CE94: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CE98:
    ctx->pc = 0x8005CE98u;
    ctx->downcount -= 5;
    // 8005CE98: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005CE9C:
    ctx->pc = 0x8005CE9Cu;
    // 8005CE9C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005CEA0:
    ctx->pc = 0x8005CEA0u;
    // 8005CEA0: addi    r5, r5, 21736
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21736);

label_8005CEA4:
    ctx->pc = 0x8005CEA4u;
    // 8005CEA4: li      r4, 4194
    ctx->gpr[4] = (u32)(s32)(4194);

label_8005CEA8:
    ctx->pc = 0x8005CEA8u;
    // 8005CEA8: bl      0x8005D3F0
    {
            ctx->lr = 0x8005CEACu;
            goto label_8005D3F0;
    }

label_8005CEAC:
    ctx->pc = 0x8005CEACu;
    ctx->downcount -= 3;
    // 8005CEAC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005CEB0:
    ctx->pc = 0x8005CEB0u;
    // 8005CEB0: li      r4, 200
    ctx->gpr[4] = (u32)(s32)(200);

label_8005CEB4:
    ctx->pc = 0x8005CEB4u;
    // 8005CEB4: b       0x8005D2EC
    {
            goto label_8005D2EC;
    }

label_8005CEB8:
    ctx->pc = 0x8005CEB8u;
    ctx->downcount -= 3;
    // 8005CEB8: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CEBC:
    ctx->pc = 0x8005CEBCu;
    // 8005CEBC: cmpwi   r0, 2
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

label_8005CEC0:
    ctx->pc = 0x8005CEC0u;
    // 8005CEC0: bc    12, 2, 0x8005D2F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D2F8;
        }
    }

label_8005CEC4:
    ctx->pc = 0x8005CEC4u;
    ctx->downcount -= 3;
    // 8005CEC4: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8005CEC8:
    ctx->pc = 0x8005CEC8u;
    // 8005CEC8: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CECC:
    ctx->pc = 0x8005CECCu;
    // 8005CECC: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CED0:
    ctx->pc = 0x8005CED0u;
    ctx->downcount -= 6;
    // 8005CED0: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005CED4:
    ctx->pc = 0x8005CED4u;
    // 8005CED4: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8005CED8:
    ctx->pc = 0x8005CED8u;
    // 8005CED8: sth     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005CEDC:
    ctx->pc = 0x8005CEDCu;
    // 8005CEDC: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005CEE0:
    ctx->pc = 0x8005CEE0u;
    // 8005CEE0: stw     r11, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005CEE4:
    ctx->pc = 0x8005CEE4u;
    // 8005CEE4: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CEE8:
    ctx->pc = 0x8005CEE8u;
    ctx->downcount -= 3;
    // 8005CEE8: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CEEC:
    ctx->pc = 0x8005CEECu;
    // 8005CEEC: cmpwi   r0, 1
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

label_8005CEF0:
    ctx->pc = 0x8005CEF0u;
    // 8005CEF0: bc    12, 2, 0x8005CF10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CF10;
        }
    }

label_8005CEF4:
    ctx->pc = 0x8005CEF4u;
    ctx->downcount -= 1;
    // 8005CEF4: bc    12, 1, 0x8005CF04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CF04;
        }
    }

label_8005CEF8:
    ctx->pc = 0x8005CEF8u;
    ctx->downcount -= 2;
    // 8005CEF8: cmpwi   r0, 0
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

label_8005CEFC:
    ctx->pc = 0x8005CEFCu;
    // 8005CEFC: bc    12, 2, 0x8005CF20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CF20;
        }
    }

label_8005CF00:
    ctx->pc = 0x8005CF00u;
    ctx->downcount -= 1;
    // 8005CF00: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CF04:
    ctx->pc = 0x8005CF04u;
    ctx->downcount -= 2;
    // 8005CF04: cmpwi   r0, 2
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

label_8005CF08:
    ctx->pc = 0x8005CF08u;
    // 8005CF08: bc    12, 2, 0x8005D2F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D2F8;
        }
    }

label_8005CF0C:
    ctx->pc = 0x8005CF0Cu;
    ctx->downcount -= 1;
    // 8005CF0C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CF10:
    ctx->pc = 0x8005CF10u;
    ctx->downcount -= 4;
    // 8005CF10: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005CF14:
    ctx->pc = 0x8005CF14u;
    // 8005CF14: li      r0, 10
    ctx->gpr[0] = (u32)(s32)(10);

label_8005CF18:
    ctx->pc = 0x8005CF18u;
    // 8005CF18: sth     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005CF1C:
    ctx->pc = 0x8005CF1Cu;
    // 8005CF1C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CF20:
    ctx->pc = 0x8005CF20u;
    ctx->downcount -= 4;
    // 8005CF20: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005CF24:
    ctx->pc = 0x8005CF24u;
    // 8005CF24: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_8005CF28:
    ctx->pc = 0x8005CF28u;
    // 8005CF28: sth     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005CF2C:
    ctx->pc = 0x8005CF2Cu;
    // 8005CF2C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CF30:
    ctx->pc = 0x8005CF30u;
    ctx->downcount -= 3;
    // 8005CF30: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CF34:
    ctx->pc = 0x8005CF34u;
    // 8005CF34: cmpwi   r0, 2
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

label_8005CF38:
    ctx->pc = 0x8005CF38u;
    // 8005CF38: bc    4, 2, 0x8005CF8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005CF8C;
        }
    }

label_8005CF3C:
    ctx->pc = 0x8005CF3Cu;
    ctx->downcount -= 3;
    // 8005CF3C: lwz     r0, -27920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27920);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CF40:
    ctx->pc = 0x8005CF40u;
    // 8005CF40: cmpwi   r0, 0
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

label_8005CF44:
    ctx->pc = 0x8005CF44u;
    // 8005CF44: bc    4, 0, 0x8005CF54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005CF54;
        }
    }

label_8005CF48:
    ctx->pc = 0x8005CF48u;
    ctx->downcount -= 3;
    // 8005CF48: li      r0, 19
    ctx->gpr[0] = (u32)(s32)(19);

label_8005CF4C:
    ctx->pc = 0x8005CF4Cu;
    // 8005CF4C: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CF50:
    ctx->pc = 0x8005CF50u;
    // 8005CF50: b       0x8005CFB0
    {
            goto label_8005CFB0;
    }

label_8005CF54:
    ctx->pc = 0x8005CF54u;
    ctx->downcount -= 5;
    // 8005CF54: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005CF58:
    ctx->pc = 0x8005CF58u;
    // 8005CF58: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005CF5C:
    ctx->pc = 0x8005CF5Cu;
    // 8005CF5C: addi    r5, r5, 21744
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21744);

label_8005CF60:
    ctx->pc = 0x8005CF60u;
    // 8005CF60: li      r4, 4198
    ctx->gpr[4] = (u32)(s32)(4198);

label_8005CF64:
    ctx->pc = 0x8005CF64u;
    // 8005CF64: bl      0x8005D3F0
    {
            ctx->lr = 0x8005CF68u;
            goto label_8005D3F0;
    }

label_8005CF68:
    ctx->pc = 0x8005CF68u;
    ctx->downcount -= 3;
    // 8005CF68: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CF6C:
    ctx->pc = 0x8005CF6Cu;
    // 8005CF6C: andis.  r9, r0, 0x4000
    {
        ctx->gpr[9] = ctx->gpr[0] & (0x4000u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005CF70:
    ctx->pc = 0x8005CF70u;
    // 8005CF70: bc    12, 2, 0x8005CF80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005CF80;
        }
    }

label_8005CF74:
    ctx->pc = 0x8005CF74u;
    ctx->downcount -= 3;
    // 8005CF74: li      r0, 38
    ctx->gpr[0] = (u32)(s32)(38);

label_8005CF78:
    ctx->pc = 0x8005CF78u;
    // 8005CF78: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CF7C:
    ctx->pc = 0x8005CF7Cu;
    // 8005CF7C: b       0x8005CFB0
    {
            goto label_8005CFB0;
    }

label_8005CF80:
    ctx->pc = 0x8005CF80u;
    ctx->downcount -= 3;
    // 8005CF80: li      r0, 37
    ctx->gpr[0] = (u32)(s32)(37);

label_8005CF84:
    ctx->pc = 0x8005CF84u;
    // 8005CF84: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CF88:
    ctx->pc = 0x8005CF88u;
    // 8005CF88: b       0x8005CFB0
    {
            goto label_8005CFB0;
    }

label_8005CF8C:
    ctx->pc = 0x8005CF8Cu;
    ctx->downcount -= 5;
    // 8005CF8C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005CF90:
    ctx->pc = 0x8005CF90u;
    // 8005CF90: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005CF94:
    ctx->pc = 0x8005CF94u;
    // 8005CF94: addi    r5, r5, 21744
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21744);

label_8005CF98:
    ctx->pc = 0x8005CF98u;
    // 8005CF98: li      r4, 4198
    ctx->gpr[4] = (u32)(s32)(4198);

label_8005CF9C:
    ctx->pc = 0x8005CF9Cu;
    // 8005CF9C: bl      0x8005D3F0
    {
            ctx->lr = 0x8005CFA0u;
            goto label_8005D3F0;
    }

label_8005CFA0:
    ctx->pc = 0x8005CFA0u;
    ctx->downcount -= 4;
    // 8005CFA0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005CFA4:
    ctx->pc = 0x8005CFA4u;
    // 8005CFA4: li      r4, 10
    ctx->gpr[4] = (u32)(s32)(10);

label_8005CFA8:
    ctx->pc = 0x8005CFA8u;
    // 8005CFA8: li      r5, 22
    ctx->gpr[5] = (u32)(s32)(22);

label_8005CFAC:
    ctx->pc = 0x8005CFACu;
    // 8005CFAC: bl      0x8005C934
    {
            ctx->lr = 0x8005CFB0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005CFB0:
    ctx->pc = 0x8005CFB0u;
    ctx->downcount -= 4;
    // 8005CFB0: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CFB4:
    ctx->pc = 0x8005CFB4u;
    // 8005CFB4: oris    r0, r0, 0x4000
    ctx->gpr[0] = ctx->gpr[0] | (0x4000u << 16);

label_8005CFB8:
    ctx->pc = 0x8005CFB8u;
    // 8005CFB8: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CFBC:
    ctx->pc = 0x8005CFBCu;
    // 8005CFBC: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CFC0:
    ctx->pc = 0x8005CFC0u;
    ctx->downcount -= 1;
    // 8005CFC0: bl      0x80014C80
    {
            ctx->lr = 0x8005CFC4u;
            ctx->pc = 0x80014C80u;
            return;
    }

label_8005CFC4:
    ctx->pc = 0x8005CFC4u;
    ctx->downcount -= 4;
    // 8005CFC4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005CFC8:
    ctx->pc = 0x8005CFC8u;
    // 8005CFC8: li      r4, 100
    ctx->gpr[4] = (u32)(s32)(100);

label_8005CFCC:
    ctx->pc = 0x8005CFCCu;
    // 8005CFCC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005CFD0:
    ctx->pc = 0x8005CFD0u;
    // 8005CFD0: bl      0x8005C934
    {
            ctx->lr = 0x8005CFD4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005CFD4:
    ctx->pc = 0x8005CFD4u;
    ctx->downcount -= 1;
    // 8005CFD4: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CFD8:
    ctx->pc = 0x8005CFD8u;
    ctx->downcount -= 2;
    // 8005CFD8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005CFDC:
    ctx->pc = 0x8005CFDCu;
    // 8005CFDC: bl      0x80014CA0
    {
            ctx->lr = 0x8005CFE0u;
            ctx->pc = 0x80014CA0u;
            return;
    }

label_8005CFE0:
    ctx->pc = 0x8005CFE0u;
    ctx->downcount -= 4;
    // 8005CFE0: li      r0, 21
    ctx->gpr[0] = (u32)(s32)(21);

label_8005CFE4:
    ctx->pc = 0x8005CFE4u;
    // 8005CFE4: stw     r3, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005CFE8:
    ctx->pc = 0x8005CFE8u;
    // 8005CFE8: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005CFEC:
    ctx->pc = 0x8005CFECu;
    // 8005CFEC: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005CFF0:
    ctx->pc = 0x8005CFF0u;
    ctx->downcount -= 3;
    // 8005CFF0: lwz     r0, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005CFF4:
    ctx->pc = 0x8005CFF4u;
    // 8005CFF4: cmpwi   r0, 0
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

label_8005CFF8:
    ctx->pc = 0x8005CFF8u;
    // 8005CFF8: bc    12, 2, 0x8005D358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D358;
        }
    }

label_8005CFFC:
    ctx->pc = 0x8005CFFCu;
    ctx->downcount -= 1;
    // 8005CFFC: bc    4, 1, 0x8005D040
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D040;
        }
    }

label_8005D000:
    ctx->pc = 0x8005D000u;
    ctx->downcount -= 2;
    // 8005D000: cmpwi   r0, 2
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

label_8005D004:
    ctx->pc = 0x8005D004u;
    // 8005D004: bc    4, 2, 0x8005D01C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D01C;
        }
    }

label_8005D008:
    ctx->pc = 0x8005D008u;
    ctx->downcount -= 4;
    // 8005D008: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_8005D00C:
    ctx->pc = 0x8005D00Cu;
    // 8005D00C: addi    r3, r3, 21684
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(21684);

label_8005D010:
    ctx->pc = 0x8005D010u;
    // 8005D010: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005D014:
    ctx->pc = 0x8005D014u;
    // 8005D014: bl      0x80166EF4
    {
            ctx->lr = 0x8005D018u;
            ctx->pc = 0x80166EF4u;
            return;
    }

label_8005D018:
    ctx->downcount -= 1;
    // 8005D018: b       0x8005D018
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D018u;
                return;
            }
            goto label_8005D018;
    }

label_8005D01C:
    ctx->pc = 0x8005D01Cu;
    ctx->downcount -= 3;
    // 8005D01C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D020:
    ctx->pc = 0x8005D020u;
    // 8005D020: cmpwi   r0, 0
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

label_8005D024:
    ctx->pc = 0x8005D024u;
    // 8005D024: bc    4, 2, 0x8005D034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D034;
        }
    }

label_8005D028:
    ctx->pc = 0x8005D028u;
    ctx->downcount -= 1;
    // 8005D028: bl      0x8003F258
    {
            ctx->lr = 0x8005D02Cu;
            ctx->pc = 0x8003F258u;
            return;
    }

label_8005D02C:
    ctx->pc = 0x8005D02Cu;
    ctx->downcount -= 2;
    // 8005D02C: cmpwi   r3, 0
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

label_8005D030:
    ctx->pc = 0x8005D030u;
    // 8005D030: bc    12, 0, 0x8005D0D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D0D4;
        }
    }

label_8005D034:
    ctx->pc = 0x8005D034u;
    ctx->downcount -= 3;
    // 8005D034: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8005D038:
    ctx->pc = 0x8005D038u;
    // 8005D038: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D03C:
    ctx->pc = 0x8005D03Cu;
    // 8005D03C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D040:
    ctx->pc = 0x8005D040u;
    ctx->downcount -= 3;
    // 8005D040: stw     r0, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D044:
    ctx->pc = 0x8005D044u;
    // 8005D044: cmpwi   r0, -98
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-98);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005D048:
    ctx->pc = 0x8005D048u;
    // 8005D048: bc    12, 2, 0x8005D07C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D07C;
        }
    }

label_8005D04C:
    ctx->pc = 0x8005D04Cu;
    ctx->downcount -= 1;
    // 8005D04C: bc    12, 1, 0x8005D05C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D05C;
        }
    }

label_8005D050:
    ctx->pc = 0x8005D050u;
    ctx->downcount -= 2;
    // 8005D050: cmpwi   r0, -99
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-99);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005D054:
    ctx->pc = 0x8005D054u;
    // 8005D054: bc    12, 2, 0x8005D070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D070;
        }
    }

label_8005D058:
    ctx->pc = 0x8005D058u;
    ctx->downcount -= 1;
    // 8005D058: b       0x8005D0EC
    {
            goto label_8005D0EC;
    }

label_8005D05C:
    ctx->pc = 0x8005D05Cu;
    ctx->downcount -= 2;
    // 8005D05C: cmpwi   r0, -97
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-97);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005D060:
    ctx->pc = 0x8005D060u;
    // 8005D060: bc    12, 2, 0x8005D0C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D0C8;
        }
    }

label_8005D064:
    ctx->pc = 0x8005D064u;
    ctx->downcount -= 2;
    // 8005D064: cmpwi   r0, -91
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-91);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005D068:
    ctx->pc = 0x8005D068u;
    // 8005D068: bc    12, 2, 0x8005D088
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D088;
        }
    }

label_8005D06C:
    ctx->pc = 0x8005D06Cu;
    ctx->downcount -= 1;
    // 8005D06C: b       0x8005D0EC
    {
            goto label_8005D0EC;
    }

label_8005D070:
    ctx->pc = 0x8005D070u;
    ctx->downcount -= 3;
    // 8005D070: li      r0, 24
    ctx->gpr[0] = (u32)(s32)(24);

label_8005D074:
    ctx->pc = 0x8005D074u;
    // 8005D074: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D078:
    ctx->pc = 0x8005D078u;
    // 8005D078: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D07C:
    ctx->pc = 0x8005D07Cu;
    ctx->downcount -= 3;
    // 8005D07C: li      r0, 23
    ctx->gpr[0] = (u32)(s32)(23);

label_8005D080:
    ctx->pc = 0x8005D080u;
    // 8005D080: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D084:
    ctx->pc = 0x8005D084u;
    // 8005D084: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D088:
    ctx->pc = 0x8005D088u;
    ctx->downcount -= 5;
    // 8005D088: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D08C:
    ctx->pc = 0x8005D08Cu;
    // 8005D08C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D090:
    ctx->pc = 0x8005D090u;
    // 8005D090: addi    r5, r5, 21828
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21828);

label_8005D094:
    ctx->pc = 0x8005D094u;
    // 8005D094: li      r4, 4635
    ctx->gpr[4] = (u32)(s32)(4635);

label_8005D098:
    ctx->pc = 0x8005D098u;
    // 8005D098: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D09Cu;
            goto label_8005D3F0;
    }

label_8005D09C:
    ctx->pc = 0x8005D09Cu;
    ctx->downcount -= 3;
    // 8005D09C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D0A0:
    ctx->pc = 0x8005D0A0u;
    // 8005D0A0: cmpwi   r0, 0
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

label_8005D0A4:
    ctx->pc = 0x8005D0A4u;
    // 8005D0A4: bc    4, 2, 0x8005D0B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D0B8;
        }
    }

label_8005D0A8:
    ctx->pc = 0x8005D0A8u;
    ctx->downcount -= 4;
    // 8005D0A8: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D0AC:
    ctx->pc = 0x8005D0ACu;
    // 8005D0AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D0B0:
    ctx->pc = 0x8005D0B0u;
    // 8005D0B0: addi    r4, r4, 5036
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5036);

label_8005D0B4:
    ctx->pc = 0x8005D0B4u;
    // 8005D0B4: b       0x8005D1F8
    {
            goto label_8005D1F8;
    }

label_8005D0B8:
    ctx->pc = 0x8005D0B8u;
    ctx->downcount -= 4;
    // 8005D0B8: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D0BC:
    ctx->pc = 0x8005D0BCu;
    // 8005D0BC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D0C0:
    ctx->pc = 0x8005D0C0u;
    // 8005D0C0: addi    r4, r4, 5084
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5084);

label_8005D0C4:
    ctx->pc = 0x8005D0C4u;
    // 8005D0C4: b       0x8005D1F8
    {
            goto label_8005D1F8;
    }

label_8005D0C8:
    ctx->pc = 0x8005D0C8u;
    ctx->downcount -= 3;
    // 8005D0C8: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D0CC:
    ctx->pc = 0x8005D0CCu;
    // 8005D0CC: cmpwi   r0, 0
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

label_8005D0D0:
    ctx->pc = 0x8005D0D0u;
    // 8005D0D0: bc    4, 2, 0x8005D0E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D0E0;
        }
    }

label_8005D0D4:
    ctx->pc = 0x8005D0D4u;
    ctx->downcount -= 3;
    // 8005D0D4: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_8005D0D8:
    ctx->pc = 0x8005D0D8u;
    // 8005D0D8: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D0DC:
    ctx->pc = 0x8005D0DCu;
    // 8005D0DC: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D0E0:
    ctx->pc = 0x8005D0E0u;
    ctx->downcount -= 3;
    // 8005D0E0: li      r0, 31
    ctx->gpr[0] = (u32)(s32)(31);

label_8005D0E4:
    ctx->pc = 0x8005D0E4u;
    // 8005D0E4: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D0E8:
    ctx->pc = 0x8005D0E8u;
    // 8005D0E8: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D0EC:
    ctx->pc = 0x8005D0ECu;
    ctx->downcount -= 3;
    // 8005D0EC: li      r0, 26
    ctx->gpr[0] = (u32)(s32)(26);

label_8005D0F0:
    ctx->pc = 0x8005D0F0u;
    // 8005D0F0: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D0F4:
    ctx->pc = 0x8005D0F4u;
    // 8005D0F4: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D0F8:
    ctx->pc = 0x8005D0F8u;
    ctx->downcount -= 5;
    // 8005D0F8: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D0FC:
    ctx->pc = 0x8005D0FCu;
    // 8005D0FC: li      r4, 4636
    ctx->gpr[4] = (u32)(s32)(4636);

label_8005D100:
    ctx->pc = 0x8005D100u;
    // 8005D100: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D104:
    ctx->pc = 0x8005D104u;
    // 8005D104: addi    r5, r5, 21956
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21956);

label_8005D108:
    ctx->pc = 0x8005D108u;
    // 8005D108: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D10Cu;
            goto label_8005D3F0;
    }

label_8005D10C:
    ctx->pc = 0x8005D10Cu;
    ctx->downcount -= 4;
    // 8005D10C: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D110:
    ctx->pc = 0x8005D110u;
    // 8005D110: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D114:
    ctx->pc = 0x8005D114u;
    // 8005D114: addi    r4, r4, 5132
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5132);

label_8005D118:
    ctx->pc = 0x8005D118u;
    // 8005D118: b       0x8005D1F8
    {
            goto label_8005D1F8;
    }

label_8005D11C:
    ctx->pc = 0x8005D11Cu;
    ctx->downcount -= 5;
    // 8005D11C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D120:
    ctx->pc = 0x8005D120u;
    // 8005D120: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D124:
    ctx->pc = 0x8005D124u;
    // 8005D124: addi    r5, r5, 22020
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22020);

label_8005D128:
    ctx->pc = 0x8005D128u;
    // 8005D128: li      r4, 4199
    ctx->gpr[4] = (u32)(s32)(4199);

label_8005D12C:
    ctx->pc = 0x8005D12Cu;
    // 8005D12C: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D130u;
            goto label_8005D3F0;
    }

label_8005D130:
    ctx->pc = 0x8005D130u;
    ctx->downcount -= 3;
    // 8005D130: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D134:
    ctx->pc = 0x8005D134u;
    // 8005D134: cmpwi   r0, 0
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

label_8005D138:
    ctx->pc = 0x8005D138u;
    // 8005D138: bc    4, 2, 0x8005D14C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D14C;
        }
    }

label_8005D13C:
    ctx->pc = 0x8005D13Cu;
    ctx->downcount -= 4;
    // 8005D13C: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D140:
    ctx->pc = 0x8005D140u;
    // 8005D140: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D144:
    ctx->pc = 0x8005D144u;
    // 8005D144: addi    r4, r4, 5168
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5168);

label_8005D148:
    ctx->pc = 0x8005D148u;
    // 8005D148: b       0x8005D1F8
    {
            goto label_8005D1F8;
    }

label_8005D14C:
    ctx->pc = 0x8005D14Cu;
    ctx->downcount -= 4;
    // 8005D14C: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D150:
    ctx->pc = 0x8005D150u;
    // 8005D150: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D154:
    ctx->pc = 0x8005D154u;
    // 8005D154: addi    r4, r4, 5216
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5216);

label_8005D158:
    ctx->pc = 0x8005D158u;
    // 8005D158: b       0x8005D1F8
    {
            goto label_8005D1F8;
    }

label_8005D15C:
    ctx->pc = 0x8005D15Cu;
    ctx->downcount -= 5;
    // 8005D15C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D160:
    ctx->pc = 0x8005D160u;
    // 8005D160: li      r4, 4200
    ctx->gpr[4] = (u32)(s32)(4200);

label_8005D164:
    ctx->pc = 0x8005D164u;
    // 8005D164: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D168:
    ctx->pc = 0x8005D168u;
    // 8005D168: addi    r5, r5, 22156
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22156);

label_8005D16C:
    ctx->pc = 0x8005D16Cu;
    // 8005D16C: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D170u;
            goto label_8005D3F0;
    }

label_8005D170:
    ctx->pc = 0x8005D170u;
    ctx->downcount -= 6;
    // 8005D170: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D174:
    ctx->pc = 0x8005D174u;
    // 8005D174: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005D178:
    ctx->pc = 0x8005D178u;
    // 8005D178: addi    r4, r9, 5264
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(5264);

label_8005D17C:
    ctx->pc = 0x8005D17Cu;
    // 8005D17C: li      r11, 11
    ctx->gpr[11] = (u32)(s32)(11);

label_8005D180:
    ctx->pc = 0x8005D180u;
    // 8005D180: cmpwi   r0, 0
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

label_8005D184:
    ctx->pc = 0x8005D184u;
    // 8005D184: bc    4, 2, 0x8005D18C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D18C;
        }
    }

label_8005D188:
    ctx->pc = 0x8005D188u;
    ctx->downcount -= 1;
    // 8005D188: li      r11, 6
    ctx->gpr[11] = (u32)(s32)(6);

label_8005D18C:
    ctx->pc = 0x8005D18Cu;
    ctx->downcount -= 3;
    // 8005D18C: stw     r11, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005D190:
    ctx->pc = 0x8005D190u;
    // 8005D190: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D194:
    ctx->pc = 0x8005D194u;
    // 8005D194: b       0x8005D1F8
    {
            goto label_8005D1F8;
    }

label_8005D198:
    ctx->pc = 0x8005D198u;
    ctx->downcount -= 10;
    // 8005D198: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_8005D19C:
    ctx->pc = 0x8005D19Cu;
    // 8005D19C: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8005D1A0:
    ctx->pc = 0x8005D1A0u;
    // 8005D1A0: sth     r0, -21584(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005D1A4:
    ctx->pc = 0x8005D1A4u;
    // 8005D1A4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005D1A8:
    ctx->pc = 0x8005D1A8u;
    // 8005D1A8: stw     r9, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005D1AC:
    ctx->pc = 0x8005D1ACu;
    // 8005D1AC: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_8005D1B0:
    ctx->pc = 0x8005D1B0u;
    // 8005D1B0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005D1B4:
    ctx->pc = 0x8005D1B4u;
    // 8005D1B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005D1B8:
    ctx->pc = 0x8005D1B8u;
    // 8005D1B8: stw     r0, 11832(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(11832);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D1BC:
    ctx->pc = 0x8005D1BCu;
    // 8005D1BC: bl      0x8005B7BC
    {
            ctx->lr = 0x8005D1C0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B7BCu;
                return;
            }
            goto label_8005B7BC;
    }

label_8005D1C0:
    ctx->pc = 0x8005D1C0u;
    ctx->downcount -= 1;
    // 8005D1C0: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D1C4:
    ctx->pc = 0x8005D1C4u;
    ctx->downcount -= 5;
    // 8005D1C4: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D1C8:
    ctx->pc = 0x8005D1C8u;
    // 8005D1C8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D1CC:
    ctx->pc = 0x8005D1CCu;
    // 8005D1CC: addi    r5, r5, 22188
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22188);

label_8005D1D0:
    ctx->pc = 0x8005D1D0u;
    // 8005D1D0: li      r4, 4201
    ctx->gpr[4] = (u32)(s32)(4201);

label_8005D1D4:
    ctx->pc = 0x8005D1D4u;
    // 8005D1D4: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D1D8u;
            goto label_8005D3F0;
    }

label_8005D1D8:
    ctx->pc = 0x8005D1D8u;
    ctx->downcount -= 5;
    // 8005D1D8: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D1DC:
    ctx->pc = 0x8005D1DCu;
    // 8005D1DC: li      r4, 4659
    ctx->gpr[4] = (u32)(s32)(4659);

label_8005D1E0:
    ctx->pc = 0x8005D1E0u;
    // 8005D1E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D1E4:
    ctx->pc = 0x8005D1E4u;
    // 8005D1E4: addi    r5, r5, 22304
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22304);

label_8005D1E8:
    ctx->pc = 0x8005D1E8u;
    // 8005D1E8: bl      0x8005D48C
    {
            ctx->lr = 0x8005D1ECu;
            goto label_8005D48C;
    }

label_8005D1EC:
    ctx->pc = 0x8005D1ECu;
    ctx->downcount -= 3;
    // 8005D1EC: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D1F0:
    ctx->pc = 0x8005D1F0u;
    // 8005D1F0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D1F4:
    ctx->pc = 0x8005D1F4u;
    // 8005D1F4: addi    r4, r4, 5300
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5300);

label_8005D1F8:
    ctx->pc = 0x8005D1F8u;
    ctx->downcount -= 2;
    // 8005D1F8: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_8005D1FC:
    ctx->pc = 0x8005D1FCu;
    // 8005D1FC: bl      0x8005C950
    {
            ctx->lr = 0x8005D200u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005D200:
    ctx->pc = 0x8005D200u;
    ctx->downcount -= 1;
    // 8005D200: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D204:
    ctx->pc = 0x8005D204u;
    ctx->downcount -= 5;
    // 8005D204: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D208:
    ctx->pc = 0x8005D208u;
    // 8005D208: li      r4, 4198
    ctx->gpr[4] = (u32)(s32)(4198);

label_8005D20C:
    ctx->pc = 0x8005D20Cu;
    // 8005D20C: addi    r5, r5, 21744
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21744);

label_8005D210:
    ctx->pc = 0x8005D210u;
    // 8005D210: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D214:
    ctx->pc = 0x8005D214u;
    // 8005D214: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D218u;
            goto label_8005D3F0;
    }

label_8005D218:
    ctx->pc = 0x8005D218u;
    ctx->downcount -= 1;
    // 8005D218: bl      0x80014CC0
    {
            ctx->lr = 0x8005D21Cu;
            ctx->pc = 0x80014CC0u;
            return;
    }

label_8005D21C:
    ctx->pc = 0x8005D21Cu;
    ctx->downcount -= 4;
    // 8005D21C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D220:
    ctx->pc = 0x8005D220u;
    // 8005D220: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005D224:
    ctx->pc = 0x8005D224u;
    // 8005D224: li      r5, 16
    ctx->gpr[5] = (u32)(s32)(16);

label_8005D228:
    ctx->pc = 0x8005D228u;
    // 8005D228: bl      0x8005C934
    {
            ctx->lr = 0x8005D22Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005D22C:
    ctx->pc = 0x8005D22Cu;
    ctx->downcount -= 1;
    // 8005D22C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D230:
    ctx->pc = 0x8005D230u;
    ctx->downcount -= 5;
    // 8005D230: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D234:
    ctx->pc = 0x8005D234u;
    // 8005D234: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D238:
    ctx->pc = 0x8005D238u;
    // 8005D238: addi    r5, r5, 22340
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22340);

label_8005D23C:
    ctx->pc = 0x8005D23Cu;
    // 8005D23C: li      r4, 4202
    ctx->gpr[4] = (u32)(s32)(4202);

label_8005D240:
    ctx->pc = 0x8005D240u;
    // 8005D240: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D244u;
            goto label_8005D3F0;
    }

label_8005D244:
    ctx->pc = 0x8005D244u;
    ctx->downcount -= 6;
    // 8005D244: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005D248:
    ctx->pc = 0x8005D248u;
    // 8005D248: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005D24C:
    ctx->pc = 0x8005D24Cu;
    // 8005D24C: addi    r9, r9, 5336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(5336);

label_8005D250:
    ctx->pc = 0x8005D250u;
    // 8005D250: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D254:
    ctx->pc = 0x8005D254u;
    // 8005D254: stw     r9, 160(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005D258:
    ctx->pc = 0x8005D258u;
    // 8005D258: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D25C:
    ctx->pc = 0x8005D25Cu;
    ctx->downcount -= 1;
    // 8005D25C: bl      0x80014CE0
    {
            ctx->lr = 0x8005D260u;
            ctx->pc = 0x80014CE0u;
            return;
    }

label_8005D260:
    ctx->pc = 0x8005D260u;
    ctx->downcount -= 2;
    // 8005D260: or.   r3, r3, r3
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

label_8005D264:
    ctx->pc = 0x8005D264u;
    // 8005D264: bc    12, 2, 0x8005D358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D358;
        }
    }

label_8005D268:
    ctx->pc = 0x8005D268u;
    ctx->downcount -= 1;
    // 8005D268: bc    4, 1, 0x8005D280
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D280;
        }
    }

label_8005D26C:
    ctx->pc = 0x8005D26Cu;
    ctx->downcount -= 4;
    // 8005D26C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D270:
    ctx->pc = 0x8005D270u;
    // 8005D270: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8005D274:
    ctx->pc = 0x8005D274u;
    // 8005D274: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_8005D278:
    ctx->pc = 0x8005D278u;
    // 8005D278: bl      0x8005C934
    {
            ctx->lr = 0x8005D27Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005D27C:
    ctx->pc = 0x8005D27Cu;
    ctx->downcount -= 1;
    // 8005D27C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D280:
    ctx->pc = 0x8005D280u;
    ctx->downcount -= 3;
    // 8005D280: stw     r3, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005D284:
    ctx->pc = 0x8005D284u;
    // 8005D284: cmpwi   r3, -98
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-98);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005D288:
    ctx->pc = 0x8005D288u;
    // 8005D288: bc    12, 2, 0x8005D2A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D2A8;
        }
    }

label_8005D28C:
    ctx->pc = 0x8005D28Cu;
    ctx->downcount -= 2;
    // 8005D28C: cmpwi   r3, -94
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

label_8005D290:
    ctx->pc = 0x8005D290u;
    // 8005D290: bc    4, 2, 0x8005D2BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D2BC;
        }
    }

label_8005D294:
    ctx->pc = 0x8005D294u;
    ctx->downcount -= 4;
    // 8005D294: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D298:
    ctx->pc = 0x8005D298u;
    // 8005D298: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8005D29C:
    ctx->pc = 0x8005D29Cu;
    // 8005D29C: li      r5, 18
    ctx->gpr[5] = (u32)(s32)(18);

label_8005D2A0:
    ctx->pc = 0x8005D2A0u;
    // 8005D2A0: bl      0x8005C934
    {
            ctx->lr = 0x8005D2A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005D2A4:
    ctx->pc = 0x8005D2A4u;
    ctx->downcount -= 1;
    // 8005D2A4: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D2A8:
    ctx->pc = 0x8005D2A8u;
    ctx->downcount -= 4;
    // 8005D2A8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D2AC:
    ctx->pc = 0x8005D2ACu;
    // 8005D2AC: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8005D2B0:
    ctx->pc = 0x8005D2B0u;
    // 8005D2B0: li      r5, 17
    ctx->gpr[5] = (u32)(s32)(17);

label_8005D2B4:
    ctx->pc = 0x8005D2B4u;
    // 8005D2B4: bl      0x8005C934
    {
            ctx->lr = 0x8005D2B8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005D2B8:
    ctx->pc = 0x8005D2B8u;
    ctx->downcount -= 1;
    // 8005D2B8: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D2BC:
    ctx->pc = 0x8005D2BCu;
    ctx->downcount -= 4;
    // 8005D2BC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D2C0:
    ctx->pc = 0x8005D2C0u;
    // 8005D2C0: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8005D2C4:
    ctx->pc = 0x8005D2C4u;
    // 8005D2C4: li      r5, 26
    ctx->gpr[5] = (u32)(s32)(26);

label_8005D2C8:
    ctx->pc = 0x8005D2C8u;
    // 8005D2C8: bl      0x8005C934
    {
            ctx->lr = 0x8005D2CCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005D2CC:
    ctx->pc = 0x8005D2CCu;
    ctx->downcount -= 1;
    // 8005D2CC: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D2D0:
    ctx->pc = 0x8005D2D0u;
    ctx->downcount -= 5;
    // 8005D2D0: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D2D4:
    ctx->pc = 0x8005D2D4u;
    // 8005D2D4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D2D8:
    ctx->pc = 0x8005D2D8u;
    // 8005D2D8: addi    r5, r5, 22404
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22404);

label_8005D2DC:
    ctx->pc = 0x8005D2DCu;
    // 8005D2DC: li      r4, 4203
    ctx->gpr[4] = (u32)(s32)(4203);

label_8005D2E0:
    ctx->pc = 0x8005D2E0u;
    // 8005D2E0: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D2E4u;
            goto label_8005D3F0;
    }

label_8005D2E4:
    ctx->pc = 0x8005D2E4u;
    ctx->downcount -= 2;
    // 8005D2E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D2E8:
    ctx->pc = 0x8005D2E8u;
    // 8005D2E8: li      r4, 90
    ctx->gpr[4] = (u32)(s32)(90);

label_8005D2EC:
    ctx->pc = 0x8005D2ECu;
    ctx->downcount -= 2;
    // 8005D2EC: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8005D2F0:
    ctx->pc = 0x8005D2F0u;
    // 8005D2F0: bl      0x8005C934
    {
            ctx->lr = 0x8005D2F4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005D2F4:
    ctx->pc = 0x8005D2F4u;
    ctx->downcount -= 1;
    // 8005D2F4: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D2F8:
    ctx->pc = 0x8005D2F8u;
    ctx->downcount -= 3;
    // 8005D2F8: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_8005D2FC:
    ctx->pc = 0x8005D2FCu;
    // 8005D2FC: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D300:
    ctx->pc = 0x8005D300u;
    // 8005D300: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D304:
    ctx->pc = 0x8005D304u;
    ctx->downcount -= 5;
    // 8005D304: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D308:
    ctx->pc = 0x8005D308u;
    // 8005D308: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005D30C:
    ctx->pc = 0x8005D30Cu;
    // 8005D30C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D310:
    ctx->pc = 0x8005D310u;
    // 8005D310: addi    r5, r5, 22420
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22420);

label_8005D314:
    ctx->pc = 0x8005D314u;
    // 8005D314: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D318u;
            goto label_8005D3F0;
    }

label_8005D318:
    ctx->pc = 0x8005D318u;
    ctx->downcount -= 5;
    // 8005D318: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D31C:
    ctx->pc = 0x8005D31Cu;
    // 8005D31C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D320:
    ctx->pc = 0x8005D320u;
    // 8005D320: addi    r4, r4, 5360
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5360);

label_8005D324:
    ctx->pc = 0x8005D324u;
    // 8005D324: li      r5, 9
    ctx->gpr[5] = (u32)(s32)(9);

label_8005D328:
    ctx->pc = 0x8005D328u;
    // 8005D328: bl      0x8005C950
    {
            ctx->lr = 0x8005D32Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005D32C:
    ctx->pc = 0x8005D32Cu;
    ctx->downcount -= 1;
    // 8005D32C: b       0x8005D358
    {
            goto label_8005D358;
    }

label_8005D330:
    ctx->pc = 0x8005D330u;
    ctx->downcount -= 5;
    // 8005D330: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005D334:
    ctx->pc = 0x8005D334u;
    // 8005D334: li      r4, 4200
    ctx->gpr[4] = (u32)(s32)(4200);

label_8005D338:
    ctx->pc = 0x8005D338u;
    // 8005D338: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D33C:
    ctx->pc = 0x8005D33Cu;
    // 8005D33C: addi    r5, r5, 22156
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22156);

label_8005D340:
    ctx->pc = 0x8005D340u;
    // 8005D340: bl      0x8005D3F0
    {
            ctx->lr = 0x8005D344u;
            goto label_8005D3F0;
    }

label_8005D344:
    ctx->pc = 0x8005D344u;
    ctx->downcount -= 5;
    // 8005D344: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005D348:
    ctx->pc = 0x8005D348u;
    // 8005D348: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D34C:
    ctx->pc = 0x8005D34Cu;
    // 8005D34C: addi    r4, r4, 5396
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5396);

label_8005D350:
    ctx->pc = 0x8005D350u;
    // 8005D350: li      r5, 9
    ctx->gpr[5] = (u32)(s32)(9);

label_8005D354:
    ctx->pc = 0x8005D354u;
    // 8005D354: bl      0x8005C950
    {
            ctx->lr = 0x8005D358u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005D358:
    ctx->pc = 0x8005D358u;
    ctx->downcount -= 2;
    // 8005D358: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D35C:
    ctx->pc = 0x8005D35Cu;
    // 8005D35C: bl      0x8005DA44
    {
            ctx->lr = 0x8005D360u;
            goto label_8005DA44;
    }

label_8005D360:
    ctx->pc = 0x8005D360u;
    ctx->downcount -= 16;
    // 8005D360: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D364:
    ctx->pc = 0x8005D364u;
    // 8005D364: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005D368:
    ctx->pc = 0x8005D368u;
    // 8005D368: lmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005D36C:
    ctx->pc = 0x8005D36Cu;
    // 8005D36C: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8005D370:
    ctx->pc = 0x8005D370u;
    // 8005D370: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005D374:
    ctx->pc = 0x8005D374u;
    ctx->downcount -= 23;
    // 8005D374: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005D378:
    ctx->pc = 0x8005D378u;
    // 8005D378: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005D37C:
    ctx->pc = 0x8005D37Cu;
    // 8005D37C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005D380:
    ctx->pc = 0x8005D380u;
    // 8005D380: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D384:
    ctx->pc = 0x8005D384u;
    // 8005D384: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005D388:
    ctx->pc = 0x8005D388u;
    // 8005D388: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8005D38C:
    ctx->pc = 0x8005D38Cu;
    // 8005D38C: lwz     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D390:
    ctx->pc = 0x8005D390u;
    // 8005D390: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005D394:
    ctx->pc = 0x8005D394u;
    // 8005D394: stw     r29, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8005D398:
    ctx->pc = 0x8005D398u;
    // 8005D398: or.   r4, r5, r5
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[5];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[4];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005D39C:
    ctx->pc = 0x8005D39Cu;
    // 8005D39C: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8005D3A0:
    ctx->pc = 0x8005D3A0u;
    // 8005D3A0: stw     r0, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D3A4:
    ctx->pc = 0x8005D3A4u;
    // 8005D3A4: bc    12, 0, 0x8005D3C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D3C8;
        }
    }

label_8005D3A8:
    ctx->pc = 0x8005D3A8u;
    ctx->downcount -= 3;
    // 8005D3A8: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_8005D3AC:
    ctx->pc = 0x8005D3ACu;
    // 8005D3AC: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_8005D3B0:
    ctx->pc = 0x8005D3B0u;
    // 8005D3B0: bl      0x80046B00
    {
            ctx->lr = 0x8005D3B4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8005D3B4:
    ctx->pc = 0x8005D3B4u;
    ctx->downcount -= 7;
    // 8005D3B4: mulli   r0, r30, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[30] * (s64)(s32)20);

label_8005D3B8:
    ctx->pc = 0x8005D3B8u;
    // 8005D3B8: addi    r9, r31, 28
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(28);

label_8005D3BC:
    ctx->pc = 0x8005D3BCu;
    // 8005D3BC: addi    r11, r31, 32
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(32);

label_8005D3C0:
    ctx->pc = 0x8005D3C0u;
    // 8005D3C0: stwx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005D3C4:
    ctx->pc = 0x8005D3C4u;
    // 8005D3C4: b       0x8005D3D8
    {
            goto label_8005D3D8;
    }

label_8005D3C8:
    ctx->pc = 0x8005D3C8u;
    ctx->downcount -= 6;
    // 8005D3C8: mulli   r0, r30, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[30] * (s64)(s32)20);

label_8005D3CC:
    ctx->pc = 0x8005D3CCu;
    // 8005D3CC: addi    r9, r31, 32
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(32);

label_8005D3D0:
    ctx->pc = 0x8005D3D0u;
    // 8005D3D0: addi    r11, r31, 28
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(28);

label_8005D3D4:
    ctx->pc = 0x8005D3D4u;
    // 8005D3D4: stwx    r6, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005D3D8:
    ctx->pc = 0x8005D3D8u;
    ctx->downcount -= 17;
    // 8005D3D8: stwx    r29, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8005D3DC:
    ctx->pc = 0x8005D3DCu;
    // 8005D3DC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D3E0:
    ctx->pc = 0x8005D3E0u;
    // 8005D3E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005D3E4:
    ctx->pc = 0x8005D3E4u;
    // 8005D3E4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005D3E8:
    ctx->pc = 0x8005D3E8u;
    // 8005D3E8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8005D3EC:
    ctx->pc = 0x8005D3ECu;
    // 8005D3EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005D3F0:
    ctx->pc = 0x8005D3F0u;
    ctx->downcount -= 21;
    // 8005D3F0: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005D3F4:
    ctx->pc = 0x8005D3F4u;
    // 8005D3F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005D3F8:
    ctx->pc = 0x8005D3F8u;
    // 8005D3F8: stmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005D3FC:
    ctx->pc = 0x8005D3FCu;
    // 8005D3FC: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D400:
    ctx->pc = 0x8005D400u;
    // 8005D400: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005D404:
    ctx->pc = 0x8005D404u;
    // 8005D404: or   r26, r4, r4
    {
        ctx->gpr[26] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005D408:
    ctx->pc = 0x8005D408u;
    // 8005D408: or   r25, r5, r5
    {
        ctx->gpr[25] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8005D40C:
    ctx->pc = 0x8005D40Cu;
    // 8005D40C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_8005D410:
    ctx->pc = 0x8005D410u;
    // 8005D410: li      r27, 320
    ctx->gpr[27] = (u32)(s32)(320);

label_8005D414:
    ctx->pc = 0x8005D414u;
    // 8005D414: li      r28, -1
    ctx->gpr[28] = (u32)(s32)(-1);

label_8005D418:
    ctx->pc = 0x8005D418u;
    // 8005D418: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_8005D41C:
    ctx->downcount -= 5;
    // 8005D41C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005D420:
    // 8005D420: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005D424:
    // 8005D424: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8005D428:
    // 8005D428: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8005D42C:
    // 8005D42C: bl      0x8005D374
    {
            ctx->lr = 0x8005D430u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D374u;
                return;
            }
            goto label_8005D374;
    }

label_8005D430:
    ctx->downcount -= 6;
    // 8005D430: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_8005D434:
    ctx->pc = 0x8005D434u;
    // 8005D434: stw     r27, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8005D438:
    // 8005D438: cmpwi   r29, 4
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005D43C:
    ctx->pc = 0x8005D43Cu;
    // 8005D43C: stw     r28, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8005D440:
    // 8005D440: addi    r31, r31, 20
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(20);

label_8005D444:
    // 8005D444: bc    4, 1, 0x8005D41C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D41Cu;
                return;
            }
            goto label_8005D41C;
        }
    }

label_8005D448:
    ctx->pc = 0x8005D448u;
    ctx->downcount -= 12;
    // 8005D448: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D44C:
    ctx->pc = 0x8005D44Cu;
    // 8005D44C: li      r9, 320
    ctx->gpr[9] = (u32)(s32)(320);

label_8005D450:
    ctx->pc = 0x8005D450u;
    // 8005D450: li      r11, 150
    ctx->gpr[11] = (u32)(s32)(150);

label_8005D454:
    ctx->pc = 0x8005D454u;
    // 8005D454: stw     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005D458:
    ctx->pc = 0x8005D458u;
    // 8005D458: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8005D45C:
    ctx->pc = 0x8005D45Cu;
    // 8005D45C: stw     r11, 24(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005D460:
    ctx->pc = 0x8005D460u;
    // 8005D460: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D464:
    ctx->pc = 0x8005D464u;
    // 8005D464: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005D468:
    ctx->pc = 0x8005D468u;
    // 8005D468: or   r5, r26, r26
    {
        ctx->gpr[5] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005D46C:
    ctx->pc = 0x8005D46Cu;
    // 8005D46C: or   r6, r25, r25
    {
        ctx->gpr[6] = ctx->gpr[25] | ctx->gpr[25];
    }

label_8005D470:
    ctx->pc = 0x8005D470u;
    // 8005D470: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005D474:
    ctx->pc = 0x8005D474u;
    // 8005D474: bl      0x8005D374
    {
            ctx->lr = 0x8005D478u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D374u;
                return;
            }
            goto label_8005D374;
    }

label_8005D478:
    ctx->pc = 0x8005D478u;
    ctx->downcount -= 16;
    // 8005D478: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D47C:
    ctx->pc = 0x8005D47Cu;
    // 8005D47C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005D480:
    ctx->pc = 0x8005D480u;
    // 8005D480: lmw     r25, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005D484:
    ctx->pc = 0x8005D484u;
    // 8005D484: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8005D488:
    ctx->pc = 0x8005D488u;
    // 8005D488: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005D48C:
    ctx->pc = 0x8005D48Cu;
    ctx->downcount -= 7;
    // 8005D48C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005D490:
    ctx->pc = 0x8005D490u;
    // 8005D490: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005D494:
    ctx->pc = 0x8005D494u;
    // 8005D494: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D498:
    ctx->pc = 0x8005D498u;
    // 8005D498: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8005D49C:
    ctx->pc = 0x8005D49Cu;
    // 8005D49C: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005D4A0:
    ctx->pc = 0x8005D4A0u;
    // 8005D4A0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005D4A4:
    ctx->pc = 0x8005D4A4u;
    // 8005D4A4: bl      0x8005D374
    {
            ctx->lr = 0x8005D4A8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D374u;
                return;
            }
            goto label_8005D374;
    }

label_8005D4A8:
    ctx->pc = 0x8005D4A8u;
    ctx->downcount -= 5;
    // 8005D4A8: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D4AC:
    ctx->pc = 0x8005D4ACu;
    // 8005D4AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005D4B0:
    ctx->pc = 0x8005D4B0u;
    // 8005D4B0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005D4B4:
    ctx->pc = 0x8005D4B4u;
    // 8005D4B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005D4B8:
    ctx->pc = 0x8005D4B8u;
    ctx->downcount -= 7;
    // 8005D4B8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005D4BC:
    ctx->pc = 0x8005D4BCu;
    // 8005D4BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005D4C0:
    ctx->pc = 0x8005D4C0u;
    // 8005D4C0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D4C4:
    ctx->pc = 0x8005D4C4u;
    // 8005D4C4: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8005D4C8:
    ctx->pc = 0x8005D4C8u;
    // 8005D4C8: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005D4CC:
    ctx->pc = 0x8005D4CCu;
    // 8005D4CC: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8005D4D0:
    ctx->pc = 0x8005D4D0u;
    // 8005D4D0: bl      0x8005D374
    {
            ctx->lr = 0x8005D4D4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D374u;
                return;
            }
            goto label_8005D374;
    }

label_8005D4D4:
    ctx->pc = 0x8005D4D4u;
    ctx->downcount -= 5;
    // 8005D4D4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D4D8:
    ctx->pc = 0x8005D4D8u;
    // 8005D4D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005D4DC:
    ctx->pc = 0x8005D4DCu;
    // 8005D4DC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005D4E0:
    ctx->pc = 0x8005D4E0u;
    // 8005D4E0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005D4E4:
    ctx->pc = 0x8005D4E4u;
    ctx->downcount -= 7;
    // 8005D4E4: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005D4E8:
    ctx->pc = 0x8005D4E8u;
    // 8005D4E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005D4EC:
    ctx->pc = 0x8005D4ECu;
    // 8005D4EC: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D4F0:
    ctx->pc = 0x8005D4F0u;
    // 8005D4F0: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8005D4F4:
    ctx->pc = 0x8005D4F4u;
    // 8005D4F4: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005D4F8:
    ctx->pc = 0x8005D4F8u;
    // 8005D4F8: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8005D4FC:
    ctx->pc = 0x8005D4FCu;
    // 8005D4FC: bl      0x8005D374
    {
            ctx->lr = 0x8005D500u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D374u;
                return;
            }
            goto label_8005D374;
    }

label_8005D500:
    ctx->pc = 0x8005D500u;
    ctx->downcount -= 5;
    // 8005D500: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D504:
    ctx->pc = 0x8005D504u;
    // 8005D504: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005D508:
    ctx->pc = 0x8005D508u;
    // 8005D508: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005D50C:
    ctx->pc = 0x8005D50Cu;
    // 8005D50C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005D510:
    ctx->pc = 0x8005D510u;
    ctx->downcount -= 7;
    // 8005D510: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005D514:
    ctx->pc = 0x8005D514u;
    // 8005D514: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005D518:
    ctx->pc = 0x8005D518u;
    // 8005D518: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D51C:
    ctx->pc = 0x8005D51Cu;
    // 8005D51C: or   r6, r5, r5
    {
        ctx->gpr[6] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8005D520:
    ctx->pc = 0x8005D520u;
    // 8005D520: or   r5, r4, r4
    {
        ctx->gpr[5] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8005D524:
    ctx->pc = 0x8005D524u;
    // 8005D524: li      r4, 4
    ctx->gpr[4] = (u32)(s32)(4);

label_8005D528:
    ctx->pc = 0x8005D528u;
    // 8005D528: bl      0x8005D374
    {
            ctx->lr = 0x8005D52Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D374u;
                return;
            }
            goto label_8005D374;
    }

label_8005D52C:
    ctx->pc = 0x8005D52Cu;
    ctx->downcount -= 5;
    // 8005D52C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D530:
    ctx->pc = 0x8005D530u;
    // 8005D530: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005D534:
    ctx->pc = 0x8005D534u;
    // 8005D534: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005D538:
    ctx->pc = 0x8005D538u;
    // 8005D538: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005D53C:
    ctx->pc = 0x8005D53Cu;
    ctx->downcount -= 21;
    // 8005D53C: stwu     r1, -104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-104);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005D540:
    ctx->pc = 0x8005D540u;
    // 8005D540: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005D544:
    ctx->pc = 0x8005D544u;
    // 8005D544: stfd     f31, 96(r1)
    if (!ppc_fp_available(ctx, 0x8005D544u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8005D548:
    ctx->pc = 0x8005D548u;
    // 8005D548: stmw     r19, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 19; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005D54C:
    ctx->pc = 0x8005D54Cu;
    // 8005D54C: stw     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D550:
    ctx->pc = 0x8005D550u;
    // 8005D550: lis     r9, -32698
    ctx->gpr[9] = ((u32)(s32)(-32698) << 16);

label_8005D554:
    ctx->pc = 0x8005D554u;
    // 8005D554: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005D558:
    ctx->pc = 0x8005D558u;
    // 8005D558: addi    r31, r9, 11668
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(11668);

label_8005D55C:
    ctx->pc = 0x8005D55Cu;
    // 8005D55C: addi    r25, r1, 8
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(8);

label_8005D560:
    ctx->pc = 0x8005D560u;
    // 8005D560: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D564:
    ctx->pc = 0x8005D564u;
    // 8005D564: bl      0x80034B48
    {
            ctx->lr = 0x8005D568u;
            ctx->pc = 0x80034B48u;
            return;
    }

label_8005D568:
    ctx->pc = 0x8005D568u;
    ctx->downcount -= 2;
    // 8005D568: cmpwi   r3, 0
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

label_8005D56C:
    ctx->pc = 0x8005D56Cu;
    // 8005D56C: bc    4, 2, 0x8005D598
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D598;
        }
    }

label_8005D570:
    ctx->pc = 0x8005D570u;
    ctx->downcount -= 8;
    // 8005D570: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8005D574:
    ctx->pc = 0x8005D574u;
    // 8005D574: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005D578:
    ctx->pc = 0x8005D578u;
    // 8005D578: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8005D57C:
    ctx->pc = 0x8005D57Cu;
    // 8005D57C: lis     r11, -32700
    ctx->gpr[11] = ((u32)(s32)(-32700) << 16);

label_8005D580:
    ctx->pc = 0x8005D580u;
    // 8005D580: lfs     f0, 22520(r9)
    if (!ppc_fp_available(ctx, 0x8005D580u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22520);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005D584:
    ctx->pc = 0x8005D584u;
    // 8005D584: addi    r31, r11, -26904
    ctx->gpr[31] = ctx->gpr[11] + (u32)(s32)(-26904);

label_8005D588:
    ctx->pc = 0x8005D588u;
    // 8005D588: addi    r9, r26, 116
    ctx->gpr[9] = ctx->gpr[26] + (u32)(s32)(116);

label_8005D58C:
    ctx->pc = 0x8005D58Cu;
    ctx->downcount -= 3;
    // 8005D58C: stfs     f0, 0(r9)
    if (!ppc_fp_available(ctx, 0x8005D58Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005D590:
    // 8005D590: addi    r9, r9, -20
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-20);

label_8005D594:
    // 8005D594: bc    16, 0, 0x8005D58C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D58Cu;
                return;
            }
            goto label_8005D58C;
        }
    }

label_8005D598:
    ctx->pc = 0x8005D598u;
    ctx->downcount -= 9;
    // 8005D598: lis     r9, -32702
    ctx->gpr[9] = ((u32)(s32)(-32702) << 16);

label_8005D59C:
    ctx->pc = 0x8005D59Cu;
    // 8005D59C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005D5A0:
    ctx->pc = 0x8005D5A0u;
    // 8005D5A0: addi    r11, r9, 30624
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(30624);

label_8005D5A4:
    ctx->pc = 0x8005D5A4u;
    // 8005D5A4: stw     r0, 30624(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D5A8:
    ctx->pc = 0x8005D5A8u;
    // 8005D5A8: lis     r10, -256
    ctx->gpr[10] = ((u32)(s32)(-256) << 16);

label_8005D5AC:
    ctx->pc = 0x8005D5ACu;
    // 8005D5AC: or   r3, r11, r11
    {
        ctx->gpr[3] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005D5B0:
    ctx->pc = 0x8005D5B0u;
    // 8005D5B0: stw     r10, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005D5B4:
    ctx->pc = 0x8005D5B4u;
    // 8005D5B4: addi    r19, r26, 36
    ctx->gpr[19] = ctx->gpr[26] + (u32)(s32)(36);

label_8005D5B8:
    ctx->pc = 0x8005D5B8u;
    // 8005D5B8: bl      0x80050528
    {
            ctx->lr = 0x8005D5BCu;
            ctx->pc = 0x80050528u;
            return;
    }

label_8005D5BC:
    ctx->pc = 0x8005D5BCu;
    ctx->downcount -= 6;
    // 8005D5BC: addi    r20, r26, 24
    ctx->gpr[20] = ctx->gpr[26] + (u32)(s32)(24);

label_8005D5C0:
    ctx->pc = 0x8005D5C0u;
    // 8005D5C0: lis     r4, -36
    ctx->gpr[4] = ((u32)(s32)(-36) << 16);

label_8005D5C4:
    ctx->pc = 0x8005D5C4u;
    // 8005D5C4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D5C8:
    ctx->pc = 0x8005D5C8u;
    // 8005D5C8: ori     r4, r4, 0xC828
    ctx->gpr[4] = ctx->gpr[4] | 0xC828u;

label_8005D5CC:
    ctx->pc = 0x8005D5CCu;
    // 8005D5CC: addi    r21, r26, 32
    ctx->gpr[21] = ctx->gpr[26] + (u32)(s32)(32);

label_8005D5D0:
    ctx->pc = 0x8005D5D0u;
    // 8005D5D0: bl      0x80034BA8
    {
            ctx->lr = 0x8005D5D4u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005D5D4:
    ctx->pc = 0x8005D5D4u;
    ctx->downcount -= 4;
    // 8005D5D4: addi    r22, r26, 28
    ctx->gpr[22] = ctx->gpr[26] + (u32)(s32)(28);

label_8005D5D8:
    ctx->pc = 0x8005D5D8u;
    // 8005D5D8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D5DC:
    ctx->pc = 0x8005D5DCu;
    // 8005D5DC: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005D5E0:
    ctx->pc = 0x8005D5E0u;
    // 8005D5E0: bl      0x80035C40
    {
            ctx->lr = 0x8005D5E4u;
            ctx->pc = 0x80035C40u;
            return;
    }

label_8005D5E4:
    ctx->pc = 0x8005D5E4u;
    ctx->downcount -= 6;
    // 8005D5E4: lis     r23, 17200
    ctx->gpr[23] = ((u32)(s32)(17200) << 16);

label_8005D5E8:
    ctx->pc = 0x8005D5E8u;
    // 8005D5E8: addi    r28, r1, 16
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(16);

label_8005D5EC:
    ctx->pc = 0x8005D5ECu;
    // 8005D5EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D5F0:
    ctx->pc = 0x8005D5F0u;
    // 8005D5F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005D5F4:
    ctx->pc = 0x8005D5F4u;
    // 8005D5F4: addi    r30, r26, 20
    ctx->gpr[30] = ctx->gpr[26] + (u32)(s32)(20);

label_8005D5F8:
    ctx->pc = 0x8005D5F8u;
    // 8005D5F8: bl      0x80035C48
    {
            ctx->lr = 0x8005D5FCu;
            ctx->pc = 0x80035C48u;
            return;
    }

label_8005D5FC:
    ctx->pc = 0x8005D5FCu;
    ctx->downcount -= 6;
    // 8005D5FC: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8005D600:
    ctx->pc = 0x8005D600u;
    // 8005D600: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D604:
    ctx->pc = 0x8005D604u;
    // 8005D604: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_8005D608:
    ctx->pc = 0x8005D608u;
    // 8005D608: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8005D60C:
    ctx->pc = 0x8005D60Cu;
    // 8005D60C: li      r24, 5
    ctx->gpr[24] = (u32)(s32)(5);

label_8005D610:
    ctx->pc = 0x8005D610u;
    // 8005D610: bl      0x80035C50
    {
            ctx->lr = 0x8005D614u;
            ctx->pc = 0x80035C50u;
            return;
    }

label_8005D614:
    ctx->pc = 0x8005D614u;
    ctx->downcount -= 7;
    // 8005D614: lfs     f0, 148(r31)
    if (!ppc_fp_available(ctx, 0x8005D614u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(148);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005D618:
    ctx->pc = 0x8005D618u;
    // 8005D618: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005D61C:
    ctx->pc = 0x8005D61Cu;
    // 8005D61C: lfd     f31, 22528(r9)
    if (!ppc_fp_available(ctx, 0x8005D61Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22528);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D620:
    ctx->pc = 0x8005D620u;
    // 8005D620: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005D620u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005D624:
    ctx->pc = 0x8005D624u;
    // 8005D624: lfs     f0, 152(r31)
    if (!ppc_fp_available(ctx, 0x8005D624u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(152);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005D628:
    ctx->pc = 0x8005D628u;
    // 8005D628: lwz     r29, 24(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(24);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8005D62C:
    ctx->pc = 0x8005D62Cu;
    // 8005D62C: stfs     f0, 4(r25)
    if (!ppc_fp_available(ctx, 0x8005D62Cu)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005D630:
    ctx->pc = 0x8005D630u;
    ctx->downcount -= 3;
    // 8005D630: lwzx    r0, r27, r20
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[20];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D634:
    // 8005D634: cmpwi   r0, -1
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

label_8005D638:
    // 8005D638: bc    12, 2, 0x8005D640
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D640;
        }
    }

label_8005D63C:
    ctx->downcount -= 1;
    // 8005D63C: or   r29, r0, r0
    {
        ctx->gpr[29] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8005D640:
    ctx->pc = 0x8005D640u;
    ctx->downcount -= 3;
    // 8005D640: lfsx    f1, r27, r19
    if (!ppc_fp_available(ctx, 0x8005D640u)) return;
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[19];
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005D644:
    // 8005D644: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D648:
    // 8005D648: bl      0x80034E48
    {
            ctx->lr = 0x8005D64Cu;
            ctx->pc = 0x80034E48u;
            return;
    }

label_8005D64C:
    ctx->pc = 0x8005D64Cu;
    ctx->downcount -= 7;
    // 8005D64C: lfs     f0, 148(r31)
    if (!ppc_fp_available(ctx, 0x8005D64Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(148);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005D650:
    ctx->pc = 0x8005D650u;
    // 8005D650: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005D650u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005D654:
    ctx->pc = 0x8005D654u;
    // 8005D654: lfs     f13, 152(r31)
    if (!ppc_fp_available(ctx, 0x8005D654u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(152);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_8005D658:
    ctx->pc = 0x8005D658u;
    // 8005D658: stfs     f13, 4(r25)
    if (!ppc_fp_available(ctx, 0x8005D658u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_8005D65C:
    ctx->pc = 0x8005D65Cu;
    // 8005D65C: lwzx    r6, r27, r21
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[21];
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005D660:
    // 8005D660: cmpwi   r6, 0
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

label_8005D664:
    // 8005D664: bc    12, 2, 0x8005D6DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D6DC;
        }
    }

label_8005D668:
    ctx->pc = 0x8005D668u;
    ctx->downcount -= 5;
    // 8005D668: lwz     r4, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005D66C:
    // 8005D66C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005D670:
    // 8005D670: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D674:
    // 8005D674: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005D678:
    // 8005D678: bl      0x80035184
    {
            ctx->lr = 0x8005D67Cu;
            ctx->pc = 0x80035184u;
            return;
    }

label_8005D67C:
    ctx->downcount -= 4;
    // 8005D67C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D680:
    // 8005D680: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005D684:
    // 8005D684: addi    r5, r1, 20
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(20);

label_8005D688:
    // 8005D688: bl      0x80035324
    {
            ctx->lr = 0x8005D68Cu;
            ctx->pc = 0x80035324u;
            return;
    }

label_8005D68C:
    ctx->pc = 0x8005D68Cu;
    ctx->downcount -= 6;
    // 8005D68C: lfs     f0, 4(r28)
    if (!ppc_fp_available(ctx, 0x8005D68Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005D690:
    // 8005D690: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D694:
    ctx->pc = 0x8005D694u;
    // 8005D694: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8005D694u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_8005D698:
    ctx->pc = 0x8005D698u;
    // 8005D698: stfd     f13, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D698u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_8005D69C:
    ctx->pc = 0x8005D69Cu;
    // 8005D69C: lwz     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8005D6A0:
    // 8005D6A0: bl      0x80034DDC
    {
            ctx->lr = 0x8005D6A4u;
            ctx->pc = 0x80034DDCu;
            return;
    }

label_8005D6A4:
    ctx->downcount -= 14;
    // 8005D6A4: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_8005D6A8:
    ctx->pc = 0x8005D6A8u;
    // 8005D6A8: stw     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005D6AC:
    // 8005D6AC: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005D6B0:
    ctx->pc = 0x8005D6B0u;
    // 8005D6B0: lfs     f11, 4(r25)
    if (!ppc_fp_available(ctx, 0x8005D6B0u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005D6B4:
    ctx->pc = 0x8005D6B4u;
    // 8005D6B4: stw     r23, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_8005D6B8:
    ctx->pc = 0x8005D6B8u;
    // 8005D6B8: lfd     f0, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D6B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D6BC:
    ctx->pc = 0x8005D6BCu;
    // 8005D6BC: fsub   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x8005D6BCu)) return;
    ppc_fsub(ctx, 0, 0, 31);

label_8005D6C0:
    ctx->pc = 0x8005D6C0u;
    // 8005D6C0: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005D6C0u)) return;
    ppc_frsp(ctx, 0, 0);

label_8005D6C4:
    ctx->pc = 0x8005D6C4u;
    // 8005D6C4: fmuls   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005D6C4u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_8005D6C8:
    ctx->pc = 0x8005D6C8u;
    // 8005D6C8: fmr    f13, f0
    if (!ppc_fp_available(ctx, 0x8005D6C8u)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_8005D6CC:
    ctx->pc = 0x8005D6CCu;
    // 8005D6CC: fctiwz    f12, f13
    if (!ppc_fp_available(ctx, 0x8005D6CCu)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_8005D6D0:
    ctx->pc = 0x8005D6D0u;
    // 8005D6D0: stfd     f12, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D6D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_8005D6D4:
    ctx->pc = 0x8005D6D4u;
    // 8005D6D4: lwz     r11, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005D6D8:
    // 8005D6D8: add   r29, r29, r11
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8005D6DC:
    ctx->pc = 0x8005D6DCu;
    ctx->downcount -= 3;
    // 8005D6DC: lwzx    r6, r27, r22
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[22];
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005D6E0:
    // 8005D6E0: cmpwi   r6, 0
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

label_8005D6E4:
    // 8005D6E4: bc    12, 2, 0x8005D758
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D758;
        }
    }

label_8005D6E8:
    ctx->pc = 0x8005D6E8u;
    ctx->downcount -= 4;
    // 8005D6E8: lwz     r4, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005D6EC:
    // 8005D6EC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005D6F0:
    // 8005D6F0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D6F4:
    // 8005D6F4: bl      0x80034F4C
    {
            ctx->lr = 0x8005D6F8u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_8005D6F8:
    ctx->downcount -= 4;
    // 8005D6F8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D6FC:
    // 8005D6FC: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005D700:
    // 8005D700: addi    r5, r1, 20
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(20);

label_8005D704:
    // 8005D704: bl      0x80035324
    {
            ctx->lr = 0x8005D708u;
            ctx->pc = 0x80035324u;
            return;
    }

label_8005D708:
    ctx->pc = 0x8005D708u;
    ctx->downcount -= 6;
    // 8005D708: lfs     f0, 4(r28)
    if (!ppc_fp_available(ctx, 0x8005D708u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005D70C:
    // 8005D70C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D710:
    ctx->pc = 0x8005D710u;
    // 8005D710: fctiwz    f13, f0
    if (!ppc_fp_available(ctx, 0x8005D710u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[0], true, &result)) ctx->fpr[13] = dolrecomp_f64_from_bits(result); }

label_8005D714:
    ctx->pc = 0x8005D714u;
    // 8005D714: stfd     f13, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D714u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[13]));
    }

label_8005D718:
    ctx->pc = 0x8005D718u;
    // 8005D718: lwz     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8005D71C:
    // 8005D71C: bl      0x80034DDC
    {
            ctx->lr = 0x8005D720u;
            ctx->pc = 0x80034DDCu;
            return;
    }

label_8005D720:
    ctx->downcount -= 14;
    // 8005D720: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_8005D724:
    ctx->pc = 0x8005D724u;
    // 8005D724: stw     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005D728:
    // 8005D728: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005D72C:
    ctx->pc = 0x8005D72Cu;
    // 8005D72C: lfs     f11, 4(r25)
    if (!ppc_fp_available(ctx, 0x8005D72Cu)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005D730:
    ctx->pc = 0x8005D730u;
    // 8005D730: stw     r23, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_8005D734:
    ctx->pc = 0x8005D734u;
    // 8005D734: lfd     f0, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D734u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D738:
    ctx->pc = 0x8005D738u;
    // 8005D738: fsub   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x8005D738u)) return;
    ppc_fsub(ctx, 0, 0, 31);

label_8005D73C:
    ctx->pc = 0x8005D73Cu;
    // 8005D73C: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005D73Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_8005D740:
    ctx->pc = 0x8005D740u;
    // 8005D740: fmuls   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005D740u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_8005D744:
    ctx->pc = 0x8005D744u;
    // 8005D744: fmr    f13, f0
    if (!ppc_fp_available(ctx, 0x8005D744u)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_8005D748:
    ctx->pc = 0x8005D748u;
    // 8005D748: fctiwz    f12, f13
    if (!ppc_fp_available(ctx, 0x8005D748u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_8005D74C:
    ctx->pc = 0x8005D74Cu;
    // 8005D74C: stfd     f12, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D74Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_8005D750:
    ctx->pc = 0x8005D750u;
    // 8005D750: lwz     r11, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005D754:
    // 8005D754: add   r29, r29, r11
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8005D758:
    ctx->downcount -= 4;
    // 8005D758: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005D75C:
    // 8005D75C: addi    r27, r27, 20
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(20);

label_8005D760:
    // 8005D760: addic.  r24, r24, -1
    {
        u64 a = ctx->gpr[24];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[24] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[24];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005D764:
    // 8005D764: bc    4, 2, 0x8005D630
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D630u;
                return;
            }
            goto label_8005D630;
        }
    }

label_8005D768:
    ctx->pc = 0x8005D768u;
    ctx->downcount -= 3;
    // 8005D768: lwz     r0, 148(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D76C:
    ctx->pc = 0x8005D76Cu;
    // 8005D76C: cmpwi   r0, 0
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

label_8005D770:
    ctx->pc = 0x8005D770u;
    // 8005D770: bc    12, 2, 0x8005DA10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DA10;
        }
    }

label_8005D774:
    ctx->pc = 0x8005D774u;
    ctx->downcount -= 3;
    // 8005D774: lwz     r0, 144(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(144);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D778:
    ctx->pc = 0x8005D778u;
    // 8005D778: cmpwi   r0, -1
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

label_8005D77C:
    ctx->pc = 0x8005D77Cu;
    // 8005D77C: bc    12, 2, 0x8005D788
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D788;
        }
    }

label_8005D780:
    ctx->pc = 0x8005D780u;
    ctx->downcount -= 2;
    // 8005D780: or   r29, r0, r0
    {
        ctx->gpr[29] = ctx->gpr[0] | ctx->gpr[0];
    }

label_8005D784:
    ctx->pc = 0x8005D784u;
    // 8005D784: b       0x8005D7E0
    {
            goto label_8005D7E0;
    }

label_8005D788:
    ctx->pc = 0x8005D788u;
    ctx->downcount -= 2;
    // 8005D788: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D78C:
    ctx->pc = 0x8005D78Cu;
    // 8005D78C: bl      0x80034DDC
    {
            ctx->lr = 0x8005D790u;
            ctx->pc = 0x80034DDCu;
            return;
    }

label_8005D790:
    ctx->pc = 0x8005D790u;
    ctx->downcount -= 20;
    // 8005D790: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_8005D794:
    ctx->pc = 0x8005D794u;
    // 8005D794: stw     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005D798:
    ctx->pc = 0x8005D798u;
    // 8005D798: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8005D79C:
    ctx->pc = 0x8005D79Cu;
    // 8005D79C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005D7A0:
    ctx->pc = 0x8005D7A0u;
    // 8005D7A0: lfs     f10, 4(r25)
    if (!ppc_fp_available(ctx, 0x8005D7A0u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_8005D7A4:
    ctx->pc = 0x8005D7A4u;
    // 8005D7A4: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D7A8:
    ctx->pc = 0x8005D7A8u;
    // 8005D7A8: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005D7AC:
    ctx->pc = 0x8005D7ACu;
    // 8005D7AC: lfd     f13, 22528(r9)
    if (!ppc_fp_available(ctx, 0x8005D7ACu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22528);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D7B0:
    ctx->pc = 0x8005D7B0u;
    // 8005D7B0: lfd     f0, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D7B0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D7B4:
    ctx->pc = 0x8005D7B4u;
    // 8005D7B4: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005D7B8:
    ctx->pc = 0x8005D7B8u;
    // 8005D7B8: lfs     f11, 22536(r10)
    if (!ppc_fp_available(ctx, 0x8005D7B8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(22536);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005D7BC:
    ctx->pc = 0x8005D7BCu;
    // 8005D7BC: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x8005D7BCu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_8005D7C0:
    ctx->pc = 0x8005D7C0u;
    // 8005D7C0: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005D7C0u)) return;
    ppc_frsp(ctx, 0, 0);

label_8005D7C4:
    ctx->pc = 0x8005D7C4u;
    // 8005D7C4: fmuls   f0, f0, f10
    if (!ppc_fp_available(ctx, 0x8005D7C4u)) return;
    ppc_fmuls(ctx, 0, 0, 10);

label_8005D7C8:
    ctx->pc = 0x8005D7C8u;
    // 8005D7C8: fmuls   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005D7C8u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_8005D7CC:
    ctx->pc = 0x8005D7CCu;
    // 8005D7CC: fmr    f13, f0
    if (!ppc_fp_available(ctx, 0x8005D7CCu)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_8005D7D0:
    ctx->pc = 0x8005D7D0u;
    // 8005D7D0: fctiwz    f12, f13
    if (!ppc_fp_available(ctx, 0x8005D7D0u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_8005D7D4:
    ctx->pc = 0x8005D7D4u;
    // 8005D7D4: stfd     f12, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D7D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_8005D7D8:
    ctx->pc = 0x8005D7D8u;
    // 8005D7D8: lwz     r9, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005D7DC:
    ctx->pc = 0x8005D7DCu;
    // 8005D7DC: add   r29, r29, r9
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8005D7E0:
    ctx->pc = 0x8005D7E0u;
    ctx->downcount -= 5;
    // 8005D7E0: lwz     r28, 148(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(148);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8005D7E4:
    ctx->pc = 0x8005D7E4u;
    // 8005D7E4: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8005D7E8:
    ctx->pc = 0x8005D7E8u;
    // 8005D7E8: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D7EC:
    ctx->pc = 0x8005D7ECu;
    // 8005D7EC: cmpwi   r0, 0
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

label_8005D7F0:
    ctx->pc = 0x8005D7F0u;
    // 8005D7F0: bc    12, 2, 0x8005D8E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D8E8;
        }
    }

label_8005D7F4:
    ctx->pc = 0x8005D7F4u;
    ctx->downcount -= 4;
    // 8005D7F4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005D7F8:
    ctx->pc = 0x8005D7F8u;
    // 8005D7F8: lis     r23, -32698
    ctx->gpr[23] = ((u32)(s32)(-32698) << 16);

label_8005D7FC:
    ctx->pc = 0x8005D7FCu;
    // 8005D7FC: lfd     f31, 22528(r9)
    if (!ppc_fp_available(ctx, 0x8005D7FCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22528);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D800:
    ctx->pc = 0x8005D800u;
    // 8005D800: lis     r24, 17200
    ctx->gpr[24] = ((u32)(s32)(17200) << 16);

label_8005D804:
    ctx->pc = 0x8005D804u;
    ctx->downcount -= 3;
    // 8005D804: lwz     r0, 156(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(156);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D808:
    // 8005D808: cmpw    r27, r0
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

label_8005D80C:
    // 8005D80C: bc    4, 2, 0x8005D83C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D83C;
        }
    }

label_8005D810:
    ctx->pc = 0x8005D810u;
    ctx->downcount -= 3;
    // 8005D810: lwz     r0, -32364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32364);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D814:
    // 8005D814: andi.   r9, r0, 0x0010
    {
        ctx->gpr[9] = ctx->gpr[0] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005D818:
    // 8005D818: bc    12, 2, 0x8005D82C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005D82C;
        }
    }

label_8005D81C:
    ctx->downcount -= 3;
    // 8005D81C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D820:
    // 8005D820: lis     r4, -256
    ctx->gpr[4] = ((u32)(s32)(-256) << 16);

label_8005D824:
    // 8005D824: bl      0x80034BA8
    {
            ctx->lr = 0x8005D828u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005D828:
    ctx->downcount -= 1;
    // 8005D828: b       0x8005D84C
    {
            goto label_8005D84C;
    }

label_8005D82C:
    ctx->downcount -= 3;
    // 8005D82C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D830:
    // 8005D830: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005D834:
    // 8005D834: bl      0x80034BA8
    {
            ctx->lr = 0x8005D838u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005D838:
    ctx->downcount -= 1;
    // 8005D838: b       0x8005D84C
    {
            goto label_8005D84C;
    }

label_8005D83C:
    ctx->downcount -= 4;
    // 8005D83C: lis     r4, -36
    ctx->gpr[4] = ((u32)(s32)(-36) << 16);

label_8005D840:
    // 8005D840: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D844:
    // 8005D844: ori     r4, r4, 0xC828
    ctx->gpr[4] = ctx->gpr[4] | 0xC828u;

label_8005D848:
    // 8005D848: bl      0x80034BA8
    {
            ctx->lr = 0x8005D84Cu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005D84C:
    ctx->pc = 0x8005D84Cu;
    ctx->downcount -= 3;
    // 8005D84C: lwz     r4, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005D850:
    // 8005D850: cmpwi   r4, 0
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

label_8005D854:
    // 8005D854: bc    4, 0, 0x8005D874
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D874;
        }
    }

label_8005D858:
    ctx->pc = 0x8005D858u;
    ctx->downcount -= 6;
    // 8005D858: lwz     r4, 140(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(140);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005D85C:
    // 8005D85C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D860:
    ctx->pc = 0x8005D860u;
    // 8005D860: lwz     r6, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005D864:
    // 8005D864: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005D868:
    // 8005D868: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005D86C:
    // 8005D86C: bl      0x80035184
    {
            ctx->lr = 0x8005D870u;
            ctx->pc = 0x80035184u;
            return;
    }

label_8005D870:
    ctx->downcount -= 1;
    // 8005D870: b       0x8005D894
    {
            goto label_8005D894;
    }

label_8005D874:
    ctx->pc = 0x8005D874u;
    ctx->downcount -= 3;
    // 8005D874: lwz     r30, 140(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(140);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8005D878:
    // 8005D878: addi    r3, r23, 9872
    ctx->gpr[3] = ctx->gpr[23] + (u32)(s32)(9872);

label_8005D87C:
    // 8005D87C: bl      0x80046B00
    {
            ctx->lr = 0x8005D880u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8005D880:
    ctx->downcount -= 5;
    // 8005D880: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005D884:
    // 8005D884: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005D888:
    // 8005D888: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D88C:
    // 8005D88C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005D890:
    // 8005D890: bl      0x80034F4C
    {
            ctx->lr = 0x8005D894u;
            ctx->pc = 0x80034F4Cu;
            return;
    }

label_8005D894:
    ctx->downcount -= 3;
    // 8005D894: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D898:
    // 8005D898: addi    r28, r28, 12
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(12);

label_8005D89C:
    // 8005D89C: bl      0x80034DDC
    {
            ctx->lr = 0x8005D8A0u;
            ctx->pc = 0x80034DDCu;
            return;
    }

label_8005D8A0:
    ctx->downcount -= 18;
    // 8005D8A0: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_8005D8A4:
    // 8005D8A4: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_8005D8A8:
    ctx->pc = 0x8005D8A8u;
    // 8005D8A8: stw     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005D8AC:
    // 8005D8AC: or   r11, r9, r9
    {
        ctx->gpr[11] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005D8B0:
    ctx->pc = 0x8005D8B0u;
    // 8005D8B0: lfs     f11, 4(r25)
    if (!ppc_fp_available(ctx, 0x8005D8B0u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005D8B4:
    ctx->pc = 0x8005D8B4u;
    // 8005D8B4: stw     r24, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_8005D8B8:
    ctx->pc = 0x8005D8B8u;
    // 8005D8B8: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D8BC:
    ctx->pc = 0x8005D8BCu;
    // 8005D8BC: lfd     f0, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D8BCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D8C0:
    // 8005D8C0: cmpwi   r0, 0
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

label_8005D8C4:
    ctx->pc = 0x8005D8C4u;
    // 8005D8C4: fsub   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x8005D8C4u)) return;
    ppc_fsub(ctx, 0, 0, 31);

label_8005D8C8:
    ctx->pc = 0x8005D8C8u;
    // 8005D8C8: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005D8C8u)) return;
    ppc_frsp(ctx, 0, 0);

label_8005D8CC:
    ctx->pc = 0x8005D8CCu;
    // 8005D8CC: fmuls   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005D8CCu)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_8005D8D0:
    ctx->pc = 0x8005D8D0u;
    // 8005D8D0: fmr    f13, f0
    if (!ppc_fp_available(ctx, 0x8005D8D0u)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_8005D8D4:
    ctx->pc = 0x8005D8D4u;
    // 8005D8D4: fctiwz    f12, f13
    if (!ppc_fp_available(ctx, 0x8005D8D4u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_8005D8D8:
    ctx->pc = 0x8005D8D8u;
    // 8005D8D8: stfd     f12, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D8D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_8005D8DC:
    ctx->pc = 0x8005D8DCu;
    // 8005D8DC: lwz     r11, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005D8E0:
    // 8005D8E0: add   r29, r29, r11
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8005D8E4:
    // 8005D8E4: bc    4, 2, 0x8005D804
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D804u;
                return;
            }
            goto label_8005D804;
        }
    }

label_8005D8E8:
    ctx->pc = 0x8005D8E8u;
    ctx->downcount -= 4;
    // 8005D8E8: lis     r4, -36
    ctx->gpr[4] = ((u32)(s32)(-36) << 16);

label_8005D8EC:
    ctx->pc = 0x8005D8ECu;
    // 8005D8EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D8F0:
    ctx->pc = 0x8005D8F0u;
    // 8005D8F0: ori     r4, r4, 0xC828
    ctx->gpr[4] = ctx->gpr[4] | 0xC828u;

label_8005D8F4:
    ctx->pc = 0x8005D8F4u;
    // 8005D8F4: bl      0x80034BA8
    {
            ctx->lr = 0x8005D8F8u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005D8F8:
    ctx->pc = 0x8005D8F8u;
    ctx->downcount -= 3;
    // 8005D8F8: lwz     r0, 12(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D8FC:
    ctx->pc = 0x8005D8FCu;
    // 8005D8FC: cmpwi   r0, 2
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

label_8005D900:
    ctx->pc = 0x8005D900u;
    // 8005D900: bc    4, 2, 0x8005D9C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005D9C4;
        }
    }

label_8005D904:
    ctx->pc = 0x8005D904u;
    ctx->downcount -= 5;
    // 8005D904: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005D908:
    ctx->pc = 0x8005D908u;
    // 8005D908: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D90C:
    ctx->pc = 0x8005D90Cu;
    // 8005D90C: lfs     f1, 22540(r9)
    if (!ppc_fp_available(ctx, 0x8005D90Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22540);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005D910:
    ctx->pc = 0x8005D910u;
    // 8005D910: lis     r27, -32698
    ctx->gpr[27] = ((u32)(s32)(-32698) << 16);

label_8005D914:
    ctx->pc = 0x8005D914u;
    // 8005D914: bl      0x80034E48
    {
            ctx->lr = 0x8005D918u;
            ctx->pc = 0x80034E48u;
            return;
    }

label_8005D918:
    ctx->pc = 0x8005D918u;
    ctx->downcount -= 2;
    // 8005D918: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D91C:
    ctx->pc = 0x8005D91Cu;
    // 8005D91C: bl      0x80034DDC
    {
            ctx->lr = 0x8005D920u;
            ctx->pc = 0x80034DDCu;
            return;
    }

label_8005D920:
    ctx->pc = 0x8005D920u;
    ctx->downcount -= 24;
    // 8005D920: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_8005D924:
    ctx->pc = 0x8005D924u;
    // 8005D924: stw     r3, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005D928:
    ctx->pc = 0x8005D928u;
    // 8005D928: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8005D92C:
    ctx->pc = 0x8005D92Cu;
    // 8005D92C: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005D930:
    ctx->pc = 0x8005D930u;
    // 8005D930: lfs     f10, 4(r25)
    if (!ppc_fp_available(ctx, 0x8005D930u)) return;
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_8005D934:
    ctx->pc = 0x8005D934u;
    // 8005D934: stw     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D938:
    ctx->pc = 0x8005D938u;
    // 8005D938: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005D93C:
    ctx->pc = 0x8005D93Cu;
    // 8005D93C: lfd     f13, 22528(r11)
    if (!ppc_fp_available(ctx, 0x8005D93Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(22528);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D940:
    ctx->pc = 0x8005D940u;
    // 8005D940: or   r29, r9, r9
    {
        ctx->gpr[29] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005D944:
    ctx->pc = 0x8005D944u;
    // 8005D944: lfd     f0, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D944u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D948:
    ctx->pc = 0x8005D948u;
    // 8005D948: li      r4, 4192
    ctx->gpr[4] = (u32)(s32)(4192);

label_8005D94C:
    ctx->pc = 0x8005D94Cu;
    // 8005D94C: lfs     f11, 22544(r10)
    if (!ppc_fp_available(ctx, 0x8005D94Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(22544);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_8005D950:
    ctx->pc = 0x8005D950u;
    // 8005D950: addi    r3, r27, 9872
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(9872);

label_8005D954:
    ctx->pc = 0x8005D954u;
    // 8005D954: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x8005D954u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_8005D958:
    ctx->pc = 0x8005D958u;
    // 8005D958: lwz     r28, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8005D95C:
    ctx->pc = 0x8005D95Cu;
    // 8005D95C: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x8005D95Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_8005D960:
    ctx->pc = 0x8005D960u;
    // 8005D960: lwz     r30, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8005D964:
    ctx->pc = 0x8005D964u;
    // 8005D964: fmuls   f0, f0, f10
    if (!ppc_fp_available(ctx, 0x8005D964u)) return;
    ppc_fmuls(ctx, 0, 0, 10);

label_8005D968:
    ctx->pc = 0x8005D968u;
    // 8005D968: fmuls   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x8005D968u)) return;
    ppc_fmuls(ctx, 0, 0, 11);

label_8005D96C:
    ctx->pc = 0x8005D96Cu;
    // 8005D96C: fmr    f13, f0
    if (!ppc_fp_available(ctx, 0x8005D96Cu)) return;
    ctx->fpr[13] = ctx->fpr[0];

label_8005D970:
    ctx->pc = 0x8005D970u;
    // 8005D970: fctiwz    f12, f13
    if (!ppc_fp_available(ctx, 0x8005D970u)) return;
    { u64 result; if (ppc_fctiw(ctx, ctx->fpr[13], true, &result)) ctx->fpr[12] = dolrecomp_f64_from_bits(result); }

label_8005D974:
    ctx->pc = 0x8005D974u;
    // 8005D974: stfd     f12, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D974u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[12]));
    }

label_8005D978:
    ctx->pc = 0x8005D978u;
    // 8005D978: lwz     r29, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8005D97C:
    ctx->pc = 0x8005D97Cu;
    // 8005D97C: bl      0x80046B00
    {
            ctx->lr = 0x8005D980u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8005D980:
    ctx->pc = 0x8005D980u;
    ctx->downcount -= 5;
    // 8005D980: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005D984:
    ctx->pc = 0x8005D984u;
    // 8005D984: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005D988:
    ctx->pc = 0x8005D988u;
    // 8005D988: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005D98C:
    ctx->pc = 0x8005D98Cu;
    // 8005D98C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D990:
    ctx->pc = 0x8005D990u;
    // 8005D990: bl      0x80034E9C
    {
            ctx->lr = 0x8005D994u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8005D994:
    ctx->pc = 0x8005D994u;
    ctx->downcount -= 6;
    // 8005D994: lwz     r30, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8005D998:
    ctx->pc = 0x8005D998u;
    // 8005D998: li      r4, 4191
    ctx->gpr[4] = (u32)(s32)(4191);

label_8005D99C:
    ctx->pc = 0x8005D99Cu;
    // 8005D99C: lwz     r28, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_8005D9A0:
    ctx->pc = 0x8005D9A0u;
    // 8005D9A0: addi    r3, r27, 9872
    ctx->gpr[3] = ctx->gpr[27] + (u32)(s32)(9872);

label_8005D9A4:
    ctx->pc = 0x8005D9A4u;
    // 8005D9A4: add   r30, r30, r29
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8005D9A8:
    ctx->pc = 0x8005D9A8u;
    // 8005D9A8: bl      0x80046B00
    {
            ctx->lr = 0x8005D9ACu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_8005D9AC:
    ctx->pc = 0x8005D9ACu;
    ctx->downcount -= 5;
    // 8005D9AC: or   r6, r3, r3
    {
        ctx->gpr[6] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005D9B0:
    ctx->pc = 0x8005D9B0u;
    // 8005D9B0: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005D9B4:
    ctx->pc = 0x8005D9B4u;
    // 8005D9B4: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005D9B8:
    ctx->pc = 0x8005D9B8u;
    // 8005D9B8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005D9BC:
    ctx->pc = 0x8005D9BCu;
    // 8005D9BC: bl      0x80034E9C
    {
            ctx->lr = 0x8005D9C0u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8005D9C0:
    ctx->pc = 0x8005D9C0u;
    ctx->downcount -= 1;
    // 8005D9C0: b       0x8005DA10
    {
            goto label_8005DA10;
    }

label_8005D9C4:
    ctx->pc = 0x8005D9C4u;
    ctx->downcount -= 19;
    // 8005D9C4: lwz     r0, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005D9C8:
    ctx->pc = 0x8005D9C8u;
    // 8005D9C8: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_8005D9CC:
    ctx->pc = 0x8005D9CCu;
    // 8005D9CC: lwz     r11, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005D9D0:
    ctx->pc = 0x8005D9D0u;
    // 8005D9D0: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005D9D4:
    ctx->pc = 0x8005D9D4u;
    // 8005D9D4: or   r8, r10, r10
    {
        ctx->gpr[8] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8005D9D8:
    ctx->pc = 0x8005D9D8u;
    // 8005D9D8: stw     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005D9DC:
    ctx->pc = 0x8005D9DCu;
    // 8005D9DC: xoris   r11, r11, 0x8000
    ctx->gpr[11] = ctx->gpr[11] ^ (0x8000u << 16);

label_8005D9E0:
    ctx->pc = 0x8005D9E0u;
    // 8005D9E0: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005D9E4:
    ctx->pc = 0x8005D9E4u;
    // 8005D9E4: stw     r7, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005D9E8:
    ctx->pc = 0x8005D9E8u;
    // 8005D9E8: lfd     f0, 22528(r9)
    if (!ppc_fp_available(ctx, 0x8005D9E8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22528);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D9EC:
    ctx->pc = 0x8005D9ECu;
    // 8005D9EC: lfd     f1, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005D9ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005D9F0:
    ctx->pc = 0x8005D9F0u;
    // 8005D9F0: stw     r11, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005D9F4:
    ctx->pc = 0x8005D9F4u;
    // 8005D9F4: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x8005D9F4u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_8005D9F8:
    ctx->pc = 0x8005D9F8u;
    // 8005D9F8: stw     r7, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005D9FC:
    ctx->pc = 0x8005D9FCu;
    // 8005D9FC: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x8005D9FCu)) return;
    ppc_frsp(ctx, 1, 1);

label_8005DA00:
    ctx->pc = 0x8005DA00u;
    // 8005DA00: lfd     f2, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005DA00u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005DA04:
    ctx->pc = 0x8005DA04u;
    // 8005DA04: fsub   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x8005DA04u)) return;
    ppc_fsub(ctx, 2, 2, 0);

label_8005DA08:
    ctx->pc = 0x8005DA08u;
    // 8005DA08: frsp    f2, f2
    if (!ppc_fp_available(ctx, 0x8005DA08u)) return;
    ppc_frsp(ctx, 2, 2);

label_8005DA0C:
    ctx->pc = 0x8005DA0Cu;
    // 8005DA0C: bl      0x80133200
    {
            ctx->lr = 0x8005DA10u;
            ctx->pc = 0x80133200u;
            return;
    }

label_8005DA10:
    ctx->pc = 0x8005DA10u;
    ctx->downcount -= 4;
    // 8005DA10: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005DA14:
    ctx->pc = 0x8005DA14u;
    // 8005DA14: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DA18:
    ctx->pc = 0x8005DA18u;
    // 8005DA18: lfs     f1, 22540(r9)
    if (!ppc_fp_available(ctx, 0x8005DA18u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(22540);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005DA1C:
    ctx->pc = 0x8005DA1Cu;
    // 8005DA1C: bl      0x80034E48
    {
            ctx->lr = 0x8005DA20u;
            ctx->pc = 0x80034E48u;
            return;
    }

label_8005DA20:
    ctx->pc = 0x8005DA20u;
    ctx->downcount -= 3;
    // 8005DA20: lis     r3, -32702
    ctx->gpr[3] = ((u32)(s32)(-32702) << 16);

label_8005DA24:
    ctx->pc = 0x8005DA24u;
    // 8005DA24: addi    r3, r3, 30624
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(30624);

label_8005DA28:
    ctx->pc = 0x8005DA28u;
    // 8005DA28: bl      0x80050698
    {
            ctx->lr = 0x8005DA2Cu;
            ctx->pc = 0x80050698u;
            return;
    }

label_8005DA2C:
    ctx->pc = 0x8005DA2Cu;
    ctx->downcount -= 17;
    // 8005DA2C: lwz     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DA30:
    ctx->pc = 0x8005DA30u;
    // 8005DA30: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005DA34:
    ctx->pc = 0x8005DA34u;
    // 8005DA34: lmw     r19, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 19; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005DA38:
    ctx->pc = 0x8005DA38u;
    // 8005DA38: lfd     f31, 96(r1)
    if (!ppc_fp_available(ctx, 0x8005DA38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005DA3C:
    ctx->pc = 0x8005DA3Cu;
    // 8005DA3C: addi    r1, r1, 104
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(104);

label_8005DA40:
    ctx->pc = 0x8005DA40u;
    // 8005DA40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005DA44:
    ctx->pc = 0x8005DA44u;
    ctx->downcount -= 8;
    // 8005DA44: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005DA48:
    ctx->pc = 0x8005DA48u;
    // 8005DA48: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005DA4C:
    ctx->pc = 0x8005DA4Cu;
    // 8005DA4C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005DA50:
    ctx->pc = 0x8005DA50u;
    // 8005DA50: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DA54:
    ctx->pc = 0x8005DA54u;
    // 8005DA54: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005DA58:
    ctx->pc = 0x8005DA58u;
    // 8005DA58: lwz     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DA5C:
    ctx->pc = 0x8005DA5Cu;
    // 8005DA5C: cmpwi   r0, 33
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(33);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DA60:
    ctx->pc = 0x8005DA60u;
    // 8005DA60: bc    12, 2, 0x8005DB40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DB40;
        }
    }

label_8005DA64:
    ctx->pc = 0x8005DA64u;
    ctx->downcount -= 1;
    // 8005DA64: bc    12, 1, 0x8005DA9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DA9C;
        }
    }

label_8005DA68:
    ctx->pc = 0x8005DA68u;
    ctx->downcount -= 2;
    // 8005DA68: cmpwi   r0, 29
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(29);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DA6C:
    ctx->pc = 0x8005DA6Cu;
    // 8005DA6C: bc    12, 2, 0x8005DC50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DC50;
        }
    }

label_8005DA70:
    ctx->pc = 0x8005DA70u;
    ctx->downcount -= 1;
    // 8005DA70: bc    12, 1, 0x8005DA8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DA8C;
        }
    }

label_8005DA74:
    ctx->pc = 0x8005DA74u;
    ctx->downcount -= 2;
    // 8005DA74: cmpwi   r0, 27
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(27);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DA78:
    ctx->pc = 0x8005DA78u;
    // 8005DA78: bc    12, 2, 0x8005DC04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DC04;
        }
    }

label_8005DA7C:
    ctx->pc = 0x8005DA7Cu;
    ctx->downcount -= 1;
    // 8005DA7C: bc    12, 1, 0x8005DBD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DBD8;
        }
    }

label_8005DA80:
    ctx->pc = 0x8005DA80u;
    ctx->downcount -= 2;
    // 8005DA80: cmpwi   r0, 26
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(26);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DA84:
    ctx->pc = 0x8005DA84u;
    // 8005DA84: bc    12, 2, 0x8005DDF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DDF8;
        }
    }

label_8005DA88:
    ctx->pc = 0x8005DA88u;
    ctx->downcount -= 1;
    // 8005DA88: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DA8C:
    ctx->pc = 0x8005DA8Cu;
    ctx->downcount -= 2;
    // 8005DA8C: cmpwi   r0, 31
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(31);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DA90:
    ctx->pc = 0x8005DA90u;
    // 8005DA90: bc    12, 2, 0x8005DAD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DAD0;
        }
    }

label_8005DA94:
    ctx->pc = 0x8005DA94u;
    ctx->downcount -= 1;
    // 8005DA94: bc    12, 1, 0x8005DAF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DAF0;
        }
    }

label_8005DA98:
    ctx->pc = 0x8005DA98u;
    ctx->downcount -= 1;
    // 8005DA98: b       0x8005DC28
    {
            goto label_8005DC28;
    }

label_8005DA9C:
    ctx->pc = 0x8005DA9Cu;
    ctx->downcount -= 2;
    // 8005DA9C: cmpwi   r0, 37
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(37);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DAA0:
    ctx->pc = 0x8005DAA0u;
    // 8005DAA0: bc    12, 2, 0x8005DBA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DBA4;
        }
    }

label_8005DAA4:
    ctx->pc = 0x8005DAA4u;
    ctx->downcount -= 1;
    // 8005DAA4: bc    12, 1, 0x8005DAB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DAB8;
        }
    }

label_8005DAA8:
    ctx->pc = 0x8005DAA8u;
    ctx->downcount -= 2;
    // 8005DAA8: cmpwi   r0, 35
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(35);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DAAC:
    ctx->pc = 0x8005DAACu;
    // 8005DAAC: bc    12, 2, 0x8005E0AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E0AC;
        }
    }

label_8005DAB0:
    ctx->pc = 0x8005DAB0u;
    ctx->downcount -= 1;
    // 8005DAB0: bc    12, 1, 0x8005E0DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E0DC;
        }
    }

label_8005DAB4:
    ctx->pc = 0x8005DAB4u;
    ctx->downcount -= 1;
    // 8005DAB4: b       0x8005E078
    {
            goto label_8005E078;
    }

label_8005DAB8:
    ctx->pc = 0x8005DAB8u;
    ctx->downcount -= 2;
    // 8005DAB8: cmpwi   r0, 39
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(39);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DABC:
    ctx->pc = 0x8005DABCu;
    // 8005DABC: bc    12, 2, 0x8005DDA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DDA0;
        }
    }

label_8005DAC0:
    ctx->pc = 0x8005DAC0u;
    ctx->downcount -= 1;
    // 8005DAC0: bc    12, 0, 0x8005DBC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DBC8;
        }
    }

label_8005DAC4:
    ctx->pc = 0x8005DAC4u;
    ctx->downcount -= 2;
    // 8005DAC4: cmpwi   r0, 40
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(40);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DAC8:
    ctx->pc = 0x8005DAC8u;
    // 8005DAC8: bc    12, 2, 0x8005DDC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DDC8;
        }
    }

label_8005DACC:
    ctx->pc = 0x8005DACCu;
    ctx->downcount -= 1;
    // 8005DACC: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DAD0:
    ctx->pc = 0x8005DAD0u;
    ctx->downcount -= 5;
    // 8005DAD0: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DAD4:
    ctx->pc = 0x8005DAD4u;
    // 8005DAD4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DAD8:
    ctx->pc = 0x8005DAD8u;
    // 8005DAD8: addi    r5, r5, 22548
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22548);

label_8005DADC:
    ctx->pc = 0x8005DADCu;
    // 8005DADC: li      r4, 4205
    ctx->gpr[4] = (u32)(s32)(4205);

label_8005DAE0:
    ctx->pc = 0x8005DAE0u;
    // 8005DAE0: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DAE4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DAE4:
    ctx->pc = 0x8005DAE4u;
    ctx->downcount -= 3;
    // 8005DAE4: li      r0, 32
    ctx->gpr[0] = (u32)(s32)(32);

label_8005DAE8:
    ctx->pc = 0x8005DAE8u;
    // 8005DAE8: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DAEC:
    ctx->pc = 0x8005DAECu;
    // 8005DAEC: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DAF0:
    ctx->pc = 0x8005DAF0u;
    ctx->downcount -= 5;
    // 8005DAF0: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DAF4:
    ctx->pc = 0x8005DAF4u;
    // 8005DAF4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DAF8:
    ctx->pc = 0x8005DAF8u;
    // 8005DAF8: addi    r5, r5, 22548
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22548);

label_8005DAFC:
    ctx->pc = 0x8005DAFCu;
    // 8005DAFC: li      r4, 4205
    ctx->gpr[4] = (u32)(s32)(4205);

label_8005DB00:
    ctx->pc = 0x8005DB00u;
    // 8005DB00: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DB04u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DB04:
    ctx->pc = 0x8005DB04u;
    ctx->downcount -= 2;
    // 8005DB04: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005DB08:
    ctx->pc = 0x8005DB08u;
    // 8005DB08: bl      0x80014CA0
    {
            ctx->lr = 0x8005DB0Cu;
            ctx->pc = 0x80014CA0u;
            return;
    }

label_8005DB0C:
    ctx->pc = 0x8005DB0Cu;
    ctx->downcount -= 2;
    // 8005DB0C: or.   r3, r3, r3
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

label_8005DB10:
    ctx->pc = 0x8005DB10u;
    // 8005DB10: bc    4, 1, 0x8005DB28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DB28;
        }
    }

label_8005DB14:
    ctx->pc = 0x8005DB14u;
    ctx->downcount -= 4;
    // 8005DB14: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DB18:
    ctx->pc = 0x8005DB18u;
    // 8005DB18: li      r4, 100
    ctx->gpr[4] = (u32)(s32)(100);

label_8005DB1C:
    ctx->pc = 0x8005DB1Cu;
    // 8005DB1C: li      r5, 33
    ctx->gpr[5] = (u32)(s32)(33);

label_8005DB20:
    ctx->pc = 0x8005DB20u;
    // 8005DB20: bl      0x8005C934
    {
            ctx->lr = 0x8005DB24u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DB24:
    ctx->pc = 0x8005DB24u;
    ctx->downcount -= 1;
    // 8005DB24: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DB28:
    ctx->pc = 0x8005DB28u;
    ctx->downcount -= 5;
    // 8005DB28: stw     r3, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005DB2C:
    ctx->pc = 0x8005DB2Cu;
    // 8005DB2C: li      r4, 100
    ctx->gpr[4] = (u32)(s32)(100);

label_8005DB30:
    ctx->pc = 0x8005DB30u;
    // 8005DB30: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DB34:
    ctx->pc = 0x8005DB34u;
    // 8005DB34: li      r5, 21
    ctx->gpr[5] = (u32)(s32)(21);

label_8005DB38:
    ctx->pc = 0x8005DB38u;
    // 8005DB38: bl      0x8005C934
    {
            ctx->lr = 0x8005DB3Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DB3C:
    ctx->pc = 0x8005DB3Cu;
    ctx->downcount -= 1;
    // 8005DB3C: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DB40:
    ctx->pc = 0x8005DB40u;
    ctx->downcount -= 5;
    // 8005DB40: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DB44:
    ctx->pc = 0x8005DB44u;
    // 8005DB44: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DB48:
    ctx->pc = 0x8005DB48u;
    // 8005DB48: addi    r5, r5, 22696
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22696);

label_8005DB4C:
    ctx->pc = 0x8005DB4Cu;
    // 8005DB4C: li      r4, 4203
    ctx->gpr[4] = (u32)(s32)(4203);

label_8005DB50:
    ctx->pc = 0x8005DB50u;
    // 8005DB50: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DB54u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DB54:
    ctx->pc = 0x8005DB54u;
    ctx->downcount -= 3;
    // 8005DB54: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DB58:
    ctx->pc = 0x8005DB58u;
    // 8005DB58: cmpwi   r0, 0
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

label_8005DB5C:
    ctx->pc = 0x8005DB5Cu;
    // 8005DB5C: bc    4, 2, 0x8005DB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DB88;
        }
    }

label_8005DB60:
    ctx->pc = 0x8005DB60u;
    ctx->downcount -= 1;
    // 8005DB60: bl      0x8003F258
    {
            ctx->lr = 0x8005DB64u;
            ctx->pc = 0x8003F258u;
            return;
    }

label_8005DB64:
    ctx->pc = 0x8005DB64u;
    ctx->downcount -= 2;
    // 8005DB64: cmpwi   r3, 0
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

label_8005DB68:
    ctx->pc = 0x8005DB68u;
    // 8005DB68: bc    4, 0, 0x8005DB80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DB80;
        }
    }

label_8005DB6C:
    ctx->pc = 0x8005DB6Cu;
    ctx->downcount -= 4;
    // 8005DB6C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DB70:
    ctx->pc = 0x8005DB70u;
    // 8005DB70: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8005DB74:
    ctx->pc = 0x8005DB74u;
    // 8005DB74: li      r5, 14
    ctx->gpr[5] = (u32)(s32)(14);

label_8005DB78:
    ctx->pc = 0x8005DB78u;
    // 8005DB78: bl      0x8005C934
    {
            ctx->lr = 0x8005DB7Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DB7C:
    ctx->pc = 0x8005DB7Cu;
    ctx->downcount -= 1;
    // 8005DB7C: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DB80:
    ctx->pc = 0x8005DB80u;
    ctx->downcount -= 2;
    // 8005DB80: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DB84:
    ctx->pc = 0x8005DB84u;
    // 8005DB84: b       0x8005DB94
    {
            goto label_8005DB94;
    }

label_8005DB88:
    ctx->pc = 0x8005DB88u;
    ctx->downcount -= 3;
    // 8005DB88: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8005DB8C:
    ctx->pc = 0x8005DB8Cu;
    // 8005DB8C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DB90:
    ctx->pc = 0x8005DB90u;
    // 8005DB90: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DB94:
    ctx->pc = 0x8005DB94u;
    ctx->downcount -= 3;
    // 8005DB94: li      r4, 150
    ctx->gpr[4] = (u32)(s32)(150);

label_8005DB98:
    ctx->pc = 0x8005DB98u;
    // 8005DB98: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_8005DB9C:
    ctx->pc = 0x8005DB9Cu;
    // 8005DB9C: bl      0x8005C934
    {
            ctx->lr = 0x8005DBA0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DBA0:
    ctx->pc = 0x8005DBA0u;
    ctx->downcount -= 1;
    // 8005DBA0: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DBA4:
    ctx->pc = 0x8005DBA4u;
    ctx->downcount -= 5;
    // 8005DBA4: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DBA8:
    ctx->pc = 0x8005DBA8u;
    // 8005DBA8: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005DBAC:
    ctx->pc = 0x8005DBACu;
    // 8005DBAC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DBB0:
    ctx->pc = 0x8005DBB0u;
    // 8005DBB0: addi    r5, r5, 22712
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22712);

label_8005DBB4:
    ctx->pc = 0x8005DBB4u;
    // 8005DBB4: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DBB8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DBB8:
    ctx->pc = 0x8005DBB8u;
    ctx->downcount -= 4;
    // 8005DBB8: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DBBC:
    ctx->pc = 0x8005DBBCu;
    // 8005DBBC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DBC0:
    ctx->pc = 0x8005DBC0u;
    // 8005DBC0: addi    r4, r4, 5432
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5432);

label_8005DBC4:
    ctx->pc = 0x8005DBC4u;
    // 8005DBC4: b       0x8005E11C
    {
            goto label_8005E11C;
    }

label_8005DBC8:
    ctx->pc = 0x8005DBC8u;
    ctx->downcount -= 1;
    // 8005DBC8: bl      0x80014CC0
    {
            ctx->lr = 0x8005DBCCu;
            ctx->pc = 0x80014CC0u;
            return;
    }

label_8005DBCC:
    ctx->pc = 0x8005DBCCu;
    ctx->downcount -= 3;
    // 8005DBCC: li      r0, 15
    ctx->gpr[0] = (u32)(s32)(15);

label_8005DBD0:
    ctx->pc = 0x8005DBD0u;
    // 8005DBD0: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DBD4:
    ctx->pc = 0x8005DBD4u;
    // 8005DBD4: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DBD8:
    ctx->pc = 0x8005DBD8u;
    ctx->downcount -= 1;
    // 8005DBD8: bl      0x80199590
    {
            ctx->lr = 0x8005DBDCu;
            ctx->pc = 0x80199590u;
            return;
    }

label_8005DBDC:
    ctx->pc = 0x8005DBDCu;
    ctx->downcount -= 1;
    // 8005DBDC: bl      0x8019931C
    {
            ctx->lr = 0x8005DBE0u;
            ctx->pc = 0x8019931Cu;
            return;
    }

label_8005DBE0:
    ctx->pc = 0x8005DBE0u;
    ctx->downcount -= 2;
    // 8005DBE0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005DBE4:
    ctx->pc = 0x8005DBE4u;
    // 8005DBE4: bl      0x80187494
    {
            ctx->lr = 0x8005DBE8u;
            ctx->pc = 0x80187494u;
            return;
    }

label_8005DBE8:
    ctx->pc = 0x8005DBE8u;
    ctx->downcount -= 1;
    // 8005DBE8: bl      0x801872A0
    {
            ctx->lr = 0x8005DBECu;
            ctx->pc = 0x801872A0u;
            return;
    }

label_8005DBEC:
    ctx->pc = 0x8005DBECu;
    ctx->downcount -= 1;
    // 8005DBEC: bl      0x80185E5C
    {
            ctx->lr = 0x8005DBF0u;
            ctx->pc = 0x80185E5Cu;
            return;
    }

label_8005DBF0:
    ctx->pc = 0x8005DBF0u;
    ctx->downcount -= 4;
    // 8005DBF0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005DBF4:
    ctx->pc = 0x8005DBF4u;
    // 8005DBF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005DBF8:
    ctx->pc = 0x8005DBF8u;
    // 8005DBF8: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8005DBFC:
    ctx->pc = 0x8005DBFCu;
    // 8005DBFC: bl      0x80175F50
    {
            ctx->lr = 0x8005DC00u;
            ctx->pc = 0x80175F50u;
            return;
    }

label_8005DC00:
    ctx->pc = 0x8005DC00u;
    ctx->downcount -= 1;
    // 8005DC00: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DC04:
    ctx->pc = 0x8005DC04u;
    ctx->downcount -= 5;
    // 8005DC04: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DC08:
    ctx->pc = 0x8005DC08u;
    // 8005DC08: li      r4, 4207
    ctx->gpr[4] = (u32)(s32)(4207);

label_8005DC0C:
    ctx->pc = 0x8005DC0Cu;
    // 8005DC0C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DC10:
    ctx->pc = 0x8005DC10u;
    // 8005DC10: addi    r5, r5, 22756
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22756);

label_8005DC14:
    ctx->pc = 0x8005DC14u;
    // 8005DC14: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DC18u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DC18:
    ctx->pc = 0x8005DC18u;
    ctx->downcount -= 4;
    // 8005DC18: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DC1C:
    ctx->pc = 0x8005DC1Cu;
    // 8005DC1C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DC20:
    ctx->pc = 0x8005DC20u;
    // 8005DC20: addi    r4, r4, 5468
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5468);

label_8005DC24:
    ctx->pc = 0x8005DC24u;
    // 8005DC24: b       0x8005DD94
    {
            goto label_8005DD94;
    }

label_8005DC28:
    ctx->pc = 0x8005DC28u;
    ctx->downcount -= 5;
    // 8005DC28: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DC2C:
    ctx->pc = 0x8005DC2Cu;
    // 8005DC2C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DC30:
    ctx->pc = 0x8005DC30u;
    // 8005DC30: addi    r5, r5, 22832
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22832);

label_8005DC34:
    ctx->pc = 0x8005DC34u;
    // 8005DC34: li      r4, 4637
    ctx->gpr[4] = (u32)(s32)(4637);

label_8005DC38:
    ctx->pc = 0x8005DC38u;
    // 8005DC38: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DC3Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DC3C:
    ctx->pc = 0x8005DC3Cu;
    ctx->downcount -= 4;
    // 8005DC3C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DC40:
    ctx->pc = 0x8005DC40u;
    // 8005DC40: li      r4, 100
    ctx->gpr[4] = (u32)(s32)(100);

label_8005DC44:
    ctx->pc = 0x8005DC44u;
    // 8005DC44: li      r5, 29
    ctx->gpr[5] = (u32)(s32)(29);

label_8005DC48:
    ctx->pc = 0x8005DC48u;
    // 8005DC48: bl      0x8005C934
    {
            ctx->lr = 0x8005DC4Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DC4C:
    ctx->pc = 0x8005DC4Cu;
    ctx->downcount -= 1;
    // 8005DC4C: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DC50:
    ctx->pc = 0x8005DC50u;
    ctx->downcount -= 3;
    // 8005DC50: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DC54:
    ctx->pc = 0x8005DC54u;
    // 8005DC54: cmpwi   r0, 2
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

label_8005DC58:
    ctx->pc = 0x8005DC58u;
    // 8005DC58: bc    4, 2, 0x8005DC68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DC68;
        }
    }

label_8005DC5C:
    ctx->pc = 0x8005DC5Cu;
    ctx->downcount -= 2;
    // 8005DC5C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005DC60:
    ctx->pc = 0x8005DC60u;
    // 8005DC60: bl      0x800148DC
    {
            ctx->lr = 0x8005DC64u;
            ctx->pc = 0x800148DCu;
            return;
    }

label_8005DC64:
    ctx->pc = 0x8005DC64u;
    ctx->downcount -= 1;
    // 8005DC64: b       0x8005DC70
    {
            goto label_8005DC70;
    }

label_8005DC68:
    ctx->pc = 0x8005DC68u;
    ctx->downcount -= 2;
    // 8005DC68: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005DC6C:
    ctx->pc = 0x8005DC6Cu;
    // 8005DC6C: bl      0x800148DC
    {
            ctx->lr = 0x8005DC70u;
            ctx->pc = 0x800148DCu;
            return;
    }

label_8005DC70:
    ctx->pc = 0x8005DC70u;
    ctx->downcount -= 2;
    // 8005DC70: cmpwi   r3, 0
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

label_8005DC74:
    ctx->pc = 0x8005DC74u;
    // 8005DC74: bc    4, 1, 0x8005DCC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DCC0;
        }
    }

label_8005DC78:
    ctx->pc = 0x8005DC78u;
    ctx->downcount -= 5;
    // 8005DC78: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DC7C:
    ctx->pc = 0x8005DC7Cu;
    // 8005DC7C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DC80:
    ctx->pc = 0x8005DC80u;
    // 8005DC80: addi    r5, r5, 22916
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22916);

label_8005DC84:
    ctx->pc = 0x8005DC84u;
    // 8005DC84: li      r4, 4208
    ctx->gpr[4] = (u32)(s32)(4208);

label_8005DC88:
    ctx->pc = 0x8005DC88u;
    // 8005DC88: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DC8Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DC8C:
    ctx->pc = 0x8005DC8Cu;
    ctx->downcount -= 3;
    // 8005DC8C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DC90:
    ctx->pc = 0x8005DC90u;
    // 8005DC90: cmpwi   r0, 2
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

label_8005DC94:
    ctx->pc = 0x8005DC94u;
    // 8005DC94: bc    4, 2, 0x8005DCAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DCAC;
        }
    }

label_8005DC98:
    ctx->pc = 0x8005DC98u;
    ctx->downcount -= 4;
    // 8005DC98: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DC9C:
    ctx->pc = 0x8005DC9Cu;
    // 8005DC9C: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8005DCA0:
    ctx->pc = 0x8005DCA0u;
    // 8005DCA0: li      r5, 39
    ctx->gpr[5] = (u32)(s32)(39);

label_8005DCA4:
    ctx->pc = 0x8005DCA4u;
    // 8005DCA4: bl      0x8005C934
    {
            ctx->lr = 0x8005DCA8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DCA8:
    ctx->pc = 0x8005DCA8u;
    ctx->downcount -= 1;
    // 8005DCA8: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DCAC:
    ctx->pc = 0x8005DCACu;
    ctx->downcount -= 4;
    // 8005DCAC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DCB0:
    ctx->pc = 0x8005DCB0u;
    // 8005DCB0: li      r4, 120
    ctx->gpr[4] = (u32)(s32)(120);

label_8005DCB4:
    ctx->pc = 0x8005DCB4u;
    // 8005DCB4: li      r5, 5
    ctx->gpr[5] = (u32)(s32)(5);

label_8005DCB8:
    ctx->pc = 0x8005DCB8u;
    // 8005DCB8: bl      0x8005C934
    {
            ctx->lr = 0x8005DCBCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DCBC:
    ctx->pc = 0x8005DCBCu;
    ctx->downcount -= 1;
    // 8005DCBC: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DCC0:
    ctx->pc = 0x8005DCC0u;
    ctx->downcount -= 3;
    // 8005DCC0: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DCC4:
    ctx->pc = 0x8005DCC4u;
    // 8005DCC4: cmpwi   r0, 2
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

label_8005DCC8:
    ctx->pc = 0x8005DCC8u;
    // 8005DCC8: bc    4, 2, 0x8005DCF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DCF0;
        }
    }

label_8005DCCC:
    ctx->pc = 0x8005DCCCu;
    ctx->downcount -= 5;
    // 8005DCCC: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DCD0:
    ctx->pc = 0x8005DCD0u;
    // 8005DCD0: li      r4, 4209
    ctx->gpr[4] = (u32)(s32)(4209);

label_8005DCD4:
    ctx->pc = 0x8005DCD4u;
    // 8005DCD4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DCD8:
    ctx->pc = 0x8005DCD8u;
    // 8005DCD8: addi    r5, r5, 22936
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22936);

label_8005DCDC:
    ctx->pc = 0x8005DCDCu;
    // 8005DCDC: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DCE0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DCE0:
    ctx->pc = 0x8005DCE0u;
    ctx->downcount -= 4;
    // 8005DCE0: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DCE4:
    ctx->pc = 0x8005DCE4u;
    // 8005DCE4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DCE8:
    ctx->pc = 0x8005DCE8u;
    // 8005DCE8: addi    r4, r4, 5504
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5504);

label_8005DCEC:
    ctx->pc = 0x8005DCECu;
    // 8005DCEC: b       0x8005DD94
    {
            goto label_8005DD94;
    }

label_8005DCF0:
    ctx->pc = 0x8005DCF0u;
    ctx->downcount -= 2;
    // 8005DCF0: cmpwi   r3, -94
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

label_8005DCF4:
    ctx->pc = 0x8005DCF4u;
    // 8005DCF4: bc    4, 2, 0x8005DD38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DD38;
        }
    }

label_8005DCF8:
    ctx->pc = 0x8005DCF8u;
    ctx->downcount -= 5;
    // 8005DCF8: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DCFC:
    ctx->pc = 0x8005DCFCu;
    // 8005DCFC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DD00:
    ctx->pc = 0x8005DD00u;
    // 8005DD00: addi    r5, r5, 23008
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23008);

label_8005DD04:
    ctx->pc = 0x8005DD04u;
    // 8005DD04: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005DD08:
    ctx->pc = 0x8005DD08u;
    // 8005DD08: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DD0Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DD0C:
    ctx->pc = 0x8005DD0Cu;
    ctx->downcount -= 3;
    // 8005DD0C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DD10:
    ctx->pc = 0x8005DD10u;
    // 8005DD10: cmpwi   r0, 0
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

label_8005DD14:
    ctx->pc = 0x8005DD14u;
    // 8005DD14: bc    4, 2, 0x8005DD28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DD28;
        }
    }

label_8005DD18:
    ctx->pc = 0x8005DD18u;
    ctx->downcount -= 4;
    // 8005DD18: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DD1C:
    ctx->pc = 0x8005DD1Cu;
    // 8005DD1C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DD20:
    ctx->pc = 0x8005DD20u;
    // 8005DD20: addi    r4, r4, 5540
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5540);

label_8005DD24:
    ctx->pc = 0x8005DD24u;
    // 8005DD24: b       0x8005DD94
    {
            goto label_8005DD94;
    }

label_8005DD28:
    ctx->pc = 0x8005DD28u;
    ctx->downcount -= 4;
    // 8005DD28: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DD2C:
    ctx->pc = 0x8005DD2Cu;
    // 8005DD2C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DD30:
    ctx->pc = 0x8005DD30u;
    // 8005DD30: addi    r4, r4, 5564
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5564);

label_8005DD34:
    ctx->pc = 0x8005DD34u;
    // 8005DD34: b       0x8005DD94
    {
            goto label_8005DD94;
    }

label_8005DD38:
    ctx->pc = 0x8005DD38u;
    ctx->downcount -= 2;
    // 8005DD38: cmpwi   r3, -89
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(-89);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DD3C:
    ctx->pc = 0x8005DD3Cu;
    // 8005DD3C: bc    4, 2, 0x8005DD58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DD58;
        }
    }

label_8005DD40:
    ctx->pc = 0x8005DD40u;
    ctx->downcount -= 6;
    // 8005DD40: lwz     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DD44:
    ctx->pc = 0x8005DD44u;
    // 8005DD44: li      r9, 26
    ctx->gpr[9] = (u32)(s32)(26);

label_8005DD48:
    ctx->pc = 0x8005DD48u;
    // 8005DD48: stw     r3, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005DD4C:
    ctx->pc = 0x8005DD4Cu;
    // 8005DD4C: stw     r0, 136(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DD50:
    ctx->pc = 0x8005DD50u;
    // 8005DD50: stw     r9, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005DD54:
    ctx->pc = 0x8005DD54u;
    // 8005DD54: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DD58:
    ctx->pc = 0x8005DD58u;
    ctx->downcount -= 5;
    // 8005DD58: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DD5C:
    ctx->pc = 0x8005DD5Cu;
    // 8005DD5C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DD60:
    ctx->pc = 0x8005DD60u;
    // 8005DD60: addi    r5, r5, 22936
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(22936);

label_8005DD64:
    ctx->pc = 0x8005DD64u;
    // 8005DD64: li      r4, 4209
    ctx->gpr[4] = (u32)(s32)(4209);

label_8005DD68:
    ctx->pc = 0x8005DD68u;
    // 8005DD68: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DD6Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DD6C:
    ctx->pc = 0x8005DD6Cu;
    ctx->downcount -= 3;
    // 8005DD6C: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DD70:
    ctx->pc = 0x8005DD70u;
    // 8005DD70: cmpwi   r0, 0
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

label_8005DD74:
    ctx->pc = 0x8005DD74u;
    // 8005DD74: bc    4, 2, 0x8005DD88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DD88;
        }
    }

label_8005DD78:
    ctx->pc = 0x8005DD78u;
    ctx->downcount -= 4;
    // 8005DD78: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DD7C:
    ctx->pc = 0x8005DD7Cu;
    // 8005DD7C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DD80:
    ctx->pc = 0x8005DD80u;
    // 8005DD80: addi    r4, r4, 5588
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5588);

label_8005DD84:
    ctx->pc = 0x8005DD84u;
    // 8005DD84: b       0x8005DD94
    {
            goto label_8005DD94;
    }

label_8005DD88:
    ctx->pc = 0x8005DD88u;
    ctx->downcount -= 3;
    // 8005DD88: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DD8C:
    ctx->pc = 0x8005DD8Cu;
    // 8005DD8C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DD90:
    ctx->pc = 0x8005DD90u;
    // 8005DD90: addi    r4, r4, 5612
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5612);

label_8005DD94:
    ctx->pc = 0x8005DD94u;
    ctx->downcount -= 2;
    // 8005DD94: li      r5, 8
    ctx->gpr[5] = (u32)(s32)(8);

label_8005DD98:
    ctx->pc = 0x8005DD98u;
    // 8005DD98: bl      0x8005C950
    {
            ctx->lr = 0x8005DD9Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005DD9C:
    ctx->pc = 0x8005DD9Cu;
    ctx->downcount -= 1;
    // 8005DD9C: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DDA0:
    ctx->pc = 0x8005DDA0u;
    ctx->downcount -= 5;
    // 8005DDA0: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DDA4:
    ctx->pc = 0x8005DDA4u;
    // 8005DDA4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DDA8:
    ctx->pc = 0x8005DDA8u;
    // 8005DDA8: addi    r5, r5, 21744
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21744);

label_8005DDAC:
    ctx->pc = 0x8005DDACu;
    // 8005DDAC: li      r4, 4198
    ctx->gpr[4] = (u32)(s32)(4198);

label_8005DDB0:
    ctx->pc = 0x8005DDB0u;
    // 8005DDB0: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DDB4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DDB4:
    ctx->pc = 0x8005DDB4u;
    ctx->downcount -= 4;
    // 8005DDB4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DDB8:
    ctx->pc = 0x8005DDB8u;
    // 8005DDB8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005DDBC:
    ctx->pc = 0x8005DDBCu;
    // 8005DDBC: li      r5, 40
    ctx->gpr[5] = (u32)(s32)(40);

label_8005DDC0:
    ctx->pc = 0x8005DDC0u;
    // 8005DDC0: bl      0x8005C934
    {
            ctx->lr = 0x8005DDC4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DDC4:
    ctx->pc = 0x8005DDC4u;
    ctx->downcount -= 1;
    // 8005DDC4: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DDC8:
    ctx->pc = 0x8005DDC8u;
    ctx->downcount -= 1;
    // 8005DDC8: bl      0x80014A94
    {
            ctx->lr = 0x8005DDCCu;
            ctx->pc = 0x80014A94u;
            return;
    }

label_8005DDCC:
    ctx->pc = 0x8005DDCCu;
    ctx->downcount -= 2;
    // 8005DDCC: or.   r3, r3, r3
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

label_8005DDD0:
    ctx->pc = 0x8005DDD0u;
    // 8005DDD0: bc    4, 1, 0x8005DDE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DDE8;
        }
    }

label_8005DDD4:
    ctx->pc = 0x8005DDD4u;
    ctx->downcount -= 4;
    // 8005DDD4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DDD8:
    ctx->pc = 0x8005DDD8u;
    // 8005DDD8: li      r4, 100
    ctx->gpr[4] = (u32)(s32)(100);

label_8005DDDC:
    ctx->pc = 0x8005DDDCu;
    // 8005DDDC: li      r5, 10
    ctx->gpr[5] = (u32)(s32)(10);

label_8005DDE0:
    ctx->pc = 0x8005DDE0u;
    // 8005DDE0: bl      0x8005C934
    {
            ctx->lr = 0x8005DDE4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005DDE4:
    ctx->pc = 0x8005DDE4u;
    ctx->downcount -= 1;
    // 8005DDE4: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DDE8:
    ctx->pc = 0x8005DDE8u;
    ctx->downcount -= 4;
    // 8005DDE8: li      r0, 26
    ctx->gpr[0] = (u32)(s32)(26);

label_8005DDEC:
    ctx->pc = 0x8005DDECu;
    // 8005DDEC: stw     r3, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005DDF0:
    ctx->pc = 0x8005DDF0u;
    // 8005DDF0: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DDF4:
    ctx->pc = 0x8005DDF4u;
    // 8005DDF4: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DDF8:
    ctx->pc = 0x8005DDF8u;
    ctx->downcount -= 3;
    // 8005DDF8: lwz     r0, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DDFC:
    ctx->pc = 0x8005DDFCu;
    // 8005DDFC: cmpwi   r0, -89
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-89);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DE00:
    ctx->pc = 0x8005DE00u;
    // 8005DE00: bc    12, 2, 0x8005DE44
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DE44;
        }
    }

label_8005DE04:
    ctx->pc = 0x8005DE04u;
    ctx->downcount -= 1;
    // 8005DE04: bc    12, 1, 0x8005DE2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DE2C;
        }
    }

label_8005DE08:
    ctx->pc = 0x8005DE08u;
    ctx->downcount -= 2;
    // 8005DE08: cmpwi   r0, -92
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-92);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DE0C:
    ctx->pc = 0x8005DE0Cu;
    // 8005DE0C: bc    12, 2, 0x8005DF04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DF04;
        }
    }

label_8005DE10:
    ctx->pc = 0x8005DE10u;
    ctx->downcount -= 1;
    // 8005DE10: bc    12, 1, 0x8005DE20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DE20;
        }
    }

label_8005DE14:
    ctx->pc = 0x8005DE14u;
    ctx->downcount -= 2;
    // 8005DE14: cmpwi   r0, -93
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-93);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DE18:
    ctx->pc = 0x8005DE18u;
    // 8005DE18: bc    12, 2, 0x8005DF54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DF54;
        }
    }

label_8005DE1C:
    ctx->pc = 0x8005DE1Cu;
    ctx->downcount -= 1;
    // 8005DE1C: b       0x8005E014
    {
            goto label_8005E014;
    }

label_8005DE20:
    ctx->pc = 0x8005DE20u;
    ctx->downcount -= 2;
    // 8005DE20: cmpwi   r0, -90
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-90);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DE24:
    ctx->pc = 0x8005DE24u;
    // 8005DE24: bc    12, 2, 0x8005DE94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DE94;
        }
    }

label_8005DE28:
    ctx->pc = 0x8005DE28u;
    ctx->downcount -= 1;
    // 8005DE28: b       0x8005E014
    {
            goto label_8005E014;
    }

label_8005DE2C:
    ctx->pc = 0x8005DE2Cu;
    ctx->downcount -= 2;
    // 8005DE2C: cmpwi   r0, -87
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-87);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DE30:
    ctx->pc = 0x8005DE30u;
    // 8005DE30: bc    12, 2, 0x8005DFFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DFFC;
        }
    }

label_8005DE34:
    ctx->pc = 0x8005DE34u;
    ctx->downcount -= 1;
    // 8005DE34: bc    12, 0, 0x8005DFAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005DFAC;
        }
    }

label_8005DE38:
    ctx->pc = 0x8005DE38u;
    ctx->downcount -= 2;
    // 8005DE38: cmpwi   r0, -86
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(-86);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005DE3C:
    ctx->pc = 0x8005DE3Cu;
    // 8005DE3C: bc    12, 2, 0x8005E008
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E008;
        }
    }

label_8005DE40:
    ctx->pc = 0x8005DE40u;
    ctx->downcount -= 1;
    // 8005DE40: b       0x8005E014
    {
            goto label_8005E014;
    }

label_8005DE44:
    ctx->pc = 0x8005DE44u;
    ctx->downcount -= 5;
    // 8005DE44: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DE48:
    ctx->pc = 0x8005DE48u;
    // 8005DE48: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DE4C:
    ctx->pc = 0x8005DE4Cu;
    // 8005DE4C: addi    r5, r5, 23080
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23080);

label_8005DE50:
    ctx->pc = 0x8005DE50u;
    // 8005DE50: li      r4, 4211
    ctx->gpr[4] = (u32)(s32)(4211);

label_8005DE54:
    ctx->pc = 0x8005DE54u;
    // 8005DE54: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DE58u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DE58:
    ctx->pc = 0x8005DE58u;
    ctx->downcount -= 3;
    // 8005DE58: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DE5C:
    ctx->pc = 0x8005DE5Cu;
    // 8005DE5C: cmpwi   r0, 2
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

label_8005DE60:
    ctx->pc = 0x8005DE60u;
    // 8005DE60: bc    4, 2, 0x8005DE74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DE74;
        }
    }

label_8005DE64:
    ctx->pc = 0x8005DE64u;
    ctx->downcount -= 4;
    // 8005DE64: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DE68:
    ctx->pc = 0x8005DE68u;
    // 8005DE68: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DE6C:
    ctx->pc = 0x8005DE6Cu;
    // 8005DE6C: addi    r4, r4, 5636
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5636);

label_8005DE70:
    ctx->pc = 0x8005DE70u;
    // 8005DE70: b       0x8005E11C
    {
            goto label_8005E11C;
    }

label_8005DE74:
    ctx->pc = 0x8005DE74u;
    ctx->downcount -= 5;
    // 8005DE74: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005DE78:
    ctx->pc = 0x8005DE78u;
    // 8005DE78: cmpwi   r0, 0
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

label_8005DE7C:
    ctx->pc = 0x8005DE7Cu;
    // 8005DE7C: addi    r4, r9, 5672
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(5672);

label_8005DE80:
    ctx->pc = 0x8005DE80u;
    // 8005DE80: li      r0, 11
    ctx->gpr[0] = (u32)(s32)(11);

label_8005DE84:
    ctx->pc = 0x8005DE84u;
    // 8005DE84: bc    4, 2, 0x8005DE8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DE8C;
        }
    }

label_8005DE88:
    ctx->pc = 0x8005DE88u;
    ctx->downcount -= 1;
    // 8005DE88: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8005DE8C:
    ctx->pc = 0x8005DE8Cu;
    ctx->downcount -= 2;
    // 8005DE8C: stw     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DE90:
    ctx->pc = 0x8005DE90u;
    // 8005DE90: b       0x8005E068
    {
            goto label_8005E068;
    }

label_8005DE94:
    ctx->pc = 0x8005DE94u;
    ctx->downcount -= 3;
    // 8005DE94: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DE98:
    ctx->pc = 0x8005DE98u;
    // 8005DE98: cmpwi   r0, 2
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

label_8005DE9C:
    ctx->pc = 0x8005DE9Cu;
    // 8005DE9C: bc    4, 2, 0x8005DEC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DEC4;
        }
    }

label_8005DEA0:
    ctx->pc = 0x8005DEA0u;
    ctx->downcount -= 5;
    // 8005DEA0: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DEA4:
    ctx->pc = 0x8005DEA4u;
    // 8005DEA4: li      r4, 4638
    ctx->gpr[4] = (u32)(s32)(4638);

label_8005DEA8:
    ctx->pc = 0x8005DEA8u;
    // 8005DEA8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DEAC:
    ctx->pc = 0x8005DEACu;
    // 8005DEAC: addi    r5, r5, 23140
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23140);

label_8005DEB0:
    ctx->pc = 0x8005DEB0u;
    // 8005DEB0: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DEB4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DEB4:
    ctx->pc = 0x8005DEB4u;
    ctx->downcount -= 4;
    // 8005DEB4: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DEB8:
    ctx->pc = 0x8005DEB8u;
    // 8005DEB8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DEBC:
    ctx->pc = 0x8005DEBCu;
    // 8005DEBC: addi    r4, r4, 5708
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5708);

label_8005DEC0:
    ctx->pc = 0x8005DEC0u;
    // 8005DEC0: b       0x8005E11C
    {
            goto label_8005E11C;
    }

label_8005DEC4:
    ctx->pc = 0x8005DEC4u;
    ctx->downcount -= 5;
    // 8005DEC4: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DEC8:
    ctx->pc = 0x8005DEC8u;
    // 8005DEC8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DECC:
    ctx->pc = 0x8005DECCu;
    // 8005DECC: addi    r5, r5, 23140
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23140);

label_8005DED0:
    ctx->pc = 0x8005DED0u;
    // 8005DED0: li      r4, 4638
    ctx->gpr[4] = (u32)(s32)(4638);

label_8005DED4:
    ctx->pc = 0x8005DED4u;
    // 8005DED4: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DED8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DED8:
    ctx->pc = 0x8005DED8u;
    ctx->downcount -= 3;
    // 8005DED8: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DEDC:
    ctx->pc = 0x8005DEDCu;
    // 8005DEDC: cmpwi   r0, 0
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

label_8005DEE0:
    ctx->pc = 0x8005DEE0u;
    // 8005DEE0: bc    4, 2, 0x8005DEF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DEF4;
        }
    }

label_8005DEE4:
    ctx->pc = 0x8005DEE4u;
    ctx->downcount -= 4;
    // 8005DEE4: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DEE8:
    ctx->pc = 0x8005DEE8u;
    // 8005DEE8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DEEC:
    ctx->pc = 0x8005DEECu;
    // 8005DEEC: addi    r4, r4, 5756
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5756);

label_8005DEF0:
    ctx->pc = 0x8005DEF0u;
    // 8005DEF0: b       0x8005E06C
    {
            goto label_8005E06C;
    }

label_8005DEF4:
    ctx->pc = 0x8005DEF4u;
    ctx->downcount -= 4;
    // 8005DEF4: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DEF8:
    ctx->pc = 0x8005DEF8u;
    // 8005DEF8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DEFC:
    ctx->pc = 0x8005DEFCu;
    // 8005DEFC: addi    r4, r4, 5804
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5804);

label_8005DF00:
    ctx->pc = 0x8005DF00u;
    // 8005DF00: b       0x8005E06C
    {
            goto label_8005E06C;
    }

label_8005DF04:
    ctx->pc = 0x8005DF04u;
    ctx->downcount -= 5;
    // 8005DF04: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DF08:
    ctx->pc = 0x8005DF08u;
    // 8005DF08: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DF0C:
    ctx->pc = 0x8005DF0Cu;
    // 8005DF0C: addi    r5, r5, 23244
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23244);

label_8005DF10:
    ctx->pc = 0x8005DF10u;
    // 8005DF10: li      r4, 4639
    ctx->gpr[4] = (u32)(s32)(4639);

label_8005DF14:
    ctx->pc = 0x8005DF14u;
    // 8005DF14: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DF18u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DF18:
    ctx->pc = 0x8005DF18u;
    ctx->downcount -= 3;
    // 8005DF18: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DF1C:
    ctx->pc = 0x8005DF1Cu;
    // 8005DF1C: cmpwi   r0, 2
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

label_8005DF20:
    ctx->pc = 0x8005DF20u;
    // 8005DF20: bc    4, 2, 0x8005DF34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DF34;
        }
    }

label_8005DF24:
    ctx->pc = 0x8005DF24u;
    ctx->downcount -= 4;
    // 8005DF24: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DF28:
    ctx->pc = 0x8005DF28u;
    // 8005DF28: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DF2C:
    ctx->pc = 0x8005DF2Cu;
    // 8005DF2C: addi    r4, r4, 5852
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5852);

label_8005DF30:
    ctx->pc = 0x8005DF30u;
    // 8005DF30: b       0x8005E11C
    {
            goto label_8005E11C;
    }

label_8005DF34:
    ctx->pc = 0x8005DF34u;
    ctx->downcount -= 5;
    // 8005DF34: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005DF38:
    ctx->pc = 0x8005DF38u;
    // 8005DF38: cmpwi   r0, 0
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

label_8005DF3C:
    ctx->pc = 0x8005DF3Cu;
    // 8005DF3C: addi    r4, r9, 5888
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(5888);

label_8005DF40:
    ctx->pc = 0x8005DF40u;
    // 8005DF40: li      r0, 11
    ctx->gpr[0] = (u32)(s32)(11);

label_8005DF44:
    ctx->pc = 0x8005DF44u;
    // 8005DF44: bc    4, 2, 0x8005DF4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DF4C;
        }
    }

label_8005DF48:
    ctx->pc = 0x8005DF48u;
    ctx->downcount -= 1;
    // 8005DF48: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8005DF4C:
    ctx->pc = 0x8005DF4Cu;
    ctx->downcount -= 2;
    // 8005DF4C: stw     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DF50:
    ctx->pc = 0x8005DF50u;
    // 8005DF50: b       0x8005E068
    {
            goto label_8005E068;
    }

label_8005DF54:
    ctx->pc = 0x8005DF54u;
    ctx->downcount -= 3;
    // 8005DF54: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DF58:
    ctx->pc = 0x8005DF58u;
    // 8005DF58: cmpwi   r0, 2
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

label_8005DF5C:
    ctx->pc = 0x8005DF5Cu;
    // 8005DF5C: bc    4, 2, 0x8005DF6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DF6C;
        }
    }

label_8005DF60:
    ctx->pc = 0x8005DF60u;
    ctx->downcount -= 3;
    // 8005DF60: li      r0, 18
    ctx->gpr[0] = (u32)(s32)(18);

label_8005DF64:
    ctx->pc = 0x8005DF64u;
    // 8005DF64: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DF68:
    ctx->pc = 0x8005DF68u;
    // 8005DF68: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005DF6C:
    ctx->pc = 0x8005DF6Cu;
    ctx->downcount -= 5;
    // 8005DF6C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DF70:
    ctx->pc = 0x8005DF70u;
    // 8005DF70: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DF74:
    ctx->pc = 0x8005DF74u;
    // 8005DF74: addi    r5, r5, 23140
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23140);

label_8005DF78:
    ctx->pc = 0x8005DF78u;
    // 8005DF78: li      r4, 4638
    ctx->gpr[4] = (u32)(s32)(4638);

label_8005DF7C:
    ctx->pc = 0x8005DF7Cu;
    // 8005DF7C: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DF80u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DF80:
    ctx->pc = 0x8005DF80u;
    ctx->downcount -= 3;
    // 8005DF80: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DF84:
    ctx->pc = 0x8005DF84u;
    // 8005DF84: cmpwi   r0, 0
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

label_8005DF88:
    ctx->pc = 0x8005DF88u;
    // 8005DF88: bc    4, 2, 0x8005DF9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DF9C;
        }
    }

label_8005DF8C:
    ctx->pc = 0x8005DF8Cu;
    ctx->downcount -= 4;
    // 8005DF8C: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DF90:
    ctx->pc = 0x8005DF90u;
    // 8005DF90: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DF94:
    ctx->pc = 0x8005DF94u;
    // 8005DF94: addi    r4, r4, 5924
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5924);

label_8005DF98:
    ctx->pc = 0x8005DF98u;
    // 8005DF98: b       0x8005E06C
    {
            goto label_8005E06C;
    }

label_8005DF9C:
    ctx->pc = 0x8005DF9Cu;
    ctx->downcount -= 4;
    // 8005DF9C: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DFA0:
    ctx->pc = 0x8005DFA0u;
    // 8005DFA0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DFA4:
    ctx->pc = 0x8005DFA4u;
    // 8005DFA4: addi    r4, r4, 5972
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(5972);

label_8005DFA8:
    ctx->pc = 0x8005DFA8u;
    // 8005DFA8: b       0x8005E06C
    {
            goto label_8005E06C;
    }

label_8005DFAC:
    ctx->pc = 0x8005DFACu;
    ctx->downcount -= 5;
    // 8005DFAC: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005DFB0:
    ctx->pc = 0x8005DFB0u;
    // 8005DFB0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DFB4:
    ctx->pc = 0x8005DFB4u;
    // 8005DFB4: addi    r5, r5, 23300
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23300);

label_8005DFB8:
    ctx->pc = 0x8005DFB8u;
    // 8005DFB8: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005DFBC:
    ctx->pc = 0x8005DFBCu;
    // 8005DFBC: bl      0x8005D3F0
    {
            ctx->lr = 0x8005DFC0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005DFC0:
    ctx->pc = 0x8005DFC0u;
    ctx->downcount -= 3;
    // 8005DFC0: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005DFC4:
    ctx->pc = 0x8005DFC4u;
    // 8005DFC4: cmpwi   r0, 2
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

label_8005DFC8:
    ctx->pc = 0x8005DFC8u;
    // 8005DFC8: bc    4, 2, 0x8005DFDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DFDC;
        }
    }

label_8005DFCC:
    ctx->pc = 0x8005DFCCu;
    ctx->downcount -= 4;
    // 8005DFCC: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005DFD0:
    ctx->pc = 0x8005DFD0u;
    // 8005DFD0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005DFD4:
    ctx->pc = 0x8005DFD4u;
    // 8005DFD4: addi    r4, r4, 6020
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6020);

label_8005DFD8:
    ctx->pc = 0x8005DFD8u;
    // 8005DFD8: b       0x8005E11C
    {
            goto label_8005E11C;
    }

label_8005DFDC:
    ctx->pc = 0x8005DFDCu;
    ctx->downcount -= 5;
    // 8005DFDC: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005DFE0:
    ctx->pc = 0x8005DFE0u;
    // 8005DFE0: cmpwi   r0, 0
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

label_8005DFE4:
    ctx->pc = 0x8005DFE4u;
    // 8005DFE4: addi    r4, r9, 6056
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(6056);

label_8005DFE8:
    ctx->pc = 0x8005DFE8u;
    // 8005DFE8: li      r0, 11
    ctx->gpr[0] = (u32)(s32)(11);

label_8005DFEC:
    ctx->pc = 0x8005DFECu;
    // 8005DFEC: bc    4, 2, 0x8005DFF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005DFF4;
        }
    }

label_8005DFF0:
    ctx->pc = 0x8005DFF0u;
    ctx->downcount -= 1;
    // 8005DFF0: li      r0, 6
    ctx->gpr[0] = (u32)(s32)(6);

label_8005DFF4:
    ctx->pc = 0x8005DFF4u;
    ctx->downcount -= 2;
    // 8005DFF4: stw     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005DFF8:
    ctx->pc = 0x8005DFF8u;
    // 8005DFF8: b       0x8005E068
    {
            goto label_8005E068;
    }

label_8005DFFC:
    ctx->pc = 0x8005DFFCu;
    ctx->downcount -= 3;
    // 8005DFFC: li      r0, -89
    ctx->gpr[0] = (u32)(s32)(-89);

label_8005E000:
    ctx->pc = 0x8005E000u;
    // 8005E000: stw     r0, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E004:
    ctx->pc = 0x8005E004u;
    // 8005E004: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E008:
    ctx->pc = 0x8005E008u;
    ctx->downcount -= 3;
    // 8005E008: li      r0, 36
    ctx->gpr[0] = (u32)(s32)(36);

label_8005E00C:
    ctx->pc = 0x8005E00Cu;
    // 8005E00C: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E010:
    ctx->pc = 0x8005E010u;
    // 8005E010: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E014:
    ctx->pc = 0x8005E014u;
    ctx->downcount -= 3;
    // 8005E014: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E018:
    ctx->pc = 0x8005E018u;
    // 8005E018: cmpwi   r0, 2
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

label_8005E01C:
    ctx->pc = 0x8005E01Cu;
    // 8005E01C: bc    4, 2, 0x8005E034
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E034;
        }
    }

label_8005E020:
    ctx->pc = 0x8005E020u;
    ctx->downcount -= 4;
    // 8005E020: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E024:
    ctx->pc = 0x8005E024u;
    // 8005E024: li      r4, 50
    ctx->gpr[4] = (u32)(s32)(50);

label_8005E028:
    ctx->pc = 0x8005E028u;
    // 8005E028: li      r5, 36
    ctx->gpr[5] = (u32)(s32)(36);

label_8005E02C:
    ctx->pc = 0x8005E02Cu;
    // 8005E02C: bl      0x8005C934
    {
            ctx->lr = 0x8005E030u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005E030:
    ctx->pc = 0x8005E030u;
    ctx->downcount -= 1;
    // 8005E030: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E034:
    ctx->pc = 0x8005E034u;
    ctx->downcount -= 5;
    // 8005E034: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E038:
    ctx->pc = 0x8005E038u;
    // 8005E038: li      r4, 4211
    ctx->gpr[4] = (u32)(s32)(4211);

label_8005E03C:
    ctx->pc = 0x8005E03Cu;
    // 8005E03C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E040:
    ctx->pc = 0x8005E040u;
    // 8005E040: addi    r5, r5, 23340
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23340);

label_8005E044:
    ctx->pc = 0x8005E044u;
    // 8005E044: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E048u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E048:
    ctx->pc = 0x8005E048u;
    ctx->downcount -= 6;
    // 8005E048: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E04C:
    ctx->pc = 0x8005E04Cu;
    // 8005E04C: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005E050:
    ctx->pc = 0x8005E050u;
    // 8005E050: addi    r4, r9, 6092
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(6092);

label_8005E054:
    ctx->pc = 0x8005E054u;
    // 8005E054: li      r11, 11
    ctx->gpr[11] = (u32)(s32)(11);

label_8005E058:
    ctx->pc = 0x8005E058u;
    // 8005E058: cmpwi   r0, 0
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

label_8005E05C:
    ctx->pc = 0x8005E05Cu;
    // 8005E05C: bc    4, 2, 0x8005E064
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E064;
        }
    }

label_8005E060:
    ctx->pc = 0x8005E060u;
    ctx->downcount -= 1;
    // 8005E060: li      r11, 6
    ctx->gpr[11] = (u32)(s32)(6);

label_8005E064:
    ctx->pc = 0x8005E064u;
    ctx->downcount -= 1;
    // 8005E064: stw     r11, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005E068:
    ctx->pc = 0x8005E068u;
    ctx->downcount -= 1;
    // 8005E068: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E06C:
    ctx->pc = 0x8005E06Cu;
    ctx->downcount -= 2;
    // 8005E06C: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_8005E070:
    ctx->pc = 0x8005E070u;
    // 8005E070: bl      0x8005C950
    {
            ctx->lr = 0x8005E074u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005E074:
    ctx->pc = 0x8005E074u;
    ctx->downcount -= 1;
    // 8005E074: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E078:
    ctx->pc = 0x8005E078u;
    ctx->downcount -= 5;
    // 8005E078: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E07C:
    ctx->pc = 0x8005E07Cu;
    // 8005E07C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E080:
    ctx->pc = 0x8005E080u;
    // 8005E080: addi    r5, r5, 23392
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23392);

label_8005E084:
    ctx->pc = 0x8005E084u;
    // 8005E084: li      r4, 4641
    ctx->gpr[4] = (u32)(s32)(4641);

label_8005E088:
    ctx->pc = 0x8005E088u;
    // 8005E088: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E08Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E08C:
    ctx->pc = 0x8005E08Cu;
    ctx->downcount -= 5;
    // 8005E08C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E090:
    ctx->pc = 0x8005E090u;
    // 8005E090: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E094:
    ctx->pc = 0x8005E094u;
    // 8005E094: addi    r5, r5, 21744
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(21744);

label_8005E098:
    ctx->pc = 0x8005E098u;
    // 8005E098: li      r4, 4198
    ctx->gpr[4] = (u32)(s32)(4198);

label_8005E09C:
    ctx->pc = 0x8005E09Cu;
    // 8005E09C: bl      0x8005D48C
    {
            ctx->lr = 0x8005E0A0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E0A0:
    ctx->pc = 0x8005E0A0u;
    ctx->downcount -= 3;
    // 8005E0A0: li      r0, 35
    ctx->gpr[0] = (u32)(s32)(35);

label_8005E0A4:
    ctx->pc = 0x8005E0A4u;
    // 8005E0A4: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E0A8:
    ctx->pc = 0x8005E0A8u;
    // 8005E0A8: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E0AC:
    ctx->pc = 0x8005E0ACu;
    ctx->downcount -= 3;
    // 8005E0AC: lis     r3, -32708
    ctx->gpr[3] = ((u32)(s32)(-32708) << 16);

label_8005E0B0:
    ctx->pc = 0x8005E0B0u;
    // 8005E0B0: addi    r3, r3, -27584
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-27584);

label_8005E0B4:
    ctx->pc = 0x8005E0B4u;
    // 8005E0B4: bl      0x80014368
    {
            ctx->lr = 0x8005E0B8u;
            ctx->pc = 0x80014368u;
            return;
    }

label_8005E0B8:
    ctx->pc = 0x8005E0B8u;
    ctx->downcount -= 3;
    // 8005E0B8: cmpwi   r3, 0
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

label_8005E0BC:
    ctx->pc = 0x8005E0BCu;
    // 8005E0BC: stw     r3, 124(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005E0C0:
    ctx->pc = 0x8005E0C0u;
    // 8005E0C0: bc    4, 0, 0x8005E0D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E0D0;
        }
    }

label_8005E0C4:
    ctx->pc = 0x8005E0C4u;
    ctx->downcount -= 3;
    // 8005E0C4: li      r0, 26
    ctx->gpr[0] = (u32)(s32)(26);

label_8005E0C8:
    ctx->pc = 0x8005E0C8u;
    // 8005E0C8: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E0CC:
    ctx->pc = 0x8005E0CCu;
    // 8005E0CC: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E0D0:
    ctx->pc = 0x8005E0D0u;
    ctx->downcount -= 3;
    // 8005E0D0: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8005E0D4:
    ctx->pc = 0x8005E0D4u;
    // 8005E0D4: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E0D8:
    ctx->pc = 0x8005E0D8u;
    // 8005E0D8: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E0DC:
    ctx->pc = 0x8005E0DCu;
    ctx->downcount -= 3;
    // 8005E0DC: lwz     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E0E0:
    ctx->pc = 0x8005E0E0u;
    // 8005E0E0: cmpwi   r0, 2
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

label_8005E0E4:
    ctx->pc = 0x8005E0E4u;
    // 8005E0E4: bc    4, 2, 0x8005E128
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E128;
        }
    }

label_8005E0E8:
    ctx->pc = 0x8005E0E8u;
    ctx->downcount -= 5;
    // 8005E0E8: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E0EC:
    ctx->pc = 0x8005E0ECu;
    // 8005E0EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E0F0:
    ctx->pc = 0x8005E0F0u;
    // 8005E0F0: addi    r5, r5, 23404
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23404);

label_8005E0F4:
    ctx->pc = 0x8005E0F4u;
    // 8005E0F4: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005E0F8:
    ctx->pc = 0x8005E0F8u;
    // 8005E0F8: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E0FCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E0FC:
    ctx->pc = 0x8005E0FCu;
    ctx->downcount -= 5;
    // 8005E0FC: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E100:
    ctx->pc = 0x8005E100u;
    // 8005E100: li      r4, 4640
    ctx->gpr[4] = (u32)(s32)(4640);

label_8005E104:
    ctx->pc = 0x8005E104u;
    // 8005E104: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E108:
    ctx->pc = 0x8005E108u;
    // 8005E108: addi    r5, r5, 23416
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23416);

label_8005E10C:
    ctx->pc = 0x8005E10Cu;
    // 8005E10C: bl      0x8005D48C
    {
            ctx->lr = 0x8005E110u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E110:
    ctx->pc = 0x8005E110u;
    ctx->downcount -= 3;
    // 8005E110: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005E114:
    ctx->pc = 0x8005E114u;
    // 8005E114: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E118:
    ctx->pc = 0x8005E118u;
    // 8005E118: addi    r4, r4, 6128
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6128);

label_8005E11C:
    ctx->pc = 0x8005E11Cu;
    ctx->downcount -= 2;
    // 8005E11C: li      r5, 9
    ctx->gpr[5] = (u32)(s32)(9);

label_8005E120:
    ctx->pc = 0x8005E120u;
    // 8005E120: bl      0x8005C950
    {
            ctx->lr = 0x8005E124u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005E124:
    ctx->pc = 0x8005E124u;
    ctx->downcount -= 1;
    // 8005E124: b       0x8005E164
    {
            goto label_8005E164;
    }

label_8005E128:
    ctx->pc = 0x8005E128u;
    ctx->downcount -= 5;
    // 8005E128: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E12C:
    ctx->pc = 0x8005E12Cu;
    // 8005E12C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E130:
    ctx->pc = 0x8005E130u;
    // 8005E130: addi    r5, r5, 23404
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23404);

label_8005E134:
    ctx->pc = 0x8005E134u;
    // 8005E134: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005E138:
    ctx->pc = 0x8005E138u;
    // 8005E138: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E13Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E13C:
    ctx->pc = 0x8005E13Cu;
    ctx->downcount -= 5;
    // 8005E13C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E140:
    ctx->pc = 0x8005E140u;
    // 8005E140: li      r4, 4640
    ctx->gpr[4] = (u32)(s32)(4640);

label_8005E144:
    ctx->pc = 0x8005E144u;
    // 8005E144: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E148:
    ctx->pc = 0x8005E148u;
    // 8005E148: addi    r5, r5, 23416
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23416);

label_8005E14C:
    ctx->pc = 0x8005E14Cu;
    // 8005E14C: bl      0x8005D48C
    {
            ctx->lr = 0x8005E150u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E150:
    ctx->pc = 0x8005E150u;
    ctx->downcount -= 5;
    // 8005E150: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005E154:
    ctx->pc = 0x8005E154u;
    // 8005E154: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E158:
    ctx->pc = 0x8005E158u;
    // 8005E158: addi    r4, r4, 6164
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6164);

label_8005E15C:
    ctx->pc = 0x8005E15Cu;
    // 8005E15C: li      r5, 6
    ctx->gpr[5] = (u32)(s32)(6);

label_8005E160:
    ctx->pc = 0x8005E160u;
    // 8005E160: bl      0x8005C950
    {
            ctx->lr = 0x8005E164u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005E164:
    ctx->pc = 0x8005E164u;
    ctx->downcount -= 2;
    // 8005E164: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E168:
    ctx->pc = 0x8005E168u;
    // 8005E168: bl      0x8005E320
    {
            ctx->lr = 0x8005E16Cu;
            goto label_8005E320;
    }

label_8005E16C:
    ctx->pc = 0x8005E16Cu;
    ctx->downcount -= 6;
    // 8005E16C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E170:
    ctx->pc = 0x8005E170u;
    // 8005E170: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005E174:
    ctx->pc = 0x8005E174u;
    // 8005E174: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8005E178:
    ctx->pc = 0x8005E178u;
    // 8005E178: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005E17C:
    ctx->pc = 0x8005E17Cu;
    // 8005E17C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005E180:
    ctx->pc = 0x8005E180u;
    ctx->downcount -= 18;
    // 8005E180: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005E184:
    ctx->pc = 0x8005E184u;
    // 8005E184: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005E188:
    ctx->pc = 0x8005E188u;
    // 8005E188: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005E18C:
    ctx->pc = 0x8005E18Cu;
    // 8005E18C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E190:
    ctx->pc = 0x8005E190u;
    // 8005E190: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005E194:
    ctx->pc = 0x8005E194u;
    // 8005E194: addi    r30, r31, 16
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(16);

label_8005E198:
    ctx->pc = 0x8005E198u;
    // 8005E198: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005E19C:
    ctx->pc = 0x8005E19Cu;
    // 8005E19C: bl      0x8005C984
    {
            ctx->lr = 0x8005E1A0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C984u;
                return;
            }
            goto label_8005C984;
    }

label_8005E1A0:
    ctx->pc = 0x8005E1A0u;
    ctx->downcount -= 3;
    // 8005E1A0: lwz     r0, 128(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(128);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E1A4:
    ctx->pc = 0x8005E1A4u;
    // 8005E1A4: cmpwi   r0, 9
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(9);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E1A8:
    ctx->pc = 0x8005E1A8u;
    // 8005E1A8: bc    4, 2, 0x8005E1B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E1B8;
        }
    }

label_8005E1AC:
    ctx->pc = 0x8005E1ACu;
    ctx->downcount -= 3;
    // 8005E1AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E1B0:
    ctx->pc = 0x8005E1B0u;
    // 8005E1B0: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_8005E1B4:
    ctx->pc = 0x8005E1B4u;
    // 8005E1B4: bl      0x80044028
    {
            ctx->lr = 0x8005E1B8u;
            ctx->pc = 0x80044028u;
            return;
    }

label_8005E1B8:
    ctx->pc = 0x8005E1B8u;
    ctx->downcount -= 16;
    // 8005E1B8: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E1BC:
    ctx->pc = 0x8005E1BCu;
    // 8005E1BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005E1C0:
    ctx->pc = 0x8005E1C0u;
    // 8005E1C0: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005E1C4:
    ctx->pc = 0x8005E1C4u;
    // 8005E1C4: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005E1C8:
    ctx->pc = 0x8005E1C8u;
    // 8005E1C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005E1CC:
    ctx->pc = 0x8005E1CCu;
    ctx->downcount -= 19;
    // 8005E1CC: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005E1D0:
    ctx->pc = 0x8005E1D0u;
    // 8005E1D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005E1D4:
    ctx->pc = 0x8005E1D4u;
    // 8005E1D4: stfd     f30, 24(r1)
    if (!ppc_fp_available(ctx, 0x8005E1D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8005E1D8:
    ctx->pc = 0x8005E1D8u;
    // 8005E1D8: stfd     f31, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005E1D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8005E1DC:
    ctx->pc = 0x8005E1DCu;
    // 8005E1DC: stmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005E1E0:
    ctx->pc = 0x8005E1E0u;
    // 8005E1E0: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E1E4:
    ctx->pc = 0x8005E1E4u;
    // 8005E1E4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005E1E8:
    ctx->pc = 0x8005E1E8u;
    // 8005E1E8: li      r11, 8328
    ctx->gpr[11] = (u32)(s32)(8328);

label_8005E1EC:
    ctx->pc = 0x8005E1ECu;
    // 8005E1EC: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005E1F0:
    loop_8005E1F0(ctx);
    if (ctx->pc == 0x8005E230u) goto label_8005E230;
    return;
label_8005E1F4:
    // 8005E1F4: addic.  r11, r11, -24
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

label_8005E1F8:
    ctx->pc = 0x8005E1F8u;
    // 8005E1F8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E1FC:
    ctx->pc = 0x8005E1FCu;
    // 8005E1FC: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E200:
    ctx->pc = 0x8005E200u;
    // 8005E200: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E204:
    ctx->pc = 0x8005E204u;
    // 8005E204: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E208:
    ctx->pc = 0x8005E208u;
    // 8005E208: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E20C:
    ctx->pc = 0x8005E20Cu;
    // 8005E20C: lwz     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E210:
    ctx->pc = 0x8005E210u;
    // 8005E210: stw     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E214:
    ctx->pc = 0x8005E214u;
    // 8005E214: lwz     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E218:
    ctx->pc = 0x8005E218u;
    // 8005E218: stw     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E21C:
    ctx->pc = 0x8005E21Cu;
    // 8005E21C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E220:
    // 8005E220: addi    r3, r3, 24
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(24);

label_8005E224:
    ctx->pc = 0x8005E224u;
    // 8005E224: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E228:
    // 8005E228: addi    r9, r9, 24
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(24);

label_8005E22C:
    // 8005E22C: bc    4, 2, 0x8005E1F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005E1F0u;
                return;
            }
            goto label_8005E1F0;
        }
    }

label_8005E230:
    ctx->pc = 0x8005E230u;
    ctx->downcount -= 5;
    // 8005E230: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005E234:
    ctx->pc = 0x8005E234u;
    // 8005E234: lis     r30, 17200
    ctx->gpr[30] = ((u32)(s32)(17200) << 16);

label_8005E238:
    ctx->pc = 0x8005E238u;
    // 8005E238: addi    r31, r9, -21636
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005E23C:
    ctx->pc = 0x8005E23Cu;
    // 8005E23C: lwz     r3, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005E240:
    ctx->pc = 0x8005E240u;
    // 8005E240: bl      0x80044020
    {
            ctx->lr = 0x8005E244u;
            ctx->pc = 0x80044020u;
            return;
    }

label_8005E244:
    ctx->pc = 0x8005E244u;
    ctx->downcount -= 30;
    // 8005E244: lwz     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E248:
    ctx->pc = 0x8005E248u;
    // 8005E248: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_8005E24C:
    ctx->pc = 0x8005E24Cu;
    // 8005E24C: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005E250:
    ctx->pc = 0x8005E250u;
    // 8005E250: srawi r0, r0, 8
    {
        u32 sh = 8u;
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

label_8005E254:
    ctx->pc = 0x8005E254u;
    // 8005E254: lfd     f31, 23480(r11)
    if (!ppc_fp_available(ctx, 0x8005E254u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(23480);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E258:
    ctx->pc = 0x8005E258u;
    // 8005E258: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005E25C:
    ctx->pc = 0x8005E25Cu;
    // 8005E25C: lfs     f30, 23488(r10)
    if (!ppc_fp_available(ctx, 0x8005E25Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(23488);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8005E260:
    ctx->pc = 0x8005E260u;
    // 8005E260: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E264:
    ctx->pc = 0x8005E264u;
    // 8005E264: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8005E268:
    ctx->pc = 0x8005E268u;
    // 8005E268: lfd     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E268u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E26C:
    ctx->pc = 0x8005E26Cu;
    // 8005E26C: fsub   f1, f1, f31
    if (!ppc_fp_available(ctx, 0x8005E26Cu)) return;
    ppc_fsub(ctx, 1, 1, 31);

label_8005E270:
    ctx->pc = 0x8005E270u;
    // 8005E270: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x8005E270u)) return;
    ppc_frsp(ctx, 1, 1);

label_8005E274:
    ctx->pc = 0x8005E274u;
    // 8005E274: fdivs   f1, f1, f30
    if (!ppc_fp_available(ctx, 0x8005E274u)) return;
    ppc_fdivs(ctx, 1, 1, 30);

label_8005E278:
    ctx->pc = 0x8005E278u;
    // 8005E278: bl      0x8004EDD0
    {
            ctx->lr = 0x8005E27Cu;
            ctx->pc = 0x8004EDD0u;
            return;
    }

label_8005E27C:
    ctx->pc = 0x8005E27Cu;
    ctx->downcount -= 26;
    // 8005E27C: lwz     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E280:
    ctx->pc = 0x8005E280u;
    // 8005E280: srawi r0, r0, 8
    {
        u32 sh = 8u;
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

label_8005E284:
    ctx->pc = 0x8005E284u;
    // 8005E284: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005E288:
    ctx->pc = 0x8005E288u;
    // 8005E288: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E28C:
    ctx->pc = 0x8005E28Cu;
    // 8005E28C: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8005E290:
    ctx->pc = 0x8005E290u;
    // 8005E290: lfd     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E290u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E294:
    ctx->pc = 0x8005E294u;
    // 8005E294: fsub   f1, f1, f31
    if (!ppc_fp_available(ctx, 0x8005E294u)) return;
    ppc_fsub(ctx, 1, 1, 31);

label_8005E298:
    ctx->pc = 0x8005E298u;
    // 8005E298: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x8005E298u)) return;
    ppc_frsp(ctx, 1, 1);

label_8005E29C:
    ctx->pc = 0x8005E29Cu;
    // 8005E29C: fdivs   f1, f1, f30
    if (!ppc_fp_available(ctx, 0x8005E29Cu)) return;
    ppc_fdivs(ctx, 1, 1, 30);

label_8005E2A0:
    ctx->pc = 0x8005E2A0u;
    // 8005E2A0: bl      0x8004EDB8
    {
            ctx->lr = 0x8005E2A4u;
            ctx->pc = 0x8004EDB8u;
            return;
    }

label_8005E2A4:
    ctx->pc = 0x8005E2A4u;
    ctx->downcount -= 3;
    // 8005E2A4: lwz     r0, -31812(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31812);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E2A8:
    ctx->pc = 0x8005E2A8u;
    // 8005E2A8: cmpwi   r0, 0
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

label_8005E2AC:
    ctx->pc = 0x8005E2ACu;
    // 8005E2AC: bc    12, 2, 0x8005E2CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E2CC;
        }
    }

label_8005E2B0:
    ctx->pc = 0x8005E2B0u;
    ctx->downcount -= 7;
    // 8005E2B0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005E2B4:
    ctx->pc = 0x8005E2B4u;
    // 8005E2B4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005E2B8:
    ctx->pc = 0x8005E2B8u;
    // 8005E2B8: addi    r9, r9, -13308
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-13308);

label_8005E2BC:
    ctx->pc = 0x8005E2BCu;
    // 8005E2BC: stw     r0, 964(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(964);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E2C0:
    ctx->pc = 0x8005E2C0u;
    // 8005E2C0: stw     r0, 17764(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(17764);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E2C4:
    ctx->pc = 0x8005E2C4u;
    // 8005E2C4: stw     r0, 1012(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1012);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E2C8:
    ctx->pc = 0x8005E2C8u;
    // 8005E2C8: stw     r0, 9388(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(9388);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E2CC:
    ctx->pc = 0x8005E2CCu;
    ctx->downcount -= 18;
    // 8005E2CC: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E2D0:
    ctx->pc = 0x8005E2D0u;
    // 8005E2D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005E2D4:
    ctx->pc = 0x8005E2D4u;
    // 8005E2D4: lmw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005E2D8:
    ctx->pc = 0x8005E2D8u;
    // 8005E2D8: lfd     f30, 24(r1)
    if (!ppc_fp_available(ctx, 0x8005E2D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E2DC:
    ctx->pc = 0x8005E2DCu;
    // 8005E2DC: lfd     f31, 32(r1)
    if (!ppc_fp_available(ctx, 0x8005E2DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E2E0:
    ctx->pc = 0x8005E2E0u;
    // 8005E2E0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8005E2E4:
    ctx->pc = 0x8005E2E4u;
    // 8005E2E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005E2E8:
    ctx->pc = 0x8005E2E8u;
    ctx->downcount -= 2;
    // 8005E2E8: cmplwi  r3, 0x0002
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

label_8005E2EC:
    ctx->pc = 0x8005E2ECu;
    // 8005E2EC: bclr  12, 1
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005E2F0:
    ctx->pc = 0x8005E2F0u;
    ctx->downcount -= 9;
    // 8005E2F0: mulli   r11, r3, 8376
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)8376);

label_8005E2F4:
    ctx->pc = 0x8005E2F4u;
    // 8005E2F4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005E2F8:
    ctx->pc = 0x8005E2F8u;
    // 8005E2F8: addi    r9, r9, -13308
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-13308);

label_8005E2FC:
    ctx->pc = 0x8005E2FCu;
    // 8005E2FC: stw     r3, -27920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27920);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005E300:
    ctx->pc = 0x8005E300u;
    // 8005E300: lwzx    r0, r9, r11
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[11];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E304:
    ctx->pc = 0x8005E304u;
    // 8005E304: cmpwi   r0, 0
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

label_8005E308:
    ctx->pc = 0x8005E308u;
    // 8005E308: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005E30C:
    ctx->pc = 0x8005E30Cu;
    ctx->downcount -= 5;
    // 8005E30C: addi    r0, r9, 48
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(48);

label_8005E310:
    ctx->pc = 0x8005E310u;
    // 8005E310: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005E314:
    ctx->pc = 0x8005E314u;
    // 8005E314: add   r0, r11, r0
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8005E318:
    ctx->pc = 0x8005E318u;
    // 8005E318: stw     r0, 16268(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E31C:
    ctx->pc = 0x8005E31Cu;
    // 8005E31C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005E320:
    ctx->pc = 0x8005E320u;
    ctx->downcount -= 18;
    // 8005E320: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005E324:
    ctx->pc = 0x8005E324u;
    // 8005E324: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005E328:
    ctx->pc = 0x8005E328u;
    // 8005E328: stmw     r26, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 26; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005E32C:
    ctx->pc = 0x8005E32Cu;
    // 8005E32C: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E330:
    ctx->pc = 0x8005E330u;
    // 8005E330: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005E334:
    ctx->pc = 0x8005E334u;
    // 8005E334: lwz     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E338:
    ctx->pc = 0x8005E338u;
    // 8005E338: cmpwi   r0, 48
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(48);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E33C:
    ctx->pc = 0x8005E33Cu;
    // 8005E33C: bc    12, 2, 0x8005E6E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E6E0;
        }
    }

label_8005E340:
    ctx->pc = 0x8005E340u;
    ctx->downcount -= 1;
    // 8005E340: bc    12, 1, 0x8005E374
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E374;
        }
    }

label_8005E344:
    ctx->pc = 0x8005E344u;
    ctx->downcount -= 2;
    // 8005E344: cmpwi   r0, 44
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(44);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E348:
    ctx->pc = 0x8005E348u;
    // 8005E348: bc    12, 2, 0x8005E3F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E3F4;
        }
    }

label_8005E34C:
    ctx->pc = 0x8005E34Cu;
    ctx->downcount -= 1;
    // 8005E34C: bc    12, 1, 0x8005E364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E364;
        }
    }

label_8005E350:
    ctx->pc = 0x8005E350u;
    ctx->downcount -= 2;
    // 8005E350: cmpwi   r0, 42
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(42);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E354:
    ctx->pc = 0x8005E354u;
    // 8005E354: bc    12, 2, 0x8005E3AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E3AC;
        }
    }

label_8005E358:
    ctx->pc = 0x8005E358u;
    ctx->downcount -= 2;
    // 8005E358: cmpwi   r0, 43
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(43);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E35C:
    ctx->pc = 0x8005E35Cu;
    // 8005E35C: bc    12, 2, 0x8005E3C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E3C4;
        }
    }

label_8005E360:
    ctx->pc = 0x8005E360u;
    ctx->downcount -= 1;
    // 8005E360: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E364:
    ctx->pc = 0x8005E364u;
    ctx->downcount -= 2;
    // 8005E364: cmpwi   r0, 46
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(46);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E368:
    ctx->pc = 0x8005E368u;
    // 8005E368: bc    12, 2, 0x8005E46C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E46C;
        }
    }

label_8005E36C:
    ctx->pc = 0x8005E36Cu;
    ctx->downcount -= 1;
    // 8005E36C: bc    12, 1, 0x8005E4A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E4A0;
        }
    }

label_8005E370:
    ctx->pc = 0x8005E370u;
    ctx->downcount -= 1;
    // 8005E370: b       0x8005E420
    {
            goto label_8005E420;
    }

label_8005E374:
    ctx->pc = 0x8005E374u;
    ctx->downcount -= 2;
    // 8005E374: cmpwi   r0, 51
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(51);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E378:
    ctx->pc = 0x8005E378u;
    // 8005E378: bc    12, 2, 0x8005E800
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E800;
        }
    }

label_8005E37C:
    ctx->pc = 0x8005E37Cu;
    ctx->downcount -= 1;
    // 8005E37C: bc    12, 1, 0x8005E394
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E394;
        }
    }

label_8005E380:
    ctx->pc = 0x8005E380u;
    ctx->downcount -= 2;
    // 8005E380: cmpwi   r0, 49
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(49);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E384:
    ctx->pc = 0x8005E384u;
    // 8005E384: bc    12, 2, 0x8005E728
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E728;
        }
    }

label_8005E388:
    ctx->pc = 0x8005E388u;
    ctx->downcount -= 2;
    // 8005E388: cmpwi   r0, 50
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(50);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E38C:
    ctx->pc = 0x8005E38Cu;
    // 8005E38C: bc    12, 2, 0x8005E78C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E78C;
        }
    }

label_8005E390:
    ctx->pc = 0x8005E390u;
    ctx->downcount -= 1;
    // 8005E390: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E394:
    ctx->pc = 0x8005E394u;
    ctx->downcount -= 2;
    // 8005E394: cmpwi   r0, 53
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(53);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E398:
    ctx->pc = 0x8005E398u;
    // 8005E398: bc    12, 2, 0x8005E8DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E8DC;
        }
    }

label_8005E39C:
    ctx->pc = 0x8005E39Cu;
    ctx->downcount -= 1;
    // 8005E39C: bc    12, 0, 0x8005E8B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E8B8;
        }
    }

label_8005E3A0:
    ctx->pc = 0x8005E3A0u;
    ctx->downcount -= 2;
    // 8005E3A0: cmpwi   r0, 54
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(54);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E3A4:
    ctx->pc = 0x8005E3A4u;
    // 8005E3A4: bc    12, 2, 0x8005E924
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E924;
        }
    }

label_8005E3A8:
    ctx->pc = 0x8005E3A8u;
    ctx->downcount -= 1;
    // 8005E3A8: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E3AC:
    ctx->pc = 0x8005E3ACu;
    ctx->downcount -= 6;
    // 8005E3AC: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005E3B0:
    ctx->pc = 0x8005E3B0u;
    // 8005E3B0: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8005E3B4:
    ctx->pc = 0x8005E3B4u;
    // 8005E3B4: sth     r0, -21584(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005E3B8:
    ctx->pc = 0x8005E3B8u;
    // 8005E3B8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005E3BC:
    ctx->pc = 0x8005E3BCu;
    // 8005E3BC: stw     r11, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005E3C0:
    ctx->pc = 0x8005E3C0u;
    // 8005E3C0: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E3C4:
    ctx->pc = 0x8005E3C4u;
    ctx->downcount -= 12;
    // 8005E3C4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005E3C8:
    ctx->pc = 0x8005E3C8u;
    // 8005E3C8: lis     r9, -32719
    ctx->gpr[9] = ((u32)(s32)(-32719) << 16);

label_8005E3CC:
    ctx->pc = 0x8005E3CCu;
    // 8005E3CC: addi    r9, r9, 27904
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(27904);

label_8005E3D0:
    ctx->pc = 0x8005E3D0u;
    // 8005E3D0: stw     r0, -31804(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31804);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3D4:
    ctx->pc = 0x8005E3D4u;
    // 8005E3D4: stw     r0, 652(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(652);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3D8:
    ctx->pc = 0x8005E3D8u;
    // 8005E3D8: stw     r0, 132(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3DC:
    ctx->pc = 0x8005E3DCu;
    // 8005E3DC: stw     r0, 296(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(296);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3E0:
    ctx->pc = 0x8005E3E0u;
    // 8005E3E0: stw     r0, 460(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(460);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3E4:
    ctx->pc = 0x8005E3E4u;
    // 8005E3E4: stw     r0, 624(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(624);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3E8:
    ctx->pc = 0x8005E3E8u;
    // 8005E3E8: stw     r0, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3EC:
    ctx->pc = 0x8005E3ECu;
    // 8005E3EC: stw     r0, 324(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(324);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3F0:
    ctx->pc = 0x8005E3F0u;
    // 8005E3F0: stw     r0, 488(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E3F4:
    ctx->pc = 0x8005E3F4u;
    ctx->downcount -= 5;
    // 8005E3F4: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E3F8:
    ctx->pc = 0x8005E3F8u;
    // 8005E3F8: li      r4, 3580
    ctx->gpr[4] = (u32)(s32)(3580);

label_8005E3FC:
    ctx->pc = 0x8005E3FCu;
    // 8005E3FC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E400:
    ctx->pc = 0x8005E400u;
    // 8005E400: addi    r5, r5, 23492
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23492);

label_8005E404:
    ctx->pc = 0x8005E404u;
    // 8005E404: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E408u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E408:
    ctx->pc = 0x8005E408u;
    ctx->downcount -= 6;
    // 8005E408: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005E40C:
    ctx->pc = 0x8005E40Cu;
    // 8005E40C: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005E410:
    ctx->pc = 0x8005E410u;
    // 8005E410: stw     r0, -31808(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31808);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E414:
    ctx->pc = 0x8005E414u;
    // 8005E414: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E418:
    ctx->pc = 0x8005E418u;
    // 8005E418: addi    r4, r4, 6200
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6200);

label_8005E41C:
    ctx->pc = 0x8005E41Cu;
    // 8005E41C: b       0x8005E780
    {
            goto label_8005E780;
    }

label_8005E420:
    ctx->pc = 0x8005E420u;
    ctx->downcount -= 5;
    // 8005E420: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E424:
    ctx->pc = 0x8005E424u;
    // 8005E424: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E428:
    ctx->pc = 0x8005E428u;
    // 8005E428: addi    r5, r5, 23544
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23544);

label_8005E42C:
    ctx->pc = 0x8005E42Cu;
    // 8005E42C: li      r4, 4176
    ctx->gpr[4] = (u32)(s32)(4176);

label_8005E430:
    ctx->pc = 0x8005E430u;
    // 8005E430: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E434u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E434:
    ctx->pc = 0x8005E434u;
    ctx->downcount -= 5;
    // 8005E434: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E438:
    ctx->pc = 0x8005E438u;
    // 8005E438: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E43C:
    ctx->pc = 0x8005E43Cu;
    // 8005E43C: addi    r5, r5, 23580
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23580);

label_8005E440:
    ctx->pc = 0x8005E440u;
    // 8005E440: li      r4, 4177
    ctx->gpr[4] = (u32)(s32)(4177);

label_8005E444:
    ctx->pc = 0x8005E444u;
    // 8005E444: bl      0x8005D48C
    {
            ctx->lr = 0x8005E448u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E448:
    ctx->pc = 0x8005E448u;
    ctx->downcount -= 5;
    // 8005E448: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E44C:
    ctx->pc = 0x8005E44Cu;
    // 8005E44C: li      r4, 4178
    ctx->gpr[4] = (u32)(s32)(4178);

label_8005E450:
    ctx->pc = 0x8005E450u;
    // 8005E450: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E454:
    ctx->pc = 0x8005E454u;
    // 8005E454: addi    r5, r5, 23624
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23624);

label_8005E458:
    ctx->pc = 0x8005E458u;
    // 8005E458: bl      0x8005D4B8
    {
            ctx->lr = 0x8005E45Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D4B8u;
                return;
            }
            goto label_8005D4B8;
    }

label_8005E45C:
    ctx->pc = 0x8005E45Cu;
    ctx->downcount -= 4;
    // 8005E45C: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005E460:
    ctx->pc = 0x8005E460u;
    // 8005E460: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E464:
    ctx->pc = 0x8005E464u;
    // 8005E464: addi    r4, r4, 6236
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6236);

label_8005E468:
    ctx->pc = 0x8005E468u;
    // 8005E468: b       0x8005E780
    {
            goto label_8005E780;
    }

label_8005E46C:
    ctx->pc = 0x8005E46Cu;
    ctx->downcount -= 5;
    // 8005E46C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E470:
    ctx->pc = 0x8005E470u;
    // 8005E470: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E474:
    ctx->pc = 0x8005E474u;
    // 8005E474: addi    r5, r5, 23656
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23656);

label_8005E478:
    ctx->pc = 0x8005E478u;
    // 8005E478: li      r4, 4660
    ctx->gpr[4] = (u32)(s32)(4660);

label_8005E47C:
    ctx->pc = 0x8005E47Cu;
    // 8005E47C: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E480u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E480:
    ctx->pc = 0x8005E480u;
    ctx->downcount -= 3;
    // 8005E480: lis     r3, 2
    ctx->gpr[3] = ((u32)(s32)(2) << 16);

label_8005E484:
    ctx->pc = 0x8005E484u;
    // 8005E484: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005E488:
    ctx->pc = 0x8005E488u;
    // 8005E488: bl      0x80044410
    {
            ctx->lr = 0x8005E48Cu;
            ctx->pc = 0x80044410u;
            return;
    }

label_8005E48C:
    ctx->pc = 0x8005E48Cu;
    ctx->downcount -= 4;
    // 8005E48C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E490:
    ctx->pc = 0x8005E490u;
    // 8005E490: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005E494:
    ctx->pc = 0x8005E494u;
    // 8005E494: li      r5, 47
    ctx->gpr[5] = (u32)(s32)(47);

label_8005E498:
    ctx->pc = 0x8005E498u;
    // 8005E498: bl      0x8005C934
    {
            ctx->lr = 0x8005E49Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005E49C:
    ctx->pc = 0x8005E49Cu;
    ctx->downcount -= 1;
    // 8005E49C: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E4A0:
    ctx->pc = 0x8005E4A0u;
    ctx->downcount -= 5;
    // 8005E4A0: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E4A4:
    ctx->pc = 0x8005E4A4u;
    // 8005E4A4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E4A8:
    ctx->pc = 0x8005E4A8u;
    // 8005E4A8: addi    r5, r5, 23656
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23656);

label_8005E4AC:
    ctx->pc = 0x8005E4ACu;
    // 8005E4AC: li      r4, 4660
    ctx->gpr[4] = (u32)(s32)(4660);

label_8005E4B0:
    ctx->pc = 0x8005E4B0u;
    // 8005E4B0: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E4B4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E4B4:
    ctx->pc = 0x8005E4B4u;
    ctx->downcount -= 2;
    // 8005E4B4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005E4B8:
    ctx->pc = 0x8005E4B8u;
    // 8005E4B8: bl      0x80008D4C
    {
            ctx->lr = 0x8005E4BCu;
            ctx->pc = 0x80008D4Cu;
            return;
    }

label_8005E4BC:
    ctx->pc = 0x8005E4BCu;
    ctx->downcount -= 2;
    // 8005E4BC: cmplwi  r3, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E4C0:
    ctx->pc = 0x8005E4C0u;
    // 8005E4C0: bc    12, 1, 0x8005E4CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E4CC;
        }
    }

label_8005E4C4:
    ctx->pc = 0x8005E4C4u;
    ctx->downcount -= 2;
    // 8005E4C4: stw     r3, -31808(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31808);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005E4C8:
    ctx->pc = 0x8005E4C8u;
    // 8005E4C8: b       0x8005E4DC
    {
            goto label_8005E4DC;
    }

label_8005E4CC:
    ctx->pc = 0x8005E4CCu;
    ctx->downcount -= 2;
    // 8005E4CC: cmpwi   r3, 101
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(101);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E4D0:
    ctx->pc = 0x8005E4D0u;
    // 8005E4D0: bc    4, 2, 0x8005E4DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E4DC;
        }
    }

label_8005E4D4:
    ctx->pc = 0x8005E4D4u;
    ctx->downcount -= 2;
    // 8005E4D4: li      r0, 48
    ctx->gpr[0] = (u32)(s32)(48);

label_8005E4D8:
    ctx->pc = 0x8005E4D8u;
    // 8005E4D8: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E4DC:
    ctx->pc = 0x8005E4DCu;
    ctx->downcount -= 4;
    // 8005E4DC: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005E4E0:
    ctx->pc = 0x8005E4E0u;
    // 8005E4E0: lwz     r0, -20996(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20996);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E4E4:
    ctx->pc = 0x8005E4E4u;
    // 8005E4E4: andis.  r9, r0, 0x0002
    {
        ctx->gpr[9] = ctx->gpr[0] & (0x0002u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005E4E8:
    ctx->pc = 0x8005E4E8u;
    // 8005E4E8: bc    12, 2, 0x8005E4F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E4F4;
        }
    }

label_8005E4EC:
    ctx->pc = 0x8005E4ECu;
    ctx->downcount -= 2;
    // 8005E4EC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005E4F0:
    ctx->pc = 0x8005E4F0u;
    // 8005E4F0: stw     r0, -31804(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31804);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E4F4:
    ctx->pc = 0x8005E4F4u;
    ctx->downcount -= 3;
    // 8005E4F4: lwz     r9, -31808(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005E4F8:
    ctx->pc = 0x8005E4F8u;
    // 8005E4F8: cmpwi   r9, -1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E4FC:
    ctx->pc = 0x8005E4FCu;
    // 8005E4FC: bc    12, 2, 0x8005E614
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E614;
        }
    }

label_8005E500:
    ctx->pc = 0x8005E500u;
    ctx->downcount -= 9;
    // 8005E500: mulli   r9, r9, 164
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)164);

label_8005E504:
    ctx->pc = 0x8005E504u;
    // 8005E504: lis     r11, -32719
    ctx->gpr[11] = ((u32)(s32)(-32719) << 16);

label_8005E508:
    ctx->pc = 0x8005E508u;
    // 8005E508: addi    r11, r11, 27904
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(27904);

label_8005E50C:
    ctx->pc = 0x8005E50Cu;
    // 8005E50C: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005E510:
    ctx->pc = 0x8005E510u;
    // 8005E510: lbz     r0, 125(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(125);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8005E514:
    ctx->pc = 0x8005E514u;
    // 8005E514: cmplwi  r0, 0x0005
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0005u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E518:
    ctx->pc = 0x8005E518u;
    // 8005E518: bc    4, 1, 0x8005E614
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E614;
        }
    }

label_8005E51C:
    ctx->pc = 0x8005E51Cu;
    ctx->downcount -= 5;
    // 8005E51C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005E520:
    ctx->pc = 0x8005E520u;
    // 8005E520: lwz     r9, -32364(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-32364);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005E524:
    ctx->pc = 0x8005E524u;
    // 8005E524: stw     r0, -31804(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31804);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E528:
    ctx->pc = 0x8005E528u;
    // 8005E528: andi.   r0, r9, 0x0010
    {
        ctx->gpr[0] = ctx->gpr[9] & 0x0010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005E52C:
    ctx->pc = 0x8005E52Cu;
    // 8005E52C: bc    12, 2, 0x8005E548
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E548;
        }
    }

label_8005E530:
    ctx->pc = 0x8005E530u;
    ctx->downcount -= 5;
    // 8005E530: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E534:
    ctx->pc = 0x8005E534u;
    // 8005E534: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E538:
    ctx->pc = 0x8005E538u;
    // 8005E538: addi    r5, r5, 23680
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23680);

label_8005E53C:
    ctx->pc = 0x8005E53Cu;
    // 8005E53C: li      r4, 4182
    ctx->gpr[4] = (u32)(s32)(4182);

label_8005E540:
    ctx->pc = 0x8005E540u;
    // 8005E540: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E544u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E544:
    ctx->pc = 0x8005E544u;
    ctx->downcount -= 1;
    // 8005E544: b       0x8005E558
    {
            goto label_8005E558;
    }

label_8005E548:
    ctx->pc = 0x8005E548u;
    ctx->downcount -= 4;
    // 8005E548: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E54C:
    ctx->pc = 0x8005E54Cu;
    // 8005E54C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005E550:
    ctx->pc = 0x8005E550u;
    // 8005E550: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8005E554:
    ctx->pc = 0x8005E554u;
    // 8005E554: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E558u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E558:
    ctx->pc = 0x8005E558u;
    ctx->downcount -= 9;
    // 8005E558: lis     r7, 24704
    ctx->gpr[7] = ((u32)(s32)(24704) << 16);

label_8005E55C:
    ctx->pc = 0x8005E55Cu;
    // 8005E55C: li      r3, 118
    ctx->gpr[3] = (u32)(s32)(118);

label_8005E560:
    ctx->pc = 0x8005E560u;
    // 8005E560: li      r4, 248
    ctx->gpr[4] = (u32)(s32)(248);

label_8005E564:
    ctx->pc = 0x8005E564u;
    // 8005E564: li      r5, 522
    ctx->gpr[5] = (u32)(s32)(522);

label_8005E568:
    ctx->pc = 0x8005E568u;
    // 8005E568: li      r6, 272
    ctx->gpr[6] = (u32)(s32)(272);

label_8005E56C:
    ctx->pc = 0x8005E56Cu;
    // 8005E56C: ori     r7, r7, 0x8080
    ctx->gpr[7] = ctx->gpr[7] | 0x8080u;

label_8005E570:
    ctx->pc = 0x8005E570u;
    // 8005E570: li      r8, 10
    ctx->gpr[8] = (u32)(s32)(10);

label_8005E574:
    ctx->pc = 0x8005E574u;
    // 8005E574: lis     r30, 20971
    ctx->gpr[30] = ((u32)(s32)(20971) << 16);

label_8005E578:
    ctx->pc = 0x8005E578u;
    // 8005E578: bl      0x80003700
    {
            ctx->lr = 0x8005E57Cu;
            ctx->pc = 0x80003700u;
            return;
    }

label_8005E57C:
    ctx->pc = 0x8005E57Cu;
    ctx->downcount -= 15;
    // 8005E57C: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_8005E580:
    ctx->pc = 0x8005E580u;
    // 8005E580: lwz     r9, -31808(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005E584:
    ctx->pc = 0x8005E584u;
    // 8005E584: lis     r11, -32719
    ctx->gpr[11] = ((u32)(s32)(-32719) << 16);

label_8005E588:
    ctx->pc = 0x8005E588u;
    // 8005E588: addi    r11, r11, 27904
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(27904);

label_8005E58C:
    ctx->pc = 0x8005E58Cu;
    // 8005E58C: ori     r30, r30, 0x851F
    ctx->gpr[30] = ctx->gpr[30] | 0x851Fu;

label_8005E590:
    ctx->pc = 0x8005E590u;
    // 8005E590: mulli   r9, r9, 164
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)164);

label_8005E594:
    ctx->pc = 0x8005E594u;
    // 8005E594: li      r28, 132
    ctx->gpr[28] = (u32)(s32)(132);

label_8005E598:
    ctx->pc = 0x8005E598u;
    // 8005E598: li      r29, 120
    ctx->gpr[29] = (u32)(s32)(120);

label_8005E59C:
    ctx->pc = 0x8005E59Cu;
    // 8005E59C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8005E5A0:
    ctx->pc = 0x8005E5A0u;
    // 8005E5A0: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005E5A4:
    ctx->pc = 0x8005E5A4u;
    // 8005E5A4: lbz     r0, 125(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(125);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8005E5A8:
    ctx->pc = 0x8005E5A8u;
    // 8005E5A8: rlwinm r26, r0, 2, 0, 29
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8005E5AC:
    ctx->pc = 0x8005E5ACu;
    // 8005E5AC: b       0x8005E600
    {
            goto label_8005E600;
    }

label_8005E5B0:
    ctx->downcount -= 24;
    // 8005E5B0: mulhw   r7, r31, r30
    {
        s64 product = (s64)(s32)ctx->gpr[31] * (s64)(s32)ctx->gpr[30];
        ctx->gpr[7] = (u32)(product >> 32);
    }

label_8005E5B4:
    // 8005E5B4: srawi r0, r31, 31
    {
        u32 sh = 31u;
        u32 value = ctx->gpr[31];
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

label_8005E5B8:
    // 8005E5B8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005E5BC:
    // 8005E5BC: or   r5, r28, r28
    {
        ctx->gpr[5] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005E5C0:
    // 8005E5C0: li      r4, 250
    ctx->gpr[4] = (u32)(s32)(250);

label_8005E5C4:
    // 8005E5C4: li      r6, 270
    ctx->gpr[6] = (u32)(s32)(270);

label_8005E5C8:
    // 8005E5C8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8005E5CC:
    // 8005E5CC: srawi r7, r7, 5
    {
        u32 sh = 5u;
        u32 value = ctx->gpr[7];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[7] = value;
        } else if (sh > 31) {
            ctx->gpr[7] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[7] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8005E5D0:
    // 8005E5D0: addi    r28, r28, 16
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(16);

label_8005E5D4:
    // 8005E5D4: subf   r7, r0, r7
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b + 1u;
        ctx->gpr[7] = res;
    }

label_8005E5D8:
    // 8005E5D8: addi    r29, r29, 16
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(16);

label_8005E5DC:
    // 8005E5DC: subfic  r0, r7, 192
    {
        u64 res = (u64)(u32)(s32)(192) + (u64)(~ctx->gpr[7]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8005E5E0:
    // 8005E5E0: addi    r31, r31, 768
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(768);

label_8005E5E4:
    // 8005E5E4: addi    r7, r7, 64
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(64);

label_8005E5E8:
    // 8005E5E8: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8005E5EC:
    // 8005E5EC: rlwinm r7, r7, 16, 0, 15
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 16u) & 0xFFFF0000u;
    }

label_8005E5F0:
    // 8005E5F0: oris    r0, r0, 0xFF00
    ctx->gpr[0] = ctx->gpr[0] | (0xFF00u << 16);

label_8005E5F4:
    // 8005E5F4: or   r7, r7, r0
    {
        ctx->gpr[7] = ctx->gpr[7] | ctx->gpr[0];
    }

label_8005E5F8:
    // 8005E5F8: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_8005E5FC:
    // 8005E5FC: bl      0x80003700
    {
            ctx->lr = 0x8005E600u;
            ctx->pc = 0x80003700u;
            return;
    }

label_8005E600:
    ctx->downcount -= 4;
    // 8005E600: or   r9, r26, r26
    {
        ctx->gpr[9] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005E604:
    // 8005E604: srawi r0, r9, 4
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

label_8005E608:
    // 8005E608: cmpw    r27, r0
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

label_8005E60C:
    // 8005E60C: bc    12, 0, 0x8005E5B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005E5B0u;
                return;
            }
            goto label_8005E5B0;
        }
    }

label_8005E610:
    ctx->pc = 0x8005E610u;
    ctx->downcount -= 1;
    // 8005E610: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E614:
    ctx->pc = 0x8005E614u;
    ctx->downcount -= 5;
    // 8005E614: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E618:
    ctx->pc = 0x8005E618u;
    // 8005E618: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E61C:
    ctx->pc = 0x8005E61Cu;
    // 8005E61C: addi    r5, r5, 23656
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23656);

label_8005E620:
    ctx->pc = 0x8005E620u;
    // 8005E620: li      r4, 4660
    ctx->gpr[4] = (u32)(s32)(4660);

label_8005E624:
    ctx->pc = 0x8005E624u;
    // 8005E624: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E628u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E628:
    ctx->pc = 0x8005E628u;
    ctx->downcount -= 19;
    // 8005E628: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E62C:
    ctx->pc = 0x8005E62Cu;
    // 8005E62C: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_8005E630:
    ctx->pc = 0x8005E630u;
    // 8005E630: lwz     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005E634:
    ctx->pc = 0x8005E634u;
    // 8005E634: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005E638:
    ctx->pc = 0x8005E638u;
    // 8005E638: or   r8, r10, r10
    {
        ctx->gpr[8] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8005E63C:
    ctx->pc = 0x8005E63Cu;
    // 8005E63C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E640:
    ctx->pc = 0x8005E640u;
    // 8005E640: xoris   r11, r11, 0x8000
    ctx->gpr[11] = ctx->gpr[11] ^ (0x8000u << 16);

label_8005E644:
    ctx->pc = 0x8005E644u;
    // 8005E644: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005E648:
    ctx->pc = 0x8005E648u;
    // 8005E648: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005E64C:
    ctx->pc = 0x8005E64Cu;
    // 8005E64C: lfd     f0, 23792(r9)
    if (!ppc_fp_available(ctx, 0x8005E64Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(23792);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E650:
    ctx->pc = 0x8005E650u;
    // 8005E650: lfd     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E650u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E654:
    ctx->pc = 0x8005E654u;
    // 8005E654: stw     r11, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005E658:
    ctx->pc = 0x8005E658u;
    // 8005E658: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x8005E658u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_8005E65C:
    ctx->pc = 0x8005E65Cu;
    // 8005E65C: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005E660:
    ctx->pc = 0x8005E660u;
    // 8005E660: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x8005E660u)) return;
    ppc_frsp(ctx, 1, 1);

label_8005E664:
    ctx->pc = 0x8005E664u;
    // 8005E664: lfd     f2, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E664u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E668:
    ctx->pc = 0x8005E668u;
    // 8005E668: fsub   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x8005E668u)) return;
    ppc_fsub(ctx, 2, 2, 0);

label_8005E66C:
    ctx->pc = 0x8005E66Cu;
    // 8005E66C: frsp    f2, f2
    if (!ppc_fp_available(ctx, 0x8005E66Cu)) return;
    ppc_frsp(ctx, 2, 2);

label_8005E670:
    ctx->pc = 0x8005E670u;
    // 8005E670: bl      0x80133520
    {
            ctx->lr = 0x8005E674u;
            ctx->pc = 0x80133520u;
            return;
    }

label_8005E674:
    ctx->pc = 0x8005E674u;
    ctx->downcount -= 3;
    // 8005E674: lwz     r9, -31808(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31808);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005E678:
    ctx->pc = 0x8005E678u;
    // 8005E678: cmpwi   r9, -1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E67C:
    ctx->pc = 0x8005E67Cu;
    // 8005E67C: bc    12, 2, 0x8005E69C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E69C;
        }
    }

label_8005E680:
    ctx->pc = 0x8005E680u;
    ctx->downcount -= 9;
    // 8005E680: mulli   r9, r9, 164
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)164);

label_8005E684:
    ctx->pc = 0x8005E684u;
    // 8005E684: lis     r11, -32719
    ctx->gpr[11] = ((u32)(s32)(-32719) << 16);

label_8005E688:
    ctx->pc = 0x8005E688u;
    // 8005E688: addi    r11, r11, 27904
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(27904);

label_8005E68C:
    ctx->pc = 0x8005E68Cu;
    // 8005E68C: add   r9, r9, r11
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005E690:
    ctx->pc = 0x8005E690u;
    // 8005E690: lbz     r0, 127(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(127);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8005E694:
    ctx->pc = 0x8005E694u;
    // 8005E694: cmpwi   r0, 0
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

label_8005E698:
    ctx->pc = 0x8005E698u;
    // 8005E698: bc    4, 2, 0x8005E9B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E9B4;
        }
    }

label_8005E69C:
    ctx->pc = 0x8005E69Cu;
    ctx->downcount -= 4;
    // 8005E69C: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005E6A0:
    ctx->pc = 0x8005E6A0u;
    // 8005E6A0: lwz     r0, -20996(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20996);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E6A4:
    ctx->pc = 0x8005E6A4u;
    // 8005E6A4: andis.  r9, r0, 0x0002
    {
        ctx->gpr[9] = ctx->gpr[0] & (0x0002u << 16);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005E6A8:
    ctx->pc = 0x8005E6A8u;
    // 8005E6A8: bc    4, 2, 0x8005E6B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005E6B8;
        }
    }

label_8005E6AC:
    ctx->pc = 0x8005E6ACu;
    ctx->downcount -= 3;
    // 8005E6AC: lwz     r0, -31804(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31804);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E6B0:
    ctx->pc = 0x8005E6B0u;
    // 8005E6B0: cmpwi   r0, 0
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

label_8005E6B4:
    ctx->pc = 0x8005E6B4u;
    // 8005E6B4: bc    12, 2, 0x8005E9B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E9B4;
        }
    }

label_8005E6B8:
    ctx->pc = 0x8005E6B8u;
    ctx->downcount -= 5;
    // 8005E6B8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005E6BC:
    ctx->pc = 0x8005E6BCu;
    // 8005E6BC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8005E6C0:
    ctx->pc = 0x8005E6C0u;
    // 8005E6C0: lfs     f1, 23800(r9)
    if (!ppc_fp_available(ctx, 0x8005E6C0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(23800);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005E6C4:
    ctx->pc = 0x8005E6C4u;
    // 8005E6C4: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_8005E6C8:
    ctx->pc = 0x8005E6C8u;
    // 8005E6C8: bl      0x8004DC00
    {
            ctx->lr = 0x8005E6CCu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8005E6CC:
    ctx->pc = 0x8005E6CCu;
    ctx->downcount -= 5;
    // 8005E6CC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005E6D0:
    ctx->pc = 0x8005E6D0u;
    // 8005E6D0: li      r9, 42
    ctx->gpr[9] = (u32)(s32)(42);

label_8005E6D4:
    ctx->pc = 0x8005E6D4u;
    // 8005E6D4: stw     r0, -31804(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31804);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E6D8:
    ctx->pc = 0x8005E6D8u;
    // 8005E6D8: stw     r9, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005E6DC:
    ctx->pc = 0x8005E6DCu;
    // 8005E6DC: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E6E0:
    ctx->pc = 0x8005E6E0u;
    ctx->downcount -= 5;
    // 8005E6E0: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_8005E6E4:
    ctx->pc = 0x8005E6E4u;
    // 8005E6E4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E6E8:
    ctx->pc = 0x8005E6E8u;
    // 8005E6E8: li      r4, 4179
    ctx->gpr[4] = (u32)(s32)(4179);

label_8005E6EC:
    ctx->pc = 0x8005E6ECu;
    // 8005E6EC: addi    r5, r30, 23692
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23692);

label_8005E6F0:
    ctx->pc = 0x8005E6F0u;
    // 8005E6F0: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E6F4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E6F4:
    ctx->pc = 0x8005E6F4u;
    ctx->downcount -= 4;
    // 8005E6F4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E6F8:
    ctx->pc = 0x8005E6F8u;
    // 8005E6F8: li      r4, 4180
    ctx->gpr[4] = (u32)(s32)(4180);

label_8005E6FC:
    ctx->pc = 0x8005E6FCu;
    // 8005E6FC: addi    r5, r30, 23692
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23692);

label_8005E700:
    ctx->pc = 0x8005E700u;
    // 8005E700: bl      0x8005D48C
    {
            ctx->lr = 0x8005E704u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E704:
    ctx->pc = 0x8005E704u;
    ctx->downcount -= 4;
    // 8005E704: addi    r5, r30, 23692
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23692);

label_8005E708:
    ctx->pc = 0x8005E708u;
    // 8005E708: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E70C:
    ctx->pc = 0x8005E70Cu;
    // 8005E70C: li      r4, 4181
    ctx->gpr[4] = (u32)(s32)(4181);

label_8005E710:
    ctx->pc = 0x8005E710u;
    // 8005E710: bl      0x8005D4B8
    {
            ctx->lr = 0x8005E714u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D4B8u;
                return;
            }
            goto label_8005D4B8;
    }

label_8005E714:
    ctx->pc = 0x8005E714u;
    ctx->downcount -= 5;
    // 8005E714: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005E718:
    ctx->pc = 0x8005E718u;
    // 8005E718: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005E71C:
    ctx->pc = 0x8005E71Cu;
    // 8005E71C: addi    r9, r9, 6272
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(6272);

label_8005E720:
    ctx->pc = 0x8005E720u;
    // 8005E720: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E724:
    ctx->pc = 0x8005E724u;
    // 8005E724: b       0x8005E9B0
    {
            goto label_8005E9B0;
    }

label_8005E728:
    ctx->pc = 0x8005E728u;
    ctx->downcount -= 7;
    // 8005E728: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005E72C:
    ctx->pc = 0x8005E72Cu;
    // 8005E72C: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_8005E730:
    ctx->pc = 0x8005E730u;
    // 8005E730: stw     r0, -31808(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31808);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E734:
    ctx->pc = 0x8005E734u;
    // 8005E734: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E738:
    ctx->pc = 0x8005E738u;
    // 8005E738: li      r4, 4162
    ctx->gpr[4] = (u32)(s32)(4162);

label_8005E73C:
    ctx->pc = 0x8005E73Cu;
    // 8005E73C: addi    r5, r30, 23712
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23712);

label_8005E740:
    ctx->pc = 0x8005E740u;
    // 8005E740: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E744u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E744:
    ctx->pc = 0x8005E744u;
    ctx->downcount -= 4;
    // 8005E744: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E748:
    ctx->pc = 0x8005E748u;
    // 8005E748: li      r4, 4163
    ctx->gpr[4] = (u32)(s32)(4163);

label_8005E74C:
    ctx->pc = 0x8005E74Cu;
    // 8005E74C: addi    r5, r30, 23712
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23712);

label_8005E750:
    ctx->pc = 0x8005E750u;
    // 8005E750: bl      0x8005D48C
    {
            ctx->lr = 0x8005E754u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E754:
    ctx->pc = 0x8005E754u;
    ctx->downcount -= 4;
    // 8005E754: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E758:
    ctx->pc = 0x8005E758u;
    // 8005E758: li      r4, 4164
    ctx->gpr[4] = (u32)(s32)(4164);

label_8005E75C:
    ctx->pc = 0x8005E75Cu;
    // 8005E75C: addi    r5, r30, 23712
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23712);

label_8005E760:
    ctx->pc = 0x8005E760u;
    // 8005E760: bl      0x8005D4B8
    {
            ctx->lr = 0x8005E764u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D4B8u;
                return;
            }
            goto label_8005D4B8;
    }

label_8005E764:
    ctx->pc = 0x8005E764u;
    ctx->downcount -= 4;
    // 8005E764: li      r4, 4165
    ctx->gpr[4] = (u32)(s32)(4165);

label_8005E768:
    ctx->pc = 0x8005E768u;
    // 8005E768: addi    r5, r30, 23712
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23712);

label_8005E76C:
    ctx->pc = 0x8005E76Cu;
    // 8005E76C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E770:
    ctx->pc = 0x8005E770u;
    // 8005E770: bl      0x8005D4E4
    {
            ctx->lr = 0x8005E774u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D4E4u;
                return;
            }
            goto label_8005D4E4;
    }

label_8005E774:
    ctx->pc = 0x8005E774u;
    ctx->downcount -= 3;
    // 8005E774: lis     r4, -32735
    ctx->gpr[4] = ((u32)(s32)(-32735) << 16);

label_8005E778:
    ctx->pc = 0x8005E778u;
    // 8005E778: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E77C:
    ctx->pc = 0x8005E77Cu;
    // 8005E77C: addi    r4, r4, 6288
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(6288);

label_8005E780:
    ctx->pc = 0x8005E780u;
    ctx->downcount -= 2;
    // 8005E780: li      r5, 42
    ctx->gpr[5] = (u32)(s32)(42);

label_8005E784:
    ctx->pc = 0x8005E784u;
    // 8005E784: bl      0x8005C950
    {
            ctx->lr = 0x8005E788u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C950u;
                return;
            }
            goto label_8005C950;
    }

label_8005E788:
    ctx->pc = 0x8005E788u;
    ctx->downcount -= 1;
    // 8005E788: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E78C:
    ctx->pc = 0x8005E78Cu;
    ctx->downcount -= 5;
    // 8005E78C: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_8005E790:
    ctx->pc = 0x8005E790u;
    // 8005E790: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E794:
    ctx->pc = 0x8005E794u;
    // 8005E794: addi    r5, r5, 23656
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(23656);

label_8005E798:
    ctx->pc = 0x8005E798u;
    // 8005E798: li      r4, 4660
    ctx->gpr[4] = (u32)(s32)(4660);

label_8005E79C:
    ctx->pc = 0x8005E79Cu;
    // 8005E79C: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E7A0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E7A0:
    ctx->pc = 0x8005E7A0u;
    ctx->downcount -= 19;
    // 8005E7A0: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E7A4:
    ctx->pc = 0x8005E7A4u;
    // 8005E7A4: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_8005E7A8:
    ctx->pc = 0x8005E7A8u;
    // 8005E7A8: lwz     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005E7AC:
    ctx->pc = 0x8005E7ACu;
    // 8005E7AC: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005E7B0:
    ctx->pc = 0x8005E7B0u;
    // 8005E7B0: or   r8, r10, r10
    {
        ctx->gpr[8] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8005E7B4:
    ctx->pc = 0x8005E7B4u;
    // 8005E7B4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E7B8:
    ctx->pc = 0x8005E7B8u;
    // 8005E7B8: xoris   r11, r11, 0x8000
    ctx->gpr[11] = ctx->gpr[11] ^ (0x8000u << 16);

label_8005E7BC:
    ctx->pc = 0x8005E7BCu;
    // 8005E7BC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005E7C0:
    ctx->pc = 0x8005E7C0u;
    // 8005E7C0: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005E7C4:
    ctx->pc = 0x8005E7C4u;
    // 8005E7C4: lfd     f0, 23792(r9)
    if (!ppc_fp_available(ctx, 0x8005E7C4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(23792);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E7C8:
    ctx->pc = 0x8005E7C8u;
    // 8005E7C8: lfd     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E7C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E7CC:
    ctx->pc = 0x8005E7CCu;
    // 8005E7CC: stw     r11, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005E7D0:
    ctx->pc = 0x8005E7D0u;
    // 8005E7D0: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x8005E7D0u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_8005E7D4:
    ctx->pc = 0x8005E7D4u;
    // 8005E7D4: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005E7D8:
    ctx->pc = 0x8005E7D8u;
    // 8005E7D8: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x8005E7D8u)) return;
    ppc_frsp(ctx, 1, 1);

label_8005E7DC:
    ctx->pc = 0x8005E7DCu;
    // 8005E7DC: lfd     f2, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E7DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E7E0:
    ctx->pc = 0x8005E7E0u;
    // 8005E7E0: fsub   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x8005E7E0u)) return;
    ppc_fsub(ctx, 2, 2, 0);

label_8005E7E4:
    ctx->pc = 0x8005E7E4u;
    // 8005E7E4: frsp    f2, f2
    if (!ppc_fp_available(ctx, 0x8005E7E4u)) return;
    ppc_frsp(ctx, 2, 2);

label_8005E7E8:
    ctx->pc = 0x8005E7E8u;
    // 8005E7E8: bl      0x80133520
    {
            ctx->lr = 0x8005E7ECu;
            ctx->pc = 0x80133520u;
            return;
    }

label_8005E7EC:
    ctx->pc = 0x8005E7ECu;
    ctx->downcount -= 4;
    // 8005E7EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E7F0:
    ctx->pc = 0x8005E7F0u;
    // 8005E7F0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8005E7F4:
    ctx->pc = 0x8005E7F4u;
    // 8005E7F4: li      r5, 51
    ctx->gpr[5] = (u32)(s32)(51);

label_8005E7F8:
    ctx->pc = 0x8005E7F8u;
    // 8005E7F8: bl      0x8005C934
    {
            ctx->lr = 0x8005E7FCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C934u;
                return;
            }
            goto label_8005C934;
    }

label_8005E7FC:
    ctx->pc = 0x8005E7FCu;
    ctx->downcount -= 1;
    // 8005E7FC: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E800:
    ctx->pc = 0x8005E800u;
    ctx->downcount -= 2;
    // 8005E800: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8005E804:
    ctx->pc = 0x8005E804u;
    // 8005E804: bl      0x80008D4C
    {
            ctx->lr = 0x8005E808u;
            ctx->pc = 0x80008D4Cu;
            return;
    }

label_8005E808:
    ctx->pc = 0x8005E808u;
    ctx->downcount -= 2;
    // 8005E808: cmpwi   r3, 102
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(102);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E80C:
    ctx->pc = 0x8005E80Cu;
    // 8005E80C: bc    12, 2, 0x8005E81C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E81C;
        }
    }

label_8005E810:
    ctx->pc = 0x8005E810u;
    ctx->downcount -= 2;
    // 8005E810: cmpwi   r3, 103
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(103);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005E814:
    ctx->pc = 0x8005E814u;
    // 8005E814: bc    12, 2, 0x8005E824
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E824;
        }
    }

label_8005E818:
    ctx->pc = 0x8005E818u;
    ctx->downcount -= 1;
    // 8005E818: b       0x8005E82C
    {
            goto label_8005E82C;
    }

label_8005E81C:
    ctx->pc = 0x8005E81Cu;
    ctx->downcount -= 2;
    // 8005E81C: li      r0, 53
    ctx->gpr[0] = (u32)(s32)(53);

label_8005E820:
    ctx->pc = 0x8005E820u;
    // 8005E820: b       0x8005E864
    {
            goto label_8005E864;
    }

label_8005E824:
    ctx->pc = 0x8005E824u;
    ctx->downcount -= 2;
    // 8005E824: li      r0, 54
    ctx->gpr[0] = (u32)(s32)(54);

label_8005E828:
    ctx->pc = 0x8005E828u;
    // 8005E828: b       0x8005E864
    {
            goto label_8005E864;
    }

label_8005E82C:
    ctx->pc = 0x8005E82Cu;
    ctx->downcount -= 8;
    // 8005E82C: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005E830:
    ctx->pc = 0x8005E830u;
    // 8005E830: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005E834:
    ctx->pc = 0x8005E834u;
    // 8005E834: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005E838:
    ctx->pc = 0x8005E838u;
    // 8005E838: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E83C:
    ctx->pc = 0x8005E83Cu;
    // 8005E83C: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_8005E840:
    ctx->pc = 0x8005E840u;
    // 8005E840: rlwinm r0, r0, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00020000u;
    }

label_8005E844:
    ctx->pc = 0x8005E844u;
    // 8005E844: and.   r9, r0, r11
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005E848:
    ctx->pc = 0x8005E848u;
    // 8005E848: bc    12, 2, 0x8005E868
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005E868;
        }
    }

label_8005E84C:
    ctx->pc = 0x8005E84Cu;
    ctx->downcount -= 5;
    // 8005E84C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005E850:
    ctx->pc = 0x8005E850u;
    // 8005E850: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_8005E854:
    ctx->pc = 0x8005E854u;
    // 8005E854: lfs     f1, 23800(r9)
    if (!ppc_fp_available(ctx, 0x8005E854u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(23800);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_8005E858:
    ctx->pc = 0x8005E858u;
    // 8005E858: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_8005E85C:
    ctx->pc = 0x8005E85Cu;
    // 8005E85C: bl      0x8004DC00
    {
            ctx->lr = 0x8005E860u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_8005E860:
    ctx->pc = 0x8005E860u;
    ctx->downcount -= 1;
    // 8005E860: li      r0, 42
    ctx->gpr[0] = (u32)(s32)(42);

label_8005E864:
    ctx->pc = 0x8005E864u;
    ctx->downcount -= 1;
    // 8005E864: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E868:
    ctx->pc = 0x8005E868u;
    ctx->downcount -= 19;
    // 8005E868: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E86C:
    ctx->pc = 0x8005E86Cu;
    // 8005E86C: lis     r7, 17200
    ctx->gpr[7] = ((u32)(s32)(17200) << 16);

label_8005E870:
    ctx->pc = 0x8005E870u;
    // 8005E870: lwz     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005E874:
    ctx->pc = 0x8005E874u;
    // 8005E874: xoris   r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x8000u << 16);

label_8005E878:
    ctx->pc = 0x8005E878u;
    // 8005E878: or   r8, r10, r10
    {
        ctx->gpr[8] = ctx->gpr[10] | ctx->gpr[10];
    }

label_8005E87C:
    ctx->pc = 0x8005E87Cu;
    // 8005E87C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E880:
    ctx->pc = 0x8005E880u;
    // 8005E880: xoris   r11, r11, 0x8000
    ctx->gpr[11] = ctx->gpr[11] ^ (0x8000u << 16);

label_8005E884:
    ctx->pc = 0x8005E884u;
    // 8005E884: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005E888:
    ctx->pc = 0x8005E888u;
    // 8005E888: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005E88C:
    ctx->pc = 0x8005E88Cu;
    // 8005E88C: lfd     f0, 23792(r9)
    if (!ppc_fp_available(ctx, 0x8005E88Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(23792);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E890:
    ctx->pc = 0x8005E890u;
    // 8005E890: lfd     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E890u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E894:
    ctx->pc = 0x8005E894u;
    // 8005E894: stw     r11, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005E898:
    ctx->pc = 0x8005E898u;
    // 8005E898: fsub   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x8005E898u)) return;
    ppc_fsub(ctx, 1, 1, 0);

label_8005E89C:
    ctx->pc = 0x8005E89Cu;
    // 8005E89C: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005E8A0:
    ctx->pc = 0x8005E8A0u;
    // 8005E8A0: frsp    f1, f1
    if (!ppc_fp_available(ctx, 0x8005E8A0u)) return;
    ppc_frsp(ctx, 1, 1);

label_8005E8A4:
    ctx->pc = 0x8005E8A4u;
    // 8005E8A4: lfd     f2, 8(r1)
    if (!ppc_fp_available(ctx, 0x8005E8A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8005E8A8:
    ctx->pc = 0x8005E8A8u;
    // 8005E8A8: fsub   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x8005E8A8u)) return;
    ppc_fsub(ctx, 2, 2, 0);

label_8005E8AC:
    ctx->pc = 0x8005E8ACu;
    // 8005E8AC: frsp    f2, f2
    if (!ppc_fp_available(ctx, 0x8005E8ACu)) return;
    ppc_frsp(ctx, 2, 2);

label_8005E8B0:
    ctx->pc = 0x8005E8B0u;
    // 8005E8B0: bl      0x80133520
    {
            ctx->lr = 0x8005E8B4u;
            ctx->pc = 0x80133520u;
            return;
    }

label_8005E8B4:
    ctx->pc = 0x8005E8B4u;
    ctx->downcount -= 1;
    // 8005E8B4: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E8B8:
    ctx->pc = 0x8005E8B8u;
    ctx->downcount -= 1;
    // 8005E8B8: li      r30, 10
    ctx->gpr[30] = (u32)(s32)(10);

label_8005E8BC:
    ctx->downcount -= 2;
    // 8005E8BC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8005E8C0:
    // 8005E8C0: bl      0x80008D4C
    {
            ctx->lr = 0x8005E8C4u;
            ctx->pc = 0x80008D4Cu;
            return;
    }

label_8005E8C4:
    ctx->downcount -= 1;
    // 8005E8C4: bl      0x80185E5C
    {
            ctx->lr = 0x8005E8C8u;
            ctx->pc = 0x80185E5Cu;
            return;
    }

label_8005E8C8:
    ctx->downcount -= 2;
    // 8005E8C8: addic.  r30, r30, -1
    {
        u64 a = ctx->gpr[30];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[30] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005E8CC:
    // 8005E8CC: bc    4, 2, 0x8005E8BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005E8BCu;
                return;
            }
            goto label_8005E8BC;
        }
    }

label_8005E8D0:
    ctx->pc = 0x8005E8D0u;
    ctx->downcount -= 3;
    // 8005E8D0: li      r0, 53
    ctx->gpr[0] = (u32)(s32)(53);

label_8005E8D4:
    ctx->pc = 0x8005E8D4u;
    // 8005E8D4: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E8D8:
    ctx->pc = 0x8005E8D8u;
    // 8005E8D8: b       0x8005E9B4
    {
            goto label_8005E9B4;
    }

label_8005E8DC:
    ctx->pc = 0x8005E8DCu;
    ctx->downcount -= 5;
    // 8005E8DC: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_8005E8E0:
    ctx->pc = 0x8005E8E0u;
    // 8005E8E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E8E4:
    ctx->pc = 0x8005E8E4u;
    // 8005E8E4: li      r4, 4168
    ctx->gpr[4] = (u32)(s32)(4168);

label_8005E8E8:
    ctx->pc = 0x8005E8E8u;
    // 8005E8E8: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E8EC:
    ctx->pc = 0x8005E8ECu;
    // 8005E8EC: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E8F0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E8F0:
    ctx->pc = 0x8005E8F0u;
    ctx->downcount -= 4;
    // 8005E8F0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E8F4:
    ctx->pc = 0x8005E8F4u;
    // 8005E8F4: li      r4, 4169
    ctx->gpr[4] = (u32)(s32)(4169);

label_8005E8F8:
    ctx->pc = 0x8005E8F8u;
    // 8005E8F8: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E8FC:
    ctx->pc = 0x8005E8FCu;
    // 8005E8FC: bl      0x8005D48C
    {
            ctx->lr = 0x8005E900u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E900:
    ctx->pc = 0x8005E900u;
    ctx->downcount -= 4;
    // 8005E900: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E904:
    ctx->pc = 0x8005E904u;
    // 8005E904: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E908:
    ctx->pc = 0x8005E908u;
    // 8005E908: li      r4, 4170
    ctx->gpr[4] = (u32)(s32)(4170);

label_8005E90C:
    ctx->pc = 0x8005E90Cu;
    // 8005E90C: bl      0x8005D4B8
    {
            ctx->lr = 0x8005E910u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D4B8u;
                return;
            }
            goto label_8005D4B8;
    }

label_8005E910:
    ctx->pc = 0x8005E910u;
    ctx->downcount -= 5;
    // 8005E910: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005E914:
    ctx->pc = 0x8005E914u;
    // 8005E914: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005E918:
    ctx->pc = 0x8005E918u;
    // 8005E918: addi    r9, r9, 6324
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(6324);

label_8005E91C:
    ctx->pc = 0x8005E91Cu;
    // 8005E91C: stw     r0, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E920:
    ctx->pc = 0x8005E920u;
    // 8005E920: b       0x8005E9B0
    {
            goto label_8005E9B0;
    }

label_8005E924:
    ctx->pc = 0x8005E924u;
    ctx->downcount -= 16;
    // 8005E924: lwz     r9, -31812(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31812);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005E928:
    ctx->pc = 0x8005E928u;
    // 8005E928: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_8005E92C:
    ctx->pc = 0x8005E92Cu;
    // 8005E92C: addi    r11, r11, -13308
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-13308);

label_8005E930:
    ctx->pc = 0x8005E930u;
    // 8005E930: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_8005E934:
    ctx->pc = 0x8005E934u;
    // 8005E934: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_8005E938:
    ctx->pc = 0x8005E938u;
    // 8005E938: lis     r10, -32699
    ctx->gpr[10] = ((u32)(s32)(-32699) << 16);

label_8005E93C:
    ctx->pc = 0x8005E93Cu;
    // 8005E93C: stw     r9, -31812(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31812);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005E940:
    ctx->pc = 0x8005E940u;
    // 8005E940: lis     r30, -32738
    ctx->gpr[30] = ((u32)(s32)(-32738) << 16);

label_8005E944:
    ctx->pc = 0x8005E944u;
    // 8005E944: stw     r29, 17764(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(17764);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8005E948:
    ctx->pc = 0x8005E948u;
    // 8005E948: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E94C:
    ctx->pc = 0x8005E94Cu;
    // 8005E94C: stw     r29, -20672(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-20672);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8005E950:
    ctx->pc = 0x8005E950u;
    // 8005E950: li      r4, 4171
    ctx->gpr[4] = (u32)(s32)(4171);

label_8005E954:
    ctx->pc = 0x8005E954u;
    // 8005E954: stw     r29, 1012(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(1012);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8005E958:
    ctx->pc = 0x8005E958u;
    // 8005E958: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E95C:
    ctx->pc = 0x8005E95Cu;
    // 8005E95C: stw     r29, 9388(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(9388);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8005E960:
    ctx->pc = 0x8005E960u;
    // 8005E960: bl      0x8005D3F0
    {
            ctx->lr = 0x8005E964u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D3F0u;
                return;
            }
            goto label_8005D3F0;
    }

label_8005E964:
    ctx->pc = 0x8005E964u;
    ctx->downcount -= 4;
    // 8005E964: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E968:
    ctx->pc = 0x8005E968u;
    // 8005E968: li      r4, 4172
    ctx->gpr[4] = (u32)(s32)(4172);

label_8005E96C:
    ctx->pc = 0x8005E96Cu;
    // 8005E96C: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E970:
    ctx->pc = 0x8005E970u;
    // 8005E970: bl      0x8005D48C
    {
            ctx->lr = 0x8005E974u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D48Cu;
                return;
            }
            goto label_8005D48C;
    }

label_8005E974:
    ctx->pc = 0x8005E974u;
    ctx->downcount -= 4;
    // 8005E974: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E978:
    ctx->pc = 0x8005E978u;
    // 8005E978: li      r4, 4173
    ctx->gpr[4] = (u32)(s32)(4173);

label_8005E97C:
    ctx->pc = 0x8005E97Cu;
    // 8005E97C: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E980:
    ctx->pc = 0x8005E980u;
    // 8005E980: bl      0x8005D4B8
    {
            ctx->lr = 0x8005E984u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D4B8u;
                return;
            }
            goto label_8005D4B8;
    }

label_8005E984:
    ctx->pc = 0x8005E984u;
    ctx->downcount -= 4;
    // 8005E984: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E988:
    ctx->pc = 0x8005E988u;
    // 8005E988: li      r4, 4174
    ctx->gpr[4] = (u32)(s32)(4174);

label_8005E98C:
    ctx->pc = 0x8005E98Cu;
    // 8005E98C: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E990:
    ctx->pc = 0x8005E990u;
    // 8005E990: bl      0x8005D4E4
    {
            ctx->lr = 0x8005E994u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D4E4u;
                return;
            }
            goto label_8005D4E4;
    }

label_8005E994:
    ctx->pc = 0x8005E994u;
    ctx->downcount -= 4;
    // 8005E994: addi    r5, r30, 23768
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(23768);

label_8005E998:
    ctx->pc = 0x8005E998u;
    // 8005E998: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005E99C:
    ctx->pc = 0x8005E99Cu;
    // 8005E99C: li      r4, 4175
    ctx->gpr[4] = (u32)(s32)(4175);

label_8005E9A0:
    ctx->pc = 0x8005E9A0u;
    // 8005E9A0: bl      0x8005D510
    {
            ctx->lr = 0x8005E9A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D510u;
                return;
            }
            goto label_8005D510;
    }

label_8005E9A4:
    ctx->pc = 0x8005E9A4u;
    ctx->downcount -= 3;
    // 8005E9A4: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005E9A8:
    ctx->pc = 0x8005E9A8u;
    // 8005E9A8: stw     r29, 128(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8005E9AC:
    ctx->pc = 0x8005E9ACu;
    // 8005E9AC: addi    r9, r9, 6340
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(6340);

label_8005E9B0:
    ctx->pc = 0x8005E9B0u;
    ctx->downcount -= 1;
    // 8005E9B0: stw     r9, 160(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005E9B4:
    ctx->pc = 0x8005E9B4u;
    ctx->downcount -= 16;
    // 8005E9B4: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005E9B8:
    ctx->pc = 0x8005E9B8u;
    // 8005E9B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005E9BC:
    ctx->pc = 0x8005E9BCu;
    // 8005E9BC: lmw     r26, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        for (u32 r = 26; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005E9C0:
    ctx->pc = 0x8005E9C0u;
    // 8005E9C0: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_8005E9C4:
    ctx->pc = 0x8005E9C4u;
    // 8005E9C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005E9C8:
    ctx->pc = 0x8005E9C8u;
    ctx->downcount -= 42;
    // 8005E9C8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005E9CC:
    ctx->pc = 0x8005E9CCu;
    // 8005E9CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005E9D0:
    ctx->pc = 0x8005E9D0u;
    // 8005E9D0: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005E9D4:
    ctx->pc = 0x8005E9D4u;
    // 8005E9D4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E9D8:
    ctx->pc = 0x8005E9D8u;
    // 8005E9D8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005E9DC:
    ctx->pc = 0x8005E9DCu;
    // 8005E9DC: lis     r10, -32699
    ctx->gpr[10] = ((u32)(s32)(-32699) << 16);

label_8005E9E0:
    ctx->pc = 0x8005E9E0u;
    // 8005E9E0: stw     r11, -13308(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-13308);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005E9E4:
    ctx->pc = 0x8005E9E4u;
    // 8005E9E4: addi    r9, r10, -13308
    ctx->gpr[9] = ctx->gpr[10] + (u32)(s32)(-13308);

label_8005E9E8:
    ctx->pc = 0x8005E9E8u;
    // 8005E9E8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8005E9EC:
    ctx->pc = 0x8005E9ECu;
    // 8005E9EC: stw     r11, 16756(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16756);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005E9F0:
    ctx->pc = 0x8005E9F0u;
    // 8005E9F0: stw     r0, 16760(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16760);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005E9F4:
    ctx->pc = 0x8005E9F4u;
    // 8005E9F4: li      r8, -1
    ctx->gpr[8] = (u32)(s32)(-1);

label_8005E9F8:
    ctx->pc = 0x8005E9F8u;
    // 8005E9F8: stw     r8, -27920(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27920);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005E9FC:
    ctx->pc = 0x8005E9FCu;
    // 8005E9FC: li      r7, 50
    ctx->gpr[7] = (u32)(s32)(50);

label_8005EA00:
    ctx->pc = 0x8005EA00u;
    // 8005EA00: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EA04:
    ctx->pc = 0x8005EA04u;
    // 8005EA04: li      r6, 350
    ctx->gpr[6] = (u32)(s32)(350);

label_8005EA08:
    ctx->pc = 0x8005EA08u;
    // 8005EA08: stw     r0, 8384(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8384);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EA0C:
    ctx->pc = 0x8005EA0Cu;
    // 8005EA0C: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8005EA10:
    ctx->pc = 0x8005EA10u;
    // 8005EA10: stw     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA14:
    ctx->pc = 0x8005EA14u;
    // 8005EA14: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8005EA18:
    ctx->pc = 0x8005EA18u;
    // 8005EA18: stw     r11, 8376(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8376);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA1C:
    ctx->pc = 0x8005EA1Cu;
    // 8005EA1C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8005EA20:
    ctx->pc = 0x8005EA20u;
    // 8005EA20: stw     r11, 8380(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8380);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA24:
    ctx->pc = 0x8005EA24u;
    // 8005EA24: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_8005EA28:
    ctx->pc = 0x8005EA28u;
    // 8005EA28: stw     r11, 16752(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16752);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA2C:
    ctx->pc = 0x8005EA2Cu;
    // 8005EA2C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005EA30:
    ctx->pc = 0x8005EA30u;
    // 8005EA30: stw     r11, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA34:
    ctx->pc = 0x8005EA34u;
    // 8005EA34: li      r31, 320
    ctx->gpr[31] = (u32)(s32)(320);

label_8005EA38:
    ctx->pc = 0x8005EA38u;
    // 8005EA38: lfs     f0, 23804(r10)
    if (!ppc_fp_available(ctx, 0x8005EA38u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(23804);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8005EA3C:
    ctx->pc = 0x8005EA3Cu;
    // 8005EA3C: li      r12, -1
    ctx->gpr[12] = (u32)(s32)(-1);

label_8005EA40:
    ctx->pc = 0x8005EA40u;
    // 8005EA40: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_8005EA44:
    ctx->pc = 0x8005EA44u;
    // 8005EA44: stw     r7, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005EA48:
    ctx->pc = 0x8005EA48u;
    // 8005EA48: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8005EA4C:
    ctx->pc = 0x8005EA4Cu;
    // 8005EA4C: stw     r6, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005EA50:
    ctx->pc = 0x8005EA50u;
    // 8005EA50: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EA54:
    ctx->pc = 0x8005EA54u;
    // 8005EA54: addi    r8, r3, 20
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(20);

label_8005EA58:
    ctx->pc = 0x8005EA58u;
    // 8005EA58: stw     r5, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8005EA5C:
    ctx->pc = 0x8005EA5Cu;
    // 8005EA5C: stw     r11, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA60:
    ctx->pc = 0x8005EA60u;
    // 8005EA60: stw     r11, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA64:
    ctx->pc = 0x8005EA64u;
    // 8005EA64: stw     r11, 132(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA68:
    ctx->pc = 0x8005EA68u;
    // 8005EA68: stw     r11, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EA6C:
    ctx->pc = 0x8005EA6Cu;
    ctx->downcount -= 7;
    // 8005EA6C: stw     r4, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005EA70:
    ctx->pc = 0x8005EA70u;
    // 8005EA70: stw     r4, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8005EA74:
    ctx->pc = 0x8005EA74u;
    // 8005EA74: stw     r31, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005EA78:
    ctx->pc = 0x8005EA78u;
    // 8005EA78: stw     r12, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8005EA7C:
    ctx->pc = 0x8005EA7Cu;
    // 8005EA7C: stfs     f0, 16(r8)
    if (!ppc_fp_available(ctx, 0x8005EA7Cu)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8005EA80:
    // 8005EA80: addi    r8, r8, 20
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(20);

label_8005EA84:
    // 8005EA84: bc    16, 0, 0x8005EA6C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005EA6Cu;
                return;
            }
            goto label_8005EA6C;
        }
    }

label_8005EA88:
    ctx->pc = 0x8005EA88u;
    ctx->downcount -= 19;
    // 8005EA88: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005EA8C:
    ctx->pc = 0x8005EA8Cu;
    // 8005EA8C: li      r10, 320
    ctx->gpr[10] = (u32)(s32)(320);

label_8005EA90:
    ctx->pc = 0x8005EA90u;
    // 8005EA90: li      r0, 150
    ctx->gpr[0] = (u32)(s32)(150);

label_8005EA94:
    ctx->pc = 0x8005EA94u;
    // 8005EA94: li      r11, -1
    ctx->gpr[11] = (u32)(s32)(-1);

label_8005EA98:
    ctx->pc = 0x8005EA98u;
    // 8005EA98: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EA9C:
    ctx->pc = 0x8005EA9Cu;
    // 8005EA9C: lis     r7, -32699
    ctx->gpr[7] = ((u32)(s32)(-32699) << 16);

label_8005EAA0:
    ctx->pc = 0x8005EAA0u;
    // 8005EAA0: stw     r10, 140(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005EAA4:
    ctx->pc = 0x8005EAA4u;
    // 8005EAA4: li      r8, 16
    ctx->gpr[8] = (u32)(s32)(16);

label_8005EAA8:
    ctx->pc = 0x8005EAA8u;
    // 8005EAA8: stw     r11, 144(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EAAC:
    ctx->pc = 0x8005EAACu;
    // 8005EAAC: li      r0, 43
    ctx->gpr[0] = (u32)(s32)(43);

label_8005EAB0:
    ctx->pc = 0x8005EAB0u;
    // 8005EAB0: stw     r9, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EAB4:
    ctx->pc = 0x8005EAB4u;
    // 8005EAB4: stw     r10, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005EAB8:
    ctx->pc = 0x8005EAB8u;
    // 8005EAB8: stw     r9, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EABC:
    ctx->pc = 0x8005EABCu;
    // 8005EABC: stw     r9, 160(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EAC0:
    ctx->pc = 0x8005EAC0u;
    // 8005EAC0: stw     r9, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EAC4:
    ctx->pc = 0x8005EAC4u;
    // 8005EAC4: stw     r9, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EAC8:
    ctx->pc = 0x8005EAC8u;
    // 8005EAC8: sth     r8, -21584(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-21584);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_8005EACC:
    ctx->pc = 0x8005EACCu;
    // 8005EACC: stw     r0, 128(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EAD0:
    ctx->pc = 0x8005EAD0u;
    // 8005EAD0: bl      0x80008860
    {
            ctx->lr = 0x8005EAD4u;
            ctx->pc = 0x80008860u;
            return;
    }

label_8005EAD4:
    ctx->pc = 0x8005EAD4u;
    ctx->downcount -= 6;
    // 8005EAD4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EAD8:
    ctx->pc = 0x8005EAD8u;
    // 8005EAD8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005EADC:
    ctx->pc = 0x8005EADCu;
    // 8005EADC: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8005EAE0:
    ctx->pc = 0x8005EAE0u;
    // 8005EAE0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_8005EAE4:
    ctx->pc = 0x8005EAE4u;
    // 8005EAE4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005EAE8:
    ctx->pc = 0x8005EAE8u;
    ctx->downcount -= 5;
    // 8005EAE8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005EAEC:
    ctx->pc = 0x8005EAECu;
    // 8005EAEC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005EAF0:
    ctx->pc = 0x8005EAF0u;
    // 8005EAF0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EAF4:
    ctx->pc = 0x8005EAF4u;
    // 8005EAF4: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_8005EAF8:
    ctx->pc = 0x8005EAF8u;
    // 8005EAF8: bl      0x8005C860
    {
            ctx->lr = 0x8005EAFCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005C860u;
                return;
            }
            goto label_8005C860;
    }

label_8005EAFC:
    ctx->pc = 0x8005EAFCu;
    ctx->downcount -= 5;
    // 8005EAFC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EB00:
    ctx->pc = 0x8005EB00u;
    // 8005EB00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005EB04:
    ctx->pc = 0x8005EB04u;
    // 8005EB04: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005EB08:
    ctx->pc = 0x8005EB08u;
    // 8005EB08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005EB0C:
    ctx->pc = 0x8005EB0Cu;
    ctx->downcount -= 5;
    // 8005EB0C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005EB10:
    ctx->pc = 0x8005EB10u;
    // 8005EB10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005EB14:
    ctx->pc = 0x8005EB14u;
    // 8005EB14: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EB18:
    ctx->pc = 0x8005EB18u;
    // 8005EB18: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_8005EB1C:
    ctx->pc = 0x8005EB1Cu;
    // 8005EB1C: bl      0x8005D53C
    {
            ctx->lr = 0x8005EB20u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005D53Cu;
                return;
            }
            goto label_8005D53C;
    }

label_8005EB20:
    ctx->pc = 0x8005EB20u;
    ctx->downcount -= 5;
    // 8005EB20: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EB24:
    ctx->pc = 0x8005EB24u;
    // 8005EB24: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005EB28:
    ctx->pc = 0x8005EB28u;
    // 8005EB28: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005EB2C:
    ctx->pc = 0x8005EB2Cu;
    // 8005EB2C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005EB30:
    ctx->pc = 0x8005EB30u;
    ctx->downcount -= 1;
    // 8005EB30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005EB34:
    ctx->pc = 0x8005EB34u;
    ctx->downcount -= 6;
    // 8005EB34: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005EB38:
    ctx->pc = 0x8005EB38u;
    // 8005EB38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005EB3C:
    ctx->pc = 0x8005EB3Cu;
    // 8005EB3C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EB40:
    ctx->pc = 0x8005EB40u;
    // 8005EB40: lwz     r0, -31800(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31800);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EB44:
    ctx->pc = 0x8005EB44u;
    // 8005EB44: andi.   r9, r0, 0x0007
    {
        ctx->gpr[9] = ctx->gpr[0] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005EB48:
    ctx->pc = 0x8005EB48u;
    // 8005EB48: bc    4, 2, 0x8005EB68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005EB68;
        }
    }

label_8005EB4C:
    ctx->pc = 0x8005EB4Cu;
    ctx->downcount -= 4;
    // 8005EB4C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EB50:
    ctx->pc = 0x8005EB50u;
    // 8005EB50: lhz     r0, -20674(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20674);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005EB54:
    ctx->pc = 0x8005EB54u;
    // 8005EB54: andi.   r0, r0, 0x0200
    {
        ctx->gpr[0] = ctx->gpr[0] & 0x0200u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005EB58:
    ctx->pc = 0x8005EB58u;
    // 8005EB58: bc    4, 2, 0x8005EB68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005EB68;
        }
    }

label_8005EB5C:
    ctx->pc = 0x8005EB5Cu;
    ctx->downcount -= 3;
    // 8005EB5C: stw     r0, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EB60:
    ctx->pc = 0x8005EB60u;
    // 8005EB60: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005EB64:
    ctx->pc = 0x8005EB64u;
    // 8005EB64: b       0x8005EC64
    {
            goto label_8005EC64;
    }

label_8005EB68:
    ctx->pc = 0x8005EB68u;
    ctx->downcount -= 7;
    // 8005EB68: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_8005EB6C:
    ctx->pc = 0x8005EB6Cu;
    // 8005EB6C: lwz     r7, -27928(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27928);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005EB70:
    ctx->pc = 0x8005EB70u;
    // 8005EB70: addi    r4, r4, 30860
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(30860);

label_8005EB74:
    ctx->pc = 0x8005EB74u;
    // 8005EB74: li      r3, 600
    ctx->gpr[3] = (u32)(s32)(600);

label_8005EB78:
    ctx->pc = 0x8005EB78u;
    // 8005EB78: li      r5, 3
    ctx->gpr[5] = (u32)(s32)(3);

label_8005EB7C:
    ctx->pc = 0x8005EB7Cu;
    // 8005EB7C: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_8005EB80:
    ctx->pc = 0x8005EB80u;
    // 8005EB80: bl      0x80039A00
    {
            ctx->lr = 0x8005EB84u;
            ctx->pc = 0x80039A00u;
            return;
    }

label_8005EB84:
    ctx->pc = 0x8005EB84u;
    ctx->downcount -= 3;
    // 8005EB84: stw     r3, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005EB88:
    ctx->pc = 0x8005EB88u;
    // 8005EB88: cmpwi   r3, 0
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

label_8005EB8C:
    ctx->pc = 0x8005EB8Cu;
    // 8005EB8C: bc    4, 2, 0x8005EB98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005EB98;
        }
    }

label_8005EB90:
    ctx->pc = 0x8005EB90u;
    ctx->downcount -= 2;
    // 8005EB90: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005EB94:
    ctx->pc = 0x8005EB94u;
    // 8005EB94: b       0x8005EC64
    {
            goto label_8005EC64;
    }

label_8005EB98:
    ctx->pc = 0x8005EB98u;
    ctx->downcount -= 5;
    // 8005EB98: li      r9, 10
    ctx->gpr[9] = (u32)(s32)(10);

label_8005EB9C:
    ctx->pc = 0x8005EB9Cu;
    // 8005EB9C: addi    r3, r3, 552
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(552);

label_8005EBA0:
    ctx->pc = 0x8005EBA0u;
    // 8005EBA0: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_8005EBA4:
    ctx->pc = 0x8005EBA4u;
    // 8005EBA4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005EBA8:
    loop_8005EBA8(ctx);
    if (ctx->pc == 0x8005EBB8u) goto label_8005EBB8;
    return;
label_8005EBAC:
    ctx->pc = 0x8005EBACu;
    // 8005EBAC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EBB0:
    // 8005EBB0: addi    r3, r3, 4
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(4);

label_8005EBB4:
    // 8005EBB4: bc    16, 0, 0x8005EBA8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005EBA8u;
                return;
            }
            goto label_8005EBA8;
        }
    }

label_8005EBB8:
    ctx->pc = 0x8005EBB8u;
    ctx->downcount -= 9;
    // 8005EBB8: lwz     r0, -31800(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31800);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EBBC:
    ctx->pc = 0x8005EBBCu;
    // 8005EBBC: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_8005EBC0:
    ctx->pc = 0x8005EBC0u;
    // 8005EBC0: lwz     r10, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005EBC4:
    ctx->pc = 0x8005EBC4u;
    // 8005EBC4: li      r11, -1
    ctx->gpr[11] = (u32)(s32)(-1);

label_8005EBC8:
    ctx->pc = 0x8005EBC8u;
    // 8005EBC8: rlwinm r0, r0, 0, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000007u;
    }

label_8005EBCC:
    ctx->pc = 0x8005EBCCu;
    // 8005EBCC: stw     r9, 592(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(592);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EBD0:
    ctx->pc = 0x8005EBD0u;
    // 8005EBD0: cmpwi   r0, 2
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

label_8005EBD4:
    ctx->pc = 0x8005EBD4u;
    // 8005EBD4: stw     r11, 596(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005EBD8:
    ctx->pc = 0x8005EBD8u;
    // 8005EBD8: bc    12, 2, 0x8005EC14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EC14;
        }
    }

label_8005EBDC:
    ctx->pc = 0x8005EBDCu;
    ctx->downcount -= 2;
    // 8005EBDC: cmplwi  r0, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EBE0:
    ctx->pc = 0x8005EBE0u;
    // 8005EBE0: bc    12, 1, 0x8005EBF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EBF0;
        }
    }

label_8005EBE4:
    ctx->pc = 0x8005EBE4u;
    ctx->downcount -= 2;
    // 8005EBE4: cmpwi   r0, 1
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

label_8005EBE8:
    ctx->pc = 0x8005EBE8u;
    // 8005EBE8: bc    12, 2, 0x8005EC04
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EC04;
        }
    }

label_8005EBEC:
    ctx->pc = 0x8005EBECu;
    ctx->downcount -= 1;
    // 8005EBEC: b       0x8005EC34
    {
            goto label_8005EC34;
    }

label_8005EBF0:
    ctx->pc = 0x8005EBF0u;
    ctx->downcount -= 2;
    // 8005EBF0: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EBF4:
    ctx->pc = 0x8005EBF4u;
    // 8005EBF4: bc    12, 2, 0x8005EC24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EC24;
        }
    }

label_8005EBF8:
    ctx->pc = 0x8005EBF8u;
    ctx->downcount -= 2;
    // 8005EBF8: cmpwi   r0, 4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EBFC:
    ctx->pc = 0x8005EBFCu;
    // 8005EBFC: bc    4, 2, 0x8005EC34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005EC34;
        }
    }

label_8005EC00:
    ctx->pc = 0x8005EC00u;
    ctx->downcount -= 1;
    // 8005EC00: b       0x8005EC24
    {
            goto label_8005EC24;
    }

label_8005EC04:
    ctx->pc = 0x8005EC04u;
    ctx->downcount -= 4;
    // 8005EC04: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005EC08:
    ctx->pc = 0x8005EC08u;
    // 8005EC08: addi    r9, r9, 9556
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9556);

label_8005EC0C:
    ctx->pc = 0x8005EC0Cu;
    // 8005EC0C: stw     r9, 512(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EC10:
    ctx->pc = 0x8005EC10u;
    // 8005EC10: b       0x8005EC44
    {
            goto label_8005EC44;
    }

label_8005EC14:
    ctx->pc = 0x8005EC14u;
    ctx->downcount -= 4;
    // 8005EC14: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EC18:
    ctx->pc = 0x8005EC18u;
    // 8005EC18: addi    r9, r9, 15540
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15540);

label_8005EC1C:
    ctx->pc = 0x8005EC1Cu;
    // 8005EC1C: stw     r9, 512(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EC20:
    ctx->pc = 0x8005EC20u;
    // 8005EC20: b       0x8005EC44
    {
            goto label_8005EC44;
    }

label_8005EC24:
    ctx->pc = 0x8005EC24u;
    ctx->downcount -= 4;
    // 8005EC24: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EC28:
    ctx->pc = 0x8005EC28u;
    // 8005EC28: addi    r9, r9, 15860
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15860);

label_8005EC2C:
    ctx->pc = 0x8005EC2Cu;
    // 8005EC2C: stw     r9, 512(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EC30:
    ctx->pc = 0x8005EC30u;
    // 8005EC30: b       0x8005EC44
    {
            goto label_8005EC44;
    }

label_8005EC34:
    ctx->pc = 0x8005EC34u;
    ctx->downcount -= 4;
    // 8005EC34: lwz     r11, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005EC38:
    ctx->pc = 0x8005EC38u;
    // 8005EC38: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EC3C:
    ctx->pc = 0x8005EC3Cu;
    // 8005EC3C: addi    r9, r9, 15860
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(15860);

label_8005EC40:
    ctx->pc = 0x8005EC40u;
    // 8005EC40: stw     r9, 512(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EC44:
    ctx->pc = 0x8005EC44u;
    ctx->downcount -= 2;
    // 8005EC44: lwz     r3, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005EC48:
    ctx->pc = 0x8005EC48u;
    // 8005EC48: bl      0x80034A2C
    {
            ctx->lr = 0x8005EC4Cu;
            ctx->pc = 0x80034A2Cu;
            return;
    }

label_8005EC4C:
    ctx->pc = 0x8005EC4Cu;
    ctx->downcount -= 5;
    // 8005EC4C: lwz     r3, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005EC50:
    ctx->pc = 0x8005EC50u;
    // 8005EC50: lis     r5, -16384
    ctx->gpr[5] = ((u32)(s32)(-16384) << 16);

label_8005EC54:
    ctx->pc = 0x8005EC54u;
    // 8005EC54: lwz     r4, -27488(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27488);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005EC58:
    ctx->pc = 0x8005EC58u;
    // 8005EC58: ori     r5, r5, 0x0004
    ctx->gpr[5] = ctx->gpr[5] | 0x0004u;

label_8005EC5C:
    ctx->pc = 0x8005EC5Cu;
    // 8005EC5C: bl      0x80034BB0
    {
            ctx->lr = 0x8005EC60u;
            ctx->pc = 0x80034BB0u;
            return;
    }

label_8005EC60:
    ctx->pc = 0x8005EC60u;
    ctx->downcount -= 1;
    // 8005EC60: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005EC64:
    ctx->pc = 0x8005EC64u;
    ctx->downcount -= 5;
    // 8005EC64: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EC68:
    ctx->pc = 0x8005EC68u;
    // 8005EC68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005EC6C:
    ctx->pc = 0x8005EC6Cu;
    // 8005EC6C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005EC70:
    ctx->pc = 0x8005EC70u;
    // 8005EC70: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005EC74:
    ctx->pc = 0x8005EC74u;
    ctx->downcount -= 17;
    // 8005EC74: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005EC78:
    ctx->pc = 0x8005EC78u;
    // 8005EC78: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005EC7C:
    ctx->pc = 0x8005EC7Cu;
    // 8005EC7C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005EC80:
    ctx->pc = 0x8005EC80u;
    // 8005EC80: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EC84:
    ctx->pc = 0x8005EC84u;
    // 8005EC84: lwz     r11, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005EC88:
    ctx->pc = 0x8005EC88u;
    // 8005EC88: cmpwi   r11, 0
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

label_8005EC8C:
    ctx->pc = 0x8005EC8Cu;
    // 8005EC8C: bc    12, 2, 0x8005EFB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EFB4;
        }
    }

label_8005EC90:
    ctx->pc = 0x8005EC90u;
    ctx->downcount -= 9;
    // 8005EC90: lwz     r9, 592(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EC94:
    ctx->pc = 0x8005EC94u;
    // 8005EC94: addi    r10, r11, 552
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(552);

label_8005EC98:
    ctx->pc = 0x8005EC98u;
    // 8005EC98: addi    r11, r11, 512
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(512);

label_8005EC9C:
    ctx->pc = 0x8005EC9Cu;
    // 8005EC9C: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_8005ECA0:
    ctx->pc = 0x8005ECA0u;
    // 8005ECA0: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8005ECA4:
    ctx->pc = 0x8005ECA4u;
    // 8005ECA4: lwzx    r31, r10, r9
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[9];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8005ECA8:
    ctx->pc = 0x8005ECA8u;
    // 8005ECA8: lwzx    r30, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8005ECAC:
    ctx->pc = 0x8005ECACu;
    // 8005ECAC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8005ECB0:
    ctx->pc = 0x8005ECB0u;
    // 8005ECB0: bl      0x8005F41C
    {
            ctx->lr = 0x8005ECB4u;
            ctx->pc = 0x8005F41Cu;
            return;
    }

label_8005ECB4:
    ctx->pc = 0x8005ECB4u;
    ctx->downcount -= 3;
    // 8005ECB4: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005ECB8:
    ctx->pc = 0x8005ECB8u;
    // 8005ECB8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005ECBC:
    ctx->pc = 0x8005ECBCu;
    // 8005ECBC: bl      0x8005F3F4
    {
            ctx->lr = 0x8005ECC0u;
            ctx->pc = 0x8005F3F4u;
            return;
    }

label_8005ECC0:
    ctx->pc = 0x8005ECC0u;
    ctx->downcount -= 8;
    // 8005ECC0: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005ECC4:
    ctx->pc = 0x8005ECC4u;
    // 8005ECC4: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005ECC8:
    ctx->pc = 0x8005ECC8u;
    // 8005ECC8: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005ECCC:
    ctx->pc = 0x8005ECCCu;
    // 8005ECCC: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005ECD0:
    ctx->pc = 0x8005ECD0u;
    // 8005ECD0: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_8005ECD4:
    ctx->pc = 0x8005ECD4u;
    // 8005ECD4: rlwinm r9, r0, 0, 11, 11
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00100000u;
    }

label_8005ECD8:
    ctx->pc = 0x8005ECD8u;
    // 8005ECD8: and.   r10, r9, r11
    {
        ctx->gpr[10] = ctx->gpr[9] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005ECDC:
    ctx->pc = 0x8005ECDCu;
    // 8005ECDC: bc    4, 2, 0x8005ECEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005ECEC;
        }
    }

label_8005ECE0:
    ctx->pc = 0x8005ECE0u;
    ctx->downcount -= 3;
    // 8005ECE0: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_8005ECE4:
    ctx->pc = 0x8005ECE4u;
    // 8005ECE4: and.   r9, r0, r11
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005ECE8:
    ctx->pc = 0x8005ECE8u;
    // 8005ECE8: bc    12, 2, 0x8005ECF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005ECF8;
        }
    }

label_8005ECEC:
    ctx->pc = 0x8005ECECu;
    ctx->downcount -= 2;
    // 8005ECEC: cmpwi   r31, 0
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

label_8005ECF0:
    ctx->pc = 0x8005ECF0u;
    // 8005ECF0: bc    4, 1, 0x8005ECF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005ECF8;
        }
    }

label_8005ECF4:
    ctx->pc = 0x8005ECF4u;
    ctx->downcount -= 1;
    // 8005ECF4: addi    r31, r31, -1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(-1);

label_8005ECF8:
    ctx->pc = 0x8005ECF8u;
    ctx->downcount -= 8;
    // 8005ECF8: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005ECFC:
    ctx->pc = 0x8005ECFCu;
    // 8005ECFC: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005ED00:
    ctx->pc = 0x8005ED00u;
    // 8005ED00: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005ED04:
    ctx->pc = 0x8005ED04u;
    // 8005ED04: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005ED08:
    ctx->pc = 0x8005ED08u;
    // 8005ED08: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_8005ED0C:
    ctx->pc = 0x8005ED0Cu;
    // 8005ED0C: rlwinm r9, r0, 0, 10, 10
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00200000u;
    }

label_8005ED10:
    ctx->pc = 0x8005ED10u;
    // 8005ED10: and.   r10, r9, r11
    {
        ctx->gpr[10] = ctx->gpr[9] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005ED14:
    ctx->pc = 0x8005ED14u;
    // 8005ED14: bc    4, 2, 0x8005ED24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005ED24;
        }
    }

label_8005ED18:
    ctx->pc = 0x8005ED18u;
    ctx->downcount -= 3;
    // 8005ED18: rlwinm r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
    }

label_8005ED1C:
    ctx->pc = 0x8005ED1Cu;
    // 8005ED1C: and.   r9, r0, r11
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005ED20:
    ctx->pc = 0x8005ED20u;
    // 8005ED20: bc    12, 2, 0x8005ED34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005ED34;
        }
    }

label_8005ED24:
    ctx->pc = 0x8005ED24u;
    ctx->downcount -= 3;
    // 8005ED24: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_8005ED28:
    ctx->pc = 0x8005ED28u;
    // 8005ED28: cmpw    r31, r0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005ED2C:
    ctx->pc = 0x8005ED2Cu;
    // 8005ED2C: bc    4, 0, 0x8005ED34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005ED34;
        }
    }

label_8005ED30:
    ctx->pc = 0x8005ED30u;
    ctx->downcount -= 1;
    // 8005ED30: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8005ED34:
    ctx->pc = 0x8005ED34u;
    ctx->downcount -= 14;
    // 8005ED34: lwz     r7, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005ED38:
    ctx->pc = 0x8005ED38u;
    // 8005ED38: lis     r11, -32700
    ctx->gpr[11] = ((u32)(s32)(-32700) << 16);

label_8005ED3C:
    ctx->pc = 0x8005ED3Cu;
    // 8005ED3C: addi    r11, r11, -21024
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21024);

label_8005ED40:
    ctx->pc = 0x8005ED40u;
    // 8005ED40: lwz     r9, 592(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005ED44:
    ctx->pc = 0x8005ED44u;
    // 8005ED44: addi    r10, r7, 552
    ctx->gpr[10] = ctx->gpr[7] + (u32)(s32)(552);

label_8005ED48:
    ctx->pc = 0x8005ED48u;
    // 8005ED48: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_8005ED4C:
    ctx->pc = 0x8005ED4Cu;
    // 8005ED4C: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8005ED50:
    ctx->pc = 0x8005ED50u;
    // 8005ED50: stwx    r31, r10, r9
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[9];
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005ED54:
    ctx->pc = 0x8005ED54u;
    // 8005ED54: lwz     r10, 28(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005ED58:
    ctx->pc = 0x8005ED58u;
    // 8005ED58: lwz     r0, 32(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005ED5C:
    ctx->pc = 0x8005ED5Cu;
    // 8005ED5C: xor   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[10];
    }

label_8005ED60:
    ctx->pc = 0x8005ED60u;
    // 8005ED60: rlwinm r9, r0, 0, 8, 8
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00800000u;
    }

label_8005ED64:
    ctx->pc = 0x8005ED64u;
    // 8005ED64: and.   r11, r9, r10
    {
        ctx->gpr[11] = ctx->gpr[9] & ctx->gpr[10];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005ED68:
    ctx->pc = 0x8005ED68u;
    // 8005ED68: bc    4, 2, 0x8005ED78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005ED78;
        }
    }

label_8005ED6C:
    ctx->pc = 0x8005ED6Cu;
    ctx->downcount -= 3;
    // 8005ED6C: rlwinm r0, r0, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000008u;
    }

label_8005ED70:
    ctx->pc = 0x8005ED70u;
    // 8005ED70: and.   r9, r0, r10
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[10];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005ED74:
    ctx->pc = 0x8005ED74u;
    // 8005ED74: bc    12, 2, 0x8005EDFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EDFC;
        }
    }

label_8005ED78:
    ctx->pc = 0x8005ED78u;
    ctx->downcount -= 7;
    // 8005ED78: mulli   r0, r31, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[31] * (s64)(s32)20);

label_8005ED7C:
    ctx->pc = 0x8005ED7Cu;
    // 8005ED7C: add   r8, r0, r30
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[30];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8005ED80:
    ctx->pc = 0x8005ED80u;
    // 8005ED80: lwz     r9, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005ED84:
    ctx->pc = 0x8005ED84u;
    // 8005ED84: cmpwi   r9, 0
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

label_8005ED88:
    ctx->pc = 0x8005ED88u;
    // 8005ED88: bc    12, 2, 0x8005EDFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EDFC;
        }
    }

label_8005ED8C:
    ctx->pc = 0x8005ED8Cu;
    ctx->downcount -= 2;
    // 8005ED8C: cmpwi   r29, 0
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

label_8005ED90:
    ctx->pc = 0x8005ED90u;
    // 8005ED90: bc    12, 2, 0x8005EDFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EDFC;
        }
    }

label_8005ED94:
    ctx->pc = 0x8005ED94u;
    ctx->downcount -= 3;
    // 8005ED94: lwz     r0, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005ED98:
    ctx->pc = 0x8005ED98u;
    // 8005ED98: cmpwi   r0, 2
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

label_8005ED9C:
    ctx->pc = 0x8005ED9Cu;
    // 8005ED9C: bc    4, 2, 0x8005EDA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005EDA8;
        }
    }

label_8005EDA0:
    ctx->pc = 0x8005EDA0u;
    ctx->downcount -= 2;
    // 8005EDA0: lhz     r0, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005EDA4:
    ctx->pc = 0x8005EDA4u;
    // 8005EDA4: stw     r0, 596(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EDA8:
    ctx->pc = 0x8005EDA8u;
    ctx->downcount -= 8;
    // 8005EDA8: lwz     r10, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005EDAC:
    ctx->pc = 0x8005EDACu;
    // 8005EDAC: lwz     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EDB0:
    ctx->pc = 0x8005EDB0u;
    // 8005EDB0: lwz     r9, 592(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EDB4:
    ctx->pc = 0x8005EDB4u;
    // 8005EDB4: addi    r6, r10, 512
    ctx->gpr[6] = ctx->gpr[10] + (u32)(s32)(512);

label_8005EDB8:
    ctx->pc = 0x8005EDB8u;
    // 8005EDB8: rlwinm r7, r9, 2, 0, 29
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8005EDBC:
    ctx->pc = 0x8005EDBCu;
    // 8005EDBC: lwzx    r11, r6, r7
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[7];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005EDC0:
    ctx->pc = 0x8005EDC0u;
    // 8005EDC0: cmpw    r11, r0
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

label_8005EDC4:
    ctx->pc = 0x8005EDC4u;
    // 8005EDC4: bc    12, 2, 0x8005EDE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EDE4;
        }
    }

label_8005EDC8:
    ctx->pc = 0x8005EDC8u;
    ctx->downcount -= 7;
    // 8005EDC8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005EDCC:
    ctx->pc = 0x8005EDCCu;
    // 8005EDCC: addi    r11, r10, 552
    ctx->gpr[11] = ctx->gpr[10] + (u32)(s32)(552);

label_8005EDD0:
    ctx->pc = 0x8005EDD0u;
    // 8005EDD0: stwx    r9, r11, r7
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[7];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EDD4:
    ctx->pc = 0x8005EDD4u;
    // 8005EDD4: lwz     r0, 592(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EDD8:
    ctx->pc = 0x8005EDD8u;
    // 8005EDD8: lwz     r9, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EDDC:
    ctx->pc = 0x8005EDDCu;
    // 8005EDDC: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8005EDE0:
    ctx->pc = 0x8005EDE0u;
    // 8005EDE0: stwx    r9, r6, r0
    {
        u32 ea = ctx->gpr[6] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EDE4:
    ctx->pc = 0x8005EDE4u;
    ctx->downcount -= 6;
    // 8005EDE4: lwz     r11, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005EDE8:
    ctx->pc = 0x8005EDE8u;
    // 8005EDE8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005EDEC:
    ctx->pc = 0x8005EDECu;
    // 8005EDEC: lwz     r9, 592(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EDF0:
    ctx->pc = 0x8005EDF0u;
    // 8005EDF0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_8005EDF4:
    ctx->pc = 0x8005EDF4u;
    // 8005EDF4: stw     r9, 592(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(592);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005EDF8:
    ctx->pc = 0x8005EDF8u;
    // 8005EDF8: b       0x8005EFB8
    {
            goto label_8005EFB8;
    }

label_8005EDFC:
    ctx->pc = 0x8005EDFCu;
    ctx->downcount -= 8;
    // 8005EDFC: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005EE00:
    ctx->pc = 0x8005EE00u;
    // 8005EE00: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005EE04:
    ctx->pc = 0x8005EE04u;
    // 8005EE04: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005EE08:
    ctx->pc = 0x8005EE08u;
    // 8005EE08: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EE0C:
    ctx->pc = 0x8005EE0Cu;
    // 8005EE0C: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_8005EE10:
    ctx->pc = 0x8005EE10u;
    // 8005EE10: rlwinm r9, r0, 0, 9, 9
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00400000u;
    }

label_8005EE14:
    ctx->pc = 0x8005EE14u;
    // 8005EE14: and.   r10, r9, r11
    {
        ctx->gpr[10] = ctx->gpr[9] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005EE18:
    ctx->pc = 0x8005EE18u;
    // 8005EE18: bc    4, 2, 0x8005EE28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005EE28;
        }
    }

label_8005EE1C:
    ctx->pc = 0x8005EE1Cu;
    ctx->downcount -= 3;
    // 8005EE1C: rlwinm r0, r0, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
    }

label_8005EE20:
    ctx->pc = 0x8005EE20u;
    // 8005EE20: and.   r9, r0, r11
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005EE24:
    ctx->pc = 0x8005EE24u;
    // 8005EE24: bc    12, 2, 0x8005EE48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EE48;
        }
    }

label_8005EE28:
    ctx->pc = 0x8005EE28u;
    ctx->downcount -= 4;
    // 8005EE28: lwz     r11, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005EE2C:
    ctx->pc = 0x8005EE2Cu;
    // 8005EE2C: lwz     r9, 592(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EE30:
    ctx->pc = 0x8005EE30u;
    // 8005EE30: cmpwi   r9, 1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EE34:
    ctx->pc = 0x8005EE34u;
    // 8005EE34: bc    4, 1, 0x8005EE48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005EE48;
        }
    }

label_8005EE38:
    ctx->pc = 0x8005EE38u;
    ctx->downcount -= 4;
    // 8005EE38: addi    r0, r9, -1
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-1);

label_8005EE3C:
    ctx->pc = 0x8005EE3Cu;
    // 8005EE3C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005EE40:
    ctx->pc = 0x8005EE40u;
    // 8005EE40: stw     r0, 592(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EE44:
    ctx->pc = 0x8005EE44u;
    // 8005EE44: b       0x8005EFB8
    {
            goto label_8005EFB8;
    }

label_8005EE48:
    ctx->pc = 0x8005EE48u;
    ctx->downcount -= 8;
    // 8005EE48: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_8005EE4C:
    ctx->pc = 0x8005EE4Cu;
    // 8005EE4C: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_8005EE50:
    ctx->pc = 0x8005EE50u;
    // 8005EE50: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005EE54:
    ctx->pc = 0x8005EE54u;
    // 8005EE54: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EE58:
    ctx->pc = 0x8005EE58u;
    // 8005EE58: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_8005EE5C:
    ctx->pc = 0x8005EE5Cu;
    // 8005EE5C: rlwinm r0, r0, 0, 15, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00010000u;
    }

label_8005EE60:
    ctx->pc = 0x8005EE60u;
    // 8005EE60: and.   r10, r0, r11
    {
        ctx->gpr[10] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005EE64:
    ctx->pc = 0x8005EE64u;
    // 8005EE64: bc    12, 2, 0x8005EFB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EFB4;
        }
    }

label_8005EE68:
    ctx->pc = 0x8005EE68u;
    ctx->downcount -= 2;
    // 8005EE68: cmpwi   r29, 0
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

label_8005EE6C:
    ctx->pc = 0x8005EE6Cu;
    // 8005EE6C: bc    12, 2, 0x8005EFB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EFB4;
        }
    }

label_8005EE70:
    ctx->pc = 0x8005EE70u;
    ctx->downcount -= 7;
    // 8005EE70: mulli   r0, r31, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[31] * (s64)(s32)20);

label_8005EE74:
    ctx->pc = 0x8005EE74u;
    // 8005EE74: add   r3, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_8005EE78:
    ctx->pc = 0x8005EE78u;
    // 8005EE78: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EE7C:
    ctx->pc = 0x8005EE7Cu;
    // 8005EE7C: cmpwi   r0, 2
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

label_8005EE80:
    ctx->pc = 0x8005EE80u;
    // 8005EE80: bc    12, 2, 0x8005EEE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EEE4;
        }
    }

label_8005EE84:
    ctx->pc = 0x8005EE84u;
    ctx->downcount -= 2;
    // 8005EE84: cmplwi  r0, 0x0002
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0002u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EE88:
    ctx->pc = 0x8005EE88u;
    // 8005EE88: bc    12, 1, 0x8005EE98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EE98;
        }
    }

label_8005EE8C:
    ctx->pc = 0x8005EE8Cu;
    ctx->downcount -= 2;
    // 8005EE8C: cmpwi   r0, 1
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

label_8005EE90:
    ctx->pc = 0x8005EE90u;
    // 8005EE90: bc    12, 2, 0x8005EEAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EEAC;
        }
    }

label_8005EE94:
    ctx->pc = 0x8005EE94u;
    ctx->downcount -= 1;
    // 8005EE94: b       0x8005EFB4
    {
            goto label_8005EFB4;
    }

label_8005EE98:
    ctx->pc = 0x8005EE98u;
    ctx->downcount -= 2;
    // 8005EE98: cmpwi   r0, 3
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EE9C:
    ctx->pc = 0x8005EE9Cu;
    // 8005EE9C: bc    12, 2, 0x8005EF10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EF10;
        }
    }

label_8005EEA0:
    ctx->pc = 0x8005EEA0u;
    ctx->downcount -= 2;
    // 8005EEA0: cmpwi   r0, 4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EEA4:
    ctx->pc = 0x8005EEA4u;
    // 8005EEA4: bc    12, 2, 0x8005EF50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EF50;
        }
    }

label_8005EEA8:
    ctx->pc = 0x8005EEA8u;
    ctx->downcount -= 1;
    // 8005EEA8: b       0x8005EFB4
    {
            goto label_8005EFB4;
    }

label_8005EEAC:
    ctx->pc = 0x8005EEACu;
    ctx->downcount -= 10;
    // 8005EEAC: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EEB0:
    ctx->pc = 0x8005EEB0u;
    // 8005EEB0: lwz     r8, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005EEB4:
    ctx->pc = 0x8005EEB4u;
    // 8005EEB4: addi    r10, r9, -21636
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005EEB8:
    ctx->pc = 0x8005EEB8u;
    // 8005EEB8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005EEBC:
    ctx->pc = 0x8005EEBCu;
    // 8005EEBC: sth     r11, 660(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(660);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_8005EEC0:
    ctx->pc = 0x8005EEC0u;
    // 8005EEC0: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_8005EEC4:
    ctx->pc = 0x8005EEC4u;
    // 8005EEC4: stw     r0, -31472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31472);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EEC8:
    ctx->pc = 0x8005EEC8u;
    // 8005EEC8: lwz     r9, 596(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(596);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EECC:
    ctx->pc = 0x8005EECCu;
    // 8005EECC: cmpwi   r9, -1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EED0:
    ctx->pc = 0x8005EED0u;
    // 8005EED0: bc    12, 2, 0x8005EEDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EEDC;
        }
    }

label_8005EED4:
    ctx->pc = 0x8005EED4u;
    ctx->downcount -= 2;
    // 8005EED4: lhz     r0, 598(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(598);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005EED8:
    ctx->pc = 0x8005EED8u;
    // 8005EED8: sth     r0, 38(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005EEDC:
    ctx->pc = 0x8005EEDCu;
    ctx->downcount -= 2;
    // 8005EEDC: lhz     r3, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8005EEE0:
    ctx->pc = 0x8005EEE0u;
    // 8005EEE0: b       0x8005EFA8
    {
            goto label_8005EFA8;
    }

label_8005EEE4:
    ctx->pc = 0x8005EEE4u;
    ctx->downcount -= 11;
    // 8005EEE4: lwz     r3, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005EEE8:
    ctx->pc = 0x8005EEE8u;
    // 8005EEE8: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EEEC:
    ctx->pc = 0x8005EEECu;
    // 8005EEEC: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005EEF0:
    ctx->pc = 0x8005EEF0u;
    // 8005EEF0: li      r10, -1
    ctx->gpr[10] = (u32)(s32)(-1);

label_8005EEF4:
    ctx->pc = 0x8005EEF4u;
    // 8005EEF4: rlwinm r0, r3, 16, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0x0000FFFFu;
    }

label_8005EEF8:
    ctx->pc = 0x8005EEF8u;
    // 8005EEF8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8005EEFC:
    ctx->pc = 0x8005EEFCu;
    // 8005EEFC: sth     r0, 38(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005EF00:
    ctx->pc = 0x8005EF00u;
    // 8005EF00: rlwinm r3, r3, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8005EF04:
    ctx->pc = 0x8005EF04u;
    // 8005EF04: stw     r10, -31472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31472);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005EF08:
    ctx->pc = 0x8005EF08u;
    // 8005EF08: sth     r11, 660(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(660);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_8005EF0C:
    ctx->pc = 0x8005EF0Cu;
    // 8005EF0C: b       0x8005EFA8
    {
            goto label_8005EFA8;
    }

label_8005EF10:
    ctx->pc = 0x8005EF10u;
    ctx->downcount -= 18;
    // 8005EF10: lwz     r5, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005EF14:
    ctx->pc = 0x8005EF14u;
    // 8005EF14: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EF18:
    ctx->pc = 0x8005EF18u;
    // 8005EF18: addi    r4, r9, -21636
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005EF1C:
    ctx->pc = 0x8005EF1Cu;
    // 8005EF1C: lwz     r6, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005EF20:
    ctx->pc = 0x8005EF20u;
    // 8005EF20: lwz     r9, 592(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EF24:
    ctx->pc = 0x8005EF24u;
    // 8005EF24: addi    r11, r5, 552
    ctx->gpr[11] = ctx->gpr[5] + (u32)(s32)(552);

label_8005EF28:
    ctx->pc = 0x8005EF28u;
    // 8005EF28: addi    r10, r5, 512
    ctx->gpr[10] = ctx->gpr[5] + (u32)(s32)(512);

label_8005EF2C:
    ctx->pc = 0x8005EF2Cu;
    // 8005EF2C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_8005EF30:
    ctx->pc = 0x8005EF30u;
    // 8005EF30: addi    r9, r9, -2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2);

label_8005EF34:
    ctx->pc = 0x8005EF34u;
    // 8005EF34: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8005EF38:
    ctx->pc = 0x8005EF38u;
    // 8005EF38: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EF3C:
    ctx->pc = 0x8005EF3Cu;
    // 8005EF3C: lwzx    r8, r10, r9
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[9];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005EF40:
    ctx->pc = 0x8005EF40u;
    // 8005EF40: sth     r7, 660(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(660);
        mem_write16(ctx, ea, (u16)ctx->gpr[7]);
    }

label_8005EF44:
    ctx->pc = 0x8005EF44u;
    // 8005EF44: mulli   r0, r0, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_8005EF48:
    ctx->pc = 0x8005EF48u;
    // 8005EF48: stw     r6, -31472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31472);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005EF4C:
    ctx->pc = 0x8005EF4Cu;
    // 8005EF4C: b       0x8005EF8C
    {
            goto label_8005EF8C;
    }

label_8005EF50:
    ctx->pc = 0x8005EF50u;
    ctx->downcount -= 17;
    // 8005EF50: lwz     r5, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005EF54:
    ctx->pc = 0x8005EF54u;
    // 8005EF54: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005EF58:
    ctx->pc = 0x8005EF58u;
    // 8005EF58: addi    r4, r9, -21636
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(-21636);

label_8005EF5C:
    ctx->pc = 0x8005EF5Cu;
    // 8005EF5C: lhz     r6, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_8005EF60:
    ctx->pc = 0x8005EF60u;
    // 8005EF60: lwz     r9, 592(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EF64:
    ctx->pc = 0x8005EF64u;
    // 8005EF64: addi    r11, r5, 552
    ctx->gpr[11] = ctx->gpr[5] + (u32)(s32)(552);

label_8005EF68:
    ctx->pc = 0x8005EF68u;
    // 8005EF68: addi    r10, r5, 512
    ctx->gpr[10] = ctx->gpr[5] + (u32)(s32)(512);

label_8005EF6C:
    ctx->pc = 0x8005EF6Cu;
    // 8005EF6C: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_8005EF70:
    ctx->pc = 0x8005EF70u;
    // 8005EF70: addi    r9, r9, -2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2);

label_8005EF74:
    ctx->pc = 0x8005EF74u;
    // 8005EF74: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8005EF78:
    ctx->pc = 0x8005EF78u;
    // 8005EF78: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EF7C:
    ctx->pc = 0x8005EF7Cu;
    // 8005EF7C: lwzx    r8, r10, r9
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[9];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005EF80:
    ctx->pc = 0x8005EF80u;
    // 8005EF80: sth     r6, 660(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(660);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_8005EF84:
    ctx->pc = 0x8005EF84u;
    // 8005EF84: mulli   r0, r0, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_8005EF88:
    ctx->pc = 0x8005EF88u;
    // 8005EF88: stw     r7, -31472(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31472);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005EF8C:
    ctx->pc = 0x8005EF8Cu;
    ctx->downcount -= 4;
    // 8005EF8C: lwz     r9, 596(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(596);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005EF90:
    ctx->pc = 0x8005EF90u;
    // 8005EF90: add   r8, r8, r0
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8005EF94:
    ctx->pc = 0x8005EF94u;
    // 8005EF94: cmpwi   r9, -1
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005EF98:
    ctx->pc = 0x8005EF98u;
    // 8005EF98: bc    12, 2, 0x8005EFA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005EFA4;
        }
    }

label_8005EF9C:
    ctx->pc = 0x8005EF9Cu;
    ctx->downcount -= 2;
    // 8005EF9C: lhz     r0, 598(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(598);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005EFA0:
    ctx->pc = 0x8005EFA0u;
    // 8005EFA0: sth     r0, 38(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(38);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8005EFA4:
    ctx->pc = 0x8005EFA4u;
    ctx->downcount -= 1;
    // 8005EFA4: lhz     r3, 14(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(14);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8005EFA8:
    ctx->pc = 0x8005EFA8u;
    ctx->downcount -= 1;
    // 8005EFA8: bl      0x8005B784
    {
            ctx->lr = 0x8005EFACu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005B784u;
                return;
            }
            goto label_8005B784;
    }

label_8005EFAC:
    ctx->pc = 0x8005EFACu;
    ctx->downcount -= 2;
    // 8005EFAC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005EFB0:
    ctx->pc = 0x8005EFB0u;
    // 8005EFB0: b       0x8005EFB8
    {
            goto label_8005EFB8;
    }

label_8005EFB4:
    ctx->pc = 0x8005EFB4u;
    ctx->downcount -= 1;
    // 8005EFB4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005EFB8:
    ctx->pc = 0x8005EFB8u;
    ctx->downcount -= 16;
    // 8005EFB8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005EFBC:
    ctx->pc = 0x8005EFBCu;
    // 8005EFBC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005EFC0:
    ctx->pc = 0x8005EFC0u;
    // 8005EFC0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005EFC4:
    ctx->pc = 0x8005EFC4u;
    // 8005EFC4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8005EFC8:
    ctx->pc = 0x8005EFC8u;
    // 8005EFC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005B2C0;
        }
    }

label_8005EFCC:
    ctx->pc = 0x8005EFCCu;
    ctx->downcount -= 20;
    // 8005EFCC: stwu     r1, -1080(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-1080);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005EFD0:
    ctx->pc = 0x8005EFD0u;
    // 8005EFD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005EFD4:
    ctx->pc = 0x8005EFD4u;
    // 8005EFD4: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_8005EFD8:
    ctx->pc = 0x8005EFD8u;
    // 8005EFD8: stmw     r15, 1012(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1012);
        for (u32 r = 15; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005EFDC:
    ctx->pc = 0x8005EFDCu;
    // 8005EFDC: stw     r0, 1084(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1084);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005EFE0:
    ctx->pc = 0x8005EFE0u;
    // 8005EFE0: stw     r12, 1008(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1008);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_8005EFE4:
    ctx->pc = 0x8005EFE4u;
    // 8005EFE4: lwz     r26, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_8005EFE8:
    ctx->pc = 0x8005EFE8u;
    // 8005EFE8: or   r23, r3, r3
    {
        ctx->gpr[23] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005EFEC:
    ctx->pc = 0x8005EFECu;
    // 8005EFEC: cmpwi   r26, 0
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

label_8005EFF0:
    ctx->pc = 0x8005EFF0u;
    // 8005EFF0: bc    12, 2, 0x8005F3A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8005F3A4u;
            return;
        }
    }

label_8005EFF4:
    ctx->pc = 0x8005EFF4u;
    ctx->downcount -= 11;
    // 8005EFF4: lwz     r10, 592(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(592);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005EFF8:
    ctx->pc = 0x8005EFF8u;
    // 8005EFF8: addi    r11, r26, 512
    ctx->gpr[11] = ctx->gpr[26] + (u32)(s32)(512);

label_8005EFFC:
    ctx->pc = 0x8005EFFCu;
    // 8005EFFC: addi    r9, r26, 552
    ctx->gpr[9] = ctx->gpr[26] + (u32)(s32)(552);

label_8005F000:
    ctx->pc = 0x8005F000u;
    // 8005F000: li      r16, 0
    ctx->gpr[16] = (u32)(s32)(0);

label_8005F004:
    ctx->pc = 0x8005F004u;
    // 8005F004: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_8005F008:
    ctx->pc = 0x8005F008u;
    // 8005F008: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_8005F00C:
    ctx->pc = 0x8005F00Cu;
    // 8005F00C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8005F010:
    ctx->pc = 0x8005F010u;
    // 8005F010: cmpwi   r10, 1
    {
        s32 val_a = (s32)(ctx->gpr[10]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005F014:
    ctx->pc = 0x8005F014u;
    // 8005F014: lwzx    r22, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[22] = mem_read32(ctx, ea);
    }

label_8005F018:
    ctx->pc = 0x8005F018u;
    // 8005F018: lwzx    r20, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[20] = mem_read32(ctx, ea);
    }

label_8005F01C:
    ctx->pc = 0x8005F01Cu;
    // 8005F01C: bc    4, 1, 0x8005F02C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F02C;
        }
    }

label_8005F020:
    ctx->pc = 0x8005F020u;
    ctx->downcount -= 3;
    // 8005F020: addi    r0, r10, -2
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-2);

label_8005F024:
    ctx->pc = 0x8005F024u;
    // 8005F024: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8005F028:
    ctx->pc = 0x8005F028u;
    // 8005F028: lwzx    r16, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[16] = mem_read32(ctx, ea);
    }

label_8005F02C:
    ctx->pc = 0x8005F02Cu;
    ctx->downcount -= 3;
    // 8005F02C: or   r3, r20, r20
    {
        ctx->gpr[3] = ctx->gpr[20] | ctx->gpr[20];
    }

label_8005F030:
    ctx->pc = 0x8005F030u;
    // 8005F030: li      r27, 160
    ctx->gpr[27] = (u32)(s32)(160);

label_8005F034:
    ctx->pc = 0x8005F034u;
    // 8005F034: bl      0x8005F3F4
    {
            ctx->lr = 0x8005F038u;
            ctx->pc = 0x8005F3F4u;
            return;
    }

label_8005F038:
    ctx->pc = 0x8005F038u;
    ctx->downcount -= 6;
    // 8005F038: mulli   r15, r22, 20
    ctx->gpr[15] = (u32)((s64)(s32)ctx->gpr[22] * (s64)(s32)20);

label_8005F03C:
    ctx->pc = 0x8005F03Cu;
    // 8005F03C: or.   r19, r3, r3
    {
        ctx->gpr[19] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[19];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005F040:
    ctx->pc = 0x8005F040u;
    // 8005F040: cmpwi   cr4, r16, 0
    {
        s32 val_a = (s32)(ctx->gpr[16]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_8005F044:
    ctx->pc = 0x8005F044u;
    // 8005F044: bc    4, 1, 0x8005F088
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F088;
        }
    }

label_8005F048:
    ctx->pc = 0x8005F048u;
    ctx->downcount -= 3;
    // 8005F048: addi    r29, r1, 808
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(808);

label_8005F04C:
    ctx->pc = 0x8005F04Cu;
    // 8005F04C: or   r30, r20, r20
    {
        ctx->gpr[30] = ctx->gpr[20] | ctx->gpr[20];
    }

label_8005F050:
    ctx->pc = 0x8005F050u;
    // 8005F050: or   r31, r19, r19
    {
        ctx->gpr[31] = ctx->gpr[19] | ctx->gpr[19];
    }

label_8005F054:
    ctx->pc = 0x8005F054u;
    ctx->downcount -= 4;
    // 8005F054: lwz     r4, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005F058:
    // 8005F058: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F05C:
    // 8005F05C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F060:
    // 8005F060: bl      0x80046DA4
    {
            ctx->lr = 0x8005F064u;
            ctx->pc = 0x80046DA4u;
            return;
    }

label_8005F064:
    ctx->downcount -= 4;
    // 8005F064: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F068:
    // 8005F068: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F06C:
    // 8005F06C: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8005F070:
    // 8005F070: bl      0x80035A54
    {
            ctx->lr = 0x8005F074u;
            ctx->pc = 0x80035A54u;
            return;
    }

label_8005F074:
    ctx->downcount -= 2;
    // 8005F074: cmpw    r3, r25
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[25]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005F078:
    // 8005F078: bc    4, 1, 0x8005F080
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F080;
        }
    }

label_8005F07C:
    ctx->downcount -= 1;
    // 8005F07C: or   r25, r3, r3
    {
        ctx->gpr[25] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005F080:
    ctx->downcount -= 2;
    // 8005F080: addic.  r31, r31, -1
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

label_8005F084:
    // 8005F084: bc    4, 2, 0x8005F054
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F054u;
                return;
            }
            goto label_8005F054;
        }
    }

label_8005F088:
    ctx->pc = 0x8005F088u;
    ctx->downcount -= 18;
    // 8005F088: addi    r28, r25, 100
    ctx->gpr[28] = ctx->gpr[25] + (u32)(s32)(100);

label_8005F08C:
    ctx->pc = 0x8005F08Cu;
    // 8005F08C: subfic  r0, r27, 480
    {
        u64 res = (u64)(u32)(s32)(480) + (u64)(~ctx->gpr[27]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8005F090:
    ctx->pc = 0x8005F090u;
    // 8005F090: subfic  r30, r28, 640
    {
        u64 res = (u64)(u32)(s32)(640) + (u64)(~ctx->gpr[28]) + 1u;
        ctx->gpr[30] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8005F094:
    ctx->pc = 0x8005F094u;
    // 8005F094: srawi r24, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[24] = value;
        } else if (sh > 31) {
            ctx->gpr[24] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[24] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8005F098:
    ctx->pc = 0x8005F098u;
    // 8005F098: rlwinm r9, r30, 1, 31, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[30], 1u) & 0x00000001u;
    }

label_8005F09C:
    ctx->pc = 0x8005F09Cu;
    // 8005F09C: add   r24, r24, r23
    {
        u32 a = ctx->gpr[24];
        u32 b = ctx->gpr[23];
        u32 res = a + b;
        ctx->gpr[24] = res;
    }

label_8005F0A0:
    ctx->pc = 0x8005F0A0u;
    // 8005F0A0: add   r30, r30, r9
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8005F0A4:
    ctx->pc = 0x8005F0A4u;
    // 8005F0A4: add   r23, r24, r27
    {
        u32 a = ctx->gpr[24];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[23] = res;
    }

label_8005F0A8:
    ctx->pc = 0x8005F0A8u;
    // 8005F0A8: srawi r30, r30, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[30];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[30] = value;
        } else if (sh > 31) {
            ctx->gpr[30] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[30] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8005F0AC:
    ctx->pc = 0x8005F0ACu;
    // 8005F0AC: add   r29, r30, r28
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[29] = res;
    }

label_8005F0B0:
    ctx->pc = 0x8005F0B0u;
    // 8005F0B0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8005F0B4:
    ctx->pc = 0x8005F0B4u;
    // 8005F0B4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005F0B8:
    ctx->pc = 0x8005F0B8u;
    // 8005F0B8: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8005F0BC:
    ctx->pc = 0x8005F0BCu;
    // 8005F0BC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F0C0:
    ctx->pc = 0x8005F0C0u;
    // 8005F0C0: or   r6, r23, r23
    {
        ctx->gpr[6] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8005F0C4:
    ctx->pc = 0x8005F0C4u;
    // 8005F0C4: lis     r7, -32768
    ctx->gpr[7] = ((u32)(s32)(-32768) << 16);

label_8005F0C8:
    ctx->pc = 0x8005F0C8u;
    // 8005F0C8: addi    r27, r24, 10
    ctx->gpr[27] = ctx->gpr[24] + (u32)(s32)(10);

label_8005F0CC:
    ctx->pc = 0x8005F0CCu;
    // 8005F0CC: bl      0x80003700
    {
            ctx->lr = 0x8005F0D0u;
            ctx->pc = 0x80003700u;
            return;
    }

label_8005F0D0:
    ctx->pc = 0x8005F0D0u;
    ctx->downcount -= 7;
    // 8005F0D0: lis     r7, -128
    ctx->gpr[7] = ((u32)(s32)(-128) << 16);

label_8005F0D4:
    ctx->pc = 0x8005F0D4u;
    // 8005F0D4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005F0D8:
    ctx->pc = 0x8005F0D8u;
    // 8005F0D8: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8005F0DC:
    ctx->pc = 0x8005F0DCu;
    // 8005F0DC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F0E0:
    ctx->pc = 0x8005F0E0u;
    // 8005F0E0: or   r6, r24, r24
    {
        ctx->gpr[6] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8005F0E4:
    ctx->pc = 0x8005F0E4u;
    // 8005F0E4: ori     r7, r7, 0x8080
    ctx->gpr[7] = ctx->gpr[7] | 0x8080u;

label_8005F0E8:
    ctx->pc = 0x8005F0E8u;
    // 8005F0E8: bl      0x80003698
    {
            ctx->lr = 0x8005F0ECu;
            ctx->pc = 0x80003698u;
            return;
    }

label_8005F0EC:
    ctx->pc = 0x8005F0ECu;
    ctx->downcount -= 8;
    // 8005F0EC: li      r31, -3
    ctx->gpr[31] = (u32)(s32)(-3);

label_8005F0F0:
    ctx->pc = 0x8005F0F0u;
    // 8005F0F0: lis     r7, -128
    ctx->gpr[7] = ((u32)(s32)(-128) << 16);

label_8005F0F4:
    ctx->pc = 0x8005F0F4u;
    // 8005F0F4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F0F8:
    ctx->pc = 0x8005F0F8u;
    // 8005F0F8: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8005F0FC:
    ctx->pc = 0x8005F0FCu;
    // 8005F0FC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F100:
    ctx->pc = 0x8005F100u;
    // 8005F100: or   r6, r23, r23
    {
        ctx->gpr[6] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8005F104:
    ctx->pc = 0x8005F104u;
    // 8005F104: ori     r7, r7, 0x8080
    ctx->gpr[7] = ctx->gpr[7] | 0x8080u;

label_8005F108:
    ctx->pc = 0x8005F108u;
    // 8005F108: bl      0x80003698
    {
            ctx->lr = 0x8005F10Cu;
            ctx->pc = 0x80003698u;
            return;
    }

label_8005F10C:
    ctx->pc = 0x8005F10Cu;
    ctx->downcount -= 7;
    // 8005F10C: lis     r7, -128
    ctx->gpr[7] = ((u32)(s32)(-128) << 16);

label_8005F110:
    ctx->pc = 0x8005F110u;
    // 8005F110: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F114:
    ctx->pc = 0x8005F114u;
    // 8005F114: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005F118:
    ctx->pc = 0x8005F118u;
    // 8005F118: or   r4, r23, r23
    {
        ctx->gpr[4] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8005F11C:
    ctx->pc = 0x8005F11Cu;
    // 8005F11C: or   r6, r23, r23
    {
        ctx->gpr[6] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8005F120:
    ctx->pc = 0x8005F120u;
    // 8005F120: ori     r7, r7, 0x8080
    ctx->gpr[7] = ctx->gpr[7] | 0x8080u;

label_8005F124:
    ctx->pc = 0x8005F124u;
    // 8005F124: bl      0x80003698
    {
            ctx->lr = 0x8005F128u;
            ctx->pc = 0x80003698u;
            return;
    }

label_8005F128:
    ctx->pc = 0x8005F128u;
    ctx->downcount -= 7;
    // 8005F128: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005F12C:
    ctx->pc = 0x8005F12Cu;
    // 8005F12C: lis     r7, -128
    ctx->gpr[7] = ((u32)(s32)(-128) << 16);

label_8005F130:
    ctx->pc = 0x8005F130u;
    // 8005F130: or   r5, r3, r3
    {
        ctx->gpr[5] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005F134:
    ctx->pc = 0x8005F134u;
    // 8005F134: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_8005F138:
    ctx->pc = 0x8005F138u;
    // 8005F138: or   r6, r23, r23
    {
        ctx->gpr[6] = ctx->gpr[23] | ctx->gpr[23];
    }

label_8005F13C:
    ctx->pc = 0x8005F13Cu;
    // 8005F13C: ori     r7, r7, 0x8080
    ctx->gpr[7] = ctx->gpr[7] | 0x8080u;

label_8005F140:
    ctx->pc = 0x8005F140u;
    // 8005F140: bl      0x80003698
    {
            ctx->lr = 0x8005F144u;
            ctx->pc = 0x80003698u;
            return;
    }

label_8005F144:
    ctx->pc = 0x8005F144u;
    ctx->downcount -= 3;
    // 8005F144: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F148:
    ctx->pc = 0x8005F148u;
    // 8005F148: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005F14C:
    ctx->pc = 0x8005F14Cu;
    // 8005F14C: bl      0x800353D4
    {
            ctx->lr = 0x8005F150u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_8005F150:
    ctx->pc = 0x8005F150u;
    ctx->downcount -= 12;
    // 8005F150: mulli   r11, r22, 20
    ctx->gpr[11] = (u32)((s64)(s32)ctx->gpr[22] * (s64)(s32)20);

label_8005F154:
    ctx->pc = 0x8005F154u;
    // 8005F154: rlwinm r9, r28, 1, 31, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[28], 1u) & 0x00000001u;
    }

label_8005F158:
    ctx->pc = 0x8005F158u;
    // 8005F158: add   r28, r28, r9
    {
        u32 a = ctx->gpr[28];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[28] = res;
    }

label_8005F15C:
    ctx->pc = 0x8005F15Cu;
    // 8005F15C: rlwinm r0, r25, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[25], 1u) & 0x00000001u;
    }

label_8005F160:
    ctx->pc = 0x8005F160u;
    // 8005F160: srawi r18, r28, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[28];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[18] = value;
        } else if (sh > 31) {
            ctx->gpr[18] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[18] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8005F164:
    ctx->pc = 0x8005F164u;
    // 8005F164: add   r0, r25, r0
    {
        u32 a = ctx->gpr[25];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8005F168:
    ctx->pc = 0x8005F168u;
    // 8005F168: add   r9, r11, r20
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[20];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_8005F16C:
    ctx->pc = 0x8005F16Cu;
    // 8005F16C: srawi r17, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[17] = value;
        } else if (sh > 31) {
            ctx->gpr[17] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[17] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_8005F170:
    ctx->pc = 0x8005F170u;
    // 8005F170: addi    r25, r11, -60
    ctx->gpr[25] = ctx->gpr[11] + (u32)(s32)(-60);

label_8005F174:
    ctx->pc = 0x8005F174u;
    // 8005F174: addi    r28, r9, -60
    ctx->gpr[28] = ctx->gpr[9] + (u32)(s32)(-60);

label_8005F178:
    ctx->downcount -= 2;
    // 8005F178: add.   r3, r22, r31
    {
        u32 a = ctx->gpr[22];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[3] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8005F17C:
    // 8005F17C: bc    12, 0, 0x8005F290
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F290;
        }
    }

label_8005F180:
    ctx->downcount -= 2;
    // 8005F180: cmpw    r3, r19
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[19]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005F184:
    // 8005F184: bc    4, 0, 0x8005F290
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F290;
        }
    }

label_8005F188:
    ctx->downcount -= 1;
    // 8005F188: bl      0x8005F41C
    {
            ctx->lr = 0x8005F18Cu;
            ctx->pc = 0x8005F41Cu;
            return;
    }

label_8005F18C:
    ctx->downcount -= 7;
    // 8005F18C: or   r21, r27, r27
    {
        ctx->gpr[21] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8005F190:
    // 8005F190: cmpwi   r31, 0
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

label_8005F194:
    ctx->pc = 0x8005F194u;
    // 8005F194: lwzx    r4, r25, r20
    {
        u32 ea = ctx->gpr[25] + ctx->gpr[20];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005F198:
    // 8005F198: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005F19C:
    // 8005F19C: mfcr    r29
    ctx->gpr[29] = ctx->cr;

label_8005F1A0:
    // 8005F1A0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F1A4:
    // 8005F1A4: bl      0x80046DA4
    {
            ctx->lr = 0x8005F1A8u;
            ctx->pc = 0x80046DA4u;
            return;
    }

label_8005F1A8:
    ctx->downcount -= 4;
    // 8005F1A8: lis     r4, -128
    ctx->gpr[4] = ((u32)(s32)(-128) << 16);

label_8005F1AC:
    // 8005F1AC: mtcrf   0x80, r29
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[29] & 0xF0000000u);

label_8005F1B0:
    // 8005F1B0: ori     r4, r4, 0x8040
    ctx->gpr[4] = ctx->gpr[4] | 0x8040u;

label_8005F1B4:
    // 8005F1B4: bc    4, 2, 0x8005F1BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F1BC;
        }
    }

label_8005F1B8:
    ctx->downcount -= 1;
    // 8005F1B8: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005F1BC:
    ctx->downcount -= 2;
    // 8005F1BC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F1C0:
    // 8005F1C0: bl      0x80034BA8
    {
            ctx->lr = 0x8005F1C4u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005F1C4:
    ctx->downcount -= 3;
    // 8005F1C4: cmpwi   r30, 0
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

label_8005F1C8:
    // 8005F1C8: mfcr    r30
    ctx->gpr[30] = ctx->cr;

label_8005F1CC:
    // 8005F1CC: bc    4, 2, 0x8005F1E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F1E0;
        }
    }

label_8005F1D0:
    ctx->downcount -= 4;
    // 8005F1D0: lis     r4, -32513
    ctx->gpr[4] = ((u32)(s32)(-32513) << 16);

label_8005F1D4:
    // 8005F1D4: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F1D8:
    // 8005F1D8: ori     r4, r4, 0x4000
    ctx->gpr[4] = ctx->gpr[4] | 0x4000u;

label_8005F1DC:
    // 8005F1DC: bl      0x80034BA8
    {
            ctx->lr = 0x8005F1E0u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005F1E0:
    ctx->downcount -= 4;
    // 8005F1E0: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F1E4:
    // 8005F1E4: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8005F1E8:
    // 8005F1E8: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F1EC:
    // 8005F1EC: bl      0x80035A54
    {
            ctx->lr = 0x8005F1F0u;
            ctx->pc = 0x80035A54u;
            return;
    }

label_8005F1F0:
    ctx->downcount -= 8;
    // 8005F1F0: subfic  r4, r3, 640
    {
        u64 res = (u64)(u32)(s32)(640) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[4] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8005F1F4:
    // 8005F1F4: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8005F1F8:
    // 8005F1F8: rlwinm r0, r4, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0x00000001u;
    }

label_8005F1FC:
    // 8005F1FC: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F200:
    // 8005F200: add   r4, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_8005F204:
    // 8005F204: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F208:
    // 8005F208: srawi r4, r4, 1
    {
        u32 sh = 1u;
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

label_8005F20C:
    // 8005F20C: bl      0x80034E9C
    {
            ctx->lr = 0x8005F210u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8005F210:
    ctx->pc = 0x8005F210u;
    ctx->downcount -= 3;
    // 8005F210: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F214:
    // 8005F214: cmpwi   r0, 0
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

label_8005F218:
    // 8005F218: bc    12, 2, 0x8005F248
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F248;
        }
    }

label_8005F21C:
    ctx->downcount -= 2;
    // 8005F21C: mtcrf   0x80, r30
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[30] & 0xF0000000u);

label_8005F220:
    // 8005F220: bc    12, 2, 0x8005F248
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F248;
        }
    }

label_8005F224:
    ctx->downcount -= 4;
    // 8005F224: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_8005F228:
    // 8005F228: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F22C:
    // 8005F22C: addi    r4, r4, 30880
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(30880);

label_8005F230:
    // 8005F230: bl      0x80046DA4
    {
            ctx->lr = 0x8005F234u;
            ctx->pc = 0x80046DA4u;
            return;
    }

label_8005F234:
    ctx->downcount -= 5;
    // 8005F234: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F238:
    // 8005F238: addi    r4, r17, 330
    ctx->gpr[4] = ctx->gpr[17] + (u32)(s32)(330);

label_8005F23C:
    // 8005F23C: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8005F240:
    // 8005F240: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F244:
    // 8005F244: bl      0x80034E9C
    {
            ctx->lr = 0x8005F248u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8005F248:
    ctx->downcount -= 2;
    // 8005F248: mtcrf   0x80, r29
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[29] & 0xF0000000u);

label_8005F24C:
    // 8005F24C: bc    4, 2, 0x8005F290
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F290;
        }
    }

label_8005F250:
    ctx->pc = 0x8005F250u;
    ctx->downcount -= 4;
    // 8005F250: lwz     r9, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F254:
    ctx->pc = 0x8005F254u;
    // 8005F254: lwz     r0, 592(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(592);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F258:
    // 8005F258: cmpwi   r0, 1
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

label_8005F25C:
    // 8005F25C: bc    4, 1, 0x8005F290
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F290;
        }
    }

label_8005F260:
    ctx->downcount -= 4;
    // 8005F260: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_8005F264:
    // 8005F264: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F268:
    // 8005F268: addi    r4, r4, 30884
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(30884);

label_8005F26C:
    // 8005F26C: bl      0x80046DA4
    {
            ctx->lr = 0x8005F270u;
            ctx->pc = 0x80046DA4u;
            return;
    }

label_8005F270:
    ctx->downcount -= 3;
    // 8005F270: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F274:
    // 8005F274: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005F278:
    // 8005F278: bl      0x80034BA8
    {
            ctx->lr = 0x8005F27Cu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005F27C:
    ctx->downcount -= 5;
    // 8005F27C: or   r5, r21, r21
    {
        ctx->gpr[5] = ctx->gpr[21] | ctx->gpr[21];
    }

label_8005F280:
    // 8005F280: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F284:
    // 8005F284: subfic  r4, r18, 330
    {
        u64 res = (u64)(u32)(s32)(330) + (u64)(~ctx->gpr[18]) + 1u;
        ctx->gpr[4] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8005F288:
    // 8005F288: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F28C:
    // 8005F28C: bl      0x80034E9C
    {
            ctx->lr = 0x8005F290u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8005F290:
    ctx->downcount -= 6;
    // 8005F290: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_8005F294:
    // 8005F294: addi    r28, r28, 20
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(20);

label_8005F298:
    // 8005F298: addi    r25, r25, 20
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(20);

label_8005F29C:
    // 8005F29C: addi    r27, r27, 20
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(20);

label_8005F2A0:
    // 8005F2A0: cmpwi   r31, 3
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005F2A4:
    // 8005F2A4: bc    4, 1, 0x8005F178
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F178u;
                return;
            }
            goto label_8005F178;
        }
    }

label_8005F2A8:
    ctx->pc = 0x8005F2A8u;
    ctx->downcount -= 4;
    // 8005F2A8: add   r31, r15, r20
    {
        u32 a = ctx->gpr[15];
        u32 b = ctx->gpr[20];
        u32 res = a + b;
        ctx->gpr[31] = res;
    }

label_8005F2AC:
    ctx->pc = 0x8005F2ACu;
    // 8005F2AC: lwz     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F2B0:
    ctx->pc = 0x8005F2B0u;
    // 8005F2B0: cmpwi   r0, 0
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

label_8005F2B4:
    ctx->pc = 0x8005F2B4u;
    // 8005F2B4: bc    12, 2, 0x8005F324
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x8005F324u;
            return;
        }
    }

label_8005F2B8:
    ctx->pc = 0x8005F2B8u;
    ctx->downcount -= 2;
    // 8005F2B8: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_8005F2BC:
    ctx->pc = 0x8005F2BCu;
    // 8005F2BC: bl      0x8005F41C
    {
            ctx->lr = 0x8005F2C0u;
            ctx->pc = 0x8005F41Cu;
            return;
    }

    ctx->pc = 0x8005F2C0u;
    return;
return_dispatch_8005B2C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8005B300u: goto label_8005B300;
    case 0x8005B3B0u: goto label_8005B3B0;
    case 0x8005B4DCu: goto label_8005B4DC;
    case 0x8005B58Cu: goto label_8005B58C;
    case 0x8005B618u: goto label_8005B618;
    case 0x8005B61Cu: goto label_8005B61C;
    case 0x8005B630u: goto label_8005B630;
    case 0x8005B634u: goto label_8005B634;
    case 0x8005B638u: goto label_8005B638;
    case 0x8005B63Cu: goto label_8005B63C;
    case 0x8005B640u: goto label_8005B640;
    case 0x8005B644u: goto label_8005B644;
    case 0x8005B648u: goto label_8005B648;
    case 0x8005B64Cu: goto label_8005B64C;
    case 0x8005B650u: goto label_8005B650;
    case 0x8005B654u: goto label_8005B654;
    case 0x8005B664u: goto label_8005B664;
    case 0x8005B690u: goto label_8005B690;
    case 0x8005B694u: goto label_8005B694;
    case 0x8005B6C0u: goto label_8005B6C0;
    case 0x8005B6ECu: goto label_8005B6EC;
    case 0x8005B718u: goto label_8005B718;
    case 0x8005B728u: goto label_8005B728;
    case 0x8005B72Cu: goto label_8005B72C;
    case 0x8005B738u: goto label_8005B738;
    case 0x8005B76Cu: goto label_8005B76C;
    case 0x8005B770u: goto label_8005B770;
    case 0x8005B7ACu: goto label_8005B7AC;
    case 0x8005B7D0u: goto label_8005B7D0;
    case 0x8005B7F4u: goto label_8005B7F4;
    case 0x8005B84Cu: goto label_8005B84C;
    case 0x8005B878u: goto label_8005B878;
    case 0x8005B894u: goto label_8005B894;
    case 0x8005B8A0u: goto label_8005B8A0;
    case 0x8005BA00u: goto label_8005BA00;
    case 0x8005BA04u: goto label_8005BA04;
    case 0x8005BA0Cu: goto label_8005BA0C;
    case 0x8005BA14u: goto label_8005BA14;
    case 0x8005BA18u: goto label_8005BA18;
    case 0x8005BA20u: goto label_8005BA20;
    case 0x8005BA24u: goto label_8005BA24;
    case 0x8005BA3Cu: goto label_8005BA3C;
    case 0x8005BA48u: goto label_8005BA48;
    case 0x8005BA50u: goto label_8005BA50;
    case 0x8005BA54u: goto label_8005BA54;
    case 0x8005BA6Cu: goto label_8005BA6C;
    case 0x8005BA78u: goto label_8005BA78;
    case 0x8005BA94u: goto label_8005BA94;
    case 0x8005BA98u: goto label_8005BA98;
    case 0x8005BAA0u: goto label_8005BAA0;
    case 0x8005BAACu: goto label_8005BAAC;
    case 0x8005BAB0u: goto label_8005BAB0;
    case 0x8005BAB8u: goto label_8005BAB8;
    case 0x8005BABCu: goto label_8005BABC;
    case 0x8005BAC4u: goto label_8005BAC4;
    case 0x8005BAD0u: goto label_8005BAD0;
    case 0x8005BAE0u: goto label_8005BAE0;
    case 0x8005BB10u: goto label_8005BB10;
    case 0x8005BB20u: goto label_8005BB20;
    case 0x8005BB24u: goto label_8005BB24;
    case 0x8005BC08u: goto label_8005BC08;
    case 0x8005BC1Cu: goto label_8005BC1C;
    case 0x8005BC28u: goto label_8005BC28;
    case 0x8005BC38u: goto label_8005BC38;
    case 0x8005BC44u: goto label_8005BC44;
    case 0x8005BC54u: goto label_8005BC54;
    case 0x8005BC68u: goto label_8005BC68;
    case 0x8005BCD0u: goto label_8005BCD0;
    case 0x8005BD34u: goto label_8005BD34;
    case 0x8005BD88u: goto label_8005BD88;
    case 0x8005BD8Cu: goto label_8005BD8C;
    case 0x8005BDC4u: goto label_8005BDC4;
    case 0x8005BDC8u: goto label_8005BDC8;
    case 0x8005BE00u: goto label_8005BE00;
    case 0x8005BE10u: goto label_8005BE10;
    case 0x8005BE20u: goto label_8005BE20;
    case 0x8005BE5Cu: goto label_8005BE5C;
    case 0x8005BE70u: goto label_8005BE70;
    case 0x8005BE7Cu: goto label_8005BE7C;
    case 0x8005BE8Cu: goto label_8005BE8C;
    case 0x8005BE98u: goto label_8005BE98;
    case 0x8005BEA8u: goto label_8005BEA8;
    case 0x8005BEC0u: goto label_8005BEC0;
    case 0x8005BF30u: goto label_8005BF30;
    case 0x8005C0C8u: goto label_8005C0C8;
    case 0x8005C0D4u: goto label_8005C0D4;
    case 0x8005C0DCu: goto label_8005C0DC;
    case 0x8005C0E0u: goto label_8005C0E0;
    case 0x8005C0E8u: goto label_8005C0E8;
    case 0x8005C0F0u: goto label_8005C0F0;
    case 0x8005C10Cu: goto label_8005C10C;
    case 0x8005C114u: goto label_8005C114;
    case 0x8005C13Cu: goto label_8005C13C;
    case 0x8005C14Cu: goto label_8005C14C;
    case 0x8005C154u: goto label_8005C154;
    case 0x8005C184u: goto label_8005C184;
    case 0x8005C18Cu: goto label_8005C18C;
    case 0x8005C1BCu: goto label_8005C1BC;
    case 0x8005C1C0u: goto label_8005C1C0;
    case 0x8005C1CCu: goto label_8005C1CC;
    case 0x8005C1D0u: goto label_8005C1D0;
    case 0x8005C1D4u: goto label_8005C1D4;
    case 0x8005C1ECu: goto label_8005C1EC;
    case 0x8005C1F0u: goto label_8005C1F0;
    case 0x8005C208u: goto label_8005C208;
    case 0x8005C214u: goto label_8005C214;
    case 0x8005C218u: goto label_8005C218;
    case 0x8005C21Cu: goto label_8005C21C;
    case 0x8005C220u: goto label_8005C220;
    case 0x8005C228u: goto label_8005C228;
    case 0x8005C254u: goto label_8005C254;
    case 0x8005C264u: goto label_8005C264;
    case 0x8005C31Cu: goto label_8005C31C;
    case 0x8005C4B0u: goto label_8005C4B0;
    case 0x8005C4B4u: goto label_8005C4B4;
    case 0x8005C4B8u: goto label_8005C4B8;
    case 0x8005C4C0u: goto label_8005C4C0;
    case 0x8005C4C4u: goto label_8005C4C4;
    case 0x8005C4DCu: goto label_8005C4DC;
    case 0x8005C51Cu: goto label_8005C51C;
    case 0x8005C558u: goto label_8005C558;
    case 0x8005C620u: goto label_8005C620;
    case 0x8005CAA4u: goto label_8005CAA4;
    case 0x8005CB20u: goto label_8005CB20;
    case 0x8005CB38u: goto label_8005CB38;
    case 0x8005CB48u: goto label_8005CB48;
    case 0x8005CB9Cu: goto label_8005CB9C;
    case 0x8005CC8Cu: goto label_8005CC8C;
    case 0x8005CD2Cu: goto label_8005CD2C;
    case 0x8005CDF8u: goto label_8005CDF8;
    case 0x8005CE04u: goto label_8005CE04;
    case 0x8005CE88u: goto label_8005CE88;
    case 0x8005CE94u: goto label_8005CE94;
    case 0x8005CEACu: goto label_8005CEAC;
    case 0x8005CF68u: goto label_8005CF68;
    case 0x8005CFA0u: goto label_8005CFA0;
    case 0x8005CFB0u: goto label_8005CFB0;
    case 0x8005CFC4u: goto label_8005CFC4;
    case 0x8005CFD4u: goto label_8005CFD4;
    case 0x8005CFE0u: goto label_8005CFE0;
    case 0x8005D018u: goto label_8005D018;
    case 0x8005D02Cu: goto label_8005D02C;
    case 0x8005D09Cu: goto label_8005D09C;
    case 0x8005D10Cu: goto label_8005D10C;
    case 0x8005D130u: goto label_8005D130;
    case 0x8005D170u: goto label_8005D170;
    case 0x8005D1C0u: goto label_8005D1C0;
    case 0x8005D1D8u: goto label_8005D1D8;
    case 0x8005D1ECu: goto label_8005D1EC;
    case 0x8005D200u: goto label_8005D200;
    case 0x8005D218u: goto label_8005D218;
    case 0x8005D21Cu: goto label_8005D21C;
    case 0x8005D22Cu: goto label_8005D22C;
    case 0x8005D244u: goto label_8005D244;
    case 0x8005D260u: goto label_8005D260;
    case 0x8005D27Cu: goto label_8005D27C;
    case 0x8005D2A4u: goto label_8005D2A4;
    case 0x8005D2B8u: goto label_8005D2B8;
    case 0x8005D2CCu: goto label_8005D2CC;
    case 0x8005D2E4u: goto label_8005D2E4;
    case 0x8005D2F4u: goto label_8005D2F4;
    case 0x8005D318u: goto label_8005D318;
    case 0x8005D32Cu: goto label_8005D32C;
    case 0x8005D344u: goto label_8005D344;
    case 0x8005D358u: goto label_8005D358;
    case 0x8005D360u: goto label_8005D360;
    case 0x8005D3B4u: goto label_8005D3B4;
    case 0x8005D430u: goto label_8005D430;
    case 0x8005D478u: goto label_8005D478;
    case 0x8005D4A8u: goto label_8005D4A8;
    case 0x8005D4D4u: goto label_8005D4D4;
    case 0x8005D500u: goto label_8005D500;
    case 0x8005D52Cu: goto label_8005D52C;
    case 0x8005D568u: goto label_8005D568;
    case 0x8005D5BCu: goto label_8005D5BC;
    case 0x8005D5D4u: goto label_8005D5D4;
    case 0x8005D5E4u: goto label_8005D5E4;
    case 0x8005D5FCu: goto label_8005D5FC;
    case 0x8005D614u: goto label_8005D614;
    case 0x8005D64Cu: goto label_8005D64C;
    case 0x8005D67Cu: goto label_8005D67C;
    case 0x8005D68Cu: goto label_8005D68C;
    case 0x8005D6A4u: goto label_8005D6A4;
    case 0x8005D6F8u: goto label_8005D6F8;
    case 0x8005D708u: goto label_8005D708;
    case 0x8005D720u: goto label_8005D720;
    case 0x8005D790u: goto label_8005D790;
    case 0x8005D828u: goto label_8005D828;
    case 0x8005D838u: goto label_8005D838;
    case 0x8005D84Cu: goto label_8005D84C;
    case 0x8005D870u: goto label_8005D870;
    case 0x8005D880u: goto label_8005D880;
    case 0x8005D894u: goto label_8005D894;
    case 0x8005D8A0u: goto label_8005D8A0;
    case 0x8005D8F8u: goto label_8005D8F8;
    case 0x8005D918u: goto label_8005D918;
    case 0x8005D920u: goto label_8005D920;
    case 0x8005D980u: goto label_8005D980;
    case 0x8005D994u: goto label_8005D994;
    case 0x8005D9ACu: goto label_8005D9AC;
    case 0x8005D9C0u: goto label_8005D9C0;
    case 0x8005DA10u: goto label_8005DA10;
    case 0x8005DA20u: goto label_8005DA20;
    case 0x8005DA2Cu: goto label_8005DA2C;
    case 0x8005DAE4u: goto label_8005DAE4;
    case 0x8005DB04u: goto label_8005DB04;
    case 0x8005DB0Cu: goto label_8005DB0C;
    case 0x8005DB24u: goto label_8005DB24;
    case 0x8005DB3Cu: goto label_8005DB3C;
    case 0x8005DB54u: goto label_8005DB54;
    case 0x8005DB64u: goto label_8005DB64;
    case 0x8005DB7Cu: goto label_8005DB7C;
    case 0x8005DBA0u: goto label_8005DBA0;
    case 0x8005DBB8u: goto label_8005DBB8;
    case 0x8005DBCCu: goto label_8005DBCC;
    case 0x8005DBDCu: goto label_8005DBDC;
    case 0x8005DBE0u: goto label_8005DBE0;
    case 0x8005DBE8u: goto label_8005DBE8;
    case 0x8005DBECu: goto label_8005DBEC;
    case 0x8005DBF0u: goto label_8005DBF0;
    case 0x8005DC00u: goto label_8005DC00;
    case 0x8005DC18u: goto label_8005DC18;
    case 0x8005DC3Cu: goto label_8005DC3C;
    case 0x8005DC4Cu: goto label_8005DC4C;
    case 0x8005DC64u: goto label_8005DC64;
    case 0x8005DC70u: goto label_8005DC70;
    case 0x8005DC8Cu: goto label_8005DC8C;
    case 0x8005DCA8u: goto label_8005DCA8;
    case 0x8005DCBCu: goto label_8005DCBC;
    case 0x8005DCE0u: goto label_8005DCE0;
    case 0x8005DD0Cu: goto label_8005DD0C;
    case 0x8005DD6Cu: goto label_8005DD6C;
    case 0x8005DD9Cu: goto label_8005DD9C;
    case 0x8005DDB4u: goto label_8005DDB4;
    case 0x8005DDC4u: goto label_8005DDC4;
    case 0x8005DDCCu: goto label_8005DDCC;
    case 0x8005DDE4u: goto label_8005DDE4;
    case 0x8005DE58u: goto label_8005DE58;
    case 0x8005DEB4u: goto label_8005DEB4;
    case 0x8005DED8u: goto label_8005DED8;
    case 0x8005DF18u: goto label_8005DF18;
    case 0x8005DF80u: goto label_8005DF80;
    case 0x8005DFC0u: goto label_8005DFC0;
    case 0x8005E030u: goto label_8005E030;
    case 0x8005E048u: goto label_8005E048;
    case 0x8005E074u: goto label_8005E074;
    case 0x8005E08Cu: goto label_8005E08C;
    case 0x8005E0A0u: goto label_8005E0A0;
    case 0x8005E0B8u: goto label_8005E0B8;
    case 0x8005E0FCu: goto label_8005E0FC;
    case 0x8005E110u: goto label_8005E110;
    case 0x8005E124u: goto label_8005E124;
    case 0x8005E13Cu: goto label_8005E13C;
    case 0x8005E150u: goto label_8005E150;
    case 0x8005E164u: goto label_8005E164;
    case 0x8005E16Cu: goto label_8005E16C;
    case 0x8005E1A0u: goto label_8005E1A0;
    case 0x8005E1B8u: goto label_8005E1B8;
    case 0x8005E244u: goto label_8005E244;
    case 0x8005E27Cu: goto label_8005E27C;
    case 0x8005E2A4u: goto label_8005E2A4;
    case 0x8005E408u: goto label_8005E408;
    case 0x8005E434u: goto label_8005E434;
    case 0x8005E448u: goto label_8005E448;
    case 0x8005E45Cu: goto label_8005E45C;
    case 0x8005E480u: goto label_8005E480;
    case 0x8005E48Cu: goto label_8005E48C;
    case 0x8005E49Cu: goto label_8005E49C;
    case 0x8005E4B4u: goto label_8005E4B4;
    case 0x8005E4BCu: goto label_8005E4BC;
    case 0x8005E544u: goto label_8005E544;
    case 0x8005E558u: goto label_8005E558;
    case 0x8005E57Cu: goto label_8005E57C;
    case 0x8005E600u: goto label_8005E600;
    case 0x8005E628u: goto label_8005E628;
    case 0x8005E674u: goto label_8005E674;
    case 0x8005E6CCu: goto label_8005E6CC;
    case 0x8005E6F4u: goto label_8005E6F4;
    case 0x8005E704u: goto label_8005E704;
    case 0x8005E714u: goto label_8005E714;
    case 0x8005E744u: goto label_8005E744;
    case 0x8005E754u: goto label_8005E754;
    case 0x8005E764u: goto label_8005E764;
    case 0x8005E774u: goto label_8005E774;
    case 0x8005E788u: goto label_8005E788;
    case 0x8005E7A0u: goto label_8005E7A0;
    case 0x8005E7ECu: goto label_8005E7EC;
    case 0x8005E7FCu: goto label_8005E7FC;
    case 0x8005E808u: goto label_8005E808;
    case 0x8005E860u: goto label_8005E860;
    case 0x8005E8B4u: goto label_8005E8B4;
    case 0x8005E8C4u: goto label_8005E8C4;
    case 0x8005E8C8u: goto label_8005E8C8;
    case 0x8005E8F0u: goto label_8005E8F0;
    case 0x8005E900u: goto label_8005E900;
    case 0x8005E910u: goto label_8005E910;
    case 0x8005E964u: goto label_8005E964;
    case 0x8005E974u: goto label_8005E974;
    case 0x8005E984u: goto label_8005E984;
    case 0x8005E994u: goto label_8005E994;
    case 0x8005E9A4u: goto label_8005E9A4;
    case 0x8005EAD4u: goto label_8005EAD4;
    case 0x8005EAFCu: goto label_8005EAFC;
    case 0x8005EB20u: goto label_8005EB20;
    case 0x8005EB84u: goto label_8005EB84;
    case 0x8005EC4Cu: goto label_8005EC4C;
    case 0x8005EC60u: goto label_8005EC60;
    case 0x8005ECB4u: goto label_8005ECB4;
    case 0x8005ECC0u: goto label_8005ECC0;
    case 0x8005EFACu: goto label_8005EFAC;
    case 0x8005F038u: goto label_8005F038;
    case 0x8005F064u: goto label_8005F064;
    case 0x8005F074u: goto label_8005F074;
    case 0x8005F0D0u: goto label_8005F0D0;
    case 0x8005F0ECu: goto label_8005F0EC;
    case 0x8005F10Cu: goto label_8005F10C;
    case 0x8005F128u: goto label_8005F128;
    case 0x8005F144u: goto label_8005F144;
    case 0x8005F150u: goto label_8005F150;
    case 0x8005F18Cu: goto label_8005F18C;
    case 0x8005F1A8u: goto label_8005F1A8;
    case 0x8005F1C4u: goto label_8005F1C4;
    case 0x8005F1E0u: goto label_8005F1E0;
    case 0x8005F1F0u: goto label_8005F1F0;
    case 0x8005F210u: goto label_8005F210;
    case 0x8005F234u: goto label_8005F234;
    case 0x8005F248u: goto label_8005F248;
    case 0x8005F270u: goto label_8005F270;
    case 0x8005F27Cu: goto label_8005F27C;
    case 0x8005F290u: goto label_8005F290;
    default: return;
    }
}

