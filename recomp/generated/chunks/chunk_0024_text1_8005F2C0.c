// DolRecomp output
#include "../generated.h"

static void loop_8005F404(CPUState* ctx) {
label_8005F404:
    ctx->downcount -= 4;
    ctx->pc = 0x8005F404u;
    // 8005F404: lwzu     r0, 20(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(20);
        ctx->gpr[0] = mem_read32(ctx, ea);
        ctx->gpr[3] = ea;
    }

    // 8005F408: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

    // 8005F40C: cmpwi   r0, 0
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

    // 8005F410: bc    4, 2, 0x8005F404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F404u;
                return;
            }
            goto label_8005F404;
        }
    }

    ctx->pc = 0x8005F414u;
}

void func_8005F2C0(CPUState* ctx) {
    switch (ctx->pc) {
    case 0x8005F2C0u: goto label_8005F2C0;
    case 0x8005F2C4u: goto label_8005F2C4;
    case 0x8005F2C8u: goto label_8005F2C8;
    case 0x8005F2CCu: goto label_8005F2CC;
    case 0x8005F2D0u: goto label_8005F2D0;
    case 0x8005F2D4u: goto label_8005F2D4;
    case 0x8005F2D8u: goto label_8005F2D8;
    case 0x8005F2DCu: goto label_8005F2DC;
    case 0x8005F2E0u: goto label_8005F2E0;
    case 0x8005F2E4u: goto label_8005F2E4;
    case 0x8005F2E8u: goto label_8005F2E8;
    case 0x8005F2ECu: goto label_8005F2EC;
    case 0x8005F2F0u: goto label_8005F2F0;
    case 0x8005F2F4u: goto label_8005F2F4;
    case 0x8005F2F8u: goto label_8005F2F8;
    case 0x8005F2FCu: goto label_8005F2FC;
    case 0x8005F300u: goto label_8005F300;
    case 0x8005F304u: goto label_8005F304;
    case 0x8005F308u: goto label_8005F308;
    case 0x8005F30Cu: goto label_8005F30C;
    case 0x8005F310u: goto label_8005F310;
    case 0x8005F314u: goto label_8005F314;
    case 0x8005F318u: goto label_8005F318;
    case 0x8005F31Cu: goto label_8005F31C;
    case 0x8005F320u: goto label_8005F320;
    case 0x8005F324u: goto label_8005F324;
    case 0x8005F328u: goto label_8005F328;
    case 0x8005F32Cu: goto label_8005F32C;
    case 0x8005F330u: goto label_8005F330;
    case 0x8005F334u: goto label_8005F334;
    case 0x8005F338u: goto label_8005F338;
    case 0x8005F33Cu: goto label_8005F33C;
    case 0x8005F340u: goto label_8005F340;
    case 0x8005F344u: goto label_8005F344;
    case 0x8005F348u: goto label_8005F348;
    case 0x8005F34Cu: goto label_8005F34C;
    case 0x8005F350u: goto label_8005F350;
    case 0x8005F354u: goto label_8005F354;
    case 0x8005F358u: goto label_8005F358;
    case 0x8005F35Cu: goto label_8005F35C;
    case 0x8005F360u: goto label_8005F360;
    case 0x8005F364u: goto label_8005F364;
    case 0x8005F368u: goto label_8005F368;
    case 0x8005F36Cu: goto label_8005F36C;
    case 0x8005F370u: goto label_8005F370;
    case 0x8005F374u: goto label_8005F374;
    case 0x8005F378u: goto label_8005F378;
    case 0x8005F37Cu: goto label_8005F37C;
    case 0x8005F380u: goto label_8005F380;
    case 0x8005F384u: goto label_8005F384;
    case 0x8005F388u: goto label_8005F388;
    case 0x8005F38Cu: goto label_8005F38C;
    case 0x8005F390u: goto label_8005F390;
    case 0x8005F394u: goto label_8005F394;
    case 0x8005F398u: goto label_8005F398;
    case 0x8005F39Cu: goto label_8005F39C;
    case 0x8005F3A0u: goto label_8005F3A0;
    case 0x8005F3A4u: goto label_8005F3A4;
    case 0x8005F3A8u: goto label_8005F3A8;
    case 0x8005F3ACu: goto label_8005F3AC;
    case 0x8005F3B0u: goto label_8005F3B0;
    case 0x8005F3B4u: goto label_8005F3B4;
    case 0x8005F3B8u: goto label_8005F3B8;
    case 0x8005F3BCu: goto label_8005F3BC;
    case 0x8005F3C0u: goto label_8005F3C0;
    case 0x8005F3C4u: goto label_8005F3C4;
    case 0x8005F3C8u: goto label_8005F3C8;
    case 0x8005F3CCu: goto label_8005F3CC;
    case 0x8005F3D0u: goto label_8005F3D0;
    case 0x8005F3D4u: goto label_8005F3D4;
    case 0x8005F3D8u: goto label_8005F3D8;
    case 0x8005F3DCu: goto label_8005F3DC;
    case 0x8005F3E0u: goto label_8005F3E0;
    case 0x8005F3E4u: goto label_8005F3E4;
    case 0x8005F3E8u: goto label_8005F3E8;
    case 0x8005F3ECu: goto label_8005F3EC;
    case 0x8005F3F0u: goto label_8005F3F0;
    case 0x8005F3F4u: goto label_8005F3F4;
    case 0x8005F3F8u: goto label_8005F3F8;
    case 0x8005F3FCu: goto label_8005F3FC;
    case 0x8005F400u: goto label_8005F400;
    case 0x8005F404u: goto label_8005F404;
    case 0x8005F408u: goto label_8005F408;
    case 0x8005F40Cu: goto label_8005F40C;
    case 0x8005F410u: goto label_8005F410;
    case 0x8005F414u: goto label_8005F414;
    case 0x8005F418u: goto label_8005F418;
    case 0x8005F41Cu: goto label_8005F41C;
    case 0x8005F420u: goto label_8005F420;
    case 0x8005F424u: goto label_8005F424;
    case 0x8005F428u: goto label_8005F428;
    case 0x8005F42Cu: goto label_8005F42C;
    case 0x8005F430u: goto label_8005F430;
    case 0x8005F434u: goto label_8005F434;
    case 0x8005F438u: goto label_8005F438;
    case 0x8005F43Cu: goto label_8005F43C;
    case 0x8005F440u: goto label_8005F440;
    case 0x8005F444u: goto label_8005F444;
    case 0x8005F448u: goto label_8005F448;
    case 0x8005F44Cu: goto label_8005F44C;
    case 0x8005F450u: goto label_8005F450;
    case 0x8005F454u: goto label_8005F454;
    case 0x8005F458u: goto label_8005F458;
    case 0x8005F45Cu: goto label_8005F45C;
    case 0x8005F460u: goto label_8005F460;
    case 0x8005F464u: goto label_8005F464;
    case 0x8005F468u: goto label_8005F468;
    case 0x8005F46Cu: goto label_8005F46C;
    case 0x8005F470u: goto label_8005F470;
    case 0x8005F474u: goto label_8005F474;
    case 0x8005F478u: goto label_8005F478;
    case 0x8005F47Cu: goto label_8005F47C;
    case 0x8005F480u: goto label_8005F480;
    case 0x8005F484u: goto label_8005F484;
    case 0x8005F488u: goto label_8005F488;
    case 0x8005F48Cu: goto label_8005F48C;
    case 0x8005F490u: goto label_8005F490;
    case 0x8005F494u: goto label_8005F494;
    case 0x8005F498u: goto label_8005F498;
    case 0x8005F49Cu: goto label_8005F49C;
    case 0x8005F4A0u: goto label_8005F4A0;
    case 0x8005F4A4u: goto label_8005F4A4;
    case 0x8005F4A8u: goto label_8005F4A8;
    case 0x8005F4ACu: goto label_8005F4AC;
    case 0x8005F4B0u: goto label_8005F4B0;
    case 0x8005F4B4u: goto label_8005F4B4;
    case 0x8005F4B8u: goto label_8005F4B8;
    case 0x8005F4BCu: goto label_8005F4BC;
    case 0x8005F4C0u: goto label_8005F4C0;
    case 0x8005F4C4u: goto label_8005F4C4;
    case 0x8005F4C8u: goto label_8005F4C8;
    case 0x8005F4CCu: goto label_8005F4CC;
    case 0x8005F4D0u: goto label_8005F4D0;
    case 0x8005F4D4u: goto label_8005F4D4;
    case 0x8005F4D8u: goto label_8005F4D8;
    case 0x8005F4DCu: goto label_8005F4DC;
    case 0x8005F4E0u: goto label_8005F4E0;
    case 0x8005F4E4u: goto label_8005F4E4;
    case 0x8005F4E8u: goto label_8005F4E8;
    case 0x8005F4ECu: goto label_8005F4EC;
    case 0x8005F4F0u: goto label_8005F4F0;
    case 0x8005F4F4u: goto label_8005F4F4;
    case 0x8005F4F8u: goto label_8005F4F8;
    case 0x8005F4FCu: goto label_8005F4FC;
    case 0x8005F500u: goto label_8005F500;
    case 0x8005F504u: goto label_8005F504;
    case 0x8005F508u: goto label_8005F508;
    case 0x8005F50Cu: goto label_8005F50C;
    case 0x8005F510u: goto label_8005F510;
    case 0x8005F514u: goto label_8005F514;
    case 0x8005F518u: goto label_8005F518;
    case 0x8005F51Cu: goto label_8005F51C;
    case 0x8005F520u: goto label_8005F520;
    case 0x8005F524u: goto label_8005F524;
    case 0x8005F528u: goto label_8005F528;
    case 0x8005F52Cu: goto label_8005F52C;
    case 0x8005F530u: goto label_8005F530;
    case 0x8005F534u: goto label_8005F534;
    case 0x8005F538u: goto label_8005F538;
    case 0x8005F53Cu: goto label_8005F53C;
    case 0x8005F540u: goto label_8005F540;
    case 0x8005F544u: goto label_8005F544;
    case 0x8005F548u: goto label_8005F548;
    case 0x8005F54Cu: goto label_8005F54C;
    case 0x8005F550u: goto label_8005F550;
    case 0x8005F554u: goto label_8005F554;
    case 0x8005F558u: goto label_8005F558;
    case 0x8005F55Cu: goto label_8005F55C;
    case 0x8005F560u: goto label_8005F560;
    case 0x8005F564u: goto label_8005F564;
    case 0x8005F568u: goto label_8005F568;
    case 0x8005F56Cu: goto label_8005F56C;
    case 0x8005F570u: goto label_8005F570;
    case 0x8005F574u: goto label_8005F574;
    case 0x8005F578u: goto label_8005F578;
    case 0x8005F57Cu: goto label_8005F57C;
    case 0x8005F580u: goto label_8005F580;
    case 0x8005F584u: goto label_8005F584;
    case 0x8005F588u: goto label_8005F588;
    case 0x8005F58Cu: goto label_8005F58C;
    case 0x8005F590u: goto label_8005F590;
    case 0x8005F594u: goto label_8005F594;
    case 0x8005F598u: goto label_8005F598;
    case 0x8005F59Cu: goto label_8005F59C;
    case 0x8005F5A0u: goto label_8005F5A0;
    case 0x8005F5A4u: goto label_8005F5A4;
    case 0x8005F5A8u: goto label_8005F5A8;
    case 0x8005F5ACu: goto label_8005F5AC;
    case 0x8005F5B0u: goto label_8005F5B0;
    case 0x8005F5B4u: goto label_8005F5B4;
    case 0x8005F5B8u: goto label_8005F5B8;
    case 0x8005F5BCu: goto label_8005F5BC;
    case 0x8005F5C0u: goto label_8005F5C0;
    case 0x8005F5C4u: goto label_8005F5C4;
    case 0x8005F5C8u: goto label_8005F5C8;
    case 0x8005F5CCu: goto label_8005F5CC;
    case 0x8005F5D0u: goto label_8005F5D0;
    case 0x8005F5D4u: goto label_8005F5D4;
    case 0x8005F5D8u: goto label_8005F5D8;
    case 0x8005F5DCu: goto label_8005F5DC;
    case 0x8005F5E0u: goto label_8005F5E0;
    case 0x8005F5E4u: goto label_8005F5E4;
    case 0x8005F5E8u: goto label_8005F5E8;
    case 0x8005F5ECu: goto label_8005F5EC;
    case 0x8005F5F0u: goto label_8005F5F0;
    case 0x8005F5F4u: goto label_8005F5F4;
    case 0x8005F5F8u: goto label_8005F5F8;
    case 0x8005F5FCu: goto label_8005F5FC;
    case 0x8005F600u: goto label_8005F600;
    case 0x8005F604u: goto label_8005F604;
    case 0x8005F608u: goto label_8005F608;
    case 0x8005F60Cu: goto label_8005F60C;
    case 0x8005F610u: goto label_8005F610;
    case 0x8005F614u: goto label_8005F614;
    case 0x8005F618u: goto label_8005F618;
    case 0x8005F61Cu: goto label_8005F61C;
    case 0x8005F620u: goto label_8005F620;
    case 0x8005F624u: goto label_8005F624;
    case 0x8005F628u: goto label_8005F628;
    case 0x8005F62Cu: goto label_8005F62C;
    case 0x8005F630u: goto label_8005F630;
    case 0x8005F634u: goto label_8005F634;
    case 0x8005F638u: goto label_8005F638;
    case 0x8005F63Cu: goto label_8005F63C;
    case 0x8005F640u: goto label_8005F640;
    case 0x8005F644u: goto label_8005F644;
    case 0x8005F648u: goto label_8005F648;
    case 0x8005F64Cu: goto label_8005F64C;
    case 0x8005F650u: goto label_8005F650;
    case 0x8005F654u: goto label_8005F654;
    case 0x8005F658u: goto label_8005F658;
    case 0x8005F65Cu: goto label_8005F65C;
    case 0x8005F660u: goto label_8005F660;
    case 0x8005F664u: goto label_8005F664;
    case 0x8005F668u: goto label_8005F668;
    case 0x8005F66Cu: goto label_8005F66C;
    case 0x8005F670u: goto label_8005F670;
    case 0x8005F674u: goto label_8005F674;
    case 0x8005F678u: goto label_8005F678;
    case 0x8005F67Cu: goto label_8005F67C;
    case 0x8005F680u: goto label_8005F680;
    case 0x8005F684u: goto label_8005F684;
    case 0x8005F688u: goto label_8005F688;
    case 0x8005F68Cu: goto label_8005F68C;
    case 0x8005F690u: goto label_8005F690;
    case 0x8005F694u: goto label_8005F694;
    case 0x8005F698u: goto label_8005F698;
    case 0x8005F69Cu: goto label_8005F69C;
    case 0x8005F6A0u: goto label_8005F6A0;
    case 0x8005F6A4u: goto label_8005F6A4;
    case 0x8005F6A8u: goto label_8005F6A8;
    case 0x8005F6ACu: goto label_8005F6AC;
    case 0x8005F6B0u: goto label_8005F6B0;
    case 0x8005F6B4u: goto label_8005F6B4;
    case 0x8005F6B8u: goto label_8005F6B8;
    case 0x8005F6BCu: goto label_8005F6BC;
    case 0x8005F6C0u: goto label_8005F6C0;
    case 0x8005F6C4u: goto label_8005F6C4;
    case 0x8005F6C8u: goto label_8005F6C8;
    case 0x8005F6CCu: goto label_8005F6CC;
    case 0x8005F6D0u: goto label_8005F6D0;
    case 0x8005F6D4u: goto label_8005F6D4;
    case 0x8005F6D8u: goto label_8005F6D8;
    case 0x8005F6DCu: goto label_8005F6DC;
    case 0x8005F6E0u: goto label_8005F6E0;
    case 0x8005F6E4u: goto label_8005F6E4;
    case 0x8005F6E8u: goto label_8005F6E8;
    case 0x8005F6ECu: goto label_8005F6EC;
    case 0x8005F6F0u: goto label_8005F6F0;
    case 0x8005F6F4u: goto label_8005F6F4;
    case 0x8005F6F8u: goto label_8005F6F8;
    case 0x8005F6FCu: goto label_8005F6FC;
    case 0x8005F700u: goto label_8005F700;
    case 0x8005F704u: goto label_8005F704;
    case 0x8005F708u: goto label_8005F708;
    case 0x8005F70Cu: goto label_8005F70C;
    case 0x8005F710u: goto label_8005F710;
    case 0x8005F714u: goto label_8005F714;
    case 0x8005F718u: goto label_8005F718;
    case 0x8005F71Cu: goto label_8005F71C;
    case 0x8005F720u: goto label_8005F720;
    case 0x8005F724u: goto label_8005F724;
    case 0x8005F728u: goto label_8005F728;
    case 0x8005F72Cu: goto label_8005F72C;
    case 0x8005F730u: goto label_8005F730;
    case 0x8005F734u: goto label_8005F734;
    case 0x8005F738u: goto label_8005F738;
    case 0x8005F73Cu: goto label_8005F73C;
    case 0x8005F740u: goto label_8005F740;
    case 0x8005F744u: goto label_8005F744;
    case 0x8005F748u: goto label_8005F748;
    case 0x8005F74Cu: goto label_8005F74C;
    case 0x8005F750u: goto label_8005F750;
    case 0x8005F754u: goto label_8005F754;
    case 0x8005F758u: goto label_8005F758;
    case 0x8005F75Cu: goto label_8005F75C;
    case 0x8005F760u: goto label_8005F760;
    case 0x8005F764u: goto label_8005F764;
    case 0x8005F768u: goto label_8005F768;
    case 0x8005F76Cu: goto label_8005F76C;
    case 0x8005F770u: goto label_8005F770;
    case 0x8005F774u: goto label_8005F774;
    case 0x8005F778u: goto label_8005F778;
    case 0x8005F77Cu: goto label_8005F77C;
    case 0x8005F780u: goto label_8005F780;
    case 0x8005F784u: goto label_8005F784;
    case 0x8005F788u: goto label_8005F788;
    case 0x8005F78Cu: goto label_8005F78C;
    case 0x8005F790u: goto label_8005F790;
    case 0x8005F794u: goto label_8005F794;
    case 0x8005F798u: goto label_8005F798;
    case 0x8005F79Cu: goto label_8005F79C;
    case 0x8005F7A0u: goto label_8005F7A0;
    case 0x8005F7A4u: goto label_8005F7A4;
    case 0x8005F7A8u: goto label_8005F7A8;
    case 0x8005F7ACu: goto label_8005F7AC;
    case 0x8005F7B0u: goto label_8005F7B0;
    case 0x8005F7B4u: goto label_8005F7B4;
    case 0x8005F7B8u: goto label_8005F7B8;
    case 0x8005F7BCu: goto label_8005F7BC;
    case 0x8005F7C0u: goto label_8005F7C0;
    case 0x8005F7C4u: goto label_8005F7C4;
    case 0x8005F7C8u: goto label_8005F7C8;
    case 0x8005F7CCu: goto label_8005F7CC;
    case 0x8005F7D0u: goto label_8005F7D0;
    case 0x8005F7D4u: goto label_8005F7D4;
    case 0x8005F7D8u: goto label_8005F7D8;
    case 0x8005F7DCu: goto label_8005F7DC;
    case 0x8005F7E0u: goto label_8005F7E0;
    case 0x8005F7E4u: goto label_8005F7E4;
    case 0x8005F7E8u: goto label_8005F7E8;
    case 0x8005F7ECu: goto label_8005F7EC;
    case 0x8005F7F0u: goto label_8005F7F0;
    case 0x8005F7F4u: goto label_8005F7F4;
    case 0x8005F7F8u: goto label_8005F7F8;
    case 0x8005F7FCu: goto label_8005F7FC;
    case 0x8005F800u: goto label_8005F800;
    case 0x8005F804u: goto label_8005F804;
    case 0x8005F808u: goto label_8005F808;
    case 0x8005F80Cu: goto label_8005F80C;
    case 0x8005F810u: goto label_8005F810;
    case 0x8005F814u: goto label_8005F814;
    case 0x8005F818u: goto label_8005F818;
    case 0x8005F81Cu: goto label_8005F81C;
    case 0x8005F820u: goto label_8005F820;
    case 0x8005F824u: goto label_8005F824;
    case 0x8005F828u: goto label_8005F828;
    case 0x8005F82Cu: goto label_8005F82C;
    case 0x8005F830u: goto label_8005F830;
    case 0x8005F834u: goto label_8005F834;
    case 0x8005F838u: goto label_8005F838;
    case 0x8005F83Cu: goto label_8005F83C;
    case 0x8005F840u: goto label_8005F840;
    case 0x8005F844u: goto label_8005F844;
    case 0x8005F848u: goto label_8005F848;
    case 0x8005F84Cu: goto label_8005F84C;
    case 0x8005F850u: goto label_8005F850;
    case 0x8005F854u: goto label_8005F854;
    case 0x8005F858u: goto label_8005F858;
    case 0x8005F85Cu: goto label_8005F85C;
    case 0x8005F860u: goto label_8005F860;
    case 0x8005F864u: goto label_8005F864;
    case 0x8005F868u: goto label_8005F868;
    case 0x8005F86Cu: goto label_8005F86C;
    case 0x8005F870u: goto label_8005F870;
    case 0x8005F874u: goto label_8005F874;
    case 0x8005F878u: goto label_8005F878;
    case 0x8005F87Cu: goto label_8005F87C;
    case 0x8005F880u: goto label_8005F880;
    case 0x8005F884u: goto label_8005F884;
    case 0x8005F888u: goto label_8005F888;
    case 0x8005F88Cu: goto label_8005F88C;
    case 0x8005F890u: goto label_8005F890;
    case 0x8005F894u: goto label_8005F894;
    case 0x8005F898u: goto label_8005F898;
    case 0x8005F89Cu: goto label_8005F89C;
    case 0x8005F8A0u: goto label_8005F8A0;
    case 0x8005F8A4u: goto label_8005F8A4;
    case 0x8005F8A8u: goto label_8005F8A8;
    case 0x8005F8ACu: goto label_8005F8AC;
    case 0x8005F8B0u: goto label_8005F8B0;
    case 0x8005F8B4u: goto label_8005F8B4;
    case 0x8005F8B8u: goto label_8005F8B8;
    case 0x8005F8BCu: goto label_8005F8BC;
    case 0x8005F8C0u: goto label_8005F8C0;
    case 0x8005F8C4u: goto label_8005F8C4;
    case 0x8005F8C8u: goto label_8005F8C8;
    case 0x8005F8CCu: goto label_8005F8CC;
    case 0x8005F8D0u: goto label_8005F8D0;
    case 0x8005F8D4u: goto label_8005F8D4;
    case 0x8005F8D8u: goto label_8005F8D8;
    case 0x8005F8DCu: goto label_8005F8DC;
    case 0x8005F8E0u: goto label_8005F8E0;
    case 0x8005F8E4u: goto label_8005F8E4;
    case 0x8005F8E8u: goto label_8005F8E8;
    case 0x8005F8ECu: goto label_8005F8EC;
    case 0x8005F8F0u: goto label_8005F8F0;
    case 0x8005F8F4u: goto label_8005F8F4;
    case 0x8005F8F8u: goto label_8005F8F8;
    case 0x8005F8FCu: goto label_8005F8FC;
    case 0x8005F900u: goto label_8005F900;
    case 0x8005F904u: goto label_8005F904;
    case 0x8005F908u: goto label_8005F908;
    case 0x8005F90Cu: goto label_8005F90C;
    case 0x8005F910u: goto label_8005F910;
    case 0x8005F914u: goto label_8005F914;
    case 0x8005F918u: goto label_8005F918;
    case 0x8005F91Cu: goto label_8005F91C;
    case 0x8005F920u: goto label_8005F920;
    case 0x8005F924u: goto label_8005F924;
    case 0x8005F928u: goto label_8005F928;
    case 0x8005F92Cu: goto label_8005F92C;
    case 0x8005F930u: goto label_8005F930;
    case 0x8005F934u: goto label_8005F934;
    case 0x8005F938u: goto label_8005F938;
    case 0x8005F93Cu: goto label_8005F93C;
    case 0x8005F940u: goto label_8005F940;
    case 0x8005F944u: goto label_8005F944;
    case 0x8005F948u: goto label_8005F948;
    case 0x8005F94Cu: goto label_8005F94C;
    case 0x8005F950u: goto label_8005F950;
    case 0x8005F954u: goto label_8005F954;
    case 0x8005F958u: goto label_8005F958;
    case 0x8005F95Cu: goto label_8005F95C;
    case 0x8005F960u: goto label_8005F960;
    case 0x8005F964u: goto label_8005F964;
    case 0x8005F968u: goto label_8005F968;
    case 0x8005F96Cu: goto label_8005F96C;
    case 0x8005F970u: goto label_8005F970;
    case 0x8005F974u: goto label_8005F974;
    case 0x8005F978u: goto label_8005F978;
    case 0x8005F97Cu: goto label_8005F97C;
    case 0x8005F980u: goto label_8005F980;
    case 0x8005F984u: goto label_8005F984;
    case 0x8005F988u: goto label_8005F988;
    case 0x8005F98Cu: goto label_8005F98C;
    case 0x8005F990u: goto label_8005F990;
    case 0x8005F994u: goto label_8005F994;
    case 0x8005F998u: goto label_8005F998;
    case 0x8005F99Cu: goto label_8005F99C;
    case 0x8005F9A0u: goto label_8005F9A0;
    case 0x8005F9A4u: goto label_8005F9A4;
    case 0x8005F9A8u: goto label_8005F9A8;
    case 0x8005F9ACu: goto label_8005F9AC;
    case 0x8005F9B0u: goto label_8005F9B0;
    case 0x8005F9B4u: goto label_8005F9B4;
    case 0x8005F9B8u: goto label_8005F9B8;
    case 0x8005F9BCu: goto label_8005F9BC;
    case 0x8005F9C0u: goto label_8005F9C0;
    case 0x8005F9C4u: goto label_8005F9C4;
    case 0x8005F9C8u: goto label_8005F9C8;
    case 0x8005F9CCu: goto label_8005F9CC;
    case 0x8005F9D0u: goto label_8005F9D0;
    case 0x8005F9D4u: goto label_8005F9D4;
    case 0x8005F9D8u: goto label_8005F9D8;
    case 0x8005F9DCu: goto label_8005F9DC;
    case 0x8005F9E0u: goto label_8005F9E0;
    case 0x8005F9E4u: goto label_8005F9E4;
    case 0x8005F9E8u: goto label_8005F9E8;
    case 0x8005F9ECu: goto label_8005F9EC;
    case 0x8005F9F0u: goto label_8005F9F0;
    case 0x8005F9F4u: goto label_8005F9F4;
    case 0x8005F9F8u: goto label_8005F9F8;
    case 0x8005F9FCu: goto label_8005F9FC;
    case 0x8005FA00u: goto label_8005FA00;
    case 0x8005FA04u: goto label_8005FA04;
    case 0x8005FA08u: goto label_8005FA08;
    case 0x8005FA0Cu: goto label_8005FA0C;
    case 0x8005FA10u: goto label_8005FA10;
    case 0x8005FA14u: goto label_8005FA14;
    case 0x8005FA18u: goto label_8005FA18;
    case 0x8005FA1Cu: goto label_8005FA1C;
    case 0x8005FA20u: goto label_8005FA20;
    case 0x8005FA24u: goto label_8005FA24;
    case 0x8005FA28u: goto label_8005FA28;
    case 0x8005FA2Cu: goto label_8005FA2C;
    case 0x8005FA30u: goto label_8005FA30;
    case 0x8005FA34u: goto label_8005FA34;
    case 0x8005FA38u: goto label_8005FA38;
    case 0x8005FA3Cu: goto label_8005FA3C;
    case 0x8005FA40u: goto label_8005FA40;
    case 0x8005FA44u: goto label_8005FA44;
    case 0x8005FA48u: goto label_8005FA48;
    case 0x8005FA4Cu: goto label_8005FA4C;
    case 0x8005FA50u: goto label_8005FA50;
    case 0x8005FA54u: goto label_8005FA54;
    case 0x8005FA58u: goto label_8005FA58;
    case 0x8005FA5Cu: goto label_8005FA5C;
    case 0x8005FA60u: goto label_8005FA60;
    case 0x8005FA64u: goto label_8005FA64;
    case 0x8005FA68u: goto label_8005FA68;
    case 0x8005FA6Cu: goto label_8005FA6C;
    case 0x8005FA70u: goto label_8005FA70;
    case 0x8005FA74u: goto label_8005FA74;
    case 0x8005FA78u: goto label_8005FA78;
    case 0x8005FA7Cu: goto label_8005FA7C;
    case 0x8005FA80u: goto label_8005FA80;
    case 0x8005FA84u: goto label_8005FA84;
    case 0x8005FA88u: goto label_8005FA88;
    case 0x8005FA8Cu: goto label_8005FA8C;
    case 0x8005FA90u: goto label_8005FA90;
    case 0x8005FA94u: goto label_8005FA94;
    case 0x8005FA98u: goto label_8005FA98;
    case 0x8005FA9Cu: goto label_8005FA9C;
    case 0x8005FAA0u: goto label_8005FAA0;
    case 0x8005FAA4u: goto label_8005FAA4;
    case 0x8005FAA8u: goto label_8005FAA8;
    case 0x8005FAACu: goto label_8005FAAC;
    case 0x8005FAB0u: goto label_8005FAB0;
    case 0x8005FAB4u: goto label_8005FAB4;
    case 0x8005FAB8u: goto label_8005FAB8;
    case 0x8005FABCu: goto label_8005FABC;
    case 0x8005FAC0u: goto label_8005FAC0;
    case 0x8005FAC4u: goto label_8005FAC4;
    case 0x8005FAC8u: goto label_8005FAC8;
    case 0x8005FACCu: goto label_8005FACC;
    case 0x8005FAD0u: goto label_8005FAD0;
    case 0x8005FAD4u: goto label_8005FAD4;
    case 0x8005FAD8u: goto label_8005FAD8;
    case 0x8005FADCu: goto label_8005FADC;
    case 0x8005FAE0u: goto label_8005FAE0;
    case 0x8005FAE4u: goto label_8005FAE4;
    case 0x8005FAE8u: goto label_8005FAE8;
    case 0x8005FAECu: goto label_8005FAEC;
    case 0x8005FAF0u: goto label_8005FAF0;
    case 0x8005FAF4u: goto label_8005FAF4;
    case 0x8005FAF8u: goto label_8005FAF8;
    case 0x8005FAFCu: goto label_8005FAFC;
    case 0x8005FB00u: goto label_8005FB00;
    case 0x8005FB04u: goto label_8005FB04;
    case 0x8005FB08u: goto label_8005FB08;
    case 0x8005FB0Cu: goto label_8005FB0C;
    case 0x8005FB10u: goto label_8005FB10;
    case 0x8005FB14u: goto label_8005FB14;
    case 0x8005FB18u: goto label_8005FB18;
    case 0x8005FB1Cu: goto label_8005FB1C;
    case 0x8005FB20u: goto label_8005FB20;
    case 0x8005FB24u: goto label_8005FB24;
    case 0x8005FB28u: goto label_8005FB28;
    case 0x8005FB2Cu: goto label_8005FB2C;
    case 0x8005FB30u: goto label_8005FB30;
    case 0x8005FB34u: goto label_8005FB34;
    case 0x8005FB38u: goto label_8005FB38;
    case 0x8005FB3Cu: goto label_8005FB3C;
    case 0x8005FB40u: goto label_8005FB40;
    case 0x8005FB44u: goto label_8005FB44;
    case 0x8005FB48u: goto label_8005FB48;
    case 0x8005FB4Cu: goto label_8005FB4C;
    case 0x8005FB50u: goto label_8005FB50;
    case 0x8005FB54u: goto label_8005FB54;
    case 0x8005FB58u: goto label_8005FB58;
    case 0x8005FB5Cu: goto label_8005FB5C;
    case 0x8005FB60u: goto label_8005FB60;
    case 0x8005FB64u: goto label_8005FB64;
    case 0x8005FB68u: goto label_8005FB68;
    case 0x8005FB6Cu: goto label_8005FB6C;
    case 0x8005FB70u: goto label_8005FB70;
    case 0x8005FB74u: goto label_8005FB74;
    case 0x8005FB78u: goto label_8005FB78;
    case 0x8005FB7Cu: goto label_8005FB7C;
    case 0x8005FB80u: goto label_8005FB80;
    case 0x8005FB84u: goto label_8005FB84;
    case 0x8005FB88u: goto label_8005FB88;
    case 0x8005FB8Cu: goto label_8005FB8C;
    case 0x8005FB90u: goto label_8005FB90;
    case 0x8005FB94u: goto label_8005FB94;
    case 0x8005FB98u: goto label_8005FB98;
    case 0x8005FB9Cu: goto label_8005FB9C;
    case 0x8005FBA0u: goto label_8005FBA0;
    case 0x8005FBA4u: goto label_8005FBA4;
    case 0x8005FBA8u: goto label_8005FBA8;
    case 0x8005FBACu: goto label_8005FBAC;
    case 0x8005FBB0u: goto label_8005FBB0;
    case 0x8005FBB4u: goto label_8005FBB4;
    case 0x8005FBB8u: goto label_8005FBB8;
    case 0x8005FBBCu: goto label_8005FBBC;
    case 0x8005FBC0u: goto label_8005FBC0;
    case 0x8005FBC4u: goto label_8005FBC4;
    case 0x8005FBC8u: goto label_8005FBC8;
    case 0x8005FBCCu: goto label_8005FBCC;
    case 0x8005FBD0u: goto label_8005FBD0;
    case 0x8005FBD4u: goto label_8005FBD4;
    case 0x8005FBD8u: goto label_8005FBD8;
    case 0x8005FBDCu: goto label_8005FBDC;
    case 0x8005FBE0u: goto label_8005FBE0;
    case 0x8005FBE4u: goto label_8005FBE4;
    case 0x8005FBE8u: goto label_8005FBE8;
    case 0x8005FBECu: goto label_8005FBEC;
    case 0x8005FBF0u: goto label_8005FBF0;
    case 0x8005FBF4u: goto label_8005FBF4;
    case 0x8005FBF8u: goto label_8005FBF8;
    case 0x8005FBFCu: goto label_8005FBFC;
    case 0x8005FC00u: goto label_8005FC00;
    case 0x8005FC04u: goto label_8005FC04;
    case 0x8005FC08u: goto label_8005FC08;
    case 0x8005FC0Cu: goto label_8005FC0C;
    case 0x8005FC10u: goto label_8005FC10;
    case 0x8005FC14u: goto label_8005FC14;
    case 0x8005FC18u: goto label_8005FC18;
    case 0x8005FC1Cu: goto label_8005FC1C;
    case 0x8005FC20u: goto label_8005FC20;
    case 0x8005FC24u: goto label_8005FC24;
    case 0x8005FC28u: goto label_8005FC28;
    case 0x8005FC2Cu: goto label_8005FC2C;
    case 0x8005FC30u: goto label_8005FC30;
    case 0x8005FC34u: goto label_8005FC34;
    case 0x8005FC38u: goto label_8005FC38;
    case 0x8005FC3Cu: goto label_8005FC3C;
    case 0x8005FC40u: goto label_8005FC40;
    case 0x8005FC44u: goto label_8005FC44;
    case 0x8005FC48u: goto label_8005FC48;
    case 0x8005FC4Cu: goto label_8005FC4C;
    case 0x8005FC50u: goto label_8005FC50;
    case 0x8005FC54u: goto label_8005FC54;
    case 0x8005FC58u: goto label_8005FC58;
    case 0x8005FC5Cu: goto label_8005FC5C;
    case 0x8005FC60u: goto label_8005FC60;
    case 0x8005FC64u: goto label_8005FC64;
    case 0x8005FC68u: goto label_8005FC68;
    case 0x8005FC6Cu: goto label_8005FC6C;
    case 0x8005FC70u: goto label_8005FC70;
    case 0x8005FC74u: goto label_8005FC74;
    case 0x8005FC78u: goto label_8005FC78;
    case 0x8005FC7Cu: goto label_8005FC7C;
    case 0x8005FC80u: goto label_8005FC80;
    case 0x8005FC84u: goto label_8005FC84;
    case 0x8005FC88u: goto label_8005FC88;
    case 0x8005FC8Cu: goto label_8005FC8C;
    case 0x8005FC90u: goto label_8005FC90;
    case 0x8005FC94u: goto label_8005FC94;
    case 0x8005FC98u: goto label_8005FC98;
    case 0x8005FC9Cu: goto label_8005FC9C;
    case 0x8005FCA0u: goto label_8005FCA0;
    case 0x8005FCA4u: goto label_8005FCA4;
    case 0x8005FCA8u: goto label_8005FCA8;
    case 0x8005FCACu: goto label_8005FCAC;
    case 0x8005FCB0u: goto label_8005FCB0;
    case 0x8005FCB4u: goto label_8005FCB4;
    case 0x8005FCB8u: goto label_8005FCB8;
    case 0x8005FCBCu: goto label_8005FCBC;
    case 0x8005FCC0u: goto label_8005FCC0;
    case 0x8005FCC4u: goto label_8005FCC4;
    case 0x8005FCC8u: goto label_8005FCC8;
    case 0x8005FCCCu: goto label_8005FCCC;
    case 0x8005FCD0u: goto label_8005FCD0;
    case 0x8005FCD4u: goto label_8005FCD4;
    case 0x8005FCD8u: goto label_8005FCD8;
    case 0x8005FCDCu: goto label_8005FCDC;
    case 0x8005FCE0u: goto label_8005FCE0;
    case 0x8005FCE4u: goto label_8005FCE4;
    case 0x8005FCE8u: goto label_8005FCE8;
    case 0x8005FCECu: goto label_8005FCEC;
    case 0x8005FCF0u: goto label_8005FCF0;
    case 0x8005FCF4u: goto label_8005FCF4;
    case 0x8005FCF8u: goto label_8005FCF8;
    case 0x8005FCFCu: goto label_8005FCFC;
    case 0x8005FD00u: goto label_8005FD00;
    case 0x8005FD04u: goto label_8005FD04;
    case 0x8005FD08u: goto label_8005FD08;
    case 0x8005FD0Cu: goto label_8005FD0C;
    case 0x8005FD10u: goto label_8005FD10;
    case 0x8005FD14u: goto label_8005FD14;
    case 0x8005FD18u: goto label_8005FD18;
    case 0x8005FD1Cu: goto label_8005FD1C;
    case 0x8005FD20u: goto label_8005FD20;
    case 0x8005FD24u: goto label_8005FD24;
    case 0x8005FD28u: goto label_8005FD28;
    case 0x8005FD2Cu: goto label_8005FD2C;
    case 0x8005FD30u: goto label_8005FD30;
    case 0x8005FD34u: goto label_8005FD34;
    case 0x8005FD38u: goto label_8005FD38;
    case 0x8005FD3Cu: goto label_8005FD3C;
    case 0x8005FD40u: goto label_8005FD40;
    case 0x8005FD44u: goto label_8005FD44;
    case 0x8005FD48u: goto label_8005FD48;
    case 0x8005FD4Cu: goto label_8005FD4C;
    case 0x8005FD50u: goto label_8005FD50;
    case 0x8005FD54u: goto label_8005FD54;
    case 0x8005FD58u: goto label_8005FD58;
    case 0x8005FD5Cu: goto label_8005FD5C;
    case 0x8005FD60u: goto label_8005FD60;
    case 0x8005FD64u: goto label_8005FD64;
    case 0x8005FD68u: goto label_8005FD68;
    case 0x8005FD6Cu: goto label_8005FD6C;
    case 0x8005FD70u: goto label_8005FD70;
    case 0x8005FD74u: goto label_8005FD74;
    case 0x8005FD78u: goto label_8005FD78;
    case 0x8005FD7Cu: goto label_8005FD7C;
    case 0x8005FD80u: goto label_8005FD80;
    case 0x8005FD84u: goto label_8005FD84;
    case 0x8005FD88u: goto label_8005FD88;
    case 0x8005FD8Cu: goto label_8005FD8C;
    case 0x8005FD90u: goto label_8005FD90;
    case 0x8005FD94u: goto label_8005FD94;
    case 0x8005FD98u: goto label_8005FD98;
    case 0x8005FD9Cu: goto label_8005FD9C;
    case 0x8005FDA0u: goto label_8005FDA0;
    case 0x8005FDA4u: goto label_8005FDA4;
    case 0x8005FDA8u: goto label_8005FDA8;
    case 0x8005FDACu: goto label_8005FDAC;
    case 0x8005FDB0u: goto label_8005FDB0;
    case 0x8005FDB4u: goto label_8005FDB4;
    case 0x8005FDB8u: goto label_8005FDB8;
    case 0x8005FDBCu: goto label_8005FDBC;
    case 0x8005FDC0u: goto label_8005FDC0;
    case 0x8005FDC4u: goto label_8005FDC4;
    case 0x8005FDC8u: goto label_8005FDC8;
    case 0x8005FDCCu: goto label_8005FDCC;
    case 0x8005FDD0u: goto label_8005FDD0;
    case 0x8005FDD4u: goto label_8005FDD4;
    case 0x8005FDD8u: goto label_8005FDD8;
    case 0x8005FDDCu: goto label_8005FDDC;
    case 0x8005FDE0u: goto label_8005FDE0;
    case 0x8005FDE4u: goto label_8005FDE4;
    case 0x8005FDE8u: goto label_8005FDE8;
    case 0x8005FDECu: goto label_8005FDEC;
    case 0x8005FDF0u: goto label_8005FDF0;
    case 0x8005FDF4u: goto label_8005FDF4;
    case 0x8005FDF8u: goto label_8005FDF8;
    case 0x8005FDFCu: goto label_8005FDFC;
    case 0x8005FE00u: goto label_8005FE00;
    case 0x8005FE04u: goto label_8005FE04;
    case 0x8005FE08u: goto label_8005FE08;
    case 0x8005FE0Cu: goto label_8005FE0C;
    case 0x8005FE10u: goto label_8005FE10;
    case 0x8005FE14u: goto label_8005FE14;
    case 0x8005FE18u: goto label_8005FE18;
    case 0x8005FE1Cu: goto label_8005FE1C;
    case 0x8005FE20u: goto label_8005FE20;
    case 0x8005FE24u: goto label_8005FE24;
    case 0x8005FE28u: goto label_8005FE28;
    case 0x8005FE2Cu: goto label_8005FE2C;
    case 0x8005FE30u: goto label_8005FE30;
    case 0x8005FE34u: goto label_8005FE34;
    case 0x8005FE38u: goto label_8005FE38;
    case 0x8005FE3Cu: goto label_8005FE3C;
    case 0x8005FE40u: goto label_8005FE40;
    case 0x8005FE44u: goto label_8005FE44;
    case 0x8005FE48u: goto label_8005FE48;
    case 0x8005FE4Cu: goto label_8005FE4C;
    case 0x8005FE50u: goto label_8005FE50;
    case 0x8005FE54u: goto label_8005FE54;
    case 0x8005FE58u: goto label_8005FE58;
    case 0x8005FE5Cu: goto label_8005FE5C;
    case 0x8005FE60u: goto label_8005FE60;
    case 0x8005FE64u: goto label_8005FE64;
    case 0x8005FE68u: goto label_8005FE68;
    case 0x8005FE6Cu: goto label_8005FE6C;
    case 0x8005FE70u: goto label_8005FE70;
    case 0x8005FE74u: goto label_8005FE74;
    case 0x8005FE78u: goto label_8005FE78;
    case 0x8005FE7Cu: goto label_8005FE7C;
    case 0x8005FE80u: goto label_8005FE80;
    case 0x8005FE84u: goto label_8005FE84;
    case 0x8005FE88u: goto label_8005FE88;
    case 0x8005FE8Cu: goto label_8005FE8C;
    case 0x8005FE90u: goto label_8005FE90;
    case 0x8005FE94u: goto label_8005FE94;
    case 0x8005FE98u: goto label_8005FE98;
    case 0x8005FE9Cu: goto label_8005FE9C;
    case 0x8005FEA0u: goto label_8005FEA0;
    case 0x8005FEA4u: goto label_8005FEA4;
    case 0x8005FEA8u: goto label_8005FEA8;
    case 0x8005FEACu: goto label_8005FEAC;
    case 0x8005FEB0u: goto label_8005FEB0;
    case 0x8005FEB4u: goto label_8005FEB4;
    case 0x8005FEB8u: goto label_8005FEB8;
    case 0x8005FEBCu: goto label_8005FEBC;
    case 0x8005FEC0u: goto label_8005FEC0;
    case 0x8005FEC4u: goto label_8005FEC4;
    case 0x8005FEC8u: goto label_8005FEC8;
    case 0x8005FECCu: goto label_8005FECC;
    case 0x8005FED0u: goto label_8005FED0;
    case 0x8005FED4u: goto label_8005FED4;
    case 0x8005FED8u: goto label_8005FED8;
    case 0x8005FEDCu: goto label_8005FEDC;
    case 0x8005FEE0u: goto label_8005FEE0;
    case 0x8005FEE4u: goto label_8005FEE4;
    case 0x8005FEE8u: goto label_8005FEE8;
    case 0x8005FEECu: goto label_8005FEEC;
    case 0x8005FEF0u: goto label_8005FEF0;
    case 0x8005FEF4u: goto label_8005FEF4;
    case 0x8005FEF8u: goto label_8005FEF8;
    case 0x8005FEFCu: goto label_8005FEFC;
    case 0x8005FF00u: goto label_8005FF00;
    case 0x8005FF04u: goto label_8005FF04;
    case 0x8005FF08u: goto label_8005FF08;
    case 0x8005FF0Cu: goto label_8005FF0C;
    case 0x8005FF10u: goto label_8005FF10;
    case 0x8005FF14u: goto label_8005FF14;
    case 0x8005FF18u: goto label_8005FF18;
    case 0x8005FF1Cu: goto label_8005FF1C;
    case 0x8005FF20u: goto label_8005FF20;
    case 0x8005FF24u: goto label_8005FF24;
    case 0x8005FF28u: goto label_8005FF28;
    case 0x8005FF2Cu: goto label_8005FF2C;
    case 0x8005FF30u: goto label_8005FF30;
    case 0x8005FF34u: goto label_8005FF34;
    case 0x8005FF38u: goto label_8005FF38;
    case 0x8005FF3Cu: goto label_8005FF3C;
    case 0x8005FF40u: goto label_8005FF40;
    case 0x8005FF44u: goto label_8005FF44;
    case 0x8005FF48u: goto label_8005FF48;
    case 0x8005FF4Cu: goto label_8005FF4C;
    case 0x8005FF50u: goto label_8005FF50;
    case 0x8005FF54u: goto label_8005FF54;
    case 0x8005FF58u: goto label_8005FF58;
    case 0x8005FF5Cu: goto label_8005FF5C;
    case 0x8005FF60u: goto label_8005FF60;
    case 0x8005FF64u: goto label_8005FF64;
    case 0x8005FF68u: goto label_8005FF68;
    case 0x8005FF6Cu: goto label_8005FF6C;
    case 0x8005FF70u: goto label_8005FF70;
    case 0x8005FF74u: goto label_8005FF74;
    case 0x8005FF78u: goto label_8005FF78;
    case 0x8005FF7Cu: goto label_8005FF7C;
    case 0x8005FF80u: goto label_8005FF80;
    case 0x8005FF84u: goto label_8005FF84;
    case 0x8005FF88u: goto label_8005FF88;
    case 0x8005FF8Cu: goto label_8005FF8C;
    case 0x8005FF90u: goto label_8005FF90;
    case 0x8005FF94u: goto label_8005FF94;
    case 0x8005FF98u: goto label_8005FF98;
    case 0x8005FF9Cu: goto label_8005FF9C;
    case 0x8005FFA0u: goto label_8005FFA0;
    case 0x8005FFA4u: goto label_8005FFA4;
    case 0x8005FFA8u: goto label_8005FFA8;
    case 0x8005FFACu: goto label_8005FFAC;
    case 0x8005FFB0u: goto label_8005FFB0;
    case 0x8005FFB4u: goto label_8005FFB4;
    case 0x8005FFB8u: goto label_8005FFB8;
    case 0x8005FFBCu: goto label_8005FFBC;
    case 0x8005FFC0u: goto label_8005FFC0;
    case 0x8005FFC4u: goto label_8005FFC4;
    case 0x8005FFC8u: goto label_8005FFC8;
    case 0x8005FFCCu: goto label_8005FFCC;
    case 0x8005FFD0u: goto label_8005FFD0;
    case 0x8005FFD4u: goto label_8005FFD4;
    case 0x8005FFD8u: goto label_8005FFD8;
    case 0x8005FFDCu: goto label_8005FFDC;
    case 0x8005FFE0u: goto label_8005FFE0;
    case 0x8005FFE4u: goto label_8005FFE4;
    case 0x8005FFE8u: goto label_8005FFE8;
    case 0x8005FFECu: goto label_8005FFEC;
    case 0x8005FFF0u: goto label_8005FFF0;
    case 0x8005FFF4u: goto label_8005FFF4;
    case 0x8005FFF8u: goto label_8005FFF8;
    case 0x8005FFFCu: goto label_8005FFFC;
    case 0x80060000u: goto label_80060000;
    case 0x80060004u: goto label_80060004;
    case 0x80060008u: goto label_80060008;
    case 0x8006000Cu: goto label_8006000C;
    case 0x80060010u: goto label_80060010;
    case 0x80060014u: goto label_80060014;
    case 0x80060018u: goto label_80060018;
    case 0x8006001Cu: goto label_8006001C;
    case 0x80060020u: goto label_80060020;
    case 0x80060024u: goto label_80060024;
    case 0x80060028u: goto label_80060028;
    case 0x8006002Cu: goto label_8006002C;
    case 0x80060030u: goto label_80060030;
    case 0x80060034u: goto label_80060034;
    case 0x80060038u: goto label_80060038;
    case 0x8006003Cu: goto label_8006003C;
    case 0x80060040u: goto label_80060040;
    case 0x80060044u: goto label_80060044;
    case 0x80060048u: goto label_80060048;
    case 0x8006004Cu: goto label_8006004C;
    case 0x80060050u: goto label_80060050;
    case 0x80060054u: goto label_80060054;
    case 0x80060058u: goto label_80060058;
    case 0x8006005Cu: goto label_8006005C;
    case 0x80060060u: goto label_80060060;
    case 0x80060064u: goto label_80060064;
    case 0x80060068u: goto label_80060068;
    case 0x8006006Cu: goto label_8006006C;
    case 0x80060070u: goto label_80060070;
    case 0x80060074u: goto label_80060074;
    case 0x80060078u: goto label_80060078;
    case 0x8006007Cu: goto label_8006007C;
    case 0x80060080u: goto label_80060080;
    case 0x80060084u: goto label_80060084;
    case 0x80060088u: goto label_80060088;
    case 0x8006008Cu: goto label_8006008C;
    case 0x80060090u: goto label_80060090;
    case 0x80060094u: goto label_80060094;
    case 0x80060098u: goto label_80060098;
    case 0x8006009Cu: goto label_8006009C;
    case 0x800600A0u: goto label_800600A0;
    case 0x800600A4u: goto label_800600A4;
    case 0x800600A8u: goto label_800600A8;
    case 0x800600ACu: goto label_800600AC;
    case 0x800600B0u: goto label_800600B0;
    case 0x800600B4u: goto label_800600B4;
    case 0x800600B8u: goto label_800600B8;
    case 0x800600BCu: goto label_800600BC;
    case 0x800600C0u: goto label_800600C0;
    case 0x800600C4u: goto label_800600C4;
    case 0x800600C8u: goto label_800600C8;
    case 0x800600CCu: goto label_800600CC;
    case 0x800600D0u: goto label_800600D0;
    case 0x800600D4u: goto label_800600D4;
    case 0x800600D8u: goto label_800600D8;
    case 0x800600DCu: goto label_800600DC;
    case 0x800600E0u: goto label_800600E0;
    case 0x800600E4u: goto label_800600E4;
    case 0x800600E8u: goto label_800600E8;
    case 0x800600ECu: goto label_800600EC;
    case 0x800600F0u: goto label_800600F0;
    case 0x800600F4u: goto label_800600F4;
    case 0x800600F8u: goto label_800600F8;
    case 0x800600FCu: goto label_800600FC;
    case 0x80060100u: goto label_80060100;
    case 0x80060104u: goto label_80060104;
    case 0x80060108u: goto label_80060108;
    case 0x8006010Cu: goto label_8006010C;
    case 0x80060110u: goto label_80060110;
    case 0x80060114u: goto label_80060114;
    case 0x80060118u: goto label_80060118;
    case 0x8006011Cu: goto label_8006011C;
    case 0x80060120u: goto label_80060120;
    case 0x80060124u: goto label_80060124;
    case 0x80060128u: goto label_80060128;
    case 0x8006012Cu: goto label_8006012C;
    case 0x80060130u: goto label_80060130;
    case 0x80060134u: goto label_80060134;
    case 0x80060138u: goto label_80060138;
    case 0x8006013Cu: goto label_8006013C;
    case 0x80060140u: goto label_80060140;
    case 0x80060144u: goto label_80060144;
    case 0x80060148u: goto label_80060148;
    case 0x8006014Cu: goto label_8006014C;
    case 0x80060150u: goto label_80060150;
    case 0x80060154u: goto label_80060154;
    case 0x80060158u: goto label_80060158;
    case 0x8006015Cu: goto label_8006015C;
    case 0x80060160u: goto label_80060160;
    case 0x80060164u: goto label_80060164;
    case 0x80060168u: goto label_80060168;
    case 0x8006016Cu: goto label_8006016C;
    case 0x80060170u: goto label_80060170;
    case 0x80060174u: goto label_80060174;
    case 0x80060178u: goto label_80060178;
    case 0x8006017Cu: goto label_8006017C;
    case 0x80060180u: goto label_80060180;
    case 0x80060184u: goto label_80060184;
    case 0x80060188u: goto label_80060188;
    case 0x8006018Cu: goto label_8006018C;
    case 0x80060190u: goto label_80060190;
    case 0x80060194u: goto label_80060194;
    case 0x80060198u: goto label_80060198;
    case 0x8006019Cu: goto label_8006019C;
    case 0x800601A0u: goto label_800601A0;
    case 0x800601A4u: goto label_800601A4;
    case 0x800601A8u: goto label_800601A8;
    case 0x800601ACu: goto label_800601AC;
    case 0x800601B0u: goto label_800601B0;
    case 0x800601B4u: goto label_800601B4;
    case 0x800601B8u: goto label_800601B8;
    case 0x800601BCu: goto label_800601BC;
    case 0x800601C0u: goto label_800601C0;
    case 0x800601C4u: goto label_800601C4;
    case 0x800601C8u: goto label_800601C8;
    case 0x800601CCu: goto label_800601CC;
    case 0x800601D0u: goto label_800601D0;
    case 0x800601D4u: goto label_800601D4;
    case 0x800601D8u: goto label_800601D8;
    case 0x800601DCu: goto label_800601DC;
    case 0x800601E0u: goto label_800601E0;
    case 0x800601E4u: goto label_800601E4;
    case 0x800601E8u: goto label_800601E8;
    case 0x800601ECu: goto label_800601EC;
    case 0x800601F0u: goto label_800601F0;
    case 0x800601F4u: goto label_800601F4;
    case 0x800601F8u: goto label_800601F8;
    case 0x800601FCu: goto label_800601FC;
    case 0x80060200u: goto label_80060200;
    case 0x80060204u: goto label_80060204;
    case 0x80060208u: goto label_80060208;
    case 0x8006020Cu: goto label_8006020C;
    case 0x80060210u: goto label_80060210;
    case 0x80060214u: goto label_80060214;
    case 0x80060218u: goto label_80060218;
    case 0x8006021Cu: goto label_8006021C;
    case 0x80060220u: goto label_80060220;
    case 0x80060224u: goto label_80060224;
    case 0x80060228u: goto label_80060228;
    case 0x8006022Cu: goto label_8006022C;
    case 0x80060230u: goto label_80060230;
    case 0x80060234u: goto label_80060234;
    case 0x80060238u: goto label_80060238;
    case 0x8006023Cu: goto label_8006023C;
    case 0x80060240u: goto label_80060240;
    case 0x80060244u: goto label_80060244;
    case 0x80060248u: goto label_80060248;
    case 0x8006024Cu: goto label_8006024C;
    case 0x80060250u: goto label_80060250;
    case 0x80060254u: goto label_80060254;
    case 0x80060258u: goto label_80060258;
    case 0x8006025Cu: goto label_8006025C;
    case 0x80060260u: goto label_80060260;
    case 0x80060264u: goto label_80060264;
    case 0x80060268u: goto label_80060268;
    case 0x8006026Cu: goto label_8006026C;
    case 0x80060270u: goto label_80060270;
    case 0x80060274u: goto label_80060274;
    case 0x80060278u: goto label_80060278;
    case 0x8006027Cu: goto label_8006027C;
    case 0x80060280u: goto label_80060280;
    case 0x80060284u: goto label_80060284;
    case 0x80060288u: goto label_80060288;
    case 0x8006028Cu: goto label_8006028C;
    case 0x80060290u: goto label_80060290;
    case 0x80060294u: goto label_80060294;
    case 0x80060298u: goto label_80060298;
    case 0x8006029Cu: goto label_8006029C;
    case 0x800602A0u: goto label_800602A0;
    case 0x800602A4u: goto label_800602A4;
    case 0x800602A8u: goto label_800602A8;
    case 0x800602ACu: goto label_800602AC;
    case 0x800602B0u: goto label_800602B0;
    case 0x800602B4u: goto label_800602B4;
    case 0x800602B8u: goto label_800602B8;
    case 0x800602BCu: goto label_800602BC;
    case 0x800602C0u: goto label_800602C0;
    case 0x800602C4u: goto label_800602C4;
    case 0x800602C8u: goto label_800602C8;
    case 0x800602CCu: goto label_800602CC;
    case 0x800602D0u: goto label_800602D0;
    case 0x800602D4u: goto label_800602D4;
    case 0x800602D8u: goto label_800602D8;
    case 0x800602DCu: goto label_800602DC;
    case 0x800602E0u: goto label_800602E0;
    case 0x800602E4u: goto label_800602E4;
    case 0x800602E8u: goto label_800602E8;
    case 0x800602ECu: goto label_800602EC;
    case 0x800602F0u: goto label_800602F0;
    case 0x800602F4u: goto label_800602F4;
    case 0x800602F8u: goto label_800602F8;
    case 0x800602FCu: goto label_800602FC;
    case 0x80060300u: goto label_80060300;
    case 0x80060304u: goto label_80060304;
    case 0x80060308u: goto label_80060308;
    case 0x8006030Cu: goto label_8006030C;
    case 0x80060310u: goto label_80060310;
    case 0x80060314u: goto label_80060314;
    case 0x80060318u: goto label_80060318;
    case 0x8006031Cu: goto label_8006031C;
    case 0x80060320u: goto label_80060320;
    case 0x80060324u: goto label_80060324;
    case 0x80060328u: goto label_80060328;
    case 0x8006032Cu: goto label_8006032C;
    case 0x80060330u: goto label_80060330;
    case 0x80060334u: goto label_80060334;
    case 0x80060338u: goto label_80060338;
    case 0x8006033Cu: goto label_8006033C;
    case 0x80060340u: goto label_80060340;
    case 0x80060344u: goto label_80060344;
    case 0x80060348u: goto label_80060348;
    case 0x8006034Cu: goto label_8006034C;
    case 0x80060350u: goto label_80060350;
    case 0x80060354u: goto label_80060354;
    case 0x80060358u: goto label_80060358;
    case 0x8006035Cu: goto label_8006035C;
    case 0x80060360u: goto label_80060360;
    case 0x80060364u: goto label_80060364;
    case 0x80060368u: goto label_80060368;
    case 0x8006036Cu: goto label_8006036C;
    case 0x80060370u: goto label_80060370;
    case 0x80060374u: goto label_80060374;
    case 0x80060378u: goto label_80060378;
    case 0x8006037Cu: goto label_8006037C;
    case 0x80060380u: goto label_80060380;
    case 0x80060384u: goto label_80060384;
    case 0x80060388u: goto label_80060388;
    case 0x8006038Cu: goto label_8006038C;
    case 0x80060390u: goto label_80060390;
    case 0x80060394u: goto label_80060394;
    case 0x80060398u: goto label_80060398;
    case 0x8006039Cu: goto label_8006039C;
    case 0x800603A0u: goto label_800603A0;
    case 0x800603A4u: goto label_800603A4;
    case 0x800603A8u: goto label_800603A8;
    case 0x800603ACu: goto label_800603AC;
    case 0x800603B0u: goto label_800603B0;
    case 0x800603B4u: goto label_800603B4;
    case 0x800603B8u: goto label_800603B8;
    case 0x800603BCu: goto label_800603BC;
    case 0x800603C0u: goto label_800603C0;
    case 0x800603C4u: goto label_800603C4;
    case 0x800603C8u: goto label_800603C8;
    case 0x800603CCu: goto label_800603CC;
    case 0x800603D0u: goto label_800603D0;
    case 0x800603D4u: goto label_800603D4;
    case 0x800603D8u: goto label_800603D8;
    case 0x800603DCu: goto label_800603DC;
    case 0x800603E0u: goto label_800603E0;
    case 0x800603E4u: goto label_800603E4;
    case 0x800603E8u: goto label_800603E8;
    case 0x800603ECu: goto label_800603EC;
    case 0x800603F0u: goto label_800603F0;
    case 0x800603F4u: goto label_800603F4;
    case 0x800603F8u: goto label_800603F8;
    case 0x800603FCu: goto label_800603FC;
    case 0x80060400u: goto label_80060400;
    case 0x80060404u: goto label_80060404;
    case 0x80060408u: goto label_80060408;
    case 0x8006040Cu: goto label_8006040C;
    case 0x80060410u: goto label_80060410;
    case 0x80060414u: goto label_80060414;
    case 0x80060418u: goto label_80060418;
    case 0x8006041Cu: goto label_8006041C;
    case 0x80060420u: goto label_80060420;
    case 0x80060424u: goto label_80060424;
    case 0x80060428u: goto label_80060428;
    case 0x8006042Cu: goto label_8006042C;
    case 0x80060430u: goto label_80060430;
    case 0x80060434u: goto label_80060434;
    case 0x80060438u: goto label_80060438;
    case 0x8006043Cu: goto label_8006043C;
    case 0x80060440u: goto label_80060440;
    case 0x80060444u: goto label_80060444;
    case 0x80060448u: goto label_80060448;
    case 0x8006044Cu: goto label_8006044C;
    case 0x80060450u: goto label_80060450;
    case 0x80060454u: goto label_80060454;
    case 0x80060458u: goto label_80060458;
    case 0x8006045Cu: goto label_8006045C;
    case 0x80060460u: goto label_80060460;
    case 0x80060464u: goto label_80060464;
    case 0x80060468u: goto label_80060468;
    case 0x8006046Cu: goto label_8006046C;
    case 0x80060470u: goto label_80060470;
    case 0x80060474u: goto label_80060474;
    case 0x80060478u: goto label_80060478;
    case 0x8006047Cu: goto label_8006047C;
    case 0x80060480u: goto label_80060480;
    case 0x80060484u: goto label_80060484;
    case 0x80060488u: goto label_80060488;
    case 0x8006048Cu: goto label_8006048C;
    case 0x80060490u: goto label_80060490;
    case 0x80060494u: goto label_80060494;
    case 0x80060498u: goto label_80060498;
    case 0x8006049Cu: goto label_8006049C;
    case 0x800604A0u: goto label_800604A0;
    case 0x800604A4u: goto label_800604A4;
    case 0x800604A8u: goto label_800604A8;
    case 0x800604ACu: goto label_800604AC;
    case 0x800604B0u: goto label_800604B0;
    case 0x800604B4u: goto label_800604B4;
    case 0x800604B8u: goto label_800604B8;
    case 0x800604BCu: goto label_800604BC;
    case 0x800604C0u: goto label_800604C0;
    case 0x800604C4u: goto label_800604C4;
    case 0x800604C8u: goto label_800604C8;
    case 0x800604CCu: goto label_800604CC;
    case 0x800604D0u: goto label_800604D0;
    case 0x800604D4u: goto label_800604D4;
    case 0x800604D8u: goto label_800604D8;
    case 0x800604DCu: goto label_800604DC;
    case 0x800604E0u: goto label_800604E0;
    case 0x800604E4u: goto label_800604E4;
    case 0x800604E8u: goto label_800604E8;
    case 0x800604ECu: goto label_800604EC;
    case 0x800604F0u: goto label_800604F0;
    case 0x800604F4u: goto label_800604F4;
    case 0x800604F8u: goto label_800604F8;
    case 0x800604FCu: goto label_800604FC;
    case 0x80060500u: goto label_80060500;
    case 0x80060504u: goto label_80060504;
    case 0x80060508u: goto label_80060508;
    case 0x8006050Cu: goto label_8006050C;
    case 0x80060510u: goto label_80060510;
    case 0x80060514u: goto label_80060514;
    case 0x80060518u: goto label_80060518;
    case 0x8006051Cu: goto label_8006051C;
    case 0x80060520u: goto label_80060520;
    case 0x80060524u: goto label_80060524;
    case 0x80060528u: goto label_80060528;
    case 0x8006052Cu: goto label_8006052C;
    case 0x80060530u: goto label_80060530;
    case 0x80060534u: goto label_80060534;
    case 0x80060538u: goto label_80060538;
    case 0x8006053Cu: goto label_8006053C;
    case 0x80060540u: goto label_80060540;
    case 0x80060544u: goto label_80060544;
    case 0x80060548u: goto label_80060548;
    case 0x8006054Cu: goto label_8006054C;
    case 0x80060550u: goto label_80060550;
    case 0x80060554u: goto label_80060554;
    case 0x80060558u: goto label_80060558;
    case 0x8006055Cu: goto label_8006055C;
    case 0x80060560u: goto label_80060560;
    case 0x80060564u: goto label_80060564;
    case 0x80060568u: goto label_80060568;
    case 0x8006056Cu: goto label_8006056C;
    case 0x80060570u: goto label_80060570;
    case 0x80060574u: goto label_80060574;
    case 0x80060578u: goto label_80060578;
    case 0x8006057Cu: goto label_8006057C;
    case 0x80060580u: goto label_80060580;
    case 0x80060584u: goto label_80060584;
    case 0x80060588u: goto label_80060588;
    case 0x8006058Cu: goto label_8006058C;
    case 0x80060590u: goto label_80060590;
    case 0x80060594u: goto label_80060594;
    case 0x80060598u: goto label_80060598;
    case 0x8006059Cu: goto label_8006059C;
    case 0x800605A0u: goto label_800605A0;
    case 0x800605A4u: goto label_800605A4;
    case 0x800605A8u: goto label_800605A8;
    case 0x800605ACu: goto label_800605AC;
    case 0x800605B0u: goto label_800605B0;
    case 0x800605B4u: goto label_800605B4;
    case 0x800605B8u: goto label_800605B8;
    case 0x800605BCu: goto label_800605BC;
    case 0x800605C0u: goto label_800605C0;
    case 0x800605C4u: goto label_800605C4;
    case 0x800605C8u: goto label_800605C8;
    case 0x800605CCu: goto label_800605CC;
    case 0x800605D0u: goto label_800605D0;
    case 0x800605D4u: goto label_800605D4;
    case 0x800605D8u: goto label_800605D8;
    case 0x800605DCu: goto label_800605DC;
    case 0x800605E0u: goto label_800605E0;
    case 0x800605E4u: goto label_800605E4;
    case 0x800605E8u: goto label_800605E8;
    case 0x800605ECu: goto label_800605EC;
    case 0x800605F0u: goto label_800605F0;
    case 0x800605F4u: goto label_800605F4;
    case 0x800605F8u: goto label_800605F8;
    case 0x800605FCu: goto label_800605FC;
    case 0x80060600u: goto label_80060600;
    case 0x80060604u: goto label_80060604;
    case 0x80060608u: goto label_80060608;
    case 0x8006060Cu: goto label_8006060C;
    case 0x80060610u: goto label_80060610;
    case 0x80060614u: goto label_80060614;
    case 0x80060618u: goto label_80060618;
    case 0x8006061Cu: goto label_8006061C;
    case 0x80060620u: goto label_80060620;
    case 0x80060624u: goto label_80060624;
    case 0x80060628u: goto label_80060628;
    case 0x8006062Cu: goto label_8006062C;
    case 0x80060630u: goto label_80060630;
    case 0x80060634u: goto label_80060634;
    case 0x80060638u: goto label_80060638;
    case 0x8006063Cu: goto label_8006063C;
    case 0x80060640u: goto label_80060640;
    case 0x80060644u: goto label_80060644;
    case 0x80060648u: goto label_80060648;
    case 0x8006064Cu: goto label_8006064C;
    case 0x80060650u: goto label_80060650;
    case 0x80060654u: goto label_80060654;
    case 0x80060658u: goto label_80060658;
    case 0x8006065Cu: goto label_8006065C;
    case 0x80060660u: goto label_80060660;
    case 0x80060664u: goto label_80060664;
    case 0x80060668u: goto label_80060668;
    case 0x8006066Cu: goto label_8006066C;
    case 0x80060670u: goto label_80060670;
    case 0x80060674u: goto label_80060674;
    case 0x80060678u: goto label_80060678;
    case 0x8006067Cu: goto label_8006067C;
    case 0x80060680u: goto label_80060680;
    case 0x80060684u: goto label_80060684;
    case 0x80060688u: goto label_80060688;
    case 0x8006068Cu: goto label_8006068C;
    case 0x80060690u: goto label_80060690;
    case 0x80060694u: goto label_80060694;
    case 0x80060698u: goto label_80060698;
    case 0x8006069Cu: goto label_8006069C;
    case 0x800606A0u: goto label_800606A0;
    case 0x800606A4u: goto label_800606A4;
    case 0x800606A8u: goto label_800606A8;
    case 0x800606ACu: goto label_800606AC;
    case 0x800606B0u: goto label_800606B0;
    case 0x800606B4u: goto label_800606B4;
    case 0x800606B8u: goto label_800606B8;
    case 0x800606BCu: goto label_800606BC;
    case 0x800606C0u: goto label_800606C0;
    case 0x800606C4u: goto label_800606C4;
    case 0x800606C8u: goto label_800606C8;
    case 0x800606CCu: goto label_800606CC;
    case 0x800606D0u: goto label_800606D0;
    case 0x800606D4u: goto label_800606D4;
    case 0x800606D8u: goto label_800606D8;
    case 0x800606DCu: goto label_800606DC;
    case 0x800606E0u: goto label_800606E0;
    case 0x800606E4u: goto label_800606E4;
    case 0x800606E8u: goto label_800606E8;
    case 0x800606ECu: goto label_800606EC;
    case 0x800606F0u: goto label_800606F0;
    case 0x800606F4u: goto label_800606F4;
    case 0x800606F8u: goto label_800606F8;
    case 0x800606FCu: goto label_800606FC;
    case 0x80060700u: goto label_80060700;
    case 0x80060704u: goto label_80060704;
    case 0x80060708u: goto label_80060708;
    case 0x8006070Cu: goto label_8006070C;
    case 0x80060710u: goto label_80060710;
    case 0x80060714u: goto label_80060714;
    case 0x80060718u: goto label_80060718;
    case 0x8006071Cu: goto label_8006071C;
    case 0x80060720u: goto label_80060720;
    case 0x80060724u: goto label_80060724;
    case 0x80060728u: goto label_80060728;
    case 0x8006072Cu: goto label_8006072C;
    case 0x80060730u: goto label_80060730;
    case 0x80060734u: goto label_80060734;
    case 0x80060738u: goto label_80060738;
    case 0x8006073Cu: goto label_8006073C;
    case 0x80060740u: goto label_80060740;
    case 0x80060744u: goto label_80060744;
    case 0x80060748u: goto label_80060748;
    case 0x8006074Cu: goto label_8006074C;
    case 0x80060750u: goto label_80060750;
    case 0x80060754u: goto label_80060754;
    case 0x80060758u: goto label_80060758;
    case 0x8006075Cu: goto label_8006075C;
    case 0x80060760u: goto label_80060760;
    case 0x80060764u: goto label_80060764;
    case 0x80060768u: goto label_80060768;
    case 0x8006076Cu: goto label_8006076C;
    case 0x80060770u: goto label_80060770;
    case 0x80060774u: goto label_80060774;
    case 0x80060778u: goto label_80060778;
    case 0x8006077Cu: goto label_8006077C;
    case 0x80060780u: goto label_80060780;
    case 0x80060784u: goto label_80060784;
    case 0x80060788u: goto label_80060788;
    case 0x8006078Cu: goto label_8006078C;
    case 0x80060790u: goto label_80060790;
    case 0x80060794u: goto label_80060794;
    case 0x80060798u: goto label_80060798;
    case 0x8006079Cu: goto label_8006079C;
    case 0x800607A0u: goto label_800607A0;
    case 0x800607A4u: goto label_800607A4;
    case 0x800607A8u: goto label_800607A8;
    case 0x800607ACu: goto label_800607AC;
    case 0x800607B0u: goto label_800607B0;
    case 0x800607B4u: goto label_800607B4;
    case 0x800607B8u: goto label_800607B8;
    case 0x800607BCu: goto label_800607BC;
    case 0x800607C0u: goto label_800607C0;
    case 0x800607C4u: goto label_800607C4;
    case 0x800607C8u: goto label_800607C8;
    case 0x800607CCu: goto label_800607CC;
    case 0x800607D0u: goto label_800607D0;
    case 0x800607D4u: goto label_800607D4;
    case 0x800607D8u: goto label_800607D8;
    case 0x800607DCu: goto label_800607DC;
    case 0x800607E0u: goto label_800607E0;
    case 0x800607E4u: goto label_800607E4;
    case 0x800607E8u: goto label_800607E8;
    case 0x800607ECu: goto label_800607EC;
    case 0x800607F0u: goto label_800607F0;
    case 0x800607F4u: goto label_800607F4;
    case 0x800607F8u: goto label_800607F8;
    case 0x800607FCu: goto label_800607FC;
    case 0x80060800u: goto label_80060800;
    case 0x80060804u: goto label_80060804;
    case 0x80060808u: goto label_80060808;
    case 0x8006080Cu: goto label_8006080C;
    case 0x80060810u: goto label_80060810;
    case 0x80060814u: goto label_80060814;
    case 0x80060818u: goto label_80060818;
    case 0x8006081Cu: goto label_8006081C;
    case 0x80060820u: goto label_80060820;
    case 0x80060824u: goto label_80060824;
    case 0x80060828u: goto label_80060828;
    case 0x8006082Cu: goto label_8006082C;
    case 0x80060830u: goto label_80060830;
    case 0x80060834u: goto label_80060834;
    case 0x80060838u: goto label_80060838;
    case 0x8006083Cu: goto label_8006083C;
    case 0x80060840u: goto label_80060840;
    case 0x80060844u: goto label_80060844;
    case 0x80060848u: goto label_80060848;
    case 0x8006084Cu: goto label_8006084C;
    case 0x80060850u: goto label_80060850;
    case 0x80060854u: goto label_80060854;
    case 0x80060858u: goto label_80060858;
    case 0x8006085Cu: goto label_8006085C;
    case 0x80060860u: goto label_80060860;
    case 0x80060864u: goto label_80060864;
    case 0x80060868u: goto label_80060868;
    case 0x8006086Cu: goto label_8006086C;
    case 0x80060870u: goto label_80060870;
    case 0x80060874u: goto label_80060874;
    case 0x80060878u: goto label_80060878;
    case 0x8006087Cu: goto label_8006087C;
    case 0x80060880u: goto label_80060880;
    case 0x80060884u: goto label_80060884;
    case 0x80060888u: goto label_80060888;
    case 0x8006088Cu: goto label_8006088C;
    case 0x80060890u: goto label_80060890;
    case 0x80060894u: goto label_80060894;
    case 0x80060898u: goto label_80060898;
    case 0x8006089Cu: goto label_8006089C;
    case 0x800608A0u: goto label_800608A0;
    case 0x800608A4u: goto label_800608A4;
    case 0x800608A8u: goto label_800608A8;
    case 0x800608ACu: goto label_800608AC;
    case 0x800608B0u: goto label_800608B0;
    case 0x800608B4u: goto label_800608B4;
    case 0x800608B8u: goto label_800608B8;
    case 0x800608BCu: goto label_800608BC;
    case 0x800608C0u: goto label_800608C0;
    case 0x800608C4u: goto label_800608C4;
    case 0x800608C8u: goto label_800608C8;
    case 0x800608CCu: goto label_800608CC;
    case 0x800608D0u: goto label_800608D0;
    case 0x800608D4u: goto label_800608D4;
    case 0x800608D8u: goto label_800608D8;
    case 0x800608DCu: goto label_800608DC;
    case 0x800608E0u: goto label_800608E0;
    case 0x800608E4u: goto label_800608E4;
    case 0x800608E8u: goto label_800608E8;
    case 0x800608ECu: goto label_800608EC;
    case 0x800608F0u: goto label_800608F0;
    case 0x800608F4u: goto label_800608F4;
    case 0x800608F8u: goto label_800608F8;
    case 0x800608FCu: goto label_800608FC;
    case 0x80060900u: goto label_80060900;
    case 0x80060904u: goto label_80060904;
    case 0x80060908u: goto label_80060908;
    case 0x8006090Cu: goto label_8006090C;
    case 0x80060910u: goto label_80060910;
    case 0x80060914u: goto label_80060914;
    case 0x80060918u: goto label_80060918;
    case 0x8006091Cu: goto label_8006091C;
    case 0x80060920u: goto label_80060920;
    case 0x80060924u: goto label_80060924;
    case 0x80060928u: goto label_80060928;
    case 0x8006092Cu: goto label_8006092C;
    case 0x80060930u: goto label_80060930;
    case 0x80060934u: goto label_80060934;
    case 0x80060938u: goto label_80060938;
    case 0x8006093Cu: goto label_8006093C;
    case 0x80060940u: goto label_80060940;
    case 0x80060944u: goto label_80060944;
    case 0x80060948u: goto label_80060948;
    case 0x8006094Cu: goto label_8006094C;
    case 0x80060950u: goto label_80060950;
    case 0x80060954u: goto label_80060954;
    case 0x80060958u: goto label_80060958;
    case 0x8006095Cu: goto label_8006095C;
    case 0x80060960u: goto label_80060960;
    case 0x80060964u: goto label_80060964;
    case 0x80060968u: goto label_80060968;
    case 0x8006096Cu: goto label_8006096C;
    case 0x80060970u: goto label_80060970;
    case 0x80060974u: goto label_80060974;
    case 0x80060978u: goto label_80060978;
    case 0x8006097Cu: goto label_8006097C;
    case 0x80060980u: goto label_80060980;
    case 0x80060984u: goto label_80060984;
    case 0x80060988u: goto label_80060988;
    case 0x8006098Cu: goto label_8006098C;
    case 0x80060990u: goto label_80060990;
    case 0x80060994u: goto label_80060994;
    case 0x80060998u: goto label_80060998;
    case 0x8006099Cu: goto label_8006099C;
    case 0x800609A0u: goto label_800609A0;
    case 0x800609A4u: goto label_800609A4;
    case 0x800609A8u: goto label_800609A8;
    case 0x800609ACu: goto label_800609AC;
    case 0x800609B0u: goto label_800609B0;
    case 0x800609B4u: goto label_800609B4;
    case 0x800609B8u: goto label_800609B8;
    case 0x800609BCu: goto label_800609BC;
    case 0x800609C0u: goto label_800609C0;
    case 0x800609C4u: goto label_800609C4;
    case 0x800609C8u: goto label_800609C8;
    case 0x800609CCu: goto label_800609CC;
    case 0x800609D0u: goto label_800609D0;
    case 0x800609D4u: goto label_800609D4;
    case 0x800609D8u: goto label_800609D8;
    case 0x800609DCu: goto label_800609DC;
    case 0x800609E0u: goto label_800609E0;
    case 0x800609E4u: goto label_800609E4;
    case 0x800609E8u: goto label_800609E8;
    case 0x800609ECu: goto label_800609EC;
    case 0x800609F0u: goto label_800609F0;
    case 0x800609F4u: goto label_800609F4;
    case 0x800609F8u: goto label_800609F8;
    case 0x800609FCu: goto label_800609FC;
    case 0x80060A00u: goto label_80060A00;
    case 0x80060A04u: goto label_80060A04;
    case 0x80060A08u: goto label_80060A08;
    case 0x80060A0Cu: goto label_80060A0C;
    case 0x80060A10u: goto label_80060A10;
    case 0x80060A14u: goto label_80060A14;
    case 0x80060A18u: goto label_80060A18;
    case 0x80060A1Cu: goto label_80060A1C;
    case 0x80060A20u: goto label_80060A20;
    case 0x80060A24u: goto label_80060A24;
    case 0x80060A28u: goto label_80060A28;
    case 0x80060A2Cu: goto label_80060A2C;
    case 0x80060A30u: goto label_80060A30;
    case 0x80060A34u: goto label_80060A34;
    case 0x80060A38u: goto label_80060A38;
    case 0x80060A3Cu: goto label_80060A3C;
    case 0x80060A40u: goto label_80060A40;
    case 0x80060A44u: goto label_80060A44;
    case 0x80060A48u: goto label_80060A48;
    case 0x80060A4Cu: goto label_80060A4C;
    case 0x80060A50u: goto label_80060A50;
    case 0x80060A54u: goto label_80060A54;
    case 0x80060A58u: goto label_80060A58;
    case 0x80060A5Cu: goto label_80060A5C;
    case 0x80060A60u: goto label_80060A60;
    case 0x80060A64u: goto label_80060A64;
    case 0x80060A68u: goto label_80060A68;
    case 0x80060A6Cu: goto label_80060A6C;
    case 0x80060A70u: goto label_80060A70;
    case 0x80060A74u: goto label_80060A74;
    case 0x80060A78u: goto label_80060A78;
    case 0x80060A7Cu: goto label_80060A7C;
    case 0x80060A80u: goto label_80060A80;
    case 0x80060A84u: goto label_80060A84;
    case 0x80060A88u: goto label_80060A88;
    case 0x80060A8Cu: goto label_80060A8C;
    case 0x80060A90u: goto label_80060A90;
    case 0x80060A94u: goto label_80060A94;
    case 0x80060A98u: goto label_80060A98;
    case 0x80060A9Cu: goto label_80060A9C;
    case 0x80060AA0u: goto label_80060AA0;
    case 0x80060AA4u: goto label_80060AA4;
    case 0x80060AA8u: goto label_80060AA8;
    case 0x80060AACu: goto label_80060AAC;
    case 0x80060AB0u: goto label_80060AB0;
    case 0x80060AB4u: goto label_80060AB4;
    case 0x80060AB8u: goto label_80060AB8;
    case 0x80060ABCu: goto label_80060ABC;
    case 0x80060AC0u: goto label_80060AC0;
    case 0x80060AC4u: goto label_80060AC4;
    case 0x80060AC8u: goto label_80060AC8;
    case 0x80060ACCu: goto label_80060ACC;
    case 0x80060AD0u: goto label_80060AD0;
    case 0x80060AD4u: goto label_80060AD4;
    case 0x80060AD8u: goto label_80060AD8;
    case 0x80060ADCu: goto label_80060ADC;
    case 0x80060AE0u: goto label_80060AE0;
    case 0x80060AE4u: goto label_80060AE4;
    case 0x80060AE8u: goto label_80060AE8;
    case 0x80060AECu: goto label_80060AEC;
    case 0x80060AF0u: goto label_80060AF0;
    case 0x80060AF4u: goto label_80060AF4;
    case 0x80060AF8u: goto label_80060AF8;
    case 0x80060AFCu: goto label_80060AFC;
    case 0x80060B00u: goto label_80060B00;
    case 0x80060B04u: goto label_80060B04;
    case 0x80060B08u: goto label_80060B08;
    case 0x80060B0Cu: goto label_80060B0C;
    case 0x80060B10u: goto label_80060B10;
    case 0x80060B14u: goto label_80060B14;
    case 0x80060B18u: goto label_80060B18;
    case 0x80060B1Cu: goto label_80060B1C;
    case 0x80060B20u: goto label_80060B20;
    case 0x80060B24u: goto label_80060B24;
    case 0x80060B28u: goto label_80060B28;
    case 0x80060B2Cu: goto label_80060B2C;
    case 0x80060B30u: goto label_80060B30;
    case 0x80060B34u: goto label_80060B34;
    case 0x80060B38u: goto label_80060B38;
    case 0x80060B3Cu: goto label_80060B3C;
    case 0x80060B40u: goto label_80060B40;
    case 0x80060B44u: goto label_80060B44;
    case 0x80060B48u: goto label_80060B48;
    case 0x80060B4Cu: goto label_80060B4C;
    case 0x80060B50u: goto label_80060B50;
    case 0x80060B54u: goto label_80060B54;
    case 0x80060B58u: goto label_80060B58;
    case 0x80060B5Cu: goto label_80060B5C;
    case 0x80060B60u: goto label_80060B60;
    case 0x80060B64u: goto label_80060B64;
    case 0x80060B68u: goto label_80060B68;
    case 0x80060B6Cu: goto label_80060B6C;
    case 0x80060B70u: goto label_80060B70;
    case 0x80060B74u: goto label_80060B74;
    case 0x80060B78u: goto label_80060B78;
    case 0x80060B7Cu: goto label_80060B7C;
    case 0x80060B80u: goto label_80060B80;
    case 0x80060B84u: goto label_80060B84;
    case 0x80060B88u: goto label_80060B88;
    case 0x80060B8Cu: goto label_80060B8C;
    case 0x80060B90u: goto label_80060B90;
    case 0x80060B94u: goto label_80060B94;
    case 0x80060B98u: goto label_80060B98;
    case 0x80060B9Cu: goto label_80060B9C;
    case 0x80060BA0u: goto label_80060BA0;
    case 0x80060BA4u: goto label_80060BA4;
    case 0x80060BA8u: goto label_80060BA8;
    case 0x80060BACu: goto label_80060BAC;
    case 0x80060BB0u: goto label_80060BB0;
    case 0x80060BB4u: goto label_80060BB4;
    case 0x80060BB8u: goto label_80060BB8;
    case 0x80060BBCu: goto label_80060BBC;
    case 0x80060BC0u: goto label_80060BC0;
    case 0x80060BC4u: goto label_80060BC4;
    case 0x80060BC8u: goto label_80060BC8;
    case 0x80060BCCu: goto label_80060BCC;
    case 0x80060BD0u: goto label_80060BD0;
    case 0x80060BD4u: goto label_80060BD4;
    case 0x80060BD8u: goto label_80060BD8;
    case 0x80060BDCu: goto label_80060BDC;
    case 0x80060BE0u: goto label_80060BE0;
    case 0x80060BE4u: goto label_80060BE4;
    case 0x80060BE8u: goto label_80060BE8;
    case 0x80060BECu: goto label_80060BEC;
    case 0x80060BF0u: goto label_80060BF0;
    case 0x80060BF4u: goto label_80060BF4;
    case 0x80060BF8u: goto label_80060BF8;
    case 0x80060BFCu: goto label_80060BFC;
    case 0x80060C00u: goto label_80060C00;
    case 0x80060C04u: goto label_80060C04;
    case 0x80060C08u: goto label_80060C08;
    case 0x80060C0Cu: goto label_80060C0C;
    case 0x80060C10u: goto label_80060C10;
    case 0x80060C14u: goto label_80060C14;
    case 0x80060C18u: goto label_80060C18;
    case 0x80060C1Cu: goto label_80060C1C;
    case 0x80060C20u: goto label_80060C20;
    case 0x80060C24u: goto label_80060C24;
    case 0x80060C28u: goto label_80060C28;
    case 0x80060C2Cu: goto label_80060C2C;
    case 0x80060C30u: goto label_80060C30;
    case 0x80060C34u: goto label_80060C34;
    case 0x80060C38u: goto label_80060C38;
    case 0x80060C3Cu: goto label_80060C3C;
    case 0x80060C40u: goto label_80060C40;
    case 0x80060C44u: goto label_80060C44;
    case 0x80060C48u: goto label_80060C48;
    case 0x80060C4Cu: goto label_80060C4C;
    case 0x80060C50u: goto label_80060C50;
    case 0x80060C54u: goto label_80060C54;
    case 0x80060C58u: goto label_80060C58;
    case 0x80060C5Cu: goto label_80060C5C;
    case 0x80060C60u: goto label_80060C60;
    case 0x80060C64u: goto label_80060C64;
    case 0x80060C68u: goto label_80060C68;
    case 0x80060C6Cu: goto label_80060C6C;
    case 0x80060C70u: goto label_80060C70;
    case 0x80060C74u: goto label_80060C74;
    case 0x80060C78u: goto label_80060C78;
    case 0x80060C7Cu: goto label_80060C7C;
    case 0x80060C80u: goto label_80060C80;
    case 0x80060C84u: goto label_80060C84;
    case 0x80060C88u: goto label_80060C88;
    case 0x80060C8Cu: goto label_80060C8C;
    case 0x80060C90u: goto label_80060C90;
    case 0x80060C94u: goto label_80060C94;
    case 0x80060C98u: goto label_80060C98;
    case 0x80060C9Cu: goto label_80060C9C;
    case 0x80060CA0u: goto label_80060CA0;
    case 0x80060CA4u: goto label_80060CA4;
    case 0x80060CA8u: goto label_80060CA8;
    case 0x80060CACu: goto label_80060CAC;
    case 0x80060CB0u: goto label_80060CB0;
    case 0x80060CB4u: goto label_80060CB4;
    case 0x80060CB8u: goto label_80060CB8;
    case 0x80060CBCu: goto label_80060CBC;
    case 0x80060CC0u: goto label_80060CC0;
    case 0x80060CC4u: goto label_80060CC4;
    case 0x80060CC8u: goto label_80060CC8;
    case 0x80060CCCu: goto label_80060CCC;
    case 0x80060CD0u: goto label_80060CD0;
    case 0x80060CD4u: goto label_80060CD4;
    case 0x80060CD8u: goto label_80060CD8;
    case 0x80060CDCu: goto label_80060CDC;
    case 0x80060CE0u: goto label_80060CE0;
    case 0x80060CE4u: goto label_80060CE4;
    case 0x80060CE8u: goto label_80060CE8;
    case 0x80060CECu: goto label_80060CEC;
    case 0x80060CF0u: goto label_80060CF0;
    case 0x80060CF4u: goto label_80060CF4;
    case 0x80060CF8u: goto label_80060CF8;
    case 0x80060CFCu: goto label_80060CFC;
    case 0x80060D00u: goto label_80060D00;
    case 0x80060D04u: goto label_80060D04;
    case 0x80060D08u: goto label_80060D08;
    case 0x80060D0Cu: goto label_80060D0C;
    case 0x80060D10u: goto label_80060D10;
    case 0x80060D14u: goto label_80060D14;
    case 0x80060D18u: goto label_80060D18;
    case 0x80060D1Cu: goto label_80060D1C;
    case 0x80060D20u: goto label_80060D20;
    case 0x80060D24u: goto label_80060D24;
    case 0x80060D28u: goto label_80060D28;
    case 0x80060D2Cu: goto label_80060D2C;
    case 0x80060D30u: goto label_80060D30;
    case 0x80060D34u: goto label_80060D34;
    case 0x80060D38u: goto label_80060D38;
    case 0x80060D3Cu: goto label_80060D3C;
    case 0x80060D40u: goto label_80060D40;
    case 0x80060D44u: goto label_80060D44;
    case 0x80060D48u: goto label_80060D48;
    case 0x80060D4Cu: goto label_80060D4C;
    case 0x80060D50u: goto label_80060D50;
    case 0x80060D54u: goto label_80060D54;
    case 0x80060D58u: goto label_80060D58;
    case 0x80060D5Cu: goto label_80060D5C;
    case 0x80060D60u: goto label_80060D60;
    case 0x80060D64u: goto label_80060D64;
    case 0x80060D68u: goto label_80060D68;
    case 0x80060D6Cu: goto label_80060D6C;
    case 0x80060D70u: goto label_80060D70;
    case 0x80060D74u: goto label_80060D74;
    case 0x80060D78u: goto label_80060D78;
    case 0x80060D7Cu: goto label_80060D7C;
    case 0x80060D80u: goto label_80060D80;
    case 0x80060D84u: goto label_80060D84;
    case 0x80060D88u: goto label_80060D88;
    case 0x80060D8Cu: goto label_80060D8C;
    case 0x80060D90u: goto label_80060D90;
    case 0x80060D94u: goto label_80060D94;
    case 0x80060D98u: goto label_80060D98;
    case 0x80060D9Cu: goto label_80060D9C;
    case 0x80060DA0u: goto label_80060DA0;
    case 0x80060DA4u: goto label_80060DA4;
    case 0x80060DA8u: goto label_80060DA8;
    case 0x80060DACu: goto label_80060DAC;
    case 0x80060DB0u: goto label_80060DB0;
    case 0x80060DB4u: goto label_80060DB4;
    case 0x80060DB8u: goto label_80060DB8;
    case 0x80060DBCu: goto label_80060DBC;
    case 0x80060DC0u: goto label_80060DC0;
    case 0x80060DC4u: goto label_80060DC4;
    case 0x80060DC8u: goto label_80060DC8;
    case 0x80060DCCu: goto label_80060DCC;
    case 0x80060DD0u: goto label_80060DD0;
    case 0x80060DD4u: goto label_80060DD4;
    case 0x80060DD8u: goto label_80060DD8;
    case 0x80060DDCu: goto label_80060DDC;
    case 0x80060DE0u: goto label_80060DE0;
    case 0x80060DE4u: goto label_80060DE4;
    case 0x80060DE8u: goto label_80060DE8;
    case 0x80060DECu: goto label_80060DEC;
    case 0x80060DF0u: goto label_80060DF0;
    case 0x80060DF4u: goto label_80060DF4;
    case 0x80060DF8u: goto label_80060DF8;
    case 0x80060DFCu: goto label_80060DFC;
    case 0x80060E00u: goto label_80060E00;
    case 0x80060E04u: goto label_80060E04;
    case 0x80060E08u: goto label_80060E08;
    case 0x80060E0Cu: goto label_80060E0C;
    case 0x80060E10u: goto label_80060E10;
    case 0x80060E14u: goto label_80060E14;
    case 0x80060E18u: goto label_80060E18;
    case 0x80060E1Cu: goto label_80060E1C;
    case 0x80060E20u: goto label_80060E20;
    case 0x80060E24u: goto label_80060E24;
    case 0x80060E28u: goto label_80060E28;
    case 0x80060E2Cu: goto label_80060E2C;
    case 0x80060E30u: goto label_80060E30;
    case 0x80060E34u: goto label_80060E34;
    case 0x80060E38u: goto label_80060E38;
    case 0x80060E3Cu: goto label_80060E3C;
    case 0x80060E40u: goto label_80060E40;
    case 0x80060E44u: goto label_80060E44;
    case 0x80060E48u: goto label_80060E48;
    case 0x80060E4Cu: goto label_80060E4C;
    case 0x80060E50u: goto label_80060E50;
    case 0x80060E54u: goto label_80060E54;
    case 0x80060E58u: goto label_80060E58;
    case 0x80060E5Cu: goto label_80060E5C;
    case 0x80060E60u: goto label_80060E60;
    case 0x80060E64u: goto label_80060E64;
    case 0x80060E68u: goto label_80060E68;
    case 0x80060E6Cu: goto label_80060E6C;
    case 0x80060E70u: goto label_80060E70;
    case 0x80060E74u: goto label_80060E74;
    case 0x80060E78u: goto label_80060E78;
    case 0x80060E7Cu: goto label_80060E7C;
    case 0x80060E80u: goto label_80060E80;
    case 0x80060E84u: goto label_80060E84;
    case 0x80060E88u: goto label_80060E88;
    case 0x80060E8Cu: goto label_80060E8C;
    case 0x80060E90u: goto label_80060E90;
    case 0x80060E94u: goto label_80060E94;
    case 0x80060E98u: goto label_80060E98;
    case 0x80060E9Cu: goto label_80060E9C;
    case 0x80060EA0u: goto label_80060EA0;
    case 0x80060EA4u: goto label_80060EA4;
    case 0x80060EA8u: goto label_80060EA8;
    case 0x80060EACu: goto label_80060EAC;
    case 0x80060EB0u: goto label_80060EB0;
    case 0x80060EB4u: goto label_80060EB4;
    case 0x80060EB8u: goto label_80060EB8;
    case 0x80060EBCu: goto label_80060EBC;
    case 0x80060EC0u: goto label_80060EC0;
    case 0x80060EC4u: goto label_80060EC4;
    case 0x80060EC8u: goto label_80060EC8;
    case 0x80060ECCu: goto label_80060ECC;
    case 0x80060ED0u: goto label_80060ED0;
    case 0x80060ED4u: goto label_80060ED4;
    case 0x80060ED8u: goto label_80060ED8;
    case 0x80060EDCu: goto label_80060EDC;
    case 0x80060EE0u: goto label_80060EE0;
    case 0x80060EE4u: goto label_80060EE4;
    case 0x80060EE8u: goto label_80060EE8;
    case 0x80060EECu: goto label_80060EEC;
    case 0x80060EF0u: goto label_80060EF0;
    case 0x80060EF4u: goto label_80060EF4;
    case 0x80060EF8u: goto label_80060EF8;
    case 0x80060EFCu: goto label_80060EFC;
    case 0x80060F00u: goto label_80060F00;
    case 0x80060F04u: goto label_80060F04;
    case 0x80060F08u: goto label_80060F08;
    case 0x80060F0Cu: goto label_80060F0C;
    case 0x80060F10u: goto label_80060F10;
    case 0x80060F14u: goto label_80060F14;
    case 0x80060F18u: goto label_80060F18;
    case 0x80060F1Cu: goto label_80060F1C;
    case 0x80060F20u: goto label_80060F20;
    case 0x80060F24u: goto label_80060F24;
    case 0x80060F28u: goto label_80060F28;
    case 0x80060F2Cu: goto label_80060F2C;
    case 0x80060F30u: goto label_80060F30;
    case 0x80060F34u: goto label_80060F34;
    case 0x80060F38u: goto label_80060F38;
    case 0x80060F3Cu: goto label_80060F3C;
    case 0x80060F40u: goto label_80060F40;
    case 0x80060F44u: goto label_80060F44;
    case 0x80060F48u: goto label_80060F48;
    case 0x80060F4Cu: goto label_80060F4C;
    case 0x80060F50u: goto label_80060F50;
    case 0x80060F54u: goto label_80060F54;
    case 0x80060F58u: goto label_80060F58;
    case 0x80060F5Cu: goto label_80060F5C;
    case 0x80060F60u: goto label_80060F60;
    case 0x80060F64u: goto label_80060F64;
    case 0x80060F68u: goto label_80060F68;
    case 0x80060F6Cu: goto label_80060F6C;
    case 0x80060F70u: goto label_80060F70;
    case 0x80060F74u: goto label_80060F74;
    case 0x80060F78u: goto label_80060F78;
    case 0x80060F7Cu: goto label_80060F7C;
    case 0x80060F80u: goto label_80060F80;
    case 0x80060F84u: goto label_80060F84;
    case 0x80060F88u: goto label_80060F88;
    case 0x80060F8Cu: goto label_80060F8C;
    case 0x80060F90u: goto label_80060F90;
    case 0x80060F94u: goto label_80060F94;
    case 0x80060F98u: goto label_80060F98;
    case 0x80060F9Cu: goto label_80060F9C;
    case 0x80060FA0u: goto label_80060FA0;
    case 0x80060FA4u: goto label_80060FA4;
    case 0x80060FA8u: goto label_80060FA8;
    case 0x80060FACu: goto label_80060FAC;
    case 0x80060FB0u: goto label_80060FB0;
    case 0x80060FB4u: goto label_80060FB4;
    case 0x80060FB8u: goto label_80060FB8;
    case 0x80060FBCu: goto label_80060FBC;
    case 0x80060FC0u: goto label_80060FC0;
    case 0x80060FC4u: goto label_80060FC4;
    case 0x80060FC8u: goto label_80060FC8;
    case 0x80060FCCu: goto label_80060FCC;
    case 0x80060FD0u: goto label_80060FD0;
    case 0x80060FD4u: goto label_80060FD4;
    case 0x80060FD8u: goto label_80060FD8;
    case 0x80060FDCu: goto label_80060FDC;
    case 0x80060FE0u: goto label_80060FE0;
    case 0x80060FE4u: goto label_80060FE4;
    case 0x80060FE8u: goto label_80060FE8;
    case 0x80060FECu: goto label_80060FEC;
    case 0x80060FF0u: goto label_80060FF0;
    case 0x80060FF4u: goto label_80060FF4;
    case 0x80060FF8u: goto label_80060FF8;
    case 0x80060FFCu: goto label_80060FFC;
    case 0x80061000u: goto label_80061000;
    case 0x80061004u: goto label_80061004;
    case 0x80061008u: goto label_80061008;
    case 0x8006100Cu: goto label_8006100C;
    case 0x80061010u: goto label_80061010;
    case 0x80061014u: goto label_80061014;
    case 0x80061018u: goto label_80061018;
    case 0x8006101Cu: goto label_8006101C;
    case 0x80061020u: goto label_80061020;
    case 0x80061024u: goto label_80061024;
    case 0x80061028u: goto label_80061028;
    case 0x8006102Cu: goto label_8006102C;
    case 0x80061030u: goto label_80061030;
    case 0x80061034u: goto label_80061034;
    case 0x80061038u: goto label_80061038;
    case 0x8006103Cu: goto label_8006103C;
    case 0x80061040u: goto label_80061040;
    case 0x80061044u: goto label_80061044;
    case 0x80061048u: goto label_80061048;
    case 0x8006104Cu: goto label_8006104C;
    case 0x80061050u: goto label_80061050;
    case 0x80061054u: goto label_80061054;
    case 0x80061058u: goto label_80061058;
    case 0x8006105Cu: goto label_8006105C;
    case 0x80061060u: goto label_80061060;
    case 0x80061064u: goto label_80061064;
    case 0x80061068u: goto label_80061068;
    case 0x8006106Cu: goto label_8006106C;
    case 0x80061070u: goto label_80061070;
    case 0x80061074u: goto label_80061074;
    case 0x80061078u: goto label_80061078;
    case 0x8006107Cu: goto label_8006107C;
    case 0x80061080u: goto label_80061080;
    case 0x80061084u: goto label_80061084;
    case 0x80061088u: goto label_80061088;
    case 0x8006108Cu: goto label_8006108C;
    case 0x80061090u: goto label_80061090;
    case 0x80061094u: goto label_80061094;
    case 0x80061098u: goto label_80061098;
    case 0x8006109Cu: goto label_8006109C;
    case 0x800610A0u: goto label_800610A0;
    case 0x800610A4u: goto label_800610A4;
    case 0x800610A8u: goto label_800610A8;
    case 0x800610ACu: goto label_800610AC;
    case 0x800610B0u: goto label_800610B0;
    case 0x800610B4u: goto label_800610B4;
    case 0x800610B8u: goto label_800610B8;
    case 0x800610BCu: goto label_800610BC;
    case 0x800610C0u: goto label_800610C0;
    case 0x800610C4u: goto label_800610C4;
    case 0x800610C8u: goto label_800610C8;
    case 0x800610CCu: goto label_800610CC;
    case 0x800610D0u: goto label_800610D0;
    case 0x800610D4u: goto label_800610D4;
    case 0x800610D8u: goto label_800610D8;
    case 0x800610DCu: goto label_800610DC;
    case 0x800610E0u: goto label_800610E0;
    case 0x800610E4u: goto label_800610E4;
    case 0x800610E8u: goto label_800610E8;
    case 0x800610ECu: goto label_800610EC;
    case 0x800610F0u: goto label_800610F0;
    case 0x800610F4u: goto label_800610F4;
    case 0x800610F8u: goto label_800610F8;
    case 0x800610FCu: goto label_800610FC;
    case 0x80061100u: goto label_80061100;
    case 0x80061104u: goto label_80061104;
    case 0x80061108u: goto label_80061108;
    case 0x8006110Cu: goto label_8006110C;
    case 0x80061110u: goto label_80061110;
    case 0x80061114u: goto label_80061114;
    case 0x80061118u: goto label_80061118;
    case 0x8006111Cu: goto label_8006111C;
    case 0x80061120u: goto label_80061120;
    case 0x80061124u: goto label_80061124;
    case 0x80061128u: goto label_80061128;
    case 0x8006112Cu: goto label_8006112C;
    case 0x80061130u: goto label_80061130;
    case 0x80061134u: goto label_80061134;
    case 0x80061138u: goto label_80061138;
    case 0x8006113Cu: goto label_8006113C;
    case 0x80061140u: goto label_80061140;
    case 0x80061144u: goto label_80061144;
    case 0x80061148u: goto label_80061148;
    case 0x8006114Cu: goto label_8006114C;
    case 0x80061150u: goto label_80061150;
    case 0x80061154u: goto label_80061154;
    case 0x80061158u: goto label_80061158;
    case 0x8006115Cu: goto label_8006115C;
    case 0x80061160u: goto label_80061160;
    case 0x80061164u: goto label_80061164;
    case 0x80061168u: goto label_80061168;
    case 0x8006116Cu: goto label_8006116C;
    case 0x80061170u: goto label_80061170;
    case 0x80061174u: goto label_80061174;
    case 0x80061178u: goto label_80061178;
    case 0x8006117Cu: goto label_8006117C;
    case 0x80061180u: goto label_80061180;
    case 0x80061184u: goto label_80061184;
    case 0x80061188u: goto label_80061188;
    case 0x8006118Cu: goto label_8006118C;
    case 0x80061190u: goto label_80061190;
    case 0x80061194u: goto label_80061194;
    case 0x80061198u: goto label_80061198;
    case 0x8006119Cu: goto label_8006119C;
    case 0x800611A0u: goto label_800611A0;
    case 0x800611A4u: goto label_800611A4;
    case 0x800611A8u: goto label_800611A8;
    case 0x800611ACu: goto label_800611AC;
    case 0x800611B0u: goto label_800611B0;
    case 0x800611B4u: goto label_800611B4;
    case 0x800611B8u: goto label_800611B8;
    case 0x800611BCu: goto label_800611BC;
    case 0x800611C0u: goto label_800611C0;
    case 0x800611C4u: goto label_800611C4;
    case 0x800611C8u: goto label_800611C8;
    case 0x800611CCu: goto label_800611CC;
    case 0x800611D0u: goto label_800611D0;
    case 0x800611D4u: goto label_800611D4;
    case 0x800611D8u: goto label_800611D8;
    case 0x800611DCu: goto label_800611DC;
    case 0x800611E0u: goto label_800611E0;
    case 0x800611E4u: goto label_800611E4;
    case 0x800611E8u: goto label_800611E8;
    case 0x800611ECu: goto label_800611EC;
    case 0x800611F0u: goto label_800611F0;
    case 0x800611F4u: goto label_800611F4;
    case 0x800611F8u: goto label_800611F8;
    case 0x800611FCu: goto label_800611FC;
    case 0x80061200u: goto label_80061200;
    case 0x80061204u: goto label_80061204;
    case 0x80061208u: goto label_80061208;
    case 0x8006120Cu: goto label_8006120C;
    case 0x80061210u: goto label_80061210;
    case 0x80061214u: goto label_80061214;
    case 0x80061218u: goto label_80061218;
    case 0x8006121Cu: goto label_8006121C;
    case 0x80061220u: goto label_80061220;
    case 0x80061224u: goto label_80061224;
    case 0x80061228u: goto label_80061228;
    case 0x8006122Cu: goto label_8006122C;
    case 0x80061230u: goto label_80061230;
    case 0x80061234u: goto label_80061234;
    case 0x80061238u: goto label_80061238;
    case 0x8006123Cu: goto label_8006123C;
    case 0x80061240u: goto label_80061240;
    case 0x80061244u: goto label_80061244;
    case 0x80061248u: goto label_80061248;
    case 0x8006124Cu: goto label_8006124C;
    case 0x80061250u: goto label_80061250;
    case 0x80061254u: goto label_80061254;
    case 0x80061258u: goto label_80061258;
    case 0x8006125Cu: goto label_8006125C;
    case 0x80061260u: goto label_80061260;
    case 0x80061264u: goto label_80061264;
    case 0x80061268u: goto label_80061268;
    case 0x8006126Cu: goto label_8006126C;
    case 0x80061270u: goto label_80061270;
    case 0x80061274u: goto label_80061274;
    case 0x80061278u: goto label_80061278;
    case 0x8006127Cu: goto label_8006127C;
    case 0x80061280u: goto label_80061280;
    case 0x80061284u: goto label_80061284;
    case 0x80061288u: goto label_80061288;
    case 0x8006128Cu: goto label_8006128C;
    case 0x80061290u: goto label_80061290;
    case 0x80061294u: goto label_80061294;
    case 0x80061298u: goto label_80061298;
    case 0x8006129Cu: goto label_8006129C;
    case 0x800612A0u: goto label_800612A0;
    case 0x800612A4u: goto label_800612A4;
    case 0x800612A8u: goto label_800612A8;
    case 0x800612ACu: goto label_800612AC;
    case 0x800612B0u: goto label_800612B0;
    case 0x800612B4u: goto label_800612B4;
    case 0x800612B8u: goto label_800612B8;
    case 0x800612BCu: goto label_800612BC;
    case 0x800612C0u: goto label_800612C0;
    case 0x800612C4u: goto label_800612C4;
    case 0x800612C8u: goto label_800612C8;
    case 0x800612CCu: goto label_800612CC;
    case 0x800612D0u: goto label_800612D0;
    case 0x800612D4u: goto label_800612D4;
    case 0x800612D8u: goto label_800612D8;
    case 0x800612DCu: goto label_800612DC;
    case 0x800612E0u: goto label_800612E0;
    case 0x800612E4u: goto label_800612E4;
    case 0x800612E8u: goto label_800612E8;
    case 0x800612ECu: goto label_800612EC;
    case 0x800612F0u: goto label_800612F0;
    case 0x800612F4u: goto label_800612F4;
    case 0x800612F8u: goto label_800612F8;
    case 0x800612FCu: goto label_800612FC;
    case 0x80061300u: goto label_80061300;
    case 0x80061304u: goto label_80061304;
    case 0x80061308u: goto label_80061308;
    case 0x8006130Cu: goto label_8006130C;
    case 0x80061310u: goto label_80061310;
    case 0x80061314u: goto label_80061314;
    case 0x80061318u: goto label_80061318;
    case 0x8006131Cu: goto label_8006131C;
    case 0x80061320u: goto label_80061320;
    case 0x80061324u: goto label_80061324;
    case 0x80061328u: goto label_80061328;
    case 0x8006132Cu: goto label_8006132C;
    case 0x80061330u: goto label_80061330;
    case 0x80061334u: goto label_80061334;
    case 0x80061338u: goto label_80061338;
    case 0x8006133Cu: goto label_8006133C;
    case 0x80061340u: goto label_80061340;
    case 0x80061344u: goto label_80061344;
    case 0x80061348u: goto label_80061348;
    case 0x8006134Cu: goto label_8006134C;
    case 0x80061350u: goto label_80061350;
    case 0x80061354u: goto label_80061354;
    case 0x80061358u: goto label_80061358;
    case 0x8006135Cu: goto label_8006135C;
    case 0x80061360u: goto label_80061360;
    case 0x80061364u: goto label_80061364;
    case 0x80061368u: goto label_80061368;
    case 0x8006136Cu: goto label_8006136C;
    case 0x80061370u: goto label_80061370;
    case 0x80061374u: goto label_80061374;
    case 0x80061378u: goto label_80061378;
    case 0x8006137Cu: goto label_8006137C;
    case 0x80061380u: goto label_80061380;
    case 0x80061384u: goto label_80061384;
    case 0x80061388u: goto label_80061388;
    case 0x8006138Cu: goto label_8006138C;
    case 0x80061390u: goto label_80061390;
    case 0x80061394u: goto label_80061394;
    case 0x80061398u: goto label_80061398;
    case 0x8006139Cu: goto label_8006139C;
    case 0x800613A0u: goto label_800613A0;
    case 0x800613A4u: goto label_800613A4;
    case 0x800613A8u: goto label_800613A8;
    case 0x800613ACu: goto label_800613AC;
    case 0x800613B0u: goto label_800613B0;
    case 0x800613B4u: goto label_800613B4;
    case 0x800613B8u: goto label_800613B8;
    case 0x800613BCu: goto label_800613BC;
    case 0x800613C0u: goto label_800613C0;
    case 0x800613C4u: goto label_800613C4;
    case 0x800613C8u: goto label_800613C8;
    case 0x800613CCu: goto label_800613CC;
    case 0x800613D0u: goto label_800613D0;
    case 0x800613D4u: goto label_800613D4;
    case 0x800613D8u: goto label_800613D8;
    case 0x800613DCu: goto label_800613DC;
    case 0x800613E0u: goto label_800613E0;
    case 0x800613E4u: goto label_800613E4;
    case 0x800613E8u: goto label_800613E8;
    case 0x800613ECu: goto label_800613EC;
    case 0x800613F0u: goto label_800613F0;
    case 0x800613F4u: goto label_800613F4;
    case 0x800613F8u: goto label_800613F8;
    case 0x800613FCu: goto label_800613FC;
    case 0x80061400u: goto label_80061400;
    case 0x80061404u: goto label_80061404;
    case 0x80061408u: goto label_80061408;
    case 0x8006140Cu: goto label_8006140C;
    case 0x80061410u: goto label_80061410;
    case 0x80061414u: goto label_80061414;
    case 0x80061418u: goto label_80061418;
    case 0x8006141Cu: goto label_8006141C;
    case 0x80061420u: goto label_80061420;
    case 0x80061424u: goto label_80061424;
    case 0x80061428u: goto label_80061428;
    case 0x8006142Cu: goto label_8006142C;
    case 0x80061430u: goto label_80061430;
    case 0x80061434u: goto label_80061434;
    case 0x80061438u: goto label_80061438;
    case 0x8006143Cu: goto label_8006143C;
    case 0x80061440u: goto label_80061440;
    case 0x80061444u: goto label_80061444;
    case 0x80061448u: goto label_80061448;
    case 0x8006144Cu: goto label_8006144C;
    case 0x80061450u: goto label_80061450;
    case 0x80061454u: goto label_80061454;
    case 0x80061458u: goto label_80061458;
    case 0x8006145Cu: goto label_8006145C;
    case 0x80061460u: goto label_80061460;
    case 0x80061464u: goto label_80061464;
    case 0x80061468u: goto label_80061468;
    case 0x8006146Cu: goto label_8006146C;
    case 0x80061470u: goto label_80061470;
    case 0x80061474u: goto label_80061474;
    case 0x80061478u: goto label_80061478;
    case 0x8006147Cu: goto label_8006147C;
    case 0x80061480u: goto label_80061480;
    case 0x80061484u: goto label_80061484;
    case 0x80061488u: goto label_80061488;
    case 0x8006148Cu: goto label_8006148C;
    case 0x80061490u: goto label_80061490;
    case 0x80061494u: goto label_80061494;
    case 0x80061498u: goto label_80061498;
    case 0x8006149Cu: goto label_8006149C;
    case 0x800614A0u: goto label_800614A0;
    case 0x800614A4u: goto label_800614A4;
    case 0x800614A8u: goto label_800614A8;
    case 0x800614ACu: goto label_800614AC;
    case 0x800614B0u: goto label_800614B0;
    case 0x800614B4u: goto label_800614B4;
    case 0x800614B8u: goto label_800614B8;
    case 0x800614BCu: goto label_800614BC;
    case 0x800614C0u: goto label_800614C0;
    case 0x800614C4u: goto label_800614C4;
    case 0x800614C8u: goto label_800614C8;
    case 0x800614CCu: goto label_800614CC;
    case 0x800614D0u: goto label_800614D0;
    case 0x800614D4u: goto label_800614D4;
    case 0x800614D8u: goto label_800614D8;
    case 0x800614DCu: goto label_800614DC;
    case 0x800614E0u: goto label_800614E0;
    case 0x800614E4u: goto label_800614E4;
    case 0x800614E8u: goto label_800614E8;
    case 0x800614ECu: goto label_800614EC;
    case 0x800614F0u: goto label_800614F0;
    case 0x800614F4u: goto label_800614F4;
    case 0x800614F8u: goto label_800614F8;
    case 0x800614FCu: goto label_800614FC;
    case 0x80061500u: goto label_80061500;
    case 0x80061504u: goto label_80061504;
    case 0x80061508u: goto label_80061508;
    case 0x8006150Cu: goto label_8006150C;
    case 0x80061510u: goto label_80061510;
    case 0x80061514u: goto label_80061514;
    case 0x80061518u: goto label_80061518;
    case 0x8006151Cu: goto label_8006151C;
    case 0x80061520u: goto label_80061520;
    case 0x80061524u: goto label_80061524;
    case 0x80061528u: goto label_80061528;
    case 0x8006152Cu: goto label_8006152C;
    case 0x80061530u: goto label_80061530;
    case 0x80061534u: goto label_80061534;
    case 0x80061538u: goto label_80061538;
    case 0x8006153Cu: goto label_8006153C;
    case 0x80061540u: goto label_80061540;
    case 0x80061544u: goto label_80061544;
    case 0x80061548u: goto label_80061548;
    case 0x8006154Cu: goto label_8006154C;
    case 0x80061550u: goto label_80061550;
    case 0x80061554u: goto label_80061554;
    case 0x80061558u: goto label_80061558;
    case 0x8006155Cu: goto label_8006155C;
    case 0x80061560u: goto label_80061560;
    case 0x80061564u: goto label_80061564;
    case 0x80061568u: goto label_80061568;
    case 0x8006156Cu: goto label_8006156C;
    case 0x80061570u: goto label_80061570;
    case 0x80061574u: goto label_80061574;
    case 0x80061578u: goto label_80061578;
    case 0x8006157Cu: goto label_8006157C;
    case 0x80061580u: goto label_80061580;
    case 0x80061584u: goto label_80061584;
    case 0x80061588u: goto label_80061588;
    case 0x8006158Cu: goto label_8006158C;
    case 0x80061590u: goto label_80061590;
    case 0x80061594u: goto label_80061594;
    case 0x80061598u: goto label_80061598;
    case 0x8006159Cu: goto label_8006159C;
    case 0x800615A0u: goto label_800615A0;
    case 0x800615A4u: goto label_800615A4;
    case 0x800615A8u: goto label_800615A8;
    case 0x800615ACu: goto label_800615AC;
    case 0x800615B0u: goto label_800615B0;
    case 0x800615B4u: goto label_800615B4;
    case 0x800615B8u: goto label_800615B8;
    case 0x800615BCu: goto label_800615BC;
    case 0x800615C0u: goto label_800615C0;
    case 0x800615C4u: goto label_800615C4;
    case 0x800615C8u: goto label_800615C8;
    case 0x800615CCu: goto label_800615CC;
    case 0x800615D0u: goto label_800615D0;
    case 0x800615D4u: goto label_800615D4;
    case 0x800615D8u: goto label_800615D8;
    case 0x800615DCu: goto label_800615DC;
    case 0x800615E0u: goto label_800615E0;
    case 0x800615E4u: goto label_800615E4;
    case 0x800615E8u: goto label_800615E8;
    case 0x800615ECu: goto label_800615EC;
    case 0x800615F0u: goto label_800615F0;
    case 0x800615F4u: goto label_800615F4;
    case 0x800615F8u: goto label_800615F8;
    case 0x800615FCu: goto label_800615FC;
    case 0x80061600u: goto label_80061600;
    case 0x80061604u: goto label_80061604;
    case 0x80061608u: goto label_80061608;
    case 0x8006160Cu: goto label_8006160C;
    case 0x80061610u: goto label_80061610;
    case 0x80061614u: goto label_80061614;
    case 0x80061618u: goto label_80061618;
    case 0x8006161Cu: goto label_8006161C;
    case 0x80061620u: goto label_80061620;
    case 0x80061624u: goto label_80061624;
    case 0x80061628u: goto label_80061628;
    case 0x8006162Cu: goto label_8006162C;
    case 0x80061630u: goto label_80061630;
    case 0x80061634u: goto label_80061634;
    case 0x80061638u: goto label_80061638;
    case 0x8006163Cu: goto label_8006163C;
    case 0x80061640u: goto label_80061640;
    case 0x80061644u: goto label_80061644;
    case 0x80061648u: goto label_80061648;
    case 0x8006164Cu: goto label_8006164C;
    case 0x80061650u: goto label_80061650;
    case 0x80061654u: goto label_80061654;
    case 0x80061658u: goto label_80061658;
    case 0x8006165Cu: goto label_8006165C;
    case 0x80061660u: goto label_80061660;
    case 0x80061664u: goto label_80061664;
    case 0x80061668u: goto label_80061668;
    case 0x8006166Cu: goto label_8006166C;
    case 0x80061670u: goto label_80061670;
    case 0x80061674u: goto label_80061674;
    case 0x80061678u: goto label_80061678;
    case 0x8006167Cu: goto label_8006167C;
    case 0x80061680u: goto label_80061680;
    case 0x80061684u: goto label_80061684;
    case 0x80061688u: goto label_80061688;
    case 0x8006168Cu: goto label_8006168C;
    case 0x80061690u: goto label_80061690;
    case 0x80061694u: goto label_80061694;
    case 0x80061698u: goto label_80061698;
    case 0x8006169Cu: goto label_8006169C;
    case 0x800616A0u: goto label_800616A0;
    case 0x800616A4u: goto label_800616A4;
    case 0x800616A8u: goto label_800616A8;
    case 0x800616ACu: goto label_800616AC;
    case 0x800616B0u: goto label_800616B0;
    case 0x800616B4u: goto label_800616B4;
    case 0x800616B8u: goto label_800616B8;
    case 0x800616BCu: goto label_800616BC;
    case 0x800616C0u: goto label_800616C0;
    case 0x800616C4u: goto label_800616C4;
    case 0x800616C8u: goto label_800616C8;
    case 0x800616CCu: goto label_800616CC;
    case 0x800616D0u: goto label_800616D0;
    case 0x800616D4u: goto label_800616D4;
    case 0x800616D8u: goto label_800616D8;
    case 0x800616DCu: goto label_800616DC;
    case 0x800616E0u: goto label_800616E0;
    case 0x800616E4u: goto label_800616E4;
    case 0x800616E8u: goto label_800616E8;
    case 0x800616ECu: goto label_800616EC;
    case 0x800616F0u: goto label_800616F0;
    case 0x800616F4u: goto label_800616F4;
    case 0x800616F8u: goto label_800616F8;
    case 0x800616FCu: goto label_800616FC;
    case 0x80061700u: goto label_80061700;
    case 0x80061704u: goto label_80061704;
    case 0x80061708u: goto label_80061708;
    case 0x8006170Cu: goto label_8006170C;
    case 0x80061710u: goto label_80061710;
    case 0x80061714u: goto label_80061714;
    case 0x80061718u: goto label_80061718;
    case 0x8006171Cu: goto label_8006171C;
    case 0x80061720u: goto label_80061720;
    case 0x80061724u: goto label_80061724;
    case 0x80061728u: goto label_80061728;
    case 0x8006172Cu: goto label_8006172C;
    case 0x80061730u: goto label_80061730;
    case 0x80061734u: goto label_80061734;
    case 0x80061738u: goto label_80061738;
    case 0x8006173Cu: goto label_8006173C;
    case 0x80061740u: goto label_80061740;
    case 0x80061744u: goto label_80061744;
    case 0x80061748u: goto label_80061748;
    case 0x8006174Cu: goto label_8006174C;
    case 0x80061750u: goto label_80061750;
    case 0x80061754u: goto label_80061754;
    case 0x80061758u: goto label_80061758;
    case 0x8006175Cu: goto label_8006175C;
    case 0x80061760u: goto label_80061760;
    case 0x80061764u: goto label_80061764;
    case 0x80061768u: goto label_80061768;
    case 0x8006176Cu: goto label_8006176C;
    case 0x80061770u: goto label_80061770;
    case 0x80061774u: goto label_80061774;
    case 0x80061778u: goto label_80061778;
    case 0x8006177Cu: goto label_8006177C;
    case 0x80061780u: goto label_80061780;
    case 0x80061784u: goto label_80061784;
    case 0x80061788u: goto label_80061788;
    case 0x8006178Cu: goto label_8006178C;
    case 0x80061790u: goto label_80061790;
    case 0x80061794u: goto label_80061794;
    case 0x80061798u: goto label_80061798;
    case 0x8006179Cu: goto label_8006179C;
    case 0x800617A0u: goto label_800617A0;
    case 0x800617A4u: goto label_800617A4;
    case 0x800617A8u: goto label_800617A8;
    case 0x800617ACu: goto label_800617AC;
    case 0x800617B0u: goto label_800617B0;
    case 0x800617B4u: goto label_800617B4;
    case 0x800617B8u: goto label_800617B8;
    case 0x800617BCu: goto label_800617BC;
    case 0x800617C0u: goto label_800617C0;
    case 0x800617C4u: goto label_800617C4;
    case 0x800617C8u: goto label_800617C8;
    case 0x800617CCu: goto label_800617CC;
    case 0x800617D0u: goto label_800617D0;
    case 0x800617D4u: goto label_800617D4;
    case 0x800617D8u: goto label_800617D8;
    case 0x800617DCu: goto label_800617DC;
    case 0x800617E0u: goto label_800617E0;
    case 0x800617E4u: goto label_800617E4;
    case 0x800617E8u: goto label_800617E8;
    case 0x800617ECu: goto label_800617EC;
    case 0x800617F0u: goto label_800617F0;
    case 0x800617F4u: goto label_800617F4;
    case 0x800617F8u: goto label_800617F8;
    case 0x800617FCu: goto label_800617FC;
    case 0x80061800u: goto label_80061800;
    case 0x80061804u: goto label_80061804;
    case 0x80061808u: goto label_80061808;
    case 0x8006180Cu: goto label_8006180C;
    case 0x80061810u: goto label_80061810;
    case 0x80061814u: goto label_80061814;
    case 0x80061818u: goto label_80061818;
    case 0x8006181Cu: goto label_8006181C;
    case 0x80061820u: goto label_80061820;
    case 0x80061824u: goto label_80061824;
    case 0x80061828u: goto label_80061828;
    case 0x8006182Cu: goto label_8006182C;
    case 0x80061830u: goto label_80061830;
    case 0x80061834u: goto label_80061834;
    case 0x80061838u: goto label_80061838;
    case 0x8006183Cu: goto label_8006183C;
    case 0x80061840u: goto label_80061840;
    case 0x80061844u: goto label_80061844;
    case 0x80061848u: goto label_80061848;
    case 0x8006184Cu: goto label_8006184C;
    case 0x80061850u: goto label_80061850;
    case 0x80061854u: goto label_80061854;
    case 0x80061858u: goto label_80061858;
    case 0x8006185Cu: goto label_8006185C;
    case 0x80061860u: goto label_80061860;
    case 0x80061864u: goto label_80061864;
    case 0x80061868u: goto label_80061868;
    case 0x8006186Cu: goto label_8006186C;
    case 0x80061870u: goto label_80061870;
    case 0x80061874u: goto label_80061874;
    case 0x80061878u: goto label_80061878;
    case 0x8006187Cu: goto label_8006187C;
    case 0x80061880u: goto label_80061880;
    case 0x80061884u: goto label_80061884;
    case 0x80061888u: goto label_80061888;
    case 0x8006188Cu: goto label_8006188C;
    case 0x80061890u: goto label_80061890;
    case 0x80061894u: goto label_80061894;
    case 0x80061898u: goto label_80061898;
    case 0x8006189Cu: goto label_8006189C;
    case 0x800618A0u: goto label_800618A0;
    case 0x800618A4u: goto label_800618A4;
    case 0x800618A8u: goto label_800618A8;
    case 0x800618ACu: goto label_800618AC;
    case 0x800618B0u: goto label_800618B0;
    case 0x800618B4u: goto label_800618B4;
    case 0x800618B8u: goto label_800618B8;
    case 0x800618BCu: goto label_800618BC;
    case 0x800618C0u: goto label_800618C0;
    case 0x800618C4u: goto label_800618C4;
    case 0x800618C8u: goto label_800618C8;
    case 0x800618CCu: goto label_800618CC;
    case 0x800618D0u: goto label_800618D0;
    case 0x800618D4u: goto label_800618D4;
    case 0x800618D8u: goto label_800618D8;
    case 0x800618DCu: goto label_800618DC;
    case 0x800618E0u: goto label_800618E0;
    case 0x800618E4u: goto label_800618E4;
    case 0x800618E8u: goto label_800618E8;
    case 0x800618ECu: goto label_800618EC;
    case 0x800618F0u: goto label_800618F0;
    case 0x800618F4u: goto label_800618F4;
    case 0x800618F8u: goto label_800618F8;
    case 0x800618FCu: goto label_800618FC;
    case 0x80061900u: goto label_80061900;
    case 0x80061904u: goto label_80061904;
    case 0x80061908u: goto label_80061908;
    case 0x8006190Cu: goto label_8006190C;
    case 0x80061910u: goto label_80061910;
    case 0x80061914u: goto label_80061914;
    case 0x80061918u: goto label_80061918;
    case 0x8006191Cu: goto label_8006191C;
    case 0x80061920u: goto label_80061920;
    case 0x80061924u: goto label_80061924;
    case 0x80061928u: goto label_80061928;
    case 0x8006192Cu: goto label_8006192C;
    case 0x80061930u: goto label_80061930;
    case 0x80061934u: goto label_80061934;
    case 0x80061938u: goto label_80061938;
    case 0x8006193Cu: goto label_8006193C;
    case 0x80061940u: goto label_80061940;
    case 0x80061944u: goto label_80061944;
    case 0x80061948u: goto label_80061948;
    case 0x8006194Cu: goto label_8006194C;
    case 0x80061950u: goto label_80061950;
    case 0x80061954u: goto label_80061954;
    case 0x80061958u: goto label_80061958;
    case 0x8006195Cu: goto label_8006195C;
    case 0x80061960u: goto label_80061960;
    case 0x80061964u: goto label_80061964;
    case 0x80061968u: goto label_80061968;
    case 0x8006196Cu: goto label_8006196C;
    case 0x80061970u: goto label_80061970;
    case 0x80061974u: goto label_80061974;
    case 0x80061978u: goto label_80061978;
    case 0x8006197Cu: goto label_8006197C;
    case 0x80061980u: goto label_80061980;
    case 0x80061984u: goto label_80061984;
    case 0x80061988u: goto label_80061988;
    case 0x8006198Cu: goto label_8006198C;
    case 0x80061990u: goto label_80061990;
    case 0x80061994u: goto label_80061994;
    case 0x80061998u: goto label_80061998;
    case 0x8006199Cu: goto label_8006199C;
    case 0x800619A0u: goto label_800619A0;
    case 0x800619A4u: goto label_800619A4;
    case 0x800619A8u: goto label_800619A8;
    case 0x800619ACu: goto label_800619AC;
    case 0x800619B0u: goto label_800619B0;
    case 0x800619B4u: goto label_800619B4;
    case 0x800619B8u: goto label_800619B8;
    case 0x800619BCu: goto label_800619BC;
    case 0x800619C0u: goto label_800619C0;
    case 0x800619C4u: goto label_800619C4;
    case 0x800619C8u: goto label_800619C8;
    case 0x800619CCu: goto label_800619CC;
    case 0x800619D0u: goto label_800619D0;
    case 0x800619D4u: goto label_800619D4;
    case 0x800619D8u: goto label_800619D8;
    case 0x800619DCu: goto label_800619DC;
    case 0x800619E0u: goto label_800619E0;
    case 0x800619E4u: goto label_800619E4;
    case 0x800619E8u: goto label_800619E8;
    case 0x800619ECu: goto label_800619EC;
    case 0x800619F0u: goto label_800619F0;
    case 0x800619F4u: goto label_800619F4;
    case 0x800619F8u: goto label_800619F8;
    case 0x800619FCu: goto label_800619FC;
    case 0x80061A00u: goto label_80061A00;
    case 0x80061A04u: goto label_80061A04;
    case 0x80061A08u: goto label_80061A08;
    case 0x80061A0Cu: goto label_80061A0C;
    case 0x80061A10u: goto label_80061A10;
    case 0x80061A14u: goto label_80061A14;
    case 0x80061A18u: goto label_80061A18;
    case 0x80061A1Cu: goto label_80061A1C;
    case 0x80061A20u: goto label_80061A20;
    case 0x80061A24u: goto label_80061A24;
    case 0x80061A28u: goto label_80061A28;
    case 0x80061A2Cu: goto label_80061A2C;
    case 0x80061A30u: goto label_80061A30;
    case 0x80061A34u: goto label_80061A34;
    case 0x80061A38u: goto label_80061A38;
    case 0x80061A3Cu: goto label_80061A3C;
    case 0x80061A40u: goto label_80061A40;
    case 0x80061A44u: goto label_80061A44;
    case 0x80061A48u: goto label_80061A48;
    case 0x80061A4Cu: goto label_80061A4C;
    case 0x80061A50u: goto label_80061A50;
    case 0x80061A54u: goto label_80061A54;
    case 0x80061A58u: goto label_80061A58;
    case 0x80061A5Cu: goto label_80061A5C;
    case 0x80061A60u: goto label_80061A60;
    case 0x80061A64u: goto label_80061A64;
    case 0x80061A68u: goto label_80061A68;
    case 0x80061A6Cu: goto label_80061A6C;
    case 0x80061A70u: goto label_80061A70;
    case 0x80061A74u: goto label_80061A74;
    case 0x80061A78u: goto label_80061A78;
    case 0x80061A7Cu: goto label_80061A7C;
    case 0x80061A80u: goto label_80061A80;
    case 0x80061A84u: goto label_80061A84;
    case 0x80061A88u: goto label_80061A88;
    case 0x80061A8Cu: goto label_80061A8C;
    case 0x80061A90u: goto label_80061A90;
    case 0x80061A94u: goto label_80061A94;
    case 0x80061A98u: goto label_80061A98;
    case 0x80061A9Cu: goto label_80061A9C;
    case 0x80061AA0u: goto label_80061AA0;
    case 0x80061AA4u: goto label_80061AA4;
    case 0x80061AA8u: goto label_80061AA8;
    case 0x80061AACu: goto label_80061AAC;
    case 0x80061AB0u: goto label_80061AB0;
    case 0x80061AB4u: goto label_80061AB4;
    case 0x80061AB8u: goto label_80061AB8;
    case 0x80061ABCu: goto label_80061ABC;
    case 0x80061AC0u: goto label_80061AC0;
    case 0x80061AC4u: goto label_80061AC4;
    case 0x80061AC8u: goto label_80061AC8;
    case 0x80061ACCu: goto label_80061ACC;
    case 0x80061AD0u: goto label_80061AD0;
    case 0x80061AD4u: goto label_80061AD4;
    case 0x80061AD8u: goto label_80061AD8;
    case 0x80061ADCu: goto label_80061ADC;
    case 0x80061AE0u: goto label_80061AE0;
    case 0x80061AE4u: goto label_80061AE4;
    case 0x80061AE8u: goto label_80061AE8;
    case 0x80061AECu: goto label_80061AEC;
    case 0x80061AF0u: goto label_80061AF0;
    case 0x80061AF4u: goto label_80061AF4;
    case 0x80061AF8u: goto label_80061AF8;
    case 0x80061AFCu: goto label_80061AFC;
    case 0x80061B00u: goto label_80061B00;
    case 0x80061B04u: goto label_80061B04;
    case 0x80061B08u: goto label_80061B08;
    case 0x80061B0Cu: goto label_80061B0C;
    case 0x80061B10u: goto label_80061B10;
    case 0x80061B14u: goto label_80061B14;
    case 0x80061B18u: goto label_80061B18;
    case 0x80061B1Cu: goto label_80061B1C;
    case 0x80061B20u: goto label_80061B20;
    case 0x80061B24u: goto label_80061B24;
    case 0x80061B28u: goto label_80061B28;
    case 0x80061B2Cu: goto label_80061B2C;
    case 0x80061B30u: goto label_80061B30;
    case 0x80061B34u: goto label_80061B34;
    case 0x80061B38u: goto label_80061B38;
    case 0x80061B3Cu: goto label_80061B3C;
    case 0x80061B40u: goto label_80061B40;
    case 0x80061B44u: goto label_80061B44;
    case 0x80061B48u: goto label_80061B48;
    case 0x80061B4Cu: goto label_80061B4C;
    case 0x80061B50u: goto label_80061B50;
    case 0x80061B54u: goto label_80061B54;
    case 0x80061B58u: goto label_80061B58;
    case 0x80061B5Cu: goto label_80061B5C;
    case 0x80061B60u: goto label_80061B60;
    case 0x80061B64u: goto label_80061B64;
    case 0x80061B68u: goto label_80061B68;
    case 0x80061B6Cu: goto label_80061B6C;
    case 0x80061B70u: goto label_80061B70;
    case 0x80061B74u: goto label_80061B74;
    case 0x80061B78u: goto label_80061B78;
    case 0x80061B7Cu: goto label_80061B7C;
    case 0x80061B80u: goto label_80061B80;
    case 0x80061B84u: goto label_80061B84;
    case 0x80061B88u: goto label_80061B88;
    case 0x80061B8Cu: goto label_80061B8C;
    case 0x80061B90u: goto label_80061B90;
    case 0x80061B94u: goto label_80061B94;
    case 0x80061B98u: goto label_80061B98;
    case 0x80061B9Cu: goto label_80061B9C;
    case 0x80061BA0u: goto label_80061BA0;
    case 0x80061BA4u: goto label_80061BA4;
    case 0x80061BA8u: goto label_80061BA8;
    case 0x80061BACu: goto label_80061BAC;
    case 0x80061BB0u: goto label_80061BB0;
    case 0x80061BB4u: goto label_80061BB4;
    case 0x80061BB8u: goto label_80061BB8;
    case 0x80061BBCu: goto label_80061BBC;
    case 0x80061BC0u: goto label_80061BC0;
    case 0x80061BC4u: goto label_80061BC4;
    case 0x80061BC8u: goto label_80061BC8;
    case 0x80061BCCu: goto label_80061BCC;
    case 0x80061BD0u: goto label_80061BD0;
    case 0x80061BD4u: goto label_80061BD4;
    case 0x80061BD8u: goto label_80061BD8;
    case 0x80061BDCu: goto label_80061BDC;
    case 0x80061BE0u: goto label_80061BE0;
    case 0x80061BE4u: goto label_80061BE4;
    case 0x80061BE8u: goto label_80061BE8;
    case 0x80061BECu: goto label_80061BEC;
    case 0x80061BF0u: goto label_80061BF0;
    case 0x80061BF4u: goto label_80061BF4;
    case 0x80061BF8u: goto label_80061BF8;
    case 0x80061BFCu: goto label_80061BFC;
    case 0x80061C00u: goto label_80061C00;
    case 0x80061C04u: goto label_80061C04;
    case 0x80061C08u: goto label_80061C08;
    case 0x80061C0Cu: goto label_80061C0C;
    case 0x80061C10u: goto label_80061C10;
    case 0x80061C14u: goto label_80061C14;
    case 0x80061C18u: goto label_80061C18;
    case 0x80061C1Cu: goto label_80061C1C;
    case 0x80061C20u: goto label_80061C20;
    case 0x80061C24u: goto label_80061C24;
    case 0x80061C28u: goto label_80061C28;
    case 0x80061C2Cu: goto label_80061C2C;
    case 0x80061C30u: goto label_80061C30;
    case 0x80061C34u: goto label_80061C34;
    case 0x80061C38u: goto label_80061C38;
    case 0x80061C3Cu: goto label_80061C3C;
    case 0x80061C40u: goto label_80061C40;
    case 0x80061C44u: goto label_80061C44;
    case 0x80061C48u: goto label_80061C48;
    case 0x80061C4Cu: goto label_80061C4C;
    case 0x80061C50u: goto label_80061C50;
    case 0x80061C54u: goto label_80061C54;
    case 0x80061C58u: goto label_80061C58;
    case 0x80061C5Cu: goto label_80061C5C;
    case 0x80061C60u: goto label_80061C60;
    case 0x80061C64u: goto label_80061C64;
    case 0x80061C68u: goto label_80061C68;
    case 0x80061C6Cu: goto label_80061C6C;
    case 0x80061C70u: goto label_80061C70;
    case 0x80061C74u: goto label_80061C74;
    case 0x80061C78u: goto label_80061C78;
    case 0x80061C7Cu: goto label_80061C7C;
    case 0x80061C80u: goto label_80061C80;
    case 0x80061C84u: goto label_80061C84;
    case 0x80061C88u: goto label_80061C88;
    case 0x80061C8Cu: goto label_80061C8C;
    case 0x80061C90u: goto label_80061C90;
    case 0x80061C94u: goto label_80061C94;
    case 0x80061C98u: goto label_80061C98;
    case 0x80061C9Cu: goto label_80061C9C;
    case 0x80061CA0u: goto label_80061CA0;
    case 0x80061CA4u: goto label_80061CA4;
    case 0x80061CA8u: goto label_80061CA8;
    case 0x80061CACu: goto label_80061CAC;
    case 0x80061CB0u: goto label_80061CB0;
    case 0x80061CB4u: goto label_80061CB4;
    case 0x80061CB8u: goto label_80061CB8;
    case 0x80061CBCu: goto label_80061CBC;
    case 0x80061CC0u: goto label_80061CC0;
    case 0x80061CC4u: goto label_80061CC4;
    case 0x80061CC8u: goto label_80061CC8;
    case 0x80061CCCu: goto label_80061CCC;
    case 0x80061CD0u: goto label_80061CD0;
    case 0x80061CD4u: goto label_80061CD4;
    case 0x80061CD8u: goto label_80061CD8;
    case 0x80061CDCu: goto label_80061CDC;
    case 0x80061CE0u: goto label_80061CE0;
    case 0x80061CE4u: goto label_80061CE4;
    case 0x80061CE8u: goto label_80061CE8;
    case 0x80061CECu: goto label_80061CEC;
    case 0x80061CF0u: goto label_80061CF0;
    case 0x80061CF4u: goto label_80061CF4;
    case 0x80061CF8u: goto label_80061CF8;
    case 0x80061CFCu: goto label_80061CFC;
    case 0x80061D00u: goto label_80061D00;
    case 0x80061D04u: goto label_80061D04;
    case 0x80061D08u: goto label_80061D08;
    case 0x80061D0Cu: goto label_80061D0C;
    case 0x80061D10u: goto label_80061D10;
    case 0x80061D14u: goto label_80061D14;
    case 0x80061D18u: goto label_80061D18;
    case 0x80061D1Cu: goto label_80061D1C;
    case 0x80061D20u: goto label_80061D20;
    case 0x80061D24u: goto label_80061D24;
    case 0x80061D28u: goto label_80061D28;
    case 0x80061D2Cu: goto label_80061D2C;
    case 0x80061D30u: goto label_80061D30;
    case 0x80061D34u: goto label_80061D34;
    case 0x80061D38u: goto label_80061D38;
    case 0x80061D3Cu: goto label_80061D3C;
    case 0x80061D40u: goto label_80061D40;
    case 0x80061D44u: goto label_80061D44;
    case 0x80061D48u: goto label_80061D48;
    case 0x80061D4Cu: goto label_80061D4C;
    case 0x80061D50u: goto label_80061D50;
    case 0x80061D54u: goto label_80061D54;
    case 0x80061D58u: goto label_80061D58;
    case 0x80061D5Cu: goto label_80061D5C;
    case 0x80061D60u: goto label_80061D60;
    case 0x80061D64u: goto label_80061D64;
    case 0x80061D68u: goto label_80061D68;
    case 0x80061D6Cu: goto label_80061D6C;
    case 0x80061D70u: goto label_80061D70;
    case 0x80061D74u: goto label_80061D74;
    case 0x80061D78u: goto label_80061D78;
    case 0x80061D7Cu: goto label_80061D7C;
    case 0x80061D80u: goto label_80061D80;
    case 0x80061D84u: goto label_80061D84;
    case 0x80061D88u: goto label_80061D88;
    case 0x80061D8Cu: goto label_80061D8C;
    case 0x80061D90u: goto label_80061D90;
    case 0x80061D94u: goto label_80061D94;
    case 0x80061D98u: goto label_80061D98;
    case 0x80061D9Cu: goto label_80061D9C;
    case 0x80061DA0u: goto label_80061DA0;
    case 0x80061DA4u: goto label_80061DA4;
    case 0x80061DA8u: goto label_80061DA8;
    case 0x80061DACu: goto label_80061DAC;
    case 0x80061DB0u: goto label_80061DB0;
    case 0x80061DB4u: goto label_80061DB4;
    case 0x80061DB8u: goto label_80061DB8;
    case 0x80061DBCu: goto label_80061DBC;
    case 0x80061DC0u: goto label_80061DC0;
    case 0x80061DC4u: goto label_80061DC4;
    case 0x80061DC8u: goto label_80061DC8;
    case 0x80061DCCu: goto label_80061DCC;
    case 0x80061DD0u: goto label_80061DD0;
    case 0x80061DD4u: goto label_80061DD4;
    case 0x80061DD8u: goto label_80061DD8;
    case 0x80061DDCu: goto label_80061DDC;
    case 0x80061DE0u: goto label_80061DE0;
    case 0x80061DE4u: goto label_80061DE4;
    case 0x80061DE8u: goto label_80061DE8;
    case 0x80061DECu: goto label_80061DEC;
    case 0x80061DF0u: goto label_80061DF0;
    case 0x80061DF4u: goto label_80061DF4;
    case 0x80061DF8u: goto label_80061DF8;
    case 0x80061DFCu: goto label_80061DFC;
    case 0x80061E00u: goto label_80061E00;
    case 0x80061E04u: goto label_80061E04;
    case 0x80061E08u: goto label_80061E08;
    case 0x80061E0Cu: goto label_80061E0C;
    case 0x80061E10u: goto label_80061E10;
    case 0x80061E14u: goto label_80061E14;
    case 0x80061E18u: goto label_80061E18;
    case 0x80061E1Cu: goto label_80061E1C;
    case 0x80061E20u: goto label_80061E20;
    case 0x80061E24u: goto label_80061E24;
    case 0x80061E28u: goto label_80061E28;
    case 0x80061E2Cu: goto label_80061E2C;
    case 0x80061E30u: goto label_80061E30;
    case 0x80061E34u: goto label_80061E34;
    case 0x80061E38u: goto label_80061E38;
    case 0x80061E3Cu: goto label_80061E3C;
    case 0x80061E40u: goto label_80061E40;
    case 0x80061E44u: goto label_80061E44;
    case 0x80061E48u: goto label_80061E48;
    case 0x80061E4Cu: goto label_80061E4C;
    case 0x80061E50u: goto label_80061E50;
    case 0x80061E54u: goto label_80061E54;
    case 0x80061E58u: goto label_80061E58;
    case 0x80061E5Cu: goto label_80061E5C;
    case 0x80061E60u: goto label_80061E60;
    case 0x80061E64u: goto label_80061E64;
    case 0x80061E68u: goto label_80061E68;
    case 0x80061E6Cu: goto label_80061E6C;
    case 0x80061E70u: goto label_80061E70;
    case 0x80061E74u: goto label_80061E74;
    case 0x80061E78u: goto label_80061E78;
    case 0x80061E7Cu: goto label_80061E7C;
    case 0x80061E80u: goto label_80061E80;
    case 0x80061E84u: goto label_80061E84;
    case 0x80061E88u: goto label_80061E88;
    case 0x80061E8Cu: goto label_80061E8C;
    case 0x80061E90u: goto label_80061E90;
    case 0x80061E94u: goto label_80061E94;
    case 0x80061E98u: goto label_80061E98;
    case 0x80061E9Cu: goto label_80061E9C;
    case 0x80061EA0u: goto label_80061EA0;
    case 0x80061EA4u: goto label_80061EA4;
    case 0x80061EA8u: goto label_80061EA8;
    case 0x80061EACu: goto label_80061EAC;
    case 0x80061EB0u: goto label_80061EB0;
    case 0x80061EB4u: goto label_80061EB4;
    case 0x80061EB8u: goto label_80061EB8;
    case 0x80061EBCu: goto label_80061EBC;
    case 0x80061EC0u: goto label_80061EC0;
    case 0x80061EC4u: goto label_80061EC4;
    case 0x80061EC8u: goto label_80061EC8;
    case 0x80061ECCu: goto label_80061ECC;
    case 0x80061ED0u: goto label_80061ED0;
    case 0x80061ED4u: goto label_80061ED4;
    case 0x80061ED8u: goto label_80061ED8;
    case 0x80061EDCu: goto label_80061EDC;
    case 0x80061EE0u: goto label_80061EE0;
    case 0x80061EE4u: goto label_80061EE4;
    case 0x80061EE8u: goto label_80061EE8;
    case 0x80061EECu: goto label_80061EEC;
    case 0x80061EF0u: goto label_80061EF0;
    case 0x80061EF4u: goto label_80061EF4;
    case 0x80061EF8u: goto label_80061EF8;
    case 0x80061EFCu: goto label_80061EFC;
    case 0x80061F00u: goto label_80061F00;
    case 0x80061F04u: goto label_80061F04;
    case 0x80061F08u: goto label_80061F08;
    case 0x80061F0Cu: goto label_80061F0C;
    case 0x80061F10u: goto label_80061F10;
    case 0x80061F14u: goto label_80061F14;
    case 0x80061F18u: goto label_80061F18;
    case 0x80061F1Cu: goto label_80061F1C;
    case 0x80061F20u: goto label_80061F20;
    case 0x80061F24u: goto label_80061F24;
    case 0x80061F28u: goto label_80061F28;
    case 0x80061F2Cu: goto label_80061F2C;
    case 0x80061F30u: goto label_80061F30;
    case 0x80061F34u: goto label_80061F34;
    case 0x80061F38u: goto label_80061F38;
    case 0x80061F3Cu: goto label_80061F3C;
    case 0x80061F40u: goto label_80061F40;
    case 0x80061F44u: goto label_80061F44;
    case 0x80061F48u: goto label_80061F48;
    case 0x80061F4Cu: goto label_80061F4C;
    case 0x80061F50u: goto label_80061F50;
    case 0x80061F54u: goto label_80061F54;
    case 0x80061F58u: goto label_80061F58;
    case 0x80061F5Cu: goto label_80061F5C;
    case 0x80061F60u: goto label_80061F60;
    case 0x80061F64u: goto label_80061F64;
    case 0x80061F68u: goto label_80061F68;
    case 0x80061F6Cu: goto label_80061F6C;
    case 0x80061F70u: goto label_80061F70;
    case 0x80061F74u: goto label_80061F74;
    case 0x80061F78u: goto label_80061F78;
    case 0x80061F7Cu: goto label_80061F7C;
    case 0x80061F80u: goto label_80061F80;
    case 0x80061F84u: goto label_80061F84;
    case 0x80061F88u: goto label_80061F88;
    case 0x80061F8Cu: goto label_80061F8C;
    case 0x80061F90u: goto label_80061F90;
    case 0x80061F94u: goto label_80061F94;
    case 0x80061F98u: goto label_80061F98;
    case 0x80061F9Cu: goto label_80061F9C;
    case 0x80061FA0u: goto label_80061FA0;
    case 0x80061FA4u: goto label_80061FA4;
    case 0x80061FA8u: goto label_80061FA8;
    case 0x80061FACu: goto label_80061FAC;
    case 0x80061FB0u: goto label_80061FB0;
    case 0x80061FB4u: goto label_80061FB4;
    case 0x80061FB8u: goto label_80061FB8;
    case 0x80061FBCu: goto label_80061FBC;
    case 0x80061FC0u: goto label_80061FC0;
    case 0x80061FC4u: goto label_80061FC4;
    case 0x80061FC8u: goto label_80061FC8;
    case 0x80061FCCu: goto label_80061FCC;
    case 0x80061FD0u: goto label_80061FD0;
    case 0x80061FD4u: goto label_80061FD4;
    case 0x80061FD8u: goto label_80061FD8;
    case 0x80061FDCu: goto label_80061FDC;
    case 0x80061FE0u: goto label_80061FE0;
    case 0x80061FE4u: goto label_80061FE4;
    case 0x80061FE8u: goto label_80061FE8;
    case 0x80061FECu: goto label_80061FEC;
    case 0x80061FF0u: goto label_80061FF0;
    case 0x80061FF4u: goto label_80061FF4;
    case 0x80061FF8u: goto label_80061FF8;
    case 0x80061FFCu: goto label_80061FFC;
    case 0x80062000u: goto label_80062000;
    case 0x80062004u: goto label_80062004;
    case 0x80062008u: goto label_80062008;
    case 0x8006200Cu: goto label_8006200C;
    case 0x80062010u: goto label_80062010;
    case 0x80062014u: goto label_80062014;
    case 0x80062018u: goto label_80062018;
    case 0x8006201Cu: goto label_8006201C;
    case 0x80062020u: goto label_80062020;
    case 0x80062024u: goto label_80062024;
    case 0x80062028u: goto label_80062028;
    case 0x8006202Cu: goto label_8006202C;
    case 0x80062030u: goto label_80062030;
    case 0x80062034u: goto label_80062034;
    case 0x80062038u: goto label_80062038;
    case 0x8006203Cu: goto label_8006203C;
    case 0x80062040u: goto label_80062040;
    case 0x80062044u: goto label_80062044;
    case 0x80062048u: goto label_80062048;
    case 0x8006204Cu: goto label_8006204C;
    case 0x80062050u: goto label_80062050;
    case 0x80062054u: goto label_80062054;
    case 0x80062058u: goto label_80062058;
    case 0x8006205Cu: goto label_8006205C;
    case 0x80062060u: goto label_80062060;
    case 0x80062064u: goto label_80062064;
    case 0x80062068u: goto label_80062068;
    case 0x8006206Cu: goto label_8006206C;
    case 0x80062070u: goto label_80062070;
    case 0x80062074u: goto label_80062074;
    case 0x80062078u: goto label_80062078;
    case 0x8006207Cu: goto label_8006207C;
    case 0x80062080u: goto label_80062080;
    case 0x80062084u: goto label_80062084;
    case 0x80062088u: goto label_80062088;
    case 0x8006208Cu: goto label_8006208C;
    case 0x80062090u: goto label_80062090;
    case 0x80062094u: goto label_80062094;
    case 0x80062098u: goto label_80062098;
    case 0x8006209Cu: goto label_8006209C;
    case 0x800620A0u: goto label_800620A0;
    case 0x800620A4u: goto label_800620A4;
    case 0x800620A8u: goto label_800620A8;
    case 0x800620ACu: goto label_800620AC;
    case 0x800620B0u: goto label_800620B0;
    case 0x800620B4u: goto label_800620B4;
    case 0x800620B8u: goto label_800620B8;
    case 0x800620BCu: goto label_800620BC;
    case 0x800620C0u: goto label_800620C0;
    case 0x800620C4u: goto label_800620C4;
    case 0x800620C8u: goto label_800620C8;
    case 0x800620CCu: goto label_800620CC;
    case 0x800620D0u: goto label_800620D0;
    case 0x800620D4u: goto label_800620D4;
    case 0x800620D8u: goto label_800620D8;
    case 0x800620DCu: goto label_800620DC;
    case 0x800620E0u: goto label_800620E0;
    case 0x800620E4u: goto label_800620E4;
    case 0x800620E8u: goto label_800620E8;
    case 0x800620ECu: goto label_800620EC;
    case 0x800620F0u: goto label_800620F0;
    case 0x800620F4u: goto label_800620F4;
    case 0x800620F8u: goto label_800620F8;
    case 0x800620FCu: goto label_800620FC;
    case 0x80062100u: goto label_80062100;
    case 0x80062104u: goto label_80062104;
    case 0x80062108u: goto label_80062108;
    case 0x8006210Cu: goto label_8006210C;
    case 0x80062110u: goto label_80062110;
    case 0x80062114u: goto label_80062114;
    case 0x80062118u: goto label_80062118;
    case 0x8006211Cu: goto label_8006211C;
    case 0x80062120u: goto label_80062120;
    case 0x80062124u: goto label_80062124;
    case 0x80062128u: goto label_80062128;
    case 0x8006212Cu: goto label_8006212C;
    case 0x80062130u: goto label_80062130;
    case 0x80062134u: goto label_80062134;
    case 0x80062138u: goto label_80062138;
    case 0x8006213Cu: goto label_8006213C;
    case 0x80062140u: goto label_80062140;
    case 0x80062144u: goto label_80062144;
    case 0x80062148u: goto label_80062148;
    case 0x8006214Cu: goto label_8006214C;
    case 0x80062150u: goto label_80062150;
    case 0x80062154u: goto label_80062154;
    case 0x80062158u: goto label_80062158;
    case 0x8006215Cu: goto label_8006215C;
    case 0x80062160u: goto label_80062160;
    case 0x80062164u: goto label_80062164;
    case 0x80062168u: goto label_80062168;
    case 0x8006216Cu: goto label_8006216C;
    case 0x80062170u: goto label_80062170;
    case 0x80062174u: goto label_80062174;
    case 0x80062178u: goto label_80062178;
    case 0x8006217Cu: goto label_8006217C;
    case 0x80062180u: goto label_80062180;
    case 0x80062184u: goto label_80062184;
    case 0x80062188u: goto label_80062188;
    case 0x8006218Cu: goto label_8006218C;
    case 0x80062190u: goto label_80062190;
    case 0x80062194u: goto label_80062194;
    case 0x80062198u: goto label_80062198;
    case 0x8006219Cu: goto label_8006219C;
    case 0x800621A0u: goto label_800621A0;
    case 0x800621A4u: goto label_800621A4;
    case 0x800621A8u: goto label_800621A8;
    case 0x800621ACu: goto label_800621AC;
    case 0x800621B0u: goto label_800621B0;
    case 0x800621B4u: goto label_800621B4;
    case 0x800621B8u: goto label_800621B8;
    case 0x800621BCu: goto label_800621BC;
    case 0x800621C0u: goto label_800621C0;
    case 0x800621C4u: goto label_800621C4;
    case 0x800621C8u: goto label_800621C8;
    case 0x800621CCu: goto label_800621CC;
    case 0x800621D0u: goto label_800621D0;
    case 0x800621D4u: goto label_800621D4;
    case 0x800621D8u: goto label_800621D8;
    case 0x800621DCu: goto label_800621DC;
    case 0x800621E0u: goto label_800621E0;
    case 0x800621E4u: goto label_800621E4;
    case 0x800621E8u: goto label_800621E8;
    case 0x800621ECu: goto label_800621EC;
    case 0x800621F0u: goto label_800621F0;
    case 0x800621F4u: goto label_800621F4;
    case 0x800621F8u: goto label_800621F8;
    case 0x800621FCu: goto label_800621FC;
    case 0x80062200u: goto label_80062200;
    case 0x80062204u: goto label_80062204;
    case 0x80062208u: goto label_80062208;
    case 0x8006220Cu: goto label_8006220C;
    case 0x80062210u: goto label_80062210;
    case 0x80062214u: goto label_80062214;
    case 0x80062218u: goto label_80062218;
    case 0x8006221Cu: goto label_8006221C;
    case 0x80062220u: goto label_80062220;
    case 0x80062224u: goto label_80062224;
    case 0x80062228u: goto label_80062228;
    case 0x8006222Cu: goto label_8006222C;
    case 0x80062230u: goto label_80062230;
    case 0x80062234u: goto label_80062234;
    case 0x80062238u: goto label_80062238;
    case 0x8006223Cu: goto label_8006223C;
    case 0x80062240u: goto label_80062240;
    case 0x80062244u: goto label_80062244;
    case 0x80062248u: goto label_80062248;
    case 0x8006224Cu: goto label_8006224C;
    case 0x80062250u: goto label_80062250;
    case 0x80062254u: goto label_80062254;
    case 0x80062258u: goto label_80062258;
    case 0x8006225Cu: goto label_8006225C;
    case 0x80062260u: goto label_80062260;
    case 0x80062264u: goto label_80062264;
    case 0x80062268u: goto label_80062268;
    case 0x8006226Cu: goto label_8006226C;
    case 0x80062270u: goto label_80062270;
    case 0x80062274u: goto label_80062274;
    case 0x80062278u: goto label_80062278;
    case 0x8006227Cu: goto label_8006227C;
    case 0x80062280u: goto label_80062280;
    case 0x80062284u: goto label_80062284;
    case 0x80062288u: goto label_80062288;
    case 0x8006228Cu: goto label_8006228C;
    case 0x80062290u: goto label_80062290;
    case 0x80062294u: goto label_80062294;
    case 0x80062298u: goto label_80062298;
    case 0x8006229Cu: goto label_8006229C;
    case 0x800622A0u: goto label_800622A0;
    case 0x800622A4u: goto label_800622A4;
    case 0x800622A8u: goto label_800622A8;
    case 0x800622ACu: goto label_800622AC;
    case 0x800622B0u: goto label_800622B0;
    case 0x800622B4u: goto label_800622B4;
    case 0x800622B8u: goto label_800622B8;
    case 0x800622BCu: goto label_800622BC;
    case 0x800622C0u: goto label_800622C0;
    case 0x800622C4u: goto label_800622C4;
    case 0x800622C8u: goto label_800622C8;
    case 0x800622CCu: goto label_800622CC;
    case 0x800622D0u: goto label_800622D0;
    case 0x800622D4u: goto label_800622D4;
    case 0x800622D8u: goto label_800622D8;
    case 0x800622DCu: goto label_800622DC;
    case 0x800622E0u: goto label_800622E0;
    case 0x800622E4u: goto label_800622E4;
    case 0x800622E8u: goto label_800622E8;
    case 0x800622ECu: goto label_800622EC;
    case 0x800622F0u: goto label_800622F0;
    case 0x800622F4u: goto label_800622F4;
    case 0x800622F8u: goto label_800622F8;
    case 0x800622FCu: goto label_800622FC;
    case 0x80062300u: goto label_80062300;
    case 0x80062304u: goto label_80062304;
    case 0x80062308u: goto label_80062308;
    case 0x8006230Cu: goto label_8006230C;
    case 0x80062310u: goto label_80062310;
    case 0x80062314u: goto label_80062314;
    case 0x80062318u: goto label_80062318;
    case 0x8006231Cu: goto label_8006231C;
    case 0x80062320u: goto label_80062320;
    case 0x80062324u: goto label_80062324;
    case 0x80062328u: goto label_80062328;
    case 0x8006232Cu: goto label_8006232C;
    case 0x80062330u: goto label_80062330;
    case 0x80062334u: goto label_80062334;
    case 0x80062338u: goto label_80062338;
    case 0x8006233Cu: goto label_8006233C;
    case 0x80062340u: goto label_80062340;
    case 0x80062344u: goto label_80062344;
    case 0x80062348u: goto label_80062348;
    case 0x8006234Cu: goto label_8006234C;
    case 0x80062350u: goto label_80062350;
    case 0x80062354u: goto label_80062354;
    case 0x80062358u: goto label_80062358;
    case 0x8006235Cu: goto label_8006235C;
    case 0x80062360u: goto label_80062360;
    case 0x80062364u: goto label_80062364;
    case 0x80062368u: goto label_80062368;
    case 0x8006236Cu: goto label_8006236C;
    case 0x80062370u: goto label_80062370;
    case 0x80062374u: goto label_80062374;
    case 0x80062378u: goto label_80062378;
    case 0x8006237Cu: goto label_8006237C;
    case 0x80062380u: goto label_80062380;
    case 0x80062384u: goto label_80062384;
    case 0x80062388u: goto label_80062388;
    case 0x8006238Cu: goto label_8006238C;
    case 0x80062390u: goto label_80062390;
    case 0x80062394u: goto label_80062394;
    case 0x80062398u: goto label_80062398;
    case 0x8006239Cu: goto label_8006239C;
    case 0x800623A0u: goto label_800623A0;
    case 0x800623A4u: goto label_800623A4;
    case 0x800623A8u: goto label_800623A8;
    case 0x800623ACu: goto label_800623AC;
    case 0x800623B0u: goto label_800623B0;
    case 0x800623B4u: goto label_800623B4;
    case 0x800623B8u: goto label_800623B8;
    case 0x800623BCu: goto label_800623BC;
    case 0x800623C0u: goto label_800623C0;
    case 0x800623C4u: goto label_800623C4;
    case 0x800623C8u: goto label_800623C8;
    case 0x800623CCu: goto label_800623CC;
    case 0x800623D0u: goto label_800623D0;
    case 0x800623D4u: goto label_800623D4;
    case 0x800623D8u: goto label_800623D8;
    case 0x800623DCu: goto label_800623DC;
    case 0x800623E0u: goto label_800623E0;
    case 0x800623E4u: goto label_800623E4;
    case 0x800623E8u: goto label_800623E8;
    case 0x800623ECu: goto label_800623EC;
    case 0x800623F0u: goto label_800623F0;
    case 0x800623F4u: goto label_800623F4;
    case 0x800623F8u: goto label_800623F8;
    case 0x800623FCu: goto label_800623FC;
    case 0x80062400u: goto label_80062400;
    case 0x80062404u: goto label_80062404;
    case 0x80062408u: goto label_80062408;
    case 0x8006240Cu: goto label_8006240C;
    case 0x80062410u: goto label_80062410;
    case 0x80062414u: goto label_80062414;
    case 0x80062418u: goto label_80062418;
    case 0x8006241Cu: goto label_8006241C;
    case 0x80062420u: goto label_80062420;
    case 0x80062424u: goto label_80062424;
    case 0x80062428u: goto label_80062428;
    case 0x8006242Cu: goto label_8006242C;
    case 0x80062430u: goto label_80062430;
    case 0x80062434u: goto label_80062434;
    case 0x80062438u: goto label_80062438;
    case 0x8006243Cu: goto label_8006243C;
    case 0x80062440u: goto label_80062440;
    case 0x80062444u: goto label_80062444;
    case 0x80062448u: goto label_80062448;
    case 0x8006244Cu: goto label_8006244C;
    case 0x80062450u: goto label_80062450;
    case 0x80062454u: goto label_80062454;
    case 0x80062458u: goto label_80062458;
    case 0x8006245Cu: goto label_8006245C;
    case 0x80062460u: goto label_80062460;
    case 0x80062464u: goto label_80062464;
    case 0x80062468u: goto label_80062468;
    case 0x8006246Cu: goto label_8006246C;
    case 0x80062470u: goto label_80062470;
    case 0x80062474u: goto label_80062474;
    case 0x80062478u: goto label_80062478;
    case 0x8006247Cu: goto label_8006247C;
    case 0x80062480u: goto label_80062480;
    case 0x80062484u: goto label_80062484;
    case 0x80062488u: goto label_80062488;
    case 0x8006248Cu: goto label_8006248C;
    case 0x80062490u: goto label_80062490;
    case 0x80062494u: goto label_80062494;
    case 0x80062498u: goto label_80062498;
    case 0x8006249Cu: goto label_8006249C;
    case 0x800624A0u: goto label_800624A0;
    case 0x800624A4u: goto label_800624A4;
    case 0x800624A8u: goto label_800624A8;
    case 0x800624ACu: goto label_800624AC;
    case 0x800624B0u: goto label_800624B0;
    case 0x800624B4u: goto label_800624B4;
    case 0x800624B8u: goto label_800624B8;
    case 0x800624BCu: goto label_800624BC;
    case 0x800624C0u: goto label_800624C0;
    case 0x800624C4u: goto label_800624C4;
    case 0x800624C8u: goto label_800624C8;
    case 0x800624CCu: goto label_800624CC;
    case 0x800624D0u: goto label_800624D0;
    case 0x800624D4u: goto label_800624D4;
    case 0x800624D8u: goto label_800624D8;
    case 0x800624DCu: goto label_800624DC;
    case 0x800624E0u: goto label_800624E0;
    case 0x800624E4u: goto label_800624E4;
    case 0x800624E8u: goto label_800624E8;
    case 0x800624ECu: goto label_800624EC;
    case 0x800624F0u: goto label_800624F0;
    case 0x800624F4u: goto label_800624F4;
    case 0x800624F8u: goto label_800624F8;
    case 0x800624FCu: goto label_800624FC;
    case 0x80062500u: goto label_80062500;
    case 0x80062504u: goto label_80062504;
    case 0x80062508u: goto label_80062508;
    case 0x8006250Cu: goto label_8006250C;
    case 0x80062510u: goto label_80062510;
    case 0x80062514u: goto label_80062514;
    case 0x80062518u: goto label_80062518;
    case 0x8006251Cu: goto label_8006251C;
    case 0x80062520u: goto label_80062520;
    case 0x80062524u: goto label_80062524;
    case 0x80062528u: goto label_80062528;
    case 0x8006252Cu: goto label_8006252C;
    case 0x80062530u: goto label_80062530;
    case 0x80062534u: goto label_80062534;
    case 0x80062538u: goto label_80062538;
    case 0x8006253Cu: goto label_8006253C;
    case 0x80062540u: goto label_80062540;
    case 0x80062544u: goto label_80062544;
    case 0x80062548u: goto label_80062548;
    case 0x8006254Cu: goto label_8006254C;
    case 0x80062550u: goto label_80062550;
    case 0x80062554u: goto label_80062554;
    case 0x80062558u: goto label_80062558;
    case 0x8006255Cu: goto label_8006255C;
    case 0x80062560u: goto label_80062560;
    case 0x80062564u: goto label_80062564;
    case 0x80062568u: goto label_80062568;
    case 0x8006256Cu: goto label_8006256C;
    case 0x80062570u: goto label_80062570;
    case 0x80062574u: goto label_80062574;
    case 0x80062578u: goto label_80062578;
    case 0x8006257Cu: goto label_8006257C;
    case 0x80062580u: goto label_80062580;
    case 0x80062584u: goto label_80062584;
    case 0x80062588u: goto label_80062588;
    case 0x8006258Cu: goto label_8006258C;
    case 0x80062590u: goto label_80062590;
    case 0x80062594u: goto label_80062594;
    case 0x80062598u: goto label_80062598;
    case 0x8006259Cu: goto label_8006259C;
    case 0x800625A0u: goto label_800625A0;
    case 0x800625A4u: goto label_800625A4;
    case 0x800625A8u: goto label_800625A8;
    case 0x800625ACu: goto label_800625AC;
    case 0x800625B0u: goto label_800625B0;
    case 0x800625B4u: goto label_800625B4;
    case 0x800625B8u: goto label_800625B8;
    case 0x800625BCu: goto label_800625BC;
    case 0x800625C0u: goto label_800625C0;
    case 0x800625C4u: goto label_800625C4;
    case 0x800625C8u: goto label_800625C8;
    case 0x800625CCu: goto label_800625CC;
    case 0x800625D0u: goto label_800625D0;
    case 0x800625D4u: goto label_800625D4;
    case 0x800625D8u: goto label_800625D8;
    case 0x800625DCu: goto label_800625DC;
    case 0x800625E0u: goto label_800625E0;
    case 0x800625E4u: goto label_800625E4;
    case 0x800625E8u: goto label_800625E8;
    case 0x800625ECu: goto label_800625EC;
    case 0x800625F0u: goto label_800625F0;
    case 0x800625F4u: goto label_800625F4;
    case 0x800625F8u: goto label_800625F8;
    case 0x800625FCu: goto label_800625FC;
    case 0x80062600u: goto label_80062600;
    case 0x80062604u: goto label_80062604;
    case 0x80062608u: goto label_80062608;
    case 0x8006260Cu: goto label_8006260C;
    case 0x80062610u: goto label_80062610;
    case 0x80062614u: goto label_80062614;
    case 0x80062618u: goto label_80062618;
    case 0x8006261Cu: goto label_8006261C;
    case 0x80062620u: goto label_80062620;
    case 0x80062624u: goto label_80062624;
    case 0x80062628u: goto label_80062628;
    case 0x8006262Cu: goto label_8006262C;
    case 0x80062630u: goto label_80062630;
    case 0x80062634u: goto label_80062634;
    case 0x80062638u: goto label_80062638;
    case 0x8006263Cu: goto label_8006263C;
    case 0x80062640u: goto label_80062640;
    case 0x80062644u: goto label_80062644;
    case 0x80062648u: goto label_80062648;
    case 0x8006264Cu: goto label_8006264C;
    case 0x80062650u: goto label_80062650;
    case 0x80062654u: goto label_80062654;
    case 0x80062658u: goto label_80062658;
    case 0x8006265Cu: goto label_8006265C;
    case 0x80062660u: goto label_80062660;
    case 0x80062664u: goto label_80062664;
    case 0x80062668u: goto label_80062668;
    case 0x8006266Cu: goto label_8006266C;
    case 0x80062670u: goto label_80062670;
    case 0x80062674u: goto label_80062674;
    case 0x80062678u: goto label_80062678;
    case 0x8006267Cu: goto label_8006267C;
    case 0x80062680u: goto label_80062680;
    case 0x80062684u: goto label_80062684;
    case 0x80062688u: goto label_80062688;
    case 0x8006268Cu: goto label_8006268C;
    case 0x80062690u: goto label_80062690;
    case 0x80062694u: goto label_80062694;
    case 0x80062698u: goto label_80062698;
    case 0x8006269Cu: goto label_8006269C;
    case 0x800626A0u: goto label_800626A0;
    case 0x800626A4u: goto label_800626A4;
    case 0x800626A8u: goto label_800626A8;
    case 0x800626ACu: goto label_800626AC;
    case 0x800626B0u: goto label_800626B0;
    case 0x800626B4u: goto label_800626B4;
    case 0x800626B8u: goto label_800626B8;
    case 0x800626BCu: goto label_800626BC;
    case 0x800626C0u: goto label_800626C0;
    case 0x800626C4u: goto label_800626C4;
    case 0x800626C8u: goto label_800626C8;
    case 0x800626CCu: goto label_800626CC;
    case 0x800626D0u: goto label_800626D0;
    case 0x800626D4u: goto label_800626D4;
    case 0x800626D8u: goto label_800626D8;
    case 0x800626DCu: goto label_800626DC;
    case 0x800626E0u: goto label_800626E0;
    case 0x800626E4u: goto label_800626E4;
    case 0x800626E8u: goto label_800626E8;
    case 0x800626ECu: goto label_800626EC;
    case 0x800626F0u: goto label_800626F0;
    case 0x800626F4u: goto label_800626F4;
    case 0x800626F8u: goto label_800626F8;
    case 0x800626FCu: goto label_800626FC;
    case 0x80062700u: goto label_80062700;
    case 0x80062704u: goto label_80062704;
    case 0x80062708u: goto label_80062708;
    case 0x8006270Cu: goto label_8006270C;
    case 0x80062710u: goto label_80062710;
    case 0x80062714u: goto label_80062714;
    case 0x80062718u: goto label_80062718;
    case 0x8006271Cu: goto label_8006271C;
    case 0x80062720u: goto label_80062720;
    case 0x80062724u: goto label_80062724;
    case 0x80062728u: goto label_80062728;
    case 0x8006272Cu: goto label_8006272C;
    case 0x80062730u: goto label_80062730;
    case 0x80062734u: goto label_80062734;
    case 0x80062738u: goto label_80062738;
    case 0x8006273Cu: goto label_8006273C;
    case 0x80062740u: goto label_80062740;
    case 0x80062744u: goto label_80062744;
    case 0x80062748u: goto label_80062748;
    case 0x8006274Cu: goto label_8006274C;
    case 0x80062750u: goto label_80062750;
    case 0x80062754u: goto label_80062754;
    case 0x80062758u: goto label_80062758;
    case 0x8006275Cu: goto label_8006275C;
    case 0x80062760u: goto label_80062760;
    case 0x80062764u: goto label_80062764;
    case 0x80062768u: goto label_80062768;
    case 0x8006276Cu: goto label_8006276C;
    case 0x80062770u: goto label_80062770;
    case 0x80062774u: goto label_80062774;
    case 0x80062778u: goto label_80062778;
    case 0x8006277Cu: goto label_8006277C;
    case 0x80062780u: goto label_80062780;
    case 0x80062784u: goto label_80062784;
    case 0x80062788u: goto label_80062788;
    case 0x8006278Cu: goto label_8006278C;
    case 0x80062790u: goto label_80062790;
    case 0x80062794u: goto label_80062794;
    case 0x80062798u: goto label_80062798;
    case 0x8006279Cu: goto label_8006279C;
    case 0x800627A0u: goto label_800627A0;
    case 0x800627A4u: goto label_800627A4;
    case 0x800627A8u: goto label_800627A8;
    case 0x800627ACu: goto label_800627AC;
    case 0x800627B0u: goto label_800627B0;
    case 0x800627B4u: goto label_800627B4;
    case 0x800627B8u: goto label_800627B8;
    case 0x800627BCu: goto label_800627BC;
    case 0x800627C0u: goto label_800627C0;
    case 0x800627C4u: goto label_800627C4;
    case 0x800627C8u: goto label_800627C8;
    case 0x800627CCu: goto label_800627CC;
    case 0x800627D0u: goto label_800627D0;
    case 0x800627D4u: goto label_800627D4;
    case 0x800627D8u: goto label_800627D8;
    case 0x800627DCu: goto label_800627DC;
    case 0x800627E0u: goto label_800627E0;
    case 0x800627E4u: goto label_800627E4;
    case 0x800627E8u: goto label_800627E8;
    case 0x800627ECu: goto label_800627EC;
    case 0x800627F0u: goto label_800627F0;
    case 0x800627F4u: goto label_800627F4;
    case 0x800627F8u: goto label_800627F8;
    case 0x800627FCu: goto label_800627FC;
    case 0x80062800u: goto label_80062800;
    case 0x80062804u: goto label_80062804;
    case 0x80062808u: goto label_80062808;
    case 0x8006280Cu: goto label_8006280C;
    case 0x80062810u: goto label_80062810;
    case 0x80062814u: goto label_80062814;
    case 0x80062818u: goto label_80062818;
    case 0x8006281Cu: goto label_8006281C;
    case 0x80062820u: goto label_80062820;
    case 0x80062824u: goto label_80062824;
    case 0x80062828u: goto label_80062828;
    case 0x8006282Cu: goto label_8006282C;
    case 0x80062830u: goto label_80062830;
    case 0x80062834u: goto label_80062834;
    case 0x80062838u: goto label_80062838;
    case 0x8006283Cu: goto label_8006283C;
    case 0x80062840u: goto label_80062840;
    case 0x80062844u: goto label_80062844;
    case 0x80062848u: goto label_80062848;
    case 0x8006284Cu: goto label_8006284C;
    case 0x80062850u: goto label_80062850;
    case 0x80062854u: goto label_80062854;
    case 0x80062858u: goto label_80062858;
    case 0x8006285Cu: goto label_8006285C;
    case 0x80062860u: goto label_80062860;
    case 0x80062864u: goto label_80062864;
    case 0x80062868u: goto label_80062868;
    case 0x8006286Cu: goto label_8006286C;
    case 0x80062870u: goto label_80062870;
    case 0x80062874u: goto label_80062874;
    case 0x80062878u: goto label_80062878;
    case 0x8006287Cu: goto label_8006287C;
    case 0x80062880u: goto label_80062880;
    case 0x80062884u: goto label_80062884;
    case 0x80062888u: goto label_80062888;
    case 0x8006288Cu: goto label_8006288C;
    case 0x80062890u: goto label_80062890;
    case 0x80062894u: goto label_80062894;
    case 0x80062898u: goto label_80062898;
    case 0x8006289Cu: goto label_8006289C;
    case 0x800628A0u: goto label_800628A0;
    case 0x800628A4u: goto label_800628A4;
    case 0x800628A8u: goto label_800628A8;
    case 0x800628ACu: goto label_800628AC;
    case 0x800628B0u: goto label_800628B0;
    case 0x800628B4u: goto label_800628B4;
    case 0x800628B8u: goto label_800628B8;
    case 0x800628BCu: goto label_800628BC;
    case 0x800628C0u: goto label_800628C0;
    case 0x800628C4u: goto label_800628C4;
    case 0x800628C8u: goto label_800628C8;
    case 0x800628CCu: goto label_800628CC;
    case 0x800628D0u: goto label_800628D0;
    case 0x800628D4u: goto label_800628D4;
    case 0x800628D8u: goto label_800628D8;
    case 0x800628DCu: goto label_800628DC;
    case 0x800628E0u: goto label_800628E0;
    case 0x800628E4u: goto label_800628E4;
    case 0x800628E8u: goto label_800628E8;
    case 0x800628ECu: goto label_800628EC;
    case 0x800628F0u: goto label_800628F0;
    case 0x800628F4u: goto label_800628F4;
    case 0x800628F8u: goto label_800628F8;
    case 0x800628FCu: goto label_800628FC;
    case 0x80062900u: goto label_80062900;
    case 0x80062904u: goto label_80062904;
    case 0x80062908u: goto label_80062908;
    case 0x8006290Cu: goto label_8006290C;
    case 0x80062910u: goto label_80062910;
    case 0x80062914u: goto label_80062914;
    case 0x80062918u: goto label_80062918;
    case 0x8006291Cu: goto label_8006291C;
    case 0x80062920u: goto label_80062920;
    case 0x80062924u: goto label_80062924;
    case 0x80062928u: goto label_80062928;
    case 0x8006292Cu: goto label_8006292C;
    case 0x80062930u: goto label_80062930;
    case 0x80062934u: goto label_80062934;
    case 0x80062938u: goto label_80062938;
    case 0x8006293Cu: goto label_8006293C;
    case 0x80062940u: goto label_80062940;
    case 0x80062944u: goto label_80062944;
    case 0x80062948u: goto label_80062948;
    case 0x8006294Cu: goto label_8006294C;
    case 0x80062950u: goto label_80062950;
    case 0x80062954u: goto label_80062954;
    case 0x80062958u: goto label_80062958;
    case 0x8006295Cu: goto label_8006295C;
    case 0x80062960u: goto label_80062960;
    case 0x80062964u: goto label_80062964;
    case 0x80062968u: goto label_80062968;
    case 0x8006296Cu: goto label_8006296C;
    case 0x80062970u: goto label_80062970;
    case 0x80062974u: goto label_80062974;
    case 0x80062978u: goto label_80062978;
    case 0x8006297Cu: goto label_8006297C;
    case 0x80062980u: goto label_80062980;
    case 0x80062984u: goto label_80062984;
    case 0x80062988u: goto label_80062988;
    case 0x8006298Cu: goto label_8006298C;
    case 0x80062990u: goto label_80062990;
    case 0x80062994u: goto label_80062994;
    case 0x80062998u: goto label_80062998;
    case 0x8006299Cu: goto label_8006299C;
    case 0x800629A0u: goto label_800629A0;
    case 0x800629A4u: goto label_800629A4;
    case 0x800629A8u: goto label_800629A8;
    case 0x800629ACu: goto label_800629AC;
    case 0x800629B0u: goto label_800629B0;
    case 0x800629B4u: goto label_800629B4;
    case 0x800629B8u: goto label_800629B8;
    case 0x800629BCu: goto label_800629BC;
    case 0x800629C0u: goto label_800629C0;
    case 0x800629C4u: goto label_800629C4;
    case 0x800629C8u: goto label_800629C8;
    case 0x800629CCu: goto label_800629CC;
    case 0x800629D0u: goto label_800629D0;
    case 0x800629D4u: goto label_800629D4;
    case 0x800629D8u: goto label_800629D8;
    case 0x800629DCu: goto label_800629DC;
    case 0x800629E0u: goto label_800629E0;
    case 0x800629E4u: goto label_800629E4;
    case 0x800629E8u: goto label_800629E8;
    case 0x800629ECu: goto label_800629EC;
    case 0x800629F0u: goto label_800629F0;
    case 0x800629F4u: goto label_800629F4;
    case 0x800629F8u: goto label_800629F8;
    case 0x800629FCu: goto label_800629FC;
    case 0x80062A00u: goto label_80062A00;
    case 0x80062A04u: goto label_80062A04;
    case 0x80062A08u: goto label_80062A08;
    case 0x80062A0Cu: goto label_80062A0C;
    case 0x80062A10u: goto label_80062A10;
    case 0x80062A14u: goto label_80062A14;
    case 0x80062A18u: goto label_80062A18;
    case 0x80062A1Cu: goto label_80062A1C;
    case 0x80062A20u: goto label_80062A20;
    case 0x80062A24u: goto label_80062A24;
    case 0x80062A28u: goto label_80062A28;
    case 0x80062A2Cu: goto label_80062A2C;
    case 0x80062A30u: goto label_80062A30;
    case 0x80062A34u: goto label_80062A34;
    case 0x80062A38u: goto label_80062A38;
    case 0x80062A3Cu: goto label_80062A3C;
    case 0x80062A40u: goto label_80062A40;
    case 0x80062A44u: goto label_80062A44;
    case 0x80062A48u: goto label_80062A48;
    case 0x80062A4Cu: goto label_80062A4C;
    case 0x80062A50u: goto label_80062A50;
    case 0x80062A54u: goto label_80062A54;
    case 0x80062A58u: goto label_80062A58;
    case 0x80062A5Cu: goto label_80062A5C;
    case 0x80062A60u: goto label_80062A60;
    case 0x80062A64u: goto label_80062A64;
    case 0x80062A68u: goto label_80062A68;
    case 0x80062A6Cu: goto label_80062A6C;
    case 0x80062A70u: goto label_80062A70;
    case 0x80062A74u: goto label_80062A74;
    case 0x80062A78u: goto label_80062A78;
    case 0x80062A7Cu: goto label_80062A7C;
    case 0x80062A80u: goto label_80062A80;
    case 0x80062A84u: goto label_80062A84;
    case 0x80062A88u: goto label_80062A88;
    case 0x80062A8Cu: goto label_80062A8C;
    case 0x80062A90u: goto label_80062A90;
    case 0x80062A94u: goto label_80062A94;
    case 0x80062A98u: goto label_80062A98;
    case 0x80062A9Cu: goto label_80062A9C;
    case 0x80062AA0u: goto label_80062AA0;
    case 0x80062AA4u: goto label_80062AA4;
    case 0x80062AA8u: goto label_80062AA8;
    case 0x80062AACu: goto label_80062AAC;
    case 0x80062AB0u: goto label_80062AB0;
    case 0x80062AB4u: goto label_80062AB4;
    case 0x80062AB8u: goto label_80062AB8;
    case 0x80062ABCu: goto label_80062ABC;
    case 0x80062AC0u: goto label_80062AC0;
    case 0x80062AC4u: goto label_80062AC4;
    case 0x80062AC8u: goto label_80062AC8;
    case 0x80062ACCu: goto label_80062ACC;
    case 0x80062AD0u: goto label_80062AD0;
    case 0x80062AD4u: goto label_80062AD4;
    case 0x80062AD8u: goto label_80062AD8;
    case 0x80062ADCu: goto label_80062ADC;
    case 0x80062AE0u: goto label_80062AE0;
    case 0x80062AE4u: goto label_80062AE4;
    case 0x80062AE8u: goto label_80062AE8;
    case 0x80062AECu: goto label_80062AEC;
    case 0x80062AF0u: goto label_80062AF0;
    case 0x80062AF4u: goto label_80062AF4;
    case 0x80062AF8u: goto label_80062AF8;
    case 0x80062AFCu: goto label_80062AFC;
    case 0x80062B00u: goto label_80062B00;
    case 0x80062B04u: goto label_80062B04;
    case 0x80062B08u: goto label_80062B08;
    case 0x80062B0Cu: goto label_80062B0C;
    case 0x80062B10u: goto label_80062B10;
    case 0x80062B14u: goto label_80062B14;
    case 0x80062B18u: goto label_80062B18;
    case 0x80062B1Cu: goto label_80062B1C;
    case 0x80062B20u: goto label_80062B20;
    case 0x80062B24u: goto label_80062B24;
    case 0x80062B28u: goto label_80062B28;
    case 0x80062B2Cu: goto label_80062B2C;
    case 0x80062B30u: goto label_80062B30;
    case 0x80062B34u: goto label_80062B34;
    case 0x80062B38u: goto label_80062B38;
    case 0x80062B3Cu: goto label_80062B3C;
    case 0x80062B40u: goto label_80062B40;
    case 0x80062B44u: goto label_80062B44;
    case 0x80062B48u: goto label_80062B48;
    case 0x80062B4Cu: goto label_80062B4C;
    case 0x80062B50u: goto label_80062B50;
    case 0x80062B54u: goto label_80062B54;
    case 0x80062B58u: goto label_80062B58;
    case 0x80062B5Cu: goto label_80062B5C;
    case 0x80062B60u: goto label_80062B60;
    case 0x80062B64u: goto label_80062B64;
    case 0x80062B68u: goto label_80062B68;
    case 0x80062B6Cu: goto label_80062B6C;
    case 0x80062B70u: goto label_80062B70;
    case 0x80062B74u: goto label_80062B74;
    case 0x80062B78u: goto label_80062B78;
    case 0x80062B7Cu: goto label_80062B7C;
    case 0x80062B80u: goto label_80062B80;
    case 0x80062B84u: goto label_80062B84;
    case 0x80062B88u: goto label_80062B88;
    case 0x80062B8Cu: goto label_80062B8C;
    case 0x80062B90u: goto label_80062B90;
    case 0x80062B94u: goto label_80062B94;
    case 0x80062B98u: goto label_80062B98;
    case 0x80062B9Cu: goto label_80062B9C;
    case 0x80062BA0u: goto label_80062BA0;
    case 0x80062BA4u: goto label_80062BA4;
    case 0x80062BA8u: goto label_80062BA8;
    case 0x80062BACu: goto label_80062BAC;
    case 0x80062BB0u: goto label_80062BB0;
    case 0x80062BB4u: goto label_80062BB4;
    case 0x80062BB8u: goto label_80062BB8;
    case 0x80062BBCu: goto label_80062BBC;
    case 0x80062BC0u: goto label_80062BC0;
    case 0x80062BC4u: goto label_80062BC4;
    case 0x80062BC8u: goto label_80062BC8;
    case 0x80062BCCu: goto label_80062BCC;
    case 0x80062BD0u: goto label_80062BD0;
    case 0x80062BD4u: goto label_80062BD4;
    case 0x80062BD8u: goto label_80062BD8;
    case 0x80062BDCu: goto label_80062BDC;
    case 0x80062BE0u: goto label_80062BE0;
    case 0x80062BE4u: goto label_80062BE4;
    case 0x80062BE8u: goto label_80062BE8;
    case 0x80062BECu: goto label_80062BEC;
    case 0x80062BF0u: goto label_80062BF0;
    case 0x80062BF4u: goto label_80062BF4;
    case 0x80062BF8u: goto label_80062BF8;
    case 0x80062BFCu: goto label_80062BFC;
    case 0x80062C00u: goto label_80062C00;
    case 0x80062C04u: goto label_80062C04;
    case 0x80062C08u: goto label_80062C08;
    case 0x80062C0Cu: goto label_80062C0C;
    case 0x80062C10u: goto label_80062C10;
    case 0x80062C14u: goto label_80062C14;
    case 0x80062C18u: goto label_80062C18;
    case 0x80062C1Cu: goto label_80062C1C;
    case 0x80062C20u: goto label_80062C20;
    case 0x80062C24u: goto label_80062C24;
    case 0x80062C28u: goto label_80062C28;
    case 0x80062C2Cu: goto label_80062C2C;
    case 0x80062C30u: goto label_80062C30;
    case 0x80062C34u: goto label_80062C34;
    case 0x80062C38u: goto label_80062C38;
    case 0x80062C3Cu: goto label_80062C3C;
    case 0x80062C40u: goto label_80062C40;
    case 0x80062C44u: goto label_80062C44;
    case 0x80062C48u: goto label_80062C48;
    case 0x80062C4Cu: goto label_80062C4C;
    case 0x80062C50u: goto label_80062C50;
    case 0x80062C54u: goto label_80062C54;
    case 0x80062C58u: goto label_80062C58;
    case 0x80062C5Cu: goto label_80062C5C;
    case 0x80062C60u: goto label_80062C60;
    case 0x80062C64u: goto label_80062C64;
    case 0x80062C68u: goto label_80062C68;
    case 0x80062C6Cu: goto label_80062C6C;
    case 0x80062C70u: goto label_80062C70;
    case 0x80062C74u: goto label_80062C74;
    case 0x80062C78u: goto label_80062C78;
    case 0x80062C7Cu: goto label_80062C7C;
    case 0x80062C80u: goto label_80062C80;
    case 0x80062C84u: goto label_80062C84;
    case 0x80062C88u: goto label_80062C88;
    case 0x80062C8Cu: goto label_80062C8C;
    case 0x80062C90u: goto label_80062C90;
    case 0x80062C94u: goto label_80062C94;
    case 0x80062C98u: goto label_80062C98;
    case 0x80062C9Cu: goto label_80062C9C;
    case 0x80062CA0u: goto label_80062CA0;
    case 0x80062CA4u: goto label_80062CA4;
    case 0x80062CA8u: goto label_80062CA8;
    case 0x80062CACu: goto label_80062CAC;
    case 0x80062CB0u: goto label_80062CB0;
    case 0x80062CB4u: goto label_80062CB4;
    case 0x80062CB8u: goto label_80062CB8;
    case 0x80062CBCu: goto label_80062CBC;
    case 0x80062CC0u: goto label_80062CC0;
    case 0x80062CC4u: goto label_80062CC4;
    case 0x80062CC8u: goto label_80062CC8;
    case 0x80062CCCu: goto label_80062CCC;
    case 0x80062CD0u: goto label_80062CD0;
    case 0x80062CD4u: goto label_80062CD4;
    case 0x80062CD8u: goto label_80062CD8;
    case 0x80062CDCu: goto label_80062CDC;
    case 0x80062CE0u: goto label_80062CE0;
    case 0x80062CE4u: goto label_80062CE4;
    case 0x80062CE8u: goto label_80062CE8;
    case 0x80062CECu: goto label_80062CEC;
    case 0x80062CF0u: goto label_80062CF0;
    case 0x80062CF4u: goto label_80062CF4;
    case 0x80062CF8u: goto label_80062CF8;
    case 0x80062CFCu: goto label_80062CFC;
    case 0x80062D00u: goto label_80062D00;
    case 0x80062D04u: goto label_80062D04;
    case 0x80062D08u: goto label_80062D08;
    case 0x80062D0Cu: goto label_80062D0C;
    case 0x80062D10u: goto label_80062D10;
    case 0x80062D14u: goto label_80062D14;
    case 0x80062D18u: goto label_80062D18;
    case 0x80062D1Cu: goto label_80062D1C;
    case 0x80062D20u: goto label_80062D20;
    case 0x80062D24u: goto label_80062D24;
    case 0x80062D28u: goto label_80062D28;
    case 0x80062D2Cu: goto label_80062D2C;
    case 0x80062D30u: goto label_80062D30;
    case 0x80062D34u: goto label_80062D34;
    case 0x80062D38u: goto label_80062D38;
    case 0x80062D3Cu: goto label_80062D3C;
    case 0x80062D40u: goto label_80062D40;
    case 0x80062D44u: goto label_80062D44;
    case 0x80062D48u: goto label_80062D48;
    case 0x80062D4Cu: goto label_80062D4C;
    case 0x80062D50u: goto label_80062D50;
    case 0x80062D54u: goto label_80062D54;
    case 0x80062D58u: goto label_80062D58;
    case 0x80062D5Cu: goto label_80062D5C;
    case 0x80062D60u: goto label_80062D60;
    case 0x80062D64u: goto label_80062D64;
    case 0x80062D68u: goto label_80062D68;
    case 0x80062D6Cu: goto label_80062D6C;
    case 0x80062D70u: goto label_80062D70;
    case 0x80062D74u: goto label_80062D74;
    case 0x80062D78u: goto label_80062D78;
    case 0x80062D7Cu: goto label_80062D7C;
    case 0x80062D80u: goto label_80062D80;
    case 0x80062D84u: goto label_80062D84;
    case 0x80062D88u: goto label_80062D88;
    case 0x80062D8Cu: goto label_80062D8C;
    case 0x80062D90u: goto label_80062D90;
    case 0x80062D94u: goto label_80062D94;
    case 0x80062D98u: goto label_80062D98;
    case 0x80062D9Cu: goto label_80062D9C;
    case 0x80062DA0u: goto label_80062DA0;
    case 0x80062DA4u: goto label_80062DA4;
    case 0x80062DA8u: goto label_80062DA8;
    case 0x80062DACu: goto label_80062DAC;
    case 0x80062DB0u: goto label_80062DB0;
    case 0x80062DB4u: goto label_80062DB4;
    case 0x80062DB8u: goto label_80062DB8;
    case 0x80062DBCu: goto label_80062DBC;
    case 0x80062DC0u: goto label_80062DC0;
    case 0x80062DC4u: goto label_80062DC4;
    case 0x80062DC8u: goto label_80062DC8;
    case 0x80062DCCu: goto label_80062DCC;
    case 0x80062DD0u: goto label_80062DD0;
    case 0x80062DD4u: goto label_80062DD4;
    case 0x80062DD8u: goto label_80062DD8;
    case 0x80062DDCu: goto label_80062DDC;
    case 0x80062DE0u: goto label_80062DE0;
    case 0x80062DE4u: goto label_80062DE4;
    case 0x80062DE8u: goto label_80062DE8;
    case 0x80062DECu: goto label_80062DEC;
    case 0x80062DF0u: goto label_80062DF0;
    case 0x80062DF4u: goto label_80062DF4;
    case 0x80062DF8u: goto label_80062DF8;
    case 0x80062DFCu: goto label_80062DFC;
    case 0x80062E00u: goto label_80062E00;
    case 0x80062E04u: goto label_80062E04;
    case 0x80062E08u: goto label_80062E08;
    case 0x80062E0Cu: goto label_80062E0C;
    case 0x80062E10u: goto label_80062E10;
    case 0x80062E14u: goto label_80062E14;
    case 0x80062E18u: goto label_80062E18;
    case 0x80062E1Cu: goto label_80062E1C;
    case 0x80062E20u: goto label_80062E20;
    case 0x80062E24u: goto label_80062E24;
    case 0x80062E28u: goto label_80062E28;
    case 0x80062E2Cu: goto label_80062E2C;
    case 0x80062E30u: goto label_80062E30;
    case 0x80062E34u: goto label_80062E34;
    case 0x80062E38u: goto label_80062E38;
    case 0x80062E3Cu: goto label_80062E3C;
    case 0x80062E40u: goto label_80062E40;
    case 0x80062E44u: goto label_80062E44;
    case 0x80062E48u: goto label_80062E48;
    case 0x80062E4Cu: goto label_80062E4C;
    case 0x80062E50u: goto label_80062E50;
    case 0x80062E54u: goto label_80062E54;
    case 0x80062E58u: goto label_80062E58;
    case 0x80062E5Cu: goto label_80062E5C;
    case 0x80062E60u: goto label_80062E60;
    case 0x80062E64u: goto label_80062E64;
    case 0x80062E68u: goto label_80062E68;
    case 0x80062E6Cu: goto label_80062E6C;
    case 0x80062E70u: goto label_80062E70;
    case 0x80062E74u: goto label_80062E74;
    case 0x80062E78u: goto label_80062E78;
    case 0x80062E7Cu: goto label_80062E7C;
    case 0x80062E80u: goto label_80062E80;
    case 0x80062E84u: goto label_80062E84;
    case 0x80062E88u: goto label_80062E88;
    case 0x80062E8Cu: goto label_80062E8C;
    case 0x80062E90u: goto label_80062E90;
    case 0x80062E94u: goto label_80062E94;
    case 0x80062E98u: goto label_80062E98;
    case 0x80062E9Cu: goto label_80062E9C;
    case 0x80062EA0u: goto label_80062EA0;
    case 0x80062EA4u: goto label_80062EA4;
    case 0x80062EA8u: goto label_80062EA8;
    case 0x80062EACu: goto label_80062EAC;
    case 0x80062EB0u: goto label_80062EB0;
    case 0x80062EB4u: goto label_80062EB4;
    case 0x80062EB8u: goto label_80062EB8;
    case 0x80062EBCu: goto label_80062EBC;
    case 0x80062EC0u: goto label_80062EC0;
    case 0x80062EC4u: goto label_80062EC4;
    case 0x80062EC8u: goto label_80062EC8;
    case 0x80062ECCu: goto label_80062ECC;
    case 0x80062ED0u: goto label_80062ED0;
    case 0x80062ED4u: goto label_80062ED4;
    case 0x80062ED8u: goto label_80062ED8;
    case 0x80062EDCu: goto label_80062EDC;
    case 0x80062EE0u: goto label_80062EE0;
    case 0x80062EE4u: goto label_80062EE4;
    case 0x80062EE8u: goto label_80062EE8;
    case 0x80062EECu: goto label_80062EEC;
    case 0x80062EF0u: goto label_80062EF0;
    case 0x80062EF4u: goto label_80062EF4;
    case 0x80062EF8u: goto label_80062EF8;
    case 0x80062EFCu: goto label_80062EFC;
    case 0x80062F00u: goto label_80062F00;
    case 0x80062F04u: goto label_80062F04;
    case 0x80062F08u: goto label_80062F08;
    case 0x80062F0Cu: goto label_80062F0C;
    case 0x80062F10u: goto label_80062F10;
    case 0x80062F14u: goto label_80062F14;
    case 0x80062F18u: goto label_80062F18;
    case 0x80062F1Cu: goto label_80062F1C;
    case 0x80062F20u: goto label_80062F20;
    case 0x80062F24u: goto label_80062F24;
    case 0x80062F28u: goto label_80062F28;
    case 0x80062F2Cu: goto label_80062F2C;
    case 0x80062F30u: goto label_80062F30;
    case 0x80062F34u: goto label_80062F34;
    case 0x80062F38u: goto label_80062F38;
    case 0x80062F3Cu: goto label_80062F3C;
    case 0x80062F40u: goto label_80062F40;
    case 0x80062F44u: goto label_80062F44;
    case 0x80062F48u: goto label_80062F48;
    case 0x80062F4Cu: goto label_80062F4C;
    case 0x80062F50u: goto label_80062F50;
    case 0x80062F54u: goto label_80062F54;
    case 0x80062F58u: goto label_80062F58;
    case 0x80062F5Cu: goto label_80062F5C;
    case 0x80062F60u: goto label_80062F60;
    case 0x80062F64u: goto label_80062F64;
    case 0x80062F68u: goto label_80062F68;
    case 0x80062F6Cu: goto label_80062F6C;
    case 0x80062F70u: goto label_80062F70;
    case 0x80062F74u: goto label_80062F74;
    case 0x80062F78u: goto label_80062F78;
    case 0x80062F7Cu: goto label_80062F7C;
    case 0x80062F80u: goto label_80062F80;
    case 0x80062F84u: goto label_80062F84;
    case 0x80062F88u: goto label_80062F88;
    case 0x80062F8Cu: goto label_80062F8C;
    case 0x80062F90u: goto label_80062F90;
    case 0x80062F94u: goto label_80062F94;
    case 0x80062F98u: goto label_80062F98;
    case 0x80062F9Cu: goto label_80062F9C;
    case 0x80062FA0u: goto label_80062FA0;
    case 0x80062FA4u: goto label_80062FA4;
    case 0x80062FA8u: goto label_80062FA8;
    case 0x80062FACu: goto label_80062FAC;
    case 0x80062FB0u: goto label_80062FB0;
    case 0x80062FB4u: goto label_80062FB4;
    case 0x80062FB8u: goto label_80062FB8;
    case 0x80062FBCu: goto label_80062FBC;
    case 0x80062FC0u: goto label_80062FC0;
    case 0x80062FC4u: goto label_80062FC4;
    case 0x80062FC8u: goto label_80062FC8;
    case 0x80062FCCu: goto label_80062FCC;
    case 0x80062FD0u: goto label_80062FD0;
    case 0x80062FD4u: goto label_80062FD4;
    case 0x80062FD8u: goto label_80062FD8;
    case 0x80062FDCu: goto label_80062FDC;
    case 0x80062FE0u: goto label_80062FE0;
    case 0x80062FE4u: goto label_80062FE4;
    case 0x80062FE8u: goto label_80062FE8;
    case 0x80062FECu: goto label_80062FEC;
    case 0x80062FF0u: goto label_80062FF0;
    case 0x80062FF4u: goto label_80062FF4;
    case 0x80062FF8u: goto label_80062FF8;
    case 0x80062FFCu: goto label_80062FFC;
    case 0x80063000u: goto label_80063000;
    case 0x80063004u: goto label_80063004;
    case 0x80063008u: goto label_80063008;
    case 0x8006300Cu: goto label_8006300C;
    case 0x80063010u: goto label_80063010;
    case 0x80063014u: goto label_80063014;
    case 0x80063018u: goto label_80063018;
    case 0x8006301Cu: goto label_8006301C;
    case 0x80063020u: goto label_80063020;
    case 0x80063024u: goto label_80063024;
    case 0x80063028u: goto label_80063028;
    case 0x8006302Cu: goto label_8006302C;
    case 0x80063030u: goto label_80063030;
    case 0x80063034u: goto label_80063034;
    case 0x80063038u: goto label_80063038;
    case 0x8006303Cu: goto label_8006303C;
    case 0x80063040u: goto label_80063040;
    case 0x80063044u: goto label_80063044;
    case 0x80063048u: goto label_80063048;
    case 0x8006304Cu: goto label_8006304C;
    case 0x80063050u: goto label_80063050;
    case 0x80063054u: goto label_80063054;
    case 0x80063058u: goto label_80063058;
    case 0x8006305Cu: goto label_8006305C;
    case 0x80063060u: goto label_80063060;
    case 0x80063064u: goto label_80063064;
    case 0x80063068u: goto label_80063068;
    case 0x8006306Cu: goto label_8006306C;
    case 0x80063070u: goto label_80063070;
    case 0x80063074u: goto label_80063074;
    case 0x80063078u: goto label_80063078;
    case 0x8006307Cu: goto label_8006307C;
    case 0x80063080u: goto label_80063080;
    case 0x80063084u: goto label_80063084;
    case 0x80063088u: goto label_80063088;
    case 0x8006308Cu: goto label_8006308C;
    case 0x80063090u: goto label_80063090;
    case 0x80063094u: goto label_80063094;
    case 0x80063098u: goto label_80063098;
    case 0x8006309Cu: goto label_8006309C;
    case 0x800630A0u: goto label_800630A0;
    case 0x800630A4u: goto label_800630A4;
    case 0x800630A8u: goto label_800630A8;
    case 0x800630ACu: goto label_800630AC;
    case 0x800630B0u: goto label_800630B0;
    case 0x800630B4u: goto label_800630B4;
    case 0x800630B8u: goto label_800630B8;
    case 0x800630BCu: goto label_800630BC;
    case 0x800630C0u: goto label_800630C0;
    case 0x800630C4u: goto label_800630C4;
    case 0x800630C8u: goto label_800630C8;
    case 0x800630CCu: goto label_800630CC;
    case 0x800630D0u: goto label_800630D0;
    case 0x800630D4u: goto label_800630D4;
    case 0x800630D8u: goto label_800630D8;
    case 0x800630DCu: goto label_800630DC;
    case 0x800630E0u: goto label_800630E0;
    case 0x800630E4u: goto label_800630E4;
    case 0x800630E8u: goto label_800630E8;
    case 0x800630ECu: goto label_800630EC;
    case 0x800630F0u: goto label_800630F0;
    case 0x800630F4u: goto label_800630F4;
    case 0x800630F8u: goto label_800630F8;
    case 0x800630FCu: goto label_800630FC;
    case 0x80063100u: goto label_80063100;
    case 0x80063104u: goto label_80063104;
    case 0x80063108u: goto label_80063108;
    case 0x8006310Cu: goto label_8006310C;
    case 0x80063110u: goto label_80063110;
    case 0x80063114u: goto label_80063114;
    case 0x80063118u: goto label_80063118;
    case 0x8006311Cu: goto label_8006311C;
    case 0x80063120u: goto label_80063120;
    case 0x80063124u: goto label_80063124;
    case 0x80063128u: goto label_80063128;
    case 0x8006312Cu: goto label_8006312C;
    case 0x80063130u: goto label_80063130;
    case 0x80063134u: goto label_80063134;
    case 0x80063138u: goto label_80063138;
    case 0x8006313Cu: goto label_8006313C;
    case 0x80063140u: goto label_80063140;
    case 0x80063144u: goto label_80063144;
    case 0x80063148u: goto label_80063148;
    case 0x8006314Cu: goto label_8006314C;
    case 0x80063150u: goto label_80063150;
    case 0x80063154u: goto label_80063154;
    case 0x80063158u: goto label_80063158;
    case 0x8006315Cu: goto label_8006315C;
    case 0x80063160u: goto label_80063160;
    case 0x80063164u: goto label_80063164;
    case 0x80063168u: goto label_80063168;
    case 0x8006316Cu: goto label_8006316C;
    case 0x80063170u: goto label_80063170;
    case 0x80063174u: goto label_80063174;
    case 0x80063178u: goto label_80063178;
    case 0x8006317Cu: goto label_8006317C;
    case 0x80063180u: goto label_80063180;
    case 0x80063184u: goto label_80063184;
    case 0x80063188u: goto label_80063188;
    case 0x8006318Cu: goto label_8006318C;
    case 0x80063190u: goto label_80063190;
    case 0x80063194u: goto label_80063194;
    case 0x80063198u: goto label_80063198;
    case 0x8006319Cu: goto label_8006319C;
    case 0x800631A0u: goto label_800631A0;
    case 0x800631A4u: goto label_800631A4;
    case 0x800631A8u: goto label_800631A8;
    case 0x800631ACu: goto label_800631AC;
    case 0x800631B0u: goto label_800631B0;
    case 0x800631B4u: goto label_800631B4;
    case 0x800631B8u: goto label_800631B8;
    case 0x800631BCu: goto label_800631BC;
    case 0x800631C0u: goto label_800631C0;
    case 0x800631C4u: goto label_800631C4;
    case 0x800631C8u: goto label_800631C8;
    case 0x800631CCu: goto label_800631CC;
    case 0x800631D0u: goto label_800631D0;
    case 0x800631D4u: goto label_800631D4;
    case 0x800631D8u: goto label_800631D8;
    case 0x800631DCu: goto label_800631DC;
    case 0x800631E0u: goto label_800631E0;
    case 0x800631E4u: goto label_800631E4;
    case 0x800631E8u: goto label_800631E8;
    case 0x800631ECu: goto label_800631EC;
    case 0x800631F0u: goto label_800631F0;
    case 0x800631F4u: goto label_800631F4;
    case 0x800631F8u: goto label_800631F8;
    case 0x800631FCu: goto label_800631FC;
    case 0x80063200u: goto label_80063200;
    case 0x80063204u: goto label_80063204;
    case 0x80063208u: goto label_80063208;
    case 0x8006320Cu: goto label_8006320C;
    case 0x80063210u: goto label_80063210;
    case 0x80063214u: goto label_80063214;
    case 0x80063218u: goto label_80063218;
    case 0x8006321Cu: goto label_8006321C;
    case 0x80063220u: goto label_80063220;
    case 0x80063224u: goto label_80063224;
    case 0x80063228u: goto label_80063228;
    case 0x8006322Cu: goto label_8006322C;
    case 0x80063230u: goto label_80063230;
    case 0x80063234u: goto label_80063234;
    case 0x80063238u: goto label_80063238;
    case 0x8006323Cu: goto label_8006323C;
    case 0x80063240u: goto label_80063240;
    case 0x80063244u: goto label_80063244;
    case 0x80063248u: goto label_80063248;
    case 0x8006324Cu: goto label_8006324C;
    case 0x80063250u: goto label_80063250;
    case 0x80063254u: goto label_80063254;
    case 0x80063258u: goto label_80063258;
    case 0x8006325Cu: goto label_8006325C;
    case 0x80063260u: goto label_80063260;
    case 0x80063264u: goto label_80063264;
    case 0x80063268u: goto label_80063268;
    case 0x8006326Cu: goto label_8006326C;
    case 0x80063270u: goto label_80063270;
    case 0x80063274u: goto label_80063274;
    case 0x80063278u: goto label_80063278;
    case 0x8006327Cu: goto label_8006327C;
    case 0x80063280u: goto label_80063280;
    case 0x80063284u: goto label_80063284;
    case 0x80063288u: goto label_80063288;
    case 0x8006328Cu: goto label_8006328C;
    case 0x80063290u: goto label_80063290;
    case 0x80063294u: goto label_80063294;
    case 0x80063298u: goto label_80063298;
    case 0x8006329Cu: goto label_8006329C;
    case 0x800632A0u: goto label_800632A0;
    case 0x800632A4u: goto label_800632A4;
    case 0x800632A8u: goto label_800632A8;
    case 0x800632ACu: goto label_800632AC;
    case 0x800632B0u: goto label_800632B0;
    case 0x800632B4u: goto label_800632B4;
    case 0x800632B8u: goto label_800632B8;
    case 0x800632BCu: goto label_800632BC;
    default: return;
    }
label_8005F2C0:
    ctx->pc = 0x8005F2C0u;
    ctx->downcount -= 2;
    // 8005F2C0: cmpwi   r3, 0
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

label_8005F2C4:
    ctx->pc = 0x8005F2C4u;
    // 8005F2C4: bc    12, 2, 0x8005F324
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F324;
        }
    }

label_8005F2C8:
    ctx->pc = 0x8005F2C8u;
    ctx->downcount -= 4;
    // 8005F2C8: lwz     r4, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005F2CC:
    ctx->pc = 0x8005F2CCu;
    // 8005F2CC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F2D0:
    ctx->pc = 0x8005F2D0u;
    // 8005F2D0: addi    r30, r23, 20
    ctx->gpr[30] = ctx->gpr[23] + (u32)(s32)(20);

label_8005F2D4:
    ctx->pc = 0x8005F2D4u;
    // 8005F2D4: bl      0x80046DA4
    {
            ctx->lr = 0x8005F2D8u;
            ctx->pc = 0x80046DA4u;
            return;
    }

label_8005F2D8:
    ctx->pc = 0x8005F2D8u;
    ctx->downcount -= 10;
    // 8005F2D8: li      r6, 20
    ctx->gpr[6] = (u32)(s32)(20);

label_8005F2DC:
    ctx->pc = 0x8005F2DCu;
    // 8005F2DC: li      r5, 590
    ctx->gpr[5] = (u32)(s32)(590);

label_8005F2E0:
    ctx->pc = 0x8005F2E0u;
    // 8005F2E0: rlwinm r6, r6, 2, 0, 29
    {
        ctx->gpr[6] = dolrecomp_rotl32(ctx->gpr[6], 2u) & 0xFFFFFFFCu;
    }

label_8005F2E4:
    ctx->pc = 0x8005F2E4u;
    // 8005F2E4: li      r3, 50
    ctx->gpr[3] = (u32)(s32)(50);

label_8005F2E8:
    ctx->pc = 0x8005F2E8u;
    // 8005F2E8: addi    r6, r6, 40
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(40);

label_8005F2EC:
    ctx->pc = 0x8005F2ECu;
    // 8005F2EC: or   r4, r30, r30
    {
        ctx->gpr[4] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005F2F0:
    ctx->pc = 0x8005F2F0u;
    // 8005F2F0: add   r6, r23, r6
    {
        u32 a = ctx->gpr[23];
        u32 b = ctx->gpr[6];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8005F2F4:
    ctx->pc = 0x8005F2F4u;
    // 8005F2F4: lis     r7, -32768
    ctx->gpr[7] = ((u32)(s32)(-32768) << 16);

label_8005F2F8:
    ctx->pc = 0x8005F2F8u;
    // 8005F2F8: li      r8, 0
    ctx->gpr[8] = (u32)(s32)(0);

label_8005F2FC:
    ctx->pc = 0x8005F2FCu;
    // 8005F2FC: bl      0x80003700
    {
            ctx->lr = 0x8005F300u;
            ctx->pc = 0x80003700u;
            return;
    }

label_8005F300:
    ctx->pc = 0x8005F300u;
    ctx->downcount -= 3;
    // 8005F300: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F304:
    ctx->pc = 0x8005F304u;
    // 8005F304: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005F308:
    ctx->pc = 0x8005F308u;
    // 8005F308: bl      0x80034BA8
    {
            ctx->lr = 0x8005F30Cu;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005F30C:
    ctx->pc = 0x8005F30Cu;
    ctx->downcount -= 6;
    // 8005F30C: lwz     r6, 16(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005F310:
    ctx->pc = 0x8005F310u;
    // 8005F310: or   r5, r30, r30
    {
        ctx->gpr[5] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8005F314:
    ctx->pc = 0x8005F314u;
    // 8005F314: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F318:
    ctx->pc = 0x8005F318u;
    // 8005F318: li      r4, 60
    ctx->gpr[4] = (u32)(s32)(60);

label_8005F31C:
    ctx->pc = 0x8005F31Cu;
    // 8005F31C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F320:
    ctx->pc = 0x8005F320u;
    // 8005F320: bl      0x800350B4
    {
            ctx->lr = 0x8005F324u;
            ctx->pc = 0x800350B4u;
            return;
    }

label_8005F324:
    ctx->pc = 0x8005F324u;
    ctx->downcount -= 1;
    // 8005F324: bc    12, 18, 0x8005F398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x00002000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F398;
        }
    }

label_8005F328:
    ctx->pc = 0x8005F328u;
    ctx->downcount -= 12;
    // 8005F328: lwz     r11, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F32C:
    ctx->pc = 0x8005F32Cu;
    // 8005F32C: lwz     r9, 592(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(592);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F330:
    ctx->pc = 0x8005F330u;
    // 8005F330: addi    r11, r11, 552
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(552);

label_8005F334:
    ctx->pc = 0x8005F334u;
    // 8005F334: addi    r9, r9, -2
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2);

label_8005F338:
    ctx->pc = 0x8005F338u;
    // 8005F338: rlwinm r9, r9, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[9], 2u) & 0xFFFFFFFCu;
    }

label_8005F33C:
    ctx->pc = 0x8005F33Cu;
    // 8005F33C: lwzx    r0, r11, r9
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[9];
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F340:
    ctx->pc = 0x8005F340u;
    // 8005F340: mulli   r0, r0, 20
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)20);

label_8005F344:
    ctx->pc = 0x8005F344u;
    // 8005F344: lwzx    r4, r16, r0
    {
        u32 ea = ctx->gpr[16] + ctx->gpr[0];
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_8005F348:
    ctx->pc = 0x8005F348u;
    // 8005F348: cmpwi   r4, 0
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

label_8005F34C:
    ctx->pc = 0x8005F34Cu;
    // 8005F34C: bc    12, 2, 0x8005F398
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F398;
        }
    }

label_8005F350:
    ctx->pc = 0x8005F350u;
    ctx->downcount -= 2;
    // 8005F350: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F354:
    ctx->pc = 0x8005F354u;
    // 8005F354: bl      0x80046DA4
    {
            ctx->lr = 0x8005F358u;
            ctx->pc = 0x80046DA4u;
            return;
    }

label_8005F358:
    ctx->pc = 0x8005F358u;
    ctx->downcount -= 4;
    // 8005F358: li      r5, -1
    ctx->gpr[5] = (u32)(s32)(-1);

label_8005F35C:
    ctx->pc = 0x8005F35Cu;
    // 8005F35C: addi    r4, r1, 8
    ctx->gpr[4] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F360:
    ctx->pc = 0x8005F360u;
    // 8005F360: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F364:
    ctx->pc = 0x8005F364u;
    // 8005F364: bl      0x80035A54
    {
            ctx->lr = 0x8005F368u;
            ctx->pc = 0x80035A54u;
            return;
    }

label_8005F368:
    ctx->pc = 0x8005F368u;
    ctx->downcount -= 4;
    // 8005F368: or   r30, r3, r3
    {
        ctx->gpr[30] = ctx->gpr[3] | ctx->gpr[3];
    }

label_8005F36C:
    ctx->pc = 0x8005F36Cu;
    // 8005F36C: li      r4, -1
    ctx->gpr[4] = (u32)(s32)(-1);

label_8005F370:
    ctx->pc = 0x8005F370u;
    // 8005F370: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F374:
    ctx->pc = 0x8005F374u;
    // 8005F374: bl      0x80034BA8
    {
            ctx->lr = 0x8005F378u;
            ctx->pc = 0x80034BA8u;
            return;
    }

label_8005F378:
    ctx->pc = 0x8005F378u;
    ctx->downcount -= 8;
    // 8005F378: subfic  r30, r30, 640
    {
        u64 res = (u64)(u32)(s32)(640) + (u64)(~ctx->gpr[30]) + 1u;
        ctx->gpr[30] = (u32)res;
        ctx->xer = (ctx->xer & ~0x20000000u) | (((u32)(res >> 32) & 1u) << 29);
    }

label_8005F37C:
    ctx->pc = 0x8005F37Cu;
    // 8005F37C: addi    r5, r24, -24
    ctx->gpr[5] = ctx->gpr[24] + (u32)(s32)(-24);

label_8005F380:
    ctx->pc = 0x8005F380u;
    // 8005F380: rlwinm r0, r30, 1, 31, 31
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[30], 1u) & 0x00000001u;
    }

label_8005F384:
    ctx->pc = 0x8005F384u;
    // 8005F384: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F388:
    ctx->pc = 0x8005F388u;
    // 8005F388: add   r30, r30, r0
    {
        u32 a = ctx->gpr[30];
        u32 b = ctx->gpr[0];
        u32 res = a + b;
        ctx->gpr[30] = res;
    }

label_8005F38C:
    ctx->pc = 0x8005F38Cu;
    // 8005F38C: addi    r6, r1, 8
    ctx->gpr[6] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F390:
    ctx->pc = 0x8005F390u;
    // 8005F390: srawi r4, r30, 1
    {
        u32 sh = 1u;
        u32 value = ctx->gpr[30];
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

label_8005F394:
    ctx->pc = 0x8005F394u;
    // 8005F394: bl      0x80034E9C
    {
            ctx->lr = 0x8005F398u;
            ctx->pc = 0x80034E9Cu;
            return;
    }

label_8005F398:
    ctx->pc = 0x8005F398u;
    ctx->downcount -= 3;
    // 8005F398: or   r3, r26, r26
    {
        ctx->gpr[3] = ctx->gpr[26] | ctx->gpr[26];
    }

label_8005F39C:
    ctx->pc = 0x8005F39Cu;
    // 8005F39C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F3A0:
    ctx->pc = 0x8005F3A0u;
    // 8005F3A0: bl      0x800353D4
    {
            ctx->lr = 0x8005F3A4u;
            ctx->pc = 0x800353D4u;
            return;
    }

label_8005F3A4:
    ctx->pc = 0x8005F3A4u;
    ctx->downcount -= 18;
    // 8005F3A4: lwz     r0, 1084(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1084);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F3A8:
    ctx->pc = 0x8005F3A8u;
    // 8005F3A8: lwz     r12, 1008(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1008);
        ctx->gpr[12] = mem_read32(ctx, ea);
    }

label_8005F3AC:
    ctx->pc = 0x8005F3ACu;
    // 8005F3AC: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005F3B0:
    ctx->pc = 0x8005F3B0u;
    // 8005F3B0: lmw     r15, 1012(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(1012);
        for (u32 r = 15; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_8005F3B4:
    ctx->pc = 0x8005F3B4u;
    // 8005F3B4: mtcrf   0x08, r12
    ctx->cr = (ctx->cr & ~0x0000F000u) | (ctx->gpr[12] & 0x0000F000u);

label_8005F3B8:
    ctx->pc = 0x8005F3B8u;
    // 8005F3B8: addi    r1, r1, 1080
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(1080);

label_8005F3BC:
    ctx->pc = 0x8005F3BCu;
    // 8005F3BC: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_8005F3C0:
    ctx->pc = 0x8005F3C0u;
    ctx->downcount -= 6;
    // 8005F3C0: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005F3C4:
    ctx->pc = 0x8005F3C4u;
    // 8005F3C4: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005F3C8:
    ctx->pc = 0x8005F3C8u;
    // 8005F3C8: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F3CC:
    ctx->pc = 0x8005F3CCu;
    // 8005F3CC: lwz     r3, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_8005F3D0:
    ctx->pc = 0x8005F3D0u;
    // 8005F3D0: cmpwi   r3, 0
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

label_8005F3D4:
    ctx->pc = 0x8005F3D4u;
    // 8005F3D4: bc    12, 2, 0x8005F3E4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F3E4;
        }
    }

label_8005F3D8:
    ctx->pc = 0x8005F3D8u;
    ctx->downcount -= 1;
    // 8005F3D8: bl      0x80039A44
    {
            ctx->lr = 0x8005F3DCu;
            ctx->pc = 0x80039A44u;
            return;
    }

label_8005F3DC:
    ctx->pc = 0x8005F3DCu;
    ctx->downcount -= 2;
    // 8005F3DC: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005F3E0:
    ctx->pc = 0x8005F3E0u;
    // 8005F3E0: stw     r0, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F3E4:
    ctx->pc = 0x8005F3E4u;
    ctx->downcount -= 5;
    // 8005F3E4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F3E8:
    ctx->pc = 0x8005F3E8u;
    // 8005F3E8: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8005F3EC:
    ctx->pc = 0x8005F3ECu;
    // 8005F3EC: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F3F0:
    ctx->pc = 0x8005F3F0u;
    // 8005F3F0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_8005F3F4:
    ctx->pc = 0x8005F3F4u;
    ctx->downcount -= 4;
    // 8005F3F4: lwz     r0, 0(r3)
    {
        u32 ea = ctx->gpr[3] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F3F8:
    ctx->pc = 0x8005F3F8u;
    // 8005F3F8: li      r9, 0
    ctx->gpr[9] = (u32)(s32)(0);

label_8005F3FC:
    ctx->pc = 0x8005F3FCu;
    // 8005F3FC: cmpwi   r0, 0
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

label_8005F400:
    ctx->pc = 0x8005F400u;
    // 8005F400: bc    12, 2, 0x8005F414
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F414;
        }
    }

label_8005F404:
    loop_8005F404(ctx);
    if (ctx->pc == 0x8005F414u) goto label_8005F414;
    return;
label_8005F408:
    // 8005F408: addi    r9, r9, 1
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(1);

label_8005F40C:
    // 8005F40C: cmpwi   r0, 0
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

label_8005F410:
    // 8005F410: bc    4, 2, 0x8005F404
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F404u;
                return;
            }
            goto label_8005F404;
        }
    }

label_8005F414:
    ctx->pc = 0x8005F414u;
    ctx->downcount -= 2;
    // 8005F414: or   r3, r9, r9
    {
        ctx->gpr[3] = ctx->gpr[9] | ctx->gpr[9];
    }

label_8005F418:
    ctx->pc = 0x8005F418u;
    // 8005F418: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_8005F41C:
    ctx->pc = 0x8005F41Cu;
    ctx->downcount -= 14;
    // 8005F41C: lwz     r11, -27720(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-27720);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F420:
    ctx->pc = 0x8005F420u;
    // 8005F420: mulli   r3, r3, 20
    ctx->gpr[3] = (u32)((s64)(s32)ctx->gpr[3] * (s64)(s32)20);

label_8005F424:
    ctx->pc = 0x8005F424u;
    // 8005F424: li      r5, 0
    ctx->gpr[5] = (u32)(s32)(0);

label_8005F428:
    ctx->pc = 0x8005F428u;
    // 8005F428: lwz     r10, 592(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(592);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F42C:
    ctx->pc = 0x8005F42Cu;
    // 8005F42C: addi    r7, r11, 512
    ctx->gpr[7] = ctx->gpr[11] + (u32)(s32)(512);

label_8005F430:
    ctx->pc = 0x8005F430u;
    // 8005F430: li      r6, 0
    ctx->gpr[6] = (u32)(s32)(0);

label_8005F434:
    ctx->pc = 0x8005F434u;
    // 8005F434: addi    r0, r10, -1
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-1);

label_8005F438:
    ctx->pc = 0x8005F438u;
    // 8005F438: cmpwi   r10, 1
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

label_8005F43C:
    ctx->pc = 0x8005F43Cu;
    // 8005F43C: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8005F440:
    ctx->pc = 0x8005F440u;
    // 8005F440: lwzx    r9, r7, r0
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F444:
    ctx->pc = 0x8005F444u;
    // 8005F444: add   r8, r9, r3
    {
        u32 a = ctx->gpr[9];
        u32 b = ctx->gpr[3];
        u32 res = a + b;
        ctx->gpr[8] = res;
    }

label_8005F448:
    ctx->pc = 0x8005F448u;
    // 8005F448: bc    4, 1, 0x8005F468
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F468;
        }
    }

label_8005F44C:
    ctx->pc = 0x8005F44Cu;
    ctx->downcount -= 9;
    // 8005F44C: addi    r0, r10, -2
    ctx->gpr[0] = ctx->gpr[10] + (u32)(s32)(-2);

label_8005F450:
    ctx->pc = 0x8005F450u;
    // 8005F450: addi    r11, r11, 552
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(552);

label_8005F454:
    ctx->pc = 0x8005F454u;
    // 8005F454: rlwinm r0, r0, 2, 0, 29
    {
        ctx->gpr[0] = dolrecomp_rotl32(ctx->gpr[0], 2u) & 0xFFFFFFFCu;
    }

label_8005F458:
    ctx->pc = 0x8005F458u;
    // 8005F458: lwzx    r9, r11, r0
    {
        u32 ea = ctx->gpr[11] + ctx->gpr[0];
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F45C:
    ctx->pc = 0x8005F45Cu;
    // 8005F45C: lwzx    r5, r7, r0
    {
        u32 ea = ctx->gpr[7] + ctx->gpr[0];
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8005F460:
    ctx->pc = 0x8005F460u;
    // 8005F460: mulli   r9, r9, 20
    ctx->gpr[9] = (u32)((s64)(s32)ctx->gpr[9] * (s64)(s32)20);

label_8005F464:
    ctx->pc = 0x8005F464u;
    // 8005F464: add   r6, r5, r9
    {
        u32 a = ctx->gpr[5];
        u32 b = ctx->gpr[9];
        u32 res = a + b;
        ctx->gpr[6] = res;
    }

label_8005F468:
    ctx->pc = 0x8005F468u;
    ctx->downcount -= 3;
    // 8005F468: lwz     r0, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F46C:
    ctx->pc = 0x8005F46Cu;
    // 8005F46C: cmplwi  r0, 0x0002
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

label_8005F470:
    ctx->pc = 0x8005F470u;
    // 8005F470: bc    4, 1, 0x8005F480
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F480;
        }
    }

label_8005F474:
    ctx->pc = 0x8005F474u;
    ctx->downcount -= 2;
    // 8005F474: cmplwi  r0, 0x0004
    {
        u32 val_a = (u32)(ctx->gpr[0]);
        u32 val_b = (u32)(0x0004u);
        u32 cr_bits = 0;
        if (val_a < val_b)  cr_bits |= 0x8u;
        if (val_a > val_b)  cr_bits |= 0x4u;
        if (val_a == val_b) cr_bits |= 0x2u;
        cr_bits |= (ctx->xer >> 31) & 1u;
        ctx->cr = (ctx->cr & ~(0xFu << 28)) | (cr_bits << 28);
    }

label_8005F478:
    ctx->pc = 0x8005F478u;
    // 8005F478: bc    12, 1, 0x8005F514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x40000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F514;
        }
    }

label_8005F47C:
    ctx->pc = 0x8005F47Cu;
    ctx->downcount -= 1;
    // 8005F47C: b       0x8005F4D4
    {
            goto label_8005F4D4;
    }

label_8005F480:
    ctx->pc = 0x8005F480u;
    ctx->downcount -= 2;
    // 8005F480: cmplwi  r0, 0x0001
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

label_8005F484:
    ctx->pc = 0x8005F484u;
    // 8005F484: bc    4, 0, 0x8005F4A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F4A0;
        }
    }

label_8005F488:
    ctx->pc = 0x8005F488u;
    ctx->downcount -= 4;
    // 8005F488: lwz     r0, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F48C:
    ctx->pc = 0x8005F48Cu;
    // 8005F48C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005F490:
    ctx->pc = 0x8005F490u;
    // 8005F490: cmpwi   r0, 0
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

label_8005F494:
    ctx->pc = 0x8005F494u;
    // 8005F494: bclr  4, 2
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_8005F498:
    ctx->downcount -= 2;
    // 8005F498: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005F49C:
    ctx->pc = 0x8005F49Cu;
    // 8005F49C: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_8005F4A0:
    ctx->pc = 0x8005F4A0u;
    ctx->downcount -= 10;
    // 8005F4A0: lhz     r0, 14(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005F4A4:
    // 8005F4A4: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005F4A8:
    // 8005F4A8: addi    r9, r9, -2804
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2804);

label_8005F4AC:
    // 8005F4AC: mulli   r0, r0, 24
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)24);

label_8005F4B0:
    // 8005F4B0: addi    r9, r9, 20
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(20);

label_8005F4B4:
    ctx->pc = 0x8005F4B4u;
    // 8005F4B4: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F4B8:
    // 8005F4B8: cmpwi   r11, 0
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

label_8005F4BC:
    // 8005F4BC: bc    4, 2, 0x8005F4CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8005F4CC;
        }
    }

label_8005F4C0:
    ctx->pc = 0x8005F4C0u;
    ctx->downcount -= 3;
    // 8005F4C0: lwz     r0, -31800(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31800);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F4C4:
    // 8005F4C4: andi.   r9, r0, 0x0004
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

label_8005F4C8:
    // 8005F4C8: bc    12, 2, 0x8005F498
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F498u;
                return;
            }
            goto label_8005F498;
        }
    }

label_8005F4CC:
    ctx->downcount -= 2;
    // 8005F4CC: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005F4D0:
    ctx->pc = 0x8005F4D0u;
    // 8005F4D0: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_8005F4D4:
    ctx->downcount -= 2;
    // 8005F4D4: cmpwi   r5, 0
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

label_8005F4D8:
    // 8005F4D8: bc    12, 2, 0x8005F514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F514;
        }
    }

label_8005F4DC:
    ctx->downcount -= 2;
    // 8005F4DC: cmpwi   r6, 0
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

label_8005F4E0:
    // 8005F4E0: bc    12, 2, 0x8005F514
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_8005F514;
        }
    }

label_8005F4E4:
    ctx->pc = 0x8005F4E4u;
    ctx->downcount -= 10;
    // 8005F4E4: lhz     r0, 14(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(14);
        ctx->gpr[0] = mem_read16(ctx, ea);
    }

label_8005F4E8:
    // 8005F4E8: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005F4EC:
    // 8005F4EC: addi    r9, r9, -2804
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(-2804);

label_8005F4F0:
    // 8005F4F0: mulli   r0, r0, 24
    ctx->gpr[0] = (u32)((s64)(s32)ctx->gpr[0] * (s64)(s32)24);

label_8005F4F4:
    // 8005F4F4: addi    r9, r9, 20
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(20);

label_8005F4F8:
    ctx->pc = 0x8005F4F8u;
    // 8005F4F8: lwzx    r11, r9, r0
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[0];
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F4FC:
    // 8005F4FC: cmpwi   r11, 0
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

label_8005F500:
    // 8005F500: bc    4, 2, 0x8005F4CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F4CCu;
                return;
            }
            goto label_8005F4CC;
        }
    }

label_8005F504:
    ctx->pc = 0x8005F504u;
    ctx->downcount -= 3;
    // 8005F504: lwz     r0, -31800(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31800);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F508:
    // 8005F508: andi.   r9, r0, 0x0004
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

label_8005F50C:
    // 8005F50C: bc    4, 2, 0x8005F4CC
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F4CCu;
                return;
            }
            goto label_8005F4CC;
        }
    }

label_8005F510:
    ctx->downcount -= 1;
    // 8005F510: b       0x8005F498
    {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F498u;
                return;
            }
            goto label_8005F498;
    }

label_8005F514:
    ctx->pc = 0x8005F514u;
    ctx->downcount -= 2;
    // 8005F514: li      r3, 0
    ctx->gpr[3] = (u32)(s32)(0);

label_8005F518:
    ctx->pc = 0x8005F518u;
    // 8005F518: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_8005F51C:
    ctx->pc = 0x8005F51Cu;
    ctx->downcount -= 18;
    // 8005F51C: stwu     r1, -336(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-336);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8005F520:
    ctx->pc = 0x8005F520u;
    // 8005F520: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8005F524:
    ctx->pc = 0x8005F524u;
    // 8005F524: stmw     r14, 264(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(264);
        for (u32 r = 14; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_8005F528:
    ctx->pc = 0x8005F528u;
    // 8005F528: stw     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F52C:
    ctx->pc = 0x8005F52Cu;
    // 8005F52C: li      r0, 0
    ctx->gpr[0] = (u32)(s32)(0);

label_8005F530:
    ctx->pc = 0x8005F530u;
    // 8005F530: ori     r0, r0, 0xFFFF
    ctx->gpr[0] = ctx->gpr[0] | 0xFFFFu;

label_8005F534:
    ctx->pc = 0x8005F534u;
    // 8005F534: cmpw    r4, r0
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

label_8005F538:
    ctx->pc = 0x8005F538u;
    // 8005F538: bc    4, 2, 0x80063124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80063124;
        }
    }

label_8005F53C:
    ctx->pc = 0x8005F53Cu;
    ctx->downcount -= 2;
    // 8005F53C: cmpwi   r3, 0
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

label_8005F540:
    ctx->pc = 0x8005F540u;
    // 8005F540: bc    12, 2, 0x80063124
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            goto label_80063124;
        }
    }

label_8005F544:
    ctx->pc = 0x8005F544u;
    ctx->downcount -= 6;
    // 8005F544: addi    r29, r1, 8
    ctx->gpr[29] = ctx->gpr[1] + (u32)(s32)(8);

label_8005F548:
    ctx->pc = 0x8005F548u;
    // 8005F548: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F54C:
    ctx->pc = 0x8005F54Cu;
    // 8005F54C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F550:
    ctx->pc = 0x8005F550u;
    // 8005F550: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F554:
    ctx->pc = 0x8005F554u;
    // 8005F554: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F558:
    ctx->pc = 0x8005F558u;
    // 8005F558: bl      0x801698F0
    {
            ctx->lr = 0x8005F55Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F55C:
    ctx->pc = 0x8005F55Cu;
    ctx->downcount -= 38;
    // 8005F55C: li      r31, 6
    ctx->gpr[31] = (u32)(s32)(6);

label_8005F560:
    ctx->pc = 0x8005F560u;
    // 8005F560: lis     r26, -32735
    ctx->gpr[26] = ((u32)(s32)(-32735) << 16);

label_8005F564:
    ctx->pc = 0x8005F564u;
    // 8005F564: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F568:
    ctx->pc = 0x8005F568u;
    // 8005F568: addi    r26, r26, -2804
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(-2804);

label_8005F56C:
    ctx->pc = 0x8005F56Cu;
    // 8005F56C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_8005F570:
    ctx->pc = 0x8005F570u;
    // 8005F570: lwz     r11, 104(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(104);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F574:
    ctx->pc = 0x8005F574u;
    // 8005F574: li      r0, 4
    ctx->gpr[0] = (u32)(s32)(4);

label_8005F578:
    ctx->pc = 0x8005F578u;
    // 8005F578: addi    r3, r3, 6556
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6556);

label_8005F57C:
    ctx->pc = 0x8005F57Cu;
    // 8005F57C: li      r5, 1
    ctx->gpr[5] = (u32)(s32)(1);

label_8005F580:
    ctx->pc = 0x8005F580u;
    // 8005F580: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F584:
    ctx->pc = 0x8005F584u;
    // 8005F584: addi    r30, r9, 12200
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(12200);

label_8005F588:
    ctx->pc = 0x8005F588u;
    // 8005F588: stw     r5, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_8005F58C:
    ctx->pc = 0x8005F58Cu;
    // 8005F58C: lis     r6, 1
    ctx->gpr[6] = ((u32)(s32)(1) << 16);

label_8005F590:
    ctx->pc = 0x8005F590u;
    // 8005F590: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F594:
    ctx->pc = 0x8005F594u;
    // 8005F594: ori     r6, r6, 0x0006
    ctx->gpr[6] = ctx->gpr[6] | 0x0006u;

label_8005F598:
    ctx->pc = 0x8005F598u;
    // 8005F598: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F59C:
    ctx->pc = 0x8005F59Cu;
    // 8005F59C: lis     r7, 3
    ctx->gpr[7] = ((u32)(s32)(3) << 16);

label_8005F5A0:
    ctx->pc = 0x8005F5A0u;
    // 8005F5A0: stw     r11, 12200(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12200);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F5A4:
    ctx->pc = 0x8005F5A4u;
    // 8005F5A4: ori     r7, r7, 0x0022
    ctx->gpr[7] = ctx->gpr[7] | 0x0022u;

label_8005F5A8:
    ctx->pc = 0x8005F5A8u;
    // 8005F5A8: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F5AC:
    ctx->pc = 0x8005F5ACu;
    // 8005F5AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F5B0:
    ctx->pc = 0x8005F5B0u;
    // 8005F5B0: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F5B4:
    ctx->pc = 0x8005F5B4u;
    // 8005F5B4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F5B8:
    ctx->pc = 0x8005F5B8u;
    // 8005F5B8: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F5BC:
    ctx->pc = 0x8005F5BCu;
    // 8005F5BC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F5C0:
    ctx->pc = 0x8005F5C0u;
    // 8005F5C0: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F5C4:
    ctx->pc = 0x8005F5C4u;
    // 8005F5C4: or   r28, r29, r29
    {
        ctx->gpr[28] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F5C8:
    ctx->pc = 0x8005F5C8u;
    // 8005F5C8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F5CC:
    ctx->pc = 0x8005F5CCu;
    // 8005F5CC: or   r27, r28, r28
    {
        ctx->gpr[27] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8005F5D0:
    ctx->pc = 0x8005F5D0u;
    // 8005F5D0: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F5D4:
    ctx->pc = 0x8005F5D4u;
    // 8005F5D4: lis     r25, -32738
    ctx->gpr[25] = ((u32)(s32)(-32738) << 16);

label_8005F5D8:
    ctx->pc = 0x8005F5D8u;
    // 8005F5D8: stw     r6, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F5DC:
    ctx->pc = 0x8005F5DCu;
    // 8005F5DC: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F5E0:
    ctx->pc = 0x8005F5E0u;
    // 8005F5E0: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F5E4:
    ctx->pc = 0x8005F5E4u;
    // 8005F5E4: stw     r7, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005F5E8:
    ctx->pc = 0x8005F5E8u;
    // 8005F5E8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F5EC:
    ctx->pc = 0x8005F5ECu;
    // 8005F5EC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F5F0:
    ctx->pc = 0x8005F5F0u;
    // 8005F5F0: bl      0x801698F0
    {
            ctx->lr = 0x8005F5F4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F5F4:
    ctx->pc = 0x8005F5F4u;
    ctx->downcount -= 29;
    // 8005F5F4: lwz     r9, 128(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(128);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F5F8:
    ctx->pc = 0x8005F5F8u;
    // 8005F5F8: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F5FC:
    ctx->pc = 0x8005F5FCu;
    // 8005F5FC: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8005F600:
    ctx->pc = 0x8005F600u;
    // 8005F600: li      r0, 5
    ctx->gpr[0] = (u32)(s32)(5);

label_8005F604:
    ctx->pc = 0x8005F604u;
    // 8005F604: addi    r3, r3, 6736
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6736);

label_8005F608:
    ctx->pc = 0x8005F608u;
    // 8005F608: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F60C:
    ctx->pc = 0x8005F60Cu;
    // 8005F60C: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F610:
    ctx->pc = 0x8005F610u;
    // 8005F610: lis     r7, 4
    ctx->gpr[7] = ((u32)(s32)(4) << 16);

label_8005F614:
    ctx->pc = 0x8005F614u;
    // 8005F614: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F618:
    ctx->pc = 0x8005F618u;
    // 8005F618: ori     r7, r7, 0x0003
    ctx->gpr[7] = ctx->gpr[7] | 0x0003u;

label_8005F61C:
    ctx->pc = 0x8005F61Cu;
    // 8005F61C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F620:
    ctx->pc = 0x8005F620u;
    // 8005F620: lis     r8, 5
    ctx->gpr[8] = ((u32)(s32)(5) << 16);

label_8005F624:
    ctx->pc = 0x8005F624u;
    // 8005F624: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F628:
    ctx->pc = 0x8005F628u;
    // 8005F628: ori     r8, r8, 0x0022
    ctx->gpr[8] = ctx->gpr[8] | 0x0022u;

label_8005F62C:
    ctx->pc = 0x8005F62Cu;
    // 8005F62C: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F630:
    ctx->pc = 0x8005F630u;
    // 8005F630: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F634:
    ctx->pc = 0x8005F634u;
    // 8005F634: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F638:
    ctx->pc = 0x8005F638u;
    // 8005F638: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F63C:
    ctx->pc = 0x8005F63Cu;
    // 8005F63C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F640:
    ctx->pc = 0x8005F640u;
    // 8005F640: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F644:
    ctx->pc = 0x8005F644u;
    // 8005F644: stw     r7, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005F648:
    ctx->pc = 0x8005F648u;
    // 8005F648: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F64C:
    ctx->pc = 0x8005F64Cu;
    // 8005F64C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F650:
    ctx->pc = 0x8005F650u;
    // 8005F650: stw     r8, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005F654:
    ctx->pc = 0x8005F654u;
    // 8005F654: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F658:
    ctx->pc = 0x8005F658u;
    // 8005F658: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F65C:
    ctx->pc = 0x8005F65Cu;
    // 8005F65C: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F660:
    ctx->pc = 0x8005F660u;
    // 8005F660: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F664:
    ctx->pc = 0x8005F664u;
    // 8005F664: bl      0x801698F0
    {
            ctx->lr = 0x8005F668u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F668:
    ctx->pc = 0x8005F668u;
    ctx->downcount -= 26;
    // 8005F668: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F66C:
    ctx->pc = 0x8005F66Cu;
    // 8005F66C: lwz     r0, 152(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(152);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F670:
    ctx->pc = 0x8005F670u;
    // 8005F670: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F674:
    ctx->pc = 0x8005F674u;
    // 8005F674: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8005F678:
    ctx->pc = 0x8005F678u;
    // 8005F678: addi    r3, r3, 6936
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6936);

label_8005F67C:
    ctx->pc = 0x8005F67Cu;
    // 8005F67C: stw     r31, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005F680:
    ctx->pc = 0x8005F680u;
    // 8005F680: lis     r7, -32699
    ctx->gpr[7] = ((u32)(s32)(-32699) << 16);

label_8005F684:
    ctx->pc = 0x8005F684u;
    // 8005F684: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F688:
    ctx->pc = 0x8005F688u;
    // 8005F688: addi    r7, r7, 15240
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(15240);

label_8005F68C:
    ctx->pc = 0x8005F68Cu;
    // 8005F68C: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F690:
    ctx->pc = 0x8005F690u;
    // 8005F690: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F694:
    ctx->pc = 0x8005F694u;
    // 8005F694: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F698:
    ctx->pc = 0x8005F698u;
    // 8005F698: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F69C:
    ctx->pc = 0x8005F69Cu;
    // 8005F69C: stw     r0, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F6A0:
    ctx->pc = 0x8005F6A0u;
    // 8005F6A0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F6A4:
    ctx->pc = 0x8005F6A4u;
    // 8005F6A4: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F6A8:
    ctx->pc = 0x8005F6A8u;
    // 8005F6A8: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F6AC:
    ctx->pc = 0x8005F6ACu;
    // 8005F6AC: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F6B0:
    ctx->pc = 0x8005F6B0u;
    // 8005F6B0: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F6B4:
    ctx->pc = 0x8005F6B4u;
    // 8005F6B4: stw     r7, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005F6B8:
    ctx->pc = 0x8005F6B8u;
    // 8005F6B8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F6BC:
    ctx->pc = 0x8005F6BCu;
    // 8005F6BC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F6C0:
    ctx->pc = 0x8005F6C0u;
    // 8005F6C0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F6C4:
    ctx->pc = 0x8005F6C4u;
    // 8005F6C4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F6C8:
    ctx->pc = 0x8005F6C8u;
    // 8005F6C8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F6CC:
    ctx->pc = 0x8005F6CCu;
    // 8005F6CC: bl      0x801698F0
    {
            ctx->lr = 0x8005F6D0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F6D0:
    ctx->pc = 0x8005F6D0u;
    ctx->downcount -= 24;
    // 8005F6D0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F6D4:
    ctx->pc = 0x8005F6D4u;
    // 8005F6D4: lwz     r9, 176(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F6D8:
    ctx->pc = 0x8005F6D8u;
    // 8005F6D8: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F6DC:
    ctx->pc = 0x8005F6DCu;
    // 8005F6DC: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8005F6E0:
    ctx->pc = 0x8005F6E0u;
    // 8005F6E0: li      r0, 7
    ctx->gpr[0] = (u32)(s32)(7);

label_8005F6E4:
    ctx->pc = 0x8005F6E4u;
    // 8005F6E4: addi    r3, r3, 6996
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6996);

label_8005F6E8:
    ctx->pc = 0x8005F6E8u;
    // 8005F6E8: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F6EC:
    ctx->pc = 0x8005F6ECu;
    // 8005F6EC: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F6F0:
    ctx->pc = 0x8005F6F0u;
    // 8005F6F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F6F4:
    ctx->pc = 0x8005F6F4u;
    // 8005F6F4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F6F8:
    ctx->pc = 0x8005F6F8u;
    // 8005F6F8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F6FC:
    ctx->pc = 0x8005F6FCu;
    // 8005F6FC: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F700:
    ctx->pc = 0x8005F700u;
    // 8005F700: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F704:
    ctx->pc = 0x8005F704u;
    // 8005F704: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F708:
    ctx->pc = 0x8005F708u;
    // 8005F708: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F70C:
    ctx->pc = 0x8005F70Cu;
    // 8005F70C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F710:
    ctx->pc = 0x8005F710u;
    // 8005F710: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F714:
    ctx->pc = 0x8005F714u;
    // 8005F714: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F718:
    ctx->pc = 0x8005F718u;
    // 8005F718: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F71C:
    ctx->pc = 0x8005F71Cu;
    // 8005F71C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F720:
    ctx->pc = 0x8005F720u;
    // 8005F720: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F724:
    ctx->pc = 0x8005F724u;
    // 8005F724: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F728:
    ctx->pc = 0x8005F728u;
    // 8005F728: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F72C:
    ctx->pc = 0x8005F72Cu;
    // 8005F72C: bl      0x801698F0
    {
            ctx->lr = 0x8005F730u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F730:
    ctx->pc = 0x8005F730u;
    ctx->downcount -= 24;
    // 8005F730: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F734:
    ctx->pc = 0x8005F734u;
    // 8005F734: lwz     r9, 200(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(200);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F738:
    ctx->pc = 0x8005F738u;
    // 8005F738: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F73C:
    ctx->pc = 0x8005F73Cu;
    // 8005F73C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8005F740:
    ctx->pc = 0x8005F740u;
    // 8005F740: li      r0, 8
    ctx->gpr[0] = (u32)(s32)(8);

label_8005F744:
    ctx->pc = 0x8005F744u;
    // 8005F744: addi    r3, r3, 7076
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7076);

label_8005F748:
    ctx->pc = 0x8005F748u;
    // 8005F748: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F74C:
    ctx->pc = 0x8005F74Cu;
    // 8005F74C: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F750:
    ctx->pc = 0x8005F750u;
    // 8005F750: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F754:
    ctx->pc = 0x8005F754u;
    // 8005F754: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F758:
    ctx->pc = 0x8005F758u;
    // 8005F758: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F75C:
    ctx->pc = 0x8005F75Cu;
    // 8005F75C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F760:
    ctx->pc = 0x8005F760u;
    // 8005F760: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F764:
    ctx->pc = 0x8005F764u;
    // 8005F764: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F768:
    ctx->pc = 0x8005F768u;
    // 8005F768: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F76C:
    ctx->pc = 0x8005F76Cu;
    // 8005F76C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F770:
    ctx->pc = 0x8005F770u;
    // 8005F770: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F774:
    ctx->pc = 0x8005F774u;
    // 8005F774: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F778:
    ctx->pc = 0x8005F778u;
    // 8005F778: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F77C:
    ctx->pc = 0x8005F77Cu;
    // 8005F77C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F780:
    ctx->pc = 0x8005F780u;
    // 8005F780: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F784:
    ctx->pc = 0x8005F784u;
    // 8005F784: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F788:
    ctx->pc = 0x8005F788u;
    // 8005F788: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F78C:
    ctx->pc = 0x8005F78Cu;
    // 8005F78C: bl      0x801698F0
    {
            ctx->lr = 0x8005F790u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F790:
    ctx->pc = 0x8005F790u;
    ctx->downcount -= 24;
    // 8005F790: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F794:
    ctx->pc = 0x8005F794u;
    // 8005F794: lwz     r9, 224(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(224);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F798:
    ctx->pc = 0x8005F798u;
    // 8005F798: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F79C:
    ctx->pc = 0x8005F79Cu;
    // 8005F79C: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8005F7A0:
    ctx->pc = 0x8005F7A0u;
    // 8005F7A0: li      r0, 9
    ctx->gpr[0] = (u32)(s32)(9);

label_8005F7A4:
    ctx->pc = 0x8005F7A4u;
    // 8005F7A4: addi    r3, r3, 7236
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7236);

label_8005F7A8:
    ctx->pc = 0x8005F7A8u;
    // 8005F7A8: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F7AC:
    ctx->pc = 0x8005F7ACu;
    // 8005F7AC: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F7B0:
    ctx->pc = 0x8005F7B0u;
    // 8005F7B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F7B4:
    ctx->pc = 0x8005F7B4u;
    // 8005F7B4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F7B8:
    ctx->pc = 0x8005F7B8u;
    // 8005F7B8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F7BC:
    ctx->pc = 0x8005F7BCu;
    // 8005F7BC: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F7C0:
    ctx->pc = 0x8005F7C0u;
    // 8005F7C0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F7C4:
    ctx->pc = 0x8005F7C4u;
    // 8005F7C4: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F7C8:
    ctx->pc = 0x8005F7C8u;
    // 8005F7C8: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F7CC:
    ctx->pc = 0x8005F7CCu;
    // 8005F7CC: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F7D0:
    ctx->pc = 0x8005F7D0u;
    // 8005F7D0: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F7D4:
    ctx->pc = 0x8005F7D4u;
    // 8005F7D4: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F7D8:
    ctx->pc = 0x8005F7D8u;
    // 8005F7D8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F7DC:
    ctx->pc = 0x8005F7DCu;
    // 8005F7DC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F7E0:
    ctx->pc = 0x8005F7E0u;
    // 8005F7E0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F7E4:
    ctx->pc = 0x8005F7E4u;
    // 8005F7E4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F7E8:
    ctx->pc = 0x8005F7E8u;
    // 8005F7E8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F7EC:
    ctx->pc = 0x8005F7ECu;
    // 8005F7EC: bl      0x801698F0
    {
            ctx->lr = 0x8005F7F0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F7F0:
    ctx->pc = 0x8005F7F0u;
    ctx->downcount -= 24;
    // 8005F7F0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F7F4:
    ctx->pc = 0x8005F7F4u;
    // 8005F7F4: lwz     r9, 248(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(248);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F7F8:
    ctx->pc = 0x8005F7F8u;
    // 8005F7F8: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F7FC:
    ctx->pc = 0x8005F7FCu;
    // 8005F7FC: addi    r31, r3, 7136
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(7136);

label_8005F800:
    ctx->pc = 0x8005F800u;
    // 8005F800: li      r6, 1
    ctx->gpr[6] = (u32)(s32)(1);

label_8005F804:
    ctx->pc = 0x8005F804u;
    // 8005F804: li      r0, 10
    ctx->gpr[0] = (u32)(s32)(10);

label_8005F808:
    ctx->pc = 0x8005F808u;
    // 8005F808: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005F80C:
    ctx->pc = 0x8005F80Cu;
    // 8005F80C: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F810:
    ctx->pc = 0x8005F810u;
    // 8005F810: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F814:
    ctx->pc = 0x8005F814u;
    // 8005F814: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F818:
    ctx->pc = 0x8005F818u;
    // 8005F818: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F81C:
    ctx->pc = 0x8005F81Cu;
    // 8005F81C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F820:
    ctx->pc = 0x8005F820u;
    // 8005F820: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F824:
    ctx->pc = 0x8005F824u;
    // 8005F824: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F828:
    ctx->pc = 0x8005F828u;
    // 8005F828: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F82C:
    ctx->pc = 0x8005F82Cu;
    // 8005F82C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F830:
    ctx->pc = 0x8005F830u;
    // 8005F830: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F834:
    ctx->pc = 0x8005F834u;
    // 8005F834: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F838:
    ctx->pc = 0x8005F838u;
    // 8005F838: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F83C:
    ctx->pc = 0x8005F83Cu;
    // 8005F83C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F840:
    ctx->pc = 0x8005F840u;
    // 8005F840: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F844:
    ctx->pc = 0x8005F844u;
    // 8005F844: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F848:
    ctx->pc = 0x8005F848u;
    // 8005F848: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F84C:
    ctx->pc = 0x8005F84Cu;
    // 8005F84C: bl      0x801698F0
    {
            ctx->lr = 0x8005F850u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F850:
    ctx->pc = 0x8005F850u;
    ctx->downcount -= 24;
    // 8005F850: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F854:
    ctx->pc = 0x8005F854u;
    // 8005F854: lwz     r9, 272(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(272);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F858:
    ctx->pc = 0x8005F858u;
    // 8005F858: lis     r6, -32735
    ctx->gpr[6] = ((u32)(s32)(-32735) << 16);

label_8005F85C:
    ctx->pc = 0x8005F85Cu;
    // 8005F85C: addi    r6, r6, 7336
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(7336);

label_8005F860:
    ctx->pc = 0x8005F860u;
    // 8005F860: li      r0, 11
    ctx->gpr[0] = (u32)(s32)(11);

label_8005F864:
    ctx->pc = 0x8005F864u;
    // 8005F864: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8005F868:
    ctx->pc = 0x8005F868u;
    // 8005F868: stw     r6, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F86C:
    ctx->pc = 0x8005F86Cu;
    // 8005F86C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F870:
    ctx->pc = 0x8005F870u;
    // 8005F870: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F874:
    ctx->pc = 0x8005F874u;
    // 8005F874: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F878:
    ctx->pc = 0x8005F878u;
    // 8005F878: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F87C:
    ctx->pc = 0x8005F87Cu;
    // 8005F87C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F880:
    ctx->pc = 0x8005F880u;
    // 8005F880: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F884:
    ctx->pc = 0x8005F884u;
    // 8005F884: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F888:
    ctx->pc = 0x8005F888u;
    // 8005F888: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F88C:
    ctx->pc = 0x8005F88Cu;
    // 8005F88C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F890:
    ctx->pc = 0x8005F890u;
    // 8005F890: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F894:
    ctx->pc = 0x8005F894u;
    // 8005F894: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F898:
    ctx->pc = 0x8005F898u;
    // 8005F898: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F89C:
    ctx->pc = 0x8005F89Cu;
    // 8005F89C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F8A0:
    ctx->pc = 0x8005F8A0u;
    // 8005F8A0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F8A4:
    ctx->pc = 0x8005F8A4u;
    // 8005F8A4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F8A8:
    ctx->pc = 0x8005F8A8u;
    // 8005F8A8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F8AC:
    ctx->pc = 0x8005F8ACu;
    // 8005F8AC: bl      0x801698F0
    {
            ctx->lr = 0x8005F8B0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F8B0:
    ctx->pc = 0x8005F8B0u;
    ctx->downcount -= 5;
    // 8005F8B0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F8B4:
    ctx->pc = 0x8005F8B4u;
    // 8005F8B4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F8B8:
    ctx->pc = 0x8005F8B8u;
    // 8005F8B8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F8BC:
    ctx->pc = 0x8005F8BCu;
    // 8005F8BC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F8C0:
    ctx->pc = 0x8005F8C0u;
    // 8005F8C0: bl      0x801698F0
    {
            ctx->lr = 0x8005F8C4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F8C4:
    ctx->pc = 0x8005F8C4u;
    ctx->downcount -= 23;
    // 8005F8C4: lwz     r0, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F8C8:
    ctx->pc = 0x8005F8C8u;
    // 8005F8C8: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005F8CC:
    ctx->pc = 0x8005F8CCu;
    // 8005F8CC: lis     r7, -32699
    ctx->gpr[7] = ((u32)(s32)(-32699) << 16);

label_8005F8D0:
    ctx->pc = 0x8005F8D0u;
    // 8005F8D0: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F8D4:
    ctx->pc = 0x8005F8D4u;
    // 8005F8D4: stw     r0, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F8D8:
    ctx->pc = 0x8005F8D8u;
    // 8005F8D8: lis     r5, -32699
    ctx->gpr[5] = ((u32)(s32)(-32699) << 16);

label_8005F8DC:
    ctx->pc = 0x8005F8DCu;
    // 8005F8DC: stw     r0, 12380(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(12380);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F8E0:
    ctx->pc = 0x8005F8E0u;
    // 8005F8E0: addi    r5, r5, 12380
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(12380);

label_8005F8E4:
    ctx->pc = 0x8005F8E4u;
    // 8005F8E4: lwz     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F8E8:
    ctx->pc = 0x8005F8E8u;
    // 8005F8E8: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_8005F8EC:
    ctx->pc = 0x8005F8ECu;
    // 8005F8EC: lwz     r9, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F8F0:
    ctx->pc = 0x8005F8F0u;
    // 8005F8F0: addi    r8, r8, 12380
    ctx->gpr[8] = ctx->gpr[8] + (u32)(s32)(12380);

label_8005F8F4:
    ctx->pc = 0x8005F8F4u;
    // 8005F8F4: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F8F8:
    ctx->pc = 0x8005F8F8u;
    // 8005F8F8: addi    r3, r5, 20
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(20);

label_8005F8FC:
    ctx->pc = 0x8005F8FCu;
    // 8005F8FC: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F900:
    ctx->pc = 0x8005F900u;
    // 8005F900: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F904:
    ctx->pc = 0x8005F904u;
    // 8005F904: stw     r9, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F908:
    ctx->pc = 0x8005F908u;
    // 8005F908: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F90C:
    ctx->pc = 0x8005F90Cu;
    // 8005F90C: stw     r0, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F910:
    ctx->pc = 0x8005F910u;
    // 8005F910: stw     r11, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F914:
    ctx->pc = 0x8005F914u;
    // 8005F914: stw     r10, 16(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F918:
    ctx->pc = 0x8005F918u;
    // 8005F918: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F91C:
    ctx->pc = 0x8005F91Cu;
    // 8005F91C: bl      0x801698F0
    {
            ctx->lr = 0x8005F920u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F920:
    ctx->pc = 0x8005F920u;
    ctx->downcount -= 19;
    // 8005F920: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005F924:
    ctx->pc = 0x8005F924u;
    // 8005F924: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_8005F928:
    ctx->pc = 0x8005F928u;
    // 8005F928: lwz     r7, 30896(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30896);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005F92C:
    ctx->pc = 0x8005F92Cu;
    // 8005F92C: addi    r30, r8, 12420
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(12420);

label_8005F930:
    ctx->pc = 0x8005F930u;
    // 8005F930: addi    r9, r9, 30896
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(30896);

label_8005F934:
    ctx->pc = 0x8005F934u;
    // 8005F934: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F938:
    ctx->pc = 0x8005F938u;
    // 8005F938: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005F93C:
    ctx->pc = 0x8005F93Cu;
    // 8005F93C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F940:
    ctx->pc = 0x8005F940u;
    // 8005F940: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F944:
    ctx->pc = 0x8005F944u;
    // 8005F944: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F948:
    ctx->pc = 0x8005F948u;
    // 8005F948: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F94C:
    ctx->pc = 0x8005F94Cu;
    // 8005F94C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F950:
    ctx->pc = 0x8005F950u;
    // 8005F950: stw     r7, 12420(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12420);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005F954:
    ctx->pc = 0x8005F954u;
    // 8005F954: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F958:
    ctx->pc = 0x8005F958u;
    // 8005F958: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F95C:
    ctx->pc = 0x8005F95Cu;
    // 8005F95C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F960:
    ctx->pc = 0x8005F960u;
    // 8005F960: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F964:
    ctx->pc = 0x8005F964u;
    // 8005F964: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F968:
    ctx->pc = 0x8005F968u;
    // 8005F968: bl      0x801698F0
    {
            ctx->lr = 0x8005F96Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F96C:
    ctx->pc = 0x8005F96Cu;
    ctx->downcount -= 25;
    // 8005F96C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F970:
    ctx->pc = 0x8005F970u;
    // 8005F970: lwz     r9, 104(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(104);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F974:
    ctx->pc = 0x8005F974u;
    // 8005F974: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005F978:
    ctx->pc = 0x8005F978u;
    // 8005F978: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F97C:
    ctx->pc = 0x8005F97Cu;
    // 8005F97C: ori     r0, r0, 0x0004
    ctx->gpr[0] = ctx->gpr[0] | 0x0004u;

label_8005F980:
    ctx->pc = 0x8005F980u;
    // 8005F980: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005F984:
    ctx->pc = 0x8005F984u;
    // 8005F984: addi    r3, r3, 6556
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6556);

label_8005F988:
    ctx->pc = 0x8005F988u;
    // 8005F988: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F98C:
    ctx->pc = 0x8005F98Cu;
    // 8005F98C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F990:
    ctx->pc = 0x8005F990u;
    // 8005F990: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F994:
    ctx->pc = 0x8005F994u;
    // 8005F994: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F998:
    ctx->pc = 0x8005F998u;
    // 8005F998: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F99C:
    ctx->pc = 0x8005F99Cu;
    // 8005F99C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005F9A0:
    ctx->pc = 0x8005F9A0u;
    // 8005F9A0: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F9A4:
    ctx->pc = 0x8005F9A4u;
    // 8005F9A4: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F9A8:
    ctx->pc = 0x8005F9A8u;
    // 8005F9A8: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F9AC:
    ctx->pc = 0x8005F9ACu;
    // 8005F9AC: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005F9B0:
    ctx->pc = 0x8005F9B0u;
    // 8005F9B0: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005F9B4:
    ctx->pc = 0x8005F9B4u;
    // 8005F9B4: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005F9B8:
    ctx->pc = 0x8005F9B8u;
    // 8005F9B8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005F9BC:
    ctx->pc = 0x8005F9BCu;
    // 8005F9BC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005F9C0:
    ctx->pc = 0x8005F9C0u;
    // 8005F9C0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005F9C4:
    ctx->pc = 0x8005F9C4u;
    // 8005F9C4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005F9C8:
    ctx->pc = 0x8005F9C8u;
    // 8005F9C8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005F9CC:
    ctx->pc = 0x8005F9CCu;
    // 8005F9CC: bl      0x801698F0
    {
            ctx->lr = 0x8005F9D0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005F9D0:
    ctx->pc = 0x8005F9D0u;
    ctx->downcount -= 25;
    // 8005F9D0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005F9D4:
    ctx->pc = 0x8005F9D4u;
    // 8005F9D4: lwz     r9, 128(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(128);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005F9D8:
    ctx->pc = 0x8005F9D8u;
    // 8005F9D8: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005F9DC:
    ctx->pc = 0x8005F9DCu;
    // 8005F9DC: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005F9E0:
    ctx->pc = 0x8005F9E0u;
    // 8005F9E0: ori     r0, r0, 0x0005
    ctx->gpr[0] = ctx->gpr[0] | 0x0005u;

label_8005F9E4:
    ctx->pc = 0x8005F9E4u;
    // 8005F9E4: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005F9E8:
    ctx->pc = 0x8005F9E8u;
    // 8005F9E8: addi    r3, r3, 6736
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6736);

label_8005F9EC:
    ctx->pc = 0x8005F9ECu;
    // 8005F9EC: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005F9F0:
    ctx->pc = 0x8005F9F0u;
    // 8005F9F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005F9F4:
    ctx->pc = 0x8005F9F4u;
    // 8005F9F4: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005F9F8:
    ctx->pc = 0x8005F9F8u;
    // 8005F9F8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005F9FC:
    ctx->pc = 0x8005F9FCu;
    // 8005F9FC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FA00:
    ctx->pc = 0x8005FA00u;
    // 8005FA00: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FA04:
    ctx->pc = 0x8005FA04u;
    // 8005FA04: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FA08:
    ctx->pc = 0x8005FA08u;
    // 8005FA08: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FA0C:
    ctx->pc = 0x8005FA0Cu;
    // 8005FA0C: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FA10:
    ctx->pc = 0x8005FA10u;
    // 8005FA10: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FA14:
    ctx->pc = 0x8005FA14u;
    // 8005FA14: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FA18:
    ctx->pc = 0x8005FA18u;
    // 8005FA18: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FA1C:
    ctx->pc = 0x8005FA1Cu;
    // 8005FA1C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FA20:
    ctx->pc = 0x8005FA20u;
    // 8005FA20: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FA24:
    ctx->pc = 0x8005FA24u;
    // 8005FA24: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FA28:
    ctx->pc = 0x8005FA28u;
    // 8005FA28: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FA2C:
    ctx->pc = 0x8005FA2Cu;
    // 8005FA2C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FA30:
    ctx->pc = 0x8005FA30u;
    // 8005FA30: bl      0x801698F0
    {
            ctx->lr = 0x8005FA34u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FA34:
    ctx->pc = 0x8005FA34u;
    ctx->downcount -= 24;
    // 8005FA34: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FA38:
    ctx->pc = 0x8005FA38u;
    // 8005FA38: lwz     r7, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005FA3C:
    ctx->pc = 0x8005FA3Cu;
    // 8005FA3C: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005FA40:
    ctx->pc = 0x8005FA40u;
    // 8005FA40: lwz     r9, 152(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(152);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FA44:
    ctx->pc = 0x8005FA44u;
    // 8005FA44: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005FA48:
    ctx->pc = 0x8005FA48u;
    // 8005FA48: addi    r3, r3, 6936
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6936);

label_8005FA4C:
    ctx->pc = 0x8005FA4Cu;
    // 8005FA4C: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FA50:
    ctx->pc = 0x8005FA50u;
    // 8005FA50: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FA54:
    ctx->pc = 0x8005FA54u;
    // 8005FA54: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FA58:
    ctx->pc = 0x8005FA58u;
    // 8005FA58: stw     r7, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005FA5C:
    ctx->pc = 0x8005FA5Cu;
    // 8005FA5C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FA60:
    ctx->pc = 0x8005FA60u;
    // 8005FA60: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FA64:
    ctx->pc = 0x8005FA64u;
    // 8005FA64: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FA68:
    ctx->pc = 0x8005FA68u;
    // 8005FA68: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FA6C:
    ctx->pc = 0x8005FA6Cu;
    // 8005FA6C: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FA70:
    ctx->pc = 0x8005FA70u;
    // 8005FA70: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FA74:
    ctx->pc = 0x8005FA74u;
    // 8005FA74: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FA78:
    ctx->pc = 0x8005FA78u;
    // 8005FA78: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FA7C:
    ctx->pc = 0x8005FA7Cu;
    // 8005FA7C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FA80:
    ctx->pc = 0x8005FA80u;
    // 8005FA80: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FA84:
    ctx->pc = 0x8005FA84u;
    // 8005FA84: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FA88:
    ctx->pc = 0x8005FA88u;
    // 8005FA88: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FA8C:
    ctx->pc = 0x8005FA8Cu;
    // 8005FA8C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FA90:
    ctx->pc = 0x8005FA90u;
    // 8005FA90: bl      0x801698F0
    {
            ctx->lr = 0x8005FA94u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FA94:
    ctx->pc = 0x8005FA94u;
    ctx->downcount -= 25;
    // 8005FA94: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FA98:
    ctx->pc = 0x8005FA98u;
    // 8005FA98: lwz     r9, 176(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FA9C:
    ctx->pc = 0x8005FA9Cu;
    // 8005FA9C: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FAA0:
    ctx->pc = 0x8005FAA0u;
    // 8005FAA0: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005FAA4:
    ctx->pc = 0x8005FAA4u;
    // 8005FAA4: ori     r0, r0, 0x0007
    ctx->gpr[0] = ctx->gpr[0] | 0x0007u;

label_8005FAA8:
    ctx->pc = 0x8005FAA8u;
    // 8005FAA8: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005FAAC:
    ctx->pc = 0x8005FAACu;
    // 8005FAAC: addi    r3, r3, 6996
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(6996);

label_8005FAB0:
    ctx->pc = 0x8005FAB0u;
    // 8005FAB0: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FAB4:
    ctx->pc = 0x8005FAB4u;
    // 8005FAB4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FAB8:
    ctx->pc = 0x8005FAB8u;
    // 8005FAB8: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FABC:
    ctx->pc = 0x8005FABCu;
    // 8005FABC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FAC0:
    ctx->pc = 0x8005FAC0u;
    // 8005FAC0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FAC4:
    ctx->pc = 0x8005FAC4u;
    // 8005FAC4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FAC8:
    ctx->pc = 0x8005FAC8u;
    // 8005FAC8: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FACC:
    ctx->pc = 0x8005FACCu;
    // 8005FACC: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FAD0:
    ctx->pc = 0x8005FAD0u;
    // 8005FAD0: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FAD4:
    ctx->pc = 0x8005FAD4u;
    // 8005FAD4: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FAD8:
    ctx->pc = 0x8005FAD8u;
    // 8005FAD8: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FADC:
    ctx->pc = 0x8005FADCu;
    // 8005FADC: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FAE0:
    ctx->pc = 0x8005FAE0u;
    // 8005FAE0: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FAE4:
    ctx->pc = 0x8005FAE4u;
    // 8005FAE4: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FAE8:
    ctx->pc = 0x8005FAE8u;
    // 8005FAE8: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FAEC:
    ctx->pc = 0x8005FAECu;
    // 8005FAEC: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FAF0:
    ctx->pc = 0x8005FAF0u;
    // 8005FAF0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FAF4:
    ctx->pc = 0x8005FAF4u;
    // 8005FAF4: bl      0x801698F0
    {
            ctx->lr = 0x8005FAF8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FAF8:
    ctx->pc = 0x8005FAF8u;
    ctx->downcount -= 25;
    // 8005FAF8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FAFC:
    ctx->pc = 0x8005FAFCu;
    // 8005FAFC: lwz     r9, 200(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(200);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FB00:
    ctx->pc = 0x8005FB00u;
    // 8005FB00: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FB04:
    ctx->pc = 0x8005FB04u;
    // 8005FB04: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005FB08:
    ctx->pc = 0x8005FB08u;
    // 8005FB08: ori     r0, r0, 0x0008
    ctx->gpr[0] = ctx->gpr[0] | 0x0008u;

label_8005FB0C:
    ctx->pc = 0x8005FB0Cu;
    // 8005FB0C: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005FB10:
    ctx->pc = 0x8005FB10u;
    // 8005FB10: addi    r3, r3, 7076
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7076);

label_8005FB14:
    ctx->pc = 0x8005FB14u;
    // 8005FB14: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FB18:
    ctx->pc = 0x8005FB18u;
    // 8005FB18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FB1C:
    ctx->pc = 0x8005FB1Cu;
    // 8005FB1C: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FB20:
    ctx->pc = 0x8005FB20u;
    // 8005FB20: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FB24:
    ctx->pc = 0x8005FB24u;
    // 8005FB24: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FB28:
    ctx->pc = 0x8005FB28u;
    // 8005FB28: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FB2C:
    ctx->pc = 0x8005FB2Cu;
    // 8005FB2C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FB30:
    ctx->pc = 0x8005FB30u;
    // 8005FB30: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FB34:
    ctx->pc = 0x8005FB34u;
    // 8005FB34: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FB38:
    ctx->pc = 0x8005FB38u;
    // 8005FB38: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FB3C:
    ctx->pc = 0x8005FB3Cu;
    // 8005FB3C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FB40:
    ctx->pc = 0x8005FB40u;
    // 8005FB40: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FB44:
    ctx->pc = 0x8005FB44u;
    // 8005FB44: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FB48:
    ctx->pc = 0x8005FB48u;
    // 8005FB48: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FB4C:
    ctx->pc = 0x8005FB4Cu;
    // 8005FB4C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FB50:
    ctx->pc = 0x8005FB50u;
    // 8005FB50: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FB54:
    ctx->pc = 0x8005FB54u;
    // 8005FB54: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FB58:
    ctx->pc = 0x8005FB58u;
    // 8005FB58: bl      0x801698F0
    {
            ctx->lr = 0x8005FB5Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FB5C:
    ctx->pc = 0x8005FB5Cu;
    ctx->downcount -= 25;
    // 8005FB5C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FB60:
    ctx->pc = 0x8005FB60u;
    // 8005FB60: lwz     r9, 224(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(224);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FB64:
    ctx->pc = 0x8005FB64u;
    // 8005FB64: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FB68:
    ctx->pc = 0x8005FB68u;
    // 8005FB68: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005FB6C:
    ctx->pc = 0x8005FB6Cu;
    // 8005FB6C: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005FB70:
    ctx->pc = 0x8005FB70u;
    // 8005FB70: ori     r0, r0, 0x0009
    ctx->gpr[0] = ctx->gpr[0] | 0x0009u;

label_8005FB74:
    ctx->pc = 0x8005FB74u;
    // 8005FB74: addi    r3, r3, 7236
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7236);

label_8005FB78:
    ctx->pc = 0x8005FB78u;
    // 8005FB78: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FB7C:
    ctx->pc = 0x8005FB7Cu;
    // 8005FB7C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FB80:
    ctx->pc = 0x8005FB80u;
    // 8005FB80: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FB84:
    ctx->pc = 0x8005FB84u;
    // 8005FB84: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FB88:
    ctx->pc = 0x8005FB88u;
    // 8005FB88: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FB8C:
    ctx->pc = 0x8005FB8Cu;
    // 8005FB8C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FB90:
    ctx->pc = 0x8005FB90u;
    // 8005FB90: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FB94:
    ctx->pc = 0x8005FB94u;
    // 8005FB94: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FB98:
    ctx->pc = 0x8005FB98u;
    // 8005FB98: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FB9C:
    ctx->pc = 0x8005FB9Cu;
    // 8005FB9C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FBA0:
    ctx->pc = 0x8005FBA0u;
    // 8005FBA0: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FBA4:
    ctx->pc = 0x8005FBA4u;
    // 8005FBA4: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FBA8:
    ctx->pc = 0x8005FBA8u;
    // 8005FBA8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FBAC:
    ctx->pc = 0x8005FBACu;
    // 8005FBAC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FBB0:
    ctx->pc = 0x8005FBB0u;
    // 8005FBB0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FBB4:
    ctx->pc = 0x8005FBB4u;
    // 8005FBB4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FBB8:
    ctx->pc = 0x8005FBB8u;
    // 8005FBB8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FBBC:
    ctx->pc = 0x8005FBBCu;
    // 8005FBBC: bl      0x801698F0
    {
            ctx->lr = 0x8005FBC0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FBC0:
    ctx->pc = 0x8005FBC0u;
    ctx->downcount -= 23;
    // 8005FBC0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FBC4:
    ctx->pc = 0x8005FBC4u;
    // 8005FBC4: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FBC8:
    ctx->pc = 0x8005FBC8u;
    // 8005FBC8: lwz     r9, 248(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(248);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FBCC:
    ctx->pc = 0x8005FBCCu;
    // 8005FBCC: ori     r0, r0, 0x000A
    ctx->gpr[0] = ctx->gpr[0] | 0x000Au;

label_8005FBD0:
    ctx->pc = 0x8005FBD0u;
    // 8005FBD0: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8005FBD4:
    ctx->pc = 0x8005FBD4u;
    // 8005FBD4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FBD8:
    ctx->pc = 0x8005FBD8u;
    // 8005FBD8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FBDC:
    ctx->pc = 0x8005FBDCu;
    // 8005FBDC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8005FBE0:
    ctx->pc = 0x8005FBE0u;
    // 8005FBE0: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FBE4:
    ctx->pc = 0x8005FBE4u;
    // 8005FBE4: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FBE8:
    ctx->pc = 0x8005FBE8u;
    // 8005FBE8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FBEC:
    ctx->pc = 0x8005FBECu;
    // 8005FBEC: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FBF0:
    ctx->pc = 0x8005FBF0u;
    // 8005FBF0: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FBF4:
    ctx->pc = 0x8005FBF4u;
    // 8005FBF4: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FBF8:
    ctx->pc = 0x8005FBF8u;
    // 8005FBF8: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FBFC:
    ctx->pc = 0x8005FBFCu;
    // 8005FBFC: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FC00:
    ctx->pc = 0x8005FC00u;
    // 8005FC00: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FC04:
    ctx->pc = 0x8005FC04u;
    // 8005FC04: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FC08:
    ctx->pc = 0x8005FC08u;
    // 8005FC08: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FC0C:
    ctx->pc = 0x8005FC0Cu;
    // 8005FC0C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FC10:
    ctx->pc = 0x8005FC10u;
    // 8005FC10: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FC14:
    ctx->pc = 0x8005FC14u;
    // 8005FC14: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FC18:
    ctx->pc = 0x8005FC18u;
    // 8005FC18: bl      0x801698F0
    {
            ctx->lr = 0x8005FC1Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FC1C:
    ctx->pc = 0x8005FC1Cu;
    ctx->downcount -= 25;
    // 8005FC1C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FC20:
    ctx->pc = 0x8005FC20u;
    // 8005FC20: lwz     r9, 272(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(272);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FC24:
    ctx->pc = 0x8005FC24u;
    // 8005FC24: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FC28:
    ctx->pc = 0x8005FC28u;
    // 8005FC28: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8005FC2C:
    ctx->pc = 0x8005FC2Cu;
    // 8005FC2C: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005FC30:
    ctx->pc = 0x8005FC30u;
    // 8005FC30: ori     r0, r0, 0x000B
    ctx->gpr[0] = ctx->gpr[0] | 0x000Bu;

label_8005FC34:
    ctx->pc = 0x8005FC34u;
    // 8005FC34: addi    r3, r3, 7336
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(7336);

label_8005FC38:
    ctx->pc = 0x8005FC38u;
    // 8005FC38: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FC3C:
    ctx->pc = 0x8005FC3Cu;
    // 8005FC3C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FC40:
    ctx->pc = 0x8005FC40u;
    // 8005FC40: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FC44:
    ctx->pc = 0x8005FC44u;
    // 8005FC44: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FC48:
    ctx->pc = 0x8005FC48u;
    // 8005FC48: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FC4C:
    ctx->pc = 0x8005FC4Cu;
    // 8005FC4C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FC50:
    ctx->pc = 0x8005FC50u;
    // 8005FC50: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FC54:
    ctx->pc = 0x8005FC54u;
    // 8005FC54: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FC58:
    ctx->pc = 0x8005FC58u;
    // 8005FC58: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FC5C:
    ctx->pc = 0x8005FC5Cu;
    // 8005FC5C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FC60:
    ctx->pc = 0x8005FC60u;
    // 8005FC60: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FC64:
    ctx->pc = 0x8005FC64u;
    // 8005FC64: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FC68:
    ctx->pc = 0x8005FC68u;
    // 8005FC68: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FC6C:
    ctx->pc = 0x8005FC6Cu;
    // 8005FC6C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FC70:
    ctx->pc = 0x8005FC70u;
    // 8005FC70: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FC74:
    ctx->pc = 0x8005FC74u;
    // 8005FC74: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FC78:
    ctx->pc = 0x8005FC78u;
    // 8005FC78: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FC7C:
    ctx->pc = 0x8005FC7Cu;
    // 8005FC7C: bl      0x801698F0
    {
            ctx->lr = 0x8005FC80u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FC80:
    ctx->pc = 0x8005FC80u;
    ctx->downcount -= 25;
    // 8005FC80: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FC84:
    ctx->pc = 0x8005FC84u;
    // 8005FC84: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FC88:
    ctx->pc = 0x8005FC88u;
    // 8005FC88: lwz     r11, 296(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(296);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FC8C:
    ctx->pc = 0x8005FC8Cu;
    // 8005FC8C: ori     r0, r0, 0x000C
    ctx->gpr[0] = ctx->gpr[0] | 0x000Cu;

label_8005FC90:
    ctx->pc = 0x8005FC90u;
    // 8005FC90: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005FC94:
    ctx->pc = 0x8005FC94u;
    // 8005FC94: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FC98:
    ctx->pc = 0x8005FC98u;
    // 8005FC98: addi    r9, r9, 7896
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7896);

label_8005FC9C:
    ctx->pc = 0x8005FC9Cu;
    // 8005FC9C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8005FCA0:
    ctx->pc = 0x8005FCA0u;
    // 8005FCA0: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FCA4:
    ctx->pc = 0x8005FCA4u;
    // 8005FCA4: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FCA8:
    ctx->pc = 0x8005FCA8u;
    // 8005FCA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FCAC:
    ctx->pc = 0x8005FCACu;
    // 8005FCAC: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FCB0:
    ctx->pc = 0x8005FCB0u;
    // 8005FCB0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FCB4:
    ctx->pc = 0x8005FCB4u;
    // 8005FCB4: stw     r11, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FCB8:
    ctx->pc = 0x8005FCB8u;
    // 8005FCB8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FCBC:
    ctx->pc = 0x8005FCBCu;
    // 8005FCBC: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FCC0:
    ctx->pc = 0x8005FCC0u;
    // 8005FCC0: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FCC4:
    ctx->pc = 0x8005FCC4u;
    // 8005FCC4: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FCC8:
    ctx->pc = 0x8005FCC8u;
    // 8005FCC8: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FCCC:
    ctx->pc = 0x8005FCCCu;
    // 8005FCCC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FCD0:
    ctx->pc = 0x8005FCD0u;
    // 8005FCD0: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FCD4:
    ctx->pc = 0x8005FCD4u;
    // 8005FCD4: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FCD8:
    ctx->pc = 0x8005FCD8u;
    // 8005FCD8: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FCDC:
    ctx->pc = 0x8005FCDCu;
    // 8005FCDC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FCE0:
    ctx->pc = 0x8005FCE0u;
    // 8005FCE0: bl      0x801698F0
    {
            ctx->lr = 0x8005FCE4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FCE4:
    ctx->pc = 0x8005FCE4u;
    ctx->downcount -= 25;
    // 8005FCE4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FCE8:
    ctx->pc = 0x8005FCE8u;
    // 8005FCE8: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FCEC:
    ctx->pc = 0x8005FCECu;
    // 8005FCEC: lwz     r11, 320(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(320);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FCF0:
    ctx->pc = 0x8005FCF0u;
    // 8005FCF0: ori     r0, r0, 0x000D
    ctx->gpr[0] = ctx->gpr[0] | 0x000Du;

label_8005FCF4:
    ctx->pc = 0x8005FCF4u;
    // 8005FCF4: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005FCF8:
    ctx->pc = 0x8005FCF8u;
    // 8005FCF8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FCFC:
    ctx->pc = 0x8005FCFCu;
    // 8005FCFC: addi    r9, r9, 7956
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7956);

label_8005FD00:
    ctx->pc = 0x8005FD00u;
    // 8005FD00: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8005FD04:
    ctx->pc = 0x8005FD04u;
    // 8005FD04: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FD08:
    ctx->pc = 0x8005FD08u;
    // 8005FD08: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FD0C:
    ctx->pc = 0x8005FD0Cu;
    // 8005FD0C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FD10:
    ctx->pc = 0x8005FD10u;
    // 8005FD10: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FD14:
    ctx->pc = 0x8005FD14u;
    // 8005FD14: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FD18:
    ctx->pc = 0x8005FD18u;
    // 8005FD18: stw     r11, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FD1C:
    ctx->pc = 0x8005FD1Cu;
    // 8005FD1C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FD20:
    ctx->pc = 0x8005FD20u;
    // 8005FD20: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FD24:
    ctx->pc = 0x8005FD24u;
    // 8005FD24: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FD28:
    ctx->pc = 0x8005FD28u;
    // 8005FD28: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FD2C:
    ctx->pc = 0x8005FD2Cu;
    // 8005FD2C: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FD30:
    ctx->pc = 0x8005FD30u;
    // 8005FD30: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FD34:
    ctx->pc = 0x8005FD34u;
    // 8005FD34: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FD38:
    ctx->pc = 0x8005FD38u;
    // 8005FD38: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FD3C:
    ctx->pc = 0x8005FD3Cu;
    // 8005FD3C: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FD40:
    ctx->pc = 0x8005FD40u;
    // 8005FD40: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FD44:
    ctx->pc = 0x8005FD44u;
    // 8005FD44: bl      0x801698F0
    {
            ctx->lr = 0x8005FD48u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FD48:
    ctx->pc = 0x8005FD48u;
    ctx->downcount -= 22;
    // 8005FD48: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FD4C:
    ctx->pc = 0x8005FD4Cu;
    // 8005FD4C: lwz     r9, 344(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(344);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FD50:
    ctx->pc = 0x8005FD50u;
    // 8005FD50: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FD54:
    ctx->pc = 0x8005FD54u;
    // 8005FD54: ori     r0, r0, 0x000E
    ctx->gpr[0] = ctx->gpr[0] | 0x000Eu;

label_8005FD58:
    ctx->pc = 0x8005FD58u;
    // 8005FD58: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8005FD5C:
    ctx->pc = 0x8005FD5Cu;
    // 8005FD5C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FD60:
    ctx->pc = 0x8005FD60u;
    // 8005FD60: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FD64:
    ctx->pc = 0x8005FD64u;
    // 8005FD64: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FD68:
    ctx->pc = 0x8005FD68u;
    // 8005FD68: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FD6C:
    ctx->pc = 0x8005FD6Cu;
    // 8005FD6C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FD70:
    ctx->pc = 0x8005FD70u;
    // 8005FD70: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FD74:
    ctx->pc = 0x8005FD74u;
    // 8005FD74: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FD78:
    ctx->pc = 0x8005FD78u;
    // 8005FD78: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FD7C:
    ctx->pc = 0x8005FD7Cu;
    // 8005FD7C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FD80:
    ctx->pc = 0x8005FD80u;
    // 8005FD80: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FD84:
    ctx->pc = 0x8005FD84u;
    // 8005FD84: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FD88:
    ctx->pc = 0x8005FD88u;
    // 8005FD88: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FD8C:
    ctx->pc = 0x8005FD8Cu;
    // 8005FD8C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FD90:
    ctx->pc = 0x8005FD90u;
    // 8005FD90: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FD94:
    ctx->pc = 0x8005FD94u;
    // 8005FD94: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FD98:
    ctx->pc = 0x8005FD98u;
    // 8005FD98: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FD9C:
    ctx->pc = 0x8005FD9Cu;
    // 8005FD9C: bl      0x801698F0
    {
            ctx->lr = 0x8005FDA0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FDA0:
    ctx->pc = 0x8005FDA0u;
    ctx->downcount -= 37;
    // 8005FDA0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FDA4:
    ctx->pc = 0x8005FDA4u;
    // 8005FDA4: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FDA8:
    ctx->pc = 0x8005FDA8u;
    // 8005FDA8: lwz     r6, 368(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(368);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005FDAC:
    ctx->pc = 0x8005FDACu;
    // 8005FDAC: ori     r0, r0, 0x000F
    ctx->gpr[0] = ctx->gpr[0] | 0x000Fu;

label_8005FDB0:
    ctx->pc = 0x8005FDB0u;
    // 8005FDB0: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8005FDB4:
    ctx->pc = 0x8005FDB4u;
    // 8005FDB4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FDB8:
    ctx->pc = 0x8005FDB8u;
    // 8005FDB8: addi    r9, r9, 8056
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8056);

label_8005FDBC:
    ctx->pc = 0x8005FDBCu;
    // 8005FDBC: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FDC0:
    ctx->pc = 0x8005FDC0u;
    // 8005FDC0: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8005FDC4:
    ctx->pc = 0x8005FDC4u;
    // 8005FDC4: stw     r6, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FDC8:
    ctx->pc = 0x8005FDC8u;
    // 8005FDC8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005FDCC:
    ctx->pc = 0x8005FDCCu;
    // 8005FDCC: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FDD0:
    ctx->pc = 0x8005FDD0u;
    // 8005FDD0: addi    r10, r9, 30916
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(30916);

label_8005FDD4:
    ctx->pc = 0x8005FDD4u;
    // 8005FDD4: lwz     r7, 30916(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30916);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005FDD8:
    ctx->pc = 0x8005FDD8u;
    // 8005FDD8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FDDC:
    ctx->pc = 0x8005FDDCu;
    // 8005FDDC: lwz     r8, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005FDE0:
    ctx->pc = 0x8005FDE0u;
    // 8005FDE0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FDE4:
    ctx->pc = 0x8005FDE4u;
    // 8005FDE4: lwz     r0, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FDE8:
    ctx->pc = 0x8005FDE8u;
    // 8005FDE8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FDEC:
    ctx->pc = 0x8005FDECu;
    // 8005FDEC: lwz     r9, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FDF0:
    ctx->pc = 0x8005FDF0u;
    // 8005FDF0: lwz     r11, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FDF4:
    ctx->pc = 0x8005FDF4u;
    // 8005FDF4: stw     r6, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FDF8:
    ctx->pc = 0x8005FDF8u;
    // 8005FDF8: stw     r8, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005FDFC:
    ctx->pc = 0x8005FDFCu;
    // 8005FDFC: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FE00:
    ctx->pc = 0x8005FE00u;
    // 8005FE00: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FE04:
    ctx->pc = 0x8005FE04u;
    // 8005FE04: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FE08:
    ctx->pc = 0x8005FE08u;
    // 8005FE08: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_8005FE0C:
    ctx->pc = 0x8005FE0Cu;
    // 8005FE0C: lwz     r8, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8005FE10:
    ctx->pc = 0x8005FE10u;
    // 8005FE10: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FE14:
    ctx->pc = 0x8005FE14u;
    // 8005FE14: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FE18:
    ctx->pc = 0x8005FE18u;
    // 8005FE18: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FE1C:
    ctx->pc = 0x8005FE1Cu;
    // 8005FE1C: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8005FE20:
    ctx->pc = 0x8005FE20u;
    // 8005FE20: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FE24:
    ctx->pc = 0x8005FE24u;
    // 8005FE24: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FE28:
    ctx->pc = 0x8005FE28u;
    // 8005FE28: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FE2C:
    ctx->pc = 0x8005FE2Cu;
    // 8005FE2C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FE30:
    ctx->pc = 0x8005FE30u;
    // 8005FE30: bl      0x801698F0
    {
            ctx->lr = 0x8005FE34u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FE34:
    ctx->pc = 0x8005FE34u;
    ctx->downcount -= 22;
    // 8005FE34: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FE38:
    ctx->pc = 0x8005FE38u;
    // 8005FE38: lwz     r9, 656(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(656);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FE3C:
    ctx->pc = 0x8005FE3Cu;
    // 8005FE3C: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FE40:
    ctx->pc = 0x8005FE40u;
    // 8005FE40: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_8005FE44:
    ctx->pc = 0x8005FE44u;
    // 8005FE44: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8005FE48:
    ctx->pc = 0x8005FE48u;
    // 8005FE48: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FE4C:
    ctx->pc = 0x8005FE4Cu;
    // 8005FE4C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FE50:
    ctx->pc = 0x8005FE50u;
    // 8005FE50: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FE54:
    ctx->pc = 0x8005FE54u;
    // 8005FE54: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FE58:
    ctx->pc = 0x8005FE58u;
    // 8005FE58: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FE5C:
    ctx->pc = 0x8005FE5Cu;
    // 8005FE5C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FE60:
    ctx->pc = 0x8005FE60u;
    // 8005FE60: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FE64:
    ctx->pc = 0x8005FE64u;
    // 8005FE64: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FE68:
    ctx->pc = 0x8005FE68u;
    // 8005FE68: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FE6C:
    ctx->pc = 0x8005FE6Cu;
    // 8005FE6C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FE70:
    ctx->pc = 0x8005FE70u;
    // 8005FE70: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FE74:
    ctx->pc = 0x8005FE74u;
    // 8005FE74: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FE78:
    ctx->pc = 0x8005FE78u;
    // 8005FE78: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FE7C:
    ctx->pc = 0x8005FE7Cu;
    // 8005FE7C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FE80:
    ctx->pc = 0x8005FE80u;
    // 8005FE80: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FE84:
    ctx->pc = 0x8005FE84u;
    // 8005FE84: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FE88:
    ctx->pc = 0x8005FE88u;
    // 8005FE88: bl      0x801698F0
    {
            ctx->lr = 0x8005FE8Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FE8C:
    ctx->pc = 0x8005FE8Cu;
    ctx->downcount -= 22;
    // 8005FE8C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FE90:
    ctx->pc = 0x8005FE90u;
    // 8005FE90: lwz     r9, 704(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(704);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FE94:
    ctx->pc = 0x8005FE94u;
    // 8005FE94: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FE98:
    ctx->pc = 0x8005FE98u;
    // 8005FE98: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_8005FE9C:
    ctx->pc = 0x8005FE9Cu;
    // 8005FE9C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8005FEA0:
    ctx->pc = 0x8005FEA0u;
    // 8005FEA0: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FEA4:
    ctx->pc = 0x8005FEA4u;
    // 8005FEA4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FEA8:
    ctx->pc = 0x8005FEA8u;
    // 8005FEA8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FEAC:
    ctx->pc = 0x8005FEACu;
    // 8005FEAC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FEB0:
    ctx->pc = 0x8005FEB0u;
    // 8005FEB0: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FEB4:
    ctx->pc = 0x8005FEB4u;
    // 8005FEB4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FEB8:
    ctx->pc = 0x8005FEB8u;
    // 8005FEB8: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FEBC:
    ctx->pc = 0x8005FEBCu;
    // 8005FEBC: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FEC0:
    ctx->pc = 0x8005FEC0u;
    // 8005FEC0: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FEC4:
    ctx->pc = 0x8005FEC4u;
    // 8005FEC4: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FEC8:
    ctx->pc = 0x8005FEC8u;
    // 8005FEC8: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FECC:
    ctx->pc = 0x8005FECCu;
    // 8005FECC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FED0:
    ctx->pc = 0x8005FED0u;
    // 8005FED0: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FED4:
    ctx->pc = 0x8005FED4u;
    // 8005FED4: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FED8:
    ctx->pc = 0x8005FED8u;
    // 8005FED8: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FEDC:
    ctx->pc = 0x8005FEDCu;
    // 8005FEDC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FEE0:
    ctx->pc = 0x8005FEE0u;
    // 8005FEE0: bl      0x801698F0
    {
            ctx->lr = 0x8005FEE4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FEE4:
    ctx->pc = 0x8005FEE4u;
    ctx->downcount -= 22;
    // 8005FEE4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FEE8:
    ctx->pc = 0x8005FEE8u;
    // 8005FEE8: lwz     r9, 728(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(728);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FEEC:
    ctx->pc = 0x8005FEECu;
    // 8005FEEC: lis     r0, 1
    ctx->gpr[0] = ((u32)(s32)(1) << 16);

label_8005FEF0:
    ctx->pc = 0x8005FEF0u;
    // 8005FEF0: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_8005FEF4:
    ctx->pc = 0x8005FEF4u;
    // 8005FEF4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8005FEF8:
    ctx->pc = 0x8005FEF8u;
    // 8005FEF8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FEFC:
    ctx->pc = 0x8005FEFCu;
    // 8005FEFC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FF00:
    ctx->pc = 0x8005FF00u;
    // 8005FF00: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FF04:
    ctx->pc = 0x8005FF04u;
    // 8005FF04: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FF08:
    ctx->pc = 0x8005FF08u;
    // 8005FF08: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FF0C:
    ctx->pc = 0x8005FF0Cu;
    // 8005FF0C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FF10:
    ctx->pc = 0x8005FF10u;
    // 8005FF10: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FF14:
    ctx->pc = 0x8005FF14u;
    // 8005FF14: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FF18:
    ctx->pc = 0x8005FF18u;
    // 8005FF18: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FF1C:
    ctx->pc = 0x8005FF1Cu;
    // 8005FF1C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FF20:
    ctx->pc = 0x8005FF20u;
    // 8005FF20: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FF24:
    ctx->pc = 0x8005FF24u;
    // 8005FF24: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FF28:
    ctx->pc = 0x8005FF28u;
    // 8005FF28: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FF2C:
    ctx->pc = 0x8005FF2Cu;
    // 8005FF2C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FF30:
    ctx->pc = 0x8005FF30u;
    // 8005FF30: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FF34:
    ctx->pc = 0x8005FF34u;
    // 8005FF34: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FF38:
    ctx->pc = 0x8005FF38u;
    // 8005FF38: bl      0x801698F0
    {
            ctx->lr = 0x8005FF3Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FF3C:
    ctx->pc = 0x8005FF3Cu;
    ctx->downcount -= 21;
    // 8005FF3C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FF40:
    ctx->pc = 0x8005FF40u;
    // 8005FF40: lwz     r0, 32(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(32);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FF44:
    ctx->pc = 0x8005FF44u;
    // 8005FF44: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_8005FF48:
    ctx->pc = 0x8005FF48u;
    // 8005FF48: lwz     r9, 152(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(152);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FF4C:
    ctx->pc = 0x8005FF4Cu;
    // 8005FF4C: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FF50:
    ctx->pc = 0x8005FF50u;
    // 8005FF50: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FF54:
    ctx->pc = 0x8005FF54u;
    // 8005FF54: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FF58:
    ctx->pc = 0x8005FF58u;
    // 8005FF58: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FF5C:
    ctx->pc = 0x8005FF5Cu;
    // 8005FF5C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FF60:
    ctx->pc = 0x8005FF60u;
    // 8005FF60: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FF64:
    ctx->pc = 0x8005FF64u;
    // 8005FF64: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FF68:
    ctx->pc = 0x8005FF68u;
    // 8005FF68: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FF6C:
    ctx->pc = 0x8005FF6Cu;
    // 8005FF6C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FF70:
    ctx->pc = 0x8005FF70u;
    // 8005FF70: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FF74:
    ctx->pc = 0x8005FF74u;
    // 8005FF74: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FF78:
    ctx->pc = 0x8005FF78u;
    // 8005FF78: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FF7C:
    ctx->pc = 0x8005FF7Cu;
    // 8005FF7C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8005FF80:
    ctx->pc = 0x8005FF80u;
    // 8005FF80: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FF84:
    ctx->pc = 0x8005FF84u;
    // 8005FF84: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FF88:
    ctx->pc = 0x8005FF88u;
    // 8005FF88: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FF8C:
    ctx->pc = 0x8005FF8Cu;
    // 8005FF8C: bl      0x801698F0
    {
            ctx->lr = 0x8005FF90u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FF90:
    ctx->pc = 0x8005FF90u;
    ctx->downcount -= 19;
    // 8005FF90: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8005FF94:
    ctx->pc = 0x8005FF94u;
    // 8005FF94: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_8005FF98:
    ctx->pc = 0x8005FF98u;
    // 8005FF98: lwz     r7, 30936(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30936);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8005FF9C:
    ctx->pc = 0x8005FF9Cu;
    // 8005FF9C: addi    r30, r8, 12800
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(12800);

label_8005FFA0:
    ctx->pc = 0x8005FFA0u;
    // 8005FFA0: addi    r9, r9, 30936
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(30936);

label_8005FFA4:
    ctx->pc = 0x8005FFA4u;
    // 8005FFA4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FFA8:
    ctx->pc = 0x8005FFA8u;
    // 8005FFA8: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8005FFAC:
    ctx->pc = 0x8005FFACu;
    // 8005FFAC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8005FFB0:
    ctx->pc = 0x8005FFB0u;
    // 8005FFB0: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8005FFB4:
    ctx->pc = 0x8005FFB4u;
    // 8005FFB4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8005FFB8:
    ctx->pc = 0x8005FFB8u;
    // 8005FFB8: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8005FFBC:
    ctx->pc = 0x8005FFBCu;
    // 8005FFBC: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8005FFC0:
    ctx->pc = 0x8005FFC0u;
    // 8005FFC0: stw     r7, 12800(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12800);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8005FFC4:
    ctx->pc = 0x8005FFC4u;
    // 8005FFC4: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8005FFC8:
    ctx->pc = 0x8005FFC8u;
    // 8005FFC8: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8005FFCC:
    ctx->pc = 0x8005FFCCu;
    // 8005FFCC: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8005FFD0:
    ctx->pc = 0x8005FFD0u;
    // 8005FFD0: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FFD4:
    ctx->pc = 0x8005FFD4u;
    // 8005FFD4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8005FFD8:
    ctx->pc = 0x8005FFD8u;
    // 8005FFD8: bl      0x801698F0
    {
            ctx->lr = 0x8005FFDCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8005FFDC:
    ctx->pc = 0x8005FFDCu;
    ctx->downcount -= 22;
    // 8005FFDC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8005FFE0:
    ctx->pc = 0x8005FFE0u;
    // 8005FFE0: lwz     r9, 728(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(728);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8005FFE4:
    ctx->pc = 0x8005FFE4u;
    // 8005FFE4: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_8005FFE8:
    ctx->pc = 0x8005FFE8u;
    // 8005FFE8: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_8005FFEC:
    ctx->pc = 0x8005FFECu;
    // 8005FFEC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8005FFF0:
    ctx->pc = 0x8005FFF0u;
    // 8005FFF0: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8005FFF4:
    ctx->pc = 0x8005FFF4u;
    // 8005FFF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8005FFF8:
    ctx->pc = 0x8005FFF8u;
    // 8005FFF8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8005FFFC:
    ctx->pc = 0x8005FFFCu;
    // 8005FFFC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060000:
    ctx->pc = 0x80060000u;
    // 80060000: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060004:
    ctx->pc = 0x80060004u;
    // 80060004: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80060008:
    ctx->pc = 0x80060008u;
    // 80060008: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006000C:
    ctx->pc = 0x8006000Cu;
    // 8006000C: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060010:
    ctx->pc = 0x80060010u;
    // 80060010: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060014:
    ctx->pc = 0x80060014u;
    // 80060014: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060018:
    ctx->pc = 0x80060018u;
    // 80060018: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006001C:
    ctx->pc = 0x8006001Cu;
    // 8006001C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060020:
    ctx->pc = 0x80060020u;
    // 80060020: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060024:
    ctx->pc = 0x80060024u;
    // 80060024: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060028:
    ctx->pc = 0x80060028u;
    // 80060028: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006002C:
    ctx->pc = 0x8006002Cu;
    // 8006002C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060030:
    ctx->pc = 0x80060030u;
    // 80060030: bl      0x801698F0
    {
            ctx->lr = 0x80060034u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060034:
    ctx->pc = 0x80060034u;
    ctx->downcount -= 22;
    // 80060034: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060038:
    ctx->pc = 0x80060038u;
    // 80060038: lwz     r9, 704(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(704);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006003C:
    ctx->pc = 0x8006003Cu;
    // 8006003C: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_80060040:
    ctx->pc = 0x80060040u;
    // 80060040: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_80060044:
    ctx->pc = 0x80060044u;
    // 80060044: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060048:
    ctx->pc = 0x80060048u;
    // 80060048: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006004C:
    ctx->pc = 0x8006004Cu;
    // 8006004C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060050:
    ctx->pc = 0x80060050u;
    // 80060050: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060054:
    ctx->pc = 0x80060054u;
    // 80060054: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060058:
    ctx->pc = 0x80060058u;
    // 80060058: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006005C:
    ctx->pc = 0x8006005Cu;
    // 8006005C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80060060:
    ctx->pc = 0x80060060u;
    // 80060060: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060064:
    ctx->pc = 0x80060064u;
    // 80060064: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060068:
    ctx->pc = 0x80060068u;
    // 80060068: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006006C:
    ctx->pc = 0x8006006Cu;
    // 8006006C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060070:
    ctx->pc = 0x80060070u;
    // 80060070: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060074:
    ctx->pc = 0x80060074u;
    // 80060074: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060078:
    ctx->pc = 0x80060078u;
    // 80060078: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006007C:
    ctx->pc = 0x8006007Cu;
    // 8006007C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060080:
    ctx->pc = 0x80060080u;
    // 80060080: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060084:
    ctx->pc = 0x80060084u;
    // 80060084: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060088:
    ctx->pc = 0x80060088u;
    // 80060088: bl      0x801698F0
    {
            ctx->lr = 0x8006008Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006008C:
    ctx->pc = 0x8006008Cu;
    ctx->downcount -= 22;
    // 8006008C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060090:
    ctx->pc = 0x80060090u;
    // 80060090: lwz     r9, 656(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(656);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060094:
    ctx->pc = 0x80060094u;
    // 80060094: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_80060098:
    ctx->pc = 0x80060098u;
    // 80060098: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_8006009C:
    ctx->pc = 0x8006009Cu;
    // 8006009C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800600A0:
    ctx->pc = 0x800600A0u;
    // 800600A0: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800600A4:
    ctx->pc = 0x800600A4u;
    // 800600A4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800600A8:
    ctx->pc = 0x800600A8u;
    // 800600A8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800600AC:
    ctx->pc = 0x800600ACu;
    // 800600AC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800600B0:
    ctx->pc = 0x800600B0u;
    // 800600B0: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800600B4:
    ctx->pc = 0x800600B4u;
    // 800600B4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800600B8:
    ctx->pc = 0x800600B8u;
    // 800600B8: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800600BC:
    ctx->pc = 0x800600BCu;
    // 800600BC: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800600C0:
    ctx->pc = 0x800600C0u;
    // 800600C0: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800600C4:
    ctx->pc = 0x800600C4u;
    // 800600C4: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800600C8:
    ctx->pc = 0x800600C8u;
    // 800600C8: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800600CC:
    ctx->pc = 0x800600CCu;
    // 800600CC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800600D0:
    ctx->pc = 0x800600D0u;
    // 800600D0: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800600D4:
    ctx->pc = 0x800600D4u;
    // 800600D4: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800600D8:
    ctx->pc = 0x800600D8u;
    // 800600D8: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800600DC:
    ctx->pc = 0x800600DCu;
    // 800600DC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800600E0:
    ctx->pc = 0x800600E0u;
    // 800600E0: bl      0x801698F0
    {
            ctx->lr = 0x800600E4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800600E4:
    ctx->pc = 0x800600E4u;
    ctx->downcount -= 34;
    // 800600E4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800600E8:
    ctx->pc = 0x800600E8u;
    // 800600E8: lwz     r7, 824(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(824);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800600EC:
    ctx->pc = 0x800600ECu;
    // 800600EC: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_800600F0:
    ctx->pc = 0x800600F0u;
    // 800600F0: ori     r0, r0, 0x0022
    ctx->gpr[0] = ctx->gpr[0] | 0x0022u;

label_800600F4:
    ctx->pc = 0x800600F4u;
    // 800600F4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800600F8:
    ctx->pc = 0x800600F8u;
    // 800600F8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800600FC:
    ctx->pc = 0x800600FCu;
    // 800600FC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80060100:
    ctx->pc = 0x80060100u;
    // 80060100: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80060104:
    ctx->pc = 0x80060104u;
    // 80060104: addi    r10, r9, 30956
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(30956);

label_80060108:
    ctx->pc = 0x80060108u;
    // 80060108: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006010C:
    ctx->pc = 0x8006010Cu;
    // 8006010C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060110:
    ctx->pc = 0x80060110u;
    // 80060110: lwz     r6, 30956(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30956);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80060114:
    ctx->pc = 0x80060114u;
    // 80060114: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060118:
    ctx->pc = 0x80060118u;
    // 80060118: lwz     r8, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006011C:
    ctx->pc = 0x8006011Cu;
    // 8006011C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80060120:
    ctx->pc = 0x80060120u;
    // 80060120: lwz     r11, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060124:
    ctx->pc = 0x80060124u;
    // 80060124: lwz     r0, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060128:
    ctx->pc = 0x80060128u;
    // 80060128: lwz     r9, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006012C:
    ctx->pc = 0x8006012Cu;
    // 8006012C: stw     r8, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060130:
    ctx->pc = 0x80060130u;
    // 80060130: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060134:
    ctx->pc = 0x80060134u;
    // 80060134: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060138:
    ctx->pc = 0x80060138u;
    // 80060138: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006013C:
    ctx->pc = 0x8006013Cu;
    // 8006013C: stw     r7, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80060140:
    ctx->pc = 0x80060140u;
    // 80060140: lwz     r8, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060144:
    ctx->pc = 0x80060144u;
    // 80060144: stwu     r6, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[30] = ea;
    }

label_80060148:
    ctx->pc = 0x80060148u;
    // 80060148: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006014C:
    ctx->pc = 0x8006014Cu;
    // 8006014C: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060150:
    ctx->pc = 0x80060150u;
    // 80060150: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060154:
    ctx->pc = 0x80060154u;
    // 80060154: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060158:
    ctx->pc = 0x80060158u;
    // 80060158: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006015C:
    ctx->pc = 0x8006015Cu;
    // 8006015C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060160:
    ctx->pc = 0x80060160u;
    // 80060160: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060164:
    ctx->pc = 0x80060164u;
    // 80060164: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060168:
    ctx->pc = 0x80060168u;
    // 80060168: bl      0x801698F0
    {
            ctx->lr = 0x8006016Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006016C:
    ctx->pc = 0x8006016Cu;
    ctx->downcount -= 28;
    // 8006016C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060170:
    ctx->pc = 0x80060170u;
    // 80060170: lwz     r9, 488(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(488);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060174:
    ctx->pc = 0x80060174u;
    // 80060174: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_80060178:
    ctx->pc = 0x80060178u;
    // 80060178: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_8006017C:
    ctx->pc = 0x8006017Cu;
    // 8006017C: ori     r0, r0, 0x0014
    ctx->gpr[0] = ctx->gpr[0] | 0x0014u;

label_80060180:
    ctx->pc = 0x80060180u;
    // 80060180: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80060184:
    ctx->pc = 0x80060184u;
    // 80060184: addi    r3, r3, 8176
    ctx->gpr[3] = ctx->gpr[3] + (u32)(s32)(8176);

label_80060188:
    ctx->pc = 0x80060188u;
    // 80060188: stw     r3, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006018C:
    ctx->pc = 0x8006018Cu;
    // 8006018C: lis     r7, -32738
    ctx->gpr[7] = ((u32)(s32)(-32738) << 16);

label_80060190:
    ctx->pc = 0x80060190u;
    // 80060190: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060194:
    ctx->pc = 0x80060194u;
    // 80060194: addi    r7, r7, 31888
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(31888);

label_80060198:
    ctx->pc = 0x80060198u;
    // 80060198: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006019C:
    ctx->pc = 0x8006019Cu;
    // 8006019C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800601A0:
    ctx->pc = 0x800601A0u;
    // 800601A0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800601A4:
    ctx->pc = 0x800601A4u;
    // 800601A4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800601A8:
    ctx->pc = 0x800601A8u;
    // 800601A8: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800601AC:
    ctx->pc = 0x800601ACu;
    // 800601AC: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800601B0:
    ctx->pc = 0x800601B0u;
    // 800601B0: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800601B4:
    ctx->pc = 0x800601B4u;
    // 800601B4: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800601B8:
    ctx->pc = 0x800601B8u;
    // 800601B8: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800601BC:
    ctx->pc = 0x800601BCu;
    // 800601BC: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800601C0:
    ctx->pc = 0x800601C0u;
    // 800601C0: lwz     r18, 0(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(0);
        ctx->gpr[18] = mem_read32(ctx, ea);
    }

label_800601C4:
    ctx->pc = 0x800601C4u;
    // 800601C4: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800601C8:
    ctx->pc = 0x800601C8u;
    // 800601C8: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800601CC:
    ctx->pc = 0x800601CCu;
    // 800601CC: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800601D0:
    ctx->pc = 0x800601D0u;
    // 800601D0: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800601D4:
    ctx->pc = 0x800601D4u;
    // 800601D4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800601D8:
    ctx->pc = 0x800601D8u;
    // 800601D8: bl      0x801698F0
    {
            ctx->lr = 0x800601DCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800601DC:
    ctx->pc = 0x800601DCu;
    ctx->downcount -= 25;
    // 800601DC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800601E0:
    ctx->pc = 0x800601E0u;
    // 800601E0: lwz     r9, 584(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(584);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800601E4:
    ctx->pc = 0x800601E4u;
    // 800601E4: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_800601E8:
    ctx->pc = 0x800601E8u;
    // 800601E8: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_800601EC:
    ctx->pc = 0x800601ECu;
    // 800601EC: addi    r31, r3, 8696
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(8696);

label_800601F0:
    ctx->pc = 0x800601F0u;
    // 800601F0: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_800601F4:
    ctx->pc = 0x800601F4u;
    // 800601F4: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_800601F8:
    ctx->pc = 0x800601F8u;
    // 800601F8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800601FC:
    ctx->pc = 0x800601FCu;
    // 800601FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060200:
    ctx->pc = 0x80060200u;
    // 80060200: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060204:
    ctx->pc = 0x80060204u;
    // 80060204: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060208:
    ctx->pc = 0x80060208u;
    // 80060208: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006020C:
    ctx->pc = 0x8006020Cu;
    // 8006020C: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80060210:
    ctx->pc = 0x80060210u;
    // 80060210: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060214:
    ctx->pc = 0x80060214u;
    // 80060214: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060218:
    ctx->pc = 0x80060218u;
    // 80060218: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006021C:
    ctx->pc = 0x8006021Cu;
    // 8006021C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060220:
    ctx->pc = 0x80060220u;
    // 80060220: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060224:
    ctx->pc = 0x80060224u;
    // 80060224: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060228:
    ctx->pc = 0x80060228u;
    // 80060228: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006022C:
    ctx->pc = 0x8006022Cu;
    // 8006022C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060230:
    ctx->pc = 0x80060230u;
    // 80060230: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060234:
    ctx->pc = 0x80060234u;
    // 80060234: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060238:
    ctx->pc = 0x80060238u;
    // 80060238: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006023C:
    ctx->pc = 0x8006023Cu;
    // 8006023C: bl      0x801698F0
    {
            ctx->lr = 0x80060240u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060240:
    ctx->pc = 0x80060240u;
    ctx->downcount -= 25;
    // 80060240: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060244:
    ctx->pc = 0x80060244u;
    // 80060244: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_80060248:
    ctx->pc = 0x80060248u;
    // 80060248: lwz     r11, 632(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(632);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006024C:
    ctx->pc = 0x8006024Cu;
    // 8006024C: ori     r0, r0, 0x001A
    ctx->gpr[0] = ctx->gpr[0] | 0x001Au;

label_80060250:
    ctx->pc = 0x80060250u;
    // 80060250: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80060254:
    ctx->pc = 0x80060254u;
    // 80060254: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060258:
    ctx->pc = 0x80060258u;
    // 80060258: addi    r9, r9, 9276
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9276);

label_8006025C:
    ctx->pc = 0x8006025Cu;
    // 8006025C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060260:
    ctx->pc = 0x80060260u;
    // 80060260: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060264:
    ctx->pc = 0x80060264u;
    // 80060264: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060268:
    ctx->pc = 0x80060268u;
    // 80060268: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006026C:
    ctx->pc = 0x8006026Cu;
    // 8006026C: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060270:
    ctx->pc = 0x80060270u;
    // 80060270: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060274:
    ctx->pc = 0x80060274u;
    // 80060274: stw     r11, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060278:
    ctx->pc = 0x80060278u;
    // 80060278: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8006027C:
    ctx->pc = 0x8006027Cu;
    // 8006027C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060280:
    ctx->pc = 0x80060280u;
    // 80060280: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060284:
    ctx->pc = 0x80060284u;
    // 80060284: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060288:
    ctx->pc = 0x80060288u;
    // 80060288: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006028C:
    ctx->pc = 0x8006028Cu;
    // 8006028C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060290:
    ctx->pc = 0x80060290u;
    // 80060290: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060294:
    ctx->pc = 0x80060294u;
    // 80060294: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060298:
    ctx->pc = 0x80060298u;
    // 80060298: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006029C:
    ctx->pc = 0x8006029Cu;
    // 8006029C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800602A0:
    ctx->pc = 0x800602A0u;
    // 800602A0: bl      0x801698F0
    {
            ctx->lr = 0x800602A4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800602A4:
    ctx->pc = 0x800602A4u;
    ctx->downcount -= 22;
    // 800602A4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800602A8:
    ctx->pc = 0x800602A8u;
    // 800602A8: lwz     r9, 152(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(152);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800602AC:
    ctx->pc = 0x800602ACu;
    // 800602AC: lis     r0, 2
    ctx->gpr[0] = ((u32)(s32)(2) << 16);

label_800602B0:
    ctx->pc = 0x800602B0u;
    // 800602B0: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_800602B4:
    ctx->pc = 0x800602B4u;
    // 800602B4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800602B8:
    ctx->pc = 0x800602B8u;
    // 800602B8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800602BC:
    ctx->pc = 0x800602BCu;
    // 800602BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800602C0:
    ctx->pc = 0x800602C0u;
    // 800602C0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800602C4:
    ctx->pc = 0x800602C4u;
    // 800602C4: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_800602C8:
    ctx->pc = 0x800602C8u;
    // 800602C8: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800602CC:
    ctx->pc = 0x800602CCu;
    // 800602CC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800602D0:
    ctx->pc = 0x800602D0u;
    // 800602D0: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800602D4:
    ctx->pc = 0x800602D4u;
    // 800602D4: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800602D8:
    ctx->pc = 0x800602D8u;
    // 800602D8: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800602DC:
    ctx->pc = 0x800602DCu;
    // 800602DC: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800602E0:
    ctx->pc = 0x800602E0u;
    // 800602E0: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800602E4:
    ctx->pc = 0x800602E4u;
    // 800602E4: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800602E8:
    ctx->pc = 0x800602E8u;
    // 800602E8: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800602EC:
    ctx->pc = 0x800602ECu;
    // 800602EC: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800602F0:
    ctx->pc = 0x800602F0u;
    // 800602F0: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800602F4:
    ctx->pc = 0x800602F4u;
    // 800602F4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800602F8:
    ctx->pc = 0x800602F8u;
    // 800602F8: bl      0x801698F0
    {
            ctx->lr = 0x800602FCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800602FC:
    ctx->pc = 0x800602FCu;
    ctx->downcount -= 19;
    // 800602FC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80060300:
    ctx->pc = 0x80060300u;
    // 80060300: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80060304:
    ctx->pc = 0x80060304u;
    // 80060304: lwz     r7, 30976(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30976);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80060308:
    ctx->pc = 0x80060308u;
    // 80060308: addi    r30, r8, 13020
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(13020);

label_8006030C:
    ctx->pc = 0x8006030Cu;
    // 8006030C: addi    r9, r9, 30976
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(30976);

label_80060310:
    ctx->pc = 0x80060310u;
    // 80060310: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060314:
    ctx->pc = 0x80060314u;
    // 80060314: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80060318:
    ctx->pc = 0x80060318u;
    // 80060318: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006031C:
    ctx->pc = 0x8006031Cu;
    // 8006031C: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060320:
    ctx->pc = 0x80060320u;
    // 80060320: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80060324:
    ctx->pc = 0x80060324u;
    // 80060324: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060328:
    ctx->pc = 0x80060328u;
    // 80060328: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006032C:
    ctx->pc = 0x8006032Cu;
    // 8006032C: stw     r7, 13020(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(13020);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80060330:
    ctx->pc = 0x80060330u;
    // 80060330: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060334:
    ctx->pc = 0x80060334u;
    // 80060334: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060338:
    ctx->pc = 0x80060338u;
    // 80060338: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006033C:
    ctx->pc = 0x8006033Cu;
    // 8006033C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060340:
    ctx->pc = 0x80060340u;
    // 80060340: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060344:
    ctx->pc = 0x80060344u;
    // 80060344: bl      0x801698F0
    {
            ctx->lr = 0x80060348u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060348:
    ctx->pc = 0x80060348u;
    ctx->downcount -= 22;
    // 80060348: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006034C:
    ctx->pc = 0x8006034Cu;
    // 8006034C: lwz     r9, 728(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(728);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060350:
    ctx->pc = 0x80060350u;
    // 80060350: lis     r0, 3
    ctx->gpr[0] = ((u32)(s32)(3) << 16);

label_80060354:
    ctx->pc = 0x80060354u;
    // 80060354: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80060358:
    ctx->pc = 0x80060358u;
    // 80060358: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8006035C:
    ctx->pc = 0x8006035Cu;
    // 8006035C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060360:
    ctx->pc = 0x80060360u;
    // 80060360: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060364:
    ctx->pc = 0x80060364u;
    // 80060364: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060368:
    ctx->pc = 0x80060368u;
    // 80060368: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006036C:
    ctx->pc = 0x8006036Cu;
    // 8006036C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060370:
    ctx->pc = 0x80060370u;
    // 80060370: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80060374:
    ctx->pc = 0x80060374u;
    // 80060374: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060378:
    ctx->pc = 0x80060378u;
    // 80060378: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006037C:
    ctx->pc = 0x8006037Cu;
    // 8006037C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060380:
    ctx->pc = 0x80060380u;
    // 80060380: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060384:
    ctx->pc = 0x80060384u;
    // 80060384: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060388:
    ctx->pc = 0x80060388u;
    // 80060388: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006038C:
    ctx->pc = 0x8006038Cu;
    // 8006038C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060390:
    ctx->pc = 0x80060390u;
    // 80060390: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060394:
    ctx->pc = 0x80060394u;
    // 80060394: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060398:
    ctx->pc = 0x80060398u;
    // 80060398: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006039C:
    ctx->pc = 0x8006039Cu;
    // 8006039C: bl      0x801698F0
    {
            ctx->lr = 0x800603A0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800603A0:
    ctx->pc = 0x800603A0u;
    ctx->downcount -= 22;
    // 800603A0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800603A4:
    ctx->pc = 0x800603A4u;
    // 800603A4: lwz     r9, 704(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(704);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800603A8:
    ctx->pc = 0x800603A8u;
    // 800603A8: lis     r0, 3
    ctx->gpr[0] = ((u32)(s32)(3) << 16);

label_800603AC:
    ctx->pc = 0x800603ACu;
    // 800603AC: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_800603B0:
    ctx->pc = 0x800603B0u;
    // 800603B0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800603B4:
    ctx->pc = 0x800603B4u;
    // 800603B4: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800603B8:
    ctx->pc = 0x800603B8u;
    // 800603B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800603BC:
    ctx->pc = 0x800603BCu;
    // 800603BC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800603C0:
    ctx->pc = 0x800603C0u;
    // 800603C0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800603C4:
    ctx->pc = 0x800603C4u;
    // 800603C4: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800603C8:
    ctx->pc = 0x800603C8u;
    // 800603C8: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800603CC:
    ctx->pc = 0x800603CCu;
    // 800603CC: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800603D0:
    ctx->pc = 0x800603D0u;
    // 800603D0: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800603D4:
    ctx->pc = 0x800603D4u;
    // 800603D4: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800603D8:
    ctx->pc = 0x800603D8u;
    // 800603D8: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800603DC:
    ctx->pc = 0x800603DCu;
    // 800603DC: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800603E0:
    ctx->pc = 0x800603E0u;
    // 800603E0: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800603E4:
    ctx->pc = 0x800603E4u;
    // 800603E4: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800603E8:
    ctx->pc = 0x800603E8u;
    // 800603E8: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800603EC:
    ctx->pc = 0x800603ECu;
    // 800603EC: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800603F0:
    ctx->pc = 0x800603F0u;
    // 800603F0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800603F4:
    ctx->pc = 0x800603F4u;
    // 800603F4: bl      0x801698F0
    {
            ctx->lr = 0x800603F8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800603F8:
    ctx->pc = 0x800603F8u;
    ctx->downcount -= 21;
    // 800603F8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800603FC:
    ctx->pc = 0x800603FCu;
    // 800603FC: lwz     r6, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80060400:
    ctx->pc = 0x80060400u;
    // 80060400: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060404:
    ctx->pc = 0x80060404u;
    // 80060404: lwz     r9, 824(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(824);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060408:
    ctx->pc = 0x80060408u;
    // 80060408: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006040C:
    ctx->pc = 0x8006040Cu;
    // 8006040C: stw     r6, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060410:
    ctx->pc = 0x80060410u;
    // 80060410: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060414:
    ctx->pc = 0x80060414u;
    // 80060414: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060418:
    ctx->pc = 0x80060418u;
    // 80060418: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8006041C:
    ctx->pc = 0x8006041Cu;
    // 8006041C: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060420:
    ctx->pc = 0x80060420u;
    // 80060420: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060424:
    ctx->pc = 0x80060424u;
    // 80060424: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060428:
    ctx->pc = 0x80060428u;
    // 80060428: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006042C:
    ctx->pc = 0x8006042Cu;
    // 8006042C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060430:
    ctx->pc = 0x80060430u;
    // 80060430: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060434:
    ctx->pc = 0x80060434u;
    // 80060434: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060438:
    ctx->pc = 0x80060438u;
    // 80060438: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006043C:
    ctx->pc = 0x8006043Cu;
    // 8006043C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060440:
    ctx->pc = 0x80060440u;
    // 80060440: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060444:
    ctx->pc = 0x80060444u;
    // 80060444: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060448:
    ctx->pc = 0x80060448u;
    // 80060448: bl      0x801698F0
    {
            ctx->lr = 0x8006044Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006044C:
    ctx->pc = 0x8006044Cu;
    ctx->downcount -= 22;
    // 8006044C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060450:
    ctx->pc = 0x80060450u;
    // 80060450: lwz     r9, 656(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(656);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060454:
    ctx->pc = 0x80060454u;
    // 80060454: lis     r0, 3
    ctx->gpr[0] = ((u32)(s32)(3) << 16);

label_80060458:
    ctx->pc = 0x80060458u;
    // 80060458: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_8006045C:
    ctx->pc = 0x8006045Cu;
    // 8006045C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060460:
    ctx->pc = 0x80060460u;
    // 80060460: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060464:
    ctx->pc = 0x80060464u;
    // 80060464: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060468:
    ctx->pc = 0x80060468u;
    // 80060468: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006046C:
    ctx->pc = 0x8006046Cu;
    // 8006046C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060470:
    ctx->pc = 0x80060470u;
    // 80060470: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060474:
    ctx->pc = 0x80060474u;
    // 80060474: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_80060478:
    ctx->pc = 0x80060478u;
    // 80060478: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006047C:
    ctx->pc = 0x8006047Cu;
    // 8006047C: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060480:
    ctx->pc = 0x80060480u;
    // 80060480: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060484:
    ctx->pc = 0x80060484u;
    // 80060484: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060488:
    ctx->pc = 0x80060488u;
    // 80060488: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006048C:
    ctx->pc = 0x8006048Cu;
    // 8006048C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060490:
    ctx->pc = 0x80060490u;
    // 80060490: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060494:
    ctx->pc = 0x80060494u;
    // 80060494: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060498:
    ctx->pc = 0x80060498u;
    // 80060498: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006049C:
    ctx->pc = 0x8006049Cu;
    // 8006049C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800604A0:
    ctx->pc = 0x800604A0u;
    // 800604A0: bl      0x801698F0
    {
            ctx->lr = 0x800604A4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800604A4:
    ctx->pc = 0x800604A4u;
    ctx->downcount -= 33;
    // 800604A4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800604A8:
    ctx->pc = 0x800604A8u;
    // 800604A8: lwz     r0, 36(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(36);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800604AC:
    ctx->pc = 0x800604ACu;
    // 800604AC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800604B0:
    ctx->pc = 0x800604B0u;
    // 800604B0: lwz     r7, 824(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(824);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800604B4:
    ctx->pc = 0x800604B4u;
    // 800604B4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800604B8:
    ctx->pc = 0x800604B8u;
    // 800604B8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800604BC:
    ctx->pc = 0x800604BCu;
    // 800604BC: addi    r10, r9, 30996
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(30996);

label_800604C0:
    ctx->pc = 0x800604C0u;
    // 800604C0: stw     r7, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800604C4:
    ctx->pc = 0x800604C4u;
    // 800604C4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800604C8:
    ctx->pc = 0x800604C8u;
    // 800604C8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800604CC:
    ctx->pc = 0x800604CCu;
    // 800604CC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800604D0:
    ctx->pc = 0x800604D0u;
    // 800604D0: lwz     r6, 30996(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(30996);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800604D4:
    ctx->pc = 0x800604D4u;
    // 800604D4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800604D8:
    ctx->pc = 0x800604D8u;
    // 800604D8: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800604DC:
    ctx->pc = 0x800604DCu;
    // 800604DC: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800604E0:
    ctx->pc = 0x800604E0u;
    // 800604E0: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800604E4:
    ctx->pc = 0x800604E4u;
    // 800604E4: lwz     r8, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800604E8:
    ctx->pc = 0x800604E8u;
    // 800604E8: stw     r7, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800604EC:
    ctx->pc = 0x800604ECu;
    // 800604EC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800604F0:
    ctx->pc = 0x800604F0u;
    // 800604F0: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800604F4:
    ctx->pc = 0x800604F4u;
    // 800604F4: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800604F8:
    ctx->pc = 0x800604F8u;
    // 800604F8: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800604FC:
    ctx->pc = 0x800604FCu;
    // 800604FC: stwu     r6, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[30] = ea;
    }

label_80060500:
    ctx->pc = 0x80060500u;
    // 80060500: lwz     r8, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060504:
    ctx->pc = 0x80060504u;
    // 80060504: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060508:
    ctx->pc = 0x80060508u;
    // 80060508: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006050C:
    ctx->pc = 0x8006050Cu;
    // 8006050C: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060510:
    ctx->pc = 0x80060510u;
    // 80060510: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060514:
    ctx->pc = 0x80060514u;
    // 80060514: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060518:
    ctx->pc = 0x80060518u;
    // 80060518: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006051C:
    ctx->pc = 0x8006051Cu;
    // 8006051C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060520:
    ctx->pc = 0x80060520u;
    // 80060520: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060524:
    ctx->pc = 0x80060524u;
    // 80060524: bl      0x801698F0
    {
            ctx->lr = 0x80060528u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060528:
    ctx->pc = 0x80060528u;
    ctx->downcount -= 23;
    // 80060528: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006052C:
    ctx->pc = 0x8006052Cu;
    // 8006052C: lis     r0, 3
    ctx->gpr[0] = ((u32)(s32)(3) << 16);

label_80060530:
    ctx->pc = 0x80060530u;
    // 80060530: lwz     r9, 488(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(488);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060534:
    ctx->pc = 0x80060534u;
    // 80060534: ori     r0, r0, 0x0014
    ctx->gpr[0] = ctx->gpr[0] | 0x0014u;

label_80060538:
    ctx->pc = 0x80060538u;
    // 80060538: stw     r18, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[18]);
    }

label_8006053C:
    ctx->pc = 0x8006053Cu;
    // 8006053C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060540:
    ctx->pc = 0x80060540u;
    // 80060540: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060544:
    ctx->pc = 0x80060544u;
    // 80060544: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060548:
    ctx->pc = 0x80060548u;
    // 80060548: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006054C:
    ctx->pc = 0x8006054Cu;
    // 8006054C: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060550:
    ctx->pc = 0x80060550u;
    // 80060550: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060554:
    ctx->pc = 0x80060554u;
    // 80060554: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060558:
    ctx->pc = 0x80060558u;
    // 80060558: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8006055C:
    ctx->pc = 0x8006055Cu;
    // 8006055C: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060560:
    ctx->pc = 0x80060560u;
    // 80060560: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060564:
    ctx->pc = 0x80060564u;
    // 80060564: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060568:
    ctx->pc = 0x80060568u;
    // 80060568: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006056C:
    ctx->pc = 0x8006056Cu;
    // 8006056C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060570:
    ctx->pc = 0x80060570u;
    // 80060570: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060574:
    ctx->pc = 0x80060574u;
    // 80060574: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060578:
    ctx->pc = 0x80060578u;
    // 80060578: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006057C:
    ctx->pc = 0x8006057Cu;
    // 8006057C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060580:
    ctx->pc = 0x80060580u;
    // 80060580: bl      0x801698F0
    {
            ctx->lr = 0x80060584u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060584:
    ctx->pc = 0x80060584u;
    ctx->downcount -= 23;
    // 80060584: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060588:
    ctx->pc = 0x80060588u;
    // 80060588: lis     r0, 3
    ctx->gpr[0] = ((u32)(s32)(3) << 16);

label_8006058C:
    ctx->pc = 0x8006058Cu;
    // 8006058C: lwz     r9, 584(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(584);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060590:
    ctx->pc = 0x80060590u;
    // 80060590: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_80060594:
    ctx->pc = 0x80060594u;
    // 80060594: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80060598:
    ctx->pc = 0x80060598u;
    // 80060598: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006059C:
    ctx->pc = 0x8006059Cu;
    // 8006059C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800605A0:
    ctx->pc = 0x800605A0u;
    // 800605A0: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_800605A4:
    ctx->pc = 0x800605A4u;
    // 800605A4: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800605A8:
    ctx->pc = 0x800605A8u;
    // 800605A8: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800605AC:
    ctx->pc = 0x800605ACu;
    // 800605AC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800605B0:
    ctx->pc = 0x800605B0u;
    // 800605B0: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800605B4:
    ctx->pc = 0x800605B4u;
    // 800605B4: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_800605B8:
    ctx->pc = 0x800605B8u;
    // 800605B8: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800605BC:
    ctx->pc = 0x800605BCu;
    // 800605BC: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800605C0:
    ctx->pc = 0x800605C0u;
    // 800605C0: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800605C4:
    ctx->pc = 0x800605C4u;
    // 800605C4: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800605C8:
    ctx->pc = 0x800605C8u;
    // 800605C8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800605CC:
    ctx->pc = 0x800605CCu;
    // 800605CC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800605D0:
    ctx->pc = 0x800605D0u;
    // 800605D0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800605D4:
    ctx->pc = 0x800605D4u;
    // 800605D4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800605D8:
    ctx->pc = 0x800605D8u;
    // 800605D8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800605DC:
    ctx->pc = 0x800605DCu;
    // 800605DC: bl      0x801698F0
    {
            ctx->lr = 0x800605E0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800605E0:
    ctx->pc = 0x800605E0u;
    ctx->downcount -= 25;
    // 800605E0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800605E4:
    ctx->pc = 0x800605E4u;
    // 800605E4: lis     r0, 3
    ctx->gpr[0] = ((u32)(s32)(3) << 16);

label_800605E8:
    ctx->pc = 0x800605E8u;
    // 800605E8: lwz     r11, 512(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(512);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800605EC:
    ctx->pc = 0x800605ECu;
    // 800605EC: ori     r0, r0, 0x0015
    ctx->gpr[0] = ctx->gpr[0] | 0x0015u;

label_800605F0:
    ctx->pc = 0x800605F0u;
    // 800605F0: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_800605F4:
    ctx->pc = 0x800605F4u;
    // 800605F4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800605F8:
    ctx->pc = 0x800605F8u;
    // 800605F8: addi    r9, r9, 9036
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9036);

label_800605FC:
    ctx->pc = 0x800605FCu;
    // 800605FC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060600:
    ctx->pc = 0x80060600u;
    // 80060600: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060604:
    ctx->pc = 0x80060604u;
    // 80060604: stw     r11, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060608:
    ctx->pc = 0x80060608u;
    // 80060608: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006060C:
    ctx->pc = 0x8006060Cu;
    // 8006060C: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060610:
    ctx->pc = 0x80060610u;
    // 80060610: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060614:
    ctx->pc = 0x80060614u;
    // 80060614: stw     r11, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060618:
    ctx->pc = 0x80060618u;
    // 80060618: or   r3, r29, r29
    {
        ctx->gpr[3] = ctx->gpr[29] | ctx->gpr[29];
    }

label_8006061C:
    ctx->pc = 0x8006061Cu;
    // 8006061C: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060620:
    ctx->pc = 0x80060620u;
    // 80060620: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060624:
    ctx->pc = 0x80060624u;
    // 80060624: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060628:
    ctx->pc = 0x80060628u;
    // 80060628: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006062C:
    ctx->pc = 0x8006062Cu;
    // 8006062C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060630:
    ctx->pc = 0x80060630u;
    // 80060630: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060634:
    ctx->pc = 0x80060634u;
    // 80060634: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060638:
    ctx->pc = 0x80060638u;
    // 80060638: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006063C:
    ctx->pc = 0x8006063Cu;
    // 8006063C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060640:
    ctx->pc = 0x80060640u;
    // 80060640: bl      0x801698F0
    {
            ctx->lr = 0x80060644u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060644:
    ctx->pc = 0x80060644u;
    ctx->downcount -= 22;
    // 80060644: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060648:
    ctx->pc = 0x80060648u;
    // 80060648: lwz     r9, 152(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(152);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006064C:
    ctx->pc = 0x8006064Cu;
    // 8006064C: lis     r0, 3
    ctx->gpr[0] = ((u32)(s32)(3) << 16);

label_80060650:
    ctx->pc = 0x80060650u;
    // 80060650: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_80060654:
    ctx->pc = 0x80060654u;
    // 80060654: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060658:
    ctx->pc = 0x80060658u;
    // 80060658: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006065C:
    ctx->pc = 0x8006065Cu;
    // 8006065C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060660:
    ctx->pc = 0x80060660u;
    // 80060660: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060664:
    ctx->pc = 0x80060664u;
    // 80060664: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80060668:
    ctx->pc = 0x80060668u;
    // 80060668: stw     r9, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006066C:
    ctx->pc = 0x8006066Cu;
    // 8006066C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060670:
    ctx->pc = 0x80060670u;
    // 80060670: stw     r9, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060674:
    ctx->pc = 0x80060674u;
    // 80060674: lwz     r9, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060678:
    ctx->pc = 0x80060678u;
    // 80060678: lwz     r10, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006067C:
    ctx->pc = 0x8006067Cu;
    // 8006067C: lwz     r0, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060680:
    ctx->pc = 0x80060680u;
    // 80060680: lwz     r11, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060684:
    ctx->pc = 0x80060684u;
    // 80060684: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060688:
    ctx->pc = 0x80060688u;
    // 80060688: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006068C:
    ctx->pc = 0x8006068Cu;
    // 8006068C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060690:
    ctx->pc = 0x80060690u;
    // 80060690: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060694:
    ctx->pc = 0x80060694u;
    // 80060694: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060698:
    ctx->pc = 0x80060698u;
    // 80060698: bl      0x801698F0
    {
            ctx->lr = 0x8006069Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006069C:
    ctx->pc = 0x8006069Cu;
    ctx->downcount -= 19;
    // 8006069C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800606A0:
    ctx->pc = 0x800606A0u;
    // 800606A0: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_800606A4:
    ctx->pc = 0x800606A4u;
    // 800606A4: lwz     r7, 31016(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31016);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800606A8:
    ctx->pc = 0x800606A8u;
    // 800606A8: addi    r30, r8, 13260
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(13260);

label_800606AC:
    ctx->pc = 0x800606ACu;
    // 800606AC: addi    r9, r9, 31016
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31016);

label_800606B0:
    ctx->pc = 0x800606B0u;
    // 800606B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800606B4:
    ctx->pc = 0x800606B4u;
    // 800606B4: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800606B8:
    ctx->pc = 0x800606B8u;
    // 800606B8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800606BC:
    ctx->pc = 0x800606BCu;
    // 800606BC: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800606C0:
    ctx->pc = 0x800606C0u;
    // 800606C0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800606C4:
    ctx->pc = 0x800606C4u;
    // 800606C4: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800606C8:
    ctx->pc = 0x800606C8u;
    // 800606C8: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800606CC:
    ctx->pc = 0x800606CCu;
    // 800606CC: stw     r7, 13260(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(13260);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800606D0:
    ctx->pc = 0x800606D0u;
    // 800606D0: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800606D4:
    ctx->pc = 0x800606D4u;
    // 800606D4: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800606D8:
    ctx->pc = 0x800606D8u;
    // 800606D8: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800606DC:
    ctx->pc = 0x800606DCu;
    // 800606DC: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800606E0:
    ctx->pc = 0x800606E0u;
    // 800606E0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800606E4:
    ctx->pc = 0x800606E4u;
    // 800606E4: bl      0x801698F0
    {
            ctx->lr = 0x800606E8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800606E8:
    ctx->pc = 0x800606E8u;
    ctx->downcount -= 23;
    // 800606E8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800606EC:
    ctx->pc = 0x800606ECu;
    // 800606EC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800606F0:
    ctx->pc = 0x800606F0u;
    // 800606F0: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_800606F4:
    ctx->pc = 0x800606F4u;
    // 800606F4: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800606F8:
    ctx->pc = 0x800606F8u;
    // 800606F8: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_800606FC:
    ctx->pc = 0x800606FCu;
    // 800606FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060700:
    ctx->pc = 0x80060700u;
    // 80060700: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060704:
    ctx->pc = 0x80060704u;
    // 80060704: lwz     r8, 728(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060708:
    ctx->pc = 0x80060708u;
    // 80060708: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8006070C:
    ctx->pc = 0x8006070Cu;
    // 8006070C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060710:
    ctx->pc = 0x80060710u;
    // 80060710: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060714:
    ctx->pc = 0x80060714u;
    // 80060714: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060718:
    ctx->pc = 0x80060718u;
    // 80060718: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006071C:
    ctx->pc = 0x8006071Cu;
    // 8006071C: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060720:
    ctx->pc = 0x80060720u;
    // 80060720: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060724:
    ctx->pc = 0x80060724u;
    // 80060724: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060728:
    ctx->pc = 0x80060728u;
    // 80060728: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006072C:
    ctx->pc = 0x8006072Cu;
    // 8006072C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060730:
    ctx->pc = 0x80060730u;
    // 80060730: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060734:
    ctx->pc = 0x80060734u;
    // 80060734: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060738:
    ctx->pc = 0x80060738u;
    // 80060738: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006073C:
    ctx->pc = 0x8006073Cu;
    // 8006073C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060740:
    ctx->pc = 0x80060740u;
    // 80060740: bl      0x801698F0
    {
            ctx->lr = 0x80060744u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060744:
    ctx->pc = 0x80060744u;
    ctx->downcount -= 22;
    // 80060744: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060748:
    ctx->pc = 0x80060748u;
    // 80060748: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_8006074C:
    ctx->pc = 0x8006074Cu;
    // 8006074C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060750:
    ctx->pc = 0x80060750u;
    // 80060750: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_80060754:
    ctx->pc = 0x80060754u;
    // 80060754: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060758:
    ctx->pc = 0x80060758u;
    // 80060758: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006075C:
    ctx->pc = 0x8006075Cu;
    // 8006075C: lwz     r8, 704(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060760:
    ctx->pc = 0x80060760u;
    // 80060760: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060764:
    ctx->pc = 0x80060764u;
    // 80060764: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060768:
    ctx->pc = 0x80060768u;
    // 80060768: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006076C:
    ctx->pc = 0x8006076Cu;
    // 8006076C: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060770:
    ctx->pc = 0x80060770u;
    // 80060770: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060774:
    ctx->pc = 0x80060774u;
    // 80060774: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060778:
    ctx->pc = 0x80060778u;
    // 80060778: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006077C:
    ctx->pc = 0x8006077Cu;
    // 8006077C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060780:
    ctx->pc = 0x80060780u;
    // 80060780: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060784:
    ctx->pc = 0x80060784u;
    // 80060784: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060788:
    ctx->pc = 0x80060788u;
    // 80060788: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006078C:
    ctx->pc = 0x8006078Cu;
    // 8006078C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060790:
    ctx->pc = 0x80060790u;
    // 80060790: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060794:
    ctx->pc = 0x80060794u;
    // 80060794: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060798:
    ctx->pc = 0x80060798u;
    // 80060798: bl      0x801698F0
    {
            ctx->lr = 0x8006079Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006079C:
    ctx->pc = 0x8006079Cu;
    ctx->downcount -= 22;
    // 8006079C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800607A0:
    ctx->pc = 0x800607A0u;
    // 800607A0: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_800607A4:
    ctx->pc = 0x800607A4u;
    // 800607A4: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800607A8:
    ctx->pc = 0x800607A8u;
    // 800607A8: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_800607AC:
    ctx->pc = 0x800607ACu;
    // 800607AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800607B0:
    ctx->pc = 0x800607B0u;
    // 800607B0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800607B4:
    ctx->pc = 0x800607B4u;
    // 800607B4: lwz     r8, 656(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(656);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800607B8:
    ctx->pc = 0x800607B8u;
    // 800607B8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800607BC:
    ctx->pc = 0x800607BCu;
    // 800607BC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800607C0:
    ctx->pc = 0x800607C0u;
    // 800607C0: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800607C4:
    ctx->pc = 0x800607C4u;
    // 800607C4: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800607C8:
    ctx->pc = 0x800607C8u;
    // 800607C8: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800607CC:
    ctx->pc = 0x800607CCu;
    // 800607CC: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800607D0:
    ctx->pc = 0x800607D0u;
    // 800607D0: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800607D4:
    ctx->pc = 0x800607D4u;
    // 800607D4: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800607D8:
    ctx->pc = 0x800607D8u;
    // 800607D8: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800607DC:
    ctx->pc = 0x800607DCu;
    // 800607DC: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800607E0:
    ctx->pc = 0x800607E0u;
    // 800607E0: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800607E4:
    ctx->pc = 0x800607E4u;
    // 800607E4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800607E8:
    ctx->pc = 0x800607E8u;
    // 800607E8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800607EC:
    ctx->pc = 0x800607ECu;
    // 800607EC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800607F0:
    ctx->pc = 0x800607F0u;
    // 800607F0: bl      0x801698F0
    {
            ctx->lr = 0x800607F4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800607F4:
    ctx->pc = 0x800607F4u;
    ctx->downcount -= 34;
    // 800607F4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800607F8:
    ctx->pc = 0x800607F8u;
    // 800607F8: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_800607FC:
    ctx->pc = 0x800607FCu;
    // 800607FC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060800:
    ctx->pc = 0x80060800u;
    // 80060800: ori     r0, r0, 0x0022
    ctx->gpr[0] = ctx->gpr[0] | 0x0022u;

label_80060804:
    ctx->pc = 0x80060804u;
    // 80060804: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80060808:
    ctx->pc = 0x80060808u;
    // 80060808: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006080C:
    ctx->pc = 0x8006080Cu;
    // 8006080C: lwz     r29, 824(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(824);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80060810:
    ctx->pc = 0x80060810u;
    // 80060810: addi    r10, r9, 31036
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(31036);

label_80060814:
    ctx->pc = 0x80060814u;
    // 80060814: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060818:
    ctx->pc = 0x80060818u;
    // 80060818: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006081C:
    ctx->pc = 0x8006081Cu;
    // 8006081C: lwz     r0, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060820:
    ctx->pc = 0x80060820u;
    // 80060820: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060824:
    ctx->pc = 0x80060824u;
    // 80060824: lwz     r6, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80060828:
    ctx->pc = 0x80060828u;
    // 80060828: lwz     r7, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8006082C:
    ctx->pc = 0x8006082Cu;
    // 8006082C: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060830:
    ctx->pc = 0x80060830u;
    // 80060830: lwz     r8, 31036(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31036);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060834:
    ctx->pc = 0x80060834u;
    // 80060834: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060838:
    ctx->pc = 0x80060838u;
    // 80060838: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8006083C:
    ctx->pc = 0x8006083Cu;
    // 8006083C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060840:
    ctx->pc = 0x80060840u;
    // 80060840: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060844:
    ctx->pc = 0x80060844u;
    // 80060844: stw     r29, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80060848:
    ctx->pc = 0x80060848u;
    // 80060848: lwz     r7, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8006084C:
    ctx->pc = 0x8006084Cu;
    // 8006084C: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80060850:
    ctx->pc = 0x80060850u;
    // 80060850: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060854:
    ctx->pc = 0x80060854u;
    // 80060854: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060858:
    ctx->pc = 0x80060858u;
    // 80060858: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006085C:
    ctx->pc = 0x8006085Cu;
    // 8006085C: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80060860:
    ctx->pc = 0x80060860u;
    // 80060860: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060864:
    ctx->pc = 0x80060864u;
    // 80060864: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060868:
    ctx->pc = 0x80060868u;
    // 80060868: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006086C:
    ctx->pc = 0x8006086Cu;
    // 8006086C: stw     r29, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80060870:
    ctx->pc = 0x80060870u;
    // 80060870: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060874:
    ctx->pc = 0x80060874u;
    // 80060874: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060878:
    ctx->pc = 0x80060878u;
    // 80060878: bl      0x801698F0
    {
            ctx->lr = 0x8006087Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006087C:
    ctx->pc = 0x8006087Cu;
    ctx->downcount -= 23;
    // 8006087C: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_80060880:
    ctx->pc = 0x80060880u;
    // 80060880: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060884:
    ctx->pc = 0x80060884u;
    // 80060884: ori     r0, r0, 0x0014
    ctx->gpr[0] = ctx->gpr[0] | 0x0014u;

label_80060888:
    ctx->pc = 0x80060888u;
    // 80060888: stw     r18, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[18]);
    }

label_8006088C:
    ctx->pc = 0x8006088Cu;
    // 8006088C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060890:
    ctx->pc = 0x80060890u;
    // 80060890: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060894:
    ctx->pc = 0x80060894u;
    // 80060894: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060898:
    ctx->pc = 0x80060898u;
    // 80060898: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006089C:
    ctx->pc = 0x8006089Cu;
    // 8006089C: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800608A0:
    ctx->pc = 0x800608A0u;
    // 800608A0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800608A4:
    ctx->pc = 0x800608A4u;
    // 800608A4: lwz     r8, 488(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(488);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800608A8:
    ctx->pc = 0x800608A8u;
    // 800608A8: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800608AC:
    ctx->pc = 0x800608ACu;
    // 800608AC: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800608B0:
    ctx->pc = 0x800608B0u;
    // 800608B0: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800608B4:
    ctx->pc = 0x800608B4u;
    // 800608B4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800608B8:
    ctx->pc = 0x800608B8u;
    // 800608B8: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800608BC:
    ctx->pc = 0x800608BCu;
    // 800608BC: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800608C0:
    ctx->pc = 0x800608C0u;
    // 800608C0: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800608C4:
    ctx->pc = 0x800608C4u;
    // 800608C4: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800608C8:
    ctx->pc = 0x800608C8u;
    // 800608C8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800608CC:
    ctx->pc = 0x800608CCu;
    // 800608CC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800608D0:
    ctx->pc = 0x800608D0u;
    // 800608D0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800608D4:
    ctx->pc = 0x800608D4u;
    // 800608D4: bl      0x801698F0
    {
            ctx->lr = 0x800608D8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800608D8:
    ctx->pc = 0x800608D8u;
    ctx->downcount -= 23;
    // 800608D8: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_800608DC:
    ctx->pc = 0x800608DCu;
    // 800608DC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800608E0:
    ctx->pc = 0x800608E0u;
    // 800608E0: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_800608E4:
    ctx->pc = 0x800608E4u;
    // 800608E4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800608E8:
    ctx->pc = 0x800608E8u;
    // 800608E8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800608EC:
    ctx->pc = 0x800608ECu;
    // 800608EC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800608F0:
    ctx->pc = 0x800608F0u;
    // 800608F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800608F4:
    ctx->pc = 0x800608F4u;
    // 800608F4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800608F8:
    ctx->pc = 0x800608F8u;
    // 800608F8: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800608FC:
    ctx->pc = 0x800608FCu;
    // 800608FC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060900:
    ctx->pc = 0x80060900u;
    // 80060900: lwz     r8, 584(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060904:
    ctx->pc = 0x80060904u;
    // 80060904: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060908:
    ctx->pc = 0x80060908u;
    // 80060908: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006090C:
    ctx->pc = 0x8006090Cu;
    // 8006090C: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060910:
    ctx->pc = 0x80060910u;
    // 80060910: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060914:
    ctx->pc = 0x80060914u;
    // 80060914: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060918:
    ctx->pc = 0x80060918u;
    // 80060918: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006091C:
    ctx->pc = 0x8006091Cu;
    // 8006091C: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060920:
    ctx->pc = 0x80060920u;
    // 80060920: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060924:
    ctx->pc = 0x80060924u;
    // 80060924: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060928:
    ctx->pc = 0x80060928u;
    // 80060928: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006092C:
    ctx->pc = 0x8006092Cu;
    // 8006092C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060930:
    ctx->pc = 0x80060930u;
    // 80060930: bl      0x801698F0
    {
            ctx->lr = 0x80060934u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060934:
    ctx->pc = 0x80060934u;
    ctx->downcount -= 25;
    // 80060934: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_80060938:
    ctx->pc = 0x80060938u;
    // 80060938: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8006093C:
    ctx->pc = 0x8006093Cu;
    // 8006093C: ori     r0, r0, 0x0011
    ctx->gpr[0] = ctx->gpr[0] | 0x0011u;

label_80060940:
    ctx->pc = 0x80060940u;
    // 80060940: addi    r9, r9, 7396
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7396);

label_80060944:
    ctx->pc = 0x80060944u;
    // 80060944: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060948:
    ctx->pc = 0x80060948u;
    // 80060948: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006094C:
    ctx->pc = 0x8006094Cu;
    // 8006094C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060950:
    ctx->pc = 0x80060950u;
    // 80060950: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060954:
    ctx->pc = 0x80060954u;
    // 80060954: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060958:
    ctx->pc = 0x80060958u;
    // 80060958: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006095C:
    ctx->pc = 0x8006095Cu;
    // 8006095C: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060960:
    ctx->pc = 0x80060960u;
    // 80060960: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060964:
    ctx->pc = 0x80060964u;
    // 80060964: lwz     r8, 416(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(416);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060968:
    ctx->pc = 0x80060968u;
    // 80060968: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006096C:
    ctx->pc = 0x8006096Cu;
    // 8006096C: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060970:
    ctx->pc = 0x80060970u;
    // 80060970: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060974:
    ctx->pc = 0x80060974u;
    // 80060974: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060978:
    ctx->pc = 0x80060978u;
    // 80060978: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006097C:
    ctx->pc = 0x8006097Cu;
    // 8006097C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060980:
    ctx->pc = 0x80060980u;
    // 80060980: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060984:
    ctx->pc = 0x80060984u;
    // 80060984: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060988:
    ctx->pc = 0x80060988u;
    // 80060988: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006098C:
    ctx->pc = 0x8006098Cu;
    // 8006098C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060990:
    ctx->pc = 0x80060990u;
    // 80060990: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060994:
    ctx->pc = 0x80060994u;
    // 80060994: bl      0x801698F0
    {
            ctx->lr = 0x80060998u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060998:
    ctx->pc = 0x80060998u;
    ctx->downcount -= 25;
    // 80060998: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_8006099C:
    ctx->pc = 0x8006099Cu;
    // 8006099C: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_800609A0:
    ctx->pc = 0x800609A0u;
    // 800609A0: ori     r0, r0, 0x0001
    ctx->gpr[0] = ctx->gpr[0] | 0x0001u;

label_800609A4:
    ctx->pc = 0x800609A4u;
    // 800609A4: addi    r9, r9, 7496
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7496);

label_800609A8:
    ctx->pc = 0x800609A8u;
    // 800609A8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800609AC:
    ctx->pc = 0x800609ACu;
    // 800609AC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800609B0:
    ctx->pc = 0x800609B0u;
    // 800609B0: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_800609B4:
    ctx->pc = 0x800609B4u;
    // 800609B4: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800609B8:
    ctx->pc = 0x800609B8u;
    // 800609B8: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800609BC:
    ctx->pc = 0x800609BCu;
    // 800609BC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800609C0:
    ctx->pc = 0x800609C0u;
    // 800609C0: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800609C4:
    ctx->pc = 0x800609C4u;
    // 800609C4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800609C8:
    ctx->pc = 0x800609C8u;
    // 800609C8: lwz     r8, 32(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(32);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800609CC:
    ctx->pc = 0x800609CCu;
    // 800609CC: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800609D0:
    ctx->pc = 0x800609D0u;
    // 800609D0: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800609D4:
    ctx->pc = 0x800609D4u;
    // 800609D4: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800609D8:
    ctx->pc = 0x800609D8u;
    // 800609D8: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800609DC:
    ctx->pc = 0x800609DCu;
    // 800609DC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800609E0:
    ctx->pc = 0x800609E0u;
    // 800609E0: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800609E4:
    ctx->pc = 0x800609E4u;
    // 800609E4: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800609E8:
    ctx->pc = 0x800609E8u;
    // 800609E8: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800609EC:
    ctx->pc = 0x800609ECu;
    // 800609EC: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800609F0:
    ctx->pc = 0x800609F0u;
    // 800609F0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800609F4:
    ctx->pc = 0x800609F4u;
    // 800609F4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800609F8:
    ctx->pc = 0x800609F8u;
    // 800609F8: bl      0x801698F0
    {
            ctx->lr = 0x800609FCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800609FC:
    ctx->pc = 0x800609FCu;
    ctx->downcount -= 21;
    // 800609FC: lwz     r3, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80060A00:
    ctx->pc = 0x80060A00u;
    // 80060A00: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060A04:
    ctx->pc = 0x80060A04u;
    // 80060A04: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060A08:
    ctx->pc = 0x80060A08u;
    // 80060A08: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060A0C:
    ctx->pc = 0x80060A0Cu;
    // 80060A0C: stw     r3, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060A10:
    ctx->pc = 0x80060A10u;
    // 80060A10: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060A14:
    ctx->pc = 0x80060A14u;
    // 80060A14: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060A18:
    ctx->pc = 0x80060A18u;
    // 80060A18: lwz     r8, 80(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(80);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060A1C:
    ctx->pc = 0x80060A1Cu;
    // 80060A1C: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060A20:
    ctx->pc = 0x80060A20u;
    // 80060A20: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060A24:
    ctx->pc = 0x80060A24u;
    // 80060A24: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060A28:
    ctx->pc = 0x80060A28u;
    // 80060A28: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060A2C:
    ctx->pc = 0x80060A2Cu;
    // 80060A2C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060A30:
    ctx->pc = 0x80060A30u;
    // 80060A30: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060A34:
    ctx->pc = 0x80060A34u;
    // 80060A34: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060A38:
    ctx->pc = 0x80060A38u;
    // 80060A38: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060A3C:
    ctx->pc = 0x80060A3Cu;
    // 80060A3C: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060A40:
    ctx->pc = 0x80060A40u;
    // 80060A40: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060A44:
    ctx->pc = 0x80060A44u;
    // 80060A44: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060A48:
    ctx->pc = 0x80060A48u;
    // 80060A48: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060A4C:
    ctx->pc = 0x80060A4Cu;
    // 80060A4C: bl      0x801698F0
    {
            ctx->lr = 0x80060A50u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060A50:
    ctx->pc = 0x80060A50u;
    ctx->downcount -= 24;
    // 80060A50: lwz     r0, 40(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(40);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060A54:
    ctx->pc = 0x80060A54u;
    // 80060A54: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80060A58:
    ctx->pc = 0x80060A58u;
    // 80060A58: addi    r9, r9, 8216
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8216);

label_80060A5C:
    ctx->pc = 0x80060A5Cu;
    // 80060A5C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060A60:
    ctx->pc = 0x80060A60u;
    // 80060A60: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060A64:
    ctx->pc = 0x80060A64u;
    // 80060A64: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060A68:
    ctx->pc = 0x80060A68u;
    // 80060A68: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060A6C:
    ctx->pc = 0x80060A6Cu;
    // 80060A6C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060A70:
    ctx->pc = 0x80060A70u;
    // 80060A70: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060A74:
    ctx->pc = 0x80060A74u;
    // 80060A74: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060A78:
    ctx->pc = 0x80060A78u;
    // 80060A78: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060A7C:
    ctx->pc = 0x80060A7Cu;
    // 80060A7C: lwz     r8, 80(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(80);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060A80:
    ctx->pc = 0x80060A80u;
    // 80060A80: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060A84:
    ctx->pc = 0x80060A84u;
    // 80060A84: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060A88:
    ctx->pc = 0x80060A88u;
    // 80060A88: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060A8C:
    ctx->pc = 0x80060A8Cu;
    // 80060A8C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060A90:
    ctx->pc = 0x80060A90u;
    // 80060A90: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060A94:
    ctx->pc = 0x80060A94u;
    // 80060A94: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060A98:
    ctx->pc = 0x80060A98u;
    // 80060A98: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060A9C:
    ctx->pc = 0x80060A9Cu;
    // 80060A9C: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060AA0:
    ctx->pc = 0x80060AA0u;
    // 80060AA0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060AA4:
    ctx->pc = 0x80060AA4u;
    // 80060AA4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060AA8:
    ctx->pc = 0x80060AA8u;
    // 80060AA8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060AAC:
    ctx->pc = 0x80060AACu;
    // 80060AAC: bl      0x801698F0
    {
            ctx->lr = 0x80060AB0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060AB0:
    ctx->pc = 0x80060AB0u;
    ctx->downcount -= 21;
    // 80060AB0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060AB4:
    ctx->pc = 0x80060AB4u;
    // 80060AB4: lis     r0, 4
    ctx->gpr[0] = ((u32)(s32)(4) << 16);

label_80060AB8:
    ctx->pc = 0x80060AB8u;
    // 80060AB8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060ABC:
    ctx->pc = 0x80060ABCu;
    // 80060ABC: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_80060AC0:
    ctx->pc = 0x80060AC0u;
    // 80060AC0: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80060AC4:
    ctx->pc = 0x80060AC4u;
    // 80060AC4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060AC8:
    ctx->pc = 0x80060AC8u;
    // 80060AC8: lwz     r8, 152(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(152);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060ACC:
    ctx->pc = 0x80060ACCu;
    // 80060ACC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060AD0:
    ctx->pc = 0x80060AD0u;
    // 80060AD0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060AD4:
    ctx->pc = 0x80060AD4u;
    // 80060AD4: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060AD8:
    ctx->pc = 0x80060AD8u;
    // 80060AD8: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060ADC:
    ctx->pc = 0x80060ADCu;
    // 80060ADC: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060AE0:
    ctx->pc = 0x80060AE0u;
    // 80060AE0: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060AE4:
    ctx->pc = 0x80060AE4u;
    // 80060AE4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060AE8:
    ctx->pc = 0x80060AE8u;
    // 80060AE8: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060AEC:
    ctx->pc = 0x80060AECu;
    // 80060AEC: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060AF0:
    ctx->pc = 0x80060AF0u;
    // 80060AF0: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060AF4:
    ctx->pc = 0x80060AF4u;
    // 80060AF4: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060AF8:
    ctx->pc = 0x80060AF8u;
    // 80060AF8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060AFC:
    ctx->pc = 0x80060AFCu;
    // 80060AFC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060B00:
    ctx->pc = 0x80060B00u;
    // 80060B00: bl      0x801698F0
    {
            ctx->lr = 0x80060B04u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060B04:
    ctx->pc = 0x80060B04u;
    ctx->downcount -= 19;
    // 80060B04: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80060B08:
    ctx->pc = 0x80060B08u;
    // 80060B08: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80060B0C:
    ctx->pc = 0x80060B0Cu;
    // 80060B0C: lwz     r7, 31056(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31056);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80060B10:
    ctx->pc = 0x80060B10u;
    // 80060B10: addi    r30, r8, 13540
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(13540);

label_80060B14:
    ctx->pc = 0x80060B14u;
    // 80060B14: addi    r9, r9, 31056
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31056);

label_80060B18:
    ctx->pc = 0x80060B18u;
    // 80060B18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060B1C:
    ctx->pc = 0x80060B1Cu;
    // 80060B1C: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80060B20:
    ctx->pc = 0x80060B20u;
    // 80060B20: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060B24:
    ctx->pc = 0x80060B24u;
    // 80060B24: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060B28:
    ctx->pc = 0x80060B28u;
    // 80060B28: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060B2C:
    ctx->pc = 0x80060B2Cu;
    // 80060B2C: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060B30:
    ctx->pc = 0x80060B30u;
    // 80060B30: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060B34:
    ctx->pc = 0x80060B34u;
    // 80060B34: stw     r7, 13540(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(13540);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80060B38:
    ctx->pc = 0x80060B38u;
    // 80060B38: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060B3C:
    ctx->pc = 0x80060B3Cu;
    // 80060B3C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060B40:
    ctx->pc = 0x80060B40u;
    // 80060B40: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060B44:
    ctx->pc = 0x80060B44u;
    // 80060B44: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060B48:
    ctx->pc = 0x80060B48u;
    // 80060B48: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060B4C:
    ctx->pc = 0x80060B4Cu;
    // 80060B4C: bl      0x801698F0
    {
            ctx->lr = 0x80060B50u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060B50:
    ctx->pc = 0x80060B50u;
    ctx->downcount -= 23;
    // 80060B50: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060B54:
    ctx->pc = 0x80060B54u;
    // 80060B54: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060B58:
    ctx->pc = 0x80060B58u;
    // 80060B58: lis     r0, 5
    ctx->gpr[0] = ((u32)(s32)(5) << 16);

label_80060B5C:
    ctx->pc = 0x80060B5Cu;
    // 80060B5C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060B60:
    ctx->pc = 0x80060B60u;
    // 80060B60: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80060B64:
    ctx->pc = 0x80060B64u;
    // 80060B64: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060B68:
    ctx->pc = 0x80060B68u;
    // 80060B68: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060B6C:
    ctx->pc = 0x80060B6Cu;
    // 80060B6C: lwz     r8, 728(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060B70:
    ctx->pc = 0x80060B70u;
    // 80060B70: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060B74:
    ctx->pc = 0x80060B74u;
    // 80060B74: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060B78:
    ctx->pc = 0x80060B78u;
    // 80060B78: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060B7C:
    ctx->pc = 0x80060B7Cu;
    // 80060B7C: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060B80:
    ctx->pc = 0x80060B80u;
    // 80060B80: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060B84:
    ctx->pc = 0x80060B84u;
    // 80060B84: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060B88:
    ctx->pc = 0x80060B88u;
    // 80060B88: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060B8C:
    ctx->pc = 0x80060B8Cu;
    // 80060B8C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060B90:
    ctx->pc = 0x80060B90u;
    // 80060B90: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060B94:
    ctx->pc = 0x80060B94u;
    // 80060B94: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060B98:
    ctx->pc = 0x80060B98u;
    // 80060B98: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060B9C:
    ctx->pc = 0x80060B9Cu;
    // 80060B9C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060BA0:
    ctx->pc = 0x80060BA0u;
    // 80060BA0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060BA4:
    ctx->pc = 0x80060BA4u;
    // 80060BA4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060BA8:
    ctx->pc = 0x80060BA8u;
    // 80060BA8: bl      0x801698F0
    {
            ctx->lr = 0x80060BACu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060BAC:
    ctx->pc = 0x80060BACu;
    ctx->downcount -= 22;
    // 80060BAC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060BB0:
    ctx->pc = 0x80060BB0u;
    // 80060BB0: lis     r0, 5
    ctx->gpr[0] = ((u32)(s32)(5) << 16);

label_80060BB4:
    ctx->pc = 0x80060BB4u;
    // 80060BB4: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060BB8:
    ctx->pc = 0x80060BB8u;
    // 80060BB8: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_80060BBC:
    ctx->pc = 0x80060BBCu;
    // 80060BBC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060BC0:
    ctx->pc = 0x80060BC0u;
    // 80060BC0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060BC4:
    ctx->pc = 0x80060BC4u;
    // 80060BC4: lwz     r8, 704(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060BC8:
    ctx->pc = 0x80060BC8u;
    // 80060BC8: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060BCC:
    ctx->pc = 0x80060BCCu;
    // 80060BCC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060BD0:
    ctx->pc = 0x80060BD0u;
    // 80060BD0: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060BD4:
    ctx->pc = 0x80060BD4u;
    // 80060BD4: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060BD8:
    ctx->pc = 0x80060BD8u;
    // 80060BD8: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060BDC:
    ctx->pc = 0x80060BDCu;
    // 80060BDC: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060BE0:
    ctx->pc = 0x80060BE0u;
    // 80060BE0: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060BE4:
    ctx->pc = 0x80060BE4u;
    // 80060BE4: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060BE8:
    ctx->pc = 0x80060BE8u;
    // 80060BE8: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060BEC:
    ctx->pc = 0x80060BECu;
    // 80060BEC: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060BF0:
    ctx->pc = 0x80060BF0u;
    // 80060BF0: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060BF4:
    ctx->pc = 0x80060BF4u;
    // 80060BF4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060BF8:
    ctx->pc = 0x80060BF8u;
    // 80060BF8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060BFC:
    ctx->pc = 0x80060BFCu;
    // 80060BFC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060C00:
    ctx->pc = 0x80060C00u;
    // 80060C00: bl      0x801698F0
    {
            ctx->lr = 0x80060C04u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060C04:
    ctx->pc = 0x80060C04u;
    ctx->downcount -= 21;
    // 80060C04: lwz     r3, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80060C08:
    ctx->pc = 0x80060C08u;
    // 80060C08: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060C0C:
    ctx->pc = 0x80060C0Cu;
    // 80060C0C: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060C10:
    ctx->pc = 0x80060C10u;
    // 80060C10: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060C14:
    ctx->pc = 0x80060C14u;
    // 80060C14: stw     r3, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060C18:
    ctx->pc = 0x80060C18u;
    // 80060C18: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060C1C:
    ctx->pc = 0x80060C1Cu;
    // 80060C1C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060C20:
    ctx->pc = 0x80060C20u;
    // 80060C20: lwz     r8, 824(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(824);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060C24:
    ctx->pc = 0x80060C24u;
    // 80060C24: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060C28:
    ctx->pc = 0x80060C28u;
    // 80060C28: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060C2C:
    ctx->pc = 0x80060C2Cu;
    // 80060C2C: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060C30:
    ctx->pc = 0x80060C30u;
    // 80060C30: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060C34:
    ctx->pc = 0x80060C34u;
    // 80060C34: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060C38:
    ctx->pc = 0x80060C38u;
    // 80060C38: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060C3C:
    ctx->pc = 0x80060C3Cu;
    // 80060C3C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060C40:
    ctx->pc = 0x80060C40u;
    // 80060C40: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060C44:
    ctx->pc = 0x80060C44u;
    // 80060C44: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060C48:
    ctx->pc = 0x80060C48u;
    // 80060C48: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060C4C:
    ctx->pc = 0x80060C4Cu;
    // 80060C4C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060C50:
    ctx->pc = 0x80060C50u;
    // 80060C50: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060C54:
    ctx->pc = 0x80060C54u;
    // 80060C54: bl      0x801698F0
    {
            ctx->lr = 0x80060C58u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060C58:
    ctx->pc = 0x80060C58u;
    ctx->downcount -= 22;
    // 80060C58: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060C5C:
    ctx->pc = 0x80060C5Cu;
    // 80060C5C: lis     r0, 5
    ctx->gpr[0] = ((u32)(s32)(5) << 16);

label_80060C60:
    ctx->pc = 0x80060C60u;
    // 80060C60: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060C64:
    ctx->pc = 0x80060C64u;
    // 80060C64: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_80060C68:
    ctx->pc = 0x80060C68u;
    // 80060C68: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060C6C:
    ctx->pc = 0x80060C6Cu;
    // 80060C6C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060C70:
    ctx->pc = 0x80060C70u;
    // 80060C70: lwz     r8, 656(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(656);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060C74:
    ctx->pc = 0x80060C74u;
    // 80060C74: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060C78:
    ctx->pc = 0x80060C78u;
    // 80060C78: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060C7C:
    ctx->pc = 0x80060C7Cu;
    // 80060C7C: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060C80:
    ctx->pc = 0x80060C80u;
    // 80060C80: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060C84:
    ctx->pc = 0x80060C84u;
    // 80060C84: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060C88:
    ctx->pc = 0x80060C88u;
    // 80060C88: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060C8C:
    ctx->pc = 0x80060C8Cu;
    // 80060C8C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060C90:
    ctx->pc = 0x80060C90u;
    // 80060C90: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060C94:
    ctx->pc = 0x80060C94u;
    // 80060C94: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060C98:
    ctx->pc = 0x80060C98u;
    // 80060C98: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060C9C:
    ctx->pc = 0x80060C9Cu;
    // 80060C9C: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060CA0:
    ctx->pc = 0x80060CA0u;
    // 80060CA0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060CA4:
    ctx->pc = 0x80060CA4u;
    // 80060CA4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060CA8:
    ctx->pc = 0x80060CA8u;
    // 80060CA8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060CAC:
    ctx->pc = 0x80060CACu;
    // 80060CAC: bl      0x801698F0
    {
            ctx->lr = 0x80060CB0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060CB0:
    ctx->pc = 0x80060CB0u;
    ctx->downcount -= 33;
    // 80060CB0: lwz     r0, 44(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(44);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060CB4:
    ctx->pc = 0x80060CB4u;
    // 80060CB4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060CB8:
    ctx->pc = 0x80060CB8u;
    // 80060CB8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060CBC:
    ctx->pc = 0x80060CBCu;
    // 80060CBC: lis     r6, -32738
    ctx->gpr[6] = ((u32)(s32)(-32738) << 16);

label_80060CC0:
    ctx->pc = 0x80060CC0u;
    // 80060CC0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060CC4:
    ctx->pc = 0x80060CC4u;
    // 80060CC4: addi    r10, r6, 31076
    ctx->gpr[10] = ctx->gpr[6] + (u32)(s32)(31076);

label_80060CC8:
    ctx->pc = 0x80060CC8u;
    // 80060CC8: lwz     r7, 31076(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(31076);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80060CCC:
    ctx->pc = 0x80060CCCu;
    // 80060CCC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060CD0:
    ctx->pc = 0x80060CD0u;
    // 80060CD0: lwz     r29, 824(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(824);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80060CD4:
    ctx->pc = 0x80060CD4u;
    // 80060CD4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060CD8:
    ctx->pc = 0x80060CD8u;
    // 80060CD8: lwz     r8, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060CDC:
    ctx->pc = 0x80060CDCu;
    // 80060CDC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060CE0:
    ctx->pc = 0x80060CE0u;
    // 80060CE0: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060CE4:
    ctx->pc = 0x80060CE4u;
    // 80060CE4: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060CE8:
    ctx->pc = 0x80060CE8u;
    // 80060CE8: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060CEC:
    ctx->pc = 0x80060CECu;
    // 80060CEC: stw     r8, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060CF0:
    ctx->pc = 0x80060CF0u;
    // 80060CF0: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060CF4:
    ctx->pc = 0x80060CF4u;
    // 80060CF4: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060CF8:
    ctx->pc = 0x80060CF8u;
    // 80060CF8: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060CFC:
    ctx->pc = 0x80060CFCu;
    // 80060CFC: stw     r29, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80060D00:
    ctx->pc = 0x80060D00u;
    // 80060D00: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_80060D04:
    ctx->pc = 0x80060D04u;
    // 80060D04: lwz     r8, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060D08:
    ctx->pc = 0x80060D08u;
    // 80060D08: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060D0C:
    ctx->pc = 0x80060D0Cu;
    // 80060D0C: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060D10:
    ctx->pc = 0x80060D10u;
    // 80060D10: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060D14:
    ctx->pc = 0x80060D14u;
    // 80060D14: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060D18:
    ctx->pc = 0x80060D18u;
    // 80060D18: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060D1C:
    ctx->pc = 0x80060D1Cu;
    // 80060D1C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060D20:
    ctx->pc = 0x80060D20u;
    // 80060D20: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060D24:
    ctx->pc = 0x80060D24u;
    // 80060D24: stw     r29, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80060D28:
    ctx->pc = 0x80060D28u;
    // 80060D28: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060D2C:
    ctx->pc = 0x80060D2Cu;
    // 80060D2C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060D30:
    ctx->pc = 0x80060D30u;
    // 80060D30: bl      0x801698F0
    {
            ctx->lr = 0x80060D34u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060D34:
    ctx->pc = 0x80060D34u;
    ctx->downcount -= 25;
    // 80060D34: lis     r0, 5
    ctx->gpr[0] = ((u32)(s32)(5) << 16);

label_80060D38:
    ctx->pc = 0x80060D38u;
    // 80060D38: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80060D3C:
    ctx->pc = 0x80060D3Cu;
    // 80060D3C: ori     r0, r0, 0x0002
    ctx->gpr[0] = ctx->gpr[0] | 0x0002u;

label_80060D40:
    ctx->pc = 0x80060D40u;
    // 80060D40: addi    r9, r9, 7696
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(7696);

label_80060D44:
    ctx->pc = 0x80060D44u;
    // 80060D44: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060D48:
    ctx->pc = 0x80060D48u;
    // 80060D48: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060D4C:
    ctx->pc = 0x80060D4Cu;
    // 80060D4C: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80060D50:
    ctx->pc = 0x80060D50u;
    // 80060D50: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060D54:
    ctx->pc = 0x80060D54u;
    // 80060D54: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060D58:
    ctx->pc = 0x80060D58u;
    // 80060D58: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060D5C:
    ctx->pc = 0x80060D5Cu;
    // 80060D5C: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060D60:
    ctx->pc = 0x80060D60u;
    // 80060D60: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060D64:
    ctx->pc = 0x80060D64u;
    // 80060D64: lwz     r8, 56(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(56);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060D68:
    ctx->pc = 0x80060D68u;
    // 80060D68: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060D6C:
    ctx->pc = 0x80060D6Cu;
    // 80060D6C: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060D70:
    ctx->pc = 0x80060D70u;
    // 80060D70: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060D74:
    ctx->pc = 0x80060D74u;
    // 80060D74: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060D78:
    ctx->pc = 0x80060D78u;
    // 80060D78: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060D7C:
    ctx->pc = 0x80060D7Cu;
    // 80060D7C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060D80:
    ctx->pc = 0x80060D80u;
    // 80060D80: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060D84:
    ctx->pc = 0x80060D84u;
    // 80060D84: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060D88:
    ctx->pc = 0x80060D88u;
    // 80060D88: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060D8C:
    ctx->pc = 0x80060D8Cu;
    // 80060D8C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060D90:
    ctx->pc = 0x80060D90u;
    // 80060D90: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060D94:
    ctx->pc = 0x80060D94u;
    // 80060D94: bl      0x801698F0
    {
            ctx->lr = 0x80060D98u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060D98:
    ctx->pc = 0x80060D98u;
    ctx->downcount -= 23;
    // 80060D98: lis     r0, 5
    ctx->gpr[0] = ((u32)(s32)(5) << 16);

label_80060D9C:
    ctx->pc = 0x80060D9Cu;
    // 80060D9C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060DA0:
    ctx->pc = 0x80060DA0u;
    // 80060DA0: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_80060DA4:
    ctx->pc = 0x80060DA4u;
    // 80060DA4: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80060DA8:
    ctx->pc = 0x80060DA8u;
    // 80060DA8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060DAC:
    ctx->pc = 0x80060DACu;
    // 80060DAC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060DB0:
    ctx->pc = 0x80060DB0u;
    // 80060DB0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060DB4:
    ctx->pc = 0x80060DB4u;
    // 80060DB4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060DB8:
    ctx->pc = 0x80060DB8u;
    // 80060DB8: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060DBC:
    ctx->pc = 0x80060DBCu;
    // 80060DBC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060DC0:
    ctx->pc = 0x80060DC0u;
    // 80060DC0: lwz     r8, 584(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060DC4:
    ctx->pc = 0x80060DC4u;
    // 80060DC4: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060DC8:
    ctx->pc = 0x80060DC8u;
    // 80060DC8: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060DCC:
    ctx->pc = 0x80060DCCu;
    // 80060DCC: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060DD0:
    ctx->pc = 0x80060DD0u;
    // 80060DD0: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060DD4:
    ctx->pc = 0x80060DD4u;
    // 80060DD4: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060DD8:
    ctx->pc = 0x80060DD8u;
    // 80060DD8: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060DDC:
    ctx->pc = 0x80060DDCu;
    // 80060DDC: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060DE0:
    ctx->pc = 0x80060DE0u;
    // 80060DE0: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060DE4:
    ctx->pc = 0x80060DE4u;
    // 80060DE4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060DE8:
    ctx->pc = 0x80060DE8u;
    // 80060DE8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060DEC:
    ctx->pc = 0x80060DECu;
    // 80060DEC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060DF0:
    ctx->pc = 0x80060DF0u;
    // 80060DF0: bl      0x801698F0
    {
            ctx->lr = 0x80060DF4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060DF4:
    ctx->pc = 0x80060DF4u;
    ctx->downcount -= 23;
    // 80060DF4: lis     r0, 5
    ctx->gpr[0] = ((u32)(s32)(5) << 16);

label_80060DF8:
    ctx->pc = 0x80060DF8u;
    // 80060DF8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060DFC:
    ctx->pc = 0x80060DFCu;
    // 80060DFC: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_80060E00:
    ctx->pc = 0x80060E00u;
    // 80060E00: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060E04:
    ctx->pc = 0x80060E04u;
    // 80060E04: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060E08:
    ctx->pc = 0x80060E08u;
    // 80060E08: lis     r29, -32735
    ctx->gpr[29] = ((u32)(s32)(-32735) << 16);

label_80060E0C:
    ctx->pc = 0x80060E0Cu;
    // 80060E0C: addi    r29, r29, -2804
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-2804);

label_80060E10:
    ctx->pc = 0x80060E10u;
    // 80060E10: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80060E14:
    ctx->pc = 0x80060E14u;
    // 80060E14: lwz     r8, 152(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(152);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060E18:
    ctx->pc = 0x80060E18u;
    // 80060E18: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060E1C:
    ctx->pc = 0x80060E1Cu;
    // 80060E1C: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060E20:
    ctx->pc = 0x80060E20u;
    // 80060E20: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060E24:
    ctx->pc = 0x80060E24u;
    // 80060E24: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060E28:
    ctx->pc = 0x80060E28u;
    // 80060E28: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060E2C:
    ctx->pc = 0x80060E2Cu;
    // 80060E2C: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060E30:
    ctx->pc = 0x80060E30u;
    // 80060E30: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060E34:
    ctx->pc = 0x80060E34u;
    // 80060E34: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060E38:
    ctx->pc = 0x80060E38u;
    // 80060E38: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060E3C:
    ctx->pc = 0x80060E3Cu;
    // 80060E3C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060E40:
    ctx->pc = 0x80060E40u;
    // 80060E40: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060E44:
    ctx->pc = 0x80060E44u;
    // 80060E44: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060E48:
    ctx->pc = 0x80060E48u;
    // 80060E48: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060E4C:
    ctx->pc = 0x80060E4Cu;
    // 80060E4C: bl      0x801698F0
    {
            ctx->lr = 0x80060E50u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060E50:
    ctx->pc = 0x80060E50u;
    ctx->downcount -= 19;
    // 80060E50: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80060E54:
    ctx->pc = 0x80060E54u;
    // 80060E54: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80060E58:
    ctx->pc = 0x80060E58u;
    // 80060E58: lwz     r7, 31096(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31096);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80060E5C:
    ctx->pc = 0x80060E5Cu;
    // 80060E5C: addi    r30, r8, 13760
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(13760);

label_80060E60:
    ctx->pc = 0x80060E60u;
    // 80060E60: addi    r9, r9, 31096
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31096);

label_80060E64:
    ctx->pc = 0x80060E64u;
    // 80060E64: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060E68:
    ctx->pc = 0x80060E68u;
    // 80060E68: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80060E6C:
    ctx->pc = 0x80060E6Cu;
    // 80060E6C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060E70:
    ctx->pc = 0x80060E70u;
    // 80060E70: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060E74:
    ctx->pc = 0x80060E74u;
    // 80060E74: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060E78:
    ctx->pc = 0x80060E78u;
    // 80060E78: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060E7C:
    ctx->pc = 0x80060E7Cu;
    // 80060E7C: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060E80:
    ctx->pc = 0x80060E80u;
    // 80060E80: stw     r7, 13760(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(13760);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80060E84:
    ctx->pc = 0x80060E84u;
    // 80060E84: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060E88:
    ctx->pc = 0x80060E88u;
    // 80060E88: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060E8C:
    ctx->pc = 0x80060E8Cu;
    // 80060E8C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060E90:
    ctx->pc = 0x80060E90u;
    // 80060E90: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060E94:
    ctx->pc = 0x80060E94u;
    // 80060E94: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060E98:
    ctx->pc = 0x80060E98u;
    // 80060E98: bl      0x801698F0
    {
            ctx->lr = 0x80060E9Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060E9C:
    ctx->pc = 0x80060E9Cu;
    ctx->downcount -= 23;
    // 80060E9C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060EA0:
    ctx->pc = 0x80060EA0u;
    // 80060EA0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060EA4:
    ctx->pc = 0x80060EA4u;
    // 80060EA4: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_80060EA8:
    ctx->pc = 0x80060EA8u;
    // 80060EA8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060EAC:
    ctx->pc = 0x80060EACu;
    // 80060EAC: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80060EB0:
    ctx->pc = 0x80060EB0u;
    // 80060EB0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060EB4:
    ctx->pc = 0x80060EB4u;
    // 80060EB4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060EB8:
    ctx->pc = 0x80060EB8u;
    // 80060EB8: lwz     r8, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060EBC:
    ctx->pc = 0x80060EBCu;
    // 80060EBC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060EC0:
    ctx->pc = 0x80060EC0u;
    // 80060EC0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060EC4:
    ctx->pc = 0x80060EC4u;
    // 80060EC4: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060EC8:
    ctx->pc = 0x80060EC8u;
    // 80060EC8: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060ECC:
    ctx->pc = 0x80060ECCu;
    // 80060ECC: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060ED0:
    ctx->pc = 0x80060ED0u;
    // 80060ED0: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060ED4:
    ctx->pc = 0x80060ED4u;
    // 80060ED4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060ED8:
    ctx->pc = 0x80060ED8u;
    // 80060ED8: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060EDC:
    ctx->pc = 0x80060EDCu;
    // 80060EDC: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060EE0:
    ctx->pc = 0x80060EE0u;
    // 80060EE0: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060EE4:
    ctx->pc = 0x80060EE4u;
    // 80060EE4: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060EE8:
    ctx->pc = 0x80060EE8u;
    // 80060EE8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060EEC:
    ctx->pc = 0x80060EECu;
    // 80060EEC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060EF0:
    ctx->pc = 0x80060EF0u;
    // 80060EF0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060EF4:
    ctx->pc = 0x80060EF4u;
    // 80060EF4: bl      0x801698F0
    {
            ctx->lr = 0x80060EF8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060EF8:
    ctx->pc = 0x80060EF8u;
    ctx->downcount -= 22;
    // 80060EF8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060EFC:
    ctx->pc = 0x80060EFCu;
    // 80060EFC: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_80060F00:
    ctx->pc = 0x80060F00u;
    // 80060F00: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060F04:
    ctx->pc = 0x80060F04u;
    // 80060F04: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_80060F08:
    ctx->pc = 0x80060F08u;
    // 80060F08: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060F0C:
    ctx->pc = 0x80060F0Cu;
    // 80060F0C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060F10:
    ctx->pc = 0x80060F10u;
    // 80060F10: lwz     r8, 704(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060F14:
    ctx->pc = 0x80060F14u;
    // 80060F14: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060F18:
    ctx->pc = 0x80060F18u;
    // 80060F18: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060F1C:
    ctx->pc = 0x80060F1Cu;
    // 80060F1C: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060F20:
    ctx->pc = 0x80060F20u;
    // 80060F20: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060F24:
    ctx->pc = 0x80060F24u;
    // 80060F24: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060F28:
    ctx->pc = 0x80060F28u;
    // 80060F28: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060F2C:
    ctx->pc = 0x80060F2Cu;
    // 80060F2C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060F30:
    ctx->pc = 0x80060F30u;
    // 80060F30: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060F34:
    ctx->pc = 0x80060F34u;
    // 80060F34: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060F38:
    ctx->pc = 0x80060F38u;
    // 80060F38: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060F3C:
    ctx->pc = 0x80060F3Cu;
    // 80060F3C: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060F40:
    ctx->pc = 0x80060F40u;
    // 80060F40: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060F44:
    ctx->pc = 0x80060F44u;
    // 80060F44: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060F48:
    ctx->pc = 0x80060F48u;
    // 80060F48: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060F4C:
    ctx->pc = 0x80060F4Cu;
    // 80060F4C: bl      0x801698F0
    {
            ctx->lr = 0x80060F50u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060F50:
    ctx->pc = 0x80060F50u;
    ctx->downcount -= 22;
    // 80060F50: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060F54:
    ctx->pc = 0x80060F54u;
    // 80060F54: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_80060F58:
    ctx->pc = 0x80060F58u;
    // 80060F58: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060F5C:
    ctx->pc = 0x80060F5Cu;
    // 80060F5C: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_80060F60:
    ctx->pc = 0x80060F60u;
    // 80060F60: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060F64:
    ctx->pc = 0x80060F64u;
    // 80060F64: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060F68:
    ctx->pc = 0x80060F68u;
    // 80060F68: lwz     r8, 656(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(656);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060F6C:
    ctx->pc = 0x80060F6Cu;
    // 80060F6C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060F70:
    ctx->pc = 0x80060F70u;
    // 80060F70: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060F74:
    ctx->pc = 0x80060F74u;
    // 80060F74: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80060F78:
    ctx->pc = 0x80060F78u;
    // 80060F78: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060F7C:
    ctx->pc = 0x80060F7Cu;
    // 80060F7C: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060F80:
    ctx->pc = 0x80060F80u;
    // 80060F80: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80060F84:
    ctx->pc = 0x80060F84u;
    // 80060F84: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060F88:
    ctx->pc = 0x80060F88u;
    // 80060F88: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80060F8C:
    ctx->pc = 0x80060F8Cu;
    // 80060F8C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060F90:
    ctx->pc = 0x80060F90u;
    // 80060F90: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060F94:
    ctx->pc = 0x80060F94u;
    // 80060F94: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80060F98:
    ctx->pc = 0x80060F98u;
    // 80060F98: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80060F9C:
    ctx->pc = 0x80060F9Cu;
    // 80060F9C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80060FA0:
    ctx->pc = 0x80060FA0u;
    // 80060FA0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80060FA4:
    ctx->pc = 0x80060FA4u;
    // 80060FA4: bl      0x801698F0
    {
            ctx->lr = 0x80060FA8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80060FA8:
    ctx->pc = 0x80060FA8u;
    ctx->downcount -= 34;
    // 80060FA8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80060FAC:
    ctx->pc = 0x80060FACu;
    // 80060FAC: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_80060FB0:
    ctx->pc = 0x80060FB0u;
    // 80060FB0: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80060FB4:
    ctx->pc = 0x80060FB4u;
    // 80060FB4: ori     r0, r0, 0x0022
    ctx->gpr[0] = ctx->gpr[0] | 0x0022u;

label_80060FB8:
    ctx->pc = 0x80060FB8u;
    // 80060FB8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80060FBC:
    ctx->pc = 0x80060FBCu;
    // 80060FBC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80060FC0:
    ctx->pc = 0x80060FC0u;
    // 80060FC0: lwz     r26, 824(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(824);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_80060FC4:
    ctx->pc = 0x80060FC4u;
    // 80060FC4: addi    r10, r9, 31116
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(31116);

label_80060FC8:
    ctx->pc = 0x80060FC8u;
    // 80060FC8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060FCC:
    ctx->pc = 0x80060FCCu;
    // 80060FCC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80060FD0:
    ctx->pc = 0x80060FD0u;
    // 80060FD0: lwz     r0, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80060FD4:
    ctx->pc = 0x80060FD4u;
    // 80060FD4: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80060FD8:
    ctx->pc = 0x80060FD8u;
    // 80060FD8: lwz     r6, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80060FDC:
    ctx->pc = 0x80060FDCu;
    // 80060FDC: lwz     r7, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80060FE0:
    ctx->pc = 0x80060FE0u;
    // 80060FE0: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80060FE4:
    ctx->pc = 0x80060FE4u;
    // 80060FE4: lwz     r8, 31116(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31116);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80060FE8:
    ctx->pc = 0x80060FE8u;
    // 80060FE8: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80060FEC:
    ctx->pc = 0x80060FECu;
    // 80060FEC: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80060FF0:
    ctx->pc = 0x80060FF0u;
    // 80060FF0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80060FF4:
    ctx->pc = 0x80060FF4u;
    // 80060FF4: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80060FF8:
    ctx->pc = 0x80060FF8u;
    // 80060FF8: stw     r26, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80060FFC:
    ctx->pc = 0x80060FFCu;
    // 80060FFC: lwz     r7, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061000:
    ctx->pc = 0x80061000u;
    // 80061000: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80061004:
    ctx->pc = 0x80061004u;
    // 80061004: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061008:
    ctx->pc = 0x80061008u;
    // 80061008: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006100C:
    ctx->pc = 0x8006100Cu;
    // 8006100C: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061010:
    ctx->pc = 0x80061010u;
    // 80061010: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80061014:
    ctx->pc = 0x80061014u;
    // 80061014: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061018:
    ctx->pc = 0x80061018u;
    // 80061018: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006101C:
    ctx->pc = 0x8006101Cu;
    // 8006101C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061020:
    ctx->pc = 0x80061020u;
    // 80061020: stw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80061024:
    ctx->pc = 0x80061024u;
    // 80061024: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061028:
    ctx->pc = 0x80061028u;
    // 80061028: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006102C:
    ctx->pc = 0x8006102Cu;
    // 8006102C: bl      0x801698F0
    {
            ctx->lr = 0x80061030u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061030:
    ctx->pc = 0x80061030u;
    ctx->downcount -= 25;
    // 80061030: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_80061034:
    ctx->pc = 0x80061034u;
    // 80061034: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_80061038:
    ctx->pc = 0x80061038u;
    // 80061038: addi    r22, r3, 8176
    ctx->gpr[22] = ctx->gpr[3] + (u32)(s32)(8176);

label_8006103C:
    ctx->pc = 0x8006103Cu;
    // 8006103C: ori     r0, r0, 0x0014
    ctx->gpr[0] = ctx->gpr[0] | 0x0014u;

label_80061040:
    ctx->pc = 0x80061040u;
    // 80061040: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_80061044:
    ctx->pc = 0x80061044u;
    // 80061044: stw     r22, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80061048:
    ctx->pc = 0x80061048u;
    // 80061048: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8006104C:
    ctx->pc = 0x8006104Cu;
    // 8006104C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061050:
    ctx->pc = 0x80061050u;
    // 80061050: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061054:
    ctx->pc = 0x80061054u;
    // 80061054: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061058:
    ctx->pc = 0x80061058u;
    // 80061058: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006105C:
    ctx->pc = 0x8006105Cu;
    // 8006105C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061060:
    ctx->pc = 0x80061060u;
    // 80061060: lwz     r8, 488(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(488);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061064:
    ctx->pc = 0x80061064u;
    // 80061064: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061068:
    ctx->pc = 0x80061068u;
    // 80061068: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006106C:
    ctx->pc = 0x8006106Cu;
    // 8006106C: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061070:
    ctx->pc = 0x80061070u;
    // 80061070: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061074:
    ctx->pc = 0x80061074u;
    // 80061074: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061078:
    ctx->pc = 0x80061078u;
    // 80061078: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006107C:
    ctx->pc = 0x8006107Cu;
    // 8006107C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061080:
    ctx->pc = 0x80061080u;
    // 80061080: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061084:
    ctx->pc = 0x80061084u;
    // 80061084: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061088:
    ctx->pc = 0x80061088u;
    // 80061088: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006108C:
    ctx->pc = 0x8006108Cu;
    // 8006108C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061090:
    ctx->pc = 0x80061090u;
    // 80061090: bl      0x801698F0
    {
            ctx->lr = 0x80061094u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061094:
    ctx->pc = 0x80061094u;
    ctx->downcount -= 25;
    // 80061094: lis     r3, -32735
    ctx->gpr[3] = ((u32)(s32)(-32735) << 16);

label_80061098:
    ctx->pc = 0x80061098u;
    // 80061098: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_8006109C:
    ctx->pc = 0x8006109Cu;
    // 8006109C: addi    r31, r3, 8696
    ctx->gpr[31] = ctx->gpr[3] + (u32)(s32)(8696);

label_800610A0:
    ctx->pc = 0x800610A0u;
    // 800610A0: li      r6, 2
    ctx->gpr[6] = (u32)(s32)(2);

label_800610A4:
    ctx->pc = 0x800610A4u;
    // 800610A4: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_800610A8:
    ctx->pc = 0x800610A8u;
    // 800610A8: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_800610AC:
    ctx->pc = 0x800610ACu;
    // 800610AC: stw     r6, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800610B0:
    ctx->pc = 0x800610B0u;
    // 800610B0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800610B4:
    ctx->pc = 0x800610B4u;
    // 800610B4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800610B8:
    ctx->pc = 0x800610B8u;
    // 800610B8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800610BC:
    ctx->pc = 0x800610BCu;
    // 800610BC: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800610C0:
    ctx->pc = 0x800610C0u;
    // 800610C0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800610C4:
    ctx->pc = 0x800610C4u;
    // 800610C4: lwz     r8, 584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800610C8:
    ctx->pc = 0x800610C8u;
    // 800610C8: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800610CC:
    ctx->pc = 0x800610CCu;
    // 800610CC: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800610D0:
    ctx->pc = 0x800610D0u;
    // 800610D0: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800610D4:
    ctx->pc = 0x800610D4u;
    // 800610D4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800610D8:
    ctx->pc = 0x800610D8u;
    // 800610D8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800610DC:
    ctx->pc = 0x800610DCu;
    // 800610DC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800610E0:
    ctx->pc = 0x800610E0u;
    // 800610E0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800610E4:
    ctx->pc = 0x800610E4u;
    // 800610E4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800610E8:
    ctx->pc = 0x800610E8u;
    // 800610E8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800610EC:
    ctx->pc = 0x800610ECu;
    // 800610EC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800610F0:
    ctx->pc = 0x800610F0u;
    // 800610F0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800610F4:
    ctx->pc = 0x800610F4u;
    // 800610F4: bl      0x801698F0
    {
            ctx->lr = 0x800610F8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800610F8:
    ctx->pc = 0x800610F8u;
    ctx->downcount -= 25;
    // 800610F8: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_800610FC:
    ctx->pc = 0x800610FCu;
    // 800610FC: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80061100:
    ctx->pc = 0x80061100u;
    // 80061100: ori     r0, r0, 0x0017
    ctx->gpr[0] = ctx->gpr[0] | 0x0017u;

label_80061104:
    ctx->pc = 0x80061104u;
    // 80061104: addi    r9, r9, 8356
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8356);

label_80061108:
    ctx->pc = 0x80061108u;
    // 80061108: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006110C:
    ctx->pc = 0x8006110Cu;
    // 8006110C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061110:
    ctx->pc = 0x80061110u;
    // 80061110: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80061114:
    ctx->pc = 0x80061114u;
    // 80061114: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061118:
    ctx->pc = 0x80061118u;
    // 80061118: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006111C:
    ctx->pc = 0x8006111Cu;
    // 8006111C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061120:
    ctx->pc = 0x80061120u;
    // 80061120: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061124:
    ctx->pc = 0x80061124u;
    // 80061124: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061128:
    ctx->pc = 0x80061128u;
    // 80061128: lwz     r8, 560(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(560);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006112C:
    ctx->pc = 0x8006112Cu;
    // 8006112C: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061130:
    ctx->pc = 0x80061130u;
    // 80061130: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061134:
    ctx->pc = 0x80061134u;
    // 80061134: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061138:
    ctx->pc = 0x80061138u;
    // 80061138: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006113C:
    ctx->pc = 0x8006113Cu;
    // 8006113C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061140:
    ctx->pc = 0x80061140u;
    // 80061140: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061144:
    ctx->pc = 0x80061144u;
    // 80061144: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061148:
    ctx->pc = 0x80061148u;
    // 80061148: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006114C:
    ctx->pc = 0x8006114Cu;
    // 8006114C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061150:
    ctx->pc = 0x80061150u;
    // 80061150: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061154:
    ctx->pc = 0x80061154u;
    // 80061154: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061158:
    ctx->pc = 0x80061158u;
    // 80061158: bl      0x801698F0
    {
            ctx->lr = 0x8006115Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006115C:
    ctx->pc = 0x8006115Cu;
    ctx->downcount -= 22;
    // 8006115C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061160:
    ctx->pc = 0x80061160u;
    // 80061160: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_80061164:
    ctx->pc = 0x80061164u;
    // 80061164: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061168:
    ctx->pc = 0x80061168u;
    // 80061168: ori     r0, r0, 0x0003
    ctx->gpr[0] = ctx->gpr[0] | 0x0003u;

label_8006116C:
    ctx->pc = 0x8006116Cu;
    // 8006116C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061170:
    ctx->pc = 0x80061170u;
    // 80061170: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061174:
    ctx->pc = 0x80061174u;
    // 80061174: lwz     r8, 80(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(80);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061178:
    ctx->pc = 0x80061178u;
    // 80061178: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8006117C:
    ctx->pc = 0x8006117Cu;
    // 8006117C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061180:
    ctx->pc = 0x80061180u;
    // 80061180: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061184:
    ctx->pc = 0x80061184u;
    // 80061184: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061188:
    ctx->pc = 0x80061188u;
    // 80061188: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006118C:
    ctx->pc = 0x8006118Cu;
    // 8006118C: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061190:
    ctx->pc = 0x80061190u;
    // 80061190: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061194:
    ctx->pc = 0x80061194u;
    // 80061194: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061198:
    ctx->pc = 0x80061198u;
    // 80061198: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006119C:
    ctx->pc = 0x8006119Cu;
    // 8006119C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800611A0:
    ctx->pc = 0x800611A0u;
    // 800611A0: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800611A4:
    ctx->pc = 0x800611A4u;
    // 800611A4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800611A8:
    ctx->pc = 0x800611A8u;
    // 800611A8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800611AC:
    ctx->pc = 0x800611ACu;
    // 800611AC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800611B0:
    ctx->pc = 0x800611B0u;
    // 800611B0: bl      0x801698F0
    {
            ctx->lr = 0x800611B4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800611B4:
    ctx->pc = 0x800611B4u;
    ctx->downcount -= 21;
    // 800611B4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800611B8:
    ctx->pc = 0x800611B8u;
    // 800611B8: lis     r0, 6
    ctx->gpr[0] = ((u32)(s32)(6) << 16);

label_800611BC:
    ctx->pc = 0x800611BCu;
    // 800611BC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800611C0:
    ctx->pc = 0x800611C0u;
    // 800611C0: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_800611C4:
    ctx->pc = 0x800611C4u;
    // 800611C4: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_800611C8:
    ctx->pc = 0x800611C8u;
    // 800611C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800611CC:
    ctx->pc = 0x800611CCu;
    // 800611CC: lwz     r8, 152(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(152);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800611D0:
    ctx->pc = 0x800611D0u;
    // 800611D0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800611D4:
    ctx->pc = 0x800611D4u;
    // 800611D4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800611D8:
    ctx->pc = 0x800611D8u;
    // 800611D8: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800611DC:
    ctx->pc = 0x800611DCu;
    // 800611DC: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800611E0:
    ctx->pc = 0x800611E0u;
    // 800611E0: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800611E4:
    ctx->pc = 0x800611E4u;
    // 800611E4: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800611E8:
    ctx->pc = 0x800611E8u;
    // 800611E8: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800611EC:
    ctx->pc = 0x800611ECu;
    // 800611EC: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800611F0:
    ctx->pc = 0x800611F0u;
    // 800611F0: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800611F4:
    ctx->pc = 0x800611F4u;
    // 800611F4: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800611F8:
    ctx->pc = 0x800611F8u;
    // 800611F8: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800611FC:
    ctx->pc = 0x800611FCu;
    // 800611FC: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061200:
    ctx->pc = 0x80061200u;
    // 80061200: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061204:
    ctx->pc = 0x80061204u;
    // 80061204: bl      0x801698F0
    {
            ctx->lr = 0x80061208u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061208:
    ctx->pc = 0x80061208u;
    ctx->downcount -= 19;
    // 80061208: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_8006120C:
    ctx->pc = 0x8006120Cu;
    // 8006120C: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80061210:
    ctx->pc = 0x80061210u;
    // 80061210: lwz     r7, 31136(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31136);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061214:
    ctx->pc = 0x80061214u;
    // 80061214: addi    r30, r8, 14000
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(14000);

label_80061218:
    ctx->pc = 0x80061218u;
    // 80061218: addi    r9, r9, 31136
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31136);

label_8006121C:
    ctx->pc = 0x8006121Cu;
    // 8006121C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061220:
    ctx->pc = 0x80061220u;
    // 80061220: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80061224:
    ctx->pc = 0x80061224u;
    // 80061224: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061228:
    ctx->pc = 0x80061228u;
    // 80061228: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006122C:
    ctx->pc = 0x8006122Cu;
    // 8006122C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061230:
    ctx->pc = 0x80061230u;
    // 80061230: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061234:
    ctx->pc = 0x80061234u;
    // 80061234: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061238:
    ctx->pc = 0x80061238u;
    // 80061238: stw     r7, 14000(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(14000);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8006123C:
    ctx->pc = 0x8006123Cu;
    // 8006123C: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80061240:
    ctx->pc = 0x80061240u;
    // 80061240: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061244:
    ctx->pc = 0x80061244u;
    // 80061244: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061248:
    ctx->pc = 0x80061248u;
    // 80061248: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006124C:
    ctx->pc = 0x8006124Cu;
    // 8006124C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061250:
    ctx->pc = 0x80061250u;
    // 80061250: bl      0x801698F0
    {
            ctx->lr = 0x80061254u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061254:
    ctx->pc = 0x80061254u;
    ctx->downcount -= 23;
    // 80061254: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061258:
    ctx->pc = 0x80061258u;
    // 80061258: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8006125C:
    ctx->pc = 0x8006125Cu;
    // 8006125C: lis     r0, 7
    ctx->gpr[0] = ((u32)(s32)(7) << 16);

label_80061260:
    ctx->pc = 0x80061260u;
    // 80061260: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061264:
    ctx->pc = 0x80061264u;
    // 80061264: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80061268:
    ctx->pc = 0x80061268u;
    // 80061268: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006126C:
    ctx->pc = 0x8006126Cu;
    // 8006126C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061270:
    ctx->pc = 0x80061270u;
    // 80061270: lwz     r8, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061274:
    ctx->pc = 0x80061274u;
    // 80061274: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061278:
    ctx->pc = 0x80061278u;
    // 80061278: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006127C:
    ctx->pc = 0x8006127Cu;
    // 8006127C: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061280:
    ctx->pc = 0x80061280u;
    // 80061280: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061284:
    ctx->pc = 0x80061284u;
    // 80061284: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061288:
    ctx->pc = 0x80061288u;
    // 80061288: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006128C:
    ctx->pc = 0x8006128Cu;
    // 8006128C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061290:
    ctx->pc = 0x80061290u;
    // 80061290: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061294:
    ctx->pc = 0x80061294u;
    // 80061294: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061298:
    ctx->pc = 0x80061298u;
    // 80061298: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006129C:
    ctx->pc = 0x8006129Cu;
    // 8006129C: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800612A0:
    ctx->pc = 0x800612A0u;
    // 800612A0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800612A4:
    ctx->pc = 0x800612A4u;
    // 800612A4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800612A8:
    ctx->pc = 0x800612A8u;
    // 800612A8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800612AC:
    ctx->pc = 0x800612ACu;
    // 800612AC: bl      0x801698F0
    {
            ctx->lr = 0x800612B0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800612B0:
    ctx->pc = 0x800612B0u;
    ctx->downcount -= 22;
    // 800612B0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800612B4:
    ctx->pc = 0x800612B4u;
    // 800612B4: lis     r0, 7
    ctx->gpr[0] = ((u32)(s32)(7) << 16);

label_800612B8:
    ctx->pc = 0x800612B8u;
    // 800612B8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800612BC:
    ctx->pc = 0x800612BCu;
    // 800612BC: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_800612C0:
    ctx->pc = 0x800612C0u;
    // 800612C0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800612C4:
    ctx->pc = 0x800612C4u;
    // 800612C4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800612C8:
    ctx->pc = 0x800612C8u;
    // 800612C8: lwz     r8, 704(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800612CC:
    ctx->pc = 0x800612CCu;
    // 800612CC: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800612D0:
    ctx->pc = 0x800612D0u;
    // 800612D0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800612D4:
    ctx->pc = 0x800612D4u;
    // 800612D4: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800612D8:
    ctx->pc = 0x800612D8u;
    // 800612D8: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800612DC:
    ctx->pc = 0x800612DCu;
    // 800612DC: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800612E0:
    ctx->pc = 0x800612E0u;
    // 800612E0: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800612E4:
    ctx->pc = 0x800612E4u;
    // 800612E4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800612E8:
    ctx->pc = 0x800612E8u;
    // 800612E8: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800612EC:
    ctx->pc = 0x800612ECu;
    // 800612EC: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800612F0:
    ctx->pc = 0x800612F0u;
    // 800612F0: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800612F4:
    ctx->pc = 0x800612F4u;
    // 800612F4: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800612F8:
    ctx->pc = 0x800612F8u;
    // 800612F8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800612FC:
    ctx->pc = 0x800612FCu;
    // 800612FC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061300:
    ctx->pc = 0x80061300u;
    // 80061300: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061304:
    ctx->pc = 0x80061304u;
    // 80061304: bl      0x801698F0
    {
            ctx->lr = 0x80061308u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061308:
    ctx->pc = 0x80061308u;
    ctx->downcount -= 22;
    // 80061308: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8006130C:
    ctx->pc = 0x8006130Cu;
    // 8006130C: lis     r0, 7
    ctx->gpr[0] = ((u32)(s32)(7) << 16);

label_80061310:
    ctx->pc = 0x80061310u;
    // 80061310: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061314:
    ctx->pc = 0x80061314u;
    // 80061314: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_80061318:
    ctx->pc = 0x80061318u;
    // 80061318: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006131C:
    ctx->pc = 0x8006131Cu;
    // 8006131C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061320:
    ctx->pc = 0x80061320u;
    // 80061320: lwz     r8, 656(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(656);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061324:
    ctx->pc = 0x80061324u;
    // 80061324: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061328:
    ctx->pc = 0x80061328u;
    // 80061328: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006132C:
    ctx->pc = 0x8006132Cu;
    // 8006132C: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061330:
    ctx->pc = 0x80061330u;
    // 80061330: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061334:
    ctx->pc = 0x80061334u;
    // 80061334: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061338:
    ctx->pc = 0x80061338u;
    // 80061338: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006133C:
    ctx->pc = 0x8006133Cu;
    // 8006133C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061340:
    ctx->pc = 0x80061340u;
    // 80061340: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061344:
    ctx->pc = 0x80061344u;
    // 80061344: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061348:
    ctx->pc = 0x80061348u;
    // 80061348: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006134C:
    ctx->pc = 0x8006134Cu;
    // 8006134C: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061350:
    ctx->pc = 0x80061350u;
    // 80061350: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061354:
    ctx->pc = 0x80061354u;
    // 80061354: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061358:
    ctx->pc = 0x80061358u;
    // 80061358: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006135C:
    ctx->pc = 0x8006135Cu;
    // 8006135C: bl      0x801698F0
    {
            ctx->lr = 0x80061360u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061360:
    ctx->pc = 0x80061360u;
    ctx->downcount -= 34;
    // 80061360: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061364:
    ctx->pc = 0x80061364u;
    // 80061364: lis     r0, 7
    ctx->gpr[0] = ((u32)(s32)(7) << 16);

label_80061368:
    ctx->pc = 0x80061368u;
    // 80061368: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006136C:
    ctx->pc = 0x8006136Cu;
    // 8006136C: ori     r0, r0, 0x0021
    ctx->gpr[0] = ctx->gpr[0] | 0x0021u;

label_80061370:
    ctx->pc = 0x80061370u;
    // 80061370: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80061374:
    ctx->pc = 0x80061374u;
    // 80061374: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061378:
    ctx->pc = 0x80061378u;
    // 80061378: lwz     r26, 800(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(800);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_8006137C:
    ctx->pc = 0x8006137Cu;
    // 8006137C: addi    r10, r9, 31156
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(31156);

label_80061380:
    ctx->pc = 0x80061380u;
    // 80061380: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061384:
    ctx->pc = 0x80061384u;
    // 80061384: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061388:
    ctx->pc = 0x80061388u;
    // 80061388: lwz     r0, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006138C:
    ctx->pc = 0x8006138Cu;
    // 8006138C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061390:
    ctx->pc = 0x80061390u;
    // 80061390: lwz     r6, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80061394:
    ctx->pc = 0x80061394u;
    // 80061394: lwz     r7, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061398:
    ctx->pc = 0x80061398u;
    // 80061398: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006139C:
    ctx->pc = 0x8006139Cu;
    // 8006139C: lwz     r8, 31156(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31156);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800613A0:
    ctx->pc = 0x800613A0u;
    // 800613A0: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800613A4:
    ctx->pc = 0x800613A4u;
    // 800613A4: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800613A8:
    ctx->pc = 0x800613A8u;
    // 800613A8: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800613AC:
    ctx->pc = 0x800613ACu;
    // 800613AC: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800613B0:
    ctx->pc = 0x800613B0u;
    // 800613B0: stw     r26, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_800613B4:
    ctx->pc = 0x800613B4u;
    // 800613B4: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_800613B8:
    ctx->pc = 0x800613B8u;
    // 800613B8: lwz     r7, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800613BC:
    ctx->pc = 0x800613BCu;
    // 800613BC: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800613C0:
    ctx->pc = 0x800613C0u;
    // 800613C0: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800613C4:
    ctx->pc = 0x800613C4u;
    // 800613C4: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800613C8:
    ctx->pc = 0x800613C8u;
    // 800613C8: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800613CC:
    ctx->pc = 0x800613CCu;
    // 800613CC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800613D0:
    ctx->pc = 0x800613D0u;
    // 800613D0: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800613D4:
    ctx->pc = 0x800613D4u;
    // 800613D4: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800613D8:
    ctx->pc = 0x800613D8u;
    // 800613D8: stw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_800613DC:
    ctx->pc = 0x800613DCu;
    // 800613DC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800613E0:
    ctx->pc = 0x800613E0u;
    // 800613E0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800613E4:
    ctx->pc = 0x800613E4u;
    // 800613E4: bl      0x801698F0
    {
            ctx->lr = 0x800613E8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800613E8:
    ctx->pc = 0x800613E8u;
    ctx->downcount -= 25;
    // 800613E8: lis     r0, 7
    ctx->gpr[0] = ((u32)(s32)(7) << 16);

label_800613EC:
    ctx->pc = 0x800613ECu;
    // 800613EC: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_800613F0:
    ctx->pc = 0x800613F0u;
    // 800613F0: ori     r0, r0, 0x0019
    ctx->gpr[0] = ctx->gpr[0] | 0x0019u;

label_800613F4:
    ctx->pc = 0x800613F4u;
    // 800613F4: addi    r9, r9, 9156
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9156);

label_800613F8:
    ctx->pc = 0x800613F8u;
    // 800613F8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800613FC:
    ctx->pc = 0x800613FCu;
    // 800613FC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061400:
    ctx->pc = 0x80061400u;
    // 80061400: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80061404:
    ctx->pc = 0x80061404u;
    // 80061404: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061408:
    ctx->pc = 0x80061408u;
    // 80061408: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006140C:
    ctx->pc = 0x8006140Cu;
    // 8006140C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061410:
    ctx->pc = 0x80061410u;
    // 80061410: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061414:
    ctx->pc = 0x80061414u;
    // 80061414: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061418:
    ctx->pc = 0x80061418u;
    // 80061418: lwz     r8, 608(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006141C:
    ctx->pc = 0x8006141Cu;
    // 8006141C: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061420:
    ctx->pc = 0x80061420u;
    // 80061420: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061424:
    ctx->pc = 0x80061424u;
    // 80061424: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061428:
    ctx->pc = 0x80061428u;
    // 80061428: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006142C:
    ctx->pc = 0x8006142Cu;
    // 8006142C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061430:
    ctx->pc = 0x80061430u;
    // 80061430: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061434:
    ctx->pc = 0x80061434u;
    // 80061434: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061438:
    ctx->pc = 0x80061438u;
    // 80061438: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006143C:
    ctx->pc = 0x8006143Cu;
    // 8006143C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061440:
    ctx->pc = 0x80061440u;
    // 80061440: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061444:
    ctx->pc = 0x80061444u;
    // 80061444: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061448:
    ctx->pc = 0x80061448u;
    // 80061448: bl      0x801698F0
    {
            ctx->lr = 0x8006144Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006144C:
    ctx->pc = 0x8006144Cu;
    ctx->downcount -= 23;
    // 8006144C: lis     r0, 7
    ctx->gpr[0] = ((u32)(s32)(7) << 16);

label_80061450:
    ctx->pc = 0x80061450u;
    // 80061450: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061454:
    ctx->pc = 0x80061454u;
    // 80061454: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_80061458:
    ctx->pc = 0x80061458u;
    // 80061458: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8006145C:
    ctx->pc = 0x8006145Cu;
    // 8006145C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061460:
    ctx->pc = 0x80061460u;
    // 80061460: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061464:
    ctx->pc = 0x80061464u;
    // 80061464: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061468:
    ctx->pc = 0x80061468u;
    // 80061468: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006146C:
    ctx->pc = 0x8006146Cu;
    // 8006146C: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061470:
    ctx->pc = 0x80061470u;
    // 80061470: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061474:
    ctx->pc = 0x80061474u;
    // 80061474: lwz     r8, 584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061478:
    ctx->pc = 0x80061478u;
    // 80061478: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006147C:
    ctx->pc = 0x8006147Cu;
    // 8006147C: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061480:
    ctx->pc = 0x80061480u;
    // 80061480: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061484:
    ctx->pc = 0x80061484u;
    // 80061484: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061488:
    ctx->pc = 0x80061488u;
    // 80061488: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006148C:
    ctx->pc = 0x8006148Cu;
    // 8006148C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061490:
    ctx->pc = 0x80061490u;
    // 80061490: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061494:
    ctx->pc = 0x80061494u;
    // 80061494: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061498:
    ctx->pc = 0x80061498u;
    // 80061498: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006149C:
    ctx->pc = 0x8006149Cu;
    // 8006149C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800614A0:
    ctx->pc = 0x800614A0u;
    // 800614A0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800614A4:
    ctx->pc = 0x800614A4u;
    // 800614A4: bl      0x801698F0
    {
            ctx->lr = 0x800614A8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800614A8:
    ctx->pc = 0x800614A8u;
    ctx->downcount -= 21;
    // 800614A8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800614AC:
    ctx->pc = 0x800614ACu;
    // 800614AC: lis     r0, 7
    ctx->gpr[0] = ((u32)(s32)(7) << 16);

label_800614B0:
    ctx->pc = 0x800614B0u;
    // 800614B0: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800614B4:
    ctx->pc = 0x800614B4u;
    // 800614B4: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_800614B8:
    ctx->pc = 0x800614B8u;
    // 800614B8: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_800614BC:
    ctx->pc = 0x800614BCu;
    // 800614BC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800614C0:
    ctx->pc = 0x800614C0u;
    // 800614C0: lwz     r8, 152(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(152);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800614C4:
    ctx->pc = 0x800614C4u;
    // 800614C4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800614C8:
    ctx->pc = 0x800614C8u;
    // 800614C8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800614CC:
    ctx->pc = 0x800614CCu;
    // 800614CC: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800614D0:
    ctx->pc = 0x800614D0u;
    // 800614D0: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800614D4:
    ctx->pc = 0x800614D4u;
    // 800614D4: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800614D8:
    ctx->pc = 0x800614D8u;
    // 800614D8: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800614DC:
    ctx->pc = 0x800614DCu;
    // 800614DC: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800614E0:
    ctx->pc = 0x800614E0u;
    // 800614E0: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800614E4:
    ctx->pc = 0x800614E4u;
    // 800614E4: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800614E8:
    ctx->pc = 0x800614E8u;
    // 800614E8: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800614EC:
    ctx->pc = 0x800614ECu;
    // 800614EC: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800614F0:
    ctx->pc = 0x800614F0u;
    // 800614F0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800614F4:
    ctx->pc = 0x800614F4u;
    // 800614F4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800614F8:
    ctx->pc = 0x800614F8u;
    // 800614F8: bl      0x801698F0
    {
            ctx->lr = 0x800614FCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800614FC:
    ctx->pc = 0x800614FCu;
    ctx->downcount -= 19;
    // 800614FC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80061500:
    ctx->pc = 0x80061500u;
    // 80061500: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80061504:
    ctx->pc = 0x80061504u;
    // 80061504: lwz     r7, 31176(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31176);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061508:
    ctx->pc = 0x80061508u;
    // 80061508: addi    r30, r8, 14200
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(14200);

label_8006150C:
    ctx->pc = 0x8006150Cu;
    // 8006150C: addi    r9, r9, 31176
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31176);

label_80061510:
    ctx->pc = 0x80061510u;
    // 80061510: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061514:
    ctx->pc = 0x80061514u;
    // 80061514: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80061518:
    ctx->pc = 0x80061518u;
    // 80061518: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006151C:
    ctx->pc = 0x8006151Cu;
    // 8006151C: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061520:
    ctx->pc = 0x80061520u;
    // 80061520: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061524:
    ctx->pc = 0x80061524u;
    // 80061524: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061528:
    ctx->pc = 0x80061528u;
    // 80061528: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006152C:
    ctx->pc = 0x8006152Cu;
    // 8006152C: stw     r7, 14200(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(14200);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80061530:
    ctx->pc = 0x80061530u;
    // 80061530: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80061534:
    ctx->pc = 0x80061534u;
    // 80061534: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061538:
    ctx->pc = 0x80061538u;
    // 80061538: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006153C:
    ctx->pc = 0x8006153Cu;
    // 8006153C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061540:
    ctx->pc = 0x80061540u;
    // 80061540: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061544:
    ctx->pc = 0x80061544u;
    // 80061544: bl      0x801698F0
    {
            ctx->lr = 0x80061548u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061548:
    ctx->pc = 0x80061548u;
    ctx->downcount -= 23;
    // 80061548: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006154C:
    ctx->pc = 0x8006154Cu;
    // 8006154C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061550:
    ctx->pc = 0x80061550u;
    // 80061550: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_80061554:
    ctx->pc = 0x80061554u;
    // 80061554: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061558:
    ctx->pc = 0x80061558u;
    // 80061558: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_8006155C:
    ctx->pc = 0x8006155Cu;
    // 8006155C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061560:
    ctx->pc = 0x80061560u;
    // 80061560: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061564:
    ctx->pc = 0x80061564u;
    // 80061564: lwz     r8, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061568:
    ctx->pc = 0x80061568u;
    // 80061568: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8006156C:
    ctx->pc = 0x8006156Cu;
    // 8006156C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061570:
    ctx->pc = 0x80061570u;
    // 80061570: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061574:
    ctx->pc = 0x80061574u;
    // 80061574: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061578:
    ctx->pc = 0x80061578u;
    // 80061578: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006157C:
    ctx->pc = 0x8006157Cu;
    // 8006157C: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061580:
    ctx->pc = 0x80061580u;
    // 80061580: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061584:
    ctx->pc = 0x80061584u;
    // 80061584: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061588:
    ctx->pc = 0x80061588u;
    // 80061588: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006158C:
    ctx->pc = 0x8006158Cu;
    // 8006158C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061590:
    ctx->pc = 0x80061590u;
    // 80061590: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061594:
    ctx->pc = 0x80061594u;
    // 80061594: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061598:
    ctx->pc = 0x80061598u;
    // 80061598: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006159C:
    ctx->pc = 0x8006159Cu;
    // 8006159C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800615A0:
    ctx->pc = 0x800615A0u;
    // 800615A0: bl      0x801698F0
    {
            ctx->lr = 0x800615A4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800615A4:
    ctx->pc = 0x800615A4u;
    ctx->downcount -= 22;
    // 800615A4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800615A8:
    ctx->pc = 0x800615A8u;
    // 800615A8: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_800615AC:
    ctx->pc = 0x800615ACu;
    // 800615AC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800615B0:
    ctx->pc = 0x800615B0u;
    // 800615B0: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_800615B4:
    ctx->pc = 0x800615B4u;
    // 800615B4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800615B8:
    ctx->pc = 0x800615B8u;
    // 800615B8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800615BC:
    ctx->pc = 0x800615BCu;
    // 800615BC: lwz     r8, 656(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(656);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800615C0:
    ctx->pc = 0x800615C0u;
    // 800615C0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800615C4:
    ctx->pc = 0x800615C4u;
    // 800615C4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800615C8:
    ctx->pc = 0x800615C8u;
    // 800615C8: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800615CC:
    ctx->pc = 0x800615CCu;
    // 800615CC: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800615D0:
    ctx->pc = 0x800615D0u;
    // 800615D0: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800615D4:
    ctx->pc = 0x800615D4u;
    // 800615D4: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800615D8:
    ctx->pc = 0x800615D8u;
    // 800615D8: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800615DC:
    ctx->pc = 0x800615DCu;
    // 800615DC: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800615E0:
    ctx->pc = 0x800615E0u;
    // 800615E0: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800615E4:
    ctx->pc = 0x800615E4u;
    // 800615E4: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800615E8:
    ctx->pc = 0x800615E8u;
    // 800615E8: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800615EC:
    ctx->pc = 0x800615ECu;
    // 800615EC: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800615F0:
    ctx->pc = 0x800615F0u;
    // 800615F0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800615F4:
    ctx->pc = 0x800615F4u;
    // 800615F4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800615F8:
    ctx->pc = 0x800615F8u;
    // 800615F8: bl      0x801698F0
    {
            ctx->lr = 0x800615FCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800615FC:
    ctx->pc = 0x800615FCu;
    ctx->downcount -= 22;
    // 800615FC: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061600:
    ctx->pc = 0x80061600u;
    // 80061600: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_80061604:
    ctx->pc = 0x80061604u;
    // 80061604: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061608:
    ctx->pc = 0x80061608u;
    // 80061608: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_8006160C:
    ctx->pc = 0x8006160Cu;
    // 8006160C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061610:
    ctx->pc = 0x80061610u;
    // 80061610: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061614:
    ctx->pc = 0x80061614u;
    // 80061614: lwz     r8, 704(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061618:
    ctx->pc = 0x80061618u;
    // 80061618: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_8006161C:
    ctx->pc = 0x8006161Cu;
    // 8006161C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061620:
    ctx->pc = 0x80061620u;
    // 80061620: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061624:
    ctx->pc = 0x80061624u;
    // 80061624: lwz     r11, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061628:
    ctx->pc = 0x80061628u;
    // 80061628: lwz     r0, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006162C:
    ctx->pc = 0x8006162Cu;
    // 8006162C: lwz     r9, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061630:
    ctx->pc = 0x80061630u;
    // 80061630: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061634:
    ctx->pc = 0x80061634u;
    // 80061634: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061638:
    ctx->pc = 0x80061638u;
    // 80061638: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006163C:
    ctx->pc = 0x8006163Cu;
    // 8006163C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061640:
    ctx->pc = 0x80061640u;
    // 80061640: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061644:
    ctx->pc = 0x80061644u;
    // 80061644: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061648:
    ctx->pc = 0x80061648u;
    // 80061648: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006164C:
    ctx->pc = 0x8006164Cu;
    // 8006164C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061650:
    ctx->pc = 0x80061650u;
    // 80061650: bl      0x801698F0
    {
            ctx->lr = 0x80061654u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061654:
    ctx->pc = 0x80061654u;
    ctx->downcount -= 34;
    // 80061654: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061658:
    ctx->pc = 0x80061658u;
    // 80061658: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_8006165C:
    ctx->pc = 0x8006165Cu;
    // 8006165C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061660:
    ctx->pc = 0x80061660u;
    // 80061660: ori     r0, r0, 0x0022
    ctx->gpr[0] = ctx->gpr[0] | 0x0022u;

label_80061664:
    ctx->pc = 0x80061664u;
    // 80061664: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80061668:
    ctx->pc = 0x80061668u;
    // 80061668: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006166C:
    ctx->pc = 0x8006166Cu;
    // 8006166C: lwz     r26, 824(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(824);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_80061670:
    ctx->pc = 0x80061670u;
    // 80061670: addi    r10, r9, 31196
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(31196);

label_80061674:
    ctx->pc = 0x80061674u;
    // 80061674: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061678:
    ctx->pc = 0x80061678u;
    // 80061678: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006167C:
    ctx->pc = 0x8006167Cu;
    // 8006167C: lwz     r0, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061680:
    ctx->pc = 0x80061680u;
    // 80061680: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061684:
    ctx->pc = 0x80061684u;
    // 80061684: lwz     r6, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80061688:
    ctx->pc = 0x80061688u;
    // 80061688: lwz     r7, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8006168C:
    ctx->pc = 0x8006168Cu;
    // 8006168C: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061690:
    ctx->pc = 0x80061690u;
    // 80061690: lwz     r8, 31196(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31196);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061694:
    ctx->pc = 0x80061694u;
    // 80061694: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80061698:
    ctx->pc = 0x80061698u;
    // 80061698: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8006169C:
    ctx->pc = 0x8006169Cu;
    // 8006169C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800616A0:
    ctx->pc = 0x800616A0u;
    // 800616A0: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800616A4:
    ctx->pc = 0x800616A4u;
    // 800616A4: stw     r26, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_800616A8:
    ctx->pc = 0x800616A8u;
    // 800616A8: lwz     r7, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800616AC:
    ctx->pc = 0x800616ACu;
    // 800616AC: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_800616B0:
    ctx->pc = 0x800616B0u;
    // 800616B0: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800616B4:
    ctx->pc = 0x800616B4u;
    // 800616B4: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800616B8:
    ctx->pc = 0x800616B8u;
    // 800616B8: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800616BC:
    ctx->pc = 0x800616BCu;
    // 800616BC: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800616C0:
    ctx->pc = 0x800616C0u;
    // 800616C0: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800616C4:
    ctx->pc = 0x800616C4u;
    // 800616C4: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800616C8:
    ctx->pc = 0x800616C8u;
    // 800616C8: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800616CC:
    ctx->pc = 0x800616CCu;
    // 800616CC: stw     r26, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_800616D0:
    ctx->pc = 0x800616D0u;
    // 800616D0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800616D4:
    ctx->pc = 0x800616D4u;
    // 800616D4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800616D8:
    ctx->pc = 0x800616D8u;
    // 800616D8: bl      0x801698F0
    {
            ctx->lr = 0x800616DCu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800616DC:
    ctx->pc = 0x800616DCu;
    ctx->downcount -= 23;
    // 800616DC: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_800616E0:
    ctx->pc = 0x800616E0u;
    // 800616E0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800616E4:
    ctx->pc = 0x800616E4u;
    // 800616E4: ori     r0, r0, 0x0014
    ctx->gpr[0] = ctx->gpr[0] | 0x0014u;

label_800616E8:
    ctx->pc = 0x800616E8u;
    // 800616E8: stw     r22, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_800616EC:
    ctx->pc = 0x800616ECu;
    // 800616EC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800616F0:
    ctx->pc = 0x800616F0u;
    // 800616F0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800616F4:
    ctx->pc = 0x800616F4u;
    // 800616F4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800616F8:
    ctx->pc = 0x800616F8u;
    // 800616F8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800616FC:
    ctx->pc = 0x800616FCu;
    // 800616FC: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061700:
    ctx->pc = 0x80061700u;
    // 80061700: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061704:
    ctx->pc = 0x80061704u;
    // 80061704: lwz     r8, 488(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(488);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061708:
    ctx->pc = 0x80061708u;
    // 80061708: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006170C:
    ctx->pc = 0x8006170Cu;
    // 8006170C: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061710:
    ctx->pc = 0x80061710u;
    // 80061710: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061714:
    ctx->pc = 0x80061714u;
    // 80061714: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061718:
    ctx->pc = 0x80061718u;
    // 80061718: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006171C:
    ctx->pc = 0x8006171Cu;
    // 8006171C: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061720:
    ctx->pc = 0x80061720u;
    // 80061720: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061724:
    ctx->pc = 0x80061724u;
    // 80061724: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061728:
    ctx->pc = 0x80061728u;
    // 80061728: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006172C:
    ctx->pc = 0x8006172Cu;
    // 8006172C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061730:
    ctx->pc = 0x80061730u;
    // 80061730: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061734:
    ctx->pc = 0x80061734u;
    // 80061734: bl      0x801698F0
    {
            ctx->lr = 0x80061738u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061738:
    ctx->pc = 0x80061738u;
    ctx->downcount -= 23;
    // 80061738: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_8006173C:
    ctx->pc = 0x8006173Cu;
    // 8006173C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061740:
    ctx->pc = 0x80061740u;
    // 80061740: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_80061744:
    ctx->pc = 0x80061744u;
    // 80061744: stw     r31, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80061748:
    ctx->pc = 0x80061748u;
    // 80061748: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006174C:
    ctx->pc = 0x8006174Cu;
    // 8006174C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061750:
    ctx->pc = 0x80061750u;
    // 80061750: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061754:
    ctx->pc = 0x80061754u;
    // 80061754: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061758:
    ctx->pc = 0x80061758u;
    // 80061758: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006175C:
    ctx->pc = 0x8006175Cu;
    // 8006175C: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_80061760:
    ctx->pc = 0x80061760u;
    // 80061760: lwz     r8, 584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061764:
    ctx->pc = 0x80061764u;
    // 80061764: lwz     r10, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061768:
    ctx->pc = 0x80061768u;
    // 80061768: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006176C:
    ctx->pc = 0x8006176Cu;
    // 8006176C: lwz     r11, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061770:
    ctx->pc = 0x80061770u;
    // 80061770: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061774:
    ctx->pc = 0x80061774u;
    // 80061774: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061778:
    ctx->pc = 0x80061778u;
    // 80061778: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006177C:
    ctx->pc = 0x8006177Cu;
    // 8006177C: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061780:
    ctx->pc = 0x80061780u;
    // 80061780: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061784:
    ctx->pc = 0x80061784u;
    // 80061784: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061788:
    ctx->pc = 0x80061788u;
    // 80061788: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006178C:
    ctx->pc = 0x8006178Cu;
    // 8006178C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061790:
    ctx->pc = 0x80061790u;
    // 80061790: bl      0x801698F0
    {
            ctx->lr = 0x80061794u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061794:
    ctx->pc = 0x80061794u;
    ctx->downcount -= 25;
    // 80061794: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_80061798:
    ctx->pc = 0x80061798u;
    // 80061798: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_8006179C:
    ctx->pc = 0x8006179Cu;
    // 8006179C: ori     r0, r0, 0x0016
    ctx->gpr[0] = ctx->gpr[0] | 0x0016u;

label_800617A0:
    ctx->pc = 0x800617A0u;
    // 800617A0: addi    r9, r9, 8516
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8516);

label_800617A4:
    ctx->pc = 0x800617A4u;
    // 800617A4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800617A8:
    ctx->pc = 0x800617A8u;
    // 800617A8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800617AC:
    ctx->pc = 0x800617ACu;
    // 800617AC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_800617B0:
    ctx->pc = 0x800617B0u;
    // 800617B0: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800617B4:
    ctx->pc = 0x800617B4u;
    // 800617B4: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800617B8:
    ctx->pc = 0x800617B8u;
    // 800617B8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800617BC:
    ctx->pc = 0x800617BCu;
    // 800617BC: lwz     r0, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800617C0:
    ctx->pc = 0x800617C0u;
    // 800617C0: or   r3, r28, r28
    {
        ctx->gpr[3] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800617C4:
    ctx->pc = 0x800617C4u;
    // 800617C4: lwz     r8, 536(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(536);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800617C8:
    ctx->pc = 0x800617C8u;
    // 800617C8: lwz     r9, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800617CC:
    ctx->pc = 0x800617CCu;
    // 800617CC: lwz     r11, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800617D0:
    ctx->pc = 0x800617D0u;
    // 800617D0: lwz     r10, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800617D4:
    ctx->pc = 0x800617D4u;
    // 800617D4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800617D8:
    ctx->pc = 0x800617D8u;
    // 800617D8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800617DC:
    ctx->pc = 0x800617DCu;
    // 800617DC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800617E0:
    ctx->pc = 0x800617E0u;
    // 800617E0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800617E4:
    ctx->pc = 0x800617E4u;
    // 800617E4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800617E8:
    ctx->pc = 0x800617E8u;
    // 800617E8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800617EC:
    ctx->pc = 0x800617ECu;
    // 800617EC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800617F0:
    ctx->pc = 0x800617F0u;
    // 800617F0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800617F4:
    ctx->pc = 0x800617F4u;
    // 800617F4: bl      0x801698F0
    {
            ctx->lr = 0x800617F8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800617F8:
    ctx->pc = 0x800617F8u;
    ctx->downcount -= 22;
    // 800617F8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800617FC:
    ctx->pc = 0x800617FCu;
    // 800617FC: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_80061800:
    ctx->pc = 0x80061800u;
    // 80061800: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061804:
    ctx->pc = 0x80061804u;
    // 80061804: ori     r0, r0, 0x0003
    ctx->gpr[0] = ctx->gpr[0] | 0x0003u;

label_80061808:
    ctx->pc = 0x80061808u;
    // 80061808: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006180C:
    ctx->pc = 0x8006180Cu;
    // 8006180C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061810:
    ctx->pc = 0x80061810u;
    // 80061810: lwz     r8, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061814:
    ctx->pc = 0x80061814u;
    // 80061814: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061818:
    ctx->pc = 0x80061818u;
    // 80061818: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006181C:
    ctx->pc = 0x8006181Cu;
    // 8006181C: lwz     r0, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061820:
    ctx->pc = 0x80061820u;
    // 80061820: lwz     r10, 80(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(80);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061824:
    ctx->pc = 0x80061824u;
    // 80061824: lwz     r11, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061828:
    ctx->pc = 0x80061828u;
    // 80061828: lwz     r9, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006182C:
    ctx->pc = 0x8006182Cu;
    // 8006182C: stw     r10, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061830:
    ctx->pc = 0x80061830u;
    // 80061830: stw     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061834:
    ctx->pc = 0x80061834u;
    // 80061834: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061838:
    ctx->pc = 0x80061838u;
    // 80061838: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006183C:
    ctx->pc = 0x8006183Cu;
    // 8006183C: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061840:
    ctx->pc = 0x80061840u;
    // 80061840: stw     r10, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061844:
    ctx->pc = 0x80061844u;
    // 80061844: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061848:
    ctx->pc = 0x80061848u;
    // 80061848: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006184C:
    ctx->pc = 0x8006184Cu;
    // 8006184C: bl      0x801698F0
    {
            ctx->lr = 0x80061850u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061850:
    ctx->pc = 0x80061850u;
    ctx->downcount -= 21;
    // 80061850: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061854:
    ctx->pc = 0x80061854u;
    // 80061854: lis     r0, 8
    ctx->gpr[0] = ((u32)(s32)(8) << 16);

label_80061858:
    ctx->pc = 0x80061858u;
    // 80061858: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006185C:
    ctx->pc = 0x8006185Cu;
    // 8006185C: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_80061860:
    ctx->pc = 0x80061860u;
    // 80061860: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80061864:
    ctx->pc = 0x80061864u;
    // 80061864: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061868:
    ctx->pc = 0x80061868u;
    // 80061868: lwz     r8, 152(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(152);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006186C:
    ctx->pc = 0x8006186Cu;
    // 8006186C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061870:
    ctx->pc = 0x80061870u;
    // 80061870: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061874:
    ctx->pc = 0x80061874u;
    // 80061874: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061878:
    ctx->pc = 0x80061878u;
    // 80061878: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006187C:
    ctx->pc = 0x8006187Cu;
    // 8006187C: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061880:
    ctx->pc = 0x80061880u;
    // 80061880: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061884:
    ctx->pc = 0x80061884u;
    // 80061884: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061888:
    ctx->pc = 0x80061888u;
    // 80061888: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006188C:
    ctx->pc = 0x8006188Cu;
    // 8006188C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061890:
    ctx->pc = 0x80061890u;
    // 80061890: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061894:
    ctx->pc = 0x80061894u;
    // 80061894: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061898:
    ctx->pc = 0x80061898u;
    // 80061898: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006189C:
    ctx->pc = 0x8006189Cu;
    // 8006189C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800618A0:
    ctx->pc = 0x800618A0u;
    // 800618A0: bl      0x801698F0
    {
            ctx->lr = 0x800618A4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800618A4:
    ctx->pc = 0x800618A4u;
    ctx->downcount -= 19;
    // 800618A4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800618A8:
    ctx->pc = 0x800618A8u;
    // 800618A8: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_800618AC:
    ctx->pc = 0x800618ACu;
    // 800618AC: lwz     r7, 31216(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31216);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800618B0:
    ctx->pc = 0x800618B0u;
    // 800618B0: addi    r30, r8, 14440
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(14440);

label_800618B4:
    ctx->pc = 0x800618B4u;
    // 800618B4: addi    r9, r9, 31216
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31216);

label_800618B8:
    ctx->pc = 0x800618B8u;
    // 800618B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800618BC:
    ctx->pc = 0x800618BCu;
    // 800618BC: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800618C0:
    ctx->pc = 0x800618C0u;
    // 800618C0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800618C4:
    ctx->pc = 0x800618C4u;
    // 800618C4: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800618C8:
    ctx->pc = 0x800618C8u;
    // 800618C8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800618CC:
    ctx->pc = 0x800618CCu;
    // 800618CC: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800618D0:
    ctx->pc = 0x800618D0u;
    // 800618D0: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800618D4:
    ctx->pc = 0x800618D4u;
    // 800618D4: stw     r7, 14440(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(14440);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800618D8:
    ctx->pc = 0x800618D8u;
    // 800618D8: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800618DC:
    ctx->pc = 0x800618DCu;
    // 800618DC: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800618E0:
    ctx->pc = 0x800618E0u;
    // 800618E0: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800618E4:
    ctx->pc = 0x800618E4u;
    // 800618E4: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800618E8:
    ctx->pc = 0x800618E8u;
    // 800618E8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800618EC:
    ctx->pc = 0x800618ECu;
    // 800618EC: bl      0x801698F0
    {
            ctx->lr = 0x800618F0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800618F0:
    ctx->pc = 0x800618F0u;
    ctx->downcount -= 23;
    // 800618F0: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800618F4:
    ctx->pc = 0x800618F4u;
    // 800618F4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800618F8:
    ctx->pc = 0x800618F8u;
    // 800618F8: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_800618FC:
    ctx->pc = 0x800618FCu;
    // 800618FC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061900:
    ctx->pc = 0x80061900u;
    // 80061900: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80061904:
    ctx->pc = 0x80061904u;
    // 80061904: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061908:
    ctx->pc = 0x80061908u;
    // 80061908: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006190C:
    ctx->pc = 0x8006190Cu;
    // 8006190C: lwz     r8, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061910:
    ctx->pc = 0x80061910u;
    // 80061910: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061914:
    ctx->pc = 0x80061914u;
    // 80061914: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061918:
    ctx->pc = 0x80061918u;
    // 80061918: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006191C:
    ctx->pc = 0x8006191Cu;
    // 8006191C: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061920:
    ctx->pc = 0x80061920u;
    // 80061920: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061924:
    ctx->pc = 0x80061924u;
    // 80061924: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061928:
    ctx->pc = 0x80061928u;
    // 80061928: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006192C:
    ctx->pc = 0x8006192Cu;
    // 8006192C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061930:
    ctx->pc = 0x80061930u;
    // 80061930: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061934:
    ctx->pc = 0x80061934u;
    // 80061934: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061938:
    ctx->pc = 0x80061938u;
    // 80061938: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006193C:
    ctx->pc = 0x8006193Cu;
    // 8006193C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061940:
    ctx->pc = 0x80061940u;
    // 80061940: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061944:
    ctx->pc = 0x80061944u;
    // 80061944: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061948:
    ctx->pc = 0x80061948u;
    // 80061948: bl      0x801698F0
    {
            ctx->lr = 0x8006194Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006194C:
    ctx->pc = 0x8006194Cu;
    ctx->downcount -= 22;
    // 8006194C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061950:
    ctx->pc = 0x80061950u;
    // 80061950: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_80061954:
    ctx->pc = 0x80061954u;
    // 80061954: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061958:
    ctx->pc = 0x80061958u;
    // 80061958: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_8006195C:
    ctx->pc = 0x8006195Cu;
    // 8006195C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061960:
    ctx->pc = 0x80061960u;
    // 80061960: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061964:
    ctx->pc = 0x80061964u;
    // 80061964: lwz     r8, 704(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061968:
    ctx->pc = 0x80061968u;
    // 80061968: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8006196C:
    ctx->pc = 0x8006196Cu;
    // 8006196C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061970:
    ctx->pc = 0x80061970u;
    // 80061970: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061974:
    ctx->pc = 0x80061974u;
    // 80061974: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061978:
    ctx->pc = 0x80061978u;
    // 80061978: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006197C:
    ctx->pc = 0x8006197Cu;
    // 8006197C: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061980:
    ctx->pc = 0x80061980u;
    // 80061980: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061984:
    ctx->pc = 0x80061984u;
    // 80061984: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061988:
    ctx->pc = 0x80061988u;
    // 80061988: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006198C:
    ctx->pc = 0x8006198Cu;
    // 8006198C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061990:
    ctx->pc = 0x80061990u;
    // 80061990: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061994:
    ctx->pc = 0x80061994u;
    // 80061994: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061998:
    ctx->pc = 0x80061998u;
    // 80061998: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006199C:
    ctx->pc = 0x8006199Cu;
    // 8006199C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800619A0:
    ctx->pc = 0x800619A0u;
    // 800619A0: bl      0x801698F0
    {
            ctx->lr = 0x800619A4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800619A4:
    ctx->pc = 0x800619A4u;
    ctx->downcount -= 34;
    // 800619A4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800619A8:
    ctx->pc = 0x800619A8u;
    // 800619A8: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_800619AC:
    ctx->pc = 0x800619ACu;
    // 800619AC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800619B0:
    ctx->pc = 0x800619B0u;
    // 800619B0: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_800619B4:
    ctx->pc = 0x800619B4u;
    // 800619B4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800619B8:
    ctx->pc = 0x800619B8u;
    // 800619B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800619BC:
    ctx->pc = 0x800619BCu;
    // 800619BC: lwz     r28, 656(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(656);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_800619C0:
    ctx->pc = 0x800619C0u;
    // 800619C0: addi    r10, r9, 31236
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(31236);

label_800619C4:
    ctx->pc = 0x800619C4u;
    // 800619C4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800619C8:
    ctx->pc = 0x800619C8u;
    // 800619C8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800619CC:
    ctx->pc = 0x800619CCu;
    // 800619CC: lwz     r0, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800619D0:
    ctx->pc = 0x800619D0u;
    // 800619D0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800619D4:
    ctx->pc = 0x800619D4u;
    // 800619D4: lwz     r6, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800619D8:
    ctx->pc = 0x800619D8u;
    // 800619D8: lwz     r7, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800619DC:
    ctx->pc = 0x800619DCu;
    // 800619DC: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800619E0:
    ctx->pc = 0x800619E0u;
    // 800619E0: lwz     r8, 31236(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31236);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800619E4:
    ctx->pc = 0x800619E4u;
    // 800619E4: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800619E8:
    ctx->pc = 0x800619E8u;
    // 800619E8: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800619EC:
    ctx->pc = 0x800619ECu;
    // 800619EC: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800619F0:
    ctx->pc = 0x800619F0u;
    // 800619F0: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800619F4:
    ctx->pc = 0x800619F4u;
    // 800619F4: stw     r28, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_800619F8:
    ctx->pc = 0x800619F8u;
    // 800619F8: lwz     r7, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800619FC:
    ctx->pc = 0x800619FCu;
    // 800619FC: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80061A00:
    ctx->pc = 0x80061A00u;
    // 80061A00: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061A04:
    ctx->pc = 0x80061A04u;
    // 80061A04: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061A08:
    ctx->pc = 0x80061A08u;
    // 80061A08: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061A0C:
    ctx->pc = 0x80061A0Cu;
    // 80061A0C: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80061A10:
    ctx->pc = 0x80061A10u;
    // 80061A10: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061A14:
    ctx->pc = 0x80061A14u;
    // 80061A14: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061A18:
    ctx->pc = 0x80061A18u;
    // 80061A18: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061A1C:
    ctx->pc = 0x80061A1Cu;
    // 80061A1C: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80061A20:
    ctx->pc = 0x80061A20u;
    // 80061A20: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061A24:
    ctx->pc = 0x80061A24u;
    // 80061A24: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061A28:
    ctx->pc = 0x80061A28u;
    // 80061A28: bl      0x801698F0
    {
            ctx->lr = 0x80061A2Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061A2C:
    ctx->pc = 0x80061A2Cu;
    ctx->downcount -= 24;
    // 80061A2C: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_80061A30:
    ctx->pc = 0x80061A30u;
    // 80061A30: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061A34:
    ctx->pc = 0x80061A34u;
    // 80061A34: ori     r0, r0, 0x0038
    ctx->gpr[0] = ctx->gpr[0] | 0x0038u;

label_80061A38:
    ctx->pc = 0x80061A38u;
    // 80061A38: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061A3C:
    ctx->pc = 0x80061A3Cu;
    // 80061A3C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061A40:
    ctx->pc = 0x80061A40u;
    // 80061A40: lis     r29, -32735
    ctx->gpr[29] = ((u32)(s32)(-32735) << 16);

label_80061A44:
    ctx->pc = 0x80061A44u;
    // 80061A44: addi    r29, r29, -2804
    ctx->gpr[29] = ctx->gpr[29] + (u32)(s32)(-2804);

label_80061A48:
    ctx->pc = 0x80061A48u;
    // 80061A48: lwz     r0, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061A4C:
    ctx->pc = 0x80061A4Cu;
    // 80061A4C: lwz     r8, 1352(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1352);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061A50:
    ctx->pc = 0x80061A50u;
    // 80061A50: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061A54:
    ctx->pc = 0x80061A54u;
    // 80061A54: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061A58:
    ctx->pc = 0x80061A58u;
    // 80061A58: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061A5C:
    ctx->pc = 0x80061A5Cu;
    // 80061A5C: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061A60:
    ctx->pc = 0x80061A60u;
    // 80061A60: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061A64:
    ctx->pc = 0x80061A64u;
    // 80061A64: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061A68:
    ctx->pc = 0x80061A68u;
    // 80061A68: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061A6C:
    ctx->pc = 0x80061A6Cu;
    // 80061A6C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061A70:
    ctx->pc = 0x80061A70u;
    // 80061A70: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061A74:
    ctx->pc = 0x80061A74u;
    // 80061A74: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061A78:
    ctx->pc = 0x80061A78u;
    // 80061A78: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061A7C:
    ctx->pc = 0x80061A7Cu;
    // 80061A7C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061A80:
    ctx->pc = 0x80061A80u;
    // 80061A80: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061A84:
    ctx->pc = 0x80061A84u;
    // 80061A84: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061A88:
    ctx->pc = 0x80061A88u;
    // 80061A88: bl      0x801698F0
    {
            ctx->lr = 0x80061A8Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061A8C:
    ctx->pc = 0x80061A8Cu;
    ctx->downcount -= 22;
    // 80061A8C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061A90:
    ctx->pc = 0x80061A90u;
    // 80061A90: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_80061A94:
    ctx->pc = 0x80061A94u;
    // 80061A94: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061A98:
    ctx->pc = 0x80061A98u;
    // 80061A98: ori     r0, r0, 0x0039
    ctx->gpr[0] = ctx->gpr[0] | 0x0039u;

label_80061A9C:
    ctx->pc = 0x80061A9Cu;
    // 80061A9C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061AA0:
    ctx->pc = 0x80061AA0u;
    // 80061AA0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061AA4:
    ctx->pc = 0x80061AA4u;
    // 80061AA4: lwz     r8, 1376(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1376);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061AA8:
    ctx->pc = 0x80061AA8u;
    // 80061AA8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061AAC:
    ctx->pc = 0x80061AACu;
    // 80061AAC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061AB0:
    ctx->pc = 0x80061AB0u;
    // 80061AB0: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061AB4:
    ctx->pc = 0x80061AB4u;
    // 80061AB4: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061AB8:
    ctx->pc = 0x80061AB8u;
    // 80061AB8: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061ABC:
    ctx->pc = 0x80061ABCu;
    // 80061ABC: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061AC0:
    ctx->pc = 0x80061AC0u;
    // 80061AC0: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061AC4:
    ctx->pc = 0x80061AC4u;
    // 80061AC4: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061AC8:
    ctx->pc = 0x80061AC8u;
    // 80061AC8: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061ACC:
    ctx->pc = 0x80061ACCu;
    // 80061ACC: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061AD0:
    ctx->pc = 0x80061AD0u;
    // 80061AD0: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061AD4:
    ctx->pc = 0x80061AD4u;
    // 80061AD4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061AD8:
    ctx->pc = 0x80061AD8u;
    // 80061AD8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061ADC:
    ctx->pc = 0x80061ADCu;
    // 80061ADC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061AE0:
    ctx->pc = 0x80061AE0u;
    // 80061AE0: bl      0x801698F0
    {
            ctx->lr = 0x80061AE4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061AE4:
    ctx->pc = 0x80061AE4u;
    ctx->downcount -= 22;
    // 80061AE4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061AE8:
    ctx->pc = 0x80061AE8u;
    // 80061AE8: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_80061AEC:
    ctx->pc = 0x80061AECu;
    // 80061AEC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061AF0:
    ctx->pc = 0x80061AF0u;
    // 80061AF0: ori     r0, r0, 0x0037
    ctx->gpr[0] = ctx->gpr[0] | 0x0037u;

label_80061AF4:
    ctx->pc = 0x80061AF4u;
    // 80061AF4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061AF8:
    ctx->pc = 0x80061AF8u;
    // 80061AF8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061AFC:
    ctx->pc = 0x80061AFCu;
    // 80061AFC: lwz     r8, 1328(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1328);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061B00:
    ctx->pc = 0x80061B00u;
    // 80061B00: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061B04:
    ctx->pc = 0x80061B04u;
    // 80061B04: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061B08:
    ctx->pc = 0x80061B08u;
    // 80061B08: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061B0C:
    ctx->pc = 0x80061B0Cu;
    // 80061B0C: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061B10:
    ctx->pc = 0x80061B10u;
    // 80061B10: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061B14:
    ctx->pc = 0x80061B14u;
    // 80061B14: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061B18:
    ctx->pc = 0x80061B18u;
    // 80061B18: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061B1C:
    ctx->pc = 0x80061B1Cu;
    // 80061B1C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061B20:
    ctx->pc = 0x80061B20u;
    // 80061B20: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061B24:
    ctx->pc = 0x80061B24u;
    // 80061B24: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061B28:
    ctx->pc = 0x80061B28u;
    // 80061B28: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061B2C:
    ctx->pc = 0x80061B2Cu;
    // 80061B2C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061B30:
    ctx->pc = 0x80061B30u;
    // 80061B30: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061B34:
    ctx->pc = 0x80061B34u;
    // 80061B34: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061B38:
    ctx->pc = 0x80061B38u;
    // 80061B38: bl      0x801698F0
    {
            ctx->lr = 0x80061B3Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061B3C:
    ctx->pc = 0x80061B3Cu;
    ctx->downcount -= 25;
    // 80061B3C: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_80061B40:
    ctx->pc = 0x80061B40u;
    // 80061B40: lis     r26, -32735
    ctx->gpr[26] = ((u32)(s32)(-32735) << 16);

label_80061B44:
    ctx->pc = 0x80061B44u;
    // 80061B44: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_80061B48:
    ctx->pc = 0x80061B48u;
    // 80061B48: addi    r26, r26, 8696
    ctx->gpr[26] = ctx->gpr[26] + (u32)(s32)(8696);

label_80061B4C:
    ctx->pc = 0x80061B4Cu;
    // 80061B4C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061B50:
    ctx->pc = 0x80061B50u;
    // 80061B50: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061B54:
    ctx->pc = 0x80061B54u;
    // 80061B54: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80061B58:
    ctx->pc = 0x80061B58u;
    // 80061B58: stw     r26, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80061B5C:
    ctx->pc = 0x80061B5Cu;
    // 80061B5C: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061B60:
    ctx->pc = 0x80061B60u;
    // 80061B60: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061B64:
    ctx->pc = 0x80061B64u;
    // 80061B64: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061B68:
    ctx->pc = 0x80061B68u;
    // 80061B68: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061B6C:
    ctx->pc = 0x80061B6Cu;
    // 80061B6C: lwz     r8, 584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061B70:
    ctx->pc = 0x80061B70u;
    // 80061B70: lwz     r9, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061B74:
    ctx->pc = 0x80061B74u;
    // 80061B74: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061B78:
    ctx->pc = 0x80061B78u;
    // 80061B78: lwz     r10, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061B7C:
    ctx->pc = 0x80061B7Cu;
    // 80061B7C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061B80:
    ctx->pc = 0x80061B80u;
    // 80061B80: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061B84:
    ctx->pc = 0x80061B84u;
    // 80061B84: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061B88:
    ctx->pc = 0x80061B88u;
    // 80061B88: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061B8C:
    ctx->pc = 0x80061B8Cu;
    // 80061B8C: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061B90:
    ctx->pc = 0x80061B90u;
    // 80061B90: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061B94:
    ctx->pc = 0x80061B94u;
    // 80061B94: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061B98:
    ctx->pc = 0x80061B98u;
    // 80061B98: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061B9C:
    ctx->pc = 0x80061B9Cu;
    // 80061B9C: bl      0x801698F0
    {
            ctx->lr = 0x80061BA0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061BA0:
    ctx->pc = 0x80061BA0u;
    ctx->downcount -= 21;
    // 80061BA0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061BA4:
    ctx->pc = 0x80061BA4u;
    // 80061BA4: lis     r0, 9
    ctx->gpr[0] = ((u32)(s32)(9) << 16);

label_80061BA8:
    ctx->pc = 0x80061BA8u;
    // 80061BA8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061BAC:
    ctx->pc = 0x80061BACu;
    // 80061BAC: ori     r0, r0, 0x0006
    ctx->gpr[0] = ctx->gpr[0] | 0x0006u;

label_80061BB0:
    ctx->pc = 0x80061BB0u;
    // 80061BB0: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80061BB4:
    ctx->pc = 0x80061BB4u;
    // 80061BB4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061BB8:
    ctx->pc = 0x80061BB8u;
    // 80061BB8: lwz     r8, 152(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(152);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061BBC:
    ctx->pc = 0x80061BBCu;
    // 80061BBC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061BC0:
    ctx->pc = 0x80061BC0u;
    // 80061BC0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061BC4:
    ctx->pc = 0x80061BC4u;
    // 80061BC4: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061BC8:
    ctx->pc = 0x80061BC8u;
    // 80061BC8: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061BCC:
    ctx->pc = 0x80061BCCu;
    // 80061BCC: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061BD0:
    ctx->pc = 0x80061BD0u;
    // 80061BD0: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061BD4:
    ctx->pc = 0x80061BD4u;
    // 80061BD4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061BD8:
    ctx->pc = 0x80061BD8u;
    // 80061BD8: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061BDC:
    ctx->pc = 0x80061BDCu;
    // 80061BDC: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061BE0:
    ctx->pc = 0x80061BE0u;
    // 80061BE0: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061BE4:
    ctx->pc = 0x80061BE4u;
    // 80061BE4: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061BE8:
    ctx->pc = 0x80061BE8u;
    // 80061BE8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061BEC:
    ctx->pc = 0x80061BECu;
    // 80061BEC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061BF0:
    ctx->pc = 0x80061BF0u;
    // 80061BF0: bl      0x801698F0
    {
            ctx->lr = 0x80061BF4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061BF4:
    ctx->pc = 0x80061BF4u;
    ctx->downcount -= 19;
    // 80061BF4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80061BF8:
    ctx->pc = 0x80061BF8u;
    // 80061BF8: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80061BFC:
    ctx->pc = 0x80061BFCu;
    // 80061BFC: lwz     r7, 31256(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31256);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061C00:
    ctx->pc = 0x80061C00u;
    // 80061C00: addi    r30, r8, 14660
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(14660);

label_80061C04:
    ctx->pc = 0x80061C04u;
    // 80061C04: addi    r9, r9, 31256
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31256);

label_80061C08:
    ctx->pc = 0x80061C08u;
    // 80061C08: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061C0C:
    ctx->pc = 0x80061C0Cu;
    // 80061C0C: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80061C10:
    ctx->pc = 0x80061C10u;
    // 80061C10: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061C14:
    ctx->pc = 0x80061C14u;
    // 80061C14: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061C18:
    ctx->pc = 0x80061C18u;
    // 80061C18: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061C1C:
    ctx->pc = 0x80061C1Cu;
    // 80061C1C: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061C20:
    ctx->pc = 0x80061C20u;
    // 80061C20: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061C24:
    ctx->pc = 0x80061C24u;
    // 80061C24: stw     r7, 14660(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(14660);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80061C28:
    ctx->pc = 0x80061C28u;
    // 80061C28: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80061C2C:
    ctx->pc = 0x80061C2Cu;
    // 80061C2C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061C30:
    ctx->pc = 0x80061C30u;
    // 80061C30: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061C34:
    ctx->pc = 0x80061C34u;
    // 80061C34: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061C38:
    ctx->pc = 0x80061C38u;
    // 80061C38: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061C3C:
    ctx->pc = 0x80061C3Cu;
    // 80061C3C: bl      0x801698F0
    {
            ctx->lr = 0x80061C40u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061C40:
    ctx->pc = 0x80061C40u;
    ctx->downcount -= 23;
    // 80061C40: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061C44:
    ctx->pc = 0x80061C44u;
    // 80061C44: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061C48:
    ctx->pc = 0x80061C48u;
    // 80061C48: lis     r0, 10
    ctx->gpr[0] = ((u32)(s32)(10) << 16);

label_80061C4C:
    ctx->pc = 0x80061C4Cu;
    // 80061C4C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061C50:
    ctx->pc = 0x80061C50u;
    // 80061C50: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80061C54:
    ctx->pc = 0x80061C54u;
    // 80061C54: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061C58:
    ctx->pc = 0x80061C58u;
    // 80061C58: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061C5C:
    ctx->pc = 0x80061C5Cu;
    // 80061C5C: lwz     r8, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061C60:
    ctx->pc = 0x80061C60u;
    // 80061C60: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061C64:
    ctx->pc = 0x80061C64u;
    // 80061C64: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061C68:
    ctx->pc = 0x80061C68u;
    // 80061C68: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061C6C:
    ctx->pc = 0x80061C6Cu;
    // 80061C6C: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061C70:
    ctx->pc = 0x80061C70u;
    // 80061C70: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061C74:
    ctx->pc = 0x80061C74u;
    // 80061C74: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061C78:
    ctx->pc = 0x80061C78u;
    // 80061C78: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061C7C:
    ctx->pc = 0x80061C7Cu;
    // 80061C7C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061C80:
    ctx->pc = 0x80061C80u;
    // 80061C80: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061C84:
    ctx->pc = 0x80061C84u;
    // 80061C84: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061C88:
    ctx->pc = 0x80061C88u;
    // 80061C88: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061C8C:
    ctx->pc = 0x80061C8Cu;
    // 80061C8C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061C90:
    ctx->pc = 0x80061C90u;
    // 80061C90: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061C94:
    ctx->pc = 0x80061C94u;
    // 80061C94: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061C98:
    ctx->pc = 0x80061C98u;
    // 80061C98: bl      0x801698F0
    {
            ctx->lr = 0x80061C9Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061C9C:
    ctx->pc = 0x80061C9Cu;
    ctx->downcount -= 22;
    // 80061C9C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061CA0:
    ctx->pc = 0x80061CA0u;
    // 80061CA0: lis     r0, 10
    ctx->gpr[0] = ((u32)(s32)(10) << 16);

label_80061CA4:
    ctx->pc = 0x80061CA4u;
    // 80061CA4: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061CA8:
    ctx->pc = 0x80061CA8u;
    // 80061CA8: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_80061CAC:
    ctx->pc = 0x80061CACu;
    // 80061CAC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061CB0:
    ctx->pc = 0x80061CB0u;
    // 80061CB0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061CB4:
    ctx->pc = 0x80061CB4u;
    // 80061CB4: lwz     r8, 704(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061CB8:
    ctx->pc = 0x80061CB8u;
    // 80061CB8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061CBC:
    ctx->pc = 0x80061CBCu;
    // 80061CBC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061CC0:
    ctx->pc = 0x80061CC0u;
    // 80061CC0: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061CC4:
    ctx->pc = 0x80061CC4u;
    // 80061CC4: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061CC8:
    ctx->pc = 0x80061CC8u;
    // 80061CC8: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061CCC:
    ctx->pc = 0x80061CCCu;
    // 80061CCC: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061CD0:
    ctx->pc = 0x80061CD0u;
    // 80061CD0: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061CD4:
    ctx->pc = 0x80061CD4u;
    // 80061CD4: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061CD8:
    ctx->pc = 0x80061CD8u;
    // 80061CD8: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061CDC:
    ctx->pc = 0x80061CDCu;
    // 80061CDC: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061CE0:
    ctx->pc = 0x80061CE0u;
    // 80061CE0: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061CE4:
    ctx->pc = 0x80061CE4u;
    // 80061CE4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061CE8:
    ctx->pc = 0x80061CE8u;
    // 80061CE8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061CEC:
    ctx->pc = 0x80061CECu;
    // 80061CEC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061CF0:
    ctx->pc = 0x80061CF0u;
    // 80061CF0: bl      0x801698F0
    {
            ctx->lr = 0x80061CF4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061CF4:
    ctx->pc = 0x80061CF4u;
    ctx->downcount -= 22;
    // 80061CF4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061CF8:
    ctx->pc = 0x80061CF8u;
    // 80061CF8: lis     r0, 10
    ctx->gpr[0] = ((u32)(s32)(10) << 16);

label_80061CFC:
    ctx->pc = 0x80061CFCu;
    // 80061CFC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061D00:
    ctx->pc = 0x80061D00u;
    // 80061D00: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_80061D04:
    ctx->pc = 0x80061D04u;
    // 80061D04: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061D08:
    ctx->pc = 0x80061D08u;
    // 80061D08: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061D0C:
    ctx->pc = 0x80061D0Cu;
    // 80061D0C: lwz     r8, 656(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(656);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061D10:
    ctx->pc = 0x80061D10u;
    // 80061D10: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061D14:
    ctx->pc = 0x80061D14u;
    // 80061D14: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061D18:
    ctx->pc = 0x80061D18u;
    // 80061D18: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061D1C:
    ctx->pc = 0x80061D1Cu;
    // 80061D1C: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061D20:
    ctx->pc = 0x80061D20u;
    // 80061D20: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061D24:
    ctx->pc = 0x80061D24u;
    // 80061D24: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061D28:
    ctx->pc = 0x80061D28u;
    // 80061D28: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061D2C:
    ctx->pc = 0x80061D2Cu;
    // 80061D2C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061D30:
    ctx->pc = 0x80061D30u;
    // 80061D30: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061D34:
    ctx->pc = 0x80061D34u;
    // 80061D34: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061D38:
    ctx->pc = 0x80061D38u;
    // 80061D38: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061D3C:
    ctx->pc = 0x80061D3Cu;
    // 80061D3C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061D40:
    ctx->pc = 0x80061D40u;
    // 80061D40: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061D44:
    ctx->pc = 0x80061D44u;
    // 80061D44: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061D48:
    ctx->pc = 0x80061D48u;
    // 80061D48: bl      0x801698F0
    {
            ctx->lr = 0x80061D4Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061D4C:
    ctx->pc = 0x80061D4Cu;
    ctx->downcount -= 34;
    // 80061D4C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061D50:
    ctx->pc = 0x80061D50u;
    // 80061D50: lis     r0, 10
    ctx->gpr[0] = ((u32)(s32)(10) << 16);

label_80061D54:
    ctx->pc = 0x80061D54u;
    // 80061D54: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061D58:
    ctx->pc = 0x80061D58u;
    // 80061D58: ori     r0, r0, 0x0022
    ctx->gpr[0] = ctx->gpr[0] | 0x0022u;

label_80061D5C:
    ctx->pc = 0x80061D5Cu;
    // 80061D5C: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80061D60:
    ctx->pc = 0x80061D60u;
    // 80061D60: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061D64:
    ctx->pc = 0x80061D64u;
    // 80061D64: lwz     r28, 824(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(824);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80061D68:
    ctx->pc = 0x80061D68u;
    // 80061D68: addi    r10, r9, 31276
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(31276);

label_80061D6C:
    ctx->pc = 0x80061D6Cu;
    // 80061D6C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061D70:
    ctx->pc = 0x80061D70u;
    // 80061D70: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061D74:
    ctx->pc = 0x80061D74u;
    // 80061D74: lwz     r0, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061D78:
    ctx->pc = 0x80061D78u;
    // 80061D78: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061D7C:
    ctx->pc = 0x80061D7Cu;
    // 80061D7C: lwz     r6, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80061D80:
    ctx->pc = 0x80061D80u;
    // 80061D80: lwz     r7, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061D84:
    ctx->pc = 0x80061D84u;
    // 80061D84: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061D88:
    ctx->pc = 0x80061D88u;
    // 80061D88: lwz     r8, 31276(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31276);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061D8C:
    ctx->pc = 0x80061D8Cu;
    // 80061D8C: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80061D90:
    ctx->pc = 0x80061D90u;
    // 80061D90: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80061D94:
    ctx->pc = 0x80061D94u;
    // 80061D94: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061D98:
    ctx->pc = 0x80061D98u;
    // 80061D98: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061D9C:
    ctx->pc = 0x80061D9Cu;
    // 80061D9C: stw     r28, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80061DA0:
    ctx->pc = 0x80061DA0u;
    // 80061DA0: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80061DA4:
    ctx->pc = 0x80061DA4u;
    // 80061DA4: lwz     r7, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061DA8:
    ctx->pc = 0x80061DA8u;
    // 80061DA8: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061DAC:
    ctx->pc = 0x80061DACu;
    // 80061DAC: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061DB0:
    ctx->pc = 0x80061DB0u;
    // 80061DB0: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061DB4:
    ctx->pc = 0x80061DB4u;
    // 80061DB4: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80061DB8:
    ctx->pc = 0x80061DB8u;
    // 80061DB8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061DBC:
    ctx->pc = 0x80061DBCu;
    // 80061DBC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061DC0:
    ctx->pc = 0x80061DC0u;
    // 80061DC0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061DC4:
    ctx->pc = 0x80061DC4u;
    // 80061DC4: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80061DC8:
    ctx->pc = 0x80061DC8u;
    // 80061DC8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061DCC:
    ctx->pc = 0x80061DCCu;
    // 80061DCC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061DD0:
    ctx->pc = 0x80061DD0u;
    // 80061DD0: bl      0x801698F0
    {
            ctx->lr = 0x80061DD4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061DD4:
    ctx->pc = 0x80061DD4u;
    ctx->downcount -= 25;
    // 80061DD4: lis     r0, 10
    ctx->gpr[0] = ((u32)(s32)(10) << 16);

label_80061DD8:
    ctx->pc = 0x80061DD8u;
    // 80061DD8: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80061DDC:
    ctx->pc = 0x80061DDCu;
    // 80061DDC: ori     r0, r0, 0x0014
    ctx->gpr[0] = ctx->gpr[0] | 0x0014u;

label_80061DE0:
    ctx->pc = 0x80061DE0u;
    // 80061DE0: addi    r9, r9, 8176
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8176);

label_80061DE4:
    ctx->pc = 0x80061DE4u;
    // 80061DE4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061DE8:
    ctx->pc = 0x80061DE8u;
    // 80061DE8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061DEC:
    ctx->pc = 0x80061DECu;
    // 80061DEC: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80061DF0:
    ctx->pc = 0x80061DF0u;
    // 80061DF0: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061DF4:
    ctx->pc = 0x80061DF4u;
    // 80061DF4: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061DF8:
    ctx->pc = 0x80061DF8u;
    // 80061DF8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061DFC:
    ctx->pc = 0x80061DFCu;
    // 80061DFC: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061E00:
    ctx->pc = 0x80061E00u;
    // 80061E00: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061E04:
    ctx->pc = 0x80061E04u;
    // 80061E04: lwz     r8, 488(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(488);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061E08:
    ctx->pc = 0x80061E08u;
    // 80061E08: lwz     r9, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061E0C:
    ctx->pc = 0x80061E0Cu;
    // 80061E0C: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061E10:
    ctx->pc = 0x80061E10u;
    // 80061E10: lwz     r10, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061E14:
    ctx->pc = 0x80061E14u;
    // 80061E14: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061E18:
    ctx->pc = 0x80061E18u;
    // 80061E18: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061E1C:
    ctx->pc = 0x80061E1Cu;
    // 80061E1C: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061E20:
    ctx->pc = 0x80061E20u;
    // 80061E20: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061E24:
    ctx->pc = 0x80061E24u;
    // 80061E24: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061E28:
    ctx->pc = 0x80061E28u;
    // 80061E28: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061E2C:
    ctx->pc = 0x80061E2Cu;
    // 80061E2C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061E30:
    ctx->pc = 0x80061E30u;
    // 80061E30: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061E34:
    ctx->pc = 0x80061E34u;
    // 80061E34: bl      0x801698F0
    {
            ctx->lr = 0x80061E38u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061E38:
    ctx->pc = 0x80061E38u;
    ctx->downcount -= 23;
    // 80061E38: lis     r0, 10
    ctx->gpr[0] = ((u32)(s32)(10) << 16);

label_80061E3C:
    ctx->pc = 0x80061E3Cu;
    // 80061E3C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061E40:
    ctx->pc = 0x80061E40u;
    // 80061E40: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_80061E44:
    ctx->pc = 0x80061E44u;
    // 80061E44: stw     r26, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80061E48:
    ctx->pc = 0x80061E48u;
    // 80061E48: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061E4C:
    ctx->pc = 0x80061E4Cu;
    // 80061E4C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061E50:
    ctx->pc = 0x80061E50u;
    // 80061E50: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061E54:
    ctx->pc = 0x80061E54u;
    // 80061E54: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061E58:
    ctx->pc = 0x80061E58u;
    // 80061E58: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061E5C:
    ctx->pc = 0x80061E5Cu;
    // 80061E5C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061E60:
    ctx->pc = 0x80061E60u;
    // 80061E60: lwz     r8, 584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061E64:
    ctx->pc = 0x80061E64u;
    // 80061E64: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061E68:
    ctx->pc = 0x80061E68u;
    // 80061E68: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061E6C:
    ctx->pc = 0x80061E6Cu;
    // 80061E6C: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061E70:
    ctx->pc = 0x80061E70u;
    // 80061E70: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061E74:
    ctx->pc = 0x80061E74u;
    // 80061E74: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061E78:
    ctx->pc = 0x80061E78u;
    // 80061E78: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061E7C:
    ctx->pc = 0x80061E7Cu;
    // 80061E7C: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061E80:
    ctx->pc = 0x80061E80u;
    // 80061E80: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061E84:
    ctx->pc = 0x80061E84u;
    // 80061E84: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061E88:
    ctx->pc = 0x80061E88u;
    // 80061E88: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061E8C:
    ctx->pc = 0x80061E8Cu;
    // 80061E8C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061E90:
    ctx->pc = 0x80061E90u;
    // 80061E90: bl      0x801698F0
    {
            ctx->lr = 0x80061E94u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061E94:
    ctx->pc = 0x80061E94u;
    ctx->downcount -= 21;
    // 80061E94: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061E98:
    ctx->pc = 0x80061E98u;
    // 80061E98: lis     r0, 10
    ctx->gpr[0] = ((u32)(s32)(10) << 16);

label_80061E9C:
    ctx->pc = 0x80061E9Cu;
    // 80061E9C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061EA0:
    ctx->pc = 0x80061EA0u;
    // 80061EA0: ori     r0, r0, 0x0003
    ctx->gpr[0] = ctx->gpr[0] | 0x0003u;

label_80061EA4:
    ctx->pc = 0x80061EA4u;
    // 80061EA4: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80061EA8:
    ctx->pc = 0x80061EA8u;
    // 80061EA8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061EAC:
    ctx->pc = 0x80061EACu;
    // 80061EAC: lwz     r8, 80(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(80);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061EB0:
    ctx->pc = 0x80061EB0u;
    // 80061EB0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061EB4:
    ctx->pc = 0x80061EB4u;
    // 80061EB4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061EB8:
    ctx->pc = 0x80061EB8u;
    // 80061EB8: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061EBC:
    ctx->pc = 0x80061EBCu;
    // 80061EBC: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061EC0:
    ctx->pc = 0x80061EC0u;
    // 80061EC0: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061EC4:
    ctx->pc = 0x80061EC4u;
    // 80061EC4: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061EC8:
    ctx->pc = 0x80061EC8u;
    // 80061EC8: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061ECC:
    ctx->pc = 0x80061ECCu;
    // 80061ECC: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061ED0:
    ctx->pc = 0x80061ED0u;
    // 80061ED0: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061ED4:
    ctx->pc = 0x80061ED4u;
    // 80061ED4: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061ED8:
    ctx->pc = 0x80061ED8u;
    // 80061ED8: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061EDC:
    ctx->pc = 0x80061EDCu;
    // 80061EDC: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061EE0:
    ctx->pc = 0x80061EE0u;
    // 80061EE0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061EE4:
    ctx->pc = 0x80061EE4u;
    // 80061EE4: bl      0x801698F0
    {
            ctx->lr = 0x80061EE8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061EE8:
    ctx->pc = 0x80061EE8u;
    ctx->downcount -= 19;
    // 80061EE8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80061EEC:
    ctx->pc = 0x80061EECu;
    // 80061EEC: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80061EF0:
    ctx->pc = 0x80061EF0u;
    // 80061EF0: lwz     r7, 31296(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31296);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80061EF4:
    ctx->pc = 0x80061EF4u;
    // 80061EF4: addi    r30, r8, 14860
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(14860);

label_80061EF8:
    ctx->pc = 0x80061EF8u;
    // 80061EF8: addi    r9, r9, 31296
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31296);

label_80061EFC:
    ctx->pc = 0x80061EFCu;
    // 80061EFC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061F00:
    ctx->pc = 0x80061F00u;
    // 80061F00: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80061F04:
    ctx->pc = 0x80061F04u;
    // 80061F04: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061F08:
    ctx->pc = 0x80061F08u;
    // 80061F08: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061F0C:
    ctx->pc = 0x80061F0Cu;
    // 80061F0C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061F10:
    ctx->pc = 0x80061F10u;
    // 80061F10: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061F14:
    ctx->pc = 0x80061F14u;
    // 80061F14: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061F18:
    ctx->pc = 0x80061F18u;
    // 80061F18: stw     r7, 14860(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(14860);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80061F1C:
    ctx->pc = 0x80061F1Cu;
    // 80061F1C: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80061F20:
    ctx->pc = 0x80061F20u;
    // 80061F20: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061F24:
    ctx->pc = 0x80061F24u;
    // 80061F24: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061F28:
    ctx->pc = 0x80061F28u;
    // 80061F28: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061F2C:
    ctx->pc = 0x80061F2Cu;
    // 80061F2C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061F30:
    ctx->pc = 0x80061F30u;
    // 80061F30: bl      0x801698F0
    {
            ctx->lr = 0x80061F34u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061F34:
    ctx->pc = 0x80061F34u;
    ctx->downcount -= 23;
    // 80061F34: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061F38:
    ctx->pc = 0x80061F38u;
    // 80061F38: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061F3C:
    ctx->pc = 0x80061F3Cu;
    // 80061F3C: lis     r0, 11
    ctx->gpr[0] = ((u32)(s32)(11) << 16);

label_80061F40:
    ctx->pc = 0x80061F40u;
    // 80061F40: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061F44:
    ctx->pc = 0x80061F44u;
    // 80061F44: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80061F48:
    ctx->pc = 0x80061F48u;
    // 80061F48: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061F4C:
    ctx->pc = 0x80061F4Cu;
    // 80061F4C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061F50:
    ctx->pc = 0x80061F50u;
    // 80061F50: lwz     r8, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061F54:
    ctx->pc = 0x80061F54u;
    // 80061F54: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061F58:
    ctx->pc = 0x80061F58u;
    // 80061F58: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061F5C:
    ctx->pc = 0x80061F5Cu;
    // 80061F5C: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061F60:
    ctx->pc = 0x80061F60u;
    // 80061F60: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061F64:
    ctx->pc = 0x80061F64u;
    // 80061F64: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061F68:
    ctx->pc = 0x80061F68u;
    // 80061F68: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061F6C:
    ctx->pc = 0x80061F6Cu;
    // 80061F6C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061F70:
    ctx->pc = 0x80061F70u;
    // 80061F70: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061F74:
    ctx->pc = 0x80061F74u;
    // 80061F74: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061F78:
    ctx->pc = 0x80061F78u;
    // 80061F78: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061F7C:
    ctx->pc = 0x80061F7Cu;
    // 80061F7C: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061F80:
    ctx->pc = 0x80061F80u;
    // 80061F80: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061F84:
    ctx->pc = 0x80061F84u;
    // 80061F84: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061F88:
    ctx->pc = 0x80061F88u;
    // 80061F88: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061F8C:
    ctx->pc = 0x80061F8Cu;
    // 80061F8C: bl      0x801698F0
    {
            ctx->lr = 0x80061F90u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061F90:
    ctx->pc = 0x80061F90u;
    ctx->downcount -= 22;
    // 80061F90: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061F94:
    ctx->pc = 0x80061F94u;
    // 80061F94: lis     r0, 11
    ctx->gpr[0] = ((u32)(s32)(11) << 16);

label_80061F98:
    ctx->pc = 0x80061F98u;
    // 80061F98: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061F9C:
    ctx->pc = 0x80061F9Cu;
    // 80061F9C: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_80061FA0:
    ctx->pc = 0x80061FA0u;
    // 80061FA0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80061FA4:
    ctx->pc = 0x80061FA4u;
    // 80061FA4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80061FA8:
    ctx->pc = 0x80061FA8u;
    // 80061FA8: lwz     r8, 704(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80061FAC:
    ctx->pc = 0x80061FACu;
    // 80061FAC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80061FB0:
    ctx->pc = 0x80061FB0u;
    // 80061FB0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061FB4:
    ctx->pc = 0x80061FB4u;
    // 80061FB4: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80061FB8:
    ctx->pc = 0x80061FB8u;
    // 80061FB8: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80061FBC:
    ctx->pc = 0x80061FBCu;
    // 80061FBC: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80061FC0:
    ctx->pc = 0x80061FC0u;
    // 80061FC0: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80061FC4:
    ctx->pc = 0x80061FC4u;
    // 80061FC4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061FC8:
    ctx->pc = 0x80061FC8u;
    // 80061FC8: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80061FCC:
    ctx->pc = 0x80061FCCu;
    // 80061FCC: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80061FD0:
    ctx->pc = 0x80061FD0u;
    // 80061FD0: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80061FD4:
    ctx->pc = 0x80061FD4u;
    // 80061FD4: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80061FD8:
    ctx->pc = 0x80061FD8u;
    // 80061FD8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80061FDC:
    ctx->pc = 0x80061FDCu;
    // 80061FDC: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80061FE0:
    ctx->pc = 0x80061FE0u;
    // 80061FE0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80061FE4:
    ctx->pc = 0x80061FE4u;
    // 80061FE4: bl      0x801698F0
    {
            ctx->lr = 0x80061FE8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80061FE8:
    ctx->pc = 0x80061FE8u;
    ctx->downcount -= 34;
    // 80061FE8: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80061FEC:
    ctx->pc = 0x80061FECu;
    // 80061FEC: lis     r0, 11
    ctx->gpr[0] = ((u32)(s32)(11) << 16);

label_80061FF0:
    ctx->pc = 0x80061FF0u;
    // 80061FF0: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80061FF4:
    ctx->pc = 0x80061FF4u;
    // 80061FF4: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_80061FF8:
    ctx->pc = 0x80061FF8u;
    // 80061FF8: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80061FFC:
    ctx->pc = 0x80061FFCu;
    // 80061FFC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062000:
    ctx->pc = 0x80062000u;
    // 80062000: lwz     r28, 656(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(656);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80062004:
    ctx->pc = 0x80062004u;
    // 80062004: addi    r10, r9, 31316
    ctx->gpr[10] = ctx->gpr[9] + (u32)(s32)(31316);

label_80062008:
    ctx->pc = 0x80062008u;
    // 80062008: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006200C:
    ctx->pc = 0x8006200Cu;
    // 8006200C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062010:
    ctx->pc = 0x80062010u;
    // 80062010: lwz     r0, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062014:
    ctx->pc = 0x80062014u;
    // 80062014: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062018:
    ctx->pc = 0x80062018u;
    // 80062018: lwz     r6, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006201C:
    ctx->pc = 0x8006201Cu;
    // 8006201C: lwz     r7, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062020:
    ctx->pc = 0x80062020u;
    // 80062020: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062024:
    ctx->pc = 0x80062024u;
    // 80062024: lwz     r8, 31316(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31316);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062028:
    ctx->pc = 0x80062028u;
    // 80062028: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8006202C:
    ctx->pc = 0x8006202Cu;
    // 8006202C: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062030:
    ctx->pc = 0x80062030u;
    // 80062030: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062034:
    ctx->pc = 0x80062034u;
    // 80062034: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062038:
    ctx->pc = 0x80062038u;
    // 80062038: stw     r28, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_8006203C:
    ctx->pc = 0x8006203Cu;
    // 8006203C: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80062040:
    ctx->pc = 0x80062040u;
    // 80062040: lwz     r7, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062044:
    ctx->pc = 0x80062044u;
    // 80062044: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062048:
    ctx->pc = 0x80062048u;
    // 80062048: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006204C:
    ctx->pc = 0x8006204Cu;
    // 8006204C: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062050:
    ctx->pc = 0x80062050u;
    // 80062050: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062054:
    ctx->pc = 0x80062054u;
    // 80062054: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062058:
    ctx->pc = 0x80062058u;
    // 80062058: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006205C:
    ctx->pc = 0x8006205Cu;
    // 8006205C: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062060:
    ctx->pc = 0x80062060u;
    // 80062060: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80062064:
    ctx->pc = 0x80062064u;
    // 80062064: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062068:
    ctx->pc = 0x80062068u;
    // 80062068: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006206C:
    ctx->pc = 0x8006206Cu;
    // 8006206C: bl      0x801698F0
    {
            ctx->lr = 0x80062070u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062070:
    ctx->pc = 0x80062070u;
    ctx->downcount -= 24;
    // 80062070: lis     r0, 11
    ctx->gpr[0] = ((u32)(s32)(11) << 16);

label_80062074:
    ctx->pc = 0x80062074u;
    // 80062074: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80062078:
    ctx->pc = 0x80062078u;
    // 80062078: ori     r0, r0, 0x0019
    ctx->gpr[0] = ctx->gpr[0] | 0x0019u;

label_8006207C:
    ctx->pc = 0x8006207Cu;
    // 8006207C: addi    r9, r9, 8956
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(8956);

label_80062080:
    ctx->pc = 0x80062080u;
    // 80062080: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062084:
    ctx->pc = 0x80062084u;
    // 80062084: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80062088:
    ctx->pc = 0x80062088u;
    // 80062088: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_8006208C:
    ctx->pc = 0x8006208Cu;
    // 8006208C: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062090:
    ctx->pc = 0x80062090u;
    // 80062090: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062094:
    ctx->pc = 0x80062094u;
    // 80062094: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062098:
    ctx->pc = 0x80062098u;
    // 80062098: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006209C:
    ctx->pc = 0x8006209Cu;
    // 8006209C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800620A0:
    ctx->pc = 0x800620A0u;
    // 800620A0: lwz     r8, 608(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800620A4:
    ctx->pc = 0x800620A4u;
    // 800620A4: lwz     r9, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800620A8:
    ctx->pc = 0x800620A8u;
    // 800620A8: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800620AC:
    ctx->pc = 0x800620ACu;
    // 800620AC: lwz     r10, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800620B0:
    ctx->pc = 0x800620B0u;
    // 800620B0: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800620B4:
    ctx->pc = 0x800620B4u;
    // 800620B4: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800620B8:
    ctx->pc = 0x800620B8u;
    // 800620B8: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800620BC:
    ctx->pc = 0x800620BCu;
    // 800620BC: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800620C0:
    ctx->pc = 0x800620C0u;
    // 800620C0: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800620C4:
    ctx->pc = 0x800620C4u;
    // 800620C4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800620C8:
    ctx->pc = 0x800620C8u;
    // 800620C8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800620CC:
    ctx->pc = 0x800620CCu;
    // 800620CC: bl      0x801698F0
    {
            ctx->lr = 0x800620D0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800620D0:
    ctx->pc = 0x800620D0u;
    ctx->downcount -= 19;
    // 800620D0: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800620D4:
    ctx->pc = 0x800620D4u;
    // 800620D4: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_800620D8:
    ctx->pc = 0x800620D8u;
    // 800620D8: lwz     r7, 31336(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31336);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800620DC:
    ctx->pc = 0x800620DCu;
    // 800620DC: addi    r30, r8, 15000
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(15000);

label_800620E0:
    ctx->pc = 0x800620E0u;
    // 800620E0: addi    r9, r9, 31336
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31336);

label_800620E4:
    ctx->pc = 0x800620E4u;
    // 800620E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800620E8:
    ctx->pc = 0x800620E8u;
    // 800620E8: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800620EC:
    ctx->pc = 0x800620ECu;
    // 800620EC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800620F0:
    ctx->pc = 0x800620F0u;
    // 800620F0: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800620F4:
    ctx->pc = 0x800620F4u;
    // 800620F4: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800620F8:
    ctx->pc = 0x800620F8u;
    // 800620F8: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800620FC:
    ctx->pc = 0x800620FCu;
    // 800620FC: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062100:
    ctx->pc = 0x80062100u;
    // 80062100: stw     r7, 15000(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(15000);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062104:
    ctx->pc = 0x80062104u;
    // 80062104: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062108:
    ctx->pc = 0x80062108u;
    // 80062108: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006210C:
    ctx->pc = 0x8006210Cu;
    // 8006210C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062110:
    ctx->pc = 0x80062110u;
    // 80062110: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062114:
    ctx->pc = 0x80062114u;
    // 80062114: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062118:
    ctx->pc = 0x80062118u;
    // 80062118: bl      0x801698F0
    {
            ctx->lr = 0x8006211Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006211C:
    ctx->pc = 0x8006211Cu;
    ctx->downcount -= 23;
    // 8006211C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062120:
    ctx->pc = 0x80062120u;
    // 80062120: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80062124:
    ctx->pc = 0x80062124u;
    // 80062124: lis     r0, 12
    ctx->gpr[0] = ((u32)(s32)(12) << 16);

label_80062128:
    ctx->pc = 0x80062128u;
    // 80062128: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006212C:
    ctx->pc = 0x8006212Cu;
    // 8006212C: ori     r0, r0, 0x001E
    ctx->gpr[0] = ctx->gpr[0] | 0x001Eu;

label_80062130:
    ctx->pc = 0x80062130u;
    // 80062130: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062134:
    ctx->pc = 0x80062134u;
    // 80062134: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062138:
    ctx->pc = 0x80062138u;
    // 80062138: lwz     r8, 728(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(728);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006213C:
    ctx->pc = 0x8006213Cu;
    // 8006213C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062140:
    ctx->pc = 0x80062140u;
    // 80062140: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062144:
    ctx->pc = 0x80062144u;
    // 80062144: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062148:
    ctx->pc = 0x80062148u;
    // 80062148: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006214C:
    ctx->pc = 0x8006214Cu;
    // 8006214C: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062150:
    ctx->pc = 0x80062150u;
    // 80062150: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062154:
    ctx->pc = 0x80062154u;
    // 80062154: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062158:
    ctx->pc = 0x80062158u;
    // 80062158: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006215C:
    ctx->pc = 0x8006215Cu;
    // 8006215C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062160:
    ctx->pc = 0x80062160u;
    // 80062160: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062164:
    ctx->pc = 0x80062164u;
    // 80062164: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062168:
    ctx->pc = 0x80062168u;
    // 80062168: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006216C:
    ctx->pc = 0x8006216Cu;
    // 8006216C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062170:
    ctx->pc = 0x80062170u;
    // 80062170: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062174:
    ctx->pc = 0x80062174u;
    // 80062174: bl      0x801698F0
    {
            ctx->lr = 0x80062178u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062178:
    ctx->pc = 0x80062178u;
    ctx->downcount -= 22;
    // 80062178: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_8006217C:
    ctx->pc = 0x8006217Cu;
    // 8006217C: lis     r0, 12
    ctx->gpr[0] = ((u32)(s32)(12) << 16);

label_80062180:
    ctx->pc = 0x80062180u;
    // 80062180: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062184:
    ctx->pc = 0x80062184u;
    // 80062184: ori     r0, r0, 0x001D
    ctx->gpr[0] = ctx->gpr[0] | 0x001Du;

label_80062188:
    ctx->pc = 0x80062188u;
    // 80062188: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006218C:
    ctx->pc = 0x8006218Cu;
    // 8006218C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062190:
    ctx->pc = 0x80062190u;
    // 80062190: lwz     r8, 704(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(704);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062194:
    ctx->pc = 0x80062194u;
    // 80062194: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062198:
    ctx->pc = 0x80062198u;
    // 80062198: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006219C:
    ctx->pc = 0x8006219Cu;
    // 8006219C: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800621A0:
    ctx->pc = 0x800621A0u;
    // 800621A0: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800621A4:
    ctx->pc = 0x800621A4u;
    // 800621A4: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800621A8:
    ctx->pc = 0x800621A8u;
    // 800621A8: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800621AC:
    ctx->pc = 0x800621ACu;
    // 800621AC: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800621B0:
    ctx->pc = 0x800621B0u;
    // 800621B0: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800621B4:
    ctx->pc = 0x800621B4u;
    // 800621B4: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800621B8:
    ctx->pc = 0x800621B8u;
    // 800621B8: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800621BC:
    ctx->pc = 0x800621BCu;
    // 800621BC: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800621C0:
    ctx->pc = 0x800621C0u;
    // 800621C0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800621C4:
    ctx->pc = 0x800621C4u;
    // 800621C4: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_800621C8:
    ctx->pc = 0x800621C8u;
    // 800621C8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800621CC:
    ctx->pc = 0x800621CCu;
    // 800621CC: bl      0x801698F0
    {
            ctx->lr = 0x800621D0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800621D0:
    ctx->pc = 0x800621D0u;
    ctx->downcount -= 22;
    // 800621D0: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800621D4:
    ctx->pc = 0x800621D4u;
    // 800621D4: lis     r0, 12
    ctx->gpr[0] = ((u32)(s32)(12) << 16);

label_800621D8:
    ctx->pc = 0x800621D8u;
    // 800621D8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800621DC:
    ctx->pc = 0x800621DCu;
    // 800621DC: ori     r0, r0, 0x001B
    ctx->gpr[0] = ctx->gpr[0] | 0x001Bu;

label_800621E0:
    ctx->pc = 0x800621E0u;
    // 800621E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800621E4:
    ctx->pc = 0x800621E4u;
    // 800621E4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800621E8:
    ctx->pc = 0x800621E8u;
    // 800621E8: lwz     r8, 656(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(656);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800621EC:
    ctx->pc = 0x800621ECu;
    // 800621EC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800621F0:
    ctx->pc = 0x800621F0u;
    // 800621F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800621F4:
    ctx->pc = 0x800621F4u;
    // 800621F4: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800621F8:
    ctx->pc = 0x800621F8u;
    // 800621F8: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800621FC:
    ctx->pc = 0x800621FCu;
    // 800621FC: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062200:
    ctx->pc = 0x80062200u;
    // 80062200: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062204:
    ctx->pc = 0x80062204u;
    // 80062204: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062208:
    ctx->pc = 0x80062208u;
    // 80062208: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006220C:
    ctx->pc = 0x8006220Cu;
    // 8006220C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062210:
    ctx->pc = 0x80062210u;
    // 80062210: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062214:
    ctx->pc = 0x80062214u;
    // 80062214: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062218:
    ctx->pc = 0x80062218u;
    // 80062218: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006221C:
    ctx->pc = 0x8006221Cu;
    // 8006221C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062220:
    ctx->pc = 0x80062220u;
    // 80062220: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062224:
    ctx->pc = 0x80062224u;
    // 80062224: bl      0x801698F0
    {
            ctx->lr = 0x80062228u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062228:
    ctx->pc = 0x80062228u;
    ctx->downcount -= 25;
    // 80062228: lis     r0, 12
    ctx->gpr[0] = ((u32)(s32)(12) << 16);

label_8006222C:
    ctx->pc = 0x8006222Cu;
    // 8006222C: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80062230:
    ctx->pc = 0x80062230u;
    // 80062230: ori     r0, r0, 0x0010
    ctx->gpr[0] = ctx->gpr[0] | 0x0010u;

label_80062234:
    ctx->pc = 0x80062234u;
    // 80062234: addi    r9, r9, 9096
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9096);

label_80062238:
    ctx->pc = 0x80062238u;
    // 80062238: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006223C:
    ctx->pc = 0x8006223Cu;
    // 8006223C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062240:
    ctx->pc = 0x80062240u;
    // 80062240: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_80062244:
    ctx->pc = 0x80062244u;
    // 80062244: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062248:
    ctx->pc = 0x80062248u;
    // 80062248: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006224C:
    ctx->pc = 0x8006224Cu;
    // 8006224C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062250:
    ctx->pc = 0x80062250u;
    // 80062250: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062254:
    ctx->pc = 0x80062254u;
    // 80062254: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062258:
    ctx->pc = 0x80062258u;
    // 80062258: lwz     r8, 392(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(392);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006225C:
    ctx->pc = 0x8006225Cu;
    // 8006225C: lwz     r9, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062260:
    ctx->pc = 0x80062260u;
    // 80062260: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062264:
    ctx->pc = 0x80062264u;
    // 80062264: lwz     r10, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062268:
    ctx->pc = 0x80062268u;
    // 80062268: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006226C:
    ctx->pc = 0x8006226Cu;
    // 8006226C: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062270:
    ctx->pc = 0x80062270u;
    // 80062270: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062274:
    ctx->pc = 0x80062274u;
    // 80062274: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062278:
    ctx->pc = 0x80062278u;
    // 80062278: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006227C:
    ctx->pc = 0x8006227Cu;
    // 8006227C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062280:
    ctx->pc = 0x80062280u;
    // 80062280: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062284:
    ctx->pc = 0x80062284u;
    // 80062284: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062288:
    ctx->pc = 0x80062288u;
    // 80062288: bl      0x801698F0
    {
            ctx->lr = 0x8006228Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006228C:
    ctx->pc = 0x8006228Cu;
    ctx->downcount -= 37;
    // 8006228C: lis     r0, 12
    ctx->gpr[0] = ((u32)(s32)(12) << 16);

label_80062290:
    ctx->pc = 0x80062290u;
    // 80062290: lis     r9, -32735
    ctx->gpr[9] = ((u32)(s32)(-32735) << 16);

label_80062294:
    ctx->pc = 0x80062294u;
    // 80062294: ori     r0, r0, 0x0015
    ctx->gpr[0] = ctx->gpr[0] | 0x0015u;

label_80062298:
    ctx->pc = 0x80062298u;
    // 80062298: addi    r9, r9, 9036
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(9036);

label_8006229C:
    ctx->pc = 0x8006229Cu;
    // 8006229C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800622A0:
    ctx->pc = 0x800622A0u;
    // 800622A0: lis     r6, -32738
    ctx->gpr[6] = ((u32)(s32)(-32738) << 16);

label_800622A4:
    ctx->pc = 0x800622A4u;
    // 800622A4: li      r0, 2
    ctx->gpr[0] = (u32)(s32)(2);

label_800622A8:
    ctx->pc = 0x800622A8u;
    // 800622A8: stw     r9, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800622AC:
    ctx->pc = 0x800622ACu;
    // 800622AC: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800622B0:
    ctx->pc = 0x800622B0u;
    // 800622B0: addi    r10, r6, 31356
    ctx->gpr[10] = ctx->gpr[6] + (u32)(s32)(31356);

label_800622B4:
    ctx->pc = 0x800622B4u;
    // 800622B4: lwz     r7, 31356(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(31356);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800622B8:
    ctx->pc = 0x800622B8u;
    // 800622B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800622BC:
    ctx->pc = 0x800622BCu;
    // 800622BC: lwz     r28, 512(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(512);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_800622C0:
    ctx->pc = 0x800622C0u;
    // 800622C0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800622C4:
    ctx->pc = 0x800622C4u;
    // 800622C4: lwz     r8, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800622C8:
    ctx->pc = 0x800622C8u;
    // 800622C8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800622CC:
    ctx->pc = 0x800622CCu;
    // 800622CC: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800622D0:
    ctx->pc = 0x800622D0u;
    // 800622D0: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800622D4:
    ctx->pc = 0x800622D4u;
    // 800622D4: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800622D8:
    ctx->pc = 0x800622D8u;
    // 800622D8: stw     r8, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800622DC:
    ctx->pc = 0x800622DCu;
    // 800622DC: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800622E0:
    ctx->pc = 0x800622E0u;
    // 800622E0: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800622E4:
    ctx->pc = 0x800622E4u;
    // 800622E4: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800622E8:
    ctx->pc = 0x800622E8u;
    // 800622E8: stw     r28, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_800622EC:
    ctx->pc = 0x800622ECu;
    // 800622EC: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_800622F0:
    ctx->pc = 0x800622F0u;
    // 800622F0: lwz     r8, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800622F4:
    ctx->pc = 0x800622F4u;
    // 800622F4: lwz     r0, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800622F8:
    ctx->pc = 0x800622F8u;
    // 800622F8: lwz     r9, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800622FC:
    ctx->pc = 0x800622FCu;
    // 800622FC: lwz     r11, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062300:
    ctx->pc = 0x80062300u;
    // 80062300: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062304:
    ctx->pc = 0x80062304u;
    // 80062304: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062308:
    ctx->pc = 0x80062308u;
    // 80062308: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006230C:
    ctx->pc = 0x8006230Cu;
    // 8006230C: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062310:
    ctx->pc = 0x80062310u;
    // 80062310: stw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80062314:
    ctx->pc = 0x80062314u;
    // 80062314: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062318:
    ctx->pc = 0x80062318u;
    // 80062318: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006231C:
    ctx->pc = 0x8006231Cu;
    // 8006231C: bl      0x801698F0
    {
            ctx->lr = 0x80062320u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062320:
    ctx->pc = 0x80062320u;
    ctx->downcount -= 22;
    // 80062320: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80062324:
    ctx->pc = 0x80062324u;
    // 80062324: lis     r0, 12
    ctx->gpr[0] = ((u32)(s32)(12) << 16);

label_80062328:
    ctx->pc = 0x80062328u;
    // 80062328: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006232C:
    ctx->pc = 0x8006232Cu;
    // 8006232C: ori     r0, r0, 0x0022
    ctx->gpr[0] = ctx->gpr[0] | 0x0022u;

label_80062330:
    ctx->pc = 0x80062330u;
    // 80062330: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062334:
    ctx->pc = 0x80062334u;
    // 80062334: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062338:
    ctx->pc = 0x80062338u;
    // 80062338: lwz     r8, 824(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(824);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006233C:
    ctx->pc = 0x8006233Cu;
    // 8006233C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062340:
    ctx->pc = 0x80062340u;
    // 80062340: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062344:
    ctx->pc = 0x80062344u;
    // 80062344: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062348:
    ctx->pc = 0x80062348u;
    // 80062348: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006234C:
    ctx->pc = 0x8006234Cu;
    // 8006234C: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062350:
    ctx->pc = 0x80062350u;
    // 80062350: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062354:
    ctx->pc = 0x80062354u;
    // 80062354: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062358:
    ctx->pc = 0x80062358u;
    // 80062358: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006235C:
    ctx->pc = 0x8006235Cu;
    // 8006235C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062360:
    ctx->pc = 0x80062360u;
    // 80062360: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062364:
    ctx->pc = 0x80062364u;
    // 80062364: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062368:
    ctx->pc = 0x80062368u;
    // 80062368: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006236C:
    ctx->pc = 0x8006236Cu;
    // 8006236C: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062370:
    ctx->pc = 0x80062370u;
    // 80062370: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062374:
    ctx->pc = 0x80062374u;
    // 80062374: bl      0x801698F0
    {
            ctx->lr = 0x80062378u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062378:
    ctx->pc = 0x80062378u;
    ctx->downcount -= 22;
    // 80062378: lis     r0, 12
    ctx->gpr[0] = ((u32)(s32)(12) << 16);

label_8006237C:
    ctx->pc = 0x8006237Cu;
    // 8006237C: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_80062380:
    ctx->pc = 0x80062380u;
    // 80062380: ori     r0, r0, 0x0018
    ctx->gpr[0] = ctx->gpr[0] | 0x0018u;

label_80062384:
    ctx->pc = 0x80062384u;
    // 80062384: stw     r26, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80062388:
    ctx->pc = 0x80062388u;
    // 80062388: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006238C:
    ctx->pc = 0x8006238Cu;
    // 8006238C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062390:
    ctx->pc = 0x80062390u;
    // 80062390: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062394:
    ctx->pc = 0x80062394u;
    // 80062394: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80062398:
    ctx->pc = 0x80062398u;
    // 80062398: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006239C:
    ctx->pc = 0x8006239Cu;
    // 8006239C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800623A0:
    ctx->pc = 0x800623A0u;
    // 800623A0: lwz     r8, 584(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(584);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800623A4:
    ctx->pc = 0x800623A4u;
    // 800623A4: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800623A8:
    ctx->pc = 0x800623A8u;
    // 800623A8: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800623AC:
    ctx->pc = 0x800623ACu;
    // 800623AC: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800623B0:
    ctx->pc = 0x800623B0u;
    // 800623B0: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800623B4:
    ctx->pc = 0x800623B4u;
    // 800623B4: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800623B8:
    ctx->pc = 0x800623B8u;
    // 800623B8: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800623BC:
    ctx->pc = 0x800623BCu;
    // 800623BC: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800623C0:
    ctx->pc = 0x800623C0u;
    // 800623C0: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800623C4:
    ctx->pc = 0x800623C4u;
    // 800623C4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800623C8:
    ctx->pc = 0x800623C8u;
    // 800623C8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800623CC:
    ctx->pc = 0x800623CCu;
    // 800623CC: bl      0x801698F0
    {
            ctx->lr = 0x800623D0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800623D0:
    ctx->pc = 0x800623D0u;
    ctx->downcount -= 5;
    // 800623D0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800623D4:
    ctx->pc = 0x800623D4u;
    // 800623D4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800623D8:
    ctx->pc = 0x800623D8u;
    // 800623D8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800623DC:
    ctx->pc = 0x800623DCu;
    // 800623DC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800623E0:
    ctx->pc = 0x800623E0u;
    // 800623E0: bl      0x801698F0
    {
            ctx->lr = 0x800623E4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800623E4:
    ctx->pc = 0x800623E4u;
    ctx->downcount -= 26;
    // 800623E4: li      r3, 2
    ctx->gpr[3] = (u32)(s32)(2);

label_800623E8:
    ctx->pc = 0x800623E8u;
    // 800623E8: lis     r0, 13
    ctx->gpr[0] = ((u32)(s32)(13) << 16);

label_800623EC:
    ctx->pc = 0x800623ECu;
    // 800623EC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800623F0:
    ctx->pc = 0x800623F0u;
    // 800623F0: ori     r0, r0, 0x0034
    ctx->gpr[0] = ctx->gpr[0] | 0x0034u;

label_800623F4:
    ctx->pc = 0x800623F4u;
    // 800623F4: lis     r6, -32699
    ctx->gpr[6] = ((u32)(s32)(-32699) << 16);

label_800623F8:
    ctx->pc = 0x800623F8u;
    // 800623F8: lis     r5, -32699
    ctx->gpr[5] = ((u32)(s32)(-32699) << 16);

label_800623FC:
    ctx->pc = 0x800623FCu;
    // 800623FC: lwz     r8, 1256(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1256);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062400:
    ctx->pc = 0x80062400u;
    // 80062400: lis     r7, -32699
    ctx->gpr[7] = ((u32)(s32)(-32699) << 16);

label_80062404:
    ctx->pc = 0x80062404u;
    // 80062404: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062408:
    ctx->pc = 0x80062408u;
    // 80062408: addi    r7, r7, 15200
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(15200);

label_8006240C:
    ctx->pc = 0x8006240Cu;
    // 8006240C: addi    r5, r5, 15200
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(15200);

label_80062410:
    ctx->pc = 0x80062410u;
    // 80062410: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062414:
    ctx->pc = 0x80062414u;
    // 80062414: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062418:
    ctx->pc = 0x80062418u;
    // 80062418: addi    r3, r5, 20
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(20);

label_8006241C:
    ctx->pc = 0x8006241Cu;
    // 8006241C: lwz     r11, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062420:
    ctx->pc = 0x80062420u;
    // 80062420: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062424:
    ctx->pc = 0x80062424u;
    // 80062424: lwz     r0, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062428:
    ctx->pc = 0x80062428u;
    // 80062428: lwz     r9, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006242C:
    ctx->pc = 0x8006242Cu;
    // 8006242C: stw     r8, 15200(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(15200);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062430:
    ctx->pc = 0x80062430u;
    // 80062430: stw     r10, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062434:
    ctx->pc = 0x80062434u;
    // 80062434: stw     r11, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062438:
    ctx->pc = 0x80062438u;
    // 80062438: stw     r0, 12(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006243C:
    ctx->pc = 0x8006243Cu;
    // 8006243C: stw     r9, 16(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062440:
    ctx->pc = 0x80062440u;
    // 80062440: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062444:
    ctx->pc = 0x80062444u;
    // 80062444: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062448:
    ctx->pc = 0x80062448u;
    // 80062448: bl      0x801698F0
    {
            ctx->lr = 0x8006244Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006244C:
    ctx->pc = 0x8006244Cu;
    ctx->downcount -= 5;
    // 8006244C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062450:
    ctx->pc = 0x80062450u;
    // 80062450: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062454:
    ctx->pc = 0x80062454u;
    // 80062454: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062458:
    ctx->pc = 0x80062458u;
    // 80062458: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006245C:
    ctx->pc = 0x8006245Cu;
    // 8006245C: bl      0x801698F0
    {
            ctx->lr = 0x80062460u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062460:
    ctx->pc = 0x80062460u;
    ctx->downcount -= 24;
    // 80062460: li      r0, 50
    ctx->gpr[0] = (u32)(s32)(50);

label_80062464:
    ctx->pc = 0x80062464u;
    // 80062464: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062468:
    ctx->pc = 0x80062468u;
    // 80062468: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006246C:
    ctx->pc = 0x8006246Cu;
    // 8006246C: lis     r6, -32699
    ctx->gpr[6] = ((u32)(s32)(-32699) << 16);

label_80062470:
    ctx->pc = 0x80062470u;
    // 80062470: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062474:
    ctx->pc = 0x80062474u;
    // 80062474: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062478:
    ctx->pc = 0x80062478u;
    // 80062478: lwz     r7, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8006247C:
    ctx->pc = 0x8006247Cu;
    // 8006247C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062480:
    ctx->pc = 0x80062480u;
    // 80062480: lwz     r8, 1208(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1208);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062484:
    ctx->pc = 0x80062484u;
    // 80062484: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062488:
    ctx->pc = 0x80062488u;
    // 80062488: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006248C:
    ctx->pc = 0x8006248Cu;
    // 8006248C: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062490:
    ctx->pc = 0x80062490u;
    // 80062490: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062494:
    ctx->pc = 0x80062494u;
    // 80062494: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062498:
    ctx->pc = 0x80062498u;
    // 80062498: stw     r8, 15240(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(15240);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006249C:
    ctx->pc = 0x8006249Cu;
    // 8006249C: stw     r10, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800624A0:
    ctx->pc = 0x800624A0u;
    // 800624A0: stw     r0, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800624A4:
    ctx->pc = 0x800624A4u;
    // 800624A4: stw     r9, 12(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800624A8:
    ctx->pc = 0x800624A8u;
    // 800624A8: stw     r11, 16(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800624AC:
    ctx->pc = 0x800624ACu;
    // 800624AC: addi    r7, r7, 20
    ctx->gpr[7] = ctx->gpr[7] + (u32)(s32)(20);

label_800624B0:
    ctx->pc = 0x800624B0u;
    // 800624B0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800624B4:
    ctx->pc = 0x800624B4u;
    // 800624B4: stw     r7, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800624B8:
    ctx->pc = 0x800624B8u;
    // 800624B8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800624BC:
    ctx->pc = 0x800624BCu;
    // 800624BC: bl      0x801698F0
    {
            ctx->lr = 0x800624C0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800624C0:
    ctx->pc = 0x800624C0u;
    ctx->downcount -= 23;
    // 800624C0: li      r0, 45
    ctx->gpr[0] = (u32)(s32)(45);

label_800624C4:
    ctx->pc = 0x800624C4u;
    // 800624C4: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800624C8:
    ctx->pc = 0x800624C8u;
    // 800624C8: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800624CC:
    ctx->pc = 0x800624CCu;
    // 800624CC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800624D0:
    ctx->pc = 0x800624D0u;
    // 800624D0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800624D4:
    ctx->pc = 0x800624D4u;
    // 800624D4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800624D8:
    ctx->pc = 0x800624D8u;
    // 800624D8: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800624DC:
    ctx->pc = 0x800624DCu;
    // 800624DC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800624E0:
    ctx->pc = 0x800624E0u;
    // 800624E0: lwz     r8, 1088(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1088);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800624E4:
    ctx->pc = 0x800624E4u;
    // 800624E4: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800624E8:
    ctx->pc = 0x800624E8u;
    // 800624E8: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800624EC:
    ctx->pc = 0x800624ECu;
    // 800624EC: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800624F0:
    ctx->pc = 0x800624F0u;
    // 800624F0: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800624F4:
    ctx->pc = 0x800624F4u;
    // 800624F4: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800624F8:
    ctx->pc = 0x800624F8u;
    // 800624F8: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800624FC:
    ctx->pc = 0x800624FCu;
    // 800624FC: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062500:
    ctx->pc = 0x80062500u;
    // 80062500: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062504:
    ctx->pc = 0x80062504u;
    // 80062504: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062508:
    ctx->pc = 0x80062508u;
    // 80062508: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_8006250C:
    ctx->pc = 0x8006250Cu;
    // 8006250C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062510:
    ctx->pc = 0x80062510u;
    // 80062510: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062514:
    ctx->pc = 0x80062514u;
    // 80062514: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062518:
    ctx->pc = 0x80062518u;
    // 80062518: bl      0x801698F0
    {
            ctx->lr = 0x8006251Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006251C:
    ctx->pc = 0x8006251Cu;
    ctx->downcount -= 23;
    // 8006251C: li      r0, 47
    ctx->gpr[0] = (u32)(s32)(47);

label_80062520:
    ctx->pc = 0x80062520u;
    // 80062520: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062524:
    ctx->pc = 0x80062524u;
    // 80062524: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062528:
    ctx->pc = 0x80062528u;
    // 80062528: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006252C:
    ctx->pc = 0x8006252Cu;
    // 8006252C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062530:
    ctx->pc = 0x80062530u;
    // 80062530: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062534:
    ctx->pc = 0x80062534u;
    // 80062534: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062538:
    ctx->pc = 0x80062538u;
    // 80062538: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_8006253C:
    ctx->pc = 0x8006253Cu;
    // 8006253C: lwz     r8, 1136(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1136);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062540:
    ctx->pc = 0x80062540u;
    // 80062540: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062544:
    ctx->pc = 0x80062544u;
    // 80062544: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062548:
    ctx->pc = 0x80062548u;
    // 80062548: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006254C:
    ctx->pc = 0x8006254Cu;
    // 8006254C: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062550:
    ctx->pc = 0x80062550u;
    // 80062550: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062554:
    ctx->pc = 0x80062554u;
    // 80062554: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062558:
    ctx->pc = 0x80062558u;
    // 80062558: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006255C:
    ctx->pc = 0x8006255Cu;
    // 8006255C: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062560:
    ctx->pc = 0x80062560u;
    // 80062560: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062564:
    ctx->pc = 0x80062564u;
    // 80062564: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_80062568:
    ctx->pc = 0x80062568u;
    // 80062568: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006256C:
    ctx->pc = 0x8006256Cu;
    // 8006256C: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062570:
    ctx->pc = 0x80062570u;
    // 80062570: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062574:
    ctx->pc = 0x80062574u;
    // 80062574: bl      0x801698F0
    {
            ctx->lr = 0x80062578u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062578:
    ctx->pc = 0x80062578u;
    ctx->downcount -= 23;
    // 80062578: li      r0, 35
    ctx->gpr[0] = (u32)(s32)(35);

label_8006257C:
    ctx->pc = 0x8006257Cu;
    // 8006257C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062580:
    ctx->pc = 0x80062580u;
    // 80062580: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062584:
    ctx->pc = 0x80062584u;
    // 80062584: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062588:
    ctx->pc = 0x80062588u;
    // 80062588: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006258C:
    ctx->pc = 0x8006258Cu;
    // 8006258C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062590:
    ctx->pc = 0x80062590u;
    // 80062590: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062594:
    ctx->pc = 0x80062594u;
    // 80062594: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062598:
    ctx->pc = 0x80062598u;
    // 80062598: lwz     r8, 848(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(848);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006259C:
    ctx->pc = 0x8006259Cu;
    // 8006259C: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800625A0:
    ctx->pc = 0x800625A0u;
    // 800625A0: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800625A4:
    ctx->pc = 0x800625A4u;
    // 800625A4: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800625A8:
    ctx->pc = 0x800625A8u;
    // 800625A8: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800625AC:
    ctx->pc = 0x800625ACu;
    // 800625AC: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800625B0:
    ctx->pc = 0x800625B0u;
    // 800625B0: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800625B4:
    ctx->pc = 0x800625B4u;
    // 800625B4: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800625B8:
    ctx->pc = 0x800625B8u;
    // 800625B8: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800625BC:
    ctx->pc = 0x800625BCu;
    // 800625BC: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800625C0:
    ctx->pc = 0x800625C0u;
    // 800625C0: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_800625C4:
    ctx->pc = 0x800625C4u;
    // 800625C4: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800625C8:
    ctx->pc = 0x800625C8u;
    // 800625C8: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800625CC:
    ctx->pc = 0x800625CCu;
    // 800625CC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800625D0:
    ctx->pc = 0x800625D0u;
    // 800625D0: bl      0x801698F0
    {
            ctx->lr = 0x800625D4u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800625D4:
    ctx->pc = 0x800625D4u;
    ctx->downcount -= 23;
    // 800625D4: li      r0, 43
    ctx->gpr[0] = (u32)(s32)(43);

label_800625D8:
    ctx->pc = 0x800625D8u;
    // 800625D8: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800625DC:
    ctx->pc = 0x800625DCu;
    // 800625DC: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800625E0:
    ctx->pc = 0x800625E0u;
    // 800625E0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800625E4:
    ctx->pc = 0x800625E4u;
    // 800625E4: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800625E8:
    ctx->pc = 0x800625E8u;
    // 800625E8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800625EC:
    ctx->pc = 0x800625ECu;
    // 800625EC: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800625F0:
    ctx->pc = 0x800625F0u;
    // 800625F0: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800625F4:
    ctx->pc = 0x800625F4u;
    // 800625F4: lwz     r8, 1040(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1040);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800625F8:
    ctx->pc = 0x800625F8u;
    // 800625F8: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800625FC:
    ctx->pc = 0x800625FCu;
    // 800625FC: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062600:
    ctx->pc = 0x80062600u;
    // 80062600: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062604:
    ctx->pc = 0x80062604u;
    // 80062604: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062608:
    ctx->pc = 0x80062608u;
    // 80062608: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006260C:
    ctx->pc = 0x8006260Cu;
    // 8006260C: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062610:
    ctx->pc = 0x80062610u;
    // 80062610: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062614:
    ctx->pc = 0x80062614u;
    // 80062614: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062618:
    ctx->pc = 0x80062618u;
    // 80062618: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006261C:
    ctx->pc = 0x8006261Cu;
    // 8006261C: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_80062620:
    ctx->pc = 0x80062620u;
    // 80062620: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062624:
    ctx->pc = 0x80062624u;
    // 80062624: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062628:
    ctx->pc = 0x80062628u;
    // 80062628: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006262C:
    ctx->pc = 0x8006262Cu;
    // 8006262C: bl      0x801698F0
    {
            ctx->lr = 0x80062630u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062630:
    ctx->pc = 0x80062630u;
    ctx->downcount -= 23;
    // 80062630: li      r0, 36
    ctx->gpr[0] = (u32)(s32)(36);

label_80062634:
    ctx->pc = 0x80062634u;
    // 80062634: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062638:
    ctx->pc = 0x80062638u;
    // 80062638: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006263C:
    ctx->pc = 0x8006263Cu;
    // 8006263C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062640:
    ctx->pc = 0x80062640u;
    // 80062640: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062644:
    ctx->pc = 0x80062644u;
    // 80062644: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062648:
    ctx->pc = 0x80062648u;
    // 80062648: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006264C:
    ctx->pc = 0x8006264Cu;
    // 8006264C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062650:
    ctx->pc = 0x80062650u;
    // 80062650: lwz     r8, 872(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(872);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062654:
    ctx->pc = 0x80062654u;
    // 80062654: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062658:
    ctx->pc = 0x80062658u;
    // 80062658: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006265C:
    ctx->pc = 0x8006265Cu;
    // 8006265C: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062660:
    ctx->pc = 0x80062660u;
    // 80062660: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062664:
    ctx->pc = 0x80062664u;
    // 80062664: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062668:
    ctx->pc = 0x80062668u;
    // 80062668: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006266C:
    ctx->pc = 0x8006266Cu;
    // 8006266C: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062670:
    ctx->pc = 0x80062670u;
    // 80062670: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062674:
    ctx->pc = 0x80062674u;
    // 80062674: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062678:
    ctx->pc = 0x80062678u;
    // 80062678: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_8006267C:
    ctx->pc = 0x8006267Cu;
    // 8006267C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062680:
    ctx->pc = 0x80062680u;
    // 80062680: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062684:
    ctx->pc = 0x80062684u;
    // 80062684: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062688:
    ctx->pc = 0x80062688u;
    // 80062688: bl      0x801698F0
    {
            ctx->lr = 0x8006268Cu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_8006268C:
    ctx->pc = 0x8006268Cu;
    ctx->downcount -= 23;
    // 8006268C: li      r0, 44
    ctx->gpr[0] = (u32)(s32)(44);

label_80062690:
    ctx->pc = 0x80062690u;
    // 80062690: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062694:
    ctx->pc = 0x80062694u;
    // 80062694: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062698:
    ctx->pc = 0x80062698u;
    // 80062698: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_8006269C:
    ctx->pc = 0x8006269Cu;
    // 8006269C: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800626A0:
    ctx->pc = 0x800626A0u;
    // 800626A0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800626A4:
    ctx->pc = 0x800626A4u;
    // 800626A4: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800626A8:
    ctx->pc = 0x800626A8u;
    // 800626A8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800626AC:
    ctx->pc = 0x800626ACu;
    // 800626AC: lwz     r8, 1064(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1064);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800626B0:
    ctx->pc = 0x800626B0u;
    // 800626B0: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800626B4:
    ctx->pc = 0x800626B4u;
    // 800626B4: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800626B8:
    ctx->pc = 0x800626B8u;
    // 800626B8: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800626BC:
    ctx->pc = 0x800626BCu;
    // 800626BC: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800626C0:
    ctx->pc = 0x800626C0u;
    // 800626C0: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800626C4:
    ctx->pc = 0x800626C4u;
    // 800626C4: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800626C8:
    ctx->pc = 0x800626C8u;
    // 800626C8: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800626CC:
    ctx->pc = 0x800626CCu;
    // 800626CC: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800626D0:
    ctx->pc = 0x800626D0u;
    // 800626D0: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800626D4:
    ctx->pc = 0x800626D4u;
    // 800626D4: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_800626D8:
    ctx->pc = 0x800626D8u;
    // 800626D8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800626DC:
    ctx->pc = 0x800626DCu;
    // 800626DC: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800626E0:
    ctx->pc = 0x800626E0u;
    // 800626E0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800626E4:
    ctx->pc = 0x800626E4u;
    // 800626E4: bl      0x801698F0
    {
            ctx->lr = 0x800626E8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800626E8:
    ctx->pc = 0x800626E8u;
    ctx->downcount -= 26;
    // 800626E8: li      r0, 37
    ctx->gpr[0] = (u32)(s32)(37);

label_800626EC:
    ctx->pc = 0x800626ECu;
    // 800626EC: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800626F0:
    ctx->pc = 0x800626F0u;
    // 800626F0: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800626F4:
    ctx->pc = 0x800626F4u;
    // 800626F4: addi    r9, r9, 31376
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31376);

label_800626F8:
    ctx->pc = 0x800626F8u;
    // 800626F8: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800626FC:
    ctx->pc = 0x800626FCu;
    // 800626FC: stw     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062700:
    ctx->pc = 0x80062700u;
    // 80062700: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062704:
    ctx->pc = 0x80062704u;
    // 80062704: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062708:
    ctx->pc = 0x80062708u;
    // 80062708: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006270C:
    ctx->pc = 0x8006270Cu;
    // 8006270C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062710:
    ctx->pc = 0x80062710u;
    // 80062710: lwz     r8, 896(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(896);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062714:
    ctx->pc = 0x80062714u;
    // 80062714: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062718:
    ctx->pc = 0x80062718u;
    // 80062718: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006271C:
    ctx->pc = 0x8006271Cu;
    // 8006271C: lwz     r9, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062720:
    ctx->pc = 0x80062720u;
    // 80062720: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062724:
    ctx->pc = 0x80062724u;
    // 80062724: lwz     r10, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062728:
    ctx->pc = 0x80062728u;
    // 80062728: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006272C:
    ctx->pc = 0x8006272Cu;
    // 8006272C: stw     r0, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062730:
    ctx->pc = 0x80062730u;
    // 80062730: stw     r9, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062734:
    ctx->pc = 0x80062734u;
    // 80062734: stw     r11, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062738:
    ctx->pc = 0x80062738u;
    // 80062738: stw     r10, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006273C:
    ctx->pc = 0x8006273Cu;
    // 8006273C: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_80062740:
    ctx->pc = 0x80062740u;
    // 80062740: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062744:
    ctx->pc = 0x80062744u;
    // 80062744: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062748:
    ctx->pc = 0x80062748u;
    // 80062748: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006274C:
    ctx->pc = 0x8006274Cu;
    // 8006274C: bl      0x801698F0
    {
            ctx->lr = 0x80062750u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062750:
    ctx->pc = 0x80062750u;
    ctx->downcount -= 23;
    // 80062750: li      r0, 41
    ctx->gpr[0] = (u32)(s32)(41);

label_80062754:
    ctx->pc = 0x80062754u;
    // 80062754: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062758:
    ctx->pc = 0x80062758u;
    // 80062758: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006275C:
    ctx->pc = 0x8006275Cu;
    // 8006275C: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062760:
    ctx->pc = 0x80062760u;
    // 80062760: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062764:
    ctx->pc = 0x80062764u;
    // 80062764: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062768:
    ctx->pc = 0x80062768u;
    // 80062768: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_8006276C:
    ctx->pc = 0x8006276Cu;
    // 8006276C: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062770:
    ctx->pc = 0x80062770u;
    // 80062770: lwz     r8, 992(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(992);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062774:
    ctx->pc = 0x80062774u;
    // 80062774: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062778:
    ctx->pc = 0x80062778u;
    // 80062778: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006277C:
    ctx->pc = 0x8006277Cu;
    // 8006277C: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062780:
    ctx->pc = 0x80062780u;
    // 80062780: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062784:
    ctx->pc = 0x80062784u;
    // 80062784: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062788:
    ctx->pc = 0x80062788u;
    // 80062788: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_8006278C:
    ctx->pc = 0x8006278Cu;
    // 8006278C: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062790:
    ctx->pc = 0x80062790u;
    // 80062790: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062794:
    ctx->pc = 0x80062794u;
    // 80062794: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062798:
    ctx->pc = 0x80062798u;
    // 80062798: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_8006279C:
    ctx->pc = 0x8006279Cu;
    // 8006279C: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800627A0:
    ctx->pc = 0x800627A0u;
    // 800627A0: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800627A4:
    ctx->pc = 0x800627A4u;
    // 800627A4: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800627A8:
    ctx->pc = 0x800627A8u;
    // 800627A8: bl      0x801698F0
    {
            ctx->lr = 0x800627ACu;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800627AC:
    ctx->pc = 0x800627ACu;
    ctx->downcount -= 23;
    // 800627AC: li      r0, 38
    ctx->gpr[0] = (u32)(s32)(38);

label_800627B0:
    ctx->pc = 0x800627B0u;
    // 800627B0: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_800627B4:
    ctx->pc = 0x800627B4u;
    // 800627B4: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800627B8:
    ctx->pc = 0x800627B8u;
    // 800627B8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800627BC:
    ctx->pc = 0x800627BCu;
    // 800627BC: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800627C0:
    ctx->pc = 0x800627C0u;
    // 800627C0: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800627C4:
    ctx->pc = 0x800627C4u;
    // 800627C4: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800627C8:
    ctx->pc = 0x800627C8u;
    // 800627C8: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800627CC:
    ctx->pc = 0x800627CCu;
    // 800627CC: lwz     r8, 920(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(920);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800627D0:
    ctx->pc = 0x800627D0u;
    // 800627D0: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800627D4:
    ctx->pc = 0x800627D4u;
    // 800627D4: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800627D8:
    ctx->pc = 0x800627D8u;
    // 800627D8: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800627DC:
    ctx->pc = 0x800627DCu;
    // 800627DC: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800627E0:
    ctx->pc = 0x800627E0u;
    // 800627E0: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800627E4:
    ctx->pc = 0x800627E4u;
    // 800627E4: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800627E8:
    ctx->pc = 0x800627E8u;
    // 800627E8: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800627EC:
    ctx->pc = 0x800627ECu;
    // 800627EC: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800627F0:
    ctx->pc = 0x800627F0u;
    // 800627F0: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800627F4:
    ctx->pc = 0x800627F4u;
    // 800627F4: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_800627F8:
    ctx->pc = 0x800627F8u;
    // 800627F8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800627FC:
    ctx->pc = 0x800627FCu;
    // 800627FC: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062800:
    ctx->pc = 0x80062800u;
    // 80062800: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062804:
    ctx->pc = 0x80062804u;
    // 80062804: bl      0x801698F0
    {
            ctx->lr = 0x80062808u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062808:
    ctx->pc = 0x80062808u;
    ctx->downcount -= 23;
    // 80062808: li      r0, 46
    ctx->gpr[0] = (u32)(s32)(46);

label_8006280C:
    ctx->pc = 0x8006280Cu;
    // 8006280C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062810:
    ctx->pc = 0x80062810u;
    // 80062810: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062814:
    ctx->pc = 0x80062814u;
    // 80062814: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062818:
    ctx->pc = 0x80062818u;
    // 80062818: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006281C:
    ctx->pc = 0x8006281Cu;
    // 8006281C: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062820:
    ctx->pc = 0x80062820u;
    // 80062820: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062824:
    ctx->pc = 0x80062824u;
    // 80062824: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062828:
    ctx->pc = 0x80062828u;
    // 80062828: lwz     r8, 1112(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1112);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_8006282C:
    ctx->pc = 0x8006282Cu;
    // 8006282C: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062830:
    ctx->pc = 0x80062830u;
    // 80062830: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062834:
    ctx->pc = 0x80062834u;
    // 80062834: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062838:
    ctx->pc = 0x80062838u;
    // 80062838: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006283C:
    ctx->pc = 0x8006283Cu;
    // 8006283C: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062840:
    ctx->pc = 0x80062840u;
    // 80062840: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062844:
    ctx->pc = 0x80062844u;
    // 80062844: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062848:
    ctx->pc = 0x80062848u;
    // 80062848: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006284C:
    ctx->pc = 0x8006284Cu;
    // 8006284C: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062850:
    ctx->pc = 0x80062850u;
    // 80062850: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_80062854:
    ctx->pc = 0x80062854u;
    // 80062854: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062858:
    ctx->pc = 0x80062858u;
    // 80062858: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_8006285C:
    ctx->pc = 0x8006285Cu;
    // 8006285C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062860:
    ctx->pc = 0x80062860u;
    // 80062860: bl      0x801698F0
    {
            ctx->lr = 0x80062864u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062864:
    ctx->pc = 0x80062864u;
    ctx->downcount -= 23;
    // 80062864: li      r0, 42
    ctx->gpr[0] = (u32)(s32)(42);

label_80062868:
    ctx->pc = 0x80062868u;
    // 80062868: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006286C:
    ctx->pc = 0x8006286Cu;
    // 8006286C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062870:
    ctx->pc = 0x80062870u;
    // 80062870: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062874:
    ctx->pc = 0x80062874u;
    // 80062874: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062878:
    ctx->pc = 0x80062878u;
    // 80062878: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_8006287C:
    ctx->pc = 0x8006287Cu;
    // 8006287C: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062880:
    ctx->pc = 0x80062880u;
    // 80062880: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_80062884:
    ctx->pc = 0x80062884u;
    // 80062884: lwz     r8, 1016(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(1016);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062888:
    ctx->pc = 0x80062888u;
    // 80062888: lwz     r10, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_8006288C:
    ctx->pc = 0x8006288Cu;
    // 8006288C: lwz     r0, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062890:
    ctx->pc = 0x80062890u;
    // 80062890: lwz     r9, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062894:
    ctx->pc = 0x80062894u;
    // 80062894: lwz     r11, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062898:
    ctx->pc = 0x80062898u;
    // 80062898: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006289C:
    ctx->pc = 0x8006289Cu;
    // 8006289C: stw     r10, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800628A0:
    ctx->pc = 0x800628A0u;
    // 800628A0: stw     r0, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800628A4:
    ctx->pc = 0x800628A4u;
    // 800628A4: stw     r9, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800628A8:
    ctx->pc = 0x800628A8u;
    // 800628A8: stw     r11, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800628AC:
    ctx->pc = 0x800628ACu;
    // 800628AC: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_800628B0:
    ctx->pc = 0x800628B0u;
    // 800628B0: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_800628B4:
    ctx->pc = 0x800628B4u;
    // 800628B4: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800628B8:
    ctx->pc = 0x800628B8u;
    // 800628B8: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_800628BC:
    ctx->pc = 0x800628BCu;
    // 800628BC: bl      0x801698F0
    {
            ctx->lr = 0x800628C0u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_800628C0:
    ctx->pc = 0x800628C0u;
    ctx->downcount -= 26;
    // 800628C0: li      r0, 39
    ctx->gpr[0] = (u32)(s32)(39);

label_800628C4:
    ctx->pc = 0x800628C4u;
    // 800628C4: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_800628C8:
    ctx->pc = 0x800628C8u;
    // 800628C8: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800628CC:
    ctx->pc = 0x800628CCu;
    // 800628CC: addi    r9, r9, 31400
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31400);

label_800628D0:
    ctx->pc = 0x800628D0u;
    // 800628D0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800628D4:
    ctx->pc = 0x800628D4u;
    // 800628D4: stw     r9, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800628D8:
    ctx->pc = 0x800628D8u;
    // 800628D8: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800628DC:
    ctx->pc = 0x800628DCu;
    // 800628DC: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800628E0:
    ctx->pc = 0x800628E0u;
    // 800628E0: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800628E4:
    ctx->pc = 0x800628E4u;
    // 800628E4: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800628E8:
    ctx->pc = 0x800628E8u;
    // 800628E8: lwz     r8, 944(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(944);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800628EC:
    ctx->pc = 0x800628ECu;
    // 800628EC: or   r3, r27, r27
    {
        ctx->gpr[3] = ctx->gpr[27] | ctx->gpr[27];
    }

label_800628F0:
    ctx->pc = 0x800628F0u;
    // 800628F0: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800628F4:
    ctx->pc = 0x800628F4u;
    // 800628F4: lwz     r9, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800628F8:
    ctx->pc = 0x800628F8u;
    // 800628F8: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800628FC:
    ctx->pc = 0x800628FCu;
    // 800628FC: lwz     r10, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062900:
    ctx->pc = 0x80062900u;
    // 80062900: stw     r8, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062904:
    ctx->pc = 0x80062904u;
    // 80062904: stw     r0, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062908:
    ctx->pc = 0x80062908u;
    // 80062908: stw     r9, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006290C:
    ctx->pc = 0x8006290Cu;
    // 8006290C: stw     r11, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062910:
    ctx->pc = 0x80062910u;
    // 80062910: stw     r10, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062914:
    ctx->pc = 0x80062914u;
    // 80062914: addi    r6, r6, 20
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(20);

label_80062918:
    ctx->pc = 0x80062918u;
    // 80062918: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_8006291C:
    ctx->pc = 0x8006291Cu;
    // 8006291C: stw     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062920:
    ctx->pc = 0x80062920u;
    // 80062920: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062924:
    ctx->pc = 0x80062924u;
    // 80062924: bl      0x801698F0
    {
            ctx->lr = 0x80062928u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062928:
    ctx->pc = 0x80062928u;
    ctx->downcount -= 22;
    // 80062928: li      r0, 40
    ctx->gpr[0] = (u32)(s32)(40);

label_8006292C:
    ctx->pc = 0x8006292Cu;
    // 8006292C: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062930:
    ctx->pc = 0x80062930u;
    // 80062930: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062934:
    ctx->pc = 0x80062934u;
    // 80062934: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062938:
    ctx->pc = 0x80062938u;
    // 80062938: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_8006293C:
    ctx->pc = 0x8006293Cu;
    // 8006293C: lwz     r5, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80062940:
    ctx->pc = 0x80062940u;
    // 80062940: lwz     r6, 48(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(48);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062944:
    ctx->pc = 0x80062944u;
    // 80062944: lwz     r10, 968(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(968);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062948:
    ctx->pc = 0x80062948u;
    // 80062948: addi    r3, r5, 20
    ctx->gpr[3] = ctx->gpr[5] + (u32)(s32)(20);

label_8006294C:
    ctx->pc = 0x8006294Cu;
    // 8006294C: lwz     r8, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062950:
    ctx->pc = 0x80062950u;
    // 80062950: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062954:
    ctx->pc = 0x80062954u;
    // 80062954: lwz     r0, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062958:
    ctx->pc = 0x80062958u;
    // 80062958: lwz     r9, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_8006295C:
    ctx->pc = 0x8006295Cu;
    // 8006295C: lwz     r11, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062960:
    ctx->pc = 0x80062960u;
    // 80062960: stw     r10, 0(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062964:
    ctx->pc = 0x80062964u;
    // 80062964: stw     r0, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062968:
    ctx->pc = 0x80062968u;
    // 80062968: stw     r9, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_8006296C:
    ctx->pc = 0x8006296Cu;
    // 8006296C: stw     r11, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062970:
    ctx->pc = 0x80062970u;
    // 80062970: stw     r8, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062974:
    ctx->pc = 0x80062974u;
    // 80062974: stw     r10, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062978:
    ctx->pc = 0x80062978u;
    // 80062978: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_8006297C:
    ctx->pc = 0x8006297Cu;
    // 8006297C: bl      0x801698F0
    {
            ctx->lr = 0x80062980u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062980:
    ctx->pc = 0x80062980u;
    ctx->downcount -= 267;
    // 80062980: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80062984:
    ctx->pc = 0x80062984u;
    // 80062984: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80062988:
    ctx->pc = 0x80062988u;
    // 80062988: lwz     r0, 31440(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31440);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006298C:
    ctx->pc = 0x8006298Cu;
    // 8006298C: addi    r11, r10, 31468
    ctx->gpr[11] = ctx->gpr[10] + (u32)(s32)(31468);

label_80062990:
    ctx->pc = 0x80062990u;
    // 80062990: addi    r9, r9, 31440
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31440);

label_80062994:
    ctx->pc = 0x80062994u;
    // 80062994: lwz     r10, 31468(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(31468);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062998:
    ctx->pc = 0x80062998u;
    // 80062998: lwz     r5, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_8006299C:
    ctx->pc = 0x8006299Cu;
    // 8006299C: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_800629A0:
    ctx->pc = 0x800629A0u;
    // 800629A0: lwz     r3, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_800629A4:
    ctx->pc = 0x800629A4u;
    // 800629A4: addi    r30, r8, 15540
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(15540);

label_800629A8:
    ctx->pc = 0x800629A8u;
    // 800629A8: stw     r5, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_800629AC:
    ctx->pc = 0x800629ACu;
    // 800629AC: lis     r4, -32738
    ctx->gpr[4] = ((u32)(s32)(-32738) << 16);

label_800629B0:
    ctx->pc = 0x800629B0u;
    // 800629B0: lwz     r6, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800629B4:
    ctx->pc = 0x800629B4u;
    // 800629B4: lis     r5, -32738
    ctx->gpr[5] = ((u32)(s32)(-32738) << 16);

label_800629B8:
    ctx->pc = 0x800629B8u;
    // 800629B8: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_800629BC:
    ctx->pc = 0x800629BCu;
    // 800629BC: lis     r31, -32738
    ctx->gpr[31] = ((u32)(s32)(-32738) << 16);

label_800629C0:
    ctx->pc = 0x800629C0u;
    // 800629C0: lwz     r7, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800629C4:
    ctx->pc = 0x800629C4u;
    // 800629C4: addi    r28, r31, 31684
    ctx->gpr[28] = ctx->gpr[31] + (u32)(s32)(31684);

label_800629C8:
    ctx->pc = 0x800629C8u;
    // 800629C8: stw     r0, 15540(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(15540);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800629CC:
    ctx->pc = 0x800629CCu;
    // 800629CC: lis     r14, -32738
    ctx->gpr[14] = ((u32)(s32)(-32738) << 16);

label_800629D0:
    ctx->pc = 0x800629D0u;
    // 800629D0: stw     r9, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_800629D4:
    ctx->pc = 0x800629D4u;
    // 800629D4: addi    r27, r14, 31712
    ctx->gpr[27] = ctx->gpr[14] + (u32)(s32)(31712);

label_800629D8:
    ctx->pc = 0x800629D8u;
    // 800629D8: stw     r10, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800629DC:
    ctx->pc = 0x800629DCu;
    // 800629DC: addi    r9, r5, 31496
    ctx->gpr[9] = ctx->gpr[5] + (u32)(s32)(31496);

label_800629E0:
    ctx->pc = 0x800629E0u;
    // 800629E0: stw     r0, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800629E4:
    ctx->pc = 0x800629E4u;
    // 800629E4: addi    r10, r4, 31524
    ctx->gpr[10] = ctx->gpr[4] + (u32)(s32)(31524);

label_800629E8:
    ctx->pc = 0x800629E8u;
    // 800629E8: stw     r3, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800629EC:
    ctx->pc = 0x800629ECu;
    // 800629EC: lis     r12, -32738
    ctx->gpr[12] = ((u32)(s32)(-32738) << 16);

label_800629F0:
    ctx->pc = 0x800629F0u;
    // 800629F0: stw     r6, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800629F4:
    ctx->pc = 0x800629F4u;
    // 800629F4: addi    r26, r12, 31740
    ctx->gpr[26] = ctx->gpr[12] + (u32)(s32)(31740);

label_800629F8:
    ctx->pc = 0x800629F8u;
    // 800629F8: stw     r7, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_800629FC:
    ctx->pc = 0x800629FCu;
    // 800629FC: stw     r6, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062A00:
    ctx->pc = 0x80062A00u;
    // 80062A00: lwz     r0, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062A04:
    ctx->pc = 0x80062A04u;
    // 80062A04: lwz     r8, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062A08:
    ctx->pc = 0x80062A08u;
    // 80062A08: lwz     r6, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062A0C:
    ctx->pc = 0x80062A0Cu;
    // 80062A0C: stw     r8, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062A10:
    ctx->pc = 0x80062A10u;
    // 80062A10: addi    r8, r25, 31552
    ctx->gpr[8] = ctx->gpr[25] + (u32)(s32)(31552);

label_80062A14:
    ctx->pc = 0x80062A14u;
    // 80062A14: stw     r3, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062A18:
    ctx->pc = 0x80062A18u;
    // 80062A18: lwz     r25, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062A1C:
    ctx->pc = 0x80062A1Cu;
    // 80062A1C: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80062A20:
    ctx->pc = 0x80062A20u;
    // 80062A20: lwz     r11, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062A24:
    ctx->pc = 0x80062A24u;
    // 80062A24: addi    r7, r3, 31580
    ctx->gpr[7] = ctx->gpr[3] + (u32)(s32)(31580);

label_80062A28:
    ctx->pc = 0x80062A28u;
    // 80062A28: stw     r6, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062A2C:
    ctx->pc = 0x80062A2Cu;
    // 80062A2C: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80062A30:
    ctx->pc = 0x80062A30u;
    // 80062A30: stw     r11, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062A34:
    ctx->pc = 0x80062A34u;
    // 80062A34: addi    r6, r3, 31608
    ctx->gpr[6] = ctx->gpr[3] + (u32)(s32)(31608);

label_80062A38:
    ctx->pc = 0x80062A38u;
    // 80062A38: lwz     r11, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062A3C:
    ctx->pc = 0x80062A3Cu;
    // 80062A3C: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80062A40:
    ctx->pc = 0x80062A40u;
    // 80062A40: stw     r25, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062A44:
    ctx->pc = 0x80062A44u;
    // 80062A44: addi    r29, r3, 31656
    ctx->gpr[29] = ctx->gpr[3] + (u32)(s32)(31656);

label_80062A48:
    ctx->pc = 0x80062A48u;
    // 80062A48: stw     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062A4C:
    ctx->pc = 0x80062A4Cu;
    // 80062A4C: lis     r25, -32738
    ctx->gpr[25] = ((u32)(s32)(-32738) << 16);

label_80062A50:
    ctx->pc = 0x80062A50u;
    // 80062A50: stwu     r11, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
        ctx->gpr[30] = ea;
    }

label_80062A54:
    ctx->pc = 0x80062A54u;
    // 80062A54: lwz     r5, 31496(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(31496);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80062A58:
    ctx->pc = 0x80062A58u;
    // 80062A58: addi    r11, r25, 31628
    ctx->gpr[11] = ctx->gpr[25] + (u32)(s32)(31628);

label_80062A5C:
    ctx->pc = 0x80062A5Cu;
    // 80062A5C: lwz     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062A60:
    ctx->pc = 0x80062A60u;
    // 80062A60: stw     r5, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80062A64:
    ctx->pc = 0x80062A64u;
    // 80062A64: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062A68:
    ctx->pc = 0x80062A68u;
    // 80062A68: lwz     r5, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80062A6C:
    ctx->pc = 0x80062A6Cu;
    // 80062A6C: stw     r5, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80062A70:
    ctx->pc = 0x80062A70u;
    // 80062A70: lwz     r25, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062A74:
    ctx->pc = 0x80062A74u;
    // 80062A74: lwz     r3, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80062A78:
    ctx->pc = 0x80062A78u;
    // 80062A78: stw     r25, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062A7C:
    ctx->pc = 0x80062A7Cu;
    // 80062A7C: lwz     r5, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80062A80:
    ctx->pc = 0x80062A80u;
    // 80062A80: lwz     r0, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062A84:
    ctx->pc = 0x80062A84u;
    // 80062A84: lwz     r25, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062A88:
    ctx->pc = 0x80062A88u;
    // 80062A88: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062A8C:
    ctx->pc = 0x80062A8Cu;
    // 80062A8C: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062A90:
    ctx->pc = 0x80062A90u;
    // 80062A90: stw     r3, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062A94:
    ctx->pc = 0x80062A94u;
    // 80062A94: stw     r5, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80062A98:
    ctx->pc = 0x80062A98u;
    // 80062A98: lis     r3, -32738
    ctx->gpr[3] = ((u32)(s32)(-32738) << 16);

label_80062A9C:
    ctx->pc = 0x80062A9Cu;
    // 80062A9C: stw     r9, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062AA0:
    ctx->pc = 0x80062AA0u;
    // 80062AA0: or   r0, r3, r3
    {
        ctx->gpr[0] = ctx->gpr[3] | ctx->gpr[3];
    }

label_80062AA4:
    ctx->pc = 0x80062AA4u;
    // 80062AA4: stw     r25, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062AA8:
    ctx->pc = 0x80062AA8u;
    // 80062AA8: addi    r9, r3, 31768
    ctx->gpr[9] = ctx->gpr[3] + (u32)(s32)(31768);

label_80062AAC:
    ctx->pc = 0x80062AACu;
    // 80062AAC: lwz     r5, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80062AB0:
    ctx->pc = 0x80062AB0u;
    // 80062AB0: lis     r25, -32738
    ctx->gpr[25] = ((u32)(s32)(-32738) << 16);

label_80062AB4:
    ctx->pc = 0x80062AB4u;
    // 80062AB4: lwz     r3, 4(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(4);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80062AB8:
    ctx->pc = 0x80062AB8u;
    // 80062AB8: mtctr    r25
    ctx->ctr = ctx->gpr[25];

label_80062ABC:
    ctx->pc = 0x80062ABCu;
    // 80062ABC: stwu     r5, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
        ctx->gpr[30] = ea;
    }

label_80062AC0:
    ctx->pc = 0x80062AC0u;
    // 80062AC0: stw     r3, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062AC4:
    ctx->pc = 0x80062AC4u;
    // 80062AC4: lwz     r5, 8(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(8);
        ctx->gpr[5] = mem_read32(ctx, ea);
    }

label_80062AC8:
    ctx->pc = 0x80062AC8u;
    // 80062AC8: lwz     r25, 12(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(12);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062ACC:
    ctx->pc = 0x80062ACCu;
    // 80062ACC: lwz     r4, 31524(r4)
    {
        u32 ea = ctx->gpr[4] + (u32)(s32)(31524);
        ctx->gpr[4] = mem_read32(ctx, ea);
    }

label_80062AD0:
    ctx->pc = 0x80062AD0u;
    // 80062AD0: lwz     r3, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->gpr[3] = mem_read32(ctx, ea);
    }

label_80062AD4:
    ctx->pc = 0x80062AD4u;
    // 80062AD4: stw     r4, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        mem_write32(ctx, ea, (u32)ctx->gpr[4]);
    }

label_80062AD8:
    ctx->pc = 0x80062AD8u;
    // 80062AD8: stw     r5, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80062ADC:
    ctx->pc = 0x80062ADCu;
    // 80062ADC: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062AE0:
    ctx->pc = 0x80062AE0u;
    // 80062AE0: stw     r25, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062AE4:
    ctx->pc = 0x80062AE4u;
    // 80062AE4: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062AE8:
    ctx->pc = 0x80062AE8u;
    // 80062AE8: stw     r3, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062AEC:
    ctx->pc = 0x80062AECu;
    // 80062AEC: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80062AF0:
    ctx->pc = 0x80062AF0u;
    // 80062AF0: lwz     r25, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062AF4:
    ctx->pc = 0x80062AF4u;
    // 80062AF4: stw     r25, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062AF8:
    ctx->pc = 0x80062AF8u;
    // 80062AF8: lwz     r25, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062AFC:
    ctx->pc = 0x80062AFCu;
    // 80062AFC: stw     r25, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062B00:
    ctx->pc = 0x80062B00u;
    // 80062B00: lwz     r25, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B04:
    ctx->pc = 0x80062B04u;
    // 80062B04: stw     r25, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062B08:
    ctx->pc = 0x80062B08u;
    // 80062B08: lwz     r25, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B0C:
    ctx->pc = 0x80062B0Cu;
    // 80062B0C: stwu     r25, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
        ctx->gpr[30] = ea;
    }

label_80062B10:
    ctx->pc = 0x80062B10u;
    // 80062B10: lwz     r10, 16(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(16);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B14:
    ctx->pc = 0x80062B14u;
    // 80062B14: stw     r10, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062B18:
    ctx->pc = 0x80062B18u;
    // 80062B18: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80062B1C:
    ctx->pc = 0x80062B1Cu;
    // 80062B1C: lwz     r25, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B20:
    ctx->pc = 0x80062B20u;
    // 80062B20: lwz     r10, 31552(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(31552);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B24:
    ctx->pc = 0x80062B24u;
    // 80062B24: stw     r10, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062B28:
    ctx->pc = 0x80062B28u;
    // 80062B28: stw     r25, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062B2C:
    ctx->pc = 0x80062B2Cu;
    // 80062B2C: lwz     r10, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B30:
    ctx->pc = 0x80062B30u;
    // 80062B30: stw     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062B34:
    ctx->pc = 0x80062B34u;
    // 80062B34: lwz     r25, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B38:
    ctx->pc = 0x80062B38u;
    // 80062B38: stw     r25, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062B3C:
    ctx->pc = 0x80062B3Cu;
    // 80062B3C: lwz     r25, 16(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(16);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B40:
    ctx->pc = 0x80062B40u;
    // 80062B40: lwz     r10, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B44:
    ctx->pc = 0x80062B44u;
    // 80062B44: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062B48:
    ctx->pc = 0x80062B48u;
    // 80062B48: stw     r25, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062B4C:
    ctx->pc = 0x80062B4Cu;
    // 80062B4C: lwz     r10, 4(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B50:
    ctx->pc = 0x80062B50u;
    // 80062B50: lwz     r25, 8(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(8);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B54:
    ctx->pc = 0x80062B54u;
    // 80062B54: lwz     r8, 12(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(12);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062B58:
    ctx->pc = 0x80062B58u;
    // 80062B58: stw     r10, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062B5C:
    ctx->pc = 0x80062B5Cu;
    // 80062B5C: stw     r8, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062B60:
    ctx->pc = 0x80062B60u;
    // 80062B60: lis     r10, -32738
    ctx->gpr[10] = ((u32)(s32)(-32738) << 16);

label_80062B64:
    ctx->pc = 0x80062B64u;
    // 80062B64: lwz     r8, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062B68:
    ctx->pc = 0x80062B68u;
    // 80062B68: stw     r25, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062B6C:
    ctx->pc = 0x80062B6Cu;
    // 80062B6C: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80062B70:
    ctx->pc = 0x80062B70u;
    // 80062B70: lwz     r10, 31580(r10)
    {
        u32 ea = ctx->gpr[10] + (u32)(s32)(31580);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B74:
    ctx->pc = 0x80062B74u;
    // 80062B74: lwz     r25, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B78:
    ctx->pc = 0x80062B78u;
    // 80062B78: stw     r10, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062B7C:
    ctx->pc = 0x80062B7Cu;
    // 80062B7C: stw     r25, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062B80:
    ctx->pc = 0x80062B80u;
    // 80062B80: lwz     r8, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062B84:
    ctx->pc = 0x80062B84u;
    // 80062B84: stw     r8, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062B88:
    ctx->pc = 0x80062B88u;
    // 80062B88: lwz     r8, 16(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062B8C:
    ctx->pc = 0x80062B8Cu;
    // 80062B8C: lwz     r10, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B90:
    ctx->pc = 0x80062B90u;
    // 80062B90: stw     r10, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062B94:
    ctx->pc = 0x80062B94u;
    // 80062B94: lwz     r10, 4(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062B98:
    ctx->pc = 0x80062B98u;
    // 80062B98: lwz     r25, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062B9C:
    ctx->pc = 0x80062B9Cu;
    // 80062B9C: stw     r25, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062BA0:
    ctx->pc = 0x80062BA0u;
    // 80062BA0: stw     r8, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062BA4:
    ctx->pc = 0x80062BA4u;
    // 80062BA4: stw     r10, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062BA8:
    ctx->pc = 0x80062BA8u;
    // 80062BA8: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_80062BAC:
    ctx->pc = 0x80062BACu;
    // 80062BAC: lwz     r25, 8(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(8);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062BB0:
    ctx->pc = 0x80062BB0u;
    // 80062BB0: lwz     r7, 12(r7)
    {
        u32 ea = ctx->gpr[7] + (u32)(s32)(12);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062BB4:
    ctx->pc = 0x80062BB4u;
    // 80062BB4: stw     r25, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062BB8:
    ctx->pc = 0x80062BB8u;
    // 80062BB8: stw     r7, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062BBC:
    ctx->pc = 0x80062BBCu;
    // 80062BBC: lwz     r7, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062BC0:
    ctx->pc = 0x80062BC0u;
    // 80062BC0: lwz     r8, 31608(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(31608);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062BC4:
    ctx->pc = 0x80062BC4u;
    // 80062BC4: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_80062BC8:
    ctx->pc = 0x80062BC8u;
    // 80062BC8: stw     r8, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062BCC:
    ctx->pc = 0x80062BCCu;
    // 80062BCC: stw     r25, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062BD0:
    ctx->pc = 0x80062BD0u;
    // 80062BD0: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062BD4:
    ctx->pc = 0x80062BD4u;
    // 80062BD4: lwz     r10, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062BD8:
    ctx->pc = 0x80062BD8u;
    // 80062BD8: lwz     r7, 4(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(4);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062BDC:
    ctx->pc = 0x80062BDCu;
    // 80062BDC: stw     r10, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062BE0:
    ctx->pc = 0x80062BE0u;
    // 80062BE0: lwz     r8, 8(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062BE4:
    ctx->pc = 0x80062BE4u;
    // 80062BE4: lwz     r25, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062BE8:
    ctx->pc = 0x80062BE8u;
    // 80062BE8: lwz     r10, 12(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(12);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062BEC:
    ctx->pc = 0x80062BECu;
    // 80062BEC: stw     r25, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062BF0:
    ctx->pc = 0x80062BF0u;
    // 80062BF0: lwz     r25, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062BF4:
    ctx->pc = 0x80062BF4u;
    // 80062BF4: stw     r7, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062BF8:
    ctx->pc = 0x80062BF8u;
    // 80062BF8: stw     r8, 180(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(180);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062BFC:
    ctx->pc = 0x80062BFCu;
    // 80062BFC: stw     r10, 184(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062C00:
    ctx->pc = 0x80062C00u;
    // 80062C00: lwz     r6, 16(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062C04:
    ctx->pc = 0x80062C04u;
    // 80062C04: stwu     r25, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
        ctx->gpr[30] = ea;
    }

label_80062C08:
    ctx->pc = 0x80062C08u;
    // 80062C08: stw     r6, 188(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062C0C:
    ctx->pc = 0x80062C0Cu;
    // 80062C0C: stw     r7, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062C10:
    ctx->pc = 0x80062C10u;
    // 80062C10: stw     r8, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062C14:
    ctx->pc = 0x80062C14u;
    // 80062C14: stw     r10, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062C18:
    ctx->pc = 0x80062C18u;
    // 80062C18: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062C1C:
    ctx->pc = 0x80062C1Cu;
    // 80062C1C: lis     r6, -32738
    ctx->gpr[6] = ((u32)(s32)(-32738) << 16);

label_80062C20:
    ctx->pc = 0x80062C20u;
    // 80062C20: lwz     r7, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062C24:
    ctx->pc = 0x80062C24u;
    // 80062C24: lwz     r6, 31628(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(31628);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062C28:
    ctx->pc = 0x80062C28u;
    // 80062C28: lwz     r8, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062C2C:
    ctx->pc = 0x80062C2Cu;
    // 80062C2C: stw     r6, 192(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062C30:
    ctx->pc = 0x80062C30u;
    // 80062C30: stw     r7, 208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062C34:
    ctx->pc = 0x80062C34u;
    // 80062C34: stw     r8, 196(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(196);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062C38:
    ctx->pc = 0x80062C38u;
    // 80062C38: lwz     r10, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062C3C:
    ctx->pc = 0x80062C3Cu;
    // 80062C3C: lwz     r11, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062C40:
    ctx->pc = 0x80062C40u;
    // 80062C40: stw     r10, 200(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(200);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062C44:
    ctx->pc = 0x80062C44u;
    // 80062C44: stw     r11, 204(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(204);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062C48:
    ctx->pc = 0x80062C48u;
    // 80062C48: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_80062C4C:
    ctx->pc = 0x80062C4Cu;
    // 80062C4C: stwu     r6, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[30] = ea;
    }

label_80062C50:
    ctx->pc = 0x80062C50u;
    // 80062C50: lwz     r11, 31656(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(31656);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062C54:
    ctx->pc = 0x80062C54u;
    // 80062C54: lwz     r6, 16(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062C58:
    ctx->pc = 0x80062C58u;
    // 80062C58: stw     r11, 212(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(212);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062C5C:
    ctx->pc = 0x80062C5Cu;
    // 80062C5C: stw     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062C60:
    ctx->pc = 0x80062C60u;
    // 80062C60: stw     r8, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062C64:
    ctx->pc = 0x80062C64u;
    // 80062C64: lwz     r24, 4(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(4);
        ctx->gpr[24] = mem_read32(ctx, ea);
    }

label_80062C68:
    ctx->pc = 0x80062C68u;
    // 80062C68: lwz     r25, 204(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(204);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062C6C:
    ctx->pc = 0x80062C6Cu;
    // 80062C6C: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062C70:
    ctx->pc = 0x80062C70u;
    // 80062C70: stw     r25, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062C74:
    ctx->pc = 0x80062C74u;
    // 80062C74: lwz     r25, 8(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(8);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062C78:
    ctx->pc = 0x80062C78u;
    // 80062C78: lwz     r29, 12(r29)
    {
        u32 ea = ctx->gpr[29] + (u32)(s32)(12);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80062C7C:
    ctx->pc = 0x80062C7Cu;
    // 80062C7C: stw     r6, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062C80:
    ctx->pc = 0x80062C80u;
    // 80062C80: stw     r29, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80062C84:
    ctx->pc = 0x80062C84u;
    // 80062C84: lwz     r7, 31684(r31)
    {
        u32 ea = ctx->gpr[31] + (u32)(s32)(31684);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062C88:
    ctx->pc = 0x80062C88u;
    // 80062C88: stwu     r11, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
        ctx->gpr[30] = ea;
    }

label_80062C8C:
    ctx->pc = 0x80062C8Cu;
    // 80062C8C: stw     r7, 224(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062C90:
    ctx->pc = 0x80062C90u;
    // 80062C90: or   r11, r0, r0
    {
        ctx->gpr[11] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80062C94:
    ctx->pc = 0x80062C94u;
    // 80062C94: stw     r25, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062C98:
    ctx->pc = 0x80062C98u;
    // 80062C98: stw     r29, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80062C9C:
    ctx->pc = 0x80062C9Cu;
    // 80062C9C: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062CA0:
    ctx->pc = 0x80062CA0u;
    // 80062CA0: stw     r24, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_80062CA4:
    ctx->pc = 0x80062CA4u;
    // 80062CA4: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_80062CA8:
    ctx->pc = 0x80062CA8u;
    // 80062CA8: lwz     r16, 4(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(4);
        ctx->gpr[16] = mem_read32(ctx, ea);
    }

label_80062CAC:
    ctx->pc = 0x80062CACu;
    // 80062CAC: lwz     r23, 16(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(16);
        ctx->gpr[23] = mem_read32(ctx, ea);
    }

label_80062CB0:
    ctx->pc = 0x80062CB0u;
    // 80062CB0: lwz     r17, 8(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(8);
        ctx->gpr[17] = mem_read32(ctx, ea);
    }

label_80062CB4:
    ctx->pc = 0x80062CB4u;
    // 80062CB4: lwz     r18, 12(r28)
    {
        u32 ea = ctx->gpr[28] + (u32)(s32)(12);
        ctx->gpr[18] = mem_read32(ctx, ea);
    }

label_80062CB8:
    ctx->pc = 0x80062CB8u;
    // 80062CB8: lwz     r20, 4(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(4);
        ctx->gpr[20] = mem_read32(ctx, ea);
    }

label_80062CBC:
    ctx->pc = 0x80062CBCu;
    // 80062CBC: lwz     r21, 8(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(8);
        ctx->gpr[21] = mem_read32(ctx, ea);
    }

label_80062CC0:
    ctx->pc = 0x80062CC0u;
    // 80062CC0: lwz     r22, 12(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(12);
        ctx->gpr[22] = mem_read32(ctx, ea);
    }

label_80062CC4:
    ctx->pc = 0x80062CC4u;
    // 80062CC4: lwz     r19, 31712(r14)
    {
        u32 ea = ctx->gpr[14] + (u32)(s32)(31712);
        ctx->gpr[19] = mem_read32(ctx, ea);
    }

label_80062CC8:
    ctx->pc = 0x80062CC8u;
    // 80062CC8: stw     r16, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[16]);
    }

label_80062CCC:
    ctx->pc = 0x80062CCCu;
    // 80062CCC: stw     r17, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[17]);
    }

label_80062CD0:
    ctx->pc = 0x80062CD0u;
    // 80062CD0: stw     r18, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[18]);
    }

label_80062CD4:
    ctx->pc = 0x80062CD4u;
    // 80062CD4: stw     r23, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_80062CD8:
    ctx->pc = 0x80062CD8u;
    // 80062CD8: stwu     r19, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[19]);
        ctx->gpr[30] = ea;
    }

label_80062CDC:
    ctx->pc = 0x80062CDCu;
    // 80062CDC: lwz     r8, 4(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(4);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062CE0:
    ctx->pc = 0x80062CE0u;
    // 80062CE0: lwz     r10, 8(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062CE4:
    ctx->pc = 0x80062CE4u;
    // 80062CE4: lwz     r14, 16(r27)
    {
        u32 ea = ctx->gpr[27] + (u32)(s32)(16);
        ctx->gpr[14] = mem_read32(ctx, ea);
    }

label_80062CE8:
    ctx->pc = 0x80062CE8u;
    // 80062CE8: lwz     r31, 16(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(16);
        ctx->gpr[31] = mem_read32(ctx, ea);
    }

label_80062CEC:
    ctx->pc = 0x80062CECu;
    // 80062CEC: lwz     r26, 12(r26)
    {
        u32 ea = ctx->gpr[26] + (u32)(s32)(12);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_80062CF0:
    ctx->pc = 0x80062CF0u;
    // 80062CF0: stw     r20, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[20]);
    }

label_80062CF4:
    ctx->pc = 0x80062CF4u;
    // 80062CF4: stw     r21, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[21]);
    }

label_80062CF8:
    ctx->pc = 0x80062CF8u;
    // 80062CF8: stw     r22, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_80062CFC:
    ctx->pc = 0x80062CFCu;
    // 80062CFC: stw     r14, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[14]);
    }

label_80062D00:
    ctx->pc = 0x80062D00u;
    // 80062D00: lwz     r15, 31740(r12)
    {
        u32 ea = ctx->gpr[12] + (u32)(s32)(31740);
        ctx->gpr[15] = mem_read32(ctx, ea);
    }

label_80062D04:
    ctx->pc = 0x80062D04u;
    // 80062D04: stw     r8, 228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(228);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062D08:
    ctx->pc = 0x80062D08u;
    // 80062D08: stw     r10, 232(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062D0C:
    ctx->pc = 0x80062D0Cu;
    // 80062D0C: stw     r26, 236(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(236);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80062D10:
    ctx->pc = 0x80062D10u;
    // 80062D10: lwz     r0, 31768(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(31768);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062D14:
    ctx->pc = 0x80062D14u;
    // 80062D14: stwu     r15, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[15]);
        ctx->gpr[30] = ea;
    }

label_80062D18:
    ctx->pc = 0x80062D18u;
    // 80062D18: lis     r11, -32738
    ctx->gpr[11] = ((u32)(s32)(-32738) << 16);

label_80062D1C:
    ctx->pc = 0x80062D1Cu;
    // 80062D1C: stw     r0, 240(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062D20:
    ctx->pc = 0x80062D20u;
    // 80062D20: addi    r11, r11, 31796
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(31796);

label_80062D24:
    ctx->pc = 0x80062D24u;
    // 80062D24: stw     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062D28:
    ctx->pc = 0x80062D28u;
    // 80062D28: stw     r26, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80062D2C:
    ctx->pc = 0x80062D2Cu;
    // 80062D2C: lwz     r7, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062D30:
    ctx->pc = 0x80062D30u;
    // 80062D30: stw     r31, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_80062D34:
    ctx->pc = 0x80062D34u;
    // 80062D34: lwz     r0, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062D38:
    ctx->pc = 0x80062D38u;
    // 80062D38: lwz     r6, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062D3C:
    ctx->pc = 0x80062D3Cu;
    // 80062D3C: stw     r8, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062D40:
    ctx->pc = 0x80062D40u;
    // 80062D40: lwz     r9, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062D44:
    ctx->pc = 0x80062D44u;
    // 80062D44: lwz     r8, 240(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062D48:
    ctx->pc = 0x80062D48u;
    // 80062D48: stw     r0, 256(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(256);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062D4C:
    ctx->pc = 0x80062D4Cu;
    // 80062D4C: stw     r6, 244(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(244);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062D50:
    ctx->pc = 0x80062D50u;
    // 80062D50: stw     r7, 248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062D54:
    ctx->pc = 0x80062D54u;
    // 80062D54: stw     r9, 252(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(252);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062D58:
    ctx->pc = 0x80062D58u;
    // 80062D58: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80062D5C:
    ctx->pc = 0x80062D5Cu;
    // 80062D5C: mfctr    r9
    ctx->gpr[9] = ctx->ctr;

label_80062D60:
    ctx->pc = 0x80062D60u;
    // 80062D60: lwz     r9, 31796(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31796);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062D64:
    ctx->pc = 0x80062D64u;
    // 80062D64: lwz     r28, 4(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(4);
        ctx->gpr[28] = mem_read32(ctx, ea);
    }

label_80062D68:
    ctx->pc = 0x80062D68u;
    // 80062D68: stw     r9, 260(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(260);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062D6C:
    ctx->pc = 0x80062D6Cu;
    // 80062D6C: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062D70:
    ctx->pc = 0x80062D70u;
    // 80062D70: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062D74:
    ctx->pc = 0x80062D74u;
    // 80062D74: lwz     r27, 8(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(8);
        ctx->gpr[27] = mem_read32(ctx, ea);
    }

label_80062D78:
    ctx->pc = 0x80062D78u;
    // 80062D78: lwz     r10, 252(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(252);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062D7C:
    ctx->pc = 0x80062D7Cu;
    // 80062D7C: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062D80:
    ctx->pc = 0x80062D80u;
    // 80062D80: stw     r10, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062D84:
    ctx->pc = 0x80062D84u;
    // 80062D84: stwu     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
        ctx->gpr[30] = ea;
    }

label_80062D88:
    ctx->pc = 0x80062D88u;
    // 80062D88: lwz     r26, 12(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(12);
        ctx->gpr[26] = mem_read32(ctx, ea);
    }

label_80062D8C:
    ctx->pc = 0x80062D8Cu;
    // 80062D8C: lwz     r29, 16(r11)
    {
        u32 ea = ctx->gpr[11] + (u32)(s32)(16);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_80062D90:
    ctx->pc = 0x80062D90u;
    // 80062D90: stw     r28, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80062D94:
    ctx->pc = 0x80062D94u;
    // 80062D94: stw     r27, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_80062D98:
    ctx->pc = 0x80062D98u;
    // 80062D98: stw     r26, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80062D9C:
    ctx->pc = 0x80062D9Cu;
    // 80062D9C: stw     r29, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80062DA0:
    ctx->pc = 0x80062DA0u;
    // 80062DA0: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062DA4:
    ctx->pc = 0x80062DA4u;
    // 80062DA4: bl      0x801698F0
    {
            ctx->lr = 0x80062DA8u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062DA8:
    ctx->pc = 0x80062DA8u;
    ctx->downcount -= 23;
    // 80062DA8: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062DAC:
    ctx->pc = 0x80062DACu;
    // 80062DAC: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_80062DB0:
    ctx->pc = 0x80062DB0u;
    // 80062DB0: li      r5, 58
    ctx->gpr[5] = (u32)(s32)(58);

label_80062DB4:
    ctx->pc = 0x80062DB4u;
    // 80062DB4: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062DB8:
    ctx->pc = 0x80062DB8u;
    // 80062DB8: lis     r6, -32735
    ctx->gpr[6] = ((u32)(s32)(-32735) << 16);

label_80062DBC:
    ctx->pc = 0x80062DBCu;
    // 80062DBC: stw     r5, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[5]);
    }

label_80062DC0:
    ctx->pc = 0x80062DC0u;
    // 80062DC0: addi    r6, r6, -2804
    ctx->gpr[6] = ctx->gpr[6] + (u32)(s32)(-2804);

label_80062DC4:
    ctx->pc = 0x80062DC4u;
    // 80062DC4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062DC8:
    ctx->pc = 0x80062DC8u;
    // 80062DC8: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80062DCC:
    ctx->pc = 0x80062DCCu;
    // 80062DCC: lwz     r8, 1400(r6)
    {
        u32 ea = ctx->gpr[6] + (u32)(s32)(1400);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062DD0:
    ctx->pc = 0x80062DD0u;
    // 80062DD0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062DD4:
    ctx->pc = 0x80062DD4u;
    // 80062DD4: lwz     r9, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062DD8:
    ctx->pc = 0x80062DD8u;
    // 80062DD8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062DDC:
    ctx->pc = 0x80062DDCu;
    // 80062DDC: lwz     r11, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062DE0:
    ctx->pc = 0x80062DE0u;
    // 80062DE0: lwz     r10, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062DE4:
    ctx->pc = 0x80062DE4u;
    // 80062DE4: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062DE8:
    ctx->pc = 0x80062DE8u;
    // 80062DE8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062DEC:
    ctx->pc = 0x80062DECu;
    // 80062DEC: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062DF0:
    ctx->pc = 0x80062DF0u;
    // 80062DF0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062DF4:
    ctx->pc = 0x80062DF4u;
    // 80062DF4: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062DF8:
    ctx->pc = 0x80062DF8u;
    // 80062DF8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062DFC:
    ctx->pc = 0x80062DFCu;
    // 80062DFC: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062E00:
    ctx->pc = 0x80062E00u;
    // 80062E00: bl      0x801698F0
    {
            ctx->lr = 0x80062E04u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062E04:
    ctx->pc = 0x80062E04u;
    ctx->downcount -= 19;
    // 80062E04: lis     r9, -32738
    ctx->gpr[9] = ((u32)(s32)(-32738) << 16);

label_80062E08:
    ctx->pc = 0x80062E08u;
    // 80062E08: lis     r8, -32699
    ctx->gpr[8] = ((u32)(s32)(-32699) << 16);

label_80062E0C:
    ctx->pc = 0x80062E0Cu;
    // 80062E0C: lwz     r7, 31832(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(31832);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062E10:
    ctx->pc = 0x80062E10u;
    // 80062E10: addi    r30, r8, 15860
    ctx->gpr[30] = ctx->gpr[8] + (u32)(s32)(15860);

label_80062E14:
    ctx->pc = 0x80062E14u;
    // 80062E14: addi    r9, r9, 31832
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(31832);

label_80062E18:
    ctx->pc = 0x80062E18u;
    // 80062E18: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062E1C:
    ctx->pc = 0x80062E1Cu;
    // 80062E1C: lwz     r6, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062E20:
    ctx->pc = 0x80062E20u;
    // 80062E20: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062E24:
    ctx->pc = 0x80062E24u;
    // 80062E24: lwz     r10, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062E28:
    ctx->pc = 0x80062E28u;
    // 80062E28: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80062E2C:
    ctx->pc = 0x80062E2Cu;
    // 80062E2C: lwz     r11, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062E30:
    ctx->pc = 0x80062E30u;
    // 80062E30: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062E34:
    ctx->pc = 0x80062E34u;
    // 80062E34: stw     r7, 15860(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(15860);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062E38:
    ctx->pc = 0x80062E38u;
    // 80062E38: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062E3C:
    ctx->pc = 0x80062E3Cu;
    // 80062E3C: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062E40:
    ctx->pc = 0x80062E40u;
    // 80062E40: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062E44:
    ctx->pc = 0x80062E44u;
    // 80062E44: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062E48:
    ctx->pc = 0x80062E48u;
    // 80062E48: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80062E4C:
    ctx->pc = 0x80062E4Cu;
    // 80062E4C: bl      0x801698F0
    {
            ctx->lr = 0x80062E50u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80062E50:
    ctx->pc = 0x80062E50u;
    ctx->downcount -= 146;
    // 80062E50: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_80062E54:
    ctx->pc = 0x80062E54u;
    // 80062E54: li      r0, 51
    ctx->gpr[0] = (u32)(s32)(51);

label_80062E58:
    ctx->pc = 0x80062E58u;
    // 80062E58: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_80062E5C:
    ctx->pc = 0x80062E5Cu;
    // 80062E5C: stw     r3, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_80062E60:
    ctx->pc = 0x80062E60u;
    // 80062E60: lis     r5, -32735
    ctx->gpr[5] = ((u32)(s32)(-32735) << 16);

label_80062E64:
    ctx->pc = 0x80062E64u;
    // 80062E64: stw     r0, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062E68:
    ctx->pc = 0x80062E68u;
    // 80062E68: addi    r5, r5, -2804
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-2804);

label_80062E6C:
    ctx->pc = 0x80062E6Cu;
    // 80062E6C: lwz     r10, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062E70:
    ctx->pc = 0x80062E70u;
    // 80062E70: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80062E74:
    ctx->pc = 0x80062E74u;
    // 80062E74: lwz     r8, 1232(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1232);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062E78:
    ctx->pc = 0x80062E78u;
    // 80062E78: addi    r3, r1, 8
    ctx->gpr[3] = ctx->gpr[1] + (u32)(s32)(8);

label_80062E7C:
    ctx->pc = 0x80062E7Cu;
    // 80062E7C: lwz     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062E80:
    ctx->pc = 0x80062E80u;
    // 80062E80: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_80062E84:
    ctx->pc = 0x80062E84u;
    // 80062E84: lwz     r9, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062E88:
    ctx->pc = 0x80062E88u;
    // 80062E88: lwz     r11, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062E8C:
    ctx->pc = 0x80062E8Cu;
    // 80062E8C: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062E90:
    ctx->pc = 0x80062E90u;
    // 80062E90: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062E94:
    ctx->pc = 0x80062E94u;
    // 80062E94: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062E98:
    ctx->pc = 0x80062E98u;
    // 80062E98: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062E9C:
    ctx->pc = 0x80062E9Cu;
    // 80062E9C: stw     r8, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062EA0:
    ctx->pc = 0x80062EA0u;
    // 80062EA0: lwz     r6, 52(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(52);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062EA4:
    ctx->pc = 0x80062EA4u;
    // 80062EA4: stwu     r6, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[30] = ea;
    }

label_80062EA8:
    ctx->pc = 0x80062EA8u;
    // 80062EA8: stw     r8, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062EAC:
    ctx->pc = 0x80062EACu;
    // 80062EAC: lwz     r7, 56(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(56);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062EB0:
    ctx->pc = 0x80062EB0u;
    // 80062EB0: stw     r7, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062EB4:
    ctx->pc = 0x80062EB4u;
    // 80062EB4: lwz     r8, 60(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(60);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062EB8:
    ctx->pc = 0x80062EB8u;
    // 80062EB8: stw     r8, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062EBC:
    ctx->pc = 0x80062EBCu;
    // 80062EBC: lwz     r9, 64(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(64);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062EC0:
    ctx->pc = 0x80062EC0u;
    // 80062EC0: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062EC4:
    ctx->pc = 0x80062EC4u;
    // 80062EC4: lwz     r10, 68(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(68);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062EC8:
    ctx->pc = 0x80062EC8u;
    // 80062EC8: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062ECC:
    ctx->pc = 0x80062ECCu;
    // 80062ECC: lwz     r11, 72(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(72);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062ED0:
    ctx->pc = 0x80062ED0u;
    // 80062ED0: stwu     r11, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
        ctx->gpr[30] = ea;
    }

label_80062ED4:
    ctx->pc = 0x80062ED4u;
    // 80062ED4: lwz     r0, 76(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(76);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062ED8:
    ctx->pc = 0x80062ED8u;
    // 80062ED8: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062EDC:
    ctx->pc = 0x80062EDCu;
    // 80062EDC: lwz     r6, 80(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(80);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062EE0:
    ctx->pc = 0x80062EE0u;
    // 80062EE0: stw     r6, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062EE4:
    ctx->pc = 0x80062EE4u;
    // 80062EE4: lwz     r7, 84(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(84);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062EE8:
    ctx->pc = 0x80062EE8u;
    // 80062EE8: stw     r7, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062EEC:
    ctx->pc = 0x80062EECu;
    // 80062EEC: lwz     r8, 88(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(88);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062EF0:
    ctx->pc = 0x80062EF0u;
    // 80062EF0: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062EF4:
    ctx->pc = 0x80062EF4u;
    // 80062EF4: lwz     r9, 92(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(92);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062EF8:
    ctx->pc = 0x80062EF8u;
    // 80062EF8: stwu     r9, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
        ctx->gpr[30] = ea;
    }

label_80062EFC:
    ctx->pc = 0x80062EFCu;
    // 80062EFC: lwz     r10, 96(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(96);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062F00:
    ctx->pc = 0x80062F00u;
    // 80062F00: stw     r10, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062F04:
    ctx->pc = 0x80062F04u;
    // 80062F04: lwz     r11, 100(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(100);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062F08:
    ctx->pc = 0x80062F08u;
    // 80062F08: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062F0C:
    ctx->pc = 0x80062F0Cu;
    // 80062F0C: lwz     r0, 104(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(104);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062F10:
    ctx->pc = 0x80062F10u;
    // 80062F10: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062F14:
    ctx->pc = 0x80062F14u;
    // 80062F14: lwz     r6, 108(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(108);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062F18:
    ctx->pc = 0x80062F18u;
    // 80062F18: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062F1C:
    ctx->pc = 0x80062F1Cu;
    // 80062F1C: lwz     r7, 112(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(112);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062F20:
    ctx->pc = 0x80062F20u;
    // 80062F20: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_80062F24:
    ctx->pc = 0x80062F24u;
    // 80062F24: lwz     r8, 116(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(116);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062F28:
    ctx->pc = 0x80062F28u;
    // 80062F28: stw     r8, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062F2C:
    ctx->pc = 0x80062F2Cu;
    // 80062F2C: lwz     r9, 120(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(120);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062F30:
    ctx->pc = 0x80062F30u;
    // 80062F30: stw     r9, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062F34:
    ctx->pc = 0x80062F34u;
    // 80062F34: lwz     r10, 124(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(124);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062F38:
    ctx->pc = 0x80062F38u;
    // 80062F38: stw     r10, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062F3C:
    ctx->pc = 0x80062F3Cu;
    // 80062F3C: lwz     r11, 128(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(128);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062F40:
    ctx->pc = 0x80062F40u;
    // 80062F40: stw     r11, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062F44:
    ctx->pc = 0x80062F44u;
    // 80062F44: lwz     r0, 132(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(132);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062F48:
    ctx->pc = 0x80062F48u;
    // 80062F48: stwu     r0, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
        ctx->gpr[30] = ea;
    }

label_80062F4C:
    ctx->pc = 0x80062F4Cu;
    // 80062F4C: lwz     r6, 136(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(136);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062F50:
    ctx->pc = 0x80062F50u;
    // 80062F50: stw     r6, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062F54:
    ctx->pc = 0x80062F54u;
    // 80062F54: lwz     r7, 140(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(140);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062F58:
    ctx->pc = 0x80062F58u;
    // 80062F58: stw     r7, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062F5C:
    ctx->pc = 0x80062F5Cu;
    // 80062F5C: lwz     r8, 144(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(144);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062F60:
    ctx->pc = 0x80062F60u;
    // 80062F60: stw     r8, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062F64:
    ctx->pc = 0x80062F64u;
    // 80062F64: lwz     r9, 148(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(148);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062F68:
    ctx->pc = 0x80062F68u;
    // 80062F68: stw     r9, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062F6C:
    ctx->pc = 0x80062F6Cu;
    // 80062F6C: lwz     r10, 152(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(152);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062F70:
    ctx->pc = 0x80062F70u;
    // 80062F70: stwu     r10, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
        ctx->gpr[30] = ea;
    }

label_80062F74:
    ctx->pc = 0x80062F74u;
    // 80062F74: lwz     r11, 156(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(156);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062F78:
    ctx->pc = 0x80062F78u;
    // 80062F78: stw     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062F7C:
    ctx->pc = 0x80062F7Cu;
    // 80062F7C: lwz     r0, 160(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(160);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062F80:
    ctx->pc = 0x80062F80u;
    // 80062F80: stw     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062F84:
    ctx->pc = 0x80062F84u;
    // 80062F84: lwz     r6, 164(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(164);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062F88:
    ctx->pc = 0x80062F88u;
    // 80062F88: stw     r6, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80062F8C:
    ctx->pc = 0x80062F8Cu;
    // 80062F8C: lwz     r7, 168(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(168);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062F90:
    ctx->pc = 0x80062F90u;
    // 80062F90: stw     r7, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062F94:
    ctx->pc = 0x80062F94u;
    // 80062F94: lwz     r8, 172(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(172);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062F98:
    ctx->pc = 0x80062F98u;
    // 80062F98: stwu     r8, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
        ctx->gpr[30] = ea;
    }

label_80062F9C:
    ctx->pc = 0x80062F9Cu;
    // 80062F9C: lwz     r9, 176(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(176);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062FA0:
    ctx->pc = 0x80062FA0u;
    // 80062FA0: stw     r9, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062FA4:
    ctx->pc = 0x80062FA4u;
    // 80062FA4: lwz     r10, 180(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(180);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062FA8:
    ctx->pc = 0x80062FA8u;
    // 80062FA8: stw     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062FAC:
    ctx->pc = 0x80062FACu;
    // 80062FAC: lwz     r11, 184(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(184);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062FB0:
    ctx->pc = 0x80062FB0u;
    // 80062FB0: stw     r11, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80062FB4:
    ctx->pc = 0x80062FB4u;
    // 80062FB4: lwz     r0, 188(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(188);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80062FB8:
    ctx->pc = 0x80062FB8u;
    // 80062FB8: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80062FBC:
    ctx->pc = 0x80062FBCu;
    // 80062FBC: lwz     r6, 192(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(192);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80062FC0:
    ctx->pc = 0x80062FC0u;
    // 80062FC0: stwu     r6, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[30] = ea;
    }

label_80062FC4:
    ctx->pc = 0x80062FC4u;
    // 80062FC4: lwz     r7, 196(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(196);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80062FC8:
    ctx->pc = 0x80062FC8u;
    // 80062FC8: stw     r7, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_80062FCC:
    ctx->pc = 0x80062FCCu;
    // 80062FCC: lwz     r8, 200(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(200);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80062FD0:
    ctx->pc = 0x80062FD0u;
    // 80062FD0: stw     r8, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80062FD4:
    ctx->pc = 0x80062FD4u;
    // 80062FD4: lwz     r9, 204(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(204);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80062FD8:
    ctx->pc = 0x80062FD8u;
    // 80062FD8: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80062FDC:
    ctx->pc = 0x80062FDCu;
    // 80062FDC: lwz     r10, 208(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(208);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80062FE0:
    ctx->pc = 0x80062FE0u;
    // 80062FE0: stw     r10, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80062FE4:
    ctx->pc = 0x80062FE4u;
    // 80062FE4: lwz     r11, 212(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(212);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_80062FE8:
    ctx->pc = 0x80062FE8u;
    // 80062FE8: stwu     r11, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
        ctx->gpr[30] = ea;
    }

label_80062FEC:
    ctx->pc = 0x80062FECu;
    // 80062FEC: stw     r24, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[24]);
    }

label_80062FF0:
    ctx->pc = 0x80062FF0u;
    // 80062FF0: stw     r25, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062FF4:
    ctx->pc = 0x80062FF4u;
    // 80062FF4: lwz     r25, 216(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(216);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80062FF8:
    ctx->pc = 0x80062FF8u;
    // 80062FF8: stw     r25, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80062FFC:
    ctx->pc = 0x80062FFCu;
    // 80062FFC: lwz     r0, 220(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(220);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063000:
    ctx->pc = 0x80063000u;
    // 80063000: stw     r0, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80063004:
    ctx->pc = 0x80063004u;
    // 80063004: lwz     r6, 224(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(224);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80063008:
    ctx->pc = 0x80063008u;
    // 80063008: stwu     r6, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
        ctx->gpr[30] = ea;
    }

label_8006300C:
    ctx->pc = 0x8006300Cu;
    // 8006300C: stw     r16, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[16]);
    }

label_80063010:
    ctx->pc = 0x80063010u;
    // 80063010: stw     r17, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[17]);
    }

label_80063014:
    ctx->pc = 0x80063014u;
    // 80063014: stw     r18, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[18]);
    }

label_80063018:
    ctx->pc = 0x80063018u;
    // 80063018: stw     r23, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[23]);
    }

label_8006301C:
    ctx->pc = 0x8006301Cu;
    // 8006301C: stwu     r19, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[19]);
        ctx->gpr[30] = ea;
    }

label_80063020:
    ctx->pc = 0x80063020u;
    // 80063020: stw     r20, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[20]);
    }

label_80063024:
    ctx->pc = 0x80063024u;
    // 80063024: stw     r21, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[21]);
    }

label_80063028:
    ctx->pc = 0x80063028u;
    // 80063028: stw     r22, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[22]);
    }

label_8006302C:
    ctx->pc = 0x8006302Cu;
    // 8006302C: stw     r14, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[14]);
    }

label_80063030:
    ctx->pc = 0x80063030u;
    // 80063030: stwu     r15, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[15]);
        ctx->gpr[30] = ea;
    }

label_80063034:
    ctx->pc = 0x80063034u;
    // 80063034: lwz     r7, 228(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(228);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_80063038:
    ctx->pc = 0x80063038u;
    // 80063038: stw     r7, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
    }

label_8006303C:
    ctx->pc = 0x8006303Cu;
    // 8006303C: lwz     r8, 232(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(232);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80063040:
    ctx->pc = 0x80063040u;
    // 80063040: stw     r8, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80063044:
    ctx->pc = 0x80063044u;
    // 80063044: lwz     r9, 236(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(236);
        ctx->gpr[9] = mem_read32(ctx, ea);
    }

label_80063048:
    ctx->pc = 0x80063048u;
    // 80063048: stw     r31, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[31]);
    }

label_8006304C:
    ctx->pc = 0x8006304Cu;
    // 8006304C: stw     r9, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[9]);
    }

label_80063050:
    ctx->pc = 0x80063050u;
    // 80063050: lwz     r10, 240(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(240);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80063054:
    ctx->pc = 0x80063054u;
    // 80063054: stwu     r10, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
        ctx->gpr[30] = ea;
    }

label_80063058:
    ctx->pc = 0x80063058u;
    // 80063058: lwz     r11, 244(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(244);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_8006305C:
    ctx->pc = 0x8006305Cu;
    // 8006305C: stw     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_80063060:
    ctx->pc = 0x80063060u;
    // 80063060: lwz     r25, 248(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(248);
        ctx->gpr[25] = mem_read32(ctx, ea);
    }

label_80063064:
    ctx->pc = 0x80063064u;
    // 80063064: stw     r25, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[25]);
    }

label_80063068:
    ctx->pc = 0x80063068u;
    // 80063068: lwz     r0, 252(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(252);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_8006306C:
    ctx->pc = 0x8006306Cu;
    // 8006306C: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80063070:
    ctx->pc = 0x80063070u;
    // 80063070: lwz     r6, 256(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(256);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_80063074:
    ctx->pc = 0x80063074u;
    // 80063074: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_80063078:
    ctx->pc = 0x80063078u;
    // 80063078: lwz     r7, 260(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(260);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_8006307C:
    ctx->pc = 0x8006307Cu;
    // 8006307C: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_80063080:
    ctx->pc = 0x80063080u;
    // 80063080: stw     r29, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_80063084:
    ctx->pc = 0x80063084u;
    // 80063084: stw     r28, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[28]);
    }

label_80063088:
    ctx->pc = 0x80063088u;
    // 80063088: stw     r27, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[27]);
    }

label_8006308C:
    ctx->pc = 0x8006308Cu;
    // 8006308C: stw     r26, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[26]);
    }

label_80063090:
    ctx->pc = 0x80063090u;
    // 80063090: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80063094:
    ctx->pc = 0x80063094u;
    // 80063094: bl      0x801698F0
    {
            ctx->lr = 0x80063098u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80063098:
    ctx->pc = 0x80063098u;
    ctx->downcount -= 35;
    // 80063098: addi    r30, r30, 20
    ctx->gpr[30] = ctx->gpr[30] + (u32)(s32)(20);

label_8006309C:
    ctx->pc = 0x8006309Cu;
    // 8006309C: li      r3, 58
    ctx->gpr[3] = (u32)(s32)(58);

label_800630A0:
    ctx->pc = 0x800630A0u;
    // 800630A0: li      r0, 1
    ctx->gpr[0] = (u32)(s32)(1);

label_800630A4:
    ctx->pc = 0x800630A4u;
    // 800630A4: stw     r0, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800630A8:
    ctx->pc = 0x800630A8u;
    // 800630A8: lis     r5, -32735
    ctx->gpr[5] = ((u32)(s32)(-32735) << 16);

label_800630AC:
    ctx->pc = 0x800630ACu;
    // 800630AC: stw     r3, 20(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_800630B0:
    ctx->pc = 0x800630B0u;
    // 800630B0: addi    r5, r5, -2804
    ctx->gpr[5] = ctx->gpr[5] + (u32)(s32)(-2804);

label_800630B4:
    ctx->pc = 0x800630B4u;
    // 800630B4: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800630B8:
    ctx->pc = 0x800630B8u;
    // 800630B8: lis     r8, -32738
    ctx->gpr[8] = ((u32)(s32)(-32738) << 16);

label_800630BC:
    ctx->pc = 0x800630BCu;
    // 800630BC: lwz     r29, 1400(r5)
    {
        u32 ea = ctx->gpr[5] + (u32)(s32)(1400);
        ctx->gpr[29] = mem_read32(ctx, ea);
    }

label_800630C0:
    ctx->pc = 0x800630C0u;
    // 800630C0: or   r10, r3, r3
    {
        ctx->gpr[10] = ctx->gpr[3] | ctx->gpr[3];
    }

label_800630C4:
    ctx->pc = 0x800630C4u;
    // 800630C4: lwz     r11, 16(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(16);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800630C8:
    ctx->pc = 0x800630C8u;
    // 800630C8: addi    r9, r8, 31868
    ctx->gpr[9] = ctx->gpr[8] + (u32)(s32)(31868);

label_800630CC:
    ctx->pc = 0x800630CCu;
    // 800630CC: lwz     r6, 24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(24);
        ctx->gpr[6] = mem_read32(ctx, ea);
    }

label_800630D0:
    ctx->pc = 0x800630D0u;
    // 800630D0: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800630D4:
    ctx->pc = 0x800630D4u;
    // 800630D4: lwz     r7, 31868(r8)
    {
        u32 ea = ctx->gpr[8] + (u32)(s32)(31868);
        ctx->gpr[7] = mem_read32(ctx, ea);
    }

label_800630D8:
    ctx->pc = 0x800630D8u;
    // 800630D8: li      r5, 20
    ctx->gpr[5] = (u32)(s32)(20);

label_800630DC:
    ctx->pc = 0x800630DCu;
    // 800630DC: stw     r0, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_800630E0:
    ctx->pc = 0x800630E0u;
    // 800630E0: stw     r11, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_800630E4:
    ctx->pc = 0x800630E4u;
    // 800630E4: stw     r10, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_800630E8:
    ctx->pc = 0x800630E8u;
    // 800630E8: stw     r6, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[6]);
    }

label_800630EC:
    ctx->pc = 0x800630ECu;
    // 800630EC: stw     r29, 0(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(0);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_800630F0:
    ctx->pc = 0x800630F0u;
    // 800630F0: stwu     r7, 20(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(20);
        mem_write32(ctx, ea, (u32)ctx->gpr[7]);
        ctx->gpr[30] = ea;
    }

label_800630F4:
    ctx->pc = 0x800630F4u;
    // 800630F4: lwz     r8, 16(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(16);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800630F8:
    ctx->pc = 0x800630F8u;
    // 800630F8: lwz     r11, 4(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(4);
        ctx->gpr[11] = mem_read32(ctx, ea);
    }

label_800630FC:
    ctx->pc = 0x800630FCu;
    // 800630FC: addi    r3, r30, 20
    ctx->gpr[3] = ctx->gpr[30] + (u32)(s32)(20);

label_80063100:
    ctx->pc = 0x80063100u;
    // 80063100: lwz     r10, 8(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(8);
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_80063104:
    ctx->pc = 0x80063104u;
    // 80063104: lwz     r0, 12(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063108:
    ctx->pc = 0x80063108u;
    // 80063108: stw     r11, 4(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(4);
        mem_write32(ctx, ea, (u32)ctx->gpr[11]);
    }

label_8006310C:
    ctx->pc = 0x8006310Cu;
    // 8006310C: stw     r10, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[10]);
    }

label_80063110:
    ctx->pc = 0x80063110u;
    // 80063110: stw     r0, 12(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80063114:
    ctx->pc = 0x80063114u;
    // 80063114: stw     r8, 16(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(16);
        mem_write32(ctx, ea, (u32)ctx->gpr[8]);
    }

label_80063118:
    ctx->pc = 0x80063118u;
    // 80063118: stw     r29, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        mem_write32(ctx, ea, (u32)ctx->gpr[29]);
    }

label_8006311C:
    ctx->pc = 0x8006311Cu;
    // 8006311C: crxor   6, 6, 6
    {
        u32 a = (ctx->cr >> (31u - 6u)) & 1u;
        u32 b = (ctx->cr >> (31u - 6u)) & 1u;
        u32 mask = 0x80000000u >> 6;
        u32 value = (a ^ b) & 1u;
        ctx->cr = (ctx->cr & ~mask) | (value ? mask : 0u);
    }

label_80063120:
    ctx->pc = 0x80063120u;
    // 80063120: bl      0x801698F0
    {
            ctx->lr = 0x80063124u;
            ctx->pc = 0x801698F0u;
            return;
    }

label_80063124:
    ctx->pc = 0x80063124u;
    ctx->downcount -= 16;
    // 80063124: lwz     r0, 340(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(340);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063128:
    ctx->pc = 0x80063128u;
    // 80063128: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006312C:
    ctx->pc = 0x8006312Cu;
    // 8006312C: lmw     r14, 264(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(264);
        for (u32 r = 14; r < 32; r++, ea += 4) ctx->gpr[r] = mem_read32(ctx, ea);
    }

label_80063130:
    ctx->pc = 0x80063130u;
    // 80063130: addi    r1, r1, 336
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(336);

label_80063134:
    ctx->pc = 0x80063134u;
    // 80063134: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_80063138:
    ctx->pc = 0x80063138u;
    ctx->downcount -= 7;
    // 80063138: stwu     r1, -8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-8);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_8006313C:
    ctx->pc = 0x8006313Cu;
    // 8006313C: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_80063140:
    ctx->pc = 0x80063140u;
    // 80063140: stw     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80063144:
    ctx->pc = 0x80063144u;
    // 80063144: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_80063148:
    ctx->pc = 0x80063148u;
    // 80063148: li      r3, 1
    ctx->gpr[3] = (u32)(s32)(1);

label_8006314C:
    ctx->pc = 0x8006314Cu;
    // 8006314C: ori     r4, r4, 0xFFFF
    ctx->gpr[4] = ctx->gpr[4] | 0xFFFFu;

label_80063150:
    ctx->pc = 0x80063150u;
    // 80063150: bl      0x8005F51C
    {
            ctx->lr = 0x80063154u;
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8005F51Cu;
                return;
            }
            goto label_8005F51C;
    }

label_80063154:
    ctx->pc = 0x80063154u;
    ctx->downcount -= 5;
    // 80063154: lwz     r0, 12(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(12);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063158:
    ctx->pc = 0x80063158u;
    // 80063158: mtlr    r0
    ctx->lr = ctx->gpr[0];

label_8006315C:
    ctx->pc = 0x8006315Cu;
    // 8006315C: addi    r1, r1, 8
    ctx->gpr[1] = ctx->gpr[1] + (u32)(s32)(8);

label_80063160:
    ctx->pc = 0x80063160u;
    // 80063160: blr
    {
        u32 target = ctx->lr & ~3u;
        bool ctr_ok = true;
        bool cr_ok = true;
        if (ctr_ok && cr_ok) {
            ctx->pc = target;
            goto return_dispatch_8005F2C0;
        }
    }

label_80063164:
    ctx->pc = 0x80063164u;
    ctx->downcount -= 16;
    // 80063164: stwu     r1, -24(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(-24);
        mem_write32(ctx, ea, (u32)ctx->gpr[1]);
        ctx->gpr[1] = ea;
    }

label_80063168:
    ctx->pc = 0x80063168u;
    // 80063168: mflr    r0
    ctx->gpr[0] = ctx->lr;

label_8006316C:
    ctx->pc = 0x8006316Cu;
    // 8006316C: stmw     r28, 8(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(8);
        for (u32 r = 28; r < 32; r++, ea += 4) mem_write32(ctx, ea, ctx->gpr[r]);
    }

label_80063170:
    ctx->pc = 0x80063170u;
    // 80063170: stw     r0, 28(r1)
    {
        u32 ea = ctx->gpr[1] + (u32)(s32)(28);
        mem_write32(ctx, ea, (u32)ctx->gpr[0]);
    }

label_80063174:
    ctx->pc = 0x80063174u;
    // 80063174: or.   r3, r3, r3
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

label_80063178:
    ctx->pc = 0x80063178u;
    // 80063178: bc    12, 2, 0x80063308
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x80063308u;
            return;
        }
    }

label_8006317C:
    ctx->pc = 0x8006317Cu;
    ctx->downcount -= 8;
    // 8006317C: lis     r9, -32699
    ctx->gpr[9] = ((u32)(s32)(-32699) << 16);

label_80063180:
    ctx->pc = 0x80063180u;
    // 80063180: li      r31, 0
    ctx->gpr[31] = (u32)(s32)(0);

label_80063184:
    ctx->pc = 0x80063184u;
    // 80063184: addi    r30, r9, 11848
    ctx->gpr[30] = ctx->gpr[9] + (u32)(s32)(11848);

label_80063188:
    ctx->pc = 0x80063188u;
    // 80063188: stw     r3, -31792(r13)
    {
        u32 ea = ctx->gpr[13] + (u32)(s32)(-31792);
        mem_write32(ctx, ea, (u32)ctx->gpr[3]);
    }

label_8006318C:
    ctx->pc = 0x8006318Cu;
    // 8006318C: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063190:
    ctx->pc = 0x80063190u;
    // 80063190: addi    r28, r13, -31792
    ctx->gpr[28] = ctx->gpr[13] + (u32)(s32)(-31792);

label_80063194:
    ctx->pc = 0x80063194u;
    // 80063194: cmpw    r31, r0
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

label_80063198:
    ctx->pc = 0x80063198u;
    // 80063198: bc    4, 0, 0x800631B8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800631B8;
        }
    }

label_8006319C:
    ctx->downcount -= 3;
    // 8006319C: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_800631A0:
    // 800631A0: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800631A4:
    // 800631A4: bl      0x8003F1B8
    {
            ctx->lr = 0x800631A8u;
            ctx->pc = 0x8003F1B8u;
            return;
    }

label_800631A8:
    ctx->downcount -= 4;
    // 800631A8: addi    r31, r31, 1
    ctx->gpr[31] = ctx->gpr[31] + (u32)(s32)(1);

label_800631AC:
    ctx->pc = 0x800631ACu;
    // 800631AC: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800631B0:
    // 800631B0: cmpw    r31, r0
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

label_800631B4:
    // 800631B4: bc    12, 0, 0x8006319C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006319Cu;
                return;
            }
            goto label_8006319C;
        }
    }

label_800631B8:
    ctx->pc = 0x800631B8u;
    ctx->downcount -= 3;
    // 800631B8: addi    r4, r13, -31788
    ctx->gpr[4] = ctx->gpr[13] + (u32)(s32)(-31788);

label_800631BC:
    ctx->pc = 0x800631BCu;
    // 800631BC: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_800631C0:
    ctx->pc = 0x800631C0u;
    // 800631C0: bl      0x80039B40
    {
            ctx->lr = 0x800631C4u;
            ctx->pc = 0x80039B40u;
            return;
    }

label_800631C4:
    ctx->pc = 0x800631C4u;
    ctx->downcount -= 4;
    // 800631C4: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800631C8:
    ctx->pc = 0x800631C8u;
    // 800631C8: li      r4, 0
    ctx->gpr[4] = (u32)(s32)(0);

label_800631CC:
    ctx->pc = 0x800631CCu;
    // 800631CC: cmpw    r4, r0
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

label_800631D0:
    ctx->pc = 0x800631D0u;
    // 800631D0: bc    4, 0, 0x80063240
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80063240;
        }
    }

label_800631D4:
    ctx->pc = 0x800631D4u;
    ctx->downcount -= 1;
    // 800631D4: addi    r29, r30, 52
    ctx->gpr[29] = ctx->gpr[30] + (u32)(s32)(52);

label_800631D8:
    ctx->downcount -= 4;
    // 800631D8: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_800631DC:
    // 800631DC: addi    r31, r4, 1
    ctx->gpr[31] = ctx->gpr[4] + (u32)(s32)(1);

label_800631E0:
    // 800631E0: cmpw    r11, r0
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

label_800631E4:
    // 800631E4: bc    4, 0, 0x8006321C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_8006321C;
        }
    }

label_800631E8:
    ctx->downcount -= 4;
    // 800631E8: rlwinm r9, r4, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[4], 2u) & 0xFFFFFFFCu;
    }

label_800631EC:
    ctx->pc = 0x800631ECu;
    // 800631EC: lwz     r8, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_800631F0:
    ctx->pc = 0x800631F0u;
    // 800631F0: lwzx    r10, r29, r9
    {
        u32 ea = ctx->gpr[29] + ctx->gpr[9];
        ctx->gpr[10] = mem_read32(ctx, ea);
    }

label_800631F4:
    // 800631F4: or   r9, r28, r28
    {
        ctx->gpr[9] = ctx->gpr[28] | ctx->gpr[28];
    }

label_800631F8:
    ctx->pc = 0x800631F8u;
    ctx->downcount -= 4;
    // 800631F8: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_800631FC:
    // 800631FC: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80063200:
    // 80063200: cmpw    r10, r0
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

label_80063204:
    // 80063204: bc    4, 2, 0x80063210
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80063210;
        }
    }

label_80063208:
    ctx->downcount -= 2;
    // 80063208: or   r0, r4, r4
    {
        ctx->gpr[0] = ctx->gpr[4] | ctx->gpr[4];
    }

label_8006320C:
    // 8006320C: b       0x80063220
    {
            goto label_80063220;
    }

label_80063210:
    ctx->downcount -= 3;
    // 80063210: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_80063214:
    // 80063214: cmpw    r11, r8
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

label_80063218:
    // 80063218: bc    12, 0, 0x800631F8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800631F8u;
                return;
            }
            goto label_800631F8;
        }
    }

label_8006321C:
    ctx->downcount -= 1;
    // 8006321C: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_80063220:
    ctx->downcount -= 2;
    // 80063220: cmpwi   r0, -1
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

label_80063224:
    // 80063224: bc    4, 2, 0x80063230
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80063230;
        }
    }

label_80063228:
    ctx->downcount -= 2;
    // 80063228: or   r3, r30, r30
    {
        ctx->gpr[3] = ctx->gpr[30] | ctx->gpr[30];
    }

label_8006322C:
    // 8006322C: bl      0x8003F1B8
    {
            ctx->lr = 0x80063230u;
            ctx->pc = 0x8003F1B8u;
            return;
    }

label_80063230:
    ctx->pc = 0x80063230u;
    ctx->downcount -= 4;
    // 80063230: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063234:
    // 80063234: or   r4, r31, r31
    {
        ctx->gpr[4] = ctx->gpr[31] | ctx->gpr[31];
    }

label_80063238:
    // 80063238: cmpw    r4, r0
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

label_8006323C:
    // 8006323C: bc    12, 0, 0x800631D8
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x800631D8u;
                return;
            }
            goto label_800631D8;
        }
    }

label_80063240:
    ctx->pc = 0x80063240u;
    ctx->downcount -= 5;
    // 80063240: lwz     r0, 8(r30)
    {
        u32 ea = ctx->gpr[30] + (u32)(s32)(8);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063244:
    ctx->pc = 0x80063244u;
    // 80063244: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_80063248:
    ctx->pc = 0x80063248u;
    // 80063248: cmpw    r11, r0
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

label_8006324C:
    ctx->pc = 0x8006324Cu;
    // 8006324C: or   r7, r0, r0
    {
        ctx->gpr[7] = ctx->gpr[0] | ctx->gpr[0];
    }

label_80063250:
    ctx->pc = 0x80063250u;
    // 80063250: bc    4, 0, 0x80063308
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x80063308u;
            return;
        }
    }

label_80063254:
    ctx->pc = 0x80063254u;
    ctx->downcount -= 5;
    // 80063254: rlwinm r9, r11, 2, 0, 29
    {
        ctx->gpr[9] = dolrecomp_rotl32(ctx->gpr[11], 2u) & 0xFFFFFFFCu;
    }

label_80063258:
    ctx->pc = 0x80063258u;
    // 80063258: addi    r31, r11, 1
    ctx->gpr[31] = ctx->gpr[11] + (u32)(s32)(1);

label_8006325C:
    ctx->pc = 0x8006325Cu;
    // 8006325C: lwzx    r8, r9, r28
    {
        u32 ea = ctx->gpr[9] + ctx->gpr[28];
        ctx->gpr[8] = mem_read32(ctx, ea);
    }

label_80063260:
    ctx->pc = 0x80063260u;
    // 80063260: cmpwi   r8, 0
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

label_80063264:
    ctx->pc = 0x80063264u;
    // 80063264: bc    12, 2, 0x800632F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x800632F4u;
            return;
        }
    }

label_80063268:
    ctx->pc = 0x80063268u;
    ctx->downcount -= 3;
    // 80063268: li      r11, 0
    ctx->gpr[11] = (u32)(s32)(0);

label_8006326C:
    ctx->pc = 0x8006326Cu;
    // 8006326C: cmpw    r11, r0
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

label_80063270:
    ctx->pc = 0x80063270u;
    // 80063270: bc    4, 0, 0x800632A0
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_800632A0;
        }
    }

label_80063274:
    ctx->pc = 0x80063274u;
    ctx->downcount -= 2;
    // 80063274: or   r10, r7, r7
    {
        ctx->gpr[10] = ctx->gpr[7] | ctx->gpr[7];
    }

label_80063278:
    ctx->pc = 0x80063278u;
    // 80063278: addi    r9, r30, 52
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(52);

label_8006327C:
    ctx->pc = 0x8006327Cu;
    ctx->downcount -= 4;
    // 8006327C: lwz     r0, 0(r9)
    {
        u32 ea = ctx->gpr[9] + (u32)(s32)(0);
        ctx->gpr[0] = mem_read32(ctx, ea);
    }

label_80063280:
    // 80063280: addi    r9, r9, 4
    ctx->gpr[9] = ctx->gpr[9] + (u32)(s32)(4);

label_80063284:
    // 80063284: cmpw    r0, r8
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

label_80063288:
    // 80063288: bc    4, 2, 0x80063294
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            goto label_80063294;
        }
    }

label_8006328C:
    ctx->downcount -= 2;
    // 8006328C: or   r0, r11, r11
    {
        ctx->gpr[0] = ctx->gpr[11] | ctx->gpr[11];
    }

label_80063290:
    // 80063290: b       0x800632A4
    {
            goto label_800632A4;
    }

label_80063294:
    ctx->downcount -= 3;
    // 80063294: addi    r11, r11, 1
    ctx->gpr[11] = ctx->gpr[11] + (u32)(s32)(1);

label_80063298:
    // 80063298: cmpw    r11, r10
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

label_8006329C:
    // 8006329C: bc    12, 0, 0x8006327C
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == true);
        if (ctr_ok && cr_ok) {
            if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) {
                ctx->pc = 0x8006327Cu;
                return;
            }
            goto label_8006327C;
        }
    }

label_800632A0:
    ctx->pc = 0x800632A0u;
    ctx->downcount -= 1;
    // 800632A0: li      r0, -1
    ctx->gpr[0] = (u32)(s32)(-1);

label_800632A4:
    ctx->pc = 0x800632A4u;
    ctx->downcount -= 2;
    // 800632A4: cmpwi   r0, -1
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

label_800632A8:
    ctx->pc = 0x800632A8u;
    // 800632A8: bc    4, 2, 0x800632F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x20000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x800632F4u;
            return;
        }
    }

label_800632AC:
    ctx->pc = 0x800632ACu;
    ctx->downcount -= 3;
    // 800632AC: li      r10, 0
    ctx->gpr[10] = (u32)(s32)(0);

label_800632B0:
    ctx->pc = 0x800632B0u;
    // 800632B0: cmpw    r10, r7
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

label_800632B4:
    ctx->pc = 0x800632B4u;
    // 800632B4: bc    4, 0, 0x800632F4
    {
        bool ctr_ok = true;
        bool cr_ok = (((ctx->cr & 0x80000000u) != 0) == false);
        if (ctr_ok && cr_ok) {
            ctx->pc = 0x800632F4u;
            return;
        }
    }

label_800632B8:
    ctx->pc = 0x800632B8u;
    ctx->downcount -= 2;
    // 800632B8: addi    r11, r8, 16
    ctx->gpr[11] = ctx->gpr[8] + (u32)(s32)(16);

label_800632BC:
    ctx->pc = 0x800632BCu;
    // 800632BC: addi    r9, r30, 52
    ctx->gpr[9] = ctx->gpr[30] + (u32)(s32)(52);

    ctx->pc = 0x800632C0u;
    return;
return_dispatch_8005F2C0:
    if (ctx->downcount <= -(s64)DOLRECOMP_C_LOOP_CYCLE_BUDGET) return;
    switch (ctx->pc) {
    case 0x8005F2D8u: goto label_8005F2D8;
    case 0x8005F300u: goto label_8005F300;
    case 0x8005F30Cu: goto label_8005F30C;
    case 0x8005F324u: goto label_8005F324;
    case 0x8005F358u: goto label_8005F358;
    case 0x8005F368u: goto label_8005F368;
    case 0x8005F378u: goto label_8005F378;
    case 0x8005F398u: goto label_8005F398;
    case 0x8005F3A4u: goto label_8005F3A4;
    case 0x8005F3DCu: goto label_8005F3DC;
    case 0x8005F55Cu: goto label_8005F55C;
    case 0x8005F5F4u: goto label_8005F5F4;
    case 0x8005F668u: goto label_8005F668;
    case 0x8005F6D0u: goto label_8005F6D0;
    case 0x8005F730u: goto label_8005F730;
    case 0x8005F790u: goto label_8005F790;
    case 0x8005F7F0u: goto label_8005F7F0;
    case 0x8005F850u: goto label_8005F850;
    case 0x8005F8B0u: goto label_8005F8B0;
    case 0x8005F8C4u: goto label_8005F8C4;
    case 0x8005F920u: goto label_8005F920;
    case 0x8005F96Cu: goto label_8005F96C;
    case 0x8005F9D0u: goto label_8005F9D0;
    case 0x8005FA34u: goto label_8005FA34;
    case 0x8005FA94u: goto label_8005FA94;
    case 0x8005FAF8u: goto label_8005FAF8;
    case 0x8005FB5Cu: goto label_8005FB5C;
    case 0x8005FBC0u: goto label_8005FBC0;
    case 0x8005FC1Cu: goto label_8005FC1C;
    case 0x8005FC80u: goto label_8005FC80;
    case 0x8005FCE4u: goto label_8005FCE4;
    case 0x8005FD48u: goto label_8005FD48;
    case 0x8005FDA0u: goto label_8005FDA0;
    case 0x8005FE34u: goto label_8005FE34;
    case 0x8005FE8Cu: goto label_8005FE8C;
    case 0x8005FEE4u: goto label_8005FEE4;
    case 0x8005FF3Cu: goto label_8005FF3C;
    case 0x8005FF90u: goto label_8005FF90;
    case 0x8005FFDCu: goto label_8005FFDC;
    case 0x80060034u: goto label_80060034;
    case 0x8006008Cu: goto label_8006008C;
    case 0x800600E4u: goto label_800600E4;
    case 0x8006016Cu: goto label_8006016C;
    case 0x800601DCu: goto label_800601DC;
    case 0x80060240u: goto label_80060240;
    case 0x800602A4u: goto label_800602A4;
    case 0x800602FCu: goto label_800602FC;
    case 0x80060348u: goto label_80060348;
    case 0x800603A0u: goto label_800603A0;
    case 0x800603F8u: goto label_800603F8;
    case 0x8006044Cu: goto label_8006044C;
    case 0x800604A4u: goto label_800604A4;
    case 0x80060528u: goto label_80060528;
    case 0x80060584u: goto label_80060584;
    case 0x800605E0u: goto label_800605E0;
    case 0x80060644u: goto label_80060644;
    case 0x8006069Cu: goto label_8006069C;
    case 0x800606E8u: goto label_800606E8;
    case 0x80060744u: goto label_80060744;
    case 0x8006079Cu: goto label_8006079C;
    case 0x800607F4u: goto label_800607F4;
    case 0x8006087Cu: goto label_8006087C;
    case 0x800608D8u: goto label_800608D8;
    case 0x80060934u: goto label_80060934;
    case 0x80060998u: goto label_80060998;
    case 0x800609FCu: goto label_800609FC;
    case 0x80060A50u: goto label_80060A50;
    case 0x80060AB0u: goto label_80060AB0;
    case 0x80060B04u: goto label_80060B04;
    case 0x80060B50u: goto label_80060B50;
    case 0x80060BACu: goto label_80060BAC;
    case 0x80060C04u: goto label_80060C04;
    case 0x80060C58u: goto label_80060C58;
    case 0x80060CB0u: goto label_80060CB0;
    case 0x80060D34u: goto label_80060D34;
    case 0x80060D98u: goto label_80060D98;
    case 0x80060DF4u: goto label_80060DF4;
    case 0x80060E50u: goto label_80060E50;
    case 0x80060E9Cu: goto label_80060E9C;
    case 0x80060EF8u: goto label_80060EF8;
    case 0x80060F50u: goto label_80060F50;
    case 0x80060FA8u: goto label_80060FA8;
    case 0x80061030u: goto label_80061030;
    case 0x80061094u: goto label_80061094;
    case 0x800610F8u: goto label_800610F8;
    case 0x8006115Cu: goto label_8006115C;
    case 0x800611B4u: goto label_800611B4;
    case 0x80061208u: goto label_80061208;
    case 0x80061254u: goto label_80061254;
    case 0x800612B0u: goto label_800612B0;
    case 0x80061308u: goto label_80061308;
    case 0x80061360u: goto label_80061360;
    case 0x800613E8u: goto label_800613E8;
    case 0x8006144Cu: goto label_8006144C;
    case 0x800614A8u: goto label_800614A8;
    case 0x800614FCu: goto label_800614FC;
    case 0x80061548u: goto label_80061548;
    case 0x800615A4u: goto label_800615A4;
    case 0x800615FCu: goto label_800615FC;
    case 0x80061654u: goto label_80061654;
    case 0x800616DCu: goto label_800616DC;
    case 0x80061738u: goto label_80061738;
    case 0x80061794u: goto label_80061794;
    case 0x800617F8u: goto label_800617F8;
    case 0x80061850u: goto label_80061850;
    case 0x800618A4u: goto label_800618A4;
    case 0x800618F0u: goto label_800618F0;
    case 0x8006194Cu: goto label_8006194C;
    case 0x800619A4u: goto label_800619A4;
    case 0x80061A2Cu: goto label_80061A2C;
    case 0x80061A8Cu: goto label_80061A8C;
    case 0x80061AE4u: goto label_80061AE4;
    case 0x80061B3Cu: goto label_80061B3C;
    case 0x80061BA0u: goto label_80061BA0;
    case 0x80061BF4u: goto label_80061BF4;
    case 0x80061C40u: goto label_80061C40;
    case 0x80061C9Cu: goto label_80061C9C;
    case 0x80061CF4u: goto label_80061CF4;
    case 0x80061D4Cu: goto label_80061D4C;
    case 0x80061DD4u: goto label_80061DD4;
    case 0x80061E38u: goto label_80061E38;
    case 0x80061E94u: goto label_80061E94;
    case 0x80061EE8u: goto label_80061EE8;
    case 0x80061F34u: goto label_80061F34;
    case 0x80061F90u: goto label_80061F90;
    case 0x80061FE8u: goto label_80061FE8;
    case 0x80062070u: goto label_80062070;
    case 0x800620D0u: goto label_800620D0;
    case 0x8006211Cu: goto label_8006211C;
    case 0x80062178u: goto label_80062178;
    case 0x800621D0u: goto label_800621D0;
    case 0x80062228u: goto label_80062228;
    case 0x8006228Cu: goto label_8006228C;
    case 0x80062320u: goto label_80062320;
    case 0x80062378u: goto label_80062378;
    case 0x800623D0u: goto label_800623D0;
    case 0x800623E4u: goto label_800623E4;
    case 0x8006244Cu: goto label_8006244C;
    case 0x80062460u: goto label_80062460;
    case 0x800624C0u: goto label_800624C0;
    case 0x8006251Cu: goto label_8006251C;
    case 0x80062578u: goto label_80062578;
    case 0x800625D4u: goto label_800625D4;
    case 0x80062630u: goto label_80062630;
    case 0x8006268Cu: goto label_8006268C;
    case 0x800626E8u: goto label_800626E8;
    case 0x80062750u: goto label_80062750;
    case 0x800627ACu: goto label_800627AC;
    case 0x80062808u: goto label_80062808;
    case 0x80062864u: goto label_80062864;
    case 0x800628C0u: goto label_800628C0;
    case 0x80062928u: goto label_80062928;
    case 0x80062980u: goto label_80062980;
    case 0x80062DA8u: goto label_80062DA8;
    case 0x80062E04u: goto label_80062E04;
    case 0x80062E50u: goto label_80062E50;
    case 0x80063098u: goto label_80063098;
    case 0x80063124u: goto label_80063124;
    case 0x80063154u: goto label_80063154;
    case 0x800631A8u: goto label_800631A8;
    case 0x800631C4u: goto label_800631C4;
    case 0x80063230u: goto label_80063230;
    default: return;
    }
}

