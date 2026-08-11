// DolRecomp output
#include "../generated.h"

static void loop_801D73FC(CPUState* ctx) {
label_801D73FC:
    ctx->downcount -= 5;
    ctx->pc = 0x801D73FCu;
    // 801D73FC: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D7400u;
    // 801D7400: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D7404u;
    // 801D7404: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D7408: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D740C: bc    16, 0, 0x801D73FC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D73FCu;
                return;
            }
            goto label_801D73FC;
        }
    }

    ctx->pc = 0x801D7410u;
}

static void loop_801D7E64(CPUState* ctx) {
label_801D7E64:
    ctx->downcount -= 5;
    ctx->pc = 0x801D7E64u;
    // 801D7E64: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D7E68u;
    // 801D7E68: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D7E6Cu;
    // 801D7E6C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D7E70: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D7E74: bc    16, 0, 0x801D7E64
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7E64u;
                return;
            }
            goto label_801D7E64;
        }
    }

    ctx->pc = 0x801D7E78u;
}

static void loop_801D81B8(CPUState* ctx) {
label_801D81B8:
    ctx->downcount -= 5;
    ctx->pc = 0x801D81B8u;
    // 801D81B8: stw     r10, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

    ctx->pc = 0x801D81BCu;
    // 801D81BC: stw     r10, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

    ctx->pc = 0x801D81C0u;
    // 801D81C0: stw     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

    // 801D81C4: addi    r11, r11, 12
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(12);

    // 801D81C8: bc    16, 0, 0x801D81B8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D81B8u;
                return;
            }
            goto label_801D81B8;
        }
    }

    ctx->pc = 0x801D81CCu;
}

static void loop_801D831C(CPUState* ctx) {
label_801D831C:
    ctx->downcount -= 5;
    ctx->pc = 0x801D831Cu;
    // 801D831C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D8320u;
    // 801D8320: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D8324u;
    // 801D8324: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D8328: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D832C: bc    16, 0, 0x801D831C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D831Cu;
                return;
            }
            goto label_801D831C;
        }
    }

    ctx->pc = 0x801D8330u;
}

static void loop_801D8858(CPUState* ctx) {
label_801D8858:
    ctx->downcount -= 5;
    ctx->pc = 0x801D8858u;
    // 801D8858: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D885Cu;
    // 801D885C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D8860u;
    // 801D8860: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D8864: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D8868: bc    16, 0, 0x801D8858
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8858u;
                return;
            }
            goto label_801D8858;
        }
    }

    ctx->pc = 0x801D886Cu;
}

static void loop_801D8D14(CPUState* ctx) {
label_801D8D14:
    ctx->downcount -= 5;
    ctx->pc = 0x801D8D14u;
    // 801D8D14: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D8D18u;
    // 801D8D18: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D8D1Cu;
    // 801D8D1C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D8D20: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D8D24: bc    16, 0, 0x801D8D14
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8D14u;
                return;
            }
            goto label_801D8D14;
        }
    }

    ctx->pc = 0x801D8D28u;
}

static void loop_801D9124(CPUState* ctx) {
label_801D9124:
    ctx->downcount -= 5;
    ctx->pc = 0x801D9124u;
    // 801D9124: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D9128u;
    // 801D9128: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D912Cu;
    // 801D912C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D9130: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D9134: bc    16, 0, 0x801D9124
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9124u;
                return;
            }
            goto label_801D9124;
        }
    }

    ctx->pc = 0x801D9138u;
}

static void loop_801D945C(CPUState* ctx) {
label_801D945C:
    ctx->downcount -= 5;
    ctx->pc = 0x801D945Cu;
    // 801D945C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D9460u;
    // 801D9460: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D9464u;
    // 801D9464: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D9468: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D946C: bc    16, 0, 0x801D945C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D945Cu;
                return;
            }
            goto label_801D945C;
        }
    }

    ctx->pc = 0x801D9470u;
}

static void loop_801D9700(CPUState* ctx) {
label_801D9700:
    ctx->downcount -= 5;
    ctx->pc = 0x801D9700u;
    // 801D9700: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D9704u;
    // 801D9704: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    ctx->pc = 0x801D9708u;
    // 801D9708: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 801D970C: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

    // 801D9710: bc    16, 0, 0x801D9700
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9700u;
                return;
            }
            goto label_801D9700;
        }
    }

    ctx->pc = 0x801D9714u;
}

void func_801D72C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x801D72C0u: goto label_801D72C0;
    case 0x801D72C4u: goto label_801D72C4;
    case 0x801D72C8u: goto label_801D72C8;
    case 0x801D72CCu: goto label_801D72CC;
    case 0x801D72D0u: goto label_801D72D0;
    case 0x801D72D4u: goto label_801D72D4;
    case 0x801D72D8u: goto label_801D72D8;
    case 0x801D72DCu: goto label_801D72DC;
    case 0x801D72E0u: goto label_801D72E0;
    case 0x801D72E4u: goto label_801D72E4;
    case 0x801D72E8u: goto label_801D72E8;
    case 0x801D72ECu: goto label_801D72EC;
    case 0x801D72F0u: goto label_801D72F0;
    case 0x801D72F4u: goto label_801D72F4;
    case 0x801D72F8u: goto label_801D72F8;
    case 0x801D72FCu: goto label_801D72FC;
    case 0x801D7300u: goto label_801D7300;
    case 0x801D7304u: goto label_801D7304;
    case 0x801D7308u: goto label_801D7308;
    case 0x801D730Cu: goto label_801D730C;
    case 0x801D7310u: goto label_801D7310;
    case 0x801D7314u: goto label_801D7314;
    case 0x801D7318u: goto label_801D7318;
    case 0x801D731Cu: goto label_801D731C;
    case 0x801D7320u: goto label_801D7320;
    case 0x801D7324u: goto label_801D7324;
    case 0x801D7328u: goto label_801D7328;
    case 0x801D732Cu: goto label_801D732C;
    case 0x801D7330u: goto label_801D7330;
    case 0x801D7334u: goto label_801D7334;
    case 0x801D7338u: goto label_801D7338;
    case 0x801D733Cu: goto label_801D733C;
    case 0x801D7340u: goto label_801D7340;
    case 0x801D7344u: goto label_801D7344;
    case 0x801D7348u: goto label_801D7348;
    case 0x801D734Cu: goto label_801D734C;
    case 0x801D7350u: goto label_801D7350;
    case 0x801D7354u: goto label_801D7354;
    case 0x801D7358u: goto label_801D7358;
    case 0x801D735Cu: goto label_801D735C;
    case 0x801D7360u: goto label_801D7360;
    case 0x801D7364u: goto label_801D7364;
    case 0x801D7368u: goto label_801D7368;
    case 0x801D736Cu: goto label_801D736C;
    case 0x801D7370u: goto label_801D7370;
    case 0x801D7374u: goto label_801D7374;
    case 0x801D7378u: goto label_801D7378;
    case 0x801D737Cu: goto label_801D737C;
    case 0x801D7380u: goto label_801D7380;
    case 0x801D7384u: goto label_801D7384;
    case 0x801D7388u: goto label_801D7388;
    case 0x801D738Cu: goto label_801D738C;
    case 0x801D7390u: goto label_801D7390;
    case 0x801D7394u: goto label_801D7394;
    case 0x801D7398u: goto label_801D7398;
    case 0x801D739Cu: goto label_801D739C;
    case 0x801D73A0u: goto label_801D73A0;
    case 0x801D73A4u: goto label_801D73A4;
    case 0x801D73A8u: goto label_801D73A8;
    case 0x801D73ACu: goto label_801D73AC;
    case 0x801D73B0u: goto label_801D73B0;
    case 0x801D73B4u: goto label_801D73B4;
    case 0x801D73B8u: goto label_801D73B8;
    case 0x801D73BCu: goto label_801D73BC;
    case 0x801D73C0u: goto label_801D73C0;
    case 0x801D73C4u: goto label_801D73C4;
    case 0x801D73C8u: goto label_801D73C8;
    case 0x801D73CCu: goto label_801D73CC;
    case 0x801D73D0u: goto label_801D73D0;
    case 0x801D73D4u: goto label_801D73D4;
    case 0x801D73D8u: goto label_801D73D8;
    case 0x801D73DCu: goto label_801D73DC;
    case 0x801D73E0u: goto label_801D73E0;
    case 0x801D73E4u: goto label_801D73E4;
    case 0x801D73E8u: goto label_801D73E8;
    case 0x801D73ECu: goto label_801D73EC;
    case 0x801D73F0u: goto label_801D73F0;
    case 0x801D73F4u: goto label_801D73F4;
    case 0x801D73F8u: goto label_801D73F8;
    case 0x801D73FCu: goto label_801D73FC;
    case 0x801D7400u: goto label_801D7400;
    case 0x801D7404u: goto label_801D7404;
    case 0x801D7408u: goto label_801D7408;
    case 0x801D740Cu: goto label_801D740C;
    case 0x801D7410u: goto label_801D7410;
    case 0x801D7414u: goto label_801D7414;
    case 0x801D7418u: goto label_801D7418;
    case 0x801D741Cu: goto label_801D741C;
    case 0x801D7420u: goto label_801D7420;
    case 0x801D7424u: goto label_801D7424;
    case 0x801D7428u: goto label_801D7428;
    case 0x801D742Cu: goto label_801D742C;
    case 0x801D7430u: goto label_801D7430;
    case 0x801D7434u: goto label_801D7434;
    case 0x801D7438u: goto label_801D7438;
    case 0x801D743Cu: goto label_801D743C;
    case 0x801D7440u: goto label_801D7440;
    case 0x801D7444u: goto label_801D7444;
    case 0x801D7448u: goto label_801D7448;
    case 0x801D744Cu: goto label_801D744C;
    case 0x801D7450u: goto label_801D7450;
    case 0x801D7454u: goto label_801D7454;
    case 0x801D7458u: goto label_801D7458;
    case 0x801D745Cu: goto label_801D745C;
    case 0x801D7460u: goto label_801D7460;
    case 0x801D7464u: goto label_801D7464;
    case 0x801D7468u: goto label_801D7468;
    case 0x801D746Cu: goto label_801D746C;
    case 0x801D7470u: goto label_801D7470;
    case 0x801D7474u: goto label_801D7474;
    case 0x801D7478u: goto label_801D7478;
    case 0x801D747Cu: goto label_801D747C;
    case 0x801D7480u: goto label_801D7480;
    case 0x801D7484u: goto label_801D7484;
    case 0x801D7488u: goto label_801D7488;
    case 0x801D748Cu: goto label_801D748C;
    case 0x801D7490u: goto label_801D7490;
    case 0x801D7494u: goto label_801D7494;
    case 0x801D7498u: goto label_801D7498;
    case 0x801D749Cu: goto label_801D749C;
    case 0x801D74A0u: goto label_801D74A0;
    case 0x801D74A4u: goto label_801D74A4;
    case 0x801D74A8u: goto label_801D74A8;
    case 0x801D74ACu: goto label_801D74AC;
    case 0x801D74B0u: goto label_801D74B0;
    case 0x801D74B4u: goto label_801D74B4;
    case 0x801D74B8u: goto label_801D74B8;
    case 0x801D74BCu: goto label_801D74BC;
    case 0x801D74C0u: goto label_801D74C0;
    case 0x801D74C4u: goto label_801D74C4;
    case 0x801D74C8u: goto label_801D74C8;
    case 0x801D74CCu: goto label_801D74CC;
    case 0x801D74D0u: goto label_801D74D0;
    case 0x801D74D4u: goto label_801D74D4;
    case 0x801D74D8u: goto label_801D74D8;
    case 0x801D74DCu: goto label_801D74DC;
    case 0x801D74E0u: goto label_801D74E0;
    case 0x801D74E4u: goto label_801D74E4;
    case 0x801D74E8u: goto label_801D74E8;
    case 0x801D74ECu: goto label_801D74EC;
    case 0x801D74F0u: goto label_801D74F0;
    case 0x801D74F4u: goto label_801D74F4;
    case 0x801D74F8u: goto label_801D74F8;
    case 0x801D74FCu: goto label_801D74FC;
    case 0x801D7500u: goto label_801D7500;
    case 0x801D7504u: goto label_801D7504;
    case 0x801D7508u: goto label_801D7508;
    case 0x801D750Cu: goto label_801D750C;
    case 0x801D7510u: goto label_801D7510;
    case 0x801D7514u: goto label_801D7514;
    case 0x801D7518u: goto label_801D7518;
    case 0x801D751Cu: goto label_801D751C;
    case 0x801D7520u: goto label_801D7520;
    case 0x801D7524u: goto label_801D7524;
    case 0x801D7528u: goto label_801D7528;
    case 0x801D752Cu: goto label_801D752C;
    case 0x801D7530u: goto label_801D7530;
    case 0x801D7534u: goto label_801D7534;
    case 0x801D7538u: goto label_801D7538;
    case 0x801D753Cu: goto label_801D753C;
    case 0x801D7540u: goto label_801D7540;
    case 0x801D7544u: goto label_801D7544;
    case 0x801D7548u: goto label_801D7548;
    case 0x801D754Cu: goto label_801D754C;
    case 0x801D7550u: goto label_801D7550;
    case 0x801D7554u: goto label_801D7554;
    case 0x801D7558u: goto label_801D7558;
    case 0x801D755Cu: goto label_801D755C;
    case 0x801D7560u: goto label_801D7560;
    case 0x801D7564u: goto label_801D7564;
    case 0x801D7568u: goto label_801D7568;
    case 0x801D756Cu: goto label_801D756C;
    case 0x801D7570u: goto label_801D7570;
    case 0x801D7574u: goto label_801D7574;
    case 0x801D7578u: goto label_801D7578;
    case 0x801D757Cu: goto label_801D757C;
    case 0x801D7580u: goto label_801D7580;
    case 0x801D7584u: goto label_801D7584;
    case 0x801D7588u: goto label_801D7588;
    case 0x801D758Cu: goto label_801D758C;
    case 0x801D7590u: goto label_801D7590;
    case 0x801D7594u: goto label_801D7594;
    case 0x801D7598u: goto label_801D7598;
    case 0x801D759Cu: goto label_801D759C;
    case 0x801D75A0u: goto label_801D75A0;
    case 0x801D75A4u: goto label_801D75A4;
    case 0x801D75A8u: goto label_801D75A8;
    case 0x801D75ACu: goto label_801D75AC;
    case 0x801D75B0u: goto label_801D75B0;
    case 0x801D75B4u: goto label_801D75B4;
    case 0x801D75B8u: goto label_801D75B8;
    case 0x801D75BCu: goto label_801D75BC;
    case 0x801D75C0u: goto label_801D75C0;
    case 0x801D75C4u: goto label_801D75C4;
    case 0x801D75C8u: goto label_801D75C8;
    case 0x801D75CCu: goto label_801D75CC;
    case 0x801D75D0u: goto label_801D75D0;
    case 0x801D75D4u: goto label_801D75D4;
    case 0x801D75D8u: goto label_801D75D8;
    case 0x801D75DCu: goto label_801D75DC;
    case 0x801D75E0u: goto label_801D75E0;
    case 0x801D75E4u: goto label_801D75E4;
    case 0x801D75E8u: goto label_801D75E8;
    case 0x801D75ECu: goto label_801D75EC;
    case 0x801D75F0u: goto label_801D75F0;
    case 0x801D75F4u: goto label_801D75F4;
    case 0x801D75F8u: goto label_801D75F8;
    case 0x801D75FCu: goto label_801D75FC;
    case 0x801D7600u: goto label_801D7600;
    case 0x801D7604u: goto label_801D7604;
    case 0x801D7608u: goto label_801D7608;
    case 0x801D760Cu: goto label_801D760C;
    case 0x801D7610u: goto label_801D7610;
    case 0x801D7614u: goto label_801D7614;
    case 0x801D7618u: goto label_801D7618;
    case 0x801D761Cu: goto label_801D761C;
    case 0x801D7620u: goto label_801D7620;
    case 0x801D7624u: goto label_801D7624;
    case 0x801D7628u: goto label_801D7628;
    case 0x801D762Cu: goto label_801D762C;
    case 0x801D7630u: goto label_801D7630;
    case 0x801D7634u: goto label_801D7634;
    case 0x801D7638u: goto label_801D7638;
    case 0x801D763Cu: goto label_801D763C;
    case 0x801D7640u: goto label_801D7640;
    case 0x801D7644u: goto label_801D7644;
    case 0x801D7648u: goto label_801D7648;
    case 0x801D764Cu: goto label_801D764C;
    case 0x801D7650u: goto label_801D7650;
    case 0x801D7654u: goto label_801D7654;
    case 0x801D7658u: goto label_801D7658;
    case 0x801D765Cu: goto label_801D765C;
    case 0x801D7660u: goto label_801D7660;
    case 0x801D7664u: goto label_801D7664;
    case 0x801D7668u: goto label_801D7668;
    case 0x801D766Cu: goto label_801D766C;
    case 0x801D7670u: goto label_801D7670;
    case 0x801D7674u: goto label_801D7674;
    case 0x801D7678u: goto label_801D7678;
    case 0x801D767Cu: goto label_801D767C;
    case 0x801D7680u: goto label_801D7680;
    case 0x801D7684u: goto label_801D7684;
    case 0x801D7688u: goto label_801D7688;
    case 0x801D768Cu: goto label_801D768C;
    case 0x801D7690u: goto label_801D7690;
    case 0x801D7694u: goto label_801D7694;
    case 0x801D7698u: goto label_801D7698;
    case 0x801D769Cu: goto label_801D769C;
    case 0x801D76A0u: goto label_801D76A0;
    case 0x801D76A4u: goto label_801D76A4;
    case 0x801D76A8u: goto label_801D76A8;
    case 0x801D76ACu: goto label_801D76AC;
    case 0x801D76B0u: goto label_801D76B0;
    case 0x801D76B4u: goto label_801D76B4;
    case 0x801D76B8u: goto label_801D76B8;
    case 0x801D76BCu: goto label_801D76BC;
    case 0x801D76C0u: goto label_801D76C0;
    case 0x801D76C4u: goto label_801D76C4;
    case 0x801D76C8u: goto label_801D76C8;
    case 0x801D76CCu: goto label_801D76CC;
    case 0x801D76D0u: goto label_801D76D0;
    case 0x801D76D4u: goto label_801D76D4;
    case 0x801D76D8u: goto label_801D76D8;
    case 0x801D76DCu: goto label_801D76DC;
    case 0x801D76E0u: goto label_801D76E0;
    case 0x801D76E4u: goto label_801D76E4;
    case 0x801D76E8u: goto label_801D76E8;
    case 0x801D76ECu: goto label_801D76EC;
    case 0x801D76F0u: goto label_801D76F0;
    case 0x801D76F4u: goto label_801D76F4;
    case 0x801D76F8u: goto label_801D76F8;
    case 0x801D76FCu: goto label_801D76FC;
    case 0x801D7700u: goto label_801D7700;
    case 0x801D7704u: goto label_801D7704;
    case 0x801D7708u: goto label_801D7708;
    case 0x801D770Cu: goto label_801D770C;
    case 0x801D7710u: goto label_801D7710;
    case 0x801D7714u: goto label_801D7714;
    case 0x801D7718u: goto label_801D7718;
    case 0x801D771Cu: goto label_801D771C;
    case 0x801D7720u: goto label_801D7720;
    case 0x801D7724u: goto label_801D7724;
    case 0x801D7728u: goto label_801D7728;
    case 0x801D772Cu: goto label_801D772C;
    case 0x801D7730u: goto label_801D7730;
    case 0x801D7734u: goto label_801D7734;
    case 0x801D7738u: goto label_801D7738;
    case 0x801D773Cu: goto label_801D773C;
    case 0x801D7740u: goto label_801D7740;
    case 0x801D7744u: goto label_801D7744;
    case 0x801D7748u: goto label_801D7748;
    case 0x801D774Cu: goto label_801D774C;
    case 0x801D7750u: goto label_801D7750;
    case 0x801D7754u: goto label_801D7754;
    case 0x801D7758u: goto label_801D7758;
    case 0x801D775Cu: goto label_801D775C;
    case 0x801D7760u: goto label_801D7760;
    case 0x801D7764u: goto label_801D7764;
    case 0x801D7768u: goto label_801D7768;
    case 0x801D776Cu: goto label_801D776C;
    case 0x801D7770u: goto label_801D7770;
    case 0x801D7774u: goto label_801D7774;
    case 0x801D7778u: goto label_801D7778;
    case 0x801D777Cu: goto label_801D777C;
    case 0x801D7780u: goto label_801D7780;
    case 0x801D7784u: goto label_801D7784;
    case 0x801D7788u: goto label_801D7788;
    case 0x801D778Cu: goto label_801D778C;
    case 0x801D7790u: goto label_801D7790;
    case 0x801D7794u: goto label_801D7794;
    case 0x801D7798u: goto label_801D7798;
    case 0x801D779Cu: goto label_801D779C;
    case 0x801D77A0u: goto label_801D77A0;
    case 0x801D77A4u: goto label_801D77A4;
    case 0x801D77A8u: goto label_801D77A8;
    case 0x801D77ACu: goto label_801D77AC;
    case 0x801D77B0u: goto label_801D77B0;
    case 0x801D77B4u: goto label_801D77B4;
    case 0x801D77B8u: goto label_801D77B8;
    case 0x801D77BCu: goto label_801D77BC;
    case 0x801D77C0u: goto label_801D77C0;
    case 0x801D77C4u: goto label_801D77C4;
    case 0x801D77C8u: goto label_801D77C8;
    case 0x801D77CCu: goto label_801D77CC;
    case 0x801D77D0u: goto label_801D77D0;
    case 0x801D77D4u: goto label_801D77D4;
    case 0x801D77D8u: goto label_801D77D8;
    case 0x801D77DCu: goto label_801D77DC;
    case 0x801D77E0u: goto label_801D77E0;
    case 0x801D77E4u: goto label_801D77E4;
    case 0x801D77E8u: goto label_801D77E8;
    case 0x801D77ECu: goto label_801D77EC;
    case 0x801D77F0u: goto label_801D77F0;
    case 0x801D77F4u: goto label_801D77F4;
    case 0x801D77F8u: goto label_801D77F8;
    case 0x801D77FCu: goto label_801D77FC;
    case 0x801D7800u: goto label_801D7800;
    case 0x801D7804u: goto label_801D7804;
    case 0x801D7808u: goto label_801D7808;
    case 0x801D780Cu: goto label_801D780C;
    case 0x801D7810u: goto label_801D7810;
    case 0x801D7814u: goto label_801D7814;
    case 0x801D7818u: goto label_801D7818;
    case 0x801D781Cu: goto label_801D781C;
    case 0x801D7820u: goto label_801D7820;
    case 0x801D7824u: goto label_801D7824;
    case 0x801D7828u: goto label_801D7828;
    case 0x801D782Cu: goto label_801D782C;
    case 0x801D7830u: goto label_801D7830;
    case 0x801D7834u: goto label_801D7834;
    case 0x801D7838u: goto label_801D7838;
    case 0x801D783Cu: goto label_801D783C;
    case 0x801D7840u: goto label_801D7840;
    case 0x801D7844u: goto label_801D7844;
    case 0x801D7848u: goto label_801D7848;
    case 0x801D784Cu: goto label_801D784C;
    case 0x801D7850u: goto label_801D7850;
    case 0x801D7854u: goto label_801D7854;
    case 0x801D7858u: goto label_801D7858;
    case 0x801D785Cu: goto label_801D785C;
    case 0x801D7860u: goto label_801D7860;
    case 0x801D7864u: goto label_801D7864;
    case 0x801D7868u: goto label_801D7868;
    case 0x801D786Cu: goto label_801D786C;
    case 0x801D7870u: goto label_801D7870;
    case 0x801D7874u: goto label_801D7874;
    case 0x801D7878u: goto label_801D7878;
    case 0x801D787Cu: goto label_801D787C;
    case 0x801D7880u: goto label_801D7880;
    case 0x801D7884u: goto label_801D7884;
    case 0x801D7888u: goto label_801D7888;
    case 0x801D788Cu: goto label_801D788C;
    case 0x801D7890u: goto label_801D7890;
    case 0x801D7894u: goto label_801D7894;
    case 0x801D7898u: goto label_801D7898;
    case 0x801D789Cu: goto label_801D789C;
    case 0x801D78A0u: goto label_801D78A0;
    case 0x801D78A4u: goto label_801D78A4;
    case 0x801D78A8u: goto label_801D78A8;
    case 0x801D78ACu: goto label_801D78AC;
    case 0x801D78B0u: goto label_801D78B0;
    case 0x801D78B4u: goto label_801D78B4;
    case 0x801D78B8u: goto label_801D78B8;
    case 0x801D78BCu: goto label_801D78BC;
    case 0x801D78C0u: goto label_801D78C0;
    case 0x801D78C4u: goto label_801D78C4;
    case 0x801D78C8u: goto label_801D78C8;
    case 0x801D78CCu: goto label_801D78CC;
    case 0x801D78D0u: goto label_801D78D0;
    case 0x801D78D4u: goto label_801D78D4;
    case 0x801D78D8u: goto label_801D78D8;
    case 0x801D78DCu: goto label_801D78DC;
    case 0x801D78E0u: goto label_801D78E0;
    case 0x801D78E4u: goto label_801D78E4;
    case 0x801D78E8u: goto label_801D78E8;
    case 0x801D78ECu: goto label_801D78EC;
    case 0x801D78F0u: goto label_801D78F0;
    case 0x801D78F4u: goto label_801D78F4;
    case 0x801D78F8u: goto label_801D78F8;
    case 0x801D78FCu: goto label_801D78FC;
    case 0x801D7900u: goto label_801D7900;
    case 0x801D7904u: goto label_801D7904;
    case 0x801D7908u: goto label_801D7908;
    case 0x801D790Cu: goto label_801D790C;
    case 0x801D7910u: goto label_801D7910;
    case 0x801D7914u: goto label_801D7914;
    case 0x801D7918u: goto label_801D7918;
    case 0x801D791Cu: goto label_801D791C;
    case 0x801D7920u: goto label_801D7920;
    case 0x801D7924u: goto label_801D7924;
    case 0x801D7928u: goto label_801D7928;
    case 0x801D792Cu: goto label_801D792C;
    case 0x801D7930u: goto label_801D7930;
    case 0x801D7934u: goto label_801D7934;
    case 0x801D7938u: goto label_801D7938;
    case 0x801D793Cu: goto label_801D793C;
    case 0x801D7940u: goto label_801D7940;
    case 0x801D7944u: goto label_801D7944;
    case 0x801D7948u: goto label_801D7948;
    case 0x801D794Cu: goto label_801D794C;
    case 0x801D7950u: goto label_801D7950;
    case 0x801D7954u: goto label_801D7954;
    case 0x801D7958u: goto label_801D7958;
    case 0x801D795Cu: goto label_801D795C;
    case 0x801D7960u: goto label_801D7960;
    case 0x801D7964u: goto label_801D7964;
    case 0x801D7968u: goto label_801D7968;
    case 0x801D796Cu: goto label_801D796C;
    case 0x801D7970u: goto label_801D7970;
    case 0x801D7974u: goto label_801D7974;
    case 0x801D7978u: goto label_801D7978;
    case 0x801D797Cu: goto label_801D797C;
    case 0x801D7980u: goto label_801D7980;
    case 0x801D7984u: goto label_801D7984;
    case 0x801D7988u: goto label_801D7988;
    case 0x801D798Cu: goto label_801D798C;
    case 0x801D7990u: goto label_801D7990;
    case 0x801D7994u: goto label_801D7994;
    case 0x801D7998u: goto label_801D7998;
    case 0x801D799Cu: goto label_801D799C;
    case 0x801D79A0u: goto label_801D79A0;
    case 0x801D79A4u: goto label_801D79A4;
    case 0x801D79A8u: goto label_801D79A8;
    case 0x801D79ACu: goto label_801D79AC;
    case 0x801D79B0u: goto label_801D79B0;
    case 0x801D79B4u: goto label_801D79B4;
    case 0x801D79B8u: goto label_801D79B8;
    case 0x801D79BCu: goto label_801D79BC;
    case 0x801D79C0u: goto label_801D79C0;
    case 0x801D79C4u: goto label_801D79C4;
    case 0x801D79C8u: goto label_801D79C8;
    case 0x801D79CCu: goto label_801D79CC;
    case 0x801D79D0u: goto label_801D79D0;
    case 0x801D79D4u: goto label_801D79D4;
    case 0x801D79D8u: goto label_801D79D8;
    case 0x801D79DCu: goto label_801D79DC;
    case 0x801D79E0u: goto label_801D79E0;
    case 0x801D79E4u: goto label_801D79E4;
    case 0x801D79E8u: goto label_801D79E8;
    case 0x801D79ECu: goto label_801D79EC;
    case 0x801D79F0u: goto label_801D79F0;
    case 0x801D79F4u: goto label_801D79F4;
    case 0x801D79F8u: goto label_801D79F8;
    case 0x801D79FCu: goto label_801D79FC;
    case 0x801D7A00u: goto label_801D7A00;
    case 0x801D7A04u: goto label_801D7A04;
    case 0x801D7A08u: goto label_801D7A08;
    case 0x801D7A0Cu: goto label_801D7A0C;
    case 0x801D7A10u: goto label_801D7A10;
    case 0x801D7A14u: goto label_801D7A14;
    case 0x801D7A18u: goto label_801D7A18;
    case 0x801D7A1Cu: goto label_801D7A1C;
    case 0x801D7A20u: goto label_801D7A20;
    case 0x801D7A24u: goto label_801D7A24;
    case 0x801D7A28u: goto label_801D7A28;
    case 0x801D7A2Cu: goto label_801D7A2C;
    case 0x801D7A30u: goto label_801D7A30;
    case 0x801D7A34u: goto label_801D7A34;
    case 0x801D7A38u: goto label_801D7A38;
    case 0x801D7A3Cu: goto label_801D7A3C;
    case 0x801D7A40u: goto label_801D7A40;
    case 0x801D7A44u: goto label_801D7A44;
    case 0x801D7A48u: goto label_801D7A48;
    case 0x801D7A4Cu: goto label_801D7A4C;
    case 0x801D7A50u: goto label_801D7A50;
    case 0x801D7A54u: goto label_801D7A54;
    case 0x801D7A58u: goto label_801D7A58;
    case 0x801D7A5Cu: goto label_801D7A5C;
    case 0x801D7A60u: goto label_801D7A60;
    case 0x801D7A64u: goto label_801D7A64;
    case 0x801D7A68u: goto label_801D7A68;
    case 0x801D7A6Cu: goto label_801D7A6C;
    case 0x801D7A70u: goto label_801D7A70;
    case 0x801D7A74u: goto label_801D7A74;
    case 0x801D7A78u: goto label_801D7A78;
    case 0x801D7A7Cu: goto label_801D7A7C;
    case 0x801D7A80u: goto label_801D7A80;
    case 0x801D7A84u: goto label_801D7A84;
    case 0x801D7A88u: goto label_801D7A88;
    case 0x801D7A8Cu: goto label_801D7A8C;
    case 0x801D7A90u: goto label_801D7A90;
    case 0x801D7A94u: goto label_801D7A94;
    case 0x801D7A98u: goto label_801D7A98;
    case 0x801D7A9Cu: goto label_801D7A9C;
    case 0x801D7AA0u: goto label_801D7AA0;
    case 0x801D7AA4u: goto label_801D7AA4;
    case 0x801D7AA8u: goto label_801D7AA8;
    case 0x801D7AACu: goto label_801D7AAC;
    case 0x801D7AB0u: goto label_801D7AB0;
    case 0x801D7AB4u: goto label_801D7AB4;
    case 0x801D7AB8u: goto label_801D7AB8;
    case 0x801D7ABCu: goto label_801D7ABC;
    case 0x801D7AC0u: goto label_801D7AC0;
    case 0x801D7AC4u: goto label_801D7AC4;
    case 0x801D7AC8u: goto label_801D7AC8;
    case 0x801D7ACCu: goto label_801D7ACC;
    case 0x801D7AD0u: goto label_801D7AD0;
    case 0x801D7AD4u: goto label_801D7AD4;
    case 0x801D7AD8u: goto label_801D7AD8;
    case 0x801D7ADCu: goto label_801D7ADC;
    case 0x801D7AE0u: goto label_801D7AE0;
    case 0x801D7AE4u: goto label_801D7AE4;
    case 0x801D7AE8u: goto label_801D7AE8;
    case 0x801D7AECu: goto label_801D7AEC;
    case 0x801D7AF0u: goto label_801D7AF0;
    case 0x801D7AF4u: goto label_801D7AF4;
    case 0x801D7AF8u: goto label_801D7AF8;
    case 0x801D7AFCu: goto label_801D7AFC;
    case 0x801D7B00u: goto label_801D7B00;
    case 0x801D7B04u: goto label_801D7B04;
    case 0x801D7B08u: goto label_801D7B08;
    case 0x801D7B0Cu: goto label_801D7B0C;
    case 0x801D7B10u: goto label_801D7B10;
    case 0x801D7B14u: goto label_801D7B14;
    case 0x801D7B18u: goto label_801D7B18;
    case 0x801D7B1Cu: goto label_801D7B1C;
    case 0x801D7B20u: goto label_801D7B20;
    case 0x801D7B24u: goto label_801D7B24;
    case 0x801D7B28u: goto label_801D7B28;
    case 0x801D7B2Cu: goto label_801D7B2C;
    case 0x801D7B30u: goto label_801D7B30;
    case 0x801D7B34u: goto label_801D7B34;
    case 0x801D7B38u: goto label_801D7B38;
    case 0x801D7B3Cu: goto label_801D7B3C;
    case 0x801D7B40u: goto label_801D7B40;
    case 0x801D7B44u: goto label_801D7B44;
    case 0x801D7B48u: goto label_801D7B48;
    case 0x801D7B4Cu: goto label_801D7B4C;
    case 0x801D7B50u: goto label_801D7B50;
    case 0x801D7B54u: goto label_801D7B54;
    case 0x801D7B58u: goto label_801D7B58;
    case 0x801D7B5Cu: goto label_801D7B5C;
    case 0x801D7B60u: goto label_801D7B60;
    case 0x801D7B64u: goto label_801D7B64;
    case 0x801D7B68u: goto label_801D7B68;
    case 0x801D7B6Cu: goto label_801D7B6C;
    case 0x801D7B70u: goto label_801D7B70;
    case 0x801D7B74u: goto label_801D7B74;
    case 0x801D7B78u: goto label_801D7B78;
    case 0x801D7B7Cu: goto label_801D7B7C;
    case 0x801D7B80u: goto label_801D7B80;
    case 0x801D7B84u: goto label_801D7B84;
    case 0x801D7B88u: goto label_801D7B88;
    case 0x801D7B8Cu: goto label_801D7B8C;
    case 0x801D7B90u: goto label_801D7B90;
    case 0x801D7B94u: goto label_801D7B94;
    case 0x801D7B98u: goto label_801D7B98;
    case 0x801D7B9Cu: goto label_801D7B9C;
    case 0x801D7BA0u: goto label_801D7BA0;
    case 0x801D7BA4u: goto label_801D7BA4;
    case 0x801D7BA8u: goto label_801D7BA8;
    case 0x801D7BACu: goto label_801D7BAC;
    case 0x801D7BB0u: goto label_801D7BB0;
    case 0x801D7BB4u: goto label_801D7BB4;
    case 0x801D7BB8u: goto label_801D7BB8;
    case 0x801D7BBCu: goto label_801D7BBC;
    case 0x801D7BC0u: goto label_801D7BC0;
    case 0x801D7BC4u: goto label_801D7BC4;
    case 0x801D7BC8u: goto label_801D7BC8;
    case 0x801D7BCCu: goto label_801D7BCC;
    case 0x801D7BD0u: goto label_801D7BD0;
    case 0x801D7BD4u: goto label_801D7BD4;
    case 0x801D7BD8u: goto label_801D7BD8;
    case 0x801D7BDCu: goto label_801D7BDC;
    case 0x801D7BE0u: goto label_801D7BE0;
    case 0x801D7BE4u: goto label_801D7BE4;
    case 0x801D7BE8u: goto label_801D7BE8;
    case 0x801D7BECu: goto label_801D7BEC;
    case 0x801D7BF0u: goto label_801D7BF0;
    case 0x801D7BF4u: goto label_801D7BF4;
    case 0x801D7BF8u: goto label_801D7BF8;
    case 0x801D7BFCu: goto label_801D7BFC;
    case 0x801D7C00u: goto label_801D7C00;
    case 0x801D7C04u: goto label_801D7C04;
    case 0x801D7C08u: goto label_801D7C08;
    case 0x801D7C0Cu: goto label_801D7C0C;
    case 0x801D7C10u: goto label_801D7C10;
    case 0x801D7C14u: goto label_801D7C14;
    case 0x801D7C18u: goto label_801D7C18;
    case 0x801D7C1Cu: goto label_801D7C1C;
    case 0x801D7C20u: goto label_801D7C20;
    case 0x801D7C24u: goto label_801D7C24;
    case 0x801D7C28u: goto label_801D7C28;
    case 0x801D7C2Cu: goto label_801D7C2C;
    case 0x801D7C30u: goto label_801D7C30;
    case 0x801D7C34u: goto label_801D7C34;
    case 0x801D7C38u: goto label_801D7C38;
    case 0x801D7C3Cu: goto label_801D7C3C;
    case 0x801D7C40u: goto label_801D7C40;
    case 0x801D7C44u: goto label_801D7C44;
    case 0x801D7C48u: goto label_801D7C48;
    case 0x801D7C4Cu: goto label_801D7C4C;
    case 0x801D7C50u: goto label_801D7C50;
    case 0x801D7C54u: goto label_801D7C54;
    case 0x801D7C58u: goto label_801D7C58;
    case 0x801D7C5Cu: goto label_801D7C5C;
    case 0x801D7C60u: goto label_801D7C60;
    case 0x801D7C64u: goto label_801D7C64;
    case 0x801D7C68u: goto label_801D7C68;
    case 0x801D7C6Cu: goto label_801D7C6C;
    case 0x801D7C70u: goto label_801D7C70;
    case 0x801D7C74u: goto label_801D7C74;
    case 0x801D7C78u: goto label_801D7C78;
    case 0x801D7C7Cu: goto label_801D7C7C;
    case 0x801D7C80u: goto label_801D7C80;
    case 0x801D7C84u: goto label_801D7C84;
    case 0x801D7C88u: goto label_801D7C88;
    case 0x801D7C8Cu: goto label_801D7C8C;
    case 0x801D7C90u: goto label_801D7C90;
    case 0x801D7C94u: goto label_801D7C94;
    case 0x801D7C98u: goto label_801D7C98;
    case 0x801D7C9Cu: goto label_801D7C9C;
    case 0x801D7CA0u: goto label_801D7CA0;
    case 0x801D7CA4u: goto label_801D7CA4;
    case 0x801D7CA8u: goto label_801D7CA8;
    case 0x801D7CACu: goto label_801D7CAC;
    case 0x801D7CB0u: goto label_801D7CB0;
    case 0x801D7CB4u: goto label_801D7CB4;
    case 0x801D7CB8u: goto label_801D7CB8;
    case 0x801D7CBCu: goto label_801D7CBC;
    case 0x801D7CC0u: goto label_801D7CC0;
    case 0x801D7CC4u: goto label_801D7CC4;
    case 0x801D7CC8u: goto label_801D7CC8;
    case 0x801D7CCCu: goto label_801D7CCC;
    case 0x801D7CD0u: goto label_801D7CD0;
    case 0x801D7CD4u: goto label_801D7CD4;
    case 0x801D7CD8u: goto label_801D7CD8;
    case 0x801D7CDCu: goto label_801D7CDC;
    case 0x801D7CE0u: goto label_801D7CE0;
    case 0x801D7CE4u: goto label_801D7CE4;
    case 0x801D7CE8u: goto label_801D7CE8;
    case 0x801D7CECu: goto label_801D7CEC;
    case 0x801D7CF0u: goto label_801D7CF0;
    case 0x801D7CF4u: goto label_801D7CF4;
    case 0x801D7CF8u: goto label_801D7CF8;
    case 0x801D7CFCu: goto label_801D7CFC;
    case 0x801D7D00u: goto label_801D7D00;
    case 0x801D7D04u: goto label_801D7D04;
    case 0x801D7D08u: goto label_801D7D08;
    case 0x801D7D0Cu: goto label_801D7D0C;
    case 0x801D7D10u: goto label_801D7D10;
    case 0x801D7D14u: goto label_801D7D14;
    case 0x801D7D18u: goto label_801D7D18;
    case 0x801D7D1Cu: goto label_801D7D1C;
    case 0x801D7D20u: goto label_801D7D20;
    case 0x801D7D24u: goto label_801D7D24;
    case 0x801D7D28u: goto label_801D7D28;
    case 0x801D7D2Cu: goto label_801D7D2C;
    case 0x801D7D30u: goto label_801D7D30;
    case 0x801D7D34u: goto label_801D7D34;
    case 0x801D7D38u: goto label_801D7D38;
    case 0x801D7D3Cu: goto label_801D7D3C;
    case 0x801D7D40u: goto label_801D7D40;
    case 0x801D7D44u: goto label_801D7D44;
    case 0x801D7D48u: goto label_801D7D48;
    case 0x801D7D4Cu: goto label_801D7D4C;
    case 0x801D7D50u: goto label_801D7D50;
    case 0x801D7D54u: goto label_801D7D54;
    case 0x801D7D58u: goto label_801D7D58;
    case 0x801D7D5Cu: goto label_801D7D5C;
    case 0x801D7D60u: goto label_801D7D60;
    case 0x801D7D64u: goto label_801D7D64;
    case 0x801D7D68u: goto label_801D7D68;
    case 0x801D7D6Cu: goto label_801D7D6C;
    case 0x801D7D70u: goto label_801D7D70;
    case 0x801D7D74u: goto label_801D7D74;
    case 0x801D7D78u: goto label_801D7D78;
    case 0x801D7D7Cu: goto label_801D7D7C;
    case 0x801D7D80u: goto label_801D7D80;
    case 0x801D7D84u: goto label_801D7D84;
    case 0x801D7D88u: goto label_801D7D88;
    case 0x801D7D8Cu: goto label_801D7D8C;
    case 0x801D7D90u: goto label_801D7D90;
    case 0x801D7D94u: goto label_801D7D94;
    case 0x801D7D98u: goto label_801D7D98;
    case 0x801D7D9Cu: goto label_801D7D9C;
    case 0x801D7DA0u: goto label_801D7DA0;
    case 0x801D7DA4u: goto label_801D7DA4;
    case 0x801D7DA8u: goto label_801D7DA8;
    case 0x801D7DACu: goto label_801D7DAC;
    case 0x801D7DB0u: goto label_801D7DB0;
    case 0x801D7DB4u: goto label_801D7DB4;
    case 0x801D7DB8u: goto label_801D7DB8;
    case 0x801D7DBCu: goto label_801D7DBC;
    case 0x801D7DC0u: goto label_801D7DC0;
    case 0x801D7DC4u: goto label_801D7DC4;
    case 0x801D7DC8u: goto label_801D7DC8;
    case 0x801D7DCCu: goto label_801D7DCC;
    case 0x801D7DD0u: goto label_801D7DD0;
    case 0x801D7DD4u: goto label_801D7DD4;
    case 0x801D7DD8u: goto label_801D7DD8;
    case 0x801D7DDCu: goto label_801D7DDC;
    case 0x801D7DE0u: goto label_801D7DE0;
    case 0x801D7DE4u: goto label_801D7DE4;
    case 0x801D7DE8u: goto label_801D7DE8;
    case 0x801D7DECu: goto label_801D7DEC;
    case 0x801D7DF0u: goto label_801D7DF0;
    case 0x801D7DF4u: goto label_801D7DF4;
    case 0x801D7DF8u: goto label_801D7DF8;
    case 0x801D7DFCu: goto label_801D7DFC;
    case 0x801D7E00u: goto label_801D7E00;
    case 0x801D7E04u: goto label_801D7E04;
    case 0x801D7E08u: goto label_801D7E08;
    case 0x801D7E0Cu: goto label_801D7E0C;
    case 0x801D7E10u: goto label_801D7E10;
    case 0x801D7E14u: goto label_801D7E14;
    case 0x801D7E18u: goto label_801D7E18;
    case 0x801D7E1Cu: goto label_801D7E1C;
    case 0x801D7E20u: goto label_801D7E20;
    case 0x801D7E24u: goto label_801D7E24;
    case 0x801D7E28u: goto label_801D7E28;
    case 0x801D7E2Cu: goto label_801D7E2C;
    case 0x801D7E30u: goto label_801D7E30;
    case 0x801D7E34u: goto label_801D7E34;
    case 0x801D7E38u: goto label_801D7E38;
    case 0x801D7E3Cu: goto label_801D7E3C;
    case 0x801D7E40u: goto label_801D7E40;
    case 0x801D7E44u: goto label_801D7E44;
    case 0x801D7E48u: goto label_801D7E48;
    case 0x801D7E4Cu: goto label_801D7E4C;
    case 0x801D7E50u: goto label_801D7E50;
    case 0x801D7E54u: goto label_801D7E54;
    case 0x801D7E58u: goto label_801D7E58;
    case 0x801D7E5Cu: goto label_801D7E5C;
    case 0x801D7E60u: goto label_801D7E60;
    case 0x801D7E64u: goto label_801D7E64;
    case 0x801D7E68u: goto label_801D7E68;
    case 0x801D7E6Cu: goto label_801D7E6C;
    case 0x801D7E70u: goto label_801D7E70;
    case 0x801D7E74u: goto label_801D7E74;
    case 0x801D7E78u: goto label_801D7E78;
    case 0x801D7E7Cu: goto label_801D7E7C;
    case 0x801D7E80u: goto label_801D7E80;
    case 0x801D7E84u: goto label_801D7E84;
    case 0x801D7E88u: goto label_801D7E88;
    case 0x801D7E8Cu: goto label_801D7E8C;
    case 0x801D7E90u: goto label_801D7E90;
    case 0x801D7E94u: goto label_801D7E94;
    case 0x801D7E98u: goto label_801D7E98;
    case 0x801D7E9Cu: goto label_801D7E9C;
    case 0x801D7EA0u: goto label_801D7EA0;
    case 0x801D7EA4u: goto label_801D7EA4;
    case 0x801D7EA8u: goto label_801D7EA8;
    case 0x801D7EACu: goto label_801D7EAC;
    case 0x801D7EB0u: goto label_801D7EB0;
    case 0x801D7EB4u: goto label_801D7EB4;
    case 0x801D7EB8u: goto label_801D7EB8;
    case 0x801D7EBCu: goto label_801D7EBC;
    case 0x801D7EC0u: goto label_801D7EC0;
    case 0x801D7EC4u: goto label_801D7EC4;
    case 0x801D7EC8u: goto label_801D7EC8;
    case 0x801D7ECCu: goto label_801D7ECC;
    case 0x801D7ED0u: goto label_801D7ED0;
    case 0x801D7ED4u: goto label_801D7ED4;
    case 0x801D7ED8u: goto label_801D7ED8;
    case 0x801D7EDCu: goto label_801D7EDC;
    case 0x801D7EE0u: goto label_801D7EE0;
    case 0x801D7EE4u: goto label_801D7EE4;
    case 0x801D7EE8u: goto label_801D7EE8;
    case 0x801D7EECu: goto label_801D7EEC;
    case 0x801D7EF0u: goto label_801D7EF0;
    case 0x801D7EF4u: goto label_801D7EF4;
    case 0x801D7EF8u: goto label_801D7EF8;
    case 0x801D7EFCu: goto label_801D7EFC;
    case 0x801D7F00u: goto label_801D7F00;
    case 0x801D7F04u: goto label_801D7F04;
    case 0x801D7F08u: goto label_801D7F08;
    case 0x801D7F0Cu: goto label_801D7F0C;
    case 0x801D7F10u: goto label_801D7F10;
    case 0x801D7F14u: goto label_801D7F14;
    case 0x801D7F18u: goto label_801D7F18;
    case 0x801D7F1Cu: goto label_801D7F1C;
    case 0x801D7F20u: goto label_801D7F20;
    case 0x801D7F24u: goto label_801D7F24;
    case 0x801D7F28u: goto label_801D7F28;
    case 0x801D7F2Cu: goto label_801D7F2C;
    case 0x801D7F30u: goto label_801D7F30;
    case 0x801D7F34u: goto label_801D7F34;
    case 0x801D7F38u: goto label_801D7F38;
    case 0x801D7F3Cu: goto label_801D7F3C;
    case 0x801D7F40u: goto label_801D7F40;
    case 0x801D7F44u: goto label_801D7F44;
    case 0x801D7F48u: goto label_801D7F48;
    case 0x801D7F4Cu: goto label_801D7F4C;
    case 0x801D7F50u: goto label_801D7F50;
    case 0x801D7F54u: goto label_801D7F54;
    case 0x801D7F58u: goto label_801D7F58;
    case 0x801D7F5Cu: goto label_801D7F5C;
    case 0x801D7F60u: goto label_801D7F60;
    case 0x801D7F64u: goto label_801D7F64;
    case 0x801D7F68u: goto label_801D7F68;
    case 0x801D7F6Cu: goto label_801D7F6C;
    case 0x801D7F70u: goto label_801D7F70;
    case 0x801D7F74u: goto label_801D7F74;
    case 0x801D7F78u: goto label_801D7F78;
    case 0x801D7F7Cu: goto label_801D7F7C;
    case 0x801D7F80u: goto label_801D7F80;
    case 0x801D7F84u: goto label_801D7F84;
    case 0x801D7F88u: goto label_801D7F88;
    case 0x801D7F8Cu: goto label_801D7F8C;
    case 0x801D7F90u: goto label_801D7F90;
    case 0x801D7F94u: goto label_801D7F94;
    case 0x801D7F98u: goto label_801D7F98;
    case 0x801D7F9Cu: goto label_801D7F9C;
    case 0x801D7FA0u: goto label_801D7FA0;
    case 0x801D7FA4u: goto label_801D7FA4;
    case 0x801D7FA8u: goto label_801D7FA8;
    case 0x801D7FACu: goto label_801D7FAC;
    case 0x801D7FB0u: goto label_801D7FB0;
    case 0x801D7FB4u: goto label_801D7FB4;
    case 0x801D7FB8u: goto label_801D7FB8;
    case 0x801D7FBCu: goto label_801D7FBC;
    case 0x801D7FC0u: goto label_801D7FC0;
    case 0x801D7FC4u: goto label_801D7FC4;
    case 0x801D7FC8u: goto label_801D7FC8;
    case 0x801D7FCCu: goto label_801D7FCC;
    case 0x801D7FD0u: goto label_801D7FD0;
    case 0x801D7FD4u: goto label_801D7FD4;
    case 0x801D7FD8u: goto label_801D7FD8;
    case 0x801D7FDCu: goto label_801D7FDC;
    case 0x801D7FE0u: goto label_801D7FE0;
    case 0x801D7FE4u: goto label_801D7FE4;
    case 0x801D7FE8u: goto label_801D7FE8;
    case 0x801D7FECu: goto label_801D7FEC;
    case 0x801D7FF0u: goto label_801D7FF0;
    case 0x801D7FF4u: goto label_801D7FF4;
    case 0x801D7FF8u: goto label_801D7FF8;
    case 0x801D7FFCu: goto label_801D7FFC;
    case 0x801D8000u: goto label_801D8000;
    case 0x801D8004u: goto label_801D8004;
    case 0x801D8008u: goto label_801D8008;
    case 0x801D800Cu: goto label_801D800C;
    case 0x801D8010u: goto label_801D8010;
    case 0x801D8014u: goto label_801D8014;
    case 0x801D8018u: goto label_801D8018;
    case 0x801D801Cu: goto label_801D801C;
    case 0x801D8020u: goto label_801D8020;
    case 0x801D8024u: goto label_801D8024;
    case 0x801D8028u: goto label_801D8028;
    case 0x801D802Cu: goto label_801D802C;
    case 0x801D8030u: goto label_801D8030;
    case 0x801D8034u: goto label_801D8034;
    case 0x801D8038u: goto label_801D8038;
    case 0x801D803Cu: goto label_801D803C;
    case 0x801D8040u: goto label_801D8040;
    case 0x801D8044u: goto label_801D8044;
    case 0x801D8048u: goto label_801D8048;
    case 0x801D804Cu: goto label_801D804C;
    case 0x801D8050u: goto label_801D8050;
    case 0x801D8054u: goto label_801D8054;
    case 0x801D8058u: goto label_801D8058;
    case 0x801D805Cu: goto label_801D805C;
    case 0x801D8060u: goto label_801D8060;
    case 0x801D8064u: goto label_801D8064;
    case 0x801D8068u: goto label_801D8068;
    case 0x801D806Cu: goto label_801D806C;
    case 0x801D8070u: goto label_801D8070;
    case 0x801D8074u: goto label_801D8074;
    case 0x801D8078u: goto label_801D8078;
    case 0x801D807Cu: goto label_801D807C;
    case 0x801D8080u: goto label_801D8080;
    case 0x801D8084u: goto label_801D8084;
    case 0x801D8088u: goto label_801D8088;
    case 0x801D808Cu: goto label_801D808C;
    case 0x801D8090u: goto label_801D8090;
    case 0x801D8094u: goto label_801D8094;
    case 0x801D8098u: goto label_801D8098;
    case 0x801D809Cu: goto label_801D809C;
    case 0x801D80A0u: goto label_801D80A0;
    case 0x801D80A4u: goto label_801D80A4;
    case 0x801D80A8u: goto label_801D80A8;
    case 0x801D80ACu: goto label_801D80AC;
    case 0x801D80B0u: goto label_801D80B0;
    case 0x801D80B4u: goto label_801D80B4;
    case 0x801D80B8u: goto label_801D80B8;
    case 0x801D80BCu: goto label_801D80BC;
    case 0x801D80C0u: goto label_801D80C0;
    case 0x801D80C4u: goto label_801D80C4;
    case 0x801D80C8u: goto label_801D80C8;
    case 0x801D80CCu: goto label_801D80CC;
    case 0x801D80D0u: goto label_801D80D0;
    case 0x801D80D4u: goto label_801D80D4;
    case 0x801D80D8u: goto label_801D80D8;
    case 0x801D80DCu: goto label_801D80DC;
    case 0x801D80E0u: goto label_801D80E0;
    case 0x801D80E4u: goto label_801D80E4;
    case 0x801D80E8u: goto label_801D80E8;
    case 0x801D80ECu: goto label_801D80EC;
    case 0x801D80F0u: goto label_801D80F0;
    case 0x801D80F4u: goto label_801D80F4;
    case 0x801D80F8u: goto label_801D80F8;
    case 0x801D80FCu: goto label_801D80FC;
    case 0x801D8100u: goto label_801D8100;
    case 0x801D8104u: goto label_801D8104;
    case 0x801D8108u: goto label_801D8108;
    case 0x801D810Cu: goto label_801D810C;
    case 0x801D8110u: goto label_801D8110;
    case 0x801D8114u: goto label_801D8114;
    case 0x801D8118u: goto label_801D8118;
    case 0x801D811Cu: goto label_801D811C;
    case 0x801D8120u: goto label_801D8120;
    case 0x801D8124u: goto label_801D8124;
    case 0x801D8128u: goto label_801D8128;
    case 0x801D812Cu: goto label_801D812C;
    case 0x801D8130u: goto label_801D8130;
    case 0x801D8134u: goto label_801D8134;
    case 0x801D8138u: goto label_801D8138;
    case 0x801D813Cu: goto label_801D813C;
    case 0x801D8140u: goto label_801D8140;
    case 0x801D8144u: goto label_801D8144;
    case 0x801D8148u: goto label_801D8148;
    case 0x801D814Cu: goto label_801D814C;
    case 0x801D8150u: goto label_801D8150;
    case 0x801D8154u: goto label_801D8154;
    case 0x801D8158u: goto label_801D8158;
    case 0x801D815Cu: goto label_801D815C;
    case 0x801D8160u: goto label_801D8160;
    case 0x801D8164u: goto label_801D8164;
    case 0x801D8168u: goto label_801D8168;
    case 0x801D816Cu: goto label_801D816C;
    case 0x801D8170u: goto label_801D8170;
    case 0x801D8174u: goto label_801D8174;
    case 0x801D8178u: goto label_801D8178;
    case 0x801D817Cu: goto label_801D817C;
    case 0x801D8180u: goto label_801D8180;
    case 0x801D8184u: goto label_801D8184;
    case 0x801D8188u: goto label_801D8188;
    case 0x801D818Cu: goto label_801D818C;
    case 0x801D8190u: goto label_801D8190;
    case 0x801D8194u: goto label_801D8194;
    case 0x801D8198u: goto label_801D8198;
    case 0x801D819Cu: goto label_801D819C;
    case 0x801D81A0u: goto label_801D81A0;
    case 0x801D81A4u: goto label_801D81A4;
    case 0x801D81A8u: goto label_801D81A8;
    case 0x801D81ACu: goto label_801D81AC;
    case 0x801D81B0u: goto label_801D81B0;
    case 0x801D81B4u: goto label_801D81B4;
    case 0x801D81B8u: goto label_801D81B8;
    case 0x801D81BCu: goto label_801D81BC;
    case 0x801D81C0u: goto label_801D81C0;
    case 0x801D81C4u: goto label_801D81C4;
    case 0x801D81C8u: goto label_801D81C8;
    case 0x801D81CCu: goto label_801D81CC;
    case 0x801D81D0u: goto label_801D81D0;
    case 0x801D81D4u: goto label_801D81D4;
    case 0x801D81D8u: goto label_801D81D8;
    case 0x801D81DCu: goto label_801D81DC;
    case 0x801D81E0u: goto label_801D81E0;
    case 0x801D81E4u: goto label_801D81E4;
    case 0x801D81E8u: goto label_801D81E8;
    case 0x801D81ECu: goto label_801D81EC;
    case 0x801D81F0u: goto label_801D81F0;
    case 0x801D81F4u: goto label_801D81F4;
    case 0x801D81F8u: goto label_801D81F8;
    case 0x801D81FCu: goto label_801D81FC;
    case 0x801D8200u: goto label_801D8200;
    case 0x801D8204u: goto label_801D8204;
    case 0x801D8208u: goto label_801D8208;
    case 0x801D820Cu: goto label_801D820C;
    case 0x801D8210u: goto label_801D8210;
    case 0x801D8214u: goto label_801D8214;
    case 0x801D8218u: goto label_801D8218;
    case 0x801D821Cu: goto label_801D821C;
    case 0x801D8220u: goto label_801D8220;
    case 0x801D8224u: goto label_801D8224;
    case 0x801D8228u: goto label_801D8228;
    case 0x801D822Cu: goto label_801D822C;
    case 0x801D8230u: goto label_801D8230;
    case 0x801D8234u: goto label_801D8234;
    case 0x801D8238u: goto label_801D8238;
    case 0x801D823Cu: goto label_801D823C;
    case 0x801D8240u: goto label_801D8240;
    case 0x801D8244u: goto label_801D8244;
    case 0x801D8248u: goto label_801D8248;
    case 0x801D824Cu: goto label_801D824C;
    case 0x801D8250u: goto label_801D8250;
    case 0x801D8254u: goto label_801D8254;
    case 0x801D8258u: goto label_801D8258;
    case 0x801D825Cu: goto label_801D825C;
    case 0x801D8260u: goto label_801D8260;
    case 0x801D8264u: goto label_801D8264;
    case 0x801D8268u: goto label_801D8268;
    case 0x801D826Cu: goto label_801D826C;
    case 0x801D8270u: goto label_801D8270;
    case 0x801D8274u: goto label_801D8274;
    case 0x801D8278u: goto label_801D8278;
    case 0x801D827Cu: goto label_801D827C;
    case 0x801D8280u: goto label_801D8280;
    case 0x801D8284u: goto label_801D8284;
    case 0x801D8288u: goto label_801D8288;
    case 0x801D828Cu: goto label_801D828C;
    case 0x801D8290u: goto label_801D8290;
    case 0x801D8294u: goto label_801D8294;
    case 0x801D8298u: goto label_801D8298;
    case 0x801D829Cu: goto label_801D829C;
    case 0x801D82A0u: goto label_801D82A0;
    case 0x801D82A4u: goto label_801D82A4;
    case 0x801D82A8u: goto label_801D82A8;
    case 0x801D82ACu: goto label_801D82AC;
    case 0x801D82B0u: goto label_801D82B0;
    case 0x801D82B4u: goto label_801D82B4;
    case 0x801D82B8u: goto label_801D82B8;
    case 0x801D82BCu: goto label_801D82BC;
    case 0x801D82C0u: goto label_801D82C0;
    case 0x801D82C4u: goto label_801D82C4;
    case 0x801D82C8u: goto label_801D82C8;
    case 0x801D82CCu: goto label_801D82CC;
    case 0x801D82D0u: goto label_801D82D0;
    case 0x801D82D4u: goto label_801D82D4;
    case 0x801D82D8u: goto label_801D82D8;
    case 0x801D82DCu: goto label_801D82DC;
    case 0x801D82E0u: goto label_801D82E0;
    case 0x801D82E4u: goto label_801D82E4;
    case 0x801D82E8u: goto label_801D82E8;
    case 0x801D82ECu: goto label_801D82EC;
    case 0x801D82F0u: goto label_801D82F0;
    case 0x801D82F4u: goto label_801D82F4;
    case 0x801D82F8u: goto label_801D82F8;
    case 0x801D82FCu: goto label_801D82FC;
    case 0x801D8300u: goto label_801D8300;
    case 0x801D8304u: goto label_801D8304;
    case 0x801D8308u: goto label_801D8308;
    case 0x801D830Cu: goto label_801D830C;
    case 0x801D8310u: goto label_801D8310;
    case 0x801D8314u: goto label_801D8314;
    case 0x801D8318u: goto label_801D8318;
    case 0x801D831Cu: goto label_801D831C;
    case 0x801D8320u: goto label_801D8320;
    case 0x801D8324u: goto label_801D8324;
    case 0x801D8328u: goto label_801D8328;
    case 0x801D832Cu: goto label_801D832C;
    case 0x801D8330u: goto label_801D8330;
    case 0x801D8334u: goto label_801D8334;
    case 0x801D8338u: goto label_801D8338;
    case 0x801D833Cu: goto label_801D833C;
    case 0x801D8340u: goto label_801D8340;
    case 0x801D8344u: goto label_801D8344;
    case 0x801D8348u: goto label_801D8348;
    case 0x801D834Cu: goto label_801D834C;
    case 0x801D8350u: goto label_801D8350;
    case 0x801D8354u: goto label_801D8354;
    case 0x801D8358u: goto label_801D8358;
    case 0x801D835Cu: goto label_801D835C;
    case 0x801D8360u: goto label_801D8360;
    case 0x801D8364u: goto label_801D8364;
    case 0x801D8368u: goto label_801D8368;
    case 0x801D836Cu: goto label_801D836C;
    case 0x801D8370u: goto label_801D8370;
    case 0x801D8374u: goto label_801D8374;
    case 0x801D8378u: goto label_801D8378;
    case 0x801D837Cu: goto label_801D837C;
    case 0x801D8380u: goto label_801D8380;
    case 0x801D8384u: goto label_801D8384;
    case 0x801D8388u: goto label_801D8388;
    case 0x801D838Cu: goto label_801D838C;
    case 0x801D8390u: goto label_801D8390;
    case 0x801D8394u: goto label_801D8394;
    case 0x801D8398u: goto label_801D8398;
    case 0x801D839Cu: goto label_801D839C;
    case 0x801D83A0u: goto label_801D83A0;
    case 0x801D83A4u: goto label_801D83A4;
    case 0x801D83A8u: goto label_801D83A8;
    case 0x801D83ACu: goto label_801D83AC;
    case 0x801D83B0u: goto label_801D83B0;
    case 0x801D83B4u: goto label_801D83B4;
    case 0x801D83B8u: goto label_801D83B8;
    case 0x801D83BCu: goto label_801D83BC;
    case 0x801D83C0u: goto label_801D83C0;
    case 0x801D83C4u: goto label_801D83C4;
    case 0x801D83C8u: goto label_801D83C8;
    case 0x801D83CCu: goto label_801D83CC;
    case 0x801D83D0u: goto label_801D83D0;
    case 0x801D83D4u: goto label_801D83D4;
    case 0x801D83D8u: goto label_801D83D8;
    case 0x801D83DCu: goto label_801D83DC;
    case 0x801D83E0u: goto label_801D83E0;
    case 0x801D83E4u: goto label_801D83E4;
    case 0x801D83E8u: goto label_801D83E8;
    case 0x801D83ECu: goto label_801D83EC;
    case 0x801D83F0u: goto label_801D83F0;
    case 0x801D83F4u: goto label_801D83F4;
    case 0x801D83F8u: goto label_801D83F8;
    case 0x801D83FCu: goto label_801D83FC;
    case 0x801D8400u: goto label_801D8400;
    case 0x801D8404u: goto label_801D8404;
    case 0x801D8408u: goto label_801D8408;
    case 0x801D840Cu: goto label_801D840C;
    case 0x801D8410u: goto label_801D8410;
    case 0x801D8414u: goto label_801D8414;
    case 0x801D8418u: goto label_801D8418;
    case 0x801D841Cu: goto label_801D841C;
    case 0x801D8420u: goto label_801D8420;
    case 0x801D8424u: goto label_801D8424;
    case 0x801D8428u: goto label_801D8428;
    case 0x801D842Cu: goto label_801D842C;
    case 0x801D8430u: goto label_801D8430;
    case 0x801D8434u: goto label_801D8434;
    case 0x801D8438u: goto label_801D8438;
    case 0x801D843Cu: goto label_801D843C;
    case 0x801D8440u: goto label_801D8440;
    case 0x801D8444u: goto label_801D8444;
    case 0x801D8448u: goto label_801D8448;
    case 0x801D844Cu: goto label_801D844C;
    case 0x801D8450u: goto label_801D8450;
    case 0x801D8454u: goto label_801D8454;
    case 0x801D8458u: goto label_801D8458;
    case 0x801D845Cu: goto label_801D845C;
    case 0x801D8460u: goto label_801D8460;
    case 0x801D8464u: goto label_801D8464;
    case 0x801D8468u: goto label_801D8468;
    case 0x801D846Cu: goto label_801D846C;
    case 0x801D8470u: goto label_801D8470;
    case 0x801D8474u: goto label_801D8474;
    case 0x801D8478u: goto label_801D8478;
    case 0x801D847Cu: goto label_801D847C;
    case 0x801D8480u: goto label_801D8480;
    case 0x801D8484u: goto label_801D8484;
    case 0x801D8488u: goto label_801D8488;
    case 0x801D848Cu: goto label_801D848C;
    case 0x801D8490u: goto label_801D8490;
    case 0x801D8494u: goto label_801D8494;
    case 0x801D8498u: goto label_801D8498;
    case 0x801D849Cu: goto label_801D849C;
    case 0x801D84A0u: goto label_801D84A0;
    case 0x801D84A4u: goto label_801D84A4;
    case 0x801D84A8u: goto label_801D84A8;
    case 0x801D84ACu: goto label_801D84AC;
    case 0x801D84B0u: goto label_801D84B0;
    case 0x801D84B4u: goto label_801D84B4;
    case 0x801D84B8u: goto label_801D84B8;
    case 0x801D84BCu: goto label_801D84BC;
    case 0x801D84C0u: goto label_801D84C0;
    case 0x801D84C4u: goto label_801D84C4;
    case 0x801D84C8u: goto label_801D84C8;
    case 0x801D84CCu: goto label_801D84CC;
    case 0x801D84D0u: goto label_801D84D0;
    case 0x801D84D4u: goto label_801D84D4;
    case 0x801D84D8u: goto label_801D84D8;
    case 0x801D84DCu: goto label_801D84DC;
    case 0x801D84E0u: goto label_801D84E0;
    case 0x801D84E4u: goto label_801D84E4;
    case 0x801D84E8u: goto label_801D84E8;
    case 0x801D84ECu: goto label_801D84EC;
    case 0x801D84F0u: goto label_801D84F0;
    case 0x801D84F4u: goto label_801D84F4;
    case 0x801D84F8u: goto label_801D84F8;
    case 0x801D84FCu: goto label_801D84FC;
    case 0x801D8500u: goto label_801D8500;
    case 0x801D8504u: goto label_801D8504;
    case 0x801D8508u: goto label_801D8508;
    case 0x801D850Cu: goto label_801D850C;
    case 0x801D8510u: goto label_801D8510;
    case 0x801D8514u: goto label_801D8514;
    case 0x801D8518u: goto label_801D8518;
    case 0x801D851Cu: goto label_801D851C;
    case 0x801D8520u: goto label_801D8520;
    case 0x801D8524u: goto label_801D8524;
    case 0x801D8528u: goto label_801D8528;
    case 0x801D852Cu: goto label_801D852C;
    case 0x801D8530u: goto label_801D8530;
    case 0x801D8534u: goto label_801D8534;
    case 0x801D8538u: goto label_801D8538;
    case 0x801D853Cu: goto label_801D853C;
    case 0x801D8540u: goto label_801D8540;
    case 0x801D8544u: goto label_801D8544;
    case 0x801D8548u: goto label_801D8548;
    case 0x801D854Cu: goto label_801D854C;
    case 0x801D8550u: goto label_801D8550;
    case 0x801D8554u: goto label_801D8554;
    case 0x801D8558u: goto label_801D8558;
    case 0x801D855Cu: goto label_801D855C;
    case 0x801D8560u: goto label_801D8560;
    case 0x801D8564u: goto label_801D8564;
    case 0x801D8568u: goto label_801D8568;
    case 0x801D856Cu: goto label_801D856C;
    case 0x801D8570u: goto label_801D8570;
    case 0x801D8574u: goto label_801D8574;
    case 0x801D8578u: goto label_801D8578;
    case 0x801D857Cu: goto label_801D857C;
    case 0x801D8580u: goto label_801D8580;
    case 0x801D8584u: goto label_801D8584;
    case 0x801D8588u: goto label_801D8588;
    case 0x801D858Cu: goto label_801D858C;
    case 0x801D8590u: goto label_801D8590;
    case 0x801D8594u: goto label_801D8594;
    case 0x801D8598u: goto label_801D8598;
    case 0x801D859Cu: goto label_801D859C;
    case 0x801D85A0u: goto label_801D85A0;
    case 0x801D85A4u: goto label_801D85A4;
    case 0x801D85A8u: goto label_801D85A8;
    case 0x801D85ACu: goto label_801D85AC;
    case 0x801D85B0u: goto label_801D85B0;
    case 0x801D85B4u: goto label_801D85B4;
    case 0x801D85B8u: goto label_801D85B8;
    case 0x801D85BCu: goto label_801D85BC;
    case 0x801D85C0u: goto label_801D85C0;
    case 0x801D85C4u: goto label_801D85C4;
    case 0x801D85C8u: goto label_801D85C8;
    case 0x801D85CCu: goto label_801D85CC;
    case 0x801D85D0u: goto label_801D85D0;
    case 0x801D85D4u: goto label_801D85D4;
    case 0x801D85D8u: goto label_801D85D8;
    case 0x801D85DCu: goto label_801D85DC;
    case 0x801D85E0u: goto label_801D85E0;
    case 0x801D85E4u: goto label_801D85E4;
    case 0x801D85E8u: goto label_801D85E8;
    case 0x801D85ECu: goto label_801D85EC;
    case 0x801D85F0u: goto label_801D85F0;
    case 0x801D85F4u: goto label_801D85F4;
    case 0x801D85F8u: goto label_801D85F8;
    case 0x801D85FCu: goto label_801D85FC;
    case 0x801D8600u: goto label_801D8600;
    case 0x801D8604u: goto label_801D8604;
    case 0x801D8608u: goto label_801D8608;
    case 0x801D860Cu: goto label_801D860C;
    case 0x801D8610u: goto label_801D8610;
    case 0x801D8614u: goto label_801D8614;
    case 0x801D8618u: goto label_801D8618;
    case 0x801D861Cu: goto label_801D861C;
    case 0x801D8620u: goto label_801D8620;
    case 0x801D8624u: goto label_801D8624;
    case 0x801D8628u: goto label_801D8628;
    case 0x801D862Cu: goto label_801D862C;
    case 0x801D8630u: goto label_801D8630;
    case 0x801D8634u: goto label_801D8634;
    case 0x801D8638u: goto label_801D8638;
    case 0x801D863Cu: goto label_801D863C;
    case 0x801D8640u: goto label_801D8640;
    case 0x801D8644u: goto label_801D8644;
    case 0x801D8648u: goto label_801D8648;
    case 0x801D864Cu: goto label_801D864C;
    case 0x801D8650u: goto label_801D8650;
    case 0x801D8654u: goto label_801D8654;
    case 0x801D8658u: goto label_801D8658;
    case 0x801D865Cu: goto label_801D865C;
    case 0x801D8660u: goto label_801D8660;
    case 0x801D8664u: goto label_801D8664;
    case 0x801D8668u: goto label_801D8668;
    case 0x801D866Cu: goto label_801D866C;
    case 0x801D8670u: goto label_801D8670;
    case 0x801D8674u: goto label_801D8674;
    case 0x801D8678u: goto label_801D8678;
    case 0x801D867Cu: goto label_801D867C;
    case 0x801D8680u: goto label_801D8680;
    case 0x801D8684u: goto label_801D8684;
    case 0x801D8688u: goto label_801D8688;
    case 0x801D868Cu: goto label_801D868C;
    case 0x801D8690u: goto label_801D8690;
    case 0x801D8694u: goto label_801D8694;
    case 0x801D8698u: goto label_801D8698;
    case 0x801D869Cu: goto label_801D869C;
    case 0x801D86A0u: goto label_801D86A0;
    case 0x801D86A4u: goto label_801D86A4;
    case 0x801D86A8u: goto label_801D86A8;
    case 0x801D86ACu: goto label_801D86AC;
    case 0x801D86B0u: goto label_801D86B0;
    case 0x801D86B4u: goto label_801D86B4;
    case 0x801D86B8u: goto label_801D86B8;
    case 0x801D86BCu: goto label_801D86BC;
    case 0x801D86C0u: goto label_801D86C0;
    case 0x801D86C4u: goto label_801D86C4;
    case 0x801D86C8u: goto label_801D86C8;
    case 0x801D86CCu: goto label_801D86CC;
    case 0x801D86D0u: goto label_801D86D0;
    case 0x801D86D4u: goto label_801D86D4;
    case 0x801D86D8u: goto label_801D86D8;
    case 0x801D86DCu: goto label_801D86DC;
    case 0x801D86E0u: goto label_801D86E0;
    case 0x801D86E4u: goto label_801D86E4;
    case 0x801D86E8u: goto label_801D86E8;
    case 0x801D86ECu: goto label_801D86EC;
    case 0x801D86F0u: goto label_801D86F0;
    case 0x801D86F4u: goto label_801D86F4;
    case 0x801D86F8u: goto label_801D86F8;
    case 0x801D86FCu: goto label_801D86FC;
    case 0x801D8700u: goto label_801D8700;
    case 0x801D8704u: goto label_801D8704;
    case 0x801D8708u: goto label_801D8708;
    case 0x801D870Cu: goto label_801D870C;
    case 0x801D8710u: goto label_801D8710;
    case 0x801D8714u: goto label_801D8714;
    case 0x801D8718u: goto label_801D8718;
    case 0x801D871Cu: goto label_801D871C;
    case 0x801D8720u: goto label_801D8720;
    case 0x801D8724u: goto label_801D8724;
    case 0x801D8728u: goto label_801D8728;
    case 0x801D872Cu: goto label_801D872C;
    case 0x801D8730u: goto label_801D8730;
    case 0x801D8734u: goto label_801D8734;
    case 0x801D8738u: goto label_801D8738;
    case 0x801D873Cu: goto label_801D873C;
    case 0x801D8740u: goto label_801D8740;
    case 0x801D8744u: goto label_801D8744;
    case 0x801D8748u: goto label_801D8748;
    case 0x801D874Cu: goto label_801D874C;
    case 0x801D8750u: goto label_801D8750;
    case 0x801D8754u: goto label_801D8754;
    case 0x801D8758u: goto label_801D8758;
    case 0x801D875Cu: goto label_801D875C;
    case 0x801D8760u: goto label_801D8760;
    case 0x801D8764u: goto label_801D8764;
    case 0x801D8768u: goto label_801D8768;
    case 0x801D876Cu: goto label_801D876C;
    case 0x801D8770u: goto label_801D8770;
    case 0x801D8774u: goto label_801D8774;
    case 0x801D8778u: goto label_801D8778;
    case 0x801D877Cu: goto label_801D877C;
    case 0x801D8780u: goto label_801D8780;
    case 0x801D8784u: goto label_801D8784;
    case 0x801D8788u: goto label_801D8788;
    case 0x801D878Cu: goto label_801D878C;
    case 0x801D8790u: goto label_801D8790;
    case 0x801D8794u: goto label_801D8794;
    case 0x801D8798u: goto label_801D8798;
    case 0x801D879Cu: goto label_801D879C;
    case 0x801D87A0u: goto label_801D87A0;
    case 0x801D87A4u: goto label_801D87A4;
    case 0x801D87A8u: goto label_801D87A8;
    case 0x801D87ACu: goto label_801D87AC;
    case 0x801D87B0u: goto label_801D87B0;
    case 0x801D87B4u: goto label_801D87B4;
    case 0x801D87B8u: goto label_801D87B8;
    case 0x801D87BCu: goto label_801D87BC;
    case 0x801D87C0u: goto label_801D87C0;
    case 0x801D87C4u: goto label_801D87C4;
    case 0x801D87C8u: goto label_801D87C8;
    case 0x801D87CCu: goto label_801D87CC;
    case 0x801D87D0u: goto label_801D87D0;
    case 0x801D87D4u: goto label_801D87D4;
    case 0x801D87D8u: goto label_801D87D8;
    case 0x801D87DCu: goto label_801D87DC;
    case 0x801D87E0u: goto label_801D87E0;
    case 0x801D87E4u: goto label_801D87E4;
    case 0x801D87E8u: goto label_801D87E8;
    case 0x801D87ECu: goto label_801D87EC;
    case 0x801D87F0u: goto label_801D87F0;
    case 0x801D87F4u: goto label_801D87F4;
    case 0x801D87F8u: goto label_801D87F8;
    case 0x801D87FCu: goto label_801D87FC;
    case 0x801D8800u: goto label_801D8800;
    case 0x801D8804u: goto label_801D8804;
    case 0x801D8808u: goto label_801D8808;
    case 0x801D880Cu: goto label_801D880C;
    case 0x801D8810u: goto label_801D8810;
    case 0x801D8814u: goto label_801D8814;
    case 0x801D8818u: goto label_801D8818;
    case 0x801D881Cu: goto label_801D881C;
    case 0x801D8820u: goto label_801D8820;
    case 0x801D8824u: goto label_801D8824;
    case 0x801D8828u: goto label_801D8828;
    case 0x801D882Cu: goto label_801D882C;
    case 0x801D8830u: goto label_801D8830;
    case 0x801D8834u: goto label_801D8834;
    case 0x801D8838u: goto label_801D8838;
    case 0x801D883Cu: goto label_801D883C;
    case 0x801D8840u: goto label_801D8840;
    case 0x801D8844u: goto label_801D8844;
    case 0x801D8848u: goto label_801D8848;
    case 0x801D884Cu: goto label_801D884C;
    case 0x801D8850u: goto label_801D8850;
    case 0x801D8854u: goto label_801D8854;
    case 0x801D8858u: goto label_801D8858;
    case 0x801D885Cu: goto label_801D885C;
    case 0x801D8860u: goto label_801D8860;
    case 0x801D8864u: goto label_801D8864;
    case 0x801D8868u: goto label_801D8868;
    case 0x801D886Cu: goto label_801D886C;
    case 0x801D8870u: goto label_801D8870;
    case 0x801D8874u: goto label_801D8874;
    case 0x801D8878u: goto label_801D8878;
    case 0x801D887Cu: goto label_801D887C;
    case 0x801D8880u: goto label_801D8880;
    case 0x801D8884u: goto label_801D8884;
    case 0x801D8888u: goto label_801D8888;
    case 0x801D888Cu: goto label_801D888C;
    case 0x801D8890u: goto label_801D8890;
    case 0x801D8894u: goto label_801D8894;
    case 0x801D8898u: goto label_801D8898;
    case 0x801D889Cu: goto label_801D889C;
    case 0x801D88A0u: goto label_801D88A0;
    case 0x801D88A4u: goto label_801D88A4;
    case 0x801D88A8u: goto label_801D88A8;
    case 0x801D88ACu: goto label_801D88AC;
    case 0x801D88B0u: goto label_801D88B0;
    case 0x801D88B4u: goto label_801D88B4;
    case 0x801D88B8u: goto label_801D88B8;
    case 0x801D88BCu: goto label_801D88BC;
    case 0x801D88C0u: goto label_801D88C0;
    case 0x801D88C4u: goto label_801D88C4;
    case 0x801D88C8u: goto label_801D88C8;
    case 0x801D88CCu: goto label_801D88CC;
    case 0x801D88D0u: goto label_801D88D0;
    case 0x801D88D4u: goto label_801D88D4;
    case 0x801D88D8u: goto label_801D88D8;
    case 0x801D88DCu: goto label_801D88DC;
    case 0x801D88E0u: goto label_801D88E0;
    case 0x801D88E4u: goto label_801D88E4;
    case 0x801D88E8u: goto label_801D88E8;
    case 0x801D88ECu: goto label_801D88EC;
    case 0x801D88F0u: goto label_801D88F0;
    case 0x801D88F4u: goto label_801D88F4;
    case 0x801D88F8u: goto label_801D88F8;
    case 0x801D88FCu: goto label_801D88FC;
    case 0x801D8900u: goto label_801D8900;
    case 0x801D8904u: goto label_801D8904;
    case 0x801D8908u: goto label_801D8908;
    case 0x801D890Cu: goto label_801D890C;
    case 0x801D8910u: goto label_801D8910;
    case 0x801D8914u: goto label_801D8914;
    case 0x801D8918u: goto label_801D8918;
    case 0x801D891Cu: goto label_801D891C;
    case 0x801D8920u: goto label_801D8920;
    case 0x801D8924u: goto label_801D8924;
    case 0x801D8928u: goto label_801D8928;
    case 0x801D892Cu: goto label_801D892C;
    case 0x801D8930u: goto label_801D8930;
    case 0x801D8934u: goto label_801D8934;
    case 0x801D8938u: goto label_801D8938;
    case 0x801D893Cu: goto label_801D893C;
    case 0x801D8940u: goto label_801D8940;
    case 0x801D8944u: goto label_801D8944;
    case 0x801D8948u: goto label_801D8948;
    case 0x801D894Cu: goto label_801D894C;
    case 0x801D8950u: goto label_801D8950;
    case 0x801D8954u: goto label_801D8954;
    case 0x801D8958u: goto label_801D8958;
    case 0x801D895Cu: goto label_801D895C;
    case 0x801D8960u: goto label_801D8960;
    case 0x801D8964u: goto label_801D8964;
    case 0x801D8968u: goto label_801D8968;
    case 0x801D896Cu: goto label_801D896C;
    case 0x801D8970u: goto label_801D8970;
    case 0x801D8974u: goto label_801D8974;
    case 0x801D8978u: goto label_801D8978;
    case 0x801D897Cu: goto label_801D897C;
    case 0x801D8980u: goto label_801D8980;
    case 0x801D8984u: goto label_801D8984;
    case 0x801D8988u: goto label_801D8988;
    case 0x801D898Cu: goto label_801D898C;
    case 0x801D8990u: goto label_801D8990;
    case 0x801D8994u: goto label_801D8994;
    case 0x801D8998u: goto label_801D8998;
    case 0x801D899Cu: goto label_801D899C;
    case 0x801D89A0u: goto label_801D89A0;
    case 0x801D89A4u: goto label_801D89A4;
    case 0x801D89A8u: goto label_801D89A8;
    case 0x801D89ACu: goto label_801D89AC;
    case 0x801D89B0u: goto label_801D89B0;
    case 0x801D89B4u: goto label_801D89B4;
    case 0x801D89B8u: goto label_801D89B8;
    case 0x801D89BCu: goto label_801D89BC;
    case 0x801D89C0u: goto label_801D89C0;
    case 0x801D89C4u: goto label_801D89C4;
    case 0x801D89C8u: goto label_801D89C8;
    case 0x801D89CCu: goto label_801D89CC;
    case 0x801D89D0u: goto label_801D89D0;
    case 0x801D89D4u: goto label_801D89D4;
    case 0x801D89D8u: goto label_801D89D8;
    case 0x801D89DCu: goto label_801D89DC;
    case 0x801D89E0u: goto label_801D89E0;
    case 0x801D89E4u: goto label_801D89E4;
    case 0x801D89E8u: goto label_801D89E8;
    case 0x801D89ECu: goto label_801D89EC;
    case 0x801D89F0u: goto label_801D89F0;
    case 0x801D89F4u: goto label_801D89F4;
    case 0x801D89F8u: goto label_801D89F8;
    case 0x801D89FCu: goto label_801D89FC;
    case 0x801D8A00u: goto label_801D8A00;
    case 0x801D8A04u: goto label_801D8A04;
    case 0x801D8A08u: goto label_801D8A08;
    case 0x801D8A0Cu: goto label_801D8A0C;
    case 0x801D8A10u: goto label_801D8A10;
    case 0x801D8A14u: goto label_801D8A14;
    case 0x801D8A18u: goto label_801D8A18;
    case 0x801D8A1Cu: goto label_801D8A1C;
    case 0x801D8A20u: goto label_801D8A20;
    case 0x801D8A24u: goto label_801D8A24;
    case 0x801D8A28u: goto label_801D8A28;
    case 0x801D8A2Cu: goto label_801D8A2C;
    case 0x801D8A30u: goto label_801D8A30;
    case 0x801D8A34u: goto label_801D8A34;
    case 0x801D8A38u: goto label_801D8A38;
    case 0x801D8A3Cu: goto label_801D8A3C;
    case 0x801D8A40u: goto label_801D8A40;
    case 0x801D8A44u: goto label_801D8A44;
    case 0x801D8A48u: goto label_801D8A48;
    case 0x801D8A4Cu: goto label_801D8A4C;
    case 0x801D8A50u: goto label_801D8A50;
    case 0x801D8A54u: goto label_801D8A54;
    case 0x801D8A58u: goto label_801D8A58;
    case 0x801D8A5Cu: goto label_801D8A5C;
    case 0x801D8A60u: goto label_801D8A60;
    case 0x801D8A64u: goto label_801D8A64;
    case 0x801D8A68u: goto label_801D8A68;
    case 0x801D8A6Cu: goto label_801D8A6C;
    case 0x801D8A70u: goto label_801D8A70;
    case 0x801D8A74u: goto label_801D8A74;
    case 0x801D8A78u: goto label_801D8A78;
    case 0x801D8A7Cu: goto label_801D8A7C;
    case 0x801D8A80u: goto label_801D8A80;
    case 0x801D8A84u: goto label_801D8A84;
    case 0x801D8A88u: goto label_801D8A88;
    case 0x801D8A8Cu: goto label_801D8A8C;
    case 0x801D8A90u: goto label_801D8A90;
    case 0x801D8A94u: goto label_801D8A94;
    case 0x801D8A98u: goto label_801D8A98;
    case 0x801D8A9Cu: goto label_801D8A9C;
    case 0x801D8AA0u: goto label_801D8AA0;
    case 0x801D8AA4u: goto label_801D8AA4;
    case 0x801D8AA8u: goto label_801D8AA8;
    case 0x801D8AACu: goto label_801D8AAC;
    case 0x801D8AB0u: goto label_801D8AB0;
    case 0x801D8AB4u: goto label_801D8AB4;
    case 0x801D8AB8u: goto label_801D8AB8;
    case 0x801D8ABCu: goto label_801D8ABC;
    case 0x801D8AC0u: goto label_801D8AC0;
    case 0x801D8AC4u: goto label_801D8AC4;
    case 0x801D8AC8u: goto label_801D8AC8;
    case 0x801D8ACCu: goto label_801D8ACC;
    case 0x801D8AD0u: goto label_801D8AD0;
    case 0x801D8AD4u: goto label_801D8AD4;
    case 0x801D8AD8u: goto label_801D8AD8;
    case 0x801D8ADCu: goto label_801D8ADC;
    case 0x801D8AE0u: goto label_801D8AE0;
    case 0x801D8AE4u: goto label_801D8AE4;
    case 0x801D8AE8u: goto label_801D8AE8;
    case 0x801D8AECu: goto label_801D8AEC;
    case 0x801D8AF0u: goto label_801D8AF0;
    case 0x801D8AF4u: goto label_801D8AF4;
    case 0x801D8AF8u: goto label_801D8AF8;
    case 0x801D8AFCu: goto label_801D8AFC;
    case 0x801D8B00u: goto label_801D8B00;
    case 0x801D8B04u: goto label_801D8B04;
    case 0x801D8B08u: goto label_801D8B08;
    case 0x801D8B0Cu: goto label_801D8B0C;
    case 0x801D8B10u: goto label_801D8B10;
    case 0x801D8B14u: goto label_801D8B14;
    case 0x801D8B18u: goto label_801D8B18;
    case 0x801D8B1Cu: goto label_801D8B1C;
    case 0x801D8B20u: goto label_801D8B20;
    case 0x801D8B24u: goto label_801D8B24;
    case 0x801D8B28u: goto label_801D8B28;
    case 0x801D8B2Cu: goto label_801D8B2C;
    case 0x801D8B30u: goto label_801D8B30;
    case 0x801D8B34u: goto label_801D8B34;
    case 0x801D8B38u: goto label_801D8B38;
    case 0x801D8B3Cu: goto label_801D8B3C;
    case 0x801D8B40u: goto label_801D8B40;
    case 0x801D8B44u: goto label_801D8B44;
    case 0x801D8B48u: goto label_801D8B48;
    case 0x801D8B4Cu: goto label_801D8B4C;
    case 0x801D8B50u: goto label_801D8B50;
    case 0x801D8B54u: goto label_801D8B54;
    case 0x801D8B58u: goto label_801D8B58;
    case 0x801D8B5Cu: goto label_801D8B5C;
    case 0x801D8B60u: goto label_801D8B60;
    case 0x801D8B64u: goto label_801D8B64;
    case 0x801D8B68u: goto label_801D8B68;
    case 0x801D8B6Cu: goto label_801D8B6C;
    case 0x801D8B70u: goto label_801D8B70;
    case 0x801D8B74u: goto label_801D8B74;
    case 0x801D8B78u: goto label_801D8B78;
    case 0x801D8B7Cu: goto label_801D8B7C;
    case 0x801D8B80u: goto label_801D8B80;
    case 0x801D8B84u: goto label_801D8B84;
    case 0x801D8B88u: goto label_801D8B88;
    case 0x801D8B8Cu: goto label_801D8B8C;
    case 0x801D8B90u: goto label_801D8B90;
    case 0x801D8B94u: goto label_801D8B94;
    case 0x801D8B98u: goto label_801D8B98;
    case 0x801D8B9Cu: goto label_801D8B9C;
    case 0x801D8BA0u: goto label_801D8BA0;
    case 0x801D8BA4u: goto label_801D8BA4;
    case 0x801D8BA8u: goto label_801D8BA8;
    case 0x801D8BACu: goto label_801D8BAC;
    case 0x801D8BB0u: goto label_801D8BB0;
    case 0x801D8BB4u: goto label_801D8BB4;
    case 0x801D8BB8u: goto label_801D8BB8;
    case 0x801D8BBCu: goto label_801D8BBC;
    case 0x801D8BC0u: goto label_801D8BC0;
    case 0x801D8BC4u: goto label_801D8BC4;
    case 0x801D8BC8u: goto label_801D8BC8;
    case 0x801D8BCCu: goto label_801D8BCC;
    case 0x801D8BD0u: goto label_801D8BD0;
    case 0x801D8BD4u: goto label_801D8BD4;
    case 0x801D8BD8u: goto label_801D8BD8;
    case 0x801D8BDCu: goto label_801D8BDC;
    case 0x801D8BE0u: goto label_801D8BE0;
    case 0x801D8BE4u: goto label_801D8BE4;
    case 0x801D8BE8u: goto label_801D8BE8;
    case 0x801D8BECu: goto label_801D8BEC;
    case 0x801D8BF0u: goto label_801D8BF0;
    case 0x801D8BF4u: goto label_801D8BF4;
    case 0x801D8BF8u: goto label_801D8BF8;
    case 0x801D8BFCu: goto label_801D8BFC;
    case 0x801D8C00u: goto label_801D8C00;
    case 0x801D8C04u: goto label_801D8C04;
    case 0x801D8C08u: goto label_801D8C08;
    case 0x801D8C0Cu: goto label_801D8C0C;
    case 0x801D8C10u: goto label_801D8C10;
    case 0x801D8C14u: goto label_801D8C14;
    case 0x801D8C18u: goto label_801D8C18;
    case 0x801D8C1Cu: goto label_801D8C1C;
    case 0x801D8C20u: goto label_801D8C20;
    case 0x801D8C24u: goto label_801D8C24;
    case 0x801D8C28u: goto label_801D8C28;
    case 0x801D8C2Cu: goto label_801D8C2C;
    case 0x801D8C30u: goto label_801D8C30;
    case 0x801D8C34u: goto label_801D8C34;
    case 0x801D8C38u: goto label_801D8C38;
    case 0x801D8C3Cu: goto label_801D8C3C;
    case 0x801D8C40u: goto label_801D8C40;
    case 0x801D8C44u: goto label_801D8C44;
    case 0x801D8C48u: goto label_801D8C48;
    case 0x801D8C4Cu: goto label_801D8C4C;
    case 0x801D8C50u: goto label_801D8C50;
    case 0x801D8C54u: goto label_801D8C54;
    case 0x801D8C58u: goto label_801D8C58;
    case 0x801D8C5Cu: goto label_801D8C5C;
    case 0x801D8C60u: goto label_801D8C60;
    case 0x801D8C64u: goto label_801D8C64;
    case 0x801D8C68u: goto label_801D8C68;
    case 0x801D8C6Cu: goto label_801D8C6C;
    case 0x801D8C70u: goto label_801D8C70;
    case 0x801D8C74u: goto label_801D8C74;
    case 0x801D8C78u: goto label_801D8C78;
    case 0x801D8C7Cu: goto label_801D8C7C;
    case 0x801D8C80u: goto label_801D8C80;
    case 0x801D8C84u: goto label_801D8C84;
    case 0x801D8C88u: goto label_801D8C88;
    case 0x801D8C8Cu: goto label_801D8C8C;
    case 0x801D8C90u: goto label_801D8C90;
    case 0x801D8C94u: goto label_801D8C94;
    case 0x801D8C98u: goto label_801D8C98;
    case 0x801D8C9Cu: goto label_801D8C9C;
    case 0x801D8CA0u: goto label_801D8CA0;
    case 0x801D8CA4u: goto label_801D8CA4;
    case 0x801D8CA8u: goto label_801D8CA8;
    case 0x801D8CACu: goto label_801D8CAC;
    case 0x801D8CB0u: goto label_801D8CB0;
    case 0x801D8CB4u: goto label_801D8CB4;
    case 0x801D8CB8u: goto label_801D8CB8;
    case 0x801D8CBCu: goto label_801D8CBC;
    case 0x801D8CC0u: goto label_801D8CC0;
    case 0x801D8CC4u: goto label_801D8CC4;
    case 0x801D8CC8u: goto label_801D8CC8;
    case 0x801D8CCCu: goto label_801D8CCC;
    case 0x801D8CD0u: goto label_801D8CD0;
    case 0x801D8CD4u: goto label_801D8CD4;
    case 0x801D8CD8u: goto label_801D8CD8;
    case 0x801D8CDCu: goto label_801D8CDC;
    case 0x801D8CE0u: goto label_801D8CE0;
    case 0x801D8CE4u: goto label_801D8CE4;
    case 0x801D8CE8u: goto label_801D8CE8;
    case 0x801D8CECu: goto label_801D8CEC;
    case 0x801D8CF0u: goto label_801D8CF0;
    case 0x801D8CF4u: goto label_801D8CF4;
    case 0x801D8CF8u: goto label_801D8CF8;
    case 0x801D8CFCu: goto label_801D8CFC;
    case 0x801D8D00u: goto label_801D8D00;
    case 0x801D8D04u: goto label_801D8D04;
    case 0x801D8D08u: goto label_801D8D08;
    case 0x801D8D0Cu: goto label_801D8D0C;
    case 0x801D8D10u: goto label_801D8D10;
    case 0x801D8D14u: goto label_801D8D14;
    case 0x801D8D18u: goto label_801D8D18;
    case 0x801D8D1Cu: goto label_801D8D1C;
    case 0x801D8D20u: goto label_801D8D20;
    case 0x801D8D24u: goto label_801D8D24;
    case 0x801D8D28u: goto label_801D8D28;
    case 0x801D8D2Cu: goto label_801D8D2C;
    case 0x801D8D30u: goto label_801D8D30;
    case 0x801D8D34u: goto label_801D8D34;
    case 0x801D8D38u: goto label_801D8D38;
    case 0x801D8D3Cu: goto label_801D8D3C;
    case 0x801D8D40u: goto label_801D8D40;
    case 0x801D8D44u: goto label_801D8D44;
    case 0x801D8D48u: goto label_801D8D48;
    case 0x801D8D4Cu: goto label_801D8D4C;
    case 0x801D8D50u: goto label_801D8D50;
    case 0x801D8D54u: goto label_801D8D54;
    case 0x801D8D58u: goto label_801D8D58;
    case 0x801D8D5Cu: goto label_801D8D5C;
    case 0x801D8D60u: goto label_801D8D60;
    case 0x801D8D64u: goto label_801D8D64;
    case 0x801D8D68u: goto label_801D8D68;
    case 0x801D8D6Cu: goto label_801D8D6C;
    case 0x801D8D70u: goto label_801D8D70;
    case 0x801D8D74u: goto label_801D8D74;
    case 0x801D8D78u: goto label_801D8D78;
    case 0x801D8D7Cu: goto label_801D8D7C;
    case 0x801D8D80u: goto label_801D8D80;
    case 0x801D8D84u: goto label_801D8D84;
    case 0x801D8D88u: goto label_801D8D88;
    case 0x801D8D8Cu: goto label_801D8D8C;
    case 0x801D8D90u: goto label_801D8D90;
    case 0x801D8D94u: goto label_801D8D94;
    case 0x801D8D98u: goto label_801D8D98;
    case 0x801D8D9Cu: goto label_801D8D9C;
    case 0x801D8DA0u: goto label_801D8DA0;
    case 0x801D8DA4u: goto label_801D8DA4;
    case 0x801D8DA8u: goto label_801D8DA8;
    case 0x801D8DACu: goto label_801D8DAC;
    case 0x801D8DB0u: goto label_801D8DB0;
    case 0x801D8DB4u: goto label_801D8DB4;
    case 0x801D8DB8u: goto label_801D8DB8;
    case 0x801D8DBCu: goto label_801D8DBC;
    case 0x801D8DC0u: goto label_801D8DC0;
    case 0x801D8DC4u: goto label_801D8DC4;
    case 0x801D8DC8u: goto label_801D8DC8;
    case 0x801D8DCCu: goto label_801D8DCC;
    case 0x801D8DD0u: goto label_801D8DD0;
    case 0x801D8DD4u: goto label_801D8DD4;
    case 0x801D8DD8u: goto label_801D8DD8;
    case 0x801D8DDCu: goto label_801D8DDC;
    case 0x801D8DE0u: goto label_801D8DE0;
    case 0x801D8DE4u: goto label_801D8DE4;
    case 0x801D8DE8u: goto label_801D8DE8;
    case 0x801D8DECu: goto label_801D8DEC;
    case 0x801D8DF0u: goto label_801D8DF0;
    case 0x801D8DF4u: goto label_801D8DF4;
    case 0x801D8DF8u: goto label_801D8DF8;
    case 0x801D8DFCu: goto label_801D8DFC;
    case 0x801D8E00u: goto label_801D8E00;
    case 0x801D8E04u: goto label_801D8E04;
    case 0x801D8E08u: goto label_801D8E08;
    case 0x801D8E0Cu: goto label_801D8E0C;
    case 0x801D8E10u: goto label_801D8E10;
    case 0x801D8E14u: goto label_801D8E14;
    case 0x801D8E18u: goto label_801D8E18;
    case 0x801D8E1Cu: goto label_801D8E1C;
    case 0x801D8E20u: goto label_801D8E20;
    case 0x801D8E24u: goto label_801D8E24;
    case 0x801D8E28u: goto label_801D8E28;
    case 0x801D8E2Cu: goto label_801D8E2C;
    case 0x801D8E30u: goto label_801D8E30;
    case 0x801D8E34u: goto label_801D8E34;
    case 0x801D8E38u: goto label_801D8E38;
    case 0x801D8E3Cu: goto label_801D8E3C;
    case 0x801D8E40u: goto label_801D8E40;
    case 0x801D8E44u: goto label_801D8E44;
    case 0x801D8E48u: goto label_801D8E48;
    case 0x801D8E4Cu: goto label_801D8E4C;
    case 0x801D8E50u: goto label_801D8E50;
    case 0x801D8E54u: goto label_801D8E54;
    case 0x801D8E58u: goto label_801D8E58;
    case 0x801D8E5Cu: goto label_801D8E5C;
    case 0x801D8E60u: goto label_801D8E60;
    case 0x801D8E64u: goto label_801D8E64;
    case 0x801D8E68u: goto label_801D8E68;
    case 0x801D8E6Cu: goto label_801D8E6C;
    case 0x801D8E70u: goto label_801D8E70;
    case 0x801D8E74u: goto label_801D8E74;
    case 0x801D8E78u: goto label_801D8E78;
    case 0x801D8E7Cu: goto label_801D8E7C;
    case 0x801D8E80u: goto label_801D8E80;
    case 0x801D8E84u: goto label_801D8E84;
    case 0x801D8E88u: goto label_801D8E88;
    case 0x801D8E8Cu: goto label_801D8E8C;
    case 0x801D8E90u: goto label_801D8E90;
    case 0x801D8E94u: goto label_801D8E94;
    case 0x801D8E98u: goto label_801D8E98;
    case 0x801D8E9Cu: goto label_801D8E9C;
    case 0x801D8EA0u: goto label_801D8EA0;
    case 0x801D8EA4u: goto label_801D8EA4;
    case 0x801D8EA8u: goto label_801D8EA8;
    case 0x801D8EACu: goto label_801D8EAC;
    case 0x801D8EB0u: goto label_801D8EB0;
    case 0x801D8EB4u: goto label_801D8EB4;
    case 0x801D8EB8u: goto label_801D8EB8;
    case 0x801D8EBCu: goto label_801D8EBC;
    case 0x801D8EC0u: goto label_801D8EC0;
    case 0x801D8EC4u: goto label_801D8EC4;
    case 0x801D8EC8u: goto label_801D8EC8;
    case 0x801D8ECCu: goto label_801D8ECC;
    case 0x801D8ED0u: goto label_801D8ED0;
    case 0x801D8ED4u: goto label_801D8ED4;
    case 0x801D8ED8u: goto label_801D8ED8;
    case 0x801D8EDCu: goto label_801D8EDC;
    case 0x801D8EE0u: goto label_801D8EE0;
    case 0x801D8EE4u: goto label_801D8EE4;
    case 0x801D8EE8u: goto label_801D8EE8;
    case 0x801D8EECu: goto label_801D8EEC;
    case 0x801D8EF0u: goto label_801D8EF0;
    case 0x801D8EF4u: goto label_801D8EF4;
    case 0x801D8EF8u: goto label_801D8EF8;
    case 0x801D8EFCu: goto label_801D8EFC;
    case 0x801D8F00u: goto label_801D8F00;
    case 0x801D8F04u: goto label_801D8F04;
    case 0x801D8F08u: goto label_801D8F08;
    case 0x801D8F0Cu: goto label_801D8F0C;
    case 0x801D8F10u: goto label_801D8F10;
    case 0x801D8F14u: goto label_801D8F14;
    case 0x801D8F18u: goto label_801D8F18;
    case 0x801D8F1Cu: goto label_801D8F1C;
    case 0x801D8F20u: goto label_801D8F20;
    case 0x801D8F24u: goto label_801D8F24;
    case 0x801D8F28u: goto label_801D8F28;
    case 0x801D8F2Cu: goto label_801D8F2C;
    case 0x801D8F30u: goto label_801D8F30;
    case 0x801D8F34u: goto label_801D8F34;
    case 0x801D8F38u: goto label_801D8F38;
    case 0x801D8F3Cu: goto label_801D8F3C;
    case 0x801D8F40u: goto label_801D8F40;
    case 0x801D8F44u: goto label_801D8F44;
    case 0x801D8F48u: goto label_801D8F48;
    case 0x801D8F4Cu: goto label_801D8F4C;
    case 0x801D8F50u: goto label_801D8F50;
    case 0x801D8F54u: goto label_801D8F54;
    case 0x801D8F58u: goto label_801D8F58;
    case 0x801D8F5Cu: goto label_801D8F5C;
    case 0x801D8F60u: goto label_801D8F60;
    case 0x801D8F64u: goto label_801D8F64;
    case 0x801D8F68u: goto label_801D8F68;
    case 0x801D8F6Cu: goto label_801D8F6C;
    case 0x801D8F70u: goto label_801D8F70;
    case 0x801D8F74u: goto label_801D8F74;
    case 0x801D8F78u: goto label_801D8F78;
    case 0x801D8F7Cu: goto label_801D8F7C;
    case 0x801D8F80u: goto label_801D8F80;
    case 0x801D8F84u: goto label_801D8F84;
    case 0x801D8F88u: goto label_801D8F88;
    case 0x801D8F8Cu: goto label_801D8F8C;
    case 0x801D8F90u: goto label_801D8F90;
    case 0x801D8F94u: goto label_801D8F94;
    case 0x801D8F98u: goto label_801D8F98;
    case 0x801D8F9Cu: goto label_801D8F9C;
    case 0x801D8FA0u: goto label_801D8FA0;
    case 0x801D8FA4u: goto label_801D8FA4;
    case 0x801D8FA8u: goto label_801D8FA8;
    case 0x801D8FACu: goto label_801D8FAC;
    case 0x801D8FB0u: goto label_801D8FB0;
    case 0x801D8FB4u: goto label_801D8FB4;
    case 0x801D8FB8u: goto label_801D8FB8;
    case 0x801D8FBCu: goto label_801D8FBC;
    case 0x801D8FC0u: goto label_801D8FC0;
    case 0x801D8FC4u: goto label_801D8FC4;
    case 0x801D8FC8u: goto label_801D8FC8;
    case 0x801D8FCCu: goto label_801D8FCC;
    case 0x801D8FD0u: goto label_801D8FD0;
    case 0x801D8FD4u: goto label_801D8FD4;
    case 0x801D8FD8u: goto label_801D8FD8;
    case 0x801D8FDCu: goto label_801D8FDC;
    case 0x801D8FE0u: goto label_801D8FE0;
    case 0x801D8FE4u: goto label_801D8FE4;
    case 0x801D8FE8u: goto label_801D8FE8;
    case 0x801D8FECu: goto label_801D8FEC;
    case 0x801D8FF0u: goto label_801D8FF0;
    case 0x801D8FF4u: goto label_801D8FF4;
    case 0x801D8FF8u: goto label_801D8FF8;
    case 0x801D8FFCu: goto label_801D8FFC;
    case 0x801D9000u: goto label_801D9000;
    case 0x801D9004u: goto label_801D9004;
    case 0x801D9008u: goto label_801D9008;
    case 0x801D900Cu: goto label_801D900C;
    case 0x801D9010u: goto label_801D9010;
    case 0x801D9014u: goto label_801D9014;
    case 0x801D9018u: goto label_801D9018;
    case 0x801D901Cu: goto label_801D901C;
    case 0x801D9020u: goto label_801D9020;
    case 0x801D9024u: goto label_801D9024;
    case 0x801D9028u: goto label_801D9028;
    case 0x801D902Cu: goto label_801D902C;
    case 0x801D9030u: goto label_801D9030;
    case 0x801D9034u: goto label_801D9034;
    case 0x801D9038u: goto label_801D9038;
    case 0x801D903Cu: goto label_801D903C;
    case 0x801D9040u: goto label_801D9040;
    case 0x801D9044u: goto label_801D9044;
    case 0x801D9048u: goto label_801D9048;
    case 0x801D904Cu: goto label_801D904C;
    case 0x801D9050u: goto label_801D9050;
    case 0x801D9054u: goto label_801D9054;
    case 0x801D9058u: goto label_801D9058;
    case 0x801D905Cu: goto label_801D905C;
    case 0x801D9060u: goto label_801D9060;
    case 0x801D9064u: goto label_801D9064;
    case 0x801D9068u: goto label_801D9068;
    case 0x801D906Cu: goto label_801D906C;
    case 0x801D9070u: goto label_801D9070;
    case 0x801D9074u: goto label_801D9074;
    case 0x801D9078u: goto label_801D9078;
    case 0x801D907Cu: goto label_801D907C;
    case 0x801D9080u: goto label_801D9080;
    case 0x801D9084u: goto label_801D9084;
    case 0x801D9088u: goto label_801D9088;
    case 0x801D908Cu: goto label_801D908C;
    case 0x801D9090u: goto label_801D9090;
    case 0x801D9094u: goto label_801D9094;
    case 0x801D9098u: goto label_801D9098;
    case 0x801D909Cu: goto label_801D909C;
    case 0x801D90A0u: goto label_801D90A0;
    case 0x801D90A4u: goto label_801D90A4;
    case 0x801D90A8u: goto label_801D90A8;
    case 0x801D90ACu: goto label_801D90AC;
    case 0x801D90B0u: goto label_801D90B0;
    case 0x801D90B4u: goto label_801D90B4;
    case 0x801D90B8u: goto label_801D90B8;
    case 0x801D90BCu: goto label_801D90BC;
    case 0x801D90C0u: goto label_801D90C0;
    case 0x801D90C4u: goto label_801D90C4;
    case 0x801D90C8u: goto label_801D90C8;
    case 0x801D90CCu: goto label_801D90CC;
    case 0x801D90D0u: goto label_801D90D0;
    case 0x801D90D4u: goto label_801D90D4;
    case 0x801D90D8u: goto label_801D90D8;
    case 0x801D90DCu: goto label_801D90DC;
    case 0x801D90E0u: goto label_801D90E0;
    case 0x801D90E4u: goto label_801D90E4;
    case 0x801D90E8u: goto label_801D90E8;
    case 0x801D90ECu: goto label_801D90EC;
    case 0x801D90F0u: goto label_801D90F0;
    case 0x801D90F4u: goto label_801D90F4;
    case 0x801D90F8u: goto label_801D90F8;
    case 0x801D90FCu: goto label_801D90FC;
    case 0x801D9100u: goto label_801D9100;
    case 0x801D9104u: goto label_801D9104;
    case 0x801D9108u: goto label_801D9108;
    case 0x801D910Cu: goto label_801D910C;
    case 0x801D9110u: goto label_801D9110;
    case 0x801D9114u: goto label_801D9114;
    case 0x801D9118u: goto label_801D9118;
    case 0x801D911Cu: goto label_801D911C;
    case 0x801D9120u: goto label_801D9120;
    case 0x801D9124u: goto label_801D9124;
    case 0x801D9128u: goto label_801D9128;
    case 0x801D912Cu: goto label_801D912C;
    case 0x801D9130u: goto label_801D9130;
    case 0x801D9134u: goto label_801D9134;
    case 0x801D9138u: goto label_801D9138;
    case 0x801D913Cu: goto label_801D913C;
    case 0x801D9140u: goto label_801D9140;
    case 0x801D9144u: goto label_801D9144;
    case 0x801D9148u: goto label_801D9148;
    case 0x801D914Cu: goto label_801D914C;
    case 0x801D9150u: goto label_801D9150;
    case 0x801D9154u: goto label_801D9154;
    case 0x801D9158u: goto label_801D9158;
    case 0x801D915Cu: goto label_801D915C;
    case 0x801D9160u: goto label_801D9160;
    case 0x801D9164u: goto label_801D9164;
    case 0x801D9168u: goto label_801D9168;
    case 0x801D916Cu: goto label_801D916C;
    case 0x801D9170u: goto label_801D9170;
    case 0x801D9174u: goto label_801D9174;
    case 0x801D9178u: goto label_801D9178;
    case 0x801D917Cu: goto label_801D917C;
    case 0x801D9180u: goto label_801D9180;
    case 0x801D9184u: goto label_801D9184;
    case 0x801D9188u: goto label_801D9188;
    case 0x801D918Cu: goto label_801D918C;
    case 0x801D9190u: goto label_801D9190;
    case 0x801D9194u: goto label_801D9194;
    case 0x801D9198u: goto label_801D9198;
    case 0x801D919Cu: goto label_801D919C;
    case 0x801D91A0u: goto label_801D91A0;
    case 0x801D91A4u: goto label_801D91A4;
    case 0x801D91A8u: goto label_801D91A8;
    case 0x801D91ACu: goto label_801D91AC;
    case 0x801D91B0u: goto label_801D91B0;
    case 0x801D91B4u: goto label_801D91B4;
    case 0x801D91B8u: goto label_801D91B8;
    case 0x801D91BCu: goto label_801D91BC;
    case 0x801D91C0u: goto label_801D91C0;
    case 0x801D91C4u: goto label_801D91C4;
    case 0x801D91C8u: goto label_801D91C8;
    case 0x801D91CCu: goto label_801D91CC;
    case 0x801D91D0u: goto label_801D91D0;
    case 0x801D91D4u: goto label_801D91D4;
    case 0x801D91D8u: goto label_801D91D8;
    case 0x801D91DCu: goto label_801D91DC;
    case 0x801D91E0u: goto label_801D91E0;
    case 0x801D91E4u: goto label_801D91E4;
    case 0x801D91E8u: goto label_801D91E8;
    case 0x801D91ECu: goto label_801D91EC;
    case 0x801D91F0u: goto label_801D91F0;
    case 0x801D91F4u: goto label_801D91F4;
    case 0x801D91F8u: goto label_801D91F8;
    case 0x801D91FCu: goto label_801D91FC;
    case 0x801D9200u: goto label_801D9200;
    case 0x801D9204u: goto label_801D9204;
    case 0x801D9208u: goto label_801D9208;
    case 0x801D920Cu: goto label_801D920C;
    case 0x801D9210u: goto label_801D9210;
    case 0x801D9214u: goto label_801D9214;
    case 0x801D9218u: goto label_801D9218;
    case 0x801D921Cu: goto label_801D921C;
    case 0x801D9220u: goto label_801D9220;
    case 0x801D9224u: goto label_801D9224;
    case 0x801D9228u: goto label_801D9228;
    case 0x801D922Cu: goto label_801D922C;
    case 0x801D9230u: goto label_801D9230;
    case 0x801D9234u: goto label_801D9234;
    case 0x801D9238u: goto label_801D9238;
    case 0x801D923Cu: goto label_801D923C;
    case 0x801D9240u: goto label_801D9240;
    case 0x801D9244u: goto label_801D9244;
    case 0x801D9248u: goto label_801D9248;
    case 0x801D924Cu: goto label_801D924C;
    case 0x801D9250u: goto label_801D9250;
    case 0x801D9254u: goto label_801D9254;
    case 0x801D9258u: goto label_801D9258;
    case 0x801D925Cu: goto label_801D925C;
    case 0x801D9260u: goto label_801D9260;
    case 0x801D9264u: goto label_801D9264;
    case 0x801D9268u: goto label_801D9268;
    case 0x801D926Cu: goto label_801D926C;
    case 0x801D9270u: goto label_801D9270;
    case 0x801D9274u: goto label_801D9274;
    case 0x801D9278u: goto label_801D9278;
    case 0x801D927Cu: goto label_801D927C;
    case 0x801D9280u: goto label_801D9280;
    case 0x801D9284u: goto label_801D9284;
    case 0x801D9288u: goto label_801D9288;
    case 0x801D928Cu: goto label_801D928C;
    case 0x801D9290u: goto label_801D9290;
    case 0x801D9294u: goto label_801D9294;
    case 0x801D9298u: goto label_801D9298;
    case 0x801D929Cu: goto label_801D929C;
    case 0x801D92A0u: goto label_801D92A0;
    case 0x801D92A4u: goto label_801D92A4;
    case 0x801D92A8u: goto label_801D92A8;
    case 0x801D92ACu: goto label_801D92AC;
    case 0x801D92B0u: goto label_801D92B0;
    case 0x801D92B4u: goto label_801D92B4;
    case 0x801D92B8u: goto label_801D92B8;
    case 0x801D92BCu: goto label_801D92BC;
    case 0x801D92C0u: goto label_801D92C0;
    case 0x801D92C4u: goto label_801D92C4;
    case 0x801D92C8u: goto label_801D92C8;
    case 0x801D92CCu: goto label_801D92CC;
    case 0x801D92D0u: goto label_801D92D0;
    case 0x801D92D4u: goto label_801D92D4;
    case 0x801D92D8u: goto label_801D92D8;
    case 0x801D92DCu: goto label_801D92DC;
    case 0x801D92E0u: goto label_801D92E0;
    case 0x801D92E4u: goto label_801D92E4;
    case 0x801D92E8u: goto label_801D92E8;
    case 0x801D92ECu: goto label_801D92EC;
    case 0x801D92F0u: goto label_801D92F0;
    case 0x801D92F4u: goto label_801D92F4;
    case 0x801D92F8u: goto label_801D92F8;
    case 0x801D92FCu: goto label_801D92FC;
    case 0x801D9300u: goto label_801D9300;
    case 0x801D9304u: goto label_801D9304;
    case 0x801D9308u: goto label_801D9308;
    case 0x801D930Cu: goto label_801D930C;
    case 0x801D9310u: goto label_801D9310;
    case 0x801D9314u: goto label_801D9314;
    case 0x801D9318u: goto label_801D9318;
    case 0x801D931Cu: goto label_801D931C;
    case 0x801D9320u: goto label_801D9320;
    case 0x801D9324u: goto label_801D9324;
    case 0x801D9328u: goto label_801D9328;
    case 0x801D932Cu: goto label_801D932C;
    case 0x801D9330u: goto label_801D9330;
    case 0x801D9334u: goto label_801D9334;
    case 0x801D9338u: goto label_801D9338;
    case 0x801D933Cu: goto label_801D933C;
    case 0x801D9340u: goto label_801D9340;
    case 0x801D9344u: goto label_801D9344;
    case 0x801D9348u: goto label_801D9348;
    case 0x801D934Cu: goto label_801D934C;
    case 0x801D9350u: goto label_801D9350;
    case 0x801D9354u: goto label_801D9354;
    case 0x801D9358u: goto label_801D9358;
    case 0x801D935Cu: goto label_801D935C;
    case 0x801D9360u: goto label_801D9360;
    case 0x801D9364u: goto label_801D9364;
    case 0x801D9368u: goto label_801D9368;
    case 0x801D936Cu: goto label_801D936C;
    case 0x801D9370u: goto label_801D9370;
    case 0x801D9374u: goto label_801D9374;
    case 0x801D9378u: goto label_801D9378;
    case 0x801D937Cu: goto label_801D937C;
    case 0x801D9380u: goto label_801D9380;
    case 0x801D9384u: goto label_801D9384;
    case 0x801D9388u: goto label_801D9388;
    case 0x801D938Cu: goto label_801D938C;
    case 0x801D9390u: goto label_801D9390;
    case 0x801D9394u: goto label_801D9394;
    case 0x801D9398u: goto label_801D9398;
    case 0x801D939Cu: goto label_801D939C;
    case 0x801D93A0u: goto label_801D93A0;
    case 0x801D93A4u: goto label_801D93A4;
    case 0x801D93A8u: goto label_801D93A8;
    case 0x801D93ACu: goto label_801D93AC;
    case 0x801D93B0u: goto label_801D93B0;
    case 0x801D93B4u: goto label_801D93B4;
    case 0x801D93B8u: goto label_801D93B8;
    case 0x801D93BCu: goto label_801D93BC;
    case 0x801D93C0u: goto label_801D93C0;
    case 0x801D93C4u: goto label_801D93C4;
    case 0x801D93C8u: goto label_801D93C8;
    case 0x801D93CCu: goto label_801D93CC;
    case 0x801D93D0u: goto label_801D93D0;
    case 0x801D93D4u: goto label_801D93D4;
    case 0x801D93D8u: goto label_801D93D8;
    case 0x801D93DCu: goto label_801D93DC;
    case 0x801D93E0u: goto label_801D93E0;
    case 0x801D93E4u: goto label_801D93E4;
    case 0x801D93E8u: goto label_801D93E8;
    case 0x801D93ECu: goto label_801D93EC;
    case 0x801D93F0u: goto label_801D93F0;
    case 0x801D93F4u: goto label_801D93F4;
    case 0x801D93F8u: goto label_801D93F8;
    case 0x801D93FCu: goto label_801D93FC;
    case 0x801D9400u: goto label_801D9400;
    case 0x801D9404u: goto label_801D9404;
    case 0x801D9408u: goto label_801D9408;
    case 0x801D940Cu: goto label_801D940C;
    case 0x801D9410u: goto label_801D9410;
    case 0x801D9414u: goto label_801D9414;
    case 0x801D9418u: goto label_801D9418;
    case 0x801D941Cu: goto label_801D941C;
    case 0x801D9420u: goto label_801D9420;
    case 0x801D9424u: goto label_801D9424;
    case 0x801D9428u: goto label_801D9428;
    case 0x801D942Cu: goto label_801D942C;
    case 0x801D9430u: goto label_801D9430;
    case 0x801D9434u: goto label_801D9434;
    case 0x801D9438u: goto label_801D9438;
    case 0x801D943Cu: goto label_801D943C;
    case 0x801D9440u: goto label_801D9440;
    case 0x801D9444u: goto label_801D9444;
    case 0x801D9448u: goto label_801D9448;
    case 0x801D944Cu: goto label_801D944C;
    case 0x801D9450u: goto label_801D9450;
    case 0x801D9454u: goto label_801D9454;
    case 0x801D9458u: goto label_801D9458;
    case 0x801D945Cu: goto label_801D945C;
    case 0x801D9460u: goto label_801D9460;
    case 0x801D9464u: goto label_801D9464;
    case 0x801D9468u: goto label_801D9468;
    case 0x801D946Cu: goto label_801D946C;
    case 0x801D9470u: goto label_801D9470;
    case 0x801D9474u: goto label_801D9474;
    case 0x801D9478u: goto label_801D9478;
    case 0x801D947Cu: goto label_801D947C;
    case 0x801D9480u: goto label_801D9480;
    case 0x801D9484u: goto label_801D9484;
    case 0x801D9488u: goto label_801D9488;
    case 0x801D948Cu: goto label_801D948C;
    case 0x801D9490u: goto label_801D9490;
    case 0x801D9494u: goto label_801D9494;
    case 0x801D9498u: goto label_801D9498;
    case 0x801D949Cu: goto label_801D949C;
    case 0x801D94A0u: goto label_801D94A0;
    case 0x801D94A4u: goto label_801D94A4;
    case 0x801D94A8u: goto label_801D94A8;
    case 0x801D94ACu: goto label_801D94AC;
    case 0x801D94B0u: goto label_801D94B0;
    case 0x801D94B4u: goto label_801D94B4;
    case 0x801D94B8u: goto label_801D94B8;
    case 0x801D94BCu: goto label_801D94BC;
    case 0x801D94C0u: goto label_801D94C0;
    case 0x801D94C4u: goto label_801D94C4;
    case 0x801D94C8u: goto label_801D94C8;
    case 0x801D94CCu: goto label_801D94CC;
    case 0x801D94D0u: goto label_801D94D0;
    case 0x801D94D4u: goto label_801D94D4;
    case 0x801D94D8u: goto label_801D94D8;
    case 0x801D94DCu: goto label_801D94DC;
    case 0x801D94E0u: goto label_801D94E0;
    case 0x801D94E4u: goto label_801D94E4;
    case 0x801D94E8u: goto label_801D94E8;
    case 0x801D94ECu: goto label_801D94EC;
    case 0x801D94F0u: goto label_801D94F0;
    case 0x801D94F4u: goto label_801D94F4;
    case 0x801D94F8u: goto label_801D94F8;
    case 0x801D94FCu: goto label_801D94FC;
    case 0x801D9500u: goto label_801D9500;
    case 0x801D9504u: goto label_801D9504;
    case 0x801D9508u: goto label_801D9508;
    case 0x801D950Cu: goto label_801D950C;
    case 0x801D9510u: goto label_801D9510;
    case 0x801D9514u: goto label_801D9514;
    case 0x801D9518u: goto label_801D9518;
    case 0x801D951Cu: goto label_801D951C;
    case 0x801D9520u: goto label_801D9520;
    case 0x801D9524u: goto label_801D9524;
    case 0x801D9528u: goto label_801D9528;
    case 0x801D952Cu: goto label_801D952C;
    case 0x801D9530u: goto label_801D9530;
    case 0x801D9534u: goto label_801D9534;
    case 0x801D9538u: goto label_801D9538;
    case 0x801D953Cu: goto label_801D953C;
    case 0x801D9540u: goto label_801D9540;
    case 0x801D9544u: goto label_801D9544;
    case 0x801D9548u: goto label_801D9548;
    case 0x801D954Cu: goto label_801D954C;
    case 0x801D9550u: goto label_801D9550;
    case 0x801D9554u: goto label_801D9554;
    case 0x801D9558u: goto label_801D9558;
    case 0x801D955Cu: goto label_801D955C;
    case 0x801D9560u: goto label_801D9560;
    case 0x801D9564u: goto label_801D9564;
    case 0x801D9568u: goto label_801D9568;
    case 0x801D956Cu: goto label_801D956C;
    case 0x801D9570u: goto label_801D9570;
    case 0x801D9574u: goto label_801D9574;
    case 0x801D9578u: goto label_801D9578;
    case 0x801D957Cu: goto label_801D957C;
    case 0x801D9580u: goto label_801D9580;
    case 0x801D9584u: goto label_801D9584;
    case 0x801D9588u: goto label_801D9588;
    case 0x801D958Cu: goto label_801D958C;
    case 0x801D9590u: goto label_801D9590;
    case 0x801D9594u: goto label_801D9594;
    case 0x801D9598u: goto label_801D9598;
    case 0x801D959Cu: goto label_801D959C;
    case 0x801D95A0u: goto label_801D95A0;
    case 0x801D95A4u: goto label_801D95A4;
    case 0x801D95A8u: goto label_801D95A8;
    case 0x801D95ACu: goto label_801D95AC;
    case 0x801D95B0u: goto label_801D95B0;
    case 0x801D95B4u: goto label_801D95B4;
    case 0x801D95B8u: goto label_801D95B8;
    case 0x801D95BCu: goto label_801D95BC;
    case 0x801D95C0u: goto label_801D95C0;
    case 0x801D95C4u: goto label_801D95C4;
    case 0x801D95C8u: goto label_801D95C8;
    case 0x801D95CCu: goto label_801D95CC;
    case 0x801D95D0u: goto label_801D95D0;
    case 0x801D95D4u: goto label_801D95D4;
    case 0x801D95D8u: goto label_801D95D8;
    case 0x801D95DCu: goto label_801D95DC;
    case 0x801D95E0u: goto label_801D95E0;
    case 0x801D95E4u: goto label_801D95E4;
    case 0x801D95E8u: goto label_801D95E8;
    case 0x801D95ECu: goto label_801D95EC;
    case 0x801D95F0u: goto label_801D95F0;
    case 0x801D95F4u: goto label_801D95F4;
    case 0x801D95F8u: goto label_801D95F8;
    case 0x801D95FCu: goto label_801D95FC;
    case 0x801D9600u: goto label_801D9600;
    case 0x801D9604u: goto label_801D9604;
    case 0x801D9608u: goto label_801D9608;
    case 0x801D960Cu: goto label_801D960C;
    case 0x801D9610u: goto label_801D9610;
    case 0x801D9614u: goto label_801D9614;
    case 0x801D9618u: goto label_801D9618;
    case 0x801D961Cu: goto label_801D961C;
    case 0x801D9620u: goto label_801D9620;
    case 0x801D9624u: goto label_801D9624;
    case 0x801D9628u: goto label_801D9628;
    case 0x801D962Cu: goto label_801D962C;
    case 0x801D9630u: goto label_801D9630;
    case 0x801D9634u: goto label_801D9634;
    case 0x801D9638u: goto label_801D9638;
    case 0x801D963Cu: goto label_801D963C;
    case 0x801D9640u: goto label_801D9640;
    case 0x801D9644u: goto label_801D9644;
    case 0x801D9648u: goto label_801D9648;
    case 0x801D964Cu: goto label_801D964C;
    case 0x801D9650u: goto label_801D9650;
    case 0x801D9654u: goto label_801D9654;
    case 0x801D9658u: goto label_801D9658;
    case 0x801D965Cu: goto label_801D965C;
    case 0x801D9660u: goto label_801D9660;
    case 0x801D9664u: goto label_801D9664;
    case 0x801D9668u: goto label_801D9668;
    case 0x801D966Cu: goto label_801D966C;
    case 0x801D9670u: goto label_801D9670;
    case 0x801D9674u: goto label_801D9674;
    case 0x801D9678u: goto label_801D9678;
    case 0x801D967Cu: goto label_801D967C;
    case 0x801D9680u: goto label_801D9680;
    case 0x801D9684u: goto label_801D9684;
    case 0x801D9688u: goto label_801D9688;
    case 0x801D968Cu: goto label_801D968C;
    case 0x801D9690u: goto label_801D9690;
    case 0x801D9694u: goto label_801D9694;
    case 0x801D9698u: goto label_801D9698;
    case 0x801D969Cu: goto label_801D969C;
    case 0x801D96A0u: goto label_801D96A0;
    case 0x801D96A4u: goto label_801D96A4;
    case 0x801D96A8u: goto label_801D96A8;
    case 0x801D96ACu: goto label_801D96AC;
    case 0x801D96B0u: goto label_801D96B0;
    case 0x801D96B4u: goto label_801D96B4;
    case 0x801D96B8u: goto label_801D96B8;
    case 0x801D96BCu: goto label_801D96BC;
    case 0x801D96C0u: goto label_801D96C0;
    case 0x801D96C4u: goto label_801D96C4;
    case 0x801D96C8u: goto label_801D96C8;
    case 0x801D96CCu: goto label_801D96CC;
    case 0x801D96D0u: goto label_801D96D0;
    case 0x801D96D4u: goto label_801D96D4;
    case 0x801D96D8u: goto label_801D96D8;
    case 0x801D96DCu: goto label_801D96DC;
    case 0x801D96E0u: goto label_801D96E0;
    case 0x801D96E4u: goto label_801D96E4;
    case 0x801D96E8u: goto label_801D96E8;
    case 0x801D96ECu: goto label_801D96EC;
    case 0x801D96F0u: goto label_801D96F0;
    case 0x801D96F4u: goto label_801D96F4;
    case 0x801D96F8u: goto label_801D96F8;
    case 0x801D96FCu: goto label_801D96FC;
    case 0x801D9700u: goto label_801D9700;
    case 0x801D9704u: goto label_801D9704;
    case 0x801D9708u: goto label_801D9708;
    case 0x801D970Cu: goto label_801D970C;
    case 0x801D9710u: goto label_801D9710;
    case 0x801D9714u: goto label_801D9714;
    case 0x801D9718u: goto label_801D9718;
    case 0x801D971Cu: goto label_801D971C;
    case 0x801D9720u: goto label_801D9720;
    case 0x801D9724u: goto label_801D9724;
    case 0x801D9728u: goto label_801D9728;
    case 0x801D972Cu: goto label_801D972C;
    case 0x801D9730u: goto label_801D9730;
    case 0x801D9734u: goto label_801D9734;
    case 0x801D9738u: goto label_801D9738;
    case 0x801D973Cu: goto label_801D973C;
    case 0x801D9740u: goto label_801D9740;
    case 0x801D9744u: goto label_801D9744;
    case 0x801D9748u: goto label_801D9748;
    case 0x801D974Cu: goto label_801D974C;
    case 0x801D9750u: goto label_801D9750;
    case 0x801D9754u: goto label_801D9754;
    case 0x801D9758u: goto label_801D9758;
    case 0x801D975Cu: goto label_801D975C;
    case 0x801D9760u: goto label_801D9760;
    case 0x801D9764u: goto label_801D9764;
    case 0x801D9768u: goto label_801D9768;
    case 0x801D976Cu: goto label_801D976C;
    case 0x801D9770u: goto label_801D9770;
    case 0x801D9774u: goto label_801D9774;
    case 0x801D9778u: goto label_801D9778;
    case 0x801D977Cu: goto label_801D977C;
    case 0x801D9780u: goto label_801D9780;
    case 0x801D9784u: goto label_801D9784;
    case 0x801D9788u: goto label_801D9788;
    case 0x801D978Cu: goto label_801D978C;
    case 0x801D9790u: goto label_801D9790;
    case 0x801D9794u: goto label_801D9794;
    case 0x801D9798u: goto label_801D9798;
    case 0x801D979Cu: goto label_801D979C;
    case 0x801D97A0u: goto label_801D97A0;
    case 0x801D97A4u: goto label_801D97A4;
    case 0x801D97A8u: goto label_801D97A8;
    case 0x801D97ACu: goto label_801D97AC;
    case 0x801D97B0u: goto label_801D97B0;
    case 0x801D97B4u: goto label_801D97B4;
    case 0x801D97B8u: goto label_801D97B8;
    case 0x801D97BCu: goto label_801D97BC;
    case 0x801D97C0u: goto label_801D97C0;
    case 0x801D97C4u: goto label_801D97C4;
    case 0x801D97C8u: goto label_801D97C8;
    case 0x801D97CCu: goto label_801D97CC;
    case 0x801D97D0u: goto label_801D97D0;
    case 0x801D97D4u: goto label_801D97D4;
    case 0x801D97D8u: goto label_801D97D8;
    case 0x801D97DCu: goto label_801D97DC;
    default: return;
    }
label_801D72C0:
    ctx->pc = 0x801D72C0u;
    ctx->downcount -= 6;
    // 801D72C0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D72C4:
    ctx->pc = 0x801D72C4u;
    // 801D72C4: stw     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D72C8:
    ctx->pc = 0x801D72C8u;
    // 801D72C8: stw     r9, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D72CC:
    ctx->pc = 0x801D72CCu;
    // 801D72CC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D72D0:
    ctx->pc = 0x801D72D0u;
    // 801D72D0: cmpwi   r9, 0
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

label_801D72D4:
    ctx->pc = 0x801D72D4u;
    // 801D72D4: bc    12, 2, 0x801D72E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D72E0;
        }
    }

label_801D72D8:
    ctx->pc = 0x801D72D8u;
    ctx->downcount -= 2;
    // 801D72D8: stw     r4, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D72DC:
    ctx->pc = 0x801D72DCu;
    // 801D72DC: b       0x801D72E4
    {
            goto label_801D72E4;
    }

label_801D72E0:
    ctx->pc = 0x801D72E0u;
    ctx->downcount -= 1;
    // 801D72E0: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D72E4:
    ctx->pc = 0x801D72E4u;
    ctx->downcount -= 5;
    // 801D72E4: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D72E8:
    ctx->pc = 0x801D72E8u;
    // 801D72E8: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D72EC:
    ctx->pc = 0x801D72ECu;
    // 801D72EC: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D72F0:
    ctx->pc = 0x801D72F0u;
    // 801D72F0: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D72F4:
    ctx->pc = 0x801D72F4u;
    // 801D72F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D72F8:
    ctx->pc = 0x801D72F8u;
    ctx->downcount -= 20;
    // 801D72F8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D72FC:
    ctx->pc = 0x801D72FCu;
    // 801D72FC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7300:
    ctx->pc = 0x801D7300u;
    // 801D7300: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7304:
    ctx->pc = 0x801D7304u;
    // 801D7304: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7308:
    ctx->pc = 0x801D7308u;
    // 801D7308: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D730C:
    ctx->pc = 0x801D730Cu;
    // 801D730C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D7310:
    ctx->pc = 0x801D7310u;
    // 801D7310: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7314:
    ctx->pc = 0x801D7314u;
    // 801D7314: cmpwi   r4, 0
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

label_801D7318:
    ctx->pc = 0x801D7318u;
    // 801D7318: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D731C:
    ctx->pc = 0x801D731Cu;
    // 801D731C: bc    12, 2, 0x801D7358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7358;
        }
    }

label_801D7320:
    ctx->pc = 0x801D7320u;
    ctx->downcount -= 3;
    // 801D7320: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7324:
    ctx->pc = 0x801D7324u;
    // 801D7324: cmpwi   r30, 0
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

label_801D7328:
    ctx->pc = 0x801D7328u;
    // 801D7328: bc    12, 2, 0x801D7358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7358;
        }
    }

label_801D732C:
    ctx->pc = 0x801D732Cu;
    ctx->downcount -= 1;
    // 801D732C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D7330:
    ctx->pc = 0x801D7330u;
    ctx->downcount -= 8;
    // 801D7330: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7334:
    // 801D7334: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7338:
    ctx->pc = 0x801D7338u;
    // 801D7338: stw     r29, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D733C:
    // 801D733C: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D7340:
    ctx->pc = 0x801D7340u;
    // 801D7340: stw     r29, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7344:
    ctx->pc = 0x801D7344u;
    // 801D7344: stw     r29, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7348:
    // 801D7348: addi    r31, r31, 36
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(36);

label_801D734C:
    // 801D734C: bl      0x801D72B0
    {
            ctx->lr = 0x801D7350u;
            ctx->pc = 0x801D72B0u;
            return;
    }

label_801D7350:
    ctx->downcount -= 2;
    // 801D7350: addic.  r30, r30, -1
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

label_801D7354:
    // 801D7354: bc    4, 2, 0x801D7330
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7330u;
                return;
            }
            goto label_801D7330;
        }
    }

label_801D7358:
    ctx->pc = 0x801D7358u;
    ctx->downcount -= 16;
    // 801D7358: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D735C:
    ctx->pc = 0x801D735Cu;
    // 801D735C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7360:
    ctx->pc = 0x801D7360u;
    // 801D7360: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7364:
    ctx->pc = 0x801D7364u;
    // 801D7364: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7368:
    ctx->pc = 0x801D7368u;
    // 801D7368: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D736C:
    ctx->pc = 0x801D736Cu;
    ctx->downcount -= 29;
    // 801D736C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7370:
    ctx->pc = 0x801D7370u;
    // 801D7370: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7374:
    ctx->pc = 0x801D7374u;
    // 801D7374: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7378:
    ctx->pc = 0x801D7378u;
    // 801D7378: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D737C:
    ctx->pc = 0x801D737Cu;
    // 801D737C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7380:
    ctx->pc = 0x801D7380u;
    // 801D7380: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7384:
    ctx->pc = 0x801D7384u;
    // 801D7384: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D7388:
    ctx->pc = 0x801D7388u;
    // 801D7388: mulli   r4, r29, 36
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)36);

label_801D738C:
    ctx->pc = 0x801D738Cu;
    // 801D738C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7390:
    ctx->pc = 0x801D7390u;
    // 801D7390: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D7394:
    ctx->pc = 0x801D7394u;
    // 801D7394: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7398:
    ctx->pc = 0x801D7398u;
    // 801D7398: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D739C:
    ctx->pc = 0x801D739Cu;
    // 801D739C: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D73A0:
    ctx->pc = 0x801D73A0u;
    // 801D73A0: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D73A4:
    ctx->pc = 0x801D73A4u;
    // 801D73A4: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D73A8:
    ctx->pc = 0x801D73A8u;
    // 801D73A8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D73AC:
    ctx->pc = 0x801D73ACu;
    // 801D73AC: bl      0x80039640
    {
            ctx->lr = 0x801D73B0u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D73B0:
    ctx->pc = 0x801D73B0u;
    ctx->downcount -= 4;
    // 801D73B0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D73B4:
    ctx->pc = 0x801D73B4u;
    // 801D73B4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D73B8:
    ctx->pc = 0x801D73B8u;
    // 801D73B8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D73BC:
    ctx->pc = 0x801D73BCu;
    // 801D73BC: bl      0x801D72F8
    {
            ctx->lr = 0x801D73C0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D72F8u;
                return;
            }
            goto label_801D72F8;
    }

label_801D73C0:
    ctx->pc = 0x801D73C0u;
    ctx->downcount -= 16;
    // 801D73C0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D73C4:
    ctx->pc = 0x801D73C4u;
    // 801D73C4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D73C8:
    ctx->pc = 0x801D73C8u;
    // 801D73C8: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D73CC:
    ctx->pc = 0x801D73CCu;
    // 801D73CC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D73D0:
    ctx->pc = 0x801D73D0u;
    // 801D73D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D73D4:
    ctx->pc = 0x801D73D4u;
    ctx->downcount -= 16;
    // 801D73D4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D73D8:
    ctx->pc = 0x801D73D8u;
    // 801D73D8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D73DC:
    ctx->pc = 0x801D73DCu;
    // 801D73DC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D73E0:
    ctx->pc = 0x801D73E0u;
    // 801D73E0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D73E4:
    ctx->pc = 0x801D73E4u;
    // 801D73E4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D73E8:
    ctx->pc = 0x801D73E8u;
    // 801D73E8: bl      0x801D736C
    {
            ctx->lr = 0x801D73ECu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D736Cu;
                return;
            }
            goto label_801D736C;
    }

label_801D73EC:
    ctx->pc = 0x801D73ECu;
    ctx->downcount -= 5;
    // 801D73EC: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_801D73F0:
    ctx->pc = 0x801D73F0u;
    // 801D73F0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D73F4:
    ctx->pc = 0x801D73F4u;
    // 801D73F4: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D73F8:
    ctx->pc = 0x801D73F8u;
    // 801D73F8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D73FC:
    loop_801D73FC(ctx);
    if (ctx->pc == 0x801D7410u) goto label_801D7410;
    return;
label_801D7400:
    ctx->pc = 0x801D7400u;
    // 801D7400: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7404:
    ctx->pc = 0x801D7404u;
    // 801D7404: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7408:
    // 801D7408: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D740C:
    // 801D740C: bc    16, 0, 0x801D73FC
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D73FCu;
                return;
            }
            goto label_801D73FC;
        }
    }

label_801D7410:
    ctx->pc = 0x801D7410u;
    ctx->downcount -= 16;
    // 801D7410: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7414:
    ctx->pc = 0x801D7414u;
    // 801D7414: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7418:
    ctx->pc = 0x801D7418u;
    // 801D7418: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D741C:
    ctx->pc = 0x801D741Cu;
    // 801D741C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D7420:
    ctx->pc = 0x801D7420u;
    // 801D7420: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7424:
    ctx->pc = 0x801D7424u;
    ctx->downcount -= 4;
    // 801D7424: lwz     r9, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7428:
    ctx->pc = 0x801D7428u;
    // 801D7428: lwz     r10, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D742C:
    ctx->pc = 0x801D742Cu;
    // 801D742C: cmpwi   r9, 0
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

label_801D7430:
    ctx->pc = 0x801D7430u;
    // 801D7430: bc    12, 2, 0x801D743C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D743C;
        }
    }

label_801D7434:
    ctx->pc = 0x801D7434u;
    ctx->downcount -= 2;
    // 801D7434: stw     r10, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7438:
    ctx->pc = 0x801D7438u;
    // 801D7438: b       0x801D7444
    {
            goto label_801D7444;
    }

label_801D743C:
    ctx->pc = 0x801D743Cu;
    ctx->downcount -= 2;
    // 801D743C: lwz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7440:
    ctx->pc = 0x801D7440u;
    // 801D7440: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7444:
    ctx->pc = 0x801D7444u;
    ctx->downcount -= 3;
    // 801D7444: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7448:
    ctx->pc = 0x801D7448u;
    // 801D7448: cmpwi   r9, 0
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

label_801D744C:
    ctx->pc = 0x801D744Cu;
    // 801D744C: bc    12, 2, 0x801D745C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D745C;
        }
    }

label_801D7450:
    ctx->pc = 0x801D7450u;
    ctx->downcount -= 3;
    // 801D7450: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7454:
    ctx->pc = 0x801D7454u;
    // 801D7454: stw     r0, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7458:
    ctx->pc = 0x801D7458u;
    // 801D7458: b       0x801D7468
    {
            goto label_801D7468;
    }

label_801D745C:
    ctx->pc = 0x801D745Cu;
    ctx->downcount -= 3;
    // 801D745C: lwz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7460:
    ctx->pc = 0x801D7460u;
    // 801D7460: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7464:
    ctx->pc = 0x801D7464u;
    // 801D7464: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7468:
    ctx->pc = 0x801D7468u;
    ctx->downcount -= 6;
    // 801D7468: lwz     r11, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D746C:
    ctx->pc = 0x801D746Cu;
    // 801D746C: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D7470:
    ctx->pc = 0x801D7470u;
    // 801D7470: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7474:
    ctx->pc = 0x801D7474u;
    // 801D7474: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D7478:
    ctx->pc = 0x801D7478u;
    // 801D7478: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D747C:
    ctx->pc = 0x801D747Cu;
    // 801D747C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7480:
    ctx->pc = 0x801D7480u;
    ctx->downcount -= 21;
    // 801D7480: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7484:
    ctx->pc = 0x801D7484u;
    // 801D7484: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7488:
    ctx->pc = 0x801D7488u;
    // 801D7488: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D748C:
    ctx->pc = 0x801D748Cu;
    // 801D748C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7490:
    ctx->pc = 0x801D7490u;
    // 801D7490: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7494:
    ctx->pc = 0x801D7494u;
    // 801D7494: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D7498:
    ctx->pc = 0x801D7498u;
    // 801D7498: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D749C:
    ctx->pc = 0x801D749Cu;
    // 801D749C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D74A0:
    ctx->pc = 0x801D74A0u;
    // 801D74A0: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D74A4:
    ctx->pc = 0x801D74A4u;
    // 801D74A4: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D74A8:
    ctx->pc = 0x801D74A8u;
    // 801D74A8: bc    12, 18, 0x801D74E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D74E0;
        }
    }

label_801D74AC:
    ctx->pc = 0x801D74ACu;
    ctx->downcount -= 2;
    // 801D74AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D74B0:
    ctx->pc = 0x801D74B0u;
    // 801D74B0: bl      0x801D7424
    {
            ctx->lr = 0x801D74B4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7424u;
                return;
            }
            goto label_801D7424;
    }

label_801D74B4:
    ctx->pc = 0x801D74B4u;
    ctx->downcount -= 6;
    // 801D74B4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D74B8:
    ctx->pc = 0x801D74B8u;
    // 801D74B8: stw     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D74BC:
    ctx->pc = 0x801D74BCu;
    // 801D74BC: stw     r0, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D74C0:
    ctx->pc = 0x801D74C0u;
    // 801D74C0: stw     r0, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D74C4:
    ctx->pc = 0x801D74C4u;
    // 801D74C4: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D74C8:
    ctx->pc = 0x801D74C8u;
    // 801D74C8: bc    12, 18, 0x801D74E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D74E0;
        }
    }

label_801D74CC:
    ctx->pc = 0x801D74CCu;
    ctx->downcount -= 7;
    // 801D74CC: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D74D0:
    ctx->pc = 0x801D74D0u;
    // 801D74D0: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D74D4:
    ctx->pc = 0x801D74D4u;
    // 801D74D4: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D74D8:
    ctx->pc = 0x801D74D8u;
    // 801D74D8: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D74DC:
    ctx->pc = 0x801D74DCu;
    // 801D74DC: bl      0x801D72B0
    {
            ctx->lr = 0x801D74E0u;
            ctx->pc = 0x801D72B0u;
            return;
    }

label_801D74E0:
    ctx->pc = 0x801D74E0u;
    ctx->downcount -= 19;
    // 801D74E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D74E4:
    ctx->pc = 0x801D74E4u;
    // 801D74E4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D74E8:
    ctx->pc = 0x801D74E8u;
    // 801D74E8: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D74EC:
    ctx->pc = 0x801D74ECu;
    // 801D74EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D74F0:
    ctx->pc = 0x801D74F0u;
    // 801D74F0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D74F4:
    ctx->pc = 0x801D74F4u;
    // 801D74F4: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D74F8:
    ctx->pc = 0x801D74F8u;
    // 801D74F8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D74FC:
    ctx->pc = 0x801D74FCu;
    // 801D74FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7500:
    ctx->pc = 0x801D7500u;
    ctx->downcount -= 4;
    // 801D7500: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7504:
    ctx->pc = 0x801D7504u;
    // 801D7504: lwz     r10, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D7508:
    ctx->pc = 0x801D7508u;
    // 801D7508: cmpwi   r9, 0
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

label_801D750C:
    ctx->pc = 0x801D750Cu;
    // 801D750C: bc    12, 2, 0x801D7518
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7518;
        }
    }

label_801D7510:
    ctx->pc = 0x801D7510u;
    ctx->downcount -= 2;
    // 801D7510: stw     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7514:
    ctx->pc = 0x801D7514u;
    // 801D7514: b       0x801D7520
    {
            goto label_801D7520;
    }

label_801D7518:
    ctx->pc = 0x801D7518u;
    ctx->downcount -= 2;
    // 801D7518: lwz     r9, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D751C:
    ctx->pc = 0x801D751Cu;
    // 801D751C: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7520:
    ctx->pc = 0x801D7520u;
    ctx->downcount -= 3;
    // 801D7520: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7524:
    ctx->pc = 0x801D7524u;
    // 801D7524: cmpwi   r9, 0
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

label_801D7528:
    ctx->pc = 0x801D7528u;
    // 801D7528: bc    12, 2, 0x801D7538
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7538;
        }
    }

label_801D752C:
    ctx->pc = 0x801D752Cu;
    ctx->downcount -= 3;
    // 801D752C: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7530:
    ctx->pc = 0x801D7530u;
    // 801D7530: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7534:
    ctx->pc = 0x801D7534u;
    // 801D7534: b       0x801D7544
    {
            goto label_801D7544;
    }

label_801D7538:
    ctx->pc = 0x801D7538u;
    ctx->downcount -= 3;
    // 801D7538: lwz     r9, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D753C:
    ctx->pc = 0x801D753Cu;
    // 801D753C: lwz     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7540:
    ctx->pc = 0x801D7540u;
    // 801D7540: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7544:
    ctx->pc = 0x801D7544u;
    ctx->downcount -= 6;
    // 801D7544: lwz     r11, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D7548:
    ctx->pc = 0x801D7548u;
    // 801D7548: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D754C:
    ctx->pc = 0x801D754Cu;
    // 801D754C: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7550:
    ctx->pc = 0x801D7550u;
    // 801D7550: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D7554:
    ctx->pc = 0x801D7554u;
    // 801D7554: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7558:
    ctx->pc = 0x801D7558u;
    // 801D7558: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D755C:
    ctx->pc = 0x801D755Cu;
    ctx->downcount -= 2;
    // 801D755C: or.   r4, r4, r4
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

label_801D7560:
    ctx->pc = 0x801D7560u;
    // 801D7560: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7564:
    ctx->pc = 0x801D7564u;
    ctx->downcount -= 8;
    // 801D7564: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801D7568:
    ctx->pc = 0x801D7568u;
    // 801D7568: stw     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D756C:
    ctx->pc = 0x801D756Cu;
    // 801D756C: stw     r9, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7570:
    ctx->pc = 0x801D7570u;
    // 801D7570: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7574:
    ctx->pc = 0x801D7574u;
    // 801D7574: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7578:
    ctx->pc = 0x801D7578u;
    // 801D7578: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D757C:
    ctx->pc = 0x801D757Cu;
    // 801D757C: cmpwi   r9, 0
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

label_801D7580:
    ctx->pc = 0x801D7580u;
    // 801D7580: bc    12, 2, 0x801D758C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D758C;
        }
    }

label_801D7584:
    ctx->pc = 0x801D7584u;
    ctx->downcount -= 2;
    // 801D7584: stw     r4, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7588:
    ctx->pc = 0x801D7588u;
    // 801D7588: b       0x801D7590
    {
            goto label_801D7590;
    }

label_801D758C:
    ctx->pc = 0x801D758Cu;
    ctx->downcount -= 1;
    // 801D758C: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7590:
    ctx->pc = 0x801D7590u;
    ctx->downcount -= 5;
    // 801D7590: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7594:
    ctx->pc = 0x801D7594u;
    // 801D7594: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7598:
    ctx->pc = 0x801D7598u;
    // 801D7598: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D759C:
    ctx->pc = 0x801D759Cu;
    // 801D759C: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D75A0:
    ctx->pc = 0x801D75A0u;
    // 801D75A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D75A4:
    ctx->pc = 0x801D75A4u;
    ctx->downcount -= 2;
    // 801D75A4: or.   r4, r4, r4
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

label_801D75A8:
    ctx->pc = 0x801D75A8u;
    // 801D75A8: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D75AC:
    ctx->pc = 0x801D75ACu;
    ctx->downcount -= 8;
    // 801D75AC: stw     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D75B0:
    ctx->pc = 0x801D75B0u;
    // 801D75B0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D75B4:
    ctx->pc = 0x801D75B4u;
    // 801D75B4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D75B8:
    ctx->pc = 0x801D75B8u;
    // 801D75B8: stw     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D75BC:
    ctx->pc = 0x801D75BCu;
    // 801D75BC: stw     r9, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D75C0:
    ctx->pc = 0x801D75C0u;
    // 801D75C0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D75C4:
    ctx->pc = 0x801D75C4u;
    // 801D75C4: cmpwi   r9, 0
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

label_801D75C8:
    ctx->pc = 0x801D75C8u;
    // 801D75C8: bc    12, 2, 0x801D75D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D75D4;
        }
    }

label_801D75CC:
    ctx->pc = 0x801D75CCu;
    ctx->downcount -= 2;
    // 801D75CC: stw     r4, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D75D0:
    ctx->pc = 0x801D75D0u;
    // 801D75D0: b       0x801D75D8
    {
            goto label_801D75D8;
    }

label_801D75D4:
    ctx->pc = 0x801D75D4u;
    ctx->downcount -= 1;
    // 801D75D4: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D75D8:
    ctx->pc = 0x801D75D8u;
    ctx->downcount -= 5;
    // 801D75D8: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D75DC:
    ctx->pc = 0x801D75DCu;
    // 801D75DC: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D75E0:
    ctx->pc = 0x801D75E0u;
    // 801D75E0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D75E4:
    ctx->pc = 0x801D75E4u;
    // 801D75E4: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D75E8:
    ctx->pc = 0x801D75E8u;
    // 801D75E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D75EC:
    ctx->pc = 0x801D75ECu;
    ctx->downcount -= 20;
    // 801D75EC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D75F0:
    ctx->pc = 0x801D75F0u;
    // 801D75F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D75F4:
    ctx->pc = 0x801D75F4u;
    // 801D75F4: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D75F8:
    ctx->pc = 0x801D75F8u;
    // 801D75F8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D75FC:
    ctx->pc = 0x801D75FCu;
    // 801D75FC: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7600:
    ctx->pc = 0x801D7600u;
    // 801D7600: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D7604:
    ctx->pc = 0x801D7604u;
    // 801D7604: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7608:
    ctx->pc = 0x801D7608u;
    // 801D7608: cmpwi   r4, 0
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

label_801D760C:
    ctx->pc = 0x801D760Cu;
    // 801D760C: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D7610:
    ctx->pc = 0x801D7610u;
    // 801D7610: bc    12, 2, 0x801D764C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D764C;
        }
    }

label_801D7614:
    ctx->pc = 0x801D7614u;
    ctx->downcount -= 3;
    // 801D7614: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7618:
    ctx->pc = 0x801D7618u;
    // 801D7618: cmpwi   r30, 0
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

label_801D761C:
    ctx->pc = 0x801D761Cu;
    // 801D761C: bc    12, 2, 0x801D764C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D764C;
        }
    }

label_801D7620:
    ctx->pc = 0x801D7620u;
    ctx->downcount -= 1;
    // 801D7620: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D7624:
    ctx->pc = 0x801D7624u;
    ctx->downcount -= 8;
    // 801D7624: stw     r29, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7628:
    // 801D7628: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D762C:
    ctx->pc = 0x801D762Cu;
    // 801D762C: stw     r29, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7630:
    // 801D7630: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D7634:
    ctx->pc = 0x801D7634u;
    // 801D7634: stw     r29, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7638:
    ctx->pc = 0x801D7638u;
    // 801D7638: stw     r29, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D763C:
    // 801D763C: addi    r31, r31, 20
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(20);

label_801D7640:
    // 801D7640: bl      0x801D75A4
    {
            ctx->lr = 0x801D7644u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D75A4u;
                return;
            }
            goto label_801D75A4;
    }

label_801D7644:
    ctx->downcount -= 2;
    // 801D7644: addic.  r30, r30, -1
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

label_801D7648:
    // 801D7648: bc    4, 2, 0x801D7624
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7624u;
                return;
            }
            goto label_801D7624;
        }
    }

label_801D764C:
    ctx->pc = 0x801D764Cu;
    ctx->downcount -= 16;
    // 801D764C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7650:
    ctx->pc = 0x801D7650u;
    // 801D7650: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7654:
    ctx->pc = 0x801D7654u;
    // 801D7654: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7658:
    ctx->pc = 0x801D7658u;
    // 801D7658: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D765C:
    ctx->pc = 0x801D765Cu;
    // 801D765C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7660:
    ctx->pc = 0x801D7660u;
    ctx->downcount -= 29;
    // 801D7660: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7664:
    ctx->pc = 0x801D7664u;
    // 801D7664: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7668:
    ctx->pc = 0x801D7668u;
    // 801D7668: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D766C:
    ctx->pc = 0x801D766Cu;
    // 801D766C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7670:
    ctx->pc = 0x801D7670u;
    // 801D7670: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7674:
    ctx->pc = 0x801D7674u;
    // 801D7674: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7678:
    ctx->pc = 0x801D7678u;
    // 801D7678: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D767C:
    ctx->pc = 0x801D767Cu;
    // 801D767C: mulli   r4, r29, 20
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)20);

label_801D7680:
    ctx->pc = 0x801D7680u;
    // 801D7680: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7684:
    ctx->pc = 0x801D7684u;
    // 801D7684: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D7688:
    ctx->pc = 0x801D7688u;
    // 801D7688: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D768C:
    ctx->pc = 0x801D768Cu;
    // 801D768C: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D7690:
    ctx->pc = 0x801D7690u;
    // 801D7690: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7694:
    ctx->pc = 0x801D7694u;
    // 801D7694: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D7698:
    ctx->pc = 0x801D7698u;
    // 801D7698: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D769C:
    ctx->pc = 0x801D769Cu;
    // 801D769C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D76A0:
    ctx->pc = 0x801D76A0u;
    // 801D76A0: bl      0x80039640
    {
            ctx->lr = 0x801D76A4u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D76A4:
    ctx->pc = 0x801D76A4u;
    ctx->downcount -= 4;
    // 801D76A4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D76A8:
    ctx->pc = 0x801D76A8u;
    // 801D76A8: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D76AC:
    ctx->pc = 0x801D76ACu;
    // 801D76AC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D76B0:
    ctx->pc = 0x801D76B0u;
    // 801D76B0: bl      0x801D75EC
    {
            ctx->lr = 0x801D76B4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D75ECu;
                return;
            }
            goto label_801D75EC;
    }

label_801D76B4:
    ctx->pc = 0x801D76B4u;
    ctx->downcount -= 16;
    // 801D76B4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D76B8:
    ctx->pc = 0x801D76B8u;
    // 801D76B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D76BC:
    ctx->pc = 0x801D76BCu;
    // 801D76BC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D76C0:
    ctx->pc = 0x801D76C0u;
    // 801D76C0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D76C4:
    ctx->pc = 0x801D76C4u;
    // 801D76C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D76C8:
    ctx->pc = 0x801D76C8u;
    ctx->downcount -= 2;
    // 801D76C8: or.   r4, r4, r4
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

label_801D76CC:
    ctx->pc = 0x801D76CCu;
    // 801D76CC: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D76D0:
    ctx->pc = 0x801D76D0u;
    ctx->downcount -= 8;
    // 801D76D0: stw     r3, 32(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D76D4:
    ctx->pc = 0x801D76D4u;
    // 801D76D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D76D8:
    ctx->pc = 0x801D76D8u;
    // 801D76D8: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D76DC:
    ctx->pc = 0x801D76DCu;
    // 801D76DC: stw     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D76E0:
    ctx->pc = 0x801D76E0u;
    // 801D76E0: stw     r9, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D76E4:
    ctx->pc = 0x801D76E4u;
    // 801D76E4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D76E8:
    ctx->pc = 0x801D76E8u;
    // 801D76E8: cmpwi   r9, 0
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

label_801D76EC:
    ctx->pc = 0x801D76ECu;
    // 801D76EC: bc    12, 2, 0x801D76F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D76F8;
        }
    }

label_801D76F0:
    ctx->pc = 0x801D76F0u;
    ctx->downcount -= 2;
    // 801D76F0: stw     r4, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D76F4:
    ctx->pc = 0x801D76F4u;
    // 801D76F4: b       0x801D76FC
    {
            goto label_801D76FC;
    }

label_801D76F8:
    ctx->pc = 0x801D76F8u;
    ctx->downcount -= 1;
    // 801D76F8: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D76FC:
    ctx->pc = 0x801D76FCu;
    ctx->downcount -= 5;
    // 801D76FC: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7700:
    ctx->pc = 0x801D7700u;
    // 801D7700: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7704:
    ctx->pc = 0x801D7704u;
    // 801D7704: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D7708:
    ctx->pc = 0x801D7708u;
    // 801D7708: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D770C:
    ctx->pc = 0x801D770Cu;
    // 801D770C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7710:
    ctx->pc = 0x801D7710u;
    ctx->downcount -= 20;
    // 801D7710: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7714:
    ctx->pc = 0x801D7714u;
    // 801D7714: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7718:
    ctx->pc = 0x801D7718u;
    // 801D7718: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D771C:
    ctx->pc = 0x801D771Cu;
    // 801D771C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7720:
    ctx->pc = 0x801D7720u;
    // 801D7720: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7724:
    ctx->pc = 0x801D7724u;
    // 801D7724: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D7728:
    ctx->pc = 0x801D7728u;
    // 801D7728: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D772C:
    ctx->pc = 0x801D772Cu;
    // 801D772C: cmpwi   r4, 0
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

label_801D7730:
    ctx->pc = 0x801D7730u;
    // 801D7730: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D7734:
    ctx->pc = 0x801D7734u;
    // 801D7734: bc    12, 2, 0x801D7770
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7770;
        }
    }

label_801D7738:
    ctx->pc = 0x801D7738u;
    ctx->downcount -= 3;
    // 801D7738: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D773C:
    ctx->pc = 0x801D773Cu;
    // 801D773C: cmpwi   r30, 0
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

label_801D7740:
    ctx->pc = 0x801D7740u;
    // 801D7740: bc    12, 2, 0x801D7770
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7770;
        }
    }

label_801D7744:
    ctx->pc = 0x801D7744u;
    ctx->downcount -= 1;
    // 801D7744: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D7748:
    ctx->pc = 0x801D7748u;
    ctx->downcount -= 8;
    // 801D7748: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D774C:
    // 801D774C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7750:
    ctx->pc = 0x801D7750u;
    // 801D7750: stw     r29, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7754:
    // 801D7754: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D7758:
    ctx->pc = 0x801D7758u;
    // 801D7758: stw     r29, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D775C:
    ctx->pc = 0x801D775Cu;
    // 801D775C: stw     r29, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7760:
    // 801D7760: addi    r31, r31, 36
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(36);

label_801D7764:
    // 801D7764: bl      0x801D76C8
    {
            ctx->lr = 0x801D7768u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D76C8u;
                return;
            }
            goto label_801D76C8;
    }

label_801D7768:
    ctx->downcount -= 2;
    // 801D7768: addic.  r30, r30, -1
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

label_801D776C:
    // 801D776C: bc    4, 2, 0x801D7748
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7748u;
                return;
            }
            goto label_801D7748;
        }
    }

label_801D7770:
    ctx->pc = 0x801D7770u;
    ctx->downcount -= 16;
    // 801D7770: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7774:
    ctx->pc = 0x801D7774u;
    // 801D7774: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7778:
    ctx->pc = 0x801D7778u;
    // 801D7778: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D777C:
    ctx->pc = 0x801D777Cu;
    // 801D777C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7780:
    ctx->pc = 0x801D7780u;
    // 801D7780: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7784:
    ctx->pc = 0x801D7784u;
    ctx->downcount -= 29;
    // 801D7784: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7788:
    ctx->pc = 0x801D7788u;
    // 801D7788: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D778C:
    ctx->pc = 0x801D778Cu;
    // 801D778C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7790:
    ctx->pc = 0x801D7790u;
    // 801D7790: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7794:
    ctx->pc = 0x801D7794u;
    // 801D7794: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7798:
    ctx->pc = 0x801D7798u;
    // 801D7798: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D779C:
    ctx->pc = 0x801D779Cu;
    // 801D779C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D77A0:
    ctx->pc = 0x801D77A0u;
    // 801D77A0: mulli   r4, r29, 36
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)36);

label_801D77A4:
    ctx->pc = 0x801D77A4u;
    // 801D77A4: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D77A8:
    ctx->pc = 0x801D77A8u;
    // 801D77A8: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D77AC:
    ctx->pc = 0x801D77ACu;
    // 801D77AC: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D77B0:
    ctx->pc = 0x801D77B0u;
    // 801D77B0: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D77B4:
    ctx->pc = 0x801D77B4u;
    // 801D77B4: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D77B8:
    ctx->pc = 0x801D77B8u;
    // 801D77B8: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D77BC:
    ctx->pc = 0x801D77BCu;
    // 801D77BC: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D77C0:
    ctx->pc = 0x801D77C0u;
    // 801D77C0: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D77C4:
    ctx->pc = 0x801D77C4u;
    // 801D77C4: bl      0x80039640
    {
            ctx->lr = 0x801D77C8u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D77C8:
    ctx->pc = 0x801D77C8u;
    ctx->downcount -= 4;
    // 801D77C8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D77CC:
    ctx->pc = 0x801D77CCu;
    // 801D77CC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D77D0:
    ctx->pc = 0x801D77D0u;
    // 801D77D0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D77D4:
    ctx->pc = 0x801D77D4u;
    // 801D77D4: bl      0x801D7710
    {
            ctx->lr = 0x801D77D8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7710u;
                return;
            }
            goto label_801D7710;
    }

label_801D77D8:
    ctx->pc = 0x801D77D8u;
    ctx->downcount -= 16;
    // 801D77D8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D77DC:
    ctx->pc = 0x801D77DCu;
    // 801D77DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D77E0:
    ctx->pc = 0x801D77E0u;
    // 801D77E0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D77E4:
    ctx->pc = 0x801D77E4u;
    // 801D77E4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D77E8:
    ctx->pc = 0x801D77E8u;
    // 801D77E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D77EC:
    ctx->pc = 0x801D77ECu;
    ctx->downcount -= 2;
    // 801D77EC: or.   r4, r4, r4
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

label_801D77F0:
    ctx->pc = 0x801D77F0u;
    // 801D77F0: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D77F4:
    ctx->pc = 0x801D77F4u;
    ctx->downcount -= 8;
    // 801D77F4: stw     r3, 52(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D77F8:
    ctx->pc = 0x801D77F8u;
    // 801D77F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D77FC:
    ctx->pc = 0x801D77FCu;
    // 801D77FC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7800:
    ctx->pc = 0x801D7800u;
    // 801D7800: stw     r0, 44(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7804:
    ctx->pc = 0x801D7804u;
    // 801D7804: stw     r9, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7808:
    ctx->pc = 0x801D7808u;
    // 801D7808: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D780C:
    ctx->pc = 0x801D780Cu;
    // 801D780C: cmpwi   r9, 0
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

label_801D7810:
    ctx->pc = 0x801D7810u;
    // 801D7810: bc    12, 2, 0x801D781C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D781C;
        }
    }

label_801D7814:
    ctx->pc = 0x801D7814u;
    ctx->downcount -= 2;
    // 801D7814: stw     r4, 44(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7818:
    ctx->pc = 0x801D7818u;
    // 801D7818: b       0x801D7820
    {
            goto label_801D7820;
    }

label_801D781C:
    ctx->pc = 0x801D781Cu;
    ctx->downcount -= 1;
    // 801D781C: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7820:
    ctx->pc = 0x801D7820u;
    ctx->downcount -= 5;
    // 801D7820: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7824:
    ctx->pc = 0x801D7824u;
    // 801D7824: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7828:
    ctx->pc = 0x801D7828u;
    // 801D7828: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D782C:
    ctx->pc = 0x801D782Cu;
    // 801D782C: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7830:
    ctx->pc = 0x801D7830u;
    // 801D7830: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7834:
    ctx->pc = 0x801D7834u;
    ctx->downcount -= 20;
    // 801D7834: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7838:
    ctx->pc = 0x801D7838u;
    // 801D7838: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D783C:
    ctx->pc = 0x801D783Cu;
    // 801D783C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7840:
    ctx->pc = 0x801D7840u;
    // 801D7840: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7844:
    ctx->pc = 0x801D7844u;
    // 801D7844: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7848:
    ctx->pc = 0x801D7848u;
    // 801D7848: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D784C:
    ctx->pc = 0x801D784Cu;
    // 801D784C: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7850:
    ctx->pc = 0x801D7850u;
    // 801D7850: cmpwi   r4, 0
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

label_801D7854:
    ctx->pc = 0x801D7854u;
    // 801D7854: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D7858:
    ctx->pc = 0x801D7858u;
    // 801D7858: bc    12, 2, 0x801D7894
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7894;
        }
    }

label_801D785C:
    ctx->pc = 0x801D785Cu;
    ctx->downcount -= 3;
    // 801D785C: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7860:
    ctx->pc = 0x801D7860u;
    // 801D7860: cmpwi   r30, 0
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

label_801D7864:
    ctx->pc = 0x801D7864u;
    // 801D7864: bc    12, 2, 0x801D7894
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7894;
        }
    }

label_801D7868:
    ctx->pc = 0x801D7868u;
    ctx->downcount -= 1;
    // 801D7868: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D786C:
    ctx->pc = 0x801D786Cu;
    ctx->downcount -= 8;
    // 801D786C: stw     r29, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7870:
    // 801D7870: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7874:
    ctx->pc = 0x801D7874u;
    // 801D7874: stw     r29, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7878:
    // 801D7878: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D787C:
    ctx->pc = 0x801D787Cu;
    // 801D787C: stw     r29, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7880:
    ctx->pc = 0x801D7880u;
    // 801D7880: stw     r29, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7884:
    // 801D7884: addi    r31, r31, 56
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(56);

label_801D7888:
    // 801D7888: bl      0x801D77EC
    {
            ctx->lr = 0x801D788Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D77ECu;
                return;
            }
            goto label_801D77EC;
    }

label_801D788C:
    ctx->downcount -= 2;
    // 801D788C: addic.  r30, r30, -1
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

label_801D7890:
    // 801D7890: bc    4, 2, 0x801D786C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D786Cu;
                return;
            }
            goto label_801D786C;
        }
    }

label_801D7894:
    ctx->pc = 0x801D7894u;
    ctx->downcount -= 16;
    // 801D7894: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7898:
    ctx->pc = 0x801D7898u;
    // 801D7898: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D789C:
    ctx->pc = 0x801D789Cu;
    // 801D789C: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D78A0:
    ctx->pc = 0x801D78A0u;
    // 801D78A0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D78A4:
    ctx->pc = 0x801D78A4u;
    // 801D78A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D78A8:
    ctx->pc = 0x801D78A8u;
    ctx->downcount -= 29;
    // 801D78A8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D78AC:
    ctx->pc = 0x801D78ACu;
    // 801D78AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D78B0:
    ctx->pc = 0x801D78B0u;
    // 801D78B0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D78B4:
    ctx->pc = 0x801D78B4u;
    // 801D78B4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D78B8:
    ctx->pc = 0x801D78B8u;
    // 801D78B8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D78BC:
    ctx->pc = 0x801D78BCu;
    // 801D78BC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D78C0:
    ctx->pc = 0x801D78C0u;
    // 801D78C0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D78C4:
    ctx->pc = 0x801D78C4u;
    // 801D78C4: mulli   r4, r29, 56
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)56);

label_801D78C8:
    ctx->pc = 0x801D78C8u;
    // 801D78C8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D78CC:
    ctx->pc = 0x801D78CCu;
    // 801D78CC: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D78D0:
    ctx->pc = 0x801D78D0u;
    // 801D78D0: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D78D4:
    ctx->pc = 0x801D78D4u;
    // 801D78D4: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D78D8:
    ctx->pc = 0x801D78D8u;
    // 801D78D8: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D78DC:
    ctx->pc = 0x801D78DCu;
    // 801D78DC: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D78E0:
    ctx->pc = 0x801D78E0u;
    // 801D78E0: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D78E4:
    ctx->pc = 0x801D78E4u;
    // 801D78E4: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D78E8:
    ctx->pc = 0x801D78E8u;
    // 801D78E8: bl      0x80039640
    {
            ctx->lr = 0x801D78ECu;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D78EC:
    ctx->pc = 0x801D78ECu;
    ctx->downcount -= 4;
    // 801D78EC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D78F0:
    ctx->pc = 0x801D78F0u;
    // 801D78F0: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D78F4:
    ctx->pc = 0x801D78F4u;
    // 801D78F4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D78F8:
    ctx->pc = 0x801D78F8u;
    // 801D78F8: bl      0x801D7834
    {
            ctx->lr = 0x801D78FCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7834u;
                return;
            }
            goto label_801D7834;
    }

label_801D78FC:
    ctx->pc = 0x801D78FCu;
    ctx->downcount -= 16;
    // 801D78FC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7900:
    ctx->pc = 0x801D7900u;
    // 801D7900: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7904:
    ctx->pc = 0x801D7904u;
    // 801D7904: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7908:
    ctx->pc = 0x801D7908u;
    // 801D7908: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D790C:
    ctx->pc = 0x801D790Cu;
    // 801D790C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7910:
    ctx->pc = 0x801D7910u;
    ctx->downcount -= 4;
    // 801D7910: lwz     r9, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7914:
    ctx->pc = 0x801D7914u;
    // 801D7914: lwz     r10, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D7918:
    ctx->pc = 0x801D7918u;
    // 801D7918: cmpwi   r9, 0
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

label_801D791C:
    ctx->pc = 0x801D791Cu;
    // 801D791C: bc    12, 2, 0x801D7928
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7928;
        }
    }

label_801D7920:
    ctx->pc = 0x801D7920u;
    ctx->downcount -= 2;
    // 801D7920: stw     r10, 40(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7924:
    ctx->pc = 0x801D7924u;
    // 801D7924: b       0x801D7930
    {
            goto label_801D7930;
    }

label_801D7928:
    ctx->pc = 0x801D7928u;
    ctx->downcount -= 2;
    // 801D7928: lwz     r9, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D792C:
    ctx->pc = 0x801D792Cu;
    // 801D792C: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7930:
    ctx->pc = 0x801D7930u;
    ctx->downcount -= 3;
    // 801D7930: lwz     r9, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7934:
    ctx->pc = 0x801D7934u;
    // 801D7934: cmpwi   r9, 0
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

label_801D7938:
    ctx->pc = 0x801D7938u;
    // 801D7938: bc    12, 2, 0x801D7948
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7948;
        }
    }

label_801D793C:
    ctx->pc = 0x801D793Cu;
    ctx->downcount -= 3;
    // 801D793C: lwz     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7940:
    ctx->pc = 0x801D7940u;
    // 801D7940: stw     r0, 44(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7944:
    ctx->pc = 0x801D7944u;
    // 801D7944: b       0x801D7954
    {
            goto label_801D7954;
    }

label_801D7948:
    ctx->pc = 0x801D7948u;
    ctx->downcount -= 3;
    // 801D7948: lwz     r9, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D794C:
    ctx->pc = 0x801D794Cu;
    // 801D794C: lwz     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7950:
    ctx->pc = 0x801D7950u;
    // 801D7950: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7954:
    ctx->pc = 0x801D7954u;
    ctx->downcount -= 6;
    // 801D7954: lwz     r11, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D7958:
    ctx->pc = 0x801D7958u;
    // 801D7958: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D795C:
    ctx->pc = 0x801D795Cu;
    // 801D795C: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7960:
    ctx->pc = 0x801D7960u;
    // 801D7960: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D7964:
    ctx->pc = 0x801D7964u;
    // 801D7964: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7968:
    ctx->pc = 0x801D7968u;
    // 801D7968: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D796C:
    ctx->pc = 0x801D796Cu;
    ctx->downcount -= 4;
    // 801D796C: lwz     r9, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7970:
    ctx->pc = 0x801D7970u;
    // 801D7970: lwz     r10, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D7974:
    ctx->pc = 0x801D7974u;
    // 801D7974: cmpwi   r9, 0
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

label_801D7978:
    ctx->pc = 0x801D7978u;
    // 801D7978: bc    12, 2, 0x801D7984
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7984;
        }
    }

label_801D797C:
    ctx->pc = 0x801D797Cu;
    ctx->downcount -= 2;
    // 801D797C: stw     r10, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7980:
    ctx->pc = 0x801D7980u;
    // 801D7980: b       0x801D798C
    {
            goto label_801D798C;
    }

label_801D7984:
    ctx->pc = 0x801D7984u;
    ctx->downcount -= 2;
    // 801D7984: lwz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7988:
    ctx->pc = 0x801D7988u;
    // 801D7988: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D798C:
    ctx->pc = 0x801D798Cu;
    ctx->downcount -= 3;
    // 801D798C: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7990:
    ctx->pc = 0x801D7990u;
    // 801D7990: cmpwi   r9, 0
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

label_801D7994:
    ctx->pc = 0x801D7994u;
    // 801D7994: bc    12, 2, 0x801D79A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D79A4;
        }
    }

label_801D7998:
    ctx->pc = 0x801D7998u;
    ctx->downcount -= 3;
    // 801D7998: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D799C:
    ctx->pc = 0x801D799Cu;
    // 801D799C: stw     r0, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D79A0:
    ctx->pc = 0x801D79A0u;
    // 801D79A0: b       0x801D79B0
    {
            goto label_801D79B0;
    }

label_801D79A4:
    ctx->pc = 0x801D79A4u;
    ctx->downcount -= 3;
    // 801D79A4: lwz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D79A8:
    ctx->pc = 0x801D79A8u;
    // 801D79A8: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D79AC:
    ctx->pc = 0x801D79ACu;
    // 801D79AC: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D79B0:
    ctx->pc = 0x801D79B0u;
    ctx->downcount -= 6;
    // 801D79B0: lwz     r11, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D79B4:
    ctx->pc = 0x801D79B4u;
    // 801D79B4: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D79B8:
    ctx->pc = 0x801D79B8u;
    // 801D79B8: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D79BC:
    ctx->pc = 0x801D79BCu;
    // 801D79BC: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D79C0:
    ctx->pc = 0x801D79C0u;
    // 801D79C0: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D79C4:
    ctx->pc = 0x801D79C4u;
    // 801D79C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D79C8:
    ctx->pc = 0x801D79C8u;
    ctx->downcount -= 4;
    // 801D79C8: lwz     r9, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D79CC:
    ctx->pc = 0x801D79CCu;
    // 801D79CC: lwz     r10, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D79D0:
    ctx->pc = 0x801D79D0u;
    // 801D79D0: cmpwi   r9, 0
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

label_801D79D4:
    ctx->pc = 0x801D79D4u;
    // 801D79D4: bc    12, 2, 0x801D79E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D79E0;
        }
    }

label_801D79D8:
    ctx->pc = 0x801D79D8u;
    ctx->downcount -= 2;
    // 801D79D8: stw     r10, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D79DC:
    ctx->pc = 0x801D79DCu;
    // 801D79DC: b       0x801D79E8
    {
            goto label_801D79E8;
    }

label_801D79E0:
    ctx->pc = 0x801D79E0u;
    ctx->downcount -= 2;
    // 801D79E0: lwz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D79E4:
    ctx->pc = 0x801D79E4u;
    // 801D79E4: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D79E8:
    ctx->pc = 0x801D79E8u;
    ctx->downcount -= 3;
    // 801D79E8: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D79EC:
    ctx->pc = 0x801D79ECu;
    // 801D79EC: cmpwi   r9, 0
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

label_801D79F0:
    ctx->pc = 0x801D79F0u;
    // 801D79F0: bc    12, 2, 0x801D7A00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7A00;
        }
    }

label_801D79F4:
    ctx->pc = 0x801D79F4u;
    ctx->downcount -= 3;
    // 801D79F4: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D79F8:
    ctx->pc = 0x801D79F8u;
    // 801D79F8: stw     r0, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D79FC:
    ctx->pc = 0x801D79FCu;
    // 801D79FC: b       0x801D7A0C
    {
            goto label_801D7A0C;
    }

label_801D7A00:
    ctx->pc = 0x801D7A00u;
    ctx->downcount -= 3;
    // 801D7A00: lwz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7A04:
    ctx->pc = 0x801D7A04u;
    // 801D7A04: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7A08:
    ctx->pc = 0x801D7A08u;
    // 801D7A08: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7A0C:
    ctx->pc = 0x801D7A0Cu;
    ctx->downcount -= 6;
    // 801D7A0C: lwz     r11, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D7A10:
    ctx->pc = 0x801D7A10u;
    // 801D7A10: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D7A14:
    ctx->pc = 0x801D7A14u;
    // 801D7A14: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7A18:
    ctx->pc = 0x801D7A18u;
    // 801D7A18: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D7A1C:
    ctx->pc = 0x801D7A1Cu;
    // 801D7A1C: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7A20:
    ctx->pc = 0x801D7A20u;
    // 801D7A20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7A24:
    ctx->pc = 0x801D7A24u;
    ctx->downcount -= 2;
    // 801D7A24: or.   r4, r4, r4
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

label_801D7A28:
    ctx->pc = 0x801D7A28u;
    // 801D7A28: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7A2C:
    ctx->pc = 0x801D7A2Cu;
    ctx->downcount -= 8;
    // 801D7A2C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801D7A30:
    ctx->pc = 0x801D7A30u;
    // 801D7A30: stw     r3, 32(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D7A34:
    ctx->pc = 0x801D7A34u;
    // 801D7A34: stw     r9, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7A38:
    ctx->pc = 0x801D7A38u;
    // 801D7A38: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7A3C:
    ctx->pc = 0x801D7A3Cu;
    // 801D7A3C: stw     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7A40:
    ctx->pc = 0x801D7A40u;
    // 801D7A40: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7A44:
    ctx->pc = 0x801D7A44u;
    // 801D7A44: cmpwi   r9, 0
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

label_801D7A48:
    ctx->pc = 0x801D7A48u;
    // 801D7A48: bc    12, 2, 0x801D7A54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7A54;
        }
    }

label_801D7A4C:
    ctx->pc = 0x801D7A4Cu;
    ctx->downcount -= 2;
    // 801D7A4C: stw     r4, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7A50:
    ctx->pc = 0x801D7A50u;
    // 801D7A50: b       0x801D7A58
    {
            goto label_801D7A58;
    }

label_801D7A54:
    ctx->pc = 0x801D7A54u;
    ctx->downcount -= 1;
    // 801D7A54: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7A58:
    ctx->pc = 0x801D7A58u;
    ctx->downcount -= 5;
    // 801D7A58: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7A5C:
    ctx->pc = 0x801D7A5Cu;
    // 801D7A5C: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7A60:
    ctx->pc = 0x801D7A60u;
    // 801D7A60: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D7A64:
    ctx->pc = 0x801D7A64u;
    // 801D7A64: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7A68:
    ctx->pc = 0x801D7A68u;
    // 801D7A68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7A6C:
    ctx->pc = 0x801D7A6Cu;
    ctx->downcount -= 21;
    // 801D7A6C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7A70:
    ctx->pc = 0x801D7A70u;
    // 801D7A70: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7A74:
    ctx->pc = 0x801D7A74u;
    // 801D7A74: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D7A78:
    ctx->pc = 0x801D7A78u;
    // 801D7A78: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7A7C:
    ctx->pc = 0x801D7A7Cu;
    // 801D7A7C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7A80:
    ctx->pc = 0x801D7A80u;
    // 801D7A80: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D7A84:
    ctx->pc = 0x801D7A84u;
    // 801D7A84: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7A88:
    ctx->pc = 0x801D7A88u;
    // 801D7A88: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7A8C:
    ctx->pc = 0x801D7A8Cu;
    // 801D7A8C: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D7A90:
    ctx->pc = 0x801D7A90u;
    // 801D7A90: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D7A94:
    ctx->pc = 0x801D7A94u;
    // 801D7A94: bc    12, 18, 0x801D7ACC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7ACC;
        }
    }

label_801D7A98:
    ctx->pc = 0x801D7A98u;
    ctx->downcount -= 2;
    // 801D7A98: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7A9C:
    ctx->pc = 0x801D7A9Cu;
    // 801D7A9C: bl      0x801D79C8
    {
            ctx->lr = 0x801D7AA0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D79C8u;
                return;
            }
            goto label_801D79C8;
    }

label_801D7AA0:
    ctx->pc = 0x801D7AA0u;
    ctx->downcount -= 6;
    // 801D7AA0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D7AA4:
    ctx->pc = 0x801D7AA4u;
    // 801D7AA4: stw     r0, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7AA8:
    ctx->pc = 0x801D7AA8u;
    // 801D7AA8: stw     r0, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7AAC:
    ctx->pc = 0x801D7AACu;
    // 801D7AAC: stw     r0, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7AB0:
    ctx->pc = 0x801D7AB0u;
    // 801D7AB0: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7AB4:
    ctx->pc = 0x801D7AB4u;
    // 801D7AB4: bc    12, 18, 0x801D7ACC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7ACC;
        }
    }

label_801D7AB8:
    ctx->pc = 0x801D7AB8u;
    ctx->downcount -= 7;
    // 801D7AB8: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D7ABC:
    ctx->pc = 0x801D7ABCu;
    // 801D7ABC: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7AC0:
    ctx->pc = 0x801D7AC0u;
    // 801D7AC0: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D7AC4:
    ctx->pc = 0x801D7AC4u;
    // 801D7AC4: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D7AC8:
    ctx->pc = 0x801D7AC8u;
    // 801D7AC8: bl      0x801D7A24
    {
            ctx->lr = 0x801D7ACCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7A24u;
                return;
            }
            goto label_801D7A24;
    }

label_801D7ACC:
    ctx->pc = 0x801D7ACCu;
    ctx->downcount -= 19;
    // 801D7ACC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7AD0:
    ctx->pc = 0x801D7AD0u;
    // 801D7AD0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7AD4:
    ctx->pc = 0x801D7AD4u;
    // 801D7AD4: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D7AD8:
    ctx->pc = 0x801D7AD8u;
    // 801D7AD8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7ADC:
    ctx->pc = 0x801D7ADCu;
    // 801D7ADC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7AE0:
    ctx->pc = 0x801D7AE0u;
    // 801D7AE0: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D7AE4:
    ctx->pc = 0x801D7AE4u;
    // 801D7AE4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7AE8:
    ctx->pc = 0x801D7AE8u;
    // 801D7AE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7AEC:
    ctx->pc = 0x801D7AECu;
    ctx->downcount -= 2;
    // 801D7AEC: or.   r4, r4, r4
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

label_801D7AF0:
    ctx->pc = 0x801D7AF0u;
    // 801D7AF0: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7AF4:
    ctx->pc = 0x801D7AF4u;
    ctx->downcount -= 8;
    // 801D7AF4: stw     r3, 32(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D7AF8:
    ctx->pc = 0x801D7AF8u;
    // 801D7AF8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D7AFC:
    ctx->pc = 0x801D7AFCu;
    // 801D7AFC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7B00:
    ctx->pc = 0x801D7B00u;
    // 801D7B00: stw     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7B04:
    ctx->pc = 0x801D7B04u;
    // 801D7B04: stw     r9, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7B08:
    ctx->pc = 0x801D7B08u;
    // 801D7B08: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7B0C:
    ctx->pc = 0x801D7B0Cu;
    // 801D7B0C: cmpwi   r9, 0
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

label_801D7B10:
    ctx->pc = 0x801D7B10u;
    // 801D7B10: bc    12, 2, 0x801D7B1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7B1C;
        }
    }

label_801D7B14:
    ctx->pc = 0x801D7B14u;
    ctx->downcount -= 2;
    // 801D7B14: stw     r4, 24(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7B18:
    ctx->pc = 0x801D7B18u;
    // 801D7B18: b       0x801D7B20
    {
            goto label_801D7B20;
    }

label_801D7B1C:
    ctx->pc = 0x801D7B1Cu;
    ctx->downcount -= 1;
    // 801D7B1C: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7B20:
    ctx->pc = 0x801D7B20u;
    ctx->downcount -= 5;
    // 801D7B20: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7B24:
    ctx->pc = 0x801D7B24u;
    // 801D7B24: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7B28:
    ctx->pc = 0x801D7B28u;
    // 801D7B28: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D7B2C:
    ctx->pc = 0x801D7B2Cu;
    // 801D7B2C: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7B30:
    ctx->pc = 0x801D7B30u;
    // 801D7B30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7B34:
    ctx->pc = 0x801D7B34u;
    ctx->downcount -= 7;
    // 801D7B34: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7B38:
    ctx->pc = 0x801D7B38u;
    // 801D7B38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7B3C:
    ctx->pc = 0x801D7B3Cu;
    // 801D7B3C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7B40:
    ctx->pc = 0x801D7B40u;
    // 801D7B40: lwz     r3, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801D7B44:
    ctx->pc = 0x801D7B44u;
    // 801D7B44: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801D7B48:
    ctx->pc = 0x801D7B48u;
    // 801D7B48: li      r5, 12
    ctx->gpr[5] = (u32)(s32)(12);

label_801D7B4C:
    ctx->pc = 0x801D7B4Cu;
    // 801D7B4C: bl      0x801698F0
    {
            ctx->lr = 0x801D7B50u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_801D7B50:
    ctx->pc = 0x801D7B50u;
    ctx->downcount -= 5;
    // 801D7B50: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7B54:
    ctx->pc = 0x801D7B54u;
    // 801D7B54: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7B58:
    ctx->pc = 0x801D7B58u;
    // 801D7B58: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801D7B5C:
    ctx->pc = 0x801D7B5Cu;
    // 801D7B5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7B60:
    ctx->pc = 0x801D7B60u;
    ctx->downcount -= 3;
    // 801D7B60: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7B64:
    ctx->pc = 0x801D7B64u;
    // 801D7B64: andi.   r0, r9, 0x0003
    {
        ctx->gpr[0] = ctx->gpr[9] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7B68:
    ctx->pc = 0x801D7B68u;
    // 801D7B68: bc    4, 2, 0x801D7BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D7BB4;
        }
    }

label_801D7B6C:
    ctx->pc = 0x801D7B6Cu;
    ctx->downcount -= 3;
    // 801D7B6C: lwz     r11, 508(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(508);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D7B70:
    ctx->pc = 0x801D7B70u;
    // 801D7B70: andi.   r7, r11, 0x0003
    {
        ctx->gpr[7] = ctx->gpr[11] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7B74:
    ctx->pc = 0x801D7B74u;
    // 801D7B74: bc    4, 2, 0x801D7BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D7BB4;
        }
    }

label_801D7B78:
    ctx->pc = 0x801D7B78u;
    ctx->downcount -= 4;
    // 801D7B78: lwz     r0, 504(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(504);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7B7C:
    ctx->pc = 0x801D7B7Cu;
    // 801D7B7C: or   r8, r0, r0
    {
        ctx->gpr[8] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801D7B80:
    ctx->pc = 0x801D7B80u;
    // 801D7B80: andi.   r10, r0, 0x0003
    {
        ctx->gpr[10] = ctx->gpr[0] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7B84:
    ctx->pc = 0x801D7B84u;
    // 801D7B84: bc    4, 2, 0x801D7BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D7BB4;
        }
    }

label_801D7B88:
    ctx->pc = 0x801D7B88u;
    ctx->downcount -= 4;
    // 801D7B88: lwz     r0, 516(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(516);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7B8C:
    ctx->pc = 0x801D7B8Cu;
    // 801D7B8C: or   r10, r0, r0
    {
        ctx->gpr[10] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801D7B90:
    ctx->pc = 0x801D7B90u;
    // 801D7B90: andi.   r7, r0, 0x0003
    {
        ctx->gpr[7] = ctx->gpr[0] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7B94:
    ctx->pc = 0x801D7B94u;
    // 801D7B94: bc    4, 2, 0x801D7BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D7BB4;
        }
    }

label_801D7B98:
    ctx->pc = 0x801D7B98u;
    ctx->downcount -= 2;
    // 801D7B98: cmpwi   r10, 0
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

label_801D7B9C:
    ctx->pc = 0x801D7B9Cu;
    // 801D7B9C: bc    12, 2, 0x801D7BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7BB4;
        }
    }

label_801D7BA0:
    ctx->pc = 0x801D7BA0u;
    ctx->downcount -= 2;
    // 801D7BA0: cmpwi   r11, 0
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

label_801D7BA4:
    ctx->pc = 0x801D7BA4u;
    // 801D7BA4: bc    12, 2, 0x801D7BBC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7BBC;
        }
    }

label_801D7BA8:
    ctx->pc = 0x801D7BA8u;
    ctx->downcount -= 1;
    // 801D7BA8: lwz     r0, 504(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(504);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7BAC:
    ctx->downcount -= 2;
    // 801D7BAC: cmpw    r0, r9
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

label_801D7BB0:
    // 801D7BB0: bc    12, 2, 0x801D7BC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7BC4;
        }
    }

label_801D7BB4:
    ctx->downcount -= 2;
    // 801D7BB4: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D7BB8:
    ctx->pc = 0x801D7BB8u;
    // 801D7BB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7BBC:
    ctx->pc = 0x801D7BBCu;
    ctx->downcount -= 2;
    // 801D7BBC: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7BC0:
    // 801D7BC0: b       0x801D7BAC
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7BACu;
                return;
            }
            goto label_801D7BAC;
    }

label_801D7BC4:
    ctx->downcount -= 2;
    // 801D7BC4: cmpwi   r8, 0
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

label_801D7BC8:
    // 801D7BC8: bc    12, 2, 0x801D7BDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7BDC;
        }
    }

label_801D7BCC:
    ctx->pc = 0x801D7BCCu;
    ctx->downcount -= 3;
    // 801D7BCC: lwz     r0, 508(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7BD0:
    // 801D7BD0: cmpw    r0, r9
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

label_801D7BD4:
    // 801D7BD4: bc    12, 2, 0x801D7BEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7BEC;
        }
    }

label_801D7BD8:
    ctx->downcount -= 1;
    // 801D7BD8: b       0x801D7BB4
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7BB4u;
                return;
            }
            goto label_801D7BB4;
    }

label_801D7BDC:
    ctx->pc = 0x801D7BDCu;
    ctx->downcount -= 4;
    // 801D7BDC: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7BE0:
    ctx->pc = 0x801D7BE0u;
    // 801D7BE0: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D7BE4:
    ctx->pc = 0x801D7BE4u;
    // 801D7BE4: cmpw    r0, r9
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

label_801D7BE8:
    ctx->pc = 0x801D7BE8u;
    // 801D7BE8: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7BEC:
    ctx->pc = 0x801D7BECu;
    ctx->downcount -= 2;
    // 801D7BEC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801D7BF0:
    ctx->pc = 0x801D7BF0u;
    // 801D7BF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7BF4:
    ctx->pc = 0x801D7BF4u;
    ctx->downcount -= 19;
    // 801D7BF4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7BF8:
    ctx->pc = 0x801D7BF8u;
    // 801D7BF8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7BFC:
    ctx->pc = 0x801D7BFCu;
    // 801D7BFC: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7C00:
    ctx->pc = 0x801D7C00u;
    // 801D7C00: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7C04:
    ctx->pc = 0x801D7C04u;
    // 801D7C04: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7C08:
    ctx->pc = 0x801D7C08u;
    // 801D7C08: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D7C0C:
    ctx->pc = 0x801D7C0Cu;
    // 801D7C0C: lwz     r31, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D7C10:
    ctx->pc = 0x801D7C10u;
    // 801D7C10: cmpwi   r31, 0
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

label_801D7C14:
    ctx->pc = 0x801D7C14u;
    // 801D7C14: bc    12, 2, 0x801D7C50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7C50;
        }
    }

label_801D7C18:
    ctx->downcount -= 3;
    // 801D7C18: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D7C1C:
    // 801D7C1C: andi.   r0, r31, 0x0003
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7C20:
    // 801D7C20: bc    4, 2, 0x801D7C54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D7C54;
        }
    }

label_801D7C24:
    ctx->downcount -= 2;
    // 801D7C24: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7C28:
    // 801D7C28: bl      0x801D7B60
    {
            ctx->lr = 0x801D7C2Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7B60u;
                return;
            }
            goto label_801D7B60;
    }

label_801D7C2C:
    ctx->pc = 0x801D7C2Cu;
    ctx->downcount -= 3;
    // 801D7C2C: lwz     r0, 516(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(516);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7C30:
    // 801D7C30: cmpw    r0, r30
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

label_801D7C34:
    // 801D7C34: bc    12, 2, 0x801D7C40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7C40;
        }
    }

label_801D7C38:
    ctx->downcount -= 2;
    // 801D7C38: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D7C3C:
    // 801D7C3C: b       0x801D7C54
    {
            goto label_801D7C54;
    }

label_801D7C40:
    ctx->pc = 0x801D7C40u;
    ctx->downcount -= 4;
    // 801D7C40: lwz     r31, 504(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(504);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D7C44:
    // 801D7C44: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_801D7C48:
    // 801D7C48: cmpwi   r31, 0
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

label_801D7C4C:
    // 801D7C4C: bc    4, 2, 0x801D7C18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7C18u;
                return;
            }
            goto label_801D7C18;
        }
    }

label_801D7C50:
    ctx->pc = 0x801D7C50u;
    ctx->downcount -= 1;
    // 801D7C50: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D7C54:
    ctx->pc = 0x801D7C54u;
    ctx->downcount -= 16;
    // 801D7C54: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7C58:
    ctx->pc = 0x801D7C58u;
    // 801D7C58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7C5C:
    ctx->pc = 0x801D7C5Cu;
    // 801D7C5C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7C60:
    ctx->pc = 0x801D7C60u;
    // 801D7C60: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7C64:
    ctx->pc = 0x801D7C64u;
    // 801D7C64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7C68:
    ctx->pc = 0x801D7C68u;
    ctx->downcount -= 18;
    // 801D7C68: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7C6C:
    ctx->pc = 0x801D7C6Cu;
    // 801D7C6C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7C70:
    ctx->pc = 0x801D7C70u;
    // 801D7C70: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7C74:
    ctx->pc = 0x801D7C74u;
    // 801D7C74: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7C78:
    ctx->pc = 0x801D7C78u;
    // 801D7C78: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7C7C:
    ctx->pc = 0x801D7C7Cu;
    // 801D7C7C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7C80:
    ctx->pc = 0x801D7C80u;
    // 801D7C80: lwz     r31, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D7C84:
    ctx->pc = 0x801D7C84u;
    // 801D7C84: bl      0x801D7BF4
    {
            ctx->lr = 0x801D7C88u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7BF4u;
                return;
            }
            goto label_801D7BF4;
    }

label_801D7C88:
    ctx->pc = 0x801D7C88u;
    ctx->downcount -= 4;
    // 801D7C88: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_801D7C8C:
    ctx->pc = 0x801D7C8Cu;
    // 801D7C8C: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7C90:
    ctx->pc = 0x801D7C90u;
    // 801D7C90: cmpw    r3, r0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801D7C94:
    ctx->pc = 0x801D7C94u;
    // 801D7C94: bc    12, 2, 0x801D7CE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7CE4;
        }
    }

label_801D7C98:
    ctx->pc = 0x801D7C98u;
    ctx->downcount -= 4;
    // 801D7C98: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_801D7C9C:
    ctx->pc = 0x801D7C9Cu;
    // 801D7C9C: addi    r3, r3, -18412
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-18412);

label_801D7CA0:
    ctx->pc = 0x801D7CA0u;
    // 801D7CA0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801D7CA4:
    ctx->pc = 0x801D7CA4u;
    // 801D7CA4: bl      0x80166EF4
    {
            ctx->lr = 0x801D7CA8u;
            ctx->pc = 0x80166EF4u;
            return;
    }

label_801D7CA8:
    ctx->downcount -= 2;
    // 801D7CA8: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D7CAC:
    // 801D7CAC: b       0x801D7CFC
    {
            goto label_801D7CFC;
    }

label_801D7CB0:
    ctx->downcount -= 2;
    // 801D7CB0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801D7CB4:
    // 801D7CB4: b       0x801D7CFC
    {
            goto label_801D7CFC;
    }

label_801D7CB8:
    ctx->downcount -= 2;
    // 801D7CB8: cmpw    r31, r29
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801D7CBC:
    // 801D7CBC: bc    12, 2, 0x801D7CB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7CB0u;
                return;
            }
            goto label_801D7CB0;
        }
    }

label_801D7CC0:
    ctx->downcount -= 3;
    // 801D7CC0: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D7CC4:
    // 801D7CC4: andi.   r0, r31, 0x0003
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7CC8:
    // 801D7CC8: bc    4, 2, 0x801D7CFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D7CFC;
        }
    }

label_801D7CCC:
    ctx->downcount -= 2;
    // 801D7CCC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7CD0:
    // 801D7CD0: bl      0x801D7B60
    {
            ctx->lr = 0x801D7CD4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7B60u;
                return;
            }
            goto label_801D7B60;
    }

label_801D7CD4:
    ctx->downcount -= 2;
    // 801D7CD4: cmpwi   r3, -1
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

label_801D7CD8:
    // 801D7CD8: bc    12, 2, 0x801D7CA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7CA8u;
                return;
            }
            goto label_801D7CA8;
        }
    }

label_801D7CDC:
    ctx->pc = 0x801D7CDCu;
    ctx->downcount -= 2;
    // 801D7CDC: lwz     r31, 504(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(504);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D7CE0:
    // 801D7CE0: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_801D7CE4:
    ctx->downcount -= 2;
    // 801D7CE4: cmpwi   r31, 0
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

label_801D7CE8:
    // 801D7CE8: bc    4, 2, 0x801D7CB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7CB8u;
                return;
            }
            goto label_801D7CB8;
        }
    }

label_801D7CEC:
    ctx->pc = 0x801D7CECu;
    ctx->downcount -= 3;
    // 801D7CEC: cmpwi   r29, 0
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

label_801D7CF0:
    ctx->pc = 0x801D7CF0u;
    // 801D7CF0: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D7CF4:
    ctx->pc = 0x801D7CF4u;
    // 801D7CF4: bc    4, 2, 0x801D7CFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D7CFC;
        }
    }

label_801D7CF8:
    ctx->pc = 0x801D7CF8u;
    ctx->downcount -= 1;
    // 801D7CF8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801D7CFC:
    ctx->pc = 0x801D7CFCu;
    ctx->downcount -= 16;
    // 801D7CFC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7D00:
    ctx->pc = 0x801D7D00u;
    // 801D7D00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7D04:
    ctx->pc = 0x801D7D04u;
    // 801D7D04: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7D08:
    ctx->pc = 0x801D7D08u;
    // 801D7D08: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7D0C:
    ctx->pc = 0x801D7D0Cu;
    // 801D7D0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7D10:
    ctx->pc = 0x801D7D10u;
    ctx->downcount -= 2;
    // 801D7D10: or.   r4, r4, r4
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

label_801D7D14:
    ctx->pc = 0x801D7D14u;
    // 801D7D14: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7D18:
    ctx->pc = 0x801D7D18u;
    ctx->downcount -= 8;
    // 801D7D18: stw     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D7D1C:
    ctx->pc = 0x801D7D1Cu;
    // 801D7D1C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D7D20:
    ctx->pc = 0x801D7D20u;
    // 801D7D20: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7D24:
    ctx->pc = 0x801D7D24u;
    // 801D7D24: stw     r0, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7D28:
    ctx->pc = 0x801D7D28u;
    // 801D7D28: stw     r9, 504(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7D2C:
    ctx->pc = 0x801D7D2Cu;
    // 801D7D2C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7D30:
    ctx->pc = 0x801D7D30u;
    // 801D7D30: cmpwi   r9, 0
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

label_801D7D34:
    ctx->pc = 0x801D7D34u;
    // 801D7D34: bc    12, 2, 0x801D7D40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7D40;
        }
    }

label_801D7D38:
    ctx->pc = 0x801D7D38u;
    ctx->downcount -= 2;
    // 801D7D38: stw     r4, 508(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7D3C:
    ctx->pc = 0x801D7D3Cu;
    // 801D7D3C: b       0x801D7D44
    {
            goto label_801D7D44;
    }

label_801D7D40:
    ctx->pc = 0x801D7D40u;
    ctx->downcount -= 1;
    // 801D7D40: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7D44:
    ctx->pc = 0x801D7D44u;
    ctx->downcount -= 5;
    // 801D7D44: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7D48:
    ctx->pc = 0x801D7D48u;
    // 801D7D48: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7D4C:
    ctx->pc = 0x801D7D4Cu;
    // 801D7D4C: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D7D50:
    ctx->pc = 0x801D7D50u;
    // 801D7D50: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7D54:
    ctx->pc = 0x801D7D54u;
    // 801D7D54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7D58:
    ctx->pc = 0x801D7D58u;
    ctx->downcount -= 20;
    // 801D7D58: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7D5C:
    ctx->pc = 0x801D7D5Cu;
    // 801D7D5C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7D60:
    ctx->pc = 0x801D7D60u;
    // 801D7D60: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7D64:
    ctx->pc = 0x801D7D64u;
    // 801D7D64: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7D68:
    ctx->pc = 0x801D7D68u;
    // 801D7D68: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7D6C:
    ctx->pc = 0x801D7D6Cu;
    // 801D7D6C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D7D70:
    ctx->pc = 0x801D7D70u;
    // 801D7D70: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7D74:
    ctx->pc = 0x801D7D74u;
    // 801D7D74: cmpwi   r4, 0
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

label_801D7D78:
    ctx->pc = 0x801D7D78u;
    // 801D7D78: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D7D7C:
    ctx->pc = 0x801D7D7Cu;
    // 801D7D7C: bc    12, 2, 0x801D7DB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7DB8;
        }
    }

label_801D7D80:
    ctx->pc = 0x801D7D80u;
    ctx->downcount -= 3;
    // 801D7D80: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7D84:
    ctx->pc = 0x801D7D84u;
    // 801D7D84: cmpwi   r30, 0
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

label_801D7D88:
    ctx->pc = 0x801D7D88u;
    // 801D7D88: bc    12, 2, 0x801D7DB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7DB8;
        }
    }

label_801D7D8C:
    ctx->pc = 0x801D7D8Cu;
    ctx->downcount -= 1;
    // 801D7D8C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D7D90:
    ctx->pc = 0x801D7D90u;
    ctx->downcount -= 8;
    // 801D7D90: stw     r29, 504(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7D94:
    // 801D7D94: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7D98:
    ctx->pc = 0x801D7D98u;
    // 801D7D98: stw     r29, 508(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7D9C:
    // 801D7D9C: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D7DA0:
    ctx->pc = 0x801D7DA0u;
    // 801D7DA0: stw     r29, 512(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7DA4:
    ctx->pc = 0x801D7DA4u;
    // 801D7DA4: stw     r29, 516(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(516);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D7DA8:
    // 801D7DA8: addi    r31, r31, 520
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(520);

label_801D7DAC:
    // 801D7DAC: bl      0x801D7D10
    {
            ctx->lr = 0x801D7DB0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7D10u;
                return;
            }
            goto label_801D7D10;
    }

label_801D7DB0:
    ctx->downcount -= 2;
    // 801D7DB0: addic.  r30, r30, -1
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

label_801D7DB4:
    // 801D7DB4: bc    4, 2, 0x801D7D90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7D90u;
                return;
            }
            goto label_801D7D90;
        }
    }

label_801D7DB8:
    ctx->pc = 0x801D7DB8u;
    ctx->downcount -= 16;
    // 801D7DB8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7DBC:
    ctx->pc = 0x801D7DBCu;
    // 801D7DBC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7DC0:
    ctx->pc = 0x801D7DC0u;
    // 801D7DC0: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7DC4:
    ctx->pc = 0x801D7DC4u;
    // 801D7DC4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7DC8:
    ctx->pc = 0x801D7DC8u;
    // 801D7DC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7DCC:
    ctx->pc = 0x801D7DCCu;
    ctx->downcount -= 29;
    // 801D7DCC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7DD0:
    ctx->pc = 0x801D7DD0u;
    // 801D7DD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7DD4:
    ctx->pc = 0x801D7DD4u;
    // 801D7DD4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7DD8:
    ctx->pc = 0x801D7DD8u;
    // 801D7DD8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7DDC:
    ctx->pc = 0x801D7DDCu;
    // 801D7DDC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7DE0:
    ctx->pc = 0x801D7DE0u;
    // 801D7DE0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D7DE4:
    ctx->pc = 0x801D7DE4u;
    // 801D7DE4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7DE8:
    ctx->pc = 0x801D7DE8u;
    // 801D7DE8: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D7DEC:
    ctx->pc = 0x801D7DECu;
    // 801D7DEC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7DF0:
    ctx->pc = 0x801D7DF0u;
    // 801D7DF0: rlwinm r4, r29, 6, 0, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[29], 6u) & 0xFFFFFFC0u;
    }

label_801D7DF4:
    ctx->pc = 0x801D7DF4u;
    // 801D7DF4: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7DF8:
    ctx->pc = 0x801D7DF8u;
    // 801D7DF8: add   r4, r4, r29
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_801D7DFC:
    ctx->pc = 0x801D7DFCu;
    // 801D7DFC: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7E00:
    ctx->pc = 0x801D7E00u;
    // 801D7E00: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D7E04:
    ctx->pc = 0x801D7E04u;
    // 801D7E04: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7E08:
    ctx->pc = 0x801D7E08u;
    // 801D7E08: rlwinm r4, r4, 3, 0, 28
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_801D7E0C:
    ctx->pc = 0x801D7E0Cu;
    // 801D7E0C: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D7E10:
    ctx->pc = 0x801D7E10u;
    // 801D7E10: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7E14:
    ctx->pc = 0x801D7E14u;
    // 801D7E14: bl      0x80039640
    {
            ctx->lr = 0x801D7E18u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D7E18:
    ctx->pc = 0x801D7E18u;
    ctx->downcount -= 4;
    // 801D7E18: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7E1C:
    ctx->pc = 0x801D7E1Cu;
    // 801D7E1C: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D7E20:
    ctx->pc = 0x801D7E20u;
    // 801D7E20: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D7E24:
    ctx->pc = 0x801D7E24u;
    // 801D7E24: bl      0x801D7D58
    {
            ctx->lr = 0x801D7E28u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7D58u;
                return;
            }
            goto label_801D7D58;
    }

label_801D7E28:
    ctx->pc = 0x801D7E28u;
    ctx->downcount -= 16;
    // 801D7E28: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7E2C:
    ctx->pc = 0x801D7E2Cu;
    // 801D7E2C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7E30:
    ctx->pc = 0x801D7E30u;
    // 801D7E30: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7E34:
    ctx->pc = 0x801D7E34u;
    // 801D7E34: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7E38:
    ctx->pc = 0x801D7E38u;
    // 801D7E38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7E3C:
    ctx->pc = 0x801D7E3Cu;
    ctx->downcount -= 16;
    // 801D7E3C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7E40:
    ctx->pc = 0x801D7E40u;
    // 801D7E40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7E44:
    ctx->pc = 0x801D7E44u;
    // 801D7E44: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7E48:
    ctx->pc = 0x801D7E48u;
    // 801D7E48: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7E4C:
    ctx->pc = 0x801D7E4Cu;
    // 801D7E4C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7E50:
    ctx->pc = 0x801D7E50u;
    // 801D7E50: bl      0x801D7DCC
    {
            ctx->lr = 0x801D7E54u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7DCCu;
                return;
            }
            goto label_801D7DCC;
    }

label_801D7E54:
    ctx->pc = 0x801D7E54u;
    ctx->downcount -= 5;
    // 801D7E54: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801D7E58:
    ctx->pc = 0x801D7E58u;
    // 801D7E58: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D7E5C:
    ctx->pc = 0x801D7E5Cu;
    // 801D7E5C: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D7E60:
    ctx->pc = 0x801D7E60u;
    // 801D7E60: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D7E64:
    loop_801D7E64(ctx);
    if (ctx->pc == 0x801D7E78u) goto label_801D7E78;
    return;
label_801D7E68:
    ctx->pc = 0x801D7E68u;
    // 801D7E68: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7E6C:
    ctx->pc = 0x801D7E6Cu;
    // 801D7E6C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7E70:
    // 801D7E70: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D7E74:
    // 801D7E74: bc    16, 0, 0x801D7E64
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7E64u;
                return;
            }
            goto label_801D7E64;
        }
    }

label_801D7E78:
    ctx->pc = 0x801D7E78u;
    ctx->downcount -= 16;
    // 801D7E78: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7E7C:
    ctx->pc = 0x801D7E7Cu;
    // 801D7E7C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7E80:
    ctx->pc = 0x801D7E80u;
    // 801D7E80: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7E84:
    ctx->pc = 0x801D7E84u;
    // 801D7E84: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D7E88:
    ctx->pc = 0x801D7E88u;
    // 801D7E88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7E8C:
    ctx->pc = 0x801D7E8Cu;
    ctx->downcount -= 4;
    // 801D7E8C: lwz     r9, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7E90:
    ctx->pc = 0x801D7E90u;
    // 801D7E90: lwz     r10, 504(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(504);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D7E94:
    ctx->pc = 0x801D7E94u;
    // 801D7E94: cmpwi   r9, 0
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

label_801D7E98:
    ctx->pc = 0x801D7E98u;
    // 801D7E98: bc    12, 2, 0x801D7EA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7EA4;
        }
    }

label_801D7E9C:
    ctx->pc = 0x801D7E9Cu;
    ctx->downcount -= 2;
    // 801D7E9C: stw     r10, 504(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7EA0:
    ctx->pc = 0x801D7EA0u;
    // 801D7EA0: b       0x801D7EAC
    {
            goto label_801D7EAC;
    }

label_801D7EA4:
    ctx->pc = 0x801D7EA4u;
    ctx->downcount -= 2;
    // 801D7EA4: lwz     r9, 516(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(516);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7EA8:
    ctx->pc = 0x801D7EA8u;
    // 801D7EA8: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D7EAC:
    ctx->pc = 0x801D7EACu;
    ctx->downcount -= 3;
    // 801D7EAC: lwz     r9, 504(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(504);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7EB0:
    ctx->pc = 0x801D7EB0u;
    // 801D7EB0: cmpwi   r9, 0
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

label_801D7EB4:
    ctx->pc = 0x801D7EB4u;
    // 801D7EB4: bc    12, 2, 0x801D7EC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7EC4;
        }
    }

label_801D7EB8:
    ctx->pc = 0x801D7EB8u;
    ctx->downcount -= 3;
    // 801D7EB8: lwz     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7EBC:
    ctx->pc = 0x801D7EBCu;
    // 801D7EBC: stw     r0, 508(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7EC0:
    ctx->pc = 0x801D7EC0u;
    // 801D7EC0: b       0x801D7ED0
    {
            goto label_801D7ED0;
    }

label_801D7EC4:
    ctx->pc = 0x801D7EC4u;
    ctx->downcount -= 3;
    // 801D7EC4: lwz     r9, 516(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(516);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7EC8:
    ctx->pc = 0x801D7EC8u;
    // 801D7EC8: lwz     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7ECC:
    ctx->pc = 0x801D7ECCu;
    // 801D7ECC: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7ED0:
    ctx->pc = 0x801D7ED0u;
    ctx->downcount -= 6;
    // 801D7ED0: lwz     r11, 516(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(516);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D7ED4:
    ctx->pc = 0x801D7ED4u;
    // 801D7ED4: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D7ED8:
    ctx->pc = 0x801D7ED8u;
    // 801D7ED8: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7EDC:
    ctx->pc = 0x801D7EDCu;
    // 801D7EDC: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D7EE0:
    ctx->pc = 0x801D7EE0u;
    // 801D7EE0: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7EE4:
    ctx->pc = 0x801D7EE4u;
    // 801D7EE4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7EE8:
    ctx->pc = 0x801D7EE8u;
    ctx->downcount -= 18;
    // 801D7EE8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7EEC:
    ctx->pc = 0x801D7EECu;
    // 801D7EEC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7EF0:
    ctx->pc = 0x801D7EF0u;
    // 801D7EF0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7EF4:
    ctx->pc = 0x801D7EF4u;
    // 801D7EF4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7EF8:
    ctx->pc = 0x801D7EF8u;
    // 801D7EF8: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D7EFC:
    ctx->pc = 0x801D7EFCu;
    // 801D7EFC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7F00:
    ctx->pc = 0x801D7F00u;
    // 801D7F00: cmpwi   r31, 0
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

label_801D7F04:
    ctx->pc = 0x801D7F04u;
    // 801D7F04: bc    12, 2, 0x801D7F28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7F28;
        }
    }

label_801D7F08:
    ctx->downcount -= 2;
    // 801D7F08: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7F0C:
    // 801D7F0C: bl      0x801D7E8C
    {
            ctx->lr = 0x801D7F10u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7E8Cu;
                return;
            }
            goto label_801D7E8C;
    }

label_801D7F10:
    ctx->downcount -= 4;
    // 801D7F10: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7F14:
    // 801D7F14: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7F18:
    // 801D7F18: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D7F1C:
    // 801D7F1C: bl      0x801D7D10
    {
            ctx->lr = 0x801D7F20u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7D10u;
                return;
            }
            goto label_801D7D10;
    }

label_801D7F20:
    ctx->downcount -= 2;
    // 801D7F20: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7F24:
    // 801D7F24: bc    4, 2, 0x801D7F08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7F08u;
                return;
            }
            goto label_801D7F08;
        }
    }

label_801D7F28:
    ctx->pc = 0x801D7F28u;
    ctx->downcount -= 16;
    // 801D7F28: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7F2C:
    ctx->pc = 0x801D7F2Cu;
    // 801D7F2C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7F30:
    ctx->pc = 0x801D7F30u;
    // 801D7F30: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7F34:
    ctx->pc = 0x801D7F34u;
    // 801D7F34: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7F38:
    ctx->pc = 0x801D7F38u;
    // 801D7F38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7F3C:
    ctx->pc = 0x801D7F3Cu;
    ctx->downcount -= 17;
    // 801D7F3C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7F40:
    ctx->pc = 0x801D7F40u;
    // 801D7F40: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7F44:
    ctx->pc = 0x801D7F44u;
    // 801D7F44: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7F48:
    ctx->pc = 0x801D7F48u;
    // 801D7F48: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7F4C:
    ctx->pc = 0x801D7F4Cu;
    // 801D7F4C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7F50:
    ctx->pc = 0x801D7F50u;
    // 801D7F50: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_801D7F54:
    ctx->pc = 0x801D7F54u;
    // 801D7F54: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_801D7F58:
    ctx->downcount -= 3;
    // 801D7F58: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7F5C:
    // 801D7F5C: addi    r4, r30, 8
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(8);

label_801D7F60:
    // 801D7F60: bl      0x801D7EE8
    {
            ctx->lr = 0x801D7F64u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7EE8u;
                return;
            }
            goto label_801D7EE8;
    }

label_801D7F64:
    ctx->downcount -= 3;
    // 801D7F64: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801D7F68:
    // 801D7F68: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D7F6C:
    // 801D7F6C: bc    4, 2, 0x801D7F58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7F58u;
                return;
            }
            goto label_801D7F58;
        }
    }

label_801D7F70:
    ctx->pc = 0x801D7F70u;
    ctx->downcount -= 16;
    // 801D7F70: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7F74:
    ctx->pc = 0x801D7F74u;
    // 801D7F74: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D7F78:
    ctx->pc = 0x801D7F78u;
    // 801D7F78: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D7F7C:
    ctx->pc = 0x801D7F7Cu;
    // 801D7F7C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D7F80:
    ctx->pc = 0x801D7F80u;
    // 801D7F80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7F84:
    ctx->pc = 0x801D7F84u;
    ctx->downcount -= 2;
    // 801D7F84: or.   r4, r4, r4
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

label_801D7F88:
    ctx->pc = 0x801D7F88u;
    // 801D7F88: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7F8C:
    ctx->pc = 0x801D7F8Cu;
    ctx->downcount -= 8;
    // 801D7F8C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801D7F90:
    ctx->pc = 0x801D7F90u;
    // 801D7F90: stw     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D7F94:
    ctx->pc = 0x801D7F94u;
    // 801D7F94: stw     r9, 504(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7F98:
    ctx->pc = 0x801D7F98u;
    // 801D7F98: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D7F9C:
    ctx->pc = 0x801D7F9Cu;
    // 801D7F9C: stw     r0, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7FA0:
    ctx->pc = 0x801D7FA0u;
    // 801D7FA0: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7FA4:
    ctx->pc = 0x801D7FA4u;
    // 801D7FA4: cmpwi   r9, 0
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

label_801D7FA8:
    ctx->pc = 0x801D7FA8u;
    // 801D7FA8: bc    12, 2, 0x801D7FB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D7FB4;
        }
    }

label_801D7FAC:
    ctx->pc = 0x801D7FACu;
    ctx->downcount -= 2;
    // 801D7FAC: stw     r4, 504(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7FB0:
    ctx->pc = 0x801D7FB0u;
    // 801D7FB0: b       0x801D7FB8
    {
            goto label_801D7FB8;
    }

label_801D7FB4:
    ctx->pc = 0x801D7FB4u;
    ctx->downcount -= 1;
    // 801D7FB4: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7FB8:
    ctx->pc = 0x801D7FB8u;
    ctx->downcount -= 5;
    // 801D7FB8: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D7FBC:
    ctx->pc = 0x801D7FBCu;
    // 801D7FBC: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D7FC0:
    ctx->pc = 0x801D7FC0u;
    // 801D7FC0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D7FC4:
    ctx->pc = 0x801D7FC4u;
    // 801D7FC4: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D7FC8:
    ctx->pc = 0x801D7FC8u;
    // 801D7FC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D7FCC:
    ctx->pc = 0x801D7FCCu;
    ctx->downcount -= 21;
    // 801D7FCC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D7FD0:
    ctx->pc = 0x801D7FD0u;
    // 801D7FD0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D7FD4:
    ctx->pc = 0x801D7FD4u;
    // 801D7FD4: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D7FD8:
    ctx->pc = 0x801D7FD8u;
    // 801D7FD8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D7FDC:
    ctx->pc = 0x801D7FDCu;
    // 801D7FDC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D7FE0:
    ctx->pc = 0x801D7FE0u;
    // 801D7FE0: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D7FE4:
    ctx->pc = 0x801D7FE4u;
    // 801D7FE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D7FE8:
    ctx->pc = 0x801D7FE8u;
    // 801D7FE8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D7FEC:
    ctx->pc = 0x801D7FECu;
    // 801D7FEC: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D7FF0:
    ctx->pc = 0x801D7FF0u;
    // 801D7FF0: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D7FF4:
    ctx->pc = 0x801D7FF4u;
    // 801D7FF4: bc    12, 18, 0x801D802C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D802C;
        }
    }

label_801D7FF8:
    ctx->pc = 0x801D7FF8u;
    ctx->downcount -= 2;
    // 801D7FF8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D7FFC:
    ctx->pc = 0x801D7FFCu;
    // 801D7FFC: bl      0x801D7E8C
    {
            ctx->lr = 0x801D8000u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7E8Cu;
                return;
            }
            goto label_801D7E8C;
    }

label_801D8000:
    ctx->pc = 0x801D8000u;
    ctx->downcount -= 6;
    // 801D8000: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8004:
    ctx->pc = 0x801D8004u;
    // 801D8004: stw     r0, 516(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(516);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8008:
    ctx->pc = 0x801D8008u;
    // 801D8008: stw     r0, 504(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D800C:
    ctx->pc = 0x801D800Cu;
    // 801D800C: stw     r0, 508(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8010:
    ctx->pc = 0x801D8010u;
    // 801D8010: stw     r0, 512(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(512);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8014:
    ctx->pc = 0x801D8014u;
    // 801D8014: bc    12, 18, 0x801D802C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D802C;
        }
    }

label_801D8018:
    ctx->pc = 0x801D8018u;
    ctx->downcount -= 7;
    // 801D8018: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D801C:
    ctx->pc = 0x801D801Cu;
    // 801D801C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8020:
    ctx->pc = 0x801D8020u;
    // 801D8020: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D8024:
    ctx->pc = 0x801D8024u;
    // 801D8024: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D8028:
    ctx->pc = 0x801D8028u;
    // 801D8028: bl      0x801D7F84
    {
            ctx->lr = 0x801D802Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7F84u;
                return;
            }
            goto label_801D7F84;
    }

label_801D802C:
    ctx->pc = 0x801D802Cu;
    ctx->downcount -= 19;
    // 801D802C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8030:
    ctx->pc = 0x801D8030u;
    // 801D8030: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8034:
    ctx->pc = 0x801D8034u;
    // 801D8034: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D8038:
    ctx->pc = 0x801D8038u;
    // 801D8038: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D803C:
    ctx->pc = 0x801D803Cu;
    // 801D803C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8040:
    ctx->pc = 0x801D8040u;
    // 801D8040: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D8044:
    ctx->pc = 0x801D8044u;
    // 801D8044: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8048:
    ctx->pc = 0x801D8048u;
    // 801D8048: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D804C:
    ctx->pc = 0x801D804Cu;
    ctx->downcount -= 3;
    // 801D804C: stfs     f2, 232(r3)
    if (!ppc_fp_available(ctx, 0x801D804Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(232);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_801D8050:
    ctx->pc = 0x801D8050u;
    // 801D8050: stfs     f1, 228(r3)
    if (!ppc_fp_available(ctx, 0x801D8050u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(228);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_801D8054:
    ctx->pc = 0x801D8054u;
    // 801D8054: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8058:
    ctx->pc = 0x801D8058u;
    ctx->downcount -= 4;
    // 801D8058: lwz     r9, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D805C:
    ctx->pc = 0x801D805Cu;
    // 801D805C: lwz     r10, 144(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D8060:
    ctx->pc = 0x801D8060u;
    // 801D8060: cmpwi   r9, 0
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

label_801D8064:
    ctx->pc = 0x801D8064u;
    // 801D8064: bc    12, 2, 0x801D8070
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8070;
        }
    }

label_801D8068:
    ctx->pc = 0x801D8068u;
    ctx->downcount -= 2;
    // 801D8068: stw     r10, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D806C:
    ctx->pc = 0x801D806Cu;
    // 801D806C: b       0x801D8078
    {
            goto label_801D8078;
    }

label_801D8070:
    ctx->pc = 0x801D8070u;
    ctx->downcount -= 2;
    // 801D8070: lwz     r9, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8074:
    ctx->pc = 0x801D8074u;
    // 801D8074: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8078:
    ctx->pc = 0x801D8078u;
    ctx->downcount -= 3;
    // 801D8078: lwz     r9, 144(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(144);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D807C:
    ctx->pc = 0x801D807Cu;
    // 801D807C: cmpwi   r9, 0
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

label_801D8080:
    ctx->pc = 0x801D8080u;
    // 801D8080: bc    12, 2, 0x801D8090
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8090;
        }
    }

label_801D8084:
    ctx->pc = 0x801D8084u;
    ctx->downcount -= 3;
    // 801D8084: lwz     r0, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8088:
    ctx->pc = 0x801D8088u;
    // 801D8088: stw     r0, 148(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D808C:
    ctx->pc = 0x801D808Cu;
    // 801D808C: b       0x801D809C
    {
            goto label_801D809C;
    }

label_801D8090:
    ctx->pc = 0x801D8090u;
    ctx->downcount -= 3;
    // 801D8090: lwz     r9, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8094:
    ctx->pc = 0x801D8094u;
    // 801D8094: lwz     r0, 148(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(148);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8098:
    ctx->pc = 0x801D8098u;
    // 801D8098: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D809C:
    ctx->pc = 0x801D809Cu;
    ctx->downcount -= 6;
    // 801D809C: lwz     r11, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D80A0:
    ctx->pc = 0x801D80A0u;
    // 801D80A0: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D80A4:
    ctx->pc = 0x801D80A4u;
    // 801D80A4: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D80A8:
    ctx->pc = 0x801D80A8u;
    // 801D80A8: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D80AC:
    ctx->pc = 0x801D80ACu;
    // 801D80AC: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D80B0:
    ctx->pc = 0x801D80B0u;
    // 801D80B0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D80B4:
    ctx->pc = 0x801D80B4u;
    ctx->downcount -= 2;
    // 801D80B4: or.   r4, r4, r4
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

label_801D80B8:
    ctx->pc = 0x801D80B8u;
    // 801D80B8: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D80BC:
    ctx->pc = 0x801D80BCu;
    ctx->downcount -= 8;
    // 801D80BC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801D80C0:
    ctx->pc = 0x801D80C0u;
    // 801D80C0: stw     r3, 156(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D80C4:
    ctx->pc = 0x801D80C4u;
    // 801D80C4: stw     r9, 144(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D80C8:
    ctx->pc = 0x801D80C8u;
    // 801D80C8: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D80CC:
    ctx->pc = 0x801D80CCu;
    // 801D80CC: stw     r0, 148(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D80D0:
    ctx->pc = 0x801D80D0u;
    // 801D80D0: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D80D4:
    ctx->pc = 0x801D80D4u;
    // 801D80D4: cmpwi   r9, 0
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

label_801D80D8:
    ctx->pc = 0x801D80D8u;
    // 801D80D8: bc    12, 2, 0x801D80E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D80E4;
        }
    }

label_801D80DC:
    ctx->pc = 0x801D80DCu;
    ctx->downcount -= 2;
    // 801D80DC: stw     r4, 144(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D80E0:
    ctx->pc = 0x801D80E0u;
    // 801D80E0: b       0x801D80E8
    {
            goto label_801D80E8;
    }

label_801D80E4:
    ctx->pc = 0x801D80E4u;
    ctx->downcount -= 1;
    // 801D80E4: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D80E8:
    ctx->pc = 0x801D80E8u;
    ctx->downcount -= 5;
    // 801D80E8: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D80EC:
    ctx->pc = 0x801D80ECu;
    // 801D80EC: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D80F0:
    ctx->pc = 0x801D80F0u;
    // 801D80F0: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D80F4:
    ctx->pc = 0x801D80F4u;
    // 801D80F4: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D80F8:
    ctx->pc = 0x801D80F8u;
    // 801D80F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D80FC:
    ctx->pc = 0x801D80FCu;
    ctx->downcount -= 21;
    // 801D80FC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8100:
    ctx->pc = 0x801D8100u;
    // 801D8100: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8104:
    ctx->pc = 0x801D8104u;
    // 801D8104: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D8108:
    ctx->pc = 0x801D8108u;
    // 801D8108: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D810C:
    ctx->pc = 0x801D810Cu;
    // 801D810C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8110:
    ctx->pc = 0x801D8110u;
    // 801D8110: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D8114:
    ctx->pc = 0x801D8114u;
    // 801D8114: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8118:
    ctx->pc = 0x801D8118u;
    // 801D8118: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D811C:
    ctx->pc = 0x801D811Cu;
    // 801D811C: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8120:
    ctx->pc = 0x801D8120u;
    // 801D8120: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D8124:
    ctx->pc = 0x801D8124u;
    // 801D8124: bc    12, 18, 0x801D815C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D815C;
        }
    }

label_801D8128:
    ctx->pc = 0x801D8128u;
    ctx->downcount -= 2;
    // 801D8128: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D812C:
    ctx->pc = 0x801D812Cu;
    // 801D812C: bl      0x801D8058
    {
            ctx->lr = 0x801D8130u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8058u;
                return;
            }
            goto label_801D8058;
    }

label_801D8130:
    ctx->pc = 0x801D8130u;
    ctx->downcount -= 6;
    // 801D8130: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8134:
    ctx->pc = 0x801D8134u;
    // 801D8134: stw     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8138:
    ctx->pc = 0x801D8138u;
    // 801D8138: stw     r0, 144(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D813C:
    ctx->pc = 0x801D813Cu;
    // 801D813C: stw     r0, 148(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8140:
    ctx->pc = 0x801D8140u;
    // 801D8140: stw     r0, 152(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8144:
    ctx->pc = 0x801D8144u;
    // 801D8144: bc    12, 18, 0x801D815C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D815C;
        }
    }

label_801D8148:
    ctx->pc = 0x801D8148u;
    ctx->downcount -= 7;
    // 801D8148: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D814C:
    ctx->pc = 0x801D814Cu;
    // 801D814C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8150:
    ctx->pc = 0x801D8150u;
    // 801D8150: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D8154:
    ctx->pc = 0x801D8154u;
    // 801D8154: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D8158:
    ctx->pc = 0x801D8158u;
    // 801D8158: bl      0x801D80B4
    {
            ctx->lr = 0x801D815Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D80B4u;
                return;
            }
            goto label_801D80B4;
    }

label_801D815C:
    ctx->pc = 0x801D815Cu;
    ctx->downcount -= 19;
    // 801D815C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8160:
    ctx->pc = 0x801D8160u;
    // 801D8160: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8164:
    ctx->pc = 0x801D8164u;
    // 801D8164: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D8168:
    ctx->pc = 0x801D8168u;
    // 801D8168: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D816C:
    ctx->pc = 0x801D816Cu;
    // 801D816C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8170:
    ctx->pc = 0x801D8170u;
    // 801D8170: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D8174:
    ctx->pc = 0x801D8174u;
    // 801D8174: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8178:
    ctx->pc = 0x801D8178u;
    // 801D8178: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D817C:
    ctx->pc = 0x801D817Cu;
    ctx->downcount -= 4;
    // 801D817C: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8180:
    ctx->pc = 0x801D8180u;
    // 801D8180: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_801D8184:
    ctx->pc = 0x801D8184u;
    // 801D8184: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8188:
    ctx->pc = 0x801D8188u;
    // 801D8188: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D818C:
    ctx->pc = 0x801D818Cu;
    ctx->downcount -= 12;
    // 801D818C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8190:
    ctx->pc = 0x801D8190u;
    // 801D8190: addi    r9, r3, 8
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(8);

label_801D8194:
    ctx->pc = 0x801D8194u;
    // 801D8194: stw     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8198:
    ctx->pc = 0x801D8198u;
    // 801D8198: addi    r11, r3, 20
    ctx->gpr[11] = ctx->gpr[3] + (u32)(s32)(20);

label_801D819C:
    ctx->pc = 0x801D819Cu;
    // 801D819C: stw     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D81A0:
    ctx->pc = 0x801D81A0u;
    // 801D81A0: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_801D81A4:
    ctx->pc = 0x801D81A4u;
    // 801D81A4: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D81A8:
    ctx->pc = 0x801D81A8u;
    // 801D81A8: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D81AC:
    ctx->pc = 0x801D81ACu;
    // 801D81AC: li      r9, 3
    ctx->gpr[9] = (u32)(s32)(3);

label_801D81B0:
    ctx->pc = 0x801D81B0u;
    // 801D81B0: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D81B4:
    ctx->pc = 0x801D81B4u;
    // 801D81B4: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D81B8:
    loop_801D81B8(ctx);
    if (ctx->pc == 0x801D81CCu) goto label_801D81CC;
    return;
label_801D81BC:
    ctx->pc = 0x801D81BCu;
    // 801D81BC: stw     r10, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D81C0:
    ctx->pc = 0x801D81C0u;
    // 801D81C0: stw     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D81C4:
    // 801D81C4: addi    r11, r11, 12
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(12);

label_801D81C8:
    // 801D81C8: bc    16, 0, 0x801D81B8
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D81B8u;
                return;
            }
            goto label_801D81B8;
        }
    }

label_801D81CC:
    ctx->pc = 0x801D81CCu;
    ctx->downcount -= 1;
    // 801D81CC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D81D0:
    ctx->pc = 0x801D81D0u;
    ctx->downcount -= 2;
    // 801D81D0: or.   r4, r4, r4
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

label_801D81D4:
    ctx->pc = 0x801D81D4u;
    // 801D81D4: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D81D8:
    ctx->pc = 0x801D81D8u;
    ctx->downcount -= 8;
    // 801D81D8: stw     r3, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D81DC:
    ctx->pc = 0x801D81DCu;
    // 801D81DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D81E0:
    ctx->pc = 0x801D81E0u;
    // 801D81E0: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D81E4:
    ctx->pc = 0x801D81E4u;
    // 801D81E4: stw     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D81E8:
    ctx->pc = 0x801D81E8u;
    // 801D81E8: stw     r9, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D81EC:
    ctx->pc = 0x801D81ECu;
    // 801D81EC: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D81F0:
    ctx->pc = 0x801D81F0u;
    // 801D81F0: cmpwi   r9, 0
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

label_801D81F4:
    ctx->pc = 0x801D81F4u;
    // 801D81F4: bc    12, 2, 0x801D8200
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8200;
        }
    }

label_801D81F8:
    ctx->pc = 0x801D81F8u;
    ctx->downcount -= 2;
    // 801D81F8: stw     r4, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D81FC:
    ctx->pc = 0x801D81FCu;
    // 801D81FC: b       0x801D8204
    {
            goto label_801D8204;
    }

label_801D8200:
    ctx->pc = 0x801D8200u;
    ctx->downcount -= 1;
    // 801D8200: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8204:
    ctx->pc = 0x801D8204u;
    ctx->downcount -= 5;
    // 801D8204: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8208:
    ctx->pc = 0x801D8208u;
    // 801D8208: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D820C:
    ctx->pc = 0x801D820Cu;
    // 801D820C: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D8210:
    ctx->pc = 0x801D8210u;
    // 801D8210: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8214:
    ctx->pc = 0x801D8214u;
    // 801D8214: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8218:
    ctx->pc = 0x801D8218u;
    ctx->downcount -= 20;
    // 801D8218: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D821C:
    ctx->pc = 0x801D821Cu;
    // 801D821C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8220:
    ctx->pc = 0x801D8220u;
    // 801D8220: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8224:
    ctx->pc = 0x801D8224u;
    // 801D8224: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8228:
    ctx->pc = 0x801D8228u;
    // 801D8228: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D822C:
    ctx->pc = 0x801D822Cu;
    // 801D822C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D8230:
    ctx->pc = 0x801D8230u;
    // 801D8230: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8234:
    ctx->pc = 0x801D8234u;
    // 801D8234: cmpwi   r4, 0
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

label_801D8238:
    ctx->pc = 0x801D8238u;
    // 801D8238: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D823C:
    ctx->pc = 0x801D823Cu;
    // 801D823C: bc    12, 2, 0x801D8278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8278;
        }
    }

label_801D8240:
    ctx->pc = 0x801D8240u;
    ctx->downcount -= 3;
    // 801D8240: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8244:
    ctx->pc = 0x801D8244u;
    // 801D8244: cmpwi   r30, 0
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

label_801D8248:
    ctx->pc = 0x801D8248u;
    // 801D8248: bc    12, 2, 0x801D8278
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8278;
        }
    }

label_801D824C:
    ctx->pc = 0x801D824Cu;
    ctx->downcount -= 1;
    // 801D824C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D8250:
    ctx->pc = 0x801D8250u;
    ctx->downcount -= 8;
    // 801D8250: stw     r29, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8254:
    // 801D8254: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8258:
    ctx->pc = 0x801D8258u;
    // 801D8258: stw     r29, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D825C:
    // 801D825C: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D8260:
    ctx->pc = 0x801D8260u;
    // 801D8260: stw     r29, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8264:
    ctx->pc = 0x801D8264u;
    // 801D8264: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8268:
    // 801D8268: addi    r31, r31, 24
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(24);

label_801D826C:
    // 801D826C: bl      0x801D81D0
    {
            ctx->lr = 0x801D8270u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D81D0u;
                return;
            }
            goto label_801D81D0;
    }

label_801D8270:
    ctx->downcount -= 2;
    // 801D8270: addic.  r30, r30, -1
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

label_801D8274:
    // 801D8274: bc    4, 2, 0x801D8250
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8250u;
                return;
            }
            goto label_801D8250;
        }
    }

label_801D8278:
    ctx->pc = 0x801D8278u;
    ctx->downcount -= 16;
    // 801D8278: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D827C:
    ctx->pc = 0x801D827Cu;
    // 801D827C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8280:
    ctx->pc = 0x801D8280u;
    // 801D8280: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8284:
    ctx->pc = 0x801D8284u;
    // 801D8284: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8288:
    ctx->pc = 0x801D8288u;
    // 801D8288: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D828C:
    ctx->pc = 0x801D828Cu;
    ctx->downcount -= 29;
    // 801D828C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8290:
    ctx->pc = 0x801D8290u;
    // 801D8290: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8294:
    ctx->pc = 0x801D8294u;
    // 801D8294: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8298:
    ctx->pc = 0x801D8298u;
    // 801D8298: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D829C:
    ctx->pc = 0x801D829Cu;
    // 801D829C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D82A0:
    ctx->pc = 0x801D82A0u;
    // 801D82A0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D82A4:
    ctx->pc = 0x801D82A4u;
    // 801D82A4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D82A8:
    ctx->pc = 0x801D82A8u;
    // 801D82A8: mulli   r4, r29, 24
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)24);

label_801D82AC:
    ctx->pc = 0x801D82ACu;
    // 801D82AC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D82B0:
    ctx->pc = 0x801D82B0u;
    // 801D82B0: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D82B4:
    ctx->pc = 0x801D82B4u;
    // 801D82B4: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D82B8:
    ctx->pc = 0x801D82B8u;
    // 801D82B8: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D82BC:
    ctx->pc = 0x801D82BCu;
    // 801D82BC: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D82C0:
    ctx->pc = 0x801D82C0u;
    // 801D82C0: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D82C4:
    ctx->pc = 0x801D82C4u;
    // 801D82C4: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D82C8:
    ctx->pc = 0x801D82C8u;
    // 801D82C8: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D82CC:
    ctx->pc = 0x801D82CCu;
    // 801D82CC: bl      0x80039640
    {
            ctx->lr = 0x801D82D0u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D82D0:
    ctx->pc = 0x801D82D0u;
    ctx->downcount -= 4;
    // 801D82D0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D82D4:
    ctx->pc = 0x801D82D4u;
    // 801D82D4: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D82D8:
    ctx->pc = 0x801D82D8u;
    // 801D82D8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D82DC:
    ctx->pc = 0x801D82DCu;
    // 801D82DC: bl      0x801D8218
    {
            ctx->lr = 0x801D82E0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8218u;
                return;
            }
            goto label_801D8218;
    }

label_801D82E0:
    ctx->pc = 0x801D82E0u;
    ctx->downcount -= 16;
    // 801D82E0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D82E4:
    ctx->pc = 0x801D82E4u;
    // 801D82E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D82E8:
    ctx->pc = 0x801D82E8u;
    // 801D82E8: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D82EC:
    ctx->pc = 0x801D82ECu;
    // 801D82EC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D82F0:
    ctx->pc = 0x801D82F0u;
    // 801D82F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D82F4:
    ctx->pc = 0x801D82F4u;
    ctx->downcount -= 16;
    // 801D82F4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D82F8:
    ctx->pc = 0x801D82F8u;
    // 801D82F8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D82FC:
    ctx->pc = 0x801D82FCu;
    // 801D82FC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8300:
    ctx->pc = 0x801D8300u;
    // 801D8300: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8304:
    ctx->pc = 0x801D8304u;
    // 801D8304: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8308:
    ctx->pc = 0x801D8308u;
    // 801D8308: bl      0x801D828C
    {
            ctx->lr = 0x801D830Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D828Cu;
                return;
            }
            goto label_801D828C;
    }

label_801D830C:
    ctx->pc = 0x801D830Cu;
    ctx->downcount -= 5;
    // 801D830C: li      r9, 3
    ctx->gpr[9] = (u32)(s32)(3);

label_801D8310:
    ctx->pc = 0x801D8310u;
    // 801D8310: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8314:
    ctx->pc = 0x801D8314u;
    // 801D8314: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D8318:
    ctx->pc = 0x801D8318u;
    // 801D8318: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D831C:
    loop_801D831C(ctx);
    if (ctx->pc == 0x801D8330u) goto label_801D8330;
    return;
label_801D8320:
    ctx->pc = 0x801D8320u;
    // 801D8320: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8324:
    ctx->pc = 0x801D8324u;
    // 801D8324: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8328:
    // 801D8328: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D832C:
    // 801D832C: bc    16, 0, 0x801D831C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D831Cu;
                return;
            }
            goto label_801D831C;
        }
    }

label_801D8330:
    ctx->pc = 0x801D8330u;
    ctx->downcount -= 16;
    // 801D8330: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8334:
    ctx->pc = 0x801D8334u;
    // 801D8334: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8338:
    ctx->pc = 0x801D8338u;
    // 801D8338: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D833C:
    ctx->pc = 0x801D833Cu;
    // 801D833C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D8340:
    ctx->pc = 0x801D8340u;
    // 801D8340: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8344:
    ctx->pc = 0x801D8344u;
    ctx->downcount -= 18;
    // 801D8344: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8348:
    ctx->pc = 0x801D8348u;
    // 801D8348: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D834C:
    ctx->pc = 0x801D834Cu;
    // 801D834C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8350:
    ctx->pc = 0x801D8350u;
    // 801D8350: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8354:
    ctx->pc = 0x801D8354u;
    // 801D8354: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8358:
    ctx->pc = 0x801D8358u;
    // 801D8358: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D835C:
    ctx->pc = 0x801D835Cu;
    // 801D835C: cmpwi   r31, 0
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

label_801D8360:
    ctx->pc = 0x801D8360u;
    // 801D8360: bc    12, 2, 0x801D8384
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8384;
        }
    }

label_801D8364:
    ctx->downcount -= 2;
    // 801D8364: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8368:
    // 801D8368: bl      0x801D6D60
    {
            ctx->lr = 0x801D836Cu;
            ctx->pc = 0x801D6D60u;
            return;
    }

label_801D836C:
    ctx->downcount -= 4;
    // 801D836C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8370:
    // 801D8370: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8374:
    // 801D8374: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D8378:
    // 801D8378: bl      0x801D81D0
    {
            ctx->lr = 0x801D837Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D81D0u;
                return;
            }
            goto label_801D81D0;
    }

label_801D837C:
    ctx->downcount -= 2;
    // 801D837C: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8380:
    // 801D8380: bc    4, 2, 0x801D8364
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8364u;
                return;
            }
            goto label_801D8364;
        }
    }

label_801D8384:
    ctx->pc = 0x801D8384u;
    ctx->downcount -= 16;
    // 801D8384: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8388:
    ctx->pc = 0x801D8388u;
    // 801D8388: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D838C:
    ctx->pc = 0x801D838Cu;
    // 801D838C: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8390:
    ctx->pc = 0x801D8390u;
    // 801D8390: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8394:
    ctx->pc = 0x801D8394u;
    // 801D8394: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8398:
    ctx->pc = 0x801D8398u;
    ctx->downcount -= 17;
    // 801D8398: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D839C:
    ctx->pc = 0x801D839Cu;
    // 801D839C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D83A0:
    ctx->pc = 0x801D83A0u;
    // 801D83A0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D83A4:
    ctx->pc = 0x801D83A4u;
    // 801D83A4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D83A8:
    ctx->pc = 0x801D83A8u;
    // 801D83A8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D83AC:
    ctx->pc = 0x801D83ACu;
    // 801D83AC: li      r29, 3
    ctx->gpr[29] = (u32)(s32)(3);

label_801D83B0:
    ctx->pc = 0x801D83B0u;
    // 801D83B0: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_801D83B4:
    ctx->downcount -= 3;
    // 801D83B4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D83B8:
    // 801D83B8: addi    r4, r30, 8
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(8);

label_801D83BC:
    // 801D83BC: bl      0x801D8344
    {
            ctx->lr = 0x801D83C0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8344u;
                return;
            }
            goto label_801D8344;
    }

label_801D83C0:
    ctx->downcount -= 3;
    // 801D83C0: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801D83C4:
    // 801D83C4: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D83C8:
    // 801D83C8: bc    4, 2, 0x801D83B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D83B4u;
                return;
            }
            goto label_801D83B4;
        }
    }

label_801D83CC:
    ctx->pc = 0x801D83CCu;
    ctx->downcount -= 16;
    // 801D83CC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D83D0:
    ctx->pc = 0x801D83D0u;
    // 801D83D0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D83D4:
    ctx->pc = 0x801D83D4u;
    // 801D83D4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D83D8:
    ctx->pc = 0x801D83D8u;
    // 801D83D8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D83DC:
    ctx->pc = 0x801D83DCu;
    // 801D83DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D83E0:
    ctx->pc = 0x801D83E0u;
    ctx->downcount -= 2;
    // 801D83E0: or.   r4, r4, r4
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

label_801D83E4:
    ctx->pc = 0x801D83E4u;
    // 801D83E4: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D83E8:
    ctx->pc = 0x801D83E8u;
    ctx->downcount -= 8;
    // 801D83E8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801D83EC:
    ctx->pc = 0x801D83ECu;
    // 801D83EC: stw     r3, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D83F0:
    ctx->pc = 0x801D83F0u;
    // 801D83F0: stw     r9, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D83F4:
    ctx->pc = 0x801D83F4u;
    // 801D83F4: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D83F8:
    ctx->pc = 0x801D83F8u;
    // 801D83F8: stw     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D83FC:
    ctx->pc = 0x801D83FCu;
    // 801D83FC: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8400:
    ctx->pc = 0x801D8400u;
    // 801D8400: cmpwi   r9, 0
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

label_801D8404:
    ctx->pc = 0x801D8404u;
    // 801D8404: bc    12, 2, 0x801D8410
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8410;
        }
    }

label_801D8408:
    ctx->pc = 0x801D8408u;
    ctx->downcount -= 2;
    // 801D8408: stw     r4, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D840C:
    ctx->pc = 0x801D840Cu;
    // 801D840C: b       0x801D8414
    {
            goto label_801D8414;
    }

label_801D8410:
    ctx->pc = 0x801D8410u;
    ctx->downcount -= 1;
    // 801D8410: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8414:
    ctx->pc = 0x801D8414u;
    ctx->downcount -= 5;
    // 801D8414: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8418:
    ctx->pc = 0x801D8418u;
    // 801D8418: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D841C:
    ctx->pc = 0x801D841Cu;
    // 801D841C: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D8420:
    ctx->pc = 0x801D8420u;
    // 801D8420: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8424:
    ctx->pc = 0x801D8424u;
    // 801D8424: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8428:
    ctx->pc = 0x801D8428u;
    ctx->downcount -= 5;
    // 801D8428: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D842C:
    ctx->pc = 0x801D842Cu;
    // 801D842C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8430:
    ctx->pc = 0x801D8430u;
    // 801D8430: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8434:
    ctx->pc = 0x801D8434u;
    // 801D8434: or.   r4, r4, r4
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

label_801D8438:
    ctx->pc = 0x801D8438u;
    // 801D8438: bc    12, 2, 0x801D848C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D848C;
        }
    }

label_801D843C:
    ctx->pc = 0x801D843Cu;
    ctx->downcount -= 2;
    // 801D843C: cmpwi   r5, 0
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

label_801D8440:
    ctx->pc = 0x801D8440u;
    // 801D8440: bc    12, 2, 0x801D8488
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8488;
        }
    }

label_801D8444:
    ctx->pc = 0x801D8444u;
    ctx->downcount -= 3;
    // 801D8444: lwz     r0, 12(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8448:
    ctx->pc = 0x801D8448u;
    // 801D8448: cmpwi   r0, 0
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

label_801D844C:
    ctx->pc = 0x801D844Cu;
    // 801D844C: bc    12, 2, 0x801D8480
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8480;
        }
    }

label_801D8450:
    ctx->pc = 0x801D8450u;
    ctx->downcount -= 12;
    // 801D8450: stw     r5, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801D8454:
    ctx->pc = 0x801D8454u;
    // 801D8454: lwz     r0, 12(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8458:
    ctx->pc = 0x801D8458u;
    // 801D8458: stw     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D845C:
    ctx->pc = 0x801D845Cu;
    // 801D845C: lwz     r9, 12(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8460:
    ctx->pc = 0x801D8460u;
    // 801D8460: stw     r4, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8464:
    ctx->pc = 0x801D8464u;
    // 801D8464: stw     r4, 12(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8468:
    ctx->pc = 0x801D8468u;
    // 801D8468: lwz     r0, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D846C:
    ctx->pc = 0x801D846Cu;
    // 801D846C: stw     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8470:
    ctx->pc = 0x801D8470u;
    // 801D8470: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8474:
    ctx->pc = 0x801D8474u;
    // 801D8474: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D8478:
    ctx->pc = 0x801D8478u;
    // 801D8478: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D847C:
    ctx->pc = 0x801D847Cu;
    // 801D847C: b       0x801D848C
    {
            goto label_801D848C;
    }

label_801D8480:
    ctx->pc = 0x801D8480u;
    ctx->downcount -= 1;
    // 801D8480: bl      0x801D81D0
    {
            ctx->lr = 0x801D8484u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D81D0u;
                return;
            }
            goto label_801D81D0;
    }

label_801D8484:
    ctx->pc = 0x801D8484u;
    ctx->downcount -= 1;
    // 801D8484: b       0x801D848C
    {
            goto label_801D848C;
    }

label_801D8488:
    ctx->pc = 0x801D8488u;
    ctx->downcount -= 1;
    // 801D8488: bl      0x801D83E0
    {
            ctx->lr = 0x801D848Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D83E0u;
                return;
            }
            goto label_801D83E0;
    }

label_801D848C:
    ctx->pc = 0x801D848Cu;
    ctx->downcount -= 5;
    // 801D848C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8490:
    ctx->pc = 0x801D8490u;
    // 801D8490: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8494:
    ctx->pc = 0x801D8494u;
    // 801D8494: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801D8498:
    ctx->pc = 0x801D8498u;
    // 801D8498: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D849C:
    ctx->pc = 0x801D849Cu;
    ctx->downcount -= 8;
    // 801D849C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D84A0:
    ctx->pc = 0x801D84A0u;
    // 801D84A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D84A4:
    ctx->pc = 0x801D84A4u;
    // 801D84A4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D84A8:
    ctx->pc = 0x801D84A8u;
    // 801D84A8: or   r9, r5, r5
    {
        ctx->gpr[9] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D84AC:
    ctx->pc = 0x801D84ACu;
    // 801D84AC: stw     r9, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D84B0:
    ctx->pc = 0x801D84B0u;
    // 801D84B0: lwz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801D84B4:
    ctx->pc = 0x801D84B4u;
    // 801D84B4: cmpwi   r5, 0
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

label_801D84B8:
    ctx->pc = 0x801D84B8u;
    // 801D84B8: bc    12, 2, 0x801D84DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D84DC;
        }
    }

label_801D84BC:
    ctx->pc = 0x801D84BCu;
    ctx->downcount -= 3;
    // 801D84BC: lwz     r0, 16(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D84C0:
    // 801D84C0: cmpw    r9, r0
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

label_801D84C4:
    // 801D84C4: bc    12, 0, 0x801D84D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D84D0;
        }
    }

label_801D84C8:
    ctx->downcount -= 1;
    // 801D84C8: bl      0x801D8428
    {
            ctx->lr = 0x801D84CCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8428u;
                return;
            }
            goto label_801D8428;
    }

label_801D84CC:
    ctx->downcount -= 1;
    // 801D84CC: b       0x801D84E0
    {
            goto label_801D84E0;
    }

label_801D84D0:
    ctx->pc = 0x801D84D0u;
    ctx->downcount -= 3;
    // 801D84D0: lwz     r5, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801D84D4:
    // 801D84D4: cmpwi   r5, 0
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

label_801D84D8:
    // 801D84D8: bc    4, 2, 0x801D84BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D84BCu;
                return;
            }
            goto label_801D84BC;
        }
    }

label_801D84DC:
    ctx->pc = 0x801D84DCu;
    ctx->downcount -= 1;
    // 801D84DC: bl      0x801D83E0
    {
            ctx->lr = 0x801D84E0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D83E0u;
                return;
            }
            goto label_801D83E0;
    }

label_801D84E0:
    ctx->pc = 0x801D84E0u;
    ctx->downcount -= 5;
    // 801D84E0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D84E4:
    ctx->pc = 0x801D84E4u;
    // 801D84E4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D84E8:
    ctx->pc = 0x801D84E8u;
    // 801D84E8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801D84EC:
    ctx->pc = 0x801D84ECu;
    // 801D84EC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D84F0:
    ctx->pc = 0x801D84F0u;
    ctx->downcount -= 4;
    // 801D84F0: lwz     r9, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D84F4:
    ctx->pc = 0x801D84F4u;
    // 801D84F4: lwz     r10, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D84F8:
    ctx->pc = 0x801D84F8u;
    // 801D84F8: cmpwi   r9, 0
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

label_801D84FC:
    ctx->pc = 0x801D84FCu;
    // 801D84FC: bc    12, 2, 0x801D8508
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8508;
        }
    }

label_801D8500:
    ctx->pc = 0x801D8500u;
    ctx->downcount -= 2;
    // 801D8500: stw     r10, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8504:
    ctx->pc = 0x801D8504u;
    // 801D8504: b       0x801D8510
    {
            goto label_801D8510;
    }

label_801D8508:
    ctx->pc = 0x801D8508u;
    ctx->downcount -= 2;
    // 801D8508: lwz     r9, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D850C:
    ctx->pc = 0x801D850Cu;
    // 801D850C: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8510:
    ctx->pc = 0x801D8510u;
    ctx->downcount -= 3;
    // 801D8510: lwz     r9, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8514:
    ctx->pc = 0x801D8514u;
    // 801D8514: cmpwi   r9, 0
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

label_801D8518:
    ctx->pc = 0x801D8518u;
    // 801D8518: bc    12, 2, 0x801D8528
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8528;
        }
    }

label_801D851C:
    ctx->pc = 0x801D851Cu;
    ctx->downcount -= 3;
    // 801D851C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8520:
    ctx->pc = 0x801D8520u;
    // 801D8520: stw     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8524:
    ctx->pc = 0x801D8524u;
    // 801D8524: b       0x801D8534
    {
            goto label_801D8534;
    }

label_801D8528:
    ctx->pc = 0x801D8528u;
    ctx->downcount -= 3;
    // 801D8528: lwz     r9, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D852C:
    ctx->pc = 0x801D852Cu;
    // 801D852C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8530:
    ctx->pc = 0x801D8530u;
    // 801D8530: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8534:
    ctx->pc = 0x801D8534u;
    ctx->downcount -= 6;
    // 801D8534: lwz     r11, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D8538:
    ctx->pc = 0x801D8538u;
    // 801D8538: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D853C:
    ctx->pc = 0x801D853Cu;
    // 801D853C: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8540:
    ctx->pc = 0x801D8540u;
    // 801D8540: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D8544:
    ctx->pc = 0x801D8544u;
    // 801D8544: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8548:
    ctx->pc = 0x801D8548u;
    // 801D8548: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D854C:
    ctx->pc = 0x801D854Cu;
    ctx->downcount -= 2;
    // 801D854C: or.   r4, r4, r4
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

label_801D8550:
    ctx->pc = 0x801D8550u;
    // 801D8550: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8554:
    ctx->pc = 0x801D8554u;
    ctx->downcount -= 8;
    // 801D8554: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801D8558:
    ctx->pc = 0x801D8558u;
    // 801D8558: stw     r3, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D855C:
    ctx->pc = 0x801D855Cu;
    // 801D855C: stw     r9, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8560:
    ctx->pc = 0x801D8560u;
    // 801D8560: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8564:
    ctx->pc = 0x801D8564u;
    // 801D8564: stw     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8568:
    ctx->pc = 0x801D8568u;
    // 801D8568: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D856C:
    ctx->pc = 0x801D856Cu;
    // 801D856C: cmpwi   r9, 0
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

label_801D8570:
    ctx->pc = 0x801D8570u;
    // 801D8570: bc    12, 2, 0x801D857C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D857C;
        }
    }

label_801D8574:
    ctx->pc = 0x801D8574u;
    ctx->downcount -= 2;
    // 801D8574: stw     r4, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8578:
    ctx->pc = 0x801D8578u;
    // 801D8578: b       0x801D8580
    {
            goto label_801D8580;
    }

label_801D857C:
    ctx->pc = 0x801D857Cu;
    ctx->downcount -= 1;
    // 801D857C: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8580:
    ctx->pc = 0x801D8580u;
    ctx->downcount -= 5;
    // 801D8580: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8584:
    ctx->pc = 0x801D8584u;
    // 801D8584: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8588:
    ctx->pc = 0x801D8588u;
    // 801D8588: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D858C:
    ctx->pc = 0x801D858Cu;
    // 801D858C: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8590:
    ctx->pc = 0x801D8590u;
    // 801D8590: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8594:
    ctx->pc = 0x801D8594u;
    ctx->downcount -= 21;
    // 801D8594: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8598:
    ctx->pc = 0x801D8598u;
    // 801D8598: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D859C:
    ctx->pc = 0x801D859Cu;
    // 801D859C: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D85A0:
    ctx->pc = 0x801D85A0u;
    // 801D85A0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D85A4:
    ctx->pc = 0x801D85A4u;
    // 801D85A4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D85A8:
    ctx->pc = 0x801D85A8u;
    // 801D85A8: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D85AC:
    ctx->pc = 0x801D85ACu;
    // 801D85AC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D85B0:
    ctx->pc = 0x801D85B0u;
    // 801D85B0: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D85B4:
    ctx->pc = 0x801D85B4u;
    // 801D85B4: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D85B8:
    ctx->pc = 0x801D85B8u;
    // 801D85B8: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D85BC:
    ctx->pc = 0x801D85BCu;
    // 801D85BC: bc    12, 18, 0x801D85F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D85F4;
        }
    }

label_801D85C0:
    ctx->pc = 0x801D85C0u;
    ctx->downcount -= 2;
    // 801D85C0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D85C4:
    ctx->pc = 0x801D85C4u;
    // 801D85C4: bl      0x801D84F0
    {
            ctx->lr = 0x801D85C8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D84F0u;
                return;
            }
            goto label_801D84F0;
    }

label_801D85C8:
    ctx->pc = 0x801D85C8u;
    ctx->downcount -= 6;
    // 801D85C8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D85CC:
    ctx->pc = 0x801D85CCu;
    // 801D85CC: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D85D0:
    ctx->pc = 0x801D85D0u;
    // 801D85D0: stw     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D85D4:
    ctx->pc = 0x801D85D4u;
    // 801D85D4: stw     r0, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D85D8:
    ctx->pc = 0x801D85D8u;
    // 801D85D8: stw     r0, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D85DC:
    ctx->pc = 0x801D85DCu;
    // 801D85DC: bc    12, 18, 0x801D85F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D85F4;
        }
    }

label_801D85E0:
    ctx->pc = 0x801D85E0u;
    ctx->downcount -= 7;
    // 801D85E0: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D85E4:
    ctx->pc = 0x801D85E4u;
    // 801D85E4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D85E8:
    ctx->pc = 0x801D85E8u;
    // 801D85E8: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D85EC:
    ctx->pc = 0x801D85ECu;
    // 801D85EC: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D85F0:
    ctx->pc = 0x801D85F0u;
    // 801D85F0: bl      0x801D854C
    {
            ctx->lr = 0x801D85F4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D854Cu;
                return;
            }
            goto label_801D854C;
    }

label_801D85F4:
    ctx->pc = 0x801D85F4u;
    ctx->downcount -= 19;
    // 801D85F4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D85F8:
    ctx->pc = 0x801D85F8u;
    // 801D85F8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D85FC:
    ctx->pc = 0x801D85FCu;
    // 801D85FC: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D8600:
    ctx->pc = 0x801D8600u;
    // 801D8600: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8604:
    ctx->pc = 0x801D8604u;
    // 801D8604: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8608:
    ctx->pc = 0x801D8608u;
    // 801D8608: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D860C:
    ctx->pc = 0x801D860Cu;
    // 801D860C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8610:
    ctx->pc = 0x801D8610u;
    // 801D8610: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8614:
    ctx->pc = 0x801D8614u;
    ctx->downcount -= 4;
    // 801D8614: lwz     r9, 544(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(544);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8618:
    ctx->pc = 0x801D8618u;
    // 801D8618: lwz     r10, 540(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(540);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D861C:
    ctx->pc = 0x801D861Cu;
    // 801D861C: cmpwi   r9, 0
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

label_801D8620:
    ctx->pc = 0x801D8620u;
    // 801D8620: bc    12, 2, 0x801D862C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D862C;
        }
    }

label_801D8624:
    ctx->pc = 0x801D8624u;
    ctx->downcount -= 2;
    // 801D8624: stw     r10, 540(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8628:
    ctx->pc = 0x801D8628u;
    // 801D8628: b       0x801D8634
    {
            goto label_801D8634;
    }

label_801D862C:
    ctx->pc = 0x801D862Cu;
    ctx->downcount -= 2;
    // 801D862C: lwz     r9, 552(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(552);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8630:
    ctx->pc = 0x801D8630u;
    // 801D8630: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8634:
    ctx->pc = 0x801D8634u;
    ctx->downcount -= 3;
    // 801D8634: lwz     r9, 540(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(540);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8638:
    ctx->pc = 0x801D8638u;
    // 801D8638: cmpwi   r9, 0
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

label_801D863C:
    ctx->pc = 0x801D863Cu;
    // 801D863C: bc    12, 2, 0x801D864C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D864C;
        }
    }

label_801D8640:
    ctx->pc = 0x801D8640u;
    ctx->downcount -= 3;
    // 801D8640: lwz     r0, 544(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(544);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8644:
    ctx->pc = 0x801D8644u;
    // 801D8644: stw     r0, 544(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(544);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8648:
    ctx->pc = 0x801D8648u;
    // 801D8648: b       0x801D8658
    {
            goto label_801D8658;
    }

label_801D864C:
    ctx->pc = 0x801D864Cu;
    ctx->downcount -= 3;
    // 801D864C: lwz     r9, 552(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(552);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8650:
    ctx->pc = 0x801D8650u;
    // 801D8650: lwz     r0, 544(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(544);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8654:
    ctx->pc = 0x801D8654u;
    // 801D8654: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8658:
    ctx->pc = 0x801D8658u;
    ctx->downcount -= 6;
    // 801D8658: lwz     r11, 552(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(552);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D865C:
    ctx->pc = 0x801D865Cu;
    // 801D865C: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D8660:
    ctx->pc = 0x801D8660u;
    // 801D8660: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8664:
    ctx->pc = 0x801D8664u;
    // 801D8664: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D8668:
    ctx->pc = 0x801D8668u;
    // 801D8668: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D866C:
    ctx->pc = 0x801D866Cu;
    // 801D866C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8670:
    ctx->pc = 0x801D8670u;
    ctx->downcount -= 2;
    // 801D8670: or.   r4, r4, r4
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

label_801D8674:
    ctx->pc = 0x801D8674u;
    // 801D8674: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8678:
    ctx->pc = 0x801D8678u;
    ctx->downcount -= 8;
    // 801D8678: stw     r3, 552(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(552);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D867C:
    ctx->pc = 0x801D867Cu;
    // 801D867C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8680:
    ctx->pc = 0x801D8680u;
    // 801D8680: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8684:
    ctx->pc = 0x801D8684u;
    // 801D8684: stw     r0, 544(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(544);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8688:
    ctx->pc = 0x801D8688u;
    // 801D8688: stw     r9, 540(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D868C:
    ctx->pc = 0x801D868Cu;
    // 801D868C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8690:
    ctx->pc = 0x801D8690u;
    // 801D8690: cmpwi   r9, 0
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

label_801D8694:
    ctx->pc = 0x801D8694u;
    // 801D8694: bc    12, 2, 0x801D86A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D86A0;
        }
    }

label_801D8698:
    ctx->pc = 0x801D8698u;
    ctx->downcount -= 2;
    // 801D8698: stw     r4, 544(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(544);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D869C:
    ctx->pc = 0x801D869Cu;
    // 801D869C: b       0x801D86A4
    {
            goto label_801D86A4;
    }

label_801D86A0:
    ctx->pc = 0x801D86A0u;
    ctx->downcount -= 1;
    // 801D86A0: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D86A4:
    ctx->pc = 0x801D86A4u;
    ctx->downcount -= 5;
    // 801D86A4: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D86A8:
    ctx->pc = 0x801D86A8u;
    // 801D86A8: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D86AC:
    ctx->pc = 0x801D86ACu;
    // 801D86AC: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D86B0:
    ctx->pc = 0x801D86B0u;
    // 801D86B0: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D86B4:
    ctx->pc = 0x801D86B4u;
    // 801D86B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D86B8:
    ctx->pc = 0x801D86B8u;
    ctx->downcount -= 18;
    // 801D86B8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D86BC:
    ctx->pc = 0x801D86BCu;
    // 801D86BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D86C0:
    ctx->pc = 0x801D86C0u;
    // 801D86C0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D86C4:
    ctx->pc = 0x801D86C4u;
    // 801D86C4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D86C8:
    ctx->pc = 0x801D86C8u;
    // 801D86C8: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D86CC:
    ctx->pc = 0x801D86CCu;
    // 801D86CC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D86D0:
    ctx->pc = 0x801D86D0u;
    // 801D86D0: cmpwi   r31, 0
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

label_801D86D4:
    ctx->pc = 0x801D86D4u;
    // 801D86D4: bc    12, 2, 0x801D86F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D86F8;
        }
    }

label_801D86D8:
    ctx->downcount -= 2;
    // 801D86D8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D86DC:
    // 801D86DC: bl      0x801D8614
    {
            ctx->lr = 0x801D86E0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8614u;
                return;
            }
            goto label_801D8614;
    }

label_801D86E0:
    ctx->downcount -= 4;
    // 801D86E0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D86E4:
    // 801D86E4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D86E8:
    // 801D86E8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D86EC:
    // 801D86EC: bl      0x801D8670
    {
            ctx->lr = 0x801D86F0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8670u;
                return;
            }
            goto label_801D8670;
    }

label_801D86F0:
    ctx->downcount -= 2;
    // 801D86F0: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D86F4:
    // 801D86F4: bc    4, 2, 0x801D86D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D86D8u;
                return;
            }
            goto label_801D86D8;
        }
    }

label_801D86F8:
    ctx->pc = 0x801D86F8u;
    ctx->downcount -= 16;
    // 801D86F8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D86FC:
    ctx->pc = 0x801D86FCu;
    // 801D86FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8700:
    ctx->pc = 0x801D8700u;
    // 801D8700: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8704:
    ctx->pc = 0x801D8704u;
    // 801D8704: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8708:
    ctx->pc = 0x801D8708u;
    // 801D8708: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D870C:
    ctx->pc = 0x801D870Cu;
    ctx->downcount -= 17;
    // 801D870C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8710:
    ctx->pc = 0x801D8710u;
    // 801D8710: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8714:
    ctx->pc = 0x801D8714u;
    // 801D8714: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8718:
    ctx->pc = 0x801D8718u;
    // 801D8718: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D871C:
    ctx->pc = 0x801D871Cu;
    // 801D871C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8720:
    ctx->pc = 0x801D8720u;
    // 801D8720: li      r29, 12
    ctx->gpr[29] = (u32)(s32)(12);

label_801D8724:
    ctx->pc = 0x801D8724u;
    // 801D8724: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_801D8728:
    ctx->downcount -= 3;
    // 801D8728: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D872C:
    // 801D872C: addi    r4, r30, 8
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(8);

label_801D8730:
    // 801D8730: bl      0x801D86B8
    {
            ctx->lr = 0x801D8734u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D86B8u;
                return;
            }
            goto label_801D86B8;
    }

label_801D8734:
    ctx->downcount -= 3;
    // 801D8734: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801D8738:
    // 801D8738: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D873C:
    // 801D873C: bc    4, 2, 0x801D8728
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8728u;
                return;
            }
            goto label_801D8728;
        }
    }

label_801D8740:
    ctx->pc = 0x801D8740u;
    ctx->downcount -= 16;
    // 801D8740: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8744:
    ctx->pc = 0x801D8744u;
    // 801D8744: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8748:
    ctx->pc = 0x801D8748u;
    // 801D8748: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D874C:
    ctx->pc = 0x801D874Cu;
    // 801D874C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8750:
    ctx->pc = 0x801D8750u;
    // 801D8750: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8754:
    ctx->pc = 0x801D8754u;
    ctx->downcount -= 20;
    // 801D8754: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8758:
    ctx->pc = 0x801D8758u;
    // 801D8758: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D875C:
    ctx->pc = 0x801D875Cu;
    // 801D875C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8760:
    ctx->pc = 0x801D8760u;
    // 801D8760: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8764:
    ctx->pc = 0x801D8764u;
    // 801D8764: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8768:
    ctx->pc = 0x801D8768u;
    // 801D8768: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D876C:
    ctx->pc = 0x801D876Cu;
    // 801D876C: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8770:
    ctx->pc = 0x801D8770u;
    // 801D8770: cmpwi   r4, 0
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

label_801D8774:
    ctx->pc = 0x801D8774u;
    // 801D8774: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D8778:
    ctx->pc = 0x801D8778u;
    // 801D8778: bc    12, 2, 0x801D87B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D87B4;
        }
    }

label_801D877C:
    ctx->pc = 0x801D877Cu;
    ctx->downcount -= 3;
    // 801D877C: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8780:
    ctx->pc = 0x801D8780u;
    // 801D8780: cmpwi   r30, 0
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

label_801D8784:
    ctx->pc = 0x801D8784u;
    // 801D8784: bc    12, 2, 0x801D87B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D87B4;
        }
    }

label_801D8788:
    ctx->pc = 0x801D8788u;
    ctx->downcount -= 1;
    // 801D8788: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D878C:
    ctx->pc = 0x801D878Cu;
    ctx->downcount -= 8;
    // 801D878C: stw     r29, 540(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8790:
    // 801D8790: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8794:
    ctx->pc = 0x801D8794u;
    // 801D8794: stw     r29, 544(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(544);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8798:
    // 801D8798: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D879C:
    ctx->pc = 0x801D879Cu;
    // 801D879C: stw     r29, 548(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(548);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D87A0:
    ctx->pc = 0x801D87A0u;
    // 801D87A0: stw     r29, 552(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(552);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D87A4:
    // 801D87A4: addi    r31, r31, 556
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(556);

label_801D87A8:
    // 801D87A8: bl      0x801D8670
    {
            ctx->lr = 0x801D87ACu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8670u;
                return;
            }
            goto label_801D8670;
    }

label_801D87AC:
    ctx->downcount -= 2;
    // 801D87AC: addic.  r30, r30, -1
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

label_801D87B0:
    // 801D87B0: bc    4, 2, 0x801D878C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D878Cu;
                return;
            }
            goto label_801D878C;
        }
    }

label_801D87B4:
    ctx->pc = 0x801D87B4u;
    ctx->downcount -= 16;
    // 801D87B4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D87B8:
    ctx->pc = 0x801D87B8u;
    // 801D87B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D87BC:
    ctx->pc = 0x801D87BCu;
    // 801D87BC: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D87C0:
    ctx->pc = 0x801D87C0u;
    // 801D87C0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D87C4:
    ctx->pc = 0x801D87C4u;
    // 801D87C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D87C8:
    ctx->pc = 0x801D87C8u;
    ctx->downcount -= 29;
    // 801D87C8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D87CC:
    ctx->pc = 0x801D87CCu;
    // 801D87CC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D87D0:
    ctx->pc = 0x801D87D0u;
    // 801D87D0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D87D4:
    ctx->pc = 0x801D87D4u;
    // 801D87D4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D87D8:
    ctx->pc = 0x801D87D8u;
    // 801D87D8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D87DC:
    ctx->pc = 0x801D87DCu;
    // 801D87DC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D87E0:
    ctx->pc = 0x801D87E0u;
    // 801D87E0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D87E4:
    ctx->pc = 0x801D87E4u;
    // 801D87E4: mulli   r4, r29, 556
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)556);

label_801D87E8:
    ctx->pc = 0x801D87E8u;
    // 801D87E8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D87EC:
    ctx->pc = 0x801D87ECu;
    // 801D87EC: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D87F0:
    ctx->pc = 0x801D87F0u;
    // 801D87F0: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D87F4:
    ctx->pc = 0x801D87F4u;
    // 801D87F4: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D87F8:
    ctx->pc = 0x801D87F8u;
    // 801D87F8: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D87FC:
    ctx->pc = 0x801D87FCu;
    // 801D87FC: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D8800:
    ctx->pc = 0x801D8800u;
    // 801D8800: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8804:
    ctx->pc = 0x801D8804u;
    // 801D8804: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8808:
    ctx->pc = 0x801D8808u;
    // 801D8808: bl      0x80039640
    {
            ctx->lr = 0x801D880Cu;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D880C:
    ctx->pc = 0x801D880Cu;
    ctx->downcount -= 4;
    // 801D880C: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8810:
    ctx->pc = 0x801D8810u;
    // 801D8810: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D8814:
    ctx->pc = 0x801D8814u;
    // 801D8814: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D8818:
    ctx->pc = 0x801D8818u;
    // 801D8818: bl      0x801D8754
    {
            ctx->lr = 0x801D881Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8754u;
                return;
            }
            goto label_801D8754;
    }

label_801D881C:
    ctx->pc = 0x801D881Cu;
    ctx->downcount -= 16;
    // 801D881C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8820:
    ctx->pc = 0x801D8820u;
    // 801D8820: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8824:
    ctx->pc = 0x801D8824u;
    // 801D8824: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8828:
    ctx->pc = 0x801D8828u;
    // 801D8828: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D882C:
    ctx->pc = 0x801D882Cu;
    // 801D882C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8830:
    ctx->pc = 0x801D8830u;
    ctx->downcount -= 16;
    // 801D8830: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8834:
    ctx->pc = 0x801D8834u;
    // 801D8834: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8838:
    ctx->pc = 0x801D8838u;
    // 801D8838: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D883C:
    ctx->pc = 0x801D883Cu;
    // 801D883C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8840:
    ctx->pc = 0x801D8840u;
    // 801D8840: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8844:
    ctx->pc = 0x801D8844u;
    // 801D8844: bl      0x801D87C8
    {
            ctx->lr = 0x801D8848u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D87C8u;
                return;
            }
            goto label_801D87C8;
    }

label_801D8848:
    ctx->pc = 0x801D8848u;
    ctx->downcount -= 5;
    // 801D8848: li      r9, 12
    ctx->gpr[9] = (u32)(s32)(12);

label_801D884C:
    ctx->pc = 0x801D884Cu;
    // 801D884C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8850:
    ctx->pc = 0x801D8850u;
    // 801D8850: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D8854:
    ctx->pc = 0x801D8854u;
    // 801D8854: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D8858:
    loop_801D8858(ctx);
    if (ctx->pc == 0x801D886Cu) goto label_801D886C;
    return;
label_801D885C:
    ctx->pc = 0x801D885Cu;
    // 801D885C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8860:
    ctx->pc = 0x801D8860u;
    // 801D8860: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8864:
    // 801D8864: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D8868:
    // 801D8868: bc    16, 0, 0x801D8858
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8858u;
                return;
            }
            goto label_801D8858;
        }
    }

label_801D886C:
    ctx->pc = 0x801D886Cu;
    ctx->downcount -= 16;
    // 801D886C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8870:
    ctx->pc = 0x801D8870u;
    // 801D8870: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8874:
    ctx->pc = 0x801D8874u;
    // 801D8874: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8878:
    ctx->pc = 0x801D8878u;
    // 801D8878: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D887C:
    ctx->pc = 0x801D887Cu;
    // 801D887C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8880:
    ctx->pc = 0x801D8880u;
    ctx->downcount -= 21;
    // 801D8880: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8884:
    ctx->pc = 0x801D8884u;
    // 801D8884: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8888:
    ctx->pc = 0x801D8888u;
    // 801D8888: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D888C:
    ctx->pc = 0x801D888Cu;
    // 801D888C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8890:
    ctx->pc = 0x801D8890u;
    // 801D8890: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8894:
    ctx->pc = 0x801D8894u;
    // 801D8894: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D8898:
    ctx->pc = 0x801D8898u;
    // 801D8898: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D889C:
    ctx->pc = 0x801D889Cu;
    // 801D889C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D88A0:
    ctx->pc = 0x801D88A0u;
    // 801D88A0: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D88A4:
    ctx->pc = 0x801D88A4u;
    // 801D88A4: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D88A8:
    ctx->pc = 0x801D88A8u;
    // 801D88A8: bc    12, 18, 0x801D88E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D88E0;
        }
    }

label_801D88AC:
    ctx->pc = 0x801D88ACu;
    ctx->downcount -= 2;
    // 801D88AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D88B0:
    ctx->pc = 0x801D88B0u;
    // 801D88B0: bl      0x801D6D60
    {
            ctx->lr = 0x801D88B4u;
            ctx->pc = 0x801D6D60u;
            return;
    }

label_801D88B4:
    ctx->pc = 0x801D88B4u;
    ctx->downcount -= 6;
    // 801D88B4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D88B8:
    ctx->pc = 0x801D88B8u;
    // 801D88B8: stw     r0, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D88BC:
    ctx->pc = 0x801D88BCu;
    // 801D88BC: stw     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D88C0:
    ctx->pc = 0x801D88C0u;
    // 801D88C0: stw     r0, 12(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D88C4:
    ctx->pc = 0x801D88C4u;
    // 801D88C4: stw     r0, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D88C8:
    ctx->pc = 0x801D88C8u;
    // 801D88C8: bc    12, 18, 0x801D88E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D88E0;
        }
    }

label_801D88CC:
    ctx->pc = 0x801D88CCu;
    ctx->downcount -= 7;
    // 801D88CC: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D88D0:
    ctx->pc = 0x801D88D0u;
    // 801D88D0: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D88D4:
    ctx->pc = 0x801D88D4u;
    // 801D88D4: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D88D8:
    ctx->pc = 0x801D88D8u;
    // 801D88D8: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D88DC:
    ctx->pc = 0x801D88DCu;
    // 801D88DC: bl      0x801D83E0
    {
            ctx->lr = 0x801D88E0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D83E0u;
                return;
            }
            goto label_801D83E0;
    }

label_801D88E0:
    ctx->pc = 0x801D88E0u;
    ctx->downcount -= 19;
    // 801D88E0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D88E4:
    ctx->pc = 0x801D88E4u;
    // 801D88E4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D88E8:
    ctx->pc = 0x801D88E8u;
    // 801D88E8: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D88EC:
    ctx->pc = 0x801D88ECu;
    // 801D88EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D88F0:
    ctx->pc = 0x801D88F0u;
    // 801D88F0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D88F4:
    ctx->pc = 0x801D88F4u;
    // 801D88F4: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D88F8:
    ctx->pc = 0x801D88F8u;
    // 801D88F8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D88FC:
    ctx->pc = 0x801D88FCu;
    // 801D88FC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8900:
    ctx->pc = 0x801D8900u;
    ctx->downcount -= 18;
    // 801D8900: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8904:
    ctx->pc = 0x801D8904u;
    // 801D8904: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8908:
    ctx->pc = 0x801D8908u;
    // 801D8908: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D890C:
    ctx->pc = 0x801D890Cu;
    // 801D890C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8910:
    ctx->pc = 0x801D8910u;
    // 801D8910: lwz     r30, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801D8914:
    ctx->pc = 0x801D8914u;
    // 801D8914: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8918:
    ctx->pc = 0x801D8918u;
    // 801D8918: cmpwi   r30, 0
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

label_801D891C:
    ctx->pc = 0x801D891Cu;
    // 801D891C: bc    12, 2, 0x801D8938
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8938;
        }
    }

label_801D8920:
    ctx->downcount -= 5;
    // 801D8920: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D8924:
    ctx->pc = 0x801D8924u;
    // 801D8924: mtlr    r31
    ctx->lr = ctx->gpr[31];

label_801D8928:
    ctx->pc = 0x801D8928u;
    // 801D8928: lwz     r30, 540(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(540);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801D892C:
    ctx->pc = 0x801D892Cu;
    // 801D892C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801D8930u;
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8930:
    ctx->downcount -= 2;
    // 801D8930: or.   r30, r30, r30
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8934:
    // 801D8934: bc    4, 2, 0x801D8920
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8920u;
                return;
            }
            goto label_801D8920;
        }
    }

label_801D8938:
    ctx->pc = 0x801D8938u;
    ctx->downcount -= 16;
    // 801D8938: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D893C:
    ctx->pc = 0x801D893Cu;
    // 801D893C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8940:
    ctx->pc = 0x801D8940u;
    // 801D8940: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8944:
    ctx->pc = 0x801D8944u;
    // 801D8944: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D8948:
    ctx->pc = 0x801D8948u;
    // 801D8948: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D894C:
    ctx->pc = 0x801D894Cu;
    ctx->downcount -= 21;
    // 801D894C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8950:
    ctx->pc = 0x801D8950u;
    // 801D8950: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8954:
    ctx->pc = 0x801D8954u;
    // 801D8954: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D8958:
    ctx->pc = 0x801D8958u;
    // 801D8958: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D895C:
    ctx->pc = 0x801D895Cu;
    // 801D895C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8960:
    ctx->pc = 0x801D8960u;
    // 801D8960: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D8964:
    ctx->pc = 0x801D8964u;
    // 801D8964: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8968:
    ctx->pc = 0x801D8968u;
    // 801D8968: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D896C:
    ctx->pc = 0x801D896Cu;
    // 801D896C: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8970:
    ctx->pc = 0x801D8970u;
    // 801D8970: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D8974:
    ctx->pc = 0x801D8974u;
    // 801D8974: bc    12, 18, 0x801D89AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D89AC;
        }
    }

label_801D8978:
    ctx->pc = 0x801D8978u;
    ctx->downcount -= 2;
    // 801D8978: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D897C:
    ctx->pc = 0x801D897Cu;
    // 801D897C: bl      0x801D8614
    {
            ctx->lr = 0x801D8980u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8614u;
                return;
            }
            goto label_801D8614;
    }

label_801D8980:
    ctx->pc = 0x801D8980u;
    ctx->downcount -= 6;
    // 801D8980: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8984:
    ctx->pc = 0x801D8984u;
    // 801D8984: stw     r0, 552(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(552);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8988:
    ctx->pc = 0x801D8988u;
    // 801D8988: stw     r0, 540(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(540);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D898C:
    ctx->pc = 0x801D898Cu;
    // 801D898C: stw     r0, 544(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(544);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8990:
    ctx->pc = 0x801D8990u;
    // 801D8990: stw     r0, 548(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(548);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8994:
    ctx->pc = 0x801D8994u;
    // 801D8994: bc    12, 18, 0x801D89AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D89AC;
        }
    }

label_801D8998:
    ctx->pc = 0x801D8998u;
    ctx->downcount -= 7;
    // 801D8998: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D899C:
    ctx->pc = 0x801D899Cu;
    // 801D899C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D89A0:
    ctx->pc = 0x801D89A0u;
    // 801D89A0: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D89A4:
    ctx->pc = 0x801D89A4u;
    // 801D89A4: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D89A8:
    ctx->pc = 0x801D89A8u;
    // 801D89A8: bl      0x801D8670
    {
            ctx->lr = 0x801D89ACu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8670u;
                return;
            }
            goto label_801D8670;
    }

label_801D89AC:
    ctx->pc = 0x801D89ACu;
    ctx->downcount -= 19;
    // 801D89AC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D89B0:
    ctx->pc = 0x801D89B0u;
    // 801D89B0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D89B4:
    ctx->pc = 0x801D89B4u;
    // 801D89B4: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D89B8:
    ctx->pc = 0x801D89B8u;
    // 801D89B8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D89BC:
    ctx->pc = 0x801D89BCu;
    // 801D89BC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D89C0:
    ctx->pc = 0x801D89C0u;
    // 801D89C0: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D89C4:
    ctx->pc = 0x801D89C4u;
    // 801D89C4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D89C8:
    ctx->pc = 0x801D89C8u;
    // 801D89C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D89CC:
    ctx->pc = 0x801D89CCu;
    ctx->downcount -= 3;
    // 801D89CC: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D89D0:
    ctx->pc = 0x801D89D0u;
    // 801D89D0: andi.   r0, r9, 0x0003
    {
        ctx->gpr[0] = ctx->gpr[9] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D89D4:
    ctx->pc = 0x801D89D4u;
    // 801D89D4: bc    4, 2, 0x801D8A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D8A20;
        }
    }

label_801D89D8:
    ctx->pc = 0x801D89D8u;
    ctx->downcount -= 3;
    // 801D89D8: lwz     r11, 544(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(544);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D89DC:
    ctx->pc = 0x801D89DCu;
    // 801D89DC: andi.   r7, r11, 0x0003
    {
        ctx->gpr[7] = ctx->gpr[11] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D89E0:
    ctx->pc = 0x801D89E0u;
    // 801D89E0: bc    4, 2, 0x801D8A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D8A20;
        }
    }

label_801D89E4:
    ctx->pc = 0x801D89E4u;
    ctx->downcount -= 4;
    // 801D89E4: lwz     r0, 540(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(540);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D89E8:
    ctx->pc = 0x801D89E8u;
    // 801D89E8: or   r8, r0, r0
    {
        ctx->gpr[8] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801D89EC:
    ctx->pc = 0x801D89ECu;
    // 801D89EC: andi.   r10, r0, 0x0003
    {
        ctx->gpr[10] = ctx->gpr[0] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D89F0:
    ctx->pc = 0x801D89F0u;
    // 801D89F0: bc    4, 2, 0x801D8A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D8A20;
        }
    }

label_801D89F4:
    ctx->pc = 0x801D89F4u;
    ctx->downcount -= 4;
    // 801D89F4: lwz     r0, 552(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(552);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D89F8:
    ctx->pc = 0x801D89F8u;
    // 801D89F8: or   r10, r0, r0
    {
        ctx->gpr[10] = ctx->gpr[0] | ctx->gpr[0];
    }

label_801D89FC:
    ctx->pc = 0x801D89FCu;
    // 801D89FC: andi.   r7, r0, 0x0003
    {
        ctx->gpr[7] = ctx->gpr[0] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8A00:
    ctx->pc = 0x801D8A00u;
    // 801D8A00: bc    4, 2, 0x801D8A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D8A20;
        }
    }

label_801D8A04:
    ctx->pc = 0x801D8A04u;
    ctx->downcount -= 2;
    // 801D8A04: cmpwi   r10, 0
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

label_801D8A08:
    ctx->pc = 0x801D8A08u;
    // 801D8A08: bc    12, 2, 0x801D8A20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8A20;
        }
    }

label_801D8A0C:
    ctx->pc = 0x801D8A0Cu;
    ctx->downcount -= 2;
    // 801D8A0C: cmpwi   r11, 0
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

label_801D8A10:
    ctx->pc = 0x801D8A10u;
    // 801D8A10: bc    12, 2, 0x801D8A28
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8A28;
        }
    }

label_801D8A14:
    ctx->pc = 0x801D8A14u;
    ctx->downcount -= 1;
    // 801D8A14: lwz     r0, 540(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(540);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8A18:
    ctx->downcount -= 2;
    // 801D8A18: cmpw    r0, r9
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

label_801D8A1C:
    // 801D8A1C: bc    12, 2, 0x801D8A30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8A30;
        }
    }

label_801D8A20:
    ctx->downcount -= 2;
    // 801D8A20: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D8A24:
    ctx->pc = 0x801D8A24u;
    // 801D8A24: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8A28:
    ctx->pc = 0x801D8A28u;
    ctx->downcount -= 2;
    // 801D8A28: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8A2C:
    // 801D8A2C: b       0x801D8A18
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8A18u;
                return;
            }
            goto label_801D8A18;
    }

label_801D8A30:
    ctx->downcount -= 2;
    // 801D8A30: cmpwi   r8, 0
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

label_801D8A34:
    // 801D8A34: bc    12, 2, 0x801D8A48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8A48;
        }
    }

label_801D8A38:
    ctx->pc = 0x801D8A38u;
    ctx->downcount -= 3;
    // 801D8A38: lwz     r0, 544(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(544);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8A3C:
    // 801D8A3C: cmpw    r0, r9
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

label_801D8A40:
    // 801D8A40: bc    12, 2, 0x801D8A58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8A58;
        }
    }

label_801D8A44:
    ctx->downcount -= 1;
    // 801D8A44: b       0x801D8A20
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8A20u;
                return;
            }
            goto label_801D8A20;
    }

label_801D8A48:
    ctx->pc = 0x801D8A48u;
    ctx->downcount -= 4;
    // 801D8A48: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8A4C:
    ctx->pc = 0x801D8A4Cu;
    // 801D8A4C: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D8A50:
    ctx->pc = 0x801D8A50u;
    // 801D8A50: cmpw    r0, r9
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

label_801D8A54:
    ctx->pc = 0x801D8A54u;
    // 801D8A54: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8A58:
    ctx->pc = 0x801D8A58u;
    ctx->downcount -= 2;
    // 801D8A58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801D8A5C:
    ctx->pc = 0x801D8A5Cu;
    // 801D8A5C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8A60:
    ctx->pc = 0x801D8A60u;
    ctx->downcount -= 19;
    // 801D8A60: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8A64:
    ctx->pc = 0x801D8A64u;
    // 801D8A64: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8A68:
    ctx->pc = 0x801D8A68u;
    // 801D8A68: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8A6C:
    ctx->pc = 0x801D8A6Cu;
    // 801D8A6C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8A70:
    ctx->pc = 0x801D8A70u;
    // 801D8A70: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8A74:
    ctx->pc = 0x801D8A74u;
    // 801D8A74: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D8A78:
    ctx->pc = 0x801D8A78u;
    // 801D8A78: lwz     r31, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8A7C:
    ctx->pc = 0x801D8A7Cu;
    // 801D8A7C: cmpwi   r31, 0
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

label_801D8A80:
    ctx->pc = 0x801D8A80u;
    // 801D8A80: bc    12, 2, 0x801D8ABC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8ABC;
        }
    }

label_801D8A84:
    ctx->downcount -= 3;
    // 801D8A84: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D8A88:
    // 801D8A88: andi.   r0, r31, 0x0003
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8A8C:
    // 801D8A8C: bc    4, 2, 0x801D8AC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D8AC0;
        }
    }

label_801D8A90:
    ctx->downcount -= 2;
    // 801D8A90: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8A94:
    // 801D8A94: bl      0x801D89CC
    {
            ctx->lr = 0x801D8A98u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D89CCu;
                return;
            }
            goto label_801D89CC;
    }

label_801D8A98:
    ctx->pc = 0x801D8A98u;
    ctx->downcount -= 3;
    // 801D8A98: lwz     r0, 552(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(552);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8A9C:
    // 801D8A9C: cmpw    r0, r30
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

label_801D8AA0:
    // 801D8AA0: bc    12, 2, 0x801D8AAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8AAC;
        }
    }

label_801D8AA4:
    ctx->downcount -= 2;
    // 801D8AA4: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D8AA8:
    // 801D8AA8: b       0x801D8AC0
    {
            goto label_801D8AC0;
    }

label_801D8AAC:
    ctx->pc = 0x801D8AACu;
    ctx->downcount -= 4;
    // 801D8AAC: lwz     r31, 540(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(540);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8AB0:
    // 801D8AB0: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_801D8AB4:
    // 801D8AB4: cmpwi   r31, 0
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

label_801D8AB8:
    // 801D8AB8: bc    4, 2, 0x801D8A84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8A84u;
                return;
            }
            goto label_801D8A84;
        }
    }

label_801D8ABC:
    ctx->pc = 0x801D8ABCu;
    ctx->downcount -= 1;
    // 801D8ABC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D8AC0:
    ctx->pc = 0x801D8AC0u;
    ctx->downcount -= 16;
    // 801D8AC0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8AC4:
    ctx->pc = 0x801D8AC4u;
    // 801D8AC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8AC8:
    ctx->pc = 0x801D8AC8u;
    // 801D8AC8: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8ACC:
    ctx->pc = 0x801D8ACCu;
    // 801D8ACC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8AD0:
    ctx->pc = 0x801D8AD0u;
    // 801D8AD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8AD4:
    ctx->pc = 0x801D8AD4u;
    ctx->downcount -= 18;
    // 801D8AD4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8AD8:
    ctx->pc = 0x801D8AD8u;
    // 801D8AD8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8ADC:
    ctx->pc = 0x801D8ADCu;
    // 801D8ADC: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8AE0:
    ctx->pc = 0x801D8AE0u;
    // 801D8AE0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8AE4:
    ctx->pc = 0x801D8AE4u;
    // 801D8AE4: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8AE8:
    ctx->pc = 0x801D8AE8u;
    // 801D8AE8: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8AEC:
    ctx->pc = 0x801D8AECu;
    // 801D8AEC: lwz     r31, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8AF0:
    ctx->pc = 0x801D8AF0u;
    // 801D8AF0: bl      0x801D8A60
    {
            ctx->lr = 0x801D8AF4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8A60u;
                return;
            }
            goto label_801D8A60;
    }

label_801D8AF4:
    ctx->pc = 0x801D8AF4u;
    ctx->downcount -= 4;
    // 801D8AF4: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_801D8AF8:
    ctx->pc = 0x801D8AF8u;
    // 801D8AF8: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8AFC:
    ctx->pc = 0x801D8AFCu;
    // 801D8AFC: cmpw    r3, r0
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801D8B00:
    ctx->pc = 0x801D8B00u;
    // 801D8B00: bc    12, 2, 0x801D8B50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8B50;
        }
    }

label_801D8B04:
    ctx->pc = 0x801D8B04u;
    ctx->downcount -= 4;
    // 801D8B04: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_801D8B08:
    ctx->pc = 0x801D8B08u;
    // 801D8B08: addi    r3, r3, 12000
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(12000);

label_801D8B0C:
    ctx->pc = 0x801D8B0Cu;
    // 801D8B0C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801D8B10:
    ctx->pc = 0x801D8B10u;
    // 801D8B10: bl      0x80166EF4
    {
            ctx->lr = 0x801D8B14u;
            ctx->pc = 0x80166EF4u;
            return;
    }

label_801D8B14:
    ctx->downcount -= 2;
    // 801D8B14: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D8B18:
    // 801D8B18: b       0x801D8B68
    {
            goto label_801D8B68;
    }

label_801D8B1C:
    ctx->downcount -= 2;
    // 801D8B1C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_801D8B20:
    // 801D8B20: b       0x801D8B68
    {
            goto label_801D8B68;
    }

label_801D8B24:
    ctx->downcount -= 2;
    // 801D8B24: cmpw    r31, r29
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801D8B28:
    // 801D8B28: bc    12, 2, 0x801D8B1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8B1Cu;
                return;
            }
            goto label_801D8B1C;
        }
    }

label_801D8B2C:
    ctx->downcount -= 3;
    // 801D8B2C: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D8B30:
    // 801D8B30: andi.   r0, r31, 0x0003
    {
        ctx->gpr[0] = ctx->gpr[31] & 0x0003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8B34:
    // 801D8B34: bc    4, 2, 0x801D8B68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D8B68;
        }
    }

label_801D8B38:
    ctx->downcount -= 2;
    // 801D8B38: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8B3C:
    // 801D8B3C: bl      0x801D89CC
    {
            ctx->lr = 0x801D8B40u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D89CCu;
                return;
            }
            goto label_801D89CC;
    }

label_801D8B40:
    ctx->downcount -= 2;
    // 801D8B40: cmpwi   r3, -1
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

label_801D8B44:
    // 801D8B44: bc    12, 2, 0x801D8B14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8B14u;
                return;
            }
            goto label_801D8B14;
        }
    }

label_801D8B48:
    ctx->pc = 0x801D8B48u;
    ctx->downcount -= 2;
    // 801D8B48: lwz     r31, 540(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(540);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8B4C:
    // 801D8B4C: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_801D8B50:
    ctx->downcount -= 2;
    // 801D8B50: cmpwi   r31, 0
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

label_801D8B54:
    // 801D8B54: bc    4, 2, 0x801D8B24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8B24u;
                return;
            }
            goto label_801D8B24;
        }
    }

label_801D8B58:
    ctx->pc = 0x801D8B58u;
    ctx->downcount -= 3;
    // 801D8B58: cmpwi   r29, 0
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

label_801D8B5C:
    ctx->pc = 0x801D8B5Cu;
    // 801D8B5C: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_801D8B60:
    ctx->pc = 0x801D8B60u;
    // 801D8B60: bc    4, 2, 0x801D8B68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801D8B68;
        }
    }

label_801D8B64:
    ctx->pc = 0x801D8B64u;
    ctx->downcount -= 1;
    // 801D8B64: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801D8B68:
    ctx->pc = 0x801D8B68u;
    ctx->downcount -= 16;
    // 801D8B68: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8B6C:
    ctx->pc = 0x801D8B6Cu;
    // 801D8B6C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8B70:
    ctx->pc = 0x801D8B70u;
    // 801D8B70: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8B74:
    ctx->pc = 0x801D8B74u;
    // 801D8B74: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8B78:
    ctx->pc = 0x801D8B78u;
    // 801D8B78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8B7C:
    ctx->pc = 0x801D8B7Cu;
    ctx->downcount -= 18;
    // 801D8B7C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8B80:
    ctx->pc = 0x801D8B80u;
    // 801D8B80: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8B84:
    ctx->pc = 0x801D8B84u;
    // 801D8B84: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8B88:
    ctx->pc = 0x801D8B88u;
    // 801D8B88: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8B8C:
    ctx->pc = 0x801D8B8Cu;
    // 801D8B8C: lwz     r30, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801D8B90:
    ctx->pc = 0x801D8B90u;
    // 801D8B90: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8B94:
    ctx->pc = 0x801D8B94u;
    // 801D8B94: cmpwi   r30, 0
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

label_801D8B98:
    ctx->pc = 0x801D8B98u;
    // 801D8B98: bc    12, 2, 0x801D8BB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8BB4;
        }
    }

label_801D8B9C:
    ctx->downcount -= 5;
    // 801D8B9C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D8BA0:
    ctx->pc = 0x801D8BA0u;
    // 801D8BA0: mtlr    r31
    ctx->lr = ctx->gpr[31];

label_801D8BA4:
    ctx->pc = 0x801D8BA4u;
    // 801D8BA4: lwz     r30, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801D8BA8:
    ctx->pc = 0x801D8BA8u;
    // 801D8BA8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801D8BACu;
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8BAC:
    ctx->downcount -= 2;
    // 801D8BAC: or.   r30, r30, r30
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8BB0:
    // 801D8BB0: bc    4, 2, 0x801D8B9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8B9Cu;
                return;
            }
            goto label_801D8B9C;
        }
    }

label_801D8BB4:
    ctx->pc = 0x801D8BB4u;
    ctx->downcount -= 16;
    // 801D8BB4: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8BB8:
    ctx->pc = 0x801D8BB8u;
    // 801D8BB8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8BBC:
    ctx->pc = 0x801D8BBCu;
    // 801D8BBC: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8BC0:
    ctx->pc = 0x801D8BC0u;
    // 801D8BC0: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D8BC4:
    ctx->pc = 0x801D8BC4u;
    // 801D8BC4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8BC8:
    ctx->pc = 0x801D8BC8u;
    ctx->downcount -= 2;
    // 801D8BC8: or.   r4, r4, r4
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

label_801D8BCC:
    ctx->pc = 0x801D8BCCu;
    // 801D8BCC: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8BD0:
    ctx->pc = 0x801D8BD0u;
    ctx->downcount -= 8;
    // 801D8BD0: stw     r3, 604(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(604);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D8BD4:
    ctx->pc = 0x801D8BD4u;
    // 801D8BD4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8BD8:
    ctx->pc = 0x801D8BD8u;
    // 801D8BD8: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8BDC:
    ctx->pc = 0x801D8BDCu;
    // 801D8BDC: stw     r0, 596(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8BE0:
    ctx->pc = 0x801D8BE0u;
    // 801D8BE0: stw     r9, 592(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(592);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8BE4:
    ctx->pc = 0x801D8BE4u;
    // 801D8BE4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8BE8:
    ctx->pc = 0x801D8BE8u;
    // 801D8BE8: cmpwi   r9, 0
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

label_801D8BEC:
    ctx->pc = 0x801D8BECu;
    // 801D8BEC: bc    12, 2, 0x801D8BF8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8BF8;
        }
    }

label_801D8BF0:
    ctx->pc = 0x801D8BF0u;
    ctx->downcount -= 2;
    // 801D8BF0: stw     r4, 596(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8BF4:
    ctx->pc = 0x801D8BF4u;
    // 801D8BF4: b       0x801D8BFC
    {
            goto label_801D8BFC;
    }

label_801D8BF8:
    ctx->pc = 0x801D8BF8u;
    ctx->downcount -= 1;
    // 801D8BF8: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8BFC:
    ctx->pc = 0x801D8BFCu;
    ctx->downcount -= 5;
    // 801D8BFC: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8C00:
    ctx->pc = 0x801D8C00u;
    // 801D8C00: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8C04:
    ctx->pc = 0x801D8C04u;
    // 801D8C04: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D8C08:
    ctx->pc = 0x801D8C08u;
    // 801D8C08: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8C0C:
    ctx->pc = 0x801D8C0Cu;
    // 801D8C0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8C10:
    ctx->pc = 0x801D8C10u;
    ctx->downcount -= 20;
    // 801D8C10: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8C14:
    ctx->pc = 0x801D8C14u;
    // 801D8C14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8C18:
    ctx->pc = 0x801D8C18u;
    // 801D8C18: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8C1C:
    ctx->pc = 0x801D8C1Cu;
    // 801D8C1C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8C20:
    ctx->pc = 0x801D8C20u;
    // 801D8C20: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8C24:
    ctx->pc = 0x801D8C24u;
    // 801D8C24: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D8C28:
    ctx->pc = 0x801D8C28u;
    // 801D8C28: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8C2C:
    ctx->pc = 0x801D8C2Cu;
    // 801D8C2C: cmpwi   r4, 0
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

label_801D8C30:
    ctx->pc = 0x801D8C30u;
    // 801D8C30: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D8C34:
    ctx->pc = 0x801D8C34u;
    // 801D8C34: bc    12, 2, 0x801D8C70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8C70;
        }
    }

label_801D8C38:
    ctx->pc = 0x801D8C38u;
    ctx->downcount -= 3;
    // 801D8C38: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8C3C:
    ctx->pc = 0x801D8C3Cu;
    // 801D8C3C: cmpwi   r30, 0
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

label_801D8C40:
    ctx->pc = 0x801D8C40u;
    // 801D8C40: bc    12, 2, 0x801D8C70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8C70;
        }
    }

label_801D8C44:
    ctx->pc = 0x801D8C44u;
    ctx->downcount -= 1;
    // 801D8C44: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D8C48:
    ctx->pc = 0x801D8C48u;
    ctx->downcount -= 8;
    // 801D8C48: stw     r29, 592(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(592);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8C4C:
    // 801D8C4C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8C50:
    ctx->pc = 0x801D8C50u;
    // 801D8C50: stw     r29, 596(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8C54:
    // 801D8C54: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D8C58:
    ctx->pc = 0x801D8C58u;
    // 801D8C58: stw     r29, 600(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(600);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8C5C:
    ctx->pc = 0x801D8C5Cu;
    // 801D8C5C: stw     r29, 604(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(604);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D8C60:
    // 801D8C60: addi    r31, r31, 608
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(608);

label_801D8C64:
    // 801D8C64: bl      0x801D8BC8
    {
            ctx->lr = 0x801D8C68u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8BC8u;
                return;
            }
            goto label_801D8BC8;
    }

label_801D8C68:
    ctx->downcount -= 2;
    // 801D8C68: addic.  r30, r30, -1
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

label_801D8C6C:
    // 801D8C6C: bc    4, 2, 0x801D8C48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8C48u;
                return;
            }
            goto label_801D8C48;
        }
    }

label_801D8C70:
    ctx->pc = 0x801D8C70u;
    ctx->downcount -= 16;
    // 801D8C70: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8C74:
    ctx->pc = 0x801D8C74u;
    // 801D8C74: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8C78:
    ctx->pc = 0x801D8C78u;
    // 801D8C78: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8C7C:
    ctx->pc = 0x801D8C7Cu;
    // 801D8C7C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8C80:
    ctx->pc = 0x801D8C80u;
    // 801D8C80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8C84:
    ctx->pc = 0x801D8C84u;
    ctx->downcount -= 29;
    // 801D8C84: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8C88:
    ctx->pc = 0x801D8C88u;
    // 801D8C88: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8C8C:
    ctx->pc = 0x801D8C8Cu;
    // 801D8C8C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8C90:
    ctx->pc = 0x801D8C90u;
    // 801D8C90: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8C94:
    ctx->pc = 0x801D8C94u;
    // 801D8C94: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8C98:
    ctx->pc = 0x801D8C98u;
    // 801D8C98: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8C9C:
    ctx->pc = 0x801D8C9Cu;
    // 801D8C9C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8CA0:
    ctx->pc = 0x801D8CA0u;
    // 801D8CA0: mulli   r4, r29, 608
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)608);

label_801D8CA4:
    ctx->pc = 0x801D8CA4u;
    // 801D8CA4: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8CA8:
    ctx->pc = 0x801D8CA8u;
    // 801D8CA8: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D8CAC:
    ctx->pc = 0x801D8CACu;
    // 801D8CAC: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8CB0:
    ctx->pc = 0x801D8CB0u;
    // 801D8CB0: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D8CB4:
    ctx->pc = 0x801D8CB4u;
    // 801D8CB4: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8CB8:
    ctx->pc = 0x801D8CB8u;
    // 801D8CB8: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D8CBC:
    ctx->pc = 0x801D8CBCu;
    // 801D8CBC: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8CC0:
    ctx->pc = 0x801D8CC0u;
    // 801D8CC0: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8CC4:
    ctx->pc = 0x801D8CC4u;
    // 801D8CC4: bl      0x80039640
    {
            ctx->lr = 0x801D8CC8u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D8CC8:
    ctx->pc = 0x801D8CC8u;
    ctx->downcount -= 4;
    // 801D8CC8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8CCC:
    ctx->pc = 0x801D8CCCu;
    // 801D8CCC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D8CD0:
    ctx->pc = 0x801D8CD0u;
    // 801D8CD0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D8CD4:
    ctx->pc = 0x801D8CD4u;
    // 801D8CD4: bl      0x801D8C10
    {
            ctx->lr = 0x801D8CD8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8C10u;
                return;
            }
            goto label_801D8C10;
    }

label_801D8CD8:
    ctx->pc = 0x801D8CD8u;
    ctx->downcount -= 16;
    // 801D8CD8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8CDC:
    ctx->pc = 0x801D8CDCu;
    // 801D8CDC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8CE0:
    ctx->pc = 0x801D8CE0u;
    // 801D8CE0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8CE4:
    ctx->pc = 0x801D8CE4u;
    // 801D8CE4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8CE8:
    ctx->pc = 0x801D8CE8u;
    // 801D8CE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8CEC:
    ctx->pc = 0x801D8CECu;
    ctx->downcount -= 16;
    // 801D8CEC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8CF0:
    ctx->pc = 0x801D8CF0u;
    // 801D8CF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8CF4:
    ctx->pc = 0x801D8CF4u;
    // 801D8CF4: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8CF8:
    ctx->pc = 0x801D8CF8u;
    // 801D8CF8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8CFC:
    ctx->pc = 0x801D8CFCu;
    // 801D8CFC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8D00:
    ctx->pc = 0x801D8D00u;
    // 801D8D00: bl      0x801D8C84
    {
            ctx->lr = 0x801D8D04u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8C84u;
                return;
            }
            goto label_801D8C84;
    }

label_801D8D04:
    ctx->pc = 0x801D8D04u;
    ctx->downcount -= 5;
    // 801D8D04: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801D8D08:
    ctx->pc = 0x801D8D08u;
    // 801D8D08: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8D0C:
    ctx->pc = 0x801D8D0Cu;
    // 801D8D0C: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D8D10:
    ctx->pc = 0x801D8D10u;
    // 801D8D10: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D8D14:
    loop_801D8D14(ctx);
    if (ctx->pc == 0x801D8D28u) goto label_801D8D28;
    return;
label_801D8D18:
    ctx->pc = 0x801D8D18u;
    // 801D8D18: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8D1C:
    ctx->pc = 0x801D8D1Cu;
    // 801D8D1C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8D20:
    // 801D8D20: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D8D24:
    // 801D8D24: bc    16, 0, 0x801D8D14
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8D14u;
                return;
            }
            goto label_801D8D14;
        }
    }

label_801D8D28:
    ctx->pc = 0x801D8D28u;
    ctx->downcount -= 16;
    // 801D8D28: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8D2C:
    ctx->pc = 0x801D8D2Cu;
    // 801D8D2C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8D30:
    ctx->pc = 0x801D8D30u;
    // 801D8D30: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8D34:
    ctx->pc = 0x801D8D34u;
    // 801D8D34: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D8D38:
    ctx->pc = 0x801D8D38u;
    // 801D8D38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8D3C:
    ctx->pc = 0x801D8D3Cu;
    ctx->downcount -= 4;
    // 801D8D3C: lwz     r9, 596(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(596);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8D40:
    ctx->pc = 0x801D8D40u;
    // 801D8D40: lwz     r10, 592(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(592);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D8D44:
    ctx->pc = 0x801D8D44u;
    // 801D8D44: cmpwi   r9, 0
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

label_801D8D48:
    ctx->pc = 0x801D8D48u;
    // 801D8D48: bc    12, 2, 0x801D8D54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8D54;
        }
    }

label_801D8D4C:
    ctx->pc = 0x801D8D4Cu;
    ctx->downcount -= 2;
    // 801D8D4C: stw     r10, 592(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(592);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8D50:
    ctx->pc = 0x801D8D50u;
    // 801D8D50: b       0x801D8D5C
    {
            goto label_801D8D5C;
    }

label_801D8D54:
    ctx->pc = 0x801D8D54u;
    ctx->downcount -= 2;
    // 801D8D54: lwz     r9, 604(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(604);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8D58:
    ctx->pc = 0x801D8D58u;
    // 801D8D58: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8D5C:
    ctx->pc = 0x801D8D5Cu;
    ctx->downcount -= 3;
    // 801D8D5C: lwz     r9, 592(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8D60:
    ctx->pc = 0x801D8D60u;
    // 801D8D60: cmpwi   r9, 0
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

label_801D8D64:
    ctx->pc = 0x801D8D64u;
    // 801D8D64: bc    12, 2, 0x801D8D74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8D74;
        }
    }

label_801D8D68:
    ctx->pc = 0x801D8D68u;
    ctx->downcount -= 3;
    // 801D8D68: lwz     r0, 596(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8D6C:
    ctx->pc = 0x801D8D6Cu;
    // 801D8D6C: stw     r0, 596(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8D70:
    ctx->pc = 0x801D8D70u;
    // 801D8D70: b       0x801D8D80
    {
            goto label_801D8D80;
    }

label_801D8D74:
    ctx->pc = 0x801D8D74u;
    ctx->downcount -= 3;
    // 801D8D74: lwz     r9, 604(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(604);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8D78:
    ctx->pc = 0x801D8D78u;
    // 801D8D78: lwz     r0, 596(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(596);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8D7C:
    ctx->pc = 0x801D8D7Cu;
    // 801D8D7C: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8D80:
    ctx->pc = 0x801D8D80u;
    ctx->downcount -= 6;
    // 801D8D80: lwz     r11, 604(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(604);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D8D84:
    ctx->pc = 0x801D8D84u;
    // 801D8D84: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D8D88:
    ctx->pc = 0x801D8D88u;
    // 801D8D88: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8D8C:
    ctx->pc = 0x801D8D8Cu;
    // 801D8D8C: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D8D90:
    ctx->pc = 0x801D8D90u;
    // 801D8D90: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8D94:
    ctx->pc = 0x801D8D94u;
    // 801D8D94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8D98:
    ctx->pc = 0x801D8D98u;
    ctx->downcount -= 18;
    // 801D8D98: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8D9C:
    ctx->pc = 0x801D8D9Cu;
    // 801D8D9C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8DA0:
    ctx->pc = 0x801D8DA0u;
    // 801D8DA0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8DA4:
    ctx->pc = 0x801D8DA4u;
    // 801D8DA4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8DA8:
    ctx->pc = 0x801D8DA8u;
    // 801D8DA8: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8DAC:
    ctx->pc = 0x801D8DACu;
    // 801D8DAC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8DB0:
    ctx->pc = 0x801D8DB0u;
    // 801D8DB0: cmpwi   r31, 0
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

label_801D8DB4:
    ctx->pc = 0x801D8DB4u;
    // 801D8DB4: bc    12, 2, 0x801D8DD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8DD8;
        }
    }

label_801D8DB8:
    ctx->downcount -= 2;
    // 801D8DB8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8DBC:
    // 801D8DBC: bl      0x801D8D3C
    {
            ctx->lr = 0x801D8DC0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8D3Cu;
                return;
            }
            goto label_801D8D3C;
    }

label_801D8DC0:
    ctx->downcount -= 4;
    // 801D8DC0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8DC4:
    // 801D8DC4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8DC8:
    // 801D8DC8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D8DCC:
    // 801D8DCC: bl      0x801D8BC8
    {
            ctx->lr = 0x801D8DD0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8BC8u;
                return;
            }
            goto label_801D8BC8;
    }

label_801D8DD0:
    ctx->downcount -= 2;
    // 801D8DD0: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8DD4:
    // 801D8DD4: bc    4, 2, 0x801D8DB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8DB8u;
                return;
            }
            goto label_801D8DB8;
        }
    }

label_801D8DD8:
    ctx->pc = 0x801D8DD8u;
    ctx->downcount -= 16;
    // 801D8DD8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8DDC:
    ctx->pc = 0x801D8DDCu;
    // 801D8DDC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8DE0:
    ctx->pc = 0x801D8DE0u;
    // 801D8DE0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8DE4:
    ctx->pc = 0x801D8DE4u;
    // 801D8DE4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8DE8:
    ctx->pc = 0x801D8DE8u;
    // 801D8DE8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8DEC:
    ctx->pc = 0x801D8DECu;
    ctx->downcount -= 17;
    // 801D8DEC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8DF0:
    ctx->pc = 0x801D8DF0u;
    // 801D8DF0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8DF4:
    ctx->pc = 0x801D8DF4u;
    // 801D8DF4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8DF8:
    ctx->pc = 0x801D8DF8u;
    // 801D8DF8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8DFC:
    ctx->pc = 0x801D8DFCu;
    // 801D8DFC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8E00:
    ctx->pc = 0x801D8E00u;
    // 801D8E00: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_801D8E04:
    ctx->pc = 0x801D8E04u;
    // 801D8E04: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_801D8E08:
    ctx->downcount -= 3;
    // 801D8E08: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8E0C:
    // 801D8E0C: addi    r4, r30, 8
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(8);

label_801D8E10:
    // 801D8E10: bl      0x801D8D98
    {
            ctx->lr = 0x801D8E14u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8D98u;
                return;
            }
            goto label_801D8D98;
    }

label_801D8E14:
    ctx->downcount -= 3;
    // 801D8E14: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801D8E18:
    // 801D8E18: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D8E1C:
    // 801D8E1C: bc    4, 2, 0x801D8E08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8E08u;
                return;
            }
            goto label_801D8E08;
        }
    }

label_801D8E20:
    ctx->pc = 0x801D8E20u;
    ctx->downcount -= 16;
    // 801D8E20: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8E24:
    ctx->pc = 0x801D8E24u;
    // 801D8E24: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8E28:
    ctx->pc = 0x801D8E28u;
    // 801D8E28: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8E2C:
    ctx->pc = 0x801D8E2Cu;
    // 801D8E2C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8E30:
    ctx->pc = 0x801D8E30u;
    // 801D8E30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8E34:
    ctx->pc = 0x801D8E34u;
    ctx->downcount -= 21;
    // 801D8E34: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8E38:
    ctx->pc = 0x801D8E38u;
    // 801D8E38: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8E3C:
    ctx->pc = 0x801D8E3Cu;
    // 801D8E3C: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D8E40:
    ctx->pc = 0x801D8E40u;
    // 801D8E40: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8E44:
    ctx->pc = 0x801D8E44u;
    // 801D8E44: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8E48:
    ctx->pc = 0x801D8E48u;
    // 801D8E48: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D8E4C:
    ctx->pc = 0x801D8E4Cu;
    // 801D8E4C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8E50:
    ctx->pc = 0x801D8E50u;
    // 801D8E50: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8E54:
    ctx->pc = 0x801D8E54u;
    // 801D8E54: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8E58:
    ctx->pc = 0x801D8E58u;
    // 801D8E58: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D8E5C:
    ctx->pc = 0x801D8E5Cu;
    // 801D8E5C: bc    12, 18, 0x801D8E94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8E94;
        }
    }

label_801D8E60:
    ctx->pc = 0x801D8E60u;
    ctx->downcount -= 2;
    // 801D8E60: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8E64:
    ctx->pc = 0x801D8E64u;
    // 801D8E64: bl      0x801D8D3C
    {
            ctx->lr = 0x801D8E68u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8D3Cu;
                return;
            }
            goto label_801D8D3C;
    }

label_801D8E68:
    ctx->pc = 0x801D8E68u;
    ctx->downcount -= 6;
    // 801D8E68: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8E6C:
    ctx->pc = 0x801D8E6Cu;
    // 801D8E6C: stw     r0, 604(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(604);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8E70:
    ctx->pc = 0x801D8E70u;
    // 801D8E70: stw     r0, 592(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(592);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8E74:
    ctx->pc = 0x801D8E74u;
    // 801D8E74: stw     r0, 596(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(596);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8E78:
    ctx->pc = 0x801D8E78u;
    // 801D8E78: stw     r0, 600(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(600);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8E7C:
    ctx->pc = 0x801D8E7Cu;
    // 801D8E7C: bc    12, 18, 0x801D8E94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8E94;
        }
    }

label_801D8E80:
    ctx->pc = 0x801D8E80u;
    ctx->downcount -= 7;
    // 801D8E80: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D8E84:
    ctx->pc = 0x801D8E84u;
    // 801D8E84: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8E88:
    ctx->pc = 0x801D8E88u;
    // 801D8E88: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D8E8C:
    ctx->pc = 0x801D8E8Cu;
    // 801D8E8C: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D8E90:
    ctx->pc = 0x801D8E90u;
    // 801D8E90: bl      0x801D8BC8
    {
            ctx->lr = 0x801D8E94u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8BC8u;
                return;
            }
            goto label_801D8BC8;
    }

label_801D8E94:
    ctx->pc = 0x801D8E94u;
    ctx->downcount -= 19;
    // 801D8E94: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8E98:
    ctx->pc = 0x801D8E98u;
    // 801D8E98: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8E9C:
    ctx->pc = 0x801D8E9Cu;
    // 801D8E9C: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D8EA0:
    ctx->pc = 0x801D8EA0u;
    // 801D8EA0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8EA4:
    ctx->pc = 0x801D8EA4u;
    // 801D8EA4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8EA8:
    ctx->pc = 0x801D8EA8u;
    // 801D8EA8: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D8EAC:
    ctx->pc = 0x801D8EACu;
    // 801D8EAC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8EB0:
    ctx->pc = 0x801D8EB0u;
    // 801D8EB0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8EB4:
    ctx->pc = 0x801D8EB4u;
    ctx->downcount -= 4;
    // 801D8EB4: lwz     r9, 112(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(112);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8EB8:
    ctx->pc = 0x801D8EB8u;
    // 801D8EB8: lwz     r10, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D8EBC:
    ctx->pc = 0x801D8EBCu;
    // 801D8EBC: cmpwi   r9, 0
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

label_801D8EC0:
    ctx->pc = 0x801D8EC0u;
    // 801D8EC0: bc    12, 2, 0x801D8ECC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8ECC;
        }
    }

label_801D8EC4:
    ctx->pc = 0x801D8EC4u;
    ctx->downcount -= 2;
    // 801D8EC4: stw     r10, 108(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8EC8:
    ctx->pc = 0x801D8EC8u;
    // 801D8EC8: b       0x801D8ED4
    {
            goto label_801D8ED4;
    }

label_801D8ECC:
    ctx->pc = 0x801D8ECCu;
    ctx->downcount -= 2;
    // 801D8ECC: lwz     r9, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8ED0:
    ctx->pc = 0x801D8ED0u;
    // 801D8ED0: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D8ED4:
    ctx->pc = 0x801D8ED4u;
    ctx->downcount -= 3;
    // 801D8ED4: lwz     r9, 108(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(108);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8ED8:
    ctx->pc = 0x801D8ED8u;
    // 801D8ED8: cmpwi   r9, 0
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

label_801D8EDC:
    ctx->pc = 0x801D8EDCu;
    // 801D8EDC: bc    12, 2, 0x801D8EEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8EEC;
        }
    }

label_801D8EE0:
    ctx->pc = 0x801D8EE0u;
    ctx->downcount -= 3;
    // 801D8EE0: lwz     r0, 112(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(112);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8EE4:
    ctx->pc = 0x801D8EE4u;
    // 801D8EE4: stw     r0, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8EE8:
    ctx->pc = 0x801D8EE8u;
    // 801D8EE8: b       0x801D8EF8
    {
            goto label_801D8EF8;
    }

label_801D8EEC:
    ctx->pc = 0x801D8EECu;
    ctx->downcount -= 3;
    // 801D8EEC: lwz     r9, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8EF0:
    ctx->pc = 0x801D8EF0u;
    // 801D8EF0: lwz     r0, 112(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(112);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8EF4:
    ctx->pc = 0x801D8EF4u;
    // 801D8EF4: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8EF8:
    ctx->pc = 0x801D8EF8u;
    ctx->downcount -= 6;
    // 801D8EF8: lwz     r11, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D8EFC:
    ctx->pc = 0x801D8EFCu;
    // 801D8EFC: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D8F00:
    ctx->pc = 0x801D8F00u;
    // 801D8F00: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8F04:
    ctx->pc = 0x801D8F04u;
    // 801D8F04: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D8F08:
    ctx->pc = 0x801D8F08u;
    // 801D8F08: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8F0C:
    ctx->pc = 0x801D8F0Cu;
    // 801D8F0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8F10:
    ctx->pc = 0x801D8F10u;
    ctx->downcount -= 2;
    // 801D8F10: or.   r4, r4, r4
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

label_801D8F14:
    ctx->pc = 0x801D8F14u;
    // 801D8F14: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8F18:
    ctx->pc = 0x801D8F18u;
    ctx->downcount -= 8;
    // 801D8F18: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801D8F1C:
    ctx->pc = 0x801D8F1Cu;
    // 801D8F1C: stw     r3, 120(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D8F20:
    ctx->pc = 0x801D8F20u;
    // 801D8F20: stw     r9, 108(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8F24:
    ctx->pc = 0x801D8F24u;
    // 801D8F24: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8F28:
    ctx->pc = 0x801D8F28u;
    // 801D8F28: stw     r0, 112(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8F2C:
    ctx->pc = 0x801D8F2Cu;
    // 801D8F2C: lwz     r9, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8F30:
    ctx->pc = 0x801D8F30u;
    // 801D8F30: cmpwi   r9, 0
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

label_801D8F34:
    ctx->pc = 0x801D8F34u;
    // 801D8F34: bc    12, 2, 0x801D8F40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8F40;
        }
    }

label_801D8F38:
    ctx->pc = 0x801D8F38u;
    ctx->downcount -= 2;
    // 801D8F38: stw     r4, 108(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8F3C:
    ctx->pc = 0x801D8F3Cu;
    // 801D8F3C: b       0x801D8F44
    {
            goto label_801D8F44;
    }

label_801D8F40:
    ctx->pc = 0x801D8F40u;
    ctx->downcount -= 1;
    // 801D8F40: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8F44:
    ctx->pc = 0x801D8F44u;
    ctx->downcount -= 5;
    // 801D8F44: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8F48:
    ctx->pc = 0x801D8F48u;
    // 801D8F48: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D8F4C:
    ctx->pc = 0x801D8F4Cu;
    // 801D8F4C: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D8F50:
    ctx->pc = 0x801D8F50u;
    // 801D8F50: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8F54:
    ctx->pc = 0x801D8F54u;
    // 801D8F54: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8F58:
    ctx->pc = 0x801D8F58u;
    ctx->downcount -= 21;
    // 801D8F58: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D8F5C:
    ctx->pc = 0x801D8F5Cu;
    // 801D8F5C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D8F60:
    ctx->pc = 0x801D8F60u;
    // 801D8F60: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D8F64:
    ctx->pc = 0x801D8F64u;
    // 801D8F64: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D8F68:
    ctx->pc = 0x801D8F68u;
    // 801D8F68: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8F6C:
    ctx->pc = 0x801D8F6Cu;
    // 801D8F6C: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D8F70:
    ctx->pc = 0x801D8F70u;
    // 801D8F70: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D8F74:
    ctx->pc = 0x801D8F74u;
    // 801D8F74: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D8F78:
    ctx->pc = 0x801D8F78u;
    // 801D8F78: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D8F7C:
    ctx->pc = 0x801D8F7Cu;
    // 801D8F7C: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D8F80:
    ctx->pc = 0x801D8F80u;
    // 801D8F80: bc    12, 18, 0x801D8FB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8FB8;
        }
    }

label_801D8F84:
    ctx->pc = 0x801D8F84u;
    ctx->downcount -= 2;
    // 801D8F84: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8F88:
    ctx->pc = 0x801D8F88u;
    // 801D8F88: bl      0x801D8EB4
    {
            ctx->lr = 0x801D8F8Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8EB4u;
                return;
            }
            goto label_801D8EB4;
    }

label_801D8F8C:
    ctx->pc = 0x801D8F8Cu;
    ctx->downcount -= 6;
    // 801D8F8C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8F90:
    ctx->pc = 0x801D8F90u;
    // 801D8F90: stw     r0, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8F94:
    ctx->pc = 0x801D8F94u;
    // 801D8F94: stw     r0, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8F98:
    ctx->pc = 0x801D8F98u;
    // 801D8F98: stw     r0, 112(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8F9C:
    ctx->pc = 0x801D8F9Cu;
    // 801D8F9C: stw     r0, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8FA0:
    ctx->pc = 0x801D8FA0u;
    // 801D8FA0: bc    12, 18, 0x801D8FB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D8FB8;
        }
    }

label_801D8FA4:
    ctx->pc = 0x801D8FA4u;
    ctx->downcount -= 7;
    // 801D8FA4: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D8FA8:
    ctx->pc = 0x801D8FA8u;
    // 801D8FA8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8FAC:
    ctx->pc = 0x801D8FACu;
    // 801D8FAC: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D8FB0:
    ctx->pc = 0x801D8FB0u;
    // 801D8FB0: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D8FB4:
    ctx->pc = 0x801D8FB4u;
    // 801D8FB4: bl      0x801D8F10
    {
            ctx->lr = 0x801D8FB8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8F10u;
                return;
            }
            goto label_801D8F10;
    }

label_801D8FB8:
    ctx->pc = 0x801D8FB8u;
    ctx->downcount -= 19;
    // 801D8FB8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D8FBC:
    ctx->pc = 0x801D8FBCu;
    // 801D8FBC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D8FC0:
    ctx->pc = 0x801D8FC0u;
    // 801D8FC0: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D8FC4:
    ctx->pc = 0x801D8FC4u;
    // 801D8FC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D8FC8:
    ctx->pc = 0x801D8FC8u;
    // 801D8FC8: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D8FCC:
    ctx->pc = 0x801D8FCCu;
    // 801D8FCC: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D8FD0:
    ctx->pc = 0x801D8FD0u;
    // 801D8FD0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D8FD4:
    ctx->pc = 0x801D8FD4u;
    // 801D8FD4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8FD8:
    ctx->pc = 0x801D8FD8u;
    ctx->downcount -= 2;
    // 801D8FD8: or.   r4, r4, r4
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

label_801D8FDC:
    ctx->pc = 0x801D8FDCu;
    // 801D8FDC: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D8FE0:
    ctx->pc = 0x801D8FE0u;
    ctx->downcount -= 8;
    // 801D8FE0: stw     r3, 120(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D8FE4:
    ctx->pc = 0x801D8FE4u;
    // 801D8FE4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D8FE8:
    ctx->pc = 0x801D8FE8u;
    // 801D8FE8: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8FEC:
    ctx->pc = 0x801D8FECu;
    // 801D8FEC: stw     r0, 112(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D8FF0:
    ctx->pc = 0x801D8FF0u;
    // 801D8FF0: stw     r9, 108(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D8FF4:
    ctx->pc = 0x801D8FF4u;
    // 801D8FF4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D8FF8:
    ctx->pc = 0x801D8FF8u;
    // 801D8FF8: cmpwi   r9, 0
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

label_801D8FFC:
    ctx->pc = 0x801D8FFCu;
    // 801D8FFC: bc    12, 2, 0x801D9008
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D9008;
        }
    }

label_801D9000:
    ctx->pc = 0x801D9000u;
    ctx->downcount -= 2;
    // 801D9000: stw     r4, 112(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D9004:
    ctx->pc = 0x801D9004u;
    // 801D9004: b       0x801D900C
    {
            goto label_801D900C;
    }

label_801D9008:
    ctx->pc = 0x801D9008u;
    ctx->downcount -= 1;
    // 801D9008: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D900C:
    ctx->pc = 0x801D900Cu;
    ctx->downcount -= 5;
    // 801D900C: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D9010:
    ctx->pc = 0x801D9010u;
    // 801D9010: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D9014:
    ctx->pc = 0x801D9014u;
    // 801D9014: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D9018:
    ctx->pc = 0x801D9018u;
    // 801D9018: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D901C:
    ctx->pc = 0x801D901Cu;
    // 801D901C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9020:
    ctx->pc = 0x801D9020u;
    ctx->downcount -= 20;
    // 801D9020: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9024:
    ctx->pc = 0x801D9024u;
    // 801D9024: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9028:
    ctx->pc = 0x801D9028u;
    // 801D9028: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D902C:
    ctx->pc = 0x801D902Cu;
    // 801D902C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9030:
    ctx->pc = 0x801D9030u;
    // 801D9030: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9034:
    ctx->pc = 0x801D9034u;
    // 801D9034: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D9038:
    ctx->pc = 0x801D9038u;
    // 801D9038: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D903C:
    ctx->pc = 0x801D903Cu;
    // 801D903C: cmpwi   r4, 0
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

label_801D9040:
    ctx->pc = 0x801D9040u;
    // 801D9040: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D9044:
    ctx->pc = 0x801D9044u;
    // 801D9044: bc    12, 2, 0x801D9080
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D9080;
        }
    }

label_801D9048:
    ctx->pc = 0x801D9048u;
    ctx->downcount -= 3;
    // 801D9048: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D904C:
    ctx->pc = 0x801D904Cu;
    // 801D904C: cmpwi   r30, 0
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

label_801D9050:
    ctx->pc = 0x801D9050u;
    // 801D9050: bc    12, 2, 0x801D9080
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D9080;
        }
    }

label_801D9054:
    ctx->pc = 0x801D9054u;
    ctx->downcount -= 1;
    // 801D9054: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D9058:
    ctx->pc = 0x801D9058u;
    ctx->downcount -= 8;
    // 801D9058: stw     r29, 108(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D905C:
    // 801D905C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D9060:
    ctx->pc = 0x801D9060u;
    // 801D9060: stw     r29, 112(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D9064:
    // 801D9064: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D9068:
    ctx->pc = 0x801D9068u;
    // 801D9068: stw     r29, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D906C:
    ctx->pc = 0x801D906Cu;
    // 801D906C: stw     r29, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D9070:
    // 801D9070: addi    r31, r31, 124
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(124);

label_801D9074:
    // 801D9074: bl      0x801D8FD8
    {
            ctx->lr = 0x801D9078u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8FD8u;
                return;
            }
            goto label_801D8FD8;
    }

label_801D9078:
    ctx->downcount -= 2;
    // 801D9078: addic.  r30, r30, -1
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

label_801D907C:
    // 801D907C: bc    4, 2, 0x801D9058
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9058u;
                return;
            }
            goto label_801D9058;
        }
    }

label_801D9080:
    ctx->pc = 0x801D9080u;
    ctx->downcount -= 16;
    // 801D9080: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9084:
    ctx->pc = 0x801D9084u;
    // 801D9084: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9088:
    ctx->pc = 0x801D9088u;
    // 801D9088: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D908C:
    ctx->pc = 0x801D908Cu;
    // 801D908C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D9090:
    ctx->pc = 0x801D9090u;
    // 801D9090: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9094:
    ctx->pc = 0x801D9094u;
    ctx->downcount -= 29;
    // 801D9094: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9098:
    ctx->pc = 0x801D9098u;
    // 801D9098: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D909C:
    ctx->pc = 0x801D909Cu;
    // 801D909C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D90A0:
    ctx->pc = 0x801D90A0u;
    // 801D90A0: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D90A4:
    ctx->pc = 0x801D90A4u;
    // 801D90A4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D90A8:
    ctx->pc = 0x801D90A8u;
    // 801D90A8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D90AC:
    ctx->pc = 0x801D90ACu;
    // 801D90AC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D90B0:
    ctx->pc = 0x801D90B0u;
    // 801D90B0: mulli   r4, r29, 124
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)124);

label_801D90B4:
    ctx->pc = 0x801D90B4u;
    // 801D90B4: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D90B8:
    ctx->pc = 0x801D90B8u;
    // 801D90B8: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D90BC:
    ctx->pc = 0x801D90BCu;
    // 801D90BC: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D90C0:
    ctx->pc = 0x801D90C0u;
    // 801D90C0: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D90C4:
    ctx->pc = 0x801D90C4u;
    // 801D90C4: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D90C8:
    ctx->pc = 0x801D90C8u;
    // 801D90C8: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D90CC:
    ctx->pc = 0x801D90CCu;
    // 801D90CC: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D90D0:
    ctx->pc = 0x801D90D0u;
    // 801D90D0: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D90D4:
    ctx->pc = 0x801D90D4u;
    // 801D90D4: bl      0x80039640
    {
            ctx->lr = 0x801D90D8u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D90D8:
    ctx->pc = 0x801D90D8u;
    ctx->downcount -= 4;
    // 801D90D8: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D90DC:
    ctx->pc = 0x801D90DCu;
    // 801D90DC: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D90E0:
    ctx->pc = 0x801D90E0u;
    // 801D90E0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D90E4:
    ctx->pc = 0x801D90E4u;
    // 801D90E4: bl      0x801D9020
    {
            ctx->lr = 0x801D90E8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9020u;
                return;
            }
            goto label_801D9020;
    }

label_801D90E8:
    ctx->pc = 0x801D90E8u;
    ctx->downcount -= 16;
    // 801D90E8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D90EC:
    ctx->pc = 0x801D90ECu;
    // 801D90EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D90F0:
    ctx->pc = 0x801D90F0u;
    // 801D90F0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D90F4:
    ctx->pc = 0x801D90F4u;
    // 801D90F4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D90F8:
    ctx->pc = 0x801D90F8u;
    // 801D90F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D90FC:
    ctx->pc = 0x801D90FCu;
    ctx->downcount -= 16;
    // 801D90FC: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9100:
    ctx->pc = 0x801D9100u;
    // 801D9100: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9104:
    ctx->pc = 0x801D9104u;
    // 801D9104: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9108:
    ctx->pc = 0x801D9108u;
    // 801D9108: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D910C:
    ctx->pc = 0x801D910Cu;
    // 801D910C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9110:
    ctx->pc = 0x801D9110u;
    // 801D9110: bl      0x801D9094
    {
            ctx->lr = 0x801D9114u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9094u;
                return;
            }
            goto label_801D9094;
    }

label_801D9114:
    ctx->pc = 0x801D9114u;
    ctx->downcount -= 5;
    // 801D9114: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_801D9118:
    ctx->pc = 0x801D9118u;
    // 801D9118: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D911C:
    ctx->pc = 0x801D911Cu;
    // 801D911C: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D9120:
    ctx->pc = 0x801D9120u;
    // 801D9120: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D9124:
    loop_801D9124(ctx);
    if (ctx->pc == 0x801D9138u) goto label_801D9138;
    return;
label_801D9128:
    ctx->pc = 0x801D9128u;
    // 801D9128: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D912C:
    ctx->pc = 0x801D912Cu;
    // 801D912C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9130:
    // 801D9130: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D9134:
    // 801D9134: bc    16, 0, 0x801D9124
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9124u;
                return;
            }
            goto label_801D9124;
        }
    }

label_801D9138:
    ctx->pc = 0x801D9138u;
    ctx->downcount -= 16;
    // 801D9138: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D913C:
    ctx->pc = 0x801D913Cu;
    // 801D913C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9140:
    ctx->pc = 0x801D9140u;
    // 801D9140: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D9144:
    ctx->pc = 0x801D9144u;
    // 801D9144: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D9148:
    ctx->pc = 0x801D9148u;
    // 801D9148: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D914C:
    ctx->pc = 0x801D914Cu;
    ctx->downcount -= 18;
    // 801D914C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9150:
    ctx->pc = 0x801D9150u;
    // 801D9150: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9154:
    ctx->pc = 0x801D9154u;
    // 801D9154: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9158:
    ctx->pc = 0x801D9158u;
    // 801D9158: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D915C:
    ctx->pc = 0x801D915Cu;
    // 801D915C: lwz     r30, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801D9160:
    ctx->pc = 0x801D9160u;
    // 801D9160: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D9164:
    ctx->pc = 0x801D9164u;
    // 801D9164: cmpwi   r30, 0
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

label_801D9168:
    ctx->pc = 0x801D9168u;
    // 801D9168: bc    12, 2, 0x801D9184
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D9184;
        }
    }

label_801D916C:
    ctx->downcount -= 5;
    // 801D916C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D9170:
    ctx->pc = 0x801D9170u;
    // 801D9170: mtlr    r31
    ctx->lr = ctx->gpr[31];

label_801D9174:
    ctx->pc = 0x801D9174u;
    // 801D9174: lwz     r30, 108(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(108);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801D9178:
    ctx->pc = 0x801D9178u;
    // 801D9178: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801D917Cu;
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D917C:
    ctx->downcount -= 2;
    // 801D917C: or.   r30, r30, r30
    {
        ctx->gpr[30] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[30];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D9180:
    // 801D9180: bc    4, 2, 0x801D916C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D916Cu;
                return;
            }
            goto label_801D916C;
        }
    }

label_801D9184:
    ctx->pc = 0x801D9184u;
    ctx->downcount -= 16;
    // 801D9184: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9188:
    ctx->pc = 0x801D9188u;
    // 801D9188: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D918C:
    ctx->pc = 0x801D918Cu;
    // 801D918C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D9190:
    ctx->pc = 0x801D9190u;
    // 801D9190: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D9194:
    ctx->pc = 0x801D9194u;
    // 801D9194: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9198:
    ctx->pc = 0x801D9198u;
    ctx->downcount -= 18;
    // 801D9198: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D919C:
    ctx->pc = 0x801D919Cu;
    // 801D919C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D91A0:
    ctx->pc = 0x801D91A0u;
    // 801D91A0: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D91A4:
    ctx->pc = 0x801D91A4u;
    // 801D91A4: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D91A8:
    ctx->pc = 0x801D91A8u;
    // 801D91A8: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D91AC:
    ctx->pc = 0x801D91ACu;
    // 801D91AC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D91B0:
    ctx->pc = 0x801D91B0u;
    // 801D91B0: cmpwi   r31, 0
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

label_801D91B4:
    ctx->pc = 0x801D91B4u;
    // 801D91B4: bc    12, 2, 0x801D91D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D91D8;
        }
    }

label_801D91B8:
    ctx->downcount -= 2;
    // 801D91B8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D91BC:
    // 801D91BC: bl      0x801D8EB4
    {
            ctx->lr = 0x801D91C0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8EB4u;
                return;
            }
            goto label_801D8EB4;
    }

label_801D91C0:
    ctx->downcount -= 4;
    // 801D91C0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D91C4:
    // 801D91C4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D91C8:
    // 801D91C8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D91CC:
    // 801D91CC: bl      0x801D8FD8
    {
            ctx->lr = 0x801D91D0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D8FD8u;
                return;
            }
            goto label_801D8FD8;
    }

label_801D91D0:
    ctx->downcount -= 2;
    // 801D91D0: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D91D4:
    // 801D91D4: bc    4, 2, 0x801D91B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D91B8u;
                return;
            }
            goto label_801D91B8;
        }
    }

label_801D91D8:
    ctx->pc = 0x801D91D8u;
    ctx->downcount -= 16;
    // 801D91D8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D91DC:
    ctx->pc = 0x801D91DCu;
    // 801D91DC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D91E0:
    ctx->pc = 0x801D91E0u;
    // 801D91E0: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D91E4:
    ctx->pc = 0x801D91E4u;
    // 801D91E4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D91E8:
    ctx->pc = 0x801D91E8u;
    // 801D91E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D91EC:
    ctx->pc = 0x801D91ECu;
    ctx->downcount -= 17;
    // 801D91EC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D91F0:
    ctx->pc = 0x801D91F0u;
    // 801D91F0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D91F4:
    ctx->pc = 0x801D91F4u;
    // 801D91F4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D91F8:
    ctx->pc = 0x801D91F8u;
    // 801D91F8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D91FC:
    ctx->pc = 0x801D91FCu;
    // 801D91FC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9200:
    ctx->pc = 0x801D9200u;
    // 801D9200: li      r29, 2
    ctx->gpr[29] = (u32)(s32)(2);

label_801D9204:
    ctx->pc = 0x801D9204u;
    // 801D9204: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_801D9208:
    ctx->downcount -= 3;
    // 801D9208: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D920C:
    // 801D920C: addi    r4, r30, 8
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(8);

label_801D9210:
    // 801D9210: bl      0x801D9198
    {
            ctx->lr = 0x801D9214u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9198u;
                return;
            }
            goto label_801D9198;
    }

label_801D9214:
    ctx->downcount -= 3;
    // 801D9214: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801D9218:
    // 801D9218: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D921C:
    // 801D921C: bc    4, 2, 0x801D9208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9208u;
                return;
            }
            goto label_801D9208;
        }
    }

label_801D9220:
    ctx->pc = 0x801D9220u;
    ctx->downcount -= 16;
    // 801D9220: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9224:
    ctx->pc = 0x801D9224u;
    // 801D9224: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9228:
    ctx->pc = 0x801D9228u;
    // 801D9228: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D922C:
    ctx->pc = 0x801D922Cu;
    // 801D922C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D9230:
    ctx->pc = 0x801D9230u;
    // 801D9230: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9234:
    ctx->pc = 0x801D9234u;
    ctx->downcount -= 3;
    // 801D9234: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_801D9238:
    ctx->pc = 0x801D9238u;
    // 801D9238: lwz     r3, 10456(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(10456);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801D923C:
    ctx->pc = 0x801D923Cu;
    // 801D923C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9240:
    ctx->pc = 0x801D9240u;
    ctx->downcount -= 12;
    // 801D9240: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9244:
    ctx->pc = 0x801D9244u;
    // 801D9244: li      r9, 20
    ctx->gpr[9] = (u32)(s32)(20);

label_801D9248:
    ctx->pc = 0x801D9248u;
    // 801D9248: li      r0, 300
    ctx->gpr[0] = (u32)(s32)(300);

label_801D924C:
    ctx->pc = 0x801D924Cu;
    // 801D924C: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9250:
    ctx->pc = 0x801D9250u;
    // 801D9250: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9254:
    ctx->pc = 0x801D9254u;
    // 801D9254: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D9258:
    ctx->pc = 0x801D9258u;
    // 801D9258: lwz     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D925C:
    ctx->pc = 0x801D925Cu;
    // 801D925C: lwz     r10, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D9260:
    ctx->pc = 0x801D9260u;
    // 801D9260: stw     r9, 0(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D9264:
    ctx->pc = 0x801D9264u;
    // 801D9264: stw     r10, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D9268:
    ctx->pc = 0x801D9268u;
    // 801D9268: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D926C:
    ctx->pc = 0x801D926Cu;
    // 801D926C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9270:
    ctx->pc = 0x801D9270u;
    ctx->downcount -= 19;
    // 801D9270: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9274:
    ctx->pc = 0x801D9274u;
    // 801D9274: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9278:
    ctx->pc = 0x801D9278u;
    // 801D9278: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D927C:
    ctx->pc = 0x801D927Cu;
    // 801D927C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9280:
    ctx->pc = 0x801D9280u;
    // 801D9280: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D9284:
    ctx->pc = 0x801D9284u;
    // 801D9284: or   r31, r5, r5
    {
        ctx->gpr[31] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D9288:
    ctx->pc = 0x801D9288u;
    // 801D9288: or   r30, r6, r6
    {
        ctx->gpr[30] = ctx->gpr[6] | ctx->gpr[6];
    }

label_801D928C:
    ctx->pc = 0x801D928Cu;
    // 801D928C: andi.   r0, r7, 0x0001
    {
        ctx->gpr[0] = ctx->gpr[7] & 0x0001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D9290:
    ctx->pc = 0x801D9290u;
    // 801D9290: bc    12, 2, 0x801D92B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D92B0;
        }
    }

label_801D9294:
    ctx->pc = 0x801D9294u;
    ctx->downcount -= 6;
    // 801D9294: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_801D9298:
    ctx->pc = 0x801D9298u;
    // 801D9298: lis     r3, -32700
    ctx->gpr[3] = ((u32)(s32)(-32700) << 16);

label_801D929C:
    ctx->pc = 0x801D929Cu;
    // 801D929C: lfs     f1, 14072(r9)
    if (!ppc_fp_available(ctx, 0x801D929Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(14072);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801D92A0:
    ctx->pc = 0x801D92A0u;
    // 801D92A0: addi    r3, r3, -26904
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-26904);

label_801D92A4:
    ctx->pc = 0x801D92A4u;
    // 801D92A4: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801D92A4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801D92A8:
    ctx->pc = 0x801D92A8u;
    // 801D92A8: bl      0x80034E6C
    {
            ctx->lr = 0x801D92ACu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801D92AC:
    ctx->pc = 0x801D92ACu;
    ctx->downcount -= 1;
    // 801D92AC: b       0x801D92C8
    {
            goto label_801D92C8;
    }

label_801D92B0:
    ctx->pc = 0x801D92B0u;
    ctx->downcount -= 6;
    // 801D92B0: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_801D92B4:
    ctx->pc = 0x801D92B4u;
    // 801D92B4: lis     r3, -32700
    ctx->gpr[3] = ((u32)(s32)(-32700) << 16);

label_801D92B8:
    ctx->pc = 0x801D92B8u;
    // 801D92B8: lfs     f1, 14076(r9)
    if (!ppc_fp_available(ctx, 0x801D92B8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(14076);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801D92BC:
    ctx->pc = 0x801D92BCu;
    // 801D92BC: addi    r3, r3, -26904
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-26904);

label_801D92C0:
    ctx->pc = 0x801D92C0u;
    // 801D92C0: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801D92C0u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801D92C4:
    ctx->pc = 0x801D92C4u;
    // 801D92C4: bl      0x80034E6C
    {
            ctx->lr = 0x801D92C8u;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801D92C8:
    ctx->pc = 0x801D92C8u;
    ctx->downcount -= 7;
    // 801D92C8: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_801D92CC:
    ctx->pc = 0x801D92CCu;
    // 801D92CC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D92D0:
    ctx->pc = 0x801D92D0u;
    // 801D92D0: addi    r5, r5, 14000
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(14000);

label_801D92D4:
    ctx->pc = 0x801D92D4u;
    // 801D92D4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D92D8:
    ctx->pc = 0x801D92D8u;
    // 801D92D8: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D92DC:
    ctx->pc = 0x801D92DCu;
    // 801D92DC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_801D92E0:
    ctx->pc = 0x801D92E0u;
    // 801D92E0: bl      0x80035D30
    {
            ctx->lr = 0x801D92E4u;
            ctx->pc = 0x80035D30u;
            return;
    }

label_801D92E4:
    ctx->pc = 0x801D92E4u;
    ctx->downcount -= 6;
    // 801D92E4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_801D92E8:
    ctx->pc = 0x801D92E8u;
    // 801D92E8: lis     r3, -32700
    ctx->gpr[3] = ((u32)(s32)(-32700) << 16);

label_801D92EC:
    ctx->pc = 0x801D92ECu;
    // 801D92EC: lfs     f1, 14080(r9)
    if (!ppc_fp_available(ctx, 0x801D92ECu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(14080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_801D92F0:
    ctx->pc = 0x801D92F0u;
    // 801D92F0: addi    r3, r3, -26904
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-26904);

label_801D92F4:
    ctx->pc = 0x801D92F4u;
    // 801D92F4: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x801D92F4u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_801D92F8:
    ctx->pc = 0x801D92F8u;
    // 801D92F8: bl      0x80034E6C
    {
            ctx->lr = 0x801D92FCu;
            ctx->pc = 0x80034E6Cu;
            return;
    }

label_801D92FC:
    ctx->pc = 0x801D92FCu;
    ctx->downcount -= 16;
    // 801D92FC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9300:
    ctx->pc = 0x801D9300u;
    // 801D9300: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9304:
    ctx->pc = 0x801D9304u;
    // 801D9304: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D9308:
    ctx->pc = 0x801D9308u;
    // 801D9308: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D930C:
    ctx->pc = 0x801D930Cu;
    // 801D930C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9310:
    ctx->pc = 0x801D9310u;
    ctx->downcount -= 2;
    // 801D9310: or.   r4, r4, r4
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

label_801D9314:
    ctx->pc = 0x801D9314u;
    // 801D9314: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9318:
    ctx->pc = 0x801D9318u;
    ctx->downcount -= 8;
    // 801D9318: stw     r3, 168(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(168);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801D931C:
    ctx->pc = 0x801D931Cu;
    // 801D931C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D9320:
    ctx->pc = 0x801D9320u;
    // 801D9320: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D9324:
    ctx->pc = 0x801D9324u;
    // 801D9324: stw     r0, 160(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9328:
    ctx->pc = 0x801D9328u;
    // 801D9328: stw     r9, 156(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D932C:
    ctx->pc = 0x801D932Cu;
    // 801D932C: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D9330:
    ctx->pc = 0x801D9330u;
    // 801D9330: cmpwi   r9, 0
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

label_801D9334:
    ctx->pc = 0x801D9334u;
    // 801D9334: bc    12, 2, 0x801D9340
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D9340;
        }
    }

label_801D9338:
    ctx->pc = 0x801D9338u;
    ctx->downcount -= 2;
    // 801D9338: stw     r4, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D933C:
    ctx->pc = 0x801D933Cu;
    // 801D933C: b       0x801D9344
    {
            goto label_801D9344;
    }

label_801D9340:
    ctx->pc = 0x801D9340u;
    ctx->downcount -= 1;
    // 801D9340: stw     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D9344:
    ctx->pc = 0x801D9344u;
    ctx->downcount -= 5;
    // 801D9344: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D9348:
    ctx->pc = 0x801D9348u;
    // 801D9348: stw     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D934C:
    ctx->pc = 0x801D934Cu;
    // 801D934C: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_801D9350:
    ctx->pc = 0x801D9350u;
    // 801D9350: stw     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D9354:
    ctx->pc = 0x801D9354u;
    // 801D9354: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9358:
    ctx->pc = 0x801D9358u;
    ctx->downcount -= 20;
    // 801D9358: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D935C:
    ctx->pc = 0x801D935Cu;
    // 801D935C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9360:
    ctx->pc = 0x801D9360u;
    // 801D9360: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9364:
    ctx->pc = 0x801D9364u;
    // 801D9364: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9368:
    ctx->pc = 0x801D9368u;
    // 801D9368: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D936C:
    ctx->pc = 0x801D936Cu;
    // 801D936C: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D9370:
    ctx->pc = 0x801D9370u;
    // 801D9370: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D9374:
    ctx->pc = 0x801D9374u;
    // 801D9374: cmpwi   r4, 0
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

label_801D9378:
    ctx->pc = 0x801D9378u;
    // 801D9378: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D937C:
    ctx->pc = 0x801D937Cu;
    // 801D937C: bc    12, 2, 0x801D93B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D93B8;
        }
    }

label_801D9380:
    ctx->pc = 0x801D9380u;
    ctx->downcount -= 3;
    // 801D9380: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D9384:
    ctx->pc = 0x801D9384u;
    // 801D9384: cmpwi   r30, 0
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

label_801D9388:
    ctx->pc = 0x801D9388u;
    // 801D9388: bc    12, 2, 0x801D93B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D93B8;
        }
    }

label_801D938C:
    ctx->pc = 0x801D938Cu;
    ctx->downcount -= 1;
    // 801D938C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D9390:
    ctx->pc = 0x801D9390u;
    ctx->downcount -= 8;
    // 801D9390: stw     r29, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D9394:
    // 801D9394: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D9398:
    ctx->pc = 0x801D9398u;
    // 801D9398: stw     r29, 160(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D939C:
    // 801D939C: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D93A0:
    ctx->pc = 0x801D93A0u;
    // 801D93A0: stw     r29, 164(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D93A4:
    ctx->pc = 0x801D93A4u;
    // 801D93A4: stw     r29, 168(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(168);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D93A8:
    // 801D93A8: addi    r31, r31, 172
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(172);

label_801D93AC:
    // 801D93AC: bl      0x801D9310
    {
            ctx->lr = 0x801D93B0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9310u;
                return;
            }
            goto label_801D9310;
    }

label_801D93B0:
    ctx->downcount -= 2;
    // 801D93B0: addic.  r30, r30, -1
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

label_801D93B4:
    // 801D93B4: bc    4, 2, 0x801D9390
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9390u;
                return;
            }
            goto label_801D9390;
        }
    }

label_801D93B8:
    ctx->pc = 0x801D93B8u;
    ctx->downcount -= 16;
    // 801D93B8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D93BC:
    ctx->pc = 0x801D93BCu;
    // 801D93BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D93C0:
    ctx->pc = 0x801D93C0u;
    // 801D93C0: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D93C4:
    ctx->pc = 0x801D93C4u;
    // 801D93C4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D93C8:
    ctx->pc = 0x801D93C8u;
    // 801D93C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D93CC:
    ctx->pc = 0x801D93CCu;
    ctx->downcount -= 29;
    // 801D93CC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D93D0:
    ctx->pc = 0x801D93D0u;
    // 801D93D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D93D4:
    ctx->pc = 0x801D93D4u;
    // 801D93D4: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D93D8:
    ctx->pc = 0x801D93D8u;
    // 801D93D8: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D93DC:
    ctx->pc = 0x801D93DCu;
    // 801D93DC: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D93E0:
    ctx->pc = 0x801D93E0u;
    // 801D93E0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D93E4:
    ctx->pc = 0x801D93E4u;
    // 801D93E4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D93E8:
    ctx->pc = 0x801D93E8u;
    // 801D93E8: mulli   r4, r29, 172
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)172);

label_801D93EC:
    ctx->pc = 0x801D93ECu;
    // 801D93EC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D93F0:
    ctx->pc = 0x801D93F0u;
    // 801D93F0: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D93F4:
    ctx->pc = 0x801D93F4u;
    // 801D93F4: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D93F8:
    ctx->pc = 0x801D93F8u;
    // 801D93F8: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D93FC:
    ctx->pc = 0x801D93FCu;
    // 801D93FC: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9400:
    ctx->pc = 0x801D9400u;
    // 801D9400: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D9404:
    ctx->pc = 0x801D9404u;
    // 801D9404: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9408:
    ctx->pc = 0x801D9408u;
    // 801D9408: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D940C:
    ctx->pc = 0x801D940Cu;
    // 801D940C: bl      0x80039640
    {
            ctx->lr = 0x801D9410u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D9410:
    ctx->pc = 0x801D9410u;
    ctx->downcount -= 4;
    // 801D9410: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9414:
    ctx->pc = 0x801D9414u;
    // 801D9414: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D9418:
    ctx->pc = 0x801D9418u;
    // 801D9418: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D941C:
    ctx->pc = 0x801D941Cu;
    // 801D941C: bl      0x801D9358
    {
            ctx->lr = 0x801D9420u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9358u;
                return;
            }
            goto label_801D9358;
    }

label_801D9420:
    ctx->pc = 0x801D9420u;
    ctx->downcount -= 16;
    // 801D9420: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9424:
    ctx->pc = 0x801D9424u;
    // 801D9424: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9428:
    ctx->pc = 0x801D9428u;
    // 801D9428: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D942C:
    ctx->pc = 0x801D942Cu;
    // 801D942C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D9430:
    ctx->pc = 0x801D9430u;
    // 801D9430: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9434:
    ctx->pc = 0x801D9434u;
    ctx->downcount -= 16;
    // 801D9434: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9438:
    ctx->pc = 0x801D9438u;
    // 801D9438: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D943C:
    ctx->pc = 0x801D943Cu;
    // 801D943C: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9440:
    ctx->pc = 0x801D9440u;
    // 801D9440: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9444:
    ctx->pc = 0x801D9444u;
    // 801D9444: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9448:
    ctx->pc = 0x801D9448u;
    // 801D9448: bl      0x801D93CC
    {
            ctx->lr = 0x801D944Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D93CCu;
                return;
            }
            goto label_801D93CC;
    }

label_801D944C:
    ctx->pc = 0x801D944Cu;
    ctx->downcount -= 5;
    // 801D944C: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801D9450:
    ctx->pc = 0x801D9450u;
    // 801D9450: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D9454:
    ctx->pc = 0x801D9454u;
    // 801D9454: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D9458:
    ctx->pc = 0x801D9458u;
    // 801D9458: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D945C:
    loop_801D945C(ctx);
    if (ctx->pc == 0x801D9470u) goto label_801D9470;
    return;
label_801D9460:
    ctx->pc = 0x801D9460u;
    // 801D9460: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9464:
    ctx->pc = 0x801D9464u;
    // 801D9464: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9468:
    // 801D9468: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D946C:
    // 801D946C: bc    16, 0, 0x801D945C
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D945Cu;
                return;
            }
            goto label_801D945C;
        }
    }

label_801D9470:
    ctx->pc = 0x801D9470u;
    ctx->downcount -= 16;
    // 801D9470: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9474:
    ctx->pc = 0x801D9474u;
    // 801D9474: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9478:
    ctx->pc = 0x801D9478u;
    // 801D9478: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D947C:
    ctx->pc = 0x801D947Cu;
    // 801D947C: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D9480:
    ctx->pc = 0x801D9480u;
    // 801D9480: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9484:
    ctx->pc = 0x801D9484u;
    ctx->downcount -= 4;
    // 801D9484: lwz     r9, 160(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(160);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D9488:
    ctx->pc = 0x801D9488u;
    // 801D9488: lwz     r10, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_801D948C:
    ctx->pc = 0x801D948Cu;
    // 801D948C: cmpwi   r9, 0
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

label_801D9490:
    ctx->pc = 0x801D9490u;
    // 801D9490: bc    12, 2, 0x801D949C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D949C;
        }
    }

label_801D9494:
    ctx->pc = 0x801D9494u;
    ctx->downcount -= 2;
    // 801D9494: stw     r10, 156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D9498:
    ctx->pc = 0x801D9498u;
    // 801D9498: b       0x801D94A4
    {
            goto label_801D94A4;
    }

label_801D949C:
    ctx->pc = 0x801D949Cu;
    ctx->downcount -= 2;
    // 801D949C: lwz     r9, 168(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(168);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D94A0:
    ctx->pc = 0x801D94A0u;
    // 801D94A0: stw     r10, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_801D94A4:
    ctx->pc = 0x801D94A4u;
    ctx->downcount -= 3;
    // 801D94A4: lwz     r9, 156(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(156);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D94A8:
    ctx->pc = 0x801D94A8u;
    // 801D94A8: cmpwi   r9, 0
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

label_801D94AC:
    ctx->pc = 0x801D94ACu;
    // 801D94AC: bc    12, 2, 0x801D94BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D94BC;
        }
    }

label_801D94B0:
    ctx->pc = 0x801D94B0u;
    ctx->downcount -= 3;
    // 801D94B0: lwz     r0, 160(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(160);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D94B4:
    ctx->pc = 0x801D94B4u;
    // 801D94B4: stw     r0, 160(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D94B8:
    ctx->pc = 0x801D94B8u;
    // 801D94B8: b       0x801D94C8
    {
            goto label_801D94C8;
    }

label_801D94BC:
    ctx->pc = 0x801D94BCu;
    ctx->downcount -= 3;
    // 801D94BC: lwz     r9, 168(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(168);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D94C0:
    ctx->pc = 0x801D94C0u;
    // 801D94C0: lwz     r0, 160(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(160);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D94C4:
    ctx->pc = 0x801D94C4u;
    // 801D94C4: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D94C8:
    ctx->pc = 0x801D94C8u;
    ctx->downcount -= 6;
    // 801D94C8: lwz     r11, 168(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(168);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801D94CC:
    ctx->pc = 0x801D94CCu;
    // 801D94CC: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_801D94D0:
    ctx->pc = 0x801D94D0u;
    // 801D94D0: lwz     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_801D94D4:
    ctx->pc = 0x801D94D4u;
    // 801D94D4: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_801D94D8:
    ctx->pc = 0x801D94D8u;
    // 801D94D8: stw     r9, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_801D94DC:
    ctx->pc = 0x801D94DCu;
    // 801D94DC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D94E0:
    ctx->pc = 0x801D94E0u;
    ctx->downcount -= 18;
    // 801D94E0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D94E4:
    ctx->pc = 0x801D94E4u;
    // 801D94E4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D94E8:
    ctx->pc = 0x801D94E8u;
    // 801D94E8: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D94EC:
    ctx->pc = 0x801D94ECu;
    // 801D94EC: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D94F0:
    ctx->pc = 0x801D94F0u;
    // 801D94F0: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D94F4:
    ctx->pc = 0x801D94F4u;
    // 801D94F4: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D94F8:
    ctx->pc = 0x801D94F8u;
    // 801D94F8: cmpwi   r31, 0
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

label_801D94FC:
    ctx->pc = 0x801D94FCu;
    // 801D94FC: bc    12, 2, 0x801D9520
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D9520;
        }
    }

label_801D9500:
    ctx->downcount -= 2;
    // 801D9500: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D9504:
    // 801D9504: bl      0x801D9484
    {
            ctx->lr = 0x801D9508u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9484u;
                return;
            }
            goto label_801D9484;
    }

label_801D9508:
    ctx->downcount -= 4;
    // 801D9508: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D950C:
    // 801D950C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D9510:
    // 801D9510: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D9514:
    // 801D9514: bl      0x801D9310
    {
            ctx->lr = 0x801D9518u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9310u;
                return;
            }
            goto label_801D9310;
    }

label_801D9518:
    ctx->downcount -= 2;
    // 801D9518: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D951C:
    // 801D951C: bc    4, 2, 0x801D9500
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9500u;
                return;
            }
            goto label_801D9500;
        }
    }

label_801D9520:
    ctx->pc = 0x801D9520u;
    ctx->downcount -= 16;
    // 801D9520: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9524:
    ctx->pc = 0x801D9524u;
    // 801D9524: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9528:
    ctx->pc = 0x801D9528u;
    // 801D9528: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D952C:
    ctx->pc = 0x801D952Cu;
    // 801D952C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D9530:
    ctx->pc = 0x801D9530u;
    // 801D9530: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9534:
    ctx->pc = 0x801D9534u;
    ctx->downcount -= 17;
    // 801D9534: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9538:
    ctx->pc = 0x801D9538u;
    // 801D9538: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D953C:
    ctx->pc = 0x801D953Cu;
    // 801D953C: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9540:
    ctx->pc = 0x801D9540u;
    // 801D9540: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9544:
    ctx->pc = 0x801D9544u;
    // 801D9544: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9548:
    ctx->pc = 0x801D9548u;
    // 801D9548: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_801D954C:
    ctx->pc = 0x801D954Cu;
    // 801D954C: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_801D9550:
    ctx->downcount -= 3;
    // 801D9550: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D9554:
    // 801D9554: addi    r4, r30, 8
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(8);

label_801D9558:
    // 801D9558: bl      0x801D94E0
    {
            ctx->lr = 0x801D955Cu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D94E0u;
                return;
            }
            goto label_801D94E0;
    }

label_801D955C:
    ctx->downcount -= 3;
    // 801D955C: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801D9560:
    // 801D9560: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D9564:
    // 801D9564: bc    4, 2, 0x801D9550
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9550u;
                return;
            }
            goto label_801D9550;
        }
    }

label_801D9568:
    ctx->pc = 0x801D9568u;
    ctx->downcount -= 16;
    // 801D9568: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D956C:
    ctx->pc = 0x801D956Cu;
    // 801D956C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9570:
    ctx->pc = 0x801D9570u;
    // 801D9570: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D9574:
    ctx->pc = 0x801D9574u;
    // 801D9574: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D9578:
    ctx->pc = 0x801D9578u;
    // 801D9578: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D957C:
    ctx->pc = 0x801D957Cu;
    ctx->downcount -= 21;
    // 801D957C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9580:
    ctx->pc = 0x801D9580u;
    // 801D9580: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9584:
    ctx->pc = 0x801D9584u;
    // 801D9584: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_801D9588:
    ctx->pc = 0x801D9588u;
    // 801D9588: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D958C:
    ctx->pc = 0x801D958Cu;
    // 801D958C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9590:
    ctx->pc = 0x801D9590u;
    // 801D9590: stw     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_801D9594:
    ctx->pc = 0x801D9594u;
    // 801D9594: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9598:
    ctx->pc = 0x801D9598u;
    // 801D9598: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D959C:
    ctx->pc = 0x801D959Cu;
    // 801D959C: lwz     r31, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D95A0:
    ctx->pc = 0x801D95A0u;
    // 801D95A0: cmpwi   cr4, r31, 0
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(0);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_801D95A4:
    ctx->pc = 0x801D95A4u;
    // 801D95A4: bc    12, 18, 0x801D95DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D95DC;
        }
    }

label_801D95A8:
    ctx->pc = 0x801D95A8u;
    ctx->downcount -= 2;
    // 801D95A8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D95AC:
    ctx->pc = 0x801D95ACu;
    // 801D95AC: bl      0x801D9484
    {
            ctx->lr = 0x801D95B0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9484u;
                return;
            }
            goto label_801D9484;
    }

label_801D95B0:
    ctx->pc = 0x801D95B0u;
    ctx->downcount -= 6;
    // 801D95B0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D95B4:
    ctx->pc = 0x801D95B4u;
    // 801D95B4: stw     r0, 168(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(168);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D95B8:
    ctx->pc = 0x801D95B8u;
    // 801D95B8: stw     r0, 156(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D95BC:
    ctx->pc = 0x801D95BCu;
    // 801D95BC: stw     r0, 160(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D95C0:
    ctx->pc = 0x801D95C0u;
    // 801D95C0: stw     r0, 164(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D95C4:
    ctx->pc = 0x801D95C4u;
    // 801D95C4: bc    12, 18, 0x801D95DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D95DC;
        }
    }

label_801D95C8:
    ctx->pc = 0x801D95C8u;
    ctx->downcount -= 7;
    // 801D95C8: mulli   r3, r29, 12
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)12);

label_801D95CC:
    ctx->pc = 0x801D95CCu;
    // 801D95CC: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D95D0:
    ctx->pc = 0x801D95D0u;
    // 801D95D0: addi    r3, r3, 20
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(20);

label_801D95D4:
    ctx->pc = 0x801D95D4u;
    // 801D95D4: add   r3, r30, r3
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_801D95D8:
    ctx->pc = 0x801D95D8u;
    // 801D95D8: bl      0x801D9310
    {
            ctx->lr = 0x801D95DCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9310u;
                return;
            }
            goto label_801D9310;
    }

label_801D95DC:
    ctx->pc = 0x801D95DCu;
    ctx->downcount -= 19;
    // 801D95DC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D95E0:
    ctx->pc = 0x801D95E0u;
    // 801D95E0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D95E4:
    ctx->pc = 0x801D95E4u;
    // 801D95E4: lwz     r12, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801D95E8:
    ctx->pc = 0x801D95E8u;
    // 801D95E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D95EC:
    ctx->pc = 0x801D95ECu;
    // 801D95EC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D95F0:
    ctx->pc = 0x801D95F0u;
    // 801D95F0: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_801D95F4:
    ctx->pc = 0x801D95F4u;
    // 801D95F4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D95F8:
    ctx->pc = 0x801D95F8u;
    // 801D95F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D95FC:
    ctx->pc = 0x801D95FCu;
    ctx->downcount -= 20;
    // 801D95FC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9600:
    ctx->pc = 0x801D9600u;
    // 801D9600: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9604:
    ctx->pc = 0x801D9604u;
    // 801D9604: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9608:
    ctx->pc = 0x801D9608u;
    // 801D9608: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D960C:
    ctx->pc = 0x801D960Cu;
    // 801D960C: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9610:
    ctx->pc = 0x801D9610u;
    // 801D9610: or   r30, r5, r5
    {
        ctx->gpr[30] = ctx->gpr[5] | ctx->gpr[5];
    }

label_801D9614:
    ctx->pc = 0x801D9614u;
    // 801D9614: stw     r4, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801D9618:
    ctx->pc = 0x801D9618u;
    // 801D9618: cmpwi   r4, 0
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

label_801D961C:
    ctx->pc = 0x801D961Cu;
    // 801D961C: stw     r30, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801D9620:
    ctx->pc = 0x801D9620u;
    // 801D9620: bc    12, 2, 0x801D965C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D965C;
        }
    }

label_801D9624:
    ctx->pc = 0x801D9624u;
    ctx->downcount -= 3;
    // 801D9624: or   r31, r4, r4
    {
        ctx->gpr[31] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D9628:
    ctx->pc = 0x801D9628u;
    // 801D9628: cmpwi   r30, 0
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

label_801D962C:
    ctx->pc = 0x801D962Cu;
    // 801D962C: bc    12, 2, 0x801D965C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D965C;
        }
    }

label_801D9630:
    ctx->pc = 0x801D9630u;
    ctx->downcount -= 1;
    // 801D9630: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_801D9634:
    ctx->pc = 0x801D9634u;
    ctx->downcount -= 8;
    // 801D9634: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D9638:
    // 801D9638: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D963C:
    ctx->pc = 0x801D963Cu;
    // 801D963C: stw     r29, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D9640:
    // 801D9640: addi    r3, r28, 8
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(8);

label_801D9644:
    ctx->pc = 0x801D9644u;
    // 801D9644: stw     r29, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D9648:
    ctx->pc = 0x801D9648u;
    // 801D9648: stw     r29, 32(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801D964C:
    // 801D964C: addi    r31, r31, 36
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(36);

label_801D9650:
    // 801D9650: bl      0x801D7AEC
    {
            ctx->lr = 0x801D9654u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7AECu;
                return;
            }
            goto label_801D7AEC;
    }

label_801D9654:
    ctx->downcount -= 2;
    // 801D9654: addic.  r30, r30, -1
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

label_801D9658:
    // 801D9658: bc    4, 2, 0x801D9634
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9634u;
                return;
            }
            goto label_801D9634;
        }
    }

label_801D965C:
    ctx->pc = 0x801D965Cu;
    ctx->downcount -= 16;
    // 801D965C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9660:
    ctx->pc = 0x801D9660u;
    // 801D9660: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9664:
    ctx->pc = 0x801D9664u;
    // 801D9664: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D9668:
    ctx->pc = 0x801D9668u;
    // 801D9668: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D966C:
    ctx->pc = 0x801D966Cu;
    // 801D966C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9670:
    ctx->pc = 0x801D9670u;
    ctx->downcount -= 29;
    // 801D9670: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9674:
    ctx->pc = 0x801D9674u;
    // 801D9674: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9678:
    ctx->pc = 0x801D9678u;
    // 801D9678: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D967C:
    ctx->pc = 0x801D967Cu;
    // 801D967C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9680:
    ctx->pc = 0x801D9680u;
    // 801D9680: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D9684:
    ctx->pc = 0x801D9684u;
    // 801D9684: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9688:
    ctx->pc = 0x801D9688u;
    // 801D9688: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D968C:
    ctx->pc = 0x801D968Cu;
    // 801D968C: mulli   r4, r29, 36
    ctx->gpr[4] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)36);

label_801D9690:
    ctx->pc = 0x801D9690u;
    // 801D9690: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9694:
    ctx->pc = 0x801D9694u;
    // 801D9694: addi    r9, r30, 8
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(8);

label_801D9698:
    ctx->pc = 0x801D9698u;
    // 801D9698: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D969C:
    ctx->pc = 0x801D969Cu;
    // 801D969C: or   r3, r7, r7
    {
        ctx->gpr[3] = ctx->gpr[7] | ctx->gpr[7];
    }

label_801D96A0:
    ctx->pc = 0x801D96A0u;
    // 801D96A0: stw     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D96A4:
    ctx->pc = 0x801D96A4u;
    // 801D96A4: li      r7, 4
    ctx->gpr[7] = (u32)(s32)(4);

label_801D96A8:
    ctx->pc = 0x801D96A8u;
    // 801D96A8: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D96AC:
    ctx->pc = 0x801D96ACu;
    // 801D96AC: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D96B0:
    ctx->pc = 0x801D96B0u;
    // 801D96B0: bl      0x80039640
    {
            ctx->lr = 0x801D96B4u;
            ctx->pc = 0x80039640u;
            return;
    }

label_801D96B4:
    ctx->pc = 0x801D96B4u;
    ctx->downcount -= 4;
    // 801D96B4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D96B8:
    ctx->pc = 0x801D96B8u;
    // 801D96B8: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D96BC:
    ctx->pc = 0x801D96BCu;
    // 801D96BC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801D96C0:
    ctx->pc = 0x801D96C0u;
    // 801D96C0: bl      0x801D95FC
    {
            ctx->lr = 0x801D96C4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D95FCu;
                return;
            }
            goto label_801D95FC;
    }

label_801D96C4:
    ctx->pc = 0x801D96C4u;
    ctx->downcount -= 16;
    // 801D96C4: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D96C8:
    ctx->pc = 0x801D96C8u;
    // 801D96C8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D96CC:
    ctx->pc = 0x801D96CCu;
    // 801D96CC: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D96D0:
    ctx->pc = 0x801D96D0u;
    // 801D96D0: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D96D4:
    ctx->pc = 0x801D96D4u;
    // 801D96D4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D96D8:
    ctx->pc = 0x801D96D8u;
    ctx->downcount -= 16;
    // 801D96D8: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D96DC:
    ctx->pc = 0x801D96DCu;
    // 801D96DC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D96E0:
    ctx->pc = 0x801D96E0u;
    // 801D96E0: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D96E4:
    ctx->pc = 0x801D96E4u;
    // 801D96E4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D96E8:
    ctx->pc = 0x801D96E8u;
    // 801D96E8: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D96EC:
    ctx->pc = 0x801D96ECu;
    // 801D96EC: bl      0x801D9670
    {
            ctx->lr = 0x801D96F0u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9670u;
                return;
            }
            goto label_801D9670;
    }

label_801D96F0:
    ctx->pc = 0x801D96F0u;
    ctx->downcount -= 5;
    // 801D96F0: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801D96F4:
    ctx->pc = 0x801D96F4u;
    // 801D96F4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801D96F8:
    ctx->pc = 0x801D96F8u;
    // 801D96F8: mtctr    r9
    ctx->ctr = ctx->gpr[9];

label_801D96FC:
    ctx->pc = 0x801D96FCu;
    // 801D96FC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_801D9700:
    loop_801D9700(ctx);
    if (ctx->pc == 0x801D9714u) goto label_801D9714;
    return;
label_801D9704:
    ctx->pc = 0x801D9704u;
    // 801D9704: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9708:
    ctx->pc = 0x801D9708u;
    // 801D9708: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D970C:
    // 801D970C: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_801D9710:
    // 801D9710: bc    16, 0, 0x801D9700
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9700u;
                return;
            }
            goto label_801D9700;
        }
    }

label_801D9714:
    ctx->pc = 0x801D9714u;
    ctx->downcount -= 16;
    // 801D9714: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D9718:
    ctx->pc = 0x801D9718u;
    // 801D9718: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D971C:
    ctx->pc = 0x801D971Cu;
    // 801D971C: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D9720:
    ctx->pc = 0x801D9720u;
    // 801D9720: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_801D9724:
    ctx->pc = 0x801D9724u;
    // 801D9724: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D9728:
    ctx->pc = 0x801D9728u;
    ctx->downcount -= 18;
    // 801D9728: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D972C:
    ctx->pc = 0x801D972Cu;
    // 801D972C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9730:
    ctx->pc = 0x801D9730u;
    // 801D9730: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9734:
    ctx->pc = 0x801D9734u;
    // 801D9734: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D9738:
    ctx->pc = 0x801D9738u;
    // 801D9738: lwz     r31, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801D973C:
    ctx->pc = 0x801D973Cu;
    // 801D973C: or   r29, r4, r4
    {
        ctx->gpr[29] = ctx->gpr[4] | ctx->gpr[4];
    }

label_801D9740:
    ctx->pc = 0x801D9740u;
    // 801D9740: cmpwi   r31, 0
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

label_801D9744:
    ctx->pc = 0x801D9744u;
    // 801D9744: bc    12, 2, 0x801D9768
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801D9768;
        }
    }

label_801D9748:
    ctx->downcount -= 2;
    // 801D9748: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D974C:
    // 801D974C: bl      0x801D79C8
    {
            ctx->lr = 0x801D9750u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D79C8u;
                return;
            }
            goto label_801D79C8;
    }

label_801D9750:
    ctx->downcount -= 4;
    // 801D9750: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9754:
    // 801D9754: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D9758:
    // 801D9758: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_801D975C:
    // 801D975C: bl      0x801D7AEC
    {
            ctx->lr = 0x801D9760u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D7AECu;
                return;
            }
            goto label_801D7AEC;
    }

label_801D9760:
    ctx->downcount -= 2;
    // 801D9760: or.   r31, r30, r30
    {
        ctx->gpr[31] = ctx->gpr[30] | ctx->gpr[30];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[31];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D9764:
    // 801D9764: bc    4, 2, 0x801D9748
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9748u;
                return;
            }
            goto label_801D9748;
        }
    }

label_801D9768:
    ctx->pc = 0x801D9768u;
    ctx->downcount -= 16;
    // 801D9768: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D976C:
    ctx->pc = 0x801D976Cu;
    // 801D976C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D9770:
    ctx->pc = 0x801D9770u;
    // 801D9770: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D9774:
    ctx->pc = 0x801D9774u;
    // 801D9774: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D9778:
    ctx->pc = 0x801D9778u;
    // 801D9778: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D977C:
    ctx->pc = 0x801D977Cu;
    ctx->downcount -= 17;
    // 801D977C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801D9780:
    ctx->pc = 0x801D9780u;
    // 801D9780: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801D9784:
    ctx->pc = 0x801D9784u;
    // 801D9784: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_801D9788:
    ctx->pc = 0x801D9788u;
    // 801D9788: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801D978C:
    ctx->pc = 0x801D978Cu;
    // 801D978C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801D9790:
    ctx->pc = 0x801D9790u;
    // 801D9790: li      r29, 1
    ctx->gpr[29] = (u32)(s32)(1);

label_801D9794:
    ctx->pc = 0x801D9794u;
    // 801D9794: addi    r31, r30, 20
    ctx->gpr[31] = ctx->gpr[30] + (u32)(s32)(20);

label_801D9798:
    ctx->downcount -= 3;
    // 801D9798: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801D979C:
    // 801D979C: addi    r4, r30, 8
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(8);

label_801D97A0:
    // 801D97A0: bl      0x801D9728
    {
            ctx->lr = 0x801D97A4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9728u;
                return;
            }
            goto label_801D9728;
    }

label_801D97A4:
    ctx->downcount -= 3;
    // 801D97A4: addi    r31, r31, 12
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(12);

label_801D97A8:
    // 801D97A8: addic.  r29, r29, -1
    {
        u64 a = ctx->gpr[29];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[29] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[29];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801D97AC:
    // 801D97AC: bc    4, 2, 0x801D9798
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801D9798u;
                return;
            }
            goto label_801D9798;
        }
    }

label_801D97B0:
    ctx->pc = 0x801D97B0u;
    ctx->downcount -= 16;
    // 801D97B0: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801D97B4:
    ctx->pc = 0x801D97B4u;
    // 801D97B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801D97B8:
    ctx->pc = 0x801D97B8u;
    // 801D97B8: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_801D97BC:
    ctx->pc = 0x801D97BCu;
    // 801D97BC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801D97C0:
    ctx->pc = 0x801D97C0u;
    // 801D97C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801D72C0;
        }
    }

label_801D97C4:
    ctx->pc = 0x801D97C4u;
    // 801D97C4: .long   0x00000000
    // embedded data

label_801D97C8:
    ctx->pc = 0x801D97C8u;
    // 801D97C8: .long   0x00000000
    // embedded data

label_801D97CC:
    ctx->pc = 0x801D97CCu;
    // 801D97CC: .long   0x00000000
    // embedded data

label_801D97D0:
    ctx->pc = 0x801D97D0u;
    // 801D97D0: .long   0x00000000
    // embedded data

label_801D97D4:
    ctx->pc = 0x801D97D4u;
    // 801D97D4: .long   0x00000000
    // embedded data

label_801D97D8:
    ctx->pc = 0x801D97D8u;
    // 801D97D8: .long   0x00000000
    // embedded data

label_801D97DC:
    ctx->pc = 0x801D97DCu;
    // 801D97DC: .long   0x00000000
    // embedded data

    ctx->pc = 0x801D97E0u;
    return;
return_dispatch_801D72C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x801D7350u: goto label_801D7350;
    case 0x801D73B0u: goto label_801D73B0;
    case 0x801D73C0u: goto label_801D73C0;
    case 0x801D73ECu: goto label_801D73EC;
    case 0x801D74B4u: goto label_801D74B4;
    case 0x801D74E0u: goto label_801D74E0;
    case 0x801D7644u: goto label_801D7644;
    case 0x801D76A4u: goto label_801D76A4;
    case 0x801D76B4u: goto label_801D76B4;
    case 0x801D7768u: goto label_801D7768;
    case 0x801D77C8u: goto label_801D77C8;
    case 0x801D77D8u: goto label_801D77D8;
    case 0x801D788Cu: goto label_801D788C;
    case 0x801D78ECu: goto label_801D78EC;
    case 0x801D78FCu: goto label_801D78FC;
    case 0x801D7AA0u: goto label_801D7AA0;
    case 0x801D7ACCu: goto label_801D7ACC;
    case 0x801D7B50u: goto label_801D7B50;
    case 0x801D7C2Cu: goto label_801D7C2C;
    case 0x801D7C88u: goto label_801D7C88;
    case 0x801D7CA8u: goto label_801D7CA8;
    case 0x801D7CD4u: goto label_801D7CD4;
    case 0x801D7DB0u: goto label_801D7DB0;
    case 0x801D7E18u: goto label_801D7E18;
    case 0x801D7E28u: goto label_801D7E28;
    case 0x801D7E54u: goto label_801D7E54;
    case 0x801D7F10u: goto label_801D7F10;
    case 0x801D7F20u: goto label_801D7F20;
    case 0x801D7F64u: goto label_801D7F64;
    case 0x801D8000u: goto label_801D8000;
    case 0x801D802Cu: goto label_801D802C;
    case 0x801D8130u: goto label_801D8130;
    case 0x801D815Cu: goto label_801D815C;
    case 0x801D8270u: goto label_801D8270;
    case 0x801D82D0u: goto label_801D82D0;
    case 0x801D82E0u: goto label_801D82E0;
    case 0x801D830Cu: goto label_801D830C;
    case 0x801D836Cu: goto label_801D836C;
    case 0x801D837Cu: goto label_801D837C;
    case 0x801D83C0u: goto label_801D83C0;
    case 0x801D8484u: goto label_801D8484;
    case 0x801D848Cu: goto label_801D848C;
    case 0x801D84CCu: goto label_801D84CC;
    case 0x801D84E0u: goto label_801D84E0;
    case 0x801D85C8u: goto label_801D85C8;
    case 0x801D85F4u: goto label_801D85F4;
    case 0x801D86E0u: goto label_801D86E0;
    case 0x801D86F0u: goto label_801D86F0;
    case 0x801D8734u: goto label_801D8734;
    case 0x801D87ACu: goto label_801D87AC;
    case 0x801D880Cu: goto label_801D880C;
    case 0x801D881Cu: goto label_801D881C;
    case 0x801D8848u: goto label_801D8848;
    case 0x801D88B4u: goto label_801D88B4;
    case 0x801D88E0u: goto label_801D88E0;
    case 0x801D8930u: goto label_801D8930;
    case 0x801D8980u: goto label_801D8980;
    case 0x801D89ACu: goto label_801D89AC;
    case 0x801D8A98u: goto label_801D8A98;
    case 0x801D8AF4u: goto label_801D8AF4;
    case 0x801D8B14u: goto label_801D8B14;
    case 0x801D8B40u: goto label_801D8B40;
    case 0x801D8BACu: goto label_801D8BAC;
    case 0x801D8C68u: goto label_801D8C68;
    case 0x801D8CC8u: goto label_801D8CC8;
    case 0x801D8CD8u: goto label_801D8CD8;
    case 0x801D8D04u: goto label_801D8D04;
    case 0x801D8DC0u: goto label_801D8DC0;
    case 0x801D8DD0u: goto label_801D8DD0;
    case 0x801D8E14u: goto label_801D8E14;
    case 0x801D8E68u: goto label_801D8E68;
    case 0x801D8E94u: goto label_801D8E94;
    case 0x801D8F8Cu: goto label_801D8F8C;
    case 0x801D8FB8u: goto label_801D8FB8;
    case 0x801D9078u: goto label_801D9078;
    case 0x801D90D8u: goto label_801D90D8;
    case 0x801D90E8u: goto label_801D90E8;
    case 0x801D9114u: goto label_801D9114;
    case 0x801D917Cu: goto label_801D917C;
    case 0x801D91C0u: goto label_801D91C0;
    case 0x801D91D0u: goto label_801D91D0;
    case 0x801D9214u: goto label_801D9214;
    case 0x801D92ACu: goto label_801D92AC;
    case 0x801D92C8u: goto label_801D92C8;
    case 0x801D92E4u: goto label_801D92E4;
    case 0x801D92FCu: goto label_801D92FC;
    case 0x801D93B0u: goto label_801D93B0;
    case 0x801D9410u: goto label_801D9410;
    case 0x801D9420u: goto label_801D9420;
    case 0x801D944Cu: goto label_801D944C;
    case 0x801D9508u: goto label_801D9508;
    case 0x801D9518u: goto label_801D9518;
    case 0x801D955Cu: goto label_801D955C;
    case 0x801D95B0u: goto label_801D95B0;
    case 0x801D95DCu: goto label_801D95DC;
    case 0x801D9654u: goto label_801D9654;
    case 0x801D96B4u: goto label_801D96B4;
    case 0x801D96C4u: goto label_801D96C4;
    case 0x801D96F0u: goto label_801D96F0;
    case 0x801D9750u: goto label_801D9750;
    case 0x801D9760u: goto label_801D9760;
    case 0x801D97A4u: goto label_801D97A4;
    default: return;
    }
}

