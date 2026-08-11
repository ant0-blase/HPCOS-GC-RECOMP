// DolRecomp output
#include "../generated.h"

static void loop_80197360(CPUState* ctx) {
label_80197360:
    ctx->downcount -= 5;
    ctx->pc = 0x80197360u;
    // 80197360: lwzu     r3, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

    ctx->pc = 0x80197364u;
    // 80197364: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    ctx->pc = 0x80197368u;
    // 80197368: stwu     r3, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
        ctx->gpr[5] = ea;
    }

    ctx->pc = 0x8019736Cu;
    // 8019736C: stw     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

    // 80197370: bc    16, 0, 0x80197360
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197360u;
                return;
            }
            goto label_80197360;
        }
    }

    ctx->pc = 0x80197374u;
}

static void loop_80197634(CPUState* ctx) {
label_80197634:
    ctx->downcount -= 2;
    ctx->pc = 0x80197634u;
    // 80197634: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

    // 80197638: bc    16, 0, 0x80197634
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197634u;
                return;
            }
            goto label_80197634;
        }
    }

    ctx->pc = 0x8019763Cu;
}

static void loop_80199E34(CPUState* ctx) {
label_80199E34:
    ctx->downcount -= 9;
    ctx->pc = 0x80199E34u;
    // 80199E34: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80199E38u;
    // 80199E38: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80199E3Cu;
    // 80199E3C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80199E40u;
    // 80199E40: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80199E44u;
    // 80199E44: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80199E48u;
    // 80199E48: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80199E4Cu;
    // 80199E4C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    ctx->pc = 0x80199E50u;
    // 80199E50: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    // 80199E54: bc    16, 0, 0x80199E34
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80199E34u;
                return;
            }
            goto label_80199E34;
        }
    }

    ctx->pc = 0x80199E58u;
}

static void loop_80199E64(CPUState* ctx) {
label_80199E64:
    ctx->downcount -= 2;
    ctx->pc = 0x80199E64u;
    // 80199E64: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

    // 80199E68: bc    16, 0, 0x80199E64
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80199E64u;
                return;
            }
            goto label_80199E64;
        }
    }

    ctx->pc = 0x80199E6Cu;
}

static void loop_8019A5EC(CPUState* ctx) {
label_8019A5EC:
    ctx->downcount -= 1;
    // 8019A5EC: rlwinm r4, r4, 31, 1, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFFu;
    }

    // 8019A5F0: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8019A5F4: bc    12, 2, 0x8019A5EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A5ECu;
                return;
            }
            goto label_8019A5EC;
        }
    }

    ctx->pc = 0x8019A5F8u;
}

static void loop_8019A66C(CPUState* ctx) {
label_8019A66C:
    ctx->downcount -= 1;
    // 8019A66C: rlwinm r4, r4, 31, 1, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFFu;
    }

    // 8019A670: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8019A674: bc    12, 2, 0x8019A66C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A66Cu;
                return;
            }
            goto label_8019A66C;
        }
    }

    ctx->pc = 0x8019A678u;
}

static void loop_8019A744(CPUState* ctx) {
label_8019A744:
    ctx->downcount -= 1;
    // 8019A744: rlwinm r4, r4, 31, 1, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFFu;
    }

    // 8019A748: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8019A74C: bc    12, 2, 0x8019A744
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A744u;
                return;
            }
            goto label_8019A744;
        }
    }

    ctx->pc = 0x8019A750u;
}

static void loop_8019A7E0(CPUState* ctx) {
label_8019A7E0:
    ctx->downcount -= 1;
    // 8019A7E0: rlwinm r4, r4, 31, 1, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFFu;
    }

    // 8019A7E4: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8019A7E8: bc    12, 2, 0x8019A7E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A7E0u;
                return;
            }
            goto label_8019A7E0;
        }
    }

    ctx->pc = 0x8019A7ECu;
}

static void loop_8019A888(CPUState* ctx) {
label_8019A888:
    ctx->downcount -= 1;
    // 8019A888: rlwinm r4, r4, 31, 1, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFFu;
    }

    // 8019A88C: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8019A890: bc    12, 2, 0x8019A888
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A888u;
                return;
            }
            goto label_8019A888;
        }
    }

    ctx->pc = 0x8019A894u;
}

static void loop_8019A980(CPUState* ctx) {
label_8019A980:
    ctx->downcount -= 1;
    // 8019A980: rlwinm r4, r4, 31, 1, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 31u) & 0x7FFFFFFFu;
    }

    // 8019A984: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

    // 8019A988: bc    12, 2, 0x8019A980
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A980u;
                return;
            }
            goto label_8019A980;
        }
    }

    ctx->pc = 0x8019A98Cu;
}

void func_801972C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x801972C0u: goto label_801972C0;
    case 0x801972C4u: goto label_801972C4;
    case 0x801972C8u: goto label_801972C8;
    case 0x801972CCu: goto label_801972CC;
    case 0x801972D0u: goto label_801972D0;
    case 0x801972D4u: goto label_801972D4;
    case 0x801972D8u: goto label_801972D8;
    case 0x801972DCu: goto label_801972DC;
    case 0x801972E0u: goto label_801972E0;
    case 0x801972E4u: goto label_801972E4;
    case 0x801972E8u: goto label_801972E8;
    case 0x801972ECu: goto label_801972EC;
    case 0x801972F0u: goto label_801972F0;
    case 0x801972F4u: goto label_801972F4;
    case 0x801972F8u: goto label_801972F8;
    case 0x801972FCu: goto label_801972FC;
    case 0x80197300u: goto label_80197300;
    case 0x80197304u: goto label_80197304;
    case 0x80197308u: goto label_80197308;
    case 0x8019730Cu: goto label_8019730C;
    case 0x80197310u: goto label_80197310;
    case 0x80197314u: goto label_80197314;
    case 0x80197318u: goto label_80197318;
    case 0x8019731Cu: goto label_8019731C;
    case 0x80197320u: goto label_80197320;
    case 0x80197324u: goto label_80197324;
    case 0x80197328u: goto label_80197328;
    case 0x8019732Cu: goto label_8019732C;
    case 0x80197330u: goto label_80197330;
    case 0x80197334u: goto label_80197334;
    case 0x80197338u: goto label_80197338;
    case 0x8019733Cu: goto label_8019733C;
    case 0x80197340u: goto label_80197340;
    case 0x80197344u: goto label_80197344;
    case 0x80197348u: goto label_80197348;
    case 0x8019734Cu: goto label_8019734C;
    case 0x80197350u: goto label_80197350;
    case 0x80197354u: goto label_80197354;
    case 0x80197358u: goto label_80197358;
    case 0x8019735Cu: goto label_8019735C;
    case 0x80197360u: goto label_80197360;
    case 0x80197364u: goto label_80197364;
    case 0x80197368u: goto label_80197368;
    case 0x8019736Cu: goto label_8019736C;
    case 0x80197370u: goto label_80197370;
    case 0x80197374u: goto label_80197374;
    case 0x80197378u: goto label_80197378;
    case 0x8019737Cu: goto label_8019737C;
    case 0x80197380u: goto label_80197380;
    case 0x80197384u: goto label_80197384;
    case 0x80197388u: goto label_80197388;
    case 0x8019738Cu: goto label_8019738C;
    case 0x80197390u: goto label_80197390;
    case 0x80197394u: goto label_80197394;
    case 0x80197398u: goto label_80197398;
    case 0x8019739Cu: goto label_8019739C;
    case 0x801973A0u: goto label_801973A0;
    case 0x801973A4u: goto label_801973A4;
    case 0x801973A8u: goto label_801973A8;
    case 0x801973ACu: goto label_801973AC;
    case 0x801973B0u: goto label_801973B0;
    case 0x801973B4u: goto label_801973B4;
    case 0x801973B8u: goto label_801973B8;
    case 0x801973BCu: goto label_801973BC;
    case 0x801973C0u: goto label_801973C0;
    case 0x801973C4u: goto label_801973C4;
    case 0x801973C8u: goto label_801973C8;
    case 0x801973CCu: goto label_801973CC;
    case 0x801973D0u: goto label_801973D0;
    case 0x801973D4u: goto label_801973D4;
    case 0x801973D8u: goto label_801973D8;
    case 0x801973DCu: goto label_801973DC;
    case 0x801973E0u: goto label_801973E0;
    case 0x801973E4u: goto label_801973E4;
    case 0x801973E8u: goto label_801973E8;
    case 0x801973ECu: goto label_801973EC;
    case 0x801973F0u: goto label_801973F0;
    case 0x801973F4u: goto label_801973F4;
    case 0x801973F8u: goto label_801973F8;
    case 0x801973FCu: goto label_801973FC;
    case 0x80197400u: goto label_80197400;
    case 0x80197404u: goto label_80197404;
    case 0x80197408u: goto label_80197408;
    case 0x8019740Cu: goto label_8019740C;
    case 0x80197410u: goto label_80197410;
    case 0x80197414u: goto label_80197414;
    case 0x80197418u: goto label_80197418;
    case 0x8019741Cu: goto label_8019741C;
    case 0x80197420u: goto label_80197420;
    case 0x80197424u: goto label_80197424;
    case 0x80197428u: goto label_80197428;
    case 0x8019742Cu: goto label_8019742C;
    case 0x80197430u: goto label_80197430;
    case 0x80197434u: goto label_80197434;
    case 0x80197438u: goto label_80197438;
    case 0x8019743Cu: goto label_8019743C;
    case 0x80197440u: goto label_80197440;
    case 0x80197444u: goto label_80197444;
    case 0x80197448u: goto label_80197448;
    case 0x8019744Cu: goto label_8019744C;
    case 0x80197450u: goto label_80197450;
    case 0x80197454u: goto label_80197454;
    case 0x80197458u: goto label_80197458;
    case 0x8019745Cu: goto label_8019745C;
    case 0x80197460u: goto label_80197460;
    case 0x80197464u: goto label_80197464;
    case 0x80197468u: goto label_80197468;
    case 0x8019746Cu: goto label_8019746C;
    case 0x80197470u: goto label_80197470;
    case 0x80197474u: goto label_80197474;
    case 0x80197478u: goto label_80197478;
    case 0x8019747Cu: goto label_8019747C;
    case 0x80197480u: goto label_80197480;
    case 0x80197484u: goto label_80197484;
    case 0x80197488u: goto label_80197488;
    case 0x8019748Cu: goto label_8019748C;
    case 0x80197490u: goto label_80197490;
    case 0x80197494u: goto label_80197494;
    case 0x80197498u: goto label_80197498;
    case 0x8019749Cu: goto label_8019749C;
    case 0x801974A0u: goto label_801974A0;
    case 0x801974A4u: goto label_801974A4;
    case 0x801974A8u: goto label_801974A8;
    case 0x801974ACu: goto label_801974AC;
    case 0x801974B0u: goto label_801974B0;
    case 0x801974B4u: goto label_801974B4;
    case 0x801974B8u: goto label_801974B8;
    case 0x801974BCu: goto label_801974BC;
    case 0x801974C0u: goto label_801974C0;
    case 0x801974C4u: goto label_801974C4;
    case 0x801974C8u: goto label_801974C8;
    case 0x801974CCu: goto label_801974CC;
    case 0x801974D0u: goto label_801974D0;
    case 0x801974D4u: goto label_801974D4;
    case 0x801974D8u: goto label_801974D8;
    case 0x801974DCu: goto label_801974DC;
    case 0x801974E0u: goto label_801974E0;
    case 0x801974E4u: goto label_801974E4;
    case 0x801974E8u: goto label_801974E8;
    case 0x801974ECu: goto label_801974EC;
    case 0x801974F0u: goto label_801974F0;
    case 0x801974F4u: goto label_801974F4;
    case 0x801974F8u: goto label_801974F8;
    case 0x801974FCu: goto label_801974FC;
    case 0x80197500u: goto label_80197500;
    case 0x80197504u: goto label_80197504;
    case 0x80197508u: goto label_80197508;
    case 0x8019750Cu: goto label_8019750C;
    case 0x80197510u: goto label_80197510;
    case 0x80197514u: goto label_80197514;
    case 0x80197518u: goto label_80197518;
    case 0x8019751Cu: goto label_8019751C;
    case 0x80197520u: goto label_80197520;
    case 0x80197524u: goto label_80197524;
    case 0x80197528u: goto label_80197528;
    case 0x8019752Cu: goto label_8019752C;
    case 0x80197530u: goto label_80197530;
    case 0x80197534u: goto label_80197534;
    case 0x80197538u: goto label_80197538;
    case 0x8019753Cu: goto label_8019753C;
    case 0x80197540u: goto label_80197540;
    case 0x80197544u: goto label_80197544;
    case 0x80197548u: goto label_80197548;
    case 0x8019754Cu: goto label_8019754C;
    case 0x80197550u: goto label_80197550;
    case 0x80197554u: goto label_80197554;
    case 0x80197558u: goto label_80197558;
    case 0x8019755Cu: goto label_8019755C;
    case 0x80197560u: goto label_80197560;
    case 0x80197564u: goto label_80197564;
    case 0x80197568u: goto label_80197568;
    case 0x8019756Cu: goto label_8019756C;
    case 0x80197570u: goto label_80197570;
    case 0x80197574u: goto label_80197574;
    case 0x80197578u: goto label_80197578;
    case 0x8019757Cu: goto label_8019757C;
    case 0x80197580u: goto label_80197580;
    case 0x80197584u: goto label_80197584;
    case 0x80197588u: goto label_80197588;
    case 0x8019758Cu: goto label_8019758C;
    case 0x80197590u: goto label_80197590;
    case 0x80197594u: goto label_80197594;
    case 0x80197598u: goto label_80197598;
    case 0x8019759Cu: goto label_8019759C;
    case 0x801975A0u: goto label_801975A0;
    case 0x801975A4u: goto label_801975A4;
    case 0x801975A8u: goto label_801975A8;
    case 0x801975ACu: goto label_801975AC;
    case 0x801975B0u: goto label_801975B0;
    case 0x801975B4u: goto label_801975B4;
    case 0x801975B8u: goto label_801975B8;
    case 0x801975BCu: goto label_801975BC;
    case 0x801975C0u: goto label_801975C0;
    case 0x801975C4u: goto label_801975C4;
    case 0x801975C8u: goto label_801975C8;
    case 0x801975CCu: goto label_801975CC;
    case 0x801975D0u: goto label_801975D0;
    case 0x801975D4u: goto label_801975D4;
    case 0x801975D8u: goto label_801975D8;
    case 0x801975DCu: goto label_801975DC;
    case 0x801975E0u: goto label_801975E0;
    case 0x801975E4u: goto label_801975E4;
    case 0x801975E8u: goto label_801975E8;
    case 0x801975ECu: goto label_801975EC;
    case 0x801975F0u: goto label_801975F0;
    case 0x801975F4u: goto label_801975F4;
    case 0x801975F8u: goto label_801975F8;
    case 0x801975FCu: goto label_801975FC;
    case 0x80197600u: goto label_80197600;
    case 0x80197604u: goto label_80197604;
    case 0x80197608u: goto label_80197608;
    case 0x8019760Cu: goto label_8019760C;
    case 0x80197610u: goto label_80197610;
    case 0x80197614u: goto label_80197614;
    case 0x80197618u: goto label_80197618;
    case 0x8019761Cu: goto label_8019761C;
    case 0x80197620u: goto label_80197620;
    case 0x80197624u: goto label_80197624;
    case 0x80197628u: goto label_80197628;
    case 0x8019762Cu: goto label_8019762C;
    case 0x80197630u: goto label_80197630;
    case 0x80197634u: goto label_80197634;
    case 0x80197638u: goto label_80197638;
    case 0x8019763Cu: goto label_8019763C;
    case 0x80197640u: goto label_80197640;
    case 0x80197644u: goto label_80197644;
    case 0x80197648u: goto label_80197648;
    case 0x8019764Cu: goto label_8019764C;
    case 0x80197650u: goto label_80197650;
    case 0x80197654u: goto label_80197654;
    case 0x80197658u: goto label_80197658;
    case 0x8019765Cu: goto label_8019765C;
    case 0x80197660u: goto label_80197660;
    case 0x80197664u: goto label_80197664;
    case 0x80197668u: goto label_80197668;
    case 0x8019766Cu: goto label_8019766C;
    case 0x80197670u: goto label_80197670;
    case 0x80197674u: goto label_80197674;
    case 0x80197678u: goto label_80197678;
    case 0x8019767Cu: goto label_8019767C;
    case 0x80197680u: goto label_80197680;
    case 0x80197684u: goto label_80197684;
    case 0x80197688u: goto label_80197688;
    case 0x8019768Cu: goto label_8019768C;
    case 0x80197690u: goto label_80197690;
    case 0x80197694u: goto label_80197694;
    case 0x80197698u: goto label_80197698;
    case 0x8019769Cu: goto label_8019769C;
    case 0x801976A0u: goto label_801976A0;
    case 0x801976A4u: goto label_801976A4;
    case 0x801976A8u: goto label_801976A8;
    case 0x801976ACu: goto label_801976AC;
    case 0x801976B0u: goto label_801976B0;
    case 0x801976B4u: goto label_801976B4;
    case 0x801976B8u: goto label_801976B8;
    case 0x801976BCu: goto label_801976BC;
    case 0x801976C0u: goto label_801976C0;
    case 0x801976C4u: goto label_801976C4;
    case 0x801976C8u: goto label_801976C8;
    case 0x801976CCu: goto label_801976CC;
    case 0x801976D0u: goto label_801976D0;
    case 0x801976D4u: goto label_801976D4;
    case 0x801976D8u: goto label_801976D8;
    case 0x801976DCu: goto label_801976DC;
    case 0x801976E0u: goto label_801976E0;
    case 0x801976E4u: goto label_801976E4;
    case 0x801976E8u: goto label_801976E8;
    case 0x801976ECu: goto label_801976EC;
    case 0x801976F0u: goto label_801976F0;
    case 0x801976F4u: goto label_801976F4;
    case 0x801976F8u: goto label_801976F8;
    case 0x801976FCu: goto label_801976FC;
    case 0x80197700u: goto label_80197700;
    case 0x80197704u: goto label_80197704;
    case 0x80197708u: goto label_80197708;
    case 0x8019770Cu: goto label_8019770C;
    case 0x80197710u: goto label_80197710;
    case 0x80197714u: goto label_80197714;
    case 0x80197718u: goto label_80197718;
    case 0x8019771Cu: goto label_8019771C;
    case 0x80197720u: goto label_80197720;
    case 0x80197724u: goto label_80197724;
    case 0x80197728u: goto label_80197728;
    case 0x8019772Cu: goto label_8019772C;
    case 0x80197730u: goto label_80197730;
    case 0x80197734u: goto label_80197734;
    case 0x80197738u: goto label_80197738;
    case 0x8019773Cu: goto label_8019773C;
    case 0x80197740u: goto label_80197740;
    case 0x80197744u: goto label_80197744;
    case 0x80197748u: goto label_80197748;
    case 0x8019774Cu: goto label_8019774C;
    case 0x80197750u: goto label_80197750;
    case 0x80197754u: goto label_80197754;
    case 0x80197758u: goto label_80197758;
    case 0x8019775Cu: goto label_8019775C;
    case 0x80197760u: goto label_80197760;
    case 0x80197764u: goto label_80197764;
    case 0x80197768u: goto label_80197768;
    case 0x8019776Cu: goto label_8019776C;
    case 0x80197770u: goto label_80197770;
    case 0x80197774u: goto label_80197774;
    case 0x80197778u: goto label_80197778;
    case 0x8019777Cu: goto label_8019777C;
    case 0x80197780u: goto label_80197780;
    case 0x80197784u: goto label_80197784;
    case 0x80197788u: goto label_80197788;
    case 0x8019778Cu: goto label_8019778C;
    case 0x80197790u: goto label_80197790;
    case 0x80197794u: goto label_80197794;
    case 0x80197798u: goto label_80197798;
    case 0x8019779Cu: goto label_8019779C;
    case 0x801977A0u: goto label_801977A0;
    case 0x801977A4u: goto label_801977A4;
    case 0x801977A8u: goto label_801977A8;
    case 0x801977ACu: goto label_801977AC;
    case 0x801977B0u: goto label_801977B0;
    case 0x801977B4u: goto label_801977B4;
    case 0x801977B8u: goto label_801977B8;
    case 0x801977BCu: goto label_801977BC;
    case 0x801977C0u: goto label_801977C0;
    case 0x801977C4u: goto label_801977C4;
    case 0x801977C8u: goto label_801977C8;
    case 0x801977CCu: goto label_801977CC;
    case 0x801977D0u: goto label_801977D0;
    case 0x801977D4u: goto label_801977D4;
    case 0x801977D8u: goto label_801977D8;
    case 0x801977DCu: goto label_801977DC;
    case 0x801977E0u: goto label_801977E0;
    case 0x801977E4u: goto label_801977E4;
    case 0x801977E8u: goto label_801977E8;
    case 0x801977ECu: goto label_801977EC;
    case 0x801977F0u: goto label_801977F0;
    case 0x801977F4u: goto label_801977F4;
    case 0x801977F8u: goto label_801977F8;
    case 0x801977FCu: goto label_801977FC;
    case 0x80197800u: goto label_80197800;
    case 0x80197804u: goto label_80197804;
    case 0x80197808u: goto label_80197808;
    case 0x8019780Cu: goto label_8019780C;
    case 0x80197810u: goto label_80197810;
    case 0x80197814u: goto label_80197814;
    case 0x80197818u: goto label_80197818;
    case 0x8019781Cu: goto label_8019781C;
    case 0x80197820u: goto label_80197820;
    case 0x80197824u: goto label_80197824;
    case 0x80197828u: goto label_80197828;
    case 0x8019782Cu: goto label_8019782C;
    case 0x80197830u: goto label_80197830;
    case 0x80197834u: goto label_80197834;
    case 0x80197838u: goto label_80197838;
    case 0x8019783Cu: goto label_8019783C;
    case 0x80197840u: goto label_80197840;
    case 0x80197844u: goto label_80197844;
    case 0x80197848u: goto label_80197848;
    case 0x8019784Cu: goto label_8019784C;
    case 0x80197850u: goto label_80197850;
    case 0x80197854u: goto label_80197854;
    case 0x80197858u: goto label_80197858;
    case 0x8019785Cu: goto label_8019785C;
    case 0x80197860u: goto label_80197860;
    case 0x80197864u: goto label_80197864;
    case 0x80197868u: goto label_80197868;
    case 0x8019786Cu: goto label_8019786C;
    case 0x80197870u: goto label_80197870;
    case 0x80197874u: goto label_80197874;
    case 0x80197878u: goto label_80197878;
    case 0x8019787Cu: goto label_8019787C;
    case 0x80197880u: goto label_80197880;
    case 0x80197884u: goto label_80197884;
    case 0x80197888u: goto label_80197888;
    case 0x8019788Cu: goto label_8019788C;
    case 0x80197890u: goto label_80197890;
    case 0x80197894u: goto label_80197894;
    case 0x80197898u: goto label_80197898;
    case 0x8019789Cu: goto label_8019789C;
    case 0x801978A0u: goto label_801978A0;
    case 0x801978A4u: goto label_801978A4;
    case 0x801978A8u: goto label_801978A8;
    case 0x801978ACu: goto label_801978AC;
    case 0x801978B0u: goto label_801978B0;
    case 0x801978B4u: goto label_801978B4;
    case 0x801978B8u: goto label_801978B8;
    case 0x801978BCu: goto label_801978BC;
    case 0x801978C0u: goto label_801978C0;
    case 0x801978C4u: goto label_801978C4;
    case 0x801978C8u: goto label_801978C8;
    case 0x801978CCu: goto label_801978CC;
    case 0x801978D0u: goto label_801978D0;
    case 0x801978D4u: goto label_801978D4;
    case 0x801978D8u: goto label_801978D8;
    case 0x801978DCu: goto label_801978DC;
    case 0x801978E0u: goto label_801978E0;
    case 0x801978E4u: goto label_801978E4;
    case 0x801978E8u: goto label_801978E8;
    case 0x801978ECu: goto label_801978EC;
    case 0x801978F0u: goto label_801978F0;
    case 0x801978F4u: goto label_801978F4;
    case 0x801978F8u: goto label_801978F8;
    case 0x801978FCu: goto label_801978FC;
    case 0x80197900u: goto label_80197900;
    case 0x80197904u: goto label_80197904;
    case 0x80197908u: goto label_80197908;
    case 0x8019790Cu: goto label_8019790C;
    case 0x80197910u: goto label_80197910;
    case 0x80197914u: goto label_80197914;
    case 0x80197918u: goto label_80197918;
    case 0x8019791Cu: goto label_8019791C;
    case 0x80197920u: goto label_80197920;
    case 0x80197924u: goto label_80197924;
    case 0x80197928u: goto label_80197928;
    case 0x8019792Cu: goto label_8019792C;
    case 0x80197930u: goto label_80197930;
    case 0x80197934u: goto label_80197934;
    case 0x80197938u: goto label_80197938;
    case 0x8019793Cu: goto label_8019793C;
    case 0x80197940u: goto label_80197940;
    case 0x80197944u: goto label_80197944;
    case 0x80197948u: goto label_80197948;
    case 0x8019794Cu: goto label_8019794C;
    case 0x80197950u: goto label_80197950;
    case 0x80197954u: goto label_80197954;
    case 0x80197958u: goto label_80197958;
    case 0x8019795Cu: goto label_8019795C;
    case 0x80197960u: goto label_80197960;
    case 0x80197964u: goto label_80197964;
    case 0x80197968u: goto label_80197968;
    case 0x8019796Cu: goto label_8019796C;
    case 0x80197970u: goto label_80197970;
    case 0x80197974u: goto label_80197974;
    case 0x80197978u: goto label_80197978;
    case 0x8019797Cu: goto label_8019797C;
    case 0x80197980u: goto label_80197980;
    case 0x80197984u: goto label_80197984;
    case 0x80197988u: goto label_80197988;
    case 0x8019798Cu: goto label_8019798C;
    case 0x80197990u: goto label_80197990;
    case 0x80197994u: goto label_80197994;
    case 0x80197998u: goto label_80197998;
    case 0x8019799Cu: goto label_8019799C;
    case 0x801979A0u: goto label_801979A0;
    case 0x801979A4u: goto label_801979A4;
    case 0x801979A8u: goto label_801979A8;
    case 0x801979ACu: goto label_801979AC;
    case 0x801979B0u: goto label_801979B0;
    case 0x801979B4u: goto label_801979B4;
    case 0x801979B8u: goto label_801979B8;
    case 0x801979BCu: goto label_801979BC;
    case 0x801979C0u: goto label_801979C0;
    case 0x801979C4u: goto label_801979C4;
    case 0x801979C8u: goto label_801979C8;
    case 0x801979CCu: goto label_801979CC;
    case 0x801979D0u: goto label_801979D0;
    case 0x801979D4u: goto label_801979D4;
    case 0x801979D8u: goto label_801979D8;
    case 0x801979DCu: goto label_801979DC;
    case 0x801979E0u: goto label_801979E0;
    case 0x801979E4u: goto label_801979E4;
    case 0x801979E8u: goto label_801979E8;
    case 0x801979ECu: goto label_801979EC;
    case 0x801979F0u: goto label_801979F0;
    case 0x801979F4u: goto label_801979F4;
    case 0x801979F8u: goto label_801979F8;
    case 0x801979FCu: goto label_801979FC;
    case 0x80197A00u: goto label_80197A00;
    case 0x80197A04u: goto label_80197A04;
    case 0x80197A08u: goto label_80197A08;
    case 0x80197A0Cu: goto label_80197A0C;
    case 0x80197A10u: goto label_80197A10;
    case 0x80197A14u: goto label_80197A14;
    case 0x80197A18u: goto label_80197A18;
    case 0x80197A1Cu: goto label_80197A1C;
    case 0x80197A20u: goto label_80197A20;
    case 0x80197A24u: goto label_80197A24;
    case 0x80197A28u: goto label_80197A28;
    case 0x80197A2Cu: goto label_80197A2C;
    case 0x80197A30u: goto label_80197A30;
    case 0x80197A34u: goto label_80197A34;
    case 0x80197A38u: goto label_80197A38;
    case 0x80197A3Cu: goto label_80197A3C;
    case 0x80197A40u: goto label_80197A40;
    case 0x80197A44u: goto label_80197A44;
    case 0x80197A48u: goto label_80197A48;
    case 0x80197A4Cu: goto label_80197A4C;
    case 0x80197A50u: goto label_80197A50;
    case 0x80197A54u: goto label_80197A54;
    case 0x80197A58u: goto label_80197A58;
    case 0x80197A5Cu: goto label_80197A5C;
    case 0x80197A60u: goto label_80197A60;
    case 0x80197A64u: goto label_80197A64;
    case 0x80197A68u: goto label_80197A68;
    case 0x80197A6Cu: goto label_80197A6C;
    case 0x80197A70u: goto label_80197A70;
    case 0x80197A74u: goto label_80197A74;
    case 0x80197A78u: goto label_80197A78;
    case 0x80197A7Cu: goto label_80197A7C;
    case 0x80197A80u: goto label_80197A80;
    case 0x80197A84u: goto label_80197A84;
    case 0x80197A88u: goto label_80197A88;
    case 0x80197A8Cu: goto label_80197A8C;
    case 0x80197A90u: goto label_80197A90;
    case 0x80197A94u: goto label_80197A94;
    case 0x80197A98u: goto label_80197A98;
    case 0x80197A9Cu: goto label_80197A9C;
    case 0x80197AA0u: goto label_80197AA0;
    case 0x80197AA4u: goto label_80197AA4;
    case 0x80197AA8u: goto label_80197AA8;
    case 0x80197AACu: goto label_80197AAC;
    case 0x80197AB0u: goto label_80197AB0;
    case 0x80197AB4u: goto label_80197AB4;
    case 0x80197AB8u: goto label_80197AB8;
    case 0x80197ABCu: goto label_80197ABC;
    case 0x80197AC0u: goto label_80197AC0;
    case 0x80197AC4u: goto label_80197AC4;
    case 0x80197AC8u: goto label_80197AC8;
    case 0x80197ACCu: goto label_80197ACC;
    case 0x80197AD0u: goto label_80197AD0;
    case 0x80197AD4u: goto label_80197AD4;
    case 0x80197AD8u: goto label_80197AD8;
    case 0x80197ADCu: goto label_80197ADC;
    case 0x80197AE0u: goto label_80197AE0;
    case 0x80197AE4u: goto label_80197AE4;
    case 0x80197AE8u: goto label_80197AE8;
    case 0x80197AECu: goto label_80197AEC;
    case 0x80197AF0u: goto label_80197AF0;
    case 0x80197AF4u: goto label_80197AF4;
    case 0x80197AF8u: goto label_80197AF8;
    case 0x80197AFCu: goto label_80197AFC;
    case 0x80197B00u: goto label_80197B00;
    case 0x80197B04u: goto label_80197B04;
    case 0x80197B08u: goto label_80197B08;
    case 0x80197B0Cu: goto label_80197B0C;
    case 0x80197B10u: goto label_80197B10;
    case 0x80197B14u: goto label_80197B14;
    case 0x80197B18u: goto label_80197B18;
    case 0x80197B1Cu: goto label_80197B1C;
    case 0x80197B20u: goto label_80197B20;
    case 0x80197B24u: goto label_80197B24;
    case 0x80197B28u: goto label_80197B28;
    case 0x80197B2Cu: goto label_80197B2C;
    case 0x80197B30u: goto label_80197B30;
    case 0x80197B34u: goto label_80197B34;
    case 0x80197B38u: goto label_80197B38;
    case 0x80197B3Cu: goto label_80197B3C;
    case 0x80197B40u: goto label_80197B40;
    case 0x80197B44u: goto label_80197B44;
    case 0x80197B48u: goto label_80197B48;
    case 0x80197B4Cu: goto label_80197B4C;
    case 0x80197B50u: goto label_80197B50;
    case 0x80197B54u: goto label_80197B54;
    case 0x80197B58u: goto label_80197B58;
    case 0x80197B5Cu: goto label_80197B5C;
    case 0x80197B60u: goto label_80197B60;
    case 0x80197B64u: goto label_80197B64;
    case 0x80197B68u: goto label_80197B68;
    case 0x80197B6Cu: goto label_80197B6C;
    case 0x80197B70u: goto label_80197B70;
    case 0x80197B74u: goto label_80197B74;
    case 0x80197B78u: goto label_80197B78;
    case 0x80197B7Cu: goto label_80197B7C;
    case 0x80197B80u: goto label_80197B80;
    case 0x80197B84u: goto label_80197B84;
    case 0x80197B88u: goto label_80197B88;
    case 0x80197B8Cu: goto label_80197B8C;
    case 0x80197B90u: goto label_80197B90;
    case 0x80197B94u: goto label_80197B94;
    case 0x80197B98u: goto label_80197B98;
    case 0x80197B9Cu: goto label_80197B9C;
    case 0x80197BA0u: goto label_80197BA0;
    case 0x80197BA4u: goto label_80197BA4;
    case 0x80197BA8u: goto label_80197BA8;
    case 0x80197BACu: goto label_80197BAC;
    case 0x80197BB0u: goto label_80197BB0;
    case 0x80197BB4u: goto label_80197BB4;
    case 0x80197BB8u: goto label_80197BB8;
    case 0x80197BBCu: goto label_80197BBC;
    case 0x80197BC0u: goto label_80197BC0;
    case 0x80197BC4u: goto label_80197BC4;
    case 0x80197BC8u: goto label_80197BC8;
    case 0x80197BCCu: goto label_80197BCC;
    case 0x80197BD0u: goto label_80197BD0;
    case 0x80197BD4u: goto label_80197BD4;
    case 0x80197BD8u: goto label_80197BD8;
    case 0x80197BDCu: goto label_80197BDC;
    case 0x80197BE0u: goto label_80197BE0;
    case 0x80197BE4u: goto label_80197BE4;
    case 0x80197BE8u: goto label_80197BE8;
    case 0x80197BECu: goto label_80197BEC;
    case 0x80197BF0u: goto label_80197BF0;
    case 0x80197BF4u: goto label_80197BF4;
    case 0x80197BF8u: goto label_80197BF8;
    case 0x80197BFCu: goto label_80197BFC;
    case 0x80197C00u: goto label_80197C00;
    case 0x80197C04u: goto label_80197C04;
    case 0x80197C08u: goto label_80197C08;
    case 0x80197C0Cu: goto label_80197C0C;
    case 0x80197C10u: goto label_80197C10;
    case 0x80197C14u: goto label_80197C14;
    case 0x80197C18u: goto label_80197C18;
    case 0x80197C1Cu: goto label_80197C1C;
    case 0x80197C20u: goto label_80197C20;
    case 0x80197C24u: goto label_80197C24;
    case 0x80197C28u: goto label_80197C28;
    case 0x80197C2Cu: goto label_80197C2C;
    case 0x80197C30u: goto label_80197C30;
    case 0x80197C34u: goto label_80197C34;
    case 0x80197C38u: goto label_80197C38;
    case 0x80197C3Cu: goto label_80197C3C;
    case 0x80197C40u: goto label_80197C40;
    case 0x80197C44u: goto label_80197C44;
    case 0x80197C48u: goto label_80197C48;
    case 0x80197C4Cu: goto label_80197C4C;
    case 0x80197C50u: goto label_80197C50;
    case 0x80197C54u: goto label_80197C54;
    case 0x80197C58u: goto label_80197C58;
    case 0x80197C5Cu: goto label_80197C5C;
    case 0x80197C60u: goto label_80197C60;
    case 0x80197C64u: goto label_80197C64;
    case 0x80197C68u: goto label_80197C68;
    case 0x80197C6Cu: goto label_80197C6C;
    case 0x80197C70u: goto label_80197C70;
    case 0x80197C74u: goto label_80197C74;
    case 0x80197C78u: goto label_80197C78;
    case 0x80197C7Cu: goto label_80197C7C;
    case 0x80197C80u: goto label_80197C80;
    case 0x80197C84u: goto label_80197C84;
    case 0x80197C88u: goto label_80197C88;
    case 0x80197C8Cu: goto label_80197C8C;
    case 0x80197C90u: goto label_80197C90;
    case 0x80197C94u: goto label_80197C94;
    case 0x80197C98u: goto label_80197C98;
    case 0x80197C9Cu: goto label_80197C9C;
    case 0x80197CA0u: goto label_80197CA0;
    case 0x80197CA4u: goto label_80197CA4;
    case 0x80197CA8u: goto label_80197CA8;
    case 0x80197CACu: goto label_80197CAC;
    case 0x80197CB0u: goto label_80197CB0;
    case 0x80197CB4u: goto label_80197CB4;
    case 0x80197CB8u: goto label_80197CB8;
    case 0x80197CBCu: goto label_80197CBC;
    case 0x80197CC0u: goto label_80197CC0;
    case 0x80197CC4u: goto label_80197CC4;
    case 0x80197CC8u: goto label_80197CC8;
    case 0x80197CCCu: goto label_80197CCC;
    case 0x80197CD0u: goto label_80197CD0;
    case 0x80197CD4u: goto label_80197CD4;
    case 0x80197CD8u: goto label_80197CD8;
    case 0x80197CDCu: goto label_80197CDC;
    case 0x80197CE0u: goto label_80197CE0;
    case 0x80197CE4u: goto label_80197CE4;
    case 0x80197CE8u: goto label_80197CE8;
    case 0x80197CECu: goto label_80197CEC;
    case 0x80197CF0u: goto label_80197CF0;
    case 0x80197CF4u: goto label_80197CF4;
    case 0x80197CF8u: goto label_80197CF8;
    case 0x80197CFCu: goto label_80197CFC;
    case 0x80197D00u: goto label_80197D00;
    case 0x80197D04u: goto label_80197D04;
    case 0x80197D08u: goto label_80197D08;
    case 0x80197D0Cu: goto label_80197D0C;
    case 0x80197D10u: goto label_80197D10;
    case 0x80197D14u: goto label_80197D14;
    case 0x80197D18u: goto label_80197D18;
    case 0x80197D1Cu: goto label_80197D1C;
    case 0x80197D20u: goto label_80197D20;
    case 0x80197D24u: goto label_80197D24;
    case 0x80197D28u: goto label_80197D28;
    case 0x80197D2Cu: goto label_80197D2C;
    case 0x80197D30u: goto label_80197D30;
    case 0x80197D34u: goto label_80197D34;
    case 0x80197D38u: goto label_80197D38;
    case 0x80197D3Cu: goto label_80197D3C;
    case 0x80197D40u: goto label_80197D40;
    case 0x80197D44u: goto label_80197D44;
    case 0x80197D48u: goto label_80197D48;
    case 0x80197D4Cu: goto label_80197D4C;
    case 0x80197D50u: goto label_80197D50;
    case 0x80197D54u: goto label_80197D54;
    case 0x80197D58u: goto label_80197D58;
    case 0x80197D5Cu: goto label_80197D5C;
    case 0x80197D60u: goto label_80197D60;
    case 0x80197D64u: goto label_80197D64;
    case 0x80197D68u: goto label_80197D68;
    case 0x80197D6Cu: goto label_80197D6C;
    case 0x80197D70u: goto label_80197D70;
    case 0x80197D74u: goto label_80197D74;
    case 0x80197D78u: goto label_80197D78;
    case 0x80197D7Cu: goto label_80197D7C;
    case 0x80197D80u: goto label_80197D80;
    case 0x80197D84u: goto label_80197D84;
    case 0x80197D88u: goto label_80197D88;
    case 0x80197D8Cu: goto label_80197D8C;
    case 0x80197D90u: goto label_80197D90;
    case 0x80197D94u: goto label_80197D94;
    case 0x80197D98u: goto label_80197D98;
    case 0x80197D9Cu: goto label_80197D9C;
    case 0x80197DA0u: goto label_80197DA0;
    case 0x80197DA4u: goto label_80197DA4;
    case 0x80197DA8u: goto label_80197DA8;
    case 0x80197DACu: goto label_80197DAC;
    case 0x80197DB0u: goto label_80197DB0;
    case 0x80197DB4u: goto label_80197DB4;
    case 0x80197DB8u: goto label_80197DB8;
    case 0x80197DBCu: goto label_80197DBC;
    case 0x80197DC0u: goto label_80197DC0;
    case 0x80197DC4u: goto label_80197DC4;
    case 0x80197DC8u: goto label_80197DC8;
    case 0x80197DCCu: goto label_80197DCC;
    case 0x80197DD0u: goto label_80197DD0;
    case 0x80197DD4u: goto label_80197DD4;
    case 0x80197DD8u: goto label_80197DD8;
    case 0x80197DDCu: goto label_80197DDC;
    case 0x80197DE0u: goto label_80197DE0;
    case 0x80197DE4u: goto label_80197DE4;
    case 0x80197DE8u: goto label_80197DE8;
    case 0x80197DECu: goto label_80197DEC;
    case 0x80197DF0u: goto label_80197DF0;
    case 0x80197DF4u: goto label_80197DF4;
    case 0x80197DF8u: goto label_80197DF8;
    case 0x80197DFCu: goto label_80197DFC;
    case 0x80197E00u: goto label_80197E00;
    case 0x80197E04u: goto label_80197E04;
    case 0x80197E08u: goto label_80197E08;
    case 0x80197E0Cu: goto label_80197E0C;
    case 0x80197E10u: goto label_80197E10;
    case 0x80197E14u: goto label_80197E14;
    case 0x80197E18u: goto label_80197E18;
    case 0x80197E1Cu: goto label_80197E1C;
    case 0x80197E20u: goto label_80197E20;
    case 0x80197E24u: goto label_80197E24;
    case 0x80197E28u: goto label_80197E28;
    case 0x80197E2Cu: goto label_80197E2C;
    case 0x80197E30u: goto label_80197E30;
    case 0x80197E34u: goto label_80197E34;
    case 0x80197E38u: goto label_80197E38;
    case 0x80197E3Cu: goto label_80197E3C;
    case 0x80197E40u: goto label_80197E40;
    case 0x80197E44u: goto label_80197E44;
    case 0x80197E48u: goto label_80197E48;
    case 0x80197E4Cu: goto label_80197E4C;
    case 0x80197E50u: goto label_80197E50;
    case 0x80197E54u: goto label_80197E54;
    case 0x80197E58u: goto label_80197E58;
    case 0x80197E5Cu: goto label_80197E5C;
    case 0x80197E60u: goto label_80197E60;
    case 0x80197E64u: goto label_80197E64;
    case 0x80197E68u: goto label_80197E68;
    case 0x80197E6Cu: goto label_80197E6C;
    case 0x80197E70u: goto label_80197E70;
    case 0x80197E74u: goto label_80197E74;
    case 0x80197E78u: goto label_80197E78;
    case 0x80197E7Cu: goto label_80197E7C;
    case 0x80197E80u: goto label_80197E80;
    case 0x80197E84u: goto label_80197E84;
    case 0x80197E88u: goto label_80197E88;
    case 0x80197E8Cu: goto label_80197E8C;
    case 0x80197E90u: goto label_80197E90;
    case 0x80197E94u: goto label_80197E94;
    case 0x80197E98u: goto label_80197E98;
    case 0x80197E9Cu: goto label_80197E9C;
    case 0x80197EA0u: goto label_80197EA0;
    case 0x80197EA4u: goto label_80197EA4;
    case 0x80197EA8u: goto label_80197EA8;
    case 0x80197EACu: goto label_80197EAC;
    case 0x80197EB0u: goto label_80197EB0;
    case 0x80197EB4u: goto label_80197EB4;
    case 0x80197EB8u: goto label_80197EB8;
    case 0x80197EBCu: goto label_80197EBC;
    case 0x80197EC0u: goto label_80197EC0;
    case 0x80197EC4u: goto label_80197EC4;
    case 0x80197EC8u: goto label_80197EC8;
    case 0x80197ECCu: goto label_80197ECC;
    case 0x80197ED0u: goto label_80197ED0;
    case 0x80197ED4u: goto label_80197ED4;
    case 0x80197ED8u: goto label_80197ED8;
    case 0x80197EDCu: goto label_80197EDC;
    case 0x80197EE0u: goto label_80197EE0;
    case 0x80197EE4u: goto label_80197EE4;
    case 0x80197EE8u: goto label_80197EE8;
    case 0x80197EECu: goto label_80197EEC;
    case 0x80197EF0u: goto label_80197EF0;
    case 0x80197EF4u: goto label_80197EF4;
    case 0x80197EF8u: goto label_80197EF8;
    case 0x80197EFCu: goto label_80197EFC;
    case 0x80197F00u: goto label_80197F00;
    case 0x80197F04u: goto label_80197F04;
    case 0x80197F08u: goto label_80197F08;
    case 0x80197F0Cu: goto label_80197F0C;
    case 0x80197F10u: goto label_80197F10;
    case 0x80197F14u: goto label_80197F14;
    case 0x80197F18u: goto label_80197F18;
    case 0x80197F1Cu: goto label_80197F1C;
    case 0x80197F20u: goto label_80197F20;
    case 0x80197F24u: goto label_80197F24;
    case 0x80197F28u: goto label_80197F28;
    case 0x80197F2Cu: goto label_80197F2C;
    case 0x80197F30u: goto label_80197F30;
    case 0x80197F34u: goto label_80197F34;
    case 0x80197F38u: goto label_80197F38;
    case 0x80197F3Cu: goto label_80197F3C;
    case 0x80197F40u: goto label_80197F40;
    case 0x80197F44u: goto label_80197F44;
    case 0x80197F48u: goto label_80197F48;
    case 0x80197F4Cu: goto label_80197F4C;
    case 0x80197F50u: goto label_80197F50;
    case 0x80197F54u: goto label_80197F54;
    case 0x80197F58u: goto label_80197F58;
    case 0x80197F5Cu: goto label_80197F5C;
    case 0x80197F60u: goto label_80197F60;
    case 0x80197F64u: goto label_80197F64;
    case 0x80197F68u: goto label_80197F68;
    case 0x80197F6Cu: goto label_80197F6C;
    case 0x80197F70u: goto label_80197F70;
    case 0x80197F74u: goto label_80197F74;
    case 0x80197F78u: goto label_80197F78;
    case 0x80197F7Cu: goto label_80197F7C;
    case 0x80197F80u: goto label_80197F80;
    case 0x80197F84u: goto label_80197F84;
    case 0x80197F88u: goto label_80197F88;
    case 0x80197F8Cu: goto label_80197F8C;
    case 0x80197F90u: goto label_80197F90;
    case 0x80197F94u: goto label_80197F94;
    case 0x80197F98u: goto label_80197F98;
    case 0x80197F9Cu: goto label_80197F9C;
    case 0x80197FA0u: goto label_80197FA0;
    case 0x80197FA4u: goto label_80197FA4;
    case 0x80197FA8u: goto label_80197FA8;
    case 0x80197FACu: goto label_80197FAC;
    case 0x80197FB0u: goto label_80197FB0;
    case 0x80197FB4u: goto label_80197FB4;
    case 0x80197FB8u: goto label_80197FB8;
    case 0x80197FBCu: goto label_80197FBC;
    case 0x80197FC0u: goto label_80197FC0;
    case 0x80197FC4u: goto label_80197FC4;
    case 0x80197FC8u: goto label_80197FC8;
    case 0x80197FCCu: goto label_80197FCC;
    case 0x80197FD0u: goto label_80197FD0;
    case 0x80197FD4u: goto label_80197FD4;
    case 0x80197FD8u: goto label_80197FD8;
    case 0x80197FDCu: goto label_80197FDC;
    case 0x80197FE0u: goto label_80197FE0;
    case 0x80197FE4u: goto label_80197FE4;
    case 0x80197FE8u: goto label_80197FE8;
    case 0x80197FECu: goto label_80197FEC;
    case 0x80197FF0u: goto label_80197FF0;
    case 0x80197FF4u: goto label_80197FF4;
    case 0x80197FF8u: goto label_80197FF8;
    case 0x80197FFCu: goto label_80197FFC;
    case 0x80198000u: goto label_80198000;
    case 0x80198004u: goto label_80198004;
    case 0x80198008u: goto label_80198008;
    case 0x8019800Cu: goto label_8019800C;
    case 0x80198010u: goto label_80198010;
    case 0x80198014u: goto label_80198014;
    case 0x80198018u: goto label_80198018;
    case 0x8019801Cu: goto label_8019801C;
    case 0x80198020u: goto label_80198020;
    case 0x80198024u: goto label_80198024;
    case 0x80198028u: goto label_80198028;
    case 0x8019802Cu: goto label_8019802C;
    case 0x80198030u: goto label_80198030;
    case 0x80198034u: goto label_80198034;
    case 0x80198038u: goto label_80198038;
    case 0x8019803Cu: goto label_8019803C;
    case 0x80198040u: goto label_80198040;
    case 0x80198044u: goto label_80198044;
    case 0x80198048u: goto label_80198048;
    case 0x8019804Cu: goto label_8019804C;
    case 0x80198050u: goto label_80198050;
    case 0x80198054u: goto label_80198054;
    case 0x80198058u: goto label_80198058;
    case 0x8019805Cu: goto label_8019805C;
    case 0x80198060u: goto label_80198060;
    case 0x80198064u: goto label_80198064;
    case 0x80198068u: goto label_80198068;
    case 0x8019806Cu: goto label_8019806C;
    case 0x80198070u: goto label_80198070;
    case 0x80198074u: goto label_80198074;
    case 0x80198078u: goto label_80198078;
    case 0x8019807Cu: goto label_8019807C;
    case 0x80198080u: goto label_80198080;
    case 0x80198084u: goto label_80198084;
    case 0x80198088u: goto label_80198088;
    case 0x8019808Cu: goto label_8019808C;
    case 0x80198090u: goto label_80198090;
    case 0x80198094u: goto label_80198094;
    case 0x80198098u: goto label_80198098;
    case 0x8019809Cu: goto label_8019809C;
    case 0x801980A0u: goto label_801980A0;
    case 0x801980A4u: goto label_801980A4;
    case 0x801980A8u: goto label_801980A8;
    case 0x801980ACu: goto label_801980AC;
    case 0x801980B0u: goto label_801980B0;
    case 0x801980B4u: goto label_801980B4;
    case 0x801980B8u: goto label_801980B8;
    case 0x801980BCu: goto label_801980BC;
    case 0x801980C0u: goto label_801980C0;
    case 0x801980C4u: goto label_801980C4;
    case 0x801980C8u: goto label_801980C8;
    case 0x801980CCu: goto label_801980CC;
    case 0x801980D0u: goto label_801980D0;
    case 0x801980D4u: goto label_801980D4;
    case 0x801980D8u: goto label_801980D8;
    case 0x801980DCu: goto label_801980DC;
    case 0x801980E0u: goto label_801980E0;
    case 0x801980E4u: goto label_801980E4;
    case 0x801980E8u: goto label_801980E8;
    case 0x801980ECu: goto label_801980EC;
    case 0x801980F0u: goto label_801980F0;
    case 0x801980F4u: goto label_801980F4;
    case 0x801980F8u: goto label_801980F8;
    case 0x801980FCu: goto label_801980FC;
    case 0x80198100u: goto label_80198100;
    case 0x80198104u: goto label_80198104;
    case 0x80198108u: goto label_80198108;
    case 0x8019810Cu: goto label_8019810C;
    case 0x80198110u: goto label_80198110;
    case 0x80198114u: goto label_80198114;
    case 0x80198118u: goto label_80198118;
    case 0x8019811Cu: goto label_8019811C;
    case 0x80198120u: goto label_80198120;
    case 0x80198124u: goto label_80198124;
    case 0x80198128u: goto label_80198128;
    case 0x8019812Cu: goto label_8019812C;
    case 0x80198130u: goto label_80198130;
    case 0x80198134u: goto label_80198134;
    case 0x80198138u: goto label_80198138;
    case 0x8019813Cu: goto label_8019813C;
    case 0x80198140u: goto label_80198140;
    case 0x80198144u: goto label_80198144;
    case 0x80198148u: goto label_80198148;
    case 0x8019814Cu: goto label_8019814C;
    case 0x80198150u: goto label_80198150;
    case 0x80198154u: goto label_80198154;
    case 0x80198158u: goto label_80198158;
    case 0x8019815Cu: goto label_8019815C;
    case 0x80198160u: goto label_80198160;
    case 0x80198164u: goto label_80198164;
    case 0x80198168u: goto label_80198168;
    case 0x8019816Cu: goto label_8019816C;
    case 0x80198170u: goto label_80198170;
    case 0x80198174u: goto label_80198174;
    case 0x80198178u: goto label_80198178;
    case 0x8019817Cu: goto label_8019817C;
    case 0x80198180u: goto label_80198180;
    case 0x80198184u: goto label_80198184;
    case 0x80198188u: goto label_80198188;
    case 0x8019818Cu: goto label_8019818C;
    case 0x80198190u: goto label_80198190;
    case 0x80198194u: goto label_80198194;
    case 0x80198198u: goto label_80198198;
    case 0x8019819Cu: goto label_8019819C;
    case 0x801981A0u: goto label_801981A0;
    case 0x801981A4u: goto label_801981A4;
    case 0x801981A8u: goto label_801981A8;
    case 0x801981ACu: goto label_801981AC;
    case 0x801981B0u: goto label_801981B0;
    case 0x801981B4u: goto label_801981B4;
    case 0x801981B8u: goto label_801981B8;
    case 0x801981BCu: goto label_801981BC;
    case 0x801981C0u: goto label_801981C0;
    case 0x801981C4u: goto label_801981C4;
    case 0x801981C8u: goto label_801981C8;
    case 0x801981CCu: goto label_801981CC;
    case 0x801981D0u: goto label_801981D0;
    case 0x801981D4u: goto label_801981D4;
    case 0x801981D8u: goto label_801981D8;
    case 0x801981DCu: goto label_801981DC;
    case 0x801981E0u: goto label_801981E0;
    case 0x801981E4u: goto label_801981E4;
    case 0x801981E8u: goto label_801981E8;
    case 0x801981ECu: goto label_801981EC;
    case 0x801981F0u: goto label_801981F0;
    case 0x801981F4u: goto label_801981F4;
    case 0x801981F8u: goto label_801981F8;
    case 0x801981FCu: goto label_801981FC;
    case 0x80198200u: goto label_80198200;
    case 0x80198204u: goto label_80198204;
    case 0x80198208u: goto label_80198208;
    case 0x8019820Cu: goto label_8019820C;
    case 0x80198210u: goto label_80198210;
    case 0x80198214u: goto label_80198214;
    case 0x80198218u: goto label_80198218;
    case 0x8019821Cu: goto label_8019821C;
    case 0x80198220u: goto label_80198220;
    case 0x80198224u: goto label_80198224;
    case 0x80198228u: goto label_80198228;
    case 0x8019822Cu: goto label_8019822C;
    case 0x80198230u: goto label_80198230;
    case 0x80198234u: goto label_80198234;
    case 0x80198238u: goto label_80198238;
    case 0x8019823Cu: goto label_8019823C;
    case 0x80198240u: goto label_80198240;
    case 0x80198244u: goto label_80198244;
    case 0x80198248u: goto label_80198248;
    case 0x8019824Cu: goto label_8019824C;
    case 0x80198250u: goto label_80198250;
    case 0x80198254u: goto label_80198254;
    case 0x80198258u: goto label_80198258;
    case 0x8019825Cu: goto label_8019825C;
    case 0x80198260u: goto label_80198260;
    case 0x80198264u: goto label_80198264;
    case 0x80198268u: goto label_80198268;
    case 0x8019826Cu: goto label_8019826C;
    case 0x80198270u: goto label_80198270;
    case 0x80198274u: goto label_80198274;
    case 0x80198278u: goto label_80198278;
    case 0x8019827Cu: goto label_8019827C;
    case 0x80198280u: goto label_80198280;
    case 0x80198284u: goto label_80198284;
    case 0x80198288u: goto label_80198288;
    case 0x8019828Cu: goto label_8019828C;
    case 0x80198290u: goto label_80198290;
    case 0x80198294u: goto label_80198294;
    case 0x80198298u: goto label_80198298;
    case 0x8019829Cu: goto label_8019829C;
    case 0x801982A0u: goto label_801982A0;
    case 0x801982A4u: goto label_801982A4;
    case 0x801982A8u: goto label_801982A8;
    case 0x801982ACu: goto label_801982AC;
    case 0x801982B0u: goto label_801982B0;
    case 0x801982B4u: goto label_801982B4;
    case 0x801982B8u: goto label_801982B8;
    case 0x801982BCu: goto label_801982BC;
    case 0x801982C0u: goto label_801982C0;
    case 0x801982C4u: goto label_801982C4;
    case 0x801982C8u: goto label_801982C8;
    case 0x801982CCu: goto label_801982CC;
    case 0x801982D0u: goto label_801982D0;
    case 0x801982D4u: goto label_801982D4;
    case 0x801982D8u: goto label_801982D8;
    case 0x801982DCu: goto label_801982DC;
    case 0x801982E0u: goto label_801982E0;
    case 0x801982E4u: goto label_801982E4;
    case 0x801982E8u: goto label_801982E8;
    case 0x801982ECu: goto label_801982EC;
    case 0x801982F0u: goto label_801982F0;
    case 0x801982F4u: goto label_801982F4;
    case 0x801982F8u: goto label_801982F8;
    case 0x801982FCu: goto label_801982FC;
    case 0x80198300u: goto label_80198300;
    case 0x80198304u: goto label_80198304;
    case 0x80198308u: goto label_80198308;
    case 0x8019830Cu: goto label_8019830C;
    case 0x80198310u: goto label_80198310;
    case 0x80198314u: goto label_80198314;
    case 0x80198318u: goto label_80198318;
    case 0x8019831Cu: goto label_8019831C;
    case 0x80198320u: goto label_80198320;
    case 0x80198324u: goto label_80198324;
    case 0x80198328u: goto label_80198328;
    case 0x8019832Cu: goto label_8019832C;
    case 0x80198330u: goto label_80198330;
    case 0x80198334u: goto label_80198334;
    case 0x80198338u: goto label_80198338;
    case 0x8019833Cu: goto label_8019833C;
    case 0x80198340u: goto label_80198340;
    case 0x80198344u: goto label_80198344;
    case 0x80198348u: goto label_80198348;
    case 0x8019834Cu: goto label_8019834C;
    case 0x80198350u: goto label_80198350;
    case 0x80198354u: goto label_80198354;
    case 0x80198358u: goto label_80198358;
    case 0x8019835Cu: goto label_8019835C;
    case 0x80198360u: goto label_80198360;
    case 0x80198364u: goto label_80198364;
    case 0x80198368u: goto label_80198368;
    case 0x8019836Cu: goto label_8019836C;
    case 0x80198370u: goto label_80198370;
    case 0x80198374u: goto label_80198374;
    case 0x80198378u: goto label_80198378;
    case 0x8019837Cu: goto label_8019837C;
    case 0x80198380u: goto label_80198380;
    case 0x80198384u: goto label_80198384;
    case 0x80198388u: goto label_80198388;
    case 0x8019838Cu: goto label_8019838C;
    case 0x80198390u: goto label_80198390;
    case 0x80198394u: goto label_80198394;
    case 0x80198398u: goto label_80198398;
    case 0x8019839Cu: goto label_8019839C;
    case 0x801983A0u: goto label_801983A0;
    case 0x801983A4u: goto label_801983A4;
    case 0x801983A8u: goto label_801983A8;
    case 0x801983ACu: goto label_801983AC;
    case 0x801983B0u: goto label_801983B0;
    case 0x801983B4u: goto label_801983B4;
    case 0x801983B8u: goto label_801983B8;
    case 0x801983BCu: goto label_801983BC;
    case 0x801983C0u: goto label_801983C0;
    case 0x801983C4u: goto label_801983C4;
    case 0x801983C8u: goto label_801983C8;
    case 0x801983CCu: goto label_801983CC;
    case 0x801983D0u: goto label_801983D0;
    case 0x801983D4u: goto label_801983D4;
    case 0x801983D8u: goto label_801983D8;
    case 0x801983DCu: goto label_801983DC;
    case 0x801983E0u: goto label_801983E0;
    case 0x801983E4u: goto label_801983E4;
    case 0x801983E8u: goto label_801983E8;
    case 0x801983ECu: goto label_801983EC;
    case 0x801983F0u: goto label_801983F0;
    case 0x801983F4u: goto label_801983F4;
    case 0x801983F8u: goto label_801983F8;
    case 0x801983FCu: goto label_801983FC;
    case 0x80198400u: goto label_80198400;
    case 0x80198404u: goto label_80198404;
    case 0x80198408u: goto label_80198408;
    case 0x8019840Cu: goto label_8019840C;
    case 0x80198410u: goto label_80198410;
    case 0x80198414u: goto label_80198414;
    case 0x80198418u: goto label_80198418;
    case 0x8019841Cu: goto label_8019841C;
    case 0x80198420u: goto label_80198420;
    case 0x80198424u: goto label_80198424;
    case 0x80198428u: goto label_80198428;
    case 0x8019842Cu: goto label_8019842C;
    case 0x80198430u: goto label_80198430;
    case 0x80198434u: goto label_80198434;
    case 0x80198438u: goto label_80198438;
    case 0x8019843Cu: goto label_8019843C;
    case 0x80198440u: goto label_80198440;
    case 0x80198444u: goto label_80198444;
    case 0x80198448u: goto label_80198448;
    case 0x8019844Cu: goto label_8019844C;
    case 0x80198450u: goto label_80198450;
    case 0x80198454u: goto label_80198454;
    case 0x80198458u: goto label_80198458;
    case 0x8019845Cu: goto label_8019845C;
    case 0x80198460u: goto label_80198460;
    case 0x80198464u: goto label_80198464;
    case 0x80198468u: goto label_80198468;
    case 0x8019846Cu: goto label_8019846C;
    case 0x80198470u: goto label_80198470;
    case 0x80198474u: goto label_80198474;
    case 0x80198478u: goto label_80198478;
    case 0x8019847Cu: goto label_8019847C;
    case 0x80198480u: goto label_80198480;
    case 0x80198484u: goto label_80198484;
    case 0x80198488u: goto label_80198488;
    case 0x8019848Cu: goto label_8019848C;
    case 0x80198490u: goto label_80198490;
    case 0x80198494u: goto label_80198494;
    case 0x80198498u: goto label_80198498;
    case 0x8019849Cu: goto label_8019849C;
    case 0x801984A0u: goto label_801984A0;
    case 0x801984A4u: goto label_801984A4;
    case 0x801984A8u: goto label_801984A8;
    case 0x801984ACu: goto label_801984AC;
    case 0x801984B0u: goto label_801984B0;
    case 0x801984B4u: goto label_801984B4;
    case 0x801984B8u: goto label_801984B8;
    case 0x801984BCu: goto label_801984BC;
    case 0x801984C0u: goto label_801984C0;
    case 0x801984C4u: goto label_801984C4;
    case 0x801984C8u: goto label_801984C8;
    case 0x801984CCu: goto label_801984CC;
    case 0x801984D0u: goto label_801984D0;
    case 0x801984D4u: goto label_801984D4;
    case 0x801984D8u: goto label_801984D8;
    case 0x801984DCu: goto label_801984DC;
    case 0x801984E0u: goto label_801984E0;
    case 0x801984E4u: goto label_801984E4;
    case 0x801984E8u: goto label_801984E8;
    case 0x801984ECu: goto label_801984EC;
    case 0x801984F0u: goto label_801984F0;
    case 0x801984F4u: goto label_801984F4;
    case 0x801984F8u: goto label_801984F8;
    case 0x801984FCu: goto label_801984FC;
    case 0x80198500u: goto label_80198500;
    case 0x80198504u: goto label_80198504;
    case 0x80198508u: goto label_80198508;
    case 0x8019850Cu: goto label_8019850C;
    case 0x80198510u: goto label_80198510;
    case 0x80198514u: goto label_80198514;
    case 0x80198518u: goto label_80198518;
    case 0x8019851Cu: goto label_8019851C;
    case 0x80198520u: goto label_80198520;
    case 0x80198524u: goto label_80198524;
    case 0x80198528u: goto label_80198528;
    case 0x8019852Cu: goto label_8019852C;
    case 0x80198530u: goto label_80198530;
    case 0x80198534u: goto label_80198534;
    case 0x80198538u: goto label_80198538;
    case 0x8019853Cu: goto label_8019853C;
    case 0x80198540u: goto label_80198540;
    case 0x80198544u: goto label_80198544;
    case 0x80198548u: goto label_80198548;
    case 0x8019854Cu: goto label_8019854C;
    case 0x80198550u: goto label_80198550;
    case 0x80198554u: goto label_80198554;
    case 0x80198558u: goto label_80198558;
    case 0x8019855Cu: goto label_8019855C;
    case 0x80198560u: goto label_80198560;
    case 0x80198564u: goto label_80198564;
    case 0x80198568u: goto label_80198568;
    case 0x8019856Cu: goto label_8019856C;
    case 0x80198570u: goto label_80198570;
    case 0x80198574u: goto label_80198574;
    case 0x80198578u: goto label_80198578;
    case 0x8019857Cu: goto label_8019857C;
    case 0x80198580u: goto label_80198580;
    case 0x80198584u: goto label_80198584;
    case 0x80198588u: goto label_80198588;
    case 0x8019858Cu: goto label_8019858C;
    case 0x80198590u: goto label_80198590;
    case 0x80198594u: goto label_80198594;
    case 0x80198598u: goto label_80198598;
    case 0x8019859Cu: goto label_8019859C;
    case 0x801985A0u: goto label_801985A0;
    case 0x801985A4u: goto label_801985A4;
    case 0x801985A8u: goto label_801985A8;
    case 0x801985ACu: goto label_801985AC;
    case 0x801985B0u: goto label_801985B0;
    case 0x801985B4u: goto label_801985B4;
    case 0x801985B8u: goto label_801985B8;
    case 0x801985BCu: goto label_801985BC;
    case 0x801985C0u: goto label_801985C0;
    case 0x801985C4u: goto label_801985C4;
    case 0x801985C8u: goto label_801985C8;
    case 0x801985CCu: goto label_801985CC;
    case 0x801985D0u: goto label_801985D0;
    case 0x801985D4u: goto label_801985D4;
    case 0x801985D8u: goto label_801985D8;
    case 0x801985DCu: goto label_801985DC;
    case 0x801985E0u: goto label_801985E0;
    case 0x801985E4u: goto label_801985E4;
    case 0x801985E8u: goto label_801985E8;
    case 0x801985ECu: goto label_801985EC;
    case 0x801985F0u: goto label_801985F0;
    case 0x801985F4u: goto label_801985F4;
    case 0x801985F8u: goto label_801985F8;
    case 0x801985FCu: goto label_801985FC;
    case 0x80198600u: goto label_80198600;
    case 0x80198604u: goto label_80198604;
    case 0x80198608u: goto label_80198608;
    case 0x8019860Cu: goto label_8019860C;
    case 0x80198610u: goto label_80198610;
    case 0x80198614u: goto label_80198614;
    case 0x80198618u: goto label_80198618;
    case 0x8019861Cu: goto label_8019861C;
    case 0x80198620u: goto label_80198620;
    case 0x80198624u: goto label_80198624;
    case 0x80198628u: goto label_80198628;
    case 0x8019862Cu: goto label_8019862C;
    case 0x80198630u: goto label_80198630;
    case 0x80198634u: goto label_80198634;
    case 0x80198638u: goto label_80198638;
    case 0x8019863Cu: goto label_8019863C;
    case 0x80198640u: goto label_80198640;
    case 0x80198644u: goto label_80198644;
    case 0x80198648u: goto label_80198648;
    case 0x8019864Cu: goto label_8019864C;
    case 0x80198650u: goto label_80198650;
    case 0x80198654u: goto label_80198654;
    case 0x80198658u: goto label_80198658;
    case 0x8019865Cu: goto label_8019865C;
    case 0x80198660u: goto label_80198660;
    case 0x80198664u: goto label_80198664;
    case 0x80198668u: goto label_80198668;
    case 0x8019866Cu: goto label_8019866C;
    case 0x80198670u: goto label_80198670;
    case 0x80198674u: goto label_80198674;
    case 0x80198678u: goto label_80198678;
    case 0x8019867Cu: goto label_8019867C;
    case 0x80198680u: goto label_80198680;
    case 0x80198684u: goto label_80198684;
    case 0x80198688u: goto label_80198688;
    case 0x8019868Cu: goto label_8019868C;
    case 0x80198690u: goto label_80198690;
    case 0x80198694u: goto label_80198694;
    case 0x80198698u: goto label_80198698;
    case 0x8019869Cu: goto label_8019869C;
    case 0x801986A0u: goto label_801986A0;
    case 0x801986A4u: goto label_801986A4;
    case 0x801986A8u: goto label_801986A8;
    case 0x801986ACu: goto label_801986AC;
    case 0x801986B0u: goto label_801986B0;
    case 0x801986B4u: goto label_801986B4;
    case 0x801986B8u: goto label_801986B8;
    case 0x801986BCu: goto label_801986BC;
    case 0x801986C0u: goto label_801986C0;
    case 0x801986C4u: goto label_801986C4;
    case 0x801986C8u: goto label_801986C8;
    case 0x801986CCu: goto label_801986CC;
    case 0x801986D0u: goto label_801986D0;
    case 0x801986D4u: goto label_801986D4;
    case 0x801986D8u: goto label_801986D8;
    case 0x801986DCu: goto label_801986DC;
    case 0x801986E0u: goto label_801986E0;
    case 0x801986E4u: goto label_801986E4;
    case 0x801986E8u: goto label_801986E8;
    case 0x801986ECu: goto label_801986EC;
    case 0x801986F0u: goto label_801986F0;
    case 0x801986F4u: goto label_801986F4;
    case 0x801986F8u: goto label_801986F8;
    case 0x801986FCu: goto label_801986FC;
    case 0x80198700u: goto label_80198700;
    case 0x80198704u: goto label_80198704;
    case 0x80198708u: goto label_80198708;
    case 0x8019870Cu: goto label_8019870C;
    case 0x80198710u: goto label_80198710;
    case 0x80198714u: goto label_80198714;
    case 0x80198718u: goto label_80198718;
    case 0x8019871Cu: goto label_8019871C;
    case 0x80198720u: goto label_80198720;
    case 0x80198724u: goto label_80198724;
    case 0x80198728u: goto label_80198728;
    case 0x8019872Cu: goto label_8019872C;
    case 0x80198730u: goto label_80198730;
    case 0x80198734u: goto label_80198734;
    case 0x80198738u: goto label_80198738;
    case 0x8019873Cu: goto label_8019873C;
    case 0x80198740u: goto label_80198740;
    case 0x80198744u: goto label_80198744;
    case 0x80198748u: goto label_80198748;
    case 0x8019874Cu: goto label_8019874C;
    case 0x80198750u: goto label_80198750;
    case 0x80198754u: goto label_80198754;
    case 0x80198758u: goto label_80198758;
    case 0x8019875Cu: goto label_8019875C;
    case 0x80198760u: goto label_80198760;
    case 0x80198764u: goto label_80198764;
    case 0x80198768u: goto label_80198768;
    case 0x8019876Cu: goto label_8019876C;
    case 0x80198770u: goto label_80198770;
    case 0x80198774u: goto label_80198774;
    case 0x80198778u: goto label_80198778;
    case 0x8019877Cu: goto label_8019877C;
    case 0x80198780u: goto label_80198780;
    case 0x80198784u: goto label_80198784;
    case 0x80198788u: goto label_80198788;
    case 0x8019878Cu: goto label_8019878C;
    case 0x80198790u: goto label_80198790;
    case 0x80198794u: goto label_80198794;
    case 0x80198798u: goto label_80198798;
    case 0x8019879Cu: goto label_8019879C;
    case 0x801987A0u: goto label_801987A0;
    case 0x801987A4u: goto label_801987A4;
    case 0x801987A8u: goto label_801987A8;
    case 0x801987ACu: goto label_801987AC;
    case 0x801987B0u: goto label_801987B0;
    case 0x801987B4u: goto label_801987B4;
    case 0x801987B8u: goto label_801987B8;
    case 0x801987BCu: goto label_801987BC;
    case 0x801987C0u: goto label_801987C0;
    case 0x801987C4u: goto label_801987C4;
    case 0x801987C8u: goto label_801987C8;
    case 0x801987CCu: goto label_801987CC;
    case 0x801987D0u: goto label_801987D0;
    case 0x801987D4u: goto label_801987D4;
    case 0x801987D8u: goto label_801987D8;
    case 0x801987DCu: goto label_801987DC;
    case 0x801987E0u: goto label_801987E0;
    case 0x801987E4u: goto label_801987E4;
    case 0x801987E8u: goto label_801987E8;
    case 0x801987ECu: goto label_801987EC;
    case 0x801987F0u: goto label_801987F0;
    case 0x801987F4u: goto label_801987F4;
    case 0x801987F8u: goto label_801987F8;
    case 0x801987FCu: goto label_801987FC;
    case 0x80198800u: goto label_80198800;
    case 0x80198804u: goto label_80198804;
    case 0x80198808u: goto label_80198808;
    case 0x8019880Cu: goto label_8019880C;
    case 0x80198810u: goto label_80198810;
    case 0x80198814u: goto label_80198814;
    case 0x80198818u: goto label_80198818;
    case 0x8019881Cu: goto label_8019881C;
    case 0x80198820u: goto label_80198820;
    case 0x80198824u: goto label_80198824;
    case 0x80198828u: goto label_80198828;
    case 0x8019882Cu: goto label_8019882C;
    case 0x80198830u: goto label_80198830;
    case 0x80198834u: goto label_80198834;
    case 0x80198838u: goto label_80198838;
    case 0x8019883Cu: goto label_8019883C;
    case 0x80198840u: goto label_80198840;
    case 0x80198844u: goto label_80198844;
    case 0x80198848u: goto label_80198848;
    case 0x8019884Cu: goto label_8019884C;
    case 0x80198850u: goto label_80198850;
    case 0x80198854u: goto label_80198854;
    case 0x80198858u: goto label_80198858;
    case 0x8019885Cu: goto label_8019885C;
    case 0x80198860u: goto label_80198860;
    case 0x80198864u: goto label_80198864;
    case 0x80198868u: goto label_80198868;
    case 0x8019886Cu: goto label_8019886C;
    case 0x80198870u: goto label_80198870;
    case 0x80198874u: goto label_80198874;
    case 0x80198878u: goto label_80198878;
    case 0x8019887Cu: goto label_8019887C;
    case 0x80198880u: goto label_80198880;
    case 0x80198884u: goto label_80198884;
    case 0x80198888u: goto label_80198888;
    case 0x8019888Cu: goto label_8019888C;
    case 0x80198890u: goto label_80198890;
    case 0x80198894u: goto label_80198894;
    case 0x80198898u: goto label_80198898;
    case 0x8019889Cu: goto label_8019889C;
    case 0x801988A0u: goto label_801988A0;
    case 0x801988A4u: goto label_801988A4;
    case 0x801988A8u: goto label_801988A8;
    case 0x801988ACu: goto label_801988AC;
    case 0x801988B0u: goto label_801988B0;
    case 0x801988B4u: goto label_801988B4;
    case 0x801988B8u: goto label_801988B8;
    case 0x801988BCu: goto label_801988BC;
    case 0x801988C0u: goto label_801988C0;
    case 0x801988C4u: goto label_801988C4;
    case 0x801988C8u: goto label_801988C8;
    case 0x801988CCu: goto label_801988CC;
    case 0x801988D0u: goto label_801988D0;
    case 0x801988D4u: goto label_801988D4;
    case 0x801988D8u: goto label_801988D8;
    case 0x801988DCu: goto label_801988DC;
    case 0x801988E0u: goto label_801988E0;
    case 0x801988E4u: goto label_801988E4;
    case 0x801988E8u: goto label_801988E8;
    case 0x801988ECu: goto label_801988EC;
    case 0x801988F0u: goto label_801988F0;
    case 0x801988F4u: goto label_801988F4;
    case 0x801988F8u: goto label_801988F8;
    case 0x801988FCu: goto label_801988FC;
    case 0x80198900u: goto label_80198900;
    case 0x80198904u: goto label_80198904;
    case 0x80198908u: goto label_80198908;
    case 0x8019890Cu: goto label_8019890C;
    case 0x80198910u: goto label_80198910;
    case 0x80198914u: goto label_80198914;
    case 0x80198918u: goto label_80198918;
    case 0x8019891Cu: goto label_8019891C;
    case 0x80198920u: goto label_80198920;
    case 0x80198924u: goto label_80198924;
    case 0x80198928u: goto label_80198928;
    case 0x8019892Cu: goto label_8019892C;
    case 0x80198930u: goto label_80198930;
    case 0x80198934u: goto label_80198934;
    case 0x80198938u: goto label_80198938;
    case 0x8019893Cu: goto label_8019893C;
    case 0x80198940u: goto label_80198940;
    case 0x80198944u: goto label_80198944;
    case 0x80198948u: goto label_80198948;
    case 0x8019894Cu: goto label_8019894C;
    case 0x80198950u: goto label_80198950;
    case 0x80198954u: goto label_80198954;
    case 0x80198958u: goto label_80198958;
    case 0x8019895Cu: goto label_8019895C;
    case 0x80198960u: goto label_80198960;
    case 0x80198964u: goto label_80198964;
    case 0x80198968u: goto label_80198968;
    case 0x8019896Cu: goto label_8019896C;
    case 0x80198970u: goto label_80198970;
    case 0x80198974u: goto label_80198974;
    case 0x80198978u: goto label_80198978;
    case 0x8019897Cu: goto label_8019897C;
    case 0x80198980u: goto label_80198980;
    case 0x80198984u: goto label_80198984;
    case 0x80198988u: goto label_80198988;
    case 0x8019898Cu: goto label_8019898C;
    case 0x80198990u: goto label_80198990;
    case 0x80198994u: goto label_80198994;
    case 0x80198998u: goto label_80198998;
    case 0x8019899Cu: goto label_8019899C;
    case 0x801989A0u: goto label_801989A0;
    case 0x801989A4u: goto label_801989A4;
    case 0x801989A8u: goto label_801989A8;
    case 0x801989ACu: goto label_801989AC;
    case 0x801989B0u: goto label_801989B0;
    case 0x801989B4u: goto label_801989B4;
    case 0x801989B8u: goto label_801989B8;
    case 0x801989BCu: goto label_801989BC;
    case 0x801989C0u: goto label_801989C0;
    case 0x801989C4u: goto label_801989C4;
    case 0x801989C8u: goto label_801989C8;
    case 0x801989CCu: goto label_801989CC;
    case 0x801989D0u: goto label_801989D0;
    case 0x801989D4u: goto label_801989D4;
    case 0x801989D8u: goto label_801989D8;
    case 0x801989DCu: goto label_801989DC;
    case 0x801989E0u: goto label_801989E0;
    case 0x801989E4u: goto label_801989E4;
    case 0x801989E8u: goto label_801989E8;
    case 0x801989ECu: goto label_801989EC;
    case 0x801989F0u: goto label_801989F0;
    case 0x801989F4u: goto label_801989F4;
    case 0x801989F8u: goto label_801989F8;
    case 0x801989FCu: goto label_801989FC;
    case 0x80198A00u: goto label_80198A00;
    case 0x80198A04u: goto label_80198A04;
    case 0x80198A08u: goto label_80198A08;
    case 0x80198A0Cu: goto label_80198A0C;
    case 0x80198A10u: goto label_80198A10;
    case 0x80198A14u: goto label_80198A14;
    case 0x80198A18u: goto label_80198A18;
    case 0x80198A1Cu: goto label_80198A1C;
    case 0x80198A20u: goto label_80198A20;
    case 0x80198A24u: goto label_80198A24;
    case 0x80198A28u: goto label_80198A28;
    case 0x80198A2Cu: goto label_80198A2C;
    case 0x80198A30u: goto label_80198A30;
    case 0x80198A34u: goto label_80198A34;
    case 0x80198A38u: goto label_80198A38;
    case 0x80198A3Cu: goto label_80198A3C;
    case 0x80198A40u: goto label_80198A40;
    case 0x80198A44u: goto label_80198A44;
    case 0x80198A48u: goto label_80198A48;
    case 0x80198A4Cu: goto label_80198A4C;
    case 0x80198A50u: goto label_80198A50;
    case 0x80198A54u: goto label_80198A54;
    case 0x80198A58u: goto label_80198A58;
    case 0x80198A5Cu: goto label_80198A5C;
    case 0x80198A60u: goto label_80198A60;
    case 0x80198A64u: goto label_80198A64;
    case 0x80198A68u: goto label_80198A68;
    case 0x80198A6Cu: goto label_80198A6C;
    case 0x80198A70u: goto label_80198A70;
    case 0x80198A74u: goto label_80198A74;
    case 0x80198A78u: goto label_80198A78;
    case 0x80198A7Cu: goto label_80198A7C;
    case 0x80198A80u: goto label_80198A80;
    case 0x80198A84u: goto label_80198A84;
    case 0x80198A88u: goto label_80198A88;
    case 0x80198A8Cu: goto label_80198A8C;
    case 0x80198A90u: goto label_80198A90;
    case 0x80198A94u: goto label_80198A94;
    case 0x80198A98u: goto label_80198A98;
    case 0x80198A9Cu: goto label_80198A9C;
    case 0x80198AA0u: goto label_80198AA0;
    case 0x80198AA4u: goto label_80198AA4;
    case 0x80198AA8u: goto label_80198AA8;
    case 0x80198AACu: goto label_80198AAC;
    case 0x80198AB0u: goto label_80198AB0;
    case 0x80198AB4u: goto label_80198AB4;
    case 0x80198AB8u: goto label_80198AB8;
    case 0x80198ABCu: goto label_80198ABC;
    case 0x80198AC0u: goto label_80198AC0;
    case 0x80198AC4u: goto label_80198AC4;
    case 0x80198AC8u: goto label_80198AC8;
    case 0x80198ACCu: goto label_80198ACC;
    case 0x80198AD0u: goto label_80198AD0;
    case 0x80198AD4u: goto label_80198AD4;
    case 0x80198AD8u: goto label_80198AD8;
    case 0x80198ADCu: goto label_80198ADC;
    case 0x80198AE0u: goto label_80198AE0;
    case 0x80198AE4u: goto label_80198AE4;
    case 0x80198AE8u: goto label_80198AE8;
    case 0x80198AECu: goto label_80198AEC;
    case 0x80198AF0u: goto label_80198AF0;
    case 0x80198AF4u: goto label_80198AF4;
    case 0x80198AF8u: goto label_80198AF8;
    case 0x80198AFCu: goto label_80198AFC;
    case 0x80198B00u: goto label_80198B00;
    case 0x80198B04u: goto label_80198B04;
    case 0x80198B08u: goto label_80198B08;
    case 0x80198B0Cu: goto label_80198B0C;
    case 0x80198B10u: goto label_80198B10;
    case 0x80198B14u: goto label_80198B14;
    case 0x80198B18u: goto label_80198B18;
    case 0x80198B1Cu: goto label_80198B1C;
    case 0x80198B20u: goto label_80198B20;
    case 0x80198B24u: goto label_80198B24;
    case 0x80198B28u: goto label_80198B28;
    case 0x80198B2Cu: goto label_80198B2C;
    case 0x80198B30u: goto label_80198B30;
    case 0x80198B34u: goto label_80198B34;
    case 0x80198B38u: goto label_80198B38;
    case 0x80198B3Cu: goto label_80198B3C;
    case 0x80198B40u: goto label_80198B40;
    case 0x80198B44u: goto label_80198B44;
    case 0x80198B48u: goto label_80198B48;
    case 0x80198B4Cu: goto label_80198B4C;
    case 0x80198B50u: goto label_80198B50;
    case 0x80198B54u: goto label_80198B54;
    case 0x80198B58u: goto label_80198B58;
    case 0x80198B5Cu: goto label_80198B5C;
    case 0x80198B60u: goto label_80198B60;
    case 0x80198B64u: goto label_80198B64;
    case 0x80198B68u: goto label_80198B68;
    case 0x80198B6Cu: goto label_80198B6C;
    case 0x80198B70u: goto label_80198B70;
    case 0x80198B74u: goto label_80198B74;
    case 0x80198B78u: goto label_80198B78;
    case 0x80198B7Cu: goto label_80198B7C;
    case 0x80198B80u: goto label_80198B80;
    case 0x80198B84u: goto label_80198B84;
    case 0x80198B88u: goto label_80198B88;
    case 0x80198B8Cu: goto label_80198B8C;
    case 0x80198B90u: goto label_80198B90;
    case 0x80198B94u: goto label_80198B94;
    case 0x80198B98u: goto label_80198B98;
    case 0x80198B9Cu: goto label_80198B9C;
    case 0x80198BA0u: goto label_80198BA0;
    case 0x80198BA4u: goto label_80198BA4;
    case 0x80198BA8u: goto label_80198BA8;
    case 0x80198BACu: goto label_80198BAC;
    case 0x80198BB0u: goto label_80198BB0;
    case 0x80198BB4u: goto label_80198BB4;
    case 0x80198BB8u: goto label_80198BB8;
    case 0x80198BBCu: goto label_80198BBC;
    case 0x80198BC0u: goto label_80198BC0;
    case 0x80198BC4u: goto label_80198BC4;
    case 0x80198BC8u: goto label_80198BC8;
    case 0x80198BCCu: goto label_80198BCC;
    case 0x80198BD0u: goto label_80198BD0;
    case 0x80198BD4u: goto label_80198BD4;
    case 0x80198BD8u: goto label_80198BD8;
    case 0x80198BDCu: goto label_80198BDC;
    case 0x80198BE0u: goto label_80198BE0;
    case 0x80198BE4u: goto label_80198BE4;
    case 0x80198BE8u: goto label_80198BE8;
    case 0x80198BECu: goto label_80198BEC;
    case 0x80198BF0u: goto label_80198BF0;
    case 0x80198BF4u: goto label_80198BF4;
    case 0x80198BF8u: goto label_80198BF8;
    case 0x80198BFCu: goto label_80198BFC;
    case 0x80198C00u: goto label_80198C00;
    case 0x80198C04u: goto label_80198C04;
    case 0x80198C08u: goto label_80198C08;
    case 0x80198C0Cu: goto label_80198C0C;
    case 0x80198C10u: goto label_80198C10;
    case 0x80198C14u: goto label_80198C14;
    case 0x80198C18u: goto label_80198C18;
    case 0x80198C1Cu: goto label_80198C1C;
    case 0x80198C20u: goto label_80198C20;
    case 0x80198C24u: goto label_80198C24;
    case 0x80198C28u: goto label_80198C28;
    case 0x80198C2Cu: goto label_80198C2C;
    case 0x80198C30u: goto label_80198C30;
    case 0x80198C34u: goto label_80198C34;
    case 0x80198C38u: goto label_80198C38;
    case 0x80198C3Cu: goto label_80198C3C;
    case 0x80198C40u: goto label_80198C40;
    case 0x80198C44u: goto label_80198C44;
    case 0x80198C48u: goto label_80198C48;
    case 0x80198C4Cu: goto label_80198C4C;
    case 0x80198C50u: goto label_80198C50;
    case 0x80198C54u: goto label_80198C54;
    case 0x80198C58u: goto label_80198C58;
    case 0x80198C5Cu: goto label_80198C5C;
    case 0x80198C60u: goto label_80198C60;
    case 0x80198C64u: goto label_80198C64;
    case 0x80198C68u: goto label_80198C68;
    case 0x80198C6Cu: goto label_80198C6C;
    case 0x80198C70u: goto label_80198C70;
    case 0x80198C74u: goto label_80198C74;
    case 0x80198C78u: goto label_80198C78;
    case 0x80198C7Cu: goto label_80198C7C;
    case 0x80198C80u: goto label_80198C80;
    case 0x80198C84u: goto label_80198C84;
    case 0x80198C88u: goto label_80198C88;
    case 0x80198C8Cu: goto label_80198C8C;
    case 0x80198C90u: goto label_80198C90;
    case 0x80198C94u: goto label_80198C94;
    case 0x80198C98u: goto label_80198C98;
    case 0x80198C9Cu: goto label_80198C9C;
    case 0x80198CA0u: goto label_80198CA0;
    case 0x80198CA4u: goto label_80198CA4;
    case 0x80198CA8u: goto label_80198CA8;
    case 0x80198CACu: goto label_80198CAC;
    case 0x80198CB0u: goto label_80198CB0;
    case 0x80198CB4u: goto label_80198CB4;
    case 0x80198CB8u: goto label_80198CB8;
    case 0x80198CBCu: goto label_80198CBC;
    case 0x80198CC0u: goto label_80198CC0;
    case 0x80198CC4u: goto label_80198CC4;
    case 0x80198CC8u: goto label_80198CC8;
    case 0x80198CCCu: goto label_80198CCC;
    case 0x80198CD0u: goto label_80198CD0;
    case 0x80198CD4u: goto label_80198CD4;
    case 0x80198CD8u: goto label_80198CD8;
    case 0x80198CDCu: goto label_80198CDC;
    case 0x80198CE0u: goto label_80198CE0;
    case 0x80198CE4u: goto label_80198CE4;
    case 0x80198CE8u: goto label_80198CE8;
    case 0x80198CECu: goto label_80198CEC;
    case 0x80198CF0u: goto label_80198CF0;
    case 0x80198CF4u: goto label_80198CF4;
    case 0x80198CF8u: goto label_80198CF8;
    case 0x80198CFCu: goto label_80198CFC;
    case 0x80198D00u: goto label_80198D00;
    case 0x80198D04u: goto label_80198D04;
    case 0x80198D08u: goto label_80198D08;
    case 0x80198D0Cu: goto label_80198D0C;
    case 0x80198D10u: goto label_80198D10;
    case 0x80198D14u: goto label_80198D14;
    case 0x80198D18u: goto label_80198D18;
    case 0x80198D1Cu: goto label_80198D1C;
    case 0x80198D20u: goto label_80198D20;
    case 0x80198D24u: goto label_80198D24;
    case 0x80198D28u: goto label_80198D28;
    case 0x80198D2Cu: goto label_80198D2C;
    case 0x80198D30u: goto label_80198D30;
    case 0x80198D34u: goto label_80198D34;
    case 0x80198D38u: goto label_80198D38;
    case 0x80198D3Cu: goto label_80198D3C;
    case 0x80198D40u: goto label_80198D40;
    case 0x80198D44u: goto label_80198D44;
    case 0x80198D48u: goto label_80198D48;
    case 0x80198D4Cu: goto label_80198D4C;
    case 0x80198D50u: goto label_80198D50;
    case 0x80198D54u: goto label_80198D54;
    case 0x80198D58u: goto label_80198D58;
    case 0x80198D5Cu: goto label_80198D5C;
    case 0x80198D60u: goto label_80198D60;
    case 0x80198D64u: goto label_80198D64;
    case 0x80198D68u: goto label_80198D68;
    case 0x80198D6Cu: goto label_80198D6C;
    case 0x80198D70u: goto label_80198D70;
    case 0x80198D74u: goto label_80198D74;
    case 0x80198D78u: goto label_80198D78;
    case 0x80198D7Cu: goto label_80198D7C;
    case 0x80198D80u: goto label_80198D80;
    case 0x80198D84u: goto label_80198D84;
    case 0x80198D88u: goto label_80198D88;
    case 0x80198D8Cu: goto label_80198D8C;
    case 0x80198D90u: goto label_80198D90;
    case 0x80198D94u: goto label_80198D94;
    case 0x80198D98u: goto label_80198D98;
    case 0x80198D9Cu: goto label_80198D9C;
    case 0x80198DA0u: goto label_80198DA0;
    case 0x80198DA4u: goto label_80198DA4;
    case 0x80198DA8u: goto label_80198DA8;
    case 0x80198DACu: goto label_80198DAC;
    case 0x80198DB0u: goto label_80198DB0;
    case 0x80198DB4u: goto label_80198DB4;
    case 0x80198DB8u: goto label_80198DB8;
    case 0x80198DBCu: goto label_80198DBC;
    case 0x80198DC0u: goto label_80198DC0;
    case 0x80198DC4u: goto label_80198DC4;
    case 0x80198DC8u: goto label_80198DC8;
    case 0x80198DCCu: goto label_80198DCC;
    case 0x80198DD0u: goto label_80198DD0;
    case 0x80198DD4u: goto label_80198DD4;
    case 0x80198DD8u: goto label_80198DD8;
    case 0x80198DDCu: goto label_80198DDC;
    case 0x80198DE0u: goto label_80198DE0;
    case 0x80198DE4u: goto label_80198DE4;
    case 0x80198DE8u: goto label_80198DE8;
    case 0x80198DECu: goto label_80198DEC;
    case 0x80198DF0u: goto label_80198DF0;
    case 0x80198DF4u: goto label_80198DF4;
    case 0x80198DF8u: goto label_80198DF8;
    case 0x80198DFCu: goto label_80198DFC;
    case 0x80198E00u: goto label_80198E00;
    case 0x80198E04u: goto label_80198E04;
    case 0x80198E08u: goto label_80198E08;
    case 0x80198E0Cu: goto label_80198E0C;
    case 0x80198E10u: goto label_80198E10;
    case 0x80198E14u: goto label_80198E14;
    case 0x80198E18u: goto label_80198E18;
    case 0x80198E1Cu: goto label_80198E1C;
    case 0x80198E20u: goto label_80198E20;
    case 0x80198E24u: goto label_80198E24;
    case 0x80198E28u: goto label_80198E28;
    case 0x80198E2Cu: goto label_80198E2C;
    case 0x80198E30u: goto label_80198E30;
    case 0x80198E34u: goto label_80198E34;
    case 0x80198E38u: goto label_80198E38;
    case 0x80198E3Cu: goto label_80198E3C;
    case 0x80198E40u: goto label_80198E40;
    case 0x80198E44u: goto label_80198E44;
    case 0x80198E48u: goto label_80198E48;
    case 0x80198E4Cu: goto label_80198E4C;
    case 0x80198E50u: goto label_80198E50;
    case 0x80198E54u: goto label_80198E54;
    case 0x80198E58u: goto label_80198E58;
    case 0x80198E5Cu: goto label_80198E5C;
    case 0x80198E60u: goto label_80198E60;
    case 0x80198E64u: goto label_80198E64;
    case 0x80198E68u: goto label_80198E68;
    case 0x80198E6Cu: goto label_80198E6C;
    case 0x80198E70u: goto label_80198E70;
    case 0x80198E74u: goto label_80198E74;
    case 0x80198E78u: goto label_80198E78;
    case 0x80198E7Cu: goto label_80198E7C;
    case 0x80198E80u: goto label_80198E80;
    case 0x80198E84u: goto label_80198E84;
    case 0x80198E88u: goto label_80198E88;
    case 0x80198E8Cu: goto label_80198E8C;
    case 0x80198E90u: goto label_80198E90;
    case 0x80198E94u: goto label_80198E94;
    case 0x80198E98u: goto label_80198E98;
    case 0x80198E9Cu: goto label_80198E9C;
    case 0x80198EA0u: goto label_80198EA0;
    case 0x80198EA4u: goto label_80198EA4;
    case 0x80198EA8u: goto label_80198EA8;
    case 0x80198EACu: goto label_80198EAC;
    case 0x80198EB0u: goto label_80198EB0;
    case 0x80198EB4u: goto label_80198EB4;
    case 0x80198EB8u: goto label_80198EB8;
    case 0x80198EBCu: goto label_80198EBC;
    case 0x80198EC0u: goto label_80198EC0;
    case 0x80198EC4u: goto label_80198EC4;
    case 0x80198EC8u: goto label_80198EC8;
    case 0x80198ECCu: goto label_80198ECC;
    case 0x80198ED0u: goto label_80198ED0;
    case 0x80198ED4u: goto label_80198ED4;
    case 0x80198ED8u: goto label_80198ED8;
    case 0x80198EDCu: goto label_80198EDC;
    case 0x80198EE0u: goto label_80198EE0;
    case 0x80198EE4u: goto label_80198EE4;
    case 0x80198EE8u: goto label_80198EE8;
    case 0x80198EECu: goto label_80198EEC;
    case 0x80198EF0u: goto label_80198EF0;
    case 0x80198EF4u: goto label_80198EF4;
    case 0x80198EF8u: goto label_80198EF8;
    case 0x80198EFCu: goto label_80198EFC;
    case 0x80198F00u: goto label_80198F00;
    case 0x80198F04u: goto label_80198F04;
    case 0x80198F08u: goto label_80198F08;
    case 0x80198F0Cu: goto label_80198F0C;
    case 0x80198F10u: goto label_80198F10;
    case 0x80198F14u: goto label_80198F14;
    case 0x80198F18u: goto label_80198F18;
    case 0x80198F1Cu: goto label_80198F1C;
    case 0x80198F20u: goto label_80198F20;
    case 0x80198F24u: goto label_80198F24;
    case 0x80198F28u: goto label_80198F28;
    case 0x80198F2Cu: goto label_80198F2C;
    case 0x80198F30u: goto label_80198F30;
    case 0x80198F34u: goto label_80198F34;
    case 0x80198F38u: goto label_80198F38;
    case 0x80198F3Cu: goto label_80198F3C;
    case 0x80198F40u: goto label_80198F40;
    case 0x80198F44u: goto label_80198F44;
    case 0x80198F48u: goto label_80198F48;
    case 0x80198F4Cu: goto label_80198F4C;
    case 0x80198F50u: goto label_80198F50;
    case 0x80198F54u: goto label_80198F54;
    case 0x80198F58u: goto label_80198F58;
    case 0x80198F5Cu: goto label_80198F5C;
    case 0x80198F60u: goto label_80198F60;
    case 0x80198F64u: goto label_80198F64;
    case 0x80198F68u: goto label_80198F68;
    case 0x80198F6Cu: goto label_80198F6C;
    case 0x80198F70u: goto label_80198F70;
    case 0x80198F74u: goto label_80198F74;
    case 0x80198F78u: goto label_80198F78;
    case 0x80198F7Cu: goto label_80198F7C;
    case 0x80198F80u: goto label_80198F80;
    case 0x80198F84u: goto label_80198F84;
    case 0x80198F88u: goto label_80198F88;
    case 0x80198F8Cu: goto label_80198F8C;
    case 0x80198F90u: goto label_80198F90;
    case 0x80198F94u: goto label_80198F94;
    case 0x80198F98u: goto label_80198F98;
    case 0x80198F9Cu: goto label_80198F9C;
    case 0x80198FA0u: goto label_80198FA0;
    case 0x80198FA4u: goto label_80198FA4;
    case 0x80198FA8u: goto label_80198FA8;
    case 0x80198FACu: goto label_80198FAC;
    case 0x80198FB0u: goto label_80198FB0;
    case 0x80198FB4u: goto label_80198FB4;
    case 0x80198FB8u: goto label_80198FB8;
    case 0x80198FBCu: goto label_80198FBC;
    case 0x80198FC0u: goto label_80198FC0;
    case 0x80198FC4u: goto label_80198FC4;
    case 0x80198FC8u: goto label_80198FC8;
    case 0x80198FCCu: goto label_80198FCC;
    case 0x80198FD0u: goto label_80198FD0;
    case 0x80198FD4u: goto label_80198FD4;
    case 0x80198FD8u: goto label_80198FD8;
    case 0x80198FDCu: goto label_80198FDC;
    case 0x80198FE0u: goto label_80198FE0;
    case 0x80198FE4u: goto label_80198FE4;
    case 0x80198FE8u: goto label_80198FE8;
    case 0x80198FECu: goto label_80198FEC;
    case 0x80198FF0u: goto label_80198FF0;
    case 0x80198FF4u: goto label_80198FF4;
    case 0x80198FF8u: goto label_80198FF8;
    case 0x80198FFCu: goto label_80198FFC;
    case 0x80199000u: goto label_80199000;
    case 0x80199004u: goto label_80199004;
    case 0x80199008u: goto label_80199008;
    case 0x8019900Cu: goto label_8019900C;
    case 0x80199010u: goto label_80199010;
    case 0x80199014u: goto label_80199014;
    case 0x80199018u: goto label_80199018;
    case 0x8019901Cu: goto label_8019901C;
    case 0x80199020u: goto label_80199020;
    case 0x80199024u: goto label_80199024;
    case 0x80199028u: goto label_80199028;
    case 0x8019902Cu: goto label_8019902C;
    case 0x80199030u: goto label_80199030;
    case 0x80199034u: goto label_80199034;
    case 0x80199038u: goto label_80199038;
    case 0x8019903Cu: goto label_8019903C;
    case 0x80199040u: goto label_80199040;
    case 0x80199044u: goto label_80199044;
    case 0x80199048u: goto label_80199048;
    case 0x8019904Cu: goto label_8019904C;
    case 0x80199050u: goto label_80199050;
    case 0x80199054u: goto label_80199054;
    case 0x80199058u: goto label_80199058;
    case 0x8019905Cu: goto label_8019905C;
    case 0x80199060u: goto label_80199060;
    case 0x80199064u: goto label_80199064;
    case 0x80199068u: goto label_80199068;
    case 0x8019906Cu: goto label_8019906C;
    case 0x80199070u: goto label_80199070;
    case 0x80199074u: goto label_80199074;
    case 0x80199078u: goto label_80199078;
    case 0x8019907Cu: goto label_8019907C;
    case 0x80199080u: goto label_80199080;
    case 0x80199084u: goto label_80199084;
    case 0x80199088u: goto label_80199088;
    case 0x8019908Cu: goto label_8019908C;
    case 0x80199090u: goto label_80199090;
    case 0x80199094u: goto label_80199094;
    case 0x80199098u: goto label_80199098;
    case 0x8019909Cu: goto label_8019909C;
    case 0x801990A0u: goto label_801990A0;
    case 0x801990A4u: goto label_801990A4;
    case 0x801990A8u: goto label_801990A8;
    case 0x801990ACu: goto label_801990AC;
    case 0x801990B0u: goto label_801990B0;
    case 0x801990B4u: goto label_801990B4;
    case 0x801990B8u: goto label_801990B8;
    case 0x801990BCu: goto label_801990BC;
    case 0x801990C0u: goto label_801990C0;
    case 0x801990C4u: goto label_801990C4;
    case 0x801990C8u: goto label_801990C8;
    case 0x801990CCu: goto label_801990CC;
    case 0x801990D0u: goto label_801990D0;
    case 0x801990D4u: goto label_801990D4;
    case 0x801990D8u: goto label_801990D8;
    case 0x801990DCu: goto label_801990DC;
    case 0x801990E0u: goto label_801990E0;
    case 0x801990E4u: goto label_801990E4;
    case 0x801990E8u: goto label_801990E8;
    case 0x801990ECu: goto label_801990EC;
    case 0x801990F0u: goto label_801990F0;
    case 0x801990F4u: goto label_801990F4;
    case 0x801990F8u: goto label_801990F8;
    case 0x801990FCu: goto label_801990FC;
    case 0x80199100u: goto label_80199100;
    case 0x80199104u: goto label_80199104;
    case 0x80199108u: goto label_80199108;
    case 0x8019910Cu: goto label_8019910C;
    case 0x80199110u: goto label_80199110;
    case 0x80199114u: goto label_80199114;
    case 0x80199118u: goto label_80199118;
    case 0x8019911Cu: goto label_8019911C;
    case 0x80199120u: goto label_80199120;
    case 0x80199124u: goto label_80199124;
    case 0x80199128u: goto label_80199128;
    case 0x8019912Cu: goto label_8019912C;
    case 0x80199130u: goto label_80199130;
    case 0x80199134u: goto label_80199134;
    case 0x80199138u: goto label_80199138;
    case 0x8019913Cu: goto label_8019913C;
    case 0x80199140u: goto label_80199140;
    case 0x80199144u: goto label_80199144;
    case 0x80199148u: goto label_80199148;
    case 0x8019914Cu: goto label_8019914C;
    case 0x80199150u: goto label_80199150;
    case 0x80199154u: goto label_80199154;
    case 0x80199158u: goto label_80199158;
    case 0x8019915Cu: goto label_8019915C;
    case 0x80199160u: goto label_80199160;
    case 0x80199164u: goto label_80199164;
    case 0x80199168u: goto label_80199168;
    case 0x8019916Cu: goto label_8019916C;
    case 0x80199170u: goto label_80199170;
    case 0x80199174u: goto label_80199174;
    case 0x80199178u: goto label_80199178;
    case 0x8019917Cu: goto label_8019917C;
    case 0x80199180u: goto label_80199180;
    case 0x80199184u: goto label_80199184;
    case 0x80199188u: goto label_80199188;
    case 0x8019918Cu: goto label_8019918C;
    case 0x80199190u: goto label_80199190;
    case 0x80199194u: goto label_80199194;
    case 0x80199198u: goto label_80199198;
    case 0x8019919Cu: goto label_8019919C;
    case 0x801991A0u: goto label_801991A0;
    case 0x801991A4u: goto label_801991A4;
    case 0x801991A8u: goto label_801991A8;
    case 0x801991ACu: goto label_801991AC;
    case 0x801991B0u: goto label_801991B0;
    case 0x801991B4u: goto label_801991B4;
    case 0x801991B8u: goto label_801991B8;
    case 0x801991BCu: goto label_801991BC;
    case 0x801991C0u: goto label_801991C0;
    case 0x801991C4u: goto label_801991C4;
    case 0x801991C8u: goto label_801991C8;
    case 0x801991CCu: goto label_801991CC;
    case 0x801991D0u: goto label_801991D0;
    case 0x801991D4u: goto label_801991D4;
    case 0x801991D8u: goto label_801991D8;
    case 0x801991DCu: goto label_801991DC;
    case 0x801991E0u: goto label_801991E0;
    case 0x801991E4u: goto label_801991E4;
    case 0x801991E8u: goto label_801991E8;
    case 0x801991ECu: goto label_801991EC;
    case 0x801991F0u: goto label_801991F0;
    case 0x801991F4u: goto label_801991F4;
    case 0x801991F8u: goto label_801991F8;
    case 0x801991FCu: goto label_801991FC;
    case 0x80199200u: goto label_80199200;
    case 0x80199204u: goto label_80199204;
    case 0x80199208u: goto label_80199208;
    case 0x8019920Cu: goto label_8019920C;
    case 0x80199210u: goto label_80199210;
    case 0x80199214u: goto label_80199214;
    case 0x80199218u: goto label_80199218;
    case 0x8019921Cu: goto label_8019921C;
    case 0x80199220u: goto label_80199220;
    case 0x80199224u: goto label_80199224;
    case 0x80199228u: goto label_80199228;
    case 0x8019922Cu: goto label_8019922C;
    case 0x80199230u: goto label_80199230;
    case 0x80199234u: goto label_80199234;
    case 0x80199238u: goto label_80199238;
    case 0x8019923Cu: goto label_8019923C;
    case 0x80199240u: goto label_80199240;
    case 0x80199244u: goto label_80199244;
    case 0x80199248u: goto label_80199248;
    case 0x8019924Cu: goto label_8019924C;
    case 0x80199250u: goto label_80199250;
    case 0x80199254u: goto label_80199254;
    case 0x80199258u: goto label_80199258;
    case 0x8019925Cu: goto label_8019925C;
    case 0x80199260u: goto label_80199260;
    case 0x80199264u: goto label_80199264;
    case 0x80199268u: goto label_80199268;
    case 0x8019926Cu: goto label_8019926C;
    case 0x80199270u: goto label_80199270;
    case 0x80199274u: goto label_80199274;
    case 0x80199278u: goto label_80199278;
    case 0x8019927Cu: goto label_8019927C;
    case 0x80199280u: goto label_80199280;
    case 0x80199284u: goto label_80199284;
    case 0x80199288u: goto label_80199288;
    case 0x8019928Cu: goto label_8019928C;
    case 0x80199290u: goto label_80199290;
    case 0x80199294u: goto label_80199294;
    case 0x80199298u: goto label_80199298;
    case 0x8019929Cu: goto label_8019929C;
    case 0x801992A0u: goto label_801992A0;
    case 0x801992A4u: goto label_801992A4;
    case 0x801992A8u: goto label_801992A8;
    case 0x801992ACu: goto label_801992AC;
    case 0x801992B0u: goto label_801992B0;
    case 0x801992B4u: goto label_801992B4;
    case 0x801992B8u: goto label_801992B8;
    case 0x801992BCu: goto label_801992BC;
    case 0x801992C0u: goto label_801992C0;
    case 0x801992C4u: goto label_801992C4;
    case 0x801992C8u: goto label_801992C8;
    case 0x801992CCu: goto label_801992CC;
    case 0x801992D0u: goto label_801992D0;
    case 0x801992D4u: goto label_801992D4;
    case 0x801992D8u: goto label_801992D8;
    case 0x801992DCu: goto label_801992DC;
    case 0x801992E0u: goto label_801992E0;
    case 0x801992E4u: goto label_801992E4;
    case 0x801992E8u: goto label_801992E8;
    case 0x801992ECu: goto label_801992EC;
    case 0x801992F0u: goto label_801992F0;
    case 0x801992F4u: goto label_801992F4;
    case 0x801992F8u: goto label_801992F8;
    case 0x801992FCu: goto label_801992FC;
    case 0x80199300u: goto label_80199300;
    case 0x80199304u: goto label_80199304;
    case 0x80199308u: goto label_80199308;
    case 0x8019930Cu: goto label_8019930C;
    case 0x80199310u: goto label_80199310;
    case 0x80199314u: goto label_80199314;
    case 0x80199318u: goto label_80199318;
    case 0x8019931Cu: goto label_8019931C;
    case 0x80199320u: goto label_80199320;
    case 0x80199324u: goto label_80199324;
    case 0x80199328u: goto label_80199328;
    case 0x8019932Cu: goto label_8019932C;
    case 0x80199330u: goto label_80199330;
    case 0x80199334u: goto label_80199334;
    case 0x80199338u: goto label_80199338;
    case 0x8019933Cu: goto label_8019933C;
    case 0x80199340u: goto label_80199340;
    case 0x80199344u: goto label_80199344;
    case 0x80199348u: goto label_80199348;
    case 0x8019934Cu: goto label_8019934C;
    case 0x80199350u: goto label_80199350;
    case 0x80199354u: goto label_80199354;
    case 0x80199358u: goto label_80199358;
    case 0x8019935Cu: goto label_8019935C;
    case 0x80199360u: goto label_80199360;
    case 0x80199364u: goto label_80199364;
    case 0x80199368u: goto label_80199368;
    case 0x8019936Cu: goto label_8019936C;
    case 0x80199370u: goto label_80199370;
    case 0x80199374u: goto label_80199374;
    case 0x80199378u: goto label_80199378;
    case 0x8019937Cu: goto label_8019937C;
    case 0x80199380u: goto label_80199380;
    case 0x80199384u: goto label_80199384;
    case 0x80199388u: goto label_80199388;
    case 0x8019938Cu: goto label_8019938C;
    case 0x80199390u: goto label_80199390;
    case 0x80199394u: goto label_80199394;
    case 0x80199398u: goto label_80199398;
    case 0x8019939Cu: goto label_8019939C;
    case 0x801993A0u: goto label_801993A0;
    case 0x801993A4u: goto label_801993A4;
    case 0x801993A8u: goto label_801993A8;
    case 0x801993ACu: goto label_801993AC;
    case 0x801993B0u: goto label_801993B0;
    case 0x801993B4u: goto label_801993B4;
    case 0x801993B8u: goto label_801993B8;
    case 0x801993BCu: goto label_801993BC;
    case 0x801993C0u: goto label_801993C0;
    case 0x801993C4u: goto label_801993C4;
    case 0x801993C8u: goto label_801993C8;
    case 0x801993CCu: goto label_801993CC;
    case 0x801993D0u: goto label_801993D0;
    case 0x801993D4u: goto label_801993D4;
    case 0x801993D8u: goto label_801993D8;
    case 0x801993DCu: goto label_801993DC;
    case 0x801993E0u: goto label_801993E0;
    case 0x801993E4u: goto label_801993E4;
    case 0x801993E8u: goto label_801993E8;
    case 0x801993ECu: goto label_801993EC;
    case 0x801993F0u: goto label_801993F0;
    case 0x801993F4u: goto label_801993F4;
    case 0x801993F8u: goto label_801993F8;
    case 0x801993FCu: goto label_801993FC;
    case 0x80199400u: goto label_80199400;
    case 0x80199404u: goto label_80199404;
    case 0x80199408u: goto label_80199408;
    case 0x8019940Cu: goto label_8019940C;
    case 0x80199410u: goto label_80199410;
    case 0x80199414u: goto label_80199414;
    case 0x80199418u: goto label_80199418;
    case 0x8019941Cu: goto label_8019941C;
    case 0x80199420u: goto label_80199420;
    case 0x80199424u: goto label_80199424;
    case 0x80199428u: goto label_80199428;
    case 0x8019942Cu: goto label_8019942C;
    case 0x80199430u: goto label_80199430;
    case 0x80199434u: goto label_80199434;
    case 0x80199438u: goto label_80199438;
    case 0x8019943Cu: goto label_8019943C;
    case 0x80199440u: goto label_80199440;
    case 0x80199444u: goto label_80199444;
    case 0x80199448u: goto label_80199448;
    case 0x8019944Cu: goto label_8019944C;
    case 0x80199450u: goto label_80199450;
    case 0x80199454u: goto label_80199454;
    case 0x80199458u: goto label_80199458;
    case 0x8019945Cu: goto label_8019945C;
    case 0x80199460u: goto label_80199460;
    case 0x80199464u: goto label_80199464;
    case 0x80199468u: goto label_80199468;
    case 0x8019946Cu: goto label_8019946C;
    case 0x80199470u: goto label_80199470;
    case 0x80199474u: goto label_80199474;
    case 0x80199478u: goto label_80199478;
    case 0x8019947Cu: goto label_8019947C;
    case 0x80199480u: goto label_80199480;
    case 0x80199484u: goto label_80199484;
    case 0x80199488u: goto label_80199488;
    case 0x8019948Cu: goto label_8019948C;
    case 0x80199490u: goto label_80199490;
    case 0x80199494u: goto label_80199494;
    case 0x80199498u: goto label_80199498;
    case 0x8019949Cu: goto label_8019949C;
    case 0x801994A0u: goto label_801994A0;
    case 0x801994A4u: goto label_801994A4;
    case 0x801994A8u: goto label_801994A8;
    case 0x801994ACu: goto label_801994AC;
    case 0x801994B0u: goto label_801994B0;
    case 0x801994B4u: goto label_801994B4;
    case 0x801994B8u: goto label_801994B8;
    case 0x801994BCu: goto label_801994BC;
    case 0x801994C0u: goto label_801994C0;
    case 0x801994C4u: goto label_801994C4;
    case 0x801994C8u: goto label_801994C8;
    case 0x801994CCu: goto label_801994CC;
    case 0x801994D0u: goto label_801994D0;
    case 0x801994D4u: goto label_801994D4;
    case 0x801994D8u: goto label_801994D8;
    case 0x801994DCu: goto label_801994DC;
    case 0x801994E0u: goto label_801994E0;
    case 0x801994E4u: goto label_801994E4;
    case 0x801994E8u: goto label_801994E8;
    case 0x801994ECu: goto label_801994EC;
    case 0x801994F0u: goto label_801994F0;
    case 0x801994F4u: goto label_801994F4;
    case 0x801994F8u: goto label_801994F8;
    case 0x801994FCu: goto label_801994FC;
    case 0x80199500u: goto label_80199500;
    case 0x80199504u: goto label_80199504;
    case 0x80199508u: goto label_80199508;
    case 0x8019950Cu: goto label_8019950C;
    case 0x80199510u: goto label_80199510;
    case 0x80199514u: goto label_80199514;
    case 0x80199518u: goto label_80199518;
    case 0x8019951Cu: goto label_8019951C;
    case 0x80199520u: goto label_80199520;
    case 0x80199524u: goto label_80199524;
    case 0x80199528u: goto label_80199528;
    case 0x8019952Cu: goto label_8019952C;
    case 0x80199530u: goto label_80199530;
    case 0x80199534u: goto label_80199534;
    case 0x80199538u: goto label_80199538;
    case 0x8019953Cu: goto label_8019953C;
    case 0x80199540u: goto label_80199540;
    case 0x80199544u: goto label_80199544;
    case 0x80199548u: goto label_80199548;
    case 0x8019954Cu: goto label_8019954C;
    case 0x80199550u: goto label_80199550;
    case 0x80199554u: goto label_80199554;
    case 0x80199558u: goto label_80199558;
    case 0x8019955Cu: goto label_8019955C;
    case 0x80199560u: goto label_80199560;
    case 0x80199564u: goto label_80199564;
    case 0x80199568u: goto label_80199568;
    case 0x8019956Cu: goto label_8019956C;
    case 0x80199570u: goto label_80199570;
    case 0x80199574u: goto label_80199574;
    case 0x80199578u: goto label_80199578;
    case 0x8019957Cu: goto label_8019957C;
    case 0x80199580u: goto label_80199580;
    case 0x80199584u: goto label_80199584;
    case 0x80199588u: goto label_80199588;
    case 0x8019958Cu: goto label_8019958C;
    case 0x80199590u: goto label_80199590;
    case 0x80199594u: goto label_80199594;
    case 0x80199598u: goto label_80199598;
    case 0x8019959Cu: goto label_8019959C;
    case 0x801995A0u: goto label_801995A0;
    case 0x801995A4u: goto label_801995A4;
    case 0x801995A8u: goto label_801995A8;
    case 0x801995ACu: goto label_801995AC;
    case 0x801995B0u: goto label_801995B0;
    case 0x801995B4u: goto label_801995B4;
    case 0x801995B8u: goto label_801995B8;
    case 0x801995BCu: goto label_801995BC;
    case 0x801995C0u: goto label_801995C0;
    case 0x801995C4u: goto label_801995C4;
    case 0x801995C8u: goto label_801995C8;
    case 0x801995CCu: goto label_801995CC;
    case 0x801995D0u: goto label_801995D0;
    case 0x801995D4u: goto label_801995D4;
    case 0x801995D8u: goto label_801995D8;
    case 0x801995DCu: goto label_801995DC;
    case 0x801995E0u: goto label_801995E0;
    case 0x801995E4u: goto label_801995E4;
    case 0x801995E8u: goto label_801995E8;
    case 0x801995ECu: goto label_801995EC;
    case 0x801995F0u: goto label_801995F0;
    case 0x801995F4u: goto label_801995F4;
    case 0x801995F8u: goto label_801995F8;
    case 0x801995FCu: goto label_801995FC;
    case 0x80199600u: goto label_80199600;
    case 0x80199604u: goto label_80199604;
    case 0x80199608u: goto label_80199608;
    case 0x8019960Cu: goto label_8019960C;
    case 0x80199610u: goto label_80199610;
    case 0x80199614u: goto label_80199614;
    case 0x80199618u: goto label_80199618;
    case 0x8019961Cu: goto label_8019961C;
    case 0x80199620u: goto label_80199620;
    case 0x80199624u: goto label_80199624;
    case 0x80199628u: goto label_80199628;
    case 0x8019962Cu: goto label_8019962C;
    case 0x80199630u: goto label_80199630;
    case 0x80199634u: goto label_80199634;
    case 0x80199638u: goto label_80199638;
    case 0x8019963Cu: goto label_8019963C;
    case 0x80199640u: goto label_80199640;
    case 0x80199644u: goto label_80199644;
    case 0x80199648u: goto label_80199648;
    case 0x8019964Cu: goto label_8019964C;
    case 0x80199650u: goto label_80199650;
    case 0x80199654u: goto label_80199654;
    case 0x80199658u: goto label_80199658;
    case 0x8019965Cu: goto label_8019965C;
    case 0x80199660u: goto label_80199660;
    case 0x80199664u: goto label_80199664;
    case 0x80199668u: goto label_80199668;
    case 0x8019966Cu: goto label_8019966C;
    case 0x80199670u: goto label_80199670;
    case 0x80199674u: goto label_80199674;
    case 0x80199678u: goto label_80199678;
    case 0x8019967Cu: goto label_8019967C;
    case 0x80199680u: goto label_80199680;
    case 0x80199684u: goto label_80199684;
    case 0x80199688u: goto label_80199688;
    case 0x8019968Cu: goto label_8019968C;
    case 0x80199690u: goto label_80199690;
    case 0x80199694u: goto label_80199694;
    case 0x80199698u: goto label_80199698;
    case 0x8019969Cu: goto label_8019969C;
    case 0x801996A0u: goto label_801996A0;
    case 0x801996A4u: goto label_801996A4;
    case 0x801996A8u: goto label_801996A8;
    case 0x801996ACu: goto label_801996AC;
    case 0x801996B0u: goto label_801996B0;
    case 0x801996B4u: goto label_801996B4;
    case 0x801996B8u: goto label_801996B8;
    case 0x801996BCu: goto label_801996BC;
    case 0x801996C0u: goto label_801996C0;
    case 0x801996C4u: goto label_801996C4;
    case 0x801996C8u: goto label_801996C8;
    case 0x801996CCu: goto label_801996CC;
    case 0x801996D0u: goto label_801996D0;
    case 0x801996D4u: goto label_801996D4;
    case 0x801996D8u: goto label_801996D8;
    case 0x801996DCu: goto label_801996DC;
    case 0x801996E0u: goto label_801996E0;
    case 0x801996E4u: goto label_801996E4;
    case 0x801996E8u: goto label_801996E8;
    case 0x801996ECu: goto label_801996EC;
    case 0x801996F0u: goto label_801996F0;
    case 0x801996F4u: goto label_801996F4;
    case 0x801996F8u: goto label_801996F8;
    case 0x801996FCu: goto label_801996FC;
    case 0x80199700u: goto label_80199700;
    case 0x80199704u: goto label_80199704;
    case 0x80199708u: goto label_80199708;
    case 0x8019970Cu: goto label_8019970C;
    case 0x80199710u: goto label_80199710;
    case 0x80199714u: goto label_80199714;
    case 0x80199718u: goto label_80199718;
    case 0x8019971Cu: goto label_8019971C;
    case 0x80199720u: goto label_80199720;
    case 0x80199724u: goto label_80199724;
    case 0x80199728u: goto label_80199728;
    case 0x8019972Cu: goto label_8019972C;
    case 0x80199730u: goto label_80199730;
    case 0x80199734u: goto label_80199734;
    case 0x80199738u: goto label_80199738;
    case 0x8019973Cu: goto label_8019973C;
    case 0x80199740u: goto label_80199740;
    case 0x80199744u: goto label_80199744;
    case 0x80199748u: goto label_80199748;
    case 0x8019974Cu: goto label_8019974C;
    case 0x80199750u: goto label_80199750;
    case 0x80199754u: goto label_80199754;
    case 0x80199758u: goto label_80199758;
    case 0x8019975Cu: goto label_8019975C;
    case 0x80199760u: goto label_80199760;
    case 0x80199764u: goto label_80199764;
    case 0x80199768u: goto label_80199768;
    case 0x8019976Cu: goto label_8019976C;
    case 0x80199770u: goto label_80199770;
    case 0x80199774u: goto label_80199774;
    case 0x80199778u: goto label_80199778;
    case 0x8019977Cu: goto label_8019977C;
    case 0x80199780u: goto label_80199780;
    case 0x80199784u: goto label_80199784;
    case 0x80199788u: goto label_80199788;
    case 0x8019978Cu: goto label_8019978C;
    case 0x80199790u: goto label_80199790;
    case 0x80199794u: goto label_80199794;
    case 0x80199798u: goto label_80199798;
    case 0x8019979Cu: goto label_8019979C;
    case 0x801997A0u: goto label_801997A0;
    case 0x801997A4u: goto label_801997A4;
    case 0x801997A8u: goto label_801997A8;
    case 0x801997ACu: goto label_801997AC;
    case 0x801997B0u: goto label_801997B0;
    case 0x801997B4u: goto label_801997B4;
    case 0x801997B8u: goto label_801997B8;
    case 0x801997BCu: goto label_801997BC;
    case 0x801997C0u: goto label_801997C0;
    case 0x801997C4u: goto label_801997C4;
    case 0x801997C8u: goto label_801997C8;
    case 0x801997CCu: goto label_801997CC;
    case 0x801997D0u: goto label_801997D0;
    case 0x801997D4u: goto label_801997D4;
    case 0x801997D8u: goto label_801997D8;
    case 0x801997DCu: goto label_801997DC;
    case 0x801997E0u: goto label_801997E0;
    case 0x801997E4u: goto label_801997E4;
    case 0x801997E8u: goto label_801997E8;
    case 0x801997ECu: goto label_801997EC;
    case 0x801997F0u: goto label_801997F0;
    case 0x801997F4u: goto label_801997F4;
    case 0x801997F8u: goto label_801997F8;
    case 0x801997FCu: goto label_801997FC;
    case 0x80199800u: goto label_80199800;
    case 0x80199804u: goto label_80199804;
    case 0x80199808u: goto label_80199808;
    case 0x8019980Cu: goto label_8019980C;
    case 0x80199810u: goto label_80199810;
    case 0x80199814u: goto label_80199814;
    case 0x80199818u: goto label_80199818;
    case 0x8019981Cu: goto label_8019981C;
    case 0x80199820u: goto label_80199820;
    case 0x80199824u: goto label_80199824;
    case 0x80199828u: goto label_80199828;
    case 0x8019982Cu: goto label_8019982C;
    case 0x80199830u: goto label_80199830;
    case 0x80199834u: goto label_80199834;
    case 0x80199838u: goto label_80199838;
    case 0x8019983Cu: goto label_8019983C;
    case 0x80199840u: goto label_80199840;
    case 0x80199844u: goto label_80199844;
    case 0x80199848u: goto label_80199848;
    case 0x8019984Cu: goto label_8019984C;
    case 0x80199850u: goto label_80199850;
    case 0x80199854u: goto label_80199854;
    case 0x80199858u: goto label_80199858;
    case 0x8019985Cu: goto label_8019985C;
    case 0x80199860u: goto label_80199860;
    case 0x80199864u: goto label_80199864;
    case 0x80199868u: goto label_80199868;
    case 0x8019986Cu: goto label_8019986C;
    case 0x80199870u: goto label_80199870;
    case 0x80199874u: goto label_80199874;
    case 0x80199878u: goto label_80199878;
    case 0x8019987Cu: goto label_8019987C;
    case 0x80199880u: goto label_80199880;
    case 0x80199884u: goto label_80199884;
    case 0x80199888u: goto label_80199888;
    case 0x8019988Cu: goto label_8019988C;
    case 0x80199890u: goto label_80199890;
    case 0x80199894u: goto label_80199894;
    case 0x80199898u: goto label_80199898;
    case 0x8019989Cu: goto label_8019989C;
    case 0x801998A0u: goto label_801998A0;
    case 0x801998A4u: goto label_801998A4;
    case 0x801998A8u: goto label_801998A8;
    case 0x801998ACu: goto label_801998AC;
    case 0x801998B0u: goto label_801998B0;
    case 0x801998B4u: goto label_801998B4;
    case 0x801998B8u: goto label_801998B8;
    case 0x801998BCu: goto label_801998BC;
    case 0x801998C0u: goto label_801998C0;
    case 0x801998C4u: goto label_801998C4;
    case 0x801998C8u: goto label_801998C8;
    case 0x801998CCu: goto label_801998CC;
    case 0x801998D0u: goto label_801998D0;
    case 0x801998D4u: goto label_801998D4;
    case 0x801998D8u: goto label_801998D8;
    case 0x801998DCu: goto label_801998DC;
    case 0x801998E0u: goto label_801998E0;
    case 0x801998E4u: goto label_801998E4;
    case 0x801998E8u: goto label_801998E8;
    case 0x801998ECu: goto label_801998EC;
    case 0x801998F0u: goto label_801998F0;
    case 0x801998F4u: goto label_801998F4;
    case 0x801998F8u: goto label_801998F8;
    case 0x801998FCu: goto label_801998FC;
    case 0x80199900u: goto label_80199900;
    case 0x80199904u: goto label_80199904;
    case 0x80199908u: goto label_80199908;
    case 0x8019990Cu: goto label_8019990C;
    case 0x80199910u: goto label_80199910;
    case 0x80199914u: goto label_80199914;
    case 0x80199918u: goto label_80199918;
    case 0x8019991Cu: goto label_8019991C;
    case 0x80199920u: goto label_80199920;
    case 0x80199924u: goto label_80199924;
    case 0x80199928u: goto label_80199928;
    case 0x8019992Cu: goto label_8019992C;
    case 0x80199930u: goto label_80199930;
    case 0x80199934u: goto label_80199934;
    case 0x80199938u: goto label_80199938;
    case 0x8019993Cu: goto label_8019993C;
    case 0x80199940u: goto label_80199940;
    case 0x80199944u: goto label_80199944;
    case 0x80199948u: goto label_80199948;
    case 0x8019994Cu: goto label_8019994C;
    case 0x80199950u: goto label_80199950;
    case 0x80199954u: goto label_80199954;
    case 0x80199958u: goto label_80199958;
    case 0x8019995Cu: goto label_8019995C;
    case 0x80199960u: goto label_80199960;
    case 0x80199964u: goto label_80199964;
    case 0x80199968u: goto label_80199968;
    case 0x8019996Cu: goto label_8019996C;
    case 0x80199970u: goto label_80199970;
    case 0x80199974u: goto label_80199974;
    case 0x80199978u: goto label_80199978;
    case 0x8019997Cu: goto label_8019997C;
    case 0x80199980u: goto label_80199980;
    case 0x80199984u: goto label_80199984;
    case 0x80199988u: goto label_80199988;
    case 0x8019998Cu: goto label_8019998C;
    case 0x80199990u: goto label_80199990;
    case 0x80199994u: goto label_80199994;
    case 0x80199998u: goto label_80199998;
    case 0x8019999Cu: goto label_8019999C;
    case 0x801999A0u: goto label_801999A0;
    case 0x801999A4u: goto label_801999A4;
    case 0x801999A8u: goto label_801999A8;
    case 0x801999ACu: goto label_801999AC;
    case 0x801999B0u: goto label_801999B0;
    case 0x801999B4u: goto label_801999B4;
    case 0x801999B8u: goto label_801999B8;
    case 0x801999BCu: goto label_801999BC;
    case 0x801999C0u: goto label_801999C0;
    case 0x801999C4u: goto label_801999C4;
    case 0x801999C8u: goto label_801999C8;
    case 0x801999CCu: goto label_801999CC;
    case 0x801999D0u: goto label_801999D0;
    case 0x801999D4u: goto label_801999D4;
    case 0x801999D8u: goto label_801999D8;
    case 0x801999DCu: goto label_801999DC;
    case 0x801999E0u: goto label_801999E0;
    case 0x801999E4u: goto label_801999E4;
    case 0x801999E8u: goto label_801999E8;
    case 0x801999ECu: goto label_801999EC;
    case 0x801999F0u: goto label_801999F0;
    case 0x801999F4u: goto label_801999F4;
    case 0x801999F8u: goto label_801999F8;
    case 0x801999FCu: goto label_801999FC;
    case 0x80199A00u: goto label_80199A00;
    case 0x80199A04u: goto label_80199A04;
    case 0x80199A08u: goto label_80199A08;
    case 0x80199A0Cu: goto label_80199A0C;
    case 0x80199A10u: goto label_80199A10;
    case 0x80199A14u: goto label_80199A14;
    case 0x80199A18u: goto label_80199A18;
    case 0x80199A1Cu: goto label_80199A1C;
    case 0x80199A20u: goto label_80199A20;
    case 0x80199A24u: goto label_80199A24;
    case 0x80199A28u: goto label_80199A28;
    case 0x80199A2Cu: goto label_80199A2C;
    case 0x80199A30u: goto label_80199A30;
    case 0x80199A34u: goto label_80199A34;
    case 0x80199A38u: goto label_80199A38;
    case 0x80199A3Cu: goto label_80199A3C;
    case 0x80199A40u: goto label_80199A40;
    case 0x80199A44u: goto label_80199A44;
    case 0x80199A48u: goto label_80199A48;
    case 0x80199A4Cu: goto label_80199A4C;
    case 0x80199A50u: goto label_80199A50;
    case 0x80199A54u: goto label_80199A54;
    case 0x80199A58u: goto label_80199A58;
    case 0x80199A5Cu: goto label_80199A5C;
    case 0x80199A60u: goto label_80199A60;
    case 0x80199A64u: goto label_80199A64;
    case 0x80199A68u: goto label_80199A68;
    case 0x80199A6Cu: goto label_80199A6C;
    case 0x80199A70u: goto label_80199A70;
    case 0x80199A74u: goto label_80199A74;
    case 0x80199A78u: goto label_80199A78;
    case 0x80199A7Cu: goto label_80199A7C;
    case 0x80199A80u: goto label_80199A80;
    case 0x80199A84u: goto label_80199A84;
    case 0x80199A88u: goto label_80199A88;
    case 0x80199A8Cu: goto label_80199A8C;
    case 0x80199A90u: goto label_80199A90;
    case 0x80199A94u: goto label_80199A94;
    case 0x80199A98u: goto label_80199A98;
    case 0x80199A9Cu: goto label_80199A9C;
    case 0x80199AA0u: goto label_80199AA0;
    case 0x80199AA4u: goto label_80199AA4;
    case 0x80199AA8u: goto label_80199AA8;
    case 0x80199AACu: goto label_80199AAC;
    case 0x80199AB0u: goto label_80199AB0;
    case 0x80199AB4u: goto label_80199AB4;
    case 0x80199AB8u: goto label_80199AB8;
    case 0x80199ABCu: goto label_80199ABC;
    case 0x80199AC0u: goto label_80199AC0;
    case 0x80199AC4u: goto label_80199AC4;
    case 0x80199AC8u: goto label_80199AC8;
    case 0x80199ACCu: goto label_80199ACC;
    case 0x80199AD0u: goto label_80199AD0;
    case 0x80199AD4u: goto label_80199AD4;
    case 0x80199AD8u: goto label_80199AD8;
    case 0x80199ADCu: goto label_80199ADC;
    case 0x80199AE0u: goto label_80199AE0;
    case 0x80199AE4u: goto label_80199AE4;
    case 0x80199AE8u: goto label_80199AE8;
    case 0x80199AECu: goto label_80199AEC;
    case 0x80199AF0u: goto label_80199AF0;
    case 0x80199AF4u: goto label_80199AF4;
    case 0x80199AF8u: goto label_80199AF8;
    case 0x80199AFCu: goto label_80199AFC;
    case 0x80199B00u: goto label_80199B00;
    case 0x80199B04u: goto label_80199B04;
    case 0x80199B08u: goto label_80199B08;
    case 0x80199B0Cu: goto label_80199B0C;
    case 0x80199B10u: goto label_80199B10;
    case 0x80199B14u: goto label_80199B14;
    case 0x80199B18u: goto label_80199B18;
    case 0x80199B1Cu: goto label_80199B1C;
    case 0x80199B20u: goto label_80199B20;
    case 0x80199B24u: goto label_80199B24;
    case 0x80199B28u: goto label_80199B28;
    case 0x80199B2Cu: goto label_80199B2C;
    case 0x80199B30u: goto label_80199B30;
    case 0x80199B34u: goto label_80199B34;
    case 0x80199B38u: goto label_80199B38;
    case 0x80199B3Cu: goto label_80199B3C;
    case 0x80199B40u: goto label_80199B40;
    case 0x80199B44u: goto label_80199B44;
    case 0x80199B48u: goto label_80199B48;
    case 0x80199B4Cu: goto label_80199B4C;
    case 0x80199B50u: goto label_80199B50;
    case 0x80199B54u: goto label_80199B54;
    case 0x80199B58u: goto label_80199B58;
    case 0x80199B5Cu: goto label_80199B5C;
    case 0x80199B60u: goto label_80199B60;
    case 0x80199B64u: goto label_80199B64;
    case 0x80199B68u: goto label_80199B68;
    case 0x80199B6Cu: goto label_80199B6C;
    case 0x80199B70u: goto label_80199B70;
    case 0x80199B74u: goto label_80199B74;
    case 0x80199B78u: goto label_80199B78;
    case 0x80199B7Cu: goto label_80199B7C;
    case 0x80199B80u: goto label_80199B80;
    case 0x80199B84u: goto label_80199B84;
    case 0x80199B88u: goto label_80199B88;
    case 0x80199B8Cu: goto label_80199B8C;
    case 0x80199B90u: goto label_80199B90;
    case 0x80199B94u: goto label_80199B94;
    case 0x80199B98u: goto label_80199B98;
    case 0x80199B9Cu: goto label_80199B9C;
    case 0x80199BA0u: goto label_80199BA0;
    case 0x80199BA4u: goto label_80199BA4;
    case 0x80199BA8u: goto label_80199BA8;
    case 0x80199BACu: goto label_80199BAC;
    case 0x80199BB0u: goto label_80199BB0;
    case 0x80199BB4u: goto label_80199BB4;
    case 0x80199BB8u: goto label_80199BB8;
    case 0x80199BBCu: goto label_80199BBC;
    case 0x80199BC0u: goto label_80199BC0;
    case 0x80199BC4u: goto label_80199BC4;
    case 0x80199BC8u: goto label_80199BC8;
    case 0x80199BCCu: goto label_80199BCC;
    case 0x80199BD0u: goto label_80199BD0;
    case 0x80199BD4u: goto label_80199BD4;
    case 0x80199BD8u: goto label_80199BD8;
    case 0x80199BDCu: goto label_80199BDC;
    case 0x80199BE0u: goto label_80199BE0;
    case 0x80199BE4u: goto label_80199BE4;
    case 0x80199BE8u: goto label_80199BE8;
    case 0x80199BECu: goto label_80199BEC;
    case 0x80199BF0u: goto label_80199BF0;
    case 0x80199BF4u: goto label_80199BF4;
    case 0x80199BF8u: goto label_80199BF8;
    case 0x80199BFCu: goto label_80199BFC;
    case 0x80199C00u: goto label_80199C00;
    case 0x80199C04u: goto label_80199C04;
    case 0x80199C08u: goto label_80199C08;
    case 0x80199C0Cu: goto label_80199C0C;
    case 0x80199C10u: goto label_80199C10;
    case 0x80199C14u: goto label_80199C14;
    case 0x80199C18u: goto label_80199C18;
    case 0x80199C1Cu: goto label_80199C1C;
    case 0x80199C20u: goto label_80199C20;
    case 0x80199C24u: goto label_80199C24;
    case 0x80199C28u: goto label_80199C28;
    case 0x80199C2Cu: goto label_80199C2C;
    case 0x80199C30u: goto label_80199C30;
    case 0x80199C34u: goto label_80199C34;
    case 0x80199C38u: goto label_80199C38;
    case 0x80199C3Cu: goto label_80199C3C;
    case 0x80199C40u: goto label_80199C40;
    case 0x80199C44u: goto label_80199C44;
    case 0x80199C48u: goto label_80199C48;
    case 0x80199C4Cu: goto label_80199C4C;
    case 0x80199C50u: goto label_80199C50;
    case 0x80199C54u: goto label_80199C54;
    case 0x80199C58u: goto label_80199C58;
    case 0x80199C5Cu: goto label_80199C5C;
    case 0x80199C60u: goto label_80199C60;
    case 0x80199C64u: goto label_80199C64;
    case 0x80199C68u: goto label_80199C68;
    case 0x80199C6Cu: goto label_80199C6C;
    case 0x80199C70u: goto label_80199C70;
    case 0x80199C74u: goto label_80199C74;
    case 0x80199C78u: goto label_80199C78;
    case 0x80199C7Cu: goto label_80199C7C;
    case 0x80199C80u: goto label_80199C80;
    case 0x80199C84u: goto label_80199C84;
    case 0x80199C88u: goto label_80199C88;
    case 0x80199C8Cu: goto label_80199C8C;
    case 0x80199C90u: goto label_80199C90;
    case 0x80199C94u: goto label_80199C94;
    case 0x80199C98u: goto label_80199C98;
    case 0x80199C9Cu: goto label_80199C9C;
    case 0x80199CA0u: goto label_80199CA0;
    case 0x80199CA4u: goto label_80199CA4;
    case 0x80199CA8u: goto label_80199CA8;
    case 0x80199CACu: goto label_80199CAC;
    case 0x80199CB0u: goto label_80199CB0;
    case 0x80199CB4u: goto label_80199CB4;
    case 0x80199CB8u: goto label_80199CB8;
    case 0x80199CBCu: goto label_80199CBC;
    case 0x80199CC0u: goto label_80199CC0;
    case 0x80199CC4u: goto label_80199CC4;
    case 0x80199CC8u: goto label_80199CC8;
    case 0x80199CCCu: goto label_80199CCC;
    case 0x80199CD0u: goto label_80199CD0;
    case 0x80199CD4u: goto label_80199CD4;
    case 0x80199CD8u: goto label_80199CD8;
    case 0x80199CDCu: goto label_80199CDC;
    case 0x80199CE0u: goto label_80199CE0;
    case 0x80199CE4u: goto label_80199CE4;
    case 0x80199CE8u: goto label_80199CE8;
    case 0x80199CECu: goto label_80199CEC;
    case 0x80199CF0u: goto label_80199CF0;
    case 0x80199CF4u: goto label_80199CF4;
    case 0x80199CF8u: goto label_80199CF8;
    case 0x80199CFCu: goto label_80199CFC;
    case 0x80199D00u: goto label_80199D00;
    case 0x80199D04u: goto label_80199D04;
    case 0x80199D08u: goto label_80199D08;
    case 0x80199D0Cu: goto label_80199D0C;
    case 0x80199D10u: goto label_80199D10;
    case 0x80199D14u: goto label_80199D14;
    case 0x80199D18u: goto label_80199D18;
    case 0x80199D1Cu: goto label_80199D1C;
    case 0x80199D20u: goto label_80199D20;
    case 0x80199D24u: goto label_80199D24;
    case 0x80199D28u: goto label_80199D28;
    case 0x80199D2Cu: goto label_80199D2C;
    case 0x80199D30u: goto label_80199D30;
    case 0x80199D34u: goto label_80199D34;
    case 0x80199D38u: goto label_80199D38;
    case 0x80199D3Cu: goto label_80199D3C;
    case 0x80199D40u: goto label_80199D40;
    case 0x80199D44u: goto label_80199D44;
    case 0x80199D48u: goto label_80199D48;
    case 0x80199D4Cu: goto label_80199D4C;
    case 0x80199D50u: goto label_80199D50;
    case 0x80199D54u: goto label_80199D54;
    case 0x80199D58u: goto label_80199D58;
    case 0x80199D5Cu: goto label_80199D5C;
    case 0x80199D60u: goto label_80199D60;
    case 0x80199D64u: goto label_80199D64;
    case 0x80199D68u: goto label_80199D68;
    case 0x80199D6Cu: goto label_80199D6C;
    case 0x80199D70u: goto label_80199D70;
    case 0x80199D74u: goto label_80199D74;
    case 0x80199D78u: goto label_80199D78;
    case 0x80199D7Cu: goto label_80199D7C;
    case 0x80199D80u: goto label_80199D80;
    case 0x80199D84u: goto label_80199D84;
    case 0x80199D88u: goto label_80199D88;
    case 0x80199D8Cu: goto label_80199D8C;
    case 0x80199D90u: goto label_80199D90;
    case 0x80199D94u: goto label_80199D94;
    case 0x80199D98u: goto label_80199D98;
    case 0x80199D9Cu: goto label_80199D9C;
    case 0x80199DA0u: goto label_80199DA0;
    case 0x80199DA4u: goto label_80199DA4;
    case 0x80199DA8u: goto label_80199DA8;
    case 0x80199DACu: goto label_80199DAC;
    case 0x80199DB0u: goto label_80199DB0;
    case 0x80199DB4u: goto label_80199DB4;
    case 0x80199DB8u: goto label_80199DB8;
    case 0x80199DBCu: goto label_80199DBC;
    case 0x80199DC0u: goto label_80199DC0;
    case 0x80199DC4u: goto label_80199DC4;
    case 0x80199DC8u: goto label_80199DC8;
    case 0x80199DCCu: goto label_80199DCC;
    case 0x80199DD0u: goto label_80199DD0;
    case 0x80199DD4u: goto label_80199DD4;
    case 0x80199DD8u: goto label_80199DD8;
    case 0x80199DDCu: goto label_80199DDC;
    case 0x80199DE0u: goto label_80199DE0;
    case 0x80199DE4u: goto label_80199DE4;
    case 0x80199DE8u: goto label_80199DE8;
    case 0x80199DECu: goto label_80199DEC;
    case 0x80199DF0u: goto label_80199DF0;
    case 0x80199DF4u: goto label_80199DF4;
    case 0x80199DF8u: goto label_80199DF8;
    case 0x80199DFCu: goto label_80199DFC;
    case 0x80199E00u: goto label_80199E00;
    case 0x80199E04u: goto label_80199E04;
    case 0x80199E08u: goto label_80199E08;
    case 0x80199E0Cu: goto label_80199E0C;
    case 0x80199E10u: goto label_80199E10;
    case 0x80199E14u: goto label_80199E14;
    case 0x80199E18u: goto label_80199E18;
    case 0x80199E1Cu: goto label_80199E1C;
    case 0x80199E20u: goto label_80199E20;
    case 0x80199E24u: goto label_80199E24;
    case 0x80199E28u: goto label_80199E28;
    case 0x80199E2Cu: goto label_80199E2C;
    case 0x80199E30u: goto label_80199E30;
    case 0x80199E34u: goto label_80199E34;
    case 0x80199E38u: goto label_80199E38;
    case 0x80199E3Cu: goto label_80199E3C;
    case 0x80199E40u: goto label_80199E40;
    case 0x80199E44u: goto label_80199E44;
    case 0x80199E48u: goto label_80199E48;
    case 0x80199E4Cu: goto label_80199E4C;
    case 0x80199E50u: goto label_80199E50;
    case 0x80199E54u: goto label_80199E54;
    case 0x80199E58u: goto label_80199E58;
    case 0x80199E5Cu: goto label_80199E5C;
    case 0x80199E60u: goto label_80199E60;
    case 0x80199E64u: goto label_80199E64;
    case 0x80199E68u: goto label_80199E68;
    case 0x80199E6Cu: goto label_80199E6C;
    case 0x80199E70u: goto label_80199E70;
    case 0x80199E74u: goto label_80199E74;
    case 0x80199E78u: goto label_80199E78;
    case 0x80199E7Cu: goto label_80199E7C;
    case 0x80199E80u: goto label_80199E80;
    case 0x80199E84u: goto label_80199E84;
    case 0x80199E88u: goto label_80199E88;
    case 0x80199E8Cu: goto label_80199E8C;
    case 0x80199E90u: goto label_80199E90;
    case 0x80199E94u: goto label_80199E94;
    case 0x80199E98u: goto label_80199E98;
    case 0x80199E9Cu: goto label_80199E9C;
    case 0x80199EA0u: goto label_80199EA0;
    case 0x80199EA4u: goto label_80199EA4;
    case 0x80199EA8u: goto label_80199EA8;
    case 0x80199EACu: goto label_80199EAC;
    case 0x80199EB0u: goto label_80199EB0;
    case 0x80199EB4u: goto label_80199EB4;
    case 0x80199EB8u: goto label_80199EB8;
    case 0x80199EBCu: goto label_80199EBC;
    case 0x80199EC0u: goto label_80199EC0;
    case 0x80199EC4u: goto label_80199EC4;
    case 0x80199EC8u: goto label_80199EC8;
    case 0x80199ECCu: goto label_80199ECC;
    case 0x80199ED0u: goto label_80199ED0;
    case 0x80199ED4u: goto label_80199ED4;
    case 0x80199ED8u: goto label_80199ED8;
    case 0x80199EDCu: goto label_80199EDC;
    case 0x80199EE0u: goto label_80199EE0;
    case 0x80199EE4u: goto label_80199EE4;
    case 0x80199EE8u: goto label_80199EE8;
    case 0x80199EECu: goto label_80199EEC;
    case 0x80199EF0u: goto label_80199EF0;
    case 0x80199EF4u: goto label_80199EF4;
    case 0x80199EF8u: goto label_80199EF8;
    case 0x80199EFCu: goto label_80199EFC;
    case 0x80199F00u: goto label_80199F00;
    case 0x80199F04u: goto label_80199F04;
    case 0x80199F08u: goto label_80199F08;
    case 0x80199F0Cu: goto label_80199F0C;
    case 0x80199F10u: goto label_80199F10;
    case 0x80199F14u: goto label_80199F14;
    case 0x80199F18u: goto label_80199F18;
    case 0x80199F1Cu: goto label_80199F1C;
    case 0x80199F20u: goto label_80199F20;
    case 0x80199F24u: goto label_80199F24;
    case 0x80199F28u: goto label_80199F28;
    case 0x80199F2Cu: goto label_80199F2C;
    case 0x80199F30u: goto label_80199F30;
    case 0x80199F34u: goto label_80199F34;
    case 0x80199F38u: goto label_80199F38;
    case 0x80199F3Cu: goto label_80199F3C;
    case 0x80199F40u: goto label_80199F40;
    case 0x80199F44u: goto label_80199F44;
    case 0x80199F48u: goto label_80199F48;
    case 0x80199F4Cu: goto label_80199F4C;
    case 0x80199F50u: goto label_80199F50;
    case 0x80199F54u: goto label_80199F54;
    case 0x80199F58u: goto label_80199F58;
    case 0x80199F5Cu: goto label_80199F5C;
    case 0x80199F60u: goto label_80199F60;
    case 0x80199F64u: goto label_80199F64;
    case 0x80199F68u: goto label_80199F68;
    case 0x80199F6Cu: goto label_80199F6C;
    case 0x80199F70u: goto label_80199F70;
    case 0x80199F74u: goto label_80199F74;
    case 0x80199F78u: goto label_80199F78;
    case 0x80199F7Cu: goto label_80199F7C;
    case 0x80199F80u: goto label_80199F80;
    case 0x80199F84u: goto label_80199F84;
    case 0x80199F88u: goto label_80199F88;
    case 0x80199F8Cu: goto label_80199F8C;
    case 0x80199F90u: goto label_80199F90;
    case 0x80199F94u: goto label_80199F94;
    case 0x80199F98u: goto label_80199F98;
    case 0x80199F9Cu: goto label_80199F9C;
    case 0x80199FA0u: goto label_80199FA0;
    case 0x80199FA4u: goto label_80199FA4;
    case 0x80199FA8u: goto label_80199FA8;
    case 0x80199FACu: goto label_80199FAC;
    case 0x80199FB0u: goto label_80199FB0;
    case 0x80199FB4u: goto label_80199FB4;
    case 0x80199FB8u: goto label_80199FB8;
    case 0x80199FBCu: goto label_80199FBC;
    case 0x80199FC0u: goto label_80199FC0;
    case 0x80199FC4u: goto label_80199FC4;
    case 0x80199FC8u: goto label_80199FC8;
    case 0x80199FCCu: goto label_80199FCC;
    case 0x80199FD0u: goto label_80199FD0;
    case 0x80199FD4u: goto label_80199FD4;
    case 0x80199FD8u: goto label_80199FD8;
    case 0x80199FDCu: goto label_80199FDC;
    case 0x80199FE0u: goto label_80199FE0;
    case 0x80199FE4u: goto label_80199FE4;
    case 0x80199FE8u: goto label_80199FE8;
    case 0x80199FECu: goto label_80199FEC;
    case 0x80199FF0u: goto label_80199FF0;
    case 0x80199FF4u: goto label_80199FF4;
    case 0x80199FF8u: goto label_80199FF8;
    case 0x80199FFCu: goto label_80199FFC;
    case 0x8019A000u: goto label_8019A000;
    case 0x8019A004u: goto label_8019A004;
    case 0x8019A008u: goto label_8019A008;
    case 0x8019A00Cu: goto label_8019A00C;
    case 0x8019A010u: goto label_8019A010;
    case 0x8019A014u: goto label_8019A014;
    case 0x8019A018u: goto label_8019A018;
    case 0x8019A01Cu: goto label_8019A01C;
    case 0x8019A020u: goto label_8019A020;
    case 0x8019A024u: goto label_8019A024;
    case 0x8019A028u: goto label_8019A028;
    case 0x8019A02Cu: goto label_8019A02C;
    case 0x8019A030u: goto label_8019A030;
    case 0x8019A034u: goto label_8019A034;
    case 0x8019A038u: goto label_8019A038;
    case 0x8019A03Cu: goto label_8019A03C;
    case 0x8019A040u: goto label_8019A040;
    case 0x8019A044u: goto label_8019A044;
    case 0x8019A048u: goto label_8019A048;
    case 0x8019A04Cu: goto label_8019A04C;
    case 0x8019A050u: goto label_8019A050;
    case 0x8019A054u: goto label_8019A054;
    case 0x8019A058u: goto label_8019A058;
    case 0x8019A05Cu: goto label_8019A05C;
    case 0x8019A060u: goto label_8019A060;
    case 0x8019A064u: goto label_8019A064;
    case 0x8019A068u: goto label_8019A068;
    case 0x8019A06Cu: goto label_8019A06C;
    case 0x8019A070u: goto label_8019A070;
    case 0x8019A074u: goto label_8019A074;
    case 0x8019A078u: goto label_8019A078;
    case 0x8019A07Cu: goto label_8019A07C;
    case 0x8019A080u: goto label_8019A080;
    case 0x8019A084u: goto label_8019A084;
    case 0x8019A088u: goto label_8019A088;
    case 0x8019A08Cu: goto label_8019A08C;
    case 0x8019A090u: goto label_8019A090;
    case 0x8019A094u: goto label_8019A094;
    case 0x8019A098u: goto label_8019A098;
    case 0x8019A09Cu: goto label_8019A09C;
    case 0x8019A0A0u: goto label_8019A0A0;
    case 0x8019A0A4u: goto label_8019A0A4;
    case 0x8019A0A8u: goto label_8019A0A8;
    case 0x8019A0ACu: goto label_8019A0AC;
    case 0x8019A0B0u: goto label_8019A0B0;
    case 0x8019A0B4u: goto label_8019A0B4;
    case 0x8019A0B8u: goto label_8019A0B8;
    case 0x8019A0BCu: goto label_8019A0BC;
    case 0x8019A0C0u: goto label_8019A0C0;
    case 0x8019A0C4u: goto label_8019A0C4;
    case 0x8019A0C8u: goto label_8019A0C8;
    case 0x8019A0CCu: goto label_8019A0CC;
    case 0x8019A0D0u: goto label_8019A0D0;
    case 0x8019A0D4u: goto label_8019A0D4;
    case 0x8019A0D8u: goto label_8019A0D8;
    case 0x8019A0DCu: goto label_8019A0DC;
    case 0x8019A0E0u: goto label_8019A0E0;
    case 0x8019A0E4u: goto label_8019A0E4;
    case 0x8019A0E8u: goto label_8019A0E8;
    case 0x8019A0ECu: goto label_8019A0EC;
    case 0x8019A0F0u: goto label_8019A0F0;
    case 0x8019A0F4u: goto label_8019A0F4;
    case 0x8019A0F8u: goto label_8019A0F8;
    case 0x8019A0FCu: goto label_8019A0FC;
    case 0x8019A100u: goto label_8019A100;
    case 0x8019A104u: goto label_8019A104;
    case 0x8019A108u: goto label_8019A108;
    case 0x8019A10Cu: goto label_8019A10C;
    case 0x8019A110u: goto label_8019A110;
    case 0x8019A114u: goto label_8019A114;
    case 0x8019A118u: goto label_8019A118;
    case 0x8019A11Cu: goto label_8019A11C;
    case 0x8019A120u: goto label_8019A120;
    case 0x8019A124u: goto label_8019A124;
    case 0x8019A128u: goto label_8019A128;
    case 0x8019A12Cu: goto label_8019A12C;
    case 0x8019A130u: goto label_8019A130;
    case 0x8019A134u: goto label_8019A134;
    case 0x8019A138u: goto label_8019A138;
    case 0x8019A13Cu: goto label_8019A13C;
    case 0x8019A140u: goto label_8019A140;
    case 0x8019A144u: goto label_8019A144;
    case 0x8019A148u: goto label_8019A148;
    case 0x8019A14Cu: goto label_8019A14C;
    case 0x8019A150u: goto label_8019A150;
    case 0x8019A154u: goto label_8019A154;
    case 0x8019A158u: goto label_8019A158;
    case 0x8019A15Cu: goto label_8019A15C;
    case 0x8019A160u: goto label_8019A160;
    case 0x8019A164u: goto label_8019A164;
    case 0x8019A168u: goto label_8019A168;
    case 0x8019A16Cu: goto label_8019A16C;
    case 0x8019A170u: goto label_8019A170;
    case 0x8019A174u: goto label_8019A174;
    case 0x8019A178u: goto label_8019A178;
    case 0x8019A17Cu: goto label_8019A17C;
    case 0x8019A180u: goto label_8019A180;
    case 0x8019A184u: goto label_8019A184;
    case 0x8019A188u: goto label_8019A188;
    case 0x8019A18Cu: goto label_8019A18C;
    case 0x8019A190u: goto label_8019A190;
    case 0x8019A194u: goto label_8019A194;
    case 0x8019A198u: goto label_8019A198;
    case 0x8019A19Cu: goto label_8019A19C;
    case 0x8019A1A0u: goto label_8019A1A0;
    case 0x8019A1A4u: goto label_8019A1A4;
    case 0x8019A1A8u: goto label_8019A1A8;
    case 0x8019A1ACu: goto label_8019A1AC;
    case 0x8019A1B0u: goto label_8019A1B0;
    case 0x8019A1B4u: goto label_8019A1B4;
    case 0x8019A1B8u: goto label_8019A1B8;
    case 0x8019A1BCu: goto label_8019A1BC;
    case 0x8019A1C0u: goto label_8019A1C0;
    case 0x8019A1C4u: goto label_8019A1C4;
    case 0x8019A1C8u: goto label_8019A1C8;
    case 0x8019A1CCu: goto label_8019A1CC;
    case 0x8019A1D0u: goto label_8019A1D0;
    case 0x8019A1D4u: goto label_8019A1D4;
    case 0x8019A1D8u: goto label_8019A1D8;
    case 0x8019A1DCu: goto label_8019A1DC;
    case 0x8019A1E0u: goto label_8019A1E0;
    case 0x8019A1E4u: goto label_8019A1E4;
    case 0x8019A1E8u: goto label_8019A1E8;
    case 0x8019A1ECu: goto label_8019A1EC;
    case 0x8019A1F0u: goto label_8019A1F0;
    case 0x8019A1F4u: goto label_8019A1F4;
    case 0x8019A1F8u: goto label_8019A1F8;
    case 0x8019A1FCu: goto label_8019A1FC;
    case 0x8019A200u: goto label_8019A200;
    case 0x8019A204u: goto label_8019A204;
    case 0x8019A208u: goto label_8019A208;
    case 0x8019A20Cu: goto label_8019A20C;
    case 0x8019A210u: goto label_8019A210;
    case 0x8019A214u: goto label_8019A214;
    case 0x8019A218u: goto label_8019A218;
    case 0x8019A21Cu: goto label_8019A21C;
    case 0x8019A220u: goto label_8019A220;
    case 0x8019A224u: goto label_8019A224;
    case 0x8019A228u: goto label_8019A228;
    case 0x8019A22Cu: goto label_8019A22C;
    case 0x8019A230u: goto label_8019A230;
    case 0x8019A234u: goto label_8019A234;
    case 0x8019A238u: goto label_8019A238;
    case 0x8019A23Cu: goto label_8019A23C;
    case 0x8019A240u: goto label_8019A240;
    case 0x8019A244u: goto label_8019A244;
    case 0x8019A248u: goto label_8019A248;
    case 0x8019A24Cu: goto label_8019A24C;
    case 0x8019A250u: goto label_8019A250;
    case 0x8019A254u: goto label_8019A254;
    case 0x8019A258u: goto label_8019A258;
    case 0x8019A25Cu: goto label_8019A25C;
    case 0x8019A260u: goto label_8019A260;
    case 0x8019A264u: goto label_8019A264;
    case 0x8019A268u: goto label_8019A268;
    case 0x8019A26Cu: goto label_8019A26C;
    case 0x8019A270u: goto label_8019A270;
    case 0x8019A274u: goto label_8019A274;
    case 0x8019A278u: goto label_8019A278;
    case 0x8019A27Cu: goto label_8019A27C;
    case 0x8019A280u: goto label_8019A280;
    case 0x8019A284u: goto label_8019A284;
    case 0x8019A288u: goto label_8019A288;
    case 0x8019A28Cu: goto label_8019A28C;
    case 0x8019A290u: goto label_8019A290;
    case 0x8019A294u: goto label_8019A294;
    case 0x8019A298u: goto label_8019A298;
    case 0x8019A29Cu: goto label_8019A29C;
    case 0x8019A2A0u: goto label_8019A2A0;
    case 0x8019A2A4u: goto label_8019A2A4;
    case 0x8019A2A8u: goto label_8019A2A8;
    case 0x8019A2ACu: goto label_8019A2AC;
    case 0x8019A2B0u: goto label_8019A2B0;
    case 0x8019A2B4u: goto label_8019A2B4;
    case 0x8019A2B8u: goto label_8019A2B8;
    case 0x8019A2BCu: goto label_8019A2BC;
    case 0x8019A2C0u: goto label_8019A2C0;
    case 0x8019A2C4u: goto label_8019A2C4;
    case 0x8019A2C8u: goto label_8019A2C8;
    case 0x8019A2CCu: goto label_8019A2CC;
    case 0x8019A2D0u: goto label_8019A2D0;
    case 0x8019A2D4u: goto label_8019A2D4;
    case 0x8019A2D8u: goto label_8019A2D8;
    case 0x8019A2DCu: goto label_8019A2DC;
    case 0x8019A2E0u: goto label_8019A2E0;
    case 0x8019A2E4u: goto label_8019A2E4;
    case 0x8019A2E8u: goto label_8019A2E8;
    case 0x8019A2ECu: goto label_8019A2EC;
    case 0x8019A2F0u: goto label_8019A2F0;
    case 0x8019A2F4u: goto label_8019A2F4;
    case 0x8019A2F8u: goto label_8019A2F8;
    case 0x8019A2FCu: goto label_8019A2FC;
    case 0x8019A300u: goto label_8019A300;
    case 0x8019A304u: goto label_8019A304;
    case 0x8019A308u: goto label_8019A308;
    case 0x8019A30Cu: goto label_8019A30C;
    case 0x8019A310u: goto label_8019A310;
    case 0x8019A314u: goto label_8019A314;
    case 0x8019A318u: goto label_8019A318;
    case 0x8019A31Cu: goto label_8019A31C;
    case 0x8019A320u: goto label_8019A320;
    case 0x8019A324u: goto label_8019A324;
    case 0x8019A328u: goto label_8019A328;
    case 0x8019A32Cu: goto label_8019A32C;
    case 0x8019A330u: goto label_8019A330;
    case 0x8019A334u: goto label_8019A334;
    case 0x8019A338u: goto label_8019A338;
    case 0x8019A33Cu: goto label_8019A33C;
    case 0x8019A340u: goto label_8019A340;
    case 0x8019A344u: goto label_8019A344;
    case 0x8019A348u: goto label_8019A348;
    case 0x8019A34Cu: goto label_8019A34C;
    case 0x8019A350u: goto label_8019A350;
    case 0x8019A354u: goto label_8019A354;
    case 0x8019A358u: goto label_8019A358;
    case 0x8019A35Cu: goto label_8019A35C;
    case 0x8019A360u: goto label_8019A360;
    case 0x8019A364u: goto label_8019A364;
    case 0x8019A368u: goto label_8019A368;
    case 0x8019A36Cu: goto label_8019A36C;
    case 0x8019A370u: goto label_8019A370;
    case 0x8019A374u: goto label_8019A374;
    case 0x8019A378u: goto label_8019A378;
    case 0x8019A37Cu: goto label_8019A37C;
    case 0x8019A380u: goto label_8019A380;
    case 0x8019A384u: goto label_8019A384;
    case 0x8019A388u: goto label_8019A388;
    case 0x8019A38Cu: goto label_8019A38C;
    case 0x8019A390u: goto label_8019A390;
    case 0x8019A394u: goto label_8019A394;
    case 0x8019A398u: goto label_8019A398;
    case 0x8019A39Cu: goto label_8019A39C;
    case 0x8019A3A0u: goto label_8019A3A0;
    case 0x8019A3A4u: goto label_8019A3A4;
    case 0x8019A3A8u: goto label_8019A3A8;
    case 0x8019A3ACu: goto label_8019A3AC;
    case 0x8019A3B0u: goto label_8019A3B0;
    case 0x8019A3B4u: goto label_8019A3B4;
    case 0x8019A3B8u: goto label_8019A3B8;
    case 0x8019A3BCu: goto label_8019A3BC;
    case 0x8019A3C0u: goto label_8019A3C0;
    case 0x8019A3C4u: goto label_8019A3C4;
    case 0x8019A3C8u: goto label_8019A3C8;
    case 0x8019A3CCu: goto label_8019A3CC;
    case 0x8019A3D0u: goto label_8019A3D0;
    case 0x8019A3D4u: goto label_8019A3D4;
    case 0x8019A3D8u: goto label_8019A3D8;
    case 0x8019A3DCu: goto label_8019A3DC;
    case 0x8019A3E0u: goto label_8019A3E0;
    case 0x8019A3E4u: goto label_8019A3E4;
    case 0x8019A3E8u: goto label_8019A3E8;
    case 0x8019A3ECu: goto label_8019A3EC;
    case 0x8019A3F0u: goto label_8019A3F0;
    case 0x8019A3F4u: goto label_8019A3F4;
    case 0x8019A3F8u: goto label_8019A3F8;
    case 0x8019A3FCu: goto label_8019A3FC;
    case 0x8019A400u: goto label_8019A400;
    case 0x8019A404u: goto label_8019A404;
    case 0x8019A408u: goto label_8019A408;
    case 0x8019A40Cu: goto label_8019A40C;
    case 0x8019A410u: goto label_8019A410;
    case 0x8019A414u: goto label_8019A414;
    case 0x8019A418u: goto label_8019A418;
    case 0x8019A41Cu: goto label_8019A41C;
    case 0x8019A420u: goto label_8019A420;
    case 0x8019A424u: goto label_8019A424;
    case 0x8019A428u: goto label_8019A428;
    case 0x8019A42Cu: goto label_8019A42C;
    case 0x8019A430u: goto label_8019A430;
    case 0x8019A434u: goto label_8019A434;
    case 0x8019A438u: goto label_8019A438;
    case 0x8019A43Cu: goto label_8019A43C;
    case 0x8019A440u: goto label_8019A440;
    case 0x8019A444u: goto label_8019A444;
    case 0x8019A448u: goto label_8019A448;
    case 0x8019A44Cu: goto label_8019A44C;
    case 0x8019A450u: goto label_8019A450;
    case 0x8019A454u: goto label_8019A454;
    case 0x8019A458u: goto label_8019A458;
    case 0x8019A45Cu: goto label_8019A45C;
    case 0x8019A460u: goto label_8019A460;
    case 0x8019A464u: goto label_8019A464;
    case 0x8019A468u: goto label_8019A468;
    case 0x8019A46Cu: goto label_8019A46C;
    case 0x8019A470u: goto label_8019A470;
    case 0x8019A474u: goto label_8019A474;
    case 0x8019A478u: goto label_8019A478;
    case 0x8019A47Cu: goto label_8019A47C;
    case 0x8019A480u: goto label_8019A480;
    case 0x8019A484u: goto label_8019A484;
    case 0x8019A488u: goto label_8019A488;
    case 0x8019A48Cu: goto label_8019A48C;
    case 0x8019A490u: goto label_8019A490;
    case 0x8019A494u: goto label_8019A494;
    case 0x8019A498u: goto label_8019A498;
    case 0x8019A49Cu: goto label_8019A49C;
    case 0x8019A4A0u: goto label_8019A4A0;
    case 0x8019A4A4u: goto label_8019A4A4;
    case 0x8019A4A8u: goto label_8019A4A8;
    case 0x8019A4ACu: goto label_8019A4AC;
    case 0x8019A4B0u: goto label_8019A4B0;
    case 0x8019A4B4u: goto label_8019A4B4;
    case 0x8019A4B8u: goto label_8019A4B8;
    case 0x8019A4BCu: goto label_8019A4BC;
    case 0x8019A4C0u: goto label_8019A4C0;
    case 0x8019A4C4u: goto label_8019A4C4;
    case 0x8019A4C8u: goto label_8019A4C8;
    case 0x8019A4CCu: goto label_8019A4CC;
    case 0x8019A4D0u: goto label_8019A4D0;
    case 0x8019A4D4u: goto label_8019A4D4;
    case 0x8019A4D8u: goto label_8019A4D8;
    case 0x8019A4DCu: goto label_8019A4DC;
    case 0x8019A4E0u: goto label_8019A4E0;
    case 0x8019A4E4u: goto label_8019A4E4;
    case 0x8019A4E8u: goto label_8019A4E8;
    case 0x8019A4ECu: goto label_8019A4EC;
    case 0x8019A4F0u: goto label_8019A4F0;
    case 0x8019A4F4u: goto label_8019A4F4;
    case 0x8019A4F8u: goto label_8019A4F8;
    case 0x8019A4FCu: goto label_8019A4FC;
    case 0x8019A500u: goto label_8019A500;
    case 0x8019A504u: goto label_8019A504;
    case 0x8019A508u: goto label_8019A508;
    case 0x8019A50Cu: goto label_8019A50C;
    case 0x8019A510u: goto label_8019A510;
    case 0x8019A514u: goto label_8019A514;
    case 0x8019A518u: goto label_8019A518;
    case 0x8019A51Cu: goto label_8019A51C;
    case 0x8019A520u: goto label_8019A520;
    case 0x8019A524u: goto label_8019A524;
    case 0x8019A528u: goto label_8019A528;
    case 0x8019A52Cu: goto label_8019A52C;
    case 0x8019A530u: goto label_8019A530;
    case 0x8019A534u: goto label_8019A534;
    case 0x8019A538u: goto label_8019A538;
    case 0x8019A53Cu: goto label_8019A53C;
    case 0x8019A540u: goto label_8019A540;
    case 0x8019A544u: goto label_8019A544;
    case 0x8019A548u: goto label_8019A548;
    case 0x8019A54Cu: goto label_8019A54C;
    case 0x8019A550u: goto label_8019A550;
    case 0x8019A554u: goto label_8019A554;
    case 0x8019A558u: goto label_8019A558;
    case 0x8019A55Cu: goto label_8019A55C;
    case 0x8019A560u: goto label_8019A560;
    case 0x8019A564u: goto label_8019A564;
    case 0x8019A568u: goto label_8019A568;
    case 0x8019A56Cu: goto label_8019A56C;
    case 0x8019A570u: goto label_8019A570;
    case 0x8019A574u: goto label_8019A574;
    case 0x8019A578u: goto label_8019A578;
    case 0x8019A57Cu: goto label_8019A57C;
    case 0x8019A580u: goto label_8019A580;
    case 0x8019A584u: goto label_8019A584;
    case 0x8019A588u: goto label_8019A588;
    case 0x8019A58Cu: goto label_8019A58C;
    case 0x8019A590u: goto label_8019A590;
    case 0x8019A594u: goto label_8019A594;
    case 0x8019A598u: goto label_8019A598;
    case 0x8019A59Cu: goto label_8019A59C;
    case 0x8019A5A0u: goto label_8019A5A0;
    case 0x8019A5A4u: goto label_8019A5A4;
    case 0x8019A5A8u: goto label_8019A5A8;
    case 0x8019A5ACu: goto label_8019A5AC;
    case 0x8019A5B0u: goto label_8019A5B0;
    case 0x8019A5B4u: goto label_8019A5B4;
    case 0x8019A5B8u: goto label_8019A5B8;
    case 0x8019A5BCu: goto label_8019A5BC;
    case 0x8019A5C0u: goto label_8019A5C0;
    case 0x8019A5C4u: goto label_8019A5C4;
    case 0x8019A5C8u: goto label_8019A5C8;
    case 0x8019A5CCu: goto label_8019A5CC;
    case 0x8019A5D0u: goto label_8019A5D0;
    case 0x8019A5D4u: goto label_8019A5D4;
    case 0x8019A5D8u: goto label_8019A5D8;
    case 0x8019A5DCu: goto label_8019A5DC;
    case 0x8019A5E0u: goto label_8019A5E0;
    case 0x8019A5E4u: goto label_8019A5E4;
    case 0x8019A5E8u: goto label_8019A5E8;
    case 0x8019A5ECu: goto label_8019A5EC;
    case 0x8019A5F0u: goto label_8019A5F0;
    case 0x8019A5F4u: goto label_8019A5F4;
    case 0x8019A5F8u: goto label_8019A5F8;
    case 0x8019A5FCu: goto label_8019A5FC;
    case 0x8019A600u: goto label_8019A600;
    case 0x8019A604u: goto label_8019A604;
    case 0x8019A608u: goto label_8019A608;
    case 0x8019A60Cu: goto label_8019A60C;
    case 0x8019A610u: goto label_8019A610;
    case 0x8019A614u: goto label_8019A614;
    case 0x8019A618u: goto label_8019A618;
    case 0x8019A61Cu: goto label_8019A61C;
    case 0x8019A620u: goto label_8019A620;
    case 0x8019A624u: goto label_8019A624;
    case 0x8019A628u: goto label_8019A628;
    case 0x8019A62Cu: goto label_8019A62C;
    case 0x8019A630u: goto label_8019A630;
    case 0x8019A634u: goto label_8019A634;
    case 0x8019A638u: goto label_8019A638;
    case 0x8019A63Cu: goto label_8019A63C;
    case 0x8019A640u: goto label_8019A640;
    case 0x8019A644u: goto label_8019A644;
    case 0x8019A648u: goto label_8019A648;
    case 0x8019A64Cu: goto label_8019A64C;
    case 0x8019A650u: goto label_8019A650;
    case 0x8019A654u: goto label_8019A654;
    case 0x8019A658u: goto label_8019A658;
    case 0x8019A65Cu: goto label_8019A65C;
    case 0x8019A660u: goto label_8019A660;
    case 0x8019A664u: goto label_8019A664;
    case 0x8019A668u: goto label_8019A668;
    case 0x8019A66Cu: goto label_8019A66C;
    case 0x8019A670u: goto label_8019A670;
    case 0x8019A674u: goto label_8019A674;
    case 0x8019A678u: goto label_8019A678;
    case 0x8019A67Cu: goto label_8019A67C;
    case 0x8019A680u: goto label_8019A680;
    case 0x8019A684u: goto label_8019A684;
    case 0x8019A688u: goto label_8019A688;
    case 0x8019A68Cu: goto label_8019A68C;
    case 0x8019A690u: goto label_8019A690;
    case 0x8019A694u: goto label_8019A694;
    case 0x8019A698u: goto label_8019A698;
    case 0x8019A69Cu: goto label_8019A69C;
    case 0x8019A6A0u: goto label_8019A6A0;
    case 0x8019A6A4u: goto label_8019A6A4;
    case 0x8019A6A8u: goto label_8019A6A8;
    case 0x8019A6ACu: goto label_8019A6AC;
    case 0x8019A6B0u: goto label_8019A6B0;
    case 0x8019A6B4u: goto label_8019A6B4;
    case 0x8019A6B8u: goto label_8019A6B8;
    case 0x8019A6BCu: goto label_8019A6BC;
    case 0x8019A6C0u: goto label_8019A6C0;
    case 0x8019A6C4u: goto label_8019A6C4;
    case 0x8019A6C8u: goto label_8019A6C8;
    case 0x8019A6CCu: goto label_8019A6CC;
    case 0x8019A6D0u: goto label_8019A6D0;
    case 0x8019A6D4u: goto label_8019A6D4;
    case 0x8019A6D8u: goto label_8019A6D8;
    case 0x8019A6DCu: goto label_8019A6DC;
    case 0x8019A6E0u: goto label_8019A6E0;
    case 0x8019A6E4u: goto label_8019A6E4;
    case 0x8019A6E8u: goto label_8019A6E8;
    case 0x8019A6ECu: goto label_8019A6EC;
    case 0x8019A6F0u: goto label_8019A6F0;
    case 0x8019A6F4u: goto label_8019A6F4;
    case 0x8019A6F8u: goto label_8019A6F8;
    case 0x8019A6FCu: goto label_8019A6FC;
    case 0x8019A700u: goto label_8019A700;
    case 0x8019A704u: goto label_8019A704;
    case 0x8019A708u: goto label_8019A708;
    case 0x8019A70Cu: goto label_8019A70C;
    case 0x8019A710u: goto label_8019A710;
    case 0x8019A714u: goto label_8019A714;
    case 0x8019A718u: goto label_8019A718;
    case 0x8019A71Cu: goto label_8019A71C;
    case 0x8019A720u: goto label_8019A720;
    case 0x8019A724u: goto label_8019A724;
    case 0x8019A728u: goto label_8019A728;
    case 0x8019A72Cu: goto label_8019A72C;
    case 0x8019A730u: goto label_8019A730;
    case 0x8019A734u: goto label_8019A734;
    case 0x8019A738u: goto label_8019A738;
    case 0x8019A73Cu: goto label_8019A73C;
    case 0x8019A740u: goto label_8019A740;
    case 0x8019A744u: goto label_8019A744;
    case 0x8019A748u: goto label_8019A748;
    case 0x8019A74Cu: goto label_8019A74C;
    case 0x8019A750u: goto label_8019A750;
    case 0x8019A754u: goto label_8019A754;
    case 0x8019A758u: goto label_8019A758;
    case 0x8019A75Cu: goto label_8019A75C;
    case 0x8019A760u: goto label_8019A760;
    case 0x8019A764u: goto label_8019A764;
    case 0x8019A768u: goto label_8019A768;
    case 0x8019A76Cu: goto label_8019A76C;
    case 0x8019A770u: goto label_8019A770;
    case 0x8019A774u: goto label_8019A774;
    case 0x8019A778u: goto label_8019A778;
    case 0x8019A77Cu: goto label_8019A77C;
    case 0x8019A780u: goto label_8019A780;
    case 0x8019A784u: goto label_8019A784;
    case 0x8019A788u: goto label_8019A788;
    case 0x8019A78Cu: goto label_8019A78C;
    case 0x8019A790u: goto label_8019A790;
    case 0x8019A794u: goto label_8019A794;
    case 0x8019A798u: goto label_8019A798;
    case 0x8019A79Cu: goto label_8019A79C;
    case 0x8019A7A0u: goto label_8019A7A0;
    case 0x8019A7A4u: goto label_8019A7A4;
    case 0x8019A7A8u: goto label_8019A7A8;
    case 0x8019A7ACu: goto label_8019A7AC;
    case 0x8019A7B0u: goto label_8019A7B0;
    case 0x8019A7B4u: goto label_8019A7B4;
    case 0x8019A7B8u: goto label_8019A7B8;
    case 0x8019A7BCu: goto label_8019A7BC;
    case 0x8019A7C0u: goto label_8019A7C0;
    case 0x8019A7C4u: goto label_8019A7C4;
    case 0x8019A7C8u: goto label_8019A7C8;
    case 0x8019A7CCu: goto label_8019A7CC;
    case 0x8019A7D0u: goto label_8019A7D0;
    case 0x8019A7D4u: goto label_8019A7D4;
    case 0x8019A7D8u: goto label_8019A7D8;
    case 0x8019A7DCu: goto label_8019A7DC;
    case 0x8019A7E0u: goto label_8019A7E0;
    case 0x8019A7E4u: goto label_8019A7E4;
    case 0x8019A7E8u: goto label_8019A7E8;
    case 0x8019A7ECu: goto label_8019A7EC;
    case 0x8019A7F0u: goto label_8019A7F0;
    case 0x8019A7F4u: goto label_8019A7F4;
    case 0x8019A7F8u: goto label_8019A7F8;
    case 0x8019A7FCu: goto label_8019A7FC;
    case 0x8019A800u: goto label_8019A800;
    case 0x8019A804u: goto label_8019A804;
    case 0x8019A808u: goto label_8019A808;
    case 0x8019A80Cu: goto label_8019A80C;
    case 0x8019A810u: goto label_8019A810;
    case 0x8019A814u: goto label_8019A814;
    case 0x8019A818u: goto label_8019A818;
    case 0x8019A81Cu: goto label_8019A81C;
    case 0x8019A820u: goto label_8019A820;
    case 0x8019A824u: goto label_8019A824;
    case 0x8019A828u: goto label_8019A828;
    case 0x8019A82Cu: goto label_8019A82C;
    case 0x8019A830u: goto label_8019A830;
    case 0x8019A834u: goto label_8019A834;
    case 0x8019A838u: goto label_8019A838;
    case 0x8019A83Cu: goto label_8019A83C;
    case 0x8019A840u: goto label_8019A840;
    case 0x8019A844u: goto label_8019A844;
    case 0x8019A848u: goto label_8019A848;
    case 0x8019A84Cu: goto label_8019A84C;
    case 0x8019A850u: goto label_8019A850;
    case 0x8019A854u: goto label_8019A854;
    case 0x8019A858u: goto label_8019A858;
    case 0x8019A85Cu: goto label_8019A85C;
    case 0x8019A860u: goto label_8019A860;
    case 0x8019A864u: goto label_8019A864;
    case 0x8019A868u: goto label_8019A868;
    case 0x8019A86Cu: goto label_8019A86C;
    case 0x8019A870u: goto label_8019A870;
    case 0x8019A874u: goto label_8019A874;
    case 0x8019A878u: goto label_8019A878;
    case 0x8019A87Cu: goto label_8019A87C;
    case 0x8019A880u: goto label_8019A880;
    case 0x8019A884u: goto label_8019A884;
    case 0x8019A888u: goto label_8019A888;
    case 0x8019A88Cu: goto label_8019A88C;
    case 0x8019A890u: goto label_8019A890;
    case 0x8019A894u: goto label_8019A894;
    case 0x8019A898u: goto label_8019A898;
    case 0x8019A89Cu: goto label_8019A89C;
    case 0x8019A8A0u: goto label_8019A8A0;
    case 0x8019A8A4u: goto label_8019A8A4;
    case 0x8019A8A8u: goto label_8019A8A8;
    case 0x8019A8ACu: goto label_8019A8AC;
    case 0x8019A8B0u: goto label_8019A8B0;
    case 0x8019A8B4u: goto label_8019A8B4;
    case 0x8019A8B8u: goto label_8019A8B8;
    case 0x8019A8BCu: goto label_8019A8BC;
    case 0x8019A8C0u: goto label_8019A8C0;
    case 0x8019A8C4u: goto label_8019A8C4;
    case 0x8019A8C8u: goto label_8019A8C8;
    case 0x8019A8CCu: goto label_8019A8CC;
    case 0x8019A8D0u: goto label_8019A8D0;
    case 0x8019A8D4u: goto label_8019A8D4;
    case 0x8019A8D8u: goto label_8019A8D8;
    case 0x8019A8DCu: goto label_8019A8DC;
    case 0x8019A8E0u: goto label_8019A8E0;
    case 0x8019A8E4u: goto label_8019A8E4;
    case 0x8019A8E8u: goto label_8019A8E8;
    case 0x8019A8ECu: goto label_8019A8EC;
    case 0x8019A8F0u: goto label_8019A8F0;
    case 0x8019A8F4u: goto label_8019A8F4;
    case 0x8019A8F8u: goto label_8019A8F8;
    case 0x8019A8FCu: goto label_8019A8FC;
    case 0x8019A900u: goto label_8019A900;
    case 0x8019A904u: goto label_8019A904;
    case 0x8019A908u: goto label_8019A908;
    case 0x8019A90Cu: goto label_8019A90C;
    case 0x8019A910u: goto label_8019A910;
    case 0x8019A914u: goto label_8019A914;
    case 0x8019A918u: goto label_8019A918;
    case 0x8019A91Cu: goto label_8019A91C;
    case 0x8019A920u: goto label_8019A920;
    case 0x8019A924u: goto label_8019A924;
    case 0x8019A928u: goto label_8019A928;
    case 0x8019A92Cu: goto label_8019A92C;
    case 0x8019A930u: goto label_8019A930;
    case 0x8019A934u: goto label_8019A934;
    case 0x8019A938u: goto label_8019A938;
    case 0x8019A93Cu: goto label_8019A93C;
    case 0x8019A940u: goto label_8019A940;
    case 0x8019A944u: goto label_8019A944;
    case 0x8019A948u: goto label_8019A948;
    case 0x8019A94Cu: goto label_8019A94C;
    case 0x8019A950u: goto label_8019A950;
    case 0x8019A954u: goto label_8019A954;
    case 0x8019A958u: goto label_8019A958;
    case 0x8019A95Cu: goto label_8019A95C;
    case 0x8019A960u: goto label_8019A960;
    case 0x8019A964u: goto label_8019A964;
    case 0x8019A968u: goto label_8019A968;
    case 0x8019A96Cu: goto label_8019A96C;
    case 0x8019A970u: goto label_8019A970;
    case 0x8019A974u: goto label_8019A974;
    case 0x8019A978u: goto label_8019A978;
    case 0x8019A97Cu: goto label_8019A97C;
    case 0x8019A980u: goto label_8019A980;
    case 0x8019A984u: goto label_8019A984;
    case 0x8019A988u: goto label_8019A988;
    case 0x8019A98Cu: goto label_8019A98C;
    case 0x8019A990u: goto label_8019A990;
    case 0x8019A994u: goto label_8019A994;
    case 0x8019A998u: goto label_8019A998;
    case 0x8019A99Cu: goto label_8019A99C;
    case 0x8019A9A0u: goto label_8019A9A0;
    case 0x8019A9A4u: goto label_8019A9A4;
    case 0x8019A9A8u: goto label_8019A9A8;
    case 0x8019A9ACu: goto label_8019A9AC;
    case 0x8019A9B0u: goto label_8019A9B0;
    case 0x8019A9B4u: goto label_8019A9B4;
    case 0x8019A9B8u: goto label_8019A9B8;
    case 0x8019A9BCu: goto label_8019A9BC;
    case 0x8019A9C0u: goto label_8019A9C0;
    case 0x8019A9C4u: goto label_8019A9C4;
    case 0x8019A9C8u: goto label_8019A9C8;
    case 0x8019A9CCu: goto label_8019A9CC;
    case 0x8019A9D0u: goto label_8019A9D0;
    case 0x8019A9D4u: goto label_8019A9D4;
    case 0x8019A9D8u: goto label_8019A9D8;
    case 0x8019A9DCu: goto label_8019A9DC;
    case 0x8019A9E0u: goto label_8019A9E0;
    case 0x8019A9E4u: goto label_8019A9E4;
    case 0x8019A9E8u: goto label_8019A9E8;
    case 0x8019A9ECu: goto label_8019A9EC;
    case 0x8019A9F0u: goto label_8019A9F0;
    case 0x8019A9F4u: goto label_8019A9F4;
    case 0x8019A9F8u: goto label_8019A9F8;
    case 0x8019A9FCu: goto label_8019A9FC;
    case 0x8019AA00u: goto label_8019AA00;
    case 0x8019AA04u: goto label_8019AA04;
    case 0x8019AA08u: goto label_8019AA08;
    case 0x8019AA0Cu: goto label_8019AA0C;
    case 0x8019AA10u: goto label_8019AA10;
    case 0x8019AA14u: goto label_8019AA14;
    case 0x8019AA18u: goto label_8019AA18;
    case 0x8019AA1Cu: goto label_8019AA1C;
    case 0x8019AA20u: goto label_8019AA20;
    case 0x8019AA24u: goto label_8019AA24;
    case 0x8019AA28u: goto label_8019AA28;
    case 0x8019AA2Cu: goto label_8019AA2C;
    case 0x8019AA30u: goto label_8019AA30;
    case 0x8019AA34u: goto label_8019AA34;
    case 0x8019AA38u: goto label_8019AA38;
    case 0x8019AA3Cu: goto label_8019AA3C;
    case 0x8019AA40u: goto label_8019AA40;
    case 0x8019AA44u: goto label_8019AA44;
    case 0x8019AA48u: goto label_8019AA48;
    case 0x8019AA4Cu: goto label_8019AA4C;
    case 0x8019AA50u: goto label_8019AA50;
    case 0x8019AA54u: goto label_8019AA54;
    case 0x8019AA58u: goto label_8019AA58;
    case 0x8019AA5Cu: goto label_8019AA5C;
    case 0x8019AA60u: goto label_8019AA60;
    case 0x8019AA64u: goto label_8019AA64;
    case 0x8019AA68u: goto label_8019AA68;
    case 0x8019AA6Cu: goto label_8019AA6C;
    case 0x8019AA70u: goto label_8019AA70;
    case 0x8019AA74u: goto label_8019AA74;
    case 0x8019AA78u: goto label_8019AA78;
    case 0x8019AA7Cu: goto label_8019AA7C;
    case 0x8019AA80u: goto label_8019AA80;
    case 0x8019AA84u: goto label_8019AA84;
    case 0x8019AA88u: goto label_8019AA88;
    case 0x8019AA8Cu: goto label_8019AA8C;
    case 0x8019AA90u: goto label_8019AA90;
    case 0x8019AA94u: goto label_8019AA94;
    case 0x8019AA98u: goto label_8019AA98;
    case 0x8019AA9Cu: goto label_8019AA9C;
    case 0x8019AAA0u: goto label_8019AAA0;
    case 0x8019AAA4u: goto label_8019AAA4;
    case 0x8019AAA8u: goto label_8019AAA8;
    case 0x8019AAACu: goto label_8019AAAC;
    case 0x8019AAB0u: goto label_8019AAB0;
    case 0x8019AAB4u: goto label_8019AAB4;
    case 0x8019AAB8u: goto label_8019AAB8;
    case 0x8019AABCu: goto label_8019AABC;
    case 0x8019AAC0u: goto label_8019AAC0;
    case 0x8019AAC4u: goto label_8019AAC4;
    case 0x8019AAC8u: goto label_8019AAC8;
    case 0x8019AACCu: goto label_8019AACC;
    case 0x8019AAD0u: goto label_8019AAD0;
    case 0x8019AAD4u: goto label_8019AAD4;
    case 0x8019AAD8u: goto label_8019AAD8;
    case 0x8019AADCu: goto label_8019AADC;
    case 0x8019AAE0u: goto label_8019AAE0;
    case 0x8019AAE4u: goto label_8019AAE4;
    case 0x8019AAE8u: goto label_8019AAE8;
    case 0x8019AAECu: goto label_8019AAEC;
    case 0x8019AAF0u: goto label_8019AAF0;
    case 0x8019AAF4u: goto label_8019AAF4;
    case 0x8019AAF8u: goto label_8019AAF8;
    case 0x8019AAFCu: goto label_8019AAFC;
    case 0x8019AB00u: goto label_8019AB00;
    case 0x8019AB04u: goto label_8019AB04;
    case 0x8019AB08u: goto label_8019AB08;
    case 0x8019AB0Cu: goto label_8019AB0C;
    case 0x8019AB10u: goto label_8019AB10;
    case 0x8019AB14u: goto label_8019AB14;
    case 0x8019AB18u: goto label_8019AB18;
    case 0x8019AB1Cu: goto label_8019AB1C;
    case 0x8019AB20u: goto label_8019AB20;
    case 0x8019AB24u: goto label_8019AB24;
    case 0x8019AB28u: goto label_8019AB28;
    case 0x8019AB2Cu: goto label_8019AB2C;
    case 0x8019AB30u: goto label_8019AB30;
    case 0x8019AB34u: goto label_8019AB34;
    case 0x8019AB38u: goto label_8019AB38;
    case 0x8019AB3Cu: goto label_8019AB3C;
    case 0x8019AB40u: goto label_8019AB40;
    case 0x8019AB44u: goto label_8019AB44;
    case 0x8019AB48u: goto label_8019AB48;
    case 0x8019AB4Cu: goto label_8019AB4C;
    case 0x8019AB50u: goto label_8019AB50;
    case 0x8019AB54u: goto label_8019AB54;
    case 0x8019AB58u: goto label_8019AB58;
    case 0x8019AB5Cu: goto label_8019AB5C;
    case 0x8019AB60u: goto label_8019AB60;
    case 0x8019AB64u: goto label_8019AB64;
    case 0x8019AB68u: goto label_8019AB68;
    case 0x8019AB6Cu: goto label_8019AB6C;
    case 0x8019AB70u: goto label_8019AB70;
    case 0x8019AB74u: goto label_8019AB74;
    case 0x8019AB78u: goto label_8019AB78;
    case 0x8019AB7Cu: goto label_8019AB7C;
    case 0x8019AB80u: goto label_8019AB80;
    case 0x8019AB84u: goto label_8019AB84;
    case 0x8019AB88u: goto label_8019AB88;
    case 0x8019AB8Cu: goto label_8019AB8C;
    case 0x8019AB90u: goto label_8019AB90;
    case 0x8019AB94u: goto label_8019AB94;
    case 0x8019AB98u: goto label_8019AB98;
    case 0x8019AB9Cu: goto label_8019AB9C;
    case 0x8019ABA0u: goto label_8019ABA0;
    case 0x8019ABA4u: goto label_8019ABA4;
    case 0x8019ABA8u: goto label_8019ABA8;
    case 0x8019ABACu: goto label_8019ABAC;
    case 0x8019ABB0u: goto label_8019ABB0;
    case 0x8019ABB4u: goto label_8019ABB4;
    case 0x8019ABB8u: goto label_8019ABB8;
    case 0x8019ABBCu: goto label_8019ABBC;
    case 0x8019ABC0u: goto label_8019ABC0;
    case 0x8019ABC4u: goto label_8019ABC4;
    case 0x8019ABC8u: goto label_8019ABC8;
    case 0x8019ABCCu: goto label_8019ABCC;
    case 0x8019ABD0u: goto label_8019ABD0;
    case 0x8019ABD4u: goto label_8019ABD4;
    case 0x8019ABD8u: goto label_8019ABD8;
    case 0x8019ABDCu: goto label_8019ABDC;
    case 0x8019ABE0u: goto label_8019ABE0;
    case 0x8019ABE4u: goto label_8019ABE4;
    case 0x8019ABE8u: goto label_8019ABE8;
    case 0x8019ABECu: goto label_8019ABEC;
    case 0x8019ABF0u: goto label_8019ABF0;
    case 0x8019ABF4u: goto label_8019ABF4;
    case 0x8019ABF8u: goto label_8019ABF8;
    case 0x8019ABFCu: goto label_8019ABFC;
    case 0x8019AC00u: goto label_8019AC00;
    case 0x8019AC04u: goto label_8019AC04;
    case 0x8019AC08u: goto label_8019AC08;
    case 0x8019AC0Cu: goto label_8019AC0C;
    case 0x8019AC10u: goto label_8019AC10;
    case 0x8019AC14u: goto label_8019AC14;
    case 0x8019AC18u: goto label_8019AC18;
    case 0x8019AC1Cu: goto label_8019AC1C;
    case 0x8019AC20u: goto label_8019AC20;
    case 0x8019AC24u: goto label_8019AC24;
    case 0x8019AC28u: goto label_8019AC28;
    case 0x8019AC2Cu: goto label_8019AC2C;
    case 0x8019AC30u: goto label_8019AC30;
    case 0x8019AC34u: goto label_8019AC34;
    case 0x8019AC38u: goto label_8019AC38;
    case 0x8019AC3Cu: goto label_8019AC3C;
    case 0x8019AC40u: goto label_8019AC40;
    case 0x8019AC44u: goto label_8019AC44;
    case 0x8019AC48u: goto label_8019AC48;
    case 0x8019AC4Cu: goto label_8019AC4C;
    case 0x8019AC50u: goto label_8019AC50;
    case 0x8019AC54u: goto label_8019AC54;
    case 0x8019AC58u: goto label_8019AC58;
    case 0x8019AC5Cu: goto label_8019AC5C;
    case 0x8019AC60u: goto label_8019AC60;
    case 0x8019AC64u: goto label_8019AC64;
    case 0x8019AC68u: goto label_8019AC68;
    case 0x8019AC6Cu: goto label_8019AC6C;
    case 0x8019AC70u: goto label_8019AC70;
    case 0x8019AC74u: goto label_8019AC74;
    case 0x8019AC78u: goto label_8019AC78;
    case 0x8019AC7Cu: goto label_8019AC7C;
    case 0x8019AC80u: goto label_8019AC80;
    case 0x8019AC84u: goto label_8019AC84;
    case 0x8019AC88u: goto label_8019AC88;
    case 0x8019AC8Cu: goto label_8019AC8C;
    case 0x8019AC90u: goto label_8019AC90;
    case 0x8019AC94u: goto label_8019AC94;
    case 0x8019AC98u: goto label_8019AC98;
    case 0x8019AC9Cu: goto label_8019AC9C;
    case 0x8019ACA0u: goto label_8019ACA0;
    case 0x8019ACA4u: goto label_8019ACA4;
    case 0x8019ACA8u: goto label_8019ACA8;
    case 0x8019ACACu: goto label_8019ACAC;
    case 0x8019ACB0u: goto label_8019ACB0;
    case 0x8019ACB4u: goto label_8019ACB4;
    case 0x8019ACB8u: goto label_8019ACB8;
    case 0x8019ACBCu: goto label_8019ACBC;
    case 0x8019ACC0u: goto label_8019ACC0;
    case 0x8019ACC4u: goto label_8019ACC4;
    case 0x8019ACC8u: goto label_8019ACC8;
    case 0x8019ACCCu: goto label_8019ACCC;
    case 0x8019ACD0u: goto label_8019ACD0;
    case 0x8019ACD4u: goto label_8019ACD4;
    case 0x8019ACD8u: goto label_8019ACD8;
    case 0x8019ACDCu: goto label_8019ACDC;
    case 0x8019ACE0u: goto label_8019ACE0;
    case 0x8019ACE4u: goto label_8019ACE4;
    case 0x8019ACE8u: goto label_8019ACE8;
    case 0x8019ACECu: goto label_8019ACEC;
    case 0x8019ACF0u: goto label_8019ACF0;
    case 0x8019ACF4u: goto label_8019ACF4;
    case 0x8019ACF8u: goto label_8019ACF8;
    case 0x8019ACFCu: goto label_8019ACFC;
    case 0x8019AD00u: goto label_8019AD00;
    case 0x8019AD04u: goto label_8019AD04;
    case 0x8019AD08u: goto label_8019AD08;
    case 0x8019AD0Cu: goto label_8019AD0C;
    case 0x8019AD10u: goto label_8019AD10;
    case 0x8019AD14u: goto label_8019AD14;
    case 0x8019AD18u: goto label_8019AD18;
    case 0x8019AD1Cu: goto label_8019AD1C;
    case 0x8019AD20u: goto label_8019AD20;
    case 0x8019AD24u: goto label_8019AD24;
    case 0x8019AD28u: goto label_8019AD28;
    case 0x8019AD2Cu: goto label_8019AD2C;
    case 0x8019AD30u: goto label_8019AD30;
    case 0x8019AD34u: goto label_8019AD34;
    case 0x8019AD38u: goto label_8019AD38;
    case 0x8019AD3Cu: goto label_8019AD3C;
    case 0x8019AD40u: goto label_8019AD40;
    case 0x8019AD44u: goto label_8019AD44;
    case 0x8019AD48u: goto label_8019AD48;
    case 0x8019AD4Cu: goto label_8019AD4C;
    case 0x8019AD50u: goto label_8019AD50;
    case 0x8019AD54u: goto label_8019AD54;
    case 0x8019AD58u: goto label_8019AD58;
    case 0x8019AD5Cu: goto label_8019AD5C;
    case 0x8019AD60u: goto label_8019AD60;
    case 0x8019AD64u: goto label_8019AD64;
    case 0x8019AD68u: goto label_8019AD68;
    case 0x8019AD6Cu: goto label_8019AD6C;
    case 0x8019AD70u: goto label_8019AD70;
    case 0x8019AD74u: goto label_8019AD74;
    case 0x8019AD78u: goto label_8019AD78;
    case 0x8019AD7Cu: goto label_8019AD7C;
    case 0x8019AD80u: goto label_8019AD80;
    case 0x8019AD84u: goto label_8019AD84;
    case 0x8019AD88u: goto label_8019AD88;
    case 0x8019AD8Cu: goto label_8019AD8C;
    case 0x8019AD90u: goto label_8019AD90;
    case 0x8019AD94u: goto label_8019AD94;
    case 0x8019AD98u: goto label_8019AD98;
    case 0x8019AD9Cu: goto label_8019AD9C;
    case 0x8019ADA0u: goto label_8019ADA0;
    case 0x8019ADA4u: goto label_8019ADA4;
    case 0x8019ADA8u: goto label_8019ADA8;
    case 0x8019ADACu: goto label_8019ADAC;
    case 0x8019ADB0u: goto label_8019ADB0;
    case 0x8019ADB4u: goto label_8019ADB4;
    case 0x8019ADB8u: goto label_8019ADB8;
    case 0x8019ADBCu: goto label_8019ADBC;
    case 0x8019ADC0u: goto label_8019ADC0;
    case 0x8019ADC4u: goto label_8019ADC4;
    case 0x8019ADC8u: goto label_8019ADC8;
    case 0x8019ADCCu: goto label_8019ADCC;
    case 0x8019ADD0u: goto label_8019ADD0;
    case 0x8019ADD4u: goto label_8019ADD4;
    case 0x8019ADD8u: goto label_8019ADD8;
    case 0x8019ADDCu: goto label_8019ADDC;
    case 0x8019ADE0u: goto label_8019ADE0;
    case 0x8019ADE4u: goto label_8019ADE4;
    case 0x8019ADE8u: goto label_8019ADE8;
    case 0x8019ADECu: goto label_8019ADEC;
    case 0x8019ADF0u: goto label_8019ADF0;
    case 0x8019ADF4u: goto label_8019ADF4;
    case 0x8019ADF8u: goto label_8019ADF8;
    case 0x8019ADFCu: goto label_8019ADFC;
    case 0x8019AE00u: goto label_8019AE00;
    case 0x8019AE04u: goto label_8019AE04;
    case 0x8019AE08u: goto label_8019AE08;
    case 0x8019AE0Cu: goto label_8019AE0C;
    case 0x8019AE10u: goto label_8019AE10;
    case 0x8019AE14u: goto label_8019AE14;
    case 0x8019AE18u: goto label_8019AE18;
    case 0x8019AE1Cu: goto label_8019AE1C;
    case 0x8019AE20u: goto label_8019AE20;
    case 0x8019AE24u: goto label_8019AE24;
    case 0x8019AE28u: goto label_8019AE28;
    case 0x8019AE2Cu: goto label_8019AE2C;
    case 0x8019AE30u: goto label_8019AE30;
    case 0x8019AE34u: goto label_8019AE34;
    case 0x8019AE38u: goto label_8019AE38;
    case 0x8019AE3Cu: goto label_8019AE3C;
    case 0x8019AE40u: goto label_8019AE40;
    case 0x8019AE44u: goto label_8019AE44;
    case 0x8019AE48u: goto label_8019AE48;
    case 0x8019AE4Cu: goto label_8019AE4C;
    case 0x8019AE50u: goto label_8019AE50;
    case 0x8019AE54u: goto label_8019AE54;
    case 0x8019AE58u: goto label_8019AE58;
    case 0x8019AE5Cu: goto label_8019AE5C;
    case 0x8019AE60u: goto label_8019AE60;
    case 0x8019AE64u: goto label_8019AE64;
    case 0x8019AE68u: goto label_8019AE68;
    case 0x8019AE6Cu: goto label_8019AE6C;
    case 0x8019AE70u: goto label_8019AE70;
    case 0x8019AE74u: goto label_8019AE74;
    case 0x8019AE78u: goto label_8019AE78;
    case 0x8019AE7Cu: goto label_8019AE7C;
    case 0x8019AE80u: goto label_8019AE80;
    case 0x8019AE84u: goto label_8019AE84;
    case 0x8019AE88u: goto label_8019AE88;
    case 0x8019AE8Cu: goto label_8019AE8C;
    case 0x8019AE90u: goto label_8019AE90;
    case 0x8019AE94u: goto label_8019AE94;
    case 0x8019AE98u: goto label_8019AE98;
    case 0x8019AE9Cu: goto label_8019AE9C;
    case 0x8019AEA0u: goto label_8019AEA0;
    case 0x8019AEA4u: goto label_8019AEA4;
    case 0x8019AEA8u: goto label_8019AEA8;
    case 0x8019AEACu: goto label_8019AEAC;
    case 0x8019AEB0u: goto label_8019AEB0;
    case 0x8019AEB4u: goto label_8019AEB4;
    case 0x8019AEB8u: goto label_8019AEB8;
    case 0x8019AEBCu: goto label_8019AEBC;
    case 0x8019AEC0u: goto label_8019AEC0;
    case 0x8019AEC4u: goto label_8019AEC4;
    case 0x8019AEC8u: goto label_8019AEC8;
    case 0x8019AECCu: goto label_8019AECC;
    case 0x8019AED0u: goto label_8019AED0;
    case 0x8019AED4u: goto label_8019AED4;
    case 0x8019AED8u: goto label_8019AED8;
    case 0x8019AEDCu: goto label_8019AEDC;
    case 0x8019AEE0u: goto label_8019AEE0;
    case 0x8019AEE4u: goto label_8019AEE4;
    case 0x8019AEE8u: goto label_8019AEE8;
    case 0x8019AEECu: goto label_8019AEEC;
    case 0x8019AEF0u: goto label_8019AEF0;
    case 0x8019AEF4u: goto label_8019AEF4;
    case 0x8019AEF8u: goto label_8019AEF8;
    case 0x8019AEFCu: goto label_8019AEFC;
    case 0x8019AF00u: goto label_8019AF00;
    case 0x8019AF04u: goto label_8019AF04;
    case 0x8019AF08u: goto label_8019AF08;
    case 0x8019AF0Cu: goto label_8019AF0C;
    case 0x8019AF10u: goto label_8019AF10;
    case 0x8019AF14u: goto label_8019AF14;
    case 0x8019AF18u: goto label_8019AF18;
    case 0x8019AF1Cu: goto label_8019AF1C;
    case 0x8019AF20u: goto label_8019AF20;
    case 0x8019AF24u: goto label_8019AF24;
    case 0x8019AF28u: goto label_8019AF28;
    case 0x8019AF2Cu: goto label_8019AF2C;
    case 0x8019AF30u: goto label_8019AF30;
    case 0x8019AF34u: goto label_8019AF34;
    case 0x8019AF38u: goto label_8019AF38;
    case 0x8019AF3Cu: goto label_8019AF3C;
    case 0x8019AF40u: goto label_8019AF40;
    case 0x8019AF44u: goto label_8019AF44;
    case 0x8019AF48u: goto label_8019AF48;
    case 0x8019AF4Cu: goto label_8019AF4C;
    case 0x8019AF50u: goto label_8019AF50;
    case 0x8019AF54u: goto label_8019AF54;
    case 0x8019AF58u: goto label_8019AF58;
    case 0x8019AF5Cu: goto label_8019AF5C;
    case 0x8019AF60u: goto label_8019AF60;
    case 0x8019AF64u: goto label_8019AF64;
    case 0x8019AF68u: goto label_8019AF68;
    case 0x8019AF6Cu: goto label_8019AF6C;
    case 0x8019AF70u: goto label_8019AF70;
    case 0x8019AF74u: goto label_8019AF74;
    case 0x8019AF78u: goto label_8019AF78;
    case 0x8019AF7Cu: goto label_8019AF7C;
    case 0x8019AF80u: goto label_8019AF80;
    case 0x8019AF84u: goto label_8019AF84;
    case 0x8019AF88u: goto label_8019AF88;
    case 0x8019AF8Cu: goto label_8019AF8C;
    case 0x8019AF90u: goto label_8019AF90;
    case 0x8019AF94u: goto label_8019AF94;
    case 0x8019AF98u: goto label_8019AF98;
    case 0x8019AF9Cu: goto label_8019AF9C;
    case 0x8019AFA0u: goto label_8019AFA0;
    case 0x8019AFA4u: goto label_8019AFA4;
    case 0x8019AFA8u: goto label_8019AFA8;
    case 0x8019AFACu: goto label_8019AFAC;
    case 0x8019AFB0u: goto label_8019AFB0;
    case 0x8019AFB4u: goto label_8019AFB4;
    case 0x8019AFB8u: goto label_8019AFB8;
    case 0x8019AFBCu: goto label_8019AFBC;
    case 0x8019AFC0u: goto label_8019AFC0;
    case 0x8019AFC4u: goto label_8019AFC4;
    case 0x8019AFC8u: goto label_8019AFC8;
    case 0x8019AFCCu: goto label_8019AFCC;
    case 0x8019AFD0u: goto label_8019AFD0;
    case 0x8019AFD4u: goto label_8019AFD4;
    case 0x8019AFD8u: goto label_8019AFD8;
    case 0x8019AFDCu: goto label_8019AFDC;
    case 0x8019AFE0u: goto label_8019AFE0;
    case 0x8019AFE4u: goto label_8019AFE4;
    case 0x8019AFE8u: goto label_8019AFE8;
    case 0x8019AFECu: goto label_8019AFEC;
    case 0x8019AFF0u: goto label_8019AFF0;
    case 0x8019AFF4u: goto label_8019AFF4;
    case 0x8019AFF8u: goto label_8019AFF8;
    case 0x8019AFFCu: goto label_8019AFFC;
    case 0x8019B000u: goto label_8019B000;
    case 0x8019B004u: goto label_8019B004;
    case 0x8019B008u: goto label_8019B008;
    case 0x8019B00Cu: goto label_8019B00C;
    case 0x8019B010u: goto label_8019B010;
    case 0x8019B014u: goto label_8019B014;
    case 0x8019B018u: goto label_8019B018;
    case 0x8019B01Cu: goto label_8019B01C;
    case 0x8019B020u: goto label_8019B020;
    case 0x8019B024u: goto label_8019B024;
    case 0x8019B028u: goto label_8019B028;
    case 0x8019B02Cu: goto label_8019B02C;
    case 0x8019B030u: goto label_8019B030;
    case 0x8019B034u: goto label_8019B034;
    case 0x8019B038u: goto label_8019B038;
    case 0x8019B03Cu: goto label_8019B03C;
    case 0x8019B040u: goto label_8019B040;
    case 0x8019B044u: goto label_8019B044;
    case 0x8019B048u: goto label_8019B048;
    case 0x8019B04Cu: goto label_8019B04C;
    case 0x8019B050u: goto label_8019B050;
    case 0x8019B054u: goto label_8019B054;
    case 0x8019B058u: goto label_8019B058;
    case 0x8019B05Cu: goto label_8019B05C;
    case 0x8019B060u: goto label_8019B060;
    case 0x8019B064u: goto label_8019B064;
    case 0x8019B068u: goto label_8019B068;
    case 0x8019B06Cu: goto label_8019B06C;
    case 0x8019B070u: goto label_8019B070;
    case 0x8019B074u: goto label_8019B074;
    case 0x8019B078u: goto label_8019B078;
    case 0x8019B07Cu: goto label_8019B07C;
    case 0x8019B080u: goto label_8019B080;
    case 0x8019B084u: goto label_8019B084;
    case 0x8019B088u: goto label_8019B088;
    case 0x8019B08Cu: goto label_8019B08C;
    case 0x8019B090u: goto label_8019B090;
    case 0x8019B094u: goto label_8019B094;
    case 0x8019B098u: goto label_8019B098;
    case 0x8019B09Cu: goto label_8019B09C;
    case 0x8019B0A0u: goto label_8019B0A0;
    case 0x8019B0A4u: goto label_8019B0A4;
    case 0x8019B0A8u: goto label_8019B0A8;
    case 0x8019B0ACu: goto label_8019B0AC;
    case 0x8019B0B0u: goto label_8019B0B0;
    case 0x8019B0B4u: goto label_8019B0B4;
    case 0x8019B0B8u: goto label_8019B0B8;
    case 0x8019B0BCu: goto label_8019B0BC;
    case 0x8019B0C0u: goto label_8019B0C0;
    case 0x8019B0C4u: goto label_8019B0C4;
    case 0x8019B0C8u: goto label_8019B0C8;
    case 0x8019B0CCu: goto label_8019B0CC;
    case 0x8019B0D0u: goto label_8019B0D0;
    case 0x8019B0D4u: goto label_8019B0D4;
    case 0x8019B0D8u: goto label_8019B0D8;
    case 0x8019B0DCu: goto label_8019B0DC;
    case 0x8019B0E0u: goto label_8019B0E0;
    case 0x8019B0E4u: goto label_8019B0E4;
    case 0x8019B0E8u: goto label_8019B0E8;
    case 0x8019B0ECu: goto label_8019B0EC;
    case 0x8019B0F0u: goto label_8019B0F0;
    case 0x8019B0F4u: goto label_8019B0F4;
    case 0x8019B0F8u: goto label_8019B0F8;
    case 0x8019B0FCu: goto label_8019B0FC;
    case 0x8019B100u: goto label_8019B100;
    case 0x8019B104u: goto label_8019B104;
    case 0x8019B108u: goto label_8019B108;
    case 0x8019B10Cu: goto label_8019B10C;
    case 0x8019B110u: goto label_8019B110;
    case 0x8019B114u: goto label_8019B114;
    case 0x8019B118u: goto label_8019B118;
    case 0x8019B11Cu: goto label_8019B11C;
    case 0x8019B120u: goto label_8019B120;
    case 0x8019B124u: goto label_8019B124;
    case 0x8019B128u: goto label_8019B128;
    case 0x8019B12Cu: goto label_8019B12C;
    case 0x8019B130u: goto label_8019B130;
    case 0x8019B134u: goto label_8019B134;
    case 0x8019B138u: goto label_8019B138;
    case 0x8019B13Cu: goto label_8019B13C;
    case 0x8019B140u: goto label_8019B140;
    case 0x8019B144u: goto label_8019B144;
    case 0x8019B148u: goto label_8019B148;
    case 0x8019B14Cu: goto label_8019B14C;
    case 0x8019B150u: goto label_8019B150;
    case 0x8019B154u: goto label_8019B154;
    case 0x8019B158u: goto label_8019B158;
    case 0x8019B15Cu: goto label_8019B15C;
    case 0x8019B160u: goto label_8019B160;
    case 0x8019B164u: goto label_8019B164;
    case 0x8019B168u: goto label_8019B168;
    case 0x8019B16Cu: goto label_8019B16C;
    case 0x8019B170u: goto label_8019B170;
    case 0x8019B174u: goto label_8019B174;
    case 0x8019B178u: goto label_8019B178;
    case 0x8019B17Cu: goto label_8019B17C;
    case 0x8019B180u: goto label_8019B180;
    case 0x8019B184u: goto label_8019B184;
    case 0x8019B188u: goto label_8019B188;
    case 0x8019B18Cu: goto label_8019B18C;
    case 0x8019B190u: goto label_8019B190;
    case 0x8019B194u: goto label_8019B194;
    case 0x8019B198u: goto label_8019B198;
    case 0x8019B19Cu: goto label_8019B19C;
    case 0x8019B1A0u: goto label_8019B1A0;
    case 0x8019B1A4u: goto label_8019B1A4;
    case 0x8019B1A8u: goto label_8019B1A8;
    case 0x8019B1ACu: goto label_8019B1AC;
    case 0x8019B1B0u: goto label_8019B1B0;
    case 0x8019B1B4u: goto label_8019B1B4;
    case 0x8019B1B8u: goto label_8019B1B8;
    case 0x8019B1BCu: goto label_8019B1BC;
    case 0x8019B1C0u: goto label_8019B1C0;
    case 0x8019B1C4u: goto label_8019B1C4;
    case 0x8019B1C8u: goto label_8019B1C8;
    case 0x8019B1CCu: goto label_8019B1CC;
    case 0x8019B1D0u: goto label_8019B1D0;
    case 0x8019B1D4u: goto label_8019B1D4;
    case 0x8019B1D8u: goto label_8019B1D8;
    case 0x8019B1DCu: goto label_8019B1DC;
    case 0x8019B1E0u: goto label_8019B1E0;
    case 0x8019B1E4u: goto label_8019B1E4;
    case 0x8019B1E8u: goto label_8019B1E8;
    case 0x8019B1ECu: goto label_8019B1EC;
    case 0x8019B1F0u: goto label_8019B1F0;
    case 0x8019B1F4u: goto label_8019B1F4;
    case 0x8019B1F8u: goto label_8019B1F8;
    case 0x8019B1FCu: goto label_8019B1FC;
    case 0x8019B200u: goto label_8019B200;
    case 0x8019B204u: goto label_8019B204;
    case 0x8019B208u: goto label_8019B208;
    case 0x8019B20Cu: goto label_8019B20C;
    case 0x8019B210u: goto label_8019B210;
    case 0x8019B214u: goto label_8019B214;
    case 0x8019B218u: goto label_8019B218;
    case 0x8019B21Cu: goto label_8019B21C;
    case 0x8019B220u: goto label_8019B220;
    case 0x8019B224u: goto label_8019B224;
    case 0x8019B228u: goto label_8019B228;
    case 0x8019B22Cu: goto label_8019B22C;
    case 0x8019B230u: goto label_8019B230;
    case 0x8019B234u: goto label_8019B234;
    case 0x8019B238u: goto label_8019B238;
    case 0x8019B23Cu: goto label_8019B23C;
    case 0x8019B240u: goto label_8019B240;
    case 0x8019B244u: goto label_8019B244;
    case 0x8019B248u: goto label_8019B248;
    case 0x8019B24Cu: goto label_8019B24C;
    case 0x8019B250u: goto label_8019B250;
    case 0x8019B254u: goto label_8019B254;
    case 0x8019B258u: goto label_8019B258;
    case 0x8019B25Cu: goto label_8019B25C;
    case 0x8019B260u: goto label_8019B260;
    case 0x8019B264u: goto label_8019B264;
    case 0x8019B268u: goto label_8019B268;
    case 0x8019B26Cu: goto label_8019B26C;
    case 0x8019B270u: goto label_8019B270;
    case 0x8019B274u: goto label_8019B274;
    case 0x8019B278u: goto label_8019B278;
    case 0x8019B27Cu: goto label_8019B27C;
    case 0x8019B280u: goto label_8019B280;
    case 0x8019B284u: goto label_8019B284;
    case 0x8019B288u: goto label_8019B288;
    case 0x8019B28Cu: goto label_8019B28C;
    case 0x8019B290u: goto label_8019B290;
    case 0x8019B294u: goto label_8019B294;
    case 0x8019B298u: goto label_8019B298;
    case 0x8019B29Cu: goto label_8019B29C;
    case 0x8019B2A0u: goto label_8019B2A0;
    case 0x8019B2A4u: goto label_8019B2A4;
    case 0x8019B2A8u: goto label_8019B2A8;
    case 0x8019B2ACu: goto label_8019B2AC;
    case 0x8019B2B0u: goto label_8019B2B0;
    case 0x8019B2B4u: goto label_8019B2B4;
    case 0x8019B2B8u: goto label_8019B2B8;
    case 0x8019B2BCu: goto label_8019B2BC;
    default: return;
    }
label_801972C0:
    ctx->pc = 0x801972C0u;
    ctx->downcount -= 13;
    // 801972C0: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_801972C4:
    ctx->pc = 0x801972C4u;
    // 801972C4: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801972C8:
    ctx->pc = 0x801972C8u;
    // 801972C8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801972CC:
    ctx->pc = 0x801972CCu;
    // 801972CC: addi    r4, r3, 16
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(16);

label_801972D0:
    ctx->pc = 0x801972D0u;
    // 801972D0: lwz     r3, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801972D4:
    ctx->pc = 0x801972D4u;
    // 801972D4: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_801972D8:
    ctx->pc = 0x801972D8u;
    // 801972D8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801972DC:
    ctx->pc = 0x801972DCu;
    // 801972DC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801972E0:
    ctx->pc = 0x801972E0u;
    // 801972E0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801972E4:
    ctx->pc = 0x801972E4u;
    // 801972E4: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801972E8:
    ctx->pc = 0x801972E8u;
    // 801972E8: lwz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801972EC:
    ctx->pc = 0x801972ECu;
    // 801972EC: sth     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801972F0:
    ctx->pc = 0x801972F0u;
    // 801972F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801972F4:
    ctx->pc = 0x801972F4u;
    ctx->downcount -= 12;
    // 801972F4: lwz     r4, -26124(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26124);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801972F8:
    ctx->pc = 0x801972F8u;
    // 801972F8: lwz     r3, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801972FC:
    ctx->pc = 0x801972FCu;
    // 801972FC: addi    r0, r3, 512
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(512);

label_80197300:
    ctx->pc = 0x80197300u;
    // 80197300: stw     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197304:
    ctx->pc = 0x80197304u;
    // 80197304: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197308:
    ctx->pc = 0x80197308u;
    // 80197308: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019730C:
    ctx->pc = 0x8019730Cu;
    // 8019730C: sth     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80197310:
    ctx->pc = 0x80197310u;
    // 80197310: lwz     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197314:
    ctx->pc = 0x80197314u;
    // 80197314: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197318:
    ctx->pc = 0x80197318u;
    // 80197318: rlwinm r0, r0, 16, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00003FFFu;
    }

label_8019731C:
    ctx->pc = 0x8019731Cu;
    // 8019731C: sth     r0, 42(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(42);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80197320:
    ctx->pc = 0x80197320u;
    // 80197320: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80197324:
    ctx->pc = 0x80197324u;
    ctx->downcount -= 7;
    // 80197324: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80197328:
    ctx->pc = 0x80197328u;
    // 80197328: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019732C:
    ctx->pc = 0x8019732Cu;
    // 8019732C: stwu     r1, -168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-168);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80197330:
    ctx->pc = 0x80197330u;
    // 80197330: stw     r31, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80197334:
    ctx->pc = 0x80197334u;
    // 80197334: stw     r30, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80197338:
    ctx->pc = 0x80197338u;
    // 80197338: stw     r29, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8019733C:
    ctx->pc = 0x8019733Cu;
    // 8019733C: bl      0x8019747C
    {
            ctx->lr = 0x80197340u;
            goto label_8019747C;
    }

label_80197340:
    ctx->pc = 0x80197340u;
    ctx->downcount -= 2;
    // 80197340: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80197344:
    ctx->pc = 0x80197344u;
    // 80197344: bl      0x80197474
    {
            ctx->lr = 0x80197348u;
            goto label_80197474;
    }

label_80197348:
    ctx->pc = 0x80197348u;
    ctx->downcount -= 7;
    // 80197348: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_8019734C:
    ctx->pc = 0x8019734Cu;
    // 8019734C: lwz     r29, 0(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(0);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80197350:
    ctx->pc = 0x80197350u;
    // 80197350: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80197354:
    ctx->pc = 0x80197354u;
    // 80197354: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80197358:
    ctx->pc = 0x80197358u;
    // 80197358: addi    r5, r1, 12
    ctx->gpr[5] = ctx->gpr[1] + (u32)(s32)(12);

label_8019735C:
    ctx->pc = 0x8019735Cu;
    // 8019735C: addi    r4, r31, -8
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(-8);

label_80197360:
    loop_80197360(ctx);
    if (ctx->pc == 0x80197374u) goto label_80197374;
    return;
label_80197364:
    ctx->pc = 0x80197364u;
    // 80197364: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197368:
    ctx->pc = 0x80197368u;
    // 80197368: stwu     r3, 8(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
        ctx->gpr[5] = ea;
    }

label_8019736C:
    ctx->pc = 0x8019736Cu;
    // 8019736C: stw     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197370:
    // 80197370: bc    16, 0, 0x80197360
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197360u;
                return;
            }
            goto label_80197360;
        }
    }

label_80197374:
    ctx->pc = 0x80197374u;
    ctx->downcount -= 1;
    // 80197374: bl      0x80173F2C
    {
            ctx->lr = 0x80197378u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80197378:
    ctx->pc = 0x80197378u;
    ctx->downcount -= 7;
    // 80197378: stw     r29, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8019737C:
    ctx->pc = 0x8019737Cu;
    // 8019737C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197380:
    ctx->pc = 0x80197380u;
    // 80197380: stw     r29, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80197384:
    ctx->pc = 0x80197384u;
    // 80197384: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197388:
    ctx->pc = 0x80197388u;
    // 80197388: lwz     r4, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019738C:
    ctx->pc = 0x8019738Cu;
    // 8019738C: cmpwi   r4, 0
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

label_80197390:
    ctx->pc = 0x80197390u;
    // 80197390: bc    4, 0, 0x801973A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801973A0;
        }
    }

label_80197394:
    ctx->pc = 0x80197394u;
    ctx->downcount -= 3;
    // 80197394: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197398:
    ctx->pc = 0x80197398u;
    // 80197398: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8019739C:
    ctx->pc = 0x8019739Cu;
    // 8019739C: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801973A0:
    ctx->pc = 0x801973A0u;
    ctx->downcount -= 1;
    // 801973A0: bl      0x80173F54
    {
            ctx->lr = 0x801973A4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801973A4:
    ctx->pc = 0x801973A4u;
    ctx->downcount -= 2;
    // 801973A4: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_801973A8:
    ctx->pc = 0x801973A8u;
    // 801973A8: bl      0x80196B6C
    {
            ctx->lr = 0x801973ACu;
            ctx->pc = 0x80196B6Cu;
            return;
    }

label_801973AC:
    ctx->pc = 0x801973ACu;
    ctx->downcount -= 2;
    // 801973AC: cmplw   r30, r31
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801973B0:
    ctx->pc = 0x801973B0u;
    // 801973B0: bc    4, 2, 0x801973BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801973BC;
        }
    }

label_801973B4:
    ctx->pc = 0x801973B4u;
    ctx->downcount -= 2;
    // 801973B4: addi    r3, r1, 20
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(20);

label_801973B8:
    ctx->pc = 0x801973B8u;
    // 801973B8: bl      0x80196A5C
    {
            ctx->lr = 0x801973BCu;
            ctx->pc = 0x80196A5Cu;
            return;
    }

label_801973BC:
    ctx->pc = 0x801973BCu;
    ctx->downcount -= 1;
    // 801973BC: bl      0x80173F2C
    {
            ctx->lr = 0x801973C0u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801973C0:
    ctx->pc = 0x801973C0u;
    ctx->downcount -= 7;
    // 801973C0: stw     r29, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801973C4:
    ctx->pc = 0x801973C4u;
    // 801973C4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801973C8:
    ctx->pc = 0x801973C8u;
    // 801973C8: stw     r29, 24(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801973CC:
    ctx->pc = 0x801973CCu;
    // 801973CC: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801973D0:
    ctx->pc = 0x801973D0u;
    // 801973D0: lwz     r4, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801973D4:
    ctx->pc = 0x801973D4u;
    // 801973D4: cmpwi   r4, 0
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

label_801973D8:
    ctx->pc = 0x801973D8u;
    // 801973D8: bc    4, 0, 0x801973E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_801973E8;
        }
    }

label_801973DC:
    ctx->pc = 0x801973DCu;
    ctx->downcount -= 3;
    // 801973DC: lwz     r0, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801973E0:
    ctx->pc = 0x801973E0u;
    // 801973E0: add   r0, r4, r0
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801973E4:
    ctx->pc = 0x801973E4u;
    // 801973E4: stw     r0, 28(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801973E8:
    ctx->pc = 0x801973E8u;
    ctx->downcount -= 1;
    // 801973E8: bl      0x80173F54
    {
            ctx->lr = 0x801973ECu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801973EC:
    ctx->pc = 0x801973ECu;
    ctx->downcount -= 2;
    // 801973EC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801973F0:
    ctx->pc = 0x801973F0u;
    // 801973F0: bl      0x80196B6C
    {
            ctx->lr = 0x801973F4u;
            ctx->pc = 0x80196B6Cu;
            return;
    }

label_801973F4:
    ctx->pc = 0x801973F4u;
    ctx->downcount -= 2;
    // 801973F4: cmplw   r30, r31
    {
        u32 val_a = (u32)(ctx->gpr[30]);
        u32 val_b = (u32)(ctx->gpr[31]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801973F8:
    ctx->pc = 0x801973F8u;
    // 801973F8: bc    4, 2, 0x80197404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80197404;
        }
    }

label_801973FC:
    ctx->pc = 0x801973FCu;
    ctx->downcount -= 2;
    // 801973FC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80197400:
    ctx->pc = 0x80197400u;
    // 80197400: bl      0x80196A5C
    {
            ctx->lr = 0x80197404u;
            ctx->pc = 0x80196A5Cu;
            return;
    }

label_80197404:
    ctx->pc = 0x80197404u;
    ctx->downcount -= 8;
    // 80197404: lwz     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197408:
    ctx->pc = 0x80197408u;
    // 80197408: lwz     r31, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019740C:
    ctx->pc = 0x8019740Cu;
    // 8019740C: lwz     r30, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80197410:
    ctx->pc = 0x80197410u;
    // 80197410: lwz     r29, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80197414:
    ctx->pc = 0x80197414u;
    // 80197414: addi    r1, r1, 168
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(168);

label_80197418:
    ctx->pc = 0x80197418u;
    // 80197418: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019741C:
    ctx->pc = 0x8019741Cu;
    // 8019741C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80197420:
    ctx->pc = 0x80197420u;
    ctx->downcount -= 6;
    // 80197420: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80197424:
    ctx->pc = 0x80197424u;
    // 80197424: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197428:
    ctx->pc = 0x80197428u;
    // 80197428: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019742C:
    ctx->pc = 0x8019742Cu;
    // 8019742C: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80197430:
    ctx->pc = 0x80197430u;
    // 80197430: stw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80197434:
    ctx->pc = 0x80197434u;
    // 80197434: bl      0x80173F2C
    {
            ctx->lr = 0x80197438u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80197438:
    ctx->pc = 0x80197438u;
    ctx->downcount -= 3;
    // 80197438: lwz     r30, -26120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26120);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8019743C:
    ctx->pc = 0x8019743Cu;
    // 8019743C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80197440:
    ctx->pc = 0x80197440u;
    // 80197440: bl      0x8017837C
    {
            ctx->lr = 0x80197444u;
            ctx->pc = 0x8017837Cu;
            return;
    }

label_80197444:
    ctx->pc = 0x80197444u;
    ctx->downcount -= 3;
    // 80197444: stw     r3, -26120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26120);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80197448:
    ctx->pc = 0x80197448u;
    // 80197448: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8019744C:
    ctx->pc = 0x8019744Cu;
    // 8019744C: bl      0x80173F54
    {
            ctx->lr = 0x80197450u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80197450:
    ctx->pc = 0x80197450u;
    ctx->downcount -= 8;
    // 80197450: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80197454:
    ctx->pc = 0x80197454u;
    // 80197454: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197458:
    ctx->pc = 0x80197458u;
    // 80197458: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019745C:
    ctx->pc = 0x8019745Cu;
    // 8019745C: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80197460:
    ctx->pc = 0x80197460u;
    // 80197460: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80197464:
    ctx->pc = 0x80197464u;
    // 80197464: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80197468:
    ctx->pc = 0x80197468u;
    // 80197468: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019746C:
    ctx->pc = 0x8019746Cu;
    ctx->downcount -= 2;
    // 8019746C: lwz     r3, -26120(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26120);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197470:
    ctx->pc = 0x80197470u;
    // 80197470: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80197474:
    ctx->pc = 0x80197474u;
    ctx->downcount -= 2;
    // 80197474: lwz     r3, -26128(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26128);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197478:
    ctx->pc = 0x80197478u;
    // 80197478: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019747C:
    ctx->pc = 0x8019747Cu;
    ctx->downcount -= 2;
    // 8019747C: lwz     r3, -26124(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197480:
    ctx->pc = 0x80197480u;
    // 80197480: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80197484:
    ctx->pc = 0x80197484u;
    ctx->downcount -= 2;
    // 80197484: lwz     r3, -26104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26104);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197488:
    ctx->pc = 0x80197488u;
    // 80197488: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019748C:
    ctx->pc = 0x8019748Cu;
    ctx->downcount -= 4;
    // 8019748C: lwz     r3, -26104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26104);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197490:
    ctx->pc = 0x80197490u;
    // 80197490: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197494:
    ctx->pc = 0x80197494u;
    // 80197494: stw     r0, -26104(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26104);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197498:
    ctx->pc = 0x80197498u;
    // 80197498: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019749C:
    ctx->pc = 0x8019749Cu;
    ctx->downcount -= 7;
    // 8019749C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801974A0:
    ctx->pc = 0x801974A0u;
    // 801974A0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801974A4:
    ctx->pc = 0x801974A4u;
    // 801974A4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801974A8:
    ctx->pc = 0x801974A8u;
    // 801974A8: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801974AC:
    ctx->pc = 0x801974ACu;
    // 801974AC: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801974B0:
    ctx->pc = 0x801974B0u;
    // 801974B0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801974B4:
    ctx->pc = 0x801974B4u;
    // 801974B4: bl      0x80173F2C
    {
            ctx->lr = 0x801974B8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801974B8:
    ctx->pc = 0x801974B8u;
    ctx->downcount -= 2;
    // 801974B8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801974BC:
    ctx->pc = 0x801974BCu;
    // 801974BC: bl      0x801991C4
    {
            ctx->lr = 0x801974C0u;
            goto label_801991C4;
    }

label_801974C0:
    ctx->downcount -= 1;
    // 801974C0: bl      0x8016F340
    {
            ctx->lr = 0x801974C4u;
            ctx->pc = 0x8016F340u;
            return;
    }

label_801974C4:
    ctx->downcount -= 2;
    // 801974C4: rlwinm. r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801974C8:
    // 801974C8: bc    4, 2, 0x801974C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801974C0u;
                return;
            }
            goto label_801974C0;
        }
    }

label_801974CC:
    ctx->pc = 0x801974CCu;
    ctx->downcount -= 3;
    // 801974CC: lis     r3, 3073
    ctx->gpr[3] = ((u32)(s32)(3073) << 16);

label_801974D0:
    ctx->pc = 0x801974D0u;
    // 801974D0: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_801974D4:
    ctx->pc = 0x801974D4u;
    // 801974D4: bl      0x8016F34C
    {
            ctx->lr = 0x801974D8u;
            ctx->pc = 0x8016F34Cu;
            return;
    }

label_801974D8:
    ctx->pc = 0x801974D8u;
    ctx->downcount -= 3;
    // 801974D8: lbz     r0, -26116(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26116);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801974DC:
    ctx->pc = 0x801974DCu;
    // 801974DC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801974E0:
    ctx->pc = 0x801974E0u;
    // 801974E0: bc    12, 2, 0x80197534
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197534;
        }
    }

label_801974E4:
    ctx->pc = 0x801974E4u;
    ctx->downcount -= 20;
    // 801974E4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801974E8:
    ctx->pc = 0x801974E8u;
    // 801974E8: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_801974EC:
    ctx->pc = 0x801974ECu;
    // 801974EC: rlwinm r0, r0, 0, 28, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFEFu;
    }

label_801974F0:
    ctx->pc = 0x801974F0u;
    // 801974F0: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801974F4:
    ctx->pc = 0x801974F4u;
    // 801974F4: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801974F8:
    ctx->pc = 0x801974F8u;
    // 801974F8: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801974FC:
    ctx->pc = 0x801974FCu;
    // 801974FC: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197500:
    ctx->pc = 0x80197500u;
    // 80197500: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80197504:
    ctx->pc = 0x80197504u;
    // 80197504: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197508:
    ctx->pc = 0x80197508u;
    // 80197508: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019750C:
    ctx->pc = 0x8019750Cu;
    // 8019750C: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_80197510:
    ctx->pc = 0x80197510u;
    // 80197510: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197514:
    ctx->pc = 0x80197514u;
    // 80197514: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197518:
    ctx->pc = 0x80197518u;
    // 80197518: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019751C:
    ctx->pc = 0x8019751Cu;
    // 8019751C: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_80197520:
    ctx->pc = 0x80197520u;
    // 80197520: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197524:
    ctx->pc = 0x80197524u;
    // 80197524: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80197528:
    ctx->pc = 0x80197528u;
    // 80197528: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019752C:
    ctx->pc = 0x8019752Cu;
    // 8019752C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197530:
    ctx->pc = 0x80197530u;
    // 80197530: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80197534:
    ctx->pc = 0x80197534u;
    ctx->downcount -= 21;
    // 80197534: lwz     r4, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80197538:
    ctx->pc = 0x80197538u;
    // 80197538: rlwinm r5, r30, 0, 2, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x3FFFFFE0u;
    }

label_8019753C:
    ctx->pc = 0x8019753Cu;
    // 8019753C: lwz     r3, -26128(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26128);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197540:
    ctx->pc = 0x80197540u;
    // 80197540: rlwinm r5, r5, 0, 6, 4
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFBFFFFFFu;
    }

label_80197544:
    ctx->pc = 0x80197544u;
    // 80197544: lwz     r0, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197548:
    ctx->pc = 0x80197548u;
    // 80197548: rlwinm r4, r0, 0, 6, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_8019754C:
    ctx->pc = 0x8019754Cu;
    // 8019754C: addis   r0, r4, -32768
    ctx->gpr[0] = ctx->gpr[4] + ((u32)(s32)(-32768) << 16);

label_80197550:
    ctx->pc = 0x80197550u;
    // 80197550: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197554:
    ctx->pc = 0x80197554u;
    // 80197554: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80197558:
    ctx->pc = 0x80197558u;
    // 80197558: lis     r0, 1024
    ctx->gpr[0] = ((u32)(s32)(1024) << 16);

label_8019755C:
    ctx->pc = 0x8019755Cu;
    // 8019755C: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197560:
    ctx->pc = 0x80197560u;
    // 80197560: stw     r4, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80197564:
    ctx->pc = 0x80197564u;
    // 80197564: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197568:
    ctx->pc = 0x80197568u;
    // 80197568: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019756C:
    ctx->pc = 0x8019756Cu;
    // 8019756C: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197570:
    ctx->pc = 0x80197570u;
    // 80197570: stw     r5, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80197574:
    ctx->pc = 0x80197574u;
    // 80197574: sync
    ppc_memory_fence();

label_80197578:
    ctx->pc = 0x80197578u;
    // 80197578: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8019757C:
    ctx->pc = 0x8019757Cu;
    // 8019757C: bl      0x80173F54
    {
            ctx->lr = 0x80197580u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80197580:
    ctx->pc = 0x80197580u;
    ctx->downcount -= 9;
    // 80197580: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80197584:
    ctx->pc = 0x80197584u;
    // 80197584: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197588:
    ctx->pc = 0x80197588u;
    // 80197588: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019758C:
    ctx->pc = 0x8019758Cu;
    // 8019758C: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_80197590:
    ctx->pc = 0x80197590u;
    // 80197590: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80197594:
    ctx->pc = 0x80197594u;
    // 80197594: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80197598:
    ctx->pc = 0x80197598u;
    // 80197598: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019759C:
    ctx->pc = 0x8019759Cu;
    // 8019759C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801975A0:
    ctx->pc = 0x801975A0u;
    ctx->downcount -= 5;
    // 801975A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801975A4:
    ctx->pc = 0x801975A4u;
    // 801975A4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801975A8:
    ctx->pc = 0x801975A8u;
    // 801975A8: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801975AC:
    ctx->pc = 0x801975ACu;
    // 801975AC: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801975B0:
    ctx->pc = 0x801975B0u;
    // 801975B0: bl      0x80173F2C
    {
            ctx->lr = 0x801975B4u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801975B4:
    ctx->pc = 0x801975B4u;
    ctx->downcount -= 33;
    // 801975B4: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_801975B8:
    ctx->pc = 0x801975B8u;
    // 801975B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801975BC:
    ctx->pc = 0x801975BCu;
    // 801975BC: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975C0:
    ctx->pc = 0x801975C0u;
    // 801975C0: li      r6, 24
    ctx->gpr[6] = (u32)(s32)(24);

label_801975C4:
    ctx->pc = 0x801975C4u;
    // 801975C4: subfic  r0, r6, 31
    {
        u64 res = (u64)(u32)(s32)(31) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801975C8:
    ctx->pc = 0x801975C8u;
    // 801975C8: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975CC:
    ctx->pc = 0x801975CCu;
    // 801975CC: cmplwi  r6, 0x001F
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x001Fu);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801975D0:
    ctx->pc = 0x801975D0u;
    // 801975D0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_801975D4:
    ctx->pc = 0x801975D4u;
    // 801975D4: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801975D8:
    ctx->pc = 0x801975D8u;
    // 801975D8: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975DC:
    ctx->pc = 0x801975DCu;
    // 801975DC: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975E0:
    ctx->pc = 0x801975E0u;
    // 801975E0: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975E4:
    ctx->pc = 0x801975E4u;
    // 801975E4: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975E8:
    ctx->pc = 0x801975E8u;
    // 801975E8: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975EC:
    ctx->pc = 0x801975ECu;
    // 801975EC: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975F0:
    ctx->pc = 0x801975F0u;
    // 801975F0: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975F4:
    ctx->pc = 0x801975F4u;
    // 801975F4: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975F8:
    ctx->pc = 0x801975F8u;
    // 801975F8: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_801975FC:
    ctx->pc = 0x801975FCu;
    // 801975FC: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197600:
    ctx->pc = 0x80197600u;
    // 80197600: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197604:
    ctx->pc = 0x80197604u;
    // 80197604: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197608:
    ctx->pc = 0x80197608u;
    // 80197608: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019760C:
    ctx->pc = 0x8019760Cu;
    // 8019760C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197610:
    ctx->pc = 0x80197610u;
    // 80197610: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197614:
    ctx->pc = 0x80197614u;
    // 80197614: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197618:
    ctx->pc = 0x80197618u;
    // 80197618: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019761C:
    ctx->pc = 0x8019761Cu;
    // 8019761C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197620:
    ctx->pc = 0x80197620u;
    // 80197620: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197624:
    ctx->pc = 0x80197624u;
    // 80197624: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197628:
    ctx->pc = 0x80197628u;
    // 80197628: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019762C:
    ctx->pc = 0x8019762Cu;
    // 8019762C: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80197630:
    ctx->pc = 0x80197630u;
    // 80197630: bc    4, 0, 0x8019763C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019763C;
        }
    }

label_80197634:
    loop_80197634(ctx);
    if (ctx->pc == 0x8019763Cu) goto label_8019763C;
    return;
label_80197638:
    // 80197638: bc    16, 0, 0x80197634
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197634u;
                return;
            }
            goto label_80197634;
        }
    }

label_8019763C:
    ctx->pc = 0x8019763Cu;
    ctx->downcount -= 1;
    // 8019763C: bl      0x8016F238
    {
            ctx->lr = 0x80197640u;
            ctx->pc = 0x8016F238u;
            return;
    }

label_80197640:
    ctx->downcount -= 1;
    // 80197640: bl      0x8016F340
    {
            ctx->lr = 0x80197644u;
            ctx->pc = 0x8016F340u;
            return;
    }

label_80197644:
    ctx->downcount -= 2;
    // 80197644: rlwinm. r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80197648:
    // 80197648: bc    4, 2, 0x80197640
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197640u;
                return;
            }
            goto label_80197640;
        }
    }

label_8019764C:
    ctx->pc = 0x8019764Cu;
    ctx->downcount -= 3;
    // 8019764C: lis     r3, 3073
    ctx->gpr[3] = ((u32)(s32)(3073) << 16);

label_80197650:
    ctx->pc = 0x80197650u;
    // 80197650: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_80197654:
    ctx->pc = 0x80197654u;
    // 80197654: bl      0x8016F34C
    {
            ctx->lr = 0x80197658u;
            ctx->pc = 0x8016F34Cu;
            return;
    }

label_80197658:
    ctx->pc = 0x80197658u;
    ctx->downcount -= 19;
    // 80197658: lwz     r4, -26128(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019765C:
    ctx->pc = 0x8019765Cu;
    // 8019765C: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197660:
    ctx->pc = 0x80197660u;
    // 80197660: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197664:
    ctx->pc = 0x80197664u;
    // 80197664: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_80197668:
    ctx->pc = 0x80197668u;
    // 80197668: stw     r0, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019766C:
    ctx->pc = 0x8019766Cu;
    // 8019766C: lwz     r4, -26128(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80197670:
    ctx->pc = 0x80197670u;
    // 80197670: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197674:
    ctx->pc = 0x80197674u;
    // 80197674: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197678:
    ctx->pc = 0x80197678u;
    // 80197678: rlwinm r0, r0, 0, 2, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFFFu;
    }

label_8019767C:
    ctx->pc = 0x8019767Cu;
    // 8019767C: stw     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197680:
    ctx->pc = 0x80197680u;
    // 80197680: lwz     r4, -26128(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80197684:
    ctx->pc = 0x80197684u;
    // 80197684: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197688:
    ctx->pc = 0x80197688u;
    // 80197688: lwz     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019768C:
    ctx->pc = 0x8019768Cu;
    // 8019768C: rlwinm r0, r0, 0, 2, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x3FFFFFE0u;
    }

label_80197690:
    ctx->pc = 0x80197690u;
    // 80197690: rlwinm r0, r0, 0, 6, 4
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFBFFFFFFu;
    }

label_80197694:
    ctx->pc = 0x80197694u;
    // 80197694: stw     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197698:
    ctx->pc = 0x80197698u;
    // 80197698: lbz     r0, -26116(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26116);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019769C:
    ctx->pc = 0x8019769Cu;
    // 8019769C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801976A0:
    ctx->pc = 0x801976A0u;
    // 801976A0: bc    12, 2, 0x80197734
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197734;
        }
    }

label_801976A4:
    ctx->pc = 0x801976A4u;
    ctx->downcount -= 36;
    // 801976A4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801976A8:
    ctx->pc = 0x801976A8u;
    // 801976A8: lwzu     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_801976AC:
    ctx->pc = 0x801976ACu;
    // 801976AC: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_801976B0:
    ctx->pc = 0x801976B0u;
    // 801976B0: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_801976B4:
    ctx->pc = 0x801976B4u;
    // 801976B4: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801976B8:
    ctx->pc = 0x801976B8u;
    // 801976B8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801976BC:
    ctx->pc = 0x801976BCu;
    // 801976BC: lwzu     r0, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_801976C0:
    ctx->pc = 0x801976C0u;
    // 801976C0: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_801976C4:
    ctx->pc = 0x801976C4u;
    // 801976C4: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_801976C8:
    ctx->pc = 0x801976C8u;
    // 801976C8: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801976CC:
    ctx->pc = 0x801976CCu;
    // 801976CC: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801976D0:
    ctx->pc = 0x801976D0u;
    // 801976D0: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801976D4:
    ctx->pc = 0x801976D4u;
    // 801976D4: lwz     r0, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801976D8:
    ctx->pc = 0x801976D8u;
    // 801976D8: sth     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801976DC:
    ctx->pc = 0x801976DCu;
    // 801976DC: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801976E0:
    ctx->pc = 0x801976E0u;
    // 801976E0: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_801976E4:
    ctx->pc = 0x801976E4u;
    // 801976E4: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_801976E8:
    ctx->pc = 0x801976E8u;
    // 801976E8: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_801976EC:
    ctx->pc = 0x801976ECu;
    // 801976EC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801976F0:
    ctx->pc = 0x801976F0u;
    // 801976F0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801976F4:
    ctx->pc = 0x801976F4u;
    // 801976F4: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_801976F8:
    ctx->pc = 0x801976F8u;
    // 801976F8: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_801976FC:
    ctx->pc = 0x801976FCu;
    // 801976FC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197700:
    ctx->pc = 0x80197700u;
    // 80197700: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80197704:
    ctx->pc = 0x80197704u;
    // 80197704: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197708:
    ctx->pc = 0x80197708u;
    // 80197708: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019770C:
    ctx->pc = 0x8019770Cu;
    // 8019770C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80197710:
    ctx->pc = 0x80197710u;
    // 80197710: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197714:
    ctx->pc = 0x80197714u;
    // 80197714: lwzu     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80197718:
    ctx->pc = 0x80197718u;
    // 80197718: rlwinm r0, r0, 0, 28, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFEFu;
    }

label_8019771C:
    ctx->pc = 0x8019771Cu;
    // 8019771C: ori     r0, r0, 0x0010
    ctx->gpr[0] = ctx->gpr[0] | 0x0010u;

label_80197720:
    ctx->pc = 0x80197720u;
    // 80197720: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197724:
    ctx->pc = 0x80197724u;
    // 80197724: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80197728:
    ctx->pc = 0x80197728u;
    // 80197728: lwz     r3, -26140(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26140);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019772C:
    ctx->pc = 0x8019772Cu;
    // 8019772C: lwz     r0, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197730:
    ctx->pc = 0x80197730u;
    // 80197730: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80197734:
    ctx->pc = 0x80197734u;
    ctx->downcount -= 5;
    // 80197734: sync
    ppc_memory_fence();

label_80197738:
    ctx->pc = 0x80197738u;
    // 80197738: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8019773C:
    ctx->pc = 0x8019773Cu;
    // 8019773C: bl      0x80173F54
    {
            ctx->lr = 0x80197740u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80197740:
    ctx->pc = 0x80197740u;
    ctx->downcount -= 6;
    // 80197740: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197744:
    ctx->pc = 0x80197744u;
    // 80197744: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80197748:
    ctx->pc = 0x80197748u;
    // 80197748: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8019774C:
    ctx->pc = 0x8019774Cu;
    // 8019774C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80197750:
    ctx->pc = 0x80197750u;
    // 80197750: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80197754:
    ctx->pc = 0x80197754u;
    ctx->downcount -= 4;
    // 80197754: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197758:
    ctx->pc = 0x80197758u;
    // 80197758: lwz     r4, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019775C:
    ctx->pc = 0x8019775Cu;
    // 8019775C: rlwinm. r0, r4, 19, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80197760:
    ctx->pc = 0x80197760u;
    // 80197760: bc    12, 2, 0x8019776C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019776C;
        }
    }

label_80197764:
    ctx->pc = 0x80197764u;
    ctx->downcount -= 2;
    // 80197764: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80197768:
    ctx->pc = 0x80197768u;
    // 80197768: b       0x80197770
    {
            goto label_80197770;
    }

label_8019776C:
    ctx->pc = 0x8019776Cu;
    ctx->downcount -= 1;
    // 8019776C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80197770:
    ctx->pc = 0x80197770u;
    ctx->downcount -= 2;
    // 80197770: rlwinm. r0, r4, 17, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 17u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80197774:
    ctx->pc = 0x80197774u;
    // 80197774: bc    12, 2, 0x80197780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197780;
        }
    }

label_80197778:
    ctx->pc = 0x80197778u;
    ctx->downcount -= 2;
    // 80197778: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_8019777C:
    ctx->pc = 0x8019777Cu;
    // 8019777C: b       0x80197784
    {
            goto label_80197784;
    }

label_80197780:
    ctx->pc = 0x80197780u;
    ctx->downcount -= 1;
    // 80197780: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80197784:
    ctx->pc = 0x80197784u;
    ctx->downcount -= 4;
    // 80197784: lbz     r0, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80197788:
    ctx->pc = 0x80197788u;
    // 80197788: add   r7, r3, r4
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[7] = res;
    }

label_8019778C:
    ctx->pc = 0x8019778Cu;
    // 8019778C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197790:
    ctx->pc = 0x80197790u;
    // 80197790: bc    12, 2, 0x8019779C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019779C;
        }
    }

label_80197794:
    ctx->pc = 0x80197794u;
    ctx->downcount -= 2;
    // 80197794: li      r4, 2
    ctx->gpr[4] = (u32)(s32)(2);

label_80197798:
    ctx->pc = 0x80197798u;
    // 80197798: b       0x801977B4
    {
            goto label_801977B4;
    }

label_8019779C:
    ctx->pc = 0x8019779Cu;
    ctx->downcount -= 3;
    // 8019779C: lbz     r0, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801977A0:
    ctx->pc = 0x801977A0u;
    // 801977A0: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801977A4:
    ctx->pc = 0x801977A4u;
    // 801977A4: bc    12, 2, 0x801977B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801977B0;
        }
    }

label_801977A8:
    ctx->pc = 0x801977A8u;
    ctx->downcount -= 2;
    // 801977A8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_801977AC:
    ctx->pc = 0x801977ACu;
    // 801977AC: b       0x801977B4
    {
            goto label_801977B4;
    }

label_801977B0:
    ctx->pc = 0x801977B0u;
    ctx->downcount -= 1;
    // 801977B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_801977B4:
    ctx->pc = 0x801977B4u;
    ctx->downcount -= 3;
    // 801977B4: lwz     r6, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801977B8:
    ctx->pc = 0x801977B8u;
    // 801977B8: rlwinm. r0, r6, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801977BC:
    ctx->pc = 0x801977BCu;
    // 801977BC: bc    12, 2, 0x801977C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801977C8;
        }
    }

label_801977C0:
    ctx->pc = 0x801977C0u;
    ctx->downcount -= 2;
    // 801977C0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801977C4:
    ctx->pc = 0x801977C4u;
    // 801977C4: b       0x801977CC
    {
            goto label_801977CC;
    }

label_801977C8:
    ctx->pc = 0x801977C8u;
    ctx->downcount -= 1;
    // 801977C8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801977CC:
    ctx->pc = 0x801977CCu;
    ctx->downcount -= 2;
    // 801977CC: rlwinm. r0, r6, 30, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 30u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801977D0:
    ctx->pc = 0x801977D0u;
    // 801977D0: bc    12, 2, 0x801977DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801977DC;
        }
    }

label_801977D4:
    ctx->pc = 0x801977D4u;
    ctx->downcount -= 2;
    // 801977D4: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_801977D8:
    ctx->pc = 0x801977D8u;
    // 801977D8: b       0x801977E0
    {
            goto label_801977E0;
    }

label_801977DC:
    ctx->pc = 0x801977DCu;
    ctx->downcount -= 1;
    // 801977DC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_801977E0:
    ctx->pc = 0x801977E0u;
    ctx->downcount -= 3;
    // 801977E0: rlwinm. r0, r6, 28, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801977E4:
    ctx->pc = 0x801977E4u;
    // 801977E4: add   r8, r3, r5
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_801977E8:
    ctx->pc = 0x801977E8u;
    // 801977E8: bc    12, 2, 0x801977F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801977F4;
        }
    }

label_801977EC:
    ctx->pc = 0x801977ECu;
    ctx->downcount -= 2;
    // 801977EC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_801977F0:
    ctx->pc = 0x801977F0u;
    // 801977F0: b       0x801977F8
    {
            goto label_801977F8;
    }

label_801977F4:
    ctx->pc = 0x801977F4u;
    ctx->downcount -= 1;
    // 801977F4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_801977F8:
    ctx->pc = 0x801977F8u;
    ctx->downcount -= 3;
    // 801977F8: rlwinm. r0, r6, 26, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 26u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801977FC:
    ctx->pc = 0x801977FCu;
    // 801977FC: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80197800:
    ctx->pc = 0x80197800u;
    // 80197800: bc    12, 2, 0x8019780C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019780C;
        }
    }

label_80197804:
    ctx->pc = 0x80197804u;
    ctx->downcount -= 2;
    // 80197804: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80197808:
    ctx->pc = 0x80197808u;
    // 80197808: b       0x80197810
    {
            goto label_80197810;
    }

label_8019780C:
    ctx->pc = 0x8019780Cu;
    ctx->downcount -= 1;
    // 8019780C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80197810:
    ctx->pc = 0x80197810u;
    ctx->downcount -= 3;
    // 80197810: rlwinm. r0, r6, 24, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80197814:
    ctx->pc = 0x80197814u;
    // 80197814: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80197818:
    ctx->pc = 0x80197818u;
    // 80197818: bc    12, 2, 0x80197824
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197824;
        }
    }

label_8019781C:
    ctx->pc = 0x8019781Cu;
    ctx->downcount -= 2;
    // 8019781C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80197820:
    ctx->pc = 0x80197820u;
    // 80197820: b       0x80197828
    {
            goto label_80197828;
    }

label_80197824:
    ctx->pc = 0x80197824u;
    ctx->downcount -= 1;
    // 80197824: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80197828:
    ctx->pc = 0x80197828u;
    ctx->downcount -= 3;
    // 80197828: rlwinm. r0, r6, 22, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019782C:
    ctx->pc = 0x8019782Cu;
    // 8019782C: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80197830:
    ctx->pc = 0x80197830u;
    // 80197830: bc    12, 2, 0x8019783C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019783C;
        }
    }

label_80197834:
    ctx->pc = 0x80197834u;
    ctx->downcount -= 2;
    // 80197834: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80197838:
    ctx->pc = 0x80197838u;
    // 80197838: b       0x80197840
    {
            goto label_80197840;
    }

label_8019783C:
    ctx->pc = 0x8019783Cu;
    ctx->downcount -= 1;
    // 8019783C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80197840:
    ctx->pc = 0x80197840u;
    ctx->downcount -= 3;
    // 80197840: rlwinm. r0, r6, 20, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 20u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80197844:
    ctx->pc = 0x80197844u;
    // 80197844: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80197848:
    ctx->pc = 0x80197848u;
    // 80197848: bc    12, 2, 0x80197854
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197854;
        }
    }

label_8019784C:
    ctx->pc = 0x8019784Cu;
    ctx->downcount -= 2;
    // 8019784C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80197850:
    ctx->pc = 0x80197850u;
    // 80197850: b       0x80197858
    {
            goto label_80197858;
    }

label_80197854:
    ctx->pc = 0x80197854u;
    ctx->downcount -= 1;
    // 80197854: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_80197858:
    ctx->pc = 0x80197858u;
    ctx->downcount -= 3;
    // 80197858: rlwinm. r0, r6, 18, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0x00000003u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019785C:
    ctx->pc = 0x8019785Cu;
    // 8019785C: add   r8, r8, r3
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80197860:
    ctx->pc = 0x80197860u;
    // 80197860: bc    12, 2, 0x8019786C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019786C;
        }
    }

label_80197864:
    ctx->pc = 0x80197864u;
    ctx->downcount -= 2;
    // 80197864: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_80197868:
    ctx->pc = 0x80197868u;
    // 80197868: b       0x80197870
    {
            goto label_80197870;
    }

label_8019786C:
    ctx->pc = 0x8019786Cu;
    ctx->downcount -= 1;
    // 8019786C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80197870:
    ctx->pc = 0x80197870u;
    ctx->downcount -= 15;
    // 80197870: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_80197874:
    ctx->pc = 0x80197874u;
    // 80197874: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197878:
    ctx->pc = 0x80197878u;
    // 80197878: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019787C:
    ctx->pc = 0x8019787Cu;
    // 8019787C: add   r8, r8, r6
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80197880:
    ctx->pc = 0x80197880u;
    // 80197880: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197884:
    ctx->pc = 0x80197884u;
    // 80197884: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_80197888:
    ctx->pc = 0x80197888u;
    // 80197888: li      r4, 4104
    ctx->gpr[4] = (u32)(s32)(4104);

label_8019788C:
    ctx->pc = 0x8019788Cu;
    // 8019788C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80197890:
    ctx->pc = 0x80197890u;
    // 80197890: rlwinm r4, r8, 4, 0, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 4u) & 0xFFFFFFF0u;
    }

label_80197894:
    ctx->pc = 0x80197894u;
    // 80197894: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_80197898:
    ctx->pc = 0x80197898u;
    // 80197898: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8019789C:
    ctx->pc = 0x8019789Cu;
    // 8019789C: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801978A0:
    ctx->pc = 0x801978A0u;
    // 801978A0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_801978A4:
    ctx->pc = 0x801978A4u;
    // 801978A4: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801978A8:
    ctx->pc = 0x801978A8u;
    // 801978A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801978AC:
    ctx->pc = 0x801978ACu;
    ctx->downcount -= 2;
    // 801978AC: cmplwi  r3, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801978B0:
    ctx->pc = 0x801978B0u;
    // 801978B0: bc    12, 1, 0x80197BB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197BB0;
        }
    }

label_801978B4:
    ctx->pc = 0x801978B4u;
    ctx->downcount -= 7;
    // 801978B4: lis     r5, -32732
    ctx->gpr[5] = ((u32)(s32)(-32732) << 16);

label_801978B8:
    ctx->pc = 0x801978B8u;
    // 801978B8: addi    r5, r5, -4232
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-4232);

label_801978BC:
    ctx->pc = 0x801978BCu;
    // 801978BC: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_801978C0:
    ctx->pc = 0x801978C0u;
    // 801978C0: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801978C4:
    ctx->pc = 0x801978C4u;
    // 801978C4: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_801978C8:
    ctx->pc = 0x801978C8u;
    // 801978C8: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_801978CC:
    ctx->pc = 0x801978CCu;
    ctx->downcount -= 6;
    // 801978CC: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801978D0:
    ctx->pc = 0x801978D0u;
    // 801978D0: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_801978D4:
    ctx->pc = 0x801978D4u;
    // 801978D4: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_801978D8:
    ctx->pc = 0x801978D8u;
    // 801978D8: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_801978DC:
    ctx->pc = 0x801978DCu;
    // 801978DC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801978E0:
    ctx->pc = 0x801978E0u;
    // 801978E0: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_801978E4:
    ctx->pc = 0x801978E4u;
    ctx->downcount -= 8;
    // 801978E4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801978E8:
    ctx->pc = 0x801978E8u;
    // 801978E8: rlwinm r0, r4, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_801978EC:
    ctx->pc = 0x801978ECu;
    // 801978EC: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_801978F0:
    ctx->pc = 0x801978F0u;
    // 801978F0: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801978F4:
    ctx->pc = 0x801978F4u;
    // 801978F4: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_801978F8:
    ctx->pc = 0x801978F8u;
    // 801978F8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801978FC:
    ctx->pc = 0x801978FCu;
    // 801978FC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197900:
    ctx->pc = 0x80197900u;
    // 80197900: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197904:
    ctx->pc = 0x80197904u;
    ctx->downcount -= 8;
    // 80197904: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197908:
    ctx->pc = 0x80197908u;
    // 80197908: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_8019790C:
    ctx->pc = 0x8019790Cu;
    // 8019790C: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197910:
    ctx->pc = 0x80197910u;
    // 80197910: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197914:
    ctx->pc = 0x80197914u;
    // 80197914: rlwinm r3, r3, 0, 30, 28
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_80197918:
    ctx->pc = 0x80197918u;
    // 80197918: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019791C:
    ctx->pc = 0x8019791Cu;
    // 8019791C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197920:
    ctx->pc = 0x80197920u;
    // 80197920: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197924:
    ctx->pc = 0x80197924u;
    ctx->downcount -= 8;
    // 80197924: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197928:
    ctx->pc = 0x80197928u;
    // 80197928: rlwinm r0, r4, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 3u) & 0xFFFFFFF8u;
    }

label_8019792C:
    ctx->pc = 0x8019792Cu;
    // 8019792C: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197930:
    ctx->pc = 0x80197930u;
    // 80197930: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197934:
    ctx->pc = 0x80197934u;
    // 80197934: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_80197938:
    ctx->pc = 0x80197938u;
    // 80197938: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019793C:
    ctx->pc = 0x8019793Cu;
    // 8019793C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197940:
    ctx->pc = 0x80197940u;
    // 80197940: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197944:
    ctx->pc = 0x80197944u;
    ctx->downcount -= 8;
    // 80197944: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197948:
    ctx->pc = 0x80197948u;
    // 80197948: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_8019794C:
    ctx->pc = 0x8019794Cu;
    // 8019794C: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197950:
    ctx->pc = 0x80197950u;
    // 80197950: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197954:
    ctx->pc = 0x80197954u;
    // 80197954: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_80197958:
    ctx->pc = 0x80197958u;
    // 80197958: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019795C:
    ctx->pc = 0x8019795Cu;
    // 8019795C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197960:
    ctx->pc = 0x80197960u;
    // 80197960: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197964:
    ctx->pc = 0x80197964u;
    ctx->downcount -= 8;
    // 80197964: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197968:
    ctx->pc = 0x80197968u;
    // 80197968: rlwinm r0, r4, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 5u) & 0xFFFFFFE0u;
    }

label_8019796C:
    ctx->pc = 0x8019796Cu;
    // 8019796C: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197970:
    ctx->pc = 0x80197970u;
    // 80197970: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197974:
    ctx->pc = 0x80197974u;
    // 80197974: rlwinm r3, r3, 0, 27, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFDFu;
    }

label_80197978:
    ctx->pc = 0x80197978u;
    // 80197978: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019797C:
    ctx->pc = 0x8019797Cu;
    // 8019797C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197980:
    ctx->pc = 0x80197980u;
    // 80197980: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197984:
    ctx->pc = 0x80197984u;
    ctx->downcount -= 8;
    // 80197984: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197988:
    ctx->pc = 0x80197988u;
    // 80197988: rlwinm r0, r4, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 6u) & 0xFFFFFFC0u;
    }

label_8019798C:
    ctx->pc = 0x8019798Cu;
    // 8019798C: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197990:
    ctx->pc = 0x80197990u;
    // 80197990: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197994:
    ctx->pc = 0x80197994u;
    // 80197994: rlwinm r3, r3, 0, 26, 24
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFBFu;
    }

label_80197998:
    ctx->pc = 0x80197998u;
    // 80197998: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019799C:
    ctx->pc = 0x8019799Cu;
    // 8019799C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801979A0:
    ctx->pc = 0x801979A0u;
    // 801979A0: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_801979A4:
    ctx->pc = 0x801979A4u;
    ctx->downcount -= 8;
    // 801979A4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801979A8:
    ctx->pc = 0x801979A8u;
    // 801979A8: rlwinm r0, r4, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 7u) & 0xFFFFFF80u;
    }

label_801979AC:
    ctx->pc = 0x801979ACu;
    // 801979AC: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_801979B0:
    ctx->pc = 0x801979B0u;
    // 801979B0: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801979B4:
    ctx->pc = 0x801979B4u;
    // 801979B4: rlwinm r3, r3, 0, 25, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF7Fu;
    }

label_801979B8:
    ctx->pc = 0x801979B8u;
    // 801979B8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801979BC:
    ctx->pc = 0x801979BCu;
    // 801979BC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801979C0:
    ctx->pc = 0x801979C0u;
    // 801979C0: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_801979C4:
    ctx->pc = 0x801979C4u;
    ctx->downcount -= 8;
    // 801979C4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801979C8:
    ctx->pc = 0x801979C8u;
    // 801979C8: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_801979CC:
    ctx->pc = 0x801979CCu;
    // 801979CC: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_801979D0:
    ctx->pc = 0x801979D0u;
    // 801979D0: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801979D4:
    ctx->pc = 0x801979D4u;
    // 801979D4: rlwinm r3, r3, 0, 24, 22
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFEFFu;
    }

label_801979D8:
    ctx->pc = 0x801979D8u;
    // 801979D8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801979DC:
    ctx->pc = 0x801979DCu;
    // 801979DC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801979E0:
    ctx->pc = 0x801979E0u;
    // 801979E0: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_801979E4:
    ctx->pc = 0x801979E4u;
    ctx->downcount -= 8;
    // 801979E4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801979E8:
    ctx->pc = 0x801979E8u;
    // 801979E8: rlwinm r0, r4, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 9u) & 0xFFFFFE00u;
    }

label_801979EC:
    ctx->pc = 0x801979ECu;
    // 801979EC: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_801979F0:
    ctx->pc = 0x801979F0u;
    // 801979F0: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801979F4:
    ctx->pc = 0x801979F4u;
    // 801979F4: rlwinm r3, r3, 0, 23, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFF9FFu;
    }

label_801979F8:
    ctx->pc = 0x801979F8u;
    // 801979F8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801979FC:
    ctx->pc = 0x801979FCu;
    // 801979FC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197A00:
    ctx->pc = 0x80197A00u;
    // 80197A00: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197A04:
    ctx->pc = 0x80197A04u;
    ctx->downcount -= 2;
    // 80197A04: cmpwi   r4, 0
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

label_80197A08:
    ctx->pc = 0x80197A08u;
    // 80197A08: bc    12, 2, 0x80197A30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197A30;
        }
    }

label_80197A0C:
    ctx->pc = 0x80197A0Cu;
    ctx->downcount -= 9;
    // 80197A0C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A10:
    ctx->pc = 0x80197A10u;
    // 80197A10: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80197A14:
    ctx->pc = 0x80197A14u;
    // 80197A14: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197A18:
    ctx->pc = 0x80197A18u;
    // 80197A18: stb     r5, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80197A1C:
    ctx->pc = 0x80197A1Cu;
    // 80197A1C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A20:
    ctx->pc = 0x80197A20u;
    // 80197A20: stb     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197A24:
    ctx->pc = 0x80197A24u;
    // 80197A24: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A28:
    ctx->pc = 0x80197A28u;
    // 80197A28: stw     r4, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80197A2C:
    ctx->pc = 0x80197A2Cu;
    // 80197A2C: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197A30:
    ctx->pc = 0x80197A30u;
    ctx->downcount -= 4;
    // 80197A30: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A34:
    ctx->pc = 0x80197A34u;
    // 80197A34: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197A38:
    ctx->pc = 0x80197A38u;
    // 80197A38: stb     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197A3C:
    ctx->pc = 0x80197A3Cu;
    // 80197A3C: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197A40:
    ctx->pc = 0x80197A40u;
    ctx->downcount -= 2;
    // 80197A40: cmpwi   r4, 0
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

label_80197A44:
    ctx->pc = 0x80197A44u;
    // 80197A44: bc    12, 2, 0x80197A6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197A6C;
        }
    }

label_80197A48:
    ctx->pc = 0x80197A48u;
    ctx->downcount -= 9;
    // 80197A48: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A4C:
    ctx->pc = 0x80197A4Cu;
    // 80197A4C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_80197A50:
    ctx->pc = 0x80197A50u;
    // 80197A50: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197A54:
    ctx->pc = 0x80197A54u;
    // 80197A54: stb     r5, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80197A58:
    ctx->pc = 0x80197A58u;
    // 80197A58: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A5C:
    ctx->pc = 0x80197A5Cu;
    // 80197A5C: stb     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197A60:
    ctx->pc = 0x80197A60u;
    // 80197A60: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A64:
    ctx->pc = 0x80197A64u;
    // 80197A64: stw     r4, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80197A68:
    ctx->pc = 0x80197A68u;
    // 80197A68: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197A6C:
    ctx->pc = 0x80197A6Cu;
    ctx->downcount -= 4;
    // 80197A6C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A70:
    ctx->pc = 0x80197A70u;
    // 80197A70: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197A74:
    ctx->pc = 0x80197A74u;
    // 80197A74: stb     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197A78:
    ctx->pc = 0x80197A78u;
    // 80197A78: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197A7C:
    ctx->pc = 0x80197A7Cu;
    ctx->downcount -= 8;
    // 80197A7C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A80:
    ctx->pc = 0x80197A80u;
    // 80197A80: rlwinm r0, r4, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 13u) & 0xFFFFE000u;
    }

label_80197A84:
    ctx->pc = 0x80197A84u;
    // 80197A84: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197A88:
    ctx->pc = 0x80197A88u;
    // 80197A88: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197A8C:
    ctx->pc = 0x80197A8Cu;
    // 80197A8C: rlwinm r3, r3, 0, 19, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF9FFFu;
    }

label_80197A90:
    ctx->pc = 0x80197A90u;
    // 80197A90: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197A94:
    ctx->pc = 0x80197A94u;
    // 80197A94: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197A98:
    ctx->pc = 0x80197A98u;
    // 80197A98: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197A9C:
    ctx->pc = 0x80197A9Cu;
    ctx->downcount -= 8;
    // 80197A9C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197AA0:
    ctx->pc = 0x80197AA0u;
    // 80197AA0: rlwinm r0, r4, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 15u) & 0xFFFF8000u;
    }

label_80197AA4:
    ctx->pc = 0x80197AA4u;
    // 80197AA4: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197AA8:
    ctx->pc = 0x80197AA8u;
    // 80197AA8: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197AAC:
    ctx->pc = 0x80197AACu;
    // 80197AAC: rlwinm r3, r3, 0, 17, 14
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFE7FFFu;
    }

label_80197AB0:
    ctx->pc = 0x80197AB0u;
    // 80197AB0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197AB4:
    ctx->pc = 0x80197AB4u;
    // 80197AB4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197AB8:
    ctx->pc = 0x80197AB8u;
    // 80197AB8: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197ABC:
    ctx->pc = 0x80197ABCu;
    ctx->downcount -= 6;
    // 80197ABC: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197AC0:
    ctx->pc = 0x80197AC0u;
    // 80197AC0: lwzu     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80197AC4:
    ctx->pc = 0x80197AC4u;
    // 80197AC4: rlwinm r0, r0, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFCu;
    }

label_80197AC8:
    ctx->pc = 0x80197AC8u;
    // 80197AC8: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_80197ACC:
    ctx->pc = 0x80197ACCu;
    // 80197ACC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197AD0:
    ctx->pc = 0x80197AD0u;
    // 80197AD0: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197AD4:
    ctx->pc = 0x80197AD4u;
    ctx->downcount -= 8;
    // 80197AD4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197AD8:
    ctx->pc = 0x80197AD8u;
    // 80197AD8: rlwinm r0, r4, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_80197ADC:
    ctx->pc = 0x80197ADCu;
    // 80197ADC: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_80197AE0:
    ctx->pc = 0x80197AE0u;
    // 80197AE0: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197AE4:
    ctx->pc = 0x80197AE4u;
    // 80197AE4: rlwinm r3, r3, 0, 30, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF3u;
    }

label_80197AE8:
    ctx->pc = 0x80197AE8u;
    // 80197AE8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197AEC:
    ctx->pc = 0x80197AECu;
    // 80197AEC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197AF0:
    ctx->pc = 0x80197AF0u;
    // 80197AF0: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197AF4:
    ctx->pc = 0x80197AF4u;
    ctx->downcount -= 8;
    // 80197AF4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197AF8:
    ctx->pc = 0x80197AF8u;
    // 80197AF8: rlwinm r0, r4, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 4u) & 0xFFFFFFF0u;
    }

label_80197AFC:
    ctx->pc = 0x80197AFCu;
    // 80197AFC: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_80197B00:
    ctx->pc = 0x80197B00u;
    // 80197B00: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B04:
    ctx->pc = 0x80197B04u;
    // 80197B04: rlwinm r3, r3, 0, 28, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFCFu;
    }

label_80197B08:
    ctx->pc = 0x80197B08u;
    // 80197B08: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197B0C:
    ctx->pc = 0x80197B0Cu;
    // 80197B0C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197B10:
    ctx->pc = 0x80197B10u;
    // 80197B10: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197B14:
    ctx->pc = 0x80197B14u;
    ctx->downcount -= 8;
    // 80197B14: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B18:
    ctx->pc = 0x80197B18u;
    // 80197B18: rlwinm r0, r4, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 6u) & 0xFFFFFFC0u;
    }

label_80197B1C:
    ctx->pc = 0x80197B1Cu;
    // 80197B1C: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_80197B20:
    ctx->pc = 0x80197B20u;
    // 80197B20: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B24:
    ctx->pc = 0x80197B24u;
    // 80197B24: rlwinm r3, r3, 0, 26, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF3Fu;
    }

label_80197B28:
    ctx->pc = 0x80197B28u;
    // 80197B28: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197B2C:
    ctx->pc = 0x80197B2Cu;
    // 80197B2C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197B30:
    ctx->pc = 0x80197B30u;
    // 80197B30: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197B34:
    ctx->pc = 0x80197B34u;
    ctx->downcount -= 8;
    // 80197B34: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B38:
    ctx->pc = 0x80197B38u;
    // 80197B38: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80197B3C:
    ctx->pc = 0x80197B3Cu;
    // 80197B3C: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_80197B40:
    ctx->pc = 0x80197B40u;
    // 80197B40: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B44:
    ctx->pc = 0x80197B44u;
    // 80197B44: rlwinm r3, r3, 0, 24, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFCFFu;
    }

label_80197B48:
    ctx->pc = 0x80197B48u;
    // 80197B48: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197B4C:
    ctx->pc = 0x80197B4Cu;
    // 80197B4C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197B50:
    ctx->pc = 0x80197B50u;
    // 80197B50: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197B54:
    ctx->pc = 0x80197B54u;
    ctx->downcount -= 8;
    // 80197B54: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B58:
    ctx->pc = 0x80197B58u;
    // 80197B58: rlwinm r0, r4, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 10u) & 0xFFFFFC00u;
    }

label_80197B5C:
    ctx->pc = 0x80197B5Cu;
    // 80197B5C: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_80197B60:
    ctx->pc = 0x80197B60u;
    // 80197B60: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B64:
    ctx->pc = 0x80197B64u;
    // 80197B64: rlwinm r3, r3, 0, 22, 19
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFF3FFu;
    }

label_80197B68:
    ctx->pc = 0x80197B68u;
    // 80197B68: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197B6C:
    ctx->pc = 0x80197B6Cu;
    // 80197B6C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197B70:
    ctx->pc = 0x80197B70u;
    // 80197B70: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197B74:
    ctx->pc = 0x80197B74u;
    ctx->downcount -= 8;
    // 80197B74: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B78:
    ctx->pc = 0x80197B78u;
    // 80197B78: rlwinm r0, r4, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0xFFFFF000u;
    }

label_80197B7C:
    ctx->pc = 0x80197B7Cu;
    // 80197B7C: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_80197B80:
    ctx->pc = 0x80197B80u;
    // 80197B80: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B84:
    ctx->pc = 0x80197B84u;
    // 80197B84: rlwinm r3, r3, 0, 20, 17
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFCFFFu;
    }

label_80197B88:
    ctx->pc = 0x80197B88u;
    // 80197B88: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197B8C:
    ctx->pc = 0x80197B8Cu;
    // 80197B8C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197B90:
    ctx->pc = 0x80197B90u;
    // 80197B90: b       0x80197BB0
    {
            goto label_80197BB0;
    }

label_80197B94:
    ctx->pc = 0x80197B94u;
    ctx->downcount -= 7;
    // 80197B94: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197B98:
    ctx->pc = 0x80197B98u;
    // 80197B98: rlwinm r0, r4, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 14u) & 0xFFFFC000u;
    }

label_80197B9C:
    ctx->pc = 0x80197B9Cu;
    // 80197B9C: addi    r4, r3, 24
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(24);

label_80197BA0:
    ctx->pc = 0x80197BA0u;
    // 80197BA0: lwz     r3, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197BA4:
    ctx->pc = 0x80197BA4u;
    // 80197BA4: rlwinm r3, r3, 0, 18, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF3FFFu;
    }

label_80197BA8:
    ctx->pc = 0x80197BA8u;
    // 80197BA8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197BAC:
    ctx->pc = 0x80197BACu;
    // 80197BAC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197BB0:
    ctx->pc = 0x80197BB0u;
    ctx->downcount -= 4;
    // 80197BB0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197BB4:
    ctx->pc = 0x80197BB4u;
    // 80197BB4: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80197BB8:
    ctx->pc = 0x80197BB8u;
    // 80197BB8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197BBC:
    ctx->pc = 0x80197BBCu;
    // 80197BBC: bc    4, 2, 0x80197BCC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80197BCC;
        }
    }

label_80197BC0:
    ctx->pc = 0x80197BC0u;
    ctx->downcount -= 3;
    // 80197BC0: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80197BC4:
    ctx->pc = 0x80197BC4u;
    // 80197BC4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197BC8:
    ctx->pc = 0x80197BC8u;
    // 80197BC8: bc    12, 2, 0x80197BEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197BEC;
        }
    }

label_80197BCC:
    ctx->pc = 0x80197BCCu;
    ctx->downcount -= 8;
    // 80197BCC: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197BD0:
    ctx->pc = 0x80197BD0u;
    // 80197BD0: lwz     r0, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197BD4:
    ctx->pc = 0x80197BD4u;
    // 80197BD4: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197BD8:
    ctx->pc = 0x80197BD8u;
    // 80197BD8: rlwinm r0, r0, 11, 0, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0xFFFFF800u;
    }

label_80197BDC:
    ctx->pc = 0x80197BDCu;
    // 80197BDC: rlwinm r3, r3, 0, 21, 18
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFE7FFu;
    }

label_80197BE0:
    ctx->pc = 0x80197BE0u;
    // 80197BE0: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197BE4:
    ctx->pc = 0x80197BE4u;
    // 80197BE4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197BE8:
    ctx->pc = 0x80197BE8u;
    // 80197BE8: b       0x80197BF8
    {
            goto label_80197BF8;
    }

label_80197BEC:
    ctx->pc = 0x80197BECu;
    ctx->downcount -= 3;
    // 80197BEC: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80197BF0:
    ctx->pc = 0x80197BF0u;
    // 80197BF0: rlwinm r0, r0, 0, 21, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFE7FFu;
    }

label_80197BF4:
    ctx->pc = 0x80197BF4u;
    // 80197BF4: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197BF8:
    ctx->pc = 0x80197BF8u;
    ctx->downcount -= 5;
    // 80197BF8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197BFC:
    ctx->pc = 0x80197BFCu;
    // 80197BFC: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197C00:
    ctx->pc = 0x80197C00u;
    // 80197C00: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80197C04:
    ctx->pc = 0x80197C04u;
    // 80197C04: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197C08:
    ctx->pc = 0x80197C08u;
    // 80197C08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80197C0C:
    ctx->pc = 0x80197C0Cu;
    ctx->downcount -= 3;
    // 80197C0C: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80197C10:
    ctx->pc = 0x80197C10u;
    // 80197C10: addi    r4, r4, -4128
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-4128);

label_80197C14:
    ctx->pc = 0x80197C14u;
    // 80197C14: b       0x80197F28
    {
            goto label_80197F28;
    }

label_80197C18:
    ctx->pc = 0x80197C18u;
    ctx->downcount -= 4;
    // 80197C18: lwz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C1C:
    ctx->pc = 0x80197C1Cu;
    // 80197C1C: lwz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197C20:
    // 80197C20: cmplwi  r5, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197C24:
    // 80197C24: bc    12, 1, 0x80197F24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197F24;
        }
    }

label_80197C28:
    ctx->downcount -= 5;
    // 80197C28: rlwinm r5, r5, 2, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_80197C2C:
    ctx->pc = 0x80197C2Cu;
    // 80197C2C: lwzx    r5, r4, r5
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[5];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C30:
    ctx->pc = 0x80197C30u;
    // 80197C30: mtctr    r5
    ctx->ctr = ctx->gpr[5];

label_80197C34:
    ctx->pc = 0x80197C34u;
    // 80197C34: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80197C38:
    ctx->pc = 0x80197C38u;
    ctx->downcount -= 7;
    // 80197C38: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C3C:
    // 80197C3C: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197C40:
    ctx->pc = 0x80197C40u;
    // 80197C40: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C44:
    // 80197C44: rlwinm r5, r5, 0, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFEu;
    }

label_80197C48:
    // 80197C48: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197C4C:
    ctx->pc = 0x80197C4Cu;
    // 80197C4C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197C50:
    // 80197C50: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197C54:
    ctx->pc = 0x80197C54u;
    ctx->downcount -= 8;
    // 80197C54: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C58:
    // 80197C58: rlwinm r0, r0, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0xFFFFFFFEu;
    }

label_80197C5C:
    // 80197C5C: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197C60:
    ctx->pc = 0x80197C60u;
    // 80197C60: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C64:
    // 80197C64: rlwinm r5, r5, 0, 31, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFDu;
    }

label_80197C68:
    // 80197C68: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197C6C:
    ctx->pc = 0x80197C6Cu;
    // 80197C6C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197C70:
    // 80197C70: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197C74:
    ctx->pc = 0x80197C74u;
    ctx->downcount -= 8;
    // 80197C74: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C78:
    // 80197C78: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80197C7C:
    // 80197C7C: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197C80:
    ctx->pc = 0x80197C80u;
    // 80197C80: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C84:
    // 80197C84: rlwinm r5, r5, 0, 30, 28
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFBu;
    }

label_80197C88:
    // 80197C88: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197C8C:
    ctx->pc = 0x80197C8Cu;
    // 80197C8C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197C90:
    // 80197C90: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197C94:
    ctx->pc = 0x80197C94u;
    ctx->downcount -= 8;
    // 80197C94: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197C98:
    // 80197C98: rlwinm r0, r0, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0xFFFFFFF8u;
    }

label_80197C9C:
    // 80197C9C: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197CA0:
    ctx->pc = 0x80197CA0u;
    // 80197CA0: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197CA4:
    // 80197CA4: rlwinm r5, r5, 0, 29, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF7u;
    }

label_80197CA8:
    // 80197CA8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197CAC:
    ctx->pc = 0x80197CACu;
    // 80197CAC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197CB0:
    // 80197CB0: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197CB4:
    ctx->pc = 0x80197CB4u;
    ctx->downcount -= 8;
    // 80197CB4: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197CB8:
    // 80197CB8: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80197CBC:
    // 80197CBC: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197CC0:
    ctx->pc = 0x80197CC0u;
    // 80197CC0: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197CC4:
    // 80197CC4: rlwinm r5, r5, 0, 28, 26
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFEFu;
    }

label_80197CC8:
    // 80197CC8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197CCC:
    ctx->pc = 0x80197CCCu;
    // 80197CCC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197CD0:
    // 80197CD0: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197CD4:
    ctx->pc = 0x80197CD4u;
    ctx->downcount -= 8;
    // 80197CD4: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197CD8:
    // 80197CD8: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_80197CDC:
    // 80197CDC: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197CE0:
    ctx->pc = 0x80197CE0u;
    // 80197CE0: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197CE4:
    // 80197CE4: rlwinm r5, r5, 0, 27, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFDFu;
    }

label_80197CE8:
    // 80197CE8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197CEC:
    ctx->pc = 0x80197CECu;
    // 80197CEC: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197CF0:
    // 80197CF0: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197CF4:
    ctx->pc = 0x80197CF4u;
    ctx->downcount -= 8;
    // 80197CF4: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197CF8:
    // 80197CF8: rlwinm r0, r0, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0xFFFFFFC0u;
    }

label_80197CFC:
    // 80197CFC: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197D00:
    ctx->pc = 0x80197D00u;
    // 80197D00: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D04:
    // 80197D04: rlwinm r5, r5, 0, 26, 24
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFBFu;
    }

label_80197D08:
    // 80197D08: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197D0C:
    ctx->pc = 0x80197D0Cu;
    // 80197D0C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197D10:
    // 80197D10: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197D14:
    ctx->pc = 0x80197D14u;
    ctx->downcount -= 8;
    // 80197D14: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D18:
    // 80197D18: rlwinm r0, r0, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 7u) & 0xFFFFFF80u;
    }

label_80197D1C:
    // 80197D1C: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197D20:
    ctx->pc = 0x80197D20u;
    // 80197D20: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D24:
    // 80197D24: rlwinm r5, r5, 0, 25, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFF7Fu;
    }

label_80197D28:
    // 80197D28: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197D2C:
    ctx->pc = 0x80197D2Cu;
    // 80197D2C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197D30:
    // 80197D30: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197D34:
    ctx->pc = 0x80197D34u;
    ctx->downcount -= 8;
    // 80197D34: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D38:
    // 80197D38: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_80197D3C:
    // 80197D3C: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197D40:
    ctx->pc = 0x80197D40u;
    // 80197D40: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D44:
    // 80197D44: rlwinm r5, r5, 0, 24, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFEFFu;
    }

label_80197D48:
    // 80197D48: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197D4C:
    ctx->pc = 0x80197D4Cu;
    // 80197D4C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197D50:
    // 80197D50: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197D54:
    ctx->pc = 0x80197D54u;
    ctx->downcount -= 8;
    // 80197D54: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D58:
    // 80197D58: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_80197D5C:
    // 80197D5C: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197D60:
    ctx->pc = 0x80197D60u;
    // 80197D60: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D64:
    // 80197D64: rlwinm r5, r5, 0, 23, 20
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF9FFu;
    }

label_80197D68:
    // 80197D68: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197D6C:
    ctx->pc = 0x80197D6Cu;
    // 80197D6C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197D70:
    // 80197D70: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197D74:
    ctx->downcount -= 2;
    // 80197D74: cmpwi   r0, 0
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

label_80197D78:
    // 80197D78: bc    12, 2, 0x80197DA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197DA0;
        }
    }

label_80197D7C:
    ctx->pc = 0x80197D7Cu;
    ctx->downcount -= 9;
    // 80197D7C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D80:
    // 80197D80: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80197D84:
    // 80197D84: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80197D88:
    ctx->pc = 0x80197D88u;
    // 80197D88: stb     r7, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_80197D8C:
    ctx->pc = 0x80197D8Cu;
    // 80197D8C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D90:
    ctx->pc = 0x80197D90u;
    // 80197D90: stb     r6, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80197D94:
    ctx->pc = 0x80197D94u;
    // 80197D94: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197D98:
    ctx->pc = 0x80197D98u;
    // 80197D98: stw     r0, 1048(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197D9C:
    // 80197D9C: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197DA0:
    ctx->pc = 0x80197DA0u;
    ctx->downcount -= 4;
    // 80197DA0: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197DA4:
    // 80197DA4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197DA8:
    ctx->pc = 0x80197DA8u;
    // 80197DA8: stb     r0, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197DAC:
    // 80197DAC: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197DB0:
    ctx->downcount -= 2;
    // 80197DB0: cmpwi   r0, 0
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

label_80197DB4:
    // 80197DB4: bc    12, 2, 0x80197DDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197DDC;
        }
    }

label_80197DB8:
    ctx->pc = 0x80197DB8u;
    ctx->downcount -= 9;
    // 80197DB8: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197DBC:
    // 80197DBC: li      r7, 1
    ctx->gpr[7] = (u32)(s32)(1);

label_80197DC0:
    // 80197DC0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_80197DC4:
    ctx->pc = 0x80197DC4u;
    // 80197DC4: stb     r7, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[7]);
    }

label_80197DC8:
    ctx->pc = 0x80197DC8u;
    // 80197DC8: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197DCC:
    ctx->pc = 0x80197DCCu;
    // 80197DCC: stb     r6, 1052(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80197DD0:
    ctx->pc = 0x80197DD0u;
    // 80197DD0: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197DD4:
    ctx->pc = 0x80197DD4u;
    // 80197DD4: stw     r0, 1048(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1048);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197DD8:
    // 80197DD8: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197DDC:
    ctx->pc = 0x80197DDCu;
    ctx->downcount -= 4;
    // 80197DDC: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197DE0:
    // 80197DE0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80197DE4:
    ctx->pc = 0x80197DE4u;
    // 80197DE4: stb     r0, 1053(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197DE8:
    // 80197DE8: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197DEC:
    ctx->pc = 0x80197DECu;
    ctx->downcount -= 8;
    // 80197DEC: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197DF0:
    // 80197DF0: rlwinm r0, r0, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0xFFFFE000u;
    }

label_80197DF4:
    // 80197DF4: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197DF8:
    ctx->pc = 0x80197DF8u;
    // 80197DF8: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197DFC:
    // 80197DFC: rlwinm r5, r5, 0, 19, 16
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF9FFFu;
    }

label_80197E00:
    // 80197E00: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197E04:
    ctx->pc = 0x80197E04u;
    // 80197E04: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197E08:
    // 80197E08: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197E0C:
    ctx->pc = 0x80197E0Cu;
    ctx->downcount -= 8;
    // 80197E0C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E10:
    // 80197E10: rlwinm r0, r0, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 15u) & 0xFFFF8000u;
    }

label_80197E14:
    // 80197E14: addi    r6, r5, 20
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(20);

label_80197E18:
    ctx->pc = 0x80197E18u;
    // 80197E18: lwz     r5, 20(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(20);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E1C:
    // 80197E1C: rlwinm r5, r5, 0, 17, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFE7FFFu;
    }

label_80197E20:
    // 80197E20: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197E24:
    ctx->pc = 0x80197E24u;
    // 80197E24: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197E28:
    // 80197E28: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197E2C:
    ctx->pc = 0x80197E2Cu;
    ctx->downcount -= 7;
    // 80197E2C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E30:
    // 80197E30: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197E34:
    ctx->pc = 0x80197E34u;
    // 80197E34: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E38:
    // 80197E38: rlwinm r5, r5, 0, 0, 29
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFFCu;
    }

label_80197E3C:
    // 80197E3C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197E40:
    ctx->pc = 0x80197E40u;
    // 80197E40: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197E44:
    // 80197E44: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197E48:
    ctx->pc = 0x80197E48u;
    ctx->downcount -= 8;
    // 80197E48: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E4C:
    // 80197E4C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80197E50:
    // 80197E50: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197E54:
    ctx->pc = 0x80197E54u;
    // 80197E54: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E58:
    // 80197E58: rlwinm r5, r5, 0, 30, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF3u;
    }

label_80197E5C:
    // 80197E5C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197E60:
    ctx->pc = 0x80197E60u;
    // 80197E60: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197E64:
    // 80197E64: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197E68:
    ctx->pc = 0x80197E68u;
    ctx->downcount -= 8;
    // 80197E68: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E6C:
    // 80197E6C: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_80197E70:
    // 80197E70: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197E74:
    ctx->pc = 0x80197E74u;
    // 80197E74: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E78:
    // 80197E78: rlwinm r5, r5, 0, 28, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFCFu;
    }

label_80197E7C:
    // 80197E7C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197E80:
    ctx->pc = 0x80197E80u;
    // 80197E80: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197E84:
    // 80197E84: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197E88:
    ctx->pc = 0x80197E88u;
    ctx->downcount -= 8;
    // 80197E88: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E8C:
    // 80197E8C: rlwinm r0, r0, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 6u) & 0xFFFFFFC0u;
    }

label_80197E90:
    // 80197E90: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197E94:
    ctx->pc = 0x80197E94u;
    // 80197E94: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197E98:
    // 80197E98: rlwinm r5, r5, 0, 26, 23
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFF3Fu;
    }

label_80197E9C:
    // 80197E9C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197EA0:
    ctx->pc = 0x80197EA0u;
    // 80197EA0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197EA4:
    // 80197EA4: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197EA8:
    ctx->pc = 0x80197EA8u;
    ctx->downcount -= 8;
    // 80197EA8: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197EAC:
    // 80197EAC: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_80197EB0:
    // 80197EB0: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197EB4:
    ctx->pc = 0x80197EB4u;
    // 80197EB4: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197EB8:
    // 80197EB8: rlwinm r5, r5, 0, 24, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFCFFu;
    }

label_80197EBC:
    // 80197EBC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197EC0:
    ctx->pc = 0x80197EC0u;
    // 80197EC0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197EC4:
    // 80197EC4: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197EC8:
    ctx->pc = 0x80197EC8u;
    ctx->downcount -= 8;
    // 80197EC8: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197ECC:
    // 80197ECC: rlwinm r0, r0, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0xFFFFFC00u;
    }

label_80197ED0:
    // 80197ED0: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197ED4:
    ctx->pc = 0x80197ED4u;
    // 80197ED4: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197ED8:
    // 80197ED8: rlwinm r5, r5, 0, 22, 19
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF3FFu;
    }

label_80197EDC:
    // 80197EDC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197EE0:
    ctx->pc = 0x80197EE0u;
    // 80197EE0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197EE4:
    // 80197EE4: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197EE8:
    ctx->pc = 0x80197EE8u;
    ctx->downcount -= 8;
    // 80197EE8: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197EEC:
    // 80197EEC: rlwinm r0, r0, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 12u) & 0xFFFFF000u;
    }

label_80197EF0:
    // 80197EF0: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197EF4:
    ctx->pc = 0x80197EF4u;
    // 80197EF4: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197EF8:
    // 80197EF8: rlwinm r5, r5, 0, 20, 17
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFCFFFu;
    }

label_80197EFC:
    // 80197EFC: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197F00:
    ctx->pc = 0x80197F00u;
    // 80197F00: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197F04:
    // 80197F04: b       0x80197F24
    {
            goto label_80197F24;
    }

label_80197F08:
    ctx->pc = 0x80197F08u;
    ctx->downcount -= 7;
    // 80197F08: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197F0C:
    // 80197F0C: rlwinm r0, r0, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0xFFFFC000u;
    }

label_80197F10:
    // 80197F10: addi    r6, r5, 24
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(24);

label_80197F14:
    ctx->pc = 0x80197F14u;
    // 80197F14: lwz     r5, 24(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(24);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80197F18:
    // 80197F18: rlwinm r5, r5, 0, 18, 15
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFF3FFFu;
    }

label_80197F1C:
    // 80197F1C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80197F20:
    ctx->pc = 0x80197F20u;
    // 80197F20: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197F24:
    ctx->downcount -= 1;
    // 80197F24: addi    r3, r3, 8
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8);

label_80197F28:
    ctx->pc = 0x80197F28u;
    ctx->downcount -= 3;
    // 80197F28: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197F2C:
    // 80197F2C: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197F30:
    // 80197F30: bc    4, 2, 0x80197C18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197C18u;
                return;
            }
            goto label_80197C18;
        }
    }

label_80197F34:
    ctx->pc = 0x80197F34u;
    ctx->downcount -= 4;
    // 80197F34: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197F38:
    ctx->pc = 0x80197F38u;
    // 80197F38: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80197F3C:
    ctx->pc = 0x80197F3Cu;
    // 80197F3C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197F40:
    ctx->pc = 0x80197F40u;
    // 80197F40: bc    4, 2, 0x80197F50
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80197F50;
        }
    }

label_80197F44:
    ctx->pc = 0x80197F44u;
    ctx->downcount -= 3;
    // 80197F44: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_80197F48:
    ctx->pc = 0x80197F48u;
    // 80197F48: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197F4C:
    ctx->pc = 0x80197F4Cu;
    // 80197F4C: bc    12, 2, 0x80197F70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80197F70;
        }
    }

label_80197F50:
    ctx->pc = 0x80197F50u;
    ctx->downcount -= 8;
    // 80197F50: addi    r4, r3, 20
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(20);

label_80197F54:
    ctx->pc = 0x80197F54u;
    // 80197F54: lwz     r0, 1048(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1048);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197F58:
    ctx->pc = 0x80197F58u;
    // 80197F58: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197F5C:
    ctx->pc = 0x80197F5Cu;
    // 80197F5C: rlwinm r0, r0, 11, 0, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0xFFFFF800u;
    }

label_80197F60:
    ctx->pc = 0x80197F60u;
    // 80197F60: rlwinm r3, r3, 0, 21, 18
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFE7FFu;
    }

label_80197F64:
    ctx->pc = 0x80197F64u;
    // 80197F64: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80197F68:
    ctx->pc = 0x80197F68u;
    // 80197F68: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197F6C:
    ctx->pc = 0x80197F6Cu;
    // 80197F6C: b       0x80197F7C
    {
            goto label_80197F7C;
    }

label_80197F70:
    ctx->pc = 0x80197F70u;
    ctx->downcount -= 3;
    // 80197F70: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80197F74:
    ctx->pc = 0x80197F74u;
    // 80197F74: rlwinm r0, r0, 0, 21, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFE7FFu;
    }

label_80197F78:
    ctx->pc = 0x80197F78u;
    // 80197F78: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197F7C:
    ctx->pc = 0x80197F7Cu;
    ctx->downcount -= 5;
    // 80197F7C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197F80:
    ctx->pc = 0x80197F80u;
    // 80197F80: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197F84:
    ctx->pc = 0x80197F84u;
    // 80197F84: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80197F88:
    ctx->pc = 0x80197F88u;
    // 80197F88: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197F8C:
    ctx->pc = 0x80197F8Cu;
    // 80197F8C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80197F90:
    ctx->pc = 0x80197F90u;
    ctx->downcount -= 18;
    // 80197F90: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80197F94:
    ctx->pc = 0x80197F94u;
    // 80197F94: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_80197F98:
    ctx->pc = 0x80197F98u;
    // 80197F98: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197F9C:
    ctx->pc = 0x80197F9Cu;
    // 80197F9C: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80197FA0:
    ctx->pc = 0x80197FA0u;
    // 80197FA0: li      r3, 80
    ctx->gpr[3] = (u32)(s32)(80);

label_80197FA4:
    ctx->pc = 0x80197FA4u;
    // 80197FA4: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80197FA8:
    ctx->pc = 0x80197FA8u;
    // 80197FA8: li      r0, 96
    ctx->gpr[0] = (u32)(s32)(96);

label_80197FAC:
    ctx->pc = 0x80197FACu;
    // 80197FAC: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80197FB0:
    ctx->pc = 0x80197FB0u;
    // 80197FB0: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80197FB4:
    ctx->pc = 0x80197FB4u;
    // 80197FB4: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80197FB8:
    ctx->pc = 0x80197FB8u;
    // 80197FB8: stb     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80197FBC:
    ctx->pc = 0x80197FBCu;
    // 80197FBC: lwz     r3, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197FC0:
    ctx->pc = 0x80197FC0u;
    // 80197FC0: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80197FC4:
    ctx->pc = 0x80197FC4u;
    // 80197FC4: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80197FC8:
    ctx->pc = 0x80197FC8u;
    // 80197FC8: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80197FCC:
    ctx->pc = 0x80197FCCu;
    // 80197FCC: lwz     r0, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80197FD0:
    ctx->pc = 0x80197FD0u;
    // 80197FD0: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80197FD4:
    ctx->pc = 0x80197FD4u;
    // 80197FD4: bl      0x80197754
    {
            ctx->lr = 0x80197FD8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197754u;
                return;
            }
            goto label_80197754;
    }

label_80197FD8:
    ctx->pc = 0x80197FD8u;
    ctx->downcount -= 4;
    // 80197FD8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80197FDC:
    ctx->pc = 0x80197FDCu;
    // 80197FDC: lhz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80197FE0:
    ctx->pc = 0x80197FE0u;
    // 80197FE0: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80197FE4:
    ctx->pc = 0x80197FE4u;
    // 80197FE4: bc    12, 2, 0x801980E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801980E4;
        }
    }

label_80197FE8:
    ctx->pc = 0x80197FE8u;
    ctx->downcount -= 67;
    // 80197FE8: lbz     r5, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_80197FEC:
    ctx->pc = 0x80197FECu;
    // 80197FEC: addi    r9, r13, -28680
    ctx->gpr[9] = ctx->gpr[13] + (u32)(s32)(-28680);

label_80197FF0:
    ctx->pc = 0x80197FF0u;
    // 80197FF0: lwz     r31, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80197FF4:
    ctx->pc = 0x80197FF4u;
    // 80197FF4: addi    r7, r13, -28688
    ctx->gpr[7] = ctx->gpr[13] + (u32)(s32)(-28688);

label_80197FF8:
    ctx->pc = 0x80197FF8u;
    // 80197FF8: rlwinm r5, r5, 1, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 1u) & 0xFFFFFFFEu;
    }

label_80197FFC:
    ctx->pc = 0x80197FFCu;
    // 80197FFC: addi    r8, r5, 1
    ctx->gpr[8] = ctx->gpr[5] + (u32)(s32)(1);

label_80198000:
    ctx->pc = 0x80198000u;
    // 80198000: lwz     r4, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198004:
    ctx->pc = 0x80198004u;
    // 80198004: rlwinm r6, r31, 21, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[31], 21u) & 0x00000003u;
    }

label_80198008:
    ctx->pc = 0x80198008u;
    // 80198008: lbzx    r10, r9, r6
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[6];
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_8019800C:
    ctx->pc = 0x8019800Cu;
    // 8019800C: rlwinm r0, r31, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00000001u;
    }

label_80198010:
    ctx->pc = 0x80198010u;
    // 80198010: rlwinm r11, r31, 31, 31, 31
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[31], 31u) & 0x00000001u;
    }

label_80198014:
    ctx->pc = 0x80198014u;
    // 80198014: rlwinm r6, r31, 19, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[31], 19u) & 0x00000003u;
    }

label_80198018:
    ctx->pc = 0x80198018u;
    // 80198018: rlwinm r5, r31, 23, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 23u) & 0x00000003u;
    }

label_8019801C:
    ctx->pc = 0x8019801Cu;
    // 8019801C: lbzx    r6, r7, r6
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[6];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80198020:
    ctx->pc = 0x80198020u;
    // 80198020: add   r0, r0, r11
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198024:
    ctx->pc = 0x80198024u;
    // 80198024: lbzx    r11, r9, r5
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[5];
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_80198028:
    ctx->pc = 0x80198028u;
    // 80198028: rlwinm r12, r31, 30, 31, 31
    {
        ctx->gpr[12] = dolrecomp_rotl32(ctx->gpr[31], 30u) & 0x00000001u;
    }

label_8019802C:
    ctx->pc = 0x8019802Cu;
    // 8019802C: rlwinm r5, r31, 17, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 17u) & 0x00000003u;
    }

label_80198030:
    ctx->pc = 0x80198030u;
    // 80198030: lbzx    r9, r7, r5
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[5];
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_80198034:
    ctx->pc = 0x80198034u;
    // 80198034: add   r0, r0, r12
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[12];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198038:
    ctx->pc = 0x80198038u;
    // 80198038: rlwinm r5, r31, 29, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 29u) & 0x00000001u;
    }

label_8019803C:
    ctx->pc = 0x8019803Cu;
    // 8019803C: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198040:
    ctx->pc = 0x80198040u;
    // 80198040: rlwinm r5, r31, 28, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 28u) & 0x00000001u;
    }

label_80198044:
    ctx->pc = 0x80198044u;
    // 80198044: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198048:
    ctx->pc = 0x80198048u;
    // 80198048: rlwinm r5, r31, 27, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 27u) & 0x00000001u;
    }

label_8019804C:
    ctx->pc = 0x8019804Cu;
    // 8019804C: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198050:
    ctx->pc = 0x80198050u;
    // 80198050: rlwinm r7, r31, 26, 31, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[31], 26u) & 0x00000001u;
    }

label_80198054:
    ctx->pc = 0x80198054u;
    // 80198054: mullw   r5, r10, r8
    {
        s64 product = (s64)(s32)ctx->gpr[10] * (s64)(s32)ctx->gpr[8];
        ctx->gpr[5] = (u32)product;
    }

label_80198058:
    ctx->pc = 0x80198058u;
    // 80198058: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8019805C:
    ctx->pc = 0x8019805Cu;
    // 8019805C: rlwinm r7, r31, 25, 31, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[31], 25u) & 0x00000001u;
    }

label_80198060:
    ctx->pc = 0x80198060u;
    // 80198060: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198064:
    ctx->pc = 0x80198064u;
    // 80198064: rlwinm r7, r31, 24, 31, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[31], 24u) & 0x00000001u;
    }

label_80198068:
    ctx->pc = 0x80198068u;
    // 80198068: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8019806C:
    ctx->pc = 0x8019806Cu;
    // 8019806C: add   r0, r0, r11
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198070:
    ctx->pc = 0x80198070u;
    // 80198070: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198074:
    ctx->pc = 0x80198074u;
    // 80198074: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198078:
    ctx->pc = 0x80198078u;
    // 80198078: rlwinm r6, r4, 0, 30, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000003u;
    }

label_8019807C:
    ctx->pc = 0x8019807Cu;
    // 8019807C: addi    r8, r13, -28684
    ctx->gpr[8] = ctx->gpr[13] + (u32)(s32)(-28684);

label_80198080:
    ctx->pc = 0x80198080u;
    // 80198080: rlwinm r5, r4, 30, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 30u) & 0x00000003u;
    }

label_80198084:
    ctx->pc = 0x80198084u;
    // 80198084: lbzx    r7, r8, r6
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[6];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_80198088:
    ctx->pc = 0x80198088u;
    // 80198088: add   r0, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8019808C:
    ctx->pc = 0x8019808Cu;
    // 8019808C: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_80198090:
    ctx->pc = 0x80198090u;
    // 80198090: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_80198094:
    ctx->pc = 0x80198094u;
    // 80198094: rlwinm r5, r4, 28, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 28u) & 0x00000003u;
    }

label_80198098:
    ctx->pc = 0x80198098u;
    // 80198098: lbzx    r7, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8019809C:
    ctx->pc = 0x8019809Cu;
    // 8019809C: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801980A0:
    ctx->pc = 0x801980A0u;
    // 801980A0: rlwinm r5, r4, 26, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 26u) & 0x00000003u;
    }

label_801980A4:
    ctx->pc = 0x801980A4u;
    // 801980A4: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_801980A8:
    ctx->pc = 0x801980A8u;
    // 801980A8: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801980AC:
    ctx->pc = 0x801980ACu;
    // 801980AC: rlwinm r5, r4, 24, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 24u) & 0x00000003u;
    }

label_801980B0:
    ctx->pc = 0x801980B0u;
    // 801980B0: lbzx    r7, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_801980B4:
    ctx->pc = 0x801980B4u;
    // 801980B4: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801980B8:
    ctx->pc = 0x801980B8u;
    // 801980B8: rlwinm r5, r4, 22, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 22u) & 0x00000003u;
    }

label_801980BC:
    ctx->pc = 0x801980BCu;
    // 801980BC: lbzx    r6, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[6] = mem_read8(ctx, ea);
    }

label_801980C0:
    ctx->pc = 0x801980C0u;
    // 801980C0: rlwinm r5, r4, 20, 30, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 20u) & 0x00000003u;
    }

label_801980C4:
    ctx->pc = 0x801980C4u;
    // 801980C4: add   r0, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801980C8:
    ctx->pc = 0x801980C8u;
    // 801980C8: lbzx    r5, r8, r5
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[5];
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_801980CC:
    ctx->pc = 0x801980CCu;
    // 801980CC: rlwinm r4, r4, 18, 30, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 18u) & 0x00000003u;
    }

label_801980D0:
    ctx->pc = 0x801980D0u;
    // 801980D0: add   r0, r0, r6
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801980D4:
    ctx->pc = 0x801980D4u;
    // 801980D4: lbzx    r4, r8, r4
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[4];
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_801980D8:
    ctx->pc = 0x801980D8u;
    // 801980D8: add   r0, r0, r5
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801980DC:
    ctx->pc = 0x801980DCu;
    // 801980DC: add   r0, r0, r4
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_801980E0:
    ctx->pc = 0x801980E0u;
    // 801980E0: sth     r0, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801980E4:
    ctx->pc = 0x801980E4u;
    ctx->downcount -= 6;
    // 801980E4: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801980E8:
    ctx->pc = 0x801980E8u;
    // 801980E8: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801980EC:
    ctx->pc = 0x801980ECu;
    // 801980EC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_801980F0:
    ctx->pc = 0x801980F0u;
    // 801980F0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801980F4:
    ctx->pc = 0x801980F4u;
    // 801980F4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801980F8:
    ctx->pc = 0x801980F8u;
    ctx->downcount -= 2;
    // 801980F8: cmplwi  r3, 0x0019
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0019u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801980FC:
    ctx->pc = 0x801980FCu;
    // 801980FC: bc    12, 1, 0x801982A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801982A0;
        }
    }

label_80198100:
    ctx->pc = 0x80198100u;
    ctx->downcount -= 7;
    // 80198100: lis     r5, -32732
    ctx->gpr[5] = ((u32)(s32)(-32732) << 16);

label_80198104:
    ctx->pc = 0x80198104u;
    // 80198104: addi    r5, r5, -4024
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-4024);

label_80198108:
    ctx->pc = 0x80198108u;
    // 80198108: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_8019810C:
    ctx->pc = 0x8019810Cu;
    // 8019810C: lwzx    r0, r5, r0
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198110:
    ctx->pc = 0x80198110u;
    // 80198110: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80198114:
    ctx->pc = 0x80198114u;
    // 80198114: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80198118:
    ctx->pc = 0x80198118u;
    ctx->downcount -= 4;
    // 80198118: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019811C:
    ctx->pc = 0x8019811Cu;
    // 8019811C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198120:
    ctx->pc = 0x80198120u;
    // 80198120: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80198124:
    ctx->pc = 0x80198124u;
    // 80198124: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198128:
    ctx->pc = 0x80198128u;
    ctx->downcount -= 4;
    // 80198128: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019812C:
    ctx->pc = 0x8019812Cu;
    // 8019812C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198130:
    ctx->pc = 0x80198130u;
    // 80198130: rlwinm r0, r0, 31, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000001u;
    }

label_80198134:
    ctx->pc = 0x80198134u;
    // 80198134: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198138:
    ctx->pc = 0x80198138u;
    ctx->downcount -= 4;
    // 80198138: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019813C:
    ctx->pc = 0x8019813Cu;
    // 8019813C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198140:
    ctx->pc = 0x80198140u;
    // 80198140: rlwinm r0, r0, 30, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000001u;
    }

label_80198144:
    ctx->pc = 0x80198144u;
    // 80198144: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198148:
    ctx->pc = 0x80198148u;
    ctx->downcount -= 4;
    // 80198148: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019814C:
    ctx->pc = 0x8019814Cu;
    // 8019814C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198150:
    ctx->pc = 0x80198150u;
    // 80198150: rlwinm r0, r0, 29, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 29u) & 0x00000001u;
    }

label_80198154:
    ctx->pc = 0x80198154u;
    // 80198154: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198158:
    ctx->pc = 0x80198158u;
    ctx->downcount -= 4;
    // 80198158: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019815C:
    ctx->pc = 0x8019815Cu;
    // 8019815C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198160:
    ctx->pc = 0x80198160u;
    // 80198160: rlwinm r0, r0, 28, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000001u;
    }

label_80198164:
    ctx->pc = 0x80198164u;
    // 80198164: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198168:
    ctx->pc = 0x80198168u;
    ctx->downcount -= 4;
    // 80198168: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019816C:
    ctx->pc = 0x8019816Cu;
    // 8019816C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198170:
    ctx->pc = 0x80198170u;
    // 80198170: rlwinm r0, r0, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x00000001u;
    }

label_80198174:
    ctx->pc = 0x80198174u;
    // 80198174: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198178:
    ctx->pc = 0x80198178u;
    ctx->downcount -= 4;
    // 80198178: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019817C:
    ctx->pc = 0x8019817Cu;
    // 8019817C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198180:
    ctx->pc = 0x80198180u;
    // 80198180: rlwinm r0, r0, 26, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000001u;
    }

label_80198184:
    ctx->pc = 0x80198184u;
    // 80198184: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198188:
    ctx->pc = 0x80198188u;
    ctx->downcount -= 4;
    // 80198188: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019818C:
    ctx->pc = 0x8019818Cu;
    // 8019818C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198190:
    ctx->pc = 0x80198190u;
    // 80198190: rlwinm r0, r0, 25, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 25u) & 0x00000001u;
    }

label_80198194:
    ctx->pc = 0x80198194u;
    // 80198194: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198198:
    ctx->pc = 0x80198198u;
    ctx->downcount -= 4;
    // 80198198: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019819C:
    ctx->pc = 0x8019819Cu;
    // 8019819C: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801981A0:
    ctx->pc = 0x801981A0u;
    // 801981A0: rlwinm r0, r0, 24, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00000001u;
    }

label_801981A4:
    ctx->pc = 0x801981A4u;
    // 801981A4: b       0x801982A4
    {
            goto label_801982A4;
    }

label_801981A8:
    ctx->pc = 0x801981A8u;
    ctx->downcount -= 4;
    // 801981A8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801981AC:
    ctx->pc = 0x801981ACu;
    // 801981AC: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801981B0:
    ctx->pc = 0x801981B0u;
    // 801981B0: rlwinm r0, r0, 23, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000003u;
    }

label_801981B4:
    ctx->pc = 0x801981B4u;
    // 801981B4: b       0x801982A4
    {
            goto label_801982A4;
    }

label_801981B8:
    ctx->pc = 0x801981B8u;
    ctx->downcount -= 4;
    // 801981B8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801981BC:
    ctx->pc = 0x801981BCu;
    // 801981BC: lbz     r0, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801981C0:
    ctx->pc = 0x801981C0u;
    // 801981C0: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801981C4:
    ctx->pc = 0x801981C4u;
    // 801981C4: bc    12, 2, 0x801981D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801981D4;
        }
    }

label_801981C8:
    ctx->pc = 0x801981C8u;
    ctx->downcount -= 3;
    // 801981C8: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801981CC:
    ctx->pc = 0x801981CCu;
    // 801981CC: rlwinm r0, r0, 21, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0x00000003u;
    }

label_801981D0:
    ctx->pc = 0x801981D0u;
    // 801981D0: b       0x801982A4
    {
            goto label_801982A4;
    }

label_801981D4:
    ctx->pc = 0x801981D4u;
    ctx->downcount -= 2;
    // 801981D4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801981D8:
    ctx->pc = 0x801981D8u;
    // 801981D8: b       0x801982A4
    {
            goto label_801982A4;
    }

label_801981DC:
    ctx->pc = 0x801981DCu;
    ctx->downcount -= 4;
    // 801981DC: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801981E0:
    ctx->pc = 0x801981E0u;
    // 801981E0: lbz     r0, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801981E4:
    ctx->pc = 0x801981E4u;
    // 801981E4: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801981E8:
    ctx->pc = 0x801981E8u;
    // 801981E8: bc    12, 2, 0x801981F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801981F8;
        }
    }

label_801981EC:
    ctx->pc = 0x801981ECu;
    ctx->downcount -= 3;
    // 801981EC: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801981F0:
    ctx->pc = 0x801981F0u;
    // 801981F0: rlwinm r0, r0, 21, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0x00000003u;
    }

label_801981F4:
    ctx->pc = 0x801981F4u;
    // 801981F4: b       0x801982A4
    {
            goto label_801982A4;
    }

label_801981F8:
    ctx->pc = 0x801981F8u;
    ctx->downcount -= 2;
    // 801981F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801981FC:
    ctx->pc = 0x801981FCu;
    // 801981FC: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198200:
    ctx->pc = 0x80198200u;
    ctx->downcount -= 4;
    // 80198200: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198204:
    ctx->pc = 0x80198204u;
    // 80198204: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198208:
    ctx->pc = 0x80198208u;
    // 80198208: rlwinm r0, r0, 19, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 19u) & 0x00000003u;
    }

label_8019820C:
    ctx->pc = 0x8019820Cu;
    // 8019820C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198210:
    ctx->pc = 0x80198210u;
    ctx->downcount -= 4;
    // 80198210: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198214:
    ctx->pc = 0x80198214u;
    // 80198214: lwz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198218:
    ctx->pc = 0x80198218u;
    // 80198218: rlwinm r0, r0, 17, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x00000003u;
    }

label_8019821C:
    ctx->pc = 0x8019821Cu;
    // 8019821C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198220:
    ctx->pc = 0x80198220u;
    ctx->downcount -= 4;
    // 80198220: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198224:
    ctx->pc = 0x80198224u;
    // 80198224: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198228:
    ctx->pc = 0x80198228u;
    // 80198228: rlwinm r0, r0, 0, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000003u;
    }

label_8019822C:
    ctx->pc = 0x8019822Cu;
    // 8019822C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198230:
    ctx->pc = 0x80198230u;
    ctx->downcount -= 4;
    // 80198230: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198234:
    ctx->pc = 0x80198234u;
    // 80198234: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198238:
    ctx->pc = 0x80198238u;
    // 80198238: rlwinm r0, r0, 30, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x00000003u;
    }

label_8019823C:
    ctx->pc = 0x8019823Cu;
    // 8019823C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198240:
    ctx->pc = 0x80198240u;
    ctx->downcount -= 4;
    // 80198240: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198244:
    ctx->pc = 0x80198244u;
    // 80198244: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198248:
    ctx->pc = 0x80198248u;
    // 80198248: rlwinm r0, r0, 28, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x00000003u;
    }

label_8019824C:
    ctx->pc = 0x8019824Cu;
    // 8019824C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198250:
    ctx->pc = 0x80198250u;
    ctx->downcount -= 4;
    // 80198250: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198254:
    ctx->pc = 0x80198254u;
    // 80198254: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198258:
    ctx->pc = 0x80198258u;
    // 80198258: rlwinm r0, r0, 26, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000003u;
    }

label_8019825C:
    ctx->pc = 0x8019825Cu;
    // 8019825C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198260:
    ctx->pc = 0x80198260u;
    ctx->downcount -= 4;
    // 80198260: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198264:
    ctx->pc = 0x80198264u;
    // 80198264: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198268:
    ctx->pc = 0x80198268u;
    // 80198268: rlwinm r0, r0, 24, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x00000003u;
    }

label_8019826C:
    ctx->pc = 0x8019826Cu;
    // 8019826C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198270:
    ctx->pc = 0x80198270u;
    ctx->downcount -= 4;
    // 80198270: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198274:
    ctx->pc = 0x80198274u;
    // 80198274: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198278:
    ctx->pc = 0x80198278u;
    // 80198278: rlwinm r0, r0, 22, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x00000003u;
    }

label_8019827C:
    ctx->pc = 0x8019827Cu;
    // 8019827C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198280:
    ctx->pc = 0x80198280u;
    ctx->downcount -= 4;
    // 80198280: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198284:
    ctx->pc = 0x80198284u;
    // 80198284: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198288:
    ctx->pc = 0x80198288u;
    // 80198288: rlwinm r0, r0, 20, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 20u) & 0x00000003u;
    }

label_8019828C:
    ctx->pc = 0x8019828Cu;
    // 8019828C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_80198290:
    ctx->pc = 0x80198290u;
    ctx->downcount -= 4;
    // 80198290: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198294:
    ctx->pc = 0x80198294u;
    // 80198294: lwz     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198298:
    ctx->pc = 0x80198298u;
    // 80198298: rlwinm r0, r0, 18, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0x00000003u;
    }

label_8019829C:
    ctx->pc = 0x8019829Cu;
    // 8019829C: b       0x801982A4
    {
            goto label_801982A4;
    }

label_801982A0:
    ctx->pc = 0x801982A0u;
    ctx->downcount -= 1;
    // 801982A0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801982A4:
    ctx->pc = 0x801982A4u;
    ctx->downcount -= 2;
    // 801982A4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801982A8:
    ctx->pc = 0x801982A8u;
    // 801982A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801982AC:
    ctx->pc = 0x801982ACu;
    ctx->downcount -= 9;
    // 801982AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801982B0:
    ctx->pc = 0x801982B0u;
    // 801982B0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801982B4:
    ctx->pc = 0x801982B4u;
    // 801982B4: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801982B8:
    ctx->pc = 0x801982B8u;
    // 801982B8: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801982BC:
    ctx->pc = 0x801982BCu;
    // 801982BC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801982C0:
    ctx->pc = 0x801982C0u;
    // 801982C0: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801982C4:
    ctx->pc = 0x801982C4u;
    // 801982C4: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801982C8:
    ctx->pc = 0x801982C8u;
    // 801982C8: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_801982CC:
    ctx->pc = 0x801982CCu;
    // 801982CC: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_801982D0:
    ctx->downcount -= 5;
    // 801982D0: add   r4, r29, r31
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[31];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_801982D4:
    ctx->pc = 0x801982D4u;
    // 801982D4: stw     r30, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801982D8:
    // 801982D8: addi    r3, r30, 0
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(0);

label_801982DC:
    // 801982DC: addi    r4, r4, 4
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(4);

label_801982E0:
    // 801982E0: bl      0x801980F8
    {
            ctx->lr = 0x801982E4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801980F8u;
                return;
            }
            goto label_801980F8;
    }

label_801982E4:
    ctx->downcount -= 4;
    // 801982E4: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_801982E8:
    // 801982E8: cmpwi   r30, 26
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(26);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801982EC:
    // 801982EC: addi    r31, r31, 8
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(8);

label_801982F0:
    // 801982F0: bc    12, 0, 0x801982D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801982D0u;
                return;
            }
            goto label_801982D0;
        }
    }

label_801982F4:
    ctx->pc = 0x801982F4u;
    ctx->downcount -= 11;
    // 801982F4: rlwinm r0, r30, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 3u) & 0xFFFFFFF8u;
    }

label_801982F8:
    ctx->pc = 0x801982F8u;
    // 801982F8: li      r3, 255
    ctx->gpr[3] = (u32)(s32)(255);

label_801982FC:
    ctx->pc = 0x801982FCu;
    // 801982FC: stwx    r3, r29, r0
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[0];
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80198300:
    ctx->pc = 0x80198300u;
    // 80198300: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198304:
    ctx->pc = 0x80198304u;
    // 80198304: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80198308:
    ctx->pc = 0x80198308u;
    // 80198308: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8019830C:
    ctx->pc = 0x8019830Cu;
    // 8019830C: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80198310:
    ctx->pc = 0x80198310u;
    // 80198310: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80198314:
    ctx->pc = 0x80198314u;
    // 80198314: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80198318:
    ctx->pc = 0x80198318u;
    // 80198318: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019831C:
    ctx->pc = 0x8019831Cu;
    ctx->downcount -= 19;
    // 8019831C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198320:
    ctx->pc = 0x80198320u;
    // 80198320: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80198324:
    ctx->pc = 0x80198324u;
    // 80198324: stw     r4, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198328:
    ctx->pc = 0x80198328u;
    // 80198328: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019832C:
    ctx->pc = 0x8019832Cu;
    // 8019832C: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80198330:
    ctx->pc = 0x80198330u;
    // 80198330: rlwinm r0, r0, 0, 23, 20
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF9FFu;
    }

label_80198334:
    ctx->pc = 0x80198334u;
    // 80198334: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_80198338:
    ctx->pc = 0x80198338u;
    // 80198338: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019833C:
    ctx->pc = 0x8019833Cu;
    // 8019833C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198340:
    ctx->pc = 0x80198340u;
    // 80198340: stw     r4, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198344:
    ctx->pc = 0x80198344u;
    // 80198344: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198348:
    ctx->pc = 0x80198348u;
    // 80198348: stb     r4, 1052(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1052);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019834C:
    ctx->pc = 0x8019834Cu;
    // 8019834C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198350:
    ctx->pc = 0x80198350u;
    // 80198350: stb     r4, 1053(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1053);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80198354:
    ctx->pc = 0x80198354u;
    // 80198354: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198358:
    ctx->pc = 0x80198358u;
    // 80198358: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019835C:
    ctx->pc = 0x8019835Cu;
    // 8019835C: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80198360:
    ctx->pc = 0x80198360u;
    // 80198360: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198364:
    ctx->pc = 0x80198364u;
    // 80198364: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198368:
    ctx->pc = 0x80198368u;
    ctx->downcount -= 9;
    // 80198368: addi    r0, r4, -9
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-9);

label_8019836C:
    ctx->pc = 0x8019836Cu;
    // 8019836C: lwz     r8, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80198370:
    ctx->pc = 0x80198370u;
    // 80198370: rlwinm r4, r3, 2, 0, 29
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80198374:
    ctx->pc = 0x80198374u;
    // 80198374: add   r9, r8, r4
    {
        u32 a = ctx->gpr[8];
        u32 b = ctx->gpr[4];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_80198378:
    ctx->pc = 0x80198378u;
    // 80198378: cmplwi  r0, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019837C:
    ctx->pc = 0x8019837Cu;
    // 8019837C: addi    r4, r9, 28
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(28);

label_80198380:
    ctx->pc = 0x80198380u;
    // 80198380: addi    r8, r9, 60
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(60);

label_80198384:
    ctx->pc = 0x80198384u;
    // 80198384: addi    r9, r9, 92
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(92);

label_80198388:
    ctx->pc = 0x80198388u;
    // 80198388: bc    12, 1, 0x80198690
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198690;
        }
    }

label_8019838C:
    ctx->pc = 0x8019838Cu;
    ctx->downcount -= 7;
    // 8019838C: lis     r10, -32732
    ctx->gpr[10] = ((u32)(s32)(-32732) << 16);

label_80198390:
    ctx->pc = 0x80198390u;
    // 80198390: addi    r10, r10, -3920
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(-3920);

label_80198394:
    ctx->pc = 0x80198394u;
    // 80198394: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80198398:
    ctx->pc = 0x80198398u;
    // 80198398: lwzx    r0, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019839C:
    ctx->pc = 0x8019839Cu;
    // 8019839C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_801983A0:
    ctx->pc = 0x801983A0u;
    // 801983A0: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_801983A4:
    ctx->pc = 0x801983A4u;
    ctx->downcount -= 15;
    // 801983A4: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801983A8:
    ctx->pc = 0x801983A8u;
    // 801983A8: rlwinm r6, r6, 1, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_801983AC:
    ctx->pc = 0x801983ACu;
    // 801983AC: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_801983B0:
    ctx->pc = 0x801983B0u;
    // 801983B0: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_801983B4:
    ctx->pc = 0x801983B4u;
    // 801983B4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801983B8:
    ctx->pc = 0x801983B8u;
    // 801983B8: rlwinm r0, r7, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0x00000FF0u;
    }

label_801983BC:
    ctx->pc = 0x801983BCu;
    // 801983BC: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801983C0:
    ctx->pc = 0x801983C0u;
    // 801983C0: rlwinm r5, r5, 0, 31, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF1u;
    }

label_801983C4:
    ctx->pc = 0x801983C4u;
    // 801983C4: or   r5, r5, r6
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[6];
    }

label_801983C8:
    ctx->pc = 0x801983C8u;
    // 801983C8: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801983CC:
    ctx->pc = 0x801983CCu;
    // 801983CC: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801983D0:
    ctx->pc = 0x801983D0u;
    // 801983D0: rlwinm r5, r5, 0, 28, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFE0Fu;
    }

label_801983D4:
    ctx->pc = 0x801983D4u;
    // 801983D4: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_801983D8:
    ctx->pc = 0x801983D8u;
    // 801983D8: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801983DC:
    ctx->pc = 0x801983DCu;
    // 801983DC: b       0x80198690
    {
            goto label_80198690;
    }

label_801983E0:
    ctx->pc = 0x801983E0u;
    ctx->downcount -= 7;
    // 801983E0: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801983E4:
    ctx->pc = 0x801983E4u;
    // 801983E4: rlwinm r0, r6, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_801983E8:
    ctx->pc = 0x801983E8u;
    // 801983E8: cmpwi   r5, 2
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801983EC:
    ctx->pc = 0x801983ECu;
    // 801983EC: rlwinm r6, r7, 0, 22, 18
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_801983F0:
    ctx->pc = 0x801983F0u;
    // 801983F0: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_801983F4:
    ctx->pc = 0x801983F4u;
    // 801983F4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801983F8:
    ctx->pc = 0x801983F8u;
    // 801983F8: bc    4, 2, 0x80198420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198420;
        }
    }

label_801983FC:
    ctx->pc = 0x801983FCu;
    ctx->downcount -= 9;
    // 801983FC: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198400:
    ctx->pc = 0x80198400u;
    // 80198400: rlwinm r0, r0, 0, 23, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFDFFu;
    }

label_80198404:
    ctx->pc = 0x80198404u;
    // 80198404: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_80198408:
    ctx->pc = 0x80198408u;
    // 80198408: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019840C:
    ctx->pc = 0x8019840Cu;
    // 8019840C: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198410:
    ctx->pc = 0x80198410u;
    // 80198410: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80198414:
    ctx->pc = 0x80198414u;
    // 80198414: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_80198418:
    ctx->pc = 0x80198418u;
    // 80198418: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019841C:
    ctx->pc = 0x8019841Cu;
    // 8019841C: b       0x80198690
    {
            goto label_80198690;
    }

label_80198420:
    ctx->pc = 0x80198420u;
    ctx->downcount -= 9;
    // 80198420: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80198424:
    ctx->pc = 0x80198424u;
    // 80198424: rlwinm r0, r5, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 9u) & 0xFFFFFE00u;
    }

label_80198428:
    ctx->pc = 0x80198428u;
    // 80198428: rlwinm r5, r6, 0, 23, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFDFFu;
    }

label_8019842C:
    ctx->pc = 0x8019842Cu;
    // 8019842C: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80198430:
    ctx->pc = 0x80198430u;
    // 80198430: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198434:
    ctx->pc = 0x80198434u;
    // 80198434: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198438:
    ctx->pc = 0x80198438u;
    // 80198438: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_8019843C:
    ctx->pc = 0x8019843Cu;
    // 8019843C: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198440:
    ctx->pc = 0x80198440u;
    // 80198440: b       0x80198690
    {
            goto label_80198690;
    }

label_80198444:
    ctx->pc = 0x80198444u;
    ctx->downcount -= 11;
    // 80198444: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80198448:
    ctx->pc = 0x80198448u;
    // 80198448: rlwinm r5, r5, 13, 0, 18
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 13u) & 0xFFFFE000u;
    }

label_8019844C:
    ctx->pc = 0x8019844Cu;
    // 8019844C: rlwinm r0, r6, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 14u) & 0xFFFFC000u;
    }

label_80198450:
    ctx->pc = 0x80198450u;
    // 80198450: rlwinm r6, r7, 0, 19, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFDFFFu;
    }

label_80198454:
    ctx->pc = 0x80198454u;
    // 80198454: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80198458:
    ctx->pc = 0x80198458u;
    // 80198458: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8019845C:
    ctx->pc = 0x8019845Cu;
    // 8019845C: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80198460:
    ctx->pc = 0x80198460u;
    // 80198460: rlwinm r5, r5, 0, 18, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFE3FFFu;
    }

label_80198464:
    ctx->pc = 0x80198464u;
    // 80198464: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80198468:
    ctx->pc = 0x80198468u;
    // 80198468: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019846C:
    ctx->pc = 0x8019846Cu;
    // 8019846C: b       0x80198690
    {
            goto label_80198690;
    }

label_80198470:
    ctx->pc = 0x80198470u;
    ctx->downcount -= 11;
    // 80198470: lwz     r7, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80198474:
    ctx->pc = 0x80198474u;
    // 80198474: rlwinm r5, r5, 17, 0, 14
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 17u) & 0xFFFE0000u;
    }

label_80198478:
    ctx->pc = 0x80198478u;
    // 80198478: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_8019847C:
    ctx->pc = 0x8019847Cu;
    // 8019847C: rlwinm r6, r7, 0, 15, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFDFFFFu;
    }

label_80198480:
    ctx->pc = 0x80198480u;
    // 80198480: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_80198484:
    ctx->pc = 0x80198484u;
    // 80198484: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80198488:
    ctx->pc = 0x80198488u;
    // 80198488: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019848C:
    ctx->pc = 0x8019848Cu;
    // 8019848C: rlwinm r5, r5, 0, 14, 10
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFE3FFFFu;
    }

label_80198490:
    ctx->pc = 0x80198490u;
    // 80198490: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_80198494:
    ctx->pc = 0x80198494u;
    // 80198494: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198498:
    ctx->pc = 0x80198498u;
    // 80198498: b       0x80198690
    {
            goto label_80198690;
    }

label_8019849C:
    ctx->pc = 0x8019849Cu;
    ctx->downcount -= 16;
    // 8019849C: lwz     r8, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_801984A0:
    ctx->pc = 0x801984A0u;
    // 801984A0: rlwinm r0, r5, 21, 0, 10
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 21u) & 0xFFE00000u;
    }

label_801984A4:
    ctx->pc = 0x801984A4u;
    // 801984A4: rlwinm r5, r8, 0, 11, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFDFFFFFu;
    }

label_801984A8:
    ctx->pc = 0x801984A8u;
    // 801984A8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_801984AC:
    ctx->pc = 0x801984ACu;
    // 801984AC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801984B0:
    ctx->pc = 0x801984B0u;
    // 801984B0: rlwinm r5, r6, 22, 0, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0xFFC00000u;
    }

label_801984B4:
    ctx->pc = 0x801984B4u;
    // 801984B4: rlwinm r0, r7, 25, 0, 6
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 25u) & 0xFE000000u;
    }

label_801984B8:
    ctx->pc = 0x801984B8u;
    // 801984B8: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801984BC:
    ctx->pc = 0x801984BCu;
    // 801984BC: rlwinm r6, r6, 0, 10, 6
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFE3FFFFFu;
    }

label_801984C0:
    ctx->pc = 0x801984C0u;
    // 801984C0: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_801984C4:
    ctx->pc = 0x801984C4u;
    // 801984C4: stw     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801984C8:
    ctx->pc = 0x801984C8u;
    // 801984C8: lwz     r5, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801984CC:
    ctx->pc = 0x801984CCu;
    // 801984CC: rlwinm r5, r5, 0, 7, 1
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xC1FFFFFFu;
    }

label_801984D0:
    ctx->pc = 0x801984D0u;
    // 801984D0: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_801984D4:
    ctx->pc = 0x801984D4u;
    // 801984D4: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801984D8:
    ctx->pc = 0x801984D8u;
    // 801984D8: b       0x80198690
    {
            goto label_80198690;
    }

label_801984DC:
    ctx->pc = 0x801984DCu;
    ctx->downcount -= 15;
    // 801984DC: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801984E0:
    ctx->pc = 0x801984E0u;
    // 801984E0: rlwinm r4, r6, 1, 0, 30
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_801984E4:
    ctx->pc = 0x801984E4u;
    // 801984E4: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_801984E8:
    ctx->pc = 0x801984E8u;
    // 801984E8: or   r0, r0, r5
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[5];
    }

label_801984EC:
    ctx->pc = 0x801984ECu;
    // 801984EC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801984F0:
    ctx->pc = 0x801984F0u;
    // 801984F0: rlwinm r0, r7, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0x00000FF0u;
    }

label_801984F4:
    ctx->pc = 0x801984F4u;
    // 801984F4: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801984F8:
    ctx->pc = 0x801984F8u;
    // 801984F8: rlwinm r5, r5, 0, 31, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF1u;
    }

label_801984FC:
    ctx->pc = 0x801984FCu;
    // 801984FC: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80198500:
    ctx->pc = 0x80198500u;
    // 80198500: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198504:
    ctx->pc = 0x80198504u;
    // 80198504: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198508:
    ctx->pc = 0x80198508u;
    // 80198508: rlwinm r4, r4, 0, 28, 22
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFE0Fu;
    }

label_8019850C:
    ctx->pc = 0x8019850Cu;
    // 8019850C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198510:
    ctx->pc = 0x80198510u;
    // 80198510: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198514:
    ctx->pc = 0x80198514u;
    // 80198514: b       0x80198690
    {
            goto label_80198690;
    }

label_80198518:
    ctx->pc = 0x80198518u;
    ctx->downcount -= 16;
    // 80198518: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019851C:
    ctx->pc = 0x8019851Cu;
    // 8019851C: rlwinm r0, r5, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 9u) & 0xFFFFFE00u;
    }

label_80198520:
    ctx->pc = 0x80198520u;
    // 80198520: rlwinm r4, r4, 0, 23, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFDFFu;
    }

label_80198524:
    ctx->pc = 0x80198524u;
    // 80198524: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198528:
    ctx->pc = 0x80198528u;
    // 80198528: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019852C:
    ctx->pc = 0x8019852Cu;
    // 8019852C: rlwinm r4, r6, 10, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_80198530:
    ctx->pc = 0x80198530u;
    // 80198530: rlwinm r0, r7, 13, 11, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 13u) & 0x001FE000u;
    }

label_80198534:
    ctx->pc = 0x80198534u;
    // 80198534: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80198538:
    ctx->pc = 0x80198538u;
    // 80198538: rlwinm r5, r5, 0, 22, 18
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFE3FFu;
    }

label_8019853C:
    ctx->pc = 0x8019853Cu;
    // 8019853C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80198540:
    ctx->pc = 0x80198540u;
    // 80198540: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198544:
    ctx->pc = 0x80198544u;
    // 80198544: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198548:
    ctx->pc = 0x80198548u;
    // 80198548: rlwinm r4, r4, 0, 19, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC1FFFu;
    }

label_8019854C:
    ctx->pc = 0x8019854Cu;
    // 8019854C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198550:
    ctx->pc = 0x80198550u;
    // 80198550: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198554:
    ctx->pc = 0x80198554u;
    // 80198554: b       0x80198690
    {
            goto label_80198690;
    }

label_80198558:
    ctx->pc = 0x80198558u;
    ctx->downcount -= 16;
    // 80198558: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019855C:
    ctx->pc = 0x8019855Cu;
    // 8019855C: rlwinm r0, r5, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 18u) & 0xFFFC0000u;
    }

label_80198560:
    ctx->pc = 0x80198560u;
    // 80198560: rlwinm r4, r4, 0, 14, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFBFFFFu;
    }

label_80198564:
    ctx->pc = 0x80198564u;
    // 80198564: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198568:
    ctx->pc = 0x80198568u;
    // 80198568: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019856C:
    ctx->pc = 0x8019856Cu;
    // 8019856C: rlwinm r4, r6, 19, 0, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 19u) & 0xFFF80000u;
    }

label_80198570:
    ctx->pc = 0x80198570u;
    // 80198570: rlwinm r0, r7, 22, 2, 9
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 22u) & 0x3FC00000u;
    }

label_80198574:
    ctx->pc = 0x80198574u;
    // 80198574: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80198578:
    ctx->pc = 0x80198578u;
    // 80198578: rlwinm r5, r5, 0, 13, 9
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFC7FFFFu;
    }

label_8019857C:
    ctx->pc = 0x8019857Cu;
    // 8019857C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80198580:
    ctx->pc = 0x80198580u;
    // 80198580: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198584:
    ctx->pc = 0x80198584u;
    // 80198584: lwz     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198588:
    ctx->pc = 0x80198588u;
    // 80198588: rlwinm r4, r4, 0, 10, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xF83FFFFFu;
    }

label_8019858C:
    ctx->pc = 0x8019858Cu;
    // 8019858C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198590:
    ctx->pc = 0x80198590u;
    // 80198590: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198594:
    ctx->pc = 0x80198594u;
    // 80198594: b       0x80198690
    {
            goto label_80198690;
    }

label_80198598:
    ctx->pc = 0x80198598u;
    ctx->downcount -= 16;
    // 80198598: lwz     r10, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8019859C:
    ctx->pc = 0x8019859Cu;
    // 8019859C: rlwinm r0, r5, 27, 0, 4
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 27u) & 0xF8000000u;
    }

label_801985A0:
    ctx->pc = 0x801985A0u;
    // 801985A0: rlwinm r4, r6, 28, 0, 3
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0xF0000000u;
    }

label_801985A4:
    ctx->pc = 0x801985A4u;
    // 801985A4: rlwinm r5, r10, 0, 5, 3
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[10], 0u) & 0xF7FFFFFFu;
    }

label_801985A8:
    ctx->pc = 0x801985A8u;
    // 801985A8: or   r0, r5, r0
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[0];
    }

label_801985AC:
    ctx->pc = 0x801985ACu;
    // 801985AC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801985B0:
    ctx->pc = 0x801985B0u;
    // 801985B0: rlwinm r0, r7, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x000000FFu;
    }

label_801985B4:
    ctx->pc = 0x801985B4u;
    // 801985B4: lwz     r5, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801985B8:
    ctx->pc = 0x801985B8u;
    // 801985B8: rlwinm r5, r5, 0, 4, 0
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x8FFFFFFFu;
    }

label_801985BC:
    ctx->pc = 0x801985BCu;
    // 801985BC: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_801985C0:
    ctx->pc = 0x801985C0u;
    // 801985C0: stw     r4, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_801985C4:
    ctx->pc = 0x801985C4u;
    // 801985C4: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801985C8:
    ctx->pc = 0x801985C8u;
    // 801985C8: rlwinm r4, r4, 0, 0, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFE0u;
    }

label_801985CC:
    ctx->pc = 0x801985CCu;
    // 801985CC: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801985D0:
    ctx->pc = 0x801985D0u;
    // 801985D0: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801985D4:
    ctx->pc = 0x801985D4u;
    // 801985D4: b       0x80198690
    {
            goto label_80198690;
    }

label_801985D8:
    ctx->pc = 0x801985D8u;
    ctx->downcount -= 16;
    // 801985D8: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801985DC:
    ctx->pc = 0x801985DCu;
    // 801985DC: rlwinm r0, r5, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 5u) & 0xFFFFFFE0u;
    }

label_801985E0:
    ctx->pc = 0x801985E0u;
    // 801985E0: rlwinm r4, r4, 0, 27, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFDFu;
    }

label_801985E4:
    ctx->pc = 0x801985E4u;
    // 801985E4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801985E8:
    ctx->pc = 0x801985E8u;
    // 801985E8: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801985EC:
    ctx->pc = 0x801985ECu;
    // 801985EC: rlwinm r4, r6, 6, 0, 25
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_801985F0:
    ctx->pc = 0x801985F0u;
    // 801985F0: rlwinm r0, r7, 9, 15, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 9u) & 0x0001FE00u;
    }

label_801985F4:
    ctx->pc = 0x801985F4u;
    // 801985F4: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_801985F8:
    ctx->pc = 0x801985F8u;
    // 801985F8: rlwinm r5, r5, 0, 26, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFE3Fu;
    }

label_801985FC:
    ctx->pc = 0x801985FCu;
    // 801985FC: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80198600:
    ctx->pc = 0x80198600u;
    // 80198600: stw     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198604:
    ctx->pc = 0x80198604u;
    // 80198604: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198608:
    ctx->pc = 0x80198608u;
    // 80198608: rlwinm r4, r4, 0, 23, 17
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFC1FFu;
    }

label_8019860C:
    ctx->pc = 0x8019860Cu;
    // 8019860C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198610:
    ctx->pc = 0x80198610u;
    // 80198610: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198614:
    ctx->pc = 0x80198614u;
    // 80198614: b       0x80198690
    {
            goto label_80198690;
    }

label_80198618:
    ctx->pc = 0x80198618u;
    ctx->downcount -= 16;
    // 80198618: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019861C:
    ctx->pc = 0x8019861Cu;
    // 8019861C: rlwinm r0, r5, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 14u) & 0xFFFFC000u;
    }

label_80198620:
    ctx->pc = 0x80198620u;
    // 80198620: rlwinm r4, r4, 0, 18, 16
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFBFFFu;
    }

label_80198624:
    ctx->pc = 0x80198624u;
    // 80198624: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198628:
    ctx->pc = 0x80198628u;
    // 80198628: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019862C:
    ctx->pc = 0x8019862Cu;
    // 8019862C: rlwinm r4, r6, 15, 0, 16
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[6], 15u) & 0xFFFF8000u;
    }

label_80198630:
    ctx->pc = 0x80198630u;
    // 80198630: rlwinm r0, r7, 18, 6, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 18u) & 0x03FC0000u;
    }

label_80198634:
    ctx->pc = 0x80198634u;
    // 80198634: lwz     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80198638:
    ctx->pc = 0x80198638u;
    // 80198638: rlwinm r5, r5, 0, 17, 13
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFC7FFFu;
    }

label_8019863C:
    ctx->pc = 0x8019863Cu;
    // 8019863C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80198640:
    ctx->pc = 0x80198640u;
    // 80198640: stw     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198644:
    ctx->pc = 0x80198644u;
    // 80198644: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198648:
    ctx->pc = 0x80198648u;
    // 80198648: rlwinm r4, r4, 0, 14, 8
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF83FFFFu;
    }

label_8019864C:
    ctx->pc = 0x8019864Cu;
    // 8019864C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198650:
    ctx->pc = 0x80198650u;
    // 80198650: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198654:
    ctx->pc = 0x80198654u;
    // 80198654: b       0x80198690
    {
            goto label_80198690;
    }

label_80198658:
    ctx->pc = 0x80198658u;
    ctx->downcount -= 14;
    // 80198658: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019865C:
    ctx->pc = 0x8019865Cu;
    // 8019865C: rlwinm r0, r5, 23, 0, 8
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 23u) & 0xFF800000u;
    }

label_80198660:
    ctx->pc = 0x80198660u;
    // 80198660: rlwinm r4, r4, 0, 9, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF7FFFFFu;
    }

label_80198664:
    ctx->pc = 0x80198664u;
    // 80198664: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198668:
    ctx->pc = 0x80198668u;
    // 80198668: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019866C:
    ctx->pc = 0x8019866Cu;
    // 8019866C: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_80198670:
    ctx->pc = 0x80198670u;
    // 80198670: lwz     r4, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198674:
    ctx->pc = 0x80198674u;
    // 80198674: rlwinm r4, r4, 0, 8, 4
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xF8FFFFFFu;
    }

label_80198678:
    ctx->pc = 0x80198678u;
    // 80198678: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_8019867C:
    ctx->pc = 0x8019867Cu;
    // 8019867C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198680:
    ctx->pc = 0x80198680u;
    // 80198680: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198684:
    ctx->pc = 0x80198684u;
    // 80198684: rlwinm r0, r0, 0, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x07FFFFFFu;
    }

label_80198688:
    ctx->pc = 0x80198688u;
    // 80198688: rlwimi r0, r7, 27, 0, 4
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 27u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xF8000000u) | (rot & 0xF8000000u);
    }

label_8019868C:
    ctx->pc = 0x8019868Cu;
    // 8019868C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198690:
    ctx->pc = 0x80198690u;
    ctx->downcount -= 13;
    // 80198690: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80198694:
    ctx->pc = 0x80198694u;
    // 80198694: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80198698:
    ctx->pc = 0x80198698u;
    // 80198698: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8019869C:
    ctx->pc = 0x8019869Cu;
    // 8019869C: lwz     r4, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801986A0:
    ctx->pc = 0x801986A0u;
    // 801986A0: slw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] << sh);
    }

label_801986A4:
    ctx->pc = 0x801986A4u;
    // 801986A4: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_801986A8:
    ctx->pc = 0x801986A8u;
    // 801986A8: ori     r3, r4, 0x0010
    ctx->gpr[3] = ctx->gpr[4] | 0x0010u;

label_801986AC:
    ctx->pc = 0x801986ACu;
    // 801986AC: stw     r3, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_801986B0:
    ctx->pc = 0x801986B0u;
    // 801986B0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801986B4:
    ctx->pc = 0x801986B4u;
    // 801986B4: lbz     r3, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_801986B8:
    ctx->pc = 0x801986B8u;
    // 801986B8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801986BC:
    ctx->pc = 0x801986BCu;
    // 801986BC: stb     r0, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801986C0:
    ctx->pc = 0x801986C0u;
    // 801986C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801986C4:
    ctx->pc = 0x801986C4u;
    ctx->downcount -= 9;
    // 801986C4: lwz     r6, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801986C8:
    ctx->pc = 0x801986C8u;
    // 801986C8: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_801986CC:
    ctx->pc = 0x801986CCu;
    // 801986CC: lis     r5, -32732
    ctx->gpr[5] = ((u32)(s32)(-32732) << 16);

label_801986D0:
    ctx->pc = 0x801986D0u;
    // 801986D0: add   r6, r6, r0
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_801986D4:
    ctx->pc = 0x801986D4u;
    // 801986D4: addi    r8, r6, 28
    ctx->gpr[8] = ctx->gpr[6] + (u32)(s32)(28);

label_801986D8:
    ctx->pc = 0x801986D8u;
    // 801986D8: addi    r9, r6, 60
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(60);

label_801986DC:
    ctx->pc = 0x801986DCu;
    // 801986DC: addi    r10, r6, 92
    ctx->gpr[10] = ctx->gpr[6] + (u32)(s32)(92);

label_801986E0:
    ctx->pc = 0x801986E0u;
    // 801986E0: addi    r5, r5, -3852
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-3852);

label_801986E4:
    ctx->pc = 0x801986E4u;
    // 801986E4: b       0x80198A00
    {
            goto label_80198A00;
    }

label_801986E8:
    ctx->pc = 0x801986E8u;
    ctx->downcount -= 7;
    // 801986E8: lwz     r6, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801986EC:
    ctx->pc = 0x801986ECu;
    // 801986EC: lbz     r7, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_801986F0:
    // 801986F0: addi    r11, r6, -9
    ctx->gpr[11] = ctx->gpr[6] + (u32)(s32)(-9);

label_801986F4:
    ctx->pc = 0x801986F4u;
    // 801986F4: lwz     r6, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801986F8:
    // 801986F8: cmplwi  r11, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[11]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801986FC:
    ctx->pc = 0x801986FCu;
    // 801986FC: lwz     r0, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198700:
    // 80198700: bc    12, 1, 0x801989FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801989FC;
        }
    }

label_80198704:
    ctx->downcount -= 5;
    // 80198704: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80198708:
    ctx->pc = 0x80198708u;
    // 80198708: lwzx    r11, r5, r11
    {
        u32 ea = ctx->gpr[5] + ctx->gpr[11];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8019870C:
    ctx->pc = 0x8019870Cu;
    // 8019870C: mtctr    r11
    ctx->ctr = ctx->gpr[11];

label_80198710:
    ctx->pc = 0x80198710u;
    // 80198710: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80198714:
    ctx->pc = 0x80198714u;
    ctx->downcount -= 15;
    // 80198714: lwz     r12, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80198718:
    // 80198718: rlwinm r11, r6, 1, 0, 30
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_8019871C:
    // 8019871C: rlwinm r6, r7, 4, 0, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_80198720:
    // 80198720: rlwinm r7, r12, 0, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFFFFFFFEu;
    }

label_80198724:
    // 80198724: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_80198728:
    ctx->pc = 0x80198728u;
    // 80198728: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019872C:
    ctx->pc = 0x8019872Cu;
    // 8019872C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198730:
    // 80198730: rlwinm r0, r0, 0, 31, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_80198734:
    // 80198734: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80198738:
    ctx->pc = 0x80198738u;
    // 80198738: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019873C:
    ctx->pc = 0x8019873Cu;
    // 8019873C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198740:
    // 80198740: rlwinm r0, r0, 0, 28, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFE0Fu;
    }

label_80198744:
    // 80198744: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_80198748:
    ctx->pc = 0x80198748u;
    // 80198748: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019874C:
    // 8019874C: b       0x801989FC
    {
            goto label_801989FC;
    }

label_80198750:
    ctx->pc = 0x80198750u;
    ctx->downcount -= 7;
    // 80198750: lwz     r7, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80198754:
    // 80198754: rlwinm r6, r6, 10, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_80198758:
    // 80198758: cmpwi   r0, 2
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

label_8019875C:
    // 8019875C: rlwinm r7, r7, 0, 22, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_80198760:
    // 80198760: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_80198764:
    ctx->pc = 0x80198764u;
    // 80198764: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80198768:
    // 80198768: bc    4, 2, 0x80198790
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198790;
        }
    }

label_8019876C:
    ctx->pc = 0x8019876Cu;
    ctx->downcount -= 9;
    // 8019876C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198770:
    // 80198770: rlwinm r0, r0, 0, 23, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFDFFu;
    }

label_80198774:
    // 80198774: ori     r0, r0, 0x0200
    ctx->gpr[0] = ctx->gpr[0] | 0x0200u;

label_80198778:
    ctx->pc = 0x80198778u;
    // 80198778: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019877C:
    ctx->pc = 0x8019877Cu;
    // 8019877C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198780:
    // 80198780: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_80198784:
    // 80198784: oris    r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | (0x8000u << 16);

label_80198788:
    ctx->pc = 0x80198788u;
    // 80198788: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019878C:
    // 8019878C: b       0x801989FC
    {
            goto label_801989FC;
    }

label_80198790:
    ctx->pc = 0x80198790u;
    ctx->downcount -= 9;
    // 80198790: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80198794:
    // 80198794: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_80198798:
    // 80198798: rlwinm r6, r6, 0, 23, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFDFFu;
    }

label_8019879C:
    // 8019879C: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_801987A0:
    ctx->pc = 0x801987A0u;
    // 801987A0: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801987A4:
    ctx->pc = 0x801987A4u;
    // 801987A4: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801987A8:
    // 801987A8: rlwinm r0, r0, 0, 1, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x7FFFFFFFu;
    }

label_801987AC:
    ctx->pc = 0x801987ACu;
    // 801987AC: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801987B0:
    // 801987B0: b       0x801989FC
    {
            goto label_801989FC;
    }

label_801987B4:
    ctx->pc = 0x801987B4u;
    ctx->downcount -= 11;
    // 801987B4: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801987B8:
    // 801987B8: rlwinm r7, r0, 13, 0, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0xFFFFE000u;
    }

label_801987BC:
    // 801987BC: rlwinm r0, r6, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 14u) & 0xFFFFC000u;
    }

label_801987C0:
    // 801987C0: rlwinm r6, r11, 0, 19, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFDFFFu;
    }

label_801987C4:
    // 801987C4: or   r6, r6, r7
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[7];
    }

label_801987C8:
    ctx->pc = 0x801987C8u;
    // 801987C8: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801987CC:
    ctx->pc = 0x801987CCu;
    // 801987CC: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801987D0:
    // 801987D0: rlwinm r6, r6, 0, 18, 14
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFE3FFFu;
    }

label_801987D4:
    // 801987D4: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_801987D8:
    ctx->pc = 0x801987D8u;
    // 801987D8: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801987DC:
    // 801987DC: b       0x801989FC
    {
            goto label_801989FC;
    }

label_801987E0:
    ctx->pc = 0x801987E0u;
    ctx->downcount -= 11;
    // 801987E0: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801987E4:
    // 801987E4: rlwinm r7, r0, 17, 0, 14
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0xFFFE0000u;
    }

label_801987E8:
    // 801987E8: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_801987EC:
    // 801987EC: rlwinm r6, r11, 0, 15, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFDFFFFu;
    }

label_801987F0:
    // 801987F0: or   r6, r6, r7
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[7];
    }

label_801987F4:
    ctx->pc = 0x801987F4u;
    // 801987F4: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801987F8:
    ctx->pc = 0x801987F8u;
    // 801987F8: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801987FC:
    // 801987FC: rlwinm r6, r6, 0, 14, 10
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFE3FFFFu;
    }

label_80198800:
    // 80198800: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80198804:
    ctx->pc = 0x80198804u;
    // 80198804: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198808:
    // 80198808: b       0x801989FC
    {
            goto label_801989FC;
    }

label_8019880C:
    ctx->pc = 0x8019880Cu;
    ctx->downcount -= 16;
    // 8019880C: lwz     r11, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80198810:
    // 80198810: rlwinm r0, r0, 21, 0, 10
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 21u) & 0xFFE00000u;
    }

label_80198814:
    // 80198814: rlwinm r6, r6, 22, 0, 9
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 22u) & 0xFFC00000u;
    }

label_80198818:
    // 80198818: rlwinm r11, r11, 0, 11, 9
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFDFFFFFu;
    }

label_8019881C:
    // 8019881C: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_80198820:
    ctx->pc = 0x80198820u;
    // 80198820: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198824:
    // 80198824: rlwinm r0, r7, 25, 0, 6
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 25u) & 0xFE000000u;
    }

label_80198828:
    ctx->pc = 0x80198828u;
    // 80198828: lwz     r7, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019882C:
    // 8019882C: rlwinm r7, r7, 0, 10, 6
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFE3FFFFFu;
    }

label_80198830:
    // 80198830: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_80198834:
    ctx->pc = 0x80198834u;
    // 80198834: stw     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80198838:
    ctx->pc = 0x80198838u;
    // 80198838: lwz     r6, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019883C:
    // 8019883C: rlwinm r6, r6, 0, 7, 1
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xC1FFFFFFu;
    }

label_80198840:
    // 80198840: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80198844:
    ctx->pc = 0x80198844u;
    // 80198844: stw     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198848:
    // 80198848: b       0x801989FC
    {
            goto label_801989FC;
    }

label_8019884C:
    ctx->pc = 0x8019884Cu;
    ctx->downcount -= 15;
    // 8019884C: lwz     r12, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80198850:
    // 80198850: rlwinm r11, r6, 1, 0, 30
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0xFFFFFFFEu;
    }

label_80198854:
    // 80198854: rlwinm r6, r7, 4, 0, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_80198858:
    // 80198858: rlwinm r7, r12, 0, 0, 30
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFFFFFFFEu;
    }

label_8019885C:
    // 8019885C: or   r0, r7, r0
    {
        ctx->gpr[0] = ctx->gpr[7] | ctx->gpr[0];
    }

label_80198860:
    ctx->pc = 0x80198860u;
    // 80198860: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198864:
    ctx->pc = 0x80198864u;
    // 80198864: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198868:
    // 80198868: rlwinm r0, r0, 0, 31, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_8019886C:
    // 8019886C: or   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[11];
    }

label_80198870:
    ctx->pc = 0x80198870u;
    // 80198870: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198874:
    ctx->pc = 0x80198874u;
    // 80198874: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198878:
    // 80198878: rlwinm r0, r0, 0, 28, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFE0Fu;
    }

label_8019887C:
    // 8019887C: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_80198880:
    ctx->pc = 0x80198880u;
    // 80198880: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198884:
    // 80198884: b       0x801989FC
    {
            goto label_801989FC;
    }

label_80198888:
    ctx->pc = 0x80198888u;
    ctx->downcount -= 16;
    // 80198888: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8019888C:
    // 8019888C: rlwinm r0, r0, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0xFFFFFE00u;
    }

label_80198890:
    // 80198890: rlwinm r6, r6, 10, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 10u) & 0xFFFFFC00u;
    }

label_80198894:
    // 80198894: rlwinm r11, r11, 0, 23, 21
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFFDFFu;
    }

label_80198898:
    // 80198898: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_8019889C:
    ctx->pc = 0x8019889Cu;
    // 8019889C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801988A0:
    // 801988A0: rlwinm r0, r7, 13, 0, 18
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 13u) & 0xFFFFE000u;
    }

label_801988A4:
    ctx->pc = 0x801988A4u;
    // 801988A4: lwz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801988A8:
    // 801988A8: rlwinm r7, r7, 0, 22, 18
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFE3FFu;
    }

label_801988AC:
    // 801988AC: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_801988B0:
    ctx->pc = 0x801988B0u;
    // 801988B0: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801988B4:
    ctx->pc = 0x801988B4u;
    // 801988B4: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801988B8:
    // 801988B8: rlwinm r6, r6, 0, 19, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFC1FFFu;
    }

label_801988BC:
    // 801988BC: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_801988C0:
    ctx->pc = 0x801988C0u;
    // 801988C0: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801988C4:
    // 801988C4: b       0x801989FC
    {
            goto label_801989FC;
    }

label_801988C8:
    ctx->pc = 0x801988C8u;
    ctx->downcount -= 16;
    // 801988C8: lwz     r11, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_801988CC:
    // 801988CC: rlwinm r0, r0, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0xFFFC0000u;
    }

label_801988D0:
    // 801988D0: rlwinm r6, r6, 19, 0, 12
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 19u) & 0xFFF80000u;
    }

label_801988D4:
    // 801988D4: rlwinm r11, r11, 0, 14, 12
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFBFFFFu;
    }

label_801988D8:
    // 801988D8: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_801988DC:
    ctx->pc = 0x801988DCu;
    // 801988DC: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801988E0:
    // 801988E0: rlwinm r0, r7, 22, 0, 9
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 22u) & 0xFFC00000u;
    }

label_801988E4:
    ctx->pc = 0x801988E4u;
    // 801988E4: lwz     r7, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801988E8:
    // 801988E8: rlwinm r7, r7, 0, 13, 9
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFC7FFFFu;
    }

label_801988EC:
    // 801988EC: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_801988F0:
    ctx->pc = 0x801988F0u;
    // 801988F0: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801988F4:
    ctx->pc = 0x801988F4u;
    // 801988F4: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801988F8:
    // 801988F8: rlwinm r6, r6, 0, 10, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xF83FFFFFu;
    }

label_801988FC:
    // 801988FC: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80198900:
    ctx->pc = 0x80198900u;
    // 80198900: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198904:
    // 80198904: b       0x801989FC
    {
            goto label_801989FC;
    }

label_80198908:
    ctx->pc = 0x80198908u;
    ctx->downcount -= 15;
    // 80198908: lwz     r12, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8019890C:
    // 8019890C: rlwinm r11, r0, 27, 0, 4
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0xF8000000u;
    }

label_80198910:
    // 80198910: rlwinm r0, r6, 28, 0, 3
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 28u) & 0xF0000000u;
    }

label_80198914:
    // 80198914: rlwinm r6, r12, 0, 5, 3
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xF7FFFFFFu;
    }

label_80198918:
    // 80198918: or   r6, r6, r11
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[11];
    }

label_8019891C:
    ctx->pc = 0x8019891Cu;
    // 8019891C: stw     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80198920:
    ctx->pc = 0x80198920u;
    // 80198920: lwz     r6, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80198924:
    // 80198924: rlwinm r6, r6, 0, 4, 0
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x8FFFFFFFu;
    }

label_80198928:
    // 80198928: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_8019892C:
    ctx->pc = 0x8019892Cu;
    // 8019892C: stw     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198930:
    ctx->pc = 0x80198930u;
    // 80198930: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198934:
    // 80198934: rlwinm r0, r0, 0, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFE0u;
    }

label_80198938:
    // 80198938: or   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[7];
    }

label_8019893C:
    ctx->pc = 0x8019893Cu;
    // 8019893C: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198940:
    // 80198940: b       0x801989FC
    {
            goto label_801989FC;
    }

label_80198944:
    ctx->pc = 0x80198944u;
    ctx->downcount -= 16;
    // 80198944: lwz     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80198948:
    // 80198948: rlwinm r0, r0, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0xFFFFFFE0u;
    }

label_8019894C:
    // 8019894C: rlwinm r6, r6, 6, 0, 25
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_80198950:
    // 80198950: rlwinm r11, r11, 0, 27, 25
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFFFDFu;
    }

label_80198954:
    // 80198954: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_80198958:
    ctx->pc = 0x80198958u;
    // 80198958: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019895C:
    // 8019895C: rlwinm r0, r7, 9, 0, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 9u) & 0xFFFFFE00u;
    }

label_80198960:
    ctx->pc = 0x80198960u;
    // 80198960: lwz     r7, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80198964:
    // 80198964: rlwinm r7, r7, 0, 26, 22
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFE3Fu;
    }

label_80198968:
    // 80198968: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_8019896C:
    ctx->pc = 0x8019896Cu;
    // 8019896C: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80198970:
    ctx->pc = 0x80198970u;
    // 80198970: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80198974:
    // 80198974: rlwinm r6, r6, 0, 23, 17
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFC1FFu;
    }

label_80198978:
    // 80198978: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_8019897C:
    ctx->pc = 0x8019897Cu;
    // 8019897C: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198980:
    // 80198980: b       0x801989FC
    {
            goto label_801989FC;
    }

label_80198984:
    ctx->pc = 0x80198984u;
    ctx->downcount -= 16;
    // 80198984: lwz     r11, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80198988:
    // 80198988: rlwinm r0, r0, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0xFFFFC000u;
    }

label_8019898C:
    // 8019898C: rlwinm r6, r6, 15, 0, 16
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 15u) & 0xFFFF8000u;
    }

label_80198990:
    // 80198990: rlwinm r11, r11, 0, 18, 16
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0xFFFFBFFFu;
    }

label_80198994:
    // 80198994: or   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[0];
    }

label_80198998:
    ctx->pc = 0x80198998u;
    // 80198998: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019899C:
    // 8019899C: rlwinm r0, r7, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 18u) & 0xFFFC0000u;
    }

label_801989A0:
    ctx->pc = 0x801989A0u;
    // 801989A0: lwz     r7, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801989A4:
    // 801989A4: rlwinm r7, r7, 0, 17, 13
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFC7FFFu;
    }

label_801989A8:
    // 801989A8: or   r6, r7, r6
    {
        ctx->gpr[6] = ctx->gpr[7] | ctx->gpr[6];
    }

label_801989AC:
    ctx->pc = 0x801989ACu;
    // 801989AC: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801989B0:
    ctx->pc = 0x801989B0u;
    // 801989B0: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801989B4:
    // 801989B4: rlwinm r6, r6, 0, 14, 8
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFF83FFFFu;
    }

label_801989B8:
    // 801989B8: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_801989BC:
    ctx->pc = 0x801989BCu;
    // 801989BC: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801989C0:
    // 801989C0: b       0x801989FC
    {
            goto label_801989FC;
    }

label_801989C4:
    ctx->pc = 0x801989C4u;
    ctx->downcount -= 14;
    // 801989C4: lwz     r12, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801989C8:
    // 801989C8: rlwinm r11, r0, 23, 0, 8
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0xFF800000u;
    }

label_801989CC:
    // 801989CC: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_801989D0:
    // 801989D0: rlwinm r6, r12, 0, 9, 7
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0xFF7FFFFFu;
    }

label_801989D4:
    // 801989D4: or   r6, r6, r11
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[11];
    }

label_801989D8:
    ctx->pc = 0x801989D8u;
    // 801989D8: stw     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_801989DC:
    ctx->pc = 0x801989DCu;
    // 801989DC: lwz     r6, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_801989E0:
    // 801989E0: rlwinm r6, r6, 0, 8, 4
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xF8FFFFFFu;
    }

label_801989E4:
    // 801989E4: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_801989E8:
    ctx->pc = 0x801989E8u;
    // 801989E8: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801989EC:
    ctx->pc = 0x801989ECu;
    // 801989EC: lwz     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801989F0:
    // 801989F0: rlwinm r0, r0, 0, 5, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x07FFFFFFu;
    }

label_801989F4:
    // 801989F4: rlwimi r0, r7, 27, 0, 4
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 27u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xF8000000u) | (rot & 0xF8000000u);
    }

label_801989F8:
    ctx->pc = 0x801989F8u;
    // 801989F8: stw     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801989FC:
    ctx->downcount -= 1;
    // 801989FC: addi    r4, r4, 16
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(16);

label_80198A00:
    ctx->pc = 0x80198A00u;
    ctx->downcount -= 3;
    // 80198A00: lwz     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198A04:
    // 80198A04: cmpwi   r0, 255
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(255);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198A08:
    // 80198A08: bc    4, 2, 0x801986E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801986E8u;
                return;
            }
            goto label_801986E8;
        }
    }

label_80198A0C:
    ctx->pc = 0x80198A0Cu;
    ctx->downcount -= 13;
    // 80198A0C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80198A10:
    ctx->pc = 0x80198A10u;
    // 80198A10: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80198A14:
    ctx->pc = 0x80198A14u;
    // 80198A14: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80198A18:
    ctx->pc = 0x80198A18u;
    // 80198A18: lwz     r4, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198A1C:
    ctx->pc = 0x80198A1Cu;
    // 80198A1C: slw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] << sh);
    }

label_80198A20:
    ctx->pc = 0x80198A20u;
    // 80198A20: rlwinm r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
    }

label_80198A24:
    ctx->pc = 0x80198A24u;
    // 80198A24: ori     r3, r4, 0x0010
    ctx->gpr[3] = ctx->gpr[4] | 0x0010u;

label_80198A28:
    ctx->pc = 0x80198A28u;
    // 80198A28: stw     r3, 1268(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80198A2C:
    ctx->pc = 0x80198A2Cu;
    // 80198A2C: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198A30:
    ctx->pc = 0x80198A30u;
    // 80198A30: lbz     r3, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80198A34:
    ctx->pc = 0x80198A34u;
    // 80198A34: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80198A38:
    ctx->pc = 0x80198A38u;
    // 80198A38: stb     r0, 1266(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1266);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198A3C:
    ctx->pc = 0x80198A3Cu;
    // 80198A3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198A40:
    ctx->pc = 0x80198A40u;
    ctx->downcount -= 5;
    // 80198A40: lwz     r10, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80198A44:
    ctx->pc = 0x80198A44u;
    // 80198A44: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_80198A48:
    ctx->pc = 0x80198A48u;
    // 80198A48: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80198A4C:
    ctx->pc = 0x80198A4Cu;
    // 80198A4C: lis     r7, -13311
    ctx->gpr[7] = ((u32)(s32)(-13311) << 16);

label_80198A50:
    ctx->pc = 0x80198A50u;
    // 80198A50: b       0x80198AC0
    {
            goto label_80198AC0;
    }

label_80198A54:
    ctx->downcount -= 6;
    // 80198A54: rlwinm r9, r12, 0, 24, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x000000FFu;
    }

label_80198A58:
    ctx->pc = 0x80198A58u;
    // 80198A58: lbz     r3, 1266(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(1266);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_80198A5C:
    // 80198A5C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80198A60:
    // 80198A60: slw   r0, r0, r9
    {
        u32 sh = ctx->gpr[9] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_80198A64:
    // 80198A64: and.   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80198A68:
    // 80198A68: bc    12, 2, 0x80198AB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198AB8;
        }
    }

label_80198A6C:
    ctx->downcount -= 19;
    // 80198A6C: li      r8, 8
    ctx->gpr[8] = (u32)(s32)(8);

label_80198A70:
    ctx->pc = 0x80198A70u;
    // 80198A70: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_80198A74:
    // 80198A74: ori     r3, r9, 0x0070
    ctx->gpr[3] = ctx->gpr[9] | 0x0070u;

label_80198A78:
    // 80198A78: addi    r0, r11, 28
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(28);

label_80198A7C:
    ctx->pc = 0x80198A7Cu;
    // 80198A7C: stb     r3, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80198A80:
    // 80198A80: ori     r5, r9, 0x0080
    ctx->gpr[5] = ctx->gpr[9] | 0x0080u;

label_80198A84:
    // 80198A84: addi    r4, r11, 60
    ctx->gpr[4] = ctx->gpr[11] + (u32)(s32)(60);

label_80198A88:
    ctx->pc = 0x80198A88u;
    // 80198A88: lwzx    r6, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80198A8C:
    // 80198A8C: ori     r3, r9, 0x0090
    ctx->gpr[3] = ctx->gpr[9] | 0x0090u;

label_80198A90:
    // 80198A90: addi    r0, r11, 92
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(92);

label_80198A94:
    ctx->pc = 0x80198A94u;
    // 80198A94: stw     r6, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80198A98:
    ctx->pc = 0x80198A98u;
    // 80198A98: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_80198A9C:
    ctx->pc = 0x80198A9Cu;
    // 80198A9C: stb     r5, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_80198AA0:
    ctx->pc = 0x80198AA0u;
    // 80198AA0: lwzx    r4, r10, r4
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[4];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198AA4:
    ctx->pc = 0x80198AA4u;
    // 80198AA4: stw     r4, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198AA8:
    ctx->pc = 0x80198AA8u;
    // 80198AA8: stb     r8, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[8]);
    }

label_80198AAC:
    ctx->pc = 0x80198AACu;
    // 80198AAC: stb     r3, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80198AB0:
    ctx->pc = 0x80198AB0u;
    // 80198AB0: lwzx    r0, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198AB4:
    ctx->pc = 0x80198AB4u;
    // 80198AB4: stw     r0, -32768(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198AB8:
    ctx->downcount -= 2;
    // 80198AB8: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_80198ABC:
    // 80198ABC: addi    r12, r12, 1
    ctx->gpr[12] = ctx->gpr[12] + (u32)(s32)(1);

label_80198AC0:
    ctx->downcount -= 3;
    // 80198AC0: rlwinm r0, r12, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 0u) & 0x000000FFu;
    }

label_80198AC4:
    // 80198AC4: cmplwi  r0, 0x0008
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0008u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198AC8:
    // 80198AC8: bc    12, 0, 0x80198A54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80198A54u;
                return;
            }
            goto label_80198A54;
        }
    }

label_80198ACC:
    ctx->pc = 0x80198ACCu;
    ctx->downcount -= 4;
    // 80198ACC: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198AD0:
    ctx->pc = 0x80198AD0u;
    // 80198AD0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80198AD4:
    ctx->pc = 0x80198AD4u;
    // 80198AD4: stb     r0, 1266(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1266);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198AD8:
    ctx->pc = 0x80198AD8u;
    // 80198AD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198ADC:
    ctx->pc = 0x80198ADCu;
    ctx->downcount -= 9;
    // 80198ADC: addi    r0, r4, -9
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-9);

label_80198AE0:
    ctx->pc = 0x80198AE0u;
    // 80198AE0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198AE4:
    ctx->pc = 0x80198AE4u;
    // 80198AE4: rlwinm r3, r3, 2, 0, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80198AE8:
    ctx->pc = 0x80198AE8u;
    // 80198AE8: add   r4, r4, r3
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[4] = res;
    }

label_80198AEC:
    ctx->pc = 0x80198AECu;
    // 80198AEC: cmplwi  r0, 0x0010
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0010u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198AF0:
    ctx->pc = 0x80198AF0u;
    // 80198AF0: addi    r3, r4, 28
    ctx->gpr[3] = ctx->gpr[4] + (u32)(s32)(28);

label_80198AF4:
    ctx->pc = 0x80198AF4u;
    // 80198AF4: addi    r8, r4, 60
    ctx->gpr[8] = ctx->gpr[4] + (u32)(s32)(60);

label_80198AF8:
    ctx->pc = 0x80198AF8u;
    // 80198AF8: addi    r9, r4, 92
    ctx->gpr[9] = ctx->gpr[4] + (u32)(s32)(92);

label_80198AFC:
    ctx->pc = 0x80198AFCu;
    // 80198AFC: bc    12, 1, 0x80198D0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198D0C;
        }
    }

label_80198B00:
    ctx->pc = 0x80198B00u;
    ctx->downcount -= 7;
    // 80198B00: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80198B04:
    ctx->pc = 0x80198B04u;
    // 80198B04: addi    r4, r4, -3784
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-3784);

label_80198B08:
    ctx->pc = 0x80198B08u;
    // 80198B08: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80198B0C:
    ctx->pc = 0x80198B0Cu;
    // 80198B0C: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198B10:
    ctx->pc = 0x80198B10u;
    // 80198B10: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80198B14:
    ctx->pc = 0x80198B14u;
    // 80198B14: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80198B18:
    ctx->pc = 0x80198B18u;
    ctx->downcount -= 10;
    // 80198B18: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198B1C:
    ctx->pc = 0x80198B1Cu;
    // 80198B1C: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80198B20:
    ctx->pc = 0x80198B20u;
    // 80198B20: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198B24:
    ctx->pc = 0x80198B24u;
    // 80198B24: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198B28:
    ctx->pc = 0x80198B28u;
    // 80198B28: rlwinm r0, r0, 31, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000007u;
    }

label_80198B2C:
    ctx->pc = 0x80198B2Cu;
    // 80198B2C: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198B30:
    ctx->pc = 0x80198B30u;
    // 80198B30: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198B34:
    ctx->pc = 0x80198B34u;
    // 80198B34: rlwinm r0, r0, 28, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0000001Fu;
    }

label_80198B38:
    ctx->pc = 0x80198B38u;
    // 80198B38: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198B3C:
    ctx->pc = 0x80198B3Cu;
    // 80198B3C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198B40:
    ctx->pc = 0x80198B40u;
    ctx->downcount -= 6;
    // 80198B40: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198B44:
    ctx->pc = 0x80198B44u;
    // 80198B44: rlwinm r0, r0, 23, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000001u;
    }

label_80198B48:
    ctx->pc = 0x80198B48u;
    // 80198B48: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198B4C:
    ctx->pc = 0x80198B4Cu;
    // 80198B4C: lwz     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198B50:
    ctx->pc = 0x80198B50u;
    // 80198B50: cmpwi   r0, 1
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

label_80198B54:
    ctx->pc = 0x80198B54u;
    // 80198B54: bc    4, 2, 0x80198B6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198B6C;
        }
    }

label_80198B58:
    ctx->pc = 0x80198B58u;
    ctx->downcount -= 3;
    // 80198B58: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198B5C:
    ctx->pc = 0x80198B5Cu;
    // 80198B5C: rlwinm. r0, r0, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80198B60:
    ctx->pc = 0x80198B60u;
    // 80198B60: bc    12, 2, 0x80198B6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198B6C;
        }
    }

label_80198B64:
    ctx->pc = 0x80198B64u;
    ctx->downcount -= 2;
    // 80198B64: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80198B68:
    ctx->pc = 0x80198B68u;
    // 80198B68: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198B6C:
    ctx->pc = 0x80198B6Cu;
    ctx->downcount -= 6;
    // 80198B6C: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198B70:
    ctx->pc = 0x80198B70u;
    // 80198B70: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80198B74:
    ctx->pc = 0x80198B74u;
    // 80198B74: rlwinm r3, r3, 22, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 22u) & 0x00000007u;
    }

label_80198B78:
    ctx->pc = 0x80198B78u;
    // 80198B78: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80198B7C:
    ctx->pc = 0x80198B7Cu;
    // 80198B7C: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198B80:
    ctx->pc = 0x80198B80u;
    // 80198B80: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198B84:
    ctx->pc = 0x80198B84u;
    ctx->downcount -= 9;
    // 80198B84: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198B88:
    ctx->pc = 0x80198B88u;
    // 80198B88: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80198B8C:
    ctx->pc = 0x80198B8Cu;
    // 80198B8C: rlwinm r4, r4, 19, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0x00000001u;
    }

label_80198B90:
    ctx->pc = 0x80198B90u;
    // 80198B90: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198B94:
    ctx->pc = 0x80198B94u;
    // 80198B94: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198B98:
    ctx->pc = 0x80198B98u;
    // 80198B98: rlwinm r3, r3, 18, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 18u) & 0x00000007u;
    }

label_80198B9C:
    ctx->pc = 0x80198B9Cu;
    // 80198B9C: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80198BA0:
    ctx->pc = 0x80198BA0u;
    // 80198BA0: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198BA4:
    ctx->pc = 0x80198BA4u;
    // 80198BA4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198BA8:
    ctx->pc = 0x80198BA8u;
    ctx->downcount -= 9;
    // 80198BA8: lwz     r4, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198BAC:
    ctx->pc = 0x80198BACu;
    // 80198BAC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80198BB0:
    ctx->pc = 0x80198BB0u;
    // 80198BB0: rlwinm r4, r4, 15, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 15u) & 0x00000001u;
    }

label_80198BB4:
    ctx->pc = 0x80198BB4u;
    // 80198BB4: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198BB8:
    ctx->pc = 0x80198BB8u;
    // 80198BB8: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198BBC:
    ctx->pc = 0x80198BBCu;
    // 80198BBC: rlwinm r3, r3, 14, 29, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 14u) & 0x00000007u;
    }

label_80198BC0:
    ctx->pc = 0x80198BC0u;
    // 80198BC0: stw     r3, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80198BC4:
    ctx->pc = 0x80198BC4u;
    // 80198BC4: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198BC8:
    ctx->pc = 0x80198BC8u;
    // 80198BC8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198BCC:
    ctx->pc = 0x80198BCCu;
    ctx->downcount -= 10;
    // 80198BCC: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198BD0:
    ctx->pc = 0x80198BD0u;
    // 80198BD0: rlwinm r0, r0, 11, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 11u) & 0x00000001u;
    }

label_80198BD4:
    ctx->pc = 0x80198BD4u;
    // 80198BD4: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198BD8:
    ctx->pc = 0x80198BD8u;
    // 80198BD8: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198BDC:
    ctx->pc = 0x80198BDCu;
    // 80198BDC: rlwinm r0, r0, 10, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x00000007u;
    }

label_80198BE0:
    ctx->pc = 0x80198BE0u;
    // 80198BE0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198BE4:
    ctx->pc = 0x80198BE4u;
    // 80198BE4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198BE8:
    ctx->pc = 0x80198BE8u;
    // 80198BE8: rlwinm r0, r0, 7, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 7u) & 0x0000001Fu;
    }

label_80198BEC:
    ctx->pc = 0x80198BECu;
    // 80198BEC: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198BF0:
    ctx->pc = 0x80198BF0u;
    // 80198BF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198BF4:
    ctx->pc = 0x80198BF4u;
    ctx->downcount -= 10;
    // 80198BF4: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198BF8:
    ctx->pc = 0x80198BF8u;
    // 80198BF8: rlwinm r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
    }

label_80198BFC:
    ctx->pc = 0x80198BFCu;
    // 80198BFC: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C00:
    ctx->pc = 0x80198C00u;
    // 80198C00: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C04:
    ctx->pc = 0x80198C04u;
    // 80198C04: rlwinm r0, r0, 31, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 31u) & 0x00000007u;
    }

label_80198C08:
    ctx->pc = 0x80198C08u;
    // 80198C08: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C0C:
    ctx->pc = 0x80198C0Cu;
    // 80198C0C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C10:
    ctx->pc = 0x80198C10u;
    // 80198C10: rlwinm r0, r0, 28, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0000001Fu;
    }

label_80198C14:
    ctx->pc = 0x80198C14u;
    // 80198C14: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198C18:
    ctx->pc = 0x80198C18u;
    // 80198C18: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198C1C:
    ctx->pc = 0x80198C1Cu;
    ctx->downcount -= 10;
    // 80198C1C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C20:
    ctx->pc = 0x80198C20u;
    // 80198C20: rlwinm r0, r0, 23, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x00000001u;
    }

label_80198C24:
    ctx->pc = 0x80198C24u;
    // 80198C24: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C28:
    ctx->pc = 0x80198C28u;
    // 80198C28: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C2C:
    ctx->pc = 0x80198C2Cu;
    // 80198C2C: rlwinm r0, r0, 22, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x00000007u;
    }

label_80198C30:
    ctx->pc = 0x80198C30u;
    // 80198C30: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C34:
    ctx->pc = 0x80198C34u;
    // 80198C34: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C38:
    ctx->pc = 0x80198C38u;
    // 80198C38: rlwinm r0, r0, 19, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 19u) & 0x0000001Fu;
    }

label_80198C3C:
    ctx->pc = 0x80198C3Cu;
    // 80198C3C: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198C40:
    ctx->pc = 0x80198C40u;
    // 80198C40: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198C44:
    ctx->pc = 0x80198C44u;
    ctx->downcount -= 10;
    // 80198C44: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C48:
    ctx->pc = 0x80198C48u;
    // 80198C48: rlwinm r0, r0, 14, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0x00000001u;
    }

label_80198C4C:
    ctx->pc = 0x80198C4Cu;
    // 80198C4C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C50:
    ctx->pc = 0x80198C50u;
    // 80198C50: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C54:
    ctx->pc = 0x80198C54u;
    // 80198C54: rlwinm r0, r0, 13, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0x00000007u;
    }

label_80198C58:
    ctx->pc = 0x80198C58u;
    // 80198C58: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C5C:
    ctx->pc = 0x80198C5Cu;
    // 80198C5C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C60:
    ctx->pc = 0x80198C60u;
    // 80198C60: rlwinm r0, r0, 10, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x0000001Fu;
    }

label_80198C64:
    ctx->pc = 0x80198C64u;
    // 80198C64: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198C68:
    ctx->pc = 0x80198C68u;
    // 80198C68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198C6C:
    ctx->pc = 0x80198C6Cu;
    ctx->downcount -= 10;
    // 80198C6C: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C70:
    ctx->pc = 0x80198C70u;
    // 80198C70: rlwinm r0, r0, 5, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x00000001u;
    }

label_80198C74:
    ctx->pc = 0x80198C74u;
    // 80198C74: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C78:
    ctx->pc = 0x80198C78u;
    // 80198C78: lwz     r0, 0(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C7C:
    ctx->pc = 0x80198C7Cu;
    // 80198C7C: rlwinm r0, r0, 4, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0x00000007u;
    }

label_80198C80:
    ctx->pc = 0x80198C80u;
    // 80198C80: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198C84:
    ctx->pc = 0x80198C84u;
    // 80198C84: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C88:
    ctx->pc = 0x80198C88u;
    // 80198C88: rlwinm r0, r0, 0, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x0000001Fu;
    }

label_80198C8C:
    ctx->pc = 0x80198C8Cu;
    // 80198C8C: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198C90:
    ctx->pc = 0x80198C90u;
    // 80198C90: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198C94:
    ctx->pc = 0x80198C94u;
    ctx->downcount -= 10;
    // 80198C94: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198C98:
    ctx->pc = 0x80198C98u;
    // 80198C98: rlwinm r0, r0, 27, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x00000001u;
    }

label_80198C9C:
    ctx->pc = 0x80198C9Cu;
    // 80198C9C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198CA0:
    ctx->pc = 0x80198CA0u;
    // 80198CA0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198CA4:
    ctx->pc = 0x80198CA4u;
    // 80198CA4: rlwinm r0, r0, 26, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 26u) & 0x00000007u;
    }

label_80198CA8:
    ctx->pc = 0x80198CA8u;
    // 80198CA8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198CAC:
    ctx->pc = 0x80198CACu;
    // 80198CAC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198CB0:
    ctx->pc = 0x80198CB0u;
    // 80198CB0: rlwinm r0, r0, 23, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 23u) & 0x0000001Fu;
    }

label_80198CB4:
    ctx->pc = 0x80198CB4u;
    // 80198CB4: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198CB8:
    ctx->pc = 0x80198CB8u;
    // 80198CB8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198CBC:
    ctx->pc = 0x80198CBCu;
    ctx->downcount -= 10;
    // 80198CBC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198CC0:
    ctx->pc = 0x80198CC0u;
    // 80198CC0: rlwinm r0, r0, 18, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0x00000001u;
    }

label_80198CC4:
    ctx->pc = 0x80198CC4u;
    // 80198CC4: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198CC8:
    ctx->pc = 0x80198CC8u;
    // 80198CC8: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198CCC:
    ctx->pc = 0x80198CCCu;
    // 80198CCC: rlwinm r0, r0, 17, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 17u) & 0x00000007u;
    }

label_80198CD0:
    ctx->pc = 0x80198CD0u;
    // 80198CD0: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198CD4:
    ctx->pc = 0x80198CD4u;
    // 80198CD4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198CD8:
    ctx->pc = 0x80198CD8u;
    // 80198CD8: rlwinm r0, r0, 14, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 14u) & 0x0000001Fu;
    }

label_80198CDC:
    ctx->pc = 0x80198CDCu;
    // 80198CDC: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198CE0:
    ctx->pc = 0x80198CE0u;
    // 80198CE0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198CE4:
    ctx->pc = 0x80198CE4u;
    ctx->downcount -= 10;
    // 80198CE4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198CE8:
    ctx->pc = 0x80198CE8u;
    // 80198CE8: rlwinm r0, r0, 9, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 9u) & 0x00000001u;
    }

label_80198CEC:
    ctx->pc = 0x80198CECu;
    // 80198CEC: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198CF0:
    ctx->pc = 0x80198CF0u;
    // 80198CF0: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198CF4:
    ctx->pc = 0x80198CF4u;
    // 80198CF4: rlwinm r0, r0, 8, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0x00000007u;
    }

label_80198CF8:
    ctx->pc = 0x80198CF8u;
    // 80198CF8: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198CFC:
    ctx->pc = 0x80198CFCu;
    // 80198CFC: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198D00:
    ctx->pc = 0x80198D00u;
    // 80198D00: rlwinm r0, r0, 5, 27, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 5u) & 0x0000001Fu;
    }

label_80198D04:
    ctx->pc = 0x80198D04u;
    // 80198D04: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198D08:
    ctx->pc = 0x80198D08u;
    // 80198D08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198D0C:
    ctx->pc = 0x80198D0Cu;
    ctx->downcount -= 6;
    // 80198D0C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80198D10:
    ctx->pc = 0x80198D10u;
    // 80198D10: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198D14:
    ctx->pc = 0x80198D14u;
    // 80198D14: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80198D18:
    ctx->pc = 0x80198D18u;
    // 80198D18: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198D1C:
    ctx->pc = 0x80198D1Cu;
    // 80198D1C: stb     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198D20:
    ctx->pc = 0x80198D20u;
    // 80198D20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198D24:
    ctx->pc = 0x80198D24u;
    ctx->downcount -= 9;
    // 80198D24: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80198D28:
    ctx->pc = 0x80198D28u;
    // 80198D28: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198D2C:
    ctx->pc = 0x80198D2Cu;
    // 80198D2C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80198D30:
    ctx->pc = 0x80198D30u;
    // 80198D30: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80198D34:
    ctx->pc = 0x80198D34u;
    // 80198D34: li      r31, 9
    ctx->gpr[31] = (u32)(s32)(9);

label_80198D38:
    ctx->pc = 0x80198D38u;
    // 80198D38: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80198D3C:
    ctx->pc = 0x80198D3Cu;
    // 80198D3C: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_80198D40:
    ctx->pc = 0x80198D40u;
    // 80198D40: stw     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80198D44:
    ctx->pc = 0x80198D44u;
    // 80198D44: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80198D48:
    ctx->pc = 0x80198D48u;
    ctx->downcount -= 7;
    // 80198D48: stw     r31, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80198D4C:
    // 80198D4C: addi    r3, r29, 0
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(0);

label_80198D50:
    // 80198D50: addi    r4, r31, 0
    ctx->gpr[4] = ctx->gpr[31] + (u32)(s32)(0);

label_80198D54:
    // 80198D54: addi    r5, r30, 4
    ctx->gpr[5] = ctx->gpr[30] + (u32)(s32)(4);

label_80198D58:
    // 80198D58: addi    r6, r30, 8
    ctx->gpr[6] = ctx->gpr[30] + (u32)(s32)(8);

label_80198D5C:
    // 80198D5C: addi    r7, r30, 12
    ctx->gpr[7] = ctx->gpr[30] + (u32)(s32)(12);

label_80198D60:
    // 80198D60: bl      0x80198ADC
    {
            ctx->lr = 0x80198D64u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80198ADCu;
                return;
            }
            goto label_80198ADC;
    }

label_80198D64:
    ctx->downcount -= 4;
    // 80198D64: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_80198D68:
    // 80198D68: cmpwi   r31, 26
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(26);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198D6C:
    // 80198D6C: addi    r30, r30, 16
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(16);

label_80198D70:
    // 80198D70: bc    12, 0, 0x80198D48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80198D48u;
                return;
            }
            goto label_80198D48;
        }
    }

label_80198D74:
    ctx->pc = 0x80198D74u;
    ctx->downcount -= 10;
    // 80198D74: li      r0, 255
    ctx->gpr[0] = (u32)(s32)(255);

label_80198D78:
    ctx->pc = 0x80198D78u;
    // 80198D78: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198D7C:
    ctx->pc = 0x80198D7Cu;
    // 80198D7C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198D80:
    ctx->pc = 0x80198D80u;
    // 80198D80: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80198D84:
    ctx->pc = 0x80198D84u;
    // 80198D84: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80198D88:
    ctx->pc = 0x80198D88u;
    // 80198D88: lwz     r29, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80198D8C:
    ctx->pc = 0x80198D8Cu;
    // 80198D8C: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80198D90:
    ctx->pc = 0x80198D90u;
    // 80198D90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80198D94:
    ctx->pc = 0x80198D94u;
    // 80198D94: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198D98:
    ctx->pc = 0x80198D98u;
    ctx->downcount -= 2;
    // 80198D98: cmpwi   r3, 25
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(25);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198D9C:
    ctx->pc = 0x80198D9Cu;
    // 80198D9C: bc    4, 2, 0x80198DA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198DA4;
        }
    }

label_80198DA0:
    ctx->pc = 0x80198DA0u;
    ctx->downcount -= 1;
    // 80198DA0: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_80198DA4:
    ctx->pc = 0x80198DA4u;
    ctx->downcount -= 10;
    // 80198DA4: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_80198DA8:
    ctx->pc = 0x80198DA8u;
    // 80198DA8: addi    r6, r3, -9
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(-9);

label_80198DAC:
    ctx->pc = 0x80198DACu;
    // 80198DAC: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80198DB0:
    ctx->pc = 0x80198DB0u;
    // 80198DB0: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198DB4:
    ctx->pc = 0x80198DB4u;
    // 80198DB4: ori     r0, r6, 0x00A0
    ctx->gpr[0] = ctx->gpr[6] | 0x00A0u;

label_80198DB8:
    ctx->pc = 0x80198DB8u;
    // 80198DB8: rlwinm r4, r4, 0, 2, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x3FFFFFFFu;
    }

label_80198DBC:
    ctx->pc = 0x80198DBCu;
    // 80198DBC: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198DC0:
    ctx->pc = 0x80198DC0u;
    // 80198DC0: addic.  r0, r6, -12
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-12);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80198DC4:
    ctx->pc = 0x80198DC4u;
    // 80198DC4: stw     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198DC8:
    ctx->pc = 0x80198DC8u;
    // 80198DC8: bc    12, 0, 0x80198DE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198DE4;
        }
    }

label_80198DCC:
    ctx->pc = 0x80198DCCu;
    ctx->downcount -= 2;
    // 80198DCC: cmpwi   r0, 4
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

label_80198DD0:
    ctx->pc = 0x80198DD0u;
    // 80198DD0: bc    4, 0, 0x80198DE4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198DE4;
        }
    }

label_80198DD4:
    ctx->pc = 0x80198DD4u;
    ctx->downcount -= 4;
    // 80198DD4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198DD8:
    ctx->pc = 0x80198DD8u;
    // 80198DD8: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80198DDC:
    ctx->pc = 0x80198DDCu;
    // 80198DDC: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80198DE0:
    ctx->pc = 0x80198DE0u;
    // 80198DE0: stw     r4, 136(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198DE4:
    ctx->pc = 0x80198DE4u;
    ctx->downcount -= 9;
    // 80198DE4: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_80198DE8:
    ctx->pc = 0x80198DE8u;
    // 80198DE8: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80198DEC:
    ctx->pc = 0x80198DECu;
    // 80198DEC: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198DF0:
    ctx->pc = 0x80198DF0u;
    // 80198DF0: ori     r0, r6, 0x00B0
    ctx->gpr[0] = ctx->gpr[6] | 0x00B0u;

label_80198DF4:
    ctx->pc = 0x80198DF4u;
    // 80198DF4: rlwinm r4, r5, 0, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
    }

label_80198DF8:
    ctx->pc = 0x80198DF8u;
    // 80198DF8: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198DFC:
    ctx->pc = 0x80198DFCu;
    // 80198DFC: addic.  r0, r6, -12
    {
        u64 a = ctx->gpr[6];
        u64 b = (u32)(s32)(-12);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80198E00:
    ctx->pc = 0x80198E00u;
    // 80198E00: stw     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198E04:
    ctx->pc = 0x80198E04u;
    // 80198E04: bclr  12, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198E08:
    ctx->pc = 0x80198E08u;
    ctx->downcount -= 2;
    // 80198E08: cmpwi   r0, 4
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

label_80198E0C:
    ctx->pc = 0x80198E0Cu;
    // 80198E0C: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198E10:
    ctx->pc = 0x80198E10u;
    ctx->downcount -= 5;
    // 80198E10: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80198E14:
    ctx->pc = 0x80198E14u;
    // 80198E14: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_80198E18:
    ctx->pc = 0x80198E18u;
    // 80198E18: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80198E1C:
    ctx->pc = 0x80198E1Cu;
    // 80198E1C: stw     r4, 152(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198E20:
    ctx->pc = 0x80198E20u;
    // 80198E20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198E24:
    ctx->pc = 0x80198E24u;
    ctx->downcount -= 4;
    // 80198E24: li      r0, 72
    ctx->gpr[0] = (u32)(s32)(72);

label_80198E28:
    ctx->pc = 0x80198E28u;
    // 80198E28: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80198E2C:
    ctx->pc = 0x80198E2Cu;
    // 80198E2C: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80198E30:
    ctx->pc = 0x80198E30u;
    // 80198E30: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80198E34:
    ctx->pc = 0x80198E34u;
    ctx->downcount -= 8;
    // 80198E34: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80198E38:
    ctx->pc = 0x80198E38u;
    // 80198E38: cmplwi  r5, 0x0014
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0014u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198E3C:
    ctx->pc = 0x80198E3Cu;
    // 80198E3C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198E40:
    ctx->pc = 0x80198E40u;
    // 80198E40: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80198E44:
    ctx->pc = 0x80198E44u;
    // 80198E44: li      r12, 0
    ctx->gpr[12] = (u32)(s32)(0);

label_80198E48:
    ctx->pc = 0x80198E48u;
    // 80198E48: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80198E4C:
    ctx->pc = 0x80198E4Cu;
    // 80198E4C: li      r10, 5
    ctx->gpr[10] = (u32)(s32)(5);

label_80198E50:
    ctx->pc = 0x80198E50u;
    // 80198E50: bc    12, 1, 0x80198EE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198EE8;
        }
    }

label_80198E54:
    ctx->pc = 0x80198E54u;
    ctx->downcount -= 7;
    // 80198E54: lis     r9, -32732
    ctx->gpr[9] = ((u32)(s32)(-32732) << 16);

label_80198E58:
    ctx->pc = 0x80198E58u;
    // 80198E58: addi    r9, r9, -3688
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-3688);

label_80198E5C:
    ctx->pc = 0x80198E5Cu;
    // 80198E5C: rlwinm r0, r5, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 2u) & 0xFFFFFFFCu;
    }

label_80198E60:
    ctx->pc = 0x80198E60u;
    // 80198E60: lwzx    r0, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198E64:
    ctx->pc = 0x80198E64u;
    // 80198E64: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80198E68:
    ctx->pc = 0x80198E68u;
    // 80198E68: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80198E6C:
    ctx->pc = 0x80198E6Cu;
    ctx->downcount -= 3;
    // 80198E6C: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_80198E70:
    ctx->pc = 0x80198E70u;
    // 80198E70: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_80198E74:
    ctx->pc = 0x80198E74u;
    // 80198E74: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198E78:
    ctx->pc = 0x80198E78u;
    ctx->downcount -= 3;
    // 80198E78: li      r10, 1
    ctx->gpr[10] = (u32)(s32)(1);

label_80198E7C:
    ctx->pc = 0x80198E7Cu;
    // 80198E7C: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_80198E80:
    ctx->pc = 0x80198E80u;
    // 80198E80: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198E84:
    ctx->pc = 0x80198E84u;
    ctx->downcount -= 3;
    // 80198E84: li      r10, 3
    ctx->gpr[10] = (u32)(s32)(3);

label_80198E88:
    ctx->pc = 0x80198E88u;
    // 80198E88: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_80198E8C:
    ctx->pc = 0x80198E8Cu;
    // 80198E8C: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198E90:
    ctx->pc = 0x80198E90u;
    ctx->downcount -= 3;
    // 80198E90: li      r10, 4
    ctx->gpr[10] = (u32)(s32)(4);

label_80198E94:
    ctx->pc = 0x80198E94u;
    // 80198E94: li      r12, 1
    ctx->gpr[12] = (u32)(s32)(1);

label_80198E98:
    ctx->pc = 0x80198E98u;
    // 80198E98: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198E9C:
    ctx->pc = 0x80198E9Cu;
    ctx->downcount -= 2;
    // 80198E9C: li      r10, 2
    ctx->gpr[10] = (u32)(s32)(2);

label_80198EA0:
    ctx->pc = 0x80198EA0u;
    // 80198EA0: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198EA4:
    ctx->pc = 0x80198EA4u;
    ctx->downcount -= 2;
    // 80198EA4: li      r10, 2
    ctx->gpr[10] = (u32)(s32)(2);

label_80198EA8:
    ctx->pc = 0x80198EA8u;
    // 80198EA8: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198EAC:
    ctx->pc = 0x80198EACu;
    ctx->downcount -= 2;
    // 80198EAC: li      r10, 5
    ctx->gpr[10] = (u32)(s32)(5);

label_80198EB0:
    ctx->pc = 0x80198EB0u;
    // 80198EB0: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198EB4:
    ctx->pc = 0x80198EB4u;
    ctx->downcount -= 2;
    // 80198EB4: li      r10, 6
    ctx->gpr[10] = (u32)(s32)(6);

label_80198EB8:
    ctx->pc = 0x80198EB8u;
    // 80198EB8: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198EBC:
    ctx->pc = 0x80198EBCu;
    ctx->downcount -= 2;
    // 80198EBC: li      r10, 7
    ctx->gpr[10] = (u32)(s32)(7);

label_80198EC0:
    ctx->pc = 0x80198EC0u;
    // 80198EC0: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198EC4:
    ctx->pc = 0x80198EC4u;
    ctx->downcount -= 2;
    // 80198EC4: li      r10, 8
    ctx->gpr[10] = (u32)(s32)(8);

label_80198EC8:
    ctx->pc = 0x80198EC8u;
    // 80198EC8: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198ECC:
    ctx->pc = 0x80198ECCu;
    ctx->downcount -= 2;
    // 80198ECC: li      r10, 9
    ctx->gpr[10] = (u32)(s32)(9);

label_80198ED0:
    ctx->pc = 0x80198ED0u;
    // 80198ED0: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198ED4:
    ctx->pc = 0x80198ED4u;
    ctx->downcount -= 2;
    // 80198ED4: li      r10, 10
    ctx->gpr[10] = (u32)(s32)(10);

label_80198ED8:
    ctx->pc = 0x80198ED8u;
    // 80198ED8: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198EDC:
    ctx->pc = 0x80198EDCu;
    ctx->downcount -= 2;
    // 80198EDC: li      r10, 11
    ctx->gpr[10] = (u32)(s32)(11);

label_80198EE0:
    ctx->pc = 0x80198EE0u;
    // 80198EE0: b       0x80198EE8
    {
            goto label_80198EE8;
    }

label_80198EE4:
    ctx->pc = 0x80198EE4u;
    ctx->downcount -= 1;
    // 80198EE4: li      r10, 12
    ctx->gpr[10] = (u32)(s32)(12);

label_80198EE8:
    ctx->pc = 0x80198EE8u;
    ctx->downcount -= 2;
    // 80198EE8: cmpwi   r4, 1
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198EEC:
    ctx->pc = 0x80198EECu;
    // 80198EEC: bc    12, 2, 0x80198F10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198F10;
        }
    }

label_80198EF0:
    ctx->pc = 0x80198EF0u;
    ctx->downcount -= 1;
    // 80198EF0: bc    4, 0, 0x80198F00
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198F00;
        }
    }

label_80198EF4:
    ctx->pc = 0x80198EF4u;
    ctx->downcount -= 2;
    // 80198EF4: cmpwi   r4, 0
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

label_80198EF8:
    ctx->pc = 0x80198EF8u;
    // 80198EF8: bc    4, 0, 0x80198F24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198F24;
        }
    }

label_80198EFC:
    ctx->pc = 0x80198EFCu;
    ctx->downcount -= 1;
    // 80198EFC: b       0x80198FA0
    {
            goto label_80198FA0;
    }

label_80198F00:
    ctx->pc = 0x80198F00u;
    ctx->downcount -= 2;
    // 80198F00: cmpwi   r4, 10
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(10);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198F04:
    ctx->pc = 0x80198F04u;
    // 80198F04: bc    12, 2, 0x80198F78
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80198F78;
        }
    }

label_80198F08:
    ctx->pc = 0x80198F08u;
    ctx->downcount -= 1;
    // 80198F08: bc    4, 0, 0x80198FA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198FA0;
        }
    }

label_80198F0C:
    ctx->pc = 0x80198F0Cu;
    ctx->downcount -= 1;
    // 80198F0C: b       0x80198F3C
    {
            goto label_80198F3C;
    }

label_80198F10:
    ctx->pc = 0x80198F10u;
    ctx->downcount -= 5;
    // 80198F10: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_80198F14:
    ctx->pc = 0x80198F14u;
    // 80198F14: rlwinm r4, r0, 0, 28, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF00Fu;
    }

label_80198F18:
    ctx->pc = 0x80198F18u;
    // 80198F18: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_80198F1C:
    ctx->pc = 0x80198F1Cu;
    // 80198F1C: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198F20:
    ctx->pc = 0x80198F20u;
    // 80198F20: b       0x80198FA0
    {
            goto label_80198FA0;
    }

label_80198F24:
    ctx->pc = 0x80198F24u;
    ctx->downcount -= 6;
    // 80198F24: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_80198F28:
    ctx->pc = 0x80198F28u;
    // 80198F28: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_80198F2C:
    ctx->pc = 0x80198F2Cu;
    // 80198F2C: rlwinm r4, r0, 0, 28, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF00Fu;
    }

label_80198F30:
    ctx->pc = 0x80198F30u;
    // 80198F30: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_80198F34:
    ctx->pc = 0x80198F34u;
    // 80198F34: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198F38:
    ctx->pc = 0x80198F38u;
    // 80198F38: b       0x80198FA0
    {
            goto label_80198FA0;
    }

label_80198F3C:
    ctx->pc = 0x80198F3Cu;
    ctx->downcount -= 15;
    // 80198F3C: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_80198F40:
    ctx->pc = 0x80198F40u;
    // 80198F40: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_80198F44:
    ctx->pc = 0x80198F44u;
    // 80198F44: ori     r0, r0, 0x0010
    ctx->gpr[0] = ctx->gpr[0] | 0x0010u;

label_80198F48:
    ctx->pc = 0x80198F48u;
    // 80198F48: rlwinm r9, r0, 0, 25, 19
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF07Fu;
    }

label_80198F4C:
    ctx->pc = 0x80198F4Cu;
    // 80198F4C: rlwinm r0, r10, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[10], 7u) & 0xFFFFFF80u;
    }

label_80198F50:
    ctx->pc = 0x80198F50u;
    // 80198F50: or   r9, r9, r0
    {
        ctx->gpr[9] = ctx->gpr[9] | ctx->gpr[0];
    }

label_80198F54:
    ctx->pc = 0x80198F54u;
    // 80198F54: addi    r5, r5, -12
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-12);

label_80198F58:
    ctx->pc = 0x80198F58u;
    // 80198F58: addi    r0, r4, -2
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-2);

label_80198F5C:
    ctx->pc = 0x80198F5Cu;
    // 80198F5C: rlwinm r9, r9, 0, 20, 16
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 0u) & 0xFFFF8FFFu;
    }

label_80198F60:
    ctx->pc = 0x80198F60u;
    // 80198F60: rlwinm r4, r5, 12, 0, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 12u) & 0xFFFFF000u;
    }

label_80198F64:
    ctx->pc = 0x80198F64u;
    // 80198F64: or   r4, r9, r4
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[4];
    }

label_80198F68:
    ctx->pc = 0x80198F68u;
    // 80198F68: rlwinm r4, r4, 0, 17, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC7FFFu;
    }

label_80198F6C:
    ctx->pc = 0x80198F6Cu;
    // 80198F6C: rlwinm r0, r0, 15, 0, 16
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 15u) & 0xFFFF8000u;
    }

label_80198F70:
    ctx->pc = 0x80198F70u;
    // 80198F70: or   r11, r4, r0
    {
        ctx->gpr[11] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80198F74:
    ctx->pc = 0x80198F74u;
    // 80198F74: b       0x80198FA0
    {
            goto label_80198FA0;
    }

label_80198F78:
    ctx->pc = 0x80198F78u;
    ctx->downcount -= 3;
    // 80198F78: cmpwi   r5, 19
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198F7C:
    ctx->pc = 0x80198F7Cu;
    // 80198F7C: rlwinm r0, r12, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[12], 2u) & 0xFFFFFFFCu;
    }

label_80198F80:
    ctx->pc = 0x80198F80u;
    // 80198F80: bc    4, 2, 0x80198F90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80198F90;
        }
    }

label_80198F84:
    ctx->pc = 0x80198F84u;
    ctx->downcount -= 3;
    // 80198F84: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_80198F88:
    ctx->pc = 0x80198F88u;
    // 80198F88: ori     r0, r0, 0x0020
    ctx->gpr[0] = ctx->gpr[0] | 0x0020u;

label_80198F8C:
    ctx->pc = 0x80198F8Cu;
    // 80198F8C: b       0x80198F98
    {
            goto label_80198F98;
    }

label_80198F90:
    ctx->pc = 0x80198F90u;
    ctx->downcount -= 2;
    // 80198F90: rlwinm r0, r0, 0, 28, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF8Fu;
    }

label_80198F94:
    ctx->pc = 0x80198F94u;
    // 80198F94: ori     r0, r0, 0x0030
    ctx->gpr[0] = ctx->gpr[0] | 0x0030u;

label_80198F98:
    ctx->pc = 0x80198F98u;
    ctx->downcount -= 2;
    // 80198F98: rlwinm r0, r0, 0, 25, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF07Fu;
    }

label_80198F9C:
    ctx->pc = 0x80198F9Cu;
    // 80198F9C: ori     r11, r0, 0x0100
    ctx->gpr[11] = ctx->gpr[0] | 0x0100u;

label_80198FA0:
    ctx->pc = 0x80198FA0u;
    ctx->downcount -= 16;
    // 80198FA0: li      r10, 16
    ctx->gpr[10] = (u32)(s32)(16);

label_80198FA4:
    ctx->pc = 0x80198FA4u;
    // 80198FA4: lis     r9, -13311
    ctx->gpr[9] = ((u32)(s32)(-13311) << 16);

label_80198FA8:
    ctx->pc = 0x80198FA8u;
    // 80198FA8: stb     r10, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_80198FAC:
    ctx->pc = 0x80198FACu;
    // 80198FAC: addi    r0, r3, 4160
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4160);

label_80198FB0:
    ctx->pc = 0x80198FB0u;
    // 80198FB0: addi    r4, r8, -64
    ctx->gpr[4] = ctx->gpr[8] + (u32)(s32)(-64);

label_80198FB4:
    ctx->pc = 0x80198FB4u;
    // 80198FB4: stw     r0, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198FB8:
    ctx->pc = 0x80198FB8u;
    // 80198FB8: rlwinm r5, r4, 0, 24, 22
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFEFFu;
    }

label_80198FBC:
    ctx->pc = 0x80198FBCu;
    // 80198FBC: rlwinm r4, r7, 8, 16, 23
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[7], 8u) & 0x0000FF00u;
    }

label_80198FC0:
    ctx->pc = 0x80198FC0u;
    // 80198FC0: stw     r11, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80198FC4:
    ctx->pc = 0x80198FC4u;
    // 80198FC4: addi    r0, r3, 4176
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(4176);

label_80198FC8:
    ctx->pc = 0x80198FC8u;
    // 80198FC8: cmplwi  r3, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80198FCC:
    ctx->pc = 0x80198FCCu;
    // 80198FCC: stb     r10, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[10]);
    }

label_80198FD0:
    ctx->pc = 0x80198FD0u;
    // 80198FD0: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_80198FD4:
    ctx->pc = 0x80198FD4u;
    // 80198FD4: stw     r0, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80198FD8:
    ctx->pc = 0x80198FD8u;
    // 80198FD8: stw     r4, -32768(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80198FDC:
    ctx->pc = 0x80198FDCu;
    // 80198FDC: bc    12, 1, 0x801990D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801990D0;
        }
    }

label_80198FE0:
    ctx->pc = 0x80198FE0u;
    ctx->downcount -= 7;
    // 80198FE0: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80198FE4:
    ctx->pc = 0x80198FE4u;
    // 80198FE4: addi    r4, r4, -3716
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-3716);

label_80198FE8:
    ctx->pc = 0x80198FE8u;
    // 80198FE8: rlwinm r0, r3, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80198FEC:
    ctx->pc = 0x80198FECu;
    // 80198FEC: lwzx    r0, r4, r0
    {
        u32 ea = ctx->gpr[4] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80198FF0:
    ctx->pc = 0x80198FF0u;
    // 80198FF0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80198FF4:
    ctx->pc = 0x80198FF4u;
    // 80198FF4: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_80198FF8:
    ctx->pc = 0x80198FF8u;
    ctx->downcount -= 8;
    // 80198FF8: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80198FFC:
    ctx->pc = 0x80198FFCu;
    // 80198FFC: rlwinm r0, r6, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_80199000:
    ctx->pc = 0x80199000u;
    // 80199000: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80199004:
    ctx->pc = 0x80199004u;
    // 80199004: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199008:
    ctx->pc = 0x80199008u;
    // 80199008: rlwinm r4, r4, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF03Fu;
    }

label_8019900C:
    ctx->pc = 0x8019900Cu;
    // 8019900C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80199010:
    ctx->pc = 0x80199010u;
    // 80199010: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199014:
    ctx->pc = 0x80199014u;
    // 80199014: b       0x801990EC
    {
            goto label_801990EC;
    }

label_80199018:
    ctx->pc = 0x80199018u;
    ctx->downcount -= 8;
    // 80199018: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019901C:
    ctx->pc = 0x8019901Cu;
    // 8019901C: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_80199020:
    ctx->pc = 0x80199020u;
    // 80199020: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80199024:
    ctx->pc = 0x80199024u;
    // 80199024: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199028:
    ctx->pc = 0x80199028u;
    // 80199028: rlwinm r4, r4, 0, 20, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC0FFFu;
    }

label_8019902C:
    ctx->pc = 0x8019902Cu;
    // 8019902C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80199030:
    ctx->pc = 0x80199030u;
    // 80199030: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199034:
    ctx->pc = 0x80199034u;
    // 80199034: b       0x801990EC
    {
            goto label_801990EC;
    }

label_80199038:
    ctx->pc = 0x80199038u;
    ctx->downcount -= 8;
    // 80199038: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019903C:
    ctx->pc = 0x8019903Cu;
    // 8019903C: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_80199040:
    ctx->pc = 0x80199040u;
    // 80199040: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80199044:
    ctx->pc = 0x80199044u;
    // 80199044: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199048:
    ctx->pc = 0x80199048u;
    // 80199048: rlwinm r4, r4, 0, 14, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF03FFFFu;
    }

label_8019904C:
    ctx->pc = 0x8019904Cu;
    // 8019904C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80199050:
    ctx->pc = 0x80199050u;
    // 80199050: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199054:
    ctx->pc = 0x80199054u;
    // 80199054: b       0x801990EC
    {
            goto label_801990EC;
    }

label_80199058:
    ctx->pc = 0x80199058u;
    ctx->downcount -= 8;
    // 80199058: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019905C:
    ctx->pc = 0x8019905Cu;
    // 8019905C: rlwinm r0, r6, 24, 0, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 24u) & 0xFF000000u;
    }

label_80199060:
    ctx->pc = 0x80199060u;
    // 80199060: addi    r5, r4, 128
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(128);

label_80199064:
    ctx->pc = 0x80199064u;
    // 80199064: lwz     r4, 128(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(128);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199068:
    ctx->pc = 0x80199068u;
    // 80199068: rlwinm r4, r4, 0, 8, 1
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xC0FFFFFFu;
    }

label_8019906C:
    ctx->pc = 0x8019906Cu;
    // 8019906C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80199070:
    ctx->pc = 0x80199070u;
    // 80199070: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199074:
    ctx->pc = 0x80199074u;
    // 80199074: b       0x801990EC
    {
            goto label_801990EC;
    }

label_80199078:
    ctx->pc = 0x80199078u;
    ctx->downcount -= 6;
    // 80199078: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019907C:
    ctx->pc = 0x8019907Cu;
    // 8019907C: lwzu     r0, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80199080:
    ctx->pc = 0x80199080u;
    // 80199080: rlwinm r0, r0, 0, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFC0u;
    }

label_80199084:
    ctx->pc = 0x80199084u;
    // 80199084: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_80199088:
    ctx->pc = 0x80199088u;
    // 80199088: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019908C:
    ctx->pc = 0x8019908Cu;
    // 8019908C: b       0x801990EC
    {
            goto label_801990EC;
    }

label_80199090:
    ctx->pc = 0x80199090u;
    ctx->downcount -= 8;
    // 80199090: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199094:
    ctx->pc = 0x80199094u;
    // 80199094: rlwinm r0, r6, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 6u) & 0xFFFFFFC0u;
    }

label_80199098:
    ctx->pc = 0x80199098u;
    // 80199098: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_8019909C:
    ctx->pc = 0x8019909Cu;
    // 8019909C: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801990A0:
    ctx->pc = 0x801990A0u;
    // 801990A0: rlwinm r4, r4, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF03Fu;
    }

label_801990A4:
    ctx->pc = 0x801990A4u;
    // 801990A4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801990A8:
    ctx->pc = 0x801990A8u;
    // 801990A8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801990AC:
    ctx->pc = 0x801990ACu;
    // 801990AC: b       0x801990EC
    {
            goto label_801990EC;
    }

label_801990B0:
    ctx->pc = 0x801990B0u;
    ctx->downcount -= 8;
    // 801990B0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801990B4:
    ctx->pc = 0x801990B4u;
    // 801990B4: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_801990B8:
    ctx->pc = 0x801990B8u;
    // 801990B8: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_801990BC:
    ctx->pc = 0x801990BCu;
    // 801990BC: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801990C0:
    ctx->pc = 0x801990C0u;
    // 801990C0: rlwinm r4, r4, 0, 20, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFC0FFFu;
    }

label_801990C4:
    ctx->pc = 0x801990C4u;
    // 801990C4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801990C8:
    ctx->pc = 0x801990C8u;
    // 801990C8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801990CC:
    ctx->pc = 0x801990CCu;
    // 801990CC: b       0x801990EC
    {
            goto label_801990EC;
    }

label_801990D0:
    ctx->pc = 0x801990D0u;
    ctx->downcount -= 7;
    // 801990D0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801990D4:
    ctx->pc = 0x801990D4u;
    // 801990D4: rlwinm r0, r6, 18, 0, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 18u) & 0xFFFC0000u;
    }

label_801990D8:
    ctx->pc = 0x801990D8u;
    // 801990D8: addi    r5, r4, 132
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(132);

label_801990DC:
    ctx->pc = 0x801990DCu;
    // 801990DC: lwz     r4, 132(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(132);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801990E0:
    ctx->pc = 0x801990E0u;
    // 801990E0: rlwinm r4, r4, 0, 14, 7
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFF03FFFFu;
    }

label_801990E4:
    ctx->pc = 0x801990E4u;
    // 801990E4: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_801990E8:
    ctx->pc = 0x801990E8u;
    // 801990E8: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801990EC:
    ctx->pc = 0x801990ECu;
    ctx->downcount -= 2;
    // 801990EC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_801990F0:
    ctx->pc = 0x801990F0u;
    // 801990F0: bl      0x8019FF00
    {
            ctx->lr = 0x801990F4u;
            ctx->pc = 0x8019FF00u;
            return;
    }

label_801990F4:
    ctx->pc = 0x801990F4u;
    ctx->downcount -= 5;
    // 801990F4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801990F8:
    ctx->pc = 0x801990F8u;
    // 801990F8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_801990FC:
    ctx->pc = 0x801990FCu;
    // 801990FC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199100:
    ctx->pc = 0x80199100u;
    // 80199100: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199104:
    ctx->pc = 0x80199104u;
    ctx->downcount -= 18;
    // 80199104: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199108:
    ctx->pc = 0x80199108u;
    // 80199108: rlwinm r7, r3, 0, 24, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_8019910C:
    ctx->pc = 0x8019910Cu;
    // 8019910C: li      r3, 16
    ctx->gpr[3] = (u32)(s32)(16);

label_80199110:
    ctx->pc = 0x80199110u;
    // 80199110: addi    r6, r4, 516
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(516);

label_80199114:
    ctx->pc = 0x80199114u;
    // 80199114: lwz     r5, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80199118:
    ctx->pc = 0x80199118u;
    // 80199118: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_8019911C:
    ctx->pc = 0x8019911Cu;
    // 8019911C: li      r0, 4159
    ctx->gpr[0] = (u32)(s32)(4159);

label_80199120:
    ctx->pc = 0x80199120u;
    // 80199120: rlwinm r5, r5, 0, 0, 27
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFFF0u;
    }

label_80199124:
    ctx->pc = 0x80199124u;
    // 80199124: or   r5, r5, r7
    {
        ctx->gpr[5] = ctx->gpr[5] | ctx->gpr[7];
    }

label_80199128:
    ctx->pc = 0x80199128u;
    // 80199128: stw     r5, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8019912C:
    ctx->pc = 0x8019912Cu;
    // 8019912C: stb     r3, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80199130:
    ctx->pc = 0x80199130u;
    // 80199130: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199134:
    ctx->pc = 0x80199134u;
    // 80199134: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199138:
    ctx->pc = 0x80199138u;
    // 80199138: stw     r7, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8019913C:
    ctx->pc = 0x8019913Cu;
    // 8019913C: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199140:
    ctx->pc = 0x80199140u;
    // 80199140: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80199144:
    ctx->pc = 0x80199144u;
    // 80199144: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199148:
    ctx->pc = 0x80199148u;
    // 80199148: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019914C:
    ctx->pc = 0x8019914Cu;
    ctx->downcount -= 2;
    // 8019914C: cmpwi   r3, 1
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

label_80199150:
    ctx->pc = 0x80199150u;
    // 80199150: bc    12, 2, 0x80199164
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199164;
        }
    }

label_80199154:
    ctx->pc = 0x80199154u;
    ctx->downcount -= 1;
    // 80199154: bclr  12, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199158:
    ctx->pc = 0x80199158u;
    ctx->downcount -= 2;
    // 80199158: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019915C:
    ctx->pc = 0x8019915Cu;
    // 8019915C: bclr  4, 0
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199160:
    ctx->pc = 0x80199160u;
    ctx->downcount -= 1;
    // 80199160: b       0x801991AC
    {
            goto label_801991AC;
    }

label_80199164:
    ctx->pc = 0x80199164u;
    ctx->downcount -= 14;
    // 80199164: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199168:
    ctx->pc = 0x80199168u;
    // 80199168: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8019916C:
    ctx->pc = 0x8019916Cu;
    // 8019916C: sth     r4, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[4]);
    }

label_80199170:
    ctx->pc = 0x80199170u;
    // 80199170: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199174:
    ctx->pc = 0x80199174u;
    // 80199174: lhz     r3, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80199178:
    ctx->pc = 0x80199178u;
    // 80199178: cntlzw r3, r3
    {
        u32 v = ctx->gpr[3];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[3] = n;
    }

label_8019917C:
    ctx->pc = 0x8019917Cu;
    // 8019917C: rlwinm r3, r3, 27, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 27u) & 0x0000FFFFu;
    }

label_80199180:
    ctx->pc = 0x80199180u;
    // 80199180: sth     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_80199184:
    ctx->pc = 0x80199184u;
    // 80199184: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199188:
    ctx->pc = 0x80199188u;
    // 80199188: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019918C:
    ctx->pc = 0x8019918Cu;
    // 8019918C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199190:
    ctx->pc = 0x80199190u;
    // 80199190: lhz     r0, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80199194:
    ctx->pc = 0x80199194u;
    // 80199194: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199198:
    ctx->pc = 0x80199198u;
    // 80199198: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019919C:
    ctx->pc = 0x8019919Cu;
    ctx->downcount -= 4;
    // 8019919C: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801991A0:
    ctx->pc = 0x801991A0u;
    // 801991A0: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_801991A4:
    ctx->pc = 0x801991A4u;
    // 801991A4: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801991A8:
    ctx->pc = 0x801991A8u;
    // 801991A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801991AC:
    ctx->pc = 0x801991ACu;
    ctx->downcount -= 6;
    // 801991AC: neg  r4, r4
    {
        u32 a = ctx->gpr[4];
        ctx->gpr[4] = (~a) + 1u;
    }

label_801991B0:
    ctx->pc = 0x801991B0u;
    // 801991B0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801991B4:
    ctx->pc = 0x801991B4u;
    // 801991B4: addic   r0, r4, -1
    {
        u64 a = ctx->gpr[4];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801991B8:
    ctx->pc = 0x801991B8u;
    // 801991B8: subfe   r0, r0, r4
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[4];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801991BC:
    ctx->pc = 0x801991BCu;
    // 801991BC: stb     r0, 1265(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1265);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801991C0:
    ctx->pc = 0x801991C0u;
    // 801991C0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801991C4:
    ctx->pc = 0x801991C4u;
    ctx->downcount -= 7;
    // 801991C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801991C8:
    ctx->pc = 0x801991C8u;
    // 801991C8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801991CC:
    ctx->pc = 0x801991CCu;
    // 801991CC: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801991D0:
    ctx->pc = 0x801991D0u;
    // 801991D0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801991D4:
    ctx->pc = 0x801991D4u;
    // 801991D4: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801991D8:
    ctx->pc = 0x801991D8u;
    // 801991D8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801991DC:
    ctx->pc = 0x801991DCu;
    // 801991DC: bc    12, 2, 0x801991E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801991E4;
        }
    }

label_801991E0:
    ctx->pc = 0x801991E0u;
    ctx->downcount -= 1;
    // 801991E0: bl      0x80199C8C
    {
            ctx->lr = 0x801991E4u;
            goto label_80199C8C;
    }

label_801991E4:
    ctx->pc = 0x801991E4u;
    ctx->downcount -= 11;
    // 801991E4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801991E8:
    ctx->pc = 0x801991E8u;
    // 801991E8: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_801991EC:
    ctx->pc = 0x801991ECu;
    // 801991EC: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801991F0:
    ctx->pc = 0x801991F0u;
    // 801991F0: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801991F4:
    ctx->pc = 0x801991F4u;
    // 801991F4: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801991F8:
    ctx->pc = 0x801991F8u;
    // 801991F8: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801991FC:
    ctx->pc = 0x801991FCu;
    // 801991FC: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199200:
    ctx->pc = 0x80199200u;
    // 80199200: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199204:
    ctx->pc = 0x80199204u;
    // 80199204: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199208:
    ctx->pc = 0x80199208u;
    // 80199208: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019920C:
    ctx->pc = 0x8019920Cu;
    // 8019920C: bl      0x8016F238
    {
            ctx->lr = 0x80199210u;
            ctx->pc = 0x8016F238u;
            return;
    }

label_80199210:
    ctx->pc = 0x80199210u;
    ctx->downcount -= 5;
    // 80199210: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199214:
    ctx->pc = 0x80199214u;
    // 80199214: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80199218:
    ctx->pc = 0x80199218u;
    // 80199218: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019921C:
    ctx->pc = 0x8019921Cu;
    // 8019921C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199220:
    ctx->pc = 0x80199220u;
    ctx->downcount -= 3;
    // 80199220: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199224:
    ctx->pc = 0x80199224u;
    // 80199224: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199228:
    ctx->pc = 0x80199228u;
    // 80199228: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019922C:
    ctx->downcount -= 1;
    // 8019922C: bl      0x8016F340
    {
            ctx->lr = 0x80199230u;
            ctx->pc = 0x8016F340u;
            return;
    }

label_80199230:
    ctx->downcount -= 2;
    // 80199230: rlwinm. r0, r3, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199234:
    // 80199234: bc    4, 2, 0x8019922C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019922Cu;
                return;
            }
            goto label_8019922C;
        }
    }

label_80199238:
    ctx->pc = 0x80199238u;
    ctx->downcount -= 3;
    // 80199238: lis     r3, 3073
    ctx->gpr[3] = ((u32)(s32)(3073) << 16);

label_8019923C:
    ctx->pc = 0x8019923Cu;
    // 8019923C: addi    r3, r3, -32768
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-32768);

label_80199240:
    ctx->pc = 0x80199240u;
    // 80199240: bl      0x8016F34C
    {
            ctx->lr = 0x80199244u;
            ctx->pc = 0x8016F34Cu;
            return;
    }

label_80199244:
    ctx->pc = 0x80199244u;
    ctx->downcount -= 5;
    // 80199244: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199248:
    ctx->pc = 0x80199248u;
    // 80199248: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8019924C:
    ctx->pc = 0x8019924Cu;
    // 8019924C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199250:
    ctx->pc = 0x80199250u;
    // 80199250: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199254:
    ctx->pc = 0x80199254u;
    ctx->downcount -= 11;
    // 80199254: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199258:
    ctx->pc = 0x80199258u;
    // 80199258: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019925C:
    ctx->pc = 0x8019925Cu;
    // 8019925C: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80199260:
    ctx->pc = 0x80199260u;
    // 80199260: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199264:
    ctx->pc = 0x80199264u;
    // 80199264: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199268:
    ctx->pc = 0x80199268u;
    // 80199268: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8019926C:
    ctx->pc = 0x8019926Cu;
    // 8019926C: stw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80199270:
    ctx->pc = 0x80199270u;
    // 80199270: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80199274:
    ctx->pc = 0x80199274u;
    // 80199274: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199278:
    ctx->pc = 0x80199278u;
    // 80199278: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019927C:
    ctx->pc = 0x8019927Cu;
    // 8019927C: bl      0x80179FF4
    {
            ctx->lr = 0x80199280u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_80199280:
    ctx->pc = 0x80199280u;
    ctx->downcount -= 5;
    // 80199280: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199284:
    ctx->pc = 0x80199284u;
    // 80199284: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80199288:
    ctx->pc = 0x80199288u;
    // 80199288: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8019928C:
    ctx->pc = 0x8019928Cu;
    // 8019928C: xoris   r28, r0, 0x8000
    ctx->gpr[28] = ctx->gpr[0] ^ (0x8000u << 16);

label_80199290:
    ctx->pc = 0x80199290u;
    // 80199290: li      r29, 50
    ctx->gpr[29] = (u32)(s32)(50);

label_80199294:
    ctx->downcount -= 1;
    // 80199294: bl      0x80179FF4
    {
            ctx->lr = 0x80199298u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_80199298:
    ctx->downcount -= 8;
    // 80199298: subfc   r4, r31, r4
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8019929C:
    // 8019929C: subfe   r0, r30, r3
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992A0:
    // 801992A0: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_801992A4:
    // 801992A4: subfc   r0, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992A8:
    // 801992A8: subfe   r3, r3, r28
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992AC:
    // 801992AC: subfe   r3, r28, r28
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992B0:
    // 801992B0: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801992B4:
    // 801992B4: bc    12, 2, 0x80199294
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80199294u;
                return;
            }
            goto label_80199294;
        }
    }

label_801992B8:
    ctx->pc = 0x801992B8u;
    ctx->downcount -= 4;
    // 801992B8: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801992BC:
    ctx->pc = 0x801992BCu;
    // 801992BC: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_801992C0:
    ctx->pc = 0x801992C0u;
    // 801992C0: stw     r30, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801992C4:
    ctx->pc = 0x801992C4u;
    // 801992C4: bl      0x80179FF4
    {
            ctx->lr = 0x801992C8u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_801992C8:
    ctx->pc = 0x801992C8u;
    ctx->downcount -= 4;
    // 801992C8: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_801992CC:
    ctx->pc = 0x801992CCu;
    // 801992CC: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_801992D0:
    ctx->pc = 0x801992D0u;
    // 801992D0: xoris   r31, r30, 0x8000
    ctx->gpr[31] = ctx->gpr[30] ^ (0x8000u << 16);

label_801992D4:
    ctx->pc = 0x801992D4u;
    // 801992D4: li      r30, 5
    ctx->gpr[30] = (u32)(s32)(5);

label_801992D8:
    ctx->downcount -= 1;
    // 801992D8: bl      0x80179FF4
    {
            ctx->lr = 0x801992DCu;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_801992DC:
    ctx->downcount -= 8;
    // 801992DC: subfc   r4, r28, r4
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992E0:
    // 801992E0: subfe   r0, r29, r3
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992E4:
    // 801992E4: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_801992E8:
    // 801992E8: subfc   r0, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992EC:
    // 801992EC: subfe   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992F0:
    // 801992F0: subfe   r3, r31, r31
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801992F4:
    // 801992F4: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801992F8:
    // 801992F8: bc    12, 2, 0x801992D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801992D8u;
                return;
            }
            goto label_801992D8;
        }
    }

label_801992FC:
    ctx->pc = 0x801992FCu;
    ctx->downcount -= 9;
    // 801992FC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199300:
    ctx->pc = 0x80199300u;
    // 80199300: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199304:
    ctx->pc = 0x80199304u;
    // 80199304: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80199308:
    ctx->pc = 0x80199308u;
    // 80199308: lwz     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_8019930C:
    ctx->pc = 0x8019930Cu;
    // 8019930C: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80199310:
    ctx->pc = 0x80199310u;
    // 80199310: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80199314:
    ctx->pc = 0x80199314u;
    // 80199314: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199318:
    ctx->pc = 0x80199318u;
    // 80199318: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019931C:
    ctx->pc = 0x8019931Cu;
    ctx->downcount -= 11;
    // 8019931C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199320:
    ctx->pc = 0x80199320u;
    // 80199320: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199324:
    ctx->pc = 0x80199324u;
    // 80199324: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80199328:
    ctx->pc = 0x80199328u;
    // 80199328: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019932C:
    ctx->pc = 0x8019932Cu;
    // 8019932C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199330:
    ctx->pc = 0x80199330u;
    // 80199330: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80199334:
    ctx->pc = 0x80199334u;
    // 80199334: stw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80199338:
    ctx->pc = 0x80199338u;
    // 80199338: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8019933C:
    ctx->pc = 0x8019933Cu;
    // 8019933C: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199340:
    ctx->pc = 0x80199340u;
    // 80199340: stw     r0, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199344:
    ctx->pc = 0x80199344u;
    // 80199344: bl      0x80179FF4
    {
            ctx->lr = 0x80199348u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_80199348:
    ctx->pc = 0x80199348u;
    ctx->downcount -= 5;
    // 80199348: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019934C:
    ctx->pc = 0x8019934Cu;
    // 8019934C: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80199350:
    ctx->pc = 0x80199350u;
    // 80199350: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_80199354:
    ctx->pc = 0x80199354u;
    // 80199354: xoris   r28, r0, 0x8000
    ctx->gpr[28] = ctx->gpr[0] ^ (0x8000u << 16);

label_80199358:
    ctx->pc = 0x80199358u;
    // 80199358: li      r29, 50
    ctx->gpr[29] = (u32)(s32)(50);

label_8019935C:
    ctx->downcount -= 1;
    // 8019935C: bl      0x80179FF4
    {
            ctx->lr = 0x80199360u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_80199360:
    ctx->downcount -= 8;
    // 80199360: subfc   r4, r31, r4
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80199364:
    // 80199364: subfe   r0, r30, r3
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80199368:
    // 80199368: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_8019936C:
    // 8019936C: subfc   r0, r4, r29
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[29];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80199370:
    // 80199370: subfe   r3, r3, r28
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80199374:
    // 80199374: subfe   r3, r28, r28
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[28];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_80199378:
    // 80199378: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019937C:
    // 8019937C: bc    12, 2, 0x8019935C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019935Cu;
                return;
            }
            goto label_8019935C;
        }
    }

label_80199380:
    ctx->pc = 0x80199380u;
    ctx->downcount -= 4;
    // 80199380: lwz     r3, -26144(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26144);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199384:
    ctx->pc = 0x80199384u;
    // 80199384: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_80199388:
    ctx->pc = 0x80199388u;
    // 80199388: stw     r30, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8019938C:
    ctx->pc = 0x8019938Cu;
    // 8019938C: bl      0x80179FF4
    {
            ctx->lr = 0x80199390u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_80199390:
    ctx->pc = 0x80199390u;
    ctx->downcount -= 4;
    // 80199390: addi    r28, r4, 0
    ctx->gpr[28] = ctx->gpr[4] + (u32)(s32)(0);

label_80199394:
    ctx->pc = 0x80199394u;
    // 80199394: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80199398:
    ctx->pc = 0x80199398u;
    // 80199398: xoris   r31, r30, 0x8000
    ctx->gpr[31] = ctx->gpr[30] ^ (0x8000u << 16);

label_8019939C:
    ctx->pc = 0x8019939Cu;
    // 8019939C: li      r30, 5
    ctx->gpr[30] = (u32)(s32)(5);

label_801993A0:
    ctx->downcount -= 1;
    // 801993A0: bl      0x80179FF4
    {
            ctx->lr = 0x801993A4u;
            ctx->pc = 0x80179FF4u;
            return;
    }

label_801993A4:
    ctx->downcount -= 8;
    // 801993A4: subfc   r4, r28, r4
    {
        u32 a = ~ctx->gpr[28];
        u32 b = ctx->gpr[4];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[4] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801993A8:
    // 801993A8: subfe   r0, r29, r3
    {
        u32 a = ~ctx->gpr[29];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801993AC:
    // 801993AC: xoris   r3, r0, 0x8000
    ctx->gpr[3] = ctx->gpr[0] ^ (0x8000u << 16);

label_801993B0:
    // 801993B0: subfc   r0, r4, r30
    {
        u32 a = ~ctx->gpr[4];
        u32 b = ctx->gpr[30];
        u64 wide = (u64)b + (u64)a + 1u;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801993B4:
    // 801993B4: subfe   r3, r3, r31
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801993B8:
    // 801993B8: subfe   r3, r31, r31
    {
        u32 a = ~ctx->gpr[31];
        u32 b = ctx->gpr[31];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[3] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_801993BC:
    // 801993BC: neg.  r3, r3
    {
        u32 a = ctx->gpr[3];
        ctx->gpr[3] = (~a) + 1u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_801993C0:
    // 801993C0: bc    12, 2, 0x801993A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801993A0u;
                return;
            }
            goto label_801993A0;
        }
    }

label_801993C4:
    ctx->pc = 0x801993C4u;
    ctx->downcount -= 1;
    // 801993C4: bl      0x80197324
    {
            ctx->lr = 0x801993C8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197324u;
                return;
            }
            goto label_80197324;
    }

label_801993C8:
    ctx->pc = 0x801993C8u;
    ctx->downcount -= 9;
    // 801993C8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801993CC:
    ctx->pc = 0x801993CCu;
    // 801993CC: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801993D0:
    ctx->pc = 0x801993D0u;
    // 801993D0: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801993D4:
    ctx->pc = 0x801993D4u;
    // 801993D4: lwz     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_801993D8:
    ctx->pc = 0x801993D8u;
    // 801993D8: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_801993DC:
    ctx->pc = 0x801993DCu;
    // 801993DC: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_801993E0:
    ctx->pc = 0x801993E0u;
    // 801993E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801993E4:
    ctx->pc = 0x801993E4u;
    // 801993E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801993E8:
    ctx->pc = 0x801993E8u;
    ctx->downcount -= 7;
    // 801993E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801993EC:
    ctx->pc = 0x801993ECu;
    // 801993EC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801993F0:
    ctx->pc = 0x801993F0u;
    // 801993F0: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801993F4:
    ctx->pc = 0x801993F4u;
    // 801993F4: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801993F8:
    ctx->pc = 0x801993F8u;
    // 801993F8: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801993FC:
    ctx->pc = 0x801993FCu;
    // 801993FC: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80199400:
    ctx->pc = 0x80199400u;
    // 80199400: bl      0x80173F2C
    {
            ctx->lr = 0x80199404u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80199404:
    ctx->pc = 0x80199404u;
    ctx->downcount -= 17;
    // 80199404: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_80199408:
    ctx->pc = 0x80199408u;
    // 80199408: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019940C:
    ctx->pc = 0x8019940Cu;
    // 8019940C: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80199410:
    ctx->pc = 0x80199410u;
    // 80199410: rlwinm r0, r30, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_80199414:
    ctx->pc = 0x80199414u;
    // 80199414: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80199418:
    ctx->pc = 0x80199418u;
    // 80199418: oris    r0, r0, 0x4800
    ctx->gpr[0] = ctx->gpr[0] | (0x4800u << 16);

label_8019941C:
    ctx->pc = 0x8019941Cu;
    // 8019941C: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199420:
    ctx->pc = 0x80199420u;
    // 80199420: rlwinm r0, r0, 0, 0, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF0000u;
    }

label_80199424:
    ctx->pc = 0x80199424u;
    // 80199424: rlwimi r0, r30, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[30], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_80199428:
    ctx->pc = 0x80199428u;
    // 80199428: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_8019942C:
    ctx->pc = 0x8019942Cu;
    // 8019942C: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_80199430:
    ctx->pc = 0x80199430u;
    // 80199430: oris    r0, r0, 0x4700
    ctx->gpr[0] = ctx->gpr[0] | (0x4700u << 16);

label_80199434:
    ctx->pc = 0x80199434u;
    // 80199434: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199438:
    ctx->pc = 0x80199438u;
    // 80199438: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019943C:
    ctx->pc = 0x8019943Cu;
    // 8019943C: lwz     r0, 1268(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199440:
    ctx->pc = 0x80199440u;
    // 80199440: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199444:
    ctx->pc = 0x80199444u;
    // 80199444: bc    12, 2, 0x8019944C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019944C;
        }
    }

label_80199448:
    ctx->pc = 0x80199448u;
    ctx->downcount -= 1;
    // 80199448: bl      0x80199C8C
    {
            ctx->lr = 0x8019944Cu;
            goto label_80199C8C;
    }

label_8019944C:
    ctx->pc = 0x8019944Cu;
    ctx->downcount -= 11;
    // 8019944C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80199450:
    ctx->pc = 0x80199450u;
    // 80199450: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80199454:
    ctx->pc = 0x80199454u;
    // 80199454: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199458:
    ctx->pc = 0x80199458u;
    // 80199458: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019945C:
    ctx->pc = 0x8019945Cu;
    // 8019945C: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199460:
    ctx->pc = 0x80199460u;
    // 80199460: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199464:
    ctx->pc = 0x80199464u;
    // 80199464: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199468:
    ctx->pc = 0x80199468u;
    // 80199468: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019946C:
    ctx->pc = 0x8019946Cu;
    // 8019946C: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199470:
    ctx->pc = 0x80199470u;
    // 80199470: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199474:
    ctx->pc = 0x80199474u;
    // 80199474: bl      0x8016F238
    {
            ctx->lr = 0x80199478u;
            ctx->pc = 0x8016F238u;
            return;
    }

label_80199478:
    ctx->pc = 0x80199478u;
    ctx->downcount -= 2;
    // 80199478: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8019947C:
    ctx->pc = 0x8019947Cu;
    // 8019947C: bl      0x80173F54
    {
            ctx->lr = 0x80199480u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80199480:
    ctx->pc = 0x80199480u;
    ctx->downcount -= 9;
    // 80199480: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199484:
    ctx->pc = 0x80199484u;
    // 80199484: sth     r31, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[31]);
    }

label_80199488:
    ctx->pc = 0x80199488u;
    // 80199488: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019948C:
    ctx->pc = 0x8019948Cu;
    // 8019948C: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199490:
    ctx->pc = 0x80199490u;
    // 80199490: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80199494:
    ctx->pc = 0x80199494u;
    // 80199494: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80199498:
    ctx->pc = 0x80199498u;
    // 80199498: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019949C:
    ctx->pc = 0x8019949Cu;
    // 8019949C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801994A0:
    ctx->pc = 0x801994A0u;
    ctx->downcount -= 3;
    // 801994A0: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801994A4:
    ctx->pc = 0x801994A4u;
    // 801994A4: lhz     r3, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_801994A8:
    ctx->pc = 0x801994A8u;
    // 801994A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801994AC:
    ctx->pc = 0x801994ACu;
    ctx->downcount -= 6;
    // 801994AC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801994B0:
    ctx->pc = 0x801994B0u;
    // 801994B0: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801994B4:
    ctx->pc = 0x801994B4u;
    // 801994B4: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801994B8:
    ctx->pc = 0x801994B8u;
    // 801994B8: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801994BC:
    ctx->pc = 0x801994BCu;
    // 801994BC: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_801994C0:
    ctx->pc = 0x801994C0u;
    // 801994C0: bl      0x80173F2C
    {
            ctx->lr = 0x801994C4u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801994C4:
    ctx->pc = 0x801994C4u;
    ctx->downcount -= 11;
    // 801994C4: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_801994C8:
    ctx->pc = 0x801994C8u;
    // 801994C8: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_801994CC:
    ctx->pc = 0x801994CCu;
    // 801994CC: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_801994D0:
    ctx->pc = 0x801994D0u;
    // 801994D0: lis     r5, 17664
    ctx->gpr[5] = ((u32)(s32)(17664) << 16);

label_801994D4:
    ctx->pc = 0x801994D4u;
    // 801994D4: stb     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801994D8:
    ctx->pc = 0x801994D8u;
    // 801994D8: addi    r0, r5, 2
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(2);

label_801994DC:
    ctx->pc = 0x801994DCu;
    // 801994DC: stw     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801994E0:
    ctx->pc = 0x801994E0u;
    // 801994E0: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801994E4:
    ctx->pc = 0x801994E4u;
    // 801994E4: lwz     r0, 1268(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801994E8:
    ctx->pc = 0x801994E8u;
    // 801994E8: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801994EC:
    ctx->pc = 0x801994ECu;
    // 801994EC: bc    12, 2, 0x801994F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801994F4;
        }
    }

label_801994F0:
    ctx->pc = 0x801994F0u;
    ctx->downcount -= 1;
    // 801994F0: bl      0x80199C8C
    {
            ctx->lr = 0x801994F4u;
            goto label_80199C8C;
    }

label_801994F4:
    ctx->pc = 0x801994F4u;
    ctx->downcount -= 11;
    // 801994F4: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_801994F8:
    ctx->pc = 0x801994F8u;
    // 801994F8: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_801994FC:
    ctx->pc = 0x801994FCu;
    // 801994FC: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199500:
    ctx->pc = 0x80199500u;
    // 80199500: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199504:
    ctx->pc = 0x80199504u;
    // 80199504: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199508:
    ctx->pc = 0x80199508u;
    // 80199508: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019950C:
    ctx->pc = 0x8019950Cu;
    // 8019950C: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199510:
    ctx->pc = 0x80199510u;
    // 80199510: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199514:
    ctx->pc = 0x80199514u;
    // 80199514: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199518:
    ctx->pc = 0x80199518u;
    // 80199518: stw     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019951C:
    ctx->pc = 0x8019951Cu;
    // 8019951C: bl      0x8016F238
    {
            ctx->lr = 0x80199520u;
            ctx->pc = 0x8016F238u;
            return;
    }

label_80199520:
    ctx->pc = 0x80199520u;
    ctx->downcount -= 3;
    // 80199520: stb     r31, -26088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26088);
        mem_write8(ctx, ea, (u8)ctx->gpr[31]);
    }

label_80199524:
    ctx->pc = 0x80199524u;
    // 80199524: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_80199528:
    ctx->pc = 0x80199528u;
    // 80199528: bl      0x80173F54
    {
            ctx->lr = 0x8019952Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8019952C:
    ctx->pc = 0x8019952Cu;
    ctx->downcount -= 7;
    // 8019952C: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199530:
    ctx->pc = 0x80199530u;
    // 80199530: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199534:
    ctx->pc = 0x80199534u;
    // 80199534: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80199538:
    ctx->pc = 0x80199538u;
    // 80199538: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_8019953C:
    ctx->pc = 0x8019953Cu;
    // 8019953C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199540:
    ctx->pc = 0x80199540u;
    // 80199540: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199544:
    ctx->pc = 0x80199544u;
    ctx->downcount -= 5;
    // 80199544: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199548:
    ctx->pc = 0x80199548u;
    // 80199548: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019954C:
    ctx->pc = 0x8019954Cu;
    // 8019954C: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199550:
    ctx->pc = 0x80199550u;
    // 80199550: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199554:
    ctx->pc = 0x80199554u;
    // 80199554: bl      0x80173F2C
    {
            ctx->lr = 0x80199558u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80199558:
    ctx->pc = 0x80199558u;
    ctx->downcount -= 2;
    // 80199558: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019955C:
    ctx->pc = 0x8019955Cu;
    // 8019955C: b       0x80199568
    {
            goto label_80199568;
    }

label_80199560:
    ctx->downcount -= 2;
    // 80199560: addi    r3, r13, -26084
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26084);

label_80199564:
    // 80199564: bl      0x80179478
    {
            ctx->lr = 0x80199568u;
            ctx->pc = 0x80179478u;
            return;
    }

label_80199568:
    ctx->pc = 0x80199568u;
    ctx->downcount -= 3;
    // 80199568: lbz     r0, -26088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26088);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019956C:
    // 8019956C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199570:
    // 80199570: bc    12, 2, 0x80199560
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80199560u;
                return;
            }
            goto label_80199560;
        }
    }

label_80199574:
    ctx->pc = 0x80199574u;
    ctx->downcount -= 2;
    // 80199574: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80199578:
    ctx->pc = 0x80199578u;
    // 80199578: bl      0x80173F54
    {
            ctx->lr = 0x8019957Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8019957C:
    ctx->pc = 0x8019957Cu;
    ctx->downcount -= 6;
    // 8019957C: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199580:
    ctx->pc = 0x80199580u;
    // 80199580: lwz     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199584:
    ctx->pc = 0x80199584u;
    // 80199584: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_80199588:
    ctx->pc = 0x80199588u;
    // 80199588: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019958C:
    ctx->pc = 0x8019958Cu;
    // 8019958C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199590:
    ctx->pc = 0x80199590u;
    ctx->downcount -= 5;
    // 80199590: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199594:
    ctx->pc = 0x80199594u;
    // 80199594: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199598:
    ctx->pc = 0x80199598u;
    // 80199598: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019959C:
    ctx->pc = 0x8019959Cu;
    // 8019959C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_801995A0:
    ctx->pc = 0x801995A0u;
    // 801995A0: bl      0x80173F2C
    {
            ctx->lr = 0x801995A4u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801995A4:
    ctx->pc = 0x801995A4u;
    ctx->downcount -= 8;
    // 801995A4: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_801995A8:
    ctx->pc = 0x801995A8u;
    // 801995A8: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_801995AC:
    ctx->pc = 0x801995ACu;
    // 801995AC: lis     r4, 17664
    ctx->gpr[4] = ((u32)(s32)(17664) << 16);

label_801995B0:
    ctx->pc = 0x801995B0u;
    // 801995B0: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801995B4:
    ctx->pc = 0x801995B4u;
    // 801995B4: addi    r0, r4, 2
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(2);

label_801995B8:
    ctx->pc = 0x801995B8u;
    // 801995B8: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801995BC:
    ctx->pc = 0x801995BCu;
    // 801995BC: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801995C0:
    ctx->pc = 0x801995C0u;
    // 801995C0: bl      0x801991C4
    {
            ctx->lr = 0x801995C4u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801991C4u;
                return;
            }
            goto label_801991C4;
    }

label_801995C4:
    ctx->pc = 0x801995C4u;
    ctx->downcount -= 4;
    // 801995C4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_801995C8:
    ctx->pc = 0x801995C8u;
    // 801995C8: stb     r0, -26088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26088);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_801995CC:
    ctx->pc = 0x801995CCu;
    // 801995CC: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801995D0:
    ctx->pc = 0x801995D0u;
    // 801995D0: bl      0x80173F54
    {
            ctx->lr = 0x801995D4u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801995D4:
    ctx->pc = 0x801995D4u;
    ctx->downcount -= 1;
    // 801995D4: bl      0x80173F2C
    {
            ctx->lr = 0x801995D8u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_801995D8:
    ctx->pc = 0x801995D8u;
    ctx->downcount -= 2;
    // 801995D8: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_801995DC:
    ctx->pc = 0x801995DCu;
    // 801995DC: b       0x801995E8
    {
            goto label_801995E8;
    }

label_801995E0:
    ctx->downcount -= 2;
    // 801995E0: addi    r3, r13, -26084
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26084);

label_801995E4:
    // 801995E4: bl      0x80179478
    {
            ctx->lr = 0x801995E8u;
            ctx->pc = 0x80179478u;
            return;
    }

label_801995E8:
    ctx->pc = 0x801995E8u;
    ctx->downcount -= 3;
    // 801995E8: lbz     r0, -26088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26088);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_801995EC:
    // 801995EC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801995F0:
    // 801995F0: bc    12, 2, 0x801995E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x801995E0u;
                return;
            }
            goto label_801995E0;
        }
    }

label_801995F4:
    ctx->pc = 0x801995F4u;
    ctx->downcount -= 2;
    // 801995F4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_801995F8:
    ctx->pc = 0x801995F8u;
    // 801995F8: bl      0x80173F54
    {
            ctx->lr = 0x801995FCu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_801995FC:
    ctx->pc = 0x801995FCu;
    ctx->downcount -= 6;
    // 801995FC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199600:
    ctx->pc = 0x80199600u;
    // 80199600: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199604:
    ctx->pc = 0x80199604u;
    // 80199604: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80199608:
    ctx->pc = 0x80199608u;
    // 80199608: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019960C:
    ctx->pc = 0x8019960Cu;
    // 8019960C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199610:
    ctx->pc = 0x80199610u;
    ctx->downcount -= 9;
    // 80199610: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80199614:
    ctx->pc = 0x80199614u;
    // 80199614: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199618:
    ctx->pc = 0x80199618u;
    // 80199618: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019961C:
    ctx->pc = 0x8019961Cu;
    // 8019961C: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80199620:
    ctx->pc = 0x80199620u;
    // 80199620: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199624:
    ctx->pc = 0x80199624u;
    // 80199624: lwz     r3, 476(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(476);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199628:
    ctx->pc = 0x80199628u;
    // 80199628: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019962C:
    ctx->pc = 0x8019962Cu;
    // 8019962C: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199630:
    ctx->pc = 0x80199630u;
    // 80199630: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199634:
    ctx->pc = 0x80199634u;
    ctx->downcount -= 9;
    // 80199634: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_80199638:
    ctx->pc = 0x80199638u;
    // 80199638: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019963C:
    ctx->pc = 0x8019963Cu;
    // 8019963C: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80199640:
    ctx->pc = 0x80199640u;
    // 80199640: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80199644:
    ctx->pc = 0x80199644u;
    // 80199644: lis     r4, 25344
    ctx->gpr[4] = ((u32)(s32)(25344) << 16);

label_80199648:
    ctx->pc = 0x80199648u;
    // 80199648: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019964C:
    ctx->pc = 0x8019964Cu;
    // 8019964C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199650:
    ctx->pc = 0x80199650u;
    // 80199650: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199654:
    ctx->pc = 0x80199654u;
    // 80199654: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199658:
    ctx->pc = 0x80199658u;
    ctx->downcount -= 5;
    // 80199658: lwz     r5, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019965C:
    ctx->pc = 0x8019965Cu;
    // 8019965C: rlwinm r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
    }

label_80199660:
    ctx->pc = 0x80199660u;
    // 80199660: rlwimi r0, r3, 8, 0, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 8u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0xFFFFFF00u) | (rot & 0xFFFFFF00u);
    }

label_80199664:
    ctx->pc = 0x80199664u;
    // 80199664: sth     r0, 6(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199668:
    ctx->pc = 0x80199668u;
    // 80199668: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019966C:
    ctx->pc = 0x8019966Cu;
    ctx->downcount -= 5;
    // 8019966C: rlwinm r0, r3, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_80199670:
    ctx->pc = 0x80199670u;
    // 80199670: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199674:
    ctx->pc = 0x80199674u;
    // 80199674: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80199678:
    ctx->pc = 0x80199678u;
    // 80199678: sth     r0, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019967C:
    ctx->pc = 0x8019967Cu;
    // 8019967C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199680:
    ctx->pc = 0x80199680u;
    ctx->downcount -= 7;
    // 80199680: lwz     r4, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199684:
    ctx->pc = 0x80199684u;
    // 80199684: rlwinm r0, r3, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0x00000FF0u;
    }

label_80199688:
    ctx->pc = 0x80199688u;
    // 80199688: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8019968C:
    ctx->pc = 0x8019968Cu;
    // 8019968C: rlwinm r3, r3, 0, 28, 26
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFEFu;
    }

label_80199690:
    ctx->pc = 0x80199690u;
    // 80199690: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199694:
    ctx->pc = 0x80199694u;
    // 80199694: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199698:
    ctx->pc = 0x80199698u;
    // 80199698: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019969C:
    ctx->pc = 0x8019969Cu;
    ctx->downcount -= 6;
    // 8019969C: lwz     r7, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_801996A0:
    ctx->pc = 0x801996A0u;
    // 801996A0: cmpwi   r3, 1
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

label_801996A4:
    ctx->pc = 0x801996A4u;
    // 801996A4: li      r9, 1
    ctx->gpr[9] = (u32)(s32)(1);

label_801996A8:
    ctx->pc = 0x801996A8u;
    // 801996A8: addi    r10, r7, 2
    ctx->gpr[10] = ctx->gpr[7] + (u32)(s32)(2);

label_801996AC:
    ctx->pc = 0x801996ACu;
    // 801996AC: lhz     r7, 2(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(2);
        ctx->gpr[7] = mem_read16(ctx, ea);
    }

label_801996B0:
    ctx->pc = 0x801996B0u;
    // 801996B0: bc    12, 2, 0x801996C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801996C0;
        }
    }

label_801996B4:
    ctx->pc = 0x801996B4u;
    ctx->downcount -= 2;
    // 801996B4: cmpwi   r3, 3
    {
        s32 val_a = (s32)(ctx->gpr[3]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_801996B8:
    ctx->pc = 0x801996B8u;
    // 801996B8: bc    12, 2, 0x801996C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801996C0;
        }
    }

label_801996BC:
    ctx->pc = 0x801996BCu;
    ctx->downcount -= 1;
    // 801996BC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_801996C0:
    ctx->pc = 0x801996C0u;
    ctx->downcount -= 25;
    // 801996C0: rlwinm r8, r7, 0, 0, 30
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFFEu;
    }

label_801996C4:
    ctx->pc = 0x801996C4u;
    // 801996C4: subfic  r0, r3, 3
    {
        u64 res = (u64)(u32)(s32)(3) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801996C8:
    ctx->pc = 0x801996C8u;
    // 801996C8: cntlzw r7, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[7] = n;
    }

label_801996CC:
    ctx->pc = 0x801996CCu;
    // 801996CC: subfic  r0, r3, 2
    {
        u64 res = (u64)(u32)(s32)(2) + (u64)(~ctx->gpr[3]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_801996D0:
    ctx->pc = 0x801996D0u;
    // 801996D0: or   r8, r8, r9
    {
        ctx->gpr[8] = ctx->gpr[8] | ctx->gpr[9];
    }

label_801996D4:
    ctx->pc = 0x801996D4u;
    // 801996D4: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_801996D8:
    ctx->pc = 0x801996D8u;
    // 801996D8: rlwinm r8, r8, 0, 21, 19
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFFFF7FFu;
    }

label_801996DC:
    ctx->pc = 0x801996DCu;
    // 801996DC: rlwinm r3, r7, 6, 0, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[7], 6u) & 0xFFFFF800u;
    }

label_801996E0:
    ctx->pc = 0x801996E0u;
    // 801996E0: or   r3, r8, r3
    {
        ctx->gpr[3] = ctx->gpr[8] | ctx->gpr[3];
    }

label_801996E4:
    ctx->pc = 0x801996E4u;
    // 801996E4: rlwinm r3, r3, 0, 31, 29
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_801996E8:
    ctx->pc = 0x801996E8u;
    // 801996E8: rlwinm r0, r0, 28, 4, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x0FFFFFFEu;
    }

label_801996EC:
    ctx->pc = 0x801996ECu;
    // 801996EC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801996F0:
    ctx->pc = 0x801996F0u;
    // 801996F0: rlwinm r3, r0, 0, 20, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF0FFFu;
    }

label_801996F4:
    ctx->pc = 0x801996F4u;
    // 801996F4: rlwinm r0, r6, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 12u) & 0xFFFFF000u;
    }

label_801996F8:
    ctx->pc = 0x801996F8u;
    // 801996F8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801996FC:
    ctx->pc = 0x801996FCu;
    // 801996FC: rlwinm r3, r0, 0, 24, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFF8FFu;
    }

label_80199700:
    ctx->pc = 0x80199700u;
    // 80199700: rlwinm r0, r4, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_80199704:
    ctx->pc = 0x80199704u;
    // 80199704: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199708:
    ctx->pc = 0x80199708u;
    // 80199708: rlwinm r3, r0, 0, 27, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF1Fu;
    }

label_8019970C:
    ctx->pc = 0x8019970Cu;
    // 8019970C: rlwinm r0, r5, 5, 0, 26
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 5u) & 0xFFFFFFE0u;
    }

label_80199710:
    ctx->pc = 0x80199710u;
    // 80199710: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199714:
    ctx->pc = 0x80199714u;
    // 80199714: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80199718:
    ctx->pc = 0x80199718u;
    // 80199718: oris    r0, r0, 0x4100
    ctx->gpr[0] = ctx->gpr[0] | (0x4100u << 16);

label_8019971C:
    ctx->pc = 0x8019971Cu;
    // 8019971C: sth     r0, 0(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199720:
    ctx->pc = 0x80199720u;
    // 80199720: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199724:
    ctx->pc = 0x80199724u;
    ctx->downcount -= 7;
    // 80199724: lwz     r4, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199728:
    ctx->pc = 0x80199728u;
    // 80199728: rlwinm r0, r3, 3, 21, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 3u) & 0x000007F8u;
    }

label_8019972C:
    ctx->pc = 0x8019972Cu;
    // 8019972C: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80199730:
    ctx->pc = 0x80199730u;
    // 80199730: rlwinm r3, r3, 0, 29, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFF7u;
    }

label_80199734:
    ctx->pc = 0x80199734u;
    // 80199734: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199738:
    ctx->pc = 0x80199738u;
    // 80199738: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019973C:
    ctx->pc = 0x8019973Cu;
    // 8019973C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199740:
    ctx->pc = 0x80199740u;
    ctx->downcount -= 5;
    // 80199740: lwz     r5, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80199744:
    ctx->pc = 0x80199744u;
    // 80199744: rlwinm r0, r3, 8, 16, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x0000FF00u;
    }

label_80199748:
    ctx->pc = 0x80199748u;
    // 80199748: rlwimi r0, r4, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8019974C:
    ctx->pc = 0x8019974Cu;
    // 8019974C: sth     r0, 4(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199750:
    ctx->pc = 0x80199750u;
    // 80199750: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199754:
    ctx->pc = 0x80199754u;
    ctx->downcount -= 7;
    // 80199754: lwz     r4, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199758:
    ctx->pc = 0x80199758u;
    // 80199758: rlwinm r0, r3, 2, 22, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x000003FCu;
    }

label_8019975C:
    ctx->pc = 0x8019975Cu;
    // 8019975C: lhzu     r3, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[3] = mem_read16(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_80199760:
    ctx->pc = 0x80199760u;
    // 80199760: rlwinm r3, r3, 0, 30, 28
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFBu;
    }

label_80199764:
    ctx->pc = 0x80199764u;
    // 80199764: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199768:
    ctx->pc = 0x80199768u;
    // 80199768: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019976C:
    ctx->pc = 0x8019976Cu;
    // 8019976C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199770:
    ctx->pc = 0x80199770u;
    ctx->downcount -= 10;
    // 80199770: rlwinm r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
    }

label_80199774:
    ctx->pc = 0x80199774u;
    // 80199774: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199778:
    ctx->pc = 0x80199778u;
    // 80199778: rlwinm r6, r0, 0, 31, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF1u;
    }

label_8019977C:
    ctx->pc = 0x8019977Cu;
    // 8019977C: rlwinm r0, r4, 1, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 1u) & 0xFFFFFFFEu;
    }

label_80199780:
    ctx->pc = 0x80199780u;
    // 80199780: or   r0, r6, r0
    {
        ctx->gpr[0] = ctx->gpr[6] | ctx->gpr[0];
    }

label_80199784:
    ctx->pc = 0x80199784u;
    // 80199784: rlwinm r4, r0, 0, 28, 26
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFEFu;
    }

label_80199788:
    ctx->pc = 0x80199788u;
    // 80199788: rlwinm r0, r5, 4, 20, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 4u) & 0x00000FF0u;
    }

label_8019978C:
    ctx->pc = 0x8019978Cu;
    // 8019978C: or   r0, r4, r0
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[0];
    }

label_80199790:
    ctx->pc = 0x80199790u;
    // 80199790: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199794:
    ctx->pc = 0x80199794u;
    // 80199794: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199798:
    ctx->pc = 0x80199798u;
    ctx->downcount -= 9;
    // 80199798: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_8019979C:
    ctx->pc = 0x8019979Cu;
    // 8019979C: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_801997A0:
    ctx->pc = 0x801997A0u;
    // 801997A0: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_801997A4:
    ctx->pc = 0x801997A4u;
    // 801997A4: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_801997A8:
    ctx->pc = 0x801997A8u;
    // 801997A8: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801997AC:
    ctx->pc = 0x801997ACu;
    // 801997AC: rlwinm r3, r0, 0, 10, 7
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_801997B0:
    ctx->pc = 0x801997B0u;
    // 801997B0: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801997B4:
    ctx->pc = 0x801997B4u;
    // 801997B4: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801997B8:
    ctx->pc = 0x801997B8u;
    // 801997B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801997BC:
    ctx->pc = 0x801997BCu;
    ctx->downcount -= 8;
    // 801997BC: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_801997C0:
    ctx->pc = 0x801997C0u;
    // 801997C0: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_801997C4:
    ctx->pc = 0x801997C4u;
    // 801997C4: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_801997C8:
    ctx->pc = 0x801997C8u;
    // 801997C8: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_801997CC:
    ctx->pc = 0x801997CCu;
    // 801997CC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801997D0:
    ctx->pc = 0x801997D0u;
    // 801997D0: rlwinm r3, r0, 0, 10, 7
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_801997D4:
    ctx->pc = 0x801997D4u;
    // 801997D4: stw     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_801997D8:
    ctx->pc = 0x801997D8u;
    // 801997D8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801997DC:
    ctx->pc = 0x801997DCu;
    ctx->downcount -= 10;
    // 801997DC: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_801997E0:
    ctx->pc = 0x801997E0u;
    // 801997E0: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_801997E4:
    ctx->pc = 0x801997E4u;
    // 801997E4: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_801997E8:
    ctx->pc = 0x801997E8u;
    // 801997E8: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_801997EC:
    ctx->pc = 0x801997ECu;
    // 801997EC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_801997F0:
    ctx->pc = 0x801997F0u;
    // 801997F0: rlwinm r0, r0, 0, 10, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_801997F4:
    ctx->pc = 0x801997F4u;
    // 801997F4: oris    r3, r0, 0x0040
    ctx->gpr[3] = ctx->gpr[0] | (0x0040u << 16);

label_801997F8:
    ctx->pc = 0x801997F8u;
    // 801997F8: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801997FC:
    ctx->pc = 0x801997FCu;
    // 801997FC: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199800:
    ctx->pc = 0x80199800u;
    // 80199800: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199804:
    ctx->pc = 0x80199804u;
    ctx->downcount -= 9;
    // 80199804: rlwinm r0, r3, 2, 14, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0x0003FFFCu;
    }

label_80199808:
    ctx->pc = 0x80199808u;
    // 80199808: oris    r0, r0, 0xC800
    ctx->gpr[0] = ctx->gpr[0] | (0xC800u << 16);

label_8019980C:
    ctx->pc = 0x8019980Cu;
    // 8019980C: rlwinm r3, r0, 0, 20, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFC00FFFu;
    }

label_80199810:
    ctx->pc = 0x80199810u;
    // 80199810: rlwinm r0, r4, 12, 4, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0x0FFFF000u;
    }

label_80199814:
    ctx->pc = 0x80199814u;
    // 80199814: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199818:
    ctx->pc = 0x80199818u;
    // 80199818: rlwinm r0, r0, 0, 10, 7
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFF3FFFFFu;
    }

label_8019981C:
    ctx->pc = 0x8019981Cu;
    // 8019981C: oris    r3, r0, 0x0040
    ctx->gpr[3] = ctx->gpr[0] | (0x0040u << 16);

label_80199820:
    ctx->pc = 0x80199820u;
    // 80199820: stw     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80199824:
    ctx->pc = 0x80199824u;
    // 80199824: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199828:
    ctx->pc = 0x80199828u;
    ctx->downcount -= 8;
    // 80199828: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8019982C:
    ctx->pc = 0x8019982Cu;
    // 8019982C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199830:
    ctx->pc = 0x80199830u;
    // 80199830: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199834:
    ctx->pc = 0x80199834u;
    // 80199834: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199838:
    ctx->pc = 0x80199838u;
    // 80199838: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8019983C:
    ctx->pc = 0x8019983Cu;
    // 8019983C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80199840:
    ctx->pc = 0x80199840u;
    // 80199840: lwz     r31, -26096(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26096);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199844:
    ctx->pc = 0x80199844u;
    // 80199844: bl      0x80173F2C
    {
            ctx->lr = 0x80199848u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80199848:
    ctx->pc = 0x80199848u;
    ctx->downcount -= 2;
    // 80199848: stw     r30, -26096(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26096);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8019984C:
    ctx->pc = 0x8019984Cu;
    // 8019984C: bl      0x80173F54
    {
            ctx->lr = 0x80199850u;
            ctx->pc = 0x80173F54u;
            return;
    }

label_80199850:
    ctx->pc = 0x80199850u;
    ctx->downcount -= 8;
    // 80199850: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80199854:
    ctx->pc = 0x80199854u;
    // 80199854: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199858:
    ctx->pc = 0x80199858u;
    // 80199858: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019985C:
    ctx->pc = 0x8019985Cu;
    // 8019985C: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80199860:
    ctx->pc = 0x80199860u;
    // 80199860: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80199864:
    ctx->pc = 0x80199864u;
    // 80199864: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199868:
    ctx->pc = 0x80199868u;
    // 80199868: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019986C:
    ctx->pc = 0x8019986Cu;
    ctx->downcount -= 11;
    // 8019986C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199870:
    ctx->pc = 0x80199870u;
    // 80199870: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199874:
    ctx->pc = 0x80199874u;
    // 80199874: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199878:
    ctx->pc = 0x80199878u;
    // 80199878: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019987C:
    ctx->pc = 0x8019987Cu;
    // 8019987C: stw     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80199880:
    ctx->pc = 0x80199880u;
    // 80199880: or   r30, r4, r4
    {
        ctx->gpr[30] = ctx->gpr[4] | ctx->gpr[4];
    }

label_80199884:
    ctx->pc = 0x80199884u;
    // 80199884: lwz     r0, -26096(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26096);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199888:
    ctx->pc = 0x80199888u;
    // 80199888: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019988C:
    ctx->pc = 0x8019988Cu;
    // 8019988C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199890:
    ctx->pc = 0x80199890u;
    // 80199890: lhz     r31, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[31] = mem_read16(ctx, ea);
    }

label_80199894:
    ctx->pc = 0x80199894u;
    // 80199894: bc    12, 2, 0x801998C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801998C8;
        }
    }

label_80199898:
    ctx->pc = 0x80199898u;
    ctx->downcount -= 2;
    // 80199898: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_8019989C:
    ctx->pc = 0x8019989Cu;
    // 8019989C: bl      0x8017248C
    {
            ctx->lr = 0x801998A0u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_801998A0:
    ctx->pc = 0x801998A0u;
    ctx->downcount -= 2;
    // 801998A0: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801998A4:
    ctx->pc = 0x801998A4u;
    // 801998A4: bl      0x80172284
    {
            ctx->lr = 0x801998A8u;
            ctx->pc = 0x80172284u;
            return;
    }

label_801998A8:
    ctx->pc = 0x801998A8u;
    ctx->downcount -= 5;
    // 801998A8: lwz     r12, -26096(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26096);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_801998AC:
    ctx->pc = 0x801998ACu;
    // 801998AC: addi    r3, r31, 0
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(0);

label_801998B0:
    ctx->pc = 0x801998B0u;
    // 801998B0: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_801998B4:
    ctx->pc = 0x801998B4u;
    // 801998B4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x801998B8u;
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801998B8:
    ctx->pc = 0x801998B8u;
    ctx->downcount -= 2;
    // 801998B8: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_801998BC:
    ctx->pc = 0x801998BCu;
    // 801998BC: bl      0x8017248C
    {
            ctx->lr = 0x801998C0u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_801998C0:
    ctx->pc = 0x801998C0u;
    ctx->downcount -= 2;
    // 801998C0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_801998C4:
    ctx->pc = 0x801998C4u;
    // 801998C4: bl      0x80172284
    {
            ctx->lr = 0x801998C8u;
            ctx->pc = 0x80172284u;
            return;
    }

label_801998C8:
    ctx->pc = 0x801998C8u;
    ctx->downcount -= 12;
    // 801998C8: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_801998CC:
    ctx->pc = 0x801998CCu;
    // 801998CC: lhzu     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_801998D0:
    ctx->pc = 0x801998D0u;
    // 801998D0: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_801998D4:
    ctx->pc = 0x801998D4u;
    // 801998D4: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_801998D8:
    ctx->pc = 0x801998D8u;
    // 801998D8: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_801998DC:
    ctx->pc = 0x801998DCu;
    // 801998DC: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801998E0:
    ctx->pc = 0x801998E0u;
    // 801998E0: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801998E4:
    ctx->pc = 0x801998E4u;
    // 801998E4: lwz     r30, 728(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(728);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_801998E8:
    ctx->pc = 0x801998E8u;
    // 801998E8: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_801998EC:
    ctx->pc = 0x801998ECu;
    // 801998EC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801998F0:
    ctx->pc = 0x801998F0u;
    // 801998F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801998F4:
    ctx->pc = 0x801998F4u;
    ctx->downcount -= 8;
    // 801998F4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801998F8:
    ctx->pc = 0x801998F8u;
    // 801998F8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801998FC:
    ctx->pc = 0x801998FCu;
    // 801998FC: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199900:
    ctx->pc = 0x80199900u;
    // 80199900: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199904:
    ctx->pc = 0x80199904u;
    // 80199904: stw     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80199908:
    ctx->pc = 0x80199908u;
    // 80199908: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019990C:
    ctx->pc = 0x8019990Cu;
    // 8019990C: lwz     r31, -26092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26092);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199910:
    ctx->pc = 0x80199910u;
    // 80199910: bl      0x80173F2C
    {
            ctx->lr = 0x80199914u;
            ctx->pc = 0x80173F2Cu;
            return;
    }

label_80199914:
    ctx->pc = 0x80199914u;
    ctx->downcount -= 2;
    // 80199914: stw     r30, -26092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26092);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80199918:
    ctx->pc = 0x80199918u;
    // 80199918: bl      0x80173F54
    {
            ctx->lr = 0x8019991Cu;
            ctx->pc = 0x80173F54u;
            return;
    }

label_8019991C:
    ctx->pc = 0x8019991Cu;
    ctx->downcount -= 8;
    // 8019991C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80199920:
    ctx->pc = 0x80199920u;
    // 80199920: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199924:
    ctx->pc = 0x80199924u;
    // 80199924: lwz     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199928:
    ctx->pc = 0x80199928u;
    // 80199928: lwz     r30, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8019992C:
    ctx->pc = 0x8019992Cu;
    // 8019992C: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_80199930:
    ctx->pc = 0x80199930u;
    // 80199930: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199934:
    ctx->pc = 0x80199934u;
    // 80199934: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199938:
    ctx->pc = 0x80199938u;
    ctx->downcount -= 15;
    // 80199938: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8019993C:
    ctx->pc = 0x8019993Cu;
    // 8019993C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80199940:
    ctx->pc = 0x80199940u;
    // 80199940: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199944:
    ctx->pc = 0x80199944u;
    // 80199944: stwu     r1, -736(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-736);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199948:
    ctx->pc = 0x80199948u;
    // 80199948: stw     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019994C:
    ctx->pc = 0x8019994Cu;
    // 8019994C: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_80199950:
    ctx->pc = 0x80199950u;
    // 80199950: lwz     r5, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80199954:
    ctx->pc = 0x80199954u;
    // 80199954: lhz     r0, 10(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_80199958:
    ctx->pc = 0x80199958u;
    // 80199958: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_8019995C:
    ctx->pc = 0x8019995Cu;
    // 8019995C: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80199960:
    ctx->pc = 0x80199960u;
    // 80199960: sth     r0, 10(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199964:
    ctx->pc = 0x80199964u;
    // 80199964: lwz     r0, -26092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26092);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199968:
    ctx->pc = 0x80199968u;
    // 80199968: stb     r3, -26088(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26088);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_8019996C:
    ctx->pc = 0x8019996Cu;
    // 8019996C: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199970:
    ctx->pc = 0x80199970u;
    // 80199970: bc    12, 2, 0x801999A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_801999A0;
        }
    }

label_80199974:
    ctx->pc = 0x80199974u;
    ctx->downcount -= 2;
    // 80199974: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80199978:
    ctx->pc = 0x80199978u;
    // 80199978: bl      0x8017248C
    {
            ctx->lr = 0x8019997Cu;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_8019997C:
    ctx->pc = 0x8019997Cu;
    ctx->downcount -= 2;
    // 8019997C: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80199980:
    ctx->pc = 0x80199980u;
    // 80199980: bl      0x80172284
    {
            ctx->lr = 0x80199984u;
            ctx->pc = 0x80172284u;
            return;
    }

label_80199984:
    ctx->pc = 0x80199984u;
    ctx->downcount -= 4;
    // 80199984: lwz     r12, -26092(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26092);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_80199988:
    ctx->pc = 0x80199988u;
    // 80199988: mtlr    r12
    ctx->lr = ctx->gpr[12];

label_8019998C:
    ctx->pc = 0x8019998Cu;
    // 8019998C: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x80199990u;
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199990:
    ctx->pc = 0x80199990u;
    ctx->downcount -= 2;
    // 80199990: addi    r3, r1, 16
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(16);

label_80199994:
    ctx->pc = 0x80199994u;
    // 80199994: bl      0x8017248C
    {
            ctx->lr = 0x80199998u;
            ctx->pc = 0x8017248Cu;
            return;
    }

label_80199998:
    ctx->pc = 0x80199998u;
    ctx->downcount -= 2;
    // 80199998: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_8019999C:
    ctx->pc = 0x8019999Cu;
    // 8019999C: bl      0x80172284
    {
            ctx->lr = 0x801999A0u;
            ctx->pc = 0x80172284u;
            return;
    }

label_801999A0:
    ctx->pc = 0x801999A0u;
    ctx->downcount -= 2;
    // 801999A0: addi    r3, r13, -26084
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26084);

label_801999A4:
    ctx->pc = 0x801999A4u;
    // 801999A4: bl      0x80179564
    {
            ctx->lr = 0x801999A8u;
            ctx->pc = 0x80179564u;
            return;
    }

label_801999A8:
    ctx->pc = 0x801999A8u;
    ctx->downcount -= 6;
    // 801999A8: lwz     r0, 740(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(740);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_801999AC:
    ctx->pc = 0x801999ACu;
    // 801999AC: lwz     r31, 732(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(732);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_801999B0:
    ctx->pc = 0x801999B0u;
    // 801999B0: addi    r1, r1, 736
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(736);

label_801999B4:
    ctx->pc = 0x801999B4u;
    // 801999B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_801999B8:
    ctx->pc = 0x801999B8u;
    // 801999B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_801999BC:
    ctx->pc = 0x801999BCu;
    ctx->downcount -= 7;
    // 801999BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_801999C0:
    ctx->pc = 0x801999C0u;
    // 801999C0: lis     r3, -32742
    ctx->gpr[3] = ((u32)(s32)(-32742) << 16);

label_801999C4:
    ctx->pc = 0x801999C4u;
    // 801999C4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_801999C8:
    ctx->pc = 0x801999C8u;
    // 801999C8: addi    r4, r3, -26516
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-26516);

label_801999CC:
    ctx->pc = 0x801999CCu;
    // 801999CC: li      r3, 18
    ctx->gpr[3] = (u32)(s32)(18);

label_801999D0:
    ctx->pc = 0x801999D0u;
    // 801999D0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_801999D4:
    ctx->pc = 0x801999D4u;
    // 801999D4: bl      0x80173F78
    {
            ctx->lr = 0x801999D8u;
            ctx->pc = 0x80173F78u;
            return;
    }

label_801999D8:
    ctx->pc = 0x801999D8u;
    ctx->downcount -= 4;
    // 801999D8: lis     r3, -32742
    ctx->gpr[3] = ((u32)(s32)(-32742) << 16);

label_801999DC:
    ctx->pc = 0x801999DCu;
    // 801999DC: addi    r4, r3, -26312
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(-26312);

label_801999E0:
    ctx->pc = 0x801999E0u;
    // 801999E0: li      r3, 19
    ctx->gpr[3] = (u32)(s32)(19);

label_801999E4:
    ctx->pc = 0x801999E4u;
    // 801999E4: bl      0x80173F78
    {
            ctx->lr = 0x801999E8u;
            ctx->pc = 0x80173F78u;
            return;
    }

label_801999E8:
    ctx->pc = 0x801999E8u;
    ctx->downcount -= 2;
    // 801999E8: addi    r3, r13, -26084
    ctx->gpr[3] = ctx->gpr[13] + (u32)(s32)(-26084);

label_801999EC:
    ctx->pc = 0x801999ECu;
    // 801999EC: bl      0x8017836C
    {
            ctx->lr = 0x801999F0u;
            ctx->pc = 0x8017836Cu;
            return;
    }

label_801999F0:
    ctx->pc = 0x801999F0u;
    ctx->downcount -= 2;
    // 801999F0: li      r3, 8192
    ctx->gpr[3] = (u32)(s32)(8192);

label_801999F4:
    ctx->pc = 0x801999F4u;
    // 801999F4: bl      0x80174418
    {
            ctx->lr = 0x801999F8u;
            ctx->pc = 0x80174418u;
            return;
    }

label_801999F8:
    ctx->pc = 0x801999F8u;
    ctx->downcount -= 2;
    // 801999F8: li      r3, 4096
    ctx->gpr[3] = (u32)(s32)(4096);

label_801999FC:
    ctx->pc = 0x801999FCu;
    // 801999FC: bl      0x80174418
    {
            ctx->lr = 0x80199A00u;
            ctx->pc = 0x80174418u;
            return;
    }

label_80199A00:
    ctx->pc = 0x80199A00u;
    ctx->downcount -= 16;
    // 80199A00: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199A04:
    ctx->pc = 0x80199A04u;
    // 80199A04: lhzu     r0, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[0] = mem_read16(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_80199A08:
    ctx->pc = 0x80199A08u;
    // 80199A08: rlwinm r0, r0, 0, 30, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFBu;
    }

label_80199A0C:
    ctx->pc = 0x80199A0Cu;
    // 80199A0C: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_80199A10:
    ctx->pc = 0x80199A10u;
    // 80199A10: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_80199A14:
    ctx->pc = 0x80199A14u;
    // 80199A14: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_80199A18:
    ctx->pc = 0x80199A18u;
    // 80199A18: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_80199A1C:
    ctx->pc = 0x80199A1Cu;
    // 80199A1C: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_80199A20:
    ctx->pc = 0x80199A20u;
    // 80199A20: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_80199A24:
    ctx->pc = 0x80199A24u;
    // 80199A24: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_80199A28:
    ctx->pc = 0x80199A28u;
    // 80199A28: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199A2C:
    ctx->pc = 0x80199A2Cu;
    // 80199A2C: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199A30:
    ctx->pc = 0x80199A30u;
    // 80199A30: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80199A34:
    ctx->pc = 0x80199A34u;
    // 80199A34: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199A38:
    ctx->pc = 0x80199A38u;
    // 80199A38: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199A3C:
    ctx->pc = 0x80199A3Cu;
    ctx->downcount -= 9;
    // 80199A3C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199A40:
    ctx->pc = 0x80199A40u;
    // 80199A40: cmpwi   r4, 2
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199A44:
    ctx->pc = 0x80199A44u;
    // 80199A44: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199A48:
    ctx->pc = 0x80199A48u;
    // 80199A48: rlwinm r0, r3, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_80199A4C:
    ctx->pc = 0x80199A4Cu;
    // 80199A4C: nor   r0, r0, r0
    {
        ctx->gpr[0] = ~(ctx->gpr[0] | ctx->gpr[0]);
    }

label_80199A50:
    ctx->pc = 0x80199A50u;
    // 80199A50: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199A54:
    ctx->pc = 0x80199A54u;
    // 80199A54: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_80199A58:
    ctx->pc = 0x80199A58u;
    // 80199A58: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199A5C:
    ctx->pc = 0x80199A5Cu;
    // 80199A5C: bc    12, 2, 0x80199AC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199AC4;
        }
    }

label_80199A60:
    ctx->pc = 0x80199A60u;
    ctx->downcount -= 1;
    // 80199A60: bc    4, 0, 0x80199A74
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199A74;
        }
    }

label_80199A64:
    ctx->pc = 0x80199A64u;
    ctx->downcount -= 2;
    // 80199A64: cmpwi   r4, 0
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

label_80199A68:
    ctx->pc = 0x80199A68u;
    // 80199A68: bc    12, 2, 0x80199A80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199A80;
        }
    }

label_80199A6C:
    ctx->pc = 0x80199A6Cu;
    ctx->downcount -= 1;
    // 80199A6C: bc    4, 0, 0x80199A88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199A88;
        }
    }

label_80199A70:
    ctx->pc = 0x80199A70u;
    ctx->downcount -= 1;
    // 80199A70: b       0x80199B3C
    {
            goto label_80199B3C;
    }

label_80199A74:
    ctx->pc = 0x80199A74u;
    ctx->downcount -= 2;
    // 80199A74: cmpwi   r4, 4
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199A78:
    ctx->pc = 0x80199A78u;
    // 80199A78: bc    4, 0, 0x80199B3C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199B3C;
        }
    }

label_80199A7C:
    ctx->pc = 0x80199A7Cu;
    ctx->downcount -= 1;
    // 80199A7C: b       0x80199B00
    {
            goto label_80199B00;
    }

label_80199A80:
    ctx->pc = 0x80199A80u;
    ctx->downcount -= 2;
    // 80199A80: rlwinm r31, r3, 24, 16, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[3], 24u) & 0x0000FFFFu;
    }

label_80199A84:
    ctx->pc = 0x80199A84u;
    // 80199A84: b       0x80199B58
    {
            goto label_80199B58;
    }

label_80199A88:
    ctx->pc = 0x80199A88u;
    ctx->downcount -= 2;
    // 80199A88: cmpwi   r0, 3
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

label_80199A8C:
    ctx->pc = 0x80199A8Cu;
    // 80199A8C: bc    4, 1, 0x80199A98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199A98;
        }
    }

label_80199A90:
    ctx->pc = 0x80199A90u;
    ctx->downcount -= 2;
    // 80199A90: li      r4, 3
    ctx->gpr[4] = (u32)(s32)(3);

label_80199A94:
    ctx->pc = 0x80199A94u;
    // 80199A94: b       0x80199A9C
    {
            goto label_80199A9C;
    }

label_80199A98:
    ctx->pc = 0x80199A98u;
    ctx->downcount -= 1;
    // 80199A98: or   r4, r0, r0
    {
        ctx->gpr[4] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80199A9C:
    ctx->pc = 0x80199A9Cu;
    ctx->downcount -= 2;
    // 80199A9C: cmpwi   r4, 3
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199AA0:
    ctx->pc = 0x80199AA0u;
    // 80199AA0: bc    4, 2, 0x80199AAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199AAC;
        }
    }

label_80199AA4:
    ctx->pc = 0x80199AA4u;
    ctx->downcount -= 2;
    // 80199AA4: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_80199AA8:
    ctx->pc = 0x80199AA8u;
    // 80199AA8: b       0x80199AB0
    {
            goto label_80199AB0;
    }

label_80199AAC:
    ctx->pc = 0x80199AACu;
    ctx->downcount -= 1;
    // 80199AAC: subfic  r0, r4, 9
    {
        u64 res = (u64)(u32)(s32)(9) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199AB0:
    ctx->pc = 0x80199AB0u;
    ctx->downcount -= 5;
    // 80199AB0: srw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_80199AB4:
    ctx->pc = 0x80199AB4u;
    // 80199AB4: rlwinm r0, r0, 0, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00003FFFu;
    }

label_80199AB8:
    ctx->pc = 0x80199AB8u;
    // 80199AB8: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80199ABC:
    ctx->pc = 0x80199ABCu;
    // 80199ABC: rlwimi r31, r4, 14, 0, 17
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 14u);
        ctx->gpr[31] = (ctx->gpr[31] & ~0xFFFFC000u) | (rot & 0xFFFFC000u);
    }

label_80199AC0:
    ctx->pc = 0x80199AC0u;
    // 80199AC0: b       0x80199B58
    {
            goto label_80199B58;
    }

label_80199AC4:
    ctx->pc = 0x80199AC4u;
    ctx->downcount -= 2;
    // 80199AC4: cmpwi   r0, 7
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

label_80199AC8:
    ctx->pc = 0x80199AC8u;
    // 80199AC8: bc    4, 1, 0x80199AD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199AD4;
        }
    }

label_80199ACC:
    ctx->pc = 0x80199ACCu;
    ctx->downcount -= 2;
    // 80199ACC: li      r4, 7
    ctx->gpr[4] = (u32)(s32)(7);

label_80199AD0:
    ctx->pc = 0x80199AD0u;
    // 80199AD0: b       0x80199AD8
    {
            goto label_80199AD8;
    }

label_80199AD4:
    ctx->pc = 0x80199AD4u;
    ctx->downcount -= 1;
    // 80199AD4: or   r4, r0, r0
    {
        ctx->gpr[4] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80199AD8:
    ctx->pc = 0x80199AD8u;
    ctx->downcount -= 2;
    // 80199AD8: cmpwi   r4, 7
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199ADC:
    ctx->pc = 0x80199ADCu;
    // 80199ADC: bc    4, 2, 0x80199AE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199AE8;
        }
    }

label_80199AE0:
    ctx->pc = 0x80199AE0u;
    ctx->downcount -= 2;
    // 80199AE0: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_80199AE4:
    ctx->pc = 0x80199AE4u;
    // 80199AE4: b       0x80199AEC
    {
            goto label_80199AEC;
    }

label_80199AE8:
    ctx->pc = 0x80199AE8u;
    ctx->downcount -= 1;
    // 80199AE8: subfic  r0, r4, 10
    {
        u64 res = (u64)(u32)(s32)(10) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199AEC:
    ctx->pc = 0x80199AECu;
    ctx->downcount -= 5;
    // 80199AEC: srw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_80199AF0:
    ctx->pc = 0x80199AF0u;
    // 80199AF0: rlwinm r0, r0, 0, 19, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00001FFFu;
    }

label_80199AF4:
    ctx->pc = 0x80199AF4u;
    // 80199AF4: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80199AF8:
    ctx->pc = 0x80199AF8u;
    // 80199AF8: rlwimi r31, r4, 13, 0, 18
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 13u);
        ctx->gpr[31] = (ctx->gpr[31] & ~0xFFFFE000u) | (rot & 0xFFFFE000u);
    }

label_80199AFC:
    ctx->pc = 0x80199AFCu;
    // 80199AFC: b       0x80199B58
    {
            goto label_80199B58;
    }

label_80199B00:
    ctx->pc = 0x80199B00u;
    ctx->downcount -= 2;
    // 80199B00: cmpwi   r0, 12
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

label_80199B04:
    ctx->pc = 0x80199B04u;
    // 80199B04: bc    4, 1, 0x80199B10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199B10;
        }
    }

label_80199B08:
    ctx->pc = 0x80199B08u;
    ctx->downcount -= 2;
    // 80199B08: li      r4, 12
    ctx->gpr[4] = (u32)(s32)(12);

label_80199B0C:
    ctx->pc = 0x80199B0Cu;
    // 80199B0C: b       0x80199B14
    {
            goto label_80199B14;
    }

label_80199B10:
    ctx->pc = 0x80199B10u;
    ctx->downcount -= 1;
    // 80199B10: or   r4, r0, r0
    {
        ctx->gpr[4] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80199B14:
    ctx->pc = 0x80199B14u;
    ctx->downcount -= 2;
    // 80199B14: cmpwi   r4, 12
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(12);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199B18:
    ctx->pc = 0x80199B18u;
    // 80199B18: bc    4, 2, 0x80199B24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199B24;
        }
    }

label_80199B1C:
    ctx->pc = 0x80199B1Cu;
    ctx->downcount -= 2;
    // 80199B1C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199B20:
    ctx->pc = 0x80199B20u;
    // 80199B20: b       0x80199B28
    {
            goto label_80199B28;
    }

label_80199B24:
    ctx->pc = 0x80199B24u;
    ctx->downcount -= 1;
    // 80199B24: subfic  r0, r4, 11
    {
        u64 res = (u64)(u32)(s32)(11) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199B28:
    ctx->pc = 0x80199B28u;
    ctx->downcount -= 5;
    // 80199B28: srw   r0, r3, r0
    {
        u32 sh = ctx->gpr[0] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[3] >> sh);
    }

label_80199B2C:
    ctx->pc = 0x80199B2Cu;
    // 80199B2C: rlwinm r0, r0, 0, 20, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000FFFu;
    }

label_80199B30:
    ctx->pc = 0x80199B30u;
    // 80199B30: or   r31, r0, r0
    {
        ctx->gpr[31] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80199B34:
    ctx->pc = 0x80199B34u;
    // 80199B34: rlwimi r31, r4, 12, 0, 19
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 12u);
        ctx->gpr[31] = (ctx->gpr[31] & ~0xFFFFF000u) | (rot & 0xFFFFF000u);
    }

label_80199B38:
    ctx->pc = 0x80199B38u;
    // 80199B38: b       0x80199B58
    {
            goto label_80199B58;
    }

label_80199B3C:
    ctx->pc = 0x80199B3Cu;
    ctx->downcount -= 7;
    // 80199B3C: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_80199B40:
    ctx->pc = 0x80199B40u;
    // 80199B40: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80199B44:
    ctx->pc = 0x80199B44u;
    // 80199B44: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80199B48:
    ctx->pc = 0x80199B48u;
    // 80199B48: addi    r5, r4, -3588
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(-3588);

label_80199B4C:
    ctx->pc = 0x80199B4Cu;
    // 80199B4C: addi    r3, r3, -3600
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-3600);

label_80199B50:
    ctx->pc = 0x80199B50u;
    // 80199B50: li      r4, 953
    ctx->gpr[4] = (u32)(s32)(953);

label_80199B54:
    ctx->pc = 0x80199B54u;
    // 80199B54: bl      0x80172A8C
    {
            ctx->lr = 0x80199B58u;
            ctx->pc = 0x80172A8Cu;
            return;
    }

label_80199B58:
    ctx->pc = 0x80199B58u;
    ctx->downcount -= 7;
    // 80199B58: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80199B5C:
    ctx->pc = 0x80199B5Cu;
    // 80199B5C: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199B60:
    ctx->pc = 0x80199B60u;
    // 80199B60: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199B64:
    ctx->pc = 0x80199B64u;
    // 80199B64: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80199B68:
    ctx->pc = 0x80199B68u;
    // 80199B68: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199B6C:
    ctx->pc = 0x80199B6Cu;
    // 80199B6C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199B70:
    ctx->pc = 0x80199B70u;
    ctx->downcount -= 6;
    // 80199B70: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199B74:
    ctx->pc = 0x80199B74u;
    // 80199B74: cmpwi   r4, 2
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199B78:
    ctx->pc = 0x80199B78u;
    // 80199B78: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199B7C:
    ctx->pc = 0x80199B7Cu;
    // 80199B7C: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199B80:
    ctx->pc = 0x80199B80u;
    // 80199B80: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199B84:
    ctx->pc = 0x80199B84u;
    // 80199B84: bc    12, 2, 0x80199BE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199BE8;
        }
    }

label_80199B88:
    ctx->pc = 0x80199B88u;
    ctx->downcount -= 1;
    // 80199B88: bc    4, 0, 0x80199B9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199B9C;
        }
    }

label_80199B8C:
    ctx->pc = 0x80199B8Cu;
    ctx->downcount -= 2;
    // 80199B8C: cmpwi   r4, 0
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

label_80199B90:
    ctx->pc = 0x80199B90u;
    // 80199B90: bc    12, 2, 0x80199BA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199BA8;
        }
    }

label_80199B94:
    ctx->pc = 0x80199B94u;
    ctx->downcount -= 1;
    // 80199B94: bc    4, 0, 0x80199BB0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199BB0;
        }
    }

label_80199B98:
    ctx->pc = 0x80199B98u;
    ctx->downcount -= 1;
    // 80199B98: b       0x80199C58
    {
            goto label_80199C58;
    }

label_80199B9C:
    ctx->pc = 0x80199B9Cu;
    ctx->downcount -= 2;
    // 80199B9C: cmpwi   r4, 4
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199BA0:
    ctx->pc = 0x80199BA0u;
    // 80199BA0: bc    4, 0, 0x80199C58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199C58;
        }
    }

label_80199BA4:
    ctx->pc = 0x80199BA4u;
    ctx->downcount -= 1;
    // 80199BA4: b       0x80199C20
    {
            goto label_80199C20;
    }

label_80199BA8:
    ctx->pc = 0x80199BA8u;
    ctx->downcount -= 2;
    // 80199BA8: rlwinm r31, r3, 8, 8, 23
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0x00FFFF00u;
    }

label_80199BAC:
    ctx->pc = 0x80199BACu;
    // 80199BAC: b       0x80199C74
    {
            goto label_80199C74;
    }

label_80199BB0:
    ctx->pc = 0x80199BB0u;
    ctx->downcount -= 3;
    // 80199BB0: rlwinm r4, r3, 18, 30, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 18u) & 0x00000003u;
    }

label_80199BB4:
    ctx->pc = 0x80199BB4u;
    // 80199BB4: cmpwi   r4, 3
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199BB8:
    ctx->pc = 0x80199BB8u;
    // 80199BB8: bc    4, 2, 0x80199BC4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199BC4;
        }
    }

label_80199BBC:
    ctx->pc = 0x80199BBCu;
    ctx->downcount -= 2;
    // 80199BBC: li      r5, 7
    ctx->gpr[5] = (u32)(s32)(7);

label_80199BC0:
    ctx->pc = 0x80199BC0u;
    // 80199BC0: b       0x80199BC8
    {
            goto label_80199BC8;
    }

label_80199BC4:
    ctx->pc = 0x80199BC4u;
    ctx->downcount -= 1;
    // 80199BC4: subfic  r5, r4, 9
    {
        u64 res = (u64)(u32)(s32)(9) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199BC8:
    ctx->pc = 0x80199BC8u;
    ctx->downcount -= 8;
    // 80199BC8: rlwinm r0, r3, 0, 18, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00003FFFu;
    }

label_80199BCC:
    ctx->pc = 0x80199BCCu;
    // 80199BCC: subfic  r3, r4, 24
    {
        u64 res = (u64)(u32)(s32)(24) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199BD0:
    ctx->pc = 0x80199BD0u;
    // 80199BD0: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80199BD4:
    ctx->pc = 0x80199BD4u;
    // 80199BD4: slw   r3, r4, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[4] << sh);
    }

label_80199BD8:
    ctx->pc = 0x80199BD8u;
    // 80199BD8: slw   r0, r0, r5
    {
        u32 sh = ctx->gpr[5] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_80199BDC:
    ctx->pc = 0x80199BDCu;
    // 80199BDC: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199BE0:
    ctx->pc = 0x80199BE0u;
    // 80199BE0: rlwinm r31, r0, 0, 8, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80199BE4:
    ctx->pc = 0x80199BE4u;
    // 80199BE4: b       0x80199C74
    {
            goto label_80199C74;
    }

label_80199BE8:
    ctx->pc = 0x80199BE8u;
    ctx->downcount -= 3;
    // 80199BE8: rlwinm r4, r3, 19, 29, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 19u) & 0x00000007u;
    }

label_80199BEC:
    ctx->pc = 0x80199BECu;
    // 80199BEC: cmpwi   r4, 7
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199BF0:
    ctx->pc = 0x80199BF0u;
    // 80199BF0: bc    4, 2, 0x80199BFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199BFC;
        }
    }

label_80199BF4:
    ctx->pc = 0x80199BF4u;
    ctx->downcount -= 2;
    // 80199BF4: li      r5, 4
    ctx->gpr[5] = (u32)(s32)(4);

label_80199BF8:
    ctx->pc = 0x80199BF8u;
    // 80199BF8: b       0x80199C00
    {
            goto label_80199C00;
    }

label_80199BFC:
    ctx->pc = 0x80199BFCu;
    ctx->downcount -= 1;
    // 80199BFC: subfic  r5, r4, 10
    {
        u64 res = (u64)(u32)(s32)(10) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199C00:
    ctx->pc = 0x80199C00u;
    ctx->downcount -= 8;
    // 80199C00: rlwinm r0, r3, 0, 19, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00001FFFu;
    }

label_80199C04:
    ctx->pc = 0x80199C04u;
    // 80199C04: subfic  r3, r4, 24
    {
        u64 res = (u64)(u32)(s32)(24) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199C08:
    ctx->pc = 0x80199C08u;
    // 80199C08: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80199C0C:
    ctx->pc = 0x80199C0Cu;
    // 80199C0C: slw   r3, r4, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[4] << sh);
    }

label_80199C10:
    ctx->pc = 0x80199C10u;
    // 80199C10: slw   r0, r0, r5
    {
        u32 sh = ctx->gpr[5] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_80199C14:
    ctx->pc = 0x80199C14u;
    // 80199C14: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199C18:
    ctx->pc = 0x80199C18u;
    // 80199C18: rlwinm r31, r0, 0, 8, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80199C1C:
    ctx->pc = 0x80199C1Cu;
    // 80199C1C: b       0x80199C74
    {
            goto label_80199C74;
    }

label_80199C20:
    ctx->pc = 0x80199C20u;
    ctx->downcount -= 3;
    // 80199C20: rlwinm r4, r3, 20, 28, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 20u) & 0x0000000Fu;
    }

label_80199C24:
    ctx->pc = 0x80199C24u;
    // 80199C24: cmpwi   r4, 12
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(12);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199C28:
    ctx->pc = 0x80199C28u;
    // 80199C28: bc    4, 2, 0x80199C34
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199C34;
        }
    }

label_80199C2C:
    ctx->pc = 0x80199C2Cu;
    ctx->downcount -= 2;
    // 80199C2C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_80199C30:
    ctx->pc = 0x80199C30u;
    // 80199C30: b       0x80199C38
    {
            goto label_80199C38;
    }

label_80199C34:
    ctx->pc = 0x80199C34u;
    ctx->downcount -= 1;
    // 80199C34: subfic  r5, r4, 11
    {
        u64 res = (u64)(u32)(s32)(11) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[5] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199C38:
    ctx->pc = 0x80199C38u;
    ctx->downcount -= 8;
    // 80199C38: rlwinm r0, r3, 0, 20, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000FFFu;
    }

label_80199C3C:
    ctx->pc = 0x80199C3Cu;
    // 80199C3C: subfic  r3, r4, 24
    {
        u64 res = (u64)(u32)(s32)(24) + (u64)(~ctx->gpr[4]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_80199C40:
    ctx->pc = 0x80199C40u;
    // 80199C40: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_80199C44:
    ctx->pc = 0x80199C44u;
    // 80199C44: slw   r3, r4, r3
    {
        u32 sh = ctx->gpr[3] & 0x3Fu;
        ctx->gpr[3] = sh > 31 ? 0u : (ctx->gpr[4] << sh);
    }

label_80199C48:
    ctx->pc = 0x80199C48u;
    // 80199C48: slw   r0, r0, r5
    {
        u32 sh = ctx->gpr[5] & 0x3Fu;
        ctx->gpr[0] = sh > 31 ? 0u : (ctx->gpr[0] << sh);
    }

label_80199C4C:
    ctx->pc = 0x80199C4Cu;
    // 80199C4C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199C50:
    ctx->pc = 0x80199C50u;
    // 80199C50: rlwinm r31, r0, 0, 8, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_80199C54:
    ctx->pc = 0x80199C54u;
    // 80199C54: b       0x80199C74
    {
            goto label_80199C74;
    }

label_80199C58:
    ctx->pc = 0x80199C58u;
    ctx->downcount -= 7;
    // 80199C58: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_80199C5C:
    ctx->pc = 0x80199C5Cu;
    // 80199C5C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80199C60:
    ctx->pc = 0x80199C60u;
    // 80199C60: lis     r4, -32732
    ctx->gpr[4] = ((u32)(s32)(-32732) << 16);

label_80199C64:
    ctx->pc = 0x80199C64u;
    // 80199C64: addi    r5, r4, -3552
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(-3552);

label_80199C68:
    ctx->pc = 0x80199C68u;
    // 80199C68: addi    r3, r3, -3600
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-3600);

label_80199C6C:
    ctx->pc = 0x80199C6Cu;
    // 80199C6C: li      r4, 1003
    ctx->gpr[4] = (u32)(s32)(1003);

label_80199C70:
    ctx->pc = 0x80199C70u;
    // 80199C70: bl      0x80172A8C
    {
            ctx->lr = 0x80199C74u;
            ctx->pc = 0x80172A8Cu;
            return;
    }

label_80199C74:
    ctx->pc = 0x80199C74u;
    ctx->downcount -= 7;
    // 80199C74: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80199C78:
    ctx->pc = 0x80199C78u;
    // 80199C78: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199C7C:
    ctx->pc = 0x80199C7Cu;
    // 80199C7C: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199C80:
    ctx->pc = 0x80199C80u;
    // 80199C80: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_80199C84:
    ctx->pc = 0x80199C84u;
    // 80199C84: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199C88:
    ctx->pc = 0x80199C88u;
    // 80199C88: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199C8C:
    ctx->pc = 0x80199C8Cu;
    ctx->downcount -= 7;
    // 80199C8C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199C90:
    ctx->pc = 0x80199C90u;
    // 80199C90: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199C94:
    ctx->pc = 0x80199C94u;
    // 80199C94: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199C98:
    ctx->pc = 0x80199C98u;
    // 80199C98: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199C9C:
    ctx->pc = 0x80199C9Cu;
    // 80199C9C: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199CA0:
    ctx->pc = 0x80199CA0u;
    // 80199CA0: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199CA4:
    ctx->pc = 0x80199CA4u;
    // 80199CA4: bc    12, 2, 0x80199CAC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199CAC;
        }
    }

label_80199CA8:
    ctx->pc = 0x80199CA8u;
    ctx->downcount -= 1;
    // 80199CA8: bl      0x8019D210
    {
            ctx->lr = 0x80199CACu;
            ctx->pc = 0x8019D210u;
            return;
    }

label_80199CAC:
    ctx->pc = 0x80199CACu;
    ctx->downcount -= 4;
    // 80199CAC: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199CB0:
    ctx->pc = 0x80199CB0u;
    // 80199CB0: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199CB4:
    ctx->pc = 0x80199CB4u;
    // 80199CB4: rlwinm. r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199CB8:
    ctx->pc = 0x80199CB8u;
    // 80199CB8: bc    12, 2, 0x80199CC0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199CC0;
        }
    }

label_80199CBC:
    ctx->pc = 0x80199CBCu;
    ctx->downcount -= 1;
    // 80199CBC: bl      0x8019DF28
    {
            ctx->lr = 0x80199CC0u;
            ctx->pc = 0x8019DF28u;
            return;
    }

label_80199CC0:
    ctx->pc = 0x80199CC0u;
    ctx->downcount -= 4;
    // 80199CC0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199CC4:
    ctx->pc = 0x80199CC4u;
    // 80199CC4: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199CC8:
    ctx->pc = 0x80199CC8u;
    // 80199CC8: rlwinm. r0, r0, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199CCC:
    ctx->pc = 0x80199CCCu;
    // 80199CCC: bc    12, 2, 0x80199CD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199CD4;
        }
    }

label_80199CD0:
    ctx->pc = 0x80199CD0u;
    ctx->downcount -= 1;
    // 80199CD0: bl      0x8019A0A8
    {
            ctx->lr = 0x80199CD4u;
            goto label_8019A0A8;
    }

label_80199CD4:
    ctx->pc = 0x80199CD4u;
    ctx->downcount -= 4;
    // 80199CD4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199CD8:
    ctx->pc = 0x80199CD8u;
    // 80199CD8: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199CDC:
    ctx->pc = 0x80199CDCu;
    // 80199CDC: rlwinm. r0, r0, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199CE0:
    ctx->pc = 0x80199CE0u;
    // 80199CE0: bc    12, 2, 0x80199CE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199CE8;
        }
    }

label_80199CE4:
    ctx->pc = 0x80199CE4u;
    ctx->downcount -= 1;
    // 80199CE4: bl      0x80197F90
    {
            ctx->lr = 0x80199CE8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197F90u;
                return;
            }
            goto label_80197F90;
    }

label_80199CE8:
    ctx->pc = 0x80199CE8u;
    ctx->downcount -= 4;
    // 80199CE8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199CEC:
    ctx->pc = 0x80199CECu;
    // 80199CEC: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199CF0:
    ctx->pc = 0x80199CF0u;
    // 80199CF0: rlwinm. r0, r0, 0, 27, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199CF4:
    ctx->pc = 0x80199CF4u;
    // 80199CF4: bc    12, 2, 0x80199CFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199CFC;
        }
    }

label_80199CF8:
    ctx->pc = 0x80199CF8u;
    ctx->downcount -= 1;
    // 80199CF8: bl      0x80198A40
    {
            ctx->lr = 0x80199CFCu;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80198A40u;
                return;
            }
            goto label_80198A40;
    }

label_80199CFC:
    ctx->pc = 0x80199CFCu;
    ctx->downcount -= 8;
    // 80199CFC: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199D00:
    ctx->pc = 0x80199D00u;
    // 80199D00: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199D04:
    ctx->pc = 0x80199D04u;
    // 80199D04: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199D08:
    ctx->pc = 0x80199D08u;
    // 80199D08: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199D0C:
    ctx->pc = 0x80199D0Cu;
    // 80199D0C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80199D10:
    ctx->pc = 0x80199D10u;
    // 80199D10: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199D14:
    ctx->pc = 0x80199D14u;
    // 80199D14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199D18:
    ctx->pc = 0x80199D18u;
    ctx->downcount -= 13;
    // 80199D18: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80199D1C:
    ctx->pc = 0x80199D1Cu;
    // 80199D1C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199D20:
    ctx->pc = 0x80199D20u;
    // 80199D20: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80199D24:
    ctx->pc = 0x80199D24u;
    // 80199D24: stw     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80199D28:
    ctx->pc = 0x80199D28u;
    // 80199D28: addi    r31, r5, 0
    ctx->gpr[31] = ctx->gpr[5] + (u32)(s32)(0);

label_80199D2C:
    ctx->pc = 0x80199D2Cu;
    // 80199D2C: stw     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_80199D30:
    ctx->pc = 0x80199D30u;
    // 80199D30: addi    r30, r4, 0
    ctx->gpr[30] = ctx->gpr[4] + (u32)(s32)(0);

label_80199D34:
    ctx->pc = 0x80199D34u;
    // 80199D34: stw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80199D38:
    ctx->pc = 0x80199D38u;
    // 80199D38: addi    r29, r3, 0
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(0);

label_80199D3C:
    ctx->pc = 0x80199D3Cu;
    // 80199D3C: lwz     r6, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80199D40:
    ctx->pc = 0x80199D40u;
    // 80199D40: lwz     r0, 1268(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199D44:
    ctx->pc = 0x80199D44u;
    // 80199D44: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199D48:
    ctx->pc = 0x80199D48u;
    // 80199D48: bc    12, 2, 0x80199DB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199DB4;
        }
    }

label_80199D4C:
    ctx->pc = 0x80199D4Cu;
    ctx->downcount -= 2;
    // 80199D4C: rlwinm. r0, r0, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199D50:
    ctx->pc = 0x80199D50u;
    // 80199D50: bc    12, 2, 0x80199D58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199D58;
        }
    }

label_80199D54:
    ctx->pc = 0x80199D54u;
    ctx->downcount -= 1;
    // 80199D54: bl      0x8019D210
    {
            ctx->lr = 0x80199D58u;
            ctx->pc = 0x8019D210u;
            return;
    }

label_80199D58:
    ctx->pc = 0x80199D58u;
    ctx->downcount -= 4;
    // 80199D58: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199D5C:
    ctx->pc = 0x80199D5Cu;
    // 80199D5C: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199D60:
    ctx->pc = 0x80199D60u;
    // 80199D60: rlwinm. r0, r0, 0, 30, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000002u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199D64:
    ctx->pc = 0x80199D64u;
    // 80199D64: bc    12, 2, 0x80199D6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199D6C;
        }
    }

label_80199D68:
    ctx->pc = 0x80199D68u;
    ctx->downcount -= 1;
    // 80199D68: bl      0x8019DF28
    {
            ctx->lr = 0x80199D6Cu;
            ctx->pc = 0x8019DF28u;
            return;
    }

label_80199D6C:
    ctx->pc = 0x80199D6Cu;
    ctx->downcount -= 4;
    // 80199D6C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199D70:
    ctx->pc = 0x80199D70u;
    // 80199D70: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199D74:
    ctx->pc = 0x80199D74u;
    // 80199D74: rlwinm. r0, r0, 0, 29, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000004u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199D78:
    ctx->pc = 0x80199D78u;
    // 80199D78: bc    12, 2, 0x80199D80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199D80;
        }
    }

label_80199D7C:
    ctx->pc = 0x80199D7Cu;
    ctx->downcount -= 1;
    // 80199D7C: bl      0x8019A0A8
    {
            ctx->lr = 0x80199D80u;
            goto label_8019A0A8;
    }

label_80199D80:
    ctx->pc = 0x80199D80u;
    ctx->downcount -= 4;
    // 80199D80: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199D84:
    ctx->pc = 0x80199D84u;
    // 80199D84: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199D88:
    ctx->pc = 0x80199D88u;
    // 80199D88: rlwinm. r0, r0, 0, 28, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000008u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199D8C:
    ctx->pc = 0x80199D8Cu;
    // 80199D8C: bc    12, 2, 0x80199D94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199D94;
        }
    }

label_80199D90:
    ctx->pc = 0x80199D90u;
    ctx->downcount -= 1;
    // 80199D90: bl      0x80197F90
    {
            ctx->lr = 0x80199D94u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80197F90u;
                return;
            }
            goto label_80197F90;
    }

label_80199D94:
    ctx->pc = 0x80199D94u;
    ctx->downcount -= 4;
    // 80199D94: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199D98:
    ctx->pc = 0x80199D98u;
    // 80199D98: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199D9C:
    ctx->pc = 0x80199D9Cu;
    // 80199D9C: rlwinm. r0, r0, 0, 27, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000010u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199DA0:
    ctx->pc = 0x80199DA0u;
    // 80199DA0: bc    12, 2, 0x80199DA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199DA8;
        }
    }

label_80199DA4:
    ctx->pc = 0x80199DA4u;
    ctx->downcount -= 1;
    // 80199DA4: bl      0x80198A40
    {
            ctx->lr = 0x80199DA8u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80198A40u;
                return;
            }
            goto label_80198A40;
    }

label_80199DA8:
    ctx->pc = 0x80199DA8u;
    ctx->downcount -= 3;
    // 80199DA8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199DAC:
    ctx->pc = 0x80199DACu;
    // 80199DAC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199DB0:
    ctx->pc = 0x80199DB0u;
    // 80199DB0: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199DB4:
    ctx->pc = 0x80199DB4u;
    ctx->downcount -= 4;
    // 80199DB4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199DB8:
    ctx->pc = 0x80199DB8u;
    // 80199DB8: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199DBC:
    ctx->pc = 0x80199DBCu;
    // 80199DBC: cmplwi  r0, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199DC0:
    ctx->pc = 0x80199DC0u;
    // 80199DC0: bc    4, 2, 0x80199DC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199DC8;
        }
    }

label_80199DC4:
    ctx->pc = 0x80199DC4u;
    ctx->downcount -= 1;
    // 80199DC4: bl      0x80199DF4
    {
            ctx->lr = 0x80199DC8u;
            goto label_80199DF4;
    }

label_80199DC8:
    ctx->pc = 0x80199DC8u;
    ctx->downcount -= 12;
    // 80199DC8: or   r0, r30, r29
    {
        ctx->gpr[0] = ctx->gpr[30] | ctx->gpr[29];
    }

label_80199DCC:
    ctx->pc = 0x80199DCCu;
    // 80199DCC: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_80199DD0:
    ctx->pc = 0x80199DD0u;
    // 80199DD0: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80199DD4:
    ctx->pc = 0x80199DD4u;
    // 80199DD4: sth     r31, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[31]);
    }

label_80199DD8:
    ctx->pc = 0x80199DD8u;
    // 80199DD8: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199DDC:
    ctx->pc = 0x80199DDCu;
    // 80199DDC: lwz     r31, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80199DE0:
    ctx->pc = 0x80199DE0u;
    // 80199DE0: lwz     r30, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_80199DE4:
    ctx->pc = 0x80199DE4u;
    // 80199DE4: lwz     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80199DE8:
    ctx->pc = 0x80199DE8u;
    // 80199DE8: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_80199DEC:
    ctx->pc = 0x80199DECu;
    // 80199DEC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_80199DF0:
    ctx->pc = 0x80199DF0u;
    // 80199DF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199DF4:
    ctx->pc = 0x80199DF4u;
    ctx->downcount -= 17;
    // 80199DF4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199DF8:
    ctx->pc = 0x80199DF8u;
    // 80199DF8: li      r0, 152
    ctx->gpr[0] = (u32)(s32)(152);

label_80199DFC:
    ctx->pc = 0x80199DFCu;
    // 80199DFC: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80199E00:
    ctx->pc = 0x80199E00u;
    // 80199E00: lhz     r6, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read16(ctx, ea);
    }

label_80199E04:
    ctx->pc = 0x80199E04u;
    // 80199E04: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80199E08:
    ctx->pc = 0x80199E08u;
    // 80199E08: lhz     r3, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_80199E0C:
    ctx->pc = 0x80199E0Cu;
    // 80199E0C: mullw   r7, r6, r3
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[3];
        ctx->gpr[7] = (u32)product;
    }

label_80199E10:
    ctx->pc = 0x80199E10u;
    // 80199E10: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80199E14:
    ctx->pc = 0x80199E14u;
    // 80199E14: sth     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write16(ctx, ea, (u16)ctx->gpr[6]);
    }

label_80199E18:
    ctx->pc = 0x80199E18u;
    // 80199E18: addi    r3, r7, 3
    ctx->gpr[3] = ctx->gpr[7] + (u32)(s32)(3);

label_80199E1C:
    ctx->pc = 0x80199E1Cu;
    // 80199E1C: cmplwi  r7, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[7]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_80199E20:
    ctx->pc = 0x80199E20u;
    // 80199E20: rlwinm r3, r3, 30, 2, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 30u) & 0x3FFFFFFFu;
    }

label_80199E24:
    ctx->pc = 0x80199E24u;
    // 80199E24: bc    4, 1, 0x80199E6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199E6C;
        }
    }

label_80199E28:
    ctx->pc = 0x80199E28u;
    ctx->downcount -= 4;
    // 80199E28: rlwinm. r0, r3, 29, 3, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 29u) & 0x1FFFFFFFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199E2C:
    ctx->pc = 0x80199E2Cu;
    // 80199E2C: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_80199E30:
    ctx->pc = 0x80199E30u;
    // 80199E30: bc    12, 2, 0x80199E60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199E60;
        }
    }

label_80199E34:
    loop_80199E34(ctx);
    if (ctx->pc == 0x80199E58u) goto label_80199E58;
    return;
label_80199E38:
    ctx->pc = 0x80199E38u;
    // 80199E38: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199E3C:
    ctx->pc = 0x80199E3Cu;
    // 80199E3C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199E40:
    ctx->pc = 0x80199E40u;
    // 80199E40: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199E44:
    ctx->pc = 0x80199E44u;
    // 80199E44: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199E48:
    ctx->pc = 0x80199E48u;
    // 80199E48: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199E4C:
    ctx->pc = 0x80199E4Cu;
    // 80199E4C: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199E50:
    ctx->pc = 0x80199E50u;
    // 80199E50: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199E54:
    // 80199E54: bc    16, 0, 0x80199E34
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80199E34u;
                return;
            }
            goto label_80199E34;
        }
    }

label_80199E58:
    ctx->pc = 0x80199E58u;
    ctx->downcount -= 2;
    // 80199E58: andi.   r3, r3, 0x0007
    {
        ctx->gpr[3] = ctx->gpr[3] & 0x0007u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[3];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_80199E5C:
    ctx->pc = 0x80199E5Cu;
    // 80199E5C: bc    12, 2, 0x80199E6C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199E6C;
        }
    }

label_80199E60:
    ctx->pc = 0x80199E60u;
    ctx->downcount -= 2;
    // 80199E60: mtctr    r3
    ctx->ctr = ctx->gpr[3];

label_80199E64:
    loop_80199E64(ctx);
    if (ctx->pc == 0x80199E6Cu) goto label_80199E6C;
    return;
label_80199E68:
    // 80199E68: bc    16, 0, 0x80199E64
    {
        ctx->ctr--;
        bool ctr_ok = (((ctx->ctr != 0) ? 1u : 0u) ^ 0u) != 0;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x80199E64u;
                return;
            }
            goto label_80199E64;
        }
    }

label_80199E6C:
    ctx->pc = 0x80199E6Cu;
    ctx->downcount -= 4;
    // 80199E6C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199E70:
    ctx->pc = 0x80199E70u;
    // 80199E70: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80199E74:
    ctx->pc = 0x80199E74u;
    // 80199E74: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199E78:
    ctx->pc = 0x80199E78u;
    // 80199E78: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199E7C:
    ctx->pc = 0x80199E7Cu;
    ctx->downcount -= 22;
    // 80199E7C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80199E80:
    ctx->pc = 0x80199E80u;
    // 80199E80: rlwinm r6, r4, 16, 0, 15
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 16u) & 0xFFFF0000u;
    }

label_80199E84:
    ctx->pc = 0x80199E84u;
    // 80199E84: li      r4, 97
    ctx->gpr[4] = (u32)(s32)(97);

label_80199E88:
    ctx->pc = 0x80199E88u;
    // 80199E88: lwz     r0, 124(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199E8C:
    ctx->pc = 0x80199E8Cu;
    // 80199E8C: addi    r7, r5, 124
    ctx->gpr[7] = ctx->gpr[5] + (u32)(s32)(124);

label_80199E90:
    ctx->pc = 0x80199E90u;
    // 80199E90: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80199E94:
    ctx->pc = 0x80199E94u;
    // 80199E94: rlwinm r0, r0, 0, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFF00u;
    }

label_80199E98:
    ctx->pc = 0x80199E98u;
    // 80199E98: rlwimi r0, r3, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_80199E9C:
    ctx->pc = 0x80199E9Cu;
    // 80199E9C: stw     r0, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199EA0:
    ctx->pc = 0x80199EA0u;
    // 80199EA0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199EA4:
    ctx->pc = 0x80199EA4u;
    // 80199EA4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199EA8:
    ctx->pc = 0x80199EA8u;
    // 80199EA8: addi    r7, r3, 124
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(124);

label_80199EAC:
    ctx->pc = 0x80199EACu;
    // 80199EAC: lwz     r3, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199EB0:
    ctx->pc = 0x80199EB0u;
    // 80199EB0: rlwinm r3, r3, 0, 16, 12
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF8FFFFu;
    }

label_80199EB4:
    ctx->pc = 0x80199EB4u;
    // 80199EB4: or   r3, r3, r6
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[6];
    }

label_80199EB8:
    ctx->pc = 0x80199EB8u;
    // 80199EB8: stw     r3, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80199EBC:
    ctx->pc = 0x80199EBCu;
    // 80199EBC: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80199EC0:
    ctx->pc = 0x80199EC0u;
    // 80199EC0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199EC4:
    ctx->pc = 0x80199EC4u;
    // 80199EC4: lwz     r3, 124(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199EC8:
    ctx->pc = 0x80199EC8u;
    // 80199EC8: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80199ECC:
    ctx->pc = 0x80199ECCu;
    // 80199ECC: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199ED0:
    ctx->pc = 0x80199ED0u;
    // 80199ED0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199ED4:
    ctx->pc = 0x80199ED4u;
    ctx->downcount -= 8;
    // 80199ED4: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80199ED8:
    ctx->pc = 0x80199ED8u;
    // 80199ED8: lwz     r0, 124(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199EDC:
    ctx->pc = 0x80199EDCu;
    // 80199EDC: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80199EE0:
    ctx->pc = 0x80199EE0u;
    // 80199EE0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199EE4:
    ctx->pc = 0x80199EE4u;
    // 80199EE4: lwz     r0, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199EE8:
    ctx->pc = 0x80199EE8u;
    // 80199EE8: rlwinm r0, r0, 16, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 16u) & 0x00000007u;
    }

label_80199EEC:
    ctx->pc = 0x80199EECu;
    // 80199EEC: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199EF0:
    ctx->pc = 0x80199EF0u;
    // 80199EF0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199EF4:
    ctx->pc = 0x80199EF4u;
    ctx->downcount -= 21;
    // 80199EF4: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80199EF8:
    ctx->pc = 0x80199EF8u;
    // 80199EF8: rlwinm r6, r4, 19, 0, 12
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[4], 19u) & 0xFFF80000u;
    }

label_80199EFC:
    ctx->pc = 0x80199EFCu;
    // 80199EFC: lwzu     r0, 124(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[5] = ea;
    }

label_80199F00:
    ctx->pc = 0x80199F00u;
    // 80199F00: li      r4, 97
    ctx->gpr[4] = (u32)(s32)(97);

label_80199F04:
    ctx->pc = 0x80199F04u;
    // 80199F04: rlwinm r0, r0, 0, 24, 15
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFF00FFu;
    }

label_80199F08:
    ctx->pc = 0x80199F08u;
    // 80199F08: rlwimi r0, r3, 8, 16, 23
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[3], 8u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000FF00u) | (rot & 0x0000FF00u);
    }

label_80199F0C:
    ctx->pc = 0x80199F0Cu;
    // 80199F0C: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199F10:
    ctx->pc = 0x80199F10u;
    // 80199F10: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80199F14:
    ctx->pc = 0x80199F14u;
    // 80199F14: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199F18:
    ctx->pc = 0x80199F18u;
    // 80199F18: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199F1C:
    ctx->pc = 0x80199F1Cu;
    // 80199F1C: addi    r7, r3, 124
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(124);

label_80199F20:
    ctx->pc = 0x80199F20u;
    // 80199F20: lwz     r3, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199F24:
    ctx->pc = 0x80199F24u;
    // 80199F24: rlwinm r3, r3, 0, 13, 9
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFC7FFFFu;
    }

label_80199F28:
    ctx->pc = 0x80199F28u;
    // 80199F28: or   r3, r3, r6
    {
        ctx->gpr[3] = ctx->gpr[3] | ctx->gpr[6];
    }

label_80199F2C:
    ctx->pc = 0x80199F2Cu;
    // 80199F2C: stw     r3, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80199F30:
    ctx->pc = 0x80199F30u;
    // 80199F30: stb     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_80199F34:
    ctx->pc = 0x80199F34u;
    // 80199F34: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199F38:
    ctx->pc = 0x80199F38u;
    // 80199F38: lwz     r3, 124(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(124);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199F3C:
    ctx->pc = 0x80199F3Cu;
    // 80199F3C: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80199F40:
    ctx->pc = 0x80199F40u;
    // 80199F40: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199F44:
    ctx->pc = 0x80199F44u;
    // 80199F44: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199F48:
    ctx->pc = 0x80199F48u;
    ctx->downcount -= 9;
    // 80199F48: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80199F4C:
    ctx->pc = 0x80199F4Cu;
    // 80199F4C: lwz     r0, 124(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199F50:
    ctx->pc = 0x80199F50u;
    // 80199F50: rlwinm r0, r0, 24, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 24u) & 0x000000FFu;
    }

label_80199F54:
    ctx->pc = 0x80199F54u;
    // 80199F54: stb     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_80199F58:
    ctx->pc = 0x80199F58u;
    // 80199F58: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199F5C:
    ctx->pc = 0x80199F5Cu;
    // 80199F5C: lwz     r0, 124(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199F60:
    ctx->pc = 0x80199F60u;
    // 80199F60: rlwinm r0, r0, 13, 29, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 13u) & 0x00000007u;
    }

label_80199F64:
    ctx->pc = 0x80199F64u;
    // 80199F64: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199F68:
    ctx->pc = 0x80199F68u;
    // 80199F68: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199F6C:
    ctx->pc = 0x80199F6Cu;
    ctx->downcount -= 25;
    // 80199F6C: lwz     r0, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80199F70:
    ctx->pc = 0x80199F70u;
    // 80199F70: rlwinm r7, r3, 2, 0, 29
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 2u) & 0xFFFFFFFCu;
    }

label_80199F74:
    ctx->pc = 0x80199F74u;
    // 80199F74: add   r6, r0, r7
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_80199F78:
    ctx->pc = 0x80199F78u;
    // 80199F78: lwz     r3, 184(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(184);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199F7C:
    ctx->pc = 0x80199F7Cu;
    // 80199F7C: rlwinm r0, r4, 18, 6, 13
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 18u) & 0x03FC0000u;
    }

label_80199F80:
    ctx->pc = 0x80199F80u;
    // 80199F80: rlwinm r4, r5, 19, 5, 12
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 19u) & 0x07F80000u;
    }

label_80199F84:
    ctx->pc = 0x80199F84u;
    // 80199F84: rlwinm r3, r3, 0, 14, 12
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFBFFFFu;
    }

label_80199F88:
    ctx->pc = 0x80199F88u;
    // 80199F88: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_80199F8C:
    ctx->pc = 0x80199F8Cu;
    // 80199F8C: stw     r0, 184(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80199F90:
    ctx->pc = 0x80199F90u;
    // 80199F90: li      r3, 97
    ctx->gpr[3] = (u32)(s32)(97);

label_80199F94:
    ctx->pc = 0x80199F94u;
    // 80199F94: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_80199F98:
    ctx->pc = 0x80199F98u;
    // 80199F98: lwz     r6, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80199F9C:
    ctx->pc = 0x80199F9Cu;
    // 80199F9C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_80199FA0:
    ctx->pc = 0x80199FA0u;
    // 80199FA0: add   r8, r6, r7
    {
        u32 a = ctx->gpr[6];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_80199FA4:
    ctx->pc = 0x80199FA4u;
    // 80199FA4: lwz     r6, 184(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(184);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80199FA8:
    ctx->pc = 0x80199FA8u;
    // 80199FA8: rlwinm r6, r6, 0, 13, 11
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFF7FFFFu;
    }

label_80199FAC:
    ctx->pc = 0x80199FACu;
    // 80199FAC: or   r4, r6, r4
    {
        ctx->gpr[4] = ctx->gpr[6] | ctx->gpr[4];
    }

label_80199FB0:
    ctx->pc = 0x80199FB0u;
    // 80199FB0: stw     r4, 184(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80199FB4:
    ctx->pc = 0x80199FB4u;
    // 80199FB4: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199FB8:
    ctx->pc = 0x80199FB8u;
    // 80199FB8: stb     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[3]);
    }

label_80199FBC:
    ctx->pc = 0x80199FBCu;
    // 80199FBC: add   r3, r4, r7
    {
        u32 a = ctx->gpr[4];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_80199FC0:
    ctx->pc = 0x80199FC0u;
    // 80199FC0: lwz     r3, 184(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(184);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80199FC4:
    ctx->pc = 0x80199FC4u;
    // 80199FC4: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80199FC8:
    ctx->pc = 0x80199FC8u;
    // 80199FC8: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_80199FCC:
    ctx->pc = 0x80199FCCu;
    // 80199FCC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_80199FD0:
    ctx->pc = 0x80199FD0u;
    ctx->downcount -= 2;
    // 80199FD0: cmpwi   r3, 2
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

label_80199FD4:
    ctx->pc = 0x80199FD4u;
    // 80199FD4: bc    12, 2, 0x80199FF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80199FF0;
        }
    }

label_80199FD8:
    ctx->pc = 0x80199FD8u;
    ctx->downcount -= 1;
    // 80199FD8: bc    4, 0, 0x80199FF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199FF4;
        }
    }

label_80199FDC:
    ctx->pc = 0x80199FDCu;
    ctx->downcount -= 2;
    // 80199FDC: cmpwi   r3, 1
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

label_80199FE0:
    ctx->pc = 0x80199FE0u;
    // 80199FE0: bc    4, 0, 0x80199FE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80199FE8;
        }
    }

label_80199FE4:
    ctx->pc = 0x80199FE4u;
    ctx->downcount -= 1;
    // 80199FE4: b       0x80199FF4
    {
            goto label_80199FF4;
    }

label_80199FE8:
    ctx->pc = 0x80199FE8u;
    ctx->downcount -= 2;
    // 80199FE8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80199FEC:
    ctx->pc = 0x80199FECu;
    // 80199FEC: b       0x80199FF4
    {
            goto label_80199FF4;
    }

label_80199FF0:
    ctx->pc = 0x80199FF0u;
    ctx->downcount -= 1;
    // 80199FF0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80199FF4:
    ctx->pc = 0x80199FF4u;
    ctx->downcount -= 11;
    // 80199FF4: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80199FF8:
    ctx->pc = 0x80199FF8u;
    // 80199FF8: rlwinm r0, r3, 14, 0, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 14u) & 0xFFFFC000u;
    }

label_80199FFC:
    ctx->pc = 0x80199FFCu;
    // 80199FFC: lwzu     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8019A000:
    ctx->pc = 0x8019A000u;
    // 8019A000: rlwinm r3, r3, 0, 18, 15
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFF3FFFu;
    }

label_8019A004:
    ctx->pc = 0x8019A004u;
    // 8019A004: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A008:
    ctx->pc = 0x8019A008u;
    // 8019A008: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A00C:
    ctx->pc = 0x8019A00Cu;
    // 8019A00C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A010:
    ctx->pc = 0x8019A010u;
    // 8019A010: lwz     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A014:
    ctx->pc = 0x8019A014u;
    // 8019A014: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_8019A018:
    ctx->pc = 0x8019A018u;
    // 8019A018: stw     r0, 1268(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1268);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A01C:
    ctx->pc = 0x8019A01Cu;
    // 8019A01C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A020:
    ctx->pc = 0x8019A020u;
    ctx->downcount -= 5;
    // 8019A020: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A024:
    ctx->pc = 0x8019A024u;
    // 8019A024: lwz     r0, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A028:
    ctx->pc = 0x8019A028u;
    // 8019A028: rlwinm r0, r0, 18, 30, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 18u) & 0x00000003u;
    }

label_8019A02C:
    ctx->pc = 0x8019A02Cu;
    // 8019A02C: cmpwi   r0, 2
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

label_8019A030:
    ctx->pc = 0x8019A030u;
    // 8019A030: bc    12, 2, 0x8019A050
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019A050;
        }
    }

label_8019A034:
    ctx->pc = 0x8019A034u;
    ctx->downcount -= 1;
    // 8019A034: bc    4, 0, 0x8019A05C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A05C;
        }
    }

label_8019A038:
    ctx->pc = 0x8019A038u;
    ctx->downcount -= 2;
    // 8019A038: cmpwi   r0, 1
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

label_8019A03C:
    ctx->pc = 0x8019A03Cu;
    // 8019A03C: bc    4, 0, 0x8019A044
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A044;
        }
    }

label_8019A040:
    ctx->pc = 0x8019A040u;
    ctx->downcount -= 1;
    // 8019A040: b       0x8019A05C
    {
            goto label_8019A05C;
    }

label_8019A044:
    ctx->pc = 0x8019A044u;
    ctx->downcount -= 3;
    // 8019A044: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8019A048:
    ctx->pc = 0x8019A048u;
    // 8019A048: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A04C:
    ctx->pc = 0x8019A04Cu;
    // 8019A04C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A050:
    ctx->pc = 0x8019A050u;
    ctx->downcount -= 3;
    // 8019A050: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8019A054:
    ctx->pc = 0x8019A054u;
    // 8019A054: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A058:
    ctx->pc = 0x8019A058u;
    // 8019A058: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A05C:
    ctx->pc = 0x8019A05Cu;
    ctx->downcount -= 2;
    // 8019A05C: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A060:
    ctx->pc = 0x8019A060u;
    // 8019A060: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A064:
    ctx->pc = 0x8019A064u;
    ctx->downcount -= 17;
    // 8019A064: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A068:
    ctx->pc = 0x8019A068u;
    // 8019A068: rlwinm r0, r3, 19, 5, 12
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 19u) & 0x07F80000u;
    }

label_8019A06C:
    ctx->pc = 0x8019A06Cu;
    // 8019A06C: li      r5, 97
    ctx->gpr[5] = (u32)(s32)(97);

label_8019A070:
    ctx->pc = 0x8019A070u;
    // 8019A070: lwz     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A074:
    ctx->pc = 0x8019A074u;
    // 8019A074: addi    r6, r4, 516
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(516);

label_8019A078:
    ctx->pc = 0x8019A078u;
    // 8019A078: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_8019A07C:
    ctx->pc = 0x8019A07Cu;
    // 8019A07C: rlwinm r3, r3, 0, 13, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF7FFFFu;
    }

label_8019A080:
    ctx->pc = 0x8019A080u;
    // 8019A080: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A084:
    ctx->pc = 0x8019A084u;
    // 8019A084: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A088:
    ctx->pc = 0x8019A088u;
    // 8019A088: lis     r0, -504
    ctx->gpr[0] = ((u32)(s32)(-504) << 16);

label_8019A08C:
    ctx->pc = 0x8019A08Cu;
    // 8019A08C: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8019A090:
    ctx->pc = 0x8019A090u;
    // 8019A090: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A094:
    ctx->pc = 0x8019A094u;
    // 8019A094: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A098:
    ctx->pc = 0x8019A098u;
    // 8019A098: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8019A09C:
    ctx->pc = 0x8019A09Cu;
    // 8019A09C: lwz     r0, 516(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(516);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A0A0:
    ctx->pc = 0x8019A0A0u;
    // 8019A0A0: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A0A4:
    ctx->pc = 0x8019A0A4u;
    // 8019A0A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A0A8:
    ctx->pc = 0x8019A0A8u;
    ctx->downcount -= 9;
    // 8019A0A8: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8019A0AC:
    ctx->pc = 0x8019A0ACu;
    // 8019A0AC: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A0B0:
    ctx->pc = 0x8019A0B0u;
    // 8019A0B0: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019A0B4:
    ctx->pc = 0x8019A0B4u;
    // 8019A0B4: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019A0B8:
    ctx->pc = 0x8019A0B8u;
    // 8019A0B8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019A0BC:
    ctx->pc = 0x8019A0BCu;
    // 8019A0BC: lwz     r3, 516(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(516);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A0C0:
    ctx->pc = 0x8019A0C0u;
    // 8019A0C0: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019A0C4:
    ctx->pc = 0x8019A0C4u;
    // 8019A0C4: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019A0C8:
    ctx->pc = 0x8019A0C8u;
    // 8019A0C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A0CC:
    ctx->pc = 0x8019A0CCu;
    ctx->downcount -= 6;
    // 8019A0CC: cmplw   r3, r4
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A0D0:
    ctx->pc = 0x8019A0D0u;
    // 8019A0D0: rlwinm r7, r5, 0, 16, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_8019A0D4:
    ctx->pc = 0x8019A0D4u;
    // 8019A0D4: rlwinm r0, r6, 0, 16, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_8019A0D8:
    ctx->pc = 0x8019A0D8u;
    // 8019A0D8: rlwinm r5, r5, 1, 16, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 1u) & 0x0000FFFEu;
    }

label_8019A0DC:
    ctx->pc = 0x8019A0DCu;
    // 8019A0DC: rlwinm r6, r6, 1, 16, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 1u) & 0x0000FFFEu;
    }

label_8019A0E0:
    ctx->pc = 0x8019A0E0u;
    // 8019A0E0: bc    12, 2, 0x8019A15C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019A15C;
        }
    }

label_8019A0E4:
    ctx->pc = 0x8019A0E4u;
    ctx->downcount -= 30;
    // 8019A0E4: lwz     r9, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019A0E8:
    ctx->pc = 0x8019A0E8u;
    // 8019A0E8: lwz     r8, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A0EC:
    ctx->pc = 0x8019A0ECu;
    // 8019A0EC: stw     r9, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019A0F0:
    ctx->pc = 0x8019A0F0u;
    // 8019A0F0: stw     r8, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A0F4:
    ctx->pc = 0x8019A0F4u;
    // 8019A0F4: lwz     r9, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019A0F8:
    ctx->pc = 0x8019A0F8u;
    // 8019A0F8: lwz     r8, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A0FC:
    ctx->pc = 0x8019A0FCu;
    // 8019A0FC: stw     r9, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019A100:
    ctx->pc = 0x8019A100u;
    // 8019A100: stw     r8, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A104:
    ctx->pc = 0x8019A104u;
    // 8019A104: lwz     r9, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019A108:
    ctx->pc = 0x8019A108u;
    // 8019A108: lwz     r8, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A10C:
    ctx->pc = 0x8019A10Cu;
    // 8019A10C: stw     r9, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019A110:
    ctx->pc = 0x8019A110u;
    // 8019A110: stw     r8, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A114:
    ctx->pc = 0x8019A114u;
    // 8019A114: lwz     r9, 24(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019A118:
    ctx->pc = 0x8019A118u;
    // 8019A118: lwz     r8, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A11C:
    ctx->pc = 0x8019A11Cu;
    // 8019A11C: stw     r9, 24(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019A120:
    ctx->pc = 0x8019A120u;
    // 8019A120: stw     r8, 28(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A124:
    ctx->pc = 0x8019A124u;
    // 8019A124: lwz     r9, 32(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019A128:
    ctx->pc = 0x8019A128u;
    // 8019A128: lwz     r8, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A12C:
    ctx->pc = 0x8019A12Cu;
    // 8019A12C: stw     r9, 32(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019A130:
    ctx->pc = 0x8019A130u;
    // 8019A130: stw     r8, 36(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A134:
    ctx->pc = 0x8019A134u;
    // 8019A134: lwz     r9, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019A138:
    ctx->pc = 0x8019A138u;
    // 8019A138: lwz     r8, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A13C:
    ctx->pc = 0x8019A13Cu;
    // 8019A13C: stw     r9, 40(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019A140:
    ctx->pc = 0x8019A140u;
    // 8019A140: stw     r8, 44(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A144:
    ctx->pc = 0x8019A144u;
    // 8019A144: lwz     r9, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8019A148:
    ctx->pc = 0x8019A148u;
    // 8019A148: lwz     r8, 52(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(52);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A14C:
    ctx->pc = 0x8019A14Cu;
    // 8019A14C: stw     r9, 48(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019A150:
    ctx->pc = 0x8019A150u;
    // 8019A150: stw     r8, 52(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A154:
    ctx->pc = 0x8019A154u;
    // 8019A154: lwz     r8, 56(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(56);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A158:
    ctx->pc = 0x8019A158u;
    // 8019A158: stw     r8, 56(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A15C:
    ctx->pc = 0x8019A15Cu;
    ctx->downcount -= 55;
    // 8019A15C: lhz     r8, 4(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_8019A160:
    ctx->pc = 0x8019A160u;
    // 8019A160: subf   r8, r5, r8
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_8019A164:
    ctx->pc = 0x8019A164u;
    // 8019A164: sth     r8, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_8019A168:
    ctx->pc = 0x8019A168u;
    // 8019A168: lhz     r10, 6(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(6);
        ctx->gpr[10] = mem_read16(ctx, ea);
    }

label_8019A16C:
    ctx->pc = 0x8019A16Cu;
    // 8019A16C: lhz     r8, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_8019A170:
    ctx->pc = 0x8019A170u;
    // 8019A170: mullw   r9, r6, r10
    {
        s64 product = (s64)(s32)ctx->gpr[6] * (s64)(s32)ctx->gpr[10];
        ctx->gpr[9] = (u32)product;
    }

label_8019A174:
    ctx->pc = 0x8019A174u;
    // 8019A174: divwu   r8, r9, r8
    {
        u32 divisor = ctx->gpr[8];
        ctx->gpr[8] = divisor == 0 ? 0u : ctx->gpr[9] / divisor;
    }

label_8019A178:
    ctx->pc = 0x8019A178u;
    // 8019A178: subf   r8, r8, r10
    {
        u32 a = ~ctx->gpr[8];
        u32 b = ctx->gpr[10];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_8019A17C:
    ctx->pc = 0x8019A17Cu;
    // 8019A17C: sth     r8, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_8019A180:
    ctx->pc = 0x8019A180u;
    // 8019A180: lwz     r8, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A184:
    ctx->pc = 0x8019A184u;
    // 8019A184: cmpwi   r8, 0
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

label_8019A188:
    ctx->pc = 0x8019A188u;
    // 8019A188: bc    4, 2, 0x8019A1AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A1AC;
        }
    }

label_8019A18C:
    ctx->pc = 0x8019A18Cu;
    ctx->downcount -= 4;
    // 8019A18C: lwz     r8, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8019A190:
    ctx->pc = 0x8019A190u;
    // 8019A190: rlwinm r8, r8, 0, 30, 30
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0x00000002u;
    }

label_8019A194:
    ctx->pc = 0x8019A194u;
    // 8019A194: cmpwi   r8, 2
    {
        s32 val_a = (s32)(ctx->gpr[8]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A198:
    ctx->pc = 0x8019A198u;
    // 8019A198: bc    12, 2, 0x8019A1AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019A1AC;
        }
    }

label_8019A19C:
    ctx->pc = 0x8019A19Cu;
    ctx->downcount -= 4;
    // 8019A19C: lhz     r8, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_8019A1A0:
    ctx->pc = 0x8019A1A0u;
    // 8019A1A0: subf   r8, r0, r8
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_8019A1A4:
    ctx->pc = 0x8019A1A4u;
    // 8019A1A4: sth     r8, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_8019A1A8:
    ctx->pc = 0x8019A1A8u;
    // 8019A1A8: b       0x8019A1B8
    {
            goto label_8019A1B8;
    }

label_8019A1AC:
    ctx->pc = 0x8019A1ACu;
    ctx->downcount -= 3;
    // 8019A1AC: lhz     r8, 8(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_8019A1B0:
    ctx->pc = 0x8019A1B0u;
    // 8019A1B0: subf   r8, r6, r8
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[8] = res;
    }

label_8019A1B4:
    ctx->pc = 0x8019A1B4u;
    // 8019A1B4: sth     r8, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        mem_write16(ctx, ea, (u16)ctx->gpr[8]);
    }

label_8019A1B8:
    ctx->pc = 0x8019A1B8u;
    ctx->downcount -= 13;
    // 8019A1B8: lhz     r8, 14(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(14);
        ctx->gpr[8] = mem_read16(ctx, ea);
    }

label_8019A1BC:
    ctx->pc = 0x8019A1BCu;
    // 8019A1BC: subf   r5, r5, r8
    {
        u32 a = ~ctx->gpr[5];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8019A1C0:
    ctx->pc = 0x8019A1C0u;
    // 8019A1C0: sth     r5, 14(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(14);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8019A1C4:
    ctx->pc = 0x8019A1C4u;
    // 8019A1C4: lhz     r5, 16(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_8019A1C8:
    ctx->pc = 0x8019A1C8u;
    // 8019A1C8: subf   r5, r6, r5
    {
        u32 a = ~ctx->gpr[6];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_8019A1CC:
    ctx->pc = 0x8019A1CCu;
    // 8019A1CC: sth     r5, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8019A1D0:
    ctx->pc = 0x8019A1D0u;
    // 8019A1D0: lhz     r5, 10(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(10);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_8019A1D4:
    ctx->pc = 0x8019A1D4u;
    // 8019A1D4: add   r5, r5, r7
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[7];
        u32 res = a + b;
        ctx->gpr[5] = res;
    }

label_8019A1D8:
    ctx->pc = 0x8019A1D8u;
    // 8019A1D8: sth     r5, 10(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(10);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8019A1DC:
    ctx->pc = 0x8019A1DCu;
    // 8019A1DC: lhz     r3, 12(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(12);
        ctx->gpr[3] = mem_read16(ctx, ea);
    }

label_8019A1E0:
    ctx->pc = 0x8019A1E0u;
    // 8019A1E0: add   r0, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_8019A1E4:
    ctx->pc = 0x8019A1E4u;
    // 8019A1E4: sth     r0, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019A1E8:
    ctx->pc = 0x8019A1E8u;
    // 8019A1E8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A1EC:
    ctx->pc = 0x8019A1ECu;
    ctx->downcount -= 48;
    // 8019A1EC: lwz     r7, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019A1F0:
    ctx->pc = 0x8019A1F0u;
    // 8019A1F0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8019A1F4:
    ctx->pc = 0x8019A1F4u;
    // 8019A1F4: rlwinm r4, r4, 10, 6, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 10u) & 0x03FFFC00u;
    }

label_8019A1F8:
    ctx->pc = 0x8019A1F8u;
    // 8019A1F8: stw     r8, 480(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(480);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A1FC:
    ctx->pc = 0x8019A1FCu;
    // 8019A1FC: rlwinm r7, r5, 0, 16, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_8019A200:
    ctx->pc = 0x8019A200u;
    // 8019A200: rlwinm r5, r6, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_8019A204:
    ctx->pc = 0x8019A204u;
    // 8019A204: lwz     r6, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019A208:
    ctx->pc = 0x8019A208u;
    // 8019A208: addi    r0, r5, -1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-1);

label_8019A20C:
    ctx->pc = 0x8019A20Cu;
    // 8019A20C: rlwinm r5, r3, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8019A210:
    ctx->pc = 0x8019A210u;
    // 8019A210: addi    r9, r6, 480
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(480);

label_8019A214:
    ctx->pc = 0x8019A214u;
    // 8019A214: lwz     r6, 480(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(480);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019A218:
    ctx->pc = 0x8019A218u;
    // 8019A218: addi    r3, r7, -1
    ctx->gpr[3] = ctx->gpr[7] + (u32)(s32)(-1);

label_8019A21C:
    ctx->pc = 0x8019A21Cu;
    // 8019A21C: rlwinm r6, r6, 0, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFC00u;
    }

label_8019A220:
    ctx->pc = 0x8019A220u;
    // 8019A220: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_8019A224:
    ctx->pc = 0x8019A224u;
    // 8019A224: stw     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8019A228:
    ctx->pc = 0x8019A228u;
    // 8019A228: rlwinm r0, r0, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0xFFFFFC00u;
    }

label_8019A22C:
    ctx->pc = 0x8019A22Cu;
    // 8019A22C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019A230:
    ctx->pc = 0x8019A230u;
    // 8019A230: addi    r6, r5, 480
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(480);

label_8019A234:
    ctx->pc = 0x8019A234u;
    // 8019A234: lwz     r5, 480(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(480);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019A238:
    ctx->pc = 0x8019A238u;
    // 8019A238: rlwinm r5, r5, 0, 22, 11
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFF003FFu;
    }

label_8019A23C:
    ctx->pc = 0x8019A23Cu;
    // 8019A23C: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8019A240:
    ctx->pc = 0x8019A240u;
    // 8019A240: stw     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019A244:
    ctx->pc = 0x8019A244u;
    // 8019A244: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A248:
    ctx->pc = 0x8019A248u;
    // 8019A248: addi    r5, r4, 480
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(480);

label_8019A24C:
    ctx->pc = 0x8019A24Cu;
    // 8019A24C: lwz     r4, 480(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(480);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A250:
    ctx->pc = 0x8019A250u;
    // 8019A250: rlwinm r4, r4, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_8019A254:
    ctx->pc = 0x8019A254u;
    // 8019A254: oris    r4, r4, 0x4900
    ctx->gpr[4] = ctx->gpr[4] | (0x4900u << 16);

label_8019A258:
    ctx->pc = 0x8019A258u;
    // 8019A258: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019A25C:
    ctx->pc = 0x8019A25Cu;
    // 8019A25C: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A260:
    ctx->pc = 0x8019A260u;
    // 8019A260: stw     r8, 484(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(484);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A264:
    ctx->pc = 0x8019A264u;
    // 8019A264: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A268:
    ctx->pc = 0x8019A268u;
    // 8019A268: addi    r5, r4, 484
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(484);

label_8019A26C:
    ctx->pc = 0x8019A26Cu;
    // 8019A26C: lwz     r4, 484(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(484);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A270:
    ctx->pc = 0x8019A270u;
    // 8019A270: rlwinm r4, r4, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_8019A274:
    ctx->pc = 0x8019A274u;
    // 8019A274: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8019A278:
    ctx->pc = 0x8019A278u;
    // 8019A278: stw     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019A27C:
    ctx->pc = 0x8019A27Cu;
    // 8019A27C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A280:
    ctx->pc = 0x8019A280u;
    // 8019A280: addi    r4, r3, 484
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(484);

label_8019A284:
    ctx->pc = 0x8019A284u;
    // 8019A284: lwz     r3, 484(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(484);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A288:
    ctx->pc = 0x8019A288u;
    // 8019A288: rlwinm r3, r3, 0, 22, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF003FFu;
    }

label_8019A28C:
    ctx->pc = 0x8019A28Cu;
    // 8019A28C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A290:
    ctx->pc = 0x8019A290u;
    // 8019A290: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A294:
    ctx->pc = 0x8019A294u;
    // 8019A294: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A298:
    ctx->pc = 0x8019A298u;
    // 8019A298: lwzu     r0, 484(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(484);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A29C:
    ctx->pc = 0x8019A29Cu;
    // 8019A29C: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_8019A2A0:
    ctx->pc = 0x8019A2A0u;
    // 8019A2A0: oris    r0, r0, 0x4A00
    ctx->gpr[0] = ctx->gpr[0] | (0x4A00u << 16);

label_8019A2A4:
    ctx->pc = 0x8019A2A4u;
    // 8019A2A4: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A2A8:
    ctx->pc = 0x8019A2A8u;
    // 8019A2A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A2AC:
    ctx->pc = 0x8019A2ACu;
    ctx->downcount -= 48;
    // 8019A2AC: lwz     r7, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019A2B0:
    ctx->pc = 0x8019A2B0u;
    // 8019A2B0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8019A2B4:
    ctx->pc = 0x8019A2B4u;
    // 8019A2B4: rlwinm r4, r4, 10, 6, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 10u) & 0x03FFFC00u;
    }

label_8019A2B8:
    ctx->pc = 0x8019A2B8u;
    // 8019A2B8: stw     r8, 496(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(496);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A2BC:
    ctx->pc = 0x8019A2BCu;
    // 8019A2BC: rlwinm r7, r5, 0, 16, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000FFFFu;
    }

label_8019A2C0:
    ctx->pc = 0x8019A2C0u;
    // 8019A2C0: rlwinm r5, r6, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0x0000FFFFu;
    }

label_8019A2C4:
    ctx->pc = 0x8019A2C4u;
    // 8019A2C4: lwz     r6, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019A2C8:
    ctx->pc = 0x8019A2C8u;
    // 8019A2C8: addi    r0, r5, -1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-1);

label_8019A2CC:
    ctx->pc = 0x8019A2CCu;
    // 8019A2CC: rlwinm r5, r3, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8019A2D0:
    ctx->pc = 0x8019A2D0u;
    // 8019A2D0: addi    r9, r6, 496
    ctx->gpr[9] = ctx->gpr[6] + (u32)(s32)(496);

label_8019A2D4:
    ctx->pc = 0x8019A2D4u;
    // 8019A2D4: lwz     r6, 496(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(496);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019A2D8:
    ctx->pc = 0x8019A2D8u;
    // 8019A2D8: addi    r3, r7, -1
    ctx->gpr[3] = ctx->gpr[7] + (u32)(s32)(-1);

label_8019A2DC:
    ctx->pc = 0x8019A2DCu;
    // 8019A2DC: rlwinm r6, r6, 0, 0, 21
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFC00u;
    }

label_8019A2E0:
    ctx->pc = 0x8019A2E0u;
    // 8019A2E0: or   r5, r6, r5
    {
        ctx->gpr[5] = ctx->gpr[6] | ctx->gpr[5];
    }

label_8019A2E4:
    ctx->pc = 0x8019A2E4u;
    // 8019A2E4: stw     r5, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8019A2E8:
    ctx->pc = 0x8019A2E8u;
    // 8019A2E8: rlwinm r0, r0, 10, 0, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0xFFFFFC00u;
    }

label_8019A2EC:
    ctx->pc = 0x8019A2ECu;
    // 8019A2EC: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019A2F0:
    ctx->pc = 0x8019A2F0u;
    // 8019A2F0: addi    r6, r5, 496
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(496);

label_8019A2F4:
    ctx->pc = 0x8019A2F4u;
    // 8019A2F4: lwz     r5, 496(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(496);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019A2F8:
    ctx->pc = 0x8019A2F8u;
    // 8019A2F8: rlwinm r5, r5, 0, 22, 11
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFF003FFu;
    }

label_8019A2FC:
    ctx->pc = 0x8019A2FCu;
    // 8019A2FC: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8019A300:
    ctx->pc = 0x8019A300u;
    // 8019A300: stw     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019A304:
    ctx->pc = 0x8019A304u;
    // 8019A304: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A308:
    ctx->pc = 0x8019A308u;
    // 8019A308: addi    r5, r4, 496
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(496);

label_8019A30C:
    ctx->pc = 0x8019A30Cu;
    // 8019A30C: lwz     r4, 496(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(496);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A310:
    ctx->pc = 0x8019A310u;
    // 8019A310: rlwinm r4, r4, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_8019A314:
    ctx->pc = 0x8019A314u;
    // 8019A314: oris    r4, r4, 0x4900
    ctx->gpr[4] = ctx->gpr[4] | (0x4900u << 16);

label_8019A318:
    ctx->pc = 0x8019A318u;
    // 8019A318: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019A31C:
    ctx->pc = 0x8019A31Cu;
    // 8019A31C: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A320:
    ctx->pc = 0x8019A320u;
    // 8019A320: stw     r8, 500(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(500);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019A324:
    ctx->pc = 0x8019A324u;
    // 8019A324: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A328:
    ctx->pc = 0x8019A328u;
    // 8019A328: addi    r5, r4, 500
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(500);

label_8019A32C:
    ctx->pc = 0x8019A32Cu;
    // 8019A32C: lwz     r4, 500(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(500);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A330:
    ctx->pc = 0x8019A330u;
    // 8019A330: rlwinm r4, r4, 0, 0, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFC00u;
    }

label_8019A334:
    ctx->pc = 0x8019A334u;
    // 8019A334: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8019A338:
    ctx->pc = 0x8019A338u;
    // 8019A338: stw     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019A33C:
    ctx->pc = 0x8019A33Cu;
    // 8019A33C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A340:
    ctx->pc = 0x8019A340u;
    // 8019A340: addi    r4, r3, 500
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(500);

label_8019A344:
    ctx->pc = 0x8019A344u;
    // 8019A344: lwz     r3, 500(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(500);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A348:
    ctx->pc = 0x8019A348u;
    // 8019A348: rlwinm r3, r3, 0, 22, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFF003FFu;
    }

label_8019A34C:
    ctx->pc = 0x8019A34Cu;
    // 8019A34C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A350:
    ctx->pc = 0x8019A350u;
    // 8019A350: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A354:
    ctx->pc = 0x8019A354u;
    // 8019A354: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A358:
    ctx->pc = 0x8019A358u;
    // 8019A358: lwzu     r0, 500(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(500);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A35C:
    ctx->pc = 0x8019A35Cu;
    // 8019A35C: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_8019A360:
    ctx->pc = 0x8019A360u;
    // 8019A360: oris    r0, r0, 0x4A00
    ctx->gpr[0] = ctx->gpr[0] | (0x4A00u << 16);

label_8019A364:
    ctx->pc = 0x8019A364u;
    // 8019A364: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A368:
    ctx->pc = 0x8019A368u;
    // 8019A368: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A36C:
    ctx->pc = 0x8019A36Cu;
    ctx->downcount -= 17;
    // 8019A36C: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A370:
    ctx->pc = 0x8019A370u;
    // 8019A370: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019A374:
    ctx->pc = 0x8019A374u;
    // 8019A374: stw     r0, 488(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(488);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A378:
    ctx->pc = 0x8019A378u;
    // 8019A378: rlwinm r0, r3, 1, 16, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0x0000FFFEu;
    }

label_8019A37C:
    ctx->pc = 0x8019A37Cu;
    // 8019A37C: srawi r0, r0, 5
    {
        u32 sh = 5u;
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

label_8019A380:
    ctx->pc = 0x8019A380u;
    // 8019A380: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A384:
    ctx->pc = 0x8019A384u;
    // 8019A384: addi    r4, r3, 488
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(488);

label_8019A388:
    ctx->pc = 0x8019A388u;
    // 8019A388: lwz     r3, 488(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(488);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A38C:
    ctx->pc = 0x8019A38Cu;
    // 8019A38C: rlwinm r3, r3, 0, 0, 21
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFC00u;
    }

label_8019A390:
    ctx->pc = 0x8019A390u;
    // 8019A390: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A394:
    ctx->pc = 0x8019A394u;
    // 8019A394: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A398:
    ctx->pc = 0x8019A398u;
    // 8019A398: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A39C:
    ctx->pc = 0x8019A39Cu;
    // 8019A39C: lwzu     r0, 488(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(488);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A3A0:
    ctx->pc = 0x8019A3A0u;
    // 8019A3A0: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_8019A3A4:
    ctx->pc = 0x8019A3A4u;
    // 8019A3A4: oris    r0, r0, 0x4D00
    ctx->gpr[0] = ctx->gpr[0] | (0x4D00u << 16);

label_8019A3A8:
    ctx->pc = 0x8019A3A8u;
    // 8019A3A8: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A3AC:
    ctx->pc = 0x8019A3ACu;
    // 8019A3AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A3B0:
    ctx->pc = 0x8019A3B0u;
    ctx->downcount -= 14;
    // 8019A3B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8019A3B4:
    ctx->pc = 0x8019A3B4u;
    // 8019A3B4: cmpwi   r5, 19
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(19);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A3B8:
    ctx->pc = 0x8019A3B8u;
    // 8019A3B8: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A3BC:
    ctx->pc = 0x8019A3BCu;
    // 8019A3BC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019A3C0:
    ctx->pc = 0x8019A3C0u;
    // 8019A3C0: addi    r8, r3, 0
    ctx->gpr[8] = ctx->gpr[3] + (u32)(s32)(0);

label_8019A3C4:
    ctx->pc = 0x8019A3C4u;
    // 8019A3C4: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019A3C8:
    ctx->pc = 0x8019A3C8u;
    // 8019A3C8: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019A3CC:
    ctx->pc = 0x8019A3CCu;
    // 8019A3CC: rlwinm r31, r5, 0, 28, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x0000000Fu;
    }

label_8019A3D0:
    ctx->pc = 0x8019A3D0u;
    // 8019A3D0: stw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8019A3D4:
    ctx->pc = 0x8019A3D4u;
    // 8019A3D4: addi    r30, r6, 0
    ctx->gpr[30] = ctx->gpr[6] + (u32)(s32)(0);

label_8019A3D8:
    ctx->pc = 0x8019A3D8u;
    // 8019A3D8: lwz     r7, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019A3DC:
    ctx->pc = 0x8019A3DCu;
    // 8019A3DC: stb     r0, 512(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(512);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019A3E0:
    ctx->pc = 0x8019A3E0u;
    // 8019A3E0: addi    r7, r4, 0
    ctx->gpr[7] = ctx->gpr[4] + (u32)(s32)(0);

label_8019A3E4:
    ctx->pc = 0x8019A3E4u;
    // 8019A3E4: bc    4, 2, 0x8019A3EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A3EC;
        }
    }

label_8019A3E8:
    ctx->pc = 0x8019A3E8u;
    ctx->downcount -= 1;
    // 8019A3E8: li      r31, 11
    ctx->gpr[31] = (u32)(s32)(11);

label_8019A3EC:
    ctx->pc = 0x8019A3ECu;
    ctx->downcount -= 2;
    // 8019A3EC: cmpwi   r5, 38
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(38);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A3F0:
    ctx->pc = 0x8019A3F0u;
    // 8019A3F0: bc    12, 2, 0x8019A40C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019A40C;
        }
    }

label_8019A3F4:
    ctx->pc = 0x8019A3F4u;
    ctx->downcount -= 1;
    // 8019A3F4: bc    4, 0, 0x8019A428
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A428;
        }
    }

label_8019A3F8:
    ctx->pc = 0x8019A3F8u;
    ctx->downcount -= 2;
    // 8019A3F8: cmpwi   r5, 4
    {
        s32 val_a = (s32)(ctx->gpr[5]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A3FC:
    ctx->pc = 0x8019A3FCu;
    // 8019A3FC: bc    4, 0, 0x8019A428
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A428;
        }
    }

label_8019A400:
    ctx->pc = 0x8019A400u;
    ctx->downcount -= 2;
    // 8019A400: cmpwi   r5, 0
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

label_8019A404:
    ctx->pc = 0x8019A404u;
    // 8019A404: bc    4, 0, 0x8019A40C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A40C;
        }
    }

label_8019A408:
    ctx->pc = 0x8019A408u;
    ctx->downcount -= 1;
    // 8019A408: b       0x8019A428
    {
            goto label_8019A428;
    }

label_8019A40C:
    ctx->pc = 0x8019A40Cu;
    ctx->downcount -= 7;
    // 8019A40C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A410:
    ctx->pc = 0x8019A410u;
    // 8019A410: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A414:
    ctx->pc = 0x8019A414u;
    // 8019A414: rlwinm r0, r0, 0, 17, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFE7FFFu;
    }

label_8019A418:
    ctx->pc = 0x8019A418u;
    // 8019A418: oris    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | (0x0001u << 16);

label_8019A41C:
    ctx->pc = 0x8019A41Cu;
    // 8019A41C: ori     r0, r0, 0x8000
    ctx->gpr[0] = ctx->gpr[0] | 0x8000u;

label_8019A420:
    ctx->pc = 0x8019A420u;
    // 8019A420: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A424:
    ctx->pc = 0x8019A424u;
    // 8019A424: b       0x8019A43C
    {
            goto label_8019A43C;
    }

label_8019A428:
    ctx->pc = 0x8019A428u;
    ctx->downcount -= 5;
    // 8019A428: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A42C:
    ctx->pc = 0x8019A42Cu;
    // 8019A42C: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A430:
    ctx->pc = 0x8019A430u;
    // 8019A430: rlwinm r0, r0, 0, 17, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFE7FFFu;
    }

label_8019A434:
    ctx->pc = 0x8019A434u;
    // 8019A434: oris    r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | (0x0001u << 16);

label_8019A438:
    ctx->pc = 0x8019A438u;
    // 8019A438: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A43C:
    ctx->pc = 0x8019A43Cu;
    ctx->downcount -= 20;
    // 8019A43C: rlwinm r4, r5, 0, 27, 27
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000010u;
    }

label_8019A440:
    ctx->pc = 0x8019A440u;
    // 8019A440: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A444:
    ctx->pc = 0x8019A444u;
    // 8019A444: addi    r0, r4, -16
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-16);

label_8019A448:
    ctx->pc = 0x8019A448u;
    // 8019A448: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8019A44C:
    ctx->pc = 0x8019A44Cu;
    // 8019A44C: rlwinm r0, r0, 27, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x000000FFu;
    }

label_8019A450:
    ctx->pc = 0x8019A450u;
    // 8019A450: stb     r0, 512(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(512);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019A454:
    ctx->pc = 0x8019A454u;
    // 8019A454: addi    r3, r5, 0
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(0);

label_8019A458:
    ctx->pc = 0x8019A458u;
    // 8019A458: addi    r5, r7, 0
    ctx->gpr[5] = ctx->gpr[7] + (u32)(s32)(0);

label_8019A45C:
    ctx->pc = 0x8019A45Cu;
    // 8019A45C: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A460:
    ctx->pc = 0x8019A460u;
    // 8019A460: addi    r7, r1, 28
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(28);

label_8019A464:
    ctx->pc = 0x8019A464u;
    // 8019A464: lwz     r0, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A468:
    ctx->pc = 0x8019A468u;
    // 8019A468: addi    r6, r4, 508
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(508);

label_8019A46C:
    ctx->pc = 0x8019A46Cu;
    // 8019A46C: addi    r4, r8, 0
    ctx->gpr[4] = ctx->gpr[8] + (u32)(s32)(0);

label_8019A470:
    ctx->pc = 0x8019A470u;
    // 8019A470: rlwinm r0, r0, 0, 29, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFF7u;
    }

label_8019A474:
    ctx->pc = 0x8019A474u;
    // 8019A474: rlwimi r0, r31, 0, 28, 28
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[31], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x00000008u) | (rot & 0x00000008u);
    }

label_8019A478:
    ctx->pc = 0x8019A478u;
    // 8019A478: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A47C:
    ctx->pc = 0x8019A47Cu;
    // 8019A47C: rlwinm r31, r31, 0, 29, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x00000007u;
    }

label_8019A480:
    ctx->pc = 0x8019A480u;
    // 8019A480: addi    r6, r1, 32
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(32);

label_8019A484:
    ctx->pc = 0x8019A484u;
    // 8019A484: addi    r8, r1, 24
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(24);

label_8019A488:
    ctx->pc = 0x8019A488u;
    // 8019A488: bl      0x8019BD50
    {
            ctx->lr = 0x8019A48Cu;
            ctx->pc = 0x8019BD50u;
            return;
    }

label_8019A48C:
    ctx->pc = 0x8019A48Cu;
    ctx->downcount -= 42;
    // 8019A48C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A490:
    ctx->pc = 0x8019A490u;
    // 8019A490: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019A494:
    ctx->pc = 0x8019A494u;
    // 8019A494: stw     r0, 504(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(504);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A498:
    ctx->pc = 0x8019A498u;
    // 8019A498: rlwinm r3, r30, 9, 15, 22
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 9u) & 0x0001FE00u;
    }

label_8019A49C:
    ctx->pc = 0x8019A49Cu;
    // 8019A49C: rlwinm r0, r31, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 4u) & 0xFFFFFFF0u;
    }

label_8019A4A0:
    ctx->pc = 0x8019A4A0u;
    // 8019A4A0: lwz     r5, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019A4A4:
    ctx->pc = 0x8019A4A4u;
    // 8019A4A4: lwz     r4, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A4A8:
    ctx->pc = 0x8019A4A8u;
    // 8019A4A8: lwz     r6, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019A4AC:
    ctx->pc = 0x8019A4ACu;
    // 8019A4AC: mullw   r4, r5, r4
    {
        s64 product = (s64)(s32)ctx->gpr[5] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[4] = (u32)product;
    }

label_8019A4B0:
    ctx->pc = 0x8019A4B0u;
    // 8019A4B0: lwzu     r5, 504(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(504);
        ctx->gpr[5] = mem_read32(ctx, ea);
        ctx->gpr[6] = ea;
    }

label_8019A4B4:
    ctx->pc = 0x8019A4B4u;
    // 8019A4B4: rlwinm r5, r5, 0, 0, 21
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFFC00u;
    }

label_8019A4B8:
    ctx->pc = 0x8019A4B8u;
    // 8019A4B8: or   r4, r5, r4
    {
        ctx->gpr[4] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8019A4BC:
    ctx->pc = 0x8019A4BCu;
    // 8019A4BC: stw     r4, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019A4C0:
    ctx->pc = 0x8019A4C0u;
    // 8019A4C0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A4C4:
    ctx->pc = 0x8019A4C4u;
    // 8019A4C4: addi    r5, r4, 504
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(504);

label_8019A4C8:
    ctx->pc = 0x8019A4C8u;
    // 8019A4C8: lwz     r4, 504(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(504);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A4CC:
    ctx->pc = 0x8019A4CCu;
    // 8019A4CC: rlwinm r4, r4, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_8019A4D0:
    ctx->pc = 0x8019A4D0u;
    // 8019A4D0: oris    r4, r4, 0x4D00
    ctx->gpr[4] = ctx->gpr[4] | (0x4D00u << 16);

label_8019A4D4:
    ctx->pc = 0x8019A4D4u;
    // 8019A4D4: stw     r4, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019A4D8:
    ctx->pc = 0x8019A4D8u;
    // 8019A4D8: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A4DC:
    ctx->pc = 0x8019A4DCu;
    // 8019A4DC: addi    r5, r4, 508
    ctx->gpr[5] = ctx->gpr[4] + (u32)(s32)(508);

label_8019A4E0:
    ctx->pc = 0x8019A4E0u;
    // 8019A4E0: lwz     r4, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A4E4:
    ctx->pc = 0x8019A4E4u;
    // 8019A4E4: rlwinm r4, r4, 0, 23, 21
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFDFFu;
    }

label_8019A4E8:
    ctx->pc = 0x8019A4E8u;
    // 8019A4E8: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8019A4EC:
    ctx->pc = 0x8019A4ECu;
    // 8019A4EC: stw     r3, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019A4F0:
    ctx->pc = 0x8019A4F0u;
    // 8019A4F0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A4F4:
    ctx->pc = 0x8019A4F4u;
    // 8019A4F4: addi    r4, r3, 508
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(508);

label_8019A4F8:
    ctx->pc = 0x8019A4F8u;
    // 8019A4F8: lwz     r3, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A4FC:
    ctx->pc = 0x8019A4FCu;
    // 8019A4FC: rlwinm r3, r3, 0, 28, 24
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFF8Fu;
    }

label_8019A500:
    ctx->pc = 0x8019A500u;
    // 8019A500: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A504:
    ctx->pc = 0x8019A504u;
    // 8019A504: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A508:
    ctx->pc = 0x8019A508u;
    // 8019A508: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A50C:
    ctx->pc = 0x8019A50Cu;
    // 8019A50C: lwz     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019A510:
    ctx->pc = 0x8019A510u;
    // 8019A510: lwz     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8019A514:
    ctx->pc = 0x8019A514u;
    // 8019A514: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_8019A518:
    ctx->pc = 0x8019A518u;
    // 8019A518: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019A51C:
    ctx->pc = 0x8019A51Cu;
    // 8019A51C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A520:
    ctx->pc = 0x8019A520u;
    ctx->downcount -= 11;
    // 8019A520: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A524:
    ctx->pc = 0x8019A524u;
    // 8019A524: rlwinm r0, r3, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 12u) & 0xFFFFF000u;
    }

label_8019A528:
    ctx->pc = 0x8019A528u;
    // 8019A528: lwzu     r3, 492(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8019A52C:
    ctx->pc = 0x8019A52Cu;
    // 8019A52C: rlwinm r3, r3, 0, 20, 17
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFCFFFu;
    }

label_8019A530:
    ctx->pc = 0x8019A530u;
    // 8019A530: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A534:
    ctx->pc = 0x8019A534u;
    // 8019A534: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A538:
    ctx->pc = 0x8019A538u;
    // 8019A538: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A53C:
    ctx->pc = 0x8019A53Cu;
    // 8019A53C: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A540:
    ctx->pc = 0x8019A540u;
    // 8019A540: rlwinm r0, r0, 0, 20, 17
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFCFFFu;
    }

label_8019A544:
    ctx->pc = 0x8019A544u;
    // 8019A544: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A548:
    ctx->pc = 0x8019A548u;
    // 8019A548: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A54C:
    ctx->pc = 0x8019A54Cu;
    ctx->downcount -= 31;
    // 8019A54C: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019A550:
    ctx->pc = 0x8019A550u;
    // 8019A550: rlwinm r4, r3, 0, 31, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000001u;
    }

label_8019A554:
    ctx->pc = 0x8019A554u;
    // 8019A554: addi    r0, r4, -1
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(-1);

label_8019A558:
    ctx->pc = 0x8019A558u;
    // 8019A558: lwz     r4, 492(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(492);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A55C:
    ctx->pc = 0x8019A55Cu;
    // 8019A55C: addi    r6, r5, 492
    ctx->gpr[6] = ctx->gpr[5] + (u32)(s32)(492);

label_8019A560:
    ctx->pc = 0x8019A560u;
    // 8019A560: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8019A564:
    ctx->pc = 0x8019A564u;
    // 8019A564: rlwinm r5, r4, 0, 0, 30
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFFFFEu;
    }

label_8019A568:
    ctx->pc = 0x8019A568u;
    // 8019A568: rlwinm r4, r0, 27, 24, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[0], 27u) & 0x000000FFu;
    }

label_8019A56C:
    ctx->pc = 0x8019A56Cu;
    // 8019A56C: or   r0, r5, r4
    {
        ctx->gpr[0] = ctx->gpr[5] | ctx->gpr[4];
    }

label_8019A570:
    ctx->pc = 0x8019A570u;
    // 8019A570: stw     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A574:
    ctx->pc = 0x8019A574u;
    // 8019A574: rlwinm r3, r3, 0, 30, 30
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00000002u;
    }

label_8019A578:
    ctx->pc = 0x8019A578u;
    // 8019A578: addi    r0, r3, -2
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-2);

label_8019A57C:
    ctx->pc = 0x8019A57Cu;
    // 8019A57C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A580:
    ctx->pc = 0x8019A580u;
    // 8019A580: cntlzw r0, r0
    {
        u32 v = ctx->gpr[0];
        u32 n = 0;
        while (n < 32 && ((v & (0x80000000u >> n)) == 0)) n++;
        ctx->gpr[0] = n;
    }

label_8019A584:
    ctx->pc = 0x8019A584u;
    // 8019A584: rlwinm r6, r0, 28, 23, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[0], 28u) & 0x000001FEu;
    }

label_8019A588:
    ctx->pc = 0x8019A588u;
    // 8019A588: addi    r5, r3, 492
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(492);

label_8019A58C:
    ctx->pc = 0x8019A58Cu;
    // 8019A58C: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A590:
    ctx->pc = 0x8019A590u;
    // 8019A590: rlwinm r0, r3, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFFFDu;
    }

label_8019A594:
    ctx->pc = 0x8019A594u;
    // 8019A594: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_8019A598:
    ctx->pc = 0x8019A598u;
    // 8019A598: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A59C:
    ctx->pc = 0x8019A59Cu;
    // 8019A59C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A5A0:
    ctx->pc = 0x8019A5A0u;
    // 8019A5A0: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A5A4:
    ctx->pc = 0x8019A5A4u;
    // 8019A5A4: rlwinm r0, r0, 0, 0, 30
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFEu;
    }

label_8019A5A8:
    ctx->pc = 0x8019A5A8u;
    // 8019A5A8: or   r0, r0, r4
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[4];
    }

label_8019A5AC:
    ctx->pc = 0x8019A5ACu;
    // 8019A5AC: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A5B0:
    ctx->pc = 0x8019A5B0u;
    // 8019A5B0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A5B4:
    ctx->pc = 0x8019A5B4u;
    // 8019A5B4: lwzu     r0, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

label_8019A5B8:
    ctx->pc = 0x8019A5B8u;
    // 8019A5B8: rlwinm r0, r0, 0, 31, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0xFFFFFFFDu;
    }

label_8019A5BC:
    ctx->pc = 0x8019A5BCu;
    // 8019A5BC: or   r0, r0, r6
    {
        ctx->gpr[0] = ctx->gpr[0] | ctx->gpr[6];
    }

label_8019A5C0:
    ctx->pc = 0x8019A5C0u;
    // 8019A5C0: stw     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A5C4:
    ctx->pc = 0x8019A5C4u;
    // 8019A5C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A5C8:
    ctx->pc = 0x8019A5C8u;
    ctx->downcount -= 45;
    // 8019A5C8: addi    r0, r3, -1
    ctx->gpr[0] = ctx->gpr[3] + (u32)(s32)(-1);

label_8019A5CC:
    ctx->pc = 0x8019A5CCu;
    // 8019A5CC: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8019A5D0:
    ctx->pc = 0x8019A5D0u;
    // 8019A5D0: divwu   r5, r0, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[5] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_8019A5D4:
    ctx->pc = 0x8019A5D4u;
    // 8019A5D4: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A5D8:
    ctx->pc = 0x8019A5D8u;
    // 8019A5D8: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8019A5DC:
    ctx->pc = 0x8019A5DCu;
    // 8019A5DC: bc    4, 1, 0x8019A60C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A60C;
        }
    }

label_8019A5E0:
    ctx->pc = 0x8019A5E0u;
    ctx->downcount -= 2;
    // 8019A5E0: cmplwi  r4, 0x0100
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0100u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A5E4:
    ctx->pc = 0x8019A5E4u;
    // 8019A5E4: bc    4, 0, 0x8019A60C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A60C;
        }
    }

label_8019A5E8:
    ctx->pc = 0x8019A5E8u;
    ctx->downcount -= 1;
    // 8019A5E8: b       0x8019A5F0
    {
            goto label_8019A5F0;
    }

label_8019A5EC:
    loop_8019A5EC(ctx);
    if (ctx->pc == 0x8019A5F8u) goto label_8019A5F8;
    return;
label_8019A5F0:
    ctx->downcount -= 2;
    // 8019A5F0: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A5F4:
    // 8019A5F4: bc    12, 2, 0x8019A5EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A5ECu;
                return;
            }
            goto label_8019A5EC;
        }
    }

label_8019A5F8:
    ctx->pc = 0x8019A5F8u;
    ctx->downcount -= 47;
    // 8019A5F8: divwu   r0, r3, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[3] / divisor;
    }

label_8019A5FC:
    ctx->pc = 0x8019A5FCu;
    // 8019A5FC: mullw   r0, r0, r4
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[0] = (u32)product;
    }

label_8019A600:
    ctx->pc = 0x8019A600u;
    // 8019A600: subf.   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A604:
    ctx->pc = 0x8019A604u;
    // 8019A604: bc    4, 2, 0x8019A60C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A60C;
        }
    }

label_8019A608:
    ctx->pc = 0x8019A608u;
    ctx->downcount -= 1;
    // 8019A608: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8019A60C:
    ctx->pc = 0x8019A60Cu;
    ctx->downcount -= 2;
    // 8019A60C: cmplwi  r5, 0x0400
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0400u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A610:
    ctx->pc = 0x8019A610u;
    // 8019A610: bc    4, 1, 0x8019A618
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A618;
        }
    }

label_8019A614:
    ctx->pc = 0x8019A614u;
    ctx->downcount -= 1;
    // 8019A614: li      r5, 1024
    ctx->gpr[5] = (u32)(s32)(1024);

label_8019A618:
    ctx->pc = 0x8019A618u;
    ctx->downcount -= 2;
    // 8019A618: or   r3, r5, r5
    {
        ctx->gpr[3] = ctx->gpr[5] | ctx->gpr[5];
    }

label_8019A61C:
    ctx->pc = 0x8019A61Cu;
    // 8019A61C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A620:
    ctx->pc = 0x8019A620u;
    ctx->downcount -= 24;
    // 8019A620: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8019A624:
    ctx->pc = 0x8019A624u;
    // 8019A624: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A628:
    ctx->pc = 0x8019A628u;
    // 8019A628: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019A62C:
    ctx->pc = 0x8019A62Cu;
    // 8019A62C: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019A630:
    ctx->pc = 0x8019A630u;
    // 8019A630: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019A634:
    ctx->pc = 0x8019A634u;
    // 8019A634: lfs     f0, -22216(r13)
    if (!ppc_fp_available(ctx, 0x8019A634u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019A638:
    ctx->pc = 0x8019A638u;
    // 8019A638: fdivs   f1, f0, f1
    if (!ppc_fp_available(ctx, 0x8019A638u)) return;
    ppc_fdivs(ctx, 1, 0, 1);

label_8019A63C:
    ctx->pc = 0x8019A63Cu;
    // 8019A63C: bl      0x80163274
    {
            ctx->lr = 0x8019A640u;
            ctx->pc = 0x80163274u;
            return;
    }

label_8019A640:
    ctx->pc = 0x8019A640u;
    ctx->downcount -= 47;
    // 8019A640: rlwinm r5, r31, 0, 16, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[31], 0u) & 0x0000FFFFu;
    }

label_8019A644:
    ctx->pc = 0x8019A644u;
    // 8019A644: addi    r0, r5, -1
    ctx->gpr[0] = ctx->gpr[5] + (u32)(s32)(-1);

label_8019A648:
    ctx->pc = 0x8019A648u;
    // 8019A648: rlwinm r4, r3, 0, 23, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000001FFu;
    }

label_8019A64C:
    ctx->pc = 0x8019A64Cu;
    // 8019A64C: rlwinm r0, r0, 8, 0, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8019A650:
    ctx->pc = 0x8019A650u;
    // 8019A650: divwu   r3, r0, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[3] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_8019A654:
    ctx->pc = 0x8019A654u;
    // 8019A654: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A658:
    ctx->pc = 0x8019A658u;
    // 8019A658: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A65C:
    ctx->pc = 0x8019A65Cu;
    // 8019A65C: bc    4, 1, 0x8019A68C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A68C;
        }
    }

label_8019A660:
    ctx->pc = 0x8019A660u;
    ctx->downcount -= 2;
    // 8019A660: cmplwi  r4, 0x0100
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0100u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A664:
    ctx->pc = 0x8019A664u;
    // 8019A664: bc    4, 0, 0x8019A68C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A68C;
        }
    }

label_8019A668:
    ctx->pc = 0x8019A668u;
    ctx->downcount -= 1;
    // 8019A668: b       0x8019A670
    {
            goto label_8019A670;
    }

label_8019A66C:
    loop_8019A66C(ctx);
    if (ctx->pc == 0x8019A678u) goto label_8019A678;
    return;
label_8019A670:
    ctx->downcount -= 2;
    // 8019A670: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A674:
    // 8019A674: bc    12, 2, 0x8019A66C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A66Cu;
                return;
            }
            goto label_8019A66C;
        }
    }

label_8019A678:
    ctx->pc = 0x8019A678u;
    ctx->downcount -= 47;
    // 8019A678: divwu   r0, r5, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[5] / divisor;
    }

label_8019A67C:
    ctx->pc = 0x8019A67Cu;
    // 8019A67C: mullw   r0, r0, r4
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[0] = (u32)product;
    }

label_8019A680:
    ctx->pc = 0x8019A680u;
    // 8019A680: subf.   r0, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A684:
    ctx->pc = 0x8019A684u;
    // 8019A684: bc    4, 2, 0x8019A68C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A68C;
        }
    }

label_8019A688:
    ctx->pc = 0x8019A688u;
    ctx->downcount -= 1;
    // 8019A688: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A68C:
    ctx->pc = 0x8019A68Cu;
    ctx->downcount -= 2;
    // 8019A68C: cmplwi  r3, 0x0400
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0400u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A690:
    ctx->pc = 0x8019A690u;
    // 8019A690: bc    4, 1, 0x8019A698
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A698;
        }
    }

label_8019A694:
    ctx->pc = 0x8019A694u;
    ctx->downcount -= 1;
    // 8019A694: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_8019A698:
    ctx->pc = 0x8019A698u;
    ctx->downcount -= 7;
    // 8019A698: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A69C:
    ctx->pc = 0x8019A69Cu;
    // 8019A69C: rlwinm r3, r3, 0, 16, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8019A6A0:
    ctx->pc = 0x8019A6A0u;
    // 8019A6A0: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019A6A4:
    ctx->pc = 0x8019A6A4u;
    // 8019A6A4: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8019A6A8:
    ctx->pc = 0x8019A6A8u;
    // 8019A6A8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019A6AC:
    ctx->pc = 0x8019A6ACu;
    // 8019A6AC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A6B0:
    ctx->pc = 0x8019A6B0u;
    ctx->downcount -= 69;
    // 8019A6B0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8019A6B4:
    ctx->pc = 0x8019A6B4u;
    // 8019A6B4: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A6B8:
    ctx->pc = 0x8019A6B8u;
    // 8019A6B8: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_8019A6BC:
    ctx->pc = 0x8019A6BCu;
    // 8019A6BC: stwu     r1, -120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-120);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019A6C0:
    ctx->pc = 0x8019A6C0u;
    // 8019A6C0: stfd     f31, 112(r1)
    if (!ppc_fp_available(ctx, 0x8019A6C0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_8019A6C4:
    ctx->pc = 0x8019A6C4u;
    // 8019A6C4: stfd     f30, 104(r1)
    if (!ppc_fp_available(ctx, 0x8019A6C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_8019A6C8:
    ctx->pc = 0x8019A6C8u;
    // 8019A6C8: stfd     f29, 96(r1)
    if (!ppc_fp_available(ctx, 0x8019A6C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_8019A6CC:
    ctx->pc = 0x8019A6CCu;
    // 8019A6CC: stfd     f28, 88(r1)
    if (!ppc_fp_available(ctx, 0x8019A6CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[28]));
    }

label_8019A6D0:
    ctx->pc = 0x8019A6D0u;
    // 8019A6D0: stmw     r25, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        for (u32 r = 25; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8019A6D4:
    ctx->pc = 0x8019A6D4u;
    // 8019A6D4: rlwinm r28, r4, 0, 16, 31
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x0000FFFFu;
    }

label_8019A6D8:
    ctx->pc = 0x8019A6D8u;
    // 8019A6D8: rlwinm r31, r3, 0, 16, 31
    {
        ctx->gpr[31] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x0000FFFFu;
    }

label_8019A6DC:
    ctx->pc = 0x8019A6DCu;
    // 8019A6DC: stw     r28, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8019A6E0:
    ctx->pc = 0x8019A6E0u;
    // 8019A6E0: or   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019A6E4:
    ctx->pc = 0x8019A6E4u;
    // 8019A6E4: or   r25, r4, r4
    {
        ctx->gpr[25] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8019A6E8:
    ctx->pc = 0x8019A6E8u;
    // 8019A6E8: stw     r31, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019A6EC:
    ctx->pc = 0x8019A6ECu;
    // 8019A6EC: stw     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A6F0:
    ctx->pc = 0x8019A6F0u;
    // 8019A6F0: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A6F4:
    ctx->pc = 0x8019A6F4u;
    // 8019A6F4: lfd     f3, -22208(r13)
    if (!ppc_fp_available(ctx, 0x8019A6F4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22208);
        ctx->fpr[3] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A6F8:
    ctx->pc = 0x8019A6F8u;
    // 8019A6F8: lfd     f2, 48(r1)
    if (!ppc_fp_available(ctx, 0x8019A6F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[2] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A6FC:
    ctx->pc = 0x8019A6FCu;
    // 8019A6FC: lfd     f1, 40(r1)
    if (!ppc_fp_available(ctx, 0x8019A6FCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A700:
    ctx->pc = 0x8019A700u;
    // 8019A700: fsubs   f2, f2, f3
    if (!ppc_fp_available(ctx, 0x8019A700u)) return;
    ppc_fsubs(ctx, 2, 2, 3);

label_8019A704:
    ctx->pc = 0x8019A704u;
    // 8019A704: lfs     f0, -22216(r13)
    if (!ppc_fp_available(ctx, 0x8019A704u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019A708:
    ctx->pc = 0x8019A708u;
    // 8019A708: fsubs   f1, f1, f3
    if (!ppc_fp_available(ctx, 0x8019A708u)) return;
    ppc_fsubs(ctx, 1, 1, 3);

label_8019A70C:
    ctx->pc = 0x8019A70Cu;
    // 8019A70C: fdivs   f2, f2, f1
    if (!ppc_fp_available(ctx, 0x8019A70Cu)) return;
    ppc_fdivs(ctx, 2, 2, 1);

label_8019A710:
    ctx->pc = 0x8019A710u;
    // 8019A710: fdivs   f1, f0, f2
    if (!ppc_fp_available(ctx, 0x8019A710u)) return;
    ppc_fdivs(ctx, 1, 0, 2);

label_8019A714:
    ctx->pc = 0x8019A714u;
    // 8019A714: fmr    f28, f2
    if (!ppc_fp_available(ctx, 0x8019A714u)) return;
    ctx->fpr[28] = ctx->fpr[2];

label_8019A718:
    ctx->pc = 0x8019A718u;
    // 8019A718: bl      0x80163274
    {
            ctx->lr = 0x8019A71Cu;
            ctx->pc = 0x80163274u;
            return;
    }

label_8019A71C:
    ctx->pc = 0x8019A71Cu;
    ctx->downcount -= 46;
    // 8019A71C: addi    r0, r31, -1
    ctx->gpr[0] = ctx->gpr[31] + (u32)(s32)(-1);

label_8019A720:
    ctx->pc = 0x8019A720u;
    // 8019A720: rlwinm r4, r3, 0, 23, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000001FFu;
    }

label_8019A724:
    ctx->pc = 0x8019A724u;
    // 8019A724: rlwinm r30, r0, 8, 0, 23
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 8u) & 0xFFFFFF00u;
    }

label_8019A728:
    ctx->pc = 0x8019A728u;
    // 8019A728: divwu   r3, r30, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[3] = divisor == 0 ? 0u : ctx->gpr[30] / divisor;
    }

label_8019A72C:
    ctx->pc = 0x8019A72Cu;
    // 8019A72C: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A730:
    ctx->pc = 0x8019A730u;
    // 8019A730: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A734:
    ctx->pc = 0x8019A734u;
    // 8019A734: bc    4, 1, 0x8019A764
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A764;
        }
    }

label_8019A738:
    ctx->pc = 0x8019A738u;
    ctx->downcount -= 2;
    // 8019A738: cmplwi  r4, 0x0100
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0100u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A73C:
    ctx->pc = 0x8019A73Cu;
    // 8019A73C: bc    4, 0, 0x8019A764
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A764;
        }
    }

label_8019A740:
    ctx->pc = 0x8019A740u;
    ctx->downcount -= 1;
    // 8019A740: b       0x8019A748
    {
            goto label_8019A748;
    }

label_8019A744:
    loop_8019A744(ctx);
    if (ctx->pc == 0x8019A750u) goto label_8019A750;
    return;
label_8019A748:
    ctx->downcount -= 2;
    // 8019A748: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A74C:
    // 8019A74C: bc    12, 2, 0x8019A744
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A744u;
                return;
            }
            goto label_8019A744;
        }
    }

label_8019A750:
    ctx->pc = 0x8019A750u;
    ctx->downcount -= 47;
    // 8019A750: divwu   r0, r31, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[31] / divisor;
    }

label_8019A754:
    ctx->pc = 0x8019A754u;
    // 8019A754: mullw   r0, r0, r4
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[0] = (u32)product;
    }

label_8019A758:
    ctx->pc = 0x8019A758u;
    // 8019A758: subf.   r0, r0, r31
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A75C:
    ctx->pc = 0x8019A75Cu;
    // 8019A75C: bc    4, 2, 0x8019A764
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A764;
        }
    }

label_8019A760:
    ctx->pc = 0x8019A760u;
    ctx->downcount -= 1;
    // 8019A760: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A764:
    ctx->pc = 0x8019A764u;
    ctx->downcount -= 2;
    // 8019A764: cmplwi  r3, 0x0400
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0400u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A768:
    ctx->pc = 0x8019A768u;
    // 8019A768: bc    4, 1, 0x8019A770
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A770;
        }
    }

label_8019A76C:
    ctx->pc = 0x8019A76Cu;
    ctx->downcount -= 1;
    // 8019A76C: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_8019A770:
    ctx->pc = 0x8019A770u;
    ctx->downcount -= 7;
    // 8019A770: lfd     f31, -22208(r13)
    if (!ppc_fp_available(ctx, 0x8019A770u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22208);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A774:
    ctx->pc = 0x8019A774u;
    // 8019A774: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019A778:
    ctx->pc = 0x8019A778u;
    // 8019A778: lfs     f30, -22216(r13)
    if (!ppc_fp_available(ctx, 0x8019A778u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_8019A77C:
    ctx->pc = 0x8019A77Cu;
    // 8019A77C: rlwinm r29, r25, 0, 16, 31
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[25], 0u) & 0x0000FFFFu;
    }

label_8019A780:
    ctx->pc = 0x8019A780u;
    // 8019A780: rlwinm r26, r27, 0, 16, 31
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[27], 0u) & 0x0000FFFFu;
    }

label_8019A784:
    ctx->pc = 0x8019A784u;
    // 8019A784: lis     r25, 17200
    ctx->gpr[25] = ((u32)(s32)(17200) << 16);

label_8019A788:
    ctx->pc = 0x8019A788u;
    // 8019A788: b       0x8019A810
    {
            goto label_8019A810;
    }

label_8019A78C:
    ctx->downcount -= 45;
    // 8019A78C: addi    r28, r28, -1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(-1);

label_8019A790:
    ctx->pc = 0x8019A790u;
    // 8019A790: stw     r26, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_8019A794:
    ctx->pc = 0x8019A794u;
    // 8019A794: stw     r28, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8019A798:
    ctx->pc = 0x8019A798u;
    // 8019A798: stw     r25, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8019A79C:
    ctx->pc = 0x8019A79Cu;
    // 8019A79C: stw     r25, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_8019A7A0:
    ctx->pc = 0x8019A7A0u;
    // 8019A7A0: lfd     f1, 40(r1)
    if (!ppc_fp_available(ctx, 0x8019A7A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A7A4:
    ctx->pc = 0x8019A7A4u;
    // 8019A7A4: lfd     f0, 48(r1)
    if (!ppc_fp_available(ctx, 0x8019A7A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A7A8:
    ctx->pc = 0x8019A7A8u;
    // 8019A7A8: fsubs   f1, f1, f31
    if (!ppc_fp_available(ctx, 0x8019A7A8u)) return;
    ppc_fsubs(ctx, 1, 1, 31);

label_8019A7AC:
    ctx->pc = 0x8019A7ACu;
    // 8019A7AC: fsubs   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x8019A7ACu)) return;
    ppc_fsubs(ctx, 0, 0, 31);

label_8019A7B0:
    ctx->pc = 0x8019A7B0u;
    // 8019A7B0: fdivs   f0, f1, f0
    if (!ppc_fp_available(ctx, 0x8019A7B0u)) return;
    ppc_fdivs(ctx, 0, 1, 0);

label_8019A7B4:
    ctx->pc = 0x8019A7B4u;
    // 8019A7B4: fdivs   f1, f30, f0
    if (!ppc_fp_available(ctx, 0x8019A7B4u)) return;
    ppc_fdivs(ctx, 1, 30, 0);

label_8019A7B8:
    ctx->pc = 0x8019A7B8u;
    // 8019A7B8: fmr    f28, f0
    if (!ppc_fp_available(ctx, 0x8019A7B8u)) return;
    ctx->fpr[28] = ctx->fpr[0];

label_8019A7BC:
    // 8019A7BC: bl      0x80163274
    {
            ctx->lr = 0x8019A7C0u;
            ctx->pc = 0x80163274u;
            return;
    }

label_8019A7C0:
    ctx->downcount -= 44;
    // 8019A7C0: rlwinm r4, r3, 0, 23, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000001FFu;
    }

label_8019A7C4:
    // 8019A7C4: divwu   r3, r30, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[3] = divisor == 0 ? 0u : ctx->gpr[30] / divisor;
    }

label_8019A7C8:
    // 8019A7C8: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A7CC:
    // 8019A7CC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A7D0:
    // 8019A7D0: bc    4, 1, 0x8019A800
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A800;
        }
    }

label_8019A7D4:
    ctx->downcount -= 2;
    // 8019A7D4: cmplwi  r4, 0x0100
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0100u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A7D8:
    // 8019A7D8: bc    4, 0, 0x8019A800
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A800;
        }
    }

label_8019A7DC:
    ctx->downcount -= 1;
    // 8019A7DC: b       0x8019A7E4
    {
            goto label_8019A7E4;
    }

label_8019A7E0:
    loop_8019A7E0(ctx);
    if (ctx->pc == 0x8019A7ECu) goto label_8019A7EC;
    return;
label_8019A7E4:
    ctx->downcount -= 2;
    // 8019A7E4: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A7E8:
    // 8019A7E8: bc    12, 2, 0x8019A7E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A7E0u;
                return;
            }
            goto label_8019A7E0;
        }
    }

label_8019A7EC:
    ctx->downcount -= 47;
    // 8019A7EC: divwu   r0, r31, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[31] / divisor;
    }

label_8019A7F0:
    // 8019A7F0: mullw   r0, r0, r4
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[0] = (u32)product;
    }

label_8019A7F4:
    // 8019A7F4: subf.   r0, r0, r31
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A7F8:
    // 8019A7F8: bc    4, 2, 0x8019A800
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A800;
        }
    }

label_8019A7FC:
    ctx->downcount -= 1;
    // 8019A7FC: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A800:
    ctx->downcount -= 2;
    // 8019A800: cmplwi  r3, 0x0400
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0400u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A804:
    // 8019A804: bc    4, 1, 0x8019A80C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A80C;
        }
    }

label_8019A808:
    ctx->downcount -= 1;
    // 8019A808: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_8019A80C:
    ctx->downcount -= 1;
    // 8019A80C: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019A810:
    ctx->downcount -= 2;
    // 8019A810: cmplw   r0, r29
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A814:
    // 8019A814: bc    12, 1, 0x8019A78C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A78Cu;
                return;
            }
            goto label_8019A78C;
        }
    }

label_8019A818:
    ctx->pc = 0x8019A818u;
    ctx->downcount -= 6;
    // 8019A818: fmr    f29, f28
    if (!ppc_fp_available(ctx, 0x8019A818u)) return;
    ctx->fpr[29] = ctx->fpr[28];

label_8019A81C:
    ctx->pc = 0x8019A81Cu;
    // 8019A81C: lfd     f30, -22208(r13)
    if (!ppc_fp_available(ctx, 0x8019A81Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22208);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A820:
    ctx->pc = 0x8019A820u;
    // 8019A820: lfs     f31, -22216(r13)
    if (!ppc_fp_available(ctx, 0x8019A820u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_8019A824:
    ctx->pc = 0x8019A824u;
    // 8019A824: rlwinm r27, r27, 0, 16, 31
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[27], 0u) & 0x0000FFFFu;
    }

label_8019A828:
    ctx->pc = 0x8019A828u;
    // 8019A828: lis     r26, 17200
    ctx->gpr[26] = ((u32)(s32)(17200) << 16);

label_8019A82C:
    ctx->pc = 0x8019A82Cu;
    // 8019A82C: b       0x8019A8B8
    {
            goto label_8019A8B8;
    }

label_8019A830:
    ctx->downcount -= 46;
    // 8019A830: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_8019A834:
    ctx->pc = 0x8019A834u;
    // 8019A834: stw     r27, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8019A838:
    ctx->pc = 0x8019A838u;
    // 8019A838: fmr    f29, f28
    if (!ppc_fp_available(ctx, 0x8019A838u)) return;
    ctx->fpr[29] = ctx->fpr[28];

label_8019A83C:
    ctx->pc = 0x8019A83Cu;
    // 8019A83C: stw     r28, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8019A840:
    ctx->pc = 0x8019A840u;
    // 8019A840: stw     r26, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_8019A844:
    ctx->pc = 0x8019A844u;
    // 8019A844: stw     r26, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_8019A848:
    ctx->pc = 0x8019A848u;
    // 8019A848: lfd     f1, 40(r1)
    if (!ppc_fp_available(ctx, 0x8019A848u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[1] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A84C:
    ctx->pc = 0x8019A84Cu;
    // 8019A84C: lfd     f0, 48(r1)
    if (!ppc_fp_available(ctx, 0x8019A84Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A850:
    ctx->pc = 0x8019A850u;
    // 8019A850: fsubs   f1, f1, f30
    if (!ppc_fp_available(ctx, 0x8019A850u)) return;
    ppc_fsubs(ctx, 1, 1, 30);

label_8019A854:
    ctx->pc = 0x8019A854u;
    // 8019A854: fsubs   f0, f0, f30
    if (!ppc_fp_available(ctx, 0x8019A854u)) return;
    ppc_fsubs(ctx, 0, 0, 30);

label_8019A858:
    ctx->pc = 0x8019A858u;
    // 8019A858: fdivs   f0, f1, f0
    if (!ppc_fp_available(ctx, 0x8019A858u)) return;
    ppc_fdivs(ctx, 0, 1, 0);

label_8019A85C:
    ctx->pc = 0x8019A85Cu;
    // 8019A85C: fdivs   f1, f31, f0
    if (!ppc_fp_available(ctx, 0x8019A85Cu)) return;
    ppc_fdivs(ctx, 1, 31, 0);

label_8019A860:
    ctx->pc = 0x8019A860u;
    // 8019A860: fmr    f28, f0
    if (!ppc_fp_available(ctx, 0x8019A860u)) return;
    ctx->fpr[28] = ctx->fpr[0];

label_8019A864:
    // 8019A864: bl      0x80163274
    {
            ctx->lr = 0x8019A868u;
            ctx->pc = 0x80163274u;
            return;
    }

label_8019A868:
    ctx->downcount -= 44;
    // 8019A868: rlwinm r4, r3, 0, 23, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000001FFu;
    }

label_8019A86C:
    // 8019A86C: divwu   r3, r30, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[3] = divisor == 0 ? 0u : ctx->gpr[30] / divisor;
    }

label_8019A870:
    // 8019A870: cmplwi  r4, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A874:
    // 8019A874: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A878:
    // 8019A878: bc    4, 1, 0x8019A8A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A8A8;
        }
    }

label_8019A87C:
    ctx->downcount -= 2;
    // 8019A87C: cmplwi  r4, 0x0100
    {
        u32 val_a = (u32)(ctx->gpr[4]);
        u32 val_b = (u32)(0x0100u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A880:
    // 8019A880: bc    4, 0, 0x8019A8A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A8A8;
        }
    }

label_8019A884:
    ctx->downcount -= 1;
    // 8019A884: b       0x8019A88C
    {
            goto label_8019A88C;
    }

label_8019A888:
    loop_8019A888(ctx);
    if (ctx->pc == 0x8019A894u) goto label_8019A894;
    return;
label_8019A88C:
    ctx->downcount -= 2;
    // 8019A88C: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A890:
    // 8019A890: bc    12, 2, 0x8019A888
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A888u;
                return;
            }
            goto label_8019A888;
        }
    }

label_8019A894:
    ctx->downcount -= 47;
    // 8019A894: divwu   r0, r31, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[31] / divisor;
    }

label_8019A898:
    // 8019A898: mullw   r0, r0, r4
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[0] = (u32)product;
    }

label_8019A89C:
    // 8019A89C: subf.   r0, r0, r31
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[31];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A8A0:
    // 8019A8A0: bc    4, 2, 0x8019A8A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A8A8;
        }
    }

label_8019A8A4:
    ctx->downcount -= 1;
    // 8019A8A4: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A8A8:
    ctx->downcount -= 2;
    // 8019A8A8: cmplwi  r3, 0x0400
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0400u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A8AC:
    // 8019A8AC: bc    4, 1, 0x8019A8B4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A8B4;
        }
    }

label_8019A8B0:
    ctx->downcount -= 1;
    // 8019A8B0: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_8019A8B4:
    ctx->downcount -= 1;
    // 8019A8B4: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8019A8B8:
    ctx->downcount -= 2;
    // 8019A8B8: cmplw   r0, r29
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A8BC:
    // 8019A8BC: bc    12, 0, 0x8019A830
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A830u;
                return;
            }
            goto label_8019A830;
        }
    }

label_8019A8C0:
    ctx->pc = 0x8019A8C0u;
    ctx->downcount -= 21;
    // 8019A8C0: lmw     r25, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        for (u32 r = 25; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8019A8C4:
    ctx->pc = 0x8019A8C4u;
    // 8019A8C4: fmr    f1, f29
    if (!ppc_fp_available(ctx, 0x8019A8C4u)) return;
    ctx->fpr[1] = ctx->fpr[29];

label_8019A8C8:
    ctx->pc = 0x8019A8C8u;
    // 8019A8C8: lwz     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A8CC:
    ctx->pc = 0x8019A8CCu;
    // 8019A8CC: lfd     f31, 112(r1)
    if (!ppc_fp_available(ctx, 0x8019A8CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A8D0:
    ctx->pc = 0x8019A8D0u;
    // 8019A8D0: lfd     f30, 104(r1)
    if (!ppc_fp_available(ctx, 0x8019A8D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A8D4:
    ctx->pc = 0x8019A8D4u;
    // 8019A8D4: lfd     f29, 96(r1)
    if (!ppc_fp_available(ctx, 0x8019A8D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A8D8:
    ctx->pc = 0x8019A8D8u;
    // 8019A8D8: lfd     f28, 88(r1)
    if (!ppc_fp_available(ctx, 0x8019A8D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[28] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_8019A8DC:
    ctx->pc = 0x8019A8DCu;
    // 8019A8DC: addi    r1, r1, 120
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(120);

label_8019A8E0:
    ctx->pc = 0x8019A8E0u;
    // 8019A8E0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019A8E4:
    ctx->pc = 0x8019A8E4u;
    // 8019A8E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A8E8:
    ctx->pc = 0x8019A8E8u;
    ctx->downcount -= 22;
    // 8019A8E8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8019A8EC:
    ctx->pc = 0x8019A8ECu;
    // 8019A8EC: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A8F0:
    ctx->pc = 0x8019A8F0u;
    // 8019A8F0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019A8F4:
    ctx->pc = 0x8019A8F4u;
    // 8019A8F4: lfs     f0, -22216(r13)
    if (!ppc_fp_available(ctx, 0x8019A8F4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22216);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019A8F8:
    ctx->pc = 0x8019A8F8u;
    // 8019A8F8: fdivs   f1, f0, f1
    if (!ppc_fp_available(ctx, 0x8019A8F8u)) return;
    ppc_fdivs(ctx, 1, 0, 1);

label_8019A8FC:
    ctx->pc = 0x8019A8FCu;
    // 8019A8FC: bl      0x80163274
    {
            ctx->lr = 0x8019A900u;
            ctx->pc = 0x80163274u;
            return;
    }

label_8019A900:
    ctx->pc = 0x8019A900u;
    ctx->downcount -= 68;
    // 8019A900: rlwinm r6, r3, 0, 23, 31
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000001FFu;
    }

label_8019A904:
    ctx->pc = 0x8019A904u;
    // 8019A904: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A908:
    ctx->pc = 0x8019A908u;
    // 8019A908: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8019A90C:
    ctx->pc = 0x8019A90Cu;
    // 8019A90C: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_8019A910:
    ctx->pc = 0x8019A910u;
    // 8019A910: stb     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019A914:
    ctx->pc = 0x8019A914u;
    // 8019A914: oris    r0, r6, 0x4E00
    ctx->gpr[0] = ctx->gpr[6] | (0x4E00u << 16);

label_8019A918:
    ctx->pc = 0x8019A918u;
    // 8019A918: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8019A91C:
    ctx->pc = 0x8019A91Cu;
    // 8019A91C: stw     r0, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A920:
    ctx->pc = 0x8019A920u;
    // 8019A920: subfic  r3, r6, 256
    {
        u64 res = (u64)(u32)(s32)(256) + (u64)(~ctx->gpr[6]) + 1u;
        ctx->gpr[3] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8019A924:
    ctx->pc = 0x8019A924u;
    // 8019A924: addic   r0, r3, -1
    {
        u64 a = ctx->gpr[3];
        u64 b = (u32)(s32)(-1);
        u64 res = a + b;
        ctx->gpr[0] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8019A928:
    ctx->pc = 0x8019A928u;
    // 8019A928: sth     r5, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[5]);
    }

label_8019A92C:
    ctx->pc = 0x8019A92Cu;
    // 8019A92C: subfe   r0, r0, r3
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[3];
        u32 carry = (ctx->xer >> 29) & 1u;
        u64 wide = (u64)a + (u64)b + carry;
        u32 res = (u32)wide;
        ctx->gpr[0] = res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(wide >> 32) & 1u) << 29);
    }

label_8019A930:
    ctx->pc = 0x8019A930u;
    // 8019A930: rlwinm r0, r0, 10, 14, 21
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 10u) & 0x0003FC00u;
    }

label_8019A934:
    ctx->pc = 0x8019A934u;
    // 8019A934: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A938:
    ctx->pc = 0x8019A938u;
    // 8019A938: cmplwi  r6, 0x0080
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0080u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A93C:
    ctx->pc = 0x8019A93Cu;
    // 8019A93C: addi    r4, r6, 0
    ctx->gpr[4] = ctx->gpr[6] + (u32)(s32)(0);

label_8019A940:
    ctx->pc = 0x8019A940u;
    // 8019A940: addi    r5, r3, 492
    ctx->gpr[5] = ctx->gpr[3] + (u32)(s32)(492);

label_8019A944:
    ctx->pc = 0x8019A944u;
    // 8019A944: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A948:
    ctx->pc = 0x8019A948u;
    // 8019A948: rlwinm r3, r3, 0, 22, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFBFFu;
    }

label_8019A94C:
    ctx->pc = 0x8019A94Cu;
    // 8019A94C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019A950:
    ctx->pc = 0x8019A950u;
    // 8019A950: stw     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019A954:
    ctx->pc = 0x8019A954u;
    // 8019A954: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019A958:
    ctx->pc = 0x8019A958u;
    // 8019A958: lwz     r0, 484(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(484);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A95C:
    ctx->pc = 0x8019A95Cu;
    // 8019A95C: rlwinm r5, r0, 22, 22, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 22u) & 0x000003FFu;
    }

label_8019A960:
    ctx->pc = 0x8019A960u;
    // 8019A960: rlwinm r0, r0, 30, 14, 23
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 30u) & 0x0003FF00u;
    }

label_8019A964:
    ctx->pc = 0x8019A964u;
    // 8019A964: divwu   r3, r0, r6
    {
        u32 divisor = ctx->gpr[6];
        ctx->gpr[3] = divisor == 0 ? 0u : ctx->gpr[0] / divisor;
    }

label_8019A968:
    ctx->pc = 0x8019A968u;
    // 8019A968: addi    r5, r5, 1
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(1);

label_8019A96C:
    ctx->pc = 0x8019A96Cu;
    // 8019A96C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A970:
    ctx->pc = 0x8019A970u;
    // 8019A970: bc    4, 1, 0x8019A9A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A9A0;
        }
    }

label_8019A974:
    ctx->pc = 0x8019A974u;
    ctx->downcount -= 2;
    // 8019A974: cmplwi  r6, 0x0100
    {
        u32 val_a = (u32)(ctx->gpr[6]);
        u32 val_b = (u32)(0x0100u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A978:
    ctx->pc = 0x8019A978u;
    // 8019A978: bc    4, 0, 0x8019A9A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A9A0;
        }
    }

label_8019A97C:
    ctx->pc = 0x8019A97Cu;
    ctx->downcount -= 1;
    // 8019A97C: b       0x8019A984
    {
            goto label_8019A984;
    }

label_8019A980:
    loop_8019A980(ctx);
    if (ctx->pc == 0x8019A98Cu) goto label_8019A98C;
    return;
label_8019A984:
    ctx->downcount -= 2;
    // 8019A984: rlwinm. r0, r4, 0, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00000001u;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A988:
    // 8019A988: bc    12, 2, 0x8019A980
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8019A980u;
                return;
            }
            goto label_8019A980;
        }
    }

label_8019A98C:
    ctx->pc = 0x8019A98Cu;
    ctx->downcount -= 47;
    // 8019A98C: divwu   r0, r5, r4
    {
        u32 divisor = ctx->gpr[4];
        ctx->gpr[0] = divisor == 0 ? 0u : ctx->gpr[5] / divisor;
    }

label_8019A990:
    ctx->pc = 0x8019A990u;
    // 8019A990: mullw   r0, r0, r4
    {
        s64 product = (s64)(s32)ctx->gpr[0] * (s64)(s32)ctx->gpr[4];
        ctx->gpr[0] = (u32)product;
    }

label_8019A994:
    ctx->pc = 0x8019A994u;
    // 8019A994: subf.   r0, r0, r5
    {
        u32 a = ~ctx->gpr[0];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019A998:
    ctx->pc = 0x8019A998u;
    // 8019A998: bc    4, 2, 0x8019A9A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A9A0;
        }
    }

label_8019A99C:
    ctx->pc = 0x8019A99Cu;
    ctx->downcount -= 1;
    // 8019A99C: addi    r3, r3, 1
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(1);

label_8019A9A0:
    ctx->pc = 0x8019A9A0u;
    ctx->downcount -= 2;
    // 8019A9A0: cmplwi  r3, 0x0400
    {
        u32 val_a = (u32)(ctx->gpr[3]);
        u32 val_b = (u32)(0x0400u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019A9A4:
    ctx->pc = 0x8019A9A4u;
    // 8019A9A4: bc    4, 1, 0x8019A9AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019A9AC;
        }
    }

label_8019A9A8:
    ctx->pc = 0x8019A9A8u;
    ctx->downcount -= 1;
    // 8019A9A8: li      r3, 1024
    ctx->gpr[3] = (u32)(s32)(1024);

label_8019A9AC:
    ctx->pc = 0x8019A9ACu;
    ctx->downcount -= 5;
    // 8019A9AC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019A9B0:
    ctx->pc = 0x8019A9B0u;
    // 8019A9B0: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8019A9B4:
    ctx->pc = 0x8019A9B4u;
    // 8019A9B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019A9B8:
    ctx->pc = 0x8019A9B8u;
    // 8019A9B8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019A9BC:
    ctx->pc = 0x8019A9BCu;
    ctx->downcount -= 26;
    // 8019A9BC: rlwinm r0, r4, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x00FFFFFFu;
    }

label_8019A9C0:
    ctx->pc = 0x8019A9C0u;
    // 8019A9C0: lbz     r4, 3(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(3);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8019A9C4:
    ctx->pc = 0x8019A9C4u;
    // 8019A9C4: lbz     r5, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8019A9C8:
    ctx->pc = 0x8019A9C8u;
    // 8019A9C8: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_8019A9CC:
    ctx->pc = 0x8019A9CCu;
    // 8019A9CC: rlwinm r7, r4, 8, 0, 23
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[4], 8u) & 0xFFFFFF00u;
    }

label_8019A9D0:
    ctx->pc = 0x8019A9D0u;
    // 8019A9D0: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019A9D4:
    ctx->pc = 0x8019A9D4u;
    // 8019A9D4: rlwimi r7, r5, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[5], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8019A9D8:
    ctx->pc = 0x8019A9D8u;
    // 8019A9D8: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019A9DC:
    ctx->pc = 0x8019A9DCu;
    // 8019A9DC: rlwinm r7, r7, 0, 8, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00FFFFFFu;
    }

label_8019A9E0:
    ctx->pc = 0x8019A9E0u;
    // 8019A9E0: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8019A9E4:
    ctx->pc = 0x8019A9E4u;
    // 8019A9E4: oris    r7, r7, 0x4F00
    ctx->gpr[7] = ctx->gpr[7] | (0x4F00u << 16);

label_8019A9E8:
    ctx->pc = 0x8019A9E8u;
    // 8019A9E8: stw     r7, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8019A9EC:
    ctx->pc = 0x8019A9ECu;
    // 8019A9EC: oris    r7, r0, 0x5100
    ctx->gpr[7] = ctx->gpr[0] | (0x5100u << 16);

label_8019A9F0:
    ctx->pc = 0x8019A9F0u;
    // 8019A9F0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019A9F4:
    ctx->pc = 0x8019A9F4u;
    // 8019A9F4: lbz     r8, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_8019A9F8:
    ctx->pc = 0x8019A9F8u;
    // 8019A9F8: lbz     r3, 1(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(1);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8019A9FC:
    ctx->pc = 0x8019A9FCu;
    // 8019A9FC: rlwinm r3, r3, 8, 0, 23
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_8019AA00:
    ctx->pc = 0x8019AA00u;
    // 8019AA00: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8019AA04:
    ctx->pc = 0x8019AA04u;
    // 8019AA04: rlwimi r3, r8, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[8], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8019AA08:
    ctx->pc = 0x8019AA08u;
    // 8019AA08: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_8019AA0C:
    ctx->pc = 0x8019AA0Cu;
    // 8019AA0C: oris    r3, r3, 0x5000
    ctx->gpr[3] = ctx->gpr[3] | (0x5000u << 16);

label_8019AA10:
    ctx->pc = 0x8019AA10u;
    // 8019AA10: stw     r3, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AA14:
    ctx->pc = 0x8019AA14u;
    // 8019AA14: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8019AA18:
    ctx->pc = 0x8019AA18u;
    // 8019AA18: stw     r7, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8019AA1C:
    ctx->pc = 0x8019AA1Cu;
    // 8019AA1C: sth     r0, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AA20:
    ctx->pc = 0x8019AA20u;
    // 8019AA20: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019AA24:
    ctx->pc = 0x8019AA24u;
    ctx->downcount -= 14;
    // 8019AA24: stwu     r1, -80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-80);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019AA28:
    ctx->pc = 0x8019AA28u;
    // 8019AA28: rlwinm. r0, r3, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AA2C:
    ctx->pc = 0x8019AA2Cu;
    // 8019AA2C: stmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8019AA30:
    ctx->pc = 0x8019AA30u;
    // 8019AA30: bc    12, 2, 0x8019AB58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AB58;
        }
    }

label_8019AA34:
    ctx->pc = 0x8019AA34u;
    ctx->downcount -= 73;
    // 8019AA34: lbz     r0, 1(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(1);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019AA38:
    ctx->pc = 0x8019AA38u;
    // 8019AA38: lbz     r3, 7(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(7);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8019AA3C:
    ctx->pc = 0x8019AA3Cu;
    // 8019AA3C: rlwinm r30, r0, 4, 0, 27
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_8019AA40:
    ctx->pc = 0x8019AA40u;
    // 8019AA40: lbz     r8, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_8019AA44:
    ctx->pc = 0x8019AA44u;
    // 8019AA44: lbz     r0, 19(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(19);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019AA48:
    ctx->pc = 0x8019AA48u;
    // 8019AA48: rlwinm r25, r3, 4, 0, 27
    {
        ctx->gpr[25] = dolrecomp_rotl32(ctx->gpr[3], 4u) & 0xFFFFFFF0u;
    }

label_8019AA4C:
    ctx->pc = 0x8019AA4Cu;
    // 8019AA4C: lbz     r10, 6(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(6);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_8019AA50:
    ctx->pc = 0x8019AA50u;
    // 8019AA50: rlwimi r30, r8, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[8], 0u);
        ctx->gpr[30] = (ctx->gpr[30] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_8019AA54:
    ctx->pc = 0x8019AA54u;
    // 8019AA54: lbz     r11, 2(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(2);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_8019AA58:
    ctx->pc = 0x8019AA58u;
    // 8019AA58: lbz     r7, 13(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(13);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8019AA5C:
    ctx->pc = 0x8019AA5Cu;
    // 8019AA5C: rlwimi r25, r10, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[10], 0u);
        ctx->gpr[25] = (ctx->gpr[25] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_8019AA60:
    ctx->pc = 0x8019AA60u;
    // 8019AA60: rlwinm r27, r11, 8, 0, 23
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[11], 8u) & 0xFFFFFF00u;
    }

label_8019AA64:
    ctx->pc = 0x8019AA64u;
    // 8019AA64: lbz     r9, 8(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_8019AA68:
    ctx->pc = 0x8019AA68u;
    // 8019AA68: lbz     r3, 14(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(14);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8019AA6C:
    ctx->pc = 0x8019AA6Cu;
    // 8019AA6C: rlwinm r26, r9, 8, 0, 23
    {
        ctx->gpr[26] = dolrecomp_rotl32(ctx->gpr[9], 8u) & 0xFFFFFF00u;
    }

label_8019AA70:
    ctx->pc = 0x8019AA70u;
    // 8019AA70: lbz     r28, 3(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(3);
        ctx->gpr[28] = mem_read8(ctx, ea);
    }

label_8019AA74:
    ctx->pc = 0x8019AA74u;
    // 8019AA74: rlwimi r27, r30, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[30], 0u);
        ctx->gpr[27] = (ctx->gpr[27] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8019AA78:
    ctx->pc = 0x8019AA78u;
    // 8019AA78: lbz     r9, 16(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read8(ctx, ea);
    }

label_8019AA7C:
    ctx->pc = 0x8019AA7Cu;
    // 8019AA7C: rlwinm r23, r7, 4, 0, 27
    {
        ctx->gpr[23] = dolrecomp_rotl32(ctx->gpr[7], 4u) & 0xFFFFFFF0u;
    }

label_8019AA80:
    ctx->pc = 0x8019AA80u;
    // 8019AA80: lbz     r12, 12(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(12);
        ctx->gpr[12] = mem_read8(ctx, ea);
    }

label_8019AA84:
    ctx->pc = 0x8019AA84u;
    // 8019AA84: lbz     r7, 21(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(21);
        ctx->gpr[7] = mem_read8(ctx, ea);
    }

label_8019AA88:
    ctx->pc = 0x8019AA88u;
    // 8019AA88: rlwinm r24, r3, 8, 0, 23
    {
        ctx->gpr[24] = dolrecomp_rotl32(ctx->gpr[3], 8u) & 0xFFFFFF00u;
    }

label_8019AA8C:
    ctx->pc = 0x8019AA8Cu;
    // 8019AA8C: rlwimi r23, r12, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[12], 0u);
        ctx->gpr[23] = (ctx->gpr[23] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_8019AA90:
    ctx->pc = 0x8019AA90u;
    // 8019AA90: lbz     r29, 18(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(18);
        ctx->gpr[29] = mem_read8(ctx, ea);
    }

label_8019AA94:
    ctx->pc = 0x8019AA94u;
    // 8019AA94: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_8019AA98:
    ctx->pc = 0x8019AA98u;
    // 8019AA98: rlwimi r0, r29, 0, 28, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[29], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x0000000Fu) | (rot & 0x0000000Fu);
    }

label_8019AA9C:
    ctx->pc = 0x8019AA9Cu;
    // 8019AA9C: lbz     r8, 20(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(20);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_8019AAA0:
    ctx->pc = 0x8019AAA0u;
    // 8019AAA0: rlwinm r28, r28, 12, 0, 19
    {
        ctx->gpr[28] = dolrecomp_rotl32(ctx->gpr[28], 12u) & 0xFFFFF000u;
    }

label_8019AAA4:
    ctx->pc = 0x8019AAA4u;
    // 8019AAA4: lbz     r31, 9(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(9);
        ctx->gpr[31] = mem_read8(ctx, ea);
    }

label_8019AAA8:
    ctx->pc = 0x8019AAA8u;
    // 8019AAA8: rlwimi r28, r27, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[27], 0u);
        ctx->gpr[28] = (ctx->gpr[28] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_8019AAAC:
    ctx->pc = 0x8019AAACu;
    // 8019AAAC: lbz     r29, 4(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(4);
        ctx->gpr[29] = mem_read8(ctx, ea);
    }

label_8019AAB0:
    ctx->pc = 0x8019AAB0u;
    // 8019AAB0: rlwimi r24, r23, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[23], 0u);
        ctx->gpr[24] = (ctx->gpr[24] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8019AAB4:
    ctx->pc = 0x8019AAB4u;
    // 8019AAB4: lbz     r10, 15(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(15);
        ctx->gpr[10] = mem_read8(ctx, ea);
    }

label_8019AAB8:
    ctx->pc = 0x8019AAB8u;
    // 8019AAB8: rlwinm r23, r8, 8, 0, 23
    {
        ctx->gpr[23] = dolrecomp_rotl32(ctx->gpr[8], 8u) & 0xFFFFFF00u;
    }

label_8019AABC:
    ctx->pc = 0x8019AABCu;
    // 8019AABC: lbz     r12, 10(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(10);
        ctx->gpr[12] = mem_read8(ctx, ea);
    }

label_8019AAC0:
    ctx->pc = 0x8019AAC0u;
    // 8019AAC0: rlwimi r26, r25, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[25], 0u);
        ctx->gpr[26] = (ctx->gpr[26] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8019AAC4:
    ctx->pc = 0x8019AAC4u;
    // 8019AAC4: lbz     r3, 22(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(22);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8019AAC8:
    ctx->pc = 0x8019AAC8u;
    // 8019AAC8: rlwinm r25, r10, 12, 0, 19
    {
        ctx->gpr[25] = dolrecomp_rotl32(ctx->gpr[10], 12u) & 0xFFFFF000u;
    }

label_8019AACC:
    ctx->pc = 0x8019AACCu;
    // 8019AACC: lbz     r30, 5(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(5);
        ctx->gpr[30] = mem_read8(ctx, ea);
    }

label_8019AAD0:
    ctx->pc = 0x8019AAD0u;
    // 8019AAD0: rlwimi r23, r0, 0, 24, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[0], 0u);
        ctx->gpr[23] = (ctx->gpr[23] & ~0x000000FFu) | (rot & 0x000000FFu);
    }

label_8019AAD4:
    ctx->pc = 0x8019AAD4u;
    // 8019AAD4: lbz     r0, 23(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(23);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019AAD8:
    ctx->pc = 0x8019AAD8u;
    // 8019AAD8: rlwinm r27, r31, 12, 0, 19
    {
        ctx->gpr[27] = dolrecomp_rotl32(ctx->gpr[31], 12u) & 0xFFFFF000u;
    }

label_8019AADC:
    ctx->pc = 0x8019AADCu;
    // 8019AADC: lbz     r11, 11(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(11);
        ctx->gpr[11] = mem_read8(ctx, ea);
    }

label_8019AAE0:
    ctx->pc = 0x8019AAE0u;
    // 8019AAE0: lbz     r8, 17(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(17);
        ctx->gpr[8] = mem_read8(ctx, ea);
    }

label_8019AAE4:
    ctx->pc = 0x8019AAE4u;
    // 8019AAE4: rlwinm r4, r29, 16, 0, 15
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[29], 16u) & 0xFFFF0000u;
    }

label_8019AAE8:
    ctx->pc = 0x8019AAE8u;
    // 8019AAE8: rlwinm r7, r7, 12, 0, 19
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 12u) & 0xFFFFF000u;
    }

label_8019AAEC:
    ctx->pc = 0x8019AAECu;
    // 8019AAEC: rlwinm r10, r12, 16, 0, 15
    {
        ctx->gpr[10] = dolrecomp_rotl32(ctx->gpr[12], 16u) & 0xFFFF0000u;
    }

label_8019AAF0:
    ctx->pc = 0x8019AAF0u;
    // 8019AAF0: rlwimi r27, r26, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[26], 0u);
        ctx->gpr[27] = (ctx->gpr[27] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_8019AAF4:
    ctx->pc = 0x8019AAF4u;
    // 8019AAF4: rlwinm r12, r3, 16, 0, 15
    {
        ctx->gpr[12] = dolrecomp_rotl32(ctx->gpr[3], 16u) & 0xFFFF0000u;
    }

label_8019AAF8:
    ctx->pc = 0x8019AAF8u;
    // 8019AAF8: rlwimi r7, r23, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[23], 0u);
        ctx->gpr[7] = (ctx->gpr[7] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_8019AAFC:
    ctx->pc = 0x8019AAFCu;
    // 8019AAFC: rlwimi r4, r28, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[28], 0u);
        ctx->gpr[4] = (ctx->gpr[4] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8019AB00:
    ctx->pc = 0x8019AB00u;
    // 8019AB00: rlwinm r3, r30, 20, 0, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[30], 20u) & 0xFFF00000u;
    }

label_8019AB04:
    ctx->pc = 0x8019AB04u;
    // 8019AB04: rlwimi r25, r24, 0, 20, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[24], 0u);
        ctx->gpr[25] = (ctx->gpr[25] & ~0x00000FFFu) | (rot & 0x00000FFFu);
    }

label_8019AB08:
    ctx->pc = 0x8019AB08u;
    // 8019AB08: rlwinm r9, r9, 16, 0, 15
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 16u) & 0xFFFF0000u;
    }

label_8019AB0C:
    ctx->pc = 0x8019AB0Cu;
    // 8019AB0C: rlwimi r10, r27, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[27], 0u);
        ctx->gpr[10] = (ctx->gpr[10] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8019AB10:
    ctx->pc = 0x8019AB10u;
    // 8019AB10: rlwimi r3, r4, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[4], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_8019AB14:
    ctx->pc = 0x8019AB14u;
    // 8019AB14: rlwimi r12, r7, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[7], 0u);
        ctx->gpr[12] = (ctx->gpr[12] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8019AB18:
    ctx->pc = 0x8019AB18u;
    // 8019AB18: rlwinm r7, r3, 0, 8, 31
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_8019AB1C:
    ctx->pc = 0x8019AB1Cu;
    // 8019AB1C: rlwinm r3, r11, 20, 0, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[11], 20u) & 0xFFF00000u;
    }

label_8019AB20:
    ctx->pc = 0x8019AB20u;
    // 8019AB20: rlwimi r3, r10, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[10], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_8019AB24:
    ctx->pc = 0x8019AB24u;
    // 8019AB24: rlwinm r4, r3, 0, 8, 31
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_8019AB28:
    ctx->pc = 0x8019AB28u;
    // 8019AB28: rlwinm r3, r8, 20, 0, 11
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[8], 20u) & 0xFFF00000u;
    }

label_8019AB2C:
    ctx->pc = 0x8019AB2Cu;
    // 8019AB2C: rlwimi r9, r25, 0, 16, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[25], 0u);
        ctx->gpr[9] = (ctx->gpr[9] & ~0x0000FFFFu) | (rot & 0x0000FFFFu);
    }

label_8019AB30:
    ctx->pc = 0x8019AB30u;
    // 8019AB30: rlwimi r3, r9, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[9], 0u);
        ctx->gpr[3] = (ctx->gpr[3] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_8019AB34:
    ctx->pc = 0x8019AB34u;
    // 8019AB34: rlwinm r0, r0, 20, 0, 11
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 20u) & 0xFFF00000u;
    }

label_8019AB38:
    ctx->pc = 0x8019AB38u;
    // 8019AB38: rlwimi r0, r12, 0, 12, 31
    {
        u32 rot = dolrecomp_rotl32(ctx->gpr[12], 0u);
        ctx->gpr[0] = (ctx->gpr[0] & ~0x000FFFFFu) | (rot & 0x000FFFFFu);
    }

label_8019AB3C:
    ctx->pc = 0x8019AB3Cu;
    // 8019AB3C: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_8019AB40:
    ctx->pc = 0x8019AB40u;
    // 8019AB40: rlwinm r0, r0, 0, 8, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00FFFFFFu;
    }

label_8019AB44:
    ctx->pc = 0x8019AB44u;
    // 8019AB44: oris    r8, r7, 0x0100
    ctx->gpr[8] = ctx->gpr[7] | (0x0100u << 16);

label_8019AB48:
    ctx->pc = 0x8019AB48u;
    // 8019AB48: oris    r7, r4, 0x0200
    ctx->gpr[7] = ctx->gpr[4] | (0x0200u << 16);

label_8019AB4C:
    ctx->pc = 0x8019AB4Cu;
    // 8019AB4C: oris    r9, r3, 0x0300
    ctx->gpr[9] = ctx->gpr[3] | (0x0300u << 16);

label_8019AB50:
    ctx->pc = 0x8019AB50u;
    // 8019AB50: oris    r10, r0, 0x0400
    ctx->gpr[10] = ctx->gpr[0] | (0x0400u << 16);

label_8019AB54:
    ctx->pc = 0x8019AB54u;
    // 8019AB54: b       0x8019AB78
    {
            goto label_8019AB78;
    }

label_8019AB58:
    ctx->pc = 0x8019AB58u;
    ctx->downcount -= 8;
    // 8019AB58: lis     r8, 358
    ctx->gpr[8] = ((u32)(s32)(358) << 16);

label_8019AB5C:
    ctx->pc = 0x8019AB5Cu;
    // 8019AB5C: lis     r7, 614
    ctx->gpr[7] = ((u32)(s32)(614) << 16);

label_8019AB60:
    ctx->pc = 0x8019AB60u;
    // 8019AB60: lis     r4, 870
    ctx->gpr[4] = ((u32)(s32)(870) << 16);

label_8019AB64:
    ctx->pc = 0x8019AB64u;
    // 8019AB64: lis     r3, 1126
    ctx->gpr[3] = ((u32)(s32)(1126) << 16);

label_8019AB68:
    ctx->pc = 0x8019AB68u;
    // 8019AB68: addi    r8, r8, 26214
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(26214);

label_8019AB6C:
    ctx->pc = 0x8019AB6Cu;
    // 8019AB6C: addi    r7, r7, 26214
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(26214);

label_8019AB70:
    ctx->pc = 0x8019AB70u;
    // 8019AB70: addi    r9, r4, 26214
    ctx->gpr[9] = ctx->gpr[4] + (u32)(s32)(26214);

label_8019AB74:
    ctx->pc = 0x8019AB74u;
    // 8019AB74: addi    r10, r3, 26214
    ctx->gpr[10] = ctx->gpr[3] + (u32)(s32)(26214);

label_8019AB78:
    ctx->pc = 0x8019AB78u;
    ctx->downcount -= 12;
    // 8019AB78: li      r4, 97
    ctx->gpr[4] = (u32)(s32)(97);

label_8019AB7C:
    ctx->pc = 0x8019AB7Cu;
    // 8019AB7C: lis     r3, -13311
    ctx->gpr[3] = ((u32)(s32)(-13311) << 16);

label_8019AB80:
    ctx->pc = 0x8019AB80u;
    // 8019AB80: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019AB84:
    ctx->pc = 0x8019AB84u;
    // 8019AB84: rlwinm. r0, r5, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AB88:
    ctx->pc = 0x8019AB88u;
    // 8019AB88: stw     r8, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8019AB8C:
    ctx->pc = 0x8019AB8Cu;
    // 8019AB8C: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019AB90:
    ctx->pc = 0x8019AB90u;
    // 8019AB90: stw     r7, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8019AB94:
    ctx->pc = 0x8019AB94u;
    // 8019AB94: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019AB98:
    ctx->pc = 0x8019AB98u;
    // 8019AB98: stw     r9, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8019AB9C:
    ctx->pc = 0x8019AB9Cu;
    // 8019AB9C: stb     r4, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[4]);
    }

label_8019ABA0:
    ctx->pc = 0x8019ABA0u;
    // 8019ABA0: stw     r10, -32768(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8019ABA4:
    ctx->pc = 0x8019ABA4u;
    // 8019ABA4: bc    12, 2, 0x8019AC0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AC0C;
        }
    }

label_8019ABA8:
    ctx->pc = 0x8019ABA8u;
    ctx->downcount -= 25;
    // 8019ABA8: lbz     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019ABAC:
    ctx->pc = 0x8019ABACu;
    // 8019ABAC: lbz     r3, 1(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8019ABB0:
    ctx->pc = 0x8019ABB0u;
    // 8019ABB0: oris    r5, r0, 0x5300
    ctx->gpr[5] = ctx->gpr[0] | (0x5300u << 16);

label_8019ABB4:
    ctx->pc = 0x8019ABB4u;
    // 8019ABB4: lbz     r0, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019ABB8:
    ctx->pc = 0x8019ABB8u;
    // 8019ABB8: lbz     r4, 2(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(2);
        ctx->gpr[4] = mem_read8(ctx, ea);
    }

label_8019ABBC:
    ctx->pc = 0x8019ABBCu;
    // 8019ABBC: rlwinm r7, r5, 0, 26, 19
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0xFFFFF03Fu;
    }

label_8019ABC0:
    ctx->pc = 0x8019ABC0u;
    // 8019ABC0: rlwinm r5, r3, 6, 0, 25
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[3], 6u) & 0xFFFFFFC0u;
    }

label_8019ABC4:
    ctx->pc = 0x8019ABC4u;
    // 8019ABC4: lbz     r3, 5(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(5);
        ctx->gpr[3] = mem_read8(ctx, ea);
    }

label_8019ABC8:
    ctx->pc = 0x8019ABC8u;
    // 8019ABC8: or   r7, r7, r5
    {
        ctx->gpr[7] = ctx->gpr[7] | ctx->gpr[5];
    }

label_8019ABCC:
    ctx->pc = 0x8019ABCCu;
    // 8019ABCC: oris    r8, r0, 0x5400
    ctx->gpr[8] = ctx->gpr[0] | (0x5400u << 16);

label_8019ABD0:
    ctx->pc = 0x8019ABD0u;
    // 8019ABD0: lbz     r5, 3(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(3);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8019ABD4:
    ctx->pc = 0x8019ABD4u;
    // 8019ABD4: lbz     r0, 6(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(6);
        ctx->gpr[0] = mem_read8(ctx, ea);
    }

label_8019ABD8:
    ctx->pc = 0x8019ABD8u;
    // 8019ABD8: rlwinm r6, r7, 0, 20, 13
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFC0FFFu;
    }

label_8019ABDC:
    ctx->pc = 0x8019ABDCu;
    // 8019ABDC: rlwinm r4, r4, 12, 0, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 12u) & 0xFFFFF000u;
    }

label_8019ABE0:
    ctx->pc = 0x8019ABE0u;
    // 8019ABE0: or   r6, r6, r4
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[4];
    }

label_8019ABE4:
    ctx->pc = 0x8019ABE4u;
    // 8019ABE4: rlwinm r4, r8, 0, 26, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[8], 0u) & 0xFFFFF03Fu;
    }

label_8019ABE8:
    ctx->pc = 0x8019ABE8u;
    // 8019ABE8: rlwinm r3, r3, 6, 0, 25
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 6u) & 0xFFFFFFC0u;
    }

label_8019ABEC:
    ctx->pc = 0x8019ABECu;
    // 8019ABEC: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8019ABF0:
    ctx->pc = 0x8019ABF0u;
    // 8019ABF0: rlwinm r6, r6, 0, 14, 7
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFF03FFFFu;
    }

label_8019ABF4:
    ctx->pc = 0x8019ABF4u;
    // 8019ABF4: rlwinm r4, r5, 18, 0, 13
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[5], 18u) & 0xFFFC0000u;
    }

label_8019ABF8:
    ctx->pc = 0x8019ABF8u;
    // 8019ABF8: rlwinm r3, r3, 0, 20, 13
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFC0FFFu;
    }

label_8019ABFC:
    ctx->pc = 0x8019ABFCu;
    // 8019ABFC: rlwinm r0, r0, 12, 0, 19
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 12u) & 0xFFFFF000u;
    }

label_8019AC00:
    ctx->pc = 0x8019AC00u;
    // 8019AC00: or   r6, r6, r4
    {
        ctx->gpr[6] = ctx->gpr[6] | ctx->gpr[4];
    }

label_8019AC04:
    ctx->pc = 0x8019AC04u;
    // 8019AC04: or   r7, r3, r0
    {
        ctx->gpr[7] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019AC08:
    ctx->pc = 0x8019AC08u;
    // 8019AC08: b       0x8019AC1C
    {
            goto label_8019AC1C;
    }

label_8019AC0C:
    ctx->pc = 0x8019AC0Cu;
    ctx->downcount -= 4;
    // 8019AC0C: lis     r4, 21337
    ctx->gpr[4] = ((u32)(s32)(21337) << 16);

label_8019AC10:
    ctx->pc = 0x8019AC10u;
    // 8019AC10: lis     r3, 21504
    ctx->gpr[3] = ((u32)(s32)(21504) << 16);

label_8019AC14:
    ctx->pc = 0x8019AC14u;
    // 8019AC14: addi    r6, r4, 20480
    ctx->gpr[6] = ctx->gpr[4] + (u32)(s32)(20480);

label_8019AC18:
    ctx->pc = 0x8019AC18u;
    // 8019AC18: addi    r7, r3, 21
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(21);

label_8019AC1C:
    ctx->pc = 0x8019AC1Cu;
    ctx->downcount -= 22;
    // 8019AC1C: li      r5, 97
    ctx->gpr[5] = (u32)(s32)(97);

label_8019AC20:
    ctx->pc = 0x8019AC20u;
    // 8019AC20: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AC24:
    ctx->pc = 0x8019AC24u;
    // 8019AC24: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_8019AC28:
    ctx->pc = 0x8019AC28u;
    // 8019AC28: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8019AC2C:
    ctx->pc = 0x8019AC2Cu;
    // 8019AC2C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019AC30:
    ctx->pc = 0x8019AC30u;
    // 8019AC30: stw     r6, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8019AC34:
    ctx->pc = 0x8019AC34u;
    // 8019AC34: stb     r5, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[5]);
    }

label_8019AC38:
    ctx->pc = 0x8019AC38u;
    // 8019AC38: stw     r7, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8019AC3C:
    ctx->pc = 0x8019AC3Cu;
    // 8019AC3C: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AC40:
    ctx->pc = 0x8019AC40u;
    // 8019AC40: lmw     r23, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 23; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8019AC44:
    ctx->pc = 0x8019AC44u;
    // 8019AC44: addi    r1, r1, 80
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(80);

label_8019AC48:
    ctx->pc = 0x8019AC48u;
    // 8019AC48: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019AC4C:
    ctx->pc = 0x8019AC4Cu;
    ctx->downcount -= 7;
    // 8019AC4C: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AC50:
    ctx->pc = 0x8019AC50u;
    // 8019AC50: rlwinm r0, r3, 7, 0, 24
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 7u) & 0xFFFFFF80u;
    }

label_8019AC54:
    ctx->pc = 0x8019AC54u;
    // 8019AC54: lwzu     r3, 492(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
        ctx->gpr[4] = ea;
    }

label_8019AC58:
    ctx->pc = 0x8019AC58u;
    // 8019AC58: rlwinm r3, r3, 0, 25, 22
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFFE7Fu;
    }

label_8019AC5C:
    ctx->pc = 0x8019AC5Cu;
    // 8019AC5C: or   r0, r3, r0
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[0];
    }

label_8019AC60:
    ctx->pc = 0x8019AC60u;
    // 8019AC60: stw     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019AC64:
    ctx->pc = 0x8019AC64u;
    // 8019AC64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019AC68:
    ctx->pc = 0x8019AC68u;
    ctx->downcount -= 2;
    // 8019AC68: rlwinm. r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AC6C:
    ctx->pc = 0x8019AC6Cu;
    // 8019AC6C: bc    12, 2, 0x8019ACA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019ACA8;
        }
    }

label_8019AC70:
    ctx->pc = 0x8019AC70u;
    ctx->downcount -= 14;
    // 8019AC70: lwz     r7, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019AC74:
    ctx->pc = 0x8019AC74u;
    // 8019AC74: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8019AC78:
    ctx->pc = 0x8019AC78u;
    // 8019AC78: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019AC7C:
    ctx->pc = 0x8019AC7Cu;
    // 8019AC7C: lwz     r6, 472(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(472);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019AC80:
    ctx->pc = 0x8019AC80u;
    // 8019AC80: rlwinm r6, r6, 0, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFEu;
    }

label_8019AC84:
    ctx->pc = 0x8019AC84u;
    // 8019AC84: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019AC88:
    ctx->pc = 0x8019AC88u;
    // 8019AC88: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_8019AC8C:
    ctx->pc = 0x8019AC8Cu;
    // 8019AC8C: rlwinm r6, r6, 0, 31, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFF1u;
    }

label_8019AC90:
    ctx->pc = 0x8019AC90u;
    // 8019AC90: ori     r6, r6, 0x000E
    ctx->gpr[6] = ctx->gpr[6] | 0x000Eu;

label_8019AC94:
    ctx->pc = 0x8019AC94u;
    // 8019AC94: stw     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8019AC98:
    ctx->pc = 0x8019AC98u;
    // 8019AC98: lwz     r6, 464(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019AC9C:
    ctx->pc = 0x8019AC9Cu;
    // 8019AC9C: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019ACA0:
    ctx->pc = 0x8019ACA0u;
    // 8019ACA0: rlwinm r0, r6, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFCu;
    }

label_8019ACA4:
    ctx->pc = 0x8019ACA4u;
    // 8019ACA4: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019ACA8:
    ctx->pc = 0x8019ACA8u;
    ctx->downcount -= 3;
    // 8019ACA8: rlwinm. r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019ACAC:
    ctx->pc = 0x8019ACACu;
    // 8019ACAC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019ACB0:
    ctx->pc = 0x8019ACB0u;
    // 8019ACB0: bc    4, 2, 0x8019ACC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019ACC8;
        }
    }

label_8019ACB4:
    ctx->pc = 0x8019ACB4u;
    ctx->downcount -= 5;
    // 8019ACB4: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019ACB8:
    ctx->pc = 0x8019ACB8u;
    // 8019ACB8: lwz     r5, 476(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(476);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019ACBC:
    ctx->pc = 0x8019ACBCu;
    // 8019ACBC: rlwinm r5, r5, 0, 29, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 0u) & 0x00000007u;
    }

label_8019ACC0:
    ctx->pc = 0x8019ACC0u;
    // 8019ACC0: cmplwi  r5, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019ACC4:
    ctx->pc = 0x8019ACC4u;
    // 8019ACC4: bc    4, 2, 0x8019ACF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019ACF4;
        }
    }

label_8019ACC8:
    ctx->pc = 0x8019ACC8u;
    ctx->downcount -= 5;
    // 8019ACC8: lwz     r5, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8019ACCC:
    ctx->pc = 0x8019ACCCu;
    // 8019ACCC: lwz     r7, 476(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(476);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019ACD0:
    ctx->pc = 0x8019ACD0u;
    // 8019ACD0: rlwinm r5, r7, 26, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 26u) & 0x00000001u;
    }

label_8019ACD4:
    ctx->pc = 0x8019ACD4u;
    // 8019ACD4: cmplwi  r5, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019ACD8:
    ctx->pc = 0x8019ACD8u;
    // 8019ACD8: bc    4, 2, 0x8019ACF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019ACF4;
        }
    }

label_8019ACDC:
    ctx->pc = 0x8019ACDCu;
    ctx->downcount -= 6;
    // 8019ACDC: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8019ACE0:
    ctx->pc = 0x8019ACE0u;
    // 8019ACE0: lis     r6, -13311
    ctx->gpr[6] = ((u32)(s32)(-13311) << 16);

label_8019ACE4:
    ctx->pc = 0x8019ACE4u;
    // 8019ACE4: stb     r0, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019ACE8:
    ctx->pc = 0x8019ACE8u;
    // 8019ACE8: rlwinm r5, r7, 0, 26, 24
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFBFu;
    }

label_8019ACEC:
    ctx->pc = 0x8019ACECu;
    // 8019ACEC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8019ACF0:
    ctx->pc = 0x8019ACF0u;
    // 8019ACF0: stw     r5, -32768(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8019ACF4:
    ctx->pc = 0x8019ACF4u;
    ctx->downcount -= 39;
    // 8019ACF4: li      r9, 97
    ctx->gpr[9] = (u32)(s32)(97);

label_8019ACF8:
    ctx->pc = 0x8019ACF8u;
    // 8019ACF8: lwz     r7, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019ACFC:
    ctx->pc = 0x8019ACFCu;
    // 8019ACFC: lis     r8, -13311
    ctx->gpr[8] = ((u32)(s32)(-13311) << 16);

label_8019AD00:
    ctx->pc = 0x8019AD00u;
    // 8019AD00: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AD04:
    ctx->pc = 0x8019AD04u;
    // 8019AD04: rlwinm r3, r3, 27, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 27u) & 0x00FFFFFFu;
    }

label_8019AD08:
    ctx->pc = 0x8019AD08u;
    // 8019AD08: oris    r10, r3, 0x4B00
    ctx->gpr[10] = ctx->gpr[3] | (0x4B00u << 16);

label_8019AD0C:
    ctx->pc = 0x8019AD0Cu;
    // 8019AD0C: lwz     r6, 480(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(480);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019AD10:
    ctx->pc = 0x8019AD10u;
    // 8019AD10: rlwinm. r5, r4, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AD14:
    ctx->pc = 0x8019AD14u;
    // 8019AD14: rlwinm r3, r4, 11, 13, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 11u) & 0x0007F800u;
    }

label_8019AD18:
    ctx->pc = 0x8019AD18u;
    // 8019AD18: stw     r6, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8019AD1C:
    ctx->pc = 0x8019AD1Cu;
    // 8019AD1C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AD20:
    ctx->pc = 0x8019AD20u;
    // 8019AD20: lwz     r4, 484(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(484);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AD24:
    ctx->pc = 0x8019AD24u;
    // 8019AD24: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019AD28:
    ctx->pc = 0x8019AD28u;
    // 8019AD28: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AD2C:
    ctx->pc = 0x8019AD2Cu;
    // 8019AD2C: lwz     r4, 488(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(488);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AD30:
    ctx->pc = 0x8019AD30u;
    // 8019AD30: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019AD34:
    ctx->pc = 0x8019AD34u;
    // 8019AD34: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AD38:
    ctx->pc = 0x8019AD38u;
    // 8019AD38: stw     r10, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8019AD3C:
    ctx->pc = 0x8019AD3Cu;
    // 8019AD3C: lwz     r4, 492(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(492);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AD40:
    ctx->pc = 0x8019AD40u;
    // 8019AD40: rlwinm r4, r4, 0, 21, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF7FFu;
    }

label_8019AD44:
    ctx->pc = 0x8019AD44u;
    // 8019AD44: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8019AD48:
    ctx->pc = 0x8019AD48u;
    // 8019AD48: stw     r3, 492(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(492);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AD4C:
    ctx->pc = 0x8019AD4Cu;
    // 8019AD4C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AD50:
    ctx->pc = 0x8019AD50u;
    // 8019AD50: addi    r4, r3, 492
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(492);

label_8019AD54:
    ctx->pc = 0x8019AD54u;
    // 8019AD54: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AD58:
    ctx->pc = 0x8019AD58u;
    // 8019AD58: rlwinm r3, r3, 0, 18, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFBFFFu;
    }

label_8019AD5C:
    ctx->pc = 0x8019AD5Cu;
    // 8019AD5C: ori     r3, r3, 0x4000
    ctx->gpr[3] = ctx->gpr[3] | 0x4000u;

label_8019AD60:
    ctx->pc = 0x8019AD60u;
    // 8019AD60: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AD64:
    ctx->pc = 0x8019AD64u;
    // 8019AD64: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AD68:
    ctx->pc = 0x8019AD68u;
    // 8019AD68: addi    r4, r3, 492
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(492);

label_8019AD6C:
    ctx->pc = 0x8019AD6Cu;
    // 8019AD6C: lwz     r3, 492(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AD70:
    ctx->pc = 0x8019AD70u;
    // 8019AD70: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_8019AD74:
    ctx->pc = 0x8019AD74u;
    // 8019AD74: oris    r3, r3, 0x5200
    ctx->gpr[3] = ctx->gpr[3] | (0x5200u << 16);

label_8019AD78:
    ctx->pc = 0x8019AD78u;
    // 8019AD78: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AD7C:
    ctx->pc = 0x8019AD7Cu;
    // 8019AD7C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AD80:
    ctx->pc = 0x8019AD80u;
    // 8019AD80: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AD84:
    ctx->pc = 0x8019AD84u;
    // 8019AD84: lwz     r3, 492(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(492);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AD88:
    ctx->pc = 0x8019AD88u;
    // 8019AD88: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AD8C:
    ctx->pc = 0x8019AD8Cu;
    // 8019AD8C: bc    12, 2, 0x8019ADA8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019ADA8;
        }
    }

label_8019AD90:
    ctx->pc = 0x8019AD90u;
    ctx->downcount -= 6;
    // 8019AD90: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AD94:
    ctx->pc = 0x8019AD94u;
    // 8019AD94: lwz     r3, 472(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(472);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AD98:
    ctx->pc = 0x8019AD98u;
    // 8019AD98: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AD9C:
    ctx->pc = 0x8019AD9Cu;
    // 8019AD9C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019ADA0:
    ctx->pc = 0x8019ADA0u;
    // 8019ADA0: lwz     r3, 464(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019ADA4:
    ctx->pc = 0x8019ADA4u;
    // 8019ADA4: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019ADA8:
    ctx->pc = 0x8019ADA8u;
    ctx->downcount -= 2;
    // 8019ADA8: rlwinm. r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019ADAC:
    ctx->pc = 0x8019ADACu;
    // 8019ADAC: bc    12, 2, 0x8019ADC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019ADC8;
        }
    }

label_8019ADB0:
    ctx->pc = 0x8019ADB0u;
    ctx->downcount -= 6;
    // 8019ADB0: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8019ADB4:
    ctx->pc = 0x8019ADB4u;
    // 8019ADB4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019ADB8:
    ctx->pc = 0x8019ADB8u;
    // 8019ADB8: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_8019ADBC:
    ctx->pc = 0x8019ADBCu;
    // 8019ADBC: stb     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019ADC0:
    ctx->pc = 0x8019ADC0u;
    // 8019ADC0: lwz     r0, 476(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(476);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019ADC4:
    ctx->pc = 0x8019ADC4u;
    // 8019ADC4: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019ADC8:
    ctx->pc = 0x8019ADC8u;
    ctx->downcount -= 4;
    // 8019ADC8: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019ADCC:
    ctx->pc = 0x8019ADCCu;
    // 8019ADCC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019ADD0:
    ctx->pc = 0x8019ADD0u;
    // 8019ADD0: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019ADD4:
    ctx->pc = 0x8019ADD4u;
    // 8019ADD4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019ADD8:
    ctx->pc = 0x8019ADD8u;
    ctx->downcount -= 2;
    // 8019ADD8: rlwinm. r0, r4, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019ADDC:
    ctx->pc = 0x8019ADDCu;
    // 8019ADDC: bc    12, 2, 0x8019AE18
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AE18;
        }
    }

label_8019ADE0:
    ctx->pc = 0x8019ADE0u;
    ctx->downcount -= 14;
    // 8019ADE0: lwz     r7, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019ADE4:
    ctx->pc = 0x8019ADE4u;
    // 8019ADE4: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8019ADE8:
    ctx->pc = 0x8019ADE8u;
    // 8019ADE8: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019ADEC:
    ctx->pc = 0x8019ADECu;
    // 8019ADEC: lwz     r6, 472(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(472);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019ADF0:
    ctx->pc = 0x8019ADF0u;
    // 8019ADF0: rlwinm r6, r6, 0, 0, 30
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFEu;
    }

label_8019ADF4:
    ctx->pc = 0x8019ADF4u;
    // 8019ADF4: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019ADF8:
    ctx->pc = 0x8019ADF8u;
    // 8019ADF8: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_8019ADFC:
    ctx->pc = 0x8019ADFCu;
    // 8019ADFC: rlwinm r6, r6, 0, 31, 27
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFF1u;
    }

label_8019AE00:
    ctx->pc = 0x8019AE00u;
    // 8019AE00: ori     r6, r6, 0x000E
    ctx->gpr[6] = ctx->gpr[6] | 0x000Eu;

label_8019AE04:
    ctx->pc = 0x8019AE04u;
    // 8019AE04: stw     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8019AE08:
    ctx->pc = 0x8019AE08u;
    // 8019AE08: lwz     r6, 464(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(464);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019AE0C:
    ctx->pc = 0x8019AE0Cu;
    // 8019AE0C: stb     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019AE10:
    ctx->pc = 0x8019AE10u;
    // 8019AE10: rlwinm r0, r6, 0, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[6], 0u) & 0xFFFFFFFCu;
    }

label_8019AE14:
    ctx->pc = 0x8019AE14u;
    // 8019AE14: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019AE18:
    ctx->pc = 0x8019AE18u;
    ctx->downcount -= 6;
    // 8019AE18: lwz     r6, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019AE1C:
    ctx->pc = 0x8019AE1Cu;
    // 8019AE1C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019AE20:
    ctx->pc = 0x8019AE20u;
    // 8019AE20: lbz     r5, 512(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(512);
        ctx->gpr[5] = mem_read8(ctx, ea);
    }

label_8019AE24:
    ctx->pc = 0x8019AE24u;
    // 8019AE24: lwz     r7, 476(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(476);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019AE28:
    ctx->pc = 0x8019AE28u;
    // 8019AE28: cmplwi  r5, 0x0000
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0000u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019AE2C:
    ctx->pc = 0x8019AE2Cu;
    // 8019AE2C: bc    12, 2, 0x8019AE48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AE48;
        }
    }

label_8019AE30:
    ctx->pc = 0x8019AE30u;
    ctx->downcount -= 3;
    // 8019AE30: rlwinm r5, r7, 0, 29, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000007u;
    }

label_8019AE34:
    ctx->pc = 0x8019AE34u;
    // 8019AE34: cmplwi  r5, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019AE38:
    ctx->pc = 0x8019AE38u;
    // 8019AE38: bc    12, 2, 0x8019AE48
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AE48;
        }
    }

label_8019AE3C:
    ctx->pc = 0x8019AE3Cu;
    ctx->downcount -= 3;
    // 8019AE3C: rlwinm r0, r7, 0, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFF8u;
    }

label_8019AE40:
    ctx->pc = 0x8019AE40u;
    // 8019AE40: ori     r7, r0, 0x0003
    ctx->gpr[7] = ctx->gpr[0] | 0x0003u;

label_8019AE44:
    ctx->pc = 0x8019AE44u;
    // 8019AE44: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8019AE48:
    ctx->pc = 0x8019AE48u;
    ctx->downcount -= 2;
    // 8019AE48: rlwinm. r5, r4, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AE4C:
    ctx->pc = 0x8019AE4Cu;
    // 8019AE4C: bc    4, 2, 0x8019AE5C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019AE5C;
        }
    }

label_8019AE50:
    ctx->pc = 0x8019AE50u;
    ctx->downcount -= 3;
    // 8019AE50: rlwinm r5, r7, 0, 29, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0x00000007u;
    }

label_8019AE54:
    ctx->pc = 0x8019AE54u;
    // 8019AE54: cmplwi  r5, 0x0003
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0003u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019AE58:
    ctx->pc = 0x8019AE58u;
    // 8019AE58: bc    4, 2, 0x8019AE70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019AE70;
        }
    }

label_8019AE5C:
    ctx->pc = 0x8019AE5Cu;
    ctx->downcount -= 3;
    // 8019AE5C: rlwinm r5, r7, 26, 31, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[7], 26u) & 0x00000001u;
    }

label_8019AE60:
    ctx->pc = 0x8019AE60u;
    // 8019AE60: cmplwi  r5, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[5]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019AE64:
    ctx->pc = 0x8019AE64u;
    // 8019AE64: bc    4, 2, 0x8019AE70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019AE70;
        }
    }

label_8019AE68:
    ctx->pc = 0x8019AE68u;
    ctx->downcount -= 2;
    // 8019AE68: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_8019AE6C:
    ctx->pc = 0x8019AE6Cu;
    // 8019AE6C: rlwinm r7, r7, 0, 26, 24
    {
        ctx->gpr[7] = dolrecomp_rotl32(ctx->gpr[7], 0u) & 0xFFFFFFBFu;
    }

label_8019AE70:
    ctx->pc = 0x8019AE70u;
    ctx->downcount -= 2;
    // 8019AE70: rlwinm. r5, r0, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AE74:
    ctx->pc = 0x8019AE74u;
    // 8019AE74: bc    12, 2, 0x8019AE88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AE88;
        }
    }

label_8019AE78:
    ctx->pc = 0x8019AE78u;
    ctx->downcount -= 4;
    // 8019AE78: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_8019AE7C:
    ctx->pc = 0x8019AE7Cu;
    // 8019AE7C: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019AE80:
    ctx->pc = 0x8019AE80u;
    // 8019AE80: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8019AE84:
    ctx->pc = 0x8019AE84u;
    // 8019AE84: stw     r7, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8019AE88:
    ctx->pc = 0x8019AE88u;
    ctx->downcount -= 38;
    // 8019AE88: li      r9, 97
    ctx->gpr[9] = (u32)(s32)(97);

label_8019AE8C:
    ctx->pc = 0x8019AE8Cu;
    // 8019AE8C: lwz     r7, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019AE90:
    ctx->pc = 0x8019AE90u;
    // 8019AE90: lis     r8, -13311
    ctx->gpr[8] = ((u32)(s32)(-13311) << 16);

label_8019AE94:
    ctx->pc = 0x8019AE94u;
    // 8019AE94: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AE98:
    ctx->pc = 0x8019AE98u;
    // 8019AE98: rlwinm r3, r3, 27, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 27u) & 0x00FFFFFFu;
    }

label_8019AE9C:
    ctx->pc = 0x8019AE9Cu;
    // 8019AE9C: oris    r10, r3, 0x4B00
    ctx->gpr[10] = ctx->gpr[3] | (0x4B00u << 16);

label_8019AEA0:
    ctx->pc = 0x8019AEA0u;
    // 8019AEA0: lwz     r6, 496(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(496);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8019AEA4:
    ctx->pc = 0x8019AEA4u;
    // 8019AEA4: rlwinm. r5, r4, 0, 24, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[5];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AEA8:
    ctx->pc = 0x8019AEA8u;
    // 8019AEA8: rlwinm r3, r4, 11, 13, 20
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[4], 11u) & 0x0007F800u;
    }

label_8019AEAC:
    ctx->pc = 0x8019AEACu;
    // 8019AEAC: stw     r6, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8019AEB0:
    ctx->pc = 0x8019AEB0u;
    // 8019AEB0: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AEB4:
    ctx->pc = 0x8019AEB4u;
    // 8019AEB4: lwz     r4, 500(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(500);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AEB8:
    ctx->pc = 0x8019AEB8u;
    // 8019AEB8: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019AEBC:
    ctx->pc = 0x8019AEBCu;
    // 8019AEBC: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AEC0:
    ctx->pc = 0x8019AEC0u;
    // 8019AEC0: lwz     r4, 504(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(504);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AEC4:
    ctx->pc = 0x8019AEC4u;
    // 8019AEC4: stw     r4, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019AEC8:
    ctx->pc = 0x8019AEC8u;
    // 8019AEC8: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AECC:
    ctx->pc = 0x8019AECCu;
    // 8019AECC: stw     r10, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8019AED0:
    ctx->pc = 0x8019AED0u;
    // 8019AED0: lwz     r4, 508(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(508);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AED4:
    ctx->pc = 0x8019AED4u;
    // 8019AED4: rlwinm r4, r4, 0, 21, 19
    {
        ctx->gpr[4] = dolrecomp_rotl32(ctx->gpr[4], 0u) & 0xFFFFF7FFu;
    }

label_8019AED8:
    ctx->pc = 0x8019AED8u;
    // 8019AED8: or   r3, r4, r3
    {
        ctx->gpr[3] = ctx->gpr[4] | ctx->gpr[3];
    }

label_8019AEDC:
    ctx->pc = 0x8019AEDCu;
    // 8019AEDC: stw     r3, 508(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(508);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AEE0:
    ctx->pc = 0x8019AEE0u;
    // 8019AEE0: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AEE4:
    ctx->pc = 0x8019AEE4u;
    // 8019AEE4: addi    r4, r3, 508
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(508);

label_8019AEE8:
    ctx->pc = 0x8019AEE8u;
    // 8019AEE8: lwz     r3, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AEEC:
    ctx->pc = 0x8019AEECu;
    // 8019AEEC: rlwinm r3, r3, 0, 18, 16
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0xFFFFBFFFu;
    }

label_8019AEF0:
    ctx->pc = 0x8019AEF0u;
    // 8019AEF0: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AEF4:
    ctx->pc = 0x8019AEF4u;
    // 8019AEF4: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AEF8:
    ctx->pc = 0x8019AEF8u;
    // 8019AEF8: addi    r4, r3, 508
    ctx->gpr[4] = ctx->gpr[3] + (u32)(s32)(508);

label_8019AEFC:
    ctx->pc = 0x8019AEFCu;
    // 8019AEFC: lwz     r3, 508(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AF00:
    ctx->pc = 0x8019AF00u;
    // 8019AF00: rlwinm r3, r3, 0, 8, 31
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[3], 0u) & 0x00FFFFFFu;
    }

label_8019AF04:
    ctx->pc = 0x8019AF04u;
    // 8019AF04: oris    r3, r3, 0x5200
    ctx->gpr[3] = ctx->gpr[3] | (0x5200u << 16);

label_8019AF08:
    ctx->pc = 0x8019AF08u;
    // 8019AF08: stw     r3, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AF0C:
    ctx->pc = 0x8019AF0Cu;
    // 8019AF0C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AF10:
    ctx->pc = 0x8019AF10u;
    // 8019AF10: lwz     r4, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8019AF14:
    ctx->pc = 0x8019AF14u;
    // 8019AF14: lwz     r3, 508(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(508);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AF18:
    ctx->pc = 0x8019AF18u;
    // 8019AF18: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AF1C:
    ctx->pc = 0x8019AF1Cu;
    // 8019AF1C: bc    12, 2, 0x8019AF38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AF38;
        }
    }

label_8019AF20:
    ctx->pc = 0x8019AF20u;
    ctx->downcount -= 6;
    // 8019AF20: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AF24:
    ctx->pc = 0x8019AF24u;
    // 8019AF24: lwz     r3, 472(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(472);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AF28:
    ctx->pc = 0x8019AF28u;
    // 8019AF28: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AF2C:
    ctx->pc = 0x8019AF2Cu;
    // 8019AF2C: stb     r9, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[9]);
    }

label_8019AF30:
    ctx->pc = 0x8019AF30u;
    // 8019AF30: lwz     r3, 464(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(464);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AF34:
    ctx->pc = 0x8019AF34u;
    // 8019AF34: stw     r3, -32768(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8019AF38:
    ctx->pc = 0x8019AF38u;
    ctx->downcount -= 2;
    // 8019AF38: rlwinm. r0, r0, 0, 24, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x000000FFu;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_8019AF3C:
    ctx->pc = 0x8019AF3Cu;
    // 8019AF3C: bc    12, 2, 0x8019AF58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019AF58;
        }
    }

label_8019AF40:
    ctx->pc = 0x8019AF40u;
    ctx->downcount -= 6;
    // 8019AF40: li      r0, 97
    ctx->gpr[0] = (u32)(s32)(97);

label_8019AF44:
    ctx->pc = 0x8019AF44u;
    // 8019AF44: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AF48:
    ctx->pc = 0x8019AF48u;
    // 8019AF48: lis     r4, -13311
    ctx->gpr[4] = ((u32)(s32)(-13311) << 16);

label_8019AF4C:
    ctx->pc = 0x8019AF4Cu;
    // 8019AF4C: stb     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[0]);
    }

label_8019AF50:
    ctx->pc = 0x8019AF50u;
    // 8019AF50: lwz     r0, 476(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(476);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019AF54:
    ctx->pc = 0x8019AF54u;
    // 8019AF54: stw     r0, -32768(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019AF58:
    ctx->pc = 0x8019AF58u;
    ctx->downcount -= 4;
    // 8019AF58: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AF5C:
    ctx->pc = 0x8019AF5Cu;
    // 8019AF5C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019AF60:
    ctx->pc = 0x8019AF60u;
    // 8019AF60: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AF64:
    ctx->pc = 0x8019AF64u;
    // 8019AF64: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019AF68:
    ctx->pc = 0x8019AF68u;
    ctx->downcount -= 14;
    // 8019AF68: li      r6, 97
    ctx->gpr[6] = (u32)(s32)(97);

label_8019AF6C:
    ctx->pc = 0x8019AF6Cu;
    // 8019AF6C: lwz     r3, -28696(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-28696);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AF70:
    ctx->pc = 0x8019AF70u;
    // 8019AF70: lis     r5, -13311
    ctx->gpr[5] = ((u32)(s32)(-13311) << 16);

label_8019AF74:
    ctx->pc = 0x8019AF74u;
    // 8019AF74: lis     r4, 21760
    ctx->gpr[4] = ((u32)(s32)(21760) << 16);

label_8019AF78:
    ctx->pc = 0x8019AF78u;
    // 8019AF78: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8019AF7C:
    ctx->pc = 0x8019AF7Cu;
    // 8019AF7C: addi    r0, r4, 1023
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(1023);

label_8019AF80:
    ctx->pc = 0x8019AF80u;
    // 8019AF80: stw     r0, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019AF84:
    ctx->pc = 0x8019AF84u;
    // 8019AF84: lis     r4, 22016
    ctx->gpr[4] = ((u32)(s32)(22016) << 16);

label_8019AF88:
    ctx->pc = 0x8019AF88u;
    // 8019AF88: addi    r4, r4, 1023
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1023);

label_8019AF8C:
    ctx->pc = 0x8019AF8Cu;
    // 8019AF8C: stb     r6, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write8(ctx, ea, (u8)ctx->gpr[6]);
    }

label_8019AF90:
    ctx->pc = 0x8019AF90u;
    // 8019AF90: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8019AF94:
    ctx->pc = 0x8019AF94u;
    // 8019AF94: stw     r4, -32768(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(-32768);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_8019AF98:
    ctx->pc = 0x8019AF98u;
    // 8019AF98: sth     r0, 2(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(2);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AF9C:
    ctx->pc = 0x8019AF9Cu;
    // 8019AF9C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019AFA0:
    ctx->pc = 0x8019AFA0u;
    ctx->downcount -= 13;
    // 8019AFA0: lwz     r7, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8019AFA4:
    ctx->pc = 0x8019AFA4u;
    // 8019AFA4: lhz     r0, 16(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8019AFA8:
    ctx->pc = 0x8019AFA8u;
    // 8019AFA8: sth     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AFAC:
    ctx->pc = 0x8019AFACu;
    // 8019AFAC: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AFB0:
    ctx->pc = 0x8019AFB0u;
    // 8019AFB0: lhz     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8019AFB4:
    ctx->pc = 0x8019AFB4u;
    // 8019AFB4: sth     r0, 0(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AFB8:
    ctx->pc = 0x8019AFB8u;
    // 8019AFB8: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AFBC:
    ctx->pc = 0x8019AFBCu;
    // 8019AFBC: lhz     r0, 18(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(18);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8019AFC0:
    ctx->pc = 0x8019AFC0u;
    // 8019AFC0: sth     r0, 0(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AFC4:
    ctx->pc = 0x8019AFC4u;
    // 8019AFC4: lwz     r3, -26136(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-26136);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8019AFC8:
    ctx->pc = 0x8019AFC8u;
    // 8019AFC8: lhz     r0, 22(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(22);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8019AFCC:
    ctx->pc = 0x8019AFCCu;
    // 8019AFCC: sth     r0, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_8019AFD0:
    ctx->pc = 0x8019AFD0u;
    // 8019AFD0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019AFD4:
    ctx->pc = 0x8019AFD4u;
    ctx->downcount -= 7;
    // 8019AFD4: stfs     f1, 16(r3)
    if (!ppc_fp_available(ctx, 0x8019AFD4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019AFD8:
    ctx->pc = 0x8019AFD8u;
    // 8019AFD8: stfs     f2, 20(r3)
    if (!ppc_fp_available(ctx, 0x8019AFD8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8019AFDC:
    ctx->pc = 0x8019AFDCu;
    // 8019AFDC: stfs     f3, 24(r3)
    if (!ppc_fp_available(ctx, 0x8019AFDCu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8019AFE0:
    ctx->pc = 0x8019AFE0u;
    // 8019AFE0: stfs     f4, 28(r3)
    if (!ppc_fp_available(ctx, 0x8019AFE0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8019AFE4:
    ctx->pc = 0x8019AFE4u;
    // 8019AFE4: stfs     f5, 32(r3)
    if (!ppc_fp_available(ctx, 0x8019AFE4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8019AFE8:
    ctx->pc = 0x8019AFE8u;
    // 8019AFE8: stfs     f6, 36(r3)
    if (!ppc_fp_available(ctx, 0x8019AFE8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[6]));
    }

label_8019AFEC:
    ctx->pc = 0x8019AFECu;
    // 8019AFEC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019AFF0:
    ctx->pc = 0x8019AFF0u;
    ctx->downcount -= 4;
    // 8019AFF0: stfs     f1, 16(r3)
    if (!ppc_fp_available(ctx, 0x8019AFF0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019AFF4:
    ctx->pc = 0x8019AFF4u;
    // 8019AFF4: stfs     f2, 20(r3)
    if (!ppc_fp_available(ctx, 0x8019AFF4u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8019AFF8:
    ctx->pc = 0x8019AFF8u;
    // 8019AFF8: stfs     f3, 24(r3)
    if (!ppc_fp_available(ctx, 0x8019AFF8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8019AFFC:
    ctx->pc = 0x8019AFFCu;
    // 8019AFFC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019B000:
    ctx->pc = 0x8019B000u;
    ctx->downcount -= 7;
    // 8019B000: lfs     f0, 16(r3)
    if (!ppc_fp_available(ctx, 0x8019B000u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B004:
    ctx->pc = 0x8019B004u;
    // 8019B004: stfs     f0, 0(r4)
    if (!ppc_fp_available(ctx, 0x8019B004u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B008:
    ctx->pc = 0x8019B008u;
    // 8019B008: lfs     f0, 20(r3)
    if (!ppc_fp_available(ctx, 0x8019B008u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B00C:
    ctx->pc = 0x8019B00Cu;
    // 8019B00C: stfs     f0, 0(r5)
    if (!ppc_fp_available(ctx, 0x8019B00Cu)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B010:
    ctx->pc = 0x8019B010u;
    // 8019B010: lfs     f0, 24(r3)
    if (!ppc_fp_available(ctx, 0x8019B010u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(24);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B014:
    ctx->pc = 0x8019B014u;
    // 8019B014: stfs     f0, 0(r6)
    if (!ppc_fp_available(ctx, 0x8019B014u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B018:
    ctx->pc = 0x8019B018u;
    // 8019B018: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019B01C:
    ctx->pc = 0x8019B01Cu;
    ctx->downcount -= 4;
    // 8019B01C: stfs     f1, 28(r3)
    if (!ppc_fp_available(ctx, 0x8019B01Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019B020:
    ctx->pc = 0x8019B020u;
    // 8019B020: stfs     f2, 32(r3)
    if (!ppc_fp_available(ctx, 0x8019B020u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8019B024:
    ctx->pc = 0x8019B024u;
    // 8019B024: stfs     f3, 36(r3)
    if (!ppc_fp_available(ctx, 0x8019B024u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8019B028:
    ctx->pc = 0x8019B028u;
    // 8019B028: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019B02C:
    ctx->pc = 0x8019B02Cu;
    ctx->downcount -= 7;
    // 8019B02C: lfs     f0, 28(r3)
    if (!ppc_fp_available(ctx, 0x8019B02Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B030:
    ctx->pc = 0x8019B030u;
    // 8019B030: stfs     f0, 0(r4)
    if (!ppc_fp_available(ctx, 0x8019B030u)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B034:
    ctx->pc = 0x8019B034u;
    // 8019B034: lfs     f0, 32(r3)
    if (!ppc_fp_available(ctx, 0x8019B034u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B038:
    ctx->pc = 0x8019B038u;
    // 8019B038: stfs     f0, 0(r5)
    if (!ppc_fp_available(ctx, 0x8019B038u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B03C:
    ctx->pc = 0x8019B03Cu;
    // 8019B03C: lfs     f0, 36(r3)
    if (!ppc_fp_available(ctx, 0x8019B03Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B040:
    ctx->pc = 0x8019B040u;
    // 8019B040: stfs     f0, 0(r6)
    if (!ppc_fp_available(ctx, 0x8019B040u)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B044:
    ctx->pc = 0x8019B044u;
    // 8019B044: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019B048:
    ctx->pc = 0x8019B048u;
    ctx->downcount -= 11;
    // 8019B048: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8019B04C:
    ctx->pc = 0x8019B04Cu;
    // 8019B04C: stw     r0, 4(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8019B050:
    ctx->pc = 0x8019B050u;
    // 8019B050: stwu     r1, -32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-32);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8019B054:
    ctx->pc = 0x8019B054u;
    // 8019B054: stw     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8019B058:
    ctx->pc = 0x8019B058u;
    // 8019B058: addi    r31, r4, 0
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(0);

label_8019B05C:
    ctx->pc = 0x8019B05Cu;
    // 8019B05C: stw     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_8019B060:
    ctx->pc = 0x8019B060u;
    // 8019B060: addi    r30, r3, 0
    ctx->gpr[30] = ctx->gpr[3] + (u32)(s32)(0);

label_8019B064:
    ctx->pc = 0x8019B064u;
    // 8019B064: lfs     f0, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B064u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B068:
    ctx->pc = 0x8019B068u;
    // 8019B068: fcmpo   cr0, f1, f0
    if (!ppc_fp_available(ctx, 0x8019B068u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8019B06C:
    ctx->pc = 0x8019B06Cu;
    // 8019B06C: cror    2, 0, 2
    {
        u32 a = (ctx->cr >> (31u - 0u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8019B070:
    ctx->pc = 0x8019B070u;
    // 8019B070: bc    12, 2, 0x8019B080
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019B080;
        }
    }

label_8019B074:
    ctx->pc = 0x8019B074u;
    ctx->downcount -= 3;
    // 8019B074: lfs     f0, -22164(r13)
    if (!ppc_fp_available(ctx, 0x8019B074u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22164);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B078:
    ctx->pc = 0x8019B078u;
    // 8019B078: fcmpo   cr0, f1, f0
    if (!ppc_fp_available(ctx, 0x8019B078u)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8019B07C:
    ctx->pc = 0x8019B07Cu;
    // 8019B07C: bc    4, 1, 0x8019B084
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019B084;
        }
    }

label_8019B080:
    ctx->pc = 0x8019B080u;
    ctx->downcount -= 1;
    // 8019B080: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_8019B084:
    ctx->pc = 0x8019B084u;
    ctx->downcount -= 21;
    // 8019B084: lfs     f2, -22160(r13)
    if (!ppc_fp_available(ctx, 0x8019B084u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22160);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8019B088:
    ctx->pc = 0x8019B088u;
    // 8019B088: lfs     f0, -22156(r13)
    if (!ppc_fp_available(ctx, 0x8019B088u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22156);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B08C:
    ctx->pc = 0x8019B08Cu;
    // 8019B08C: fmuls   f1, f2, f1
    if (!ppc_fp_available(ctx, 0x8019B08Cu)) return;
    ppc_fmuls(ctx, 1, 2, 1);

label_8019B090:
    ctx->pc = 0x8019B090u;
    // 8019B090: fdivs   f1, f1, f0
    if (!ppc_fp_available(ctx, 0x8019B090u)) return;
    ppc_fdivs(ctx, 1, 1, 0);

label_8019B094:
    ctx->pc = 0x8019B094u;
    // 8019B094: bl      0x801657E4
    {
            ctx->lr = 0x8019B098u;
            ctx->pc = 0x801657E4u;
            return;
    }

label_8019B098:
    ctx->pc = 0x8019B098u;
    ctx->downcount -= 2;
    // 8019B098: cmplwi  r31, 0x0006
    {
        u32 val_a = (u32)(ctx->gpr[31]);
        u32 val_b = (u32)(0x0006u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019B09C:
    ctx->pc = 0x8019B09Cu;
    // 8019B09C: bc    12, 1, 0x8019B198
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019B198;
        }
    }

label_8019B0A0:
    ctx->pc = 0x8019B0A0u;
    ctx->downcount -= 7;
    // 8019B0A0: lis     r3, -32732
    ctx->gpr[3] = ((u32)(s32)(-32732) << 16);

label_8019B0A4:
    ctx->pc = 0x8019B0A4u;
    // 8019B0A4: addi    r3, r3, -1648
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-1648);

label_8019B0A8:
    ctx->pc = 0x8019B0A8u;
    // 8019B0A8: rlwinm r0, r31, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[31], 2u) & 0xFFFFFFFCu;
    }

label_8019B0AC:
    ctx->pc = 0x8019B0ACu;
    // 8019B0AC: lwzx    r0, r3, r0
    {
        u32 ea = ctx->gpr[3] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019B0B0:
    ctx->pc = 0x8019B0B0u;
    // 8019B0B0: mtctr    r0
    ctx->ctr = ctx->gpr[0];

label_8019B0B4:
    ctx->pc = 0x8019B0B4u;
    // 8019B0B4: bctr
    {
        u32 target = ctx->ctr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            return;
        }
    }

label_8019B0B8:
    ctx->pc = 0x8019B0B8u;
    ctx->downcount -= 5;
    // 8019B0B8: lfs     f0, -22152(r13)
    if (!ppc_fp_available(ctx, 0x8019B0B8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22152);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B0BC:
    ctx->pc = 0x8019B0BCu;
    // 8019B0BC: lfs     f2, -22148(r13)
    if (!ppc_fp_available(ctx, 0x8019B0BCu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22148);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8019B0C0:
    ctx->pc = 0x8019B0C0u;
    // 8019B0C0: fmuls   f5, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B0C0u)) return;
    ppc_fmuls(ctx, 5, 0, 1);

label_8019B0C4:
    ctx->pc = 0x8019B0C4u;
    // 8019B0C4: lfs     f3, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B0C4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8019B0C8:
    ctx->pc = 0x8019B0C8u;
    // 8019B0C8: b       0x8019B1A4
    {
            goto label_8019B1A4;
    }

label_8019B0CC:
    ctx->pc = 0x8019B0CCu;
    ctx->downcount -= 39;
    // 8019B0CC: lfs     f0, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B0CCu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B0D0:
    ctx->pc = 0x8019B0D0u;
    // 8019B0D0: fneg    f2, f1
    if (!ppc_fp_available(ctx, 0x8019B0D0u)) return;
    ctx->fpr[2] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_8019B0D4:
    ctx->pc = 0x8019B0D4u;
    // 8019B0D4: lfs     f3, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B0D4u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8019B0D8:
    ctx->pc = 0x8019B0D8u;
    // 8019B0D8: fsubs   f1, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B0D8u)) return;
    ppc_fsubs(ctx, 1, 0, 1);

label_8019B0DC:
    ctx->pc = 0x8019B0DCu;
    // 8019B0DC: fdivs   f5, f2, f1
    if (!ppc_fp_available(ctx, 0x8019B0DCu)) return;
    ppc_fdivs(ctx, 5, 2, 1);

label_8019B0E0:
    ctx->pc = 0x8019B0E0u;
    // 8019B0E0: fdivs   f2, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B0E0u)) return;
    ppc_fdivs(ctx, 2, 0, 1);

label_8019B0E4:
    ctx->pc = 0x8019B0E4u;
    // 8019B0E4: b       0x8019B1A4
    {
            goto label_8019B1A4;
    }

label_8019B0E8:
    ctx->pc = 0x8019B0E8u;
    ctx->downcount -= 39;
    // 8019B0E8: lfs     f0, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B0E8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B0EC:
    ctx->pc = 0x8019B0ECu;
    // 8019B0EC: fneg    f2, f1
    if (!ppc_fp_available(ctx, 0x8019B0ECu)) return;
    ctx->fpr[2] = dolrecomp_f64_from_bits(dolrecomp_f64_to_bits(ctx->fpr[1]) ^ 0x8000000000000000ull);

label_8019B0F0:
    ctx->pc = 0x8019B0F0u;
    // 8019B0F0: lfs     f5, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B0F0u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8019B0F4:
    ctx->pc = 0x8019B0F4u;
    // 8019B0F4: fsubs   f1, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B0F4u)) return;
    ppc_fsubs(ctx, 1, 0, 1);

label_8019B0F8:
    ctx->pc = 0x8019B0F8u;
    // 8019B0F8: fdivs   f2, f2, f1
    if (!ppc_fp_available(ctx, 0x8019B0F8u)) return;
    ppc_fdivs(ctx, 2, 2, 1);

label_8019B0FC:
    ctx->pc = 0x8019B0FCu;
    // 8019B0FC: fdivs   f3, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B0FCu)) return;
    ppc_fdivs(ctx, 3, 0, 1);

label_8019B100:
    ctx->pc = 0x8019B100u;
    // 8019B100: b       0x8019B1A4
    {
            goto label_8019B1A4;
    }

label_8019B104:
    ctx->pc = 0x8019B104u;
    ctx->downcount -= 59;
    // 8019B104: lfs     f0, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B104u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B108:
    ctx->pc = 0x8019B108u;
    // 8019B108: lfs     f3, -22140(r13)
    if (!ppc_fp_available(ctx, 0x8019B108u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22140);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8019B10C:
    ctx->pc = 0x8019B10Cu;
    // 8019B10C: fsubs   f4, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B10Cu)) return;
    ppc_fsubs(ctx, 4, 0, 1);

label_8019B110:
    ctx->pc = 0x8019B110u;
    // 8019B110: lfs     f0, -22136(r13)
    if (!ppc_fp_available(ctx, 0x8019B110u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22136);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B114:
    ctx->pc = 0x8019B114u;
    // 8019B114: fsubs   f2, f1, f3
    if (!ppc_fp_available(ctx, 0x8019B114u)) return;
    ppc_fsubs(ctx, 2, 1, 3);

label_8019B118:
    ctx->pc = 0x8019B118u;
    // 8019B118: fmuls   f4, f4, f4
    if (!ppc_fp_available(ctx, 0x8019B118u)) return;
    ppc_fmuls(ctx, 4, 4, 4);

label_8019B11C:
    ctx->pc = 0x8019B11Cu;
    // 8019B11C: fmuls   f1, f1, f2
    if (!ppc_fp_available(ctx, 0x8019B11Cu)) return;
    ppc_fmuls(ctx, 1, 1, 2);

label_8019B120:
    ctx->pc = 0x8019B120u;
    // 8019B120: fdivs   f2, f3, f4
    if (!ppc_fp_available(ctx, 0x8019B120u)) return;
    ppc_fdivs(ctx, 2, 3, 4);

label_8019B124:
    ctx->pc = 0x8019B124u;
    // 8019B124: fdivs   f5, f1, f4
    if (!ppc_fp_available(ctx, 0x8019B124u)) return;
    ppc_fdivs(ctx, 5, 1, 4);

label_8019B128:
    ctx->pc = 0x8019B128u;
    // 8019B128: fdivs   f3, f0, f4
    if (!ppc_fp_available(ctx, 0x8019B128u)) return;
    ppc_fdivs(ctx, 3, 0, 4);

label_8019B12C:
    ctx->pc = 0x8019B12Cu;
    // 8019B12C: b       0x8019B1A4
    {
            goto label_8019B1A4;
    }

label_8019B130:
    ctx->pc = 0x8019B130u;
    ctx->downcount -= 60;
    // 8019B130: lfs     f0, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B130u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B134:
    ctx->pc = 0x8019B134u;
    // 8019B134: lfs     f3, -22132(r13)
    if (!ppc_fp_available(ctx, 0x8019B134u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22132);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8019B138:
    ctx->pc = 0x8019B138u;
    // 8019B138: fsubs   f4, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B138u)) return;
    ppc_fsubs(ctx, 4, 0, 1);

label_8019B13C:
    ctx->pc = 0x8019B13Cu;
    // 8019B13C: lfs     f2, -22128(r13)
    if (!ppc_fp_available(ctx, 0x8019B13Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22128);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8019B140:
    ctx->pc = 0x8019B140u;
    // 8019B140: fadds   f0, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B140u)) return;
    ppc_fadds(ctx, 0, 0, 1);

label_8019B144:
    ctx->pc = 0x8019B144u;
    // 8019B144: fmuls   f1, f3, f1
    if (!ppc_fp_available(ctx, 0x8019B144u)) return;
    ppc_fmuls(ctx, 1, 3, 1);

label_8019B148:
    ctx->pc = 0x8019B148u;
    // 8019B148: fmuls   f4, f4, f4
    if (!ppc_fp_available(ctx, 0x8019B148u)) return;
    ppc_fmuls(ctx, 4, 4, 4);

label_8019B14C:
    ctx->pc = 0x8019B14Cu;
    // 8019B14C: fmuls   f0, f2, f0
    if (!ppc_fp_available(ctx, 0x8019B14Cu)) return;
    ppc_fmuls(ctx, 0, 2, 0);

label_8019B150:
    ctx->pc = 0x8019B150u;
    // 8019B150: fdivs   f5, f1, f4
    if (!ppc_fp_available(ctx, 0x8019B150u)) return;
    ppc_fdivs(ctx, 5, 1, 4);

label_8019B154:
    ctx->pc = 0x8019B154u;
    // 8019B154: fdivs   f2, f0, f4
    if (!ppc_fp_available(ctx, 0x8019B154u)) return;
    ppc_fdivs(ctx, 2, 0, 4);

label_8019B158:
    ctx->pc = 0x8019B158u;
    // 8019B158: fdivs   f3, f3, f4
    if (!ppc_fp_available(ctx, 0x8019B158u)) return;
    ppc_fdivs(ctx, 3, 3, 4);

label_8019B15C:
    ctx->pc = 0x8019B15Cu;
    // 8019B15C: b       0x8019B1A4
    {
            goto label_8019B1A4;
    }

label_8019B160:
    ctx->pc = 0x8019B160u;
    ctx->downcount -= 62;
    // 8019B160: lfs     f4, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B160u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8019B164:
    ctx->pc = 0x8019B164u;
    // 8019B164: lfs     f0, -22140(r13)
    if (!ppc_fp_available(ctx, 0x8019B164u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22140);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B168:
    ctx->pc = 0x8019B168u;
    // 8019B168: fsubs   f5, f4, f1
    if (!ppc_fp_available(ctx, 0x8019B168u)) return;
    ppc_fsubs(ctx, 5, 4, 1);

label_8019B16C:
    ctx->pc = 0x8019B16Cu;
    // 8019B16C: lfs     f2, -22128(r13)
    if (!ppc_fp_available(ctx, 0x8019B16Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22128);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8019B170:
    ctx->pc = 0x8019B170u;
    // 8019B170: fmuls   f3, f0, f1
    if (!ppc_fp_available(ctx, 0x8019B170u)) return;
    ppc_fmuls(ctx, 3, 0, 1);

label_8019B174:
    ctx->pc = 0x8019B174u;
    // 8019B174: lfs     f0, -22124(r13)
    if (!ppc_fp_available(ctx, 0x8019B174u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22124);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B178:
    ctx->pc = 0x8019B178u;
    // 8019B178: fmuls   f2, f2, f1
    if (!ppc_fp_available(ctx, 0x8019B178u)) return;
    ppc_fmuls(ctx, 2, 2, 1);

label_8019B17C:
    ctx->pc = 0x8019B17Cu;
    // 8019B17C: fmuls   f5, f5, f5
    if (!ppc_fp_available(ctx, 0x8019B17Cu)) return;
    ppc_fmuls(ctx, 5, 5, 5);

label_8019B180:
    ctx->pc = 0x8019B180u;
    // 8019B180: fmuls   f1, f3, f1
    if (!ppc_fp_available(ctx, 0x8019B180u)) return;
    ppc_fmuls(ctx, 1, 3, 1);

label_8019B184:
    ctx->pc = 0x8019B184u;
    // 8019B184: fdivs   f2, f2, f5
    if (!ppc_fp_available(ctx, 0x8019B184u)) return;
    ppc_fdivs(ctx, 2, 2, 5);

label_8019B188:
    ctx->pc = 0x8019B188u;
    // 8019B188: fdivs   f1, f1, f5
    if (!ppc_fp_available(ctx, 0x8019B188u)) return;
    ppc_fdivs(ctx, 1, 1, 5);

label_8019B18C:
    ctx->pc = 0x8019B18Cu;
    // 8019B18C: fdivs   f3, f0, f5
    if (!ppc_fp_available(ctx, 0x8019B18Cu)) return;
    ppc_fdivs(ctx, 3, 0, 5);

label_8019B190:
    ctx->pc = 0x8019B190u;
    // 8019B190: fsubs   f5, f4, f1
    if (!ppc_fp_available(ctx, 0x8019B190u)) return;
    ppc_fsubs(ctx, 5, 4, 1);

label_8019B194:
    ctx->pc = 0x8019B194u;
    // 8019B194: b       0x8019B1A4
    {
            goto label_8019B1A4;
    }

label_8019B198:
    ctx->pc = 0x8019B198u;
    ctx->downcount -= 3;
    // 8019B198: lfs     f2, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B198u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_8019B19C:
    ctx->pc = 0x8019B19Cu;
    // 8019B19C: lfs     f5, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B19Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8019B1A0:
    ctx->pc = 0x8019B1A0u;
    // 8019B1A0: fmr    f3, f2
    if (!ppc_fp_available(ctx, 0x8019B1A0u)) return;
    ctx->fpr[3] = ctx->fpr[2];

label_8019B1A4:
    ctx->pc = 0x8019B1A4u;
    ctx->downcount -= 10;
    // 8019B1A4: stfs     f5, 16(r30)
    if (!ppc_fp_available(ctx, 0x8019B1A4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8019B1A8:
    ctx->pc = 0x8019B1A8u;
    // 8019B1A8: stfs     f2, 20(r30)
    if (!ppc_fp_available(ctx, 0x8019B1A8u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8019B1AC:
    ctx->pc = 0x8019B1ACu;
    // 8019B1AC: stfs     f3, 24(r30)
    if (!ppc_fp_available(ctx, 0x8019B1ACu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8019B1B0:
    ctx->pc = 0x8019B1B0u;
    // 8019B1B0: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8019B1B4:
    ctx->pc = 0x8019B1B4u;
    // 8019B1B4: lwz     r31, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_8019B1B8:
    ctx->pc = 0x8019B1B8u;
    // 8019B1B8: lwz     r30, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_8019B1BC:
    ctx->pc = 0x8019B1BCu;
    // 8019B1BC: addi    r1, r1, 32
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(32);

label_8019B1C0:
    ctx->pc = 0x8019B1C0u;
    // 8019B1C0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8019B1C4:
    ctx->pc = 0x8019B1C4u;
    // 8019B1C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019B1C8:
    ctx->pc = 0x8019B1C8u;
    ctx->downcount -= 3;
    // 8019B1C8: lfs     f0, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B1C8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B1CC:
    ctx->pc = 0x8019B1CCu;
    // 8019B1CC: fcmpo   cr0, f1, f0
    if (!ppc_fp_available(ctx, 0x8019B1CCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[1], ctx->fpr[0], true);

label_8019B1D0:
    ctx->pc = 0x8019B1D0u;
    // 8019B1D0: bc    4, 0, 0x8019B1D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019B1D8;
        }
    }

label_8019B1D4:
    ctx->pc = 0x8019B1D4u;
    ctx->downcount -= 1;
    // 8019B1D4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8019B1D8:
    ctx->pc = 0x8019B1D8u;
    ctx->downcount -= 4;
    // 8019B1D8: lfs     f0, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B1D8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B1DC:
    ctx->pc = 0x8019B1DCu;
    // 8019B1DC: fcmpo   cr0, f2, f0
    if (!ppc_fp_available(ctx, 0x8019B1DCu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], true);

label_8019B1E0:
    ctx->pc = 0x8019B1E0u;
    // 8019B1E0: cror    2, 0, 2
    {
        u32 a = (ctx->cr >> (31u - 0u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8019B1E4:
    ctx->pc = 0x8019B1E4u;
    // 8019B1E4: bc    12, 2, 0x8019B1F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019B1F8;
        }
    }

label_8019B1E8:
    ctx->pc = 0x8019B1E8u;
    ctx->downcount -= 4;
    // 8019B1E8: lfs     f0, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B1E8u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B1EC:
    ctx->pc = 0x8019B1ECu;
    // 8019B1EC: fcmpo   cr0, f2, f0
    if (!ppc_fp_available(ctx, 0x8019B1ECu)) return;
    ppc_fcmp(ctx, 0, ctx->fpr[2], ctx->fpr[0], true);

label_8019B1F0:
    ctx->pc = 0x8019B1F0u;
    // 8019B1F0: cror    2, 1, 2
    {
        u32 a = (ctx->cr >> (31u - 1u)) & 1u;
        u32 b = (ctx->cr >> (31u - 2u)) & 1u;
        u32 mask = 0x80000000u >> 2;
        u32 value = (a | b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8019B1F4:
    ctx->pc = 0x8019B1F4u;
    // 8019B1F4: bc    4, 2, 0x8019B1FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019B1FC;
        }
    }

label_8019B1F8:
    ctx->pc = 0x8019B1F8u;
    ctx->downcount -= 1;
    // 8019B1F8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8019B1FC:
    ctx->pc = 0x8019B1FCu;
    ctx->downcount -= 2;
    // 8019B1FC: cmpwi   r4, 2
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019B200:
    ctx->pc = 0x8019B200u;
    // 8019B200: bc    12, 2, 0x8019B23C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019B23C;
        }
    }

label_8019B204:
    ctx->pc = 0x8019B204u;
    ctx->downcount -= 1;
    // 8019B204: bc    4, 0, 0x8019B218
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019B218;
        }
    }

label_8019B208:
    ctx->pc = 0x8019B208u;
    ctx->downcount -= 2;
    // 8019B208: cmpwi   r4, 0
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

label_8019B20C:
    ctx->pc = 0x8019B20Cu;
    // 8019B20C: bc    12, 2, 0x8019B27C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8019B27C;
        }
    }

label_8019B210:
    ctx->pc = 0x8019B210u;
    ctx->downcount -= 1;
    // 8019B210: bc    4, 0, 0x8019B224
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019B224;
        }
    }

label_8019B214:
    ctx->pc = 0x8019B214u;
    ctx->downcount -= 1;
    // 8019B214: b       0x8019B27C
    {
            goto label_8019B27C;
    }

label_8019B218:
    ctx->pc = 0x8019B218u;
    ctx->downcount -= 2;
    // 8019B218: cmpwi   r4, 4
    {
        s32 val_a = (s32)(ctx->gpr[4]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8019B21C:
    ctx->pc = 0x8019B21Cu;
    // 8019B21C: bc    4, 0, 0x8019B27C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8019B27C;
        }
    }

label_8019B220:
    ctx->pc = 0x8019B220u;
    ctx->downcount -= 1;
    // 8019B220: b       0x8019B260
    {
            goto label_8019B260;
    }

label_8019B224:
    ctx->pc = 0x8019B224u;
    ctx->downcount -= 22;
    // 8019B224: lfs     f5, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B224u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8019B228:
    ctx->pc = 0x8019B228u;
    // 8019B228: fmuls   f0, f2, f1
    if (!ppc_fp_available(ctx, 0x8019B228u)) return;
    ppc_fmuls(ctx, 0, 2, 1);

label_8019B22C:
    ctx->pc = 0x8019B22Cu;
    // 8019B22C: lfs     f4, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B22Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[4] = value;
        ctx->ps1[4] = value;
    }

label_8019B230:
    ctx->pc = 0x8019B230u;
    // 8019B230: fsubs   f1, f5, f2
    if (!ppc_fp_available(ctx, 0x8019B230u)) return;
    ppc_fsubs(ctx, 1, 5, 2);

label_8019B234:
    ctx->pc = 0x8019B234u;
    // 8019B234: fdivs   f3, f1, f0
    if (!ppc_fp_available(ctx, 0x8019B234u)) return;
    ppc_fdivs(ctx, 3, 1, 0);

label_8019B238:
    ctx->pc = 0x8019B238u;
    // 8019B238: b       0x8019B288
    {
            goto label_8019B288;
    }

label_8019B23C:
    ctx->pc = 0x8019B23Cu;
    ctx->downcount -= 41;
    // 8019B23C: lfs     f5, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B23Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8019B240:
    ctx->pc = 0x8019B240u;
    // 8019B240: fmuls   f4, f2, f1
    if (!ppc_fp_available(ctx, 0x8019B240u)) return;
    ppc_fmuls(ctx, 4, 2, 1);

label_8019B244:
    ctx->pc = 0x8019B244u;
    // 8019B244: lfs     f3, -22120(r13)
    if (!ppc_fp_available(ctx, 0x8019B244u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22120);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8019B248:
    ctx->pc = 0x8019B248u;
    // 8019B248: fsubs   f2, f5, f2
    if (!ppc_fp_available(ctx, 0x8019B248u)) return;
    ppc_fsubs(ctx, 2, 5, 2);

label_8019B24C:
    ctx->pc = 0x8019B24Cu;
    // 8019B24C: fmuls   f0, f1, f4
    if (!ppc_fp_available(ctx, 0x8019B24Cu)) return;
    ppc_fmuls(ctx, 0, 1, 4);

label_8019B250:
    ctx->pc = 0x8019B250u;
    // 8019B250: fmuls   f1, f3, f2
    if (!ppc_fp_available(ctx, 0x8019B250u)) return;
    ppc_fmuls(ctx, 1, 3, 2);

label_8019B254:
    ctx->pc = 0x8019B254u;
    // 8019B254: fdivs   f3, f1, f4
    if (!ppc_fp_available(ctx, 0x8019B254u)) return;
    ppc_fdivs(ctx, 3, 1, 4);

label_8019B258:
    ctx->pc = 0x8019B258u;
    // 8019B258: fdivs   f4, f1, f0
    if (!ppc_fp_available(ctx, 0x8019B258u)) return;
    ppc_fdivs(ctx, 4, 1, 0);

label_8019B25C:
    ctx->pc = 0x8019B25Cu;
    // 8019B25C: b       0x8019B288
    {
            goto label_8019B288;
    }

label_8019B260:
    ctx->pc = 0x8019B260u;
    ctx->downcount -= 23;
    // 8019B260: fmuls   f0, f2, f1
    if (!ppc_fp_available(ctx, 0x8019B260u)) return;
    ppc_fmuls(ctx, 0, 2, 1);

label_8019B264:
    ctx->pc = 0x8019B264u;
    // 8019B264: lfs     f5, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B264u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8019B268:
    ctx->pc = 0x8019B268u;
    // 8019B268: lfs     f3, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B268u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8019B26C:
    ctx->pc = 0x8019B26Cu;
    // 8019B26C: fsubs   f2, f5, f2
    if (!ppc_fp_available(ctx, 0x8019B26Cu)) return;
    ppc_fsubs(ctx, 2, 5, 2);

label_8019B270:
    ctx->pc = 0x8019B270u;
    // 8019B270: fmuls   f0, f1, f0
    if (!ppc_fp_available(ctx, 0x8019B270u)) return;
    ppc_fmuls(ctx, 0, 1, 0);

label_8019B274:
    ctx->pc = 0x8019B274u;
    // 8019B274: fdivs   f4, f2, f0
    if (!ppc_fp_available(ctx, 0x8019B274u)) return;
    ppc_fdivs(ctx, 4, 2, 0);

label_8019B278:
    ctx->pc = 0x8019B278u;
    // 8019B278: b       0x8019B288
    {
            goto label_8019B288;
    }

label_8019B27C:
    ctx->pc = 0x8019B27Cu;
    ctx->downcount -= 3;
    // 8019B27C: lfs     f3, -22168(r13)
    if (!ppc_fp_available(ctx, 0x8019B27Cu)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22168);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_8019B280:
    ctx->pc = 0x8019B280u;
    // 8019B280: lfs     f5, -22144(r13)
    if (!ppc_fp_available(ctx, 0x8019B280u)) return;
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-22144);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[5] = value;
        ctx->ps1[5] = value;
    }

label_8019B284:
    ctx->pc = 0x8019B284u;
    // 8019B284: fmr    f4, f3
    if (!ppc_fp_available(ctx, 0x8019B284u)) return;
    ctx->fpr[4] = ctx->fpr[3];

label_8019B288:
    ctx->pc = 0x8019B288u;
    ctx->downcount -= 4;
    // 8019B288: stfs     f5, 28(r3)
    if (!ppc_fp_available(ctx, 0x8019B288u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[5]));
    }

label_8019B28C:
    ctx->pc = 0x8019B28Cu;
    // 8019B28C: stfs     f3, 32(r3)
    if (!ppc_fp_available(ctx, 0x8019B28Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(32);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8019B290:
    ctx->pc = 0x8019B290u;
    // 8019B290: stfs     f4, 36(r3)
    if (!ppc_fp_available(ctx, 0x8019B290u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[4]));
    }

label_8019B294:
    ctx->pc = 0x8019B294u;
    // 8019B294: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019B298:
    ctx->pc = 0x8019B298u;
    ctx->downcount -= 4;
    // 8019B298: stfs     f1, 40(r3)
    if (!ppc_fp_available(ctx, 0x8019B298u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_8019B29C:
    ctx->pc = 0x8019B29Cu;
    // 8019B29C: stfs     f2, 44(r3)
    if (!ppc_fp_available(ctx, 0x8019B29Cu)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_8019B2A0:
    ctx->pc = 0x8019B2A0u;
    // 8019B2A0: stfs     f3, 48(r3)
    if (!ppc_fp_available(ctx, 0x8019B2A0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[3]));
    }

label_8019B2A4:
    ctx->pc = 0x8019B2A4u;
    // 8019B2A4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_801972C0;
        }
    }

label_8019B2A8:
    ctx->pc = 0x8019B2A8u;
    ctx->downcount -= 6;
    // 8019B2A8: lfs     f0, 40(r3)
    if (!ppc_fp_available(ctx, 0x8019B2A8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B2AC:
    ctx->pc = 0x8019B2ACu;
    // 8019B2AC: stfs     f0, 0(r4)
    if (!ppc_fp_available(ctx, 0x8019B2ACu)) return;
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B2B0:
    ctx->pc = 0x8019B2B0u;
    // 8019B2B0: lfs     f0, 44(r3)
    if (!ppc_fp_available(ctx, 0x8019B2B0u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B2B4:
    ctx->pc = 0x8019B2B4u;
    // 8019B2B4: stfs     f0, 0(r5)
    if (!ppc_fp_available(ctx, 0x8019B2B4u)) return;
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_8019B2B8:
    ctx->pc = 0x8019B2B8u;
    // 8019B2B8: lfs     f0, 48(r3)
    if (!ppc_fp_available(ctx, 0x8019B2B8u)) return;
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_8019B2BC:
    ctx->pc = 0x8019B2BCu;
    // 8019B2BC: stfs     f0, 0(r6)
    if (!ppc_fp_available(ctx, 0x8019B2BCu)) return;
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

    ctx->pc = 0x8019B2C0u;
    return;
return_dispatch_801972C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x80197340u: goto label_80197340;
    case 0x80197348u: goto label_80197348;
    case 0x80197378u: goto label_80197378;
    case 0x801973A4u: goto label_801973A4;
    case 0x801973ACu: goto label_801973AC;
    case 0x801973BCu: goto label_801973BC;
    case 0x801973C0u: goto label_801973C0;
    case 0x801973ECu: goto label_801973EC;
    case 0x801973F4u: goto label_801973F4;
    case 0x80197404u: goto label_80197404;
    case 0x80197438u: goto label_80197438;
    case 0x80197444u: goto label_80197444;
    case 0x80197450u: goto label_80197450;
    case 0x801974B8u: goto label_801974B8;
    case 0x801974C0u: goto label_801974C0;
    case 0x801974C4u: goto label_801974C4;
    case 0x801974D8u: goto label_801974D8;
    case 0x80197580u: goto label_80197580;
    case 0x801975B4u: goto label_801975B4;
    case 0x80197640u: goto label_80197640;
    case 0x80197644u: goto label_80197644;
    case 0x80197658u: goto label_80197658;
    case 0x80197740u: goto label_80197740;
    case 0x80197FD8u: goto label_80197FD8;
    case 0x801982E4u: goto label_801982E4;
    case 0x80198D64u: goto label_80198D64;
    case 0x801990F4u: goto label_801990F4;
    case 0x801991E4u: goto label_801991E4;
    case 0x80199210u: goto label_80199210;
    case 0x80199230u: goto label_80199230;
    case 0x80199244u: goto label_80199244;
    case 0x80199280u: goto label_80199280;
    case 0x80199298u: goto label_80199298;
    case 0x801992C8u: goto label_801992C8;
    case 0x801992DCu: goto label_801992DC;
    case 0x80199348u: goto label_80199348;
    case 0x80199360u: goto label_80199360;
    case 0x80199390u: goto label_80199390;
    case 0x801993A4u: goto label_801993A4;
    case 0x801993C8u: goto label_801993C8;
    case 0x80199404u: goto label_80199404;
    case 0x8019944Cu: goto label_8019944C;
    case 0x80199478u: goto label_80199478;
    case 0x80199480u: goto label_80199480;
    case 0x801994C4u: goto label_801994C4;
    case 0x801994F4u: goto label_801994F4;
    case 0x80199520u: goto label_80199520;
    case 0x8019952Cu: goto label_8019952C;
    case 0x80199558u: goto label_80199558;
    case 0x80199568u: goto label_80199568;
    case 0x8019957Cu: goto label_8019957C;
    case 0x801995A4u: goto label_801995A4;
    case 0x801995C4u: goto label_801995C4;
    case 0x801995D4u: goto label_801995D4;
    case 0x801995D8u: goto label_801995D8;
    case 0x801995E8u: goto label_801995E8;
    case 0x801995FCu: goto label_801995FC;
    case 0x80199848u: goto label_80199848;
    case 0x80199850u: goto label_80199850;
    case 0x801998A0u: goto label_801998A0;
    case 0x801998A8u: goto label_801998A8;
    case 0x801998B8u: goto label_801998B8;
    case 0x801998C0u: goto label_801998C0;
    case 0x801998C8u: goto label_801998C8;
    case 0x80199914u: goto label_80199914;
    case 0x8019991Cu: goto label_8019991C;
    case 0x8019997Cu: goto label_8019997C;
    case 0x80199984u: goto label_80199984;
    case 0x80199990u: goto label_80199990;
    case 0x80199998u: goto label_80199998;
    case 0x801999A0u: goto label_801999A0;
    case 0x801999A8u: goto label_801999A8;
    case 0x801999D8u: goto label_801999D8;
    case 0x801999E8u: goto label_801999E8;
    case 0x801999F0u: goto label_801999F0;
    case 0x801999F8u: goto label_801999F8;
    case 0x80199A00u: goto label_80199A00;
    case 0x80199B58u: goto label_80199B58;
    case 0x80199C74u: goto label_80199C74;
    case 0x80199CACu: goto label_80199CAC;
    case 0x80199CC0u: goto label_80199CC0;
    case 0x80199CD4u: goto label_80199CD4;
    case 0x80199CE8u: goto label_80199CE8;
    case 0x80199CFCu: goto label_80199CFC;
    case 0x80199D58u: goto label_80199D58;
    case 0x80199D6Cu: goto label_80199D6C;
    case 0x80199D80u: goto label_80199D80;
    case 0x80199D94u: goto label_80199D94;
    case 0x80199DA8u: goto label_80199DA8;
    case 0x80199DC8u: goto label_80199DC8;
    case 0x8019A48Cu: goto label_8019A48C;
    case 0x8019A640u: goto label_8019A640;
    case 0x8019A71Cu: goto label_8019A71C;
    case 0x8019A7C0u: goto label_8019A7C0;
    case 0x8019A868u: goto label_8019A868;
    case 0x8019A900u: goto label_8019A900;
    case 0x8019B098u: goto label_8019B098;
    default: return;
    }
}

