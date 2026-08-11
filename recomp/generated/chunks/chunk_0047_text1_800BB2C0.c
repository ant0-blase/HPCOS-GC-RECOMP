// DolRecomp output
#include "../generated.h"

static void loop_800BDA7C(CPUState* ctx) {
label_800BDA7C:
    ctx->downcount -= 4;
    ctx->pc = 0x800BDA7Cu;
    // 800BDA7C: lwzu     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[9] = ea;
    }

    // 800BDA80: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

    // 800BDA84: cmpwi   r0, 0
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

    // 800BDA88: bc    4, 2, 0x800BDA7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BDA7Cu;
                return;
            }
            goto label_800BDA7C;
        }
    }

    ctx->pc = 0x800BDA8Cu;
}

static void loop_800BE110(CPUState* ctx) {
label_800BE110:
    ctx->downcount -= 8;
    // 800BE110: addi    r11, r10, 1
    ctx->gpr[11] = ctx->gpr[10] + (u32)(s32)(1);

    // 800BE114: mulli   r9, r11, 52
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)52);

    // 800BE118: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x800BE11Cu;
    // 800BE11C: lwzx    r0, r8, r9
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 800BE120: cmpwi   r0, -1
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

    // 800BE124: bc    4, 2, 0x800BE110
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE110u;
                return;
            }
            goto label_800BE110;
        }
    }

    ctx->pc = 0x800BE128u;
}

static void loop_800BE2B0(CPUState* ctx) {
label_800BE2B0:
    ctx->downcount -= 8;
    // 800BE2B0: addi    r11, r10, 1
    ctx->gpr[11] = ctx->gpr[10] + (u32)(s32)(1);

    // 800BE2B4: mulli   r9, r11, 52
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)52);

    // 800BE2B8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

    ctx->pc = 0x800BE2BCu;
    // 800BE2BC: lwzx    r0, r8, r9
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

    // 800BE2C0: cmpwi   r0, -1
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

    // 800BE2C4: bc    4, 2, 0x800BE2B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE2B0u;
                return;
            }
            goto label_800BE2B0;
        }
    }

    ctx->pc = 0x800BE2C8u;
}

void func_800BB2C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x800BB2C0u: goto label_800BB2C0;
    case 0x800BB2C4u: goto label_800BB2C4;
    case 0x800BB2C8u: goto label_800BB2C8;
    case 0x800BB2CCu: goto label_800BB2CC;
    case 0x800BB2D0u: goto label_800BB2D0;
    case 0x800BB2D4u: goto label_800BB2D4;
    case 0x800BB2D8u: goto label_800BB2D8;
    case 0x800BB2DCu: goto label_800BB2DC;
    case 0x800BB2E0u: goto label_800BB2E0;
    case 0x800BB2E4u: goto label_800BB2E4;
    case 0x800BB2E8u: goto label_800BB2E8;
    case 0x800BB2ECu: goto label_800BB2EC;
    case 0x800BB2F0u: goto label_800BB2F0;
    case 0x800BB2F4u: goto label_800BB2F4;
    case 0x800BB2F8u: goto label_800BB2F8;
    case 0x800BB2FCu: goto label_800BB2FC;
    case 0x800BB300u: goto label_800BB300;
    case 0x800BB304u: goto label_800BB304;
    case 0x800BB308u: goto label_800BB308;
    case 0x800BB30Cu: goto label_800BB30C;
    case 0x800BB310u: goto label_800BB310;
    case 0x800BB314u: goto label_800BB314;
    case 0x800BB318u: goto label_800BB318;
    case 0x800BB31Cu: goto label_800BB31C;
    case 0x800BB320u: goto label_800BB320;
    case 0x800BB324u: goto label_800BB324;
    case 0x800BB328u: goto label_800BB328;
    case 0x800BB32Cu: goto label_800BB32C;
    case 0x800BB330u: goto label_800BB330;
    case 0x800BB334u: goto label_800BB334;
    case 0x800BB338u: goto label_800BB338;
    case 0x800BB33Cu: goto label_800BB33C;
    case 0x800BB340u: goto label_800BB340;
    case 0x800BB344u: goto label_800BB344;
    case 0x800BB348u: goto label_800BB348;
    case 0x800BB34Cu: goto label_800BB34C;
    case 0x800BB350u: goto label_800BB350;
    case 0x800BB354u: goto label_800BB354;
    case 0x800BB358u: goto label_800BB358;
    case 0x800BB35Cu: goto label_800BB35C;
    case 0x800BB360u: goto label_800BB360;
    case 0x800BB364u: goto label_800BB364;
    case 0x800BB368u: goto label_800BB368;
    case 0x800BB36Cu: goto label_800BB36C;
    case 0x800BB370u: goto label_800BB370;
    case 0x800BB374u: goto label_800BB374;
    case 0x800BB378u: goto label_800BB378;
    case 0x800BB37Cu: goto label_800BB37C;
    case 0x800BB380u: goto label_800BB380;
    case 0x800BB384u: goto label_800BB384;
    case 0x800BB388u: goto label_800BB388;
    case 0x800BB38Cu: goto label_800BB38C;
    case 0x800BB390u: goto label_800BB390;
    case 0x800BB394u: goto label_800BB394;
    case 0x800BB398u: goto label_800BB398;
    case 0x800BB39Cu: goto label_800BB39C;
    case 0x800BB3A0u: goto label_800BB3A0;
    case 0x800BB3A4u: goto label_800BB3A4;
    case 0x800BB3A8u: goto label_800BB3A8;
    case 0x800BB3ACu: goto label_800BB3AC;
    case 0x800BB3B0u: goto label_800BB3B0;
    case 0x800BB3B4u: goto label_800BB3B4;
    case 0x800BB3B8u: goto label_800BB3B8;
    case 0x800BB3BCu: goto label_800BB3BC;
    case 0x800BB3C0u: goto label_800BB3C0;
    case 0x800BB3C4u: goto label_800BB3C4;
    case 0x800BB3C8u: goto label_800BB3C8;
    case 0x800BB3CCu: goto label_800BB3CC;
    case 0x800BB3D0u: goto label_800BB3D0;
    case 0x800BB3D4u: goto label_800BB3D4;
    case 0x800BB3D8u: goto label_800BB3D8;
    case 0x800BB3DCu: goto label_800BB3DC;
    case 0x800BB3E0u: goto label_800BB3E0;
    case 0x800BB3E4u: goto label_800BB3E4;
    case 0x800BB3E8u: goto label_800BB3E8;
    case 0x800BB3ECu: goto label_800BB3EC;
    case 0x800BB3F0u: goto label_800BB3F0;
    case 0x800BB3F4u: goto label_800BB3F4;
    case 0x800BB3F8u: goto label_800BB3F8;
    case 0x800BB3FCu: goto label_800BB3FC;
    case 0x800BB400u: goto label_800BB400;
    case 0x800BB404u: goto label_800BB404;
    case 0x800BB408u: goto label_800BB408;
    case 0x800BB40Cu: goto label_800BB40C;
    case 0x800BB410u: goto label_800BB410;
    case 0x800BB414u: goto label_800BB414;
    case 0x800BB418u: goto label_800BB418;
    case 0x800BB41Cu: goto label_800BB41C;
    case 0x800BB420u: goto label_800BB420;
    case 0x800BB424u: goto label_800BB424;
    case 0x800BB428u: goto label_800BB428;
    case 0x800BB42Cu: goto label_800BB42C;
    case 0x800BB430u: goto label_800BB430;
    case 0x800BB434u: goto label_800BB434;
    case 0x800BB438u: goto label_800BB438;
    case 0x800BB43Cu: goto label_800BB43C;
    case 0x800BB440u: goto label_800BB440;
    case 0x800BB444u: goto label_800BB444;
    case 0x800BB448u: goto label_800BB448;
    case 0x800BB44Cu: goto label_800BB44C;
    case 0x800BB450u: goto label_800BB450;
    case 0x800BB454u: goto label_800BB454;
    case 0x800BB458u: goto label_800BB458;
    case 0x800BB45Cu: goto label_800BB45C;
    case 0x800BB460u: goto label_800BB460;
    case 0x800BB464u: goto label_800BB464;
    case 0x800BB468u: goto label_800BB468;
    case 0x800BB46Cu: goto label_800BB46C;
    case 0x800BB470u: goto label_800BB470;
    case 0x800BB474u: goto label_800BB474;
    case 0x800BB478u: goto label_800BB478;
    case 0x800BB47Cu: goto label_800BB47C;
    case 0x800BB480u: goto label_800BB480;
    case 0x800BB484u: goto label_800BB484;
    case 0x800BB488u: goto label_800BB488;
    case 0x800BB48Cu: goto label_800BB48C;
    case 0x800BB490u: goto label_800BB490;
    case 0x800BB494u: goto label_800BB494;
    case 0x800BB498u: goto label_800BB498;
    case 0x800BB49Cu: goto label_800BB49C;
    case 0x800BB4A0u: goto label_800BB4A0;
    case 0x800BB4A4u: goto label_800BB4A4;
    case 0x800BB4A8u: goto label_800BB4A8;
    case 0x800BB4ACu: goto label_800BB4AC;
    case 0x800BB4B0u: goto label_800BB4B0;
    case 0x800BB4B4u: goto label_800BB4B4;
    case 0x800BB4B8u: goto label_800BB4B8;
    case 0x800BB4BCu: goto label_800BB4BC;
    case 0x800BB4C0u: goto label_800BB4C0;
    case 0x800BB4C4u: goto label_800BB4C4;
    case 0x800BB4C8u: goto label_800BB4C8;
    case 0x800BB4CCu: goto label_800BB4CC;
    case 0x800BB4D0u: goto label_800BB4D0;
    case 0x800BB4D4u: goto label_800BB4D4;
    case 0x800BB4D8u: goto label_800BB4D8;
    case 0x800BB4DCu: goto label_800BB4DC;
    case 0x800BB4E0u: goto label_800BB4E0;
    case 0x800BB4E4u: goto label_800BB4E4;
    case 0x800BB4E8u: goto label_800BB4E8;
    case 0x800BB4ECu: goto label_800BB4EC;
    case 0x800BB4F0u: goto label_800BB4F0;
    case 0x800BB4F4u: goto label_800BB4F4;
    case 0x800BB4F8u: goto label_800BB4F8;
    case 0x800BB4FCu: goto label_800BB4FC;
    case 0x800BB500u: goto label_800BB500;
    case 0x800BB504u: goto label_800BB504;
    case 0x800BB508u: goto label_800BB508;
    case 0x800BB50Cu: goto label_800BB50C;
    case 0x800BB510u: goto label_800BB510;
    case 0x800BB514u: goto label_800BB514;
    case 0x800BB518u: goto label_800BB518;
    case 0x800BB51Cu: goto label_800BB51C;
    case 0x800BB520u: goto label_800BB520;
    case 0x800BB524u: goto label_800BB524;
    case 0x800BB528u: goto label_800BB528;
    case 0x800BB52Cu: goto label_800BB52C;
    case 0x800BB530u: goto label_800BB530;
    case 0x800BB534u: goto label_800BB534;
    case 0x800BB538u: goto label_800BB538;
    case 0x800BB53Cu: goto label_800BB53C;
    case 0x800BB540u: goto label_800BB540;
    case 0x800BB544u: goto label_800BB544;
    case 0x800BB548u: goto label_800BB548;
    case 0x800BB54Cu: goto label_800BB54C;
    case 0x800BB550u: goto label_800BB550;
    case 0x800BB554u: goto label_800BB554;
    case 0x800BB558u: goto label_800BB558;
    case 0x800BB55Cu: goto label_800BB55C;
    case 0x800BB560u: goto label_800BB560;
    case 0x800BB564u: goto label_800BB564;
    case 0x800BB568u: goto label_800BB568;
    case 0x800BB56Cu: goto label_800BB56C;
    case 0x800BB570u: goto label_800BB570;
    case 0x800BB574u: goto label_800BB574;
    case 0x800BB578u: goto label_800BB578;
    case 0x800BB57Cu: goto label_800BB57C;
    case 0x800BB580u: goto label_800BB580;
    case 0x800BB584u: goto label_800BB584;
    case 0x800BB588u: goto label_800BB588;
    case 0x800BB58Cu: goto label_800BB58C;
    case 0x800BB590u: goto label_800BB590;
    case 0x800BB594u: goto label_800BB594;
    case 0x800BB598u: goto label_800BB598;
    case 0x800BB59Cu: goto label_800BB59C;
    case 0x800BB5A0u: goto label_800BB5A0;
    case 0x800BB5A4u: goto label_800BB5A4;
    case 0x800BB5A8u: goto label_800BB5A8;
    case 0x800BB5ACu: goto label_800BB5AC;
    case 0x800BB5B0u: goto label_800BB5B0;
    case 0x800BB5B4u: goto label_800BB5B4;
    case 0x800BB5B8u: goto label_800BB5B8;
    case 0x800BB5BCu: goto label_800BB5BC;
    case 0x800BB5C0u: goto label_800BB5C0;
    case 0x800BB5C4u: goto label_800BB5C4;
    case 0x800BB5C8u: goto label_800BB5C8;
    case 0x800BB5CCu: goto label_800BB5CC;
    case 0x800BB5D0u: goto label_800BB5D0;
    case 0x800BB5D4u: goto label_800BB5D4;
    case 0x800BB5D8u: goto label_800BB5D8;
    case 0x800BB5DCu: goto label_800BB5DC;
    case 0x800BB5E0u: goto label_800BB5E0;
    case 0x800BB5E4u: goto label_800BB5E4;
    case 0x800BB5E8u: goto label_800BB5E8;
    case 0x800BB5ECu: goto label_800BB5EC;
    case 0x800BB5F0u: goto label_800BB5F0;
    case 0x800BB5F4u: goto label_800BB5F4;
    case 0x800BB5F8u: goto label_800BB5F8;
    case 0x800BB5FCu: goto label_800BB5FC;
    case 0x800BB600u: goto label_800BB600;
    case 0x800BB604u: goto label_800BB604;
    case 0x800BB608u: goto label_800BB608;
    case 0x800BB60Cu: goto label_800BB60C;
    case 0x800BB610u: goto label_800BB610;
    case 0x800BB614u: goto label_800BB614;
    case 0x800BB618u: goto label_800BB618;
    case 0x800BB61Cu: goto label_800BB61C;
    case 0x800BB620u: goto label_800BB620;
    case 0x800BB624u: goto label_800BB624;
    case 0x800BB628u: goto label_800BB628;
    case 0x800BB62Cu: goto label_800BB62C;
    case 0x800BB630u: goto label_800BB630;
    case 0x800BB634u: goto label_800BB634;
    case 0x800BB638u: goto label_800BB638;
    case 0x800BB63Cu: goto label_800BB63C;
    case 0x800BB640u: goto label_800BB640;
    case 0x800BB644u: goto label_800BB644;
    case 0x800BB648u: goto label_800BB648;
    case 0x800BB64Cu: goto label_800BB64C;
    case 0x800BB650u: goto label_800BB650;
    case 0x800BB654u: goto label_800BB654;
    case 0x800BB658u: goto label_800BB658;
    case 0x800BB65Cu: goto label_800BB65C;
    case 0x800BB660u: goto label_800BB660;
    case 0x800BB664u: goto label_800BB664;
    case 0x800BB668u: goto label_800BB668;
    case 0x800BB66Cu: goto label_800BB66C;
    case 0x800BB670u: goto label_800BB670;
    case 0x800BB674u: goto label_800BB674;
    case 0x800BB678u: goto label_800BB678;
    case 0x800BB67Cu: goto label_800BB67C;
    case 0x800BB680u: goto label_800BB680;
    case 0x800BB684u: goto label_800BB684;
    case 0x800BB688u: goto label_800BB688;
    case 0x800BB68Cu: goto label_800BB68C;
    case 0x800BB690u: goto label_800BB690;
    case 0x800BB694u: goto label_800BB694;
    case 0x800BB698u: goto label_800BB698;
    case 0x800BB69Cu: goto label_800BB69C;
    case 0x800BB6A0u: goto label_800BB6A0;
    case 0x800BB6A4u: goto label_800BB6A4;
    case 0x800BB6A8u: goto label_800BB6A8;
    case 0x800BB6ACu: goto label_800BB6AC;
    case 0x800BB6B0u: goto label_800BB6B0;
    case 0x800BB6B4u: goto label_800BB6B4;
    case 0x800BB6B8u: goto label_800BB6B8;
    case 0x800BB6BCu: goto label_800BB6BC;
    case 0x800BB6C0u: goto label_800BB6C0;
    case 0x800BB6C4u: goto label_800BB6C4;
    case 0x800BB6C8u: goto label_800BB6C8;
    case 0x800BB6CCu: goto label_800BB6CC;
    case 0x800BB6D0u: goto label_800BB6D0;
    case 0x800BB6D4u: goto label_800BB6D4;
    case 0x800BB6D8u: goto label_800BB6D8;
    case 0x800BB6DCu: goto label_800BB6DC;
    case 0x800BB6E0u: goto label_800BB6E0;
    case 0x800BB6E4u: goto label_800BB6E4;
    case 0x800BB6E8u: goto label_800BB6E8;
    case 0x800BB6ECu: goto label_800BB6EC;
    case 0x800BB6F0u: goto label_800BB6F0;
    case 0x800BB6F4u: goto label_800BB6F4;
    case 0x800BB6F8u: goto label_800BB6F8;
    case 0x800BB6FCu: goto label_800BB6FC;
    case 0x800BB700u: goto label_800BB700;
    case 0x800BB704u: goto label_800BB704;
    case 0x800BB708u: goto label_800BB708;
    case 0x800BB70Cu: goto label_800BB70C;
    case 0x800BB710u: goto label_800BB710;
    case 0x800BB714u: goto label_800BB714;
    case 0x800BB718u: goto label_800BB718;
    case 0x800BB71Cu: goto label_800BB71C;
    case 0x800BB720u: goto label_800BB720;
    case 0x800BB724u: goto label_800BB724;
    case 0x800BB728u: goto label_800BB728;
    case 0x800BB72Cu: goto label_800BB72C;
    case 0x800BB730u: goto label_800BB730;
    case 0x800BB734u: goto label_800BB734;
    case 0x800BB738u: goto label_800BB738;
    case 0x800BB73Cu: goto label_800BB73C;
    case 0x800BB740u: goto label_800BB740;
    case 0x800BB744u: goto label_800BB744;
    case 0x800BB748u: goto label_800BB748;
    case 0x800BB74Cu: goto label_800BB74C;
    case 0x800BB750u: goto label_800BB750;
    case 0x800BB754u: goto label_800BB754;
    case 0x800BB758u: goto label_800BB758;
    case 0x800BB75Cu: goto label_800BB75C;
    case 0x800BB760u: goto label_800BB760;
    case 0x800BB764u: goto label_800BB764;
    case 0x800BB768u: goto label_800BB768;
    case 0x800BB76Cu: goto label_800BB76C;
    case 0x800BB770u: goto label_800BB770;
    case 0x800BB774u: goto label_800BB774;
    case 0x800BB778u: goto label_800BB778;
    case 0x800BB77Cu: goto label_800BB77C;
    case 0x800BB780u: goto label_800BB780;
    case 0x800BB784u: goto label_800BB784;
    case 0x800BB788u: goto label_800BB788;
    case 0x800BB78Cu: goto label_800BB78C;
    case 0x800BB790u: goto label_800BB790;
    case 0x800BB794u: goto label_800BB794;
    case 0x800BB798u: goto label_800BB798;
    case 0x800BB79Cu: goto label_800BB79C;
    case 0x800BB7A0u: goto label_800BB7A0;
    case 0x800BB7A4u: goto label_800BB7A4;
    case 0x800BB7A8u: goto label_800BB7A8;
    case 0x800BB7ACu: goto label_800BB7AC;
    case 0x800BB7B0u: goto label_800BB7B0;
    case 0x800BB7B4u: goto label_800BB7B4;
    case 0x800BB7B8u: goto label_800BB7B8;
    case 0x800BB7BCu: goto label_800BB7BC;
    case 0x800BB7C0u: goto label_800BB7C0;
    case 0x800BB7C4u: goto label_800BB7C4;
    case 0x800BB7C8u: goto label_800BB7C8;
    case 0x800BB7CCu: goto label_800BB7CC;
    case 0x800BB7D0u: goto label_800BB7D0;
    case 0x800BB7D4u: goto label_800BB7D4;
    case 0x800BB7D8u: goto label_800BB7D8;
    case 0x800BB7DCu: goto label_800BB7DC;
    case 0x800BB7E0u: goto label_800BB7E0;
    case 0x800BB7E4u: goto label_800BB7E4;
    case 0x800BB7E8u: goto label_800BB7E8;
    case 0x800BB7ECu: goto label_800BB7EC;
    case 0x800BB7F0u: goto label_800BB7F0;
    case 0x800BB7F4u: goto label_800BB7F4;
    case 0x800BB7F8u: goto label_800BB7F8;
    case 0x800BB7FCu: goto label_800BB7FC;
    case 0x800BB800u: goto label_800BB800;
    case 0x800BB804u: goto label_800BB804;
    case 0x800BB808u: goto label_800BB808;
    case 0x800BB80Cu: goto label_800BB80C;
    case 0x800BB810u: goto label_800BB810;
    case 0x800BB814u: goto label_800BB814;
    case 0x800BB818u: goto label_800BB818;
    case 0x800BB81Cu: goto label_800BB81C;
    case 0x800BB820u: goto label_800BB820;
    case 0x800BB824u: goto label_800BB824;
    case 0x800BB828u: goto label_800BB828;
    case 0x800BB82Cu: goto label_800BB82C;
    case 0x800BB830u: goto label_800BB830;
    case 0x800BB834u: goto label_800BB834;
    case 0x800BB838u: goto label_800BB838;
    case 0x800BB83Cu: goto label_800BB83C;
    case 0x800BB840u: goto label_800BB840;
    case 0x800BB844u: goto label_800BB844;
    case 0x800BB848u: goto label_800BB848;
    case 0x800BB84Cu: goto label_800BB84C;
    case 0x800BB850u: goto label_800BB850;
    case 0x800BB854u: goto label_800BB854;
    case 0x800BB858u: goto label_800BB858;
    case 0x800BB85Cu: goto label_800BB85C;
    case 0x800BB860u: goto label_800BB860;
    case 0x800BB864u: goto label_800BB864;
    case 0x800BB868u: goto label_800BB868;
    case 0x800BB86Cu: goto label_800BB86C;
    case 0x800BB870u: goto label_800BB870;
    case 0x800BB874u: goto label_800BB874;
    case 0x800BB878u: goto label_800BB878;
    case 0x800BB87Cu: goto label_800BB87C;
    case 0x800BB880u: goto label_800BB880;
    case 0x800BB884u: goto label_800BB884;
    case 0x800BB888u: goto label_800BB888;
    case 0x800BB88Cu: goto label_800BB88C;
    case 0x800BB890u: goto label_800BB890;
    case 0x800BB894u: goto label_800BB894;
    case 0x800BB898u: goto label_800BB898;
    case 0x800BB89Cu: goto label_800BB89C;
    case 0x800BB8A0u: goto label_800BB8A0;
    case 0x800BB8A4u: goto label_800BB8A4;
    case 0x800BB8A8u: goto label_800BB8A8;
    case 0x800BB8ACu: goto label_800BB8AC;
    case 0x800BB8B0u: goto label_800BB8B0;
    case 0x800BB8B4u: goto label_800BB8B4;
    case 0x800BB8B8u: goto label_800BB8B8;
    case 0x800BB8BCu: goto label_800BB8BC;
    case 0x800BB8C0u: goto label_800BB8C0;
    case 0x800BB8C4u: goto label_800BB8C4;
    case 0x800BB8C8u: goto label_800BB8C8;
    case 0x800BB8CCu: goto label_800BB8CC;
    case 0x800BB8D0u: goto label_800BB8D0;
    case 0x800BB8D4u: goto label_800BB8D4;
    case 0x800BB8D8u: goto label_800BB8D8;
    case 0x800BB8DCu: goto label_800BB8DC;
    case 0x800BB8E0u: goto label_800BB8E0;
    case 0x800BB8E4u: goto label_800BB8E4;
    case 0x800BB8E8u: goto label_800BB8E8;
    case 0x800BB8ECu: goto label_800BB8EC;
    case 0x800BB8F0u: goto label_800BB8F0;
    case 0x800BB8F4u: goto label_800BB8F4;
    case 0x800BB8F8u: goto label_800BB8F8;
    case 0x800BB8FCu: goto label_800BB8FC;
    case 0x800BB900u: goto label_800BB900;
    case 0x800BB904u: goto label_800BB904;
    case 0x800BB908u: goto label_800BB908;
    case 0x800BB90Cu: goto label_800BB90C;
    case 0x800BB910u: goto label_800BB910;
    case 0x800BB914u: goto label_800BB914;
    case 0x800BB918u: goto label_800BB918;
    case 0x800BB91Cu: goto label_800BB91C;
    case 0x800BB920u: goto label_800BB920;
    case 0x800BB924u: goto label_800BB924;
    case 0x800BB928u: goto label_800BB928;
    case 0x800BB92Cu: goto label_800BB92C;
    case 0x800BB930u: goto label_800BB930;
    case 0x800BB934u: goto label_800BB934;
    case 0x800BB938u: goto label_800BB938;
    case 0x800BB93Cu: goto label_800BB93C;
    case 0x800BB940u: goto label_800BB940;
    case 0x800BB944u: goto label_800BB944;
    case 0x800BB948u: goto label_800BB948;
    case 0x800BB94Cu: goto label_800BB94C;
    case 0x800BB950u: goto label_800BB950;
    case 0x800BB954u: goto label_800BB954;
    case 0x800BB958u: goto label_800BB958;
    case 0x800BB95Cu: goto label_800BB95C;
    case 0x800BB960u: goto label_800BB960;
    case 0x800BB964u: goto label_800BB964;
    case 0x800BB968u: goto label_800BB968;
    case 0x800BB96Cu: goto label_800BB96C;
    case 0x800BB970u: goto label_800BB970;
    case 0x800BB974u: goto label_800BB974;
    case 0x800BB978u: goto label_800BB978;
    case 0x800BB97Cu: goto label_800BB97C;
    case 0x800BB980u: goto label_800BB980;
    case 0x800BB984u: goto label_800BB984;
    case 0x800BB988u: goto label_800BB988;
    case 0x800BB98Cu: goto label_800BB98C;
    case 0x800BB990u: goto label_800BB990;
    case 0x800BB994u: goto label_800BB994;
    case 0x800BB998u: goto label_800BB998;
    case 0x800BB99Cu: goto label_800BB99C;
    case 0x800BB9A0u: goto label_800BB9A0;
    case 0x800BB9A4u: goto label_800BB9A4;
    case 0x800BB9A8u: goto label_800BB9A8;
    case 0x800BB9ACu: goto label_800BB9AC;
    case 0x800BB9B0u: goto label_800BB9B0;
    case 0x800BB9B4u: goto label_800BB9B4;
    case 0x800BB9B8u: goto label_800BB9B8;
    case 0x800BB9BCu: goto label_800BB9BC;
    case 0x800BB9C0u: goto label_800BB9C0;
    case 0x800BB9C4u: goto label_800BB9C4;
    case 0x800BB9C8u: goto label_800BB9C8;
    case 0x800BB9CCu: goto label_800BB9CC;
    case 0x800BB9D0u: goto label_800BB9D0;
    case 0x800BB9D4u: goto label_800BB9D4;
    case 0x800BB9D8u: goto label_800BB9D8;
    case 0x800BB9DCu: goto label_800BB9DC;
    case 0x800BB9E0u: goto label_800BB9E0;
    case 0x800BB9E4u: goto label_800BB9E4;
    case 0x800BB9E8u: goto label_800BB9E8;
    case 0x800BB9ECu: goto label_800BB9EC;
    case 0x800BB9F0u: goto label_800BB9F0;
    case 0x800BB9F4u: goto label_800BB9F4;
    case 0x800BB9F8u: goto label_800BB9F8;
    case 0x800BB9FCu: goto label_800BB9FC;
    case 0x800BBA00u: goto label_800BBA00;
    case 0x800BBA04u: goto label_800BBA04;
    case 0x800BBA08u: goto label_800BBA08;
    case 0x800BBA0Cu: goto label_800BBA0C;
    case 0x800BBA10u: goto label_800BBA10;
    case 0x800BBA14u: goto label_800BBA14;
    case 0x800BBA18u: goto label_800BBA18;
    case 0x800BBA1Cu: goto label_800BBA1C;
    case 0x800BBA20u: goto label_800BBA20;
    case 0x800BBA24u: goto label_800BBA24;
    case 0x800BBA28u: goto label_800BBA28;
    case 0x800BBA2Cu: goto label_800BBA2C;
    case 0x800BBA30u: goto label_800BBA30;
    case 0x800BBA34u: goto label_800BBA34;
    case 0x800BBA38u: goto label_800BBA38;
    case 0x800BBA3Cu: goto label_800BBA3C;
    case 0x800BBA40u: goto label_800BBA40;
    case 0x800BBA44u: goto label_800BBA44;
    case 0x800BBA48u: goto label_800BBA48;
    case 0x800BBA4Cu: goto label_800BBA4C;
    case 0x800BBA50u: goto label_800BBA50;
    case 0x800BBA54u: goto label_800BBA54;
    case 0x800BBA58u: goto label_800BBA58;
    case 0x800BBA5Cu: goto label_800BBA5C;
    case 0x800BBA60u: goto label_800BBA60;
    case 0x800BBA64u: goto label_800BBA64;
    case 0x800BBA68u: goto label_800BBA68;
    case 0x800BBA6Cu: goto label_800BBA6C;
    case 0x800BBA70u: goto label_800BBA70;
    case 0x800BBA74u: goto label_800BBA74;
    case 0x800BBA78u: goto label_800BBA78;
    case 0x800BBA7Cu: goto label_800BBA7C;
    case 0x800BBA80u: goto label_800BBA80;
    case 0x800BBA84u: goto label_800BBA84;
    case 0x800BBA88u: goto label_800BBA88;
    case 0x800BBA8Cu: goto label_800BBA8C;
    case 0x800BBA90u: goto label_800BBA90;
    case 0x800BBA94u: goto label_800BBA94;
    case 0x800BBA98u: goto label_800BBA98;
    case 0x800BBA9Cu: goto label_800BBA9C;
    case 0x800BBAA0u: goto label_800BBAA0;
    case 0x800BBAA4u: goto label_800BBAA4;
    case 0x800BBAA8u: goto label_800BBAA8;
    case 0x800BBAACu: goto label_800BBAAC;
    case 0x800BBAB0u: goto label_800BBAB0;
    case 0x800BBAB4u: goto label_800BBAB4;
    case 0x800BBAB8u: goto label_800BBAB8;
    case 0x800BBABCu: goto label_800BBABC;
    case 0x800BBAC0u: goto label_800BBAC0;
    case 0x800BBAC4u: goto label_800BBAC4;
    case 0x800BBAC8u: goto label_800BBAC8;
    case 0x800BBACCu: goto label_800BBACC;
    case 0x800BBAD0u: goto label_800BBAD0;
    case 0x800BBAD4u: goto label_800BBAD4;
    case 0x800BBAD8u: goto label_800BBAD8;
    case 0x800BBADCu: goto label_800BBADC;
    case 0x800BBAE0u: goto label_800BBAE0;
    case 0x800BBAE4u: goto label_800BBAE4;
    case 0x800BBAE8u: goto label_800BBAE8;
    case 0x800BBAECu: goto label_800BBAEC;
    case 0x800BBAF0u: goto label_800BBAF0;
    case 0x800BBAF4u: goto label_800BBAF4;
    case 0x800BBAF8u: goto label_800BBAF8;
    case 0x800BBAFCu: goto label_800BBAFC;
    case 0x800BBB00u: goto label_800BBB00;
    case 0x800BBB04u: goto label_800BBB04;
    case 0x800BBB08u: goto label_800BBB08;
    case 0x800BBB0Cu: goto label_800BBB0C;
    case 0x800BBB10u: goto label_800BBB10;
    case 0x800BBB14u: goto label_800BBB14;
    case 0x800BBB18u: goto label_800BBB18;
    case 0x800BBB1Cu: goto label_800BBB1C;
    case 0x800BBB20u: goto label_800BBB20;
    case 0x800BBB24u: goto label_800BBB24;
    case 0x800BBB28u: goto label_800BBB28;
    case 0x800BBB2Cu: goto label_800BBB2C;
    case 0x800BBB30u: goto label_800BBB30;
    case 0x800BBB34u: goto label_800BBB34;
    case 0x800BBB38u: goto label_800BBB38;
    case 0x800BBB3Cu: goto label_800BBB3C;
    case 0x800BBB40u: goto label_800BBB40;
    case 0x800BBB44u: goto label_800BBB44;
    case 0x800BBB48u: goto label_800BBB48;
    case 0x800BBB4Cu: goto label_800BBB4C;
    case 0x800BBB50u: goto label_800BBB50;
    case 0x800BBB54u: goto label_800BBB54;
    case 0x800BBB58u: goto label_800BBB58;
    case 0x800BBB5Cu: goto label_800BBB5C;
    case 0x800BBB60u: goto label_800BBB60;
    case 0x800BBB64u: goto label_800BBB64;
    case 0x800BBB68u: goto label_800BBB68;
    case 0x800BBB6Cu: goto label_800BBB6C;
    case 0x800BBB70u: goto label_800BBB70;
    case 0x800BBB74u: goto label_800BBB74;
    case 0x800BBB78u: goto label_800BBB78;
    case 0x800BBB7Cu: goto label_800BBB7C;
    case 0x800BBB80u: goto label_800BBB80;
    case 0x800BBB84u: goto label_800BBB84;
    case 0x800BBB88u: goto label_800BBB88;
    case 0x800BBB8Cu: goto label_800BBB8C;
    case 0x800BBB90u: goto label_800BBB90;
    case 0x800BBB94u: goto label_800BBB94;
    case 0x800BBB98u: goto label_800BBB98;
    case 0x800BBB9Cu: goto label_800BBB9C;
    case 0x800BBBA0u: goto label_800BBBA0;
    case 0x800BBBA4u: goto label_800BBBA4;
    case 0x800BBBA8u: goto label_800BBBA8;
    case 0x800BBBACu: goto label_800BBBAC;
    case 0x800BBBB0u: goto label_800BBBB0;
    case 0x800BBBB4u: goto label_800BBBB4;
    case 0x800BBBB8u: goto label_800BBBB8;
    case 0x800BBBBCu: goto label_800BBBBC;
    case 0x800BBBC0u: goto label_800BBBC0;
    case 0x800BBBC4u: goto label_800BBBC4;
    case 0x800BBBC8u: goto label_800BBBC8;
    case 0x800BBBCCu: goto label_800BBBCC;
    case 0x800BBBD0u: goto label_800BBBD0;
    case 0x800BBBD4u: goto label_800BBBD4;
    case 0x800BBBD8u: goto label_800BBBD8;
    case 0x800BBBDCu: goto label_800BBBDC;
    case 0x800BBBE0u: goto label_800BBBE0;
    case 0x800BBBE4u: goto label_800BBBE4;
    case 0x800BBBE8u: goto label_800BBBE8;
    case 0x800BBBECu: goto label_800BBBEC;
    case 0x800BBBF0u: goto label_800BBBF0;
    case 0x800BBBF4u: goto label_800BBBF4;
    case 0x800BBBF8u: goto label_800BBBF8;
    case 0x800BBBFCu: goto label_800BBBFC;
    case 0x800BBC00u: goto label_800BBC00;
    case 0x800BBC04u: goto label_800BBC04;
    case 0x800BBC08u: goto label_800BBC08;
    case 0x800BBC0Cu: goto label_800BBC0C;
    case 0x800BBC10u: goto label_800BBC10;
    case 0x800BBC14u: goto label_800BBC14;
    case 0x800BBC18u: goto label_800BBC18;
    case 0x800BBC1Cu: goto label_800BBC1C;
    case 0x800BBC20u: goto label_800BBC20;
    case 0x800BBC24u: goto label_800BBC24;
    case 0x800BBC28u: goto label_800BBC28;
    case 0x800BBC2Cu: goto label_800BBC2C;
    case 0x800BBC30u: goto label_800BBC30;
    case 0x800BBC34u: goto label_800BBC34;
    case 0x800BBC38u: goto label_800BBC38;
    case 0x800BBC3Cu: goto label_800BBC3C;
    case 0x800BBC40u: goto label_800BBC40;
    case 0x800BBC44u: goto label_800BBC44;
    case 0x800BBC48u: goto label_800BBC48;
    case 0x800BBC4Cu: goto label_800BBC4C;
    case 0x800BBC50u: goto label_800BBC50;
    case 0x800BBC54u: goto label_800BBC54;
    case 0x800BBC58u: goto label_800BBC58;
    case 0x800BBC5Cu: goto label_800BBC5C;
    case 0x800BBC60u: goto label_800BBC60;
    case 0x800BBC64u: goto label_800BBC64;
    case 0x800BBC68u: goto label_800BBC68;
    case 0x800BBC6Cu: goto label_800BBC6C;
    case 0x800BBC70u: goto label_800BBC70;
    case 0x800BBC74u: goto label_800BBC74;
    case 0x800BBC78u: goto label_800BBC78;
    case 0x800BBC7Cu: goto label_800BBC7C;
    case 0x800BBC80u: goto label_800BBC80;
    case 0x800BBC84u: goto label_800BBC84;
    case 0x800BBC88u: goto label_800BBC88;
    case 0x800BBC8Cu: goto label_800BBC8C;
    case 0x800BBC90u: goto label_800BBC90;
    case 0x800BBC94u: goto label_800BBC94;
    case 0x800BBC98u: goto label_800BBC98;
    case 0x800BBC9Cu: goto label_800BBC9C;
    case 0x800BBCA0u: goto label_800BBCA0;
    case 0x800BBCA4u: goto label_800BBCA4;
    case 0x800BBCA8u: goto label_800BBCA8;
    case 0x800BBCACu: goto label_800BBCAC;
    case 0x800BBCB0u: goto label_800BBCB0;
    case 0x800BBCB4u: goto label_800BBCB4;
    case 0x800BBCB8u: goto label_800BBCB8;
    case 0x800BBCBCu: goto label_800BBCBC;
    case 0x800BBCC0u: goto label_800BBCC0;
    case 0x800BBCC4u: goto label_800BBCC4;
    case 0x800BBCC8u: goto label_800BBCC8;
    case 0x800BBCCCu: goto label_800BBCCC;
    case 0x800BBCD0u: goto label_800BBCD0;
    case 0x800BBCD4u: goto label_800BBCD4;
    case 0x800BBCD8u: goto label_800BBCD8;
    case 0x800BBCDCu: goto label_800BBCDC;
    case 0x800BBCE0u: goto label_800BBCE0;
    case 0x800BBCE4u: goto label_800BBCE4;
    case 0x800BBCE8u: goto label_800BBCE8;
    case 0x800BBCECu: goto label_800BBCEC;
    case 0x800BBCF0u: goto label_800BBCF0;
    case 0x800BBCF4u: goto label_800BBCF4;
    case 0x800BBCF8u: goto label_800BBCF8;
    case 0x800BBCFCu: goto label_800BBCFC;
    case 0x800BBD00u: goto label_800BBD00;
    case 0x800BBD04u: goto label_800BBD04;
    case 0x800BBD08u: goto label_800BBD08;
    case 0x800BBD0Cu: goto label_800BBD0C;
    case 0x800BBD10u: goto label_800BBD10;
    case 0x800BBD14u: goto label_800BBD14;
    case 0x800BBD18u: goto label_800BBD18;
    case 0x800BBD1Cu: goto label_800BBD1C;
    case 0x800BBD20u: goto label_800BBD20;
    case 0x800BBD24u: goto label_800BBD24;
    case 0x800BBD28u: goto label_800BBD28;
    case 0x800BBD2Cu: goto label_800BBD2C;
    case 0x800BBD30u: goto label_800BBD30;
    case 0x800BBD34u: goto label_800BBD34;
    case 0x800BBD38u: goto label_800BBD38;
    case 0x800BBD3Cu: goto label_800BBD3C;
    case 0x800BBD40u: goto label_800BBD40;
    case 0x800BBD44u: goto label_800BBD44;
    case 0x800BBD48u: goto label_800BBD48;
    case 0x800BBD4Cu: goto label_800BBD4C;
    case 0x800BBD50u: goto label_800BBD50;
    case 0x800BBD54u: goto label_800BBD54;
    case 0x800BBD58u: goto label_800BBD58;
    case 0x800BBD5Cu: goto label_800BBD5C;
    case 0x800BBD60u: goto label_800BBD60;
    case 0x800BBD64u: goto label_800BBD64;
    case 0x800BBD68u: goto label_800BBD68;
    case 0x800BBD6Cu: goto label_800BBD6C;
    case 0x800BBD70u: goto label_800BBD70;
    case 0x800BBD74u: goto label_800BBD74;
    case 0x800BBD78u: goto label_800BBD78;
    case 0x800BBD7Cu: goto label_800BBD7C;
    case 0x800BBD80u: goto label_800BBD80;
    case 0x800BBD84u: goto label_800BBD84;
    case 0x800BBD88u: goto label_800BBD88;
    case 0x800BBD8Cu: goto label_800BBD8C;
    case 0x800BBD90u: goto label_800BBD90;
    case 0x800BBD94u: goto label_800BBD94;
    case 0x800BBD98u: goto label_800BBD98;
    case 0x800BBD9Cu: goto label_800BBD9C;
    case 0x800BBDA0u: goto label_800BBDA0;
    case 0x800BBDA4u: goto label_800BBDA4;
    case 0x800BBDA8u: goto label_800BBDA8;
    case 0x800BBDACu: goto label_800BBDAC;
    case 0x800BBDB0u: goto label_800BBDB0;
    case 0x800BBDB4u: goto label_800BBDB4;
    case 0x800BBDB8u: goto label_800BBDB8;
    case 0x800BBDBCu: goto label_800BBDBC;
    case 0x800BBDC0u: goto label_800BBDC0;
    case 0x800BBDC4u: goto label_800BBDC4;
    case 0x800BBDC8u: goto label_800BBDC8;
    case 0x800BBDCCu: goto label_800BBDCC;
    case 0x800BBDD0u: goto label_800BBDD0;
    case 0x800BBDD4u: goto label_800BBDD4;
    case 0x800BBDD8u: goto label_800BBDD8;
    case 0x800BBDDCu: goto label_800BBDDC;
    case 0x800BBDE0u: goto label_800BBDE0;
    case 0x800BBDE4u: goto label_800BBDE4;
    case 0x800BBDE8u: goto label_800BBDE8;
    case 0x800BBDECu: goto label_800BBDEC;
    case 0x800BBDF0u: goto label_800BBDF0;
    case 0x800BBDF4u: goto label_800BBDF4;
    case 0x800BBDF8u: goto label_800BBDF8;
    case 0x800BBDFCu: goto label_800BBDFC;
    case 0x800BBE00u: goto label_800BBE00;
    case 0x800BBE04u: goto label_800BBE04;
    case 0x800BBE08u: goto label_800BBE08;
    case 0x800BBE0Cu: goto label_800BBE0C;
    case 0x800BBE10u: goto label_800BBE10;
    case 0x800BBE14u: goto label_800BBE14;
    case 0x800BBE18u: goto label_800BBE18;
    case 0x800BBE1Cu: goto label_800BBE1C;
    case 0x800BBE20u: goto label_800BBE20;
    case 0x800BBE24u: goto label_800BBE24;
    case 0x800BBE28u: goto label_800BBE28;
    case 0x800BBE2Cu: goto label_800BBE2C;
    case 0x800BBE30u: goto label_800BBE30;
    case 0x800BBE34u: goto label_800BBE34;
    case 0x800BBE38u: goto label_800BBE38;
    case 0x800BBE3Cu: goto label_800BBE3C;
    case 0x800BBE40u: goto label_800BBE40;
    case 0x800BBE44u: goto label_800BBE44;
    case 0x800BBE48u: goto label_800BBE48;
    case 0x800BBE4Cu: goto label_800BBE4C;
    case 0x800BBE50u: goto label_800BBE50;
    case 0x800BBE54u: goto label_800BBE54;
    case 0x800BBE58u: goto label_800BBE58;
    case 0x800BBE5Cu: goto label_800BBE5C;
    case 0x800BBE60u: goto label_800BBE60;
    case 0x800BBE64u: goto label_800BBE64;
    case 0x800BBE68u: goto label_800BBE68;
    case 0x800BBE6Cu: goto label_800BBE6C;
    case 0x800BBE70u: goto label_800BBE70;
    case 0x800BBE74u: goto label_800BBE74;
    case 0x800BBE78u: goto label_800BBE78;
    case 0x800BBE7Cu: goto label_800BBE7C;
    case 0x800BBE80u: goto label_800BBE80;
    case 0x800BBE84u: goto label_800BBE84;
    case 0x800BBE88u: goto label_800BBE88;
    case 0x800BBE8Cu: goto label_800BBE8C;
    case 0x800BBE90u: goto label_800BBE90;
    case 0x800BBE94u: goto label_800BBE94;
    case 0x800BBE98u: goto label_800BBE98;
    case 0x800BBE9Cu: goto label_800BBE9C;
    case 0x800BBEA0u: goto label_800BBEA0;
    case 0x800BBEA4u: goto label_800BBEA4;
    case 0x800BBEA8u: goto label_800BBEA8;
    case 0x800BBEACu: goto label_800BBEAC;
    case 0x800BBEB0u: goto label_800BBEB0;
    case 0x800BBEB4u: goto label_800BBEB4;
    case 0x800BBEB8u: goto label_800BBEB8;
    case 0x800BBEBCu: goto label_800BBEBC;
    case 0x800BBEC0u: goto label_800BBEC0;
    case 0x800BBEC4u: goto label_800BBEC4;
    case 0x800BBEC8u: goto label_800BBEC8;
    case 0x800BBECCu: goto label_800BBECC;
    case 0x800BBED0u: goto label_800BBED0;
    case 0x800BBED4u: goto label_800BBED4;
    case 0x800BBED8u: goto label_800BBED8;
    case 0x800BBEDCu: goto label_800BBEDC;
    case 0x800BBEE0u: goto label_800BBEE0;
    case 0x800BBEE4u: goto label_800BBEE4;
    case 0x800BBEE8u: goto label_800BBEE8;
    case 0x800BBEECu: goto label_800BBEEC;
    case 0x800BBEF0u: goto label_800BBEF0;
    case 0x800BBEF4u: goto label_800BBEF4;
    case 0x800BBEF8u: goto label_800BBEF8;
    case 0x800BBEFCu: goto label_800BBEFC;
    case 0x800BBF00u: goto label_800BBF00;
    case 0x800BBF04u: goto label_800BBF04;
    case 0x800BBF08u: goto label_800BBF08;
    case 0x800BBF0Cu: goto label_800BBF0C;
    case 0x800BBF10u: goto label_800BBF10;
    case 0x800BBF14u: goto label_800BBF14;
    case 0x800BBF18u: goto label_800BBF18;
    case 0x800BBF1Cu: goto label_800BBF1C;
    case 0x800BBF20u: goto label_800BBF20;
    case 0x800BBF24u: goto label_800BBF24;
    case 0x800BBF28u: goto label_800BBF28;
    case 0x800BBF2Cu: goto label_800BBF2C;
    case 0x800BBF30u: goto label_800BBF30;
    case 0x800BBF34u: goto label_800BBF34;
    case 0x800BBF38u: goto label_800BBF38;
    case 0x800BBF3Cu: goto label_800BBF3C;
    case 0x800BBF40u: goto label_800BBF40;
    case 0x800BBF44u: goto label_800BBF44;
    case 0x800BBF48u: goto label_800BBF48;
    case 0x800BBF4Cu: goto label_800BBF4C;
    case 0x800BBF50u: goto label_800BBF50;
    case 0x800BBF54u: goto label_800BBF54;
    case 0x800BBF58u: goto label_800BBF58;
    case 0x800BBF5Cu: goto label_800BBF5C;
    case 0x800BBF60u: goto label_800BBF60;
    case 0x800BBF64u: goto label_800BBF64;
    case 0x800BBF68u: goto label_800BBF68;
    case 0x800BBF6Cu: goto label_800BBF6C;
    case 0x800BBF70u: goto label_800BBF70;
    case 0x800BBF74u: goto label_800BBF74;
    case 0x800BBF78u: goto label_800BBF78;
    case 0x800BBF7Cu: goto label_800BBF7C;
    case 0x800BBF80u: goto label_800BBF80;
    case 0x800BBF84u: goto label_800BBF84;
    case 0x800BBF88u: goto label_800BBF88;
    case 0x800BBF8Cu: goto label_800BBF8C;
    case 0x800BBF90u: goto label_800BBF90;
    case 0x800BBF94u: goto label_800BBF94;
    case 0x800BBF98u: goto label_800BBF98;
    case 0x800BBF9Cu: goto label_800BBF9C;
    case 0x800BBFA0u: goto label_800BBFA0;
    case 0x800BBFA4u: goto label_800BBFA4;
    case 0x800BBFA8u: goto label_800BBFA8;
    case 0x800BBFACu: goto label_800BBFAC;
    case 0x800BBFB0u: goto label_800BBFB0;
    case 0x800BBFB4u: goto label_800BBFB4;
    case 0x800BBFB8u: goto label_800BBFB8;
    case 0x800BBFBCu: goto label_800BBFBC;
    case 0x800BBFC0u: goto label_800BBFC0;
    case 0x800BBFC4u: goto label_800BBFC4;
    case 0x800BBFC8u: goto label_800BBFC8;
    case 0x800BBFCCu: goto label_800BBFCC;
    case 0x800BBFD0u: goto label_800BBFD0;
    case 0x800BBFD4u: goto label_800BBFD4;
    case 0x800BBFD8u: goto label_800BBFD8;
    case 0x800BBFDCu: goto label_800BBFDC;
    case 0x800BBFE0u: goto label_800BBFE0;
    case 0x800BBFE4u: goto label_800BBFE4;
    case 0x800BBFE8u: goto label_800BBFE8;
    case 0x800BBFECu: goto label_800BBFEC;
    case 0x800BBFF0u: goto label_800BBFF0;
    case 0x800BBFF4u: goto label_800BBFF4;
    case 0x800BBFF8u: goto label_800BBFF8;
    case 0x800BBFFCu: goto label_800BBFFC;
    case 0x800BC000u: goto label_800BC000;
    case 0x800BC004u: goto label_800BC004;
    case 0x800BC008u: goto label_800BC008;
    case 0x800BC00Cu: goto label_800BC00C;
    case 0x800BC010u: goto label_800BC010;
    case 0x800BC014u: goto label_800BC014;
    case 0x800BC018u: goto label_800BC018;
    case 0x800BC01Cu: goto label_800BC01C;
    case 0x800BC020u: goto label_800BC020;
    case 0x800BC024u: goto label_800BC024;
    case 0x800BC028u: goto label_800BC028;
    case 0x800BC02Cu: goto label_800BC02C;
    case 0x800BC030u: goto label_800BC030;
    case 0x800BC034u: goto label_800BC034;
    case 0x800BC038u: goto label_800BC038;
    case 0x800BC03Cu: goto label_800BC03C;
    case 0x800BC040u: goto label_800BC040;
    case 0x800BC044u: goto label_800BC044;
    case 0x800BC048u: goto label_800BC048;
    case 0x800BC04Cu: goto label_800BC04C;
    case 0x800BC050u: goto label_800BC050;
    case 0x800BC054u: goto label_800BC054;
    case 0x800BC058u: goto label_800BC058;
    case 0x800BC05Cu: goto label_800BC05C;
    case 0x800BC060u: goto label_800BC060;
    case 0x800BC064u: goto label_800BC064;
    case 0x800BC068u: goto label_800BC068;
    case 0x800BC06Cu: goto label_800BC06C;
    case 0x800BC070u: goto label_800BC070;
    case 0x800BC074u: goto label_800BC074;
    case 0x800BC078u: goto label_800BC078;
    case 0x800BC07Cu: goto label_800BC07C;
    case 0x800BC080u: goto label_800BC080;
    case 0x800BC084u: goto label_800BC084;
    case 0x800BC088u: goto label_800BC088;
    case 0x800BC08Cu: goto label_800BC08C;
    case 0x800BC090u: goto label_800BC090;
    case 0x800BC094u: goto label_800BC094;
    case 0x800BC098u: goto label_800BC098;
    case 0x800BC09Cu: goto label_800BC09C;
    case 0x800BC0A0u: goto label_800BC0A0;
    case 0x800BC0A4u: goto label_800BC0A4;
    case 0x800BC0A8u: goto label_800BC0A8;
    case 0x800BC0ACu: goto label_800BC0AC;
    case 0x800BC0B0u: goto label_800BC0B0;
    case 0x800BC0B4u: goto label_800BC0B4;
    case 0x800BC0B8u: goto label_800BC0B8;
    case 0x800BC0BCu: goto label_800BC0BC;
    case 0x800BC0C0u: goto label_800BC0C0;
    case 0x800BC0C4u: goto label_800BC0C4;
    case 0x800BC0C8u: goto label_800BC0C8;
    case 0x800BC0CCu: goto label_800BC0CC;
    case 0x800BC0D0u: goto label_800BC0D0;
    case 0x800BC0D4u: goto label_800BC0D4;
    case 0x800BC0D8u: goto label_800BC0D8;
    case 0x800BC0DCu: goto label_800BC0DC;
    case 0x800BC0E0u: goto label_800BC0E0;
    case 0x800BC0E4u: goto label_800BC0E4;
    case 0x800BC0E8u: goto label_800BC0E8;
    case 0x800BC0ECu: goto label_800BC0EC;
    case 0x800BC0F0u: goto label_800BC0F0;
    case 0x800BC0F4u: goto label_800BC0F4;
    case 0x800BC0F8u: goto label_800BC0F8;
    case 0x800BC0FCu: goto label_800BC0FC;
    case 0x800BC100u: goto label_800BC100;
    case 0x800BC104u: goto label_800BC104;
    case 0x800BC108u: goto label_800BC108;
    case 0x800BC10Cu: goto label_800BC10C;
    case 0x800BC110u: goto label_800BC110;
    case 0x800BC114u: goto label_800BC114;
    case 0x800BC118u: goto label_800BC118;
    case 0x800BC11Cu: goto label_800BC11C;
    case 0x800BC120u: goto label_800BC120;
    case 0x800BC124u: goto label_800BC124;
    case 0x800BC128u: goto label_800BC128;
    case 0x800BC12Cu: goto label_800BC12C;
    case 0x800BC130u: goto label_800BC130;
    case 0x800BC134u: goto label_800BC134;
    case 0x800BC138u: goto label_800BC138;
    case 0x800BC13Cu: goto label_800BC13C;
    case 0x800BC140u: goto label_800BC140;
    case 0x800BC144u: goto label_800BC144;
    case 0x800BC148u: goto label_800BC148;
    case 0x800BC14Cu: goto label_800BC14C;
    case 0x800BC150u: goto label_800BC150;
    case 0x800BC154u: goto label_800BC154;
    case 0x800BC158u: goto label_800BC158;
    case 0x800BC15Cu: goto label_800BC15C;
    case 0x800BC160u: goto label_800BC160;
    case 0x800BC164u: goto label_800BC164;
    case 0x800BC168u: goto label_800BC168;
    case 0x800BC16Cu: goto label_800BC16C;
    case 0x800BC170u: goto label_800BC170;
    case 0x800BC174u: goto label_800BC174;
    case 0x800BC178u: goto label_800BC178;
    case 0x800BC17Cu: goto label_800BC17C;
    case 0x800BC180u: goto label_800BC180;
    case 0x800BC184u: goto label_800BC184;
    case 0x800BC188u: goto label_800BC188;
    case 0x800BC18Cu: goto label_800BC18C;
    case 0x800BC190u: goto label_800BC190;
    case 0x800BC194u: goto label_800BC194;
    case 0x800BC198u: goto label_800BC198;
    case 0x800BC19Cu: goto label_800BC19C;
    case 0x800BC1A0u: goto label_800BC1A0;
    case 0x800BC1A4u: goto label_800BC1A4;
    case 0x800BC1A8u: goto label_800BC1A8;
    case 0x800BC1ACu: goto label_800BC1AC;
    case 0x800BC1B0u: goto label_800BC1B0;
    case 0x800BC1B4u: goto label_800BC1B4;
    case 0x800BC1B8u: goto label_800BC1B8;
    case 0x800BC1BCu: goto label_800BC1BC;
    case 0x800BC1C0u: goto label_800BC1C0;
    case 0x800BC1C4u: goto label_800BC1C4;
    case 0x800BC1C8u: goto label_800BC1C8;
    case 0x800BC1CCu: goto label_800BC1CC;
    case 0x800BC1D0u: goto label_800BC1D0;
    case 0x800BC1D4u: goto label_800BC1D4;
    case 0x800BC1D8u: goto label_800BC1D8;
    case 0x800BC1DCu: goto label_800BC1DC;
    case 0x800BC1E0u: goto label_800BC1E0;
    case 0x800BC1E4u: goto label_800BC1E4;
    case 0x800BC1E8u: goto label_800BC1E8;
    case 0x800BC1ECu: goto label_800BC1EC;
    case 0x800BC1F0u: goto label_800BC1F0;
    case 0x800BC1F4u: goto label_800BC1F4;
    case 0x800BC1F8u: goto label_800BC1F8;
    case 0x800BC1FCu: goto label_800BC1FC;
    case 0x800BC200u: goto label_800BC200;
    case 0x800BC204u: goto label_800BC204;
    case 0x800BC208u: goto label_800BC208;
    case 0x800BC20Cu: goto label_800BC20C;
    case 0x800BC210u: goto label_800BC210;
    case 0x800BC214u: goto label_800BC214;
    case 0x800BC218u: goto label_800BC218;
    case 0x800BC21Cu: goto label_800BC21C;
    case 0x800BC220u: goto label_800BC220;
    case 0x800BC224u: goto label_800BC224;
    case 0x800BC228u: goto label_800BC228;
    case 0x800BC22Cu: goto label_800BC22C;
    case 0x800BC230u: goto label_800BC230;
    case 0x800BC234u: goto label_800BC234;
    case 0x800BC238u: goto label_800BC238;
    case 0x800BC23Cu: goto label_800BC23C;
    case 0x800BC240u: goto label_800BC240;
    case 0x800BC244u: goto label_800BC244;
    case 0x800BC248u: goto label_800BC248;
    case 0x800BC24Cu: goto label_800BC24C;
    case 0x800BC250u: goto label_800BC250;
    case 0x800BC254u: goto label_800BC254;
    case 0x800BC258u: goto label_800BC258;
    case 0x800BC25Cu: goto label_800BC25C;
    case 0x800BC260u: goto label_800BC260;
    case 0x800BC264u: goto label_800BC264;
    case 0x800BC268u: goto label_800BC268;
    case 0x800BC26Cu: goto label_800BC26C;
    case 0x800BC270u: goto label_800BC270;
    case 0x800BC274u: goto label_800BC274;
    case 0x800BC278u: goto label_800BC278;
    case 0x800BC27Cu: goto label_800BC27C;
    case 0x800BC280u: goto label_800BC280;
    case 0x800BC284u: goto label_800BC284;
    case 0x800BC288u: goto label_800BC288;
    case 0x800BC28Cu: goto label_800BC28C;
    case 0x800BC290u: goto label_800BC290;
    case 0x800BC294u: goto label_800BC294;
    case 0x800BC298u: goto label_800BC298;
    case 0x800BC29Cu: goto label_800BC29C;
    case 0x800BC2A0u: goto label_800BC2A0;
    case 0x800BC2A4u: goto label_800BC2A4;
    case 0x800BC2A8u: goto label_800BC2A8;
    case 0x800BC2ACu: goto label_800BC2AC;
    case 0x800BC2B0u: goto label_800BC2B0;
    case 0x800BC2B4u: goto label_800BC2B4;
    case 0x800BC2B8u: goto label_800BC2B8;
    case 0x800BC2BCu: goto label_800BC2BC;
    case 0x800BC2C0u: goto label_800BC2C0;
    case 0x800BC2C4u: goto label_800BC2C4;
    case 0x800BC2C8u: goto label_800BC2C8;
    case 0x800BC2CCu: goto label_800BC2CC;
    case 0x800BC2D0u: goto label_800BC2D0;
    case 0x800BC2D4u: goto label_800BC2D4;
    case 0x800BC2D8u: goto label_800BC2D8;
    case 0x800BC2DCu: goto label_800BC2DC;
    case 0x800BC2E0u: goto label_800BC2E0;
    case 0x800BC2E4u: goto label_800BC2E4;
    case 0x800BC2E8u: goto label_800BC2E8;
    case 0x800BC2ECu: goto label_800BC2EC;
    case 0x800BC2F0u: goto label_800BC2F0;
    case 0x800BC2F4u: goto label_800BC2F4;
    case 0x800BC2F8u: goto label_800BC2F8;
    case 0x800BC2FCu: goto label_800BC2FC;
    case 0x800BC300u: goto label_800BC300;
    case 0x800BC304u: goto label_800BC304;
    case 0x800BC308u: goto label_800BC308;
    case 0x800BC30Cu: goto label_800BC30C;
    case 0x800BC310u: goto label_800BC310;
    case 0x800BC314u: goto label_800BC314;
    case 0x800BC318u: goto label_800BC318;
    case 0x800BC31Cu: goto label_800BC31C;
    case 0x800BC320u: goto label_800BC320;
    case 0x800BC324u: goto label_800BC324;
    case 0x800BC328u: goto label_800BC328;
    case 0x800BC32Cu: goto label_800BC32C;
    case 0x800BC330u: goto label_800BC330;
    case 0x800BC334u: goto label_800BC334;
    case 0x800BC338u: goto label_800BC338;
    case 0x800BC33Cu: goto label_800BC33C;
    case 0x800BC340u: goto label_800BC340;
    case 0x800BC344u: goto label_800BC344;
    case 0x800BC348u: goto label_800BC348;
    case 0x800BC34Cu: goto label_800BC34C;
    case 0x800BC350u: goto label_800BC350;
    case 0x800BC354u: goto label_800BC354;
    case 0x800BC358u: goto label_800BC358;
    case 0x800BC35Cu: goto label_800BC35C;
    case 0x800BC360u: goto label_800BC360;
    case 0x800BC364u: goto label_800BC364;
    case 0x800BC368u: goto label_800BC368;
    case 0x800BC36Cu: goto label_800BC36C;
    case 0x800BC370u: goto label_800BC370;
    case 0x800BC374u: goto label_800BC374;
    case 0x800BC378u: goto label_800BC378;
    case 0x800BC37Cu: goto label_800BC37C;
    case 0x800BC380u: goto label_800BC380;
    case 0x800BC384u: goto label_800BC384;
    case 0x800BC388u: goto label_800BC388;
    case 0x800BC38Cu: goto label_800BC38C;
    case 0x800BC390u: goto label_800BC390;
    case 0x800BC394u: goto label_800BC394;
    case 0x800BC398u: goto label_800BC398;
    case 0x800BC39Cu: goto label_800BC39C;
    case 0x800BC3A0u: goto label_800BC3A0;
    case 0x800BC3A4u: goto label_800BC3A4;
    case 0x800BC3A8u: goto label_800BC3A8;
    case 0x800BC3ACu: goto label_800BC3AC;
    case 0x800BC3B0u: goto label_800BC3B0;
    case 0x800BC3B4u: goto label_800BC3B4;
    case 0x800BC3B8u: goto label_800BC3B8;
    case 0x800BC3BCu: goto label_800BC3BC;
    case 0x800BC3C0u: goto label_800BC3C0;
    case 0x800BC3C4u: goto label_800BC3C4;
    case 0x800BC3C8u: goto label_800BC3C8;
    case 0x800BC3CCu: goto label_800BC3CC;
    case 0x800BC3D0u: goto label_800BC3D0;
    case 0x800BC3D4u: goto label_800BC3D4;
    case 0x800BC3D8u: goto label_800BC3D8;
    case 0x800BC3DCu: goto label_800BC3DC;
    case 0x800BC3E0u: goto label_800BC3E0;
    case 0x800BC3E4u: goto label_800BC3E4;
    case 0x800BC3E8u: goto label_800BC3E8;
    case 0x800BC3ECu: goto label_800BC3EC;
    case 0x800BC3F0u: goto label_800BC3F0;
    case 0x800BC3F4u: goto label_800BC3F4;
    case 0x800BC3F8u: goto label_800BC3F8;
    case 0x800BC3FCu: goto label_800BC3FC;
    case 0x800BC400u: goto label_800BC400;
    case 0x800BC404u: goto label_800BC404;
    case 0x800BC408u: goto label_800BC408;
    case 0x800BC40Cu: goto label_800BC40C;
    case 0x800BC410u: goto label_800BC410;
    case 0x800BC414u: goto label_800BC414;
    case 0x800BC418u: goto label_800BC418;
    case 0x800BC41Cu: goto label_800BC41C;
    case 0x800BC420u: goto label_800BC420;
    case 0x800BC424u: goto label_800BC424;
    case 0x800BC428u: goto label_800BC428;
    case 0x800BC42Cu: goto label_800BC42C;
    case 0x800BC430u: goto label_800BC430;
    case 0x800BC434u: goto label_800BC434;
    case 0x800BC438u: goto label_800BC438;
    case 0x800BC43Cu: goto label_800BC43C;
    case 0x800BC440u: goto label_800BC440;
    case 0x800BC444u: goto label_800BC444;
    case 0x800BC448u: goto label_800BC448;
    case 0x800BC44Cu: goto label_800BC44C;
    case 0x800BC450u: goto label_800BC450;
    case 0x800BC454u: goto label_800BC454;
    case 0x800BC458u: goto label_800BC458;
    case 0x800BC45Cu: goto label_800BC45C;
    case 0x800BC460u: goto label_800BC460;
    case 0x800BC464u: goto label_800BC464;
    case 0x800BC468u: goto label_800BC468;
    case 0x800BC46Cu: goto label_800BC46C;
    case 0x800BC470u: goto label_800BC470;
    case 0x800BC474u: goto label_800BC474;
    case 0x800BC478u: goto label_800BC478;
    case 0x800BC47Cu: goto label_800BC47C;
    case 0x800BC480u: goto label_800BC480;
    case 0x800BC484u: goto label_800BC484;
    case 0x800BC488u: goto label_800BC488;
    case 0x800BC48Cu: goto label_800BC48C;
    case 0x800BC490u: goto label_800BC490;
    case 0x800BC494u: goto label_800BC494;
    case 0x800BC498u: goto label_800BC498;
    case 0x800BC49Cu: goto label_800BC49C;
    case 0x800BC4A0u: goto label_800BC4A0;
    case 0x800BC4A4u: goto label_800BC4A4;
    case 0x800BC4A8u: goto label_800BC4A8;
    case 0x800BC4ACu: goto label_800BC4AC;
    case 0x800BC4B0u: goto label_800BC4B0;
    case 0x800BC4B4u: goto label_800BC4B4;
    case 0x800BC4B8u: goto label_800BC4B8;
    case 0x800BC4BCu: goto label_800BC4BC;
    case 0x800BC4C0u: goto label_800BC4C0;
    case 0x800BC4C4u: goto label_800BC4C4;
    case 0x800BC4C8u: goto label_800BC4C8;
    case 0x800BC4CCu: goto label_800BC4CC;
    case 0x800BC4D0u: goto label_800BC4D0;
    case 0x800BC4D4u: goto label_800BC4D4;
    case 0x800BC4D8u: goto label_800BC4D8;
    case 0x800BC4DCu: goto label_800BC4DC;
    case 0x800BC4E0u: goto label_800BC4E0;
    case 0x800BC4E4u: goto label_800BC4E4;
    case 0x800BC4E8u: goto label_800BC4E8;
    case 0x800BC4ECu: goto label_800BC4EC;
    case 0x800BC4F0u: goto label_800BC4F0;
    case 0x800BC4F4u: goto label_800BC4F4;
    case 0x800BC4F8u: goto label_800BC4F8;
    case 0x800BC4FCu: goto label_800BC4FC;
    case 0x800BC500u: goto label_800BC500;
    case 0x800BC504u: goto label_800BC504;
    case 0x800BC508u: goto label_800BC508;
    case 0x800BC50Cu: goto label_800BC50C;
    case 0x800BC510u: goto label_800BC510;
    case 0x800BC514u: goto label_800BC514;
    case 0x800BC518u: goto label_800BC518;
    case 0x800BC51Cu: goto label_800BC51C;
    case 0x800BC520u: goto label_800BC520;
    case 0x800BC524u: goto label_800BC524;
    case 0x800BC528u: goto label_800BC528;
    case 0x800BC52Cu: goto label_800BC52C;
    case 0x800BC530u: goto label_800BC530;
    case 0x800BC534u: goto label_800BC534;
    case 0x800BC538u: goto label_800BC538;
    case 0x800BC53Cu: goto label_800BC53C;
    case 0x800BC540u: goto label_800BC540;
    case 0x800BC544u: goto label_800BC544;
    case 0x800BC548u: goto label_800BC548;
    case 0x800BC54Cu: goto label_800BC54C;
    case 0x800BC550u: goto label_800BC550;
    case 0x800BC554u: goto label_800BC554;
    case 0x800BC558u: goto label_800BC558;
    case 0x800BC55Cu: goto label_800BC55C;
    case 0x800BC560u: goto label_800BC560;
    case 0x800BC564u: goto label_800BC564;
    case 0x800BC568u: goto label_800BC568;
    case 0x800BC56Cu: goto label_800BC56C;
    case 0x800BC570u: goto label_800BC570;
    case 0x800BC574u: goto label_800BC574;
    case 0x800BC578u: goto label_800BC578;
    case 0x800BC57Cu: goto label_800BC57C;
    case 0x800BC580u: goto label_800BC580;
    case 0x800BC584u: goto label_800BC584;
    case 0x800BC588u: goto label_800BC588;
    case 0x800BC58Cu: goto label_800BC58C;
    case 0x800BC590u: goto label_800BC590;
    case 0x800BC594u: goto label_800BC594;
    case 0x800BC598u: goto label_800BC598;
    case 0x800BC59Cu: goto label_800BC59C;
    case 0x800BC5A0u: goto label_800BC5A0;
    case 0x800BC5A4u: goto label_800BC5A4;
    case 0x800BC5A8u: goto label_800BC5A8;
    case 0x800BC5ACu: goto label_800BC5AC;
    case 0x800BC5B0u: goto label_800BC5B0;
    case 0x800BC5B4u: goto label_800BC5B4;
    case 0x800BC5B8u: goto label_800BC5B8;
    case 0x800BC5BCu: goto label_800BC5BC;
    case 0x800BC5C0u: goto label_800BC5C0;
    case 0x800BC5C4u: goto label_800BC5C4;
    case 0x800BC5C8u: goto label_800BC5C8;
    case 0x800BC5CCu: goto label_800BC5CC;
    case 0x800BC5D0u: goto label_800BC5D0;
    case 0x800BC5D4u: goto label_800BC5D4;
    case 0x800BC5D8u: goto label_800BC5D8;
    case 0x800BC5DCu: goto label_800BC5DC;
    case 0x800BC5E0u: goto label_800BC5E0;
    case 0x800BC5E4u: goto label_800BC5E4;
    case 0x800BC5E8u: goto label_800BC5E8;
    case 0x800BC5ECu: goto label_800BC5EC;
    case 0x800BC5F0u: goto label_800BC5F0;
    case 0x800BC5F4u: goto label_800BC5F4;
    case 0x800BC5F8u: goto label_800BC5F8;
    case 0x800BC5FCu: goto label_800BC5FC;
    case 0x800BC600u: goto label_800BC600;
    case 0x800BC604u: goto label_800BC604;
    case 0x800BC608u: goto label_800BC608;
    case 0x800BC60Cu: goto label_800BC60C;
    case 0x800BC610u: goto label_800BC610;
    case 0x800BC614u: goto label_800BC614;
    case 0x800BC618u: goto label_800BC618;
    case 0x800BC61Cu: goto label_800BC61C;
    case 0x800BC620u: goto label_800BC620;
    case 0x800BC624u: goto label_800BC624;
    case 0x800BC628u: goto label_800BC628;
    case 0x800BC62Cu: goto label_800BC62C;
    case 0x800BC630u: goto label_800BC630;
    case 0x800BC634u: goto label_800BC634;
    case 0x800BC638u: goto label_800BC638;
    case 0x800BC63Cu: goto label_800BC63C;
    case 0x800BC640u: goto label_800BC640;
    case 0x800BC644u: goto label_800BC644;
    case 0x800BC648u: goto label_800BC648;
    case 0x800BC64Cu: goto label_800BC64C;
    case 0x800BC650u: goto label_800BC650;
    case 0x800BC654u: goto label_800BC654;
    case 0x800BC658u: goto label_800BC658;
    case 0x800BC65Cu: goto label_800BC65C;
    case 0x800BC660u: goto label_800BC660;
    case 0x800BC664u: goto label_800BC664;
    case 0x800BC668u: goto label_800BC668;
    case 0x800BC66Cu: goto label_800BC66C;
    case 0x800BC670u: goto label_800BC670;
    case 0x800BC674u: goto label_800BC674;
    case 0x800BC678u: goto label_800BC678;
    case 0x800BC67Cu: goto label_800BC67C;
    case 0x800BC680u: goto label_800BC680;
    case 0x800BC684u: goto label_800BC684;
    case 0x800BC688u: goto label_800BC688;
    case 0x800BC68Cu: goto label_800BC68C;
    case 0x800BC690u: goto label_800BC690;
    case 0x800BC694u: goto label_800BC694;
    case 0x800BC698u: goto label_800BC698;
    case 0x800BC69Cu: goto label_800BC69C;
    case 0x800BC6A0u: goto label_800BC6A0;
    case 0x800BC6A4u: goto label_800BC6A4;
    case 0x800BC6A8u: goto label_800BC6A8;
    case 0x800BC6ACu: goto label_800BC6AC;
    case 0x800BC6B0u: goto label_800BC6B0;
    case 0x800BC6B4u: goto label_800BC6B4;
    case 0x800BC6B8u: goto label_800BC6B8;
    case 0x800BC6BCu: goto label_800BC6BC;
    case 0x800BC6C0u: goto label_800BC6C0;
    case 0x800BC6C4u: goto label_800BC6C4;
    case 0x800BC6C8u: goto label_800BC6C8;
    case 0x800BC6CCu: goto label_800BC6CC;
    case 0x800BC6D0u: goto label_800BC6D0;
    case 0x800BC6D4u: goto label_800BC6D4;
    case 0x800BC6D8u: goto label_800BC6D8;
    case 0x800BC6DCu: goto label_800BC6DC;
    case 0x800BC6E0u: goto label_800BC6E0;
    case 0x800BC6E4u: goto label_800BC6E4;
    case 0x800BC6E8u: goto label_800BC6E8;
    case 0x800BC6ECu: goto label_800BC6EC;
    case 0x800BC6F0u: goto label_800BC6F0;
    case 0x800BC6F4u: goto label_800BC6F4;
    case 0x800BC6F8u: goto label_800BC6F8;
    case 0x800BC6FCu: goto label_800BC6FC;
    case 0x800BC700u: goto label_800BC700;
    case 0x800BC704u: goto label_800BC704;
    case 0x800BC708u: goto label_800BC708;
    case 0x800BC70Cu: goto label_800BC70C;
    case 0x800BC710u: goto label_800BC710;
    case 0x800BC714u: goto label_800BC714;
    case 0x800BC718u: goto label_800BC718;
    case 0x800BC71Cu: goto label_800BC71C;
    case 0x800BC720u: goto label_800BC720;
    case 0x800BC724u: goto label_800BC724;
    case 0x800BC728u: goto label_800BC728;
    case 0x800BC72Cu: goto label_800BC72C;
    case 0x800BC730u: goto label_800BC730;
    case 0x800BC734u: goto label_800BC734;
    case 0x800BC738u: goto label_800BC738;
    case 0x800BC73Cu: goto label_800BC73C;
    case 0x800BC740u: goto label_800BC740;
    case 0x800BC744u: goto label_800BC744;
    case 0x800BC748u: goto label_800BC748;
    case 0x800BC74Cu: goto label_800BC74C;
    case 0x800BC750u: goto label_800BC750;
    case 0x800BC754u: goto label_800BC754;
    case 0x800BC758u: goto label_800BC758;
    case 0x800BC75Cu: goto label_800BC75C;
    case 0x800BC760u: goto label_800BC760;
    case 0x800BC764u: goto label_800BC764;
    case 0x800BC768u: goto label_800BC768;
    case 0x800BC76Cu: goto label_800BC76C;
    case 0x800BC770u: goto label_800BC770;
    case 0x800BC774u: goto label_800BC774;
    case 0x800BC778u: goto label_800BC778;
    case 0x800BC77Cu: goto label_800BC77C;
    case 0x800BC780u: goto label_800BC780;
    case 0x800BC784u: goto label_800BC784;
    case 0x800BC788u: goto label_800BC788;
    case 0x800BC78Cu: goto label_800BC78C;
    case 0x800BC790u: goto label_800BC790;
    case 0x800BC794u: goto label_800BC794;
    case 0x800BC798u: goto label_800BC798;
    case 0x800BC79Cu: goto label_800BC79C;
    case 0x800BC7A0u: goto label_800BC7A0;
    case 0x800BC7A4u: goto label_800BC7A4;
    case 0x800BC7A8u: goto label_800BC7A8;
    case 0x800BC7ACu: goto label_800BC7AC;
    case 0x800BC7B0u: goto label_800BC7B0;
    case 0x800BC7B4u: goto label_800BC7B4;
    case 0x800BC7B8u: goto label_800BC7B8;
    case 0x800BC7BCu: goto label_800BC7BC;
    case 0x800BC7C0u: goto label_800BC7C0;
    case 0x800BC7C4u: goto label_800BC7C4;
    case 0x800BC7C8u: goto label_800BC7C8;
    case 0x800BC7CCu: goto label_800BC7CC;
    case 0x800BC7D0u: goto label_800BC7D0;
    case 0x800BC7D4u: goto label_800BC7D4;
    case 0x800BC7D8u: goto label_800BC7D8;
    case 0x800BC7DCu: goto label_800BC7DC;
    case 0x800BC7E0u: goto label_800BC7E0;
    case 0x800BC7E4u: goto label_800BC7E4;
    case 0x800BC7E8u: goto label_800BC7E8;
    case 0x800BC7ECu: goto label_800BC7EC;
    case 0x800BC7F0u: goto label_800BC7F0;
    case 0x800BC7F4u: goto label_800BC7F4;
    case 0x800BC7F8u: goto label_800BC7F8;
    case 0x800BC7FCu: goto label_800BC7FC;
    case 0x800BC800u: goto label_800BC800;
    case 0x800BC804u: goto label_800BC804;
    case 0x800BC808u: goto label_800BC808;
    case 0x800BC80Cu: goto label_800BC80C;
    case 0x800BC810u: goto label_800BC810;
    case 0x800BC814u: goto label_800BC814;
    case 0x800BC818u: goto label_800BC818;
    case 0x800BC81Cu: goto label_800BC81C;
    case 0x800BC820u: goto label_800BC820;
    case 0x800BC824u: goto label_800BC824;
    case 0x800BC828u: goto label_800BC828;
    case 0x800BC82Cu: goto label_800BC82C;
    case 0x800BC830u: goto label_800BC830;
    case 0x800BC834u: goto label_800BC834;
    case 0x800BC838u: goto label_800BC838;
    case 0x800BC83Cu: goto label_800BC83C;
    case 0x800BC840u: goto label_800BC840;
    case 0x800BC844u: goto label_800BC844;
    case 0x800BC848u: goto label_800BC848;
    case 0x800BC84Cu: goto label_800BC84C;
    case 0x800BC850u: goto label_800BC850;
    case 0x800BC854u: goto label_800BC854;
    case 0x800BC858u: goto label_800BC858;
    case 0x800BC85Cu: goto label_800BC85C;
    case 0x800BC860u: goto label_800BC860;
    case 0x800BC864u: goto label_800BC864;
    case 0x800BC868u: goto label_800BC868;
    case 0x800BC86Cu: goto label_800BC86C;
    case 0x800BC870u: goto label_800BC870;
    case 0x800BC874u: goto label_800BC874;
    case 0x800BC878u: goto label_800BC878;
    case 0x800BC87Cu: goto label_800BC87C;
    case 0x800BC880u: goto label_800BC880;
    case 0x800BC884u: goto label_800BC884;
    case 0x800BC888u: goto label_800BC888;
    case 0x800BC88Cu: goto label_800BC88C;
    case 0x800BC890u: goto label_800BC890;
    case 0x800BC894u: goto label_800BC894;
    case 0x800BC898u: goto label_800BC898;
    case 0x800BC89Cu: goto label_800BC89C;
    case 0x800BC8A0u: goto label_800BC8A0;
    case 0x800BC8A4u: goto label_800BC8A4;
    case 0x800BC8A8u: goto label_800BC8A8;
    case 0x800BC8ACu: goto label_800BC8AC;
    case 0x800BC8B0u: goto label_800BC8B0;
    case 0x800BC8B4u: goto label_800BC8B4;
    case 0x800BC8B8u: goto label_800BC8B8;
    case 0x800BC8BCu: goto label_800BC8BC;
    case 0x800BC8C0u: goto label_800BC8C0;
    case 0x800BC8C4u: goto label_800BC8C4;
    case 0x800BC8C8u: goto label_800BC8C8;
    case 0x800BC8CCu: goto label_800BC8CC;
    case 0x800BC8D0u: goto label_800BC8D0;
    case 0x800BC8D4u: goto label_800BC8D4;
    case 0x800BC8D8u: goto label_800BC8D8;
    case 0x800BC8DCu: goto label_800BC8DC;
    case 0x800BC8E0u: goto label_800BC8E0;
    case 0x800BC8E4u: goto label_800BC8E4;
    case 0x800BC8E8u: goto label_800BC8E8;
    case 0x800BC8ECu: goto label_800BC8EC;
    case 0x800BC8F0u: goto label_800BC8F0;
    case 0x800BC8F4u: goto label_800BC8F4;
    case 0x800BC8F8u: goto label_800BC8F8;
    case 0x800BC8FCu: goto label_800BC8FC;
    case 0x800BC900u: goto label_800BC900;
    case 0x800BC904u: goto label_800BC904;
    case 0x800BC908u: goto label_800BC908;
    case 0x800BC90Cu: goto label_800BC90C;
    case 0x800BC910u: goto label_800BC910;
    case 0x800BC914u: goto label_800BC914;
    case 0x800BC918u: goto label_800BC918;
    case 0x800BC91Cu: goto label_800BC91C;
    case 0x800BC920u: goto label_800BC920;
    case 0x800BC924u: goto label_800BC924;
    case 0x800BC928u: goto label_800BC928;
    case 0x800BC92Cu: goto label_800BC92C;
    case 0x800BC930u: goto label_800BC930;
    case 0x800BC934u: goto label_800BC934;
    case 0x800BC938u: goto label_800BC938;
    case 0x800BC93Cu: goto label_800BC93C;
    case 0x800BC940u: goto label_800BC940;
    case 0x800BC944u: goto label_800BC944;
    case 0x800BC948u: goto label_800BC948;
    case 0x800BC94Cu: goto label_800BC94C;
    case 0x800BC950u: goto label_800BC950;
    case 0x800BC954u: goto label_800BC954;
    case 0x800BC958u: goto label_800BC958;
    case 0x800BC95Cu: goto label_800BC95C;
    case 0x800BC960u: goto label_800BC960;
    case 0x800BC964u: goto label_800BC964;
    case 0x800BC968u: goto label_800BC968;
    case 0x800BC96Cu: goto label_800BC96C;
    case 0x800BC970u: goto label_800BC970;
    case 0x800BC974u: goto label_800BC974;
    case 0x800BC978u: goto label_800BC978;
    case 0x800BC97Cu: goto label_800BC97C;
    case 0x800BC980u: goto label_800BC980;
    case 0x800BC984u: goto label_800BC984;
    case 0x800BC988u: goto label_800BC988;
    case 0x800BC98Cu: goto label_800BC98C;
    case 0x800BC990u: goto label_800BC990;
    case 0x800BC994u: goto label_800BC994;
    case 0x800BC998u: goto label_800BC998;
    case 0x800BC99Cu: goto label_800BC99C;
    case 0x800BC9A0u: goto label_800BC9A0;
    case 0x800BC9A4u: goto label_800BC9A4;
    case 0x800BC9A8u: goto label_800BC9A8;
    case 0x800BC9ACu: goto label_800BC9AC;
    case 0x800BC9B0u: goto label_800BC9B0;
    case 0x800BC9B4u: goto label_800BC9B4;
    case 0x800BC9B8u: goto label_800BC9B8;
    case 0x800BC9BCu: goto label_800BC9BC;
    case 0x800BC9C0u: goto label_800BC9C0;
    case 0x800BC9C4u: goto label_800BC9C4;
    case 0x800BC9C8u: goto label_800BC9C8;
    case 0x800BC9CCu: goto label_800BC9CC;
    case 0x800BC9D0u: goto label_800BC9D0;
    case 0x800BC9D4u: goto label_800BC9D4;
    case 0x800BC9D8u: goto label_800BC9D8;
    case 0x800BC9DCu: goto label_800BC9DC;
    case 0x800BC9E0u: goto label_800BC9E0;
    case 0x800BC9E4u: goto label_800BC9E4;
    case 0x800BC9E8u: goto label_800BC9E8;
    case 0x800BC9ECu: goto label_800BC9EC;
    case 0x800BC9F0u: goto label_800BC9F0;
    case 0x800BC9F4u: goto label_800BC9F4;
    case 0x800BC9F8u: goto label_800BC9F8;
    case 0x800BC9FCu: goto label_800BC9FC;
    case 0x800BCA00u: goto label_800BCA00;
    case 0x800BCA04u: goto label_800BCA04;
    case 0x800BCA08u: goto label_800BCA08;
    case 0x800BCA0Cu: goto label_800BCA0C;
    case 0x800BCA10u: goto label_800BCA10;
    case 0x800BCA14u: goto label_800BCA14;
    case 0x800BCA18u: goto label_800BCA18;
    case 0x800BCA1Cu: goto label_800BCA1C;
    case 0x800BCA20u: goto label_800BCA20;
    case 0x800BCA24u: goto label_800BCA24;
    case 0x800BCA28u: goto label_800BCA28;
    case 0x800BCA2Cu: goto label_800BCA2C;
    case 0x800BCA30u: goto label_800BCA30;
    case 0x800BCA34u: goto label_800BCA34;
    case 0x800BCA38u: goto label_800BCA38;
    case 0x800BCA3Cu: goto label_800BCA3C;
    case 0x800BCA40u: goto label_800BCA40;
    case 0x800BCA44u: goto label_800BCA44;
    case 0x800BCA48u: goto label_800BCA48;
    case 0x800BCA4Cu: goto label_800BCA4C;
    case 0x800BCA50u: goto label_800BCA50;
    case 0x800BCA54u: goto label_800BCA54;
    case 0x800BCA58u: goto label_800BCA58;
    case 0x800BCA5Cu: goto label_800BCA5C;
    case 0x800BCA60u: goto label_800BCA60;
    case 0x800BCA64u: goto label_800BCA64;
    case 0x800BCA68u: goto label_800BCA68;
    case 0x800BCA6Cu: goto label_800BCA6C;
    case 0x800BCA70u: goto label_800BCA70;
    case 0x800BCA74u: goto label_800BCA74;
    case 0x800BCA78u: goto label_800BCA78;
    case 0x800BCA7Cu: goto label_800BCA7C;
    case 0x800BCA80u: goto label_800BCA80;
    case 0x800BCA84u: goto label_800BCA84;
    case 0x800BCA88u: goto label_800BCA88;
    case 0x800BCA8Cu: goto label_800BCA8C;
    case 0x800BCA90u: goto label_800BCA90;
    case 0x800BCA94u: goto label_800BCA94;
    case 0x800BCA98u: goto label_800BCA98;
    case 0x800BCA9Cu: goto label_800BCA9C;
    case 0x800BCAA0u: goto label_800BCAA0;
    case 0x800BCAA4u: goto label_800BCAA4;
    case 0x800BCAA8u: goto label_800BCAA8;
    case 0x800BCAACu: goto label_800BCAAC;
    case 0x800BCAB0u: goto label_800BCAB0;
    case 0x800BCAB4u: goto label_800BCAB4;
    case 0x800BCAB8u: goto label_800BCAB8;
    case 0x800BCABCu: goto label_800BCABC;
    case 0x800BCAC0u: goto label_800BCAC0;
    case 0x800BCAC4u: goto label_800BCAC4;
    case 0x800BCAC8u: goto label_800BCAC8;
    case 0x800BCACCu: goto label_800BCACC;
    case 0x800BCAD0u: goto label_800BCAD0;
    case 0x800BCAD4u: goto label_800BCAD4;
    case 0x800BCAD8u: goto label_800BCAD8;
    case 0x800BCADCu: goto label_800BCADC;
    case 0x800BCAE0u: goto label_800BCAE0;
    case 0x800BCAE4u: goto label_800BCAE4;
    case 0x800BCAE8u: goto label_800BCAE8;
    case 0x800BCAECu: goto label_800BCAEC;
    case 0x800BCAF0u: goto label_800BCAF0;
    case 0x800BCAF4u: goto label_800BCAF4;
    case 0x800BCAF8u: goto label_800BCAF8;
    case 0x800BCAFCu: goto label_800BCAFC;
    case 0x800BCB00u: goto label_800BCB00;
    case 0x800BCB04u: goto label_800BCB04;
    case 0x800BCB08u: goto label_800BCB08;
    case 0x800BCB0Cu: goto label_800BCB0C;
    case 0x800BCB10u: goto label_800BCB10;
    case 0x800BCB14u: goto label_800BCB14;
    case 0x800BCB18u: goto label_800BCB18;
    case 0x800BCB1Cu: goto label_800BCB1C;
    case 0x800BCB20u: goto label_800BCB20;
    case 0x800BCB24u: goto label_800BCB24;
    case 0x800BCB28u: goto label_800BCB28;
    case 0x800BCB2Cu: goto label_800BCB2C;
    case 0x800BCB30u: goto label_800BCB30;
    case 0x800BCB34u: goto label_800BCB34;
    case 0x800BCB38u: goto label_800BCB38;
    case 0x800BCB3Cu: goto label_800BCB3C;
    case 0x800BCB40u: goto label_800BCB40;
    case 0x800BCB44u: goto label_800BCB44;
    case 0x800BCB48u: goto label_800BCB48;
    case 0x800BCB4Cu: goto label_800BCB4C;
    case 0x800BCB50u: goto label_800BCB50;
    case 0x800BCB54u: goto label_800BCB54;
    case 0x800BCB58u: goto label_800BCB58;
    case 0x800BCB5Cu: goto label_800BCB5C;
    case 0x800BCB60u: goto label_800BCB60;
    case 0x800BCB64u: goto label_800BCB64;
    case 0x800BCB68u: goto label_800BCB68;
    case 0x800BCB6Cu: goto label_800BCB6C;
    case 0x800BCB70u: goto label_800BCB70;
    case 0x800BCB74u: goto label_800BCB74;
    case 0x800BCB78u: goto label_800BCB78;
    case 0x800BCB7Cu: goto label_800BCB7C;
    case 0x800BCB80u: goto label_800BCB80;
    case 0x800BCB84u: goto label_800BCB84;
    case 0x800BCB88u: goto label_800BCB88;
    case 0x800BCB8Cu: goto label_800BCB8C;
    case 0x800BCB90u: goto label_800BCB90;
    case 0x800BCB94u: goto label_800BCB94;
    case 0x800BCB98u: goto label_800BCB98;
    case 0x800BCB9Cu: goto label_800BCB9C;
    case 0x800BCBA0u: goto label_800BCBA0;
    case 0x800BCBA4u: goto label_800BCBA4;
    case 0x800BCBA8u: goto label_800BCBA8;
    case 0x800BCBACu: goto label_800BCBAC;
    case 0x800BCBB0u: goto label_800BCBB0;
    case 0x800BCBB4u: goto label_800BCBB4;
    case 0x800BCBB8u: goto label_800BCBB8;
    case 0x800BCBBCu: goto label_800BCBBC;
    case 0x800BCBC0u: goto label_800BCBC0;
    case 0x800BCBC4u: goto label_800BCBC4;
    case 0x800BCBC8u: goto label_800BCBC8;
    case 0x800BCBCCu: goto label_800BCBCC;
    case 0x800BCBD0u: goto label_800BCBD0;
    case 0x800BCBD4u: goto label_800BCBD4;
    case 0x800BCBD8u: goto label_800BCBD8;
    case 0x800BCBDCu: goto label_800BCBDC;
    case 0x800BCBE0u: goto label_800BCBE0;
    case 0x800BCBE4u: goto label_800BCBE4;
    case 0x800BCBE8u: goto label_800BCBE8;
    case 0x800BCBECu: goto label_800BCBEC;
    case 0x800BCBF0u: goto label_800BCBF0;
    case 0x800BCBF4u: goto label_800BCBF4;
    case 0x800BCBF8u: goto label_800BCBF8;
    case 0x800BCBFCu: goto label_800BCBFC;
    case 0x800BCC00u: goto label_800BCC00;
    case 0x800BCC04u: goto label_800BCC04;
    case 0x800BCC08u: goto label_800BCC08;
    case 0x800BCC0Cu: goto label_800BCC0C;
    case 0x800BCC10u: goto label_800BCC10;
    case 0x800BCC14u: goto label_800BCC14;
    case 0x800BCC18u: goto label_800BCC18;
    case 0x800BCC1Cu: goto label_800BCC1C;
    case 0x800BCC20u: goto label_800BCC20;
    case 0x800BCC24u: goto label_800BCC24;
    case 0x800BCC28u: goto label_800BCC28;
    case 0x800BCC2Cu: goto label_800BCC2C;
    case 0x800BCC30u: goto label_800BCC30;
    case 0x800BCC34u: goto label_800BCC34;
    case 0x800BCC38u: goto label_800BCC38;
    case 0x800BCC3Cu: goto label_800BCC3C;
    case 0x800BCC40u: goto label_800BCC40;
    case 0x800BCC44u: goto label_800BCC44;
    case 0x800BCC48u: goto label_800BCC48;
    case 0x800BCC4Cu: goto label_800BCC4C;
    case 0x800BCC50u: goto label_800BCC50;
    case 0x800BCC54u: goto label_800BCC54;
    case 0x800BCC58u: goto label_800BCC58;
    case 0x800BCC5Cu: goto label_800BCC5C;
    case 0x800BCC60u: goto label_800BCC60;
    case 0x800BCC64u: goto label_800BCC64;
    case 0x800BCC68u: goto label_800BCC68;
    case 0x800BCC6Cu: goto label_800BCC6C;
    case 0x800BCC70u: goto label_800BCC70;
    case 0x800BCC74u: goto label_800BCC74;
    case 0x800BCC78u: goto label_800BCC78;
    case 0x800BCC7Cu: goto label_800BCC7C;
    case 0x800BCC80u: goto label_800BCC80;
    case 0x800BCC84u: goto label_800BCC84;
    case 0x800BCC88u: goto label_800BCC88;
    case 0x800BCC8Cu: goto label_800BCC8C;
    case 0x800BCC90u: goto label_800BCC90;
    case 0x800BCC94u: goto label_800BCC94;
    case 0x800BCC98u: goto label_800BCC98;
    case 0x800BCC9Cu: goto label_800BCC9C;
    case 0x800BCCA0u: goto label_800BCCA0;
    case 0x800BCCA4u: goto label_800BCCA4;
    case 0x800BCCA8u: goto label_800BCCA8;
    case 0x800BCCACu: goto label_800BCCAC;
    case 0x800BCCB0u: goto label_800BCCB0;
    case 0x800BCCB4u: goto label_800BCCB4;
    case 0x800BCCB8u: goto label_800BCCB8;
    case 0x800BCCBCu: goto label_800BCCBC;
    case 0x800BCCC0u: goto label_800BCCC0;
    case 0x800BCCC4u: goto label_800BCCC4;
    case 0x800BCCC8u: goto label_800BCCC8;
    case 0x800BCCCCu: goto label_800BCCCC;
    case 0x800BCCD0u: goto label_800BCCD0;
    case 0x800BCCD4u: goto label_800BCCD4;
    case 0x800BCCD8u: goto label_800BCCD8;
    case 0x800BCCDCu: goto label_800BCCDC;
    case 0x800BCCE0u: goto label_800BCCE0;
    case 0x800BCCE4u: goto label_800BCCE4;
    case 0x800BCCE8u: goto label_800BCCE8;
    case 0x800BCCECu: goto label_800BCCEC;
    case 0x800BCCF0u: goto label_800BCCF0;
    case 0x800BCCF4u: goto label_800BCCF4;
    case 0x800BCCF8u: goto label_800BCCF8;
    case 0x800BCCFCu: goto label_800BCCFC;
    case 0x800BCD00u: goto label_800BCD00;
    case 0x800BCD04u: goto label_800BCD04;
    case 0x800BCD08u: goto label_800BCD08;
    case 0x800BCD0Cu: goto label_800BCD0C;
    case 0x800BCD10u: goto label_800BCD10;
    case 0x800BCD14u: goto label_800BCD14;
    case 0x800BCD18u: goto label_800BCD18;
    case 0x800BCD1Cu: goto label_800BCD1C;
    case 0x800BCD20u: goto label_800BCD20;
    case 0x800BCD24u: goto label_800BCD24;
    case 0x800BCD28u: goto label_800BCD28;
    case 0x800BCD2Cu: goto label_800BCD2C;
    case 0x800BCD30u: goto label_800BCD30;
    case 0x800BCD34u: goto label_800BCD34;
    case 0x800BCD38u: goto label_800BCD38;
    case 0x800BCD3Cu: goto label_800BCD3C;
    case 0x800BCD40u: goto label_800BCD40;
    case 0x800BCD44u: goto label_800BCD44;
    case 0x800BCD48u: goto label_800BCD48;
    case 0x800BCD4Cu: goto label_800BCD4C;
    case 0x800BCD50u: goto label_800BCD50;
    case 0x800BCD54u: goto label_800BCD54;
    case 0x800BCD58u: goto label_800BCD58;
    case 0x800BCD5Cu: goto label_800BCD5C;
    case 0x800BCD60u: goto label_800BCD60;
    case 0x800BCD64u: goto label_800BCD64;
    case 0x800BCD68u: goto label_800BCD68;
    case 0x800BCD6Cu: goto label_800BCD6C;
    case 0x800BCD70u: goto label_800BCD70;
    case 0x800BCD74u: goto label_800BCD74;
    case 0x800BCD78u: goto label_800BCD78;
    case 0x800BCD7Cu: goto label_800BCD7C;
    case 0x800BCD80u: goto label_800BCD80;
    case 0x800BCD84u: goto label_800BCD84;
    case 0x800BCD88u: goto label_800BCD88;
    case 0x800BCD8Cu: goto label_800BCD8C;
    case 0x800BCD90u: goto label_800BCD90;
    case 0x800BCD94u: goto label_800BCD94;
    case 0x800BCD98u: goto label_800BCD98;
    case 0x800BCD9Cu: goto label_800BCD9C;
    case 0x800BCDA0u: goto label_800BCDA0;
    case 0x800BCDA4u: goto label_800BCDA4;
    case 0x800BCDA8u: goto label_800BCDA8;
    case 0x800BCDACu: goto label_800BCDAC;
    case 0x800BCDB0u: goto label_800BCDB0;
    case 0x800BCDB4u: goto label_800BCDB4;
    case 0x800BCDB8u: goto label_800BCDB8;
    case 0x800BCDBCu: goto label_800BCDBC;
    case 0x800BCDC0u: goto label_800BCDC0;
    case 0x800BCDC4u: goto label_800BCDC4;
    case 0x800BCDC8u: goto label_800BCDC8;
    case 0x800BCDCCu: goto label_800BCDCC;
    case 0x800BCDD0u: goto label_800BCDD0;
    case 0x800BCDD4u: goto label_800BCDD4;
    case 0x800BCDD8u: goto label_800BCDD8;
    case 0x800BCDDCu: goto label_800BCDDC;
    case 0x800BCDE0u: goto label_800BCDE0;
    case 0x800BCDE4u: goto label_800BCDE4;
    case 0x800BCDE8u: goto label_800BCDE8;
    case 0x800BCDECu: goto label_800BCDEC;
    case 0x800BCDF0u: goto label_800BCDF0;
    case 0x800BCDF4u: goto label_800BCDF4;
    case 0x800BCDF8u: goto label_800BCDF8;
    case 0x800BCDFCu: goto label_800BCDFC;
    case 0x800BCE00u: goto label_800BCE00;
    case 0x800BCE04u: goto label_800BCE04;
    case 0x800BCE08u: goto label_800BCE08;
    case 0x800BCE0Cu: goto label_800BCE0C;
    case 0x800BCE10u: goto label_800BCE10;
    case 0x800BCE14u: goto label_800BCE14;
    case 0x800BCE18u: goto label_800BCE18;
    case 0x800BCE1Cu: goto label_800BCE1C;
    case 0x800BCE20u: goto label_800BCE20;
    case 0x800BCE24u: goto label_800BCE24;
    case 0x800BCE28u: goto label_800BCE28;
    case 0x800BCE2Cu: goto label_800BCE2C;
    case 0x800BCE30u: goto label_800BCE30;
    case 0x800BCE34u: goto label_800BCE34;
    case 0x800BCE38u: goto label_800BCE38;
    case 0x800BCE3Cu: goto label_800BCE3C;
    case 0x800BCE40u: goto label_800BCE40;
    case 0x800BCE44u: goto label_800BCE44;
    case 0x800BCE48u: goto label_800BCE48;
    case 0x800BCE4Cu: goto label_800BCE4C;
    case 0x800BCE50u: goto label_800BCE50;
    case 0x800BCE54u: goto label_800BCE54;
    case 0x800BCE58u: goto label_800BCE58;
    case 0x800BCE5Cu: goto label_800BCE5C;
    case 0x800BCE60u: goto label_800BCE60;
    case 0x800BCE64u: goto label_800BCE64;
    case 0x800BCE68u: goto label_800BCE68;
    case 0x800BCE6Cu: goto label_800BCE6C;
    case 0x800BCE70u: goto label_800BCE70;
    case 0x800BCE74u: goto label_800BCE74;
    case 0x800BCE78u: goto label_800BCE78;
    case 0x800BCE7Cu: goto label_800BCE7C;
    case 0x800BCE80u: goto label_800BCE80;
    case 0x800BCE84u: goto label_800BCE84;
    case 0x800BCE88u: goto label_800BCE88;
    case 0x800BCE8Cu: goto label_800BCE8C;
    case 0x800BCE90u: goto label_800BCE90;
    case 0x800BCE94u: goto label_800BCE94;
    case 0x800BCE98u: goto label_800BCE98;
    case 0x800BCE9Cu: goto label_800BCE9C;
    case 0x800BCEA0u: goto label_800BCEA0;
    case 0x800BCEA4u: goto label_800BCEA4;
    case 0x800BCEA8u: goto label_800BCEA8;
    case 0x800BCEACu: goto label_800BCEAC;
    case 0x800BCEB0u: goto label_800BCEB0;
    case 0x800BCEB4u: goto label_800BCEB4;
    case 0x800BCEB8u: goto label_800BCEB8;
    case 0x800BCEBCu: goto label_800BCEBC;
    case 0x800BCEC0u: goto label_800BCEC0;
    case 0x800BCEC4u: goto label_800BCEC4;
    case 0x800BCEC8u: goto label_800BCEC8;
    case 0x800BCECCu: goto label_800BCECC;
    case 0x800BCED0u: goto label_800BCED0;
    case 0x800BCED4u: goto label_800BCED4;
    case 0x800BCED8u: goto label_800BCED8;
    case 0x800BCEDCu: goto label_800BCEDC;
    case 0x800BCEE0u: goto label_800BCEE0;
    case 0x800BCEE4u: goto label_800BCEE4;
    case 0x800BCEE8u: goto label_800BCEE8;
    case 0x800BCEECu: goto label_800BCEEC;
    case 0x800BCEF0u: goto label_800BCEF0;
    case 0x800BCEF4u: goto label_800BCEF4;
    case 0x800BCEF8u: goto label_800BCEF8;
    case 0x800BCEFCu: goto label_800BCEFC;
    case 0x800BCF00u: goto label_800BCF00;
    case 0x800BCF04u: goto label_800BCF04;
    case 0x800BCF08u: goto label_800BCF08;
    case 0x800BCF0Cu: goto label_800BCF0C;
    case 0x800BCF10u: goto label_800BCF10;
    case 0x800BCF14u: goto label_800BCF14;
    case 0x800BCF18u: goto label_800BCF18;
    case 0x800BCF1Cu: goto label_800BCF1C;
    case 0x800BCF20u: goto label_800BCF20;
    case 0x800BCF24u: goto label_800BCF24;
    case 0x800BCF28u: goto label_800BCF28;
    case 0x800BCF2Cu: goto label_800BCF2C;
    case 0x800BCF30u: goto label_800BCF30;
    case 0x800BCF34u: goto label_800BCF34;
    case 0x800BCF38u: goto label_800BCF38;
    case 0x800BCF3Cu: goto label_800BCF3C;
    case 0x800BCF40u: goto label_800BCF40;
    case 0x800BCF44u: goto label_800BCF44;
    case 0x800BCF48u: goto label_800BCF48;
    case 0x800BCF4Cu: goto label_800BCF4C;
    case 0x800BCF50u: goto label_800BCF50;
    case 0x800BCF54u: goto label_800BCF54;
    case 0x800BCF58u: goto label_800BCF58;
    case 0x800BCF5Cu: goto label_800BCF5C;
    case 0x800BCF60u: goto label_800BCF60;
    case 0x800BCF64u: goto label_800BCF64;
    case 0x800BCF68u: goto label_800BCF68;
    case 0x800BCF6Cu: goto label_800BCF6C;
    case 0x800BCF70u: goto label_800BCF70;
    case 0x800BCF74u: goto label_800BCF74;
    case 0x800BCF78u: goto label_800BCF78;
    case 0x800BCF7Cu: goto label_800BCF7C;
    case 0x800BCF80u: goto label_800BCF80;
    case 0x800BCF84u: goto label_800BCF84;
    case 0x800BCF88u: goto label_800BCF88;
    case 0x800BCF8Cu: goto label_800BCF8C;
    case 0x800BCF90u: goto label_800BCF90;
    case 0x800BCF94u: goto label_800BCF94;
    case 0x800BCF98u: goto label_800BCF98;
    case 0x800BCF9Cu: goto label_800BCF9C;
    case 0x800BCFA0u: goto label_800BCFA0;
    case 0x800BCFA4u: goto label_800BCFA4;
    case 0x800BCFA8u: goto label_800BCFA8;
    case 0x800BCFACu: goto label_800BCFAC;
    case 0x800BCFB0u: goto label_800BCFB0;
    case 0x800BCFB4u: goto label_800BCFB4;
    case 0x800BCFB8u: goto label_800BCFB8;
    case 0x800BCFBCu: goto label_800BCFBC;
    case 0x800BCFC0u: goto label_800BCFC0;
    case 0x800BCFC4u: goto label_800BCFC4;
    case 0x800BCFC8u: goto label_800BCFC8;
    case 0x800BCFCCu: goto label_800BCFCC;
    case 0x800BCFD0u: goto label_800BCFD0;
    case 0x800BCFD4u: goto label_800BCFD4;
    case 0x800BCFD8u: goto label_800BCFD8;
    case 0x800BCFDCu: goto label_800BCFDC;
    case 0x800BCFE0u: goto label_800BCFE0;
    case 0x800BCFE4u: goto label_800BCFE4;
    case 0x800BCFE8u: goto label_800BCFE8;
    case 0x800BCFECu: goto label_800BCFEC;
    case 0x800BCFF0u: goto label_800BCFF0;
    case 0x800BCFF4u: goto label_800BCFF4;
    case 0x800BCFF8u: goto label_800BCFF8;
    case 0x800BCFFCu: goto label_800BCFFC;
    case 0x800BD000u: goto label_800BD000;
    case 0x800BD004u: goto label_800BD004;
    case 0x800BD008u: goto label_800BD008;
    case 0x800BD00Cu: goto label_800BD00C;
    case 0x800BD010u: goto label_800BD010;
    case 0x800BD014u: goto label_800BD014;
    case 0x800BD018u: goto label_800BD018;
    case 0x800BD01Cu: goto label_800BD01C;
    case 0x800BD020u: goto label_800BD020;
    case 0x800BD024u: goto label_800BD024;
    case 0x800BD028u: goto label_800BD028;
    case 0x800BD02Cu: goto label_800BD02C;
    case 0x800BD030u: goto label_800BD030;
    case 0x800BD034u: goto label_800BD034;
    case 0x800BD038u: goto label_800BD038;
    case 0x800BD03Cu: goto label_800BD03C;
    case 0x800BD040u: goto label_800BD040;
    case 0x800BD044u: goto label_800BD044;
    case 0x800BD048u: goto label_800BD048;
    case 0x800BD04Cu: goto label_800BD04C;
    case 0x800BD050u: goto label_800BD050;
    case 0x800BD054u: goto label_800BD054;
    case 0x800BD058u: goto label_800BD058;
    case 0x800BD05Cu: goto label_800BD05C;
    case 0x800BD060u: goto label_800BD060;
    case 0x800BD064u: goto label_800BD064;
    case 0x800BD068u: goto label_800BD068;
    case 0x800BD06Cu: goto label_800BD06C;
    case 0x800BD070u: goto label_800BD070;
    case 0x800BD074u: goto label_800BD074;
    case 0x800BD078u: goto label_800BD078;
    case 0x800BD07Cu: goto label_800BD07C;
    case 0x800BD080u: goto label_800BD080;
    case 0x800BD084u: goto label_800BD084;
    case 0x800BD088u: goto label_800BD088;
    case 0x800BD08Cu: goto label_800BD08C;
    case 0x800BD090u: goto label_800BD090;
    case 0x800BD094u: goto label_800BD094;
    case 0x800BD098u: goto label_800BD098;
    case 0x800BD09Cu: goto label_800BD09C;
    case 0x800BD0A0u: goto label_800BD0A0;
    case 0x800BD0A4u: goto label_800BD0A4;
    case 0x800BD0A8u: goto label_800BD0A8;
    case 0x800BD0ACu: goto label_800BD0AC;
    case 0x800BD0B0u: goto label_800BD0B0;
    case 0x800BD0B4u: goto label_800BD0B4;
    case 0x800BD0B8u: goto label_800BD0B8;
    case 0x800BD0BCu: goto label_800BD0BC;
    case 0x800BD0C0u: goto label_800BD0C0;
    case 0x800BD0C4u: goto label_800BD0C4;
    case 0x800BD0C8u: goto label_800BD0C8;
    case 0x800BD0CCu: goto label_800BD0CC;
    case 0x800BD0D0u: goto label_800BD0D0;
    case 0x800BD0D4u: goto label_800BD0D4;
    case 0x800BD0D8u: goto label_800BD0D8;
    case 0x800BD0DCu: goto label_800BD0DC;
    case 0x800BD0E0u: goto label_800BD0E0;
    case 0x800BD0E4u: goto label_800BD0E4;
    case 0x800BD0E8u: goto label_800BD0E8;
    case 0x800BD0ECu: goto label_800BD0EC;
    case 0x800BD0F0u: goto label_800BD0F0;
    case 0x800BD0F4u: goto label_800BD0F4;
    case 0x800BD0F8u: goto label_800BD0F8;
    case 0x800BD0FCu: goto label_800BD0FC;
    case 0x800BD100u: goto label_800BD100;
    case 0x800BD104u: goto label_800BD104;
    case 0x800BD108u: goto label_800BD108;
    case 0x800BD10Cu: goto label_800BD10C;
    case 0x800BD110u: goto label_800BD110;
    case 0x800BD114u: goto label_800BD114;
    case 0x800BD118u: goto label_800BD118;
    case 0x800BD11Cu: goto label_800BD11C;
    case 0x800BD120u: goto label_800BD120;
    case 0x800BD124u: goto label_800BD124;
    case 0x800BD128u: goto label_800BD128;
    case 0x800BD12Cu: goto label_800BD12C;
    case 0x800BD130u: goto label_800BD130;
    case 0x800BD134u: goto label_800BD134;
    case 0x800BD138u: goto label_800BD138;
    case 0x800BD13Cu: goto label_800BD13C;
    case 0x800BD140u: goto label_800BD140;
    case 0x800BD144u: goto label_800BD144;
    case 0x800BD148u: goto label_800BD148;
    case 0x800BD14Cu: goto label_800BD14C;
    case 0x800BD150u: goto label_800BD150;
    case 0x800BD154u: goto label_800BD154;
    case 0x800BD158u: goto label_800BD158;
    case 0x800BD15Cu: goto label_800BD15C;
    case 0x800BD160u: goto label_800BD160;
    case 0x800BD164u: goto label_800BD164;
    case 0x800BD168u: goto label_800BD168;
    case 0x800BD16Cu: goto label_800BD16C;
    case 0x800BD170u: goto label_800BD170;
    case 0x800BD174u: goto label_800BD174;
    case 0x800BD178u: goto label_800BD178;
    case 0x800BD17Cu: goto label_800BD17C;
    case 0x800BD180u: goto label_800BD180;
    case 0x800BD184u: goto label_800BD184;
    case 0x800BD188u: goto label_800BD188;
    case 0x800BD18Cu: goto label_800BD18C;
    case 0x800BD190u: goto label_800BD190;
    case 0x800BD194u: goto label_800BD194;
    case 0x800BD198u: goto label_800BD198;
    case 0x800BD19Cu: goto label_800BD19C;
    case 0x800BD1A0u: goto label_800BD1A0;
    case 0x800BD1A4u: goto label_800BD1A4;
    case 0x800BD1A8u: goto label_800BD1A8;
    case 0x800BD1ACu: goto label_800BD1AC;
    case 0x800BD1B0u: goto label_800BD1B0;
    case 0x800BD1B4u: goto label_800BD1B4;
    case 0x800BD1B8u: goto label_800BD1B8;
    case 0x800BD1BCu: goto label_800BD1BC;
    case 0x800BD1C0u: goto label_800BD1C0;
    case 0x800BD1C4u: goto label_800BD1C4;
    case 0x800BD1C8u: goto label_800BD1C8;
    case 0x800BD1CCu: goto label_800BD1CC;
    case 0x800BD1D0u: goto label_800BD1D0;
    case 0x800BD1D4u: goto label_800BD1D4;
    case 0x800BD1D8u: goto label_800BD1D8;
    case 0x800BD1DCu: goto label_800BD1DC;
    case 0x800BD1E0u: goto label_800BD1E0;
    case 0x800BD1E4u: goto label_800BD1E4;
    case 0x800BD1E8u: goto label_800BD1E8;
    case 0x800BD1ECu: goto label_800BD1EC;
    case 0x800BD1F0u: goto label_800BD1F0;
    case 0x800BD1F4u: goto label_800BD1F4;
    case 0x800BD1F8u: goto label_800BD1F8;
    case 0x800BD1FCu: goto label_800BD1FC;
    case 0x800BD200u: goto label_800BD200;
    case 0x800BD204u: goto label_800BD204;
    case 0x800BD208u: goto label_800BD208;
    case 0x800BD20Cu: goto label_800BD20C;
    case 0x800BD210u: goto label_800BD210;
    case 0x800BD214u: goto label_800BD214;
    case 0x800BD218u: goto label_800BD218;
    case 0x800BD21Cu: goto label_800BD21C;
    case 0x800BD220u: goto label_800BD220;
    case 0x800BD224u: goto label_800BD224;
    case 0x800BD228u: goto label_800BD228;
    case 0x800BD22Cu: goto label_800BD22C;
    case 0x800BD230u: goto label_800BD230;
    case 0x800BD234u: goto label_800BD234;
    case 0x800BD238u: goto label_800BD238;
    case 0x800BD23Cu: goto label_800BD23C;
    case 0x800BD240u: goto label_800BD240;
    case 0x800BD244u: goto label_800BD244;
    case 0x800BD248u: goto label_800BD248;
    case 0x800BD24Cu: goto label_800BD24C;
    case 0x800BD250u: goto label_800BD250;
    case 0x800BD254u: goto label_800BD254;
    case 0x800BD258u: goto label_800BD258;
    case 0x800BD25Cu: goto label_800BD25C;
    case 0x800BD260u: goto label_800BD260;
    case 0x800BD264u: goto label_800BD264;
    case 0x800BD268u: goto label_800BD268;
    case 0x800BD26Cu: goto label_800BD26C;
    case 0x800BD270u: goto label_800BD270;
    case 0x800BD274u: goto label_800BD274;
    case 0x800BD278u: goto label_800BD278;
    case 0x800BD27Cu: goto label_800BD27C;
    case 0x800BD280u: goto label_800BD280;
    case 0x800BD284u: goto label_800BD284;
    case 0x800BD288u: goto label_800BD288;
    case 0x800BD28Cu: goto label_800BD28C;
    case 0x800BD290u: goto label_800BD290;
    case 0x800BD294u: goto label_800BD294;
    case 0x800BD298u: goto label_800BD298;
    case 0x800BD29Cu: goto label_800BD29C;
    case 0x800BD2A0u: goto label_800BD2A0;
    case 0x800BD2A4u: goto label_800BD2A4;
    case 0x800BD2A8u: goto label_800BD2A8;
    case 0x800BD2ACu: goto label_800BD2AC;
    case 0x800BD2B0u: goto label_800BD2B0;
    case 0x800BD2B4u: goto label_800BD2B4;
    case 0x800BD2B8u: goto label_800BD2B8;
    case 0x800BD2BCu: goto label_800BD2BC;
    case 0x800BD2C0u: goto label_800BD2C0;
    case 0x800BD2C4u: goto label_800BD2C4;
    case 0x800BD2C8u: goto label_800BD2C8;
    case 0x800BD2CCu: goto label_800BD2CC;
    case 0x800BD2D0u: goto label_800BD2D0;
    case 0x800BD2D4u: goto label_800BD2D4;
    case 0x800BD2D8u: goto label_800BD2D8;
    case 0x800BD2DCu: goto label_800BD2DC;
    case 0x800BD2E0u: goto label_800BD2E0;
    case 0x800BD2E4u: goto label_800BD2E4;
    case 0x800BD2E8u: goto label_800BD2E8;
    case 0x800BD2ECu: goto label_800BD2EC;
    case 0x800BD2F0u: goto label_800BD2F0;
    case 0x800BD2F4u: goto label_800BD2F4;
    case 0x800BD2F8u: goto label_800BD2F8;
    case 0x800BD2FCu: goto label_800BD2FC;
    case 0x800BD300u: goto label_800BD300;
    case 0x800BD304u: goto label_800BD304;
    case 0x800BD308u: goto label_800BD308;
    case 0x800BD30Cu: goto label_800BD30C;
    case 0x800BD310u: goto label_800BD310;
    case 0x800BD314u: goto label_800BD314;
    case 0x800BD318u: goto label_800BD318;
    case 0x800BD31Cu: goto label_800BD31C;
    case 0x800BD320u: goto label_800BD320;
    case 0x800BD324u: goto label_800BD324;
    case 0x800BD328u: goto label_800BD328;
    case 0x800BD32Cu: goto label_800BD32C;
    case 0x800BD330u: goto label_800BD330;
    case 0x800BD334u: goto label_800BD334;
    case 0x800BD338u: goto label_800BD338;
    case 0x800BD33Cu: goto label_800BD33C;
    case 0x800BD340u: goto label_800BD340;
    case 0x800BD344u: goto label_800BD344;
    case 0x800BD348u: goto label_800BD348;
    case 0x800BD34Cu: goto label_800BD34C;
    case 0x800BD350u: goto label_800BD350;
    case 0x800BD354u: goto label_800BD354;
    case 0x800BD358u: goto label_800BD358;
    case 0x800BD35Cu: goto label_800BD35C;
    case 0x800BD360u: goto label_800BD360;
    case 0x800BD364u: goto label_800BD364;
    case 0x800BD368u: goto label_800BD368;
    case 0x800BD36Cu: goto label_800BD36C;
    case 0x800BD370u: goto label_800BD370;
    case 0x800BD374u: goto label_800BD374;
    case 0x800BD378u: goto label_800BD378;
    case 0x800BD37Cu: goto label_800BD37C;
    case 0x800BD380u: goto label_800BD380;
    case 0x800BD384u: goto label_800BD384;
    case 0x800BD388u: goto label_800BD388;
    case 0x800BD38Cu: goto label_800BD38C;
    case 0x800BD390u: goto label_800BD390;
    case 0x800BD394u: goto label_800BD394;
    case 0x800BD398u: goto label_800BD398;
    case 0x800BD39Cu: goto label_800BD39C;
    case 0x800BD3A0u: goto label_800BD3A0;
    case 0x800BD3A4u: goto label_800BD3A4;
    case 0x800BD3A8u: goto label_800BD3A8;
    case 0x800BD3ACu: goto label_800BD3AC;
    case 0x800BD3B0u: goto label_800BD3B0;
    case 0x800BD3B4u: goto label_800BD3B4;
    case 0x800BD3B8u: goto label_800BD3B8;
    case 0x800BD3BCu: goto label_800BD3BC;
    case 0x800BD3C0u: goto label_800BD3C0;
    case 0x800BD3C4u: goto label_800BD3C4;
    case 0x800BD3C8u: goto label_800BD3C8;
    case 0x800BD3CCu: goto label_800BD3CC;
    case 0x800BD3D0u: goto label_800BD3D0;
    case 0x800BD3D4u: goto label_800BD3D4;
    case 0x800BD3D8u: goto label_800BD3D8;
    case 0x800BD3DCu: goto label_800BD3DC;
    case 0x800BD3E0u: goto label_800BD3E0;
    case 0x800BD3E4u: goto label_800BD3E4;
    case 0x800BD3E8u: goto label_800BD3E8;
    case 0x800BD3ECu: goto label_800BD3EC;
    case 0x800BD3F0u: goto label_800BD3F0;
    case 0x800BD3F4u: goto label_800BD3F4;
    case 0x800BD3F8u: goto label_800BD3F8;
    case 0x800BD3FCu: goto label_800BD3FC;
    case 0x800BD400u: goto label_800BD400;
    case 0x800BD404u: goto label_800BD404;
    case 0x800BD408u: goto label_800BD408;
    case 0x800BD40Cu: goto label_800BD40C;
    case 0x800BD410u: goto label_800BD410;
    case 0x800BD414u: goto label_800BD414;
    case 0x800BD418u: goto label_800BD418;
    case 0x800BD41Cu: goto label_800BD41C;
    case 0x800BD420u: goto label_800BD420;
    case 0x800BD424u: goto label_800BD424;
    case 0x800BD428u: goto label_800BD428;
    case 0x800BD42Cu: goto label_800BD42C;
    case 0x800BD430u: goto label_800BD430;
    case 0x800BD434u: goto label_800BD434;
    case 0x800BD438u: goto label_800BD438;
    case 0x800BD43Cu: goto label_800BD43C;
    case 0x800BD440u: goto label_800BD440;
    case 0x800BD444u: goto label_800BD444;
    case 0x800BD448u: goto label_800BD448;
    case 0x800BD44Cu: goto label_800BD44C;
    case 0x800BD450u: goto label_800BD450;
    case 0x800BD454u: goto label_800BD454;
    case 0x800BD458u: goto label_800BD458;
    case 0x800BD45Cu: goto label_800BD45C;
    case 0x800BD460u: goto label_800BD460;
    case 0x800BD464u: goto label_800BD464;
    case 0x800BD468u: goto label_800BD468;
    case 0x800BD46Cu: goto label_800BD46C;
    case 0x800BD470u: goto label_800BD470;
    case 0x800BD474u: goto label_800BD474;
    case 0x800BD478u: goto label_800BD478;
    case 0x800BD47Cu: goto label_800BD47C;
    case 0x800BD480u: goto label_800BD480;
    case 0x800BD484u: goto label_800BD484;
    case 0x800BD488u: goto label_800BD488;
    case 0x800BD48Cu: goto label_800BD48C;
    case 0x800BD490u: goto label_800BD490;
    case 0x800BD494u: goto label_800BD494;
    case 0x800BD498u: goto label_800BD498;
    case 0x800BD49Cu: goto label_800BD49C;
    case 0x800BD4A0u: goto label_800BD4A0;
    case 0x800BD4A4u: goto label_800BD4A4;
    case 0x800BD4A8u: goto label_800BD4A8;
    case 0x800BD4ACu: goto label_800BD4AC;
    case 0x800BD4B0u: goto label_800BD4B0;
    case 0x800BD4B4u: goto label_800BD4B4;
    case 0x800BD4B8u: goto label_800BD4B8;
    case 0x800BD4BCu: goto label_800BD4BC;
    case 0x800BD4C0u: goto label_800BD4C0;
    case 0x800BD4C4u: goto label_800BD4C4;
    case 0x800BD4C8u: goto label_800BD4C8;
    case 0x800BD4CCu: goto label_800BD4CC;
    case 0x800BD4D0u: goto label_800BD4D0;
    case 0x800BD4D4u: goto label_800BD4D4;
    case 0x800BD4D8u: goto label_800BD4D8;
    case 0x800BD4DCu: goto label_800BD4DC;
    case 0x800BD4E0u: goto label_800BD4E0;
    case 0x800BD4E4u: goto label_800BD4E4;
    case 0x800BD4E8u: goto label_800BD4E8;
    case 0x800BD4ECu: goto label_800BD4EC;
    case 0x800BD4F0u: goto label_800BD4F0;
    case 0x800BD4F4u: goto label_800BD4F4;
    case 0x800BD4F8u: goto label_800BD4F8;
    case 0x800BD4FCu: goto label_800BD4FC;
    case 0x800BD500u: goto label_800BD500;
    case 0x800BD504u: goto label_800BD504;
    case 0x800BD508u: goto label_800BD508;
    case 0x800BD50Cu: goto label_800BD50C;
    case 0x800BD510u: goto label_800BD510;
    case 0x800BD514u: goto label_800BD514;
    case 0x800BD518u: goto label_800BD518;
    case 0x800BD51Cu: goto label_800BD51C;
    case 0x800BD520u: goto label_800BD520;
    case 0x800BD524u: goto label_800BD524;
    case 0x800BD528u: goto label_800BD528;
    case 0x800BD52Cu: goto label_800BD52C;
    case 0x800BD530u: goto label_800BD530;
    case 0x800BD534u: goto label_800BD534;
    case 0x800BD538u: goto label_800BD538;
    case 0x800BD53Cu: goto label_800BD53C;
    case 0x800BD540u: goto label_800BD540;
    case 0x800BD544u: goto label_800BD544;
    case 0x800BD548u: goto label_800BD548;
    case 0x800BD54Cu: goto label_800BD54C;
    case 0x800BD550u: goto label_800BD550;
    case 0x800BD554u: goto label_800BD554;
    case 0x800BD558u: goto label_800BD558;
    case 0x800BD55Cu: goto label_800BD55C;
    case 0x800BD560u: goto label_800BD560;
    case 0x800BD564u: goto label_800BD564;
    case 0x800BD568u: goto label_800BD568;
    case 0x800BD56Cu: goto label_800BD56C;
    case 0x800BD570u: goto label_800BD570;
    case 0x800BD574u: goto label_800BD574;
    case 0x800BD578u: goto label_800BD578;
    case 0x800BD57Cu: goto label_800BD57C;
    case 0x800BD580u: goto label_800BD580;
    case 0x800BD584u: goto label_800BD584;
    case 0x800BD588u: goto label_800BD588;
    case 0x800BD58Cu: goto label_800BD58C;
    case 0x800BD590u: goto label_800BD590;
    case 0x800BD594u: goto label_800BD594;
    case 0x800BD598u: goto label_800BD598;
    case 0x800BD59Cu: goto label_800BD59C;
    case 0x800BD5A0u: goto label_800BD5A0;
    case 0x800BD5A4u: goto label_800BD5A4;
    case 0x800BD5A8u: goto label_800BD5A8;
    case 0x800BD5ACu: goto label_800BD5AC;
    case 0x800BD5B0u: goto label_800BD5B0;
    case 0x800BD5B4u: goto label_800BD5B4;
    case 0x800BD5B8u: goto label_800BD5B8;
    case 0x800BD5BCu: goto label_800BD5BC;
    case 0x800BD5C0u: goto label_800BD5C0;
    case 0x800BD5C4u: goto label_800BD5C4;
    case 0x800BD5C8u: goto label_800BD5C8;
    case 0x800BD5CCu: goto label_800BD5CC;
    case 0x800BD5D0u: goto label_800BD5D0;
    case 0x800BD5D4u: goto label_800BD5D4;
    case 0x800BD5D8u: goto label_800BD5D8;
    case 0x800BD5DCu: goto label_800BD5DC;
    case 0x800BD5E0u: goto label_800BD5E0;
    case 0x800BD5E4u: goto label_800BD5E4;
    case 0x800BD5E8u: goto label_800BD5E8;
    case 0x800BD5ECu: goto label_800BD5EC;
    case 0x800BD5F0u: goto label_800BD5F0;
    case 0x800BD5F4u: goto label_800BD5F4;
    case 0x800BD5F8u: goto label_800BD5F8;
    case 0x800BD5FCu: goto label_800BD5FC;
    case 0x800BD600u: goto label_800BD600;
    case 0x800BD604u: goto label_800BD604;
    case 0x800BD608u: goto label_800BD608;
    case 0x800BD60Cu: goto label_800BD60C;
    case 0x800BD610u: goto label_800BD610;
    case 0x800BD614u: goto label_800BD614;
    case 0x800BD618u: goto label_800BD618;
    case 0x800BD61Cu: goto label_800BD61C;
    case 0x800BD620u: goto label_800BD620;
    case 0x800BD624u: goto label_800BD624;
    case 0x800BD628u: goto label_800BD628;
    case 0x800BD62Cu: goto label_800BD62C;
    case 0x800BD630u: goto label_800BD630;
    case 0x800BD634u: goto label_800BD634;
    case 0x800BD638u: goto label_800BD638;
    case 0x800BD63Cu: goto label_800BD63C;
    case 0x800BD640u: goto label_800BD640;
    case 0x800BD644u: goto label_800BD644;
    case 0x800BD648u: goto label_800BD648;
    case 0x800BD64Cu: goto label_800BD64C;
    case 0x800BD650u: goto label_800BD650;
    case 0x800BD654u: goto label_800BD654;
    case 0x800BD658u: goto label_800BD658;
    case 0x800BD65Cu: goto label_800BD65C;
    case 0x800BD660u: goto label_800BD660;
    case 0x800BD664u: goto label_800BD664;
    case 0x800BD668u: goto label_800BD668;
    case 0x800BD66Cu: goto label_800BD66C;
    case 0x800BD670u: goto label_800BD670;
    case 0x800BD674u: goto label_800BD674;
    case 0x800BD678u: goto label_800BD678;
    case 0x800BD67Cu: goto label_800BD67C;
    case 0x800BD680u: goto label_800BD680;
    case 0x800BD684u: goto label_800BD684;
    case 0x800BD688u: goto label_800BD688;
    case 0x800BD68Cu: goto label_800BD68C;
    case 0x800BD690u: goto label_800BD690;
    case 0x800BD694u: goto label_800BD694;
    case 0x800BD698u: goto label_800BD698;
    case 0x800BD69Cu: goto label_800BD69C;
    case 0x800BD6A0u: goto label_800BD6A0;
    case 0x800BD6A4u: goto label_800BD6A4;
    case 0x800BD6A8u: goto label_800BD6A8;
    case 0x800BD6ACu: goto label_800BD6AC;
    case 0x800BD6B0u: goto label_800BD6B0;
    case 0x800BD6B4u: goto label_800BD6B4;
    case 0x800BD6B8u: goto label_800BD6B8;
    case 0x800BD6BCu: goto label_800BD6BC;
    case 0x800BD6C0u: goto label_800BD6C0;
    case 0x800BD6C4u: goto label_800BD6C4;
    case 0x800BD6C8u: goto label_800BD6C8;
    case 0x800BD6CCu: goto label_800BD6CC;
    case 0x800BD6D0u: goto label_800BD6D0;
    case 0x800BD6D4u: goto label_800BD6D4;
    case 0x800BD6D8u: goto label_800BD6D8;
    case 0x800BD6DCu: goto label_800BD6DC;
    case 0x800BD6E0u: goto label_800BD6E0;
    case 0x800BD6E4u: goto label_800BD6E4;
    case 0x800BD6E8u: goto label_800BD6E8;
    case 0x800BD6ECu: goto label_800BD6EC;
    case 0x800BD6F0u: goto label_800BD6F0;
    case 0x800BD6F4u: goto label_800BD6F4;
    case 0x800BD6F8u: goto label_800BD6F8;
    case 0x800BD6FCu: goto label_800BD6FC;
    case 0x800BD700u: goto label_800BD700;
    case 0x800BD704u: goto label_800BD704;
    case 0x800BD708u: goto label_800BD708;
    case 0x800BD70Cu: goto label_800BD70C;
    case 0x800BD710u: goto label_800BD710;
    case 0x800BD714u: goto label_800BD714;
    case 0x800BD718u: goto label_800BD718;
    case 0x800BD71Cu: goto label_800BD71C;
    case 0x800BD720u: goto label_800BD720;
    case 0x800BD724u: goto label_800BD724;
    case 0x800BD728u: goto label_800BD728;
    case 0x800BD72Cu: goto label_800BD72C;
    case 0x800BD730u: goto label_800BD730;
    case 0x800BD734u: goto label_800BD734;
    case 0x800BD738u: goto label_800BD738;
    case 0x800BD73Cu: goto label_800BD73C;
    case 0x800BD740u: goto label_800BD740;
    case 0x800BD744u: goto label_800BD744;
    case 0x800BD748u: goto label_800BD748;
    case 0x800BD74Cu: goto label_800BD74C;
    case 0x800BD750u: goto label_800BD750;
    case 0x800BD754u: goto label_800BD754;
    case 0x800BD758u: goto label_800BD758;
    case 0x800BD75Cu: goto label_800BD75C;
    case 0x800BD760u: goto label_800BD760;
    case 0x800BD764u: goto label_800BD764;
    case 0x800BD768u: goto label_800BD768;
    case 0x800BD76Cu: goto label_800BD76C;
    case 0x800BD770u: goto label_800BD770;
    case 0x800BD774u: goto label_800BD774;
    case 0x800BD778u: goto label_800BD778;
    case 0x800BD77Cu: goto label_800BD77C;
    case 0x800BD780u: goto label_800BD780;
    case 0x800BD784u: goto label_800BD784;
    case 0x800BD788u: goto label_800BD788;
    case 0x800BD78Cu: goto label_800BD78C;
    case 0x800BD790u: goto label_800BD790;
    case 0x800BD794u: goto label_800BD794;
    case 0x800BD798u: goto label_800BD798;
    case 0x800BD79Cu: goto label_800BD79C;
    case 0x800BD7A0u: goto label_800BD7A0;
    case 0x800BD7A4u: goto label_800BD7A4;
    case 0x800BD7A8u: goto label_800BD7A8;
    case 0x800BD7ACu: goto label_800BD7AC;
    case 0x800BD7B0u: goto label_800BD7B0;
    case 0x800BD7B4u: goto label_800BD7B4;
    case 0x800BD7B8u: goto label_800BD7B8;
    case 0x800BD7BCu: goto label_800BD7BC;
    case 0x800BD7C0u: goto label_800BD7C0;
    case 0x800BD7C4u: goto label_800BD7C4;
    case 0x800BD7C8u: goto label_800BD7C8;
    case 0x800BD7CCu: goto label_800BD7CC;
    case 0x800BD7D0u: goto label_800BD7D0;
    case 0x800BD7D4u: goto label_800BD7D4;
    case 0x800BD7D8u: goto label_800BD7D8;
    case 0x800BD7DCu: goto label_800BD7DC;
    case 0x800BD7E0u: goto label_800BD7E0;
    case 0x800BD7E4u: goto label_800BD7E4;
    case 0x800BD7E8u: goto label_800BD7E8;
    case 0x800BD7ECu: goto label_800BD7EC;
    case 0x800BD7F0u: goto label_800BD7F0;
    case 0x800BD7F4u: goto label_800BD7F4;
    case 0x800BD7F8u: goto label_800BD7F8;
    case 0x800BD7FCu: goto label_800BD7FC;
    case 0x800BD800u: goto label_800BD800;
    case 0x800BD804u: goto label_800BD804;
    case 0x800BD808u: goto label_800BD808;
    case 0x800BD80Cu: goto label_800BD80C;
    case 0x800BD810u: goto label_800BD810;
    case 0x800BD814u: goto label_800BD814;
    case 0x800BD818u: goto label_800BD818;
    case 0x800BD81Cu: goto label_800BD81C;
    case 0x800BD820u: goto label_800BD820;
    case 0x800BD824u: goto label_800BD824;
    case 0x800BD828u: goto label_800BD828;
    case 0x800BD82Cu: goto label_800BD82C;
    case 0x800BD830u: goto label_800BD830;
    case 0x800BD834u: goto label_800BD834;
    case 0x800BD838u: goto label_800BD838;
    case 0x800BD83Cu: goto label_800BD83C;
    case 0x800BD840u: goto label_800BD840;
    case 0x800BD844u: goto label_800BD844;
    case 0x800BD848u: goto label_800BD848;
    case 0x800BD84Cu: goto label_800BD84C;
    case 0x800BD850u: goto label_800BD850;
    case 0x800BD854u: goto label_800BD854;
    case 0x800BD858u: goto label_800BD858;
    case 0x800BD85Cu: goto label_800BD85C;
    case 0x800BD860u: goto label_800BD860;
    case 0x800BD864u: goto label_800BD864;
    case 0x800BD868u: goto label_800BD868;
    case 0x800BD86Cu: goto label_800BD86C;
    case 0x800BD870u: goto label_800BD870;
    case 0x800BD874u: goto label_800BD874;
    case 0x800BD878u: goto label_800BD878;
    case 0x800BD87Cu: goto label_800BD87C;
    case 0x800BD880u: goto label_800BD880;
    case 0x800BD884u: goto label_800BD884;
    case 0x800BD888u: goto label_800BD888;
    case 0x800BD88Cu: goto label_800BD88C;
    case 0x800BD890u: goto label_800BD890;
    case 0x800BD894u: goto label_800BD894;
    case 0x800BD898u: goto label_800BD898;
    case 0x800BD89Cu: goto label_800BD89C;
    case 0x800BD8A0u: goto label_800BD8A0;
    case 0x800BD8A4u: goto label_800BD8A4;
    case 0x800BD8A8u: goto label_800BD8A8;
    case 0x800BD8ACu: goto label_800BD8AC;
    case 0x800BD8B0u: goto label_800BD8B0;
    case 0x800BD8B4u: goto label_800BD8B4;
    case 0x800BD8B8u: goto label_800BD8B8;
    case 0x800BD8BCu: goto label_800BD8BC;
    case 0x800BD8C0u: goto label_800BD8C0;
    case 0x800BD8C4u: goto label_800BD8C4;
    case 0x800BD8C8u: goto label_800BD8C8;
    case 0x800BD8CCu: goto label_800BD8CC;
    case 0x800BD8D0u: goto label_800BD8D0;
    case 0x800BD8D4u: goto label_800BD8D4;
    case 0x800BD8D8u: goto label_800BD8D8;
    case 0x800BD8DCu: goto label_800BD8DC;
    case 0x800BD8E0u: goto label_800BD8E0;
    case 0x800BD8E4u: goto label_800BD8E4;
    case 0x800BD8E8u: goto label_800BD8E8;
    case 0x800BD8ECu: goto label_800BD8EC;
    case 0x800BD8F0u: goto label_800BD8F0;
    case 0x800BD8F4u: goto label_800BD8F4;
    case 0x800BD8F8u: goto label_800BD8F8;
    case 0x800BD8FCu: goto label_800BD8FC;
    case 0x800BD900u: goto label_800BD900;
    case 0x800BD904u: goto label_800BD904;
    case 0x800BD908u: goto label_800BD908;
    case 0x800BD90Cu: goto label_800BD90C;
    case 0x800BD910u: goto label_800BD910;
    case 0x800BD914u: goto label_800BD914;
    case 0x800BD918u: goto label_800BD918;
    case 0x800BD91Cu: goto label_800BD91C;
    case 0x800BD920u: goto label_800BD920;
    case 0x800BD924u: goto label_800BD924;
    case 0x800BD928u: goto label_800BD928;
    case 0x800BD92Cu: goto label_800BD92C;
    case 0x800BD930u: goto label_800BD930;
    case 0x800BD934u: goto label_800BD934;
    case 0x800BD938u: goto label_800BD938;
    case 0x800BD93Cu: goto label_800BD93C;
    case 0x800BD940u: goto label_800BD940;
    case 0x800BD944u: goto label_800BD944;
    case 0x800BD948u: goto label_800BD948;
    case 0x800BD94Cu: goto label_800BD94C;
    case 0x800BD950u: goto label_800BD950;
    case 0x800BD954u: goto label_800BD954;
    case 0x800BD958u: goto label_800BD958;
    case 0x800BD95Cu: goto label_800BD95C;
    case 0x800BD960u: goto label_800BD960;
    case 0x800BD964u: goto label_800BD964;
    case 0x800BD968u: goto label_800BD968;
    case 0x800BD96Cu: goto label_800BD96C;
    case 0x800BD970u: goto label_800BD970;
    case 0x800BD974u: goto label_800BD974;
    case 0x800BD978u: goto label_800BD978;
    case 0x800BD97Cu: goto label_800BD97C;
    case 0x800BD980u: goto label_800BD980;
    case 0x800BD984u: goto label_800BD984;
    case 0x800BD988u: goto label_800BD988;
    case 0x800BD98Cu: goto label_800BD98C;
    case 0x800BD990u: goto label_800BD990;
    case 0x800BD994u: goto label_800BD994;
    case 0x800BD998u: goto label_800BD998;
    case 0x800BD99Cu: goto label_800BD99C;
    case 0x800BD9A0u: goto label_800BD9A0;
    case 0x800BD9A4u: goto label_800BD9A4;
    case 0x800BD9A8u: goto label_800BD9A8;
    case 0x800BD9ACu: goto label_800BD9AC;
    case 0x800BD9B0u: goto label_800BD9B0;
    case 0x800BD9B4u: goto label_800BD9B4;
    case 0x800BD9B8u: goto label_800BD9B8;
    case 0x800BD9BCu: goto label_800BD9BC;
    case 0x800BD9C0u: goto label_800BD9C0;
    case 0x800BD9C4u: goto label_800BD9C4;
    case 0x800BD9C8u: goto label_800BD9C8;
    case 0x800BD9CCu: goto label_800BD9CC;
    case 0x800BD9D0u: goto label_800BD9D0;
    case 0x800BD9D4u: goto label_800BD9D4;
    case 0x800BD9D8u: goto label_800BD9D8;
    case 0x800BD9DCu: goto label_800BD9DC;
    case 0x800BD9E0u: goto label_800BD9E0;
    case 0x800BD9E4u: goto label_800BD9E4;
    case 0x800BD9E8u: goto label_800BD9E8;
    case 0x800BD9ECu: goto label_800BD9EC;
    case 0x800BD9F0u: goto label_800BD9F0;
    case 0x800BD9F4u: goto label_800BD9F4;
    case 0x800BD9F8u: goto label_800BD9F8;
    case 0x800BD9FCu: goto label_800BD9FC;
    case 0x800BDA00u: goto label_800BDA00;
    case 0x800BDA04u: goto label_800BDA04;
    case 0x800BDA08u: goto label_800BDA08;
    case 0x800BDA0Cu: goto label_800BDA0C;
    case 0x800BDA10u: goto label_800BDA10;
    case 0x800BDA14u: goto label_800BDA14;
    case 0x800BDA18u: goto label_800BDA18;
    case 0x800BDA1Cu: goto label_800BDA1C;
    case 0x800BDA20u: goto label_800BDA20;
    case 0x800BDA24u: goto label_800BDA24;
    case 0x800BDA28u: goto label_800BDA28;
    case 0x800BDA2Cu: goto label_800BDA2C;
    case 0x800BDA30u: goto label_800BDA30;
    case 0x800BDA34u: goto label_800BDA34;
    case 0x800BDA38u: goto label_800BDA38;
    case 0x800BDA3Cu: goto label_800BDA3C;
    case 0x800BDA40u: goto label_800BDA40;
    case 0x800BDA44u: goto label_800BDA44;
    case 0x800BDA48u: goto label_800BDA48;
    case 0x800BDA4Cu: goto label_800BDA4C;
    case 0x800BDA50u: goto label_800BDA50;
    case 0x800BDA54u: goto label_800BDA54;
    case 0x800BDA58u: goto label_800BDA58;
    case 0x800BDA5Cu: goto label_800BDA5C;
    case 0x800BDA60u: goto label_800BDA60;
    case 0x800BDA64u: goto label_800BDA64;
    case 0x800BDA68u: goto label_800BDA68;
    case 0x800BDA6Cu: goto label_800BDA6C;
    case 0x800BDA70u: goto label_800BDA70;
    case 0x800BDA74u: goto label_800BDA74;
    case 0x800BDA78u: goto label_800BDA78;
    case 0x800BDA7Cu: goto label_800BDA7C;
    case 0x800BDA80u: goto label_800BDA80;
    case 0x800BDA84u: goto label_800BDA84;
    case 0x800BDA88u: goto label_800BDA88;
    case 0x800BDA8Cu: goto label_800BDA8C;
    case 0x800BDA90u: goto label_800BDA90;
    case 0x800BDA94u: goto label_800BDA94;
    case 0x800BDA98u: goto label_800BDA98;
    case 0x800BDA9Cu: goto label_800BDA9C;
    case 0x800BDAA0u: goto label_800BDAA0;
    case 0x800BDAA4u: goto label_800BDAA4;
    case 0x800BDAA8u: goto label_800BDAA8;
    case 0x800BDAACu: goto label_800BDAAC;
    case 0x800BDAB0u: goto label_800BDAB0;
    case 0x800BDAB4u: goto label_800BDAB4;
    case 0x800BDAB8u: goto label_800BDAB8;
    case 0x800BDABCu: goto label_800BDABC;
    case 0x800BDAC0u: goto label_800BDAC0;
    case 0x800BDAC4u: goto label_800BDAC4;
    case 0x800BDAC8u: goto label_800BDAC8;
    case 0x800BDACCu: goto label_800BDACC;
    case 0x800BDAD0u: goto label_800BDAD0;
    case 0x800BDAD4u: goto label_800BDAD4;
    case 0x800BDAD8u: goto label_800BDAD8;
    case 0x800BDADCu: goto label_800BDADC;
    case 0x800BDAE0u: goto label_800BDAE0;
    case 0x800BDAE4u: goto label_800BDAE4;
    case 0x800BDAE8u: goto label_800BDAE8;
    case 0x800BDAECu: goto label_800BDAEC;
    case 0x800BDAF0u: goto label_800BDAF0;
    case 0x800BDAF4u: goto label_800BDAF4;
    case 0x800BDAF8u: goto label_800BDAF8;
    case 0x800BDAFCu: goto label_800BDAFC;
    case 0x800BDB00u: goto label_800BDB00;
    case 0x800BDB04u: goto label_800BDB04;
    case 0x800BDB08u: goto label_800BDB08;
    case 0x800BDB0Cu: goto label_800BDB0C;
    case 0x800BDB10u: goto label_800BDB10;
    case 0x800BDB14u: goto label_800BDB14;
    case 0x800BDB18u: goto label_800BDB18;
    case 0x800BDB1Cu: goto label_800BDB1C;
    case 0x800BDB20u: goto label_800BDB20;
    case 0x800BDB24u: goto label_800BDB24;
    case 0x800BDB28u: goto label_800BDB28;
    case 0x800BDB2Cu: goto label_800BDB2C;
    case 0x800BDB30u: goto label_800BDB30;
    case 0x800BDB34u: goto label_800BDB34;
    case 0x800BDB38u: goto label_800BDB38;
    case 0x800BDB3Cu: goto label_800BDB3C;
    case 0x800BDB40u: goto label_800BDB40;
    case 0x800BDB44u: goto label_800BDB44;
    case 0x800BDB48u: goto label_800BDB48;
    case 0x800BDB4Cu: goto label_800BDB4C;
    case 0x800BDB50u: goto label_800BDB50;
    case 0x800BDB54u: goto label_800BDB54;
    case 0x800BDB58u: goto label_800BDB58;
    case 0x800BDB5Cu: goto label_800BDB5C;
    case 0x800BDB60u: goto label_800BDB60;
    case 0x800BDB64u: goto label_800BDB64;
    case 0x800BDB68u: goto label_800BDB68;
    case 0x800BDB6Cu: goto label_800BDB6C;
    case 0x800BDB70u: goto label_800BDB70;
    case 0x800BDB74u: goto label_800BDB74;
    case 0x800BDB78u: goto label_800BDB78;
    case 0x800BDB7Cu: goto label_800BDB7C;
    case 0x800BDB80u: goto label_800BDB80;
    case 0x800BDB84u: goto label_800BDB84;
    case 0x800BDB88u: goto label_800BDB88;
    case 0x800BDB8Cu: goto label_800BDB8C;
    case 0x800BDB90u: goto label_800BDB90;
    case 0x800BDB94u: goto label_800BDB94;
    case 0x800BDB98u: goto label_800BDB98;
    case 0x800BDB9Cu: goto label_800BDB9C;
    case 0x800BDBA0u: goto label_800BDBA0;
    case 0x800BDBA4u: goto label_800BDBA4;
    case 0x800BDBA8u: goto label_800BDBA8;
    case 0x800BDBACu: goto label_800BDBAC;
    case 0x800BDBB0u: goto label_800BDBB0;
    case 0x800BDBB4u: goto label_800BDBB4;
    case 0x800BDBB8u: goto label_800BDBB8;
    case 0x800BDBBCu: goto label_800BDBBC;
    case 0x800BDBC0u: goto label_800BDBC0;
    case 0x800BDBC4u: goto label_800BDBC4;
    case 0x800BDBC8u: goto label_800BDBC8;
    case 0x800BDBCCu: goto label_800BDBCC;
    case 0x800BDBD0u: goto label_800BDBD0;
    case 0x800BDBD4u: goto label_800BDBD4;
    case 0x800BDBD8u: goto label_800BDBD8;
    case 0x800BDBDCu: goto label_800BDBDC;
    case 0x800BDBE0u: goto label_800BDBE0;
    case 0x800BDBE4u: goto label_800BDBE4;
    case 0x800BDBE8u: goto label_800BDBE8;
    case 0x800BDBECu: goto label_800BDBEC;
    case 0x800BDBF0u: goto label_800BDBF0;
    case 0x800BDBF4u: goto label_800BDBF4;
    case 0x800BDBF8u: goto label_800BDBF8;
    case 0x800BDBFCu: goto label_800BDBFC;
    case 0x800BDC00u: goto label_800BDC00;
    case 0x800BDC04u: goto label_800BDC04;
    case 0x800BDC08u: goto label_800BDC08;
    case 0x800BDC0Cu: goto label_800BDC0C;
    case 0x800BDC10u: goto label_800BDC10;
    case 0x800BDC14u: goto label_800BDC14;
    case 0x800BDC18u: goto label_800BDC18;
    case 0x800BDC1Cu: goto label_800BDC1C;
    case 0x800BDC20u: goto label_800BDC20;
    case 0x800BDC24u: goto label_800BDC24;
    case 0x800BDC28u: goto label_800BDC28;
    case 0x800BDC2Cu: goto label_800BDC2C;
    case 0x800BDC30u: goto label_800BDC30;
    case 0x800BDC34u: goto label_800BDC34;
    case 0x800BDC38u: goto label_800BDC38;
    case 0x800BDC3Cu: goto label_800BDC3C;
    case 0x800BDC40u: goto label_800BDC40;
    case 0x800BDC44u: goto label_800BDC44;
    case 0x800BDC48u: goto label_800BDC48;
    case 0x800BDC4Cu: goto label_800BDC4C;
    case 0x800BDC50u: goto label_800BDC50;
    case 0x800BDC54u: goto label_800BDC54;
    case 0x800BDC58u: goto label_800BDC58;
    case 0x800BDC5Cu: goto label_800BDC5C;
    case 0x800BDC60u: goto label_800BDC60;
    case 0x800BDC64u: goto label_800BDC64;
    case 0x800BDC68u: goto label_800BDC68;
    case 0x800BDC6Cu: goto label_800BDC6C;
    case 0x800BDC70u: goto label_800BDC70;
    case 0x800BDC74u: goto label_800BDC74;
    case 0x800BDC78u: goto label_800BDC78;
    case 0x800BDC7Cu: goto label_800BDC7C;
    case 0x800BDC80u: goto label_800BDC80;
    case 0x800BDC84u: goto label_800BDC84;
    case 0x800BDC88u: goto label_800BDC88;
    case 0x800BDC8Cu: goto label_800BDC8C;
    case 0x800BDC90u: goto label_800BDC90;
    case 0x800BDC94u: goto label_800BDC94;
    case 0x800BDC98u: goto label_800BDC98;
    case 0x800BDC9Cu: goto label_800BDC9C;
    case 0x800BDCA0u: goto label_800BDCA0;
    case 0x800BDCA4u: goto label_800BDCA4;
    case 0x800BDCA8u: goto label_800BDCA8;
    case 0x800BDCACu: goto label_800BDCAC;
    case 0x800BDCB0u: goto label_800BDCB0;
    case 0x800BDCB4u: goto label_800BDCB4;
    case 0x800BDCB8u: goto label_800BDCB8;
    case 0x800BDCBCu: goto label_800BDCBC;
    case 0x800BDCC0u: goto label_800BDCC0;
    case 0x800BDCC4u: goto label_800BDCC4;
    case 0x800BDCC8u: goto label_800BDCC8;
    case 0x800BDCCCu: goto label_800BDCCC;
    case 0x800BDCD0u: goto label_800BDCD0;
    case 0x800BDCD4u: goto label_800BDCD4;
    case 0x800BDCD8u: goto label_800BDCD8;
    case 0x800BDCDCu: goto label_800BDCDC;
    case 0x800BDCE0u: goto label_800BDCE0;
    case 0x800BDCE4u: goto label_800BDCE4;
    case 0x800BDCE8u: goto label_800BDCE8;
    case 0x800BDCECu: goto label_800BDCEC;
    case 0x800BDCF0u: goto label_800BDCF0;
    case 0x800BDCF4u: goto label_800BDCF4;
    case 0x800BDCF8u: goto label_800BDCF8;
    case 0x800BDCFCu: goto label_800BDCFC;
    case 0x800BDD00u: goto label_800BDD00;
    case 0x800BDD04u: goto label_800BDD04;
    case 0x800BDD08u: goto label_800BDD08;
    case 0x800BDD0Cu: goto label_800BDD0C;
    case 0x800BDD10u: goto label_800BDD10;
    case 0x800BDD14u: goto label_800BDD14;
    case 0x800BDD18u: goto label_800BDD18;
    case 0x800BDD1Cu: goto label_800BDD1C;
    case 0x800BDD20u: goto label_800BDD20;
    case 0x800BDD24u: goto label_800BDD24;
    case 0x800BDD28u: goto label_800BDD28;
    case 0x800BDD2Cu: goto label_800BDD2C;
    case 0x800BDD30u: goto label_800BDD30;
    case 0x800BDD34u: goto label_800BDD34;
    case 0x800BDD38u: goto label_800BDD38;
    case 0x800BDD3Cu: goto label_800BDD3C;
    case 0x800BDD40u: goto label_800BDD40;
    case 0x800BDD44u: goto label_800BDD44;
    case 0x800BDD48u: goto label_800BDD48;
    case 0x800BDD4Cu: goto label_800BDD4C;
    case 0x800BDD50u: goto label_800BDD50;
    case 0x800BDD54u: goto label_800BDD54;
    case 0x800BDD58u: goto label_800BDD58;
    case 0x800BDD5Cu: goto label_800BDD5C;
    case 0x800BDD60u: goto label_800BDD60;
    case 0x800BDD64u: goto label_800BDD64;
    case 0x800BDD68u: goto label_800BDD68;
    case 0x800BDD6Cu: goto label_800BDD6C;
    case 0x800BDD70u: goto label_800BDD70;
    case 0x800BDD74u: goto label_800BDD74;
    case 0x800BDD78u: goto label_800BDD78;
    case 0x800BDD7Cu: goto label_800BDD7C;
    case 0x800BDD80u: goto label_800BDD80;
    case 0x800BDD84u: goto label_800BDD84;
    case 0x800BDD88u: goto label_800BDD88;
    case 0x800BDD8Cu: goto label_800BDD8C;
    case 0x800BDD90u: goto label_800BDD90;
    case 0x800BDD94u: goto label_800BDD94;
    case 0x800BDD98u: goto label_800BDD98;
    case 0x800BDD9Cu: goto label_800BDD9C;
    case 0x800BDDA0u: goto label_800BDDA0;
    case 0x800BDDA4u: goto label_800BDDA4;
    case 0x800BDDA8u: goto label_800BDDA8;
    case 0x800BDDACu: goto label_800BDDAC;
    case 0x800BDDB0u: goto label_800BDDB0;
    case 0x800BDDB4u: goto label_800BDDB4;
    case 0x800BDDB8u: goto label_800BDDB8;
    case 0x800BDDBCu: goto label_800BDDBC;
    case 0x800BDDC0u: goto label_800BDDC0;
    case 0x800BDDC4u: goto label_800BDDC4;
    case 0x800BDDC8u: goto label_800BDDC8;
    case 0x800BDDCCu: goto label_800BDDCC;
    case 0x800BDDD0u: goto label_800BDDD0;
    case 0x800BDDD4u: goto label_800BDDD4;
    case 0x800BDDD8u: goto label_800BDDD8;
    case 0x800BDDDCu: goto label_800BDDDC;
    case 0x800BDDE0u: goto label_800BDDE0;
    case 0x800BDDE4u: goto label_800BDDE4;
    case 0x800BDDE8u: goto label_800BDDE8;
    case 0x800BDDECu: goto label_800BDDEC;
    case 0x800BDDF0u: goto label_800BDDF0;
    case 0x800BDDF4u: goto label_800BDDF4;
    case 0x800BDDF8u: goto label_800BDDF8;
    case 0x800BDDFCu: goto label_800BDDFC;
    case 0x800BDE00u: goto label_800BDE00;
    case 0x800BDE04u: goto label_800BDE04;
    case 0x800BDE08u: goto label_800BDE08;
    case 0x800BDE0Cu: goto label_800BDE0C;
    case 0x800BDE10u: goto label_800BDE10;
    case 0x800BDE14u: goto label_800BDE14;
    case 0x800BDE18u: goto label_800BDE18;
    case 0x800BDE1Cu: goto label_800BDE1C;
    case 0x800BDE20u: goto label_800BDE20;
    case 0x800BDE24u: goto label_800BDE24;
    case 0x800BDE28u: goto label_800BDE28;
    case 0x800BDE2Cu: goto label_800BDE2C;
    case 0x800BDE30u: goto label_800BDE30;
    case 0x800BDE34u: goto label_800BDE34;
    case 0x800BDE38u: goto label_800BDE38;
    case 0x800BDE3Cu: goto label_800BDE3C;
    case 0x800BDE40u: goto label_800BDE40;
    case 0x800BDE44u: goto label_800BDE44;
    case 0x800BDE48u: goto label_800BDE48;
    case 0x800BDE4Cu: goto label_800BDE4C;
    case 0x800BDE50u: goto label_800BDE50;
    case 0x800BDE54u: goto label_800BDE54;
    case 0x800BDE58u: goto label_800BDE58;
    case 0x800BDE5Cu: goto label_800BDE5C;
    case 0x800BDE60u: goto label_800BDE60;
    case 0x800BDE64u: goto label_800BDE64;
    case 0x800BDE68u: goto label_800BDE68;
    case 0x800BDE6Cu: goto label_800BDE6C;
    case 0x800BDE70u: goto label_800BDE70;
    case 0x800BDE74u: goto label_800BDE74;
    case 0x800BDE78u: goto label_800BDE78;
    case 0x800BDE7Cu: goto label_800BDE7C;
    case 0x800BDE80u: goto label_800BDE80;
    case 0x800BDE84u: goto label_800BDE84;
    case 0x800BDE88u: goto label_800BDE88;
    case 0x800BDE8Cu: goto label_800BDE8C;
    case 0x800BDE90u: goto label_800BDE90;
    case 0x800BDE94u: goto label_800BDE94;
    case 0x800BDE98u: goto label_800BDE98;
    case 0x800BDE9Cu: goto label_800BDE9C;
    case 0x800BDEA0u: goto label_800BDEA0;
    case 0x800BDEA4u: goto label_800BDEA4;
    case 0x800BDEA8u: goto label_800BDEA8;
    case 0x800BDEACu: goto label_800BDEAC;
    case 0x800BDEB0u: goto label_800BDEB0;
    case 0x800BDEB4u: goto label_800BDEB4;
    case 0x800BDEB8u: goto label_800BDEB8;
    case 0x800BDEBCu: goto label_800BDEBC;
    case 0x800BDEC0u: goto label_800BDEC0;
    case 0x800BDEC4u: goto label_800BDEC4;
    case 0x800BDEC8u: goto label_800BDEC8;
    case 0x800BDECCu: goto label_800BDECC;
    case 0x800BDED0u: goto label_800BDED0;
    case 0x800BDED4u: goto label_800BDED4;
    case 0x800BDED8u: goto label_800BDED8;
    case 0x800BDEDCu: goto label_800BDEDC;
    case 0x800BDEE0u: goto label_800BDEE0;
    case 0x800BDEE4u: goto label_800BDEE4;
    case 0x800BDEE8u: goto label_800BDEE8;
    case 0x800BDEECu: goto label_800BDEEC;
    case 0x800BDEF0u: goto label_800BDEF0;
    case 0x800BDEF4u: goto label_800BDEF4;
    case 0x800BDEF8u: goto label_800BDEF8;
    case 0x800BDEFCu: goto label_800BDEFC;
    case 0x800BDF00u: goto label_800BDF00;
    case 0x800BDF04u: goto label_800BDF04;
    case 0x800BDF08u: goto label_800BDF08;
    case 0x800BDF0Cu: goto label_800BDF0C;
    case 0x800BDF10u: goto label_800BDF10;
    case 0x800BDF14u: goto label_800BDF14;
    case 0x800BDF18u: goto label_800BDF18;
    case 0x800BDF1Cu: goto label_800BDF1C;
    case 0x800BDF20u: goto label_800BDF20;
    case 0x800BDF24u: goto label_800BDF24;
    case 0x800BDF28u: goto label_800BDF28;
    case 0x800BDF2Cu: goto label_800BDF2C;
    case 0x800BDF30u: goto label_800BDF30;
    case 0x800BDF34u: goto label_800BDF34;
    case 0x800BDF38u: goto label_800BDF38;
    case 0x800BDF3Cu: goto label_800BDF3C;
    case 0x800BDF40u: goto label_800BDF40;
    case 0x800BDF44u: goto label_800BDF44;
    case 0x800BDF48u: goto label_800BDF48;
    case 0x800BDF4Cu: goto label_800BDF4C;
    case 0x800BDF50u: goto label_800BDF50;
    case 0x800BDF54u: goto label_800BDF54;
    case 0x800BDF58u: goto label_800BDF58;
    case 0x800BDF5Cu: goto label_800BDF5C;
    case 0x800BDF60u: goto label_800BDF60;
    case 0x800BDF64u: goto label_800BDF64;
    case 0x800BDF68u: goto label_800BDF68;
    case 0x800BDF6Cu: goto label_800BDF6C;
    case 0x800BDF70u: goto label_800BDF70;
    case 0x800BDF74u: goto label_800BDF74;
    case 0x800BDF78u: goto label_800BDF78;
    case 0x800BDF7Cu: goto label_800BDF7C;
    case 0x800BDF80u: goto label_800BDF80;
    case 0x800BDF84u: goto label_800BDF84;
    case 0x800BDF88u: goto label_800BDF88;
    case 0x800BDF8Cu: goto label_800BDF8C;
    case 0x800BDF90u: goto label_800BDF90;
    case 0x800BDF94u: goto label_800BDF94;
    case 0x800BDF98u: goto label_800BDF98;
    case 0x800BDF9Cu: goto label_800BDF9C;
    case 0x800BDFA0u: goto label_800BDFA0;
    case 0x800BDFA4u: goto label_800BDFA4;
    case 0x800BDFA8u: goto label_800BDFA8;
    case 0x800BDFACu: goto label_800BDFAC;
    case 0x800BDFB0u: goto label_800BDFB0;
    case 0x800BDFB4u: goto label_800BDFB4;
    case 0x800BDFB8u: goto label_800BDFB8;
    case 0x800BDFBCu: goto label_800BDFBC;
    case 0x800BDFC0u: goto label_800BDFC0;
    case 0x800BDFC4u: goto label_800BDFC4;
    case 0x800BDFC8u: goto label_800BDFC8;
    case 0x800BDFCCu: goto label_800BDFCC;
    case 0x800BDFD0u: goto label_800BDFD0;
    case 0x800BDFD4u: goto label_800BDFD4;
    case 0x800BDFD8u: goto label_800BDFD8;
    case 0x800BDFDCu: goto label_800BDFDC;
    case 0x800BDFE0u: goto label_800BDFE0;
    case 0x800BDFE4u: goto label_800BDFE4;
    case 0x800BDFE8u: goto label_800BDFE8;
    case 0x800BDFECu: goto label_800BDFEC;
    case 0x800BDFF0u: goto label_800BDFF0;
    case 0x800BDFF4u: goto label_800BDFF4;
    case 0x800BDFF8u: goto label_800BDFF8;
    case 0x800BDFFCu: goto label_800BDFFC;
    case 0x800BE000u: goto label_800BE000;
    case 0x800BE004u: goto label_800BE004;
    case 0x800BE008u: goto label_800BE008;
    case 0x800BE00Cu: goto label_800BE00C;
    case 0x800BE010u: goto label_800BE010;
    case 0x800BE014u: goto label_800BE014;
    case 0x800BE018u: goto label_800BE018;
    case 0x800BE01Cu: goto label_800BE01C;
    case 0x800BE020u: goto label_800BE020;
    case 0x800BE024u: goto label_800BE024;
    case 0x800BE028u: goto label_800BE028;
    case 0x800BE02Cu: goto label_800BE02C;
    case 0x800BE030u: goto label_800BE030;
    case 0x800BE034u: goto label_800BE034;
    case 0x800BE038u: goto label_800BE038;
    case 0x800BE03Cu: goto label_800BE03C;
    case 0x800BE040u: goto label_800BE040;
    case 0x800BE044u: goto label_800BE044;
    case 0x800BE048u: goto label_800BE048;
    case 0x800BE04Cu: goto label_800BE04C;
    case 0x800BE050u: goto label_800BE050;
    case 0x800BE054u: goto label_800BE054;
    case 0x800BE058u: goto label_800BE058;
    case 0x800BE05Cu: goto label_800BE05C;
    case 0x800BE060u: goto label_800BE060;
    case 0x800BE064u: goto label_800BE064;
    case 0x800BE068u: goto label_800BE068;
    case 0x800BE06Cu: goto label_800BE06C;
    case 0x800BE070u: goto label_800BE070;
    case 0x800BE074u: goto label_800BE074;
    case 0x800BE078u: goto label_800BE078;
    case 0x800BE07Cu: goto label_800BE07C;
    case 0x800BE080u: goto label_800BE080;
    case 0x800BE084u: goto label_800BE084;
    case 0x800BE088u: goto label_800BE088;
    case 0x800BE08Cu: goto label_800BE08C;
    case 0x800BE090u: goto label_800BE090;
    case 0x800BE094u: goto label_800BE094;
    case 0x800BE098u: goto label_800BE098;
    case 0x800BE09Cu: goto label_800BE09C;
    case 0x800BE0A0u: goto label_800BE0A0;
    case 0x800BE0A4u: goto label_800BE0A4;
    case 0x800BE0A8u: goto label_800BE0A8;
    case 0x800BE0ACu: goto label_800BE0AC;
    case 0x800BE0B0u: goto label_800BE0B0;
    case 0x800BE0B4u: goto label_800BE0B4;
    case 0x800BE0B8u: goto label_800BE0B8;
    case 0x800BE0BCu: goto label_800BE0BC;
    case 0x800BE0C0u: goto label_800BE0C0;
    case 0x800BE0C4u: goto label_800BE0C4;
    case 0x800BE0C8u: goto label_800BE0C8;
    case 0x800BE0CCu: goto label_800BE0CC;
    case 0x800BE0D0u: goto label_800BE0D0;
    case 0x800BE0D4u: goto label_800BE0D4;
    case 0x800BE0D8u: goto label_800BE0D8;
    case 0x800BE0DCu: goto label_800BE0DC;
    case 0x800BE0E0u: goto label_800BE0E0;
    case 0x800BE0E4u: goto label_800BE0E4;
    case 0x800BE0E8u: goto label_800BE0E8;
    case 0x800BE0ECu: goto label_800BE0EC;
    case 0x800BE0F0u: goto label_800BE0F0;
    case 0x800BE0F4u: goto label_800BE0F4;
    case 0x800BE0F8u: goto label_800BE0F8;
    case 0x800BE0FCu: goto label_800BE0FC;
    case 0x800BE100u: goto label_800BE100;
    case 0x800BE104u: goto label_800BE104;
    case 0x800BE108u: goto label_800BE108;
    case 0x800BE10Cu: goto label_800BE10C;
    case 0x800BE110u: goto label_800BE110;
    case 0x800BE114u: goto label_800BE114;
    case 0x800BE118u: goto label_800BE118;
    case 0x800BE11Cu: goto label_800BE11C;
    case 0x800BE120u: goto label_800BE120;
    case 0x800BE124u: goto label_800BE124;
    case 0x800BE128u: goto label_800BE128;
    case 0x800BE12Cu: goto label_800BE12C;
    case 0x800BE130u: goto label_800BE130;
    case 0x800BE134u: goto label_800BE134;
    case 0x800BE138u: goto label_800BE138;
    case 0x800BE13Cu: goto label_800BE13C;
    case 0x800BE140u: goto label_800BE140;
    case 0x800BE144u: goto label_800BE144;
    case 0x800BE148u: goto label_800BE148;
    case 0x800BE14Cu: goto label_800BE14C;
    case 0x800BE150u: goto label_800BE150;
    case 0x800BE154u: goto label_800BE154;
    case 0x800BE158u: goto label_800BE158;
    case 0x800BE15Cu: goto label_800BE15C;
    case 0x800BE160u: goto label_800BE160;
    case 0x800BE164u: goto label_800BE164;
    case 0x800BE168u: goto label_800BE168;
    case 0x800BE16Cu: goto label_800BE16C;
    case 0x800BE170u: goto label_800BE170;
    case 0x800BE174u: goto label_800BE174;
    case 0x800BE178u: goto label_800BE178;
    case 0x800BE17Cu: goto label_800BE17C;
    case 0x800BE180u: goto label_800BE180;
    case 0x800BE184u: goto label_800BE184;
    case 0x800BE188u: goto label_800BE188;
    case 0x800BE18Cu: goto label_800BE18C;
    case 0x800BE190u: goto label_800BE190;
    case 0x800BE194u: goto label_800BE194;
    case 0x800BE198u: goto label_800BE198;
    case 0x800BE19Cu: goto label_800BE19C;
    case 0x800BE1A0u: goto label_800BE1A0;
    case 0x800BE1A4u: goto label_800BE1A4;
    case 0x800BE1A8u: goto label_800BE1A8;
    case 0x800BE1ACu: goto label_800BE1AC;
    case 0x800BE1B0u: goto label_800BE1B0;
    case 0x800BE1B4u: goto label_800BE1B4;
    case 0x800BE1B8u: goto label_800BE1B8;
    case 0x800BE1BCu: goto label_800BE1BC;
    case 0x800BE1C0u: goto label_800BE1C0;
    case 0x800BE1C4u: goto label_800BE1C4;
    case 0x800BE1C8u: goto label_800BE1C8;
    case 0x800BE1CCu: goto label_800BE1CC;
    case 0x800BE1D0u: goto label_800BE1D0;
    case 0x800BE1D4u: goto label_800BE1D4;
    case 0x800BE1D8u: goto label_800BE1D8;
    case 0x800BE1DCu: goto label_800BE1DC;
    case 0x800BE1E0u: goto label_800BE1E0;
    case 0x800BE1E4u: goto label_800BE1E4;
    case 0x800BE1E8u: goto label_800BE1E8;
    case 0x800BE1ECu: goto label_800BE1EC;
    case 0x800BE1F0u: goto label_800BE1F0;
    case 0x800BE1F4u: goto label_800BE1F4;
    case 0x800BE1F8u: goto label_800BE1F8;
    case 0x800BE1FCu: goto label_800BE1FC;
    case 0x800BE200u: goto label_800BE200;
    case 0x800BE204u: goto label_800BE204;
    case 0x800BE208u: goto label_800BE208;
    case 0x800BE20Cu: goto label_800BE20C;
    case 0x800BE210u: goto label_800BE210;
    case 0x800BE214u: goto label_800BE214;
    case 0x800BE218u: goto label_800BE218;
    case 0x800BE21Cu: goto label_800BE21C;
    case 0x800BE220u: goto label_800BE220;
    case 0x800BE224u: goto label_800BE224;
    case 0x800BE228u: goto label_800BE228;
    case 0x800BE22Cu: goto label_800BE22C;
    case 0x800BE230u: goto label_800BE230;
    case 0x800BE234u: goto label_800BE234;
    case 0x800BE238u: goto label_800BE238;
    case 0x800BE23Cu: goto label_800BE23C;
    case 0x800BE240u: goto label_800BE240;
    case 0x800BE244u: goto label_800BE244;
    case 0x800BE248u: goto label_800BE248;
    case 0x800BE24Cu: goto label_800BE24C;
    case 0x800BE250u: goto label_800BE250;
    case 0x800BE254u: goto label_800BE254;
    case 0x800BE258u: goto label_800BE258;
    case 0x800BE25Cu: goto label_800BE25C;
    case 0x800BE260u: goto label_800BE260;
    case 0x800BE264u: goto label_800BE264;
    case 0x800BE268u: goto label_800BE268;
    case 0x800BE26Cu: goto label_800BE26C;
    case 0x800BE270u: goto label_800BE270;
    case 0x800BE274u: goto label_800BE274;
    case 0x800BE278u: goto label_800BE278;
    case 0x800BE27Cu: goto label_800BE27C;
    case 0x800BE280u: goto label_800BE280;
    case 0x800BE284u: goto label_800BE284;
    case 0x800BE288u: goto label_800BE288;
    case 0x800BE28Cu: goto label_800BE28C;
    case 0x800BE290u: goto label_800BE290;
    case 0x800BE294u: goto label_800BE294;
    case 0x800BE298u: goto label_800BE298;
    case 0x800BE29Cu: goto label_800BE29C;
    case 0x800BE2A0u: goto label_800BE2A0;
    case 0x800BE2A4u: goto label_800BE2A4;
    case 0x800BE2A8u: goto label_800BE2A8;
    case 0x800BE2ACu: goto label_800BE2AC;
    case 0x800BE2B0u: goto label_800BE2B0;
    case 0x800BE2B4u: goto label_800BE2B4;
    case 0x800BE2B8u: goto label_800BE2B8;
    case 0x800BE2BCu: goto label_800BE2BC;
    case 0x800BE2C0u: goto label_800BE2C0;
    case 0x800BE2C4u: goto label_800BE2C4;
    case 0x800BE2C8u: goto label_800BE2C8;
    case 0x800BE2CCu: goto label_800BE2CC;
    case 0x800BE2D0u: goto label_800BE2D0;
    case 0x800BE2D4u: goto label_800BE2D4;
    case 0x800BE2D8u: goto label_800BE2D8;
    case 0x800BE2DCu: goto label_800BE2DC;
    case 0x800BE2E0u: goto label_800BE2E0;
    case 0x800BE2E4u: goto label_800BE2E4;
    case 0x800BE2E8u: goto label_800BE2E8;
    case 0x800BE2ECu: goto label_800BE2EC;
    case 0x800BE2F0u: goto label_800BE2F0;
    case 0x800BE2F4u: goto label_800BE2F4;
    case 0x800BE2F8u: goto label_800BE2F8;
    case 0x800BE2FCu: goto label_800BE2FC;
    case 0x800BE300u: goto label_800BE300;
    case 0x800BE304u: goto label_800BE304;
    case 0x800BE308u: goto label_800BE308;
    case 0x800BE30Cu: goto label_800BE30C;
    case 0x800BE310u: goto label_800BE310;
    case 0x800BE314u: goto label_800BE314;
    case 0x800BE318u: goto label_800BE318;
    case 0x800BE31Cu: goto label_800BE31C;
    case 0x800BE320u: goto label_800BE320;
    case 0x800BE324u: goto label_800BE324;
    case 0x800BE328u: goto label_800BE328;
    case 0x800BE32Cu: goto label_800BE32C;
    case 0x800BE330u: goto label_800BE330;
    case 0x800BE334u: goto label_800BE334;
    case 0x800BE338u: goto label_800BE338;
    case 0x800BE33Cu: goto label_800BE33C;
    case 0x800BE340u: goto label_800BE340;
    case 0x800BE344u: goto label_800BE344;
    case 0x800BE348u: goto label_800BE348;
    case 0x800BE34Cu: goto label_800BE34C;
    case 0x800BE350u: goto label_800BE350;
    case 0x800BE354u: goto label_800BE354;
    case 0x800BE358u: goto label_800BE358;
    case 0x800BE35Cu: goto label_800BE35C;
    case 0x800BE360u: goto label_800BE360;
    case 0x800BE364u: goto label_800BE364;
    case 0x800BE368u: goto label_800BE368;
    case 0x800BE36Cu: goto label_800BE36C;
    case 0x800BE370u: goto label_800BE370;
    case 0x800BE374u: goto label_800BE374;
    case 0x800BE378u: goto label_800BE378;
    case 0x800BE37Cu: goto label_800BE37C;
    case 0x800BE380u: goto label_800BE380;
    case 0x800BE384u: goto label_800BE384;
    case 0x800BE388u: goto label_800BE388;
    case 0x800BE38Cu: goto label_800BE38C;
    case 0x800BE390u: goto label_800BE390;
    case 0x800BE394u: goto label_800BE394;
    case 0x800BE398u: goto label_800BE398;
    case 0x800BE39Cu: goto label_800BE39C;
    case 0x800BE3A0u: goto label_800BE3A0;
    case 0x800BE3A4u: goto label_800BE3A4;
    case 0x800BE3A8u: goto label_800BE3A8;
    case 0x800BE3ACu: goto label_800BE3AC;
    case 0x800BE3B0u: goto label_800BE3B0;
    case 0x800BE3B4u: goto label_800BE3B4;
    case 0x800BE3B8u: goto label_800BE3B8;
    case 0x800BE3BCu: goto label_800BE3BC;
    case 0x800BE3C0u: goto label_800BE3C0;
    case 0x800BE3C4u: goto label_800BE3C4;
    case 0x800BE3C8u: goto label_800BE3C8;
    case 0x800BE3CCu: goto label_800BE3CC;
    case 0x800BE3D0u: goto label_800BE3D0;
    case 0x800BE3D4u: goto label_800BE3D4;
    case 0x800BE3D8u: goto label_800BE3D8;
    case 0x800BE3DCu: goto label_800BE3DC;
    case 0x800BE3E0u: goto label_800BE3E0;
    case 0x800BE3E4u: goto label_800BE3E4;
    case 0x800BE3E8u: goto label_800BE3E8;
    case 0x800BE3ECu: goto label_800BE3EC;
    case 0x800BE3F0u: goto label_800BE3F0;
    case 0x800BE3F4u: goto label_800BE3F4;
    case 0x800BE3F8u: goto label_800BE3F8;
    case 0x800BE3FCu: goto label_800BE3FC;
    case 0x800BE400u: goto label_800BE400;
    case 0x800BE404u: goto label_800BE404;
    case 0x800BE408u: goto label_800BE408;
    case 0x800BE40Cu: goto label_800BE40C;
    case 0x800BE410u: goto label_800BE410;
    case 0x800BE414u: goto label_800BE414;
    case 0x800BE418u: goto label_800BE418;
    case 0x800BE41Cu: goto label_800BE41C;
    case 0x800BE420u: goto label_800BE420;
    case 0x800BE424u: goto label_800BE424;
    case 0x800BE428u: goto label_800BE428;
    case 0x800BE42Cu: goto label_800BE42C;
    case 0x800BE430u: goto label_800BE430;
    case 0x800BE434u: goto label_800BE434;
    case 0x800BE438u: goto label_800BE438;
    case 0x800BE43Cu: goto label_800BE43C;
    case 0x800BE440u: goto label_800BE440;
    case 0x800BE444u: goto label_800BE444;
    case 0x800BE448u: goto label_800BE448;
    case 0x800BE44Cu: goto label_800BE44C;
    case 0x800BE450u: goto label_800BE450;
    case 0x800BE454u: goto label_800BE454;
    case 0x800BE458u: goto label_800BE458;
    case 0x800BE45Cu: goto label_800BE45C;
    case 0x800BE460u: goto label_800BE460;
    case 0x800BE464u: goto label_800BE464;
    case 0x800BE468u: goto label_800BE468;
    case 0x800BE46Cu: goto label_800BE46C;
    case 0x800BE470u: goto label_800BE470;
    case 0x800BE474u: goto label_800BE474;
    case 0x800BE478u: goto label_800BE478;
    case 0x800BE47Cu: goto label_800BE47C;
    case 0x800BE480u: goto label_800BE480;
    case 0x800BE484u: goto label_800BE484;
    case 0x800BE488u: goto label_800BE488;
    case 0x800BE48Cu: goto label_800BE48C;
    case 0x800BE490u: goto label_800BE490;
    case 0x800BE494u: goto label_800BE494;
    case 0x800BE498u: goto label_800BE498;
    case 0x800BE49Cu: goto label_800BE49C;
    case 0x800BE4A0u: goto label_800BE4A0;
    case 0x800BE4A4u: goto label_800BE4A4;
    case 0x800BE4A8u: goto label_800BE4A8;
    case 0x800BE4ACu: goto label_800BE4AC;
    case 0x800BE4B0u: goto label_800BE4B0;
    case 0x800BE4B4u: goto label_800BE4B4;
    case 0x800BE4B8u: goto label_800BE4B8;
    case 0x800BE4BCu: goto label_800BE4BC;
    case 0x800BE4C0u: goto label_800BE4C0;
    case 0x800BE4C4u: goto label_800BE4C4;
    case 0x800BE4C8u: goto label_800BE4C8;
    case 0x800BE4CCu: goto label_800BE4CC;
    case 0x800BE4D0u: goto label_800BE4D0;
    case 0x800BE4D4u: goto label_800BE4D4;
    case 0x800BE4D8u: goto label_800BE4D8;
    case 0x800BE4DCu: goto label_800BE4DC;
    case 0x800BE4E0u: goto label_800BE4E0;
    case 0x800BE4E4u: goto label_800BE4E4;
    case 0x800BE4E8u: goto label_800BE4E8;
    case 0x800BE4ECu: goto label_800BE4EC;
    case 0x800BE4F0u: goto label_800BE4F0;
    case 0x800BE4F4u: goto label_800BE4F4;
    case 0x800BE4F8u: goto label_800BE4F8;
    case 0x800BE4FCu: goto label_800BE4FC;
    case 0x800BE500u: goto label_800BE500;
    case 0x800BE504u: goto label_800BE504;
    case 0x800BE508u: goto label_800BE508;
    case 0x800BE50Cu: goto label_800BE50C;
    case 0x800BE510u: goto label_800BE510;
    case 0x800BE514u: goto label_800BE514;
    case 0x800BE518u: goto label_800BE518;
    case 0x800BE51Cu: goto label_800BE51C;
    case 0x800BE520u: goto label_800BE520;
    case 0x800BE524u: goto label_800BE524;
    case 0x800BE528u: goto label_800BE528;
    case 0x800BE52Cu: goto label_800BE52C;
    case 0x800BE530u: goto label_800BE530;
    case 0x800BE534u: goto label_800BE534;
    case 0x800BE538u: goto label_800BE538;
    case 0x800BE53Cu: goto label_800BE53C;
    case 0x800BE540u: goto label_800BE540;
    case 0x800BE544u: goto label_800BE544;
    case 0x800BE548u: goto label_800BE548;
    case 0x800BE54Cu: goto label_800BE54C;
    case 0x800BE550u: goto label_800BE550;
    case 0x800BE554u: goto label_800BE554;
    case 0x800BE558u: goto label_800BE558;
    case 0x800BE55Cu: goto label_800BE55C;
    case 0x800BE560u: goto label_800BE560;
    case 0x800BE564u: goto label_800BE564;
    case 0x800BE568u: goto label_800BE568;
    case 0x800BE56Cu: goto label_800BE56C;
    case 0x800BE570u: goto label_800BE570;
    case 0x800BE574u: goto label_800BE574;
    case 0x800BE578u: goto label_800BE578;
    case 0x800BE57Cu: goto label_800BE57C;
    case 0x800BE580u: goto label_800BE580;
    case 0x800BE584u: goto label_800BE584;
    case 0x800BE588u: goto label_800BE588;
    case 0x800BE58Cu: goto label_800BE58C;
    case 0x800BE590u: goto label_800BE590;
    case 0x800BE594u: goto label_800BE594;
    case 0x800BE598u: goto label_800BE598;
    case 0x800BE59Cu: goto label_800BE59C;
    case 0x800BE5A0u: goto label_800BE5A0;
    case 0x800BE5A4u: goto label_800BE5A4;
    case 0x800BE5A8u: goto label_800BE5A8;
    case 0x800BE5ACu: goto label_800BE5AC;
    case 0x800BE5B0u: goto label_800BE5B0;
    case 0x800BE5B4u: goto label_800BE5B4;
    case 0x800BE5B8u: goto label_800BE5B8;
    case 0x800BE5BCu: goto label_800BE5BC;
    case 0x800BE5C0u: goto label_800BE5C0;
    case 0x800BE5C4u: goto label_800BE5C4;
    case 0x800BE5C8u: goto label_800BE5C8;
    case 0x800BE5CCu: goto label_800BE5CC;
    case 0x800BE5D0u: goto label_800BE5D0;
    case 0x800BE5D4u: goto label_800BE5D4;
    case 0x800BE5D8u: goto label_800BE5D8;
    case 0x800BE5DCu: goto label_800BE5DC;
    case 0x800BE5E0u: goto label_800BE5E0;
    case 0x800BE5E4u: goto label_800BE5E4;
    case 0x800BE5E8u: goto label_800BE5E8;
    case 0x800BE5ECu: goto label_800BE5EC;
    case 0x800BE5F0u: goto label_800BE5F0;
    case 0x800BE5F4u: goto label_800BE5F4;
    case 0x800BE5F8u: goto label_800BE5F8;
    case 0x800BE5FCu: goto label_800BE5FC;
    case 0x800BE600u: goto label_800BE600;
    case 0x800BE604u: goto label_800BE604;
    case 0x800BE608u: goto label_800BE608;
    case 0x800BE60Cu: goto label_800BE60C;
    case 0x800BE610u: goto label_800BE610;
    case 0x800BE614u: goto label_800BE614;
    case 0x800BE618u: goto label_800BE618;
    case 0x800BE61Cu: goto label_800BE61C;
    case 0x800BE620u: goto label_800BE620;
    case 0x800BE624u: goto label_800BE624;
    case 0x800BE628u: goto label_800BE628;
    case 0x800BE62Cu: goto label_800BE62C;
    case 0x800BE630u: goto label_800BE630;
    case 0x800BE634u: goto label_800BE634;
    case 0x800BE638u: goto label_800BE638;
    case 0x800BE63Cu: goto label_800BE63C;
    case 0x800BE640u: goto label_800BE640;
    case 0x800BE644u: goto label_800BE644;
    case 0x800BE648u: goto label_800BE648;
    case 0x800BE64Cu: goto label_800BE64C;
    case 0x800BE650u: goto label_800BE650;
    case 0x800BE654u: goto label_800BE654;
    case 0x800BE658u: goto label_800BE658;
    case 0x800BE65Cu: goto label_800BE65C;
    case 0x800BE660u: goto label_800BE660;
    case 0x800BE664u: goto label_800BE664;
    case 0x800BE668u: goto label_800BE668;
    case 0x800BE66Cu: goto label_800BE66C;
    case 0x800BE670u: goto label_800BE670;
    case 0x800BE674u: goto label_800BE674;
    case 0x800BE678u: goto label_800BE678;
    case 0x800BE67Cu: goto label_800BE67C;
    case 0x800BE680u: goto label_800BE680;
    case 0x800BE684u: goto label_800BE684;
    case 0x800BE688u: goto label_800BE688;
    case 0x800BE68Cu: goto label_800BE68C;
    case 0x800BE690u: goto label_800BE690;
    case 0x800BE694u: goto label_800BE694;
    case 0x800BE698u: goto label_800BE698;
    case 0x800BE69Cu: goto label_800BE69C;
    case 0x800BE6A0u: goto label_800BE6A0;
    case 0x800BE6A4u: goto label_800BE6A4;
    case 0x800BE6A8u: goto label_800BE6A8;
    case 0x800BE6ACu: goto label_800BE6AC;
    case 0x800BE6B0u: goto label_800BE6B0;
    case 0x800BE6B4u: goto label_800BE6B4;
    case 0x800BE6B8u: goto label_800BE6B8;
    case 0x800BE6BCu: goto label_800BE6BC;
    case 0x800BE6C0u: goto label_800BE6C0;
    case 0x800BE6C4u: goto label_800BE6C4;
    case 0x800BE6C8u: goto label_800BE6C8;
    case 0x800BE6CCu: goto label_800BE6CC;
    case 0x800BE6D0u: goto label_800BE6D0;
    case 0x800BE6D4u: goto label_800BE6D4;
    case 0x800BE6D8u: goto label_800BE6D8;
    case 0x800BE6DCu: goto label_800BE6DC;
    case 0x800BE6E0u: goto label_800BE6E0;
    case 0x800BE6E4u: goto label_800BE6E4;
    case 0x800BE6E8u: goto label_800BE6E8;
    case 0x800BE6ECu: goto label_800BE6EC;
    case 0x800BE6F0u: goto label_800BE6F0;
    case 0x800BE6F4u: goto label_800BE6F4;
    case 0x800BE6F8u: goto label_800BE6F8;
    case 0x800BE6FCu: goto label_800BE6FC;
    case 0x800BE700u: goto label_800BE700;
    case 0x800BE704u: goto label_800BE704;
    case 0x800BE708u: goto label_800BE708;
    case 0x800BE70Cu: goto label_800BE70C;
    case 0x800BE710u: goto label_800BE710;
    case 0x800BE714u: goto label_800BE714;
    case 0x800BE718u: goto label_800BE718;
    case 0x800BE71Cu: goto label_800BE71C;
    case 0x800BE720u: goto label_800BE720;
    case 0x800BE724u: goto label_800BE724;
    case 0x800BE728u: goto label_800BE728;
    case 0x800BE72Cu: goto label_800BE72C;
    case 0x800BE730u: goto label_800BE730;
    case 0x800BE734u: goto label_800BE734;
    case 0x800BE738u: goto label_800BE738;
    case 0x800BE73Cu: goto label_800BE73C;
    case 0x800BE740u: goto label_800BE740;
    case 0x800BE744u: goto label_800BE744;
    case 0x800BE748u: goto label_800BE748;
    case 0x800BE74Cu: goto label_800BE74C;
    case 0x800BE750u: goto label_800BE750;
    case 0x800BE754u: goto label_800BE754;
    case 0x800BE758u: goto label_800BE758;
    case 0x800BE75Cu: goto label_800BE75C;
    case 0x800BE760u: goto label_800BE760;
    case 0x800BE764u: goto label_800BE764;
    case 0x800BE768u: goto label_800BE768;
    case 0x800BE76Cu: goto label_800BE76C;
    case 0x800BE770u: goto label_800BE770;
    case 0x800BE774u: goto label_800BE774;
    case 0x800BE778u: goto label_800BE778;
    case 0x800BE77Cu: goto label_800BE77C;
    case 0x800BE780u: goto label_800BE780;
    case 0x800BE784u: goto label_800BE784;
    case 0x800BE788u: goto label_800BE788;
    case 0x800BE78Cu: goto label_800BE78C;
    case 0x800BE790u: goto label_800BE790;
    case 0x800BE794u: goto label_800BE794;
    case 0x800BE798u: goto label_800BE798;
    case 0x800BE79Cu: goto label_800BE79C;
    case 0x800BE7A0u: goto label_800BE7A0;
    case 0x800BE7A4u: goto label_800BE7A4;
    case 0x800BE7A8u: goto label_800BE7A8;
    case 0x800BE7ACu: goto label_800BE7AC;
    case 0x800BE7B0u: goto label_800BE7B0;
    case 0x800BE7B4u: goto label_800BE7B4;
    case 0x800BE7B8u: goto label_800BE7B8;
    case 0x800BE7BCu: goto label_800BE7BC;
    case 0x800BE7C0u: goto label_800BE7C0;
    case 0x800BE7C4u: goto label_800BE7C4;
    case 0x800BE7C8u: goto label_800BE7C8;
    case 0x800BE7CCu: goto label_800BE7CC;
    case 0x800BE7D0u: goto label_800BE7D0;
    case 0x800BE7D4u: goto label_800BE7D4;
    case 0x800BE7D8u: goto label_800BE7D8;
    case 0x800BE7DCu: goto label_800BE7DC;
    case 0x800BE7E0u: goto label_800BE7E0;
    case 0x800BE7E4u: goto label_800BE7E4;
    case 0x800BE7E8u: goto label_800BE7E8;
    case 0x800BE7ECu: goto label_800BE7EC;
    case 0x800BE7F0u: goto label_800BE7F0;
    case 0x800BE7F4u: goto label_800BE7F4;
    case 0x800BE7F8u: goto label_800BE7F8;
    case 0x800BE7FCu: goto label_800BE7FC;
    case 0x800BE800u: goto label_800BE800;
    case 0x800BE804u: goto label_800BE804;
    case 0x800BE808u: goto label_800BE808;
    case 0x800BE80Cu: goto label_800BE80C;
    case 0x800BE810u: goto label_800BE810;
    case 0x800BE814u: goto label_800BE814;
    case 0x800BE818u: goto label_800BE818;
    case 0x800BE81Cu: goto label_800BE81C;
    case 0x800BE820u: goto label_800BE820;
    case 0x800BE824u: goto label_800BE824;
    case 0x800BE828u: goto label_800BE828;
    case 0x800BE82Cu: goto label_800BE82C;
    case 0x800BE830u: goto label_800BE830;
    case 0x800BE834u: goto label_800BE834;
    case 0x800BE838u: goto label_800BE838;
    case 0x800BE83Cu: goto label_800BE83C;
    case 0x800BE840u: goto label_800BE840;
    case 0x800BE844u: goto label_800BE844;
    case 0x800BE848u: goto label_800BE848;
    case 0x800BE84Cu: goto label_800BE84C;
    case 0x800BE850u: goto label_800BE850;
    case 0x800BE854u: goto label_800BE854;
    case 0x800BE858u: goto label_800BE858;
    case 0x800BE85Cu: goto label_800BE85C;
    case 0x800BE860u: goto label_800BE860;
    case 0x800BE864u: goto label_800BE864;
    case 0x800BE868u: goto label_800BE868;
    case 0x800BE86Cu: goto label_800BE86C;
    case 0x800BE870u: goto label_800BE870;
    case 0x800BE874u: goto label_800BE874;
    case 0x800BE878u: goto label_800BE878;
    case 0x800BE87Cu: goto label_800BE87C;
    case 0x800BE880u: goto label_800BE880;
    case 0x800BE884u: goto label_800BE884;
    case 0x800BE888u: goto label_800BE888;
    case 0x800BE88Cu: goto label_800BE88C;
    case 0x800BE890u: goto label_800BE890;
    case 0x800BE894u: goto label_800BE894;
    case 0x800BE898u: goto label_800BE898;
    case 0x800BE89Cu: goto label_800BE89C;
    case 0x800BE8A0u: goto label_800BE8A0;
    case 0x800BE8A4u: goto label_800BE8A4;
    case 0x800BE8A8u: goto label_800BE8A8;
    case 0x800BE8ACu: goto label_800BE8AC;
    case 0x800BE8B0u: goto label_800BE8B0;
    case 0x800BE8B4u: goto label_800BE8B4;
    case 0x800BE8B8u: goto label_800BE8B8;
    case 0x800BE8BCu: goto label_800BE8BC;
    case 0x800BE8C0u: goto label_800BE8C0;
    case 0x800BE8C4u: goto label_800BE8C4;
    case 0x800BE8C8u: goto label_800BE8C8;
    case 0x800BE8CCu: goto label_800BE8CC;
    case 0x800BE8D0u: goto label_800BE8D0;
    case 0x800BE8D4u: goto label_800BE8D4;
    case 0x800BE8D8u: goto label_800BE8D8;
    case 0x800BE8DCu: goto label_800BE8DC;
    case 0x800BE8E0u: goto label_800BE8E0;
    case 0x800BE8E4u: goto label_800BE8E4;
    case 0x800BE8E8u: goto label_800BE8E8;
    case 0x800BE8ECu: goto label_800BE8EC;
    case 0x800BE8F0u: goto label_800BE8F0;
    case 0x800BE8F4u: goto label_800BE8F4;
    case 0x800BE8F8u: goto label_800BE8F8;
    case 0x800BE8FCu: goto label_800BE8FC;
    case 0x800BE900u: goto label_800BE900;
    case 0x800BE904u: goto label_800BE904;
    case 0x800BE908u: goto label_800BE908;
    case 0x800BE90Cu: goto label_800BE90C;
    case 0x800BE910u: goto label_800BE910;
    case 0x800BE914u: goto label_800BE914;
    case 0x800BE918u: goto label_800BE918;
    case 0x800BE91Cu: goto label_800BE91C;
    case 0x800BE920u: goto label_800BE920;
    case 0x800BE924u: goto label_800BE924;
    case 0x800BE928u: goto label_800BE928;
    case 0x800BE92Cu: goto label_800BE92C;
    case 0x800BE930u: goto label_800BE930;
    case 0x800BE934u: goto label_800BE934;
    case 0x800BE938u: goto label_800BE938;
    case 0x800BE93Cu: goto label_800BE93C;
    case 0x800BE940u: goto label_800BE940;
    case 0x800BE944u: goto label_800BE944;
    case 0x800BE948u: goto label_800BE948;
    case 0x800BE94Cu: goto label_800BE94C;
    case 0x800BE950u: goto label_800BE950;
    case 0x800BE954u: goto label_800BE954;
    case 0x800BE958u: goto label_800BE958;
    case 0x800BE95Cu: goto label_800BE95C;
    case 0x800BE960u: goto label_800BE960;
    case 0x800BE964u: goto label_800BE964;
    case 0x800BE968u: goto label_800BE968;
    case 0x800BE96Cu: goto label_800BE96C;
    case 0x800BE970u: goto label_800BE970;
    case 0x800BE974u: goto label_800BE974;
    case 0x800BE978u: goto label_800BE978;
    case 0x800BE97Cu: goto label_800BE97C;
    case 0x800BE980u: goto label_800BE980;
    case 0x800BE984u: goto label_800BE984;
    case 0x800BE988u: goto label_800BE988;
    case 0x800BE98Cu: goto label_800BE98C;
    case 0x800BE990u: goto label_800BE990;
    case 0x800BE994u: goto label_800BE994;
    case 0x800BE998u: goto label_800BE998;
    case 0x800BE99Cu: goto label_800BE99C;
    case 0x800BE9A0u: goto label_800BE9A0;
    case 0x800BE9A4u: goto label_800BE9A4;
    case 0x800BE9A8u: goto label_800BE9A8;
    case 0x800BE9ACu: goto label_800BE9AC;
    case 0x800BE9B0u: goto label_800BE9B0;
    case 0x800BE9B4u: goto label_800BE9B4;
    case 0x800BE9B8u: goto label_800BE9B8;
    case 0x800BE9BCu: goto label_800BE9BC;
    case 0x800BE9C0u: goto label_800BE9C0;
    case 0x800BE9C4u: goto label_800BE9C4;
    case 0x800BE9C8u: goto label_800BE9C8;
    case 0x800BE9CCu: goto label_800BE9CC;
    case 0x800BE9D0u: goto label_800BE9D0;
    case 0x800BE9D4u: goto label_800BE9D4;
    case 0x800BE9D8u: goto label_800BE9D8;
    case 0x800BE9DCu: goto label_800BE9DC;
    case 0x800BE9E0u: goto label_800BE9E0;
    case 0x800BE9E4u: goto label_800BE9E4;
    case 0x800BE9E8u: goto label_800BE9E8;
    case 0x800BE9ECu: goto label_800BE9EC;
    case 0x800BE9F0u: goto label_800BE9F0;
    case 0x800BE9F4u: goto label_800BE9F4;
    case 0x800BE9F8u: goto label_800BE9F8;
    case 0x800BE9FCu: goto label_800BE9FC;
    case 0x800BEA00u: goto label_800BEA00;
    case 0x800BEA04u: goto label_800BEA04;
    case 0x800BEA08u: goto label_800BEA08;
    case 0x800BEA0Cu: goto label_800BEA0C;
    case 0x800BEA10u: goto label_800BEA10;
    case 0x800BEA14u: goto label_800BEA14;
    case 0x800BEA18u: goto label_800BEA18;
    case 0x800BEA1Cu: goto label_800BEA1C;
    case 0x800BEA20u: goto label_800BEA20;
    case 0x800BEA24u: goto label_800BEA24;
    case 0x800BEA28u: goto label_800BEA28;
    case 0x800BEA2Cu: goto label_800BEA2C;
    case 0x800BEA30u: goto label_800BEA30;
    case 0x800BEA34u: goto label_800BEA34;
    case 0x800BEA38u: goto label_800BEA38;
    case 0x800BEA3Cu: goto label_800BEA3C;
    case 0x800BEA40u: goto label_800BEA40;
    case 0x800BEA44u: goto label_800BEA44;
    case 0x800BEA48u: goto label_800BEA48;
    case 0x800BEA4Cu: goto label_800BEA4C;
    case 0x800BEA50u: goto label_800BEA50;
    case 0x800BEA54u: goto label_800BEA54;
    case 0x800BEA58u: goto label_800BEA58;
    case 0x800BEA5Cu: goto label_800BEA5C;
    case 0x800BEA60u: goto label_800BEA60;
    case 0x800BEA64u: goto label_800BEA64;
    case 0x800BEA68u: goto label_800BEA68;
    case 0x800BEA6Cu: goto label_800BEA6C;
    case 0x800BEA70u: goto label_800BEA70;
    case 0x800BEA74u: goto label_800BEA74;
    case 0x800BEA78u: goto label_800BEA78;
    case 0x800BEA7Cu: goto label_800BEA7C;
    case 0x800BEA80u: goto label_800BEA80;
    case 0x800BEA84u: goto label_800BEA84;
    case 0x800BEA88u: goto label_800BEA88;
    case 0x800BEA8Cu: goto label_800BEA8C;
    case 0x800BEA90u: goto label_800BEA90;
    case 0x800BEA94u: goto label_800BEA94;
    case 0x800BEA98u: goto label_800BEA98;
    case 0x800BEA9Cu: goto label_800BEA9C;
    case 0x800BEAA0u: goto label_800BEAA0;
    case 0x800BEAA4u: goto label_800BEAA4;
    case 0x800BEAA8u: goto label_800BEAA8;
    case 0x800BEAACu: goto label_800BEAAC;
    case 0x800BEAB0u: goto label_800BEAB0;
    case 0x800BEAB4u: goto label_800BEAB4;
    case 0x800BEAB8u: goto label_800BEAB8;
    case 0x800BEABCu: goto label_800BEABC;
    case 0x800BEAC0u: goto label_800BEAC0;
    case 0x800BEAC4u: goto label_800BEAC4;
    case 0x800BEAC8u: goto label_800BEAC8;
    case 0x800BEACCu: goto label_800BEACC;
    case 0x800BEAD0u: goto label_800BEAD0;
    case 0x800BEAD4u: goto label_800BEAD4;
    case 0x800BEAD8u: goto label_800BEAD8;
    case 0x800BEADCu: goto label_800BEADC;
    case 0x800BEAE0u: goto label_800BEAE0;
    case 0x800BEAE4u: goto label_800BEAE4;
    case 0x800BEAE8u: goto label_800BEAE8;
    case 0x800BEAECu: goto label_800BEAEC;
    case 0x800BEAF0u: goto label_800BEAF0;
    case 0x800BEAF4u: goto label_800BEAF4;
    case 0x800BEAF8u: goto label_800BEAF8;
    case 0x800BEAFCu: goto label_800BEAFC;
    case 0x800BEB00u: goto label_800BEB00;
    case 0x800BEB04u: goto label_800BEB04;
    case 0x800BEB08u: goto label_800BEB08;
    case 0x800BEB0Cu: goto label_800BEB0C;
    case 0x800BEB10u: goto label_800BEB10;
    case 0x800BEB14u: goto label_800BEB14;
    case 0x800BEB18u: goto label_800BEB18;
    case 0x800BEB1Cu: goto label_800BEB1C;
    case 0x800BEB20u: goto label_800BEB20;
    case 0x800BEB24u: goto label_800BEB24;
    case 0x800BEB28u: goto label_800BEB28;
    case 0x800BEB2Cu: goto label_800BEB2C;
    case 0x800BEB30u: goto label_800BEB30;
    case 0x800BEB34u: goto label_800BEB34;
    case 0x800BEB38u: goto label_800BEB38;
    case 0x800BEB3Cu: goto label_800BEB3C;
    case 0x800BEB40u: goto label_800BEB40;
    case 0x800BEB44u: goto label_800BEB44;
    case 0x800BEB48u: goto label_800BEB48;
    case 0x800BEB4Cu: goto label_800BEB4C;
    case 0x800BEB50u: goto label_800BEB50;
    case 0x800BEB54u: goto label_800BEB54;
    case 0x800BEB58u: goto label_800BEB58;
    case 0x800BEB5Cu: goto label_800BEB5C;
    case 0x800BEB60u: goto label_800BEB60;
    case 0x800BEB64u: goto label_800BEB64;
    case 0x800BEB68u: goto label_800BEB68;
    case 0x800BEB6Cu: goto label_800BEB6C;
    case 0x800BEB70u: goto label_800BEB70;
    case 0x800BEB74u: goto label_800BEB74;
    case 0x800BEB78u: goto label_800BEB78;
    case 0x800BEB7Cu: goto label_800BEB7C;
    case 0x800BEB80u: goto label_800BEB80;
    case 0x800BEB84u: goto label_800BEB84;
    case 0x800BEB88u: goto label_800BEB88;
    case 0x800BEB8Cu: goto label_800BEB8C;
    case 0x800BEB90u: goto label_800BEB90;
    case 0x800BEB94u: goto label_800BEB94;
    case 0x800BEB98u: goto label_800BEB98;
    case 0x800BEB9Cu: goto label_800BEB9C;
    case 0x800BEBA0u: goto label_800BEBA0;
    case 0x800BEBA4u: goto label_800BEBA4;
    case 0x800BEBA8u: goto label_800BEBA8;
    case 0x800BEBACu: goto label_800BEBAC;
    case 0x800BEBB0u: goto label_800BEBB0;
    case 0x800BEBB4u: goto label_800BEBB4;
    case 0x800BEBB8u: goto label_800BEBB8;
    case 0x800BEBBCu: goto label_800BEBBC;
    case 0x800BEBC0u: goto label_800BEBC0;
    case 0x800BEBC4u: goto label_800BEBC4;
    case 0x800BEBC8u: goto label_800BEBC8;
    case 0x800BEBCCu: goto label_800BEBCC;
    case 0x800BEBD0u: goto label_800BEBD0;
    case 0x800BEBD4u: goto label_800BEBD4;
    case 0x800BEBD8u: goto label_800BEBD8;
    case 0x800BEBDCu: goto label_800BEBDC;
    case 0x800BEBE0u: goto label_800BEBE0;
    case 0x800BEBE4u: goto label_800BEBE4;
    case 0x800BEBE8u: goto label_800BEBE8;
    case 0x800BEBECu: goto label_800BEBEC;
    case 0x800BEBF0u: goto label_800BEBF0;
    case 0x800BEBF4u: goto label_800BEBF4;
    case 0x800BEBF8u: goto label_800BEBF8;
    case 0x800BEBFCu: goto label_800BEBFC;
    case 0x800BEC00u: goto label_800BEC00;
    case 0x800BEC04u: goto label_800BEC04;
    case 0x800BEC08u: goto label_800BEC08;
    case 0x800BEC0Cu: goto label_800BEC0C;
    case 0x800BEC10u: goto label_800BEC10;
    case 0x800BEC14u: goto label_800BEC14;
    case 0x800BEC18u: goto label_800BEC18;
    case 0x800BEC1Cu: goto label_800BEC1C;
    case 0x800BEC20u: goto label_800BEC20;
    case 0x800BEC24u: goto label_800BEC24;
    case 0x800BEC28u: goto label_800BEC28;
    case 0x800BEC2Cu: goto label_800BEC2C;
    case 0x800BEC30u: goto label_800BEC30;
    case 0x800BEC34u: goto label_800BEC34;
    case 0x800BEC38u: goto label_800BEC38;
    case 0x800BEC3Cu: goto label_800BEC3C;
    case 0x800BEC40u: goto label_800BEC40;
    case 0x800BEC44u: goto label_800BEC44;
    case 0x800BEC48u: goto label_800BEC48;
    case 0x800BEC4Cu: goto label_800BEC4C;
    case 0x800BEC50u: goto label_800BEC50;
    case 0x800BEC54u: goto label_800BEC54;
    case 0x800BEC58u: goto label_800BEC58;
    case 0x800BEC5Cu: goto label_800BEC5C;
    case 0x800BEC60u: goto label_800BEC60;
    case 0x800BEC64u: goto label_800BEC64;
    case 0x800BEC68u: goto label_800BEC68;
    case 0x800BEC6Cu: goto label_800BEC6C;
    case 0x800BEC70u: goto label_800BEC70;
    case 0x800BEC74u: goto label_800BEC74;
    case 0x800BEC78u: goto label_800BEC78;
    case 0x800BEC7Cu: goto label_800BEC7C;
    case 0x800BEC80u: goto label_800BEC80;
    case 0x800BEC84u: goto label_800BEC84;
    case 0x800BEC88u: goto label_800BEC88;
    case 0x800BEC8Cu: goto label_800BEC8C;
    case 0x800BEC90u: goto label_800BEC90;
    case 0x800BEC94u: goto label_800BEC94;
    case 0x800BEC98u: goto label_800BEC98;
    case 0x800BEC9Cu: goto label_800BEC9C;
    case 0x800BECA0u: goto label_800BECA0;
    case 0x800BECA4u: goto label_800BECA4;
    case 0x800BECA8u: goto label_800BECA8;
    case 0x800BECACu: goto label_800BECAC;
    case 0x800BECB0u: goto label_800BECB0;
    case 0x800BECB4u: goto label_800BECB4;
    case 0x800BECB8u: goto label_800BECB8;
    case 0x800BECBCu: goto label_800BECBC;
    case 0x800BECC0u: goto label_800BECC0;
    case 0x800BECC4u: goto label_800BECC4;
    case 0x800BECC8u: goto label_800BECC8;
    case 0x800BECCCu: goto label_800BECCC;
    case 0x800BECD0u: goto label_800BECD0;
    case 0x800BECD4u: goto label_800BECD4;
    case 0x800BECD8u: goto label_800BECD8;
    case 0x800BECDCu: goto label_800BECDC;
    case 0x800BECE0u: goto label_800BECE0;
    case 0x800BECE4u: goto label_800BECE4;
    case 0x800BECE8u: goto label_800BECE8;
    case 0x800BECECu: goto label_800BECEC;
    case 0x800BECF0u: goto label_800BECF0;
    case 0x800BECF4u: goto label_800BECF4;
    case 0x800BECF8u: goto label_800BECF8;
    case 0x800BECFCu: goto label_800BECFC;
    case 0x800BED00u: goto label_800BED00;
    case 0x800BED04u: goto label_800BED04;
    case 0x800BED08u: goto label_800BED08;
    case 0x800BED0Cu: goto label_800BED0C;
    case 0x800BED10u: goto label_800BED10;
    case 0x800BED14u: goto label_800BED14;
    case 0x800BED18u: goto label_800BED18;
    case 0x800BED1Cu: goto label_800BED1C;
    case 0x800BED20u: goto label_800BED20;
    case 0x800BED24u: goto label_800BED24;
    case 0x800BED28u: goto label_800BED28;
    case 0x800BED2Cu: goto label_800BED2C;
    case 0x800BED30u: goto label_800BED30;
    case 0x800BED34u: goto label_800BED34;
    case 0x800BED38u: goto label_800BED38;
    case 0x800BED3Cu: goto label_800BED3C;
    case 0x800BED40u: goto label_800BED40;
    case 0x800BED44u: goto label_800BED44;
    case 0x800BED48u: goto label_800BED48;
    case 0x800BED4Cu: goto label_800BED4C;
    case 0x800BED50u: goto label_800BED50;
    case 0x800BED54u: goto label_800BED54;
    case 0x800BED58u: goto label_800BED58;
    case 0x800BED5Cu: goto label_800BED5C;
    case 0x800BED60u: goto label_800BED60;
    case 0x800BED64u: goto label_800BED64;
    case 0x800BED68u: goto label_800BED68;
    case 0x800BED6Cu: goto label_800BED6C;
    case 0x800BED70u: goto label_800BED70;
    case 0x800BED74u: goto label_800BED74;
    case 0x800BED78u: goto label_800BED78;
    case 0x800BED7Cu: goto label_800BED7C;
    case 0x800BED80u: goto label_800BED80;
    case 0x800BED84u: goto label_800BED84;
    case 0x800BED88u: goto label_800BED88;
    case 0x800BED8Cu: goto label_800BED8C;
    case 0x800BED90u: goto label_800BED90;
    case 0x800BED94u: goto label_800BED94;
    case 0x800BED98u: goto label_800BED98;
    case 0x800BED9Cu: goto label_800BED9C;
    case 0x800BEDA0u: goto label_800BEDA0;
    case 0x800BEDA4u: goto label_800BEDA4;
    case 0x800BEDA8u: goto label_800BEDA8;
    case 0x800BEDACu: goto label_800BEDAC;
    case 0x800BEDB0u: goto label_800BEDB0;
    case 0x800BEDB4u: goto label_800BEDB4;
    case 0x800BEDB8u: goto label_800BEDB8;
    case 0x800BEDBCu: goto label_800BEDBC;
    case 0x800BEDC0u: goto label_800BEDC0;
    case 0x800BEDC4u: goto label_800BEDC4;
    case 0x800BEDC8u: goto label_800BEDC8;
    case 0x800BEDCCu: goto label_800BEDCC;
    case 0x800BEDD0u: goto label_800BEDD0;
    case 0x800BEDD4u: goto label_800BEDD4;
    case 0x800BEDD8u: goto label_800BEDD8;
    case 0x800BEDDCu: goto label_800BEDDC;
    case 0x800BEDE0u: goto label_800BEDE0;
    case 0x800BEDE4u: goto label_800BEDE4;
    case 0x800BEDE8u: goto label_800BEDE8;
    case 0x800BEDECu: goto label_800BEDEC;
    case 0x800BEDF0u: goto label_800BEDF0;
    case 0x800BEDF4u: goto label_800BEDF4;
    case 0x800BEDF8u: goto label_800BEDF8;
    case 0x800BEDFCu: goto label_800BEDFC;
    case 0x800BEE00u: goto label_800BEE00;
    case 0x800BEE04u: goto label_800BEE04;
    case 0x800BEE08u: goto label_800BEE08;
    case 0x800BEE0Cu: goto label_800BEE0C;
    case 0x800BEE10u: goto label_800BEE10;
    case 0x800BEE14u: goto label_800BEE14;
    case 0x800BEE18u: goto label_800BEE18;
    case 0x800BEE1Cu: goto label_800BEE1C;
    case 0x800BEE20u: goto label_800BEE20;
    case 0x800BEE24u: goto label_800BEE24;
    case 0x800BEE28u: goto label_800BEE28;
    case 0x800BEE2Cu: goto label_800BEE2C;
    case 0x800BEE30u: goto label_800BEE30;
    case 0x800BEE34u: goto label_800BEE34;
    case 0x800BEE38u: goto label_800BEE38;
    case 0x800BEE3Cu: goto label_800BEE3C;
    case 0x800BEE40u: goto label_800BEE40;
    case 0x800BEE44u: goto label_800BEE44;
    case 0x800BEE48u: goto label_800BEE48;
    case 0x800BEE4Cu: goto label_800BEE4C;
    case 0x800BEE50u: goto label_800BEE50;
    case 0x800BEE54u: goto label_800BEE54;
    case 0x800BEE58u: goto label_800BEE58;
    case 0x800BEE5Cu: goto label_800BEE5C;
    case 0x800BEE60u: goto label_800BEE60;
    case 0x800BEE64u: goto label_800BEE64;
    case 0x800BEE68u: goto label_800BEE68;
    case 0x800BEE6Cu: goto label_800BEE6C;
    case 0x800BEE70u: goto label_800BEE70;
    case 0x800BEE74u: goto label_800BEE74;
    case 0x800BEE78u: goto label_800BEE78;
    case 0x800BEE7Cu: goto label_800BEE7C;
    case 0x800BEE80u: goto label_800BEE80;
    case 0x800BEE84u: goto label_800BEE84;
    case 0x800BEE88u: goto label_800BEE88;
    case 0x800BEE8Cu: goto label_800BEE8C;
    case 0x800BEE90u: goto label_800BEE90;
    case 0x800BEE94u: goto label_800BEE94;
    case 0x800BEE98u: goto label_800BEE98;
    case 0x800BEE9Cu: goto label_800BEE9C;
    case 0x800BEEA0u: goto label_800BEEA0;
    case 0x800BEEA4u: goto label_800BEEA4;
    case 0x800BEEA8u: goto label_800BEEA8;
    case 0x800BEEACu: goto label_800BEEAC;
    case 0x800BEEB0u: goto label_800BEEB0;
    case 0x800BEEB4u: goto label_800BEEB4;
    case 0x800BEEB8u: goto label_800BEEB8;
    case 0x800BEEBCu: goto label_800BEEBC;
    case 0x800BEEC0u: goto label_800BEEC0;
    case 0x800BEEC4u: goto label_800BEEC4;
    case 0x800BEEC8u: goto label_800BEEC8;
    case 0x800BEECCu: goto label_800BEECC;
    case 0x800BEED0u: goto label_800BEED0;
    case 0x800BEED4u: goto label_800BEED4;
    case 0x800BEED8u: goto label_800BEED8;
    case 0x800BEEDCu: goto label_800BEEDC;
    case 0x800BEEE0u: goto label_800BEEE0;
    case 0x800BEEE4u: goto label_800BEEE4;
    case 0x800BEEE8u: goto label_800BEEE8;
    case 0x800BEEECu: goto label_800BEEEC;
    case 0x800BEEF0u: goto label_800BEEF0;
    case 0x800BEEF4u: goto label_800BEEF4;
    case 0x800BEEF8u: goto label_800BEEF8;
    case 0x800BEEFCu: goto label_800BEEFC;
    case 0x800BEF00u: goto label_800BEF00;
    case 0x800BEF04u: goto label_800BEF04;
    case 0x800BEF08u: goto label_800BEF08;
    case 0x800BEF0Cu: goto label_800BEF0C;
    case 0x800BEF10u: goto label_800BEF10;
    case 0x800BEF14u: goto label_800BEF14;
    case 0x800BEF18u: goto label_800BEF18;
    case 0x800BEF1Cu: goto label_800BEF1C;
    case 0x800BEF20u: goto label_800BEF20;
    case 0x800BEF24u: goto label_800BEF24;
    case 0x800BEF28u: goto label_800BEF28;
    case 0x800BEF2Cu: goto label_800BEF2C;
    case 0x800BEF30u: goto label_800BEF30;
    case 0x800BEF34u: goto label_800BEF34;
    case 0x800BEF38u: goto label_800BEF38;
    case 0x800BEF3Cu: goto label_800BEF3C;
    case 0x800BEF40u: goto label_800BEF40;
    case 0x800BEF44u: goto label_800BEF44;
    case 0x800BEF48u: goto label_800BEF48;
    case 0x800BEF4Cu: goto label_800BEF4C;
    case 0x800BEF50u: goto label_800BEF50;
    case 0x800BEF54u: goto label_800BEF54;
    case 0x800BEF58u: goto label_800BEF58;
    case 0x800BEF5Cu: goto label_800BEF5C;
    case 0x800BEF60u: goto label_800BEF60;
    case 0x800BEF64u: goto label_800BEF64;
    case 0x800BEF68u: goto label_800BEF68;
    case 0x800BEF6Cu: goto label_800BEF6C;
    case 0x800BEF70u: goto label_800BEF70;
    case 0x800BEF74u: goto label_800BEF74;
    case 0x800BEF78u: goto label_800BEF78;
    case 0x800BEF7Cu: goto label_800BEF7C;
    case 0x800BEF80u: goto label_800BEF80;
    case 0x800BEF84u: goto label_800BEF84;
    case 0x800BEF88u: goto label_800BEF88;
    case 0x800BEF8Cu: goto label_800BEF8C;
    case 0x800BEF90u: goto label_800BEF90;
    case 0x800BEF94u: goto label_800BEF94;
    case 0x800BEF98u: goto label_800BEF98;
    case 0x800BEF9Cu: goto label_800BEF9C;
    case 0x800BEFA0u: goto label_800BEFA0;
    case 0x800BEFA4u: goto label_800BEFA4;
    case 0x800BEFA8u: goto label_800BEFA8;
    case 0x800BEFACu: goto label_800BEFAC;
    case 0x800BEFB0u: goto label_800BEFB0;
    case 0x800BEFB4u: goto label_800BEFB4;
    case 0x800BEFB8u: goto label_800BEFB8;
    case 0x800BEFBCu: goto label_800BEFBC;
    case 0x800BEFC0u: goto label_800BEFC0;
    case 0x800BEFC4u: goto label_800BEFC4;
    case 0x800BEFC8u: goto label_800BEFC8;
    case 0x800BEFCCu: goto label_800BEFCC;
    case 0x800BEFD0u: goto label_800BEFD0;
    case 0x800BEFD4u: goto label_800BEFD4;
    case 0x800BEFD8u: goto label_800BEFD8;
    case 0x800BEFDCu: goto label_800BEFDC;
    case 0x800BEFE0u: goto label_800BEFE0;
    case 0x800BEFE4u: goto label_800BEFE4;
    case 0x800BEFE8u: goto label_800BEFE8;
    case 0x800BEFECu: goto label_800BEFEC;
    case 0x800BEFF0u: goto label_800BEFF0;
    case 0x800BEFF4u: goto label_800BEFF4;
    case 0x800BEFF8u: goto label_800BEFF8;
    case 0x800BEFFCu: goto label_800BEFFC;
    case 0x800BF000u: goto label_800BF000;
    case 0x800BF004u: goto label_800BF004;
    case 0x800BF008u: goto label_800BF008;
    case 0x800BF00Cu: goto label_800BF00C;
    case 0x800BF010u: goto label_800BF010;
    case 0x800BF014u: goto label_800BF014;
    case 0x800BF018u: goto label_800BF018;
    case 0x800BF01Cu: goto label_800BF01C;
    case 0x800BF020u: goto label_800BF020;
    case 0x800BF024u: goto label_800BF024;
    case 0x800BF028u: goto label_800BF028;
    case 0x800BF02Cu: goto label_800BF02C;
    case 0x800BF030u: goto label_800BF030;
    case 0x800BF034u: goto label_800BF034;
    case 0x800BF038u: goto label_800BF038;
    case 0x800BF03Cu: goto label_800BF03C;
    case 0x800BF040u: goto label_800BF040;
    case 0x800BF044u: goto label_800BF044;
    case 0x800BF048u: goto label_800BF048;
    case 0x800BF04Cu: goto label_800BF04C;
    case 0x800BF050u: goto label_800BF050;
    case 0x800BF054u: goto label_800BF054;
    case 0x800BF058u: goto label_800BF058;
    case 0x800BF05Cu: goto label_800BF05C;
    case 0x800BF060u: goto label_800BF060;
    case 0x800BF064u: goto label_800BF064;
    case 0x800BF068u: goto label_800BF068;
    case 0x800BF06Cu: goto label_800BF06C;
    case 0x800BF070u: goto label_800BF070;
    case 0x800BF074u: goto label_800BF074;
    case 0x800BF078u: goto label_800BF078;
    case 0x800BF07Cu: goto label_800BF07C;
    case 0x800BF080u: goto label_800BF080;
    case 0x800BF084u: goto label_800BF084;
    case 0x800BF088u: goto label_800BF088;
    case 0x800BF08Cu: goto label_800BF08C;
    case 0x800BF090u: goto label_800BF090;
    case 0x800BF094u: goto label_800BF094;
    case 0x800BF098u: goto label_800BF098;
    case 0x800BF09Cu: goto label_800BF09C;
    case 0x800BF0A0u: goto label_800BF0A0;
    case 0x800BF0A4u: goto label_800BF0A4;
    case 0x800BF0A8u: goto label_800BF0A8;
    case 0x800BF0ACu: goto label_800BF0AC;
    case 0x800BF0B0u: goto label_800BF0B0;
    case 0x800BF0B4u: goto label_800BF0B4;
    case 0x800BF0B8u: goto label_800BF0B8;
    case 0x800BF0BCu: goto label_800BF0BC;
    case 0x800BF0C0u: goto label_800BF0C0;
    case 0x800BF0C4u: goto label_800BF0C4;
    case 0x800BF0C8u: goto label_800BF0C8;
    case 0x800BF0CCu: goto label_800BF0CC;
    case 0x800BF0D0u: goto label_800BF0D0;
    case 0x800BF0D4u: goto label_800BF0D4;
    case 0x800BF0D8u: goto label_800BF0D8;
    case 0x800BF0DCu: goto label_800BF0DC;
    case 0x800BF0E0u: goto label_800BF0E0;
    case 0x800BF0E4u: goto label_800BF0E4;
    case 0x800BF0E8u: goto label_800BF0E8;
    case 0x800BF0ECu: goto label_800BF0EC;
    case 0x800BF0F0u: goto label_800BF0F0;
    case 0x800BF0F4u: goto label_800BF0F4;
    case 0x800BF0F8u: goto label_800BF0F8;
    case 0x800BF0FCu: goto label_800BF0FC;
    case 0x800BF100u: goto label_800BF100;
    case 0x800BF104u: goto label_800BF104;
    case 0x800BF108u: goto label_800BF108;
    case 0x800BF10Cu: goto label_800BF10C;
    case 0x800BF110u: goto label_800BF110;
    case 0x800BF114u: goto label_800BF114;
    case 0x800BF118u: goto label_800BF118;
    case 0x800BF11Cu: goto label_800BF11C;
    case 0x800BF120u: goto label_800BF120;
    case 0x800BF124u: goto label_800BF124;
    case 0x800BF128u: goto label_800BF128;
    case 0x800BF12Cu: goto label_800BF12C;
    case 0x800BF130u: goto label_800BF130;
    case 0x800BF134u: goto label_800BF134;
    case 0x800BF138u: goto label_800BF138;
    case 0x800BF13Cu: goto label_800BF13C;
    case 0x800BF140u: goto label_800BF140;
    case 0x800BF144u: goto label_800BF144;
    case 0x800BF148u: goto label_800BF148;
    case 0x800BF14Cu: goto label_800BF14C;
    case 0x800BF150u: goto label_800BF150;
    case 0x800BF154u: goto label_800BF154;
    case 0x800BF158u: goto label_800BF158;
    case 0x800BF15Cu: goto label_800BF15C;
    case 0x800BF160u: goto label_800BF160;
    case 0x800BF164u: goto label_800BF164;
    case 0x800BF168u: goto label_800BF168;
    case 0x800BF16Cu: goto label_800BF16C;
    case 0x800BF170u: goto label_800BF170;
    case 0x800BF174u: goto label_800BF174;
    case 0x800BF178u: goto label_800BF178;
    case 0x800BF17Cu: goto label_800BF17C;
    case 0x800BF180u: goto label_800BF180;
    case 0x800BF184u: goto label_800BF184;
    case 0x800BF188u: goto label_800BF188;
    case 0x800BF18Cu: goto label_800BF18C;
    case 0x800BF190u: goto label_800BF190;
    case 0x800BF194u: goto label_800BF194;
    case 0x800BF198u: goto label_800BF198;
    case 0x800BF19Cu: goto label_800BF19C;
    case 0x800BF1A0u: goto label_800BF1A0;
    case 0x800BF1A4u: goto label_800BF1A4;
    case 0x800BF1A8u: goto label_800BF1A8;
    case 0x800BF1ACu: goto label_800BF1AC;
    case 0x800BF1B0u: goto label_800BF1B0;
    case 0x800BF1B4u: goto label_800BF1B4;
    case 0x800BF1B8u: goto label_800BF1B8;
    case 0x800BF1BCu: goto label_800BF1BC;
    case 0x800BF1C0u: goto label_800BF1C0;
    case 0x800BF1C4u: goto label_800BF1C4;
    case 0x800BF1C8u: goto label_800BF1C8;
    case 0x800BF1CCu: goto label_800BF1CC;
    case 0x800BF1D0u: goto label_800BF1D0;
    case 0x800BF1D4u: goto label_800BF1D4;
    case 0x800BF1D8u: goto label_800BF1D8;
    case 0x800BF1DCu: goto label_800BF1DC;
    case 0x800BF1E0u: goto label_800BF1E0;
    case 0x800BF1E4u: goto label_800BF1E4;
    case 0x800BF1E8u: goto label_800BF1E8;
    case 0x800BF1ECu: goto label_800BF1EC;
    case 0x800BF1F0u: goto label_800BF1F0;
    case 0x800BF1F4u: goto label_800BF1F4;
    case 0x800BF1F8u: goto label_800BF1F8;
    case 0x800BF1FCu: goto label_800BF1FC;
    case 0x800BF200u: goto label_800BF200;
    case 0x800BF204u: goto label_800BF204;
    case 0x800BF208u: goto label_800BF208;
    case 0x800BF20Cu: goto label_800BF20C;
    case 0x800BF210u: goto label_800BF210;
    case 0x800BF214u: goto label_800BF214;
    case 0x800BF218u: goto label_800BF218;
    case 0x800BF21Cu: goto label_800BF21C;
    case 0x800BF220u: goto label_800BF220;
    case 0x800BF224u: goto label_800BF224;
    case 0x800BF228u: goto label_800BF228;
    case 0x800BF22Cu: goto label_800BF22C;
    case 0x800BF230u: goto label_800BF230;
    case 0x800BF234u: goto label_800BF234;
    case 0x800BF238u: goto label_800BF238;
    case 0x800BF23Cu: goto label_800BF23C;
    case 0x800BF240u: goto label_800BF240;
    case 0x800BF244u: goto label_800BF244;
    case 0x800BF248u: goto label_800BF248;
    case 0x800BF24Cu: goto label_800BF24C;
    case 0x800BF250u: goto label_800BF250;
    case 0x800BF254u: goto label_800BF254;
    case 0x800BF258u: goto label_800BF258;
    case 0x800BF25Cu: goto label_800BF25C;
    case 0x800BF260u: goto label_800BF260;
    case 0x800BF264u: goto label_800BF264;
    case 0x800BF268u: goto label_800BF268;
    case 0x800BF26Cu: goto label_800BF26C;
    case 0x800BF270u: goto label_800BF270;
    case 0x800BF274u: goto label_800BF274;
    case 0x800BF278u: goto label_800BF278;
    case 0x800BF27Cu: goto label_800BF27C;
    case 0x800BF280u: goto label_800BF280;
    case 0x800BF284u: goto label_800BF284;
    case 0x800BF288u: goto label_800BF288;
    case 0x800BF28Cu: goto label_800BF28C;
    case 0x800BF290u: goto label_800BF290;
    case 0x800BF294u: goto label_800BF294;
    case 0x800BF298u: goto label_800BF298;
    case 0x800BF29Cu: goto label_800BF29C;
    case 0x800BF2A0u: goto label_800BF2A0;
    case 0x800BF2A4u: goto label_800BF2A4;
    case 0x800BF2A8u: goto label_800BF2A8;
    case 0x800BF2ACu: goto label_800BF2AC;
    case 0x800BF2B0u: goto label_800BF2B0;
    case 0x800BF2B4u: goto label_800BF2B4;
    case 0x800BF2B8u: goto label_800BF2B8;
    case 0x800BF2BCu: goto label_800BF2BC;
    default: return;
    }
label_800BB2C0:
    ctx->pc = 0x800BB2C0u;
    ctx->downcount -= 2;
    // 800BB2C0: cmpwi   r0, 4
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

label_800BB2C4:
    ctx->pc = 0x800BB2C4u;
    // 800BB2C4: bc    12, 2, 0x800BB37C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BB37C;
        }
    }

label_800BB2C8:
    ctx->pc = 0x800BB2C8u;
    ctx->downcount -= 2;
    // 800BB2C8: cmpwi   r0, 8
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

label_800BB2CC:
    ctx->pc = 0x800BB2CCu;
    // 800BB2CC: bc    12, 2, 0x800BB424
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BB424;
        }
    }

label_800BB2D0:
    ctx->pc = 0x800BB2D0u;
    ctx->downcount -= 1;
    // 800BB2D0: b       0x800BB67C
    {
            goto label_800BB67C;
    }

label_800BB2D4:
    ctx->pc = 0x800BB2D4u;
    ctx->downcount -= 16;
    // 800BB2D4: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB2D8:
    ctx->pc = 0x800BB2D8u;
    // 800BB2D8: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BB2DC:
    ctx->pc = 0x800BB2DCu;
    // 800BB2DC: lfs     f31, -16076(r9)
    if (!ppc_fp_available(ctx, 0x800BB2DCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16076);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800BB2E0:
    ctx->pc = 0x800BB2E0u;
    // 800BB2E0: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BB2E4:
    ctx->pc = 0x800BB2E4u;
    // 800BB2E4: lfs     f30, -16080(r11)
    if (!ppc_fp_available(ctx, 0x800BB2E4u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800BB2E8:
    ctx->pc = 0x800BB2E8u;
    // 800BB2E8: addi    r4, r25, -27432
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(-27432);

label_800BB2EC:
    ctx->pc = 0x800BB2ECu;
    // 800BB2EC: lfs     f2, 20(r30)
    if (!ppc_fp_available(ctx, 0x800BB2ECu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB2F0:
    ctx->pc = 0x800BB2F0u;
    // 800BB2F0: ori     r3, r3, 0x0135
    ctx->gpr[3] = ctx->gpr[3] | 0x0135u;

label_800BB2F4:
    ctx->pc = 0x800BB2F4u;
    // 800BB2F4: lfs     f0, 16(r30)
    if (!ppc_fp_available(ctx, 0x800BB2F4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB2F8:
    ctx->pc = 0x800BB2F8u;
    // 800BB2F8: fadds   f2, f2, f30
    if (!ppc_fp_available(ctx, 0x800BB2F8u)) return;
    ppc_fadds(ctx, 2, 2, 30);

label_800BB2FC:
    ctx->pc = 0x800BB2FCu;
    // 800BB2FC: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB2FCu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB300:
    ctx->pc = 0x800BB300u;
    // 800BB300: fsubs   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB300u)) return;
    ppc_fsubs(ctx, 0, 0, 31);

label_800BB304:
    ctx->pc = 0x800BB304u;
    // 800BB304: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB304u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB308:
    ctx->pc = 0x800BB308u;
    // 800BB308: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB308u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB30C:
    ctx->pc = 0x800BB30Cu;
    // 800BB30C: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB30Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB310:
    ctx->pc = 0x800BB310u;
    // 800BB310: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB314u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB314:
    ctx->pc = 0x800BB314u;
    ctx->downcount -= 12;
    // 800BB314: lfs     f2, 32(r30)
    if (!ppc_fp_available(ctx, 0x800BB314u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB318:
    ctx->pc = 0x800BB318u;
    // 800BB318: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BB31C:
    ctx->pc = 0x800BB31Cu;
    // 800BB31C: lfs     f0, 28(r30)
    if (!ppc_fp_available(ctx, 0x800BB31Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB320:
    ctx->pc = 0x800BB320u;
    // 800BB320: addi    r4, r25, -27432
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(-27432);

label_800BB324:
    ctx->pc = 0x800BB324u;
    // 800BB324: fadds   f2, f2, f30
    if (!ppc_fp_available(ctx, 0x800BB324u)) return;
    ppc_fadds(ctx, 2, 2, 30);

label_800BB328:
    ctx->pc = 0x800BB328u;
    // 800BB328: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB328u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB32C:
    ctx->pc = 0x800BB32Cu;
    // 800BB32C: fsubs   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB32Cu)) return;
    ppc_fsubs(ctx, 0, 0, 31);

label_800BB330:
    ctx->pc = 0x800BB330u;
    // 800BB330: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB330u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB334:
    ctx->pc = 0x800BB334u;
    // 800BB334: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB334u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB338:
    ctx->pc = 0x800BB338u;
    // 800BB338: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB338u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB33C:
    ctx->pc = 0x800BB33Cu;
    // 800BB33C: ori     r3, r3, 0x0135
    ctx->gpr[3] = ctx->gpr[3] | 0x0135u;

label_800BB340:
    ctx->pc = 0x800BB340u;
    // 800BB340: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB344u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB344:
    ctx->pc = 0x800BB344u;
    ctx->downcount -= 13;
    // 800BB344: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB348:
    ctx->pc = 0x800BB348u;
    // 800BB348: lfs     f1, 40(r30)
    if (!ppc_fp_available(ctx, 0x800BB348u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BB34C:
    ctx->pc = 0x800BB34Cu;
    // 800BB34C: lfs     f2, 44(r30)
    if (!ppc_fp_available(ctx, 0x800BB34Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB350:
    ctx->pc = 0x800BB350u;
    // 800BB350: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BB354:
    ctx->pc = 0x800BB354u;
    // 800BB354: lfs     f0, -16072(r9)
    if (!ppc_fp_available(ctx, 0x800BB354u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16072);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB358:
    ctx->pc = 0x800BB358u;
    // 800BB358: fsubs   f1, f1, f31
    if (!ppc_fp_available(ctx, 0x800BB358u)) return;
    ppc_fsubs(ctx, 1, 1, 31);

label_800BB35C:
    ctx->pc = 0x800BB35Cu;
    // 800BB35C: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB35Cu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB360:
    ctx->pc = 0x800BB360u;
    // 800BB360: addi    r4, r25, -27432
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(-27432);

label_800BB364:
    ctx->pc = 0x800BB364u;
    // 800BB364: fadds   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x800BB364u)) return;
    ppc_fadds(ctx, 2, 2, 0);

label_800BB368:
    ctx->pc = 0x800BB368u;
    // 800BB368: stfs     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB368u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_800BB36C:
    ctx->pc = 0x800BB36Cu;
    // 800BB36C: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB36Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB370:
    ctx->pc = 0x800BB370u;
    // 800BB370: ori     r3, r3, 0x013C
    ctx->gpr[3] = ctx->gpr[3] | 0x013Cu;

label_800BB374:
    ctx->pc = 0x800BB374u;
    // 800BB374: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB378u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB378:
    ctx->pc = 0x800BB378u;
    ctx->downcount -= 1;
    // 800BB378: b       0x800BB67C
    {
            goto label_800BB67C;
    }

label_800BB37C:
    ctx->pc = 0x800BB37Cu;
    ctx->downcount -= 16;
    // 800BB37C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB380:
    ctx->pc = 0x800BB380u;
    // 800BB380: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BB384:
    ctx->pc = 0x800BB384u;
    // 800BB384: lfs     f31, -16076(r9)
    if (!ppc_fp_available(ctx, 0x800BB384u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16076);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800BB388:
    ctx->pc = 0x800BB388u;
    // 800BB388: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BB38C:
    ctx->pc = 0x800BB38Cu;
    // 800BB38C: lfs     f30, -16080(r11)
    if (!ppc_fp_available(ctx, 0x800BB38Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800BB390:
    ctx->pc = 0x800BB390u;
    // 800BB390: addi    r4, r25, -27432
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(-27432);

label_800BB394:
    ctx->pc = 0x800BB394u;
    // 800BB394: lfs     f2, 20(r30)
    if (!ppc_fp_available(ctx, 0x800BB394u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB398:
    ctx->pc = 0x800BB398u;
    // 800BB398: ori     r3, r3, 0x0135
    ctx->gpr[3] = ctx->gpr[3] | 0x0135u;

label_800BB39C:
    ctx->pc = 0x800BB39Cu;
    // 800BB39C: lfs     f0, 16(r30)
    if (!ppc_fp_available(ctx, 0x800BB39Cu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB3A0:
    ctx->pc = 0x800BB3A0u;
    // 800BB3A0: fadds   f2, f2, f30
    if (!ppc_fp_available(ctx, 0x800BB3A0u)) return;
    ppc_fadds(ctx, 2, 2, 30);

label_800BB3A4:
    ctx->pc = 0x800BB3A4u;
    // 800BB3A4: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB3A4u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB3A8:
    ctx->pc = 0x800BB3A8u;
    // 800BB3A8: fsubs   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB3A8u)) return;
    ppc_fsubs(ctx, 0, 0, 31);

label_800BB3AC:
    ctx->pc = 0x800BB3ACu;
    // 800BB3AC: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB3ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB3B0:
    ctx->pc = 0x800BB3B0u;
    // 800BB3B0: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB3B0u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB3B4:
    ctx->pc = 0x800BB3B4u;
    // 800BB3B4: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB3B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB3B8:
    ctx->pc = 0x800BB3B8u;
    // 800BB3B8: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB3BCu;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB3BC:
    ctx->pc = 0x800BB3BCu;
    ctx->downcount -= 12;
    // 800BB3BC: lfs     f2, 32(r30)
    if (!ppc_fp_available(ctx, 0x800BB3BCu)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB3C0:
    ctx->pc = 0x800BB3C0u;
    // 800BB3C0: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BB3C4:
    ctx->pc = 0x800BB3C4u;
    // 800BB3C4: lfs     f0, 28(r30)
    if (!ppc_fp_available(ctx, 0x800BB3C4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB3C8:
    ctx->pc = 0x800BB3C8u;
    // 800BB3C8: addi    r4, r25, -27432
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(-27432);

label_800BB3CC:
    ctx->pc = 0x800BB3CCu;
    // 800BB3CC: fadds   f2, f2, f30
    if (!ppc_fp_available(ctx, 0x800BB3CCu)) return;
    ppc_fadds(ctx, 2, 2, 30);

label_800BB3D0:
    ctx->pc = 0x800BB3D0u;
    // 800BB3D0: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB3D0u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB3D4:
    ctx->pc = 0x800BB3D4u;
    // 800BB3D4: fsubs   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB3D4u)) return;
    ppc_fsubs(ctx, 0, 0, 31);

label_800BB3D8:
    ctx->pc = 0x800BB3D8u;
    // 800BB3D8: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB3D8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB3DC:
    ctx->pc = 0x800BB3DCu;
    // 800BB3DC: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB3DCu)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB3E0:
    ctx->pc = 0x800BB3E0u;
    // 800BB3E0: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB3E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB3E4:
    ctx->pc = 0x800BB3E4u;
    // 800BB3E4: ori     r3, r3, 0x0135
    ctx->gpr[3] = ctx->gpr[3] | 0x0135u;

label_800BB3E8:
    ctx->pc = 0x800BB3E8u;
    // 800BB3E8: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB3ECu;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB3EC:
    ctx->pc = 0x800BB3ECu;
    ctx->downcount -= 13;
    // 800BB3EC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB3F0:
    ctx->pc = 0x800BB3F0u;
    // 800BB3F0: lfs     f1, 40(r30)
    if (!ppc_fp_available(ctx, 0x800BB3F0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BB3F4:
    ctx->pc = 0x800BB3F4u;
    // 800BB3F4: lfs     f2, 44(r30)
    if (!ppc_fp_available(ctx, 0x800BB3F4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(44);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB3F8:
    ctx->pc = 0x800BB3F8u;
    // 800BB3F8: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BB3FC:
    ctx->pc = 0x800BB3FCu;
    // 800BB3FC: lfs     f0, -16072(r9)
    if (!ppc_fp_available(ctx, 0x800BB3FCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16072);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB400:
    ctx->pc = 0x800BB400u;
    // 800BB400: fsubs   f1, f1, f31
    if (!ppc_fp_available(ctx, 0x800BB400u)) return;
    ppc_fsubs(ctx, 1, 1, 31);

label_800BB404:
    ctx->pc = 0x800BB404u;
    // 800BB404: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB404u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB408:
    ctx->pc = 0x800BB408u;
    // 800BB408: addi    r4, r25, -27432
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(-27432);

label_800BB40C:
    ctx->pc = 0x800BB40Cu;
    // 800BB40C: fadds   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x800BB40Cu)) return;
    ppc_fadds(ctx, 2, 2, 0);

label_800BB410:
    ctx->pc = 0x800BB410u;
    // 800BB410: stfs     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB410u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[1]));
    }

label_800BB414:
    ctx->pc = 0x800BB414u;
    // 800BB414: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB414u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB418:
    ctx->pc = 0x800BB418u;
    // 800BB418: ori     r3, r3, 0x013B
    ctx->gpr[3] = ctx->gpr[3] | 0x013Bu;

label_800BB41C:
    ctx->pc = 0x800BB41Cu;
    // 800BB41C: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB420u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB420:
    ctx->pc = 0x800BB420u;
    ctx->downcount -= 1;
    // 800BB420: b       0x800BB67C
    {
            goto label_800BB67C;
    }

label_800BB424:
    ctx->pc = 0x800BB424u;
    ctx->downcount -= 22;
    // 800BB424: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB428:
    ctx->pc = 0x800BB428u;
    // 800BB428: lfs     f13, 20(r30)
    if (!ppc_fp_available(ctx, 0x800BB428u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BB42C:
    ctx->pc = 0x800BB42Cu;
    // 800BB42C: lfs     f11, -16080(r9)
    if (!ppc_fp_available(ctx, 0x800BB42Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800BB430:
    ctx->pc = 0x800BB430u;
    // 800BB430: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BB434:
    ctx->pc = 0x800BB434u;
    // 800BB434: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB438:
    ctx->pc = 0x800BB438u;
    // 800BB438: lfs     f0, 16(r30)
    if (!ppc_fp_available(ctx, 0x800BB438u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB43C:
    ctx->pc = 0x800BB43Cu;
    // 800BB43C: lfs     f12, -16064(r9)
    if (!ppc_fp_available(ctx, 0x800BB43Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16064);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BB440:
    ctx->pc = 0x800BB440u;
    // 800BB440: fadds   f13, f13, f11
    if (!ppc_fp_available(ctx, 0x800BB440u)) return;
    ppc_fadds(ctx, 13, 13, 11);

label_800BB444:
    ctx->pc = 0x800BB444u;
    // 800BB444: lfs     f10, -16068(r11)
    if (!ppc_fp_available(ctx, 0x800BB444u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16068);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800BB448:
    ctx->pc = 0x800BB448u;
    // 800BB448: addi    r26, r1, 26
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(26);

label_800BB44C:
    ctx->pc = 0x800BB44Cu;
    // 800BB44C: fsubs   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x800BB44Cu)) return;
    ppc_fsubs(ctx, 0, 0, 12);

label_800BB450:
    ctx->pc = 0x800BB450u;
    // 800BB450: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BB454:
    ctx->pc = 0x800BB454u;
    // 800BB454: fsubs   f13, f13, f10
    if (!ppc_fp_available(ctx, 0x800BB454u)) return;
    ppc_fsubs(ctx, 13, 13, 10);

label_800BB458:
    ctx->pc = 0x800BB458u;
    // 800BB458: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB458u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB45C:
    ctx->pc = 0x800BB45Cu;
    // 800BB45C: stfs     f13, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB45Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BB460:
    ctx->pc = 0x800BB460u;
    // 800BB460: fmr    f31, f11
    if (!ppc_fp_available(ctx, 0x800BB460u)) return;
    ctx->fpr[31] = ctx->fpr[11];

label_800BB464:
    ctx->pc = 0x800BB464u;
    // 800BB464: addi    r24, r9, -6860
    ctx->gpr[24] = ctx->gpr[9] + (u32)(s32)(-6860);

label_800BB468:
    ctx->pc = 0x800BB468u;
    // 800BB468: or   r29, r26, r26
    {
        ctx->gpr[29] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BB46C:
    ctx->pc = 0x800BB46Cu;
    // 800BB46C: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_800BB470:
    ctx->pc = 0x800BB470u;
    // 800BB470: addi    r28, r1, 24
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(24);

label_800BB474:
    ctx->pc = 0x800BB474u;
    // 800BB474: addi    r23, r1, 28
    ctx->gpr[23] = ctx->gpr[1] + (u32)(s32)(28);

label_800BB478:
    ctx->pc = 0x800BB478u;
    // 800BB478: addi    r22, r1, 30
    ctx->gpr[22] = ctx->gpr[1] + (u32)(s32)(30);

label_800BB47C:
    ctx->downcount -= 7;
    // 800BB47C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BB480:
    // 800BB480: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BB484:
    // 800BB484: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BB488:
    // 800BB488: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BB48C:
    // 800BB48C: or   r7, r29, r29
    {
        ctx->gpr[7] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BB490:
    // 800BB490: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_800BB494:
    // 800BB494: bl      0x8012D2E4
    {
            ctx->lr = 0x800BB498u;
            ctx->pc = 0x8012D2E4u;
            return;
    }

label_800BB498:
    ctx->pc = 0x800BB498u;
    ctx->downcount -= 8;
    // 800BB498: lhz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BB49C:
    // 800BB49C: addi    r4, r25, -27432
    ctx->gpr[4] = ctx->gpr[25] + (u32)(s32)(-27432);

label_800BB4A0:
    ctx->pc = 0x800BB4A0u;
    // 800BB4A0: lfs     f1, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB4A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BB4A4:
    // 800BB4A4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800BB4A8:
    ctx->pc = 0x800BB4A8u;
    // 800BB4A8: lfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB4A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB4AC:
    ctx->pc = 0x800BB4ACu;
    // 800BB4AC: lwzx    r3, r24, r0
    {
        u32 ea = ctx->gpr[24] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BB4B0:
    ctx->pc = 0x800BB4B0u;
    // 800BB4B0: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB4B0u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB4B4:
    // 800BB4B4: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB4B8u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB4B8:
    ctx->pc = 0x800BB4B8u;
    ctx->downcount -= 5;
    // 800BB4B8: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB4B8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB4BC:
    // 800BB4BC: cmpwi   r30, 3
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BB4C0:
    ctx->pc = 0x800BB4C0u;
    // 800BB4C0: fadds   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB4C0u)) return;
    ppc_fadds(ctx, 0, 0, 31);

label_800BB4C4:
    ctx->pc = 0x800BB4C4u;
    // 800BB4C4: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB4C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB4C8:
    // 800BB4C8: bc    4, 1, 0x800BB47C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BB47Cu;
                return;
            }
            goto label_800BB47C;
        }
    }

label_800BB4CC:
    ctx->pc = 0x800BB4CCu;
    ctx->downcount -= 15;
    // 800BB4CC: lis     r29, -32699
    ctx->gpr[29] = ((u32)(s32)(-32699) << 16);

label_800BB4D0:
    ctx->pc = 0x800BB4D0u;
    // 800BB4D0: or   r5, r23, r23
    {
        ctx->gpr[5] = ctx->gpr[23] | ctx->gpr[23];
    }

label_800BB4D4:
    ctx->pc = 0x800BB4D4u;
    // 800BB4D4: addi    r29, r29, -21636
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-21636);

label_800BB4D8:
    ctx->pc = 0x800BB4D8u;
    // 800BB4D8: or   r6, r26, r26
    {
        ctx->gpr[6] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BB4DC:
    ctx->pc = 0x800BB4DCu;
    // 800BB4DC: lwz     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BB4E0:
    ctx->pc = 0x800BB4E0u;
    // 800BB4E0: or   r7, r22, r22
    {
        ctx->gpr[7] = ctx->gpr[22] | ctx->gpr[22];
    }

label_800BB4E4:
    ctx->pc = 0x800BB4E4u;
    // 800BB4E4: or   r8, r26, r26
    {
        ctx->gpr[8] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BB4E8:
    ctx->pc = 0x800BB4E8u;
    // 800BB4E8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BB4EC:
    ctx->pc = 0x800BB4ECu;
    // 800BB4EC: rlwinm r0, r3, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0x00000001u;
    }

label_800BB4F0:
    ctx->pc = 0x800BB4F0u;
    // 800BB4F0: lis     r27, -32737
    ctx->gpr[27] = ((u32)(s32)(-32737) << 16);

label_800BB4F4:
    ctx->pc = 0x800BB4F4u;
    // 800BB4F4: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800BB4F8:
    ctx->pc = 0x800BB4F8u;
    // 800BB4F8: lis     r28, -32735
    ctx->gpr[28] = ((u32)(s32)(-32735) << 16);

label_800BB4FC:
    ctx->pc = 0x800BB4FCu;
    // 800BB4FC: srawi r3, r3, 1
    {
        u32 sh = 1u;
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

label_800BB500:
    ctx->pc = 0x800BB500u;
    // 800BB500: addi    r3, r3, -3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-3);

label_800BB504:
    ctx->pc = 0x800BB504u;
    // 800BB504: bl      0x8012D3A0
    {
            ctx->lr = 0x800BB508u;
            ctx->pc = 0x8012D3A0u;
            return;
    }

label_800BB508:
    ctx->pc = 0x800BB508u;
    ctx->downcount -= 25;
    // 800BB508: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BB50C:
    ctx->pc = 0x800BB50Cu;
    // 800BB50C: lfs     f2, 1436(r31)
    if (!ppc_fp_available(ctx, 0x800BB50Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1436);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB510:
    ctx->pc = 0x800BB510u;
    // 800BB510: lfs     f13, -16080(r11)
    if (!ppc_fp_available(ctx, 0x800BB510u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16080);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BB514:
    ctx->pc = 0x800BB514u;
    // 800BB514: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB518:
    ctx->pc = 0x800BB518u;
    // 800BB518: lfs     f12, -16068(r9)
    if (!ppc_fp_available(ctx, 0x800BB518u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16068);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BB51C:
    ctx->pc = 0x800BB51Cu;
    // 800BB51C: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BB520:
    ctx->pc = 0x800BB520u;
    // 800BB520: lfs     f0, -16060(r11)
    if (!ppc_fp_available(ctx, 0x800BB520u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16060);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB524:
    ctx->pc = 0x800BB524u;
    // 800BB524: fadds   f2, f2, f13
    if (!ppc_fp_available(ctx, 0x800BB524u)) return;
    ppc_fadds(ctx, 2, 2, 13);

label_800BB528:
    ctx->pc = 0x800BB528u;
    // 800BB528: fsubs   f2, f2, f12
    if (!ppc_fp_available(ctx, 0x800BB528u)) return;
    ppc_fsubs(ctx, 2, 2, 12);

label_800BB52C:
    ctx->pc = 0x800BB52Cu;
    // 800BB52C: lhz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BB530:
    ctx->pc = 0x800BB530u;
    // 800BB530: fadds   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x800BB530u)) return;
    ppc_fadds(ctx, 2, 2, 0);

label_800BB534:
    ctx->pc = 0x800BB534u;
    // 800BB534: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB538:
    ctx->pc = 0x800BB538u;
    // 800BB538: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB538u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB53C:
    ctx->pc = 0x800BB53Cu;
    // 800BB53C: lis     r30, -32734
    ctx->gpr[30] = ((u32)(s32)(-32734) << 16);

label_800BB540:
    ctx->pc = 0x800BB540u;
    // 800BB540: lfs     f30, -16056(r9)
    if (!ppc_fp_available(ctx, 0x800BB540u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16056);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800BB544:
    ctx->pc = 0x800BB544u;
    // 800BB544: addi    r30, r30, -6860
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-6860);

label_800BB548:
    ctx->pc = 0x800BB548u;
    // 800BB548: lfs     f0, 1432(r31)
    if (!ppc_fp_available(ctx, 0x800BB548u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB54C:
    ctx->pc = 0x800BB54Cu;
    // 800BB54C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800BB550:
    ctx->pc = 0x800BB550u;
    // 800BB550: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BB554:
    ctx->pc = 0x800BB554u;
    // 800BB554: addi    r4, r28, -27432
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(-27432);

label_800BB558:
    ctx->pc = 0x800BB558u;
    // 800BB558: fsubs   f0, f0, f30
    if (!ppc_fp_available(ctx, 0x800BB558u)) return;
    ppc_fsubs(ctx, 0, 0, 30);

label_800BB55C:
    ctx->pc = 0x800BB55Cu;
    // 800BB55C: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB55Cu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB560:
    ctx->pc = 0x800BB560u;
    // 800BB560: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB560u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB564:
    ctx->pc = 0x800BB564u;
    // 800BB564: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB564u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB568:
    ctx->pc = 0x800BB568u;
    // 800BB568: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB56Cu;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB56C:
    ctx->pc = 0x800BB56Cu;
    ctx->downcount -= 13;
    // 800BB56C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB570:
    ctx->pc = 0x800BB570u;
    // 800BB570: lhz     r0, 30(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(30);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BB574:
    ctx->pc = 0x800BB574u;
    // 800BB574: lfs     f31, -16052(r9)
    if (!ppc_fp_available(ctx, 0x800BB574u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16052);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800BB578:
    ctx->pc = 0x800BB578u;
    // 800BB578: addi    r4, r28, -27432
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(-27432);

label_800BB57C:
    ctx->pc = 0x800BB57Cu;
    // 800BB57C: lfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB57Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB580:
    ctx->pc = 0x800BB580u;
    // 800BB580: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800BB584:
    ctx->pc = 0x800BB584u;
    // 800BB584: lfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB584u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB588:
    ctx->pc = 0x800BB588u;
    // 800BB588: fadds   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB588u)) return;
    ppc_fadds(ctx, 0, 0, 31);

label_800BB58C:
    ctx->pc = 0x800BB58Cu;
    // 800BB58C: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BB590:
    ctx->pc = 0x800BB590u;
    // 800BB590: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB590u)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB594:
    ctx->pc = 0x800BB594u;
    // 800BB594: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB594u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB598:
    ctx->pc = 0x800BB598u;
    // 800BB598: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB598u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB59C:
    ctx->pc = 0x800BB59Cu;
    // 800BB59C: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB5A0u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB5A0:
    ctx->pc = 0x800BB5A0u;
    ctx->downcount -= 11;
    // 800BB5A0: lwz     r3, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BB5A4:
    ctx->pc = 0x800BB5A4u;
    // 800BB5A4: or   r6, r26, r26
    {
        ctx->gpr[6] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BB5A8:
    ctx->pc = 0x800BB5A8u;
    // 800BB5A8: or   r5, r23, r23
    {
        ctx->gpr[5] = ctx->gpr[23] | ctx->gpr[23];
    }

label_800BB5AC:
    ctx->pc = 0x800BB5ACu;
    // 800BB5AC: or   r7, r22, r22
    {
        ctx->gpr[7] = ctx->gpr[22] | ctx->gpr[22];
    }

label_800BB5B0:
    ctx->pc = 0x800BB5B0u;
    // 800BB5B0: rlwinm r0, r3, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0x00000001u;
    }

label_800BB5B4:
    ctx->pc = 0x800BB5B4u;
    // 800BB5B4: or   r8, r6, r6
    {
        ctx->gpr[8] = ctx->gpr[6] | ctx->gpr[6];
    }

label_800BB5B8:
    ctx->pc = 0x800BB5B8u;
    // 800BB5B8: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800BB5BC:
    ctx->pc = 0x800BB5BCu;
    // 800BB5BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BB5C0:
    ctx->pc = 0x800BB5C0u;
    // 800BB5C0: srawi r3, r3, 1
    {
        u32 sh = 1u;
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

label_800BB5C4:
    ctx->pc = 0x800BB5C4u;
    // 800BB5C4: addi    r3, r3, -3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-3);

label_800BB5C8:
    ctx->pc = 0x800BB5C8u;
    // 800BB5C8: bl      0x8012D3A0
    {
            ctx->lr = 0x800BB5CCu;
            ctx->pc = 0x8012D3A0u;
            return;
    }

label_800BB5CC:
    ctx->pc = 0x800BB5CCu;
    ctx->downcount -= 13;
    // 800BB5CC: lfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB5CCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB5D0:
    ctx->pc = 0x800BB5D0u;
    // 800BB5D0: addi    r4, r28, -27432
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(-27432);

label_800BB5D4:
    ctx->pc = 0x800BB5D4u;
    // 800BB5D4: lhz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BB5D8:
    ctx->pc = 0x800BB5D8u;
    // 800BB5D8: fadds   f2, f2, f31
    if (!ppc_fp_available(ctx, 0x800BB5D8u)) return;
    ppc_fadds(ctx, 2, 2, 31);

label_800BB5DC:
    ctx->pc = 0x800BB5DCu;
    // 800BB5DC: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB5DCu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB5E0:
    ctx->pc = 0x800BB5E0u;
    // 800BB5E0: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB5E0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB5E4:
    ctx->pc = 0x800BB5E4u;
    // 800BB5E4: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800BB5E8:
    ctx->pc = 0x800BB5E8u;
    // 800BB5E8: lfs     f0, 1432(r31)
    if (!ppc_fp_available(ctx, 0x800BB5E8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB5EC:
    ctx->pc = 0x800BB5ECu;
    // 800BB5EC: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BB5F0:
    ctx->pc = 0x800BB5F0u;
    // 800BB5F0: fsubs   f0, f0, f30
    if (!ppc_fp_available(ctx, 0x800BB5F0u)) return;
    ppc_fsubs(ctx, 0, 0, 30);

label_800BB5F4:
    ctx->pc = 0x800BB5F4u;
    // 800BB5F4: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB5F4u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB5F8:
    ctx->pc = 0x800BB5F8u;
    // 800BB5F8: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB5F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB5FC:
    ctx->pc = 0x800BB5FCu;
    // 800BB5FC: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB600u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB600:
    ctx->pc = 0x800BB600u;
    ctx->downcount -= 11;
    // 800BB600: lhz     r0, 30(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(30);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BB604:
    ctx->pc = 0x800BB604u;
    // 800BB604: addi    r4, r28, -27432
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(-27432);

label_800BB608:
    ctx->pc = 0x800BB608u;
    // 800BB608: lfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB608u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB60C:
    ctx->pc = 0x800BB60Cu;
    // 800BB60C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_800BB610:
    ctx->pc = 0x800BB610u;
    // 800BB610: lfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB610u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB614:
    ctx->pc = 0x800BB614u;
    // 800BB614: fadds   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB614u)) return;
    ppc_fadds(ctx, 0, 0, 31);

label_800BB618:
    ctx->pc = 0x800BB618u;
    // 800BB618: lwzx    r3, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BB61C:
    ctx->pc = 0x800BB61Cu;
    // 800BB61C: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB61Cu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB620:
    ctx->pc = 0x800BB620u;
    // 800BB620: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB620u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB624:
    ctx->pc = 0x800BB624u;
    // 800BB624: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB624u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB628:
    ctx->pc = 0x800BB628u;
    // 800BB628: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB62Cu;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB62C:
    ctx->pc = 0x800BB62Cu;
    ctx->downcount -= 14;
    // 800BB62C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB630:
    ctx->pc = 0x800BB630u;
    // 800BB630: lfs     f2, 1436(r31)
    if (!ppc_fp_available(ctx, 0x800BB630u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1436);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BB634:
    ctx->pc = 0x800BB634u;
    // 800BB634: lfs     f0, -16072(r9)
    if (!ppc_fp_available(ctx, 0x800BB634u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16072);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB638:
    ctx->pc = 0x800BB638u;
    // 800BB638: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BB63C:
    ctx->pc = 0x800BB63Cu;
    // 800BB63C: lfs     f3, -16084(r27)
    if (!ppc_fp_available(ctx, 0x800BB63Cu)) return;
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(-16084);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BB640:
    ctx->pc = 0x800BB640u;
    // 800BB640: addi    r4, r28, -27432
    ctx->gpr[4] = ctx->gpr[28] + (u32)(s32)(-27432);

label_800BB644:
    ctx->pc = 0x800BB644u;
    // 800BB644: fadds   f2, f2, f0
    if (!ppc_fp_available(ctx, 0x800BB644u)) return;
    ppc_fadds(ctx, 2, 2, 0);

label_800BB648:
    ctx->pc = 0x800BB648u;
    // 800BB648: ori     r3, r3, 0x013D
    ctx->gpr[3] = ctx->gpr[3] | 0x013Du;

label_800BB64C:
    ctx->pc = 0x800BB64Cu;
    // 800BB64C: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB64Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BB650:
    ctx->pc = 0x800BB650u;
    // 800BB650: lfs     f0, 1432(r31)
    if (!ppc_fp_available(ctx, 0x800BB650u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB654:
    ctx->pc = 0x800BB654u;
    // 800BB654: fadds   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BB654u)) return;
    ppc_fadds(ctx, 0, 0, 31);

label_800BB658:
    ctx->pc = 0x800BB658u;
    // 800BB658: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BB658u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BB65C:
    ctx->pc = 0x800BB65Cu;
    // 800BB65C: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB65Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB660:
    ctx->pc = 0x800BB660u;
    // 800BB660: bl      0x800B7AD8
    {
            ctx->lr = 0x800BB664u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BB664:
    ctx->pc = 0x800BB664u;
    ctx->downcount -= 1;
    // 800BB664: b       0x800BB67C
    {
            goto label_800BB67C;
    }

label_800BB668:
    ctx->pc = 0x800BB668u;
    ctx->downcount -= 5;
    // 800BB668: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB66C:
    ctx->pc = 0x800BB66Cu;
    // 800BB66C: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_800BB670:
    ctx->pc = 0x800BB670u;
    // 800BB670: stw     r9, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BB674:
    ctx->pc = 0x800BB674u;
    // 800BB674: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB678:
    ctx->pc = 0x800BB678u;
    // 800BB678: stw     r9, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BB67C:
    ctx->pc = 0x800BB67Cu;
    ctx->downcount -= 19;
    // 800BB67C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB680:
    ctx->pc = 0x800BB680u;
    // 800BB680: lwz     r0, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB684:
    ctx->pc = 0x800BB684u;
    // 800BB684: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BB688:
    ctx->pc = 0x800BB688u;
    // 800BB688: lmw     r22, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        for (u32 r = 22; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BB68C:
    ctx->pc = 0x800BB68Cu;
    // 800BB68C: lfd     f30, 72(r1)
    if (!ppc_fp_available(ctx, 0x800BB68Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BB690:
    ctx->pc = 0x800BB690u;
    // 800BB690: lfd     f31, 80(r1)
    if (!ppc_fp_available(ctx, 0x800BB690u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BB694:
    ctx->pc = 0x800BB694u;
    // 800BB694: addi    r1, r1, 88
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(88);

label_800BB698:
    ctx->pc = 0x800BB698u;
    // 800BB698: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BB69C:
    ctx->pc = 0x800BB69Cu;
    ctx->downcount -= 24;
    // 800BB69C: stwu     r1, -2400(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-2400);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BB6A0:
    ctx->pc = 0x800BB6A0u;
    // 800BB6A0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BB6A4:
    ctx->pc = 0x800BB6A4u;
    // 800BB6A4: stfd     f29, 2376(r1)
    if (!ppc_fp_available(ctx, 0x800BB6A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2376);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_800BB6A8:
    ctx->pc = 0x800BB6A8u;
    // 800BB6A8: stfd     f30, 2384(r1)
    if (!ppc_fp_available(ctx, 0x800BB6A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2384);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_800BB6AC:
    ctx->pc = 0x800BB6ACu;
    // 800BB6AC: stfd     f31, 2392(r1)
    if (!ppc_fp_available(ctx, 0x800BB6ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2392);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800BB6B0:
    ctx->pc = 0x800BB6B0u;
    // 800BB6B0: stmw     r14, 2304(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2304);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BB6B4:
    ctx->pc = 0x800BB6B4u;
    // 800BB6B4: stw     r0, 2404(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2404);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB6B8:
    ctx->pc = 0x800BB6B8u;
    // 800BB6B8: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BB6BC:
    ctx->pc = 0x800BB6BCu;
    // 800BB6BC: lis     r9, -32698
    ctx->gpr[9] = ((u32)(s32)(-32698) << 16);

label_800BB6C0:
    ctx->pc = 0x800BB6C0u;
    // 800BB6C0: addi    r3, r1, 88
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(88);

label_800BB6C4:
    ctx->pc = 0x800BB6C4u;
    // 800BB6C4: addi    r18, r9, 7984
    ctx->gpr[18] = ctx->gpr[9] + (u32)(s32)(7984);

label_800BB6C8:
    ctx->pc = 0x800BB6C8u;
    // 800BB6C8: or   r21, r3, r3
    {
        ctx->gpr[21] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BB6CC:
    ctx->pc = 0x800BB6CCu;
    // 800BB6CC: lis     r31, -32698
    ctx->gpr[31] = ((u32)(s32)(-32698) << 16);

label_800BB6D0:
    ctx->pc = 0x800BB6D0u;
    // 800BB6D0: bl      0x80036150
    {
            ctx->lr = 0x800BB6D4u;
            ctx->pc = 0x80036150u;
            return;
    }

label_800BB6D4:
    ctx->pc = 0x800BB6D4u;
    ctx->downcount -= 5;
    // 800BB6D4: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_800BB6D8:
    ctx->pc = 0x800BB6D8u;
    // 800BB6D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BB6DC:
    ctx->pc = 0x800BB6DCu;
    // 800BB6DC: addi    r3, r3, 7924
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7924);

label_800BB6E0:
    ctx->pc = 0x800BB6E0u;
    // 800BB6E0: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BB6E4:
    ctx->pc = 0x800BB6E4u;
    // 800BB6E4: bl      0x801698F0
    {
            ctx->lr = 0x800BB6E8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BB6E8:
    ctx->pc = 0x800BB6E8u;
    ctx->downcount -= 2;
    // 800BB6E8: cmpwi   r26, 0
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

label_800BB6EC:
    ctx->pc = 0x800BB6ECu;
    // 800BB6EC: bc    12, 2, 0x800BC398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC398;
        }
    }

label_800BB6F0:
    ctx->pc = 0x800BB6F0u;
    ctx->downcount -= 3;
    // 800BB6F0: lwz     r11, 40(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BB6F4:
    ctx->pc = 0x800BB6F4u;
    // 800BB6F4: cmpwi   r11, 0
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

label_800BB6F8:
    ctx->pc = 0x800BB6F8u;
    // 800BB6F8: bc    12, 0, 0x800BC398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC398;
        }
    }

label_800BB6FC:
    ctx->pc = 0x800BB6FCu;
    ctx->downcount -= 3;
    // 800BB6FC: lwz     r0, 44(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB700:
    ctx->pc = 0x800BB700u;
    // 800BB700: cmpw    r11, r0
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

label_800BB704:
    ctx->pc = 0x800BB704u;
    // 800BB704: bc    4, 0, 0x800BC398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BC398;
        }
    }

label_800BB708:
    ctx->pc = 0x800BB708u;
    ctx->downcount -= 5;
    // 800BB708: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BB70C:
    ctx->pc = 0x800BB70Cu;
    // 800BB70C: rlwinm r0, r11, 6, 0, 25
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 6u) & 0xFFFFFFC0u;
    }

label_800BB710:
    ctx->pc = 0x800BB710u;
    // 800BB710: addi    r10, r9, -7212
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(-7212);

label_800BB714:
    ctx->pc = 0x800BB714u;
    // 800BB714: add.   r28, r0, r10
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[10];
        u32 res = a + b;
        ctx->gpr[28] = res;
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[28];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BB718:
    ctx->pc = 0x800BB718u;
    // 800BB718: bc    12, 2, 0x800BC398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC398;
        }
    }

label_800BB71C:
    ctx->pc = 0x800BB71Cu;
    ctx->downcount -= 30;
    // 800BB71C: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BB720:
    ctx->pc = 0x800BB720u;
    // 800BB720: lfs     f13, 1420(r26)
    if (!ppc_fp_available(ctx, 0x800BB720u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(1420);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BB724:
    ctx->pc = 0x800BB724u;
    // 800BB724: lfs     f12, -16048(r11)
    if (!ppc_fp_available(ctx, 0x800BB724u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16048);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BB728:
    ctx->pc = 0x800BB728u;
    // 800BB728: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BB72C:
    ctx->pc = 0x800BB72Cu;
    // 800BB72C: lfs     f0, 1424(r26)
    if (!ppc_fp_available(ctx, 0x800BB72Cu)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(1424);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BB730:
    ctx->pc = 0x800BB730u;
    // 800BB730: addi    r11, r1, 8
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(8);

label_800BB734:
    ctx->pc = 0x800BB734u;
    // 800BB734: fsubs   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x800BB734u)) return;
    ppc_fsubs(ctx, 13, 13, 12);

label_800BB738:
    ctx->pc = 0x800BB738u;
    // 800BB738: lfs     f11, -16044(r9)
    if (!ppc_fp_available(ctx, 0x800BB738u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16044);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800BB73C:
    ctx->pc = 0x800BB73Cu;
    // 800BB73C: stfs     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BB73Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BB740:
    ctx->pc = 0x800BB740u;
    // 800BB740: addi    r9, r1, 2248
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(2248);

label_800BB744:
    ctx->pc = 0x800BB744u;
    // 800BB744: fsubs   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x800BB744u)) return;
    ppc_fsubs(ctx, 0, 0, 11);

label_800BB748:
    ctx->pc = 0x800BB748u;
    // 800BB748: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BB74C:
    ctx->pc = 0x800BB74Cu;
    // 800BB74C: lwzx    r5, r10, r0
    {
        u32 ea = ctx->gpr[10] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BB750:
    ctx->pc = 0x800BB750u;
    // 800BB750: or   r27, r9, r9
    {
        ctx->gpr[27] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BB754:
    ctx->pc = 0x800BB754u;
    // 800BB754: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BB754u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BB758:
    ctx->pc = 0x800BB758u;
    // 800BB758: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BB75C:
    ctx->pc = 0x800BB75Cu;
    // 800BB75C: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB760:
    ctx->pc = 0x800BB760u;
    // 800BB760: or   r20, r11, r11
    {
        ctx->gpr[20] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BB764:
    ctx->pc = 0x800BB764u;
    // 800BB764: lwz     r10, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BB768:
    ctx->pc = 0x800BB768u;
    // 800BB768: or   r3, r18, r18
    {
        ctx->gpr[3] = ctx->gpr[18] | ctx->gpr[18];
    }

label_800BB76C:
    ctx->pc = 0x800BB76Cu;
    // 800BB76C: lwz     r8, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BB770:
    ctx->pc = 0x800BB770u;
    // 800BB770: ori     r6, r6, 0x0041
    ctx->gpr[6] = ctx->gpr[6] | 0x0041u;

label_800BB774:
    ctx->pc = 0x800BB774u;
    // 800BB774: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB778:
    ctx->pc = 0x800BB778u;
    // 800BB778: li      r7, 180
    ctx->gpr[7] = (u32)(s32)(180);

label_800BB77C:
    ctx->pc = 0x800BB77Cu;
    // 800BB77C: stw     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BB780:
    ctx->pc = 0x800BB780u;
    // 800BB780: stw     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BB784:
    ctx->pc = 0x800BB784u;
    // 800BB784: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BB788:
    ctx->pc = 0x800BB788u;
    // 800BB788: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BB78C:
    ctx->pc = 0x800BB78Cu;
    // 800BB78C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB790:
    ctx->pc = 0x800BB790u;
    // 800BB790: bl      0x800C3D88
    {
            ctx->lr = 0x800BB794u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BB794:
    ctx->pc = 0x800BB794u;
    ctx->downcount -= 3;
    // 800BB794: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB798:
    ctx->pc = 0x800BB798u;
    // 800BB798: cmpwi   r0, 2
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

label_800BB79C:
    ctx->pc = 0x800BB79Cu;
    // 800BB79C: bc    12, 2, 0x800BB944
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BB944;
        }
    }

label_800BB7A0:
    ctx->pc = 0x800BB7A0u;
    ctx->downcount -= 1;
    // 800BB7A0: bc    12, 1, 0x800BB7B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BB7B0;
        }
    }

label_800BB7A4:
    ctx->pc = 0x800BB7A4u;
    ctx->downcount -= 2;
    // 800BB7A4: cmpwi   r0, 1
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

label_800BB7A8:
    ctx->pc = 0x800BB7A8u;
    // 800BB7A8: bc    12, 2, 0x800BB7C4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BB7C4;
        }
    }

label_800BB7AC:
    ctx->pc = 0x800BB7ACu;
    ctx->downcount -= 1;
    // 800BB7AC: b       0x800BC398
    {
            goto label_800BC398;
    }

label_800BB7B0:
    ctx->pc = 0x800BB7B0u;
    ctx->downcount -= 2;
    // 800BB7B0: cmpwi   r0, 4
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

label_800BB7B4:
    ctx->pc = 0x800BB7B4u;
    // 800BB7B4: bc    12, 2, 0x800BBA68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BBA68;
        }
    }

label_800BB7B8:
    ctx->pc = 0x800BB7B8u;
    ctx->downcount -= 2;
    // 800BB7B8: cmpwi   r0, 8
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

label_800BB7BC:
    ctx->pc = 0x800BB7BCu;
    // 800BB7BC: bc    12, 2, 0x800BBC1C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BBC1C;
        }
    }

label_800BB7C0:
    ctx->pc = 0x800BB7C0u;
    ctx->downcount -= 1;
    // 800BB7C0: b       0x800BC398
    {
            goto label_800BC398;
    }

label_800BB7C4:
    ctx->pc = 0x800BB7C4u;
    ctx->downcount -= 16;
    // 800BB7C4: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BB7C8:
    ctx->pc = 0x800BB7C8u;
    // 800BB7C8: addi    r9, r28, 16
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(16);

label_800BB7CC:
    ctx->pc = 0x800BB7CCu;
    // 800BB7CC: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BB7D0:
    ctx->pc = 0x800BB7D0u;
    // 800BB7D0: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BB7D4:
    ctx->pc = 0x800BB7D4u;
    // 800BB7D4: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB7D8:
    ctx->pc = 0x800BB7D8u;
    // 800BB7D8: li      r6, 16384
    ctx->gpr[6] = (u32)(s32)(16384);

label_800BB7DC:
    ctx->pc = 0x800BB7DCu;
    // 800BB7DC: lwz     r5, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BB7E0:
    ctx->pc = 0x800BB7E0u;
    // 800BB7E0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB7E4:
    ctx->pc = 0x800BB7E4u;
    // 800BB7E4: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BB7E8:
    ctx->pc = 0x800BB7E8u;
    // 800BB7E8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BB7EC:
    ctx->pc = 0x800BB7ECu;
    // 800BB7EC: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BB7F0:
    ctx->pc = 0x800BB7F0u;
    // 800BB7F0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BB7F4:
    ctx->pc = 0x800BB7F4u;
    // 800BB7F4: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB7F8:
    ctx->pc = 0x800BB7F8u;
    // 800BB7F8: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BB7FC:
    ctx->pc = 0x800BB7FCu;
    // 800BB7FC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB800:
    ctx->pc = 0x800BB800u;
    // 800BB800: bl      0x800C3D88
    {
            ctx->lr = 0x800BB804u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BB804:
    ctx->pc = 0x800BB804u;
    ctx->downcount -= 16;
    // 800BB804: lwz     r11, 28(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BB808:
    ctx->pc = 0x800BB808u;
    // 800BB808: addi    r9, r28, 28
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(28);

label_800BB80C:
    ctx->pc = 0x800BB80Cu;
    // 800BB80C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB810:
    ctx->pc = 0x800BB810u;
    // 800BB810: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BB814:
    ctx->pc = 0x800BB814u;
    // 800BB814: lwz     r5, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BB818:
    ctx->pc = 0x800BB818u;
    // 800BB818: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BB81C:
    ctx->pc = 0x800BB81Cu;
    // 800BB81C: lwz     r4, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BB820:
    ctx->pc = 0x800BB820u;
    // 800BB820: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BB824:
    ctx->pc = 0x800BB824u;
    // 800BB824: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BB828:
    ctx->pc = 0x800BB828u;
    // 800BB828: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB82C:
    ctx->pc = 0x800BB82Cu;
    // 800BB82C: stw     r4, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_800BB830:
    ctx->pc = 0x800BB830u;
    // 800BB830: li      r6, 16384
    ctx->gpr[6] = (u32)(s32)(16384);

label_800BB834:
    ctx->pc = 0x800BB834u;
    // 800BB834: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB838:
    ctx->pc = 0x800BB838u;
    // 800BB838: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BB83C:
    ctx->pc = 0x800BB83Cu;
    // 800BB83C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB840:
    ctx->pc = 0x800BB840u;
    // 800BB840: bl      0x800C3D88
    {
            ctx->lr = 0x800BB844u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BB844:
    ctx->pc = 0x800BB844u;
    ctx->downcount -= 2;
    // 800BB844: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB848:
    ctx->pc = 0x800BB848u;
    // 800BB848: bl      0x80159D80
    {
            ctx->lr = 0x800BB84Cu;
            ctx->pc = 0x80159D80u;
            return;
    }

label_800BB84C:
    ctx->pc = 0x800BB84Cu;
    ctx->downcount -= 3;
    // 800BB84C: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BB850:
    ctx->pc = 0x800BB850u;
    // 800BB850: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB854:
    ctx->pc = 0x800BB854u;
    // 800BB854: bl      0x80159DA8
    {
            ctx->lr = 0x800BB858u;
            ctx->pc = 0x80159DA8u;
            return;
    }

label_800BB858:
    ctx->pc = 0x800BB858u;
    ctx->downcount -= 5;
    // 800BB858: subf   r30, r3, r30
    {
        u32 a = ~ctx->gpr[3];
        u32 b = ctx->gpr[30];
        u32 res = a + b + 1u;
        ctx->gpr[30] = res;
    }

label_800BB85C:
    ctx->pc = 0x800BB85Cu;
    // 800BB85C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BB860:
    ctx->pc = 0x800BB860u;
    // 800BB860: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BB864:
    ctx->pc = 0x800BB864u;
    // 800BB864: addi    r3, r31, 7924
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BB868:
    ctx->pc = 0x800BB868u;
    // 800BB868: bl      0x801698F0
    {
            ctx->lr = 0x800BB86Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BB86C:
    ctx->pc = 0x800BB86Cu;
    ctx->downcount -= 2;
    // 800BB86C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BB870:
    ctx->pc = 0x800BB870u;
    // 800BB870: bl      0x80036180
    {
            ctx->lr = 0x800BB874u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BB874:
    ctx->pc = 0x800BB874u;
    ctx->downcount -= 5;
    // 800BB874: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BB878:
    ctx->pc = 0x800BB878u;
    // 800BB878: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BB87C:
    ctx->pc = 0x800BB87Cu;
    // 800BB87C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BB880:
    ctx->pc = 0x800BB880u;
    // 800BB880: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BB884:
    ctx->pc = 0x800BB884u;
    // 800BB884: bl      0x800361A8
    {
            ctx->lr = 0x800BB888u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BB888:
    ctx->pc = 0x800BB888u;
    ctx->downcount -= 4;
    // 800BB888: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_800BB88C:
    ctx->pc = 0x800BB88Cu;
    // 800BB88C: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BB890:
    ctx->pc = 0x800BB890u;
    // 800BB890: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_800BB894:
    ctx->pc = 0x800BB894u;
    // 800BB894: bl      0x80046B00
    {
            ctx->lr = 0x800BB898u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BB898:
    ctx->pc = 0x800BB898u;
    ctx->downcount -= 5;
    // 800BB898: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BB89C:
    ctx->pc = 0x800BB89Cu;
    // 800BB89C: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BB8A0:
    ctx->pc = 0x800BB8A0u;
    // 800BB8A0: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BB8A4:
    ctx->pc = 0x800BB8A4u;
    // 800BB8A4: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BB8A8:
    ctx->pc = 0x800BB8A8u;
    // 800BB8A8: bl      0x8003632C
    {
            ctx->lr = 0x800BB8ACu;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BB8AC:
    ctx->pc = 0x800BB8ACu;
    ctx->downcount -= 17;
    // 800BB8AC: lwz     r11, 40(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BB8B0:
    ctx->pc = 0x800BB8B0u;
    // 800BB8B0: addi    r9, r28, 40
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(40);

label_800BB8B4:
    ctx->pc = 0x800BB8B4u;
    // 800BB8B4: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BB8B8:
    ctx->pc = 0x800BB8B8u;
    // 800BB8B8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BB8BC:
    ctx->pc = 0x800BB8BCu;
    // 800BB8BC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB8C0:
    ctx->pc = 0x800BB8C0u;
    // 800BB8C0: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BB8C4:
    ctx->pc = 0x800BB8C4u;
    // 800BB8C4: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BB8C8:
    ctx->pc = 0x800BB8C8u;
    // 800BB8C8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB8CC:
    ctx->pc = 0x800BB8CCu;
    // 800BB8CC: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BB8D0:
    ctx->pc = 0x800BB8D0u;
    // 800BB8D0: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BB8D4:
    ctx->pc = 0x800BB8D4u;
    // 800BB8D4: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB8D8:
    ctx->pc = 0x800BB8D8u;
    // 800BB8D8: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BB8DC:
    ctx->pc = 0x800BB8DCu;
    // 800BB8DC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BB8E0:
    ctx->pc = 0x800BB8E0u;
    // 800BB8E0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BB8E4:
    ctx->pc = 0x800BB8E4u;
    // 800BB8E4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB8E8:
    ctx->pc = 0x800BB8E8u;
    // 800BB8E8: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BB8EC:
    ctx->pc = 0x800BB8ECu;
    // 800BB8EC: bl      0x800C3E20
    {
            ctx->lr = 0x800BB8F0u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BB8F0:
    ctx->pc = 0x800BB8F0u;
    ctx->downcount -= 2;
    // 800BB8F0: cmpwi   r30, 0
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

label_800BB8F4:
    ctx->pc = 0x800BB8F4u;
    // 800BB8F4: bc    12, 2, 0x800BC398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC398;
        }
    }

label_800BB8F8:
    ctx->pc = 0x800BB8F8u;
    ctx->downcount -= 2;
    // 800BB8F8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BB8FC:
    ctx->pc = 0x800BB8FCu;
    // 800BB8FC: bl      0x800BAC48
    {
            ctx->lr = 0x800BB900u;
            ctx->pc = 0x800BAC48u;
            return;
    }

label_800BB900:
    ctx->pc = 0x800BB900u;
    ctx->downcount -= 17;
    // 800BB900: sth     r3, 2266(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2266);
        mem_write16(ctx, ea, (u16)ctx->gpr[3]);
    }

label_800BB904:
    ctx->pc = 0x800BB904u;
    // 800BB904: addi    r9, r28, 52
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(52);

label_800BB908:
    ctx->pc = 0x800BB908u;
    // 800BB908: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BB90C:
    ctx->pc = 0x800BB90Cu;
    // 800BB90C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BB910:
    ctx->pc = 0x800BB910u;
    // 800BB910: lwz     r11, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BB914:
    ctx->pc = 0x800BB914u;
    // 800BB914: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB918:
    ctx->pc = 0x800BB918u;
    // 800BB918: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BB91C:
    ctx->pc = 0x800BB91Cu;
    // 800BB91C: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BB920:
    ctx->pc = 0x800BB920u;
    // 800BB920: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB924:
    ctx->pc = 0x800BB924u;
    // 800BB924: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BB928:
    ctx->pc = 0x800BB928u;
    // 800BB928: lhz     r5, 2266(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2266);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BB92C:
    ctx->pc = 0x800BB92Cu;
    // 800BB92C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BB930:
    ctx->pc = 0x800BB930u;
    // 800BB930: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BB934:
    ctx->pc = 0x800BB934u;
    // 800BB934: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB938:
    ctx->pc = 0x800BB938u;
    // 800BB938: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BB93C:
    ctx->pc = 0x800BB93Cu;
    // 800BB93C: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB940:
    ctx->pc = 0x800BB940u;
    // 800BB940: b       0x800BBC10
    {
            goto label_800BBC10;
    }

label_800BB944:
    ctx->pc = 0x800BB944u;
    ctx->downcount -= 16;
    // 800BB944: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BB948:
    ctx->pc = 0x800BB948u;
    // 800BB948: addi    r9, r28, 16
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(16);

label_800BB94C:
    ctx->pc = 0x800BB94Cu;
    // 800BB94C: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BB950:
    ctx->pc = 0x800BB950u;
    // 800BB950: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BB954:
    ctx->pc = 0x800BB954u;
    // 800BB954: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB958:
    ctx->pc = 0x800BB958u;
    // 800BB958: li      r6, 16384
    ctx->gpr[6] = (u32)(s32)(16384);

label_800BB95C:
    ctx->pc = 0x800BB95Cu;
    // 800BB95C: lwz     r5, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BB960:
    ctx->pc = 0x800BB960u;
    // 800BB960: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB964:
    ctx->pc = 0x800BB964u;
    // 800BB964: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BB968:
    ctx->pc = 0x800BB968u;
    // 800BB968: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BB96C:
    ctx->pc = 0x800BB96Cu;
    // 800BB96C: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BB970:
    ctx->pc = 0x800BB970u;
    // 800BB970: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BB974:
    ctx->pc = 0x800BB974u;
    // 800BB974: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB978:
    ctx->pc = 0x800BB978u;
    // 800BB978: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BB97C:
    ctx->pc = 0x800BB97Cu;
    // 800BB97C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB980:
    ctx->pc = 0x800BB980u;
    // 800BB980: bl      0x800C3D88
    {
            ctx->lr = 0x800BB984u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BB984:
    ctx->pc = 0x800BB984u;
    ctx->downcount -= 16;
    // 800BB984: lwz     r11, 28(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BB988:
    ctx->pc = 0x800BB988u;
    // 800BB988: addi    r9, r28, 28
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(28);

label_800BB98C:
    ctx->pc = 0x800BB98Cu;
    // 800BB98C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BB990:
    ctx->pc = 0x800BB990u;
    // 800BB990: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BB994:
    ctx->pc = 0x800BB994u;
    // 800BB994: lwz     r4, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BB998:
    ctx->pc = 0x800BB998u;
    // 800BB998: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BB99C:
    ctx->pc = 0x800BB99Cu;
    // 800BB99C: lwz     r5, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BB9A0:
    ctx->pc = 0x800BB9A0u;
    // 800BB9A0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BB9A4:
    ctx->pc = 0x800BB9A4u;
    // 800BB9A4: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BB9A8:
    ctx->pc = 0x800BB9A8u;
    // 800BB9A8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BB9AC:
    ctx->pc = 0x800BB9ACu;
    // 800BB9AC: stw     r4, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_800BB9B0:
    ctx->pc = 0x800BB9B0u;
    // 800BB9B0: li      r6, 16384
    ctx->gpr[6] = (u32)(s32)(16384);

label_800BB9B4:
    ctx->pc = 0x800BB9B4u;
    // 800BB9B4: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BB9B8:
    ctx->pc = 0x800BB9B8u;
    // 800BB9B8: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BB9BC:
    ctx->pc = 0x800BB9BCu;
    // 800BB9BC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BB9C0:
    ctx->pc = 0x800BB9C0u;
    // 800BB9C0: bl      0x800C3D88
    {
            ctx->lr = 0x800BB9C4u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BB9C4:
    ctx->pc = 0x800BB9C4u;
    ctx->downcount -= 4;
    // 800BB9C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BB9C8:
    ctx->pc = 0x800BB9C8u;
    // 800BB9C8: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BB9CC:
    ctx->pc = 0x800BB9CCu;
    // 800BB9CC: addi    r3, r31, 7924
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BB9D0:
    ctx->pc = 0x800BB9D0u;
    // 800BB9D0: bl      0x801698F0
    {
            ctx->lr = 0x800BB9D4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BB9D4:
    ctx->pc = 0x800BB9D4u;
    ctx->downcount -= 2;
    // 800BB9D4: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BB9D8:
    ctx->pc = 0x800BB9D8u;
    // 800BB9D8: bl      0x80036180
    {
            ctx->lr = 0x800BB9DCu;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BB9DC:
    ctx->pc = 0x800BB9DCu;
    ctx->downcount -= 7;
    // 800BB9DC: lis     r30, -32699
    ctx->gpr[30] = ((u32)(s32)(-32699) << 16);

label_800BB9E0:
    ctx->pc = 0x800BB9E0u;
    // 800BB9E0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BB9E4:
    ctx->pc = 0x800BB9E4u;
    // 800BB9E4: addi    r30, r30, -21636
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-21636);

label_800BB9E8:
    ctx->pc = 0x800BB9E8u;
    // 800BB9E8: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BB9EC:
    ctx->pc = 0x800BB9ECu;
    // 800BB9EC: lhz     r5, 212(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(212);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BB9F0:
    ctx->pc = 0x800BB9F0u;
    // 800BB9F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BB9F4:
    ctx->pc = 0x800BB9F4u;
    // 800BB9F4: bl      0x800361A8
    {
            ctx->lr = 0x800BB9F8u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BB9F8:
    ctx->pc = 0x800BB9F8u;
    ctx->downcount -= 4;
    // 800BB9F8: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_800BB9FC:
    ctx->pc = 0x800BB9FCu;
    // 800BB9FC: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BBA00:
    ctx->pc = 0x800BBA00u;
    // 800BBA00: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_800BBA04:
    ctx->pc = 0x800BBA04u;
    // 800BBA04: bl      0x80046B00
    {
            ctx->lr = 0x800BBA08u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BBA08:
    ctx->pc = 0x800BBA08u;
    ctx->downcount -= 5;
    // 800BBA08: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BBA0C:
    ctx->pc = 0x800BBA0Cu;
    // 800BBA0C: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBA10:
    ctx->pc = 0x800BBA10u;
    // 800BBA10: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BBA14:
    ctx->pc = 0x800BBA14u;
    // 800BBA14: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BBA18:
    ctx->pc = 0x800BBA18u;
    // 800BBA18: bl      0x8003632C
    {
            ctx->lr = 0x800BBA1Cu;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BBA1C:
    ctx->pc = 0x800BBA1Cu;
    ctx->downcount -= 17;
    // 800BBA1C: lwz     r11, 40(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBA20:
    ctx->pc = 0x800BBA20u;
    // 800BBA20: addi    r9, r28, 40
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(40);

label_800BBA24:
    ctx->pc = 0x800BBA24u;
    // 800BBA24: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BBA28:
    ctx->pc = 0x800BBA28u;
    // 800BBA28: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBA2C:
    ctx->pc = 0x800BBA2Cu;
    // 800BBA2C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBA30:
    ctx->pc = 0x800BBA30u;
    // 800BBA30: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBA34:
    ctx->pc = 0x800BBA34u;
    // 800BBA34: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBA38:
    ctx->pc = 0x800BBA38u;
    // 800BBA38: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBA3C:
    ctx->pc = 0x800BBA3Cu;
    // 800BBA3C: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BBA40:
    ctx->pc = 0x800BBA40u;
    // 800BBA40: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBA44:
    ctx->pc = 0x800BBA44u;
    // 800BBA44: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBA48:
    ctx->pc = 0x800BBA48u;
    // 800BBA48: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBA4C:
    ctx->pc = 0x800BBA4Cu;
    // 800BBA4C: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBA50:
    ctx->pc = 0x800BBA50u;
    // 800BBA50: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BBA54:
    ctx->pc = 0x800BBA54u;
    // 800BBA54: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBA58:
    ctx->pc = 0x800BBA58u;
    // 800BBA58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBA5C:
    ctx->pc = 0x800BBA5Cu;
    // 800BBA5C: bl      0x800C3E20
    {
            ctx->lr = 0x800BBA60u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BBA60:
    ctx->pc = 0x800BBA60u;
    ctx->downcount -= 2;
    // 800BBA60: lhz     r11, 216(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(216);
        ctx->gpr[11] = mem_read16(ctx, ea);
    }

label_800BBA64:
    ctx->pc = 0x800BBA64u;
    // 800BBA64: b       0x800BBBBC
    {
            goto label_800BBBBC;
    }

label_800BBA68:
    ctx->pc = 0x800BBA68u;
    ctx->downcount -= 17;
    // 800BBA68: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBA6C:
    ctx->pc = 0x800BBA6Cu;
    // 800BBA6C: addi    r9, r28, 16
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(16);

label_800BBA70:
    ctx->pc = 0x800BBA70u;
    // 800BBA70: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BBA74:
    ctx->pc = 0x800BBA74u;
    // 800BBA74: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBA78:
    ctx->pc = 0x800BBA78u;
    // 800BBA78: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBA7C:
    ctx->pc = 0x800BBA7Cu;
    // 800BBA7C: li      r6, 16384
    ctx->gpr[6] = (u32)(s32)(16384);

label_800BBA80:
    ctx->pc = 0x800BBA80u;
    // 800BBA80: lwz     r5, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BBA84:
    ctx->pc = 0x800BBA84u;
    // 800BBA84: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBA88:
    ctx->pc = 0x800BBA88u;
    // 800BBA88: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBA8C:
    ctx->pc = 0x800BBA8Cu;
    // 800BBA8C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBA90:
    ctx->pc = 0x800BBA90u;
    // 800BBA90: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BBA94:
    ctx->pc = 0x800BBA94u;
    // 800BBA94: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBA98:
    ctx->pc = 0x800BBA98u;
    // 800BBA98: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBA9C:
    ctx->pc = 0x800BBA9Cu;
    // 800BBA9C: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBAA0:
    ctx->pc = 0x800BBAA0u;
    // 800BBAA0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBAA4:
    ctx->pc = 0x800BBAA4u;
    // 800BBAA4: lis     r30, -30584
    ctx->gpr[30] = ((u32)(s32)(-30584) << 16);

label_800BBAA8:
    ctx->pc = 0x800BBAA8u;
    // 800BBAA8: bl      0x800C3D88
    {
            ctx->lr = 0x800BBAACu;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BBAAC:
    ctx->pc = 0x800BBAACu;
    ctx->downcount -= 17;
    // 800BBAAC: ori     r30, r30, 0x8889
    ctx->gpr[30] = ctx->gpr[30] | 0x8889u;

label_800BBAB0:
    ctx->pc = 0x800BBAB0u;
    // 800BBAB0: lwz     r11, 28(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBAB4:
    ctx->pc = 0x800BBAB4u;
    // 800BBAB4: addi    r9, r28, 28
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(28);

label_800BBAB8:
    ctx->pc = 0x800BBAB8u;
    // 800BBAB8: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBABC:
    ctx->pc = 0x800BBABCu;
    // 800BBABC: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBAC0:
    ctx->pc = 0x800BBAC0u;
    // 800BBAC0: lwz     r4, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BBAC4:
    ctx->pc = 0x800BBAC4u;
    // 800BBAC4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBAC8:
    ctx->pc = 0x800BBAC8u;
    // 800BBAC8: lwz     r5, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BBACC:
    ctx->pc = 0x800BBACCu;
    // 800BBACC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBAD0:
    ctx->pc = 0x800BBAD0u;
    // 800BBAD0: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBAD4:
    ctx->pc = 0x800BBAD4u;
    // 800BBAD4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBAD8:
    ctx->pc = 0x800BBAD8u;
    // 800BBAD8: stw     r4, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_800BBADC:
    ctx->pc = 0x800BBADCu;
    // 800BBADC: li      r6, 16384
    ctx->gpr[6] = (u32)(s32)(16384);

label_800BBAE0:
    ctx->pc = 0x800BBAE0u;
    // 800BBAE0: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBAE4:
    ctx->pc = 0x800BBAE4u;
    // 800BBAE4: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBAE8:
    ctx->pc = 0x800BBAE8u;
    // 800BBAE8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBAEC:
    ctx->pc = 0x800BBAECu;
    // 800BBAEC: bl      0x800C3D88
    {
            ctx->lr = 0x800BBAF0u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BBAF0:
    ctx->pc = 0x800BBAF0u;
    ctx->downcount -= 4;
    // 800BBAF0: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BBAF4:
    ctx->pc = 0x800BBAF4u;
    // 800BBAF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBAF8:
    ctx->pc = 0x800BBAF8u;
    // 800BBAF8: addi    r3, r31, 7924
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBAFC:
    ctx->pc = 0x800BBAFCu;
    // 800BBAFC: bl      0x801698F0
    {
            ctx->lr = 0x800BBB00u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BBB00:
    ctx->pc = 0x800BBB00u;
    ctx->downcount -= 2;
    // 800BBB00: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BBB04:
    ctx->pc = 0x800BBB04u;
    // 800BBB04: bl      0x80036180
    {
            ctx->lr = 0x800BBB08u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BBB08:
    ctx->pc = 0x800BBB08u;
    ctx->downcount -= 13;
    // 800BBB08: lis     r29, -32699
    ctx->gpr[29] = ((u32)(s32)(-32699) << 16);

label_800BBB0C:
    ctx->pc = 0x800BBB0Cu;
    // 800BBB0C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BBB10:
    ctx->pc = 0x800BBB10u;
    // 800BBB10: addi    r29, r29, -21636
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-21636);

label_800BBB14:
    ctx->pc = 0x800BBB14u;
    // 800BBB14: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBB18:
    ctx->pc = 0x800BBB18u;
    // 800BBB18: lwz     r5, 196(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(196);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BBB1C:
    ctx->pc = 0x800BBB1Cu;
    // 800BBB1C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBB20:
    ctx->pc = 0x800BBB20u;
    // 800BBB20: mulhwu   r5, r5, r30
    {
        u64 product = (u64)ctx->gpr[5] * (u64)ctx->gpr[30];
        ctx->gpr[5] = (u32)(product >> 32);
    }

label_800BBB24:
    ctx->pc = 0x800BBB24u;
    // 800BBB24: rlwinm r5, r5, 27, 5, 31
    {
        ctx->gpr[5] = dolrecomp_rotl32(ctx->gpr[5], 27u) & 0x07FFFFFFu;
    }

label_800BBB28:
    ctx->pc = 0x800BBB28u;
    // 800BBB28: bl      0x800361A8
    {
            ctx->lr = 0x800BBB2Cu;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BBB2C:
    ctx->pc = 0x800BBB2Cu;
    ctx->downcount -= 15;
    // 800BBB2C: lwz     r5, 196(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(196);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BBB30:
    ctx->pc = 0x800BBB30u;
    // 800BBB30: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_800BBB34:
    ctx->pc = 0x800BBB34u;
    // 800BBB34: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BBB38:
    ctx->pc = 0x800BBB38u;
    // 800BBB38: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BBB3C:
    ctx->pc = 0x800BBB3Cu;
    // 800BBB3C: mulhwu   r30, r5, r30
    {
        u64 product = (u64)ctx->gpr[5] * (u64)ctx->gpr[30];
        ctx->gpr[30] = (u32)(product >> 32);
    }

label_800BBB40:
    ctx->pc = 0x800BBB40u;
    // 800BBB40: rlwinm r30, r30, 27, 5, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 27u) & 0x07FFFFFFu;
    }

label_800BBB44:
    ctx->pc = 0x800BBB44u;
    // 800BBB44: mulli   r30, r30, 60
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[30] * (s64)(s32)60);

label_800BBB48:
    ctx->pc = 0x800BBB48u;
    // 800BBB48: subf   r5, r30, r5
    {
        u32 a = ~ctx->gpr[30];
        u32 b = ctx->gpr[5];
        u32 res = a + b + 1u;
        ctx->gpr[5] = res;
    }

label_800BBB4C:
    ctx->pc = 0x800BBB4Cu;
    // 800BBB4C: bl      0x800361A8
    {
            ctx->lr = 0x800BBB50u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BBB50:
    ctx->pc = 0x800BBB50u;
    ctx->downcount -= 4;
    // 800BBB50: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_800BBB54:
    ctx->pc = 0x800BBB54u;
    // 800BBB54: li      r4, 3750
    ctx->gpr[4] = (u32)(s32)(3750);

label_800BBB58:
    ctx->pc = 0x800BBB58u;
    // 800BBB58: addi    r3, r3, 9872
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(9872);

label_800BBB5C:
    ctx->pc = 0x800BBB5Cu;
    // 800BBB5C: bl      0x80046B00
    {
            ctx->lr = 0x800BBB60u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BBB60:
    ctx->pc = 0x800BBB60u;
    ctx->downcount -= 5;
    // 800BBB60: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BBB64:
    ctx->pc = 0x800BBB64u;
    // 800BBB64: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBB68:
    ctx->pc = 0x800BBB68u;
    // 800BBB68: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BBB6C:
    ctx->pc = 0x800BBB6Cu;
    // 800BBB6C: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BBB70:
    ctx->pc = 0x800BBB70u;
    // 800BBB70: bl      0x8003632C
    {
            ctx->lr = 0x800BBB74u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BBB74:
    ctx->pc = 0x800BBB74u;
    ctx->downcount -= 17;
    // 800BBB74: lwz     r11, 40(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBB78:
    ctx->pc = 0x800BBB78u;
    // 800BBB78: addi    r9, r28, 40
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(40);

label_800BBB7C:
    ctx->pc = 0x800BBB7Cu;
    // 800BBB7C: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BBB80:
    ctx->pc = 0x800BBB80u;
    // 800BBB80: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBB84:
    ctx->pc = 0x800BBB84u;
    // 800BBB84: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBB88:
    ctx->pc = 0x800BBB88u;
    // 800BBB88: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBB8C:
    ctx->pc = 0x800BBB8Cu;
    // 800BBB8C: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBB90:
    ctx->pc = 0x800BBB90u;
    // 800BBB90: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBB94:
    ctx->pc = 0x800BBB94u;
    // 800BBB94: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BBB98:
    ctx->pc = 0x800BBB98u;
    // 800BBB98: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBB9C:
    ctx->pc = 0x800BBB9Cu;
    // 800BBB9C: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBBA0:
    ctx->pc = 0x800BBBA0u;
    // 800BBBA0: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBBA4:
    ctx->pc = 0x800BBBA4u;
    // 800BBBA4: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBBA8:
    ctx->pc = 0x800BBBA8u;
    // 800BBBA8: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BBBAC:
    ctx->pc = 0x800BBBACu;
    // 800BBBAC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBBB0:
    ctx->pc = 0x800BBBB0u;
    // 800BBBB0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBBB4:
    ctx->pc = 0x800BBBB4u;
    // 800BBBB4: bl      0x800C3E20
    {
            ctx->lr = 0x800BBBB8u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BBBB8:
    ctx->pc = 0x800BBBB8u;
    ctx->downcount -= 1;
    // 800BBBB8: lhz     r11, 204(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(204);
        ctx->gpr[11] = mem_read16(ctx, ea);
    }

label_800BBBBC:
    ctx->pc = 0x800BBBBCu;
    ctx->downcount -= 21;
    // 800BBBBC: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BBBC0:
    ctx->pc = 0x800BBBC0u;
    // 800BBBC0: addi    r9, r9, -6892
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-6892);

label_800BBBC4:
    ctx->pc = 0x800BBBC4u;
    // 800BBBC4: addi    r10, r28, 52
    ctx->gpr[10] = ctx->gpr[28] + (u32)(s32)(52);

label_800BBBC8:
    ctx->pc = 0x800BBBC8u;
    // 800BBBC8: rlwinm r11, r11, 2, 0, 29
    {
        ctx->gpr[11] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_800BBBCC:
    ctx->pc = 0x800BBBCCu;
    // 800BBBCC: lwz     r8, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BBBD0:
    ctx->pc = 0x800BBBD0u;
    // 800BBBD0: add   r11, r11, r9
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800BBBD4:
    ctx->pc = 0x800BBBD4u;
    // 800BBBD4: lwz     r30, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800BBBD8:
    ctx->pc = 0x800BBBD8u;
    // 800BBBD8: lhz     r0, 2(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BBBDC:
    ctx->pc = 0x800BBBDCu;
    // 800BBBDC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBBE0:
    ctx->pc = 0x800BBBE0u;
    // 800BBBE0: lwz     r9, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BBBE4:
    ctx->pc = 0x800BBBE4u;
    // 800BBBE4: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBBE8:
    ctx->pc = 0x800BBBE8u;
    // 800BBBE8: sth     r0, 2266(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2266);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_800BBBEC:
    ctx->pc = 0x800BBBECu;
    // 800BBBEC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBBF0:
    ctx->pc = 0x800BBBF0u;
    // 800BBBF0: stw     r8, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BBBF4:
    ctx->pc = 0x800BBBF4u;
    // 800BBBF4: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BBBF8:
    ctx->pc = 0x800BBBF8u;
    // 800BBBF8: lhz     r5, 2266(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2266);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BBBFC:
    ctx->pc = 0x800BBBFCu;
    // 800BBBFC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBC00:
    ctx->pc = 0x800BBC00u;
    // 800BBC00: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BBC04:
    ctx->pc = 0x800BBC04u;
    // 800BBC04: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBC08:
    ctx->pc = 0x800BBC08u;
    // 800BBC08: stw     r30, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BBC0C:
    ctx->pc = 0x800BBC0Cu;
    // 800BBC0C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBC10:
    ctx->pc = 0x800BBC10u;
    ctx->downcount -= 2;
    // 800BBC10: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBC14:
    ctx->pc = 0x800BBC14u;
    // 800BBC14: bl      0x800C3D88
    {
            ctx->lr = 0x800BBC18u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BBC18:
    ctx->pc = 0x800BBC18u;
    ctx->downcount -= 1;
    // 800BBC18: b       0x800BC398
    {
            goto label_800BC398;
    }

label_800BBC1C:
    ctx->pc = 0x800BBC1Cu;
    ctx->downcount -= 17;
    // 800BBC1C: lwz     r11, 28(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBC20:
    ctx->pc = 0x800BBC20u;
    // 800BBC20: addi    r9, r28, 28
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(28);

label_800BBC24:
    ctx->pc = 0x800BBC24u;
    // 800BBC24: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BBC28:
    ctx->pc = 0x800BBC28u;
    // 800BBC28: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BBC2C:
    ctx->pc = 0x800BBC2Cu;
    // 800BBC2C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBC30:
    ctx->pc = 0x800BBC30u;
    // 800BBC30: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBC34:
    ctx->pc = 0x800BBC34u;
    // 800BBC34: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBC38:
    ctx->pc = 0x800BBC38u;
    // 800BBC38: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBC3C:
    ctx->pc = 0x800BBC3Cu;
    // 800BBC3C: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BBC40:
    ctx->pc = 0x800BBC40u;
    // 800BBC40: li      r5, 3752
    ctx->gpr[5] = (u32)(s32)(3752);

label_800BBC44:
    ctx->pc = 0x800BBC44u;
    // 800BBC44: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBC48:
    ctx->pc = 0x800BBC48u;
    // 800BBC48: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBC4C:
    ctx->pc = 0x800BBC4Cu;
    // 800BBC4C: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BBC50:
    ctx->pc = 0x800BBC50u;
    // 800BBC50: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBC54:
    ctx->pc = 0x800BBC54u;
    // 800BBC54: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBC58:
    ctx->pc = 0x800BBC58u;
    // 800BBC58: or   r3, r18, r18
    {
        ctx->gpr[3] = ctx->gpr[18] | ctx->gpr[18];
    }

label_800BBC5C:
    ctx->pc = 0x800BBC5Cu;
    // 800BBC5C: bl      0x800C3D88
    {
            ctx->lr = 0x800BBC60u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BBC60:
    ctx->pc = 0x800BBC60u;
    ctx->downcount -= 18;
    // 800BBC60: li      r22, 0
    ctx->gpr[22] = (u32)(s32)(0);

label_800BBC64:
    ctx->pc = 0x800BBC64u;
    // 800BBC64: lwz     r11, 40(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBC68:
    ctx->pc = 0x800BBC68u;
    // 800BBC68: addi    r9, r28, 40
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(40);

label_800BBC6C:
    ctx->pc = 0x800BBC6Cu;
    // 800BBC6C: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BBC70:
    ctx->pc = 0x800BBC70u;
    // 800BBC70: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BBC74:
    ctx->pc = 0x800BBC74u;
    // 800BBC74: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBC78:
    ctx->pc = 0x800BBC78u;
    // 800BBC78: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBC7C:
    ctx->pc = 0x800BBC7Cu;
    // 800BBC7C: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBC80:
    ctx->pc = 0x800BBC80u;
    // 800BBC80: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBC84:
    ctx->pc = 0x800BBC84u;
    // 800BBC84: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BBC88:
    ctx->pc = 0x800BBC88u;
    // 800BBC88: li      r5, 3754
    ctx->gpr[5] = (u32)(s32)(3754);

label_800BBC8C:
    ctx->pc = 0x800BBC8Cu;
    // 800BBC8C: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBC90:
    ctx->pc = 0x800BBC90u;
    // 800BBC90: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBC94:
    ctx->pc = 0x800BBC94u;
    // 800BBC94: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BBC98:
    ctx->pc = 0x800BBC98u;
    // 800BBC98: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBC9C:
    ctx->pc = 0x800BBC9Cu;
    // 800BBC9C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBCA0:
    ctx->pc = 0x800BBCA0u;
    // 800BBCA0: or   r3, r18, r18
    {
        ctx->gpr[3] = ctx->gpr[18] | ctx->gpr[18];
    }

label_800BBCA4:
    ctx->pc = 0x800BBCA4u;
    // 800BBCA4: bl      0x800C3D88
    {
            ctx->lr = 0x800BBCA8u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BBCA8:
    ctx->pc = 0x800BBCA8u;
    ctx->downcount -= 18;
    // 800BBCA8: lis     r31, -32698
    ctx->gpr[31] = ((u32)(s32)(-32698) << 16);

label_800BBCAC:
    ctx->pc = 0x800BBCACu;
    // 800BBCAC: lwz     r11, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBCB0:
    ctx->pc = 0x800BBCB0u;
    // 800BBCB0: addi    r9, r28, 52
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(52);

label_800BBCB4:
    ctx->pc = 0x800BBCB4u;
    // 800BBCB4: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BBCB8:
    ctx->pc = 0x800BBCB8u;
    // 800BBCB8: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BBCBC:
    ctx->pc = 0x800BBCBCu;
    // 800BBCBC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBCC0:
    ctx->pc = 0x800BBCC0u;
    // 800BBCC0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBCC4:
    ctx->pc = 0x800BBCC4u;
    // 800BBCC4: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBCC8:
    ctx->pc = 0x800BBCC8u;
    // 800BBCC8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBCCC:
    ctx->pc = 0x800BBCCCu;
    // 800BBCCC: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BBCD0:
    ctx->pc = 0x800BBCD0u;
    // 800BBCD0: or   r3, r18, r18
    {
        ctx->gpr[3] = ctx->gpr[18] | ctx->gpr[18];
    }

label_800BBCD4:
    ctx->pc = 0x800BBCD4u;
    // 800BBCD4: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBCD8:
    ctx->pc = 0x800BBCD8u;
    // 800BBCD8: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBCDC:
    ctx->pc = 0x800BBCDCu;
    // 800BBCDC: li      r5, 3753
    ctx->gpr[5] = (u32)(s32)(3753);

label_800BBCE0:
    ctx->pc = 0x800BBCE0u;
    // 800BBCE0: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BBCE4:
    ctx->pc = 0x800BBCE4u;
    // 800BBCE4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBCE8:
    ctx->pc = 0x800BBCE8u;
    // 800BBCE8: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBCEC:
    ctx->pc = 0x800BBCECu;
    // 800BBCEC: bl      0x800C3D88
    {
            ctx->lr = 0x800BBCF0u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BBCF0:
    ctx->pc = 0x800BBCF0u;
    ctx->downcount -= 36;
    // 800BBCF0: lis     r19, -32698
    ctx->gpr[19] = ((u32)(s32)(-32698) << 16);

label_800BBCF4:
    ctx->pc = 0x800BBCF4u;
    // 800BBCF4: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BBCF8:
    ctx->pc = 0x800BBCF8u;
    // 800BBCF8: lfs     f0, 20(r28)
    if (!ppc_fp_available(ctx, 0x800BBCF8u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BBCFC:
    ctx->pc = 0x800BBCFCu;
    // 800BBCFC: lfs     f13, -16040(r9)
    if (!ppc_fp_available(ctx, 0x800BBCFCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16040);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BBD00:
    ctx->pc = 0x800BBD00u;
    // 800BBD00: addi    r8, r26, 1432
    ctx->gpr[8] = ctx->gpr[26] + (u32)(s32)(1432);

label_800BBD04:
    ctx->pc = 0x800BBD04u;
    // 800BBD04: lfs     f10, 52(r28)
    if (!ppc_fp_available(ctx, 0x800BBD04u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[10] = value;
        ctx->ps1[10] = value;
    }

label_800BBD08:
    ctx->pc = 0x800BBD08u;
    // 800BBD08: addi    r9, r1, 2272
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(2272);

label_800BBD0C:
    ctx->pc = 0x800BBD0Cu;
    // 800BBD0C: fadds   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BBD0Cu)) return;
    ppc_fadds(ctx, 0, 0, 13);

label_800BBD10:
    ctx->pc = 0x800BBD10u;
    // 800BBD10: lfs     f12, 16(r28)
    if (!ppc_fp_available(ctx, 0x800BBD10u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BBD14:
    ctx->pc = 0x800BBD14u;
    // 800BBD14: lfs     f11, 28(r28)
    if (!ppc_fp_available(ctx, 0x800BBD14u)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800BBD18:
    ctx->pc = 0x800BBD18u;
    // 800BBD18: addi    r0, r1, 2274
    ctx->gpr[0] = ctx->gpr[1] + (u32)(s32)(2274);

label_800BBD1C:
    ctx->pc = 0x800BBD1Cu;
    // 800BBD1C: lfs     f13, 40(r28)
    if (!ppc_fp_available(ctx, 0x800BBD1Cu)) return;
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(40);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BBD20:
    ctx->pc = 0x800BBD20u;
    // 800BBD20: addi    r14, r1, 2264
    ctx->gpr[14] = ctx->gpr[1] + (u32)(s32)(2264);

label_800BBD24:
    ctx->pc = 0x800BBD24u;
    // 800BBD24: stw     r8, 2296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2296);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BBD28:
    ctx->pc = 0x800BBD28u;
    // 800BBD28: addi    r15, r1, 2266
    ctx->gpr[15] = ctx->gpr[1] + (u32)(s32)(2266);

label_800BBD2C:
    ctx->pc = 0x800BBD2Cu;
    // 800BBD2C: stw     r9, 2280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2280);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BBD30:
    ctx->pc = 0x800BBD30u;
    // 800BBD30: addi    r8, r1, 2276
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(2276);

label_800BBD34:
    ctx->pc = 0x800BBD34u;
    // 800BBD34: addi    r9, r1, 2278
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(2278);

label_800BBD38:
    ctx->pc = 0x800BBD38u;
    // 800BBD38: stfs     f0, 28(r1)
    if (!ppc_fp_available(ctx, 0x800BBD38u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBD3C:
    ctx->pc = 0x800BBD3Cu;
    // 800BBD3C: stfs     f12, 24(r1)
    if (!ppc_fp_available(ctx, 0x800BBD3Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800BBD40:
    ctx->pc = 0x800BBD40u;
    // 800BBD40: addi    r16, r1, 2268
    ctx->gpr[16] = ctx->gpr[1] + (u32)(s32)(2268);

label_800BBD44:
    ctx->pc = 0x800BBD44u;
    // 800BBD44: stw     r0, 2284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBD48:
    ctx->pc = 0x800BBD48u;
    // 800BBD48: addi    r17, r1, 2270
    ctx->gpr[17] = ctx->gpr[1] + (u32)(s32)(2270);

label_800BBD4C:
    ctx->pc = 0x800BBD4Cu;
    // 800BBD4C: stfs     f11, 40(r1)
    if (!ppc_fp_available(ctx, 0x800BBD4Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[11]));
    }

label_800BBD50:
    ctx->pc = 0x800BBD50u;
    // 800BBD50: or   r28, r21, r21
    {
        ctx->gpr[28] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BBD54:
    ctx->pc = 0x800BBD54u;
    // 800BBD54: stw     r8, 2288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2288);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BBD58:
    ctx->pc = 0x800BBD58u;
    // 800BBD58: or   r29, r27, r27
    {
        ctx->gpr[29] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBD5C:
    ctx->pc = 0x800BBD5Cu;
    // 800BBD5C: stfs     f13, 56(r1)
    if (!ppc_fp_available(ctx, 0x800BBD5Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BBD60:
    ctx->pc = 0x800BBD60u;
    // 800BBD60: addi    r23, r1, 40
    ctx->gpr[23] = ctx->gpr[1] + (u32)(s32)(40);

label_800BBD64:
    ctx->pc = 0x800BBD64u;
    // 800BBD64: stw     r9, 2292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2292);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BBD68:
    ctx->pc = 0x800BBD68u;
    // 800BBD68: addi    r24, r1, 56
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(56);

label_800BBD6C:
    ctx->pc = 0x800BBD6Cu;
    // 800BBD6C: stfs     f10, 72(r1)
    if (!ppc_fp_available(ctx, 0x800BBD6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[10]));
    }

label_800BBD70:
    ctx->pc = 0x800BBD70u;
    // 800BBD70: addi    r25, r1, 72
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(72);

label_800BBD74:
    ctx->pc = 0x800BBD74u;
    // 800BBD74: stfs     f0, 76(r1)
    if (!ppc_fp_available(ctx, 0x800BBD74u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBD78:
    ctx->pc = 0x800BBD78u;
    // 800BBD78: stfs     f0, 60(r1)
    if (!ppc_fp_available(ctx, 0x800BBD78u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBD7C:
    ctx->pc = 0x800BBD7Cu;
    // 800BBD7C: stfs     f0, 44(r1)
    if (!ppc_fp_available(ctx, 0x800BBD7Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBD80:
    ctx->downcount -= 7;
    // 800BBD80: or   r7, r17, r17
    {
        ctx->gpr[7] = ctx->gpr[17] | ctx->gpr[17];
    }

label_800BBD84:
    // 800BBD84: or   r6, r16, r16
    {
        ctx->gpr[6] = ctx->gpr[16] | ctx->gpr[16];
    }

label_800BBD88:
    // 800BBD88: or   r3, r22, r22
    {
        ctx->gpr[3] = ctx->gpr[22] | ctx->gpr[22];
    }

label_800BBD8C:
    // 800BBD8C: or   r4, r14, r14
    {
        ctx->gpr[4] = ctx->gpr[14] | ctx->gpr[14];
    }

label_800BBD90:
    // 800BBD90: or   r5, r15, r15
    {
        ctx->gpr[5] = ctx->gpr[15] | ctx->gpr[15];
    }

label_800BBD94:
    // 800BBD94: addi    r22, r22, 1
    ctx->gpr[22] = ctx->gpr[22] + (u32)(s32)(1);

label_800BBD98:
    // 800BBD98: bl      0x8012D2E4
    {
            ctx->lr = 0x800BBD9Cu;
            ctx->pc = 0x8012D2E4u;
            return;
    }

label_800BBD9C:
    ctx->pc = 0x800BBD9Cu;
    ctx->downcount -= 8;
    // 800BBD9C: lhz     r0, 2270(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2270);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BBDA0:
    // 800BBDA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBDA4:
    ctx->pc = 0x800BBDA4u;
    // 800BBDA4: lhz     r30, 2268(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2268);
        ctx->gpr[30] = mem_read16(ctx, ea);
    }

label_800BBDA8:
    // 800BBDA8: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BBDAC:
    // 800BBDAC: addi    r3, r31, 7924
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBDB0:
    // 800BBDB0: add   r30, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_800BBDB4:
    // 800BBDB4: rlwinm r30, r30, 0, 16, 31
    {
        ctx->gpr[30] = dolrecomp_rotl32(ctx->gpr[30], 0u) & 0x0000FFFFu;
    }

label_800BBDB8:
    // 800BBDB8: bl      0x801698F0
    {
            ctx->lr = 0x800BBDBCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BBDBC:
    ctx->downcount -= 2;
    // 800BBDBC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBDC0:
    // 800BBDC0: bl      0x80036180
    {
            ctx->lr = 0x800BBDC4u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BBDC4:
    ctx->downcount -= 5;
    // 800BBDC4: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BBDC8:
    // 800BBDC8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBDCC:
    // 800BBDCC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBDD0:
    // 800BBDD0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBDD4:
    // 800BBDD4: bl      0x800361A8
    {
            ctx->lr = 0x800BBDD8u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BBDD8:
    ctx->downcount -= 3;
    // 800BBDD8: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BBDDC:
    // 800BBDDC: addi    r3, r19, 9872
    ctx->gpr[3] = ctx->gpr[19] + (u32)(s32)(9872);

label_800BBDE0:
    // 800BBDE0: bl      0x80046B00
    {
            ctx->lr = 0x800BBDE4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BBDE4:
    ctx->downcount -= 5;
    // 800BBDE4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BBDE8:
    // 800BBDE8: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBDEC:
    // 800BBDEC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBDF0:
    // 800BBDF0: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BBDF4:
    // 800BBDF4: bl      0x8003632C
    {
            ctx->lr = 0x800BBDF8u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BBDF8:
    ctx->pc = 0x800BBDF8u;
    ctx->downcount -= 16;
    // 800BBDF8: lwz     r9, 4(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BBDFC:
    // 800BBDFC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBE00:
    ctx->pc = 0x800BBE00u;
    // 800BBE00: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBE04:
    // 800BBE04: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBE08:
    ctx->pc = 0x800BBE08u;
    // 800BBE08: lwz     r11, 8(r23)
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBE0C:
    // 800BBE0C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBE10:
    ctx->pc = 0x800BBE10u;
    // 800BBE10: stw     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BBE14:
    // 800BBE14: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBE18:
    ctx->pc = 0x800BBE18u;
    // 800BBE18: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBE1C:
    // 800BBE1C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBE20:
    ctx->pc = 0x800BBE20u;
    // 800BBE20: stw     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBE24:
    // 800BBE24: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BBE28:
    // 800BBE28: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BBE2C:
    // 800BBE2C: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBE30:
    // 800BBE30: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBE34:
    // 800BBE34: bl      0x800C3E20
    {
            ctx->lr = 0x800BBE38u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BBE38:
    ctx->downcount -= 4;
    // 800BBE38: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBE3C:
    // 800BBE3C: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BBE40:
    // 800BBE40: addi    r3, r31, 7924
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBE44:
    // 800BBE44: bl      0x801698F0
    {
            ctx->lr = 0x800BBE48u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BBE48:
    ctx->downcount -= 2;
    // 800BBE48: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBE4C:
    // 800BBE4C: bl      0x80036180
    {
            ctx->lr = 0x800BBE50u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BBE50:
    ctx->pc = 0x800BBE50u;
    ctx->downcount -= 5;
    // 800BBE50: lhz     r5, 2270(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2270);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BBE54:
    // 800BBE54: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBE58:
    // 800BBE58: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBE5C:
    // 800BBE5C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBE60:
    // 800BBE60: bl      0x800361A8
    {
            ctx->lr = 0x800BBE64u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BBE64:
    ctx->downcount -= 3;
    // 800BBE64: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BBE68:
    // 800BBE68: addi    r3, r19, 9872
    ctx->gpr[3] = ctx->gpr[19] + (u32)(s32)(9872);

label_800BBE6C:
    // 800BBE6C: bl      0x80046B00
    {
            ctx->lr = 0x800BBE70u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BBE70:
    ctx->downcount -= 5;
    // 800BBE70: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BBE74:
    // 800BBE74: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBE78:
    // 800BBE78: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBE7C:
    // 800BBE7C: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BBE80:
    // 800BBE80: bl      0x8003632C
    {
            ctx->lr = 0x800BBE84u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BBE84:
    ctx->pc = 0x800BBE84u;
    ctx->downcount -= 16;
    // 800BBE84: lwz     r9, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BBE88:
    // 800BBE88: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBE8C:
    ctx->pc = 0x800BBE8Cu;
    // 800BBE8C: lwz     r0, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBE90:
    // 800BBE90: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBE94:
    ctx->pc = 0x800BBE94u;
    // 800BBE94: lwz     r11, 8(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBE98:
    // 800BBE98: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBE9C:
    ctx->pc = 0x800BBE9Cu;
    // 800BBE9C: stw     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BBEA0:
    // 800BBEA0: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBEA4:
    ctx->pc = 0x800BBEA4u;
    // 800BBEA4: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBEA8:
    // 800BBEA8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBEAC:
    ctx->pc = 0x800BBEACu;
    // 800BBEAC: stw     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBEB0:
    // 800BBEB0: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BBEB4:
    // 800BBEB4: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BBEB8:
    // 800BBEB8: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBEBC:
    // 800BBEBC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBEC0:
    // 800BBEC0: bl      0x800C3E20
    {
            ctx->lr = 0x800BBEC4u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BBEC4:
    ctx->downcount -= 4;
    // 800BBEC4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBEC8:
    // 800BBEC8: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BBECC:
    // 800BBECC: addi    r3, r31, 7924
    ctx->gpr[3] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBED0:
    // 800BBED0: bl      0x801698F0
    {
            ctx->lr = 0x800BBED4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BBED4:
    ctx->downcount -= 2;
    // 800BBED4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBED8:
    // 800BBED8: bl      0x80036180
    {
            ctx->lr = 0x800BBEDCu;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BBEDC:
    ctx->pc = 0x800BBEDCu;
    ctx->downcount -= 5;
    // 800BBEDC: lhz     r5, 2268(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2268);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BBEE0:
    // 800BBEE0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBEE4:
    // 800BBEE4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBEE8:
    // 800BBEE8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BBEEC:
    // 800BBEEC: bl      0x800361A8
    {
            ctx->lr = 0x800BBEF0u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BBEF0:
    ctx->downcount -= 3;
    // 800BBEF0: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BBEF4:
    // 800BBEF4: addi    r3, r19, 9872
    ctx->gpr[3] = ctx->gpr[19] + (u32)(s32)(9872);

label_800BBEF8:
    // 800BBEF8: bl      0x80046B00
    {
            ctx->lr = 0x800BBEFCu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BBEFC:
    ctx->downcount -= 5;
    // 800BBEFC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BBF00:
    // 800BBF00: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBF04:
    // 800BBF04: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BBF08:
    // 800BBF08: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BBF0C:
    // 800BBF0C: bl      0x8003632C
    {
            ctx->lr = 0x800BBF10u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BBF10:
    ctx->pc = 0x800BBF10u;
    ctx->downcount -= 16;
    // 800BBF10: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BBF14:
    // 800BBF14: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BBF18:
    ctx->pc = 0x800BBF18u;
    // 800BBF18: lwz     r11, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBF1C:
    // 800BBF1C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBF20:
    ctx->pc = 0x800BBF20u;
    // 800BBF20: lwz     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBF24:
    // 800BBF24: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BBF28:
    ctx->pc = 0x800BBF28u;
    // 800BBF28: stw     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BBF2C:
    // 800BBF2C: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BBF30:
    ctx->pc = 0x800BBF30u;
    // 800BBF30: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBF34:
    // 800BBF34: addi    r5, r31, 7924
    ctx->gpr[5] = ctx->gpr[31] + (u32)(s32)(7924);

label_800BBF38:
    // 800BBF38: ori     r6, r6, 0xC000
    ctx->gpr[6] = ctx->gpr[6] | 0xC000u;

label_800BBF3C:
    ctx->pc = 0x800BBF3Cu;
    // 800BBF3C: stw     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBF40:
    // 800BBF40: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BBF44:
    // 800BBF44: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBF48:
    // 800BBF48: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBF4C:
    // 800BBF4C: bl      0x800C3E20
    {
            ctx->lr = 0x800BBF50u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BBF50:
    ctx->downcount -= 10;
    // 800BBF50: lis     r8, -32737
    ctx->gpr[8] = ((u32)(s32)(-32737) << 16);

label_800BBF54:
    ctx->pc = 0x800BBF54u;
    // 800BBF54: lfs     f0, 76(r1)
    if (!ppc_fp_available(ctx, 0x800BBF54u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BBF58:
    ctx->pc = 0x800BBF58u;
    // 800BBF58: lfs     f29, -16040(r8)
    if (!ppc_fp_available(ctx, 0x800BBF58u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-16040);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_800BBF5C:
    // 800BBF5C: cmpwi   r22, 3
    {
        s32 val_a = (s32)(ctx->gpr[22]);
        s32 val_b = (s32)(3);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BBF60:
    ctx->pc = 0x800BBF60u;
    // 800BBF60: fadds   f0, f0, f29
    if (!ppc_fp_available(ctx, 0x800BBF60u)) return;
    ppc_fadds(ctx, 0, 0, 29);

label_800BBF64:
    ctx->pc = 0x800BBF64u;
    // 800BBF64: stfs     f0, 28(r1)
    if (!ppc_fp_available(ctx, 0x800BBF64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBF68:
    ctx->pc = 0x800BBF68u;
    // 800BBF68: stfs     f0, 76(r1)
    if (!ppc_fp_available(ctx, 0x800BBF68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBF6C:
    ctx->pc = 0x800BBF6Cu;
    // 800BBF6C: stfs     f0, 60(r1)
    if (!ppc_fp_available(ctx, 0x800BBF6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBF70:
    ctx->pc = 0x800BBF70u;
    // 800BBF70: stfs     f0, 44(r1)
    if (!ppc_fp_available(ctx, 0x800BBF70u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBF74:
    // 800BBF74: bc    4, 1, 0x800BBD80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BBD80u;
                return;
            }
            goto label_800BBD80;
        }
    }

label_800BBF78:
    ctx->pc = 0x800BBF78u;
    ctx->downcount -= 27;
    // 800BBF78: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BBF7C:
    ctx->pc = 0x800BBF7Cu;
    // 800BBF7C: lfs     f13, 1444(r26)
    if (!ppc_fp_available(ctx, 0x800BBF7Cu)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(1444);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BBF80:
    ctx->pc = 0x800BBF80u;
    // 800BBF80: lfs     f12, -16048(r9)
    if (!ppc_fp_available(ctx, 0x800BBF80u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16048);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BBF84:
    ctx->pc = 0x800BBF84u;
    // 800BBF84: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BBF88:
    ctx->pc = 0x800BBF88u;
    // 800BBF88: lfs     f11, -16044(r11)
    if (!ppc_fp_available(ctx, 0x800BBF88u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16044);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[11] = value;
        ctx->ps1[11] = value;
    }

label_800BBF8C:
    ctx->pc = 0x800BBF8Cu;
    // 800BBF8C: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BBF90:
    ctx->pc = 0x800BBF90u;
    // 800BBF90: lfs     f0, 1448(r26)
    if (!ppc_fp_available(ctx, 0x800BBF90u)) return;
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(1448);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BBF94:
    ctx->pc = 0x800BBF94u;
    // 800BBF94: fsubs   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x800BBF94u)) return;
    ppc_fsubs(ctx, 13, 13, 12);

label_800BBF98:
    ctx->pc = 0x800BBF98u;
    // 800BBF98: lwz     r30, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800BBF9C:
    ctx->pc = 0x800BBF9Cu;
    // 800BBF9C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BBFA0:
    ctx->pc = 0x800BBFA0u;
    // 800BBFA0: stfs     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BBFA0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BBFA4:
    ctx->pc = 0x800BBFA4u;
    // 800BBFA4: fsubs   f0, f0, f11
    if (!ppc_fp_available(ctx, 0x800BBFA4u)) return;
    ppc_fsubs(ctx, 0, 0, 11);

label_800BBFA8:
    ctx->pc = 0x800BBFA8u;
    // 800BBFA8: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BBFA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BBFAC:
    ctx->pc = 0x800BBFACu;
    // 800BBFAC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BBFB0:
    ctx->pc = 0x800BBFB0u;
    // 800BBFB0: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBFB4:
    ctx->pc = 0x800BBFB4u;
    // 800BBFB4: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BBFB8:
    ctx->pc = 0x800BBFB8u;
    // 800BBFB8: lwz     r11, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BBFBC:
    ctx->pc = 0x800BBFBCu;
    // 800BBFBC: li      r5, 3749
    ctx->gpr[5] = (u32)(s32)(3749);

label_800BBFC0:
    ctx->pc = 0x800BBFC0u;
    // 800BBFC0: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BBFC4:
    ctx->pc = 0x800BBFC4u;
    // 800BBFC4: ori     r6, r6, 0x0041
    ctx->gpr[6] = ctx->gpr[6] | 0x0041u;

label_800BBFC8:
    ctx->pc = 0x800BBFC8u;
    // 800BBFC8: li      r7, 220
    ctx->gpr[7] = (u32)(s32)(220);

label_800BBFCC:
    ctx->pc = 0x800BBFCCu;
    // 800BBFCC: stw     r11, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BBFD0:
    ctx->pc = 0x800BBFD0u;
    // 800BBFD0: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBFD4:
    ctx->pc = 0x800BBFD4u;
    // 800BBFD4: stw     r30, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BBFD8:
    ctx->pc = 0x800BBFD8u;
    // 800BBFD8: or   r3, r18, r18
    {
        ctx->gpr[3] = ctx->gpr[18] | ctx->gpr[18];
    }

label_800BBFDC:
    ctx->pc = 0x800BBFDCu;
    // 800BBFDC: lis     r29, -32698
    ctx->gpr[29] = ((u32)(s32)(-32698) << 16);

label_800BBFE0:
    ctx->pc = 0x800BBFE0u;
    // 800BBFE0: bl      0x800C3D88
    {
            ctx->lr = 0x800BBFE4u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BBFE4:
    ctx->pc = 0x800BBFE4u;
    ctx->downcount -= 28;
    // 800BBFE4: lis     r28, -32698
    ctx->gpr[28] = ((u32)(s32)(-32698) << 16);

label_800BBFE8:
    ctx->pc = 0x800BBFE8u;
    // 800BBFE8: lwz     r8, 2296(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2296);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BBFEC:
    ctx->pc = 0x800BBFECu;
    // 800BBFEC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BBFF0:
    ctx->pc = 0x800BBFF0u;
    // 800BBFF0: lfs     f13, -16036(r9)
    if (!ppc_fp_available(ctx, 0x800BBFF0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16036);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BBFF4:
    ctx->pc = 0x800BBFF4u;
    // 800BBFF4: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BBFF8:
    ctx->pc = 0x800BBFF8u;
    // 800BBFF8: lwz     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BBFFC:
    ctx->pc = 0x800BBFFCu;
    // 800BBFFC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC000:
    ctx->pc = 0x800BC000u;
    // 800BC000: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC004:
    ctx->pc = 0x800BC004u;
    // 800BC004: li      r5, 3756
    ctx->gpr[5] = (u32)(s32)(3756);

label_800BC008:
    ctx->pc = 0x800BC008u;
    // 800BC008: stw     r0, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC00C:
    ctx->pc = 0x800BC00Cu;
    // 800BC00C: li      r6, 16448
    ctx->gpr[6] = (u32)(s32)(16448);

label_800BC010:
    ctx->pc = 0x800BC010u;
    // 800BC010: lwz     r0, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC014:
    ctx->pc = 0x800BC014u;
    // 800BC014: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BC018:
    ctx->pc = 0x800BC018u;
    // 800BC018: lwz     r11, 1432(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(1432);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC01C:
    ctx->pc = 0x800BC01Cu;
    // 800BC01C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC020:
    ctx->pc = 0x800BC020u;
    // 800BC020: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC020u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BC024:
    ctx->pc = 0x800BC024u;
    // 800BC024: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC028:
    ctx->pc = 0x800BC028u;
    // 800BC028: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC02C:
    ctx->pc = 0x800BC02Cu;
    // 800BC02C: stw     r0, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC030:
    ctx->pc = 0x800BC030u;
    // 800BC030: fadds   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BC030u)) return;
    ppc_fadds(ctx, 0, 0, 13);

label_800BC034:
    ctx->pc = 0x800BC034u;
    // 800BC034: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC034u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC038:
    ctx->pc = 0x800BC038u;
    // 800BC038: lwz     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800BC03C:
    ctx->pc = 0x800BC03Cu;
    // 800BC03C: lwz     r11, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC040:
    ctx->pc = 0x800BC040u;
    // 800BC040: lwz     r0, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC044:
    ctx->pc = 0x800BC044u;
    // 800BC044: stw     r30, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BC048:
    ctx->pc = 0x800BC048u;
    // 800BC048: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC04C:
    ctx->pc = 0x800BC04Cu;
    // 800BC04C: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC050:
    ctx->pc = 0x800BC050u;
    // 800BC050: bl      0x800C3D88
    {
            ctx->lr = 0x800BC054u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BC054:
    ctx->pc = 0x800BC054u;
    ctx->downcount -= 13;
    // 800BC054: lis     r30, -32699
    ctx->gpr[30] = ((u32)(s32)(-32699) << 16);

label_800BC058:
    ctx->pc = 0x800BC058u;
    // 800BC058: lwz     r7, 2288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2288);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800BC05C:
    ctx->pc = 0x800BC05Cu;
    // 800BC05C: addi    r30, r30, -21636
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-21636);

label_800BC060:
    ctx->pc = 0x800BC060u;
    // 800BC060: lwz     r8, 2292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2292);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BC064:
    ctx->pc = 0x800BC064u;
    // 800BC064: lwz     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BC068:
    ctx->pc = 0x800BC068u;
    // 800BC068: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BC06C:
    ctx->pc = 0x800BC06Cu;
    // 800BC06C: lwz     r6, 2284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2284);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800BC070:
    ctx->pc = 0x800BC070u;
    // 800BC070: rlwinm r0, r3, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0x00000001u;
    }

label_800BC074:
    ctx->pc = 0x800BC074u;
    // 800BC074: lwz     r5, 2280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2280);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BC078:
    ctx->pc = 0x800BC078u;
    // 800BC078: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800BC07C:
    ctx->pc = 0x800BC07Cu;
    // 800BC07C: srawi r3, r3, 1
    {
        u32 sh = 1u;
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

label_800BC080:
    ctx->pc = 0x800BC080u;
    // 800BC080: addi    r3, r3, -3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-3);

label_800BC084:
    ctx->pc = 0x800BC084u;
    // 800BC084: bl      0x8012D3A0
    {
            ctx->lr = 0x800BC088u;
            ctx->pc = 0x8012D3A0u;
            return;
    }

label_800BC088:
    ctx->pc = 0x800BC088u;
    ctx->downcount -= 12;
    // 800BC088: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BC08C:
    ctx->pc = 0x800BC08Cu;
    // 800BC08C: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC08Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BC090:
    ctx->pc = 0x800BC090u;
    // 800BC090: lfs     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC090u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BC094:
    ctx->pc = 0x800BC094u;
    // 800BC094: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC098:
    ctx->pc = 0x800BC098u;
    // 800BC098: lfs     f30, -16032(r9)
    if (!ppc_fp_available(ctx, 0x800BC098u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16032);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800BC09C:
    ctx->pc = 0x800BC09Cu;
    // 800BC09C: fadds   f0, f0, f29
    if (!ppc_fp_available(ctx, 0x800BC09Cu)) return;
    ppc_fadds(ctx, 0, 0, 29);

label_800BC0A0:
    ctx->pc = 0x800BC0A0u;
    // 800BC0A0: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC0A0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC0A4:
    ctx->pc = 0x800BC0A4u;
    // 800BC0A4: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BC0A8:
    ctx->pc = 0x800BC0A8u;
    // 800BC0A8: fadds   f13, f13, f30
    if (!ppc_fp_available(ctx, 0x800BC0A8u)) return;
    ppc_fadds(ctx, 13, 13, 30);

label_800BC0AC:
    ctx->pc = 0x800BC0ACu;
    // 800BC0AC: addi    r3, r29, 7924
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC0B0:
    ctx->pc = 0x800BC0B0u;
    // 800BC0B0: stfs     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC0B0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BC0B4:
    ctx->pc = 0x800BC0B4u;
    // 800BC0B4: bl      0x801698F0
    {
            ctx->lr = 0x800BC0B8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BC0B8:
    ctx->pc = 0x800BC0B8u;
    ctx->downcount -= 2;
    // 800BC0B8: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC0BC:
    ctx->pc = 0x800BC0BCu;
    // 800BC0BC: bl      0x80036180
    {
            ctx->lr = 0x800BC0C0u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BC0C0:
    ctx->pc = 0x800BC0C0u;
    ctx->downcount -= 5;
    // 800BC0C0: lhz     r5, 2274(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2274);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BC0C4:
    ctx->pc = 0x800BC0C4u;
    // 800BC0C4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC0C8:
    ctx->pc = 0x800BC0C8u;
    // 800BC0C8: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC0CC:
    ctx->pc = 0x800BC0CCu;
    // 800BC0CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC0D0:
    ctx->pc = 0x800BC0D0u;
    // 800BC0D0: bl      0x800361A8
    {
            ctx->lr = 0x800BC0D4u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BC0D4:
    ctx->pc = 0x800BC0D4u;
    ctx->downcount -= 3;
    // 800BC0D4: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BC0D8:
    ctx->pc = 0x800BC0D8u;
    // 800BC0D8: addi    r3, r28, 9872
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(9872);

label_800BC0DC:
    ctx->pc = 0x800BC0DCu;
    // 800BC0DC: bl      0x80046B00
    {
            ctx->lr = 0x800BC0E0u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BC0E0:
    ctx->pc = 0x800BC0E0u;
    ctx->downcount -= 5;
    // 800BC0E0: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BC0E4:
    ctx->pc = 0x800BC0E4u;
    // 800BC0E4: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC0E8:
    ctx->pc = 0x800BC0E8u;
    // 800BC0E8: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC0EC:
    ctx->pc = 0x800BC0ECu;
    // 800BC0EC: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BC0F0:
    ctx->pc = 0x800BC0F0u;
    // 800BC0F0: bl      0x8003632C
    {
            ctx->lr = 0x800BC0F4u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BC0F4:
    ctx->pc = 0x800BC0F4u;
    ctx->downcount -= 16;
    // 800BC0F4: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC0F8:
    ctx->pc = 0x800BC0F8u;
    // 800BC0F8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC0FC:
    ctx->pc = 0x800BC0FCu;
    // 800BC0FC: lwz     r11, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC100:
    ctx->pc = 0x800BC100u;
    // 800BC100: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC104:
    ctx->pc = 0x800BC104u;
    // 800BC104: lwz     r5, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BC108:
    ctx->pc = 0x800BC108u;
    // 800BC108: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BC10C:
    ctx->pc = 0x800BC10Cu;
    // 800BC10C: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC110:
    ctx->pc = 0x800BC110u;
    // 800BC110: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC114:
    ctx->pc = 0x800BC114u;
    // 800BC114: stw     r5, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_800BC118:
    ctx->pc = 0x800BC118u;
    // 800BC118: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BC11C:
    ctx->pc = 0x800BC11Cu;
    // 800BC11C: stw     r11, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC120:
    ctx->pc = 0x800BC120u;
    // 800BC120: ori     r6, r6, 0xC040
    ctx->gpr[6] = ctx->gpr[6] | 0xC040u;

label_800BC124:
    ctx->pc = 0x800BC124u;
    // 800BC124: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC128:
    ctx->pc = 0x800BC128u;
    // 800BC128: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC12C:
    ctx->pc = 0x800BC12Cu;
    // 800BC12C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC130:
    ctx->pc = 0x800BC130u;
    // 800BC130: bl      0x800C3E20
    {
            ctx->lr = 0x800BC134u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BC134:
    ctx->pc = 0x800BC134u;
    ctx->downcount -= 9;
    // 800BC134: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BC138:
    ctx->pc = 0x800BC138u;
    // 800BC138: lfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC138u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BC13C:
    ctx->pc = 0x800BC13Cu;
    // 800BC13C: lfs     f31, -16028(r9)
    if (!ppc_fp_available(ctx, 0x800BC13Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16028);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800BC140:
    ctx->pc = 0x800BC140u;
    // 800BC140: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC144:
    ctx->pc = 0x800BC144u;
    // 800BC144: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BC148:
    ctx->pc = 0x800BC148u;
    // 800BC148: addi    r3, r29, 7924
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC14C:
    ctx->pc = 0x800BC14Cu;
    // 800BC14C: fadds   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BC14Cu)) return;
    ppc_fadds(ctx, 0, 0, 31);

label_800BC150:
    ctx->pc = 0x800BC150u;
    // 800BC150: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC150u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC154:
    ctx->pc = 0x800BC154u;
    // 800BC154: bl      0x801698F0
    {
            ctx->lr = 0x800BC158u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BC158:
    ctx->pc = 0x800BC158u;
    ctx->downcount -= 2;
    // 800BC158: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC15C:
    ctx->pc = 0x800BC15Cu;
    // 800BC15C: bl      0x80036180
    {
            ctx->lr = 0x800BC160u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BC160:
    ctx->pc = 0x800BC160u;
    ctx->downcount -= 5;
    // 800BC160: lhz     r5, 2278(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2278);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BC164:
    ctx->pc = 0x800BC164u;
    // 800BC164: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC168:
    ctx->pc = 0x800BC168u;
    // 800BC168: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC16C:
    ctx->pc = 0x800BC16Cu;
    // 800BC16C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC170:
    ctx->pc = 0x800BC170u;
    // 800BC170: bl      0x800361A8
    {
            ctx->lr = 0x800BC174u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BC174:
    ctx->pc = 0x800BC174u;
    ctx->downcount -= 3;
    // 800BC174: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BC178:
    ctx->pc = 0x800BC178u;
    // 800BC178: addi    r3, r28, 9872
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(9872);

label_800BC17C:
    ctx->pc = 0x800BC17Cu;
    // 800BC17C: bl      0x80046B00
    {
            ctx->lr = 0x800BC180u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BC180:
    ctx->pc = 0x800BC180u;
    ctx->downcount -= 5;
    // 800BC180: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BC184:
    ctx->pc = 0x800BC184u;
    // 800BC184: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC188:
    ctx->pc = 0x800BC188u;
    // 800BC188: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC18C:
    ctx->pc = 0x800BC18Cu;
    // 800BC18C: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BC190:
    ctx->pc = 0x800BC190u;
    // 800BC190: bl      0x8003632C
    {
            ctx->lr = 0x800BC194u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BC194:
    ctx->pc = 0x800BC194u;
    ctx->downcount -= 16;
    // 800BC194: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC198:
    ctx->pc = 0x800BC198u;
    // 800BC198: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC19C:
    ctx->pc = 0x800BC19Cu;
    // 800BC19C: lwz     r9, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC1A0:
    ctx->pc = 0x800BC1A0u;
    // 800BC1A0: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC1A4:
    ctx->pc = 0x800BC1A4u;
    // 800BC1A4: lwz     r11, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC1A8:
    ctx->pc = 0x800BC1A8u;
    // 800BC1A8: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC1AC:
    ctx->pc = 0x800BC1ACu;
    // 800BC1AC: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC1B0:
    ctx->pc = 0x800BC1B0u;
    // 800BC1B0: ori     r6, r6, 0xC040
    ctx->gpr[6] = ctx->gpr[6] | 0xC040u;

label_800BC1B4:
    ctx->pc = 0x800BC1B4u;
    // 800BC1B4: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC1B8:
    ctx->pc = 0x800BC1B8u;
    // 800BC1B8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BC1BC:
    ctx->pc = 0x800BC1BCu;
    // 800BC1BC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC1C0:
    ctx->pc = 0x800BC1C0u;
    // 800BC1C0: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC1C4:
    ctx->pc = 0x800BC1C4u;
    // 800BC1C4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC1C8:
    ctx->pc = 0x800BC1C8u;
    // 800BC1C8: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BC1CC:
    ctx->pc = 0x800BC1CCu;
    // 800BC1CC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC1D0:
    ctx->pc = 0x800BC1D0u;
    // 800BC1D0: bl      0x800C3E20
    {
            ctx->lr = 0x800BC1D4u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BC1D4:
    ctx->pc = 0x800BC1D4u;
    ctx->downcount -= 23;
    // 800BC1D4: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC1D4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BC1D8:
    ctx->pc = 0x800BC1D8u;
    // 800BC1D8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BC1DC:
    ctx->pc = 0x800BC1DCu;
    // 800BC1DC: lfs     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC1DCu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BC1E0:
    ctx->pc = 0x800BC1E0u;
    // 800BC1E0: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BC1E4:
    ctx->pc = 0x800BC1E4u;
    // 800BC1E4: fadds   f0, f0, f29
    if (!ppc_fp_available(ctx, 0x800BC1E4u)) return;
    ppc_fadds(ctx, 0, 0, 29);

label_800BC1E8:
    ctx->pc = 0x800BC1E8u;
    // 800BC1E8: lfs     f12, -16024(r9)
    if (!ppc_fp_available(ctx, 0x800BC1E8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-16024);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BC1EC:
    ctx->pc = 0x800BC1ECu;
    // 800BC1EC: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC1ECu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC1F0:
    ctx->pc = 0x800BC1F0u;
    // 800BC1F0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC1F4:
    ctx->pc = 0x800BC1F4u;
    // 800BC1F4: fsubs   f13, f13, f12
    if (!ppc_fp_available(ctx, 0x800BC1F4u)) return;
    ppc_fsubs(ctx, 13, 13, 12);

label_800BC1F8:
    ctx->pc = 0x800BC1F8u;
    // 800BC1F8: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC1FC:
    ctx->pc = 0x800BC1FCu;
    // 800BC1FC: lwz     r3, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BC200:
    ctx->pc = 0x800BC200u;
    // 800BC200: li      r5, 3757
    ctx->gpr[5] = (u32)(s32)(3757);

label_800BC204:
    ctx->pc = 0x800BC204u;
    // 800BC204: stfs     f13, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC204u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BC208:
    ctx->pc = 0x800BC208u;
    // 800BC208: li      r6, 16448
    ctx->gpr[6] = (u32)(s32)(16448);

label_800BC20C:
    ctx->pc = 0x800BC20Cu;
    // 800BC20C: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BC210:
    ctx->pc = 0x800BC210u;
    // 800BC210: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC214:
    ctx->pc = 0x800BC214u;
    // 800BC214: lwz     r0, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC218:
    ctx->pc = 0x800BC218u;
    // 800BC218: lwz     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC21C:
    ctx->pc = 0x800BC21Cu;
    // 800BC21C: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC220:
    ctx->pc = 0x800BC220u;
    // 800BC220: stw     r11, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC224:
    ctx->pc = 0x800BC224u;
    // 800BC224: stw     r3, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BC228:
    ctx->pc = 0x800BC228u;
    // 800BC228: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC22C:
    ctx->pc = 0x800BC22Cu;
    // 800BC22C: bl      0x800C3D88
    {
            ctx->lr = 0x800BC230u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BC230:
    ctx->pc = 0x800BC230u;
    ctx->downcount -= 11;
    // 800BC230: lwz     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BC234:
    ctx->pc = 0x800BC234u;
    // 800BC234: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC238:
    ctx->pc = 0x800BC238u;
    // 800BC238: lwz     r7, 2288(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2288);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800BC23C:
    ctx->pc = 0x800BC23Cu;
    // 800BC23C: rlwinm r0, r3, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[3], 1u) & 0x00000001u;
    }

label_800BC240:
    ctx->pc = 0x800BC240u;
    // 800BC240: lwz     r8, 2292(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2292);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BC244:
    ctx->pc = 0x800BC244u;
    // 800BC244: add   r3, r3, r0
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[3] = res;
    }

label_800BC248:
    ctx->pc = 0x800BC248u;
    // 800BC248: lwz     r6, 2284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2284);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800BC24C:
    ctx->pc = 0x800BC24Cu;
    // 800BC24C: lwz     r5, 2280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2280);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BC250:
    ctx->pc = 0x800BC250u;
    // 800BC250: srawi r3, r3, 1
    {
        u32 sh = 1u;
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

label_800BC254:
    ctx->pc = 0x800BC254u;
    // 800BC254: addi    r3, r3, -3
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(-3);

label_800BC258:
    ctx->pc = 0x800BC258u;
    // 800BC258: bl      0x8012D3A0
    {
            ctx->lr = 0x800BC25Cu;
            ctx->pc = 0x8012D3A0u;
            return;
    }

label_800BC25C:
    ctx->pc = 0x800BC25Cu;
    ctx->downcount -= 10;
    // 800BC25C: lfs     f13, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC25Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BC260:
    ctx->pc = 0x800BC260u;
    // 800BC260: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC264:
    ctx->pc = 0x800BC264u;
    // 800BC264: lfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC264u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BC268:
    ctx->pc = 0x800BC268u;
    // 800BC268: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BC26C:
    ctx->pc = 0x800BC26Cu;
    // 800BC26C: fadds   f13, f13, f29
    if (!ppc_fp_available(ctx, 0x800BC26Cu)) return;
    ppc_fadds(ctx, 13, 13, 29);

label_800BC270:
    ctx->pc = 0x800BC270u;
    // 800BC270: addi    r3, r29, 7924
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC274:
    ctx->pc = 0x800BC274u;
    // 800BC274: fadds   f0, f0, f30
    if (!ppc_fp_available(ctx, 0x800BC274u)) return;
    ppc_fadds(ctx, 0, 0, 30);

label_800BC278:
    ctx->pc = 0x800BC278u;
    // 800BC278: stfs     f13, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC278u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BC27C:
    ctx->pc = 0x800BC27Cu;
    // 800BC27C: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC27Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC280:
    ctx->pc = 0x800BC280u;
    // 800BC280: bl      0x801698F0
    {
            ctx->lr = 0x800BC284u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BC284:
    ctx->pc = 0x800BC284u;
    ctx->downcount -= 2;
    // 800BC284: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC288:
    ctx->pc = 0x800BC288u;
    // 800BC288: bl      0x80036180
    {
            ctx->lr = 0x800BC28Cu;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BC28C:
    ctx->pc = 0x800BC28Cu;
    ctx->downcount -= 5;
    // 800BC28C: lhz     r5, 2274(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2274);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BC290:
    ctx->pc = 0x800BC290u;
    // 800BC290: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC294:
    ctx->pc = 0x800BC294u;
    // 800BC294: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC298:
    ctx->pc = 0x800BC298u;
    // 800BC298: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC29C:
    ctx->pc = 0x800BC29Cu;
    // 800BC29C: bl      0x800361A8
    {
            ctx->lr = 0x800BC2A0u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BC2A0:
    ctx->pc = 0x800BC2A0u;
    ctx->downcount -= 3;
    // 800BC2A0: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BC2A4:
    ctx->pc = 0x800BC2A4u;
    // 800BC2A4: addi    r3, r28, 9872
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(9872);

label_800BC2A8:
    ctx->pc = 0x800BC2A8u;
    // 800BC2A8: bl      0x80046B00
    {
            ctx->lr = 0x800BC2ACu;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BC2AC:
    ctx->pc = 0x800BC2ACu;
    ctx->downcount -= 5;
    // 800BC2AC: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BC2B0:
    ctx->pc = 0x800BC2B0u;
    // 800BC2B0: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC2B4:
    ctx->pc = 0x800BC2B4u;
    // 800BC2B4: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC2B8:
    ctx->pc = 0x800BC2B8u;
    // 800BC2B8: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BC2BC:
    ctx->pc = 0x800BC2BCu;
    // 800BC2BC: bl      0x8003632C
    {
            ctx->lr = 0x800BC2C0u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BC2C0:
    ctx->pc = 0x800BC2C0u;
    ctx->downcount -= 16;
    // 800BC2C0: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC2C4:
    ctx->pc = 0x800BC2C4u;
    // 800BC2C4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC2C8:
    ctx->pc = 0x800BC2C8u;
    // 800BC2C8: lwz     r11, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC2CC:
    ctx->pc = 0x800BC2CCu;
    // 800BC2CC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC2D0:
    ctx->pc = 0x800BC2D0u;
    // 800BC2D0: lwz     r5, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BC2D4:
    ctx->pc = 0x800BC2D4u;
    // 800BC2D4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BC2D8:
    ctx->pc = 0x800BC2D8u;
    // 800BC2D8: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC2DC:
    ctx->pc = 0x800BC2DCu;
    // 800BC2DC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC2E0:
    ctx->pc = 0x800BC2E0u;
    // 800BC2E0: stw     r5, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_800BC2E4:
    ctx->pc = 0x800BC2E4u;
    // 800BC2E4: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BC2E8:
    ctx->pc = 0x800BC2E8u;
    // 800BC2E8: stw     r11, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC2EC:
    ctx->pc = 0x800BC2ECu;
    // 800BC2EC: ori     r6, r6, 0xC040
    ctx->gpr[6] = ctx->gpr[6] | 0xC040u;

label_800BC2F0:
    ctx->pc = 0x800BC2F0u;
    // 800BC2F0: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC2F4:
    ctx->pc = 0x800BC2F4u;
    // 800BC2F4: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC2F8:
    ctx->pc = 0x800BC2F8u;
    // 800BC2F8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC2FC:
    ctx->pc = 0x800BC2FCu;
    // 800BC2FC: bl      0x800C3E20
    {
            ctx->lr = 0x800BC300u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BC300:
    ctx->pc = 0x800BC300u;
    ctx->downcount -= 7;
    // 800BC300: lfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC300u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BC304:
    ctx->pc = 0x800BC304u;
    // 800BC304: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC308:
    ctx->pc = 0x800BC308u;
    // 800BC308: li      r5, 60
    ctx->gpr[5] = (u32)(s32)(60);

label_800BC30C:
    ctx->pc = 0x800BC30Cu;
    // 800BC30C: addi    r3, r29, 7924
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC310:
    ctx->pc = 0x800BC310u;
    // 800BC310: fadds   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BC310u)) return;
    ppc_fadds(ctx, 0, 0, 31);

label_800BC314:
    ctx->pc = 0x800BC314u;
    // 800BC314: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BC314u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC318:
    ctx->pc = 0x800BC318u;
    // 800BC318: bl      0x801698F0
    {
            ctx->lr = 0x800BC31Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BC31C:
    ctx->pc = 0x800BC31Cu;
    ctx->downcount -= 2;
    // 800BC31C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC320:
    ctx->pc = 0x800BC320u;
    // 800BC320: bl      0x80036180
    {
            ctx->lr = 0x800BC324u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BC324:
    ctx->pc = 0x800BC324u;
    ctx->downcount -= 5;
    // 800BC324: lhz     r5, 2278(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2278);
        ctx->gpr[5] = mem_read16(ctx, ea);
    }

label_800BC328:
    ctx->pc = 0x800BC328u;
    // 800BC328: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC32C:
    ctx->pc = 0x800BC32Cu;
    // 800BC32C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC330:
    ctx->pc = 0x800BC330u;
    // 800BC330: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC334:
    ctx->pc = 0x800BC334u;
    // 800BC334: bl      0x800361A8
    {
            ctx->lr = 0x800BC338u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BC338:
    ctx->pc = 0x800BC338u;
    ctx->downcount -= 3;
    // 800BC338: li      r4, 3755
    ctx->gpr[4] = (u32)(s32)(3755);

label_800BC33C:
    ctx->pc = 0x800BC33Cu;
    // 800BC33C: addi    r3, r28, 9872
    ctx->gpr[3] = ctx->gpr[28] + (u32)(s32)(9872);

label_800BC340:
    ctx->pc = 0x800BC340u;
    // 800BC340: bl      0x80046B00
    {
            ctx->lr = 0x800BC344u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BC344:
    ctx->pc = 0x800BC344u;
    ctx->downcount -= 5;
    // 800BC344: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BC348:
    ctx->pc = 0x800BC348u;
    // 800BC348: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC34C:
    ctx->pc = 0x800BC34Cu;
    // 800BC34C: or   r3, r21, r21
    {
        ctx->gpr[3] = ctx->gpr[21] | ctx->gpr[21];
    }

label_800BC350:
    ctx->pc = 0x800BC350u;
    // 800BC350: li      r6, 30
    ctx->gpr[6] = (u32)(s32)(30);

label_800BC354:
    ctx->pc = 0x800BC354u;
    // 800BC354: bl      0x8003632C
    {
            ctx->lr = 0x800BC358u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BC358:
    ctx->pc = 0x800BC358u;
    ctx->downcount -= 16;
    // 800BC358: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC35C:
    ctx->pc = 0x800BC35Cu;
    // 800BC35C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC360:
    ctx->pc = 0x800BC360u;
    // 800BC360: lwz     r9, 4(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC364:
    ctx->pc = 0x800BC364u;
    // 800BC364: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC368:
    ctx->pc = 0x800BC368u;
    // 800BC368: lwz     r11, 8(r20)
    {
        u32 ea = ctx->gpr[20] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC36C:
    ctx->pc = 0x800BC36Cu;
    // 800BC36C: addi    r5, r29, 7924
    ctx->gpr[5] = ctx->gpr[29] + (u32)(s32)(7924);

label_800BC370:
    ctx->pc = 0x800BC370u;
    // 800BC370: stw     r0, 2248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2248);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC374:
    ctx->pc = 0x800BC374u;
    // 800BC374: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC378:
    ctx->pc = 0x800BC378u;
    // 800BC378: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC37C:
    ctx->pc = 0x800BC37Cu;
    // 800BC37C: ori     r6, r6, 0xC040
    ctx->gpr[6] = ctx->gpr[6] | 0xC040u;

label_800BC380:
    ctx->pc = 0x800BC380u;
    // 800BC380: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC384:
    ctx->pc = 0x800BC384u;
    // 800BC384: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BC388:
    ctx->pc = 0x800BC388u;
    // 800BC388: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC38C:
    ctx->pc = 0x800BC38Cu;
    // 800BC38C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC390:
    ctx->pc = 0x800BC390u;
    // 800BC390: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BC394:
    ctx->pc = 0x800BC394u;
    // 800BC394: bl      0x800C3E20
    {
            ctx->lr = 0x800BC398u;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BC398:
    ctx->pc = 0x800BC398u;
    ctx->downcount -= 19;
    // 800BC398: lwz     r0, 2404(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2404);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC39C:
    ctx->pc = 0x800BC39Cu;
    // 800BC39C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BC3A0:
    ctx->pc = 0x800BC3A0u;
    // 800BC3A0: lmw     r14, 2304(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2304);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BC3A4:
    ctx->pc = 0x800BC3A4u;
    // 800BC3A4: lfd     f29, 2376(r1)
    if (!ppc_fp_available(ctx, 0x800BC3A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2376);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BC3A8:
    ctx->pc = 0x800BC3A8u;
    // 800BC3A8: lfd     f30, 2384(r1)
    if (!ppc_fp_available(ctx, 0x800BC3A8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2384);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BC3AC:
    ctx->pc = 0x800BC3ACu;
    // 800BC3AC: lfd     f31, 2392(r1)
    if (!ppc_fp_available(ctx, 0x800BC3ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2392);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BC3B0:
    ctx->pc = 0x800BC3B0u;
    // 800BC3B0: addi    r1, r1, 2400
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(2400);

label_800BC3B4:
    ctx->pc = 0x800BC3B4u;
    // 800BC3B4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BC3B8:
    ctx->pc = 0x800BC3B8u;
    ctx->downcount -= 16;
    // 800BC3B8: stwu     r1, -112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-112);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BC3BC:
    ctx->pc = 0x800BC3BCu;
    // 800BC3BC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BC3C0:
    ctx->pc = 0x800BC3C0u;
    // 800BC3C0: stmw     r27, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BC3C4:
    ctx->pc = 0x800BC3C4u;
    // 800BC3C4: stw     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC3C8:
    ctx->pc = 0x800BC3C8u;
    // 800BC3C8: or.   r29, r3, r3
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

label_800BC3CC:
    ctx->pc = 0x800BC3CCu;
    // 800BC3CC: bc    12, 2, 0x800BC528
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC528;
        }
    }

label_800BC3D0:
    ctx->pc = 0x800BC3D0u;
    ctx->downcount -= 5;
    // 800BC3D0: lwz     r3, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BC3D4:
    ctx->pc = 0x800BC3D4u;
    // 800BC3D4: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_800BC3D8:
    ctx->pc = 0x800BC3D8u;
    // 800BC3D8: stw     r0, 72(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC3DC:
    ctx->pc = 0x800BC3DCu;
    // 800BC3DC: cmpwi   r3, 0
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

label_800BC3E0:
    ctx->pc = 0x800BC3E0u;
    // 800BC3E0: bc    12, 2, 0x800BC528
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC528;
        }
    }

label_800BC3E4:
    ctx->pc = 0x800BC3E4u;
    ctx->downcount -= 3;
    // 800BC3E4: lis     r4, 20992
    ctx->gpr[4] = ((u32)(s32)(20992) << 16);

label_800BC3E8:
    ctx->pc = 0x800BC3E8u;
    // 800BC3E8: ori     r4, r4, 0x0129
    ctx->gpr[4] = ctx->gpr[4] | 0x0129u;

label_800BC3EC:
    ctx->pc = 0x800BC3ECu;
    // 800BC3EC: bl      0x80047634
    {
            ctx->lr = 0x800BC3F0u;
            ctx->pc = 0x80047634u;
            return;
    }

label_800BC3F0:
    ctx->pc = 0x800BC3F0u;
    ctx->downcount -= 2;
    // 800BC3F0: or.   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[27];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BC3F4:
    ctx->pc = 0x800BC3F4u;
    // 800BC3F4: bc    12, 2, 0x800BC528
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC528;
        }
    }

label_800BC3F8:
    ctx->pc = 0x800BC3F8u;
    ctx->downcount -= 7;
    // 800BC3F8: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BC3FC:
    ctx->pc = 0x800BC3FCu;
    // 800BC3FC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC400:
    ctx->pc = 0x800BC400u;
    // 800BC400: ori     r4, r4, 0x00B6
    ctx->gpr[4] = ctx->gpr[4] | 0x00B6u;

label_800BC404:
    ctx->pc = 0x800BC404u;
    // 800BC404: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC408:
    ctx->pc = 0x800BC408u;
    // 800BC408: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC40C:
    ctx->pc = 0x800BC40Cu;
    // 800BC40C: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BC410:
    ctx->pc = 0x800BC410u;
    // 800BC410: bl      0x800303A8
    {
            ctx->lr = 0x800BC414u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BC414:
    ctx->pc = 0x800BC414u;
    ctx->downcount -= 3;
    // 800BC414: addi    r28, r1, 8
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC418:
    ctx->pc = 0x800BC418u;
    // 800BC418: cmpwi   r3, 0
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

label_800BC41C:
    ctx->pc = 0x800BC41Cu;
    // 800BC41C: bc    12, 2, 0x800BC464
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC464;
        }
    }

label_800BC420:
    ctx->pc = 0x800BC420u;
    ctx->downcount -= 6;
    // 800BC420: addi    r30, r1, 40
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(40);

label_800BC424:
    ctx->pc = 0x800BC424u;
    // 800BC424: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BC428:
    ctx->pc = 0x800BC428u;
    // 800BC428: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC42C:
    ctx->pc = 0x800BC42Cu;
    // 800BC42C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC430:
    ctx->pc = 0x800BC430u;
    // 800BC430: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC434:
    ctx->pc = 0x800BC434u;
    // 800BC434: bl      0x800C48AC
    {
            ctx->lr = 0x800BC438u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BC438:
    ctx->pc = 0x800BC438u;
    ctx->downcount -= 11;
    // 800BC438: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC43C:
    ctx->pc = 0x800BC43Cu;
    // 800BC43C: addi    r10, r29, 1432
    ctx->gpr[10] = ctx->gpr[29] + (u32)(s32)(1432);

label_800BC440:
    ctx->pc = 0x800BC440u;
    // 800BC440: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC444:
    ctx->pc = 0x800BC444u;
    // 800BC444: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC448:
    ctx->pc = 0x800BC448u;
    // 800BC448: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC44C:
    ctx->pc = 0x800BC44Cu;
    // 800BC44C: stw     r11, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC450:
    ctx->pc = 0x800BC450u;
    // 800BC450: stw     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC454:
    ctx->pc = 0x800BC454u;
    // 800BC454: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC458:
    ctx->pc = 0x800BC458u;
    // 800BC458: stw     r0, 1432(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1432);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC45C:
    ctx->pc = 0x800BC45Cu;
    // 800BC45C: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC460:
    ctx->pc = 0x800BC460u;
    // 800BC460: stw     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC464:
    ctx->pc = 0x800BC464u;
    ctx->downcount -= 8;
    // 800BC464: addi    r31, r1, 24
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(24);

label_800BC468:
    ctx->pc = 0x800BC468u;
    // 800BC468: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BC46C:
    ctx->pc = 0x800BC46Cu;
    // 800BC46C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC470:
    ctx->pc = 0x800BC470u;
    // 800BC470: ori     r4, r4, 0x00BA
    ctx->gpr[4] = ctx->gpr[4] | 0x00BAu;

label_800BC474:
    ctx->pc = 0x800BC474u;
    // 800BC474: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC478:
    ctx->pc = 0x800BC478u;
    // 800BC478: or   r6, r31, r31
    {
        ctx->gpr[6] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BC47C:
    ctx->pc = 0x800BC47Cu;
    // 800BC47C: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BC480:
    ctx->pc = 0x800BC480u;
    // 800BC480: bl      0x800303A8
    {
            ctx->lr = 0x800BC484u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BC484:
    ctx->pc = 0x800BC484u;
    ctx->downcount -= 2;
    // 800BC484: cmpwi   r3, 0
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

label_800BC488:
    ctx->pc = 0x800BC488u;
    // 800BC488: bc    12, 2, 0x800BC4BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC4BC;
        }
    }

label_800BC48C:
    ctx->pc = 0x800BC48Cu;
    ctx->downcount -= 6;
    // 800BC48C: addi    r30, r1, 40
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(40);

label_800BC490:
    ctx->pc = 0x800BC490u;
    // 800BC490: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BC494:
    ctx->pc = 0x800BC494u;
    // 800BC494: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC498:
    ctx->pc = 0x800BC498u;
    // 800BC498: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC49C:
    ctx->pc = 0x800BC49Cu;
    // 800BC49C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC4A0:
    ctx->pc = 0x800BC4A0u;
    // 800BC4A0: bl      0x800C48AC
    {
            ctx->lr = 0x800BC4A4u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BC4A4:
    ctx->pc = 0x800BC4A4u;
    ctx->downcount -= 6;
    // 800BC4A4: lwz     r9, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC4A8:
    ctx->pc = 0x800BC4A8u;
    // 800BC4A8: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC4AC:
    ctx->pc = 0x800BC4ACu;
    // 800BC4AC: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC4B0:
    ctx->pc = 0x800BC4B0u;
    // 800BC4B0: stw     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC4B4:
    ctx->pc = 0x800BC4B4u;
    // 800BC4B4: stw     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC4B8:
    ctx->pc = 0x800BC4B8u;
    // 800BC4B8: stw     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC4BC:
    ctx->pc = 0x800BC4BCu;
    ctx->downcount -= 3;
    // 800BC4BC: addi    r30, r29, 3720
    ctx->gpr[30] = ctx->gpr[29] + (u32)(s32)(3720);

label_800BC4C0:
    ctx->pc = 0x800BC4C0u;
    // 800BC4C0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC4C4:
    ctx->pc = 0x800BC4C4u;
    // 800BC4C4: bl      0x800C13B0
    {
            ctx->lr = 0x800BC4C8u;
            ctx->pc = 0x800C13B0u;
            return;
    }

label_800BC4C8:
    ctx->pc = 0x800BC4C8u;
    ctx->downcount -= 20;
    // 800BC4C8: lwz     r10, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BC4CC:
    ctx->pc = 0x800BC4CCu;
    // 800BC4CC: addi    r9, r1, 56
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(56);

label_800BC4D0:
    ctx->pc = 0x800BC4D0u;
    // 800BC4D0: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC4D4:
    ctx->pc = 0x800BC4D4u;
    // 800BC4D4: or   r5, r9, r9
    {
        ctx->gpr[5] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BC4D8:
    ctx->pc = 0x800BC4D8u;
    // 800BC4D8: lwz     r8, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BC4DC:
    ctx->pc = 0x800BC4DCu;
    // 800BC4DC: addi    r11, r1, 72
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(72);

label_800BC4E0:
    ctx->pc = 0x800BC4E0u;
    // 800BC4E0: stw     r10, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BC4E4:
    ctx->pc = 0x800BC4E4u;
    // 800BC4E4: lis     r4, -32734
    ctx->gpr[4] = ((u32)(s32)(-32734) << 16);

label_800BC4E8:
    ctx->pc = 0x800BC4E8u;
    // 800BC4E8: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC4EC:
    ctx->pc = 0x800BC4ECu;
    // 800BC4EC: addi    r4, r4, -6840
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-6840);

label_800BC4F0:
    ctx->pc = 0x800BC4F0u;
    // 800BC4F0: stw     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BC4F4:
    ctx->pc = 0x800BC4F4u;
    // 800BC4F4: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BC4F8:
    ctx->pc = 0x800BC4F8u;
    // 800BC4F8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC4FC:
    ctx->pc = 0x800BC4FCu;
    // 800BC4FC: lwz     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC500:
    ctx->pc = 0x800BC500u;
    // 800BC500: lwz     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC504:
    ctx->pc = 0x800BC504u;
    // 800BC504: lwz     r10, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BC508:
    ctx->pc = 0x800BC508u;
    // 800BC508: stw     r9, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC50C:
    ctx->pc = 0x800BC50Cu;
    // 800BC50C: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC510:
    ctx->pc = 0x800BC510u;
    // 800BC510: stw     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BC514:
    ctx->pc = 0x800BC514u;
    // 800BC514: bl      0x800C14A8
    {
            ctx->lr = 0x800BC518u;
            ctx->pc = 0x800C14A8u;
            return;
    }

label_800BC518:
    ctx->pc = 0x800BC518u;
    ctx->downcount -= 4;
    // 800BC518: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BC51C:
    ctx->pc = 0x800BC51Cu;
    // 800BC51C: stw     r0, 40(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC520:
    ctx->pc = 0x800BC520u;
    // 800BC520: lwz     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC524:
    ctx->pc = 0x800BC524u;
    // 800BC524: stw     r9, 44(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC528:
    ctx->pc = 0x800BC528u;
    ctx->downcount -= 16;
    // 800BC528: lwz     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC52C:
    ctx->pc = 0x800BC52Cu;
    // 800BC52C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BC530:
    ctx->pc = 0x800BC530u;
    // 800BC530: lmw     r27, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BC534:
    ctx->pc = 0x800BC534u;
    // 800BC534: addi    r1, r1, 112
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(112);

label_800BC538:
    ctx->pc = 0x800BC538u;
    // 800BC538: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BC53C:
    ctx->pc = 0x800BC53Cu;
    ctx->downcount -= 5;
    // 800BC53C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BC540:
    ctx->pc = 0x800BC540u;
    // 800BC540: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BC544:
    ctx->pc = 0x800BC544u;
    // 800BC544: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC548:
    ctx->pc = 0x800BC548u;
    // 800BC548: addi    r3, r3, 3720
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3720);

label_800BC54C:
    ctx->pc = 0x800BC54Cu;
    // 800BC54C: bl      0x800C1A00
    {
            ctx->lr = 0x800BC550u;
            ctx->pc = 0x800C1A00u;
            return;
    }

label_800BC550:
    ctx->pc = 0x800BC550u;
    ctx->downcount -= 5;
    // 800BC550: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC554:
    ctx->pc = 0x800BC554u;
    // 800BC554: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BC558:
    ctx->pc = 0x800BC558u;
    // 800BC558: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC55C:
    ctx->pc = 0x800BC55Cu;
    // 800BC55C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BC560:
    ctx->pc = 0x800BC560u;
    ctx->downcount -= 2;
    // 800BC560: or.   r3, r3, r3
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

label_800BC564:
    ctx->pc = 0x800BC564u;
    // 800BC564: bc    12, 2, 0x800BC634
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC634;
        }
    }

label_800BC568:
    ctx->pc = 0x800BC568u;
    ctx->downcount -= 3;
    // 800BC568: lwz     r0, 72(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC56C:
    ctx->pc = 0x800BC56Cu;
    // 800BC56C: cmpwi   r0, 14
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

label_800BC570:
    ctx->pc = 0x800BC570u;
    // 800BC570: bc    12, 2, 0x800BC580
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC580;
        }
    }

label_800BC574:
    ctx->pc = 0x800BC574u;
    ctx->downcount -= 2;
    // 800BC574: cmpwi   r0, 17
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

label_800BC578:
    ctx->pc = 0x800BC578u;
    // 800BC578: bc    12, 2, 0x800BC620
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC620;
        }
    }

label_800BC57C:
    ctx->pc = 0x800BC57Cu;
    ctx->downcount -= 1;
    // 800BC57C: b       0x800BC634
    {
            goto label_800BC634;
    }

label_800BC580:
    ctx->pc = 0x800BC580u;
    ctx->downcount -= 8;
    // 800BC580: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BC584:
    ctx->pc = 0x800BC584u;
    // 800BC584: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BC588:
    ctx->pc = 0x800BC588u;
    // 800BC588: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC58C:
    ctx->pc = 0x800BC58Cu;
    // 800BC58C: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC590:
    ctx->pc = 0x800BC590u;
    // 800BC590: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_800BC594:
    ctx->pc = 0x800BC594u;
    // 800BC594: rlwinm r9, r0, 0, 23, 23
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000100u;
    }

label_800BC598:
    ctx->pc = 0x800BC598u;
    // 800BC598: and.   r10, r9, r11
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

label_800BC59C:
    ctx->pc = 0x800BC59Cu;
    // 800BC59C: bc    12, 2, 0x800BC5C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC5C0;
        }
    }

label_800BC5A0:
    ctx->pc = 0x800BC5A0u;
    ctx->downcount -= 3;
    // 800BC5A0: lwz     r9, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC5A4:
    ctx->pc = 0x800BC5A4u;
    // 800BC5A4: cmpwi   r9, 1
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

label_800BC5A8:
    ctx->pc = 0x800BC5A8u;
    // 800BC5A8: bc    4, 1, 0x800BC5F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BC5F8;
        }
    }

label_800BC5AC:
    ctx->pc = 0x800BC5ACu;
    ctx->downcount -= 5;
    // 800BC5AC: addi    r0, r9, -2
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(-2);

label_800BC5B0:
    ctx->pc = 0x800BC5B0u;
    // 800BC5B0: li      r9, 2
    ctx->gpr[9] = (u32)(s32)(2);

label_800BC5B4:
    ctx->pc = 0x800BC5B4u;
    // 800BC5B4: stw     r0, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC5B8:
    ctx->pc = 0x800BC5B8u;
    // 800BC5B8: stw     r9, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC5BC:
    ctx->pc = 0x800BC5BCu;
    // 800BC5BC: b       0x800BC5EC
    {
            goto label_800BC5EC;
    }

label_800BC5C0:
    ctx->pc = 0x800BC5C0u;
    ctx->downcount -= 3;
    // 800BC5C0: rlwinm r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
    }

label_800BC5C4:
    ctx->pc = 0x800BC5C4u;
    // 800BC5C4: and.   r9, r0, r11
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

label_800BC5C8:
    ctx->pc = 0x800BC5C8u;
    // 800BC5C8: bc    12, 2, 0x800BC5EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC5EC;
        }
    }

label_800BC5CC:
    ctx->pc = 0x800BC5CCu;
    ctx->downcount -= 5;
    // 800BC5CC: lwz     r9, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC5D0:
    ctx->pc = 0x800BC5D0u;
    // 800BC5D0: lwz     r0, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC5D4:
    ctx->pc = 0x800BC5D4u;
    // 800BC5D4: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_800BC5D8:
    ctx->pc = 0x800BC5D8u;
    // 800BC5D8: cmpw    r9, r0
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

label_800BC5DC:
    ctx->pc = 0x800BC5DCu;
    // 800BC5DC: bc    4, 0, 0x800BC5EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BC5EC;
        }
    }

label_800BC5E0:
    ctx->pc = 0x800BC5E0u;
    ctx->downcount -= 3;
    // 800BC5E0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800BC5E4:
    ctx->pc = 0x800BC5E4u;
    // 800BC5E4: stw     r9, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC5E8:
    ctx->pc = 0x800BC5E8u;
    // 800BC5E8: stw     r0, 68(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC5EC:
    ctx->pc = 0x800BC5ECu;
    ctx->downcount -= 3;
    // 800BC5EC: lwz     r11, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC5F0:
    ctx->pc = 0x800BC5F0u;
    // 800BC5F0: cmpwi   r11, 1
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BC5F4:
    ctx->pc = 0x800BC5F4u;
    // 800BC5F4: bc    12, 1, 0x800BC604
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC604;
        }
    }

label_800BC5F8:
    ctx->pc = 0x800BC5F8u;
    ctx->downcount -= 3;
    // 800BC5F8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BC5FC:
    ctx->pc = 0x800BC5FCu;
    // 800BC5FC: stw     r0, 116(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC600:
    ctx->pc = 0x800BC600u;
    // 800BC600: b       0x800BC634
    {
            goto label_800BC634;
    }

label_800BC604:
    ctx->pc = 0x800BC604u;
    ctx->downcount -= 4;
    // 800BC604: lwz     r9, 44(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC608:
    ctx->pc = 0x800BC608u;
    // 800BC608: addi    r0, r11, 2
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(2);

label_800BC60C:
    ctx->pc = 0x800BC60Cu;
    // 800BC60C: cmpw    r0, r9
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

label_800BC610:
    ctx->pc = 0x800BC610u;
    // 800BC610: bc    12, 0, 0x800BC634
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC634;
        }
    }

label_800BC614:
    ctx->pc = 0x800BC614u;
    ctx->downcount -= 3;
    // 800BC614: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BC618:
    ctx->pc = 0x800BC618u;
    // 800BC618: stw     r0, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC61C:
    ctx->pc = 0x800BC61Cu;
    // 800BC61C: b       0x800BC634
    {
            goto label_800BC634;
    }

label_800BC620:
    ctx->pc = 0x800BC620u;
    ctx->downcount -= 5;
    // 800BC620: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC624:
    ctx->pc = 0x800BC624u;
    // 800BC624: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_800BC628:
    ctx->pc = 0x800BC628u;
    // 800BC628: stw     r9, 120(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC62C:
    ctx->pc = 0x800BC62Cu;
    // 800BC62C: stw     r0, 72(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC630:
    ctx->pc = 0x800BC630u;
    // 800BC630: stw     r9, 116(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC634:
    ctx->pc = 0x800BC634u;
    ctx->downcount -= 2;
    // 800BC634: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC638:
    ctx->pc = 0x800BC638u;
    // 800BC638: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BC63C:
    ctx->pc = 0x800BC63Cu;
    ctx->downcount -= 18;
    // 800BC63C: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BC640:
    ctx->pc = 0x800BC640u;
    // 800BC640: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BC644:
    ctx->pc = 0x800BC644u;
    // 800BC644: stmw     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BC648:
    ctx->pc = 0x800BC648u;
    // 800BC648: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC64C:
    ctx->pc = 0x800BC64Cu;
    // 800BC64C: lis     r9, -32698
    ctx->gpr[9] = ((u32)(s32)(-32698) << 16);

label_800BC650:
    ctx->pc = 0x800BC650u;
    // 800BC650: or.   r31, r3, r3
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

label_800BC654:
    ctx->pc = 0x800BC654u;
    // 800BC654: addi    r3, r9, 7984
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(7984);

label_800BC658:
    ctx->pc = 0x800BC658u;
    // 800BC658: bc    12, 2, 0x800BC780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC780;
        }
    }

label_800BC65C:
    ctx->pc = 0x800BC65Cu;
    ctx->downcount -= 3;
    // 800BC65C: lwz     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC660:
    ctx->pc = 0x800BC660u;
    // 800BC660: cmpwi   r0, 14
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

label_800BC664:
    ctx->pc = 0x800BC664u;
    // 800BC664: bc    4, 2, 0x800BC780
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BC780;
        }
    }

label_800BC668:
    ctx->pc = 0x800BC668u;
    ctx->downcount -= 3;
    // 800BC668: lwz     r0, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC66C:
    ctx->pc = 0x800BC66Cu;
    // 800BC66C: cmpwi   r0, 0
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

label_800BC670:
    ctx->pc = 0x800BC670u;
    // 800BC670: bc    4, 2, 0x800BC758
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BC758;
        }
    }

label_800BC674:
    ctx->pc = 0x800BC674u;
    ctx->downcount -= 29;
    // 800BC674: lwz     r11, 1432(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC678:
    ctx->pc = 0x800BC678u;
    // 800BC678: addi    r9, r31, 1432
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(1432);

label_800BC67C:
    ctx->pc = 0x800BC67Cu;
    // 800BC67C: lwz     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BC680:
    ctx->pc = 0x800BC680u;
    // 800BC680: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC684:
    ctx->pc = 0x800BC684u;
    // 800BC684: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC688:
    ctx->pc = 0x800BC688u;
    // 800BC688: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BC68C:
    ctx->pc = 0x800BC68Cu;
    // 800BC68C: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC690:
    ctx->pc = 0x800BC690u;
    // 800BC690: addi    r30, r1, 24
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(24);

label_800BC694:
    ctx->pc = 0x800BC694u;
    // 800BC694: stw     r8, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BC698:
    ctx->pc = 0x800BC698u;
    // 800BC698: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BC69C:
    ctx->pc = 0x800BC69Cu;
    // 800BC69C: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC6A0:
    ctx->pc = 0x800BC6A0u;
    // 800BC6A0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC6A4:
    ctx->pc = 0x800BC6A4u;
    // 800BC6A4: lfs     f13, -16020(r10)
    if (!ppc_fp_available(ctx, 0x800BC6A4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-16020);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BC6A8:
    ctx->pc = 0x800BC6A8u;
    // 800BC6A8: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC6AC:
    ctx->pc = 0x800BC6ACu;
    // 800BC6AC: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC6ACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BC6B0:
    ctx->pc = 0x800BC6B0u;
    // 800BC6B0: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BC6B4:
    ctx->pc = 0x800BC6B4u;
    // 800BC6B4: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_800BC6B8:
    ctx->pc = 0x800BC6B8u;
    // 800BC6B8: li      r5, 3702
    ctx->gpr[5] = (u32)(s32)(3702);

label_800BC6BC:
    ctx->pc = 0x800BC6BCu;
    // 800BC6BC: fadds   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BC6BCu)) return;
    ppc_fadds(ctx, 0, 0, 13);

label_800BC6C0:
    ctx->pc = 0x800BC6C0u;
    // 800BC6C0: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BC6C4:
    ctx->pc = 0x800BC6C4u;
    // 800BC6C4: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC6C4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC6C8:
    ctx->pc = 0x800BC6C8u;
    // 800BC6C8: li      r7, 180
    ctx->gpr[7] = (u32)(s32)(180);

label_800BC6CC:
    ctx->pc = 0x800BC6CCu;
    // 800BC6CC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC6D0:
    ctx->pc = 0x800BC6D0u;
    // 800BC6D0: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC6D4:
    ctx->pc = 0x800BC6D4u;
    // 800BC6D4: lwz     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC6D8:
    ctx->pc = 0x800BC6D8u;
    // 800BC6D8: stw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_800BC6DC:
    ctx->pc = 0x800BC6DCu;
    // 800BC6DC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC6E0:
    ctx->pc = 0x800BC6E0u;
    // 800BC6E0: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC6E4:
    ctx->pc = 0x800BC6E4u;
    // 800BC6E4: bl      0x800C3D88
    {
            ctx->lr = 0x800BC6E8u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BC6E8:
    ctx->pc = 0x800BC6E8u;
    ctx->downcount -= 28;
    // 800BC6E8: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_800BC6EC:
    ctx->pc = 0x800BC6ECu;
    // 800BC6EC: stw     r3, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BC6F0:
    ctx->pc = 0x800BC6F0u;
    // 800BC6F0: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_800BC6F4:
    ctx->pc = 0x800BC6F4u;
    // 800BC6F4: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BC6F8:
    ctx->pc = 0x800BC6F8u;
    // 800BC6F8: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BC6FC:
    ctx->pc = 0x800BC6FCu;
    // 800BC6FC: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC700:
    ctx->pc = 0x800BC700u;
    // 800BC700: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC704:
    ctx->pc = 0x800BC704u;
    // 800BC704: lfd     f13, -16016(r11)
    if (!ppc_fp_available(ctx, 0x800BC704u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16016);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BC708:
    ctx->pc = 0x800BC708u;
    // 800BC708: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BC70C:
    ctx->pc = 0x800BC70Cu;
    // 800BC70C: lfd     f0, 40(r1)
    if (!ppc_fp_available(ctx, 0x800BC70Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BC710:
    ctx->pc = 0x800BC710u;
    // 800BC710: li      r5, 3810
    ctx->gpr[5] = (u32)(s32)(3810);

label_800BC714:
    ctx->pc = 0x800BC714u;
    // 800BC714: lfs     f12, -16008(r10)
    if (!ppc_fp_available(ctx, 0x800BC714u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-16008);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BC718:
    ctx->pc = 0x800BC718u;
    // 800BC718: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC71C:
    ctx->pc = 0x800BC71Cu;
    // 800BC71C: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BC71Cu)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800BC720:
    ctx->pc = 0x800BC720u;
    // 800BC720: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_800BC724:
    ctx->pc = 0x800BC724u;
    // 800BC724: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x800BC724u)) return;
    ppc_frsp(ctx, 0, 0);

label_800BC728:
    ctx->pc = 0x800BC728u;
    // 800BC728: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BC72C:
    ctx->pc = 0x800BC72Cu;
    // 800BC72C: fadds   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x800BC72Cu)) return;
    ppc_fadds(ctx, 0, 0, 12);

label_800BC730:
    ctx->pc = 0x800BC730u;
    // 800BC730: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BC734:
    ctx->pc = 0x800BC734u;
    // 800BC734: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BC734u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BC738:
    ctx->pc = 0x800BC738u;
    // 800BC738: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BC73C:
    ctx->pc = 0x800BC73Cu;
    // 800BC73C: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BC740:
    ctx->pc = 0x800BC740u;
    // 800BC740: lwz     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC744:
    ctx->pc = 0x800BC744u;
    // 800BC744: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC748:
    ctx->pc = 0x800BC748u;
    // 800BC748: stw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_800BC74C:
    ctx->pc = 0x800BC74Cu;
    // 800BC74C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC750:
    ctx->pc = 0x800BC750u;
    // 800BC750: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC754:
    ctx->pc = 0x800BC754u;
    // 800BC754: bl      0x800C3D88
    {
            ctx->lr = 0x800BC758u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BC758:
    ctx->pc = 0x800BC758u;
    ctx->downcount -= 5;
    // 800BC758: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BC75C:
    ctx->pc = 0x800BC75Cu;
    // 800BC75C: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BC760:
    ctx->pc = 0x800BC760u;
    // 800BC760: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC764:
    ctx->pc = 0x800BC764u;
    // 800BC764: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC768:
    ctx->pc = 0x800BC768u;
    // 800BC768: bl      0x800C1D34
    {
            ctx->lr = 0x800BC76Cu;
            ctx->pc = 0x800C1D34u;
            return;
    }

label_800BC76C:
    ctx->pc = 0x800BC76Cu;
    ctx->downcount -= 5;
    // 800BC76C: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BC770:
    ctx->pc = 0x800BC770u;
    // 800BC770: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC774:
    ctx->pc = 0x800BC774u;
    // 800BC774: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC778:
    ctx->pc = 0x800BC778u;
    // 800BC778: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BC77C:
    ctx->pc = 0x800BC77Cu;
    // 800BC77C: bl      0x800C1D34
    {
            ctx->lr = 0x800BC780u;
            ctx->pc = 0x800C1D34u;
            return;
    }

label_800BC780:
    ctx->pc = 0x800BC780u;
    ctx->downcount -= 16;
    // 800BC780: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC784:
    ctx->pc = 0x800BC784u;
    // 800BC784: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BC788:
    ctx->pc = 0x800BC788u;
    // 800BC788: lmw     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BC78C:
    ctx->pc = 0x800BC78Cu;
    // 800BC78C: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_800BC790:
    ctx->pc = 0x800BC790u;
    // 800BC790: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BC794:
    ctx->pc = 0x800BC794u;
    ctx->downcount -= 5;
    // 800BC794: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BC798:
    ctx->pc = 0x800BC798u;
    // 800BC798: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BC79C:
    ctx->pc = 0x800BC79Cu;
    // 800BC79C: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC7A0:
    ctx->pc = 0x800BC7A0u;
    // 800BC7A0: cmpwi   r4, 0
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

label_800BC7A4:
    ctx->pc = 0x800BC7A4u;
    // 800BC7A4: bc    4, 2, 0x800BC7B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BC7B0;
        }
    }

label_800BC7A8:
    ctx->pc = 0x800BC7A8u;
    ctx->downcount -= 2;
    // 800BC7A8: li      r3, 470
    ctx->gpr[3] = (u32)(s32)(470);

label_800BC7AC:
    ctx->pc = 0x800BC7ACu;
    // 800BC7AC: bl      0x8005B3F8
    {
            ctx->lr = 0x800BC7B0u;
            ctx->pc = 0x8005B3F8u;
            return;
    }

label_800BC7B0:
    ctx->pc = 0x800BC7B0u;
    ctx->downcount -= 5;
    // 800BC7B0: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC7B4:
    ctx->pc = 0x800BC7B4u;
    // 800BC7B4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BC7B8:
    ctx->pc = 0x800BC7B8u;
    // 800BC7B8: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC7BC:
    ctx->pc = 0x800BC7BCu;
    // 800BC7BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BC7C0:
    ctx->pc = 0x800BC7C0u;
    ctx->downcount -= 16;
    // 800BC7C0: stwu     r1, -184(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-184);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BC7C4:
    ctx->pc = 0x800BC7C4u;
    // 800BC7C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BC7C8:
    ctx->pc = 0x800BC7C8u;
    // 800BC7C8: stmw     r24, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        for (u32 r = 24; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BC7CC:
    ctx->pc = 0x800BC7CCu;
    // 800BC7CC: stw     r0, 188(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC7D0:
    ctx->pc = 0x800BC7D0u;
    // 800BC7D0: or.   r31, r3, r3
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

label_800BC7D4:
    ctx->pc = 0x800BC7D4u;
    // 800BC7D4: bc    12, 2, 0x800BC9D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC9D4;
        }
    }

label_800BC7D8:
    ctx->pc = 0x800BC7D8u;
    ctx->downcount -= 5;
    // 800BC7D8: lwz     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BC7DC:
    ctx->pc = 0x800BC7DCu;
    // 800BC7DC: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_800BC7E0:
    ctx->pc = 0x800BC7E0u;
    // 800BC7E0: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC7E4:
    ctx->pc = 0x800BC7E4u;
    // 800BC7E4: cmpwi   r3, 0
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

label_800BC7E8:
    ctx->pc = 0x800BC7E8u;
    // 800BC7E8: bc    12, 2, 0x800BC9D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC9D4;
        }
    }

label_800BC7EC:
    ctx->pc = 0x800BC7ECu;
    ctx->downcount -= 3;
    // 800BC7EC: lis     r4, 20992
    ctx->gpr[4] = ((u32)(s32)(20992) << 16);

label_800BC7F0:
    ctx->pc = 0x800BC7F0u;
    // 800BC7F0: ori     r4, r4, 0x0129
    ctx->gpr[4] = ctx->gpr[4] | 0x0129u;

label_800BC7F4:
    ctx->pc = 0x800BC7F4u;
    // 800BC7F4: bl      0x80047634
    {
            ctx->lr = 0x800BC7F8u;
            ctx->pc = 0x80047634u;
            return;
    }

label_800BC7F8:
    ctx->pc = 0x800BC7F8u;
    ctx->downcount -= 2;
    // 800BC7F8: or.   r29, r3, r3
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

label_800BC7FC:
    ctx->pc = 0x800BC7FCu;
    // 800BC7FC: bc    12, 2, 0x800BC9D4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC9D4;
        }
    }

label_800BC800:
    ctx->pc = 0x800BC800u;
    ctx->downcount -= 7;
    // 800BC800: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BC804:
    ctx->pc = 0x800BC804u;
    // 800BC804: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BC808:
    ctx->pc = 0x800BC808u;
    // 800BC808: ori     r4, r4, 0x00B6
    ctx->gpr[4] = ctx->gpr[4] | 0x00B6u;

label_800BC80C:
    ctx->pc = 0x800BC80Cu;
    // 800BC80C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC810:
    ctx->pc = 0x800BC810u;
    // 800BC810: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC814:
    ctx->pc = 0x800BC814u;
    // 800BC814: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BC818:
    ctx->pc = 0x800BC818u;
    // 800BC818: bl      0x800303A8
    {
            ctx->lr = 0x800BC81Cu;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BC81C:
    ctx->pc = 0x800BC81Cu;
    ctx->downcount -= 3;
    // 800BC81C: addi    r24, r1, 40
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(40);

label_800BC820:
    ctx->pc = 0x800BC820u;
    // 800BC820: cmpwi   r3, 0
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

label_800BC824:
    ctx->pc = 0x800BC824u;
    // 800BC824: bc    12, 2, 0x800BC86C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC86C;
        }
    }

label_800BC828:
    ctx->pc = 0x800BC828u;
    ctx->downcount -= 6;
    // 800BC828: addi    r30, r1, 72
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(72);

label_800BC82C:
    ctx->pc = 0x800BC82Cu;
    // 800BC82C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC830:
    ctx->pc = 0x800BC830u;
    // 800BC830: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC834:
    ctx->pc = 0x800BC834u;
    // 800BC834: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC838:
    ctx->pc = 0x800BC838u;
    // 800BC838: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC83C:
    ctx->pc = 0x800BC83Cu;
    // 800BC83C: bl      0x800C48AC
    {
            ctx->lr = 0x800BC840u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BC840:
    ctx->pc = 0x800BC840u;
    ctx->downcount -= 11;
    // 800BC840: lwz     r0, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC844:
    ctx->pc = 0x800BC844u;
    // 800BC844: addi    r10, r31, 1432
    ctx->gpr[10] = ctx->gpr[31] + (u32)(s32)(1432);

label_800BC848:
    ctx->pc = 0x800BC848u;
    // 800BC848: lwz     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC84C:
    ctx->pc = 0x800BC84Cu;
    // 800BC84C: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC850:
    ctx->pc = 0x800BC850u;
    // 800BC850: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC854:
    ctx->pc = 0x800BC854u;
    // 800BC854: stw     r11, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC858:
    ctx->pc = 0x800BC858u;
    // 800BC858: stw     r9, 8(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC85C:
    ctx->pc = 0x800BC85Cu;
    // 800BC85C: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC860:
    ctx->pc = 0x800BC860u;
    // 800BC860: stw     r0, 1432(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC864:
    ctx->pc = 0x800BC864u;
    // 800BC864: stw     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC868:
    ctx->pc = 0x800BC868u;
    // 800BC868: stw     r11, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC86C:
    ctx->pc = 0x800BC86Cu;
    ctx->downcount -= 9;
    // 800BC86C: addi    r25, r1, 24
    ctx->gpr[25] = ctx->gpr[1] + (u32)(s32)(24);

label_800BC870:
    ctx->pc = 0x800BC870u;
    // 800BC870: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BC874:
    ctx->pc = 0x800BC874u;
    // 800BC874: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BC878:
    ctx->pc = 0x800BC878u;
    // 800BC878: ori     r4, r4, 0x00BA
    ctx->gpr[4] = ctx->gpr[4] | 0x00BAu;

label_800BC87C:
    ctx->pc = 0x800BC87Cu;
    // 800BC87C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC880:
    ctx->pc = 0x800BC880u;
    // 800BC880: or   r6, r25, r25
    {
        ctx->gpr[6] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BC884:
    ctx->pc = 0x800BC884u;
    // 800BC884: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BC888:
    ctx->pc = 0x800BC888u;
    // 800BC888: addi    r26, r1, 56
    ctx->gpr[26] = ctx->gpr[1] + (u32)(s32)(56);

label_800BC88C:
    ctx->pc = 0x800BC88Cu;
    // 800BC88C: bl      0x800303A8
    {
            ctx->lr = 0x800BC890u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BC890:
    ctx->pc = 0x800BC890u;
    ctx->downcount -= 2;
    // 800BC890: cmpwi   r3, 0
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

label_800BC894:
    ctx->pc = 0x800BC894u;
    // 800BC894: bc    12, 2, 0x800BC8C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BC8C8;
        }
    }

label_800BC898:
    ctx->pc = 0x800BC898u;
    ctx->downcount -= 6;
    // 800BC898: addi    r30, r1, 72
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(72);

label_800BC89C:
    ctx->pc = 0x800BC89Cu;
    // 800BC89C: or   r4, r25, r25
    {
        ctx->gpr[4] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BC8A0:
    ctx->pc = 0x800BC8A0u;
    // 800BC8A0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC8A4:
    ctx->pc = 0x800BC8A4u;
    // 800BC8A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC8A8:
    ctx->pc = 0x800BC8A8u;
    // 800BC8A8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BC8AC:
    ctx->pc = 0x800BC8ACu;
    // 800BC8AC: bl      0x800C48AC
    {
            ctx->lr = 0x800BC8B0u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BC8B0:
    ctx->pc = 0x800BC8B0u;
    ctx->downcount -= 6;
    // 800BC8B0: lwz     r9, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC8B4:
    ctx->pc = 0x800BC8B4u;
    // 800BC8B4: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC8B8:
    ctx->pc = 0x800BC8B8u;
    // 800BC8B8: lwz     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC8BC:
    ctx->pc = 0x800BC8BCu;
    // 800BC8BC: stw     r9, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC8C0:
    ctx->pc = 0x800BC8C0u;
    // 800BC8C0: stw     r0, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC8C4:
    ctx->pc = 0x800BC8C4u;
    // 800BC8C4: stw     r11, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC8C8:
    ctx->pc = 0x800BC8C8u;
    ctx->downcount -= 9;
    // 800BC8C8: addi    r27, r1, 88
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(88);

label_800BC8CC:
    ctx->pc = 0x800BC8CCu;
    // 800BC8CC: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BC8D0:
    ctx->pc = 0x800BC8D0u;
    // 800BC8D0: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BC8D4:
    ctx->pc = 0x800BC8D4u;
    // 800BC8D4: ori     r4, r4, 0x00C2
    ctx->gpr[4] = ctx->gpr[4] | 0x00C2u;

label_800BC8D8:
    ctx->pc = 0x800BC8D8u;
    // 800BC8D8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BC8DC:
    ctx->pc = 0x800BC8DCu;
    // 800BC8DC: or   r6, r27, r27
    {
        ctx->gpr[6] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BC8E0:
    ctx->pc = 0x800BC8E0u;
    // 800BC8E0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BC8E4:
    ctx->pc = 0x800BC8E4u;
    // 800BC8E4: addi    r28, r31, 3720
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BC8E8:
    ctx->pc = 0x800BC8E8u;
    // 800BC8E8: bl      0x800303A8
    {
            ctx->lr = 0x800BC8ECu;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BC8EC:
    ctx->pc = 0x800BC8ECu;
    ctx->downcount -= 4;
    // 800BC8EC: addi    r30, r1, 104
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(104);

label_800BC8F0:
    ctx->pc = 0x800BC8F0u;
    // 800BC8F0: addi    r29, r1, 120
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(120);

label_800BC8F4:
    ctx->pc = 0x800BC8F4u;
    // 800BC8F4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BC8F8:
    ctx->pc = 0x800BC8F8u;
    // 800BC8F8: bl      0x800C13B0
    {
            ctx->lr = 0x800BC8FCu;
            ctx->pc = 0x800C13B0u;
            return;
    }

label_800BC8FC:
    ctx->pc = 0x800BC8FCu;
    ctx->downcount -= 25;
    // 800BC8FC: lwz     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC900:
    ctx->pc = 0x800BC900u;
    // 800BC900: addi    r9, r1, 8
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(8);

label_800BC904:
    ctx->pc = 0x800BC904u;
    // 800BC904: lwz     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BC908:
    ctx->pc = 0x800BC908u;
    // 800BC908: addi    r10, r1, 136
    ctx->gpr[10] = ctx->gpr[1] + (u32)(s32)(136);

label_800BC90C:
    ctx->pc = 0x800BC90Cu;
    // 800BC90C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC910:
    ctx->pc = 0x800BC910u;
    // 800BC910: or   r6, r10, r10
    {
        ctx->gpr[6] = ctx->gpr[10] | ctx->gpr[10];
    }

label_800BC914:
    ctx->pc = 0x800BC914u;
    // 800BC914: stw     r11, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC918:
    ctx->pc = 0x800BC918u;
    // 800BC918: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC91C:
    ctx->pc = 0x800BC91Cu;
    // 800BC91C: stw     r8, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BC920:
    ctx->pc = 0x800BC920u;
    // 800BC920: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BC924:
    ctx->pc = 0x800BC924u;
    // 800BC924: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC928:
    ctx->pc = 0x800BC928u;
    // 800BC928: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BC92C:
    ctx->pc = 0x800BC92Cu;
    // 800BC92C: lwz     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC930:
    ctx->pc = 0x800BC930u;
    // 800BC930: lwz     r11, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC934:
    ctx->pc = 0x800BC934u;
    // 800BC934: lwz     r0, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC938:
    ctx->pc = 0x800BC938u;
    // 800BC938: stw     r9, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC93C:
    ctx->pc = 0x800BC93Cu;
    // 800BC93C: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC940:
    ctx->pc = 0x800BC940u;
    // 800BC940: stw     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC944:
    ctx->pc = 0x800BC944u;
    // 800BC944: lwz     r9, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC948:
    ctx->pc = 0x800BC948u;
    // 800BC948: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC94C:
    ctx->pc = 0x800BC94Cu;
    // 800BC94C: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC950:
    ctx->pc = 0x800BC950u;
    // 800BC950: stw     r9, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC954:
    ctx->pc = 0x800BC954u;
    // 800BC954: stw     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC958:
    ctx->pc = 0x800BC958u;
    // 800BC958: stw     r11, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC95C:
    ctx->pc = 0x800BC95Cu;
    // 800BC95C: bl      0x800C140C
    {
            ctx->lr = 0x800BC960u;
            ctx->pc = 0x800C140Cu;
            return;
    }

label_800BC960:
    ctx->pc = 0x800BC960u;
    ctx->downcount -= 18;
    // 800BC960: lwz     r9, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC964:
    ctx->pc = 0x800BC964u;
    // 800BC964: lis     r4, -32734
    ctx->gpr[4] = ((u32)(s32)(-32734) << 16);

label_800BC968:
    ctx->pc = 0x800BC968u;
    // 800BC968: lwz     r11, 8(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC96C:
    ctx->pc = 0x800BC96Cu;
    // 800BC96C: addi    r4, r4, -6400
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-6400);

label_800BC970:
    ctx->pc = 0x800BC970u;
    // 800BC970: lwz     r0, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC974:
    ctx->pc = 0x800BC974u;
    // 800BC974: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BC978:
    ctx->pc = 0x800BC978u;
    // 800BC978: stw     r9, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC97C:
    ctx->pc = 0x800BC97Cu;
    // 800BC97C: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BC980:
    ctx->pc = 0x800BC980u;
    // 800BC980: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC984:
    ctx->pc = 0x800BC984u;
    // 800BC984: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BC988:
    ctx->pc = 0x800BC988u;
    // 800BC988: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC98C:
    ctx->pc = 0x800BC98Cu;
    // 800BC98C: lwz     r9, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BC990:
    ctx->pc = 0x800BC990u;
    // 800BC990: lwz     r11, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BC994:
    ctx->pc = 0x800BC994u;
    // 800BC994: lwz     r0, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC998:
    ctx->pc = 0x800BC998u;
    // 800BC998: stw     r9, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BC99C:
    ctx->pc = 0x800BC99Cu;
    // 800BC99C: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC9A0:
    ctx->pc = 0x800BC9A0u;
    // 800BC9A0: stw     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BC9A4:
    ctx->pc = 0x800BC9A4u;
    // 800BC9A4: bl      0x800C14A8
    {
            ctx->lr = 0x800BC9A8u;
            ctx->pc = 0x800C14A8u;
            return;
    }

label_800BC9A8:
    ctx->pc = 0x800BC9A8u;
    ctx->downcount -= 7;
    // 800BC9A8: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BC9AC:
    ctx->pc = 0x800BC9ACu;
    // 800BC9AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BC9B0:
    ctx->pc = 0x800BC9B0u;
    // 800BC9B0: stw     r0, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC9B4:
    ctx->pc = 0x800BC9B4u;
    // 800BC9B4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BC9B8:
    ctx->pc = 0x800BC9B8u;
    // 800BC9B8: lwz     r0, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC9BC:
    ctx->pc = 0x800BC9BCu;
    // 800BC9BC: stw     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC9C0:
    ctx->pc = 0x800BC9C0u;
    // 800BC9C0: bl      0x800C1AB0
    {
            ctx->lr = 0x800BC9C4u;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BC9C4:
    ctx->pc = 0x800BC9C4u;
    ctx->downcount -= 4;
    // 800BC9C4: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BC9C8:
    ctx->pc = 0x800BC9C8u;
    // 800BC9C8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BC9CC:
    ctx->pc = 0x800BC9CCu;
    // 800BC9CC: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BC9D0:
    ctx->pc = 0x800BC9D0u;
    // 800BC9D0: bl      0x800C1AB0
    {
            ctx->lr = 0x800BC9D4u;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BC9D4:
    ctx->pc = 0x800BC9D4u;
    ctx->downcount -= 16;
    // 800BC9D4: lwz     r0, 188(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BC9D8:
    ctx->pc = 0x800BC9D8u;
    // 800BC9D8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BC9DC:
    ctx->pc = 0x800BC9DCu;
    // 800BC9DC: lmw     r24, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        for (u32 r = 24; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BC9E0:
    ctx->pc = 0x800BC9E0u;
    // 800BC9E0: addi    r1, r1, 184
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(184);

label_800BC9E4:
    ctx->pc = 0x800BC9E4u;
    // 800BC9E4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BC9E8:
    ctx->pc = 0x800BC9E8u;
    ctx->downcount -= 5;
    // 800BC9E8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BC9EC:
    ctx->pc = 0x800BC9ECu;
    // 800BC9EC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BC9F0:
    ctx->pc = 0x800BC9F0u;
    // 800BC9F0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BC9F4:
    ctx->pc = 0x800BC9F4u;
    // 800BC9F4: addi    r3, r3, 3720
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3720);

label_800BC9F8:
    ctx->pc = 0x800BC9F8u;
    // 800BC9F8: bl      0x800C1A00
    {
            ctx->lr = 0x800BC9FCu;
            ctx->pc = 0x800C1A00u;
            return;
    }

label_800BC9FC:
    ctx->pc = 0x800BC9FCu;
    ctx->downcount -= 5;
    // 800BC9FC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCA00:
    ctx->pc = 0x800BCA00u;
    // 800BCA00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BCA04:
    ctx->pc = 0x800BCA04u;
    // 800BCA04: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BCA08:
    ctx->pc = 0x800BCA08u;
    // 800BCA08: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BCA0C:
    ctx->pc = 0x800BCA0Cu;
    ctx->downcount -= 17;
    // 800BCA0C: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BCA10:
    ctx->pc = 0x800BCA10u;
    // 800BCA10: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BCA14:
    ctx->pc = 0x800BCA14u;
    // 800BCA14: stmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BCA18:
    ctx->pc = 0x800BCA18u;
    // 800BCA18: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCA1C:
    ctx->pc = 0x800BCA1Cu;
    // 800BCA1C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_800BCA20:
    ctx->pc = 0x800BCA20u;
    // 800BCA20: or.   r31, r3, r3
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

label_800BCA24:
    ctx->pc = 0x800BCA24u;
    // 800BCA24: bc    12, 2, 0x800BCBC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCBC8;
        }
    }

label_800BCA28:
    ctx->pc = 0x800BCA28u;
    ctx->downcount -= 3;
    // 800BCA28: lwz     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCA2C:
    ctx->pc = 0x800BCA2Cu;
    // 800BCA2C: cmpwi   r0, 14
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

label_800BCA30:
    ctx->pc = 0x800BCA30u;
    // 800BCA30: bc    12, 2, 0x800BCA40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCA40;
        }
    }

label_800BCA34:
    ctx->pc = 0x800BCA34u;
    ctx->downcount -= 2;
    // 800BCA34: cmpwi   r0, 17
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

label_800BCA38:
    ctx->pc = 0x800BCA38u;
    // 800BCA38: bc    12, 2, 0x800BCB98
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCB98;
        }
    }

label_800BCA3C:
    ctx->pc = 0x800BCA3Cu;
    ctx->downcount -= 1;
    // 800BCA3C: b       0x800BCBC8
    {
            goto label_800BCBC8;
    }

label_800BCA40:
    ctx->pc = 0x800BCA40u;
    ctx->downcount -= 8;
    // 800BCA40: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BCA44:
    ctx->pc = 0x800BCA44u;
    // 800BCA44: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BCA48:
    ctx->pc = 0x800BCA48u;
    // 800BCA48: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BCA4C:
    ctx->pc = 0x800BCA4Cu;
    // 800BCA4C: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCA50:
    ctx->pc = 0x800BCA50u;
    // 800BCA50: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_800BCA54:
    ctx->pc = 0x800BCA54u;
    // 800BCA54: rlwinm r9, r0, 0, 23, 23
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000100u;
    }

label_800BCA58:
    ctx->pc = 0x800BCA58u;
    // 800BCA58: and.   r10, r9, r11
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

label_800BCA5C:
    ctx->pc = 0x800BCA5Cu;
    // 800BCA5C: bc    12, 2, 0x800BCA9C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCA9C;
        }
    }

label_800BCA60:
    ctx->pc = 0x800BCA60u;
    ctx->downcount -= 4;
    // 800BCA60: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCA64:
    ctx->pc = 0x800BCA64u;
    // 800BCA64: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BCA68:
    ctx->pc = 0x800BCA68u;
    // 800BCA68: cmpwi   r4, 1
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

label_800BCA6C:
    ctx->pc = 0x800BCA6Cu;
    // 800BCA6C: bc    4, 1, 0x800BCAEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCAEC;
        }
    }

label_800BCA70:
    ctx->pc = 0x800BCA70u;
    ctx->downcount -= 2;
    // 800BCA70: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCA74:
    ctx->pc = 0x800BCA74u;
    // 800BCA74: bl      0x800C1F74
    {
            ctx->lr = 0x800BCA78u;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BCA78:
    ctx->pc = 0x800BCA78u;
    ctx->downcount -= 4;
    // 800BCA78: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCA7C:
    ctx->pc = 0x800BCA7Cu;
    // 800BCA7C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCA80:
    ctx->pc = 0x800BCA80u;
    // 800BCA80: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BCA84:
    ctx->pc = 0x800BCA84u;
    // 800BCA84: bl      0x800C1F74
    {
            ctx->lr = 0x800BCA88u;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BCA88:
    ctx->pc = 0x800BCA88u;
    ctx->downcount -= 5;
    // 800BCA88: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BCA8C:
    ctx->pc = 0x800BCA8Cu;
    // 800BCA8C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_800BCA90:
    ctx->pc = 0x800BCA90u;
    // 800BCA90: stw     r0, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCA94:
    ctx->pc = 0x800BCA94u;
    // 800BCA94: addi    r9, r9, -2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2);

label_800BCA98:
    ctx->pc = 0x800BCA98u;
    // 800BCA98: b       0x800BCAE8
    {
            goto label_800BCAE8;
    }

label_800BCA9C:
    ctx->pc = 0x800BCA9Cu;
    ctx->downcount -= 4;
    // 800BCA9C: rlwinm r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
    }

label_800BCAA0:
    ctx->pc = 0x800BCAA0u;
    // 800BCAA0: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BCAA4:
    ctx->pc = 0x800BCAA4u;
    // 800BCAA4: and.   r9, r0, r11
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

label_800BCAA8:
    ctx->pc = 0x800BCAA8u;
    // 800BCAA8: bc    12, 2, 0x800BCAEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCAEC;
        }
    }

label_800BCAAC:
    ctx->pc = 0x800BCAACu;
    ctx->downcount -= 5;
    // 800BCAAC: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCAB0:
    ctx->pc = 0x800BCAB0u;
    // 800BCAB0: lwz     r9, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BCAB4:
    ctx->pc = 0x800BCAB4u;
    // 800BCAB4: addi    r0, r4, 2
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(2);

label_800BCAB8:
    ctx->pc = 0x800BCAB8u;
    // 800BCAB8: cmpw    r0, r9
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

label_800BCABC:
    ctx->pc = 0x800BCABCu;
    // 800BCABC: bc    4, 0, 0x800BCAEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCAEC;
        }
    }

label_800BCAC0:
    ctx->pc = 0x800BCAC0u;
    ctx->downcount -= 2;
    // 800BCAC0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCAC4:
    ctx->pc = 0x800BCAC4u;
    // 800BCAC4: bl      0x800C1F74
    {
            ctx->lr = 0x800BCAC8u;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BCAC8:
    ctx->pc = 0x800BCAC8u;
    ctx->downcount -= 4;
    // 800BCAC8: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCACC:
    ctx->pc = 0x800BCACCu;
    // 800BCACC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCAD0:
    ctx->pc = 0x800BCAD0u;
    // 800BCAD0: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BCAD4:
    ctx->pc = 0x800BCAD4u;
    // 800BCAD4: bl      0x800C1F74
    {
            ctx->lr = 0x800BCAD8u;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BCAD8:
    ctx->pc = 0x800BCAD8u;
    ctx->downcount -= 4;
    // 800BCAD8: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BCADC:
    ctx->pc = 0x800BCADCu;
    // 800BCADC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800BCAE0:
    ctx->pc = 0x800BCAE0u;
    // 800BCAE0: stw     r0, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCAE4:
    ctx->pc = 0x800BCAE4u;
    // 800BCAE4: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_800BCAE8:
    ctx->pc = 0x800BCAE8u;
    ctx->downcount -= 1;
    // 800BCAE8: stw     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BCAEC:
    ctx->pc = 0x800BCAECu;
    ctx->downcount -= 3;
    // 800BCAEC: lwz     r11, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BCAF0:
    ctx->pc = 0x800BCAF0u;
    // 800BCAF0: cmpwi   r11, 0
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

label_800BCAF4:
    ctx->pc = 0x800BCAF4u;
    // 800BCAF4: bc    4, 2, 0x800BCB40
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCB40;
        }
    }

label_800BCAF8:
    ctx->pc = 0x800BCAF8u;
    ctx->downcount -= 3;
    // 800BCAF8: lwz     r10, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BCAFC:
    ctx->pc = 0x800BCAFCu;
    // 800BCAFC: cmpwi   r10, 1
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

label_800BCB00:
    ctx->pc = 0x800BCB00u;
    // 800BCB00: bc    12, 1, 0x800BCB0C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCB0C;
        }
    }

label_800BCB04:
    ctx->pc = 0x800BCB04u;
    ctx->downcount -= 2;
    // 800BCB04: stw     r11, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCB08:
    ctx->pc = 0x800BCB08u;
    // 800BCB08: b       0x800BCB20
    {
            goto label_800BCB20;
    }

label_800BCB0C:
    ctx->pc = 0x800BCB0Cu;
    ctx->downcount -= 4;
    // 800BCB0C: lwz     r9, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BCB10:
    ctx->pc = 0x800BCB10u;
    // 800BCB10: addi    r0, r10, 2
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(2);

label_800BCB14:
    ctx->pc = 0x800BCB14u;
    // 800BCB14: cmpw    r0, r9
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

label_800BCB18:
    ctx->pc = 0x800BCB18u;
    // 800BCB18: bc    12, 0, 0x800BCB20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCB20;
        }
    }

label_800BCB1C:
    ctx->pc = 0x800BCB1Cu;
    ctx->downcount -= 1;
    // 800BCB1C: stw     r11, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCB20:
    ctx->pc = 0x800BCB20u;
    ctx->downcount -= 3;
    // 800BCB20: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCB24:
    ctx->pc = 0x800BCB24u;
    // 800BCB24: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCB28:
    ctx->pc = 0x800BCB28u;
    // 800BCB28: bl      0x800C1C7C
    {
            ctx->lr = 0x800BCB2Cu;
            ctx->pc = 0x800C1C7Cu;
            return;
    }

label_800BCB2C:
    ctx->pc = 0x800BCB2Cu;
    ctx->downcount -= 4;
    // 800BCB2C: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCB30:
    ctx->pc = 0x800BCB30u;
    // 800BCB30: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCB34:
    ctx->pc = 0x800BCB34u;
    // 800BCB34: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BCB38:
    ctx->pc = 0x800BCB38u;
    // 800BCB38: bl      0x800C1C7C
    {
            ctx->lr = 0x800BCB3Cu;
            ctx->pc = 0x800C1C7Cu;
            return;
    }

label_800BCB3C:
    ctx->pc = 0x800BCB3Cu;
    ctx->downcount -= 1;
    // 800BCB3C: b       0x800BCBC8
    {
            goto label_800BCBC8;
    }

label_800BCB40:
    ctx->pc = 0x800BCB40u;
    ctx->downcount -= 4;
    // 800BCB40: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCB44:
    ctx->pc = 0x800BCB44u;
    // 800BCB44: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCB48:
    ctx->pc = 0x800BCB48u;
    // 800BCB48: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BCB4C:
    ctx->pc = 0x800BCB4Cu;
    // 800BCB4C: bl      0x800C20F8
    {
            ctx->lr = 0x800BCB50u;
            ctx->pc = 0x800C20F8u;
            return;
    }

label_800BCB50:
    ctx->pc = 0x800BCB50u;
    ctx->downcount -= 3;
    // 800BCB50: or   r11, r3, r3
    {
        ctx->gpr[11] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BCB54:
    ctx->pc = 0x800BCB54u;
    // 800BCB54: cmpwi   r11, -1
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BCB58:
    ctx->pc = 0x800BCB58u;
    // 800BCB58: bc    12, 2, 0x800BCBC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCBC8;
        }
    }

label_800BCB5C:
    ctx->pc = 0x800BCB5Cu;
    ctx->downcount -= 2;
    // 800BCB5C: li      r29, 0
    ctx->gpr[29] = (u32)(s32)(0);

label_800BCB60:
    ctx->pc = 0x800BCB60u;
    // 800BCB60: b       0x800BCB68
    {
            goto label_800BCB68;
    }

label_800BCB64:
    ctx->downcount -= 1;
    // 800BCB64: addi    r29, r29, 1
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(1);

label_800BCB68:
    ctx->downcount -= 6;
    // 800BCB68: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BCB6C:
    // 800BCB6C: rlwinm r0, r29, 3, 0, 28
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[29], 3u) & 0xFFFFFFF8u;
    }

label_800BCB70:
    // 800BCB70: addi    r9, r9, -5124
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-5124);

label_800BCB74:
    ctx->pc = 0x800BCB74u;
    // 800BCB74: lwzx    r3, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BCB78:
    // 800BCB78: cmpwi   r3, 0
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

label_800BCB7C:
    // 800BCB7C: bc    12, 2, 0x800BCBC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCBC8;
        }
    }

label_800BCB80:
    ctx->downcount -= 4;
    // 800BCB80: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_800BCB84:
    ctx->pc = 0x800BCB84u;
    // 800BCB84: lwzx    r0, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCB88:
    // 800BCB88: cmpw    r0, r11
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BCB8C:
    // 800BCB8C: bc    4, 2, 0x800BCB64
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BCB64u;
                return;
            }
            goto label_800BCB64;
        }
    }

label_800BCB90:
    ctx->pc = 0x800BCB90u;
    ctx->downcount -= 1;
    // 800BCB90: bl      0x8005B3F8
    {
            ctx->lr = 0x800BCB94u;
            ctx->pc = 0x8005B3F8u;
            return;
    }

label_800BCB94:
    ctx->pc = 0x800BCB94u;
    ctx->downcount -= 1;
    // 800BCB94: b       0x800BCBC8
    {
            goto label_800BCBC8;
    }

label_800BCB98:
    ctx->pc = 0x800BCB98u;
    ctx->downcount -= 4;
    // 800BCB98: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCB9C:
    ctx->pc = 0x800BCB9Cu;
    // 800BCB9C: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BCBA0:
    ctx->pc = 0x800BCBA0u;
    // 800BCBA0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCBA4:
    ctx->pc = 0x800BCBA4u;
    // 800BCBA4: bl      0x800C1AB0
    {
            ctx->lr = 0x800BCBA8u;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BCBA8:
    ctx->pc = 0x800BCBA8u;
    ctx->downcount -= 4;
    // 800BCBA8: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCBAC:
    ctx->pc = 0x800BCBACu;
    // 800BCBAC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCBB0:
    ctx->pc = 0x800BCBB0u;
    // 800BCBB0: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BCBB4:
    ctx->pc = 0x800BCBB4u;
    // 800BCBB4: bl      0x800C1AB0
    {
            ctx->lr = 0x800BCBB8u;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BCBB8:
    ctx->pc = 0x800BCBB8u;
    ctx->downcount -= 4;
    // 800BCBB8: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_800BCBBC:
    ctx->pc = 0x800BCBBCu;
    // 800BCBBC: stw     r29, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800BCBC0:
    ctx->pc = 0x800BCBC0u;
    // 800BCBC0: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCBC4:
    ctx->pc = 0x800BCBC4u;
    // 800BCBC4: stw     r29, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800BCBC8:
    ctx->pc = 0x800BCBC8u;
    ctx->downcount -= 17;
    // 800BCBC8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BCBCC:
    ctx->pc = 0x800BCBCCu;
    // 800BCBCC: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCBD0:
    ctx->pc = 0x800BCBD0u;
    // 800BCBD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BCBD4:
    ctx->pc = 0x800BCBD4u;
    // 800BCBD4: lmw     r29, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BCBD8:
    ctx->pc = 0x800BCBD8u;
    // 800BCBD8: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800BCBDC:
    ctx->pc = 0x800BCBDCu;
    // 800BCBDC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BCBE0:
    ctx->pc = 0x800BCBE0u;
    ctx->downcount -= 18;
    // 800BCBE0: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BCBE4:
    ctx->pc = 0x800BCBE4u;
    // 800BCBE4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BCBE8:
    ctx->pc = 0x800BCBE8u;
    // 800BCBE8: stmw     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BCBEC:
    ctx->pc = 0x800BCBECu;
    // 800BCBEC: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCBF0:
    ctx->pc = 0x800BCBF0u;
    // 800BCBF0: lis     r9, -32698
    ctx->gpr[9] = ((u32)(s32)(-32698) << 16);

label_800BCBF4:
    ctx->pc = 0x800BCBF4u;
    // 800BCBF4: or.   r31, r3, r3
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

label_800BCBF8:
    ctx->pc = 0x800BCBF8u;
    // 800BCBF8: addi    r3, r9, 7984
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(7984);

label_800BCBFC:
    ctx->pc = 0x800BCBFCu;
    // 800BCBFC: bc    12, 2, 0x800BCD24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCD24;
        }
    }

label_800BCC00:
    ctx->pc = 0x800BCC00u;
    ctx->downcount -= 3;
    // 800BCC00: lwz     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCC04:
    ctx->pc = 0x800BCC04u;
    // 800BCC04: cmpwi   r0, 14
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

label_800BCC08:
    ctx->pc = 0x800BCC08u;
    // 800BCC08: bc    4, 2, 0x800BCD24
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCD24;
        }
    }

label_800BCC0C:
    ctx->pc = 0x800BCC0Cu;
    ctx->downcount -= 3;
    // 800BCC0C: lwz     r0, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCC10:
    ctx->pc = 0x800BCC10u;
    // 800BCC10: cmpwi   r0, 0
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

label_800BCC14:
    ctx->pc = 0x800BCC14u;
    // 800BCC14: bc    4, 2, 0x800BCCFC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCCFC;
        }
    }

label_800BCC18:
    ctx->pc = 0x800BCC18u;
    ctx->downcount -= 29;
    // 800BCC18: lwz     r11, 1432(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BCC1C:
    ctx->pc = 0x800BCC1Cu;
    // 800BCC1C: addi    r9, r31, 1432
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(1432);

label_800BCC20:
    ctx->pc = 0x800BCC20u;
    // 800BCC20: lwz     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BCC24:
    ctx->pc = 0x800BCC24u;
    // 800BCC24: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_800BCC28:
    ctx->pc = 0x800BCC28u;
    // 800BCC28: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCC2C:
    ctx->pc = 0x800BCC2Cu;
    // 800BCC2C: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BCC30:
    ctx->pc = 0x800BCC30u;
    // 800BCC30: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCC34:
    ctx->pc = 0x800BCC34u;
    // 800BCC34: addi    r30, r1, 24
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(24);

label_800BCC38:
    ctx->pc = 0x800BCC38u;
    // 800BCC38: stw     r8, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BCC3C:
    ctx->pc = 0x800BCC3Cu;
    // 800BCC3C: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BCC40:
    ctx->pc = 0x800BCC40u;
    // 800BCC40: stw     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCC44:
    ctx->pc = 0x800BCC44u;
    // 800BCC44: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BCC48:
    ctx->pc = 0x800BCC48u;
    // 800BCC48: lfs     f13, -16004(r10)
    if (!ppc_fp_available(ctx, 0x800BCC48u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-16004);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BCC4C:
    ctx->pc = 0x800BCC4Cu;
    // 800BCC4C: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCC50:
    ctx->pc = 0x800BCC50u;
    // 800BCC50: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BCC50u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BCC54:
    ctx->pc = 0x800BCC54u;
    // 800BCC54: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BCC58:
    ctx->pc = 0x800BCC58u;
    // 800BCC58: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_800BCC5C:
    ctx->pc = 0x800BCC5Cu;
    // 800BCC5C: li      r5, 3885
    ctx->gpr[5] = (u32)(s32)(3885);

label_800BCC60:
    ctx->pc = 0x800BCC60u;
    // 800BCC60: fadds   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BCC60u)) return;
    ppc_fadds(ctx, 0, 0, 13);

label_800BCC64:
    ctx->pc = 0x800BCC64u;
    // 800BCC64: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BCC68:
    ctx->pc = 0x800BCC68u;
    // 800BCC68: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BCC68u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BCC6C:
    ctx->pc = 0x800BCC6Cu;
    // 800BCC6C: li      r7, 250
    ctx->gpr[7] = (u32)(s32)(250);

label_800BCC70:
    ctx->pc = 0x800BCC70u;
    // 800BCC70: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BCC74:
    ctx->pc = 0x800BCC74u;
    // 800BCC74: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCC78:
    ctx->pc = 0x800BCC78u;
    // 800BCC78: lwz     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BCC7C:
    ctx->pc = 0x800BCC7Cu;
    // 800BCC7C: stw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_800BCC80:
    ctx->pc = 0x800BCC80u;
    // 800BCC80: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCC84:
    ctx->pc = 0x800BCC84u;
    // 800BCC84: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCC88:
    ctx->pc = 0x800BCC88u;
    // 800BCC88: bl      0x800C3D88
    {
            ctx->lr = 0x800BCC8Cu;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BCC8C:
    ctx->pc = 0x800BCC8Cu;
    ctx->downcount -= 28;
    // 800BCC8C: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_800BCC90:
    ctx->pc = 0x800BCC90u;
    // 800BCC90: stw     r3, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BCC94:
    ctx->pc = 0x800BCC94u;
    // 800BCC94: lis     r0, 17200
    ctx->gpr[0] = ((u32)(s32)(17200) << 16);

label_800BCC98:
    ctx->pc = 0x800BCC98u;
    // 800BCC98: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BCC9C:
    ctx->pc = 0x800BCC9Cu;
    // 800BCC9C: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BCCA0:
    ctx->pc = 0x800BCCA0u;
    // 800BCCA0: stw     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCCA4:
    ctx->pc = 0x800BCCA4u;
    // 800BCCA4: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCCA8:
    ctx->pc = 0x800BCCA8u;
    // 800BCCA8: lfd     f13, -16000(r11)
    if (!ppc_fp_available(ctx, 0x800BCCA8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-16000);
        ctx->fpr[13] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BCCAC:
    ctx->pc = 0x800BCCACu;
    // 800BCCAC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BCCB0:
    ctx->pc = 0x800BCCB0u;
    // 800BCCB0: lfd     f0, 40(r1)
    if (!ppc_fp_available(ctx, 0x800BCCB0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BCCB4:
    ctx->pc = 0x800BCCB4u;
    // 800BCCB4: li      r5, 3886
    ctx->gpr[5] = (u32)(s32)(3886);

label_800BCCB8:
    ctx->pc = 0x800BCCB8u;
    // 800BCCB8: lfs     f12, -15992(r10)
    if (!ppc_fp_available(ctx, 0x800BCCB8u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-15992);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[12] = value;
        ctx->ps1[12] = value;
    }

label_800BCCBC:
    ctx->pc = 0x800BCCBCu;
    // 800BCCBC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BCCC0:
    ctx->pc = 0x800BCCC0u;
    // 800BCCC0: fsub   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BCCC0u)) return;
    ppc_fsub(ctx, 0, 0, 13);

label_800BCCC4:
    ctx->pc = 0x800BCCC4u;
    // 800BCCC4: lwz     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_800BCCC8:
    ctx->pc = 0x800BCCC8u;
    // 800BCCC8: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x800BCCC8u)) return;
    ppc_frsp(ctx, 0, 0);

label_800BCCCC:
    ctx->pc = 0x800BCCCCu;
    // 800BCCCC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BCCD0:
    ctx->pc = 0x800BCCD0u;
    // 800BCCD0: fadds   f0, f0, f12
    if (!ppc_fp_available(ctx, 0x800BCCD0u)) return;
    ppc_fadds(ctx, 0, 0, 12);

label_800BCCD4:
    ctx->pc = 0x800BCCD4u;
    // 800BCCD4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BCCD8:
    ctx->pc = 0x800BCCD8u;
    // 800BCCD8: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BCCD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BCCDC:
    ctx->pc = 0x800BCCDCu;
    // 800BCCDC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BCCE0:
    ctx->pc = 0x800BCCE0u;
    // 800BCCE0: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BCCE4:
    ctx->pc = 0x800BCCE4u;
    // 800BCCE4: lwz     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BCCE8:
    ctx->pc = 0x800BCCE8u;
    // 800BCCE8: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCCEC:
    ctx->pc = 0x800BCCECu;
    // 800BCCEC: stw     r28, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_800BCCF0:
    ctx->pc = 0x800BCCF0u;
    // 800BCCF0: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCCF4:
    ctx->pc = 0x800BCCF4u;
    // 800BCCF4: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCCF8:
    ctx->pc = 0x800BCCF8u;
    // 800BCCF8: bl      0x800C3D88
    {
            ctx->lr = 0x800BCCFCu;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BCCFC:
    ctx->pc = 0x800BCCFCu;
    ctx->downcount -= 5;
    // 800BCCFC: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCD00:
    ctx->pc = 0x800BCD00u;
    // 800BCD00: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BCD04:
    ctx->pc = 0x800BCD04u;
    // 800BCD04: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCD08:
    ctx->pc = 0x800BCD08u;
    // 800BCD08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BCD0C:
    ctx->pc = 0x800BCD0Cu;
    // 800BCD0C: bl      0x800C1D34
    {
            ctx->lr = 0x800BCD10u;
            ctx->pc = 0x800C1D34u;
            return;
    }

label_800BCD10:
    ctx->pc = 0x800BCD10u;
    ctx->downcount -= 5;
    // 800BCD10: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCD14:
    ctx->pc = 0x800BCD14u;
    // 800BCD14: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCD18:
    ctx->pc = 0x800BCD18u;
    // 800BCD18: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BCD1C:
    ctx->pc = 0x800BCD1Cu;
    // 800BCD1C: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BCD20:
    ctx->pc = 0x800BCD20u;
    // 800BCD20: bl      0x800C1D34
    {
            ctx->lr = 0x800BCD24u;
            ctx->pc = 0x800C1D34u;
            return;
    }

label_800BCD24:
    ctx->pc = 0x800BCD24u;
    ctx->downcount -= 16;
    // 800BCD24: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCD28:
    ctx->pc = 0x800BCD28u;
    // 800BCD28: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BCD2C:
    ctx->pc = 0x800BCD2Cu;
    // 800BCD2C: lmw     r28, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BCD30:
    ctx->pc = 0x800BCD30u;
    // 800BCD30: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_800BCD34:
    ctx->pc = 0x800BCD34u;
    // 800BCD34: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BCD38:
    ctx->pc = 0x800BCD38u;
    ctx->downcount -= 5;
    // 800BCD38: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BCD3C:
    ctx->pc = 0x800BCD3Cu;
    // 800BCD3C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BCD40:
    ctx->pc = 0x800BCD40u;
    // 800BCD40: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCD44:
    ctx->pc = 0x800BCD44u;
    // 800BCD44: cmpwi   r4, 0
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

label_800BCD48:
    ctx->pc = 0x800BCD48u;
    // 800BCD48: bc    4, 2, 0x800BCD54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCD54;
        }
    }

label_800BCD4C:
    ctx->pc = 0x800BCD4Cu;
    ctx->downcount -= 2;
    // 800BCD4C: li      r3, 465
    ctx->gpr[3] = (u32)(s32)(465);

label_800BCD50:
    ctx->pc = 0x800BCD50u;
    // 800BCD50: bl      0x8005B3F8
    {
            ctx->lr = 0x800BCD54u;
            ctx->pc = 0x8005B3F8u;
            return;
    }

label_800BCD54:
    ctx->pc = 0x800BCD54u;
    ctx->downcount -= 5;
    // 800BCD54: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCD58:
    ctx->pc = 0x800BCD58u;
    // 800BCD58: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BCD5C:
    ctx->pc = 0x800BCD5Cu;
    // 800BCD5C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BCD60:
    ctx->pc = 0x800BCD60u;
    // 800BCD60: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BCD64:
    ctx->pc = 0x800BCD64u;
    ctx->downcount -= 16;
    // 800BCD64: stwu     r1, -112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-112);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BCD68:
    ctx->pc = 0x800BCD68u;
    // 800BCD68: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BCD6C:
    ctx->pc = 0x800BCD6Cu;
    // 800BCD6C: stmw     r27, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BCD70:
    ctx->pc = 0x800BCD70u;
    // 800BCD70: stw     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCD74:
    ctx->pc = 0x800BCD74u;
    // 800BCD74: or.   r31, r3, r3
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

label_800BCD78:
    ctx->pc = 0x800BCD78u;
    // 800BCD78: bc    12, 2, 0x800BCFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCFA0;
        }
    }

label_800BCD7C:
    ctx->pc = 0x800BCD7Cu;
    ctx->downcount -= 4;
    // 800BCD7C: lwz     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BCD80:
    ctx->pc = 0x800BCD80u;
    // 800BCD80: lis     r4, 20992
    ctx->gpr[4] = ((u32)(s32)(20992) << 16);

label_800BCD84:
    ctx->pc = 0x800BCD84u;
    // 800BCD84: ori     r4, r4, 0x0129
    ctx->gpr[4] = ctx->gpr[4] | 0x0129u;

label_800BCD88:
    ctx->pc = 0x800BCD88u;
    // 800BCD88: bl      0x80047634
    {
            ctx->lr = 0x800BCD8Cu;
            ctx->pc = 0x80047634u;
            return;
    }

label_800BCD8C:
    ctx->pc = 0x800BCD8Cu;
    ctx->downcount -= 2;
    // 800BCD8C: or.   r29, r3, r3
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

label_800BCD90:
    ctx->pc = 0x800BCD90u;
    // 800BCD90: bc    12, 2, 0x800BCFA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCFA0;
        }
    }

label_800BCD94:
    ctx->pc = 0x800BCD94u;
    ctx->downcount -= 7;
    // 800BCD94: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BCD98:
    ctx->pc = 0x800BCD98u;
    // 800BCD98: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCD9C:
    ctx->pc = 0x800BCD9Cu;
    // 800BCD9C: ori     r4, r4, 0x00B7
    ctx->gpr[4] = ctx->gpr[4] | 0x00B7u;

label_800BCDA0:
    ctx->pc = 0x800BCDA0u;
    // 800BCDA0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BCDA4:
    ctx->pc = 0x800BCDA4u;
    // 800BCDA4: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_800BCDA8:
    ctx->pc = 0x800BCDA8u;
    // 800BCDA8: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BCDAC:
    ctx->pc = 0x800BCDACu;
    // 800BCDAC: bl      0x800303A8
    {
            ctx->lr = 0x800BCDB0u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BCDB0:
    ctx->pc = 0x800BCDB0u;
    ctx->downcount -= 3;
    // 800BCDB0: addi    r27, r1, 8
    ctx->gpr[27] = ctx->gpr[1] + (u32)(s32)(8);

label_800BCDB4:
    ctx->pc = 0x800BCDB4u;
    // 800BCDB4: cmpwi   r3, 0
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

label_800BCDB8:
    ctx->pc = 0x800BCDB8u;
    // 800BCDB8: bc    12, 2, 0x800BCE14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCE14;
        }
    }

label_800BCDBC:
    ctx->pc = 0x800BCDBCu;
    ctx->downcount -= 6;
    // 800BCDBC: addi    r30, r1, 40
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(40);

label_800BCDC0:
    ctx->pc = 0x800BCDC0u;
    // 800BCDC0: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BCDC4:
    ctx->pc = 0x800BCDC4u;
    // 800BCDC4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCDC8:
    ctx->pc = 0x800BCDC8u;
    // 800BCDC8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BCDCC:
    ctx->pc = 0x800BCDCCu;
    // 800BCDCC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BCDD0:
    ctx->pc = 0x800BCDD0u;
    // 800BCDD0: bl      0x800C48AC
    {
            ctx->lr = 0x800BCDD4u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BCDD4:
    ctx->pc = 0x800BCDD4u;
    ctx->downcount -= 16;
    // 800BCDD4: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCDD8:
    ctx->pc = 0x800BCDD8u;
    // 800BCDD8: addi    r8, r31, 1432
    ctx->gpr[8] = ctx->gpr[31] + (u32)(s32)(1432);

label_800BCDDC:
    ctx->pc = 0x800BCDDCu;
    // 800BCDDC: lwz     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BCDE0:
    ctx->pc = 0x800BCDE0u;
    // 800BCDE0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BCDE4:
    ctx->pc = 0x800BCDE4u;
    // 800BCDE4: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BCDE8:
    ctx->pc = 0x800BCDE8u;
    // 800BCDE8: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCDEC:
    ctx->pc = 0x800BCDECu;
    // 800BCDEC: stw     r11, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCDF0:
    ctx->pc = 0x800BCDF0u;
    // 800BCDF0: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BCDF4:
    ctx->pc = 0x800BCDF4u;
    // 800BCDF4: lfs     f13, -15988(r9)
    if (!ppc_fp_available(ctx, 0x800BCDF4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15988);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BCDF8:
    ctx->pc = 0x800BCDF8u;
    // 800BCDF8: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCDFC:
    ctx->pc = 0x800BCDFCu;
    // 800BCDFC: stw     r0, 1432(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCE00:
    ctx->pc = 0x800BCE00u;
    // 800BCE00: stw     r10, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BCE04:
    ctx->pc = 0x800BCE04u;
    // 800BCE04: stw     r11, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCE08:
    ctx->pc = 0x800BCE08u;
    // 800BCE08: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BCE08u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BCE0C:
    ctx->pc = 0x800BCE0Cu;
    // 800BCE0C: fadds   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BCE0Cu)) return;
    ppc_fadds(ctx, 0, 0, 13);

label_800BCE10:
    ctx->pc = 0x800BCE10u;
    // 800BCE10: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BCE10u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BCE14:
    ctx->pc = 0x800BCE14u;
    ctx->downcount -= 8;
    // 800BCE14: addi    r28, r1, 24
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(24);

label_800BCE18:
    ctx->pc = 0x800BCE18u;
    // 800BCE18: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BCE1C:
    ctx->pc = 0x800BCE1Cu;
    // 800BCE1C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCE20:
    ctx->pc = 0x800BCE20u;
    // 800BCE20: ori     r4, r4, 0x00BB
    ctx->gpr[4] = ctx->gpr[4] | 0x00BBu;

label_800BCE24:
    ctx->pc = 0x800BCE24u;
    // 800BCE24: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BCE28:
    ctx->pc = 0x800BCE28u;
    // 800BCE28: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BCE2C:
    ctx->pc = 0x800BCE2Cu;
    // 800BCE2C: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BCE30:
    ctx->pc = 0x800BCE30u;
    // 800BCE30: bl      0x800303A8
    {
            ctx->lr = 0x800BCE34u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BCE34:
    ctx->pc = 0x800BCE34u;
    ctx->downcount -= 2;
    // 800BCE34: cmpwi   r3, 0
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

label_800BCE38:
    ctx->pc = 0x800BCE38u;
    // 800BCE38: bc    12, 2, 0x800BCE94
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCE94;
        }
    }

label_800BCE3C:
    ctx->pc = 0x800BCE3Cu;
    ctx->downcount -= 6;
    // 800BCE3C: addi    r30, r1, 40
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(40);

label_800BCE40:
    ctx->pc = 0x800BCE40u;
    // 800BCE40: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BCE44:
    ctx->pc = 0x800BCE44u;
    // 800BCE44: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BCE48:
    ctx->pc = 0x800BCE48u;
    // 800BCE48: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BCE4C:
    ctx->pc = 0x800BCE4Cu;
    // 800BCE4C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BCE50:
    ctx->pc = 0x800BCE50u;
    // 800BCE50: bl      0x800C48AC
    {
            ctx->lr = 0x800BCE54u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BCE54:
    ctx->pc = 0x800BCE54u;
    ctx->downcount -= 16;
    // 800BCE54: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCE58:
    ctx->pc = 0x800BCE58u;
    // 800BCE58: addi    r8, r31, 1444
    ctx->gpr[8] = ctx->gpr[31] + (u32)(s32)(1444);

label_800BCE5C:
    ctx->pc = 0x800BCE5Cu;
    // 800BCE5C: lwz     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BCE60:
    ctx->pc = 0x800BCE60u;
    // 800BCE60: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BCE64:
    ctx->pc = 0x800BCE64u;
    // 800BCE64: lwz     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BCE68:
    ctx->pc = 0x800BCE68u;
    // 800BCE68: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCE6C:
    ctx->pc = 0x800BCE6Cu;
    // 800BCE6C: stw     r11, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCE70:
    ctx->pc = 0x800BCE70u;
    // 800BCE70: stw     r10, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BCE74:
    ctx->pc = 0x800BCE74u;
    // 800BCE74: lfs     f13, -15988(r9)
    if (!ppc_fp_available(ctx, 0x800BCE74u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15988);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BCE78:
    ctx->pc = 0x800BCE78u;
    // 800BCE78: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCE7C:
    ctx->pc = 0x800BCE7Cu;
    // 800BCE7C: stw     r0, 1444(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1444);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCE80:
    ctx->pc = 0x800BCE80u;
    // 800BCE80: stw     r10, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BCE84:
    ctx->pc = 0x800BCE84u;
    // 800BCE84: stw     r11, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCE88:
    ctx->pc = 0x800BCE88u;
    // 800BCE88: lfs     f0, 28(r1)
    if (!ppc_fp_available(ctx, 0x800BCE88u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BCE8C:
    ctx->pc = 0x800BCE8Cu;
    // 800BCE8C: fadds   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BCE8Cu)) return;
    ppc_fadds(ctx, 0, 0, 13);

label_800BCE90:
    ctx->pc = 0x800BCE90u;
    // 800BCE90: stfs     f0, 28(r1)
    if (!ppc_fp_available(ctx, 0x800BCE90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BCE94:
    ctx->pc = 0x800BCE94u;
    ctx->downcount -= 5;
    // 800BCE94: addi    r29, r31, 3720
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BCE98:
    ctx->pc = 0x800BCE98u;
    // 800BCE98: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_800BCE9C:
    ctx->pc = 0x800BCE9Cu;
    // 800BCE9C: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCEA0:
    ctx->pc = 0x800BCEA0u;
    // 800BCEA0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCEA4:
    ctx->pc = 0x800BCEA4u;
    // 800BCEA4: bl      0x800C13B0
    {
            ctx->lr = 0x800BCEA8u;
            ctx->pc = 0x800C13B0u;
            return;
    }

label_800BCEA8:
    ctx->pc = 0x800BCEA8u;
    ctx->downcount -= 4;
    // 800BCEA8: li      r4, 240
    ctx->gpr[4] = (u32)(s32)(240);

label_800BCEAC:
    ctx->pc = 0x800BCEACu;
    // 800BCEAC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCEB0:
    ctx->pc = 0x800BCEB0u;
    // 800BCEB0: li      r5, 240
    ctx->gpr[5] = (u32)(s32)(240);

label_800BCEB4:
    ctx->pc = 0x800BCEB4u;
    // 800BCEB4: bl      0x800C1484
    {
            ctx->lr = 0x800BCEB8u;
            ctx->pc = 0x800C1484u;
            return;
    }

label_800BCEB8:
    ctx->pc = 0x800BCEB8u;
    ctx->downcount -= 20;
    // 800BCEB8: lwz     r10, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BCEBC:
    ctx->pc = 0x800BCEBCu;
    // 800BCEBC: addi    r9, r1, 56
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(56);

label_800BCEC0:
    ctx->pc = 0x800BCEC0u;
    // 800BCEC0: lwz     r8, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BCEC4:
    ctx->pc = 0x800BCEC4u;
    // 800BCEC4: or   r5, r9, r9
    {
        ctx->gpr[5] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BCEC8:
    ctx->pc = 0x800BCEC8u;
    // 800BCEC8: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCECC:
    ctx->pc = 0x800BCECCu;
    // 800BCECC: addi    r11, r1, 72
    ctx->gpr[11] = ctx->gpr[1] + (u32)(s32)(72);

label_800BCED0:
    ctx->pc = 0x800BCED0u;
    // 800BCED0: stw     r10, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BCED4:
    ctx->pc = 0x800BCED4u;
    // 800BCED4: lis     r4, -32734
    ctx->gpr[4] = ((u32)(s32)(-32734) << 16);

label_800BCED8:
    ctx->pc = 0x800BCED8u;
    // 800BCED8: stw     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BCEDC:
    ctx->pc = 0x800BCEDCu;
    // 800BCEDC: or   r6, r11, r11
    {
        ctx->gpr[6] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BCEE0:
    ctx->pc = 0x800BCEE0u;
    // 800BCEE0: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCEE4:
    ctx->pc = 0x800BCEE4u;
    // 800BCEE4: addi    r4, r4, -5084
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(-5084);

label_800BCEE8:
    ctx->pc = 0x800BCEE8u;
    // 800BCEE8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCEEC:
    ctx->pc = 0x800BCEECu;
    // 800BCEEC: lwz     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BCEF0:
    ctx->pc = 0x800BCEF0u;
    // 800BCEF0: lwz     r10, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BCEF4:
    ctx->pc = 0x800BCEF4u;
    // 800BCEF4: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCEF8:
    ctx->pc = 0x800BCEF8u;
    // 800BCEF8: stw     r9, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BCEFC:
    ctx->pc = 0x800BCEFCu;
    // 800BCEFC: stw     r0, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCF00:
    ctx->pc = 0x800BCF00u;
    // 800BCF00: stw     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BCF04:
    ctx->pc = 0x800BCF04u;
    // 800BCF04: bl      0x800C14A8
    {
            ctx->lr = 0x800BCF08u;
            ctx->pc = 0x800C14A8u;
            return;
    }

label_800BCF08:
    ctx->pc = 0x800BCF08u;
    ctx->downcount -= 10;
    // 800BCF08: lwz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCF0C:
    ctx->pc = 0x800BCF0Cu;
    // 800BCF0C: lis     r30, -32734
    ctx->gpr[30] = ((u32)(s32)(-32734) << 16);

label_800BCF10:
    ctx->pc = 0x800BCF10u;
    // 800BCF10: addi    r30, r30, -3500
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-3500);

label_800BCF14:
    ctx->pc = 0x800BCF14u;
    // 800BCF14: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCF18:
    ctx->pc = 0x800BCF18u;
    // 800BCF18: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_800BCF1C:
    ctx->pc = 0x800BCF1Cu;
    // 800BCF1C: addi    r30, r30, 8
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(8);

label_800BCF20:
    ctx->pc = 0x800BCF20u;
    // 800BCF20: lwzx    r4, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCF24:
    ctx->pc = 0x800BCF24u;
    // 800BCF24: bl      0x800C2088
    {
            ctx->lr = 0x800BCF28u;
            ctx->pc = 0x800C2088u;
            return;
    }

label_800BCF28:
    ctx->pc = 0x800BCF28u;
    ctx->downcount -= 11;
    // 800BCF28: lwz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCF2C:
    ctx->pc = 0x800BCF2Cu;
    // 800BCF2C: or   r9, r3, r3
    {
        ctx->gpr[9] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BCF30:
    ctx->pc = 0x800BCF30u;
    // 800BCF30: stw     r9, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BCF34:
    ctx->pc = 0x800BCF34u;
    // 800BCF34: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCF38:
    ctx->pc = 0x800BCF38u;
    // 800BCF38: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_800BCF3C:
    ctx->pc = 0x800BCF3Cu;
    // 800BCF3C: stw     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BCF40:
    ctx->pc = 0x800BCF40u;
    // 800BCF40: lwzx    r4, r30, r0
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCF44:
    ctx->pc = 0x800BCF44u;
    // 800BCF44: addi    r4, r4, 1
    ctx->gpr[4] = ctx->gpr[4] + (u32)(s32)(1);

label_800BCF48:
    ctx->pc = 0x800BCF48u;
    // 800BCF48: bl      0x800C2088
    {
            ctx->lr = 0x800BCF4Cu;
            ctx->pc = 0x800C2088u;
            return;
    }

label_800BCF4C:
    ctx->pc = 0x800BCF4Cu;
    ctx->downcount -= 3;
    // 800BCF4C: cmpwi   r3, -1
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

label_800BCF50:
    ctx->pc = 0x800BCF50u;
    // 800BCF50: stw     r3, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BCF54:
    ctx->pc = 0x800BCF54u;
    // 800BCF54: bc    4, 2, 0x800BCF60
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCF60;
        }
    }

label_800BCF58:
    ctx->pc = 0x800BCF58u;
    ctx->downcount -= 2;
    // 800BCF58: lwz     r0, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCF5C:
    ctx->pc = 0x800BCF5Cu;
    // 800BCF5C: stw     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCF60:
    ctx->pc = 0x800BCF60u;
    ctx->downcount -= 3;
    // 800BCF60: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BCF64:
    ctx->pc = 0x800BCF64u;
    // 800BCF64: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCF68:
    ctx->pc = 0x800BCF68u;
    // 800BCF68: bl      0x800C1AB0
    {
            ctx->lr = 0x800BCF6Cu;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BCF6C:
    ctx->pc = 0x800BCF6Cu;
    ctx->downcount -= 5;
    // 800BCF6C: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BCF70:
    ctx->pc = 0x800BCF70u;
    // 800BCF70: lwz     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCF74:
    ctx->pc = 0x800BCF74u;
    // 800BCF74: addi    r4, r9, 1
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(1);

label_800BCF78:
    ctx->pc = 0x800BCF78u;
    // 800BCF78: cmpw    r4, r0
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

label_800BCF7C:
    ctx->pc = 0x800BCF7Cu;
    // 800BCF7C: bc    4, 0, 0x800BCF88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BCF88;
        }
    }

label_800BCF80:
    ctx->pc = 0x800BCF80u;
    ctx->downcount -= 2;
    // 800BCF80: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BCF84:
    ctx->pc = 0x800BCF84u;
    // 800BCF84: bl      0x800C1AB0
    {
            ctx->lr = 0x800BCF88u;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BCF88:
    ctx->pc = 0x800BCF88u;
    ctx->downcount -= 6;
    // 800BCF88: lwz     r9, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BCF8C:
    ctx->pc = 0x800BCF8Cu;
    // 800BCF8C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800BCF90:
    ctx->pc = 0x800BCF90u;
    // 800BCF90: lwz     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCF94:
    ctx->pc = 0x800BCF94u;
    // 800BCF94: subf   r0, r9, r0
    {
        u32 a = ~ctx->gpr[9];
        u32 b = ctx->gpr[0];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800BCF98:
    ctx->pc = 0x800BCF98u;
    // 800BCF98: cmpwi   r0, 2
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

label_800BCF9C:
    ctx->pc = 0x800BCF9Cu;
    // 800BCF9C: bc    12, 1, 0x800BCFA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BCFA4;
        }
    }

label_800BCFA0:
    ctx->pc = 0x800BCFA0u;
    ctx->downcount -= 1;
    // 800BCFA0: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BCFA4:
    ctx->pc = 0x800BCFA4u;
    ctx->downcount -= 16;
    // 800BCFA4: lwz     r0, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCFA8:
    ctx->pc = 0x800BCFA8u;
    // 800BCFA8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BCFAC:
    ctx->pc = 0x800BCFACu;
    // 800BCFAC: lmw     r27, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BCFB0:
    ctx->pc = 0x800BCFB0u;
    // 800BCFB0: addi    r1, r1, 112
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(112);

label_800BCFB4:
    ctx->pc = 0x800BCFB4u;
    // 800BCFB4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BCFB8:
    ctx->pc = 0x800BCFB8u;
    ctx->downcount -= 5;
    // 800BCFB8: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BCFBC:
    ctx->pc = 0x800BCFBCu;
    // 800BCFBC: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BCFC0:
    ctx->pc = 0x800BCFC0u;
    // 800BCFC0: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCFC4:
    ctx->pc = 0x800BCFC4u;
    // 800BCFC4: addi    r3, r3, 3720
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(3720);

label_800BCFC8:
    ctx->pc = 0x800BCFC8u;
    // 800BCFC8: bl      0x800C1A00
    {
            ctx->lr = 0x800BCFCCu;
            ctx->pc = 0x800C1A00u;
            return;
    }

label_800BCFCC:
    ctx->pc = 0x800BCFCCu;
    ctx->downcount -= 5;
    // 800BCFCC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BCFD0:
    ctx->pc = 0x800BCFD0u;
    // 800BCFD0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BCFD4:
    ctx->pc = 0x800BCFD4u;
    // 800BCFD4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BCFD8:
    ctx->pc = 0x800BCFD8u;
    // 800BCFD8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BCFDC:
    ctx->pc = 0x800BCFDCu;
    ctx->downcount -= 3;
    // 800BCFDC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800BCFE0:
    ctx->pc = 0x800BCFE0u;
    // 800BCFE0: or.   r3, r3, r3
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

label_800BCFE4:
    ctx->pc = 0x800BCFE4u;
    // 800BCFE4: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BCFE8:
    ctx->pc = 0x800BCFE8u;
    ctx->downcount -= 6;
    // 800BCFE8: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_800BCFEC:
    ctx->pc = 0x800BCFECu;
    // 800BCFEC: li      r11, 5
    ctx->gpr[11] = (u32)(s32)(5);

label_800BCFF0:
    ctx->pc = 0x800BCFF0u;
    // 800BCFF0: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BCFF4:
    ctx->pc = 0x800BCFF4u;
    // 800BCFF4: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BCFF8:
    ctx->pc = 0x800BCFF8u;
    // 800BCFF8: stw     r11, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BCFFC:
    ctx->pc = 0x800BCFFCu;
    // 800BCFFC: lwz     r0, -3500(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-3500);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD000:
    ctx->downcount -= 2;
    // 800BD000: cmpwi   r0, -1
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

label_800BD004:
    ctx->pc = 0x800BD004u;
    // 800BD004: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD008:
    ctx->downcount -= 2;
    // 800BD008: cmpw    r0, r4
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[4]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BD00C:
    // 800BD00C: bc    4, 2, 0x800BD018
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD018;
        }
    }

label_800BD010:
    ctx->pc = 0x800BD010u;
    ctx->downcount -= 2;
    // 800BD010: stw     r10, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BD014:
    ctx->pc = 0x800BD014u;
    // 800BD014: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD018:
    ctx->downcount -= 8;
    // 800BD018: addi    r10, r10, 1
    ctx->gpr[10] = ctx->gpr[10] + (u32)(s32)(1);

label_800BD01C:
    // 800BD01C: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BD020:
    // 800BD020: mulli   r0, r10, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[10] * (s64)(s32)12);

label_800BD024:
    // 800BD024: addi    r9, r9, -3500
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-3500);

label_800BD028:
    ctx->pc = 0x800BD028u;
    // 800BD028: lwzx    r0, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD02C:
    // 800BD02C: b       0x800BD000
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BD000u;
                return;
            }
            goto label_800BD000;
    }

label_800BD030:
    ctx->pc = 0x800BD030u;
    ctx->downcount -= 19;
    // 800BD030: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BD034:
    ctx->pc = 0x800BD034u;
    // 800BD034: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BD038:
    ctx->pc = 0x800BD038u;
    // 800BD038: stfd     f31, 40(r1)
    if (!ppc_fp_available(ctx, 0x800BD038u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800BD03C:
    ctx->pc = 0x800BD03Cu;
    // 800BD03C: stmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BD040:
    ctx->pc = 0x800BD040u;
    // 800BD040: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD044:
    ctx->pc = 0x800BD044u;
    // 800BD044: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BD048:
    ctx->pc = 0x800BD048u;
    // 800BD048: lwz     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD04C:
    ctx->pc = 0x800BD04Cu;
    // 800BD04C: cmpwi   r0, 14
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

label_800BD050:
    ctx->pc = 0x800BD050u;
    // 800BD050: bc    12, 2, 0x800BD060
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD060;
        }
    }

label_800BD054:
    ctx->pc = 0x800BD054u;
    ctx->downcount -= 2;
    // 800BD054: cmpwi   r0, 17
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

label_800BD058:
    ctx->pc = 0x800BD058u;
    // 800BD058: bc    12, 2, 0x800BD208
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD208;
        }
    }

label_800BD05C:
    ctx->pc = 0x800BD05Cu;
    ctx->downcount -= 1;
    // 800BD05C: b       0x800BD248
    {
            goto label_800BD248;
    }

label_800BD060:
    ctx->pc = 0x800BD060u;
    ctx->downcount -= 5;
    // 800BD060: lwz     r8, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BD064:
    ctx->pc = 0x800BD064u;
    // 800BD064: lwz     r10, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BD068:
    ctx->pc = 0x800BD068u;
    // 800BD068: subf   r0, r10, r8
    {
        u32 a = ~ctx->gpr[10];
        u32 b = ctx->gpr[8];
        u32 res = a + b + 1u;
        ctx->gpr[0] = res;
    }

label_800BD06C:
    ctx->pc = 0x800BD06Cu;
    // 800BD06C: cmpwi   r0, 2
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

label_800BD070:
    ctx->pc = 0x800BD070u;
    // 800BD070: bc    4, 1, 0x800BD134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD134;
        }
    }

label_800BD074:
    ctx->pc = 0x800BD074u;
    ctx->downcount -= 8;
    // 800BD074: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BD078:
    ctx->pc = 0x800BD078u;
    // 800BD078: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BD07C:
    ctx->pc = 0x800BD07Cu;
    // 800BD07C: lwz     r11, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD080:
    ctx->pc = 0x800BD080u;
    // 800BD080: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD084:
    ctx->pc = 0x800BD084u;
    // 800BD084: xor   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[11];
    }

label_800BD088:
    ctx->pc = 0x800BD088u;
    // 800BD088: rlwinm r9, r0, 0, 23, 23
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000100u;
    }

label_800BD08C:
    ctx->pc = 0x800BD08Cu;
    // 800BD08C: and.   r7, r9, r11
    {
        ctx->gpr[7] = ctx->gpr[9] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD090:
    ctx->pc = 0x800BD090u;
    // 800BD090: bc    12, 2, 0x800BD0DC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD0DC;
        }
    }

label_800BD094:
    ctx->pc = 0x800BD094u;
    ctx->downcount -= 3;
    // 800BD094: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BD098:
    ctx->pc = 0x800BD098u;
    // 800BD098: cmpw    r4, r10
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

label_800BD09C:
    ctx->pc = 0x800BD09Cu;
    // 800BD09C: bc    4, 1, 0x800BD134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD134;
        }
    }

label_800BD0A0:
    ctx->pc = 0x800BD0A0u;
    ctx->downcount -= 3;
    // 800BD0A0: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BD0A4:
    ctx->pc = 0x800BD0A4u;
    // 800BD0A4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD0A8:
    ctx->pc = 0x800BD0A8u;
    // 800BD0A8: bl      0x800C1F74
    {
            ctx->lr = 0x800BD0ACu;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BD0AC:
    ctx->pc = 0x800BD0ACu;
    ctx->downcount -= 5;
    // 800BD0AC: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD0B0:
    ctx->pc = 0x800BD0B0u;
    // 800BD0B0: lwz     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD0B4:
    ctx->pc = 0x800BD0B4u;
    // 800BD0B4: addi    r4, r9, 1
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(1);

label_800BD0B8:
    ctx->pc = 0x800BD0B8u;
    // 800BD0B8: cmpw    r4, r0
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

label_800BD0BC:
    ctx->pc = 0x800BD0BCu;
    // 800BD0BC: bc    4, 0, 0x800BD0C8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD0C8;
        }
    }

label_800BD0C0:
    ctx->pc = 0x800BD0C0u;
    ctx->downcount -= 2;
    // 800BD0C0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD0C4:
    ctx->pc = 0x800BD0C4u;
    // 800BD0C4: bl      0x800C1F74
    {
            ctx->lr = 0x800BD0C8u;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BD0C8:
    ctx->pc = 0x800BD0C8u;
    ctx->downcount -= 5;
    // 800BD0C8: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD0CC:
    ctx->pc = 0x800BD0CCu;
    // 800BD0CC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_800BD0D0:
    ctx->pc = 0x800BD0D0u;
    // 800BD0D0: stw     r0, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD0D4:
    ctx->pc = 0x800BD0D4u;
    // 800BD0D4: addi    r9, r9, -2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2);

label_800BD0D8:
    ctx->pc = 0x800BD0D8u;
    // 800BD0D8: b       0x800BD130
    {
            goto label_800BD130;
    }

label_800BD0DC:
    ctx->pc = 0x800BD0DCu;
    ctx->downcount -= 3;
    // 800BD0DC: rlwinm r0, r0, 0, 22, 22
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 0u) & 0x00000200u;
    }

label_800BD0E0:
    ctx->pc = 0x800BD0E0u;
    // 800BD0E0: and.   r7, r0, r11
    {
        ctx->gpr[7] = ctx->gpr[0] & ctx->gpr[11];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[7];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD0E4:
    ctx->pc = 0x800BD0E4u;
    // 800BD0E4: bc    12, 2, 0x800BD134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD134;
        }
    }

label_800BD0E8:
    ctx->pc = 0x800BD0E8u;
    ctx->downcount -= 4;
    // 800BD0E8: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BD0EC:
    ctx->pc = 0x800BD0ECu;
    // 800BD0EC: addi    r0, r4, 2
    ctx->gpr[0] = ctx->gpr[4] + (u32)(s32)(2);

label_800BD0F0:
    ctx->pc = 0x800BD0F0u;
    // 800BD0F0: cmpw    r0, r8
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

label_800BD0F4:
    ctx->pc = 0x800BD0F4u;
    // 800BD0F4: bc    4, 0, 0x800BD134
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD134;
        }
    }

label_800BD0F8:
    ctx->pc = 0x800BD0F8u;
    ctx->downcount -= 3;
    // 800BD0F8: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BD0FC:
    ctx->pc = 0x800BD0FCu;
    // 800BD0FC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD100:
    ctx->pc = 0x800BD100u;
    // 800BD100: bl      0x800C1F74
    {
            ctx->lr = 0x800BD104u;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BD104:
    ctx->pc = 0x800BD104u;
    ctx->downcount -= 5;
    // 800BD104: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD108:
    ctx->pc = 0x800BD108u;
    // 800BD108: lwz     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD10C:
    ctx->pc = 0x800BD10Cu;
    // 800BD10C: addi    r4, r9, 1
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(1);

label_800BD110:
    ctx->pc = 0x800BD110u;
    // 800BD110: cmpw    r4, r0
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

label_800BD114:
    ctx->pc = 0x800BD114u;
    // 800BD114: bc    4, 0, 0x800BD120
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD120;
        }
    }

label_800BD118:
    ctx->pc = 0x800BD118u;
    ctx->downcount -= 2;
    // 800BD118: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD11C:
    ctx->pc = 0x800BD11Cu;
    // 800BD11C: bl      0x800C1F74
    {
            ctx->lr = 0x800BD120u;
            ctx->pc = 0x800C1F74u;
            return;
    }

label_800BD120:
    ctx->pc = 0x800BD120u;
    ctx->downcount -= 4;
    // 800BD120: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD124:
    ctx->pc = 0x800BD124u;
    // 800BD124: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800BD128:
    ctx->pc = 0x800BD128u;
    // 800BD128: stw     r0, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD12C:
    ctx->pc = 0x800BD12Cu;
    // 800BD12C: addi    r9, r9, 2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(2);

label_800BD130:
    ctx->pc = 0x800BD130u;
    ctx->downcount -= 1;
    // 800BD130: stw     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD134:
    ctx->pc = 0x800BD134u;
    ctx->downcount -= 3;
    // 800BD134: lwz     r11, 68(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(68);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD138:
    ctx->pc = 0x800BD138u;
    // 800BD138: cmpwi   r11, 0
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

label_800BD13C:
    ctx->pc = 0x800BD13Cu;
    // 800BD13C: bc    4, 2, 0x800BD248
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD248;
        }
    }

label_800BD140:
    ctx->pc = 0x800BD140u;
    ctx->downcount -= 4;
    // 800BD140: lwz     r10, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BD144:
    ctx->pc = 0x800BD144u;
    // 800BD144: lwz     r0, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD148:
    ctx->pc = 0x800BD148u;
    // 800BD148: cmpw    r10, r0
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

label_800BD14C:
    ctx->pc = 0x800BD14Cu;
    // 800BD14C: bc    12, 1, 0x800BD158
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD158;
        }
    }

label_800BD150:
    ctx->pc = 0x800BD150u;
    ctx->downcount -= 2;
    // 800BD150: stw     r11, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD154:
    ctx->pc = 0x800BD154u;
    // 800BD154: b       0x800BD16C
    {
            goto label_800BD16C;
    }

label_800BD158:
    ctx->pc = 0x800BD158u;
    ctx->downcount -= 4;
    // 800BD158: lwz     r9, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD15C:
    ctx->pc = 0x800BD15Cu;
    // 800BD15C: addi    r0, r10, 2
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(2);

label_800BD160:
    ctx->pc = 0x800BD160u;
    // 800BD160: cmpw    r0, r9
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

label_800BD164:
    ctx->pc = 0x800BD164u;
    // 800BD164: bc    12, 0, 0x800BD16C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD16C;
        }
    }

label_800BD168:
    ctx->pc = 0x800BD168u;
    ctx->downcount -= 1;
    // 800BD168: stw     r11, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD16C:
    ctx->pc = 0x800BD16Cu;
    ctx->downcount -= 4;
    // 800BD16C: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BD170:
    ctx->pc = 0x800BD170u;
    // 800BD170: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BD174:
    ctx->pc = 0x800BD174u;
    // 800BD174: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD178:
    ctx->pc = 0x800BD178u;
    // 800BD178: bl      0x800C1C7C
    {
            ctx->lr = 0x800BD17Cu;
            ctx->pc = 0x800C1C7Cu;
            return;
    }

label_800BD17C:
    ctx->pc = 0x800BD17Cu;
    ctx->downcount -= 5;
    // 800BD17C: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD180:
    ctx->pc = 0x800BD180u;
    // 800BD180: lwz     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD184:
    ctx->pc = 0x800BD184u;
    // 800BD184: addi    r4, r9, 1
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(1);

label_800BD188:
    ctx->pc = 0x800BD188u;
    // 800BD188: cmpw    r4, r0
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

label_800BD18C:
    ctx->pc = 0x800BD18Cu;
    // 800BD18C: bc    4, 0, 0x800BD198
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD198;
        }
    }

label_800BD190:
    ctx->pc = 0x800BD190u;
    ctx->downcount -= 2;
    // 800BD190: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD194:
    ctx->pc = 0x800BD194u;
    // 800BD194: bl      0x800C1C7C
    {
            ctx->lr = 0x800BD198u;
            ctx->pc = 0x800C1C7Cu;
            return;
    }

label_800BD198:
    ctx->pc = 0x800BD198u;
    ctx->downcount -= 16;
    // 800BD198: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BD19C:
    ctx->pc = 0x800BD19Cu;
    // 800BD19C: lfs     f0, 1432(r31)
    if (!ppc_fp_available(ctx, 0x800BD19Cu)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BD1A0:
    ctx->pc = 0x800BD1A0u;
    // 800BD1A0: lfs     f31, -15984(r9)
    if (!ppc_fp_available(ctx, 0x800BD1A0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15984);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800BD1A4:
    ctx->pc = 0x800BD1A4u;
    // 800BD1A4: lis     r29, -32737
    ctx->gpr[29] = ((u32)(s32)(-32737) << 16);

label_800BD1A8:
    ctx->pc = 0x800BD1A8u;
    // 800BD1A8: lfs     f13, 1436(r31)
    if (!ppc_fp_available(ctx, 0x800BD1A8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1436);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BD1AC:
    ctx->pc = 0x800BD1ACu;
    // 800BD1AC: lis     r30, -32735
    ctx->gpr[30] = ((u32)(s32)(-32735) << 16);

label_800BD1B0:
    ctx->pc = 0x800BD1B0u;
    // 800BD1B0: fsubs   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BD1B0u)) return;
    ppc_fsubs(ctx, 0, 0, 31);

label_800BD1B4:
    ctx->pc = 0x800BD1B4u;
    // 800BD1B4: lfs     f3, -15980(r29)
    if (!ppc_fp_available(ctx, 0x800BD1B4u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-15980);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BD1B8:
    ctx->pc = 0x800BD1B8u;
    // 800BD1B8: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BD1BC:
    ctx->pc = 0x800BD1BCu;
    // 800BD1BC: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BD1BCu)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BD1C0:
    ctx->pc = 0x800BD1C0u;
    // 800BD1C0: fmr    f2, f13
    if (!ppc_fp_available(ctx, 0x800BD1C0u)) return;
    ctx->fpr[2] = ctx->fpr[13];

label_800BD1C4:
    ctx->pc = 0x800BD1C4u;
    // 800BD1C4: addi    r4, r30, -27544
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-27544);

label_800BD1C8:
    ctx->pc = 0x800BD1C8u;
    // 800BD1C8: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BD1C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD1CC:
    ctx->pc = 0x800BD1CCu;
    // 800BD1CC: ori     r3, r3, 0x0135
    ctx->gpr[3] = ctx->gpr[3] | 0x0135u;

label_800BD1D0:
    ctx->pc = 0x800BD1D0u;
    // 800BD1D0: stfs     f13, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BD1D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BD1D4:
    ctx->pc = 0x800BD1D4u;
    // 800BD1D4: bl      0x800B7AD8
    {
            ctx->lr = 0x800BD1D8u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BD1D8:
    ctx->pc = 0x800BD1D8u;
    ctx->downcount -= 11;
    // 800BD1D8: lfs     f0, 1444(r31)
    if (!ppc_fp_available(ctx, 0x800BD1D8u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1444);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BD1DC:
    ctx->pc = 0x800BD1DCu;
    // 800BD1DC: lis     r3, 8192
    ctx->gpr[3] = ((u32)(s32)(8192) << 16);

label_800BD1E0:
    ctx->pc = 0x800BD1E0u;
    // 800BD1E0: lfs     f2, 1448(r31)
    if (!ppc_fp_available(ctx, 0x800BD1E0u)) return;
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1448);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[2] = value;
        ctx->ps1[2] = value;
    }

label_800BD1E4:
    ctx->pc = 0x800BD1E4u;
    // 800BD1E4: addi    r4, r30, -27544
    ctx->gpr[4] = ctx->gpr[30] + (u32)(s32)(-27544);

label_800BD1E8:
    ctx->pc = 0x800BD1E8u;
    // 800BD1E8: fsubs   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BD1E8u)) return;
    ppc_fsubs(ctx, 0, 0, 31);

label_800BD1EC:
    ctx->pc = 0x800BD1ECu;
    // 800BD1EC: lfs     f3, -15980(r29)
    if (!ppc_fp_available(ctx, 0x800BD1ECu)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-15980);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[3] = value;
        ctx->ps1[3] = value;
    }

label_800BD1F0:
    ctx->pc = 0x800BD1F0u;
    // 800BD1F0: fmr    f1, f0
    if (!ppc_fp_available(ctx, 0x800BD1F0u)) return;
    ctx->fpr[1] = ctx->fpr[0];

label_800BD1F4:
    ctx->pc = 0x800BD1F4u;
    // 800BD1F4: stfs     f2, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BD1F4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[2]));
    }

label_800BD1F8:
    ctx->pc = 0x800BD1F8u;
    // 800BD1F8: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BD1F8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD1FC:
    ctx->pc = 0x800BD1FCu;
    // 800BD1FC: ori     r3, r3, 0x0135
    ctx->gpr[3] = ctx->gpr[3] | 0x0135u;

label_800BD200:
    ctx->pc = 0x800BD200u;
    // 800BD200: bl      0x800B7AD8
    {
            ctx->lr = 0x800BD204u;
            ctx->pc = 0x800B7AD8u;
            return;
    }

label_800BD204:
    ctx->pc = 0x800BD204u;
    ctx->downcount -= 1;
    // 800BD204: b       0x800BD248
    {
            goto label_800BD248;
    }

label_800BD208:
    ctx->pc = 0x800BD208u;
    ctx->downcount -= 4;
    // 800BD208: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BD20C:
    ctx->pc = 0x800BD20Cu;
    // 800BD20C: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BD210:
    ctx->pc = 0x800BD210u;
    // 800BD210: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD214:
    ctx->pc = 0x800BD214u;
    // 800BD214: bl      0x800C1AB0
    {
            ctx->lr = 0x800BD218u;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BD218:
    ctx->pc = 0x800BD218u;
    ctx->downcount -= 5;
    // 800BD218: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD21C:
    ctx->pc = 0x800BD21Cu;
    // 800BD21C: lwz     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD220:
    ctx->pc = 0x800BD220u;
    // 800BD220: addi    r4, r9, 1
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(1);

label_800BD224:
    ctx->pc = 0x800BD224u;
    // 800BD224: cmpw    r4, r0
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

label_800BD228:
    ctx->pc = 0x800BD228u;
    // 800BD228: bc    4, 0, 0x800BD234
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD234;
        }
    }

label_800BD22C:
    ctx->pc = 0x800BD22Cu;
    ctx->downcount -= 2;
    // 800BD22C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD230:
    ctx->pc = 0x800BD230u;
    // 800BD230: bl      0x800C1AB0
    {
            ctx->lr = 0x800BD234u;
            ctx->pc = 0x800C1AB0u;
            return;
    }

label_800BD234:
    ctx->pc = 0x800BD234u;
    ctx->downcount -= 5;
    // 800BD234: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BD238:
    ctx->pc = 0x800BD238u;
    // 800BD238: li      r0, 14
    ctx->gpr[0] = (u32)(s32)(14);

label_800BD23C:
    ctx->pc = 0x800BD23Cu;
    // 800BD23C: stw     r9, 120(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD240:
    ctx->pc = 0x800BD240u;
    // 800BD240: stw     r0, 72(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD244:
    ctx->pc = 0x800BD244u;
    // 800BD244: stw     r9, 116(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD248:
    ctx->pc = 0x800BD248u;
    ctx->downcount -= 18;
    // 800BD248: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BD24C:
    ctx->pc = 0x800BD24Cu;
    // 800BD24C: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD250:
    ctx->pc = 0x800BD250u;
    // 800BD250: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BD254:
    ctx->pc = 0x800BD254u;
    // 800BD254: lmw     r29, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        for (u32 r = 29; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BD258:
    ctx->pc = 0x800BD258u;
    // 800BD258: lfd     f31, 40(r1)
    if (!ppc_fp_available(ctx, 0x800BD258u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BD25C:
    ctx->pc = 0x800BD25Cu;
    // 800BD25C: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_800BD260:
    ctx->pc = 0x800BD260u;
    // 800BD260: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD264:
    ctx->pc = 0x800BD264u;
    ctx->downcount -= 18;
    // 800BD264: stwu     r1, -48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-48);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BD268:
    ctx->pc = 0x800BD268u;
    // 800BD268: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BD26C:
    ctx->pc = 0x800BD26Cu;
    // 800BD26C: stmw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BD270:
    ctx->pc = 0x800BD270u;
    // 800BD270: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD274:
    ctx->pc = 0x800BD274u;
    // 800BD274: lis     r9, -32698
    ctx->gpr[9] = ((u32)(s32)(-32698) << 16);

label_800BD278:
    ctx->pc = 0x800BD278u;
    // 800BD278: or.   r31, r3, r3
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

label_800BD27C:
    ctx->pc = 0x800BD27Cu;
    // 800BD27C: addi    r3, r9, 7984
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(7984);

label_800BD280:
    ctx->pc = 0x800BD280u;
    // 800BD280: bc    12, 2, 0x800BD328
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD328;
        }
    }

label_800BD284:
    ctx->pc = 0x800BD284u;
    ctx->downcount -= 31;
    // 800BD284: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BD288:
    ctx->pc = 0x800BD288u;
    // 800BD288: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BD28C:
    ctx->pc = 0x800BD28Cu;
    // 800BD28C: lfs     f0, -15976(r9)
    if (!ppc_fp_available(ctx, 0x800BD28Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15976);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BD290:
    ctx->pc = 0x800BD290u;
    // 800BD290: addi    r8, r1, 8
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(8);

label_800BD294:
    ctx->pc = 0x800BD294u;
    // 800BD294: lfs     f13, -15972(r11)
    if (!ppc_fp_available(ctx, 0x800BD294u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15972);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BD298:
    ctx->pc = 0x800BD298u;
    // 800BD298: addi    r9, r1, 24
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(24);

label_800BD29C:
    ctx->pc = 0x800BD29Cu;
    // 800BD29C: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BD29Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD2A0:
    ctx->pc = 0x800BD2A0u;
    // 800BD2A0: lis     r11, -32734
    ctx->gpr[11] = ((u32)(s32)(-32734) << 16);

label_800BD2A4:
    ctx->pc = 0x800BD2A4u;
    // 800BD2A4: stfs     f13, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BD2A4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BD2A8:
    ctx->pc = 0x800BD2A8u;
    // 800BD2A8: addi    r11, r11, -3500
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-3500);

label_800BD2AC:
    ctx->pc = 0x800BD2ACu;
    // 800BD2AC: lwz     r10, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BD2B0:
    ctx->pc = 0x800BD2B0u;
    // 800BD2B0: addi    r11, r11, 4
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(4);

label_800BD2B4:
    ctx->pc = 0x800BD2B4u;
    // 800BD2B4: lwz     r7, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800BD2B8:
    ctx->pc = 0x800BD2B8u;
    // 800BD2B8: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BD2BC:
    ctx->pc = 0x800BD2BCu;
    // 800BD2BC: lwz     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD2C0:
    ctx->pc = 0x800BD2C0u;
    // 800BD2C0: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BD2C4:
    ctx->pc = 0x800BD2C4u;
    // 800BD2C4: stw     r10, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BD2C8:
    ctx->pc = 0x800BD2C8u;
    // 800BD2C8: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BD2CC:
    ctx->pc = 0x800BD2CCu;
    // 800BD2CC: stw     r7, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800BD2D0:
    ctx->pc = 0x800BD2D0u;
    // 800BD2D0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BD2D4:
    ctx->pc = 0x800BD2D4u;
    // 800BD2D4: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD2D8:
    ctx->pc = 0x800BD2D8u;
    // 800BD2D8: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BD2DC:
    ctx->pc = 0x800BD2DCu;
    // 800BD2DC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BD2E0:
    ctx->pc = 0x800BD2E0u;
    // 800BD2E0: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BD2E4:
    ctx->pc = 0x800BD2E4u;
    // 800BD2E4: lwz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD2E8:
    ctx->pc = 0x800BD2E8u;
    // 800BD2E8: addi    r30, r31, 3720
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(3720);

label_800BD2EC:
    ctx->pc = 0x800BD2ECu;
    // 800BD2EC: mulli   r0, r0, 12
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)12);

label_800BD2F0:
    ctx->pc = 0x800BD2F0u;
    // 800BD2F0: lwzx    r5, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BD2F4:
    ctx->pc = 0x800BD2F4u;
    // 800BD2F4: bl      0x800C3D88
    {
            ctx->lr = 0x800BD2F8u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BD2F8:
    ctx->pc = 0x800BD2F8u;
    ctx->downcount -= 4;
    // 800BD2F8: lwz     r4, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BD2FC:
    ctx->pc = 0x800BD2FCu;
    // 800BD2FC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD300:
    ctx->pc = 0x800BD300u;
    // 800BD300: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BD304:
    ctx->pc = 0x800BD304u;
    // 800BD304: bl      0x800C1D34
    {
            ctx->lr = 0x800BD308u;
            ctx->pc = 0x800C1D34u;
            return;
    }

label_800BD308:
    ctx->pc = 0x800BD308u;
    ctx->downcount -= 5;
    // 800BD308: lwz     r9, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD30C:
    ctx->pc = 0x800BD30Cu;
    // 800BD30C: lwz     r0, 44(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD310:
    ctx->pc = 0x800BD310u;
    // 800BD310: addi    r4, r9, 1
    ctx->gpr[4] = ctx->gpr[9] + (u32)(s32)(1);

label_800BD314:
    ctx->pc = 0x800BD314u;
    // 800BD314: cmpw    r4, r0
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

label_800BD318:
    ctx->pc = 0x800BD318u;
    // 800BD318: bc    4, 0, 0x800BD328
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD328;
        }
    }

label_800BD31C:
    ctx->pc = 0x800BD31Cu;
    ctx->downcount -= 3;
    // 800BD31C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD320:
    ctx->pc = 0x800BD320u;
    // 800BD320: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BD324:
    ctx->pc = 0x800BD324u;
    // 800BD324: bl      0x800C1D34
    {
            ctx->lr = 0x800BD328u;
            ctx->pc = 0x800C1D34u;
            return;
    }

label_800BD328:
    ctx->pc = 0x800BD328u;
    ctx->downcount -= 16;
    // 800BD328: lwz     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD32C:
    ctx->pc = 0x800BD32Cu;
    // 800BD32C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BD330:
    ctx->pc = 0x800BD330u;
    // 800BD330: lmw     r30, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BD334:
    ctx->pc = 0x800BD334u;
    // 800BD334: addi    r1, r1, 48
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(48);

label_800BD338:
    ctx->pc = 0x800BD338u;
    // 800BD338: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD33C:
    ctx->pc = 0x800BD33Cu;
    ctx->downcount -= 5;
    // 800BD33C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BD340:
    ctx->pc = 0x800BD340u;
    // 800BD340: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BD344:
    ctx->pc = 0x800BD344u;
    // 800BD344: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD348:
    ctx->pc = 0x800BD348u;
    // 800BD348: cmpwi   r4, 0
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

label_800BD34C:
    ctx->pc = 0x800BD34Cu;
    // 800BD34C: bc    4, 2, 0x800BD358
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD358;
        }
    }

label_800BD350:
    ctx->pc = 0x800BD350u;
    ctx->downcount -= 2;
    // 800BD350: li      r3, 466
    ctx->gpr[3] = (u32)(s32)(466);

label_800BD354:
    ctx->pc = 0x800BD354u;
    // 800BD354: bl      0x8005B3F8
    {
            ctx->lr = 0x800BD358u;
            ctx->pc = 0x8005B3F8u;
            return;
    }

label_800BD358:
    ctx->pc = 0x800BD358u;
    ctx->downcount -= 5;
    // 800BD358: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD35C:
    ctx->pc = 0x800BD35Cu;
    // 800BD35C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BD360:
    ctx->pc = 0x800BD360u;
    // 800BD360: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BD364:
    ctx->pc = 0x800BD364u;
    // 800BD364: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD368:
    ctx->pc = 0x800BD368u;
    ctx->downcount -= 18;
    // 800BD368: stwu     r1, -120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-120);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BD36C:
    ctx->pc = 0x800BD36Cu;
    // 800BD36C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BD370:
    ctx->pc = 0x800BD370u;
    // 800BD370: stmw     r27, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BD374:
    ctx->pc = 0x800BD374u;
    // 800BD374: stw     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD378:
    ctx->pc = 0x800BD378u;
    // 800BD378: li      r30, 0
    ctx->gpr[30] = (u32)(s32)(0);

label_800BD37C:
    ctx->pc = 0x800BD37Cu;
    // 800BD37C: li      r29, -1
    ctx->gpr[29] = (u32)(s32)(-1);

label_800BD380:
    ctx->pc = 0x800BD380u;
    // 800BD380: or.   r31, r3, r3
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

label_800BD384:
    ctx->pc = 0x800BD384u;
    // 800BD384: bc    12, 2, 0x800BD590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD590;
        }
    }

label_800BD388:
    ctx->pc = 0x800BD388u;
    ctx->downcount -= 4;
    // 800BD388: lwz     r3, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BD38C:
    ctx->pc = 0x800BD38Cu;
    // 800BD38C: lis     r4, 20992
    ctx->gpr[4] = ((u32)(s32)(20992) << 16);

label_800BD390:
    ctx->pc = 0x800BD390u;
    // 800BD390: ori     r4, r4, 0x0129
    ctx->gpr[4] = ctx->gpr[4] | 0x0129u;

label_800BD394:
    ctx->pc = 0x800BD394u;
    // 800BD394: bl      0x80047634
    {
            ctx->lr = 0x800BD398u;
            ctx->pc = 0x80047634u;
            return;
    }

label_800BD398:
    ctx->pc = 0x800BD398u;
    ctx->downcount -= 2;
    // 800BD398: or.   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[27];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD39C:
    ctx->pc = 0x800BD39Cu;
    // 800BD39C: bc    12, 2, 0x800BD590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD590;
        }
    }

label_800BD3A0:
    ctx->pc = 0x800BD3A0u;
    ctx->downcount -= 7;
    // 800BD3A0: stw     r29, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800BD3A4:
    ctx->pc = 0x800BD3A4u;
    // 800BD3A4: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BD3A8:
    ctx->pc = 0x800BD3A8u;
    // 800BD3A8: addi    r11, r9, -3152
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-3152);

label_800BD3AC:
    ctx->pc = 0x800BD3ACu;
    // 800BD3AC: addi    r28, r1, 48
    ctx->gpr[28] = ctx->gpr[1] + (u32)(s32)(48);

label_800BD3B0:
    ctx->pc = 0x800BD3B0u;
    // 800BD3B0: lwz     r0, -3152(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-3152);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD3B4:
    ctx->pc = 0x800BD3B4u;
    // 800BD3B4: cmpwi   r0, -1
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

label_800BD3B8:
    ctx->pc = 0x800BD3B8u;
    // 800BD3B8: bc    12, 2, 0x800BD420
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD420;
        }
    }

label_800BD3BC:
    ctx->pc = 0x800BD3BCu;
    ctx->downcount -= 5;
    // 800BD3BC: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BD3C0:
    ctx->pc = 0x800BD3C0u;
    // 800BD3C0: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BD3C4:
    ctx->pc = 0x800BD3C4u;
    // 800BD3C4: lwz     r7, 40(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(40);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800BD3C8:
    ctx->pc = 0x800BD3C8u;
    // 800BD3C8: addi    r8, r9, -21636
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BD3CC:
    ctx->pc = 0x800BD3CCu;
    // 800BD3CC: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800BD3D0:
    ctx->pc = 0x800BD3D0u;
    ctx->downcount -= 3;
    // 800BD3D0: lwzx    r9, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD3D4:
    // 800BD3D4: and.   r0, r7, r9
    {
        ctx->gpr[0] = ctx->gpr[7] & ctx->gpr[9];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD3D8:
    // 800BD3D8: bc    12, 2, 0x800BD3EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD3EC;
        }
    }

label_800BD3DC:
    ctx->pc = 0x800BD3DCu;
    ctx->downcount -= 3;
    // 800BD3DC: lhz     r0, 972(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(972);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BD3E0:
    // 800BD3E0: and.   r6, r0, r9
    {
        ctx->gpr[6] = ctx->gpr[0] & ctx->gpr[9];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD3E4:
    // 800BD3E4: bc    4, 2, 0x800BD40C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD40C;
        }
    }

label_800BD3E8:
    ctx->pc = 0x800BD3E8u;
    ctx->downcount -= 1;
    // 800BD3E8: stw     r30, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BD3EC:
    ctx->pc = 0x800BD3ECu;
    ctx->downcount -= 4;
    // 800BD3EC: lhz     r9, 972(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(972);
        ctx->gpr[9] = mem_read16(ctx, ea);
    }

label_800BD3F0:
    ctx->pc = 0x800BD3F0u;
    // 800BD3F0: lwzx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD3F4:
    // 800BD3F4: and.   r6, r9, r0
    {
        ctx->gpr[6] = ctx->gpr[9] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[6];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD3F8:
    // 800BD3F8: bc    4, 2, 0x800BD40C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD40C;
        }
    }

label_800BD3FC:
    ctx->downcount -= 2;
    // 800BD3FC: cmpwi   r29, -1
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BD400:
    // 800BD400: bc    4, 2, 0x800BD40C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD40C;
        }
    }

label_800BD404:
    ctx->downcount -= 2;
    // 800BD404: or   r29, r30, r30
    {
        ctx->gpr[29] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD408:
    ctx->pc = 0x800BD408u;
    // 800BD408: stw     r29, 56(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800BD40C:
    ctx->downcount -= 5;
    // 800BD40C: addi    r11, r11, 16
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(16);

label_800BD410:
    // 800BD410: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_800BD414:
    ctx->pc = 0x800BD414u;
    // 800BD414: lwzx    r0, r11, r10
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[10];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD418:
    // 800BD418: cmpwi   r0, -1
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

label_800BD41C:
    // 800BD41C: bc    4, 2, 0x800BD3D0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BD3D0u;
                return;
            }
            goto label_800BD3D0;
        }
    }

label_800BD420:
    ctx->pc = 0x800BD420u;
    ctx->downcount -= 4;
    // 800BD420: lwz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD424:
    ctx->pc = 0x800BD424u;
    // 800BD424: stw     r30, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BD428:
    ctx->pc = 0x800BD428u;
    // 800BD428: cmpwi   r0, -1
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

label_800BD42C:
    ctx->pc = 0x800BD42Cu;
    // 800BD42C: bc    4, 2, 0x800BD434
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD434;
        }
    }

label_800BD430:
    ctx->pc = 0x800BD430u;
    ctx->downcount -= 1;
    // 800BD430: stw     r29, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800BD434:
    ctx->pc = 0x800BD434u;
    ctx->downcount -= 7;
    // 800BD434: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BD438:
    ctx->pc = 0x800BD438u;
    // 800BD438: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BD43C:
    ctx->pc = 0x800BD43Cu;
    // 800BD43C: ori     r4, r4, 0x00B8
    ctx->gpr[4] = ctx->gpr[4] | 0x00B8u;

label_800BD440:
    ctx->pc = 0x800BD440u;
    // 800BD440: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BD444:
    ctx->pc = 0x800BD444u;
    // 800BD444: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BD448:
    ctx->pc = 0x800BD448u;
    // 800BD448: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BD44C:
    ctx->pc = 0x800BD44Cu;
    // 800BD44C: bl      0x800303A8
    {
            ctx->lr = 0x800BD450u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BD450:
    ctx->pc = 0x800BD450u;
    ctx->downcount -= 2;
    // 800BD450: cmpwi   r3, 0
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

label_800BD454:
    ctx->pc = 0x800BD454u;
    // 800BD454: bc    12, 2, 0x800BD48C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD48C;
        }
    }

label_800BD458:
    ctx->pc = 0x800BD458u;
    ctx->downcount -= 6;
    // 800BD458: addi    r30, r1, 64
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(64);

label_800BD45C:
    ctx->pc = 0x800BD45Cu;
    // 800BD45C: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BD460:
    ctx->pc = 0x800BD460u;
    // 800BD460: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD464:
    ctx->pc = 0x800BD464u;
    // 800BD464: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BD468:
    ctx->pc = 0x800BD468u;
    // 800BD468: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BD46C:
    ctx->pc = 0x800BD46Cu;
    // 800BD46C: bl      0x800C48AC
    {
            ctx->lr = 0x800BD470u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BD470:
    ctx->pc = 0x800BD470u;
    ctx->downcount -= 7;
    // 800BD470: lwz     r10, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BD474:
    ctx->pc = 0x800BD474u;
    // 800BD474: addi    r11, r31, 1420
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(1420);

label_800BD478:
    ctx->pc = 0x800BD478u;
    // 800BD478: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD47C:
    ctx->pc = 0x800BD47Cu;
    // 800BD47C: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD480:
    ctx->pc = 0x800BD480u;
    // 800BD480: stw     r10, 1420(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1420);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BD484:
    ctx->pc = 0x800BD484u;
    // 800BD484: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD488:
    ctx->pc = 0x800BD488u;
    // 800BD488: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD48C:
    ctx->pc = 0x800BD48Cu;
    ctx->downcount -= 7;
    // 800BD48C: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BD490:
    ctx->pc = 0x800BD490u;
    // 800BD490: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BD494:
    ctx->pc = 0x800BD494u;
    // 800BD494: ori     r4, r4, 0x00BC
    ctx->gpr[4] = ctx->gpr[4] | 0x00BCu;

label_800BD498:
    ctx->pc = 0x800BD498u;
    // 800BD498: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BD49C:
    ctx->pc = 0x800BD49Cu;
    // 800BD49C: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BD4A0:
    ctx->pc = 0x800BD4A0u;
    // 800BD4A0: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BD4A4:
    ctx->pc = 0x800BD4A4u;
    // 800BD4A4: bl      0x800303A8
    {
            ctx->lr = 0x800BD4A8u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BD4A8:
    ctx->pc = 0x800BD4A8u;
    ctx->downcount -= 2;
    // 800BD4A8: cmpwi   r3, 0
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

label_800BD4AC:
    ctx->pc = 0x800BD4ACu;
    // 800BD4AC: bc    12, 2, 0x800BD4E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD4E4;
        }
    }

label_800BD4B0:
    ctx->pc = 0x800BD4B0u;
    ctx->downcount -= 6;
    // 800BD4B0: addi    r30, r1, 64
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(64);

label_800BD4B4:
    ctx->pc = 0x800BD4B4u;
    // 800BD4B4: or   r4, r28, r28
    {
        ctx->gpr[4] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BD4B8:
    ctx->pc = 0x800BD4B8u;
    // 800BD4B8: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD4BC:
    ctx->pc = 0x800BD4BCu;
    // 800BD4BC: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BD4C0:
    ctx->pc = 0x800BD4C0u;
    // 800BD4C0: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BD4C4:
    ctx->pc = 0x800BD4C4u;
    // 800BD4C4: bl      0x800C48AC
    {
            ctx->lr = 0x800BD4C8u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BD4C8:
    ctx->pc = 0x800BD4C8u;
    ctx->downcount -= 7;
    // 800BD4C8: lwz     r10, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BD4CC:
    ctx->pc = 0x800BD4CCu;
    // 800BD4CC: addi    r11, r31, 1432
    ctx->gpr[11] = ctx->gpr[31] + (u32)(s32)(1432);

label_800BD4D0:
    ctx->pc = 0x800BD4D0u;
    // 800BD4D0: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD4D4:
    ctx->pc = 0x800BD4D4u;
    // 800BD4D4: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD4D8:
    ctx->pc = 0x800BD4D8u;
    // 800BD4D8: stw     r10, 1432(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BD4DC:
    ctx->pc = 0x800BD4DCu;
    // 800BD4DC: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD4E0:
    ctx->pc = 0x800BD4E0u;
    // 800BD4E0: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD4E4:
    ctx->pc = 0x800BD4E4u;
    ctx->downcount -= 7;
    // 800BD4E4: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BD4E8:
    ctx->pc = 0x800BD4E8u;
    // 800BD4E8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BD4EC:
    ctx->pc = 0x800BD4ECu;
    // 800BD4EC: ori     r4, r4, 0x009A
    ctx->gpr[4] = ctx->gpr[4] | 0x009Au;

label_800BD4F0:
    ctx->pc = 0x800BD4F0u;
    // 800BD4F0: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BD4F4:
    ctx->pc = 0x800BD4F4u;
    // 800BD4F4: or   r6, r28, r28
    {
        ctx->gpr[6] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BD4F8:
    ctx->pc = 0x800BD4F8u;
    // 800BD4F8: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BD4FC:
    ctx->pc = 0x800BD4FCu;
    // 800BD4FC: bl      0x800303A8
    {
            ctx->lr = 0x800BD500u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BD500:
    ctx->pc = 0x800BD500u;
    ctx->downcount -= 2;
    // 800BD500: cmpwi   r3, 0
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

label_800BD504:
    ctx->pc = 0x800BD504u;
    // 800BD504: bc    12, 2, 0x800BD590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD590;
        }
    }

label_800BD508:
    ctx->pc = 0x800BD508u;
    ctx->downcount -= 8;
    // 800BD508: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BD50C:
    ctx->pc = 0x800BD50Cu;
    // 800BD50C: lwz     r0, 48(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD510:
    ctx->pc = 0x800BD510u;
    // 800BD510: addi    r9, r9, -3152
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-3152);

label_800BD514:
    ctx->pc = 0x800BD514u;
    // 800BD514: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_800BD518:
    ctx->pc = 0x800BD518u;
    // 800BD518: addi    r9, r9, 12
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(12);

label_800BD51C:
    ctx->pc = 0x800BD51Cu;
    // 800BD51C: lwzx    r5, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BD520:
    ctx->pc = 0x800BD520u;
    // 800BD520: cmpwi   r5, 0
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

label_800BD524:
    ctx->pc = 0x800BD524u;
    // 800BD524: bc    12, 2, 0x800BD590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD590;
        }
    }

label_800BD528:
    ctx->pc = 0x800BD528u;
    ctx->downcount -= 18;
    // 800BD528: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BD52C:
    ctx->pc = 0x800BD52Cu;
    // 800BD52C: lfs     f0, 52(r1)
    if (!ppc_fp_available(ctx, 0x800BD52Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BD530:
    ctx->pc = 0x800BD530u;
    // 800BD530: lfs     f13, -15968(r9)
    if (!ppc_fp_available(ctx, 0x800BD530u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15968);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BD534:
    ctx->pc = 0x800BD534u;
    // 800BD534: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BD538:
    ctx->pc = 0x800BD538u;
    // 800BD538: lwz     r10, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BD53C:
    ctx->pc = 0x800BD53Cu;
    // 800BD53C: addi    r9, r1, 80
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(80);

label_800BD540:
    ctx->pc = 0x800BD540u;
    // 800BD540: fsubs   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BD540u)) return;
    ppc_fsubs(ctx, 0, 0, 13);

label_800BD544:
    ctx->pc = 0x800BD544u;
    // 800BD544: lfs     f1, -15964(r11)
    if (!ppc_fp_available(ctx, 0x800BD544u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15964);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BD548:
    ctx->pc = 0x800BD548u;
    // 800BD548: stfs     f0, 52(r1)
    if (!ppc_fp_available(ctx, 0x800BD548u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD54C:
    ctx->pc = 0x800BD54Cu;
    // 800BD54C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BD550:
    ctx->pc = 0x800BD550u;
    // 800BD550: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BD554:
    ctx->pc = 0x800BD554u;
    // 800BD554: addi    r6, r31, 20
    ctx->gpr[6] = ctx->gpr[31] + (u32)(s32)(20);

label_800BD558:
    ctx->pc = 0x800BD558u;
    // 800BD558: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD55C:
    ctx->pc = 0x800BD55Cu;
    // 800BD55C: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD560:
    ctx->pc = 0x800BD560u;
    // 800BD560: stw     r10, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BD564:
    ctx->pc = 0x800BD564u;
    // 800BD564: stw     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD568:
    ctx->pc = 0x800BD568u;
    // 800BD568: stw     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD56C:
    ctx->pc = 0x800BD56Cu;
    // 800BD56C: bl      0x800C457C
    {
            ctx->lr = 0x800BD570u;
            ctx->pc = 0x800C457Cu;
            return;
    }

label_800BD570:
    ctx->pc = 0x800BD570u;
    ctx->downcount -= 3;
    // 800BD570: lwz     r3, 20(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BD574:
    ctx->pc = 0x800BD574u;
    // 800BD574: cmpwi   r3, 0
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

label_800BD578:
    ctx->pc = 0x800BD578u;
    // 800BD578: bc    12, 2, 0x800BD590
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD590;
        }
    }

label_800BD57C:
    ctx->pc = 0x800BD57Cu;
    ctx->downcount -= 5;
    // 800BD57C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BD580:
    ctx->pc = 0x800BD580u;
    // 800BD580: lfs     f1, -15960(r9)
    if (!ppc_fp_available(ctx, 0x800BD580u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15960);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BD584:
    ctx->pc = 0x800BD584u;
    // 800BD584: fmr    f2, f1
    if (!ppc_fp_available(ctx, 0x800BD584u)) return;
    ctx->fpr[2] = ctx->fpr[1];

label_800BD588:
    ctx->pc = 0x800BD588u;
    // 800BD588: fmr    f3, f1
    if (!ppc_fp_available(ctx, 0x800BD588u)) return;
    ctx->fpr[3] = ctx->fpr[1];

label_800BD58C:
    ctx->pc = 0x800BD58Cu;
    // 800BD58C: bl      0x80040E7C
    {
            ctx->lr = 0x800BD590u;
            ctx->pc = 0x80040E7Cu;
            return;
    }

label_800BD590:
    ctx->pc = 0x800BD590u;
    ctx->downcount -= 16;
    // 800BD590: lwz     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD594:
    ctx->pc = 0x800BD594u;
    // 800BD594: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BD598:
    ctx->pc = 0x800BD598u;
    // 800BD598: lmw     r27, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BD59C:
    ctx->pc = 0x800BD59Cu;
    // 800BD59C: addi    r1, r1, 120
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(120);

label_800BD5A0:
    ctx->pc = 0x800BD5A0u;
    // 800BD5A0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD5A4:
    ctx->pc = 0x800BD5A4u;
    ctx->downcount -= 16;
    // 800BD5A4: stwu     r1, -16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-16);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BD5A8:
    ctx->pc = 0x800BD5A8u;
    // 800BD5A8: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BD5AC:
    ctx->pc = 0x800BD5ACu;
    // 800BD5AC: stmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BD5B0:
    ctx->pc = 0x800BD5B0u;
    // 800BD5B0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD5B4:
    ctx->pc = 0x800BD5B4u;
    // 800BD5B4: or.   r30, r3, r3
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

label_800BD5B8:
    ctx->pc = 0x800BD5B8u;
    // 800BD5B8: bc    12, 2, 0x800BD628
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD628;
        }
    }

label_800BD5BC:
    ctx->pc = 0x800BD5BCu;
    ctx->downcount -= 6;
    // 800BD5BC: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BD5C0:
    ctx->pc = 0x800BD5C0u;
    // 800BD5C0: lwz     r11, 40(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(40);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD5C4:
    ctx->pc = 0x800BD5C4u;
    // 800BD5C4: addi    r31, r9, -21636
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BD5C8:
    ctx->pc = 0x800BD5C8u;
    // 800BD5C8: lhz     r0, 972(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(972);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BD5CC:
    ctx->pc = 0x800BD5CCu;
    // 800BD5CC: and.   r9, r0, r11
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

label_800BD5D0:
    ctx->pc = 0x800BD5D0u;
    // 800BD5D0: bc    12, 2, 0x800BD5E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD5E0;
        }
    }

label_800BD5D4:
    ctx->pc = 0x800BD5D4u;
    ctx->downcount -= 3;
    // 800BD5D4: li      r3, 10
    ctx->gpr[3] = (u32)(s32)(10);

label_800BD5D8:
    ctx->pc = 0x800BD5D8u;
    // 800BD5D8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BD5DC:
    ctx->pc = 0x800BD5DCu;
    // 800BD5DC: bl      0x80159D1C
    {
            ctx->lr = 0x800BD5E0u;
            ctx->pc = 0x80159D1Cu;
            return;
    }

label_800BD5E0:
    ctx->pc = 0x800BD5E0u;
    ctx->downcount -= 7;
    // 800BD5E0: lwz     r0, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD5E4:
    ctx->pc = 0x800BD5E4u;
    // 800BD5E4: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BD5E8:
    ctx->pc = 0x800BD5E8u;
    // 800BD5E8: addi    r9, r9, -3152
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-3152);

label_800BD5EC:
    ctx->pc = 0x800BD5ECu;
    // 800BD5EC: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_800BD5F0:
    ctx->pc = 0x800BD5F0u;
    // 800BD5F0: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD5F4:
    ctx->pc = 0x800BD5F4u;
    // 800BD5F4: cmpwi   r11, 0
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

label_800BD5F8:
    ctx->pc = 0x800BD5F8u;
    // 800BD5F8: bc    12, 2, 0x800BD614
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD614;
        }
    }

label_800BD5FC:
    ctx->pc = 0x800BD5FCu;
    ctx->downcount -= 5;
    // 800BD5FC: add   r9, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BD600:
    ctx->pc = 0x800BD600u;
    // 800BD600: li      r3, 4107
    ctx->gpr[3] = (u32)(s32)(4107);

label_800BD604:
    ctx->pc = 0x800BD604u;
    // 800BD604: lhz     r0, 2(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(2);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BD608:
    ctx->pc = 0x800BD608u;
    // 800BD608: sth     r0, 974(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(974);
        mem_write16(ctx, ea, (u16)ctx->gpr[0]);
    }

label_800BD60C:
    ctx->pc = 0x800BD60Cu;
    // 800BD60C: bl      0x800C4E28
    {
            ctx->lr = 0x800BD610u;
            ctx->pc = 0x800C4E28u;
            return;
    }

label_800BD610:
    ctx->pc = 0x800BD610u;
    ctx->downcount -= 1;
    // 800BD610: b       0x800BD620
    {
            goto label_800BD620;
    }

label_800BD614:
    ctx->pc = 0x800BD614u;
    ctx->downcount -= 3;
    // 800BD614: li      r3, 4107
    ctx->gpr[3] = (u32)(s32)(4107);

label_800BD618:
    ctx->pc = 0x800BD618u;
    // 800BD618: sth     r11, 974(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(974);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_800BD61C:
    ctx->pc = 0x800BD61Cu;
    // 800BD61C: bl      0x800C4E68
    {
            ctx->lr = 0x800BD620u;
            ctx->pc = 0x800C4E68u;
            return;
    }

label_800BD620:
    ctx->pc = 0x800BD620u;
    ctx->downcount -= 2;
    // 800BD620: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_800BD624:
    ctx->pc = 0x800BD624u;
    // 800BD624: bl      0x800C4764
    {
            ctx->lr = 0x800BD628u;
            ctx->pc = 0x800C4764u;
            return;
    }

label_800BD628:
    ctx->pc = 0x800BD628u;
    ctx->downcount -= 16;
    // 800BD628: lwz     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD62C:
    ctx->pc = 0x800BD62Cu;
    // 800BD62C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BD630:
    ctx->pc = 0x800BD630u;
    // 800BD630: lmw     r30, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 30; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BD634:
    ctx->pc = 0x800BD634u;
    // 800BD634: addi    r1, r1, 16
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(16);

label_800BD638:
    ctx->pc = 0x800BD638u;
    // 800BD638: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD63C:
    ctx->pc = 0x800BD63Cu;
    ctx->downcount -= 2;
    // 800BD63C: or.   r3, r3, r3
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

label_800BD640:
    ctx->pc = 0x800BD640u;
    // 800BD640: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD644:
    ctx->pc = 0x800BD644u;
    ctx->downcount -= 6;
    // 800BD644: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_800BD648:
    ctx->pc = 0x800BD648u;
    // 800BD648: li      r9, 6
    ctx->gpr[9] = (u32)(s32)(6);

label_800BD64C:
    ctx->pc = 0x800BD64Cu;
    // 800BD64C: stw     r4, 40(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_800BD650:
    ctx->pc = 0x800BD650u;
    // 800BD650: stw     r0, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD654:
    ctx->pc = 0x800BD654u;
    // 800BD654: stw     r9, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD658:
    ctx->pc = 0x800BD658u;
    // 800BD658: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD65C:
    ctx->pc = 0x800BD65Cu;
    ctx->downcount -= 5;
    // 800BD65C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BD660:
    ctx->pc = 0x800BD660u;
    // 800BD660: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BD664:
    ctx->pc = 0x800BD664u;
    // 800BD664: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD668:
    ctx->pc = 0x800BD668u;
    // 800BD668: lwz     r3, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BD66C:
    ctx->pc = 0x800BD66Cu;
    // 800BD66C: bl      0x800C4714
    {
            ctx->lr = 0x800BD670u;
            ctx->pc = 0x800C4714u;
            return;
    }

label_800BD670:
    ctx->pc = 0x800BD670u;
    ctx->downcount -= 6;
    // 800BD670: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BD674:
    ctx->pc = 0x800BD674u;
    // 800BD674: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD678:
    ctx->pc = 0x800BD678u;
    // 800BD678: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BD67C:
    ctx->pc = 0x800BD67Cu;
    // 800BD67C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BD680:
    ctx->pc = 0x800BD680u;
    // 800BD680: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD684:
    ctx->pc = 0x800BD684u;
    ctx->downcount -= 21;
    // 800BD684: stwu     r1, -160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-160);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BD688:
    ctx->pc = 0x800BD688u;
    // 800BD688: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BD68C:
    ctx->pc = 0x800BD68Cu;
    // 800BD68C: stfd     f29, 136(r1)
    if (!ppc_fp_available(ctx, 0x800BD68Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[29]));
    }

label_800BD690:
    ctx->pc = 0x800BD690u;
    // 800BD690: stfd     f30, 144(r1)
    if (!ppc_fp_available(ctx, 0x800BD690u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_800BD694:
    ctx->pc = 0x800BD694u;
    // 800BD694: stfd     f31, 152(r1)
    if (!ppc_fp_available(ctx, 0x800BD694u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800BD698:
    ctx->pc = 0x800BD698u;
    // 800BD698: stmw     r21, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        for (u32 r = 21; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BD69C:
    ctx->pc = 0x800BD69Cu;
    // 800BD69C: stw     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD6A0:
    ctx->pc = 0x800BD6A0u;
    // 800BD6A0: lis     r9, -32698
    ctx->gpr[9] = ((u32)(s32)(-32698) << 16);

label_800BD6A4:
    ctx->pc = 0x800BD6A4u;
    // 800BD6A4: or.   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[28];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD6A8:
    ctx->pc = 0x800BD6A8u;
    // 800BD6A8: addi    r30, r9, 7984
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(7984);

label_800BD6AC:
    ctx->pc = 0x800BD6ACu;
    // 800BD6AC: bc    12, 2, 0x800BD95C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD95C;
        }
    }

label_800BD6B0:
    ctx->pc = 0x800BD6B0u;
    ctx->downcount -= 25;
    // 800BD6B0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BD6B4:
    ctx->pc = 0x800BD6B4u;
    // 800BD6B4: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BD6B8:
    ctx->pc = 0x800BD6B8u;
    // 800BD6B8: lfs     f0, -15956(r9)
    if (!ppc_fp_available(ctx, 0x800BD6B8u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15956);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BD6BC:
    ctx->pc = 0x800BD6BCu;
    // 800BD6BC: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_800BD6C0:
    ctx->pc = 0x800BD6C0u;
    // 800BD6C0: lfs     f31, -15952(r11)
    if (!ppc_fp_available(ctx, 0x800BD6C0u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15952);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800BD6C4:
    ctx->pc = 0x800BD6C4u;
    // 800BD6C4: addi    r31, r1, 56
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(56);

label_800BD6C8:
    ctx->pc = 0x800BD6C8u;
    // 800BD6C8: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BD6C8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD6CC:
    ctx->pc = 0x800BD6CCu;
    // 800BD6CC: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BD6D0:
    ctx->pc = 0x800BD6D0u;
    // 800BD6D0: stfs     f31, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BD6D0u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800BD6D4:
    ctx->pc = 0x800BD6D4u;
    // 800BD6D4: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BD6D8:
    ctx->pc = 0x800BD6D8u;
    // 800BD6D8: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD6DC:
    ctx->pc = 0x800BD6DCu;
    // 800BD6DC: li      r5, 3843
    ctx->gpr[5] = (u32)(s32)(3843);

label_800BD6E0:
    ctx->pc = 0x800BD6E0u;
    // 800BD6E0: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD6E4:
    ctx->pc = 0x800BD6E4u;
    // 800BD6E4: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BD6E8:
    ctx->pc = 0x800BD6E8u;
    // 800BD6E8: lwz     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD6EC:
    ctx->pc = 0x800BD6ECu;
    // 800BD6EC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BD6F0:
    ctx->pc = 0x800BD6F0u;
    // 800BD6F0: stw     r0, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD6F4:
    ctx->pc = 0x800BD6F4u;
    // 800BD6F4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BD6F8:
    ctx->pc = 0x800BD6F8u;
    // 800BD6F8: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD6FC:
    ctx->pc = 0x800BD6FCu;
    // 800BD6FC: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BD700:
    ctx->pc = 0x800BD700u;
    // 800BD700: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BD704:
    ctx->pc = 0x800BD704u;
    // 800BD704: stw     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD708:
    ctx->pc = 0x800BD708u;
    // 800BD708: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD70C:
    ctx->pc = 0x800BD70Cu;
    // 800BD70C: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_800BD710:
    ctx->pc = 0x800BD710u;
    // 800BD710: bl      0x800C3D88
    {
            ctx->lr = 0x800BD714u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BD714:
    ctx->pc = 0x800BD714u;
    ctx->downcount -= 20;
    // 800BD714: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BD718:
    ctx->pc = 0x800BD718u;
    // 800BD718: stfs     f31, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BD718u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[31]));
    }

label_800BD71C:
    ctx->pc = 0x800BD71Cu;
    // 800BD71C: lfs     f0, -15948(r9)
    if (!ppc_fp_available(ctx, 0x800BD71Cu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15948);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BD720:
    ctx->pc = 0x800BD720u;
    // 800BD720: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD724:
    ctx->pc = 0x800BD724u;
    // 800BD724: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BD728:
    ctx->pc = 0x800BD728u;
    // 800BD728: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BD72C:
    ctx->pc = 0x800BD72Cu;
    // 800BD72C: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BD72Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD730:
    ctx->pc = 0x800BD730u;
    // 800BD730: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BD734:
    ctx->pc = 0x800BD734u;
    // 800BD734: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BD738:
    ctx->pc = 0x800BD738u;
    // 800BD738: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BD73C:
    ctx->pc = 0x800BD73Cu;
    // 800BD73C: lwz     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD740:
    ctx->pc = 0x800BD740u;
    // 800BD740: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BD744:
    ctx->pc = 0x800BD744u;
    // 800BD744: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD748:
    ctx->pc = 0x800BD748u;
    // 800BD748: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BD74C:
    ctx->pc = 0x800BD74Cu;
    // 800BD74C: lwz     r30, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800BD750:
    ctx->pc = 0x800BD750u;
    // 800BD750: li      r5, 3844
    ctx->gpr[5] = (u32)(s32)(3844);

label_800BD754:
    ctx->pc = 0x800BD754u;
    // 800BD754: stw     r11, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD758:
    ctx->pc = 0x800BD758u;
    // 800BD758: stw     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD75C:
    ctx->pc = 0x800BD75Cu;
    // 800BD75C: stw     r30, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BD760:
    ctx->pc = 0x800BD760u;
    // 800BD760: bl      0x800C3D88
    {
            ctx->lr = 0x800BD764u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BD764:
    ctx->pc = 0x800BD764u;
    ctx->downcount -= 19;
    // 800BD764: lwz     r11, 1420(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(1420);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD768:
    ctx->pc = 0x800BD768u;
    // 800BD768: addi    r9, r28, 1420
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(1420);

label_800BD76C:
    ctx->pc = 0x800BD76Cu;
    // 800BD76C: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD770:
    ctx->pc = 0x800BD770u;
    // 800BD770: addi    r7, r1, 24
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(24);

label_800BD774:
    ctx->pc = 0x800BD774u;
    // 800BD774: lwz     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BD778:
    ctx->pc = 0x800BD778u;
    // 800BD778: addi    r10, r28, 1432
    ctx->gpr[10] = ctx->gpr[28] + (u32)(s32)(1432);

label_800BD77C:
    ctx->pc = 0x800BD77Cu;
    // 800BD77C: stw     r11, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD780:
    ctx->pc = 0x800BD780u;
    // 800BD780: addi    r6, r1, 40
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(40);

label_800BD784:
    ctx->pc = 0x800BD784u;
    // 800BD784: stw     r0, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD788:
    ctx->pc = 0x800BD788u;
    // 800BD788: stw     r8, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BD78C:
    ctx->pc = 0x800BD78Cu;
    // 800BD78C: lwz     r9, 1432(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(1432);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD790:
    ctx->pc = 0x800BD790u;
    // 800BD790: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD794:
    ctx->pc = 0x800BD794u;
    // 800BD794: lwz     r11, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD798:
    ctx->pc = 0x800BD798u;
    // 800BD798: stw     r9, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD79C:
    ctx->pc = 0x800BD79Cu;
    // 800BD79C: stw     r0, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD7A0:
    ctx->pc = 0x800BD7A0u;
    // 800BD7A0: stw     r11, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD7A4:
    ctx->pc = 0x800BD7A4u;
    // 800BD7A4: lwz     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD7A8:
    ctx->pc = 0x800BD7A8u;
    // 800BD7A8: cmpw    r25, r0
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BD7AC:
    ctx->pc = 0x800BD7ACu;
    // 800BD7AC: bc    4, 0, 0x800BD954
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD954;
        }
    }

label_800BD7B0:
    ctx->pc = 0x800BD7B0u;
    ctx->downcount -= 18;
    // 800BD7B0: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BD7B4:
    ctx->pc = 0x800BD7B4u;
    // 800BD7B4: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BD7B8:
    ctx->pc = 0x800BD7B8u;
    // 800BD7B8: addi    r9, r9, -3152
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-3152);

label_800BD7BC:
    ctx->pc = 0x800BD7BCu;
    // 800BD7BC: lfd     f31, -15944(r11)
    if (!ppc_fp_available(ctx, 0x800BD7BCu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15944);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BD7C0:
    ctx->pc = 0x800BD7C0u;
    // 800BD7C0: addi    r23, r9, 4
    ctx->gpr[23] = ctx->gpr[9] + (u32)(s32)(4);

label_800BD7C4:
    ctx->pc = 0x800BD7C4u;
    // 800BD7C4: or   r21, r9, r9
    {
        ctx->gpr[21] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BD7C8:
    ctx->pc = 0x800BD7C8u;
    // 800BD7C8: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BD7CC:
    ctx->pc = 0x800BD7CCu;
    // 800BD7CC: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BD7D0:
    ctx->pc = 0x800BD7D0u;
    // 800BD7D0: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BD7D4:
    ctx->pc = 0x800BD7D4u;
    // 800BD7D4: or   r30, r31, r31
    {
        ctx->gpr[30] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BD7D8:
    ctx->pc = 0x800BD7D8u;
    // 800BD7D8: lfs     f29, -15936(r11)
    if (!ppc_fp_available(ctx, 0x800BD7D8u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15936);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[29] = value;
        ctx->ps1[29] = value;
    }

label_800BD7DC:
    ctx->pc = 0x800BD7DCu;
    // 800BD7DC: addi    r22, r9, -21636
    ctx->gpr[22] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BD7E0:
    ctx->pc = 0x800BD7E0u;
    // 800BD7E0: lfs     f30, -15932(r10)
    if (!ppc_fp_available(ctx, 0x800BD7E0u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-15932);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800BD7E4:
    ctx->pc = 0x800BD7E4u;
    // 800BD7E4: or   r26, r7, r7
    {
        ctx->gpr[26] = ctx->gpr[7] | ctx->gpr[7];
    }

label_800BD7E8:
    ctx->pc = 0x800BD7E8u;
    // 800BD7E8: or   r27, r6, r6
    {
        ctx->gpr[27] = ctx->gpr[6] | ctx->gpr[6];
    }

label_800BD7EC:
    ctx->pc = 0x800BD7ECu;
    // 800BD7EC: lis     r24, 17200
    ctx->gpr[24] = ((u32)(s32)(17200) << 16);

label_800BD7F0:
    ctx->pc = 0x800BD7F0u;
    // 800BD7F0: or   r29, r23, r23
    {
        ctx->gpr[29] = ctx->gpr[23] | ctx->gpr[23];
    }

label_800BD7F4:
    ctx->pc = 0x800BD7F4u;
    // 800BD7F4: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_800BD7F8:
    ctx->pc = 0x800BD7F8u;
    ctx->downcount -= 3;
    // 800BD7F8: lwz     r0, 48(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD7FC:
    // 800BD7FC: cmpw    r0, r25
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[25]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BD800:
    // 800BD800: bc    4, 2, 0x800BD8A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BD8A4;
        }
    }

label_800BD804:
    ctx->pc = 0x800BD804u;
    ctx->downcount -= 15;
    // 800BD804: lwz     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD808:
    // 800BD808: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BD80C:
    ctx->pc = 0x800BD80Cu;
    // 800BD80C: lwz     r11, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD810:
    // 800BD810: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD814:
    ctx->pc = 0x800BD814u;
    // 800BD814: lwz     r3, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BD818:
    // 800BD818: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_800BD81C:
    ctx->pc = 0x800BD81Cu;
    // 800BD81C: lwz     r5, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BD820:
    // 800BD820: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BD824:
    ctx->pc = 0x800BD824u;
    // 800BD824: stw     r0, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD828:
    // 800BD828: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BD82C:
    ctx->pc = 0x800BD82Cu;
    // 800BD82C: stw     r3, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BD830:
    // 800BD830: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BD834:
    ctx->pc = 0x800BD834u;
    // 800BD834: stw     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD838:
    // 800BD838: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BD83C:
    // 800BD83C: bl      0x800C3D88
    {
            ctx->lr = 0x800BD840u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BD840:
    ctx->downcount -= 24;
    // 800BD840: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_800BD844:
    ctx->pc = 0x800BD844u;
    // 800BD844: stw     r3, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BD848:
    // 800BD848: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BD84C:
    ctx->pc = 0x800BD84Cu;
    // 800BD84C: lwz     r11, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD850:
    // 800BD850: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BD854:
    ctx->pc = 0x800BD854u;
    // 800BD854: stw     r24, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_800BD858:
    // 800BD858: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD85C:
    ctx->pc = 0x800BD85Cu;
    // 800BD85C: lwz     r0, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD860:
    // 800BD860: ori     r6, r6, 0x8008
    ctx->gpr[6] = ctx->gpr[6] | 0x8008u;

label_800BD864:
    ctx->pc = 0x800BD864u;
    // 800BD864: lfd     f0, 80(r1)
    if (!ppc_fp_available(ctx, 0x800BD864u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BD868:
    // 800BD868: li      r7, 250
    ctx->gpr[7] = (u32)(s32)(250);

label_800BD86C:
    ctx->pc = 0x800BD86Cu;
    // 800BD86C: lwz     r5, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BD870:
    // 800BD870: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BD874:
    ctx->pc = 0x800BD874u;
    // 800BD874: fsub   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BD874u)) return;
    ppc_fsub(ctx, 0, 0, 31);

label_800BD878:
    ctx->pc = 0x800BD878u;
    // 800BD878: stw     r11, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD87C:
    ctx->pc = 0x800BD87Cu;
    // 800BD87C: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x800BD87Cu)) return;
    ppc_frsp(ctx, 0, 0);

label_800BD880:
    ctx->pc = 0x800BD880u;
    // 800BD880: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD884:
    ctx->pc = 0x800BD884u;
    // 800BD884: fadds   f0, f0, f29
    if (!ppc_fp_available(ctx, 0x800BD884u)) return;
    ppc_fadds(ctx, 0, 0, 29);

label_800BD888:
    // 800BD888: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BD88C:
    ctx->pc = 0x800BD88Cu;
    // 800BD88C: stfs     f0, 28(r1)
    if (!ppc_fp_available(ctx, 0x800BD88Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD890:
    // 800BD890: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BD894:
    ctx->pc = 0x800BD894u;
    // 800BD894: lwz     r0, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD898:
    ctx->pc = 0x800BD898u;
    // 800BD898: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD89C:
    // 800BD89C: bl      0x800C3D88
    {
            ctx->lr = 0x800BD8A0u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BD8A0:
    ctx->downcount -= 1;
    // 800BD8A0: b       0x800BD93C
    {
            goto label_800BD93C;
    }

label_800BD8A4:
    ctx->pc = 0x800BD8A4u;
    ctx->downcount -= 4;
    // 800BD8A4: lhz     r0, 972(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(972);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_800BD8A8:
    ctx->pc = 0x800BD8A8u;
    // 800BD8A8: lwzx    r9, r21, r31
    {
        u32 ea = ctx->gpr[21] + ctx->gpr[31];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD8AC:
    // 800BD8AC: and.   r11, r0, r9
    {
        ctx->gpr[11] = ctx->gpr[0] & ctx->gpr[9];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD8B0:
    // 800BD8B0: bc    12, 2, 0x800BD93C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD93C;
        }
    }

label_800BD8B4:
    ctx->pc = 0x800BD8B4u;
    ctx->downcount -= 3;
    // 800BD8B4: lwz     r0, 40(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD8B8:
    // 800BD8B8: and.   r11, r0, r9
    {
        ctx->gpr[11] = ctx->gpr[0] & ctx->gpr[9];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[11];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD8BC:
    // 800BD8BC: bc    12, 2, 0x800BD8E0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD8E0;
        }
    }

label_800BD8C0:
    ctx->pc = 0x800BD8C0u;
    ctx->downcount -= 8;
    // 800BD8C0: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD8C4:
    // 800BD8C4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BD8C8:
    ctx->pc = 0x800BD8C8u;
    // 800BD8C8: lwz     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD8CC:
    // 800BD8CC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD8D0:
    ctx->pc = 0x800BD8D0u;
    // 800BD8D0: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD8D4:
    // 800BD8D4: li      r6, 40
    ctx->gpr[6] = (u32)(s32)(40);

label_800BD8D8:
    ctx->pc = 0x800BD8D8u;
    // 800BD8D8: lwz     r5, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BD8DC:
    // 800BD8DC: b       0x800BD8FC
    {
            goto label_800BD8FC;
    }

label_800BD8E0:
    ctx->pc = 0x800BD8E0u;
    ctx->downcount -= 7;
    // 800BD8E0: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD8E4:
    // 800BD8E4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BD8E8:
    ctx->pc = 0x800BD8E8u;
    // 800BD8E8: lwz     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BD8EC:
    // 800BD8EC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BD8F0:
    ctx->pc = 0x800BD8F0u;
    // 800BD8F0: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BD8F4:
    // 800BD8F4: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_800BD8F8:
    ctx->pc = 0x800BD8F8u;
    // 800BD8F8: lwzx    r5, r23, r31
    {
        u32 ea = ctx->gpr[23] + ctx->gpr[31];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BD8FC:
    ctx->downcount -= 8;
    // 800BD8FC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BD900:
    ctx->pc = 0x800BD900u;
    // 800BD900: stw     r0, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BD904:
    // 800BD904: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BD908:
    ctx->pc = 0x800BD908u;
    // 800BD908: stw     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BD90C:
    // 800BD90C: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BD910:
    // 800BD910: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BD914:
    ctx->pc = 0x800BD914u;
    // 800BD914: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BD918:
    // 800BD918: bl      0x800C3D88
    {
            ctx->lr = 0x800BD91Cu;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BD91C:
    ctx->downcount -= 8;
    // 800BD91C: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_800BD920:
    ctx->pc = 0x800BD920u;
    // 800BD920: stw     r3, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BD924:
    ctx->pc = 0x800BD924u;
    // 800BD924: stw     r24, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_800BD928:
    ctx->pc = 0x800BD928u;
    // 800BD928: lfd     f0, 80(r1)
    if (!ppc_fp_available(ctx, 0x800BD928u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BD92C:
    ctx->pc = 0x800BD92Cu;
    // 800BD92C: fsub   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BD92Cu)) return;
    ppc_fsub(ctx, 0, 0, 31);

label_800BD930:
    ctx->pc = 0x800BD930u;
    // 800BD930: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x800BD930u)) return;
    ppc_frsp(ctx, 0, 0);

label_800BD934:
    ctx->pc = 0x800BD934u;
    // 800BD934: fadds   f0, f0, f30
    if (!ppc_fp_available(ctx, 0x800BD934u)) return;
    ppc_fadds(ctx, 0, 0, 30);

label_800BD938:
    ctx->pc = 0x800BD938u;
    // 800BD938: stfs     f0, 44(r1)
    if (!ppc_fp_available(ctx, 0x800BD938u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BD93C:
    ctx->pc = 0x800BD93Cu;
    ctx->downcount -= 6;
    // 800BD93C: lwz     r0, 52(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD940:
    // 800BD940: addi    r25, r25, 1
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(1);

label_800BD944:
    // 800BD944: addi    r29, r29, 16
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(16);

label_800BD948:
    // 800BD948: addi    r31, r31, 16
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(16);

label_800BD94C:
    // 800BD94C: cmpw    r25, r0
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BD950:
    // 800BD950: bc    12, 0, 0x800BD7F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BD7F8u;
                return;
            }
            goto label_800BD7F8;
        }
    }

label_800BD954:
    ctx->pc = 0x800BD954u;
    ctx->downcount -= 2;
    // 800BD954: lwz     r3, 20(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(20);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BD958:
    ctx->pc = 0x800BD958u;
    // 800BD958: bl      0x800C473C
    {
            ctx->lr = 0x800BD95Cu;
            ctx->pc = 0x800C473Cu;
            return;
    }

label_800BD95C:
    ctx->pc = 0x800BD95Cu;
    ctx->downcount -= 19;
    // 800BD95C: lwz     r0, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD960:
    ctx->pc = 0x800BD960u;
    // 800BD960: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BD964:
    ctx->pc = 0x800BD964u;
    // 800BD964: lmw     r21, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        for (u32 r = 21; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BD968:
    ctx->pc = 0x800BD968u;
    // 800BD968: lfd     f29, 136(r1)
    if (!ppc_fp_available(ctx, 0x800BD968u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->fpr[29] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BD96C:
    ctx->pc = 0x800BD96Cu;
    // 800BD96C: lfd     f30, 144(r1)
    if (!ppc_fp_available(ctx, 0x800BD96Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BD970:
    ctx->pc = 0x800BD970u;
    // 800BD970: lfd     f31, 152(r1)
    if (!ppc_fp_available(ctx, 0x800BD970u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BD974:
    ctx->pc = 0x800BD974u;
    // 800BD974: addi    r1, r1, 160
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(160);

label_800BD978:
    ctx->pc = 0x800BD978u;
    // 800BD978: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD97C:
    ctx->pc = 0x800BD97Cu;
    ctx->downcount -= 5;
    // 800BD97C: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BD980:
    ctx->pc = 0x800BD980u;
    // 800BD980: addi    r9, r9, -3152
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-3152);

label_800BD984:
    ctx->pc = 0x800BD984u;
    // 800BD984: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD988:
    ctx->pc = 0x800BD988u;
    // 800BD988: cmpwi   r0, -1
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

label_800BD98C:
    ctx->pc = 0x800BD98Cu;
    // 800BD98C: bc    12, 2, 0x800BD9C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD9C0;
        }
    }

label_800BD990:
    ctx->pc = 0x800BD990u;
    ctx->downcount -= 2;
    // 800BD990: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800BD994:
    ctx->pc = 0x800BD994u;
    // 800BD994: addi    r3, r9, 4
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(4);

label_800BD998:
    ctx->pc = 0x800BD998u;
    ctx->downcount -= 3;
    // 800BD998: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD99C:
    // 800BD99C: and.   r10, r0, r4
    {
        ctx->gpr[10] = ctx->gpr[0] & ctx->gpr[4];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[10];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD9A0:
    // 800BD9A0: bc    12, 2, 0x800BD9AC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD9AC;
        }
    }

label_800BD9A4:
    ctx->pc = 0x800BD9A4u;
    ctx->downcount -= 2;
    // 800BD9A4: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BD9A8:
    ctx->pc = 0x800BD9A8u;
    // 800BD9A8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD9AC:
    ctx->downcount -= 5;
    // 800BD9AC: addi    r11, r11, 16
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(16);

label_800BD9B0:
    // 800BD9B0: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_800BD9B4:
    ctx->pc = 0x800BD9B4u;
    // 800BD9B4: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD9B8:
    // 800BD9B8: cmpwi   r0, -1
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

label_800BD9BC:
    // 800BD9BC: bc    4, 2, 0x800BD998
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BD998u;
                return;
            }
            goto label_800BD998;
        }
    }

label_800BD9C0:
    ctx->pc = 0x800BD9C0u;
    ctx->downcount -= 2;
    // 800BD9C0: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_800BD9C4:
    ctx->pc = 0x800BD9C4u;
    // 800BD9C4: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD9C8:
    ctx->pc = 0x800BD9C8u;
    ctx->downcount -= 6;
    // 800BD9C8: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BD9CC:
    ctx->pc = 0x800BD9CCu;
    // 800BD9CC: or   r10, r3, r3
    {
        ctx->gpr[10] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BD9D0:
    ctx->pc = 0x800BD9D0u;
    // 800BD9D0: addi    r9, r9, -3152
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-3152);

label_800BD9D4:
    ctx->pc = 0x800BD9D4u;
    // 800BD9D4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD9D8:
    ctx->pc = 0x800BD9D8u;
    // 800BD9D8: cmpwi   r0, -1
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

label_800BD9DC:
    ctx->pc = 0x800BD9DCu;
    // 800BD9DC: bc    12, 2, 0x800BDA10
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDA10;
        }
    }

label_800BD9E0:
    ctx->pc = 0x800BD9E0u;
    ctx->downcount -= 2;
    // 800BD9E0: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800BD9E4:
    ctx->pc = 0x800BD9E4u;
    // 800BD9E4: addi    r3, r9, 12
    ctx->gpr[3] = ctx->gpr[9] + (u32)(s32)(12);

label_800BD9E8:
    ctx->pc = 0x800BD9E8u;
    ctx->downcount -= 3;
    // 800BD9E8: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BD9EC:
    // 800BD9EC: and.   r8, r0, r10
    {
        ctx->gpr[8] = ctx->gpr[0] & ctx->gpr[10];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[8];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BD9F0:
    // 800BD9F0: bc    12, 2, 0x800BD9FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BD9FC;
        }
    }

label_800BD9F4:
    ctx->pc = 0x800BD9F4u;
    ctx->downcount -= 2;
    // 800BD9F4: lwz     r3, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BD9F8:
    ctx->pc = 0x800BD9F8u;
    // 800BD9F8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BD9FC:
    ctx->downcount -= 5;
    // 800BD9FC: addi    r11, r11, 16
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(16);

label_800BDA00:
    // 800BDA00: addi    r3, r3, 16
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(16);

label_800BDA04:
    ctx->pc = 0x800BDA04u;
    // 800BDA04: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDA08:
    // 800BDA08: cmpwi   r0, -1
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

label_800BDA0C:
    // 800BDA0C: bc    4, 2, 0x800BD9E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BD9E8u;
                return;
            }
            goto label_800BD9E8;
        }
    }

label_800BDA10:
    ctx->pc = 0x800BDA10u;
    ctx->downcount -= 2;
    // 800BDA10: li      r3, -1
    ctx->gpr[3] = (u32)(s32)(-1);

label_800BDA14:
    ctx->pc = 0x800BDA14u;
    // 800BDA14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDA18:
    ctx->pc = 0x800BDA18u;
    ctx->downcount -= 22;
    // 800BDA18: stwu     r1, -64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-64);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BDA1C:
    ctx->pc = 0x800BDA1Cu;
    // 800BDA1C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BDA20:
    ctx->pc = 0x800BDA20u;
    // 800BDA20: stmw     r27, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 27; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BDA24:
    ctx->pc = 0x800BDA24u;
    // 800BDA24: stw     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDA28:
    ctx->pc = 0x800BDA28u;
    // 800BDA28: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BDA2C:
    ctx->pc = 0x800BDA2Cu;
    // 800BDA2C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_800BDA30:
    ctx->pc = 0x800BDA30u;
    // 800BDA30: lwz     r0, -21632(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21632);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDA34:
    ctx->pc = 0x800BDA34u;
    // 800BDA34: or.   r29, r3, r3
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

label_800BDA38:
    ctx->pc = 0x800BDA38u;
    // 800BDA38: rlwinm r9, r0, 1, 31, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
    }

label_800BDA3C:
    ctx->pc = 0x800BDA3Cu;
    // 800BDA3C: add   r0, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800BDA40:
    ctx->pc = 0x800BDA40u;
    // 800BDA40: srawi r28, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[28] = value;
        } else if (sh > 31) {
            ctx->gpr[28] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[28] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800BDA44:
    ctx->pc = 0x800BDA44u;
    // 800BDA44: bc    12, 2, 0x800BDB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDB88;
        }
    }

label_800BDA48:
    ctx->pc = 0x800BDA48u;
    ctx->downcount -= 4;
    // 800BDA48: lwz     r3, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BDA4C:
    ctx->pc = 0x800BDA4Cu;
    // 800BDA4C: lis     r4, 20992
    ctx->gpr[4] = ((u32)(s32)(20992) << 16);

label_800BDA50:
    ctx->pc = 0x800BDA50u;
    // 800BDA50: ori     r4, r4, 0x0129
    ctx->gpr[4] = ctx->gpr[4] | 0x0129u;

label_800BDA54:
    ctx->pc = 0x800BDA54u;
    // 800BDA54: bl      0x80047634
    {
            ctx->lr = 0x800BDA58u;
            ctx->pc = 0x80047634u;
            return;
    }

label_800BDA58:
    ctx->pc = 0x800BDA58u;
    ctx->downcount -= 2;
    // 800BDA58: or.   r27, r3, r3
    {
        ctx->gpr[27] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[27];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BDA5C:
    ctx->pc = 0x800BDA5Cu;
    // 800BDA5C: bc    12, 2, 0x800BDB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDB88;
        }
    }

label_800BDA60:
    ctx->pc = 0x800BDA60u;
    ctx->downcount -= 6;
    // 800BDA60: stw     r31, 48(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800BDA64:
    ctx->pc = 0x800BDA64u;
    // 800BDA64: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BDA68:
    ctx->pc = 0x800BDA68u;
    // 800BDA68: addi    r11, r9, -2960
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-2960);

label_800BDA6C:
    ctx->pc = 0x800BDA6Cu;
    // 800BDA6C: lwz     r0, -2960(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-2960);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDA70:
    ctx->pc = 0x800BDA70u;
    // 800BDA70: cmpwi   r0, 0
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

label_800BDA74:
    ctx->pc = 0x800BDA74u;
    // 800BDA74: bc    12, 2, 0x800BDA8C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDA8C;
        }
    }

label_800BDA78:
    ctx->pc = 0x800BDA78u;
    ctx->downcount -= 1;
    // 800BDA78: or   r9, r11, r11
    {
        ctx->gpr[9] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BDA7C:
    loop_800BDA7C(ctx);
    if (ctx->pc == 0x800BDA8Cu) goto label_800BDA8C;
    return;
label_800BDA80:
    // 800BDA80: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_800BDA84:
    // 800BDA84: cmpwi   r0, 0
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

label_800BDA88:
    // 800BDA88: bc    4, 2, 0x800BDA7C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BDA7Cu;
                return;
            }
            goto label_800BDA7C;
        }
    }

label_800BDA8C:
    ctx->pc = 0x800BDA8Cu;
    ctx->downcount -= 5;
    // 800BDA8C: stw     r31, 52(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800BDA90:
    ctx->pc = 0x800BDA90u;
    // 800BDA90: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BDA94:
    ctx->pc = 0x800BDA94u;
    // 800BDA94: addi    r30, r9, -2960
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-2960);

label_800BDA98:
    ctx->pc = 0x800BDA98u;
    // 800BDA98: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_800BDA9C:
    ctx->pc = 0x800BDA9Cu;
    // 800BDA9C: b       0x800BDAA8
    {
            goto label_800BDAA8;
    }

label_800BDAA0:
    ctx->downcount -= 2;
    // 800BDAA0: addi    r30, r30, 16
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(16);

label_800BDAA4:
    // 800BDAA4: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_800BDAA8:
    ctx->pc = 0x800BDAA8u;
    ctx->downcount -= 3;
    // 800BDAA8: lwz     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDAAC:
    // 800BDAAC: cmpwi   r0, 0
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

label_800BDAB0:
    // 800BDAB0: bc    12, 2, 0x800BDAD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDAD8;
        }
    }

label_800BDAB4:
    ctx->pc = 0x800BDAB4u;
    ctx->downcount -= 3;
    // 800BDAB4: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDAB8:
    // 800BDAB8: cmpwi   r0, 0
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

label_800BDABC:
    // 800BDABC: bc    12, 2, 0x800BDAD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDAD4;
        }
    }

label_800BDAC0:
    ctx->downcount -= 4;
    // 800BDAC0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BDAC4:
    ctx->pc = 0x800BDAC4u;
    // 800BDAC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDAC8:
    ctx->pc = 0x800BDAC8u;
    // 800BDAC8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800BDACCu;
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDACC:
    ctx->downcount -= 2;
    // 800BDACC: cmpwi   r3, 0
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

label_800BDAD0:
    // 800BDAD0: bc    12, 2, 0x800BDAA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BDAA0u;
                return;
            }
            goto label_800BDAA0;
        }
    }

label_800BDAD4:
    ctx->pc = 0x800BDAD4u;
    ctx->downcount -= 1;
    // 800BDAD4: stw     r31, 48(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800BDAD8:
    ctx->pc = 0x800BDAD8u;
    ctx->downcount -= 7;
    // 800BDAD8: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BDADC:
    ctx->pc = 0x800BDADCu;
    // 800BDADC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BDAE0:
    ctx->pc = 0x800BDAE0u;
    // 800BDAE0: ori     r4, r4, 0x00B8
    ctx->gpr[4] = ctx->gpr[4] | 0x00B8u;

label_800BDAE4:
    ctx->pc = 0x800BDAE4u;
    // 800BDAE4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BDAE8:
    ctx->pc = 0x800BDAE8u;
    // 800BDAE8: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_800BDAEC:
    ctx->pc = 0x800BDAECu;
    // 800BDAEC: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BDAF0:
    ctx->pc = 0x800BDAF0u;
    // 800BDAF0: bl      0x800303A8
    {
            ctx->lr = 0x800BDAF4u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BDAF4:
    ctx->pc = 0x800BDAF4u;
    ctx->downcount -= 2;
    // 800BDAF4: cmpwi   r3, 0
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

label_800BDAF8:
    ctx->pc = 0x800BDAF8u;
    // 800BDAF8: bc    12, 2, 0x800BDB30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDB30;
        }
    }

label_800BDAFC:
    ctx->pc = 0x800BDAFCu;
    ctx->downcount -= 6;
    // 800BDAFC: addi    r30, r1, 24
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(24);

label_800BDB00:
    ctx->pc = 0x800BDB00u;
    // 800BDB00: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_800BDB04:
    ctx->pc = 0x800BDB04u;
    // 800BDB04: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BDB08:
    ctx->pc = 0x800BDB08u;
    // 800BDB08: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BDB0C:
    ctx->pc = 0x800BDB0Cu;
    // 800BDB0C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BDB10:
    ctx->pc = 0x800BDB10u;
    // 800BDB10: bl      0x800C48AC
    {
            ctx->lr = 0x800BDB14u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BDB14:
    ctx->pc = 0x800BDB14u;
    ctx->downcount -= 7;
    // 800BDB14: lwz     r10, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BDB18:
    ctx->pc = 0x800BDB18u;
    // 800BDB18: addi    r11, r29, 1420
    ctx->gpr[11] = ctx->gpr[29] + (u32)(s32)(1420);

label_800BDB1C:
    ctx->pc = 0x800BDB1Cu;
    // 800BDB1C: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDB20:
    ctx->pc = 0x800BDB20u;
    // 800BDB20: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BDB24:
    ctx->pc = 0x800BDB24u;
    // 800BDB24: stw     r10, 1420(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1420);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BDB28:
    ctx->pc = 0x800BDB28u;
    // 800BDB28: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDB2C:
    ctx->pc = 0x800BDB2Cu;
    // 800BDB2C: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BDB30:
    ctx->pc = 0x800BDB30u;
    ctx->downcount -= 7;
    // 800BDB30: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BDB34:
    ctx->pc = 0x800BDB34u;
    // 800BDB34: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BDB38:
    ctx->pc = 0x800BDB38u;
    // 800BDB38: ori     r4, r4, 0x00BE
    ctx->gpr[4] = ctx->gpr[4] | 0x00BEu;

label_800BDB3C:
    ctx->pc = 0x800BDB3Cu;
    // 800BDB3C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BDB40:
    ctx->pc = 0x800BDB40u;
    // 800BDB40: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_800BDB44:
    ctx->pc = 0x800BDB44u;
    // 800BDB44: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BDB48:
    ctx->pc = 0x800BDB48u;
    // 800BDB48: bl      0x800303A8
    {
            ctx->lr = 0x800BDB4Cu;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BDB4C:
    ctx->pc = 0x800BDB4Cu;
    ctx->downcount -= 2;
    // 800BDB4C: cmpwi   r3, 0
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

label_800BDB50:
    ctx->pc = 0x800BDB50u;
    // 800BDB50: bc    12, 2, 0x800BDB88
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDB88;
        }
    }

label_800BDB54:
    ctx->pc = 0x800BDB54u;
    ctx->downcount -= 6;
    // 800BDB54: addi    r30, r1, 24
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(24);

label_800BDB58:
    ctx->pc = 0x800BDB58u;
    // 800BDB58: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_800BDB5C:
    ctx->pc = 0x800BDB5Cu;
    // 800BDB5C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BDB60:
    ctx->pc = 0x800BDB60u;
    // 800BDB60: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BDB64:
    ctx->pc = 0x800BDB64u;
    // 800BDB64: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BDB68:
    ctx->pc = 0x800BDB68u;
    // 800BDB68: bl      0x800C48AC
    {
            ctx->lr = 0x800BDB6Cu;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BDB6C:
    ctx->pc = 0x800BDB6Cu;
    ctx->downcount -= 7;
    // 800BDB6C: lwz     r10, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BDB70:
    ctx->pc = 0x800BDB70u;
    // 800BDB70: addi    r11, r29, 1432
    ctx->gpr[11] = ctx->gpr[29] + (u32)(s32)(1432);

label_800BDB74:
    ctx->pc = 0x800BDB74u;
    // 800BDB74: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDB78:
    ctx->pc = 0x800BDB78u;
    // 800BDB78: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BDB7C:
    ctx->pc = 0x800BDB7Cu;
    // 800BDB7C: stw     r10, 1432(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1432);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BDB80:
    ctx->pc = 0x800BDB80u;
    // 800BDB80: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDB84:
    ctx->pc = 0x800BDB84u;
    // 800BDB84: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BDB88:
    ctx->pc = 0x800BDB88u;
    ctx->downcount -= 16;
    // 800BDB88: lwz     r0, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDB8C:
    ctx->pc = 0x800BDB8Cu;
    // 800BDB8C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDB90:
    ctx->pc = 0x800BDB90u;
    // 800BDB90: lmw     r27, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        for (u32 r = 27; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BDB94:
    ctx->pc = 0x800BDB94u;
    // 800BDB94: addi    r1, r1, 64
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(64);

label_800BDB98:
    ctx->pc = 0x800BDB98u;
    // 800BDB98: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDB9C:
    ctx->pc = 0x800BDB9Cu;
    ctx->downcount -= 5;
    // 800BDB9C: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BDBA0:
    ctx->pc = 0x800BDBA0u;
    // 800BDBA0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BDBA4:
    ctx->pc = 0x800BDBA4u;
    // 800BDBA4: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDBA8:
    ctx->pc = 0x800BDBA8u;
    // 800BDBA8: or.   r3, r3, r3
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

label_800BDBAC:
    ctx->pc = 0x800BDBACu;
    // 800BDBAC: bc    12, 2, 0x800BDBEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDBEC;
        }
    }

label_800BDBB0:
    ctx->pc = 0x800BDBB0u;
    ctx->downcount -= 3;
    // 800BDBB0: lwz     r0, 60(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(60);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDBB4:
    ctx->pc = 0x800BDBB4u;
    // 800BDBB4: cmpwi   r0, 12
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

label_800BDBB8:
    ctx->pc = 0x800BDBB8u;
    // 800BDBB8: bc    4, 2, 0x800BDBEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BDBEC;
        }
    }

label_800BDBBC:
    ctx->pc = 0x800BDBBCu;
    ctx->downcount -= 8;
    // 800BDBBC: lwz     r0, 48(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDBC0:
    ctx->pc = 0x800BDBC0u;
    // 800BDBC0: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BDBC4:
    ctx->pc = 0x800BDBC4u;
    // 800BDBC4: addi    r11, r9, -2960
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-2960);

label_800BDBC8:
    ctx->pc = 0x800BDBC8u;
    // 800BDBC8: rlwinm r3, r0, 4, 0, 27
    {
        ctx->gpr[3] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_800BDBCC:
    ctx->pc = 0x800BDBCCu;
    // 800BDBCC: addi    r9, r11, 12
    ctx->gpr[9] = ctx->gpr[11] + (u32)(s32)(12);

label_800BDBD0:
    ctx->pc = 0x800BDBD0u;
    // 800BDBD0: lwzx    r0, r9, r3
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[3];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDBD4:
    ctx->pc = 0x800BDBD4u;
    // 800BDBD4: cmpwi   r0, 0
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

label_800BDBD8:
    ctx->pc = 0x800BDBD8u;
    // 800BDBD8: bc    12, 2, 0x800BDBEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDBEC;
        }
    }

label_800BDBDC:
    ctx->pc = 0x800BDBDCu;
    ctx->downcount -= 5;
    // 800BDBDC: add   r9, r3, r11
    {
        u32 a = ctx->gpr[3];
        u32 b = ctx->gpr[11];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BDBE0:
    ctx->pc = 0x800BDBE0u;
    // 800BDBE0: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDBE4:
    ctx->pc = 0x800BDBE4u;
    // 800BDBE4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDBE8:
    ctx->pc = 0x800BDBE8u;
    // 800BDBE8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800BDBECu;
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDBEC:
    ctx->pc = 0x800BDBECu;
    ctx->downcount -= 5;
    // 800BDBEC: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDBF0:
    ctx->pc = 0x800BDBF0u;
    // 800BDBF0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDBF4:
    ctx->pc = 0x800BDBF4u;
    // 800BDBF4: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BDBF8:
    ctx->pc = 0x800BDBF8u;
    // 800BDBF8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDBFC:
    ctx->pc = 0x800BDBFCu;
    ctx->downcount -= 2;
    // 800BDBFC: or.   r3, r3, r3
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

label_800BDC00:
    ctx->pc = 0x800BDC00u;
    // 800BDC00: bclr  12, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDC04:
    ctx->pc = 0x800BDC04u;
    ctx->downcount -= 5;
    // 800BDC04: li      r9, 4
    ctx->gpr[9] = (u32)(s32)(4);

label_800BDC08:
    ctx->pc = 0x800BDC08u;
    // 800BDC08: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_800BDC0C:
    ctx->pc = 0x800BDC0Cu;
    // 800BDC0C: stw     r0, 36(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDC10:
    ctx->pc = 0x800BDC10u;
    // 800BDC10: stw     r9, 28(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BDC14:
    ctx->pc = 0x800BDC14u;
    // 800BDC14: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDC18:
    ctx->pc = 0x800BDC18u;
    ctx->downcount -= 30;
    // 800BDC18: stwu     r1, -40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-40);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BDC1C:
    ctx->pc = 0x800BDC1Cu;
    // 800BDC1C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BDC20:
    ctx->pc = 0x800BDC20u;
    // 800BDC20: stmw     r24, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 24; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BDC24:
    ctx->pc = 0x800BDC24u;
    // 800BDC24: stw     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDC28:
    ctx->pc = 0x800BDC28u;
    // 800BDC28: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BDC2C:
    ctx->pc = 0x800BDC2Cu;
    // 800BDC2C: lis     r10, -32699
    ctx->gpr[10] = ((u32)(s32)(-32699) << 16);

label_800BDC30:
    ctx->pc = 0x800BDC30u;
    // 800BDC30: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BDC34:
    ctx->pc = 0x800BDC34u;
    // 800BDC34: lwz     r11, -21632(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-21632);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BDC38:
    ctx->pc = 0x800BDC38u;
    // 800BDC38: lwz     r7, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800BDC3C:
    ctx->pc = 0x800BDC3Cu;
    // 800BDC3C: lis     r10, 16
    ctx->gpr[10] = ((u32)(s32)(16) << 16);

label_800BDC40:
    ctx->pc = 0x800BDC40u;
    // 800BDC40: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDC44:
    ctx->pc = 0x800BDC44u;
    // 800BDC44: rlwinm r8, r11, 1, 31, 31
    {
        ctx->gpr[8] = dolrecomp_rotl32(ctx->gpr[11], 1u) & 0x00000001u;
    }

label_800BDC48:
    ctx->pc = 0x800BDC48u;
    // 800BDC48: ori     r10, r10, 0x0001
    ctx->gpr[10] = ctx->gpr[10] | 0x0001u;

label_800BDC4C:
    ctx->pc = 0x800BDC4Cu;
    // 800BDC4C: add   r11, r11, r8
    {
        u32 a = ctx->gpr[11];
        u32 b = ctx->gpr[8];
        u32 res = a + b;
        ctx->gpr[11] = res;
    }

label_800BDC50:
    ctx->pc = 0x800BDC50u;
    // 800BDC50: xor   r0, r0, r7
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[7];
    }

label_800BDC54:
    ctx->pc = 0x800BDC54u;
    // 800BDC54: srawi r25, r11, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[11];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[25] = value;
        } else if (sh > 31) {
            ctx->gpr[25] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[25] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800BDC58:
    ctx->pc = 0x800BDC58u;
    // 800BDC58: and   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[10];
    }

label_800BDC5C:
    ctx->pc = 0x800BDC5Cu;
    // 800BDC5C: or   r26, r3, r3
    {
        ctx->gpr[26] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BDC60:
    ctx->pc = 0x800BDC60u;
    // 800BDC60: and.   r9, r0, r7
    {
        ctx->gpr[9] = ctx->gpr[0] & ctx->gpr[7];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BDC64:
    ctx->pc = 0x800BDC64u;
    // 800BDC64: bc    12, 2, 0x800BDD08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDD08;
        }
    }

label_800BDC68:
    ctx->pc = 0x800BDC68u;
    ctx->downcount -= 3;
    // 800BDC68: lwz     r9, 48(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(48);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BDC6C:
    ctx->pc = 0x800BDC6Cu;
    // 800BDC6C: cmpwi   r9, 0
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

label_800BDC70:
    ctx->pc = 0x800BDC70u;
    // 800BDC70: bc    4, 1, 0x800BDD08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BDD08;
        }
    }

label_800BDC74:
    ctx->pc = 0x800BDC74u;
    ctx->downcount -= 4;
    // 800BDC74: addi    r30, r9, -1
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-1);

label_800BDC78:
    ctx->pc = 0x800BDC78u;
    // 800BDC78: lis     r24, -32734
    ctx->gpr[24] = ((u32)(s32)(-32734) << 16);

label_800BDC7C:
    ctx->pc = 0x800BDC7Cu;
    // 800BDC7C: rlwinm r29, r30, 4, 0, 27
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[30], 4u) & 0xFFFFFFF0u;
    }

label_800BDC80:
    ctx->pc = 0x800BDC80u;
    // 800BDC80: b       0x800BDC8C
    {
            goto label_800BDC8C;
    }

label_800BDC84:
    ctx->downcount -= 2;
    // 800BDC84: addi    r29, r31, -16
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(-16);

label_800BDC88:
    // 800BDC88: addi    r30, r30, -1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-1);

label_800BDC8C:
    ctx->downcount -= 2;
    // 800BDC8C: cmpwi   r30, 0
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

label_800BDC90:
    // 800BDC90: bc    12, 0, 0x800BDD08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDD08;
        }
    }

label_800BDC94:
    ctx->downcount -= 6;
    // 800BDC94: addi    r27, r24, -2960
    ctx->gpr[27] = ctx->gpr[24] + (u32)(s32)(-2960);

label_800BDC98:
    // 800BDC98: or   r31, r29, r29
    {
        ctx->gpr[31] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BDC9C:
    // 800BDC9C: addi    r28, r27, 8
    ctx->gpr[28] = ctx->gpr[27] + (u32)(s32)(8);

label_800BDCA0:
    ctx->pc = 0x800BDCA0u;
    // 800BDCA0: lwzx    r0, r28, r31
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[31];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDCA4:
    // 800BDCA4: cmpwi   r0, 0
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

label_800BDCA8:
    // 800BDCA8: bc    12, 2, 0x800BDCC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDCC8;
        }
    }

label_800BDCAC:
    ctx->downcount -= 6;
    // 800BDCAC: add   r9, r31, r27
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BDCB0:
    // 800BDCB0: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BDCB4:
    ctx->pc = 0x800BDCB4u;
    // 800BDCB4: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDCB8:
    ctx->pc = 0x800BDCB8u;
    // 800BDCB8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDCBC:
    ctx->pc = 0x800BDCBCu;
    // 800BDCBC: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800BDCC0u;
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDCC0:
    ctx->downcount -= 2;
    // 800BDCC0: cmpwi   r3, 0
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

label_800BDCC4:
    // 800BDCC4: bc    12, 2, 0x800BDC84
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BDC84u;
                return;
            }
            goto label_800BDC84;
        }
    }

label_800BDCC8:
    ctx->pc = 0x800BDCC8u;
    ctx->downcount -= 3;
    // 800BDCC8: lwzx    r0, r28, r29
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[29];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDCCC:
    ctx->pc = 0x800BDCCCu;
    // 800BDCCC: cmpwi   r0, 0
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

label_800BDCD0:
    ctx->pc = 0x800BDCD0u;
    // 800BDCD0: bc    12, 2, 0x800BDCF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDCF0;
        }
    }

label_800BDCD4:
    ctx->pc = 0x800BDCD4u;
    ctx->downcount -= 6;
    // 800BDCD4: add   r9, r29, r27
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[27];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BDCD8:
    ctx->pc = 0x800BDCD8u;
    // 800BDCD8: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BDCDC:
    ctx->pc = 0x800BDCDCu;
    // 800BDCDC: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDCE0:
    ctx->pc = 0x800BDCE0u;
    // 800BDCE0: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDCE4:
    ctx->pc = 0x800BDCE4u;
    // 800BDCE4: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800BDCE8u;
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDCE8:
    ctx->pc = 0x800BDCE8u;
    ctx->downcount -= 2;
    // 800BDCE8: cmpwi   r3, 0
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

label_800BDCEC:
    ctx->pc = 0x800BDCECu;
    // 800BDCEC: bc    12, 2, 0x800BDCF4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDCF4;
        }
    }

label_800BDCF0:
    ctx->pc = 0x800BDCF0u;
    ctx->downcount -= 1;
    // 800BDCF0: stw     r30, 48(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BDCF4:
    ctx->pc = 0x800BDCF4u;
    ctx->downcount -= 5;
    // 800BDCF4: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BDCF8:
    ctx->pc = 0x800BDCF8u;
    // 800BDCF8: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BDCFC:
    ctx->pc = 0x800BDCFCu;
    // 800BDCFC: lfs     f1, -15928(r9)
    if (!ppc_fp_available(ctx, 0x800BDCFCu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15928);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BDD00:
    ctx->pc = 0x800BDD00u;
    // 800BDD00: ori     r3, r3, 0x006A
    ctx->gpr[3] = ctx->gpr[3] | 0x006Au;

label_800BDD04:
    ctx->pc = 0x800BDD04u;
    // 800BDD04: bl      0x8004DC00
    {
            ctx->lr = 0x800BDD08u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BDD08:
    ctx->pc = 0x800BDD08u;
    ctx->downcount -= 10;
    // 800BDD08: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BDD0C:
    ctx->pc = 0x800BDD0Cu;
    // 800BDD0C: lis     r11, 32
    ctx->gpr[11] = ((u32)(s32)(32) << 16);

label_800BDD10:
    ctx->pc = 0x800BDD10u;
    // 800BDD10: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BDD14:
    ctx->pc = 0x800BDD14u;
    // 800BDD14: ori     r11, r11, 0x0002
    ctx->gpr[11] = ctx->gpr[11] | 0x0002u;

label_800BDD18:
    ctx->pc = 0x800BDD18u;
    // 800BDD18: lwz     r10, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BDD1C:
    ctx->pc = 0x800BDD1Cu;
    // 800BDD1C: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDD20:
    ctx->pc = 0x800BDD20u;
    // 800BDD20: xor   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[10];
    }

label_800BDD24:
    ctx->pc = 0x800BDD24u;
    // 800BDD24: and   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[11];
    }

label_800BDD28:
    ctx->pc = 0x800BDD28u;
    // 800BDD28: and.   r9, r0, r10
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

label_800BDD2C:
    ctx->pc = 0x800BDD2Cu;
    // 800BDD2C: bc    12, 2, 0x800BDDEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDDEC;
        }
    }

label_800BDD30:
    ctx->pc = 0x800BDD30u;
    ctx->downcount -= 6;
    // 800BDD30: lwz     r9, 48(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(48);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BDD34:
    ctx->pc = 0x800BDD34u;
    // 800BDD34: lwz     r0, 52(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDD38:
    ctx->pc = 0x800BDD38u;
    // 800BDD38: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_800BDD3C:
    ctx->pc = 0x800BDD3Cu;
    // 800BDD3C: or   r11, r0, r0
    {
        ctx->gpr[11] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800BDD40:
    ctx->pc = 0x800BDD40u;
    // 800BDD40: cmpw    r9, r0
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

label_800BDD44:
    ctx->pc = 0x800BDD44u;
    // 800BDD44: bc    4, 0, 0x800BDDEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BDDEC;
        }
    }

label_800BDD48:
    ctx->pc = 0x800BDD48u;
    ctx->downcount -= 4;
    // 800BDD48: or   r30, r9, r9
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BDD4C:
    ctx->pc = 0x800BDD4Cu;
    // 800BDD4C: lis     r24, -32734
    ctx->gpr[24] = ((u32)(s32)(-32734) << 16);

label_800BDD50:
    ctx->pc = 0x800BDD50u;
    // 800BDD50: rlwinm r29, r30, 4, 0, 27
    {
        ctx->gpr[29] = dolrecomp_rotl32(ctx->gpr[30], 4u) & 0xFFFFFFF0u;
    }

label_800BDD54:
    ctx->pc = 0x800BDD54u;
    // 800BDD54: b       0x800BDD64
    {
            goto label_800BDD64;
    }

label_800BDD58:
    ctx->pc = 0x800BDD58u;
    ctx->downcount -= 3;
    // 800BDD58: lwz     r11, 52(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(52);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BDD5C:
    // 800BDD5C: addi    r29, r31, 16
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(16);

label_800BDD60:
    // 800BDD60: addi    r30, r30, 1
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(1);

label_800BDD64:
    ctx->downcount -= 2;
    // 800BDD64: cmpw    r30, r11
    {
        s32 val_a = (s32)(ctx->gpr[30]);
        s32 val_b = (s32)(ctx->gpr[11]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BDD68:
    // 800BDD68: bc    4, 0, 0x800BDDEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BDDEC;
        }
    }

label_800BDD6C:
    ctx->downcount -= 6;
    // 800BDD6C: addi    r28, r24, -2960
    ctx->gpr[28] = ctx->gpr[24] + (u32)(s32)(-2960);

label_800BDD70:
    // 800BDD70: or   r31, r29, r29
    {
        ctx->gpr[31] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BDD74:
    // 800BDD74: addi    r27, r28, 8
    ctx->gpr[27] = ctx->gpr[28] + (u32)(s32)(8);

label_800BDD78:
    ctx->pc = 0x800BDD78u;
    // 800BDD78: lwzx    r0, r27, r31
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[31];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDD7C:
    // 800BDD7C: cmpwi   r0, 0
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

label_800BDD80:
    // 800BDD80: bc    12, 2, 0x800BDDA0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDDA0;
        }
    }

label_800BDD84:
    ctx->downcount -= 6;
    // 800BDD84: add   r9, r31, r28
    {
        u32 a = ctx->gpr[31];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BDD88:
    // 800BDD88: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BDD8C:
    ctx->pc = 0x800BDD8Cu;
    // 800BDD8C: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDD90:
    ctx->pc = 0x800BDD90u;
    // 800BDD90: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDD94:
    ctx->pc = 0x800BDD94u;
    // 800BDD94: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800BDD98u;
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDD98:
    ctx->downcount -= 2;
    // 800BDD98: cmpwi   r3, 0
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

label_800BDD9C:
    // 800BDD9C: bc    12, 2, 0x800BDD58
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BDD58u;
                return;
            }
            goto label_800BDD58;
        }
    }

label_800BDDA0:
    ctx->pc = 0x800BDDA0u;
    ctx->downcount -= 3;
    // 800BDDA0: lwz     r0, 52(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDDA4:
    ctx->pc = 0x800BDDA4u;
    // 800BDDA4: cmpw    r30, r0
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

label_800BDDA8:
    ctx->pc = 0x800BDDA8u;
    // 800BDDA8: bc    4, 0, 0x800BDDEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BDDEC;
        }
    }

label_800BDDAC:
    ctx->pc = 0x800BDDACu;
    ctx->downcount -= 3;
    // 800BDDAC: lwzx    r0, r27, r29
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[29];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDDB0:
    ctx->pc = 0x800BDDB0u;
    // 800BDDB0: cmpwi   r0, 0
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

label_800BDDB4:
    ctx->pc = 0x800BDDB4u;
    // 800BDDB4: bc    12, 2, 0x800BDDD4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDDD4;
        }
    }

label_800BDDB8:
    ctx->pc = 0x800BDDB8u;
    ctx->downcount -= 6;
    // 800BDDB8: add   r9, r29, r28
    {
        u32 a = ctx->gpr[29];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BDDBC:
    ctx->pc = 0x800BDDBCu;
    // 800BDDBC: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BDDC0:
    ctx->pc = 0x800BDDC0u;
    // 800BDDC0: lwz     r0, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDDC4:
    ctx->pc = 0x800BDDC4u;
    // 800BDDC4: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDDC8:
    ctx->pc = 0x800BDDC8u;
    // 800BDDC8: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800BDDCCu;
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDDCC:
    ctx->pc = 0x800BDDCCu;
    ctx->downcount -= 2;
    // 800BDDCC: cmpwi   r3, 0
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

label_800BDDD0:
    ctx->pc = 0x800BDDD0u;
    // 800BDDD0: bc    12, 2, 0x800BDDD8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDDD8;
        }
    }

label_800BDDD4:
    ctx->pc = 0x800BDDD4u;
    ctx->downcount -= 1;
    // 800BDDD4: stw     r30, 48(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BDDD8:
    ctx->pc = 0x800BDDD8u;
    ctx->downcount -= 5;
    // 800BDDD8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BDDDC:
    ctx->pc = 0x800BDDDCu;
    // 800BDDDC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BDDE0:
    ctx->pc = 0x800BDDE0u;
    // 800BDDE0: lfs     f1, -15928(r9)
    if (!ppc_fp_available(ctx, 0x800BDDE0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15928);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BDDE4:
    ctx->pc = 0x800BDDE4u;
    // 800BDDE4: ori     r3, r3, 0x006A
    ctx->gpr[3] = ctx->gpr[3] | 0x006Au;

label_800BDDE8:
    ctx->pc = 0x800BDDE8u;
    // 800BDDE8: bl      0x8004DC00
    {
            ctx->lr = 0x800BDDECu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BDDEC:
    ctx->pc = 0x800BDDECu;
    ctx->downcount -= 20;
    // 800BDDEC: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BDDF0:
    ctx->pc = 0x800BDDF0u;
    // 800BDDF0: li      r0, 4100
    ctx->gpr[0] = (u32)(s32)(4100);

label_800BDDF4:
    ctx->pc = 0x800BDDF4u;
    // 800BDDF4: stw     r0, -19532(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-19532);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDDF8:
    ctx->pc = 0x800BDDF8u;
    // 800BDDF8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BDDFC:
    ctx->pc = 0x800BDDFCu;
    // 800BDDFC: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDE00:
    ctx->pc = 0x800BDE00u;
    // 800BDE00: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BDE04:
    ctx->pc = 0x800BDE04u;
    // 800BDE04: lmw     r24, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 24; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BDE08:
    ctx->pc = 0x800BDE08u;
    // 800BDE08: addi    r1, r1, 40
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(40);

label_800BDE0C:
    ctx->pc = 0x800BDE0Cu;
    // 800BDE0C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDE10:
    ctx->pc = 0x800BDE10u;
    ctx->downcount -= 25;
    // 800BDE10: stwu     r1, -104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-104);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BDE14:
    ctx->pc = 0x800BDE14u;
    // 800BDE14: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BDE18:
    ctx->pc = 0x800BDE18u;
    // 800BDE18: stfd     f30, 88(r1)
    if (!ppc_fp_available(ctx, 0x800BDE18u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[30]));
    }

label_800BDE1C:
    ctx->pc = 0x800BDE1Cu;
    // 800BDE1C: stfd     f31, 96(r1)
    if (!ppc_fp_available(ctx, 0x800BDE1Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800BDE20:
    ctx->pc = 0x800BDE20u;
    // 800BDE20: stmw     r22, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 22; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BDE24:
    ctx->pc = 0x800BDE24u;
    // 800BDE24: stw     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDE28:
    ctx->pc = 0x800BDE28u;
    // 800BDE28: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BDE2C:
    ctx->pc = 0x800BDE2Cu;
    // 800BDE2C: lis     r11, -32698
    ctx->gpr[11] = ((u32)(s32)(-32698) << 16);

label_800BDE30:
    ctx->pc = 0x800BDE30u;
    // 800BDE30: lwz     r0, -21632(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-21632);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDE34:
    ctx->pc = 0x800BDE34u;
    // 800BDE34: addi    r10, r11, 7984
    ctx->gpr[10] = ctx->gpr[11] + (u32)(s32)(7984);

label_800BDE38:
    ctx->pc = 0x800BDE38u;
    // 800BDE38: or.   r30, r3, r3
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

label_800BDE3C:
    ctx->pc = 0x800BDE3Cu;
    // 800BDE3C: rlwinm r9, r0, 1, 31, 31
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[0], 1u) & 0x00000001u;
    }

label_800BDE40:
    ctx->pc = 0x800BDE40u;
    // 800BDE40: add   r0, r0, r9
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800BDE44:
    ctx->pc = 0x800BDE44u;
    // 800BDE44: srawi r23, r0, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[0];
        bool ca = false;
        if (sh == 0) {
            ctx->gpr[23] = value;
        } else if (sh > 31) {
            ctx->gpr[23] = (value & 0x80000000u) ? 0xFFFFFFFFu : 0u;
            ca = (value & 0x80000000u) != 0;
        } else {
            ctx->gpr[23] = (u32)((s32)value >> sh);
            ca = (value & 0x80000000u) && ((value << (32u - sh)) != 0);
        }
        ctx->xer = (ctx->xer & ~0x20000000u) | (ca ? 0x20000000u : 0u);
    }

label_800BDE48:
    ctx->pc = 0x800BDE48u;
    // 800BDE48: bc    12, 2, 0x800BE02C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE02C;
        }
    }

label_800BDE4C:
    ctx->pc = 0x800BDE4Cu;
    ctx->downcount -= 25;
    // 800BDE4C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BDE50:
    ctx->pc = 0x800BDE50u;
    // 800BDE50: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BDE54:
    ctx->pc = 0x800BDE54u;
    // 800BDE54: lfs     f0, -15924(r9)
    if (!ppc_fp_available(ctx, 0x800BDE54u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15924);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BDE58:
    ctx->pc = 0x800BDE58u;
    // 800BDE58: addi    r31, r1, 8
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(8);

label_800BDE5C:
    ctx->pc = 0x800BDE5Cu;
    // 800BDE5C: lfs     f13, -15920(r11)
    if (!ppc_fp_available(ctx, 0x800BDE5Cu)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15920);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BDE60:
    ctx->pc = 0x800BDE60u;
    // 800BDE60: or   r3, r10, r10
    {
        ctx->gpr[3] = ctx->gpr[10] | ctx->gpr[10];
    }

label_800BDE64:
    ctx->pc = 0x800BDE64u;
    // 800BDE64: stfs     f0, 8(r1)
    if (!ppc_fp_available(ctx, 0x800BDE64u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BDE68:
    ctx->pc = 0x800BDE68u;
    // 800BDE68: addi    r9, r1, 24
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(24);

label_800BDE6C:
    ctx->pc = 0x800BDE6Cu;
    // 800BDE6C: stfs     f13, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BDE6Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BDE70:
    ctx->pc = 0x800BDE70u;
    // 800BDE70: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BDE74:
    ctx->pc = 0x800BDE74u;
    // 800BDE74: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDE78:
    ctx->pc = 0x800BDE78u;
    // 800BDE78: or   r24, r9, r9
    {
        ctx->gpr[24] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BDE7C:
    ctx->pc = 0x800BDE7Cu;
    // 800BDE7C: lwz     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BDE80:
    ctx->pc = 0x800BDE80u;
    // 800BDE80: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BDE84:
    ctx->pc = 0x800BDE84u;
    // 800BDE84: lwz     r10, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BDE88:
    ctx->pc = 0x800BDE88u;
    // 800BDE88: li      r5, 3878
    ctx->gpr[5] = (u32)(s32)(3878);

label_800BDE8C:
    ctx->pc = 0x800BDE8Cu;
    // 800BDE8C: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDE90:
    ctx->pc = 0x800BDE90u;
    // 800BDE90: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BDE94:
    ctx->pc = 0x800BDE94u;
    // 800BDE94: stw     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BDE98:
    ctx->pc = 0x800BDE98u;
    // 800BDE98: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BDE9C:
    ctx->pc = 0x800BDE9Cu;
    // 800BDE9C: stw     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BDEA0:
    ctx->pc = 0x800BDEA0u;
    // 800BDEA0: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BDEA4:
    ctx->pc = 0x800BDEA4u;
    // 800BDEA4: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BDEA8:
    ctx->pc = 0x800BDEA8u;
    // 800BDEA8: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BDEAC:
    ctx->pc = 0x800BDEACu;
    // 800BDEAC: bl      0x800C3D88
    {
            ctx->lr = 0x800BDEB0u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BDEB0:
    ctx->pc = 0x800BDEB0u;
    ctx->downcount -= 11;
    // 800BDEB0: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_800BDEB4:
    ctx->pc = 0x800BDEB4u;
    // 800BDEB4: lwz     r11, 1420(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1420);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BDEB8:
    ctx->pc = 0x800BDEB8u;
    // 800BDEB8: addi    r9, r30, 1420
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(1420);

label_800BDEBC:
    ctx->pc = 0x800BDEBCu;
    // 800BDEBC: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDEC0:
    ctx->pc = 0x800BDEC0u;
    // 800BDEC0: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BDEC4:
    ctx->pc = 0x800BDEC4u;
    // 800BDEC4: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BDEC8:
    ctx->pc = 0x800BDEC8u;
    // 800BDEC8: stw     r0, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDECC:
    ctx->pc = 0x800BDECCu;
    // 800BDECC: stw     r10, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BDED0:
    ctx->pc = 0x800BDED0u;
    // 800BDED0: lwz     r0, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDED4:
    ctx->pc = 0x800BDED4u;
    // 800BDED4: cmpw    r27, r0
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

label_800BDED8:
    ctx->pc = 0x800BDED8u;
    // 800BDED8: bc    4, 0, 0x800BDFD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BDFD0;
        }
    }

label_800BDEDC:
    ctx->pc = 0x800BDEDCu;
    ctx->downcount -= 11;
    // 800BDEDC: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BDEE0:
    ctx->pc = 0x800BDEE0u;
    // 800BDEE0: lis     r11, -32737
    ctx->gpr[11] = ((u32)(s32)(-32737) << 16);

label_800BDEE4:
    ctx->pc = 0x800BDEE4u;
    // 800BDEE4: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BDEE8:
    ctx->pc = 0x800BDEE8u;
    // 800BDEE8: addi    r29, r9, -2960
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-2960);

label_800BDEEC:
    ctx->pc = 0x800BDEECu;
    // 800BDEEC: or   r28, r31, r31
    {
        ctx->gpr[28] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BDEF0:
    ctx->pc = 0x800BDEF0u;
    // 800BDEF0: lfd     f31, -15912(r11)
    if (!ppc_fp_available(ctx, 0x800BDEF0u)) return;
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-15912);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BDEF4:
    ctx->pc = 0x800BDEF4u;
    // 800BDEF4: lfs     f30, -15904(r10)
    if (!ppc_fp_available(ctx, 0x800BDEF4u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-15904);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[30] = value;
        ctx->ps1[30] = value;
    }

label_800BDEF8:
    ctx->pc = 0x800BDEF8u;
    // 800BDEF8: addi    r22, r29, 8
    ctx->gpr[22] = ctx->gpr[29] + (u32)(s32)(8);

label_800BDEFC:
    ctx->pc = 0x800BDEFCu;
    // 800BDEFC: or   r31, r24, r24
    {
        ctx->gpr[31] = ctx->gpr[24] | ctx->gpr[24];
    }

label_800BDF00:
    ctx->pc = 0x800BDF00u;
    // 800BDF00: lis     r25, 17200
    ctx->gpr[25] = ((u32)(s32)(17200) << 16);

label_800BDF04:
    ctx->pc = 0x800BDF04u;
    // 800BDF04: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_800BDF08:
    ctx->pc = 0x800BDF08u;
    ctx->downcount -= 3;
    // 800BDF08: lwzx    r0, r22, r26
    {
        u32 ea = ctx->gpr[22] + ctx->gpr[26];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDF0C:
    // 800BDF0C: cmpwi   r0, 0
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

label_800BDF10:
    // 800BDF10: bc    12, 2, 0x800BDF2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDF2C;
        }
    }

label_800BDF14:
    ctx->pc = 0x800BDF14u;
    ctx->downcount -= 5;
    // 800BDF14: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BDF18:
    // 800BDF18: or   r3, r23, r23
    {
        ctx->gpr[3] = ctx->gpr[23] | ctx->gpr[23];
    }

label_800BDF1C:
    ctx->pc = 0x800BDF1Cu;
    // 800BDF1C: mtlr    r9
    ctx->lr = ctx->gpr[9];

label_800BDF20:
    ctx->pc = 0x800BDF20u;
    // 800BDF20: blrl
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->lr = 0x800BDF24u;
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BDF24:
    ctx->downcount -= 2;
    // 800BDF24: cmpwi   r3, 0
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

label_800BDF28:
    // 800BDF28: bc    12, 2, 0x800BDFB8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BDFB8;
        }
    }

label_800BDF2C:
    ctx->pc = 0x800BDF2Cu;
    ctx->downcount -= 3;
    // 800BDF2C: lwz     r0, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDF30:
    // 800BDF30: cmpw    r0, r27
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[27]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BDF34:
    // 800BDF34: bc    4, 2, 0x800BDF54
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BDF54;
        }
    }

label_800BDF38:
    ctx->pc = 0x800BDF38u;
    ctx->downcount -= 7;
    // 800BDF38: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDF3C:
    // 800BDF3C: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BDF40:
    ctx->pc = 0x800BDF40u;
    // 800BDF40: lwz     r9, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BDF44:
    // 800BDF44: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BDF48:
    ctx->pc = 0x800BDF48u;
    // 800BDF48: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BDF4C:
    // 800BDF4C: li      r6, 24
    ctx->gpr[6] = (u32)(s32)(24);

label_800BDF50:
    // 800BDF50: b       0x800BDF6C
    {
            goto label_800BDF6C;
    }

label_800BDF54:
    ctx->pc = 0x800BDF54u;
    ctx->downcount -= 6;
    // 800BDF54: lwz     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDF58:
    // 800BDF58: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BDF5C:
    ctx->pc = 0x800BDF5Cu;
    // 800BDF5C: lwz     r9, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BDF60:
    // 800BDF60: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BDF64:
    ctx->pc = 0x800BDF64u;
    // 800BDF64: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BDF68:
    // 800BDF68: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_800BDF6C:
    ctx->pc = 0x800BDF6Cu;
    ctx->downcount -= 9;
    // 800BDF6C: lwz     r5, 0(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(0);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BDF70:
    // 800BDF70: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BDF74:
    ctx->pc = 0x800BDF74u;
    // 800BDF74: stw     r0, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BDF78:
    // 800BDF78: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BDF7C:
    ctx->pc = 0x800BDF7Cu;
    // 800BDF7C: stw     r9, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BDF80:
    // 800BDF80: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BDF84:
    // 800BDF84: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BDF88:
    ctx->pc = 0x800BDF88u;
    // 800BDF88: stw     r11, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BDF8C:
    // 800BDF8C: bl      0x800C3D88
    {
            ctx->lr = 0x800BDF90u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BDF90:
    ctx->downcount -= 10;
    // 800BDF90: xoris   r3, r3, 0x8000
    ctx->gpr[3] = ctx->gpr[3] ^ (0x8000u << 16);

label_800BDF94:
    ctx->pc = 0x800BDF94u;
    // 800BDF94: stw     r3, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BDF98:
    ctx->pc = 0x800BDF98u;
    // 800BDF98: stw     r25, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_800BDF9C:
    ctx->pc = 0x800BDF9Cu;
    // 800BDF9C: lfd     f0, 40(r1)
    if (!ppc_fp_available(ctx, 0x800BDF9Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->fpr[0] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BDFA0:
    ctx->pc = 0x800BDFA0u;
    // 800BDFA0: fsub   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BDFA0u)) return;
    ppc_fsub(ctx, 0, 0, 31);

label_800BDFA4:
    ctx->pc = 0x800BDFA4u;
    // 800BDFA4: frsp    f0, f0
    if (!ppc_fp_available(ctx, 0x800BDFA4u)) return;
    ppc_frsp(ctx, 0, 0);

label_800BDFA8:
    ctx->pc = 0x800BDFA8u;
    // 800BDFA8: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BDFA8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BDFAC:
    ctx->pc = 0x800BDFACu;
    // 800BDFAC: lfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BDFACu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BDFB0:
    ctx->pc = 0x800BDFB0u;
    // 800BDFB0: fadds   f0, f0, f30
    if (!ppc_fp_available(ctx, 0x800BDFB0u)) return;
    ppc_fadds(ctx, 0, 0, 30);

label_800BDFB4:
    ctx->pc = 0x800BDFB4u;
    // 800BDFB4: stfs     f0, 12(r1)
    if (!ppc_fp_available(ctx, 0x800BDFB4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BDFB8:
    ctx->pc = 0x800BDFB8u;
    ctx->downcount -= 6;
    // 800BDFB8: lwz     r0, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDFBC:
    // 800BDFBC: addi    r27, r27, 1
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(1);

label_800BDFC0:
    // 800BDFC0: addi    r29, r29, 16
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(16);

label_800BDFC4:
    // 800BDFC4: addi    r26, r26, 16
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(16);

label_800BDFC8:
    // 800BDFC8: cmpw    r27, r0
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

label_800BDFCC:
    // 800BDFCC: bc    12, 0, 0x800BDF08
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BDF08u;
                return;
            }
            goto label_800BDF08;
        }
    }

label_800BDFD0:
    ctx->pc = 0x800BDFD0u;
    ctx->downcount -= 3;
    // 800BDFD0: lwz     r0, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BDFD4:
    ctx->pc = 0x800BDFD4u;
    // 800BDFD4: cmpwi   r0, 0
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

label_800BDFD8:
    ctx->pc = 0x800BDFD8u;
    // 800BDFD8: bc    12, 0, 0x800BE02C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE02C;
        }
    }

label_800BDFDC:
    ctx->pc = 0x800BDFDCu;
    ctx->downcount -= 20;
    // 800BDFDC: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BDFE0:
    ctx->pc = 0x800BDFE0u;
    // 800BDFE0: lwz     r8, 1432(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1432);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BDFE4:
    ctx->pc = 0x800BDFE4u;
    // 800BDFE4: addi    r9, r9, -2960
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2960);

label_800BDFE8:
    ctx->pc = 0x800BDFE8u;
    // 800BDFE8: addi    r11, r30, 1432
    ctx->gpr[11] = ctx->gpr[30] + (u32)(s32)(1432);

label_800BDFEC:
    ctx->pc = 0x800BDFECu;
    // 800BDFEC: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_800BDFF0:
    ctx->pc = 0x800BDFF0u;
    // 800BDFF0: rlwinm r0, r0, 4, 0, 27
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 4u) & 0xFFFFFFF0u;
    }

label_800BDFF4:
    ctx->pc = 0x800BDFF4u;
    // 800BDFF4: lwz     r7, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800BDFF8:
    ctx->pc = 0x800BDFF8u;
    // 800BDFF8: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_800BDFFC:
    ctx->pc = 0x800BDFFCu;
    // 800BDFFC: lwz     r10, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE000:
    ctx->pc = 0x800BE000u;
    // 800BE000: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BE004:
    ctx->pc = 0x800BE004u;
    // 800BE004: lwzx    r5, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BE008:
    ctx->pc = 0x800BE008u;
    // 800BE008: li      r6, 8
    ctx->gpr[6] = (u32)(s32)(8);

label_800BE00C:
    ctx->pc = 0x800BE00Cu;
    // 800BE00C: stw     r8, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BE010:
    ctx->pc = 0x800BE010u;
    // 800BE010: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BE014:
    ctx->pc = 0x800BE014u;
    // 800BE014: stw     r10, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BE018:
    ctx->pc = 0x800BE018u;
    // 800BE018: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BE01C:
    ctx->pc = 0x800BE01Cu;
    // 800BE01C: stw     r7, 8(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800BE020:
    ctx->pc = 0x800BE020u;
    // 800BE020: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BE024:
    ctx->pc = 0x800BE024u;
    // 800BE024: li      r7, 200
    ctx->gpr[7] = (u32)(s32)(200);

label_800BE028:
    ctx->pc = 0x800BE028u;
    // 800BE028: bl      0x800C3D88
    {
            ctx->lr = 0x800BE02Cu;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BE02C:
    ctx->pc = 0x800BE02Cu;
    ctx->downcount -= 18;
    // 800BE02C: lwz     r0, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE030:
    ctx->pc = 0x800BE030u;
    // 800BE030: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BE034:
    ctx->pc = 0x800BE034u;
    // 800BE034: lmw     r22, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        for (u32 r = 22; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BE038:
    ctx->pc = 0x800BE038u;
    // 800BE038: lfd     f30, 88(r1)
    if (!ppc_fp_available(ctx, 0x800BE038u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->fpr[30] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BE03C:
    ctx->pc = 0x800BE03Cu;
    // 800BE03C: lfd     f31, 96(r1)
    if (!ppc_fp_available(ctx, 0x800BE03Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BE040:
    ctx->pc = 0x800BE040u;
    // 800BE040: addi    r1, r1, 104
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(104);

label_800BE044:
    ctx->pc = 0x800BE044u;
    // 800BE044: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BE048:
    ctx->pc = 0x800BE048u;
    ctx->downcount -= 5;
    // 800BE048: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BE04C:
    ctx->pc = 0x800BE04Cu;
    // 800BE04C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BE050:
    ctx->pc = 0x800BE050u;
    // 800BE050: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE054:
    ctx->pc = 0x800BE054u;
    // 800BE054: cmpwi   r4, 0
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

label_800BE058:
    ctx->pc = 0x800BE058u;
    // 800BE058: bc    4, 2, 0x800BE064
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE064;
        }
    }

label_800BE05C:
    ctx->pc = 0x800BE05Cu;
    ctx->downcount -= 2;
    // 800BE05C: li      r3, 465
    ctx->gpr[3] = (u32)(s32)(465);

label_800BE060:
    ctx->pc = 0x800BE060u;
    // 800BE060: bl      0x8005B3F8
    {
            ctx->lr = 0x800BE064u;
            ctx->pc = 0x8005B3F8u;
            return;
    }

label_800BE064:
    ctx->pc = 0x800BE064u;
    ctx->downcount -= 5;
    // 800BE064: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE068:
    ctx->pc = 0x800BE068u;
    // 800BE068: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BE06C:
    ctx->pc = 0x800BE06Cu;
    // 800BE06C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_800BE070:
    ctx->pc = 0x800BE070u;
    // 800BE070: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BE074:
    ctx->pc = 0x800BE074u;
    ctx->downcount -= 21;
    // 800BE074: stwu     r1, -168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-168);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BE078:
    ctx->pc = 0x800BE078u;
    // 800BE078: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BE07C:
    ctx->pc = 0x800BE07Cu;
    // 800BE07C: stmw     r14, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BE080:
    ctx->pc = 0x800BE080u;
    // 800BE080: stw     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE084:
    ctx->pc = 0x800BE084u;
    // 800BE084: lis     r9, -32736
    ctx->gpr[9] = ((u32)(s32)(-32736) << 16);

label_800BE088:
    ctx->pc = 0x800BE088u;
    // 800BE088: or   r16, r3, r3
    {
        ctx->gpr[16] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BE08C:
    ctx->pc = 0x800BE08Cu;
    // 800BE08C: addi    r9, r9, 11952
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(11952);

label_800BE090:
    ctx->pc = 0x800BE090u;
    // 800BE090: addi    r9, r9, 26056
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(26056);

label_800BE094:
    ctx->pc = 0x800BE094u;
    // 800BE094: lwz     r0, 20(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE098:
    ctx->pc = 0x800BE098u;
    // 800BE098: cmpwi   r0, 0
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

label_800BE09C:
    ctx->pc = 0x800BE09Cu;
    // 800BE09C: bc    12, 2, 0x800BE0B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE0B0;
        }
    }

label_800BE0A0:
    ctx->pc = 0x800BE0A0u;
    ctx->downcount -= 4;
    // 800BE0A0: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE0A4:
    ctx->pc = 0x800BE0A4u;
    // 800BE0A4: xoris   r0, r0, 0x2000
    ctx->gpr[0] = ctx->gpr[0] ^ (0x2000u << 16);

label_800BE0A8:
    ctx->pc = 0x800BE0A8u;
    // 800BE0A8: rlwinm r0, r0, 3, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 3u) & 0x00000001u;
    }

label_800BE0AC:
    ctx->pc = 0x800BE0ACu;
    // 800BE0AC: b       0x800BE0B4
    {
            goto label_800BE0B4;
    }

label_800BE0B0:
    ctx->pc = 0x800BE0B0u;
    ctx->downcount -= 1;
    // 800BE0B0: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BE0B4:
    ctx->pc = 0x800BE0B4u;
    ctx->downcount -= 3;
    // 800BE0B4: cmpwi   r0, 0
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

label_800BE0B8:
    ctx->pc = 0x800BE0B8u;
    // 800BE0B8: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BE0BC:
    ctx->pc = 0x800BE0BCu;
    // 800BE0BC: bc    12, 2, 0x800BE5FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE5FC;
        }
    }

label_800BE0C0:
    ctx->pc = 0x800BE0C0u;
    ctx->downcount -= 6;
    // 800BE0C0: lwz     r3, 4(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BE0C4:
    ctx->pc = 0x800BE0C4u;
    // 800BE0C4: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BE0C8:
    ctx->pc = 0x800BE0C8u;
    // 800BE0C8: stw     r0, -31328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31328);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE0CC:
    ctx->pc = 0x800BE0CCu;
    // 800BE0CC: stw     r0, -31324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31324);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE0D0:
    ctx->pc = 0x800BE0D0u;
    // 800BE0D0: cmpwi   r3, 0
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

label_800BE0D4:
    ctx->pc = 0x800BE0D4u;
    // 800BE0D4: bc    12, 2, 0x800BE5F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE5F0;
        }
    }

label_800BE0D8:
    ctx->pc = 0x800BE0D8u;
    ctx->downcount -= 3;
    // 800BE0D8: lis     r4, 20992
    ctx->gpr[4] = ((u32)(s32)(20992) << 16);

label_800BE0DC:
    ctx->pc = 0x800BE0DCu;
    // 800BE0DC: ori     r4, r4, 0x0129
    ctx->gpr[4] = ctx->gpr[4] | 0x0129u;

label_800BE0E0:
    ctx->pc = 0x800BE0E0u;
    // 800BE0E0: bl      0x80047634
    {
            ctx->lr = 0x800BE0E4u;
            ctx->pc = 0x80047634u;
            return;
    }

label_800BE0E4:
    ctx->pc = 0x800BE0E4u;
    ctx->downcount -= 2;
    // 800BE0E4: or.   r17, r3, r3
    {
        ctx->gpr[17] = ctx->gpr[3] | ctx->gpr[3];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[17];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BE0E8:
    ctx->pc = 0x800BE0E8u;
    // 800BE0E8: bc    12, 2, 0x800BE5F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE5F0;
        }
    }

label_800BE0EC:
    ctx->pc = 0x800BE0ECu;
    ctx->downcount -= 10;
    // 800BE0EC: lwz     r10, -31328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31328);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE0F0:
    ctx->pc = 0x800BE0F0u;
    // 800BE0F0: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BE0F4:
    ctx->pc = 0x800BE0F4u;
    // 800BE0F4: addi    r11, r9, -2880
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BE0F8:
    ctx->pc = 0x800BE0F8u;
    // 800BE0F8: addi    r29, r1, 48
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(48);

label_800BE0FC:
    ctx->pc = 0x800BE0FCu;
    // 800BE0FC: mulli   r0, r10, 52
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[10] * (s64)(s32)52);

label_800BE100:
    ctx->pc = 0x800BE100u;
    // 800BE100: lwzx    r9, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE104:
    ctx->pc = 0x800BE104u;
    // 800BE104: cmpwi   r9, -1
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

label_800BE108:
    ctx->pc = 0x800BE108u;
    // 800BE108: bc    12, 2, 0x800BE12C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE12C;
        }
    }

label_800BE10C:
    ctx->pc = 0x800BE10Cu;
    ctx->downcount -= 1;
    // 800BE10C: or   r8, r11, r11
    {
        ctx->gpr[8] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BE110:
    loop_800BE110(ctx);
    if (ctx->pc == 0x800BE128u) goto label_800BE128;
    return;
label_800BE114:
    // 800BE114: mulli   r9, r11, 52
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)52);

label_800BE118:
    // 800BE118: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BE11C:
    ctx->pc = 0x800BE11Cu;
    // 800BE11C: lwzx    r0, r8, r9
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE120:
    // 800BE120: cmpwi   r0, -1
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

label_800BE124:
    // 800BE124: bc    4, 2, 0x800BE110
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE110u;
                return;
            }
            goto label_800BE110;
        }
    }

label_800BE128:
    ctx->pc = 0x800BE128u;
    ctx->downcount -= 1;
    // 800BE128: stw     r11, -31328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31328);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BE12C:
    ctx->pc = 0x800BE12Cu;
    ctx->downcount -= 4;
    // 800BE12C: lwz     r0, -31328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31328);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE130:
    ctx->pc = 0x800BE130u;
    // 800BE130: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_800BE134:
    ctx->pc = 0x800BE134u;
    // 800BE134: cmpw    r26, r0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE138:
    ctx->pc = 0x800BE138u;
    // 800BE138: bc    4, 0, 0x800BE290
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE290;
        }
    }

label_800BE13C:
    ctx->pc = 0x800BE13Cu;
    ctx->downcount -= 9;
    // 800BE13C: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BE140:
    ctx->pc = 0x800BE140u;
    // 800BE140: addi    r24, r1, 80
    ctx->gpr[24] = ctx->gpr[1] + (u32)(s32)(80);

label_800BE144:
    ctx->pc = 0x800BE144u;
    // 800BE144: addi    r23, r9, -2880
    ctx->gpr[23] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BE148:
    ctx->pc = 0x800BE148u;
    // 800BE148: lis     r18, -32737
    ctx->gpr[18] = ((u32)(s32)(-32737) << 16);

label_800BE14C:
    ctx->pc = 0x800BE14Cu;
    // 800BE14C: or   r22, r29, r29
    {
        ctx->gpr[22] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE150:
    ctx->pc = 0x800BE150u;
    // 800BE150: addi    r19, r23, 32
    ctx->gpr[19] = ctx->gpr[23] + (u32)(s32)(32);

label_800BE154:
    ctx->pc = 0x800BE154u;
    // 800BE154: addi    r20, r23, 28
    ctx->gpr[20] = ctx->gpr[23] + (u32)(s32)(28);

label_800BE158:
    ctx->pc = 0x800BE158u;
    // 800BE158: addi    r28, r23, 36
    ctx->gpr[28] = ctx->gpr[23] + (u32)(s32)(36);

label_800BE15C:
    ctx->pc = 0x800BE15Cu;
    // 800BE15C: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_800BE160:
    ctx->downcount -= 7;
    // 800BE160: addi    r9, r23, 24
    ctx->gpr[9] = ctx->gpr[23] + (u32)(s32)(24);

label_800BE164:
    // 800BE164: or   r3, r17, r17
    {
        ctx->gpr[3] = ctx->gpr[17] | ctx->gpr[17];
    }

label_800BE168:
    ctx->pc = 0x800BE168u;
    // 800BE168: lwzx    r4, r9, r25
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[25];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BE16C:
    // 800BE16C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE170:
    // 800BE170: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE174:
    // 800BE174: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BE178:
    // 800BE178: bl      0x800303A8
    {
            ctx->lr = 0x800BE17Cu;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BE17C:
    ctx->downcount -= 2;
    // 800BE17C: cmpwi   r3, 0
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

label_800BE180:
    // 800BE180: bc    12, 2, 0x800BE270
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE270;
        }
    }

label_800BE184:
    ctx->downcount -= 16;
    // 800BE184: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE188:
    ctx->pc = 0x800BE188u;
    // 800BE188: lwz     r10, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE18C:
    // 800BE18C: addi    r27, r9, -21636
    ctx->gpr[27] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE190:
    ctx->pc = 0x800BE190u;
    // 800BE190: lwz     r8, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BE194:
    ctx->pc = 0x800BE194u;
    // 800BE194: lwz     r11, 936(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(936);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE198:
    // 800BE198: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BE19C:
    ctx->pc = 0x800BE19Cu;
    // 800BE19C: lwz     r7, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800BE1A0:
    // 800BE1A0: addi    r31, r1, 80
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(80);

label_800BE1A4:
    ctx->pc = 0x800BE1A4u;
    // 800BE1A4: lwz     r0, -32(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(-32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE1A8:
    // 800BE1A8: lis     r21, -32737
    ctx->gpr[21] = ((u32)(s32)(-32737) << 16);

label_800BE1AC:
    ctx->pc = 0x800BE1ACu;
    // 800BE1AC: stw     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE1B0:
    ctx->pc = 0x800BE1B0u;
    // 800BE1B0: stw     r10, 0(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BE1B4:
    // 800BE1B4: and.   r9, r11, r0
    {
        ctx->gpr[9] = ctx->gpr[11] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BE1B8:
    ctx->pc = 0x800BE1B8u;
    // 800BE1B8: stw     r8, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BE1BC:
    ctx->pc = 0x800BE1BCu;
    // 800BE1BC: stw     r7, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800BE1C0:
    // 800BE1C0: bc    12, 2, 0x800BE23C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE23C;
        }
    }

label_800BE1C4:
    ctx->downcount -= 4;
    // 800BE1C4: addi    r9, r23, 20
    ctx->gpr[9] = ctx->gpr[23] + (u32)(s32)(20);

label_800BE1C8:
    ctx->pc = 0x800BE1C8u;
    // 800BE1C8: lwzx    r5, r9, r25
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[25];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BE1CC:
    // 800BE1CC: cmpwi   r5, 0
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

label_800BE1D0:
    // 800BE1D0: bc    12, 2, 0x800BE23C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE23C;
        }
    }

label_800BE1D4:
    ctx->pc = 0x800BE1D4u;
    ctx->downcount -= 8;
    // 800BE1D4: stw     r10, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BE1D8:
    // 800BE1D8: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BE1DC:
    ctx->pc = 0x800BE1DCu;
    // 800BE1DC: lfs     f1, -15828(r21)
    if (!ppc_fp_available(ctx, 0x800BE1DCu)) return;
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(-15828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE1E0:
    // 800BE1E0: or   r4, r24, r24
    {
        ctx->gpr[4] = ctx->gpr[24] | ctx->gpr[24];
    }

label_800BE1E4:
    ctx->pc = 0x800BE1E4u;
    // 800BE1E4: stw     r8, 4(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BE1E8:
    // 800BE1E8: or   r6, r20, r20
    {
        ctx->gpr[6] = ctx->gpr[20] | ctx->gpr[20];
    }

label_800BE1EC:
    ctx->pc = 0x800BE1ECu;
    // 800BE1EC: stw     r7, 8(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800BE1F0:
    // 800BE1F0: bl      0x800C457C
    {
            ctx->lr = 0x800BE1F4u;
            ctx->pc = 0x800C457Cu;
            return;
    }

label_800BE1F4:
    ctx->pc = 0x800BE1F4u;
    ctx->downcount -= 3;
    // 800BE1F4: lwz     r30, -8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(-8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800BE1F8:
    // 800BE1F8: cmpwi   r30, 0
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

label_800BE1FC:
    // 800BE1FC: bc    12, 2, 0x800BE23C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE23C;
        }
    }

label_800BE200:
    ctx->pc = 0x800BE200u;
    ctx->downcount -= 3;
    // 800BE200: lwz     r0, 1004(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(1004);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE204:
    // 800BE204: cmpw    r0, r26
    {
        s32 val_a = (s32)(ctx->gpr[0]);
        s32 val_b = (s32)(ctx->gpr[26]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE208:
    // 800BE208: bc    4, 2, 0x800BE220
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE220;
        }
    }

label_800BE20C:
    ctx->pc = 0x800BE20Cu;
    ctx->downcount -= 4;
    // 800BE20C: lfs     f1, -15824(r18)
    if (!ppc_fp_available(ctx, 0x800BE20Cu)) return;
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(-15824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE210:
    // 800BE210: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE214:
    // 800BE214: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BE218:
    // 800BE218: bl      0x800C4664
    {
            ctx->lr = 0x800BE21Cu;
            ctx->pc = 0x800C4664u;
            return;
    }

label_800BE21C:
    ctx->downcount -= 1;
    // 800BE21C: b       0x800BE23C
    {
            goto label_800BE23C;
    }

label_800BE220:
    ctx->pc = 0x800BE220u;
    ctx->downcount -= 4;
    // 800BE220: lfs     f1, -15824(r18)
    if (!ppc_fp_available(ctx, 0x800BE220u)) return;
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(-15824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE224:
    // 800BE224: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE228:
    // 800BE228: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BE22C:
    // 800BE22C: bl      0x800C4664
    {
            ctx->lr = 0x800BE230u;
            ctx->pc = 0x800C4664u;
            return;
    }

label_800BE230:
    ctx->pc = 0x800BE230u;
    ctx->downcount -= 3;
    // 800BE230: lfs     f1, -15824(r18)
    if (!ppc_fp_available(ctx, 0x800BE230u)) return;
    {
        u32 ea = ctx->gpr[18] + (u32)(s32)(-15824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE234:
    // 800BE234: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE238:
    // 800BE238: bl      0x800C45F4
    {
            ctx->lr = 0x800BE23Cu;
            ctx->pc = 0x800C45F4u;
            return;
    }

label_800BE23C:
    ctx->pc = 0x800BE23Cu;
    ctx->downcount -= 13;
    // 800BE23C: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE240:
    // 800BE240: lis     r5, -20480
    ctx->gpr[5] = ((u32)(s32)(-20480) << 16);

label_800BE244:
    ctx->pc = 0x800BE244u;
    // 800BE244: lwz     r11, 4(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE248:
    // 800BE248: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE24C:
    ctx->pc = 0x800BE24Cu;
    // 800BE24C: lwz     r9, 8(r22)
    {
        u32 ea = ctx->gpr[22] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE250:
    // 800BE250: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BE254:
    ctx->pc = 0x800BE254u;
    // 800BE254: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE258:
    // 800BE258: ori     r5, r5, 0x020D
    ctx->gpr[5] = ctx->gpr[5] | 0x020Du;

label_800BE25C:
    ctx->pc = 0x800BE25Cu;
    // 800BE25C: lfs     f1, -15828(r21)
    if (!ppc_fp_available(ctx, 0x800BE25Cu)) return;
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(-15828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE260:
    // 800BE260: or   r6, r19, r19
    {
        ctx->gpr[6] = ctx->gpr[19] | ctx->gpr[19];
    }

label_800BE264:
    ctx->pc = 0x800BE264u;
    // 800BE264: stw     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BE268:
    ctx->pc = 0x800BE268u;
    // 800BE268: stw     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE26C:
    // 800BE26C: bl      0x800C457C
    {
            ctx->lr = 0x800BE270u;
            ctx->pc = 0x800C457Cu;
            return;
    }

label_800BE270:
    ctx->pc = 0x800BE270u;
    ctx->downcount -= 8;
    // 800BE270: lwz     r0, -31328(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31328);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE274:
    // 800BE274: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_800BE278:
    // 800BE278: addi    r19, r19, 52
    ctx->gpr[19] = ctx->gpr[19] + (u32)(s32)(52);

label_800BE27C:
    // 800BE27C: addi    r20, r20, 52
    ctx->gpr[20] = ctx->gpr[20] + (u32)(s32)(52);

label_800BE280:
    // 800BE280: cmpw    r26, r0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE284:
    // 800BE284: addi    r28, r28, 52
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(52);

label_800BE288:
    // 800BE288: addi    r25, r25, 52
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(52);

label_800BE28C:
    // 800BE28C: bc    12, 0, 0x800BE160
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE160u;
                return;
            }
            goto label_800BE160;
        }
    }

label_800BE290:
    ctx->pc = 0x800BE290u;
    ctx->downcount -= 9;
    // 800BE290: lwz     r10, -31324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31324);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE294:
    ctx->pc = 0x800BE294u;
    // 800BE294: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BE298:
    ctx->pc = 0x800BE298u;
    // 800BE298: addi    r11, r9, -2412
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-2412);

label_800BE29C:
    ctx->pc = 0x800BE29Cu;
    // 800BE29C: mulli   r0, r10, 52
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[10] * (s64)(s32)52);

label_800BE2A0:
    ctx->pc = 0x800BE2A0u;
    // 800BE2A0: lwzx    r9, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE2A4:
    ctx->pc = 0x800BE2A4u;
    // 800BE2A4: cmpwi   r9, -1
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

label_800BE2A8:
    ctx->pc = 0x800BE2A8u;
    // 800BE2A8: bc    12, 2, 0x800BE2CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE2CC;
        }
    }

label_800BE2AC:
    ctx->pc = 0x800BE2ACu;
    ctx->downcount -= 1;
    // 800BE2AC: or   r8, r11, r11
    {
        ctx->gpr[8] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BE2B0:
    loop_800BE2B0(ctx);
    if (ctx->pc == 0x800BE2C8u) goto label_800BE2C8;
    return;
label_800BE2B4:
    // 800BE2B4: mulli   r9, r11, 52
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[11] * (s64)(s32)52);

label_800BE2B8:
    // 800BE2B8: or   r10, r11, r11
    {
        ctx->gpr[10] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BE2BC:
    ctx->pc = 0x800BE2BCu;
    // 800BE2BC: lwzx    r0, r8, r9
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE2C0:
    // 800BE2C0: cmpwi   r0, -1
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

label_800BE2C4:
    // 800BE2C4: bc    4, 2, 0x800BE2B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE2B0u;
                return;
            }
            goto label_800BE2B0;
        }
    }

label_800BE2C8:
    ctx->pc = 0x800BE2C8u;
    ctx->downcount -= 1;
    // 800BE2C8: stw     r11, -31324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31324);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BE2CC:
    ctx->pc = 0x800BE2CCu;
    ctx->downcount -= 4;
    // 800BE2CC: lwz     r0, -31324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31324);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE2D0:
    ctx->pc = 0x800BE2D0u;
    // 800BE2D0: li      r26, 0
    ctx->gpr[26] = (u32)(s32)(0);

label_800BE2D4:
    ctx->pc = 0x800BE2D4u;
    // 800BE2D4: cmpw    r26, r0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE2D8:
    ctx->pc = 0x800BE2D8u;
    // 800BE2D8: bc    4, 0, 0x800BE4E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE4E8;
        }
    }

label_800BE2DC:
    ctx->pc = 0x800BE2DCu;
    ctx->downcount -= 13;
    // 800BE2DC: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BE2E0:
    ctx->pc = 0x800BE2E0u;
    // 800BE2E0: addi    r31, r1, 80
    ctx->gpr[31] = ctx->gpr[1] + (u32)(s32)(80);

label_800BE2E4:
    ctx->pc = 0x800BE2E4u;
    // 800BE2E4: addi    r24, r9, -2412
    ctx->gpr[24] = ctx->gpr[9] + (u32)(s32)(-2412);

label_800BE2E8:
    ctx->pc = 0x800BE2E8u;
    // 800BE2E8: lis     r23, -32737
    ctx->gpr[23] = ((u32)(s32)(-32737) << 16);

label_800BE2EC:
    ctx->pc = 0x800BE2ECu;
    // 800BE2EC: addi    r22, r24, 28
    ctx->gpr[22] = ctx->gpr[24] + (u32)(s32)(28);

label_800BE2F0:
    ctx->pc = 0x800BE2F0u;
    // 800BE2F0: addi    r14, r24, 48
    ctx->gpr[14] = ctx->gpr[24] + (u32)(s32)(48);

label_800BE2F4:
    ctx->pc = 0x800BE2F4u;
    // 800BE2F4: lis     r15, -32737
    ctx->gpr[15] = ((u32)(s32)(-32737) << 16);

label_800BE2F8:
    ctx->pc = 0x800BE2F8u;
    // 800BE2F8: addi    r18, r24, 32
    ctx->gpr[18] = ctx->gpr[24] + (u32)(s32)(32);

label_800BE2FC:
    ctx->pc = 0x800BE2FCu;
    // 800BE2FC: or   r19, r22, r22
    {
        ctx->gpr[19] = ctx->gpr[22] | ctx->gpr[22];
    }

label_800BE300:
    ctx->pc = 0x800BE300u;
    // 800BE300: or   r20, r22, r22
    {
        ctx->gpr[20] = ctx->gpr[22] | ctx->gpr[22];
    }

label_800BE304:
    ctx->pc = 0x800BE304u;
    // 800BE304: addi    r25, r24, 36
    ctx->gpr[25] = ctx->gpr[24] + (u32)(s32)(36);

label_800BE308:
    ctx->pc = 0x800BE308u;
    // 800BE308: li      r27, 0
    ctx->gpr[27] = (u32)(s32)(0);

label_800BE30C:
    ctx->pc = 0x800BE30Cu;
    // 800BE30C: or   r21, r29, r29
    {
        ctx->gpr[21] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE310:
    ctx->downcount -= 7;
    // 800BE310: addi    r9, r24, 24
    ctx->gpr[9] = ctx->gpr[24] + (u32)(s32)(24);

label_800BE314:
    // 800BE314: or   r3, r17, r17
    {
        ctx->gpr[3] = ctx->gpr[17] | ctx->gpr[17];
    }

label_800BE318:
    ctx->pc = 0x800BE318u;
    // 800BE318: lwzx    r4, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BE31C:
    // 800BE31C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE320:
    // 800BE320: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE324:
    // 800BE324: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BE328:
    // 800BE328: bl      0x800303A8
    {
            ctx->lr = 0x800BE32Cu;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BE32C:
    ctx->downcount -= 2;
    // 800BE32C: cmpwi   r3, 0
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

label_800BE330:
    // 800BE330: bc    12, 2, 0x800BE4C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE4C0;
        }
    }

label_800BE334:
    ctx->pc = 0x800BE334u;
    ctx->downcount -= 10;
    // 800BE334: lwz     r11, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE338:
    // 800BE338: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800BE33C:
    ctx->pc = 0x800BE33Cu;
    // 800BE33C: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE340:
    // 800BE340: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BE344:
    ctx->pc = 0x800BE344u;
    // 800BE344: lwz     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE348:
    ctx->pc = 0x800BE348u;
    // 800BE348: stw     r11, 0(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BE34C:
    ctx->pc = 0x800BE34Cu;
    // 800BE34C: stw     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE350:
    ctx->pc = 0x800BE350u;
    // 800BE350: stw     r0, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE354:
    ctx->pc = 0x800BE354u;
    // 800BE354: stwx    r10, r14, r27
    {
        u32 ea = ctx->gpr[14] + ctx->gpr[27];
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BE358:
    // 800BE358: bl      0x800BF484
    {
            ctx->lr = 0x800BE35Cu;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BE35C:
    ctx->downcount -= 2;
    // 800BE35C: cmpwi   r3, 0
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

label_800BE360:
    // 800BE360: bc    12, 2, 0x800BE470
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE470;
        }
    }

label_800BE364:
    ctx->downcount -= 4;
    // 800BE364: addi    r28, r24, 16
    ctx->gpr[28] = ctx->gpr[24] + (u32)(s32)(16);

label_800BE368:
    ctx->pc = 0x800BE368u;
    // 800BE368: lwzx    r5, r28, r27
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[27];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BE36C:
    // 800BE36C: cmpwi   r5, 0
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

label_800BE370:
    // 800BE370: bc    12, 2, 0x800BE470
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE470;
        }
    }

label_800BE374:
    ctx->downcount -= 4;
    // 800BE374: addi    r30, r24, 20
    ctx->gpr[30] = ctx->gpr[24] + (u32)(s32)(20);

label_800BE378:
    ctx->pc = 0x800BE378u;
    // 800BE378: lwzx    r0, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE37C:
    // 800BE37C: cmpwi   r0, 0
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

label_800BE380:
    // 800BE380: bc    12, 2, 0x800BE3F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE3F0;
        }
    }

label_800BE384:
    ctx->downcount -= 2;
    // 800BE384: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BE388:
    // 800BE388: bl      0x800BF320
    {
            ctx->lr = 0x800BE38Cu;
            ctx->pc = 0x800BF320u;
            return;
    }

label_800BE38C:
    ctx->downcount -= 2;
    // 800BE38C: cmpwi   r3, 0
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

label_800BE390:
    // 800BE390: bc    12, 2, 0x800BE3BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE3BC;
        }
    }

label_800BE394:
    ctx->pc = 0x800BE394u;
    ctx->downcount -= 10;
    // 800BE394: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE398:
    // 800BE398: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BE39C:
    ctx->pc = 0x800BE39Cu;
    // 800BE39C: lwz     r11, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE3A0:
    // 800BE3A0: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE3A4:
    ctx->pc = 0x800BE3A4u;
    // 800BE3A4: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE3A8:
    // 800BE3A8: or   r6, r20, r20
    {
        ctx->gpr[6] = ctx->gpr[20] | ctx->gpr[20];
    }

label_800BE3AC:
    ctx->pc = 0x800BE3ACu;
    // 800BE3AC: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE3B0:
    ctx->pc = 0x800BE3B0u;
    // 800BE3B0: lfs     f1, -15828(r23)
    if (!ppc_fp_available(ctx, 0x800BE3B0u)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(-15828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE3B4:
    ctx->pc = 0x800BE3B4u;
    // 800BE3B4: lwzx    r5, r30, r27
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[27];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BE3B8:
    // 800BE3B8: b       0x800BE3E0
    {
            goto label_800BE3E0;
    }

label_800BE3BC:
    ctx->pc = 0x800BE3BCu;
    ctx->downcount -= 9;
    // 800BE3BC: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE3C0:
    // 800BE3C0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BE3C4:
    ctx->pc = 0x800BE3C4u;
    // 800BE3C4: lwz     r11, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE3C8:
    // 800BE3C8: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE3CC:
    ctx->pc = 0x800BE3CCu;
    // 800BE3CC: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE3D0:
    // 800BE3D0: or   r6, r22, r22
    {
        ctx->gpr[6] = ctx->gpr[22] | ctx->gpr[22];
    }

label_800BE3D4:
    ctx->pc = 0x800BE3D4u;
    // 800BE3D4: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE3D8:
    ctx->pc = 0x800BE3D8u;
    // 800BE3D8: lfs     f1, -15828(r23)
    if (!ppc_fp_available(ctx, 0x800BE3D8u)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(-15828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE3DC:
    ctx->pc = 0x800BE3DCu;
    // 800BE3DC: lwzx    r5, r28, r27
    {
        u32 ea = ctx->gpr[28] + ctx->gpr[27];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BE3E0:
    ctx->pc = 0x800BE3E0u;
    ctx->downcount -= 3;
    // 800BE3E0: stw     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BE3E4:
    ctx->pc = 0x800BE3E4u;
    // 800BE3E4: stw     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE3E8:
    // 800BE3E8: bl      0x800C457C
    {
            ctx->lr = 0x800BE3ECu;
            ctx->pc = 0x800C457Cu;
            return;
    }

label_800BE3EC:
    ctx->downcount -= 1;
    // 800BE3EC: b       0x800BE41C
    {
            goto label_800BE41C;
    }

label_800BE3F0:
    ctx->pc = 0x800BE3F0u;
    ctx->downcount -= 11;
    // 800BE3F0: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE3F4:
    // 800BE3F4: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BE3F8:
    ctx->pc = 0x800BE3F8u;
    // 800BE3F8: lwz     r11, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE3FC:
    // 800BE3FC: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE400:
    ctx->pc = 0x800BE400u;
    // 800BE400: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE404:
    // 800BE404: or   r6, r19, r19
    {
        ctx->gpr[6] = ctx->gpr[19] | ctx->gpr[19];
    }

label_800BE408:
    ctx->pc = 0x800BE408u;
    // 800BE408: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE40C:
    ctx->pc = 0x800BE40Cu;
    // 800BE40C: lfs     f1, -15828(r23)
    if (!ppc_fp_available(ctx, 0x800BE40Cu)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(-15828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE410:
    ctx->pc = 0x800BE410u;
    // 800BE410: stw     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BE414:
    ctx->pc = 0x800BE414u;
    // 800BE414: stw     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE418:
    // 800BE418: bl      0x800C457C
    {
            ctx->lr = 0x800BE41Cu;
            ctx->pc = 0x800C457Cu;
            return;
    }

label_800BE41C:
    ctx->pc = 0x800BE41Cu;
    ctx->downcount -= 3;
    // 800BE41C: lwz     r30, -8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(-8);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800BE420:
    // 800BE420: cmpwi   r30, 0
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

label_800BE424:
    // 800BE424: bc    12, 2, 0x800BE470
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE470;
        }
    }

label_800BE428:
    ctx->downcount -= 6;
    // 800BE428: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_800BE42C:
    // 800BE42C: addi    r11, r11, -21636
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(-21636);

label_800BE430:
    ctx->pc = 0x800BE430u;
    // 800BE430: lwz     r9, 1004(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(1004);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE434:
    // 800BE434: addi    r9, r9, -8
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-8);

label_800BE438:
    // 800BE438: cmpw    r9, r26
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(ctx->gpr[26]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE43C:
    // 800BE43C: bc    4, 2, 0x800BE454
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE454;
        }
    }

label_800BE440:
    ctx->pc = 0x800BE440u;
    ctx->downcount -= 4;
    // 800BE440: lfs     f1, -15824(r15)
    if (!ppc_fp_available(ctx, 0x800BE440u)) return;
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(-15824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE444:
    // 800BE444: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE448:
    // 800BE448: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BE44C:
    // 800BE44C: bl      0x800C4664
    {
            ctx->lr = 0x800BE450u;
            ctx->pc = 0x800C4664u;
            return;
    }

label_800BE450:
    ctx->downcount -= 1;
    // 800BE450: b       0x800BE470
    {
            goto label_800BE470;
    }

label_800BE454:
    ctx->pc = 0x800BE454u;
    ctx->downcount -= 4;
    // 800BE454: lfs     f1, -15824(r15)
    if (!ppc_fp_available(ctx, 0x800BE454u)) return;
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(-15824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE458:
    // 800BE458: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE45C:
    // 800BE45C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BE460:
    // 800BE460: bl      0x800C4664
    {
            ctx->lr = 0x800BE464u;
            ctx->pc = 0x800C4664u;
            return;
    }

label_800BE464:
    ctx->pc = 0x800BE464u;
    ctx->downcount -= 3;
    // 800BE464: lfs     f1, -15824(r15)
    if (!ppc_fp_available(ctx, 0x800BE464u)) return;
    {
        u32 ea = ctx->gpr[15] + (u32)(s32)(-15824);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE468:
    // 800BE468: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE46C:
    // 800BE46C: bl      0x800C45F4
    {
            ctx->lr = 0x800BE470u;
            ctx->pc = 0x800C45F4u;
            return;
    }

label_800BE470:
    ctx->downcount -= 2;
    // 800BE470: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BE474:
    // 800BE474: bl      0x800BF484
    {
            ctx->lr = 0x800BE478u;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BE478:
    ctx->downcount -= 2;
    // 800BE478: cmpwi   r3, 0
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

label_800BE47C:
    // 800BE47C: bc    4, 2, 0x800BE48C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE48C;
        }
    }

label_800BE480:
    ctx->downcount -= 3;
    // 800BE480: addi    r0, r26, -1
    ctx->gpr[0] = ctx->gpr[26] + (u32)(s32)(-1);

label_800BE484:
    // 800BE484: cmplwi  r0, 0x0001
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0001u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE488:
    // 800BE488: bc    4, 1, 0x800BE4C0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE4C0;
        }
    }

label_800BE48C:
    ctx->pc = 0x800BE48Cu;
    ctx->downcount -= 13;
    // 800BE48C: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE490:
    // 800BE490: lis     r5, -20480
    ctx->gpr[5] = ((u32)(s32)(-20480) << 16);

label_800BE494:
    ctx->pc = 0x800BE494u;
    // 800BE494: lwz     r11, 4(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE498:
    // 800BE498: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BE49C:
    ctx->pc = 0x800BE49Cu;
    // 800BE49C: lwz     r9, 8(r21)
    {
        u32 ea = ctx->gpr[21] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE4A0:
    // 800BE4A0: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE4A4:
    ctx->pc = 0x800BE4A4u;
    // 800BE4A4: stw     r0, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE4A8:
    // 800BE4A8: ori     r5, r5, 0x020D
    ctx->gpr[5] = ctx->gpr[5] | 0x020Du;

label_800BE4AC:
    ctx->pc = 0x800BE4ACu;
    // 800BE4AC: lfs     f1, -15828(r23)
    if (!ppc_fp_available(ctx, 0x800BE4ACu)) return;
    {
        u32 ea = ctx->gpr[23] + (u32)(s32)(-15828);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE4B0:
    // 800BE4B0: or   r6, r18, r18
    {
        ctx->gpr[6] = ctx->gpr[18] | ctx->gpr[18];
    }

label_800BE4B4:
    ctx->pc = 0x800BE4B4u;
    // 800BE4B4: stw     r11, 4(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BE4B8:
    ctx->pc = 0x800BE4B8u;
    // 800BE4B8: stw     r9, 8(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE4BC:
    // 800BE4BC: bl      0x800C457C
    {
            ctx->lr = 0x800BE4C0u;
            ctx->pc = 0x800C457Cu;
            return;
    }

label_800BE4C0:
    ctx->pc = 0x800BE4C0u;
    ctx->downcount -= 10;
    // 800BE4C0: lwz     r0, -31324(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31324);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE4C4:
    // 800BE4C4: addi    r26, r26, 1
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(1);

label_800BE4C8:
    // 800BE4C8: addi    r18, r18, 52
    ctx->gpr[18] = ctx->gpr[18] + (u32)(s32)(52);

label_800BE4CC:
    // 800BE4CC: addi    r19, r19, 52
    ctx->gpr[19] = ctx->gpr[19] + (u32)(s32)(52);

label_800BE4D0:
    // 800BE4D0: cmpw    r26, r0
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[0]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE4D4:
    // 800BE4D4: addi    r22, r22, 52
    ctx->gpr[22] = ctx->gpr[22] + (u32)(s32)(52);

label_800BE4D8:
    // 800BE4D8: addi    r20, r20, 52
    ctx->gpr[20] = ctx->gpr[20] + (u32)(s32)(52);

label_800BE4DC:
    // 800BE4DC: addi    r25, r25, 52
    ctx->gpr[25] = ctx->gpr[25] + (u32)(s32)(52);

label_800BE4E0:
    // 800BE4E0: addi    r27, r27, 52
    ctx->gpr[27] = ctx->gpr[27] + (u32)(s32)(52);

label_800BE4E4:
    // 800BE4E4: bc    12, 0, 0x800BE310
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE310u;
                return;
            }
            goto label_800BE310;
        }
    }

label_800BE4E8:
    ctx->pc = 0x800BE4E8u;
    ctx->downcount -= 7;
    // 800BE4E8: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BE4EC:
    ctx->pc = 0x800BE4ECu;
    // 800BE4EC: or   r3, r17, r17
    {
        ctx->gpr[3] = ctx->gpr[17] | ctx->gpr[17];
    }

label_800BE4F0:
    ctx->pc = 0x800BE4F0u;
    // 800BE4F0: ori     r4, r4, 0x0071
    ctx->gpr[4] = ctx->gpr[4] | 0x0071u;

label_800BE4F4:
    ctx->pc = 0x800BE4F4u;
    // 800BE4F4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE4F8:
    ctx->pc = 0x800BE4F8u;
    // 800BE4F8: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE4FC:
    ctx->pc = 0x800BE4FCu;
    // 800BE4FC: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BE500:
    ctx->pc = 0x800BE500u;
    // 800BE500: bl      0x800303A8
    {
            ctx->lr = 0x800BE504u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BE504:
    ctx->pc = 0x800BE504u;
    ctx->downcount -= 2;
    // 800BE504: cmpwi   r3, 0
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

label_800BE508:
    ctx->pc = 0x800BE508u;
    // 800BE508: bc    12, 2, 0x800BE540
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE540;
        }
    }

label_800BE50C:
    ctx->pc = 0x800BE50Cu;
    ctx->downcount -= 6;
    // 800BE50C: addi    r30, r1, 64
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(64);

label_800BE510:
    ctx->pc = 0x800BE510u;
    // 800BE510: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE514:
    ctx->pc = 0x800BE514u;
    // 800BE514: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE518:
    ctx->pc = 0x800BE518u;
    // 800BE518: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE51C:
    ctx->pc = 0x800BE51Cu;
    // 800BE51C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BE520:
    ctx->pc = 0x800BE520u;
    // 800BE520: bl      0x800C48AC
    {
            ctx->lr = 0x800BE524u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BE524:
    ctx->pc = 0x800BE524u;
    ctx->downcount -= 7;
    // 800BE524: lwz     r10, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE528:
    ctx->pc = 0x800BE528u;
    // 800BE528: addi    r11, r16, 1420
    ctx->gpr[11] = ctx->gpr[16] + (u32)(s32)(1420);

label_800BE52C:
    ctx->pc = 0x800BE52Cu;
    // 800BE52C: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE530:
    ctx->pc = 0x800BE530u;
    // 800BE530: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE534:
    ctx->pc = 0x800BE534u;
    // 800BE534: stw     r10, 1420(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(1420);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BE538:
    ctx->pc = 0x800BE538u;
    // 800BE538: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE53C:
    ctx->pc = 0x800BE53Cu;
    // 800BE53C: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE540:
    ctx->pc = 0x800BE540u;
    ctx->downcount -= 7;
    // 800BE540: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BE544:
    ctx->pc = 0x800BE544u;
    // 800BE544: or   r3, r17, r17
    {
        ctx->gpr[3] = ctx->gpr[17] | ctx->gpr[17];
    }

label_800BE548:
    ctx->pc = 0x800BE548u;
    // 800BE548: ori     r4, r4, 0x0072
    ctx->gpr[4] = ctx->gpr[4] | 0x0072u;

label_800BE54C:
    ctx->pc = 0x800BE54Cu;
    // 800BE54C: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE550:
    ctx->pc = 0x800BE550u;
    // 800BE550: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE554:
    ctx->pc = 0x800BE554u;
    // 800BE554: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BE558:
    ctx->pc = 0x800BE558u;
    // 800BE558: bl      0x800303A8
    {
            ctx->lr = 0x800BE55Cu;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BE55C:
    ctx->pc = 0x800BE55Cu;
    ctx->downcount -= 2;
    // 800BE55C: cmpwi   r3, 0
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

label_800BE560:
    ctx->pc = 0x800BE560u;
    // 800BE560: bc    12, 2, 0x800BE598
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE598;
        }
    }

label_800BE564:
    ctx->pc = 0x800BE564u;
    ctx->downcount -= 6;
    // 800BE564: addi    r30, r1, 64
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(64);

label_800BE568:
    ctx->pc = 0x800BE568u;
    // 800BE568: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE56C:
    ctx->pc = 0x800BE56Cu;
    // 800BE56C: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE570:
    ctx->pc = 0x800BE570u;
    // 800BE570: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE574:
    ctx->pc = 0x800BE574u;
    // 800BE574: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BE578:
    ctx->pc = 0x800BE578u;
    // 800BE578: bl      0x800C48AC
    {
            ctx->lr = 0x800BE57Cu;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BE57C:
    ctx->pc = 0x800BE57Cu;
    ctx->downcount -= 7;
    // 800BE57C: lwz     r10, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE580:
    ctx->pc = 0x800BE580u;
    // 800BE580: addi    r11, r16, 1432
    ctx->gpr[11] = ctx->gpr[16] + (u32)(s32)(1432);

label_800BE584:
    ctx->pc = 0x800BE584u;
    // 800BE584: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE588:
    ctx->pc = 0x800BE588u;
    // 800BE588: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE58C:
    ctx->pc = 0x800BE58Cu;
    // 800BE58C: stw     r10, 1432(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(1432);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BE590:
    ctx->pc = 0x800BE590u;
    // 800BE590: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE594:
    ctx->pc = 0x800BE594u;
    // 800BE594: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE598:
    ctx->pc = 0x800BE598u;
    ctx->downcount -= 7;
    // 800BE598: lis     r4, 24576
    ctx->gpr[4] = ((u32)(s32)(24576) << 16);

label_800BE59C:
    ctx->pc = 0x800BE59Cu;
    // 800BE59C: or   r3, r17, r17
    {
        ctx->gpr[3] = ctx->gpr[17] | ctx->gpr[17];
    }

label_800BE5A0:
    ctx->pc = 0x800BE5A0u;
    // 800BE5A0: ori     r4, r4, 0x0073
    ctx->gpr[4] = ctx->gpr[4] | 0x0073u;

label_800BE5A4:
    ctx->pc = 0x800BE5A4u;
    // 800BE5A4: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE5A8:
    ctx->pc = 0x800BE5A8u;
    // 800BE5A8: or   r6, r29, r29
    {
        ctx->gpr[6] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE5AC:
    ctx->pc = 0x800BE5ACu;
    // 800BE5AC: li      r7, -1
    ctx->gpr[7] = (u32)(s32)(-1);

label_800BE5B0:
    ctx->pc = 0x800BE5B0u;
    // 800BE5B0: bl      0x800303A8
    {
            ctx->lr = 0x800BE5B4u;
            ctx->pc = 0x800303A8u;
            return;
    }

label_800BE5B4:
    ctx->pc = 0x800BE5B4u;
    ctx->downcount -= 2;
    // 800BE5B4: cmpwi   r3, 0
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

label_800BE5B8:
    ctx->pc = 0x800BE5B8u;
    // 800BE5B8: bc    12, 2, 0x800BE5F0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE5F0;
        }
    }

label_800BE5BC:
    ctx->pc = 0x800BE5BCu;
    ctx->downcount -= 6;
    // 800BE5BC: addi    r30, r1, 64
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(64);

label_800BE5C0:
    ctx->pc = 0x800BE5C0u;
    // 800BE5C0: or   r4, r29, r29
    {
        ctx->gpr[4] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE5C4:
    ctx->pc = 0x800BE5C4u;
    // 800BE5C4: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE5C8:
    ctx->pc = 0x800BE5C8u;
    // 800BE5C8: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BE5CC:
    ctx->pc = 0x800BE5CCu;
    // 800BE5CC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BE5D0:
    ctx->pc = 0x800BE5D0u;
    // 800BE5D0: bl      0x800C48AC
    {
            ctx->lr = 0x800BE5D4u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BE5D4:
    ctx->pc = 0x800BE5D4u;
    ctx->downcount -= 7;
    // 800BE5D4: lwz     r10, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE5D8:
    ctx->pc = 0x800BE5D8u;
    // 800BE5D8: addi    r11, r16, 1444
    ctx->gpr[11] = ctx->gpr[16] + (u32)(s32)(1444);

label_800BE5DC:
    ctx->pc = 0x800BE5DCu;
    // 800BE5DC: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE5E0:
    ctx->pc = 0x800BE5E0u;
    // 800BE5E0: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE5E4:
    ctx->pc = 0x800BE5E4u;
    // 800BE5E4: stw     r10, 1444(r16)
    {
        u32 ea = ctx->gpr[16] + (u32)(s32)(1444);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BE5E8:
    ctx->pc = 0x800BE5E8u;
    // 800BE5E8: stw     r0, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE5EC:
    ctx->pc = 0x800BE5ECu;
    // 800BE5EC: stw     r9, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE5F0:
    ctx->pc = 0x800BE5F0u;
    ctx->downcount -= 2;
    // 800BE5F0: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800BE5F4:
    ctx->pc = 0x800BE5F4u;
    // 800BE5F4: bl      0x800B7A68
    {
            ctx->lr = 0x800BE5F8u;
            ctx->pc = 0x800B7A68u;
            return;
    }

label_800BE5F8:
    ctx->pc = 0x800BE5F8u;
    ctx->downcount -= 1;
    // 800BE5F8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800BE5FC:
    ctx->pc = 0x800BE5FCu;
    ctx->downcount -= 16;
    // 800BE5FC: lwz     r0, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE600:
    ctx->pc = 0x800BE600u;
    // 800BE600: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BE604:
    ctx->pc = 0x800BE604u;
    // 800BE604: lmw     r14, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BE608:
    ctx->pc = 0x800BE608u;
    // 800BE608: addi    r1, r1, 168
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(168);

label_800BE60C:
    ctx->pc = 0x800BE60Cu;
    // 800BE60C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BE610:
    ctx->pc = 0x800BE610u;
    ctx->downcount -= 20;
    // 800BE610: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BE614:
    ctx->pc = 0x800BE614u;
    // 800BE614: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BE618:
    ctx->pc = 0x800BE618u;
    // 800BE618: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BE61C:
    ctx->pc = 0x800BE61Cu;
    // 800BE61C: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE620:
    ctx->pc = 0x800BE620u;
    // 800BE620: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BE624:
    ctx->pc = 0x800BE624u;
    // 800BE624: or   r28, r3, r3
    {
        ctx->gpr[28] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BE628:
    ctx->pc = 0x800BE628u;
    // 800BE628: addi    r9, r9, -2880
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BE62C:
    ctx->pc = 0x800BE62Cu;
    // 800BE62C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE630:
    ctx->pc = 0x800BE630u;
    // 800BE630: cmpwi   r0, -1
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

label_800BE634:
    ctx->pc = 0x800BE634u;
    // 800BE634: bc    12, 2, 0x800BE668
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE668;
        }
    }

label_800BE638:
    ctx->pc = 0x800BE638u;
    ctx->downcount -= 3;
    // 800BE638: or   r31, r9, r9
    {
        ctx->gpr[31] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BE63C:
    ctx->pc = 0x800BE63Cu;
    // 800BE63C: addi    r30, r31, 32
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(32);

label_800BE640:
    ctx->pc = 0x800BE640u;
    // 800BE640: addi    r29, r31, 28
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(28);

label_800BE644:
    ctx->downcount -= 2;
    // 800BE644: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE648:
    // 800BE648: bl      0x800C4764
    {
            ctx->lr = 0x800BE64Cu;
            ctx->pc = 0x800C4764u;
            return;
    }

label_800BE64C:
    ctx->downcount -= 3;
    // 800BE64C: addi    r29, r29, 52
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(52);

label_800BE650:
    // 800BE650: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE654:
    // 800BE654: bl      0x800C4764
    {
            ctx->lr = 0x800BE658u;
            ctx->pc = 0x800C4764u;
            return;
    }

label_800BE658:
    ctx->downcount -= 4;
    // 800BE658: addi    r30, r30, 52
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(52);

label_800BE65C:
    ctx->pc = 0x800BE65Cu;
    // 800BE65C: lwzu     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[31] = ea;
    }

label_800BE660:
    // 800BE660: cmpwi   r0, -1
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

label_800BE664:
    // 800BE664: bc    4, 2, 0x800BE644
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE644u;
                return;
            }
            goto label_800BE644;
        }
    }

label_800BE668:
    ctx->pc = 0x800BE668u;
    ctx->downcount -= 6;
    // 800BE668: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BE66C:
    ctx->pc = 0x800BE66Cu;
    // 800BE66C: addi    r28, r28, 24
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(24);

label_800BE670:
    ctx->pc = 0x800BE670u;
    // 800BE670: addi    r9, r9, -2412
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2412);

label_800BE674:
    ctx->pc = 0x800BE674u;
    // 800BE674: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE678:
    ctx->pc = 0x800BE678u;
    // 800BE678: cmpwi   r0, -1
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

label_800BE67C:
    ctx->pc = 0x800BE67Cu;
    // 800BE67C: bc    12, 2, 0x800BE6B0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE6B0;
        }
    }

label_800BE680:
    ctx->pc = 0x800BE680u;
    ctx->downcount -= 3;
    // 800BE680: or   r31, r9, r9
    {
        ctx->gpr[31] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BE684:
    ctx->pc = 0x800BE684u;
    // 800BE684: addi    r30, r31, 32
    ctx->gpr[30] = ctx->gpr[31] + (u32)(s32)(32);

label_800BE688:
    ctx->pc = 0x800BE688u;
    // 800BE688: addi    r29, r31, 28
    ctx->gpr[29] = ctx->gpr[31] + (u32)(s32)(28);

label_800BE68C:
    ctx->downcount -= 2;
    // 800BE68C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BE690:
    // 800BE690: bl      0x800C4764
    {
            ctx->lr = 0x800BE694u;
            ctx->pc = 0x800C4764u;
            return;
    }

label_800BE694:
    ctx->downcount -= 3;
    // 800BE694: addi    r29, r29, 52
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(52);

label_800BE698:
    // 800BE698: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BE69C:
    // 800BE69C: bl      0x800C4764
    {
            ctx->lr = 0x800BE6A0u;
            ctx->pc = 0x800C4764u;
            return;
    }

label_800BE6A0:
    ctx->downcount -= 4;
    // 800BE6A0: addi    r30, r30, 52
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(52);

label_800BE6A4:
    ctx->pc = 0x800BE6A4u;
    // 800BE6A4: lwzu     r0, 52(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[31] = ea;
    }

label_800BE6A8:
    // 800BE6A8: cmpwi   r0, -1
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

label_800BE6AC:
    // 800BE6AC: bc    4, 2, 0x800BE68C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BE68Cu;
                return;
            }
            goto label_800BE68C;
        }
    }

label_800BE6B0:
    ctx->pc = 0x800BE6B0u;
    ctx->downcount -= 2;
    // 800BE6B0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BE6B4:
    ctx->pc = 0x800BE6B4u;
    // 800BE6B4: bl      0x800C4764
    {
            ctx->lr = 0x800BE6B8u;
            ctx->pc = 0x800C4764u;
            return;
    }

label_800BE6B8:
    ctx->pc = 0x800BE6B8u;
    ctx->downcount -= 16;
    // 800BE6B8: lwz     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE6BC:
    ctx->pc = 0x800BE6BCu;
    // 800BE6BC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BE6C0:
    ctx->pc = 0x800BE6C0u;
    // 800BE6C0: lmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BE6C4:
    ctx->pc = 0x800BE6C4u;
    // 800BE6C4: addi    r1, r1, 24
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(24);

label_800BE6C8:
    ctx->pc = 0x800BE6C8u;
    // 800BE6C8: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BE6CC:
    ctx->pc = 0x800BE6CCu;
    ctx->downcount -= 29;
    // 800BE6CC: stwu     r1, -120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-120);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BE6D0:
    ctx->pc = 0x800BE6D0u;
    // 800BE6D0: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BE6D4:
    ctx->pc = 0x800BE6D4u;
    // 800BE6D4: mfcr    r12
    ctx->gpr[12] = ctx->cr;

label_800BE6D8:
    ctx->pc = 0x800BE6D8u;
    // 800BE6D8: stmw     r24, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        for (u32 r = 24; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BE6DC:
    ctx->pc = 0x800BE6DCu;
    // 800BE6DC: stw     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE6E0:
    ctx->pc = 0x800BE6E0u;
    // 800BE6E0: stw     r12, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[12]);
    }

label_800BE6E4:
    ctx->pc = 0x800BE6E4u;
    // 800BE6E4: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BE6E8:
    ctx->pc = 0x800BE6E8u;
    // 800BE6E8: lis     r0, 64
    ctx->gpr[0] = ((u32)(s32)(64) << 16);

label_800BE6EC:
    ctx->pc = 0x800BE6ECu;
    // 800BE6EC: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BE6F0:
    ctx->pc = 0x800BE6F0u;
    // 800BE6F0: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_800BE6F4:
    ctx->pc = 0x800BE6F4u;
    // 800BE6F4: lwz     r10, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE6F8:
    ctx->pc = 0x800BE6F8u;
    // 800BE6F8: or   r24, r3, r3
    {
        ctx->gpr[24] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BE6FC:
    ctx->pc = 0x800BE6FCu;
    // 800BE6FC: lwz     r11, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE700:
    ctx->pc = 0x800BE700u;
    // 800BE700: li      r25, -1
    ctx->gpr[25] = (u32)(s32)(-1);

label_800BE704:
    ctx->pc = 0x800BE704u;
    // 800BE704: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_800BE708:
    ctx->pc = 0x800BE708u;
    // 800BE708: xor   r11, r11, r10
    {
        ctx->gpr[11] = ctx->gpr[11] ^ ctx->gpr[10];
    }

label_800BE70C:
    ctx->pc = 0x800BE70Cu;
    // 800BE70C: and   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] & ctx->gpr[0];
    }

label_800BE710:
    ctx->pc = 0x800BE710u;
    // 800BE710: and.   r9, r0, r10
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

label_800BE714:
    ctx->pc = 0x800BE714u;
    // 800BE714: bc    12, 2, 0x800BE754
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE754;
        }
    }

label_800BE718:
    ctx->pc = 0x800BE718u;
    ctx->downcount -= 6;
    // 800BE718: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE71C:
    ctx->pc = 0x800BE71Cu;
    // 800BE71C: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE720:
    ctx->pc = 0x800BE720u;
    // 800BE720: lwz     r11, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE724:
    ctx->pc = 0x800BE724u;
    // 800BE724: cmpwi   r11, 0
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

label_800BE728:
    ctx->pc = 0x800BE728u;
    // 800BE728: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_800BE72C:
    ctx->pc = 0x800BE72Cu;
    // 800BE72C: bc    4, 1, 0x800BE734
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE734;
        }
    }

label_800BE730:
    ctx->pc = 0x800BE730u;
    ctx->downcount -= 1;
    // 800BE730: addi    r0, r11, -1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(-1);

label_800BE734:
    ctx->pc = 0x800BE734u;
    ctx->downcount -= 7;
    // 800BE734: stw     r0, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE738:
    ctx->pc = 0x800BE738u;
    // 800BE738: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BE73C:
    ctx->pc = 0x800BE73Cu;
    // 800BE73C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BE740:
    ctx->pc = 0x800BE740u;
    // 800BE740: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BE740u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE744:
    ctx->pc = 0x800BE744u;
    // 800BE744: ori     r3, r3, 0x006A
    ctx->gpr[3] = ctx->gpr[3] | 0x006Au;

label_800BE748:
    ctx->pc = 0x800BE748u;
    // 800BE748: li      r28, -1
    ctx->gpr[28] = (u32)(s32)(-1);

label_800BE74C:
    ctx->pc = 0x800BE74Cu;
    // 800BE74C: bl      0x8004DC00
    {
            ctx->lr = 0x800BE750u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BE750:
    ctx->pc = 0x800BE750u;
    ctx->downcount -= 1;
    // 800BE750: b       0x800BE80C
    {
            goto label_800BE80C;
    }

label_800BE754:
    ctx->pc = 0x800BE754u;
    ctx->downcount -= 5;
    // 800BE754: lis     r0, 128
    ctx->gpr[0] = ((u32)(s32)(128) << 16);

label_800BE758:
    ctx->pc = 0x800BE758u;
    // 800BE758: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_800BE75C:
    ctx->pc = 0x800BE75Cu;
    // 800BE75C: and   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] & ctx->gpr[0];
    }

label_800BE760:
    ctx->pc = 0x800BE760u;
    // 800BE760: and.   r9, r0, r10
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

label_800BE764:
    ctx->pc = 0x800BE764u;
    // 800BE764: bc    12, 2, 0x800BE7A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE7A4;
        }
    }

label_800BE768:
    ctx->pc = 0x800BE768u;
    ctx->downcount -= 6;
    // 800BE768: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE76C:
    ctx->pc = 0x800BE76Cu;
    // 800BE76C: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE770:
    ctx->pc = 0x800BE770u;
    // 800BE770: lwz     r11, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BE774:
    ctx->pc = 0x800BE774u;
    // 800BE774: cmpwi   r11, 15
    {
        s32 val_a = (s32)(ctx->gpr[11]);
        s32 val_b = (s32)(15);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE778:
    ctx->pc = 0x800BE778u;
    // 800BE778: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BE77C:
    ctx->pc = 0x800BE77Cu;
    // 800BE77C: bc    12, 1, 0x800BE784
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE784;
        }
    }

label_800BE780:
    ctx->pc = 0x800BE780u;
    ctx->downcount -= 1;
    // 800BE780: addi    r0, r11, 1
    ctx->gpr[0] = ctx->gpr[11] + (u32)(s32)(1);

label_800BE784:
    ctx->pc = 0x800BE784u;
    ctx->downcount -= 7;
    // 800BE784: stw     r0, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE788:
    ctx->pc = 0x800BE788u;
    // 800BE788: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BE78C:
    ctx->pc = 0x800BE78Cu;
    // 800BE78C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BE790:
    ctx->pc = 0x800BE790u;
    // 800BE790: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BE790u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE794:
    ctx->pc = 0x800BE794u;
    // 800BE794: ori     r3, r3, 0x006A
    ctx->gpr[3] = ctx->gpr[3] | 0x006Au;

label_800BE798:
    ctx->pc = 0x800BE798u;
    // 800BE798: li      r28, 1
    ctx->gpr[28] = (u32)(s32)(1);

label_800BE79C:
    ctx->pc = 0x800BE79Cu;
    // 800BE79C: bl      0x8004DC00
    {
            ctx->lr = 0x800BE7A0u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BE7A0:
    ctx->pc = 0x800BE7A0u;
    ctx->downcount -= 1;
    // 800BE7A0: b       0x800BE80C
    {
            goto label_800BE80C;
    }

label_800BE7A4:
    ctx->pc = 0x800BE7A4u;
    ctx->downcount -= 5;
    // 800BE7A4: lis     r0, 16
    ctx->gpr[0] = ((u32)(s32)(16) << 16);

label_800BE7A8:
    ctx->pc = 0x800BE7A8u;
    // 800BE7A8: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_800BE7AC:
    ctx->pc = 0x800BE7ACu;
    // 800BE7AC: and   r0, r11, r0
    {
        ctx->gpr[0] = ctx->gpr[11] & ctx->gpr[0];
    }

label_800BE7B0:
    ctx->pc = 0x800BE7B0u;
    // 800BE7B0: and.   r9, r0, r10
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

label_800BE7B4:
    ctx->pc = 0x800BE7B4u;
    // 800BE7B4: bc    12, 2, 0x800BE80C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE80C;
        }
    }

label_800BE7B8:
    ctx->pc = 0x800BE7B8u;
    ctx->downcount -= 6;
    // 800BE7B8: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE7BC:
    ctx->pc = 0x800BE7BCu;
    // 800BE7BC: addi    r30, r9, -21636
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE7C0:
    ctx->pc = 0x800BE7C0u;
    // 800BE7C0: lwz     r29, 1004(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1004);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_800BE7C4:
    ctx->pc = 0x800BE7C4u;
    // 800BE7C4: cmpwi   r29, 7
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE7C8:
    ctx->pc = 0x800BE7C8u;
    // 800BE7C8: mfcr    r31
    ctx->gpr[31] = ctx->cr;

label_800BE7CC:
    ctx->pc = 0x800BE7CCu;
    // 800BE7CC: bc    4, 1, 0x800BE7D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE7D8;
        }
    }

label_800BE7D0:
    ctx->pc = 0x800BE7D0u;
    ctx->downcount -= 2;
    // 800BE7D0: addi    r0, r29, -8
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(-8);

label_800BE7D4:
    ctx->pc = 0x800BE7D4u;
    // 800BE7D4: stw     r0, 1004(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE7D8:
    ctx->pc = 0x800BE7D8u;
    ctx->downcount -= 5;
    // 800BE7D8: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BE7DC:
    ctx->pc = 0x800BE7DCu;
    // 800BE7DC: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BE7E0:
    ctx->pc = 0x800BE7E0u;
    // 800BE7E0: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BE7E0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE7E4:
    ctx->pc = 0x800BE7E4u;
    // 800BE7E4: ori     r3, r3, 0x006A
    ctx->gpr[3] = ctx->gpr[3] | 0x006Au;

label_800BE7E8:
    ctx->pc = 0x800BE7E8u;
    // 800BE7E8: bl      0x8004DC00
    {
            ctx->lr = 0x800BE7ECu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BE7EC:
    ctx->pc = 0x800BE7ECu;
    ctx->downcount -= 2;
    // 800BE7EC: mtcrf   0x80, r31
    ctx->cr = (ctx->cr & ~0xF0000000u) | (ctx->gpr[31] & 0xF0000000u);

label_800BE7F0:
    ctx->pc = 0x800BE7F0u;
    // 800BE7F0: bc    4, 1, 0x800BE80C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE80C;
        }
    }

label_800BE7F4:
    ctx->pc = 0x800BE7F4u;
    ctx->downcount -= 3;
    // 800BE7F4: addi    r0, r29, -8
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(-8);

label_800BE7F8:
    ctx->pc = 0x800BE7F8u;
    // 800BE7F8: cmpwi   r0, 1
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

label_800BE7FC:
    ctx->pc = 0x800BE7FCu;
    // 800BE7FC: bc    4, 1, 0x800BE80C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE80C;
        }
    }

label_800BE800:
    ctx->pc = 0x800BE800u;
    ctx->downcount -= 3;
    // 800BE800: lwz     r9, 1004(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1004);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE804:
    ctx->pc = 0x800BE804u;
    // 800BE804: addi    r9, r9, -1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-1);

label_800BE808:
    ctx->pc = 0x800BE808u;
    // 800BE808: stw     r9, 1004(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BE80C:
    ctx->pc = 0x800BE80Cu;
    ctx->downcount -= 10;
    // 800BE80C: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BE810:
    ctx->pc = 0x800BE810u;
    // 800BE810: lis     r11, 32
    ctx->gpr[11] = ((u32)(s32)(32) << 16);

label_800BE814:
    ctx->pc = 0x800BE814u;
    // 800BE814: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BE818:
    ctx->pc = 0x800BE818u;
    // 800BE818: ori     r11, r11, 0x0002
    ctx->gpr[11] = ctx->gpr[11] | 0x0002u;

label_800BE81C:
    ctx->pc = 0x800BE81Cu;
    // 800BE81C: lwz     r10, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE820:
    ctx->pc = 0x800BE820u;
    // 800BE820: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE824:
    ctx->pc = 0x800BE824u;
    // 800BE824: xor   r0, r0, r10
    {
        ctx->gpr[0] = ctx->gpr[0] ^ ctx->gpr[10];
    }

label_800BE828:
    ctx->pc = 0x800BE828u;
    // 800BE828: and   r0, r0, r11
    {
        ctx->gpr[0] = ctx->gpr[0] & ctx->gpr[11];
    }

label_800BE82C:
    ctx->pc = 0x800BE82Cu;
    // 800BE82C: and.   r9, r0, r10
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

label_800BE830:
    ctx->pc = 0x800BE830u;
    // 800BE830: bc    12, 2, 0x800BE8A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE8A4;
        }
    }

label_800BE834:
    ctx->pc = 0x800BE834u;
    ctx->downcount -= 5;
    // 800BE834: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE838:
    ctx->pc = 0x800BE838u;
    // 800BE838: addi    r31, r9, -21636
    ctx->gpr[31] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE83C:
    ctx->pc = 0x800BE83Cu;
    // 800BE83C: lwz     r9, 1004(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1004);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BE840:
    ctx->pc = 0x800BE840u;
    // 800BE840: cmpwi   r9, 7
    {
        s32 val_a = (s32)(ctx->gpr[9]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE844:
    ctx->pc = 0x800BE844u;
    // 800BE844: bc    12, 1, 0x800BE850
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE850;
        }
    }

label_800BE848:
    ctx->pc = 0x800BE848u;
    ctx->downcount -= 2;
    // 800BE848: addi    r0, r9, 8
    ctx->gpr[0] = ctx->gpr[9] + (u32)(s32)(8);

label_800BE84C:
    ctx->pc = 0x800BE84Cu;
    // 800BE84C: stw     r0, 1004(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE850:
    ctx->pc = 0x800BE850u;
    ctx->downcount -= 6;
    // 800BE850: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BE854:
    ctx->pc = 0x800BE854u;
    // 800BE854: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BE858:
    ctx->pc = 0x800BE858u;
    // 800BE858: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BE858u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE85C:
    ctx->pc = 0x800BE85Cu;
    // 800BE85C: ori     r3, r3, 0x006A
    ctx->gpr[3] = ctx->gpr[3] | 0x006Au;

label_800BE860:
    ctx->pc = 0x800BE860u;
    // 800BE860: li      r28, 1
    ctx->gpr[28] = (u32)(s32)(1);

label_800BE864:
    ctx->pc = 0x800BE864u;
    // 800BE864: bl      0x8004DC00
    {
            ctx->lr = 0x800BE868u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BE868:
    ctx->pc = 0x800BE868u;
    ctx->downcount -= 3;
    // 800BE868: lwz     r29, 1004(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1004);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_800BE86C:
    ctx->pc = 0x800BE86Cu;
    // 800BE86C: cmpwi   r29, 7
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE870:
    ctx->pc = 0x800BE870u;
    // 800BE870: bc    4, 1, 0x800BE888
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE888;
        }
    }

label_800BE874:
    ctx->pc = 0x800BE874u;
    ctx->downcount -= 3;
    // 800BE874: addi    r0, r29, -8
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(-8);

label_800BE878:
    ctx->pc = 0x800BE878u;
    // 800BE878: cmpwi   r0, 1
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

label_800BE87C:
    ctx->pc = 0x800BE87Cu;
    // 800BE87C: bc    4, 1, 0x800BE888
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE888;
        }
    }

label_800BE880:
    ctx->pc = 0x800BE880u;
    ctx->downcount -= 2;
    // 800BE880: addi    r0, r29, 1
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(1);

label_800BE884:
    ctx->pc = 0x800BE884u;
    // 800BE884: stw     r0, 1004(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE888:
    ctx->pc = 0x800BE888u;
    ctx->downcount -= 5;
    // 800BE888: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE88C:
    ctx->pc = 0x800BE88Cu;
    // 800BE88C: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE890:
    ctx->pc = 0x800BE890u;
    // 800BE890: lwz     r0, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE894:
    ctx->pc = 0x800BE894u;
    // 800BE894: cmpwi   r0, 16
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

label_800BE898:
    ctx->pc = 0x800BE898u;
    // 800BE898: bc    4, 1, 0x800BE8A4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE8A4;
        }
    }

label_800BE89C:
    ctx->pc = 0x800BE89Cu;
    ctx->downcount -= 2;
    // 800BE89C: li      r0, 16
    ctx->gpr[0] = (u32)(s32)(16);

label_800BE8A0:
    ctx->pc = 0x800BE8A0u;
    // 800BE8A0: stw     r0, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE8A4:
    ctx->pc = 0x800BE8A4u;
    ctx->downcount -= 6;
    // 800BE8A4: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE8A8:
    ctx->pc = 0x800BE8A8u;
    // 800BE8A8: addi    r30, r9, -21636
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE8AC:
    ctx->pc = 0x800BE8ACu;
    // 800BE8AC: lwz     r29, 1004(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1004);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_800BE8B0:
    ctx->pc = 0x800BE8B0u;
    // 800BE8B0: lwz     r26, 1008(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1008);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_800BE8B4:
    ctx->pc = 0x800BE8B4u;
    // 800BE8B4: cmpwi   r29, 7
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE8B8:
    ctx->pc = 0x800BE8B8u;
    // 800BE8B8: bc    4, 1, 0x800BE918
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE918;
        }
    }

label_800BE8BC:
    ctx->pc = 0x800BE8BCu;
    ctx->downcount -= 3;
    // 800BE8BC: addi    r3, r29, -8
    ctx->gpr[3] = ctx->gpr[29] + (u32)(s32)(-8);

label_800BE8C0:
    ctx->pc = 0x800BE8C0u;
    // 800BE8C0: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BE8C4:
    ctx->pc = 0x800BE8C4u;
    // 800BE8C4: bl      0x800BF484
    {
            ctx->lr = 0x800BE8C8u;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BE8C8:
    ctx->pc = 0x800BE8C8u;
    ctx->downcount -= 2;
    // 800BE8C8: cmpwi   r3, 0
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

label_800BE8CC:
    ctx->pc = 0x800BE8CCu;
    // 800BE8CC: bc    4, 2, 0x800BE8E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE8E8;
        }
    }

label_800BE8D0:
    ctx->pc = 0x800BE8D0u;
    ctx->downcount -= 2;
    // 800BE8D0: cmpwi   r31, 2
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(2);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE8D4:
    ctx->pc = 0x800BE8D4u;
    // 800BE8D4: bc    4, 2, 0x800BE8E8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE8E8;
        }
    }

label_800BE8D8:
    ctx->pc = 0x800BE8D8u;
    ctx->downcount -= 4;
    // 800BE8D8: lwz     r0, 1004(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1004);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE8DC:
    ctx->pc = 0x800BE8DCu;
    // 800BE8DC: add   r0, r0, r28
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800BE8E0:
    ctx->pc = 0x800BE8E0u;
    // 800BE8E0: stw     r0, 1004(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE8E4:
    ctx->pc = 0x800BE8E4u;
    // 800BE8E4: b       0x800BE914
    {
            goto label_800BE914;
    }

label_800BE8E8:
    ctx->pc = 0x800BE8E8u;
    ctx->downcount -= 2;
    // 800BE8E8: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE8EC:
    ctx->pc = 0x800BE8ECu;
    // 800BE8EC: bl      0x800BF484
    {
            ctx->lr = 0x800BE8F0u;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BE8F0:
    ctx->pc = 0x800BE8F0u;
    ctx->downcount -= 2;
    // 800BE8F0: cmpwi   r3, 0
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

label_800BE8F4:
    ctx->pc = 0x800BE8F4u;
    // 800BE8F4: bc    4, 2, 0x800BE918
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE918;
        }
    }

label_800BE8F8:
    ctx->pc = 0x800BE8F8u;
    ctx->downcount -= 2;
    // 800BE8F8: cmpwi   r31, 1
    {
        s32 val_a = (s32)(ctx->gpr[31]);
        s32 val_b = (s32)(1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE8FC:
    ctx->pc = 0x800BE8FCu;
    // 800BE8FC: bc    4, 2, 0x800BE918
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BE918;
        }
    }

label_800BE900:
    ctx->pc = 0x800BE900u;
    ctx->downcount -= 5;
    // 800BE900: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BE904:
    ctx->pc = 0x800BE904u;
    // 800BE904: addi    r9, r9, -21636
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21636);

label_800BE908:
    ctx->pc = 0x800BE908u;
    // 800BE908: lwz     r0, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE90C:
    ctx->pc = 0x800BE90Cu;
    // 800BE90C: add   r0, r0, r28
    {
        u32 a = ctx->gpr[0];
        u32 b = ctx->gpr[28];
        u32 res = a + b;
        ctx->gpr[0] = res;
    }

label_800BE910:
    ctx->pc = 0x800BE910u;
    // 800BE910: stw     r0, 1004(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(1004);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BE914:
    ctx->pc = 0x800BE914u;
    ctx->downcount -= 1;
    // 800BE914: or   r29, r0, r0
    {
        ctx->gpr[29] = ctx->gpr[0] | ctx->gpr[0];
    }

label_800BE918:
    ctx->pc = 0x800BE918u;
    ctx->downcount -= 8;
    // 800BE918: lis     r9, -32700
    ctx->gpr[9] = ((u32)(s32)(-32700) << 16);

label_800BE91C:
    ctx->pc = 0x800BE91Cu;
    // 800BE91C: addi    r9, r9, -21024
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-21024);

label_800BE920:
    ctx->pc = 0x800BE920u;
    // 800BE920: lwz     r10, 28(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(28);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE924:
    ctx->pc = 0x800BE924u;
    // 800BE924: lwz     r0, 32(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE928:
    ctx->pc = 0x800BE928u;
    // 800BE928: xor   r11, r0, r10
    {
        ctx->gpr[11] = ctx->gpr[0] ^ ctx->gpr[10];
    }

label_800BE92C:
    ctx->pc = 0x800BE92Cu;
    // 800BE92C: rlwinm r9, r11, 0, 13, 13
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00040000u;
    }

label_800BE930:
    ctx->pc = 0x800BE930u;
    // 800BE930: and.   r0, r9, r10
    {
        ctx->gpr[0] = ctx->gpr[9] & ctx->gpr[10];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[0];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BE934:
    ctx->pc = 0x800BE934u;
    // 800BE934: bc    12, 2, 0x800BE93C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE93C;
        }
    }

label_800BE938:
    ctx->pc = 0x800BE938u;
    ctx->downcount -= 1;
    // 800BE938: li      r25, 0
    ctx->gpr[25] = (u32)(s32)(0);

label_800BE93C:
    ctx->pc = 0x800BE93Cu;
    ctx->downcount -= 3;
    // 800BE93C: rlwinm r0, r11, 0, 12, 12
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00080000u;
    }

label_800BE940:
    ctx->pc = 0x800BE940u;
    // 800BE940: and.   r9, r0, r10
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

label_800BE944:
    ctx->pc = 0x800BE944u;
    // 800BE944: bc    12, 2, 0x800BE94C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE94C;
        }
    }

label_800BE948:
    ctx->pc = 0x800BE948u;
    ctx->downcount -= 1;
    // 800BE948: li      r25, 1
    ctx->gpr[25] = (u32)(s32)(1);

label_800BE94C:
    ctx->pc = 0x800BE94Cu;
    ctx->downcount -= 3;
    // 800BE94C: rlwinm r0, r11, 0, 14, 14
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[11], 0u) & 0x00020000u;
    }

label_800BE950:
    ctx->pc = 0x800BE950u;
    // 800BE950: and.   r9, r0, r10
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

label_800BE954:
    ctx->pc = 0x800BE954u;
    // 800BE954: bc    12, 2, 0x800BE95C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE95C;
        }
    }

label_800BE958:
    ctx->pc = 0x800BE958u;
    ctx->downcount -= 1;
    // 800BE958: li      r25, 2
    ctx->gpr[25] = (u32)(s32)(2);

label_800BE95C:
    ctx->pc = 0x800BE95Cu;
    ctx->downcount -= 7;
    // 800BE95C: cmpwi   r25, -1
    {
        s32 val_a = (s32)(ctx->gpr[25]);
        s32 val_b = (s32)(-1);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BE960:
    ctx->pc = 0x800BE960u;
    // 800BE960: mulli   r27, r29, 52
    ctx->gpr[27] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)52);

label_800BE964:
    ctx->pc = 0x800BE964u;
    // 800BE964: cmpwi   cr4, r29, 7
    {
        s32 val_a = (s32)(ctx->gpr[29]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 12)) | (cr_bits << 12);
    }

label_800BE968:
    ctx->pc = 0x800BE968u;
    // 800BE968: lis     r30, -32734
    ctx->gpr[30] = ((u32)(s32)(-32734) << 16);

label_800BE96C:
    ctx->pc = 0x800BE96Cu;
    // 800BE96C: bc    12, 2, 0x800BEA4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEA4C;
        }
    }

label_800BE970:
    ctx->pc = 0x800BE970u;
    ctx->downcount -= 1;
    // 800BE970: bc    12, 17, 0x800BE9BC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00004000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BE9BC;
        }
    }

label_800BE974:
    ctx->pc = 0x800BE974u;
    ctx->downcount -= 8;
    // 800BE974: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BE978:
    ctx->pc = 0x800BE978u;
    // 800BE978: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_800BE97C:
    ctx->pc = 0x800BE97Cu;
    // 800BE97C: addi    r8, r9, -2880
    ctx->gpr[8] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BE980:
    ctx->pc = 0x800BE980u;
    // 800BE980: lwz     r10, -20700(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-20700);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BE984:
    ctx->pc = 0x800BE984u;
    // 800BE984: addi    r9, r8, 4
    ctx->gpr[9] = ctx->gpr[8] + (u32)(s32)(4);

label_800BE988:
    ctx->pc = 0x800BE988u;
    // 800BE988: lwzx    r0, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE98C:
    ctx->pc = 0x800BE98Cu;
    // 800BE98C: and.   r9, r10, r0
    {
        ctx->gpr[9] = ctx->gpr[10] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BE990:
    ctx->pc = 0x800BE990u;
    // 800BE990: bc    12, 2, 0x800BEA4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEA4C;
        }
    }

label_800BE994:
    ctx->pc = 0x800BE994u;
    ctx->downcount -= 3;
    // 800BE994: lwzx    r4, r8, r27
    {
        u32 ea = ctx->gpr[8] + ctx->gpr[27];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BE998:
    ctx->pc = 0x800BE998u;
    // 800BE998: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BE99C:
    ctx->pc = 0x800BE99Cu;
    // 800BE99C: bl      0x800BF2C0
    {
            ctx->lr = 0x800BE9A0u;
            ctx->pc = 0x800BF2C0u;
            return;
    }

label_800BE9A0:
    ctx->pc = 0x800BE9A0u;
    ctx->downcount -= 7;
    // 800BE9A0: lwz     r0, -27480(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27480);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BE9A4:
    ctx->pc = 0x800BE9A4u;
    // 800BE9A4: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BE9A8:
    ctx->pc = 0x800BE9A8u;
    // 800BE9A8: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BE9AC:
    ctx->pc = 0x800BE9ACu;
    // 800BE9AC: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BE9ACu)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BE9B0:
    ctx->pc = 0x800BE9B0u;
    // 800BE9B0: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_800BE9B4:
    ctx->pc = 0x800BE9B4u;
    // 800BE9B4: ori     r3, r3, 0x03C4
    ctx->gpr[3] = ctx->gpr[3] | 0x03C4u;

label_800BE9B8:
    ctx->pc = 0x800BE9B8u;
    // 800BE9B8: b       0x800BEA14
    {
            goto label_800BEA14;
    }

label_800BE9BC:
    ctx->pc = 0x800BE9BCu;
    ctx->downcount -= 3;
    // 800BE9BC: addi    r31, r29, -8
    ctx->gpr[31] = ctx->gpr[29] + (u32)(s32)(-8);

label_800BE9C0:
    ctx->pc = 0x800BE9C0u;
    // 800BE9C0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE9C4:
    ctx->pc = 0x800BE9C4u;
    // 800BE9C4: bl      0x800BF484
    {
            ctx->lr = 0x800BE9C8u;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BE9C8:
    ctx->pc = 0x800BE9C8u;
    ctx->downcount -= 2;
    // 800BE9C8: cmpwi   r3, 0
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

label_800BE9CC:
    ctx->pc = 0x800BE9CCu;
    // 800BE9CC: bc    12, 2, 0x800BEA4C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEA4C;
        }
    }

label_800BE9D0:
    ctx->pc = 0x800BE9D0u;
    ctx->downcount -= 2;
    // 800BE9D0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BE9D4:
    ctx->pc = 0x800BE9D4u;
    // 800BE9D4: bl      0x800BF320
    {
            ctx->lr = 0x800BE9D8u;
            ctx->pc = 0x800BF320u;
            return;
    }

label_800BE9D8:
    ctx->pc = 0x800BE9D8u;
    ctx->downcount -= 2;
    // 800BE9D8: cmpwi   r3, 0
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

label_800BE9DC:
    ctx->pc = 0x800BE9DCu;
    // 800BE9DC: bc    12, 2, 0x800BEA38
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEA38;
        }
    }

label_800BE9E0:
    ctx->pc = 0x800BE9E0u;
    ctx->downcount -= 7;
    // 800BE9E0: mulli   r0, r31, 52
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[31] * (s64)(s32)52);

label_800BE9E4:
    ctx->pc = 0x800BE9E4u;
    // 800BE9E4: addi    r9, r30, -2412
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(-2412);

label_800BE9E8:
    ctx->pc = 0x800BE9E8u;
    // 800BE9E8: lwzx    r4, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_800BE9EC:
    ctx->pc = 0x800BE9ECu;
    // 800BE9EC: cmpwi   r4, 0
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

label_800BE9F0:
    ctx->pc = 0x800BE9F0u;
    // 800BE9F0: bc    12, 2, 0x800BEA20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEA20;
        }
    }

label_800BE9F4:
    ctx->pc = 0x800BE9F4u;
    ctx->downcount -= 2;
    // 800BE9F4: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BE9F8:
    ctx->pc = 0x800BE9F8u;
    // 800BE9F8: bl      0x800BF2C0
    {
            ctx->lr = 0x800BE9FCu;
            ctx->pc = 0x800BF2C0u;
            return;
    }

label_800BE9FC:
    ctx->pc = 0x800BE9FCu;
    ctx->downcount -= 6;
    // 800BE9FC: lwz     r0, -27480(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27480);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEA00:
    ctx->pc = 0x800BEA00u;
    // 800BEA00: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEA04:
    ctx->pc = 0x800BEA04u;
    // 800BEA04: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BEA08:
    ctx->pc = 0x800BEA08u;
    // 800BEA08: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BEA08u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEA0C:
    ctx->pc = 0x800BEA0Cu;
    // 800BEA0C: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_800BEA10:
    ctx->pc = 0x800BEA10u;
    // 800BEA10: ori     r3, r3, 0x006B
    ctx->gpr[3] = ctx->gpr[3] | 0x006Bu;

label_800BEA14:
    ctx->pc = 0x800BEA14u;
    ctx->downcount -= 2;
    // 800BEA14: stw     r0, -27480(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27480);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEA18:
    ctx->pc = 0x800BEA18u;
    // 800BEA18: bl      0x8004DC00
    {
            ctx->lr = 0x800BEA1Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BEA1C:
    ctx->pc = 0x800BEA1Cu;
    ctx->downcount -= 1;
    // 800BEA1C: b       0x800BEA4C
    {
            goto label_800BEA4C;
    }

label_800BEA20:
    ctx->pc = 0x800BEA20u;
    ctx->downcount -= 5;
    // 800BEA20: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEA24:
    ctx->pc = 0x800BEA24u;
    // 800BEA24: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BEA28:
    ctx->pc = 0x800BEA28u;
    // 800BEA28: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BEA28u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEA2C:
    ctx->pc = 0x800BEA2Cu;
    // 800BEA2C: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_800BEA30:
    ctx->pc = 0x800BEA30u;
    // 800BEA30: bl      0x8004DC00
    {
            ctx->lr = 0x800BEA34u;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BEA34:
    ctx->pc = 0x800BEA34u;
    ctx->downcount -= 1;
    // 800BEA34: b       0x800BEA4C
    {
            goto label_800BEA4C;
    }

label_800BEA38:
    ctx->pc = 0x800BEA38u;
    ctx->downcount -= 5;
    // 800BEA38: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEA3C:
    ctx->pc = 0x800BEA3Cu;
    // 800BEA3C: lis     r3, 768
    ctx->gpr[3] = ((u32)(s32)(768) << 16);

label_800BEA40:
    ctx->pc = 0x800BEA40u;
    // 800BEA40: lfs     f1, -15820(r9)
    if (!ppc_fp_available(ctx, 0x800BEA40u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEA44:
    ctx->pc = 0x800BEA44u;
    // 800BEA44: ori     r3, r3, 0x03C5
    ctx->gpr[3] = ctx->gpr[3] | 0x03C5u;

label_800BEA48:
    ctx->pc = 0x800BEA48u;
    // 800BEA48: bl      0x8004DC00
    {
            ctx->lr = 0x800BEA4Cu;
            ctx->pc = 0x8004DC00u;
            return;
    }

label_800BEA4C:
    ctx->pc = 0x800BEA4Cu;
    ctx->downcount -= 2;
    // 800BEA4C: li      r3, 3
    ctx->gpr[3] = (u32)(s32)(3);

label_800BEA50:
    ctx->pc = 0x800BEA50u;
    // 800BEA50: bl      0x800B7A88
    {
            ctx->lr = 0x800BEA54u;
            ctx->pc = 0x800B7A88u;
            return;
    }

label_800BEA54:
    ctx->pc = 0x800BEA54u;
    ctx->downcount -= 1;
    // 800BEA54: bc    12, 17, 0x800BEAA4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00004000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEAA4;
        }
    }

label_800BEA58:
    ctx->pc = 0x800BEA58u;
    ctx->downcount -= 18;
    // 800BEA58: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BEA5C:
    ctx->pc = 0x800BEA5Cu;
    // 800BEA5C: addi    r7, r1, 48
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(48);

label_800BEA60:
    ctx->pc = 0x800BEA60u;
    // 800BEA60: addi    r9, r9, -2844
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2844);

label_800BEA64:
    ctx->pc = 0x800BEA64u;
    // 800BEA64: lis     r8, -32737
    ctx->gpr[8] = ((u32)(s32)(-32737) << 16);

label_800BEA68:
    ctx->pc = 0x800BEA68u;
    // 800BEA68: lwzx    r11, r27, r9
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[9];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEA6C:
    ctx->pc = 0x800BEA6Cu;
    // 800BEA6C: add   r9, r27, r9
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BEA70:
    ctx->pc = 0x800BEA70u;
    // 800BEA70: lfs     f13, -15816(r8)
    if (!ppc_fp_available(ctx, 0x800BEA70u)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-15816);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BEA74:
    ctx->pc = 0x800BEA74u;
    // 800BEA74: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEA78:
    ctx->pc = 0x800BEA78u;
    // 800BEA78: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEA7C:
    ctx->pc = 0x800BEA7Cu;
    // 800BEA7C: stw     r11, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BEA80:
    ctx->pc = 0x800BEA80u;
    // 800BEA80: stw     r0, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEA84:
    ctx->pc = 0x800BEA84u;
    // 800BEA84: stw     r10, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BEA88:
    ctx->pc = 0x800BEA88u;
    // 800BEA88: lwz     r10, 24(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(24);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEA8C:
    ctx->pc = 0x800BEA8Cu;
    // 800BEA8C: lfs     f0, 52(r1)
    if (!ppc_fp_available(ctx, 0x800BEA8Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BEA90:
    ctx->pc = 0x800BEA90u;
    // 800BEA90: cmpwi   r10, 0
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

label_800BEA94:
    ctx->pc = 0x800BEA94u;
    // 800BEA94: fadds   f12, f0, f13
    if (!ppc_fp_available(ctx, 0x800BEA94u)) return;
    ppc_fadds(ctx, 12, 0, 13);

label_800BEA98:
    ctx->pc = 0x800BEA98u;
    // 800BEA98: stfs     f12, 52(r1)
    if (!ppc_fp_available(ctx, 0x800BEA98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800BEA9C:
    ctx->pc = 0x800BEA9Cu;
    // 800BEA9C: bc    12, 2, 0x800BEAEC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEAEC;
        }
    }

label_800BEAA0:
    ctx->pc = 0x800BEAA0u;
    ctx->downcount -= 1;
    // 800BEAA0: b       0x800BEB2C
    {
            goto label_800BEB2C;
    }

label_800BEAA4:
    ctx->pc = 0x800BEAA4u;
    ctx->downcount -= 18;
    // 800BEAA4: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BEAA8:
    ctx->pc = 0x800BEAA8u;
    // 800BEAA8: addi    r7, r1, 48
    ctx->gpr[7] = ctx->gpr[1] + (u32)(s32)(48);

label_800BEAAC:
    ctx->pc = 0x800BEAACu;
    // 800BEAAC: addi    r9, r9, -2792
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2792);

label_800BEAB0:
    ctx->pc = 0x800BEAB0u;
    // 800BEAB0: lis     r8, -32737
    ctx->gpr[8] = ((u32)(s32)(-32737) << 16);

label_800BEAB4:
    ctx->pc = 0x800BEAB4u;
    // 800BEAB4: lwzx    r11, r27, r9
    {
        u32 ea = ctx->gpr[27] + ctx->gpr[9];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEAB8:
    ctx->pc = 0x800BEAB8u;
    // 800BEAB8: add   r9, r27, r9
    {
        u32 a = ctx->gpr[27];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[9] = res;
    }

label_800BEABC:
    ctx->pc = 0x800BEABCu;
    // 800BEABC: lfs     f13, -15816(r8)
    if (!ppc_fp_available(ctx, 0x800BEABCu)) return;
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(-15816);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BEAC0:
    ctx->pc = 0x800BEAC0u;
    // 800BEAC0: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEAC4:
    ctx->pc = 0x800BEAC4u;
    // 800BEAC4: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEAC8:
    ctx->pc = 0x800BEAC8u;
    // 800BEAC8: stw     r11, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BEACC:
    ctx->pc = 0x800BEACCu;
    // 800BEACC: stw     r0, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEAD0:
    ctx->pc = 0x800BEAD0u;
    // 800BEAD0: stw     r10, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BEAD4:
    ctx->pc = 0x800BEAD4u;
    // 800BEAD4: lwz     r10, 24(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(24);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEAD8:
    ctx->pc = 0x800BEAD8u;
    // 800BEAD8: lfs     f0, 52(r1)
    if (!ppc_fp_available(ctx, 0x800BEAD8u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BEADC:
    ctx->pc = 0x800BEADCu;
    // 800BEADC: cmpwi   r10, 0
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

label_800BEAE0:
    ctx->pc = 0x800BEAE0u;
    // 800BEAE0: fadds   f12, f0, f13
    if (!ppc_fp_available(ctx, 0x800BEAE0u)) return;
    ppc_fadds(ctx, 12, 0, 13);

label_800BEAE4:
    ctx->pc = 0x800BEAE4u;
    // 800BEAE4: stfs     f12, 52(r1)
    if (!ppc_fp_available(ctx, 0x800BEAE4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800BEAE8:
    ctx->pc = 0x800BEAE8u;
    // 800BEAE8: bc    4, 2, 0x800BEB2C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BEB2C;
        }
    }

label_800BEAEC:
    ctx->pc = 0x800BEAECu;
    ctx->downcount -= 15;
    // 800BEAEC: lwz     r0, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEAF0:
    ctx->pc = 0x800BEAF0u;
    // 800BEAF0: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BEAF4:
    ctx->pc = 0x800BEAF4u;
    // 800BEAF4: lwz     r8, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BEAF8:
    ctx->pc = 0x800BEAF8u;
    // 800BEAF8: addi    r9, r1, 64
    ctx->gpr[9] = ctx->gpr[1] + (u32)(s32)(64);

label_800BEAFC:
    ctx->pc = 0x800BEAFCu;
    // 800BEAFC: lwz     r11, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEB00:
    ctx->pc = 0x800BEB00u;
    // 800BEB00: lis     r5, -20480
    ctx->gpr[5] = ((u32)(s32)(-20480) << 16);

label_800BEB04:
    ctx->pc = 0x800BEB04u;
    // 800BEB04: stw     r0, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEB08:
    ctx->pc = 0x800BEB08u;
    // 800BEB08: or   r4, r9, r9
    {
        ctx->gpr[4] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BEB0C:
    ctx->pc = 0x800BEB0Cu;
    // 800BEB0C: lfs     f1, -15820(r10)
    if (!ppc_fp_available(ctx, 0x800BEB0Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-15820);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEB10:
    ctx->pc = 0x800BEB10u;
    // 800BEB10: addi    r6, r24, 24
    ctx->gpr[6] = ctx->gpr[24] + (u32)(s32)(24);

label_800BEB14:
    ctx->pc = 0x800BEB14u;
    // 800BEB14: stw     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BEB18:
    ctx->pc = 0x800BEB18u;
    // 800BEB18: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BEB1C:
    ctx->pc = 0x800BEB1Cu;
    // 800BEB1C: stw     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BEB20:
    ctx->pc = 0x800BEB20u;
    // 800BEB20: ori     r5, r5, 0x019A
    ctx->gpr[5] = ctx->gpr[5] | 0x019Au;

label_800BEB24:
    ctx->pc = 0x800BEB24u;
    // 800BEB24: bl      0x800C457C
    {
            ctx->lr = 0x800BEB28u;
            ctx->pc = 0x800C457Cu;
            return;
    }

label_800BEB28:
    ctx->pc = 0x800BEB28u;
    ctx->downcount -= 1;
    // 800BEB28: b       0x800BEB54
    {
            goto label_800BEB54;
    }

label_800BEB2C:
    ctx->pc = 0x800BEB2Cu;
    ctx->downcount -= 10;
    // 800BEB2C: lfs     f0, 48(r1)
    if (!ppc_fp_available(ctx, 0x800BEB2Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BEB30:
    ctx->pc = 0x800BEB30u;
    // 800BEB30: addi    r9, r10, 4
    ctx->gpr[9] = ctx->gpr[10] + (u32)(s32)(4);

label_800BEB34:
    ctx->pc = 0x800BEB34u;
    // 800BEB34: lfs     f13, 56(r1)
    if (!ppc_fp_available(ctx, 0x800BEB34u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BEB38:
    ctx->pc = 0x800BEB38u;
    // 800BEB38: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800BEB3C:
    ctx->pc = 0x800BEB3Cu;
    // 800BEB3C: stfs     f0, 4(r10)
    if (!ppc_fp_available(ctx, 0x800BEB3Cu)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BEB40:
    ctx->pc = 0x800BEB40u;
    // 800BEB40: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BEB44:
    ctx->pc = 0x800BEB44u;
    // 800BEB44: stfs     f13, 8(r9)
    if (!ppc_fp_available(ctx, 0x800BEB44u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BEB48:
    ctx->pc = 0x800BEB48u;
    // 800BEB48: stfs     f12, 4(r9)
    if (!ppc_fp_available(ctx, 0x800BEB48u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[12]));
    }

label_800BEB4C:
    ctx->pc = 0x800BEB4Cu;
    // 800BEB4C: stw     r0, 236(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(236);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEB50:
    ctx->pc = 0x800BEB50u;
    // 800BEB50: sth     r11, 48(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(48);
        mem_write16(ctx, ea, (u16)ctx->gpr[11]);
    }

label_800BEB54:
    ctx->pc = 0x800BEB54u;
    ctx->downcount -= 2;
    // 800BEB54: cmpw    r26, r29
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(ctx->gpr[29]);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BEB58:
    ctx->pc = 0x800BEB58u;
    // 800BEB58: bc    12, 2, 0x800BEC70
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEC70;
        }
    }

label_800BEB5C:
    ctx->pc = 0x800BEB5Cu;
    ctx->downcount -= 2;
    // 800BEB5C: cmpwi   r26, 7
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BEB60:
    ctx->pc = 0x800BEB60u;
    // 800BEB60: bc    4, 1, 0x800BEB80
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BEB80;
        }
    }

label_800BEB64:
    ctx->pc = 0x800BEB64u;
    ctx->downcount -= 9;
    // 800BEB64: addi    r0, r26, -8
    ctx->gpr[0] = ctx->gpr[26] + (u32)(s32)(-8);

label_800BEB68:
    ctx->pc = 0x800BEB68u;
    // 800BEB68: lis     r11, -32734
    ctx->gpr[11] = ((u32)(s32)(-32734) << 16);

label_800BEB6C:
    ctx->pc = 0x800BEB6Cu;
    // 800BEB6C: mulli   r28, r0, 52
    ctx->gpr[28] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)52);

label_800BEB70:
    ctx->pc = 0x800BEB70u;
    // 800BEB70: addi    r26, r11, -2412
    ctx->gpr[26] = ctx->gpr[11] + (u32)(s32)(-2412);

label_800BEB74:
    ctx->pc = 0x800BEB74u;
    // 800BEB74: addi    r9, r26, 28
    ctx->gpr[9] = ctx->gpr[26] + (u32)(s32)(28);

label_800BEB78:
    ctx->pc = 0x800BEB78u;
    // 800BEB78: lwzx    r31, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800BEB7C:
    ctx->pc = 0x800BEB7Cu;
    // 800BEB7C: b       0x800BEB94
    {
            goto label_800BEB94;
    }

label_800BEB80:
    ctx->pc = 0x800BEB80u;
    ctx->downcount -= 7;
    // 800BEB80: mulli   r28, r26, 52
    ctx->gpr[28] = (u32)((s64)(s32)ctx->gpr[26] * (s64)(s32)52);

label_800BEB84:
    ctx->pc = 0x800BEB84u;
    // 800BEB84: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BEB88:
    ctx->pc = 0x800BEB88u;
    // 800BEB88: addi    r26, r9, -2880
    ctx->gpr[26] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BEB8C:
    ctx->pc = 0x800BEB8Cu;
    // 800BEB8C: addi    r11, r26, 28
    ctx->gpr[11] = ctx->gpr[26] + (u32)(s32)(28);

label_800BEB90:
    ctx->pc = 0x800BEB90u;
    // 800BEB90: lwzx    r31, r11, r28
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[28];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800BEB94:
    ctx->pc = 0x800BEB94u;
    ctx->downcount -= 2;
    // 800BEB94: cmpwi   r31, 0
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

label_800BEB98:
    ctx->pc = 0x800BEB98u;
    // 800BEB98: bc    12, 2, 0x800BEBC8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEBC8;
        }
    }

label_800BEB9C:
    ctx->pc = 0x800BEB9Cu;
    ctx->downcount -= 5;
    // 800BEB9C: lis     r30, -32737
    ctx->gpr[30] = ((u32)(s32)(-32737) << 16);

label_800BEBA0:
    ctx->pc = 0x800BEBA0u;
    // 800BEBA0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BEBA4:
    ctx->pc = 0x800BEBA4u;
    // 800BEBA4: lfs     f1, -15812(r30)
    if (!ppc_fp_available(ctx, 0x800BEBA4u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-15812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEBA8:
    ctx->pc = 0x800BEBA8u;
    // 800BEBA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BEBAC:
    ctx->pc = 0x800BEBACu;
    // 800BEBAC: bl      0x800C4664
    {
            ctx->lr = 0x800BEBB0u;
            ctx->pc = 0x800C4664u;
            return;
    }

label_800BEBB0:
    ctx->pc = 0x800BEBB0u;
    ctx->downcount -= 3;
    // 800BEBB0: lfs     f1, -15812(r30)
    if (!ppc_fp_available(ctx, 0x800BEBB0u)) return;
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(-15812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEBB4:
    ctx->pc = 0x800BEBB4u;
    // 800BEBB4: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BEBB8:
    ctx->pc = 0x800BEBB8u;
    // 800BEBB8: bl      0x800C45F4
    {
            ctx->lr = 0x800BEBBCu;
            ctx->pc = 0x800C45F4u;
            return;
    }

label_800BEBBC:
    ctx->pc = 0x800BEBBCu;
    ctx->downcount -= 3;
    // 800BEBBC: addi    r9, r26, 48
    ctx->gpr[9] = ctx->gpr[26] + (u32)(s32)(48);

label_800BEBC0:
    ctx->pc = 0x800BEBC0u;
    // 800BEBC0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800BEBC4:
    ctx->pc = 0x800BEBC4u;
    // 800BEBC4: stwx    r0, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEBC8:
    ctx->pc = 0x800BEBC8u;
    ctx->downcount -= 1;
    // 800BEBC8: bc    4, 17, 0x800BEC20
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00004000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800BEC20;
        }
    }

label_800BEBCC:
    ctx->pc = 0x800BEBCCu;
    ctx->downcount -= 10;
    // 800BEBCC: addi    r0, r29, -8
    ctx->gpr[0] = ctx->gpr[29] + (u32)(s32)(-8);

label_800BEBD0:
    ctx->pc = 0x800BEBD0u;
    // 800BEBD0: lis     r11, -32734
    ctx->gpr[11] = ((u32)(s32)(-32734) << 16);

label_800BEBD4:
    ctx->pc = 0x800BEBD4u;
    // 800BEBD4: mulli   r30, r0, 52
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)52);

label_800BEBD8:
    ctx->pc = 0x800BEBD8u;
    // 800BEBD8: addi    r28, r11, -2412
    ctx->gpr[28] = ctx->gpr[11] + (u32)(s32)(-2412);

label_800BEBDC:
    ctx->pc = 0x800BEBDCu;
    // 800BEBDC: addi    r9, r28, 28
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(28);

label_800BEBE0:
    ctx->pc = 0x800BEBE0u;
    // 800BEBE0: lwzx    r31, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800BEBE4:
    ctx->pc = 0x800BEBE4u;
    // 800BEBE4: cmpwi   r31, 0
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

label_800BEBE8:
    ctx->pc = 0x800BEBE8u;
    // 800BEBE8: bc    12, 2, 0x800BEC68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEC68;
        }
    }

label_800BEBEC:
    ctx->pc = 0x800BEBECu;
    ctx->downcount -= 5;
    // 800BEBEC: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEBF0:
    ctx->pc = 0x800BEBF0u;
    // 800BEBF0: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BEBF4:
    ctx->pc = 0x800BEBF4u;
    // 800BEBF4: lfs     f1, -15812(r9)
    if (!ppc_fp_available(ctx, 0x800BEBF4u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEBF8:
    ctx->pc = 0x800BEBF8u;
    // 800BEBF8: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BEBFC:
    ctx->pc = 0x800BEBFCu;
    // 800BEBFC: bl      0x800C4664
    {
            ctx->lr = 0x800BEC00u;
            ctx->pc = 0x800C4664u;
            return;
    }

label_800BEC00:
    ctx->pc = 0x800BEC00u;
    ctx->downcount -= 4;
    // 800BEC00: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEC04:
    ctx->pc = 0x800BEC04u;
    // 800BEC04: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BEC08:
    ctx->pc = 0x800BEC08u;
    // 800BEC08: lfs     f1, -15808(r9)
    if (!ppc_fp_available(ctx, 0x800BEC08u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15808);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEC0C:
    ctx->pc = 0x800BEC0Cu;
    // 800BEC0C: bl      0x800C4628
    {
            ctx->lr = 0x800BEC10u;
            ctx->pc = 0x800C4628u;
            return;
    }

label_800BEC10:
    ctx->pc = 0x800BEC10u;
    ctx->downcount -= 4;
    // 800BEC10: addi    r9, r28, 48
    ctx->gpr[9] = ctx->gpr[28] + (u32)(s32)(48);

label_800BEC14:
    ctx->pc = 0x800BEC14u;
    // 800BEC14: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BEC18:
    ctx->pc = 0x800BEC18u;
    // 800BEC18: stwx    r0, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEC1C:
    ctx->pc = 0x800BEC1Cu;
    // 800BEC1C: b       0x800BEC68
    {
            goto label_800BEC68;
    }

label_800BEC20:
    ctx->pc = 0x800BEC20u;
    ctx->downcount -= 6;
    // 800BEC20: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BEC24:
    ctx->pc = 0x800BEC24u;
    // 800BEC24: addi    r30, r9, -2880
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BEC28:
    ctx->pc = 0x800BEC28u;
    // 800BEC28: addi    r11, r30, 28
    ctx->gpr[11] = ctx->gpr[30] + (u32)(s32)(28);

label_800BEC2C:
    ctx->pc = 0x800BEC2Cu;
    // 800BEC2C: lwzx    r31, r11, r27
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[27];
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_800BEC30:
    ctx->pc = 0x800BEC30u;
    // 800BEC30: cmpwi   r31, 0
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

label_800BEC34:
    ctx->pc = 0x800BEC34u;
    // 800BEC34: bc    12, 2, 0x800BEC68
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEC68;
        }
    }

label_800BEC38:
    ctx->pc = 0x800BEC38u;
    ctx->downcount -= 5;
    // 800BEC38: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEC3C:
    ctx->pc = 0x800BEC3Cu;
    // 800BEC3C: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BEC40:
    ctx->pc = 0x800BEC40u;
    // 800BEC40: lfs     f1, -15812(r9)
    if (!ppc_fp_available(ctx, 0x800BEC40u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEC44:
    ctx->pc = 0x800BEC44u;
    // 800BEC44: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BEC48:
    ctx->pc = 0x800BEC48u;
    // 800BEC48: bl      0x800C4664
    {
            ctx->lr = 0x800BEC4Cu;
            ctx->pc = 0x800C4664u;
            return;
    }

label_800BEC4C:
    ctx->pc = 0x800BEC4Cu;
    ctx->downcount -= 4;
    // 800BEC4C: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEC50:
    ctx->pc = 0x800BEC50u;
    // 800BEC50: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BEC54:
    ctx->pc = 0x800BEC54u;
    // 800BEC54: lfs     f1, -15808(r9)
    if (!ppc_fp_available(ctx, 0x800BEC54u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15808);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BEC58:
    ctx->pc = 0x800BEC58u;
    // 800BEC58: bl      0x800C4628
    {
            ctx->lr = 0x800BEC5Cu;
            ctx->pc = 0x800C4628u;
            return;
    }

label_800BEC5C:
    ctx->pc = 0x800BEC5Cu;
    ctx->downcount -= 3;
    // 800BEC5C: addi    r9, r30, 48
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(48);

label_800BEC60:
    ctx->pc = 0x800BEC60u;
    // 800BEC60: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_800BEC64:
    ctx->pc = 0x800BEC64u;
    // 800BEC64: stwx    r0, r9, r27
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[27];
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEC68:
    ctx->pc = 0x800BEC68u;
    ctx->downcount -= 2;
    // 800BEC68: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_800BEC6C:
    ctx->pc = 0x800BEC6Cu;
    // 800BEC6C: stw     r29, -20628(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-20628);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800BEC70:
    ctx->pc = 0x800BEC70u;
    ctx->downcount -= 5;
    // 800BEC70: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BEC74:
    ctx->pc = 0x800BEC74u;
    // 800BEC74: addi    r9, r9, -2880
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BEC78:
    ctx->pc = 0x800BEC78u;
    // 800BEC78: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEC7C:
    ctx->pc = 0x800BEC7Cu;
    // 800BEC7C: cmpwi   r0, -1
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

label_800BEC80:
    ctx->pc = 0x800BEC80u;
    // 800BEC80: bc    12, 2, 0x800BECD0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BECD0;
        }
    }

label_800BEC84:
    ctx->pc = 0x800BEC84u;
    ctx->downcount -= 3;
    // 800BEC84: or   r30, r9, r9
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BEC88:
    ctx->pc = 0x800BEC88u;
    // 800BEC88: lis     r29, -32737
    ctx->gpr[29] = ((u32)(s32)(-32737) << 16);

label_800BEC8C:
    ctx->pc = 0x800BEC8Cu;
    // 800BEC8C: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_800BEC90:
    ctx->pc = 0x800BEC90u;
    ctx->downcount -= 3;
    // 800BEC90: lwz     r0, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEC94:
    // 800BEC94: cmpwi   r0, 0
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

label_800BEC98:
    // 800BEC98: bc    12, 2, 0x800BECB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BECB4;
        }
    }

label_800BEC9C:
    ctx->pc = 0x800BEC9Cu;
    ctx->downcount -= 3;
    // 800BEC9C: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BECA0:
    ctx->pc = 0x800BECA0u;
    // 800BECA0: lfs     f1, -15812(r29)
    if (!ppc_fp_available(ctx, 0x800BECA0u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-15812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BECA4:
    // 800BECA4: bl      0x800C45F4
    {
            ctx->lr = 0x800BECA8u;
            ctx->pc = 0x800C45F4u;
            return;
    }

label_800BECA8:
    ctx->downcount -= 2;
    // 800BECA8: cmpwi   r3, 0
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

label_800BECAC:
    // 800BECAC: bc    12, 2, 0x800BECB4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BECB4;
        }
    }

label_800BECB0:
    ctx->pc = 0x800BECB0u;
    ctx->downcount -= 1;
    // 800BECB0: stw     r31, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800BECB4:
    ctx->pc = 0x800BECB4u;
    ctx->downcount -= 2;
    // 800BECB4: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BECB8:
    // 800BECB8: bl      0x800C4714
    {
            ctx->lr = 0x800BECBCu;
            ctx->pc = 0x800C4714u;
            return;
    }

label_800BECBC:
    ctx->pc = 0x800BECBCu;
    ctx->downcount -= 2;
    // 800BECBC: lwz     r3, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BECC0:
    // 800BECC0: bl      0x800C4714
    {
            ctx->lr = 0x800BECC4u;
            ctx->pc = 0x800C4714u;
            return;
    }

label_800BECC4:
    ctx->pc = 0x800BECC4u;
    ctx->downcount -= 3;
    // 800BECC4: lwzu     r0, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[30] = ea;
    }

label_800BECC8:
    // 800BECC8: cmpwi   r0, -1
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

label_800BECCC:
    // 800BECCC: bc    4, 2, 0x800BEC90
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BEC90u;
                return;
            }
            goto label_800BEC90;
        }
    }

label_800BECD0:
    ctx->pc = 0x800BECD0u;
    ctx->downcount -= 5;
    // 800BECD0: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BECD4:
    ctx->pc = 0x800BECD4u;
    // 800BECD4: addi    r9, r9, -2412
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2412);

label_800BECD8:
    ctx->pc = 0x800BECD8u;
    // 800BECD8: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BECDC:
    ctx->pc = 0x800BECDCu;
    // 800BECDC: cmpwi   r0, -1
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

label_800BECE0:
    ctx->pc = 0x800BECE0u;
    // 800BECE0: bc    12, 2, 0x800BED30
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BED30;
        }
    }

label_800BECE4:
    ctx->pc = 0x800BECE4u;
    ctx->downcount -= 3;
    // 800BECE4: or   r30, r9, r9
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BECE8:
    ctx->pc = 0x800BECE8u;
    // 800BECE8: lis     r29, -32737
    ctx->gpr[29] = ((u32)(s32)(-32737) << 16);

label_800BECEC:
    ctx->pc = 0x800BECECu;
    // 800BECEC: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_800BECF0:
    ctx->pc = 0x800BECF0u;
    ctx->downcount -= 3;
    // 800BECF0: lwz     r0, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BECF4:
    // 800BECF4: cmpwi   r0, 0
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

label_800BECF8:
    // 800BECF8: bc    12, 2, 0x800BED14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BED14;
        }
    }

label_800BECFC:
    ctx->pc = 0x800BECFCu;
    ctx->downcount -= 3;
    // 800BECFC: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BED00:
    ctx->pc = 0x800BED00u;
    // 800BED00: lfs     f1, -15812(r29)
    if (!ppc_fp_available(ctx, 0x800BED00u)) return;
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(-15812);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[1] = value;
        ctx->ps1[1] = value;
    }

label_800BED04:
    // 800BED04: bl      0x800C45F4
    {
            ctx->lr = 0x800BED08u;
            ctx->pc = 0x800C45F4u;
            return;
    }

label_800BED08:
    ctx->downcount -= 2;
    // 800BED08: cmpwi   r3, 0
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

label_800BED0C:
    // 800BED0C: bc    12, 2, 0x800BED14
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BED14;
        }
    }

label_800BED10:
    ctx->pc = 0x800BED10u;
    ctx->downcount -= 1;
    // 800BED10: stw     r31, 48(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800BED14:
    ctx->pc = 0x800BED14u;
    ctx->downcount -= 2;
    // 800BED14: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BED18:
    // 800BED18: bl      0x800C4714
    {
            ctx->lr = 0x800BED1Cu;
            ctx->pc = 0x800C4714u;
            return;
    }

label_800BED1C:
    ctx->pc = 0x800BED1Cu;
    ctx->downcount -= 2;
    // 800BED1C: lwz     r3, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BED20:
    // 800BED20: bl      0x800C4714
    {
            ctx->lr = 0x800BED24u;
            ctx->pc = 0x800C4714u;
            return;
    }

label_800BED24:
    ctx->pc = 0x800BED24u;
    ctx->downcount -= 3;
    // 800BED24: lwzu     r0, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[30] = ea;
    }

label_800BED28:
    // 800BED28: cmpwi   r0, -1
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

label_800BED2C:
    // 800BED2C: bc    4, 2, 0x800BECF0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BECF0u;
                return;
            }
            goto label_800BECF0;
        }
    }

label_800BED30:
    ctx->pc = 0x800BED30u;
    ctx->downcount -= 19;
    // 800BED30: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BED34:
    ctx->pc = 0x800BED34u;
    // 800BED34: lwz     r0, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BED38:
    ctx->pc = 0x800BED38u;
    // 800BED38: lwz     r12, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_800BED3C:
    ctx->pc = 0x800BED3Cu;
    // 800BED3C: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BED40:
    ctx->pc = 0x800BED40u;
    // 800BED40: lmw     r24, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        for (u32 r = 24; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BED44:
    ctx->pc = 0x800BED44u;
    // 800BED44: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_800BED48:
    ctx->pc = 0x800BED48u;
    // 800BED48: addi    r1, r1, 120
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(120);

label_800BED4C:
    ctx->pc = 0x800BED4Cu;
    // 800BED4C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

label_800BED50:
    ctx->pc = 0x800BED50u;
    ctx->downcount -= 20;
    // 800BED50: stwu     r1, -2280(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-2280);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_800BED54:
    ctx->pc = 0x800BED54u;
    // 800BED54: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_800BED58:
    ctx->pc = 0x800BED58u;
    // 800BED58: stfd     f31, 2272(r1)
    if (!ppc_fp_available(ctx, 0x800BED58u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2272);
        mem_write64(ctx, ea, dolrecomp_f64_to_bits(ctx->fpr[31]));
    }

label_800BED5C:
    ctx->pc = 0x800BED5Cu;
    // 800BED5C: stmw     r21, 2228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2228);
        for (u32 r = 21; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_800BED60:
    ctx->pc = 0x800BED60u;
    // 800BED60: stw     r0, 2284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2284);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BED64:
    ctx->pc = 0x800BED64u;
    // 800BED64: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BED68:
    ctx->pc = 0x800BED68u;
    // 800BED68: addi    r30, r1, 2168
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(2168);

label_800BED6C:
    ctx->pc = 0x800BED6Cu;
    // 800BED6C: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BED70:
    ctx->pc = 0x800BED70u;
    // 800BED70: or   r25, r30, r30
    {
        ctx->gpr[25] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BED74:
    ctx->pc = 0x800BED74u;
    // 800BED74: bl      0x80036150
    {
            ctx->lr = 0x800BED78u;
            ctx->pc = 0x80036150u;
            return;
    }

label_800BED78:
    ctx->pc = 0x800BED78u;
    ctx->downcount -= 28;
    // 800BED78: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BED7C:
    ctx->pc = 0x800BED7Cu;
    // 800BED7C: lis     r10, -32737
    ctx->gpr[10] = ((u32)(s32)(-32737) << 16);

label_800BED80:
    ctx->pc = 0x800BED80u;
    // 800BED80: lfs     f0, -15804(r9)
    if (!ppc_fp_available(ctx, 0x800BED80u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15804);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BED84:
    ctx->pc = 0x800BED84u;
    // 800BED84: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_800BED88:
    ctx->pc = 0x800BED88u;
    // 800BED88: lfs     f13, -15800(r10)
    if (!ppc_fp_available(ctx, 0x800BED88u)) return;
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(-15800);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BED8C:
    ctx->pc = 0x800BED8Cu;
    // 800BED8C: addi    r28, r11, -21636
    ctx->gpr[28] = ctx->gpr[11] + (u32)(s32)(-21636);

label_800BED90:
    ctx->pc = 0x800BED90u;
    // 800BED90: stfs     f0, 2168(r1)
    if (!ppc_fp_available(ctx, 0x800BED90u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2168);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BED94:
    ctx->pc = 0x800BED94u;
    // 800BED94: addi    r8, r1, 2208
    ctx->gpr[8] = ctx->gpr[1] + (u32)(s32)(2208);

label_800BED98:
    ctx->pc = 0x800BED98u;
    // 800BED98: stfs     f13, 2172(r1)
    if (!ppc_fp_available(ctx, 0x800BED98u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2172);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[13]));
    }

label_800BED9C:
    ctx->pc = 0x800BED9Cu;
    // 800BED9C: or   r4, r8, r8
    {
        ctx->gpr[4] = ctx->gpr[8] | ctx->gpr[8];
    }

label_800BEDA0:
    ctx->pc = 0x800BEDA0u;
    // 800BEDA0: lwz     r0, 2168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEDA4:
    ctx->pc = 0x800BEDA4u;
    // 800BEDA4: or   r27, r8, r8
    {
        ctx->gpr[27] = ctx->gpr[8] | ctx->gpr[8];
    }

label_800BEDA8:
    ctx->pc = 0x800BEDA8u;
    // 800BEDA8: lwz     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BEDAC:
    ctx->pc = 0x800BEDACu;
    // 800BEDAC: lis     r3, -32698
    ctx->gpr[3] = ((u32)(s32)(-32698) << 16);

label_800BEDB0:
    ctx->pc = 0x800BEDB0u;
    // 800BEDB0: lwz     r26, 1004(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(1004);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_800BEDB4:
    ctx->pc = 0x800BEDB4u;
    // 800BEDB4: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_800BEDB8:
    ctx->pc = 0x800BEDB8u;
    // 800BEDB8: lwz     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEDBC:
    ctx->pc = 0x800BEDBCu;
    // 800BEDBC: addi    r3, r3, 7984
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7984);

label_800BEDC0:
    ctx->pc = 0x800BEDC0u;
    // 800BEDC0: stw     r0, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEDC4:
    ctx->pc = 0x800BEDC4u;
    // 800BEDC4: li      r5, 3560
    ctx->gpr[5] = (u32)(s32)(3560);

label_800BEDC8:
    ctx->pc = 0x800BEDC8u;
    // 800BEDC8: stw     r9, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BEDCC:
    ctx->pc = 0x800BEDCCu;
    // 800BEDCC: ori     r6, r6, 0x0001
    ctx->gpr[6] = ctx->gpr[6] | 0x0001u;

label_800BEDD0:
    ctx->pc = 0x800BEDD0u;
    // 800BEDD0: stw     r11, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BEDD4:
    ctx->pc = 0x800BEDD4u;
    // 800BEDD4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BEDD8:
    ctx->pc = 0x800BEDD8u;
    // 800BEDD8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BEDDC:
    ctx->pc = 0x800BEDDCu;
    // 800BEDDC: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BEDE0:
    ctx->pc = 0x800BEDE0u;
    // 800BEDE0: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BEDE4:
    ctx->pc = 0x800BEDE4u;
    // 800BEDE4: bl      0x800C3D88
    {
            ctx->lr = 0x800BEDE8u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BEDE8:
    ctx->pc = 0x800BEDE8u;
    ctx->downcount -= 2;
    // 800BEDE8: cmpwi   r26, 7
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BEDEC:
    ctx->pc = 0x800BEDECu;
    // 800BEDEC: bc    12, 1, 0x800BEEE8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEEE8;
        }
    }

label_800BEDF0:
    ctx->pc = 0x800BEDF0u;
    ctx->downcount -= 11;
    // 800BEDF0: mulli   r30, r26, 52
    ctx->gpr[30] = (u32)((s64)(s32)ctx->gpr[26] * (s64)(s32)52);

label_800BEDF4:
    ctx->pc = 0x800BEDF4u;
    // 800BEDF4: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BEDF8:
    ctx->pc = 0x800BEDF8u;
    // 800BEDF8: addi    r29, r9, -2880
    ctx->gpr[29] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BEDFC:
    ctx->pc = 0x800BEDFCu;
    // 800BEDFC: lwz     r11, 936(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(936);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEE00:
    ctx->pc = 0x800BEE00u;
    // 800BEE00: addi    r9, r29, 4
    ctx->gpr[9] = ctx->gpr[29] + (u32)(s32)(4);

label_800BEE04:
    ctx->pc = 0x800BEE04u;
    // 800BEE04: addi    r28, r31, 1444
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(1444);

label_800BEE08:
    ctx->pc = 0x800BEE08u;
    // 800BEE08: lwzx    r0, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEE0C:
    ctx->pc = 0x800BEE0Cu;
    // 800BEE0C: and.   r9, r11, r0
    {
        ctx->gpr[9] = ctx->gpr[11] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BEE10:
    ctx->pc = 0x800BEE10u;
    // 800BEE10: bc    12, 2, 0x800BEFDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEFDC;
        }
    }

label_800BEE14:
    ctx->pc = 0x800BEE14u;
    ctx->downcount -= 17;
    // 800BEE14: lwz     r10, 1420(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1420);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEE18:
    ctx->pc = 0x800BEE18u;
    // 800BEE18: addi    r9, r31, 1420
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(1420);

label_800BEE1C:
    ctx->pc = 0x800BEE1Cu;
    // 800BEE1C: addi    r11, r29, 8
    ctx->gpr[11] = ctx->gpr[29] + (u32)(s32)(8);

label_800BEE20:
    ctx->pc = 0x800BEE20u;
    // 800BEE20: lwz     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BEE24:
    ctx->pc = 0x800BEE24u;
    // 800BEE24: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEE28:
    ctx->pc = 0x800BEE28u;
    // 800BEE28: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BEE2C:
    ctx->pc = 0x800BEE2Cu;
    // 800BEE2C: lwzx    r5, r11, r30
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[30];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BEE30:
    ctx->pc = 0x800BEE30u;
    // 800BEE30: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BEE34:
    ctx->pc = 0x800BEE34u;
    // 800BEE34: stw     r10, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BEE38:
    ctx->pc = 0x800BEE38u;
    // 800BEE38: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BEE3C:
    ctx->pc = 0x800BEE3Cu;
    // 800BEE3C: stw     r3, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BEE40:
    ctx->pc = 0x800BEE40u;
    // 800BEE40: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BEE44:
    ctx->pc = 0x800BEE44u;
    // 800BEE44: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BEE48:
    ctx->pc = 0x800BEE48u;
    // 800BEE48: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BEE4C:
    ctx->pc = 0x800BEE4Cu;
    // 800BEE4C: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEE50:
    ctx->pc = 0x800BEE50u;
    // 800BEE50: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BEE54:
    ctx->pc = 0x800BEE54u;
    // 800BEE54: bl      0x800C3D88
    {
            ctx->lr = 0x800BEE58u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BEE58:
    ctx->pc = 0x800BEE58u;
    ctx->downcount -= 18;
    // 800BEE58: lwz     r10, 1432(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEE5C:
    ctx->pc = 0x800BEE5Cu;
    // 800BEE5C: addi    r9, r31, 1432
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(1432);

label_800BEE60:
    ctx->pc = 0x800BEE60u;
    // 800BEE60: addi    r11, r29, 12
    ctx->gpr[11] = ctx->gpr[29] + (u32)(s32)(12);

label_800BEE64:
    ctx->pc = 0x800BEE64u;
    // 800BEE64: lwz     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BEE68:
    ctx->pc = 0x800BEE68u;
    // 800BEE68: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEE6C:
    ctx->pc = 0x800BEE6Cu;
    // 800BEE6C: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BEE70:
    ctx->pc = 0x800BEE70u;
    // 800BEE70: lwzx    r5, r11, r30
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[30];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BEE74:
    ctx->pc = 0x800BEE74u;
    // 800BEE74: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BEE78:
    ctx->pc = 0x800BEE78u;
    // 800BEE78: stw     r10, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BEE7C:
    ctx->pc = 0x800BEE7Cu;
    // 800BEE7C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BEE80:
    ctx->pc = 0x800BEE80u;
    // 800BEE80: stw     r8, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BEE84:
    ctx->pc = 0x800BEE84u;
    // 800BEE84: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BEE88:
    ctx->pc = 0x800BEE88u;
    // 800BEE88: ori     r6, r6, 0x8000
    ctx->gpr[6] = ctx->gpr[6] | 0x8000u;

label_800BEE8C:
    ctx->pc = 0x800BEE8Cu;
    // 800BEE8C: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEE90:
    ctx->pc = 0x800BEE90u;
    // 800BEE90: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BEE94:
    ctx->pc = 0x800BEE94u;
    // 800BEE94: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BEE98:
    ctx->pc = 0x800BEE98u;
    // 800BEE98: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BEE9C:
    ctx->pc = 0x800BEE9Cu;
    // 800BEE9C: bl      0x800C3D88
    {
            ctx->lr = 0x800BEEA0u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BEEA0:
    ctx->pc = 0x800BEEA0u;
    ctx->downcount -= 17;
    // 800BEEA0: lwz     r0, 1444(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1444);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEEA4:
    ctx->pc = 0x800BEEA4u;
    // 800BEEA4: addi    r9, r29, 16
    ctx->gpr[9] = ctx->gpr[29] + (u32)(s32)(16);

label_800BEEA8:
    ctx->pc = 0x800BEEA8u;
    // 800BEEA8: lwz     r10, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEEAC:
    ctx->pc = 0x800BEEACu;
    // 800BEEAC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BEEB0:
    ctx->pc = 0x800BEEB0u;
    // 800BEEB0: lwzx    r5, r9, r30
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[30];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BEEB4:
    ctx->pc = 0x800BEEB4u;
    // 800BEEB4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BEEB8:
    ctx->pc = 0x800BEEB8u;
    // 800BEEB8: lwz     r11, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEEBC:
    ctx->pc = 0x800BEEBCu;
    // 800BEEBC: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BEEC0:
    ctx->pc = 0x800BEEC0u;
    // 800BEEC0: stw     r0, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEEC4:
    ctx->pc = 0x800BEEC4u;
    // 800BEEC4: ori     r6, r6, 0x8000
    ctx->gpr[6] = ctx->gpr[6] | 0x8000u;

label_800BEEC8:
    ctx->pc = 0x800BEEC8u;
    // 800BEEC8: stw     r10, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BEECC:
    ctx->pc = 0x800BEECCu;
    // 800BEECC: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BEED0:
    ctx->pc = 0x800BEED0u;
    // 800BEED0: stw     r11, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BEED4:
    ctx->pc = 0x800BEED4u;
    // 800BEED4: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BEED8:
    ctx->pc = 0x800BEED8u;
    // 800BEED8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BEEDC:
    ctx->pc = 0x800BEEDCu;
    // 800BEEDC: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BEEE0:
    ctx->pc = 0x800BEEE0u;
    // 800BEEE0: bl      0x800C3D88
    {
            ctx->lr = 0x800BEEE4u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BEEE4:
    ctx->pc = 0x800BEEE4u;
    ctx->downcount -= 1;
    // 800BEEE4: b       0x800BEFDC
    {
            goto label_800BEFDC;
    }

label_800BEEE8:
    ctx->pc = 0x800BEEE8u;
    ctx->downcount -= 4;
    // 800BEEE8: addi    r29, r26, -8
    ctx->gpr[29] = ctx->gpr[26] + (u32)(s32)(-8);

label_800BEEEC:
    ctx->pc = 0x800BEEECu;
    // 800BEEEC: addi    r28, r31, 1444
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(1444);

label_800BEEF0:
    ctx->pc = 0x800BEEF0u;
    // 800BEEF0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BEEF4:
    ctx->pc = 0x800BEEF4u;
    // 800BEEF4: bl      0x800BF484
    {
            ctx->lr = 0x800BEEF8u;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BEEF8:
    ctx->pc = 0x800BEEF8u;
    ctx->downcount -= 2;
    // 800BEEF8: cmpwi   r3, 0
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

label_800BEEFC:
    ctx->pc = 0x800BEEFCu;
    // 800BEEFC: bc    12, 2, 0x800BEFDC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BEFDC;
        }
    }

label_800BEF00:
    ctx->pc = 0x800BEF00u;
    ctx->downcount -= 22;
    // 800BEF00: mulli   r29, r29, 52
    ctx->gpr[29] = (u32)((s64)(s32)ctx->gpr[29] * (s64)(s32)52);

label_800BEF04:
    ctx->pc = 0x800BEF04u;
    // 800BEF04: lis     r30, -32734
    ctx->gpr[30] = ((u32)(s32)(-32734) << 16);

label_800BEF08:
    ctx->pc = 0x800BEF08u;
    // 800BEF08: addi    r30, r30, -2412
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(-2412);

label_800BEF0C:
    ctx->pc = 0x800BEF0Cu;
    // 800BEF0C: lwz     r10, 1420(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1420);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEF10:
    ctx->pc = 0x800BEF10u;
    // 800BEF10: addi    r11, r30, 4
    ctx->gpr[11] = ctx->gpr[30] + (u32)(s32)(4);

label_800BEF14:
    ctx->pc = 0x800BEF14u;
    // 800BEF14: addi    r9, r31, 1420
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(1420);

label_800BEF18:
    ctx->pc = 0x800BEF18u;
    // 800BEF18: lwz     r3, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BEF1C:
    ctx->pc = 0x800BEF1Cu;
    // 800BEF1C: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BEF20:
    ctx->pc = 0x800BEF20u;
    // 800BEF20: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEF24:
    ctx->pc = 0x800BEF24u;
    // 800BEF24: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BEF28:
    ctx->pc = 0x800BEF28u;
    // 800BEF28: lwzx    r5, r11, r29
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[29];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BEF2C:
    ctx->pc = 0x800BEF2Cu;
    // 800BEF2C: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BEF30:
    ctx->pc = 0x800BEF30u;
    // 800BEF30: stw     r10, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BEF34:
    ctx->pc = 0x800BEF34u;
    // 800BEF34: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BEF38:
    ctx->pc = 0x800BEF38u;
    // 800BEF38: stw     r3, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800BEF3C:
    ctx->pc = 0x800BEF3Cu;
    // 800BEF3C: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BEF40:
    ctx->pc = 0x800BEF40u;
    // 800BEF40: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BEF44:
    ctx->pc = 0x800BEF44u;
    // 800BEF44: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEF48:
    ctx->pc = 0x800BEF48u;
    // 800BEF48: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BEF4C:
    ctx->pc = 0x800BEF4Cu;
    // 800BEF4C: bl      0x800C3D88
    {
            ctx->lr = 0x800BEF50u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BEF50:
    ctx->pc = 0x800BEF50u;
    ctx->downcount -= 18;
    // 800BEF50: lwz     r10, 1432(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1432);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BEF54:
    ctx->pc = 0x800BEF54u;
    // 800BEF54: addi    r11, r30, 8
    ctx->gpr[11] = ctx->gpr[30] + (u32)(s32)(8);

label_800BEF58:
    ctx->pc = 0x800BEF58u;
    // 800BEF58: addi    r9, r31, 1432
    ctx->gpr[9] = ctx->gpr[31] + (u32)(s32)(1432);

label_800BEF5C:
    ctx->pc = 0x800BEF5Cu;
    // 800BEF5C: lwzx    r5, r11, r29
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[29];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BEF60:
    ctx->pc = 0x800BEF60u;
    // 800BEF60: lwz     r8, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800BEF64:
    ctx->pc = 0x800BEF64u;
    // 800BEF64: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BEF68:
    ctx->pc = 0x800BEF68u;
    // 800BEF68: lwz     r0, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEF6C:
    ctx->pc = 0x800BEF6Cu;
    // 800BEF6C: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BEF70:
    ctx->pc = 0x800BEF70u;
    // 800BEF70: stw     r10, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800BEF74:
    ctx->pc = 0x800BEF74u;
    // 800BEF74: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BEF78:
    ctx->pc = 0x800BEF78u;
    // 800BEF78: stw     r8, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800BEF7C:
    ctx->pc = 0x800BEF7Cu;
    // 800BEF7C: ori     r6, r6, 0x8000
    ctx->gpr[6] = ctx->gpr[6] | 0x8000u;

label_800BEF80:
    ctx->pc = 0x800BEF80u;
    // 800BEF80: stw     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEF84:
    ctx->pc = 0x800BEF84u;
    // 800BEF84: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BEF88:
    ctx->pc = 0x800BEF88u;
    // 800BEF88: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BEF8C:
    ctx->pc = 0x800BEF8Cu;
    // 800BEF8C: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BEF90:
    ctx->pc = 0x800BEF90u;
    // 800BEF90: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BEF94:
    ctx->pc = 0x800BEF94u;
    // 800BEF94: bl      0x800C3D88
    {
            ctx->lr = 0x800BEF98u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BEF98:
    ctx->pc = 0x800BEF98u;
    ctx->downcount -= 17;
    // 800BEF98: lwz     r0, 1444(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1444);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEF9C:
    ctx->pc = 0x800BEF9Cu;
    // 800BEF9C: addi    r30, r30, 12
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(12);

label_800BEFA0:
    ctx->pc = 0x800BEFA0u;
    // 800BEFA0: lwz     r9, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BEFA4:
    ctx->pc = 0x800BEFA4u;
    // 800BEFA4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BEFA8:
    ctx->pc = 0x800BEFA8u;
    // 800BEFA8: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEFAC:
    ctx->pc = 0x800BEFACu;
    // 800BEFAC: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BEFB0:
    ctx->pc = 0x800BEFB0u;
    // 800BEFB0: lwzx    r5, r30, r29
    {
        u32 ea = ctx->gpr[30] + ctx->gpr[29];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_800BEFB4:
    ctx->pc = 0x800BEFB4u;
    // 800BEFB4: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BEFB8:
    ctx->pc = 0x800BEFB8u;
    // 800BEFB8: stw     r0, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEFBC:
    ctx->pc = 0x800BEFBCu;
    // 800BEFBC: ori     r6, r6, 0x8000
    ctx->gpr[6] = ctx->gpr[6] | 0x8000u;

label_800BEFC0:
    ctx->pc = 0x800BEFC0u;
    // 800BEFC0: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BEFC4:
    ctx->pc = 0x800BEFC4u;
    // 800BEFC4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BEFC8:
    ctx->pc = 0x800BEFC8u;
    // 800BEFC8: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BEFCC:
    ctx->pc = 0x800BEFCCu;
    // 800BEFCC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BEFD0:
    ctx->pc = 0x800BEFD0u;
    // 800BEFD0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BEFD4:
    ctx->pc = 0x800BEFD4u;
    // 800BEFD4: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BEFD8:
    ctx->pc = 0x800BEFD8u;
    // 800BEFD8: bl      0x800C3D88
    {
            ctx->lr = 0x800BEFDCu;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BEFDC:
    ctx->pc = 0x800BEFDCu;
    ctx->downcount -= 13;
    // 800BEFDC: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEFE0:
    ctx->pc = 0x800BEFE0u;
    // 800BEFE0: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BEFE4:
    ctx->pc = 0x800BEFE4u;
    // 800BEFE4: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BEFE8:
    ctx->pc = 0x800BEFE8u;
    // 800BEFE8: cmpwi   r26, 7
    {
        s32 val_a = (s32)(ctx->gpr[26]);
        s32 val_b = (s32)(7);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BEFEC:
    ctx->pc = 0x800BEFECu;
    // 800BEFEC: stw     r0, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BEFF0:
    ctx->pc = 0x800BEFF0u;
    // 800BEFF0: lfs     f13, -15796(r9)
    if (!ppc_fp_available(ctx, 0x800BEFF0u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15796);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[13] = value;
        ctx->ps1[13] = value;
    }

label_800BEFF4:
    ctx->pc = 0x800BEFF4u;
    // 800BEFF4: lfs     f0, 2172(r1)
    if (!ppc_fp_available(ctx, 0x800BEFF4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2172);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BEFF8:
    ctx->pc = 0x800BEFF8u;
    // 800BEFF8: lwz     r0, 1444(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(1444);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BEFFC:
    ctx->pc = 0x800BEFFCu;
    // 800BEFFC: stw     r11, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BF000:
    ctx->pc = 0x800BF000u;
    // 800BF000: fadds   f0, f0, f13
    if (!ppc_fp_available(ctx, 0x800BF000u)) return;
    ppc_fadds(ctx, 0, 0, 13);

label_800BF004:
    ctx->pc = 0x800BF004u;
    // 800BF004: stw     r0, 2168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2168);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BF008:
    ctx->pc = 0x800BF008u;
    // 800BF008: stfs     f0, 2172(r1)
    if (!ppc_fp_available(ctx, 0x800BF008u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2172);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BF00C:
    ctx->pc = 0x800BF00Cu;
    // 800BF00C: bc    12, 1, 0x800BF074
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF074;
        }
    }

label_800BF010:
    ctx->pc = 0x800BF010u;
    ctx->downcount -= 11;
    // 800BF010: mulli   r8, r26, 52
    ctx->gpr[8] = (u32)((s64)(s32)ctx->gpr[26] * (s64)(s32)52);

label_800BF014:
    ctx->pc = 0x800BF014u;
    // 800BF014: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BF018:
    ctx->pc = 0x800BF018u;
    // 800BF018: addi    r9, r9, -2880
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BF01C:
    ctx->pc = 0x800BF01Cu;
    // 800BF01C: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_800BF020:
    ctx->pc = 0x800BF020u;
    // 800BF020: lis     r11, -32699
    ctx->gpr[11] = ((u32)(s32)(-32699) << 16);

label_800BF024:
    ctx->pc = 0x800BF024u;
    // 800BF024: lwz     r10, -20700(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(-20700);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800BF028:
    ctx->pc = 0x800BF028u;
    // 800BF028: lwzx    r0, r9, r8
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[8];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BF02C:
    ctx->pc = 0x800BF02Cu;
    // 800BF02C: and.   r9, r10, r0
    {
        ctx->gpr[9] = ctx->gpr[10] & ctx->gpr[0];
        u32 cr_bits = 0;
        s32 cr_value = (s32)ctx->gpr[9];
        if (cr_value < 0)  cr_bits |= 0x8u;
        if (cr_value > 0)  cr_bits |= 0x4u;
        if (cr_value == 0) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & 0x0FFFFFFFu) | (cr_bits << 28);
    }

label_800BF030:
    ctx->pc = 0x800BF030u;
    // 800BF030: bc    12, 2, 0x800BF0EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF0EC;
        }
    }

label_800BF034:
    ctx->pc = 0x800BF034u;
    ctx->downcount -= 15;
    // 800BF034: lwz     r0, 2168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BF038:
    ctx->pc = 0x800BF038u;
    // 800BF038: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BF03C:
    ctx->pc = 0x800BF03Cu;
    // 800BF03C: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BF040:
    ctx->pc = 0x800BF040u;
    // 800BF040: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BF044:
    ctx->pc = 0x800BF044u;
    // 800BF044: lwz     r11, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BF048:
    ctx->pc = 0x800BF048u;
    // 800BF048: li      r5, 3790
    ctx->gpr[5] = (u32)(s32)(3790);

label_800BF04C:
    ctx->pc = 0x800BF04Cu;
    // 800BF04C: stw     r0, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BF050:
    ctx->pc = 0x800BF050u;
    // 800BF050: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BF054:
    ctx->pc = 0x800BF054u;
    // 800BF054: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BF058:
    ctx->pc = 0x800BF058u;
    // 800BF058: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BF05C:
    ctx->pc = 0x800BF05Cu;
    // 800BF05C: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BF060:
    ctx->pc = 0x800BF060u;
    // 800BF060: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BF064:
    ctx->pc = 0x800BF064u;
    // 800BF064: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BF068:
    ctx->pc = 0x800BF068u;
    // 800BF068: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BF06C:
    ctx->pc = 0x800BF06Cu;
    // 800BF06C: bl      0x800C3D88
    {
            ctx->lr = 0x800BF070u;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BF070:
    ctx->pc = 0x800BF070u;
    ctx->downcount -= 1;
    // 800BF070: b       0x800BF0EC
    {
            goto label_800BF0EC;
    }

label_800BF074:
    ctx->pc = 0x800BF074u;
    ctx->downcount -= 3;
    // 800BF074: addi    r31, r26, -8
    ctx->gpr[31] = ctx->gpr[26] + (u32)(s32)(-8);

label_800BF078:
    ctx->pc = 0x800BF078u;
    // 800BF078: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BF07C:
    ctx->pc = 0x800BF07Cu;
    // 800BF07C: bl      0x800BF484
    {
            ctx->lr = 0x800BF080u;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BF080:
    ctx->pc = 0x800BF080u;
    ctx->downcount -= 2;
    // 800BF080: cmpwi   r3, 0
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

label_800BF084:
    ctx->pc = 0x800BF084u;
    // 800BF084: bc    12, 2, 0x800BF0EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF0EC;
        }
    }

label_800BF088:
    ctx->pc = 0x800BF088u;
    ctx->downcount -= 2;
    // 800BF088: or   r3, r31, r31
    {
        ctx->gpr[3] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BF08C:
    ctx->pc = 0x800BF08Cu;
    // 800BF08C: bl      0x800BF320
    {
            ctx->lr = 0x800BF090u;
            ctx->pc = 0x800BF320u;
            return;
    }

label_800BF090:
    ctx->pc = 0x800BF090u;
    ctx->downcount -= 2;
    // 800BF090: cmpwi   r3, 0
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

label_800BF094:
    ctx->pc = 0x800BF094u;
    // 800BF094: bc    12, 2, 0x800BF0EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF0EC;
        }
    }

label_800BF098:
    ctx->pc = 0x800BF098u;
    ctx->downcount -= 8;
    // 800BF098: mulli   r0, r31, 52
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[31] * (s64)(s32)52);

label_800BF09C:
    ctx->pc = 0x800BF09Cu;
    // 800BF09C: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BF0A0:
    ctx->pc = 0x800BF0A0u;
    // 800BF0A0: addi    r9, r9, -2412
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2412);

label_800BF0A4:
    ctx->pc = 0x800BF0A4u;
    // 800BF0A4: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BF0A8:
    ctx->pc = 0x800BF0A8u;
    // 800BF0A8: cmpwi   r11, 0
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

label_800BF0AC:
    ctx->pc = 0x800BF0ACu;
    // 800BF0AC: bc    12, 2, 0x800BF0EC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF0EC;
        }
    }

label_800BF0B0:
    ctx->pc = 0x800BF0B0u;
    ctx->downcount -= 15;
    // 800BF0B0: lwz     r0, 2168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2168);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BF0B4:
    ctx->pc = 0x800BF0B4u;
    // 800BF0B4: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BF0B8:
    ctx->pc = 0x800BF0B8u;
    // 800BF0B8: lwz     r9, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800BF0BC:
    ctx->pc = 0x800BF0BCu;
    // 800BF0BC: or   r4, r27, r27
    {
        ctx->gpr[4] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BF0C0:
    ctx->pc = 0x800BF0C0u;
    // 800BF0C0: lwz     r11, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BF0C4:
    ctx->pc = 0x800BF0C4u;
    // 800BF0C4: li      r5, 3790
    ctx->gpr[5] = (u32)(s32)(3790);

label_800BF0C8:
    ctx->pc = 0x800BF0C8u;
    // 800BF0C8: stw     r0, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BF0CC:
    ctx->pc = 0x800BF0CCu;
    // 800BF0CC: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BF0D0:
    ctx->pc = 0x800BF0D0u;
    // 800BF0D0: stw     r9, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800BF0D4:
    ctx->pc = 0x800BF0D4u;
    // 800BF0D4: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BF0D8:
    ctx->pc = 0x800BF0D8u;
    // 800BF0D8: stw     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BF0DC:
    ctx->pc = 0x800BF0DCu;
    // 800BF0DC: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BF0E0:
    ctx->pc = 0x800BF0E0u;
    // 800BF0E0: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BF0E4:
    ctx->pc = 0x800BF0E4u;
    // 800BF0E4: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BF0E8:
    ctx->pc = 0x800BF0E8u;
    // 800BF0E8: bl      0x800C3D88
    {
            ctx->lr = 0x800BF0ECu;
            ctx->pc = 0x800C3D88u;
            return;
    }

label_800BF0EC:
    ctx->pc = 0x800BF0ECu;
    ctx->downcount -= 5;
    // 800BF0EC: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BF0F0:
    ctx->pc = 0x800BF0F0u;
    // 800BF0F0: addi    r9, r9, -2880
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2880);

label_800BF0F4:
    ctx->pc = 0x800BF0F4u;
    // 800BF0F4: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BF0F8:
    ctx->pc = 0x800BF0F8u;
    // 800BF0F8: cmpwi   r0, -1
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

label_800BF0FC:
    ctx->pc = 0x800BF0FCu;
    // 800BF0FC: bc    12, 2, 0x800BF120
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF120;
        }
    }

label_800BF100:
    ctx->pc = 0x800BF100u;
    ctx->downcount -= 1;
    // 800BF100: or   r30, r9, r9
    {
        ctx->gpr[30] = ctx->gpr[9] | ctx->gpr[9];
    }

label_800BF104:
    ctx->pc = 0x800BF104u;
    ctx->downcount -= 2;
    // 800BF104: lwz     r3, 32(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(32);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BF108:
    // 800BF108: bl      0x800C473C
    {
            ctx->lr = 0x800BF10Cu;
            ctx->pc = 0x800C473Cu;
            return;
    }

label_800BF10C:
    ctx->pc = 0x800BF10Cu;
    ctx->downcount -= 2;
    // 800BF10C: lwz     r3, 28(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(28);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BF110:
    // 800BF110: bl      0x800C473C
    {
            ctx->lr = 0x800BF114u;
            ctx->pc = 0x800C473Cu;
            return;
    }

label_800BF114:
    ctx->pc = 0x800BF114u;
    ctx->downcount -= 3;
    // 800BF114: lwzu     r0, 52(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[30] = ea;
    }

label_800BF118:
    // 800BF118: cmpwi   r0, -1
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

label_800BF11C:
    // 800BF11C: bc    4, 2, 0x800BF104
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BF104u;
                return;
            }
            goto label_800BF104;
        }
    }

label_800BF120:
    ctx->pc = 0x800BF120u;
    ctx->downcount -= 6;
    // 800BF120: lis     r9, -32734
    ctx->gpr[9] = ((u32)(s32)(-32734) << 16);

label_800BF124:
    ctx->pc = 0x800BF124u;
    // 800BF124: li      r28, 0
    ctx->gpr[28] = (u32)(s32)(0);

label_800BF128:
    ctx->pc = 0x800BF128u;
    // 800BF128: addi    r11, r9, -2412
    ctx->gpr[11] = ctx->gpr[9] + (u32)(s32)(-2412);

label_800BF12C:
    ctx->pc = 0x800BF12Cu;
    // 800BF12C: lwzx    r0, r11, r28
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[28];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BF130:
    ctx->pc = 0x800BF130u;
    // 800BF130: cmpwi   r0, -1
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

label_800BF134:
    ctx->pc = 0x800BF134u;
    // 800BF134: bc    12, 2, 0x800BF2A8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF2A8;
        }
    }

label_800BF138:
    ctx->pc = 0x800BF138u;
    ctx->downcount -= 7;
    // 800BF138: lis     r9, -32737
    ctx->gpr[9] = ((u32)(s32)(-32737) << 16);

label_800BF13C:
    ctx->pc = 0x800BF13Cu;
    // 800BF13C: or   r24, r11, r11
    {
        ctx->gpr[24] = ctx->gpr[11] | ctx->gpr[11];
    }

label_800BF140:
    ctx->pc = 0x800BF140u;
    // 800BF140: lfs     f31, -15792(r9)
    if (!ppc_fp_available(ctx, 0x800BF140u)) return;
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(-15792);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[31] = value;
        ctx->ps1[31] = value;
    }

label_800BF144:
    ctx->pc = 0x800BF144u;
    // 800BF144: or   r21, r24, r24
    {
        ctx->gpr[21] = ctx->gpr[24] | ctx->gpr[24];
    }

label_800BF148:
    ctx->pc = 0x800BF148u;
    // 800BF148: or   r26, r27, r27
    {
        ctx->gpr[26] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BF14C:
    ctx->pc = 0x800BF14Cu;
    // 800BF14C: lis     r22, -32698
    ctx->gpr[22] = ((u32)(s32)(-32698) << 16);

label_800BF150:
    ctx->pc = 0x800BF150u;
    // 800BF150: addi    r23, r24, 36
    ctx->gpr[23] = ctx->gpr[24] + (u32)(s32)(36);

label_800BF154:
    ctx->downcount -= 5;
    // 800BF154: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BF158:
    // 800BF158: mulli   r31, r28, 52
    ctx->gpr[31] = (u32)((s64)(s32)ctx->gpr[28] * (s64)(s32)52);

label_800BF15C:
    // 800BF15C: bl      0x800BF484
    {
            ctx->lr = 0x800BF160u;
            ctx->pc = 0x800BF484u;
            return;
    }

label_800BF160:
    ctx->downcount -= 2;
    // 800BF160: cmpwi   r3, 0
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

label_800BF164:
    // 800BF164: bc    12, 2, 0x800BF27C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF27C;
        }
    }

label_800BF168:
    ctx->downcount -= 2;
    // 800BF168: cmpwi   r28, 4
    {
        s32 val_a = (s32)(ctx->gpr[28]);
        s32 val_b = (s32)(4);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_800BF16C:
    // 800BF16C: bc    12, 1, 0x800BF27C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF27C;
        }
    }

label_800BF170:
    ctx->downcount -= 3;
    // 800BF170: addi    r30, r1, 2184
    ctx->gpr[30] = ctx->gpr[1] + (u32)(s32)(2184);

label_800BF174:
    // 800BF174: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BF178:
    // 800BF178: bl      0x800BF320
    {
            ctx->lr = 0x800BF17Cu;
            ctx->pc = 0x800BF320u;
            return;
    }

label_800BF17C:
    ctx->downcount -= 4;
    // 800BF17C: or   r27, r30, r30
    {
        ctx->gpr[27] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BF180:
    // 800BF180: or   r29, r3, r3
    {
        ctx->gpr[29] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BF184:
    // 800BF184: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800BF188:
    // 800BF188: bl      0x800BF434
    {
            ctx->lr = 0x800BF18Cu;
            ctx->pc = 0x800BF434u;
            return;
    }

label_800BF18C:
    ctx->downcount -= 5;
    // 800BF18C: or   r31, r3, r3
    {
        ctx->gpr[31] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BF190:
    // 800BF190: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BF194:
    // 800BF194: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800BF198:
    // 800BF198: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800BF19C:
    // 800BF19C: bl      0x801698F0
    {
            ctx->lr = 0x800BF1A0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800BF1A0:
    ctx->downcount -= 2;
    // 800BF1A0: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BF1A4:
    // 800BF1A4: bl      0x80036180
    {
            ctx->lr = 0x800BF1A8u;
            ctx->pc = 0x80036180u;
            return;
    }

label_800BF1A8:
    ctx->downcount -= 5;
    // 800BF1A8: or   r5, r29, r29
    {
        ctx->gpr[5] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800BF1AC:
    // 800BF1AC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BF1B0:
    // 800BF1B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800BF1B4:
    // 800BF1B4: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BF1B8:
    // 800BF1B8: bl      0x800361A8
    {
            ctx->lr = 0x800BF1BCu;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BF1BC:
    ctx->downcount -= 2;
    // 800BF1BC: cmpwi   r31, 0
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

label_800BF1C0:
    // 800BF1C0: bc    12, 2, 0x800BF1FC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_800BF1FC;
        }
    }

label_800BF1C4:
    ctx->downcount -= 5;
    // 800BF1C4: or   r5, r31, r31
    {
        ctx->gpr[5] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800BF1C8:
    // 800BF1C8: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BF1CC:
    // 800BF1CC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BF1D0:
    // 800BF1D0: li      r4, 1
    ctx->gpr[4] = (u32)(s32)(1);

label_800BF1D4:
    // 800BF1D4: bl      0x800361A8
    {
            ctx->lr = 0x800BF1D8u;
            ctx->pc = 0x800361A8u;
            return;
    }

label_800BF1D8:
    ctx->downcount -= 3;
    // 800BF1D8: li      r4, 3683
    ctx->gpr[4] = (u32)(s32)(3683);

label_800BF1DC:
    // 800BF1DC: addi    r3, r22, 9872
    ctx->gpr[3] = ctx->gpr[22] + (u32)(s32)(9872);

label_800BF1E0:
    // 800BF1E0: bl      0x80046B00
    {
            ctx->lr = 0x800BF1E4u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BF1E4:
    ctx->downcount -= 5;
    // 800BF1E4: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BF1E8:
    // 800BF1E8: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BF1EC:
    // 800BF1EC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BF1F0:
    // 800BF1F0: li      r6, 20
    ctx->gpr[6] = (u32)(s32)(20);

label_800BF1F4:
    // 800BF1F4: bl      0x8003632C
    {
            ctx->lr = 0x800BF1F8u;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BF1F8:
    ctx->downcount -= 1;
    // 800BF1F8: b       0x800BF21C
    {
            goto label_800BF21C;
    }

label_800BF1FC:
    ctx->downcount -= 3;
    // 800BF1FC: li      r4, 3684
    ctx->gpr[4] = (u32)(s32)(3684);

label_800BF200:
    // 800BF200: addi    r3, r22, 9872
    ctx->gpr[3] = ctx->gpr[22] + (u32)(s32)(9872);

label_800BF204:
    // 800BF204: bl      0x80046B00
    {
            ctx->lr = 0x800BF208u;
            ctx->pc = 0x80046B00u;
            return;
    }

label_800BF208:
    ctx->downcount -= 5;
    // 800BF208: or   r4, r3, r3
    {
        ctx->gpr[4] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800BF20C:
    // 800BF20C: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BF210:
    // 800BF210: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_800BF214:
    // 800BF214: li      r6, 20
    ctx->gpr[6] = (u32)(s32)(20);

label_800BF218:
    // 800BF218: bl      0x8003632C
    {
            ctx->lr = 0x800BF21Cu;
            ctx->pc = 0x8003632Cu;
            return;
    }

label_800BF21C:
    ctx->downcount -= 5;
    // 800BF21C: or   r4, r23, r23
    {
        ctx->gpr[4] = ctx->gpr[23] | ctx->gpr[23];
    }

label_800BF220:
    // 800BF220: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_800BF224:
    // 800BF224: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_800BF228:
    // 800BF228: or   r3, r25, r25
    {
        ctx->gpr[3] = ctx->gpr[25] | ctx->gpr[25];
    }

label_800BF22C:
    // 800BF22C: bl      0x800C48AC
    {
            ctx->lr = 0x800BF230u;
            ctx->pc = 0x800C48ACu;
            return;
    }

label_800BF230:
    ctx->downcount -= 21;
    // 800BF230: mulli   r31, r28, 52
    ctx->gpr[31] = (u32)((s64)(s32)ctx->gpr[28] * (s64)(s32)52);

label_800BF234:
    ctx->pc = 0x800BF234u;
    // 800BF234: lfs     f0, 2172(r1)
    if (!ppc_fp_available(ctx, 0x800BF234u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2172);
        f64 value = dolrecomp_f32_from_bits(mem_read32(ctx, ea));
        ctx->fpr[0] = value;
        ctx->ps1[0] = value;
    }

label_800BF238:
    // 800BF238: or   r5, r27, r27
    {
        ctx->gpr[5] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800BF23C:
    ctx->pc = 0x800BF23Cu;
    // 800BF23C: lwz     r30, 2168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2168);
        ctx->gpr[30] = mem_read32(ctx, ea);
    }

label_800BF240:
    // 800BF240: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_800BF244:
    ctx->pc = 0x800BF244u;
    // 800BF244: fadds   f0, f0, f31
    if (!ppc_fp_available(ctx, 0x800BF244u)) return;
    ppc_fadds(ctx, 0, 0, 31);

label_800BF248:
    // 800BF248: or   r4, r26, r26
    {
        ctx->gpr[4] = ctx->gpr[26] | ctx->gpr[26];
    }

label_800BF24C:
    ctx->pc = 0x800BF24Cu;
    // 800BF24C: stfs     f0, 2172(r1)
    if (!ppc_fp_available(ctx, 0x800BF24Cu)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2172);
        mem_write32(ctx, ea, dolrecomp_f32_to_bits(ctx->fpr[0]));
    }

label_800BF250:
    // 800BF250: li      r6, 4
    ctx->gpr[6] = (u32)(s32)(4);

label_800BF254:
    // 800BF254: li      r7, 0
    ctx->gpr[7] = (u32)(s32)(0);

label_800BF258:
    // 800BF258: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_800BF25C:
    ctx->pc = 0x800BF25Cu;
    // 800BF25C: lwz     r11, 4(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800BF260:
    // 800BF260: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_800BF264:
    ctx->pc = 0x800BF264u;
    // 800BF264: lwz     r0, 8(r25)
    {
        u32 ea = ctx->gpr[25] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BF268:
    // 800BF268: li      r10, 255
    ctx->gpr[10] = (u32)(s32)(255);

label_800BF26C:
    ctx->pc = 0x800BF26Cu;
    // 800BF26C: stw     r30, 2208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2208);
        mem_write32(ctx, ea, (u32)ctx->gpr[30]);
    }

label_800BF270:
    ctx->pc = 0x800BF270u;
    // 800BF270: stw     r11, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800BF274:
    ctx->pc = 0x800BF274u;
    // 800BF274: stw     r0, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800BF278:
    // 800BF278: bl      0x800C3E20
    {
            ctx->lr = 0x800BF27Cu;
            ctx->pc = 0x800C3E20u;
            return;
    }

label_800BF27C:
    ctx->downcount -= 5;
    // 800BF27C: addi    r9, r21, 32
    ctx->gpr[9] = ctx->gpr[21] + (u32)(s32)(32);

label_800BF280:
    // 800BF280: addi    r23, r23, 52
    ctx->gpr[23] = ctx->gpr[23] + (u32)(s32)(52);

label_800BF284:
    ctx->pc = 0x800BF284u;
    // 800BF284: lwzx    r3, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BF288:
    // 800BF288: addi    r28, r28, 1
    ctx->gpr[28] = ctx->gpr[28] + (u32)(s32)(1);

label_800BF28C:
    // 800BF28C: bl      0x800C473C
    {
            ctx->lr = 0x800BF290u;
            ctx->pc = 0x800C473Cu;
            return;
    }

label_800BF290:
    ctx->downcount -= 3;
    // 800BF290: addi    r9, r21, 28
    ctx->gpr[9] = ctx->gpr[21] + (u32)(s32)(28);

label_800BF294:
    ctx->pc = 0x800BF294u;
    // 800BF294: lwzx    r3, r9, r31
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[31];
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800BF298:
    // 800BF298: bl      0x800C473C
    {
            ctx->lr = 0x800BF29Cu;
            ctx->pc = 0x800C473Cu;
            return;
    }

label_800BF29C:
    ctx->pc = 0x800BF29Cu;
    ctx->downcount -= 3;
    // 800BF29C: lwzu     r0, 52(r24)
    {
        u32 ea = ctx->gpr[24] + (u32)(s32)(52);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[24] = ea;
    }

label_800BF2A0:
    // 800BF2A0: cmpwi   r0, -1
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

label_800BF2A4:
    // 800BF2A4: bc    4, 2, 0x800BF154
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800BF154u;
                return;
            }
            goto label_800BF154;
        }
    }

label_800BF2A8:
    ctx->pc = 0x800BF2A8u;
    ctx->downcount -= 17;
    // 800BF2A8: lwz     r0, 2284(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2284);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800BF2AC:
    ctx->pc = 0x800BF2ACu;
    // 800BF2AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_800BF2B0:
    ctx->pc = 0x800BF2B0u;
    // 800BF2B0: lmw     r21, 2228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2228);
        for (u32 r = 21; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_800BF2B4:
    ctx->pc = 0x800BF2B4u;
    // 800BF2B4: lfd     f31, 2272(r1)
    if (!ppc_fp_available(ctx, 0x800BF2B4u)) return;
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(2272);
        ctx->fpr[31] = dolrecomp_f64_from_bits(mem_read64(ctx, ea));
    }

label_800BF2B8:
    ctx->pc = 0x800BF2B8u;
    // 800BF2B8: addi    r1, r1, 2280
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(2280);

label_800BF2BC:
    ctx->pc = 0x800BF2BCu;
    // 800BF2BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_800BB2C0;
        }
    }

    ctx->pc = 0x800BF2C0u;
    return;
return_dispatch_800BB2C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x800BB314u: goto label_800BB314;
    case 0x800BB344u: goto label_800BB344;
    case 0x800BB378u: goto label_800BB378;
    case 0x800BB3BCu: goto label_800BB3BC;
    case 0x800BB3ECu: goto label_800BB3EC;
    case 0x800BB420u: goto label_800BB420;
    case 0x800BB498u: goto label_800BB498;
    case 0x800BB4B8u: goto label_800BB4B8;
    case 0x800BB508u: goto label_800BB508;
    case 0x800BB56Cu: goto label_800BB56C;
    case 0x800BB5A0u: goto label_800BB5A0;
    case 0x800BB5CCu: goto label_800BB5CC;
    case 0x800BB600u: goto label_800BB600;
    case 0x800BB62Cu: goto label_800BB62C;
    case 0x800BB664u: goto label_800BB664;
    case 0x800BB6D4u: goto label_800BB6D4;
    case 0x800BB6E8u: goto label_800BB6E8;
    case 0x800BB794u: goto label_800BB794;
    case 0x800BB804u: goto label_800BB804;
    case 0x800BB844u: goto label_800BB844;
    case 0x800BB84Cu: goto label_800BB84C;
    case 0x800BB858u: goto label_800BB858;
    case 0x800BB86Cu: goto label_800BB86C;
    case 0x800BB874u: goto label_800BB874;
    case 0x800BB888u: goto label_800BB888;
    case 0x800BB898u: goto label_800BB898;
    case 0x800BB8ACu: goto label_800BB8AC;
    case 0x800BB8F0u: goto label_800BB8F0;
    case 0x800BB900u: goto label_800BB900;
    case 0x800BB984u: goto label_800BB984;
    case 0x800BB9C4u: goto label_800BB9C4;
    case 0x800BB9D4u: goto label_800BB9D4;
    case 0x800BB9DCu: goto label_800BB9DC;
    case 0x800BB9F8u: goto label_800BB9F8;
    case 0x800BBA08u: goto label_800BBA08;
    case 0x800BBA1Cu: goto label_800BBA1C;
    case 0x800BBA60u: goto label_800BBA60;
    case 0x800BBAACu: goto label_800BBAAC;
    case 0x800BBAF0u: goto label_800BBAF0;
    case 0x800BBB00u: goto label_800BBB00;
    case 0x800BBB08u: goto label_800BBB08;
    case 0x800BBB2Cu: goto label_800BBB2C;
    case 0x800BBB50u: goto label_800BBB50;
    case 0x800BBB60u: goto label_800BBB60;
    case 0x800BBB74u: goto label_800BBB74;
    case 0x800BBBB8u: goto label_800BBBB8;
    case 0x800BBC18u: goto label_800BBC18;
    case 0x800BBC60u: goto label_800BBC60;
    case 0x800BBCA8u: goto label_800BBCA8;
    case 0x800BBCF0u: goto label_800BBCF0;
    case 0x800BBD9Cu: goto label_800BBD9C;
    case 0x800BBDBCu: goto label_800BBDBC;
    case 0x800BBDC4u: goto label_800BBDC4;
    case 0x800BBDD8u: goto label_800BBDD8;
    case 0x800BBDE4u: goto label_800BBDE4;
    case 0x800BBDF8u: goto label_800BBDF8;
    case 0x800BBE38u: goto label_800BBE38;
    case 0x800BBE48u: goto label_800BBE48;
    case 0x800BBE50u: goto label_800BBE50;
    case 0x800BBE64u: goto label_800BBE64;
    case 0x800BBE70u: goto label_800BBE70;
    case 0x800BBE84u: goto label_800BBE84;
    case 0x800BBEC4u: goto label_800BBEC4;
    case 0x800BBED4u: goto label_800BBED4;
    case 0x800BBEDCu: goto label_800BBEDC;
    case 0x800BBEF0u: goto label_800BBEF0;
    case 0x800BBEFCu: goto label_800BBEFC;
    case 0x800BBF10u: goto label_800BBF10;
    case 0x800BBF50u: goto label_800BBF50;
    case 0x800BBFE4u: goto label_800BBFE4;
    case 0x800BC054u: goto label_800BC054;
    case 0x800BC088u: goto label_800BC088;
    case 0x800BC0B8u: goto label_800BC0B8;
    case 0x800BC0C0u: goto label_800BC0C0;
    case 0x800BC0D4u: goto label_800BC0D4;
    case 0x800BC0E0u: goto label_800BC0E0;
    case 0x800BC0F4u: goto label_800BC0F4;
    case 0x800BC134u: goto label_800BC134;
    case 0x800BC158u: goto label_800BC158;
    case 0x800BC160u: goto label_800BC160;
    case 0x800BC174u: goto label_800BC174;
    case 0x800BC180u: goto label_800BC180;
    case 0x800BC194u: goto label_800BC194;
    case 0x800BC1D4u: goto label_800BC1D4;
    case 0x800BC230u: goto label_800BC230;
    case 0x800BC25Cu: goto label_800BC25C;
    case 0x800BC284u: goto label_800BC284;
    case 0x800BC28Cu: goto label_800BC28C;
    case 0x800BC2A0u: goto label_800BC2A0;
    case 0x800BC2ACu: goto label_800BC2AC;
    case 0x800BC2C0u: goto label_800BC2C0;
    case 0x800BC300u: goto label_800BC300;
    case 0x800BC31Cu: goto label_800BC31C;
    case 0x800BC324u: goto label_800BC324;
    case 0x800BC338u: goto label_800BC338;
    case 0x800BC344u: goto label_800BC344;
    case 0x800BC358u: goto label_800BC358;
    case 0x800BC398u: goto label_800BC398;
    case 0x800BC3F0u: goto label_800BC3F0;
    case 0x800BC414u: goto label_800BC414;
    case 0x800BC438u: goto label_800BC438;
    case 0x800BC484u: goto label_800BC484;
    case 0x800BC4A4u: goto label_800BC4A4;
    case 0x800BC4C8u: goto label_800BC4C8;
    case 0x800BC518u: goto label_800BC518;
    case 0x800BC550u: goto label_800BC550;
    case 0x800BC6E8u: goto label_800BC6E8;
    case 0x800BC758u: goto label_800BC758;
    case 0x800BC76Cu: goto label_800BC76C;
    case 0x800BC780u: goto label_800BC780;
    case 0x800BC7B0u: goto label_800BC7B0;
    case 0x800BC7F8u: goto label_800BC7F8;
    case 0x800BC81Cu: goto label_800BC81C;
    case 0x800BC840u: goto label_800BC840;
    case 0x800BC890u: goto label_800BC890;
    case 0x800BC8B0u: goto label_800BC8B0;
    case 0x800BC8ECu: goto label_800BC8EC;
    case 0x800BC8FCu: goto label_800BC8FC;
    case 0x800BC960u: goto label_800BC960;
    case 0x800BC9A8u: goto label_800BC9A8;
    case 0x800BC9C4u: goto label_800BC9C4;
    case 0x800BC9D4u: goto label_800BC9D4;
    case 0x800BC9FCu: goto label_800BC9FC;
    case 0x800BCA78u: goto label_800BCA78;
    case 0x800BCA88u: goto label_800BCA88;
    case 0x800BCAC8u: goto label_800BCAC8;
    case 0x800BCAD8u: goto label_800BCAD8;
    case 0x800BCB2Cu: goto label_800BCB2C;
    case 0x800BCB3Cu: goto label_800BCB3C;
    case 0x800BCB50u: goto label_800BCB50;
    case 0x800BCB94u: goto label_800BCB94;
    case 0x800BCBA8u: goto label_800BCBA8;
    case 0x800BCBB8u: goto label_800BCBB8;
    case 0x800BCC8Cu: goto label_800BCC8C;
    case 0x800BCCFCu: goto label_800BCCFC;
    case 0x800BCD10u: goto label_800BCD10;
    case 0x800BCD24u: goto label_800BCD24;
    case 0x800BCD54u: goto label_800BCD54;
    case 0x800BCD8Cu: goto label_800BCD8C;
    case 0x800BCDB0u: goto label_800BCDB0;
    case 0x800BCDD4u: goto label_800BCDD4;
    case 0x800BCE34u: goto label_800BCE34;
    case 0x800BCE54u: goto label_800BCE54;
    case 0x800BCEA8u: goto label_800BCEA8;
    case 0x800BCEB8u: goto label_800BCEB8;
    case 0x800BCF08u: goto label_800BCF08;
    case 0x800BCF28u: goto label_800BCF28;
    case 0x800BCF4Cu: goto label_800BCF4C;
    case 0x800BCF6Cu: goto label_800BCF6C;
    case 0x800BCF88u: goto label_800BCF88;
    case 0x800BCFCCu: goto label_800BCFCC;
    case 0x800BD0ACu: goto label_800BD0AC;
    case 0x800BD0C8u: goto label_800BD0C8;
    case 0x800BD104u: goto label_800BD104;
    case 0x800BD120u: goto label_800BD120;
    case 0x800BD17Cu: goto label_800BD17C;
    case 0x800BD198u: goto label_800BD198;
    case 0x800BD1D8u: goto label_800BD1D8;
    case 0x800BD204u: goto label_800BD204;
    case 0x800BD218u: goto label_800BD218;
    case 0x800BD234u: goto label_800BD234;
    case 0x800BD2F8u: goto label_800BD2F8;
    case 0x800BD308u: goto label_800BD308;
    case 0x800BD328u: goto label_800BD328;
    case 0x800BD358u: goto label_800BD358;
    case 0x800BD398u: goto label_800BD398;
    case 0x800BD450u: goto label_800BD450;
    case 0x800BD470u: goto label_800BD470;
    case 0x800BD4A8u: goto label_800BD4A8;
    case 0x800BD4C8u: goto label_800BD4C8;
    case 0x800BD500u: goto label_800BD500;
    case 0x800BD570u: goto label_800BD570;
    case 0x800BD590u: goto label_800BD590;
    case 0x800BD5E0u: goto label_800BD5E0;
    case 0x800BD610u: goto label_800BD610;
    case 0x800BD620u: goto label_800BD620;
    case 0x800BD628u: goto label_800BD628;
    case 0x800BD670u: goto label_800BD670;
    case 0x800BD714u: goto label_800BD714;
    case 0x800BD764u: goto label_800BD764;
    case 0x800BD840u: goto label_800BD840;
    case 0x800BD8A0u: goto label_800BD8A0;
    case 0x800BD91Cu: goto label_800BD91C;
    case 0x800BD95Cu: goto label_800BD95C;
    case 0x800BDA58u: goto label_800BDA58;
    case 0x800BDACCu: goto label_800BDACC;
    case 0x800BDAF4u: goto label_800BDAF4;
    case 0x800BDB14u: goto label_800BDB14;
    case 0x800BDB4Cu: goto label_800BDB4C;
    case 0x800BDB6Cu: goto label_800BDB6C;
    case 0x800BDBECu: goto label_800BDBEC;
    case 0x800BDCC0u: goto label_800BDCC0;
    case 0x800BDCE8u: goto label_800BDCE8;
    case 0x800BDD08u: goto label_800BDD08;
    case 0x800BDD98u: goto label_800BDD98;
    case 0x800BDDCCu: goto label_800BDDCC;
    case 0x800BDDECu: goto label_800BDDEC;
    case 0x800BDEB0u: goto label_800BDEB0;
    case 0x800BDF24u: goto label_800BDF24;
    case 0x800BDF90u: goto label_800BDF90;
    case 0x800BE02Cu: goto label_800BE02C;
    case 0x800BE064u: goto label_800BE064;
    case 0x800BE0E4u: goto label_800BE0E4;
    case 0x800BE17Cu: goto label_800BE17C;
    case 0x800BE1F4u: goto label_800BE1F4;
    case 0x800BE21Cu: goto label_800BE21C;
    case 0x800BE230u: goto label_800BE230;
    case 0x800BE23Cu: goto label_800BE23C;
    case 0x800BE270u: goto label_800BE270;
    case 0x800BE32Cu: goto label_800BE32C;
    case 0x800BE35Cu: goto label_800BE35C;
    case 0x800BE38Cu: goto label_800BE38C;
    case 0x800BE3ECu: goto label_800BE3EC;
    case 0x800BE41Cu: goto label_800BE41C;
    case 0x800BE450u: goto label_800BE450;
    case 0x800BE464u: goto label_800BE464;
    case 0x800BE470u: goto label_800BE470;
    case 0x800BE478u: goto label_800BE478;
    case 0x800BE4C0u: goto label_800BE4C0;
    case 0x800BE504u: goto label_800BE504;
    case 0x800BE524u: goto label_800BE524;
    case 0x800BE55Cu: goto label_800BE55C;
    case 0x800BE57Cu: goto label_800BE57C;
    case 0x800BE5B4u: goto label_800BE5B4;
    case 0x800BE5D4u: goto label_800BE5D4;
    case 0x800BE5F8u: goto label_800BE5F8;
    case 0x800BE64Cu: goto label_800BE64C;
    case 0x800BE658u: goto label_800BE658;
    case 0x800BE694u: goto label_800BE694;
    case 0x800BE6A0u: goto label_800BE6A0;
    case 0x800BE6B8u: goto label_800BE6B8;
    case 0x800BE750u: goto label_800BE750;
    case 0x800BE7A0u: goto label_800BE7A0;
    case 0x800BE7ECu: goto label_800BE7EC;
    case 0x800BE868u: goto label_800BE868;
    case 0x800BE8C8u: goto label_800BE8C8;
    case 0x800BE8F0u: goto label_800BE8F0;
    case 0x800BE9A0u: goto label_800BE9A0;
    case 0x800BE9C8u: goto label_800BE9C8;
    case 0x800BE9D8u: goto label_800BE9D8;
    case 0x800BE9FCu: goto label_800BE9FC;
    case 0x800BEA1Cu: goto label_800BEA1C;
    case 0x800BEA34u: goto label_800BEA34;
    case 0x800BEA4Cu: goto label_800BEA4C;
    case 0x800BEA54u: goto label_800BEA54;
    case 0x800BEB28u: goto label_800BEB28;
    case 0x800BEBB0u: goto label_800BEBB0;
    case 0x800BEBBCu: goto label_800BEBBC;
    case 0x800BEC00u: goto label_800BEC00;
    case 0x800BEC10u: goto label_800BEC10;
    case 0x800BEC4Cu: goto label_800BEC4C;
    case 0x800BEC5Cu: goto label_800BEC5C;
    case 0x800BECA8u: goto label_800BECA8;
    case 0x800BECBCu: goto label_800BECBC;
    case 0x800BECC4u: goto label_800BECC4;
    case 0x800BED08u: goto label_800BED08;
    case 0x800BED1Cu: goto label_800BED1C;
    case 0x800BED24u: goto label_800BED24;
    case 0x800BED78u: goto label_800BED78;
    case 0x800BEDE8u: goto label_800BEDE8;
    case 0x800BEE58u: goto label_800BEE58;
    case 0x800BEEA0u: goto label_800BEEA0;
    case 0x800BEEE4u: goto label_800BEEE4;
    case 0x800BEEF8u: goto label_800BEEF8;
    case 0x800BEF50u: goto label_800BEF50;
    case 0x800BEF98u: goto label_800BEF98;
    case 0x800BEFDCu: goto label_800BEFDC;
    case 0x800BF070u: goto label_800BF070;
    case 0x800BF080u: goto label_800BF080;
    case 0x800BF090u: goto label_800BF090;
    case 0x800BF0ECu: goto label_800BF0EC;
    case 0x800BF10Cu: goto label_800BF10C;
    case 0x800BF114u: goto label_800BF114;
    case 0x800BF160u: goto label_800BF160;
    case 0x800BF17Cu: goto label_800BF17C;
    case 0x800BF18Cu: goto label_800BF18C;
    case 0x800BF1A0u: goto label_800BF1A0;
    case 0x800BF1A8u: goto label_800BF1A8;
    case 0x800BF1BCu: goto label_800BF1BC;
    case 0x800BF1D8u: goto label_800BF1D8;
    case 0x800BF1E4u: goto label_800BF1E4;
    case 0x800BF1F8u: goto label_800BF1F8;
    case 0x800BF208u: goto label_800BF208;
    case 0x800BF21Cu: goto label_800BF21C;
    case 0x800BF230u: goto label_800BF230;
    case 0x800BF27Cu: goto label_800BF27C;
    case 0x800BF290u: goto label_800BF290;
    case 0x800BF29Cu: goto label_800BF29C;
    default: return;
    }
}

